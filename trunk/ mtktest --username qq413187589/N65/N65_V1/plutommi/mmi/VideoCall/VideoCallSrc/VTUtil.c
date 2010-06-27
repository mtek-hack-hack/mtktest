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
 *  VTUtil.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI VT utility file
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_VIDEO_TELEPHONY__
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "DateTimeGprot.h"
#include "csmcc_common_enums.h"
#include "GpioInc.h"

#include "CallStructureManagementProtEx.h"
#include "CommonStubsProtEx.h"
#include "CallManagementStructEx.h"
#include "ProfileGprots.h"
#include "mdi_audio.h"

#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "UCMProt.h"
#include "UCMResDef.h"

#include "VTGProt.h"
#include "VTProt.h"
#include "VTResDef.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_init_incall_setting
 * DESCRIPTION
 *  Init incall setting before entering incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_init_incall_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.ev = MMI_VT_DEFAULT_EV;
    g_vt_p->incall_screen.zoom_status = MMI_VT_DEFAULT_ZOOM;
    g_vt_p->incall_screen.curr_hilite_index = 0;
    
    /* g_vt_p->incall_screen.is_camera_on should be set in dial MO or answer MT call */

    if (g_vt_p->setting.is_mic_off)
    {
        mmi_vt_set_mic_status(MMI_FALSE);
    }
    else
    {
        mmi_vt_set_mic_status(MMI_TRUE);
    }

    mmi_vt_set_volume_status(MMI_VT_DEFAULT_VOLUME);

    if (g_vt_p->setting.is_speaker_off)
    {
        mmi_vt_set_speaker_status(MMI_FALSE);
    }
    else
    {
        mmi_vt_set_speaker_status(MMI_TRUE);
    }
    
    g_vt_p->incall_screen.is_backend_camera = MMI_FALSE;
    g_vt_p->incall_screen.is_image_switch = MMI_FALSE;
    g_vt_p->incall_screen.is_small_region_hide = MMI_FALSE;
    g_vt_p->incall_screen.is_mirror = MMI_FALSE;
    g_vt_p->incall_screen.video_quality = MMI_VT_VIDEO_QUALITY_NORMAL;
    g_vt_p->incall_screen.mode = MMI_VT_INCALL_SCREEN_MODE_INCALL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_camera_status
 * DESCRIPTION
 *  get camera status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means camera is turned on. Otherwise false.
 *****************************************************************************/
MMI_BOOL mmi_vt_get_camera_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.is_camera_on;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_camera_status
 * DESCRIPTION
 *  set camera status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_camera_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.is_camera_on = status;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_backend_camera_status
 * DESCRIPTION
 *  get backend camera status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means backend camera is used. Otherwise false.
 *****************************************************************************/
MMI_BOOL mmi_vt_get_backend_camera_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.is_backend_camera;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_backend_camera_status
 * DESCRIPTION
 *  set backend camera status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_backend_camera_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.is_backend_camera = status;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_mic_status
 * DESCRIPTION
 *  get mic status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means mic is turned on. Otherwise false.
 *****************************************************************************/
