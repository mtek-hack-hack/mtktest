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
 *   gui_resource_type.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   GUI Resource Type Definitions
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

#ifndef __GUI_RESOURCE_TYPE_H__
#define __GUI_RESOURCE_TYPE_H__

#include "MMI_features.h"
#include "gdi_const.h"

/* Image Resource Types */
#define IMAGE_TYPE_INVALID                GDI_IMAGE_TYPE_INVALID
#define IMAGE_TYPE_BMP                    GDI_IMAGE_TYPE_BMP
#define IMAGE_TYPE_BMP_SEQUENCE           GDI_IMAGE_TYPE_BMP_SEQUENCE
#define IMAGE_TYPE_GIF                    GDI_IMAGE_TYPE_GIF
#define IMAGE_TYPE_DEVICE_BITMAP          GDI_IMAGE_TYPE_DEVICE_BITMAP
#define IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE
#define IMAGE_TYPE_BMP_FILE               GDI_IMAGE_TYPE_BMP_FILE
#define IMAGE_TYPE_GIF_FILE               GDI_IMAGE_TYPE_GIF_FILE
#define IMAGE_TYPE_WBMP_FILE              GDI_IMAGE_TYPE_WBMP_FILE
#define IMAGE_TYPE_JPG                    GDI_IMAGE_TYPE_JPG
#define IMAGE_TYPE_JPG_FILE               GDI_IMAGE_TYPE_JPG_FILE
#define IMAGE_TYPE_WBMP                   GDI_IMAGE_TYPE_WBMP
#define IMAGE_TYPE_AVI                    GDI_IMAGE_TYPE_AVI
#define IMAGE_TYPE_AVI_FILE               GDI_IMAGE_TYPE_AVI_FILE
#define IMAGE_TYPE_3GP                    GDI_IMAGE_TYPE_3GP
#define IMAGE_TYPE_3GP_FILE               GDI_IMAGE_TYPE_3GP_FILE
#define IMAGE_TYPE_MP4                    GDI_IMAGE_TYPE_MP4
#define IMAGE_TYPE_MP4_FILE               GDI_IMAGE_TYPE_MP4_FILE
#define IMAGE_TYPE_JPG_SEQUENCE           GDI_IMAGE_TYPE_JPG_SEQUENCE
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define IMAGE_TYPE_BMP_FILE_OFFSET        GDI_IMAGE_TYPE_BMP_FILE_OFFSET
#define IMAGE_TYPE_GIF_FILE_OFFSET        GDI_IMAGE_TYPE_GIF_FILE_OFFSET
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#define IMAGE_TYPE_PNG                    GDI_IMAGE_TYPE_PNG
#define IMAGE_TYPE_PNG_SEQUENCE           GDI_IMAGE_TYPE_PNG_SEQUENCE
#define IMAGE_TYPE_PPN                    (GDI_IMAGE_TYPE_SUM + 1)
#define IMAGE_TYPE_M3D                    GDI_IMAGE_TYPE_M3D
#define IMAGE_TYPE_SWFLASH                GDI_IMAGE_TYPE_SWFLASH
#define IMAGE_TYPE_SVG                    GDI_IMAGE_TYPE_SVG
#define IMAGE_TYPE_SVG_FILE               GDI_IMAGE_TYPE_SVG_FILE
#define IMAGE_TYPE_ABM                    GDI_IMAGE_TYPE_ABM
#define IMAGE_TYPE_ABM_SEQUENCE           GDI_IMAGE_TYPE_ABM_SEQUENCE
#define IMAGE_TYPE_ABM_FILE_OFFSET        GDI_IMAGE_TYPE_ABM_FILE_OFFSET
#define IMAGE_TYPE_VIS                    GDI_IMAGE_TYPE_VIS
#define IMAGE_TYPE_VIS_FILE               GDI_IMAGE_TYPE_VIS_FILE
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
#define IMAGE_TYPE_ENFB                   255
#endif

/* Audio Resource Types */
#define AUDIO_TYPE_INVALID             0
#define AUDIO_TYPE_MP3                 5
#define AUDIO_TYPE_IMY                 18
#define AUDIO_TYPE_MID                 17
#define AUDIO_TYPE_WAV                 13
#define AUDIO_TYPE_MMF                 20
#define AUDIO_TYPE_PCM                 7
#define AUDIO_TYPE_DVI                 11
#define AUDIO_TYPE_AMR                 3
#define AUDIO_TYPE_AAC                 6
#define AUDIO_TYPE_WMA                 29
#define AUDIO_TYPE_M4A                 25

#endif /* __GUI_RESOURCE_TYPE_H__ */
