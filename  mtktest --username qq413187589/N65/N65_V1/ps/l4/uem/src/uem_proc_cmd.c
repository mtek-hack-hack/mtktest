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
 * UEM_PROC_CMD.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4C->UEM command using.
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
 * removed!
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

/***************************************************************************** 
* Include
*****************************************************************************/
#define NEW_FRAME

#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "kal_trace.h"
#include "stdio.h"
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "stack_timer.h"
#include "event_shed.h"
#include "med_struct.h"

#include "lcd_if.h"
#include "l1audio.h"
#include "melody.h"
#include "rtc_sw.h"
#include "gpio_sw.h"
#include "keypad_sw.h"
#include "pwic.h"
#include "device.h"
#include "pmic6318_sw.h"
#include "uart_sw.h"

#if defined (__WIFI_SUPPORT__)
#include "wndrv_cnst.h"
#include "wndrv_ft_types.h"
#include "wndrv_cal.h"
#include "wndrv_ft_msg.h"
#endif

#include "mph_types.h"
#include "mph_cnst.h"
#include "rftool_types.h"

#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "nvram_editor_data_item.h"
#include "nvram.h"
#include "custom_nvram_editor_data_item.h"
#include "nvram_interface.h"

#include "l4c2uem_struct.h"
#include "l4c_eq_msg.h"

#include "resource_audio.h"

#include "custom_equipment.h"
#include "custom_led_patterns.h"
#include "custom_hw_default.h"

#include "uem_context.h"
#include "uem_main.h"
#include "uem_trc.h"
#include "uem_utility.h"
#include "uem_proc_msg.h"
#include "uem_proc_cmd.h"
#include "uem_gpio_ctrl.h"
#include "l4c_common_enum.h"

#ifdef __DRM_V02__
#include "app_datetime.h"
extern void DRM_update_local_time(applib_time_struct *old_time, applib_time_struct* new_time, kal_bool reliable);
#endif

/***************************************************************************** 
* Define
*****************************************************************************/
#define MINIMUM(A,B) (((A)<(B))?(A):(B))

/***************************************************************************** 
* Extern Functions
*****************************************************************************/
#ifdef __MTK_TARGET__
extern DRV_RESET(void);
extern void BMT_CallState(kal_uint8 callState);
#endif /* __MTK_TARGET__ */ 

#if defined(DCM_ENABLE)
extern kal_uint8 DCM_Disable(kal_uint8 handle);
extern kal_uint8 DCM_Enable(kal_uint8 handle);
#endif /* defined(DCM_ENABLE) */ 

extern void UART_TurnOnPower(UART_PORT port, kal_bool enable);

#ifdef FM_RADIO_ENABLE
extern void FMR_Radio_EngineerMode(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value);
#endif /* #ifdef FM_RADIO_ENABLE */

#if defined(__WIFI_SUPPORT__)
extern void uemdrv_rf_test_wifi_rx_pkt_callback(wndrv_test_rx_status_struct* result);
#endif

/***************************************************************************** 
* Extern Variable
*****************************************************************************/
#if defined(PLUTO_MMI)
extern kal_bool SanityCheckDone;
#endif 

/***************************************************************************** 
* Global Variables
*****************************************************************************/
kal_uint8 uem_adc_on = 0;
eventid uem_adc_timer_id = 0;

/******************************************************************************/
/*******************   External Functions *************************************/
/******************************************************************************/
/*****************************************************************************
*   Function 
*      l4cuem_audio_play_req
*   DESCRIPTION
*      The function is used to play the audio device. Including keypad, tone, and melody play.
*   PARAMETERS
*      audio_device_id   IN   
*      audio_sound_id      IN
*      audio_volume      IN
*      audio_play_style   IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_audio_play_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_sound_id          [IN]        
 *  audio_play_style        [IN]        
 *  identifier              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_audio_play_req(kal_uint8 audio_sound_id, kal_uint8 audio_play_style, kal_uint16 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_AUDIO_PLAY);

    uem_send_msg_to_aud(
        MSG_ID_L4AUD_AUDIO_PLAY_REQ,
        (kal_uint32) audio_sound_id,
        (kal_uint32) audio_play_style,
        (kal_uint32) identifier);
}

/*****************************************************************************
*   Function 
*      l4cuem_audio_stop_req
*   DESCRIPTION
*      The function is used to stop the audio device play. Including keypad, tone, and melody stop.
*   PARAMETERS
*      audio_device   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_audio_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_sound_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_audio_stop_req(kal_uint8 audio_sound_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_AUDIO_STOP);
    uem_send_msg_to_aud(MSG_ID_L4AUD_AUDIO_STOP_REQ, (kal_uint32) audio_sound_id);
}

/*****************************************************************************
*   Function 
*      l4cuem_audio_set_volume_req 
*   DESCRIPTION
*      The function is used to adjust audio volume.
*   PARAMETERS
*      audio_device   IN
*      volume_level   IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_audio_set_volume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume_type         [IN]        
 *  volume_level        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_audio_set_volume_req(kal_uint8 volume_type, kal_uint8 volume_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (volume_type)
    {
        case VOL_TYPE_MEDIA:
        {
            uem_send_msg_to_aud(
                MSG_ID_L4AUD_AUDIO_SET_VOLUME_REQ,
                (kal_uint32) volume_type,
                (kal_uint32) volume_level,
                (kal_uint32) volume_level,
                (kal_uint32) 0);
            break;
        }
        case VOL_TYPE_SPH:
        {
            uem_send_msg_to_aud(
                MSG_ID_L4AUD_AUDIO_SET_VOLUME_REQ,
                (kal_uint32) volume_type,
                (kal_uint32) volume_level,
                (kal_uint32) volume_level,
                (kal_uint32) 0);
            break;
        }
        case VOL_TYPE_KEY:
        {
            uem_send_msg_to_aud(
                MSG_ID_L4AUD_AUDIO_SET_VOLUME_REQ,
                (kal_uint32) volume_type,
                (kal_uint32) volume_level,
                (kal_uint32) volume_level,
                (kal_uint32) 0);
            break;
        }
        case VOL_TYPE_MIC:
        case VOL_TYPE_CTN:
        case VOL_TYPE_SID:
        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_audio_get_volume_req
*   DESCRIPTION
*      The function is used to get audio volume.
*   PARAMETERS
*      audio_device   IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_audio_get_volume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_audio_get_volume_req(kal_uint8 volume_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_L4AUD_AUDIO_GET_VOLUME_REQ, volume_type);
    /* aud_audio_get_volume_req(volume_type, volume); */
}

/*****************************************************************************
*   Function 
*      l4cuem_demo_ext_imelody_ring_req
*   DESCRIPTION
*      Demo the extended imelody. The note stream can be used in EMS or 
*      Ring Composer.
*   PARAMETERS
*      imelody       IN
*      len               IN
*      play_style    IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_demo_ext_imelody_ring_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imelody         [?]         
 *  len             [IN]        
 *  play_style      [IN]        
 *  identifier      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_demo_ext_imelody_ring_req(
        kal_uint8 *imelody,
        kal_uint16 len,
        kal_uint8 play_style,
        /* audio_play_style_enum */ kal_uint16 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_DEMO_EXT_IMELODY_RING);

    uem_send_msg_to_aud(
        MSG_ID_L4AUD_AUDIO_DEMO_IMY_REQ,
        (kal_uint32) imelody,
        (kal_uint32) len,
        (kal_uint32) play_style,
        (kal_uint32) identifier);
}

/*****************************************************************************
*   Function 
*      l4cuem_power_off_req  
*   DESCRIPTION
*      The function is used to notify the MMI will power off. 
*   PARAMETERS
*   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_power_off_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_power_off_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_POEWR_OFF);

    nvram_shutdown_handler();

#if defined(PLUTO_MMI)
    if (SanityCheckDone)
#endif 
        FS_ClearDiskFlag();

    FS_ShutDown();

    /* Turn off backlight */
    custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, 0);

    /* Turn off LCD before baseband power off */
    lcd_power_on(MAIN_LCD, KAL_FALSE);
