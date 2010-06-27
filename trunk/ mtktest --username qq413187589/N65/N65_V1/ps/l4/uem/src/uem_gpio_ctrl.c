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
 * uem_gpio_ctrl.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for control LED/LCM/Vibrator pattern.
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

/***************************************************************************** 
* Include
*****************************************************************************/
#define NEW_FRAME
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "kal_trace.h"

#include "stdio.h"
#include "l1audio.h"
#include "melody.h"
#include "rtc_sw.h"
#include "gpio_sw.h"
#include "keypad_sw.h"
#include "device.h"
#include "pwic.h"
#include "fat_fs.h"
#include "med_struct.h"

#include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#include "custom_led_patterns.h"
#include "custom_equipment.h"

#include "uem_context.h"
#include "uem_gpio_ctrl.h"
#include "uem_trc.h"
#include "uem_utility.h"
#include "uem_msg_hdlr.h"
#include "uem_proc_msg.h"

/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern void MMICheckDiskDisplay(void);

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void uem_play_led_pattern_callback(void *ptr);
static void uem_play_lcd_pattern_callback(void *ptr);
static void uem_play_vib_pattern_callback(void *ptr);
static void uem_play_led_pattern(void);
static void uem_play_lcd_pattern(void);
static void uem_play_vib_pattern(void);
static void uem_set_led_level(kal_uint8 led_id, kal_uint8 level);
static void uem_set_lcd_level(kal_uint8 lcd_id, kal_uint8 level);
static void uem_set_vib_level(kal_uint8 vib_id, kal_uint8 level);
static void uem_stop_led_level(kal_uint8 led_id);
static void uem_stop_lcd_level(kal_uint8 lcd_id);
static void uem_stop_vib_level(kal_uint8 vib_id);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static kal_uint8 led_ptn_idx = 0, lcd_ptn_idx = 0, vib_ptn_idx = 0;
static PATTERN_TYPE led_ptn_type = PLAY_ONCE, lcd_ptn_type = PLAY_ONCE, vib_ptn_type = PLAY_ONCE;

static const LED_PATTERN_STRUCT *led_play_pattern;
static const LCD_PATTERN_STRUCT *lcd_play_pattern;
static const VIB_PATTERN_STRUCT *vib_play_pattern;

/***************************************************************************** 
****************************************************************************** 
* External Funcations 
******************************************************************************
******************************************************************************/
/*****************************************************************************
*   Function 
*      uem_play_pattern
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
 *  uem_play_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pattern_id          [IN]        
 *  pattern_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool uem_play_pattern(PATTERN_ID pattern_id, PATTERN_TYPE pattern_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool res = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* out of range */
    if ((pattern_type > MAX_PATTERN_TYPE) || (pattern_id > MAX_PATTERN_ID))
    {
        ASSERT(0);
    }

    /* play stop */
    if (pattern_type == PLAY_STOP)
    {
        uem_stop_pattern(pattern_id);
        return KAL_TRUE;
    }

    /* play LED pattern */
    if (pattern_id <= LED_PATTERN_END)  /* pattern_id always >= LED_PATTERN_BEGIN */
    {
        /* always to stop previous */
        uem_stop_pattern(pattern_id);

        led_play_pattern = custom_get_led_patterns(pattern_id);
        led_ptn_type = pattern_type;

        uem_play_led_pattern();

        res = KAL_TRUE;
    }
    /* play LCD backlight pattern */
    else if ((pattern_id >= LCD_PATTERN_BEGIN) && (pattern_id <= LCD_PATTERN_END))
    {
        /* always to stop previous */
        uem_stop_pattern(pattern_id);
        lcd_play_pattern = custom_get_lcd_patterns(pattern_id);
        lcd_ptn_type = pattern_type;
        uem_play_lcd_pattern();

        res = KAL_TRUE;
    }
    /* play vibrator pattern */
    else if ((pattern_id >= VIB_PATTERN_BEGIN) && (pattern_id <= VIB_PATTERN_END))
    {
        /* always to stop previous */
        uem_stop_pattern(pattern_id);
        vib_play_pattern = custom_get_vib_patterns(pattern_id);
        vib_ptn_type = pattern_type;
        uem_play_vib_pattern();

        res = KAL_TRUE;
    }
    return res;
}

