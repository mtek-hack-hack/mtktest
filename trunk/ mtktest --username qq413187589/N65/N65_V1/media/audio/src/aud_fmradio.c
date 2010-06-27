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
 * aud_fmradio.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes FM Radio service functions
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

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "fat_fs.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifndef WIN32 
#ifdef __MED_FMR_MOD__

/* 2009.05.31 modified by hongzhe.liu + */
unsigned char  const FM_RADIO_INPUT_LEVEL_THRESHOLD = 1; 
/* 2009.05.31 modified by hongzhe.liu - */

#endif 
#else

/* 2009.05.31 modified by hongzhe.liu + */
#if defined(FM_RADIO_ENABLE)
unsigned char  const FM_RADIO_INPUT_LEVEL_THRESHOLD = 1; 
#endif 
/* 2009.05.31 modified by hongzhe.liu - */
#endif

/*****************************************************************************
 * FUNCTION
 *  aud_fmr_power_on_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_power_on_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_power_on_req_struct *msg_p = (media_fmr_power_on_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->melody_output_device = msg_p->output_path;

   // aud_get_active_device_path_by_mode(msg_p->output_path, aud_fmr_set_output_device);
	if( aud_context_p->audio_mode == AUD_MODE_HEADSET )
		aud_fmr_set_output_device( custom_cfg_hw_aud_output_path( msg_p->output_path ) );  
	#if defined(FM_RADIO_WITH_TV)
	else if( aud_context_p->audio_mode == AUD_MODE_LOUDSPK)
		aud_fmr_set_output_device( custom_cfg_hw_aud_output_path( AUDIO_DEVICE_LOUDSPEAKER) );
	else
		aud_fmr_set_output_device( custom_cfg_hw_aud_output_path( AUDIO_DEVICE_LOUDSPEAKER) );
	#endif

    FMR_PowerOn();
#endif /* __MED_FMR_MOD__ */ 
    AUD_SET_EVENT(AUD_EVT_FMR_ON);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_power_off_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_power_off_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MED_FMR_MOD__
    FMR_PowerOff();
#endif 
    AUD_SET_EVENT(AUD_EVT_FMR_OFF);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_set_freq_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_set_freq_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_set_freq_req_struct *msg_p = (media_fmr_set_freq_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMR_SetFreq(msg_p->freq);
#endif /* __MED_FMR_MOD__ */ 
    AUD_SET_EVENT(AUD_EVT_FMR_SET);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_mute_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_mute_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_mute_req_struct *msg_p = (media_fmr_mute_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMR_Mute(msg_p->mute);
#endif /* __MED_FMR_MOD__ */ 
    AUD_SET_EVENT(AUD_EVT_FMR_MUTE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_check_is_valid_stop_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_check_is_valid_stop_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_check_is_valid_stop_req_struct *msg_p =
        (media_fmr_check_is_valid_stop_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint8 result = FMR_ValidStop(msg_p->freq, (signed char)FM_RADIO_INPUT_LEVEL_THRESHOLD, msg_p->is_step_up);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    aud_send_fmr_check_is_valid_stop_cnf(result);
#else /* __MED_FMR_MOD__ */ 
    aud_send_fmr_check_is_valid_stop_cnf(1);
#endif /* __MED_FMR_MOD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_get_signal_level_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_get_signal_level_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_get_signal_level_req_struct *msg_p = (media_fmr_get_signal_level_req_struct*) ilm_ptr->local_para_ptr;
    #if defined(FM_RADIO_WITH_TV)
    kal_uint16 result;
    #else  
    kal_uint8 result;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FMR_ValidStop(msg_p->freq, (signed char)FM_RADIO_INPUT_LEVEL_THRESHOLD, msg_p->is_step_up))
    {
#ifndef WIN32
//Huyanwei Add Macro Control
         #if defined(FM_RADIO_WITH_TV)
	 result = FMR_GetSignalLevel( msg_p->freq );
	#else
        result = FMR_GetSignalLevel(msg_p->freq) + 1;
        #endif

#endif
    }
    else
    {
        result = 0;
    }

    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    aud_send_fmr_get_signal_level_cnf(result);
#else /* __MED_FMR_MOD__ */ 
    aud_send_fmr_get_signal_level_cnf(5);
#endif /* __MED_FMR_MOD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_set_volume(kal_uint8 volume1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MED_FMR_MOD__
    AUD_TRACE_VOLUME(AUD_VOLUME_FMR, volume1, 0);
    FMR_SetOutputVolume(volume1, 0);
#elif defined(__MED_TLG_TV_MOD__) //ANALOG_TV_SUPPORT
    AUD_TRACE_VOLUME( AUD_VOLUME_FMR, volume1, 0);
    AFE_SetOutputVolume( L1SP_FM_RADIO, volume1, 0 );
#endif
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_set_output_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_set_output_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MED_FMR_MOD__
    AUD_TRACE_PATH(AUD_TYPE_FMR, device, -1);
    FMR_SetOutputDevice(device);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_evaluate_threshold_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_evaluate_threshold_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_FMR_MOD__) && defined(__MTK_TARGET__)
    AUD_TRACE_PATH(AUD_TYPE_FMR, -1, -1);
    FMR_EvaluateRSSIThreshold();
#endif 

    AUD_SET_EVENT(AUD_EVT_FMR_EVA_THRESHOLD);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_is_power_on
 * DESCRIPTION
 *  check if FM radio is currently power on
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_fmr_is_power_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_FMR_MOD__) && defined(__MTK_TARGET__)
    return FMR_IsActive();
#else
    return KAL_FALSE;
#endif 
}

