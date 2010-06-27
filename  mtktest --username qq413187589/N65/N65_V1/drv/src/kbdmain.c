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
 *    kbdmain.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the keypad task
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include 	"kal_release.h"
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"syscomp_config.h"
#include 	"task_config.h"
#include 	"stacklib.h"
#include    "stack_timer.h"      /*stack_timer_struct....definitions*/
#include 	"drv_comm.h"
#include    "reg_base.h"
#include    "keypad_hw.h"
#include    "keypad_sw.h"
#include    "gpt_sw.h"
#include    "intrCtrl.h"
#include    "kbd_table.h"   
#include    "drv_hisr.h"
#include    "gpio_sw.h"
#if defined(TOUCH_PAD_SUPPORT)
#include "touchpad_custom.h"
#endif
#include   "eint.h"

#if !defined(__KBD_JOYSTICK_SUPPORT__)
kbd_struct KBD;

#if defined(DRV_WDT_RESET_PKEY_RELEASE)
extern void DRV_RESET(void);
extern kal_uint8  TargetReset;
#endif   /*DRV_WDT_RESET_PKEY_RELEASE*/
    

/*************************************************************************
* Function declaration
 *************************************************************************/
kal_bool 	         kbd_create(comptask_handler_struct **handle);
kal_bool             send_kbdilm = KAL_TRUE;

kal_bool             kbd_push_assert = KAL_FALSE;
kal_bool             kbd_pop_assert = KAL_FALSE;

kbd_buffer_struct    kbd_buffer;
static kal_uint8     kbd_press_event_count;

#ifdef KBD_DETECT_ONLY_ONE_KEY
static   kal_uint8   key_save;
#else /*KBD_DETECT_ONLY_ONE_KEY*/
static kal_uint8     kbd_saved_pressed_key[KBD_KEY_DETECTION_CNT];
   #ifdef __KBD_2STEP_KEY_SUPPORT__
   static kal_bool     kbd_is_2steps_key;
   #endif
   static kal_uint8     kbd_ext_press_event_count;
#endif /*KBD_DETECT_ONLY_ONE_KEY*/

static void kbd_task_main(task_entry_struct *task_entry_ptr);
static kal_bool	kbd_task_reset(task_indx_type task_indx);
static kal_bool 	kbd_task_end(task_indx_type task_indx);

/*customize */
extern const keypad_customize_function_struct *keypad_GetFunc(void);
const keypad_customize_function_struct *keypadCustomFunc;
const keypad_struct *keypad_comm_def;
#if defined(TOUCH_PAD_SUPPORT)
kal_uint8 kbd_owner_stat = KBD_OWNER_NONE;
#endif
void keypad_customize_init(void)
{
   keypadCustomFunc=keypad_GetFunc();
   keypad_comm_def = keypadCustomFunc->keypad_Get_Data();
}   

/*************************************************************************
* FUNCTION                                                            
*	kbd_create
*
* DESCRIPTION                                                           
*	This function implements xyz entity's create handler.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
kbd_create(comptask_handler_struct **handle)
{
	static const comptask_handler_struct kbd_handler_info = 
	{
		kbd_task_main,			/* task entry function */
		NULL,		  	/* task initialization function */
		NULL, 	/* task configuration function */
		kbd_task_reset,		/* task reset handler */
		kbd_task_end			/* task termination handler */
	};

	*handle = (comptask_handler_struct *)&kbd_handler_info;
	return KAL_TRUE;
}

kal_bool Kbd_GetKeyData(kbd_data *keydata)
{
   kal_bool result;

   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   EINT_Mask(EINT_A_KEY);
   EINT_Mask(EINT_B_KEY);
   #endif
   IRQMask(IRQ_GPT_CODE);
   IRQMask(IRQ_KPAD_CODE);
   if (kbd_buffer.kbd_data_buffer_rindex != kbd_buffer.kbd_data_buffer_windex)
   {
      #ifdef TWO_KEY_ENABLE
         kbd_pop_twokey_from_kbdbuffer(keydata->Keyevent,keydata->Keydata[0],keydata->Keydata[1]);
      #else /*!TWO_KEY_ENABLE*/
         kbd_pop_onekey_from_kbdbuffer(keydata->Keyevent,keydata->Keydata[0]);
      #endif   /*TWO_KEY_ENABLE*/
      result = KAL_TRUE;
   }
   else
   {
      send_kbdilm = KAL_TRUE;
      result = KAL_FALSE;
   }
   
   IRQUnmask(IRQ_KPAD_CODE);
   IRQUnmask(IRQ_GPT_CODE);
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   EINT_UnMask(EINT_A_KEY);
   EINT_UnMask(EINT_B_KEY);
   #endif
   return result;
}

void KBDRepeatHandler(void *parameter)
{
   ilm_struct     *Kp_ilm;
   kal_uint8      roomleft;
#ifndef KBD_DETECT_ONLY_ONE_KEY
   kal_uint8      handle;
   kal_uint32      index;
   kal_uint8      key_event;
#endif
   
   IRQMask(IRQ_KPAD_CODE);
   
   kbdbuffer_get_roomleft(roomleft);
   #ifdef KBD_DBGMODE
      ASSERT(roomleft != 0);
   #endif

#ifndef KBD_DETECT_ONLY_ONE_KEY
   index = (kal_uint32)parameter;
   handle = KBD.gpthandle[index];
   #ifndef KBD_DBGMODE
      if (roomleft <= (kbd_press_event_count+kbd_ext_press_event_count))
      {
         GPTI_StartItem(handle,
                  KBD.repeat_time,
                  KBDRepeatHandler,
                  parameter);

         IRQUnmask(IRQ_KPAD_CODE);
         return;
      }
   #endif
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   if (index < KBD_KEY_DETECTION_CNT)
   {
   #endif
      key_event = kbd_saved_pressed_key[index];
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   }
   else
   {
      key_event = (index==KBD_KEY_DETECTION_CNT) ? DEVICE_KEY_EXT_A: DEVICE_KEY_EXT_B;
   }
   #endif
   kbd_push_onekey_to_kbdbuffer(kbd_onekey_repeated, key_event);
#else /* KBD_DETECT_ONLY_ONE_KEY */
   #ifndef KBD_DBGMODE
      if (roomleft == kbd_press_event_count)
      {
         GPTI_StartItem(KBD.gpthandle,
                     KBD.repeat_time,
                     KBDRepeatHandler,
                     NULL);

         IRQUnmask(IRQ_KPAD_CODE);
         return;
      }
   #endif   /*KBD_DBGMODE*/
   kbd_push_onekey_to_kbdbuffer(kbd_onekey_repeated,key_save);
#endif /* KBD_DETECT_ONLY_ONE_KEY */
   
   if (send_kbdilm)
   {
      send_kbdilm = KAL_FALSE;
#ifndef L4_NOT_PRESENT
      DRV_BuildPrimitive(Kp_ilm,
                         MOD_DRVKBD,
                         MOD_UEM,
                         MSG_ID_DRVUEM_KEYPAD_IND,
                         NULL);
   
      msg_send_ext_queue(Kp_ilm);
#endif   /*L4_NOT_PRESENT*/
   }
#ifndef KBD_DETECT_ONLY_ONE_KEY
   GPTI_StartItem(handle,
                  KBD.repeat_time,
                  KBDRepeatHandler,
                  parameter);
#else /* KBD_DETECT_ONLY_ONE_KEY */
   GPTI_StartItem(KBD.gpthandle,
                  KBD.repeat_time,
                  KBDRepeatHandler,
                  NULL);
#endif /* KBD_DETECT_ONLY_ONE_KEY */

   IRQUnmask(IRQ_KPAD_CODE);
}

void KBDTimeOutHandler(void *parameter)
{
   ilm_struct     *Kp_ilm;
   kal_uint8      roomleft;
#ifndef KBD_DETECT_ONLY_ONE_KEY
   kal_uint8      handle;
   kal_uint32      index;
   kal_uint8      key_event;
#endif   

   IRQMask(IRQ_KPAD_CODE);
   kbdbuffer_get_roomleft(roomleft);
   #ifdef KBD_DBGMODE
      ASSERT(roomleft != 0);
   #endif

#ifndef KBD_DETECT_ONLY_ONE_KEY
   index = (kal_uint32)parameter;
   handle = KBD.gpthandle[index];
   #ifndef KBD_DBGMODE
      if (roomleft <= (kbd_press_event_count+kbd_ext_press_event_count))
      {
         GPTI_StartItem(handle,
                  KBD.repeat_time,
                  KBDTimeOutHandler,
                  parameter);

         IRQUnmask(IRQ_KPAD_CODE);
         return;
      }
   #endif
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   if (index < KBD_KEY_DETECTION_CNT)
   {
   #endif
      key_event = kbd_saved_pressed_key[index];
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
   }
   else
   {
      key_event = (index==KBD_KEY_DETECTION_CNT) ? DEVICE_KEY_EXT_A: DEVICE_KEY_EXT_B;
   }
   #endif
   kbd_push_onekey_to_kbdbuffer(kbd_onekey_longpress, key_event);
#else /* KBD_DETECT_ONLY_ONE_KEY */
   #ifndef KBD_DBGMODE
      if (roomleft == kbd_press_event_count)
      {
         GPTI_StartItem(KBD.gpthandle,
                  KBD.repeat_time,
                  KBDTimeOutHandler,
                  NULL);

         IRQUnmask(IRQ_KPAD_CODE);
         return;
      }
   #endif   /*KBD_DBGMODE*/
   kbd_push_onekey_to_kbdbuffer(kbd_onekey_longpress,key_save);
#endif /* KBD_DETECT_ONLY_ONE_KEY */
   
   if (send_kbdilm)
   {
      send_kbdilm = KAL_FALSE;
#ifndef L4_NOT_PRESENT
      DRV_BuildPrimitive(Kp_ilm,
                         MOD_DRVKBD,
                         MOD_UEM,
                         MSG_ID_DRVUEM_KEYPAD_IND,
                         NULL);
   
      msg_send_ext_queue(Kp_ilm);
#endif   /*L4_NOT_PRESENT*/
   }
   
#ifndef KBD_DETECT_ONLY_ONE_KEY
   GPTI_StartItem(handle,
                  KBD.repeat_time,
                  KBDRepeatHandler,
                  parameter);
   IRQUnmask(IRQ_KPAD_CODE);
#else /* KBD_DETECT_ONLY_ONE_KEY */
   GPTI_StartItem(KBD.gpthandle,
                  KBD.repeat_time,
                  KBDRepeatHandler,
                  NULL);
   IRQUnmask(IRQ_KPAD_CODE);
#endif /* KBD_DETECT_ONLY_ONE_KEY */
}
#ifdef __KBD_2STEP_KEY_SUPPORT__
void KBD2KeyHandler(void *parameter)
{
   ilm_struct     *Kp_ilm;
   kal_uint8      roomleft;
   
   IRQMask(IRQ_KPAD_CODE);
   
   if(keypadCustomFunc->keypad_check_fullpress())
   {
      kbdbuffer_get_roomleft(roomleft);
      #ifdef KBD_DBGMODE
         ASSERT(roomleft != 0);
      #else
         #ifndef KBD_DETECT_ONLY_ONE_KEY
         if (roomleft <= (kbd_press_event_count+kbd_ext_press_event_count+1))
         {
            GPTI_StartItem(KBD.gpthandle[0],
                           10,
                           KBD2KeyHandler,
                           NULL);
         #else /* KBD_DETECT_ONLY_ONE_KEY */
         if (roomleft == kbd_press_event_count)
         {
            GPTI_StartItem(KBD.gpthandle,
                           10,
                           KBD2KeyHandler,
                           NULL);
      
         #endif /* KBD_DETECT_ONLY_ONE_KEY */
            IRQUnmask(IRQ_KPAD_CODE);
            return;
         }
      #endif   /*KBD_DBGMODE*/
      
      #ifndef KBD_DETECT_ONLY_ONE_KEY
         kbd_push_onekey_to_kbdbuffer(kbd_onekey_fullpress,kbd_saved_pressed_key[0]);
         /* start longpress timer after full press. */
		   GPTI_StartItem(KBD.gpthandle[0],
                        KBD.longpress_timeout,
                        KBDTimeOutHandler,
                        0);
      #else /* KBD_DETECT_ONLY_ONE_KEY */
         kbd_push_onekey_to_kbdbuffer(kbd_onekey_fullpress,key_save);
         /* start longpress timer after full press. */
		   GPTI_StartItem(KBD.gpthandle,
                        KBD.longpress_timeout,
                        KBDTimeOutHandler,
                        NULL);
      #endif /* KBD_DETECT_ONLY_ONE_KEY */
      if (send_kbdilm)
      {
         send_kbdilm = KAL_FALSE;
#ifndef L4_NOT_PRESENT
         DRV_BuildPrimitive(Kp_ilm,
                            MOD_DRVKBD,
                            MOD_UEM,
                            MSG_ID_DRVUEM_KEYPAD_IND,
                            NULL);
         
         msg_send_ext_queue(Kp_ilm);
#endif   /*L4_NOT_PRESENT*/
      }         
      GPTI_StopItem(KBD.kbd_2key_handle);                  
   }
   else
   {
      GPTI_StartItem(KBD.kbd_2key_handle,
                  10,
                  KBD2KeyHandler,
                  NULL);   
   }   
   
   IRQUnmask(IRQ_KPAD_CODE);
}
#endif

#ifndef KBD_DETECT_ONLY_ONE_KEY

#define KEY_INVALID		0xFF

/* To store keypad mode it is now. */
static kal_uint8  kbd_key_detection_mode = kbd_1_key_det_mode;
static kal_uint8  kbd_key_detection_new_mode = kbd_1_key_det_mode;

/*************************************************************************
* FUNCTION                                                            
*	kbd_key_det_mode_switch
*
* DESCRIPTION                                                           
*	This function is to switch to the one, two, or three keys detction mode.
*
* PARAMETERS
*  mode   - The mode to switch to
*
* RETURNS
*  KAL_TRUE   - Enable or disable two key dection mode successfully.
*  KAL_FALSE  - Already in the mode. No need to set. 
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool kbd_key_det_mode_switch(kbd_key_det_mode mode)
{
   if (mode == kbd_key_detection_mode)
      return KAL_FALSE;
#if defined(__TWO_KEY_DETECTION_SWITCHABLE__)
   if (mode > kbd_2_keys_det_mode)
      return KAL_FALSE;
#elif defined(__THREE_KEY_DETECTION_SWITCHABLE__)
   if (mode > kbd_3_keys_det_mode)
      return KAL_FALSE;
#endif
   kbd_key_detection_new_mode = mode;
   /* Set event to keypad task. */
   kal_set_eg_events(KBD.event,2,KAL_OR);
   return KAL_TRUE;
}

