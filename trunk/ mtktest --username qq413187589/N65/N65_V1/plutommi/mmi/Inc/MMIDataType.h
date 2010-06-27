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
 *	 PixtelDataType.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI data type define
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
#ifndef _MMI_DATA_TYPE_H
#define _MMI_DATA_TYPE_H

#ifdef __ASCII
#define ENCODING_LENGTH			1
#endif

#ifdef __UCS2_ENCODING
#define ENCODING_LENGTH			2
#endif

#define CONST_HARDWARE const


/****************************************************************************
*
* Data Type
*
*****************************************************************************/
#ifdef __RESOURCE_GEN_
#include "stdafx.h"

    typedef enum {
        MMI_FALSE   = 0,
        MMI_TRUE    = 1
    } MMI_BOOL;

    typedef char                S8;
    typedef char                *PS8;
    typedef unsigned char       U8;
    typedef unsigned char       *PU8;

    typedef unsigned short      pBOOL;

    typedef short int           S16;
    typedef short int           *PS16;
    typedef unsigned short int  U16;
    typedef unsigned short int  *PU16;

    typedef int                 S32;
    typedef int                 *PS32;
    typedef unsigned int        U32;
    typedef unsigned int        *PU32;

    typedef float               float32;

    typedef unsigned __int64    U64;
    typedef __int64             S64;

    typedef unsigned int        UINT;

#else /* __RESOURCE_GEN_ */
#include "kal_release.h"

  #ifndef FALSE
	#define FALSE   		0
  #endif
    #define TRUE            1
    #define ST_SUCCESS      1
    #define ST_FAILURE      0
    #define MMI_BOOL        kal_bool
    #define MMI_FALSE       KAL_FALSE
    #define MMI_TRUE        KAL_TRUE

    typedef double              DOUBLE;
    typedef float               FLOAT;

    typedef char                S8;
    typedef char                *PS8;
    typedef unsigned char       U8;
    typedef unsigned char       *PU8;

    typedef unsigned short      pBOOL;

    typedef short int           S16;
    typedef short int           *PS16;
    typedef unsigned short int  U16;
    typedef unsigned short int  *PU16;

    typedef int                 S32;
    typedef int                 *PS32;
    typedef unsigned int        U32;
    typedef unsigned int        *PU32;

    typedef float               float32;

#ifdef WIN32
   typedef unsigned __int64     U64;
   typedef __int64              S64;
#else
   typedef unsigned long long   U64;
   typedef long long            S64;
#endif

    typedef unsigned int        UINT;

    typedef unsigned long       STRING_ID;
    typedef unsigned long       IMAGE_ID;
    typedef unsigned long       MENU_ID;
    typedef unsigned long       screen_ID;

    typedef unsigned short      MMI_ID_TYPE;

#if !defined(WIN32) || !defined(_WINDOWS_) /* Windows.h */
    typedef unsigned char   BOOL;
#ifndef CONST
    #define CONST const;
#endif
#endif /* ~WIN32 || ~_WINDOWS_ */

    typedef void (*oslTimerFuncPtr)(void*);
    typedef void (*oslTaskFuncPtr)(void*);

    typedef void (*mmi_void_funcptr_type)(void);
    typedef void (*mmi_int_funcptr_type)(S32);
    typedef void (*mmi_bool_funcptr_type)(MMI_BOOL);

    typedef enum {
       OSL_SUCCESS,
       OSL_ERROR,
       OSL_Q_FULL,
       OSL_Q_EMPTY,
       OSL_SEM_NOT_AVAILABLE,
       OSL_WOULD_BLOCK,
       OSL_MESSAGE_TOO_BIG,
       OSL_INVALID_ID,
       OSL_NOT_INITIALIZED,
       OSL_INVALID_LENGHT,
       OSL_NULL_ADDRESS,
       OSL_NOT_RECEIVE,
       OSL_NOT_SEND,
       OSL_MEMORY_NOT_VALID
    } OSLSTATUS;

#endif /* __RESOURCE_GEN_ */




/****************************************************************************
*
* Applcation Enum
*
*****************************************************************************/
/* Ranges of hash defines given to various Application */
#define  APP_DEFAULT_BASE	101	  /* UNDEPLOYABLE Application base id */


/* Application under APPLICATION_DEFAULT enum can not be undeployed. */
typedef enum {
	APP_MAINMENU=APP_DEFAULT_BASE,
	APP_IDLEAPP,
	APP_BOOTUP,
	APP_SIMTOOLKIT,
	APP_EMAIL,
	APP_GLOBALDEFS,
	APP_CHARGER,
	APP_UIFRAMEWORK,
	APP_PHONEBOOK,
	APP_MESSAGES,
	APP_SETTINGS,
	APP_CALLMANAGEMENT,
	APP_CALLHISTORY,
	APP_CALLSETUP,
	APP_PROFILES,
	APP_NETWORKSETUP,
	APP_WORLDCLOCK,
	APP_DEMOAPP,
	APP_SECURITY_SETUP,
	APP_IMPS,
	APP_UMMS_MMS,
	APP_JATAAYU_MMS,
	APP_JATAAYU_BROWSER,
	APP_JATAAYU_PROVISIONING,
	APP_JATAAYU_JDD,
    APP_JATAAYU_PROFILE,
	APP_MMI_CERTMAN,

	/* please add before this */
	APP_DEFAULT_END
}APPLICATION_DEFAULT;

/* Application under APPLICATION_DEPLOY enum can be deployed or undeployed. */
typedef enum {
	APP_SHORTCUTS=1,
	APP_FUNANDGAMES,
	APP_SERVICES,
	APP_ORGANIZER,
	APP_CALLBARRING,		
	APP_DATAACCOUNT,
	APP_DOWNLOAD,
	APP_TODOLIST,
	APP_INPUTMETHOD,
	APP_VOICEMEMO,
	APP_ENGINEERMODE,
	APP_CALENDAR,
	APP_FACTORYMODE,
	APP_RINGTONECOMPOSER,
	APP_GAMES,
	APP_WAP,
	APP_ALARM,
	APP_CALCULATOR,
	APP_UNITCONVETER,
	APP_CURRENCYCONVERTER,
	APP_HEALTHBMI,
	APP_HEALTHCALORIE,
	APP_HEALTHMENSTRUAL,
	APP_STOPWATCH,	
	APP_PHONESETUP,
	APP_PICTURE_EDITOR,
	APP_AUDIOPLAYER,
	APP_FILEMANAGER,
	APP_SOUNDRECORDER,
	APP_CAMERA,
	APP_IMAGEVIEWER,
	APP_EXTDEVICE,
	APP_JAVA,
	APP_MULTIMEDIA,
	APP_EXTRA,
	APP_VDOPLY,
	APP_VDOREC,
	APP_CHAT,
	APP_FMRDO,
	APP_PHOEDT,
	APP_MESSAGE_CLUB,
	APP_ABREPEATER,
	APP_FMSCHEDULEREC,
	APP_BGSOUND,
	APP_DICTIONARY,
	APP_FTP,
	APP_EBOOK,
	APP_DOWNLOADAGENT,
	APP_DEVAPP,
	APP_UNIFIEDMESSAGE,
	APP_BARCODEREADER,
        APP_SWFLASH,
   	APP_LANGLN,
        APP_UNIFIEDCOMPOSER,
        APP_VDOEDT,
        APP_DEVICE_MANAGEMENT,
        APP_CCA,
        APP_AVATAR,
        APP_CSB,
        APP_RMGR,
	APP_DMUI,
	APP_MOBILE_SERVICE,
   	APP_CUSTOMER_SERVICE,
        APP_MYFAVORITE,
        APP_SLIDESHOW,
        APP_MOBILE_TV_PLAYER,
        APP_VT,
	APP_MMS_BGSR,
        APP_BIP,
        APP_GIS,
    /* please add before this */
    APP_DEPLOY_END
// #ifdef __MMI_DUAL_SIM_MASTER__
 	,
 	APP_MERCURY
// #endif	/* __MERCURY_MASTER__ */
} APPLICATION_DEPLOY;