/*****************************************************************************
*   Function 
*      uem_stop_pattern
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
 *  uem_stop_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pattern_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool uem_stop_pattern(PATTERN_ID pattern_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool res = KAL_FALSE;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop timer */
    if (pattern_id <= LED_PATTERN_END)  /* pattern_id always >= LED_PATTERN_BEGIN */
    {
        led_ptn_idx = 0;
        uem_stop_timer(LED_EVENT_TIMER);
        for (i = 0; i < MAX_LED_GPIO; i++)
        {
            uem_stop_led_level(i);
        }
        res = KAL_TRUE;
    }
    else if ((pattern_id >= LCD_PATTERN_BEGIN) && (pattern_id <= LCD_PATTERN_END))
    {
        lcd_ptn_idx = 0;
        uem_stop_timer(LCD_EVENT_TIMER);
        for (i = 0; i < MAX_LCD_BACKLIGHT; i++)
        {
            uem_stop_lcd_level(i);
        }
        res = KAL_TRUE;
    }
    else if ((pattern_id >= VIB_PATTERN_BEGIN) && (pattern_id <= VIB_PATTERN_END))
    {
        vib_ptn_idx = 0;
        uem_stop_timer(VIB_EVENT_TIMER);
        for (i = 0; i < MAX_VIBRATOR; i++)
        {
            uem_stop_vib_level(i);
        }
        res = KAL_TRUE;
    }
    return res;
}

/***************************************************************************** 
****************************************************************************** 
* Local Funcations 
******************************************************************************
******************************************************************************/
/*****************************************************************************
*   Function 
*      uem_play_led_pattern_callback
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_led_pattern_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_led_pattern_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    led_ptn_idx++;
    uem_timer_table[LED_EVENT_TIMER].eventID = NULL;
    uem_play_led_pattern();
}

/*****************************************************************************
*   Function 
*      uem_play_led_pattern
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_led_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_led_pattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (led_ptn_idx == 0)
    {
        /* only one time */
        if (led_play_pattern[led_ptn_idx].duration_time == 0)
        {
            for (i = 0; i < MAX_LED_GPIO; i++)
            {
                uem_set_led_level(i, led_play_pattern[led_ptn_idx].gpio_control[i]);
            }
            return;
        }
    }

    for (i = 0; i < MAX_LED_GPIO; i++)
    {
        /* below is dummy function for led light control */
        uem_set_led_level(i, led_play_pattern[led_ptn_idx].gpio_control[i]);
    }

    /* start timer to do next pattern */
    if (led_play_pattern[led_ptn_idx].duration_time != 0)
    {
        uem_start_timer(LED_EVENT_TIMER, uem_play_led_pattern_callback, led_play_pattern[led_ptn_idx].duration_time);
    }
    else    /* end of pattern */
    {
        /* restart from base index 0 */
        led_ptn_idx = 0;
        if (led_ptn_type == PLAY_REPEAT)
        {
            uem_play_led_pattern();
        }
        else
        {
            /* no case to run */
        }
    }
}

/*****************************************************************************
*   Function 
*      uem_play_lcd_pattern_callback
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_lcd_pattern_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_lcd_pattern_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lcd_ptn_idx++;
    uem_timer_table[LCD_EVENT_TIMER].eventID = NULL;
    uem_play_lcd_pattern();
}

/*****************************************************************************
*   Function 
*      uem_play_lcd_pattern
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_lcd_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_lcd_pattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_ptn_idx == 0)
    {
        /* only one time */
        if (lcd_play_pattern[lcd_ptn_idx].duration_time == 0)
        {
            for (i = 0; i < MAX_LCD_BACKLIGHT; i++)
            {
                uem_set_lcd_level(i, lcd_play_pattern[lcd_ptn_idx].gpio_control[i]);
            }
            return;
        }
    }

    for (i = 0; i < MAX_LCD_BACKLIGHT; i++)
    {
        /* below is dummy function for led light control */
        uem_set_lcd_level(i, lcd_play_pattern[lcd_ptn_idx].gpio_control[i]);
    }

    if (lcd_play_pattern[lcd_ptn_idx].duration_time != 0)
    {
        uem_start_timer(LCD_EVENT_TIMER, uem_play_lcd_pattern_callback, lcd_play_pattern[lcd_ptn_idx].duration_time);
    }
    else    /* end of pattern */
    {
        /* restart from base index 0 */
        lcd_ptn_idx = 0;
        if (lcd_ptn_type == PLAY_REPEAT)
        {
            uem_play_lcd_pattern();
        }
        else
        {
            /* no case to run */
        }
    }
}

/*****************************************************************************
*   Function 
*      uem_play_vib_pattern_callback
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_vib_pattern_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_vib_pattern_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vib_ptn_idx++;
    uem_timer_table[VIB_EVENT_TIMER].eventID = NULL;
    uem_play_vib_pattern();
}

/*****************************************************************************
*   Function 
*      uem_play_lcd_pattern
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_vib_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_vib_pattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vib_ptn_idx == 0)
    {
        /* only one time */
        if (vib_play_pattern[vib_ptn_idx].duration_time == 0)
        {
            for (i = 0; i < MAX_VIBRATOR; i++)
            {
                uem_set_vib_level(i, vib_play_pattern[vib_ptn_idx].gpio_control[i]);
            }
            return;
        }
    }

    for (i = 0; i < MAX_VIBRATOR; i++)
    {
        /* below is dummy function for led light control */
        uem_set_vib_level(i, vib_play_pattern[vib_ptn_idx].gpio_control[i]);
    }

    if (vib_play_pattern[vib_ptn_idx].duration_time != 0)
    {
        uem_start_timer(VIB_EVENT_TIMER, uem_play_vib_pattern_callback, vib_play_pattern[vib_ptn_idx].duration_time);
    }
    else    /* end of pattern */
    {
        /* restart from base index 0 */
        vib_ptn_idx = 0;
        if (vib_ptn_type == PLAY_REPEAT)
        {
            uem_play_vib_pattern();
        }
        else
        {
            /* no case to run */
        }
    }
}

/*****************************************************************************
*   Function 
*      uem_set_led_level
*   DESCRIPTION
*      set led level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_led_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  led_id      [IN]        
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_led_level(kal_uint8 led_id, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_cfg_gpio_set_level(custom_get_led_label(led_id), level);
}

/*****************************************************************************
*   Function 
*      uem_set_lcd_level
*   DESCRIPTION
*      set lcd level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_lcd_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id      [IN]        
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_lcd_level(kal_uint8 lcd_id, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_cfg_gpio_set_level(custom_get_lcd_label(lcd_id), level);
}

/*****************************************************************************
*   Function 
*      uem_set_vib_level
*   DESCRIPTION
*      set lcd level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_vib_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vib_id      [IN]        
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_vib_level(kal_uint8 vib_id, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_cfg_gpio_set_level(custom_get_vib_label(vib_id), level);
}

/*****************************************************************************
*   Function 
*      uem_stop_led_level
*   DESCRIPTION
*      set led level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_stop_led_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  led_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_stop_led_level(kal_uint8 led_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_cfg_gpio_set_level(custom_get_led_label(led_id), 0);
}

/*****************************************************************************
*   Function 
*      uem_set_lcd_level
*   DESCRIPTION
*      set lcd level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_stop_lcd_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_stop_lcd_level(kal_uint8 lcd_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_cfg_gpio_set_level(custom_get_lcd_label(lcd_id), 0);
}

/*****************************************************************************
*   Function 
*      uem_set_vib_level
*   DESCRIPTION
*      set lcd level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_stop_vib_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vib_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_stop_vib_level(kal_uint8 vib_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_cfg_gpio_set_level(custom_get_vib_label(vib_id), 0);
}