#ifdef DUAL_LCD
    lcd_power_on(SUB_LCD, KAL_FALSE);
#endif 

    /* Turn off the power */
    DRV_POWEROFF();
    DRV_RESET();
}

/*****************************************************************************
*   Function 
*      l4cuem_rtc_get_count_req
*   DESCRIPTION
*      The function is used to retrieve the RTC alarm count value.
*   PARAMETERS
*      rtctime   OUT   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_get_count_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 l4cuem_rtc_get_count_req(kal_uint8 rtc_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rtc_type == RTC_TIME_CLOCK_IND)
    {
        count = 0;
    }
    else
    {
        for (i = 0; i < MAX_ALARM_NUM; i++)
        {
            if (g_uem_cntx_p->rmi_data.alarm_info[i].alarm_format != DEVICE_AL_EN_None)
            {
                ++count;
            }
        }
    }
    return count;
}

/*****************************************************************************
*   Function 
*      l4cuem_rtc_get_time_req
*   DESCRIPTION
*      The function is used to retrieve the RTC alarm time value.
*   PARAMETERS
*      rtctime   OUT   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_get_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtc_alarm_id        [IN]        
 *  rtctime             [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_rtc_get_time_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id, rtc_alarm_info_struct *rtctime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    t_rtc l_rtctime;
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_GET_TIME);

    ASSERT(rtctime != NULL);    /* invalid address */

    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
            RTC_GetTime(&l_rtctime);

            rtctime->data_time.rtc_day = l_rtctime.rtc_day;
            rtctime->data_time.rtc_hour = l_rtctime.rtc_hour;
            rtctime->data_time.rtc_min = l_rtctime.rtc_min;
            rtctime->data_time.rtc_sec = l_rtctime.rtc_sec;
            rtctime->data_time.rtc_year = (kal_uint8) l_rtctime.rtc_year;
            rtctime->data_time.rtc_mon = l_rtctime.rtc_mon;
            rtctime->data_time.rtc_wday = l_rtctime.rtc_wday;

            result = KAL_TRUE;
            break;

        case RTC_ALARM_IND:
            if (rtc_alarm_id < MAX_ALARM_NUM)
            {
                /* return the alarm index */
                rtctime->alarm_index = rtc_alarm_id;

                kal_mem_cpy(rtctime, &(g_uem_cntx_p->rmi_data.alarm_info[rtc_alarm_id]), sizeof(rtc_alarm_info_struct));
                if (g_uem_cntx_p->rmi_data.alarm_info[rtc_alarm_id].alarm_format == DEVICE_AL_EN_None)
                {
                    result = KAL_FALSE;
                }
                else
                {
                    result = KAL_TRUE;
                }
            }
            else
            {
                kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
                result = KAL_FALSE;
            }
            break;

        default:
            kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
            break;
    }
    return result;
}

/*****************************************************************************
*  Function 
*     l4cuem_rtc_get_hw_time_req
*  DESCRIPTION
*     
*  PARAMETERS
*       ...  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_get_hw_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtc_alarm_id        [IN]        
 *  rtctime             [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_rtc_get_hw_time_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id, rtc_alarm_info_struct *rtctime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    t_rtc l_rtctime;
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_GET_TIME);

    ASSERT(rtctime != NULL);    /* invalid address */

    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
    #ifdef MMI_ON_WIN32

            rtctime->data_time.rtc_day = 1;
            rtctime->data_time.rtc_hour = 1;
            rtctime->data_time.rtc_min = 1;
            rtctime->data_time.rtc_sec = 1;
            rtctime->data_time.rtc_year = 3;
            rtctime->data_time.rtc_mon = 1;
            rtctime->data_time.rtc_wday = 1;
    #else /* MMI_ON_WIN32 */ 
            RTC_GetTime(&l_rtctime);

            rtctime->data_time.rtc_day = l_rtctime.rtc_day;
            rtctime->data_time.rtc_hour = l_rtctime.rtc_hour;
            rtctime->data_time.rtc_min = l_rtctime.rtc_min;
            rtctime->data_time.rtc_sec = l_rtctime.rtc_sec;
            rtctime->data_time.rtc_year = (kal_uint8) l_rtctime.rtc_year;
            rtctime->data_time.rtc_mon = l_rtctime.rtc_mon;
            rtctime->data_time.rtc_wday = l_rtctime.rtc_wday;
    #endif /* MMI_ON_WIN32 */ 
            result = KAL_TRUE;
            break;

        case RTC_ALARM_IND:
            RTC_GetALTime(&l_rtctime);
            rtctime->data_time.rtc_day = l_rtctime.rtc_day;
            rtctime->data_time.rtc_hour = l_rtctime.rtc_hour;
            rtctime->data_time.rtc_min = l_rtctime.rtc_min;
            rtctime->data_time.rtc_sec = l_rtctime.rtc_sec;
            rtctime->data_time.rtc_year = (kal_uint8) l_rtctime.rtc_year;
            rtctime->data_time.rtc_mon = l_rtctime.rtc_mon;
            rtctime->data_time.rtc_wday = l_rtctime.rtc_wday;
            result = KAL_TRUE;
            break;
        default:
            kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
            break;
    }
    return result;
}

/*****************************************************************************
*  Function 
*     l4cuem_rtc_set_time_req
*  DESCRIPTION
*     
*  PARAMETERS
*       ...  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_set_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtctime             [IN]        
 *  setting_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_rtc_set_time_req(kal_uint8 rtc_type, rtc_alarm_info_struct rtctime, kal_uint8 setting_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    t_rtc l_rtctime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_SET_TIME);

    switch (setting_type)   /* rtc_setting_type_enum */
    {
        case RTC_SETTING_TYPE_DATE:
            RTC_GetTime(&l_rtctime);
            l_rtctime.rtc_year = rtctime.data_time.rtc_year;
            l_rtctime.rtc_mon = rtctime.data_time.rtc_mon;
            l_rtctime.rtc_day = rtctime.data_time.rtc_day;
            l_rtctime.rtc_wday = rtctime.data_time.rtc_wday;
            break;

        case RTC_SETTING_TYPE_TIME:
            RTC_GetTime(&l_rtctime);
            l_rtctime.rtc_hour = rtctime.data_time.rtc_hour;
            l_rtctime.rtc_min = rtctime.data_time.rtc_min;
            l_rtctime.rtc_sec = rtctime.data_time.rtc_sec;
            break;

        case RTC_SETTING_TYPE_DATETIME:
        default:
            l_rtctime.rtc_year = rtctime.data_time.rtc_year;
            l_rtctime.rtc_mon = rtctime.data_time.rtc_mon;
            l_rtctime.rtc_day = rtctime.data_time.rtc_day;
            l_rtctime.rtc_hour = rtctime.data_time.rtc_hour;
            l_rtctime.rtc_min = rtctime.data_time.rtc_min;
            l_rtctime.rtc_wday = rtctime.data_time.rtc_wday;
            l_rtctime.rtc_sec = rtctime.data_time.rtc_sec;
            break;
    }

    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
    #ifdef __DRM_V02__
		{
			applib_time_struct old_time, new_time;

			applib_dt_get_rtc_time(&old_time);
			RTC_InitTC_Time(&l_rtctime);
			applib_dt_get_rtc_time(&new_time);

			DRM_update_local_time(&old_time, &new_time, KAL_FALSE);
		}
    #else
        RTC_InitTC_Time(&l_rtctime);

    #endif            



            RTC_Config(
                uem_rtc_alarm_format_convert(DEVICE_AL_EN_NoChange),
                uem_rtc_clock_format_convert(DEVICE_TC_EN_ChkM));
            break;
        case RTC_ALARM_IND:
            if (rtctime.alarm_index < MAX_ALARM_NUM)
            {
                RTC_SetAlarm(&l_rtctime);

                RTC_Config(
                    uem_rtc_alarm_format_convert(rtctime.alarm_format),
                    uem_rtc_clock_format_convert(DEVICE_TC_EN_NoChange));
            }
            else
            {
                kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
            }
            break;
        default:
            kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
            break;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_alarm_get_time_req
*   DESCRIPTION
*      The function is used to set the RTC alarm or clock time value.
*   PARAMETERS
*      rtctime   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_alarm_get_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_alarm_id        [IN]        
 *  alarm_info          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_alarm_get_time_req(kal_uint8 rtc_alarm_id, rtc_alarm_info_struct *alarm_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_ALARM_GET_TIME);

    ASSERT(alarm_info != NULL); /* invalid address */

    if (rtc_alarm_id < MAX_ALARM_NUM)
    {
        kal_mem_cpy(alarm_info, &(g_uem_cntx_p->rmi_data.alarm_info[rtc_alarm_id]), sizeof(rtc_alarm_info_struct));
    }
    else
    {
        /* error: out of range */
        kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_rtc_cnfg_format_req
*   DESCRIPTION
*      The function is used to set the RTC format.
*   PARAMETERS
*      rtctime   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_cnfg_format_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtc_alarm_id        [IN]        
 *  rtc_format_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_rtc_cnfg_format_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id, kal_uint8 rtc_format_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_CNFG_FORMAT);

    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
            RTC_Config(
                uem_rtc_alarm_format_convert(DEVICE_AL_EN_NoChange),
                uem_rtc_clock_format_convert(rtc_format_id));
            break;
        case RTC_ALARM_IND:
            if (rtc_alarm_id < MAX_ALARM_NUM)
            {
                RTC_Config(
                    uem_rtc_alarm_format_convert(rtc_format_id),
                    uem_rtc_clock_format_convert(DEVICE_TC_EN_NoChange));
            }
            break;
        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_rtc_delete_date_time_req
*   DESCRIPTION
*      The function is used to set the RTC format.
*   PARAMETERS
*      rtctime   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_delete_date_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtc_alarm_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_rtc_delete_date_time_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_DELETE_DATE_TIME);

    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
            l4cuem_rtc_cnfg_format_req(rtc_type, rtc_alarm_id, DEVICE_TC_EN_None);
            break;
        case RTC_ALARM_IND:
            l4cuem_rtc_cnfg_format_req(rtc_type, rtc_alarm_id, DEVICE_AL_EN_None);
            break;
        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_speech_set_mode_req
*   DESCRIPTION
*      The function is used to set the speech mode on/off while there is in a call setup.
*   PARAMETERS
*      speech_mode_onoff   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_speech_set_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  speech_mode_onoff       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_speech_set_mode_req(kal_bool speech_mode_onoff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, INFO_UEM_SPEECH_SET_MODE, speech_mode_onoff);

#ifdef __MTK_TARGET__
    if (speech_mode_onoff)
    {
        BMT_CallState(KAL_TRUE);
    }
    else
    {
        BMT_CallState(KAL_FALSE);
    }
#endif /* __MTK_TARGET__ */ 

    uem_send_msg_to_aud(MSG_ID_L4AUD_SP_SET_MODE_REQ, (kal_uint32) speech_mode_onoff);
}

/*****************************************************************************
*   Function 
*      l4cuem_call_status_ind
*   DESCRIPTION
*      The function is used to inform AUX if a calling is being set, connected or disconected.
*   PARAMETERS
*      ind_type   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_call_status_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ind_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_call_status_req_ind(kal_uint8 ind_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    switch (ind_type)
    {
        case UEM_CALL_SETUP:
            g_uem_cntx_p->incall_state = UEM_CALL_SETUP;

            /* Inform BMT call state active */
            BMT_CallState(KAL_TRUE);

            /* Inform AUB call state deactive */
            uem_send_msg_to_aux(MSG_ID_AUX_CALL_SETUP_REQ_IND);

            /* Change ADC measure parameter */
            uem_send_msg_to_bmt(
                MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ,
                (kal_uint32) (g_uem_cntx_p->adc_sche_id),
                (kal_uint32) (ADC_TALKING_EVAL_COUNT),
                (kal_uint32) (ADC_TALKING_EVAL_PERIOD));
            break;
        case UEM_CALL_CONNECT:
            g_uem_cntx_p->incall_state = UEM_CALL_CONNECT;
            uem_send_msg_to_aux(MSG_ID_AUX_CALL_CONNECT_REQ_IND);
            break;
        case UEM_CALL_DISCONNECT:
            g_uem_cntx_p->incall_state = UEM_CALL_DISCONNECT;

            /* Inform BMT call state deactive */
            BMT_CallState(KAL_FALSE);

            /* Inform AUX call state deactive */
            uem_send_msg_to_aux(MSG_ID_AUX_CALL_DISCONNECT_REQ_IND);

            /* Change ADC measure parameter */
            uem_send_msg_to_bmt(
                MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ,
                (kal_uint32) (g_uem_cntx_p->adc_sche_id),
                (kal_uint32) (ADC_IDLE_EVAL_COUNT),
                (kal_uint32) (ADC_IDLE_EVAL_PERIOD));
            break;
        default:
            break;
    }
#endif /* __MTK_TARGET__ */ 
}

/*****************************************************************************
*   Function 
*      l4cuem_set_mute_req
*   DESCRIPTION
*      The function is used to turn on/off the microphone.
*   PARAMETERS
*      mute_onoff   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_mute_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_device        [IN]        
 *  mute_onoff          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_mute_req(kal_uint8 audio_device, kal_bool mute_onoff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_MUTE);

    /* store the audio mute flag */
    uem_audio_set_mute(audio_device, mute_onoff);

    uem_send_msg_to_aud(MSG_ID_L4AUD_AUDIO_MUTE_REQ, (kal_uint32) audio_device, (kal_uint32) mute_onoff);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_mute_req
*   DESCRIPTION
*      The function is used to retrieve the mute information.
*   PARAMETERS
*      mute_onoff   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_mute_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_device        [IN]        
 *  is_mute             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_mute_req(kal_uint8 audio_device, kal_bool *is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_MUTE);

    ASSERT(is_mute != NULL);    /* invalid address */

    *is_mute = uem_audio_get_mute(audio_device);
}

/*****************************************************************************
*   Function 
*      l4cuem_gpio_set_level_req
*   DESCRIPTION
*      The function is used to set the level of the GPIO device including the vibrator.
*   PARAMETERS
*      gpio_dev_type      IN
*      gpio_dev_level      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_gpio_set_level_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gpio_dev_type       [IN]        
 *  gpio_dev_level      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_gpio_set_level_req(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GPIO_SET_LEVEL);

    uem_set_gpio_status(gpio_dev_type, gpio_dev_level); /* Cylen 2005/08/23 GPIO Setting */
    custom_cfg_gpio_set_level(gpio_dev_type, gpio_dev_level);
}

/*****************************************************************************
*   Function 
*      l4cuem_pattern_play_req
*   DESCRIPTION
*      The function is used to play vibrator pattern.
*   PARAMETERS
*      pattern      IN
*      action      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_pattern_play_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pattern     [IN]        
 *  action      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_pattern_play_req(kal_uint8 pattern, kal_uint8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_play_pattern(pattern, action);
}

/*****************************************************************************
*   Function 
*     l4cuem_pattern_stop_req
*   DESCRIPTION
*      The function is used to play led pattern.
*   PARAMETERS
*      pattern      IN
*      action      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_pattern_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pattern     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_pattern_stop_req(kal_uint8 pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_stop_pattern(pattern);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_equip_id_req
*   DESCRIPTION
*      Retrieve the string of the equipment ID.
*   PARAMETERS
*      equip_id      IN
*   RETURNS
*      kal_uint8*
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_equip_id_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  equip_id            [IN]        
 *  equip_string        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_equip_id_req(kal_uint8 equip_id, kal_uint8 *equip_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_EQUIP_ID);

    ASSERT(equip_string != NULL);   /* invalid address */

    uem_get_equip_id(equip_id, equip_string);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_battery_status_req
