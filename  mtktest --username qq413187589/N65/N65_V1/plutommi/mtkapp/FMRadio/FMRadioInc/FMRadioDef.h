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

/*******************************************************************************
* Filename:
* ---------
*  FMRadioDef.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio id, const & macro definition
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
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
 * remove the compile option in the screen ID define
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
*==============================================================================
*******************************************************************************/
#ifndef _FM_RADIO_DEF_H
#define _FM_RADIO_DEF_H

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__

#include "FMRadioResDef.h"
/*
 * Need to include:
 * (1) xxx.h
 * (2) yyy.h
 */

#define MAX_VOL_LEVEL 7
#define IS_CHANNEL_EMPTY(f) ((f)==0)
#define DEFAULT_FREQUENCY            1017  /* hongzhe.liu 987 */
#define MAX_MANUAL_INPUT_LEN 6
//UNI@bw_20070921 all all 加大收音机的名字长度
//#define MAX_NAME_INPUT_LEN 21 /*UNI@bw_20070717 13:07:29 文字输入MAX_NAME_INPUT_LEN由21增加到100, 适应外文字符串存储*/
#define MIN_FM_FREQUENCY 875
#define MAX_FM_FREQUENCY 1080
#define FM_BANDWIDTH (MAX_FM_FREQUENCY - MIN_FM_FREQUENCY + 1)
#define NORMAL_REAPEAT_STEP_TIME 2000
#define NORMAL_REAPEAT_STEP_PERIOD 200
#define FAST_REAPEAT_STEP_PERIOD 100
#define NORMAL_REAPEAT_STEP_COUNT (NORMAL_REAPEAT_STEP_TIME / NORMAL_REAPEAT_STEP_PERIOD)
#define TWINKLE_FREQUENCY_COUNT 5
#define TWINKLE_FREQUENCY_ON_TIME 200
#define TWINKLE_FREQUENCY_OFF_TIME 100
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
#define NORMAL_TIMER_FOR_GOBACKSUBLCD 2000
#endif

#define FM_SUB_BAND_NUM NVRAM_EF_FM_RADIO_CHANNEL /* customizable in MMI_Fetures.h */
#define FM_RADIO_CHANNEL_NUM  NVRAM_EF_FM_RADIO_CHANNEL /* customizable in MMI_Fetures.h */

#define FM_SUB_BANDWIDTH ((FM_BANDWIDTH+1)/FM_SUB_BAND_NUM)
#if defined(FM_RADIO_WITH_TV)
#define FM_MARK_SIG(x) ((x) |= 0x8000)
#define FM_SIG_MARK(x) ((x) & 0x8000)
#define FM_SIG_LVL(x) ((x) & 0x7FFF)
#else
#define FM_MARK_SIG(x) ((x) |= 0x80)
#define FM_SIG_MARK(x) ((x) & 0x80)
#define FM_SIG_LVL(x) ((x) & 0x7F)
#endif
#define FM_SUB_MARK(x,i) ((x)&(1<<(i)))
#define FM_MARK_SUB(x,i) ((x) |= (1<<(i)))


#if defined(__MMI_FM_RADIO_RECORD__)
/* Note these defines should be the same as sound recorder */
#define MAX_FM_FILE_NAME_LEN     80
#define MAX_FM_PATH_LEN          25     /* The path is fixed. i.e "c:\audio\" */
#define MAX_FM_FULL_NAME_LEN     (MAX_FM_PATH_LEN+MAX_FM_FILE_NAME_LEN)

#define MAX_FM_INPUT_FILE_LEN    35     /* max file length for user to input */

#define FM_FILE_EXT_AMR L".amr"
#define FM_FILE_EXT_WAV L".wav"
#define FM_FILE_EXT_AWB L".awb"

#if defined(__DRM_SUPPORT__)
#define DRM_NOT_PERMIT_TO_APPEND 10000
#endif 
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

typedef enum
{
    FMRDO_STATE_NOT_READY = 0,
    FMRDO_STATE_READY,
    FMRDO_STATE_RECORD,
    FMRDO_STATE_RECORD_PAUSE,
    FMRDO_STATE_SEARCH_ONE,
    FMRDO_STATE_SEARCH_ALL,
    NO_OF_FMRDO_STATE
} fmrdo_state_enum;

typedef enum
{
    FMRDO_BUTTON_NONE,
    FMRDO_BUTTON_POWER,
    FMRDO_BUTTON_SEARCH,
    FMRDO_BUTTON_STEP_UP,
    FMRDO_BUTTON_STEP_DOWN,
    FMRDO_BUTTON_REC,
    FMRDO_BUTTON_REC_PAUSE
} fmrdo_main_button_enum;
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
typedef enum
{
    FMRDO_SUB_LCD_STEP_MODE,
    FMRDO_SUB_LCD_CHANNEL_MODE,
    FMRDO_SUB_LCD_SEARCH_MODE,
    FMRDO_SUB_LCD_NO_MODE
}fmrdo_on_sublcd_mode_enum;
#endif /*__MMI_FM_RADIO_ON_SUBLCD__*/

/* Number of FM Radio Main Option */
typedef enum
{
    FMRDO_MAIN_OPTION_CHANNEL_LIST,
    FMRDO_MAIN_OPTION_MANUAL_INPUT,
    FMRDO_MAIN_OPTION_PRESET_AUTO_SEARCH,
    FMRDO_MAIN_OPTION_SETTINGS,
#if defined(__MMI_FM_RADIO_RECORD__)
    FMRDO_MAIN_OPTION_RECORD,
    FMRDO_MAIN_OPTION_APPEND,
    FMRDO_MAIN_OPTION_FILE_LIST,
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
    FMRDO_MAIN_OPTION_TOTAL
} fmrdo_main_option_item_enum;

#if defined(__MMI_FM_RADIO_RECORD__)

typedef enum
{
    FM_FORMAT_AMR,
    FM_FORMAT_WAV,
#if defined( AMRWB_ENCODE ) && defined( AMRWB_DECODE )
    FM_FORMAT_AWB,
#endif
    FM_REC_FORMAT_NUM
} fmrdo_record_format;

typedef enum
{
    FM_QUALITY_LOW,
    FM_QUALITY_HIGH,
    NO_OF_QUALITY
} fmrdo_record_quality;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#endif /* __MMI_FM_RADIO__ */ 
#endif /* _FM_RADIO_DEF_H */ 

