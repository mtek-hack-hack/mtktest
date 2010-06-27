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
 * aud_melody.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes voice memo related functions of audio manager task.
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

/******************************************************************
 * MODULE
 *    AUD_VM
 * DESCRIPTION
 *    This module defines the voice memo related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =======*/

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
#include "gpio_sw.h"
#include "alerter_sw.h"
#include "device.h"
#include "resource_audio.h"
#include "custom_equipment.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
/* for FAT FS */
#include "fat_fs.h"
/* DRM_REPLACE */
#include "drm_gprot.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_main.h"
#include "aud_main.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
/* -- added for turn on/off backlight by MMI task -- */
#include "mmiapi_struct.h"
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 

#include "aud_daf_parser.h"

/*==== IMPORTS =======*/
#define AMR_HEADER   "#!AMR\n"
#define AWB_HEADER   "#!AMR-WB\n"

#define MAX_MELODY_DIR 20
#define MELODY_FULL_NAME (MAX_MELODY_FILE_NAME+MAX_MELODY_DIR)
#define CRESCENDO_STEPS  4

static kal_uint16 max_melody_volume1;

/* /static kal_uint16 max_melody_volume2; */
static kal_uint16 current_melody_volume1;

/* /static kal_uint16 current_melody_volume2; */
static kal_uint16 melody_volume_step1;

/* /static kal_uint16 melody_volume_step2; */

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
/* -- added for turn on/off backlight by MMI task -- */
#define CTRL_BACKLIGHT_REQ_IDLE 0
#define CTRL_BACKLIGHT_REQ_WAIT 1
#define CTRL_BACKLIGHT_REQ_WAIT_CLOSE 2
#define CTRL_BACKLIGHT_REQ_CLOSE 3
static kal_uint8 backlight_ctrl_state = CTRL_BACKLIGHT_REQ_IDLE;
static kal_bool backlight_ctrl_in_use = KAL_FALSE;
static volatile kal_mutexid backlight_ctrl_mutex;
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 

#ifdef __MMI_SUPPORT_LED_SYNC__
/* -- added for turn on/off led by MMI task -- */
static kal_uint8 wait_for_led_ctrl_rsp = 0;
static volatile kal_mutexid led_ctrl_mutex;
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 

kal_uint8 current_playing_melody_volume_level = 0;  /* this variable will keep track of current playing melody volume level */

#if defined(TV_OUT_SUPPORT)
extern kal_bool audio_tv_cable_in;
extern kal_bool audio_tv_loud_speaker;
#endif

#ifdef __MED_BT_A2DP_MOD__
#if defined(__BTMTK__)
extern void aud_bt_a2dp_open_codec(kal_int32 audio_format);
extern kal_bool aud_bt_a2dp_is_mute_phone(void);
#endif
#endif /* __MED_BT_A2DP_MOD__ */ 


/*****************************************************************************
 * FUNCTION
 *  aud_melody_init
 * DESCRIPTION
 *  This function is used to init aud_melody module
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_melody_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->vibrator_enabled = KAL_TRUE;
    aud_context_p->vibrator_on = KAL_FALSE;
    aud_context_p->led_on = KAL_FALSE;
    aud_context_p->backlight_on = KAL_TRUE;

    aud_context_p->vibrator_on_stored = KAL_FALSE;
    aud_context_p->led_on_stored = KAL_FALSE;
    aud_context_p->backlight_on_stored = KAL_TRUE;

    aud_context_p->source_type = AUD_UNKNOWN_SOURCE_TYPE;
    aud_context_p->media_playing = KAL_FALSE;
    aud_context_p->audio_id = 255;
    aud_context_p->string_p = NULL;

    custom_get_fixed_imelody_range(&aud_context_p->min_fixed_imy_id, &aud_context_p->max_fixed_imy_id);
    custom_get_fixed_midi_range(&aud_context_p->min_fixed_midi_id, &aud_context_p->max_fixed_midi_id);
    custom_get_fixed_sound_range(&aud_context_p->min_fixed_sound_id, &aud_context_p->max_fixed_sound_id);
    custom_get_fixed_message_sound_range(
        &aud_context_p->min_fixed_message_sound_id,
        &aud_context_p->max_fixed_message_sound_id);

    /* create the a semaphore */
    aud_context_p->media_sem = kal_create_sem("MEDIA SEM", 1);

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
    backlight_ctrl_mutex = kal_create_mutex("backlight_ctrl_mutex");
#endif 
#ifdef __MMI_SUPPORT_LED_SYNC__
    led_ctrl_mutex = kal_create_mutex("led_ctrl_mutex");
#endif 
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_free_melody_file_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_free_melody_file_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->melody_string_p)
    {
        med_free_ext_mem((void **)&aud_context_p->melody_string_p);

        /* close file */
        if(aud_context_p->current_file_handle > 0)
        {
            DRM_close_file(aud_context_p->current_file_handle);
            aud_context_p->current_file_handle = -1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_vibrator_enabled_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_vibrator_enabled_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_vibrator_enabled_req_struct *msg_p =
        (media_aud_set_vibrator_enabled_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->vibrator_enabled = (kal_bool) msg_p->enabled;
}

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
/* -- added for turn on/off backlight by MMI task -- */


/*****************************************************************************
 * FUNCTION
 *  aud_backlight_ctrl_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_backlight_ctrl_rsp_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_backlight_control_rsp_struct *msg_p = (mmiapi_backlight_control_rsp_struct*) ilm_ptr->local_para_ptr;
    kal_bool on_off = (msg_p->on_off ? KAL_TRUE : KAL_FALSE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(backlight_ctrl_mutex);
    switch (backlight_ctrl_state)
    {
        case CTRL_BACKLIGHT_REQ_IDLE:
            ASSERT(0);
            break;
        case CTRL_BACKLIGHT_REQ_WAIT:
            if (on_off == aud_context_p->backlight_on)
            {
                backlight_ctrl_state = CTRL_BACKLIGHT_REQ_IDLE;
            }
            else
            {
                aud_send_backlight_ctrl_req(MOD_MMI, (kal_uint8) aud_context_p->backlight_on, 1);
            }
            break;
        case CTRL_BACKLIGHT_REQ_WAIT_CLOSE:
            aud_send_backlight_ctrl_req(MOD_MMI, (kal_uint8) aud_context_p->backlight_on, 0);
            backlight_ctrl_state = CTRL_BACKLIGHT_REQ_CLOSE;
            break;
        case CTRL_BACKLIGHT_REQ_CLOSE:
            if (on_off == aud_context_p->backlight_on)
            {
                backlight_ctrl_state = CTRL_BACKLIGHT_REQ_IDLE;
            }
            else
            {
                ASSERT(0);
            }
            break;
    }
    kal_give_mutex(backlight_ctrl_mutex);
}
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 

#ifdef __MMI_SUPPORT_LED_SYNC__
/* -- added for turn on/off led by MMI task -- */


/*****************************************************************************
 * FUNCTION
 *  aud_led_ctrl_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_led_ctrl_rsp_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_led_control_rsp_struct *msg_p = (mmiapi_led_control_rsp_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(led_ctrl_mutex);
    if (msg_p->on_off)
    {
        /* MMI responses that it finishs turning on led request */
        if (!aud_context_p->led_on)
        {
            aud_send_led_ctrl_req(MOD_MMI, 0);  /* request to turn off led */
            wait_for_led_ctrl_rsp = 1;
        }
        else
        {
            wait_for_led_ctrl_rsp = 0;
        }
    }
    else
    {
        /* MMI responses that it finishs turning off led request */
        if (aud_context_p->led_on)
        {
            aud_send_led_ctrl_req(MOD_MMI, 1);  /* request to turn on led */
            wait_for_led_ctrl_rsp = 1;
        }
        else
        {
            wait_for_led_ctrl_rsp = 0;
        }
    }
    kal_give_mutex(led_ctrl_mutex);
}
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__


