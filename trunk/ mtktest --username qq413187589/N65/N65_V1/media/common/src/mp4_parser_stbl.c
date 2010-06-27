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
 * mp4_parser_stbl.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Parser, sample table related functions.
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


#include "mp4_parser.h"

static MP4_Parser_Status MP4_STTS_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint16 uCount );
static MP4_Parser_Status MP4_STSS_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint32 uCount );

/*******************************************************************************
   Get the track index number with respect to the specified track type.
*******************************************************************************/
static MP4_Parser_Status MP4_GetTrackNoByType(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint8 *pbTrackNo)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(pbTrackNo!=NULL);

   if (MP4_TRACK_AUDIO == eTrackType) {
      *pbTrackNo = pstMp4Parser->bAudioTrack;
   } else if (MP4_TRACK_VIDEO == eTrackType) {
      *pbTrackNo = pstMp4Parser->bVideoTrack;
   } else {
      return MP4_PARSER_NO_SUCH_TRACK;
   }
   /// Note: the initial value of bAudioTrack or bVideoTrack is MP4_RESERVED_TRACK_NO.
   if (MP4_RESERVED_TRACK_NO == *pbTrackNo)
      return MP4_PARSER_NO_SUCH_TRACK;

   return MP4_PARSER_OK;
}



/* --------------------- Media Header related functions --------------------- */

/*******************************************************************************
   Get the media time scale with respect to the specified track type.
*******************************************************************************/
MP4_Parser_Status MP4_GetMediaTimeScale(STMp4Parser *pstMp4Parser, kal_uint32 *puTimeScale, MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puTimeScale!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   *puTimeScale = pstMp4Parser->stMp4Track[bTrackNo].uMediaTimeScale;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the duration with respect to the specified track type.
*******************************************************************************/
MP4_Parser_Status MP4_GetMediaDuration(STMp4Parser *pstMp4Parser, kal_uint32 *puDuration, MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puDuration!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   *puDuration = pstMp4Parser->stMp4Track[bTrackNo].uMediaDuration;

   return MP4_PARSER_OK;
}



/* --------------------- Sample Size Table related functions --------------------- */

/*******************************************************************************
   Get the sample count of the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleCount(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint32 *puSampleCount)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleCount!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   *puSampleCount = pstMp4Parser->stMp4Track[bTrackNo].uSampleCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the sample size of the specified sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleSize(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo,
                                    kal_uint32 *puSampleSize, MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;
   STFSAL *pstFSAL_STSZ;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleSize!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   *puSampleSize = pstMp4Parser->stMp4Track[bTrackNo].uConstantSampleSize;
   pstFSAL_STSZ = pstMp4Parser->stMp4Track[bTrackNo].pstFSAL_STSZ;

   if (*puSampleSize != 0) {
      return MP4_PARSER_OK;
   } else {
      kal_uint32 uOffset;
      MP4_PARSER_ASSERT(uSampleNo<pstMp4Parser->stMp4Track[bTrackNo].uSampleCount);
      uOffset = pstMp4Parser->stMp4Track[bTrackNo].uOffsetSampleSizeTable;
      uOffset += (uSampleNo * 4);
      if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL_STSZ, uOffset))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;
      if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstFSAL_STSZ, puSampleSize))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

      return MP4_PARSER_OK;
   }
}



/* --------------------- Chunk Offset Table related functions --------------------- */

/*******************************************************************************
   Get the number of chunks in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetChunkCount(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint32 *puChunkCount)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puChunkCount!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   *puChunkCount = pstMp4Parser->stMp4Track[bTrackNo].uChunkCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the number of chunks in the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetChunkOffset(STMp4Parser *pstMp4Parser, kal_uint32 uChunkNo,
                                            kal_uint32 *puChunkOffset, MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint32 uOffset;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puChunkOffset!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   MP4_PARSER_ASSERT(uChunkNo<pstMp4Parser->stMp4Track[bTrackNo].uChunkCount);

   uOffset = pstMp4Parser->stMp4Track[bTrackNo].uOffsetChunkOffsetTable;
   uOffset += (uChunkNo * 4);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, puChunkOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   return MP4_PARSER_OK;
}



/* --------------------- Sample To Chunk Table related functions --------------------- */

/*******************************************************************************
   Get the the number of entries in the STSC box of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetSampleToChunkEntryCount(STMp4Parser *pstMp4Parser, MP4_Track_Type type, kal_uint32 *puEntryCount)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puEntryCount!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   *puEntryCount = pstMp4Parser->stMp4Track[bTrackNo].uSampleToChunkEntryCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the index of the first chunk of the specified run in the STSC box
   of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetFirstChunkInRun(STMp4Parser *pstMp4Parser, kal_uint32 uRun,
                                                kal_uint32 *puFirstChunkInRun, MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint32 uOffset;
   kal_uint8 bTrackNo;
   STFSAL *pstFSAL_STCO;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puFirstChunkInRun!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK) {
      return ret;
   }

   MP4_PARSER_ASSERT(uRun<pstMp4Parser->stMp4Track[bTrackNo].uSampleToChunkEntryCount);

   pstFSAL_STCO = pstMp4Parser->stMp4Track[bTrackNo].pstFSAL_STCO;
   if (pstFSAL_STCO == NULL)
      pstFSAL_STCO = pstMp4Parser->pstFSAL;

   uOffset = pstMp4Parser->stMp4Track[bTrackNo].uOffsetSampleToChunkTable;
   uOffset += (uRun * 12);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL_STCO, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstFSAL_STCO, puFirstChunkInRun))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   *puFirstChunkInRun -= 1; /// index from 0

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the number of samples per chunk of the specified run in the STSC box
   of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetSamplePerChunkInRun(STMp4Parser *pstMp4Parser, kal_uint32 uRun,
                                                    kal_uint32 *puSamplePerChunk, MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint32 uOffset;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;
   STFSAL *pstFSAL_STCO;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSamplePerChunk!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   MP4_PARSER_ASSERT(uRun < pCurTrack->uSampleToChunkEntryCount);

   pstFSAL_STCO = pCurTrack->pstFSAL_STCO;
   if (pstFSAL_STCO == NULL)
      pstFSAL_STCO = pstMp4Parser->pstFSAL;

   uOffset = pCurTrack->uOffsetSampleToChunkTable;
   uOffset += (uRun * 12 + 4);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL_STCO, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstFSAL_STCO, puSamplePerChunk))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the number of the chunk and the file offset of the chunk
   where the specified sample resides in.
*******************************************************************************/
static MP4_Parser_Status MP4_GetChunkNoAndOffset(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo,
                                                 kal_uint32 *puSampleInChunk, kal_uint32 *puSampleOffsetChunk,
                                                 MP4_Track_Type eTrackType )
{
   MP4_Parser_Status ret;
   kal_uint32 uSamplePerChunk;
   kal_uint32 uSampleToChunkIndex = 0;
   kal_uint32 uFirstChunk, uLastChunk;
   kal_uint32 uSampleToChunkEntryCount = 0;
   kal_uint32 uSampleSumPrev = 0, uSampleSum = 0;
   STMp4Track *pCurTrack;
   kal_uint8  bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleInChunk!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleOffsetChunk!=NULL);

   if ((ret = MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
       return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if ((ret = MP4_GetSampleToChunkEntryCount(pstMp4Parser, eTrackType, &uSampleToChunkEntryCount))!=MP4_PARSER_OK)
       return ret;

   if (pCurTrack->uSTSCCacheTableEntryCount > 0)
   {  /// STSC cache is enabled. Perform binary search in the cache.
      kal_uint16 start_index, end_index;
      STSC_Cache_Entry *stsc_cache_table;

      stsc_cache_table = pCurTrack->pSTSCCacheTable;
      start_index = 0;
      end_index = pCurTrack->uSTSCCacheTableEntryCount-1;
      while ((end_index-start_index)>1)
      {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if( uSampleNo > stsc_cache_table[middle_index].accumulated_sample_count )
            start_index = middle_index;
         else
            end_index = middle_index;
      }

      if (start_index)
      {
         uSampleToChunkIndex=end_index * pCurTrack->uSTSCCacheTableStepSize;
         uSampleSum = stsc_cache_table[start_index].accumulated_sample_count;
         uSampleSumPrev = uSampleSum;
      }
   }

   for (; uSampleToChunkIndex<uSampleToChunkEntryCount; uSampleToChunkIndex++) {
      if ((ret = MP4_GetSamplePerChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uSamplePerChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if (uSampleToChunkIndex == uSampleToChunkEntryCount-1) {
         if ((ret = MP4_GetChunkCount(pstMp4Parser, eTrackType, &uLastChunk))!=MP4_PARSER_OK)
            return ret;
         uLastChunk--;
      } else {
         if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex+1, &uLastChunk, eTrackType))!=MP4_PARSER_OK)
            return ret;
         uLastChunk--;
      }
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uFirstChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uSampleSum += (uLastChunk - uFirstChunk + 1)*uSamplePerChunk;
      if (uSampleNo<=uSampleSum) {
         *puSampleInChunk = (uSampleNo - uSampleSumPrev) / uSamplePerChunk + uFirstChunk;
         *puSampleOffsetChunk = (uSampleNo - uSampleSumPrev) % uSamplePerChunk;

         pCurTrack->uSampleToChunkIndex = uSampleToChunkIndex;
         pCurTrack->uSamplePerChunk     = uSamplePerChunk;
         pCurTrack->uFirstChunk         = uFirstChunk;
         pCurTrack->uSampleSum          = uSampleSum;
         pCurTrack->uSampleSumPrev      = uSampleSumPrev;

         return MP4_PARSER_OK;
      }
      uSampleSumPrev = uSampleSum;
   }
   return MP4_PARSER_INTERNAL_ERROR;
}

static MP4_Parser_Status MP4_GetChunkNoAndOffset_Next(STMp4Parser *pstMp4Parser, kal_uint32 *uSampleInChunk, kal_uint32 *uSampleOffsetChunk, MP4_Track_Type type)
{
   kal_uint32 uSampleToChunkIndex, uSampleNo;
   kal_uint32 uFirstChunk, uLastChunk;
   kal_uint32 uSampleToChunkEntryCount;
   kal_uint32 uSamplePerChunk;
   kal_uint32 uSampleSum, uSampleSumPrev;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;
   kal_uint8  bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(uSampleInChunk!=NULL);
   MP4_PARSER_CHECK_ARG(uSampleOffsetChunk!=NULL);

   if ((ret = MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
       return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   uSampleNo                = pCurTrack->uCurSampleNo;
   uSampleToChunkEntryCount = pCurTrack->uSampleToChunkEntryCount;
   uSampleToChunkIndex      = pCurTrack->uSampleToChunkIndex;
   uSampleSum               = pCurTrack->uSampleSum;
   uSampleSumPrev           = pCurTrack->uSampleSumPrev;
   uSamplePerChunk          = pCurTrack->uSamplePerChunk;
   uFirstChunk              = pCurTrack->uFirstChunk;

   if (uSampleNo<uSampleSum) {
      *uSampleInChunk = (uSampleNo - uSampleSumPrev) / uSamplePerChunk + uFirstChunk;
      *uSampleOffsetChunk = (uSampleNo - uSampleSumPrev) % uSamplePerChunk;
      return MP4_PARSER_OK;
   }

   uSampleSumPrev = uSampleSum;
   uSampleToChunkIndex++;

   if ((ret = MP4_GetSamplePerChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uSamplePerChunk, type))!=MP4_PARSER_OK) {
      return ret;
   }

   if (uSampleToChunkIndex == uSampleToChunkEntryCount-1) {
      if ((ret = MP4_GetChunkCount(pstMp4Parser, type, &uLastChunk))!=MP4_PARSER_OK) {
         return ret;
      }
      uLastChunk--;
   } else {
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex+1, &uLastChunk, type))!=MP4_PARSER_OK) {
         return ret;
      }
      uLastChunk--;
   }

   if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uFirstChunk, type))!=MP4_PARSER_OK) {
      return ret;
   }

   uSampleSum += (uLastChunk - uFirstChunk + 1)*uSamplePerChunk;

   *uSampleInChunk = (uSampleNo - uSampleSumPrev) / uSamplePerChunk + uFirstChunk;
   *uSampleOffsetChunk = (uSampleNo - uSampleSumPrev) % uSamplePerChunk;
   
   pCurTrack->uSampleToChunkIndex = uSampleToChunkIndex;
   pCurTrack->uSamplePerChunk     = uSamplePerChunk;
   pCurTrack->uFirstChunk         = uFirstChunk;
   pCurTrack->uSampleSum          = uSampleSum;
   pCurTrack->uSampleSumPrev      = uSampleSumPrev;
   
   return MP4_PARSER_OK;
}

static MP4_Parser_Status MP4_GetChunkNoAndOffset_Previous(STMp4Parser *pstMp4Parser, kal_uint32 *uSampleInChunk, kal_uint32 *uSampleOffsetChunk, MP4_Track_Type type)
{
   kal_uint32 uSampleToChunkIndex, uSampleNo;
   kal_uint32 uFirstChunk, uLastChunk;
   kal_uint32 uSampleToChunkEntryCount;
   kal_uint32 uSamplePerChunk;
   kal_uint32 uSampleSum, uSampleSumPrev;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;
   kal_uint8  bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(uSampleInChunk!=NULL);
   MP4_PARSER_CHECK_ARG(uSampleOffsetChunk!=NULL);

   if ((ret = MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
       return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   uSampleNo                = pCurTrack->uCurSampleNo;
   uSampleToChunkEntryCount = pCurTrack->uSampleToChunkEntryCount;
   uSampleToChunkIndex      = pCurTrack->uSampleToChunkIndex;
   uSampleSum               = pCurTrack->uSampleSum;
   uSampleSumPrev           = pCurTrack->uSampleSumPrev;
   uSamplePerChunk          = pCurTrack->uSamplePerChunk;
   uFirstChunk              = pCurTrack->uFirstChunk;

   if (uSampleNo > uSampleSumPrev) {
      *uSampleInChunk = (uSampleNo - uSampleSumPrev) / uSamplePerChunk + uFirstChunk;
      *uSampleOffsetChunk = (uSampleNo - uSampleSumPrev) % uSamplePerChunk;
      return MP4_PARSER_OK;
   }

   uSampleSum = uSampleSumPrev;
   uSampleToChunkIndex--;
   if ((ret = MP4_GetSamplePerChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uSamplePerChunk, type))!=MP4_PARSER_OK) {
      return ret;
   }

   if (uSampleToChunkIndex == uSampleToChunkEntryCount-1) {
      if ((ret = MP4_GetChunkCount(pstMp4Parser, type, &uLastChunk))!=MP4_PARSER_OK) {
         return ret;
      }
      uLastChunk--;
   } else {
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex+1, &uLastChunk, type))!=MP4_PARSER_OK) {
         return ret;
      }
      uLastChunk--;
   }

   if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uFirstChunk, type))!=MP4_PARSER_OK) {
      return ret;
   }

   uSampleSumPrev -= (uLastChunk - uFirstChunk + 1)*uSamplePerChunk;

   *uSampleInChunk = (uSampleNo - uSampleSumPrev) / uSamplePerChunk + uFirstChunk;
   *uSampleOffsetChunk = (uSampleNo - uSampleSumPrev) % uSamplePerChunk;
   
   pCurTrack->uSampleToChunkIndex = uSampleToChunkIndex;
   pCurTrack->uSamplePerChunk     = uSamplePerChunk;
   pCurTrack->uFirstChunk         = uFirstChunk;
   pCurTrack->uSampleSum          = uSampleSum;
   pCurTrack->uSampleSumPrev      = uSampleSumPrev;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the file offset of the specified sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleOffset(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint32 *puSampleOffset, MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;
   kal_uint8  bTrackNo;
   kal_uint32 uSampleInChunk, uSampleOffsetChunk;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleOffset!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   /// locate the chuck of the sample
   if ((ret=MP4_GetChunkNoAndOffset(pstMp4Parser, uSampleNo, &uSampleInChunk, &uSampleOffsetChunk, type))!=MP4_PARSER_OK)
      return ret;
   
   /// Check if the single-point cache is valid or not
   if (pCurTrack->uSampleOffset_Cache != 0) {
      if (pCurTrack->uSampleInChunk_Cache == uSampleInChunk) {
         /// Case 1: uSampleNo == uCurSampleNo
         if (uSampleNo == pCurTrack->uCurSampleNo) {
            *puSampleOffset = pCurTrack->uSampleOffset_Cache;
            return MP4_PARSER_OK;
         }

         /// Case 2: uSampleNo > uCurSampleNo, seek forward from current sample
         if (uSampleNo > pCurTrack->uCurSampleNo) {
            kal_uint32 i = uSampleNo - pCurTrack->uCurSampleNo + 1;
            while (--i > 0) {
               if ((ret=MP4_GetSampleOffset_Next(pstMp4Parser, puSampleOffset, type))!=MP4_PARSER_OK)
                  return ret;
            }
            return MP4_PARSER_OK;
         }
      }

      /// Case 3: uSampleNo < uCurSampleNo and (uCurSampleNo - uSampleNo) < uSampleOffsetChunk
      /// In this case, seek backward from current sample
      if ((uSampleNo < pCurTrack->uCurSampleNo) && 
          ((pCurTrack->uCurSampleNo - uSampleNo) < uSampleOffsetChunk)) {
         kal_uint32 i = pCurTrack->uCurSampleNo - uSampleNo + 1;
         while (--i > 0) {
            if ((ret=MP4_GetSampleOffset_Previous(pstMp4Parser, puSampleOffset, type))!=MP4_PARSER_OK)
               return ret;
         }
         return MP4_PARSER_OK;
      }
   }

   {
      /// Case 4: General case, seek forward from the beginning of the chunk
      kal_uint32 j, k;
      kal_uint32 temp_offset;

      if ((ret=MP4_GetChunkOffset(pstMp4Parser, uSampleInChunk, &temp_offset, type))!=MP4_PARSER_OK)
         return ret;

      k = uSampleNo - uSampleOffsetChunk;
      for (j=uSampleOffsetChunk+1; --j>0; ) {
         kal_uint32 uSampleSize;
         if ((ret=MP4_GetSampleSize(pstMp4Parser, k++, &uSampleSize, type))!=MP4_PARSER_OK)
            return ret;
         temp_offset += uSampleSize;
      }
      *puSampleOffset = temp_offset;
      pCurTrack->uCurSampleNo         = uSampleNo;
      pCurTrack->uSampleInChunk_Cache = uSampleInChunk;
      pCurTrack->uSampleOffset_Cache  = temp_offset;
      return MP4_PARSER_OK;
   }
}

