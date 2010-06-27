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
 *  mdi_mtv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV interfce header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MDI_MTV_H_
#define _MDI_MTV_H_

#ifdef __MMI_MOBILE_TV_PLAYER__

#ifndef _MDI_DATATYPE_H_
#error "Please include mdi_datatype.h before mdi_mtv.h"
#endif 

#ifndef _MDI_ENUM_H_
#include "mdi_enum.h"
#endif

#include "med_api.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define MDI_MTV_BRIGHTNESS_N5              0
#define MDI_MTV_BRIGHTNESS_N4              1
#define MDI_MTV_BRIGHTNESS_N3              2
#define MDI_MTV_BRIGHTNESS_N2              3
#define MDI_MTV_BRIGHTNESS_N1              4
#define MDI_MTV_BRIGHTNESS_0               5
#define MDI_MTV_BRIGHTNESS_P1              6
#define MDI_MTV_BRIGHTNESS_P2              7
#define MDI_MTV_BRIGHTNESS_P3              8
#define MDI_MTV_BRIGHTNESS_P4              9
#define MDI_MTV_BRIGHTNESS_P5              10

#define MDI_MTV_CONTRAST_N5                0
#define MDI_MTV_CONTRAST_N4                1
#define MDI_MTV_CONTRAST_N3                2
#define MDI_MTV_CONTRAST_N2                3
#define MDI_MTV_CONTRAST_N1                4
#define MDI_MTV_CONTRAST_0                 5
#define MDI_MTV_CONTRAST_P1                6
#define MDI_MTV_CONTRAST_P2                7
#define MDI_MTV_CONTRAST_P3                8
#define MDI_MTV_CONTRAST_P4                9
#define MDI_MTV_CONTRAST_P5                10

/***************************************************************************** 
* Event enums
*****************************************************************************/
/**
  * Service events.
  */
typedef enum
{
    MDI_MTV_SERVICE_STARTED,              /**< the service has been started */
    MDI_MTV_SERVICE_READY,                /**< the service is ready for play, record, or other purposes */
    MDI_MTV_SERVICE_STOPPED,              /**< the service has been stopped */
    MDI_MTV_SERVICE_ADDED,                /**< new service is available */
    MDI_MTV_SERVICE_REMOVED               /**< existing service is removed */
} mdi_mtv_service_event_enum;

/**
  * Player events.
  */
typedef enum
{
    MDI_MTV_PLAYER_STARTED,               /**< the player has been started */
    MDI_MTV_PLAYER_TIMESHIFT_PAUSED,      /**< the playback of time-shift content has been paused */
    MDI_MTV_PLAYER_TIMESHIFT_DELAYED,     /**< delayed (buffered) content is played */
    MDI_MTV_PLAYER_TIMESHIFT_LIVE,        /**< live broadcast content is played */
    MDI_MTV_PLAYER_BEGINNING_OF_CONTENT,  /**< a rewind hits the beginning of time-shift buffer */
    MDI_MTV_PLAYER_END_OF_CONTENT,        /**< a forward playback catches up with the live recording point */
    MDI_MTV_PLAYER_SNAPSHOT_TAKEN,        /**< a video snapshot has been taken. the event parameter will be the snapshot filename. */
    MDI_MTV_PLAYER_DYNAMIC_LABEL,         /**< a dynamic label is available. the event parameter will be a null-terminated wchar string. */
    MDI_MTV_PLAYER_ERROR,                 /**< an internal error of player has happened. the client should stop the player immediately. */
    MDI_MTV_PLAYER_STOPPED                /**< the player has been stopped */
} mdi_mtv_player_event_enum;

/**
  * Recorder events.
  */
typedef enum
{
    MDI_MTV_RECORDER_STARTED,         /**< the recorder has been started */
    MDI_MTV_RECORDER_SAVING,          /**< file saving is in progress */
    MDI_MTV_RECORDER_SAVING_SUCCEEDED, /**< file saving is succeeded */
    MDI_MTV_RECORDER_SAVING_FAILED,    /**< file saving is failed */
    MDI_MTV_RECORDER_ERROR,           /**< an internal error of recorder has happened. the client should stop the recorder immediately. */
    MDI_MTV_RECORDER_STOPPED          /**< the recorder has been stopped. the event parameter will be the recorded filename. */
} mdi_mtv_recorder_event_enum;