/*****************************************************************************
 * FUNCTION
 *  aud_melody_imy_close_backlight_ctrl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_imy_close_backlight_ctrl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(backlight_ctrl_mutex);
    /* -- added for turn on/off backlight by MMI task -- */
    if (backlight_ctrl_state == CTRL_BACKLIGHT_REQ_IDLE)
    {
        if (backlight_ctrl_in_use)
        {
            aud_send_backlight_ctrl_req(MOD_MMI, 1, 0);
            backlight_ctrl_state = CTRL_BACKLIGHT_REQ_CLOSE;
        }
    }
    else if (backlight_ctrl_state != CTRL_BACKLIGHT_REQ_CLOSE)
    {
        backlight_ctrl_state = CTRL_BACKLIGHT_REQ_WAIT_CLOSE;
    }
    backlight_ctrl_in_use = KAL_FALSE;
    aud_context_p->backlight_on = KAL_TRUE;
    kal_give_mutex(backlight_ctrl_mutex);
}
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 


/*****************************************************************************
 * FUNCTION
 *  aud_melody_stop_driver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_stop_driver(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_L1SP, "IMY vibrator: enabled = %d, on = %d", aud_context_p->vibrator_enabled, KAL_FALSE);
    if (aud_context_p->vibrator_enabled)
    {
        if (aud_context_p->vibrator_on)
        {
            custom_cfg_gpio_set_level(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
            aud_context_p->vibrator_on = KAL_FALSE;
        }
    }

    /* turn off led, if on */
#ifndef __MMI_SUPPORT_LED_SYNC__
    if (aud_context_p->led_on)
    {
        custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);
        aud_context_p->led_on = KAL_FALSE;
    }
#else /* __MMI_SUPPORT_LED_SYNC__ */ 
    kal_take_mutex(led_ctrl_mutex);
    if (aud_context_p->led_on)
    {
        /* -- added for turn on/off led by MMI task -- */
        if (!wait_for_led_ctrl_rsp)
        {
            aud_send_led_ctrl_req(MOD_MMI, 1);
            wait_for_led_ctrl_rsp = 1;
        }
        aud_context_p->led_on = KAL_FALSE;
    }
    kal_give_mutex(led_ctrl_mutex);
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 

#ifndef __MMI_SUPPORT_BACKLIGHT_SYNC__
    if (!aud_context_p->backlight_on)
    {
        custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL5);
    }
    aud_context_p->backlight_on = KAL_TRUE;
#else /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
    aud_melody_imy_close_backlight_ctrl();
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_imy_vibrator_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_imy_vibrator_hdlr(kal_bool on)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_L1SP, "IMY vibrator: enabled = %d, on = %d", aud_context_p->vibrator_enabled, on);
    if (aud_context_p->vibrator_enabled)
    {
        if (on)
        {
            custom_cfg_gpio_set_level(GPIO_DEV_VIBRATOR, VIBRATOR_ON);
        }
        else
        {
            custom_cfg_gpio_set_level(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
        }
        aud_context_p->vibrator_on = on;
    }

#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_imy_led_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_imy_led_hdlr(kal_bool on)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SUPPORT_LED_SYNC__
    if (on)
    {
        custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL5);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL5);
    }
    else
    {
        custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);
    }
    aud_context_p->led_on = on;
#else /* __MMI_SUPPORT_LED_SYNC__ */ 
    kal_take_mutex(led_ctrl_mutex);
    /* -- added for turn on/off led by MMI task -- */
    if (!wait_for_led_ctrl_rsp)
    {
        aud_send_led_ctrl_req(MOD_MMI, (kal_uint8) on);
        wait_for_led_ctrl_rsp = 1;
    }
    aud_context_p->led_on = on;
    kal_give_mutex(led_ctrl_mutex);
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_imy_backlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_imy_backlight_hdlr(kal_bool on)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SUPPORT_BACKLIGHT_SYNC__
    if (on)
    {
        custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL5);
    }
    else
    {
        custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL2);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL2);
        custom_cfg_gpio_set_level(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);
    }
    aud_context_p->backlight_on = on;
#else /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
    kal_take_mutex(backlight_ctrl_mutex);
    /* -- added for turn on/off backlight by MMI task -- */
    if (backlight_ctrl_state == CTRL_BACKLIGHT_REQ_IDLE)
    {
        aud_send_backlight_ctrl_req(MOD_MMI, (kal_uint8) on, 1);
    }
    backlight_ctrl_state = CTRL_BACKLIGHT_REQ_WAIT;
    backlight_ctrl_in_use = KAL_TRUE;
    aud_context_p->backlight_on = on;
    kal_give_mutex(backlight_ctrl_mutex);
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_store_driver_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_store_driver_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->vibrator_on_stored = aud_context_p->vibrator_on;

#ifdef __MMI_SUPPORT_LED_SYNC__
    kal_take_mutex(led_ctrl_mutex);
    aud_context_p->led_on_stored = aud_context_p->led_on;
    kal_give_mutex(led_ctrl_mutex);
#else /* __MMI_SUPPORT_LED_SYNC__ */ 
    aud_context_p->led_on_stored = aud_context_p->led_on;
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
    kal_take_mutex(backlight_ctrl_mutex);
    aud_context_p->backlight_on_stored = aud_context_p->backlight_on;
    kal_give_mutex(backlight_ctrl_mutex);
#else /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
    aud_context_p->backlight_on_stored = aud_context_p->backlight_on;
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_restore_driver_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_restore_driver_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_melody_imy_vibrator_hdlr(aud_context_p->vibrator_on_stored);
    aud_melody_imy_led_hdlr(aud_context_p->led_on_stored);
    aud_melody_imy_backlight_hdlr(aud_context_p->backlight_on_stored);
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_create_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the dir exists, open it ,otherwise create it */
    file_handle = FS_Open(L"z:\\def_sound", FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        result = FS_CreateDir(L"z:\\def_sound");
        ASSERT(result >= 0);
    }
    else
    {
        FS_Close(file_handle);
    }

    /* if the dir exists, open it ,otherwise create it */
    file_handle = FS_Open(L"z:\\def_sound\\imelody", FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        result = FS_CreateDir(L"z:\\def_sound\\imelody");
        ASSERT(result >= 0);
    }
    else
    {
        FS_Close(file_handle);
    }

    /* if the dir exists, open it ,otherwise create it */
    file_handle = FS_Open(L"z:\\def_sound\\other", FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        result = FS_CreateDir(L"z:\\def_sound\\other");
        ASSERT(result >= 0);
    }
    else
    {
        FS_Close(file_handle);
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_startup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_melody_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* aud_melody_create_folder(); */
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_set_max_swing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  max_swing       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_set_max_swing(kal_uint16 max_swing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_VALUE_TRACE(max_swing, -1, -1);
    Media_Control(MEDIA_CTRL_MAX_SWING, max_swing);

}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_set_output_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_set_output_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_MELODY, device, -1);
    Media_SetOutputDevice(device);
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_set_volume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_MEDIA, volume1, digital_gain_index);
    Media_SetOutputVolume(volume1, digital_gain_index);

}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_set_output_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_melody_volume1 = (kal_uint16) volume1;
    /* /max_melody_volume2 = (kal_uint16)volume2; */
    aud_melody_set_volume(volume1, digital_gain_index);
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_active_ring_tone_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_active_ring_tone_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* incoming call ring, alarm, message use the same volume */
    kal_uint8 gain_audio_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store playing melody volume level */
    current_playing_melody_volume_level = aud_get_volume_level(aud_context_p->audio_mode, AUD_VOLUME_MEDIA);
    /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
    if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
        aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
    {
        gain_audio_mode = VOL_NORMAL;
    }
