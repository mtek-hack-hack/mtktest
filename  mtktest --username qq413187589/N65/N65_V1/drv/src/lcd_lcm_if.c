/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   lcd_lcm_if.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This function implements LCM interface adaptation layer
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Code Review.
 *
 * removed!
 * removed!
 * Update header to log check-in records.
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#include "kal_release.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_sw.h"
#include "lcd_sw_inc.h"
#include "lcd_hw.h"
#include "lcd_sw.h"
#include "lcd_if.h"
#include "visual_comm.h"
#include "drv_hisr.h"

#if defined(DRV_IDP_SUPPORT)
   #include "visual_comm.h"
   #include "img_comm.h"
   #include "imgproc.h"
   #include "imgdma.h"
   #if (defined(ISP_SUPPORT))
      #include "isp_if.h"
   #endif
   #ifdef TV_OUT_SUPPORT
      #include "tv_out.h"
      #include "2d_engine.h"
   #endif
#endif //DRV_IDP_SUPPORT

#include "msdc_lsd.h"


/**
 * Set Rotation of LCM
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param rotate_value the rotate value of LCM
 *
 * @return None.
 */
void lcd_set_rotate(kal_uint8 lcd_id, kal_uint8 rotate_value)
{   
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/   
   
#ifdef LCM_ROTATE_SUPPORT
   current_lcd_rotate_value=rotate_value;
   if (MAIN_LCD==lcd_id)
   {
      ASSERT(MainLCD->SetRotation!=NULL);
      MainLCD->SetRotation(rotate_value);
   }
   #ifdef DUAL_LCD
   else if (SUB_LCD==lcd_id)
   {
      ASSERT(SubLCD->SetRotation!=NULL)
      SubLCD->SetRotation(rotate_value);
   }
   #endif
#endif
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
}



/**
 * Set the temperature compensation parameters of LCM
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param compensate the temperature compensate of LCM
 *
 * @return None.
 */
void lcd_set_temp_compensate(kal_uint8 lcd_id, kal_uint8 *compensate)
{
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id)
   {
      case MAIN_LCD:
#if ( !defined(MT6205B) && !defined(MT6208) )
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
#endif
         MainLCD->SetTemperatureCompensate(compensate);
      break;
#ifdef DUAL_LCD
      case SUB_LCD:
   #if ( !defined(MT6205B) && !defined(MT6208) )
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
   #endif
         SubLCD->SetTemperatureCompensate(compensate);
      break;
#endif   /* DUAL_LCD */
      default:
         ASSERT(0);
      break;
   }
   lcd_power_ctrl(KAL_FALSE);
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
}



/**
 * set the line rate of LCM.
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param linereate the line rate of LCM
 *
 * @return None.
 */
void lcd_set_linerate(kal_uint8 lcd_id, kal_uint8 *linereate)
{
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id)
   {
      case MAIN_LCD:
#if ( !defined(MT6205B) && !defined(MT6208) )
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
#endif
         MainLCD->SetLineRate(linereate);
      break;
#ifdef DUAL_LCD
      case SUB_LCD:
   #if ( !defined(MT6205B) && !defined(MT6208) )
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
   #endif
         SubLCD->SetLineRate(linereate);
      break;
#endif   /* DUAL_LCD */
      default:
         ASSERT(0);
      break;
   }
  lcd_power_ctrl(KAL_FALSE);
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
}



/**
 * set the contrast of LCM.
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param contrast the contrast of LCM
 *
 * @return None.
 */
void lcd_set_contrast(kal_uint8 lcd_id, kal_uint8 *contrast)
{
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id)
   {
      case MAIN_LCD:
#if ( !defined(MT6205B) && !defined(MT6208) )
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
#endif
         MainLCD->SetContrast(contrast);
      break;
#ifdef DUAL_LCD
      case SUB_LCD:
   #if ( !defined(MT6205B) && !defined(MT6208) )
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
   #endif
         SubLCD->SetContrast(contrast);
      break;
#endif   /* DUAL_LCD */
      default:
         ASSERT(0);
      break;
   }
   lcd_power_ctrl(KAL_FALSE);
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
}



