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
 *   awb_plus_drv.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Driver for AMR-WB and AMR-WB Plus Decoding
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

#if defined(AWB_PLUS_DECODE)

#include "media.h"
#include "fsal.h"
#include "awb_plus_drv.h"
#include "med_utility.h"
#include "l1sp_trc.h"

#define AWB_DEBUG 0
#define CacheAsOriginal 1

extern kal_semid WAVsema;

extern kal_uint32 SaveAndSetIRQMask( void );
extern void RestoreIRQMask( uint32 );

// In bytes
const kal_uint16 awbpFrameSize[48] = {
   17, 23, 32, 36, 40, 46, 50, 58, 60,  5,
   34, 45, 60, 60,  0,  0, 26, 30, 34, 38,
   42, 48, 52, 60, 31, 32, 35, 36, 38, 40,
   41, 43, 45, 46, 48, 50, 51, 53, 56, 58,
   60, 64, 65, 67, 72, 74, 75, 80
};

// in 1/45 ms
const kal_uint16 awbpFrameDuration_ms[14] = {
   80,  160,  142,  128,  120,  106,   96,
   85,   80,   71,   64,   60,   56,   53
};

const kal_uint16 awbpFrameDuration_45thms[14] = {
    0,    0,   10,    0,    0,   30,    0,
   15,    0,    5,    0,    0,   40,   15
};

kal_uint8 *awbpWorking_data = (kal_uint8 *)0;

// 20070530
#if AWB_DEBUG
short awbpDebugBuf[4387];
static kal_wchar awbp_debug_file_name[50];  // file path
STFSAL pDebugFSAL;
#endif


//-------- Utility for Buffer Operation --------

// To fill full the media buffer
static void awbpFillMediaBuffer(MHdl *hdl)
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;
   kal_uint8 *pBuf;
   short *pOutBuf;
   int uFreeSpace, segment;
   short sampleCount;
   
   uFreeSpace = hdl->GetFreeSpace( hdl ); // Len in byte
   
   while ((!hdl->eof) && (uFreeSpace > 2*ihdl->frameSize)) {
      int state;
      unsigned int duration, numBytes;

      state = AWB_ParseFrameData(ihdl->decStruct, ihdl->pstFSAL, hdl, ihdl->isStreaming, &numBytes, &duration);
      ihdl->fileOffset += numBytes;  // the number of byte

      // KH: No data (0) or Error (-1, -4)
      if ( (state == 0) || (state == -1) || (state == -4) ) {
         ihdl->mh.eof = true;
         break;
      } else {
         ihdl->parsedTime += duration;
      }
      
      // Update the cache table
      if (ihdl->AudioCacheTbl != 0) {
         awbpCacheTable *pCacheTable;
         
         pCacheTable = ihdl->AudioCacheTbl;
         if (ihdl->fileOffset > pCacheTable->entryBoundary) {
            uint16 index;
            
            pCacheTable->currentEntryIndex++;
            index = pCacheTable->currentEntryIndex;
            pCacheTable->entryBoundary = ihdl->fileOffset + pCacheTable->sizePerEntry;
            if (pCacheTable->entryBoundary >= ihdl->uFileSize)
               pCacheTable->entryBoundary = ihdl->uFileSize;

            pCacheTable->accumulateTime[index] = ihdl->parsedTime;
            pCacheTable->accumulateOffset[index] = ihdl->fileOffset;
         }
      }

      
#if AWB_DEBUG
      if ( FSAL_Read_Bytes( &pDebugFSAL, (unsigned char *)awbpDebugBuf, 4377*sizeof(short) ) == FSAL_OK ) {
         awbpDebugBuf[4381] = awbpDebugBuf[4376];  // dspQFormat
         awbpDebugBuf[4380] = awbpDebugBuf[4375];  // L_frame
         awbpDebugBuf[4378] = awbpDebugBuf[4374];  // num_channels
         awbpDebugBuf[4377] = 0;                   // Limiter
         awbpDebugBuf[4374] = 1;                   // Extension
         awbpDebugBuf[4375] = 16000;               // Sample Frequency
         awbpDebugBuf[4376] = 0;                   // mono decode stereo
         
         sampleCount = 4387;
      } else {
         sampleCount = -2;
      }
      pOutBuf = awbpDebugBuf;
#else
      pOutBuf = AWB_Decode(ihdl->decStruct, &sampleCount, ihdl->pstFSAL);
#endif

      if (sampleCount == -1) {
         // Error
         ihdl->fDecoderError = true;
         return;
         //return MEDIA_ERROR;
      } else if (sampleCount == -2) {
         // EOF
         ihdl->mh.eof = true;
         return;
      } else {
         kal_uint32 uMBufLen;

         // Normal case
         hdl->GetWriteBuffer(hdl, &pBuf, &uMBufLen);  // uMBufLen in byte
         uMBufLen = uMBufLen & (~0x01);
         sampleCount = sampleCount*sizeof(short);     // Transform in byte
         if (uMBufLen > sampleCount)
            uMBufLen = sampleCount;
         segment = uMBufLen;
         
         // First Stage
         memcpy(pBuf, pOutBuf, segment);
         hdl->WriteDataDone(hdl, uMBufLen);
         pOutBuf += (segment / sizeof(short));
         
         // Second Stage
         segment = sampleCount - uMBufLen;
         if (segment > 0) {
            hdl->GetWriteBuffer(hdl, &pBuf, &uMBufLen);  // uMBufLen in byte
            memcpy(pBuf, pOutBuf, segment);
            hdl->WriteDataDone(hdl, segment);
         }

         uFreeSpace -= sampleCount;
      }
   }
   
   if (ihdl->fileOffset >= ihdl->uFileSize) {
      hdl->eof = true;
   }
}