#if defined(TV_OUT_SUPPORT)
    /* TV out is on, and audio output to TV only */
    else if (audio_tv_cable_in && 
             !audio_tv_loud_speaker &&
             aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
    {
        gain_audio_mode = VOL_TV_OUT;
    }
#endif
    else
    {
        gain_audio_mode = aud_context_p->audio_mode;
    }


    aud_set_melody_volume(gain_audio_mode, current_playing_melody_volume_level);
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_active_sound_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_active_sound_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* power on/off, cover on/off use the same volume */
    /* the volume gain is for sound, but the volume level is tied with keytone's */
    kal_uint8 volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    volume = aud_get_volume_gain(
                aud_context_p->audio_mode,
                AUD_VOLUME_FMR,
                aud_get_volume_level(aud_context_p->audio_mode, VOL_TYPE_GMI));
    aud_melody_set_volume(volume, 0);

}


/*****************************************************************************
 * FUNCTION
 *  aud_get_active_device_path_by_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  request_path      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_active_device_path_by_mode(kal_uint8 request_path, void (*set_path_func)(kal_uint8))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 device;
#if defined(TV_OUT_SUPPORT)
    kal_uint8 output_path;
#endif    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(set_path_func != NULL);

    /* Check if play to both path when SCO connected, or just output to BT earphone */
#ifdef __MED_BT_AUDIO_VIA_SCO__
    if (aud_bt_hfp_is_audio_path_on())
    {
        if(request_path == AUDIO_DEVICE_SPEAKER_BOTH)
        {
            device = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER);
            set_path_func(device);            
        }
        else
        {
            set_path_func(0);
        }
        return;
    }
