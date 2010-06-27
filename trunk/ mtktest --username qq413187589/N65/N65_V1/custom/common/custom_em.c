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
 * Filename:
 * ---------
 * custom_em.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for engineer mode.
 *
 * Author:
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
 * add pluto mmi compile option
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
 * compile error
 *
 * removed!
 * removed!
 * Let customer can configure ACM boundary, if acm is exceed the reasonable boundary, turn off ACM check and will not disconnect MO/MT call.
 *
 * removed!
 * rebase maintrunk.MAUI_MSZ on 03/17/2007 11:19:34 PM.
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
 * Network Events notification mech. support.
 *
 * removed!
 * removed!
 * Fix MoDIS compile warning.
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
 * download folder name customization
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __L1_STANDALONE__

/* System */
#include "fat_fs.h"
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_buff_alloc.h"
#include "app_ltlcom.h"

/* Drv */
#include "lcd_sw.h"
#include "pwm_sw.h"
#include "alerter_sw.h"
#include "gpio_sw.h"
#include "rtc_sw.h"
#include "uart_sw.h"

/* Custom_EM */
#include "custom_em.h"
#include "device.h"
#include "l1audio.h"
#include "resource_audio.h"

#if (defined(MT6218B) || defined(MT6219))
#include "lcd_if.h"
#endif

/* Globol variable */
kal_bool g_is_custom_em_init = KAL_FALSE;
custom_em_param_context_struct g_em_context;
extern LCD_Funcs *MainLCD;

#ifdef DUAL_LCD
extern LCD_Funcs *SubLCD;
#endif

//mtk00924 20051026:  +EIMG and +EMDY download to MS default folder name customization
//at most 25 characters in UCS2 format for folder name, and 0x005C and 0x0000 should be given at the end
kal_wchar CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME[] = {0x0041, 0x0075, 0x0064, 0x0069, 0x006F, 0x005C, 0x0000};  /* default folder = Audio */
kal_wchar CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME[] = {0x0049, 0x006D, 0x0061, 0x0067, 0x0065, 0x0073, 0x005C, 0x0000};  /* default folder = Images */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */


#if defined(__EM_MODE__) && defined(PLUTO_MMI)
/* Note:
 * 1. max event num in a group = MAX_NWEVENT_OF_A_GROUP = 20
 * 2. max string len of event name = MAX_LEN_OF_NW_EVENT_NAME = 20
 * 3. Please add the event in order with group id
 * 4. total event num should be less than EM_NW_EVENT_MAX_NUM_OF_EVENTS = 100
 */
em_network_event_struct em_network_event_tbl[] =
{
#ifdef __WCDMA_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else	
    /* Group 1 */
    {EM_NW_EVENT_GROUP_1, "RR", MOD_RMC, EM_NW_EVENT_ID_TEST1, "Event 1", 0},
    {EM_NW_EVENT_GROUP_1, "RR", MOD_RMC, EM_NW_EVENT_ID_TEST2, "Event 2", 0},
    {EM_NW_EVENT_GROUP_1, "RR", MOD_RMC, EM_NW_EVENT_ID_TEST3, "Event 3", 0},
    {EM_NW_EVENT_GROUP_1, "RR", MOD_RMC, EM_NW_EVENT_ID_TEST4, "Event 4", 0},
#endif

    /* Group 2 */
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST5, "Event 5", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST6, "Event 6", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST7, "Event 7", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST8, "Event 8", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST9, "Event 9", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST10, "Event 10", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST11, "Event 11", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST12, "Event 12", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST13, "Event 13", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST14, "Event 14", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST15, "Event 15", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST16, "Event 16", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST17, "Event 17", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST18, "Event 18", 0},
    {EM_NW_EVENT_GROUP_2, "SMU", MOD_SMU, EM_NW_EVENT_ID_TEST19, "Event 19", 0},

    /* Group 3 */
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST20, "Event 20", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST21, "Event 21", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST22, "Event 22", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST23, "Event 23", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST24, "Event 24", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST25, "Event 25", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST26, "Event 26", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST27, "Event 27", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST28, "Event 28", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST29, "Event 29", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST30, "Event 30", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST31, "Event 31", 0},
    {EM_NW_EVENT_GROUP_3, "TCM", MOD_TCM, EM_NW_EVENT_ID_TEST32, "Event 32", 0},

#ifdef __WCDMA_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    /* Group 4 */
    {EM_NW_EVENT_GROUP_4, "RMC", MOD_RMC, EM_NW_EVENT_ID_TEST33, "Event 33", 0},
    {EM_NW_EVENT_GROUP_4, "RMC", MOD_RMC, EM_NW_EVENT_ID_TEST34, "Event 34", 0},
#endif

    /* Group 5 */
    {EM_NW_EVENT_GROUP_5, "PHB", MOD_PHB, EM_NW_EVENT_ID_TEST35, "Event 35", 0},
    {EM_NW_EVENT_GROUP_5, "PHB", MOD_PHB, EM_NW_EVENT_ID_TEST36, "Event 36", 0},
    {EM_NW_EVENT_GROUP_5, "PHB", MOD_PHB, EM_NW_EVENT_ID_TEST37, "Event 37", 0},

    /* John Tang 2006/11/13 */
