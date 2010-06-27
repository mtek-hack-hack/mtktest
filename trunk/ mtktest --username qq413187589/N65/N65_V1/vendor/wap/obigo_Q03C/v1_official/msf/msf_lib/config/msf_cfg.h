/*
 * Copyright (C) Obigo AB, 2002-2006.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msf_cfg.h
 *
 * Created by
 *
 * Revision history:
 *
 *
 */
#ifndef _msf_cfg_h
#define _msf_cfg_h

#include "MMI_features.h"
#include "gui_config.h"
#include "PixtelDataTypes.h"
#include "gdi_datatype.h"
#include "gdi_include.h"

#include "msf_def.h"

#ifdef MMS_SUPPORT
#define MMSAT_SUPPORT                /* Support MMS AT command*/
  #if (!defined(MEA_MERGE_SENT)) || (!defined(MEA_MERGE_OUTBOX))
    #define MEA_MERGE_SENT
  #endif /* (!defined(MEA_MERGE_SENT)) || (!defined(MEA_MERGE_OUTBOX)) */
#if defined(__MMI_DUAL_SIM__)
#define __MMS_DUAL_SIM_SUPPORT__
#endif

#endif /* MMS_SUPPORT */
#define MMS_SLIM_MEM
#define MMS_FILE_PROTECT_SUPPORT     /* Support Checksum mechanism */

#define WPS_SUPPORT
#define WPS_TASK_SUPPORT

/* 
 * [Experimental Feature]
 * Share MCU time with MMI task since the two tasks have the same priority 
 * Otherwise, if WAP task is busy running, MMI task does not have any chance to run unless
 * WAP task is paused in a waiting queue by system service like kal_take_mutex()
 */
#define WAP_COOPERATIVE_SHARE_MCU_TIME

/**************************************************
 * Release policy
 **************************************************/
/* the following two options are equivalent */
#undef WAP_RELEASE
#define WAP_DEBUG		1

/**************************************************
 * Startup policy
 **************************************************/

#define MSF_STARTUP_STATIC       0
#define MSF_STARTUP_DYNAMIC      1
#define MSF_STARTUP_EXTERNAL     2

 
/**************************************************
 * Modules in this configuration
 **************************************************/



/*
#define MSF_MODID_MSM            0x00
#define MSF_MODID_STK            0x01
#define MSF_MODID_BRS            0x02
#define MSF_MODID_PHS            0x03
#define MSF_MODID_SEC            0x04
#define MSF_MODID_BRA            0x05
#define MSF_MODID_PRS            0x06
#define MSF_MODID_CMS            0x07
#define MSF_MODID_CMA            0x08
#define MSF_MODID_UIS            0x09
#define MSF_MODID_UIA            0x0A
#define MSF_NUMBER_OF_MODULES    11
*/

typedef enum
{
   MSF_MODID_MSM_ENUM,
   MSF_MODID_STK_ENUM,
   MSF_MODID_BRS_ENUM,
   MSF_MODID_BRA_ENUM,
   MSF_MODID_PHS_ENUM,
   MSF_MODID_UIS_ENUM,
   MSF_MODID_PRS_ENUM,
   MSF_MODID_SEC_ENUM,
   MSF_MODID_MMS_ENUM,
   MSF_MODID_MEA_ENUM,
   MSF_MODID_SLS_ENUM,
   MSF_MODID_SMA_ENUM,
   MSF_MODID_MMC_ENUM,
   MSF_MODID_MMA_ENUM,
   MSF_MODID_WPS_ENUM,
   MSF_MODID_DAS_ENUM,
   MSF_MODID_WIDGET_ENUM,
   MSF_NUMBER_OF_MODULES
}msf_modid_enum;

#define MSF_MODID_MSM            MSF_MODID_MSM_ENUM
#define MSF_MODID_STK            MSF_MODID_STK_ENUM
#define MSF_MODID_BRS            MSF_MODID_BRS_ENUM
#define MSF_MODID_BRA            MSF_MODID_BRA_ENUM
#define MSF_MODID_PHS            MSF_MODID_PHS_ENUM
#define MSF_MODID_UIS            MSF_MODID_UIS_ENUM
#define MSF_MODID_PRS            MSF_MODID_PRS_ENUM
#define MSF_MODID_SEC            MSF_MODID_SEC_ENUM
#define MSF_MODID_MMS            MSF_MODID_MMS_ENUM
#define MSF_MODID_MEA            MSF_MODID_MEA_ENUM
#define MSF_MODID_SLS            MSF_MODID_SLS_ENUM
#define MSF_MODID_SMA            MSF_MODID_SMA_ENUM
#define MSF_MODID_MMC            MSF_MODID_MMC_ENUM 
#define MSF_MODID_MMA            MSF_MODID_MMA_ENUM 
#define MSF_MODID_WPS            MSF_MODID_WPS_ENUM
#define MSF_MODID_DAS            MSF_MODID_DAS_ENUM
#define MSF_MODID_WIDGET         MSF_MODID_WIDGET_ENUM