#endif /* #ifdef __BT_AUDIO_VIA_SCO__ */
    
    if (aud_context_p->audio_mode == AUD_MODE_HEADSET)
    {
        device = custom_cfg_hw_aud_output_path(request_path);
        set_path_func(device);
    }
    else /* AUD_MODE_NORMAL, AUD_MODE_LOUDSPK */
    {
    #if defined(TV_OUT_SUPPORT)
    #ifdef __MED_BT_A2DP_MOD__
    #if defined(__BTMTK__)
    	if (!aud_bt_a2dp_is_mute_phone())
    #endif
    #endif /* __MED_BT_A2DP_MOD__ */ 
        {
            if (audio_tv_cable_in)
            {
                /* Set output path to both TV out and mobile device */
                if(audio_tv_loud_speaker || request_path == AUDIO_DEVICE_SPEAKER_BOTH)
                {
                    output_path = AUDIO_DEVICE_SPEAKER_BOTH;
                }
                else  /* Set output path to earphone to let it play through TV only. */
                {
                    output_path = AUDIO_DEVICE_SPEAKER2;
                }
            }
            else
            {
                output_path = AUDIO_DEVICE_LOUDSPEAKER;
            }

            device = custom_cfg_hw_aud_output_path(output_path);
            set_path_func(device);
        }
    #endif /* #if defined(TV_OUT_SUPPORT) */        
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_crescendo_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_crescendo_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_melody_volume1 += melody_volume_step1;
    /* /current_melody_volume2+= melody_volume_step2; */

    current_melody_volume1 = MIN(current_melody_volume1, max_melody_volume1);
    /* /current_melody_volume2 = MIN(current_melody_volume2, max_melody_volume2); */

    /* /aud_melody_set_volume((kal_uint8)current_melody_volume1, (kal_uint8)current_melody_volume2); */
    aud_melody_set_volume((kal_uint8) current_melody_volume1, 0);

    if (current_melody_volume1 < max_melody_volume1)
        /* /|| current_melody_volume2<max_melody_volume2) */
    {
        med_start_timer(AUD_TIMER_CRESCENDO, AUD_TIMER_PERIOD, aud_melody_crescendo_hdlr, 0);
    }
    else
    {
        med_stop_timer(AUD_TIMER_CRESCENDO);
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_stop_crescendo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_stop_crescendo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_stop_timer(AUD_TIMER_CRESCENDO);
    /* /aud_melody_set_volume((kal_uint8)max_melody_volume1, (kal_uint8)max_melody_volume2); */
    aud_melody_set_volume((kal_uint8) max_melody_volume1, 0);

}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_start_crescendo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  play_style      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_start_crescendo(kal_uint8 play_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (play_style == DEVICE_AUDIO_PLAY_CRESCENDO)
    {
        if (current_melody_volume1 < max_melody_volume1)
        {
            med_stop_timer(AUD_TIMER_CRESCENDO);
            med_start_timer(AUD_TIMER_CRESCENDO, AUD_TIMER_PERIOD, aud_melody_crescendo_hdlr, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_play_style_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  play_style      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_melody_play_style_convert(kal_uint8 play_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 l1sp_play_style = 1;  /* AUDIO_PLAY_ONCE; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (play_style)
    {
            /* Play sound for crescendo */
        case DEVICE_AUDIO_PLAY_CRESCENDO:
            l1sp_play_style = 0;    /* AUDIO_PLAY_CRESCENDO; */
            if (max_melody_volume1 >= CRESCENDO_STEPS)
            {
                melody_volume_step1 = max_melody_volume1 / CRESCENDO_STEPS;
                /* / melody_volume_step2 = max_melody_volume2/CRESCENDO_STEPS; */
                current_melody_volume1 = melody_volume_step1;
                /* / current_melody_volume2 = melody_volume_step2; */
                med_start_timer(AUD_TIMER_CRESCENDO, AUD_TIMER_PERIOD, aud_melody_crescendo_hdlr, 0);
            }
            else
            {
                melody_volume_step1 = 0;
                /* /melody_volume_step2 = 0; */
                current_melody_volume1 = max_melody_volume1;
                /* / current_melody_volume2 = max_melody_volume2; */
            }
            /* /aud_melody_set_volume((kal_uint8)current_melody_volume1, (kal_uint8)current_melody_volume2); */
            aud_melody_set_volume((kal_uint8) current_melody_volume1, 0);
            break;
            /* Play sound for repeat. */
        case DEVICE_AUDIO_PLAY_INFINITE:
            l1sp_play_style = 0;    /* AUDIO_PLAY_INFINITE; */
            break;
            /* Play sound for once. */
        case DEVICE_AUDIO_PLAY_ONCE:
            l1sp_play_style = 1;    /* AUDIO_PLAY_ONCE; */
            break;
        default:
            break;
    }

    return l1sp_play_style;

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_play_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_play_event_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_media_play_event_ind_struct *ind_p = (aud_media_play_event_ind_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->last_seq_no != ind_p->seq_no ||
        (aud_context_p->state != AUD_MEDIA_PLAY && aud_context_p->state != AUD_MEDIA_PLAY_PAUSED))
    {
        AUD_VALUE_TRACE(ind_p->seq_no, aud_context_p->last_seq_no, aud_context_p->state);
        return;
    }

    switch (ind_p->event)
    {
        case MEDIA_END:
            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            //aud_melody_stop_driver(); /*Stop immediately in L1audio callback*/

            /* aud_context_p->source_type== AUD_FILE */

    #ifdef __MED_MMA_MOD__
            aud_melody_close_handle();
    #endif 
            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);

            /* free file buffer */
            aud_free_melody_file_buffer();

            if (aud_context_p->play_mode == AUD_MEDIA_PLAY_AS_RING)
            {
                aud_send_audio_play_finish_ind(MED_RES_END_OF_FILE);
            }
            else
            {
                aud_send_media_play_finish_ind(MED_RES_END_OF_FILE);
            }

            break;
        case MEDIA_ERROR:

        #ifdef __MED_MMA_MOD__
            aud_melody_close_handle();
        #endif 
            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);

            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);

            /* not for iMelody, so ... */
            aud_melody_stop_driver();

            /* free file buffer */
            aud_free_melody_file_buffer();

            if (aud_context_p->source_type == AUD_FILE && aud_context_p->play_mode == AUD_MEDIA_PLAY_AS_SONG)
            {
                aud_send_media_play_finish_ind(MED_RES_ERROR);
            }
            else
            {
                aud_send_audio_play_finish_ind(MED_RES_ERROR);
            }
            break;
        case MEDIA_TERMINATED:
            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);

            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);

            /* not for iMelody, so ... */
            aud_melody_stop_driver();
            break;
        case MEDIA_DATA_REQUEST:
        case MEDIA_DATA_NOTIFICATION:
            break;
        default:
            /* not for iMelody, so ... */
            break;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_ievent_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]         
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_ievent_callback(Media_Handle *handle, Media_Event event)
{
#ifdef __MED_MMA_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event == MEDIA_EXTENDED_EVENT)
    {
        kal_int32 note;

        while ((event = JSmf_QueryExtEvent(handle, &note)) != MEDIA_NONE)
        {
            kal_prompt_trace(MOD_L1SP, "ExtEVT GetQ: %d", note);
            switch (event)
            {
                case MEDIA_LED_ON:
                    kal_prompt_trace(MOD_L1SP, "ExtEVT LED ON: %d", note);
                    aud_melody_imy_led_hdlr(KAL_TRUE);
                    break;
                case MEDIA_LED_OFF:
                    kal_prompt_trace(MOD_L1SP, "ExtEVT LED OFF: %d", note);
                    aud_melody_imy_led_hdlr(KAL_FALSE);
                    break;
                case MEDIA_VIBRATOR_ON:
                    kal_prompt_trace(MOD_L1SP, "ExtEVT VIBRATOR ON: %d", note);
                    aud_melody_imy_vibrator_hdlr(KAL_TRUE);
                    break;
                case MEDIA_VIBRATOR_OFF:
                    kal_prompt_trace(MOD_L1SP, "ExtEVT VIBRATOR OFF: %d", note);
                    aud_melody_imy_backlight_hdlr(KAL_FALSE);
                    break;
                case MEDIA_BACKLIGHT_ON:
                    kal_prompt_trace(MOD_L1SP, "ExtEVT BACKLIGHT ON: %d", note);
                    aud_melody_imy_backlight_hdlr(KAL_TRUE);
                    break;
                case MEDIA_BACKLIGHT_OFF:
                    kal_prompt_trace(MOD_L1SP, "ExtEVT BACKLIGHT OFF: %d", note);
                    aud_melody_imy_backlight_hdlr(KAL_FALSE);
                    break;
            }
        }
    }
    else
#endif /* __MED_MMA_MOD__ */ 
        aud_media_event_callback(event);
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_event_callback(Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_media_play_event_ind_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_L1SP, "aud_media_event_callback: event=[%d]", event);

    switch (event)
    {
        case MEDIA_LED_ON:
            aud_melody_imy_led_hdlr(KAL_TRUE);
            return;
        case MEDIA_LED_OFF:
            aud_melody_imy_led_hdlr(KAL_FALSE);
            return;
        case MEDIA_VIBRATOR_ON:
            aud_melody_imy_vibrator_hdlr(KAL_TRUE);
            return;
        case MEDIA_VIBRATOR_OFF:
            aud_melody_imy_vibrator_hdlr(KAL_FALSE);
            return;
        case MEDIA_BACKLIGHT_ON:
            aud_melody_imy_backlight_hdlr(KAL_TRUE);
            return;
        case MEDIA_BACKLIGHT_OFF:
            aud_melody_imy_backlight_hdlr(KAL_FALSE);
            return;
        case MEDIA_REPEATED:
            aud_melody_stop_driver();
            return;
        case MEDIA_TERMINATED:
            return;
        case MEDIA_END:
        case MEDIA_ERROR:
            aud_melody_stop_driver();
            break;
        default:
            break;
    }
    ind_p = (aud_media_play_event_ind_struct*) construct_local_para(sizeof(aud_media_play_event_ind_struct), TD_CTRL);

    ind_p->src_id = aud_context_p->src_id;
    ind_p->event = event;
    ind_p->seq_no = aud_context_p->last_seq_no;

    aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_PLAY_EVENT_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_play_imy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  len             [IN]        
 *  play_style      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_melody_play_imy(kal_uint8 *data, kal_uint32 len, kal_uint8 play_style)
{
#ifdef __MED_MMA_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_iMelody_Param *imy_param_p;
    Media_Status status = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((aud_context_p->last_handle = JImy_Open(aud_media_ievent_callback, &imy_param_p)) != NULL)
    {
        aud_context_p->current_file_handle = -1;
        imy_param_p->imyfile = (const kal_uint8*)data;
        imy_param_p->filesize = len;
        imy_param_p->repeats = aud_melody_play_style_convert(play_style);
        imy_param_p->default_instrument = IMY_DEFAULT_INSTRUMENT;
    #ifdef __MED_BT_A2DP_MOD__
    #if defined(__BTMTK__)
	    aud_bt_a2dp_open_codec(MED_TYPE_IMELODY);
    #endif
    #endif /* __MED_BT_A2DP_MOD__ */
        if ((status = JImy_Play(aud_context_p->last_handle)) == MEDIA_SUCCESS)
        {
            /* enter AUD_MEDIA_PLAY state */
            AUD_ENTER_STATE(AUD_MEDIA_PLAY);
        }
        else
        {
            JImy_Close(aud_context_p->last_handle);
            aud_context_p->last_handle = NULL;
            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);
        }
    }
    else
    {
        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);
    }
#else /* __MED_MMA_MOD__ */ 
    Media_iMelody_Param msp;
    Media_Status status = MEDIA_FAIL;

    msp.imyfile = (const kal_uint8*)data;
    msp.filesize = len;
    msp.repeats = aud_melody_play_style_convert(play_style);
    msp.default_instrument = IMY_DEFAULT_INSTRUMENT;

    Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
    if ((status = Media_Play((Media_Format) MED_TYPE_IMELODY, aud_media_event_callback, &msp)) == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY state */
        AUD_ENTER_STATE(AUD_MEDIA_PLAY);
    }
    else
    {
        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);
    }
