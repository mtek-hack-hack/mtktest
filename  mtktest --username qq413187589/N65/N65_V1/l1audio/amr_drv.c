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
 * amr_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   AMR/AMR-WB codec driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"
#include "fsal.h"
#include "l1sp_trc.h"


#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)

#include "amr_table.h"
#include "am.h"
#include "afe.h"

static const kal_uint16 AMR_BitRate[]={
   4750, 5150, 5900, 6700, 7400, 7950, 10200, 12200};
#if defined(AMRWB_DECODE)
static const kal_uint16 AMRWB_BitRate[]={
   6600, 8850, 12650, 14250, 15850, 18250, 19850, 23050, 23850};
#endif

#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DSP_IDLE              0
#define DSP_INITIALIZED       1
#define DSP_PLAYING           2
#define DSP_STOP              3
#endif // AWB state machine

#define AMR_STATE_PLAY        1
#define AMR_STATE_PAUSE       2
#define AMR_STATE_IDLE        3

#define MAX_DATA_REQUESTED    1024
#define FRAMES_PER_SEC        50
#define FRAME_DURATION        20

#define HEADER_OK             0
#define HEADER_NO_DATA_FRAME  1
#define HEADER_ERROR          2

#define MAX_CACHE_ENTRIES     254

typedef struct {
   kal_uint32 start_offset[MAX_CACHE_ENTRIES];
   kal_uint32 accumulated_frames[MAX_CACHE_ENTRIES];
   kal_uint32 total_frame;
   kal_uint16 frames_per_cache;
   kal_uint16 valid_cache_number;
   kal_uint16 current_cache_index;
} AudioCacheTable;

typedef struct amrVar{
   kal_uint32        vm;
   kal_bool          bWideBand;
   kal_uint8         bCodecMode; /* Codec Mode for DSP Sherif Setting */
} amrInternal;

typedef struct mh_internal {
   MHdl              mh;
   amrInternal       amr;
   STFSAL            *pstFSAL;
   audInfoStruct     *description;
   Media_Event       end_status;
   kal_uint16        Tx_ordering_buffer[30];
   kal_uint16        Tx_data_buffer[30];
   kal_uint32        fileOffset;
   kal_uint32        lastFrameOffset;
   kal_uint32        uFileSize;
   kal_uint32        uDurUpdateThd;
   kal_uint8         buf[MAX_DATA_REQUESTED];
   AudioCacheTable   *AudioCacheTbl;
} amrMediaHdl;

static kal_int32 amrGetBytesFromFile(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr)
{
   kal_uint32 file_size, data_size;

   FSAL_GetFileSize(pstFSAL, &file_size);
   data_size = file_size - fileOffset;
   if(data_size <= num_bytes)
      num_bytes = data_size;

   FSAL_Seek( pstFSAL, fileOffset);
   if(FSAL_Read_Bytes( pstFSAL, ptr, num_bytes) != FSAL_OK)
      return -1;

   return num_bytes;
}

static void media_playback_error(amrMediaHdl *ihdl)
{
   ihdl->end_status = MEDIA_ERROR;
   mhdlException( (MHdl*)ihdl, MEDIA_ERROR );
}

static kal_uint8 media_buffer_get_byte(amrMediaHdl *ihdl)
{
   if (ihdl->mh.read != ihdl->mh.write) {
   	kal_uint8 wVal = ihdl->mh.rb_base[ihdl->mh.read++];
      if (ihdl->mh.read >= ihdl->mh.rb_size)
         ihdl->mh.read = 0;
      return wVal;
   }
   ASSERT(ihdl->mh.read != ihdl->mh.write);   /* media ring buffer underflow */
   return 0;
}

static kal_uint8 media_buffer_peek_byte(amrMediaHdl *ihdl)
{
   if (ihdl->mh.read != ihdl->mh.write) {
      return ihdl->mh.rb_base[ihdl->mh.read];
   }
   ASSERT( ihdl->mh.read != ihdl->mh.write );   /* media ring buffer underflow */
   return 0;
}

static void media_buffer_get_nbytes(amrMediaHdl *ihdl, kal_uint8 *buf, kal_uint32 uLen)
{
   kal_uint32 i=0;
   ASSERT(buf!=NULL);
   while(uLen-->0) {
      buf[i++] = media_buffer_get_byte(ihdl);
   }
}

static void amr_write_speech_mode_to_dsp( amrMediaHdl *ihdl, kal_uint8 bTxType)
{
#if defined(AMRWB_DECODE)
   if (KAL_TRUE == ihdl->amr.bWideBand) {
      *DP_SD2_AWB_VM_0 = (ihdl->amr.bCodecMode << 8) | bTxType; /* codec mode | Tx-Type */
   } else
#endif
   {
      *DP_SD2_VM_17 = ihdl->amr.bCodecMode;
      *DP_SD2_VM_0 = bTxType;
   }
}

static void amr_write_speech_data_to_dsp(amrMediaHdl *ihdl, kal_uint16 *pwData, kal_uint16 bLen)
{
   volatile kal_uint16 *pwSherifAddr;
   kal_uint8 i;
#if defined(AMRWB_DECODE)
   if (KAL_TRUE==ihdl->amr.bWideBand) {
      pwSherifAddr = DP_SD2_AWB_VM_1;
      if (bLen>17) {
         for(i=0; i<17; i++) {
   	    *pwSherifAddr++ = *pwData++;
   	 }
   	 pwSherifAddr = DP_SD2_AWB_VM_18;
   	 for(; i< bLen; i++) {
   	    *pwSherifAddr++ = *pwData++;
   	 }
      } else {
         for(i=0; i < bLen; i++ )
         *pwSherifAddr++ = *pwData++;
      }
   } else
#endif
   {
      pwSherifAddr = DP_SD2_VM_1;
      for (i = 0; i < bLen; i++)
         *pwSherifAddr++ = *pwData++;
   }
}

static void amr_bit_ordering_file_to_sherif(amrMediaHdl *ihdl, kal_uint8 bTxType, kal_uint8 bFrameType, kal_uint16* pInData, kal_uint16* pOutData, kal_uint16 wLenBits)
{
   kal_uint16 i, k, p, q;

   k = 0;
#if defined(AMRWB_DECODE)
   if (KAL_TRUE == ihdl->amr.bWideBand) {
      const kal_uint16* pOrderingTable = tblAMR_WBOrder[bFrameType];
      for(i=0, p=0, q=0; i<wLenBits; i++){
         if (bTxType==2) { /* Speech */
      	    k = (kal_uint16)pOrderingTable[i];
         } else if (bTxType==3) { /* SID first or SID update */
            k=i;
         } else {ASSERT(KAL_FALSE);}
         pOutData[k/16] |= (pInData[q] & AMR_ord_tab[p]) ? AMR_get_tab[k%16] : 0;
         if(++p==16) { p=0; q++; }
      }
   } else
#endif
   {
      const kal_uint8* pOrderingTable = tblAMROrder[bFrameType];
      for(i=0, p=0, q=0; i<wLenBits; i++){
         if (bTxType==2) { /* Speech */
      	    k = (kal_uint16)pOrderingTable[i];
         } else if (bTxType==3) { /* SID first or SID update */
            k=i;
         } else {ASSERT(KAL_FALSE);}
         pOutData[k/16] |= (pInData[q] & AMR_ord_tab[p]) ? AMR_get_tab[k%16] : 0;
         if(++p==16) { p=0; q++; }
      }
   }
}