/*******************************************************************************
   Get the file offset of the "NEXT" sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleOffset_Next(STMp4Parser *pstMp4Parser, kal_uint32 *puSampleOffset, MP4_Track_Type type)
{
   kal_uint32 uSampleInChunk, uSampleOffsetChunk;
   kal_uint32 uSampleSize;
   MP4_Parser_Status ret;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleOffset!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   pCurTrack->uCurSampleNo++;

   /// locate the chuck of the sample
   if ((ret=MP4_GetChunkNoAndOffset_Next(pstMp4Parser, &uSampleInChunk, &uSampleOffsetChunk, type))!=MP4_PARSER_OK) {
      return ret;
   }

   if (uSampleInChunk == pCurTrack->uSampleInChunk_Cache) {
      if ((ret=MP4_GetSampleSize(pstMp4Parser, pCurTrack->uCurSampleNo - 1, &uSampleSize, type))!=MP4_PARSER_OK) {
         return ret;
      }
      *puSampleOffset = pCurTrack->uSampleOffset_Cache + uSampleSize;
   } else {
      if ((ret=MP4_GetChunkOffset(pstMp4Parser, uSampleInChunk, puSampleOffset, type))!=MP4_PARSER_OK) {
      	 return ret;
      }
      pCurTrack->uSampleInChunk_Cache = uSampleInChunk;
   }

   pCurTrack->uSampleOffset_Cache = *puSampleOffset;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the file offset of the "PREVIOUS" sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleOffset_Previous(STMp4Parser *pstMp4Parser, kal_uint32 *puSampleOffset, MP4_Track_Type type)
{
   kal_uint32 uSampleInChunk, uSampleOffsetChunk;
   kal_uint32 uSampleSize;
   MP4_Parser_Status ret;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleOffset!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   pCurTrack->uCurSampleNo--;

   /// locate the chuck of the sample
   if ((ret=MP4_GetChunkNoAndOffset_Previous(pstMp4Parser, &uSampleInChunk, &uSampleOffsetChunk, type))!=MP4_PARSER_OK) {
      return ret;
   }

   if (uSampleInChunk == pCurTrack->uSampleInChunk_Cache) {
      /// Get the size of current sample
      if ((ret=MP4_GetSampleSize(pstMp4Parser, pCurTrack->uCurSampleNo, &uSampleSize, type))!=MP4_PARSER_OK) {
         return ret;
      }
      *puSampleOffset = pCurTrack->uSampleOffset_Cache - uSampleSize;
   } else {
      kal_uint32 temp_offset, k, j;
      if ((ret=MP4_GetChunkOffset(pstMp4Parser, uSampleInChunk, &temp_offset, type))!=MP4_PARSER_OK) {
      	 return ret;
      }
      k = pCurTrack->uCurSampleNo - uSampleOffsetChunk;
      for (j=uSampleOffsetChunk+1; --j>0; ) {
         kal_uint32 uSampleSize;
         if ((ret=MP4_GetSampleSize(pstMp4Parser, k++, &uSampleSize, type))!=MP4_PARSER_OK)
            return ret;
         temp_offset += uSampleSize;
      }
      *puSampleOffset = temp_offset;
      pCurTrack->uSampleInChunk_Cache = uSampleInChunk;
   }
   pCurTrack->uSampleOffset_Cache = *puSampleOffset;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the file offsets of certain number of consecutive sample in the
   specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleOffset_Array(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint32 *puSampleOffsetArray, kal_uint32 *pArraySize, MP4_Track_Type eTrackType)
{
   kal_uint32 uIndex;
   MP4_Parser_Status ret;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleOffsetArray!=NULL);
   MP4_PARSER_CHECK_ARG(pArraySize!=0);

   if ((ret=MP4_GetSampleOffset(pstMp4Parser, uSampleNo, &(puSampleOffsetArray[0]) , eTrackType))!=MP4_PARSER_OK){
      *pArraySize = 0;
      return ret;
   }

   for (uIndex=1; uIndex<*pArraySize; uIndex++) {
      if ((ret=MP4_GetSampleOffset_Next(pstMp4Parser, &(puSampleOffsetArray[uIndex]) , eTrackType))!=MP4_PARSER_OK)
      {
         *pArraySize = uIndex;
         return ret;
      }
   }

   return MP4_PARSER_OK;
}



/* --------------------- Decoding Time to Sample Table related functions --------------------- */

/*******************************************************************************
   Get the sample count of sample delta of the specified index in the STTS table
   of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetSampleCountAndDelta(STMp4Parser *pstMp4Parser, kal_uint32 uIndex,
                                                    kal_uint32 *puSampleCount, kal_uint32 *puSampleDelta,
                                                    MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint32 uOffset;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleCount!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleDelta!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   MP4_PARSER_ASSERT(uIndex < pstMp4Parser->stMp4Track[bTrackNo].uTimeToSampleTableEntryCount);

   uOffset = pstMp4Parser->stMp4Track[bTrackNo].uOffsetTimeToSampleTable;
   uOffset += (uIndex * 8);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, puSampleCount))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, puSampleDelta))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   /// trick: use the average sample duration instead if the recorded one is negative.
   if (*puSampleDelta & 0x80000000) {
      *puSampleDelta = pstMp4Parser->stMp4Track[bTrackNo].uMediaDuration / pstMp4Parser->stMp4Track[bTrackNo].uSampleCount;
   }

   /// to prevent from divided by zero
   if (*puSampleDelta == 0) {
      *puSampleDelta = 1;
   }

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the decode time delta of the specified sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetDecodeTimeDelta(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo,
                                         kal_uint64 *puDecodeTimeDelta, MP4_Track_Type eTrackType)
{
   kal_uint32 uDecodeTimeToSampleTableSize;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   kal_uint32 uCurSampleCount = 0;
   kal_uint32 uIndex = 0;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puDecodeTimeDelta!=NULL);

   *puDecodeTimeDelta = 0;

   if ((ret=MP4_GetSampleCount(pstMp4Parser, eTrackType, &uThisSampleCount))!=MP4_PARSER_OK)
      return ret;

   if (uSampleNo >= uThisSampleCount)
      return MP4_PARSER_NO_SUCH_SAMPLE;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if (pCurTrack->uSTTSCacheTableEntryCount > 0) {
      kal_uint16 start_index, end_index;
      STTS_Cache_Entry *stts_cache_table;

      stts_cache_table = pCurTrack->pSTTSCacheTable;

      do { /// Initial Cache
         MP4_STTS_ProcCacheTableByTrack(pstMp4Parser, eTrackType, 32 );
      }
      while (pCurTrack->uSTTSCacheIndex != pCurTrack->uSTTSCacheTableEntryCount &&
          uSampleNo > stts_cache_table[pCurTrack->uSTTSCacheIndex-1].accumulated_sample_count);

      start_index = 0;
      end_index = pCurTrack->uSTTSCacheIndex-1;
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if (uSampleNo > stts_cache_table[middle_index].accumulated_sample_count)
            start_index = middle_index;
         else
            end_index = middle_index;
      }
      if (start_index) {
         uIndex = end_index * pCurTrack->uSTTSCacheTableStepSize;
         uCurSampleCount = stts_cache_table[start_index].accumulated_sample_count;
      }
   }

   uDecodeTimeToSampleTableSize = pCurTrack->uTimeToSampleTableEntryCount;

   for (; uIndex<uDecodeTimeToSampleTableSize; uIndex++) {
      if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurSampleCount += uThisSampleCount;
      if (uCurSampleCount > uSampleNo) {
         pCurTrack->uDecodeTimeDelta_SampleNo        = uSampleNo;
         pCurTrack->uDecodeTimeDelta_ThisSampleDelta = uThisSampleDelta;
         pCurTrack->uDecodeTimeDelta_CurSampleCount  = uCurSampleCount;
         pCurTrack->uDecodeTimeDelta_TableIndex      = uIndex;
         *puDecodeTimeDelta = uThisSampleDelta;
         break;
      }
   }
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the decode time delta of the "NEXT" sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetDecodeTimeDelta_Next(STMp4Parser *pstMp4Parser, kal_uint64 *puDecodeTimeDelta,
                                              MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint32 uSampleNo;
   kal_uint32 uDecodeTimeToSampleTableSize;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puDecodeTimeDelta!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   pCurTrack->uDecodeTimeDelta_SampleNo++;
   uSampleNo = pCurTrack->uDecodeTimeDelta_SampleNo;

   if (uSampleNo < pCurTrack->uDecodeTimeDelta_CurSampleCount) {
      *puDecodeTimeDelta = pCurTrack->uDecodeTimeDelta_ThisSampleDelta;
      return MP4_PARSER_OK;
   }

   pCurTrack->uDecodeTimeDelta_TableIndex++;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   uDecodeTimeToSampleTableSize = pCurTrack->uTimeToSampleTableEntryCount;

   if (pCurTrack->uDecodeTimeDelta_TableIndex >= uDecodeTimeToSampleTableSize)
      return MP4_PARSER_READ_EOF;

   if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, pCurTrack->uDecodeTimeDelta_TableIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
      return ret;

   *puDecodeTimeDelta = uThisSampleDelta;
   pCurTrack->uDecodeTimeDelta_CurSampleCount += uThisSampleCount;
   pCurTrack->uDecodeTimeDelta_ThisSampleDelta = uThisSampleDelta;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the decode time delta of certain number of consecutive samples in the
   specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetDecodeTimeDelta_Array(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo,
                                               kal_uint64 *puDecodeTimeDeltaArray, kal_uint32 *pArraySize,
                                               MP4_Track_Type eTrackType)
{
   kal_uint32 uIndex;
   MP4_Parser_Status ret;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puDecodeTimeDeltaArray!=NULL);
   MP4_PARSER_CHECK_ARG(pArraySize!=0);

   if ((ret=MP4_GetDecodeTimeDelta(pstMp4Parser, uSampleNo, &(puDecodeTimeDeltaArray[0]) , eTrackType))!=MP4_PARSER_OK)
      return ret;

   for (uIndex=1; uIndex<*pArraySize; uIndex++) {
      if ((ret=MP4_GetDecodeTimeDelta_Next(pstMp4Parser, &(puDecodeTimeDeltaArray[uIndex]) , eTrackType))!=MP4_PARSER_OK)
      {
         *pArraySize = uIndex;
         return ret;
      }
   }

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the sample number with respect to the specified decoding time in the
   specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleNumber(STMp4Parser *pstMp4Parser, kal_uint32 *puSampleNo,
                                      kal_uint64 uDecodeTime, MP4_Track_Type eTrackType)
{
   kal_uint64 uCurDecodeTime = 0;
   kal_uint32 uDecodeTimeToSampleTableSize;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   kal_uint32 uCurSampleCount = 0;
   kal_uint32 uIndex = 0;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSampleNo!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if (pCurTrack->uSTTSCacheTableEntryCount > 0) {
      /// STTS cache is enabled. Perform bunary search.
      kal_uint16 start_index, end_index;
      STTS_Cache_Entry *stts_cache_table;

      stts_cache_table = pCurTrack->pSTTSCacheTable;

      do { /// Initial Cache
         MP4_STTS_ProcCacheTableByTrack(pstMp4Parser, eTrackType, 64 );
      }
      while (pCurTrack->uSTTSCacheIndex != pCurTrack->uSTTSCacheTableEntryCount &&
          uDecodeTime > stts_cache_table[pCurTrack->uSTTSCacheIndex-1].accumulated_decode_time);

      start_index = 0;
      end_index = pCurTrack->uSTTSCacheIndex-1;
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if (uDecodeTime > stts_cache_table[middle_index].accumulated_decode_time)
            start_index = middle_index;
         else
            end_index = middle_index;
      }

      if (start_index) {
         uIndex = end_index * pCurTrack->uSTTSCacheTableStepSize;
         uCurSampleCount = stts_cache_table[start_index].accumulated_sample_count;
         uCurDecodeTime = stts_cache_table[start_index].accumulated_decode_time;
      }
   }

   uDecodeTimeToSampleTableSize = pCurTrack->uTimeToSampleTableEntryCount;

   for (; uIndex<uDecodeTimeToSampleTableSize; uIndex++) {
      if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurDecodeTime += (kal_uint64)uThisSampleCount * (kal_uint64)uThisSampleDelta;
      uCurSampleCount += uThisSampleCount;
      if (uCurDecodeTime >= uDecodeTime) {
         *puSampleNo = uCurSampleCount - (uCurDecodeTime-uDecodeTime+uThisSampleDelta-1)/uThisSampleDelta;
         return MP4_PARSER_OK;
      }
   }

   return MP4_PARSER_NO_SUCH_SAMPLE;
}

/*******************************************************************************
   Get the decode time with respect to the specified sample number in the
   specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetDecodeTime(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo,
                                    kal_uint64 *puDecodeTime, MP4_Track_Type eTrackType )
{
   kal_uint32 uDecodeTimeToSampleTableSize;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta = 0;
   kal_uint32 uCurSampleCount = 0;
   kal_uint32 uIndex = 0;
   kal_uint8 bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puDecodeTime!=NULL);

   *puDecodeTime = 0;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if (pCurTrack->uSTTSCacheTableEntryCount > 0) {
      /// STTS cache is enabled. Perform binary search.
      kal_uint16 start_index, end_index;
      STTS_Cache_Entry *stts_cache_table;

      stts_cache_table = pCurTrack->pSTTSCacheTable;

      do { /// Initial Cache
         MP4_STTS_ProcCacheTableByTrack(pstMp4Parser, eTrackType, 32 );
      }
      while (pCurTrack->uSTTSCacheIndex != pCurTrack->uSTTSCacheTableEntryCount &&
          uSampleNo > stts_cache_table[pCurTrack->uSTTSCacheIndex-1].accumulated_sample_count);

      start_index = 0;
      end_index = pCurTrack->uSTTSCacheIndex-1;
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if (uSampleNo > stts_cache_table[middle_index].accumulated_sample_count)
            start_index = middle_index;
         else
            end_index = middle_index;
      }

      if (start_index) {
         uIndex = end_index * pCurTrack->uSTTSCacheTableStepSize;
         uCurSampleCount = stts_cache_table[start_index].accumulated_sample_count;
         *puDecodeTime = stts_cache_table[start_index].accumulated_decode_time;
      }
   }

   uDecodeTimeToSampleTableSize = pCurTrack->uTimeToSampleTableEntryCount;

   for (; uIndex<uDecodeTimeToSampleTableSize; uIndex++) {
      if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurSampleCount += uThisSampleCount;
      if (uCurSampleCount > uSampleNo) {
         *puDecodeTime += (kal_uint64)uThisSampleDelta * (kal_uint64)(uSampleNo - uCurSampleCount + uThisSampleCount );
         break;
      } else {
         *puDecodeTime += (kal_uint64)uThisSampleDelta * (kal_uint64)uThisSampleCount;
      }
   }

   /// if the decode time of the specified sample is 0, it is an error case.
   if (uSampleNo != 0 && *puDecodeTime == pCurTrack->uDecodeTime_PrevDecodeTime
       && uSampleNo != pCurTrack->uDecodeTime_SampleNo)
      return MP4_PARSER_PARSE_ERROR;

   pCurTrack->uDecodeTime_SampleNo        = uSampleNo;
   pCurTrack->uDecodeTime_TableIndex      = uIndex;
   pCurTrack->uDecodeTime_PrevDecodeTime  = *puDecodeTime;
   pCurTrack->uDecodeTime_ThisSampleDelta = uThisSampleDelta;
   pCurTrack->uDecodeTime_CurSampleCount  = uCurSampleCount;
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the decode time of the "NEXT" sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetDecodeTime_Next(STMp4Parser *pstMp4Parser, kal_uint64 *puDecodeTime,
                                         MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint32 uSampleNo;
   kal_uint32 uDecodeTimeToSampleTableSize;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puDecodeTime!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   uSampleNo = pCurTrack->uDecodeTime_SampleNo;
   pCurTrack->uDecodeTime_SampleNo++;

   if (uSampleNo < pCurTrack->uDecodeTime_CurSampleCount) {
      pCurTrack->uDecodeTime_PrevDecodeTime += pCurTrack->uDecodeTime_ThisSampleDelta;
      *puDecodeTime = pCurTrack->uDecodeTime_PrevDecodeTime;
      return MP4_PARSER_OK;
   }

   pCurTrack->uDecodeTime_TableIndex++;
   
   uDecodeTimeToSampleTableSize = pCurTrack->uTimeToSampleTableEntryCount;

   if (pCurTrack->uDecodeTime_TableIndex >= uDecodeTimeToSampleTableSize)
      return MP4_PARSER_READ_EOF;

   if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, pCurTrack->uDecodeTime_TableIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
      return ret;

   pCurTrack->uDecodeTime_PrevDecodeTime += uThisSampleDelta;
   pCurTrack->uDecodeTime_CurSampleCount += uThisSampleCount;
   pCurTrack->uDecodeTime_ThisSampleDelta = uThisSampleDelta;
   *puDecodeTime = pCurTrack->uDecodeTime_PrevDecodeTime;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the decode time of certain number of consecutive samples in the
   specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetDecodeTime_Array(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo,
                                          kal_uint64 *puDecodeTimeArray, kal_uint32 *pArraySize,
                                          MP4_Track_Type eTrackType)
{
   kal_uint32 uIndex;
   MP4_Parser_Status ret;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puDecodeTimeArray!=NULL);
   MP4_PARSER_CHECK_ARG(pArraySize!=0);

   if ((ret=MP4_GetDecodeTime(pstMp4Parser, uSampleNo, &(puDecodeTimeArray[0]) , eTrackType))!=MP4_PARSER_OK)
      return ret;

   for (uIndex=1; uIndex<*pArraySize; uIndex++) {
      if ((ret=MP4_GetDecodeTime_Next(pstMp4Parser, &(puDecodeTimeArray[uIndex]) , eTrackType))!=MP4_PARSER_OK)
      {
         *pArraySize = uIndex;
         return ret;
      }
   }

   return MP4_PARSER_OK;
}



/* --------------------- Sync Sample Box related functions --------------------- */