*   DESCRIPTION
*      Retrieve the battery status.
*   PARAMETERS
*      battery_status      OUT
*     battery_vol         OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_battery_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  battery_status      [?]     
 *  battery_vol         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_battery_status_req(kal_uint8 *battery_status, kal_uint8 *battery_vol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_BATTERY_STATUS);

    ASSERT((battery_status != NULL) && (battery_vol != NULL));  /* invalid address */

    uem_get_bat_status(&bmt_status);
    *battery_status = bmt_status.status;
    *battery_vol = uem_vbat_level_convert(bmt_status.volt);
}

/*****************************************************************************
*   Function 
*      l4cuem_set_silent_mode_req
*   DESCRIPTION
*      Set the silent.
*   PARAMETERS
*      is_silent      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_silent_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_silent       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_silent_mode_req(kal_bool is_silent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_SILENT_MODE);

    uem_set_silent_mode(is_silent);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_silent_mode_req
*   DESCRIPTION
*      Set the silent.
*   PARAMETERS
*      mode  OUT
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_silent_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_silent       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_silent_mode_req(kal_uint8 *is_silent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_SILENT_MODE);

    ASSERT(is_silent != NULL);  /* invalid address */

    *is_silent = uem_get_silent_mode();
}

/*****************************************************************************
*   Function 
*      l4cuem_set_alert_mode_req
*   DESCRIPTION
*      Set the alert mode.
*   PARAMETERS
*      void
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_alert_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alert_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_alert_mode_req(kal_uint8 alert_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_ALERT_MODE);

    uem_set_alert_mode(alert_mode);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_alert_mode_req
*   DESCRIPTION
*      Set the silent.
*   PARAMETERS
*      void
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_alert_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alert_mode      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_alert_mode_req(kal_uint8 *alert_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_ALERT_MODE);

    ASSERT(alert_mode != NULL); /* invalid address */

    *alert_mode = uem_get_alert_mode();
}

/*****************************************************************************
*   Function 
*      l4cuem_set_greeting_text_req
*   DESCRIPTION
*      RMI requests L4C to set date format. Please reference the AT command "+CSDF".
*   PARAMETERS
*      mode      OUT
*      greeting_text       OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_greeting_text_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode                [IN]        
 *  text_dcs            [IN]        
 *  greeting_text       [?]         
 *  no_text             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_greeting_text_req(kal_bool mode, kal_uint8 text_dcs, kal_uint8 *greeting_text, kal_uint8 no_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_GREETING_TEXT);

    ASSERT(greeting_text != NULL);

    if (no_text >= UEM_GREETING_LEN)
    {
        no_text = UEM_GREETING_LEN - 1;
    }
    greeting_text[no_text] = '\0';

    uem_set_greeting_text(mode, text_dcs, greeting_text, no_text);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_greeting_text_req
*   DESCRIPTION
*      RMI requests L4C to set date format. Please reference the AT command "+CSDF".
*   PARAMETERS
*      mode      OUT
*      greeting_text       OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_greeting_text_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode                [?]     
 *  text_dcs            [?]     
 *  greeting_text       [?]     
 *  text_no             [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_greeting_text_req
    (kal_uint8 *mode, kal_uint8 *text_dcs, kal_uint8 *greeting_text, kal_uint8 *text_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_GREETING_TEXT);

    ASSERT((mode != NULL) && (greeting_text != NULL));  /* invalid address */

    uem_get_greeting_text(mode, text_dcs, greeting_text, text_no);
}

/*****************************************************************************
*   Function 
*      l4cuem_gpio_get_level_req
*   DESCRIPTION
*      L4C requests UEM to get gpio value. Please reference the AT command "+CVIB".
*   PARAMETERS
*      mode      OUT
*      greeting_text       OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_gpio_get_level_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gpio_device         [IN]        
 *  gpio_dev_level      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_gpio_get_level_req(kal_uint8 gpio_device, kal_uint8 *gpio_dev_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GPIO_GET_LEVEL);

    ASSERT(gpio_dev_level != NULL); /* invalid address */

    if (gpio_device < MAX_GPIO_DEVICE_NUM)
    {
        *gpio_dev_level = uem_get_gpio_status(gpio_device);
    }
    else
    {
        *gpio_dev_level = 0;
        kal_trace(TRACE_WARNING, WARNING_UEM_OUT_OF_RANGE);
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_equip_set_cc_req
*   DESCRIPTION
*      L4C requests UEM to set the country code. Please reference the AT command "+GCI".
*   PARAMETERS
*      country_code      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_equip_set_cc_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  country_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_equip_set_cc_req(kal_uint8 country_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_EQUIP_SET_CC);

    g_uem_cntx_p->rmi_data.country_code = country_code;
}

/*****************************************************************************
*   Function 
*      l4cuem_equip_get_cc_req
*   DESCRIPTION
*      L4C requests UEM to get the country code. Please reference the AT command "+GCI".
*   PARAMETERS
*      country_code      OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_equip_get_cc_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  country_code        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_equip_get_cc_req(kal_uint8 *country_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_EQUIP_GET_CC);

    ASSERT(country_code != NULL);   /* invalid address */

    *country_code = g_uem_cntx_p->rmi_data.country_code;
}

/*****************************************************************************
*   Function 
*      l4cuem_set_lang_req
*   DESCRIPTION
*      L4C requests UEM to store the current language. Please reference the AT command "+CLAV".
*   PARAMETERS
*      lang_id      OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_lang_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang_id_0       [IN]        
 *  lang_id_1       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_lang_req(kal_uint8 lang_id_0, kal_uint8 lang_id_1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_LANG);

    g_uem_cntx_p->rmi_data.lang_id[0] = lang_id_0;
    g_uem_cntx_p->rmi_data.lang_id[1] = lang_id_1;
}

/*****************************************************************************
*   Function 
*      l4cuem_get_lang_req
*   DESCRIPTION
*      L4C requests UEM to store the current language. Please reference the AT command "+CLAV".
*   PARAMETERS
*      lang_id      OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_lang_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang_id     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_lang_req(kal_uint8 *lang_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_LANG);

    ASSERT(lang_id != NULL);    /* invalid address */

    lang_id[0] = g_uem_cntx_p->rmi_data.lang_id[0];
    lang_id[1] = g_uem_cntx_p->rmi_data.lang_id[1];
}

/*****************************************************************************
*   Function 
*      l4cuem_set_date_time_format_req
*   DESCRIPTION
*      L4C requests UEM to store date format. Please reference the AT command "+CSDF".
*   PARAMETERS
*      lang_id      OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_date_time_format_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_date_set     [IN]        
 *  mode            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_date_time_format_req(kal_bool is_date_set, kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_DATE_TIME_FORMAT);

    /* ref: date_format_enum/time_format_enum */
    uem_set_datetime_format(is_date_set, mode);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_date_time_format_req
*   DESCRIPTION
*      L4C requests UEM to retrieve date format. Please reference the AT command "+CSDF".
*   PARAMETERS
*      lang_id      OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_date_time_format_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_date_set     [IN]        
 *  mode            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_date_time_format_req(kal_bool is_date_set, kal_uint8 *mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_DATE_TIME_FORMAT);

    ASSERT(mode != NULL);   /* invalid address */

    /* ref: date_format_enum/time_format_enum */
    *mode = uem_get_datetime_format(is_date_set);
}

/*****************************************************************************
*   Function 
*      l4cuem_set_accustic_value
*   DESCRIPTION
*      set the accustic gain value
*   PARAMETERS
*      kal_uint8 volume_type,
*      kal_uint8 volume_level,
*      kal_uint8 volume_gain
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_accustic_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume_type         [IN]        
 *  volume_level        [IN]        
 *  volume_gain         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_set_accustic_value(kal_uint8 volume_type, kal_uint8 volume_level, kal_uint8 volume_gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool res = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(
        MSG_ID_L4AUD_AUDIO_SET_GAIN_REQ,
        (kal_uint32) volume_type,
        (kal_uint32) volume_level,
        (kal_uint32) volume_gain);
    return res;
}

/*****************************************************************************
*   Function 
*      l4cuem_get_accustic_value
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*      kal_uint8 volume_type,
*      kal_uint8 volume_level,
*      kal_uint8 volume_gain
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_accustic_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume_type         [IN]        
 *  volume_level        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_accustic_value(kal_uint8 volume_type, kal_uint8 volume_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* kal_bool   res = KAL_TRUE; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_L4AUD_AUDIO_GET_GAIN_REQ, volume_type, volume_level);

    /* aud_audio_get_gain_req(volume_type, volume_level, volume_gain); */

    /* return res; */
}