//-------- HISR Level --------
static void awbpIncTime( MHdl *hdl, uint32 num_bytes )
{
   (void)hdl;
   (void)num_bytes;
   
   return;  // dummy function
}

static void awbpUpdateReadPos(MHdl *hdl, int numByte)
{
   hdl->read += numByte;
   if ( hdl->read >= hdl->rb_size ) {
      hdl->read = 0;
   }
}

static void awbpWriteDataToDSP(awbpMediaHdl *ihdl)
{
   MHdl *pstMHdl;
   kal_uint16 *dsp_ptr, *mcu_ptr;
   int i, baseAddr;
   int dataCount;
   
   pstMHdl = ihdl->pstMHdl;
   baseAddr = *AWBPLUS_FIFO_BASE;
   dsp_ptr = (kal_uint16 *)DSP_DM_ADDR(AWBPLUS_PAGE_NUM, baseAddr);
   dataCount = pstMHdl->GetDataCount(pstMHdl) >> 1;   // in Word
   
   if (ihdl->isStereo) {
      // Check the data amount
      if (dataCount < 4370+17) {
         return;
      } else {
         kal_uint8 *bufPtr;
         uint32 bufSize;
         int segment;
         
         // Part 1: Parameters
         pstMHdl->GetReadBuffer(pstMHdl, &bufPtr, &bufSize);
         segment = bufSize >> 1;
         mcu_ptr = (kal_uint16 *)bufPtr;
         if (segment >= 4370)
            segment = 4370;
         
         for (i=segment-1; i>=0; i--)
            *dsp_ptr++ = *mcu_ptr++;
         awbpUpdateReadPos(pstMHdl, segment<<1);
         
         segment = 4370 - segment;
         if (segment > 0) {
            pstMHdl->GetReadBuffer(pstMHdl, &bufPtr, &bufSize);
            mcu_ptr = (kal_uint16 *)bufPtr;
            
            for (i=segment-1; i>=0; i--)
               *dsp_ptr++ = *mcu_ptr++;
            awbpUpdateReadPos(pstMHdl, segment<<1);
         }
         
         // Part 2: Configuration
         baseAddr = *AWBPLUS_CONFIG_BASE;
         dsp_ptr = (kal_uint16 *)DSP_DM_ADDR(AWBPLUS_PAGE_NUM, baseAddr);
         
         pstMHdl->GetReadBuffer(pstMHdl, &bufPtr, &bufSize);
         segment = bufSize >> 1;
         mcu_ptr = (kal_uint16 *)bufPtr;
         if (segment >= 16)
            segment = 16;
         
         for (i=segment-1; i>=0; i--)
            *dsp_ptr++ = *mcu_ptr++;
         awbpUpdateReadPos(pstMHdl, segment<<1);
         
         segment = 16 - segment;
         if (segment > 0) {
            pstMHdl->GetReadBuffer(pstMHdl, &bufPtr, &bufSize);
            mcu_ptr = (kal_uint16 *)bufPtr;
            
            for (i=segment-1; i>=0; i--)
               *dsp_ptr++ = *mcu_ptr++;
            awbpUpdateReadPos(pstMHdl, segment<<1);
         }
         
         // Get ISF to know time information
         {
            int isf_index;
            
            pstMHdl->GetReadBuffer(pstMHdl, &bufPtr, &bufSize);
            mcu_ptr = (kal_uint16 *)bufPtr;
            isf_index = *mcu_ptr;
            awbpUpdateReadPos(pstMHdl, 2);
            
            ihdl->mh.current_time += awbpFrameDuration_ms[isf_index];
            ihdl->remainderTime += awbpFrameDuration_45thms[isf_index];
            
            if (ihdl->remainderTime >= 45) {
               ihdl->remainderTime -= 45;
               ihdl->mh.current_time++;
            }
         }
      }
   } else {
      // Check the data amount
      if (dataCount < 1280) {
         kal_uint8 *bufPtr;
         uint32 bufSize;
         int segment, totalSample;
         
         // Part 1: Parameters
         totalSample = 1280;
         pstMHdl->GetReadBuffer(pstMHdl, &bufPtr, &bufSize);
         segment = bufSize >> 1;
         mcu_ptr = (kal_uint16 *)bufPtr;
         
         for (i=segment-1; i>=0; i--)
            *dsp_ptr++ = *mcu_ptr++;
         awbpUpdateReadPos(pstMHdl, segment<<1);
         totalSample -= segment;
         
         pstMHdl->GetReadBuffer(pstMHdl, &bufPtr, &bufSize);
         segment = bufSize >> 1;
         mcu_ptr = (kal_uint16 *)bufPtr;
            
         for (i=segment-1; i>=0; i--)
            *dsp_ptr++ = *mcu_ptr++;
         awbpUpdateReadPos(pstMHdl, segment<<1);
         totalSample -= segment;
         
         // Write Zero to DSP
         for (i=totalSample-1; i>=0; i--)
            *dsp_ptr++ = 0;
         
         // Part 2: Configuration
         baseAddr = *AWBPLUS_CONFIG_BASE;
         dsp_ptr = (kal_uint16 *)DSP_DM_ADDR(AWBPLUS_PAGE_NUM, baseAddr);
         *(dsp_ptr + 4) = 0;       // Extension = false
         *(dsp_ptr + 5) = 16000;   // Sampling Frequency = 16000
         *(dsp_ptr + 7) = 1;       // Limiter is Enable
         *(dsp_ptr + 8) = 1;       // Number of channel is 1 (mono)
         *(dsp_ptr + 10) = 1280;   // Frame length is 1280 samples
         
         ihdl->mh.current_time += 80;

         return;
      } else {
         kal_uint8 *bufPtr;
         uint32 bufSize;
         int segment;
         
         // Part 1: Parameters
         pstMHdl->GetReadBuffer(pstMHdl, &bufPtr, &bufSize);
         segment = bufSize >> 1;
         mcu_ptr = (kal_uint16 *)bufPtr;
         if (segment >= 1280)
            segment = 1280;
         
         for (i=segment-1; i>=0; i--)
            *dsp_ptr++ = *mcu_ptr++;
         awbpUpdateReadPos(pstMHdl, segment<<1);
         
         segment = 1280 - segment;
         if (segment > 0) {
            pstMHdl->GetReadBuffer(pstMHdl, &bufPtr, &bufSize);
            mcu_ptr = (kal_uint16 *)bufPtr;
            
            for (i=segment-1; i>=0; i--)
               *dsp_ptr++ = *mcu_ptr++;
            awbpUpdateReadPos(pstMHdl, segment<<1);
         }
         
         // Part 2: Configuration
         baseAddr = *AWBPLUS_CONFIG_BASE;
         dsp_ptr = (kal_uint16 *)DSP_DM_ADDR(AWBPLUS_PAGE_NUM, baseAddr);
         *(dsp_ptr + 4) = 0;       // Extension = false
         *(dsp_ptr + 5) = 16000;   // Sampling Frequency = 16000
         *(dsp_ptr + 7) = 1;       // Limiter is Enable
         *(dsp_ptr + 8) = 1;      // Number of channel is 1 (mono)
         *(dsp_ptr + 10) = 1280;   // Frame length is 1280 samples
         
         ihdl->mh.current_time += 80;
      }
   }
}