/**
 * set the bias of LCM.
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param bias the bias of LCM
 *
 * @return None.
 */
void lcd_set_bias(kal_uint8 lcd_id, kal_uint8 *bias)
{
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id)
   {
      case MAIN_LCD:
#if ( !defined(MT6205B) && !defined(MT6208) )
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
#endif
         MainLCD->SetBias(bias);
      break;
#ifdef DUAL_LCD
      case SUB_LCD:
   #if ( !defined(MT6205B) && !defined(MT6208) )
         DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
         DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
   #endif
         SubLCD->SetBias(bias);
      break;
#endif   /* DUAL_LCD */
      default:
         ASSERT(0);
      break;
   }
   lcd_power_ctrl(KAL_FALSE);
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
}



/**
 * Get the width and height of LCM
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param lcd_width the width of LCM
 * @param lcd_height the height of LCM
 *
 * @return None.
 */
void lcd_get_size(kal_uint8 lcd_id, kal_uint16 *lcd_width, kal_uint16 *lcd_height)
{
   switch (lcd_id)
   {
      case MAIN_LCD:
         MainLCD->GetSize(lcd_width, lcd_height);
      break;
#ifdef DUAL_LCD
      case SUB_LCD:
         SubLCD->GetSize(lcd_width, lcd_height);
      break;
#endif   /* DUAL_LCD */
      default:
         ASSERT(0);
      break;
   }
}



/**
 * Get the specified parameter of LCM
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param type which parameter will be returned (bias, contrast, linerate or
 *             temperature compensation)
 *
 * @return the value of the specified parameter of LCM
 */
kal_uint8 lcd_get_parameter(kal_uint8 lcd_id,lcd_func_type type)
{
   kal_uint8 return_value=0;

   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   switch (lcd_id)
   {
      case MAIN_LCD:
         return_value=MainLCD->GetEngineeringModeParamNumber(type);
      break;
#ifdef DUAL_LCD
      case SUB_LCD:
         return_value=SubLCD->GetEngineeringModeParamNumber(type);
      break;
#endif   /* DUAL_LCD */
      default:
         ASSERT(0);
      break;
   }
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   return return_value;
}



/**
 * Turns on/off LCM screen
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param on turn on/off screen (KAL_TRUE/KAL_FALSE)
 *
 * @return None.
 */
void lcd_screen_on(kal_uint8 lcd_id, kal_bool on)
{
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id)
   {
      case MAIN_LCD:
         #if ( !defined(MT6205B) && !defined(MT6208) )
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
         #endif
         MainLCD->TurnOnScreen(on);
         break;
#ifdef DUAL_LCD
      case SUB_LCD:
         #if ( !defined(MT6205B) && !defined(MT6208) )
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
         #endif
         SubLCD->TurnOnScreen(on);
         break;
#endif   /* DUAL_LCD */
      default:
         ASSERT(0);
         break;
   }
   lcd_power_ctrl(KAL_FALSE);
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
}



/**
 * Turns on/off LCM power
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param on turn on/off LCM power (KAL_TRUE/KAL_FALSE)
 *
 * @return None.
 */
void lcd_power_on(kal_uint8 lcd_id, kal_bool on)
{
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id)
   {
      case MAIN_LCD:
         #if ( !defined(MT6205B) && !defined(MT6208) )
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
         #endif
         MainLCD->TurnOnPower(on);
         break;
#ifdef DUAL_LCD
      case SUB_LCD:
         #if ( !defined(MT6205B) && !defined(MT6208) )
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
         #endif
         SubLCD->TurnOnPower(on);
         break;
#endif   /* DUAL_LCD */
      default:
         ASSERT(0);
         break;
   }
   lcd_power_ctrl(KAL_FALSE);
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
}



