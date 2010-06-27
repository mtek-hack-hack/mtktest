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
 * amr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   AMR/AMR-WB codec driver, the storage format is used for
 *   storing AMR/AMR-WB speech frames in a file for sending via MMS.
 *
 * Author:
 * -------
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
 *
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

#include "media.h"

#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)

#include "amr_table.h"
#include "am.h"
#include "afe.h"
#include "vmi.h"
#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DSP_IDLE                     0
#define DSP_INITIALIZED              1
#define DSP_PLAYING                  2
#define DSP_RECORDING                2
#define DSP_STOP                     3
#endif

#define DEBUG_AMR_RAM_FILE 0
#define DEBUG_AMR_ROM_FILE 0
#define DEBUG_AMR_DSP 0

/* Turn on these only when determining the most appropriate size of the ring buffer */
#define AMR_CHECK_BUFFER_UNDERFLOW 0
#define AMR_CHECK_BUFFER_OVERFLOW 0

#define AMR_WRITE_FILE_HEADER 0
#define AMR_READ_FILE_HEADER 0

#define AMR_STATE_RECORD 1
#define AMR_STATE_RECORD_PAUSE 2
#define AMR_STATE_PLAY 3
#define AMR_STATE_PLAY_PAUSE 4
#define AMR_STATE_STOP 5

#if defined(MT6219) && defined( AMRWB_ENCODE )
 #error should not release WB-AMR record on MT6219
#endif 

static kal_uint16 Tx_ordering_buffer[30];
static kal_uint16 Tx_data_buffer[30];

/* Note: can't record with odd frame length, unless modify ring buffer mechanism in media.c */

static struct{
   mediaControl   *ctrl;
   kal_uint8      state;
   kal_uint16     wType;
   kal_uint8      bCodecMode; /* Codec Mode for DSP Sherif Setting */
   kal_bool       bWideBand;
   kal_uint32     uRecordOverflowCount; /* number of frames that is waiting to be put into ring buffer */
   kal_bool       bOddFlag;
   kal_uint8      bOddData; /* buffers/store one byte when read/write from/to ring buffer */
   kal_bool       dedicated_mode;
#if DEBUG_AMR_RAM_FILE
   kal_uint8      bRamFileBuffer[80000];
   kal_uint32     uRamFileOffset;
#endif
} amr;

int amrGetDataCount( void )
{
   int32 count;

   count = (int32)amr.ctrl->write - (int32)amr.ctrl->read;
   if( count < 0 )
      count += amr.ctrl->rb_size;
   count <<= 1;
   if ( amr.bOddFlag == KAL_TRUE )
      count++;
   return count;
}

static void media_playback_ending(Media_Event event) {
   /* Prevent the message from overwritten in mediaDataRequest */
   amr.ctrl->end_status = MEDIA_END;

#if defined( AMRWB_DECODE ) && (defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238))
   if(amr.bWideBand){
      if(*DP_AWB_SD_CTRL == DSP_PLAYING){
         *DP_AWB_SD_CTRL = DSP_STOP;
         amr.ctrl->end_status = event;
         return;
      }
   }
#endif

#if AMR_AWB_AUDIO_PATH_SUPPORT
   *DP_AUDIO_FLEXI_CTRL = 0;
   AM_AudioPlaybackOff( false );
#else // AMR_AWB_AUDIO_PATH_SUPPORT
   AM_VMPlaybackOff(amr.ctrl->param.vm);
#endif

   mediaSetEvent(event);
}

static void amrEndHandler(void *data, Media_Event event)
{
   (void) data;    // to avoid warning
   media_playback_ending( MEDIA_END );
}

void media_buffer_put_byte(kal_uint8 bData) {
#if DEBUG_AMR_RAM_FILE
   if (amr.uRamFileOffset<sizeof(amr.bRamFileBuffer)) {
     amr.bRamFileBuffer[amr.uRamFileOffset++] = bData;
     amr.ctrl->write = (amr.uRamFileOffset+1)/2;
   }
#else
   if (amr.bOddFlag == KAL_TRUE) {
      kal_uint16 wVal;
      wVal = amr.bOddData | bData<<8;
      if( amr.ctrl->read > amr.ctrl->write ) {
         if( amr.ctrl->read - amr.ctrl->write > 1 )
            amr.ctrl->rb_base[amr.ctrl->write++] = wVal;
         else
            ASSERT(KAL_FALSE); /* media buffer overflow */
      } else if( amr.ctrl->read == 0 ) {
         if( amr.ctrl->rb_size - amr.ctrl->write > 1 )
            amr.ctrl->rb_base[amr.ctrl->write++] = wVal;
         else
            ASSERT(KAL_FALSE); /* media buffer overflow */
      } else {
         amr.ctrl->rb_base[amr.ctrl->write++] = wVal;
         if( amr.ctrl->write == amr.ctrl->rb_size )
            amr.ctrl->write = 0;
      }
      amr.bOddFlag = KAL_FALSE;
      return;
   } else if (amr.bOddFlag == KAL_FALSE) {
      amr.bOddData = bData;
      amr.bOddFlag = KAL_TRUE;
      return;
   }
#endif
}

/* to trigger the update of write pointer, so that
the last byte can be recorded */
void media_buffer_flush()
{
   if (amr.bOddFlag == KAL_TRUE) {
      media_buffer_put_byte(0x7C); /* 'no-data' frame */
   }
}