/***************************************************************************** 
* Typedef
*****************************************************************************/
typedef struct
{
    U32 service_id;
    PS8 service_name;
    U32 service_number;
    mdi_mtv_service_type_enum service_type;
    mdi_mtv_service_flag_enum service_flags;

}mdi_mtv_service_info_struct;

typedef void (*mdi_mtv_on_service_found_hdlr)(mdi_mtv_service_info_struct *service_info);
typedef void (*mdi_mtv_on_search_progress_ind_hdlr)(S32 value);
typedef void (*mdi_mtv_on_complete_saving_ind_hdlr)(S32 value);
typedef void (*mdi_mtv_event_callback)(U32 event_id, S32 param);

typedef struct
{
    mdi_mtv_on_service_found_hdlr on_service_found_hdlr;
    mdi_mtv_on_search_progress_ind_hdlr on_search_progress_ind_hdlr;
    mdi_mtv_on_complete_saving_ind_hdlr on_complete_saving_ind_hdlr;   
    mdi_mtv_event_callback on_service_event_callback;
    mdi_mtv_event_callback on_player_event_callback;
    mdi_mtv_event_callback on_recorder_event_callback;
}mdi_mtv_service_config_struct;

typedef struct
{
    mdi_mtv_service_state_enum state;
    U32 signal_strength;
    pBOOL timeshift_available;
}mdi_mtv_service_status_struct;

typedef struct
{
    mdi_mtv_player_state_enum state;
    U32 play_delay;
    U32 max_delay;
    S32 play_rate;
}mdi_mtv_player_status_struct;

typedef struct
{
    mdi_mtv_recorder_state_enum state;
    U32 recorded_duration;   
}mdi_mtv_recorder_status_struct;

typedef struct
{
    U32 max_timeshift_delay;
    U32 max_timeshift_buffer_kb;
    U16 brightness;
    U16 contrast;
    U16 gamma;
    U16 hue;
    U16 sharpness;
    U16 volume_level;
    PU8 record_dir;
    pBOOL is_mute;
    pBOOL is_visible;
    pBOOL is_timeshift_enabled;

}mdi_mtv_setting_struct;


typedef struct
{
    U32 context;
    U32 service_id;
  
    mdi_mtv_engine_state_enum engine_state;
    mdi_mtv_service_state_enum service_state;
    mdi_mtv_player_state_enum player_state;
    mdi_mtv_recorder_state_enum recorder_state;
    mdi_mtv_setting_struct setting;
    mdi_mtv_service_config_struct service_config;

}mdi_mtv_context_struct;


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/* ENGINE PART */
extern MDI_RESULT mdi_mtv_open(U32 *mtv_handle, 
                               gdi_handle update_layer_handle,
                               mdi_mtv_setting_struct* mtv_setting,
                               mdi_mtv_service_config_struct* mtv_service_config);
extern MDI_RESULT mdi_mtv_close(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_restore_unsaved_recording(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_discard_unsaved_recording(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_scan_services_on_air(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_scan_services_from_database(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_abort_scan_services(U32 mtv_handle);

/* SERVICE PART */
extern MDI_RESULT mdi_mtv_start_service(U32 mtv_handle, 
                                        U32 service_id);
extern MDI_RESULT mdi_mtv_stop_service(U32 mtv_handle, U32 service_id);
extern MDI_RESULT mdi_mtv_service_get_status(U32 mtv_handle, mdi_mtv_service_status_struct *status);

/* PLAYER PART */
extern MDI_RESULT mdi_mtv_player_start_play(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_player_stop_play(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_player_play_pause(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_player_pause(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_player_resume(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_player_get_status(U32 mtv_handle, mdi_mtv_player_status_struct *status);

/* RECORD PART */
extern MDI_RESULT mdi_mtv_recorder_start_record(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_recorder_stop_record(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_recorder_save_recording(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_recorder_discard_recording(U32 mtv_handle);
extern MDI_RESULT mdi_mtv_recorder_get_status(U32 mtv_handle, mdi_mtv_recorder_status_struct *status);
extern MDI_RESULT mdi_mtv_recorder_seek(U32 mtv_handle, U32 play_delay);
/* MISC */
extern MDI_RESULT mdi_mtv_update_param(U32 mtv_handle, mdi_mtv_setting_param_enum param, U16 value);
extern MDI_RESULT mdi_mtv_update_brightness(U32 mtv_handle, U16 value);
extern MDI_RESULT mdi_mtv_update_contrast(U32 mtv_handle, U16 value);

#endif /* __MMI_MOBILE_TV_PLAYER__ */ 
#endif /* _MDI_MTV_H_ */

