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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_FMSR_RESDEF_H
#define _MMI_FMSR_RESDEF_H

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__

#include "MMIDataType.h"    /* for resource base */

typedef enum
{
    STR_ID_FMSR_BASE = FM_SCHEDULE_REC_BASE + 1,
    STR_ID_FMSR_APP,
    STR_ID_FMSR_SAVE_CONFIRM,
    STR_ID_FMSR_CHAN_SETTING,
    STR_ID_FMSR_CHAN_LIST,
    STR_ID_FMSR_CHAN_MANUAL,
    STR_ID_FMSR_REC_SETTING,
    STR_ID_FMSR_REPEAT,
    STR_ID_FMSR_ONCE,
    STR_ID_FMSR_EVERYDAY,
    STR_ID_FMSR_DAYS,
    STR_ID_FMSR_WEEKLY,
    STR_ID_FMSR_MONTHLY,
    STR_ID_FMSR_REC_FORMAT,
    STR_ID_FMSR_REC_QUALITY,
    STR_ID_FMSR_REC_QUALITY_LOW,
    STR_ID_FMSR_REC_QUALITY_HIGH,
    STR_ID_FMSR_REC_TYPE,
    STR_ID_FMSR_REC_STORAGE,
    STR_ID_FMSR_AMR,
    STR_ID_FMSR_WAV,
    STR_ID_FMSR_AWB,    
    STR_ID_FMSR_NEW_FILE,
    STR_ID_FMSR_APPEND_FILE,
    STR_ID_FMSR_STOP,
    STR_ID_FMSR_PAUSE,
    STR_ID_FMSR_RESUME,
    STR_ID_FMSR_RECORDING,
    STR_ID_FMSR_BAD_FORMAT,
    STR_ID_FMSR_INVALID_FORMAT,
    STR_ID_FMSR_DEVICE_BUSY,
    STR_ID_FMSR_OPEN_FILE_ERROR,
    STR_ID_FMSR_NO_CARD,
    STR_ID_FMSR_WRITE_PROTECTION_ERROR,
    STR_ID_FMSR_VALID_FREQUENCY,
    STR_ID_FMSR_FILENAME_TOO_LONG,
    STR_ID_FMSR_FILE_EMPTY,
    STR_ID_FMSR_FILE_EXIST,
    STR_ID_FMSR_END_TIME_INCORRECT,
    STR_ID_FMSR_START_TIME_INCORRECT,
    STR_ID_FMSR_TIME_OVERLAP,
    STR_ID_FMSR_SYSTEM_INTERRUPT,
    STR_ID_FMSR_USER_STOP,
    STR_ID_FMSR_USER_PAUSE,
    STR_ID_FMSR_USE_DEFAULT_FILE,
    STR_ID_FMSR_TIME_EXPIRE,
    STR_ID_FMSR_INVALID_FREQUENCY,
    STR_ID_FMSR_CANT_CREATE_FOLDER,
    STR_ID_FMSR_IN_USB_MODE,
    STR_ID_FMSR_RECORD_IN_BT_SCO,
    STR_ID_FMSR_RECORD_FINISH_1,
    STR_ID_FMSR_RECORD_FINISH_2,
    STR_ID_FMSR_RECORD_FINISH_3,
    STR_ID_FMSR_RECORD_FINISH_4,
    STR_ID_FMSR_APPEND_ERORR,
    NO_OF_STR_ID_FMSR
} fmsr_str_id_enum;

typedef enum
{
    IMG_ID_FMSR_BASE = FM_SCHEDULE_REC_BASE + 1,
    IMG_ID_FMSR_APP,
    IMG_ID_FMSR_BACKGROUND,
    NO_OF_IMG_ID_FMSR
} fmsr_img_id_enum;

typedef enum
{
    SCR_ID_FMSR_BASE = FM_SCHEDULE_REC_BASE + 1,
    SCR_ID_FMSR_MAIN_LIST,
    SCR_ID_FMSR_MAIN_SETTING,
    SCR_ID_FMSR_CHAN_SETTNIG,
    SCR_ID_FMSR_CHAN_LIST,
    SCR_ID_FMSR_CHAN_MANUAL,
    SCR_ID_FMSR_REC_SETTING,
    SCR_ID_FMSR_RECORDING,
    SCR_ID_FMSR_SHOW_MESSAGE,
    NO_OF_SCR_ID_FMSR
} fmsr_scr_id_enum;


#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */ /* #ifdef __MMI_FM_RADIO_SCHEDULE_REC__ */
#endif /* _MMI_FMSR_RESDEF_H */ /* #ifndef _MMI_FMSRDEF_H */