/**
 * Display partial screen on LCD
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param start_line the first line to display
 * @param end_line the last line to display
 *
 * @return None.
 */
void lcd_partial_on(kal_uint8 lcd_id, kal_uint16 start_line, kal_uint16 end_line)
{
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id)
   {
      case MAIN_LCD:
         #if ( !defined(MT6205B) && !defined(MT6208) )
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
         #endif
         if (MainLCD->TurnOnPartialDisplay != NULL) {
            MainLCD->TurnOnPartialDisplay(start_line,end_line);
         }
         break;
   #ifdef DUAL_LCD
      case SUB_LCD:
         #if ( !defined(MT6205B) && !defined(MT6208) )
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
         #endif
         if (SubLCD->TurnOnPartialDisplay != NULL) {
            SubLCD->TurnOnPartialDisplay(start_line,end_line);
         }
         break;
   #endif   /* DUAL_LCD */
      default:
         ASSERT(0);
         break;
   }
   lcd_power_ctrl(KAL_FALSE);
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
}



/**
 * Exit partial display mode
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 *
 * @return None.
 */
void lcd_partial_off(kal_uint8 lcd_id)
{
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id)
   {
      case MAIN_LCD:
         #if ( !defined(MT6205B) && !defined(MT6208) )
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
         #endif
         if (MainLCD->TurnOffPartialDisplay != NULL) {
            MainLCD->TurnOffPartialDisplay();
         }
         break;
   #ifdef DUAL_LCD
      case SUB_LCD:
         #if ( !defined(MT6205B) && !defined(MT6208) )
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
         #endif /* MT6218B, MT6219 */
         if (SubLCD->TurnOffPartialDisplay != NULL) {
            SubLCD->TurnOffPartialDisplay();
         }
         break;
   #endif   /* DUAL_LCD */
      default:
         ASSERT(0);
         break;
   }
   lcd_power_ctrl(KAL_FALSE);
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
}



/**
 * Get align line for partial display
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 *
 * @return align line for partial display
 */
kal_uint8 lcd_partial_display_align_line(kal_uint8 lcd_id)
{
   kal_uint8 returnValue = 0;
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   switch (lcd_id)
   {
      case MAIN_LCD:
         if (MainLCD->GetPartialDisplayAlignment != NULL){
            returnValue = MainLCD->GetPartialDisplayAlignment();
            LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
            return returnValue;
         }
         else{
            LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
            return 0;
         }
         break;
   #ifdef DUAL_LCD
      case SUB_LCD:
         if (SubLCD->GetPartialDisplayAlignment != NULL){
            returnValue = SubLCD->GetPartialDisplayAlignment();
            LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
            return returnValue;
         }
         else{
            LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
            return 0;
         }
         break;
   #endif   /* DUAL_LCD */
      default:
            LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
         ASSERT(0);
         break;
   }
   return 0;
}



/**
 * Set the brightness of LCM
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param bright_level brightness level of LCM
 *
 * @return None.
 */
void lcd_bright_level(kal_uint8 lcd_id, kal_uint8 bright_level)
{
   LSD_TakeControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
   lcd_power_ctrl(KAL_TRUE);
   switch (lcd_id)
   {
      case MAIN_LCD:
         #if ( !defined(MT6205B) && !defined(MT6208) )
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
         #endif
         MainLCD->SetBrightLevel(bright_level);
         break;
#ifdef DUAL_LCD
      case SUB_LCD:
         #if ( !defined(MT6205B) && !defined(MT6208) )
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
         #endif
         SubLCD->SetBrightLevel(bright_level);
         break;
#endif   /* DUAL_LCD */
      default:
         ASSERT(0);
         break;
   }
   lcd_power_ctrl(KAL_FALSE);
   LSD_GiveControl(LSD_LCDARB_LCD);/*to protect when LCD and MSDC share pins*/
}
