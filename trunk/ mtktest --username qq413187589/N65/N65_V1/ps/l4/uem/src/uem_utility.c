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
 * UEM_UTILITY.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for UEM utility.
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
#include "app_buff_alloc.h"
#include "stdarg.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "stack_timer.h"
#include "event_shed.h"

#include "kal_trace.h"
#include "uem_trc.h"

#include "l1audio.h"
#include "rtc_sw.h"
#include "device.h"
#include "drvsignals.h"
#include "keypad_sw.h"

#include "em_struct.h"
#include "ps2sat_struct.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "usb_msdisk.h"

#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#endif 

#ifdef __USB_ENABLE__
#include "usb_comm.h"
#endif 

#include "nvram_data_items.h"
#include "nvram.h"
#include "nvram_user_defs.h"
#include "nvram_editor_data_item.h"
#include "nvram_interface.h"

#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"

#include "l4c2uem_struct.h"
#include "l4c_rspfmttr.h"
#include "l4c_common_enum.h"
#include "l3_inc_struct.h"
#include "l4c_utility.h"

#include "uem_context.h"
#include "uem_main.h"
#include "uem_utility.h"
#include "uem_msg_hdlr.h"
#include "uem_proc_cmd.h"

#ifdef __GEMINI__
#include  "sim_common_enums.h"
#endif /* __GEMINI__ */

/***************************************************************************** 
* Extern Functions
*****************************************************************************/
extern kal_uint32 custom_cfg_vbat_percentage_convert(kal_uint32 vbat);

/***************************************************************************** 
* Define the audio device mute status
*****************************************************************************/
#define AUDIO_MUTE_SPEAKER          0x01
#define AUDIO_MUTE_MICROPHONE       0x02
#define AUDIO_MUTE_SPEAKER2         0x04
#define AUDIO_MUTE_LOUDSPEAKER      0x08

/***************************************************************************** 
* Local Variables Declaration
*****************************************************************************/
static const kal_uint8 undef_equip_str[MAX_ME_ID_LEN] = "undefined message";

/***************************************************************************** 
* Global Variables Declaration
*****************************************************************************/
UEM_TIMER_EVENTS uem_timer_table[MAX_UEM_EVENT_TIMER];
stack_timer_struct uem_base_timer;
event_scheduler *event_scheduler_uem_ptr;

#if defined(__USB_IN_NORMAL_MODE__) || defined(PICTBRIDGE_SUPPORT)
kal_uint8 uem_normal_ms_buffer[USBMS_MAX_BUFFERSIZE];
#endif /* defined(__USB_IN_NORMAL_MODE__) || defined(PICTBRIDGE_SUPPORT) */ 

/***************************************************************************** 
****************************************************************************** 
* External Funcations 
******************************************************************************
******************************************************************************/
/*****************************************************************************
*   Function 
*      uem_rtc_alarm_format_convert
*   DESCRIPTION
*      Rtc alarm format convert
*   PARAMETERS
*
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_rtc_alarm_format_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_alarm_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem_rtc_alarm_format_convert(rtc_alarm_format_enum rtc_alarm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 alarm_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rtc_alarm_id)
    {
        case DEVICE_AL_EN_None:
            alarm_format = AL_EN_None;
            break;
        case DEVICE_AL_EN_ChkS:
            alarm_format = AL_EN_ChkS;
            break;
        case DEVICE_AL_EN_ChkMS:
            alarm_format = AL_EN_ChkMS;
            break;
        case DEVICE_AL_EN_ChkHMS:
            alarm_format = AL_EN_ChkHMS;
            break;
        case DEVICE_AL_EN_ChkDHMS:
            alarm_format = AL_EN_ChkDHMS;
            break;
        case DEVICE_AL_EN_ChkWHMS:
            alarm_format = AL_EN_ChkWHMS;
            break;
        case DEVICE_AL_EN_ChkMDHMS:
            alarm_format = AL_EN_ChkMDHMS;
            break;
        case DEVICE_AL_EN_ChkYMDHMS:
            alarm_format = AL_EN_ChkYMDHMS;
            break;
        case DEVICE_AL_EN_NoChange:
            alarm_format = AL_EN_NoChange;
            break;
        default:
            alarm_format = AL_EN_None;
            break;
    }

    return alarm_format;
}

/*****************************************************************************
*   Function 
*      uem_rtc_clock_format_convert
*   DESCRIPTION
*      Rtc clock format convert
*   PARAMETERS
*
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_rtc_clock_format_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_clock_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem_rtc_clock_format_convert(rtc_clock_format_enum rtc_clock_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 clock_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rtc_clock_id)
    {
        case DEVICE_TC_EN_None:
            clock_format = TC_EN_None;
            break;
        case DEVICE_TC_EN_ChkS:
            clock_format = TC_EN_ChkS;
            break;
        case DEVICE_TC_EN_ChkM:
            clock_format = TC_EN_ChkM;
            break;
        case DEVICE_TC_EN_ChkH:
            clock_format = TC_EN_ChkH;
            break;
        case DEVICE_TC_EN_ChkD:
            clock_format = TC_EN_ChkD;
            break;
        case DEVICE_TC_EN_ChkW:
            clock_format = TC_EN_ChkW;
            break;
        case DEVICE_TC_EN_ChkMon:
            clock_format = TC_EN_ChkMon;
            break;
        case DEVICE_TC_EN_ChkY:
            clock_format = TC_EN_ChkY;
            break;
        case DEVICE_TC_EN_NoChange:
            clock_format = TC_EN_NoChange;
            break;
        default:
            clock_format = TC_EN_None;
            break;
    }

    return clock_format;
}

/*****************************************************************************
*   Function 
*      uem_battery_status_convert
*   DESCRIPTION
*      uem battery status convert
*   PARAMETERS
*      vm_status      IN
*   RETURNS
*      dev_status_enum
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_battery_status_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
battery_status_enum uem_battery_status_convert(kal_uint8 status_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    battery_status_enum bs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status_type)
    {
            /* Charger plug in */
        case BMT_CHARGER_IN:
            bs = PMIC_CHARGER_IN;
            break;
            /* Charger plug out */
        case BMT_CHARGER_OUT:
            bs = PMIC_CHARGER_OUT;
            break;
            /* The voltage of battery is too high. */
        case BMT_OVERVOLPROTECT:
            bs = PMIC_OVERVOLPROTECT;
            break;
            /* The temperature of battery is too high. */
        case BMT_OVERBATTEMP:
            bs = PMIC_OVERBATTEMP;
            break;
            /* The temperature of battery is too low. */
        case BMT_LOWBATTEMP:
            bs = PMIC_LOWBATTEMP;
            break;
            /* Charge current is too large. */
        case BMT_OVERCHARGECURRENT:
            bs = PMIC_OVERCHARGECURRENT;
            break;
            /* Charge current is too low. */
        case BMT_LOWCHARGECURRENT:
            bs = PMIC_LOWCHARGECURRENT;
            break;
            /* Charge is completed. */
        case BMT_CHARGE_COMPLETE:
            bs = PMIC_CHARGE_COMPLETE;
            break;
            /* Invalid battery */
        case BMT_INVALID_BAT:
            bs = PMIC_INVALID_BATTERY;
            break;
            /* Invalid charger */
        case BMT_INVALID_CHARGER:
            bs = PMIC_INVALID_CHARGER;
            break;
            /* Charging timeout, battery is bad */
        case BMT_CHARGE_TIMEOUT:
            bs = PMIC_CHARGING_TIMEOUT;
            break;
        case BMT_CHARGE_BAD_CONTACT:
            bs = PMIC_CHARGE_BAD_CONTACT;
            break;
        case BMT_BATTERY_BAD_CONTACT:
            bs = PMIC_BATTERY_BAD_CONTACT;
            break;

    #ifdef __USB_ENABLE__
        case BMT_USB_CHARGER_IN:
            bs = PMIC_USB_CHARGER_IN;
            break;
        case BMT_USB_CHARGER_OUT:
            bs = PMIC_USB_CHARGER_OUT;
            break;
        case BMT_USB_NO_CHARGING_IN:
            bs = PMIC_USB_NO_CHARGER_IN;
            break;
        case BMT_USB_NO_CHARGING_OUT:
            bs = PMIC_USB_NO_CHARGER_OUT;
            break;
    #endif /* __USB_ENABLE__ */ 

        default:
            bs = PMIC_VBAT_STATUS;
            break;
    }

    return bs;
}

