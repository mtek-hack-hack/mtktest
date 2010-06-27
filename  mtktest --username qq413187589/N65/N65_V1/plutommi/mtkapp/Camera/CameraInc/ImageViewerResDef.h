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
 * ImageViewerResDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ImageViewer resource id define
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_VIEWER_RES_DEF_H_
#define _IMAGE_VIEWER_RES_DEF_H_

/************************************************************************/
/* Define, Structure, Enum                                              */
/************************************************************************/

typedef enum
{
    SCR_ID_IMGVIEW_VIEW = IMAGE_VIEWER_BASE + 1,    /* show thumbnail images */
    SCR_ID_IMGVIEW_OPTION,
    SCR_ID_IMGVIEW_APP,
    SCR_ID_IMGVIEW_STORAGE,
    SCR_ID_IMGVIEW_VIEW_STYLE,
    SCR_ID_IMGVIEW_FROM_FMGR
} SCR_ID_IMGVIEW_ENUM;

typedef enum
{
    STR_ID_IMGVIEW_NAME = IMAGE_VIEWER_BASE + 1,
    STR_ID_IMGVIEW_SET_AS_CAMERA_PATH,
    STR_ID_IMGVIEW_SET_AS_CAMERA_PATH_CONFIRM,
    STR_ID_IMGVIEW_STORAGE,
    STR_ID_IMGVIEW_STORAGE_PHONE,
    STR_ID_IMGVIEW_STORAGE_MEMORY_CARD,
    STR_ID_IMGVIEW_NOTIFY_NO_MEMORY_CARD,
    STR_ID_IMGVIEW_NOTIFY_WRITE_PROTECTION,
    STR_ID_IMGVIEW_PRINT,
    STR_ID_IMGVIEW_PRINT_NOT_SUPPORT,
    STR_ID_IMGVIEW_VIEW_STYLE,
    STR_ID_IMGVIEW_VIEW_STYLE_INFO,
    STR_ID_IMGVIEW_VIEW_STYLE_LIST,
    STR_ID_IMGVIEW_VIEW_STYLE_MATRIX,
    STR_ID_IMGVIEW_NOTIFY_MULTIPART_NOT_SUPPORT
} STR_ID_IMGVIEW_ENUM;

typedef enum
{
    IMG_ID_IMGVIEW_MAIN_ICON = IMAGE_VIEWER_BASE + 1
} IMG_ID_IMGVIEW_ENUM;

#ifdef __MMI_IMAGEVIEWER_ADV__
typedef enum
{
    SCR_ID_IMAGEVIEWER_VIEW = IMAGE_VIEWER_BASE + 1,    /* show thumbnail images */
    SCR_ID_IMAGEVIEWER_OPTION,
    SCR_ID_IMAGEVIEWER_APP,
    SCR_ID_IMAGEVIEWER_STORAGE,
    SCR_ID_IMAGEVIEWER_VIEW_STYLE
} SCR_ID_IMAGEVIEWER_ENUM;

typedef enum
{
    STR_ID_IMAGEVIEWER_NAME = IMAGE_VIEWER_BASE + 1,
    STR_ID_IMAGEVIEWER_SET_AS_CAMERA_PATH,
    STR_ID_IMAGEVIEWER_SET_AS_CAMERA_PATH_CONFIRM,
    STR_ID_IMAGEVIEWER_STORAGE,
    STR_ID_IMAGEVIEWER_STORAGE_PHONE,
    STR_ID_IMAGEVIEWER_STORAGE_MEMORY_CARD,
    STR_ID_IMAGEVIEWER_NOTIFY_NO_MEMORY_CARD,
    STR_ID_IMAGEVIEWER_NOTIFY_WRITE_PROTECTION,
    STR_ID_IMAGEVIEWER_VIEW_STYLE,
    STR_ID_IMAGEVIEWER_VIEW_STYLE_INFO,
    STR_ID_IMAGEVIEWER_VIEW_STYLE_LIST,
    STR_ID_IMAGEVIEWER_VIEW_STYLE_MATRIX
} STR_ID_IMAGEVIEWER_ENUM;

typedef enum
{
    IMG_ID_IMAGEVIEWER_MAIN_ICON = IMAGE_VIEWER_BASE + 1,
    IMG_ID_IMAGEVIEWER_BACKGROUND,
    IMG_ID_IMAGEVIEWER_LEFT_ARROW_DOWN,
    IMG_ID_IMAGEVIEWER_LEFT_ARROW_UP,
    IMG_ID_IMAGEVIEWER_RIGHT_ARROW_DOWN,
    IMG_ID_IMAGEVIEWER_RIGHT_ARROW_UP,
    IMG_ID_IMAGEVIEWER_ZOOMIN_DOWN,
    IMG_ID_IMAGEVIEWER_ZOOMIN_UP,
    IMG_ID_IMAGEVIEWER_ZOOMOUT_DOWN,
    IMG_ID_IMAGEVIEWER_ZOOMOUT_UP,
    IMG_ID_IMAGEVIEWER_ROTATE_DOWN,
    IMG_ID_IMAGEVIEWER_ROTATE_UP,
    IMG_ID_IMAGEVIEWER_SCREEN_MODE_DOWN,
    IMG_ID_IMAGEVIEWER_SCREEN_MODE_UP,
    IMG_ID_IMAGEVIEWER_BACKGROUND_HORIZONTAL,
    IMG_ID_IMAGEVIEWER_DRM
} IMG_ID_IMAGEVIEWER_ENUM;
#endif /* defined(__MMI_IMAGEVIEWER_ADV__) */ 
#endif /* _IMAGE_VIEWER_RES_DEF_H_ */ 

