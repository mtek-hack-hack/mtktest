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
 * rtp_amr_drv.c
 *
 * Project:
 * --------
 *   MTK6229
 *
 * Description:
 * ------------
 *   RTP Audio interface for AMR/AWB
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
// NOTE: At present, this is just a limited implementation, supporting:
// octet-alignment only; no interleaving; no frame CRC; no robust-sorting.

//#define STREAM_SUPPORT
//#define AUD_RTP_UNIT_TEST

#include "media.h"
#include "audio_rtp.h"
#include "l1sp_trc.h"
#include "afe.h"

#if defined(STREAM_SUPPORT)
// The mapping from the "FT" field to frame size.
static const uint8 AMR_frame_length[] = { 12, 13, 15, 17, 19, 20, 26, 31, 5, 6, 5, 5, 0, 0, 0, 0 };
static const uint8 AWB_frame_length[] = { 17, 23, 32, 36, 40, 46, 50, 58, 60, 5, 0, 0, 0, 0, 0, 0 };

#if defined (AUD_RTP_UNIT_TEST)
static uint8 packet_buffer[5][173] = {
{
0x80, 0x60, 0x36, 0x67, 0x2d, 0xac,
0x6b, 0x1e, 0x26, 0xc0, 0xbc, 0xce, 0xf0, 0xbc, 0xbc, 0xbc, 0xbc, 0x3c, 0x2a, 0x53, 0xa3, 0xb0,
0x30, 0xcb, 0xc5, 0xcc, 0xcc, 0x80, 0x3f, 0xf7, 0x02, 0x76, 0x62, 0x80, 0x00, 0x7b, 0x6d, 0x1a,
0x08, 0x56, 0x58, 0x00, 0x05, 0xf4, 0xf2, 0x16, 0xd2, 0xb1, 0x50, 0x0e, 0xb9, 0x5d, 0x28, 0xcb,
0x98, 0x42, 0x06, 0x99, 0x84, 0x9c, 0x27, 0x98, 0x06, 0x96, 0x0f, 0x07, 0x4f, 0x2d, 0xea, 0x82,
0x8f, 0xfb, 0x38, 0x4e, 0xbb, 0x64, 0x05, 0x7d, 0xff, 0xd0, 0x3b, 0x36, 0x87, 0x9d, 0x59, 0x26,
0x10, 0xe5, 0xa3, 0x80, 0x07, 0xc4, 0x3c, 0xe6, 0x7d, 0xc0, 0xed, 0x79, 0x58, 0xf0, 0x47, 0xf8,
0xa4, 0x58, 0x34, 0xa7, 0x70, 0x65, 0x90, 0x6d, 0xd0, 0x42, 0x7e, 0x74, 0x45, 0x60, 0x5e, 0x02,
0xc1, 0xfe, 0x7b, 0x54, 0xdd, 0x75, 0x34, 0xa3, 0xec, 0x13, 0x7a, 0x5f, 0x02, 0xa6, 0x42, 0x38,
0x9e, 0x3e, 0x1e, 0xc9, 0xd4, 0x5f, 0xb9, 0x30, 0x2e, 0xed, 0x69, 0x9b, 0xbe, 0xc8, 0x41, 0xa1,
0xff, 0xd0, 0x95, 0x86, 0x11, 0x47, 0xbe, 0x8b, 0x96, 0x24, 0xe5, 0x7b, 0x20, 0x3d, 0xb5, 0x9d,
0x88, 0x24, 0x78, 0xa7, 0x30, 0x16, 0xd0
},
{
0x80, 0x60, 0x36, 0x68, 0x2d, 0xac,
0x6e, 0x3e, 0x26, 0xc0, 0xbc, 0xce, 0xf0, 0xbc, 0xbc, 0xbc, 0xbc, 0x3c, 0x54, 0x70, 0x9b, 0x22,
0xe9, 0xe2, 0x14, 0x30, 0xef, 0x83, 0xc8, 0xf2, 0x78, 0xe8, 0x02, 0x6a, 0x7c, 0xc9, 0xbc, 0x6d,
0x0e, 0x38, 0xb7, 0x8d, 0x5e, 0x23, 0x00, 0x03, 0xcd, 0xbf, 0x80, 0xf2, 0x71, 0x71, 0xb0, 0x1f,
0x68, 0x14, 0x29, 0x76, 0x6b, 0x42, 0x59, 0x0e, 0x83, 0xc1, 0xd8, 0x1b, 0x0a, 0x73, 0xca, 0xe7,
0x8a, 0x87, 0x46, 0xbd, 0xc3, 0x88, 0xf2, 0x4a, 0x5d, 0x50, 0x90, 0x71, 0x1d, 0x32, 0xc8, 0x0c,
0x03, 0x41, 0xfe, 0x55, 0xbe, 0x0e, 0xcf, 0x5e, 0x40, 0xfa, 0xa4, 0x3c, 0x7b, 0x30, 0xa1, 0xb5,
0x2a, 0x62, 0xa2, 0x6e, 0x44, 0xe0, 0xef, 0x88, 0x20, 0x22, 0x72, 0x5f, 0x8a, 0x38, 0x7e, 0x4a,
0x29, 0x77, 0x01, 0x33, 0x43, 0x7d, 0x8c, 0xaa, 0xea, 0xbb, 0xb1, 0xf2, 0xca, 0x44, 0xd4, 0x87,
0x6c, 0xc8, 0x3e, 0x80, 0x52, 0x70, 0x92, 0x20, 0x46, 0xec, 0x79, 0x3c, 0x69, 0xac, 0x01, 0x63,
0xdd, 0x38, 0xd9, 0xd6, 0xaa, 0xc0, 0x0c, 0x8f, 0x38, 0x34, 0x26, 0x63, 0x5e, 0x9e, 0x9f, 0xef,
0xf7, 0x3c, 0x2e, 0x80, 0x83, 0x71, 0x50
},
{
0x80, 0x60, 0x36, 0x69, 0x2d, 0xac,
0x71, 0x5e, 0x26, 0xc0, 0xbc, 0xce, 0xf0, 0xbc, 0xbc, 0xbc, 0xbc, 0x3c, 0x20, 0x5c, 0x69, 0x94,
0x0b, 0xe2, 0x21, 0xc1, 0xee, 0x23, 0x54, 0x4e, 0x74, 0x16, 0x7d, 0xf6, 0x15, 0xcf, 0xfa, 0x9e,
0xd0, 0xaf, 0xf4, 0x58, 0x72, 0xe9, 0xaa, 0xc3, 0x5f, 0x9a, 0xf0, 0x46, 0xed, 0x68, 0x8a, 0xba,
0xf4, 0x48, 0x30, 0xef, 0xc9, 0x78, 0x63, 0x42, 0x5f, 0x11, 0xf0, 0x0d, 0x84, 0xac, 0x8c, 0x29,
0xbd, 0x0b, 0xcf, 0x91, 0x0e, 0xba, 0x3e, 0x6c, 0x13, 0x20, 0x34, 0x6c, 0x6b, 0x32, 0x13, 0xf4,
0x08, 0x21, 0xff, 0x80, 0xf6, 0x2a, 0xd6, 0x55, 0xda, 0x76, 0x52, 0xee, 0xae, 0x19, 0x57, 0x91,
0x9f, 0x96, 0x1b, 0x82, 0x8a, 0x4e, 0x83, 0xbe, 0x20, 0xef, 0x33, 0x6c, 0x8c, 0x1b, 0x8c, 0x10,
0xf0, 0xee, 0x57, 0xb7, 0x07, 0x4c, 0x12, 0x8d, 0xbe, 0xe4, 0x9c, 0x57, 0xf8, 0x8c, 0x87, 0xb4,
0x77, 0x91, 0x78, 0x86, 0x2b, 0xf1, 0xe9, 0x60, 0x48, 0x64, 0x6d, 0x45, 0xf8, 0x3c, 0x0a, 0x03,
0xdc, 0xd0, 0xb8, 0xf0, 0xb1, 0xbd, 0x66, 0x7a, 0x4a, 0x6d, 0x23, 0xca, 0xda, 0xfb, 0xa4, 0x02,
0x4f, 0x03, 0x11, 0x61, 0x28, 0x87, 0xb0
},
{
0x80, 0x60, 0x36, 0x6a, 0x2d, 0xac,
0x74, 0x7e, 0x26, 0xc0, 0xbc, 0xce, 0xf0, 0xbc, 0xbc, 0xbc, 0xbc, 0x3c, 0x49, 0x00, 0x90, 0x77,
0xec, 0x49, 0x99, 0xd8, 0x63, 0x7b, 0x62, 0xd8, 0x49, 0x25, 0xc8, 0x59, 0x31, 0x94, 0x57, 0x81,
0xfb, 0x00, 0xad, 0xb8, 0x67, 0xa2, 0xe1, 0xab, 0x5d, 0x93, 0x70, 0x3a, 0x64, 0x67, 0xfa, 0xfa,
0xf8, 0x03, 0x81, 0xfe, 0xb7, 0xde, 0xe9, 0xc9, 0xcc, 0x90, 0xd9, 0xf1, 0x86, 0x55, 0x5e, 0xe1,
0xb3, 0xec, 0x2e, 0xc9, 0x3a, 0x9c, 0xa4, 0xf0, 0x4c, 0x90, 0x26, 0x72, 0x7b, 0x70, 0xb6, 0x02,
0x12, 0xc9, 0x71, 0x06, 0x61, 0xa3, 0xbf, 0x30, 0x6c, 0x82, 0x82, 0x43, 0x07, 0x9e, 0x41, 0xfd,
0x8d, 0xc2, 0xba, 0xa1, 0x52, 0xe3, 0x2a, 0x6a, 0x90, 0x46, 0x67, 0x69, 0xe5, 0x5d, 0xa2, 0x05,
0x81, 0xfd, 0x13, 0x78, 0x8b, 0xc1, 0xae, 0xb3, 0x7e, 0xf2, 0xbb, 0xf0, 0xc2, 0x40, 0x38, 0x0c,
0xc0, 0xad, 0x5a, 0xf7, 0xf6, 0xae, 0xf7, 0x60, 0x1c, 0x7e, 0x71, 0x27, 0x5e, 0xc7, 0x0b, 0x41,
0xfe, 0x3b, 0x97, 0xa4, 0xf2, 0xfa, 0x4d, 0x74, 0xa8, 0x3c, 0x91, 0x4e, 0x9b, 0x73, 0xb4, 0xb4,
0xec, 0xf4, 0xc1, 0x6f, 0x6c, 0x70, 0xf0
},
{
0x80, 0x60, 0x36, 0x6b, 0x2d, 0xac,
0x77, 0x9e, 0x26, 0xc0, 0xbc, 0xce, 0xf0, 0xbc, 0xbc, 0xbc, 0xbc, 0x3c, 0x56, 0xed, 0x23, 0xb4,
0x48, 0x2e, 0x01, 0xe1, 0xff, 0x0a, 0xb5, 0x18, 0x24, 0xd1, 0xab, 0xa4, 0x28, 0xfa, 0x8f, 0x04,
0x9a, 0x2f, 0xb4, 0x16, 0x9c, 0xf1, 0xed, 0x87, 0xf9, 0xc3, 0x20, 0x30, 0x5e, 0x79, 0x1a, 0xbe,
0xa6, 0x15, 0xe1, 0xfe, 0xca, 0xf5, 0x08, 0xc5, 0x5a, 0x0f, 0x8c, 0xf9, 0xa3, 0xeb, 0xb0, 0x5f,
0xe4, 0x45, 0xee, 0x20, 0x0b, 0xad, 0x48, 0x14, 0xba, 0x20, 0x34, 0x68, 0x82, 0xb2, 0x98, 0xf0,
0x12, 0xe3, 0xd5, 0x9d, 0x27, 0x9d, 0x0f, 0xc5, 0xbf, 0xc0, 0x51, 0xdb, 0x54, 0x98, 0xbd, 0x27,
0x85, 0xfe, 0xb9, 0x91, 0xfc, 0x84, 0x26, 0xad, 0x10, 0x2e, 0x66, 0x7f, 0x24, 0x5c, 0xe6, 0x01,
0xe1, 0xee, 0x94, 0xd5, 0x6e, 0x99, 0x11, 0x2a, 0x8a, 0xc3, 0xd4, 0x87, 0x27, 0x37, 0x0f, 0x4c,
0xb9, 0xc1, 0xdf, 0xdb, 0xb0, 0xa8, 0x2a, 0x90, 0x3e, 0xec, 0x60, 0x8e, 0xe2, 0x88, 0x01, 0x21,
0xfe, 0x71, 0xb6, 0x74, 0x57, 0x8c, 0x5e, 0x7e, 0x10, 0xba, 0x45, 0x72, 0x0b, 0x65, 0x5c, 0x08,
0x42, 0x49, 0x35, 0xb7, 0xee, 0x39, 0x40
}};

