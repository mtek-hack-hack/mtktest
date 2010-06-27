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
 *   FMScheduleRecDef.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  .............
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_FMSRDEF_H
#define _MMI_FMSRDEF_H

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__

#include "FMScheduleRecResDef.h"

/* Note these defines should be the same as sound recorder */
#define MAX_FMSR_FILE_NAME_LEN      80
#define MAX_FMSR_PATH_LEN        25     /* The path is fixed. i.e "c:\audio\" */
#define MAX_FMSR_FULL_NAME_LEN   (MAX_FMSR_PATH_LEN+MAX_FMSR_FILE_NAME_LEN)
// #define MAX_FMSR_INPUT_FILE_LEN      35 /* max file length for user to input */

#define FMSR_MAX_MSG_BUFFER      500

#define FMSR_FILE_EXT_AMR  L".amr"
#define FMSR_FILE_EXT_WAV  L".wav"
#define FMSR_FILE_EXT_AWB  L".awb"

#define FMSR_NUM_DAYS   7
#define FMSR_FREQ_INPUT_LEN   6 /* "107.7" */
#define FMSR_FREQ_DISPLAY_LEN 10        /* "FM 107.7" */
#define FMSR_MIN_FREQUENCY 875
#define FMSR_MAX_FREQUENCY 1080

#define FMSR_MAX_YEAR   2030
#define FMSR_MIN_YEAR   2004

#define FMSR_MSG_NONE   0
#define FMSR_MSG_REC_INTERRUPT      0x00000001
#define FMSR_MSG_USER_STOP       0x00000002
#define FMSR_MSG_REC_PAUSE       0x00000004
#define FMSR_MSG_DEFAULT_FILE    0x00000008

#if defined(__DRM_SUPPORT__)
#define DRM_NOT_PERMIT_TO_APPEND 10000
#endif 

#define MAX_VOL_LEVEL 7

/* 
 * Typedef 
 */

typedef enum
{
    FMSR_ERROR_TIME_EXPIRE = 10001,
    FMSR_ERROR_INVALID_FREQ,
    FMSR_ERROR_NO_FOLDER,
    FMSR_ERROR_USB_MODE,
    FMSR_ERROR_TOTAL
} fmsr_err_code_enum;


typedef enum
{
    FMSR_FORMAT_AMR,
    FMSR_FORMAT_WAV,
#if defined( AMRWB_ENCODE ) && defined( AMRWB_DECODE )
    FMSR_FORMAT_AWB,
#endif    
    FMSR_REC_FORMAT_NUM
} fmsr_record_format;


typedef enum
{
    FMSR_QUALITY_LOW,
    FMSR_QUALITY_HIGH,
    NO_OF_FMSR_QUALITY
} fmsr_record_quality;


typedef enum
{
    FMSR_TYPE_NEW,
    FMSR_TYPE_APPEND,
    FMSR_REC_TYPE_NUM
} fmsr_record_type;


typedef enum
{
    FMSR_STATE_IDLE,
    FMSR_STATE_READY,   /* Power on */
    FMSR_STATE_RECORD,
    FMSR_STATE_PAUSE,
    FMSR_STATE_TOTAL
} fmsr_rec_state_enum;

typedef enum
{
    FMSR_REPEAT_ONCE,
    FMSR_REPEAT_EVERYDAY,
    FMSR_REPEAT_DAYS,
    FMSR_REPEAT_WEEKLY,
    FMSR_REPEAT_MONTHLY,
    FMSR_REPEAT_NUM
} fmsr_repeat_type_enum;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */ /* #ifdef __MMI_FM_RADIO_SCHEDULE_REC__ */
#endif /* _MMI_FMSRDEF_H */ /* #ifndef _MMI_FMSRDEF_H */