/*****************************************************************************
*   Function 
*      uem_set_poweron_mode
*   DESCRIPTION
*      Rtc clock format convert
*   PARAMETERS
*      is_key_power      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_poweron_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_poweron_mode(kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uem_cntx_p->power_on_mode = mode;
}

/*****************************************************************************
*   Function 
*      uem_get_poweron_mode
*   DESCRIPTION
*      Speaker convert
*   PARAMETERS
*      void
*   RETURNS
*      is_key_power      IN
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_get_poweron_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem_get_poweron_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_uem_cntx_p->power_on_mode;
}

/*****************************************************************************
*   Function 
*      uem_set_bat_status
*   DESCRIPTION
*      Speaker convert
*   PARAMETERS
*      bat_status      IN
*      bat_vol      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_bat_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bmt_status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_bat_status(uem_bmt_struct bmt_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uem_cntx_p->bmt_status.status = bmt_status.status;
    g_uem_cntx_p->bmt_status.volt = bmt_status.volt;
    g_uem_cntx_p->bmt_status.adc = bmt_status.adc;
}

/*****************************************************************************
*   Function 
*      uem_get_bat_status
*   DESCRIPTION
*      Speaker convert
*   PARAMETERS
*      bat_status      IN
*      bat_vol      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_get_bat_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bmt_status      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_get_bat_status(uem_bmt_struct *bmt_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(bmt_status);

    bmt_status->status = g_uem_cntx_p->bmt_status.status;
    bmt_status->volt = g_uem_cntx_p->bmt_status.volt;
    bmt_status->adc = g_uem_cntx_p->bmt_status.adc;
}

/*****************************************************************************
*   Function 
*      uem_vbat_level_convert
*   DESCRIPTION
*      vbat convert to user level
*   PARAMETERS
*      bat_status      IN
*      bat_vol      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_vbat_level_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vbat        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem_vbat_level_convert(kal_int32 vbat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return custom_cfg_vbat_level_convert(vbat);
}

/*****************************************************************************
*   Function 
*      uem_set_silent_mode
*   DESCRIPTION
*      Silent mode
*   PARAMETERS
*      silent_mode      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_silent_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  silent_mode     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_silent_mode(kal_bool silent_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uem_cntx_p->rmi_data.silent_mode = silent_mode;
}

/*****************************************************************************
*   Function 
*      uem_get_silent_mode
*   DESCRIPTION
*      Silent mode
*   PARAMETERS
*      silent_mode      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_get_silent_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem_get_silent_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_uem_cntx_p->rmi_data.silent_mode;
}

/*****************************************************************************
*   Function 
*      uem_set_alert_mode
*   DESCRIPTION
*      Alert mode
*   PARAMETERS
*      alert_mode      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_alert_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alert_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_alert_mode(kal_uint8 alert_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uem_cntx_p->rmi_data.alert_mode = alert_mode;
}

/*****************************************************************************
*   Function 
*      uem_get_alert_mode
*   DESCRIPTION
*      Alert mode
*   PARAMETERS
*      silent_mode      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_get_alert_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem_get_alert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_uem_cntx_p->rmi_data.alert_mode;
}

/*****************************************************************************
*   Function 
*      uem_set_greeting_text
*   DESCRIPTION
*      Greeting Text
*   PARAMETERS
*      mode      IN
*      greeting_text IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_greeting_text
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
void uem_set_greeting_text(kal_bool mode, kal_uint8 text_dcs, kal_uint8 *greeting_text, kal_uint8 no_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uem_cntx_p->rmi_data.greeting_mode = mode;
    g_uem_cntx_p->rmi_data.greeting_text.text_length = no_text;
    g_uem_cntx_p->rmi_data.greeting_text.text_dcs = text_dcs;
    kal_mem_cpy(g_uem_cntx_p->rmi_data.greeting_text.text, greeting_text, UEM_GREETING_LEN - 1);
    g_uem_cntx_p->rmi_data.greeting_text.text[UEM_GREETING_LEN - 1] = '\0';
}

/*****************************************************************************
*   Function 
*      uem_get_alert_mode
*   DESCRIPTION
*      Greeting Text
*   PARAMETERS
*      mode      IN
*      greeting_text IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_get_greeting_text
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
void uem_get_greeting_text(kal_uint8 *mode, kal_uint8 *text_dcs, kal_uint8 *greeting_text, kal_uint8 *text_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *mode = g_uem_cntx_p->rmi_data.greeting_mode;
    *text_dcs = g_uem_cntx_p->rmi_data.greeting_text.text_dcs;
    *text_no = g_uem_cntx_p->rmi_data.greeting_text.text_length;
    kal_mem_cpy(greeting_text, g_uem_cntx_p->rmi_data.greeting_text.text, UEM_GREETING_LEN);
}

/*****************************************************************************
*   Function 
*      uem_get_equip_id
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
 *  uem_get_equip_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  equip_id            [IN]        
 *  equip_string        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void uem_get_equip_id(kal_uint8 equip_id, kal_uint8 *equip_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (equip_id)
    {
        case EQ_ME_REVISION_ID:
    #ifndef _WIN32
        {
            extern kal_char *release_verno(void);

            kal_mem_cpy(equip_string, (kal_uint8*) release_verno(), MAX_ME_ID_LEN - 1);
            equip_string[MAX_ME_ID_LEN - 1] = '\0';
            break;
        }
    #endif /* _WIN32 */ 

        case EQ_ME_MANUFACTURE_ID:
        case EQ_ME_MODEL_ID:
        case EQ_ME_GLOBAL_OBJECT_ID:
        case EQ_ME_MANUFACTURE_INFO_ID:
        case EQ_ME_COMP_CAP_LIST_ID:
        {
            kal_mem_cpy(
                equip_string,
                (kal_uint8*) g_uem_cntx_p->manufacture_data.me_manufacture_id[equip_id],
                MAX_ME_ID_LEN - 1);
            equip_string[MAX_ME_ID_LEN - 1] = '\0';
            break;
        }
        case EQ_ME_SERIAL_NUMBER_ID:
        {
            kal_uint8 imei_buf[9];

            /* Begin : modify by mtk00714 */
            if (nvram_get_imei_value(8, imei_buf))
            {
                imei_buf[7] = imei_buf[7] | 0xf0;
                /* convert IMEI from BCD to ASCII and copy it into equip_string */
                convert_to_digit(imei_buf, equip_string);
            }
            else
            {   /* get IMEI error */
                equip_string[0] = '\0';
            }
            break;
        }
        default:
            kal_mem_cpy(equip_string, (kal_uint8*) undef_equip_str, MAX_ME_ID_LEN - 1);
            equip_string[MAX_ME_ID_LEN - 1] = '\0';
            break;
    }
}