/*****************************************************************************
*   Function 
*      l4cuem_power_reset
*   DESCRIPTION
*      power reset 
*   PARAMETERS
*      kal_uint8 reset_type
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_power_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  reset_type      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_power_reset(
            kal_uint8 reset_type /* pmic_reset_type_enum */ )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool res = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_POWER_RESET);

    /* Turn off backlight */
    custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, 0);        
        	
    switch (reset_type)
    {
        case NORMAL_RESET:
        {
            /* Turn off LCD before baseband power off */
            lcd_power_on(MAIN_LCD, KAL_FALSE);
        #ifdef DUAL_LCD
            lcd_power_on(SUB_LCD, KAL_FALSE);
        #endif 

            DRV_RESET();
            break;
        }
        case CHARGING_RESET:
        {
            /* Turn off LCD before baseband power off */
            lcd_power_on(MAIN_LCD, KAL_FALSE);
        #ifdef DUAL_LCD
            lcd_power_on(SUB_LCD, KAL_FALSE);
        #endif 

            /* New_USB_Mode */
            nvram_shutdown_handler();

            DRV_POWEROFF();
            DRV_RESET();

            break;
        }
        case ALARM_RESET:
        {
            /* New_USB_Mode */
        #ifdef __NVRAM_IN_USB_MS__
            nvram_shutdown_handler();
        #endif 
            if (POWER_ON_PRECHARGE != uem_get_poweron_mode())
            {
                uem_send_msg_to_l4c(MSG_ID_L4CUEM_STARTUP_CNF, NULL);
            }
            break;
        }
        default:
        {
            res = KAL_FALSE;
            kal_trace(TRACE_WARNING, WARNING_UEM_OUT_OF_RANGE);
            break;
        }
    }
    return res;
}

/*****************************************************************************
*  Function 
*     l4cuem_get_audio_profile_req
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_audio_profile_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_audio_profile_req(kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_L4AUD_GET_AUDIO_PROFILE_REQ, mode);
    //    aud_get_audio_profile_req(aud_profile);
    //    return KAL_TRUE;
}

/*****************************************************************************
*  Function 
*     l4cuem_get_audio_param_req
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_audio_param_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_audio_param_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_L4AUD_GET_AUDIO_PARAM_REQ);
    /* aud_get_audio_param_req( audio_param ); */
}

/*****************************************************************************
*  Function 
*     l4cuem_set_audio_mode
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_audio_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_audio_mode(kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_L4AUD_SET_AUDIO_MODE_REQ, (kal_uint32) mode);
}

/*****************************************************************************
*  Function 
*     l4cuem_get_adc_all_channel_stop_req
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_adc_all_channel_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_adc_all_channel_stop_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_adc_on = 0;
    if (ADC_EVENT_TIMER != 0)
    {
        uem_stop_timer(ADC_EVENT_TIMER);
    }
}

/*****************************************************************************
*  Function 
*     l4cuem_get_adc_all_channel_start_req
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_adc_all_channel_start_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_adc_all_channel_start_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_adc_on = 1;
    uem_send_msg_to_aux(MSG_ID_READ_ALL_ADC_CHANNEL_REQ);
}

/*****************************************************************************
*  Function 
*     l4cuem_get_hw_level_req
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_hw_level_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hw_level        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_get_hw_level_req(l4cuem_set_hw_level_req_struct *hw_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hw_level)
    {
        kal_mem_set(hw_level, 0, sizeof(l4cuem_set_hw_level_req_struct));
        for (i = 0; i < 5; i++)
        {
            hw_level->PWM1_freq_Level_Info[i] = PWM1_Level_Info[i][0];
            hw_level->PWM1_duty_Level_Info[i] = PWM1_Level_Info[i][1];

            hw_level->PWM2_freq_Level_Info[i] = PWM2_Level_Info[i][0];
            hw_level->PWM2_duty_Level_Info[i] = PWM2_Level_Info[i][1];

            hw_level->PWM3_freq_Level_Info[i] = Alter_Level_Info[i][0];
            hw_level->PWM3_duty_Level_Info[i] = Alter_Level_Info[i][1];
        }
        for (i = 0; i < LCD_CONTRAST_MAX_LEVEL; i++)
        {
            hw_level->MainLCD_Contrast_Level_Info[i] = MainLCD_Contrast_Level_Info[i];
        #ifdef DUAL_LCD
            hw_level->SubLCD_Contrast_Level_Info[i] = SubLCD_Contrast_Level_Info[i];
        #endif 
        }

        for (i = 0; i < LCD_PARAM_MAX_LEVEL; i++)
        {
            hw_level->MainLCD_Bias_Level_Info[i] = MainLCD_Bias_Level_Info[i];
            hw_level->MainLCD_Linerate_Level_Info[i] = MainLCD_Linerate_Level_Info[i];
            hw_level->MainLCD_Temp_Level_Info[i] = MainLCD_Temp_Level_Info[i];

        #ifdef DUAL_LCD
            hw_level->SubLCD_Bias_Level_Info[i] = SubLCD_Bias_Level_Info[i];
            hw_level->SubLCD_Linerate_Level_Info[i] = SubLCD_Linerate_Level_Info[i];
            hw_level->SubLCD_Temp_Level_Info[i] = SubLCD_Temp_Level_Info[i];
        #endif /* DUAL_LCD */ 
        }
        for (i = 0; i < BATTERY_MAX_LEVEL; i++)
        {
            hw_level->Battery_Level_Info[i] = Battery_Level_Info[i];
        }
    }
    else
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

#ifdef __USB_ENABLE__
/*****************************************************************************
*  Function 
*     l4cuem_usbconfig_req
*  DESCRIPTION
*     Config USB
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_usbconfig_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_id          [IN]        
 *  mode            [IN]        
 *  reserved        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_usbconfig_req(kal_uint8 src_id, kal_uint8 mode, kal_uint32 reserved)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 usb_action_4_drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uem_cntx_p->usb_msg_src_id = src_id;

    usb_action_4_drv = (kal_uint32) uem2drv_usb_config_action_convert(mode);
    uem_send_msg_to_usbms(MSG_ID_DRVUEM_USBCFG_REQ, usb_action_4_drv, (kal_uint32) reserved);
}
#endif /* __USB_ENABLE__ */ 

/*****************************************************************************
*  Function 
*     ueml4c_em_pmic_config_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_em_pmic_config_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_id              [IN]        
 *  request_type        [IN]        
 *  request             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_em_pmic_config_req(kal_uint8 src_id, kal_uint8 request_type, pmic_config_param_struct request)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(MT6318) && defined(PLUTO_MMI)
    kal_uint8 i = 0;
    custom_hw_level_struct cust_hw_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (request_type)
    {
        case PMIC_GET_CHR_STATE:
        {
            pmic_chr_state_struct *req = &(request.chr_state);

            req->charger_status = pmic_chr_status(req->status);
            break;
        }
        case PMIC_GET_AC_USB:
        {
            pmic_get_ac_usb_status_struct *req = &(request.ac_usb_status);

            pmic_get_ac_usb_status(req->type, &req->chr_enable, &req->current);
            break;
        }
        case PMIC_GET_LED_CONFIG:
        {
            pmic_get_led_config_struct *req = &(request.led_config);

            pmic_get_LED_config(req->type, &req->duty, &req->current);
            break;
        }
        case PMIC_GET_RGB_DIM:
        {
            pmic_get_rgb_dim_struct *req = &(request.rgb_dim);

            pmic_get_rgb_dim(&req->pump_enable, &req->pump_current, &req->clk);
            break;
        }
        case PMIC_GET_BL_DIM:
        {
            pmic_get_bl_dim_struct *req = &(request.bl_dim);

            pmic_get_BL_dim(&req->div_enable, &req->clk);
            break;
        }
        case PMIC_GET_SPEAKER_STATE:
        {
            pmic_get_speaker_state_struct *req = &(request.speaker_state);

            req->state = pmic_get_speaker_stat();
            break;
        }
        case PMIC_GET_SPEAKER_GAIN:
        {
            pmic_get_speaker_gain_struct *req = &(request.speaker_gin);

            req->gain = pmic_get_speaker_gain();
            break;
        }
        case PMIC_GET_MISC_LDO_STATE:
        {
            pmic_get_misc_ldo_stat_struct *req = &(request.misc_ldo_state);

            pmic_get_misc_ldo_stat(req->type, &req->enable);
            break;
        }
        case PMIC_READ_REG:
        {
            pmic_read_reg_struct *req = &(request.read_reg);

            req->result = pmic_reg_read(req->register_index);
            break;
        }
        case PMIC_WRITE_REG:
        {
            pmic_write_reg_struct *req = &(request.write_reg);

            pmic_reg_write(req->data, req->register_index);
            break;
        }
        case PMIC_CHR_ENABLE:
        {
            pmic_chr_enable_struct *req = &(request.chr_enable);

            pmic_chr_enable(req->enable);
            break;
        }
        case PMIC_CHR_CURRENT_CTRL:
        {
            pmic_chr_current_control_struct *req = &(request.chr_current_control);

            pmic_charging_currnet_ctrl(req->chr_current);
            break;
        }
        case PMIC_USB_CHR_ENABLE:
        {
            pmic_usb_chr_enable_struct *req = &(request.usb_chr_enable);

            pmic_usb_chr_enable(req->enable);
            break;
        }
        case PMIC_LED_ENABLE:
        {
            pmic_led_enable_struct *req = &(request.led_enable);

            pmic_led_enable(req->type, req->enable);
            break;
        }
        case PMIC_LED_CONFIG:
        {
            pmic_led_config_struct *req = &(request.led_setting);

            pmic_led_config(&(req->led_conf));
            break;
        }
        case PMIC_RGB_DIM_CLK:
        {
            pmic_rgb_dim_clk_setting_struct *req = &(request.rgb_dim_clk_setting);

            pmic_rgb_dim_clk_setting(req->dim_clk);
            break;
        }
        case PMIC_CHR_PUMP_ENABLE:
        {
            pmic_chr_pump_enable_struct *req = &(request.chr_pump_enable);

            pmic_chr_pump_enable(req->enable);
            break;
        }
        case PMIC_CHR_PUMP_CURRENT:
        {
            pmic_chr_pump_current_struct *req = &(request.chr_pump_current_level);

            pmic_chr_pump_current_level(req->level);
            break;
        }
        case PMIC_BL_DIM_CLK:
        {
            pmic_bl_dim_clk_setting_struct *req = &(request.bl_dim_clk_setting);

            pmic_bl_dim_clk_setting((kal_uint32)req->dim_clk);
            break;
        }
        case PMIC_BL_DIV_BYPASS:
        {
            pmic_bl_div_bypass_enable_struct *req = &(request.bl_div_bypass_enable);

            pmic_bl_div_bypass(req->enable);
            break;
        }
        case PMIC_SPEAKER_ENABLE:
        {
            pmic_speaker_enable_struct *req = &(request.speaker_enable);

            pmic_speaker_enable(req->enable);
            break;
        }
        case PMIC_SPEAKER_GAIN:
        {
            pmic_speaker_gain_struct *req = &(request.speaker_gain);

            pmic_speaker_gain(req->gain);
            break;
        }
        case PMIC_VIBRATOR_ENABLE:
        {
            pmic_vibrator_enable_struct *req = &(request.vibrator_enable);

            pmic_vibrator_enable(req->enable);
            break;
        }
        case PMIC_VIBRATOR_SEL:
        {
            pmic_vibrator_sel_struct *req = &(request.vibrator_sel);

            pmic_vibrator_sel(req->value);
            break;
        }
        case PMIC_VMC_ENABLE:
        {
            pmic_vmc_enable_struct *req = &(request.vmc_enable);

            pmic_vmc_enable(req->enable);
            break;
        }
        case PMIC_VMC_SEL:
        {
            pmic_vmc_sel_struct *req = &(request.vmc_sel);

            pmic_vmc_sel(req->vmc_sel_value);
            break;
        }
        case PMIC_VASW_ENABLE:
        {
            pmic_vasw_enable_struct *req = &(request.vasw_enable);

            pmic_vasw_enable(req->enable);
            break;
        }
        case PMIC_VASW_SEL:
        {
            pmic_vasw_sel_struct *req = &(request.vasw_sel);

            pmic_sw_sel(req->value);
            break;
        }
        case PMIC_USB_REG_ENABLE:
        {
            pmic_usb_regulator_enable_struct *req = &(request.usb_reg_enable);

            pmic_usb_regulator_enable(req->enable);
            break;
        }
        case PMIC_VBAT_ENABLE:
        {
            pmic_vbat_enable_struct *req = &(request.vbat_enable);

            pmic_adc_measure_sel(req->enable);
            break;
        }
        case PMIC_ISENSE_ENABLE:
        {
            pmic_isense_enable_struct *req = &(request.isense_enable);

            pmic_adc_measure_sel(req->adc_value);
            break;
        }
        case PMIC_BL_PWM:
        {
            kal_mem_set(&cust_hw_level, 0, sizeof(custom_hw_level_struct));
            for (i = 0; i < PWM_MAX_LEVEL; i++)
            {
                cust_hw_level.PWM1[i][0] = PWM1_Level_Info[i][0];
                cust_hw_level.PWM1[i][1] = PWM1_Level_Info[i][1];

                cust_hw_level.PWM2[i][0] = PWM2_Level_Info[i][0];
                cust_hw_level.PWM2[i][1] = PWM2_Level_Info[i][1];

                cust_hw_level.PWM3[i][0] = Alter_Level_Info[i][0];
                cust_hw_level.PWM3[i][1] = Alter_Level_Info[i][1];

                cust_hw_level.PMIC6318BLPWM[i][0] = PMIC6318_PWM_Level_Info[i][0];
                cust_hw_level.PMIC6318BLPWM[i][1] = PMIC6318_PWM_Level_Info[i][1];
            }

            for (i = 0; i < LCD_CONTRAST_MAX_LEVEL; i++)
            {
                cust_hw_level.MainLCD_Contrast[i] = MainLCD_Contrast_Level_Info[i];

            #ifdef DUAL_LCD
                cust_hw_level.SubLCD_Contrast[i] = SubLCD_Contrast_Level_Info[i];
            #endif /* DUAL_LCD */ 
            }

            for (i = 0; i < LCD_PARAM_MAX_LEVEL; i++)
            {
                cust_hw_level.MainLCD_Bias[i] = MainLCD_Bias_Level_Info[i];
                cust_hw_level.MainLCD_Linerate[i] = MainLCD_Linerate_Level_Info[i];
                cust_hw_level.MainLCD_Temp[i] = MainLCD_Temp_Level_Info[i];

            #ifdef DUAL_LCD
                cust_hw_level.SubLCD_Bias[i] = SubLCD_Bias_Level_Info[i];
                cust_hw_level.SubLCD_Linerate[i] = SubLCD_Linerate_Level_Info[i];
                cust_hw_level.SubLCD_Temp[i] = SubLCD_Temp_Level_Info[i];
            #endif /* DUAL_LCD */ 
            }

            for (i = 0; i < BATTERY_MAX_LEVEL; i++)
            {
                cust_hw_level.BatteryLevel[i] = Battery_Level_Info[i];
            }

            if (uem_get_state() == UEM_STATE_READY)
            {
                g_uem_cntx_p->func_id = CGCI_SET + 12; /* strange func_id, only for check in write confirm msg */
                uem_send_msg_to_nvram(
                    MSG_ID_NVRAM_WRITE_REQ,
                    NVRAM_EF_CUST_HW_LEVEL_TBL_LID,
                    &cust_hw_level,
                    sizeof(custom_hw_level_struct));
            }
            break;
        }
        default:
            break;
    }

    l4cuem_pmic_config_cnf(src_id, request_type, request);
