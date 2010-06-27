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
 * vm_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   VM Decoder Driver
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "fsal.h"
#include "media.h"
#include "l1sp_trc.h"
#include "afe.h"

#if !defined(MT6205B)
#define VM_LOG_DEBUG
#define CACHE_ENABLE
#endif
//#define VM_VR_RERECORD

#define VM_CTRL_UL         1
#define VM_CTRL_DL         2
#define VM_CTRL_SC_START   2
#define VM_CTRL_SD_START   6

#define VM_STATE_IDLE          0
#define VM_STATE_PLAY          3
#define VM_STATE_PLAY_PAUSE    4
#define VM_STATE_STOP          5

#define LoadDWORD( dw, p )   (dw) = (*(p+3)<<24) | (*(p+2)<<16) | (*(p+1)<<8) |(*p);  (p) += sizeof(uint32);
#define MAX_DATA_REQUESTED    1024
#define MAX_CACHE_ENTRIES     250

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define MAX_CACHE_PROCESS_SIZE  8192
#else
#define MAX_CACHE_PROCESS_SIZE  2048
#endif


/* ------------------------------------------------------------------------------ */
typedef struct {
   uint16 blockPerCache;
   uint16 currentCacheIndex;
   uint32 blockBoundary;
   uint32 entryBoundary;
   uint32 accumulateFrame[MAX_CACHE_ENTRIES];
   uint32 accumulateOffset[MAX_CACHE_ENTRIES];
} AudioCacheTable;

typedef struct vm_internal{
   MHdl           mh;
   STFSAL         *pstFSAL;
   Media_Event    end_status;

   uint8          state;
   uint8          buf[MAX_DATA_REQUESTED];
   uint16         type;
   uint16         control;    /* control word for FR/HR/EFR                         */
                              /* bit  0-1:   Channel usage(bit0:UL,bit1:DL)         */
                              /* bit  2-5:   UL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  6-9:   DL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  10:    DP_TX_TCH_S0_0 data bit 1              */
                              /* bit 11-15:  DP_RX_TCH_S0_0 data bit 1-5            */

                              /* control word for AMR                               */
                              /* bit  0-1:   Channel usage(bit0:UL,bit1:DL)         */
                              /* bit  2-5:   UL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  6-9:   DL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit 10-11:  DP_TX_TCH_S0_0 data bit 0-1            */
                              /* bit 12-15:  DP_RX_TCH_S0_0 data bit 1-3,5          */
   uint32         param;
   uint32         validLen;   // min (file size, vr data size) in byte

   uint32         file_size;
   uint32         fileOffset;
   uint32         headerOffset;

   uint32         cacheOffset;
   uint32         lastCacheOffset;
   uint32         lastCacheFrame;
   AudioCacheTable   *AudioCacheTbl;
} vmMediaHdl;


#define  GET_PLAYBACK_DATA(val)                             \
   if (read_cache == write_cache) {                         \
      return MEDIA_READ_FAIL;                               \
   } else {                                                 \
      uint16 *pMedBuf;                                      \
      pMedBuf = (uint16 *) &hdl->rb_base[read_cache];       \
      (val) = *pMedBuf;                                     \
      read_cache += 2;                                      \
      if( read_cache >= rb_size_cache )                     \
         read_cache = 0;                                    \
   }