static kal_uint32 amrChkFrameHeader( amrMediaHdl *ihdl, kal_uint8  bFrameHeader, kal_uint8 *Tx_Type, kal_uint16 *lenSherifData, kal_uint16 *rd_bits )
{
   kal_uint8  FT, FQI;
   FT = (bFrameHeader >> 3) & 0x0F;
   FQI = (bFrameHeader >> 2) & 0x01;

   if (FT<=7) { /* AMR 4.75 ~ 12.2 kbps */
      ihdl->amr.bCodecMode = FTtoSCM_AMR[FT];
      *rd_bits = lenSpeechBitsAMR[FT];
      *Tx_Type = 2;
      *lenSherifData = (*rd_bits+15)/16;
   } else if (FT==8) { /* AMR SID */
      *rd_bits = lenSpeechBitsAMR[FT];
      *Tx_Type = 3;
      *lenSherifData = 3;
   } else if (FT>=9 && FT<=14) { /* GSM/TDMA/PDC SID and 'for-future-use' mode */
      return HEADER_ERROR;
   } else if (FT==15) { /* No_Data*/
   	*rd_bits = 0;
   	*lenSherifData = 0;
      *Tx_Type = 0;
      return HEADER_NO_DATA_FRAME;
   }
   return HEADER_OK;
}

#if defined(AMRWB_DECODE)
static kal_int32 amrWBChkFrameHeader( amrMediaHdl *ihdl, kal_uint8  bFrameHeader, kal_uint8 *Tx_Type, kal_uint16 *lenSherifData, kal_uint16 *rd_bits )
{
   kal_uint8  FT, FQI;
   FT = (bFrameHeader >> 3) & 0x0F;
   FQI = (bFrameHeader >> 2) & 0x01;

   if (FT<=8) { /* AMR-WB 6.60 kbps ~ 23.85 kbps */
      *Tx_Type = 2;
      ihdl->amr.bCodecMode = FTtoSCM_AMR_WB[FT];
      *rd_bits = lenSpeechBitsAMR_WB[FT];
      *lenSherifData = (*rd_bits+15)/16;
   } else if (FT==9) { /* AMR-WB SID */
      *Tx_Type = 3;
      *rd_bits = lenSpeechBitsAMR_WB[FT];
      *lenSherifData = 3;
   } else if (FT==14) { /* SPEECH_LOST */
      if (FQI==0) {
         *rd_bits = 0;
         *lenSherifData = 0;
         *Tx_Type = 0;
      } else {
         return HEADER_ERROR; /* undefined situation */
      }
   } else if (FT==15) { /* NO_DATA */
      *rd_bits = 0;
      *lenSherifData = 0;
      *Tx_Type = 0;
      return HEADER_NO_DATA_FRAME;
   } else { /* 'for-future-use' mode */
   	 return HEADER_ERROR;
   }
   return HEADER_OK;
}

#endif

static void amrProcessCache(amrMediaHdl *ihdl, kal_int32 processCacheCnt)
{
   kal_uint32  i, k, uCurPos, frames_per_cache, valid_cache_number, current_cache_index, temp_offset;
   kal_uint32  uOffset;
   kal_int32   uCnt, uFrameCnt;

   kal_uint8 *pBuf;
   kal_uint32 buf_len;
   ihdl->mh.GetWriteBuffer((MHdl *)ihdl, &pBuf, &buf_len);

   current_cache_index = (kal_uint32)ihdl->AudioCacheTbl->current_cache_index;
   valid_cache_number = (kal_uint32)ihdl->AudioCacheTbl->valid_cache_number;
   frames_per_cache = (kal_uint32)ihdl->AudioCacheTbl->frames_per_cache;
   temp_offset = ihdl->AudioCacheTbl->start_offset[current_cache_index];

   if(current_cache_index == valid_cache_number-1){
	   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FINISH_RETURN, MEDIA_FORMAT_AMR );
	   return; // cache table finished
	}

   FSAL_GetCurPos(ihdl->pstFSAL, &uCurPos);

   uCnt = 0;
   uFrameCnt = 0;
   uOffset = 0;
   for (i=processCacheCnt; i != 0; i--) {
	   for (k=0; k < frames_per_cache; k++){
		    kal_uint32 uHeader;
                     /* decode frame header */
          if(!uCnt){
		       if( (uCnt = amrGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, temp_offset, buf_len, pBuf)) < 0){
		          valid_cache_number = current_cache_index + 1;
			       FSAL_Seek( ihdl->pstFSAL, uCurPos);
                ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
                ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
                ihdl->AudioCacheTbl->total_frame += uFrameCnt;
                kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_END, MEDIA_FORMAT_AMR, ihdl->AudioCacheTbl->total_frame);
                return;
		       }
		    }

		    uHeader = (kal_uint32)*(pBuf+uOffset);

#if defined(AMRWB_DECODE)
          if (MEDIA_FORMAT_AMR_WB == ihdl->mh.mediaType) {
             {
                kal_uint32  FT, FQI;
                FT = (uHeader >> 3) & 0x0F;
                FQI = (uHeader >> 2) & 0x01;

                if (FT<=9) { /* AMR-WB 6.60 kbps ~ 23.85 kbps */ /* AMR-WB SID */
                   uOffset += (((kal_uint32)lenSpeechBitsAMR_WB[FT]+7)>>3) + 1;
                } else if (FT==14) { /* SPEECH_LOST */
                   if (FQI==0) {
                      uOffset += 1;
                   } else {
                        valid_cache_number = current_cache_index + 1;
                        FSAL_Seek( ihdl->pstFSAL, uCurPos);
                        ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
                        ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
                        ihdl->AudioCacheTbl->total_frame += uFrameCnt;
                        kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FAILED, MEDIA_FORMAT_AMR, ihdl->AudioCacheTbl->total_frame );
                        return;
                   }
                } else if (FT==15) { /* NO_DATA */
                      uOffset += 1;
                } else { /* 'for-future-use' mode */
                     valid_cache_number = current_cache_index + 1;
                	   FSAL_Seek( ihdl->pstFSAL, uCurPos);
                     ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
                     ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
                     ihdl->AudioCacheTbl->total_frame += uFrameCnt;
                     kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FAILED, MEDIA_FORMAT_AMR, ihdl->AudioCacheTbl->total_frame );
                     return;
                }
             }
		    }else
#endif
		    {
             {
                kal_uint32  FT, FQI;
                FT = (uHeader >> 3) & 0x0F;
                FQI = (uHeader >> 2) & 0x01;

                if (FT<=8) { /* AMR 4.75 ~ 12.2 kbps */ /* AMR SID */
                   uOffset += (((kal_uint32)lenSpeechBitsAMR[FT]+7)>>3) + 1;
                } else if (FT>=9 && FT<=14) { /* GSM/TDMA/PDC SID and 'for-future-use' mode */
                    valid_cache_number = current_cache_index + 1;
                    FSAL_Seek( ihdl->pstFSAL, uCurPos);
                    ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
                    ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
                    ihdl->AudioCacheTbl->total_frame += uFrameCnt;
                    kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FAILED, MEDIA_FORMAT_AMR, ihdl->AudioCacheTbl->total_frame );
                    return;
                } else if (FT==15) { /* No_Data*/
                	    uOffset += 1;
                }
             }
		    }
		    uFrameCnt++;
		    if(uOffset >= uCnt){
		       temp_offset += uOffset;
		       uCnt = 0;
		       uOffset = 0;
		    }
	   }
      if(current_cache_index){
         ihdl->AudioCacheTbl->accumulated_frames[current_cache_index]=
		   ihdl->AudioCacheTbl->accumulated_frames[current_cache_index-1]+k;
		   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_ACCFRAME, MEDIA_FORMAT_AMR, current_cache_index, ihdl->AudioCacheTbl->accumulated_frames[current_cache_index-1]+k );
		}else{
         ihdl->AudioCacheTbl->accumulated_frames[0]= k;
         kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_ACCFRAME, MEDIA_FORMAT_AMR, 0, k );
      }
		if(current_cache_index != valid_cache_number-1){
         ihdl->AudioCacheTbl->start_offset[++current_cache_index]=temp_offset+uOffset;
         kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, MEDIA_FORMAT_AMR, current_cache_index, temp_offset+uOffset );
      }

   }
   FSAL_Seek( ihdl->pstFSAL, uCurPos);
   ihdl->AudioCacheTbl->current_cache_index = (kal_uint16)current_cache_index;
   ihdl->AudioCacheTbl->valid_cache_number = (kal_uint16)valid_cache_number;
   ihdl->AudioCacheTbl->total_frame = ihdl->AudioCacheTbl->accumulated_frames[current_cache_index-1];
}

static void amrHisr( void *data )
{
   kal_int32  uBytesAvailable;
   kal_uint16 rd_bytes, lenSherifData, rd_bits;
   kal_uint8  bFrameHeader, FT, Tx_Type;

   amrMediaHdl *ihdl = (amrMediaHdl *)data;

   if (ihdl->mh.state != AMR_STATE_PLAY || ihdl->end_status == MEDIA_END
       || ihdl->end_status == MEDIA_ERROR || ihdl->end_status == MEDIA_TERMINATED)
      return;

   /* check ring buffer emptiness */
   uBytesAvailable = ihdl->mh.GetDataCount((MHdl *)ihdl);
   uBytesAvailable --;  /* 1 byte for header */

   if (uBytesAvailable < 1) {
      /* media buffer underflows */
      /* stuff 'no-data' frame */
      amr_write_speech_mode_to_dsp( ihdl, 0 );
      if (ihdl->mh.eof) {
         ihdl->end_status = MEDIA_END;
         mhdlException( (MHdl*)ihdl, MEDIA_END );
      }
      return;
   }

   /* decode frame header */
   bFrameHeader = media_buffer_peek_byte( ihdl );
   FT = (bFrameHeader >> 3) & 0x0F;

#if defined(AMRWB_DECODE)
   if (KAL_TRUE==ihdl->amr.bWideBand) {
      /* If the codec mode are not right, DSP may mal-function */
      EXT_ASSERT((((((*DP_SD2_AWB_VM_0)>>8)&0xFF)>=0x20) &&
        ((((*DP_SD2_AWB_VM_0)>>8)&0xFF)<=0x28)), (*DP_SD2_AWB_VM_0), 0, 0);

      {
         kal_int32 ret;
         ret = amrWBChkFrameHeader( ihdl, bFrameHeader, &Tx_Type, &lenSherifData, &rd_bits );
         if(ret == HEADER_ERROR){
            media_playback_error(ihdl);
            return;
         }else if(ret == HEADER_NO_DATA_FRAME){
             media_buffer_get_byte(ihdl);   /* consume the header byte */
             ihdl->mh.current_time += 20;
             ihdl->lastFrameOffset += 1;
             amr_write_speech_mode_to_dsp(ihdl, Tx_Type);
             return;
          }
      }

   } else
#endif
   {
      /* If the codec mode are not right, DSP may mal-function */
      EXT_ASSERT(((*DP_SD2_VM_17>=0x03) && (*DP_SD2_VM_17<=0x0A)), (*DP_SD2_VM_17), 0, 0);
      {
         kal_uint32 ret;
         ret = amrChkFrameHeader( ihdl, bFrameHeader, &Tx_Type, &lenSherifData, &rd_bits );
         if(ret == HEADER_ERROR){
            media_playback_error(ihdl);
            return;
         }else if(ret == HEADER_NO_DATA_FRAME){
             media_buffer_get_byte(ihdl);   /* consume the header byte */
             ihdl->mh.current_time += 20;
             ihdl->lastFrameOffset += 1;
             amr_write_speech_mode_to_dsp(ihdl, Tx_Type);
             return;
          }
      }
   }

   /* check buffer underflow */
   rd_bytes = (rd_bits+7)>>3;
   if (rd_bytes > uBytesAvailable) {
      amr_write_speech_mode_to_dsp( ihdl, 0 );
      if (ihdl->mh.eof) {
         ihdl->end_status = MEDIA_END;
         mhdlException( (MHdl*)ihdl, MEDIA_END );
      }
      return;
   }

   if(ihdl->mh.current_time >= ihdl->mh.stop_time) {
      ihdl->end_status = MEDIA_END;
      mhdlException( (MHdl*)ihdl, MEDIA_STOP_TIME_UP );
      return;
   }

   ihdl->mh.current_time += 20;
   ihdl->lastFrameOffset += (rd_bytes+1);
   if(ihdl->AudioCacheTbl != 0){  // update cache table
      kal_uint32 uAcumFrms, uTotalFrames, uCurCacheIdx;
      uCurCacheIdx = ihdl->AudioCacheTbl->current_cache_index;
      if(uCurCacheIdx)
         uAcumFrms = ihdl->AudioCacheTbl->accumulated_frames[uCurCacheIdx-1];
      else
         uAcumFrms = 0;

      uTotalFrames = ihdl->mh.current_time / FRAME_DURATION;

      if((uTotalFrames-uAcumFrms)==ihdl->AudioCacheTbl->frames_per_cache){
         if(uCurCacheIdx){
            ihdl->AudioCacheTbl->accumulated_frames[uCurCacheIdx] = uTotalFrames;
            kal_prompt_trace( MOD_L1SP, " AMR: Cache_AccFrame = %d, idx = %d", uTotalFrames, uCurCacheIdx);
	      }else{
            ihdl->AudioCacheTbl->accumulated_frames[0]= uTotalFrames;
            kal_prompt_trace( MOD_L1SP, " AMR: Cache_AccFrame = %d, idx = %d", uTotalFrames, 0);
         }
	      if(uCurCacheIdx != ihdl->AudioCacheTbl->valid_cache_number-1){
            ihdl->AudioCacheTbl->start_offset[++uCurCacheIdx]=ihdl->lastFrameOffset;
            kal_prompt_trace( MOD_L1SP, " AMR: Cache_StrOffset = %d, idx = %d", ihdl->lastFrameOffset, uCurCacheIdx);
            ihdl->AudioCacheTbl->current_cache_index = uCurCacheIdx;
            ihdl->AudioCacheTbl->total_frame = ihdl->AudioCacheTbl->accumulated_frames[uCurCacheIdx-1];
         }
      }
   }

   media_buffer_get_byte(ihdl);   /* consume the header byte */
   /* get speech data from ring buffer */
   media_buffer_get_nbytes( ihdl, (kal_uint8*)ihdl->Tx_ordering_buffer, rd_bytes);

   /* bits re-ordering */
   kal_mem_set(ihdl->Tx_data_buffer, 0, sizeof(ihdl->Tx_data_buffer));
   amr_bit_ordering_file_to_sherif(ihdl, Tx_Type, FT, ihdl->Tx_ordering_buffer, ihdl->Tx_data_buffer, rd_bits);

   if (Tx_Type==3) { /* SID first or SID update */
      ihdl->Tx_data_buffer[2]&=0x00E0;
      if((ihdl->Tx_ordering_buffer[2]&0x0010)==0)   /* STI */
         Tx_Type = 1; /* SID first */
   }

   /* write speech frame to sherif */
   amr_write_speech_mode_to_dsp(ihdl, Tx_Type);
   amr_write_speech_data_to_dsp(ihdl, ihdl->Tx_data_buffer, lenSherifData);

   mhdlDataRequest((MHdl*)ihdl, ihdl->end_status);
}

static kal_uint16 amr_SetAndGetInitialCodecMode( amrMediaHdl *ihdl )
{
   kal_uint16 wInitialCodecMode;

#if defined(AMRWB_DECODE)
   if (KAL_TRUE == ihdl->amr.bWideBand) {
      ihdl->amr.bCodecMode = 0x20;
      wInitialCodecMode = (0x20<<2);
   } else
#endif
   {
      ihdl->amr.bCodecMode = 0x03;
      wInitialCodecMode = (0x03<<2) | (0x03<<6);
   }
   return wInitialCodecMode;
}

#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
static void amr_WBStopCtrl( amrMediaHdl *ihdl, bool isPlayback )
{
   kal_uint16  I, ctl;
   volatile kal_uint16* ptr;

   ptr = ((isPlayback == true )?DP_AWB_SD_CTRL:DP_AWB_SE_CTRL);

   if(*ptr == DSP_PLAYING){
      ihdl->mh.state = AMR_STATE_IDLE;
      *ptr = DSP_STOP;
      kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
   }
   for( I = 0; ; I++ ) {
      ctl = *ptr;
      if( ctl == DSP_IDLE ){                /* DSP returns to idle state */
         kal_trace( TRACE_STATE, L1AUDIO_IDLE_STATE );
         break;
      }
      ASSERT_REBOOT( I < 20 );
      kal_sleep_task( 2 );
   }
}
#endif
#endif

static void amrOpenDevice( amrMediaHdl *ihdl , kal_uint16 wCodecMode)
{
   ihdl->end_status = MEDIA_NONE;
   mhdlDisallowSleep( (MHdl*)ihdl );

   KT_StopAndWait();

#if AMR_AWB_AUDIO_PATH_SUPPORT
   {
      uint16 control = wCodecMode ;
      uint32 style = ihdl->amr.vm;
      uint32 vm_control  = (style<<16) | control;
      uint16 sc_mode, sd_mode;
      uint16 codec_mode;
      uint16 amr_sd_mode = (control&0x3C) >> 2;
      uint16 awb_sd_mode = (control&0xFC) >> 2;
      uint16 samplingrate;
      /* Set Digital Gain for AMR/AMR-WB */
      AFE_SetDigitalGain( L1SP_AUDIO, ihdl->mh.volume_level );

      if( ((0x03<=amr_sd_mode) && (0x0A>=amr_sd_mode))){ // AMR
         DSP_DynamicDownload( DDID_AMRSBC );
         codec_mode = ASP_TYPE_AMR;
         sc_mode = (vm_control>>2) & 0xF;
         sd_mode = (vm_control>>6) & 0xF;
         samplingrate = ASP_FS_8K;
      }
#if defined(AMRWB_DECODE)
      else if ((0x20<=awb_sd_mode) && (0x28>=awb_sd_mode)){  // AWB
          DSP_DynamicDownload(DDID_AWBDEC);
          codec_mode = ASP_TYPE_AWBDEC;
          sc_mode = (vm_control>>2) & 0xFF;
          sd_mode = 0;
          samplingrate = ASP_FS_16K;
      }
#endif
      if( sc_mode == 0 )
         sc_mode = sd_mode;
      if( sd_mode == 0 )
         sd_mode = sc_mode;

      *AMR_AWB_AUDIO_PATH_CTRL = 0x40;
      if( sc_mode > 2){
         *AMR_PARAM1 = 0x1622;
      }else{
          *AMR_PARAM1 = 0x2622;
      }
      *AMR_PARAM2 = sd_mode | (sc_mode << 8);
      *DP_AUDIO_FLEXI_CTRL = 0x5;
      AM_AudioPlaybackOn( codec_mode, samplingrate);
   }
#else // AMR_AWB_AUDIO_PATH_SUPPORT
   /* Set Digital Gain for AMR/AMR-WB */
   AFE_SetDigitalGain( L1SP_VOICE, ihdl->mh.volume_level );
   AM_VMPlaybackOn( wCodecMode, ihdl->amr.vm);
#endif

   ihdl->mh.state = AMR_STATE_PLAY;

#if defined(AMRWB_DECODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
   if (MEDIA_FORMAT_AMR_WB == ihdl->mh.mediaType ){
      kal_uint32 I;
      kal_uint16 ctl;
      volatile kal_uint16* ptr;

      *DP_AWB_SD_CTRL = DSP_INITIALIZED;
      ptr = DP_AWB_SD_CTRL;
      for( I = 0; ; I++ ) {
         ctl = *ptr;
         if( ctl == DSP_PLAYING ){                /* DSP returns to idle state */
            kal_trace( TRACE_STATE, L1AUDIO_RUNNING_STATE );
            break;
         }
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
#endif

#if AMR_AWB_AUDIO_PATH_SUPPORT
   {
      kal_uint32 uCnt;
      for( uCnt = 0; ; uCnt++ ) {
         if( *AMR_AWB_AUDIO_PATH_CTRL == 0 ){
            break;
         }
         ASSERT_REBOOT( uCnt < 20 );
         kal_sleep_task( 2 );
      }
   }
#endif // AMR_AWB_AUDIO_PATH_SUPPORT

}

static void amrCloseDevice( amrMediaHdl *ihdl )
{
#if defined(AMRWB_DECODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
   if(ihdl->amr.bWideBand)
      amr_WBStopCtrl( ihdl, true );
#endif

#if AMR_AWB_AUDIO_PATH_SUPPORT
   *DP_AUDIO_FLEXI_CTRL = 0;
   AM_AudioPlaybackOff( true );
#else // AMR_AWB_AUDIO_PATH_SUPPORT
   AM_VMPlaybackOff(ihdl->amr.vm);
#endif
   mhdlAllowSleep( (MHdl*)ihdl );
}

static kal_bool amrChkFileHeader( amrMediaHdl *ihdl )
{
   kal_uint8 AMR_Header[9];
   /* check amr-wb file header */
   if(amrGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, ihdl->fileOffset, 9, AMR_Header) != 9)
      return KAL_FALSE;
#if defined(AMRWB_DECODE)
   if (memcmp(AMR_Header, "#!AMR-WB\n", 9)==0){
      ihdl->mh.mediaType = MEDIA_FORMAT_AMR_WB;
      ihdl->fileOffset += 9;
   }else
#endif
   {
      if(memcmp(AMR_Header, "#!AMR\n", 6)!=0)
         return KAL_FALSE;
      ihdl->mh.mediaType = MEDIA_FORMAT_AMR;
      ihdl->fileOffset += 6;
   }

   return KAL_TRUE;
}

static Media_Status amrMFClose( MHdl *hdl )
{
   ASSERT( hdl != 0 && hdl->state != AMR_STATE_PLAY);
   if( hdl->handler != NULL )
      mhdlFinalize( hdl, DP_D2C_SD_DONE );


   free_ctrl_buffer( hdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static kal_bool amrSeek( amrMediaHdl *ihdl, kal_bool cacheEnable )
{
   kal_int32 cnt, startFrame;
   kal_uint16 lenSherifData, rd_bits;
   kal_uint8  FT, Tx_Type, FQI;
   kal_uint32 ret;

   startFrame = ihdl->mh.start_time / FRAME_DURATION; // calculate the first frame number

   /// Process cache table
   if((ihdl->AudioCacheTbl != 0) && cacheEnable){
      kal_uint16 start_index, end_index;
      start_index = 0;
      end_index = ihdl->AudioCacheTbl->current_cache_index;
      /// Binary Search
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index + end_index) / 2;
         if (startFrame > (kal_int32)ihdl->AudioCacheTbl->accumulated_frames[middle_index])
            start_index = middle_index;
         else
            end_index = middle_index;
      }
      /// Linear Search
      if (start_index) {
         cnt = ihdl->AudioCacheTbl->accumulated_frames[start_index];
      } else {
         cnt = 0;
      }

      {
         kal_uint32 uOffset;
   	   kal_int32  uCnt;

         kal_uint8 *pBuf;
         kal_uint32 buf_len;
         kal_uint32 temp_offset;

         if(start_index)
	         temp_offset = ihdl->AudioCacheTbl->start_offset[start_index+1];
	      else
	         temp_offset = ihdl->AudioCacheTbl->start_offset[0];

         ihdl->mh.read = 0;
         ihdl->mh.write = 0;
         ihdl->mh.GetWriteBuffer((MHdl *)ihdl, &pBuf, &buf_len);

         uCnt = 0;
         uOffset = 0;
         for(; cnt < startFrame; cnt++)
         {
            kal_uint32 uHeader;
                     /* decode frame header */
            if(!uCnt){ // Load data from storage
               if( (uCnt = amrGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, temp_offset, buf_len, pBuf)) < 0){
                  break;
               }
            }
            uHeader = (kal_uint32) *(pBuf+uOffset);

#if defined(AMRWB_DECODE)
            if (MEDIA_FORMAT_AMR_WB == ihdl->mh.mediaType) {

                {
                   kal_uint32  FT, FQI;
                   FT = (uHeader >> 3) & 0x0F;
                   FQI = (uHeader >> 2) & 0x01;

                   if (FT<=9) { /* AMR-WB 6.60 kbps ~ 23.85 kbps */ /* AMR-WB SID */
                      uOffset += (((kal_uint32)lenSpeechBitsAMR_WB[FT]+7)>>3) + 1;
                   } else if (FT==14) { /* SPEECH_LOST */
                      if (FQI==0) {
                         uOffset += 1;
                      } else {
                           break;
                      }
                   } else if (FT==15) { /* NO_DATA */
                      uOffset += 1;
                   } else { /* 'for-future-use' mode */
                        break;
                   }
                }
   			} else
#endif
            {
               kal_uint32  FT, FQI;
               FT = (uHeader >> 3) & 0x0F;
               FQI = (uHeader >> 2) & 0x01;

               if (FT<=8) { /* AMR 4.75 ~ 12.2 kbps */ /* AMR SID */
                  uOffset += (((kal_uint32)lenSpeechBitsAMR[FT]+7)>>3) + 1;
               } else if (FT>=9 && FT<=14) { /* GSM/TDMA/PDC SID and 'for-future-use' mode */
                    break;
               } else if (FT==15) { /* No_Data*/
               	    uOffset += 1;
               }
            }
            if(uOffset >= uCnt){
               temp_offset += uOffset;
               uCnt = 0;
               uOffset = 0;
            }
         }
	      ihdl->fileOffset = temp_offset + uOffset;
	      ihdl->lastFrameOffset = temp_offset + uOffset; // last frame offset aligned frame boundary
      }
   } else {
	   kal_uint32 tmpFileOffset = ihdl->fileOffset;

      for(cnt=0; cnt < startFrame; cnt++)
      {
                     /* decode frame header */
            if(amrGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, tmpFileOffset, 1, &ihdl->buf[0]) != 1)
               break;
            FT = (ihdl->buf[0] >> 3) & 0x0F;
            FQI = (ihdl->buf[0] >> 2) & 0x01;

#if defined(AMRWB_DECODE)
            if (MEDIA_FORMAT_AMR_WB == ihdl->mh.mediaType) {
               ret = amrWBChkFrameHeader( ihdl, ihdl->buf[0], &Tx_Type, &lenSherifData, &rd_bits );
               if(ret == HEADER_ERROR) break;
			} else
#endif
			{
               ret = amrChkFrameHeader( ihdl, ihdl->buf[0], &Tx_Type, &lenSherifData, &rd_bits );
               if(ret == HEADER_ERROR) break;
			}
            if(ret == HEADER_NO_DATA_FRAME)
               tmpFileOffset += 1;
            else
               tmpFileOffset += ((rd_bits+7)>>3) + 1;
      }
	   ihdl->fileOffset = tmpFileOffset;
	   ihdl->lastFrameOffset = tmpFileOffset;
   }
   if (cnt != startFrame){
      ihdl->mh.start_time = ihdl->mh.current_time = cnt * FRAME_DURATION; // update start time
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_FAIL, MEDIA_FORMAT_AMR, startFrame, ihdl->fileOffset, ihdl->mh.start_time);
      return KAL_FALSE;
   }else{
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_RESULT, MEDIA_FORMAT_AMR, startFrame, ihdl->fileOffset, ihdl->mh.start_time);
      return KAL_TRUE;
   }
}

static void amrProgressiveSeek( amrMediaHdl *ihdl )
{
   /// Process cache table
   amrProcessCache(ihdl, 1);
   if((ihdl->AudioCacheTbl->valid_cache_number-1)!= 0){
      ihdl->mh.uSeekProgress = ihdl->AudioCacheTbl->current_cache_index * 100 / (ihdl->AudioCacheTbl->valid_cache_number-1);
      ihdl->mh.eSeekLastRet = MEDIA_SUCCESS;
   }else{
      ihdl->mh.uSeekProgress = 0;
      ihdl->mh.eSeekLastRet = MEDIA_SEEK_FAIL;
   }
   return;
}

static void amrMFSeek( MHdl *hdl, Media_Status *eSeekLastRet, kal_uint32 *uProgress )
{
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;

   if(hdl->uGetDurProgress == 0){

      ihdl->fileOffset = 0;
      ihdl->end_status = MEDIA_NONE;
      hdl->read = 0;
      hdl->write = 0;
      hdl->eof = KAL_FALSE;
      hdl->waiting = KAL_FALSE;
      hdl->current_time = hdl->start_time;

      if(amrChkFileHeader( ihdl ) == KAL_FALSE){
         hdl->eSeekLastRet = MEDIA_BAD_FORMAT;
         return;
      }
      ihdl->AudioCacheTbl->start_offset[0]=ihdl->fileOffset;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, MEDIA_FORMAT_AMR, 0, ihdl->fileOffset );
   }

   amrProgressiveSeek(ihdl);

   *eSeekLastRet = hdl->eSeekLastRet;
   *uProgress = hdl->uSeekProgress;

}

