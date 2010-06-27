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
 *   mp4_producer_audio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Producer, for audio track
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

#include "mp4_producer_audio.h"
#include "mp4_sample_data_audio.h"
#include "fsal.h"

#include "mp4_parser.h"

#define MP4_SAMPLE_DATA_GET_TIME_SCALE(uTimeScale)                  \
   if (MP4_AudioSampleData_GetTimeScale(pstMp4Producer->pstMp4SampleData, &(uTimeScale))!= MP4_SAMPLE_DATA_OK)                                 \
      return MP4_PRODUCER_SAMPLE_DATA_READ_ERROR

#define MP4_SAMPLE_DATA_GET_FMT_MP4A_SIZE(uSize)                  \
   if (MP4_AudioSampleData_Get_FMT_MP4A_Size(pstMp4Producer->pstMp4SampleData, &(uSize))!= MP4_SAMPLE_DATA_OK)                                 \
      return MP4_PRODUCER_SAMPLE_DATA_READ_ERROR

#define MP4_SAMPLE_DATA_GET_FMT_MP4A_DATA(bData)                  \
   if (MP4_AudioSampleData_Get_FMT_MP4A_Data(pstMp4Producer->pstMp4SampleData, &(bData), 1)!= MP4_SAMPLE_DATA_OK)                                 \
      return MP4_PRODUCER_SAMPLE_DATA_READ_ERROR


extern const kal_uint16 lenSpeechBitsAMR[9];
extern const kal_uint16 lenSpeechBitsAMR_WB[10];




#define MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_COUNT(uSampleCount)                  \
   if (MP4_AudioSampleData_GetSampleCount(pstMp4Producer->pstMp4SampleData,  \
      &(uSampleCount)) != MP4_SAMPLE_DATA_OK)                                 \
      return MP4_PRODUCER_SAMPLE_DATA_READ_ERROR

#define MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_SIZE(uSampleNo, uSampleSize)         \
   if (MP4_AudioSampleData_GetSampleSize(pstMp4Producer->pstMp4SampleData,   \
      (uSampleNo), &(uSampleSize)) != MP4_SAMPLE_DATA_OK)                     \
      return MP4_PRODUCER_SAMPLE_DATA_READ_ERROR

#define MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_OFFSET(uSampleNo, uSampleOffset, uSampleNo_Ref, uSampleOffset_Ref)     \
   if (MP4_AudioSampleData_GetSampleOffset(pstMp4Producer->pstMp4SampleData, \
      (uSampleNo), &(uSampleOffset), (uSampleNo_Ref), (uSampleOffset_Ref)) != MP4_SAMPLE_DATA_OK)                   \
      return MP4_PRODUCER_SAMPLE_DATA_READ_ERROR

#define MP4_PRODUCER_FILE_GET_CUR_POS(pos) \
   if (FSAL_GetCurPos(pstMp4Producer->pstFSAL, &(pos))!=FSAL_OK) \
      return MP4_PRODUCER_FILE_ACCESS_ERROR

static MP4_Producer_Status mp4_produce_box(STMp4Producer *pstMp4Producer, kal_uint32 uBoxType, kal_uint32 uBoxSize, kal_uint32 *puFileOffset)
{
   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puFileOffset!=NULL);

   MP4_PRODUCER_FILE_GET_CUR_POS(*puFileOffset);

	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uBoxSize))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uBoxType))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}

static MP4_Producer_Status mp4_produce_fullbox(STMp4Producer *pstMp4Producer, kal_uint32 uBoxType, kal_uint32 uBoxSize, kal_uint8 bVersion, kal_uint32 uFlags, kal_uint32 *puFileOffset)
{
   MP4_Producer_Status ret;
   kal_uint8 pBuf[4];

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puFileOffset!=NULL);

   if ((ret=mp4_produce_box(pstMp4Producer, uBoxType, uBoxSize, puFileOffset))!=MP4_PRODUCER_OK)
      return ret;

   pBuf[0] = bVersion;
   pBuf[1] = (uFlags >> 16) & 0xFF;
   pBuf[2] = (uFlags >> 8) & 0xFF;
   pBuf[3] = (uFlags) & 0xFF;

	if ((pstMp4Producer->eFSALErr=FSAL_Write_Bytes(pstMp4Producer->pstFSAL, pBuf, 4))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}


MP4_Producer_Status MP4_Produce_FileTypeBox(STMp4Producer *pstMp4Producer)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uBoxSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);

   /* header */
   if ((ret=mp4_produce_box(pstMp4Producer, BOX_TYPE_FTYP, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;

   /* major brand */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, MP4_BRAND_3GP5))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   /* minor version */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x00000100))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   uBoxSize = 16;

   /* compatible_brands */
   {
      kal_uint8 pBuf[] = "3gp53gp4";

   	if ((pstMp4Producer->eFSALErr=FSAL_Write_Bytes(pstMp4Producer->pstFSAL, pBuf, 8))!=FSAL_OK)
		   return MP4_PRODUCER_FILE_WRITE_ERROR;

      uBoxSize += 8;
   }

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, uBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}


extern kal_uint8 bMP4_Extr_FrmPerSample;
MP4_Producer_Status mp4_produce_mvhd(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_MVHD, 0, 0, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   /* creation time */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* modification time */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   {
      kal_uint32 uTimeScale;
	  kal_uint32 uSampleCount;
	  kal_uint32 uSamplePerFrame;

	  if (pstMp4Producer->pstMp4SampleData->eAudioType == MP4_AUDIO_AAC){
		  MP4_SAMPLE_DATA_GET_TIME_SCALE(uTimeScale);

		  uSamplePerFrame = 1024;
	  }else if(pstMp4Producer->pstMp4SampleData->eAudioType == MP4_AUDIO_AMR){
		  uTimeScale = 8000;
		  uSamplePerFrame = 160;
	  }else{
		  uTimeScale = 16000;
		  uSamplePerFrame = 320;
	  }

     /* timescale: (audio: 8000) */
  	  if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uTimeScale))!=FSAL_OK)
		  return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
   
   /* duration (audio) */
      
      MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_COUNT(uSampleCount);
  	   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSampleCount*uSamplePerFrame*bMP4_Extr_FrmPerSample))!=FSAL_OK)
		   return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
   }

   /* rate */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x00010000))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* volume */
   {
      kal_uint16 wVolume;
      if (MP4_TRACK_AUDIO==pstMp4Producer->eCurTrack) {
         wVolume = 0x0100;
      } else {
         wVolume = 0;
      }
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, wVolume))!=FSAL_OK)
	      return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 2;
   }

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 10;

   /* matrix */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x00010000))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x00010000))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x40000000))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;

   *puBoxSize += 36;

   /* pre_defined */
   {
      kal_int16 i;

      for(i=0; i<6; i++) {
         if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	         return MP4_PRODUCER_FILE_WRITE_ERROR;
      }
      *puBoxSize += 24;
   }

   /* XXX: next_track_ID */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x07))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_tkhd(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_TKHD, 0, 0, 0x0007, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   /* creation time */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* modification time */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* XXX: track_ID */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x06))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* duration (audio) */
   {
      kal_uint32 uSampleCount;
	  kal_uint32 uSamplePerFrame;

	  if (pstMp4Producer->pstMp4SampleData->eAudioType == MP4_AUDIO_AAC){
		  uSamplePerFrame = 1024;
	  }else if(pstMp4Producer->pstMp4SampleData->eAudioType == MP4_AUDIO_AMR){
		  uSamplePerFrame = 160;
	  }else{
		  uSamplePerFrame = 320;
	  }

      MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_COUNT(uSampleCount);
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSampleCount*uSamplePerFrame*bMP4_Extr_FrmPerSample))!=FSAL_OK)
	      return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
   }

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 8;

   /* layer */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* alternate group */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* volume */
   {
      kal_uint16 wVolume;
      if (MP4_TRACK_AUDIO==pstMp4Producer->eCurTrack) {
         wVolume = 0x0100;
      } else {
         wVolume = 0;
      }
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, wVolume))!=FSAL_OK)
         return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 2;
   }

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* matrix */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x00010000))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x00010000))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x40000000))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 36;

   /* XXX: width */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* XXX: height */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0x0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_mdhd(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_MDHD, 0, 0, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   /* creation time */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* modification time */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   {
      kal_uint32 uTimeScale;
	  kal_uint32 uSampleCount;
	  kal_uint32 uSamplePerFrame;

	  if (pstMp4Producer->pstMp4SampleData->eAudioType == MP4_AUDIO_AAC){
		  MP4_SAMPLE_DATA_GET_TIME_SCALE(uTimeScale);

		  uSamplePerFrame = 1024;
	  }else if(pstMp4Producer->pstMp4SampleData->eAudioType == MP4_AUDIO_AMR){
		  uTimeScale = 8000;
		  uSamplePerFrame = 160;
	  }else{
		  uTimeScale = 16000;
		  uSamplePerFrame = 320;
	  }

     /* timescale: (audio: 8000) */
  	  if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uTimeScale))!=FSAL_OK)
		  return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
   
   /* duration (audio) */
      
      MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_COUNT(uSampleCount);
  	   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSampleCount*uSamplePerFrame*bMP4_Extr_FrmPerSample))!=FSAL_OK)
		   return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
   }

   /* language */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0x15C7))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* predefined */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;


   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}