static void awbpHisr( void *data )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)data;
   MHdl *hdl = (MHdl *)ihdl;

   if ( ihdl->end_status == MEDIA_TERMINATED )
      return;

   if ( *AWBPLUS_STATUS == DSP_AWBPLUS_STATE_IDLE ) {  // DSP in idle state
      ihdl->end_status = MEDIA_TERMINATED;
      kal_prompt_trace( MOD_L1SPHISR, " DAF_L1AUDIO_IDLE_STATE ");

      if (KAL_TRUE == ihdl->bError) {         
         mhdlException( (MHdl*)ihdl, MEDIA_ERROR );
      } else if(KAL_TRUE == ihdl->bDecUnsupport){
         mhdlException( (MHdl*)ihdl, MEDIA_DECODER_UNSUPPORT );
      } else{
         mhdlException( (MHdl*)ihdl, MEDIA_END );
      }
      return;
   }

   if ( ihdl->end_status == MEDIA_END )
      return;

   if ( ihdl->fDecoderError )
      mhdlException( (MHdl*)ihdl, MEDIA_ERROR );

   // bypass the buffer underflow warning from DSP
   if ( (*AWBPLUS_ERROR_REPORT != 0) && (*AWBPLUS_ERROR_REPORT != 0x2222) ) {
      if (ihdl->AWB_Decode_EOF){
         ihdl->end_status = MEDIA_END;
         if ( *AWBPLUS_STATUS == DSP_AWBPLUS_STATE_PLAYING )
            *AWBPLUS_STATUS = DSP_AWBPLUS_STATE_END;
         kal_prompt_trace( MOD_L1SPHISR, " DAF_L1AUDIO_END_STATE ");
         return;
      }
      
      /* check if DSP reports error */
      *AWBPLUS_STATUS = DSP_AWBPLUS_STATE_STOP;
      if (*AWBPLUS_STATUS == 0x1111)
         ihdl->bDecUnsupport = KAL_TRUE;
      else
         ihdl->bError = KAL_TRUE;
      return;
   }

   if( ihdl->mh.dsp_rb_base == 0 ) {   // DSP RingBuf initialization
      ihdl->mh.dsp_rb_base = *AWBPLUS_FIFO_BASE;
   }

   if (!ihdl->AWB_Decode_EOF) {
      awbpWriteDataToDSP(ihdl);
   } else {
      ihdl->end_status = MEDIA_END;
      if ( *AWBPLUS_STATUS == DSP_AWBPLUS_STATE_PLAYING )
         *AWBPLUS_STATUS = DSP_AWBPLUS_STATE_END;
     
      kal_prompt_trace( MOD_L1SPHISR, " DAF_L1AUDIO_END_STATE ");
      return;
   }

   if ( (hdl->eof && (hdl->GetDataCount(hdl) <= 1))
        || (ihdl->mh.current_time >= ihdl->mh.stop_time) ) {
      if ( *AWBPLUS_STATUS == DSP_AWBPLUS_STATE_PLAYING ) {
         ihdl->AWB_Decode_EOF = true;
         
         ihdl->end_status = MEDIA_END;
         *AWBPLUS_STATUS = DSP_AWBPLUS_STATE_END;
     
         kal_prompt_trace( MOD_L1SPHISR, " DAF_L1AUDIO_END_STATE ");
      }
   }

   mhdlDataRequest((MHdl*)ihdl, ihdl->end_status);
}


//-------- Open / Close Device

static void awbpOpenDevice( awbpMediaHdl *ihdl)
{
   ihdl->end_status = MEDIA_NONE; // Clear for streaming case
   ihdl->mh.dsp_rb_base = 0;

   mhdlDisallowSleep( (MHdl*)ihdl );
   ASSERT(*AWBPLUS_STATUS == DSP_AWBPLUS_STATE_IDLE);

   kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE );

   *DP_AUDIO_CTRL2 |= DP_PCM_R_DIS;
   *DP_AUDIO_FLEXI_CTRL |= 0x0005;
   
   DSP_DynamicDownload( DDID_AWB_PLUS );
  
   *AWBPLUS_STATUS = DSP_AWBPLUS_STATE_START;
   
#if defined(AUD_TIME_STRETCH)
   AudioPP_Disable();
#endif // AUD_TIME_STRETCH

   AM_AudioPlaybackOn( ASP_TYPE_AWB_PLUS, ihdl->sr_index );

   {
      kal_uint16 I;
      for ( I = 0; ; I++ ) {
         if ( (DSP_AWBPLUS_STATE_PLAYING == *AWBPLUS_STATUS) || (ihdl->end_status != MEDIA_NONE) ) {
            kal_trace( TRACE_STATE, L1AUDIO_RUNNING_STATE );
            break;
         }

         if (DSP_AWBPLUS_STATE_IDLE == *AWBPLUS_STATUS) {
            /* This is the case when AWB decoder has started and encoutered an error,
               awbpPlaybackHisr found this and set the state to STOP, then AWB decoder set the state to IDLE. */
            break;
         }
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
   
   ihdl->mh.state = AWBPLUS_STATE_PLAY;
}


static void awbpCloseDevice( awbpMediaHdl *ihdl )
{
   kal_uint32 I;

   for ( I = 0; ; I++ ) {
       // DSP returns to idle state
      if ( DSP_AWBPLUS_STATE_IDLE == *AWBPLUS_STATUS )
         break;
      
      if ( DSP_AWBPLUS_STATE_PLAYING == *AWBPLUS_STATUS ) {
         // give ABORT command to the DSP
         *AWBPLUS_STATUS = DSP_AWBPLUS_STATE_STOP;
         kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
      }
      ASSERT_REBOOT( I < 80 );
      kal_sleep_task( 2 );
   }

   AM_AudioPlaybackOff( true );

   *DP_AUDIO_FLEXI_CTRL &= ~0x0005;
   *DP_AUDIO_CTRL2 &= ~DP_PCM_R_DIS;

#if defined(AUD_TIME_STRETCH)
   AudioPP_Enable();
#endif  // AUD_TIME_STRETCH

   mhdlAllowSleep( (MHdl*)ihdl );
}


//-------- L1Audio Task Level : to decode AWB bit stream --------
static void awbpDecodeTask( void *data )
{
   MHdl *hdl = (MHdl *)data;
   awbpMediaHdl *ihdl = (awbpMediaHdl *) hdl;

   if ( ihdl->end_status == MEDIA_TERMINATED )
      return;

   kal_take_sem( WAVsema, KAL_INFINITE_WAIT );
   if ( hdl->state != AWBPLUS_STATE_PLAY ) {
      hdl->waiting = KAL_FALSE;
      kal_give_sem( WAVsema );
      return;
   }

   awbpFillMediaBuffer(hdl);
   hdl->waiting = KAL_FALSE;
   kal_give_sem( WAVsema );
}


//-------- Cache Related Functions --------


static kal_int32 awbpGetBytesFromFile(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr)
{
   kal_uint32 file_size, data_size;

   FSAL_GetFileSize(pstFSAL, &file_size);
   data_size = file_size - fileOffset;
   if (data_size <= num_bytes)
      num_bytes = data_size;

   FSAL_Seek( pstFSAL, fileOffset);
   if (FSAL_Read_Bytes( pstFSAL, ptr, num_bytes) != FSAL_OK)
      return -1;

   return num_bytes;
}

static void awbpProcessCache(awbpMediaHdl *ihdl)
{
   kal_uint32 currentIndex, currentTime, currentOffset, cacheBoundary;
   kal_uint32 duration, numByte;
   int flag;
   
   currentIndex  = ihdl->AudioCacheTbl->currentEntryIndex;
   cacheBoundary = ihdl->AudioCacheTbl->entryBoundary;
   currentTime   = ihdl->AudioCacheTbl->accumulateTime[currentIndex];
   currentOffset = ihdl->AudioCacheTbl->accumulateOffset[currentIndex];
   
   if (currentOffset == ihdl->uFileSize) {
      // Cache table finished
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FINISH_RETURN, MEDIA_FORMAT_AMR );
      return;
   }
   
   while (currentOffset < cacheBoundary) {
      
      FSAL_Seek( ihdl->pstFSAL, currentOffset);
      flag = AWB_CacheParseFrame(ihdl->pstFSAL, &duration, &numByte, &ihdl->extension);
      
      if (flag == AWB_ERROR_NUMBER) {
         // Error Occurs, should return error message
         ihdl->mh.eSeekLastRet = MEDIA_SEEK_FAIL;
         return;
      } else if (flag == 0) {
         // No data, at the end of file
         currentOffset = ihdl->uFileSize;
      } else {
         currentTime += duration;
         currentOffset += numByte;
      }
   }
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, MEDIA_FORMAT_AMR, currentIndex, currentOffset );
   
   cacheBoundary += ihdl->AudioCacheTbl->sizePerEntry;
   currentIndex++;
   if (cacheBoundary > ihdl->uFileSize)
      cacheBoundary = ihdl->uFileSize;
   
   ihdl->AudioCacheTbl->currentEntryIndex              = currentIndex;
   ihdl->AudioCacheTbl->entryBoundary                  = cacheBoundary;
   ihdl->AudioCacheTbl->accumulateTime[currentIndex]   = currentTime;
   ihdl->AudioCacheTbl->accumulateOffset[currentIndex] = currentOffset;
}


static kal_bool awbpChkFileHeader( awbpMediaHdl *ihdl )
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

   return KAL_TRUE;
#endif
}

static void awbpProgressiveSeek( awbpMediaHdl *ihdl )
{
   uint32 cacheOffset;

   // Process cache table
   awbpProcessCache(ihdl);

   cacheOffset = ihdl->AudioCacheTbl->accumulateOffset[ ihdl->AudioCacheTbl->currentEntryIndex ];
   
   if (ihdl->uFileSize != 0) {
      ihdl->mh.uSeekProgress = (kal_uint64)cacheOffset * 100 / (kal_uint64) ihdl->uFileSize;
      ihdl->mh.eSeekLastRet = MEDIA_SUCCESS;
   } else {
      ihdl->mh.uSeekProgress = 0;
      ihdl->mh.eSeekLastRet = MEDIA_SEEK_FAIL;
   }
}

static void awbpMFSeek( MHdl *hdl, Media_Status *eSeekLastRet, kal_uint32 *uProgress )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;

#if CacheAsOriginal
   if (hdl->uGetDurProgress == 0){
      ihdl->fileOffset = 0;
      ihdl->end_status = MEDIA_NONE;
      hdl->read = 0;
      hdl->write = 0;
      hdl->eof = KAL_FALSE;
      hdl->waiting = KAL_FALSE;
      hdl->current_time = hdl->start_time;

      if (awbpChkFileHeader( ihdl ) == KAL_FALSE){
         hdl->eSeekLastRet = MEDIA_BAD_FORMAT;
         return;
      }
      ihdl->AudioCacheTbl->accumulateOffset[0] = ihdl->fileOffset;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, MEDIA_FORMAT_AWB_PLUS, 0, ihdl->fileOffset );
   }
#endif

   awbpProgressiveSeek(ihdl);

   *eSeekLastRet = hdl->eSeekLastRet;
   *uProgress = hdl->uSeekProgress;
}

static void awbpMFBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;

   if( 100 == hdl->uGetDurProgress ){ // cache table finished
      *eLastRet = MEDIA_SUCCESS;
      *uProgress = 100;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_BUILD_CACHE, MEDIA_FORMAT_AWB_PLUS, MEDIA_SUCCESS, 100 );
      return;
   }

   {
      Media_Status eSeekLastRet;
      kal_uint32 uProgress;
      awbpMFSeek( hdl, &eSeekLastRet, &uProgress );   // parse fixed size
   }
   
   *eLastRet = hdl->eSeekLastRet;   // last result
   
   {
      kal_uint32 uCurPos;

      ASSERT(ihdl->uFileSize != 0);
      uCurPos = ihdl->AudioCacheTbl->accumulateOffset[ihdl->AudioCacheTbl->currentEntryIndex];
      hdl->uGetDurProgress = (kal_uint64)uCurPos * (kal_uint64)100 / (kal_uint64)ihdl->uFileSize;
   }

   *uProgress = hdl->uGetDurProgress;

#if CacheAsOriginal
   if( 100 == hdl->uGetDurProgress ){
      hdl->uSeekProgress = 0;
      hdl->start_time = 0;
      ihdl->fileOffset = 0;
   }
#endif

   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_BUILD_CACHE, MEDIA_FORMAT_AWB_PLUS, *eLastRet, *uProgress );
}

static kal_bool awbpSeek(awbpMediaHdl *ihdl)
{
   awbpCacheTable *pCacheTable;
   uint32 startTime, tempAccuTime, tmpFileOffset;
   
   pCacheTable = ihdl->AudioCacheTbl;
   startTime = (ihdl->mh.start_time) * 45;   // Time unit is 1/45 ms
   tempAccuTime = 0;
   tmpFileOffset = 0;
   if (pCacheTable != 0) {
      // Binary Search
      uint16 start_index, end_index;
      
      // Binary Search
      start_index = 0;
      end_index = pCacheTable->currentEntryIndex;
      if (startTime > pCacheTable->accumulateTime[end_index]) {
         start_index = end_index;
      } else {
         while ((end_index-start_index)>1) {
            uint16 middle_index = (start_index + end_index) / 2;
            if (startTime > pCacheTable->accumulateTime[middle_index])
               start_index = middle_index;
            else
               end_index = middle_index;
         }
      }
      tempAccuTime = pCacheTable->accumulateTime[start_index];
      tmpFileOffset = pCacheTable->accumulateOffset[start_index];
   }

   // Linear Search
   {
      uint32 validFileSize, duration, frameByte;
      int32 state;

      // Read all frames to ensure correct time
      validFileSize = ihdl->uFileSize;
      FSAL_Seek( ihdl->pstFSAL, tmpFileOffset);
      while (startTime > tempAccuTime) {
         state = AWB_CacheParseFrame(ihdl->pstFSAL, &duration, &frameByte, &ihdl->extension);
         
         if (frameByte == 0) {
            ihdl->mh.eof = true;
            break;
         } else if (state == AWB_ERROR_NUMBER) {
            // Error or no data
            return false;
         }
         
         if (tempAccuTime+duration <= startTime) {
            tempAccuTime += duration;
            tmpFileOffset += frameByte;
         } else {
            // Seek the wanted position
            break;
         }
      }
      
      ihdl->fileOffset = tmpFileOffset;
      FSAL_Seek( ihdl->pstFSAL, tmpFileOffset);
   }

   return true;
}

static void awbpMFSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, void *param )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;
   
    // make sure 4-byte alignment
   ASSERT(((uint32)ptr & 0x03) == 0 );
   ihdl->AudioCacheTbl = (awbpCacheTable *)ptr;
   (void) param;      // To avoid warning

   if (ihdl->AudioCacheTbl->sizePerEntry == 0) {
      ihdl->AudioCacheTbl->sizePerEntry = ihdl->uFileSize / MAX_CACHE_ENTRIES;
      if ( ihdl->AudioCacheTbl->sizePerEntry < MIN_CACHE_PROCESS_SIZE )
         ihdl->AudioCacheTbl->sizePerEntry = MIN_CACHE_PROCESS_SIZE;
   
      if (ihdl->AudioCacheTbl->sizePerEntry < ihdl->uFileSize)
         ihdl->AudioCacheTbl->entryBoundary = ihdl->AudioCacheTbl->sizePerEntry;
      else
         ihdl->AudioCacheTbl->entryBoundary = ihdl->uFileSize;
   }

   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SET_CACHE_TBL, MEDIA_FORMAT_AWB_PLUS );
}

kal_uint32 awbpMFGetCacheDur(MHdl *hdl)
{
   kal_uint32 uDur;
   awbpMediaHdl *ihdl = (awbpMediaHdl *) hdl;
   
   ASSERT(ihdl->AudioCacheTbl != 0);

   uDur = ihdl->AudioCacheTbl->accumulateTime[ihdl->AudioCacheTbl->currentEntryIndex] / 45;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR_F, MEDIA_FORMAT_AMR, uDur );
   return uDur;
}

kal_uint32 awbpMFGetTotalDuration( MHdl *hdl )
{
   kal_uint32 uDur, uSize;
   awbpMediaHdl *ihdl = (awbpMediaHdl *) hdl;

   ASSERT(ihdl->AudioCacheTbl != 0);

   uDur  = ihdl->AudioCacheTbl->accumulateTime[ihdl->AudioCacheTbl->currentEntryIndex] / 45;
   uSize = ihdl->AudioCacheTbl->accumulateOffset[ihdl->AudioCacheTbl->currentEntryIndex];
   if (uSize != 0) {
      // Linear Extrapolation
      uDur  = (kal_uint64)uDur * (kal_uint64) ihdl->uFileSize / (kal_uint64) uSize;
   } else {
      uDur = 0;
   }

   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_TOTAL_DUR, MEDIA_FORMAT_AMR, uDur );
   return uDur;
}

//-------- Basic Function For Operation --------

static Media_Event awbpMFProcess( MHdl *hdl, Media_Event event )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *) hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, hdl->mediaType );

   switch (event)
   {
      case MEDIA_END:
         if ( hdl->state == AWBPLUS_STATE_PLAY )
            awbpCloseDevice( ihdl );
         hdl->state = AWBPLUS_STATE_IDLE;
         return event;
         
      case MEDIA_ERROR:
      case MEDIA_DECODER_UNSUPPORT:
         kal_trace( TRACE_ERROR, L1AUDIO_DSP_ERROR );
         if ( hdl->state == AWBPLUS_STATE_PLAY )
            awbpCloseDevice( ihdl );
         hdl->state = AWBPLUS_STATE_IDLE;
         return event;

      case MEDIA_DATA_REQUEST:
         kal_take_sem( WAVsema, KAL_INFINITE_WAIT );
         L1Audio_SetEvent( ihdl->aud_id_decoder, hdl );
         kal_give_sem( WAVsema );
         
         {
            kal_uint32 uRatio;
            
            uRatio = (kal_uint64)ihdl->fileOffset * 100 / (kal_uint64)ihdl->uFileSize;
            if (uRatio > ihdl->uDurUpdateThd) {
               if (ihdl->uDurUpdateThd < 100)
                  ihdl->uDurUpdateThd += 5;
               return MEDIA_UPDATE_DUR;
            }
         }
         
         return MEDIA_NONE;

      default:
         ASSERT(0); // should never reach here
   }
   return MEDIA_NONE;
}

static Media_Event awbpMFStrmProcess( MHdl *hdl, Media_Event event )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *) hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, hdl->mediaType );

   switch (event)
   {
      case MEDIA_END:
      case MEDIA_ERROR:
         kal_trace( TRACE_ERROR, L1AUDIO_DSP_ERROR );
         if( hdl->state == AWBPLUS_STATE_PLAY )
            awbpCloseDevice( ihdl );
         hdl->state = AWBPLUS_STATE_IDLE;
         return event;

      case MEDIA_DATA_REQUEST:
         return MEDIA_DATA_REQUEST;

      default:
         ASSERT(0); // should never reach here
   }
   return MEDIA_NONE;
}

static Media_Status awbpMFPlayFile( MHdl *hdl )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;

   if (hdl->start_time || hdl->current_time) {
      ihdl->fileOffset = 0;
      ihdl->end_status = MEDIA_NONE;
      hdl->read = 0;
      hdl->write = 0;
      hdl->eof = KAL_FALSE;
      hdl->waiting = KAL_FALSE;
      hdl->current_time = hdl->start_time;
   }
   ihdl->parsedTime = hdl->start_time * 45;

   // Get the memory space for handle / share buffer
   // Set configuration
   if (!awbpWorking_data) {
      unsigned int tempBufSize;
      int mode;
      
      tempBufSize = AWB_GetTempBufSize();
      awbpWorking_data = (kal_uint8 *)med_alloc_ext_mem(tempBufSize);
      ihdl->decStruct = AWB_Decode_Open((char *)awbpWorking_data);
      
      ihdl->frameMode = mode = AWB_ReadHeader(ihdl->decStruct, ihdl->pstFSAL);
      
      if ((mode >= 16) && (mode <= 47)) {
         ihdl->sr_index = ASP_FS_48K;
         ihdl->extension = 1;
         ihdl->isStereo = true;
         ihdl->frameSize = 4370+17;
      } else if ((mode >= 0) && (mode <= 15)) {
         ihdl->sr_index = ASP_FS_16K;
         
         if ( (mode >= 10) && (mode <= 13) ) {
            ihdl->extension = 1;
         } else {
            ihdl->extension = 0;
         }
         
         if ((mode==11) || (mode==13)) {
            ihdl->isStereo = true;
            ihdl->frameSize = 4370+17;
         } else {
            ihdl->isStereo = false;
            ihdl->frameSize = 1280;
         }
      } else {
         return MEDIA_BAD_FORMAT;
      }
   }

   if ( (awbpSeek(ihdl) != KAL_TRUE) || (ihdl->fileOffset >= ihdl->uFileSize) )
      return MEDIA_SEEK_EOF;

   awbpFillMediaBuffer(hdl);

   awbpOpenDevice(ihdl);

   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_FILE, hdl->mediaType);

   return MEDIA_SUCCESS;
}

static Media_Status awbpMFPlayStrm( MHdl *hdl )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;

   ihdl->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   if (ihdl->pstFSAL == NULL)
      return MEDIA_FAIL;

   ihdl->fileOffset = 0;
   ihdl->end_status = MEDIA_NONE;
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->current_time = hdl->start_time;
   ihdl->parsedTime = hdl->start_time * 45;
   
   {
      FSAL_Status eFSALStatus;
      FSAL_Direct_SetRamFileSize(ihdl->pstFSAL, hdl->rb_size);
      eFSALStatus = FSAL_Open(ihdl->pstFSAL, hdl->rb_base, FSAL_ROMFILE);
      ASSERT(eFSALStatus == FSAL_OK);
   }
   
   // Get the memory space for handle / share buffer
   // Set configuration
   if (!awbpWorking_data) {
      unsigned int tempBufSize;
      int mode;
      
      tempBufSize = AWB_GetTempBufSize();
      awbpWorking_data = (kal_uint8 *)med_alloc_ext_mem(tempBufSize);
      ihdl->decStruct = AWB_Decode_Open((char *)awbpWorking_data);
      
      ihdl->frameMode = mode = AWB_ReadHeader(ihdl->decStruct, ihdl->pstFSAL);
      
      if ((mode >= 16) && (mode <= 47)) {
         ihdl->sr_index = ASP_FS_48K;
         ihdl->isStereo = true;
         ihdl->frameSize = 4370+17;
      } else if ((mode >= 0) && (mode <= 15)) {
         ihdl->sr_index = ASP_FS_16K;
         if ((mode==11) || (mode==13)) {
            ihdl->isStereo = true;
            ihdl->frameSize = 4370+17;
         } else {
            ihdl->isStereo = false;
            ihdl->frameSize = 1280;
         }
      } else {
         free_ctrl_buffer( ihdl->pstFSAL );
         return MEDIA_BAD_FORMAT;
      }
   }

   {
      MHdl *pstTmp = ihdl->pstMHdl;
      
      pstTmp->rb_base = (kal_uint8 *)med_alloc_ext_mem(AWBPLUS_OUT_BUF_SIZE);
      pstTmp->rb_size = AWBPLUS_OUT_BUF_SIZE;
      pstTmp->read = 0;
      pstTmp->write = 0;
   }

   awbpFillMediaBuffer(hdl);
   awbpOpenDevice(ihdl);

   free_ctrl_buffer( ihdl->pstFSAL );
   ihdl->pstFSAL = NULL;

   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_FILE, hdl->mediaType);

   return MEDIA_SUCCESS;
}

static Media_Status awbpMFPause( MHdl *hdl )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;

   kal_take_sem( WAVsema, KAL_INFINITE_WAIT );
   ASSERT( hdl->state == AWBPLUS_STATE_PLAY );

   ihdl->end_status = MEDIA_TERMINATED;
   awbpCloseDevice( ihdl );
   hdl->state = AWBPLUS_STATE_PAUSE;

   kal_give_sem( WAVsema );
   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, hdl->mediaType );

   return MEDIA_SUCCESS;
}

static Media_Status awbpMFResumeFile( MHdl *hdl )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;

   if ( hdl->state != AWBPLUS_STATE_PAUSE )
      return MEDIA_FAIL;

   if (ihdl->AWB_Decode_EOF || hdl->eof) {
      mhdlException(hdl, MEDIA_END);
      return MEDIA_SUCCESS;
   }

   hdl->read = 0;
   hdl->write = 0;
   hdl->eof = false;
   hdl->waiting = false;
   hdl->start_time = hdl->current_time;
//   ihdl->fileOffset = ihdl->resumeFrameOffset;

   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType );

   return awbpMFPlayFile(hdl);
}

static Media_Status awbpMFResumeStrm( MHdl *hdl )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;

   ASSERT( hdl->state == AWBPLUS_STATE_PAUSE );

   awbpFillMediaBuffer(hdl);
   awbpOpenDevice(ihdl);
   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType);

   return MEDIA_SUCCESS;
}

static Media_Status awbpMFStop( MHdl *hdl )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;

   kal_take_sem( WAVsema, KAL_INFINITE_WAIT );

   if( hdl->state == AWBPLUS_STATE_PAUSE || hdl->state == AWBPLUS_STATE_IDLE ){
      kal_give_sem( WAVsema );
      return MEDIA_SUCCESS;
   }

   ihdl->end_status = MEDIA_TERMINATED;
   awbpCloseDevice( ihdl );
   hdl->state = AWBPLUS_STATE_IDLE;

   kal_give_sem( WAVsema );

   kal_trace( TRACE_FUNC, L1AUDIO_STOP, hdl->mediaType );
   
   return MEDIA_SUCCESS;
}

static Media_Status awbpMFClose( MHdl *hdl )
{
   awbpMediaHdl *ihdl = (awbpMediaHdl *)hdl;
   ASSERT( hdl != 0 && hdl->state != AWBPLUS_STATE_PLAY);

   if( hdl->handler != NULL ) {
      mhdlFinalize( hdl, DP_D2C_AWBPLUS );
   }

   L1Audio_FreeAudioID( ihdl->aud_id_decoder );
   med_free_ext_mem( (void **) &awbpWorking_data);
   
   if (ihdl->isStreaming)
      med_free_ext_mem( (void **) &ihdl->pstMHdl->rb_base);
   
   free_ctrl_buffer( hdl );
   
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, hdl->mediaType );

#if AWB_DEBUG
   FSAL_Close(&pDebugFSAL);
#endif

   return MEDIA_SUCCESS;
}


MHdl *AWB_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   awbpMediaHdl *ihdl;

#if AWB_DEBUG
   {
      FSAL_Status eFSALRet;
      
      kal_wsprintf(awbp_debug_file_name, "C:\\debug1_ARM.bin");
      eFSALRet = FSAL_Open(&pDebugFSAL, awbp_debug_file_name, FSAL_READ);
      ASSERT( eFSALRet==FSAL_OK );
      
      memset(awbpDebugBuf, 0, 4387*sizeof(short));
   }
#endif

   ihdl = (awbpMediaHdl *)get_ctrl_buffer( sizeof(awbpMediaHdl) );
   memset(ihdl, 0, sizeof(awbpMediaHdl));
   hdl = (MHdl *) ihdl;
   
   if( handler != NULL )
      mhdlInit( hdl, DP_D2C_AWBPLUS, awbpHisr );
   else
      mhdlInitEx( hdl, DP_D2C_AWBPLUS, awbpHisr );

   ihdl->pstMHdl   = NULL;
   hdl->state      = AWBPLUS_STATE_IDLE;
   hdl->handler    = handler;
   hdl->mediaType  = MEDIA_FORMAT_AWB_PLUS;
   ihdl->pstFSAL   = pstFSAL;
   FSAL_GetFileSize( ihdl->pstFSAL, &ihdl->uFileSize);
   
   
   hdl->Stop       = awbpMFStop;
   hdl->Pause      = awbpMFPause;
   hdl->Close      = awbpMFClose;
   
   if (pstFSAL != NULL) {
      // File case
      hdl->Play       = awbpMFPlayFile;
      hdl->Resume     = awbpMFResumeFile;
      hdl->Process    = awbpMFProcess;
      
      ihdl->isStreaming = false;
      ihdl->pstMHdl     = hdl;
      
      kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, MEDIA_FORMAT_AWB_PLUS );
   } else {
      // Streaming case
      hdl->Play       = awbpMFPlayStrm;
      hdl->Resume     = awbpMFResumeStrm;
      hdl->Process    = awbpMFStrmProcess;
      
      ihdl->isStreaming = true;
      ihdl->pstMHdl = (MHdl*)get_ctrl_buffer( sizeof(MHdl) );
      memset(ihdl->pstMHdl, 0, sizeof(MHdl));
      mhdlInitEx( ihdl->pstMHdl, DP_D2C_AWBPLUS, awbpHisr );
      
      kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, MEDIA_FORMAT_AWB_PLUS );
   }
   
   hdl->BuildCache    = awbpMFBuildCache;
   hdl->SetCacheTbl  = awbpMFSetCacheTbl;
   hdl->GetCacheDuration = awbpMFGetCacheDur;
   hdl->GetTotalDuration = awbpMFGetTotalDuration;

   ihdl->aud_id_decoder = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( ihdl->aud_id_decoder, awbpDecodeTask );

   return hdl;
}


Media_Status AWB_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   kal_uint32 file_size, frame_size, frame_time;
   kal_int32 mode;

   FSAL_GetFileSize( pstFSAL, &file_size);

   contentInfo->title[0]  = '\0';
   contentInfo->artist[0] = '\0';
   contentInfo->album[0]  = '\0';
   contentInfo->author[0]  = '\0';
   contentInfo->copyright[0]  = '\0';
   contentInfo->date[0]  = '\0';
   contentInfo->time = 0;
   contentInfo->bitRate = 0;
   contentInfo->sampleRate = 0;
   contentInfo->stereo = false;

   AWBP_GetFrameInformation(pstFSAL, &frame_size, &frame_time, &mode);

   if (mode < 16) {
      contentInfo->sampleRate = 16000;
      if ( (mode == 11) || (mode == 13) )
         contentInfo->stereo = true;
      else
         contentInfo->stereo = false;
   } else if (mode < 24) {
      contentInfo->sampleRate = 48000;
      contentInfo->stereo = false;
   } else if (mode < 48) {
      contentInfo->sampleRate = 48000;
      contentInfo->stereo = true;
   } else {
      return MEDIA_BAD_FORMAT;
   }
   
   if (frame_time > 0)
      contentInfo->bitRate = (frame_size * 8000) / frame_time;
   if (frame_size > 0)
      contentInfo->time = frame_time * (file_size / frame_size);
   
   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, MEDIA_FORMAT_AWB_PLUS );
   return MEDIA_SUCCESS;
}

Media_Status AWB_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
   Media_Status ret;
   FSAL_Status eFSALStatus;
   STFSAL *pstFSAL = 0;

   pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   if(pstFSAL == NULL)
      return MEDIA_FAIL;
   memset(pstFSAL, 0, sizeof(STFSAL));
      
   if(NULL != filename){      
      eFSALStatus = FSAL_Open(pstFSAL, (void*)filename, FSAL_READ);
      if(eFSALStatus != FSAL_OK){
         free_ctrl_buffer(pstFSAL);
         return MEDIA_FAIL;
      }   
   }else{
       ASSERT(pbBuf != 0);
       ASSERT(uSize != 0)
       FSAL_Direct_SetRamFileSize(pstFSAL, uSize);
       eFSALStatus = FSAL_Open(pstFSAL, pbBuf, FSAL_ROMFILE);
       ASSERT(eFSALStatus == FSAL_OK);
   }

   ret = AWB_GetContentDescInfo( pstFSAL, contentInfo, (void *)0);
   
   if(NULL != filename){
      FSAL_Close(pstFSAL);
   }
   free_ctrl_buffer(pstFSAL);

   return ret;
}

#if defined(AWB_UNIT_TEST)
// AWB_Plus uses AMR format

MHdl *AMR_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;

   hdl = AWB_Open( handler, pstFSAL, param);
   return hdl;
}

Media_Status AMR_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   Media_Status state;
   
   state = AWB_GetContentDescInfo(pstFSAL, contentInfo, param);
   return state;
}

Media_Status AMR_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
   Media_Status state;
   
   state = AWB_GetMetaData(filename, pbBuf, uSize, contentInfo, param);
   return state;
}

#endif  // AWB_UNIT_TEST

#endif  // AWB_PLUS_DECODE
