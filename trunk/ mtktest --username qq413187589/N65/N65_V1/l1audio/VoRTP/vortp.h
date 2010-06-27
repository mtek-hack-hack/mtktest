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
 *   VoRTP.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Private definition of VoRTP driver
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef VoRTP_DOT_H
#define VoRTP_DOT_H

/*****************************************************************************
*                     C O M P I L E R   F L A G S
******************************************************************************
*/
//#define _VORTP_AUTOREC_SUPPORT_
#define VOIPEVL_SUPPORT                 1
#if !defined(SIM_ON_VC)
#define NOT_TO_ALLOC_CODEC_BUF_FROM_EXT
#endif

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/
#if !defined(SIM_ON_VC)
#include "kal_release.h"
#include "kal_trace.h"
#include "drv_comm.h"
#else
#include <stdio.h>
#endif
#include "l1sp_trc.h"

#include "l1audio.h"
#include "l1audio_def.h"
#include "VMI.h"
#include "evinf.h"

#if !defined(SIM_ON_VC) && (defined(_VORTP_AUTOREC_SUPPORT_) || defined(VORTP_UNIT_TEST))
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "med_utility.h" /* med_alloc_ext_mem and med_free_ext_mem */
#endif

/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define DEFAULT_DL_PAYLOAD_SIZE         80
#define NUM_TIME_PER_SECOND             8000
#define NUM_TICK_PER_SECOND             8000
#define WRAPPED_TICK                    0
#define PROTOCOL_VERSION                2
#define MIN_HEADER_SIZE                 12
#define ESTIMATE_JITTER_RATIO           256
#define RTP_FIFO_SIZE                   4
#define RTP_DIR_UL                      0
#define RTP_DIR_DL                      1

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/
/*
typedef enum {
   PCMU,         // G.711 u-Law
   FS1016,       // Federal Standard 1016 CELP
   G721,         // ADPCM - Subsumed by G.726
   G726 = G721,
   GSM,          // GSM 06.10
   G7231,        // G.723.1 at 6.3kbps or 5.3 kbps
   DVI4_8k,      // DVI4 at 8kHz sample rate
   DVI4_16k,     // DVI4 at 16kHz sample rate
   LPC,          // LPC-10 Linear Predictive CELP
   PCMA,         // G.711 A-Law
   G722,         // G.722
   L16_Stereo,   // 16 bit linear PCM
   L16_Mono,     // 16 bit linear PCM
   G723,         // G.723
   CN,           // Confort Noise
   MPA,          // MPEG1 or MPEG2 audio
   G728,         // G.728 16kbps CELP
   DVI4_11k,     // DVI4 at 11kHz sample rate
   DVI4_22k,     // DVI4 at 22kHz sample rate
   G729,         // G.729 8kbps
   Cisco_CN,     // Cisco systems comfort noise (unofficial)
 
   CelB = 25,    // Sun Systems Cell-B video
   JPEG,         // Motion JPEG
   H261 = 31,    // H.261
   MPV,          // MPEG1 or MPEG2 video
   MP2T,         // MPEG2 transport system
   H263,         // H.263
 
   LastKnownPayloadType,
 
   DynamicBase = 96,
   MaxPayloadType = 127,

   IllegalPayloadType
} RTP_PayloadTypes;
*/
typedef struct {
   kal_uint8        *theArray;
   kal_int32        theArraySize;
   kal_int32        packetSize;
   kal_int32        payloadSize;
   kal_uint32 tick;
} RTP_DataFrame;

typedef enum {
   e_ProcessPacket,
   e_IgnorePacket,
   e_AbortTransport
} RTP_SendReceiveStatus;

typedef struct {
   kal_uint32       version:2; /* protocol version */
   kal_uint32       p:1;       /* padding flag */
   kal_uint32       x:1;       /* header extension flag */
   kal_uint32       cc:4;      /* CSRC count */
   kal_uint32       m:1;       /* marker bit */
   kal_uint32       pt:7;      /* payload type */
   kal_uint32       seq:16;    /* sequence numeber */
   kal_uint32       ts;        /* timestamp */
   kal_uint32       ssrc;      /* synchronization source */
   kal_uint32       csrc[1];   /* optional CSRC list */
} rtp_hdr_t;

typedef struct RTPJitterEntry_t RTPJitterEntry;
struct RTPJitterEntry_t {
   RTP_DataFrame    rtp;
   RTPJitterEntry   *prev;
   RTPJitterEntry   *next;
   kal_uint32       tick;
} ;

typedef struct RTPJitterHandleStruct RTP_JITTER_HANDLE;
struct RTPJitterHandleStruct {
   kal_uint16       minJitterTime; // set by master, unit: 8KHz
   kal_uint16       maxJitterTime; // set by master, unit: 8KHz
   kal_uint16       maxPayloadSize; // set by master
   kal_uint16       minPacketTime; // set by master, unit: 8KHz

   RTPJitterEntry   *oldestFrame; // set by slave
   RTPJitterEntry   *newestFrame; // set by slave
   RTPJitterEntry   *freeFrames; // set by slave
   RTPJitterEntry   *currentWriteFrame; // set by slave

   kal_uint32       lastSSRC;
   kal_uint32       lastTimestamp;
   kal_uint16       lastSeqNumber;
   kal_bool         lastSeqNumberInit;

   kal_uint8        consecutiveNoData;
   kal_int32        estimateJitterMean; // unit: 1/256 ms
   kal_int32        previousJitter;
   kal_int32        estimateJitterVar; // unit 1/256 ms
   kal_uint16       incJitterThreshold; // unit  ms
   kal_uint16       decJitterThreshold; // unit  ms
   kal_uint32       lastArrivedTimestamp; // unit TIME (8KHz)
   kal_uint32       lastArrivedTick; // unit TICK (8KHz)
   kal_bool         isArrivedInit;

   kal_bool         preBuffering; // set by slave
   kal_uint16       currentJitterTime; // set by slave, unit: 8KHz
   kal_uint8        numJitterEntry;
   kal_uint8        currentDepth; // set by slave
   kal_uint8        packetsTooLate; // set by slave
   kal_uint8        bufferOverruns; // set by slave
   kal_uint8        consecutiveBufferOverruns; // set by slave
   kal_uint8        maxConsecutiveMarkerBits; // set by master, normally 10
   kal_uint8        consecutiveMarkerBits; // set by slave
   kal_uint8        maxSIDPayloadSize;

   kal_int32        latestBurstJitter;
   kal_uint32       rtpSessionId;
   int              tidBurstExpired;
   int              tidPauseDecreasing;
   kal_bool         isBurstState;
   kal_bool         isPauseDecreasing;
   kal_uint16       periodPauseDecreasing;

   kal_int16        consecutiveEarlyPacket;
};

typedef struct RTPFifoHandleStruct RTP_FIFO_HANDLE;
struct RTPFifoHandleStruct {
   kal_uint32       maxPayloadSize; // set by master

   RTP_DataFrame    entry[RTP_FIFO_SIZE]; // set by slave
   kal_uint32       read; // set by slave
   kal_uint32       write; // set by slave
};

 typedef struct {
   rtp_audio_codec_type codec_type; // MIME subtype, RTP payload format
   rtp_audio_codec_cap  codec_cap;
   kal_uint8            codec_cap_length;
} RTP_AUDIO_CAP;

typedef struct RTPCodecParaStruct RTP_CODEC_PARA;
typedef struct RTPAudioCodecHandleStruct RTP_CODEC_HANDLE;

struct RTPCodecParaStruct {
   kal_uint32       frameTime; // samples
   kal_uint32       sampleBufferSize;

   kal_bool         (*Open)( RTP_CODEC_HANDLE *handle );
   kal_bool         (*Close)( RTP_CODEC_HANDLE *handle );
   kal_bool         (*Encode)( RTP_CODEC_HANDLE *handle, kal_uint8 *bits_buffer, kal_uint32 *buffer_size, rtp_audio_codec_type *alt_codec_type, kal_bool get_cn );
   kal_bool         (*Decode)( RTP_CODEC_HANDLE *handle, kal_uint8 *bits_buffer, kal_uint32 *buffer_size, rtp_audio_codec_type alt_codec_type );
};

typedef struct {
   kal_bool         is_g729_user;
   kal_bool         is_g7231_user;
   kal_bool         is_external;
   kal_bool         is_loader;
} RTP_CODEC_SETTING;

struct RTPAudioCodecHandleStruct {
   kal_uint8            dir; // set by master

   const RTP_CODEC_PARA *para; // set by master
   RTP_AUDIO_CAP        config; // set by master
   PCMRB                *rb; // set by master
   kal_uint32           maxTxFramesInPacket; // set by codec, referred to para
   kal_uint32           maxFrameSize; // bytes, set by codec, referred to para
   void                 *codec_data;
   kal_uint8            *codec_buffer;
   void                 *codec_data2;
   kal_char             name_str[16];
};

struct wav_header 
{
   char                 riff_chunk[4];
   unsigned int         riff_size;
   char                 riff_type[4];
   char                 fmt_chunk[4];
   unsigned int         fmt_size;
   short                fmt_codec;
   short                channels;
   unsigned int         fs;
   unsigned int         bytes_per_sec;
   short                block_align;
   short                bits_per_sample;
   char                 data_chunk[4];
   unsigned int         data_size;
};

typedef struct timer_t TIMER;
struct timer_t
{
   kal_bool         isUsed;
   kal_uint32       resetValue;
   kal_uint32       curValue;
   void             (*toCallback)(int tid);
   void             *host_data;
};

/*****************************************************************************
*                  D A T A   D E C L A R A T I O N S
******************************************************************************
*/
extern const RTP_CODEC_PARA rtp_g729_para;
extern const RTP_CODEC_PARA rtp_g726_para;
extern const RTP_CODEC_PARA rtp_g711_para;
extern const RTP_CODEC_PARA rtp_g7231_para;

extern kal_uint32 VoRTP_current_session_id_l1aud;

/* The event recorder interface */
#if VOIPEVL_SUPPORT
extern kal_bool VoRTP_isEventLogging;
#endif

extern int VoIP_MIN_JITTER_TIME; // in msec
extern int VoIP_MAX_JITTER_TIME; // in msec
#ifdef VORTP_UNIT_TEST
extern unsigned char is_rec_pcm;
extern unsigned char is_rec_dl;
extern unsigned char is_rec_ul;
extern int jitter_var_mul;
extern int jitter_mean_run;
#endif
extern kal_bool drop_output;

#if defined(SIM_ON_VC)
extern FILE *trace_info;
#endif

/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/
#if !defined(SIM_ON_VC)
extern kal_uint32 SaveAndSetIRQMask( void );
extern void RestoreIRQMask( kal_uint32 mask );
#endif
extern kal_uint16 L1Audio_GetDebugInfo( kal_uint8 index );
extern TICK vortp_get_tick(void);
/* Below's implementation are in RTPBuffer.c */
extern void RTP_SetContribSource(RTP_DataFrame *rtp, kal_int32 idx, kal_uint32 src);
extern void RTP_AssociatePacket(RTP_DataFrame *rtp, const kal_uint8 *packetBuf, kal_uint32 packetLen);
extern void RTP_DuplicatePacket(RTP_DataFrame *dest, const RTP_DataFrame *src);
extern void RTP_InitDataFrame(RTP_DataFrame *rtp, kal_uint32 payloadSize, kal_uint32 **buffer_pool);
extern RTP_SendReceiveStatus RTP_ReceiveData(RTP_DataFrame *rtp, const kal_uint8 *packetBuf, kal_uint32 packetLen);
extern kal_bool RTP_isSIDPacket(RTP_DataFrame *rtp, int maxSIDPayloadSize);

extern kal_uint32 RTPJitter_GetBufferSize( RTP_JITTER_HANDLE *handle );
extern kal_bool RTPJitter_Open( RTP_JITTER_HANDLE *handle, kal_uint8 *buffer, kal_uint32 *buffer_size, kal_uint32 session_id );
extern kal_bool RTPJitter_Close( RTP_JITTER_HANDLE *handle );
extern kal_bool RTPJitter_PutData( RTP_JITTER_HANDLE *handle, const RTP_DataFrame *rtpPacket, rtp_audio_codec_type codec_type );
extern kal_bool RTPJitter_GetData( RTP_JITTER_HANDLE *handle, RTP_DataFrame *rtpPacket, kal_uint32 timestamp );

extern kal_uint32 RTPFifo_GetBufferSize( RTP_FIFO_HANDLE *handle );
extern kal_bool RTPFifo_Open( RTP_FIFO_HANDLE *handle, kal_uint8 *buffer, kal_uint32 *buffer_size );
extern kal_bool RTPFifo_Close( RTP_FIFO_HANDLE *handle );
extern kal_bool RTPFifo_IsFull( RTP_FIFO_HANDLE *handle );
extern kal_bool RTPFifo_IsEmpty( RTP_FIFO_HANDLE *handle );
extern kal_bool RTPFifo_PutData( RTP_FIFO_HANDLE *handle, const RTP_DataFrame *rtpPacket );
extern kal_bool RTPFifo_GetData( RTP_FIFO_HANDLE *handle, RTP_DataFrame *rtpPacket );

extern rtp_audio_codec_type RTPCodec_GetAvailableCodecs( RTP_CODEC_HANDLE *handle, rtp_audio_codec_type *alt_codec_type );
extern kal_bool RTPCodec_GetCodecCapability( RTP_CODEC_HANDLE *handle, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap, kal_bool alternated );
extern kal_bool RTPCodec_Register( RTP_CODEC_HANDLE *handle, kal_uint8 dir, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap );
extern kal_bool RTPCodec_UnRegister( RTP_CODEC_HANDLE *handle );
extern int RTPCodec_QueryMaxSIDPayloadSize(RTP_CODEC_HANDLE *handle);
extern void RTPCodec_Init(void);

extern void VoIPev_Protect( void );
extern void VoIPev_UnProtect( void );
extern void VoIPev_AppendData(kal_uint8 *dataPtr, kal_uint32 dataLen);
extern void VoIPev_Flush( void );

extern int rtpCreateTimer(kal_uint32 resetVal, void (*toCallback)(int tid), void *host_data);
extern void rtpResetTimer(int tid, kal_uint32 resetValue);
extern void rtpDeleteTimer(int tid);
extern void rtpDeleteAllTimer(void);
extern void *rtpTimerGetHostData(int tid);

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/
#define VORTP_TRACE kal_trace
#if !defined(SIM_ON_VC)
#define ENTER_CRITICAL()            { kal_uint32 _savedMask = SaveAndSetIRQMask();
#define EXIT_CRITICAL()             RestoreIRQMask(_savedMask); }
#else
#define kal_sprintf                 sprintf

#define med_alloc_ext_mem           malloc
__inline void med_free_ext_mem(void **ptr)
{
   free( *ptr );
   *ptr = NULL;
}

#define ENTER_CRITICAL()            {
#define EXIT_CRITICAL()             }

#endif

#define RTP_ASSERT(x)               ASSERT(x)
#define aligned_sizeof(_type)       ((sizeof(_type)+3)&(~3))
#define is_aligned(_ptr)            (0==((unsigned int)(_ptr)&3))

#define Tick2Time(_t)               ((kal_uint32)(_t))
#define Time2Tick(_t)               ((TICK)(_t))
#define Msec2Time(_ms)              ((kal_uint32)(_ms) * (NUM_TIME_PER_SECOND / 1000))
#define Msec2Tick(_ms)              ((TICK)(_ms) * (NUM_TICK_PER_SECOND / 1000))
#define Time2Msec(_t)               ((int)(_t) * 1000 / NUM_TIME_PER_SECOND)
#define Tick2Msec(_t)               ((int)(_t) * 1000 / NUM_TICK_PER_SECOND)
#define GetDurationTick(_t_prev,_t_post) ((_t_post) - (_t_prev))
#define GetDurationTime(_t_prev,_t_post) ((_t_post) - (_t_prev))

#define Tick                        vortp_get_tick

#define VORTP_TRACE_EVENT(ev,ID)                              \
{                                                             \
   EVINF_WRITE_HDR((ev), Tick(), (ID), sizeof(ev));           \
   VoIPev_Protect();                                          \
   VoIPev_AppendData((kal_uint8 *)(&(ev)), (ev).uInfoLength); \
   VoIPev_Flush();                                            \
   VoIPev_UnProtect();                                        \
}

#define VORTP_CODEC_TRACE_EVENT(ev,ID,pcm_p,bit_p)                 \
{                                                                  \
   UINT32 length = sizeof(ev) + (((ev).uPCMLength + 1) & (~1)) +   \
                   (((ev).uBitstreamLength + 1) & (~1));           \
   EVINF_WRITE_HDR((ev), Tick(), (ID), length);                    \
   VoIPev_Protect();                                               \
   VoIPev_AppendData((kal_uint8 *)(&(ev)), sizeof(ev));            \
   VoIPev_AppendData((kal_uint8 *)(pcm_p), (ev).uPCMLength);       \
   VoIPev_AppendData((kal_uint8 *)(bit_p), (ev).uBitstreamLength); \
   VoIPev_Flush();                                                 \
   VoIPev_UnProtect();                                             \
}

#define VORTP_SES_TRACE_EVENT(ev,ID,cap_p)                           \
{                                                                    \
   UINT32 length = sizeof(ev) + (((ev).uCodecCapLength + 1) & (~1)); \
   EVINF_WRITE_HDR((ev), Tick(), (ID), length);                      \
   VoIPev_Protect();                                                 \
   VoIPev_AppendData((kal_uint8 *)(&(ev)), sizeof(ev));              \
   VoIPev_AppendData((kal_uint8 *)(cap_p), (ev).uCodecCapLength);    \
   VoIPev_Flush();                                                   \
   VoIPev_UnProtect();                                               \
}

#define IS_VOIPEVL_LOGGING()            (VoRTP_isEventLogging==KAL_TRUE)
#ifdef _VORTP_AUTOREC_SUPPORT_
#define DEFAULT_LOGGING_OPTION          0x0000
#else
#define DEFAULT_LOGGING_OPTION          0x0025
#endif
#define VOIPEVL_LOGGING_OPTION          (DEFAULT_LOGGING_OPTION | L1Audio_GetDebugInfo(VOIPEVL_DEBUG_INFO))
/*
 * VOIPEVL_LOGGING_OPTION:
 *    x x x x k j i h g f e e d c b a
 *               | | | | | | | | | |
 *               | | | | | | | | | -- enable uplink packet logging
 *               | | | | | | | | ---- enable uplink pcm logging
 *               | | | | | | | ------ enable downlink packet logging
 *               | | | | | | -------- enable downlink pcm logging
 *               | | | | ------------ VoIP logging format, 1: WAV, 2: EVL
 *               | | | -------------- VoIP logging location, 0: NAND Flash drive, 1: Removable drive
 *               | | ---------------- force to disable DTX
 *               |   ------------------ enable prebuffering
 *                  ------------------- disable network info logging
 */
#if !defined(VORTP_UNIT_TEST)
#define IS_VOIPEVL_LOGGING_UL()         (IS_VOIPEVL_LOGGING() && (VOIPEVL_LOGGING_OPTION&0x1))
#define IS_VOIPEVL_LOGGING_ULPCM()      (IS_VOIPEVL_LOGGING() && (VOIPEVL_LOGGING_OPTION&0x2))
#define IS_VOIPEVL_LOGGING_DL()         (IS_VOIPEVL_LOGGING() && (VOIPEVL_LOGGING_OPTION&0x4))
#define IS_VOIPEVL_LOGGING_DLPCM()      (IS_VOIPEVL_LOGGING() && (VOIPEVL_LOGGING_OPTION&0x8))
#else
#define IS_VOIPEVL_LOGGING_UL()         (IS_VOIPEVL_LOGGING() && ((VOIPEVL_LOGGING_OPTION&0x1) || (is_rec_ul == 1)))
#define IS_VOIPEVL_LOGGING_ULPCM()      (IS_VOIPEVL_LOGGING() && ((VOIPEVL_LOGGING_OPTION&0x2) || ((is_rec_ul == 1) && (is_rec_pcm == 1))))
#define IS_VOIPEVL_LOGGING_DL()         (IS_VOIPEVL_LOGGING() && ((VOIPEVL_LOGGING_OPTION&0x4) || (is_rec_dl == 1)))
#define IS_VOIPEVL_LOGGING_DLPCM()      (IS_VOIPEVL_LOGGING() && ((VOIPEVL_LOGGING_OPTION&0x8) || ((is_rec_dl == 1) && (is_rec_pcm == 1))))
#endif
#define GET_VOIPEVL_FORMAT()            ((VOIPEVL_LOGGING_OPTION&0x0030)>>4)
#define IS_VOIPEVL_IN_RMV_DRV()         (VOIPEVL_LOGGING_OPTION&0x0040)
#define IS_DTX_DISABLED()               (VOIPEVL_LOGGING_OPTION&0x0080)
#define IS_PREBUFFERING_DISABLED()      (VOIPEVL_LOGGING_OPTION&0x0100)
#define IS_VOIPEVL_LOGGING_NW()         (IS_VOIPEVL_LOGGING() && ((VOIPEVL_LOGGING_OPTION&0x0200) == 0))

/*****************************************************************************
*       I N L I N E   F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/
__inline kal_uint32 GET_UINT32(kal_uint8 *ptr)
{
   kal_uint32 u32_t;
   u32_t = (kal_uint32)ptr[0] << 24;
   u32_t += (kal_uint32)ptr[1] << 16;
   u32_t += (kal_uint32)ptr[2] << 8;
   u32_t += (kal_uint32)ptr[3];
   return u32_t;
}

__inline void PUT_UINT32(kal_uint8 *ptr, kal_uint32 u32_t)
{
   ptr[0] = (kal_uint8)( (u32_t >> 24) & 0xff );
   ptr[1] = (kal_uint8)( (u32_t >> 16) & 0xff );
   ptr[2] = (kal_uint8)( (u32_t >> 8) & 0xff );
   ptr[3] = (kal_uint8)( (u32_t) & 0xff );
}


__inline kal_uint16 GET_UINT16(kal_uint8 *ptr)
{
   kal_uint16 u16_t;
   u16_t = (kal_uint32)ptr[0] << 8;
   u16_t += (kal_uint32)ptr[1];
   return u16_t;
}

__inline void PUT_UINT16(kal_uint8 *ptr, kal_uint16 u16_t)
{
   ptr[0] = (kal_uint8)( (u16_t >> 8) & 0xff );
   ptr[1] = (kal_uint8)( (u16_t) & 0xff );
}


__inline rtp_audio_codec_type RTP_GetCodecType(RTP_DataFrame *rtp) { return( (rtp_audio_codec_type)(((rtp_hdr_t *)(rtp->theArray))->ssrc) ); }
__inline void RTP_SetCodecType(RTP_DataFrame *rtp, rtp_audio_codec_type codec_type) { ((rtp_hdr_t *)(rtp->theArray))->ssrc = (kal_uint32)codec_type; }

__inline kal_uint8 RTP_GetPayloadType(RTP_DataFrame *rtp) { return (kal_uint8)(rtp->theArray[1]&0x7f); }
__inline void RTP_SetPayloadType(RTP_DataFrame *rtp, kal_uint8 t) {
   ASSERT(t <= 0x7f);
   rtp->theArray[1] &= 0x80;
   rtp->theArray[1] |= t;
}

__inline kal_uint32 RTP_GetVersion(RTP_DataFrame *rtp) { return( (rtp->theArray[0]>>6)&3 ); }

__inline kal_bool RTP_GetExtension(RTP_DataFrame *rtp) { return( (rtp->theArray[0]&0x10)!=0 ); }
__inline void RTP_SetExtension(RTP_DataFrame *rtp, kal_bool ext) {
   if(ext==KAL_TRUE)
      rtp->theArray[0] |= 0x10;
   else
      rtp->theArray[0] &= ~0x10;
}

__inline kal_uint32 RTP_GetMarker(RTP_DataFrame *rtp) { return( (rtp->theArray[1]&0x80) >> 7 ); }
__inline void RTP_SetMarker(RTP_DataFrame *rtp, kal_bool m) {
   if(m==KAL_TRUE)
      rtp->theArray[1] |= 0x80;
   else
      rtp->theArray[1] &= ~0x80;
}

__inline kal_uint16 RTP_GetSequenceNumber(RTP_DataFrame *rtp) { return GET_UINT16(&(rtp->theArray[2])); }
__inline void RTP_SetSequenceNumber(RTP_DataFrame *rtp, kal_uint16 n) { PUT_UINT16(&(rtp->theArray[2]), n); }

__inline kal_uint32 RTP_GetTimestamp(RTP_DataFrame *rtp)
{
   ASSERT(rtp != NULL);
   ASSERT(rtp->theArray != NULL);
   return GET_UINT32(&(rtp->theArray[4]));
}
__inline void RTP_SetTimestamp(RTP_DataFrame *rtp, kal_uint32 t) { PUT_UINT32(&(rtp->theArray[4]), t); }

__inline kal_uint32 RTP_GetSyncSource(RTP_DataFrame *rtp) { return GET_UINT32(&(rtp->theArray[8])); }
__inline void RTP_SetSyncSource(RTP_DataFrame *rtp, kal_uint32 s) { PUT_UINT32(&(rtp->theArray[8]), s); }

__inline kal_int32 RTP_GetContribSrcCount(RTP_DataFrame *rtp) { return rtp->theArray[0]&0xf; }
__inline kal_uint32 RTP_GetContribSource(RTP_DataFrame *rtp, kal_int32 idx) { 
   ASSERT( idx <= RTP_GetContribSrcCount(rtp) );
   return GET_UINT32(&(rtp->theArray[MIN_HEADER_SIZE+idx*4]));
}
__inline kal_int32 RTP_GetExtensionSize(RTP_DataFrame *rtp) {
   if (RTP_GetExtension(rtp))
      return *(kal_uint16 *)&(rtp->theArray[MIN_HEADER_SIZE + 4*RTP_GetContribSrcCount(rtp) + 2]);
   else
      return 0;
}

__inline kal_int32 RTP_GetHeaderSize(RTP_DataFrame *rtp) {
   kal_int32 sz = MIN_HEADER_SIZE + 4*RTP_GetContribSrcCount(rtp);
   if (RTP_GetExtension(rtp))
      sz += 4 + RTP_GetExtensionSize(rtp);
   return sz;
}

__inline kal_bool RTP_SetMinSize(RTP_DataFrame *rtp, kal_int32 sz) {
   if( sz > rtp->theArraySize )
      return KAL_FALSE;
   rtp->packetSize = sz;
   return KAL_TRUE;
}

__inline kal_bool RTP_SetExtensionSize(RTP_DataFrame *rtp, kal_int32 sz) {
   if (RTP_SetMinSize(rtp, MIN_HEADER_SIZE + 4*RTP_GetContribSrcCount(rtp) + 4+4*sz + rtp->payloadSize)==KAL_FALSE)
      return KAL_FALSE;

   RTP_SetExtension(rtp, KAL_TRUE);
   *(kal_uint16 *)&(rtp->theArray[MIN_HEADER_SIZE + 4*RTP_GetContribSrcCount(rtp) + 2]) = (kal_uint16)sz;
   return KAL_TRUE;
}
__inline kal_uint8 *RTP_GetExtensionPtr(RTP_DataFrame *rtp) {
   if (RTP_GetExtension(rtp))
      return (kal_uint8 *)&(rtp->theArray[MIN_HEADER_SIZE + 4*RTP_GetContribSrcCount(rtp) + 4]);

   return NULL;
}

__inline kal_int32 RTP_GetExtensionType(RTP_DataFrame *rtp) { // -1 is no extension
   if (RTP_GetExtension(rtp))
      return *(kal_uint16 *)&(rtp->theArray[MIN_HEADER_SIZE + 4*RTP_GetContribSrcCount(rtp)]);
   else
      return -1;
}
__inline void RTP_SetExtensionType(RTP_DataFrame *rtp, int type) {
   if (type < 0)
      RTP_SetExtension(rtp, KAL_FALSE);
   else {
      if (RTP_GetExtension(rtp)==KAL_FALSE)
         RTP_SetExtensionSize(rtp, 0);
      *(kal_uint16 *)&(rtp->theArray[MIN_HEADER_SIZE + 4*RTP_GetContribSrcCount(rtp)]) = (kal_uint16)type;
  }
}

__inline kal_int32 RTP_GetPayloadSize(RTP_DataFrame *rtp) { return rtp->payloadSize; }
__inline kal_bool RTP_SetPayloadSize(RTP_DataFrame *rtp, kal_int32 sz) {
   rtp->payloadSize = sz;
   return RTP_SetMinSize(rtp, (rtp->theArray==NULL)?MIN_HEADER_SIZE:RTP_GetHeaderSize(rtp)+rtp->payloadSize);
}

__inline kal_uint8 *RTP_GetPayloadPtr(RTP_DataFrame *rtp) { return (kal_uint8 *)(rtp->theArray+RTP_GetHeaderSize(rtp)); }

__inline kal_int32 RTP_GetPaddingSize(RTP_DataFrame *rtp) {
   if(((rtp->theArray[0]>>5)&1)==0)
      return 0;
   else
      return rtp->theArray[rtp->packetSize-1];
}

__inline void RTP_SetTick(RTP_DataFrame *rtp, kal_uint32 tick) {
   rtp->tick = tick;
}

__inline kal_uint32 RTP_GetTick(RTP_DataFrame *rtp) {
   return rtp->tick;
}

#endif /* VoRTP_DOT_H */