#else
    l4cuem_pmic_config_cnf(src_id, PMIC_MAX_NUM, request);
#endif /* defined(MT6318) */ 

}

/*****************************************************************************
*  Function 
*     l4cuem_battery_status_res_req
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_battery_status_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_battery_status_res_req(kal_uint8 status_type)
{
#if defined(PLUTO_MMI)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status_type)
    {
        case PMIC_USB_NO_CHARGER_OUT:
        case PMIC_USB_CHARGER_OUT:  /* USB Charger out */
        {
            /* set accessory state */
            FLAG_SET_OFF(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_USB_CHARGER))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_battery_status_ind(PMIC_USB_CHARGER_IN, g_uem_cntx_p->bmt_status.disp_level);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            break;
        }
        case PMIC_USB_NO_CHARGER_IN:
        case PMIC_USB_CHARGER_IN:   /* USB Charger in */
        {
            /* set accessory state */
            FLAG_SET_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_USB_CHARGER))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_battery_status_ind(PMIC_USB_CHARGER_OUT, g_uem_cntx_p->bmt_status.disp_level);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            break;
        }
        case PMIC_CHARGER_OUT:
        {
            /* set accessory state */
            FLAG_SET_OFF(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CHARGER);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_CHARGER))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_battery_status_ind(PMIC_CHARGER_IN, g_uem_cntx_p->bmt_status.disp_level);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);
            }
            break;
        }
        case PMIC_CHARGER_IN:   /* Charger plug in */
        {
            /* set accessory state */
            FLAG_SET_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CHARGER);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_CHARGER))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_battery_status_ind(PMIC_CHARGER_OUT, g_uem_cntx_p->bmt_status.disp_level);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);
            }
            break;
        }
    }
#endif /* defined(PLUTO_MMI) */ 
}

/*****************************************************************************
*  Function 
*     l4cuem_usbdetect_res_req
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_usbdetect_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_usbdetect_res_req(kal_uint8 action)
{
#if defined(PLUTO_MMI)
#ifdef __USB_ENABLE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action == DEVUSB_DETECT_ACTION_PLUGIN)
    {
        /* set accessory state */
        FLAG_SET_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB);
        /* Set not in progress */
        FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);

        /* check if prev state is matched with latest state */
        if (!is_status_matched(UEM_ACCESSORY_TYPE_USB))
        {
            /* not matched, Notify MMI with the latest statue */
            l4cuem_usbdetect_ind(DEVUSB_DETECT_ACTION_PLUGOUT);

            /* Set in progress */
            FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);
        }
    }
    else if (action == DEVUSB_DETECT_ACTION_PLUGOUT)
    {
        /* set accessory state */
        FLAG_SET_OFF(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB);
        /* Set not in progress */
        FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);

        /* check if prev state is matched with latest state */
        if (!is_status_matched(UEM_ACCESSORY_TYPE_USB))
        {
            /* not matched, Notify MMI with the latest statue */
            l4cuem_usbdetect_ind(DEVUSB_DETECT_ACTION_PLUGIN);

            /* Set in progress */
            FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);
        }
    }
#endif /* __USB_ENABLE__ */ 
#endif /* defined(PLUTO_MMI) */ 
}

/*****************************************************************************
*  Function 
*     l4cuem_em_dcm_enable_req
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_em_dcm_enable_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  enable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_em_dcm_enable_req(kal_bool enable)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(DCM_ENABLE)
    extern kal_uint8 uem_dcm_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        DCM_Enable(uem_dcm_handle);
    }
    else
    {
        DCM_Disable(uem_dcm_handle);
    }
#endif /* defined(DCM_ENABLE) */ 
#endif /* __MTK_TARGET__ */ 
}

/*****************************************************************************
*  Function 
*     l4cuem_em_uart_poweron_req
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_em_uart_poweron_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  uart_power_setting      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_em_uart_poweron_req(kal_uint8 uart_power_setting)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern kal_uint8 UART_POWER_SETTING;
    kal_bool enable;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    enable = UART_POWER_SETTING & (0x01 << uart_port1) ? KAL_TRUE : KAL_FALSE;
    UART_TurnOnPower(uart_port1, enable);

    enable = UART_POWER_SETTING & (0x01 << uart_port2) ? KAL_TRUE : KAL_FALSE;
    UART_TurnOnPower(uart_port2, enable);

    enable = UART_POWER_SETTING & (0x01 << uart_port3) ? KAL_TRUE : KAL_FALSE;
    UART_TurnOnPower(uart_port3, enable);
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
*	Function 
*		l4cuem_em_rf_test_gsm_req
*	DESCRIPTION
*		...
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void l4cuem_em_rf_test_gsm_req(kal_uint8 src_id, kal_uint8 request_type, rf_test_gsm_param_struct request)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__    
    switch(request_type)
    {
        case RF_TEST_GSM_STOP:
        {
            RFTool_GSM_Stop();
            break;		
        }
        case RF_TEST_GSM_TX_TEST:
        {
            rf_test_gsm_tx_test_struct *req = &(request.gsm_tx_test);
            
            RFTool_GSM_TxTest(req->band, req->arfcn, req->tsc, req->pcl, req->afc, req->pattern);
            break;
        }
        case RF_TEST_GSM_RX_TEST:
        {
            rf_test_gsm_rx_test_struct *req = &(request.gsm_rx_test);

            RFTool_GSM_RxTest(req->band, req->arfcn, req->gain, req->pattern);
            break;
        }
        case RF_TEST_GSM_POWER_SCAN:
        {
            rf_test_gsm_power_scan_struct *req = &(request.gsm_power_scan);
            
            RFTool_GSM_PowerScan(req->band, req->arfcn_in, uemdrv_rf_test_gsm_powerscan_callback);       
            return;
            
            break;
        }        
        default:
            break;
    }
#endif /* #ifdef __MTK_TARGET__ */

    l4cuem_rf_test_gsm_cnf(src_id, request_type, request);
}


