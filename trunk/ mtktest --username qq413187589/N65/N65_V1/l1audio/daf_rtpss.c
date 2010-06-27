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
 *   daf_rtpss.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   DAF sender streaming over RTP (RFC2250),
 *   including interface support for Bluetooth A2DP
 *
 * Author:
 * -------
 * -------
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
 *============================================================================
 ****************************************************************************/

#if !defined(DAF_RTPSS_UT_ON_VC)
#include "media.h"
#include "l1sp_trc.h"
#else
#include "ut_daf_rtpss.h"
#endif

#if (defined(__BT_A2DP_PROFILE__) && defined(DAF_DECODE)) || defined(DAF_RTPSS_UT_ON_VC)

#if !defined(DAF_RTPSS_UT_ON_VC)
#define TRACE_ENTER_OPEN() kal_trace( TRACE_FUNC, ENTER_A2DP_DAF_OPEN )
#define TRACE_ENTER_CLOSE() kal_trace( TRACE_FUNC, ENTER_A2DP_DAF_CLOSE )
//#define TRACE_PUTDATA(p1, p2, p3) kal_trace( TRACE_GROUP_DAFRTP, DAFRTP_PUTDATA, (p1), (p2), (p3) )
#define TRACE_PUTDATA(p1, p2, p3) kal_prompt_trace( MOD_L1SP, "DAFRTP PutData, putlen=%d, elapsed: %d, wait: %d", (p1), (p2), (p3) )
#define TRACE_GETDATA(p1, p2, p3, p4, p5) kal_trace( TRACE_GROUP_DAFRTP, DAFRTP_GETDATA, (p1), (p2), (p3), (p4), (p5) )
#define TRACE_FRAMESYNC(p1, p2, p3) kal_trace( TRACE_GROUP_DAFRTP, DAFRTP_FRAMESYNC, (p1), (p2), (p3) )
extern const uint16 DAF_BIT_RATE_TABLE_V1[15];
extern const uint16 DAF_BIT_RATE_TABLE_V2[15];
#else
SSHdl *my_ss_handle = NULL;
#endif

typedef struct {
   kal_uint32 Emphasis: 2;
   kal_uint32 Original: 1;
   kal_uint32 Copyright: 1;
   kal_uint32 ModeExt: 2;
   kal_uint32 ChannelMode: 2; // fixed
   kal_uint32 Private: 1;
   kal_uint32 Padding: 1;
   kal_uint32 SampleRateIndex: 2; // fixed
   kal_uint32 BitRateIndex: 4;
   kal_uint32 Protection: 1;
   kal_uint32 Layer: 2; // fixed
   kal_uint32 VersionID: 2; // fixed
   kal_uint32 Sync: 11; // fixed
} dafHeaderStruct;

typedef struct {
   SSHdl ss_handle;
   dafHeaderStruct config_header;
   kal_uint32 last_frame_size;
   kal_uint32 last_bit_rate;
   kal_uint32 fragment_start;
} dafRTPSSHdlInternal;

__inline void PUT_UINT32(kal_uint8 *ptr, kal_uint32 u32_t)
{
   ptr[0] = (kal_uint8)( (u32_t >> 24) & 0xff );
   ptr[1] = (kal_uint8)( (u32_t >> 16) & 0xff );
   ptr[2] = (kal_uint8)( (u32_t >> 8) & 0xff );
   ptr[3] = (kal_uint8)( (u32_t) & 0xff );
}

__inline kal_uint32 GET_UINT32(kal_uint8 *ptr)
{
   kal_uint32 u32_t;
   u32_t = (kal_uint32)ptr[0] << 24;
   u32_t += (kal_uint32)ptr[1] << 16;
   u32_t += (kal_uint32)ptr[2] << 8;
   u32_t += (kal_uint32)ptr[3];
   return u32_t;
}

kal_int32 SSHdl_GetFreeSpace(SSHdl *hdl)
{
   kal_int32 cnt;
   cnt = hdl->rb_read - hdl->rb_write - 1;
   if( cnt < 0 )
      cnt += hdl->rb_size;
   return cnt;
}

