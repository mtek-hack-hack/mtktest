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
 * ThemeArchiverDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines string, screen, and image ids for Theme Archiver application.
 *
 * Author:
 * -------
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
 * removed!
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

/**************************************************************

   FILENAME : ThemeArchiverDef.h

   PURPOSE     : Theme Archiver

   REMARKS     : nil

   AUTHOR      : Alok

   DATE     : April 14,05

**************************************************************/
#ifndef _MMI_THEME_ARCHIVER_DEF_H
#define _MMI_THEME_ARCHIVER_DEF_H

#include "MMI_features.h"
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

#define MAX_FILE_NAME_LENGTH        20
#define MAX_VERSION_LENGTH           5
#define MAX_URL_LENGTH              20
#define MAX_FILE_TYPE_LENGTH        10
#define MAX_MODEL_NAME_LENGTH       20
#define MAX_FILE_SIZE_LENGTH        20
#define MAX_DESCRIPTOR_ELEMENTS_NUM     8
#define MAX_ACCEPTABLE_THEME_FILE_TYPE  2
#define MAX_LCD_STRING_SIZE                 10

typedef enum
{
    CONTENT_TYPE_OMA,
    CONTENT_TYPE_NON_OMA
} TA_DA_DESCRIPTOR_TYPE_ENUM;

typedef enum
{
    DLT_TYPE,
    DLT_URI,
    DLT_SIZE,
    DLT_VERSION,
    DLT_NOTIFY_URI,
    DLT_FILE_NAME,
    DLT_LCD_HEIGHT,
    DLT_LCD_WIDTH
} TA_DESCRIPTOR_TAG_TYPE_ENUM;


typedef struct
{
    U8 current_hilite_storage_type;
    FLOAT da_file_size;
    S8 file_name_with_path[(FMGR_MAX_PATH_LEN + FMGR_MAX_FILE_LEN) *ENCODING_LENGTH];
    U16 curr_storage_type;
    U8 num_theme_type;
 } ta_da_context_struct;

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ // #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

#endif /* _MMI_THEME_ARCHIVER_DEF_H */ // #ifndef _MMI_THEME_ARCHIVER_DEF_H

