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
 * rtp_daf_drv.c
 *
 * Project:
 * --------
 *   MTK6228
 *
 * Description:
 * ------------
 *   RTP Audio interface for MP3/MP2
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
//#define STREAM_SUPPORT
//#define AUD_RTP_UNIT_TEST

#include "media.h"
#include "audio_rtp.h"
#include "l1sp_trc.h"
#include "afe.h"

#if defined(__TDMB_SUPPORT__)
#if  defined(STREAM_SUPPORT)

static const kal_uint32 maxByterateFromIndex[16] = {
  0, 0, 0, 36000, 33076, 24000, 18000, 16538,
  16000, 12000, 9000, 6000, 0, 0, 0, 0
};

#define  RTP_DAF_STATE_DL_INIT           0x00
#define  RTP_DAF_STATE_DL_CONFIGURED     0x01
#define  RTP_DAF_STATE_DL_READY          0x02
#define  RTP_DAF_STATE_DL_DECODE         0x03

#define  MAX_BUF_DUR  6  // in sec, worst case buffer size: 216kB
#define  MAX_PACKET_LOSS 5

typedef struct aud_rtp_internal {
   AudRTP_DL_HANDLE    sAudHdl;
   kal_uint32          current_time;
   kal_uint32          uFrameDur;
   kal_uint32          bit_rate;
   kal_uint8           bFreqIdx;
} dafRTPHdl;

static AudRTP_DL_HANDLE  *psAudRTPdaf = 0;

static void dafPutNByte( AudRTP_DL_HANDLE *hdl, kal_uint8* pbBuf, kal_uint32 uLen )
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

static AudRTP_STATUS AudRTP_DAF_GetCodecCapability(AudRTP_DL_HANDLE *hdl,
                                                   rtp_audio_codec_type codec_type,
                                                   rtp_audio_codec_cap *codec_cap )
{
   (void)hdl;
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_DAF_Config(AudRTP_DL_HANDLE *hdl,
                                   rtp_audio_codec_type codec_type,
                                   rtp_audio_codec_cap *codec_cap,
                                   AudRTP_DL_CALLBACK callback,
                                   void *host_data, kal_uint32 session_id )
{
//   dafRTPHdl* ihdl = (dafRTPHdl *) hdl;

   ASSERT( hdl->uState == RTP_DAF_STATE_DL_INIT );

   hdl->callback = callback;
   hdl->host_data = (kal_uint32)host_data;
   hdl->session_id = session_id;

   hdl->uState = RTP_DAF_STATE_DL_CONFIGURED;

   return AudRTP_STATUS_SUCCESS;
}

static kal_uint32 AudRTP_DAF_GetSamplingFreq( AudRTP_DL_HANDLE *hdl )
{
   return 0;
}

static kal_uint8 AudRTP_DAF_GetChannelNum( AudRTP_DL_HANDLE *hdl )
{
   return 0;
}

static void AudRTP_DAF_SetVolumeLevel( AudRTP_DL_HANDLE *hdl, kal_uint8 level )
{
   ASSERT( level <= 100 );
   AFE_SetDigitalGain(AFE_DIGITAL_GAIN_AUDIO, level);
   AFE_SetDigitalGain(AFE_DIGITAL_GAIN_SPEECH, level);
}

static kal_uint32 AudRTP_DAF_GetBufferSize(AudRTP_DL_HANDLE *hdl )
{
   dafRTPHdl* ihdl = (dafRTPHdl *) hdl;
   ASSERT(maxByterateFromIndex[ihdl->bFreqIdx] != 0);
   return (maxByterateFromIndex[ihdl->bFreqIdx]*MAX_BUF_DUR); // 12 sec
}

static AudRTP_STATUS AudRTP_DAF_SetBuffer(AudRTP_DL_HANDLE *hdl, kal_uint8 *buffer, kal_uint32 buffer_size )
{
   ASSERT( hdl->uState == RTP_DAF_STATE_DL_CONFIGURED );
   hdl->uState = RTP_DAF_STATE_DL_READY;
   ASSERT(((uint32)buffer & 3) == 0 );       /* make sure 4-byte alignment */
   ASSERT( (buffer_size & 1) == 0 );         /* insure 2-byte alignment */
   hdl->psMHdl->SetBuffer( hdl->psMHdl, buffer, buffer_size );

   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_DAF_Close(AudRTP_DL_HANDLE *hdl )
{
   ASSERT( hdl->uState != RTP_DAF_STATE_DL_DECODE );

   hdl->psMHdl->Close(hdl->psMHdl);
   psAudRTPdaf = (AudRTP_DL_HANDLE  *)0;
   free_ctrl_buffer( hdl );

   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_DAF_Start(AudRTP_DL_HANDLE *hdl, kal_uint32 start_time )
{
   Media_Status res;
   dafRTPHdl* ihdl = (dafRTPHdl *) hdl;
   ASSERT( hdl->uState == RTP_DAF_STATE_DL_READY );

   if(hdl->psMHdl->write == 6) // buffer underflow
      return AudRTP_STATUS_FAIL;

   hdl->psMHdl->start_time = start_time;
   res = hdl->psMHdl->Play(hdl->psMHdl);
   if(res != MEDIA_SUCCESS) // Play fail
      return AudRTP_STATUS_FAIL;
   ihdl->current_time = start_time;
   hdl->psMHdl->current_time = start_time;
   hdl->uPacketLossCnt = 0;
   hdl->uState = RTP_DAF_STATE_DL_DECODE;
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_DAF_Stop(AudRTP_DL_HANDLE *hdl )
{
   dafRTPHdl* ihdl = (dafRTPHdl *) hdl;
   ASSERT( hdl->uState == RTP_DAF_STATE_DL_DECODE );
   hdl->psMHdl->Stop(hdl->psMHdl);
   hdl->psMHdl->write = 0;   // Reset Media Buffer
   hdl->psMHdl->read = 0;
   hdl->psMHdl->eof = false;
   hdl->psMHdl->waiting = false;
   hdl->uTotalFrameInBuf = 0;
   hdl->uPrePacketNum = 0;
   hdl->uPreTimeStamp = 0;

   hdl->uState = RTP_DAF_STATE_DL_READY;
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_DAF_GetPlayTime(AudRTP_DL_HANDLE *hdl, kal_uint32 *p_current_time)
{
   *p_current_time = hdl->psMHdl->current_time;
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS AudRTP_DAF_GetBufferStatus(AudRTP_DL_HANDLE *psRTPHdl, kal_uint32 *puCurBufDur,
               kal_uint32 *puBufFreeSize, kal_uint32 *puBufTotalSize, kal_uint32 *puMinBufTotalDur)
{
   dafRTPHdl* ihdl = (dafRTPHdl *) psRTPHdl;
   *puCurBufDur = psRTPHdl->uTotalFrameInBuf * ihdl->uFrameDur; // in ms
   // *puCurBufDur = psRTPHdl->uTotalFrameInBuf * ihdl->uFrameDur / 1000000;
   *puBufTotalSize = psRTPHdl->psMHdl->rb_size - 1;
   *puBufFreeSize = psRTPHdl->psMHdl->GetFreeSpace(psRTPHdl->psMHdl);
   *puMinBufTotalDur = MAX_BUF_DUR * 1000;

   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_BUF_STATUS, *puCurBufDur, *puBufTotalSize, *puBufFreeSize, *puMinBufTotalDur );
   return AudRTP_STATUS_SUCCESS;
}

// under construction
static AudRTP_STATUS AudRTP_DAF_PutPacket(AudRTP_DL_HANDLE *hdl, kal_uint8 *buf, kal_uint32 buffer_size)
{
   return AudRTP_STATUS_SUCCESS;
}

static AudRTP_STATUS   AudRTP_DAF_AddAccessUnit(AudRTP_DL_HANDLE *hdl, kal_uint8* buf, kal_uint32 buffer_size, kal_uint32 timestamp)
{
   dafRTPHdl* ihdl = (dafRTPHdl *) hdl;

   if( hdl->psMHdl->GetFreeSpace(hdl->psMHdl) < buffer_size ){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_OF, 1, MEDIA_FORMAT_DAF);
      mhdlException( hdl->psMHdl, (Media_Event)AudRTP_EVENT_BUF_OVERFLOW );
      return AudRTP_STATUS_FAIL;            /* buffer overflow */
   }

   dafPutNByte( hdl, buf, buffer_size );

   return AudRTP_STATUS_SUCCESS;
}

// under construction
static AudRTP_STATUS   AudRTP_DAF_RTP_Parser(AudRTP_DL_HANDLE *handle, kal_uint8 *buffer,
                                      kal_uint32 buffer_size, kal_uint8 *au,
                                      kal_uint32 au_size, kal_uint32 *timestamp)
{

}


// must be sure aac_Handler would be invoked every D2M INT
static void daf_Handler( MHdl *handle, Media_Event event )
{
   dafRTPHdl* ihdl = (dafRTPHdl *) psAudRTPdaf;
   ASSERT(psAudRTPdaf != 0);
   (void)event;   /* do nothing */
   (void)handle;

   kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_FRM_IN_BUF, psAudRTPdaf->uTotalFrameInBuf, MEDIA_FORMAT_DAF);
   //ASSERT(event != MEDIA_ERROR);

   if(event == MEDIA_ERROR){
      psAudRTPdaf->callback(AudRTP_EVENT_MEDIA_ERROR, psAudRTPdaf, (void  *)psAudRTPdaf->host_data);
      return;
   }

   if((AudRTP_EVENT)event == AudRTP_EVENT_BUF_OVERFLOW){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_OF, 0, MEDIA_FORMAT_DAF);
      psAudRTPdaf->callback(AudRTP_EVENT_BUF_OVERFLOW, psAudRTPdaf, (void  *)psAudRTPdaf->host_data);
      return;
   }else if((AudRTP_EVENT)event == AudRTP_EVENT_PACKET_LOSS){
      kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_PKT_LOSS, MAX_PACKET_LOSS, MEDIA_FORMAT_DAF);
      psAudRTPdaf->callback(AudRTP_EVENT_PACKET_LOSS, psAudRTPdaf, (void  *)psAudRTPdaf->host_data);
      return;
    }

   if(handle->current_time > ihdl->current_time){
      kal_uint32 uFrameCnt;
      uFrameCnt = handle->current_time - ihdl->current_time;
      if(0 != ihdl->uFrameDur)
      {
          uFrameCnt /= ihdl->uFrameDur;
          if(psAudRTPdaf->uTotalFrameInBuf > uFrameCnt)
             psAudRTPdaf->uTotalFrameInBuf -= uFrameCnt;
      }
      if( psAudRTPdaf->psMHdl->GetDataCount(psAudRTPdaf->psMHdl) <= 1 ){
         kal_trace( TRACE_GROUP_AUDRTP, RTP_AUD_MB_UF, 0, MEDIA_FORMAT_DAF);
         psAudRTPdaf->callback(AudRTP_EVENT_BUF_UNDERFLOW, psAudRTPdaf, (void  *)psAudRTPdaf->host_data);
      }
      ihdl->current_time = handle->current_time;
   }
   psAudRTPdaf->psMHdl->waiting = false;
}

AudRTP_DL_HANDLE *RTPDAF_OpenDLChannel( void )
{
   AudRTP_DL_HANDLE* dafRTP = (AudRTP_DL_HANDLE *)get_ctrl_buffer( sizeof(dafRTPHdl) );
   ASSERT(dafRTP != 0);

   memset(dafRTP, 0, sizeof(dafRTPHdl));

   dafRTP->psMHdl = DAF_Open( daf_Handler,(STFSAL *)0, (void *)0);
   dafRTP->GetCodecCapability = AudRTP_DAF_GetCodecCapability;
   dafRTP->Config = AudRTP_DAF_Config;
   dafRTP->GetSamplingFreq = AudRTP_DAF_GetSamplingFreq;
   dafRTP->GetChannelNum = AudRTP_DAF_GetChannelNum;
   dafRTP->GetBufferSize = AudRTP_DAF_GetBufferSize;
   dafRTP->SetBuffer = AudRTP_DAF_SetBuffer;
   dafRTP->Close = AudRTP_DAF_Close;
   dafRTP->Start = AudRTP_DAF_Start;
   dafRTP->Stop = AudRTP_DAF_Stop;
   dafRTP->PutPacket = AudRTP_DAF_PutPacket;
   dafRTP->AddAccessUnit = AudRTP_DAF_AddAccessUnit;
   dafRTP->RTP_Parser = AudRTP_DAF_RTP_Parser;
   dafRTP->GetPlayTime = AudRTP_DAF_GetPlayTime;
   dafRTP->SetVolumeLevel = AudRTP_DAF_SetVolumeLevel;
   dafRTP->GetBufferStatus = AudRTP_DAF_GetBufferStatus;
   dafRTP->uState = RTP_DAF_STATE_DL_INIT;

   psAudRTPdaf = dafRTP;
   return dafRTP;
}

#endif // #if  defined(STREAM_SUPPORT)
#endif // #if defined(__TDMB_SUPPORT__)