/*****************************************************************************
*   Function 
*      uem_set_gpio_status
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
 *  uem_set_gpio_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gpio_dev_type       [IN]        
 *  gpio_dev_level      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_gpio_status(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gpio_dev_type < MAX_GPIO_DEVICE_NUM)
    {
        g_uem_cntx_p->rmi_data.gpio_status[gpio_dev_type] = gpio_dev_level;
    }
}

/*****************************************************************************
*   Function 
*      uem_get_gpio_status
*   DESCRIPTION
*      The function is used to get the level of the GPIO device including the vibrator.
*   PARAMETERS
*      gpio_dev_type      IN
*      gpio_dev_level      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_get_gpio_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gpio_dev_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem_get_gpio_status(kal_uint8 gpio_dev_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_uem_cntx_p->rmi_data.gpio_status[gpio_dev_type];
}

/*****************************************************************************
*   Function 
*      uem_audio_set_mute
*   DESCRIPTION
*      
*   PARAMETERS
*      audio_device      IN
*      mute_onoff      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_audio_set_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_device        [IN]        
 *  mute_onoff          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_audio_set_mute(kal_uint8 audio_device, kal_bool mute_onoff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audio_device)
    {
        case AUDIO_DEVICE_MICROPHONE:
            if (mute_onoff)
            {
                g_uem_cntx_p->rmi_data.audio_mute_flag |= AUDIO_MUTE_MICROPHONE;
            }
            else
            {
                g_uem_cntx_p->rmi_data.audio_mute_flag &= ~AUDIO_MUTE_MICROPHONE;
            }
            break;
        case AUDIO_DEVICE_SPEAKER:
            if (mute_onoff)
            {
                g_uem_cntx_p->rmi_data.audio_mute_flag |= AUDIO_MUTE_SPEAKER;
            }
            else
            {
                g_uem_cntx_p->rmi_data.audio_mute_flag &= ~AUDIO_MUTE_SPEAKER;
            }
            break;
        case AUDIO_DEVICE_SPEAKER2:
            if (mute_onoff)
            {
                g_uem_cntx_p->rmi_data.audio_mute_flag |= AUDIO_MUTE_SPEAKER2;
            }
            else
            {
                g_uem_cntx_p->rmi_data.audio_mute_flag &= ~AUDIO_MUTE_SPEAKER2;
            }
            break;
        case AUDIO_DEVICE_LOUDSPEAKER:
            if (mute_onoff)
            {
                g_uem_cntx_p->rmi_data.audio_mute_flag |= AUDIO_MUTE_LOUDSPEAKER;
            }
            else
            {
                g_uem_cntx_p->rmi_data.audio_mute_flag &= ~AUDIO_MUTE_LOUDSPEAKER;
            }
            break;
        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      uem_audio_get_mute
*   DESCRIPTION
*      
*   PARAMETERS
*      audio_device      IN
*      mute_onoff      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_audio_get_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_device        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool uem_audio_get_mute(kal_uint8 audio_device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool mute_onoff = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audio_device)
    {
        case AUDIO_DEVICE_MICROPHONE:
            mute_onoff = ((g_uem_cntx_p->rmi_data.audio_mute_flag) & AUDIO_MUTE_MICROPHONE) ? KAL_TRUE : KAL_FALSE;
            break;
        case AUDIO_DEVICE_SPEAKER:
            mute_onoff = ((g_uem_cntx_p->rmi_data.audio_mute_flag) & AUDIO_MUTE_SPEAKER) ? KAL_TRUE : KAL_FALSE;
            break;
        case AUDIO_DEVICE_SPEAKER2:
            mute_onoff = ((g_uem_cntx_p->rmi_data.audio_mute_flag) & AUDIO_MUTE_SPEAKER2) ? KAL_TRUE : KAL_FALSE;
            break;
        case AUDIO_DEVICE_LOUDSPEAKER:
            mute_onoff = ((g_uem_cntx_p->rmi_data.audio_mute_flag) & AUDIO_MUTE_LOUDSPEAKER) ? KAL_TRUE : KAL_FALSE;
            break;
        default:
            break;
    }

    return mute_onoff;
}

/*****************************************************************************
*   Function 
*      uem_set_datetime_mode
*   DESCRIPTION
*      L4C requests UEM to store date format. Please reference the AT command "+CSDF"
*   PARAMETERS
*      is_date_set      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_datetime_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_date_set     [IN]        
 *  format          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_datetime_format(kal_bool is_date_set, kal_uint8 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ref: date_format_enum */
    if (is_date_set == KAL_TRUE)
    {
        g_uem_cntx_p->rmi_data.date_mode = format;
    }
    /* ref: time_format_enum */
    else
    {
        g_uem_cntx_p->rmi_data.time_mode = format;
    }
}

/*****************************************************************************
*   Function 
*      uem_get_datetime_format
*   DESCRIPTION
*      L4C requests UEM to store date format. Please reference the AT command "+CSDF"
*   PARAMETERS
*      is_date_set      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_get_datetime_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_date_set     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem_get_datetime_format(kal_bool is_date_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ref: date_format_enum */
    if (is_date_set == KAL_TRUE)
    {
        return g_uem_cntx_p->rmi_data.date_mode;
    }
    /* ref: time_format_enum */
    else
    {
        return g_uem_cntx_p->rmi_data.time_mode;
    }
}

