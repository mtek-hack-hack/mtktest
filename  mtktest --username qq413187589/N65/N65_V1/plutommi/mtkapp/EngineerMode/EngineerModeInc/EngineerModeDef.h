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
 * EngineerModeDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode defination
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
 *
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
 *
 *
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_ENGINEER_MODE__    /* MTK Add Robin 1001 for saperate MMI feature by project */

#ifndef _ENGINEER_MODE_DEF_H
#define _ENGINEER_MODE_DEF_H

#include "gui_data_types.h"

#include "EngineerModeResDef.h"

#define EM_NOTIFY_DURATION             UI_POPUP_NOTIFYDURATION_TIME
#define EM_HIGHTLIGHT_DURATION         1000

#define EM_ASCII_BUF_LEN            80
#define EM_UNICODE_BUF_LEN      160

/* Menu item IDs         */
/*
 * //#define ENGINEER_MODE_BASE             7000
 * #define EM_NETWORK_BASE                ENGINEER_MODE_BASE+100
 * #define EM_AUDIO_BASE                  ENGINEER_MODE_BASE+200
 * #define EM_DEVICE_BASE                 ENGINEER_MODE_BASE+300
 * #define EM_GPRS_ACT_BASE                ENGINEER_MODE_BASE+400
 * #define EM_BAND_SEL_BASE                ENGINEER_MODE_BASE+500
 * #define EM_MISC_BASE                ENGINEER_MODE_BASE+600
 * #define EM_AUTO_TEST_SETTING_BASE    ENGINEER_MODE_BASE+700
 * #define EM_DEBUG_INFO_BASE    ENGINEER_MODE_BASE+800
 * #define EM_SOCKET_BASE        ENGINEER_MODE_BASE+900
 * #define EM_TOUCHSCREEN_BASE            ENGINEER_MODE_BASE+950
 * #define EM_BT_BASE    EM_TOUCHSCREEN_BASE+50
 * #define EM_BT_BASE_LAST    EM_BT_BASE+50
 */

typedef enum
{

    EM_MENU_SERIAL_PORT_EN_1 = 0x0,
    EM_MENU_SERIAL_PORT_EN_2,
    EM_MENU_SERIAL_PORT_EN_3,

    EM_MENU_SERIAL_PORT_EN_MAX
} EM_SERIAL_PORT_EN_MENU_ITEM;

enum EM_SOCKET_ECHO_INLINE_ITEM
{
    ENUM_SERVER_IP_CAPTION = 0,
    ENUM_SERVER_IP,
    ENUM_ECHO_STRING_CAPTION,
    ENUM_ECHO_STRING,
    ENUM_ECHO_TOTAL
};

enum EM_SOCKET_DATE_INLINE_ITEM
{
    ENUM_DATE_SERVER_IP_CAPTION = 0,
    ENUM_DATE_SERVER_IP,
    ENUM_DATE_TOTAL
};

/****** CONSTANT *********/

#define MAX_EM_MODE 32

#define DEFAULT_CHANNEL 8
#define RR_IDLE_STATE 1
#define RR_DEDICATE_STATE 4
#define RR_CELL_SELECTION 9

#define AUD_MIDI     1
#define AUD_IMELODY 2
#define AUD_TONE     3
#define AUD_SOUND     4

#define MAX_EM_VOLUME_LEVEL 7

#define MAX_VOLUME 255
#define MIN_VOLUME 0
#define VOLUME_STEP 4
#define INIT_VOLUME 128

#define MAX_KEY_SHIFT 20

#define MAX_HINT_STRING_LEN  60

#define MAX(a,b) (a>b)? a:b
#define MIN(a,b) (a<b)? a:b

#define MAX_ENERGY_VAL  31
#define MIN_ENERGY_VAL  0
#define MAX_DELAY_VAL  30
#define MIN_DELAY_VAL  0
#define AUD_PARAM_STEP 1
#if defined(__VOIP__)
typedef enum
{
    EM_VOIP_LOG_CALL_OUT,
    EM_VOIP_LOG_CALL_IN,
    EM_VOIP_LOG_CALL_TOTAL
} em_voip_log_direction_enum;

