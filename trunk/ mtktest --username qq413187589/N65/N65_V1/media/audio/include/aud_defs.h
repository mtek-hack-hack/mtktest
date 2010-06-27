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
 * aud_defs.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary definitions of audio manager task.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#ifndef _AUD_DEFS_H
#define _AUD_DEFS_H

/*==== CONSTANTS ========*/

#define MAX_VM_RECORD 32
#define MAX_NUM_OF_VM_FILE 20
#define MAX_VM_SIZE  (128*1024*1024)    /* 128M */

/* audio type */
#define  AUD_TYPE_NONE        0
#define  AUD_TYPE_SPEECH      1
#define  AUD_TYPE_TONE        2
#define  AUD_TYPE_KEYTONE     3
#define  AUD_TYPE_MELODY      4
#define  AUD_TYPE_VM           5
#define  AUD_TYPE_DAF          6
#define  AUD_TYPE_VR           7
#define  AUD_TYPE_MIC          8
#define  AUD_TYPE_FMR          9
#define  AUD_TYPE_BGSND      10

/* volume type */
#define AUD_VOLUME_CTN                0 /* call tone attribute */
#define AUD_VOLUME_KEY                1 /* keypad tone attribute */
#define AUD_VOLUME_MIC                2 /* microphone attribute */
#define AUD_VOLUME_FMR                3 /* FM radio attribute */
#define AUD_VOLUME_SPH                4 /* speech sound attribute */
#define AUD_VOLUME_SID                  5       /* side tone attribute */
#define AUD_VOLUME_MEDIA             6  /* MP3, Wave,... attribute */
#define AUD_VOLUME_TVO             7    /* TV Out Volume,... attribute */
#define AUD_MAX_VOLUME_TYPE          8

#define AUD_MAX_VOLUME_LEVEL            7

/*==== TYPES ===========*/

typedef enum
{
    AUD_VM_DIR_DL,  /* Uplink            */
    AUD_VM_DIR_UL,  /* Downlink          */
    AUD_VM_DIR_BOTH /* Both direction    */
}
aud_vm_record_dir_enum;

typedef enum
{
    AUD_RES_OK,             /* OK  */
    AUD_RES_FAIL,           /* General Fail   */
    AUD_RES_BUSY,           /* system busy  */
    AUD_RES_DISC_FULL,      /* Memory full    */
    AUD_RES_OPEN_FILE_FAIL, /* open file fail    */
    AUD_RES_END_OF_FILE,
    AUD_RES_TERMINATED,
    AUD_RES_BAD_FORMAT,
    AUD_RES_INVALID_FORMAT,
    AUD_RES_ERROR,
    AUD_RES_NO_DISC,
    AUD_RES_NOT_ENOUGH_SPACE,
    AUD_RES_RESUME,
    AUD_RES_BLOCKED
}
aud_res_enum;

/* this enum has to sync with Media_Format in l1audio.h */
typedef enum
{
    MEDIA_FORMAT_NONE = -1,
    MEDIA_GSM_FR,           /* 0 */
    MEDIA_GSM_HR,           /* 1 */
    MEDIA_GSM_EFR,          /* 2 */
    MEDIA_AMR,              /* 3 */
    MEDIA_AMR_WB,           /* 4 */
    MEDIA_DAF,              /* 5 */
    MEDIA_AAC,              /* 6 */
    MEDIA_PCM_8K,           /* 7 */
    MEDIA_PCM_16K,          /* 8 */
    MEDIA_G711_ALAW,        /* 9 */
    MEDIA_G711_ULAW,        /* 10 */
    MEDIA_DVI_ADPCM,        /* 11 */
    MEDIA_VR,               /* 12 */
    MEDIA_WAV,              /* 13 */
    MEDIA_WAV_ALAW,         /* 14 */
    MEDIA_WAV_ULAW,         /* 15 */
    MEDIA_WAV_DVI_ADPCM,    /* 16 */
    MEDIA_SMF,              /* 17 */
    MEDIA_IMELODY,          /* 18 */
    MEDIA_SMF_SND,          /* 19 */
    MEDIA_SMAF,             /* 20 */
    MEDIA_3GP,              /* 21 */
    /*Add format from l1audio.h*/
    MEDIA_VOIPEVL = 27,     /* 27 */
    NUM_OF_MEDIA_FORMAT
}
media_format_enum;

typedef struct
{
    kal_uint16 num_of_vm;
    kal_wchar *file_name_list[MAX_NUM_OF_VM_FILE];
    kal_uint32 free_space;
}
aud_vm_local_info_struct;

#endif /* _AUD_DEFS_H */ 

#endif /* MED_NOT_PRESENT */ 