void media_buffer_put_2bytes(kal_uint16 wData)
{
   media_buffer_put_byte((kal_uint8)(wData & 0xFF));
   media_buffer_put_byte((kal_uint8)(wData >> 8));
}

void media_buffer_put_nbytes(kal_uint8 *pBuf, int n) {
   int i=0;
   ASSERT(pBuf!=NULL);
   while(n-->0) {
      media_buffer_put_byte(pBuf[i++]);
   }
}

static void amr_bit_ordering_sherif_to_file(kal_uint8 bTxType, kal_uint8 bFrameType, kal_uint16* pInData, kal_uint16* pOutData, kal_uint16 wLenBits)
{
   kal_uint16 i, k, p, q;

   k = 0;
#if defined( AMRWB_ENCODE )
   if (KAL_TRUE == amr.bWideBand) {
      const kal_uint16* pOrderingTable = tblAMR_WBOrder[bFrameType];
      for(i=0,p=0,q=0;i<wLenBits;i++) {
         if (bTxType==2) { /* Speech */
      	    k = (kal_uint16)pOrderingTable[i];
         } else if (bTxType==3) { /* SID first or SID update */
            k=i;
         } else {ASSERT(KAL_FALSE);}
         pOutData[q] |= (pInData[k/16] & AMR_get_tab[k%16]) ? AMR_ord_tab[p] : 0;
         if(++p==16) {  p=0; q++; }
      }
   } else
#endif
   {
      const kal_uint8* pOrderingTable = tblAMROrder[bFrameType];
      for(i=0,p=0,q=0;i<wLenBits;i++) {
         if (bTxType==2) { /* Speech */
      	    k = (kal_uint16)pOrderingTable[i];
         } else if (bTxType==3) { /* SID first or SID update */
            k=i;
         } else {ASSERT(KAL_FALSE);}
         pOutData[q] |= (pInData[k/16] & AMR_get_tab[k%16]) ? AMR_ord_tab[p] : 0;
         if(++p==16) {  p=0; q++; }
      }
   }
}

void amrRecordHisr( void )
{
   kal_uint32 uRBFreeCount;
   volatile kal_uint16 *pwSherifAddr;
   kal_uint8    FT, bCodecMode, Tx_Type;
   kal_uint16   uLenSpeechInSherif, i;
   kal_uint16   rd_bits,rd_bytes;

   FT = 0; 
   bCodecMode = 0;
   Tx_Type = 0;
   /**
    * Stop recording immediately after MMI commands Media_Stop.
    * In case that user is recodring while an incoming call comes in,
    * traffic channel will be corrupted, and can not continue to perform
    * recording normally.
    */
   if (amr.state != AMR_STATE_RECORD)
      return;

   /* check ring buffer fullness */
   uRBFreeCount = mediaGetFreeSpace(); /* in unit of words */
   if (uRBFreeCount>0)
      uRBFreeCount = uRBFreeCount * 2 - 1; /* in unit of bytes, -1 means potential pending byte in bOddData */

   /* put pending 'no-data' frame into ring buffer */
   if (amr.uRecordOverflowCount>0) {
      kal_uint32 uBytesToWrite;
      if (uRBFreeCount>=amr.uRecordOverflowCount) {
         uBytesToWrite = amr.uRecordOverflowCount;
         uRBFreeCount -= amr.uRecordOverflowCount;
         amr.uRecordOverflowCount = 0;
      } else {
      	 uBytesToWrite = uRBFreeCount;
      	 amr.uRecordOverflowCount -= uRBFreeCount;
      	 uRBFreeCount = 0;
      }
      for(i=0; i<uBytesToWrite; i++)
         media_buffer_put_byte(0x7C);
   }

   if (uRBFreeCount<61) { /* 8 bit frame header + max. 477 bits speech data */
      /* media buffer overflows */
#if AMR_CHECK_BUFFER_OVERFLOW
      /* If this happens, we have to enlarge the size of ring buffer. */
      ASSERT(KAL_FALSE);
#endif
      if(uRBFreeCount>1) {
         /* stuff 'no-data' frame */
         media_buffer_put_byte(0x7C);
      } else {
      	 amr.uRecordOverflowCount++;
      }
      return;
   }

#if DEBUG_AMR_DSP
   {
      kal_uint16 I, sc_mode;
      I = *DP_SC_MODE;
      sc_mode  = (I >> 8) & 0xFF;
      ASSERT((sc_mode>=0x20 && sc_mode<=0x28) || (sc_mode>=0x03 && sc_mode<=0x0A));
      I = *DP_AUDIO_PAR;
      if (amr.bWideBand) {
         ASSERT(I&0x08); /* check amr-wb flag has not been reset by other place */
      }
   }
#endif
#if defined(AMRWB_ENCODE)
   if (amr.bWideBand == KAL_TRUE) {
      Tx_Type = *DP_AWB_TX_TCH_S0(0) & 0x0003;
      bCodecMode = ((*DP_AWB_SC_TCH_MODE) & 0xFF);
   } else
#endif
   {
      if (amr.dedicated_mode){
          Tx_Type = *DP_TX_TCH_S(0,0) & 0x0003;
          bCodecMode = ((*DP_SC_TCH_MODE >> 8) & 0x0F);
      } else {
#if defined(MT6229_S00) || defined(MT6230_S00)
          Tx_Type = *DP_SD2_VM_0 & 0x0003;  /* Uplink TCH buffer */
          bCodecMode = ((*DP_SD2_VM_17 >> 8) & 0x0F);
#elif defined(MT6229_S01) || defined(MT6230_S01) || defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
          Tx_Type = *DP_TX_TCH_S(0, 0) & 0x0003;
          bCodecMode = ((*DP_TX_TCH_S(0, 17) >> 8) & 0x0F);
#else
          Tx_Type = *DP_SD1_VM_0 & 0x0003;  /* Uplink TCH buffer */
          bCodecMode = ((*DP_SD1_VM_17 >> 8) & 0x0F);
#endif
      }
   }

   /* get AMR frame type */
   if (bCodecMode>=0x03 && bCodecMode<=0x0A) {
      FT = 0x0A - bCodecMode;
   }
#if defined( AMRWB_ENCODE )
   else if (bCodecMode>=0x20 && bCodecMode<=0x28) {
      FT = bCodecMode - 0x20;
   }
#endif
   else {
      ASSERT(KAL_FALSE);
   }

   if (Tx_Type==0) { /* Tx_Type: No data */
      media_buffer_put_byte(0x7C);
      return;
   } else if (Tx_Type==1 || Tx_Type==3) { /* Tx_Type: SID First or SID Update */
      kal_uint16 SID_ord_buf[3];

      /* put SID frame header to media buffer */
      if (amr.bWideBand == KAL_TRUE) {
         media_buffer_put_byte(0x4C);
      } else {
         media_buffer_put_byte(0x44);
      }

      /* Get speech parameter bits */
#if defined( AMRWB_ENCODE )
      if (amr.bWideBand) {
      	 pwSherifAddr = DP_AWB_TX_TCH_S0(1);
      } else 
#endif
      {
         if(amr.dedicated_mode)
            pwSherifAddr = DP_TX_TCH_S(0, 1);
         else
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
            pwSherifAddr = DP_SD2_VM_1;
#else
            pwSherifAddr = DP_SD1_VM_1;
#endif
      }
      kal_mem_set(SID_ord_buf, 0, sizeof(SID_ord_buf));
      if (Tx_Type==3) { /* SID Update */
         kal_uint16 SID_buffer[3];
         for (i = 0; i < 3; i++ ) {
            SID_buffer[i] = *pwSherifAddr++;
         }
         amr_bit_ordering_sherif_to_file(Tx_Type, FT, SID_buffer, SID_ord_buf, 35);
         SID_ord_buf[2] |= AMR_ord_tab[3];  /* SID Type Indicator (STI) */
      }

      /* Mode Indication */
#if defined( AMRWB_ENCODE )
      if (amr.bWideBand == KAL_TRUE) {
         SID_ord_buf[2] |= (FT & 0x0008) ? AMR_ord_tab[4] : 0;
         SID_ord_buf[2] |= (FT & 0x0004) ? AMR_ord_tab[5] : 0;
         SID_ord_buf[2] |= (FT & 0x0002) ? AMR_ord_tab[6] : 0;
         SID_ord_buf[2] |= (FT & 0x0001) ? AMR_ord_tab[7] : 0;
      } else 
#endif
      {
         SID_ord_buf[2] |= (FT & 0x0001) ? AMR_ord_tab[4] : 0;
         SID_ord_buf[2] |= (FT & 0x0002) ? AMR_ord_tab[5] : 0;
         SID_ord_buf[2] |= (FT & 0x0004) ? AMR_ord_tab[6] : 0;
      }

      media_buffer_put_nbytes((kal_uint8*)SID_ord_buf, 5);
      return;
   } else if (Tx_Type==2) { /* TX_TYPE: SPEECH */
#if defined( AMRWB_ENCODE )
      if (amr.bWideBand == KAL_TRUE) {
         rd_bits = lenSpeechBitsAMR_WB[FT];
      } else
#endif
      {
         rd_bits = lenSpeechBitsAMR[FT];
      }
      rd_bytes = (rd_bits + 7)/8;
      uLenSpeechInSherif = (rd_bytes+1)/2;

      /* Get speech parameter bits */
#if defined( AMRWB_ENCODE )
      if (amr.bWideBand == KAL_TRUE){
         pwSherifAddr = DP_AWB_TX_TCH_S0( 1 );
         if ( uLenSpeechInSherif > 16) {//16 words from DP_AWB_TX_TCH_S0(1)
            for ( i = 0; i < 16; i++)
               Tx_data_buffer[i] = *pwSherifAddr++;
            pwSherifAddr = DP_AWB_TX_TCH_S17( 0 );
            for ( i = 16; i < uLenSpeechInSherif; i++ )
               Tx_data_buffer[i] = *pwSherifAddr++;
         }else
            for ( i = 0; i < uLenSpeechInSherif; i++ )
               Tx_data_buffer[i] = *pwSherifAddr++;
      }else
#endif
      {
         if(amr.dedicated_mode)
            pwSherifAddr = DP_TX_TCH_S( 0, 1 );
         else
#if defined(MT6229_S00) || defined(MT6230_S00)
            pwSherifAddr = DP_SD2_VM_1;
#elif defined(MT6229_S01) || defined(MT6230_S01) || defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
            pwSherifAddr = DP_TX_TCH_S(0, 1);
#else
            pwSherifAddr = DP_SD1_VM_1;
#endif
         for (i=0; i<uLenSpeechInSherif; i++)
            Tx_data_buffer[i] = *pwSherifAddr++;
      }

      /* bits ordering */
      kal_mem_set(Tx_ordering_buffer, 0, sizeof(Tx_ordering_buffer));
      amr_bit_ordering_sherif_to_file(Tx_Type, FT, Tx_data_buffer, Tx_ordering_buffer, rd_bits);

      /* put frame header to media buffer */
      media_buffer_put_byte((kal_uint8)((FT<<3) | (0x1<<2))); /* FT | FQI */

      /* put ordering data to media buffer */
      media_buffer_put_nbytes((kal_uint8*)Tx_ordering_buffer, rd_bytes);
   } else {
      ASSERT(KAL_FALSE);
   }
}

kal_uint8 media_buffer_get_byte() {
   if (amr.bOddFlag == KAL_TRUE) {
      amr.bOddFlag = KAL_FALSE;
      return amr.bOddData;
   } else if (amr.bOddFlag == KAL_FALSE) {
      if (amr.ctrl->read != amr.ctrl->write) {
      	 kal_uint16 wVal = amr.ctrl->rb_base[amr.ctrl->read++];
         if (amr.ctrl->read >= amr.ctrl->rb_size)
            amr.ctrl->read = 0;
         amr.bOddData = (kal_uint8)(wVal >> 8);
         amr.bOddFlag = KAL_TRUE;
         return (kal_uint8)(wVal & 0x00FF);
      }
      /* XXX: media ring buffer underflow */
      ASSERT(amr.ctrl->read != amr.ctrl->write);
   } else {
      ASSERT(KAL_FALSE);
   }
   return 0;
}

kal_uint8 media_buffer_peek_byte() {
   if (amr.bOddFlag == KAL_TRUE) {
      return amr.bOddData;
   } else if (amr.bOddFlag == KAL_FALSE) {
      if (amr.ctrl->read != amr.ctrl->write) {
      	 kal_uint16 wVal = amr.ctrl->rb_base[amr.ctrl->read];
         return (kal_uint8)(wVal & 0x00FF);
      }
      /* XXX: media ring buffer underflow */
      ASSERT(amr.ctrl->read != amr.ctrl->write);
   } else {
      ASSERT(KAL_FALSE);
   }
   return 0;
}

kal_uint16 media_buffer_get_2bytes() {
   kal_uint8 buf1, buf2;
   buf1 = media_buffer_get_byte();
   buf2 = media_buffer_get_byte();
   return (kal_uint16)(buf1 | buf2<<8);
}

void media_buffer_get_nbytes(kal_uint8 *buf, kal_uint32 uLen) {
   kal_uint32 i=0;
   ASSERT(buf!=NULL);
   while(uLen-->0) {
      buf[i++] = media_buffer_get_byte();
   }
}

kal_uint8 media_buffer_peek_nbytes(kal_uint8 *buf, kal_uint32 uLen) {
   kal_uint32 uOrigRead = amr.ctrl->read;
   kal_bool bOrigOddFlag = amr.bOddFlag;
   kal_uint8 bOrigOddData = amr.bOddData;

   media_buffer_get_nbytes(buf, uLen);

   amr.ctrl->read = uOrigRead;
   amr.bOddFlag = bOrigOddFlag;
   amr.bOddData = bOrigOddData;
   return 0;
}

static void amr_write_speech_mode_to_dsp(kal_uint8 bTxType)
{
   if (KAL_TRUE==amr.bWideBand) {
      *DP_SD2_AWB_VM_0 = (amr.bCodecMode << 8) | bTxType; /* codec mode | Tx-Type */
   } else {
      *DP_SD2_VM_17 = amr.bCodecMode;
      *DP_SD2_VM_0 = bTxType;
   }
}

static void amr_write_speech_data_to_dsp(kal_uint16 *pwData, kal_uint16 bLen)
{
   volatile kal_uint16 *pwSherifAddr;
   kal_uint8 i;
   if (KAL_TRUE==amr.bWideBand) {
      pwSherifAddr = DP_SD2_AWB_VM_1;
      if (bLen>17) {
         for(i=0; i<17; i++) {
   	    *pwSherifAddr++ = pwData[i];
   	 }
   	 pwSherifAddr = DP_SD2_AWB_VM_18;
   	 for(; i< bLen; i++) {
   	    *pwSherifAddr++ = pwData[i];
   	 }
      } else {
         for(i=0; i < bLen; i++ )
         *pwSherifAddr++ = pwData[i];
      }
   } else {
      pwSherifAddr = DP_SD2_VM_1;
      for (i = 0; i < bLen; i++)
         *pwSherifAddr++ = pwData[i];
   }
}

static void amr_bit_ordering_file_to_sherif(kal_uint8 bTxType, kal_uint8 bFrameType, kal_uint16* pInData, kal_uint16* pOutData, kal_uint16 wLenBits)
{
   kal_uint16 i, k, p, q;

   k = 0;
#if defined( AMRWB_DECODE )
   if (KAL_TRUE == amr.bWideBand) {
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

void amrPlaybackHisr( void )
{
   kal_int32  uBytesAvailable;
   kal_uint16 rd_bytes;
   kal_uint16 rd_bits;
   kal_uint8  bFrameHeader, FT, Tx_Type, FQI;
   kal_uint16 lenSherifData;

   rd_bits = 0;
   Tx_Type = 0;
   lenSherifData = 0;
   if (amr.state != AMR_STATE_PLAY)
      return;

#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   {
#if defined( AMRWB_DECODE )
      kal_uint16 awbCtrl;
      if(amr.bWideBand){
         awbCtrl = *DP_AWB_SD_CTRL;
         switch(awbCtrl)
         {
            case DSP_PLAYING:   break;
            case DSP_STOP:       return;
            case DSP_IDLE:
#if AMR_AWB_AUDIO_PATH_SUPPORT
                      *DP_AUDIO_FLEXI_CTRL = 0;
                      AM_AudioPlaybackOff( false );
#else // AMR_AWB_AUDIO_PATH_SUPPORT
                      AM_VMPlaybackOff(amr.ctrl->param.vm);
#endif
                      mediaSetEvent( amr.ctrl->end_status );
                      return;
            default:
                      ASSERT_REBOOT(KAL_FALSE);
         }
      }
#endif
   }
#endif

   /* check ring buffer emptiness */
   uBytesAvailable = mediaGetDataCount();
   uBytesAvailable = (uBytesAvailable << 1) + amr.bOddFlag;
   uBytesAvailable --;  /* 1 byte for header */

   if (uBytesAvailable < 1) {
      /* media buffer underflows */
      /* stuff 'no-data' frame */
      amr_write_speech_mode_to_dsp(0);
      if (amr.ctrl->eof) {
#if APM_SUPPORT
         APM_NOTIFY_MEDIA_END( amrEndHandler, NULL, false , MEDIA_END);
#else
         amrEndHandler(NULL, 0);
#endif
      }
#if AMR_CHECK_BUFFER_UNDERFLOW
      else {
         /* If this happens, we have to enlarge the size of ring buffer. */
         ASSERT(KAL_FALSE);
      }
#endif
      return;
   }

   /* decode frame header */
   bFrameHeader = media_buffer_peek_byte();
   FT = (bFrameHeader >> 3) & 0x0F;
   FQI = (bFrameHeader >> 2) & 0x01;

#if defined( AMRWB_DECODE )
   if (KAL_TRUE==amr.bWideBand) {
      /* If the codec mode are not right, DSP may mal-function */
      EXT_ASSERT((((((*DP_SD2_AWB_VM_0)>>8)&0xFF)>=0x20) &&
        ((((*DP_SD2_AWB_VM_0)>>8)&0xFF)<=0x28)), (*DP_SD2_AWB_VM_0), 0, 0);
      if (FT<=8) { /* AMR-WB 6.60 kbps ~ 23.85 kbps */
         Tx_Type = 2;
         amr.bCodecMode = FTtoSCM_AMR_WB[FT];
         rd_bits = lenSpeechBitsAMR_WB[FT];
         lenSherifData = (rd_bits+15)/16;
         if (FQI==1) { /* SPEECH_GOOD */
         } else { /* SPEECH_BAD */
         }
      } else if (FT==9) { /* AMR-WB SID */
         Tx_Type = 3;
         rd_bits = lenSpeechBitsAMR_WB[FT];
         lenSherifData = 3;
         if (FQI==1) { /* SID_UPDATE or SID_FIRST */
         } else { /* SID_BAD */
         }
      } else if (FT==14) { /* SPEECH_LOST */
         if (FQI==0) {
            rd_bits = 0;
            lenSherifData = 0;
            Tx_Type = 0;
         } else {
            media_playback_ending(MEDIA_ERROR);
            return; /* undefined situation */
         }
      } else if (FT==15) { /* NO_DATA */
         rd_bits = 0;
         lenSherifData = 0;
         Tx_Type = 0;

         media_buffer_get_byte();   /* consume the header byte */
         amr_write_speech_mode_to_dsp(Tx_Type);
     	   return;
      } else { /* 'for-future-use' mode */
      	 media_playback_ending(MEDIA_ERROR);
      	 return;
      }
   } else
#endif
   {
      /* If the codec mode are not right, DSP may mal-function */
      EXT_ASSERT(((*DP_SD2_VM_17>=0x03) && (*DP_SD2_VM_17<=0x0A)), (*DP_SD2_VM_17), 0, 0);
      if (FT<=7) { /* AMR 4.75 ~ 12.2 kbps */
         amr.bCodecMode = FTtoSCM_AMR[FT];
         rd_bits = lenSpeechBitsAMR[FT];
         Tx_Type = 2;
         lenSherifData = (rd_bits+15)/16;
         if(FQI==1) { /* SPEECH_GOOD */
         } else { /* SPEECH_BAD */
         }
      } else if (FT==8) { /* AMR SID */
         rd_bits = lenSpeechBitsAMR[FT];
         Tx_Type = 3;
         lenSherifData = 3;
         if(FQI==1) { /* SID_UPDATE or SID_FIRST */
         } else { /* SID_BAD */
         }
      } else if (FT>=9 && FT<=14) { /* GSM/TDMA/PDC SID and 'for-future-use' mode */
      	 media_playback_ending(MEDIA_ERROR);
         return;
      } else if (FT==15) { /* No_Data*/
         rd_bits = 0;
         lenSherifData = 0;
         Tx_Type = 0;
         media_buffer_get_byte();   /* consume the header byte */
         amr_write_speech_mode_to_dsp(Tx_Type);
     	   return;
      }
   }

   /* check buffer underflow */
   rd_bytes = (rd_bits+7)>>3;
   if (rd_bytes > uBytesAvailable) {
      amr_write_speech_mode_to_dsp(0);
      if (amr.ctrl->eof) {
         media_playback_ending(MEDIA_END);
      }
#if AMR_CHECK_BUFFER_UNDERFLOW
      else {
         /* If this happens, we have to enlarge the size of ring buffer. */
         ASSERT(KAL_FALSE);
      }
#endif
      return;
   }
   media_buffer_get_byte();   /* consume the header byte */
   /* get speech data from ring buffer */
   media_buffer_get_nbytes((kal_uint8*)Tx_ordering_buffer, rd_bytes);

   /* bits re-ordering */
   kal_mem_set(Tx_data_buffer, 0, sizeof(Tx_data_buffer));
   amr_bit_ordering_file_to_sherif(Tx_Type, FT, Tx_ordering_buffer, Tx_data_buffer, rd_bits);

   if (Tx_Type==3) { /* SID first or SID update */
      Tx_data_buffer[2]&=0x00E0;
      if((Tx_ordering_buffer[2]&0x0010)==0)   /* STI */
         Tx_Type = 1; /* SID first */
   }

   /* write speech frame to sherif */
   amr_write_speech_mode_to_dsp(Tx_Type);
   amr_write_speech_data_to_dsp(Tx_data_buffer, lenSherifData);
}

void amrRecord( mediaControl *ctrl, kal_uint16 type )
{
   amr.ctrl = ctrl;
   amr.state = AMR_STATE_RECORD;
   amr.bOddFlag = KAL_FALSE;
   amr.wType = type;
   amr.uRecordOverflowCount = 0;
#if DEBUG_AMR_RAM_FILE
   amr.uRamFileOffset = 0;
#endif
   amr.dedicated_mode = AM_IsSpeechOn();
   
#if VMI_SUPPORT   
   if(AM_IsVoIPOn() == true)
   {
      VMI_PutAllToSE(true);
   }
#endif
   
   *DP_SC_MUTE = 0x0002;   /* uplink path only */

   /*
    * Stuff no-data frame first to handle the situation when DSP issues
    * interrupt to MCU for recording, but at that time the AMR codec in DSP
    * has not finished its job.
    */
#if defined( AMRWB_ENCODE )
   if (MEDIA_FORMAT_AMR_WB==ctrl->format) { /* AMR-WB */

#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   DSP_DynamicDownload( DDID_AWB );
   *DP_AWB_SE_CTRL = DSP_INITIALIZED;
#endif

      amr.bWideBand = KAL_TRUE;
#if AMR_WRITE_FILE_HEADER
      media_buffer_put_nbytes((kal_uint8*)"#!AMR-WB\n", 9); /* magic number  "#!AMR-WB\n" */
#endif
      ASSERT(type>=0x20 && type<=0x28);
      *DP_AWB_TX_TCH_S0(0) &= 0xFC;  /* Tx_type "No data" */
      *DP_AWB_SC_TCH_MODE &= 0xFF00;
      *DP_AWB_SC_TCH_MODE |= 0x0020; /* SC Mode: 4.75kbps */
   } else 
#endif
   if (MEDIA_FORMAT_AMR==ctrl->format) { /* AMR */
      amr.bWideBand = KAL_FALSE;
#if AMR_WRITE_FILE_HEADER
      media_buffer_put_nbytes((kal_uint8*)"#!AMR\n", 6); /* magic number  "#!AMR\n" */
#endif
      ASSERT(type>=0x03 && type<=0x0A);
      if (amr.dedicated_mode){
         *DP_TX_TCH_S(0,0) &= 0xFC; /* Tx_type "No data" */
         *DP_SC_TCH_MODE &= 0xF0FF;
         *DP_SC_TCH_MODE |= 0x0900; /* SC mode: 5.15kbps */
      } else {
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
         *DP_SD2_VM_0 &= 0xFC;       /* Tx_type "No data" */
         *DP_SD2_VM_17 &= 0xF0FF;
         *DP_SD2_VM_17 |= 0x0900;    /* SC mode: 5.15kbps */
#else
         *DP_SD1_VM_0 &= 0xFC;       /* Tx_type "No data" */
         *DP_SD1_VM_17 &= 0xF0FF;
         *DP_SD1_VM_17 |= 0x0900;    /* SC mode: 5.15kbps */
#endif
      }
   } else {
      ASSERT(KAL_FALSE);
   }
   AM_VMRecordOn( (kal_uint16)type );

#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#if defined( AMRWB_ENCODE )
   if (MEDIA_FORMAT_AMR_WB == ctrl->format ){
      kal_uint32 I;
      kal_uint16 ctl;
      volatile kal_uint16* ptr;

      ptr = DP_AWB_SE_CTRL;
      for( I = 0; ; I++ ) {
         ctl = *ptr;
         if( ctl == DSP_RECORDING )                /* DSP returns to idle state */
            break;
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
#endif
#endif
}

kal_uint16 amrSetAndGetInitialCodecMode()
{
   kal_uint16 wInitialCodecMode;
#if defined( AMRWB_DECODE )
   if (KAL_TRUE==amr.bWideBand) {
      amr.bCodecMode = 0x20;
      wInitialCodecMode = (0x20<<2);
   } else
#endif
   {
      amr.bCodecMode = 0x03;
      wInitialCodecMode = (0x03<<2) | (0x03<<6);
   }
   return wInitialCodecMode;
}

Media_Status amrPlay( mediaControl *ctrl )
{
   kal_uint16 wCodecMode;

   amr.ctrl = ctrl;
   amr.state = AMR_STATE_PLAY;
   amr.bOddFlag = KAL_FALSE;
#if DEBUG_AMR_RAM_FILE
   Media_SetBuffer( (kal_uint16 *)amr.bRamFileBuffer, sizeof(amr.bRamFileBuffer)/sizeof(kal_uint16)+1);
   Media_WriteDataDone( sizeof(amr.bRamFileBuffer)/sizeof(kal_uint16) );
   Media_DataFinished();
#endif

#if DEBUG_AMR_ROM_FILE
   {
      extern const unsigned char amr_stream[77357];
      Media_SetBuffer( (kal_uint16 *)amr_stream, sizeof(amr_stream)/sizeof(kal_uint16)+1);
      Media_WriteDataDone( sizeof(amr_stream)/sizeof(kal_uint16) );
      Media_DataFinished();
   }
#endif

#if defined( AMRWB_DECODE )
   if (MEDIA_FORMAT_AMR_WB == ctrl->format) { /* AMR-WB */

#if !AMR_AWB_AUDIO_PATH_SUPPORT
#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T)
   DSP_DynamicDownload( DDID_AWB );
#endif
#endif

#if AMR_READ_FILE_HEADER
      kal_uint8 AMR_Header[9];
      /* check amr-wb file header */
      media_buffer_get_nbytes(AMR_Header, 9);
      if (kal_mem_cmp(AMR_Header, "#!AMR-WB\n", 9)!=0)
         return MEDIA_BAD_FORMAT;
#endif
      amr.bWideBand = KAL_TRUE;
      amr.ctrl->param.vm |= (kal_uint32)MEDIA_VMP_AMR_WB;
   } else 
#endif//#if defined( AMRWB_DECODE )
   if (MEDIA_FORMAT_AMR == ctrl->format) { /* AMR */
#if AMR_READ_FILE_HEADER
      kal_uint8 AMR_Header[6];
      /* check amr file header */
      media_buffer_get_nbytes(AMR_Header, 6);
      if(kal_mem_cmp(AMR_Header, "#!AMR\n", 6)!=0)
         return MEDIA_BAD_FORMAT;
#endif
      amr.bWideBand = KAL_FALSE;
   }  else {
      ASSERT(KAL_FALSE);
   }

   wCodecMode = amrSetAndGetInitialCodecMode();

   /* write 'No-Data' speech frame to dsp */
   amr_write_speech_mode_to_dsp(0);

#if AMR_AWB_AUDIO_PATH_SUPPORT
   {
      uint16 control = wCodecMode ;
      uint32 style = amr.ctrl->param.vm;
      uint32 vm_control  = (style<<16) | control;
      uint16 sc_mode, sd_mode;
      uint16 codec_mode;
      uint16 amr_sd_mode = (control&0x3C) >> 2;
      uint16 awb_sd_mode = (control&0xFC) >> 2;
      uint16 samplingrate;
      /* Set Digital Gain for AMR/AMR-WB */
      AFE_SetDigitalGain( L1SP_AUDIO, amr.ctrl->level );

      if( ((0x03<=amr_sd_mode) && (0x0A>=amr_sd_mode))){ // AMR
         DSP_DynamicDownload( DDID_AMRSBC );
         codec_mode = ASP_TYPE_AMR;
         sc_mode = (vm_control>>2) & 0xF;
         sd_mode = (vm_control>>6) & 0xF;
         samplingrate = ASP_FS_8K;
      }
#if defined( AMRWB_DECODE )
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
   AFE_SetDigitalGain( L1SP_VOICE, amr.ctrl->level );
   AM_VMPlaybackOn( wCodecMode, amr.ctrl->param.vm);
#endif

#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#if defined( AMRWB_DECODE )
   if (MEDIA_FORMAT_AMR_WB == ctrl->format ){
      kal_uint32 I;
      kal_uint16 ctl;
      volatile kal_uint16* ptr;

      *DP_AWB_SD_CTRL = DSP_INITIALIZED;
      ptr = DP_AWB_SD_CTRL;
      for( I = 0; ; I++ ) {
         ctl = *ptr;
         if( ctl == DSP_PLAYING )                /* DSP returns to idle state */
            break;
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
#endif
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

   return MEDIA_SUCCESS;
}

#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
void amrWBStopCtrl(bool isPlayback)
{
   uint16 I, ctl;
   volatile uint16* ptr;

   ptr = ((isPlayback == true )?DP_AWB_SD_CTRL:DP_AWB_SE_CTRL);

   if(*ptr == DSP_PLAYING || *ptr == DSP_RECORDING){
      amr.state = AMR_STATE_STOP;
      *ptr = DSP_STOP;
   }
   for( I = 0; ; I++ ) {
      ctl = *ptr;
      if( ctl == DSP_IDLE )                /* DSP returns to idle state */
         break;
      ASSERT_REBOOT( I < 20 );
      kal_sleep_task( 2 );
   }
}
#endif
#endif

void amrStop( void )
{

   switch(amr.state) {
      case AMR_STATE_RECORD:
      case AMR_STATE_RECORD_PAUSE:

#if defined(AMRWB_ENCODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
         if(amr.bWideBand)
            amrWBStopCtrl(false);
#endif

         *DP_SC_MUTE = 0x0000;
         AM_VMRecordOff();
         media_buffer_flush();
         break;
      case AMR_STATE_PLAY:
      case AMR_STATE_PLAY_PAUSE:

#if defined(AMRWB_DECODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
         if(amr.bWideBand)
            amrWBStopCtrl(true);
#endif
#if AMR_AWB_AUDIO_PATH_SUPPORT
         *DP_AUDIO_FLEXI_CTRL = 0;
         AM_AudioPlaybackOff( true );
#else // AMR_AWB_AUDIO_PATH_SUPPORT
         AM_VMPlaybackOff(amr.ctrl->param.vm);
#endif
         break;
      default:
         ASSERT(KAL_FALSE);
   }
#if VMI_SUPPORT     
   VMI_PutAllToSE(false);
#endif   
   amr.state = AMR_STATE_STOP;
}

void amrPause(mediaControl *ctrl)
{
   switch(amr.state) {
      case AMR_STATE_RECORD:

#if defined(AMRWB_ENCODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
         if(amr.bWideBand)
            amrWBStopCtrl(false);
#endif

         *DP_SC_MUTE = 0x0000;
         AM_VMRecordOff();
         amr.state = AMR_STATE_RECORD_PAUSE;
         break;
      case AMR_STATE_PLAY:

#if defined(AMRWB_DECODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
         if(amr.bWideBand)
            amrWBStopCtrl(true);
#endif
#if AMR_AWB_AUDIO_PATH_SUPPORT
         *DP_AUDIO_FLEXI_CTRL = 0;
         AM_AudioPlaybackOff( true );
#else // AMR_AWB_AUDIO_PATH_SUPPORT
         AM_VMPlaybackOff(amr.ctrl->param.vm);
#endif
         amr.state = AMR_STATE_PLAY_PAUSE;
         break;
      default:
         ASSERT(KAL_FALSE);
   }
   
#if VMI_SUPPORT     
   VMI_PutAllToSE(false);
#endif   
   
}

void amrResume(mediaControl *ctrl)
{
   kal_uint16 wCodecMode;

   switch(amr.state) {
      case AMR_STATE_RECORD_PAUSE:

#if VMI_SUPPORT        	
         if(AM_IsVoIPOn() == true)
         {
            VMI_PutAllToSE(true);
         }
#endif
         
         *DP_SC_MUTE = 0x0002;   /* uplink path only */

#if defined(AMRWB_ENCODE) && ( defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )
         if(amr.bWideBand)
            *DP_AWB_SE_CTRL = DSP_INITIALIZED;
#endif

         AM_VMRecordOn( amr.wType );
         amr.state = AMR_STATE_RECORD;

#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#if defined( AMRWB_ENCODE )
         if (MEDIA_FORMAT_AMR_WB == ctrl->format ){
            kal_uint32 I;
            kal_uint16 ctl;
            volatile kal_uint16* ptr;

            ptr = DP_AWB_SE_CTRL;
            for( I = 0; ; I++ ) {
               ctl = *ptr;
               if( ctl == DSP_RECORDING )                /* DSP returns to idle state */
                  break;
               ASSERT_REBOOT( I < 20 );
               kal_sleep_task( 2 );
            }
         }
#endif
#endif

         break;
      case AMR_STATE_PLAY_PAUSE:
         wCodecMode = amrSetAndGetInitialCodecMode();
         /* write 'No-Data' speech frame to dsp */
         amr_write_speech_mode_to_dsp(0);

#if AMR_AWB_AUDIO_PATH_SUPPORT
         {
            uint16 control = wCodecMode ;
            uint32 style = amr.ctrl->param.vm;
            uint32 vm_control  = (style<<16) | control;
            uint16 sc_mode, sd_mode;
            uint16 codec_mode;
            uint16 amr_sd_mode = (control&0x3C) >> 2;
            uint16 awb_sd_mode = (control&0xFC) >> 2;
            uint16 samplingrate;
         
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
         AM_VMPlaybackOn( wCodecMode, amr.ctrl->param.vm);
#endif         

#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#if defined( AMRWB_DECODE )
         if (MEDIA_FORMAT_AMR_WB == ctrl->format ){
            kal_uint32 I;
            kal_uint16 ctl;
            volatile kal_uint16* ptr;
            
            *DP_AWB_SD_CTRL = DSP_INITIALIZED;
            ptr = DP_AWB_SD_CTRL;
            for( I = 0; ; I++ ) {
               ctl = *ptr;
               if( ctl == DSP_PLAYING )                /* DSP returns to idle state */
                  break;
               ASSERT_REBOOT( I < 20 );
               kal_sleep_task( 2 );
            }
         }
#endif
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

         amr.state = AMR_STATE_PLAY;
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}

void amrUpdateLevel()
{
#if AMR_AWB_AUDIO_PATH_SUPPORT
   AFE_SetDigitalGain( L1SP_AUDIO, amr.ctrl->level );
#else
   AFE_SetDigitalGain( L1SP_VOICE, amr.ctrl->level );
#endif // #if AMR_AWB_AUDIO_PATH_SUPPORT
}

#endif   // IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION


