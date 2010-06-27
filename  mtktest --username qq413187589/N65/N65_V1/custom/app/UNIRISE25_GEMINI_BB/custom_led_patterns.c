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
 *   custom_led_patterns.c
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

#ifndef __L1_STANDALONE__

/*
 *   Includes
 */
#include "kal_release.h"
#include "stack_types.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "device.h"
#include "custom_led_patterns.h"

/*
 *  LED pattern 
 */
#define LED_LEVEL_0  0
#define LED_LEVEL_1  1
#define LED_LEVEL_2  2
#define LED_LEVEL_3  3
#define LED_LEVEL_4  4
#define LED_LEVEL_5  5

/* Power On */
const LED_PATTERN_STRUCT led_gpio_ptn1[] = 
{
    /* red ligth 1, green ligth 2, blue light 3, duration time */
    {{LED_LEVEL_5, LED_LEVEL_0, LED_LEVEL_0}, 500},
    {{LED_LEVEL_0, LED_LEVEL_5, LED_LEVEL_0}, 500},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_5}, 500},
    {{LED_LEVEL_5, LED_LEVEL_5, LED_LEVEL_0}, 500},
    {{LED_LEVEL_0, LED_LEVEL_5, LED_LEVEL_5}, 500},
    {{LED_LEVEL_5, LED_LEVEL_0, LED_LEVEL_5}, 500},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Power Off */
const LED_PATTERN_STRUCT led_gpio_ptn2[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_5, LED_LEVEL_5}, 500},
    {{LED_LEVEL_5, LED_LEVEL_0, LED_LEVEL_5}, 500},
    {{LED_LEVEL_5, LED_LEVEL_5, LED_LEVEL_0}, 500},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_5}, 500},
    {{LED_LEVEL_0, LED_LEVEL_5, LED_LEVEL_0}, 500},
    {{LED_LEVEL_5, LED_LEVEL_0, LED_LEVEL_0}, 500},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Battery Warning */
const LED_PATTERN_STRUCT led_gpio_ptn3[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_5, LED_LEVEL_0, LED_LEVEL_0}, 100},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 2000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Battery Low */
const LED_PATTERN_STRUCT led_gpio_ptn4[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 7000},
    {{LED_LEVEL_1, LED_LEVEL_0, LED_LEVEL_0}, 100},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Camp on 900 */
const LED_PATTERN_STRUCT led_gpio_ptn5[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 7000},
    {{LED_LEVEL_0, LED_LEVEL_1, LED_LEVEL_0}, 100},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Camp on 1800 */
const LED_PATTERN_STRUCT led_gpio_ptn6[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 7000},
    {{LED_LEVEL_0, LED_LEVEL_1, LED_LEVEL_0}, 100},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Power Off Charging */
const LED_PATTERN_STRUCT led_gpio_ptn7[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 7000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_2}, 100},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Power Off Charging, Full Charge */
const LED_PATTERN_STRUCT led_gpio_ptn8[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_2, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Message In */
const LED_PATTERN_STRUCT led_gpio_ptn9[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_5, LED_LEVEL_5, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Message Remain */
const LED_PATTERN_STRUCT led_gpio_ptn10[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_5, LED_LEVEL_5, LED_LEVEL_0}, 100},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 7000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Caller Group 1 */
const LED_PATTERN_STRUCT led_gpio_ptn11[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_5, LED_LEVEL_0, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Caller Group 2 */
const LED_PATTERN_STRUCT led_gpio_ptn12[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_5, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Caller Group 3 */
const LED_PATTERN_STRUCT led_gpio_ptn13[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_5}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Caller Group 4 */
const LED_PATTERN_STRUCT led_gpio_ptn14[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_5, LED_LEVEL_0, LED_LEVEL_5}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Caller Group 5 */
const LED_PATTERN_STRUCT led_gpio_ptn15[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_5, LED_LEVEL_5, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Caller Group 6 */
const LED_PATTERN_STRUCT led_gpio_ptn16[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_5, LED_LEVEL_5}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 1000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Limit Service */
const LED_PATTERN_STRUCT led_gpio_ptn17[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 7000},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_1}, 100},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* No Service */
const LED_PATTERN_STRUCT led_gpio_ptn18[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 7000},
    {{LED_LEVEL_1, LED_LEVEL_0, LED_LEVEL_0}, 100},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Connect 1900 */
const LED_PATTERN_STRUCT led_gpio_ptn19[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 7000},
    {{LED_LEVEL_0, LED_LEVEL_1, LED_LEVEL_0}, 100},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

/* Roaming */
const LED_PATTERN_STRUCT led_gpio_ptn20[] = 
{
    /* ligth 1, ligth 2, light 3, duration time */
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 7000},
    {{LED_LEVEL_1, LED_LEVEL_1, LED_LEVEL_1}, 100},
    {{LED_LEVEL_0, LED_LEVEL_0, LED_LEVEL_0}, 0}    /* duration timer is zero to terminate it */
};

const LED_PATTERN_STRUCT *led_gpio_patterns[] = 
{
    led_gpio_ptn1,
    led_gpio_ptn2,
    led_gpio_ptn3,
    led_gpio_ptn4,
    led_gpio_ptn5,
    led_gpio_ptn6,
    led_gpio_ptn7,
    led_gpio_ptn8,
    led_gpio_ptn9,
    led_gpio_ptn10,
    led_gpio_ptn11,
    led_gpio_ptn12,
    led_gpio_ptn13,
    led_gpio_ptn14,
    led_gpio_ptn15,
    led_gpio_ptn16,
    led_gpio_ptn17,
    led_gpio_ptn18,
    led_gpio_ptn19,
    led_gpio_ptn20
};

/*
 *  LCD pattern 
 */
#define LCD_LEVEL_0  0
#define LCD_LEVEL_1  1

const LCD_PATTERN_STRUCT lcd_gpio_ptn1[] = 
{
    /* lcd, duration time */
    {{LCD_LEVEL_1}, 1000},
    {{LCD_LEVEL_0}, 1000},  /* duration timer is zero to terminate it */
    {{LCD_LEVEL_0}, 0}      /* duration timer is zero to terminate it */
};
const LCD_PATTERN_STRUCT lcd_gpio_ptn2[] = 
{
    /* lcd, duration time */
    {{LCD_LEVEL_1}, 0}  /* duration timer is zero to terminate it */
};
const LCD_PATTERN_STRUCT *lcd_gpio_patterns[] = 
{
    lcd_gpio_ptn1,
    lcd_gpio_ptn2
};

/*
 *  VIB pattern 
 */
#define VIB_LEVEL_0  0
#define VIB_LEVEL_1  1

const VIB_PATTERN_STRUCT vib_gpio_ptn1[] = 
{
    /* vib, duration time */
    {{VIB_LEVEL_1}, 1000},
    {{VIB_LEVEL_0}, 1000},
    {{VIB_LEVEL_0}, 0}  /* duration timer is zero to terminate it */
};

const VIB_PATTERN_STRUCT vib_gpio_ptn2[] = 
{
    /* vib duration time */
    {{VIB_LEVEL_1}, 0}  /* duration timer is zero to terminate it */
};

const VIB_PATTERN_STRUCT vib_gpio_ptn3[] = 
{
    /* Incomming SMS */
    {{VIB_LEVEL_1}, 500},   /* duration timer is zero to terminate it */
    {{VIB_LEVEL_0}, 500},   /* duration timer is zero to terminate it */
    {{VIB_LEVEL_1}, 500},   /* duration timer is zero to terminate it */
    {{VIB_LEVEL_0}, 1500},  /* duration timer is zero to terminate it */
    {{VIB_LEVEL_1}, 500},   /* duration timer is zero to terminate it */
    {{VIB_LEVEL_0}, 500},   /* duration timer is zero to terminate it */
    {{VIB_LEVEL_1}, 500},   /* duration timer is zero to terminate it */
    {{VIB_LEVEL_0}, 0}      /* duration timer is zero to terminate it */
};

const VIB_PATTERN_STRUCT *vib_gpio_patterns[] = 
{
    vib_gpio_ptn1,
    vib_gpio_ptn2,
    vib_gpio_ptn3
};


/*****************************************************************************
 * FUNCTION
 *  custom_get_led_patterns
 * DESCRIPTION
 *  
 * PARAMETERS
 *  led_pattern_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const LED_PATTERN_STRUCT *custom_get_led_patterns(PATTERN_ID led_pattern_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* out of pattern number */
    if (led_pattern_id - LED_PATTERN_BEGIN > (sizeof(led_gpio_patterns) / sizeof(led_gpio_patterns[0])))
    {
        ASSERT(0);
    }

    /* based index from 0 */
    return (led_gpio_patterns[led_pattern_id - LED_PATTERN_BEGIN]);
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_lcd_patterns
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_pattern_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const LCD_PATTERN_STRUCT *custom_get_lcd_patterns(PATTERN_ID lcd_pattern_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* out of pattern number */
    if (lcd_pattern_id - LCD_PATTERN_BEGIN > (sizeof(lcd_gpio_patterns) / sizeof(lcd_gpio_patterns[0])))
    {
        ASSERT(0);
    }

    /* based index from 0 */
    return (lcd_gpio_patterns[lcd_pattern_id - LCD_PATTERN_BEGIN]);
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_vib_patterns
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vib_pattern_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const VIB_PATTERN_STRUCT *custom_get_vib_patterns(PATTERN_ID vib_pattern_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* out of pattern number */
    if (vib_pattern_id - VIB_PATTERN_BEGIN > (sizeof(vib_gpio_patterns) / sizeof(vib_gpio_patterns[0])))
    {
        ASSERT(0);
    }

    /* based index from 0 */
    return (vib_gpio_patterns[vib_pattern_id - VIB_PATTERN_BEGIN]);
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_led_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 custom_get_led_label(const kal_uint8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (id)
    {
        case 0:
            return GPIO_DEV_LED_STATUS_1;

        case 1:
            return GPIO_DEV_LED_STATUS_2;

        case 2:
            return GPIO_DEV_LED_STATUS_3;

        default:
            return GPIO_DEV_LED_STATUS_1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_lcd_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 custom_get_lcd_label(const kal_uint8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (id)
    {
        case 0:
            return GPIO_DEV_LED_SUBLCD;

        case 1:
            return GPIO_DEV_LED_MAINLCD;

        default:
            return GPIO_DEV_LED_SUBLCD;
    }

}


/*****************************************************************************
 * FUNCTION
 *  custom_get_vib_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 custom_get_vib_label(const kal_uint8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GPIO_DEV_VIBRATOR;
}

#endif /* __L1_STANDALONE__ */ 