/*****************************************************************************
*   Function 
*      uem_set_state
*   DESCRIPTION
*      NVRAM state
*   PARAMETERS
*      state      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_state(uem_status_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uem_cntx_p->state = state;
}

/*****************************************************************************
*   Function 
*      uem_get_state
*   DESCRIPTION
*      NVRAM state
*   PARAMETERS
*      
*   RETURNS
*      NVRAM state
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_get_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_uem_cntx_p->state;
}

/*****************************************************************************
*   Function 
*      uem_alarm_set_time
*   DESCRIPTION
*      set alarm time
*   PARAMETERS
*      void
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_alarm_set_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_alarm_id        [IN]        
 *  alarm_info          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_alarm_set_time(kal_uint8 rtc_alarm_id, rtc_alarm_info_struct alarm_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rtc_alarm_id < MAX_ALARM_NUM)
    {
        kal_mem_cpy(&(g_uem_cntx_p->rmi_data.alarm_info[rtc_alarm_id]), &alarm_info, sizeof(rtc_alarm_info_struct));
    }
}

/*****************************************************************************
*   Function 
*      uem_rtc_delete
*   DESCRIPTION
*      
*   PARAMETERS
*      rtc_type      IN
*      rtc_alarm_id   IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_rtc_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtc_alarm_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_rtc_delete(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
            break;
        case RTC_ALARM_IND:
            if (rtc_alarm_id < MAX_ALARM_NUM)
            {
                g_uem_cntx_p->rmi_data.alarm_info[rtc_alarm_id].alarm_format = DEVICE_TC_EN_None;
            }
            break;
        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      uem_get_vbat_percentage
*   DESCRIPTION
*      
*   PARAMETERS
*      void
*   RETURNS
*      kal_uint32
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_get_vbat_percentage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 uem_get_vbat_percentage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_get_bat_status(&bmt_status);

    return custom_cfg_vbat_percentage_convert(bmt_status.volt);
}

#ifdef __USB_ENABLE__
/*****************************************************************************
*   Function 
*      uem2l4_usb_detect_action_convert
*   DESCRIPTION
*      
*   PARAMETERS
*      action        IN
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem2l4_usb_detect_action_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem2l4_usb_detect_action_convert(kal_uint8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    USB_DETECT_ACTION_ID usb_action = (USB_DETECT_ACTION_ID) action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (usb_action)
    {
        case DETECT_ACTION_PLUGIN:
            return DEVUSB_DETECT_ACTION_PLUGIN;

        case DETECT_ACTION_PLUGOUT:
            return DEVUSB_DETECT_ACTION_PLUGOUT;

        default:
            return DETECT_ACTION_UNKNOWN;
    }
}

/*****************************************************************************
*   Function 
*      uem2l4_usb_config_action_convert
*   DESCRIPTION
*      
*   PARAMETERS
*      action        IN
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem2l4_usb_config_action_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem2l4_usb_config_action_convert(kal_uint8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    USB_DEVICE_TYPE usb_action = (USB_DEVICE_TYPE) action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (usb_action)
    {
        case USB_CDC_ACM:
            return DEVUSB_CFG_ACTION_CDC_ACM;

        case USB_MASS_STORAGE:
            return DEVUSB_CFG_ACTION_MASS_STORAGE;

        case USB_COMPOSITE:
            return DEVUSB_CFG_ACTION_COMPOSITE;

        case USB_VIDEO:
            return DEVUSB_CFG_ACTION_WEBCAM;

        case USB_STOP_MS:
            return DEVUSB_CFG_ACTION_STOP_MS;
        case USB_CDC_ACM_IRDBG:
            return DEVUSB_CFG_ACTION_IRDBG;
            
        case USB_IMAGE:
            return DEVUSB_CFG_ACTION_PICTBRIGE;
        
        default:
            return DEVUSB_CFG_ACTION_UNKNOWN;
    }
}

/*****************************************************************************
*   Function 
*      uem2drv_usb_config_action_convert
*   DESCRIPTION
*      
*   PARAMETERS
*      action        IN
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem2drv_usb_config_action_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 uem2drv_usb_config_action_convert(kal_uint8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    USB_DEVICE_TYPE usb_action = (USB_DEVICE_TYPE) action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (usb_action)
    {
        case DEVUSB_CFG_ACTION_CDC_ACM:
            return USB_CDC_ACM;

        case DEVUSB_CFG_ACTION_MASS_STORAGE:
            return USB_MASS_STORAGE;

        case DEVUSB_CFG_ACTION_WEBCAM:
            return USB_VIDEO;

        case DEVUSB_CFG_ACTION_COMPOSITE:
            return USB_COMPOSITE;

        case DEVUSB_CFG_ACTION_STOP_MS:
            return USB_STOP_MS;

        case DEVUSB_CFG_ACTION_IRDBG:
            return USB_CDC_ACM_IRDBG;

        case DEVUSB_CFG_ACTION_PICTBRIGE:
            return USB_IMAGE;

        default:
            return USB_UNKOWN;
    }
}
#endif /* __USB_ENABLE__ */ 

#if defined(PLUTO_MMI)
/*****************************************************************************
*   Function 
*      is_status_matched
*   DESCRIPTION
*      
*   PARAMETERS
*      
*   RETURNS
*      
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  is_status_matched
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool is_status_matched(uem_accessory_status_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, type) == FLAG_IS_ON(g_uem_cntx_p->acc_latest_state, type))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}
#endif /* defined(PLUTO_MMI) */ 

/*****************************************************************************
*   Function 
*      uem_send_msg_to_l4c
*   DESCRIPTION
*      
*   PARAMETERS
*      msg_name        IN
*      data_ptr        IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_send_msg_to_l4c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 *  data_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void uem_send_msg_to_l4c(msg_type msg_name, void *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;
    ilm_struct *ilm_ptr = NULL;
    void *local_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SEND_MSG_TO_L4C);

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_UEM);

    ilm_ptr->msg_id = msg_name; /* Set the message id */
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->peer_buff_ptr = NULL;

    switch (msg_name)
    {
            /* set profile confirm to L4c */
        case MSG_ID_L4CUEM_SET_PROFILE_CNF:
            local_data_ptr =
                (l4cuem_set_profile_cnf_struct*) construct_local_para(sizeof(l4cuem_set_profile_cnf_struct), TD_CTRL);
            ((l4cuem_set_profile_cnf_struct*) local_data_ptr)->src_id = LMMI_SRC;
            ((l4cuem_set_profile_cnf_struct*) local_data_ptr)->type = g_uem_cntx_p->func_id;

            if (g_uem_cntx_p->cause_id == NVRAM_IO_ERRNO_OK)
            {
                ((l4cuem_set_profile_cnf_struct*) local_data_ptr)->response = L4C_OK;
            }
            else
            {
                ((l4cuem_set_profile_cnf_struct*) local_data_ptr)->response = L4C_ERROR;
            }

            ((l4cuem_set_profile_cnf_struct*) local_data_ptr)->cause = g_uem_cntx_p->cause_id;

            ilm_ptr->local_para_ptr = (local_para_struct*) local_data_ptr;
            break;

        case MSG_ID_L4CUEM_SET_HW_LEVEL_CNF:
            local_data_ptr =
                (l4cuem_set_hw_level_cnf_struct*) construct_local_para(
                                                    sizeof(l4cuem_set_hw_level_cnf_struct),
                                                    TD_CTRL);
            ((l4cuem_set_hw_level_cnf_struct*) local_data_ptr)->src_id = g_uem_cntx_p->src_id;

            if (g_uem_cntx_p->cause_id == NVRAM_IO_ERRNO_OK)
            {
                ((l4cuem_set_hw_level_cnf_struct*) local_data_ptr)->response = L4C_OK;
            }
            else
            {
                ((l4cuem_set_hw_level_cnf_struct*) local_data_ptr)->response = L4C_ERROR;
            }

            ((l4cuem_set_hw_level_cnf_struct*) local_data_ptr)->cause = g_uem_cntx_p->cause_id;

            ilm_ptr->local_para_ptr = (local_para_struct*) local_data_ptr;
            break;

            /* set startup confirm to L4c */
        case MSG_ID_L4CUEM_STARTUP_CNF:
            local_data_ptr =
                (l4cuem_startup_cnf_struct*) construct_local_para(sizeof(l4cuem_startup_cnf_struct), TD_CTRL);
            ((l4cuem_startup_cnf_struct*) local_data_ptr)->src_id = LMMI_SRC;

            if (g_uem_cntx_p->cause_id == NVRAM_IO_ERRNO_OK)
            {
                ((l4cuem_startup_cnf_struct*) local_data_ptr)->response = L4C_OK;
            }
            else
            {
                ((l4cuem_startup_cnf_struct*) local_data_ptr)->response = L4C_ERROR;
            }

            ((l4cuem_startup_cnf_struct*) local_data_ptr)->cause = g_uem_cntx_p->cause_id;

            ilm_ptr->local_para_ptr = (local_para_struct*) local_data_ptr;
            break;

        case MSG_ID_L4CUEM_SET_AUDIO_PROFILE_CNF:
        case MSG_ID_L4CUEM_SET_AUDIO_PARAM_CNF:
        case MSG_ID_L4CUEM_AUDIO_PLAY_BY_NAME_CNF:
        case MSG_ID_L4CUEM_AUDIO_STOP_BY_NAME_CNF:
        case MSG_ID_L4CUEM_AUDIO_PLAY_BY_STRING_CNF:
        case MSG_ID_L4CUEM_AUDIO_STOP_BY_STRING_CNF:
            /* hold the local parameter struct and directly pass to L4c */
            hold_local_para((local_para_struct*) data_ptr);
            ilm_ptr->local_para_ptr = (local_para_struct*) data_ptr;
            break;

        case MSG_ID_L4CPS_EM_STATUS_IND:
            /* Engineering mode idication: send status to L4C-EM module */
        {
            peer_buff_struct *peer_ptr;
            l4cps_em_status_ind_struct *local_ptr;
            kal_uint16 len_pdu;
            uem_em_battery_info *l_uem_battery_info;
            uem_bmt_struct bmt_status;

            /* get the battery status */
            uem_get_bat_status(&bmt_status);

            /* fill the battery status */
            peer_ptr = (peer_buff_struct*) construct_peer_buff(sizeof(uem_em_battery_info), 0, 0, TD_CTRL);
            l_uem_battery_info = (uem_em_battery_info*) get_pdu_ptr(peer_ptr, &(len_pdu));
            l_uem_battery_info->adc_value = bmt_status.volt;
            l_uem_battery_info->battery_level = uem_vbat_level_convert(bmt_status.volt);
            l_uem_battery_info->battery_status = bmt_status.status;

            /* fill the UEM battery infomation indication */
            local_ptr =
                (l4cps_em_status_ind_struct*) construct_local_para(sizeof(l4cps_em_status_ind_struct), TD_CTRL);
            local_ptr->em_info = UEM_EM_BATTERY_INFO;

            /* fill the message */
            ilm_ptr->local_para_ptr = (local_para_struct*) local_ptr;
            ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_ptr;
            break;
        }

        default:
            ret_val = KAL_FALSE;
            /* SME_ASSERT(KAL_FALSE, "Wrong message" ); */
            break;
    }   /* End Switch */
    /* Check whether that there were no errors while constructing the message.  */

    /* Send the message to the UEM module */
    if (ret_val == KAL_TRUE)
    {
        SEND_ILM(MOD_UEM, MOD_L4C, UEM_L4C_SAP, ilm_ptr);
    }

    return;
}

/*****************************************************************************
*   Function 
*      uem_send_msg_to_nvram
*   DESCRIPTION
*      
*   PARAMETERS
*      msg_name        IN
*      ef_id           IN
*      data_ptr        IN
*      length        IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_send_msg_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 *  ef_id           [IN]        
 *  data_ptr        [?]         
 *  length          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_send_msg_to_nvram(msg_type msg_name, kal_uint16 ef_id, void *data_ptr, kal_uint16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;
    ilm_struct *ilm_ptr = NULL;
    peer_buff_struct *data_stream;
    local_para_struct *parm_stream;
    kal_uint16 pdu_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SEND_MSG_TO_NVRAM);

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_UEM);

    ilm_ptr->msg_id = msg_name; /* Set the message id */
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->peer_buff_ptr = NULL;
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->local_para_ptr = NULL;
    switch (msg_name)
    {
        case MSG_ID_NVRAM_WRITE_REQ:
            switch (ef_id)
            {
                case NVRAM_EF_UEM_RMI_DATA_LID:
                case NVRAM_EF_CUST_HW_LEVEL_TBL_LID:
                    parm_stream = construct_local_para(sizeof(nvram_write_req_struct), TD_CTRL);
                    data_stream = construct_peer_buff(length, 0, 0, TD_CTRL);

                    ((nvram_write_req_struct*) parm_stream)->file_idx = (kal_uint8) ef_id;
                    ((nvram_write_req_struct*) parm_stream)->para = 1;
                    /* keep the function id in NVRAM message from UEM */
                    ((nvram_write_req_struct*) parm_stream)->access_id = g_uem_cntx_p->func_id;

                    pdu_len = length;
                    kal_mem_cpy(get_pdu_ptr(data_stream, &pdu_len), data_ptr, length);

                    ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
                    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) data_stream;
                    break;
                default:
                    /* error write */
                    break;
            }
            break;

        case MSG_ID_NVRAM_READ_REQ:
            switch (ef_id)
            {
                case NVRAM_EF_UEM_RMI_DATA_LID:
                case NVRAM_EF_UEM_MANUFACTURE_DATA_LID:
                case NVRAM_EF_CUST_HW_LEVEL_TBL_LID:
                    parm_stream = construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);

                    ((nvram_read_req_struct*) parm_stream)->file_idx = (kal_uint8) ef_id;
                    ((nvram_read_req_struct*) parm_stream)->para = 1;

                    ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
                    break;

                default:
                    /* error read */
                    break;
            }
            break;

        default:
            ret_val = KAL_FALSE;
            /* SME_ASSERT(KAL_FALSE, "Wrong message" ); */
            break;
    }   /* End Switch */
    /* Check whether that there were no errors while constructing the message.  */

    /* Send the message to the NVRAM module */
    if (ret_val == KAL_TRUE)
    {
        SEND_ILM(MOD_UEM, MOD_NVRAM, PS_NVRAM_SAP, ilm_ptr);
    }

    return;
}