/*
#define MSF_MODULES_STARTUP { MSF_STARTUP_STATIC, "MSM" ,    \
                              MSF_STARTUP_STATIC, "STK" ,    \
                              MSF_STARTUP_STATIC, "BRS" ,    \
                              MSF_STARTUP_STATIC, "PHS" ,    \
                              MSF_STARTUP_STATIC, "SEC" ,    \
                              MSF_STARTUP_STATIC, "BRA" ,    \
                              MSF_STARTUP_STATIC, "PRS" ,    \
                              MSF_STARTUP_STATIC, "CMS" ,    \
                              MSF_STARTUP_DYNAMIC, "CMA" ,    \
                              MSF_STARTUP_STATIC, "UIS" ,    \
                              MSF_STARTUP_STATIC, "UIA" ,    \
                            }
*/

#define MSF_BROWSER_STARTUP   MSF_STARTUP_STATIC,  "MSM" ,    \
                              MSF_STARTUP_STATIC,  "STK" ,    \
                              MSF_STARTUP_DYNAMIC, "BRS" ,    \
                              MSF_STARTUP_STATIC,  "BRA" ,    \
                              MSF_STARTUP_STATIC,  "PHS" ,    \
                              MSF_STARTUP_STATIC,  "UIS" ,    \
                              MSF_STARTUP_STATIC,  "PRS" ,

#define MSF_SEC_STARTUP       MSF_STARTUP_STATIC,  "SEC" ,     

#define MSF_MMS_STARTUP       MSF_STARTUP_STATIC, "MMS"  ,   \
                              MSF_STARTUP_DYNAMIC, "MEA" ,   \
                              MSF_STARTUP_DYNAMIC, "SLS" ,   \
                              MSF_STARTUP_DYNAMIC, "SMA" ,   

#define MSF_MMC_STARTUP       MSF_STARTUP_STATIC, "MMC"  ,

#define MSF_MMA_STARTUP       MSF_STARTUP_DYNAMIC, "MMA"  ,

#define MSF_WPS_STARTUP       MSF_STARTUP_STATIC, "WPS"  ,

#define MSF_DAS_STARTUP       MSF_STARTUP_STATIC,  "DAS"  ,

#define MSF_WIDGET_STARTUP    MSF_STARTUP_STATIC,  "WDG"


#define MSF_MODULES_STARTUP   {  MSF_BROWSER_STARTUP \
                                 MSF_SEC_STARTUP     \
                                 MSF_MMS_STARTUP     \
                                 MSF_MMC_STARTUP     \
                                 MSF_MMA_STARTUP     \
                                 MSF_WPS_STARTUP     \
                                 MSF_DAS_STARTUP     \
                                 MSF_WIDGET_STARTUP  \
                              }

/*****************************************************
 * Digital Rights Management Extension Package support
 *  - Define MSF_CONFIG_DRE if DRE should be used
 *****************************************************/

/*#define MSF_CONFIG_DRE*/

/**************************************************
 * Parsing
 **************************************************/
/* Flag to use SGML grammar for WML */
#define MSF_CFG_EXTENDED_WML_PARSING

/**************************************************
 * Logging
 **************************************************/

/* This flag decides whether the MSF_LOG_MSG and MSF_LOG_DATA macros will be compiled in */ 
/*(enabled). */
/* If set calls to HDIa_logMsg and HDIa_logData will be made. */
#ifdef __PRODUCTION_RELEASE__
#undef MSF_LOG_MODULE
#else
#define MSF_LOG_MODULE
#endif

/* This flag decides whether The MSF_LOG_SIG... macros will be compiled in */ 
/*(enabled). */
/* If set a call to HDIa_logSignal will be made for each signal send/recv */
/* that uses those macros. */
#undef MSF_LOG_SIGNALS /* MSF Q03C1_1.1 has bug in log*/


/************************************************************************/
/* FEATURE DEFINES                                                      */
/************************************************************************/

/************************************************************************/
/* Push Address handling, to define if originator address or service    */
/* center will be extracted and appended alone with received message.   */
/************************************************************************/
/*
 * Address definitions:
 *   1      Originator address:   originator address is applied
 *   2      SC address:    service center address is applied
 */
#ifdef __MMI_PUSH_SHOW_SENDER_ADDR__
#define MSF_CFG_PUSH_ADDRESS_OPTION   1
#else
#define MSF_CFG_PUSH_ADDRESS_OPTION   2
#endif


/************************************************************************/
/* NEW_PIPE_ERROR_EVENT, define this to activate the usage of the error */
/* code HDI_PIPE_ERROR_CLOSED_ERROR and the integration function        */
/*   HDIa_pipeCloseError                                                */
/************************************************************************/
#define NEW_PIPE_ERROR_EVENT

/************************************************************************/
/* MSF_CFG_MIME_ACTIONS_EXTERN, define this to have the                 */
/* msf_act_mime_action_table declared as extern.                        */
/* Note: When msf_act_mime_action_table is set externally,              */
/* extern_nbr_of_mime_actions also has to be set.                       */
/************************************************************************/

#define MSF_CFG_MIME_ACTIONS_EXTERN

#define MSF_USE_FILE_READ_DIR_SEQ

/**************************************************
 * Memory allocation
 **************************************************/
/*#define MSF_CONFIG_INTERNAL_MALLOC*/

#if defined MSF_CONFIG_INTERNAL_MALLOC
/* Define this to help find memory problems */
/* #define MSF_CFG_DEBUG_INTERNAL_MALLOC */
#endif

/**************************************************
 * Temporary Folder - Must NOT be terminated by a slash
 **************************************************/
#define MSF_CFG_TEMPORARY_FOLDER_PATH "/temp"

/**************************************************
 * Filename length supported by native file system
 **************************************************/
#define MSF_CFG_FILE_EXTENSION_LENGTH	4 /* WBMP takes four characters */
#define MSF_CFG_FILE_NAME_LENGTH      	(40-MSF_CFG_FILE_EXTENSION_LENGTH-1)

/**************************************************
 * Virtual Max Filename length (Extension included)
 * (this is the filename displayed to the user internally)
 **************************************************/
#define MSF_CFG_VIRTUAL_FILE_NAME_LENGTH (MSF_CFG_FILE_NAME_LENGTH+MSF_CFG_FILE_EXTENSION_LENGTH+1/*dot*/)

/**************************************************
 * Disable the creation of shorter filenames.
 **************************************************/
#define MSF_CFG_AFI_DISABLE_FILENAME_CONV

 /**********************************************************************
 * User Root Folders
 *
 * The User Root Folder are a set of folders the packages will use through 
 * the AFI package to Save, Create and Open file and folders with long filenames
 * and with the possibility to associate attributes with those files. It
 * is not possible to access any other part of the file system from the 
 * AFI package other than the folders defined here. A localized version of all
 * User Root Folders may be created. 
 *
 * The structure must be as follows:
 *
 * Posix pathname      : The physical posix pathname to where the folder 
 *                       content should be stored. Note that is not possible
 *                       to access files stored under this path other than 
 *                       through the AFI package.
 * String Resource id  : A resource id to the string that will be displayed 
 *                       to the user, e.g. the folder "My Pictures" will be
 *                       called "Mina Bilder" if Swedish were selected as 
 *                       current language.
 * Root folder id      : A folder string identifier that uniquely identifies 
 *                       this folder. Note that this id must also be unique 
 *                       among the User Folders defined below.
 * mime type           : The mime types that will be possible to store in this
 *                       folder.
 * max directory depth : The maximum depth of the directory structure that
 *                       may be created. 1 indicates that no subdirectories
 *                       may be created under the root. 2 would indicate that
 *                       that any number of subdirectories may be created 
 *                       as long as they are the child of the root directory.
 *                       NOTE! This parameter is not used in this implementation
 *                       but is included for future use.
 * external              This is used to indicate if this User Root Folder is 
 *                       mapped to a external memory device such as memory 
 *                       card etc. 1 means external and 0 internal
 *
 **********************************************************************/

/* A typical User Root Folder configuration may be defined as below:
*/
#ifdef WAP_SUPPORT

/* Although we do not use user root folder in our design, we still need to 
 * define the following MACRO to make MSF framework happy */

/* pathnames must end with '/' */
#define WAP_IMAGE_FOLDER	"/public/"
#define WAP_SOUND_FOLDER	"/public/"
#define WAP_VIDEO_FOLDER	"/public/"
#define WAP_VOBJECT_FOLDER  "/public/"
#define WAP_DOWNLOAD_FOLDER "/download/"
#define WAP_DOWNLOAD_FOLDER_LEN 10

  #ifdef __DRM_SUPPORT__
#define MSF_NBR_OF_USER_ROOT_FOLDERS 5 
#define MSF_USER_ROOT_FOLDERS { WAP_IMAGE_FOLDER, MSF_STR_ID_ROOT_FOLDER_PICTURE, "picture", "image/*", 1, 0,\
                                WAP_SOUND_FOLDER, MSF_STR_ID_ROOT_FOLDER_SOUND, "sound", "audio/*,text/x-imelody,application/vnd.smaf,application/x-smaf", 1, 0,\
                                WAP_VIDEO_FOLDER, MSF_STR_ID_ROOT_FOLDER_VIDEO, "video", "video/*", 1, 0,\
                                WAP_VOBJECT_FOLDER, MSF_STR_ID_ROOT_FOLDER_APP, "app", "text/x-vcard,text/x-vcalendar", 1, 0,\
                                WAP_VOBJECT_FOLDER, MSF_STR_ID_ROOT_FOLDER_APP, "app", "application/vnd.oma.drm.message,application/vnd.oma.drm.content", 1, 0,\
}
  #else
#define MSF_NBR_OF_USER_ROOT_FOLDERS 4
#define MSF_USER_ROOT_FOLDERS { WAP_IMAGE_FOLDER, MSF_STR_ID_ROOT_FOLDER_PICTURE, "picture", "image/*", 1, 0,\
                                WAP_SOUND_FOLDER, MSF_STR_ID_ROOT_FOLDER_SOUND, "sound", "audio/*,text/x-imelody,application/vnd.smaf,application/x-smaf", 1, 0,\
                                WAP_VIDEO_FOLDER, MSF_STR_ID_ROOT_FOLDER_VIDEO, "video", "video/*", 1, 0,\
                                WAP_VOBJECT_FOLDER, MSF_STR_ID_ROOT_FOLDER_APP, "app", "text/x-vcard,text/x-vcalendar", 1, 0,\
}
  #endif /* __DRM_SUPPORT__ */

#else	/* WAP_SUPPORT */

#define MSF_NBR_OF_USER_ROOT_FOLDERS 9

#define MSF_USER_ROOT_FOLDERS { "/usr_data/picture/",    MSF_STR_ID_ROOT_FOLDER_PICTURE, "picture"    , "image/*", 3, 0,\
                                "/usr_data/sound/",      MSF_STR_ID_ROOT_FOLDER_SOUND,   "sound"      , "audio/*", 2, 0,\
                                "/usr_data/video/",      MSF_STR_ID_ROOT_FOLDER_VIDEO,   "video"      , "video/*", 1, 0,\
                                "/usr_data/app/",        MSF_STR_ID_ROOT_FOLDER_APP,     "application", "application/*,application/x-obigo-midlet-id", 2, 0,\
                                "/usr_data/anim/",       MSF_STR_ID_ROOT_FOLDER_ANIM,    "animations" , "application/x-obigo-ems-animation", 1, 0, \
                                "/usr_data/bookmark/",   MSF_STR_ID_ROOT_FOLDER_BKM,     "bookmarks"  , "application/x-obigo-bookmark", 2, 0, \
                                "/usr_data/ofln_pgs/",   MSF_STR_ID_ROOT_FOLDER_OFLN_PGS,"offline"    , "application/x-obigo-bookmark", 1, 0, \
                                "/usr_data/bkm_pers/",   MSF_STR_ID_ROOT_FOLDER_BKM_PERS,"persistent" , "application/x-obigo-bookmark", 1, 0, \
                                "/external/c:usr_data/", MSF_STR_ID_ROOT_FOLDER_EXT,     "external"   , "*/*", 2, 1,\
}

#endif	/* WAP_SUPPORT */

/* A typical User Folder configuration may be defined as below:
 * Note: If user folders are nested, define the parent user folders ordered first.
 */
#ifdef WAP_SUPPORT

#undef MSF_NBR_OF_USER_FOLDERS
#undef MSF_USER_FOLDERS

#else

#define MSF_NBR_OF_USER_FOLDERS 5

#define MSF_USER_FOLDERS      { MSF_STR_ID_USER_FOLDER_NATURE,    "nature",   "picture",     \
                                MSF_STR_ID_USER_FOLDER_WORK,      "work",     "picture",     \
                                MSF_STR_ID_USER_FOLDER_VACATION,  "vacation", "picture",     \
                                MSF_STR_ID_USER_FOLDER_MUSIC,     "music",    "sound",       \
                                MSF_STR_ID_USER_FOLDER_SOUNDS,    "sounds",   "sound",       \
}

#endif