/*****************************************************************************
*	Function 
*		l4cuem_em_rf_test_wifi_req
*	DESCRIPTION
*		...
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void l4cuem_em_rf_test_wifi_req(kal_uint8 src_id, kal_uint8 request_type, rf_test_wifi_param_struct request)
{
#if defined(__WIFI_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(request_type)
    {
        case RF_TEST_WIFI_STOP:
        {
            RFTool_WiFi_Stop();
            break;		
        }
        case RF_TEST_WIFI_TEST_MODE:
        {
            RFTool_WiFi_EnterTestMode();
            break;		
        }
        case RF_TEST_WIFI_NORMAL_MODE:
        {
            RFTool_WiFi_EnterNormalMode();
            break;
        }
        case RF_TEST_WIFI_TX_GET_DAC_OFFSET:
        {
            RFTool_WiFi_DacDCOffset(&(request.wifi_get_dac.ich), &(request.wifi_get_dac.qch));
            break;
        }        
        case RF_TEST_WIFI_TX_OUTPUT_POWER:
        {
            rf_test_wifi_tx_common_struct *req = &(request.wifi_tx_common);
            wndrv_test_tx_struct contx_tx;

            contx_tx.ch_freq = req->ch_freq;
            contx_tx.tx_rate = req->tx_rate;
            contx_tx.txAnt = req->tx_ant;
            contx_tx.tx_gain_dac = req->gain;

            RFTool_WiFi_ContTx(req->contry_code, contx_tx);
            
            break;
        }         
        case RF_TEST_WIFI_TX_CARRIER_SUPP:
        {
            rf_test_wifi_tx_common_struct *req = &(request.wifi_tx_common);
            wndrv_test_tx_struct carrier_supp;

            carrier_supp.ch_freq = req->ch_freq;
            carrier_supp.tx_rate = req->tx_rate;
            carrier_supp.txAnt = req->tx_ant;
            carrier_supp.tx_gain_dac = req->gain;
            
            RFTool_WiFi_CarrierSupp(req->contry_code, carrier_supp);
            break;
        }
        case RF_TEST_WIFI_TX_LOCAL_FREQ:
        {
            rf_test_wifi_tx_common_struct *req = &(request.wifi_tx_common);
            wndrv_test_tx_struct local_freq;

            local_freq.ch_freq = req->ch_freq;
            local_freq.tx_rate = req->tx_rate;
            local_freq.txAnt = req->tx_ant;
            local_freq.tx_gain_dac = req->gain;

            RFTool_WiFi_LocalFreq(req->contry_code, local_freq);
            break;
        }
        case RF_TEST_WIFI_TX_CONT_PKT:
        {
            rf_test_wifi_tx_cont_pkt_struct *req = &(request.wifi_tx_cont_pkt);
            wndrv_test_pkt_tx_struct cont_tx;
            kal_uint8 i;

            cont_tx.ch_freq = req->ch_freq;
            cont_tx.tx_rate = req->tx_rate;
            cont_tx.txAnt = req->tx_ant;
            cont_tx.tx_gain_dac = req->gain;
            cont_tx.pktCount = req->pkt_count;
            cont_tx.pktInterval = req->pkt_interval;
            cont_tx.pktLength = req->pkt_length;
            cont_tx.pattern = req->tx_pattern;
            cont_tx.is_short_preamble = req->short_peramble;

            for (i=0 ; i<24; i++)
                cont_tx.mac_header[i] = req->mac_header[i];
             
            RFTool_WiFi_PktTx(req->contry_code, cont_tx);
            break;
        }
        case RF_TEST_WIFI_RX_CONT_PKT:
        {
            rf_test_wifi_rx_cont_pkt_struct *req = &(request.wifi_rx_cont_pkt);

            g_uem_cntx_p->src_id = src_id;
           
            RFTool_WiFi_PktRx(req->ch_freq,  uemdrv_rf_test_wifi_rx_pkt_callback);       

            return;
            
            break;
        }
        case RF_TEST_WIFI_POWER_SAVE:
        {
            rf_test_wifi_power_save_struct *req = &(request.wifi_power_save);

            RFTool_WiFi_PwrMgt(req->pwr_mgt);        
            break;
        }        
        case RF_TEST_WIFI_REG_MCR32_WRITE:
        {
            rf_test_wifi_reg_mcr32_write_struct *req = &(request.wifi_mcr32_write);

            RFTool_WiFi_MCR32_Write(req->mcr_index, req->mcr32);        
            break;
        }        
        case RF_TEST_WIFI_REG_MCR32_READ:
        {
            rf_test_wifi_reg_mcr32_read_struct *req = &(request.wifi_mcr32_read);

            RFTool_WiFi_MCR32_Read(req->mcr_index, &(request.wifi_mcr32_read.mcr32));        

            break;
        }
        case RF_TEST_WIFI_REG_MCR16_WRITE:
        {
            rf_test_wifi_reg_mcr16_write_struct *req = &(request.wifi_mcr16_write);

            RFTool_WiFi_MCR16_Write (req->mcr_index, req->mcr16);              
            break;
        }
        case RF_TEST_WIFI_REG_MCR16_READ:
        {
            rf_test_wifi_reg_mcr16_read_struct *req = &(request.wifi_mcr16_read);

            RFTool_WiFi_MCR16_Read(req->mcr_index, &(request.wifi_mcr16_read.mcr16));  
            break;
        }
        case RF_TEST_WIFI_REG_BBCR_WRITE:
        {
            rf_test_wifi_reg_bbcr_write_struct *req = &(request.wifi_bbcr_write);

            RFTool_WiFi_BBCR_Write(req->bbcr_index, req->bbcr);               
            break;
        }
        case RF_TEST_WIFI_REG_BBCR_READ:
        {
            rf_test_wifi_reg_bbcr_read_struct *req = &(request.wifi_bbcr_read);

            RFTool_WiFi_BBCR_Read(req->bbcr_index, &(request.wifi_bbcr_read.bbcr));   
            break;
        }
        case RF_TEST_WIFI_REG_EEPROM_WRITE:
        {
            rf_test_wifi_reg_eeprom_write_struct *req = &(request.wifi_eeprom_write);

            RFTool_WiFi_EEPROM_Write(req->eeprom_index, req->eeprom);       
            break;
        }
        case RF_TEST_WIFI_REG_EEPROM_READ: 
        {
            rf_test_wifi_reg_eeprom_read_struct *req = &(request.wifi_eeprom_read);

            RFTool_WiFi_EEPROM_Read(req->eeprom_index, &(request.wifi_eeprom_read.eeprom));       
            break;
        }    
        default:
            break;
    }

    l4cuem_rf_test_wifi_cnf(src_id, request_type, request);
#endif  /* #if defined(__WIFI_SUPPORT__) */	
}


/*****************************************************************************
*	Function 
*		l4cuem_em_fm_radio_config_req
*	DESCRIPTION
*		...
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void l4cuem_em_fm_radio_config_req(kal_uint8 src_id, kal_uint8 request_type, fm_radio_config_param_struct request)
{
#ifdef FM_RADIO_ENABLE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(request_type)
    {
        case FM_RADIO_CMD_MONO:
        {
            fm_radio_mono_struct *req = &(request.fm_radio_mono);
            FMR_Radio_EngineerMode((kal_uint16)request_type, 0 , (kal_uint32)req->mono_enable);
            break;		
        }
        case FM_RADIO_CMD_STEREO:
        {
            fm_radio_stereo_struct *req = &(request.fm_radio_stereo);
            FMR_Radio_EngineerMode((kal_uint16)request_type, (kal_uint16)req->sblend_onoff , (kal_uint32)req->stereo_enable);
            break;
        }
        case FM_RADIO_CMD_RSSI:
        {
            fm_radio_rssi_struct *req = &(request.fm_radio_rssi);
            FMR_Radio_EngineerMode((kal_uint16)request_type, 0 , (kal_uint32)req->level);
            break;
        }
        case FM_RADIO_CMD_IF_COUNT:
        {
            fm_radio_if_count_delta_struct *req = &(request.fm_radio_if);
            FMR_Radio_EngineerMode((kal_uint16)request_type, 0 , (kal_uint32)req->item_value);       
            break;
        }        
        default:
            break;
    }

    l4cuem_fm_radio_config_cnf(src_id, request_type, request);
    
#endif /* #ifdef FM_RADIO_ENABLE */
}

/*****************************************************************************
*	Function 
*		l4cuem_em_fm_radio_config_req
*	DESCRIPTION
*		...
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void l4cuem_startup_cnf_rsp(void)
{
#ifdef PLUTO_MMI

#endif /* PLUTO_MMI */ 
}


/*****************************************************************************
 * FUNCTION
 *  l4cuem_gpio_detect_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_gpio_detect_res_req(kal_uint8 ext_gpio_device)
{
#if defined(PLUTO_MMI)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ext_gpio_device)
    {
        case EXT_DEV_CLAM_CLOSE:  /* Clam Close */
        {
            /* set accessory state */
            FLAG_SET_OFF(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CLAM);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_CLAM))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_gpio_detect_ind(EXT_DEV_CLAM_OPEN, KAL_TRUE);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);
            }
            break;
        }
        case EXT_DEV_CLAM_OPEN:   /* Clam Open */
        {
            /* set accessory state */
            FLAG_SET_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CLAM);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_CLAM))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_gpio_detect_ind(EXT_DEV_CLAM_CLOSE, KAL_TRUE);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);
            }
            break;
        }
        default:
            break;
    }
#endif /* defined(PLUTO_MMI) */ 
}