static void amrMFBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress )
{
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;

   if( 100 == hdl->uGetDurProgress ){ // cache table finished
      *eLastRet = MEDIA_SUCCESS;
      *uProgress = 100;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_BUILD_CACHE, MEDIA_FORMAT_AMR, MEDIA_SUCCESS, 100 );
      return;
   }

   {
      Media_Status eSeekLastRet;
      kal_uint32 uProgress;
      amrMFSeek( hdl, &eSeekLastRet, &uProgress ); // parse fixed frames
   }
   *eLastRet = hdl->eSeekLastRet; // last result
   {
      kal_uint32 uCurPos;

      ASSERT(ihdl->uFileSize != 0);
      uCurPos = ihdl->AudioCacheTbl->start_offset[ihdl->AudioCacheTbl->current_cache_index];
      hdl->uGetDurProgress = (kal_uint64)uCurPos * (kal_uint64)100 / (kal_uint64)ihdl->uFileSize;
      if(ihdl->AudioCacheTbl->current_cache_index == (ihdl->AudioCacheTbl->valid_cache_number -1 ))
         hdl->uGetDurProgress = 100;
   }

   *uProgress = hdl->uGetDurProgress;

   if( 100 == hdl->uGetDurProgress ){
      hdl->uSeekProgress = 0;
      hdl->start_time = 0;
      ihdl->fileOffset = 0;
   }
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_BUILD_CACHE, MEDIA_FORMAT_AMR, *eLastRet, *uProgress );
}

static void amrMFSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, void *param )
{
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;

   ASSERT(((uint32)ptr & 0x03) == 0 );   /* make sure 4-byte alignment */
   ihdl->AudioCacheTbl = (AudioCacheTable *)ptr;

   { // update frame per cache according to file size
      kal_uint32 uSize;
      
      if(ihdl->uFileSize > 2440){ // worst case: frame size is 61 Bytes
         uSize = ihdl->uFileSize / (100 * 1024); // 300 KB
         ihdl->AudioCacheTbl->frames_per_cache = (uSize * 40) + 40;
      }else{
         ihdl->AudioCacheTbl->frames_per_cache = 1;
      }
   }

   if(!ihdl->AudioCacheTbl->valid_cache_number)
      ihdl->AudioCacheTbl->valid_cache_number = MAX_CACHE_ENTRIES;

   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SET_CACHE_TBL, MEDIA_FORMAT_AMR );
}

static Media_Status amrMFPlayFile( MHdl *hdl )
{
   kal_uint16 wCodecMode;
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;

   if(hdl->start_time || hdl->current_time){
      ihdl->fileOffset = 0;
      ihdl->end_status = MEDIA_NONE;
      hdl->read = 0;
      hdl->write = 0;
      hdl->eof = KAL_FALSE;
      hdl->waiting = KAL_FALSE;
      hdl->current_time = hdl->start_time;
   }

   if(amrChkFileHeader( ihdl ) == KAL_FALSE)
      return MEDIA_UNSUPPORTED_TYPE;

   if(ihdl->AudioCacheTbl != 0)
      ihdl->AudioCacheTbl->start_offset[0] = ihdl->fileOffset;

#if defined(AMRWB_DECODE)
   if (MEDIA_FORMAT_AMR_WB == hdl->mediaType ) { /* AMR-WB */
      ihdl->amr.bWideBand = KAL_TRUE;
      ihdl->amr.vm |= (kal_uint32)MEDIA_VMP_AMR_WB;
   }else 
#endif
   if (MEDIA_FORMAT_AMR == hdl->mediaType ) { /* AMR */
      ihdl->amr.bWideBand = KAL_FALSE;
   }

   if(hdl->start_time){
      FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
      if ((amrSeek(ihdl, true)==KAL_FALSE) || (ihdl->fileOffset >= ihdl->uFileSize))
         return MEDIA_SEEK_EOF;
   }else{
        ihdl->lastFrameOffset = ihdl->fileOffset;
    }


   {  /* Fill Media Buffer */
      kal_uint8 *pBuf;
      kal_int32 num_bytes;
      kal_uint32 buf_len;
      hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
      num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, buf_len, pBuf);
      if(num_bytes < 0) return MEDIA_READ_FAIL;
      ihdl->fileOffset += num_bytes;
      hdl->WriteDataDone( hdl, num_bytes );
   }

#if !AMR_AWB_AUDIO_PATH_SUPPORT
#if defined(AMRWB_DECODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
   if(ihdl->amr.bWideBand == KAL_TRUE){
      DSP_DynamicDownload( DDID_AWB );
      kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE );
   }
#endif
#endif

   wCodecMode = amr_SetAndGetInitialCodecMode( ihdl );

   /* write 'No-Data' speech frame to dsp */
   amr_write_speech_mode_to_dsp( ihdl, 0 );

   amrOpenDevice( ihdl, wCodecMode );

   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_FILE, hdl->mediaType );

   return MEDIA_SUCCESS;
}

static Media_Status amrMFStop( MHdl *hdl )
{
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;

   if( hdl->state == AMR_STATE_PAUSE || hdl->state == AMR_STATE_IDLE )
      return MEDIA_SUCCESS;

   ihdl->end_status = MEDIA_TERMINATED;

   amrCloseDevice( ihdl );
   hdl->uSeekProgress = 0;
   hdl->uCurSeekFrm = 0;
   hdl->state = AMR_STATE_IDLE;
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Status amrMFPause( MHdl *hdl )
{
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;

   ASSERT( hdl->state == AMR_STATE_PLAY );
   ihdl->end_status = MEDIA_TERMINATED;

   amrCloseDevice( ihdl );
   hdl->uSeekProgress = 0;
   hdl->uCurSeekFrm = 0;
   hdl->state = AMR_STATE_PAUSE;

   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, hdl->mediaType );

   return MEDIA_SUCCESS;
}

static Media_Status amrMFResumeFile( MHdl *hdl )
{
   kal_uint16 wCodecMode;
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;

   ASSERT( hdl->state == AMR_STATE_PAUSE );

   wCodecMode = amr_SetAndGetInitialCodecMode( ihdl );
         /* write 'No-Data' speech frame to dsp */
   amr_write_speech_mode_to_dsp( ihdl, 0 );

   amrOpenDevice( ihdl , wCodecMode );
   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Event amrMFStrmProcess( MHdl *hdl, Media_Event event )
{
   amrMediaHdl *ihdl = (amrMediaHdl *) hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, hdl->mediaType );

   switch(event)
   {
      case MEDIA_END:
      case MEDIA_ERROR:
      case MEDIA_STOP_TIME_UP:
         kal_trace( TRACE_ERROR, L1AUDIO_DSP_ERROR );
         if( hdl->state == AMR_STATE_PLAY )
            amrCloseDevice( ihdl );
         hdl->state = AMR_STATE_IDLE;
         return event;

      case MEDIA_DATA_REQUEST:
         return MEDIA_DATA_REQUEST;

      default:
         ASSERT(0); // should never reach here
   }
   return MEDIA_NONE;
}

