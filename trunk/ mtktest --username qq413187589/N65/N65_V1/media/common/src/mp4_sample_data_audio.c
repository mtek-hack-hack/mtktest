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
 * mp4_sample_data_audio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Audio sample data file accessing utilities for MPEG-4 recording
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "mp4_sample_data_audio.h"


extern const kal_uint16 lenSpeechBitsAMR[9];
extern const kal_uint16 lenSpeechBitsAMR_WB[10];

#define MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_SIZE(uSampleNo, uSampleSize) \
   if (MP4_AudioSampleData_GetSampleSize(pstMp4SampleData, (uSampleNo), &(uSampleSize))!=MP4_SAMPLE_DATA_OK) \
      return MP4_SAMPLE_DATA_FILE_READ_ERROR;

MP4_SampleData_Status MP4_AudioSampleData_Init(STMp4SampleDataAudio *pstMp4SampleData, STFSAL *pstFSAL)
{

   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData!=NULL);
   MP4_SAMPLE_DATA_CHECK_ARG(pstFSAL!=NULL);

   pstMp4SampleData->pstFSAL = pstFSAL;
   pstMp4SampleData->bIsVidEdit = 0;

   /* get audio type */
   pstMp4SampleData->eAudioType = MP4_AUDIO_NONE;
	if ((pstMp4SampleData->eFSALErr=FSAL_Seek(pstFSAL, 0))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_SEEK_ERROR;
	if ((pstMp4SampleData->eFSALErr=FSAL_Read_Bytes(pstFSAL, (kal_uint8 *)&(pstMp4SampleData->eAudioType), 1))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_READ_ERROR;

   return MP4_SAMPLE_DATA_OK;
}

MP4_SampleData_Status MP4_AudioSampleData_SetVidEditFlag(STMp4SampleDataAudio *pstMp4SampleData)
{
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData!=NULL);
   pstMp4SampleData->bIsVidEdit = 1;

   return MP4_SAMPLE_DATA_OK;
}

 MP4_SampleData_Status MP4_AudioSampleData_GetSampleCount(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 *puSampleCount)
{
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData!=NULL);
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData->pstFSAL!=NULL);
   MP4_SAMPLE_DATA_CHECK_ARG(puSampleCount!=NULL);

	if ((pstMp4SampleData->eFSALErr=FSAL_Seek(pstMp4SampleData->pstFSAL, 1))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_SEEK_ERROR;

	if ((pstMp4SampleData->eFSALErr=FSAL_Read_UINT(pstMp4SampleData->pstFSAL, puSampleCount))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_READ_ERROR;

   return MP4_SAMPLE_DATA_OK;
}

MP4_SampleData_Status MP4_AudioSampleData_WriteSampleCount(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 uSampleCount)
{
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData!=NULL);
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData->pstFSAL!=NULL);

	if ((pstMp4SampleData->eFSALErr=FSAL_Seek(pstMp4SampleData->pstFSAL, 1))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_SEEK_ERROR;

	if ((pstMp4SampleData->eFSALErr=FSAL_Write_UINT(pstMp4SampleData->pstFSAL, uSampleCount))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_WRITE_ERROR;

   return MP4_SAMPLE_DATA_OK;
}

MP4_SampleData_Status MP4_AudioSampleData_GetTimeScale(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 *puTimeScale)
{
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData!=NULL);
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData->pstFSAL!=NULL);

	if ((pstMp4SampleData->eFSALErr=FSAL_Seek(pstMp4SampleData->pstFSAL, 5))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_SEEK_ERROR;

	if ((pstMp4SampleData->eFSALErr=FSAL_Read_UINT(pstMp4SampleData->pstFSAL, puTimeScale))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_READ_ERROR;

   return MP4_SAMPLE_DATA_OK;
}

MP4_SampleData_Status MP4_AudioSampleData_Get_FMT_MP4A_Size(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 *puSize)
{
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData!=NULL);
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData->pstFSAL!=NULL);

	if ((pstMp4SampleData->eFSALErr=FSAL_Seek(pstMp4SampleData->pstFSAL, 9))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_SEEK_ERROR;

	if ((pstMp4SampleData->eFSALErr=FSAL_Read_UINT(pstMp4SampleData->pstFSAL, puSize))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_READ_ERROR;

   return MP4_SAMPLE_DATA_OK;
}

MP4_SampleData_Status MP4_AudioSampleData_Get_FMT_MP4A_Data(STMp4SampleDataAudio *pstMp4SampleData, kal_uint8 *pbData, kal_uint32 size)
{
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData!=NULL);
   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData->pstFSAL!=NULL);

	if ((pstMp4SampleData->eFSALErr=FSAL_Read_Bytes(pstMp4SampleData->pstFSAL, pbData, size))!=FSAL_OK)
		return MP4_SAMPLE_DATA_FILE_READ_ERROR;

   return MP4_SAMPLE_DATA_OK;
}

kal_bool MP4_AudioSampleData_EqualSampleSize(STMp4SampleDataAudio *pstMp4SampleData)
{
   return KAL_FALSE;
}