#endif /* __MED_MMA_MOD__ */ 

    AUD_VALUE_TRACE(status, -1, -1);

    return aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_play_smf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  len             [IN]        
 *  play_style      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_melody_play_smf(kal_uint8 *data, kal_uint32 len, kal_uint8 play_style)
{
#ifdef __MED_MMA_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_SMF_Param *smf_param_p;
    Media_Status status = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((aud_context_p->last_handle = JSmf_Open(aud_media_ievent_callback, &smf_param_p)) != NULL)
    {
        aud_context_p->current_file_handle = -1;
        smf_param_p->smffile = (const kal_uint8*)data;
        smf_param_p->filesize = len;
        smf_param_p->repeats = aud_melody_play_style_convert(play_style);
    #ifdef __MED_BT_A2DP_MOD__
    #if defined(__BTMTK__)
	    aud_bt_a2dp_open_codec(MED_TYPE_SMF);
    #endif
    #endif /* __MED_BT_A2DP_MOD__ */ 
        if ((status = JSmf_Play(aud_context_p->last_handle)) == MEDIA_SUCCESS)
        {
            /* enter AUD_MEDIA_PLAY state */
            AUD_ENTER_STATE(AUD_MEDIA_PLAY);
        }
        else
        {
            JSmf_Close(aud_context_p->last_handle);
            aud_context_p->last_handle = NULL;
            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);
        }
    }
    else    /* free file buffer */
    {
        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);
    }
#else /* __MED_MMA_MOD__ */ 
    Media_SMF_Param msp;
    Media_Status status = MEDIA_FAIL;

    msp.smffile = (const kal_uint8*)data;
    msp.filesize = len;
    msp.repeats = aud_melody_play_style_convert(play_style);

    Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
    if ((status = Media_Play((Media_Format) MED_TYPE_SMF, aud_media_event_callback, &msp)) == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY state */
        AUD_ENTER_STATE(AUD_MEDIA_PLAY);
    }
    else
    {
        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);
    }
#endif /* __MED_MMA_MOD__ */ 

    AUD_VALUE_TRACE(status, -1, -1);

    return aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_play_mmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  len             [IN]        
 *  play_style      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_melody_play_mmf(kal_uint8 *data, kal_uint32 len, kal_uint8 play_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status status = MEDIA_FAIL;

#if !defined(__MED_MMA_MOD__)
    Media_MMF_Param msp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msp.mmffile = (const kal_uint8*)data;
    msp.filesize = len;
    msp.repeats = aud_melody_play_style_convert(play_style);

    // #ifdef SW_SYN_16K
    Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
    // #endif
    if ((status = Media_Play((Media_Format) MED_TYPE_MMF, aud_media_event_callback, &msp)) == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY state */
        AUD_ENTER_STATE(AUD_MEDIA_PLAY);
    }
    else
    {
        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);
    }
