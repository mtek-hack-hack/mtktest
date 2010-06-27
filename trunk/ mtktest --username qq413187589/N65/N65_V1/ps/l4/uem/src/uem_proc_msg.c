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
 * UEM_PROC_MSG.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4C<-UEM message using.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "kal_trace.h"
#include "stdio.h"
#include "kal_non_specific_general_types.h"
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "stack_timer.h"
#include "event_shed.h"
#include "med_struct.h"

#include "l1audio.h"
#include "drvsignals.h"
#include "keypad_sw.h"
#include "aud_defs.h"
#include "bmt.h"
#include "adc.h"
#include "Rtc_sw.h"
#include "pwic.h"
#include "device.h"
#include "pwm_sw.h"

#include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#include "l4c2uem_struct.h"
#include "l4c_eq_msg.h"

#include "uem_context.h"
#include "uem_utility.h"
#include "uem_main.h"
#include "uem_proc_msg.h"
#include "uem_trc.h"

#include "custom_equipment.h"
#include "custom_hw_default.h"

#if defined (__WIFI_SUPPORT__)
#include "wndrv_cnst.h"
#include "wndrv_ft_types.h"
#endif

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Global/Extern Function
*****************************************************************************/
extern void MMICheckDiskDisplay(void);

#ifdef __MTK_TARGET__
extern DRV_RESET(void);
extern kal_uint8 adc_sche_create_object(
                    module_type ownerid,
                    kal_uint8 adc_channel,
                    kal_uint32 period,
                    kal_uint8 evaluate_count,
                    kal_bool send_primitive);
#endif /* __MTK_TARGET__ */ 

#ifdef __USB_ENABLE__
extern void l4cuem_usbconfig_cnf(kal_uint8 src_id, kal_bool result, kal_uint8 mode, kal_uint32 reserved);
#endif 

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void uem_pmic_power_on_if_needed(kal_uint8 vbat_level);

/******************************************************************************/
/*******************   External Functions *************************************/
/******************************************************************************/
/*****************************************************************************
*   Function 
*      uemdrv_keypad_detect_ind
*   DESCRIPTION
*      The function is used to detect the user pressed or released keypad. 
*      The Driver will callback the function that the keypad is pressed or released and 
*      given the pressed or released key code value.
*   PARAMETERS
*      keypad_status   IN
*      keypad_code      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_keypad_detect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_get_key_func        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_keypad_detect_ind(kal_bool(*drv_get_key_func) (kbd_data *))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l4cuem_keypad_detect_ind(drv_get_key_func);
}

/*****************************************************************************
*   Function 
*      uemdrv_alarm_detect_ind
*   DESCRIPTION
*      The function is used to detect the alarm time is up at power off point. 
*      The Driver will callback the function that the alarm is startup.
*   PARAMETERS
*      alarm_status   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_alarm_detect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_alarm_detect_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;
    kal_uint8 poweron_mode = uem_get_poweron_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_ALARM_DETECT);

    /* this is alarm power on case */
    uem_get_bat_status(&bmt_status);

    RTC_Config(uem_rtc_alarm_format_convert(DEVICE_AL_EN_None), uem_rtc_clock_format_convert(DEVICE_TC_EN_NoChange));

    if (POWERON(poweron_mode))
    {
        t_rtc lrtc;
        rtc_format_struct rtc_time;

        RTC_GetTime(&lrtc);
        rtc_time.rtc_day = lrtc.rtc_day;
        rtc_time.rtc_hour = lrtc.rtc_hour;
        rtc_time.rtc_min = lrtc.rtc_min;
        rtc_time.rtc_sec = lrtc.rtc_sec;
        rtc_time.rtc_year = lrtc.rtc_year;
        rtc_time.rtc_mon = lrtc.rtc_mon;
        rtc_time.rtc_wday = lrtc.rtc_wday;

        l4cuem_alarm_detect_ind(&rtc_time);
    }
}

