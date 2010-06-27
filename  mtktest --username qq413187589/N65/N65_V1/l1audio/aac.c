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
 * aac.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   AAC playback
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
#if defined(AAC_DECODE)

#include "media.h"
#include "ddload.h"
#include "afe.h"

#define DSP_WRITE(addr, data) (*(addr) = (kal_uint16)(data))

/* Turn on this flag only when determining the most appropriate size of the ring buffer */
#define AAC_CHECK_BUFFER_UNDERFLOW 0

#define AAC_STATE_PLAY 1
#define AAC_STATE_PAUSE 2
#define AAC_STATE_STOP 3

#define DSP_AAC_STATE_IDLE 0
#define DSP_AAC_STATE_START 6
#define DSP_AAC_STATE_PLAYING 2
#define DSP_AAC_STATE_STOP 10
#define DSP_AAC_STATE_END 14

#define VERIFY_AAC_STEP1 0

#if VERIFY_DATA_TO_DSP
extern void VERIFY_DATA_TO_DSP_WRITE_DATA( const kal_uint16 *buf, int32 len );
#endif

static struct{
   mediaControl *ctrl;
   kal_uint8 bState;
   /// sampling frequency to be set in Sherif DP_Audio_ASP_Fs
   /// expected values are ASP_FS_8K - ASP_FS_48K
   kal_uint16 wFreq;
   kal_uint8 bADTSFixedHeader[4];
   /// error flag
   kal_bool bError;
   /// format flag
   kal_bool bIsTypeADTS;
} aac;

#if VERIFY_AAC_STEP1
#include "aac.h"
void setup_ring_buffer(void) {
   Media_SetBuffer( (kal_uint16 *)aac_file, (sizeof(aac_file)+1)/sizeof(kal_uint16) + 1);
   Media_WriteDataDone( (sizeof(aac_file)+1)/sizeof(kal_uint16) );
   Media_DataFinished();
   aac.wFreq = ASP_FS_44K;
}
#endif

static kal_uint8 get_bits(kal_uint8 *pBuf, kal_uint32 *puBitCnt, kal_uint32 uBitLen)
{
	static kal_uint8 bCurByte;
	kal_uint8 bMask;
	kal_uint32 uCurBitPos;
	kal_uint8 bValue;

   ASSERT(puBitCnt!=NULL);
	ASSERT(uBitLen>=1 && uBitLen<=8);

	uCurBitPos = *puBitCnt % 8;

	if(uCurBitPos==0) {
	   bCurByte = pBuf[*puBitCnt/8];
	}

	*puBitCnt += uBitLen;

	if(uCurBitPos+uBitLen<=8) {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		bValue = (unsigned char)((bCurByte&bMask) >> (8-(uCurBitPos+uBitLen)));
	} else {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		bValue = (unsigned char)((bCurByte&bMask) << (uBitLen-(8-uCurBitPos)));
		bCurByte = pBuf[*puBitCnt/8];
		bValue |= bCurByte>>(16-uBitLen-uCurBitPos);
	}

	return bValue;
}

Media_Status aac_parse_header(void) {
   kal_uint8 bSamplingFreqIndex;
   kal_uint8 *pBuf = (kal_uint8*) (aac.ctrl->rb_base + aac.ctrl->read);
   kal_uint32 uBitCnt=0;

   if ((pBuf[0] == 0xFF) && (pBuf[1] & 0xF0 == 0xF0)) { /* ADTS */
      /* syncword */
      get_bits(pBuf, &uBitCnt, 8);
      get_bits(pBuf, &uBitCnt, 4);

      /* ID */
      get_bits(pBuf, &uBitCnt, 1);

      /* layer */
      if (get_bits(pBuf, &uBitCnt, 2) != 0x00)
         return MEDIA_BAD_FORMAT;

      /* protection absent */
      get_bits(pBuf, &uBitCnt, 1);

      /* profile object type */
      if (get_bits(pBuf, &uBitCnt, 2) != 0x01)
         return MEDIA_UNSUPPORTED_TYPE;

      /* sampling frequency index */
      bSamplingFreqIndex = get_bits(pBuf, &uBitCnt, 4);

      /* private bit */
      get_bits(pBuf, &uBitCnt, 1);

      /* channel configuration */
      if (get_bits(pBuf, &uBitCnt, 3) > 0x02)
         return MEDIA_UNSUPPORTED_CHANNEL;

      /* cache ADTS Fixed Header */
      kal_mem_cpy(aac.bADTSFixedHeader, pBuf, 4);
      aac.bADTSFixedHeader[3] &= 0xF0;
      aac.bIsTypeADTS = KAL_TRUE;
   } else if ((pBuf[0] == 'A') && (pBuf[1] == 'D') && (pBuf[2] == 'I') && (pBuf[3] == 'F')) { /* ADIF */
      kal_uint32 uBitstreamType;

      /* read out 4 bytes */
      get_bits(pBuf, &uBitCnt, 8);
      get_bits(pBuf, &uBitCnt, 8);
      get_bits(pBuf, &uBitCnt, 8);
      get_bits(pBuf, &uBitCnt, 8);

      /* copyright_id_present */
      if (get_bits(pBuf, &uBitCnt, 1)) {
         kal_uint32 uCount;
         for (uCount=0; uCount<9; uCount++)
            get_bits(pBuf, &uBitCnt, 8);
      }

      /* origianl copy */
      get_bits(pBuf, &uBitCnt, 1);

      /* home */
      get_bits(pBuf, &uBitCnt, 1);

      /* bitstream_type */
      uBitstreamType = get_bits(pBuf, &uBitCnt, 1);

      /* bit rate */
      get_bits(pBuf, &uBitCnt, 8);
      get_bits(pBuf, &uBitCnt, 8);
      get_bits(pBuf, &uBitCnt, 7);

      /* number_program_config_elements */
      get_bits(pBuf, &uBitCnt, 4);

      if (0 == uBitstreamType) {
         get_bits(pBuf, &uBitCnt, 8);
         get_bits(pBuf, &uBitCnt, 8);
         get_bits(pBuf, &uBitCnt, 4);
      }

      /*--- PCE ---*/

      /* element_instance_tag */
      get_bits(pBuf, &uBitCnt, 4);

      /* object type */
      if (get_bits(pBuf, &uBitCnt, 2) != 0x01)
         return MEDIA_UNSUPPORTED_TYPE;

      /* sampling frequency index */
      bSamplingFreqIndex = get_bits(pBuf, &uBitCnt, 4);
      
      aac.bIsTypeADTS = KAL_FALSE;
   } else {
      return MEDIA_BAD_FORMAT;
   }

   switch(bSamplingFreqIndex) {
      case 3:
         aac.wFreq = ASP_FS_48K;
         break;
      case 4:
         aac.wFreq = ASP_FS_44K;
         break;
      case 5:
         aac.wFreq = ASP_FS_32K;
         break;
      case 6:
         aac.wFreq = ASP_FS_24K;
         break;
      case 7:
         aac.wFreq = ASP_FS_22K;
         break;
      case 8:
         aac.wFreq = ASP_FS_16K;
         break;
      case 9:
         aac.wFreq = ASP_FS_12K;
         break;
      case 10:
         aac.wFreq = ASP_FS_11K;
         break;
      case 11:
         aac.wFreq = ASP_FS_8K;
         break;
      default:
         return MEDIA_UNSUPPORTED_FREQ;
      }

   return MEDIA_SUCCESS;
}



static int32 aacWriteIDMA( const kal_uint16 *buf, int32 len )
{
   int32 I, count;
   kal_uint16 rb_w;

   rb_w = *AAC_MCU_WRITE_PTR;

   do {
      I = (int32)*AAC_DSP_READ_PTR;
   } while( I != (int32)*AAC_DSP_READ_PTR );

   I = I - (int32)rb_w - 1;
   if( I < 0 )
      I += aac.ctrl->dsp_rb_size;

   if( I < len )
      len = I;

   if( len == 0 )
      return 0;

   count = (int32)(aac.ctrl->dsp_rb_end - rb_w);
   if( count > len )
      count = len;

   DSP_WRITE( DSP_PM_ADDR(0, rb_w), *buf++ );
   for( I = 1; I < count; I++ )
      DSP_WRITE( IDMA_SHORT_ADDR, *buf++ );

   rb_w += (kal_uint16)count;
   if( rb_w >= aac.ctrl->dsp_rb_end )
      rb_w = aac.ctrl->dsp_rb_base;
   *AAC_MCU_WRITE_PTR = rb_w;

   count = len - count;
   if( count > 0 ) {
     DSP_WRITE( DSP_PM_ADDR(0, rb_w), *buf++ );
     for( I = 1; I < count; I++ )
        DSP_WRITE( IDMA_SHORT_ADDR, *buf++ );

     *AAC_MCU_WRITE_PTR = rb_w + (uint16)count;
   }

   return len;
}

static void aacWriteToDSP( void )
{
   int32 I, count;

   count = mediaGetDataCount();

   I = aac.ctrl->rb_size - aac.ctrl->read;
   if( I > count )
      I = count;
   count -= I;

   I = aacWriteIDMA( &aac.ctrl->rb_base[aac.ctrl->read], I );
#if VERIFY_DATA_TO_DSP
   VERIFY_DATA_TO_DSP_WRITE_DATA( &aac.ctrl->rb_base[aac.ctrl->read], I );
#endif
   aac.ctrl->read += I;
   if( aac.ctrl->read >= aac.ctrl->rb_size ){
      aac.ctrl->read = 0;
      if( count > 0 ) {
         I = aacWriteIDMA( &aac.ctrl->rb_base[aac.ctrl->read], count );
#if VERIFY_DATA_TO_DSP
         VERIFY_DATA_TO_DSP_WRITE_DATA( &aac.ctrl->rb_base[aac.ctrl->read], I );
#endif
         aac.ctrl->read += I;
      }
   }
}

static void aacEndHandler(void *data, Media_Event event)
{
   (void) data;      // to avoid warning
   AM_AudioPlaybackOff( false );
   mediaSetEvent( MEDIA_END );
}

void aacPlaybackHisr( void )
{
   if( aac.ctrl->end_status == MEDIA_TERMINATED )
      return;

   if( DSP_AAC_STATE_IDLE == *AAC_MAIN_CONTROL ) {           /* DSP returns to idle state */
      /* To avoid the following data request message to overwrite the media end or media error message. */
      aac.ctrl->end_status = MEDIA_END;

      if (KAL_FALSE == aac.bError) {
#if APM_SUPPORT
         APM_NOTIFY_MEDIA_END( aacEndHandler, NULL, false , MEDIA_END);
#else
         aacEndHandler(NULL, 0);
#endif
      } else {
         AM_AudioPlaybackOff( false );
         mediaSetEvent( MEDIA_ERROR );
      }
      return;
   }

   if( aac.ctrl->end_status == MEDIA_END )
      return;

   /* check if DSP reports error */
   if (*AAC_ERROR_REPORT != 0 && *AAC_ERROR_REPORT != 0x2222)  /* bypass the buffer underflow warning from DSP */
   {
      *AAC_MAIN_CONTROL = DSP_AAC_STATE_STOP;
      aac.bError = KAL_TRUE;
      return;
   }

   if( aac.ctrl->dsp_rb_base == 0 ) {
     /* AAC_FIFO_BASE, AAC_FIFO_LENGTH, AAC_MCU_WRITE_PTR will be initialized by DSP at state '3' */
      aac.ctrl->dsp_rb_base = *AAC_FIFO_BASE;
      aac.ctrl->dsp_rb_size = *AAC_FIFO_LENGTH;
      aac.ctrl->dsp_rb_end = aac.ctrl->dsp_rb_base + aac.ctrl->dsp_rb_size;
   }

#if AAC_CHECK_BUFFER_UNDERFLOW
   /* check for audio ring buffer underflow */
   if( (mediaGetDataCount() == 0) && (!aac.ctrl->eof)) {
       /* If this happens, we have to enlarge the size of ring buffer. */
       ASSERT(KAL_FALSE);
   }
#endif

   aacWriteToDSP();

   if( mediaGetDataCount() == 0 && aac.ctrl->eof) {
      aac.ctrl->end_status = MEDIA_END;
      if( DSP_AAC_STATE_PLAYING == *AAC_MAIN_CONTROL )
         *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
   }
}

void aacPlayInternal(void)
{
   aac.ctrl->end_status = MEDIA_NONE;
   aac.ctrl->dsp_rb_base = 0;

   DSP_DynamicDownload( DDID_AAC );

   *DP_AUDIO_CTRL2 |= (DP_AAC_CTRL_ASP | DP_PCM_R_DIS);

   /* Set Digital Gain for AAC */
   AFE_SetDigitalGain(L1SP_AUDIO, aac.ctrl->level);

   ASSERT(*AAC_MAIN_CONTROL == DSP_AAC_STATE_IDLE);

   AM_AudioPlaybackOn( ASP_TYPE_AAC, aac.wFreq );

   *AAC_MAIN_CONTROL = DSP_AAC_STATE_START;

   {
      kal_uint16 I;
      for( I = 0; ; I++ ) {
         if (DSP_AAC_STATE_PLAYING == *AAC_MAIN_CONTROL || aac.ctrl->end_status == MEDIA_END)
            break;
         if (DSP_AAC_STATE_IDLE == *AAC_MAIN_CONTROL) {
            /* This is the case when AAC codec has started and encoutered an error,
               aacPlaybackHisr found this and set the state to STOP, then AAC codec
               set the state to IDLE. */
            break;
         }
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }

   aac.bState = AAC_STATE_PLAY;
}

Media_Status aacPlay( mediaControl *mctrl)
{
   aac.ctrl = mctrl;
   aac.bError = KAL_FALSE;

#if VERIFY_AAC_STEP1
   setup_ring_buffer();
#endif

   /* Parse AAC Header */
   {
      Media_Status ret;
      if ((ret=aac_parse_header())!=MEDIA_SUCCESS)
         return ret;
   }

   aacPlayInternal();

   return MEDIA_SUCCESS;
}

void aacStopInternal( void )
{
   kal_uint32 I;

   for( I = 0; ; I++ ) {
      if( DSP_AAC_STATE_IDLE == *AAC_MAIN_CONTROL )          /* DSP returns to idle state */
         break;
      if( DSP_AAC_STATE_PLAYING == *AAC_MAIN_CONTROL ) {
         *AAC_MAIN_CONTROL = DSP_AAC_STATE_STOP;             /* give ABORT command to the DSP */
      }
      ASSERT_REBOOT( I < 80 );
      kal_sleep_task( 2 );
   }
   AM_AudioPlaybackOff( true );
   *DP_AUDIO_CTRL2 &= ~(DP_AAC_CTRL_ASP | DP_PCM_R_DIS);
}

void aacStop( void )
{
   if (AAC_STATE_PAUSE == aac.bState)
      return;

   aac.ctrl->end_status = MEDIA_TERMINATED;
   aacStopInternal();
   aac.bState = AAC_STATE_STOP;
}

kal_uint32 getByte(kal_uint32 uByteOffset)
{
   kal_uint32 uLocation;
   kal_uint32 uReadData;

   uLocation = (aac.ctrl->read) + (uByteOffset>>1);
   if (uLocation >= aac.ctrl->rb_size)
      uLocation -= aac.ctrl->rb_size;
   uReadData = aac.ctrl->rb_base[uLocation];
   if (uByteOffset&0x01) {
      return (uReadData>>8);
   } else {
      return (uReadData&0x00FF);
   }
}

kal_bool aacSeekFrameHeader() {
   kal_uint32 I, uDataCount;

   uDataCount = mediaGetDataCount()*2; // number of bytes in ring buffer

   if (uDataCount<4)
      return KAL_FALSE;

   for (I=0; I<uDataCount-3; I++) {
      kal_uint8 bHeader[4];
      bHeader[0] = getByte(I);
      bHeader[1] = getByte(I+1);
      bHeader[2] = getByte(I+2);
      bHeader[3] = getByte(I+3);
      bHeader[3] &= 0xF0;
      if (kal_mem_cmp(aac.bADTSFixedHeader, bHeader, 4)==0) {
         if (I&0x01)
            I--;
         I >>= 1;
         aac.ctrl->read += I;
         if (aac.ctrl->read >= aac.ctrl->rb_size)
            aac.ctrl->read -= aac.ctrl->rb_size;
         return KAL_TRUE;
      }
   }

   return KAL_FALSE;
}

Media_Status aacPause(mediaControl *mctrl)
{
   if( aac.bIsTypeADTS == KAL_FALSE )
      return MEDIA_UNSUPPORTED_OPERATION;
   aac.ctrl->end_status = MEDIA_TERMINATED;
   aacStopInternal();
   aac.bState = AAC_STATE_PAUSE;
   return MEDIA_SUCCESS;
}

Media_Status aacResume(mediaControl *mctrl)
{
   if (AAC_STATE_PAUSE == aac.bState) {
      if (aacSeekFrameHeader()==KAL_FALSE)
         return MEDIA_BAD_FORMAT;
      aacPlayInternal();
   }

   return MEDIA_SUCCESS;
}

void aacUpdateLevel( void )
{
   AFE_SetDigitalGain( L1SP_AUDIO, aac.ctrl->level );
}

#endif /* AAC_DECODE */


