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
 * poc_amr.c
 *
 * Project:
 * --------
 *   MTK6218B
 *
 * Description:
 * ------------
 *   Audio interface for PoC
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"

#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6223) || defined(MT6223P)  || defined(MT6235) || defined(MT6238)

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );

static const uint8 frame_length[] = { 12, 13, 15, 17, 19, 20, 26, 31, 5, 0, 0, 0, 0, 0, 0, 0 };


#define POC_AMR_STATE_ENCODING         1
#define POC_AMR_STATE_ENCODING_WAIT    2
#define POC_AMR_STATE_DECODING         3

typedef struct{
   void           (*callback)( void );
   int32          threshold;
   int32          frames;
   uint8          state;
} PoC_Struct;

static PoC_Struct *poc = (PoC_Struct *)0;


void PoC_AMR_SetBuffer(uint16 *buf, uint32 len)
{
   Media_SetBuffer( buf, len );
}

PoC_AMR_Type PoC_AMR_GetVocoderCapability(void)
{
   return POC_AMR_ALL;
}

static void pocAmrEncodeHandler( Media_Event event )
{
   ASSERT( event == MEDIA_DATA_NOTIFICATION );
   ASSERT( poc != (PoC_Struct*)0 );
   poc->frames++;
   Media_ReadDataDone( 0 );      /* clear waiting flag */
   switch( poc->state ) {
      case POC_AMR_STATE_ENCODING:
         if( poc->frames >= poc->threshold ) {
            if( poc->callback != 0 ) {
               poc->state = POC_AMR_STATE_ENCODING_WAIT;
               poc->callback();
            }
         }
      case POC_AMR_STATE_ENCODING_WAIT:   /* do nothing, waiting for MED to get data */
         break;
      default:
         ASSERT(false);
   }
}

Media_Status PoC_AMR_EncodeStart( PoC_AMR_Type vocoder, void (*media_handler)(void), int32 frame_threshold )
{
   uint32 amrType = 9;

   ASSERT( poc == (PoC_Struct *)0 );
   poc = (PoC_Struct*)get_ctrl_buffer( sizeof(PoC_Struct) );
   ASSERT( poc != (PoC_Struct *)0 );
   switch( vocoder ) {
      case POC_AMR_0475:   amrType = 10;     break;
      case POC_AMR_0515:   amrType = 9;      break;
      case POC_AMR_0590:   amrType = 8;      break;
      case POC_AMR_0670:   amrType = 7;      break;
      case POC_AMR_0740:   amrType = 6;      break;
      case POC_AMR_0795:   amrType = 5;      break;
      case POC_AMR_1020:   amrType = 4;      break;
      case POC_AMR_1220:   amrType = 3;      break;
      default:             ASSERT(false);    break;
   }
   poc->callback = media_handler;
   poc->threshold = frame_threshold;
   mediaGetControl()->rb_threshold = 1;      /* make the callback every 20 ms */
   poc->frames = -1;    /* insure always at least 1 frame inside media buffer */
   rb_ClearRB();
   Media_Record( MEDIA_FORMAT_AMR, pocAmrEncodeHandler, (void*)amrType );
   poc->state = POC_AMR_STATE_ENCODING;
   return MEDIA_SUCCESS;
}

Media_Status PoC_AMR_EncodeStop( void )
{
   ASSERT( poc != (PoC_Struct *)0 );
   ASSERT( poc->state == POC_AMR_STATE_ENCODING || poc->state == POC_AMR_STATE_ENCODING_WAIT );
   Media_Stop();
   mediaGetControl()->rb_threshold = MEDIA_RB_DEFAULT_THRESHOLD;
   free_ctrl_buffer( poc );
   poc = (PoC_Struct*)0;
   return MEDIA_SUCCESS;
}

static void pocAmrDecodeHandler( Media_Event event )
{
   ASSERT( poc->state == POC_AMR_STATE_DECODING );
}

Media_Status PoC_AMR_DecodeStart( void )
{
   ASSERT( poc == (PoC_Struct *)0 );
   poc = (PoC_Struct*)get_ctrl_buffer( sizeof(PoC_Struct) );
   ASSERT( poc != (PoC_Struct *)0 );
//   ASSERT( rb_PutNByte( (const kal_uint8*)"#!AMR\n", 6 ) == 6 );
   rb_ClearRB();
   Media_Play( MEDIA_FORMAT_AMR, pocAmrDecodeHandler, MEDIA_VMP_AS_RINGTONE );
   poc->frames = 0;
   poc->state = POC_AMR_STATE_DECODING;
   return MEDIA_SUCCESS;
}

Media_Status PoC_AMR_DecodeStop( void )
{
   ASSERT( poc != (PoC_Struct *)0 );
   ASSERT( poc->state == POC_AMR_STATE_DECODING );
   Media_Stop();
   free_ctrl_buffer( poc );
   poc = (PoC_Struct*)0;
   return MEDIA_SUCCESS;
}

int32 PoC_AMR_GetFrameCount( void )
{
   if( poc == (PoC_Struct *)0 || poc->frames <= 0 )
      return 0;
   return poc->frames;
}

int32 PoC_AMR_GetPayload( uint8 *buf, int32 max_len, int32 frames )
{
   uint8 *toc;
   uint8 ft;
   uint32 framelen;
   int32 payload_size;

   if( poc == (PoC_Struct *)0 )
      return 0;

   if( frames > poc->frames )
      frames = poc->frames;

   *buf++ = 0x10;       /* CMR = 1 */
   payload_size = 1;
   max_len--;
   toc = buf;
   buf += frames;
   while( frames > 0 ) {
      poc->frames--;
      frames--;
      rb_GetByte( &ft );
      *toc++ = ft | (frames?0x80:0);
      ft = (ft >> 3) & 0x0F;
      ASSERT( ft <= 8 || ft == 15 );
      framelen = frame_length[ft];
      if( framelen > 0 ) {
         ASSERT( rb_GetNByte( buf, framelen ) == framelen );
         buf += framelen;
      }
      max_len -= (framelen+1);
      payload_size += (framelen+1);
      ASSERT( max_len > 0 || (max_len==0&&frames==0) );
   }

   if( poc->state == POC_AMR_STATE_ENCODING_WAIT )
      poc->state = POC_AMR_STATE_ENCODING;
   return payload_size;
}

Media_Status PoC_AMR_PutPayload( const uint8 *buf, int32 len )
{
   uint32 framecount;
   const uint8 *toc;
   uint8 ft;
   uint32 framelen;

   ASSERT( poc != (PoC_Struct *)0 );
   if( rb_GetFreeSpace() < len )
      return MEDIA_FAIL;            /* buffer overflow */
   buf++;   len--;                  /* ignore CMR */
   toc = buf;
   framecount = 1;
   while( *buf++ & 0x80 )
      framecount++;
   while( framecount > 0 ) {
      framecount--;
      ft = *toc++ & 0x7F;
      rb_PutByte( ft );
      ft = (ft >> 3) & 0x0F;
      ASSERT( ft <= 8 || ft == 15 );
      framelen = frame_length[ft];
      if( framelen > 0 ) {
         ASSERT( rb_PutNByte( buf, framelen ) == framelen );
         buf += framelen;
      }
      len -= (framelen+1);
      ASSERT( len > 0 || (len==0&&framecount==0) );
   }
   return MEDIA_SUCCESS;
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* ------------------------------------------------------------------------------------------------- */
/*  New interface for making PoC AMR interface same as VoRTP interface                               */
/* ------------------------------------------------------------------------------------------------- */
#define  POC_AMR_STATE_UL_INIT         0x00
#define  POC_AMR_STATE_UL_CONFIGURED   0x01
#define  POC_AMR_STATE_UL_READY        0x02
#define  POC_AMR_STATE_UL_ENCODE       0x03
#define  POC_AMR_STATE_UL_ENCODE_WAIT  0x04
#define  POC_AMR_STATE_DL_INIT         0x10
#define  POC_AMR_STATE_DL_CONFIGURED   0x11
#define  POC_AMR_STATE_DL_READY        0x12
#define  POC_AMR_STATE_DL_DECODE       0x13

#define  POC_AMR_MAXPTIME              240
#define  POC_AMR_PTIME                 (POC_AMR_MAXPTIME/2)


typedef struct VoRTPHandleStruct_UL {
   VORTP_UL_HANDLE   vhdl;
   uint16            amrtype;
   int32             threshold;
   int32             frames;
} VoRTP_UL_AMR;

static VoRTP_UL_AMR  *pocamr = 0;

/* --------------------------------------------------------- */
/*  UL/DL shared functions                                   */
/* --------------------------------------------------------- */
static rtp_audio_codec_type poc_GetAvailableCodecs( void )
{
   return RTP_AUDIO_AMR;
}

static VORTP_STATUS poc_GetCodecCapability( rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap )
{
   ASSERT( codec_type == RTP_AUDIO_AMR );
   codec_cap->amr.ptime                 = POC_AMR_PTIME;
   codec_cap->amr.maxptime              = POC_AMR_MAXPTIME;
   codec_cap->amr.octet_align           = RTP_CODEC_SUPPORT;
   codec_cap->amr.mode_change_neighbor  = RTP_CODEC_UNSUPPORT;
   codec_cap->amr.crc                   = RTP_CODEC_UNSUPPORT;
   codec_cap->amr.robust_sorting        = RTP_CODEC_UNSUPPORT;
   codec_cap->amr.mode_set              = 0xFF;
   codec_cap->amr.mode_change_period    = RTP_CODEC_UNSPECIFIED;
   codec_cap->amr.interleaving          = RTP_CODEC_UNSPECIFIED;
   codec_cap->amr.channels              = 1;
   return VORTP_STATUS_SUCCESS;
}

static kal_uint32 poc_GetBufferSize( void )
{
   return 1024;   /* 1K bytes is quite enough */
}

static VORTP_STATUS poc_SetBuffer( kal_uint8 *buffer, kal_uint32 buffer_size )
{
   ASSERT(((uint32)buffer & 1) == 0 );       /* make sure 2-byte alignment */
   ASSERT( (buffer_size & 1) == 0 );         /* insure 2-byte alignment */
   Media_SetBuffer( (kal_uint16*)buffer, buffer_size >> 1 );
   return VORTP_STATUS_SUCCESS;
}

/* --------------------------------------------------------- */
static rtp_audio_codec_type ulamr_GetAvailableCodecs( VORTP_UL_HANDLE *hdl, rtp_audio_codec_type *alt_codec_type )
{
   rtp_audio_codec_type codec_type = poc_GetAvailableCodecs();
   (void)hdl;
   *alt_codec_type = codec_type;
   return codec_type;
}

static VORTP_STATUS ulamr_GetCodecCapability( VORTP_UL_HANDLE *hdl, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap, kal_bool alternated )
{
   (void)hdl;
   (void)alternated;
   return poc_GetCodecCapability( codec_type, codec_cap );
}

static VORTP_STATUS ulamr_Config( VORTP_UL_HANDLE *hdl, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap,
                                VORTP_UL_CALLBACK callback, void *host_data, kal_uint32 session_id )
{
   VoRTP_UL_AMR *vortp_amr = (VoRTP_UL_AMR *)hdl;
   kal_int32 ptime;

   ASSERT( codec_type == RTP_AUDIO_AMR );
   ASSERT( hdl->state == POC_AMR_STATE_UL_INIT );

   hdl->callback = callback;
   hdl->host_data = host_data;
   hdl->session_id = session_id;

   switch( codec_cap->amr.mode_set ) {
      case AMR_MODE_0_0475:   vortp_amr->amrtype = 10;      break;
      case AMR_MODE_1_0515:   vortp_amr->amrtype = 9;       break;
      case AMR_MODE_2_0590:   vortp_amr->amrtype = 8;       break;
      case AMR_MODE_3_0670:   vortp_amr->amrtype = 7;       break;
      case AMR_MODE_4_0740:   vortp_amr->amrtype = 6;       break;
      case AMR_MODE_5_0795:   vortp_amr->amrtype = 5;       break;
      case AMR_MODE_6_1020:   vortp_amr->amrtype = 4;       break;
      case AMR_MODE_7_1220:   vortp_amr->amrtype = 3;       break;
      default:                vortp_amr->amrtype = 9;       break;      /* default use AMR515 */
   }
   ptime = codec_cap->amr.ptime;
   if( ptime == RTP_CAP_UNSPECIFIED )
      ptime = POC_AMR_PTIME;
   vortp_amr->threshold = ptime/20;
   if( vortp_amr->threshold == 0 )
      vortp_amr->threshold = 1;
   hdl->state = POC_AMR_STATE_UL_CONFIGURED;
   return VORTP_STATUS_SUCCESS;
}

static kal_uint32 ulamr_GetBufferSize( VORTP_UL_HANDLE *hdl )
{
   (void)hdl;
   return poc_GetBufferSize();
}

static VORTP_STATUS ulamr_SetBuffer( VORTP_UL_HANDLE *hdl, kal_uint8 *buffer, kal_uint32 buffer_size )
{
   (void)hdl;
   ASSERT( hdl->state == POC_AMR_STATE_UL_CONFIGURED );
   ASSERT( buffer_size >= poc_GetBufferSize() );
   hdl->state = POC_AMR_STATE_UL_READY;
   return poc_SetBuffer( buffer, buffer_size );
}

static VORTP_STATUS ulamr_Close( VORTP_UL_HANDLE *hdl )
{
   ASSERT( hdl->state == POC_AMR_STATE_UL_INIT || hdl->state == POC_AMR_STATE_UL_CONFIGURED ||
      hdl->state == POC_AMR_STATE_UL_READY );
   free_ctrl_buffer( hdl );
   return VORTP_STATUS_SUCCESS;
}

static void poc_EncodeHandler( Media_Event event )
{
   uint32 savedMask;
   VORTP_UL_HANDLE *hdl = (VORTP_UL_HANDLE *)pocamr;

   ASSERT( event == MEDIA_DATA_NOTIFICATION );
   ASSERT( pocamr != (VoRTP_UL_AMR *)0 );

   savedMask = SaveAndSetIRQMask();    /* Disable interrupt for prevent race condition */
   pocamr->frames++;
   RestoreIRQMask( savedMask );
//   kal_prompt_trace( MOD_L1SP, "EncodeHdlr - state=%d, frames=%d\n", hdl->state, pocamr->frames );

   Media_ReadDataDone( 0 );      /* clear waiting flag */
   switch( hdl->state ) {
      case POC_AMR_STATE_UL_ENCODE:
         if( pocamr->frames >= pocamr->threshold ) {
            if( hdl->callback != 0 ) {
               hdl->state = POC_AMR_STATE_UL_ENCODE_WAIT;
               hdl->callback( VORTP_EVENT_UL_READY, hdl, hdl->host_data );
            }
         }
      case POC_AMR_STATE_UL_ENCODE_WAIT:   /* do nothing, waiting for MED to get data */
         break;
      default:
         ASSERT(false);
   }
}

static VORTP_STATUS ulamr_Start( VORTP_UL_HANDLE *hdl, kal_uint32 timestamp )
{
   VoRTP_UL_AMR *vortp_amr = (VoRTP_UL_AMR *)hdl;

   ASSERT( hdl->callback != 0);

   ASSERT( hdl->state == POC_AMR_STATE_UL_READY );
   ASSERT( pocamr == (VoRTP_UL_AMR *)0 );
   hdl->timestamp = timestamp;
   pocamr = vortp_amr;
   mediaGetControl()->rb_threshold = 1;      /* make the callback every 20 ms */
   vortp_amr->frames = -1;    /* insure always at least 1 frame inside media buffer */
   rb_ClearRB();
   Media_Record( MEDIA_FORMAT_AMR, poc_EncodeHandler, (void*)vortp_amr->amrtype );
   hdl->state = POC_AMR_STATE_UL_ENCODE;
   return VORTP_STATUS_SUCCESS;
}

static VORTP_STATUS ulamr_Stop( VORTP_UL_HANDLE *hdl )
{
   ASSERT( hdl->state == POC_AMR_STATE_UL_ENCODE || hdl->state == POC_AMR_STATE_UL_ENCODE_WAIT );
   Media_Stop();
   mediaGetControl()->rb_threshold = MEDIA_RB_DEFAULT_THRESHOLD;
   pocamr = (VoRTP_UL_AMR *)0;
   hdl->state = POC_AMR_STATE_UL_READY;
   return VORTP_STATUS_SUCCESS;
}

// interface only for uplink
static VORTP_STATUS ulamr_SetMix( VORTP_UL_HANDLE *hdl, kal_bool enable )
{
   (void)hdl;
   (void)enable;
   return VORTP_STATUS_FAIL;
}

static kal_int32 ulamr_GetPacketCount( VORTP_UL_HANDLE *hdl )
{
   VoRTP_UL_AMR *vortp_amr = (VoRTP_UL_AMR *)hdl;
   if( vortp_amr->frames <= 0 )
      return 0;
   return vortp_amr->frames / vortp_amr->threshold;
}

static kal_uint32 ulamr_GetPacket( VORTP_UL_HANDLE *hdl, kal_uint8 *buf, kal_uint32 buffer_size,
                                 rtp_audio_codec_type *codec_type )
{
   VoRTP_UL_AMR *vortp_amr = (VoRTP_UL_AMR *)hdl;
   uint8 *toc, ft;
   uint32 temp;
   uint32 payload_size;
   int32 max_size = (int32)buffer_size;
   int32 frames = vortp_amr->threshold;   /* frame count in a packet */

   ASSERT( vortp_amr->frames >= frames );
   ASSERT( vortp_amr->amrtype <= 10 && vortp_amr->amrtype >= 3 );
   ASSERT( hdl->state == POC_AMR_STATE_UL_ENCODE_WAIT );

   buf[0] = (uint8)0x80;                        /* RTP header byte 0, V=2, P=0, X=0, CC=0 */
   buf[4] = (uint8)(hdl->timestamp>> 24);
   buf[6] = (uint8)((hdl->timestamp&0xFF0000) >> 16);
   buf[7] = (uint8)((hdl->timestamp&0xFF00) >> 8);
   buf[8] = (uint8)(hdl->timestamp&0xFF);

   buf[12] = (uint8)((10-vortp_amr->amrtype)<<4);   /* Payload header */
   buf += 13;
   payload_size = 13;
   max_size -= 13;
   toc = buf;
   buf += frames;
   temp = SaveAndSetIRQMask();    /* Disable interrupt for prevent race condition */
   vortp_amr->frames-=frames;
   RestoreIRQMask( temp );
   hdl->timestamp += frames*160;  /* in samples unit */

   while( frames > 0 ) {
      frames--;
      rb_GetByte( &ft );
      *toc++ = ft | (frames?0x80:0);
      ft = (ft >> 3) & 0x0F;
      ASSERT( ft <= 8 || ft == 15 );
      temp = frame_length[ft];
      if( temp > 0 ) {
         ASSERT( rb_GetNByte( buf, temp ) == temp );
         buf += temp;
      }
      max_size -= (temp+1);
      payload_size += (temp+1);
      ASSERT( max_size > 0 || (max_size==0&&frames==0) );
   }
   *codec_type = RTP_AUDIO_AMR;

   hdl->state = POC_AMR_STATE_UL_ENCODE;
   return payload_size;

}

VORTP_UL_HANDLE *PoCAMR_OpenULChannel( void )
{
   VoRTP_UL_AMR *vortp_amr = (VoRTP_UL_AMR *)get_ctrl_buffer( sizeof(VoRTP_UL_AMR) );
   VORTP_UL_HANDLE *hdl = (VORTP_UL_HANDLE *)vortp_amr;

   hdl->GetAvailableCodecs = ulamr_GetAvailableCodecs;
   hdl->GetCodecCapability = ulamr_GetCodecCapability;
   hdl->Config = ulamr_Config;
   hdl->GetBufferSize = ulamr_GetBufferSize;
   hdl->SetBuffer = ulamr_SetBuffer;
   hdl->Close = ulamr_Close;
   hdl->Start = ulamr_Start;
   hdl->Stop = ulamr_Stop;
   hdl->SetMix = ulamr_SetMix;
   hdl->GetPacketCount = ulamr_GetPacketCount;
   hdl->GetPacket = ulamr_GetPacket;
   hdl->state = POC_AMR_STATE_UL_INIT;
   vortp_amr->amrtype = 0;

   return hdl;
}
/* --------------------------------------------------------- */

static rtp_audio_codec_type dlamr_GetAvailableCodecs( VORTP_DL_HANDLE *hdl, rtp_audio_codec_type *alt_codec_type )
{
   rtp_audio_codec_type codec_type = poc_GetAvailableCodecs();
   (void)hdl;
   *alt_codec_type = codec_type;
   return codec_type;
}

static VORTP_STATUS dlamr_GetCodecCapability( VORTP_DL_HANDLE *hdl, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap, kal_bool alternated )
{
   (void)hdl;
   (void)alternated;
   return poc_GetCodecCapability( codec_type, codec_cap );
}

static VORTP_STATUS dlamr_Config( VORTP_DL_HANDLE *hdl, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap,
                                 VORTP_DL_CALLBACK callback, void *host_data, kal_uint32 session_id )
{
   ASSERT( codec_type == RTP_AUDIO_AMR );
   ASSERT( hdl->state == POC_AMR_STATE_DL_INIT );

   hdl->callback = callback;
   hdl->host_data = host_data;
   hdl->session_id = session_id;
   hdl->state = POC_AMR_STATE_DL_CONFIGURED;
   return VORTP_STATUS_SUCCESS;
}

static kal_uint32 dlamr_GetBufferSize( VORTP_DL_HANDLE *hdl )
{
   (void)hdl;
   return poc_GetBufferSize();
}

static VORTP_STATUS dlamr_SetBuffer( VORTP_DL_HANDLE *hdl, kal_uint8 *buffer, kal_uint32 buffer_size )
{
   ASSERT( hdl->state == POC_AMR_STATE_DL_CONFIGURED );
   ASSERT( buffer_size >= poc_GetBufferSize() );
   hdl->state = POC_AMR_STATE_DL_READY;
   return poc_SetBuffer( buffer, buffer_size );
}

static VORTP_STATUS dlamr_Close( VORTP_DL_HANDLE *hdl )
{
   ASSERT( hdl->state == POC_AMR_STATE_DL_READY);
   free_ctrl_buffer( hdl );
   return VORTP_STATUS_SUCCESS;
}


static void poc_DecodeHandler( Media_Event event )
{
   (void)event;   /* do nothing */
}

static VORTP_STATUS dlamr_Start( VORTP_DL_HANDLE *hdl  )
{
   ASSERT( hdl->state == POC_AMR_STATE_DL_READY );

   rb_ClearRB();
   Media_Play( MEDIA_FORMAT_AMR, poc_DecodeHandler, MEDIA_VMP_AS_RINGTONE );
   hdl->state = POC_AMR_STATE_DL_DECODE;
   return VORTP_STATUS_SUCCESS;
}

static VORTP_STATUS dlamr_Stop( VORTP_DL_HANDLE *hdl )
{
   ASSERT( hdl->state == POC_AMR_STATE_DL_DECODE );
   Media_Stop();
   hdl->state = POC_AMR_STATE_DL_READY;
   return VORTP_STATUS_SUCCESS;
}

// interface only for downlink
static VORTP_STATUS dlamr_PutPacket( VORTP_DL_HANDLE *hdl, kal_uint8 *buf, kal_uint32 buffer_size, rtp_audio_codec_type codec_type )
{
   uint32 framecount;
   const uint8 *toc;
   uint8 ft;
   uint32 framelen;

   ASSERT( codec_type == RTP_AUDIO_AMR );

   if( rb_GetFreeSpace() < buffer_size )
      return VORTP_STATUS_FAIL;            /* buffer overflow */
   buf+=13;
   buffer_size-=13;                  /* ignore RTP header & CMR */
   toc = buf;
   framecount = 1;
   while( *buf++ & 0x80 )
      framecount++;
   while( framecount > 0 ) {
      framecount--;
      ft = *toc++ & 0x7F;
      rb_PutByte( ft );
      ft = (ft >> 3) & 0x0F;
      ASSERT( ft <= 8 || ft == 15 );
      framelen = frame_length[ft];
      if( framelen > 0 ) {
         ASSERT( rb_PutNByte( buf, framelen ) == framelen );
         buf += framelen;
      }
      buffer_size -= (framelen+1);
      ASSERT( buffer_size > 0 || (buffer_size==0&&framecount==0) );
   }
   return VORTP_STATUS_SUCCESS;
}

VORTP_DL_HANDLE *PoCAMR_OpenDLChannel( void )
{
   VORTP_DL_HANDLE *vortp = (VORTP_DL_HANDLE *)get_ctrl_buffer( sizeof(VORTP_DL_HANDLE) );

   vortp->GetAvailableCodecs = dlamr_GetAvailableCodecs;
   vortp->GetCodecCapability = dlamr_GetCodecCapability;
   vortp->Config = dlamr_Config;
   vortp->GetBufferSize = dlamr_GetBufferSize;
   vortp->SetBuffer = dlamr_SetBuffer;
   vortp->Close = dlamr_Close;
   vortp->Start = dlamr_Start;
   vortp->Stop = dlamr_Stop;
   vortp->PutPacket = dlamr_PutPacket;
   vortp->state = POC_AMR_STATE_DL_INIT;

   return vortp;
}

/* ------------------------------------------------------------------------------------------------- */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif   /* IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION */


