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
 *  mdi_enum.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Header file of all MDI enum
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MDI_ENUM_H_
#define _MDI_ENUM_H_



#ifdef __MMI_MOBILE_TV_PLAYER__
/***************************************************************************** 
* MDI MOBILE TV
*****************************************************************************/
typedef enum
{
    MDI_MTV_ENGINE_STATE_CLOSED = 0,
    MDI_MTV_ENGINE_STATE_OPENED,
    MDI_MTV_ENGINE_STATE_SCANNING,
    MDI_MTV_ENGINE_STATE_SAVING,

    MDI_MTV_ENGINE_STATE_TOTAL_COUNT
}mdi_mtv_engine_state_enum;

typedef enum
{
    MDI_MTV_SERVICE_STATE_STOPPED = 0,
    MDI_MTV_SERVICE_STATE_STARTED,
    MDI_MTV_SERVICE_STATE_READY,

    MDI_MTV_SERVICE_STATE_TOTAL_COUNT
}mdi_mtv_service_state_enum;

typedef enum
{
    MDI_MTV_PLAYER_STATE_STOPPED = 0,
    MDI_MTV_PLAYER_STATE_PLAYING,
    MDI_MTV_PLAYER_STATE_PAUSED,

    MDI_MTV_PLAYER_STATE_TOTAL_COUNT
}mdi_mtv_player_state_enum;

typedef enum
{
    MDI_MTV_RECORDER_STATE_STOPPED = 0,
    MDI_MTV_RECORDER_STATE_STARTED,
    MDI_MTV_RECORDER_STATE_SAVING,

    MDI_MTV_RECORDER_STATE_TOTAL_COUNT
}mdi_mtv_recorder_state_enum;

typedef enum
{
    MDI_MTV_PARAM_BRIGHTNESS = 0,
    MDI_MTV_PARAM_CONTRAST,
    MDI_MTV_PARAM_GAMMA,
    MDI_MTV_PARAM_HUE,
    MDI_MTV_PARAM_SHARPNESS,
    MDI_MTV_PARAM_VISIBLE,
    MDI_MTV_PARAM_MUTE,
    MDI_MTV_PARAM_VOLUME,
    MDI_MTV_PARAM_TIMESHIFT_DELAY,

    MDI_MTV_PARAM_TOTAL_COUNT
}mdi_mtv_setting_param_enum;

typedef enum
{
    MDI_MTV_SERVICE_TYPE_UNKNOWN = 0,
    MDI_MTV_SERVICE_TYPE_DIGITAL_RADIO,
    MDI_MTV_SERVICE_TYPE_DIGITAL_TV,
    MDI_MTV_SERVICE_TYPE_MOT_SLIDESHOW,
    MDI_MTV_SERVICE_TYPE_TPEG,
    MDI_MTV_SERVICE_TYPE_BWS,
    MDI_MTV_SERVICE_TYPE_FILE_DOWNLOAD,

    MDI_MTV_SERVICE_TYPE_TOTAL_COUNT
}mdi_mtv_service_type_enum;

typedef enum
{
    MDI_MTV_SERVICE_FLAG_FREE = 0,
    MDI_MTV_SERVICE_FLAG_CLEAR_TO_AIR,

    MDI_MTV_SERVICE_FLAG_TOTAL_COUNT
}mdi_mtv_service_flag_enum;

#endif /* __MMI_MOBILE_TV_PLAYER__ */ 

#endif /* _MDI_ENUM_H_ */