#endif /* !defined(__MED_MMA_MOD__) */

    AUD_VALUE_TRACE(status, -1, -1);

    return aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_play_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_id                [IN]        
 *  play_style              [IN]        
 *  audio_out_device        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_play_by_id(kal_uint8 audio_id, kal_uint8 play_style, kal_uint8 audio_out_device)
{
#ifndef MED_MODEM
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 rel_audio_id;
    kal_int32 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->source_type = AUD_ID;
    aud_context_p->audio_id = audio_id;
    aud_context_p->play_style = play_style;
    aud_context_p->start_offset = aud_context_p->end_offset = 0;

    /* set to the volume of ringtone */
    aud_set_active_ring_tone_volume();
    /* long imelody for incoming call and alarm */
    if ((audio_id >= aud_context_p->min_fixed_imy_id) && (audio_id <= aud_context_p->max_fixed_imy_id))
    {
        rel_audio_id = audio_id - aud_context_p->min_fixed_imy_id;
        aud_context_p->current_format = resource_imelodys[rel_audio_id].format;
        aud_context_p->string_p = (kal_uint8*) resource_imelodys[rel_audio_id].data;
        aud_context_p->buf_len = resource_imelodys[rel_audio_id].len;
    }
    /* long midi for incoming call and alarm */
    else if ((audio_id >= aud_context_p->min_fixed_midi_id) && (audio_id <= aud_context_p->max_fixed_midi_id))
    {
        rel_audio_id = audio_id - aud_context_p->min_fixed_midi_id;
        aud_context_p->current_format = resource_midis[rel_audio_id].format;
        aud_context_p->string_p = (kal_uint8*) resource_midis[rel_audio_id].data;
        aud_context_p->buf_len = resource_midis[rel_audio_id].len;
    }
    /* short sound for cover open/close, power on/off */
    else if ((audio_id >= aud_context_p->min_fixed_sound_id) && (audio_id <= aud_context_p->max_fixed_sound_id))
    {
        rel_audio_id = audio_id - aud_context_p->min_fixed_sound_id;
        aud_context_p->current_format = resource_sounds[rel_audio_id].format;
        aud_context_p->string_p = (kal_uint8*) resource_sounds[rel_audio_id].data;
        aud_context_p->buf_len = resource_sounds[rel_audio_id].len;
    }
    /* short sound for message */
    else if ((audio_id >= aud_context_p->min_fixed_message_sound_id) &&
             (audio_id <= aud_context_p->max_fixed_message_sound_id))
    {

        rel_audio_id = audio_id - aud_context_p->min_fixed_message_sound_id;
        aud_context_p->current_format = resource_message_sounds[rel_audio_id].format;
        aud_context_p->string_p = (kal_uint8*) resource_message_sounds[rel_audio_id].data;
        aud_context_p->buf_len = resource_message_sounds[rel_audio_id].len;
    }
    /* short sound for EMS */
    else if ((audio_id >= MIN_EMS_SND_ID) && (audio_id <= MAX_EMS_SND_ID))
    {
        rel_audio_id = audio_id - MIN_EMS_SND_ID;
        aud_context_p->current_format = resource_ems_sounds[rel_audio_id].format;
        aud_context_p->string_p = (kal_uint8*) resource_ems_sounds[rel_audio_id].data;
        aud_context_p->buf_len = resource_ems_sounds[rel_audio_id].len;
    }
    else
    {
        aud_send_audio_play_finish_ind(MED_RES_ERROR);
        return;
    }

    switch (aud_context_p->current_format)
    {
        case MED_TYPE_SMF:
            res = aud_melody_play_smf(aud_context_p->string_p, aud_context_p->buf_len, play_style);
            break;
        case MED_TYPE_IMELODY:
            res = aud_melody_play_imy(aud_context_p->string_p, aud_context_p->buf_len, play_style);
            break;
        case MED_TYPE_MMF:
            res = aud_melody_play_mmf(aud_context_p->string_p, aud_context_p->buf_len, play_style);
            break;

        case MED_TYPE_GSM_FR:
        case MED_TYPE_GSM_HR:
        case MED_TYPE_GSM_EFR:
    #ifdef AMR_DECODE
        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
    #endif /* AMR_DECODE */ 
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:
    #endif 
    #endif /* DAF_DECODE */ 
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_G711_ALAW:
        case MED_TYPE_G711_ULAW:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
    #ifdef AU_DECODE
        case MED_TYPE_AU:
    #endif
    #ifdef AIFF_DECODE
        case MED_TYPE_AIFF:
    #endif
    #ifdef AAC_DECODE
        case MED_TYPE_AAC:
    #endif 
    #ifdef WMA_DECODE
        case MED_TYPE_WMA:
    #endif 
    #if defined(AAC_DECODE)
        case MED_TYPE_M4A:
    #endif 
            res = aud_media_play_byte_stream(aud_context_p->string_p, aud_context_p->buf_len, play_style);
            break;

        default:
            res = MED_RES_INVALID_FORMAT;
            break;
    }
    if (res != MED_RES_OK)
    {
        aud_send_audio_play_finish_ind(MED_RES_OK);
    }
#endif /*MED_MODEM*/
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_play_by_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string          [?]         
 *  play_style      [IN]        
 *  string_len      [IN]        
 *  format          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_melody_play_by_string(kal_uint8 *string, kal_uint8 play_style, kal_uint32 string_len, kal_uint8 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->source_type = AUD_STRING;
    aud_context_p->current_format = format;
    aud_context_p->string_p = string;
    aud_context_p->buf_len = string_len;

    /* set to the volume of ringtone */
    aud_set_active_ring_tone_volume();

    switch (aud_context_p->current_format)
    {
        case MED_TYPE_SMF:
            res = aud_melody_play_smf(aud_context_p->string_p, aud_context_p->buf_len, play_style);
            break;
        case MED_TYPE_IMELODY:
            res = aud_melody_play_imy(aud_context_p->string_p, aud_context_p->buf_len, play_style);
            break;
        case MED_TYPE_MMF:
            res = aud_melody_play_mmf(aud_context_p->string_p, aud_context_p->buf_len, play_style);
            break;

        case MED_TYPE_GSM_FR:
        case MED_TYPE_GSM_HR:
        case MED_TYPE_GSM_EFR:
    #ifdef AMR_DECODE
        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
    #endif /* AMR_DECODE */ 
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:
    #endif 
    #endif  /* DAF_DECODE */
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_G711_ALAW:
        case MED_TYPE_G711_ULAW:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
    #ifdef AU_DECODE
        case MED_TYPE_AU:
    #endif
    #ifdef AIFF_DECODE
        case MED_TYPE_AIFF:
    #endif
    #ifdef AAC_DECODE
        case MED_TYPE_AAC:
    #endif 
    #ifdef WMA_DECODE
        case MED_TYPE_WMA:
    #endif 
    #if defined(AAC_DECODE)
        case MED_TYPE_M4A:
    #endif 
            res = aud_media_play_byte_stream(aud_context_p->string_p, aud_context_p->buf_len, play_style);
            break;

        default:
            res = MED_RES_ERROR;
            break;
    }
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_play_by_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name               [?]         
 *  play_style              [IN]        
 *  audio_out_device        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_melody_play_by_name(kal_wchar *file_name, kal_uint8 play_style, kal_uint8 audio_out_device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* open the file */
    kal_int16 format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MELODY_PLAY_BY_NAME);

    aud_context_p->source_type = AUD_FILE;

    format = med_get_media_type(file_name);

    /* set to the volume of ringtone */
    aud_set_active_ring_tone_volume();

    aud_context_p->current_file_handle = DRM_open_file(file_name, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_NOBUSY_CHECK_MODE, DRM_PERMISSION_PLAY);

    if (aud_context_p->current_file_handle >= 0)
    {
        kal_uint32 len;
        kal_uint32 buf_len;
        kal_int32 result;

        aud_context_p->audio_end = KAL_FALSE;

        result = DRM_file_size(aud_context_p->current_file_handle, &buf_len);
        if (!(result == FS_NO_ERROR && buf_len > 0))
        {
            DRM_close_file(aud_context_p->current_file_handle);
            aud_context_p->current_file_handle = -1;
            return MED_RES_BAD_FORMAT;
        }
        else if (buf_len > AUD_MELODY_BUFFER_LEN)
        {
            DRM_close_file(aud_context_p->current_file_handle);
            aud_context_p->current_file_handle = -1;            
            return MED_RES_MEM_INSUFFICIENT;
        }
        aud_context_p->melody_string_p = med_alloc_ext_mem(buf_len);
        if (aud_context_p->melody_string_p == NULL)
        {
            DRM_close_file(aud_context_p->current_file_handle);
            aud_context_p->current_file_handle = -1;            
            return MED_RES_MEM_INSUFFICIENT;
        }

        /* read data from file to buffer */
        DRM_read_file(aud_context_p->current_file_handle, aud_context_p->melody_string_p, buf_len, &len);

        /* close the file after play finish */
        //DRM_close_file(aud_context_p->current_file_handle);

        if (len == 0)
        {
            /* free file buffer */
            aud_free_melody_file_buffer();
            return MED_RES_BAD_FORMAT;
        }
        else
        {
            switch (format)
            {
                case MED_TYPE_IMELODY:
                {
                #ifdef __MED_MMA_MOD__
                    Media_iMelody_Param *imy_param_p;
                    Media_Status status = MEDIA_FAIL;

                    if ((aud_context_p->last_handle = JImy_Open(aud_media_ievent_callback, &imy_param_p)) != NULL)
                    {
                        imy_param_p->imyfile = (const kal_uint8*)aud_context_p->melody_string_p;
                        imy_param_p->filesize = len;
                        imy_param_p->repeats = aud_melody_play_style_convert(play_style);
                        imy_param_p->default_instrument = IMY_DEFAULT_INSTRUMENT;
                        JImy_SetStartTime(aud_context_p->last_handle, (kal_int32) aud_context_p->start_offset);
                    #ifdef __MED_BT_A2DP_MOD__
                    #if defined(__BTMTK__)
                	    aud_bt_a2dp_open_codec((kal_int32)format);
                    #endif
                    #endif /* __MED_BT_A2DP_MOD__ */ 
                        if ((status = JImy_Play(aud_context_p->last_handle)) == MEDIA_SUCCESS)
                        {
                            /* enter AUD_MEDIA_PLAY state */
                            AUD_ENTER_STATE(AUD_MEDIA_PLAY);
                        }
                        else
                        {
                            JImy_Close(aud_context_p->last_handle);
                            aud_context_p->last_handle = NULL;
                            /* free file buffer */
                            aud_free_melody_file_buffer();
                            /* stop volume crescendo timer */
                            med_stop_timer(AUD_TIMER_CRESCENDO);
                        }
                    }
                    else
                    {
                        /* free file buffer */
                        aud_free_melody_file_buffer();

                        /* stop volume crescendo timer */
                        med_stop_timer(AUD_TIMER_CRESCENDO);
                    }
                #else /* __MED_MMA_MOD__ */ 
                    Media_iMelody_Param msp;
                    Media_Status status = MEDIA_FAIL;

                    msp.imyfile = (const kal_uint8*)aud_context_p->melody_string_p;
                    msp.filesize = len;
                    msp.repeats = aud_melody_play_style_convert(play_style);
                    msp.default_instrument = IMY_DEFAULT_INSTRUMENT;
                    Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
                    if ((status = Media_Play((Media_Format) MED_TYPE_IMELODY, aud_media_event_callback, &msp)) == MEDIA_SUCCESS)
                    {
                        /* enter AUD_MEDIA_PLAY state */
                        AUD_ENTER_STATE(AUD_MEDIA_PLAY);
                    }
                    else
                    {
                        /* free file buffer */
                        aud_free_melody_file_buffer();

                        /* stop volume crescendo timer */
                        med_stop_timer(AUD_TIMER_CRESCENDO);
                    }
                #endif /* __MED_MMA_MOD__ */ 

                    AUD_VALUE_TRACE(status, -1, -1);

                    return aud_get_res((kal_uint8) status);
                }
                case MED_TYPE_SMF:
                {
                #ifdef __MED_MMA_MOD__
                    Media_SMF_Param *smf_param_p;
                    Media_Status status = MEDIA_FAIL;

                    if ((aud_context_p->last_handle = JSmf_Open(aud_media_ievent_callback, &smf_param_p)) != NULL)
                    {
                        smf_param_p->smffile = (const kal_uint8*)aud_context_p->melody_string_p;
                        smf_param_p->filesize = len;
                        smf_param_p->repeats = aud_melody_play_style_convert(play_style);
                        JSmf_SetStartTime(aud_context_p->last_handle, (kal_int32) aud_context_p->start_offset);
                    #ifdef __MED_BT_A2DP_MOD__
                    #if defined(__BTMTK__)
                	    aud_bt_a2dp_open_codec((kal_int32)format);
                    #endif
                    #endif /* __MED_BT_A2DP_MOD__ */ 
                        if ((status = JSmf_Play(aud_context_p->last_handle)) == MEDIA_SUCCESS)
                        {
                            /* enter AUD_MEDIA_PLAY state */
                            AUD_ENTER_STATE(AUD_MEDIA_PLAY);
                        }
                        else
                        {
                            JSmf_Close(aud_context_p->last_handle);
                            aud_context_p->last_handle = NULL;
                            /* free file buffer */
                            aud_free_melody_file_buffer();
                            /* stop volume crescendo timer */
                            med_stop_timer(AUD_TIMER_CRESCENDO);
                        }
                    }
                    else
                    {
                        /* free file buffer */
                        aud_free_melody_file_buffer();

                        /* stop volume crescendo timer */
                        med_stop_timer(AUD_TIMER_CRESCENDO);
                    }
                #else /* __MED_MMA_MOD__ */ 
                    Media_SMF_Param msp;
                    Media_Status status = MEDIA_FAIL;

                    msp.smffile = (const kal_uint8*)aud_context_p->melody_string_p;
                    msp.filesize = len;
                    msp.repeats = aud_melody_play_style_convert(play_style);
                    Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
                    if ((status = Media_Play((Media_Format) format, aud_media_event_callback, &msp)) == MEDIA_SUCCESS)
                    {
                        /* enter AUD_MEDIA_PLAY state */
                        AUD_ENTER_STATE(AUD_MEDIA_PLAY);
                    }
                    else
                    {
                        /* free file buffer */
                        aud_free_melody_file_buffer();

                        /* stop volume crescendo timer */
                        med_stop_timer(AUD_TIMER_CRESCENDO);
                    }
                #endif /* __MED_MMA_MOD__ */ 

                    AUD_VALUE_TRACE(status, -1, -1);

                    return aud_get_res((kal_uint8) status);
                }
                case MED_TYPE_MMF:
                {
                    Media_Status status = MEDIA_FAIL;
                    
                #if !defined(__MED_MMA_MOD__)
                    Media_MMF_Param mmp;

                    mmp.mmffile = (const kal_uint8*)aud_context_p->melody_string_p;
                    mmp.filesize = len;
                    mmp.repeats = aud_melody_play_style_convert(play_style);
                    Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
                    if ((status = Media_Play((Media_Format) format, aud_media_event_callback, &mmp)) == MEDIA_SUCCESS)
                    {
                        /* enter AUD_MEDIA_PLAY state */
                        AUD_ENTER_STATE(AUD_MEDIA_PLAY);
                    }
                    else
                    {
                        /* free file buffer */
                        aud_free_melody_file_buffer();

                        /* stop volume crescendo timer */
                        med_stop_timer(AUD_TIMER_CRESCENDO);
                    }
                #endif /* !defined(__MED_MMA_MOD__) */ 

                    AUD_VALUE_TRACE(status, -1, -1);

                    return aud_get_res((kal_uint8) status);
                }
                default:
                {
                    /* free file buffer */
                    aud_free_melody_file_buffer();
                    return MED_RES_INVALID_FORMAT;
                }
            }

        }

    }
    else
    {
        return MED_RES_OPEN_FILE_FAIL;
    }
}

#ifdef __MED_MMA_MOD__

/*****************************************************************************
 * FUNCTION
 *  aud_melody_get_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name               [IN]         
 *  duration                [OUT]        
 * RETURNS
 * 
 *****************************************************************************/
kal_uint8 aud_melody_get_duration(kal_wchar *file_name, kal_uint8 *aud_data, kal_uint32 aud_len, kal_int16 format, kal_uint32* duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fileHandle = NULL;
    kal_uint32 len;
    kal_uint32 buf_len;
    kal_int32 result;
    kal_uint8 med_result = MED_RES_FAIL;
    kal_uint8 *melody_string_p;
    kal_bool from_file = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(aud_data != NULL)
    {
        melody_string_p = aud_data;
        len = aud_len;
        from_file = KAL_FALSE;
    }
    else
    {
        fileHandle = DRM_open_file(file_name, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_NOBUSY_CHECK_MODE, DRM_PERMISSION_PLAY);
        if(fileHandle >= 0)
        {
            result = DRM_file_size(fileHandle, &buf_len);
            if (!(result == FS_NO_ERROR && buf_len > 0))
            {
                DRM_close_file(fileHandle);
                return MED_RES_BAD_FORMAT;
            }
            else if (buf_len > AUD_MELODY_BUFFER_LEN)
            {
                DRM_close_file(fileHandle);
                return MED_RES_MEM_INSUFFICIENT;
            }
            melody_string_p = med_alloc_ext_mem(buf_len);
            if (melody_string_p == NULL)
            {
                DRM_close_file(fileHandle);
                return MED_RES_MEM_INSUFFICIENT;
            }
            DRM_read_file(fileHandle, melody_string_p, buf_len, &len);
            DRM_close_file(fileHandle);

            if (len == 0)
            {
                /* free file buffer */
                med_free_ext_mem((void **)&melody_string_p);
                return MED_RES_BAD_FORMAT;
            }
        }        
        else
        {
            return MED_RES_OPEN_FILE_FAIL;
        }
    }

    switch (format)
    {
        case MED_TYPE_IMELODY:
        {
            Media_iMelody_Param *imy_param_p;
            Media_Handle *last_handle;
            kal_int32 imy_duration;
            
            if ((last_handle = JImy_Open(aud_media_ievent_callback, &imy_param_p)) != NULL)
            {
                imy_param_p->imyfile = (const kal_uint8*)melody_string_p;
                imy_param_p->filesize = len;
                imy_param_p->repeats = 1 ; /*1 stands for not repeat*/
                imy_param_p->default_instrument = IMY_DEFAULT_INSTRUMENT;
                imy_duration = JImy_GetDuration(last_handle);
                JImy_Close(last_handle);
                last_handle = NULL;                            
                if(imy_duration < 0)
                {
                    *duration = 0;
                    med_result = MED_RES_FAIL;
                }
                else
                {
                    *duration = (kal_uint32)imy_duration;
                    med_result = MED_RES_OK ;
                }
            }
            else
            {
                med_result = MED_RES_OPEN_FILE_FAIL;
            }
        }
        break;
        case MED_TYPE_SMF:
        {
            kal_int32 temp_duration;
            temp_duration = JSmf_GetMidiDuration((const kal_uint8*)melody_string_p);
            if(temp_duration < 0)
            {
                *duration = 0 ;
                med_result = MED_RES_FAIL ;
            }
            else
            {
                *duration =  temp_duration;
                med_result = MED_RES_OK ;
            }
        }
        break;
        default:
            med_result = MED_RES_INVALID_FORMAT;
            break;
    }

    if(from_file)
    {
        med_free_ext_mem((void **)&melody_string_p);
    }
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_restore_by_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name               [?]         
 *  play_style              [IN]        
 *  audio_out_device        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_melody_restore_by_name(kal_wchar *file_name, kal_uint8 play_style, kal_uint8 audio_out_device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* open the file */
    kal_int16 format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MELODY_PLAY_BY_NAME);

    aud_context_p->source_type = AUD_FILE;

    format = med_get_media_type(file_name);

    /* set to the volume of ringtone */
    aud_set_active_ring_tone_volume();

    aud_context_p->current_file_handle = DRM_open_file(file_name, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_NOBUSY_CHECK_MODE, DRM_PERMISSION_PLAY);

    if (aud_context_p->current_file_handle >= 0)
    {
        kal_uint32 len;
        kal_uint32 buf_len;
        kal_int32 result;

        aud_context_p->audio_end = KAL_FALSE;

        result = DRM_file_size(aud_context_p->current_file_handle, &buf_len);
        if (!(result == FS_NO_ERROR && buf_len > 0))
        {
            DRM_close_file(aud_context_p->current_file_handle);
            aud_context_p->current_file_handle = -1;
            return MED_RES_OPEN_FILE_FAIL;
        }
        else if (buf_len > AUD_MELODY_BUFFER_LEN)
        {
            DRM_close_file(aud_context_p->current_file_handle);
            aud_context_p->current_file_handle = -1;
            return MED_RES_MEM_INSUFFICIENT;
        }
        aud_context_p->melody_string_p = med_alloc_ext_mem(buf_len);
        if (aud_context_p->melody_string_p == NULL)
        {
            DRM_close_file(aud_context_p->current_file_handle);
            aud_context_p->current_file_handle = -1;
            return MED_RES_MEM_INSUFFICIENT;
        }

        /* read data from file to buffer */
        DRM_read_file(aud_context_p->current_file_handle, aud_context_p->melody_string_p, buf_len, &len);

        /* close the file after play finish */
        //DRM_close_file(aud_context_p->current_file_handle);

        if (len == 0)
        {
            /* free file buffer */
            aud_free_melody_file_buffer();
            return MED_RES_OPEN_FILE_FAIL;
        }
        else
        {
            switch (format)
            {
                case MED_TYPE_IMELODY:
                {
                    Media_iMelody_Param *imy_param_p;
                    Media_Status status = MEDIA_FAIL;

                    if ((aud_context_p->last_handle = JImy_Open(aud_media_ievent_callback, &imy_param_p)) != NULL)
                    {
                        imy_param_p->imyfile = (const kal_uint8*)aud_context_p->melody_string_p;
                        imy_param_p->filesize = len;
                        imy_param_p->repeats = aud_melody_play_style_convert(play_style);
                        imy_param_p->default_instrument = IMY_DEFAULT_INSTRUMENT;
                        JImy_SetStartTime(aud_context_p->last_handle, (kal_int32) aud_context_p->last_time);
                    #ifdef __MED_BT_A2DP_MOD__
                    #if defined(__BTMTK__)
                	    aud_bt_a2dp_open_codec((kal_int32)format);
                    #endif
                    #endif /* __MED_BT_A2DP_MOD__ */ 
                        if ((status = JImy_Play(aud_context_p->last_handle)) == MEDIA_SUCCESS)
                        {
                            /* enter AUD_MEDIA_PLAY state */
                            AUD_ENTER_STATE(AUD_MEDIA_PLAY);
                        }
                        else
                        {
                            JImy_Close(aud_context_p->last_handle);
                            aud_context_p->last_handle = NULL;
                            /* free file buffer */
                            aud_free_melody_file_buffer();
                            /* stop volume crescendo timer */
                            med_stop_timer(AUD_TIMER_CRESCENDO);
                        }
                    }
                    else
                    {
                        /* free file buffer */
                        aud_free_melody_file_buffer();
                        /* stop volume crescendo timer */
                        med_stop_timer(AUD_TIMER_CRESCENDO);
                    }
                    AUD_VALUE_TRACE(status, -1, -1);

                    return aud_get_res((kal_uint8) status);
                }
                case MED_TYPE_SMF:
                {
                    Media_SMF_Param *smf_param_p;
                    Media_Status status = MEDIA_FAIL;

                    if ((aud_context_p->last_handle = JSmf_Open(aud_media_ievent_callback, &smf_param_p)) != NULL)
                    {
                        smf_param_p->smffile = (const kal_uint8*)aud_context_p->melody_string_p;
                        smf_param_p->filesize = len;
                        smf_param_p->repeats = aud_melody_play_style_convert(play_style);
                        JSmf_SetStartTime(aud_context_p->last_handle, (kal_int32) aud_context_p->last_time);
                    #ifdef __MED_BT_A2DP_MOD__
                    #if defined(__BTMTK__)
                	    aud_bt_a2dp_open_codec((kal_int32)format);
                    #endif
                    #endif /* __MED_BT_A2DP_MOD__ */ 
                        if ((status = JSmf_Play(aud_context_p->last_handle)) == MEDIA_SUCCESS)
                        {
                            /* enter AUD_MEDIA_PLAY state */
                            AUD_ENTER_STATE(AUD_MEDIA_PLAY);
                        }
                        else
                        {
                            JSmf_Close(aud_context_p->last_handle);
                            aud_context_p->last_handle = NULL;
                            /* free file buffer */
                            aud_free_melody_file_buffer();
                            /* stop volume crescendo timer */
                            med_stop_timer(AUD_TIMER_CRESCENDO);
                        }
                    }
                    else
                    {
                        /* free file buffer */
                        aud_free_melody_file_buffer();
                        /* stop volume crescendo timer */
                        med_stop_timer(AUD_TIMER_CRESCENDO);
                    }
                    AUD_VALUE_TRACE(status, -1, -1);

                    return aud_get_res((kal_uint8) status);
                }
                default:
                {
                    /* free file buffer */
                    aud_free_melody_file_buffer();
                    return MED_RES_INVALID_FORMAT;
                }
            }

        }

    }
    else
    {
        return MED_RES_OPEN_FILE_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
Media_Status aud_melody_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aud_context_p->current_format)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_SMF_SND:
            ASSERT(aud_context_p->last_handle != NULL);
            result = JSmf_Pause(aud_context_p->last_handle);
            break;
        case MED_TYPE_IMELODY:
            ASSERT(aud_context_p->last_handle != NULL);
            result = JImy_Pause(aud_context_p->last_handle);
            break;
        default:
            result = Media_Pause();
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
Media_Status aud_melody_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aud_context_p->current_format)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_SMF_SND:
            ASSERT(aud_context_p->last_handle != NULL);
        #if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
            aud_bt_a2dp_open_codec((kal_int32)aud_context_p->current_format);
        #endif
            result = JSmf_Resume(aud_context_p->last_handle);
            break;
        case MED_TYPE_IMELODY:
            ASSERT(aud_context_p->last_handle != NULL);
        #if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
            aud_bt_a2dp_open_codec((kal_int32)aud_context_p->current_format);
        #endif
            result = JImy_Resume(aud_context_p->last_handle);
            break;
        default:
            result = Media_Resume();
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_close_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_close_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->last_handle == NULL)
    {
        return;
    }
    switch (aud_context_p->current_format)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_SMF_SND:
            JSmf_Close(aud_context_p->last_handle);
            aud_context_p->last_handle = NULL;
            break;
        case MED_TYPE_IMELODY:
            JImy_Close(aud_context_p->last_handle);
            aud_context_p->last_handle = NULL;
            break;
    }
}

#endif /* __MED_MMA_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

