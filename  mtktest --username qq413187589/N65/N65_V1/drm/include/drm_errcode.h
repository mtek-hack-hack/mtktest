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

/*******************************************************************************
 * Filename:
 * ---------
 * drm_def.h
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
#ifndef DRM_ERRCODE_H
#define DRM_ERRCODE_H
#include "fs_errcode.h"

typedef enum
{
    DRM_RESULT_BEGIN                = -0x00010000,
    DRM_RESULT_NOT_SUPPORT          = -0x00020000,
    DRM_RESULT_NON_DRM              = -0x00030000,
    DRM_RESULT_NOT_ARCHIVE          = -0x00040000,
    DRM_RESULT_FS_ERROR             = -0x00050000,
    DRM_RESULT_BAD_CONTENT_TYPE     = -0x00060000,
    DRM_RESULT_INVALID_FORMAT       = -0x00070000,
    DRM_RESULT_INVALID_PATH         = -0x00080000,
    DRM_RESULT_SIZE_TOO_BIG         = -0x00090000,
    DRM_RESULT_NO_PERMISSION        = -0x000A0000,
    DRM_RESULT_FILE_EXISTS          = -0x000B0000,
    DRM_RESULT_INVALID_KEY          = -0x000C0000,
    DRM_RESULT_INVALID_RIGHT        = -0x000D0000,
    DRM_RESULT_INVALID_PARA         = -0x000E0000,
    DRM_RESULT_INVALID_CERT         = -0x000F0000,
    DRM_RESULT_CERT_EXPIRED         = -0x00100000,
    DRM_RESULT_EOF                  = -0x00110000,
    DRM_RESULT_TRUNCATED            = -0x00120000,
    DRM_RESULT_BUSY                 = -0x00130000,
    DRM_RESULT_CANCELED             = -0x00140000,
    DRM_RESULT_TOO_MANY_FILES       = -0x00150000,
    DRM_RESULT_NO_MEMORY            = -0x00160000,
    DRM_RESULT_DATA_NOT_FOUND       = -0x00170000,
    DRM_RESULT_KEY_NOT_FOUND        = -0x00180000,
    DRM_RESULT_CERT_NOT_FOUND       = -0x00190000,
    DRM_RESULT_NOT_IN_DOMAIN        = -0x001A0000,
    DRM_RESULT_NOT_REGISTERED       = -0x001B0000,
    DRM_RESULT_NO_RIGHTS            = -0x001C0000,

    DRM_RESULT_REGISTRATION_FAILED  = -0x001D0000,
    DRM_RESULT_JOIN_DOMAIN_FAILED   = -0x001E0000,
    DRM_RESULT_LEAVE_DOMAIN_FAILED  = -0x001F0000,
    DRM_RESULT_DOMAIN_EXPIRED       = -0x00200000,
    DRM_RESULT_SIGNATURE_ERROR      = -0x00210000,
    DRM_RESULT_NEED_DOMAIN_UPGD     = -0x00220000,
    DRM_RESULT_INVALID_DRMTIME      = -0x00230000,
    DRM_RESULT_NETWORK_ERROR        = -0x00240000,
    DRM_RESULT_DATABASE_ERROR       = -0x00250000,
    DRM_RESULT_TIME_UNTRUSTED       = -0x00260000,

    DRM_RESULT_UNKNOWN_ERROR        = -0x0FFF0000,

    DRM_PROC_ENCRYPT_FAIL			= -0x10000000,
    DRM_PROC_ENCRYPT_OCCUPIED       = -0x11000000,
    DRM_PROC_ENCRYPT_BUSY           = -0x12000000,
    DRM_PROC_ENCRYPT_CANCELING      = -0x13000000,
    DRM_PROC_ENCRYPT_CANCELED       = -0x14000000,
    DRM_PROC_ENCRYPT_FINISHED       = -0x15000000,

    DRM_RESULT_INVALID              = -0x7FFF0000,
    DRM_RESULT_OK = 0,
    DRM_PROC_ENCRYPT_READY = 0
} drm_proc_enum;
#endif /* DRM_ERRCODE_H */ 