/*******************************************************************************
   Get the sync sample number with respect to the given index in the sync
   sample table of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetSyncSampleNo(STMp4Parser *pstMp4Parser, kal_uint32 uIndex,
                                             kal_uint32 *puSyncSampleNo, MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint32 uOffset;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puSyncSampleNo!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   MP4_PARSER_ASSERT(uIndex < pstMp4Parser->stMp4Track[bTrackNo].uSyncCount);

   uOffset = pstMp4Parser->stMp4Track[bTrackNo].uOffsetSyncSampleTable;
   uOffset += (uIndex * 4);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, puSyncSampleNo))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   /// Change starting number of index from 1 to 0.
   *puSyncSampleNo -= 1;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the sample number of the previous sync sample of the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetPrevSyncSampleNo(STMp4Parser *pstMp4Parser, kal_uint32 uCurSampleNo,
                                          kal_uint32 *puPrevSyncSampleNo, MP4_Track_Type eTrackType)
{
   kal_uint32 uSyncSampleNo = 0;
   kal_uint32 uStartIndex, uEndIndex;
   kal_uint8 bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(puPrevSyncSampleNo!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   uEndIndex = pCurTrack->uSyncCount;

   /// If the Sync Sample Box is not present, every sample is a random access point.
   if(!pCurTrack->bHasSTSS) {
      *puPrevSyncSampleNo = uCurSampleNo;
      return MP4_PARSER_OK;
   }

   if (uEndIndex==0) {
      *puPrevSyncSampleNo = 0;
      return MP4_PARSER_OK;
   }

   if (pCurTrack->uSTSSCacheTableEntryCount > 0) {
      /// STSS cache is enabled. Perform binary search.
      kal_uint16 start_index, end_index;
      STSS_Cache_Entry *stss_cache_table;

      stss_cache_table = pCurTrack->pSTSSCacheTable;

      do { /// Initial Cache
         MP4_STSS_ProcCacheTableByTrack(pstMp4Parser, eTrackType, 4 );
      }
      while (pCurTrack->uSTSSCacheIndex != pCurTrack->uSTSSCacheTableEntryCount &&
          uCurSampleNo > stss_cache_table[pCurTrack->uSTSSCacheIndex-1].sample_number);

      start_index = 0;
      end_index = pCurTrack->uSTSSCacheIndex-1;
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if (uCurSampleNo > stss_cache_table[middle_index].sample_number)
            start_index = middle_index;
         else
            end_index = middle_index;
      }
      uStartIndex = start_index * pCurTrack->uSTSSCacheTableStepSize;
      uEndIndex = end_index * pCurTrack->uSTSSCacheTableStepSize;
   }
   else {
      uStartIndex = 0;
      uEndIndex --;
   }

   /// Perform binary search
   while ((uEndIndex-uStartIndex)>1) {
      kal_uint32 uMiddleIndex = (uStartIndex+uEndIndex)>>1;
      if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uMiddleIndex, &uSyncSampleNo, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if (uCurSampleNo > uSyncSampleNo)
         uStartIndex = uMiddleIndex;
      else
         uEndIndex = uMiddleIndex;
   }
   if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uStartIndex, puPrevSyncSampleNo, eTrackType))!=MP4_PARSER_OK)
      return ret;
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the audio type of the MP4 parser.
*******************************************************************************/
MP4_Audio_Type MP4_GetAudioType(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   return pstMp4Parser->bAudioType;
}

/*******************************************************************************
   Get the video type of the MP4 parser.
*******************************************************************************/
MP4_Video_Type MP4_GetVideoType(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   return pstMp4Parser->bVideoType;
}

/*******************************************************************************
   Get the offset of MOOV box.
*******************************************************************************/
kal_uint32 MP4_GetMovieHeaderOffset(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   return pstMp4Parser->uMOOVOffset;
}

/*******************************************************************************
   Get the offset of VOS.
*******************************************************************************/
kal_uint32 MP4_Video_GetVOSOffset(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_ASSERT(MP4_VIDEO_MPEG4==MP4_GetVideoType(pstMp4Parser));

   return pstMp4Parser->uVOSOffset;
}

/*******************************************************************************
   Get the size of VOS.
*******************************************************************************/
kal_uint32 MP4_Video_GetVOSSize(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_ASSERT(MP4_VIDEO_MPEG4==MP4_GetVideoType(pstMp4Parser));

   return pstMp4Parser->uVOSSize;
}