MMI_BOOL mmi_vt_get_mic_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.is_mic_on;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_mic_status
 * DESCRIPTION
 *  set mic status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_mic_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.is_mic_on = status;
    
    if (g_vt_p->incall_screen.is_mic_on)
    {
        MuteOffMicrophone();        
    }
    else
    {
        MuteOnMicrophone();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_speaker_status
 * DESCRIPTION
 *  get speaker status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means speaker is turned on. Otherwise false.
 *****************************************************************************/
MMI_BOOL mmi_vt_get_speaker_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.is_speaker_on;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_speaker_status
 * DESCRIPTION
 *  set speaker status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_speaker_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.is_speaker_on = status;
    
    if (g_vt_p->incall_screen.is_speaker_on)
    {
        mdi_audio_set_mute(4, FALSE);
    }
    else
    {
        mdi_audio_set_mute(4, TRUE);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_pic_switch_status
 * DESCRIPTION
 *  get picture switch status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means picture is switched. Peer image is in small area and 
 *  local image is in main area.
 *  False means peer image is in main area and local image is in small area.
 *****************************************************************************/
MMI_BOOL mmi_vt_get_pic_switch_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.is_image_switch;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_pic_switch_status
 * DESCRIPTION
 *  set picture switch status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_pic_switch_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.is_image_switch = status;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_hide_small_pic_status
 * DESCRIPTION
 *  get hide small pic status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means the small picture is hidden.
 *  False means the small picture is displayed.
 *****************************************************************************/
MMI_BOOL mmi_vt_get_hide_small_pic_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.is_small_region_hide;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_hide_small_pic_status
 * DESCRIPTION
 *  set small picture status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_hide_small_pic_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.is_small_region_hide = status;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_file_name
 * DESCRIPTION
 *  Get file name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16* mmi_vt_get_file_name(U16* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_path_len = mmi_ucs2strlen((S8*)file_path);
    U16* cur_position;
    U16* pre_position;
    S32 i = file_path_len - 1;
    U8 pattern[3 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pattern, 0, sizeof(pattern));
    mmi_asc_n_to_ucs2((S8*)pattern, "\\", 1);
    
    for (; i >= 0 ; i--)
    {
        cur_position = &(file_path[i]);
        pre_position = cur_position - 1;
        if (mmi_ucs2ncmp((S8*)pre_position, (S8*)pattern, 1) == 0)
        {
            return cur_position;
        }
    }

    return file_path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_incall_pic
 * DESCRIPTION
 *  Get file name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_incall_pic(U16* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error_code = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((S8*)g_vt_p->setting.incall_image_file_path, (S8*)file_path, NVRAM_EF_VT_SETTING_SIZE / ENCODING_LENGTH);

    WriteRecord(
        NVRAM_EF_VT_SETTING_LID,
        1,
        (void*)&(g_vt_p->setting.incall_image_file_path),
        NVRAM_EF_VT_SETTING_SIZE,
        &error_code);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_incall_pic
 * DESCRIPTION
 *  Get file name
 * PARAMETERS
 *  [OUT] default_pic_id : image resource id if return value is MMI_VT_INCALL_PIC_STATUS_BUILT_IN
 *  [OUT] file_unicode_str_ptr : file path if return value is MMI_VT_INCALL_PIC_STATUS_FILE
 * RETURNS
 *  mmi_vt_incall_pic_status_enum
 *****************************************************************************/
mmi_vt_incall_pic_status_enum mmi_vt_get_incall_pic(U16* default_pic_id, S8** file_unicode_str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*)g_vt_p->setting.incall_image_file_path) == 0)
    {
        *default_pic_id = (U8)MMI_TRUE;
        file_unicode_str_ptr = NULL;

        return MMI_VT_INCALL_PIC_STATUS_BUILT_IN;
    }
    else
    {
        *default_pic_id = 0;
        *file_unicode_str_ptr = (S8*)g_vt_p->setting.incall_image_file_path;

        return MMI_VT_INCALL_PIC_STATUS_FILE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_dummy
 * DESCRIPTION
 *  Dummy entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_dummy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VT_DUMMY, NULL, NULL, NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_video_quality_status
 * DESCRIPTION
 *  get video quality status
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_vt_video_quality_enum
 *****************************************************************************/
mmi_vt_video_quality_enum mmi_vt_get_video_quality_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.video_quality;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_video_quality_status
 * DESCRIPTION
 *  set video quality  status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_video_quality_status(mmi_vt_video_quality_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.video_quality = status;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_mirror_status
 * DESCRIPTION
 *  get mirror status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means mirror is turned on. Otherwise false.
 *****************************************************************************/
MMI_BOOL mmi_vt_get_mirror_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.is_mirror;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_mirror_status
 * DESCRIPTION
 *  set mirror status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_mirror_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.is_mirror = status;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_incall_screen_mode
 * DESCRIPTION
 *  get incall screen mode
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_vt_incall_screen_mode_enum
 *****************************************************************************/
mmi_vt_incall_screen_mode_enum mmi_vt_get_incall_screen_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.mode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_incall_screen_mode
 * DESCRIPTION
 *  set incall screen mode
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_incall_screen_mode(mmi_vt_incall_screen_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.mode = mode;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_ev_status
 * DESCRIPTION
 *  get EV status
 * PARAMETERS
 *  void
 * RETURNS
 *  EV status
 *****************************************************************************/
mmi_vt_ev_enum mmi_vt_get_ev_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.ev;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_ev_status
 * DESCRIPTION
 *  set EV status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_ev_status(mmi_vt_ev_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.ev = status;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_zoom_status
 * DESCRIPTION
 *  get zoom status
 * PARAMETERS
 *  void
 * RETURNS
 *  zoom status
 *****************************************************************************/
mmi_vt_zoom_enum mmi_vt_get_zoom_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.zoom_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_zoom_status
 * DESCRIPTION
 *  set zoom status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_zoom_status(mmi_vt_zoom_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.zoom_status = status;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_volume_status
 * DESCRIPTION
 *  get volume status
 * PARAMETERS
 *  void
 * RETURNS
 *  volume status
 *****************************************************************************/
mmi_vt_vol_enum mmi_vt_get_volume_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.volume;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_volume_status
 * DESCRIPTION
 *  set volume status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_volume_status(mmi_vt_vol_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.volume = status;

    mdi_audio_set_volume(MDI_VOLUME_SPH,  g_vt_p->incall_screen.volume);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_hand_free_status
 * DESCRIPTION
 *  get hand-free status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means hand-free. Otherwise hand-held.
 *****************************************************************************/
MMI_BOOL mmi_vt_get_hand_free_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vt_p->incall_screen.is_hand_free;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_hand_free_status
 * DESCRIPTION
 *  set hand-free status
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_hand_free_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.is_hand_free = status;

    if (g_vt_p->incall_screen.is_hand_free)
    {
        EnableHandsFree();
        SetLoudSpeaker(TRUE);
    }
    else
    {
        DisbleHandsFree();
        SetLoudSpeaker(FALSE);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_call_cost_status
 * DESCRIPTION
 *  get call cost status
 * PARAMETERS
 *  unit and cost
 * RETURNS
 *  True means call cost should be displayed. Otherwise false
 *****************************************************************************/
MMI_BOOL mmi_vt_get_call_cost_status(S8* unit_uincode_str, S8* cost_uincode_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*)g_ucm_p->call_cost.cost))
    {
        unit_uincode_str = (S8*)g_ucm_p->call_cost.symbol;
        cost_uincode_str = (S8*)g_ucm_p->call_cost.cost;
        
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_remote_display_name
 * DESCRIPTION
 *  get remote display name
 * PARAMETERS
 *  void
 * RETURNS
 *  display name
 *****************************************************************************/
U16* mmi_vt_get_remote_display_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 activeIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_get_active_group(MMI_UCM_VIDEO_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list))
    {
        activeIndex = g_ucm_p->call_misc.index_list[0].group_index;
        return g_ucm_p->call_list.group_info[activeIndex].call_info[0].remote_info.disp_name;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_get_call_start_time
 * DESCRIPTION
 *  get start time
 * PARAMETERS
 *  void
 * RETURNS
 *  start time of the video call
 *****************************************************************************/
applib_time_struct* mmi_vt_get_call_start_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 activeIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_get_active_group(MMI_UCM_VIDEO_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list))
    {
        activeIndex = g_ucm_p->call_misc.index_list[0].group_index;
        return (applib_time_struct*)&g_ucm_p->call_list.group_info[activeIndex].call_info[0].start_time;
    }
    else
    {
        return NULL;
    }
}

#endif /* __MMI_VIDEO_TELEPHONY__ */