MP4_SampleData_Status MP4_AudioSampleData_GetSampleSize(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 uSampleNo, kal_uint32 *puSampleSize)
{
   if(!pstMp4SampleData->bIsVidEdit){
      kal_uint8 bFrameType;
      
      MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData!=NULL);
      MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData->pstFSAL!=NULL);
      MP4_SAMPLE_DATA_CHECK_ARG(puSampleSize!=NULL);
      
	   if ((pstMp4SampleData->eFSALErr=FSAL_Seek(pstMp4SampleData->pstFSAL, 5 + uSampleNo*1))!=FSAL_OK)
	   	return MP4_SAMPLE_DATA_FILE_SEEK_ERROR;
      
	   if ((pstMp4SampleData->eFSALErr=FSAL_Read_Bytes(pstMp4SampleData->pstFSAL, &bFrameType, 1))!=FSAL_OK)
	   	return MP4_SAMPLE_DATA_FILE_READ_ERROR;
      
      if (MP4_AUDIO_AMR==pstMp4SampleData->eAudioType) {
         if (bFrameType<=8)
            *puSampleSize = (lenSpeechBitsAMR[bFrameType] + 7) / 8;
         else if (bFrameType==15)
            *puSampleSize = 0;
         else
            return MP4_SAMPLE_DATA_FILE_FORMAT_ERROR;
      } else if (MP4_AUDIO_AMR_WB==pstMp4SampleData->eAudioType) {
         if (bFrameType<=9)
            *puSampleSize = (lenSpeechBitsAMR_WB[bFrameType] + 7) / 8;
         else if (bFrameType==15)
            *puSampleSize = 0;
         else
            return MP4_SAMPLE_DATA_FILE_FORMAT_ERROR;
      } else {
         return MP4_SAMPLE_DATA_FILE_FORMAT_ERROR;
      }
      
      *puSampleSize += 1; /* include frame header */
      
      return MP4_SAMPLE_DATA_OK;
   }else{
      kal_uint8 bFrameSize;
      kal_uint16 wFrameSize;
      
      MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData!=NULL);
      MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData->pstFSAL!=NULL);
      MP4_SAMPLE_DATA_CHECK_ARG(puSampleSize!=NULL);
      
      if(MP4_AUDIO_AAC==pstMp4SampleData->eAudioType) {
         kal_uint32 uFMT_MP4A_Size;
         if ((pstMp4SampleData->eFSALErr=FSAL_Seek(pstMp4SampleData->pstFSAL, 9))!=FSAL_OK)
	   	 return MP4_SAMPLE_DATA_FILE_SEEK_ERROR;
      
	     if ((pstMp4SampleData->eFSALErr=FSAL_Read_UINT(pstMp4SampleData->pstFSAL, &uFMT_MP4A_Size))!=FSAL_OK)
	    	return MP4_SAMPLE_DATA_FILE_READ_ERROR;
      
         if ((pstMp4SampleData->eFSALErr=FSAL_Seek(pstMp4SampleData->pstFSAL, 9 + (uFMT_MP4A_Size-8) + uSampleNo*2))!=FSAL_OK)
	   	 return MP4_SAMPLE_DATA_FILE_SEEK_ERROR;
	     if ((pstMp4SampleData->eFSALErr=FSAL_Read_UINT16(pstMp4SampleData->pstFSAL, &wFrameSize))!=FSAL_OK)
	   	 return MP4_SAMPLE_DATA_FILE_READ_ERROR;
         *puSampleSize = (kal_uint32)wFrameSize;
      }else{
      
          if ((pstMp4SampleData->eFSALErr=FSAL_Seek(pstMp4SampleData->pstFSAL, 9 + uSampleNo*2))!=FSAL_OK)
	      	   return MP4_SAMPLE_DATA_FILE_SEEK_ERROR;	   
	      if ((pstMp4SampleData->eFSALErr=FSAL_Read_UINT16(pstMp4SampleData->pstFSAL, &wFrameSize))!=FSAL_OK)
	   	   return MP4_SAMPLE_DATA_FILE_READ_ERROR;
          
	      *puSampleSize = (kal_uint32)wFrameSize;
      
      }
      
      return MP4_SAMPLE_DATA_OK;
   }

}



MP4_Audio_Type MP4_AudioSampleData_GetAudioType(STMp4SampleDataAudio *pstMp4SampleData)
{
   ASSERT(pstMp4SampleData!=NULL);

   return pstMp4SampleData->eAudioType;
}

MP4_SampleData_Status MP4_AudioSampleData_GetSampleOffset(STMp4SampleDataAudio *pstMp4SampleData, kal_uint32 uSampleNo, kal_uint32 *puSampleOffset, kal_uint32 uSampleNo_Ref, kal_uint32 uSampleOffset_Ref)
{
   kal_uint32 uEachSample;

   MP4_SAMPLE_DATA_CHECK_ARG(pstMp4SampleData!=NULL);
   MP4_SAMPLE_DATA_CHECK_ARG(puSampleOffset!=NULL);

   *puSampleOffset = uSampleOffset_Ref;

   for(uEachSample=uSampleNo_Ref; uEachSample<uSampleNo; uEachSample++) {
      kal_uint32 uSampleSize;
      MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_SIZE(uEachSample, uSampleSize);
      *puSampleOffset += uSampleSize;
   }
   // printf("get sample %d offset=%d\n", uSampleNo, uSampleOffset);
   // *puSampleOffset += 8; /* XXX: "8" WILL BE AN INPUT WHEN INTEGRATION */

   return MP4_SAMPLE_DATA_OK;
}