/*****************************************************************************
*   Function 
*      uem_send_msg_to_sat
*   DESCRIPTION
*      
*   PARAMETERS
*      ...
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_send_msg_to_sat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 *  data_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void uem_send_msg_to_sat(kal_uint32 src_mod_id, msg_type msg_name, void *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;
    ilm_struct *ilm_ptr = NULL;
    sat_language_cnf_struct *l_language_cnf_data;
    sat_current_time_cnf_struct *l_current_time_cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SEND_MSG_TO_SAT);

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_UEM);

    ilm_ptr->msg_id = msg_name; /* Set the message id */
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->peer_buff_ptr = NULL;
    switch (msg_name)
    {
        case MSG_ID_SAT_LANGUAGE_CNF:
            l_language_cnf_data = (sat_language_cnf_struct*)
                construct_local_para(sizeof(sat_language_cnf_struct), TD_CTRL);

            l_language_cnf_data->language[0] = g_uem_cntx_p->rmi_data.lang_id[0];
            l_language_cnf_data->language[1] = g_uem_cntx_p->rmi_data.lang_id[1];

            ilm_ptr->local_para_ptr = (local_para_struct*) l_language_cnf_data;
            break;

        case MSG_ID_SAT_CURRENT_TIME_CNF:
        {
            rtc_alarm_info_struct l_rtc_clock_info;

            l_current_time_cnf_data = (sat_current_time_cnf_struct*)
                construct_local_para(sizeof(sat_current_time_cnf_struct), TD_CTRL);

            l4cuem_rtc_get_time_req(RTC_TIME_CLOCK_IND, 0, &l_rtc_clock_info);

            l_current_time_cnf_data->time_info[0] = l_rtc_clock_info.data_time.rtc_day;
            l_current_time_cnf_data->time_info[1] = l_rtc_clock_info.data_time.rtc_hour;
            l_current_time_cnf_data->time_info[2] = l_rtc_clock_info.data_time.rtc_min;
            l_current_time_cnf_data->time_info[3] = l_rtc_clock_info.data_time.rtc_sec;
            l_current_time_cnf_data->time_info[4] = l_rtc_clock_info.data_time.rtc_year;
            l_current_time_cnf_data->time_info[5] = l_rtc_clock_info.data_time.rtc_mon;

            ilm_ptr->local_para_ptr = (local_para_struct*) l_current_time_cnf_data;
            break;
        }

        default:
            ret_val = KAL_FALSE;
            /* SME_ASSERT(KAL_FALSE, "Wrong message" ); */
            break;
    }   /* End Switch */
    /* Check whether that there were no errors while constructing the message.  */

    /* Send the message to the UEM module */
    if (ret_val == KAL_TRUE)
    {
    #ifdef __GEMINI__
        if (src_mod_id == MOD_SIM_2)
        {
            SEND_ILM(MOD_UEM, MOD_SIM_2, PS_SIM_SAP, ilm_ptr);
        }
        else
    #endif /* #ifdef __GEMINI__ */
        {
            SEND_ILM(MOD_UEM, MOD_SIM, PS_SIM_SAP, ilm_ptr);
        }
    }

    return;
}

/*****************************************************************************
*   Function 
*      uem_send_msg_to_aud
*   DESCRIPTION
*      
*   PARAMETERS
*      ...
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_send_msg_to_aud
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_send_msg_to_aud(kal_uint32 msg_name, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list varpars;
    kal_bool ret_val = KAL_TRUE;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SEND_MSG_TO_AUD);

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_UEM);

    ilm_ptr->msg_id = (msg_type) msg_name;  /* Set the message id */
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->peer_buff_ptr = NULL;
    switch (msg_name)
    {
        case MSG_ID_MED_STARTUP_REQ:
        {
            med_startup_req_struct *dst_data_ptr;

            dst_data_ptr = (med_startup_req_struct*) construct_local_para(sizeof(med_startup_req_struct), TD_CTRL);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_SET_AUDIO_MODE_REQ:
        {
            l4aud_set_audio_mode_req_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_set_audio_mode_req_struct*)
                construct_local_para(sizeof(l4aud_set_audio_mode_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->mode = (kal_uint8) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_GPIO_DETECT_IND:
        {
            l4aud_gpio_detect_ind_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_gpio_detect_ind_struct*)
                construct_local_para(sizeof(l4aud_gpio_detect_ind_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->gpio_device = (kal_uint8) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_AUDIO_SET_GAIN_REQ:
        {
            l4aud_audio_set_gain_req_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_audio_set_gain_req_struct*)
                construct_local_para(sizeof(l4aud_audio_set_gain_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->audio_type = (kal_uint8) va_arg(varpars, kal_uint32);
            dst_data_ptr->volume_level = (kal_uint8) va_arg(varpars, kal_uint32);
            dst_data_ptr->gain = (kal_uint8) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_SP_SET_MODE_REQ:
        {
            l4aud_sp_set_mode_req_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_sp_set_mode_req_struct*)
                construct_local_para(sizeof(l4aud_sp_set_mode_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->speech_on = (kal_bool) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_AUDIO_SET_DEVICE_REQ:
        {
            l4aud_audio_set_device_req_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_audio_set_device_req_struct*)
                construct_local_para(sizeof(l4aud_audio_set_device_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->audio_type = (kal_uint8) va_arg(varpars, kal_uint32);
            dst_data_ptr->device = (kal_uint8) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_AUDIO_PLAY_REQ:
        {
            l4aud_audio_play_req_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_audio_play_req_struct*)
                construct_local_para(sizeof(l4aud_audio_play_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->audio_id = (kal_uint8) va_arg(varpars, kal_uint32);
            dst_data_ptr->play_style = (kal_uint8) va_arg(varpars, kal_uint32);
            dst_data_ptr->identifier = (kal_uint16) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_AUDIO_STOP_REQ:
        {
            l4aud_audio_stop_req_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_audio_stop_req_struct*)
                construct_local_para(sizeof(l4aud_audio_stop_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->audio_id = (kal_uint8) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_AUDIO_MUTE_REQ:
        {
            l4aud_audio_mute_req_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_audio_mute_req_struct*)
                construct_local_para(sizeof(l4aud_audio_mute_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->device = (kal_uint8) va_arg(varpars, kal_uint32);
            dst_data_ptr->mute = (kal_bool) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_AUDIO_SET_VOLUME_REQ:
        {
            l4aud_audio_set_volume_req_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_audio_set_volume_req_struct*)
                construct_local_para(sizeof(l4aud_audio_set_volume_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->audio_type = (kal_uint8) va_arg(varpars, kal_uint32);
            dst_data_ptr->volume = (kal_uint8) va_arg(varpars, kal_uint32);
            dst_data_ptr->aux_volume = (kal_uint8) va_arg(varpars, kal_uint32);
            dst_data_ptr->mode = (kal_uint8) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_AUDIO_DEMO_IMY_REQ:
        {
            l4aud_audio_demo_imy_req_struct *dst_data_ptr;
            peer_buff_struct *data_stream;
            kal_uint8 *src_data_ptr;
            kal_uint16 pdu_len;

            dst_data_ptr = (l4aud_audio_demo_imy_req_struct*)
                construct_local_para(sizeof(l4aud_audio_demo_imy_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            src_data_ptr = (kal_uint8*) va_arg(varpars, kal_uint32);
            dst_data_ptr->imy_len = (kal_uint16) va_arg(varpars, kal_uint32);
            dst_data_ptr->play_style = (kal_uint8) va_arg(varpars, kal_uint32);
            dst_data_ptr->identifier = (kal_uint16) va_arg(varpars, kal_uint32);
            va_end(varpars);

            data_stream = construct_peer_buff(dst_data_ptr->imy_len, 0, 0, TD_CTRL);
            kal_mem_cpy(get_pdu_ptr(data_stream, &pdu_len), src_data_ptr, dst_data_ptr->imy_len);

            ilm_ptr->peer_buff_ptr = (peer_buff_struct*) data_stream;
            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }

        case MSG_ID_L4AUD_AUDIO_PLAY_BY_NAME_REQ:
        case MSG_ID_L4AUD_AUDIO_STOP_BY_NAME_REQ:
        case MSG_ID_L4AUD_AUDIO_PLAY_BY_STRING_REQ:
        case MSG_ID_L4AUD_AUDIO_STOP_BY_STRING_REQ:
        case MSG_ID_L4AUD_SET_AUDIO_PROFILE_REQ:
        case MSG_ID_L4AUD_SET_AUDIO_PARAM_REQ:
        {
            local_para_struct *data_ptr;

            va_start(varpars, msg_name);
            data_ptr = (local_para_struct*) va_arg(varpars, kal_uint32);
            va_end(varpars);

            /* hold the local parameter struct and directly pass to L4c */
            hold_local_para((local_para_struct*) data_ptr);

            ilm_ptr->local_para_ptr = (local_para_struct*) data_ptr;
            break;
        }
        case MSG_ID_MEDIA_TVO_AV_CABLE_DETECT_IND:  /* tv out cable in */
        {
            media_tvo_av_cable_detect_ind_struct *dst_data_ptr;

            dst_data_ptr = (media_tvo_av_cable_detect_ind_struct*)
                construct_local_para(sizeof(media_tvo_av_cable_detect_ind_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->result = (kal_int16) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_GET_AUDIO_PARAM_REQ:
        {
            l4aud_get_audio_param_req_struct *data_ptr;

            data_ptr = (l4aud_get_audio_param_req_struct*)
                construct_local_para(sizeof(l4aud_get_audio_param_req_struct), TD_CTRL);

            ilm_ptr->local_para_ptr = (local_para_struct*) data_ptr;

            break;
        }
        case MSG_ID_L4AUD_GET_AUDIO_PROFILE_REQ:
        {
            l4aud_get_audio_profile_req_struct *data_ptr;

            data_ptr = (l4aud_get_audio_profile_req_struct*)
                construct_local_para(sizeof(l4aud_get_audio_profile_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            data_ptr->mode = (kal_int8) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) data_ptr;
            break;
        }
        case MSG_ID_L4AUD_AUDIO_GET_VOLUME_REQ:
        {
            l4aud_get_volume_req_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_get_volume_req_struct*)
                construct_local_para(sizeof(l4aud_get_volume_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->volume_type = (kal_int16) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }
        case MSG_ID_L4AUD_AUDIO_GET_GAIN_REQ:
        {
            l4aud_get_gain_req_struct *dst_data_ptr;

            dst_data_ptr = (l4aud_get_gain_req_struct*)
                construct_local_para(sizeof(l4aud_get_gain_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            dst_data_ptr->volume_type = (kal_int16) va_arg(varpars, kal_uint32);
            dst_data_ptr->volume_level = (kal_int16) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;
            break;
        }

        default:
            ret_val = KAL_FALSE;
            break;
    }   /* End Switch */
    /* Check whether that there were no errors while constructing the message. */

    /* Send the message to the AUD module */
    if (ret_val == KAL_TRUE)
    {
        SEND_ILM(MOD_UEM, MOD_MED, MED_SAP, ilm_ptr);
    }

    return;
}

/*****************************************************************************
*   Function 
*      uem_send_msg_to_bmt
*   DESCRIPTION
*      
*   PARAMETERS
*      ...
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_send_msg_to_bmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_send_msg_to_bmt(kal_uint32 msg_name, ...)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;
    ilm_struct *ilm_ptr = NULL;
    void *parm_stream;
    va_list varpars;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SEND_MSG_TO_BMT);

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_UEM);

    ilm_ptr->msg_id = (msg_type) msg_name;  /* Set the message id */
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->peer_buff_ptr = NULL;

    switch (msg_name)
    {
        case MSG_ID_BMT_ADC_ADD_ITEM_REQ:
        {
            parm_stream =
                (bmt_adc_add_item_req_struct*) construct_local_para(sizeof(bmt_adc_add_item_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            ((bmt_adc_add_item_req_struct*) parm_stream)->adc_sche_id = (kal_uint8) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
            break;
        }
        case MSG_ID_BMT_ADC_REMOVE_ITEM_REQ:
        {
            parm_stream =
                (bmt_adc_remove_item_req_struct*) construct_local_para(
                                                    sizeof(bmt_adc_remove_item_req_struct),
                                                    TD_CTRL);

            va_start(varpars, msg_name);
            ((bmt_adc_remove_item_req_struct*) parm_stream)->adc_sche_id = (kal_uint8) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
            break;
        }
        case MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ:
        {
            parm_stream =
                (bmt_adc_modify_parameters_req_struct*)
                construct_local_para(sizeof(bmt_adc_modify_parameters_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            ((bmt_adc_modify_parameters_req_struct*) parm_stream)->adc_sche_id =
                (kal_uint8) va_arg(varpars, kal_uint32);
            ((bmt_adc_modify_parameters_req_struct*) parm_stream)->evaluate_count =
                (kal_uint8) va_arg(varpars, kal_uint32);
            ((bmt_adc_modify_parameters_req_struct*) parm_stream)->period = (kal_uint32) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
            break;
        }
        default:
            ret_val = KAL_FALSE;
            break;
    }

    /* Send the message to the UEM module */
    if (ret_val == KAL_TRUE)
    {
        SEND_ILM(MOD_UEM, MOD_BMT, DRIVER_PS_SAP, ilm_ptr);
    }
#endif /* __MTK_TARGET__ */ 

    return;
}

/*****************************************************************************
*   Function 
*      uem_send_msg_to_aux
*   DESCRIPTION
*      
*   PARAMETERS
*      ...
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_send_msg_to_aux
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_send_msg_to_aux(kal_uint32 msg_name, ...)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_bool ret_val = KAL_TRUE;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_UEM);

    ilm_ptr->msg_id = (msg_type) msg_name;  /* Set the message id */
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->peer_buff_ptr = NULL;

    switch (msg_name)
    {
        case MSG_ID_READ_ALL_ADC_CHANNEL_REQ:
            ilm_ptr->local_para_ptr = NULL;
            break;
        case MSG_ID_AUX_CALL_SETUP_REQ_IND:
            ilm_ptr->local_para_ptr = NULL;
            break;
        case MSG_ID_AUX_CALL_CONNECT_REQ_IND:
            ilm_ptr->local_para_ptr = NULL;
            break;
        case MSG_ID_AUX_CALL_DISCONNECT_REQ_IND:
            ilm_ptr->local_para_ptr = NULL;
            break;
        default:
            ret_val = KAL_FALSE;
            break;
    }

    /* Send the message to the UEM module */
    if (ret_val == KAL_TRUE)
    {
        SEND_ILM(MOD_UEM, MOD_AUX, DRIVER_PS_SAP, ilm_ptr);
    }
#endif /* __MTK_TARGET__ */ 

    return;
}

#ifdef __USB_ENABLE__
/*****************************************************************************
*   Function 
*      uem_send_msg_to_usbms
*   DESCRIPTION
*      
*   PARAMETERS
*      ...
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_send_msg_to_usbms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_send_msg_to_usbms(kal_uint32 msg_name, ...)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;
    ilm_struct *ilm_ptr = NULL;
    drvuem_usbcfg_req_struct *parm_stream;
    va_list varpars;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_UEM);

    ilm_ptr->msg_id = (msg_type) msg_name;  /* Set the message id */
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->peer_buff_ptr = NULL;

    switch (msg_name)
    {
        case MSG_ID_DRVUEM_USBCFG_REQ:
        {
            parm_stream = (drvuem_usbcfg_req_struct*) construct_local_para(sizeof(drvuem_usbcfg_req_struct), TD_CTRL);

            va_start(varpars, msg_name);
            parm_stream->mode = (kal_uint8) va_arg(varpars, kal_uint32);
        #if (defined(__USB_IN_NORMAL_MODE__) && defined(__MULTI_BOOT__)) || defined(PICTBRIDGE_SUPPORT)
            if (USBMS_BOOT != stack_query_boot_mode())
            {
                kal_prompt_trace(MOD_UEM, "USB buffer address: 0x%x", uem_normal_ms_buffer);
                parm_stream->parameter = (kal_uint32*) uem_normal_ms_buffer;
            }
        #endif /* (defined(__USB_IN_NORMAL_MODE__) && defined(__MULTI_BOOT__)) || defined(PICTBRIDGE_SUPPORT) */ 
            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
            break;
        }
        default:
            ret_val = KAL_FALSE;
            break;
    }

    /* Send the message to the UEM module */
    if (ret_val == KAL_TRUE)
    {
        SEND_ILM(MOD_UEM, MOD_USB, DRIVER_PS_SAP, ilm_ptr);
    }
#endif /* __MTK_TARGET__ */ 

    return;
}
#endif /* __USB_ENABLE__ */ 

#ifdef TST_INJECTED_EVENT
/*****************************************************************************
*   Function 
*      uem_send_msg_to_uem
*   DESCRIPTION
*      
*   PARAMETERS
*      ...
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_send_msg_to_uem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_send_msg_to_uem(kal_uint32 msg_name, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;
    ilm_struct *ilm_ptr = NULL;

#if (defined(__USB_ENABLE__) && defined(TST_INJECTED_EVENT))
    va_list varpars;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SEND_MSG_TO_UEM);

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_DRVKBD);

    ilm_ptr->msg_id = (msg_type) msg_name;  /* Set the message id */
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->peer_buff_ptr = NULL;
    switch (msg_name)
    {
        case MSG_ID_DRVUEM_KEYPAD_IND:
        {
            break;
        }

    #if (defined(__USB_ENABLE__) && defined(TST_INJECTED_EVENT))
        case MSG_ID_DRVUEM_USBDETECT_IND:
        {
            drvuem_usbdetect_ind_struct *param;

            param = (drvuem_usbdetect_ind_struct*) construct_local_para(sizeof(drvuem_usbdetect_ind_struct), TD_CTRL);

            param->action = (kal_uint8) va_arg(varpars, kal_uint32);
            ilm_ptr->local_para_ptr = (local_para_struct*) param;

            break;
        }
        case MSG_ID_DRVUEM_USBCFG_CNF:
        {
            drvuem_usbcfg_cnf_struct *param;

            param = (drvuem_usbcfg_cnf_struct*) construct_local_para(sizeof(drvuem_usbcfg_cnf_struct), TD_CTRL);

            va_start(varpars, msg_name);

            param->mode = (kal_uint8) va_arg(varpars, kal_uint32);
            param->result = (kal_uint8) va_arg(varpars, kal_uint32);
            param->reserved = (kal_uint8) va_arg(varpars, kal_uint32);

            va_end(varpars);

            ilm_ptr->local_para_ptr = (local_para_struct*) param;
            break;
        }
    #endif /* (defined(__USB_ENABLE__) && defined(TST_INJECTED_EVENT)) */ 

        default:
            ret_val = KAL_FALSE;
            /* SME_ASSERT(KAL_FALSE, "Wrong message" ); */
            break;
    }   /* End Switch */
    /* Check whether that there were no errors while constructing the message.  */

    /* Send the message to the UEM module */
    if (ret_val == KAL_TRUE)
    {
        SEND_ILM(MOD_DRVKBD, MOD_UEM, UEM_L4C_SAP, ilm_ptr);
    }

    return;
}
#endif /* TST_INJECTED_EVENT */ 

/*****************************************************************************
*   Function 
*      uem_timer_init
*   DESCRIPTION
*      To initial the timer.
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_timer_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uem_timer_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_init_timer(&uem_base_timer, "UEM_Base_Timer1", MOD_UEM);

    /* Create a no alignment timer schedule */
    event_scheduler_uem_ptr = new_evshed(
                                &uem_base_timer,
                                uem_start_basetimer,
                                uem_stop_basetimer,
                                0,
                                kal_evshed_get_mem,
                                kal_evshed_free_mem,
                                0);
}

/*****************************************************************************
*   Function 
*      uem_stop_basetimer
*   DESCRIPTION
*      To stop base timer.
*   PARAMETERS
*      base_timer_ptr   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_stop_basetimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_stop_basetimer(void *base_timer_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_stop_timer((stack_timer_struct*) base_timer_ptr);
}

/*****************************************************************************
*   Function 
*      uem_start_basetimer
*   DESCRIPTION
*      To start base timer.
*   PARAMETERS
*      base_timer_ptr   IN   
*      time_out   IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_start_basetimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_ptr      [?]         
 *  time_out            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_start_basetimer(void *base_timer_ptr, unsigned int time_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_start_timer((stack_timer_struct*) base_timer_ptr, 0, time_out);
}

/*****************************************************************************
*   Function 
*      uem_start_timer
*   DESCRIPTION
*      To start base timer.
*   PARAMETERS
*      base_timer_ptr   IN   
*      time_out   IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nTimerId                    [IN]        
 *  timer_expiry                [IN]        
 *  nTimeDurationInTicks        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_start_timer(kal_uint8 nTimerId, UEM_TIMER_FUNC_PRT timer_expiry, kal_uint32 nTimeDurationInTicks)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 temp = nTimeDurationInTicks / 10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp == 0)
    {
        temp = 1;
    }

    uem_timer_table[nTimerId].eventID = evshed_set_event(
                                            (event_scheduler*) event_scheduler_uem_ptr,
                                            (kal_timer_func_ptr) timer_expiry,
                                            (void*)nTimerId,
                                            (kal_uint32) (temp * KAL_TICKS_10_MSEC));
}

/*****************************************************************************
*   Function 
*      uem_stop_timer
*   DESCRIPTION
*      To start base timer.
*   PARAMETERS
*      base_timer_ptr   IN   
*      time_out   IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nTimerId        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_stop_timer(kal_uint8 nTimerId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (uem_timer_table[nTimerId].eventID != NULL)
    {
        evshed_cancel_event(
            (event_scheduler*) event_scheduler_uem_ptr,
            (eventid*) & (uem_timer_table[nTimerId].eventID));
    }
    uem_timer_table[nTimerId].eventID = NULL;
}

