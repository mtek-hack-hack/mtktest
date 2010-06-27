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
 *    keypad_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for keypad driver and adaption.
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
#ifndef _KEYPAD_SW_H
#define _KEYPAD_SW_H

#include "drv_features.h"

/* #define TWO_KEY_ENABLE */
/*#define KBD_DBGMODE */    /*to check buffer full when MMI is too slow */
#if defined(__TWO_KEY_DETECTION_SWITCHABLE__)
   #define KBD_KEY_DETECTION_CNT 2

   #ifdef __EXTRA_A_B_KEY_SUPPORT__
      #define KBD_GPT_HDL_CNT    4
   #else /*__EXTRA_A_B_KEY_SUPPORT__*/
      #define KBD_GPT_HDL_CNT    2
   #endif/*__EXTRA_A_B_KEY_SUPPORT__*/

#elif defined(__THREE_KEY_DETECTION_SWITCHABLE__)
   #define KBD_KEY_DETECTION_CNT 3

   #ifdef __EXTRA_A_B_KEY_SUPPORT__
      #define KBD_GPT_HDL_CNT    5
   #else /*__EXTRA_A_B_KEY_SUPPORT__*/
      #define KBD_GPT_HDL_CNT    3
   #endif/*__EXTRA_A_B_KEY_SUPPORT__*/


#else
   #define KBD_DETECT_ONLY_ONE_KEY
#endif /* __TWO_KEY_DETECTION_SWITCHABLE__ */

typedef enum {
   kbd_1_key_det_mode = 0,
   kbd_2_keys_det_mode,
   kbd_3_keys_det_mode
} kbd_key_det_mode;

#if defined(TWO_KEY_ENABLE)
   #if defined(__TWO_KEY_DETECTION_SWITCHABLE__) || defined(__THREE_KEY_DETECTION_SWITCHABLE__)
   #error " kbd config conflicts!!"
   #endif
#endif

#if defined(DRV_KBD_25_KEYS) || defined(FPGA)
   #define  kbd_allkeys          25
#elif defined(DRV_KBD_36_KEYS)
   #define  kbd_allkeys          36
#elif defined(DRV_KBD_42_KEYS)
   #define  kbd_allkeys          42   
#elif defined(DRV_KBD_35_KEYS)
   #define  kbd_allkeys          35
#elif defined(DRV_KBD_72_KEYS)
   #define  kbd_allkeys          72
#endif   /*DRV_KBD_25_KEYS,FPGA*/

#define  kbd_buffer_size         32


/*keypad*/
typedef enum {
      low_key=0,
#if defined(DRV_KBD_32KEYS_ABOVE)
      medium_key,
#elif defined(DRV_KBD_64KEYS_ABOVE)
      medium_key,
      medium_key1,
      medium_key2,
#endif      
      high_key

} kbd_type;
/*keypad*/
typedef enum {
      kbd_onekey_press=0,
      kbd_onekey_release,
#ifdef TWO_KEY_ENABLE
      kbd_twokey_press,
      kbd_twokey_release,
#endif   /*TWO_KEY_ENABLE*/
      kbd_onekey_longpress,
      kbd_onekey_repeated,
      kbd_onekey_fullpress,
      kbd_twokey_detection_enable,
      kbd_threekey_detection_enable,
      kbd_multikey_detection_disable
} kbd_event;

typedef struct
{
   kbd_event   Keyevent;
#ifdef TWO_KEY_ENABLE
   kal_uint8   Keydata[2];
#else /*!TWO_KEY_ENABLE*/
   kal_uint8   Keydata[1];
#endif   /*TWO_KEY_ENABLE*/
} kbd_data;

typedef struct
{
   kal_hisrid        hisr;
   kal_eventgrpid    event;
   #ifndef KBD_DETECT_ONLY_ONE_KEY
      #ifdef __EXTRA_A_B_KEY_SUPPORT__
      kal_uint8      gpthandle[KBD_GPT_HDL_CNT];
      kal_bool       ext_status[2];
      #else /*__EXTRA_A_B_KEY_SUPPORT__*/
      kal_uint8         gpthandle[2];
      #endif/*__EXTRA_A_B_KEY_SUPPORT__*/
   #else
   kal_uint8         gpthandle;
   #endif
   #ifdef __KBD_2STEP_KEY_SUPPORT__
   kal_uint8         kbd_2key_handle;   
   #endif
   kal_uint32        longpress_timeout;
   kal_uint32        repeat_time;
   kal_uint32        kbdmap_reg;
   #if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
      kal_uint32        kbdmap_reg1;
   #endif   /*DRV_KBD_32KEYS_ABOVE*/
   #if defined(DRV_KBD_64KEYS_ABOVE)
      kal_uint32        kbdmap_reg2;
   #endif   /*DRV_KBD_64KEYS_ABOVE*/
} kbd_struct;

typedef struct
{
   kbd_data       kbd_data_buffer[kbd_buffer_size];
   kal_uint8      kbd_data_buffer_rindex;
   kal_uint8      kbd_data_buffer_windex;
} kbd_buffer_struct;

/*Customizae Keypad*/
typedef struct {
	/*keypad mapping*/
   kal_uint8 keypad[kbd_allkeys];
	/*power on period*/
   kal_uint32 Custom_Keypress_Period;
   /*power key  position*/
   kal_uint8 powerkey_position;   
} keypad_struct;
typedef struct {  
   const keypad_struct * (*keypad_Get_Data)(void);
   #ifdef __KBD_2STEP_KEY_SUPPORT__   
   kal_bool (*keypad_is_fullpress)(kal_uint8 key);
   kal_bool (*keypad_check_fullpress)(void);   
   #endif 
}keypad_customize_function_struct;  


#if !defined(KBD_DETECT_ONLY_ONE_KEY) && defined(__EXTRA_A_B_KEY_SUPPORT__)
      extern const kal_uint8    EXTRA_A_KEY_EINT_NO;
      extern const kal_uint8    EXTRA_B_KEY_EINT_NO;
      #define  EINT_A_KEY     EXTRA_A_KEY_EINT_NO
      #define  EINT_B_KEY     EXTRA_B_KEY_EINT_NO
#endif


#define kbd_push_onekey_to_kbdbuffer(_event,_key)   \
{\
   ASSERT(kbd_push_assert == KAL_FALSE);\
   kbd_push_assert = KAL_TRUE;\
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keyevent = _event;\
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[0] = _key;\
   kbd_buffer.kbd_data_buffer_windex++;\
   kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);\
   kbd_push_assert = KAL_FALSE;\
}

#define kbd_push_twokey_to_kbdbuffer(_event,_key1,_key2)   \
{\
   ASSERT(kbd_push_assert == KAL_FALSE);\
   kbd_push_assert = KAL_TRUE;\
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keyevent = _event;\
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[0] = _key1;\
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[1] = _key2;\
   kbd_buffer.kbd_data_buffer_windex++;\
   kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);\
   kbd_push_assert = KAL_FALSE;\
}

#define kbdbuffer_get_roomleft(_left)   \
{\
   if ( kbd_buffer.kbd_data_buffer_rindex <= kbd_buffer.kbd_data_buffer_windex ) \
	{\
      _left = kbd_buffer_size - kbd_buffer.kbd_data_buffer_windex + kbd_buffer.kbd_data_buffer_rindex - 1;\
	}\
	else\
	{\
		_left = kbd_buffer.kbd_data_buffer_rindex - kbd_buffer.kbd_data_buffer_windex - 1;\
	}\
}

#ifdef TWO_KEY_ENABLE
   #define kbd_pop_twokey_from_kbdbuffer(_event,_key1,_key2)   \
   {\
      ASSERT(kbd_pop_assert == KAL_FALSE);\
      kbd_pop_assert = KAL_TRUE;\
      _event = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keyevent;\
      _key1 = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keydata[0];\
      _key2 = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keydata[1];\
      kbd_buffer.kbd_data_buffer_rindex++;\
      kbd_buffer.kbd_data_buffer_rindex &= (kbd_buffer_size-1);\
      kbd_pop_assert = KAL_FALSE;\
   }
#else /*!TWO_KEY_ENABLE*/
   #define kbd_pop_onekey_from_kbdbuffer(_event,_key)   \
   {\
      ASSERT(kbd_pop_assert == KAL_FALSE);\
      kbd_pop_assert = KAL_TRUE;\
      _event = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keyevent;\
      _key = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keydata[0];\
      kbd_buffer.kbd_data_buffer_rindex++;\
      kbd_buffer.kbd_data_buffer_rindex &= (kbd_buffer_size-1);\
      kbd_pop_assert = KAL_FALSE;\
   }
#endif   /*TWO_KEY_ENABLE*/
extern kal_bool PowerKey_Pressed(void);
extern kal_bool kbd_is_mutiple_key(kal_uint8 key);
extern void keypad_customize_init(void);
extern kal_bool kbd_key_det_mode_switch(kbd_key_det_mode mode);
extern kal_bool kbd_IsKeyButtonSupported(kal_uint8 key);
#endif