typedef enum
{
    EM_VOIP_LOG_DELETE_NONE,
    EM_VOIP_LOG_DELETE,
    EM_VOIP_LOG_DELETE_ALL,
    EM_VOIP_LOG_DELETE_TOTAL
} em_voip_log_delete_enum;

typedef enum
{
    EM_VOIP_LOG_ACTIVATE_OFF,
    EM_VOIP_LOG_ACTIVATE_ON,
    EM_VOIP_LOG_ACTIVATE_TOTAL
} em_voip_log_activate_enum;

typedef enum
{
    EM_VOIP_LOG_AUTO_DELETE_ALL,
    EM_VOIP_LOG_AUTO_DELETE_ONE_DAY,
    EM_VOIP_LOG_AUTO_DELETE_HALF_MONTH,
    EM_VOIP_LOG_AUTO_DELETE_ONE_MONTH,
    EM_VOIP_LOG_AUTO_DELETE_TOTAL
} em_voip_log_auto_delete_enum;

typedef enum
{
	EM_VOIP_LOG_INLINE_ACTIVATE_CAPTION,
	EM_VOIP_LOG_INLINE_ACTIVATE,
	EM_VOIP_LOG_INLINE_SAVE_CAPTION,
	EM_VOIP_LOG_INLINE_SAVE,
	EM_VOIP_LOG_INLINE_AUTO_DELETE_CAPTION,
	EM_VOIP_LOG_INLINE_AUTO_DELETE,
	EM_VOIP_LOG_INLINE_TOTAL
} em_voip_log_inline_item_enum;

#define EM_VOIP_LOG_MAX_CALL         (MMI_VOIP_MAX_NUM_CALL * 2 - 1) /* max number of voip voice call */
#define EM_VOIP_LOG_MAX_DIR_PATH     32 /* Bytes */
#define EM_VOIP_LOG_TEMP_FILE        L"temp.mtklog" /* temporary file */
#define EM_VOIP_LOG_DIR_PATH         L"MTKVoipLog\\" /* directory path */
#define EM_VOIP_LOG_EXT_FILENAME     L".mtklog" /* extended filename */
#endif  /*  __VOIP_ */

/*
 * #ifndef MMI_ON_HARDWARE_P
 * #define NVRAM_EF_AUDIO_PARAM_SIZE 512
 * #endif
 */

#define EM_TCM_PDU_HDR 0

#define BACKLIGHT_FOREVER   0
#define BACKLIGHT_NORMAL    1

#ifdef __TCPIP__
#define EM_SOCKET_MAX_INPUT_LEN  64
#define EM_SOCKET_IP_LEN   4
#define MAX_TRACERT_RESULT_SIZE 512
#endif /* __TCPIP__ */

/* BEGIN OF IPERF */
#ifndef __MTK_TARGET__
#define IPERF_DBG(x) x
#else /* __MTK_TARGET__ */
#define IPERF_DBG(x) /* empty */
#endif /* __MTK_TARGET__ */
#define IPERF_INLINE_COUNT	24  /* number of items in iperf setting screen */
#define IPERF_LEN 5     /* number of digits for port + NULL terminate */
#define IPERF_PORT 6     /* number of digits for port + NULL terminate */
#define IPERF_WINDOW 6     /* number of digits for port + NULL terminate */
#define IPERF_MSS 5     /* number of digits for port + NULL terminate */
#define IPERF_BANDWIDTH 6     /* number of digits for port + NULL terminate */
#define IPERF_NUM 9     /* number of digits for port + NULL terminate */
#define IPERF_TIME 4    /* number of digits for port + NULL terminate */
#define IPERF_SETTING_FILE              (L"z:\\Iperf_Setting.conf")
#define MAX_REPORT_BUFF 200 /* size of report buffer */
/* END OF IPERF */

#endif /* _ENGINEER_MODE_DEF_H */

#endif /* __MMI_ENGINEER_MODE__ */