/*****************************************************************************
*   Function 
*      uemdrv_rtc_period_ind
*   DESCRIPTION
*      The function is used to detect the RTC period time with one minute timer. 
*      The Driver will callback the function that the RTC within the specific time to 
*      generate RTC alarm interrupt.
*   PARAMETERS
*      rtc_type   IN/OUT   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_rtc_period_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_rtc_period_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    t_rtc lrtc;
    rtc_format_struct rtc_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_PERIOD);

    RTC_GetTime(&lrtc);

    rtc_time.rtc_day = lrtc.rtc_day;
    rtc_time.rtc_hour = lrtc.rtc_hour;
    rtc_time.rtc_min = lrtc.rtc_min;
    rtc_time.rtc_sec = lrtc.rtc_sec;
    rtc_time.rtc_year = lrtc.rtc_year;
    rtc_time.rtc_mon = lrtc.rtc_mon;
    rtc_time.rtc_wday = lrtc.rtc_wday;

    /* execute the callback function */
    l4cuem_rtc_period_ind(RTC_TIME_CLOCK_IND, &rtc_time);
}

/*****************************************************************************
*   Function 
*      uemdrv_keypad_power_on_ind
*   DESCRIPTION
*      The function is used to keypad power on.
*   PARAMETERS
*      void
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_keypad_power_on_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_keypad_power_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_KEYPAD_POWER_ON);

    /* set power on flag */
    uem_set_poweron_mode(POWER_ON_KEYPAD);
    uem_get_bat_status(&bmt_status);

    l4cuem_power_on_ind(POWER_ON_KEYPAD, uem_vbat_level_convert(bmt_status.volt));

    return;
}

/*****************************************************************************
*   Function 
*      uemdrv_exception_power_on_ind
*   DESCRIPTION
*      The function is used to excetption reboot.
*   PARAMETERS
*      void
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_exception_power_on_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_exception_power_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_set_poweron_mode(POWER_ON_EXCEPTION);
    uem_get_bat_status(&bmt_status);
    l4cuem_power_on_ind(POWER_ON_EXCEPTION, uem_vbat_level_convert(bmt_status.volt));
    return;
}

/*****************************************************************************
*   Function 
*      uemdrv_pmic_ind
*   DESCRIPTION
*      The function is used to notify the battery status from PMIC driver.
*   PARAMETERS
*      alarm_status   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_pmic_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_pmic_ind(kal_uint8 status_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;
    kal_uint8 vbat_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_PMIC_DETECT);
    /* reserve future to call back with message while the BMT indication notify */

    uem_get_bat_status(&bmt_status);

    if (status_type == PMIC_VBAT_STATUS)
    {
        vbat_level = custom_cfg_vbat_level_regulator(
                        bmt_status.volt,
                        &(g_uem_cntx_p->bmt_status.last_level),
                        &(g_uem_cntx_p->bmt_status.disp_level),
                        &(g_uem_cntx_p->bmt_status.hit_count));
    }
    else
    {
        vbat_level = g_uem_cntx_p->bmt_status.disp_level;
    }

    kal_prompt_trace(
        MOD_UEM,
        "[BAT_LV: %u] [BMT status:%d volt:%d last:%d disp:%d cnt:%d]",
        vbat_level,
        bmt_status.status,
        bmt_status.volt,
        g_uem_cntx_p->bmt_status.last_level,
        g_uem_cntx_p->bmt_status.disp_level,
        g_uem_cntx_p->bmt_status.hit_count);

    switch (status_type)
    {
        case PMIC_VBAT_STATUS:          /* Notify the battery voltage, pass */
        case PMIC_OVERVOLPROTECT:       /* The voltage of battery is too high, pass */
        case PMIC_OVERBATTEMP:          /* The temperature of battery is too high, pass */
        case PMIC_LOWBATTEMP:           /* The temperature of battery is too low, pass */
        case PMIC_OVERCHARGECURRENT:    /* Charge current is too large, pass */
        case PMIC_LOWCHARGECURRENT:     /* Charge current is too large, pass */
        case PMIC_CHARGE_COMPLETE:      /* Charge is completed, pass */
        case PMIC_INVALID_BATTERY:      /* invalid battery, pass */
        case PMIC_INVALID_CHARGER:      /* invalid charger, pass */
        case PMIC_CHARGING_TIMEOUT:     /* Bad battery, pass */
        case PMIC_CHARGE_BAD_CONTACT:   /* Charger Bad Contact, pass */
        case PMIC_BATTERY_BAD_CONTACT:  /* Battery Bad Contact, pass */
            l4cuem_battery_status_ind(status_type, vbat_level);
            break;

        case PMIC_USB_NO_CHARGER_OUT:   /* pass */
        case PMIC_USB_CHARGER_OUT:      /* USB Charger out */
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is IN && it is not in progress */
            if (FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER))
            {
                l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            /* update the latest status */
            FLAG_SET_OFF(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB_CHARGER);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
        #endif /* defined(PLUTO_MMI) */ 

            break;
        }
        case PMIC_USB_NO_CHARGER_IN:    /* pass */
        {
        #if defined(PLUTO_MMI)
            if (!FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER))
            {
                l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            else if (g_uem_cntx_p->is_usb_charing == KAL_TRUE)
            {
               l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */
            }

            g_uem_cntx_p->is_usb_charing = KAL_FALSE;
            
            /* update the latest status */
            FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB_CHARGER);

            uem_pmic_power_on_if_needed(vbat_level);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
            uem_pmic_power_on_if_needed(vbat_level);
        #endif /* defined(PLUTO_MMI) */ 
            break;
        }
        case PMIC_USB_CHARGER_IN:       /* USB Charger in */
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is OUT && it is not in progress */
            if (!FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER))
            {

                l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            else if (g_uem_cntx_p->is_usb_charing == KAL_FALSE)
            {
               l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */
            }

            g_uem_cntx_p->is_usb_charing = KAL_TRUE;
            
            /* update the latest status */
            FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB_CHARGER);

            uem_pmic_power_on_if_needed(vbat_level);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
            uem_pmic_power_on_if_needed(vbat_level);
        #endif /* defined(PLUTO_MMI) */ 
            break;
        }

        case PMIC_CHARGER_OUT:
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is IN && it is not in progress */
            if (FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER))
            {
                l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);
            }
            /* update the latest status */
            FLAG_SET_OFF(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CHARGER);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
        #endif /* defined(PLUTO_MMI) */ 

            break;
        }

        case PMIC_CHARGER_IN:   /* Charger plug in */
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is OUT && it is not in progress */
            if (!FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER))
            {
                /* Always send charger-in indication to avoid fast repeating charger in-out b4 power-on completes */
                l4cuem_battery_status_ind(status_type, vbat_level);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);
            }

            /* update the latest status */
            FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CHARGER);

            uem_pmic_power_on_if_needed(vbat_level);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
            uem_pmic_power_on_if_needed(vbat_level);
        #endif /* defined(PLUTO_MMI) */ 
            break;

        }

        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      uemdrv_gpio_detect_ind
*   DESCRIPTION
*      The function is used to detect the GPIO device including hand-free, and earphone. 
*      When the driver detect any earphone is plugged in, it will callback this function 
*      to notify MMI, if the driver detect the earphone is plugged out, it will callback 
*      this function to notify MMI too.
*   PARAMETERS
*      gpio_device      IN
*     on_off         IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_gpio_detect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ext_gpio_device     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_gpio_detect_ind(kal_uint8 ext_gpio_device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GPIO_DETECT);

    /* the gpio plug in */
    switch (ext_gpio_device)
    {
        case EXT_DEV_NONE:
        {
            /* set output path, audio_mode has been change at uemdrv_aux_id_hdlr() */
            uem_send_msg_to_aud(MSG_ID_L4AUD_GPIO_DETECT_IND, (kal_uint32) ext_gpio_device);
            l4cuem_gpio_detect_ind(g_uem_cntx_p->ext_dev_status, KAL_FALSE);
            g_uem_cntx_p->ext_dev_status = EXT_DEV_NONE;
            /* l4cuem_gpio_detect_ind(EXT_DEV_NONE, KAL_FALSE); */
            break;
        }

        case EXT_DEV_HANDFREE:
        case EXT_DEV_EARPHONE:
        case EXT_DEV_CARKIT:
        {
            g_uem_cntx_p->ext_dev_status = ext_gpio_device;
            /* set output path, audio_mode has been change at uemdrv_aux_id_hdlr() */
            uem_send_msg_to_aud(MSG_ID_L4AUD_GPIO_DETECT_IND, (kal_uint32) ext_gpio_device);
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
            break;
        }
        case EXT_DEV_UART:
        {
            /* Only accessory plug in/out change context */
            g_uem_cntx_p->ext_dev_status = ext_gpio_device;
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
            break;
        }
        case EXT_DEV_KEY_1:
        case EXT_DEV_KEY_2:
        {
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
            break;
        }
        case EXT_DEV_CLAM_OPEN:
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is IN && it is not in progress */
            if (!FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CLAM) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM))
            {
                l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);
            }
            /* update the latest status */
            FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CLAM);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
        #endif
            break;
        }
        case EXT_DEV_CLAM_CLOSE:
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is IN && it is not in progress */
            if (FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CLAM) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM))
            {
                l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);
            }
            /* update the latest status */
            FLAG_SET_OFF(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CLAM);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
        #endif
            break;
        }
        default:
            break;
    }
}