kal_int32 SSHdl_GetDataCount(SSHdl *hdl)
{
   kal_int32 cnt;
   cnt = hdl->rb_write - hdl->rb_read;
      if( cnt < 0 )
         cnt += hdl->rb_size;
   return cnt;
}

void SSHdl_GetWriteBuffer(SSHdl *hdl, kal_uint8 **buf, kal_int32 *buf_len)
{
   kal_int32 cnt;

   if( hdl->rb_read > hdl->rb_write )
      cnt = hdl->rb_read - hdl->rb_write - 1;
   else if( hdl->rb_read == 0 )
      cnt = hdl->rb_size - hdl->rb_write - 1;
   else
      cnt = hdl->rb_size - hdl->rb_write;
   *buf = &hdl->rb_base[hdl->rb_write];
   *buf_len = cnt;
}

void SSHdl_GetReadBuffer(SSHdl *hdl, kal_uint8 **buf, kal_int32 *buf_len)
{
   kal_int32 cnt;

   if( hdl->rb_write > hdl->rb_read )
      cnt = hdl->rb_write - hdl->rb_read;
   else
      cnt = hdl->rb_size - hdl->rb_read;
   *buf = &hdl->rb_base[hdl->rb_read];
   *buf_len = cnt;
}

void SSHdl_ShiftWritePointer(SSHdl *hdl, kal_int32 shamt)
{
   hdl->rb_write += shamt;
   if( hdl->rb_write >= hdl->rb_size )
      hdl->rb_write -= hdl->rb_size;
}

void SSHdl_ShiftReadPointer(SSHdl *hdl, kal_int32 shamt)
{
   hdl->rb_read += shamt;
   if( hdl->rb_read >= hdl->rb_size )
      hdl->rb_read -= hdl->rb_size;
   hdl->rb_read_total += shamt;
}

void SSHdl_SniffNBytes(SSHdl *hdl, kal_uint32 offset, kal_uint32 N, kal_uint8 *dest)
{
   kal_int32 read = hdl->rb_read;
   read += offset;
   if(read >= hdl->rb_size )
   {
      read -= hdl->rb_size;
   }
   for( ; N>0; N-- )
   {
      *dest++ = hdl->rb_base[read];
      read += 1;
      if( read == hdl->rb_size )
         read = 0;
   }
}

void dafRTPSS_PutData( SSHdl *hdl, kal_uint8 *buf, kal_uint32 length )
{
   kal_int32 cnt;
   kal_int32 length_t = (kal_int32)length;

   ASSERT( hdl != NULL );
   if( !is_SSHdl_valid( hdl ) )
      return;
   
   cnt = SSHdl_GetFreeSpace( hdl );
   if( cnt<length )
   { // Buffer overflow
      TRACE_PUTDATA(length_t, -cnt, hdl->wait);
      return;
      // ASSERT(0);
   }

   while( length>0 )
   {
      kal_uint8 *dest;
      SSHdl_GetWriteBuffer( hdl, &dest, &cnt );
      if( cnt > length )
         cnt = length;
      kal_mem_cpy( dest, buf, cnt );
      SSHdl_ShiftWritePointer( hdl, cnt );
      buf += cnt;
      length -= cnt;
   }

   cnt = SSHdl_GetDataCount( hdl );
   TRACE_PUTDATA(length_t, cnt, hdl->wait);

   if( hdl->wait == KAL_FALSE && cnt >= hdl->rb_threshold )
   {
      hdl->wait = KAL_TRUE;
      hdl->callback( 0 );
   }
}

void dafRTPSS_Flush( SSHdl *hdl )
{
   kal_int32 cnt;

   ASSERT( hdl != NULL );
   if( !is_SSHdl_valid( hdl ) )
      return;
   
   cnt = SSHdl_GetDataCount( hdl );
   TRACE_PUTDATA(-1, cnt, hdl->wait);

   if( cnt > 0 )
      hdl->callback( (void *)2 );
}

const uint16 DAF_SAMPLE_RATE_TABLE[3] = { 44100, 48000, 32000 };
kal_uint32 dafGetFrameLen( dafHeaderStruct stDafHeader, kal_uint32 *uBitRate )
{ // support MPEG-1,2,2.5 Layer III only
   kal_uint32 frameLen, sampleRate, bitRate, samplePerFrame = 576;

   sampleRate = (kal_uint32)DAF_SAMPLE_RATE_TABLE[stDafHeader.SampleRateIndex];
   if( stDafHeader.VersionID == 0x2 )
      sampleRate >>= 1;
   else if( stDafHeader.VersionID == 0x0 )
      sampleRate >>= 2;
   else
      samplePerFrame <<= 1;

   if( stDafHeader.VersionID == 0x3 )
      bitRate = DAF_BIT_RATE_TABLE_V1[stDafHeader.BitRateIndex];
   else
      bitRate = DAF_BIT_RATE_TABLE_V2[stDafHeader.BitRateIndex];

   *uBitRate = bitRate;
   frameLen = ( ( samplePerFrame * bitRate * 1000 / 8 ) / sampleRate );
   return frameLen;
}

kal_uint32 dafRTPSS_GetData( SSHdl *hdl, kal_uint8 *buf, kal_uint32 buf_len, kal_uint32 *sample_cnt )
{
   dafRTPSSHdlInternal *ihdl = (dafRTPSSHdlInternal *)hdl;
   kal_int32 cnt, cnt2, write_cnt = 0;
   kal_uint8 *payload_header = buf;
   kal_uint32 samples = 0;
   kal_uint32 buf_len_t = buf_len;

   ASSERT( hdl != NULL );

   if( SSHdl_GetDataCount( hdl ) == 0 )
      return 0;

   payload_header = buf;
   buf += 4;
   buf_len -= 4;
   ASSERT( buf_len > 0 );
   
   if( ihdl->fragment_start != 0 )
   {
      cnt = (kal_int32)ihdl->last_frame_size - (kal_int32)ihdl->fragment_start;
      ASSERT( cnt > 0 );
      if( cnt > buf_len )
         cnt = buf_len;
      cnt2 = SSHdl_GetDataCount( hdl );
      if( cnt > cnt2 )
         cnt = cnt2;

      PUT_UINT32( payload_header, ihdl->fragment_start );
      ihdl->fragment_start += cnt;
      buf_len -= cnt;
      write_cnt += cnt;
      while( cnt > 0 )
      {
         kal_uint8 *src;
         SSHdl_GetReadBuffer( hdl, &src, &cnt2 );
         if( cnt2 > cnt )
            cnt2 = cnt;
         kal_mem_cpy( buf, src, cnt2 );
         SSHdl_ShiftReadPointer( hdl, cnt2 );
         buf += cnt2;
         cnt -= cnt2;
      }

      ASSERT( ihdl->fragment_start <= ihdl->last_frame_size );
      if( ihdl->fragment_start == ihdl->last_frame_size )
         ihdl->fragment_start = 0;
   }
   else
   {
      kal_uint32 state = 0, break_code, skip_count = 0;
      kal_uint8 uDafHeaderWord[4];
      kal_int32 frameLen = 0;
      kal_uint32 bitRate;
      
      dafHeaderStruct stDafHeader;
      *(kal_uint32 *)&stDafHeader = 0;
      do
      {
         break_code = 0;
         switch( state )
         {
            case 0: // search next frame header
            {
               if( SSHdl_GetDataCount( hdl ) >= 4 )
               {
                  SSHdl_SniffNBytes( hdl, 0, 4, uDafHeaderWord );
                  *(kal_uint32 *)&stDafHeader = GET_UINT32( uDafHeaderWord );

                  if( ( stDafHeader.Sync == ihdl->config_header.Sync ) && 
                      ( stDafHeader.VersionID == ihdl->config_header.VersionID ) && 
                      ( stDafHeader.Layer == ihdl->config_header.Layer ) && 
                      ( stDafHeader.BitRateIndex != 0x0 ) && ( stDafHeader.BitRateIndex != 0xf ) && 
                      ( stDafHeader.SampleRateIndex == ihdl->config_header.SampleRateIndex )
                    )
                  {
                     frameLen = dafGetFrameLen( stDafHeader, &bitRate );
                     state = 1;
                  }
                  else
                  {
                     state = 0;
                     SSHdl_ShiftReadPointer( hdl, 1 ); // skip one byte from bitstream
                     skip_count ++;
                  }
               }
               else
               {
                  break_code = 1;
                  TRACE_FRAMESYNC(skip_count, 0, 0);
               }
            }
               break;
            case 1:
            {
               dafHeaderStruct stNextDafHeader;
               if( SSHdl_GetDataCount( hdl ) >= (4+frameLen+4) )
               {
                  SSHdl_SniffNBytes( hdl, frameLen+1, 4, uDafHeaderWord );

                  *(kal_uint32 *)&stNextDafHeader = GET_UINT32( uDafHeaderWord );
                  if( ( stNextDafHeader.Sync == ihdl->config_header.Sync ) && 
                      ( stNextDafHeader.VersionID == ihdl->config_header.VersionID ) && 
                      ( stNextDafHeader.Layer == ihdl->config_header.Layer ) && 
                      ( stNextDafHeader.BitRateIndex != 0x0 ) && ( stDafHeader.BitRateIndex != 0xf ) && 
                      ( stNextDafHeader.SampleRateIndex == ihdl->config_header.SampleRateIndex )
                    )
                  {
                     stDafHeader.Padding = 1;
                     frameLen += 1;
                  }
                  else
                  {
                     stDafHeader.Padding = 0;
                  }
                  state = 2;
               }
               else
               {
                  break_code = 10;
               }
            }
               break;
            case 2: // get one frame
            {  
               ihdl->last_frame_size = frameLen;
               ihdl->last_bit_rate = bitRate;

               TRACE_FRAMESYNC(skip_count, frameLen, bitRate);

               cnt = SSHdl_GetDataCount( hdl );
               if( cnt > buf_len )
                  cnt = buf_len;
               if( cnt > frameLen )
                  cnt = frameLen;

               if( ( write_cnt == 0 ) || ( cnt == frameLen ) )
               {
                  kal_uint32 temp;
                  if( write_cnt == 0 )
                     PUT_UINT32( payload_header, ihdl->fragment_start );
                  ihdl->fragment_start += cnt;
                  buf_len -= cnt;
                  write_cnt += cnt;

                  cnt2 = sizeof(stDafHeader);
                  temp = GET_UINT32((kal_uint8 *)&stDafHeader);
                  kal_mem_cpy(buf, &temp, cnt2 );
                  SSHdl_ShiftReadPointer( hdl, cnt2 );
                  buf += cnt2;
                  cnt -= cnt2;
                  
                  while( cnt > 0 )
                  {
                     kal_uint8 *src;
                     SSHdl_GetReadBuffer( hdl, &src, &cnt2 );
                     if( cnt2 > cnt )
                        cnt2 = cnt;
                     kal_mem_cpy( buf, src, cnt2 );
                     SSHdl_ShiftReadPointer( hdl, cnt2 );
                     buf += cnt2;
                     cnt -= cnt2;
                  }

                  ASSERT( ihdl->fragment_start <= ihdl->last_frame_size );
                  if( ihdl->fragment_start == ihdl->last_frame_size )
                  {
                     ihdl->fragment_start = 0;
                     state = 0;
                     skip_count = 0;
                  }
                  else
                     break_code = 3;
                  samples += (ihdl->config_header.VersionID==0x3)? 1152: 576;
               }
               else
               {
                  break_code = 2;
               }
            }
               break;
            default:
               ASSERT(0);
               break;
         }
      }while( ( break_code == 0 ) && ( buf_len > 0 ) );
   }
   *sample_cnt = (samples * 90000) / DAF_SAMPLE_RATE_TABLE[ihdl->config_header.SampleRateIndex];
   // hdl->wait = KAL_FALSE;

   TRACE_GETDATA(buf_len_t, write_cnt, SSHdl_GetDataCount( hdl ), samples, GET_UINT32(payload_header));
   if( write_cnt > 0 )
      write_cnt += 4;
   return ( write_cnt );
}

void dafRTPSS_GetDataDone(SSHdl *hdl)
{
   hdl->wait = KAL_FALSE;
}

#if defined(__BT_A2DP_PROFILE__) || defined(DAF_RTPSS_UT_ON_VC)

static struct {
   A2DP_codec_struct  *a2dp_codec_hdl;
   dafRTPSSHdlInternal *daf_ss_handle;
   A2DP_Callback callback;
} a2dp_daf_strm;

const bt_a2dp_mp3_codec_cap_struct mp3_cap[1] = 
{
   0x1, // layer
   KAL_TRUE, // CRC
   0xf, // channel_mode
   KAL_FALSE, // MPF
   0x03, // sample_rate
   KAL_TRUE, // VBR
   0x7FFE // bit_rate
};

static void a2dp_callback( void *data )
{
   if(a2dp_daf_strm.a2dp_codec_hdl != NULL)
   {
      a2dp_daf_strm.a2dp_codec_hdl->state = (kal_uint32)data;
      a2dp_daf_strm.callback( A2DP_DATA_NOTIFY, a2dp_daf_strm.a2dp_codec_hdl );
   }
}

static uint32 a2dp_daf_GetPayload(uint8 *buf , uint32 buf_len, uint32 *sample_cnt)
{
   uint32 size;
   if( a2dp_daf_strm.daf_ss_handle == NULL )
      return 0;
   
   size = dafRTPSS_GetData( (SSHdl *)a2dp_daf_strm.daf_ss_handle, buf, buf_len, sample_cnt );
   return size;
}

static void a2dp_daf_GetPayloadDone()
{
   dafRTPSS_GetDataDone( (SSHdl *)a2dp_daf_strm.daf_ss_handle );
}

static void a2dp_daf_QueryPayloadSize(uint32 *min, uint32 *total)
{
   if( a2dp_daf_strm.daf_ss_handle == NULL )
   {
      *min = 0;
      *total = 0;
   }
   else
   {
      uint32 cnt = SSHdl_GetDataCount( (SSHdl *)a2dp_daf_strm.daf_ss_handle );
      if( a2dp_daf_strm.daf_ss_handle->fragment_start != 0 )
         *min = a2dp_daf_strm.daf_ss_handle->last_frame_size - a2dp_daf_strm.daf_ss_handle->fragment_start;
      else
         *min = a2dp_daf_strm.daf_ss_handle->last_frame_size;
      if(cnt == 0)
         *total = 0;
      else
         *total = cnt + 4;
   }
}

static kal_uint32 a2dp_daf_SetBitRate(kal_uint32 bit_rate)
{
   if( a2dp_daf_strm.daf_ss_handle == NULL )
      return 0;
   return a2dp_daf_strm.daf_ss_handle->last_bit_rate;
}

static kal_uint32 a2dp_daf_AdjustBitRateFromQos(kal_uint8 qos) // return adjusted bit rate
{
   if( a2dp_daf_strm.daf_ss_handle == NULL )
      return 0;
   return a2dp_daf_strm.daf_ss_handle->last_bit_rate;
}

kal_uint32 A2DP_DAF_GetMemReq(void)
{
   return 4096;
}

A2DP_codec_struct *A2DP_DAF_Open( MHdl *mhdl_handle, A2DP_Callback pHandler, bt_a2dp_mp3_codec_cap_struct *daf_config_data, kal_uint8 *buf, kal_uint32 buf_len)
{
   A2DP_codec_struct *a2dp_codec_handle;
   
   TRACE_ENTER_OPEN();
   ASSERT( buf_len >= A2DP_DAF_GetMemReq() );
   ASSERT( daf_config_data != NULL );

   {
      dafRTPSSHdlInternal *ihdl;
      
      ihdl = (dafRTPSSHdlInternal *)get_ctrl_buffer( sizeof(dafRTPSSHdlInternal) );
      ihdl->ss_handle.PutData = dafRTPSS_PutData;
      ihdl->ss_handle.Flush = dafRTPSS_Flush;
      ihdl->ss_handle.rb_base = buf;
      ihdl->ss_handle.rb_size = buf_len;
      ihdl->ss_handle.rb_read = 0;
      ihdl->ss_handle.rb_write = 0;
      ihdl->ss_handle.rb_threshold = (1024<(buf_len/2))? 1024: (buf_len/2);
      ihdl->ss_handle.callback = a2dp_callback;
      ihdl->ss_handle.wait = KAL_FALSE;
      ihdl->ss_handle.rb_read_total = 0;
      ihdl->last_frame_size = 0;
      ihdl->last_bit_rate = 0;
      ihdl->fragment_start = 0;
      *(kal_uint32 *)&(ihdl->config_header) = 0;

      if( daf_config_data->layer == 0x1 )
         ihdl->config_header.Layer = 0x1; // Layer III
      else
         ASSERT(0); // not support or error

      if( daf_config_data->channel_mode == 0x01 )
         ihdl->config_header.ChannelMode = 0x1; // joint stereo
      else if( daf_config_data->channel_mode == 0x02 )
         ihdl->config_header.ChannelMode = 0x0; // stereo
      else if( daf_config_data->channel_mode == 0x04 )
         ihdl->config_header.ChannelMode = 0x2; // dual
      else if( daf_config_data->channel_mode == 0x08 )
         ihdl->config_header.ChannelMode = 0x3; // mono
      else
         ASSERT(0); // error
      
      if( daf_config_data->sample_rate == 0x01 )
         ihdl->config_header.SampleRateIndex = 0x1; // 48000
      else if( daf_config_data->sample_rate == 0x02 )
         ihdl->config_header.SampleRateIndex = 0x0; // 44100
      else if( daf_config_data->sample_rate == 0x04 )
         ihdl->config_header.SampleRateIndex = 0x2; // 32000
      else if( daf_config_data->sample_rate == 0x08 )
         ihdl->config_header.SampleRateIndex = 0x1; // 24000
      else if( daf_config_data->sample_rate == 0x10 )
         ihdl->config_header.SampleRateIndex = 0x0; // 22050
      else if( daf_config_data->sample_rate == 0x20 )
         ihdl->config_header.SampleRateIndex = 0x2; // 16000
      else
         ASSERT(0); // error
      
      if( daf_config_data->sample_rate & 0x7 )
         ihdl->config_header.VersionID = 0x3;
      else
         ihdl->config_header.VersionID = 0x2;

      ihdl->config_header.Sync = 0x7ff;
      
      a2dp_daf_strm.daf_ss_handle = ihdl;
#if !defined(DAF_RTPSS_UT_ON_VC)
      mhdl_handle->ss_handle = (SSHdl *)ihdl;
#else
      my_ss_handle = (SSHdl *)ihdl;
#endif
   }

   a2dp_codec_handle = (A2DP_codec_struct *)get_ctrl_buffer( sizeof(A2DP_codec_struct) );
   a2dp_codec_handle->GetPayload = a2dp_daf_GetPayload;
   a2dp_codec_handle->GetPayloadDone = a2dp_daf_GetPayloadDone;
   a2dp_codec_handle->QueryPayloadSize = a2dp_daf_QueryPayloadSize;
   a2dp_codec_handle->SetBitRate = a2dp_daf_SetBitRate;
   a2dp_codec_handle->AdjustBitRateFromQos = a2dp_daf_AdjustBitRateFromQos;
   a2dp_codec_handle->state = 0;
   a2dp_daf_strm.a2dp_codec_hdl = a2dp_codec_handle;

   a2dp_daf_strm.callback = pHandler;

   return a2dp_codec_handle;
}

void A2DP_DAF_Close( MHdl *mhdl_handle )
{
   TRACE_ENTER_CLOSE();

#if !defined(DAF_RTPSS_UT_ON_VC)
   if( mhdl_handle != NULL )
      mhdl_handle->ss_handle = NULL;
#else
   my_ss_handle = NULL;
#endif
   if( a2dp_daf_strm.daf_ss_handle != NULL )
   {
      void *ptr = (void *)a2dp_daf_strm.daf_ss_handle;
      a2dp_daf_strm.daf_ss_handle->ss_handle.Flush( (SSHdl *)a2dp_daf_strm.daf_ss_handle );
      kal_sleep_task(4);
      a2dp_daf_strm.daf_ss_handle = NULL;
      free_ctrl_buffer( ptr );
   }
   if( a2dp_daf_strm.a2dp_codec_hdl != NULL )
   {
      void *ptr = (void *)a2dp_daf_strm.a2dp_codec_hdl;
      a2dp_daf_strm.a2dp_codec_hdl = NULL;
      free_ctrl_buffer( ptr );
   }
}

#endif // ... __BT_A2DP_PROFILE__ || DAF_RTPSS_UT_ON_VC

#if defined(DAF_RTPSS_UT_ON_VC)

#define MAX_MTU_SIZE (668-12)
kal_uint8 mtu_buffer[MAX_MTU_SIZE];
A2DP_codec_struct *my_a2dp_handle = NULL;
bt_a2dp_mp3_codec_cap_struct daf_config;
FILE *fp_in, *fp_out;

void a2dp_callback_handler(A2DP_Event event , void*data)
{
    kal_uint32 flush = my_a2dp_handle->state & 2;
    while(1)
    {
        kal_uint32 min_payload_size, total_payload_size, read_cnt, num_samples, payload_header;

        my_a2dp_handle->QueryPayloadSize(&min_payload_size, &total_payload_size);
        if((!flush && total_payload_size<MAX_MTU_SIZE) || total_payload_size<=8)
            break;

        if(total_payload_size>MAX_MTU_SIZE)
            total_payload_size = MAX_MTU_SIZE;
        read_cnt = my_a2dp_handle->GetPayload(mtu_buffer, total_payload_size, &num_samples);
        if(read_cnt == 0)
            break;
        my_a2dp_handle->GetPayloadDone();
        payload_header = GET_UINT32(mtu_buffer);
        fwrite(mtu_buffer+4, 1, read_cnt-4, fp_out);
    }
}

unsigned int my_rand(int seed)
{
    return (unsigned int)(unsigned short)(seed*31821 + 13849);
}

int get_daf_config(bt_a2dp_mp3_codec_cap_struct *cfg, FILE *fp)
{
    int offset = 0;
    dafHeaderStruct stDafHeader;

    while(!feof(fp))
    {
        kal_uint8 uDafHeaderWord[4];

        fseek(fp, offset, SEEK_SET);
        if( 4 != fread(uDafHeaderWord, 1, 4, fp) )
            return -1;
        *(kal_uint32 *)&stDafHeader = GET_UINT32(uDafHeaderWord);
        if( stDafHeader.Sync == 0x7ff )
            break;
        else
            offset ++;
    }

    if( stDafHeader.Layer == 0x1 )
        cfg->layer = 0x1;
    else
        return -2;
    cfg->CRC = ( stDafHeader.Protection == 0x1 );
    if( stDafHeader.ChannelMode == 0x0 )
        cfg->channel_mode = 0x2;
    else if( stDafHeader.ChannelMode == 0x1 )
        cfg->channel_mode = 0x1;
    else if( stDafHeader.ChannelMode == 0x2 )
        cfg->channel_mode = 0x4;
    else if( stDafHeader.ChannelMode == 0x3 )
        cfg->channel_mode = 0x8;
    else
        return -2;
    cfg->MPF = KAL_FALSE;
    if( stDafHeader.VersionID == 0x2 )
    {
        if( stDafHeader.SampleRateIndex == 0x0 )
            cfg->sample_rate = 0x10; // 22050
        else if( stDafHeader.SampleRateIndex == 0x1 )
            cfg->sample_rate = 0x8; // 24000
        else if( stDafHeader.SampleRateIndex == 0x2 )
            cfg->sample_rate = 0x20; // 16000
        else 
            return -2;
    }
    else if( stDafHeader.VersionID == 0x3 )
    {
        if( stDafHeader.SampleRateIndex == 0x0 )
            cfg->sample_rate = 0x2; // 44100
        else if( stDafHeader.SampleRateIndex == 0x1 )
            cfg->sample_rate = 0x1; // 48000
        else if( stDafHeader.SampleRateIndex == 0x2 )
            cfg->sample_rate = 0x4; // 32000
        else 
            return -2;
    }
    else
        return -2;
    
    cfg->VBR = KAL_TRUE;
    cfg->bit_rate = 0x4000;
    
    fseek(fp, 0, SEEK_SET);
    return 0;
}

void main(int argc, char **argv)
{
    char filename[40];
    int argi = 3;
    int count, file_size;
    
    if(argc<4)
        exit(-1);

    flog = fopen("dafrtp.log", "w");

    while( argi < argc )
    {
        /* Put data */
        {
            kal_uint8 *app_buf;
            kal_uint32 app_buf_len;
            kal_uint8 *bits_buf;
            kal_uint32 nBytes1, nBytes2, nBytes2_t, seed;

            nBytes1 = (kal_uint32)atoi(argv[1]);
            nBytes2 = (kal_uint32)atoi(argv[2]);
            sprintf(filename, "out_%s", argv[argi]);

            fp_in = fopen(argv[argi], "rb");
            fp_out = fopen(filename, "wb");
            if(fp_in==NULL || fp_out==NULL)
                exit(-2);
            fseek(fp_in, 0, SEEK_END);
            file_size = ftell(fp_in);
            fseek(fp_in, 0, SEEK_SET);
            fprintf(flog, "\nInput: %s, %d bytes\nOutput: %s\n", argv[argi], file_size, filename);

            bits_buf = (kal_uint8 *)get_ctrl_buffer(nBytes1+nBytes2);

            if( 0 != get_daf_config( &daf_config, fp_in ) )
                break;
            app_buf_len = A2DP_DAF_GetMemReq();
            app_buf = (kal_uint8 *)get_ctrl_buffer(app_buf_len);
            my_a2dp_handle = A2DP_DAF_Open(NULL, a2dp_callback_handler, &daf_config, app_buf, app_buf_len);

            count = 0;
            seed = nBytes2_t = nBytes2;
            while(!feof(fp_in))
            {
                kal_uint32 read_cnt = nBytes1+nBytes2;
                read_cnt = fread(bits_buf, 1, read_cnt, fp_in);
                if(read_cnt==0) break;
                
                ASSERT(my_ss_handle!=NULL);
                my_ss_handle->PutData(my_ss_handle, bits_buf, read_cnt);
                count += read_cnt;

                seed = my_rand(seed);
                nBytes2 = (nBytes2_t * seed) >> 16;
            }
            my_ss_handle->Flush(my_ss_handle);

            A2DP_DAF_Close(NULL);
            free_ctrl_buffer(app_buf);
            free_ctrl_buffer(bits_buf);
            fclose(fp_in);
            fclose(fp_out);
            fprintf(flog, "Put data complete: %d bytes\n", count);
        }

        /* Compare */
        if( count == file_size )
        {
            kal_uint32 first_header_word, temp;
            int error = 0;
            int file_offset = 0;

            fp_in = fopen(argv[argi], "rb");
            fp_out = fopen(filename, "rb");
            if(fp_in==NULL || fp_out==NULL)
                exit(-2);

            /* Seek sync */
            {
                int offset = 0;
                fread(&first_header_word, 1, 4, fp_out);
                while(!feof(fp_in))
                {
                    fseek(fp_in, offset, SEEK_SET);
                    fread(&temp, 1, 4, fp_in);
                    if(first_header_word==temp)
                        break;
                    offset += 1;
                }
                fprintf(flog, "File offset: %d bytes\n", offset);
            }
            while(!feof(fp_in) && !feof(fp_out))
            {
                unsigned char data_in, data_out;
                if(fread(&data_in, 1, 1, fp_in) != 1) break;
                if(fread(&data_out, 1, 1, fp_out) != 1) break;
                if(data_in!=data_out)
                {
                    error ++;
                    fprintf(flog, "%dth error in offset %d, in:0x%x, out:0x%x\n", error, file_offset, data_in, data_out);
                }
                file_offset ++;
            }
            fclose(fp_in);
            fclose(fp_out);
            fprintf(flog, "Compare data complete\n");
        }
        argi ++;
    }

    fclose(flog);
}

#endif // ... DAF_RTPSS_UT_ON_VC

#endif // ... DAF_DECODE || DAF_RTPSS_UT_ON_VC

kal_bool is_SSHdl_valid(SSHdl *hdl)
{
#if (defined(__BT_A2DP_PROFILE__) && defined(DAF_DECODE)) || defined(DAF_RTPSS_UT_ON_VC)
   if( hdl != NULL && hdl == (SSHdl *)a2dp_daf_strm.daf_ss_handle )
      return KAL_TRUE;
#endif

   return KAL_FALSE;
}
