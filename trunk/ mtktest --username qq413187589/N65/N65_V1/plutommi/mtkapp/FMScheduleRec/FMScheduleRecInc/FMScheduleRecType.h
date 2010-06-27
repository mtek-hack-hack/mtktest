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
 *   FMScheduleRecType.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_FMSRTYPE_H
#define _MMI_FMSRTYPE_H

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__

/* if some header should be include before this one */
//#ifndef _PREINC_H
//#error "preinc.h should be included before header.h"
//#endif

/* 
 * Typedef 
 */

typedef struct
{
    S32 onoff_state;
    S32 repeat;
    S32 format;
    S32 quality;
    S32 type;
    U16 curr_channel;
    U16 freqency;
    U8 drive;
    U8 is_DOW_set;
    U8 is_changed;
    UI_character_type full_path[MAX_FMSR_FULL_NAME_LEN];
} fmsr_setting_struct;

typedef struct
{
    U16 freqency;
    UI_character_type full_path[MAX_FMSR_FULL_NAME_LEN];
    U32 rec_time;
    U32 total_rec_duration;
    U32 error_msg;
    U16 error_str_id;
    U8 index;
    U8 state;               /* Current state */
    BOOL is_screen_paused;  /* Does the screen display state as pause? */
    U8 format;
    U8 quality;
    U8 type;
    U8 drive;
    U16 year;
    U8 mon;
    U8 day;
    U8 hour1;
    U8 min1;
    U8 hour2;
    U8 min2;
    U8 volume;
    BOOL is_first_record;
    BOOL is_show_msg;
    BOOL is_start_duration;
    BOOL power_on_record;
} fmsr_recording_struct;

typedef struct
{
    fmsr_recording_struct rec;
    fmsr_setting_struct setting;
} fmsr_context_struct;

typedef struct
{
    U8 state;
    U16 freq;
    U16 year;
    U8 mon;
    U8 day;
    U8 hour1;
    U8 min1;
    U8 hour2;
    U8 min2;
    U8 repeat;
    U8 weekday;
    U8 format;
    U8 quality;
    U8 storage;
    U8 type;
    UI_character_type filename[MAX_FMSR_FILE_NAME_LEN];
} fmsr_nvram_struct;

/* 
 * Define
 */

/* 
 * Extern Global Variable
 */
extern fmsr_context_struct g_fmsr_cntx;

/* 
 * Extern Global Function
 */

#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */ /* #ifdef __MMI_FM_RADIO_SCHEDULE_REC__ */
#endif /* _MMI_FMSRTYPE_H */ /* #ifndef _MMI_FMSRTYPE_H */