/*****************************************************************************
*  Function 
*     uemdrv_audio_play_finish_ind
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
 *  uemdrv_audio_play_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  identifier      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_audio_play_finish_ind(kal_uint8 result, kal_uint16 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l4cuem_audio_play_finish_ind(result, identifier);
}

#ifdef __USB_ENABLE__
/*****************************************************************************
*  Function 
*     uemdrv_usb_power_on_ind
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
 *  uemdrv_usb_power_on_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_usb_power_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_set_poweron_mode(POWER_ON_USB);

   /***  2004/05/28 Robin
     *   Postpone latch power to uemdrv_usb_detect_ind() because driver will send power on indication
     * before SW debounce time finish. If user plug out usb device during the SW debounce time,
     * driver will not send out USB_DETECT_IND/plugout so wil not able to  power off
   ***/
#ifndef __NVRAM_IN_USB_MS__
    l4cuem_usb_power_on_ind();
#endif 
    return;
}

/*****************************************************************************
*  Function 
*     uemdrv_usb_detect_ind
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
 *  uemdrv_usb_detect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_usb_detect_ind(kal_uint8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action == DEVUSB_DETECT_ACTION_PLUGOUT)
    {
    #ifndef __NVRAM_IN_USB_MS__
        if (uem_get_poweron_mode() == POWER_ON_USB)
        {
            DRV_POWEROFF();
        #if (defined(MT6318) || defined(MT6305))
            DRV_RESET();
        #endif 
            return;
        }
    #endif /* __NVRAM_IN_USB_MS__ */ 

        if ((uem_get_poweron_mode() == POWER_ON_USB) &&(uem_get_state() != UEM_STATE_READY))
        {
            DRV_POWEROFF();
        #if (defined(MT6318) || defined(MT6305))
            DRV_RESET();
        #endif 
            return;
        }

    #if (defined(__USB_IN_NORMAL_MODE__) || defined(PICTBRIDGE_SUPPORT)) && defined (APPMEM_SUPPORT)
        if (uem_normal_ms_buffer)
        {
            kal_app_mem_free(uem_normal_ms_buffer);
            uem_normal_ms_buffer = NULL;
        }
    #endif /* (defined(__USB_IN_NORMAL_MODE__) || defined(PICTBRIDGE_SUPPORT) ) && defined (APPMEM_SUPPORT) */ 
    }
#ifndef __NVRAM_IN_USB_MS__
    else if ((action == DEVUSB_DETECT_ACTION_PLUGIN) && (uem_get_poweron_mode() == POWER_ON_USB))
    {
        DRV_POWERON();
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

#if defined(PLUTO_MMI)
    if (action == DEVUSB_DETECT_ACTION_PLUGOUT)
    {
        /* check if the accessory prev state is IN && it is not in progress */
        if (FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB) &&
            !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB))
        {
            l4cuem_usbdetect_ind(action);   /* Notify MMI */

            /* Set in progress */
            FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);
        }
        /* update the latest status */
        FLAG_SET_OFF(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB);
    }
    else if (action == DEVUSB_DETECT_ACTION_PLUGIN)
    {
        /* check if the accessory prev state is OUT && it is not in progress */
        if (!FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB) &&
            !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB))
        {
            l4cuem_usbdetect_ind(action);   /* Notify MMI */

            /* Set in progress */
            FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);
        }
        /* update the latest status */
        FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB);
    }