#ifdef __WCDMA_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #ifdef __WCDMA_RAT__ */    

};


/*****************************************************************************
 * FUNCTION
 *  em_nw_get_total_event
 * DESCRIPTION
 *
 * PARAMETERS
 *  is_reset        [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_uint32 em_nw_get_total_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(em_network_event_tbl)/sizeof(em_network_event_struct));
}
#endif /* #ifdef #if defined(__EM_MODE__) && defined(PLUTO_MMI) */


#define CM_DTMF_P_W_SWITCH_FLAG  KAL_FALSE

/* Lisen 08082005 */
#ifdef _LOW_COST_SINGLE_BANK_FLASH_


/*****************************************************************************
 * FUNCTION
 *  custom_em_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  is_reset        [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_init(kal_bool is_reset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 Ret, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&g_em_context, 0, sizeof(custom_em_param_context_struct));

    if (MainLCD && MainLCD->GetEngineeringModeParamNumber)
    {
        g_em_context.custom_em_main_lcd_param.bias_idx = MainLCD->GetEngineeringModeParamNumber(lcd_Bais_func);
        g_em_context.custom_em_main_lcd_param.contrast_idx = MainLCD->GetEngineeringModeParamNumber(lcd_Contrast_func);
        g_em_context.custom_em_main_lcd_param.linerate_idx = MainLCD->GetEngineeringModeParamNumber(lcd_LineRate_func);
        g_em_context.custom_em_main_lcd_param.temp_compensate_idx =
            MainLCD->GetEngineeringModeParamNumber(lcd_Temperature_Compensation_func);
    }
    else
    {
        kal_mem_set(&g_em_context.custom_em_main_lcd_param, 0, sizeof(custom_em_lcd_param_set_struct));
    }

#ifdef DUAL_LCD

    if (SubLCD && SubLCD->GetEngineeringModeParamNumber)
    {
        g_em_context.custom_em_sub_lcd_param.bias_idx = SubLCD->GetEngineeringModeParamNumber(lcd_Bais_func);
        g_em_context.custom_em_sub_lcd_param.contrast_idx = SubLCD->GetEngineeringModeParamNumber(lcd_Contrast_func);
        g_em_context.custom_em_sub_lcd_param.linerate_idx = SubLCD->GetEngineeringModeParamNumber(lcd_LineRate_func);
        g_em_context.custom_em_sub_lcd_param.temp_compensate_idx =
            SubLCD->GetEngineeringModeParamNumber(lcd_Temperature_Compensation_func);
    }
    else
    {
        kal_mem_set(&g_em_context.custom_em_sub_lcd_param, 0, sizeof(custom_em_lcd_param_set_struct));
    }

#else /* DUAL_LCD */

    kal_mem_set(&g_em_context.custom_em_sub_lcd_param, 0, sizeof(custom_em_lcd_param_set_struct));

#endif /* DUAL_LCD */

    g_is_custom_em_init = KAL_TRUE;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_flush_to_fs
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_flush_to_fs()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_get_from_fs
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_get_from_fs()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_lcd_get_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  lcd_param       [?]
 *  type            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_lcd_get_value(custom_em_lcd_param_set_struct *lcd_param, CUSTOM_EM_LCD_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (type)
    {
        case (CUSTOM_EM_LCD_MAIN):
            kal_mem_cpy(lcd_param, &g_em_context.custom_em_main_lcd_param, sizeof(custom_em_lcd_param_set_struct));
            break;
        case (CUSTOM_EM_LCD_SUB):
    #ifdef DUAL_LCD
            kal_mem_cpy(lcd_param, &g_em_context.custom_em_sub_lcd_param, sizeof(custom_em_lcd_param_set_struct));
    #endif
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_lcd_set_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  lcd_param       [?]
 *  type            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_lcd_set_value(custom_em_lcd_param_set_struct *lcd_param, CUSTOM_EM_LCD_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (type)
    {
        case (CUSTOM_EM_LCD_MAIN):
            kal_mem_cpy(&g_em_context.custom_em_main_lcd_param, lcd_param, sizeof(custom_em_lcd_param_set_struct));
            break;
        case (CUSTOM_EM_LCD_SUB):
    #ifdef DUAL_LCD
            kal_mem_cpy(&g_em_context.custom_em_sub_lcd_param, lcd_param, sizeof(custom_em_lcd_param_set_struct));
    #endif
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_lcd_get_param_number
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  func        [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 custom_em_lcd_get_param_number(CUSTOM_EM_LCD_TYPE type, CUSTOM_EM_LCD_FUNC_TYPE func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (type)
    {
        case (CUSTOM_EM_LCD_MAIN):
    #if (defined(MT6218B) || defined(MT6219))
            return lcd_get_parameter(MAIN_LCD, func);
    #else /* (defined(MT6218B) || defined(MT6219)) */ /* old platform */
            if (MainLCD && MainLCD->GetEngineeringModeParamNumber)
            {
                return MainLCD->GetEngineeringModeParamNumber(func);
            }
            else
            {
                return 0;
            }
    #endif /* (defined(MT6218B) || defined(MT6219)) */

        case (CUSTOM_EM_LCD_SUB):
        #ifdef DUAL_LCD
        #if (defined(MT6218B) || defined(MT6219))
            return lcd_get_parameter(SUB_LCD, func);
        #else /* (defined(MT6218B) || defined(MT6219)) */ /* old platform */
            if (SubLCD && SubLCD->GetEngineeringModeParamNumber)
            {
                return SubLCD->GetEngineeringModeParamNumber(func);
            }
            else
            {
                return 0;
            }
        #endif /* (defined(MT6218B) || defined(MT6219)) */
        #endif /* DUAL_LCD */
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_lcd_exe_function
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  func        [IN]
 *  param       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_lcd_exe_function(CUSTOM_EM_LCD_TYPE type, CUSTOM_EM_LCD_FUNC_TYPE func, kal_uint8 *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (func)
    {
        case (CUSTOM_EM_LCD_FUNC_BIAS):
            if (type == CUSTOM_EM_LCD_MAIN)
            {
                lcd_set_bias(MAIN_LCD, param);
            }
        #ifdef DUAL_LCD
            else if (type == CUSTOM_EM_LCD_SUB)
            {
                lcd_set_bias(SUB_LCD, param);
            }
        #endif /* DUAL_LCD */
            else
            {
                ASSERT(0);
            }
            break;

        case (CUSTOM_EM_LCD_FUNC_CONSTRAST):
            if (type == CUSTOM_EM_LCD_MAIN)
            {
                lcd_set_contrast(MAIN_LCD, param);
            }
        #ifdef DUAL_LCD
            else if (type == CUSTOM_EM_LCD_SUB)
            {
                lcd_set_contrast(SUB_LCD, param);
            }
        #endif /* DUAL_LCD */
            else
            {
                ASSERT(0);
            }
            break;

        case (CUSTOM_EM_LCD_FUNC_LINERATE):
            if (type == CUSTOM_EM_LCD_MAIN)
            {
                lcd_set_linerate(MAIN_LCD, param);
            }
        #ifdef DUAL_LCD
            else if (type == CUSTOM_EM_LCD_SUB)
            {
                lcd_set_linerate(SUB_LCD, param);
            }
        #endif /* DUAL_LCD */
            else
            {
                ASSERT(0);
            }
            break;

        case (CUSTOM_EM_LCD_FUNC_TEMPCOM):
            if (type == CUSTOM_EM_LCD_MAIN)
            {
                lcd_set_temp_compensate(MAIN_LCD, param);
            }
        #ifdef DUAL_LCD
            else if (type == CUSTOM_EM_LCD_SUB)
            {
                lcd_set_temp_compensate(SUB_LCD, param);
            }
        #endif /* DUAL_LCD */
            else
            {
                ASSERT(0);
            }
            break;
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_get_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  freq            [?]
 *  duty_cycle      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_pwm_get_value(kal_uint16 *freq, kal_uint8 *duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    kal_mem_cpy(freq, g_em_context.custom_em_pwm_param.freq, sizeof(g_em_context.custom_em_pwm_param.freq));
    kal_mem_cpy(
        duty_cycle,
        g_em_context.custom_em_pwm_param.duty_cycle,
        sizeof(g_em_context.custom_em_pwm_param.duty_cycle));
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_set_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  freq            [?]
 *  duty_cycle      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_pwm_set_value(kal_uint16 *freq, kal_uint8 *duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    kal_mem_cpy(g_em_context.custom_em_pwm_param.freq, freq, sizeof(g_em_context.custom_em_pwm_param.freq));
    kal_mem_cpy(
        g_em_context.custom_em_pwm_param.duty_cycle,
        duty_cycle,
        sizeof(g_em_context.custom_em_pwm_param.duty_cycle));
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_get_level_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  type            [IN]
 *  level           [IN]
 *  freq            [?]
 *  duty_cycle      [?]
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_pwm_get_level_value(
            CUSTOM_EM_PWM_TYPE type,
            CUSTOM_EM_PWM_LEVEL level,
            kal_uint16 *freq,
            kal_uint8 *duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    if (level >= CUSTOM_EM_PWM_LEVEL_MAX || type >= CUSTOM_EM_PWM_TYPE_MAX)
    {
        return KAL_FALSE;
    }

    *freq = g_em_context.custom_em_pwm_level_param[level].freq[type];
    *duty_cycle = g_em_context.custom_em_pwm_level_param[level].duty_cycle[type];

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_set_level_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  type            [IN]
 *  level           [IN]
 *  freq            [IN]
 *  duty_cycle      [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_pwm_set_level_value(
            CUSTOM_EM_PWM_TYPE type,
            CUSTOM_EM_PWM_LEVEL level,
            kal_uint16 freq,
            kal_uint8 duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    if (level >= CUSTOM_EM_PWM_LEVEL_MAX || type >= CUSTOM_EM_PWM_TYPE_MAX)
    {
        return KAL_FALSE;
    }

    g_em_context.custom_em_pwm_level_param[level].freq[type] = freq;
    g_em_context.custom_em_pwm_level_param[level].duty_cycle[type] = duty_cycle;

    return KAL_TRUE;

}

#else /* _LOW_COST_SINGLE_BANK_FLASH_ */


/*****************************************************************************
 * FUNCTION
 *  custom_em_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  is_reset        [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_init(kal_bool is_reset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VTCHAR filename[CUSTOM_EM_MAX_PATH_LENGTH];
    FS_HANDLE hFile = 0;
    kal_uint32 Ret, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check buffer boundary */
    Ret = CUSTOM_EM_GET_FULL_PATH_LEN;
    ASSERT(CUSTOM_EM_MAX_PATH_LENGTH > Ret);

    /* Create Folder if not exist */
    MAKE_CUSTOM_EM_PARAM_PATHNAME(filename);
    hFile = FS_Open((const VTCHAR*)filename, FS_READ_ONLY | FS_OPEN_DIR);
    if (hFile == FS_FILE_NOT_FOUND)
    {
        /* Return value should be FS_FILE_NOT_FOUND (-9) only, others treat as fatal error */
        Ret = FS_CreateDir((const VTCHAR*)filename);
        ASSERT(Ret == FS_NO_ERROR);
        is_reset = KAL_TRUE;
    }
    else if (hFile > FS_NO_ERROR)
    {
        FS_Close(hFile);
    }
    else
    {
        ASSERT(KAL_FALSE);
    }

    /* Create File if not exist */
    MAKE_CUSTOM_EM_PARAM_FILENAME(filename);
    if (is_reset == KAL_TRUE)
    {
        /* Create always, get default value */
        /* kal_mem_cpy( &g_em_context, CUSTOM_EM_PARAM_DEFAULT, sizeof( custom_em_param_context_struct ) ); */
        kal_mem_set(&g_em_context, 0, sizeof(custom_em_param_context_struct));
        hFile = FS_Open((const VTCHAR*)filename, FS_CREATE_ALWAYS | FS_READ_WRITE | FS_OPEN_NO_DIR);
        ASSERT(hFile >= FS_NO_ERROR);
    }
    else
    {
        /* Read from file */
        hFile = FS_Open((const VTCHAR*)filename, FS_READ_WRITE | FS_OPEN_NO_DIR);
        if (hFile == FS_FILE_NOT_FOUND)
        {
            /* kal_mem_cpy( &g_em_context, CUSTOM_EM_PARAM_DEFAULT, sizeof( custom_em_param_context_struct ) ); */
            kal_mem_set(&g_em_context, 0, sizeof(custom_em_param_context_struct));
            hFile = FS_Open((const VTCHAR*)filename, FS_CREATE_ALWAYS | FS_READ_WRITE | FS_OPEN_NO_DIR);
            ASSERT(hFile >= FS_NO_ERROR);
            is_reset = KAL_TRUE;
        }
        else
        {
            Ret = FS_Read(hFile, &g_em_context, sizeof(custom_em_param_context_struct), &len);
            ASSERT(Ret == FS_NO_ERROR);
            if (len == 0)
            {
                is_reset = KAL_TRUE;
            }
        }
    }

    if (MainLCD && MainLCD->GetEngineeringModeParamNumber)
    {
        g_em_context.custom_em_main_lcd_param.bias_idx = MainLCD->GetEngineeringModeParamNumber(lcd_Bais_func);
        g_em_context.custom_em_main_lcd_param.contrast_idx = MainLCD->GetEngineeringModeParamNumber(lcd_Contrast_func);
        g_em_context.custom_em_main_lcd_param.linerate_idx = MainLCD->GetEngineeringModeParamNumber(lcd_LineRate_func);
        g_em_context.custom_em_main_lcd_param.temp_compensate_idx =
            MainLCD->GetEngineeringModeParamNumber(lcd_Temperature_Compensation_func);
    }
    else
    {
        kal_mem_set(&g_em_context.custom_em_main_lcd_param, 0, sizeof(custom_em_lcd_param_set_struct));
    }

#ifdef DUAL_LCD

    if (SubLCD && SubLCD->GetEngineeringModeParamNumber)
    {
        g_em_context.custom_em_sub_lcd_param.bias_idx = SubLCD->GetEngineeringModeParamNumber(lcd_Bais_func);
        g_em_context.custom_em_sub_lcd_param.contrast_idx = SubLCD->GetEngineeringModeParamNumber(lcd_Contrast_func);
        g_em_context.custom_em_sub_lcd_param.linerate_idx = SubLCD->GetEngineeringModeParamNumber(lcd_LineRate_func);
        g_em_context.custom_em_sub_lcd_param.temp_compensate_idx =
            SubLCD->GetEngineeringModeParamNumber(lcd_Temperature_Compensation_func);
    }
    else
    {
        kal_mem_set(&g_em_context.custom_em_sub_lcd_param, 0, sizeof(custom_em_lcd_param_set_struct));
    }

#else /* DUAL_LCD */

    kal_mem_set(&g_em_context.custom_em_sub_lcd_param, 0, sizeof(custom_em_lcd_param_set_struct));

#endif /* DUAL_LCD */

    if (is_reset == KAL_TRUE)
    {
        Ret = FS_Write(hFile, &g_em_context, (kal_uint32) sizeof(g_em_context), &len);
        ASSERT(Ret == FS_NO_ERROR && len == sizeof(g_em_context));
    }

    if (hFile)
    {
        FS_Close(hFile);
    }

    g_is_custom_em_init = KAL_TRUE;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_flush_to_fs
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_flush_to_fs()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VTCHAR filename[CUSTOM_EM_MAX_PATH_LENGTH];
    FS_HANDLE hFile = 0;
    kal_uint32 Ret, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    MAKE_CUSTOM_EM_PARAM_FILENAME(filename);
    hFile = FS_Open((const VTCHAR*)filename, FS_READ_WRITE | FS_OPEN_NO_DIR);
    ASSERT(hFile > FS_NO_ERROR);

    Ret = FS_Write(hFile, &g_em_context, (kal_uint32) sizeof(custom_em_param_context_struct), &len);
    ASSERT(Ret == FS_NO_ERROR && len == sizeof(g_em_context));

    FS_Close(hFile);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_get_from_fs
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_get_from_fs()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VTCHAR filename[CUSTOM_EM_MAX_PATH_LENGTH];
    FS_HANDLE hFile = 0;
    kal_uint32 Ret, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    MAKE_CUSTOM_EM_PARAM_FILENAME(filename);
    hFile = FS_Open((const VTCHAR*)filename, FS_READ_WRITE | FS_OPEN_NO_DIR);
    ASSERT(hFile > FS_NO_ERROR);

    Ret = FS_Read(hFile, &g_em_context, (kal_uint32) sizeof(custom_em_param_context_struct), &len);
    ASSERT(Ret == FS_NO_ERROR && len == sizeof(g_em_context));

    FS_Close(hFile);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_lcd_get_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  lcd_param       [?]
 *  type            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_lcd_get_value(custom_em_lcd_param_set_struct *lcd_param, CUSTOM_EM_LCD_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (type)
    {
        case (CUSTOM_EM_LCD_MAIN):
            kal_mem_cpy(lcd_param, &g_em_context.custom_em_main_lcd_param, sizeof(custom_em_lcd_param_set_struct));
            break;
        case (CUSTOM_EM_LCD_SUB):
    #ifdef DUAL_LCD
            kal_mem_cpy(lcd_param, &g_em_context.custom_em_sub_lcd_param, sizeof(custom_em_lcd_param_set_struct));
    #endif
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_lcd_set_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  lcd_param       [?]
 *  type            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_lcd_set_value(custom_em_lcd_param_set_struct *lcd_param, CUSTOM_EM_LCD_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (type)
    {
        case (CUSTOM_EM_LCD_MAIN):
            kal_mem_cpy(&g_em_context.custom_em_main_lcd_param, lcd_param, sizeof(custom_em_lcd_param_set_struct));
            break;
        case (CUSTOM_EM_LCD_SUB):
    #ifdef DUAL_LCD
            kal_mem_cpy(&g_em_context.custom_em_sub_lcd_param, lcd_param, sizeof(custom_em_lcd_param_set_struct));
    #endif
            break;
        default:
            break;
    }
    custom_em_flush_to_fs();
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_lcd_get_param_number
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  func        [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 custom_em_lcd_get_param_number(CUSTOM_EM_LCD_TYPE type, CUSTOM_EM_LCD_FUNC_TYPE func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (type)
    {
        case (CUSTOM_EM_LCD_MAIN):
    #if (defined(MT6218B) || defined(MT6219))
            return lcd_get_parameter(MAIN_LCD, func);
    #else /* (defined(MT6218B) || defined(MT6219)) */ /* old platform */
            if (MainLCD && MainLCD->GetEngineeringModeParamNumber)
            {
                return MainLCD->GetEngineeringModeParamNumber(func);
            }
            else
            {
                return 0;
            }
    #endif /* (defined(MT6218B) || defined(MT6219)) */

        case (CUSTOM_EM_LCD_SUB):
        #ifdef DUAL_LCD
        #if (defined(MT6218B) || defined(MT6219))
            return lcd_get_parameter(SUB_LCD, func);
        #else /* (defined(MT6218B) || defined(MT6219)) */ /* old platform */
            if (SubLCD && SubLCD->GetEngineeringModeParamNumber)
            {
                return SubLCD->GetEngineeringModeParamNumber(func);
            }
            else
            {
                return 0;
            }
        #endif /* (defined(MT6218B) || defined(MT6219)) */
        #endif /* DUAL_LCD */
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_lcd_exe_function
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  func        [IN]
 *  param       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_lcd_exe_function(CUSTOM_EM_LCD_TYPE type, CUSTOM_EM_LCD_FUNC_TYPE func, kal_uint8 *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (func)
    {
        case (CUSTOM_EM_LCD_FUNC_BIAS):
            if (type == CUSTOM_EM_LCD_MAIN)
            {
                lcd_set_bias(MAIN_LCD, param);
            }
        #ifdef DUAL_LCD
            else if (type == CUSTOM_EM_LCD_SUB)
            {
                lcd_set_bias(SUB_LCD, param);
            }
        #endif /* DUAL_LCD */
            else
            {
                ASSERT(0);
            }
            break;

        case (CUSTOM_EM_LCD_FUNC_CONSTRAST):
            if (type == CUSTOM_EM_LCD_MAIN)
            {
                lcd_set_contrast(MAIN_LCD, param);
            }
        #ifdef DUAL_LCD
            else if (type == CUSTOM_EM_LCD_SUB)
            {
                lcd_set_contrast(SUB_LCD, param);
            }
        #endif /* DUAL_LCD */
            else
            {
                ASSERT(0);
            }
            break;

        case (CUSTOM_EM_LCD_FUNC_LINERATE):
            if (type == CUSTOM_EM_LCD_MAIN)
            {
                lcd_set_linerate(MAIN_LCD, param);
            }
        #ifdef DUAL_LCD
            else if (type == CUSTOM_EM_LCD_SUB)
            {
                lcd_set_linerate(SUB_LCD, param);
            }
        #endif /* DUAL_LCD */
            else
            {
                ASSERT(0);
            }
            break;

        case (CUSTOM_EM_LCD_FUNC_TEMPCOM):
            if (type == CUSTOM_EM_LCD_MAIN)
            {
                lcd_set_temp_compensate(MAIN_LCD, param);
            }
        #ifdef DUAL_LCD
            else if (type == CUSTOM_EM_LCD_SUB)
            {
                lcd_set_temp_compensate(SUB_LCD, param);
            }
        #endif /* DUAL_LCD */
            else
            {
                ASSERT(0);
            }
            break;
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_get_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  freq            [?]
 *  duty_cycle      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_pwm_get_value(kal_uint16 *freq, kal_uint8 *duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    kal_mem_cpy(freq, g_em_context.custom_em_pwm_param.freq, sizeof(g_em_context.custom_em_pwm_param.freq));
    kal_mem_cpy(
        duty_cycle,
        g_em_context.custom_em_pwm_param.duty_cycle,
        sizeof(g_em_context.custom_em_pwm_param.duty_cycle));
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_set_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  freq            [?]
 *  duty_cycle      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_pwm_set_value(kal_uint16 *freq, kal_uint8 *duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    kal_mem_cpy(g_em_context.custom_em_pwm_param.freq, freq, sizeof(g_em_context.custom_em_pwm_param.freq));
    kal_mem_cpy(
        g_em_context.custom_em_pwm_param.duty_cycle,
        duty_cycle,
        sizeof(g_em_context.custom_em_pwm_param.duty_cycle));
    custom_em_flush_to_fs();
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_get_level_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  type            [IN]
 *  level           [IN]
 *  freq            [?]
 *  duty_cycle      [?]
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_pwm_get_level_value(
            CUSTOM_EM_PWM_TYPE type,
            CUSTOM_EM_PWM_LEVEL level,
            kal_uint16 *freq,
            kal_uint8 *duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    if (level >= CUSTOM_EM_PWM_LEVEL_MAX || type >= CUSTOM_EM_PWM_TYPE_MAX)
    {
        return KAL_FALSE;
    }

    *freq = g_em_context.custom_em_pwm_level_param[level].freq[type];
    *duty_cycle = g_em_context.custom_em_pwm_level_param[level].duty_cycle[type];

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_set_level_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  type            [IN]
 *  level           [IN]
 *  freq            [IN]
 *  duty_cycle      [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_pwm_set_level_value(
            CUSTOM_EM_PWM_TYPE type,
            CUSTOM_EM_PWM_LEVEL level,
            kal_uint16 freq,
            kal_uint8 duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    if (level >= CUSTOM_EM_PWM_LEVEL_MAX || type >= CUSTOM_EM_PWM_TYPE_MAX)
    {
        return KAL_FALSE;
    }

    g_em_context.custom_em_pwm_level_param[level].freq[type] = freq;
    g_em_context.custom_em_pwm_level_param[level].duty_cycle[type] = duty_cycle;

    custom_em_flush_to_fs();

    return KAL_TRUE;

}

#endif /* _LOW_COST_SINGLE_BANK_FLASH_ */


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  freq        [IN]
 *  duty        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_pwm_start(CUSTOM_EM_PWM_TYPE type, kal_uint32 freq, kal_uint32 duty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (type)
    {
        case (CUSTOM_EM_PWM_TYPE_1):
            PWM1_Configure(freq, (kal_uint8) duty);
            PWM1_Start();
            break;
        case (CUSTOM_EM_PWM_TYPE_2):
    #if ( (defined(MT6205B)) || (defined(MT6218)) || (defined(MT6218B)))
            PWM2_Configure(freq, (kal_uint8) duty);
            PWM2_Start();
    #endif /* ( (defined(MT6205B)) || (defined(MT6218)) || (defined(MT6218B))) */
            break;
        case (CUSTOM_EM_PWM_TYPE_3):
            Alter_Configure(freq, (kal_uint8) duty);
            Alter_Start();
            break;
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_pwm_stop(CUSTOM_EM_PWM_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (type)
    {
        case (CUSTOM_EM_PWM_TYPE_1):
            PWM1_Stop();
            break;
        case (CUSTOM_EM_PWM_TYPE_2):
    #if ( (defined(MT6205B)) || (defined(MT6218)) || (defined(MT6218B)))
            PWM2_Stop();
    #endif
            break;
        case (CUSTOM_EM_PWM_TYPE_3):
            Alter_Stop();
            break;
        default:
            ASSERT(0);
            break;
    }
}

extern kal_uint8 PWM1_GetCurrentLevel(void);
extern kal_uint8 PWM2_GetCurrentLevel(void);
extern kal_uint8 Alter_GetCurrentLevel(void);
extern void PWM_level(kal_uint8 level);
extern void Alter_level(kal_uint8 level);
extern void DRV_RESET(void);
extern void DRV_POWEROFF(void);
extern kal_uint8 custom_cfg_hw_aud_output_path(kal_uint8 speaker_id);
extern kal_uint8 custom_cfg_hw_aud_input_path(kal_uint8 mic_id);
extern kal_bool Get_UART_Detection_Status(UART_PORT port);
extern void UART_Detection_Enable(UART_PORT port, kal_bool enable_flag);


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_get_hw_current_level
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 custom_em_pwm_get_hw_current_level(CUSTOM_EM_PWM_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case (CUSTOM_EM_PWM_TYPE_1):
            return PWM1_GetCurrentLevel();
        case (CUSTOM_EM_PWM_TYPE_2):
    #if ( (defined(MT6205B)) || (defined(MT6218)) || (defined(MT6218B)))
            return PWM2_GetCurrentLevel();
    #else
            return 0;
    #endif
        case (CUSTOM_EM_PWM_TYPE_3):
            return Alter_GetCurrentLevel();
        default:
            ASSERT(0);
            break;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_set_level
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  level       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_pwm_set_level(CUSTOM_EM_PWM_TYPE type, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case (CUSTOM_EM_PWM_TYPE_1):
            PWM_level(level);
            break;
        case (CUSTOM_EM_PWM_TYPE_2):
    #if ( (defined(MT6205B)) || (defined(MT6218)) || (defined(MT6218B)))
            PWM2_level(level);
    #endif
            break;
        case (CUSTOM_EM_PWM_TYPE_3):
            Alter_level(level);
            break;
        default:
            ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  custom_em_gpio_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_gpio_start(kal_uint8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GPIO_WriteIO(1, port);
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_gpio_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_gpio_stop(kal_uint8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GPIO_WriteIO(0, port);
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_gpo_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_gpo_start(kal_uint8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GPO_WriteIO(1, port);
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_gpo_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_gpo_stop(kal_uint8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GPO_WriteIO(0, port);
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_gpo_writeio
 * DESCRIPTION
 *
 * PARAMETERS
 *  data        [IN]
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_gpo_writeio(kal_int8 data, kal_int8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GPO_WriteIO(data, port);
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwn_cycle
 * DESCRIPTION
 *
 * PARAMETERS
 *  is_on       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_pwn_cycle(kal_bool is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_on)
    {
        DRV_RESET();
    }
    else
    {
        DRV_POWEROFF();
        DRV_RESET();
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_rtc_get_time
 * DESCRIPTION
 *
 * PARAMETERS
 *  year        [?]
 *  mon         [?]
 *  day         [?]
 *  hour        [?]
 *  min         [?]
 *  sec         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_rtc_get_time(
        kal_uint16 *year,
        kal_uint8 *mon,
        kal_uint8 *day,
        kal_uint8 *hour,
        kal_uint8 *min,
        kal_uint8 *sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    t_rtc l_rtctime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RTC_GetTime(&l_rtctime);
    *sec = l_rtctime.rtc_sec;
    *min = l_rtctime.rtc_min;
    *hour = l_rtctime.rtc_hour;
    *day = l_rtctime.rtc_day;
    *mon = l_rtctime.rtc_mon;
    *year = l_rtctime.rtc_year;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_test
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_test()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * custom_em_lcd_param_set_struct aaa;
     * kal_uint16 freq[3];
     * kal_uint8 duty_cycle[3];
     *
     * custom_em_init(KAL_FALSE);
     * custom_em_lcd_get_value( &aaa, CUSTOM_EM_LCD_MAIN );
     * aaa.bias_idx = 1;
     * aaa.contrast_idx = 2;
     * aaa.linerate_idx = 3;
     * aaa.temp_compensate_idx = 4;
     * kal_mem_set( &aaa.bias[0], 0x5, 10 );
     * kal_mem_set( &aaa.contrast[0], 0x6, 10 );
     * kal_mem_set( &aaa.linerate[0], 0x7, 10 );
     * kal_mem_set( &aaa.temp_compensate[0], 0x8, 10 );
     *
     * custom_em_lcd_set_value( &aaa, CUSTOM_EM_LCD_MAIN );
     *
     * custom_em_lcd_set_value( &aaa, CUSTOM_EM_LCD_SUB );
     *
     * kal_mem_set( &aaa, 0x0, sizeof(custom_em_lcd_param_set_struct) );
     * custom_em_lcd_get_value( &aaa, CUSTOM_EM_LCD_SUB );
     *
     * custom_em_lcd_exe_function(CUSTOM_EM_LCD_MAIN, lcd_Bais_func, &aaa.bias[0] );
     * custom_em_lcd_exe_function(CUSTOM_EM_LCD_MAIN, lcd_Contrast_func, &aaa.contrast[0] );
     * custom_em_lcd_exe_function(CUSTOM_EM_LCD_MAIN, lcd_LineRate_func, &aaa.linerate[0] );
     * custom_em_lcd_exe_function(CUSTOM_EM_LCD_MAIN, lcd_Temperature_Compensation_func, &aaa.temp_compensate[0] );
     *
     * custom_em_lcd_exe_function(CUSTOM_EM_LCD_SUB, lcd_Bais_func, &aaa.bias[0] );
     * custom_em_lcd_exe_function(CUSTOM_EM_LCD_SUB, lcd_Contrast_func, &aaa.contrast[0] );
     * custom_em_lcd_exe_function(CUSTOM_EM_LCD_SUB, lcd_LineRate_func, &aaa.linerate[0] );
     * custom_em_lcd_exe_function(CUSTOM_EM_LCD_SUB, lcd_Temperature_Compensation_func, &aaa.temp_compensate[0] );
     *
     * custom_em_pwm_get_value(freq, duty_cycle );
     * freq[0] = 1;  duty_cycle[0] = 1;
     * freq[1] = 2;  duty_cycle[1] = 2;
     * freq[2] = 3;  duty_cycle[2] = 3;
     *
     * custom_em_pwm_set_value(freq, duty_cycle );
     * custom_em_pwm_start(CUSTOM_EM_PWM_TYPE_1, freq[0], duty_cycle[0] );
     * custom_em_pwm_start(CUSTOM_EM_PWM_TYPE_2, freq[1], duty_cycle[1] );
     * custom_em_pwm_start(CUSTOM_EM_PWM_TYPE_3, freq[2], duty_cycle[2] );
     * custom_em_pwm_stop(CUSTOM_EM_PWM_TYPE_1);
     * custom_em_pwm_stop(CUSTOM_EM_PWM_TYPE_2);
     * custom_em_pwm_stop(CUSTOM_EM_PWM_TYPE_3);
     */
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_set_gain
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  gain        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_set_gain(kal_uint8 type, kal_uint8 gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case VOL_TYPE_CTN:
            TONE_SetOutputVolume(gain, 0);
            break;
        case VOL_TYPE_KEY:
            KT_SetOutputVolume(gain, 0);
            break;
        case VOL_TYPE_MIC:
            L1SP_SetMicrophoneVolume(gain);
            break;
        case VOL_TYPE_SPH:
            L1SP_SetOutputVolume(gain, 0);
            break;
        case VOL_TYPE_SID:
            L1SP_SetSidetoneVolume(gain);
            break;
        case VOL_TYPE_MEDIA:
            Media_SetOutputVolume(gain, 0);
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  custom_em_set_loopback
 * DESCRIPTION
 *
 * PARAMETERS
 *  on      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_set_loopback(kal_bool on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L1SP_SetAfeLoopback(on);
    if (on)
    {
        L1SP_Speech_On(0);
    }
    else
    {
        L1SP_Speech_Off();
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_get_melody_version
 * DESCRIPTION
 *
 * PARAMETERS
 *  mel_ver     [?]
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_get_melody_version(kal_char *mel_ver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 file_handle;
    kal_wchar file_name[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(file_name, "%s\\melody_ver.txt", "c:\\def_sound\\imelody");
    file_handle = FS_Open(file_name, FS_READ_ONLY | FS_OPEN_NO_DIR);

    if (file_handle >= 0)
    {
        kal_uint32 len;

        FS_Read(file_handle, mel_ver, 50, &len);

        /* close the file */
        FS_Close(file_handle);

    }
    else
    {
        strcpy(mel_ver, "Melody V0.0");
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_melody_key_shift
 * DESCRIPTION
 *
 * PARAMETERS
 *  level       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_melody_key_shift(kal_int32 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Media_Control(MEDIA_CTRL_KEY_SHIFT, level) != MEDIA_SUCCESS)
        return KAL_FALSE;;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_get_uart_detection_status
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool custom_em_get_uart_detection_status(CUSTOM_EM_PORT_TYPE port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (port)
    {
        case CUSTOM_EM_UART_PORT1:
            return Get_UART_Detection_Status(uart_port1);
        case CUSTOM_EM_UART_PORT2:
            return Get_UART_Detection_Status(uart_port2);
    #ifdef __UART3_SUPPORT__
        case CUSTOM_EM_UART_PORT3:
            return Get_UART_Detection_Status(uart_port3);
    #endif /* __UART3_SUPPORT__ */
        default:
            return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_set_uart_detection_status
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 *  enable      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_set_uart_detection_status(CUSTOM_EM_PORT_TYPE port, kal_bool enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (port)
    {
        case CUSTOM_EM_UART_PORT1:
            UART_Detection_Enable(uart_port1, enable);
            break;
        case CUSTOM_EM_UART_PORT2:
            UART_Detection_Enable(uart_port2, enable);
            break;
    #ifdef __UART3_SUPPORT__
        case CUSTOM_EM_UART_PORT3:
            UART_Detection_Enable(uart_port3, enable);
            break;
    #endif /* __UART3_SUPPORT__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_at_audio_download_folder
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_wchar *custom_get_at_audio_download_folder()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME;
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_at_image_download_folder
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_wchar *custom_get_at_image_download_folder()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME;
}

/*****************************************************************************
* FUNCTION
*  cm_p_w_switch
* DESCRIPTION
*   This function is used to define if "P"(pause) and "W"(wait for user command)
*   of DTMF separator is switched or not
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool cm_dtmf_p_w_switch (void)
{
   return (CM_DTMF_P_W_SWITCH_FLAG);
}

#ifdef __CUSTOM_CONFIG_ACM_BOUND__
/*****************************************************************************
* FUNCTION
*  custom_is_acm_exceed_boundary
* DESCRIPTION
*   This function is used to check if acm exceed the boundary.
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool custom_is_acm_exceed_boundary (kal_uint32 acm_value)
{
       return ((kal_bool)(acm_value > CUSTOM_ACM_BOUND));
}
#endif

#endif /* __L1_STANDALONE__ */

#ifdef __GEMINI__
/*****************************************************************************
* FUNCTION
*  custom_dual_sim_has_two_imei
* DESCRIPTION
*   For Dual SIM projects, this function is used to check if customer use two IMEIs or one
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool custom_has_more_than_1_imei(void)
{
   return (CUSTOM_DUAL_SIM_TWO_IMEI);
}
#endif