/* 120304 Calvin added */
typedef enum {
	RES_IMAGE,
	RES_MEDIA,
	RES_AUDIO,
	RES_JAVA_GAME
} RESOURCE_TYPE_LIST;
/* Calvin end */

/* 101205 audio resource Calvin move here */
typedef enum _image_type_enum
{
	SYSTEM_IMAGE,
	EXT_IMAGE,
	NFB_PROGRESS_IMAGE
}image_type_enum;
/* 101205 audio resource Calvin end */


/****************************************************************************
*
* Resource Base ID
*
* Note: We define the the starting value of resource enum ID 
*       for each application instead of using one big enum definition.
*       As a result, we can avoid re-compile of the whole plutommi 
*       when add/remove string/image enum ID.
* 
* Note: The maximum value of resource ID is 65535 due to U16 datatype.
*
*****************************************************************************/

#define RESOURCE_BASE_RANGE(name, count)    \
    RESOURCE_BASE_##name,                   \
    RESOURCE_BASE_##name##_END = RESOURCE_BASE_##name + count - 1

/* 
 * Declare the range of resource ID of each application.
 *
 * For example:
 *      RESOURCE_BASE_RANGE(MY_APP1,    100),
 *      RESOURCE_BASE_RANGE(MY_APP2,    50),
 */

typedef enum 
{
    RESOURCE_BASE_FIRST_VALUE = 0, 

    /* Because wap.lib will use resource, RESOURCE_BASE_WAP need to be front of the table */
    RESOURCE_BASE_RANGE(WAP,                        1500),

    /* please add new resource base below this line */
    RESOURCE_BASE_RANGE(MAIN_MENU,                  600),
    RESOURCE_BASE_RANGE(PHONE_BOOK,                 1200),
    RESOURCE_BASE_RANGE(SHORTCUTS,                  50),
    RESOURCE_BASE_RANGE(FUN_GAMES,                  300),
    RESOURCE_BASE_RANGE(STATUS_ICONS,               300),
    /* Service */
    RESOURCE_BASE_RANGE(SERVICES,                   100),
    RESOURCE_BASE_RANGE(INFO_NUM,                   100),
    RESOURCE_BASE_RANGE(DATA_ACCOUNT,               200),
    /* Organizer */
    RESOURCE_BASE_RANGE(ORGANIZER,                  100),
    RESOURCE_BASE_RANGE(TO_DO_LIST,                 100),
    RESOURCE_BASE_RANGE(ALARM,                      50),
    RESOURCE_BASE_RANGE(CALCULATOR,                 50),
    RESOURCE_BASE_RANGE(UNIT_CONVERTER,             100),
    RESOURCE_BASE_RANGE(CURRENCY_CONVERTER,         50),
    RESOURCE_BASE_RANGE(WORLD_CLOCK,                200),
    RESOURCE_BASE_RANGE(HEALTH_CALORIE,             100),
    RESOURCE_BASE_RANGE(HEALTH_MENSTRUAL,           50),
    RESOURCE_BASE_RANGE(HEALTH_BMI,                 50),
    /* Message */
    RESOURCE_BASE_RANGE(MESSAGES,                   1500),
    RESOURCE_BASE_RANGE(CHAT,                       200),
    /* Unified Message */
    RESOURCE_BASE_RANGE(UNIFIED_MESSAGE,            300),
    /* Unified Composer */
    RESOURCE_BASE_RANGE(UNIFIED_COMPOSER,           300),
    /* XXX unused */
    RESOURCE_BASE_RANGE(CONNECTS,                   100),
    /* Setting */
    RESOURCE_BASE_RANGE(SETTINGS,                   300),
    RESOURCE_BASE_RANGE(SECURITY_SETUP,             300),
    /* Call Management */
    RESOURCE_BASE_RANGE(CALL_MANAGEMENT,	        700),
    /* Idle App */
    RESOURCE_BASE_RANGE(IDLE_APP,                   500),
    RESOURCE_BASE_RANGE(CATEGORY_SCREENS,           700),
    /* Demo App */
    RESOURCE_BASE_RANGE(DEMO_APP,                   700),
    /* Common screen */
    RESOURCE_BASE_RANGE(COMMON_SCREENS,             300),
    /* Phone Setup */
    RESOURCE_BASE_RANGE(PHONE_SETUP,                200),
    RESOURCE_BASE_RANGE(SCREENSAVER,                100),
    RESOURCE_BASE_RANGE(WALLPAPER,                  100),
    RESOURCE_BASE_RANGE(SPOF,                       100),
    RESOURCE_BASE_RANGE(NITZ,                       20),
    RESOURCE_BASE_RANGE(LANG_SETTINGS,              10),
    RESOURCE_BASE_RANGE(HELP,                       100),
    RESOURCE_BASE_RANGE(PHNSET_ONOFF,               200),
    RESOURCE_BASE_RANGE(FLIGHT_MODE,                100),
    /* Misc */
    RESOURCE_BASE_RANGE(SIM_DETECTION,              1000),
    RESOURCE_BASE_RANGE(SAT,                        500),
    RESOURCE_BASE_RANGE(EMAIL,                      300),
    RESOURCE_BASE_RANGE(IMPS,                       300),
    /* Used for FDL/BDL/SDL/Call fwd/call waiting*/
    RESOURCE_BASE_RANGE(CALL_NEW,                   700),
    RESOURCE_BASE_RANGE(CALL_HISTORY,               300),
    RESOURCE_BASE_RANGE(PROFILES,                   600),
    RESOURCE_BASE_RANGE(CHARGER,                    200),
    /* XXX unused */
    RESOURCE_BASE_RANGE(CALL_BARRING,               100),
    RESOURCE_BASE_RANGE(GLOBAL,                     300),
    RESOURCE_BASE_RANGE(NETWORK_SETUP,              200),
    RESOURCE_BASE_RANGE(DOWNLOAD,                   100),
    RESOURCE_BASE_RANGE(VOICE_MEMO,                 200),
    RESOURCE_BASE_RANGE(INPUT_METHOD,               200),
    RESOURCE_BASE_RANGE(CTK,                        200),
    RESOURCE_BASE_RANGE(ENGINEER_MODE,              1000),
    /* Calendar */
    RESOURCE_BASE_RANGE(CAL,                        300),
    RESOURCE_BASE_RANGE(FACTORY_MODE,               300),
    RESOURCE_BASE_RANGE(COMPOSE_RING_TONE_ENGINE,   200),
    RESOURCE_BASE_RANGE(COMPOSE_RINGTONE,           100),
    RESOURCE_BASE_RANGE(AUDIO_PLAYER,               500),
    RESOURCE_BASE_RANGE(SOUND_RECORDER,             300),
    RESOURCE_BASE_RANGE(FILE_MANAGER,               600),
    RESOURCE_BASE_RANGE(JAVA,                       500),
    /* Download application. XXX. To be removed */
    RESOURCE_BASE_RANGE(NV_RAM_FILE_IMAGE,          2000),
    RESOURCE_BASE_RANGE(EXT_DEVICE,                 700),
    RESOURCE_BASE_RANGE(MMEDIA,                     100),
    RESOURCE_BASE_RANGE(EXTRA_APP,                  100),
    RESOURCE_BASE_RANGE(EBOOK,                      200),
    /* Download application. XXX. To be removed */
    RESOURCE_BASE_RANGE(NV_RAM_FILE_EXT_MELODY,     1000),
    RESOURCE_BASE_RANGE(GAME,                       3000),
    RESOURCE_BASE_RANGE(MMIAPI,                     100),
    RESOURCE_BASE_RANGE(VOBJECT,                    50),
    RESOURCE_BASE_RANGE(VCARD,                      50),
    RESOURCE_BASE_RANGE(VCALENDAR,                  50),
    RESOURCE_BASE_RANGE(VBOOKMARK,					50), /*Added by shariq*/
    RESOURCE_BASE_RANGE(STOPWATCH,                  100),
    RESOURCE_BASE_RANGE(DICTIONARY,                 150),
    RESOURCE_BASE_RANGE(PICTURE_EDITOR,             200),
    RESOURCE_BASE_RANGE(CAMERA,                     600),
    RESOURCE_BASE_RANGE(IMAGE_VIEWER,               100),
    RESOURCE_BASE_RANGE(VDOPLY,                     500),
    RESOURCE_BASE_RANGE(VDOREC,                     500),
    RESOURCE_BASE_RANGE(FM_RADIO,                   300),
    /* Voice Command - SD */
    RESOURCE_BASE_RANGE(VRSD,                       100),
    /* Voice Command - SI */
    RESOURCE_BASE_RANGE(VRSI,                       200),
    RESOURCE_BASE_RANGE(PHOEDT,                     300),
    RESOURCE_BASE_RANGE(MESSAGE_CLUB,               1000),
    RESOURCE_BASE_RANGE(POC,                        200),
    RESOURCE_BASE_RANGE(AB_REPEATER,                200),
    /*Schedule FM Radio Record*/
    RESOURCE_BASE_RANGE(FM_SCHEDULE_REC,            200),
    /*Background Sound Effect*/
    RESOURCE_BASE_RANGE(BG_SOUND,                   200),	
    RESOURCE_BASE_RANGE(DL_AGENT,                   100),	
    RESOURCE_BASE_RANGE(JATAAYU_MMS,                1000),
	RESOURCE_BASE_RANGE(UMMS_MMS,                   1000),
    RESOURCE_BASE_RANGE(JATAAYU_BROWSER,            1000),
    RESOURCE_BASE_RANGE(JATAAYU_PROVISIONING,       200),
    RESOURCE_BASE_RANGE(JATAAYU_JDD,                200),
    RESOURCE_BASE_RANGE(JATAAYU_PROFILE,            100),
    RESOURCE_BASE_RANGE(BARCODEREADER,              600),
    RESOURCE_BASE_RANGE(SWFLASH,                    600),
    
    /* Language Learning */
    RESOURCE_BASE_RANGE(LANGLN,     1000),
    
    RESOURCE_BASE_RANGE(SYNCML,                     200),
    RESOURCE_BASE_RANGE(PICT_BRIDGE,                200),
    RESOURCE_BASE_RANGE(VOIP,                       1000),
    RESOURCE_BASE_RANGE(VDOEDT,                     500),
    RESOURCE_BASE_RANGE(DEVICE_MANAGEMENT,          300),
    RESOURCE_BASE_RANGE(CCA,                        100),
    RESOURCE_BASE_RANGE(AVATAR,                     600),
    RESOURCE_BASE_RANGE(CSB,                        100),
    RESOURCE_BASE_RANGE(RMGR,                       300),
	RESOURCE_BASE_RANGE(DMUI,                       200),
    /* Monwap */
    RESOURCE_BASE_RANGE(MONWAP,                     100),
    /* My Favorite */
    RESOURCE_BASE_RANGE(MY_FAVORITE,                100), 
    /*Mobile Service*/     
    RESOURCE_BASE_RANGE(MOBILE_SERVICE,             100),    
    /*Customer Service*/
    RESOURCE_BASE_RANGE(CUSTOMER_SERVICE,           100),
    RESOURCE_BASE_RANGE(UCM,                        1000),       
    RESOURCE_BASE_RANGE(MOBILE_TV_PLAYER,            500),
    RESOURCE_BASE_RANGE(SLIDESHOW,                  100),
    RESOURCE_BASE_RANGE(VT,                         300),   
    RESOURCE_BASE_RANGE(MMS_BGSR,                   100),       
    RESOURCE_BASE_RANGE(MMI_CERTMAN,		        100),

    /* please add new resource base above devapp */	
    RESOURCE_BASE_RANGE(DEVAPP,                     300),
    /*GIS*/
    RESOURCE_BASE_RANGE(GIS,                         1000),
    /* please add new resource base above this line */
//#ifdef __MMI_DUAL_SIM_MASTER__
	RESOURCE_BASE_RANGE(MERCURY,	1000),
	//#endif  /* __MMI_DUAL_SIM_MASTER__ */
     RESOURCE_BASE_RANGE(CMS_WAP,	300),//05.10.18 pan add
    RESOURCE_BASE_RANGE(CMS_MMS,	300),//05.10.18 pan add

	#if 1
	//Huyanwei Add It 
        RESOURCE_BASE_RANGE(THAI_IMAGE, 100),
	#endif

	#if 1
	//Huyanwei Add It 
        RESOURCE_BASE_RANGE(HUYANWEI, 100),	
	#endif
	
    RESOURCE_BASE_RANGE(END,                        1)
} RESOURCE_BASE_ENUM;


