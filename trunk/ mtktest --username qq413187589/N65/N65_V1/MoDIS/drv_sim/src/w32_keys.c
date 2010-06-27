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
 *   w32_keys.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   keypad dummy functions for WIN32 environment
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <windows.h>

#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"

#include "stacklib.h"
#include "stack_timer.h"

#include "syscomp_config.h"
#include "task_config.h"
#include "kbd_table.h"

#include "device.h"
#include "drvsignals.h"
#include <assert.h>

#include "w32_keys.h"


#include "keypad_sw.h"
// MoDIS code use kbd_event_enum as kbd_event
typedef kbd_event kbd_event_enum;
// keypad mapping table used in MAUI
extern const keypad_struct  keypad_custom_def;



/***************************************************************************** 
* Define
*****************************************************************************/

/* use KAL service for timer */
#define KBD_TIMER_USE_KAL_SERVICE

/* turn on it for debugging */
//#define KBD_UNIT_DEBUG
#undef KBD_UNIT_DEBUG

#define  DRV_KBD_BUFFER_SIZE            32

#define KBD_TIMER_LONGPRESS_MIILLISECONDS  (1500)
#define KBD_TIMER_REPEAT_MIILLISECONDS     (1000)

#if defined(KBD_TIMER_USE_KAL_SERVICE)
   /* TBD. Assume: the value should be machince speed independant. */
   #define KBD_SPEED_RATION            (1.0/7)
   #define KBD_TIMER_LONGPRESS_TICKS   (KBD_TIMER_LONGPRESS_MIILLISECONDS * KAL_TICKS_10_MSEC /10.0 * KBD_SPEED_RATION)  /* 1 second */
   #define KBD_TIMER_REPEAT_TICKS      (KBD_TIMER_REPEAT_MIILLISECONDS * KAL_TICKS_10_MSEC /10.0 * KBD_SPEED_RATION)   /* 0.5 second */
#else
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef struct
{
   LOCAL_PARA_HDR
   keypad_status_enum keypad_status;
   keypad_code_enum keypad_code;
} uemdrv_keypad_ind_struct;

typedef struct 
{
   kal_uint8 logical_key;
} key_hw2sw_struct;


// use MAUI defined data type instead
//typedef enum 
//{
//   kbd_onekey_press=0,
//   kbd_onekey_release,
//   kbd_onekey_longpress,
//   kbd_onekey_repeated
//} kbd_event_enum;


typedef struct
{
   kbd_event_enum    Keyevent;
   kal_uint8         Keydata[1];
} kbd_data_struct;

typedef struct
{
   kbd_data_struct   kbd_data_buffer[DRV_KBD_BUFFER_SIZE];
   kal_uint8         kbd_data_buffer_rindex;
   kal_uint8         kbd_data_buffer_windex;
   int			      sum;
} kbd_buffer_struct_modis;



/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* physical to S/W key mappong */
static const key_hw2sw_struct key_hw2sw_table[] = 
{
   /* WIN32_EXT_KEY_1 */         {DEVICE_KEY_1},    
   /* WIN32_EXT_KEY_2 */         {DEVICE_KEY_2}, 
   /* WIN32_EXT_KEY_3 */         {DEVICE_KEY_3},
   /* WIN32_EXT_KEY_4 */         {DEVICE_KEY_4}, 
   /* WIN32_EXT_KEY_5 */         {DEVICE_KEY_5}, 
   /* WIN32_EXT_KEY_6 */         {DEVICE_KEY_6},  
   /* WIN32_EXT_KEY_7 */         {DEVICE_KEY_7},
   /* WIN32_EXT_KEY_8 */         {DEVICE_KEY_8}, 
   /* WIN32_EXT_KEY_9 */         {DEVICE_KEY_9}, 
   /* WIN32_EXT_KEY_10 */        {DEVICE_KEY_0},  
   /* WIN32_EXT_KEY_STAR */      {DEVICE_KEY_STAR},
   /* WIN32_EXT_KEY_HASH */      {DEVICE_KEY_HASH},
   /* WIN32_EXT_KEY_SK_LEFT */   {DEVICE_KEY_SK_LEFT},
   /* WIN32_EXT_KEY_SK_RIGHT */  {DEVICE_KEY_SK_RIGHT},
   /* WIN32_EXT_KEY_SEND */      {DEVICE_KEY_SEND},
   /* WIN32_EXT_KEY_END */       {DEVICE_KEY_END},
   /* WIN32_EXT_KEY_UP */        {DEVICE_KEY_UP},
   /* WIN32_EXT_KEY_DOWN */      {DEVICE_KEY_DOWN},
   /* WIN32_EXT_KEY_LEFT */      {DEVICE_KEY_LEFT},
   /* WIN32_EXT_KEY_RIGHT */     {DEVICE_KEY_RIGHT},
   /* WIN32_EXT_KEY_MENU */      {DEVICE_KEY_MENU},
   /* WIN32_EXT_KEY_FUNCTION */  {DEVICE_KEY_FUNCTION},
   /* WIN32_EXT_KEY_VOL_UP */    {DEVICE_KEY_VOL_UP},
   /* WIN32_EXT_KEY_VOL_DOWN */  {DEVICE_KEY_VOL_DOWN},
   /* WIN32_EXT_KEY_POWER */     {DEVICE_KEY_POWER},
   /* WIN32_EXT_KEY_CLEAR */     {DEVICE_KEY_CLEAR},
   /* WIN32_EXT_KEY_MP3_FWD */   {DEVICE_KEY_MP3_FWD},
   /* WIN32_EXT_KEY_MP3_PLAY_STOP */{DEVICE_KEY_MP3_PLAY_STOP},
   /* WIN32_EXT_KEY_MP3_BACK */  {DEVICE_KEY_MP3_BACK},
};

/* circular kbd buffer */

static kbd_buffer_struct_modis kbd_buffer; /* Note: sharing among threads */

/* already power on or not */
static kal_uint8 is_key_poweron = KAL_FALSE;

#if defined(KBD_TIMER_USE_KAL_SERVICE)
   static kal_timerid timerID; /* Note: sharing among threads ? */
#else
#endif

static CRITICAL_SECTION	keyBuf_cs;

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void kbd_long_detect(void *timer_param);
static void kbd_repeat_detect(void *timer_param);
static BOOL kbd_write_buffer(unsigned char key_code, unsigned char key_status);
static void kbd_uninit(void);
static void kbd_init(void);
static void kbd_send_msg_to_uem(msg_type msg_name, unsigned int para, unsigned int para2);

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*   Kbd_GetKeyData
* DESCRIPTION
*   kbd data buffer reader function
* PARAMETERS
*   keydata     OUT    key data
* RETURNS
*   Success or not
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
kal_bool Kbd_GetKeyData(kbd_data_struct *keydata)
{
   kal_bool result;

   EnterCriticalSection(&keyBuf_cs);

   if (kbd_buffer.sum > 0)
   {
	   keydata->Keydata[0] = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keydata[0];
	   keydata->Keyevent = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keyevent;
	   kbd_buffer.kbd_data_buffer_rindex ++;
	   kbd_buffer.kbd_data_buffer_rindex &= (DRV_KBD_BUFFER_SIZE-1);
	   kbd_buffer.sum --;
	   result = KAL_TRUE;
   }
   else
	  result = KAL_FALSE;

   LeaveCriticalSection(&keyBuf_cs);

#if defined(KBD_UNIT_DEBUG)
   kal_printf("Kbd_GetKeyData() status:%d code:%d return:%d\n", keydata->Keyevent, keydata->Keydata[0], result);
#endif
   return result;
}

/*****************************************************************************
* FUNCTION
*   w32_key_detect_ind
* DESCRIPTION
*   key event handling function for native system
* PARAMETERS
*   key_status     IN    physical key status, either KEY_PRESSED or KEY_RELEASED
*   key_code     IN    physical key code. Please refer to win32_ext_key_enum
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void w32_key_detect_ind(unsigned char phy_key_status, unsigned char phy_key_code)
{
   static unsigned char pre_phy_key_status = KEY_RELEASED;
   static unsigned char pre_phy_key_code = 0;

   /* key status with considering duration */
   unsigned char logi_key_status;
   /* key code */
   unsigned char logi_key_code;

#if defined(KBD_UNIT_DEBUG)
   kal_printf("w32_key_detect_ind() %d %d\n", phy_key_status, phy_key_code);
#endif

   if (is_key_poweron == KAL_TRUE)
   {
      /* in MS Windows, 
         a. long press PC keyboard, and there're continuous KEY_PRESSED events.
         b. long press mouse, and there's only one KEY_PRESSED event.
         Here, continuous KEY_PRESSSED events are ingored by comparing with previous logical key event 
      */
      if ((phy_key_code == pre_phy_key_code) &&
          (phy_key_status == KEY_PRESSED) && 
          (pre_phy_key_status == KEY_PRESSED))
      {
         /* ingore it */
         return;
      }

      /* in MS Windows, when user press/release sequence us 1-down, 2-down, 1-up, 2-up
         the Windows event would be: 
                                    phy-1-down, phy-2-down, phy-1-up, phy-2-up.
         we need to change to:
                                    phy-1-down, phy-1-up', phy-2-down, (phy-1-up'',) phy-2-up.
               phy-1-up'   is added here
               phy-1-up''  is removed here

      */
      if (phy_key_status == KEY_PRESSED) 
      {
         if ((pre_phy_key_status == KEY_PRESSED) && (phy_key_code != pre_phy_key_code))
            w32_key_detect_ind(KEY_RELEASED, pre_phy_key_code);
      }
      else if (phy_key_status == KEY_RELEASED) 
      {
         if (phy_key_code != pre_phy_key_code)
         {
            /* ingore it */
            return;
         }
      }
   }

   /* record the event */
   pre_phy_key_status = phy_key_status;
   pre_phy_key_code = phy_key_code;

   /* change to logical event */
   logi_key_status = phy_key_status;
   logi_key_code   = key_hw2sw_table[phy_key_code].logical_key;  

   if ((is_key_poweron == KAL_FALSE) && (logi_key_status == 1) && (logi_key_code == DEVICE_KEY_POWER))
   {
      kbd_init();

      kbd_send_msg_to_uem(MSG_ID_DRVUEM_POWER_ON_IND, (unsigned int)NULL, (unsigned int)NULL);
      is_key_poweron = KAL_TRUE;
	}
	else if (is_key_poweron == KAL_TRUE)
	{


      if(logi_key_status == KEY_RELEASED)
      {
#if defined(KBD_TIMER_USE_KAL_SERVICE)
      kal_cancel_timer(timerID);
#else
#endif
      }
      else if(logi_key_status == KEY_PRESSED)
      {
#if defined(KBD_TIMER_USE_KAL_SERVICE)
         kal_cancel_timer(timerID);
         kal_set_timer(timerID, (kal_timer_func_ptr)kbd_long_detect, (void*)logi_key_code, (kal_uint32)KBD_TIMER_LONGPRESS_TICKS, 0);
#else
#endif
      }

      if (TRUE == kbd_write_buffer(logi_key_code, logi_key_status))
         kbd_send_msg_to_uem(MSG_ID_DRVUEM_KEYPAD_IND, (unsigned int)logi_key_code, (unsigned int)logi_key_status);
	}
}

/*****************************************************************************
* FUNCTION
*   kbd_find_2step
* DESCRIPTION
*   legancy function (TBD)
* PARAMETERS
* RETURNS
* GLOBALS AFFECTED
*****************************************************************************/
void kbd_find_2step(kal_uint32 *number, kal_uint8 *two_step) 
{
   /* null function */
}

/*****************************************************************************
* FUNCTION
*   kbd_send_msg_to_uem
* DESCRIPTION
*   send kbd msg to UEM for necessary cases
* PARAMETERS
*   msg_name    IN    kbd relating msg name
*   para        IN    paramter 1, msg dependant.
*   para2       IN   paramter 2, msg dependant.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static void kbd_send_msg_to_uem(msg_type msg_name, unsigned int para, unsigned int para2)
{
	kal_bool ret_val = KAL_FALSE;
	ilm_struct *ilm_ptr = NULL;
	uemdrv_keypad_ind_struct *l_keypad_data;

   switch (msg_name)
   {
   case MSG_ID_DRVUEM_KEYPAD_IND:
      /* only send when buffer raising edge. If not, do nothing */
      EnterCriticalSection(&keyBuf_cs);
	   if(kbd_buffer.sum > 1)
      {
         LeaveCriticalSection(&keyBuf_cs);
         return;
      }
      LeaveCriticalSection(&keyBuf_cs);

      /* prepare to send */
      ilm_ptr = allocate_ilm( MOD_DRVKBD );
      ilm_ptr->msg_id = (kal_uint16) msg_name;
      ilm_ptr->peer_buff_ptr = NULL;

		l_keypad_data =  (uemdrv_keypad_ind_struct *) 
         construct_local_para( sizeof(uemdrv_keypad_ind_struct), TD_CTRL );

		l_keypad_data ->keypad_code = (unsigned char) para;
		l_keypad_data ->keypad_status = (unsigned char) para2;
      
		ilm_ptr->local_para_ptr = (local_para_struct *) l_keypad_data;
		ret_val = KAL_TRUE;
		break;

	case MSG_ID_DRVUEM_POWER_ON_IND:
      {
		   drvuem_power_on_ind_struct *p = (drvuem_power_on_ind_struct*)
						   construct_local_para(sizeof(drvuem_power_on_ind_struct),TD_CTRL);

		   ilm_ptr = allocate_ilm( MOD_DRVKBD );
		   ilm_ptr->msg_id = (kal_uint16) msg_name;
		   ilm_ptr->peer_buff_ptr = NULL;

		   p->power_on = PWRKEYPWRON;
		   p->poweron_time_left = 0;
		   ilm_ptr->local_para_ptr = (local_para_struct *) p;
		   ret_val = KAL_TRUE;
      }
      break;

	default :
		break;
   }
   
	/* Send the message to the UEM module */
	if (ret_val == KAL_TRUE)
	{
		SEND_ILM( MOD_DRVKBD, MOD_UEM, DRIVER_PS_SAP, ilm_ptr);
	}
	return;
}

/*****************************************************************************
* FUNCTION
*   kbd_init
* DESCRIPTION
*   init kbd driver module
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static void kbd_init(void) 
{
   /* system object */
#if defined(KBD_TIMER_USE_KAL_SERVICE)
   timerID = kal_create_timer("KbdTimer");
#else
#endif
   InitializeCriticalSection(&keyBuf_cs);

   
   /* buffer */
   EnterCriticalSection(&keyBuf_cs);
   kbd_buffer.kbd_data_buffer_rindex = kbd_buffer.kbd_data_buffer_windex  = kbd_buffer.sum = 0;    
   LeaveCriticalSection(&keyBuf_cs);
   return;
}

/*****************************************************************************
* FUNCTION
*   kbd_uninit
* DESCRIPTION
*   uninit kbd driver module
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static void kbd_uninit(void) 
{
   /* system object */
#if defined(KBD_TIMER_USE_KAL_SERVICE)
   kal_cancel_timer(timerID);
#else
#endif
   DeleteCriticalSection(&keyBuf_cs);

   return;
}

/*****************************************************************************
* FUNCTION
*   kbd_long_detect
* DESCRIPTION
*   deal with key longpress detected
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static void kbd_long_detect(void *timer_param)
{
   unsigned char key_code = (unsigned char)timer_param;
   unsigned char key_status = KEY_LONGPRESS;
#if defined(KBD_UNIT_DEBUG)
   kal_printf("kbd_long_detect\n");
#endif
   if (TRUE == kbd_write_buffer(key_code, key_status))
      kbd_send_msg_to_uem(MSG_ID_DRVUEM_KEYPAD_IND, (unsigned int)key_code, (unsigned int)key_status);

   /* whether need to issue repeat event later */
   kal_cancel_timer(timerID);
   kal_set_timer(timerID, (kal_timer_func_ptr)kbd_repeat_detect, (void*)key_code, (kal_uint32)KBD_TIMER_REPEAT_TICKS, 0);
}

/*****************************************************************************
* FUNCTION
*   kbd_repeat_detect
* DESCRIPTION
*   deal with key repeat detected
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static void kbd_repeat_detect(void *timer_param)
{
   unsigned char key_code = (unsigned char)timer_param;
   unsigned char key_status = KEY_REPEATED;
#if defined(KBD_UNIT_DEBUG)
   kal_printf("kbd_repeat_detect\n");
#endif
   if (TRUE == kbd_write_buffer(key_code, key_status))
      kbd_send_msg_to_uem(MSG_ID_DRVUEM_KEYPAD_IND, (unsigned int)key_code, (unsigned int)key_status);

   /* whether need to issue repeat event later */
   kal_cancel_timer(timerID);
   kal_set_timer(timerID, (kal_timer_func_ptr)kbd_repeat_detect, (void*)key_code, (kal_uint32)KBD_TIMER_REPEAT_TICKS, 0);
}

/*****************************************************************************
* FUNCTION
*   kbd_write_buffer
* DESCRIPTION
*   write to kbd buffer
* PARAMETERS
*   key_status     IN    key status
*   key_code     IN    key code
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static BOOL kbd_write_buffer(unsigned char key_code, unsigned char key_status)
{
   BOOL write = FALSE;

#if defined(KBD_UNIT_DEBUG)
   /* for debugging multi-thread program */
   kal_uint16 sum = kbd_buffer.sum;
	kal_uint16 size = DRV_KBD_BUFFER_SIZE;
#endif

   EnterCriticalSection(&keyBuf_cs);

   /* flow control to avoid key buffer full */
   if ((kbd_buffer.sum + 1) > (DRV_KBD_BUFFER_SIZE - 1))
   {
      /* ingore it */
      write = FALSE;
   }
   else if ((kbd_buffer.sum + 1) > (DRV_KBD_BUFFER_SIZE - 2))
   {
      if (key_status == KEY_RELEASED) 
         write = TRUE;
      else
         write = FALSE;
   }
   else
   {
      write = TRUE;
   }

   if (write == TRUE)
   {
		kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[0] = key_code;
	 	kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keyevent = key_status;
		kbd_buffer.kbd_data_buffer_windex ++;
		kbd_buffer.kbd_data_buffer_windex &= (DRV_KBD_BUFFER_SIZE-1);
		kbd_buffer.sum ++;
   }
   LeaveCriticalSection(&keyBuf_cs);
   return write;
}


/*************************************************************************
* FUNCTION                                                            
*	kbd_two_key_detection_switch
*
* DESCRIPTION                                                           
*	(Fake function to pass linking)
*	This function is to enable/disable the two key detction mode.
*
* PARAMETERS
*  KAL_TRUE   - To enable the two key detction mode.
*  KAL_FALSE  - To disable the two key detction mode.
*
* RETURNS
*  KAL_TRUE   - Enable or disable two key dection mode successfully.
*  KAL_FALSE  - Already in the mode. No need to set. 
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool kbd_two_key_detection_switch(kal_bool enable)
{
    /* MoDIS Not support */
    return KAL_FALSE;
}


// Use same prototype as that in MAUI
//kal_bool kbd_key_det_mode_switch(kal_uint32 mode)
//{
//    /* MoDIS Not support */
//    return KAL_FALSE;
//}
// The function is same as that used in MAUI
kal_bool kbd_key_det_mode_switch(kbd_key_det_mode mode)
{
    /* MoDIS Not support */
    return KAL_FALSE;
}




/*************************************************************************
* FUNCTION                                                            
*	kbd_IsKeyButtonSupported
*
* DESCRIPTION                                                           
*	
*	This function queries if a specific key is supported or NOT
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
	num_key = sizeof(keypad_custom_def.keypad)/sizeof(kal_uint8);
	for (i=0;i<num_key;i++){
		if ( key == keypad_custom_def.keypad[i] ){
			return KAL_TRUE;
		}
	}
	
	return ret;
}