/*******************************************************************************
   Set the FSAL interface for STCO box.
*******************************************************************************/
MP4_Parser_Status MP4_SetFSAL_STCO(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, STFSAL *pstFSAL)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(pstFSAL!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   pstMp4Parser->stMp4Track[bTrackNo].pstFSAL_STCO = pstFSAL;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Set the FSAL interface for STSZ box.
*******************************************************************************/
MP4_Parser_Status MP4_SetFSAL_STSZ(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, STFSAL *pstFSAL)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(pstFSAL!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   pstMp4Parser->stMp4Track[bTrackNo].pstFSAL_STSZ = pstFSAL;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Update the sample count. Compare the sample count calculated from STSC and
   stored in STSZ and make the smaller one to be the real sample count.
*******************************************************************************/
MP4_Parser_Status MP4_UpdateSampleCount(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType)
{
   kal_uint32 uSampleToChunkIndex;
   kal_uint32 uFirstChunk, uLastChunk;
   kal_uint32 uSampleToChunkEntryCount;
   kal_uint32 uSampleSum = 0;
   kal_uint32 uSamplePerChunk;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;
   MP4_Parser_Status ret;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if ((ret = MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if (pCurTrack->bSampleCountUpdated)
      return MP4_PARSER_OK;

   if ((ret = MP4_GetSampleToChunkEntryCount(pstMp4Parser, eTrackType, &uSampleToChunkEntryCount))!=MP4_PARSER_OK)
      return ret;

   pCurTrack->uSampleToChunkEntryCount = uSampleToChunkEntryCount;
   uSampleToChunkEntryCount--;
   for (uSampleToChunkIndex=0; uSampleToChunkIndex<uSampleToChunkEntryCount; uSampleToChunkIndex++) {
      if ((ret = MP4_GetSamplePerChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uSamplePerChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex+1, &uLastChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uFirstChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uSampleSum += (uLastChunk - uFirstChunk)*uSamplePerChunk;
   }
   // handle the last entry
   if ((ret = MP4_GetSamplePerChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uSamplePerChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
   if ((ret = MP4_GetChunkCount(pstMp4Parser, eTrackType, &uLastChunk))!=MP4_PARSER_OK)
        return ret;
   if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uFirstChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
   uSampleSum += (uLastChunk - uFirstChunk)*uSamplePerChunk;

   if( pCurTrack->uSampleCount > uSampleSum )
      pCurTrack->uSampleCount = uSampleSum;
   pCurTrack->bSampleCountUpdated = KAL_TRUE;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Initialize the STTS cache of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_STTS_InitCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType,
                                                         STTS_Cache_Entry *pSTTSCacheTable, kal_uint32 uSTTSCacheTableCount,
                                                         kal_uint32 *puSTTSCacheTblCntExist)
{
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   kal_uint32 uIndex = 0;
   kal_uint32 uSTTSEntryCount = 0;
   kal_uint32 uCurSampleCount = 0;
   kal_uint64 uCurDecodeTime = 0;
   kal_uint16 uCacheIndex = 0;
   kal_uint16 uStepSize = 0;
   kal_uint16 uStepCounter = 0;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;

   *puSTTSCacheTblCntExist = 0;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   uSTTSEntryCount = pstMp4Parser->stMp4Track[bTrackNo].uTimeToSampleTableEntryCount;

   if ((0==uSTTSCacheTableCount) || (0==uSTTSEntryCount))
      return MP4_PARSER_OK;

   uStepSize = (uSTTSEntryCount+uSTTSCacheTableCount-1) / uSTTSCacheTableCount;
   /* avoid divide-by-zero */
   if (0 == uStepSize)
      uStepSize = 1;
   uSTTSCacheTableCount = uSTTSEntryCount / uStepSize;

   /// In the initialization, process at most 2048 STTS entries to prevent the response time
   /// from being too long.
   if (uSTTSEntryCount > 4096)
      uSTTSEntryCount = 4096;
   for (uIndex=0; uIndex<uSTTSEntryCount; uIndex++) {
      if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurSampleCount += uThisSampleCount;
      uCurDecodeTime += (kal_uint64)uThisSampleDelta * (kal_uint64)uThisSampleCount;
      uStepCounter++;
      if (uStepCounter == uStepSize) {
         uStepCounter = 0;
         pSTTSCacheTable[uCacheIndex].accumulated_sample_count = uCurSampleCount;
         pSTTSCacheTable[uCacheIndex++].accumulated_decode_time = uCurDecodeTime;
         if( uCacheIndex == uSTTSCacheTableCount )
            break;
      }
   }
   pstMp4Parser->stMp4Track[bTrackNo].uSTTSStepCounter          = uStepCounter;
   pstMp4Parser->stMp4Track[bTrackNo].uSTTSCurSampleCount       = uCurSampleCount;
   pstMp4Parser->stMp4Track[bTrackNo].uSTTSCurDecodeTime        = uCurDecodeTime;
   pstMp4Parser->stMp4Track[bTrackNo].uSTTSCacheIndex           = uCacheIndex;
   pstMp4Parser->stMp4Track[bTrackNo].uSTTSIndex                = uIndex;
   pstMp4Parser->stMp4Track[bTrackNo].pSTTSCacheTable           = pSTTSCacheTable;
   pstMp4Parser->stMp4Track[bTrackNo].uSTTSCacheTableStepSize   = uStepSize;
   pstMp4Parser->stMp4Track[bTrackNo].uSTTSCacheTableEntryCount = uSTTSCacheTableCount;

   *puSTTSCacheTblCntExist = uSTTSCacheTableCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Process certain number of STTS cache of the specified track.
   uCount is the number of STTS entries to be processed.
*******************************************************************************/
static MP4_Parser_Status MP4_STTS_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint16 uCount )
{
   kal_uint32 uIndex, local_counter;
   kal_uint32 uSTTSEntryCount, uSTTSCacheTableCount;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   kal_uint32 uCurSampleCount;
   kal_uint64 uCurDecodeTime;
   kal_uint16 uCacheIndex;
   kal_uint16 uStepSize;
   kal_uint16 uStepCounter;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   STTS_Cache_Entry *pSTTSCacheTable;
   STMp4Track *pCurTrack;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   
   uCacheIndex          = pCurTrack->uSTTSCacheIndex;
   uSTTSCacheTableCount = pCurTrack->uSTTSCacheTableEntryCount;

   if (uSTTSCacheTableCount==0 || uCacheIndex==uSTTSCacheTableCount)
      return MP4_PARSER_OK;

   uSTTSEntryCount      = pCurTrack->uTimeToSampleTableEntryCount;
   uStepCounter         = pCurTrack->uSTTSStepCounter;
   uCurSampleCount      = pCurTrack->uSTTSCurSampleCount;
   uCurDecodeTime       = pCurTrack->uSTTSCurDecodeTime;
   uIndex               = pCurTrack->uSTTSIndex;
   pSTTSCacheTable      = pCurTrack->pSTTSCacheTable;
   uStepSize            = pCurTrack->uSTTSCacheTableStepSize;

   for (local_counter=0; uIndex<uSTTSEntryCount && local_counter<uCount; uIndex++, local_counter++) {
      if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurSampleCount += uThisSampleCount;
      uCurDecodeTime += (kal_uint64)uThisSampleDelta * (kal_uint64)uThisSampleCount;
      uStepCounter++;
      if (uStepCounter == uStepSize) {
         uStepCounter = 0;
         pSTTSCacheTable[uCacheIndex].accumulated_sample_count = uCurSampleCount;
         pSTTSCacheTable[uCacheIndex++].accumulated_decode_time = uCurDecodeTime;
         if( uCacheIndex == uSTTSCacheTableCount )
            break;
      }
   }
   pCurTrack->uSTTSStepCounter             = uStepCounter;
   pCurTrack->uSTTSCurSampleCount          = uCurSampleCount;
   pCurTrack->uSTTSCurDecodeTime           = uCurDecodeTime;
   pCurTrack->uSTTSCacheIndex              = uCacheIndex;
   pCurTrack->uSTTSIndex                   = uIndex;

   return MP4_PARSER_OK;
}

/*******************************************************************************
    Initialize the STTS cache.
*******************************************************************************/
static MP4_Parser_Status MP4_STTS_InitCacheTable(STMp4Parser *pstMp4Parser, kal_uint32 *pSTTSCachePool, kal_uint32 uSTTSCachePoolSize, kal_uint32 *puSTTSCachePoolUsed)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;
   STMp4Track *pAudioTrack, *pVideoTrack;
   const kal_uint16 entry_size = sizeof(STTS_Cache_Entry)/sizeof(kal_uint32);

   *puSTTSCachePoolUsed = 0;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, MP4_TRACK_AUDIO, &bTrackNo))!=MP4_PARSER_OK)
      pAudioTrack = NULL;
   else
      pAudioTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, MP4_TRACK_VIDEO, &bTrackNo))!=MP4_PARSER_OK)
      pVideoTrack = NULL;
   else
      pVideoTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if (pAudioTrack!=NULL && pVideoTrack!=NULL) {
      kal_uint32 audio_cache_size, video_cache_size;
      /// avoid divide by zero
      if ((0==pAudioTrack->uTimeToSampleTableEntryCount) &&
          (0==pVideoTrack->uTimeToSampleTableEntryCount))
         return MP4_PARSER_OK;

      audio_cache_size = (kal_uint32)(((kal_uint64) pAudioTrack->uTimeToSampleTableEntryCount * uSTTSCachePoolSize) / (pAudioTrack->uTimeToSampleTableEntryCount + pVideoTrack->uTimeToSampleTableEntryCount));
      video_cache_size = uSTTSCachePoolSize - audio_cache_size;

      if ((ret = MP4_STTS_InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_VIDEO, (STTS_Cache_Entry *)pSTTSCachePool, video_cache_size/entry_size, &video_cache_size)) != MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_STTS_InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_AUDIO, (STTS_Cache_Entry *)(pSTTSCachePool+(video_cache_size*entry_size)), audio_cache_size/entry_size, &audio_cache_size)) != MP4_PARSER_OK)
         return ret;
      *puSTTSCachePoolUsed = audio_cache_size + video_cache_size;
   }
   else if (pAudioTrack!=NULL) {
      if ((ret = MP4_STTS_InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_AUDIO, (STTS_Cache_Entry *)pSTTSCachePool, uSTTSCachePoolSize/entry_size, puSTTSCachePoolUsed)) != MP4_PARSER_OK)
         return ret;
   }
   else if (pVideoTrack!=NULL) {
      if( (ret = MP4_STTS_InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_VIDEO, (STTS_Cache_Entry *)pSTTSCachePool, uSTTSCachePoolSize/entry_size, puSTTSCachePoolUsed)) != MP4_PARSER_OK )
         return ret;
   }
   *puSTTSCachePoolUsed *= entry_size;
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Process the STSC cache of the specified track.
   STSC cache table will be processed all at once.