MP4_Producer_Status mp4_produce_hdlr(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_HDLR, 0, 0, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   /* predefined */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* XXX: handler_type */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, HDLR_TYPE_SOUN))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 12;

   /* string */
   {
      kal_uint8 pBuf[] = "MTK Sound Handler";

   	if ((pstMp4Producer->eFSALErr=FSAL_Write_Bytes(pstMp4Producer->pstFSAL, pBuf, 18))!=FSAL_OK)
		   return MP4_PRODUCER_FILE_WRITE_ERROR;

      *puBoxSize += 18;
   }

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_url(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_URL, 0, 0, 1, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}

MP4_Producer_Status mp4_produce_dref(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uUrlSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_DREF, 0, 0, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   /* entry count */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 1))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* data entry box */
   if((ret=mp4_produce_url(pstMp4Producer, &uUrlSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uUrlSize;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_dinf(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uDrefSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_box(pstMp4Producer, BOX_TYPE_DINF, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 8;

   /* data information */
   if((ret=mp4_produce_dref(pstMp4Producer, &uDrefSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uDrefSize;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



static MP4_Producer_Status mp4_produce_damr(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_box(pstMp4Producer, BOX_TYPE_DAMR, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 8;

   /* AMR Decoder Specific Structure */

   /* vendor */
   {
      kal_uint8 pBuf[] = "MTK ";

	   if ((pstMp4Producer->eFSALErr=FSAL_Write_Bytes(pstMp4Producer->pstFSAL, pBuf, 4))!=FSAL_OK)
		   return MP4_PRODUCER_FILE_WRITE_ERROR;

      *puBoxSize += 4;
   }

   /* decoder version */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 1;

   /* mode_set */
   {
      MP4_Audio_Type eAudioType;
      kal_uint16 wModeSet;
      eAudioType = MP4_AudioSampleData_GetAudioType(pstMp4Producer->pstMp4SampleData);
      if (MP4_AUDIO_AMR == eAudioType) {
         wModeSet = 0x81FF;
      } else if (MP4_AUDIO_AMR_WB == eAudioType) {
         wModeSet = 0x83FF;
      } else {
         return MP4_PRODUCER_SAMPLE_DATA_AUDIO_TYPE_ERROR;
      }
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0x81FF))!=FSAL_OK)
         return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 2;
   }

   /* mode change period */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 1;

   /* frame per sample */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, bMP4_Extr_FrmPerSample))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 1;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}

static MP4_Producer_Status mp4_produce_esds(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);
   
   /* header */
   if((ret=mp4_produce_box(pstMp4Producer, BOX_TYPE_ESDS, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 8;

   /* version */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;

   /* flags */
   {
	  kal_uint32 cnt;
	  for(cnt=3; cnt>0; cnt--){
         if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
            return MP4_PRODUCER_FILE_WRITE_ERROR;
	  }
   }
   *puBoxSize += 4;

      /* tag */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 0x03))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
      /* size */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 25))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;

   /* ES_ID */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0x0002))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;

      /* flag */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 5;

      /* tag */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 0x04))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
      /* size */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 17))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;

      /* objectTypeIndication */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 0x40))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
      /* streamType */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 21))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;

   {
	  kal_uint32 cnt;
	  for(cnt=3; cnt>0; cnt--){
         if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
            return MP4_PRODUCER_FILE_WRITE_ERROR;
	  }
   }

   /* maxBitrate */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   /* avgBitrate */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;

   *puBoxSize += 15;
/* DecoderSpecificInfo */

         /* tag */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 0x05))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
      /* size */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, 2))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;

   *puBoxSize += 2;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;
   
   return MP4_PRODUCER_OK;
}

static MP4_Producer_Status mp4_produce_mp4a(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uDamrSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);
   
   /* header */
   {
      kal_uint32 uBoxType;

      uBoxType = SAMPLE_FMT_MP4A;
      if((ret=mp4_produce_box(pstMp4Producer, uBoxType, 0, &uFilePos))!=MP4_PRODUCER_OK)
         return ret;
      *puBoxSize = 8;
   }

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 6;

   /* data reference index */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 1))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 8;
   
   /* channel count = 2 */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 2))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* sample size = 16 */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 16))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;
   
   /* predefined */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;
   
   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;
   
   {
	  kal_uint32 uTimeScale;
	  MP4_SAMPLE_DATA_GET_TIME_SCALE(uTimeScale);
   /* time scale (audio) */
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, (kal_uint16)uTimeScale))!=FSAL_OK)
         return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 2;
   }

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;
   
   /* MP4A Specific Box */
   if((ret=mp4_produce_esds(pstMp4Producer, &uDamrSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uDamrSize;
   
   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;
   
   return MP4_PRODUCER_OK;
}

static MP4_Producer_Status mp4_produce_samr(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uDamrSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   {
      kal_uint32 uBoxType;
      MP4_Audio_Type eAudioType;
      eAudioType = MP4_AudioSampleData_GetAudioType(pstMp4Producer->pstMp4SampleData);
      if (MP4_AUDIO_AMR == eAudioType) {
         uBoxType = SAMPLE_FMT_SAMR;
      } else if (MP4_AUDIO_AMR_WB == eAudioType) {
         uBoxType = SAMPLE_FMT_SAWB;
      } else {
         return MP4_PRODUCER_SAMPLE_DATA_AUDIO_TYPE_ERROR;
      }
      if((ret=mp4_produce_box(pstMp4Producer, uBoxType, 0, &uFilePos))!=MP4_PRODUCER_OK)
         return ret;
      *puBoxSize = 8;
   }

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 6;

   /* data reference index */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 1))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 8;

   /* channel count = 2 */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 2))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* sample size = 16 */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 16))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* predefined */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* time scale (audio) */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 8000))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* reserved */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 2;

   /* AMR Specific Box */
   if((ret=mp4_produce_damr(pstMp4Producer, &uDamrSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uDamrSize;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}

static MP4_Producer_Status mp4_produce_copy_mp4a(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   kal_uint32 size;
   kal_uint32 cnt;
   kal_uint8  bData;
   kal_uint32 uFilePos;

   MP4_SAMPLE_DATA_GET_FMT_MP4A_SIZE(size);
	      /* header */
	  {
         kal_uint32 uBoxType;

         uBoxType = SAMPLE_FMT_MP4A;
         if((mp4_produce_box(pstMp4Producer, uBoxType, size, &uFilePos))!=MP4_PRODUCER_OK)
            return MP4_PRODUCER_FILE_WRITE_ERROR;
         *puBoxSize = 0;
	  }

   *puBoxSize += size;
   size-=8;

   for(cnt=0; cnt<size; cnt++){
      MP4_SAMPLE_DATA_GET_FMT_MP4A_DATA(bData);
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT8(pstMp4Producer->pstFSAL, bData))!=FSAL_OK)
         return MP4_PRODUCER_FILE_WRITE_ERROR;
   }
   return MP4_PRODUCER_OK;
}

MP4_Producer_Status mp4_produce_stsd(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uSampleSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_STSD, 0, 0, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   /* entry count */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 1))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   if (pstMp4Producer->pstMp4SampleData->eAudioType == MP4_AUDIO_AAC){

      if((mp4_produce_copy_mp4a(pstMp4Producer, &uSampleSize)) != MP4_PRODUCER_OK)
	     return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += uSampleSize;
   }else{
      /* XXX: soun */
      if((ret=mp4_produce_samr(pstMp4Producer, &uSampleSize))!=MP4_PRODUCER_OK)
         return ret;
      *puBoxSize += uSampleSize;
	}

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_stts(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_STTS, 0, 0, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   /* entry count */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 1))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;

   *puBoxSize += 4;

   /* sample count */
   {
      kal_uint32 uSampleCount;
      MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_COUNT(uSampleCount);
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSampleCount))!=FSAL_OK)
 	      return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
   }

   /* sample delta */
   {
	  kal_uint32 uSamplePerFrame;

	  if (pstMp4Producer->pstMp4SampleData->eAudioType == MP4_AUDIO_AAC){
		  uSamplePerFrame = 1024;
	  }else if(pstMp4Producer->pstMp4SampleData->eAudioType == MP4_AUDIO_AMR){
		  uSamplePerFrame = 160;
	  }else{
		  uSamplePerFrame = 320;
	  }

      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSamplePerFrame*bMP4_Extr_FrmPerSample))!=FSAL_OK)
 	      return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
   }

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_stsc(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uEntryCount;
   kal_uint32 uSampleCount;
   kal_uint32 uSamplePerChunk;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_STSC, 0, 0, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   /* get sample count */
   MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_COUNT(uSampleCount);

   /* entry count */
   {
      if(uSampleCount<25) {
         uSamplePerChunk = uSampleCount;
         uEntryCount = 1;
      } else {
         uSamplePerChunk = 25;
         if (0==uSampleCount%25) {
            uEntryCount = 1;
         } else {
            uEntryCount = 2;
         }
      }
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uEntryCount))!=FSAL_OK)
 	      return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
   }

   /* first chunk */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 1))!=FSAL_OK)
 	   return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* samples per chunk */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSamplePerChunk))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* sample description index */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 1))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   if (uEntryCount==2) {
      /* first chunk */
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, (uSampleCount / 25) + 1))!=FSAL_OK)
         return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;

      /* samples per chunk */
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSampleCount % 25))!=FSAL_OK)
         return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;

      /* sample description index */
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, 1))!=FSAL_OK)
         return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
   }

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_stsz(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uSampleSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_STSZ, 0, 0, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   /* sample size */
   {
      //if(KAL_TRUE==MP4_SampleData_Audio_EqualSampleSize())
      //   uSampleSize = MP4_SampleData_Audio_GetSampleSize(pstMp4Producer->pstMp4SampleData);
      //else
         uSampleSize = 0;
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSampleSize))!=FSAL_OK)
         return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
   }


   if(0==uSampleSize) {
      /* sample count */
      kal_uint32 uSampleCount;
      kal_uint32 uSampleNo;

      MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_COUNT(uSampleCount);
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSampleCount))!=FSAL_OK)
         return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;

#if MP4_PRODUCER_AUDIO_VERBOSE
      printf("sample count=%d\n", uSampleCount);
#endif
      for(uSampleNo=0; uSampleNo<uSampleCount; uSampleNo++) {
         kal_uint32 uSampleSize;
         MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_SIZE(uSampleNo, uSampleSize);
         if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSampleSize))!=FSAL_OK)
            return MP4_PRODUCER_FILE_WRITE_ERROR;
         *puBoxSize += 4;
      }

   }

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_stco(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize, kal_uint32 uAudioDataOffset)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uSampleCount;
   kal_uint32 uChunkCount;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_STCO, 0, 0, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_COUNT(uSampleCount);
   uChunkCount = (uSampleCount+24) / 25;
#if MP4_PRODUCER_AUDIO_VERBOSE
   printf("uSampleCount = %d, uChunkCount = %d\n", uSampleCount, uChunkCount);
#endif

   /* chunk count (audio) */
   if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uChunkCount))!=FSAL_OK)
       return MP4_PRODUCER_FILE_WRITE_ERROR;
   *puBoxSize += 4;

   /* chunk offset */
   if( uChunkCount > 0 )
   {
      kal_uint32 uChunkNo = 0;
      kal_uint32 uSampleOffset;
      MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_OFFSET(0, uSampleOffset, 0, 8);
      if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSampleOffset+uAudioDataOffset))!=FSAL_OK)
         return MP4_PRODUCER_FILE_WRITE_ERROR;
      *puBoxSize += 4;
      for(uChunkNo=1; uChunkNo<uChunkCount; uChunkNo++) {
         MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_OFFSET(uChunkNo * 25, uSampleOffset, uChunkNo * 25 - 25, uSampleOffset);
         if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT(pstMp4Producer->pstFSAL, uSampleOffset+uAudioDataOffset))!=FSAL_OK)
            return MP4_PRODUCER_FILE_WRITE_ERROR;
         *puBoxSize += 4;
      }
   }

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_stbl(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize, kal_uint32 uAudioDataOffset)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uStsdSize, uSttsSize, uStscSize, uStszSize, uStcoSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_box(pstMp4Producer, BOX_TYPE_STBL, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 8;

   /* sample description */
   if((ret=mp4_produce_stsd(pstMp4Producer, &uStsdSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uStsdSize;

   /* decoding time-to-sample */
   if((ret=mp4_produce_stts(pstMp4Producer, &uSttsSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uSttsSize;

   /* sample-to-chunk */
   if((ret=mp4_produce_stsc(pstMp4Producer, &uStscSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uStscSize;

   /* sample sizes (framing) */
   if((ret=mp4_produce_stsz(pstMp4Producer, &uStszSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uStszSize;

   /* chunk offset */
   if((ret=mp4_produce_stco(pstMp4Producer, &uStcoSize, uAudioDataOffset))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uStcoSize;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}

MP4_Producer_Status mp4_produce_smhd(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_fullbox(pstMp4Producer, BOX_TYPE_SMHD, 0, 0, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 12;

   if((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;

   if((pstMp4Producer->eFSALErr=FSAL_Write_UINT16(pstMp4Producer->pstFSAL, 0))!=FSAL_OK)
      return MP4_PRODUCER_FILE_WRITE_ERROR;

   *puBoxSize+=4;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}

MP4_Producer_Status mp4_produce_minf(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize, kal_uint32 uAudioDataOffset)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uDinfSize, uStblSize, uSmhdSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_box(pstMp4Producer, BOX_TYPE_MINF, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 8;

   if((ret=mp4_produce_smhd(pstMp4Producer, &uSmhdSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uSmhdSize;

   /* data information */
   if((ret=mp4_produce_dinf(pstMp4Producer, &uDinfSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uDinfSize;

   /* sample table */
   if((ret=mp4_produce_stbl(pstMp4Producer, &uStblSize, uAudioDataOffset))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uStblSize;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_mdia(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize, kal_uint32 uAudioDataOffset)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uMdhdSize, uHdlrSize, uMinfSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);

   /* header */
   if((ret=mp4_produce_box(pstMp4Producer, BOX_TYPE_MDIA, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 8;

   /* media header */
   if((ret=mp4_produce_mdhd(pstMp4Producer, &uMdhdSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uMdhdSize;

   /* handler */
   if((ret=mp4_produce_hdlr(pstMp4Producer, &uHdlrSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uHdlrSize;

   /* media information */
   if((ret=mp4_produce_minf(pstMp4Producer, &uMinfSize, uAudioDataOffset))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uMinfSize;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status MP4_Produce_Trak_Audio(STMp4Producer *pstMp4Producer, kal_uint32 *puBoxSize, kal_uint32 uAudioDataOffset)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uTkhdSize, uMdiaSize;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(puBoxSize!=NULL);
   
   if(!pstMp4Producer->bIsVidEdit)
      bMP4_Extr_FrmPerSample = 1;

   /* header */
   if((ret=mp4_produce_box(pstMp4Producer, BOX_TYPE_TRAK, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize = 8;

   /* track header (tkhd) */
   if((ret=mp4_produce_tkhd(pstMp4Producer, &uTkhdSize))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uTkhdSize;

   /* media information (mdia) */
   if((ret=mp4_produce_mdia(pstMp4Producer, &uMdiaSize, uAudioDataOffset))!=MP4_PRODUCER_OK)
      return ret;
   *puBoxSize += uMdiaSize;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, *puBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}


MP4_Producer_Status MP4_Produce_MovieHeader(STMp4Producer *pstMp4Producer, kal_uint32 uAudioDataOffset)
{
   MP4_Producer_Status ret;
   kal_uint32 uFilePos;
   kal_uint32 uBoxSize, uMvhdSize, uTrakSize;

   /* header */
   if((ret=mp4_produce_box(pstMp4Producer, BOX_TYPE_MOOV, 0, &uFilePos))!=MP4_PRODUCER_OK)
      return ret;
   uBoxSize = 8;

   if((ret=mp4_produce_mvhd(pstMp4Producer, &uMvhdSize))!=MP4_PRODUCER_OK)
      return ret;
   uBoxSize += uMvhdSize;

   if((ret=MP4_Produce_Trak_Audio(pstMp4Producer, &uTrakSize, uAudioDataOffset))!=MP4_PRODUCER_OK)
      return ret;
   uBoxSize += uTrakSize;

   /* update box size */
  	if ((pstMp4Producer->eFSALErr=FSAL_Write_UINT_AT(pstMp4Producer->pstFSAL, uBoxSize, uFilePos))!=FSAL_OK)
		return MP4_PRODUCER_FILE_WRITE_ERROR;

   return MP4_PRODUCER_OK;
}



MP4_Producer_Status mp4_produce_mdat(STMp4Producer *pstMp4Producer)
{
   return MP4_PRODUCER_OK;
}



MP4_Producer_Status MP4_Produce_Init(STMp4Producer *pstMp4Producer, STMp4SampleDataAudio *pstMp4SampleData, STFSAL *pstFSAL)
{
//   MP4_Producer_Status ret;

   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   MP4_PRODUCER_CHECK_ARG(pstMp4SampleData!=NULL);
   MP4_PRODUCER_CHECK_ARG(pstFSAL!=NULL);

   pstMp4Producer->pstMp4SampleData = pstMp4SampleData;
   pstMp4Producer->pstFSAL = pstFSAL;
   pstMp4Producer->eCurTrack = MP4_TRACK_AUDIO;
   
   pstMp4Producer->bIsVidEdit = 0;
      

//   if((ret=MP4_Produce_FileTypeBox(pstMp4Producer))!=MP4_PRODUCER_OK)
//      return ret;

//   if((ret=mp4_produce_mdat(pstMp4Producer))!=MP4_PRODUCER_OK)
//      return ret;

//   if((ret=MP4_Produce_MovieHeader(pstMp4Producer))!=MP4_PRODUCER_OK)
//      return ret;

   return MP4_PRODUCER_OK;
}

MP4_SampleData_Status MP4_Produce_SetVidEditFlag(STMp4Producer *pstMp4Producer)
{
   MP4_PRODUCER_CHECK_ARG(pstMp4Producer!=NULL);
   pstMp4Producer->bIsVidEdit = 1;

   return MP4_PRODUCER_OK;
}


MP4_Producer_Status MP4_Produce_CalculateLimitedAudioFileSize(
   STFSAL *pstFSAL, kal_uint32 uNumBytesLimit, kal_uint32 uMilliSecondsLimit,
   kal_uint8 bAMRType, kal_uint32 *puResultBytes)
{
   kal_uint32 uSpeechFrameLimit;
   kal_uint32 uSpeechFrameCount;
   kal_uint32 uAudioFileLen;
   kal_uint32 uAMRFilePos;
   FSAL_Status eFSALRet;

   ASSERT(pstFSAL!=NULL);
   ASSERT(puResultBytes!=NULL);

   eFSALRet = FSAL_GetFileSize(pstFSAL, &uAudioFileLen);
   if (eFSALRet!=FSAL_OK)
      return MP4_PRODUCER_FILE_ACCESS_ERROR;

   if (uAudioFileLen<8)
      return MP4_PRODUCER_AUDIO_FILE_TOO_SMALL;

   uAMRFilePos = 8;
   *puResultBytes = 8;
   uSpeechFrameLimit = uMilliSecondsLimit / 20;
   uSpeechFrameCount = 0;

   /* parse each audio frame */
   while(uAMRFilePos < uAudioFileLen) {
      unsigned char bFrameHeader;
      unsigned char bFrameType;
      unsigned char bFrameLength;
      unsigned char bFQI;

      eFSALRet = FSAL_Seek(pstFSAL, uAMRFilePos);
      if(eFSALRet!=FSAL_OK)
      {
         return MP4_PRODUCER_FILE_SEEK_ERROR;
      }

      eFSALRet = FSAL_Read_Bytes(pstFSAL, &bFrameHeader, 1);
      if(eFSALRet != FSAL_OK)
         return MP4_PRODUCER_FILE_READ_ERROR;

      bFrameType = (bFrameHeader >> 3)&0x0F;
      bFQI = (bFrameHeader >> 2)&0x01;
      if( bFQI == 0 )
      {
         return MP4_PRODUCER_AMR_FQI_INVALID;
      }
      // ASSERT(bFQI==1);
      // After this line, bFQI is no more valid and hence can be used as temporary variable.

      if (bAMRType==0)
         bFQI = 8; /* AMR */
      else
         bFQI = 9; /* AMR-WB */

      if (bFrameType <= bFQI) {
         bFrameLength = (lenSpeechBitsAMR[bFrameType] + 7) / 8;
      } else if (bFrameType == 15) {
         bFrameLength = 0;
      } else {
         return MP4_PRODUCER_AMR_FRAME_INVALID;
      }

      uAMRFilePos += (bFrameLength + 1);
      uSpeechFrameCount++;

      if (uAMRFilePos > uNumBytesLimit)
         break;

      if (uSpeechFrameCount > uSpeechFrameLimit)
         break;

      /* Handle the case for partial frame */
      if (uAMRFilePos > uAudioFileLen)
         break;

      *puResultBytes += (bFrameLength + 1);
   }

   return MP4_PRODUCER_OK;
}

#ifdef WIN32_UNIT_TEST

#define mu_run_test(test)          \
  do {                             \
    char *message;                 \
    printf("Doing: %s\n", #test);  \
    message = test(); tests_run++; \
    if (message) return message;   \
  } while (0)
extern int tests_run;

int tests_run = 0;

/* No Speech Frame */
const unsigned char amr_file_1[8] = {
   /* 8 bytes file header */
   0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};

/* One Speech Frame */
const unsigned char amr_file_2[22] = {
   /* 8 bytes file header */
   0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
   /* 5.15kbps: 1 byte frame header 13 bytes frame data */
   0x0C, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
};

/* Two Speech Frame */
const unsigned char amr_file_3[36] = {
   /* 8 bytes file header */
   0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
   /* 5.15kbps: 1 byte frame header 13 bytes frame data */
   0x0C, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
   /* 5.15kbps: 1 byte frame header 13 bytes frame data */
   0x0C, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
};

/* File Size Less Than 8 */
const unsigned char amr_file_4[7] = {
   1, 2, 3, 4, 5, 6, 7
};

/* File With Invalid FQI */
const unsigned char amr_file_5[9] = {
   /* 8 bytes file header */
   0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
   /* invalid frame header */
   0
};

/* File With Invalid Frame Header */
const unsigned char amr_file_6[9] = {
   /* 8 bytes file header */
   0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
   /* invalid frame header */
   0x74
};

/* File with partial frame */
const unsigned char amr_file_7[32] = {
   /* 8 bytes file header */
   0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
   /* 5.15kbps: 1 byte frame header 13 bytes frame data */
   0x0C, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
   /* 5.15kbps: 1 byte frame header 13 bytes frame data */
   0x0C, 1, 2, 3, 4, 5, 6, 7, 8, 9
};

STFSAL stFSAL;
FSAL_Status eFSALStatus;
kal_uint32 uResultBytes;
MP4_Producer_Status eMp4ProducerStatus;

static char* mu_CalculateLimitedAudioFileSize_1(void)
{
   FSAL_Direct_SetRamFileSize(&stFSAL, sizeof(amr_file_1));
   eFSALStatus = FSAL_Open(&stFSAL, (void*)amr_file_1, FSAL_ROMFILE);
   ASSERT(eFSALStatus == FSAL_OK);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 0, 0, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 8);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 7, 0, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 8);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 8, 0, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 8);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 9, 0, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 8);
   eFSALStatus = FSAL_Close(&stFSAL);
   ASSERT(eFSALStatus == FSAL_OK);
   return NULL;
}

static char* mu_CalculateLimitedAudioFileSize_2(void)
{
   FSAL_Direct_SetRamFileSize(&stFSAL, sizeof(amr_file_2));
   eFSALStatus = FSAL_Open(&stFSAL, (void*)amr_file_2, FSAL_ROMFILE);
   ASSERT(eFSALStatus == FSAL_OK);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 0, 0, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 8);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 7, 0, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 8);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 8, 0, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 8);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 9, 0, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 8);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 21, 0, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 8);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 22, 0, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 8);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 22, 20, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 22);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 22, 40, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 22);
   eFSALStatus = FSAL_Close(&stFSAL);
   ASSERT(eFSALStatus == FSAL_OK);
   return NULL;
}

static char* mu_CalculateLimitedAudioFileSize_3(void)
{
   FSAL_Direct_SetRamFileSize(&stFSAL, sizeof(amr_file_3));
   eFSALStatus = FSAL_Open(&stFSAL, (void*)amr_file_3, FSAL_ROMFILE);
   ASSERT(eFSALStatus == FSAL_OK);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 36, 40, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 36);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 36, 80, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 36);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 72, 80, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 36);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 35, 40, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 22);
   eFSALStatus = FSAL_Close(&stFSAL);
   ASSERT(eFSALStatus == FSAL_OK);
   return NULL;
}

static char* mu_CalculateLimitedAudioFileSize_4(void)
{
   FSAL_Direct_SetRamFileSize(&stFSAL, sizeof(amr_file_4));
   eFSALStatus = FSAL_Open(&stFSAL, (void*)amr_file_4, FSAL_ROMFILE);
   ASSERT(eFSALStatus == FSAL_OK);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 36, 40, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_AUDIO_FILE_TOO_SMALL);
   eFSALStatus = FSAL_Close(&stFSAL);
   ASSERT(eFSALStatus == FSAL_OK);
   return NULL;
}

static char* mu_CalculateLimitedAudioFileSize_5(void)
{
   FSAL_Direct_SetRamFileSize(&stFSAL, sizeof(amr_file_5));
   eFSALStatus = FSAL_Open(&stFSAL, (void*)amr_file_5, FSAL_ROMFILE);
   ASSERT(eFSALStatus == FSAL_OK);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 36, 40, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_AMR_FQI_INVALID);
   eFSALStatus = FSAL_Close(&stFSAL);
   ASSERT(eFSALStatus == FSAL_OK);
   return NULL;
}

static char* mu_CalculateLimitedAudioFileSize_6(void)
{
   FSAL_Direct_SetRamFileSize(&stFSAL, sizeof(amr_file_6));
   eFSALStatus = FSAL_Open(&stFSAL, (void*)amr_file_6, FSAL_ROMFILE);
   ASSERT(eFSALStatus == FSAL_OK);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 36, 40, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_AMR_FRAME_INVALID);
   eFSALStatus = FSAL_Close(&stFSAL);
   ASSERT(eFSALStatus == FSAL_OK);
   return NULL;
}

static char* mu_CalculateLimitedAudioFileSize_7(void)
{
   FSAL_Direct_SetRamFileSize(&stFSAL, sizeof(amr_file_7));
   eFSALStatus = FSAL_Open(&stFSAL, (void*)amr_file_7, FSAL_ROMFILE);
   ASSERT(eFSALStatus == FSAL_OK);
   eMp4ProducerStatus = MP4_Produce_CalculateLimitedAudioFileSize(&stFSAL, 36, 40, 0, &uResultBytes);
   ASSERT(eMp4ProducerStatus == MP4_PRODUCER_OK);
   ASSERT(uResultBytes == 22);
   eFSALStatus = FSAL_Close(&stFSAL);
   ASSERT(eFSALStatus == FSAL_OK);
   return NULL;
}

static char * all_tests() {
  mu_run_test(mu_CalculateLimitedAudioFileSize_1);
  mu_run_test(mu_CalculateLimitedAudioFileSize_2);
  mu_run_test(mu_CalculateLimitedAudioFileSize_3);
  mu_run_test(mu_CalculateLimitedAudioFileSize_4);
  mu_run_test(mu_CalculateLimitedAudioFileSize_5);
  mu_run_test(mu_CalculateLimitedAudioFileSize_6);
  mu_run_test(mu_CalculateLimitedAudioFileSize_7);
  return 0;
}

int main(int argc, char **argv)
{
   char *result = all_tests();
   if (result != 0) {
      printf("Failed at: %s\n", result);
   } else {
      printf("ALL TESTS PASSED\n");
   }
   printf("Tests run: %d\n", tests_run);

   return (result != 0);
}
#endif