/* 
 * Declare MACRO to cast enum names (such as RESOURCE_BASE_MAIN_MENU) 
 * into U16 datatype to be compatible with RVCT.
 *
 * For example:
 *   #define MAIN_MENU_BASE     ((U16) RESOURCE_BASE_MAIN_MENU)
 *   #define MAIN_MENU_BASE_MAX ((U16) RESOURCE_BASE_MAIN_MENU_END)
 */

typedef struct 
{
	char *appname;
	unsigned short min;
	unsigned short max;
} mmi_resource_base_struct;

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)

/* Table of resource base ID used for reference in debugging */
#define RESOURCE_BASE_TABLE_BEGIN()         \
    const	mmi_resource_base_struct g_mmi_resource_base_table[] = {

#define RESOURCE_BASE_TABLE_ITEM(ENUM_NAME) \
        {#ENUM_NAME, (U16) RESOURCE_BASE_##ENUM_NAME, (U16) RESOURCE_BASE_##ENUM_NAME##_END},

#define RESOURCE_BASE_TABLE_END()           \
    };

#else /* _POPULATE_RES_C */

#define RESOURCE_BASE_TABLE_BEGIN()

#define RESOURCE_BASE_TABLE_ITEM(ENUM_NAME)

#define RESOURCE_BASE_TABLE_END()

#endif /* _POPULATE_RES_C */

/****************************************************************************
* Definition of applications
*****************************************************************************/

/* Beginning of resource table */
RESOURCE_BASE_TABLE_BEGIN()

/****************************************************************************
* Main Menu
*****************************************************************************/
#define MAIN_MENU_BASE                      ((U16) RESOURCE_BASE_MAIN_MENU)
#define MAIN_MENU_BASE_MAX                  ((U16) RESOURCE_BASE_MAIN_MENU_END)
RESOURCE_BASE_TABLE_ITEM(MAIN_MENU)

/****************************************************************************
* PhoneBook
*****************************************************************************/
#define PHONE_BOOK_BASE                     ((U16) RESOURCE_BASE_PHONE_BOOK)
#define PHONE_BOOK_BASE_MAX                 ((U16) RESOURCE_BASE_PHONE_BOOK_END)
RESOURCE_BASE_TABLE_ITEM(PHONE_BOOK)

/****************************************************************************
* Shortcut
*****************************************************************************/
#define SHORTCUTS_BASE                      ((U16) RESOURCE_BASE_SHORTCUTS)
#define SHORTCUTS_BASE_MAX                  ((U16) RESOURCE_BASE_SHORTCUTS_END)
RESOURCE_BASE_TABLE_ITEM(SHORTCUTS)

/****************************************************************************
* Fun&Game
*****************************************************************************/
#define FUN_GAMES_BASE                      ((U16) RESOURCE_BASE_FUN_GAMES)
#define FUN_GAMES_BASE_MAX                  ((U16) RESOURCE_BASE_FUN_GAMES_END)
RESOURCE_BASE_TABLE_ITEM(FUN_GAMES)

/****************************************************************************
* Status icons
*****************************************************************************/
#define STATUS_ICONS_BASE                   ((U16) RESOURCE_BASE_STATUS_ICONS)
#define STATUS_ICONS_BASE_MAX               ((U16) RESOURCE_BASE_STATUS_ICONS_END)
RESOURCE_BASE_TABLE_ITEM(STATUS_ICONS)

/****************************************************************************
* Service
*****************************************************************************/
#define SERVICES_BASE                       ((U16) RESOURCE_BASE_SERVICES)
#define SERVICES_BASE_MAX                   ((U16) RESOURCE_BASE_SERVICES_END)
RESOURCE_BASE_TABLE_ITEM(SERVICES)

#define INFO_NUM_BASE                       ((U16) RESOURCE_BASE_INFO_NUM)
#define INFO_NUM_BASE_MAX                   ((U16) RESOURCE_BASE_INFO_NUM_END)
RESOURCE_BASE_TABLE_ITEM(INFO_NUM)

#define DATA_ACCOUNT_BASE                   ((U16) RESOURCE_BASE_DATA_ACCOUNT)
#define DATA_ACCOUNT_BASE_MAX               ((U16) RESOURCE_BASE_DATA_ACCOUNT_END)
RESOURCE_BASE_TABLE_ITEM(DATA_ACCOUNT)

/****************************************************************************
* Organizer
*****************************************************************************/

#define ORGANIZER_BASE                      ((U16) RESOURCE_BASE_ORGANIZER)
#define ORGANIZER_BASE_MAX                  ((U16) RESOURCE_BASE_ORGANIZER_END)
RESOURCE_BASE_TABLE_ITEM(ORGANIZER)

#define EBOOK_BASE                          ((U16) RESOURCE_BASE_EBOOK)
#define EBOOK_BASE_MAX                      ((U16) RESOURCE_BASE_EBOOK_END)
RESOURCE_BASE_TABLE_ITEM(EBOOK)

#define TO_DO_LIST_BASE                     ((U16) RESOURCE_BASE_TO_DO_LIST)
#define TO_DO_LIST_BASE_MAX                 ((U16) RESOURCE_BASE_TO_DO_LIST_END)
RESOURCE_BASE_TABLE_ITEM(TO_DO_LIST)

#define ALARM_BASE                          ((U16) RESOURCE_BASE_ALARM)
#define ALARM_BASE_MAX                      ((U16) RESOURCE_BASE_ALARM_END)
RESOURCE_BASE_TABLE_ITEM(ALARM)

#define CALCULATOR_BASE                     ((U16) RESOURCE_BASE_CALCULATOR)
#define CALCULATOR_BASE_MAX                 ((U16) RESOURCE_BASE_CALCULATOR_END)
RESOURCE_BASE_TABLE_ITEM(CALCULATOR)

#define UNIT_CONVERTER_BASE                 ((U16) RESOURCE_BASE_UNIT_CONVERTER)
#define UNIT_CONVERTER                      UNIT_CONVERTER_BASE /* Be backward compatible */
#define UNIT_CONVERTER_BASE_MAX             ((U16) RESOURCE_BASE_UNIT_CONVERTER_END)
RESOURCE_BASE_TABLE_ITEM(UNIT_CONVERTER)

#define CURRENCY_CONVERTER_BASE             ((U16) RESOURCE_BASE_CURRENCY_CONVERTER)
#define CURRENCY_CONVERTER                  CURRENCY_CONVERTER_BASE /* Be backward compatible */
#define CURRENCY_CONVERTER_BASE_MAX         ((U16) RESOURCE_BASE_CURRENCY_CONVERTER_END)
RESOURCE_BASE_TABLE_ITEM(CURRENCY_CONVERTER)

#define WORLD_CLOCK_BASE                    ((U16) RESOURCE_BASE_WORLD_CLOCK)
#define WORLD_CLOCK                         WORLD_CLOCK_BASE /* Be backward compatible */
#define WORLD_CLOCK_BASE_MAX                ((U16) RESOURCE_BASE_WORLD_CLOCK_END)
RESOURCE_BASE_TABLE_ITEM(WORLD_CLOCK)

#define HEALTH_CALORIE_BASE                 ((U16) RESOURCE_BASE_HEALTH_CALORIE)
#define HEALTH_CALORIE                      HEALTH_CALORIE_BASE /* Be backward compatible */
#define HEALTH_CALORIE_BASE_MAX             ((U16) RESOURCE_BASE_HEALTH_CALORIE_END)
RESOURCE_BASE_TABLE_ITEM(HEALTH_CALORIE)

#define HEALTH_MENSTRUAL_BASE               ((U16) RESOURCE_BASE_HEALTH_MENSTRUAL)
#define HEALTH_MENSTRUAL                    HEALTH_MENSTRUAL_BASE /* Be backward compatible */
#define HEALTH_MENSTRUAL_BASE_MAX           ((U16) RESOURCE_BASE_HEALTH_MENSTRUAL_END)
RESOURCE_BASE_TABLE_ITEM(HEALTH_MENSTRUAL)

#define HEALTH_BMI_BASE                     ((U16) RESOURCE_BASE_HEALTH_BMI)
#define HEALTH_BMI                          HEALTH_BMI_BASE /* Be backward compatible */
#define HEALTH_BMI_BASE_MAX                 ((U16) RESOURCE_BASE_HEALTH_BMI_END)
RESOURCE_BASE_TABLE_ITEM(HEALTH_BMI)

#define RMGR_BASE								((U16) RESOURCE_BASE_RMGR)
#define RMGR                                    RMGR_BASE
#define	RMGR_BASE_MAX							((U16) RESOURCE_BASE_RMGR_END)
RESOURCE_BASE_TABLE_ITEM(RMGR)

/****************************************************************************
* Message
*****************************************************************************/

#define MESSAGES_BASE                       ((U16) RESOURCE_BASE_MESSAGES)
#define MESSAGES_BASE_MAX                   ((U16) RESOURCE_BASE_MESSAGES_END)
RESOURCE_BASE_TABLE_ITEM(MESSAGES)

#define CHAT_BASE                           ((U16) RESOURCE_BASE_CHAT)
#define CHAT_BASE_MAX                       ((U16) RESOURCE_BASE_CHAT_END)
RESOURCE_BASE_TABLE_ITEM(CHAT)

/****************************************************************************
* Unified Message
*****************************************************************************/

#define UNIFIED_MESSAGE_BASE                ((U16) RESOURCE_BASE_UNIFIED_MESSAGE)
#define UNIFIED_MESSAGE_BASE_MAX            ((U16) RESOURCE_BASE_UNIFIED_MESSAGE_END)
RESOURCE_BASE_TABLE_ITEM(UNIFIED_MESSAGE)

/****************************************************************************
* Unified Composer
*****************************************************************************/

#define UNIFIED_COMPOSER_BASE               ((U16) RESOURCE_BASE_UNIFIED_COMPOSER)
#define UNIFIED_COMPOSER_BASE_MAX           ((U16) RESOURCE_BASE_UNIFIED_COMPOSER_END)
RESOURCE_BASE_TABLE_ITEM(UNIFIED_COMPOSER)


/****************************************************************************
* Connection
*****************************************************************************/
#define CONNECTS_BASE                       ((U16) RESOURCE_BASE_CONNECTS)
#define CONNECTS_BASE_MAX                   ((U16) RESOURCE_BASE_CONNECTS_END)
RESOURCE_BASE_TABLE_ITEM(CONNECTS)

/****************************************************************************
* Setting
*****************************************************************************/

#define SETTINGS_BASE                       ((U16) RESOURCE_BASE_SETTINGS)
#define SETTINGS_BASE_MAX                   ((U16) RESOURCE_BASE_SETTINGS_END)
RESOURCE_BASE_TABLE_ITEM(SETTINGS)

#define SECURITY_SETUP_BASE                 ((U16) RESOURCE_BASE_SECURITY_SETUP)
#define SECURITY_SETUP_BASE_MAX             ((U16) RESOURCE_BASE_SECURITY_SETUP_END)
RESOURCE_BASE_TABLE_ITEM(SECURITY_SETUP)

/****************************************************************************
* Call Management
*****************************************************************************/

#define CALL_MANAGEMENT_BASE                ((U16) RESOURCE_BASE_CALL_MANAGEMENT)
#define CALL_MANAGEMENT_BASE_MAX            ((U16) RESOURCE_BASE_CALL_MANAGEMENT_END)
RESOURCE_BASE_TABLE_ITEM(CALL_MANAGEMENT)

/****************************************************************************
* Idle App
*****************************************************************************/

#define IDLE_APP_BASE                       ((U16) RESOURCE_BASE_IDLE_APP)
#define IDLE_APP_BASE_MAX                   ((U16) RESOURCE_BASE_IDLE_APP_END)
RESOURCE_BASE_TABLE_ITEM(IDLE_APP)

/****************************************************************************
* Category Screens
*****************************************************************************/

#define CATEGORY_SCREENS_BASE               ((U16) RESOURCE_BASE_CATEGORY_SCREENS)
#define CATEGORY_SCREENS_BASE_MAX           ((U16) RESOURCE_BASE_CATEGORY_SCREENS_END)
RESOURCE_BASE_TABLE_ITEM(CATEGORY_SCREENS)

/****************************************************************************
* Demo App
*****************************************************************************/

#define DEMO_APP_BASE                       ((U16) RESOURCE_BASE_DEMO_APP)
#define DEMO_APP_BASE_MAX                   ((U16) RESOURCE_BASE_DEMO_APP_END)
RESOURCE_BASE_TABLE_ITEM(DEMO_APP)

/****************************************************************************
* Common Screen 
*****************************************************************************/


#define COMMON_SCREENS_BASE                 ((U16) RESOURCE_BASE_COMMON_SCREENS)
#define COMMON_SCREENS_BASE_MAX             ((U16) RESOURCE_BASE_COMMON_SCREENS_END)
RESOURCE_BASE_TABLE_ITEM(COMMON_SCREENS)

/****************************************************************************
* Phone Setup
*****************************************************************************/

#define PHONE_SETUP_BASE                    ((U16) RESOURCE_BASE_PHONE_SETUP)
#define PHONE_SETUP_BASE_MAX                ((U16) RESOURCE_BASE_PHONE_SETUP_END)
RESOURCE_BASE_TABLE_ITEM(PHONE_SETUP)

#define SCREENSAVER_BASE                    ((U16) RESOURCE_BASE_SCREENSAVER)
#define SCREENSAVER_BASE_MAX                ((U16) RESOURCE_BASE_SCREENSAVER_END)
RESOURCE_BASE_TABLE_ITEM(SCREENSAVER)

#define WALLPAPER_BASE                      ((U16) RESOURCE_BASE_WALLPAPER)
#define WALLPAPER_BASE_MAX                  ((U16) RESOURCE_BASE_WALLPAPER_END)
RESOURCE_BASE_TABLE_ITEM(WALLPAPER)

#define SPOF_BASE                           ((U16) RESOURCE_BASE_SPOF)
#define SPOF_BASE_MAX                       ((U16) RESOURCE_BASE_SPOF_END)
RESOURCE_BASE_TABLE_ITEM(SPOF)

#define NITZ_BASE                           ((U16) RESOURCE_BASE_NITZ)
#define NITZ_BASE_MAX                       ((U16) RESOURCE_BASE_NITZ_END)
RESOURCE_BASE_TABLE_ITEM(NITZ)

#define LANG_SETTINGS_BASE                  ((U16) RESOURCE_BASE_LANG_SETTINGS)
#define LANG_SETTINGS_BASE_MAX              ((U16) RESOURCE_BASE_LANG_SETTINGS_END)
RESOURCE_BASE_TABLE_ITEM(LANG_SETTINGS)

#define HELP_BASE                           ((U16) RESOURCE_BASE_HELP)
#define HELP_BASE_MAX                       ((U16) RESOURCE_BASE_HELP_END)
RESOURCE_BASE_TABLE_ITEM(HELP)

#define PHNSET_ONOFF_BASE                   ((U16) RESOURCE_BASE_PHNSET_ONOFF)
#define PHNSET_ONOFF_BASE_MAX               ((U16) RESOURCE_BASE_PHNSET_ONOFF_END)
RESOURCE_BASE_TABLE_ITEM(PHNSET_ONOFF)

#define FLIGHT_MODE_BASE                    ((U16) RESOURCE_BASE_FLIGHT_MODE)
#define FLIGHT_MODE_BASE_MAX                ((U16) RESOURCE_BASE_FLIGHT_MODE_END)
RESOURCE_BASE_TABLE_ITEM(FLIGHT_MODE)

/****************************************************************************
* Misc
*****************************************************************************/

#define SIM_DETECTION_BASE                  ((U16) RESOURCE_BASE_SIM_DETECTION)
#define SIM_DETECTION_BASE_MAX              ((U16) RESOURCE_BASE_SIM_DETECTION_END)
RESOURCE_BASE_TABLE_ITEM(SIM_DETECTION)

#define SAT_BASE                            ((U16) RESOURCE_BASE_SAT)
#define SAT_BASE_MAX                        ((U16) RESOURCE_BASE_SAT_END)
RESOURCE_BASE_TABLE_ITEM(SAT)

#define EMAIL_BASE                          ((U16) RESOURCE_BASE_EMAIL)
#define EMAIL_BASE_MAX                      ((U16) RESOURCE_BASE_EMAIL_END)
RESOURCE_BASE_TABLE_ITEM(EMAIL)

#define IMPS_BASE                           ((U16) RESOURCE_BASE_IMPS)
#define IMPS_BASE_MAX                       ((U16) RESOURCE_BASE_IMPS_END)
RESOURCE_BASE_TABLE_ITEM(IMPS)

#define CALL_NEW_BASE                       ((U16) RESOURCE_BASE_CALL_NEW)
#define CALL_BASE_NEW                       CALL_NEW_BASE /* Be backward compatible */
#define CALL_NEW_BASE_MAX                   ((U16) RESOURCE_BASE_CALL_NEW_END)
RESOURCE_BASE_TABLE_ITEM(CALL_NEW)

#define CALL_HISTORY_BASE                   ((U16) RESOURCE_BASE_CALL_HISTORY)
#define CALL_HISTORY                        CALL_HISTORY_BASE /* Be backward compatible */
#define CALL_HISTORY_BASE_MAX               ((U16) RESOURCE_BASE_CALL_HISTORY_END)
RESOURCE_BASE_TABLE_ITEM(CALL_HISTORY)

#define PROFILES_BASE                       ((U16) RESOURCE_BASE_PROFILES)
#define PROFILES_BASE_MAX                   ((U16) RESOURCE_BASE_PROFILES_END)
RESOURCE_BASE_TABLE_ITEM(PROFILES)

#define CHARGER_BASE                        ((U16) RESOURCE_BASE_CHARGER)
#define CHARGER_BASE_MAX                    ((U16) RESOURCE_BASE_CHARGER_END)
RESOURCE_BASE_TABLE_ITEM(CHARGER)

#define CALL_BARRING_BASE                   ((U16) RESOURCE_BASE_CALL_BARRING)
#define CALL_BARRING                        CALL_BARRING_BASE /* Be backward compatible */
#define CALL_BARRING_BASE_MAX               ((U16) RESOURCE_BASE_CALL_BARRING_END)
RESOURCE_BASE_TABLE_ITEM(CALL_BARRING)

#define GLOBAL_BASE                         ((U16) RESOURCE_BASE_GLOBAL)
#define GLOBAL_BASE_MAX                     ((U16) RESOURCE_BASE_GLOBAL_END)
RESOURCE_BASE_TABLE_ITEM(GLOBAL)

#define NETWORK_SETUP_BASE                  ((U16) RESOURCE_BASE_NETWORK_SETUP)
#define NETWORK_SETUP_BASE_MAX              ((U16) RESOURCE_BASE_NETWORK_SETUP_END)
RESOURCE_BASE_TABLE_ITEM(NETWORK_SETUP)

#define DOWNLOAD_BASE                       ((U16) RESOURCE_BASE_DOWNLOAD)
#define DOWNLOAD_BASE_MAX                   ((U16) RESOURCE_BASE_DOWNLOAD_END)
RESOURCE_BASE_TABLE_ITEM(DOWNLOAD)

#define VOICE_MEMO_BASE                     ((U16) RESOURCE_BASE_VOICE_MEMO)
#define VOICE_MEMO_BASE_MAX                 ((U16) RESOURCE_BASE_VOICE_MEMO_END)
RESOURCE_BASE_TABLE_ITEM(VOICE_MEMO)

#define INPUT_METHOD_BASE                   ((U16) RESOURCE_BASE_INPUT_METHOD)
#define INPUT_METHOD_BASE_MAX               ((U16) RESOURCE_BASE_INPUT_METHOD_END)
RESOURCE_BASE_TABLE_ITEM(INPUT_METHOD)

#define CTK_BASE                            ((U16) RESOURCE_BASE_CTK)
#define CTK_BASE_MAX                        ((U16) RESOURCE_BASE_CTK_END)
RESOURCE_BASE_TABLE_ITEM(CTK)

#define ENGINEER_MODE_BASE                  ((U16) RESOURCE_BASE_ENGINEER_MODE)
#define ENGINEER_MODE_BASE_MAX              ((U16) RESOURCE_BASE_ENGINEER_MODE_END)
RESOURCE_BASE_TABLE_ITEM(ENGINEER_MODE)

#define CAL_BASE                            ((U16) RESOURCE_BASE_CAL)
#define CAL_BASE_MAX                        ((U16) RESOURCE_BASE_CAL_END)
RESOURCE_BASE_TABLE_ITEM(CAL)

#define FACTORY_MODE_BASE                   ((U16) RESOURCE_BASE_FACTORY_MODE)
#define FACTORY_MODE_BASE_MAX               ((U16) RESOURCE_BASE_FACTORY_MODE_END)
RESOURCE_BASE_TABLE_ITEM(FACTORY_MODE)

#define COMPOSE_RING_TONE_ENGINE_BASE       ((U16) RESOURCE_BASE_COMPOSE_RING_TONE_ENGINE)
#define COMPOSE_RING_TONE_ENGINE_BASE_MAX   ((U16) RESOURCE_BASE_COMPOSE_RING_TONE_ENGINE_END)
RESOURCE_BASE_TABLE_ITEM(COMPOSE_RING_TONE_ENGINE)

#define COMPOSE_RINGTONE_BASE               ((U16) RESOURCE_BASE_COMPOSE_RINGTONE)
#define COMPOSE_RINGTONE_BASE_MAX           ((U16) RESOURCE_BASE_COMPOSE_RINGTONE_END)
RESOURCE_BASE_TABLE_ITEM(COMPOSE_RINGTONE)

#define WAP_BASE                            ((U16) RESOURCE_BASE_WAP)
#define WAP_BASE_MAX                        ((U16) RESOURCE_BASE_WAP_END)
RESOURCE_BASE_TABLE_ITEM(WAP)

#define AUDIO_PLAYER_BASE                   ((U16) RESOURCE_BASE_AUDIO_PLAYER)
#define AUDIO_PLAYER_BASE_MAX               ((U16) RESOURCE_BASE_AUDIO_PLAYER_END)
RESOURCE_BASE_TABLE_ITEM(AUDIO_PLAYER)

#define SOUND_RECORDER_BASE                 ((U16) RESOURCE_BASE_SOUND_RECORDER)
#define SOUND_RECORDER_BASE_MAX             ((U16) RESOURCE_BASE_SOUND_RECORDER_END)
RESOURCE_BASE_TABLE_ITEM(SOUND_RECORDER)

#define FILE_MANAGER_BASE                   ((U16) RESOURCE_BASE_FILE_MANAGER)
#define FILE_MANAGER_BASE_MAX               ((U16) RESOURCE_BASE_FILE_MANAGER_END)
RESOURCE_BASE_TABLE_ITEM(FILE_MANAGER)

#define JAVA_BASE                           ((U16) RESOURCE_BASE_JAVA)
#define JAVA_BASE_MAX                       ((U16) RESOURCE_BASE_JAVA_END)
RESOURCE_BASE_TABLE_ITEM(JAVA)

#define NV_RAM_FILE_IMAGE_BASE              ((U16) RESOURCE_BASE_NV_RAM_FILE_IMAGE)
#define NV_RAM_FILE_IMAGE_ID_BASE           NV_RAM_FILE_IMAGE_BASE
#define NV_RAM_FILE_IMAGE_BASE_MAX          ((U16) RESOURCE_BASE_NV_RAM_FILE_IMAGE_END)
RESOURCE_BASE_TABLE_ITEM(NV_RAM_FILE_IMAGE)

#define EXT_DEVICE_BASE                     ((U16) RESOURCE_BASE_EXT_DEVICE)
#define EXT_DEVICE_BASE_MAX                 ((U16) RESOURCE_BASE_EXT_DEVICE_END)
RESOURCE_BASE_TABLE_ITEM(EXT_DEVICE)

#define MMEDIA_BASE                         ((U16) RESOURCE_BASE_MMEDIA)
#define MMEDIA_BASE_MAX                     ((U16) RESOURCE_BASE_MMEDIA_END)
RESOURCE_BASE_TABLE_ITEM(MMEDIA)

#define EXTRA_APP_BASE                      ((U16) RESOURCE_BASE_EXTRA_APP)
#define EXTRA_APP_BASE_MAX                  ((U16) RESOURCE_BASE_EXTRA_APP_END)
RESOURCE_BASE_TABLE_ITEM(EXTRA_APP)

#define NV_RAM_FILE_EXT_MELODY_BASE         ((U16) RESOURCE_BASE_NV_RAM_FILE_EXT_MELODY)
#define NV_RAM_FILE_EXT_MELODY_ID_BASE      NV_RAM_FILE_EXT_MELODY_BASE
#define NV_RAM_FILE_EXT_MELODY_BASE_MAX     ((U16) RESOURCE_BASE_NV_RAM_FILE_EXT_MELODY_END)
RESOURCE_BASE_TABLE_ITEM(NV_RAM_FILE_EXT_MELODY)

#define GAME_BASE                           ((U16) RESOURCE_BASE_GAME)
#define GAME_BASE_MAX                       ((U16) RESOURCE_BASE_GAME_END)
RESOURCE_BASE_TABLE_ITEM(GAME)

#define MMIAPI_BASE                         ((U16) RESOURCE_BASE_MMIAPI)
#define MMIAPI_BASE_MAX                     ((U16) RESOURCE_BASE_MMIAPI_END)
RESOURCE_BASE_TABLE_ITEM(MMIAPI)

#define VOBJECT_BASE                        ((U16) RESOURCE_BASE_VOBJECT)
#define VOBJECT_BASE_MAX                    ((U16) RESOURCE_BASE_VOBJECT_END)
RESOURCE_BASE_TABLE_ITEM(VOBJECT)

#define VCARD_BASE                          ((U16) RESOURCE_BASE_VCARD)
#define VCARD_BASE_MAX                      ((U16) RESOURCE_BASE_VCARD_END)
RESOURCE_BASE_TABLE_ITEM(VCARD)

#define VCALENDAR_BASE                      ((U16) RESOURCE_BASE_VCALENDAR)
#define VCALENDAR_BASE_MAX                  ((U16) RESOURCE_BASE_VCALENDAR_END)
RESOURCE_BASE_TABLE_ITEM(VCALENDAR)

 /*Added by shariq*/
#define  VBOOKMARK_BASE						((U16) RESOURCE_BASE_VBOOKMARK)
#define	VBOOKMARK_BASE_MAX					((U16) RESOURCE_BASE_VBOOKMARK_END)
RESOURCE_BASE_TABLE_ITEM(VBOOKMARK)

#define STOPWATCH_BASE                      ((U16) RESOURCE_BASE_STOPWATCH)
#define STOPWATCH_BASE_MAX                  ((U16) RESOURCE_BASE_STOPWATCH_END)
RESOURCE_BASE_TABLE_ITEM(STOPWATCH)

#define DICTIONARY_BASE                     ((U16) RESOURCE_BASE_DICTIONARY)
#define DICTIONARY_BASE_MAX                 ((U16) RESOURCE_BASE_DICTIONARY_END)
RESOURCE_BASE_TABLE_ITEM(DICTIONARY)

#define PICTURE_EDITOR_BASE                 ((U16) RESOURCE_BASE_PICTURE_EDITOR)
#define PICTURE_EDITOR_BASE_MAX             ((U16) RESOURCE_BASE_PICTURE_EDITOR_END)
RESOURCE_BASE_TABLE_ITEM(PICTURE_EDITOR)

#define CAMERA_BASE                         ((U16) RESOURCE_BASE_CAMERA)
#define CAMERA_BASE_MAX                     ((U16) RESOURCE_BASE_CAMERA_END)
RESOURCE_BASE_TABLE_ITEM(CAMERA)

#define BARCODEREADER_BASE                  ((U16) RESOURCE_BASE_BARCODEREADER)
#define BARCODEREADER_BASE_MAX              ((U16) RESOURCE_BASE_BARCODEREADER_END)
RESOURCE_BASE_TABLE_ITEM(BARCODEREADER)

#define IMAGE_VIEWER_BASE                   ((U16) RESOURCE_BASE_IMAGE_VIEWER)
#define IMAGE_VIEWER_BASE_MAX               ((U16) RESOURCE_BASE_IMAGE_VIEWER_END)
RESOURCE_BASE_TABLE_ITEM(IMAGE_VIEWER)

#define VDOPLY_BASE                         ((U16) RESOURCE_BASE_VDOPLY)
#define VDOPLY_BASE_MAX                     ((U16) RESOURCE_BASE_VDOPLY_END)
RESOURCE_BASE_TABLE_ITEM(VDOPLY)

#define VDOREC_BASE                         ((U16) RESOURCE_BASE_VDOREC)
#define VDOREC_BASE_MAX                     ((U16) RESOURCE_BASE_VDOREC_END)
RESOURCE_BASE_TABLE_ITEM(VDOREC)

#define FM_RADIO_BASE                       ((U16) RESOURCE_BASE_FM_RADIO)
#define FM_RADIO_BASE_MAX                   ((U16) RESOURCE_BASE_FM_RADIO_END)
RESOURCE_BASE_TABLE_ITEM(FM_RADIO)

#define VRSD_BASE                           ((U16) RESOURCE_BASE_VRSD)
#define VRSD_BASE_MAX                       ((U16) RESOURCE_BASE_VRSD_END)
RESOURCE_BASE_TABLE_ITEM(VRSD)

#define VRSI_BASE                           ((U16) RESOURCE_BASE_VRSI)
#define VRSI_BASE_MAX                       ((U16) RESOURCE_BASE_VRSI_END)
RESOURCE_BASE_TABLE_ITEM(VRSI)

#define PHOEDT_BASE                         ((U16) RESOURCE_BASE_PHOEDT)
#define PHOEDT_BASE_MAX                     ((U16) RESOURCE_BASE_PHOEDT_END)
RESOURCE_BASE_TABLE_ITEM(PHOEDT)

#define MESSAGE_CLUB_BASE                   ((U16) RESOURCE_BASE_MESSAGE_CLUB)
#define MESSAGE_CLUB_BASE_MAX               ((U16) RESOURCE_BASE_MESSAGE_CLUB_END)
RESOURCE_BASE_TABLE_ITEM(MESSAGE_CLUB)

#define POC_BASE                            ((U16) RESOURCE_BASE_POC)
#define POC_BASE_MAX                        ((U16) RESOURCE_BASE_POC_END)
RESOURCE_BASE_TABLE_ITEM(POC)

#define AB_REPEATER_BASE                    ((U16) RESOURCE_BASE_AB_REPEATER)
#define AB_REPEATER_BASE_MAX                ((U16) RESOURCE_BASE_AB_REPEATER_END)
RESOURCE_BASE_TABLE_ITEM(AB_REPEATER)

/****************************************************************************
* Schedule FM Radio Record
*****************************************************************************/
#define FM_SCHEDULE_REC_BASE                ((U16) RESOURCE_BASE_FM_SCHEDULE_REC)
#define FM_SCHEDULE_REC_BASE_MAX            ((U16) RESOURCE_BASE_FM_SCHEDULE_REC_END)
RESOURCE_BASE_TABLE_ITEM(FM_SCHEDULE_REC)

/****************************************************************************
* Background Sound Effect
*****************************************************************************/
#define BG_SOUND_BASE                       ((U16) RESOURCE_BASE_BG_SOUND)
#define BG_SOUND_BASE_MAX                   ((U16) RESOURCE_BASE_BG_SOUND_END)
RESOURCE_BASE_TABLE_ITEM(BG_SOUND)

#define DEVAPP_BASE                         ((U16) RESOURCE_BASE_DEVAPP)
#define DEVAPP_BASE_MAX                     ((U16) RESOURCE_BASE_DEVAPP_END)
RESOURCE_BASE_TABLE_ITEM(DEVAPP)

/****************************************************************************
* Download Agent
*****************************************************************************/
#define DL_AGENT_BASE                       ((U16) RESOURCE_BASE_DL_AGENT)
#define DL_AGENT_BASE_MAX                   ((U16) RESOURCE_BASE_DL_AGENT_END)
RESOURCE_BASE_TABLE_ITEM(DL_AGENT)

#define UMMS_MMS_BASE						((U16) RESOURCE_BASE_UMMS_MMS)
#define UMMS_MMS_BASE_MAX					((U16) RESOURCE_BASE_UMMS_MMS_END)
RESOURCE_BASE_TABLE_ITEM(UMMS_MMS)
/****************************************************************************
* Porting Jataayu WAP/MMS
*****************************************************************************/
#define JATAAYU_MMS_BASE                    ((U16) RESOURCE_BASE_JATAAYU_MMS)
#define JATAAYU_MMS_BASE_MAX                ((U16) RESOURCE_BASE_JATAAYU_MMS_END)
RESOURCE_BASE_TABLE_ITEM(JATAAYU_MMS)

#define JATAAYU_BROWSER_BASE                ((U16) RESOURCE_BASE_JATAAYU_BROWSER)
#define JATAAYU_BROWSER_BASE_MAX            ((U16) RESOURCE_BASE_JATAAYU_BROWSER_END)
RESOURCE_BASE_TABLE_ITEM(JATAAYU_BROWSER) 

#define JATAAYU_PROVISIONING_BASE           ((U16) RESOURCE_BASE_JATAAYU_PROVISIONING)
#define JATAAYU_PROVISIONING_BASE_MAX       ((U16) RESOURCE_BASE_JATAAYU_PROVISIONING_END)
RESOURCE_BASE_TABLE_ITEM(JATAAYU_PROVISIONING) 

#define JATAAYU_JDD_BASE                    ((U16) RESOURCE_BASE_JATAAYU_JDD)
#define JATAAYU_JDD_BASE_MAX                ((U16) RESOURCE_BASE_JATAAYU_JDD_END)
RESOURCE_BASE_TABLE_ITEM(JATAAYU_JDD) 

#define JATAAYU_PROFILE_BASE           ((U16) RESOURCE_BASE_JATAAYU_PROFILE)
#define JATAAYU_PROFILE_BASE_MAX       ((U16) RESOURCE_BASE_JATAAYU_PROFILE_END)
RESOURCE_BASE_TABLE_ITEM(JATAAYU_PROFILE)
/****************************************************************************
* SW Flash
*****************************************************************************/
#define SWFLASH_BASE                        ((U16) RESOURCE_BASE_SWFLASH)
#define SWFLASH_BASE_MAX                    ((U16) RESOURCE_BASE_SWFLASH_END)
RESOURCE_BASE_TABLE_ITEM(SWFLASH)

/****************************************************************************
* SyncML
*****************************************************************************/
#define SYNCML_BASE                         ((U16) RESOURCE_BASE_SYNCML)
#define SYNCML_BASE_MAX                     ((U16) RESOURCE_BASE_SYNCML_END)
RESOURCE_BASE_TABLE_ITEM(SYNCML)

/****************************************************************************
* PictBridge
*****************************************************************************/
#define PICT_BRIDGE_BASE                    ((U16) RESOURCE_BASE_PICT_BRIDGE)
#define	PICT_BRIDGE_BASE_MAX                ((U16) RESOURCE_BASE_PICT_BRIDGE_END)
RESOURCE_BASE_TABLE_ITEM(PICT_BRIDGE)

#define VOIP_BASE                           ((U16)RESOURCE_BASE_VOIP)
#define VOIP_BASE_MAX                       ((U16)RESOURCE_BASE_VOIP_END)
RESOURCE_BASE_TABLE_ITEM(VOIP)

/*****************************************************************************
* CSB
******************************************************************************/
#define CSB_BASE							((U16)RESOURCE_BASE_CSB)
#define CSB_BASE_MAX						((U16)RESOURCE_BASE_CSB_END)
RESOURCE_BASE_TABLE_ITEM(CSB)

RESOURCE_BASE_TABLE_ITEM(END)

#define VDOEDT_BASE                         ((U16) RESOURCE_BASE_VDOEDT)
#define VDOEDT_BASE_MAX                     ((U16) RESOURCE_BASE_VDOEDT_END)
RESOURCE_BASE_TABLE_ITEM(VDOEDT)

/****************************************************************************
* Device Management
*****************************************************************************/
#define DEVICE_MANAGEMENT_BASE              ((U16) RESOURCE_BASE_DEVICE_MANAGEMENT)
#define DEVICE_MANAGEMENT_BASE_MAX          ((U16) RESOURCE_BASE_DEVICE_MANAGEMENT_END)
RESOURCE_BASE_TABLE_ITEM(DEVICE_MANAGEMENT)

/****************************************************************************
* Centralised Configuration Agent
*****************************************************************************/
#define CCA_BASE                            ((U16) RESOURCE_BASE_CCA)
#define	CCA_BASE_MAX                        ((U16) RESOURCE_BASE_CCA_END)
RESOURCE_BASE_TABLE_ITEM(CCA)

/****************************************************************************
* Avatar
*****************************************************************************/
#define  AVATAR_BASE                        ((U16) RESOURCE_BASE_AVATAR)
#define  AVATAR_BASE_MAX                    ((U16) RESOURCE_BASE_AVATAR_END)
RESOURCE_BASE_TABLE_ITEM(AVATAR)

/****************************************************************************
* DM UI 
*****************************************************************************/
#define DMUI_BASE                    ((U16) RESOURCE_BASE_DMUI)
#define	DMUI_BASE_MAX                ((U16) RESOURCE_BASE_DMUI_END)
RESOURCE_BASE_TABLE_ITEM(DMUI)

/****************************************************************************
* MONWAP
*****************************************************************************/
#define  MONWAP_BASE                        ((U16) RESOURCE_BASE_MONWAP)
#define  MONWAP_BASE_MAX                    ((U16) RESOURCE_BASE_MONWAP_END)
RESOURCE_BASE_TABLE_ITEM(MONWAP)

/****************************************************************************
* My favorite
*****************************************************************************/
#define MY_FAVORITE_BASE                        ((U16) RESOURCE_BASE_MY_FAVORITE)
#define  MY_FAVORITE_BASE_MAX                    ((U16) RESOURCE_BASE_MY_FAVORITE_END)
RESOURCE_BASE_TABLE_ITEM(MY_FAVORITE)

/****************************************************************************
* Mobile Service
*****************************************************************************/
#define  MOBILE_SERVICE_BASE		((U16) RESOURCE_BASE_MOBILE_SERVICE)
#define	MOBILE_SERVICE_BASE_MAX	((U16) RESOURCE_BASE_MOBILE_SERVICE_END)
RESOURCE_BASE_TABLE_ITEM(MOBILE_SERVICE)

/****************************************************************************
* MMS BGSR
*****************************************************************************/
#define MMS_BGSR_BASE		((U16) RESOURCE_BASE_MMS_BGSR)
#define	MMS_BGSR_BASE_MAX	((U16) RESOURCE_BASE_MMS_BGSR_END)
RESOURCE_BASE_TABLE_ITEM(MMS_BGSR)


/****************************************************************************
* Customer Service
*****************************************************************************/
#define  CUSTOMER_SERVICE_BASE		((U16) RESOURCE_BASE_CUSTOMER_SERVICE)
#define	CUSTOMER_SERVICE_BASE_MAX	((U16) RESOURCE_BASE_CUSTOMER_SERVICE_END)
RESOURCE_BASE_TABLE_ITEM(CUSTOMER_SERVICE)

/****************************************************************************
* UCM
*****************************************************************************/
#define UCM_BASE                            ((U16)RESOURCE_BASE_UCM)
#define UCM_BASE_MAX                        ((U16)RESOURCE_BASE_UCM_END)
RESOURCE_BASE_TABLE_ITEM(UCM)

/****************************************************************************
* VT
*****************************************************************************/
#define VT_BASE                            ((U16)RESOURCE_BASE_VT)
#define VT_BASE_MAX                        ((U16)RESOURCE_BASE_VT_END)
RESOURCE_BASE_TABLE_ITEM(VT)

/****************************************************************************
* Mobile TV Player 
*****************************************************************************/
#define  MOBILE_TV_PLAYER_BASE              ((U16) RESOURCE_BASE_MOBILE_TV_PLAYER)
#define  MOBILE_TV_PLAYER_BASE_MAX          ((U16) RESOURCE_BASE_MOBILE_TV_PLAYER_END)
RESOURCE_BASE_TABLE_ITEM(MOBILE_TV_PLAYER)

/****************************************************************************
* Language Learning
*****************************************************************************/
#define  LANGLN_BASE				((U16) RESOURCE_BASE_LANGLN)
#define	 LANGLN_BASE_MAX		((U16) RESOURCE_BASE_LANGLN_END)
RESOURCE_BASE_TABLE_ITEM(LANGLN)

/****************************************************************************
* Slide Show
*****************************************************************************/
#define  SLIDESHOW_BASE		((U16) RESOURCE_BASE_SLIDESHOW)
#define	SLIDESHOW_BASE_MAX	((U16) RESOURCE_BASE_SLIDESHOW_END)
RESOURCE_BASE_TABLE_ITEM(SLIDESHOW)

/****************************************************************************
* Certificate Manager
*****************************************************************************/
#define MMI_CERTMAN_BASE						((U16) RESOURCE_BASE_MMI_CERTMAN)
#define MMI_CERTMAN_BASE_MAX					((U16) RESOURCE_BASE_MMI_CERTMAN_END)
RESOURCE_BASE_TABLE_ITEM(MMI_CERTMAN)

/****************************************************************************
* mercury module
*****************************************************************************/
//#ifdef __MMI_DUAL_SIM_MASTER__
#define MERCURY_BASE                    ((U16) RESOURCE_BASE_MERCURY)
#define	MERCURY_BASE_MAX                ((U16) RESOURCE_BASE_MERCURY_END)
RESOURCE_BASE_TABLE_ITEM(MERCURY)
//#endif  /* __MMI_DUAL_SIM_MASTER__ */

//05.10.18 pan add start
#define  CMS_WAP_BASE				((U16) RESOURCE_BASE_CMS_WAP)
#define	CMS_WAP_BASE_MAX		((U16) RESOURCE_BASE_CMS_WAP_END)
RESOURCE_BASE_TABLE_ITEM(CMS_WAP)

#define  CMS_MMS_BASE				((U16) RESOURCE_BASE_CMS_MMS)
#define	CMS_MMS_BASE_MAX		((U16) RESOURCE_BASE_CMS_MMS_END)
RESOURCE_BASE_TABLE_ITEM(CMS_MMS)


#if 1
//Huyanwei Add It 
#define  THAI_IMAGE_BASE				((U16) RESOURCE_BASE_THAI_IMAGE)
#define  THAI_IMAGE_BASE_MAX			((U16) RESOURCE_BASE_THAI_IMAGE_END)
RESOURCE_BASE_TABLE_ITEM(THAI_IMAGE)
#endif


#if 1
//Huyanwei Add It For Customer defined 
#define HUYANWEI_BASE ((U16) RESOURCE_BASE_HUYANWEI)
#define HUYANWEI_BASE_MAX			((U16) RESOURCE_BASE_HUYANWEI_END)
RESOURCE_BASE_TABLE_ITEM(HUYANWEI)
#endif

/* please add new resource base table above this line */
RESOURCE_BASE_TABLE_ITEM(END)

/* End of resource table */
RESOURCE_BASE_TABLE_END()


#endif /* _MMI_DATA_TYPE_H */
