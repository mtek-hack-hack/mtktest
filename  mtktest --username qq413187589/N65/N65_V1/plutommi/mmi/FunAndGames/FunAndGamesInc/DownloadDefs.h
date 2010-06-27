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
 * DownloadDefs.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant value, enum value and data structures for download application.
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : DownloadDefs.h

   PURPOSE     : Resource IDs for the FunAndGames Application

   REMARKS     : nil

   AUTHOR      : Gurinder

   DATE     : 

**************************************************************/

#ifndef _MMI_DOWNLOADDEFS_H
#define _MMI_DOWNLOADDEFS_H
#include "MMIDataType.h"
#include "MMI_features.h"
#include "custom_mmi_default_value.h"
/* 
 * Define
 */

#define MAX_IMAGE_HEADER_LENGTH           6
#define MAX_IMAGE_NAME_EXTENSION_WIDTH    (5*ENCODING_LENGTH)
#define MAX_IMAGE_NAME_WIDTH           ((13*ENCODING_LENGTH)   +  MAX_IMAGE_NAME_EXTENSION_WIDTH + ENCODING_LENGTH)
#define MAX_IMAGE_NAME_PATH_WIDTH         (32*ENCODING_LENGTH)  /* Update if a long path added */
#define MAX_AUDIO_NAME_WIDTH           ((13*ENCODING_LENGTH)   +  MAX_IMAGE_NAME_EXTENSION_WIDTH + ENCODING_LENGTH)
#define MAX_SEARCH_STR_LENGTH          (15*ENCODING_LENGTH)

#define PLAY_DOWNLOAD_AUDIO_TIMEOUT    2000

#define     MAXIMUM_EMS_DOWNLOAD_IMELODY     5
#define     MAXIMUM_DOWNLOAD_IMAGES          15
#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
#define     MAXIMUM_PICTURE_EDITOR_IMAGES    5
#endif 
#define     MAXIMUM_DOWNLOAD_AUDIO           15
#define     MAXIMUM_DOWNLOAD_IMELODY         MAXIMUM_DOWNLOAD_AUDIO
#define     MAXIMUM_COMPOSED_RINGTONE        5

#define MAXIMUM_FULLSCREEN_FACTORY_IMAGES       7
#define MAXIMUM_ASSOCIATED_FACTORY_IMAGES       5
#define     MAXIMUM_FACTORY_TONES            5
#define     MAXIMUM_FACTORY_IMELODY          5

/* Leo add for DLT */
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define         MAXIMUM_THEMES_TONES                 1  /* ritesh */
#endif 
/* Leo end */

#define     FULLSCREEN_FACTORY_IMAGE_PATH    "C:\\def_image\\fullscreen\\"
#define     ASSOCIATE_FACTORY_IMAGE_PATH     "C:\\def_image\\associate\\"
#define     DOWNLOADED_IMAGE_PATH            "C:\\User\\image\\standard\\"

#define     FACTORY_TONE_PATH             "C:\\def_sound\\other\\"
#define     FACTORY_IMELODY_PATH          "C:\\def_sound\\imelody\\"
#define     DOWNLOAD_TONE_PATH               "C:\\User\\sound\\other\\"
#define     DOWNLOAD_IMELODY_PATH            "C:\\User\\sound\\imelody\\"
extern S16 RINGCOMPOSER_PATH[];

#define     RNGC_PATH1              "User\\"
#define     RNGC_PATH2              "sound\\"
#define     RNGC_PATH3              "compose\\"
#define     AST_SEARCH_STR                "*.*"

#define     NV_RAM_FILE_IMAGE_ID_BASE_END    (NV_RAM_FILE_IMAGE_ID_BASE + 999)

#define     FULLSCREEN_FACTORY_IMAGE_BASE    (NV_RAM_FILE_IMAGE_ID_BASE)
#define     FULLSCREEN_FACTORY_IMAGE_BASE_END   (FULLSCREEN_FACTORY_IMAGE_BASE + MAXIMUM_FULLSCREEN_FACTORY_IMAGES - 1)

#define     ASSOCIATED_FACTORY_IMAGE_BASE    (FULLSCREEN_FACTORY_IMAGE_BASE_END + 1)
#define     ASSOCIATED_FACTORY_IMAGE_BASE_END   (ASSOCIATED_FACTORY_IMAGE_BASE + MAXIMUM_ASSOCIATED_FACTORY_IMAGES - 1)

#define     DOWNLOAD_IMAGE_BASE              (ASSOCIATED_FACTORY_IMAGE_BASE_END + 1)
#define     DOWNLOAD_IMAGE_BASE_END          (DOWNLOAD_IMAGE_BASE + MAXIMUM_DOWNLOAD_IMAGES - 1)
#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
#define     PICTURE_EDITOR_IMAGE_BASE        (DOWNLOAD_IMAGE_BASE_END + 1)
#define     PICTURE_EDITOR_IMAGE_BASE_END    (PICTURE_EDITOR_IMAGE_BASE + MAXIMUM_PICTURE_EDITOR_IMAGES - 1)
#define     PICTURE_EDITOR_PATH              "C:\\User\\Image\\Editor\\"
#endif /* __MMI_PICTURE_EDITOR_SUPPORT__ */ 
#define     FACTORY_TONES_BASE               (NV_RAM_FILE_IMAGE_ID_BASE)
#define     FACTORY_TONES_BASE_END           (FACTORY_TONES_BASE + MAXIMUM_FACTORY_TONES - 1)

#define     FACTORY_IMELODY_BASE          (FACTORY_TONES_BASE_END + 1)
#define     FACTORY_IMELODY_BASE_END         (FACTORY_IMELODY_BASE + MAXIMUM_FACTORY_IMELODY - 1)

#define     DOWNLOADED_TONE_BASE          (FACTORY_IMELODY_BASE_END + 1)
#define     DOWNLOADED_TONE_BASE_END         (DOWNLOADED_TONE_BASE + MAXIMUM_DOWNLOAD_AUDIO - 1)

#define     DOWNLOADED_IMELODY_BASE          (DOWNLOADED_TONE_BASE_END + 1)
#define     DOWNLOADED_IMELODY_BASE_END         (DOWNLOADED_IMELODY_BASE + MAXIMUM_DOWNLOAD_IMELODY - 1)

#define     COMPOSED_RINGTONE_BASE           (DOWNLOADED_IMELODY_BASE_END + 1)
#define     COMPOSED_RINGTONE_BASE_END       (COMPOSED_RINGTONE_BASE + MAXIMUM_COMPOSED_RINGTONE - 1)

#define     DOWNLOADED_EMS_IMELODY_BASE         (COMPOSED_RINGTONE_BASE_END + 1)
#define     DOWNLOADED_EMS_IMELODY_BASE_END     (DOWNLOADED_EMS_IMELODY_BASE + MAXIMUM_EMS_DOWNLOAD_IMELODY - 1)

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define     THEME_V2_TONE_BASE                  (DOWNLOADED_EMS_IMELODY_BASE_END +1)    /* ritesh */
#define     THEME_V2_TONE_BASE_END              (THEME_V2_TONE_BASE +MAXIMUM_THEMES_TONES -1)   /* ritesh */
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

#define     FILESYSTEM_AUDIO_BASE            (NV_RAM_FILE_IMAGE_ID_BASE)
#define     FILESYSTEM_AUDIO_BASE_END        (NV_RAM_FILE_IMAGE_ID_BASE + 999)

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define     CURRENT_THEME_INCOMING_CALL_TONE THEME_V2_TONE_BASE
#define     CURRENT_THEME_ALARM_EXPIRY_TONE     THEME_V2_TONE_BASE
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
/* 
 * Typedef 
 */
typedef struct
{
    U16 CurrAudioId;
    U8 CurrHiliteImage;
    U8 TotalFacAssoImages;
    U8 TotalFacFullScrImages;
    U8 TotalFacTones;
    U8 TotalFacIMelodies;
    U8 AddToHistFlag;
} dwnl_context_struct;

typedef struct
{
    union
    {
        DYNIMAGEINFO *ImageInfo;
        DYNAUDIOINFO *AudioInfo;
    } DYNINFOUNION;
    U8 DynInfoType; /* IMAGEINFO, AUDIOINFO */
    U8 NoOfEntries;
} DYNAMICINFO;

typedef enum
{
    IMAGEINFO = 0,
    AUDIOINFO
} DynamicInfoType;

#endif /* _MMI_DOWNLOADDEFS_H */ // #ifndef _MMI_DOWNLOADDEFS_H

