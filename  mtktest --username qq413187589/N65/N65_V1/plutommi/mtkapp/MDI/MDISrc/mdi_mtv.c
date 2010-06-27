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
 *  mdi_mtv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access mobile tv related functions.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*****************************************************************************
* Include
*****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_MOBILE_TV_PLAYER__

#include "stdC.h"
#include "L4Dr1.h"

#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "QueueGprot.h" /* message handling */
#include "fat_fs.h"
#include "gdi_include.h"        /* include data type */
#include "gui.h"
#include "med_api.h"
#include "mdi_datatype.h"
#include "med_api.h"    /* media task */
#include "mdi_mtv.h" /* include camera related define */
#include "EventsGprot.h"        /* event hadnling - get message return from camera driver */
#include "gpioInc.h"    /* avoid sleep when using camera */
#include "fat_fs.h"

#include "lcd_if.h"
#include "lcd_sw_rnd.h"

#include "med_api.h"
#include "med_main.h"
#include "med_struct.h"

#include "MMI_media_app_trc.h"

/*****************************************************************************
* Typedef
*****************************************************************************/

/*****************************************************************************
* Local Variable
*****************************************************************************/
mdi_mtv_context_struct mdi_mtv_context;
mdi_mtv_context_struct *mdi_mtv_p = &mdi_mtv_context;
/*****************************************************************************
* Local Function
*****************************************************************************/
static void mdi_mtv_on_service_found(void* local_param);
static void mdi_mtv_on_search_progress(void* local_param);
static void mdi_mtv_on_service_event_hdlr(void* local_param);
static void mdi_mtv_on_complete_saving(void *local_param);


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_on_service_found
 * DESCRIPTION
 *  init MTV engine
 * PARAMETERS
 *  local_param IN media_mtv_service_found_ind_struct*
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
static void mdi_mtv_on_service_found(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_service_found_ind_struct* ind = (media_mtv_service_found_ind_struct*) local_param;
    mdi_mtv_service_info_struct  service_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_ON_SERVICE_FOUND_IND);

    service_info.service_id = ind->info.service_id;
    service_info.service_name = (PS8)ind->info.service_name;
    service_info.service_number = ind->info.service_number;
    service_info.service_type = ind->info.service_type;
    service_info.service_flags = ind->info.service_flags;

    /* we need to copy the name because it may change later */
    mdi_mtv_p->service_config.on_service_found_hdlr(&service_info);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_on_search_progress
 * DESCRIPTION
 *  init MTV engine
 * PARAMETERS
 *  local_param IN media_mtv_search_progress_ind_struct*
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
static void mdi_mtv_on_search_progress(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_search_progress_ind_struct* ind = (media_mtv_search_progress_ind_struct*) local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_ON_SEARCH_PROGRESS_IND);

    if (ind->percentage == 100)
    {
        mdi_mtv_p->service_config.on_search_progress_ind_hdlr(100);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_on_complete_saving
 * DESCRIPTION
 *  complete recovering recording indication hdlr
 * PARAMETERS
 *  local_param IN media_mtv_complete_recovering_ind_struct*
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
static void mdi_mtv_on_complete_saving(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //media_mtv_complete_recovering_ind_struct* ind = (media_mtv_complete_recovering_ind_struct*) local_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_ON_COMPLETE_SAVING_IND);

    mdi_mtv_p->service_config.on_complete_saving_ind_hdlr(MDI_RES_MTV_SUCCEED);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_on_service_event_hdlr
 * DESCRIPTION
 *  mtv service event hdlr
 * PARAMETERS
 *  media_mtv_service_event_ind_struct*  IN service event ind struct.
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
static void mdi_mtv_on_service_event_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_service_event_ind_struct* ind = (media_mtv_service_event_ind_struct*) local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_ON_SERVICE_EVENT_IND,mdi_mtv_p->context,ind->event,ind->parameter);

    /* ignore not-matched service id ind */
    if (ind->service_id != mdi_mtv_p->service_id)
    return;


    switch (ind->event)
    {
    case MEDIA_MTV_SERVICE_STARTED:
        mdi_mtv_p->service_config.on_service_event_callback(MDI_MTV_SERVICE_STARTED,MDI_RES_MTV_SUCCEED);
        break;
    case MEDIA_MTV_SERVICE_STOPPED:
        PRINT_INFORMATION("MEDIA_MTV_SERVICE_STOPPED\n");
        break;
    case MEDIA_MTV_SERVICE_ADDED:
        PRINT_INFORMATION("MEDIA_MTV_SERVICE_ADDED\n");
        break;
    case MEDIA_MTV_SERVICE_REMOVED:
        PRINT_INFORMATION("MEDIA_MTV_SERVICE_REMOVED\n");
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_on_recorder_event_hdlr
 * DESCRIPTION
 *  mtv recorder event hdlr
 * PARAMETERS
 *  media_mtv_service_event_ind_struct*  IN service event ind struct.
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
static void mdi_mtv_on_recorder_event_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_recorder_event_ind_struct* ind = (media_mtv_recorder_event_ind_struct*) local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_ON_RECORDER_EVENT_IND,mdi_mtv_p->context,ind->event,ind->parameter);

    switch (ind->event)
    {
    case MEDIA_MTV_RECORDER_STARTED:
        break;
    case MEDIA_MTV_RECORDER_STOPPED:
        mdi_mtv_p->service_config.on_recorder_event_callback(MDI_MTV_RECORDER_STOPPED,MDI_RES_MTV_COMPLETE_SAVING);
        break;
    case MEDIA_MTV_RECORDER_SAVING:
        break;
    case MEDIA_MTV_RECORDER_ERROR:
        mdi_mtv_p->service_config.on_recorder_event_callback(MDI_MTV_RECORDER_ERROR,MDI_RES_MTV_COMMON_ERROR);
        break;
    case MEDIA_MTV_RECORDER_SAVING_FAILED:
        mdi_mtv_p->service_config.on_recorder_event_callback(MDI_MTV_RECORDER_SAVING_FAILED,MDI_RES_MTV_COMMON_ERROR);
        break;
    case MEDIA_MTV_RECORDER_SAVING_SUCCEEDED:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_on_player_event_hdlr
 * DESCRIPTION
 *  mtv player event hdlr
 * PARAMETERS
 *  media_mtv_service_event_ind_struct*  IN service event ind struct.
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
static void mdi_mtv_on_player_event_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_player_event_ind_struct* ind = (media_mtv_player_event_ind_struct*) local_param;
    U32 event_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_ON_PLAYER_EVENT_IND,mdi_mtv_p->context,ind->event,ind->parameter);

    switch (ind->event)
    {
    case MEDIA_MTV_PLAYER_STARTED:
        event_id = MDI_MTV_PLAYER_STARTED;
        break;
    case MEDIA_MTV_PLAYER_STOPPED:
        event_id = MDI_MTV_PLAYER_STOPPED;
        break;
    case MEDIA_MTV_PLAYER_TIMESHIFT_PAUSED:
        event_id = MDI_MTV_PLAYER_TIMESHIFT_PAUSED;
        break;
    case MEDIA_MTV_PLAYER_TIMESHIFT_DELAYED:
        event_id = MDI_MTV_PLAYER_TIMESHIFT_DELAYED;
        break;
    case MEDIA_MTV_PLAYER_TIMESHIFT_LIVE:
        event_id = MDI_MTV_PLAYER_TIMESHIFT_LIVE;
        break;
    case MEDIA_MTV_PLAYER_BEGINNING_OF_CONTENT:
        event_id = MDI_MTV_PLAYER_BEGINNING_OF_CONTENT;
        break;
    case MEDIA_MTV_PLAYER_END_OF_CONTENT:
        event_id = MDI_MTV_PLAYER_END_OF_CONTENT;
        break;
    case MEDIA_MTV_PLAYER_SNAPSHOT_TAKEN:
        event_id = MDI_MTV_PLAYER_SNAPSHOT_TAKEN;
        break;
    case MEDIA_MTV_PLAYER_DYNAMIC_LABEL:
        event_id = MDI_MTV_PLAYER_DYNAMIC_LABEL;
        break;
    case MEDIA_MTV_PLAYER_ERROR:
        event_id = MDI_MTV_PLAYER_ERROR;
        break;
    }

    mdi_mtv_p->service_config.on_player_event_callback(event_id,ind->parameter);
}

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_open
 * DESCRIPTION
 *  init MTV engine
 * PARAMETERS
 *  U32*                            OUT     mtv_handle
 *  gdi_handle                      IN      update_layer_handle
 *  mdi_mtv_setting_struct*         IN      mtv_setting
 *  mdi_mtv_service_config_struct*  IN      mtv_service_config
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_open(U32 *mtv_handle,
                        gdi_handle update_layer_handle,
                        mdi_mtv_setting_struct* mtv_setting,
                        mdi_mtv_service_config_struct* mtv_service_config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unsaved_recording_found;
    S32 ret;
    media_config_video_struct video;
    media_config_audio_struct audio;
    media_mtv_config_record_struct record;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_OPEN);
    mdi_mtv_p->service_config.on_search_progress_ind_hdlr = mtv_service_config->on_search_progress_ind_hdlr;
    mdi_mtv_p->service_config.on_complete_saving_ind_hdlr = mtv_service_config->on_complete_saving_ind_hdlr;
    mdi_mtv_p->service_config.on_service_found_hdlr = mtv_service_config->on_service_found_hdlr;
    mdi_mtv_p->service_config.on_service_event_callback = mtv_service_config->on_service_event_callback;
    mdi_mtv_p->service_config.on_player_event_callback = mtv_service_config->on_player_event_callback;
    mdi_mtv_p->service_config.on_recorder_event_callback = mtv_service_config->on_recorder_event_callback;

    SetProtocolEventHandler(mdi_mtv_on_service_found, MSG_ID_MEDIA_MTV_SERVICE_FOUND_IND);
    SetProtocolEventHandler(mdi_mtv_on_search_progress, MSG_ID_MEDIA_MTV_SEARCH_PROGRESS_IND);
    SetProtocolEventHandler(mdi_mtv_on_complete_saving, MSG_ID_MEDIA_MTV_COMPLETE_RECOVERING_IND);
    SetProtocolEventHandler(mdi_mtv_on_service_event_hdlr, MSG_ID_MEDIA_MTV_SERVICE_EVENT_IND);
    SetProtocolEventHandler(mdi_mtv_on_player_event_hdlr, MSG_ID_MEDIA_MTV_PLAYER_EVENT_IND);
    SetProtocolEventHandler(mdi_mtv_on_recorder_event_hdlr, MSG_ID_MEDIA_MTV_RECORDER_EVENT_IND);

    ret = media_mtv_open(MOD_MMI, &mdi_mtv_p->context);
    ASSERT(ret == MED_RES_OK);

    *mtv_handle = mdi_mtv_p->context;



    record.enable_timeshift = KAL_TRUE;
    record.max_timeshift_delay = 30 * 60;
    record.max_timeshift_buffer_kb = 2 * 1024;
    record.record_dir = (kal_wchar*)mtv_setting->record_dir;
    ret = media_mtv_config(MOD_MMI, *mtv_handle, &video, &audio, &record);
    ASSERT(ret == MED_RES_OK);

    ret = media_mtv_find_unsaved_recording(MOD_MMI, *mtv_handle, &unsaved_recording_found);


    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_OPEN_RESULT,ret,mdi_mtv_p->context);
    if (unsaved_recording_found == KAL_TRUE)
        return MDI_RES_MTV_UNSAVE_RECORDING_IND;

    ASSERT(ret == MED_RES_OK);
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_close
 * DESCRIPTION
 *  close MTV engine
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_close(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_close(MOD_MMI, mtv_handle);

    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_CLOSE);

    ASSERT(ret == MED_RES_OK);
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_restore_unsaved_recording
 * DESCRIPTION
 *  restore unsaved recoding data dut to plugout battery directly when recording
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_restore_unsaved_recording(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_RESTORE_UNSAVED_RECORDING);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_recover_recording(MOD_MMI, mtv_handle);
    ASSERT(ret == MED_RES_OK);
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_discard_unsaved_recording
 * DESCRIPTION
 *  remove unsaved recording data.
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_discard_unsaved_recording(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_DISCARD_UNSAVED_RECORDING);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_discard_unsaved_recording(MOD_MMI, mtv_handle);
    ASSERT(ret == MED_RES_OK);
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_scan_services_on_air
 * DESCRIPTION
 *  scan service data on air immediately
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_scan_services_on_air(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_SCAN_SERVICE_ON_AIR);

    ret = media_mtv_search_services(MOD_MMI, mtv_handle, MEDIA_MTV_SERVICES_FROM_LIVE_SIGNAL, MEDIA_MTV_TDMB_BAND_III);
    ASSERT(ret == MED_RES_OK);
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_scan_services_from_database
 * DESCRIPTION
 *  scan service data from database immediately
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_scan_services_from_database(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_SCAN_SERVICE_FROM_DATABASE);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    //ret = media_mtv_search_services(MOD_MMI, mtv_handle, MEDIA_MTV_SERVICES_FROM_LOCAL_DATABASE);
    ret = media_mtv_search_services(MOD_MMI, mtv_handle, MEDIA_MTV_SERVICES_FROM_LIVE_SIGNAL, MEDIA_MTV_TDMB_BAND_III);
    ASSERT(ret == MED_RES_OK);
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_abort_scan_services
 * DESCRIPTION
 *  abort scan service request
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_abort_scan_services(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_ABORT_SCAN_SERVICE);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_abort_searching(MOD_MMI, mtv_handle);
    ASSERT(ret >= 0)
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_start_service
 * DESCRIPTION
 *  Start service (engine must be opened successfully)
 * PARAMETERS
 *  U32                             IN     mtv_handle
 *  U32                             IN     service_id
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_start_service(U32 mtv_handle, U32 service_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_START_SERVICE,service_id);

    mdi_mtv_p->service_id = service_id;
    ret = media_mtv_start_service(MOD_MMI, mtv_handle, service_id, MEDIA_MTV_SERVICE_ACTIVITY_PLAY);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_stop_service
 * DESCRIPTION
 *  Stop service (service must be started)
 * PARAMETERS
 *  U32                             IN     mtv_handle
 *  U32                             IN     service_id
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_stop_service(U32 mtv_handle, U32 service_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_STOP_SERVICE,service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ASSERT(mdi_mtv_p->service_id == service_id);
    ret = media_mtv_stop_service(MOD_MMI, mtv_handle, service_id);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_service_get_status
 * DESCRIPTION
 *  get service status
 * PARAMETERS
 *  U32                             IN     mtv_handle
 *  mdi_mtv_service_status_struct   OUT    status
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_service_get_status(U32 mtv_handle, mdi_mtv_service_status_struct *status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_mtv_service_status_struct mtv_s;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_SERVICE_GET_STATUS);



    ASSERT(mtv_handle == mdi_mtv_p->context);


    ret = media_mtv_service_get_status(MOD_MMI, mtv_handle, mdi_mtv_p->service_id, &mtv_s);
    ASSERT(ret == MED_RES_OK);

    status->signal_strength = mtv_s.signal_strength;
    status->state = mtv_s.state;
    status->timeshift_available = mtv_s.timeshift_available;

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_start_play
 * DESCRIPTION
 *  start to play the program
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_player_start_play(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_PLAYER_START,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_player_play(MOD_MMI,mtv_handle,mdi_mtv_p->service_id);
    ASSERT(ret>=0);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_stop_play
 * DESCRIPTION
 *  stop play the program
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_player_stop_play(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_PLAYER_STOP,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_player_stop(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_play_pause
 * DESCRIPTION
 *  !!NOT AVAILABLE
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_player_play_pause(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_PLAYER_PLAY_PAUSE,mdi_mtv_p->service_id);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_pause
 * DESCRIPTION
 *  pause player
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_player_pause(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_PLAYER_PAUSE,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_player_pause(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);
    ASSERT(ret == MED_RES_OK);
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_resume
 * DESCRIPTION
 *  resume player
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_player_resume(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_PLAYER_RESUME,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_player_play(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_get_status
 * DESCRIPTION
 *  get status of player
 * PARAMETERS
 *  U32                             IN     mtv_handle
 *  mdi_mtv_player_status_struct    OUT    status
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_player_get_status(U32 mtv_handle, mdi_mtv_player_status_struct *status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_mtv_player_status_struct mtv_s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_PLAYER_GET_STATUS);


    ASSERT(mtv_handle == mdi_mtv_p->context);


    ret = media_mtv_player_get_status(MOD_MMI, mtv_handle, mdi_mtv_p->service_id, &mtv_s);
    ASSERT(ret == MED_RES_OK);

    status->max_delay = mtv_s.max_delay;
    status->play_delay = mtv_s.play_delay;
    status->play_rate = mtv_s.play_rate;
    status->state = mtv_s.state;

//  ret = media_mtv_player_seek(MOD_MMI, g_ctx.mtv_sap, mdi_mtv_p->service_id, status.play_delay + 8);
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_start_record
 * DESCRIPTION
 *  start record
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_recorder_start_record(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_RECORDER_START,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_recorder_start(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_stop_record
 * DESCRIPTION
 *  stop record
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_recorder_stop_record(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_RECORDER_STOP,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_recorder_stop(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_save_recording
 * DESCRIPTION
 *  save the recorded data into file
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_recorder_save_recording(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_RECORDER_SAVE_RECORDING,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_recorder_save(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);
    ASSERT(ret == MED_RES_OK);
    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_discard_recording
 * DESCRIPTION
 *  remove the recorded data from engine
 * PARAMETERS
 *  U32                             IN     mtv_handle
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_recorder_discard_recording(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_RECORDER_DISCARD_RECORDING,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_recorder_discard_recording(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_get_status
 * DESCRIPTION
 *  get recorder's status
 * PARAMETERS
 *  U32                             IN     mtv_handle
 *  mdi_mtv_recorder_status_struct  OUT    status
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_recorder_get_status(U32 mtv_handle, mdi_mtv_recorder_status_struct *status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_RECORDER_GET_STATUS);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_on_instant_delay
 * DESCRIPTION
 *  udpate param to mtv engine
 * PARAMETERS
 *  U32                             IN     mtv_handle
 *  mdi_mtv_setting_param_enum      IN     param
 *  U16                             IN     value
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
extern MDI_RESULT mdi_mtv_recorder_seek(U32 mtv_handle, U32 play_delay)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_RECORDER_SEEK);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_player_seek(MOD_MMI, mtv_handle, mdi_mtv_p->service_id,play_delay);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_update_param
 * DESCRIPTION
 *  udpate param to mtv engine
 * PARAMETERS
 *  U32                             IN     mtv_handle
 *  mdi_mtv_setting_param_enum      IN     param
 *  U16                             IN     value
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_update_param(U32 mtv_handle, mdi_mtv_setting_param_enum param, U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_UPDATE_PARAM);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_update_brightness
 * DESCRIPTION
 *  update brightness value
 * PARAMETERS
 *  U32                             IN     mtv_handle
 *  U16                             IN     value
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_update_brightness(U32 mtv_handle, U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_UPDATE_BRIGHTNESS);

    return MDI_RES_MTV_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_update_contrast
 * DESCRIPTION
 *  update contrast value
 * PARAMETERS
 *  U32                             IN     mtv_handle
 *  U16                             IN     value
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_mtv_update_contrast(U32 mtv_handle, U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MDI_MTV_UPDATE_CONTRAST);

    return MDI_RES_MTV_SUCCEED;
}


#endif /* __MMI_MOBILE_TV_PLAYER__ */

