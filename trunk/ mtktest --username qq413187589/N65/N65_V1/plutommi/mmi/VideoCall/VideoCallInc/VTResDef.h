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
 *  VTResDef.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Resource enum for MMI VT application
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VT_RES_DEF_H
#define VT_RES_DEF_H

#include "MMIDatatype.h"

typedef enum
{
    STR_ID_VT_VIDEO_CALL = (VT_BASE + 1),
    STR_ID_VT_MAKE_VIDEO_CALL,
    STR_ID_VT_START_CAMERA,
    STR_ID_VT_STOP_CAMERA,
    STR_ID_VT_MUTE_MIC,
    STR_ID_VT_UNMUTE_MIC,
    STR_ID_VT_MUTE_SPEAKER,
    STR_ID_VT_UNMUTE_SPEAKER,
    STR_ID_VT_SWITCH_PIC,
    STR_ID_VT_HIDE_SMALL_PIC,
    STR_ID_VT_UNHIDE_SMALL_PIC,
    STR_ID_VT_ALTERNATIVE_PIC,
    STR_ID_VT_VIDEO_CALL_SETTING,
    STR_ID_VT_ADVANCED,
    STR_ID_VT_ANSWER_MODE,
    STR_ID_VT_DIAL_MODE,
    STR_ID_VT_IMAGE_IN_VIDEO_CALL,
    STR_ID_VT_AUDIO_OPTION,
    STR_ID_VT_PROMPT,
    STR_ID_VT_MIC_OFF,
    STR_ID_VT_SPEAKER_OFF,
    STR_ID_VT_START_CALL_WITH,
    STR_ID_VT_DEFAULT,
    STR_ID_VT_USER_DEFINE,
    STR_ID_VT_FAIL_TO_MAKE_VIDEO_CALL,
    STR_ID_VT_MAKE_VOICE_CALL,
    STR_ID_VT_REDIAL_VIDEO_CALL,
    STR_ID_VT_SEND_MMS,
    STR_ID_VT_SEND_SMS,
    STR_ID_VT_BRIGHTNESS,
    STR_ID_VT_VIDEO_QUALITY,
    STR_ID_VT_RECORD_AUDIO,
    STR_ID_VT_SAVE_PICTURE,
    STR_ID_VT_MIRROR_IMAGE,
    STR_ID_VT_SMOOTH,
    STR_ID_VT_NORMAL,
    STR_ID_VT_SHARP,
    STR_ID_VT_START_CAMERA_QUERY,
    STR_ID_VT_SWITCH_AUDIO_PATH,
    STR_ID_VT_TOTAL
} vt_string_enum;

typedef enum
{
    IMG_ID_VT_OUTGOING_CALL = (VT_BASE + 1),
    IMG_ID_VT_TOTAL
} vt_image_enum;

typedef enum
{
    SCR_ID_VT_INCALL = (VT_BASE + 1),
    SCR_ID_VT_INCALL_OPTION,
    SCR_ID_VT_DIALER,
    SCR_ID_VT_SETTING,
    SCR_ID_VT_ANSWER_MODE,
    SCR_ID_VT_DIAL_MODE,
    SCR_ID_VT_ALT_INCALL_PIC,
    SCR_ID_VT_AUDIO_OPTION,
    SCR_ID_VT_MO_FAIL_POST_ACTION,
    SCR_ID_VT_DUMMY,
    SCR_ID_VT_ADVANCE,
    SCR_ID_VT_VIDEO_QUALITY,
    SCR_ID_VT_TOTAL
} vt_screen_enum;
#endif /* VT_RES_DEF_H */ 

