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
 *
 * Filename:
 * ---------
 *   mp4_producer_audio.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Producer, for Audio track
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
  *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __MP4_PRODUCER_H__
#define __MP4_PRODUCER_H__


#ifndef MP4_UT_ONWIN32
   /// For target and MoDIS
   #define MP4_PRODUCER_AUDIO_VERBOSE 0
   #include "kal_release.h"
   #include "med_status.h"
#else
   /// For Win32 standalone application, unit test and PC Simulator
   #include <stdio.h>
   #include <assert.h>
   #include <string.h>
   #ifndef ASSERT
      #define ASSERT(x) assert(x)
   #endif
   #define MP4_PRODUCER_AUDIO_VERBOSE 1
   #define kal_mem_cpy(a,b,c) memcpy(a,b,c)
   #include "kal_non_specific_general_types.h"
   #include "med_status.h"
#endif

#include "mp4_common.h"
#include "mp4_sample_data_audio.h"
#include "fsal.h"

typedef enum {
   MP4_PRODUCER_OK = MED_STAT_MP4_PRODUCER_START,
   MP4_PRODUCER_FILE_READ_ERROR,
   MP4_PRODUCER_FILE_WRITE_ERROR,
   MP4_PRODUCER_FILE_SEEK_ERROR,
   MP4_PRODUCER_FILE_ACCESS_ERROR,
   MP4_PRODUCER_SAMPLE_DATA_READ_ERROR,
   MP4_PRODUCER_SAMPLE_DATA_AUDIO_TYPE_ERROR,
   /// In MP4_Produce_CalculateLimitedAudioFileSize, it's found that
   /// the Audio File is less than 8 bytes. The first 8 bytes are
   /// supposed to be MDAT (4 bytes) and SIZE (4 bytes).
   MP4_PRODUCER_AUDIO_FILE_TOO_SMALL,
   MP4_PRODUCER_AMR_FQI_INVALID,
   MP4_PRODUCER_AMR_FRAME_INVALID,
   MP4_PRODUCER_INVALID_ARGUMENT
} MP4_Producer_Status;

typedef struct {
   STFSAL *pstFSAL;
   FSAL_Status eFSALErr;

   STMp4SampleDataAudio *pstMp4SampleData;

   MP4_Track_Type eCurTrack;
   kal_bool    bIsVidEdit;
} STMp4Producer;

/* ------ Private Macros ------ */

#define MP4_PRODUCER_CHECK_ARG(exp) \
   if (!(exp)) \
      return MP4_PRODUCER_INVALID_ARGUMENT

/* --- private functions --- */
MP4_Producer_Status MP4_Produce_Init(STMp4Producer *pstMp4Producer, STMp4SampleDataAudio *pstMp4SampleData, STFSAL *pstFSAL);
MP4_Producer_Status MP4_Produce_MovieHeader(STMp4Producer *pstMp4Producer, kal_uint32 uAudioDataOffset);

MP4_SampleData_Status MP4_Produce_SetVidEditFlag(STMp4Producer *pstMp4Producer);

/* --- public functions --- */

/**
 * Produce a Mp4 file with audio track.
 *
 * @param pstMp4Producer pointer to Mp4Producer structure prepared by caller.
 * The structure will be initialized in the invocation.
 * @param pstMp4SampleData ponter to Mp4SampleData structure for accessing
 *        sample data file.
 * @param pstFSAL pointer to FSAL structure representing the file to be produced.
 *
 * @return If the function succeeds, the return value is MP4_PRODUCER_OK.
 * Otherwise, an error code is returned.
 */
MP4_Producer_Status MP4_Produce_Trak_Audio(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize, kal_uint32 uAudioDataOffset);

/**
 * Calculate the adjusted file size, based on two limiting factors:
 * 1. the speech length <= specified time length
 * 2. the file size <= specified size
 * In calculating the resulted file size, the speech frames are guaranteed
 * to remain complete, i.e., they will not be truncated.
 *
 * @param pstFSAL_In FSAL pointer to the MPEG4 Audio Recording File opened for READ.
 * The AMR speech frames in this file start at file offset 8.
 * If the file length is less than 8, MP4_PRODUCER_FILE_SEEK_ERROR will be returned.
 * @param uNumBytes Limit the file size to this value, in unit of byte.
 * @param uMilliSeconds Limit the time period of the speech frames to this value,
 * in unit of millisecond.
 * @param bAMRType 0:AMR 1:WB-AMR
 * @param puResultBytes The resulted file size. The minimum value will be 8,
 * accounting for the 8 bytes header of MPEG4 Audio Recording File.
 *
 * @return If the function succeeds, the return value is MP4_PRODUCER_OK.
 * Otherwise, an error code is returned.
 */
MP4_Producer_Status MP4_Produce_CalculateLimitedAudioFileSize(
   STFSAL *pstFSAL, kal_uint32 uNumBytesLimit, kal_uint32 uMilliSecondsLimit,
   kal_uint8 bAMRType, kal_uint32 *puResultBytes);

#endif