#if !defined(MT6205B)
static uint32 vmCacheParseFrame(vmMediaHdl *ihdl)
{
   MHdl *hdl = (MHdl *) ihdl;

   uint32  temp_offset = 0;
   uint32  data_len;
   uint16  control, sc_mode, sd_mode, debug_data_len = 0;

   FSAL_Seek( ihdl->pstFSAL, ihdl->cacheOffset);

   while( 1 ) {
      if( hdl->mediaType != MEDIA_FORMAT_VRD && hdl->mediaType != MEDIA_FORMAT_VRSI) {
#if defined( VM_LOG_DEBUG )
         do {
            temp_offset += 2;
            if (FSAL_Read_Bytes( ihdl->pstFSAL, &ihdl->buf[0], 2) != FSAL_OK)
               return temp_offset;
            control = (ihdl->buf[1]<<8) | ihdl->buf[0];
         } while( (control != 0xAA55) && (!hdl->eof) );
         temp_offset += 2;
         if (FSAL_Read_Bytes( ihdl->pstFSAL, &ihdl->buf[0], 2) != FSAL_OK)
            return temp_offset;
         debug_data_len = ( (ihdl->buf[1]<<8) | ihdl->buf[0] ) >> 6;
         temp_offset += 4;
         if (FSAL_Read_Bytes( ihdl->pstFSAL, &ihdl->buf[0], 4) != FSAL_OK)
            return temp_offset;
#endif
         temp_offset += 2;
         if (FSAL_Read_Bytes( ihdl->pstFSAL, &ihdl->buf[0], 2) != FSAL_OK)
            return temp_offset;
         control = (ihdl->buf[1]<<8) | ihdl->buf[0];

         if( (control&3) == 0 )
            continue;
      } else {
         control = 0x401;
      }

      sc_mode = (control >> VM_CTRL_SC_START) & 0x0F;
      sd_mode = (control >> VM_CTRL_SD_START) & 0x0F;
#if !defined(MT6205B)
      if( sc_mode != sd_mode && (sc_mode <= 2 || sd_mode <= 2) )
         continue;
#else
      if( sc_mode > 2 || sc_mode != sd_mode )
         continue;
#endif
      break;
   }

   if (control & VM_CTRL_UL) {
      data_len = AM_GetSpeechPatternLength(sc_mode);
      temp_offset += (data_len << 1);
   }

   if (control & VM_CTRL_DL) {
      data_len = AM_GetSpeechPatternLength(sd_mode);
      temp_offset += (data_len << 1);
   }

#if defined( VM_LOG_DEBUG )
   //if ( sd_mode>2 && sd_mode<11 && (control & VM_CTRL_DL) ){
   if( debug_data_len > 0 ){
      temp_offset += (debug_data_len << 1 );
   }
#endif
   
   return temp_offset;
}
#endif

#if defined(CACHE_ENABLE)
static void vmProcessCache(vmMediaHdl *ihdl)
{
   AudioCacheTable *pCacheTable;
   uint32  frameCount, blockBoundary;

   pCacheTable = ihdl->AudioCacheTbl;
   blockBoundary = pCacheTable->blockBoundary;
   frameCount = 0;

   if (blockBoundary > ihdl->validLen)
      blockBoundary = ihdl->validLen;

   // Increase Entry
   if (ihdl->lastCacheOffset >= pCacheTable->entryBoundary){
      pCacheTable->entryBoundary += (pCacheTable->blockPerCache * MAX_CACHE_PROCESS_SIZE);
      if (pCacheTable->entryBoundary > ihdl->validLen)
         pCacheTable->entryBoundary = ihdl->validLen;
      pCacheTable->currentCacheIndex++;
      pCacheTable->accumulateFrame[pCacheTable->currentCacheIndex] =
         pCacheTable->accumulateFrame[pCacheTable->currentCacheIndex-1];
   }

   // Parse a certain file length
   ihdl->cacheOffset = ihdl->lastCacheOffset;
   while (ihdl->cacheOffset < blockBoundary) {
      uint32 offset;
      offset = vmCacheParseFrame(ihdl);
      ihdl->cacheOffset += offset;
      frameCount++;
   }

   // Increase the element in entry
   ihdl->lastCacheFrame += frameCount;
   ihdl->lastCacheOffset = ihdl->cacheOffset;
   pCacheTable->blockBoundary += MAX_CACHE_PROCESS_SIZE;
   pCacheTable->accumulateOffset[pCacheTable->currentCacheIndex] = ihdl->lastCacheOffset;
   pCacheTable->accumulateFrame[pCacheTable->currentCacheIndex] += frameCount;
}
#endif

#if !defined(MT6205B)
static kal_bool vmSeek( vmMediaHdl *ihdl)
{
   MHdl *hdl = (MHdl *)ihdl;
   uint32  cnt, startFrame;

   startFrame = hdl->start_time / 20;


#if defined(CACHE_ENABLE)
   // Process cache table
   {
      uint16 start_index, end_index;
      uint32 currPos;
      AudioCacheTable *pCacheTbl;

      // Initial Cache
      pCacheTbl = ihdl->AudioCacheTbl;
      FSAL_GetCurPos(ihdl->pstFSAL, &currPos);
      while ( (ihdl->cacheOffset < ihdl->validLen) && (ihdl->lastCacheFrame < startFrame) )
      {
         vmProcessCache(ihdl);
      }
      FSAL_Seek( ihdl->pstFSAL, currPos);

      // Binary Search
      start_index = 0;
      end_index = pCacheTbl->currentCacheIndex;
      while ((end_index-start_index)>1) {
         uint16 middle_index = (start_index + end_index) / 2;
         if (startFrame > pCacheTbl->accumulateFrame[middle_index])
            start_index = middle_index;
         else
            end_index = middle_index;
      }

      // Linear Search
      cnt = pCacheTbl->accumulateFrame[start_index];
      {
         uint32 offset_cache, validFileSize, frame_length;

         offset_cache = pCacheTbl->accumulateOffset[start_index];
         ihdl->cacheOffset = offset_cache;
         validFileSize = ihdl->validLen;
         FSAL_Seek( ihdl->pstFSAL, offset_cache);
         for (; cnt < startFrame; cnt++) {
            frame_length = vmCacheParseFrame(ihdl);
            offset_cache += frame_length;
            if (offset_cache >= validFileSize) {
               hdl->eof = true;
               break;
            }
         }
         ihdl->fileOffset = offset_cache;
      }
   }
#else
   {
      uint32 tmpFileOffset, validFileSize, frame_length;

      // Read all frames to ensure correct time
      tmpFileOffset = ihdl->headerOffset;
      validFileSize = ihdl->validLen;
      ihdl->cacheOffset = tmpFileOffset;
      FSAL_Seek( ihdl->pstFSAL, tmpFileOffset);
      for (cnt=0; cnt < startFrame; cnt++) {
         frame_length = vmCacheParseFrame(ihdl);
         tmpFileOffset += frame_length;

         if (tmpFileOffset >= validFileSize) {
            hdl->eof = true;
            break;
         }
      }
      ihdl->fileOffset = tmpFileOffset;
   }
#endif

   hdl->start_time = hdl->current_time = cnt * 20; // update start time

   if (hdl->eof)
      ihdl->fileOffset = ihdl->file_size;

   if (cnt != startFrame)
      return KAL_FALSE;
   else
      return KAL_TRUE;
}
#endif

static Media_Status vmWriteFrame(MHdl *hdl, bool isReset)
{
   vmMediaHdl *ihdl = (vmMediaHdl *)hdl;

   volatile uint16 *addr;
   uint32   frame_data_len = 0;
   uint16   I, control, sc_mode, sd_mode, data_len, debug_data_len = 0;
   int32    read_cache, write_cache, rb_size_cache;

   read_cache = hdl->read;
   write_cache = hdl->write;
   rb_size_cache = hdl->rb_size;

   while( 1 ) {
      if( hdl->mediaType != MEDIA_FORMAT_VRD && hdl->mediaType != MEDIA_FORMAT_VRSI) {
#if defined( VM_LOG_DEBUG )
         do {
            GET_PLAYBACK_DATA( control );
            frame_data_len += 2;
         } while( control != 0xAA55 );
         GET_PLAYBACK_DATA( control ); //new header, MLB 10 bit : debug length; 3 bit : mode; 3 bit, vm,1st/2nd set pcm
         debug_data_len = control >> 6;
         read_cache += 4;
         frame_data_len += 6;
         if (read_cache >= rb_size_cache)
            read_cache -= rb_size_cache;
#endif
         GET_PLAYBACK_DATA( control );
         frame_data_len += 2;
         if( (control&3) == 0 )
            continue;
      } else {
         control = 0x401;
      }

      sc_mode = (control >> VM_CTRL_SC_START) & 0x0F;
      sd_mode = (control >> VM_CTRL_SD_START) & 0x0F;
#if !defined(MT6205B)
      if( sc_mode != sd_mode && (sc_mode <= 2 || sd_mode <= 2) )
         continue;
#else
      if( sc_mode > 2 || sc_mode != sd_mode )
         continue;
#endif
      break;
   }

   if( control & VM_CTRL_UL ) {
      addr = DP_SD2_VM_0;
      if( sc_mode <= 2 )
         *addr++ = (control >> 9) & 2;       // Write real AMR UL data
      else
         *addr++ = (control >> 10) & 3;      // Write real AMR UL data
      data_len = AM_GetSpeechPatternLength(sc_mode);
      frame_data_len += (data_len << 1);
      for( I = data_len; I > 0; I-- )
         GET_PLAYBACK_DATA( *addr++ );
   } else {                                             // No UL data
      sc_mode = sd_mode;
      AM_FillSilencePattern( DP_SD2_VM_0, 2, sc_mode );
   }
   if( sc_mode > 2 )
      *DP_SD2_VM_17 = sc_mode;

   if( (control & VM_CTRL_DL) == 0 ) {                  // No DL data
      sd_mode = sc_mode;
      AM_FillSilencePattern( DP_SD1_VM_0, 0, sd_mode );
   } else if( control & 0x8000 ) {                      // bad speech
      AM_FillSilencePattern( DP_SD1_VM_0, 0, sd_mode );
      data_len = AM_GetSpeechPatternLength(sd_mode);
      frame_data_len += (data_len << 1);

      hdl->read = read_cache;
      if (hdl->GetDataCount(hdl) < (data_len << 1))
         return MEDIA_READ_FAIL;  // data underflow
      read_cache += (data_len << 1);
      if (read_cache >= rb_size_cache)
         read_cache -= rb_size_cache;
   } else {
      addr = DP_SD1_VM_0;
      if( sd_mode <= 2 ) {
         *addr++ = (control >> 10) & 0x3E;
      } else {
         I = (control >> 12);
         *addr++ = ((I & 8) << 2) + ((I & 7) << 1);
      }
      data_len = AM_GetSpeechPatternLength(sd_mode);
      frame_data_len += (data_len << 1);
      for( I = data_len; I > 0; I-- )
         GET_PLAYBACK_DATA( *addr++ );
   }
#if defined( VM_LOG_DEBUG )
   //if( sd_mode>2 && sd_mode<11 && (control & VM_CTRL_DL) ){
   if( debug_data_len > 0 ){
      debug_data_len = ( debug_data_len << 1 );
      frame_data_len += debug_data_len;

      hdl->read = read_cache;
      if (hdl->GetDataCount(hdl) < debug_data_len)
         return MEDIA_READ_FAIL;  // data underflow
      read_cache += debug_data_len;
      if (read_cache >= rb_size_cache)
         read_cache -= rb_size_cache;
   }
#endif
   if( sd_mode > 2 )
      *DP_SD1_VM_17 = sd_mode;

   if ( (ihdl->control & 0x3FC) != (control & 0x3FC) ) {
      ihdl->control = control;
      AM_VMWriteParameter(sc_mode, sd_mode, isReset);
   }

   ihdl->fileOffset += frame_data_len;
   hdl->read = read_cache;

   return MEDIA_SUCCESS;
}


static void vmHisr( void *data )
{
   vmMediaHdl *ihdl = (vmMediaHdl *)data;
   MHdl *hdl = (MHdl *) ihdl;

   int32 count;

   if (hdl->state != VM_STATE_PLAY)
      return;

   if (vmWriteFrame(hdl, true) != MEDIA_SUCCESS)
      mhdlException( hdl, MEDIA_ERROR );

   hdl->current_time += 20;
   count = hdl->GetDataCount(hdl);

   if( ((hdl->eof) && (count < 34))          ||
   	   (hdl->current_time >= hdl->stop_time) ||
   	   (ihdl->fileOffset >= ihdl->validLen) )
      mhdlException( hdl, MEDIA_END );

   mhdlDataRequest(hdl, ihdl->end_status);
}

Media_Event vmMFProcess( MHdl *hdl, Media_Event event )
{
   vmMediaHdl *ihdl = (vmMediaHdl *) hdl;
   uint32 buf_len;
   int32 get_len, total_len;
   uint8  *pBuf;

   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, hdl->mediaType );

   switch(event)
   {
      case MEDIA_END:
      case MEDIA_ERROR:
         kal_trace( TRACE_ERROR, L1AUDIO_MCU_ERROR );
         if( hdl->state == VM_STATE_PLAY ) {
            AM_VMPlaybackOff( ihdl->param );
            mhdlAllowSleep( hdl );
         }
         hdl->state = VM_STATE_IDLE;
         return event;
      case MEDIA_DATA_REQUEST:
         total_len = hdl->GetFreeSpace(hdl);
         total_len &= 0xFFFFFFFE;

         while (total_len > 0) {
            hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
            get_len = autGetBytes(hdl, ihdl->pstFSAL, buf_len, pBuf);
            if (get_len < 0) {
               kal_trace( TRACE_ERROR, L1AUDIO_MCU_ERROR );
               return MEDIA_ERROR;
            } else if (get_len < buf_len) {
               hdl->eof = true;
               hdl->WriteDataDone( hdl, get_len );
               break;
            } else {
               hdl->WriteDataDone( hdl, get_len );
               total_len -= get_len;
            }
         }

#if defined(CACHE_ENABLE)
         if (ihdl->cacheOffset < ihdl->validLen) {
            uint32 currPos;

            FSAL_GetCurPos(ihdl->pstFSAL, &currPos);
            vmProcessCache(ihdl);
            FSAL_Seek( ihdl->pstFSAL, currPos);
         }
#endif
         hdl->waiting = KAL_FALSE;
         return MEDIA_NONE;
      default:
         ASSERT(0); // should never reach here
   }
   return MEDIA_NONE;
}

static Media_Status vmMFPlayFile( MHdl *hdl )
{
   vmMediaHdl *ihdl = (vmMediaHdl *)hdl;
   Media_Status ret = MEDIA_SUCCESS;

   // Initialize for repeat play
   if (hdl->start_time || hdl->current_time) {
      hdl->state = VM_STATE_PLAY;
      hdl->read = 0;
      hdl->write = 0;
      hdl->eof = false;
      ihdl->fileOffset = 0;
      ihdl->control = 0;
      ihdl->end_status = MEDIA_NONE;
      hdl->current_time = hdl->start_time;
   }

//   if (hdl->rb_size > MAX_DATA_REQUESTED)
//      hdl->rb_size = MAX_DATA_REQUESTED;

#if defined(MT6205B)
   FSAL_Seek( ihdl->pstFSAL, 0);
#endif

   // VRD parser
   if (hdl->mediaType == MEDIA_FORMAT_VRD){
      uint32 dummy_32;
      int32  get_len;
      uint8 *pData;

      ihdl->headerOffset = 18;
      pData = &ihdl->buf[0];
      get_len = autGetBytes(hdl, ihdl->pstFSAL, 18, pData);
      ihdl->fileOffset += 18;
      if (get_len < 18)
         return MEDIA_BAD_FORMAT;

      LoadDWORD(dummy_32, pData);
      if ( (dummy_32 != 0x564B544D) && (dummy_32 != 0x56425943) )
         return MEDIA_BAD_FORMAT;

      pData += 6;
      LoadDWORD(dummy_32, pData);
      if (dummy_32 != 0x45434F56)
         return MEDIA_BAD_FORMAT;

      LoadDWORD(ihdl->validLen, pData);
      if (ihdl->validLen > ihdl->file_size)
         ihdl->validLen = ihdl->file_size;
   }

#if defined(CACHE_ENABLE)
   ihdl->AudioCacheTbl->blockPerCache = ihdl->validLen / (MAX_CACHE_PROCESS_SIZE * MAX_CACHE_ENTRIES);
   ihdl->AudioCacheTbl->blockPerCache += 1;
#endif

#if !defined(MT6205B)
   if (vmSeek(ihdl) == KAL_FALSE) {
      return MEDIA_SEEK_FAIL;
   }
#endif

   {
      uint32 buf_len;
      int32 get_len;
      uint8  *pBuf;

      hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
      buf_len &= 0xFFFFFFFE;
      get_len = autGetBytes(hdl, ihdl->pstFSAL, buf_len, pBuf);
      if (get_len < 0) {
         return MEDIA_BAD_FORMAT;
      } else if (get_len < buf_len) {
         hdl->eof = true;
      }
      hdl->WriteDataDone( hdl, get_len );
   }

   ret = vmWriteFrame(hdl, false);
   if (ret == MEDIA_SUCCESS) {
      /* Set Digital Gain for Voice Memo */
      AFE_SetDigitalGain( L1SP_VOICE, 100 );
      KT_StopAndWait();
      TONE_StopAndWait();
      AM_VMPlaybackOn( ihdl->control, ihdl->param );


      ihdl->end_status = MEDIA_NONE;
      hdl->state = VM_STATE_PLAY;
      mhdlDisallowSleep( hdl );
   }
   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_FILE, hdl->mediaType );

   return ret;
}

static Media_Status vmMFResumeFile( MHdl *hdl )
{
   vmMediaHdl *ihdl = (vmMediaHdl *)hdl;
   Media_Status ret = MEDIA_SUCCESS;

   hdl->start_time = hdl->current_time;
   ihdl->end_status = MEDIA_NONE;

   ASSERT(hdl->state == VM_STATE_PLAY_PAUSE);

   hdl->state = VM_STATE_PLAY;
   hdl->read = 0;
   hdl->write = 0;
   hdl->eof = false;
   ihdl->control = 0;

   // KH: to shorten buffer size
//   if (hdl->rb_size > MAX_DATA_REQUESTED)
//      hdl->rb_size = MAX_DATA_REQUESTED;


#if defined(CACHE_ENABLE)
   if (vmSeek(ihdl)==KAL_FALSE) {
      return MEDIA_SEEK_FAIL;
   }
#else
   FSAL_Seek( ihdl->pstFSAL, ihdl->fileOffset);
#endif

   {
      uint32 buf_len;
      int32 get_len;
      uint8  *pBuf;

      hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
      buf_len &= 0xFFFFFFFE;
      get_len = autGetBytes(hdl, ihdl->pstFSAL, buf_len, pBuf);
      if (get_len < 0) {
         return MEDIA_BAD_FORMAT;
      } else if (get_len < buf_len) {
         hdl->eof = true;
      }
      hdl->WriteDataDone( hdl, get_len );
   }

   mhdlDisallowSleep( hdl );
   ret = vmWriteFrame(hdl, false);

   if (ret == MEDIA_SUCCESS) {
      /* Set Digital Gain for Voice Memo */
      AFE_SetDigitalGain( L1SP_VOICE, 100 );
      KT_StopAndWait();
      TONE_StopAndWait();
      AM_VMPlaybackOn( ihdl->control, ihdl->param );
   }

   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType );

   return ret;
}


static Media_Status vmMFPause( MHdl *hdl )
{
   vmMediaHdl *ihdl = (vmMediaHdl *)hdl;

   ASSERT(hdl->state == VM_STATE_PLAY);

   AM_VMPlaybackOff(ihdl->param);
   mhdlAllowSleep( hdl );
   hdl->state = VM_STATE_PLAY_PAUSE;

   ihdl->end_status = MEDIA_TERMINATED;
   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, hdl->mediaType );

   return MEDIA_SUCCESS;
}


static Media_Status vmMFStop( MHdl *hdl )
{
   vmMediaHdl *ihdl = (vmMediaHdl *)hdl;

   switch (hdl->state) {
      case VM_STATE_IDLE:
      case VM_STATE_PLAY_PAUSE:
         return MEDIA_SUCCESS;
      case VM_STATE_PLAY:
         AM_VMPlaybackOff(ihdl->param);
         mhdlAllowSleep( hdl );
         break;
      default:
         ASSERT(0);
   }

   ihdl->end_status = MEDIA_TERMINATED;
   hdl->state = VM_STATE_IDLE;
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, hdl->mediaType );

   return MEDIA_SUCCESS;
}

static Media_Status vmMFClose( MHdl *hdl )
{
   vmMediaHdl *ihdl = (vmMediaHdl *) hdl;
   ASSERT( (hdl != 0) && (hdl->state != VM_STATE_PLAY) );
   mhdlFinalize( hdl, DP_D2C_SD_DONE );

#if defined(CACHE_ENABLE)
   free_ctrl_buffer( ihdl->AudioCacheTbl );
#endif
   free_ctrl_buffer( hdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, hdl->mediaType );

   return MEDIA_SUCCESS;
}


MHdl *VM_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   vmMediaHdl *ihdl;
   Media_VM_PCM_Param *vm_param = (Media_VM_PCM_Param *) param;

   ihdl = (vmMediaHdl*)get_ctrl_buffer( sizeof(vmMediaHdl) );
   memset(ihdl, 0, sizeof(vmMediaHdl));
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, DP_D2C_SD_DONE, vmHisr );

   hdl->handler   = handler;
   ihdl->pstFSAL  = pstFSAL;
   hdl->mediaType = vm_param->mediaType;
#if IS_EV_BOARD
   ihdl->param  = (uint32)MEDIA_VMP_AS_SPEECH;
#else
   ihdl->param  = vm_param->vmParam;
#endif

   hdl->state     = VM_STATE_IDLE;
   hdl->Close     = vmMFClose;
   hdl->Pause     = vmMFPause;
   hdl->Stop      = vmMFStop;
   hdl->Process   = vmMFProcess;
   hdl->Play      = vmMFPlayFile;
   hdl->Resume    = vmMFResumeFile;
   FSAL_GetFileSize( ihdl->pstFSAL, &ihdl->file_size);
   ihdl->validLen = ihdl->file_size;

#if defined(CACHE_ENABLE)
   // Initialize the audio cache table for random access
   ihdl->AudioCacheTbl = (AudioCacheTable*)get_ctrl_buffer( sizeof(AudioCacheTable) );
   memset(ihdl->AudioCacheTbl, 0, sizeof(AudioCacheTable));

   // Initial cache table for VRD
   if (hdl->mediaType == MEDIA_FORMAT_VRD) {
      ihdl->cacheOffset = 18;
      ihdl->lastCacheOffset = 18;
      ihdl->AudioCacheTbl->accumulateOffset[0] = 18;
   }
#endif

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, hdl->mediaType );

   return hdl;
}

static Media_Status vmGetFirstFrameContent(vmMediaHdl *ihdl, audInfoStruct *contentInfo, Media_Format eFormat)
{
   uint32 file_size;  // in byte
   MHdl *hdl;

   hdl = (MHdl *) ihdl;

   FSAL_GetFileSize( ihdl->pstFSAL, &file_size);

   // VRD parser
   if (eFormat == MEDIA_FORMAT_VRD){
      uint32 dummy_32;
      int32  get_len;
      uint8 *pData;

      ihdl->headerOffset = 18;
      pData = &ihdl->buf[0];
      get_len = autGetBytes(hdl, ihdl->pstFSAL, 18, pData);
      ihdl->fileOffset += 18;
      if (get_len < 18) {
         return MEDIA_BAD_FORMAT;
      }

      LoadDWORD(dummy_32, pData);
      if ( (dummy_32 != 0x564B544D) && (dummy_32 != 0x56425943) )
         return MEDIA_BAD_FORMAT;

      pData += 6;
      LoadDWORD(dummy_32, pData);
      if (dummy_32 != 0x45434F56)
         return MEDIA_BAD_FORMAT;

      LoadDWORD(file_size, pData);
   }

   // Parse the first frame
   {
      uint16 control, sc_mode, sd_mode, data_len, debug_data_len = 0;
      uint8  *pBuf;

      data_len = 0;
      pBuf = &ihdl->buf[0];

      while( 1 ) {
         if( eFormat != MEDIA_FORMAT_VRD && eFormat != MEDIA_FORMAT_VRSI) {
#if defined( VM_LOG_DEBUG )
            data_len = 3;
            do {
               if ( autGetBytes(hdl, ihdl->pstFSAL, 2, pBuf) != 2)
                  return MEDIA_BAD_FORMAT;

               control = *(uint16 *)pBuf;
            } while( control != 0xAA55 );
            if ( autGetBytes(hdl, ihdl->pstFSAL, 2, pBuf) != 2)//format
               return MEDIA_BAD_FORMAT;
            debug_data_len = *(uint16 *)pBuf >> 6;
            if ( autGetBytes(hdl, ihdl->pstFSAL, 4, pBuf) != 4)
               return MEDIA_BAD_FORMAT;
#endif
            if ( autGetBytes(hdl, ihdl->pstFSAL, 2, pBuf) != 2)
               return MEDIA_BAD_FORMAT;

            control = *(uint16 *)pBuf;

            if( (control&3) == 0 )
               continue;
         }
         else
            control = 0x401;

         sc_mode = (control >> VM_CTRL_SC_START) & 0x0F;
         sd_mode = (control >> VM_CTRL_SD_START) & 0x0F;
   #if !defined(MT6205B)
         if( sc_mode != sd_mode && (sc_mode <= 2 || sd_mode <= 2) )
            continue;
   #else
         if( sc_mode > 2 || sc_mode != sd_mode )
            continue;
   #endif
         break;
      }

      if (control & VM_CTRL_UL)
         data_len += AM_GetSpeechPatternLength(sc_mode);

      if (control & VM_CTRL_DL)
         data_len += AM_GetSpeechPatternLength(sd_mode);

#if defined( VM_LOG_DEBUG )
      //if( sd_mode>2 && sd_mode<11 && (control & VM_CTRL_DL) )
      if( debug_data_len > 0 )
         data_len += ( debug_data_len << 1 );
#endif

      contentInfo->bitRate = data_len * 800;

      if (data_len)
         contentInfo->time = 20 * (file_size / data_len);
   }
   return MEDIA_SUCCESS;
}

Media_Status VM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )
{
   vmMediaHdl *ihdl;
   MHdl *hdl;
   Media_Format eFormat;
   Media_Status ret = MEDIA_SUCCESS;

   ihdl = (vmMediaHdl*)get_ctrl_buffer( sizeof(vmMediaHdl) );
   memset(ihdl, 0, sizeof(vmMediaHdl));
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, 0xFFFF, vmHisr );
   ihdl->pstFSAL = pstFSAL;
   eFormat = *(Media_Format *) param;

   contentInfo->title[0]  = '\0';
   contentInfo->artist[0] = '\0';
   contentInfo->album[0]  = '\0';
   contentInfo->time = 0;
   contentInfo->bitRate = 0;
   contentInfo->sampleRate = 8000;
   contentInfo->stereo = false;

   ret = vmGetFirstFrameContent(ihdl, contentInfo, eFormat);

   mhdlFinalize( hdl, 0xFFFF );
   free_ctrl_buffer( ihdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, eFormat );
   return ret;
}
