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
 *  SlideShowDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Slideshow Header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SLIDESHOWDEFS_H_
#define _SLIDESHOWDEFS_H_

/***************************************************************************** 
* Image ID
*****************************************************************************/
typedef enum
{
    IMG_ID_SLIDSHOW_APP = SLIDESHOW_BASE + 1,
    IMG_ID_SLIDSHOW_SETTING_TYPE_OF_PLAY,
    IMG_ID_SLIDSHOW_SETTING_SPEED,
    IMG_ID_SLIDSHOW_SETTING_EFFECT,
    IMG_ID_SLIDSHOW_SETTING_BACK_SOUND,
    IMG_ID_SLIDSHOW_SETTING_HORZ_DISPLAY,
    IMG_ID_SLIDSHOW_SETTING_SOUND_EFFECT,
    IMG_ID_SLIDSHOW_LEFT_ARROW,
    IMG_ID_SLIDSHOW_LEFT_ARROW_SEL,
    IMG_ID_SLIDSHOW_RIGHT_ARROW,
    IMG_ID_SLIDSHOW_RIGHT_ARROW_SEL
} slideshow_img_id_enum;

typedef enum
{
    SCR_ID_SLIDSHOW_APP = SLIDESHOW_BASE + 1,
    SCR_ID_SLIDSHOW_FMGR,
    SCR_ID_SLIDSHOW_OPTION,
    SCR_ID_SLIDSHOW_OPTION_EDIT,
    SCR_ID_SLIDSHOW_PLAY,
    SCR_ID_SLIDSHOW_SETTING,
    SCR_ID_SLIDSHOW_BGM_FILE_OPTION
} slideshow_scr_id_enum;

typedef enum
{
   /************* Slide Show **************/
    STR_ID_SLIDSHOW_APP = SLIDESHOW_BASE + 1,
    STR_ID_SLIDSHOW_NOTIFY_SELECT_FOLDER,
    STR_ID_SLIDSHOW_PLAY,
    STR_ID_SLIDSHOW_SETTING,
    STR_ID_SLIDSHOW_RESUME,
    STR_ID_SLIDSHOW_PAUSE,
    STR_ID_SLIDSHOW_TYPE_OF_PLAY,
    STR_ID_SLIDSHOW_SPEED,
    STR_ID_SLIDSHOW_EFFECT,
    STR_ID_SLIDSHOW_BGM,
    STR_ID_SLIDSHOW_HORIZONTAL_DISPLAY,
    STR_ID_SLIDSHOW_SOUND_EFFECT,
    STR_ID_SLIDSHOW_AUTO_ONCE,
    STR_ID_SLIDSHOW_AUTO_REPEAT,
    STR_ID_SLIDSHOW_MANUAL,
    STR_ID_SLIDSHOW_LOW,
    STR_ID_SLIDSHOW_MEDIUM,
    STR_ID_SLIDSHOW_FAST,
    STR_ID_SLIDSHOW_NORMAL,
    STR_ID_SLIDSHOW_FADE_IN,
    STR_ID_SLIDSHOW_SPLIT,
    STR_ID_SLIDSHOW_WIPE,
    STR_ID_SLIDSHOW_RANDOM,
    STR_ID_SLIDSHOW_SELECT_BGM,
    STR_ID_SLIDSHOW_AUD1,
    STR_ID_SLIDSHOW_AUD2,
    STR_ID_SLIDSHOW_AUD3,
    STR_ID_SLIDSHOW_ASSOCIATE_AUDIO,
    STR_ID_SLIDSHOW_PLAY_AUDIO,
    STR_ID_SLIDSHOW_SAVE_SETTING
} slideshow_str_id_enum;

/* audio id */
typedef enum
{
    AUD_ID_SLIDSHOW_BASE = SLIDESHOW_BASE + 1,
    AUD_ID_SLIDSHOW_1,
    AUD_ID_SLIDSHOW_2,
    AUD_ID_SLIDSHOW_3
} slideshow_aud_id_enum;

#endif /* _SLIDESHOWDEFS_H_ */ 