static Media_Event amrMFProcess( MHdl *hdl, Media_Event event )
{
   amrMediaHdl *ihdl = (amrMediaHdl *) hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, hdl->mediaType );

   switch(event)
   {
      case MEDIA_END:
      case MEDIA_ERROR:
      case MEDIA_STOP_TIME_UP:
         kal_trace( TRACE_ERROR, L1AUDIO_DSP_ERROR );
         if( hdl->state == AMR_STATE_PLAY )
            amrCloseDevice( ihdl );
         hdl->uSeekProgress = 0;
         hdl->uCurSeekFrm = 0;
         hdl->state = AMR_STATE_IDLE;
         return event;

      case MEDIA_DATA_REQUEST:
         {
            kal_uint8 *pBuf;
            kal_int32 num_bytes, cnt = 0;
            kal_uint32 buf_len;
            do{
               hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
               if(buf_len == 0 || hdl->eof ) break;
               num_bytes = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, buf_len, pBuf);
               if(num_bytes < 0) return MEDIA_READ_ERROR;
               ihdl->fileOffset += num_bytes;
               hdl->WriteDataDone( hdl, num_bytes );
            }while(++cnt <= 2);
         }
         hdl->waiting = KAL_FALSE;

         {
            kal_uint64 uRatio;
            FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
            uRatio = (kal_uint64)ihdl->lastFrameOffset * 100 / (kal_uint64)ihdl->uFileSize;
            if( uRatio > ihdl->uDurUpdateThd ){
               if(ihdl->uDurUpdateThd != 100)
                  ihdl->uDurUpdateThd += 20;
               return MEDIA_UPDATE_DUR;
            }
         }

         return MEDIA_NONE;

      default:
         ASSERT(0); // should never reach here
   }
   return MEDIA_NONE;
}

static Media_Status amrMFPlayStrm( MHdl *hdl )
{
   kal_uint16 wCodecMode;
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;

   ihdl->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   if(ihdl->pstFSAL == NULL)
      return MEDIA_FAIL;

   ihdl->fileOffset = 0;
   ihdl->end_status = MEDIA_NONE;
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->current_time = hdl->start_time;
   
   {
      FSAL_Status eFSALStatus;
      FSAL_Direct_SetRamFileSize(ihdl->pstFSAL, hdl->rb_size);
      eFSALStatus = FSAL_Open(ihdl->pstFSAL, hdl->rb_base, FSAL_ROMFILE);
      ASSERT(eFSALStatus == FSAL_OK);
   }

   if(amrChkFileHeader( ihdl ) == KAL_FALSE){
      free_ctrl_buffer( ihdl->pstFSAL );
      return MEDIA_UNSUPPORTED_TYPE;
   }

#if defined(AMRWB_DECODE)
   if (MEDIA_FORMAT_AMR_WB == hdl->mediaType ) { /* AMR-WB */

#if !AMR_AWB_AUDIO_PATH_SUPPORT
#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
      DSP_DynamicDownload( DDID_AWB );
      kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE );
#endif
#endif

      ihdl->amr.bWideBand = KAL_TRUE;
      ihdl->amr.vm |= (kal_uint32)MEDIA_VMP_AMR_WB;
      hdl->read += 9;
   }else 
#endif
   if (MEDIA_FORMAT_AMR == hdl->mediaType ) { /* AMR */
      ihdl->amr.bWideBand = KAL_FALSE;
      hdl->read += 6;
   }else {
      ASSERT(KAL_FALSE);
   }

   wCodecMode = amr_SetAndGetInitialCodecMode( ihdl );

   /* write 'No-Data' speech frame to dsp */
   amr_write_speech_mode_to_dsp( ihdl, 0 );
   amrOpenDevice(ihdl , wCodecMode);

   free_ctrl_buffer( ihdl->pstFSAL );
   ihdl->pstFSAL = NULL;

   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_STREAM, hdl->mediaType );

   return MEDIA_SUCCESS;
}

static Media_Status amrMFResumeStrm( MHdl *hdl )
{
   kal_uint16 wCodecMode;
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;

   ASSERT( hdl->state == AMR_STATE_PAUSE );

   wCodecMode = amr_SetAndGetInitialCodecMode( ihdl );
         /* write 'No-Data' speech frame to dsp */
   amr_write_speech_mode_to_dsp( ihdl, 0 );

   amrOpenDevice( ihdl , wCodecMode );
   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, hdl->mediaType );
   return MEDIA_SUCCESS;
}

kal_uint32 amrMFGetCacheDur(MHdl *hdl)
{
   kal_uint32 uDur;
   amrMediaHdl *ihdl = (amrMediaHdl *) hdl;
   ASSERT(ihdl->AudioCacheTbl != 0);

   if(ihdl->AudioCacheTbl->current_cache_index == (ihdl->AudioCacheTbl->valid_cache_number-1)){
      uDur = (kal_uint64)ihdl->AudioCacheTbl->total_frame * FRAME_DURATION;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR_F, MEDIA_FORMAT_AMR, uDur );
      return uDur;
   }

   if(ihdl->AudioCacheTbl->current_cache_index){
      uDur = (kal_uint64)ihdl->AudioCacheTbl->accumulated_frames[ihdl->AudioCacheTbl->current_cache_index-1]*FRAME_DURATION;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR, MEDIA_FORMAT_AMR, uDur );
      return uDur;
   }
   return 0;
}

kal_uint32 amrMFGetTotalDuration( MHdl *hdl )
{
   kal_uint32 uDur;
   kal_uint64 uTotalFrame;
   amrMediaHdl *ihdl = (amrMediaHdl *) hdl;
   ASSERT(ihdl->AudioCacheTbl != 0);

// cache table finished
   if((ihdl->AudioCacheTbl->current_cache_index == (ihdl->AudioCacheTbl->valid_cache_number-1)) || (ihdl->lastFrameOffset == 0)){
      uDur = (kal_uint64)ihdl->AudioCacheTbl->total_frame * FRAME_DURATION;
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR_F, MEDIA_FORMAT_AMR, uDur );
      return uDur;
   }
   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
   uDur = (kal_uint64)hdl->current_time * (kal_uint64)ihdl->uFileSize / (kal_uint64)ihdl->lastFrameOffset;

   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_TOTAL_DUR, MEDIA_FORMAT_AMR, uDur );
   return uDur;
}

MHdl *AMR_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   amrMediaHdl *ihdl;

#if !IS_EV_BOARD
   Media_VM_PCM_Param *amr_param = (Media_VM_PCM_Param *) param;
#endif

   ihdl = (amrMediaHdl*)get_ctrl_buffer( sizeof(amrMediaHdl) );
   memset(ihdl, 0, sizeof(amrMediaHdl));
   hdl = (MHdl *) ihdl;
   if( handler != NULL )
      mhdlInit( hdl, DP_D2C_SD_DONE, amrHisr );
   else
      mhdlInitEx( hdl, DP_D2C_SD_DONE, amrHisr );

   hdl->handler  = handler;
   hdl->state    = AMR_STATE_IDLE;
   ihdl->pstFSAL = pstFSAL;
#if IS_EV_BOARD
   ihdl->amr.vm  = (uint32)MEDIA_VMP_AS_SPEECH;
#else
   ihdl->amr.vm  = amr_param->vmParam;
#endif
   hdl->Close    = amrMFClose;
   hdl->Pause    = amrMFPause;
   hdl->Stop     = amrMFStop;

   hdl->BuildCache    = amrMFBuildCache;
   hdl->SetCacheTbl  = amrMFSetCacheTbl;
   hdl->GetCacheDuration = amrMFGetCacheDur;
   hdl->GetTotalDuration = amrMFGetTotalDuration;


   if(pstFSAL != NULL){
      hdl->Play = amrMFPlayFile;
      hdl->Resume = amrMFResumeFile;
      hdl->Process  = amrMFProcess;
      kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, MEDIA_FORMAT_AMR );
   }else{
       hdl->Play = amrMFPlayStrm;
       hdl->Resume = amrMFResumeStrm;
       hdl->Process  = amrMFStrmProcess;
       kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, MEDIA_FORMAT_AMR );
    }

   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_FILE_SIZE, MEDIA_FORMAT_AMR, ihdl->uFileSize);

   return hdl;
}

static kal_uint32 amrGetTotalDur(amrMediaHdl *ihdl)
{
   kal_uint32  uFrameCnt, uFrameLen, uFileOffset;
   kal_uint16 lenSherifData, rd_bits;
   kal_uint8  FT, Tx_Type, FQI;
   kal_uint32 ret;

   uFileOffset = ihdl->fileOffset;
   uFrameCnt = 0;
   while(1){
                     /* decode frame header */
      if(amrGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, uFileOffset, 1, &ihdl->buf[0]) != 1)
         break;
      FT = (ihdl->buf[0] >> 3) & 0x0F;
      FQI = (ihdl->buf[0] >> 2) & 0x01;

#if defined(AMRWB_DECODE)
      if (MEDIA_FORMAT_AMR_WB == ihdl->mh.mediaType) {
         ret = amrWBChkFrameHeader( ihdl, ihdl->buf[0], &Tx_Type, &lenSherifData, &rd_bits );
         if(ret == HEADER_ERROR) break;
		} else
#endif
		{
         ret = amrChkFrameHeader( ihdl, ihdl->buf[0], &Tx_Type, &lenSherifData, &rd_bits );
         if(ret == HEADER_ERROR) break;
		}
      if(ret == HEADER_NO_DATA_FRAME)
         uFileOffset += 1;
      else
         uFileOffset += ((rd_bits+7)>>3) + 1;
      uFrameCnt++;
   }
	return (uFrameCnt * FRAME_DURATION); 
}

Media_Status AMR_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   amrMediaHdl *ihdl;
   kal_uint32 file_size;
   kal_uint8 AMR_Header = 0x7C;

   FSAL_GetFileSize( pstFSAL, &file_size);

   ihdl = (amrMediaHdl*)get_ctrl_buffer( sizeof(amrMediaHdl) );
   memset(ihdl, 0, sizeof(amrMediaHdl));
   mhdlInit( ( MHdl *)ihdl, 0xFFFF , amrHisr );
   ihdl->pstFSAL = pstFSAL;

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

   if(amrChkFileHeader( ihdl ) == KAL_FALSE){
      free_ctrl_buffer(ihdl);
      return MEDIA_BAD_FORMAT;
   }

   {
      kal_int32 cnt = 0;
      while(AMR_Header == 0x7C){ // No Data Frame
         if(amrGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, ihdl->fileOffset+cnt, 1, &AMR_Header) != 1){
            free_ctrl_buffer(ihdl);
            return MEDIA_BAD_FORMAT;
         }
         cnt++;
      }
   }

   {
      kal_uint8  FT;
      FT = (AMR_Header >> 3) & 0x0F;
#if defined(AMRWB_DECODE)
      if (MEDIA_FORMAT_AMR_WB == ihdl->mh.mediaType ) { /* AMR-WB */
         contentInfo->sampleRate = 16000;
         if(FT <= 8){
            contentInfo->bitRate = AMRWB_BitRate[FT];
            contentInfo->time = (kal_uint64)(file_size - 9) / (AWB_frame_length[FT]+1) * 20;
         }
      }else 
#endif
       if (MEDIA_FORMAT_AMR == ihdl->mh.mediaType ) { /* AMR */
          contentInfo->sampleRate = 8000;
          if(FT <= 7){
             contentInfo->bitRate = AMR_BitRate[FT];
             contentInfo->time = (kal_uint64)(file_size - 6) / (AMR_frame_length[FT]+1) * 20;
          }
       }
   }

   //if(file_size <= 307200) // 300kB
   //   contentInfo->time = amrGetTotalDur(ihdl);
   free_ctrl_buffer( ihdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, ihdl->mh.mediaType );
   return MEDIA_SUCCESS;
}

Media_Status AMR_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
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

   ret = AMR_GetContentDescInfo( pstFSAL, contentInfo, (void *)0);
   
   if(NULL != filename){
      FSAL_Close(pstFSAL);
   }
   free_ctrl_buffer(pstFSAL);

   return ret;
}

Media_Status AMR_Trim(STFSAL *pstInput, STFSAL *pstOutput, kal_uint32 uStartTime, kal_uint32 uStopTime)
{
   amrMediaHdl *ihdl;
   kal_uint32 uStartOffset, uEndOffset;
   Media_Status eResult = MEDIA_SUCCESS;

   if(((kal_int32)uStopTime - (kal_int32)uStartTime) <= 0)
      return MEDIA_BAD_PARAMETER; // invalid stop time

   ihdl = (amrMediaHdl*)get_ctrl_buffer( sizeof(amrMediaHdl) );
   memset(ihdl, 0, sizeof(amrMediaHdl));

   if(amrChkFileHeader( ihdl ) == KAL_FALSE){
      free_ctrl_buffer(ihdl);
      return MEDIA_BAD_FORMAT;
   }

   // find the start/end offset of extraction
   {
	  kal_uint32 uFirstFrameFileOffset = ihdl->fileOffset;
	  ihdl->mh.start_time = uStartTime;
      if (amrSeek(ihdl, false)==KAL_FALSE){
         free_ctrl_buffer(ihdl);
         return MEDIA_SEEK_FAIL;
	  }
	  uStartOffset = ihdl->fileOffset;
	  ihdl->fileOffset = uFirstFrameFileOffset;

      ihdl->mh.start_time = uStopTime;
      if (amrSeek(ihdl, false)==KAL_FALSE){
         free_ctrl_buffer(ihdl);
         return MEDIA_SEEK_FAIL;
	  }
      uEndOffset = ihdl->fileOffset;
	  ihdl->fileOffset = uStartOffset;
	}

   //write fregment audio data
   {
	   FSAL_Status eFSALStatus;
	   kal_int32 uNumBytes;
	   kal_int32 uLength = (kal_int32)uEndOffset-(kal_int32)uStartOffset;

	   // refill buffer
	   while(uLength > 0){
		  kal_uint32 len = MAX_DATA_REQUESTED;
		  if(uLength<MAX_DATA_REQUESTED)
			  len = uLength;
		  uNumBytes = amrGetBytesFromFile((MHdl *)ihdl, ihdl->pstFSAL, ihdl->fileOffset, len, &ihdl->buf[0]);
		  if(uNumBytes<0){
             free_ctrl_buffer(ihdl);
             return MEDIA_READ_FAIL;
		  }
	      eFSALStatus = FSAL_Write(pstOutput, &ihdl->buf[0], uNumBytes);
		  if(FSAL_OK != eFSALStatus){
             free_ctrl_buffer(ihdl);
             if(eFSALStatus == FS_DISK_FULL)
                return MEDIA_DISK_FULL;
             else
                return MEDIA_WRITE_FAIL;
		  }
		  ihdl->fileOffset += uNumBytes;
		  uLength -= uNumBytes;

	   }
   }
   free_ctrl_buffer(ihdl);
   return eResult;
}
#endif   // IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION