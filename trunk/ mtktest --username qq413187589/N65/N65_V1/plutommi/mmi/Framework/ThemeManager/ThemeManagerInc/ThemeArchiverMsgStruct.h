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

   FILENAME : ThemeArchiverMsgStruct.h

   PURPOSE     : Theme Archiver

   REMARKS     : nil

   AUTHOR      : Alok

   DATE     : April 14,05

**************************************************************/

#ifndef _MMI_THEME_ARCHIVER_MSG_STRUCT_H
#define _MMI_THEME_ARCHIVER_MSG_STRUCT_H

#include "MMI_features.h"

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
typedef enum
{
    DA_THEME_DATA = 1,
    DA_DESCRIPTOR_DATA,
    NON_DESCRIPTOR_THEME_DATA
} TA_DA_CONTENT_TYPE_ENUM;

typedef enum
{
    DLT_NO_ERROR,
    DLT_ERROR_CREATE_FILE,
    DLT_ERROR_DOWNLOAD_FILE,
    DLT_ERROR_CONNECTION_ABORT,
    DLT_ERROR_USER_CANCEL
} TA_DLT_ERROR_TYPE_ENUM;

typedef struct
{
    LOCAL_PARA_HDR U32 content_type;
    U32 size;
    U32 error_code;
    U16 *download_url_p;
    U16 *file_path_name_p;
} ta_da_content_received_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint32 session_id;
    kal_wchar *download_url_p;
    kal_wchar *save_file_path_p;
} ta_da_wap_get_file_req_struct;

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ // #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

#endif /* _MMI_THEME_ARCHIVER_MSG_STRUCT_H */ // #ifndef _MMI_THEME_ARCHIVER_MSG_STRUCT_H

