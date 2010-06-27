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
 * EngineerModeType.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_ENGINEER_MODE__   

#ifndef _ENGINEER_MODE_TYPE_H
#define _ENGINEER_MODE_TYPE_H
#include "MMI_features.h"


/*****************************************************************/
/***************************  Band Sel. **************************/
/*****************************************************************/
typedef enum
{
    EM_BANDSEL_900,
    EM_BANDSEL_1800,
    EM_BANDSEL_DUAL,
    EM_BANDSEL_1900,
    EM_BANDSEL_850,
    EM_BANDSEL_AUTO,
    EM_BANDSEL_MAX
} BANDENUM;


/*****************************************************************/
/********************  Structures / Definitions ******************/
/*****************************************************************/
#define     UART_BAUD_AUTO          0
#define     UART_BAUD_75            75
#define     UART_BAUD_150           150
#define     UART_BAUD_300           300
#define     UART_BAUD_600           600
#define     UART_BAUD_1200          1200
#define     UART_BAUD_2400          2400
#define     UART_BAUD_4800          4800
#define     UART_BAUD_7200          7200
#define     UART_BAUD_9600          9600
#define     UART_BAUD_14400         14400
#define     UART_BAUD_19200         19200
#define     UART_BAUD_28800         28800
#define     UART_BAUD_33900         33900
#define     UART_BAUD_38400         38400
#define     UART_BAUD_57600         57600
#define     UART_BAUD_115200        115200
#define     UART_BAUD_230400        230400
#define     UART_BAUD_460800        460800
#define     UART_BAUD_921600        921600

#if defined(DCM_ENABLE) && (!defined(MT6226D) && !defined(MT6227D) && !defined(MT6223) && !defined(MT6223P))
#define     EM_BAUD_NUM  19
#else 
#define     EM_BAUD_NUM  20
#endif 

typedef enum
{
    EM_UART_PORT_1 = 0,
    EM_UART_PORT_2,
#ifdef __UART3_SUPPORT__
    EM_UATR_PORT_3,
#endif

#ifdef __MMI_USB_SUPPORT__
    EM_USB_PORT,
#endif

    EM_UART_PORT_NULL,

    EM_UART_MAX_PORT_NUM
} EM_PORT_ENUM;

typedef enum
{ 
    EM_INLINE_TST_PS_CONFIG_STR = 0,
    EM_INLINE_TST_PS_UART_PORT,
    EM_INLINE_TST_PS_UART_BAUD,
    
    EM_INLINE_PS_CONFIG_STR ,
    EM_INLINE_PS_UART_PORT,
    EM_INLINE_PS_UART_BAUD,

    EM_INLINE_TST_L1_CONFIG_STR,
    EM_INLINE_TST_L1_UART_PORT,
    EM_INLINE_TST_L1_UART_BAUD,

#if defined(__MA_L1__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
    
    EM_INLINE_STRUCT_MAX_NUM
} EM_SET_UART_INLINE;

typedef enum
{
/* Fion Add, Start */
    EM_APP_TST_PS = 0,
    EM_APP_PS,
    EM_APP_TST_L1,
    EM_APP_CTI,    
    EM_APP_MAX_NUM
} EM_APP_UART_SETTING;

typedef enum
{
    EM_NONE,
    EM_START,
    EM_STOP
} EmCommandTypeEnum;

typedef enum
{
    EM_VOL_TYPE_CTN,
    EM_VOL_TYPE_KEY,
    EM_VOL_TYPE_MIC,
    EM_VOL_TYPE_SND,
    EM_VOL_TYPE_SPH,
    EM_VOL_TYPE_SID,
    EM_VOL_TYPE_MEDIA,
    EM_VOL_TYPE_TVOUT
} EmVolumeTypeEnum;

typedef enum
{
    EM_NORMAL_MODE,
    EM_HEADSET_MODE,
    EM_LOUDSP_MODE,
    EM_TV_OUT_MODE
} EmVolumeModeEnum;

typedef enum {
   EM_SET_UART_UART_SETTING = 0 ,
   EM_SET_UART_HIGH_SPEED_SIM,
   EM_SET_UART_SWDBG,
   EM_SET_UART_POWER_SETTING
} EM_SET_UART_REQ_TYPE_ENUM;

typedef enum
{
    EM_GPRS_PDP_CONTEXT_1,
    EM_GPRS_PDP_CONTEXT_2,
    EM_GPRS_PDP_CONTEXT_3,
    EM_GPRS_PDP_CONTEXT_4,
    EM_GPRS_PDP_CONTEXT_5,
    EM_GPRS_PDP_CONTEXT_6,
    EM_GPRS_PDP_CONTEXT_7,
    EM_GPRS_PDP_CONTEXT_8,
    EM_GPRS_PDP_CONTEXT_9,
    EM_GPRS_PDP_CONTEXT_10,
    EM_GPRS_PDP_CONTEXT_11,
    EM_GPRS_PDP_CONTEXT_12,
    EM_GPRS_PDP_CONTEXT_13,
    EM_GPRS_PDP_CONTEXT_14,
    EM_GPRS_PDP_CONTEXT_15
    
#ifdef __R99__	   
    ,EM_GPRS_PDP_CONTEXT_30
    ,EM_GPRS_PDP_CONTEXT_31

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif     

#endif /* __R99 */

    /* Add new item before this */
    , EM_GPRS_PDP_CONTEXT_MAX_NUM    
}EmGprsPDPContext;


typedef struct
{
    U8 mode;
    U8 speech[MAX_EM_VOLUME_LEVEL];
    U8 sp_gain;
    U8 keytone[MAX_EM_VOLUME_LEVEL];
    U8 kt_gain;
    U8 melody[MAX_EM_VOLUME_LEVEL];
    U8 mel_gain;
    U8 sound[MAX_EM_VOLUME_LEVEL];
    U8 snd_gain;
    U8 mic[MAX_EM_VOLUME_LEVEL];
    U8 mic_gain;
    U8 sidetone;
    U8 tvout[MAX_EM_VOLUME_LEVEL];
    U8 tvout_gain;
    U8 vol_16_level_max_gain;
    U8 vol_16_level_step;
} EmAudioProfileStruct;

/* refer to "aud_struct.h", audio_param_struct chang, this struct should change as well. */
typedef struct
{
    kal_uint16 selected_FIR_output_index;
    kal_uint16 speech_common_para[12];
    kal_uint16 speech_mode_para[8][8];
    kal_uint16 max_swing;
    kal_uint16 debug_info[8];
} EmAudioParamStruct;

#endif /* _ENGINEER_MODE_TYPE_H */ 

#endif /* __MMI_ENGINEER_MODE__ */ 

