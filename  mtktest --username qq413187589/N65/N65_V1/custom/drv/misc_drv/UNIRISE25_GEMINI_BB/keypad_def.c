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
 *    keypad_def.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for keypad table
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "kbd_table.h"
#include "keypad_sw.h"
#ifdef __CUST_NEW__
#include "keypad_drv.h"
#endif /*__CUST_NEW__*/

const keypad_struct *keypad_Get_Data(void); 
#ifdef __CUST_NEW__
   #define Custom_Keypress_Period KEY_PRESS_PERIOD
   kal_uint8 powerkey_position=POWERKEY_POSITION;
#else /*__CUST_NEW__*/
   #define Custom_Keypress_Period 2500
   kal_uint8 powerkey_position=DEVICE_KEY_END;
#endif  /*__CUST_NEW__*/

const keypad_struct  keypad_custom_def = {          
      /*keypad mapping*/
      {
      #ifndef __CUST_NEW__
          /* row 0 */
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_3,
          DEVICE_KEY_2,
          DEVICE_KEY_1,
          DEVICE_KEY_POWER,//DEVICE_KEY_POWER,
      
      	 /* row 1 */
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_6,
          DEVICE_KEY_5,
          DEVICE_KEY_4,
          DEVICE_KEY_POWER,//DEVICE_KEY_POWER,
          
      	 /* row 2 */
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,//DEVICE_KEY_MP3,
          DEVICE_KEY_9,
          DEVICE_KEY_8,
          DEVICE_KEY_7,
          DEVICE_KEY_POWER,//DEVICE_KEY_POWER,
                    
      	 /* row 3 */
          DEVICE_KEY_VOL_UP,
          DEVICE_KEY_VOL_DOWN, 
          DEVICE_KEY_NONE, 
          DEVICE_KEY_HASH, 
          DEVICE_KEY_0, 
          DEVICE_KEY_STAR, 
          DEVICE_KEY_POWER,//DEVICE_KEY_POWER,
          
      	 /* row 4 */
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_POWER,//DEVICE_KEY_POWER,
      
      	 /* row 5 */
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_NONE,
          DEVICE_KEY_POWER,//DEVICE_KEY_POWER,
      #else /* __CUST_NEW__ */
          KEYPAD_MAPPING
      #endif /* __CUST_NEW__ */
      },
      /*power on period*/
      Custom_Keypress_Period,                  
      /*powerkey position*/
      #ifndef __CUST_NEW__
      /*powerkey position*/
      DEVICE_KEY_POWER            
      #else /* __CUST_NEW__ */
      POWERKEY_POSITION
      #endif /* __CUST_NEW__ */
      };      
const keypad_customize_function_struct keypad_custom_func=
{
     keypad_Get_Data
};            
const keypad_customize_function_struct *keypad_GetFunc(void)
{
   return (&keypad_custom_func);  
}   
const keypad_struct *keypad_Get_Data(void) 
{
   return (&keypad_custom_def);
}
kal_uint32 Customer_Period_Period(void)
{         
   return ((kal_uint32) Custom_Keypress_Period);
}   

