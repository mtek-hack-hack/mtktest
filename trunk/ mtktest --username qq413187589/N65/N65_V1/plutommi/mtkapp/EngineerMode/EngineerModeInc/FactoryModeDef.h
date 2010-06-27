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
 * FactoryModeDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for factory mode 
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

#include "MMI_features.h"

#ifdef __MMI_FACTORY_MODE__     /* MTK Add Robin 1001 for saperate MMI feature by project */

#include "FactoryModeResDef.h"

#ifndef _FACTORY_MODE_DEF_H
#define _FACTORY_MODE_DEF_H

#include "gui_data_types.h"

/* Defination */
/* Lisen 0921 */
#define MAX_VER_NUM    9
// #define MAX_LED_MENU_NUM     6
#define MAX_CONTRAST_NUM   15
#define MIN_CONTRAST_NUM   0
#define CONTRAST_STEP      1

/* Marco */
#define FM_IS_SET(b, a)       ((b & (0x1 << a)) >> a)
#define FM_STATE_SET(b, a)    (b |= (0x1 << a))
#define FM_STATE_UNSET(b, a)  (b &= ~(0x1 << a))
#define FM_STATE_TOGGLE(b, a) (b ^= (0x1 << a))

/*===== Auto Testing Settings ===== */
#define MAX_TEST_ITEM_NAME_LEN   20
/* 2009.05.08 added by huyanwei for software info + */
#define MAX_TEST_STRING_BUF         256
/* 2009.05.08 added by huyanwei for software info - */

#define VBAT_LOWER_BOUNDARY      3.3
#define VBAT_UPPER_BOUNDARY         4.2
#define TEMP_LOWER_BOUNDARY         15
#define TEMP_UPPER_BOUNDARY         35
#define CURR__LOWER_BOUNDARY        0.3

#define LED_DURATION             2000
#define CLAM_DURATION            5000
#define LCM_CONSTRAST_DURATION   100
#define VERSION_DURATION         1500
#define BACKLIGHT_DURATION       500
#define RECEIVER_DURATION        3000
#define MIC_DURATION          3000
#define HEADSET_DURATION         3000
#define SPEAKER_DURATION         3000
#define VIB_DURATION          500
#define ADC_DURATION          1000
#define MELODY_DURATION       3000
/* Lisen 01262005 */
#define CAMERA_DURATION       5000
#define MEMORYCARD_DURATION          6000

/* hongzhe.liu add start */
#define ANALOGTV_DURATION			6000
/* hongzhe.liu add end */



typedef enum
{
    FM_TEST_LED = 0,
#if defined(DOUBLE_BATTERY_SUPPORT)
    FM_TEST_DOUBLE_BATTERY,
#endif
    FM_TEST_CLAM_DETECT,
    FM_TEST_SUBLCM,
    FM_TEST_SW_VERSION,
    FM_TEST_BACKLIGHT,
    FM_TEST_LCD,
    FM_TEST_KEYPAD,
    FM_TEST_RECEIVER,
    FM_TEST_MIC,
    FM_TEST_SPEAKER,
    FM_TEST_HEADSET,
    FM_TEST_VIB,
    FM_TEST_BATTERY,
    FM_TEST_MELODY,
    FM_TEST_CHARGER,
    FM_TEST_NAND,
    FM_TEST_UART,
    /* Lisen 01262005 */
    FM_TEST_DOUBLE_SPEAKER,
    FM_TEST_CAMERA,
    FM_TEST_MEMORYCARD,
#ifdef __MMI_TOUCH_SCREEN__
    FM_TEST_PEN_PARALLEL_LINES,
    FM_TEST_PEN_N_CROSS_M_POINTS,
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* hongzhe.liu add start */
    FM_TEST_ANALOG_TV,
/* hongzhe.liu add end */
    MAX_AUTO_TEST_ITEMS
} EM_AUTO_TESTS_ENUM;

typedef enum
{
    FM_TEST_UNTESTED = 0,
    FM_TEST_FAILED,
    FM_TEST_PASSED
} FM_AUTO_TEST_RESULT_ENUM;

typedef enum
{
    FM_ADC_BATTERY = 0,
    FM_ADC_CHARGER
} FM_ADC_TYPE_ENUM;

typedef enum
{
    FM_AUTOTEST_LED = 0,
    FM_AUTOTEST_CLAM,
    FM_AUTOTEST_SUBLCM,
    FM_AUTOTEST_VERSION,
    FM_AUTOTEST_BACKLIGHT,
    FM_AUTOTEST_LCD,
    FM_AUTOTEST_KEYPAD,
    FM_AUTOTEST_RECEIVER,
    FM_AUTOTEST_MIC,
    FM_AUTOTEST_SPEAKER,
    FM_AUTOTEST_HEADSET,
    FM_AUTOTEST_BATTERY,
    FM_AUTOTEST_MELODY,
    FM_AUTOTEST_VIB,
    FM_AUTOTEST_CHARGER,
    FM_AUTOTEST_NAND,
    FM_AUTOTEST_UART,
    /* Lisen 01262005 */
    FM_AUTOTEST_DOUBLE_SPEAKER,
    FM_AUTOTEST_CAMERA,
    FM_AUTOTEST_MEMORYCARD,
#ifdef __MMI_TOUCH_SCREEN__
    FM_AUTOTEST_PARALLEL_LINE,
    FM_AUTOTEST_N_CROSS_M_POINTS,
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* hongzhe.liu add start */
    FM_AUTOTEST_ANALOGTV,
/* hongzhe.liu add end */

    FM_AUTOTEST_MAX_ITEMS
} FM_AUTO_TEST_ENUM;

typedef void (*AUTO_TEST_FUNC) (void);

typedef struct
{
    S8 name[MAX_TEST_ITEM_NAME_LEN *ENCODING_LENGTH];
    AUTO_TEST_FUNC func;
} testlet;

typedef struct
{
    U8 count;
    U8 priority[MAX_AUTO_TEST_ITEMS];   /* for example, priority[0] = 8 means that the first one is test item 8 */
} AutoTestItemArray;

typedef struct
{
    U8 count;
    FM_AUTO_TEST_RESULT_ENUM result[MAX_AUTO_TEST_ITEMS];   /* for example, result[0] = FM_TEST_PASSED means that the first test item passed the test */
} AutoTestResultArray;

/*===== MTBF ===== */
#define FM_MTBF_PERIOD        1000      /* in milli seconds */

/* Cycle in milli seconds */
#define FM_MTBF_LCD_CYCLE  2000
#define FM_MTBF_LED_CYCLE  1000
#define FM_MTBF_VIB_CYCLE  1000

#define FM_MTBF_AUDIO_GAP               20
#define FM_MTBF_SPK_UNIT   3000
#define FM_MTBF_REV_UNIT   3000
#define FM_MTBF_SPK_UNIT_CYCLE   (FM_MTBF_SPK_UNIT - FM_MTBF_AUDIO_GAP)
#define FM_MTBF_REV_UNIT_CYCLE   (FM_MTBF_REV_UNIT - FM_MTBF_AUDIO_GAP)
#define FM_MTBF_SPK_CYCLE  (FM_MTBF_SPK_UNIT*FM_MTBF_SPK_MAX)
#define FM_MTBF_REV_CYCLE  (FM_MTBF_REV_UNIT*FM_MTBF_REV_MAX)

typedef enum
{
    FM_MTBF_LCD_START = 0,
    FM_MTBF_LCD_R = 0,
    FM_MTBF_LCD_G,
    FM_MTBF_LCD_B,
    FM_MTBF_LCD_W,
    FM_MTBF_LCD_END = FM_MTBF_LCD_W
} FM_MTBF_LCD_ENUM;

typedef enum
{
    FM_MTBF_LED_START = 0,
    FM_MTBF_LED_KEYPAD = 0,
    FM_MTBF_LED_R,
    FM_MTBF_LED_G,
    FM_MTBF_LED_B,
    FM_MTBF_LED_END = FM_MTBF_LED_B
} FM_MTBF_LED_ENUM;

typedef enum
{
    FM_MTBF_VIB_START = 0,
    FM_MTBF_VIB_ON = 0,
    FM_MTBF_VIB_OFF,
    FM_MTBF_VIB_END = FM_MTBF_VIB_OFF
} FM_MTBF_VIB_ENUM;

typedef enum
{
    FM_MTBF_SPK_START = 0,
    FM_MTBF_SPK_400 = 0,
    FM_MTBF_SPK_600,
    FM_MTBF_SPK_800,
    FM_MTBF_SPK_850_1,
    FM_MTBF_SPK_850_2,
    FM_MTBF_SPK_900,
    FM_MTBF_SPK_1000,
    FM_MTBF_SPK_2000,
    FM_MTBF_SPK_4000,
    FM_MTBF_SPK_8000,
    FM_MTBF_SPK_END = FM_MTBF_SPK_8000,
    FM_MTBF_SPK_MAX
} FM_MTBF_SPK_ENUM;

typedef enum
{
    FM_MTBF_REV_START = 0,
    FM_MTBF_REV_400 = 0,
    FM_MTBF_REV_500,
    FM_MTBF_REV_600_1,
    FM_MTBF_REV_600_2,
    FM_MTBF_REV_700,
    FM_MTBF_REV_800,
    FM_MTBF_REV_1000,
    FM_MTBF_REV_1500,
    FM_MTBF_REV_2000,
    FM_MTBF_REV_3000,
    FM_MTBF_REV_END = FM_MTBF_REV_3000,
    FM_MTBF_REV_MAX
} FM_MTBF_REV_ENUM;

typedef enum
{
    FM_MTBF_AUD_START = 0,
    FM_MTBF_AUD_SPK = 0,
    FM_MTBF_AUD_REV,
    FM_MTBF_AUD_END = FM_MTBF_AUD_REV
} FM_MTBF_AUD_ALTERNATION_ENUM;

#endif /* _FACTORY_MODE_DEF_H */ 

#endif /* __MMI_FACTORY_MODE__ */ 