#else /* defined(PLUTO_MMI) */ 
    l4cuem_usbdetect_ind(action);
#endif /* defined(PLUTO_MMI) */ 

    return;
}

/*****************************************************************************
*  Function 
*     uemdrv_usb_config_cnf
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
 *  uemdrv_usb_config_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode            [IN]        
 *  result          [IN]        
 *  reserved        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_usb_config_cnf(kal_uint8 mode, kal_bool result, kal_uint32 reserved)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l4cuem_usbconfig_cnf(g_uem_cntx_p->usb_msg_src_id, result, mode, reserved);
    return;
}
#endif /* __USB_ENABLE__ */ 

/*****************************************************************************
*  Function 
*     uemdrv_prechr_power_on_ind
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
 *  uemdrv_prechr_power_on_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_prechr_power_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    /* show the logo */
    MMICheckDiskDisplay();

    /* Turn on backlight after the picture is shown */
    custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, 5);
#endif /* !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) */ 

    uem_get_bat_status(&bmt_status);
    uem_set_poweron_mode(POWER_ON_PRECHARGE);
    l4cuem_power_on_ind(POWER_ON_PRECHARGE, uem_vbat_level_convert(bmt_status.volt));
}

/*****************************************************************************
*  Function 
*     uemdrv_get_hw_level_pwm_info_req
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
 *  uemdrv_get_hw_level_pwm_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  level       [IN]        
 *  info1       [?]         
 *  info2       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_get_hw_level_pwm_info_req(kal_uint8 type, kal_uint8 level, kal_uint8 *info1, kal_uint8 *info2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case PWM1:
            *info1 = PWM1_Level_Info[level - 1][0];
            *info2 = PWM1_Level_Info[level - 1][1];
            break;
        case PWM2:
            *info1 = PWM2_Level_Info[level - 1][0];
            *info2 = PWM2_Level_Info[level - 1][1];
            break;
        default:
            break;
    }
}

/*****************************************************************************
*  Function 
*     uemdrv_get_hw_level_alter_info_req
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
 *  uemdrv_get_hw_level_alter_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  level       [IN]        
 *  info1       [?]         
 *  info2       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_get_hw_level_alter_info_req(kal_uint8 level, kal_uint8 *info1, kal_uint8 *info2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *info1 = Alter_Level_Info[level - 1][0];
    *info2 = Alter_Level_Info[level - 1][1];
}

/*****************************************************************************
*   Function 
*      uem_poweron_timer_expiry_hdlr
*   DESCRIPTION
*      handle the power on timer expire
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_poweron_timer_expiry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_poweron_timer_expiry_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_stop_timer(PWN_EVENT_TIMER);

    /* Latch power and do the rest */
    DRV_POWERON();

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    /* show the logo */
    MMICheckDiskDisplay();

    /* Turn on backlight after the picture is shown */
    custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, 5);
#endif /* !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) */ 

#if defined(MT6223P)
     FS_LockFAT(FS_CARD_BUSY_NONBLOCK_ENUM);
#endif

#if !defined(__FS_CHECKDRIVE_SUPPORT__) && !defined(_LOW_COST_SINGLE_BANK_FLASH_)
    /* Before this point, releasing power key does not consider as "abnormal poweroff" */
    FS_SetDiskFlag();
#endif /* !defined(__FS_CHECKDRIVE_SUPPORT__) && !defined(_LOW_COST_SINGLE_BANK_FLASH_) */ 

    /* send message to L4/MMI */
    uemdrv_keypad_power_on_ind();
}

/*****************************************************************************
*   Function 
*      uem_poweron_timer_start
*   DESCRIPTION
*      start a timer to t
*   PARAMETERS
*     time left to power on
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_poweron_timer_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time_in_ms      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_poweron_timer_start(kal_uint32 time_in_ms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_start_timer(PWN_EVENT_TIMER, uem_poweron_timer_expiry_hdlr, time_in_ms);
}

/***************************************************************************** 
****************************************************************************** 
* Local Funcations 
******************************************************************************
*****************************************************************************/
/*****************************************************************************
*  Function 
*     uem_pmic_power_on_if_needed
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
 *  uem_pmic_power_on_if_needed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vbat_level      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void uem_pmic_power_on_if_needed(kal_uint8 vbat_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 poweron_mode = uem_get_poweron_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (uem_get_state() < UEM_STATE_STARTUP)    /* to avoid startup twice */
    {
        if ((poweron_mode == POWER_ON_CHARGER_IN) || (poweron_mode == POWER_ON_USB))
        {
        #ifdef __MTK_TARGET__
            if (g_uem_cntx_p->adc_sche_id == 0)
            {
                g_uem_cntx_p->adc_sche_id = adc_sche_create_object(
                                                MOD_UEM,
                                                ADC_VBAT,
                                                ADC_BOOTUP_EVAL_PERIOD,
                                                (kal_uint8) ADC_BOOTUP_EVAL_COUNT,
                                                KAL_TRUE);
                uem_send_msg_to_bmt(MSG_ID_BMT_ADC_ADD_ITEM_REQ, g_uem_cntx_p->adc_sche_id);
            }
        #endif /* __MTK_TARGET__ */ 

            DRV_POWERON();
            l4cuem_power_on_ind(poweron_mode, vbat_level);
        }
    }
}


/*****************************************************************************
*	Function 
*		uemdrv_rf_test_gsm_powerscan_callback
*	DESCRIPTION
*		callback function for RF Test GSM
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void uemdrv_rf_test_gsm_powerscan_callback(kal_int16 *arfcn, kal_int16 *power)
{
    kal_uint8 i;
    rf_test_gsm_param_struct request={0};

    for (i=0; i<20; i++)
    {
        request.gsm_power_scan.arfcn_out[i] = arfcn[i];
        request.gsm_power_scan.power[i] = power[i];
    }
     
    l4cuem_rf_test_gsm_cnf(g_uem_cntx_p->src_id , RF_TEST_GSM_POWER_SCAN, request);
}

#if defined(__WIFI_SUPPORT__)
/*****************************************************************************
*	Function 
*		uemdrv_rf_test_wifi_rx_pkt_callback
*	DESCRIPTION
*		callback function for RF Test Wifi
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void uemdrv_rf_test_wifi_rx_pkt_callback(wndrv_test_rx_status_struct* result)
{
    rf_test_wifi_param_struct request={0};

    request.wifi_rx_cont_pkt.pau_total = result->pau_rx_pkt_count;
    request.wifi_rx_cont_pkt.pau_err = result->pau_crc_err_count;
    request.wifi_rx_cont_pkt.pau_ccca = result->pau_cca_count;
    request.wifi_rx_cont_pkt.pau_fifo_full = result->pau_rx_fifo_full_count;
    request.wifi_rx_cont_pkt.int_ok = result->int_rx_ok_num;
    request.wifi_rx_cont_pkt.int_err = result->int_crc_err_num;
    request.wifi_rx_cont_pkt.rssi_mean = result->int_rssi_mean;
    request.wifi_rx_cont_pkt.rssi_max = result->int_rssi_max;
    request.wifi_rx_cont_pkt.rssi_min = result->int_rssi_min;
    request.wifi_rx_cont_pkt.rssi_variance = result->int_rssi_variance;
    request.wifi_rx_cont_pkt.int_long_preamble = result->int_long_preamble_num;
    request.wifi_rx_cont_pkt.int_short_preamble = result->int_short_preamble_num;
     
    l4cuem_rf_test_wifi_cnf(g_uem_cntx_p->src_id , RF_TEST_WIFI_RX_CONT_PKT, request);
}
#endif /* defined(__WIFI_SUPPORT__) */