#endif /* MED_NOT_PRESENT */ 

//ANALOG_TV_SUPPORT
//anlaog tv start
#ifdef __MED_TLG_TV_MOD__

void aud_analog_tv_set_output_device( kal_uint8 device )
{

	AUD_TRACE_PATH( AUD_TYPE_FMR, device, -1 )
#ifndef WIN32
//Huyanwei Add Macro Control
	analog_tv_SetOutputDevice( device );
#endif

}
void aud_analog_tv_power_up_hdlr(ilm_struct *ilm_ptr)
{
 media_analog_tv_power_up_req_struct *req_p;
	//MEDIA_STATUS_CODE status;
        req_p = (media_analog_tv_power_up_req_struct*)ilm_ptr->local_para_ptr;
	/*call  analog tv init function*/
	TLG1100_PowerOn();
	TLG_TV_SET_EVENT(TLG_TV_EVT_PWR_ON);
}
void aud_analog_tv_power_down_hdlr(ilm_struct *ilm_ptr)
{
media_analog_tv_power_down_req_struct *req_p;
	//MEDIA_STATUS_CODE status;
        req_p = (media_analog_tv_power_down_req_struct*)ilm_ptr->local_para_ptr;
	/*call  analog tv power down function*/
	TLG1100_PowerOff();
	TLG_TV_SET_EVENT(TLG_TV_EVT_PWR_OFF);
}
void aud_analog_tv_open_path_req_hdlr( ilm_struct *ilm_ptr )
{

	media_analog_tv_open_path_req_struct* msg_p = (media_analog_tv_open_path_req_struct*)ilm_ptr->local_para_ptr;
	//aud_context_p->melody_output_device=msg_p->output_path;
     
	if( aud_context_p->audio_mode == AUD_MODE_HEADSET )
		aud_analog_tv_set_output_device( custom_cfg_hw_aud_output_path( AUDIO_DEVICE_SPEAKER2) );
	else if( aud_context_p->audio_mode == AUD_MODE_LOUDSPK)
		aud_analog_tv_set_output_device( custom_cfg_hw_aud_output_path( AUDIO_DEVICE_LOUDSPEAKER) );
	else 
		aud_analog_tv_set_output_device( custom_cfg_hw_aud_output_path( AUDIO_DEVICE_LOUDSPEAKER) );

	TLG_TV_SET_EVENT( TLG_TV_EVT_OPEN_PATH );
}

void aud_analog_tv_close_path_req_hdlr( ilm_struct *ilm_ptr )
{

	TLG_TV_SET_EVENT( TLG_TV_EVT_CLOSE_PATH );
}

void aud_analog_tv_mute_req_hdlr( ilm_struct *ilm_ptr )
{

	media_analog_tv_mute_req_struct* msg_p = (media_analog_tv_mute_req_struct*)ilm_ptr->local_para_ptr;
#ifndef WIN32
//Huyanwei Add Macro Control
	analog_tv_Mute( msg_p->mute );
#endif
	TLG_TV_SET_EVENT( TLG_TV_EVT_MUTE);
}

aud_analog_tv_set_channel_req_hdlr(  ilm_struct *ilm_ptr)
{
      media_analog_tv_set_channel_req_struct* msg_p = (media_analog_tv_set_channel_req_struct*)ilm_ptr->local_para_ptr;
      kal_uint8 ret=0;
	ret=TLGAPP_SetChannel(msg_p->channel);
      aud_context_p->src_mod = ilm_ptr->src_mod_id;
      aud_analog_tv_set_channel_cnf( ret);

}


void aud_analog_tv_get_valid_channel_req_hdlr( ilm_struct *ilm_ptr )
{

	media_analog_tv_get_valid_channel_req_struct* msg_p = (media_analog_tv_get_valid_channel_req_struct*)ilm_ptr->local_para_ptr;
	kal_uint8 ret;
	if(TLGAPP_SetChannel(msg_p->chan))
	{
	   ret=1;	
	}
	else
	   ret=0;
	aud_context_p->src_mod = ilm_ptr->src_mod_id;
	aud_analog_tv_get_valid_channel_cnf( ret);
}

#endif