/**********************************************************************
 * Mime Actions
 *
 * The Mime Actions stores actions. An action has a list of mime
 * types. The list records for which kind of files the action is applicable..
 * For each action, there is also an associated action name, intended to
 * be displayed in a menu to the user.
 *   . 
 *
 * The structure must be as follows:
 *
 * Mime types          : Mime types separated by comma.
 * Action command      : A string that identifies the action. For actions
 *                       executed internally, it may also be a command
 *                       string.
 *                        MSF_PACKET_OPERATION_ID_SAS : command string
 *                            for save as operation.
 * Module id           : The module to which an internal action will be
 *                       forwarded to for execution.
 *                       Use 0 if not applicable, e.g. for external actions
 *                       (see Action type below).
 *                       For packet and category type, use 0.
 *                       MSF_MIME_ACTION_TYPE_INTERNAL actions, uses content
 *                       routing. Use a non-zero id in these cases.
 *                       The non-zero id implies direct content routing.
 *                       (MSF_MIME_ACTION_TYPE_INTERNAL actions may be used
 *                       with zero id, which implies that MSM will try to find a 
 *                       receiver module based on MIME registry information 
 *                       for content routing. Zero module id for
 *                       MSF_MIME_ACTION_TYPE_INTERNAL actions, may only be used
 *                       if it is certain that MSM will find a match in its
 *                       content routing descision.)
 * Action Name id      : A resource id to the localized string that will be  
 *                       displayed to the user.
 * Action type         : The type of action indicating if the action is 
 *                       realized internally, as an internal packet, externally
 *                       or if it is a category (see below).
 *                          MSF_MIME_ACTION_TYPE_EXTERNAL
 *                          MSF_MIME_ACTION_TYPE_INTERNAL
 *                          MSF_MIME_ACTION_TYPE_PACKET  
 *                          MSF_MIME_ACTION_TYPE_CATEGORY  
 * Category action     : The category to which this action belongs to.
 *                       Actions may be grouped into action categories.
 *                       In this case the category is represented by an
 *                       MSF_MIME_ACTION_TYPE_CATEGORY action and a contained
 *                       action (sub-action) must in this field reference the
 *                       category. The reference is expressed as the index
 *                       (row nr - 1) into this table where the category action
 *                       is recorded. If the action does not belong to any catogory
 *                       this field must be set to -1.
 *                       Category actions are regarded as internal but may
 *                       contain external actions. Only MSF_MIME_ACTION_TYPE_EXTERNAL 
 *                       actions are passed on externally..
 *                       NOTE: When adding or removing rows in the table,
 *                       remember to check/update this field for ALL remaining
 *                       rows. Also note, that sub-actions may not be category 
 *                       actions in turn, i.e. the category structure is only 
 *                       one level deep.
 * Blocked permissions : The denied or blocked DRM permissions (bits)
 *                       for the action. When a DRM permission is required, 
 *                       this field is checked wether it blocks (denies) 
 *                       the permission or not.
 *                       Use MSF_PERMISSION_NONE_BLOCKED if all permissions
 *                       are granted. Use MSF_PERMISSION_FORWARD_BLOCKED
 *                       if DRM forward permission is denied for the action.
 *                       Note, this field is only applicable when
 *                       permissions are required.
 *
 **********************************************************************/
#ifndef MTK_TMP_PATCH /* CR25284 Moved to msf_misc.c for customizable definition */

/* A typical Mime Action configuration may be defined as below */
#ifdef WAP_SUPPORT

/* FIXME. Imelody support is defined by compilation option*/
#ifdef __DRM_SUPPORT__
#define MSF_NBR_OF_MIME_ACTIONS 5

#define MSF_MIME_ACTIONS  \
  { "image/vnd.wap.wbmp,image/gif,image/bmp,image/jpeg,image/png",\
    MSF_PACKET_OPERATION_ID_SAS, 0, SMA_STR_ID_MENU_SAVE_IMAGE, MSF_MIME_ACTION_TYPE_PACKET,   -1, MSF_PERMISSION_NONE_BLOCKED, \
	 "audio/imelody,text/x-imelody,audio/x-wav,audio/wav," \
	 "audio/midi,audio/mid,audio/x-midi,audio/sp-midi,application/vnd.smaf,application/x-smaf," \
	 "audio/amr,audio/mp3,audio/mpeg,audio/amr-wb",\
    MSF_PACKET_OPERATION_ID_SAS, 0, SMA_STR_ID_MENU_SAVE_AUDIO, MSF_MIME_ACTION_TYPE_PACKET,   -1, MSF_PERMISSION_NONE_BLOCKED, \
    "video/3gpp,video/mpeg,video/x-msvideo", \
    MSF_PACKET_OPERATION_ID_SAS, 0, SMA_STR_ID_MENU_SAVE_VIDEO, MSF_MIME_ACTION_TYPE_PACKET, -1, MSF_PERMISSION_NONE_BLOCKED, \
    "text/x-vcard,text/x-vcalendar,text/vnd.sun.j2me.app-descriptor,application/java-archive", MSF_PACKET_OPERATION_ID_SAS, 0, MSF_STR_ID_MIME_ACTION_SAVE, MSF_MIME_ACTION_TYPE_PACKET, -1, MSF_PERMISSION_NONE_BLOCKED, \
    "application/vnd.oma.drm.message,application/vnd.oma.drm.content,application/vnd.oma.drm.rights+wbxml,application/vnd.oma.drm.rights+xml", MSF_PACKET_OPERATION_ID_SAS, 0, MSF_STR_ID_MIME_ACTION_SAVE, MSF_MIME_ACTION_TYPE_PACKET, -1, MSF_PERMISSION_NONE_BLOCKED \
  }
#else

#define MSF_NBR_OF_MIME_ACTIONS 4

#define MSF_MIME_ACTIONS  \
  { "image/vnd.wap.wbmp,image/gif,image/bmp,image/jpeg,image/png",\
    MSF_PACKET_OPERATION_ID_SAS, 0, SMA_STR_ID_MENU_SAVE_IMAGE, MSF_MIME_ACTION_TYPE_PACKET,   -1, MSF_PERMISSION_NONE_BLOCKED, \
	 "audio/imelody,text/x-imelody,audio/x-wav,audio/wav," \
	 "audio/midi,audio/mid,audio/x-midi,audio/sp-midi,application/vnd.smaf,application/x-smaf," \
	 "audio/amr,audio/mp3,audio/mpeg,audio/amr-wb",\
    MSF_PACKET_OPERATION_ID_SAS, 0, SMA_STR_ID_MENU_SAVE_AUDIO, MSF_MIME_ACTION_TYPE_PACKET,   -1, MSF_PERMISSION_NONE_BLOCKED, \
    "video/3gpp,video/mpeg,video/x-msvideo", \
    MSF_PACKET_OPERATION_ID_SAS, 0, SMA_STR_ID_MENU_SAVE_VIDEO, MSF_MIME_ACTION_TYPE_PACKET, -1, MSF_PERMISSION_NONE_BLOCKED, \
    "text/x-vcard,text/x-vcalendar,text/vnd.sun.j2me.app-descriptor,application/java-archive", MSF_PACKET_OPERATION_ID_SAS, 0, MSF_STR_ID_MIME_ACTION_SAVE, MSF_MIME_ACTION_TYPE_PACKET, -1, MSF_PERMISSION_NONE_BLOCKED \
  }

#endif /* __DRM_SUPPORT__ */

#else

#define MSF_NBR_OF_MIME_ACTIONS 6

#define MSF_MIME_ACTIONS  \
  { "*/*", MSF_PACKET_OPERATION_ID_SAS,   0, MSF_STR_ID_MIME_ACTION_SAVE,            MSF_MIME_ACTION_TYPE_PACKET,   -1, MSF_PERMISSION_NONE_BLOCKED, \
    "",           "set",                  0, MSF_STR_ID_MIME_ACTION_SET,             MSF_MIME_ACTION_TYPE_CATEGORY, -1, MSF_PERMISSION_NONE_BLOCKED, \
    "image/jpeg", "set screensaver",      0, MSF_STR_ID_MIME_ACTION_SET_SCREENSAVER, MSF_MIME_ACTION_TYPE_EXTERNAL,  1, MSF_PERMISSION_NONE_BLOCKED, \
    "image/jpeg", "set greeting",         0, MSF_STR_ID_MIME_ACTION_SET_GREETING,    MSF_MIME_ACTION_TYPE_EXTERNAL,  1, MSF_PERMISSION_NONE_BLOCKED, \
    "image/jpeg", "set wallpaper",        0, MSF_STR_ID_MIME_ACTION_SET_WALLPAPER,   MSF_MIME_ACTION_TYPE_EXTERNAL,  1, MSF_PERMISSION_NONE_BLOCKED, \
    "audio/*",    "set ringtone",         0, MSF_STR_ID_MIME_ACTION_SET_RINGTONE,    MSF_MIME_ACTION_TYPE_EXTERNAL,  1, MSF_PERMISSION_NONE_BLOCKED \
  }

#endif

#endif
/* Example of an MSF_MIME_ACTIONS row using an internal command to send as mms:
    "image/jpeg", "-mode new -i", MSF_MODID_MEA, MSF_STR_ID_MIME_ACTION_SEND_AS_MMS, MSF_MIME_ACTION_TYPE_INTERNAL, -1, MSF_PERMISSION_FORWARD_BLOCKED, \
*/

/**********************************************************************
 * Icon Table
 *
 * In this table it is possible to configure which icon to be associated
 * with at specific (or general) mime type. To ensure that all files 
 * always are associated with an icon the * / * type should be defined.
 * If both a string resource id and a integer resource id is defined 
 * for one item the string resource will be used.
 *
 * Note that the last element int the table must be NULL
 * 
 *
 * The structure must be as follows:
 *
 * Mime type          : Mime type to associate this icon with.
 * 
 * resource_type      : The type of resource defined. There are 
 *                      two types of icon resources.
 *                      MSF_ICON_RESOURCE_TYPE_PREDEFINED
 *                      MSF_ICON_RESOURCE_TYPE_FILE                            
 * resource_str_id    : This could be either a resource id to
 *                      a predefined image or it could be a 
 *                      filename.
 * resource_int_id    : image resource identifier
 * 
 **********************************************************************/


#define MSF_ICON_MIME_MAP_TABLE {\
{"image/*"    ,MSF_ICON_RESOURCE_TYPE_PREDEFINED, NULL , MSF_IMAGE_ID_ICON_IMAGE_ANY  },\
{"audio/*"    ,MSF_ICON_RESOURCE_TYPE_PREDEFINED, NULL , MSF_IMAGE_ID_ICON_AUDIO_ANY  },\
{"image/jpeg" ,MSF_ICON_RESOURCE_TYPE_PREDEFINED, NULL , MSF_IMAGE_ID_ICON_IMAGE_JPEG },\
{"*/*"        ,MSF_ICON_RESOURCE_TYPE_PREDEFINED, NULL , MSF_IMAGE_ID_ICON_ANY        },\
{NULL         ,0                                , NULL , 0                            },\
}

/**********************************************************************
 * Misc Configuration for Save as
 **********************************************************************/
/* a safety net: if the disk space is below MSF_SAVE_AS_FREE_SPACE_WATERMARK, we delete the downloaded files */
#define MSF_SAVE_AS_FREE_SPACE_WATERMARK (10*1024)

/* maximum size for download */
#define MSF_MAX_DOWNLOAD_SIZE (325*1024)

/* Deprecated. We allow WAP download of any size on public disk drive */
#define MAX_TOTAL_DOWNLOAD_SIZE   (10*1024*1024) 

/* Minimum disk free space for image cache in filesystem 
 * It should be larger than the biggest MMS media object to prevent filesystem full. */
#define WIDGET_RAWFILE_FREE_SPACE_WATERMARK	(55*1024)

#define WIDGET_RAWFILE_RESERVE_SPACE_MIN	(1024)

#define WIDGET_RAWFILE_RESERVE_SPACE_MAX 	(80*1024)

/* The virtual path to cache image/sound files in filesystem (map to Z:\@wcache) */
#define WIDGET_RAWFILE_DIRECTORY "/wcache/common/"
#define WIDGET_RAWFILE_DIRECTORY_LEN (15)

#define WIDGET_RAWFILE_MMS_DIRECTORY "/wcache/mms/"
#define WIDGET_RAWFILE_MMS_DIRECTORY_LEN (12)


/**************************************************
 * MAUI
 **************************************************/
#define MSF_FILE_TIMER_ID 0
#define MSF_MSM_TIMER_ID  1
#define MSF_POWEROFF_TIMER_ID 2
#define MAX_HDI_FILE_NAME_SIZE     (64)

/* Add memory statistics in WAP menu */
#undef WAP_MEM_DEBUG

/* 
 * Add checksum before and after an allocated memory chunk. 
 * Used to detect memory corruption or memory double release. 
 * Because it has space overheads in memory consumption , it should not be used
 * in production load.
 */
#define WAP_MEM_CHECK

/* Use ADM  in system service instead of default WAP memory allocator */
#undef WAP_USE_ADM

/* Use aplication-shared memory */
#ifndef __MED_MEM_POOL__
#define __MED_MEM_POOL__
#endif
#if defined(APPMEM_SUPPORT)||defined(__MED_MEM_POOL__)
#define WAP_USE_ASM
#endif /* APPMEM_SUPPORT */

/* Queue Push When WAP is not ready at power on stage */
#define WAP_QUEUE_SMS_PUSH

// real root folder
#define WAP_FS_ROOT_FOLDER 				"/@wap/"
#define WAP_FS_ROOT_FOLDER_STRLEN 		(6)
#undef WAP_SELF_CREATE_ROOT_FOLDER

#ifdef MMS_SUPPORT
/* Zoom images in SMIL only by width, not by height, and let it scrollable */
#define WIDGET_SLIDING_SMIL_SUPPORT			1
/* Add scrollbar support in SMIL */
#define WIDGET_SLIDING_SMIL_VBAR				1

/* Stop GIF animation after SMIL is stopped. */
#define WIDGET_ANIMATION_ON_SMIL_PLAYING	1


#if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__)

#define WIDGET_LARGE_RESOLUTION             1
#define WIDGET_ADVANCED_SMIL_EDITOR			1

#ifdef __MMI_MAINLCD_320X240__
#define WIDGET_LANDSCAPE_STYLE              1
#endif

#else /* #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) */

/* __MMI_MAINLCD_128X128__ || __MMI_MAINLCD_128X160__ */
#define WIDGET_SMALL_RESOLUTION             1

#endif /* #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) */


/* Disable word wrapping in SMIL player */
#define WIDGET_SMIL_DISABLE_WORD_WRAPPING	1

#endif /* MMS_SUPPORT */

/* Pre-cache images in layer memory (typically used by SMIL player and editor) */
#if defined(__GDI_MEMORY_PROFILE_2__)
#define WIDGET_PRECACHE_IMAGE	1
#else
#undef WIDGET_PRECACHE_IMAGE
#endif

/*
 *
 * WIDGET/BRS related
 */

extern MSF_INT16 widget_get_scrollbar_width(void);
#define MSF_CFG_SCROLLBAR_WIDTH	(widget_get_scrollbar_width())

/* Extension of MsfSoundFormat */
typedef enum {
	MsfImelody = 0x80,
	MsfAmrWB,
	MsfWma,
	MsfAac,
	MsfM4a,
	MsfAiff,
	MsfBasic
} MsfSoundFormatExt;

/* Extension of MsfImageFormat */
typedef enum {
    /* Predefined Image */
	MsfPI_Start = 0x80,
    MsfPbmPI,
	MsfAbmPI,
    MsfGifPI,
    MsfBmpPI,
    MsfJpegPI,
    MsfPngPI,
    MsfPI_End
} MsfImageFormatExt;


/*
 * Remember that flash erase time is 0.7 sec
 * although it typically taks only a few hundred milliseconds
 */
#define WAP_SHUTDOWN_MAX_TIME     (3000)

#define HDI_FILE_SET_CUSTOM_BLOCKING (1<<14)

typedef enum
{
   WAP_MEM_POOL,
#ifdef WAP_USE_ASM
   WAP_APP_MEM_POOL,
#endif   
   WAP_MEM_POOL_NUM
} wap_mem_enum;

typedef enum
{
   WAP_RUNNING,
   WAP_RESET_ONGOING,
   WAP_RESET_COMPLETE
} wap_reset_enum;

typedef enum
{
   WAP_ACTION_NONE,
   WAP_ACTION_FIRST_POWER_ON,
   WAP_ACTION_POWER_ON,
   WAP_ACTION_POWER_OFF,
   WAP_ACTION_RESET,
   WAP_ACTION_SHUTDOWN,
   WAP_ACTION_RESET_BEFORE_RESTORE_FACTORY_SETTING,
   WAP_ACTION_RESTORE_FACTORY_SETTING,
   WAP_ACTION_FMT_FORMAT
} wap_task_action_enum;

typedef enum
{
   WAP_PROV_ACTION
} wap_action_enum;
   
/**************************************************
 * backup rules
 **************************************************/
#define MSM_NUM_CRITICAL_FILES (1)

/* remember to modify MSM_BACKUP_CHECKSUM_PATH_VALUES when changing this */
#define MSM_CRITICAL_FILES_VALUES { \
	"/bra/profiles.dat" \
}

#define MSM_CRITICAL_FILES_BACKUP_VALUES { \
	"/bra/profiles.bks"\
}

/* whether to compute the checksum of the corresponding files during poweroff  (values: 0 or 1) */
#define MSM_CRITICAL_FILES_CHECKSUM_POWEROFF_VALUES { \
	1 \
}

/* index of each files */
enum 
{
	MSM_BACKUP_INDEX_BRA_PROFILE = 0
};

/* paths that should exist before compute checksum & backup */
#define MSM_NUM_BACKUP_CHECKSUM_PATH        (1)
#define MSM_BACKUP_CHECKSUM_PATH_VALUES { \
	"\\msm"	\
}

/****************************************************************************
 * Kevin: Deal with the corruption of index files.
 *
 * the handling is different from critical files:
 * when we detects the index file is been corrupted, we delete all files
 * under the folder.
 ****************************************************************************/
#define MSM_NUM_INDEX_FILES (3)


#define MSM_INDEX_FILES_VALUES {\
   "/stk/cache/index.dat",\
   "/stk/cookie/index.dat",\
   "/stk/auth/index.dat"\
}
    
#define MSM_INDEX_FILES_FOLDER_VALUES {\
   "/stk/cache",\
   "/stk/cookie",\
   "/stk/auth"\
}

/* paths that should exist before compute checksum & backup */
#define MSM_NUM_IDX_FILE_PATH        (4)
#define MSM_IDX_FILE_PATH_VALUES { \
    "\\stk",	\
    "\\stk\\cache",	\
    "\\stk\\cookie",    \
    "\\stk\\auth"       \
}


   
/****************************************************************************
 * Kevin: Deal with the corruption of security files.
 * 
 * when we detects the sec files been corrupted, 
 * copy security files from backup folder.
 ****************************************************************************/
#define MSM_SEC_PATH              "/sec/storage"

/* paths that should exist before computing checksum */
#define MSM_NUM_SEC_FILE_PATH        (2)
#define MSM_SEC_FILE_PATH_VALUES { \
    "\\sec",	\
    "\\sec\\storage"\
}

#define FILE_DEBUG_VERBOSE		(0)

#endif


