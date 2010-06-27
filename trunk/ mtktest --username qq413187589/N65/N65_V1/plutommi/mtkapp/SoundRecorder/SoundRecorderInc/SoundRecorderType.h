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
 * SoundRecorderType.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
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
#ifndef _SOUND_RECORDER_TYPE_H
#define _SOUND_RECORDER_TYPE_H

typedef enum
{
    STATE_IDLE,
    STATE_PLAY,
    STATE_PLAY_PAUSED,
    STATE_RECORD,
    STATE_RECORD_PAUSED,
    NO_OF_STATE
}
SoundRecorderStateEnum;


typedef enum
{
#ifndef MT6205B
    FORMAT_AMR,
    FORMAT_WAV,
#endif /* MT6205B */ 
#if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)
    FORMAT_AWB,
#endif 
    FORMAT_VM,
    NO_OF_FORMAT
}
SoundRecorderFormatEnum;


typedef enum
{
    QUALITY_LOW,
    QUALITY_HIGH,
    NO_OF_QUALITY
}
SoundRecorderQualityEnum;


#define FORMAT_EVL (NO_OF_FORMAT + 1) /* Propietary format to record VOIP data, auto record debug only */

typedef struct
{
    U16 noOfEntries;
    UI_character_type storagePath[MAX_STORAGE_PATH_LEN];
}
SoundFileListStruct;

typedef struct
{
    S32 dataRate[NO_OF_FORMAT];
    U8 curr_drv;
    U8 format;
    U8 quality;
}
SoundRecorderSettingsStruct;

typedef struct
{
    SoundFileListStruct SoundFileList;
    SoundRecorderSettingsStruct Settings;

    U8 state;
    BOOL inCall;
    BOOL cmdProcessing;
    BOOL inSoundRecorder;
    BOOL exitToStop;
    BOOL isAppend;
    BOOL isSlefStop;
    BOOL isFromCallExpress;
    MMI_BOOL is_sim_two;
    MMI_BOOL need_file_prefix;
    U8 volume;
    UI_character_type fileName[MAX_FILE_NAME_LEN];
    UI_character_type fullName[MAX_FULL_NAME_LEN];
    U32 recTime;
    U32 constSeconds;
    U32 recSeconds;
    U8 auto_record;
    U8 auto_record_count;
    U8 vm_support;
    U8 num_of_formats;
}
SoundRecorderStruct;

#endif /* _SOUND_RECORDER_TYPE_H */ 