*******************************************************************************/
static MP4_Parser_Status MP4_STSC_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, STSC_Cache_Entry *pSTSCCacheTable, kal_uint32 uSTSCCacheTableCount, kal_uint32 *puSTSCCacheTblCntExist)
{
   kal_uint32 uIndex;
   kal_uint32 uSTSCEntryCount;
   kal_uint32 uSamplePerChunk;
   kal_uint32 uCurSampleCount = 0;
   kal_uint32 uFirstChunk, uLastChunk;
   kal_uint16 uCacheIndex = 0;
   kal_uint16 uStepSize = 0;
   kal_uint16 uStepCounter = 0;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;

   *puSTSCCacheTblCntExist = 0;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   uSTSCEntryCount = pstMp4Parser->stMp4Track[bTrackNo].uSampleToChunkEntryCount;

   if ((0 == uSTSCCacheTableCount) || (0 == uSTSCEntryCount))
      return MP4_PARSER_OK;

   uStepSize = (uSTSCEntryCount+uSTSCCacheTableCount-1) / uSTSCCacheTableCount;
   /* avoid divide by zero */
   if (0 == uStepSize)
     uStepSize = 1;
   uSTSCCacheTableCount = uSTSCEntryCount / uStepSize;

   uSTSCEntryCount--;
   for (uIndex=0; uIndex<uSTSCEntryCount; uIndex++) {
      if ((ret=MP4_GetSamplePerChunkInRun(pstMp4Parser, uIndex, &uSamplePerChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uIndex+1, &uLastChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uIndex, &uFirstChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurSampleCount += (uLastChunk - uFirstChunk)*uSamplePerChunk;
      uStepCounter++;
      if (uStepCounter == uStepSize) {
         uStepCounter = 0;
         pSTSCCacheTable[uCacheIndex++].accumulated_sample_count = uCurSampleCount;
      }
   }

   // handle the last one
   if ((ret=MP4_GetSamplePerChunkInRun(pstMp4Parser, uIndex, &uSamplePerChunk, eTrackType))!=MP4_PARSER_OK)
      return ret;
   if ((ret = MP4_GetChunkCount(pstMp4Parser, eTrackType, &uLastChunk))!=MP4_PARSER_OK)
      return ret;
   if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uIndex, &uFirstChunk, eTrackType))!=MP4_PARSER_OK)
      return ret;
   uCurSampleCount += (uLastChunk - uFirstChunk)*uSamplePerChunk;
   uStepCounter++;
   if (uStepCounter == uStepSize) {
      uStepCounter = 0;
      pSTSCCacheTable[uCacheIndex++].accumulated_sample_count = uCurSampleCount;
   }

   pstMp4Parser->stMp4Track[bTrackNo].pSTSCCacheTable           = pSTSCCacheTable;
   pstMp4Parser->stMp4Track[bTrackNo].uSTSCCacheTableStepSize   = uStepSize;
   pstMp4Parser->stMp4Track[bTrackNo].uSTSCCacheTableEntryCount = uSTSCCacheTableCount;

   *puSTSCCacheTblCntExist = uSTSCCacheTableCount;

   if (pstMp4Parser->stMp4Track[bTrackNo].uSampleCount > uCurSampleCount)
      pstMp4Parser->stMp4Track[bTrackNo].uSampleCount = uCurSampleCount;
   pstMp4Parser->stMp4Track[bTrackNo].bSampleCountUpdated = KAL_TRUE;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Initialize the STSC cache.
*******************************************************************************/
static MP4_Parser_Status MP4_STSC_InitCacheTable(STMp4Parser *pstMp4Parser, kal_uint32 *pSTSCCachePool, kal_uint32 uSTSCCachePoolSize, kal_uint32 *puSTSCCachePoolUsed)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;
   STMp4Track *pAudioTrack, *pVideoTrack;
   const kal_uint16 entry_size = sizeof(STSC_Cache_Entry)/sizeof(kal_uint32);

   *puSTSCCachePoolUsed = 0;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, MP4_TRACK_AUDIO, &bTrackNo))!=MP4_PARSER_OK)
      pAudioTrack = NULL;
   else
      pAudioTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, MP4_TRACK_VIDEO, &bTrackNo))!=MP4_PARSER_OK)
      pVideoTrack = NULL;
   else
      pVideoTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if (pAudioTrack!=NULL && pVideoTrack!=NULL) {
      kal_uint32 audio_cache_size, video_cache_size;
      /// avoid divide by zero
      if ((0==pAudioTrack->uSampleToChunkEntryCount) &&
          (0==pVideoTrack->uSampleToChunkEntryCount))
         return MP4_PARSER_OK;

      audio_cache_size = (kal_uint32)(((kal_uint64)pAudioTrack->uSampleToChunkEntryCount * uSTSCCachePoolSize) / (pAudioTrack->uSampleToChunkEntryCount + pVideoTrack->uSampleToChunkEntryCount));
      video_cache_size = uSTSCCachePoolSize - audio_cache_size;
      if ((ret = MP4_STSC_ProcCacheTableByTrack( pstMp4Parser, MP4_TRACK_VIDEO, (STSC_Cache_Entry *)pSTSCCachePool, video_cache_size/entry_size, &video_cache_size)) != MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_STSC_ProcCacheTableByTrack( pstMp4Parser, MP4_TRACK_AUDIO, (STSC_Cache_Entry *)(pSTSCCachePool+(video_cache_size*entry_size)), audio_cache_size/entry_size, &audio_cache_size)) != MP4_PARSER_OK)
         return ret;
      *puSTSCCachePoolUsed = video_cache_size + audio_cache_size;
   }
   else if (pAudioTrack!=NULL) {
      if ((ret = MP4_STSC_ProcCacheTableByTrack( pstMp4Parser, MP4_TRACK_AUDIO, (STSC_Cache_Entry *)pSTSCCachePool, uSTSCCachePoolSize/entry_size, puSTSCCachePoolUsed)) != MP4_PARSER_OK)
         return ret;
   }
   else if (pVideoTrack!=NULL) {
      if ((ret = MP4_STSC_ProcCacheTableByTrack( pstMp4Parser, MP4_TRACK_VIDEO, (STSC_Cache_Entry *)pSTSCCachePool, uSTSCCachePoolSize/entry_size, puSTSCCachePoolUsed)) != MP4_PARSER_OK)
         return ret;
   }
   *puSTSCCachePoolUsed *= entry_size;
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Initialize the STSS cache of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_STSS_InitCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType,
                                                         STSS_Cache_Entry *pSTSSCacheTable, kal_uint32 uSTSSCacheTableCount,
                                                         kal_uint32 *puSTSSCacheTblCntExist)
{
   kal_uint32 uSTSSEntryCount;
   kal_uint32 uIndex;
   kal_uint16 uCacheIndex;
   kal_uint16 uStepSize;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;

   *puSTSSCacheTblCntExist = 0;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   uSTSSEntryCount = pstMp4Parser->stMp4Track[bTrackNo].uSyncCount;

   if ((0==uSTSSCacheTableCount) || (0==uSTSSEntryCount))
      return MP4_PARSER_OK;

   uStepSize = (uSTSSEntryCount+uSTSSCacheTableCount-1) / uSTSSCacheTableCount;
   /* avoid divide by zero */
   if (0 == uStepSize)
      uStepSize = 1;
   uSTSSCacheTableCount = uSTSSEntryCount / uStepSize;

   /// In the initialization, process at most 16 STSS "CACHE" entries to prevent the response time
   /// from being too long.
   uSTSSEntryCount = uSTSSCacheTableCount;   /// Use uSTSSEntryCount as temporary variable
   if (uSTSSEntryCount > 32)
      uSTSSEntryCount = 32;
   for (uCacheIndex=0, uIndex=0; uCacheIndex<uSTSSEntryCount; uCacheIndex++, uIndex+=uStepSize) {
      if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uIndex, &(pSTSSCacheTable[uCacheIndex].sample_number), eTrackType))!=MP4_PARSER_OK)
         return ret;
   }
   pstMp4Parser->stMp4Track[bTrackNo].pSTSSCacheTable             = pSTSSCacheTable;
   pstMp4Parser->stMp4Track[bTrackNo].uSTSSCacheIndex             = uCacheIndex;
   pstMp4Parser->stMp4Track[bTrackNo].uSTSSIndex                  = uIndex;
   pstMp4Parser->stMp4Track[bTrackNo].uSTSSCacheTableStepSize     = uStepSize;
   pstMp4Parser->stMp4Track[bTrackNo].uSTSSCacheTableEntryCount   = uSTSSCacheTableCount;

   *puSTSSCacheTblCntExist = uSTSSCacheTableCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Process certain number of STSS cache of the specified track.
   uCount is the number of STSS "CACHE" entries to be processed.
*******************************************************************************/
static MP4_Parser_Status MP4_STSS_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint32 uCount )
{
   kal_uint32 uIndex, local_counter;
   kal_uint32 uSTSSCacheTableCount;
   kal_uint16 uStepSize;
   kal_uint16 uCacheIndex;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   STSS_Cache_Entry *pSTSSCacheTable;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   uCacheIndex          = pstMp4Parser->stMp4Track[bTrackNo].uSTSSCacheIndex;
   uSTSSCacheTableCount = pstMp4Parser->stMp4Track[bTrackNo].uSTSSCacheTableEntryCount;

   if (uSTSSCacheTableCount==0 || uCacheIndex==uSTSSCacheTableCount)
      return MP4_PARSER_OK;

   uIndex               = pstMp4Parser->stMp4Track[bTrackNo].uSTSSIndex;
   pSTSSCacheTable      = pstMp4Parser->stMp4Track[bTrackNo].pSTSSCacheTable;
   uStepSize            = pstMp4Parser->stMp4Track[bTrackNo].uSTSSCacheTableStepSize;

   for (local_counter=0; uCacheIndex<uSTSSCacheTableCount && local_counter<uCount; uCacheIndex++, uIndex+=uStepSize, local_counter++) {
      if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uIndex, &(pSTSSCacheTable[uCacheIndex].sample_number), eTrackType))!=MP4_PARSER_OK)
         return ret;
   }
   pstMp4Parser->stMp4Track[bTrackNo].uSTSSCacheIndex = uCacheIndex;
   pstMp4Parser->stMp4Track[bTrackNo].uSTSSIndex      = uIndex;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Initialize the STSS cache.
*******************************************************************************/
static MP4_Parser_Status MP4_STSS_InitCacheTable( STMp4Parser *pstMp4Parser, kal_uint32 *pSTSSCachePool,
                                                        kal_uint32 uSTSSCachePoolSize, kal_uint32 *puSTSSCachePoolUsed )
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;
   STMp4Track *pAudioTrack, *pVideoTrack;
   const kal_uint16 entry_size = sizeof(STSS_Cache_Entry)/sizeof(kal_uint32);

   *puSTSSCachePoolUsed = 0;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, MP4_TRACK_AUDIO, &bTrackNo))!=MP4_PARSER_OK)
      pAudioTrack = NULL;
   else
      pAudioTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, MP4_TRACK_VIDEO, &bTrackNo))!=MP4_PARSER_OK)
      pVideoTrack = NULL;
   else
      pVideoTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if (pAudioTrack!=NULL && pVideoTrack!=NULL) {
      kal_uint32 audio_cache_size, video_cache_size;
      /// avoid divide by zero
      if ((0==pAudioTrack->uSyncCount) &&
          (0==pVideoTrack->uSyncCount))
         return MP4_PARSER_OK;

      audio_cache_size = (kal_uint32)(((kal_uint64)pAudioTrack->uSyncCount * uSTSSCachePoolSize) / (pAudioTrack->uSyncCount + pVideoTrack->uSyncCount));
      video_cache_size = uSTSSCachePoolSize - audio_cache_size;
      if ((ret = MP4_STSS_InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_VIDEO, (STSS_Cache_Entry *)pSTSSCachePool, video_cache_size/entry_size, &video_cache_size)) != MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_STSS_InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_AUDIO, (STSS_Cache_Entry *)(pSTSSCachePool+(video_cache_size*entry_size)), audio_cache_size/entry_size, &audio_cache_size)) != MP4_PARSER_OK)
         return ret;
      *puSTSSCachePoolUsed = audio_cache_size + video_cache_size;
   }
   else if (pAudioTrack != NULL) {
      if ((ret = MP4_STSS_InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_AUDIO, (STSS_Cache_Entry *)pSTSSCachePool, uSTSSCachePoolSize/entry_size, puSTSSCachePoolUsed)) != MP4_PARSER_OK)
         return ret;
   }
   else if (pVideoTrack != NULL) {
      if ((ret = MP4_STSS_InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_VIDEO, (STSS_Cache_Entry *)pSTSSCachePool, uSTSSCachePoolSize/entry_size, puSTSSCachePoolUsed)) != MP4_PARSER_OK)
         return ret;
   }
   *puSTSSCachePoolUsed *= entry_size;
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Initialize the STBL cache.
*******************************************************************************/
MP4_Parser_Status MP4_STBL_CacheTablePreprocess(STMp4Parser *pstMp4Parser, kal_uint32 *pCachePool, kal_uint32 uCachePoolSize)
{
   MP4_Parser_Status eMp4ParserRet = MP4_PARSER_OK;
   kal_uint32 uCachePoolUsed = 0;
   kal_uint8 bCacheEnableFlag = 7;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(pCachePool!=NULL);
   MP4_PARSER_CHECK_ARG(uCachePoolSize!=0);

   /* The cache sizes of STTS, STSC and STSS are 4:3:1         */
   /* The order of initialization is STSS, STSC and then STTS  */
   if (bCacheEnableFlag & 1) {
      pCachePool += uCachePoolUsed;
      uCachePoolSize -= uCachePoolUsed;
      eMp4ParserRet = MP4_STSS_InitCacheTable(pstMp4Parser, pCachePool, uCachePoolSize>>3, &uCachePoolUsed);
      if(eMp4ParserRet!=MP4_PARSER_OK )
         return eMp4ParserRet;
   }
   if (bCacheEnableFlag & 2) {
      pCachePool += uCachePoolUsed;
      uCachePoolSize -= uCachePoolUsed;
      eMp4ParserRet = MP4_STSC_InitCacheTable(pstMp4Parser, pCachePool, uCachePoolSize*3/7, &uCachePoolUsed);
      if(eMp4ParserRet!=MP4_PARSER_OK )
         return eMp4ParserRet;
   }
   if (bCacheEnableFlag & 4) {
      pCachePool += uCachePoolUsed;
      uCachePoolSize -= uCachePoolUsed;
      eMp4ParserRet = MP4_STTS_InitCacheTable(pstMp4Parser, pCachePool, uCachePoolSize, &uCachePoolUsed);
      if(eMp4ParserRet!=MP4_PARSER_OK )
         return eMp4ParserRet;
   }
   return eMp4ParserRet;
}


