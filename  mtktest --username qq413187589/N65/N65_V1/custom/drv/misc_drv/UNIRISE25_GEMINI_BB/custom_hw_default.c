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
 *   custom_hw_default.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains definition of custom component module configuration
 *   variables, and routines handle for equipment device.
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
/*
**   Includes
*/


#include "kal_release.h"
#include "custom_hw_default.h"

#ifndef __L1_STANDALONE__

#include "stack_types.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"

#include "custom_nvram_editor_data_item.h"


#endif /* __L1_STANDALONE__ */

#ifdef MMI_ON_HARDWARE_P
#include "Pmic6318_sw.h"
#endif

/* 
**   Globol Varibales 
*/

kal_uint32 PWM1_Level_Info[PWM_MAX_LEVEL][2] = 
{
   /*Freq,duty*/
   {200,20},    /*Level 1*/
   {200,40},    /*Level 2*/
   {200,60},    /*Level 3*/
   {200,80},    /*Level 4*/
   {200,100}    /*Level 5*/
};

kal_uint32 PWM2_Level_Info[PWM_MAX_LEVEL][2] = 
{
   /*Freq,duty*/
   {200,30},    /*Level 1*/
   {200,25},    /*Level 2*/
   {200,20},    /*Level 3*/
   {200,15},    /*Level 4*/
   {200,10}    /*Level 5*/
};

kal_uint32 Alter_Level_Info[PWM_MAX_LEVEL][2] = 
{
   /*Freq,duty*/
   {200,20},    /*Level 1*/
   {200,40},    /*Level 2*/
   {200,60},    /*Level 3*/
   {200,80},    /*Level 4*/
   {200,100}    /*Level 5*/
};

#if defined(MT6318)
kal_uint32 PMIC6318_PWM_Level_Info[PWM_MAX_LEVEL][2] = 
{
   /*Freq,duty*/
   {200,20},    /*Level 1*/
   {200,40},    /*Level 2*/
   {200,60},    /*Level 3*/
   {200,80},    /*Level 4*/
   {200,100}    /*Level 5*/
};

kal_uint16 pmic_custom_get_bl_pmw_type(void)
{
   // Choose BL_LED or KP_LED. If no use, just return 0.
   return KP_LED;
}
#endif
/* 2009.04.14 modified by hongzhe.liu + */
const kal_uint8 DEFAULT_HARDWARE_YEAR = 9; //2009
const kal_uint8 DEFAULT_HARDWARE_MON = 6;
const kal_uint8 DEFAULT_HARDWARE_DAY = 1;
/* 2009.04.14 modified by hongzhe.liu - */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//50ms * 10 = 0.5 sec
const kal_uint32 ADC_BOOTUP_EVAL_PERIOD  =  KAL_TICKS_50_MSEC;  
const kal_uint32 ADC_BOOTUP_EVAL_COUNT   =  10;

//10sec * 6 = 1min
const kal_uint32 ADC_IDLE_EVAL_PERIOD  =  (2*KAL_TICKS_5_SEC);
const kal_uint32 ADC_IDLE_EVAL_COUNT   =   6;

//5sec * 6 = 30sec
const kal_uint32 ADC_TALKING_EVAL_PERIOD  = (KAL_TICKS_5_SEC);
const kal_uint32 ADC_TALKING_EVAL_COUNT   =  6;

//150 * 10 ms = 1.5 sec  (unit : 10ms )
const kal_uint32 KPD_LONGPRESS_PERIOD  = 150;

//50 * 10ms = 0.5 sec  (unit : 10ms )
const kal_uint32 KPD_REPEAT_PERIOD     = 50;

#ifndef __L1_STANDALONE__

kal_uint8   MainLCD_Contrast_Level_Info[LCD_CONTRAST_MAX_LEVEL];
kal_uint8   MainLCD_Bias_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   MainLCD_Linerate_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   MainLCD_Temp_Level_Info[LCD_PARAM_MAX_LEVEL];
   
#ifdef DUAL_LCD
kal_uint8   SubLCD_Contrast_Level_Info[LCD_CONTRAST_MAX_LEVEL];
kal_uint8   SubLCD_Bias_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   SubLCD_Linerate_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   SubLCD_Temp_Level_Info[LCD_PARAM_MAX_LEVEL];
#endif

kal_uint32   Battery_Level_Info[BATTERY_MAX_LEVEL];


void  custom_init_hardware_level(void *hw_level_struct)
{
    kal_uint8 i, j;

   custom_hw_level_struct *hw_level = (custom_hw_level_struct *)hw_level_struct;

    for( i=0; i< LCD_CONTRAST_MAX_LEVEL; i++ )
    {
        MainLCD_Contrast_Level_Info[i]= hw_level->MainLCD_Contrast[i];
#ifdef DUAL_LCD        
        SubLCD_Contrast_Level_Info[i]= hw_level->SubLCD_Contrast[i];
#endif        
    }

    for( i=0; i< LCD_PARAM_MAX_LEVEL; i++ )
    {
        MainLCD_Bias_Level_Info[i]= hw_level->MainLCD_Bias[i];
        MainLCD_Linerate_Level_Info[i]= hw_level->MainLCD_Linerate[i];
        MainLCD_Temp_Level_Info[i] =  hw_level->MainLCD_Temp[i];
#ifdef DUAL_LCD
        SubLCD_Bias_Level_Info[i]= hw_level->SubLCD_Bias[i];
        SubLCD_Linerate_Level_Info[i]= hw_level->SubLCD_Linerate[i];
        SubLCD_Temp_Level_Info[i] =  hw_level->SubLCD_Temp[i];
#endif        
    }

    for( i=0; i< BATTERY_MAX_LEVEL; i++ )
      Battery_Level_Info[i] = hw_level->BatteryLevel[i];

   for( i=0; i<PWM_MAX_LEVEL; i++ )
      for( j=0; j<2; j++ )
         {
               PWM1_Level_Info[i][j] = hw_level->PWM1[i][j];
               PWM2_Level_Info[i][j] = hw_level->PWM2[i][j];
               Alter_Level_Info[i][j] = hw_level->PWM3[i][j];
         }
      
#if defined(MT6318)   
   for( i=0; i<PWM_MAX_LEVEL; i++ )
      for( j=0; j<2; j++ )
         {
             PMIC6318_PWM_Level_Info[i][j] = hw_level->PMIC6318BLPWM[i][j];
         }
#endif      

}

#endif /* __L1_STANDALONE__ */