static int packet_size[5] = { 173, 173, 173, 173, 173 };

#endif // #if defined (AUD_RTP_UNIT_TEST)

#define  RTP_AMR_STATE_DL_INIT           0x00
#define  RTP_AMR_STATE_DL_CONFIGURED     0x01
#define  RTP_AMR_STATE_DL_READY          0x02
#define  RTP_AMR_STATE_DL_DECODE         0x03

#define  MED_BUF_SIZE 22400
#define  MAX_PACKET_SIZE  2048
#define  MAX_JITTER_PACKET_CNT  5
#define  JITTER_BUF_SIZE (MAX_PACKET_SIZE * MAX_JITTER_PACKET_CNT)
#define  MAX_PACKET_LOSS 5
#define  AMR_FRAME_DUR   20  // ms

static AudRTP_DL_HANDLE  *psAudRTPamr = 0;

static void amrPutNByte( AudRTP_DL_HANDLE *hdl, kal_uint8* pbBuf, kal_uint32 uLen )
{
   kal_uint8 *buffer;
   kal_uint32 buf_len;

   hdl->psMHdl->GetWriteBuffer( hdl->psMHdl, &buffer, &buf_len );
   if(uLen > buf_len){
      uLen -= buf_len;
      memcpy( buffer, pbBuf, buf_len);
      hdl->psMHdl->WriteDataDone(hdl->psMHdl, buf_len);
      pbBuf += buf_len;
   }
   if(uLen > 0){
      hdl->psMHdl->GetWriteBuffer( hdl->psMHdl, &buffer, &buf_len );
      memcpy( buffer, pbBuf, uLen);
      hdl->psMHdl->WriteDataDone(hdl->psMHdl, uLen);
   }
}

static AudRTP_STATUS AudRTP_AMR_GetCodecCapability(AudRTP_DL_HANDLE *hdl,
                                                   rtp_audio_codec_type codec_type,
                                                   rtp_audio_codec_cap *codec_cap )
{
   (void)hdl;
   ASSERT((codec_type == RTP_AUDIO_AMR) || (codec_type == RTP_AUDIO_AWB));
   memset(codec_cap, 0, sizeof(rtp_audio_codec_cap));
   codec_cap->amr.octet_align        = KAL_TRUE;
   codec_cap->amr.channels           = 1;

   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AMR_Config(AudRTP_DL_HANDLE *hdl,
                                   rtp_audio_codec_type codec_type,
                                   rtp_audio_codec_cap *codec_cap,
                                   AudRTP_DL_CALLBACK callback,
                                   void *host_data, kal_uint32 session_id )
{
   ASSERT((codec_type == RTP_AUDIO_AMR) || (codec_type == RTP_AUDIO_AWB));
   ASSERT( hdl->uState == RTP_AMR_STATE_DL_INIT );

   hdl->callback = callback;
   hdl->host_data = (kal_uint32)host_data;
   hdl->session_id = session_id;
   memcpy( &hdl->stCodecCap, codec_cap, sizeof(rtp_audio_codec_cap));
   hdl->eAudCodecType = codec_type;

   if(KAL_TRUE != codec_cap->amr.octet_align)
      return AudRTP_STATUS_NOT_OCTET_ALIGN;

   if(codec_cap->amr.channels != 1)
      return AudRTP_STATUS_NOT_SINGLE_CHANNEL;

   hdl->uState = RTP_AMR_STATE_DL_CONFIGURED;
   return AudRTP_STATUS_SUCCESS;
}

static kal_uint32 AudRTP_AMR_GetSamplingFreq( AudRTP_DL_HANDLE *hdl )
{
   if( RTP_AUDIO_AMR == hdl->eAudCodecType )
      return 8000;
   else if( RTP_AUDIO_AWB == hdl->eAudCodecType )
      return 16000;
   else
      ASSERT(0); // never reach here
}

static kal_uint8 AudRTP_AMR_GetChannelNum( AudRTP_DL_HANDLE *hdl )
{
   return hdl->stCodecCap.amr.channels;
}

static void AudRTP_AMR_SetVolumeLevel( AudRTP_DL_HANDLE *hdl, kal_uint8 level )
{
   ASSERT( level <= 100 );
   AFE_SetDigitalGain(L1SP_AUDIO, level);
   AFE_SetDigitalGain(L1SP_VOICE, level);
}

static kal_uint32 AudRTP_AMR_GetBufferSize(AudRTP_DL_HANDLE *hdl )
{
   return (MED_BUF_SIZE + JITTER_BUF_SIZE); // Buffer size fixed at 8+8 KB
}

static AudRTP_STATUS AudRTP_AMR_SetBuffer(AudRTP_DL_HANDLE *hdl, kal_uint8 *buffer, kal_uint32 buffer_size )
{
   ASSERT( hdl->uState == RTP_AMR_STATE_DL_CONFIGURED );
   ASSERT(((uint32)buffer & 3) == 0 );       /* make sure 4-byte alignment */
   ASSERT( (buffer_size & 1) == 0 );         /* insure 2-byte alignment */
   hdl->psMHdl->SetBuffer( hdl->psMHdl, buffer, MED_BUF_SIZE );

   if(hdl->eAudCodecType == RTP_AUDIO_AMR) // initialize file header for streaming played back
      amrPutNByte( hdl, (kal_uint8*)"#!AMR\n", 6 );
   else
      amrPutNByte( hdl, (kal_uint8*)"#!AMR-WB\n", 9 );

   if(hdl->host_data){ // silent mode
      kal_uint32 uCnt;
      kal_uint8 AMR_Header = 0x7C;
      for(uCnt=5; uCnt>0; uCnt--)
         amrPutNByte( hdl, &AMR_Header, 1 );
      hdl->uTotalFrameInBuf+=5;
   }

   { // initialize Jitter Buffer
      kal_uint32 uCnt;
      for(uCnt=0; uCnt<MAX_JIT_PKT_CNT; uCnt++)
         hdl->stJitBuf[uCnt].pAddrs = hdl->psMHdl->rb_base + MED_BUF_SIZE +(MAX_PACKET_SIZE * uCnt);
   }

   hdl->uState = RTP_AMR_STATE_DL_READY;
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AMR_Close(AudRTP_DL_HANDLE *hdl )
{
   ASSERT( hdl->uState != RTP_AMR_STATE_DL_DECODE );

   hdl->psMHdl->Close(hdl->psMHdl);
   psAudRTPamr = (AudRTP_DL_HANDLE  *)0;
   free_ctrl_buffer( hdl );

   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AMR_Start(AudRTP_DL_HANDLE *hdl, kal_uint32 start_time )
{
   Media_Status res;
   ASSERT( hdl->uState == RTP_AMR_STATE_DL_READY );

   if(hdl->psMHdl->write == 6) // buffer underflow
      return AudRTP_STATUS_FAIL;

   hdl->psMHdl->start_time = start_time;
   res = hdl->psMHdl->Play(hdl->psMHdl);
   if(res != MEDIA_SUCCESS) // Play Fail
      return AudRTP_STATUS_FAIL;
   hdl->psMHdl->current_time = start_time;
   hdl->uPacketLossCnt = 0;
   hdl->uState = RTP_AMR_STATE_DL_DECODE;
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AMR_Stop(AudRTP_DL_HANDLE *hdl )
{
   ASSERT( hdl->uState == RTP_AMR_STATE_DL_DECODE );
   hdl->psMHdl->Stop(hdl->psMHdl);
   hdl->psMHdl->write = 0;  // Reset Media Buffer
   hdl->psMHdl->read = 0;
   hdl->psMHdl->eof = false;
   hdl->psMHdl->waiting = false;
   hdl->uTotalFrameInBuf = 0;
   hdl->uPrePacketNum = 0;
   hdl->uPreTimeStamp = 0;

   hdl->uState = RTP_AMR_STATE_DL_READY;
   return AudRTP_STATUS_SUCCESS;
}
// Put packet to media buffer including silence padding
static AudRTP_STATUS rtpAmrPutPacket( AudRTP_DL_HANDLE *psRTPHdl, kal_uint8 *pbBuf, kal_uint32 uBufSize,
                  kal_uint32 uPacketNum, kal_uint32 uTimeStamp )
{
   const kal_uint8 *pbToc;
   kal_uint32 uFrameCnt, uFrameLen;
   kal_uint8 bFT;

   {   // check if packet loss or not, put no data frame to media buffer if need
       kal_uint8 AMR_Header = 0x7C;

       if(psRTPHdl->uPrePacketNum != (uPacketNum-1)){
          kal_uint32 uFrameCnt = uTimeStamp - psRTPHdl->uPreTimeStamp;
          if(RTP_AUDIO_AMR == psRTPHdl->eAudCodecType)
             uFrameCnt /= 160;
          else
             uFrameCnt /= 320;

          if( psRTPHdl->psMHdl->GetFreeSpace(psRTPHdl->psMHdl) < uFrameCnt ){
             kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_OF, 0, MEDIA_FORMAT_AMR);
             mhdlException( psRTPHdl->psMHdl, (Media_Event)AudRTP_EVENT_BUF_OVERFLOW );
             return AudRTP_STATUS_FAIL;            /* buffer overflow */
          }
          psRTPHdl->uTotalFrameInBuf+=uFrameCnt;
          kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PUT_SIL, uPacketNum, uFrameCnt, MEDIA_FORMAT_AMR);
          for(;uFrameCnt!=0; uFrameCnt--)
             amrPutNByte( psRTPHdl, &AMR_Header, 1 );
       }

       if( (uPacketNum - psRTPHdl->uPrePacketNum) > MAX_PACKET_LOSS  ){
          kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PKT_LOSS, (uPacketNum - psRTPHdl->uPrePacketNum) , MEDIA_FORMAT_AMR);
          mhdlException( psRTPHdl->psMHdl, (Media_Event)AudRTP_EVENT_PACKET_LOSS );
          //return AudRTP_STATUS_FAIL;
       }
   }

   psRTPHdl->uPrePacketNum = uPacketNum;
   psRTPHdl->uPreTimeStamp = uTimeStamp;

   if( psRTPHdl->psMHdl->GetFreeSpace(psRTPHdl->psMHdl) < uBufSize ){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_OF, 1, MEDIA_FORMAT_AMR);
      mhdlException( psRTPHdl->psMHdl, (Media_Event)AudRTP_EVENT_BUF_OVERFLOW );
      return AudRTP_STATUS_FAIL;            /* buffer overflow */
   }

   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PUT_PKT, uPacketNum, uTimeStamp, MEDIA_FORMAT_AMR);

   pbBuf+=13;
   uBufSize-=13;         /* ignore RTP header & CMR */
   pbToc = pbBuf;
   uFrameCnt = 1;
   while( *pbBuf++ & 0x80 )
      uFrameCnt++;
   while( uFrameCnt > 0 ) {
      kal_uint8 bTmp;
                  
      bFT = *pbToc++ & 0x7F;
      bTmp = (bFT >> 3) & 0x0F;
      if(RTP_AUDIO_AMR == psRTPHdl->eAudCodecType){
         //ASSERT( bTmp <= 8 || bTmp == 15 );
         uFrameLen = AMR_frame_length[bTmp];
      }else{
          //ASSERT( bTmp <= 9 || bTmp == 15 );
          uFrameLen = AWB_frame_length[bTmp];
       }

      uBufSize -= (uFrameLen+1);
      if((kal_int32)uBufSize < 0)
         break;

      amrPutNByte( psRTPHdl, &bFT, 1 );

      if( uFrameLen > 0 ) {
         amrPutNByte( psRTPHdl, pbBuf, uFrameLen );
         pbBuf += uFrameLen;
      }
      
      psRTPHdl->uTotalFrameInBuf++;
      uFrameCnt--;
   }
   return AudRTP_STATUS_SUCCESS;
}

// Put packet to Jitter buffer
static void amrJitterBuf(AudRTP_DL_HANDLE *psRTPHdl, kal_uint8 *pbBuf, kal_uint32 uBufSize, kal_uint32 uPacketNum, kal_uint32 uTimeStamp)
{
   kal_uint32 uCnt;

   ASSERT(uBufSize<=MAX_PACKET_SIZE);

   for(uCnt = 0; uCnt<MAX_JIT_PKT_CNT; uCnt++){
      if( 0 == psRTPHdl->stJitBuf[uCnt].uPktSize ){
         psRTPHdl->stJitBuf[uCnt].uPktSize = uBufSize;
         psRTPHdl->stJitBuf[uCnt].uSeqNum = uPacketNum;
         psRTPHdl->stJitBuf[uCnt].uTimeStamp = uTimeStamp;
         memcpy(psRTPHdl->stJitBuf[uCnt].pAddrs, pbBuf, uBufSize);
         break;
      }
   }

   psRTPHdl->uJitterBufPacketCnt++;
   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PutPktToJitter, uPacketNum, psRTPHdl->uJitterBufPacketCnt, uCnt, MEDIA_FORMAT_AMR);
}
// Get packet from Jitter buffer
static void amrGetPkt(AudRTP_DL_HANDLE *psRTPHdl, kal_uint8 **pbBuf, kal_uint32 *uBufSize, kal_uint32 *uPacketNum, kal_uint32 *uTimeStamp)
{
   kal_uint32 uCnt, uCandidate=0;
   JitterBuf *ptr;

   for(uCnt=0; uCnt<MAX_JIT_PKT_CNT; uCnt++){
      if(0 != psRTPHdl->stJitBuf[uCnt].uSeqNum){
         if(!uCandidate)
            uCandidate = uCnt;
         if( psRTPHdl->stJitBuf[uCandidate].uSeqNum > psRTPHdl->stJitBuf[uCnt].uSeqNum)
            uCandidate = uCnt;
      }
   }

   ptr = &psRTPHdl->stJitBuf[uCandidate];

   *pbBuf = ptr->pAddrs;
   *uBufSize = ptr->uPktSize;
   *uPacketNum = ptr->uSeqNum;
   *uTimeStamp = ptr->uTimeStamp;   
   
   ptr->uPktSize = 0;
   ptr->uPktSize = 0;
   ptr->uTimeStamp = 0;
   psRTPHdl->uJitterBufPacketCnt--;
   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_GetFromJitter, ptr->uSeqNum, psRTPHdl->uJitterBufPacketCnt, uCandidate);
}
// Query sequence number of the earliest packet in Jitter buffer
static kal_uint32 amrGetPktNum(AudRTP_DL_HANDLE *psRTPHdl)
{
   kal_uint32 uCnt, uCandidate=0;
   JitterBuf *ptr;

   for(uCnt=0; uCnt<MAX_JIT_PKT_CNT; uCnt++){
      if(0 != psRTPHdl->stJitBuf[uCnt].uSeqNum){
         if(!uCandidate)
            uCandidate = uCnt;
         if( psRTPHdl->stJitBuf[uCandidate].uSeqNum > psRTPHdl->stJitBuf[uCnt].uSeqNum)
            uCandidate = uCnt;
      }
   }

   ptr = &psRTPHdl->stJitBuf[uCandidate];

   return ptr->uSeqNum;
}

static AudRTP_STATUS AudRTP_AMR_PutPacket( AudRTP_DL_HANDLE *psRTPHdl, kal_uint8 *pbBuf, kal_uint32 uBufSize )
{
   kal_uint32 uPacketNum, uTimeStamp, uTmpPktNum;
   AudRTP_STATUS ret;

   uPacketNum = AudRTP_getPacketNum( pbBuf, uBufSize );
   uTimeStamp = AudRTP_getTimeStamp( pbBuf, uBufSize );
   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PUTPKT_FUNC, uPacketNum, uTimeStamp, uBufSize, MEDIA_FORMAT_AMR );

   if(psRTPHdl->uPrePacketNum == 0){
       psRTPHdl->uPrePacketNum = uPacketNum-1;
       kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PUTPKT_FST, uPacketNum, MEDIA_FORMAT_AMR);
       if( (ret = rtpAmrPutPacket( psRTPHdl, pbBuf, uBufSize,uPacketNum, uTimeStamp )) != AudRTP_STATUS_SUCCESS)
          return ret;
       return AudRTP_STATUS_SUCCESS;
   }

   amrJitterBuf(psRTPHdl, pbBuf, uBufSize, uPacketNum, uTimeStamp);
   uTmpPktNum = amrGetPktNum(psRTPHdl);

   if(psRTPHdl->uPrePacketNum >= uTmpPktNum){  // discard duplicate or loss packet
      amrGetPkt(psRTPHdl, &pbBuf, &uBufSize, &uPacketNum, &uTimeStamp);
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_DISCAR, uPacketNum, MEDIA_FORMAT_AMR);
      psRTPHdl->uPacketLossCnt++;
      if( (psRTPHdl->uPacketLossCnt) > MAX_PACKET_LOSS  ){
          kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PKT_LOSS, (uTmpPktNum - psRTPHdl->uPrePacketNum), MEDIA_FORMAT_AMR );
          mhdlException( psRTPHdl->psMHdl, (Media_Event)AudRTP_EVENT_PACKET_LOSS );
          return AudRTP_STATUS_FAIL;
       }
      return AudRTP_STATUS_SUCCESS;
   }

   if(psRTPHdl->uPrePacketNum != (uTmpPktNum-1)){
      if(psRTPHdl->uJitterBufPacketCnt < MAX_JITTER_PACKET_CNT){
         return AudRTP_STATUS_SUCCESS;
      }else{
          amrGetPkt(psRTPHdl, &pbBuf, &uBufSize, &uPacketNum, &uTimeStamp);
          kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PutPktFromJitter, uPacketNum, psRTPHdl->uJitterBufPacketCnt, MEDIA_FORMAT_AMR);
          if( (ret = rtpAmrPutPacket( psRTPHdl, pbBuf, uBufSize,uPacketNum, uTimeStamp )) != AudRTP_STATUS_SUCCESS)
             return ret;
      }
   }else{
       amrGetPkt(psRTPHdl, &pbBuf, &uBufSize, &uPacketNum, &uTimeStamp);
       kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PutPkt, uPacketNum, psRTPHdl->uJitterBufPacketCnt, MEDIA_FORMAT_AMR);
       if( (ret = rtpAmrPutPacket( psRTPHdl, pbBuf, uBufSize,uPacketNum, uTimeStamp )) != AudRTP_STATUS_SUCCESS)
          return ret;
   }

   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AMR_GetPlayTime(AudRTP_DL_HANDLE *hdl, kal_uint32 *p_current_time)
{
   *p_current_time = hdl->psMHdl->current_time;
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_AMR_GetBufferStatus(AudRTP_DL_HANDLE *psRTPHdl, kal_uint32 *puCurBufDur,
               kal_uint32 *puBufFreeSize, kal_uint32 *puBufTotalSize, kal_uint32 *puMinBufTotalDur)
{
   *puCurBufDur = psRTPHdl->uTotalFrameInBuf * AMR_FRAME_DUR; // in ms
   *puBufTotalSize = MED_BUF_SIZE - 1;
   *puBufFreeSize = psRTPHdl->psMHdl->GetFreeSpace(psRTPHdl->psMHdl);

   // max. frame size:  AMR == 32B;  AWB == 61B;
   if(psRTPHdl->eAudCodecType == RTP_AUDIO_AMR)
      *puMinBufTotalDur = 14000; // 22400 / 32 * 20
   else
      *puMinBufTotalDur = 7344; // 22400 / 61 * 20

   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_BUF_STATUS, *puCurBufDur, *puBufTotalSize, *puBufFreeSize, *puMinBufTotalDur );
   return AudRTP_STATUS_SUCCESS;
}

static void amr_Handler( MHdl *handle, Media_Event event )
{
   (void)event;   /* do nothing */
   (void)handle;
   ASSERT(psAudRTPamr != 0);

   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_FRM_IN_BUF, psAudRTPamr->uTotalFrameInBuf, MEDIA_FORMAT_AMR);
   //ASSERT(event != MEDIA_ERROR);

   if(event == MEDIA_ERROR){
      psAudRTPamr->callback(AudRTP_EVENT_MEDIA_ERROR, psAudRTPamr, (void  *)psAudRTPamr->host_data);
      return;
   }

   if((AudRTP_EVENT)event == AudRTP_EVENT_BUF_OVERFLOW){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_OF, 0, MEDIA_FORMAT_AMR);
      psAudRTPamr->callback(AudRTP_EVENT_BUF_OVERFLOW, psAudRTPamr, (void  *)psAudRTPamr->host_data);
      return;
   }else if((AudRTP_EVENT)event == AudRTP_EVENT_PACKET_LOSS){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PKT_LOSS, MAX_PACKET_LOSS, MEDIA_FORMAT_AMR);
      psAudRTPamr->callback(AudRTP_EVENT_PACKET_LOSS, psAudRTPamr, (void  *)psAudRTPamr->host_data);
      return;
    }

   if(psAudRTPamr->host_data){ // silent mode
      kal_uint8 AMR_Header = 0x7C;
      amrPutNByte( psAudRTPamr, &AMR_Header, 1 );
      psAudRTPamr->uTotalFrameInBuf++;
   }

   if(psAudRTPamr->uTotalFrameInBuf > 0)
      psAudRTPamr->uTotalFrameInBuf--;
   if( psAudRTPamr->psMHdl->GetDataCount(psAudRTPamr->psMHdl) == 0 ){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_UF, 0, MEDIA_FORMAT_AMR);
      psAudRTPamr->callback(AudRTP_EVENT_BUF_UNDERFLOW, psAudRTPamr, (void  *)psAudRTPamr->host_data);
   } // check if buffer underflow
   psAudRTPamr->psMHdl->waiting = false;
}

AudRTP_DL_HANDLE *RTPAMR_OpenDLChannel( void )
{
   Media_VM_PCM_Param stParam;
   AudRTP_DL_HANDLE *amrRTP = (AudRTP_DL_HANDLE *)get_ctrl_buffer( sizeof(AudRTP_DL_HANDLE) );
   ASSERT(amrRTP != 0);

   memset(amrRTP, 0, sizeof(AudRTP_DL_HANDLE));

   stParam.mediaType = MEDIA_FORMAT_AMR;
   stParam.vmParam = (uint32)MEDIA_VMP_AS_RINGTONE;
   amrRTP->psMHdl = AMR_Open( amr_Handler,(STFSAL *)0, (void *)&stParam);
   amrRTP->GetCodecCapability = AudRTP_AMR_GetCodecCapability;
   amrRTP->Config = AudRTP_AMR_Config;
   amrRTP->GetSamplingFreq = AudRTP_AMR_GetSamplingFreq;
   amrRTP->GetChannelNum = AudRTP_AMR_GetChannelNum;
   amrRTP->GetBufferSize = AudRTP_AMR_GetBufferSize;
   amrRTP->SetBuffer = AudRTP_AMR_SetBuffer;
   amrRTP->Close = AudRTP_AMR_Close;
   amrRTP->Start = AudRTP_AMR_Start;
   amrRTP->Stop = AudRTP_AMR_Stop;
   amrRTP->PutPacket = AudRTP_AMR_PutPacket;
   amrRTP->GetPlayTime = AudRTP_AMR_GetPlayTime;
   amrRTP->SetVolumeLevel = AudRTP_AMR_SetVolumeLevel;
   amrRTP->GetBufferStatus = AudRTP_AMR_GetBufferStatus;
   amrRTP->uState = RTP_AMR_STATE_DL_INIT;

   psAudRTPamr = amrRTP;
   return amrRTP;
}

#if defined (AUD_RTP_UNIT_TEST)
/* Example code for doing Unit Test */

static uint8 test_media_buffer[40960];

void test_callback( AudRTP_EVENT event, AudRTP_DL_HANDLE *hdl, void *host_data )
{
   return;
}

static rtp_audio_codec_cap sCodecCap;
static uint32 uCnt=0;

void KT_Play( uint16 freq1, uint16 freq2, uint16 duration )
{
   AudRTP_DL_HANDLE *psDLhdl;
   int I;

   if(!(uCnt&0x01)){
      memset(&sCodecCap, 0, sizeof(sCodecCap));
      if( duration != 0 ) {

         psDLhdl = RTPAMR_OpenDLChannel();

         psDLhdl->GetCodecCapability( psDLhdl, RTP_AUDIO_AMR, &sCodecCap );

   // SDP initialization
         sCodecCap.amr.channels = 1;
         sCodecCap.amr.octet_align = true;

         psDLhdl->Config( psDLhdl, RTP_AUDIO_AMR, &sCodecCap, test_callback, 0, 0 );
         psDLhdl->SetBuffer(psDLhdl, test_media_buffer, sizeof( test_media_buffer));

         for( I = 0; I < 5; I++ ) {
            psDLhdl->PutPacket( psDLhdl, &packet_buffer[I][0], packet_size[I]);
            kal_sleep_task(2);
         }

         psDLhdl->Start(psDLhdl , 0);
   //      kal_prompt_trace( MOD_L1SP, "AMR RTP downlink Start\n" );

         for( I = 5; I < 30; I++ ) {
            psDLhdl->PutPacket( psDLhdl, &packet_buffer[I%5][0], packet_size[I/5]);
   //         kal_prompt_trace( MOD_L1SP, "PutPacket %d, packet size=%d\n", I, packet_size[I/5] );
            kal_sleep_task(2);
         }

         psDLhdl->psMHdl->DataFinished(psDLhdl->psMHdl);
   //      kal_prompt_trace( MOD_L1SP, "AMR RTP downlink Stop\n" );
      }
   }else{
       ASSERT(psAudRTPamr != 0);
       psAudRTPamr->Stop(psAudRTPamr );
       psAudRTPamr->Close( psAudRTPamr );
    }
   uCnt++;

}
#endif // #if defined (AUD_RTP_UNIT_TEST)

#endif // #if  defined(STREAM_SUPPORT)