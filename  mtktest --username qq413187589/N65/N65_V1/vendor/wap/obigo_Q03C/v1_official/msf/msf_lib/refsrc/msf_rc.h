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
 * msf_rc.h
 * 
 * Description: This file implement the Common resources needed 
 *              by MSM, Packages, and other modules.
 *    
 */


#ifndef _msf_rc_h
#define _msf_rc_h

#ifndef _msf_cfg_h 
#include "msf_cfg.h"
#endif

#ifndef WAP_SUPPORT
#define MSF_NORMAL_NUMBER_OF_STRINGS 55

#ifdef CONTENT_OBJECT_ACTION_DISABLE
  #define MSF_NUMBER_OF_STRINGS (MSF_NORMAL_NUMBER_OF_STRINGS+1)
#else
  #define MSF_NUMBER_OF_STRINGS (MSF_NORMAL_NUMBER_OF_STRINGS+0)
#endif


extern const char * const msf_strings[][MSF_NUMBER_OF_STRINGS+1];

#define MSF_STR_ID_ROOT_FOLDER_PICTURE         (MSF_MODID_MSM + 0x0100)  /*"Pictures"*/
#define MSF_STR_ID_ROOT_FOLDER_SOUND           (MSF_MODID_MSM + 0x0200)  /*"Sounds"*/
#define MSF_STR_ID_ROOT_FOLDER_VIDEO           (MSF_MODID_MSM + 0x0300)  /*"Videos"*/
#define MSF_STR_ID_ROOT_FOLDER_APP             (MSF_MODID_MSM + 0x0400)  /*"Applications"*/
#define MSF_STR_ID_ROOT_FOLDER_ANIM            (MSF_MODID_MSM + 0x0500)  /*"Animations"*/
#define MSF_STR_ID_ROOT_FOLDER_EXT             (MSF_MODID_MSM + 0x0600)  /*"External"*/
#define MSF_STR_ID_DLG_ACTION_OK               (MSF_MODID_MSM + 0x0700)  /*"Ok"*/
#define MSF_STR_ID_DLG_ACTION_BACK             (MSF_MODID_MSM + 0x0800)  /*"Back"*/
#define MSF_STR_ID_DLG_ACTION_CANCEL           (MSF_MODID_MSM + 0x0900)  /*"Cancel"*/
#define MSF_STR_ID_DLG_ACTION_SAVE             (MSF_MODID_MSM + 0x0a00)  /*"Save"*/
#define MSF_STR_ID_DLG_TEXT_EDIT_FILENAME      (MSF_MODID_MSM + 0x0b00)  /*"Edit filename"*/
#define MSF_STR_ID_DLG_TEXT_ROOT_FOLDER        (MSF_MODID_MSM + 0x0c00)  /*"Root folder"*/
#define MSF_STR_ID_DLG_TEXT_SAVE_HERE          (MSF_MODID_MSM + 0x0d00)  /*"Save here"*/
#define MSF_STR_ID_DLG_EXISTS_TEXT1            (MSF_MODID_MSM + 0x0e00)  /*""*/
#define MSF_STR_ID_DLG_EXISTS_TEXT2            (MSF_MODID_MSM + 0x0f00)  /*" already exists. Do you want to replace it?"*/
#define MSF_STR_ID_DLG_EXISTS_TITLE            (MSF_MODID_MSM + 0x1000)  /*"File exists"*/
#define MSF_STR_ID_DLG_NO_REPLACE_TEXT1        (MSF_MODID_MSM + 0x1100)  /*""*/
#define MSF_STR_ID_DLG_NO_REPLACE_TEXT2        (MSF_MODID_MSM + 0x1200)  /*" already exists and cannot be replaced."*/
#define MSF_STR_ID_DLG_NO_REPLACE_TITLE        (MSF_MODID_MSM + 0x1300)  /*"File exists"*/
#define MSF_STR_ID_DLG_SAVE_ERROR              (MSF_MODID_MSM + 0x1400)  /*"Save Error"*/
#define MSF_STR_ID_DLG_SAVE_NOT_ALLOWED        (MSF_MODID_MSM + 0x1500)  /*"This file type may not be saved."*/
#define MSF_STR_ID_USER_FOLDER_NATURE          (MSF_MODID_MSM + 0x1600)  /*"Nature pictures"*/
#define MSF_STR_ID_USER_FOLDER_WORK            (MSF_MODID_MSM + 0x1700)  /*"Work pictures"*/
#define MSF_STR_ID_USER_FOLDER_VACATION        (MSF_MODID_MSM + 0x1800)  /*"Vacation pictures"*/
#define MSF_STR_ID_USER_FOLDER_MUSIC           (MSF_MODID_MSM + 0x1900)  /*"My music"*/
#define MSF_STR_ID_USER_FOLDER_SOUNDS          (MSF_MODID_MSM + 0x1a00)  /*"My sounds"*/
#define MSF_STR_ID_SAS_BAR_TITLE               (MSF_MODID_MSM + 0x1b00)  /*"Saving..."*/
#define MSF_STR_ID_SAS_ACTION_CANCEL           (MSF_MODID_MSM + 0x1c00)  /*"Cancel"*/
#define MSF_STR_ID_SAS_ERROR_TITLE             (MSF_MODID_MSM + 0x1d00)  /*"Unexpected error"*/
#define MSF_STR_ID_SAS_ERROR_FULL              (MSF_MODID_MSM + 0x1e00)  /*"The memory is full"*/
#define MSF_STR_ID_SAS_ERROR_SIZE              (MSF_MODID_MSM + 0x1f00)  /*"File size exceeds the file system maximum file size"*/
#define MSF_STR_ID_MIME_ACTION_SAVE            (MSF_MODID_MSM + 0x2000)  /*"Save As"*/
#define MSF_STR_ID_MIME_ACTION_SEND_AS_MMS     (MSF_MODID_MSM + 0x2100)  /*"Send as MMS"*/
#define MSF_STR_ID_MIME_ACTION_SET             (MSF_MODID_MSM + 0x2200)  /*"Set"*/
#define MSF_STR_ID_MIME_ACTION_SET_SCREENSAVER (MSF_MODID_MSM + 0x2300)  /*"Set screensaver"*/
#define MSF_STR_ID_MIME_ACTION_SET_GREETING    (MSF_MODID_MSM + 0x2400)  /*"Set greeting"*/
#define MSF_STR_ID_MIME_ACTION_SET_WALLPAPER   (MSF_MODID_MSM + 0x2500)  /*"Set wallpaper"*/
#define MSF_STR_ID_DLG_ACTION_CREATE_DIR       (MSF_MODID_MSM + 0x2600)  /*"Create folder"*/
#define MSF_STR_ID_DLG_TITLE_CREATE_DIR        (MSF_MODID_MSM + 0x2700)  /*"Create new folder"*/
#define MSF_STR_ID_DLG_ERROR_CREATE_DIR        (MSF_MODID_MSM + 0x2800)  /*"Could not create folder with the specified name."*/
#define MSF_STR_ID_DLG_COMMON_ERROR            (MSF_MODID_MSM + 0x2900)  /*"Error"*/
#define MSF_STR_ID_DLG_ERROR_NAME              (MSF_MODID_MSM + 0x2a00)  /*"The specified name is not valid."*/
#define MSF_STR_ID_SAS_PERCENT                 (MSF_MODID_MSM + 0x2b00)  /*" % done."*/
#define MSF_STR_ID_SAS_BYTES_SAVED             (MSF_MODID_MSM + 0x2c00)  /*" bytes saved. "*/
#define MSF_STR_ID_DLG_CANNOT_SAVE             (MSF_MODID_MSM + 0x2d00)  /*"Cannot save this file type!"*/
#define MSF_STR_ID_PROPERTIES_SIZE2            (MSF_MODID_MSM + 0x2e00)  /*"."*/
#define MSF_STR_ID_PROPERTIES_SIZE3            (MSF_MODID_MSM + 0x2f00)  /*" kBytes"*/
#define MSF_STR_ID_PROPERTIES_SIZE4            (MSF_MODID_MSM + 0x3000)  /*" MBytes"*/
#define MSF_STR_ID_PROPERTIES_SIZE5            (MSF_MODID_MSM + 0x3100)  /*" Bytes"*/
#define MSF_STR_ID_DLG_MIME_ACTION_NONE        (MSF_MODID_MSM + 0x3200)  /*"Unsupported content."*/
#define MSF_STR_ID_MIME_ACTION_SET_RINGTONE    (MSF_MODID_MSM + 0x3300)  /*"Set ringtone"*/
#define MSF_STR_ID_ROOT_FOLDER_BKM             (MSF_MODID_MSM + 0x3400)  /*"My Bookmarks"*/
#define MSF_STR_ID_ROOT_FOLDER_OFLN_PGS        (MSF_MODID_MSM + 0x3500)  /*"Offline Pages"*/
#define MSF_STR_ID_ROOT_FOLDER_BKM_PERS        (MSF_MODID_MSM + 0x3600)  /*"Persistent Bookmarks"*/
#define MSF_STR_ID_DLG_EXISTS_LOCKED           (MSF_MODID_MSM + 0x3700)  /*"File exists and is protected"*/ 

#ifdef CONTENT_OBJECT_ACTION_DISABLE
#define MSF_STR_ID_CONTENT_UNKNOWN            (MSF_MODID_MSM + 0x3800)  /*"Unknown content or filetype."*/
#endif
#endif

#include "wap.h"

/*Predefined images*/
#define MSF_NUMBER_OF_IMAGES 4

extern const unsigned char * const msf_images[MSF_NUMBER_OF_IMAGES+1];

#define MSF_IMAGE_ID_ICON_IMAGE_ANY            (MSF_MODID_MSM + 0x0100)
#define MSF_IMAGE_ID_ICON_IMAGE_JPEG           (MSF_MODID_MSM + 0x0200) 
#define MSF_IMAGE_ID_ICON_ANY                  (MSF_MODID_MSM + 0x0300) 
#define MSF_IMAGE_ID_ICON_AUDIO_ANY            (MSF_MODID_MSM + 0x0400) 

#endif