void kbd_task_main( task_entry_struct * task_entry_ptr )
{
   kal_uint32     event_group;
   kal_uint32     kbd_map_temp_reg;
#if defined(DRV_KBD_32KEYS_ABOVE)
   kal_uint32     kbd_map_temp_reg1;
#elif defined(DRV_KBD_64KEYS_ABOVE)
   kal_uint32     kbd_map_temp_reg1;
   kal_uint32     kbd_map_temp_reg2;
#endif   /*DRV_KBD_32KEYS_ABOVE*/
   kal_uint8      key_presscount;
   kal_uint8      key_releasecount;
   kal_uint8      key_index;
   kal_uint8      kbd_press_key[KBD_KEY_DETECTION_CNT];
   kal_uint8      kbd_release_key[KBD_KEY_DETECTION_CNT];
   ilm_struct     *Kp_ilm;
   kal_uint8      key_total_count;
   kal_uint8      roomleft;
   kal_uint8		end_press_count, end_release_count;
   kal_bool         buf_full;
   kal_uint8      array_idx;
   
   for (key_index = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++)
   {
      kbd_saved_pressed_key[key_index] = KEY_INVALID;
   }
#ifdef __KBD_2STEP_KEY_SUPPORT__
   kbd_is_2steps_key = KAL_FALSE;
#endif
   kbd_press_event_count = 0;
   buf_full = KAL_FALSE;
   while(1)
   {
      kal_retrieve_eg_events(KBD.event,3,KAL_OR_CONSUME
         ,&event_group,KAL_SUSPEND);
      
      #ifndef __PRODUCTION_RELEASE__
      ASSERT(kbd_press_event_count < (kbd_buffer_size/2));
      #endif

      /* Check if there's swtich mode request. */
      #ifdef KBD_DBGMODE
      if (event_group & 2)
      #else  /*KBD_DBGMODE*/
      if ((event_group & 2) || (buf_full == KAL_TRUE))
      #endif  /*KBD_DBGMODE*/
      {
         #ifdef __EXTRA_A_B_KEY_SUPPORT__
         EINT_Mask(EINT_A_KEY);
         EINT_Mask(EINT_B_KEY);
         #endif
         /* Stop all longpress or repeated timer. */
         for (key_index = 0; key_index < KBD_GPT_HDL_CNT; key_index++)
         {
            GPTI_StopItem(KBD.gpthandle[key_index]);
         }
         #ifdef __KBD_2STEP_KEY_SUPPORT__
            GPTI_StopItem(KBD.kbd_2key_handle);
            kbd_is_2steps_key = KAL_FALSE;
         #endif
         kbdbuffer_get_roomleft(roomleft);
         #ifdef KBD_DBGMODE
            ASSERT(roomleft >= (kbd_press_event_count+kbd_ext_press_event_count+1));
         #else  /*KBD_DBGMODE*/
         /* Buffer room left should more than reserved release key events and plus one 
            switch mode event. */
         if (roomleft <= (kbd_press_event_count+kbd_ext_press_event_count+1))
         {
            /* Not enough room, should wait. */
            buf_full = KAL_TRUE;
         }
         else
         {
            buf_full = KAL_FALSE;
         #endif   /*KBD_DBGMODE*/
            /* Compel to send key release event before mode switch. */
            for (key_index = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++)
            {
               if (kbd_saved_pressed_key[key_index] != KEY_INVALID)
                  kbd_push_onekey_to_kbdbuffer(kbd_onekey_release,kbd_saved_pressed_key[key_index]);
            }
            #ifdef __EXTRA_A_B_KEY_SUPPORT__
            if (kbd_key_detection_mode != kbd_1_key_det_mode)
            {
               if (KBD.ext_status[0] == LEVEL_LOW)
                  kbd_push_onekey_to_kbdbuffer(kbd_onekey_release,DEVICE_KEY_EXT_A);
               if (KBD.ext_status[1] == LEVEL_LOW)
                  kbd_push_onekey_to_kbdbuffer(kbd_onekey_release,DEVICE_KEY_EXT_B);
            }
            KBD.ext_status[0] = LEVEL_HIGH;
            KBD.ext_status[1] = LEVEL_HIGH;
            #endif
            /* Reset all key status. */
            kbd_press_event_count = 0;
            kbd_ext_press_event_count = 0;
            for (key_index = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++)
            {
               kbd_saved_pressed_key[key_index] = KEY_INVALID;
            }
            /* Push two key detection enable/disable event to key buffer. */
            if (kbd_key_detection_new_mode == kbd_1_key_det_mode)
            {
               kbd_push_onekey_to_kbdbuffer(kbd_multikey_detection_disable,0);
            }
            else if (kbd_key_detection_new_mode == kbd_2_keys_det_mode)
            {
               kbd_push_onekey_to_kbdbuffer(kbd_twokey_detection_enable,0);
               #ifdef __EXTRA_A_B_KEY_SUPPORT__
               EINT_Set_Polarity(EINT_A_KEY, LEVEL_LOW);
               EINT_Set_Polarity(EINT_B_KEY, LEVEL_LOW);
               #endif
            }
            #ifdef __THREE_KEY_DETECTION_SWITCHABLE__
            else if (kbd_key_detection_new_mode == kbd_3_keys_det_mode)
            {
               kbd_push_onekey_to_kbdbuffer(kbd_threekey_detection_enable,0);
               #ifdef __EXTRA_A_B_KEY_SUPPORT__
               EINT_Set_Polarity(EINT_A_KEY, LEVEL_LOW);
               EINT_Set_Polarity(EINT_B_KEY, LEVEL_LOW);
               #endif
            }
            #endif
            kbd_key_detection_mode = kbd_key_detection_new_mode;
         #ifndef KBD_DBGMODE
         } /* if (roomleft >= (kbd_press_event_count+1)) */
         #endif
         #ifdef __EXTRA_A_B_KEY_SUPPORT__
         EINT_UnMask(EINT_A_KEY);
         EINT_UnMask(EINT_B_KEY);
         #endif
      }
      /* Skip the codes beblow, if there's no any key detection interrupt. */
      if (!(event_group & 1))
         continue;

      key_total_count=0;
      end_press_count = 0;
      end_release_count = 0;
      
#if defined(DRV_KBD_32KEYS_EQ_BELOW) || defined(FPGA)
      kbd_map_temp_reg = ( ((kal_uint32)(DRV_Reg(KP_HI_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );

#if defined(TOUCH_PAD_SUPPORT)
#if defined(TOUCH_PAD_USE_KEY_COLUMN)
		#if defined(TOUCHPAD_DEBUG)		
		kal_prompt_trace(MOD_DRVKBD, "kbd_map_temp_reg=%x,kbd_map_temp_reg1=%x",kbd_map_temp_reg,kbd_map_temp_reg1);
		#endif
      // if some keypad key is pressed, the corresponding bit of key 
      // status register is changed from 1 to 0
      if (((kbd_map_temp_reg >> TOUCH_PAD_KEY_COLUMN_NUM) & 0x00000001) == 0) 
      {
           // reset each key status bit corresponding to the keypad column to 1 to 
           // prevent keypad status to be processed in the following general key press
         if (kbd_owner_stat == KBD_OWNER_KEYPAD)
         {
            kbd_map_temp_reg |= KEYPAD_SCANNER_REG;
            kbd_map_temp_reg1 |= KEYPAD_SCANNER_REG1;
         }
         TOUCHPAD_UART_PutBytes(TOUCHPAD_UART_PORT, 0x50);
         if (kbd_owner_stat != KBD_OWNER_KEYPAD)
         {
            if (kbd_owner_stat == KBD_OWNER_NONE)
               kbd_owner_stat = KBD_OWNER_TOUCHPAD;
            continue;
         }
      }
      else if (kbd_owner_stat == KBD_OWNER_TOUCHPAD)
         continue;

      #if defined(TOUCHPAD_DEBUG)		
      kal_prompt_trace(MOD_DRVKBD, "after change: kbd_map_temp_reg=%x,kbd_map_temp_reg1=%x",kbd_map_temp_reg,kbd_map_temp_reg1);
      #endif
#endif  /*  TOUCH_PAD_USE_KEY_COLUMN    */
#endif  /*  TOUCH_PAD_SUPPORT   */

      if (KBD.kbdmap_reg != kbd_map_temp_reg)
#elif defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
      kbd_map_temp_reg = ( ((kal_uint32)(DRV_Reg(KP_MID_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );
      #if defined(DRV_KBD_32KEYS_ABOVE)
      kbd_map_temp_reg1 = (kal_uint32)(DRV_Reg(KP_HI_KEY));
      #elif defined(DRV_KBD_64KEYS_ABOVE)
      kbd_map_temp_reg1 = ( ((kal_uint32)(DRV_Reg(KP_MID2_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_MID1_KEY))) );
      kbd_map_temp_reg2 = (kal_uint32)(DRV_Reg(KP_HI_KEY));
      #endif

#if defined(TOUCH_PAD_SUPPORT)
#if defined(TOUCH_PAD_USE_KEY_COLUMN)
		#if defined(TOUCHPAD_DEBUG)		
		kal_prompt_trace(MOD_DRVKBD, "kbd_map_temp_reg=%x,kbd_map_temp_reg1=%x",kbd_map_temp_reg,kbd_map_temp_reg1);
		#endif
      // if some keypad key is pressed, the corresponding bit of key 
      // status register is changed from 1 to 0
      if (((kbd_map_temp_reg >> TOUCH_PAD_KEY_COLUMN_NUM) & 0x00000001) == 0) 
      {
           // reset each key status bit corresponding to the keypad column to 1 to 
           // prevent keypad status to be processed in the following general key press
         if (kbd_owner_stat == KBD_OWNER_KEYPAD)
         {
            kbd_map_temp_reg |= KEYPAD_SCANNER_REG;
            kbd_map_temp_reg1 |= KEYPAD_SCANNER_REG1;
            #if defined(DRV_KBD_64KEYS_ABOVE)
            kbd_map_temp_reg2 |= KEYPAD_SCANNER_REG2;
            #endif
         }
         TOUCHPAD_UART_PutBytes(TOUCHPAD_UART_PORT, 0x50);
         if (kbd_owner_stat != KBD_OWNER_KEYPAD)
         {
            if (kbd_owner_stat == KBD_OWNER_NONE)
               kbd_owner_stat = KBD_OWNER_TOUCHPAD;
            continue;
         }
      }
      else if (kbd_owner_stat == KBD_OWNER_TOUCHPAD)
         continue;

	   #if defined(TOUCHPAD_DEBUG)		
	   kal_prompt_trace(MOD_DRVKBD, "after change: kbd_map_temp_reg=%x,kbd_map_temp_reg1=%x",kbd_map_temp_reg,kbd_map_temp_reg1);
	   #endif
#endif  /*  TOUCH_PAD_USE_KEY_COLUMN    */
#endif  /*  TOUCH_PAD_SUPPORT   */

      #if defined(DRV_KBD_32KEYS_ABOVE)
      if ((KBD.kbdmap_reg != kbd_map_temp_reg) || (KBD.kbdmap_reg1 != kbd_map_temp_reg1 ))
      #elif defined(DRV_KBD_64KEYS_ABOVE)
      if ((KBD.kbdmap_reg != kbd_map_temp_reg) || (KBD.kbdmap_reg1 != kbd_map_temp_reg1 ) || (KBD.kbdmap_reg2 != kbd_map_temp_reg2))
      #endif
#endif   /*DRV_KBD_32KEYS_EQ_BELOW,FPGA*//*DRV_KBD_32KEYS_ABOVE*/
      {
         key_presscount = 0;
         key_releasecount = 0;
         /*The first for loop is to check first 2 status register*/
#if defined(DRV_KBD_32KEYS_EQ_BELOW) || defined(FPGA)
         for(key_index=0;key_index<kbd_allkeys;key_index++)
#elif defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
         for(key_index=0;key_index<32;key_index++)
#endif   /*DRV_KBD_32KEYS_EQ_BELOW,FPGA*//*DRV_KBD_32KEYS_ABOVE*/
         {
            /* For each key position, if its status has changed. */
            if( (KBD.kbdmap_reg &(1<<key_index)) != (kbd_map_temp_reg &(1<<key_index)) )
            {
               /* If the key is pressed now.... */
               if (!(kbd_map_temp_reg &(1<<key_index)))
               {
                  if (key_presscount == 0)
                  {
                     /* Record the 1st pressed key event. */
                     kbd_press_key[0] = keypad_comm_def->keypad[key_index];
                     key_presscount = 1;
                  }
                  else if (key_presscount == 1)
                  {
                     if (kbd_press_key[0] != keypad_comm_def->keypad[key_index])
                     {
                        /* Record the 2nd pressed key event. */
                        if (kbd_key_detection_mode != kbd_1_key_det_mode)
						      kbd_press_key[1] = keypad_comm_def->keypad[key_index];
                        key_presscount = 2;
                     }
                  }
                  else if ((kbd_key_detection_mode != kbd_1_key_det_mode) && (key_presscount == 2))
                  {
                     /* More than 2 keys are pressed. */
                     if ((kbd_press_key[0] != keypad_comm_def->keypad[key_index])
                        && (kbd_press_key[1] != keypad_comm_def->keypad[key_index]))
                     {
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
                        /* Record the 3rd pressed key event if in 3 keys detection mode. */
                        if (kbd_key_detection_mode == kbd_3_keys_det_mode)
						         kbd_press_key[2] = keypad_comm_def->keypad[key_index];
#endif
                        key_presscount = 3;
                  }
               }
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
                  else if ((kbd_key_detection_mode == kbd_3_keys_det_mode) && (key_presscount == 3))
                  {
                     /* More than 2 keys are pressed. */
                     if ((kbd_press_key[0] != keypad_comm_def->keypad[key_index])
                        && (kbd_press_key[1] != keypad_comm_def->keypad[key_index])
                        && (kbd_press_key[2] != keypad_comm_def->keypad[key_index]))
                        key_presscount = 4;
                  }
#endif
               }
               /* Else if the key is released. */
               else
               {
                  //KBD.kbdmap_reg |= (1<<key_index);
                  /* Only deal with those keys that we've recorded as pressed. */
                  if ((KEY_INVALID != kbd_saved_pressed_key[0]) && (kbd_saved_pressed_key[0] == keypad_comm_def->keypad[key_index]))
                  {
                     /* Record the released key event. */
                     kbd_release_key[key_releasecount] = kbd_saved_pressed_key[0];
					      key_releasecount++;
                     #ifdef __KBD_2STEP_KEY_SUPPORT__
                        /* Note that 2-steps key is only enable when 2 key detection is disable. */
                        if (kbd_is_2steps_key == KAL_TRUE)
                        {
                           GPTI_StopItem(KBD.kbd_2key_handle);
                           kbd_is_2steps_key = KAL_FALSE;
                        }
                     #endif /*__KBD_2STEP_KEY_SUPPORT__*/
                     /* Stop the longpress/repeate timer for this key. */
                     GPTI_StopItem(KBD.gpthandle[0]);
                     kbd_saved_pressed_key[0] = KEY_INVALID;
                     kbd_press_event_count--;
                  }
                  /* Only if 2key or 3key detection is enable, 2nd key may have been recorded as pressed. */
                  else if (kbd_key_detection_mode != kbd_1_key_det_mode)
                  {
                     if((KEY_INVALID != kbd_saved_pressed_key[1]) && (kbd_saved_pressed_key[1] == keypad_comm_def->keypad[key_index]))
                     {
                        /* Record the released key event. */
                        kbd_release_key[key_releasecount] = kbd_saved_pressed_key[1];
                        key_releasecount++;
                        /* Stop the longpress/repeate timer for this key. */
                        GPTI_StopItem(KBD.gpthandle[1]);
                        kbd_saved_pressed_key[1] = KEY_INVALID;
                        kbd_press_event_count--;
                     }
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
                     /* Only if 3key detection is enable, 2nd key may have been recorded as pressed. */
                     else if (kbd_key_detection_mode == kbd_3_keys_det_mode)
                     {
                        if((KEY_INVALID != kbd_saved_pressed_key[2]) && (kbd_saved_pressed_key[2] == keypad_comm_def->keypad[key_index]))
                        {
                           /* Record the released key event. */
                           kbd_release_key[key_releasecount] = kbd_saved_pressed_key[2];
                           key_releasecount++;
                           /* Stop the longpress/repeate timer for this key. */
                           GPTI_StopItem(KBD.gpthandle[2]);
                           kbd_saved_pressed_key[2] = KEY_INVALID;
                           kbd_press_event_count--;
                        }
                     }
#endif
                  }
               }
            } /* if( (KBD.kbdmap_reg &(1<<key_index)) != (kbd_map_temp_reg &(1<<key_index)) ) */
         } /* for(key_index=0;  */
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
         /*to check the last status register*/
#if defined(DRV_KBD_32KEYS_ABOVE)
         for(key_index=0, array_idx=32;key_index<(kbd_allkeys-32);key_index++, array_idx++)
         #elif defined(DRV_KBD_64KEYS_ABOVE)
         for(key_index=0, array_idx=32;key_index<32;key_index++, array_idx++)
         #endif
         {
            if( (KBD.kbdmap_reg1 &(1<<key_index)) != (kbd_map_temp_reg1 &(1<<key_index)) )
            {
               if (!(kbd_map_temp_reg1 &(1<<key_index)))
               {
                  if (key_presscount == 0)
                  {
                     kbd_press_key[0] = keypad_comm_def->keypad[array_idx];
                     key_presscount = 1;
                  }
                  else if (key_presscount == 1)
                  {
                     if (kbd_press_key[0] != keypad_comm_def->keypad[array_idx])
                     {
                        /* Record the 2nd pressed key event. */
                        if (kbd_key_detection_mode != kbd_1_key_det_mode)
                        {
                        kbd_press_key[1] = keypad_comm_def->keypad[array_idx];
                        }
                        key_presscount = 2;
                     }
                  }
                  else if ((kbd_key_detection_mode != kbd_1_key_det_mode) && (key_presscount == 2))
                  {
                     if ((kbd_press_key[0] != keypad_comm_def->keypad[array_idx])
                        && (kbd_press_key[1] != keypad_comm_def->keypad[array_idx]))
                     {
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
                        /* Record the 3rd pressed key event if in 3 keys detection mode. */
                        if (kbd_key_detection_mode == kbd_3_keys_det_mode)
                        {
						         kbd_press_key[2] = keypad_comm_def->keypad[array_idx];
                        }
#endif
                        key_presscount = 3;
                  }
               }
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
                  else if ((kbd_key_detection_mode == kbd_3_keys_det_mode) && (key_presscount == 3))
                  {
                     /* More than 2 keys are pressed. */
                     if ((kbd_press_key[0] != keypad_comm_def->keypad[array_idx])
                        && (kbd_press_key[1] != keypad_comm_def->keypad[array_idx])
                        && (kbd_press_key[2] != keypad_comm_def->keypad[array_idx]))
                     {
                        key_presscount = 4;
                     }
                  }
#endif
               }
               else
               {
                  //KBD.kbdmap_reg1 |= (1<<key_index);
                  if ((KEY_INVALID != kbd_saved_pressed_key[0]) && (kbd_saved_pressed_key[0] == keypad_comm_def->keypad[array_idx]))
				      {
                     kbd_release_key[key_releasecount] = kbd_saved_pressed_key[0];
                     key_releasecount++;
                     #ifdef __KBD_2STEP_KEY_SUPPORT__
                        /* Note that 2-steps key is only enable when 2 key detection is disable. */
                        if (kbd_is_2steps_key == KAL_TRUE)
                        {
                           GPTI_StopItem(KBD.kbd_2key_handle);
                           kbd_is_2steps_key = KAL_FALSE;
                        }
                     #endif /*__KBD_2STEP_KEY_SUPPORT__*/
                     GPTI_StopItem(KBD.gpthandle[0]);
                     kbd_saved_pressed_key[0] = KEY_INVALID;
                     kbd_press_event_count--;
                  }
                  /* Only if 2key or 3key detection is enable, 2nd key may have been recorded as pressed. */
                  else if (kbd_key_detection_mode != kbd_1_key_det_mode)
                  {
                     if((KEY_INVALID != kbd_saved_pressed_key[1]) && (kbd_saved_pressed_key[1] == keypad_comm_def->keypad[array_idx]))
                     {
                        kbd_release_key[key_releasecount] = kbd_saved_pressed_key[1];
                        key_releasecount++;
                        GPTI_StopItem(KBD.gpthandle[1]);
                        kbd_saved_pressed_key[1] = KEY_INVALID;
                        kbd_press_event_count--;
                     }
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
                     /* Only if 3key detection is enable, 2nd key may have been recorded as pressed. */
                     else if (kbd_key_detection_mode == kbd_3_keys_det_mode)
                     {
                        if((KEY_INVALID != kbd_saved_pressed_key[2]) && (kbd_saved_pressed_key[2] == keypad_comm_def->keypad[array_idx]))
                        {
                           /* Record the released key event. */
                           kbd_release_key[key_releasecount] = kbd_saved_pressed_key[2];
                           key_releasecount++;
                           /* Stop the longpress/repeate timer for this key. */
                           GPTI_StopItem(KBD.gpthandle[2]);
                           kbd_saved_pressed_key[2] = KEY_INVALID;
                           kbd_press_event_count--;
                        }
                     }
#endif
                  }
               }
            } /* if( (KBD.kbdmap_reg1 &(1<<key_index)) != (kbd_map_temp_reg1 &(1<<key_index)) ) */
         } /* for(key_index=0;  */
#endif   /*DRV_KBD_32KEYS_ABOVE*/
#if defined(DRV_KBD_64KEYS_ABOVE)
         /*to check the last status register*/
         for(key_index=0, array_idx=64;key_index<(kbd_allkeys-64);key_index++, array_idx++)
         {
            if( (KBD.kbdmap_reg2 &(1<<key_index)) != (kbd_map_temp_reg2 &(1<<key_index)) )
            {
               if (!(kbd_map_temp_reg2 &(1<<key_index)))
               {
                  if (key_presscount == 0)
                  {
                     kbd_press_key[0] = keypad_comm_def->keypad[array_idx];
                     key_presscount = 1;
                  }
                  else if (key_presscount == 1)
                  {
                     if (kbd_press_key[0] != keypad_comm_def->keypad[array_idx])
                     {
                        /* Record the 2nd pressed key event. */
                        if (kbd_key_detection_mode != kbd_1_key_det_mode)
                        {
                        kbd_press_key[1] = keypad_comm_def->keypad[array_idx];
                        }
                        key_presscount = 2;
                     }
                  }
                  else if ((kbd_key_detection_mode != kbd_1_key_det_mode) && (key_presscount == 2))
                  {
                     if ((kbd_press_key[0] != keypad_comm_def->keypad[array_idx])
                        && (kbd_press_key[1] != keypad_comm_def->keypad[array_idx]))
                     {
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
                        /* Record the 3rd pressed key event if in 3 keys detection mode. */
                        if (kbd_key_detection_mode == kbd_3_keys_det_mode)
                        {
						         kbd_press_key[2] = keypad_comm_def->keypad[array_idx];
                        }
#endif
                        key_presscount = 3;
                  }
               }
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
                  else if ((kbd_key_detection_mode == kbd_3_keys_det_mode) && (key_presscount == 3))
                  {
                     /* More than 2 keys are pressed. */
                     if ((kbd_press_key[0] != keypad_comm_def->keypad[array_idx])
                        && (kbd_press_key[1] != keypad_comm_def->keypad[array_idx])
                        && (kbd_press_key[2] != keypad_comm_def->keypad[array_idx]))
                     {
                        key_presscount = 4;
                     }
                  }
#endif
               }
               else
               {
                  //KBD.kbdmap_reg1 |= (1<<key_index);
                  if ((KEY_INVALID != kbd_saved_pressed_key[0]) && (kbd_saved_pressed_key[0] == keypad_comm_def->keypad[array_idx]))
				      {
                     kbd_release_key[key_releasecount] = kbd_saved_pressed_key[0];
                     key_releasecount++;
                     #ifdef __KBD_2STEP_KEY_SUPPORT__
                        /* Note that 2-steps key is only enable when 2 key detection is disable. */
                        if (kbd_is_2steps_key == KAL_TRUE)
                        {
                           GPTI_StopItem(KBD.kbd_2key_handle);
                           kbd_is_2steps_key = KAL_FALSE;
                        }
                     #endif /*__KBD_2STEP_KEY_SUPPORT__*/
                     GPTI_StopItem(KBD.gpthandle[0]);
                     kbd_saved_pressed_key[0] = KEY_INVALID;
                     kbd_press_event_count--;
                  }
                  /* Only if 2key or 3key detection is enable, 2nd key may have been recorded as pressed. */
                  else if (kbd_key_detection_mode != kbd_1_key_det_mode)
                  {
                     if((KEY_INVALID != kbd_saved_pressed_key[1]) && (kbd_saved_pressed_key[1] == keypad_comm_def->keypad[array_idx]))
                     {
                        kbd_release_key[key_releasecount] = kbd_saved_pressed_key[1];
                        key_releasecount++;
                        GPTI_StopItem(KBD.gpthandle[1]);
                        kbd_saved_pressed_key[1] = KEY_INVALID;
                        kbd_press_event_count--;
                     }
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
                     /* Only if 3key detection is enable, 2nd key may have been recorded as pressed. */
                     else if (kbd_key_detection_mode == kbd_3_keys_det_mode)
                     {
                        if((KEY_INVALID != kbd_saved_pressed_key[2]) && (kbd_saved_pressed_key[2] == keypad_comm_def->keypad[array_idx]))
                        {
                           /* Record the released key event. */
                           kbd_release_key[key_releasecount] = kbd_saved_pressed_key[2];
                           key_releasecount++;
                           /* Stop the longpress/repeate timer for this key. */
                           GPTI_StopItem(KBD.gpthandle[2]);
                           kbd_saved_pressed_key[2] = KEY_INVALID;
                           kbd_press_event_count--;
                        }
                     }
#endif
                  }
               }
            } /* if( (KBD.kbdmap_reg1 &(1<<key_index)) != (kbd_map_temp_reg1 &(1<<key_index)) ) */
         } /* for(key_index=0;  */
#endif   /*DRV_KBD_64KEYS_ABOVE*/
         /* Process the release key first. */
         if (key_releasecount > 0 && key_releasecount <= KBD_KEY_DETECTION_CNT)
         {
            #ifdef __EXTRA_A_B_KEY_SUPPORT__
            if (kbd_key_detection_mode != kbd_1_key_det_mode)
            {
               EINT_Mask(EINT_A_KEY);
               EINT_Mask(EINT_B_KEY);
               IRQMask(IRQ_GPT_CODE);
            }
            #endif
            kbdbuffer_get_roomleft(roomleft);
            #ifdef KBD_DBGMODE
               ASSERT(roomleft>key_releasecount);
            #else
               /* Check if buffer room is enough or not. Note there should be one buffer left for 
                  2key detection enable/disable event. */
               if (roomleft <= key_releasecount)
               {
                  kal_uint8   count;

                  #ifdef __EXTRA_A_B_KEY_SUPPORT__
                  if (kbd_key_detection_mode != kbd_1_key_det_mode)
                  {
                     EINT_UnMask(EINT_A_KEY);
                     EINT_UnMask(EINT_B_KEY);
                     IRQUnmask(IRQ_GPT_CODE);
                  }
                  #endif
                  /* Not enough room. So we recover saved press key event. */
                  for (key_index = 0, count = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++)
                  {
                     if (kbd_saved_pressed_key[key_index] == KEY_INVALID)
                     {
                        kbd_saved_pressed_key[key_index] = kbd_release_key[count];
                        count++;
                        if (count >= key_releasecount)
                           break;
                     }
                  }
                  kbd_press_event_count += key_releasecount;
			         continue;
               }
            #endif
            #if defined(DRV_WDT_RESET_PKEY_RELEASE)
            if (TargetReset)
               DRV_RESET();
            #endif   /*DRV_WDT_RESET_PKEY_RELEASE*/
            for (key_index = 0; key_index < key_releasecount; key_index++)
            {
               kbd_push_onekey_to_kbdbuffer(kbd_onekey_release,kbd_release_key[key_index]);
            }
            #ifdef __EXTRA_A_B_KEY_SUPPORT__
            if (kbd_key_detection_mode != kbd_1_key_det_mode)
            {
               EINT_UnMask(EINT_A_KEY);
               EINT_UnMask(EINT_B_KEY);
               IRQUnmask(IRQ_GPT_CODE);
            }
            #endif
         }
         /* Update the keypad scan registers for release keys here. */
         KBD.kbdmap_reg |= kbd_map_temp_reg;
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
         KBD.kbdmap_reg1 |= kbd_map_temp_reg1;
#endif
#if defined(DRV_KBD_64KEYS_ABOVE)
         KBD.kbdmap_reg2 |= kbd_map_temp_reg2;
#endif
         /* Calculate the total press keys count now. */
         key_total_count = kbd_press_event_count + key_presscount;
         /* Check if the total press keys count exceeds the limitation. */
         if (((kbd_key_detection_mode == kbd_1_key_det_mode) && (key_total_count > 1))
            || ((kbd_key_detection_mode == kbd_2_keys_det_mode) && (key_total_count > 2))
            || ((kbd_key_detection_mode == kbd_3_keys_det_mode) && (key_total_count > 3)))
         {
            /* Exceed the press key count so we don't process the newly pressed keys. */
            if (key_releasecount == 0)
             continue;
         }
         else
         {
            if (key_presscount > 0 && key_presscount <= KBD_KEY_DETECTION_CNT)
            {
               kal_uint8 count;

               #ifdef __EXTRA_A_B_KEY_SUPPORT__
               if (kbd_key_detection_mode != kbd_1_key_det_mode)
               {
                  EINT_Mask(EINT_A_KEY);
                  EINT_Mask(EINT_B_KEY);
                  IRQMask(IRQ_GPT_CODE);
               }
               #endif
               kbdbuffer_get_roomleft(roomleft);
               #ifdef KBD_DBGMODE
                  ASSERT(roomleft >= (key_presscount*2+kbd_press_event_count+kbd_ext_press_event_count+1));
               #endif
               /* Note the left buffer room should more than the sum of
                  1. kbd_press_event_count: for release key events later. 
                  2. newly press keys x 2 . (1 for press, 1 for release later).
                  3. 1: multi key detection enable/disable event. 
                  4. External A/B pressed keys: for release key events later */
               if (roomleft < (key_presscount*2+kbd_press_event_count+kbd_ext_press_event_count+1))
               {
                  #ifdef __EXTRA_A_B_KEY_SUPPORT__
                  if (kbd_key_detection_mode != kbd_1_key_det_mode)
                  {
                     EINT_UnMask(EINT_A_KEY);
                     EINT_UnMask(EINT_B_KEY);
                     IRQUnmask(IRQ_GPT_CODE);
                  }
                  #endif
               }
               else
               {
                  #ifdef KBD_DBGMODE
                     //ASSERT(kbd_saved_pressed_key[0] == KEY_INVALID);
                     //ASSERT(kbd_saved_pressed_key[1] == KEY_INVALID);
                  #endif   /*KBD_DBGMODE*/
                  /* Store the press key event. */
                  for (key_index = 0, count = 0; key_index < KBD_KEY_DETECTION_CNT; key_index++)
                  {
                     if (kbd_saved_pressed_key[key_index] == KEY_INVALID)
                     {
                        kbd_saved_pressed_key[key_index] = kbd_press_key[count];
                        kbd_push_onekey_to_kbdbuffer(kbd_onekey_press,kbd_press_key[count]);
                        /* Start the longpress timer for this key. */
                        #ifdef __KBD_2STEP_KEY_SUPPORT__
                        /* Check if it's 2-steps key. Note that 2-steps key is disable in multi-keys detection mode. */
                        if((kbd_key_detection_mode == kbd_1_key_det_mode) 
                           && keypadCustomFunc->keypad_is_fullpress(kbd_press_key[count]))
                        {
                           kbd_is_2steps_key = KAL_TRUE;
                           GPTI_StartItem(KBD.kbd_2key_handle,
                                          10,
                                          KBD2KeyHandler,
                                          NULL);                     
                        }   
                        else
                        {
                        #endif /*__KBD_2STEP_KEY_SUPPORT__*/
                           /* Start the longpress timer for this. */
                           GPTI_StartItem(KBD.gpthandle[key_index],
                                             KBD.longpress_timeout,
                                             KBDTimeOutHandler,
                                             (void *)key_index);
                        #ifdef __KBD_2STEP_KEY_SUPPORT__
                        }
                        #endif /*__KBD_2STEP_KEY_SUPPORT__*/
                        count++;
                        if (count >= key_presscount)
                           break;
                     }
                  }
			         kbd_press_event_count+=key_presscount;
                  #ifdef __EXTRA_A_B_KEY_SUPPORT__
                  if (kbd_key_detection_mode != kbd_1_key_det_mode)
                  {
                     EINT_UnMask(EINT_A_KEY);
                     EINT_UnMask(EINT_B_KEY);
                     IRQUnmask(IRQ_GPT_CODE);
                  }
                  #endif
                  /* Update the keypad scan registers for press keys here. */
                  KBD.kbdmap_reg &= kbd_map_temp_reg;
                  #if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
                     KBD.kbdmap_reg1 &= kbd_map_temp_reg1;
                  #endif   /*DRV_KBD_32KEYS_ABOVE*/
                  #if defined(DRV_KBD_64KEYS_ABOVE)
                     KBD.kbdmap_reg2 &= kbd_map_temp_reg2;
                  #endif   /*DRV_KBD_32KEYS_ABOVE*/
               }
            }
         }
#if defined(TOUCH_PAD_SUPPORT)
         kbd_owner_stat = (kbd_press_event_count > 0) ? KBD_OWNER_KEYPAD: KBD_OWNER_NONE;
#endif /*TOUCH_PAD_SUPPORT*/
         if (send_kbdilm)
         {
            send_kbdilm = KAL_FALSE;
         #ifndef L4_NOT_PRESENT
            DRV_BuildPrimitive(Kp_ilm,
                               MOD_DRVKBD,
                               MOD_UEM,
                               MSG_ID_DRVUEM_KEYPAD_IND,
                               NULL);
   
            msg_send_ext_queue(Kp_ilm);
         #endif   /*L4_NOT_PRESENT*/
         }
      }  /*if (KBD.kbdmap_reg != KBD.kbdmap_reg)*/
   }
}

#else /* KBD_DETECT_ONLY_ONE_KEY */

kal_bool kbd_key_det_mode_switch(kbd_key_det_mode mode)
{
   return KAL_FALSE;
}

void kbd_task_main( task_entry_struct * task_entry_ptr )
{
   kal_uint32     event_group;
   kal_uint32     kbd_map_temp_reg;
#if defined(DRV_KBD_32KEYS_ABOVE)
   kal_uint32     kbd_map_temp_reg1;
#elif defined(DRV_KBD_64KEYS_ABOVE)
   kal_uint32     kbd_map_temp_reg1;
   kal_uint32     kbd_map_temp_reg2;
#endif   /*DRV_KBD_32KEYS_ABOVE*/
   kal_uint8      key_presscount;
   kal_uint8      key_releasecount;
   kal_uint8      key_index;
   kal_uint8      kbd_press_key[2];
   kal_uint8      kbd_release_key[2];
   ilm_struct     *Kp_ilm;
   kal_uint8      key_total_count;
   kal_uint8      roomleft;
   kal_uint8		end_press_count, end_release_count;
   
   while(1)
   {
      kal_retrieve_eg_events(KBD.event,1,KAL_OR_CONSUME
         ,&event_group,KAL_SUSPEND);
      
      #ifndef __PRODUCTION_RELEASE__
      ASSERT(kbd_press_event_count < (kbd_buffer_size/2));
      #endif

      key_total_count=0;
      end_press_count = 0;
      end_release_count = 0;
      
#if defined(DRV_KBD_32KEYS_EQ_BELOW) || defined(FPGA)
      kbd_map_temp_reg = ( ((kal_uint32)(DRV_Reg(KP_HI_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );

#if defined(TOUCH_PAD_SUPPORT)
#if defined(TOUCH_PAD_USE_KEY_COLUMN)
		#if defined(TOUCHPAD_DEBUG)		
		kal_prompt_trace(MOD_DRVKBD, "kbd_map_temp_reg=%x,kbd_map_temp_reg1=%x",kbd_map_temp_reg,kbd_map_temp_reg1);
		#endif
      // if some keypad key is pressed, the corresponding bit of key 
      // status register is changed from 1 to 0
      if (((kbd_map_temp_reg >> TOUCH_PAD_KEY_COLUMN_NUM) & 0x00000001) == 0) 
      {
           // reset each key status bit corresponding to the keypad column to 1 to 
           // prevent keypad status to be processed in the following general key press
         if (kbd_owner_stat == KBD_OWNER_KEYPAD)
         {
            kbd_map_temp_reg |= KEYPAD_SCANNER_REG;
            kbd_map_temp_reg1 |= KEYPAD_SCANNER_REG1;
         }
         TOUCHPAD_UART_PutBytes(TOUCHPAD_UART_PORT, 0x50);
         if (kbd_owner_stat != KBD_OWNER_KEYPAD)
         {
            if (kbd_owner_stat == KBD_OWNER_NONE)
               kbd_owner_stat = KBD_OWNER_TOUCHPAD;
            continue;
         }
      }
      else if (kbd_owner_stat == KBD_OWNER_TOUCHPAD)
         continue;

      #if defined(TOUCHPAD_DEBUG)		
      kal_prompt_trace(MOD_DRVKBD, "after change: kbd_map_temp_reg=%x,kbd_map_temp_reg1=%x",kbd_map_temp_reg,kbd_map_temp_reg1);
      #endif
#endif  /*  TOUCH_PAD_USE_KEY_COLUMN    */
#endif  /*  TOUCH_PAD_SUPPORT   */

      if (KBD.kbdmap_reg != kbd_map_temp_reg)
#elif defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
      kbd_map_temp_reg = ( ((kal_uint32)(DRV_Reg(KP_MID_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );
      #if defined(DRV_KBD_32KEYS_ABOVE)
      kbd_map_temp_reg1 = (kal_uint32)(DRV_Reg(KP_HI_KEY));
      #elif defined(DRV_KBD_64KEYS_ABOVE)
      kbd_map_temp_reg1 = ( ((kal_uint32)(DRV_Reg(KP_MID2_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_MID1_KEY))) );
      kbd_map_temp_reg2 = (kal_uint32)(DRV_Reg(KP_HI_KEY));
      #endif

#if defined(TOUCH_PAD_SUPPORT)
#if defined(TOUCH_PAD_USE_KEY_COLUMN)
		#if defined(TOUCHPAD_DEBUG)		
		kal_prompt_trace(MOD_DRVKBD, "kbd_map_temp_reg=%x,kbd_map_temp_reg1=%x",kbd_map_temp_reg,kbd_map_temp_reg1);
		#endif
      // if some keypad key is pressed, the corresponding bit of key 
      // status register is changed from 1 to 0
      if (((kbd_map_temp_reg >> TOUCH_PAD_KEY_COLUMN_NUM) & 0x00000001) == 0) 
      {
           // reset each key status bit corresponding to the keypad column to 1 to 
           // prevent keypad status to be processed in the following general key press
         if (kbd_owner_stat == KBD_OWNER_KEYPAD)
         {
            kbd_map_temp_reg |= KEYPAD_SCANNER_REG;
            kbd_map_temp_reg1 |= KEYPAD_SCANNER_REG1;
            #if defined(DRV_KBD_64KEYS_ABOVE)
            kbd_map_temp_reg2 |= KEYPAD_SCANNER_REG2;
            #endif
         }
         TOUCHPAD_UART_PutBytes(TOUCHPAD_UART_PORT, 0x50);
         if (kbd_owner_stat != KBD_OWNER_KEYPAD)
         {
            if (kbd_owner_stat == KBD_OWNER_NONE)
               kbd_owner_stat = KBD_OWNER_TOUCHPAD;
            continue;
         }
      }
      else if (kbd_owner_stat == KBD_OWNER_TOUCHPAD)
         continue;

	   #if defined(TOUCHPAD_DEBUG)		
	   kal_prompt_trace(MOD_DRVKBD, "after change: kbd_map_temp_reg=%x,kbd_map_temp_reg1=%x",kbd_map_temp_reg,kbd_map_temp_reg1);
	   #endif
#endif  /*  TOUCH_PAD_USE_KEY_COLUMN    */
#endif  /*  TOUCH_PAD_SUPPORT   */

      #if defined(DRV_KBD_32KEYS_ABOVE)
      if ((KBD.kbdmap_reg != kbd_map_temp_reg) || (KBD.kbdmap_reg1 != kbd_map_temp_reg1 ))
      #elif defined(DRV_KBD_64KEYS_ABOVE)
      if ((KBD.kbdmap_reg != kbd_map_temp_reg) || (KBD.kbdmap_reg1 != kbd_map_temp_reg1 ) || (KBD.kbdmap_reg2 != kbd_map_temp_reg2))
      #endif
#endif   /*DRV_KBD_32KEYS_EQ_BELOW,FPGA*//*DRV_KBD_32KEYS_ABOVE*/
      {
         //GPTI_StopItem(KBD.gpthandle);
         #if 0
         #ifdef __KBD_2STEP_KEY_SUPPORT__
/* under construction !*/
         #endif
         #endif
         key_presscount = 0;
         key_releasecount = 0;
         /*The first for loop is to check first 2 status register*/
#if defined(DRV_KBD_32KEYS_EQ_BELOW) || defined(FPGA)
         for(key_index=0;key_index<kbd_allkeys;key_index++)
#elif defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
         for(key_index=0;key_index<32;key_index++)
#endif   /*DRV_KBD_32KEYS_EQ_BELOW,FPGA*//*DRV_KBD_32KEYS_EQ_BELOW*/
         {
            if ( (kbd_map_temp_reg &(1<<key_index))==0 )
               key_total_count++;

            if( (KBD.kbdmap_reg &(1<<key_index)) != (kbd_map_temp_reg &(1<<key_index)) )
            {
               if (!(kbd_map_temp_reg &(1<<key_index)))
               {
                  kbd_press_key[key_presscount&1] = keypad_comm_def->keypad[key_index];
                  #if (defined(__MAUI_BASIC__)) && (defined(MONZA)) 
                  monza_kp_control(keypad_comm_def->keypad[key_index]);
                  #endif
                  key_presscount++;
                  if(kbd_is_mutiple_key(keypad_comm_def->keypad[key_index]))                
                  {

                     end_press_count++;
                  }
               }
               else
               {
                  kbd_release_key[key_releasecount&1] = keypad_comm_def->keypad[key_index];
                  key_releasecount++;
                  if(kbd_is_mutiple_key(keypad_comm_def->keypad[key_index]))                                  
                  {

                     end_release_count++;
                  }
               }
            }
         }
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
         /*to check the last status register*/
         #if defined(DRV_KBD_32KEYS_ABOVE)
         for(key_index=0;key_index<(kbd_allkeys-32);key_index++)
         #elif defined(DRV_KBD_64KEYS_ABOVE)
         for(key_index=0;key_index<32;key_index++)
         #endif
         {
            if ( (kbd_map_temp_reg1 &(1<<key_index)) == 0 )
               key_total_count++;

            if( (KBD.kbdmap_reg1 &(1<<key_index)) != (kbd_map_temp_reg1 &(1<<key_index)) )
            {
               if (!(kbd_map_temp_reg1 &(1<<key_index)))
               {
                  kbd_press_key[key_presscount&1] = keypad_comm_def->keypad[key_index+32];
                  key_presscount++;
                  if(kbd_is_mutiple_key(keypad_comm_def->keypad[key_index+32]))                                  
                  {
                     end_press_count++;
                  }
               }
               else
               {
                  kbd_release_key[key_releasecount&1] = keypad_comm_def->keypad[key_index+32];
                  key_releasecount++;
                  if(kbd_is_mutiple_key(keypad_comm_def->keypad[key_index+32]))                                  
                  {
                     end_release_count++;
                  }
               }
            }           
         }
#endif   /*DRV_KBD_32KEYS_ABOVE*/
#if defined(DRV_KBD_64KEYS_ABOVE)
         /*to check the last status register*/
         for(key_index=0;key_index<(kbd_allkeys-64);key_index++)
         {
            if ( (kbd_map_temp_reg2 &(1<<key_index)) == 0 )
               key_total_count++;

            if( (KBD.kbdmap_reg2 &(1<<key_index)) != (kbd_map_temp_reg2 &(1<<key_index)) )
            {
               if (!(kbd_map_temp_reg2 &(1<<key_index)))
               {
                  kbd_press_key[key_presscount&1] = keypad_comm_def->keypad[key_index+64];
                  key_presscount++;
                  if(kbd_is_mutiple_key(keypad_comm_def->keypad[key_index+64]))                                  
                  {
                     end_press_count++;
                  }
               }
               else
               {
                  kbd_release_key[key_releasecount&1] = keypad_comm_def->keypad[key_index+64];
                  key_releasecount++;
                  if(kbd_is_mutiple_key(keypad_comm_def->keypad[key_index+64]))                                  
                  {
                     end_release_count++;
                  }
               }
            }           
         }
#endif   /*DRV_KBD_64KEYS_ABOVE*/
      
      if(0!=end_press_count)/*to cover one<->multiple */
      { 
         key_total_count = key_total_count - end_press_count + 1;
         key_presscount = key_presscount - end_press_count + 1;
      }
      if(0!=end_release_count)/*to cover one<->multiple */
         key_releasecount = key_releasecount - end_release_count + 1;
      
      #ifdef TWO_KEY_ENABLE
         if ((key_presscount<=2) && (key_total_count <= 2) )
      #else /*!TWO_KEY_ENABLE*/
         if ( (key_presscount<=1) && (key_total_count <= 1) )
      #endif   /*TWO_KEY_ENABLE*/
         {
         #ifdef KBD_DBGMODE
            KBD.kbdmap_reg = kbd_map_temp_reg;
            #if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
               KBD.kbdmap_reg1 = kbd_map_temp_reg1;
            #endif   /*DRV_KBD_32KEYS_ABOVE*/
            #if defined(DRV_KBD_64KEYS_ABOVE)
               KBD.kbdmap_reg2 = kbd_map_temp_reg2;
            #endif   /*DRV_KBD_32KEYS_ABOVE*/
         #else /*!KBD_DBGMODE*/
            /*Predict*/
            kbdbuffer_get_roomleft(roomleft);
            if ( (roomleft <=key_presscount*2+kbd_press_event_count) && (key_releasecount == 0) )
            {
               continue;
            }
            else
            {
               KBD.kbdmap_reg = kbd_map_temp_reg;
               #if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
                  KBD.kbdmap_reg1 = kbd_map_temp_reg1;
               #endif   /*DRV_KBD_32KEYS_ABOVE*/
               #if defined(DRV_KBD_64KEYS_ABOVE)
                  KBD.kbdmap_reg2 = kbd_map_temp_reg2;
               #endif   /*DRV_KBD_32KEYS_ABOVE*/
            }
         #endif
         }
         else
            continue;
         GPTI_StopItem(KBD.gpthandle);
         #ifdef __KBD_2STEP_KEY_SUPPORT__
         GPTI_StopItem(KBD.kbd_2key_handle); 
         #endif               
         switch(key_releasecount)
         {
            case 1:
               #ifndef KBD_DBGMODE
               if (!kbd_press_event_count)
                  break;
               #endif

               kbdbuffer_get_roomleft(roomleft);
               ASSERT(roomleft!=0);
               
               kbd_press_event_count--;
               #if defined(DRV_WDT_RESET_PKEY_RELEASE)
                  if (TargetReset)
   	               DRV_RESET();
               #endif   /*MT6205,MT6208*/

               kbd_push_onekey_to_kbdbuffer(kbd_onekey_release,kbd_release_key[0]);
               break;
               
            case 2:
               #ifndef KBD_DBGMODE
               if (!kbd_press_event_count)
                  break;
               #endif
               kbdbuffer_get_roomleft(roomleft);
               ASSERT(roomleft>=2);
               
               kbd_press_event_count-=2;
               #if defined(DRV_WDT_RESET_PKEY_RELEASE)
                  if (TargetReset)
   	               DRV_RESET();
               #endif   /*MT6205,MT6208*/
               
               #ifdef TWO_KEY_ENABLE
                     kbd_push_twokey_to_kbdbuffer(kbd_twokey_release,kbd_release_key[0],kbd_release_key[1]);
               #else    /*!TWO_KEY_ENABLE*/
                     kbd_push_onekey_to_kbdbuffer(kbd_onekey_release,kbd_release_key[0]);
                     kbd_push_onekey_to_kbdbuffer(kbd_onekey_release,kbd_release_key[1]);
               #endif   /*TWO_KEY_ENABLE*/
               break;
               
            default:
               break;
         }
         
         switch(key_presscount)
         {
            case 1:
               key_save = kbd_press_key[0];
               kbdbuffer_get_roomleft(roomleft);
               #ifdef KBD_DBGMODE
                  ASSERT(roomleft!=0);
               #else
                  if ( roomleft < (kbd_press_event_count+2))
                  {
                     break;
                  }
               #endif   /*KBD_DBGMODE*/
               
               kbd_push_onekey_to_kbdbuffer(kbd_onekey_press,kbd_press_key[0]);
               kbd_press_event_count++;
               #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
               #endif               
               #ifdef __KBD_2STEP_KEY_SUPPORT__
               if(keypadCustomFunc->keypad_is_fullpress(kbd_press_key[0]))
               {
                  GPTI_StartItem(KBD.kbd_2key_handle,
                                 10,
                                 KBD2KeyHandler,
                                 NULL);                     
               }   
               else
               {
               	GPTI_StartItem(KBD.gpthandle,
                              KBD.longpress_timeout,
                              KBDTimeOutHandler,
                              NULL);			
               }	   
               #else
               GPTI_StartItem(KBD.gpthandle,
                              KBD.longpress_timeout,
                              KBDTimeOutHandler,
                              NULL);					               
               #endif                                    
               break;
            
         #ifdef TWO_KEY_ENABLE
            case 2:
               kbdbuffer_get_roomleft(roomleft);
               #ifdef KBD_DBGMODE
                  ASSERT(roomleft!=0);
               #else
                  if ( roomleft < (kbd_press_event_count+4))
                  {
                     break;
                  }
               #endif   /*KBD_DBGMODE*/
               
               kbd_push_twokey_to_kbdbuffer(kbd_twokey_press,kbd_press_key[0],kbd_press_key[1]);
               kbd_press_event_count+=2;
               break;
         #endif   /*TWO_KEY_ENABLE*/
         
            default:
               break;
         }
#if defined(TOUCH_PAD_SUPPORT)
         kbd_owner_stat = (kbd_press_event_count > 0) ? KBD_OWNER_KEYPAD: KBD_OWNER_NONE;
#endif /*TOUCH_PAD_SUPPORT*/
         if (send_kbdilm)
         {
            send_kbdilm = KAL_FALSE;
         #ifndef L4_NOT_PRESENT
            DRV_BuildPrimitive(Kp_ilm,
                               MOD_DRVKBD,
                               MOD_UEM,
                               MSG_ID_DRVUEM_KEYPAD_IND,
                               NULL);
   
            msg_send_ext_queue(Kp_ilm);
         #endif   /*L4_NOT_PRESENT*/
         }
      }  /*if (KBD.kbdmap_reg != KBD.kbdmap_reg)*/
   }
}
#endif /* KBD_DETECT_ONLY_ONE_KEY */

/*************************************************************************
* FUNCTION                                                            
*	kbd_task_reset
*
* DESCRIPTION
*	This function implements xyz's reset handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool 
kbd_task_reset(task_indx_type task_indx)
{
  	/* Do task's reset here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_reset() will do. */
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION                                                            
*	kbd_task_end
*
* DESCRIPTION
*	This function implements xyz's termination handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool 
kbd_task_end(task_indx_type task_indx)
{
  	/* Do task's termination here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_end() will do. */
	return KAL_TRUE;
}

/*
* FUNCTION
*  Kbd_LISR
*
* DESCRIPTION
*     This function is keypad interrupt handler.
*
* CALLS
*  This function is called when keypad IRQ signal is coming.
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void Kbd_LISR(void)
{
   //kal_activate_hisr(KBD.hisr);
   drv_active_hisr(DRV_KP_HISR_ID);
}
void Kbd_HisrEntry(void)
{      
   kal_set_eg_events(KBD.event,1,KAL_OR);           
}

/*the tick unit is 10ms*/
void Kbd_SetLongPressTime(kal_uint32 ticks)
{
   KBD.longpress_timeout = ticks;
}

void Kbd_SetRepeatTime(kal_uint32 ticks)
{
   KBD.repeat_time = ticks;
}

#if !defined(KBD_DETECT_ONLY_ONE_KEY) && defined(__EXTRA_A_B_KEY_SUPPORT__)
void EXT_A_EINT_HISR(void)
{
   ilm_struct     *Kp_ilm;

   if (KAL_FALSE == kbd_2key_detection_enable)
      return;
   /* LEVEL_HIGH: Original up, now down.*/
   if (KBD.ext_status[0] == LEVEL_HIGH)
   {
      kbd_push_onekey_to_kbdbuffer(kbd_onekey_press, DEVICE_KEY_EXT_A);
      kbd_ext_press_event_count++;
      GPTI_StartItem(KBD.gpthandle[KBD_KEY_DETECTION_CNT], KBD.longpress_timeout, KBDTimeOutHandler, (void *)KBD_KEY_DETECTION_CNT);
   }
   /* LEVEL_LOW: Original down, now up.*/
   else
   {
      GPTI_StopItem(KBD.gpthandle[KBD_KEY_DETECTION_CNT]); 
      kbd_push_onekey_to_kbdbuffer(kbd_onekey_release, DEVICE_KEY_EXT_A);
      kbd_ext_press_event_count--;
   }
   EINT_Set_Polarity(EINT_A_KEY, KBD.ext_status[0]);
   KBD.ext_status[0] = !(KBD.ext_status[0]);
   if (send_kbdilm)
   {
      send_kbdilm = KAL_FALSE;
   #ifndef L4_NOT_PRESENT
      DRV_BuildPrimitive(Kp_ilm,
                         MOD_DRVKBD,
                         MOD_UEM,
                         MSG_ID_DRVUEM_KEYPAD_IND,
                         NULL);

      msg_send_ext_queue(Kp_ilm);
   #endif   /*L4_NOT_PRESENT*/
   }
}


void EXT_B_EINT_HISR(void)
{
   ilm_struct     *Kp_ilm;

   if (KAL_FALSE == kbd_2key_detection_enable)
      return;
   /* LEVEL_HIGH: Original up, now down.*/
   if (KBD.ext_status[1] == LEVEL_HIGH)
   {
      kbd_push_onekey_to_kbdbuffer(kbd_onekey_press, DEVICE_KEY_EXT_B);
      kbd_ext_press_event_count++;
      GPTI_StartItem(KBD.gpthandle[KBD_KEY_DETECTION_CNT+1], KBD.longpress_timeout, KBDTimeOutHandler, (void *)(KBD_KEY_DETECTION_CNT+1));
   }
   /* LEVEL_LOW: Original down, now up.*/
   else
   {
      GPTI_StopItem(KBD.gpthandle[KBD_KEY_DETECTION_CNT+1]); 
      kbd_push_onekey_to_kbdbuffer(kbd_onekey_release, DEVICE_KEY_EXT_B);
      kbd_ext_press_event_count--;
   }
   EINT_Set_Polarity(EINT_B_KEY, KBD.ext_status[1]);
   KBD.ext_status[1] = !(KBD.ext_status[1]);
   if (send_kbdilm)
   {
      send_kbdilm = KAL_FALSE;
   #ifndef L4_NOT_PRESENT
      DRV_BuildPrimitive(Kp_ilm,
                         MOD_DRVKBD,
                         MOD_UEM,
                         MSG_ID_DRVUEM_KEYPAD_IND,
                         NULL);

      msg_send_ext_queue(Kp_ilm);
   #endif   /*L4_NOT_PRESENT*/
   }
}
#endif

/*
* FUNCTION
*  Kbd_Init
*
* DESCRIPTION
*     This function is keypad ini. function.
*
* CALLS
*  This function should be called before any keypad signal is coming
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void Kbd_Init(void)
{
   #ifndef KBD_DETECT_ONLY_ONE_KEY
   kal_uint8  index;
   #endif /*KBD_DETECT_ONLY_ONE_KEY*/

#if defined(DRV_KBD_MUX_WITH_GPIO) && defined(DRV_GPIO_REG_AS_6225)
   if ((2==GPIO_ReturnMode(35)) || (2==GPIO_ReturnMode(36)))
   {
      GPIO_PullenSetup(35, KAL_FALSE);
      GPIO_PullenSetup(36, KAL_FALSE);
      DRV_Reg(0x80000700) |= 0x0002; //ACIF_CON0 bit1
   }
#endif
   if (KBD.event == NULL)
      KBD.event = kal_create_event_group("KBDEVT");
      
   if ( KBD.hisr == NULL)
   {
      //KBD.hisr = kal_create_hisr("KP_HISR",2,512,Kbd_HisrEntry,NULL);
      KBD.hisr=(void*)0x1234;
      DRV_Register_HISR(DRV_KP_HISR_ID, Kbd_HisrEntry);
      
   }   

   IRQ_Register_LISR(IRQ_KPAD_CODE, Kbd_LISR,"KBD handler");
   
   #ifndef KBD_DETECT_ONLY_ONE_KEY
   for (index = 0; index < KBD_KEY_DETECTION_CNT; index++)
   {
      GPTI_GetHandle(&KBD.gpthandle[index]);
   }
      #ifdef __EXTRA_A_B_KEY_SUPPORT__
         GPTI_GetHandle(&KBD.gpthandle[KBD_KEY_DETECTION_CNT]);
         GPTI_GetHandle(&KBD.gpthandle[KBD_KEY_DETECTION_CNT+1]);
      #endif
   kbd_ext_press_event_count = 0;
   #else /*KBD_DETECT_ONLY_ONE_KEY*/
   GPTI_GetHandle(&KBD.gpthandle);
   #endif /*KBD_DETECT_ONLY_ONE_KEY*/

   #ifdef __KBD_2STEP_KEY_SUPPORT__
   GPTI_GetHandle(&KBD.kbd_2key_handle);
   #endif
   /* Bind callback functions */
#if defined(DRV_KBD_32KEYS_EQ_BELOW) || defined(FPGA)
   KBD.kbdmap_reg = ( ((kal_uint32)(DRV_Reg(KP_HI_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );
#endif   /*DRV_KBD_32KEYS_EQ_BELOW,FPGA*/
#if defined(DRV_KBD_32KEYS_ABOVE)
   KBD.kbdmap_reg = ( ((kal_uint32)(DRV_Reg(KP_MID_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );
   KBD.kbdmap_reg1 = (kal_uint32)(DRV_Reg(KP_HI_KEY));
   DRV_WriteReg(KP_DEBOUNCE,KP_DEBOUNCE_TIME);/*16ms*/
#elif defined(DRV_KBD_64KEYS_ABOVE)
   KBD.kbdmap_reg = ( ((kal_uint32)(DRV_Reg(KP_MID_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );
   KBD.kbdmap_reg1 = ( ((kal_uint32)(DRV_Reg(KP_MID2_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_MID1_KEY))) );
   KBD.kbdmap_reg2 = (kal_uint32)(DRV_Reg(KP_HI_KEY));
   DRV_WriteReg(KP_DEBOUNCE,KP_DEBOUNCE_TIME);/*16ms*/
#endif   /*DRV_KBD_32KEYS_ABOVE*/

   KBD.longpress_timeout = 200; /*2s*/
   KBD.repeat_time = 100;  /*1s*/   
   
   /**(volatile kal_uint16 *)KP_DEBOUNCE = KP_DEBOUNCE_TIME; // 1/32 sec */
   /* *(volatile kal_uint16 *)KP_SCAN = KP_SCAN_4KHZ; */
   IRQSensitivity(IRQ_KPAD_CODE,EDGE_SENSITIVE);
   IRQUnmask(IRQ_KPAD_CODE);

#if !defined(KBD_DETECT_ONLY_ONE_KEY) && defined(__EXTRA_A_B_KEY_SUPPORT__)
   KBD.ext_status[0] = LEVEL_HIGH;
   KBD.ext_status[1] = LEVEL_HIGH;
   if (EINT_A_KEY < EINT_MAX_CHANNEL)
      EINT_Registration(EINT_A_KEY, KAL_TRUE, LEVEL_LOW, EXT_A_EINT_HISR, KAL_TRUE);
   else
      EXTRA_EINT_Registration(EINT_A_KEY, LEVEL_LOW, EXT_A_EINT_HISR, KAL_TRUE);

   if (EINT_B_KEY < EINT_MAX_CHANNEL)
      EINT_Registration(EINT_B_KEY, KAL_TRUE, LEVEL_LOW, EXT_B_EINT_HISR, KAL_TRUE);
   else
      EXTRA_EINT_Registration(EINT_B_KEY, LEVEL_LOW, EXT_B_EINT_HISR, KAL_TRUE);
   EINT_Mask(EINT_A_KEY);
   EINT_Mask(EINT_B_KEY);
   EINT_Set_HW_Debounce(EINT_A_KEY, 50);
   EINT_Set_HW_Debounce(EINT_B_KEY, 50);

   /* for test A, B key. */
   //kbd_two_key_detection_switch(KAL_TRUE);
#endif
}
/*
* FUNCTION
*	   PowerKey_Pressed
*
* DESCRIPTION                                                           
*   	This function is to check if power key is pressed 
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   return keypressed result
*
* GLOBALS AFFECTED
*     None
*/

kal_bool PowerKey_Pressed(void)
{
   kal_uint32 i;
   kal_uint16 pwrkey_reg=0;
   kal_uint16 pwrkey_bit=0;
   kal_uint16 powerkey_status=0;
   for(i=0;i<kbd_allkeys;i++)
   {
      if(keypad_comm_def->keypad[i]==keypad_comm_def->powerkey_position)
      {
         pwrkey_reg=(i/16);         
         pwrkey_bit=0x0001 <<(i&0xf);
         break;
      }     
   }   
#if defined(DRV_KBD_MUX_WITH_GPIO)
   /* Need a delay to wait 32KHz sample for keypad scan. */
   for(i=0;i<1000000;i++)
   {
   }
#endif /* KBD_MUX_WITH_GPIO */
   switch(pwrkey_reg)
   {
       case low_key:
         powerkey_status= DRV_Reg(KP_LOW_KEY);
         break;
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
      case medium_key:
         powerkey_status= DRV_Reg(KP_MID_KEY);               
         break;
#endif          
#if defined(DRV_KBD_64KEYS_ABOVE)
      case medium_key1:
         powerkey_status= DRV_Reg(KP_MID1_KEY);
         break;
      case medium_key2:
         powerkey_status= DRV_Reg(KP_MID2_KEY);               
         break;
#endif          
      case high_key:
         powerkey_status= DRV_Reg(KP_HI_KEY);
         break;
      default:
         ASSERT(0);
         break;     
   }
        
   if((DRV_Reg(KP_STS) & KP_STS_KEYPRESS) && 
       ((~powerkey_status)&(pwrkey_bit))//((~DRV_Reg(KP_LOW_KEY))&(PWRKEY_index))
     )
   {
      return KAL_TRUE;
   }
   else
      return KAL_FALSE;  
        
    
}   

/*
* FUNCTION
*	   kbd_is_mutiple_key
*
* DESCRIPTION
*   	This function is to check if the key is multi-defined
*
* CALLS
*
* PARAMETERS
*	   kal_uint8 key
*
* RETURNS
*	   kal_bool
*
* GLOBALS AFFECTED
*     None
*/
kal_bool kbd_is_mutiple_key(kal_uint8 key)
{
   kal_uint8 i, key_count=0;
   
   for(i=0;i<kbd_allkeys;i++)
   {
      if(keypad_comm_def->keypad[i]==key)
      {        
         key_count++;
            if(key_count>=2)
               return KAL_TRUE;            
      }
   }
   
   return KAL_FALSE;    
}   
/*
* FUNCTION
*	   kbd_find_2step
*
* DESCRIPTION
*   	This function is to find who are 2 step key
*
* CALLS
*
* PARAMETERS
*	   *number: number of 2 step keys 
*		*two_step: 2 step key definition
*
* RETURNS
*	   none
*
* GLOBALS AFFECTED
*     None
*/
void kbd_find_2step(kal_uint32 *number, kal_uint8 *two_step)
{
	#ifdef __KBD_2STEP_KEY_SUPPORT__
	*number=1;
	*two_step=DEVICE_KEY_FUNCTION;
	#else
	*number=0;
	#endif
}	

/*************************************************************************
* FUNCTION                                                            
*	kbd_IsKeyButtonSupported
*
* DESCRIPTION                                                           
*	
*	This function queries if a specific key is supported or NOT
*  This function exists whether we support joystick or not
*
* PARAMETERS
*  key        - Key ID to query
*
* RETURNS
*  KAL_TRUE   - The specific key is supported in this phone
*  KAL_FALSE  - The specific key is NOT supported in this phone
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool kbd_IsKeyButtonSupported(kal_uint8 key){
	kal_uint32 num_key, i;
	kal_bool ret = KAL_FALSE;
	num_key = sizeof(keypad_comm_def->keypad)/sizeof(kal_uint8);
	for (i=0;i<num_key;i++){
		if ( key == keypad_comm_def->keypad[i] ){
			return KAL_TRUE;
		}
	}
	return ret;
}


#else /*!defined(__KBD_JOYSTICK_SUPPORT__)*/

kal_bool kbd_key_det_mode_switch(kbd_key_det_mode mode)
{
   return KAL_FALSE;
}

#endif /*!defined(__KBD_JOYSTICK_SUPPORT__)*/
