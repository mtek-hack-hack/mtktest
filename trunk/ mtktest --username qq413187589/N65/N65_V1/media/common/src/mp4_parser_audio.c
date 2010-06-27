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
 * mp4_parser_audio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Parser, for handling audio-related boxes
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
 
#include "mp4_parser.h"
#include "mp4_sample_data_audio.h"
#include "med_utility.h"

//extern void*  med_alloc_ext_mem(kal_int32 size);
//extern void   med_free_ext_mem(void** pointer);
static const kal_uint32 samplingFrequencyFromIndex[16] = {
  96000, 88200, 64000, 48000, 44100, 32000, 24000, 22050,
  16000, 12000, 11025, 8000, 7350, 0, 0, 0
};
#define MP4_SAMPLE_DATA_WRITE_AUDIO_SAMPLE_COUNT(uSampleCount)                  \
   if (MP4_AudioSampleData_WriteSampleCount((STMp4SampleDataAudio *)pstFSAL_AudioSampleDataFile,                   \
      uSampleCount) != MP4_SAMPLE_DATA_OK)                                 \
      return MP4_AUD_EXTR_FILE_WRITE_ERROR

#define MP4_SAMPLE_DATA_GET_AUDIO_SAMPLE_COUNT(uSampleCount)                  \
   if (MP4_AudioSampleData_GetSampleCount((STMp4SampleDataAudio *)pstFSAL_AudioSampleDataFile,                   \
      (kal_uint32 *)&(uSampleCount)) != MP4_SAMPLE_DATA_OK)                                 \
      return MP4_AUD_EXTR_FILE_READ_ERROR
      

/*
   Convert sampling frequency to sampling frequency index.
   Refer to 14496-3 Subpart 4
*/
kal_uint32 convertSamplingFreqToIndex(kal_uint32 uSamplingFreq)
{
   kal_uint32 uSamplingFreqIndex;
   if (uSamplingFreq>=92017) uSamplingFreqIndex = 0x0;
   else if (uSamplingFreq>=75132) uSamplingFreqIndex = 0x1;
   else if (uSamplingFreq>=55426) uSamplingFreqIndex = 0x2;
   else if (uSamplingFreq>=46009) uSamplingFreqIndex = 0x3;
   else if (uSamplingFreq>=37566) uSamplingFreqIndex = 0x4;
   else if (uSamplingFreq>=27713) uSamplingFreqIndex = 0x5;
   else if (uSamplingFreq>=23004) uSamplingFreqIndex = 0x6;
   else if (uSamplingFreq>=18783) uSamplingFreqIndex = 0x7;
   else if (uSamplingFreq>=13856) uSamplingFreqIndex = 0x8;
   else if (uSamplingFreq>=11502) uSamplingFreqIndex = 0x9;
   else if (uSamplingFreq>=9391) uSamplingFreqIndex = 0xa;
   else uSamplingFreqIndex = 0xb;
   
   return uSamplingFreqIndex;
}



/*
DESCRIPTION
   Parse the Program Config Element of AudioSpecificConfig of 14496-3.
INPUT
   *puBitCnt: current bit offset
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_decoder_config_14496_3_pce(STMp4Parser *pstMp4Parser, kal_uint32 *puBitCnt)
{
   kal_uint32 uInitialBitCnt = *puBitCnt;
   kal_uint8 element_instance_tag;
   kal_uint8 object_type;
   kal_uint8 sampling_freq_index;
   kal_uint8 num_front_channel_elements;
   kal_uint8 num_side_channel_elements;
   kal_uint8 num_back_channel_elements;
   kal_uint8 num_lfe_channel_elements;
   kal_uint8 num_assoc_data_elements;
   kal_uint8 num_valid_cc_elements;
   kal_uint8 mono_mixdown_present;
   kal_uint8 stereo_mixdown_present;
   kal_uint8 matrix_mixdown_idx_present;
   kal_uint8 discard;
   kal_uint8 i;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puBitCnt!=NULL);

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &element_instance_tag, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((element_instance_tag == 0) || (element_instance_tag == 1))
      pstMp4Parser->bAudioChannelConfig = element_instance_tag + 1;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &object_type, 2))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &sampling_freq_index, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_front_channel_elements, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_side_channel_elements, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_back_channel_elements, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_lfe_channel_elements, 2))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_assoc_data_elements, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &num_valid_cc_elements, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   /* mono mixdown */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &mono_mixdown_present, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if(mono_mixdown_present) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 4))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   /* stereo mixdown */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &stereo_mixdown_present, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if(stereo_mixdown_present) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 4))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   /* matrix mixdown */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &matrix_mixdown_idx_present, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if(matrix_mixdown_idx_present) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 3))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   /* front channel element */
   for(i=0; i<num_front_channel_elements; i++) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 5))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   /* side channel element */
   for(i=0; i<num_side_channel_elements; i++) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 5))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   /* back channel element */
   for(i=0; i<num_back_channel_elements; i++) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 5))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   /* lfe channel element */
   for(i=0; i<num_lfe_channel_elements; i++) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 4))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   /* assoc data element */
   for(i=0; i<num_assoc_data_elements; i++) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 4))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   /* valid cc element */
   for(i=0; i<num_valid_cc_elements; i++) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, puBitCnt, &discard, 5))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
   }
   pstMp4Parser->uAudioPCEBitLength = (*puBitCnt)-uInitialBitCnt;

   return MP4_PARSER_OK;
}


/*
DESCRIPTION
   Parse Sample Entry MP4A.
INPUT
   size: The size of Sample Entry MP4A excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

MP4_Parser_Status mp4_parse_mp4a(STMp4Parser *pstMp4Parser, long mp4a_size)
{
   /* Sample Entry MP4A is a leaf node. */
   MP4_Parser_Status ret;

   /* Audio Sample Entry */
   kal_uint16 channelcount;
   kal_uint16 samplesize;
   kal_uint32 samplerate;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /* Sample Entry */
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   mp4a_size-=8;

   /* Audio Sample Entry */
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &channelcount))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &samplesize))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &samplerate))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   mp4a_size-=20;
#if MP4_PARSER_VERBOSE
   printf("channel=%u, samplesize=%u, samplerate=%u\n",
      channelcount, samplesize, samplerate>>16);
#endif

   /* ESDBox */
   {
      unsigned int size;
      unsigned int type;

      if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      if(type==BOX_TYPE_ESDS) {
         if((ret=mp4_parse_esds(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
      } else
         return MP4_PARSER_PARSE_ERROR;
   }

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse AMR Specific Box.
INPUT
   size: The size of AMR Specific Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_damr(STMp4Parser *pstMp4Parser, long damr_size)
{
   kal_uint16 mode_set;
   kal_uint8 mode_change_period;
   kal_uint8 bFramesPerSample;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /* AMR Decoder Specific Structure */
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 5))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &mode_set))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &mode_change_period, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &bFramesPerSample, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   damr_size-=9;
#if MP4_PARSER_VERBOSE
   printf("mode_set=%0X, mode_change_period=%0X, frames_per_sample=%0X\n",
      mode_set, mode_change_period, bFramesPerSample);
#endif
   pstMp4Parser->bFramesPerSample = bFramesPerSample;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, damr_size))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   return MP4_PARSER_OK;
}



kal_uint8 mp4_audio_amr_get_frame_per_sample(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   
   return pstMp4Parser->bFramesPerSample;
}



/*
DESCRIPTION
   Parse Sample Entry SAMR or SAWB.
INPUT
   size: The size of Sample Entry SAMR or SAWB excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

MP4_Parser_Status mp4_parse_samr(STMp4Parser *pstMp4Parser, long samr_size)
{
   /* Sample Entry SAMR or SAWB is a leaf node. */
   MP4_Parser_Status ret;

   /* Audio Sample Entry */
   kal_uint16 channelcount;
   kal_uint16 samplesize;
   kal_uint32 uSampleRate;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /* Sample Entry */
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   samr_size-=8;

   /* Audio Sample Entry */
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &channelcount))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &samplesize))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &uSampleRate))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   pstMp4Parser->bAudioSamplingFreqIndex = convertSamplingFreqToIndex(uSampleRate>>16);

   samr_size-=20;
   
#if MP4_PARSER_VERBOSE
   printf("channel=%u, samplesize=%u, samplerate=%u\n",
      channelcount, samplesize, uSampleRate>>16);
#endif

   /* AMRSpecificBox */
   {
      kal_uint32 size, type;

      if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      if(type==BOX_TYPE_DAMR) {
         if((ret=mp4_parse_damr(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
      } else
         return MP4_PARSER_DAMR_BOX_EXPECTED;
   }

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the AudioSpecificConfig of 14496-3.
INPUT
   size: The size of the decoder specific info.
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

MP4_Parser_Status mp4_parse_decoder_config_14496_3(STMp4Parser *pstMp4Parser, long box_size)
{
   MP4_Parser_Status ret;
   kal_uint32 uBitCnt = 0;

   /* Audio Specific Config */
   kal_uint8 audioObjectType;
   kal_uint8 samplingFreqIndex;
   kal_uint32 samplingFreq;

   /* GA Specific Config */
   kal_uint8 frameLengthFlag;
   kal_uint8 dependsOnCoreCoder;
   kal_uint8 extensionFlag;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /* Refer to 14496-3 Subpart 1 */

   /* audio object type */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &audioObjectType, 5))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &samplingFreqIndex, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   
   if(samplingFreqIndex==0xf) {
      kal_uint8 freq[3];
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &freq[2], 8))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &freq[1], 8))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &freq[0], 8))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

      samplingFreq = (freq[2]<<16) + (freq[1]<<8) + (freq[0]);

      /* Refer to 14496-3 Subpart 4 */
      samplingFreqIndex = convertSamplingFreqToIndex(samplingFreq);
   } else if(samplingFreqIndex==0xc) {
      /* Refer to 14496-3 Subpart 4 */
      samplingFreqIndex = 0xb;
   } else if(samplingFreqIndex==0xd || samplingFreqIndex==0xe) {
      return MP4_PARSER_PARSE_ERROR;
   }
   if(samplingFreqIndex<=0x02) {
      return MP4_PARSER_SAMPLING_FREQ_NOT_SUPPORT;
   }

   pstMp4Parser->bAudioSamplingFreqIndex = samplingFreqIndex;

   /* channel configuration */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &(pstMp4Parser->bAudioChannelConfig), 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if(pstMp4Parser->bAudioChannelConfig>0x02)
      return MP4_PARSER_AUDIO_TOO_MANY_CHANNEL;

   /* GA Specific Config */
   /* Refer to 14496-3 Part 4 */

   /* frame length flag */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &frameLengthFlag, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if(frameLengthFlag!=0)
      return MP4_PARSER_960_120_IMDCT_NOT_SUPPORT;

   /* depends on core coder */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &dependsOnCoreCoder, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   //if(dependsOnCoreCoder)
   //   return MP4_PARSER_SCALABLE_STREAM_NOT_SUPPORT;

   /* extension flag */
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bits(pstMp4Parser->pstFSAL, &uBitCnt, &extensionFlag, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if(pstMp4Parser->bAudioChannelConfig==0) {
      /* parse program_config_element */
      MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->uAudioPCEFileOffset);
      
      if((ret=mp4_parse_decoder_config_14496_3_pce(pstMp4Parser, &uBitCnt))!=MP4_PARSER_OK)
         return ret;
   }

   box_size -= (uBitCnt+7)/8;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, box_size))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   return MP4_PARSER_OK;
}



static void putbits(unsigned char *in, unsigned int *bitcnt, int data, int data_length)
{
   int t,count;

   MP4_PARSER_ASSERT_NO_RET_VAL(data_length>0 && data_length<=16);

   t = *bitcnt;

   if( (t & 0x7)== 0)
      in[t>>3] = 0;

   if( (t & 0x7) + data_length  <= 8)
      in[(t>>3)] |= (data << (8-((t&0x7) + data_length)));
   else {
      count = (t&7) + data_length;
      in[(t>>3)] |= (data >> (data_length - 8 + (t&7)));
      count -= 8;

      if(count > 8) {
         in[(t>>3)+1] = (unsigned char)((data >> (count-8))&0xFF);
         in[(t>>3)+2] = (unsigned char)((data << (16-count))&0xFF);
      } else {
         in[(t>>3)+1] = (unsigned char)((data << (8-count))&0xFF);
      }
   }
   *bitcnt += data_length;
}

/*
 * Prepare only once for the whole stream.
 */
MP4_Parser_Status prepareADIFFrameHeader(STMp4Parser *pstMp4Parser)
{
   kal_uint32 uBitCnt;
   kal_uint32 uBitrate;
   kal_uint8 *pbHeader;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   pbHeader = pstMp4Parser->pbADIFFrameHeader;
   
   pstMp4Parser->uADIFHeaderReadOffset = 0;

   if(pstMp4Parser->uAudioAvgBitrate) { /* constant bitrate */
      uBitrate = pstMp4Parser->uAudioAvgBitrate;
   } else {
      uBitrate = pstMp4Parser->uAudioMaxBitrate;
   }

   /* adif_header */
   uBitCnt = 0;
   //uHeaderSize = 8 + pstMp4Parser->uAudioPCELength;
   putbits(pbHeader, &uBitCnt, 0x4144, 16); /* adif_id: AD */
   putbits(pbHeader, &uBitCnt, 0x4946, 16); /* adif_id: IF */
   putbits(pbHeader, &uBitCnt, 0, 1);     /* copyright id present */
   putbits(pbHeader, &uBitCnt, 1, 1);     /* original copy */
   putbits(pbHeader, &uBitCnt, 0, 1);     /* home */
   putbits(pbHeader, &uBitCnt, 1, 1);     /* bitstream type */
   putbits(pbHeader, &uBitCnt, (uBitrate>>7) & 0xFFFF, 16); /* bit rate */
   putbits(pbHeader, &uBitCnt, (uBitrate) & 0x7F, 7);    /* bit rate */
   putbits(pbHeader, &uBitCnt, 0x0, 4);      /* number of program config elements */
   MP4_PARSER_ASSERT(uBitCnt==63);

   /* program_config_element */
   {
      kal_int32 iBitLeft;
      kal_uint8 bPCE;

      if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, pstMp4Parser->uAudioPCEFileOffset))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;

      iBitLeft = pstMp4Parser->uAudioPCEBitLength;
      while (iBitLeft > 0) {
         if ((pstMp4Parser->eFSALErr=FSAL_Read(pstMp4Parser->pstFSAL, &bPCE, 1))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
         if (iBitLeft<8)
            putbits(pbHeader, &uBitCnt, bPCE, iBitLeft);
         else
            putbits(pbHeader, &uBitCnt, bPCE, 8);
         iBitLeft -= 8;
      }
   }

   /* byte alignment */
   if (uBitCnt%8 != 0)
      putbits(pbHeader, &uBitCnt, 0, 8-uBitCnt%8);

   /* comment_field_bytes */
   putbits(pbHeader, &uBitCnt, 0, 8);

   MP4_PARSER_ASSERT(uBitCnt%8 == 0);
   MP4_PARSER_ASSERT(uBitCnt<=ADIF_HEADER_SIZE*8);
   
   pstMp4Parser->uADIFFrameHeaderLen = uBitCnt/8;
   
   MP4_PARSER_ASSERT(pstMp4Parser->uADIFFrameHeaderLen ==
      (63 + pstMp4Parser->uAudioPCEBitLength + 7) / 8 + 1);
   
   return MP4_PARSER_OK;
}
/*
 * Prepare for every audio sample of the whole stream.
 */
void prepareADTSFrameHeader(STMp4Parser *pstMp4Parser, kal_uint8* pbFrameHeader, kal_uint32 uSampleSize)
{
   kal_uint32 uBitCnt;

   MP4_PARSER_ASSERT_NO_RET_VAL(pstMp4Parser!=NULL);
   MP4_PARSER_ASSERT_NO_RET_VAL(pbFrameHeader!=NULL);

   /* adts_fixed_header */
   uBitCnt = 0;
   putbits(pbFrameHeader, &uBitCnt, 0xFFF, 12); // syncword
   putbits(pbFrameHeader, &uBitCnt, 0, 1);      // ID
   putbits(pbFrameHeader, &uBitCnt, 0, 2);      // Layer
   putbits(pbFrameHeader, &uBitCnt, 1, 1);      // Protection absent
   putbits(pbFrameHeader, &uBitCnt, 1, 2);      // Profile
   putbits(pbFrameHeader, &uBitCnt, MP4_Audio_GetFreqIndex(pstMp4Parser), 4); // sample_frequency_index
   putbits(pbFrameHeader, &uBitCnt, 0, 1);      // private_bit
   putbits(pbFrameHeader, &uBitCnt, pstMp4Parser->bAudioChannelConfig, 3); // Channel_configuration
   putbits(pbFrameHeader, &uBitCnt, 1, 1);      // original_copy
   putbits(pbFrameHeader, &uBitCnt, 0, 1);      // Home

   /* adts_variable_header */
   putbits(pbFrameHeader, &uBitCnt, 0, 1);      // copy_identification_bit
   putbits(pbFrameHeader, &uBitCnt, 0, 1);      // copy_identification_byte
   putbits(pbFrameHeader, &uBitCnt, uSampleSize + ADTS_HEADER_SIZE, 13); // length
   putbits(pbFrameHeader, &uBitCnt, 0x7FF, 11); // buffer_fullness
   putbits(pbFrameHeader, &uBitCnt, 0, 2);      // no_raw_data_blocks_in_frame
   MP4_PARSER_ASSERT_NO_RET_VAL(uBitCnt==56);
}

MP4_Parser_Status prepareAACFrameHeader(STMp4Parser *pstMp4Parser)
{
   MP4_Parser_Status ret;
   MP4_Audio_Type eAudioType;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   eAudioType = MP4_GetAudioType(pstMp4Parser);
   if (eAudioType != MP4_AUDIO_AAC)
      return MP4_PARSER_OK;

   if (pstMp4Parser->bAudioChannelConfig==0) {
      /* Generate ADIF stream */
      pstMp4Parser->bAddADIFFrameHeader = KAL_TRUE;
      if ((ret=prepareADIFFrameHeader(pstMp4Parser))!=MP4_PARSER_OK)
         return ret;
   } else {
      /* Generate ADTS stream */
      pstMp4Parser->bAddADTSFrameHeader = KAL_TRUE;
   }
   
   return MP4_PARSER_OK;
}



kal_uint8 MP4_Audio_GetFreqIndex(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   return pstMp4Parser->bAudioSamplingFreqIndex;
}

kal_uint32 MP4_Audio_GetSamplingFreq(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(pstMp4Parser->bAudioType == MP4_AUDIO_AAC){
      return samplingFrequencyFromIndex[pstMp4Parser->bAudioSamplingFreqIndex];
   }else if(pstMp4Parser->bAudioType == MP4_AUDIO_AMR){
      return 8000;
   }else if(pstMp4Parser->bAudioType == MP4_AUDIO_AMR_WB){
      return 16000;
   }else
      MP4_PARSER_ASSERT(0);
}

kal_uint8 MP4_Audio_GetChannelNum(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(pstMp4Parser->bAudioType == MP4_AUDIO_AAC){
      kal_uint8 bAudioChannelConfig = pstMp4Parser->bAudioChannelConfig;
      
      if(bAudioChannelConfig)
         return bAudioChannelConfig;
      else{
         return 2; // Not support
      }
   }else // AMR or AWB
      return 1;
}

MP4_Parser_Status MP4_Audio_SetFSAL(STMp4Parser *pstMp4Parser, STFSAL *pstFSALAudio)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(pstFSALAudio!=NULL);
   
   pstMp4Parser->pstFSALAudio = pstFSALAudio;

   return MP4_PARSER_OK;
}



MP4_Parser_Status MP4_Audio_Seek_To_Video(STMp4Parser *pstMp4Parser, kal_uint64 uVideoDecodeTime, kal_uint32 *puAudioSampleNo)
{
   MP4_Parser_Status ret;
   kal_uint64 uAudioDecodeTime;
   kal_uint32 uVideoTimeScale;
   kal_uint32 uAudioTimeScale;
   
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puAudioSampleNo!=NULL);

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uVideoTimeScale, MP4_TRACK_VIDEO))!=MP4_PARSER_OK)
      return ret;

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;

   uAudioDecodeTime = uVideoDecodeTime * uAudioTimeScale / uVideoTimeScale;   
   if ((ret=MP4_GetSampleNumber(pstMp4Parser, puAudioSampleNo, uAudioDecodeTime, MP4_TRACK_AUDIO ))!=MP4_PARSER_OK)
      return ret;
   
   return MP4_PARSER_OK;
}



MP4_Parser_Status MP4_Audio_Seek(STMp4Parser *pstMp4Parser, kal_uint32 uAudioSampleNo)
{
   MP4_Parser_Status ret;
   kal_uint32 uAudioSampleCount;
   kal_uint32 uAudioTimeScale;
   kal_uint64 uAudioDecodeTime;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   pstMp4Parser->uAudioReadSampleNo = uAudioSampleNo;
   pstMp4Parser->uAudioReadSampleOffset = 0;
   pstMp4Parser->uADTSHeaderReadOffset = 0;

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;

   if ((ret=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uAudioSampleCount))!=MP4_PARSER_OK)
      return ret;

   if ((ret=MP4_GetDecodeTime(pstMp4Parser, uAudioSampleNo, &uAudioDecodeTime, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;
   
   pstMp4Parser->uAudioSeekPointTime = uAudioDecodeTime * 1000 / uAudioTimeScale;

   if (uAudioSampleNo < uAudioSampleCount) { 
      if ((ret=MP4_GetSampleOffset(pstMp4Parser, uAudioSampleNo, &(pstMp4Parser->uAudioReadSampleFileOffset), MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
         return ret;
   }
   
   return MP4_PARSER_OK;
}



/*
 * Invoke MP4_GetSampleOffset_Next for optimization
 */
MP4_Parser_Status MP4_Audio_Seek_Internal(STMp4Parser *pstMp4Parser, kal_uint32 uAudioSampleNo)
{
   MP4_Parser_Status ret;
   kal_uint32 uAudioSampleCount;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   pstMp4Parser->uAudioReadSampleNo = uAudioSampleNo;
   pstMp4Parser->uAudioReadSampleOffset = 0;
   pstMp4Parser->uADTSHeaderReadOffset = 0;

   if ((ret=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uAudioSampleCount))!=MP4_PARSER_OK)
      return ret;

   if (uAudioSampleNo<uAudioSampleCount) { 
      if ((ret=MP4_GetSampleOffset_Next(pstMp4Parser, &(pstMp4Parser->uAudioReadSampleFileOffset), MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
         return ret;
   }

   return MP4_PARSER_OK;
}

/* Update some variables after reading some data */
#define MP4_AUDIO_READ_UPDATE(uLen) \
   *uReadSize += (uLen); \
   pBuf += (uLen); \
   uSizeLeft -= (uLen)

/**
 * Read audio samples as a contiguous stream.
 * Note that fsal_direct_seek must be done immediately before fsal_direct_read,
 * to avoid the situation
 * that when accessing sample tables, file position has been changed.
 */
MP4_Parser_Status MP4_Audio_Read(STMp4Parser *pstMp4Parser, kal_uint8* pBuf, kal_uint32 uSize, kal_uint32 *uReadSize)
{
   MP4_Parser_Status ret;
   kal_uint32 uSizeLeft = uSize;
   kal_uint32 uCurSampleSize;
   kal_uint32 uCurSampleOffset;
   kal_uint32 uSampleCount;
   kal_uint32 uFileOffset;
   kal_uint8 *pbADTSFrameHeader;
   kal_uint8 *pbADIFFrameHeader;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(pstMp4Parser->pstFSALAudio!=NULL);
   MP4_PARSER_CHECK_ARG(pBuf!=NULL);
   MP4_PARSER_CHECK_ARG(uReadSize!=NULL);

   /* Initialize some local variables */
   *uReadSize = 0;
   pbADTSFrameHeader = pstMp4Parser->pbADTSFrameHeader;
   pbADIFFrameHeader = pstMp4Parser->pbADIFFrameHeader;

   /* consider when there is no audio track or audio sample number is 0 */
   if ((ret=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uSampleCount))!=MP4_PARSER_OK)
      return ret;
   if (pstMp4Parser->uAudioReadSampleNo >= uSampleCount)
      return MP4_PARSER_READ_EOF;

   {  /* Update File Size */
      FSAL_Status ret;      
      if ((ret = FSAL_Direct_GetFileSize(pstMp4Parser->pstFSALAudio, &(pstMp4Parser->pstFSALAudio->uFileSize))) != FSAL_OK)
         return MP4_PARSER_READ_EOF;
   }
            
   if ((ret=MP4_GetSampleSize(pstMp4Parser, pstMp4Parser->uAudioReadSampleNo, &uCurSampleSize, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;
   uCurSampleOffset = pstMp4Parser->uAudioReadSampleOffset;
   uFileOffset = pstMp4Parser->uAudioReadSampleFileOffset;
   if (KAL_TRUE == pstMp4Parser->bAddADIFFrameHeader) {
      /* handle the case if the ADTS frame header has not been read out completely */
      if (pstMp4Parser->uADIFHeaderReadOffset < pstMp4Parser->uADIFFrameHeaderLen) {
         kal_uint32 uADIFFrameSizeLeft = pstMp4Parser->uADIFFrameHeaderLen - pstMp4Parser->uADIFHeaderReadOffset;
         if (uADIFFrameSizeLeft >= uSizeLeft) {
            kal_mem_cpy(pBuf, pbADIFFrameHeader + pstMp4Parser->uADIFHeaderReadOffset, uSizeLeft);
            pstMp4Parser->uADIFHeaderReadOffset += uSizeLeft;
            MP4_AUDIO_READ_UPDATE(uSizeLeft);
            return MP4_PARSER_OK;
         } else {
            kal_mem_cpy(pBuf, pbADIFFrameHeader + pstMp4Parser->uADIFHeaderReadOffset, uADIFFrameSizeLeft);
            pstMp4Parser->uADIFHeaderReadOffset = pstMp4Parser->uADIFFrameHeaderLen;
            MP4_AUDIO_READ_UPDATE(uADIFFrameSizeLeft);
         }
      }
   }

   if (KAL_TRUE == pstMp4Parser->bAddADTSFrameHeader) {
      /* handle the case if the ADTS frame header has been read partially */
      if (pstMp4Parser->uADTSHeaderReadOffset < ADTS_HEADER_SIZE) {
         kal_uint32 uADTSFrameSizeLeft = ADTS_HEADER_SIZE - pstMp4Parser->uADTSHeaderReadOffset;
         prepareADTSFrameHeader(pstMp4Parser, pbADTSFrameHeader, uCurSampleSize);
         if (uADTSFrameSizeLeft >= uSizeLeft) {
            kal_mem_cpy(pBuf, pbADTSFrameHeader + pstMp4Parser->uADTSHeaderReadOffset, uSizeLeft);
            pstMp4Parser->uADTSHeaderReadOffset += uSizeLeft;
            MP4_AUDIO_READ_UPDATE(uSizeLeft);
            return MP4_PARSER_OK;
         } else {
            kal_mem_cpy(pBuf, pbADTSFrameHeader + pstMp4Parser->uADTSHeaderReadOffset, uADTSFrameSizeLeft);
            pstMp4Parser->uADTSHeaderReadOffset = ADTS_HEADER_SIZE;
            MP4_AUDIO_READ_UPDATE(uADTSFrameSizeLeft);
         }
      }       
   }

   /* handle the case if the current sample has been read partially */
   if (pstMp4Parser->uAudioReadSampleOffset!=0) {
      kal_uint32 uCurSampleSizeLeft = uCurSampleSize - uCurSampleOffset;
      uFileOffset += pstMp4Parser->uAudioReadSampleOffset;
      if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSALAudio, uFileOffset))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;
      if (uCurSampleSizeLeft > uSizeLeft) {
         {

            if(pstMp4Parser->pstFSALAudio->uFileSize < (uFileOffset+uSizeLeft))
               return MP4_PARSER_READ_EOF;
         }
         if ((pstMp4Parser->eFSALErr=FSAL_Read(pstMp4Parser->pstFSALAudio, pBuf, uSizeLeft))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
         pstMp4Parser->uAudioReadSampleOffset += uSizeLeft;
         MP4_AUDIO_READ_UPDATE(uSizeLeft);
         return MP4_PARSER_OK;
      } else {

         if(pstMp4Parser->pstFSALAudio->uFileSize < (uFileOffset + uCurSampleSizeLeft))
            return MP4_PARSER_READ_EOF;
         if ((pstMp4Parser->eFSALErr=FSAL_Read(pstMp4Parser->pstFSALAudio, pBuf, uCurSampleSizeLeft))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
         MP4_AUDIO_READ_UPDATE(uCurSampleSizeLeft);
         /* read out the current sample, seek to next sample */
         if ((ret=MP4_Audio_Seek_Internal(pstMp4Parser, pstMp4Parser->uAudioReadSampleNo+1))!=MP4_PARSER_OK)
            return ret;
      }
   }
   
   while(uSizeLeft > 0 && pstMp4Parser->uAudioReadSampleNo < uSampleCount) {
      if ((ret=MP4_GetSampleSize(pstMp4Parser, pstMp4Parser->uAudioReadSampleNo, &uCurSampleSize, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
         return ret;
      uFileOffset = pstMp4Parser->uAudioReadSampleFileOffset;
      if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSALAudio, uFileOffset))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;
      if (KAL_TRUE == pstMp4Parser->bAddADTSFrameHeader) {
         if (pstMp4Parser->uADTSHeaderReadOffset < ADTS_HEADER_SIZE) {
            kal_uint32 uADTSFrameSizeLeft = ADTS_HEADER_SIZE - pstMp4Parser->uADTSHeaderReadOffset;
            prepareADTSFrameHeader(pstMp4Parser, pbADTSFrameHeader, uCurSampleSize);
            if (uADTSFrameSizeLeft >= uSizeLeft) {
               kal_mem_cpy(pBuf, pbADTSFrameHeader + pstMp4Parser->uADTSHeaderReadOffset, uSizeLeft);
               pstMp4Parser->uADTSHeaderReadOffset += uSizeLeft;
               MP4_AUDIO_READ_UPDATE(uSizeLeft);
               break;
            } else {
               kal_mem_cpy(pBuf, pbADTSFrameHeader + pstMp4Parser->uADTSHeaderReadOffset, uADTSFrameSizeLeft);
               pstMp4Parser->uADTSHeaderReadOffset = ADTS_HEADER_SIZE;
               MP4_AUDIO_READ_UPDATE(uADTSFrameSizeLeft);
            }
         }
      }
      if (uCurSampleSize > uSizeLeft) {
         {

            if(pstMp4Parser->pstFSALAudio->uFileSize < (uFileOffset+uSizeLeft))
               return MP4_PARSER_READ_EOF;                                     
         }                                                                     
         if((pstMp4Parser->eFSALErr=FSAL_Read(pstMp4Parser->pstFSALAudio, pBuf, uSizeLeft))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
         pstMp4Parser->uAudioReadSampleOffset = uSizeLeft;
         MP4_AUDIO_READ_UPDATE(uSizeLeft);
         break;
      } else {
         {

            if(pstMp4Parser->pstFSALAudio->uFileSize < (uFileOffset+uCurSampleSize))
               return MP4_PARSER_READ_EOF;
         }
         if ((pstMp4Parser->eFSALErr=FSAL_Read(pstMp4Parser->pstFSALAudio, pBuf, uCurSampleSize))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
         MP4_AUDIO_READ_UPDATE(uCurSampleSize);
         if ((ret=MP4_Audio_Seek_Internal(pstMp4Parser, pstMp4Parser->uAudioReadSampleNo+1))!=MP4_PARSER_OK)
            return ret;
      }     
   }

   if (pstMp4Parser->uAudioReadSampleNo >= uSampleCount)
      return MP4_PARSER_READ_EOF;
   else
      return MP4_PARSER_OK;
}

MP4_Parser_Status MP4_Audio_TimeToSampleNo(STMp4Parser *pstMp4Parser, kal_uint64 uMiliSecond, kal_uint32 *puAudioSampleNo )
{
   MP4_Parser_Status ret;
   kal_uint64 uAudioDecodeTime;
   kal_uint32 uAudioTimeScale;
   
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puAudioSampleNo!=NULL);

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;

   uAudioDecodeTime = uMiliSecond * uAudioTimeScale / 1000;   
   if ((ret=MP4_GetSampleNumber(pstMp4Parser, puAudioSampleNo, uAudioDecodeTime, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;
      
   return MP4_PARSER_OK;
}

MP4_Parser_Status MP4_Audio_GetAvailableDur(STMp4Parser *pstMp4Parser, kal_uint32 *puAudioDuration )
{
   MP4_Parser_Status ret;
   kal_uint32 uAudDuration, uAudioSampleNo, uSampleOffset, start_index, end_index, uAudioLastSampleNo;
   kal_uint32 file_size, uAudioTimeScale;
   kal_uint32 *pGetAvaDurCurSampleCnt;

   FSAL_GetFileSize(pstMp4Parser->pstFSAL, &file_size);

   *puAudioDuration = 0;
   pGetAvaDurCurSampleCnt = &pstMp4Parser->stMp4Track[pstMp4Parser->bAudioTrack].uGetAvaDurCurSampleCnt;
// duration in sample count
   if ((ret=MP4_GetMediaDuration(pstMp4Parser, &uAudDuration, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
      return ret;
// duration in ms
   uAudDuration = (kal_uint64)uAudDuration * (kal_uint64)1000 / (kal_uint64)uAudioTimeScale;

   //if ((ret=MP4_Audio_TimeToSampleNo(pstMp4Parser, uAudDuration, &uAudioLastSampleNo))!=MP4_PARSER_OK)
   //   return ret;

   uAudioLastSampleNo = pstMp4Parser->stMp4Track[pstMp4Parser->bAudioTrack].uSampleCount;
   uAudioSampleNo = *pGetAvaDurCurSampleCnt;
   if(uAudioSampleNo > 0)
      uAudioSampleNo -= 1;
   while(1)
   {

	  if ((ret=MP4_GetSampleOffset(pstMp4Parser, uAudioSampleNo, &uSampleOffset, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
         return ret;

	  if((kal_int32)file_size <= (kal_int32)uSampleOffset){
         break;
	  }else{
         if( (uAudioSampleNo+ CHNUK_SAMPLE_NO) < uAudioLastSampleNo )
	         uAudioSampleNo += CHNUK_SAMPLE_NO;
		   else{
		      uAudioSampleNo = uAudioLastSampleNo;
		      break;
		   }
	  }

   }

   start_index = *pGetAvaDurCurSampleCnt;
   end_index = uAudioSampleNo;

// Binary Search
   if(end_index < start_index){
      end_index = start_index;
   }else{
       while ((kal_int32)(end_index-start_index)>1) {
          kal_uint32 middle_index = (start_index + end_index) / 2;
       
          if ((ret=MP4_GetSampleOffset(pstMp4Parser, middle_index, &uSampleOffset, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
             return ret;
          
          kal_prompt_trace(MOD_MED, "file_size: %d\n", file_size);
          kal_prompt_trace(MOD_MED, "uSampleOffset: %d\n", uSampleOffset);
          kal_prompt_trace(MOD_MED, "start_index: %d\n", start_index);
          kal_prompt_trace(MOD_MED, "middle_index: %d\n", middle_index);
          kal_prompt_trace(MOD_MED, "end_index: %d\n", end_index);
          if ((kal_int32)file_size > (kal_int32)uSampleOffset)
             start_index = middle_index;
          else
             end_index = middle_index;
       }
	  if ((end_index > start_index) && (end_index < uAudioLastSampleNo))
	  	end_index = start_index;
   }


   *pGetAvaDurCurSampleCnt = end_index;
   *puAudioDuration = (kal_uint64)end_index * (kal_uint64)uAudDuration / (kal_uint64)uAudioLastSampleNo;
   return MP4_PARSER_OK;
}
//  MP4 Audio Extraction

#define BUF_SIZE 1024

MP4_Aud_Extr_Status write_aac_adts_output(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_Out, 
                  kal_uint32 uStartTime, kal_uint32 uStopTime)
{

	MP4_Aud_Extr_Status  eResult = MP4_AUD_EXTR_OK;
	MP4_Parser_Status ret = MP4_PARSER_OK;
   FSAL_Status eFSALStatus;
	kal_uint32  uStartSampleNo, uLastSampleNo;
	kal_uint32 bitcnt, uCurSample, uSampleCount, uSampleSize, uSampleOffset;
	kal_uint8  *pBuf;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   uStartSampleNo = uStartTime;
   uLastSampleNo = uStopTime;
   if ((ret=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uSampleCount))!=MP4_PARSER_OK)
	   return MP4_AUD_EXTR_PARSE_ERROR;

   pBuf = (kal_uint8*)med_alloc_ext_mem( sizeof(kal_uint8)* BUF_SIZE);
	for(uCurSample=uStartSampleNo; uCurSample<=uLastSampleNo; uCurSample++) {

		/* get the size of the audio sample */
      if (MP4_GetSampleSize(pstMp4Parser, uCurSample, &uSampleSize, MP4_TRACK_AUDIO)!=MP4_PARSER_OK) {
         return MP4_AUD_EXTR_PARSE_ERROR;
      }

		/* locate the offset of the audio sample */
      if (uStartSampleNo == uCurSample) {
     		if (MP4_GetSampleOffset(pstMp4Parser, uCurSample, &uSampleOffset, MP4_TRACK_AUDIO)!=MP4_PARSER_OK)
               return MP4_AUD_EXTR_PARSE_ERROR;
      } else {
    		if (MP4_GetSampleOffset_Next(pstMp4Parser, &uSampleOffset, MP4_TRACK_AUDIO)!=MP4_PARSER_OK)
               return MP4_AUD_EXTR_PARSE_ERROR;
      }

      if (FSAL_Seek(pstMp4Parser->pstFSAL, uSampleOffset)!=FSAL_OK) {
         return MP4_AUD_EXTR_FILE_SEEK_ERROR;
      }

		while(uSampleSize > 0){
	       kal_uint32 uBufSize = uSampleSize;

		   if(uBufSize > BUF_SIZE)
		      uBufSize = BUF_SIZE;
           uSampleSize -= uBufSize;

         if (FSAL_Read(pstMp4Parser->pstFSAL, pBuf, uBufSize)!=FSAL_OK) {
            med_free_ext_mem( (void **) &pBuf );
            return MP4_AUD_EXTR_FILE_READ_ERROR;
		   }
		   eFSALStatus = FSAL_Write(pstFSAL_Out, pBuf, uBufSize);
	      if(FSAL_OK != eFSALStatus){
	         med_free_ext_mem( (void **) &pBuf );
		      return MP4_AUD_EXTR_FILE_WRITE_ERROR;
		   }
		}
	}
	med_free_ext_mem( (void **) &pBuf );
	return eResult;
}

MP4_Aud_Extr_Status write_amr_output(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_Out, 
              kal_uint32 uStartTime, kal_uint32 uStopTime, MP4_Audio_Type eAudioType)
{
   FSAL_Status eFSALStatus;
	kal_uint32  uStartSampleNo, uLastSampleNo;
   MP4_Parser_Status ret;
   kal_uint8  *pBuf;
	unsigned char pAMRHeader[] = "#!AMR\n";
	unsigned char pAMR_WBHeader[] = "#!AMR-WB\n";
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   uStartSampleNo = uStartTime;
   uLastSampleNo = uStopTime;
   
   {
	   kal_uint32 uCurSample;
	   kal_uint32 uSampleCount;
      pBuf = (kal_uint8*)med_alloc_ext_mem( sizeof(kal_uint8)* BUF_SIZE);
	   for(uCurSample=uStartSampleNo; uCurSample<=uLastSampleNo; uCurSample++) {
          kal_uint32 uSampleSize;
	      kal_uint32 uSampleOffset;

		   /* get the size of the audio sample */
		   if ((ret=MP4_GetSampleSize(pstMp4Parser, uCurSample, &uSampleSize, MP4_TRACK_AUDIO))!=MP4_PARSER_OK){
		      med_free_ext_mem( (void **) &pBuf );
		      return MP4_AUD_EXTR_PARSE_ERROR;
		   }

		   /* locate the offset of the audio sample */
		   if (uStartSampleNo == uCurSample) {
      		   if (MP4_GetSampleOffset(pstMp4Parser, uCurSample, &uSampleOffset, MP4_TRACK_AUDIO)!=MP4_PARSER_OK){
      		      med_free_ext_mem( (void **) &pBuf );
                  return MP4_AUD_EXTR_PARSE_ERROR;
               }
		   } else {
      		   if (MP4_GetSampleOffset_Next(pstMp4Parser, &uSampleOffset, MP4_TRACK_AUDIO)!=MP4_PARSER_OK){
      		      med_free_ext_mem( (void **) &pBuf );
                  return MP4_AUD_EXTR_PARSE_ERROR;                  
               }
		   }
         
         if (FSAL_Seek(pstMp4Parser->pstFSAL, uSampleOffset)!=FSAL_OK) {
            med_free_ext_mem( (void **) &pBuf );
            return MP4_AUD_EXTR_FILE_SEEK_ERROR;
		   }

		   while(uSampleSize > 0){
			   kal_uint32 uBufSize = uSampleSize;

			   if(uBufSize > BUF_SIZE)
			      uBufSize = BUF_SIZE;

            uSampleSize -= uBufSize;

		      if (FSAL_Read(pstMp4Parser->pstFSAL, pBuf, uBufSize)!=FSAL_OK) {
		         med_free_ext_mem( (void **) &pBuf );
               return MP4_AUD_EXTR_FILE_READ_ERROR;
			   }
		      eFSALStatus = FSAL_Write(pstFSAL_Out, pBuf, uBufSize);
	         if(FSAL_OK != eFSALStatus){
	            med_free_ext_mem( (void **) &pBuf );
		         return MP4_AUD_EXTR_FILE_WRITE_ERROR;
		      }
		   }
	   }
   }
   med_free_ext_mem( (void **) &pBuf );
   return MP4_AUD_EXTR_OK;
}

MP4_Aud_Extr_Status MP4_ExtrAudio_CheckAudType(STMp4Parser *pstMp4Parser1, STMp4Parser *pstMp4Parser2)
{
   MP4_Audio_Type eAudioType;
   MP4_Parser_Status ret;
   kal_uint32 uAudioTimeScale1;
   kal_uint32 uAudioTimeScale2;

   MP4_PARSER_CHECK_ARG(pstMp4Parser1!=NULL);
   MP4_PARSER_CHECK_ARG(pstMp4Parser2!=NULL);

   eAudioType = MP4_GetAudioType(pstMp4Parser1);
   if(eAudioType != MP4_GetAudioType(pstMp4Parser2))
      return MP4_AUD_EXTR_AUDIO_TYPE_MISMATCH;

   	switch(eAudioType) {
	case MP4_AUDIO_AAC:
        if(pstMp4Parser1->bAudioChannelConfig != pstMp4Parser2->bAudioChannelConfig)
           return MP4_AUD_EXTR_CHANNEL_NUMBER_MISMATCH;
		if ((ret=MP4_GetMediaTimeScale(pstMp4Parser1, &uAudioTimeScale1, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
           return MP4_AUD_EXTR_Get_TIME_SCALE_FAILED;
		if ((ret=MP4_GetMediaTimeScale(pstMp4Parser1, &uAudioTimeScale2, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
           return MP4_AUD_EXTR_Get_TIME_SCALE_FAILED;
        if(uAudioTimeScale1 != uAudioTimeScale2)
		   return MP4_AUD_EXTR_SAMPLE_RATE_MISMATCH;
	case MP4_AUDIO_AMR:
    case MP4_AUDIO_AMR_WB:
		return MP4_AUD_EXTR_AUDIO_TYPE_MATCH;
	default:
       return MP4_AUD_EXTR_AUDIO_TYPE_NOT_SUPPORT;
	}
}

MP4_Aud_Extr_Status MP4_ExtrAudio_GetAudSize(STMp4Parser *pstMp4Parser, kal_uint32 uStartTime, kal_uint32 uStopTime, kal_uint32 *puAudSizeInByte)
{
	MP4_Parser_Status ret;
	kal_uint32  uStartSampleNo, uLastSampleNo;
	kal_uint32  uCurSample, uSampleSize;
    MP4_Audio_Type eAudioType;

	MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
    eAudioType = MP4_GetAudioType(pstMp4Parser);
	*puAudSizeInByte = 0;

	// Get sample number
	{
	   if( (ret = MP4_Audio_TimeToSampleNo(pstMp4Parser, uStartTime, &uStartSampleNo)) != MP4_PARSER_OK)
          return MP4_AUD_EXTR_PARSE_ERROR;
	   if( (ret = MP4_Audio_TimeToSampleNo(pstMp4Parser, uStopTime, &uLastSampleNo)) != MP4_PARSER_OK)
          return MP4_AUD_EXTR_PARSE_ERROR;
	}

	for(uCurSample=uStartSampleNo; uCurSample<=uLastSampleNo; uCurSample++) {

		/* get the size of the audio sample */
      if (MP4_GetSampleSize(pstMp4Parser, uCurSample, &uSampleSize, MP4_TRACK_AUDIO)!=MP4_PARSER_OK) {
         return MP4_AUD_EXTR_PARSE_ERROR;
      }
      *puAudSizeInByte += uSampleSize;
	}

	// Meta data size

	*puAudSizeInByte += 9;

	switch(eAudioType) {
	case MP4_AUDIO_AAC:
		*puAudSizeInByte += ((uLastSampleNo-uStartSampleNo) * 2) + 4 + (pstMp4Parser->uMP4A_FMT_size-8);
		break;
	case MP4_AUDIO_AMR:
    case MP4_AUDIO_AMR_WB:
		*puAudSizeInByte += (uLastSampleNo-uStartSampleNo);
		break;
	default:
       return MP4_AUD_EXTR_AUDIO_TYPE_NOT_SUPPORT;
	}
    return MP4_AUD_EXTR_OK;
}

MP4_Aud_Extr_Status MP4_ExtrAudio_GetAudFrameDur(STMp4Parser *pstMp4Parser, kal_uint32 *puAudFrameDur)
{
   MP4_Audio_Type eAudioType;
   MP4_Aud_Extr_Status ret;
   kal_uint32 uAudioTimeScale;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   eAudioType = MP4_GetAudioType(pstMp4Parser);

	switch(eAudioType) {
	case MP4_AUDIO_AAC:
		if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uAudioTimeScale, MP4_TRACK_AUDIO))!=MP4_PARSER_OK)
           return MP4_AUD_EXTR_Get_TIME_SCALE_FAILED;
        *puAudFrameDur = 1000 * 1024 / uAudioTimeScale ;
		break;
	case MP4_AUDIO_AMR:
    case MP4_AUDIO_AMR_WB:
        *puAudFrameDur = 20;
		break;
	default:
       return MP4_AUD_EXTR_AUDIO_TYPE_NOT_SUPPORT;
	}
    return MP4_AUD_EXTR_OK;
}

kal_uint8 bMP4_Extr_FrmPerSample = 0;
MP4_Aud_Extr_Status MP4_ExtrAudio(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_Out, kal_uint32 uStartTime, kal_uint32 uStopTime)
{
   MP4_Audio_Type eAudioType;
   MP4_Aud_Extr_Status ret;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   eAudioType = MP4_GetAudioType(pstMp4Parser);

   if(pstMp4Parser->bFramesPerSample)
      bMP4_Extr_FrmPerSample = pstMp4Parser->bFramesPerSample;
   else
      bMP4_Extr_FrmPerSample = 1;

	switch(eAudioType) {
	case MP4_AUDIO_AAC:
        if(pstMp4Parser->bAudioChannelConfig==0) {
			return MP4_AUD_EXTR_ADIF_NOT_SUPPORT;
		} else {
			ret = write_aac_adts_output( pstMp4Parser, pstFSAL_Out, uStartTime, uStopTime);
		}
		break;
	case MP4_AUDIO_AMR:
    case MP4_AUDIO_AMR_WB:
		ret = write_amr_output( pstMp4Parser, pstFSAL_Out, uStartTime, uStopTime, eAudioType);
		break;
	default:
       return MP4_AUD_EXTR_AUDIO_TYPE_NOT_SUPPORT;
	}

   return ret;
}

MP4_Aud_Extr_Status MP4_ExtrAudio_Append(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_Out, kal_uint32 uStartTime, kal_uint32 uStopTime)
{
   kal_uint32 file_size;
   MP4_Aud_Extr_Status ret;

   FSAL_CacheFlush(pstFSAL_Out);
   FSAL_GetFileSize(pstFSAL_Out, &file_size);

   if (FSAL_Seek(pstFSAL_Out, file_size)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   ret = MP4_ExtrAudio(pstMp4Parser, pstFSAL_Out, uStartTime, uStopTime);

   return ret;
}

MP4_Aud_Extr_Status write_amr_silence( STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_Out, kal_uint32 uSilenceFrameCnt )
{
   kal_uint32 cnt;
   FSAL_Status eFSALStatus;
   unsigned char noDataFrame = 0x7C;

   for(cnt=uSilenceFrameCnt; cnt>0; cnt--){
      eFSALStatus = FSAL_Write( pstFSAL_Out, &noDataFrame, 1);
	  if(FSAL_OK != eFSALStatus)
         return MP4_AUD_EXTR_FILE_WRITE_ERROR;
   }

   return MP4_AUD_EXTR_OK;
}

MP4_Aud_Extr_Status write_aac_silence(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_Out, kal_uint32 uSilenceFrameCnt)
{
   kal_uint32 cnt;
   FSAL_Status eFSALStatus;

   unsigned char silenceFram[9] = {0x21, 0x00, 0x49, 0x90, 0x02, 0x19, 0x00, 0x23, 0x80};

   if(pstMp4Parser->bAudioChannelConfig != 2)
	   return MP4_AUD_EXTR_FILL_SILENCE_NOT_SUPPORT;

   for(cnt=uSilenceFrameCnt; cnt>0; cnt--){

      eFSALStatus = FSAL_Write( pstFSAL_Out, (kal_uint8 *)&silenceFram, 9);
	  if(FSAL_OK != eFSALStatus)
         return MP4_AUD_EXTR_FILE_WRITE_ERROR;
   }

   return MP4_AUD_EXTR_OK;
}

MP4_Aud_Extr_Status MP4_ExtrAudio_Append_Silence(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_Out, kal_uint32 uSilenceFrameCnt)
{
   MP4_Audio_Type eAudioType;
   MP4_Aud_Extr_Status ret = MP4_AUD_EXTR_OK;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   eAudioType = MP4_GetAudioType(pstMp4Parser);

	switch(eAudioType) {
	case MP4_AUDIO_AAC:
         ret = write_aac_silence( pstMp4Parser, pstFSAL_Out, uSilenceFrameCnt);
		 break;
	case MP4_AUDIO_AMR:
    case MP4_AUDIO_AMR_WB:
		 ret = write_amr_silence( pstMp4Parser, pstFSAL_Out, uSilenceFrameCnt );
		 break;
	default:
         return MP4_AUD_EXTR_AUDIO_TYPE_NOT_SUPPORT;
	}

   return ret;
}

MP4_Aud_Extr_Status MP4_ExtrAudio_Append_Silence_To_Sample_Data(STFSAL *pstFSAL_AudioSampleDataFile, kal_uint32 uSilenceFrameCnt)
{
   MP4_Audio_Type eAudioType = 0;
   kal_uint32 uFMT_MP4A_Size, uSampleCount, uCnt;
   MP4_Aud_Extr_Status ret = MP4_AUD_EXTR_OK;

   MP4_PARSER_CHECK_ARG(pstFSAL_AudioSampleDataFile!=NULL);
   if (FSAL_Seek(pstFSAL_AudioSampleDataFile, 0)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   if (FSAL_Read_Bytes(pstFSAL_AudioSampleDataFile, (kal_uint8 *)&eAudioType, 1)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_READ_ERROR;

   if (FSAL_Seek(pstFSAL_AudioSampleDataFile, 1)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   if (FSAL_Read_UINT(pstFSAL_AudioSampleDataFile, &uSampleCount)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_READ_ERROR;

   if (FSAL_Seek(pstFSAL_AudioSampleDataFile, 1)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   if(FSAL_Write_UINT(pstFSAL_AudioSampleDataFile, (uSampleCount+uSilenceFrameCnt)) != FSAL_OK)
      return MP4_AUD_EXTR_FILE_WRITE_ERROR;

	switch(eAudioType) {
	case MP4_AUDIO_AAC:
         if (FSAL_Seek(pstFSAL_AudioSampleDataFile, 9)!=FSAL_OK)
		    return MP4_AUD_EXTR_FILE_SEEK_ERROR;

	     if (FSAL_Read_UINT(pstFSAL_AudioSampleDataFile, &uFMT_MP4A_Size)!=FSAL_OK)
	 	    return MP4_AUD_EXTR_FILE_READ_ERROR;

         if (FSAL_Seek(pstFSAL_AudioSampleDataFile, 9 + (uFMT_MP4A_Size-8) + uSampleCount*4)!=FSAL_OK)
		    return MP4_AUD_EXTR_FILE_SEEK_ERROR;

		 for(uCnt=uSilenceFrameCnt; uCnt>0; uCnt--){
	        if(FSAL_Write_UINT(pstFSAL_AudioSampleDataFile, 0x09) != FSAL_OK)
               return MP4_AUD_EXTR_FILE_WRITE_ERROR;
		 }
		 break;
	case MP4_AUDIO_AMR:
    case MP4_AUDIO_AMR_WB:
		 if (FSAL_Seek(pstFSAL_AudioSampleDataFile, 9 + uSampleCount*2)!=FSAL_OK)
	   	   return MP4_AUD_EXTR_FILE_SEEK_ERROR;
		 for(uCnt=uSilenceFrameCnt; uCnt>0; uCnt--){
	        if(FSAL_Write_UINT16(pstFSAL_AudioSampleDataFile, 0x01) != FSAL_OK)
               return MP4_AUD_EXTR_FILE_WRITE_ERROR;
		 }
		 break;
	default:
         return MP4_AUD_EXTR_AUDIO_TYPE_NOT_SUPPORT;
	}

   return ret;
}

MP4_Aud_Extr_Status MP4_ExtrAudio_Merge_Auido_File(STFSAL *pstFSAL_ASDFileDes, STFSAL *pstFSAL_ASDFileSoc)
{
   MP4_Audio_Type eAudioType;
   kal_uint32 file_size;
   FSAL_Status eFSALStatus;
   kal_uint8  *pBuf;
   MP4_Aud_Extr_Status ret = MP4_AUD_EXTR_OK;

   MP4_PARSER_CHECK_ARG(pstFSAL_ASDFileDes!=NULL);
   MP4_PARSER_CHECK_ARG(pstFSAL_ASDFileSoc!=NULL);

   FSAL_CacheFlush(pstFSAL_ASDFileDes);
   FSAL_GetFileSize(pstFSAL_ASDFileDes, &file_size);

   if (FSAL_Seek(pstFSAL_ASDFileDes, file_size)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   FSAL_CacheFlush(pstFSAL_ASDFileSoc);
   FSAL_GetFileSize(pstFSAL_ASDFileSoc, &file_size);

   if (FSAL_Seek(pstFSAL_ASDFileSoc, 0)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   pBuf = (kal_uint8*)med_alloc_ext_mem( sizeof(kal_uint8)* BUF_SIZE);
   while(file_size > 0){
      kal_uint32 uBufSize = file_size;

	  if(uBufSize > BUF_SIZE)
	     uBufSize = BUF_SIZE;

      file_size -= uBufSize;

      if (FSAL_Read(pstFSAL_ASDFileSoc, pBuf, uBufSize)!=FSAL_OK) {
         med_free_ext_mem( (void **) &pBuf );
         return MP4_AUD_EXTR_FILE_READ_ERROR;
	  }
	  eFSALStatus = FSAL_Write(pstFSAL_ASDFileDes, pBuf, uBufSize);
	  if(FSAL_OK != eFSALStatus){
	     med_free_ext_mem( (void **) &pBuf );
        return MP4_AUD_EXTR_FILE_WRITE_ERROR;
     }
   }
   med_free_ext_mem( (void **) &pBuf );
   return ret;
}

MP4_Aud_Extr_Status MP4_ExtrAudio_Merge_Sample_Data(STFSAL *pstFSAL_ASDFileDes, STFSAL *pstFSAL_ASDFileSoc)
{
   MP4_Audio_Type eAudioType;
   kal_uint32 file_size;
   kal_uint32 uSampleCount, uTemp;
   FSAL_Status eFSALStatus;
   kal_uint8  *pBuf;
   MP4_Aud_Extr_Status ret = MP4_AUD_EXTR_OK;

   MP4_PARSER_CHECK_ARG(pstFSAL_ASDFileDes!=NULL);
   MP4_PARSER_CHECK_ARG(pstFSAL_ASDFileSoc!=NULL);
// update sample count
   if (FSAL_Seek(pstFSAL_ASDFileSoc, 1)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   if (FSAL_Read_UINT(pstFSAL_ASDFileSoc, &uTemp)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_READ_ERROR;

   if (FSAL_Seek(pstFSAL_ASDFileDes, 1)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   if (FSAL_Read_UINT(pstFSAL_ASDFileDes, &uSampleCount)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_READ_ERROR;

   if (FSAL_Seek(pstFSAL_ASDFileDes, 1)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   if(FSAL_Write_UINT(pstFSAL_ASDFileDes, (uSampleCount+uTemp)) != FSAL_OK)
      return MP4_AUD_EXTR_FILE_WRITE_ERROR;

   FSAL_CacheFlush(pstFSAL_ASDFileDes);
   FSAL_GetFileSize(pstFSAL_ASDFileDes, &file_size);

   if (FSAL_Seek(pstFSAL_ASDFileDes, file_size)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   FSAL_CacheFlush(pstFSAL_ASDFileSoc);
   FSAL_GetFileSize(pstFSAL_ASDFileSoc, &file_size);

   // seek source to sample size
   // file_size -= sample size offset;

   if (FSAL_Seek(pstFSAL_ASDFileSoc, 0)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   pBuf = (kal_uint8*)med_alloc_ext_mem( sizeof(kal_uint8)* BUF_SIZE);
   while(file_size > 0){
      kal_uint32 uBufSize = file_size;

	  if(uBufSize > BUF_SIZE)
	     uBufSize = BUF_SIZE;

      file_size -= uBufSize;

      if (FSAL_Read(pstFSAL_ASDFileSoc, pBuf, uBufSize)!=FSAL_OK) {
         med_free_ext_mem( (void **) &pBuf );
         return MP4_AUD_EXTR_FILE_READ_ERROR;
	  }
	  eFSALStatus = FSAL_Write(pstFSAL_ASDFileDes, pBuf, uBufSize);
	  if(FSAL_OK != eFSALStatus){
	     med_free_ext_mem( (void **) &pBuf );
        return MP4_AUD_EXTR_FILE_WRITE_ERROR;
     }
   }
   med_free_ext_mem( (void **) &pBuf );
   return ret;
}

// This function is to write audio sample(meta) file for video file merge
MP4_Aud_Extr_Status MP4_ExtrAudio_Write_Sample_Data(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_AudioSampleDataFile, kal_uint32 uStartTime, kal_uint32 uStopTime)
{
   FSAL_Status eFSALRet;
   MP4_Audio_Type eAudioType;
   MP4_Parser_Status eResult;   
   kal_uint32  uStartSampleNo, uLastSampleNo, uSampleCount, uCurSample, uSampleSize;
   kal_uint8  *pBuf;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   uStartSampleNo = uStartTime;
   uLastSampleNo = uStopTime;
   if ((eResult=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uSampleCount))!=MP4_PARSER_OK)
	   return MP4_AUD_EXTR_PARSE_ERROR;

   eAudioType = MP4_GetAudioType(pstMp4Parser);
   ASSERT(eAudioType != MP4_AUDIO_NONE);
   eFSALRet = FSAL_Write_UINT8(pstFSAL_AudioSampleDataFile, eAudioType);
   if(eFSALRet!=FSAL_OK)
   {
	  return MP4_AUD_EXTR_FILE_WRITE_ERROR;
   }

   /* sample count */
   eFSALRet = FSAL_Write_UINT(pstFSAL_AudioSampleDataFile, (uLastSampleNo-uStartSampleNo+1));
   if(eFSALRet!=FSAL_OK)
   {
      return MP4_AUD_EXTR_FILE_WRITE_ERROR;
   }

   /* time scale */
   eFSALRet = FSAL_Write_UINT(pstFSAL_AudioSampleDataFile, pstMp4Parser->stMp4Track[pstMp4Parser->bAudioTrack].uMediaTimeScale);
   if(eFSALRet!=FSAL_OK)
   {
      return MP4_AUD_EXTR_FILE_WRITE_ERROR;
   }

   if(eAudioType == MP4_AUDIO_AAC){
	  kal_uint32 cnt;
	  kal_uint32 uSAMPLE_FMT_MP4A_Size = pstMp4Parser->uMP4A_FMT_size;
	  if (FSAL_Seek(pstMp4Parser->pstFSAL, pstMp4Parser->uMP4A_FMT_offset)!=FSAL_OK) {
              return MP4_AUD_EXTR_FILE_SEEK_ERROR;
	  }
	  // copy SAMPLE_FMT_MP4A
      eFSALRet = FSAL_Write_UINT(pstFSAL_AudioSampleDataFile, uSAMPLE_FMT_MP4A_Size);
      if(eFSALRet!=FSAL_OK)
	  {
         return MP4_AUD_EXTR_FILE_WRITE_ERROR;
	  }
	  uSAMPLE_FMT_MP4A_Size -= 8;
	  pBuf = (kal_uint8*)med_alloc_ext_mem( sizeof(kal_uint8)* BUF_SIZE);
	  while(uSAMPLE_FMT_MP4A_Size > 0){
	     kal_uint32 uBufSize = uSAMPLE_FMT_MP4A_Size;

		 if(uBufSize > BUF_SIZE)
			uBufSize = BUF_SIZE;

         uSAMPLE_FMT_MP4A_Size -= uBufSize;

		 if (FSAL_Read(pstMp4Parser->pstFSAL, pBuf, uBufSize)!=FSAL_OK) {
		    med_free_ext_mem( (void **) &pBuf );
          return MP4_AUD_EXTR_FILE_READ_ERROR;
		 }
		 if(FSAL_Write(pstFSAL_AudioSampleDataFile, pBuf, uBufSize) != FSAL_OK){
		    med_free_ext_mem( (void **) &pBuf );
		    return MP4_AUD_EXTR_FILE_WRITE_ERROR;
		 }
	  }

	for(uCurSample=uStartSampleNo; uCurSample<=uLastSampleNo; uCurSample++) {
		kal_uint16 wFrameSize;
		/* get the size of the audio sample */
      if (MP4_GetSampleSize(pstMp4Parser, uCurSample, &uSampleSize, MP4_TRACK_AUDIO)!=MP4_PARSER_OK) {
         return MP4_AUD_EXTR_PARSE_ERROR;
      }
      wFrameSize = (kal_uint16)uSampleSize;
      eFSALRet = FSAL_Write_UINT16(pstFSAL_AudioSampleDataFile, wFrameSize);
      if(eFSALRet!=FSAL_OK)
      {
         return MP4_AUD_EXTR_FILE_WRITE_ERROR;
      }

	}
   }else{
	for(uCurSample=uStartSampleNo; uCurSample<=uLastSampleNo; uCurSample++) {
      kal_uint16 wFrameSize;

		/* get the size of the audio sample */
      if (MP4_GetSampleSize(pstMp4Parser, uCurSample, &uSampleSize, MP4_TRACK_AUDIO)!=MP4_PARSER_OK) {
         return MP4_AUD_EXTR_PARSE_ERROR;
      }
	  wFrameSize = (kal_uint16)(uSampleSize);
      eFSALRet = FSAL_Write_UINT16(pstFSAL_AudioSampleDataFile, wFrameSize);
      if(eFSALRet!=FSAL_OK)
      {
         return MP4_AUD_EXTR_FILE_WRITE_ERROR;
      }
	}

   }
   return MP4_AUD_EXTR_OK;
}

MP4_Aud_Extr_Status MP4_ExtrAudio_Write_Sample_Data_Append(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL_AudioSampleDataFile, kal_uint32 uStartTime, kal_uint32 uStopTime)
{
   FSAL_Status eFSALRet;
   MP4_Audio_Type eAudioType;
   MP4_Parser_Status eResult;
   kal_uint32  uStartSampleNo, uLastSampleNo, uSampleCount, uCurSample, uSampleSize, uTemp;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   uStartSampleNo = uStartTime;
   uLastSampleNo = uStopTime;
   //eAudioType = MP4_GetAudioType(pstMp4Parser);
   //if ((eResult=MP4_GetSampleCount(pstMp4Parser, MP4_TRACK_AUDIO, &uSampleCount))!=MP4_PARSER_OK)
	//   return MP4_AUD_EXTR_PARSE_ERROR;

   uSampleCount = uLastSampleNo - uStartSampleNo + 1;
   if (FSAL_Seek(pstFSAL_AudioSampleDataFile, 1)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   if (FSAL_Read_UINT(pstFSAL_AudioSampleDataFile, &uTemp)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_READ_ERROR;

   if (FSAL_Seek(pstFSAL_AudioSampleDataFile, 1)!=FSAL_OK)
      return MP4_AUD_EXTR_FILE_SEEK_ERROR;

   if(FSAL_Write_UINT(pstFSAL_AudioSampleDataFile, (uSampleCount+uTemp)) != FSAL_OK)
      return MP4_AUD_EXTR_FILE_WRITE_ERROR;

   {
      kal_uint32 file_size;
      FSAL_CacheFlush(pstFSAL_AudioSampleDataFile);
      FSAL_GetFileSize(pstFSAL_AudioSampleDataFile, &file_size);

      if (FSAL_Seek(pstFSAL_AudioSampleDataFile, file_size)!=FSAL_OK)
         return MP4_AUD_EXTR_FILE_SEEK_ERROR;
   }

   if(eAudioType == MP4_AUDIO_AAC){
	  kal_uint32 cnt;
	   for(uCurSample=uStartSampleNo; uCurSample<=uLastSampleNo; uCurSample++) {
		  kal_uint16 wFrameSize;
		/* get the size of the audio sample */
         if (MP4_GetSampleSize(pstMp4Parser, uCurSample, &uSampleSize, MP4_TRACK_AUDIO)!=MP4_PARSER_OK) {
            return MP4_AUD_EXTR_PARSE_ERROR;
		 }
         wFrameSize = (kal_uint16)uSampleSize;
         eFSALRet = FSAL_Write_UINT16(pstFSAL_AudioSampleDataFile, wFrameSize);
         if(eFSALRet!=FSAL_OK)
		 {
            return MP4_AUD_EXTR_FILE_WRITE_ERROR;
		 }

	}
   }else{
	for(uCurSample=uStartSampleNo; uCurSample<=uLastSampleNo; uCurSample++) {
      kal_uint16 wFrameSize;

		/* get the size of the audio sample */
      if (MP4_GetSampleSize(pstMp4Parser, uCurSample, &uSampleSize, MP4_TRACK_AUDIO)!=MP4_PARSER_OK) {
         return MP4_AUD_EXTR_PARSE_ERROR;
      }
	  //bFrameSize = (kal_uint8)(uSampleSize+1);
	  wFrameSize = (kal_uint16)uSampleSize;
      eFSALRet = FSAL_Write_UINT16(pstFSAL_AudioSampleDataFile, wFrameSize);
      if(eFSALRet!=FSAL_OK)
      {
         return MP4_AUD_EXTR_FILE_WRITE_ERROR;
      }
	}

   }
   return MP4_AUD_EXTR_OK;
}