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
 *   VoRTP.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   VoRTP interface and driver, for VoIP application
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

/*****************************************************************************
*                     C O M P I L E R   F L A G S
******************************************************************************
*/
#define ALLOW_UL_WAIT  0

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/
#include "l1audio.h"
#include "VoRTP.h"
#if !defined(SIM_ON_VC)
#include "rtc_sw.h"
#include "fsal.h"
#endif
#include "media.h"

#if VORTP_SUPPORT || defined(VORTP_UNIT_TEST)

/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define VORTP_HANDLE_STATE_INITIALIZED  1
#define VORTP_HANDLE_STATE_CONFIGURED   2
#define VORTP_HANDLE_STATE_READY        3
#define VORTP_HANDLE_STATE_STREAMING    4

#if !defined(SIM_ON_VC)
#define NUM_SYSTIME_PER_SECOND          32768
#else
#define NUM_SYSTIME_PER_SECOND          8000
#endif

//#define AUTOREC_MEDIA_BUF_SIZE          (48 * 1024)
#define AUTOREC_MEDIA_BUF_SIZE          (200 * 1024)

#define NUM_TIMER                       8
#define PERIOD_DUMP_INFO                (10*50) /* 10 s */

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/
typedef struct VoRTPUplinkInternalStruct VORTP_UL_INT;
struct VoRTPUplinkInternalStruct {
   VORTP_UL_HANDLE      handle;

   VMI_HANDLE           *vmi_handle;
   RTP_FIFO_HANDLE      fifo_handle;
   RTP_CODEC_HANDLE     codec_handle;

   kal_uint8            *buffer_pool;
   kal_int32            buffer_pool_size;

   kal_bool             mix_enable;

   kal_uint32           txCurrentPayloadSize;
   kal_uint32           txFrameCount;
   kal_uint32           txPacketCount;
   kal_bool             txSilent;
   rtp_audio_codec_type txAltCodecType;
   RTP_DataFrame        txAltPacket;
   RTP_DataFrame        txCNPacket;
#if ALLOW_UL_WAIT
   kal_bool             wait;
#endif

   VORTP_UL_INT         *next;
};

typedef struct VoRTPDownlinkInternalStruct VORTP_DL_INT;
struct VoRTPDownlinkInternalStruct {
   VORTP_DL_HANDLE      handle;

   VMI_HANDLE           *vmi_handle;
   RTP_JITTER_HANDLE    jitter_handle;
   RTP_CODEC_HANDLE     codec_handle;

   kal_uint8            *buffer_pool;
   kal_int32            buffer_pool_size;

   kal_uint32           rxTimestamp;
   kal_bool             rxTimestampInit;
   kal_uint8            *rxCurrentDecodePtr;
   RTP_DataFrame        rxCurrentDecodePacket;
   kal_uint32           rxCurrentPayloadSize;
   rtp_audio_codec_type rxCurrentCodecType;
   
   VORTP_DL_INT         *next;

   // Below is the debug info
   kal_uint32           rxLastTimestamp;
   kal_uint32           rxBadFrameDelayCount;
   kal_uint32           consecutiveNoData;
   kal_uint32           consecutiveNoDataStartTime;

   kal_uint32           totalArrivedPackets;
   kal_uint32           totalPlayedPackets;
   kal_uint16           rxLastPlayedSeq;
   kal_bool             rxLastPlayedSeqInit;
   kal_uint32           totalMissedPackets;
};

typedef struct {
   VORTP_EVENT      event_t;
   void             *handle;
   void             *host_data;
} _ut_VoRTP_PARAM_T;

/*****************************************************************************
*                        P U B L I C   D A T A
******************************************************************************
*/
#if VOIPEVL_SUPPORT
kal_bool VoRTP_isEventLogging;
#endif
kal_uint32 VoRTP_current_session_id_l1aud;

int VoIP_MIN_JITTER_TIME = 30;
int VoIP_MAX_JITTER_TIME = 1200;
#if defined(VORTP_UNIT_TEST)
unsigned char is_rec_pcm = 0;
unsigned char is_rec_ul = 0;
unsigned char is_rec_dl = 1;
int jitter_var_mul = 3;
int jitter_mean_run = 32;
#endif

kal_bool drop_output = KAL_FALSE;

/*****************************************************************************
*                       P R I V A T E   D A T A
******************************************************************************
*/
static struct {
   kal_uint16           audId;

   VORTP_UL_INT         *uplinkHead;
   VORTP_DL_INT         *downlinkHead;
   VMI_EVENT            vmiEvents;

   VORTP_TONE_CALLBACK  toneCallback;
   void                 *toneData;
   
   kal_uint32           numStreams;

   TICK                 lastTick; // Internal clock, 8,000Hz
   kal_uint32           lastSystemTime; // system clock, 32,768 Hz
   int                  tidDumpInfo;
} VoRTP_context;

static TIMER rtpTimerArray[NUM_TIMER];
static kal_mutexid rtpTimerLock;

#if defined(VORTP_AUTOREC_SUPPORT_) || defined(VORTP_UNIT_TEST)
/* Auto record */
#if !defined(SIM_ON_VC)
static STFSAL fAutoRec;
#else
static FILE *fAutoRec;
#endif
static kal_uint16 *pAutoRecBuffer;
static kal_uint8 uIncNumber;
static kal_bool bWriteToRemDrv;
static Media_Format autoRecordingFormat;
#endif

#if defined(VORTP_UNIT_TEST)
/* Auto speak */
static struct {
#if !defined(SIM_ON_VC)
   STFSAL            fAutoSpeak;
#else
   FILE              *fAutoSpeak;
#endif
   char              filename[40];
   int               reopen;
   struct wav_header stWavHdr;
   kal_uint32        sample_elapsed;
   kal_uint16        *pAutoSpeakBuffer;
   kal_uint8         *pFSALBuffer;
   kal_uint8         uIncNumber;
   kal_bool          bReadFromRemDrv;
   VMI_HANDLE        *vmi_handle;
} vortp_auto_speak;
static kal_bool autoSpeakEnable;

/* Unit test data */
static struct {
   struct {
      VORTP_UL_HANDLE   *uplink;
      VORTP_DL_HANDLE   *downlink;
      kal_uint8         *app_buffer;
      kal_uint16        ul_seq_no;
#if !defined(SIM_ON_VC)
      STFSAL            fp_ul, fp_dl;
      kal_uint8         *fs_buf_ul, *fs_buf_dl;
#else
      FILE              *fp_ul, *fp_dl;
#endif
   } session[10];
   kal_uint8        packet_buffer[256];
} ut_VoRTP;

static _ut_VoRTP_PARAM_T _ut_VoRTP_Param;
static int _ut_VoRTP_loopback_ = 1;
static int _ut_VoRTP_save_ = 0;
#endif // ... defined(VORTP_UNIT_TEST)

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/
#define Systime2Tick(_t)                (((_t) * NUM_TICK_PER_SECOND) / NUM_SYSTIME_PER_SECOND)
#define Tick2Systime(_t)                (((_t) * NUM_SYSTIME_PER_SECOND) / NUM_TICK_PER_SECOND)
#if !defined(SIM_ON_VC)
#define GetCurrentSystime               drv_get_current_time
#define GetDurationSystime(_p,_c)       drv_get_duration_tick((_p),(_c))
#else
#define GetCurrentSystime               get_current_time
#define GetDurationSystime(_p,_c)       (((_c)>(_p))?((_c)-(_p)):0)
#endif

/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/
#if defined(VORTP_AUTOREC_SUPPORT_) || defined(VORTP_UNIT_TEST)
static void vortp_AutoRec_Start( void );
static void vortp_AutoRec_Stop( void );
#endif

#if defined(VORTP_UNIT_TEST)
static void vortp_AutoSpeak_Start( void );
static void vortp_AutoSpeak_Stop( void );
#endif

/*****************************************************************************
*                          F U N C T I O N S
******************************************************************************
*/

/*****************************************************************************
 * FUNCTION
 *  vortp_get_tick
 * DESCRIPTION
 *  This function return the system time in the unit of 8KHz.
 *  The system time is not an absolute value.
 * PARAMETERS
 *  void
 * RETURNS
 *  TICK                      The reference system time
 *****************************************************************************
 */
TICK vortp_get_tick(void)
{
   TICK current_tick;
   kal_uint32 current_systime;
   kal_uint32 dur_systime;
   TICK dur_tick;
   kal_uint32 last_system_time;
   kal_uint32 last_tick;

   ENTER_CRITICAL();
   
   last_system_time = VoRTP_context.lastSystemTime;
   last_tick = VoRTP_context.lastTick;
   
   EXIT_CRITICAL();

   current_systime = GetCurrentSystime();
   dur_systime = GetDurationSystime(last_system_time, current_systime);
   
   if(dur_systime > Tick2Systime(320))
   {
      kal_prompt_trace(MOD_L1SP, "warning:dur_systime=%d\n", dur_systime);
   }
   dur_tick = Systime2Tick(dur_systime);
   current_tick = last_tick;
   current_tick += dur_tick;

   return current_tick;
}

/*****************************************************************************
 * FUNCTION
 *  vortp_update_tick
 * DESCRIPTION
 *  This function increments the system time in unit of 8KHz.
 * PARAMETERS
 *  t               [IN]      The increment value
 * RETURNS
 *  void
 *****************************************************************************
 */
void vortp_update_tick(TICK t)
{
   ENTER_CRITICAL();
   VoRTP_context.lastTick += t;
   VoRTP_context.lastSystemTime = GetCurrentSystime();
   EXIT_CRITICAL();
   
   return;
}

int rtpCreateTimer(kal_uint32 resetVal, void (*toCallback)(int tid), void *host_data)
{
   int tid;
   TIMER *this = NULL;

   kal_take_mutex(rtpTimerLock);
   for(tid=0; tid<NUM_TIMER; tid++)
   {
      this = &rtpTimerArray[tid];
      if(this->isUsed == KAL_FALSE)
      {
         this->isUsed = KAL_TRUE;
         this->resetValue = resetVal;
         this->curValue = resetVal;
         this->toCallback = toCallback;
         this->host_data = host_data;
         kal_give_mutex(rtpTimerLock);
         return tid;
      }
   }

   kal_give_mutex(rtpTimerLock);
   return -1;
}

void rtpResetTimer(int tid, kal_uint32 resetValue)
{
   if(tid < 0) return;
   
   kal_take_mutex(rtpTimerLock);
   RTP_ASSERT(rtpTimerArray[tid].isUsed == KAL_TRUE);
   rtpTimerArray[tid].curValue = rtpTimerArray[tid].resetValue = resetValue;
   kal_give_mutex(rtpTimerLock);
}

void rtpDeleteTimer(int tid)
{
   if(tid < 0) return;

   kal_take_mutex(rtpTimerLock);
   RTP_ASSERT(rtpTimerArray[tid].isUsed == KAL_TRUE);
   rtpTimerArray[tid].isUsed = KAL_FALSE;
   kal_give_mutex(rtpTimerLock);
}

void rtpDeleteAllTimer()
{
   int tid;

   kal_take_mutex(rtpTimerLock);
   for(tid=0; tid<NUM_TIMER; tid++)
      rtpTimerArray[tid].isUsed = KAL_FALSE;
   kal_give_mutex(rtpTimerLock);
   
}

void *rtpTimerGetHostData(int tid)
{
   if(tid < 0) return NULL;

   RTP_ASSERT(rtpTimerArray[tid].isUsed == KAL_TRUE);
   return rtpTimerArray[tid].host_data;
}

void rtpTimerTick()
{
   int tid;
   TIMER *this = NULL;

   for(tid=0; tid<NUM_TIMER; tid++)
   {
      this = &rtpTimerArray[tid];
      kal_take_mutex(rtpTimerLock);
      if((this->isUsed == KAL_TRUE) && (this->resetValue != 0) && ((--this->curValue) == 0))
      {
         this->curValue = this->resetValue;
         kal_give_mutex(rtpTimerLock);
         this->toCallback(tid);
      }
      else
         kal_give_mutex(rtpTimerLock);
   }
}

void _vortp_dump_info(int tid)
{
   VORTP_DL_INT *dl = VoRTP_context.downlinkHead;

   while(dl != NULL)
   {
      VORTP_TRACE( TRACE_INFO, VORTP_DL_INFO1, dl->handle.session_id, dl->totalArrivedPackets, dl->totalPlayedPackets, dl->totalMissedPackets);
      dl = dl->next;
   }
}

/*****************************************************************************
 * FUNCTION
 *  _trace_dl_packet_arrival_
 * DESCRIPTION
 *  This function puts traces of downlink RTP packet arrived.
 * PARAMETERS
 *  downlink        [IN]      The downlink channel handle
 *  rtp             [IN]      The arrived RTP packet
 * RETURNS
 *  void
 *****************************************************************************
 */
static void _trace_dl_packet_arrival_( VORTP_DL_INT *downlink, RTP_DataFrame *rtp )
{
   kal_uint16 seq_no = RTP_GetSequenceNumber( rtp );
   kal_uint32 timestamp = RTP_GetTimestamp( rtp );
   rtp_audio_codec_type codec_type = RTP_GetCodecType( rtp );
   kal_uint32 payload_size = RTP_GetPayloadSize( rtp );
   kal_uint8 payload_type = RTP_GetPayloadType( rtp );
   kal_uint8 marker = (kal_uint8)RTP_GetMarker( rtp );

   VORTP_TRACE( TRACE_GROUP_VORTP, VORTP_DL_ARRIVAL, downlink->handle.session_id, seq_no, timestamp, codec_type, payload_size, payload_type, marker );
}

/*****************************************************************************
 * FUNCTION
 *  _trace_dl_packet_play_
 * DESCRIPTION
 *  This function puts traces of downlink RTP packet played.
 * PARAMETERS
 *  downlink        [IN]      The downlink channel handle
 *  rtp             [IN]      The arrived RTP packet
 * RETURNS
 *  void
 *****************************************************************************
 */
static void _trace_dl_packet_play_( VORTP_DL_INT *downlink, RTP_DataFrame *rtp )
{
   kal_uint16 seq_no = RTP_GetSequenceNumber( rtp );
   kal_uint32 timestamp = RTP_GetTimestamp( rtp );
   rtp_audio_codec_type codec_type = RTP_GetCodecType( rtp );
   kal_uint32 payload_size = RTP_GetPayloadSize( rtp );
   kal_uint8 payload_type = RTP_GetPayloadType( rtp );
   kal_uint8 marker = (kal_uint8)RTP_GetMarker( rtp );

   VORTP_TRACE( TRACE_GROUP_VORTP, VORTP_DL_PLAY, downlink->handle.session_id, seq_no, timestamp, codec_type, payload_size, payload_type, marker );
}

/*****************************************************************************
 * FUNCTION
 *  _trace_ul_packet_born_
 * DESCRIPTION
 *  This function puts traces of uplink RTP packet born.
 * PARAMETERS
 *  uplink          [IN]      The uplink channel handle
 *  rtp             [IN]      The arrived RTP packet
 * RETURNS
 *  void
 *****************************************************************************
 */
static void _trace_ul_packet_born_( VORTP_UL_INT *uplink, RTP_DataFrame *rtp )
{
   kal_uint32 timestamp = RTP_GetTimestamp( rtp );
   rtp_audio_codec_type codec_type = RTP_GetCodecType( rtp );
   kal_uint32 payload_size = RTP_GetPayloadSize( rtp );
   kal_uint8 marker = (kal_uint8)RTP_GetMarker( rtp );

   VORTP_TRACE( TRACE_GROUP_VORTP, VORTP_UL_BORN, uplink->handle.session_id, timestamp, codec_type, payload_size, marker );
}

/*****************************************************************************
 * FUNCTION
 *  _trace_ul_packet_sent_
 * DESCRIPTION
 *  This function puts traces of uplink RTP packet sent.
 * PARAMETERS
 *  uplink          [IN]      The uplink channel handle
 *  rtp             [IN]      The arrived RTP packet
 * RETURNS
 *  void
 *****************************************************************************
 */
static void _trace_ul_packet_sent_( VORTP_UL_INT *uplink, RTP_DataFrame *rtp )
{
   kal_uint32 timestamp = RTP_GetTimestamp( rtp );
   rtp_audio_codec_type codec_type = RTP_GetCodecType( rtp );
   kal_uint32 payload_size = RTP_GetPayloadSize( rtp );
   kal_uint8 marker = (kal_uint8)RTP_GetMarker( rtp );

   VORTP_TRACE( TRACE_GROUP_VORTP, VORTP_UL_SENT, uplink->handle.session_id, timestamp, codec_type, payload_size, marker );
}

#ifndef SIM_ON_VC
static int query_mmi_qos()
{
   extern kal_msgqid mmi_ext_qid;
   kal_msgq_info mmi_msgq_info;
   int mmi_qos;
   
   if(KAL_FALSE == kal_get_queue_info(mmi_ext_qid, &mmi_msgq_info))
      return 0;
   
   mmi_qos = (mmi_msgq_info.pending_msgs * 10 + 5) / mmi_msgq_info.max_msgs;
   return mmi_qos;
}
#else
#define query_mmi_qos()   (0)
#endif

/*****************************************************************************
 * FUNCTION
 *  _vortp_process
 * DESCRIPTION
 *  This function is the event handler to control the whole process of encoding and decoding.
 * PARAMETERS
 *  data                      NOT USED
 * RETURNS
 *  void
 *****************************************************************************
 */
static void _vortp_process( void *data )
{
   register VORTP_UL_INT *uplink = VoRTP_context.uplinkHead;
   register VORTP_DL_INT *downlink = VoRTP_context.downlinkHead;
   register RTP_DataFrame *rtp;
   kal_bool isContinued;
   kal_bool result;
   kal_uint32 length;
   kal_uint32 savedMask;
   kal_int32 SlowIdleValue;

   (void)data;

   vortp_update_tick(VMI_FRAME_SIZE);
   rtpTimerTick();

   if( VoRTP_context.vmiEvents&VMI_EVENT_TONE_OFF )
   {
      if( VoRTP_context.toneCallback!=NULL )
         VoRTP_context.toneCallback( VORTP_EVENT_TONE_FINISH, VoRTP_context.toneData );

      savedMask = SaveAndSetIRQMask();
      VoRTP_context.vmiEvents &= ~VMI_EVENT_TONE_OFF;
      RestoreIRQMask( savedMask );
   }

   SlowIdleValue = (kal_int32) L1Audio_Disable_DSPSlowIdle();
   ASSERT( SlowIdleValue == 1 );

   while( downlink!=NULL )
   {
      int processed_samples = 0;

      VoRTP_current_session_id_l1aud = downlink->handle.session_id;
      do
      {
         isContinued = KAL_TRUE;
         if( PCMRB_GetFreeSpace( &downlink->vmi_handle->rb )>=(int32)downlink->codec_handle.para->frameTime )
         {
            if( downlink->rxCurrentPayloadSize==0 )
            { // get new packet from jitter buffer
               rtp = &downlink->rxCurrentDecodePacket;
               rtp->theArray = NULL;
               isContinued = RTPJitter_GetData( &downlink->jitter_handle, rtp, downlink->rxTimestamp );
               if( isContinued==KAL_TRUE )
               { // it's time to decode packet whether it is available or not
                  if( rtp->theArray==NULL )
                  {
                     downlink->rxCurrentDecodePtr = NULL;
                     downlink->rxCurrentPayloadSize = 0;
                  }
                  else
                  {
                     kal_uint32 curTimestamp = RTP_GetTimestamp( rtp );
                     kal_uint16 curSeq = RTP_GetSequenceNumber( rtp );

                     downlink->rxTimestamp = curTimestamp;
                     downlink->rxTimestampInit = KAL_TRUE;
                     downlink->rxCurrentDecodePtr = RTP_GetPayloadPtr( rtp );
                     downlink->rxCurrentPayloadSize = RTP_GetPayloadSize( rtp );
                     downlink->rxCurrentCodecType = RTP_GetCodecType( rtp );
                     downlink->rxLastTimestamp = downlink->rxTimestamp;

                     _trace_dl_packet_play_( downlink, rtp );
                     downlink->totalPlayedPackets ++;
                     if(downlink->rxLastPlayedSeqInit == KAL_TRUE)
                     {
                        kal_int16 seq_dif = curSeq - downlink->rxLastPlayedSeq;
///                        if(seq_dif < 0)
///                           RTP_ASSERT(0);
                        if(seq_dif > 0)
                           downlink->totalMissedPackets += seq_dif - 1;
                     }
                     downlink->rxLastPlayedSeqInit = KAL_TRUE;
                     downlink->rxLastPlayedSeq = curSeq;
#if VOIPEVL_SUPPORT
                     if(IS_VOIPEVL_LOGGING_DL())
                     {
                        INF_VORTP_DLPKT_PLAY_STRUCT event;
                        TICK t = Tick();
                        event.tDelay = (t>RTP_GetTick(rtp))? GetDurationTick(RTP_GetTick(rtp), Tick() ): 1;
                        event.uSessionID = (UINT8)((downlink->handle.session_id & 0x7f) | (RTP_GetMarker(rtp) << 7));
                        event.uCodecType = (UINT16)downlink->codec_handle.config.codec_type;
                        event.uRTPPayloadSize = (UINT16)rtp->payloadSize;
                        event.uRTPTimestamp = (UINT32)RTP_GetTimestamp( rtp );
                        event.uRTPSeqNo = (UINT16)RTP_GetSequenceNumber( rtp );
                        event.uJitterDepth = (UINT8)downlink->jitter_handle.currentDepth;
                        VORTP_TRACE_EVENT(event, INF_VORTP_DLPKT_PLAY);
                     }
#endif
                  }
               }
            }

            if( isContinued==KAL_TRUE )
            {
               if( downlink->rxCurrentPayloadSize==0 )
               {
                  if( PCMRB_GetDataCount( &downlink->vmi_handle->rb )<VMI_FRAME_SIZE )
                  {
#if VOIPEVL_SUPPORT
                     if(IS_VOIPEVL_LOGGING_DL())
                     {
                        INF_VORTP_DLPKT_PLAY_STRUCT event;
                        event.tDelay = 0;
                        event.uSessionID = (UINT8)(downlink->handle.session_id & 0x7f);
						if(rtp->theArray != NULL)
                           event.uSessionID |= (UINT8)(RTP_GetMarker(rtp) << 7);
                        event.uCodecType = (UINT16)downlink->codec_handle.config.codec_type;
                        event.uRTPPayloadSize = (UINT16)0;
                        event.uRTPTimestamp = (UINT32)downlink->rxTimestamp;
                        event.uRTPSeqNo = (UINT16)0;
                        event.uJitterDepth = (UINT8)downlink->jitter_handle.currentDepth;
                        VORTP_TRACE_EVENT(event, INF_VORTP_DLPKT_PLAY);
                     }
#endif
                     length = 0;
                     downlink->codec_handle.para->Decode( &downlink->codec_handle, NULL, &length, downlink->rxCurrentCodecType );

                     if(downlink->consecutiveNoData == 0)
                        downlink->consecutiveNoDataStartTime = downlink->rxTimestamp;
                     downlink->consecutiveNoData ++;

                     downlink->rxTimestamp += downlink->codec_handle.para->frameTime;
                     processed_samples += downlink->codec_handle.para->frameTime;
                  }
                  else
                  {
                     downlink->rxBadFrameDelayCount ++;
                     isContinued = KAL_FALSE;
                  }
               }
               else
               {
                  length = downlink->rxCurrentPayloadSize;
                  result = downlink->codec_handle.para->Decode( 
                     &downlink->codec_handle, 
                     downlink->rxCurrentDecodePtr, 
                     &length, 
                     downlink->rxCurrentCodecType );

                  if( result==KAL_TRUE )
                  {
                     downlink->rxTimestamp += downlink->codec_handle.para->frameTime;
                     processed_samples += downlink->codec_handle.para->frameTime;
                     downlink->rxCurrentDecodePtr += length;
                     downlink->rxCurrentPayloadSize -= length;
                  }
                  else
                  { // if decode error, drop the whole packet
                     downlink->rxCurrentPayloadSize = 0;
                     downlink->handle.callback( VORTP_EVENT_DL_ERROR, &downlink->handle, downlink->handle.host_data );
                  }
                  downlink->consecutiveNoData = 0;
               }
            }

            if( processed_samples >= VMI_FRAME_SIZE )
               isContinued = KAL_FALSE;
         }
         else
            isContinued = KAL_FALSE;
      } while( isContinued==KAL_TRUE );

      downlink = downlink->next;
   }

#if VMI_IN_TASK
   vmi_process();
#endif


   SlowIdleValue = (kal_int32) L1Audio_Enable_DSPSlowIdle();
   ASSERT( SlowIdleValue == 0 );

   while( (uplink != NULL) && (query_mmi_qos() < 7) )
   {
      VoRTP_current_session_id_l1aud = uplink->handle.session_id;
      do
      {
         isContinued = KAL_FALSE;
         if( RTPFifo_IsFull( &uplink->fifo_handle )==KAL_FALSE )
         {
            rtp = &uplink->fifo_handle.entry[uplink->fifo_handle.write&(RTP_FIFO_SIZE-1)];
            if( uplink->txAltPacket.theArray!=NULL )
            { // send alternated type packet
               RTP_DuplicatePacket( rtp, &uplink->txAltPacket );
               _trace_ul_packet_born_( uplink, rtp );
#if VOIPEVL_SUPPORT
              if(IS_VOIPEVL_LOGGING_UL())
              {
                 INF_VORTP_ULPKT_BORN_STRUCT event;
                 event.uSessionID = (UINT8)((uplink->handle.session_id & 0x7f) | (RTP_GetMarker(rtp) << 7));;
                 event.uCodecType = (UINT16)uplink->codec_handle.config.codec_type;
                 event.uRTPPayloadSize = (UINT16)rtp->payloadSize;
                 event.uRTPTimestamp = (UINT32)RTP_GetTimestamp( rtp );
                 event.uFIFOWriteIdx = (UINT8)uplink->fifo_handle.write;
                 event.uFIFOReadIdx = (UINT8)uplink->fifo_handle.read;
                 VORTP_TRACE_EVENT(event, INF_VORTP_ULPKT_BORN);
              }
#endif

               uplink->fifo_handle.write ++;
#if ALLOW_UL_WAIT
               if( uplink->wait==KAL_FALSE )
               {
                  uplink->handle.callback( VORTP_EVENT_UL_READY, &uplink->handle, uplink->handle.host_data );
                  uplink->wait = KAL_TRUE;
               }
#else
               uplink->handle.callback( VORTP_EVENT_UL_READY, &uplink->handle, uplink->handle.host_data );
#endif
               uplink->txFrameCount ++;
               free_ctrl_buffer( uplink->txAltPacket.theArray );
               uplink->txAltPacket.theArray = NULL;

               isContinued = KAL_TRUE;
            }
            else if( PCMRB_GetDataCount( &uplink->vmi_handle->rb )>=(int32)uplink->codec_handle.para->frameTime )
            {
               kal_uint8 *payload_ptr;
               kal_bool isAlternated;
               rtp_audio_codec_type codec_type;

               payload_ptr = RTP_GetPayloadPtr( rtp ) + uplink->txCurrentPayloadSize;
               result = uplink->codec_handle.para->Encode( 
                  &uplink->codec_handle, 
                  payload_ptr, 
                  &length, 
                  &codec_type,
                  KAL_FALSE );
               isAlternated = ( codec_type==uplink->codec_handle.config.codec_type )? KAL_FALSE: KAL_TRUE;

               /* DTX detector */
               if( result==KAL_FALSE )
               {
                  if( uplink->txCurrentPayloadSize==0 ) // first frame in the packet
                  {
                     RTP_SetMarker( rtp, uplink->txSilent );
                     RTP_SetTimestamp( rtp, uplink->handle.timestamp );
                     RTP_SetCodecType( rtp, codec_type );
                  }
                  if( isAlternated==KAL_FALSE || uplink->txCurrentPayloadSize==0 )
                     uplink->txCurrentPayloadSize += length;
                  else
                  {
                     kal_uint32 *buffer = (kal_uint32 *)get_ctrl_buffer( MIN_HEADER_SIZE+length+4 );
                     RTP_InitDataFrame( &uplink->txAltPacket, length, &buffer );
                     RTP_SetMarker( &uplink->txAltPacket, KAL_FALSE );
                     RTP_SetTimestamp( &uplink->txAltPacket, uplink->handle.timestamp );
                     RTP_SetCodecType( &uplink->txAltPacket, codec_type );
                     memcpy( RTP_GetPayloadPtr( &uplink->txAltPacket ), payload_ptr, length );
                     RTP_SetPayloadSize( &uplink->txAltPacket, length );
                     RTP_SetTick( &uplink->txAltPacket, Tick() );
                  }

                  /* look for the case to send packet immediately */
                  if( ( isAlternated==KAL_TRUE ) ||
                      ( uplink->codec_handle.config.codec_type==RTP_AUDIO_G729 && length==2 ) )
                     uplink->txFrameCount = uplink->codec_handle.maxTxFramesInPacket;
                  else
                     uplink->txFrameCount ++;
               }
               else
               { // no transmission
                  if( uplink->txSilent==KAL_FALSE )
                  {
                     if( uplink->txCurrentPayloadSize!=0 )
                        uplink->txFrameCount = uplink->codec_handle.maxTxFramesInPacket;
                  }
               }
               uplink->txSilent = result;
               uplink->handle.timestamp += uplink->codec_handle.para->frameTime;
               
               if( uplink->txFrameCount==uplink->codec_handle.maxTxFramesInPacket )
               {
                  RTP_SetPayloadSize( rtp, uplink->txCurrentPayloadSize );
                  RTP_SetTick( rtp, Tick() );
                  _trace_ul_packet_born_( uplink, rtp );
#if VOIPEVL_SUPPORT
                  if(IS_VOIPEVL_LOGGING_UL())
                  {
                     INF_VORTP_ULPKT_BORN_STRUCT event;
                     event.uSessionID = (UINT8)((uplink->handle.session_id & 0x7f) | (RTP_GetMarker(rtp) << 7));
                     event.uCodecType = (UINT16)uplink->codec_handle.config.codec_type;
                     event.uRTPPayloadSize = (UINT16)rtp->payloadSize;
                     event.uRTPTimestamp = (UINT32)RTP_GetTimestamp( rtp );
                     event.uFIFOWriteIdx = (UINT8)uplink->fifo_handle.write;
                     event.uFIFOReadIdx = (UINT8)uplink->fifo_handle.read;
                     VORTP_TRACE_EVENT(event, INF_VORTP_ULPKT_BORN);
                  }
#endif
                  uplink->fifo_handle.write ++;
#if ALLOW_UL_WAIT
                  if( uplink->wait==KAL_FALSE )
                  {
                     uplink->handle.callback( VORTP_EVENT_UL_READY, &uplink->handle, uplink->handle.host_data );
                     uplink->wait = KAL_TRUE;
                  }
#else
                  uplink->handle.callback( VORTP_EVENT_UL_READY, &uplink->handle, uplink->handle.host_data );
#endif
                  uplink->txCurrentPayloadSize = 0;
                  uplink->txFrameCount = 0;
               }
               isContinued = KAL_TRUE;
            }
         }
      } while( isContinued==KAL_TRUE );

      uplink = uplink->next;
   }

}

/*****************************************************************************
 * FUNCTION
 *  vortp_VMICallback
 * DESCRIPTION
 *  This function is the callback function of VMI running under L1Audio_HISR.
 * PARAMETERS
 *  host_data                 NOT USED
 *  event       [IN]      The VMI event recording the interrupt information.
 * RETURNS
 *  void
 *****************************************************************************
 */
static void vortp_VMICallback( void *host_data, VMI_EVENT event )
{
   (void)host_data;
   VoRTP_context.vmiEvents |= event;
   L1Audio_SetEvent( VoRTP_context.audId, (void *)0 );
}

/*****************************************************************************
 * FUNCTION
 *  _vortp_turn_on
 * DESCRIPTION
 *  This function allocates L1AUDIO resources.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************
 */
static void _vortp_turn_on( void )
{
   if( VoRTP_context.numStreams==0 )
   {
      VoRTP_context.audId = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( VoRTP_context.audId, _vortp_process );
      L1Audio_SetFlag( VoRTP_context.audId );
      vortp_update_tick(VMI_FRAME_SIZE);
      VoRTP_context.tidDumpInfo = rtpCreateTimer(PERIOD_DUMP_INFO, _vortp_dump_info, (void *)0);
#if defined(VORTP_AUTOREC_SUPPORT_) || defined(VORTP_UNIT_TEST)
      vortp_AutoRec_Start();
#endif
   }
}

/*****************************************************************************
 * FUNCTION
 *  _vortp_turn_off
 * DESCRIPTION
 *  This function frees L1AUDIO resources.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************
 */
static void _vortp_turn_off( void )
{
   if( VoRTP_context.numStreams==0 )
   {
#if defined(VORTP_AUTOREC_SUPPORT_) || defined(VORTP_UNIT_TEST)
      vortp_AutoRec_Stop();
#endif
      rtpDeleteTimer(VoRTP_context.tidDumpInfo);
      L1Audio_ClearFlag( VoRTP_context.audId );
      L1Audio_FreeAudioID( VoRTP_context.audId );
      VoRTP_context.audId = 0;
   }
}

/*****************************************************************************
 * FUNCTION
 *  _vortp_ul_is_exist
 * DESCRIPTION
 *  This function checks whether the request uplink channel handle is exist in the processing 
 *  queue.
 * PARAMETERS
 *  uplink          [IN]      The uplink channel handle
 * RETURNS
 *  kal_bool                  return KAL_TRUE when it exists in the processing queue.
 *****************************************************************************
 */
static kal_bool _vortp_ul_is_exist( VORTP_UL_INT *uplink )
{
   VORTP_UL_INT *uplink_t = VoRTP_context.uplinkHead;

   while( uplink_t!=uplink )
   {
      if( uplink_t==NULL )
         return KAL_FALSE;
      uplink_t = uplink_t->next;
   }
   return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  _vortp_ul_add
 * DESCRIPTION
 *  This function adds the requested uplink channel hanlde to processing queue.
 * PARAMETERS
 *  uplink          [IN]      The uplink channel handle
 * RETURNS
 *  kal_bool                  return KAL_TRUE when it exists in the processed queue.
 *****************************************************************************
 */
static void _vortp_ul_add( VORTP_UL_INT *uplink )
{
   uplink->next = VoRTP_context.uplinkHead;
   VoRTP_context.uplinkHead = uplink;
   VoRTP_context.numStreams ++;
}

/*****************************************************************************
 * FUNCTION
 *  _vortp_ul_remove
 * DESCRIPTION
 *  This function removes the requested uplink channel hanlde from processing queue.
 * PARAMETERS
 *  uplink          [IN]      The uplink channel handle
 * RETURNS
 *  kal_bool                  return KAL_FALSE when it does not exist in the processing queue.
 *****************************************************************************
 */
static kal_bool _vortp_ul_remove( VORTP_UL_INT *uplink )
{
   if( VoRTP_context.uplinkHead==uplink )
      VoRTP_context.uplinkHead = uplink->next;
   else
   {
      VORTP_UL_INT *my_prev = VoRTP_context.uplinkHead;

      while( my_prev->next!=uplink )
      {
         if( my_prev->next==NULL )
            return KAL_FALSE;
         my_prev = my_prev->next;
      }
      my_prev->next = uplink->next;
   }

   VoRTP_context.numStreams --;
   return KAL_TRUE;
}

static kal_bool _vortp_dl_is_exist( VORTP_DL_INT *downlink )
{
   VORTP_DL_INT *downlink_t = VoRTP_context.downlinkHead;

   while( downlink_t!=downlink )
   {
      if( downlink_t==NULL )
         return KAL_FALSE;
      downlink_t = downlink_t->next;
   }
   return KAL_TRUE;
}

static void _vortp_dl_add( VORTP_DL_INT *downlink )
{
   downlink->next = VoRTP_context.downlinkHead;
   VoRTP_context.downlinkHead = downlink;
   VoRTP_context.numStreams ++;
}

static kal_bool _vortp_dl_remove( VORTP_DL_INT *downlink )
{
   if( VoRTP_context.downlinkHead==downlink )
      VoRTP_context.downlinkHead = downlink->next;
   else
   {
      VORTP_DL_INT *my_prev = VoRTP_context.downlinkHead;

      while( my_prev->next!=downlink )
      {
         if( my_prev->next==NULL )
            return KAL_FALSE;
         my_prev = my_prev->next;
      }
      my_prev->next = downlink->next;
   }

   VoRTP_context.numStreams --;
   return KAL_TRUE;
}

#define VORTP_UPLINK_INTERFACE
/*****************************************************************************
 * FUNCTION
 *  vortp_ul_GetAvailableCodecs
 * DESCRIPTION
 *  This function returns the available codecs.
 *  If the alternated codec type is valid, it will return the available codecs when the alternated 
 *  codec is stopped.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 *  alt_codec_type  [IN]      The alternated codec type
 * RETURNS
 *  kal_bool                  return KAL_FALSE when it does not exist in the processing queue.
 *****************************************************************************
 */
static rtp_audio_codec_type vortp_ul_GetAvailableCodecs( VORTP_UL_HANDLE *handle, rtp_audio_codec_type *alt_codec_type )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;

   RTP_ASSERT( handle!=NULL );
   return RTPCodec_GetAvailableCodecs( &uplink->codec_handle, alt_codec_type );
}

/*****************************************************************************
 * FUNCTION
 *  vortp_ul_GetCodecCapability
 * DESCRIPTION
 *  This function returns the available codec capability of the requested codec type.
 *  If the alternated codec type is valid, it will return the available codecs when the alternated 
 *  codec is stopped.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 *  codec_type      [IN]      The requested codec type
 *  codec_cap       [OUT]     The codec capability
 *  alternated      [IN]      set KAL_TRUE to indicate the handle will be alternated
 * RETURNS
 *  VORTP_STATUS              return VORTP_STATUS_SUCCESS when the result capability is 
 *                            valid
 *****************************************************************************
 */
static VORTP_STATUS vortp_ul_GetCodecCapability( VORTP_UL_HANDLE *handle, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap, kal_bool alternated )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;

   RTP_ASSERT( handle!=NULL );
   if( RTPCodec_GetCodecCapability( &uplink->codec_handle, codec_type, codec_cap, alternated )==KAL_TRUE )
      return VORTP_STATUS_SUCCESS;
   else
      return VORTP_STATUS_FAIL;
}

/*****************************************************************************
 * FUNCTION
 *  vortp_ul_Config
 * DESCRIPTION
 *  This function configures the uplink channel with new codec type and capability.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 *  codec_type      [IN]      The requested codec type
 *  codec_cap       [IN]      The codec capability
 *  callback        [IN]      The callback entry
 *  host_data       [IN]      The callback parameter for host
 * RETURNS
 *  VORTP_STATUS              return VORTP_STATUS_SUCCESS when the configuration is 
 *                            success
 *****************************************************************************
 */
static VORTP_STATUS vortp_ul_Config( 
   VORTP_UL_HANDLE *handle, 
   rtp_audio_codec_type codec_type, 
   rtp_audio_codec_cap *codec_cap,
   VORTP_UL_CALLBACK callback, 
   void *host_data,
   kal_uint32 session_id )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;
   RTP_CODEC_HANDLE *codec_handle = &uplink->codec_handle;

   VORTP_TRACE( TRACE_FUNC, VORTP_UL_ENTER_CONFIG, codec_type, session_id );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_INITIALIZED );
   RTP_ASSERT( callback!=NULL );

   // register codec
   if( RTPCodec_Register( codec_handle, RTP_DIR_UL, codec_type, codec_cap )==KAL_FALSE )
      return VORTP_STATUS_NOT_SUPPORTED_CONFIG;

   // configure fifo
   uplink->fifo_handle.maxPayloadSize = codec_handle->maxFrameSize*codec_handle->maxTxFramesInPacket;

   handle->callback = callback;
   handle->host_data = host_data;
   handle->session_id = session_id;
   
   handle->state = VORTP_HANDLE_STATE_CONFIGURED;
   return VORTP_STATUS_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  vortp_ul_GetBufferSize
 * DESCRIPTION
 *  This function returns the minimum required buffer size of the uplink channel.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 * RETURNS
 *  kal_uint32                The minimum buffer size in unit of bytes
 *****************************************************************************
 */
static kal_uint32 vortp_ul_GetBufferSize( VORTP_UL_HANDLE *handle )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;
   kal_uint32 buffer_size;
   
   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_CONFIGURED );

   buffer_size = (uplink->codec_handle.para->sampleBufferSize*sizeof(int16)+3)&(~3); // for vmi_handle
   buffer_size += (RTPFifo_GetBufferSize( &uplink->fifo_handle )+3)&(~3);
//   buffer_size += (uplink->codec_handle.para->GetBufferSize( &uplink->codec_handle )+3)&(~3);

   return buffer_size;
}

/*****************************************************************************
 * FUNCTION
 *  vortp_ul_SetBuffer
 * DESCRIPTION
 *  This function setup the buffer for the uplink channel.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 *  buffer          [IN]      The pointer to the buffer
 *  buffer_size     [IN]      the buffer size
 * RETURNS
 *  VORTP_STATUS              return VORTP_STATUS_SUCCESS when the setup is success
 *****************************************************************************
 */
static VORTP_STATUS vortp_ul_SetBuffer( VORTP_UL_HANDLE *handle, kal_uint8 *buffer, kal_uint32 buffer_size )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;

   VORTP_TRACE( TRACE_FUNC, VORTP_UL_ENTER_SETBUFFER, buffer_size );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_CONFIGURED );

   if( buffer_size<handle->GetBufferSize( handle ) )
      return VORTP_STATUS_FAIL;

   uplink->buffer_pool = buffer;
   uplink->buffer_pool_size = buffer_size;

   handle->state = VORTP_HANDLE_STATE_READY;
   return VORTP_STATUS_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  vortp_ul_Close
 * DESCRIPTION
 *  This function closes the uplink channel.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 * RETURNS
 *  VORTP_STATUS              return VORTP_STATUS_SUCCESS
 *****************************************************************************
 */
static VORTP_STATUS vortp_ul_Close( VORTP_UL_HANDLE *handle )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;

   VORTP_TRACE( TRACE_FUNC, VORTP_UL_ENTER_CLOSE );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_INITIALIZED ||
      handle->state==VORTP_HANDLE_STATE_CONFIGURED || 
      handle->state==VORTP_HANDLE_STATE_READY );

   if( handle->state==VORTP_HANDLE_STATE_CONFIGURED || handle->state==VORTP_HANDLE_STATE_READY )
      RTPCodec_UnRegister( &uplink->codec_handle );

   handle->state = 0;

   if(uplink->txCNPacket.theArray != NULL)
      free_ctrl_buffer(uplink->txCNPacket.theArray);
   free_ctrl_buffer( handle );
   return VORTP_STATUS_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  vortp_ul_Close
 * DESCRIPTION
 *  This function starts the uplink channel.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 *  timestamp       [IN]      The RTP timestamp of the first sample
 * RETURNS
 *  VORTP_STATUS              return VORTP_STATUS_SUCCESS
 *****************************************************************************
 */
static VORTP_STATUS vortp_ul_Start( VORTP_UL_HANDLE *handle, kal_uint32 timestamp )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;
   kal_uint8 *buffer = uplink->buffer_pool;
   kal_uint32 buffer_size;
   kal_int32 total_buffer_size = uplink->buffer_pool_size;

   VORTP_TRACE( TRACE_FUNC, VORTP_UL_ENTER_START, handle->session_id, timestamp );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_READY );
   RTP_ASSERT( _vortp_ul_is_exist( uplink )==KAL_FALSE );

   kal_prompt_trace( MOD_L1SP, "vortp_ul_Start: %s, %d B\n", 
      uplink->codec_handle.name_str, 
      uplink->buffer_pool_size);

//   buffer_size = total_buffer_size;
//   RTP_ASSERT( uplink->codec_handle.para->Open( &uplink->codec_handle, buffer, &buffer_size )==KAL_TRUE );
//   buffer_size = (buffer_size+3)&(~3);
//   buffer += buffer_size;
//   total_buffer_size -= buffer_size;
   RTP_ASSERT( uplink->codec_handle.para->Open( &uplink->codec_handle )==KAL_TRUE );

   buffer_size = (uplink->codec_handle.para->sampleBufferSize*sizeof(int16)+3)&(~3);
   uplink->vmi_handle = VMI_GetHandle( VMI_DIR_UL, buffer, buffer_size );
   RTP_ASSERT( uplink->vmi_handle!=NULL );
   buffer += buffer_size;
   total_buffer_size -= buffer_size;

   buffer_size = total_buffer_size;
   RTP_ASSERT( RTPFifo_Open( &uplink->fifo_handle, buffer, &buffer_size )==KAL_TRUE );
   buffer_size = (buffer_size+3)&(~3);
   buffer += buffer_size;
   total_buffer_size -= buffer_size;

   uplink->codec_handle.rb = &uplink->vmi_handle->rb;

   RTP_ASSERT( total_buffer_size>=0 );

   uplink->txSilent = KAL_TRUE;
   uplink->txFrameCount = 0;
   uplink->txCurrentPayloadSize = 0;

   handle->timestamp = timestamp;
   handle->state = VORTP_HANDLE_STATE_STREAMING;

   _vortp_turn_on();
   _vortp_ul_add( uplink ); // add a streaming handle to process list

#ifdef VORTP_UNIT_TEST
   if( VoRTP_context.numStreams == 1 )
   {
      if( autoSpeakEnable )
         vortp_AutoSpeak_Start();
   }
#endif

#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_UL())
   {
      INF_VORTP_ULSES_START_STRUCT event;
      event.uSessionID = (UINT8)uplink->handle.session_id;
      event.uCodecType = (UINT16)uplink->codec_handle.config.codec_type;
      event.uCodecCapLength = (UINT16)uplink->codec_handle.config.codec_cap_length;
      VORTP_SES_TRACE_EVENT(event, INF_VORTP_ULSES_START, &uplink->codec_handle.config.codec_cap);
   }
#endif

   uplink->vmi_handle->mix = ( uplink->mix_enable==KAL_TRUE )? 1: 0;
   uplink->vmi_handle->session_id = handle->session_id;

   uplink->vmi_handle->callback = vortp_VMICallback;

   uplink->vmi_handle->host_data = (void *)uplink;
   RTP_ASSERT( VMI_Start( uplink->vmi_handle )==VMI_STATUS_SUCCESS );

   return VORTP_STATUS_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  vortp_ul_Stop
 * DESCRIPTION
 *  This function stops the uplink channel.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 * RETURNS
 *  VORTP_STATUS              return VORTP_STATUS_SUCCESS
 *****************************************************************************
 */
static VORTP_STATUS vortp_ul_Stop( VORTP_UL_HANDLE *handle )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;

   VORTP_TRACE( TRACE_FUNC, VORTP_UL_ENTER_STOP, handle->session_id );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_STREAMING );
   RTP_ASSERT( _vortp_ul_is_exist( uplink )==KAL_TRUE );

   RTP_ASSERT( VMI_FreeHandle( uplink->vmi_handle )==VMI_STATUS_SUCCESS );

   RTP_ASSERT( _vortp_ul_remove( uplink )==KAL_TRUE ); // remove a streaming handle from process list
   _vortp_turn_off();

   handle->state = VORTP_HANDLE_STATE_READY;

   RTP_ASSERT( RTPFifo_Close( &uplink->fifo_handle )==KAL_TRUE );

   if( uplink->txAltPacket.theArray!=NULL )
   {
      free_ctrl_buffer( uplink->txAltPacket.theArray );
      uplink->txAltPacket.theArray = NULL;
   }

   { /* send CN packet to the end */
      kal_uint32 length = 10;
      rtp_audio_codec_type codec_type;
      kal_uint32 *buffer = (kal_uint32 *)get_ctrl_buffer( MIN_HEADER_SIZE+length );
      RTP_DataFrame *rtp = &uplink->txCNPacket;
      kal_bool isSilent;

      RTP_InitDataFrame( rtp, length, &buffer );
      isSilent = uplink->codec_handle.para->Encode(&uplink->codec_handle, rtp->theArray+MIN_HEADER_SIZE, &length, &codec_type, KAL_TRUE);
      if(isSilent != KAL_FALSE)
      {
         free_ctrl_buffer(rtp->theArray);
         rtp->theArray = NULL;
      }
      else
      {
         RTP_SetMarker( rtp, KAL_FALSE );
         RTP_SetTimestamp( rtp, uplink->handle.timestamp );
         RTP_SetCodecType( rtp, codec_type );
         RTP_SetPayloadSize( rtp, length );
         RTP_SetTick( rtp, Tick() );
         _trace_ul_packet_born_( uplink, rtp );
#if VOIPEVL_SUPPORT
         if(IS_VOIPEVL_LOGGING_UL())
         {
            INF_VORTP_ULPKT_BORN_STRUCT event;
            event.uSessionID = (UINT8)((uplink->handle.session_id & 0x7f) | (RTP_GetMarker(rtp) << 7));
            event.uCodecType = (UINT16)uplink->codec_handle.config.codec_type;
            event.uRTPPayloadSize = (UINT16)rtp->payloadSize;
            event.uRTPTimestamp = (UINT32)RTP_GetTimestamp( rtp );
            event.uFIFOWriteIdx = 0;
            event.uFIFOReadIdx = 0;
            VORTP_TRACE_EVENT(event, INF_VORTP_ULPKT_BORN);
         }
#endif
#if ALLOW_UL_WAIT
         if( uplink->wait==KAL_FALSE )
         {
            uplink->handle.callback( VORTP_EVENT_UL_READY, &uplink->handle, uplink->handle.host_data );
            uplink->wait = KAL_TRUE;
         }
#else
         uplink->handle.callback( VORTP_EVENT_UL_READY, &uplink->handle, uplink->handle.host_data );
#endif
      }
   }

#ifdef VORTP_UNIT_TEST
   if( VoRTP_context.numStreams == 0 )
   {
      vortp_AutoSpeak_Stop();
   }
#endif

   RTP_ASSERT( uplink->codec_handle.para->Close( &uplink->codec_handle )==KAL_TRUE );

   return VORTP_STATUS_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  vortp_ul_SetMix
 * DESCRIPTION
 *  This function sets the mixing function of the uplink channel.
 *  The mixing function is used to conferencing other channel and is enabled by default.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 * RETURNS
 *  VORTP_STATUS              return VORTP_STATUS_SUCCESS
 *****************************************************************************
 */
static VORTP_STATUS vortp_ul_SetMix( VORTP_UL_HANDLE *handle, kal_bool enable )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;

   VORTP_TRACE( TRACE_FUNC, VORTP_UL_ENTER_SETMIX, enable );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_CONFIGURED || 
      handle->state==VORTP_HANDLE_STATE_READY || 
      handle->state==VORTP_HANDLE_STATE_STREAMING );

   uplink->mix_enable = enable;
   if( handle->state==VORTP_HANDLE_STATE_STREAMING )
      uplink->vmi_handle->mix = ( enable==KAL_TRUE )? 1: 0;

   return VORTP_STATUS_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  vortp_ul_GetPacketCount
 * DESCRIPTION
 *  This function returns the number of born packets.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 * RETURNS
 *  kal_int32                 The number of born packets
 *****************************************************************************
 */
static kal_int32 vortp_ul_GetPacketCount( VORTP_UL_HANDLE *handle )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;
   kal_int32 packet_count;
   
   RTP_ASSERT( handle!=NULL );
   if(handle->state == VORTP_HANDLE_STATE_READY)
   {
      if(uplink->txCNPacket.theArray != NULL)
         return 1;
      else
         return 0;
   }

   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_STREAMING );

   packet_count = uplink->fifo_handle.write - uplink->fifo_handle.read;
   RTP_ASSERT( (packet_count>=0) && (packet_count<=RTP_FIFO_SIZE) );

   return packet_count;
}

/*****************************************************************************
 * FUNCTION
 *  vortp_ul_GetPacketCount
 * DESCRIPTION
 *  This function gets a born RTP packet to host's buffer.
 * PARAMETERS
 *  handle          [IN]      The uplink channel handle
 *  buffer          [OUT]     The host's buffer
 *  buffer_size     [IN]      The size of the host's buffer
 *  codec_type      [OUT]     The codec type of the RTP packet
 * RETURNS
 *  kal_uint32                The size of the born packet
 *****************************************************************************
 */
static kal_uint32 vortp_ul_GetPacket( VORTP_UL_HANDLE *handle, kal_uint8 *buffer, kal_uint32 buffer_size, rtp_audio_codec_type *codec_type )
{
   VORTP_UL_INT *uplink = (VORTP_UL_INT *)handle;
   RTP_DataFrame *rtp;
   kal_bool get_cn = KAL_FALSE;
   
   RTP_ASSERT( handle!=NULL );
   if(uplink->txCNPacket.theArray != NULL)
   {
      RTP_ASSERT(handle->state == VORTP_HANDLE_STATE_READY);
      get_cn = KAL_TRUE;
      rtp = &uplink->txCNPacket;
   }
   else
   {
      RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_STREAMING );
      if( RTPFifo_IsEmpty( &uplink->fifo_handle )==KAL_TRUE )
#if ALLOW_UL_WAIT
         return 0;
#else
         RTP_ASSERT(0);
#endif
      rtp = &(uplink->fifo_handle.entry[uplink->fifo_handle.read&(RTP_FIFO_SIZE-1)]);
   }

   RTP_ASSERT( (int)buffer_size>=rtp->packetSize );

   *codec_type = RTP_GetCodecType( rtp );
   memcpy( buffer, rtp->theArray, rtp->packetSize );

   _trace_ul_packet_sent_( uplink, rtp );
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_UL())
   {
      INF_VORTP_ULPKT_SENT_STRUCT event;
      event.tDelay = GetDurationTick( RTP_GetTick( rtp ), Tick() );
      event.uSessionID = (UINT8)((uplink->handle.session_id & 0x7f) | (RTP_GetMarker(rtp) << 7));
      event.uCodecType = (UINT16)uplink->codec_handle.config.codec_type;
      event.uRTPPayloadSize = (UINT16)rtp->payloadSize;
      event.uRTPTimestamp = (UINT32)RTP_GetTimestamp( rtp );
      event.uFIFOWriteIdx = (UINT8)uplink->fifo_handle.write;
      event.uFIFOReadIdx = (UINT8)uplink->fifo_handle.read;
      VORTP_TRACE_EVENT(event, INF_VORTP_ULPKT_SENT);
   }
#endif

   if(get_cn == KAL_FALSE)
   {
      uplink->fifo_handle.read ++;
#if ALLOW_UL_WAIT
      if( RTPFifo_IsEmpty( &uplink->fifo_handle )==KAL_TRUE )
         uplink->wait = KAL_FALSE;
#endif
   }
   else
   {
#if ALLOW_UL_WAIT
      uplink->wait = KAL_FALSE;
#endif
   }

   if(get_cn != KAL_FALSE)
   {
      free_ctrl_buffer(uplink->txCNPacket.theArray);
      uplink->txCNPacket.theArray = NULL;
   }
   return (kal_uint32)rtp->packetSize;
}

#define VORTP_DOWNLINK_INTERFACE
static rtp_audio_codec_type vortp_dl_GetAvailableCodecs( VORTP_DL_HANDLE *handle, rtp_audio_codec_type *alt_codec_type )
{
   VORTP_DL_INT *downlink = (VORTP_DL_INT *)handle;

   RTP_ASSERT( handle!=NULL );
   return RTPCodec_GetAvailableCodecs( &downlink->codec_handle, alt_codec_type );
}

static VORTP_STATUS vortp_dl_GetCodecCapability( VORTP_DL_HANDLE *handle, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap, kal_bool alternated )
{
   VORTP_DL_INT *downlink = (VORTP_DL_INT *)handle;

   RTP_ASSERT( handle!=NULL );
   if( RTPCodec_GetCodecCapability( &downlink->codec_handle, codec_type, codec_cap, alternated )==KAL_TRUE )
      return VORTP_STATUS_SUCCESS;
   else
      return VORTP_STATUS_FAIL;
}

static VORTP_STATUS vortp_dl_Config( 
   VORTP_DL_HANDLE *handle, 
   rtp_audio_codec_type codec_type, 
   rtp_audio_codec_cap *codec_cap,
   VORTP_DL_CALLBACK callback, 
   void *host_data,
   kal_uint32 session_id )
{
   VORTP_DL_INT *downlink = (VORTP_DL_INT *)handle;
   RTP_CODEC_HANDLE *codec_handle = &downlink->codec_handle;

   VORTP_TRACE( TRACE_FUNC, VORTP_DL_ENTER_CONFIG, codec_type, session_id );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_INITIALIZED );
   RTP_ASSERT( callback!=NULL );

   // register codec
   if( RTPCodec_Register( codec_handle, RTP_DIR_DL, codec_type, codec_cap )==KAL_FALSE )
      return VORTP_STATUS_NOT_SUPPORTED_CONFIG;

   // configure jitter buffer
   downlink->jitter_handle.maxPayloadSize = codec_handle->maxFrameSize*codec_handle->maxTxFramesInPacket;
   if( downlink->jitter_handle.maxPayloadSize < DEFAULT_DL_PAYLOAD_SIZE )
      downlink->jitter_handle.maxPayloadSize = DEFAULT_DL_PAYLOAD_SIZE;
   downlink->jitter_handle.minJitterTime = Msec2Time(VoIP_MIN_JITTER_TIME);
   if( ( codec_type==RTP_AUDIO_G729 || codec_type==RTP_AUDIO_G7231) && 
        ( downlink->jitter_handle.minJitterTime<Msec2Time(60) ) )
      downlink->jitter_handle.minJitterTime = Msec2Time(60);
   downlink->jitter_handle.maxJitterTime = Msec2Time(VoIP_MAX_JITTER_TIME);
   downlink->jitter_handle.maxConsecutiveMarkerBits = 10;
   //downlink->jitter_handle.minPacketTime = ( Msec2Time(20)<codec_handle->para->frameTime )? Msec2Time(20): codec_handle->para->frameTime;
   downlink->jitter_handle.minPacketTime = Msec2Time(20);
   downlink->jitter_handle.maxSIDPayloadSize = RTPCodec_QueryMaxSIDPayloadSize(codec_handle);
   
   handle->callback = callback;
   handle->host_data = host_data;
   handle->session_id = session_id;

   handle->state = VORTP_HANDLE_STATE_CONFIGURED;
   return VORTP_STATUS_SUCCESS;
}

static kal_uint32 vortp_dl_GetBufferSize( VORTP_DL_HANDLE *handle )
{
   VORTP_DL_INT *downlink = (VORTP_DL_INT *)handle;
   kal_uint32 buffer_size;
   
   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_CONFIGURED );

   buffer_size = (downlink->codec_handle.para->sampleBufferSize*sizeof(int16)+3)&(~3); // for vmi_handle
   buffer_size += (RTPJitter_GetBufferSize( &downlink->jitter_handle )+3)&(~3);
//   buffer_size += (downlink->codec_handle.para->GetBufferSize( &downlink->codec_handle )+3)&(~3);

   return buffer_size;
}

static VORTP_STATUS vortp_dl_SetBuffer( VORTP_DL_HANDLE *handle, kal_uint8 *buffer, kal_uint32 buffer_size )
{
   VORTP_DL_INT *downlink = (VORTP_DL_INT *)handle;

   VORTP_TRACE( TRACE_FUNC, VORTP_DL_ENTER_SETBUFFER, buffer_size );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_CONFIGURED );

   if( buffer_size<handle->GetBufferSize( handle ) )
      return VORTP_STATUS_FAIL;

   downlink->buffer_pool = buffer;
   downlink->buffer_pool_size = buffer_size;

   handle->state = VORTP_HANDLE_STATE_READY;
   return VORTP_STATUS_SUCCESS;
}

static VORTP_STATUS vortp_dl_Close( VORTP_DL_HANDLE *handle )
{
   VORTP_DL_INT *downlink = (VORTP_DL_INT *)handle;

   VORTP_TRACE( TRACE_FUNC, VORTP_DL_ENTER_CLOSE );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_INITIALIZED ||
      handle->state==VORTP_HANDLE_STATE_CONFIGURED || 
      handle->state==VORTP_HANDLE_STATE_READY );

   if( handle->state==VORTP_HANDLE_STATE_CONFIGURED || handle->state==VORTP_HANDLE_STATE_READY )
      RTPCodec_UnRegister( &downlink->codec_handle );

   handle->state = 0;
   free_ctrl_buffer( handle );
   return VORTP_STATUS_SUCCESS;
}

static VORTP_STATUS vortp_dl_Start( VORTP_DL_HANDLE *handle )
{
   VORTP_DL_INT *downlink = (VORTP_DL_INT *)handle;
   kal_uint8 *buffer = downlink->buffer_pool;
   kal_uint32 buffer_size;
   kal_int32 total_buffer_size = downlink->buffer_pool_size;

   VORTP_TRACE( TRACE_FUNC, VORTP_DL_ENTER_START, handle->session_id );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_READY );
   RTP_ASSERT( _vortp_dl_is_exist( downlink )==KAL_FALSE );

   kal_prompt_trace( MOD_L1SP, "vortp_dl_Start: %s, %d B\n", 
      downlink->codec_handle.name_str, 
      downlink->buffer_pool_size);

//   buffer_size = total_buffer_size;
//   RTP_ASSERT( downlink->codec_handle.para->Open( &downlink->codec_handle, buffer, &buffer_size )==KAL_TRUE );
//   buffer_size = (buffer_size+3)&(~3);
//   buffer += buffer_size;
//   total_buffer_size -= buffer_size;
   RTP_ASSERT( downlink->codec_handle.para->Open( &downlink->codec_handle )==KAL_TRUE );

   buffer_size = (downlink->codec_handle.para->sampleBufferSize*sizeof(int16)+3)&(~3);
   downlink->vmi_handle = VMI_GetHandle( VMI_DIR_DL, buffer, buffer_size );
   RTP_ASSERT( downlink->vmi_handle!=NULL );
   buffer += buffer_size;
   total_buffer_size -= buffer_size;

   buffer_size = total_buffer_size;
   RTP_ASSERT( RTPJitter_Open( &downlink->jitter_handle, buffer, &buffer_size, handle->session_id )==KAL_TRUE );
   buffer_size = (buffer_size+3)&(~3);
   buffer += buffer_size;
   total_buffer_size -= buffer_size;

   downlink->codec_handle.rb = &downlink->vmi_handle->rb;

   RTP_ASSERT( total_buffer_size>=0 );

   handle->state = VORTP_HANDLE_STATE_STREAMING;

   _vortp_turn_on();
   _vortp_dl_add( downlink ); // add a streaming handle to process list

#ifdef VORTP_UNIT_TEST
   if( VoRTP_context.numStreams == 1 )
   {
      if( autoSpeakEnable )
         vortp_AutoSpeak_Start();
   }
#endif

#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_DL())
   {
      INF_VORTP_DLSES_START_STRUCT event;
      event.uSessionID = (UINT8)downlink->handle.session_id;
      event.uCodecType = (UINT16)downlink->codec_handle.config.codec_type;
      event.uCodecCapLength = (UINT16)downlink->codec_handle.config.codec_cap_length;
      VORTP_SES_TRACE_EVENT(event, INF_VORTP_DLSES_START, &downlink->codec_handle.config.codec_cap);
   }
#endif

   downlink->vmi_handle->mix = 1;
   downlink->vmi_handle->session_id = handle->session_id;

   downlink->vmi_handle->callback = vortp_VMICallback;

   downlink->vmi_handle->host_data = (void *)downlink;
   RTP_ASSERT( VMI_Start( downlink->vmi_handle )==VMI_STATUS_SUCCESS );

   return VORTP_STATUS_SUCCESS;
}

static VORTP_STATUS vortp_dl_Stop( VORTP_DL_HANDLE *handle )
{
   VORTP_DL_INT *downlink = (VORTP_DL_INT *)handle;

   VORTP_TRACE( TRACE_FUNC, VORTP_DL_ENTER_STOP, handle->session_id );

   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_STREAMING );
   RTP_ASSERT( _vortp_dl_is_exist( downlink )==KAL_TRUE );

   RTP_ASSERT( VMI_FreeHandle( downlink->vmi_handle )==VMI_STATUS_SUCCESS );

   RTP_ASSERT( _vortp_dl_remove( downlink )==KAL_TRUE ); // remove a streaming handle from process list
   _vortp_turn_off();

   handle->state = VORTP_HANDLE_STATE_READY;

#ifdef VORTP_UNIT_TEST
  if( VoRTP_context.numStreams == 0 )
  {
      vortp_AutoSpeak_Stop();
   }
#endif
   
   RTP_ASSERT( RTPJitter_Close( &downlink->jitter_handle ) );
   RTP_ASSERT( downlink->codec_handle.para->Close( &downlink->codec_handle )==KAL_TRUE );
   
   return VORTP_STATUS_SUCCESS;
}

static VORTP_STATUS vortp_dl_PutPacket( VORTP_DL_HANDLE *handle, kal_uint8 *buffer, kal_uint32 buffer_size, rtp_audio_codec_type codec_type )
{
   VORTP_DL_INT *downlink = (VORTP_DL_INT *)handle;
   RTP_DataFrame rtp;
   kal_bool put_result;
   
   RTP_ASSERT( handle!=NULL );
   RTP_ASSERT( handle->state==VORTP_HANDLE_STATE_STREAMING );

   switch( RTP_ReceiveData( &rtp, buffer, buffer_size ) )
   {
      case e_ProcessPacket:
         RTP_SetTick( &rtp, Tick() );
         put_result = RTPJitter_PutData( &downlink->jitter_handle, &rtp, codec_type );
         downlink->totalArrivedPackets ++;
         _trace_dl_packet_arrival_( downlink, &rtp );
#if VOIPEVL_SUPPORT
         if(IS_VOIPEVL_LOGGING_DL())
         {
            INF_VORTP_DLPKT_ARRIVE_STRUCT event;
            event.uSessionID = (UINT8)((downlink->handle.session_id & 0x7f) | (RTP_GetMarker(&rtp) << 7));
            event.uCodecType = (UINT16)downlink->codec_handle.config.codec_type;
            event.uRTPPayloadSize = (UINT16)rtp.payloadSize;
            event.uRTPTimestamp = (UINT32)RTP_GetTimestamp( &rtp );
            event.uRTPSeqNo = (UINT16)RTP_GetSequenceNumber( &rtp );
            event.uJitterDepth = (UINT8)downlink->jitter_handle.currentDepth;
            VORTP_TRACE_EVENT(event, INF_VORTP_DLPKT_ARRIVE);
         }
#endif
         if( put_result == KAL_TRUE )
            break;
      case e_IgnorePacket:
         return VORTP_STATUS_FAIL;
      default:
         RTP_ASSERT(0);
         break;
   }

   return VORTP_STATUS_SUCCESS;
}

void VoRTP_Init( void )
{
   VoRTP_context.audId = 0;
   VoRTP_context.uplinkHead = NULL;
   VoRTP_context.downlinkHead = NULL;
   VoRTP_context.vmiEvents = VMI_EVENT_NONE;
   VoRTP_context.toneCallback = NULL;
   VoRTP_context.toneData = NULL;
   VoRTP_context.numStreams = 0;
   RTPCodec_Init();
   rtpTimerLock = kal_create_mutex("rtpTimerLock");
}

VORTP_UL_HANDLE *VoRTP_OpenULChannel( void )
{
   VORTP_UL_INT *uplink;

   VORTP_TRACE( TRACE_FUNC, VORTP_UL_ENTER_OPEN );

   uplink = (VORTP_UL_INT *)get_ctrl_buffer( sizeof(VORTP_UL_INT) );
   if( uplink!=NULL )
   {
      VORTP_UL_HANDLE *handle = &uplink->handle;

      memset( uplink, 0, sizeof(VORTP_UL_INT) );
      handle->GetAvailableCodecs = vortp_ul_GetAvailableCodecs;
      handle->GetCodecCapability = vortp_ul_GetCodecCapability;
      handle->Config = vortp_ul_Config;
      handle->GetBufferSize = vortp_ul_GetBufferSize;
      handle->SetBuffer = vortp_ul_SetBuffer;
      handle->Close = vortp_ul_Close;
      handle->Start = vortp_ul_Start;
      handle->Stop = vortp_ul_Stop;
      handle->SetMix = vortp_ul_SetMix;
      handle->GetPacketCount = vortp_ul_GetPacketCount;
      handle->GetPacket = vortp_ul_GetPacket;
      handle->state = VORTP_HANDLE_STATE_INITIALIZED;

      uplink->mix_enable = KAL_TRUE;
#if ALLOW_UL_WAIT
      uplink->wait = KAL_FALSE;
#endif
   }

   return (VORTP_UL_HANDLE *)uplink;
}

VORTP_DL_HANDLE *VoRTP_OpenDLChannel( void )
{
   VORTP_DL_INT *downlink;
   
   VORTP_TRACE( TRACE_FUNC, VORTP_DL_ENTER_OPEN );

   downlink = (VORTP_DL_INT *)get_ctrl_buffer( sizeof(VORTP_DL_INT) );
   if( downlink!=NULL )
   {
      VORTP_DL_HANDLE *handle = &downlink->handle;

      memset( downlink, 0, sizeof(VORTP_DL_INT) );
      handle->GetAvailableCodecs = vortp_dl_GetAvailableCodecs;
      handle->GetCodecCapability = vortp_dl_GetCodecCapability;
      handle->Config = vortp_dl_Config;
      handle->GetBufferSize = vortp_dl_GetBufferSize;
      handle->SetBuffer = vortp_dl_SetBuffer;
      handle->Close = vortp_dl_Close;
      handle->Start = vortp_dl_Start;
      handle->Stop = vortp_dl_Stop;
      handle->PutPacket = vortp_dl_PutPacket;
      handle->state = VORTP_HANDLE_STATE_INITIALIZED;
   }

   return (VORTP_DL_HANDLE *)downlink;
}

VORTP_STATUS VoRTP_StartInbandTone( kal_uint32 freq1, kal_uint32 freq2, kal_int32 amp_dbm0, kal_uint32 duration_msec, VORTP_TONE_CALLBACK callback, void *host_data  )
{
   VMI_TONE_PARA tone_para;
   
   VORTP_TRACE( TRACE_FUNC, VORTP_ENTER_STARTTONE, freq1, freq2, amp_dbm0, duration_msec );

//   RTP_ASSERT( callback!=NULL );
   RTP_ASSERT( VoRTP_context.uplinkHead!=NULL ); // There shall be at least one uplink channel in streaming

   tone_para.uplink_en = 1;
   tone_para.downlink_en = 0;
   tone_para.uplink_mix = 0;
   tone_para.downlink_mix = 0;
   tone_para.unused = 0;
   tone_para.freq1 = freq1;
   tone_para.freq2 = freq2;
   tone_para.gain = 32767;
   if( amp_dbm0<0 )
      tone_para.gain >>= (-amp_dbm0/3);
   tone_para.duration = duration_msec;
   tone_para.callback = vortp_VMICallback;
   tone_para.host_data = 0;
   if( VMI_ToneOn( &tone_para )!=VMI_STATUS_SUCCESS )
      return VORTP_STATUS_FAIL;

   VoRTP_context.toneCallback = callback;
   VoRTP_context.toneData = host_data;

   return VORTP_STATUS_SUCCESS;
}

VORTP_STATUS VoRTP_StopInbandTone( void )
{ 
   VORTP_TRACE( TRACE_FUNC, VORTP_ENTER_STOPTONE );

   if( VMI_ToneOff()!=VMI_STATUS_SUCCESS )
      return VORTP_STATUS_FAIL;

   VoRTP_context.toneCallback = NULL;
   VoRTP_context.toneData = NULL;

   return VORTP_STATUS_SUCCESS;
}

void network_event_callback(EVINF_INFO_ID id, kal_uint32 parm)
{
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_NW())
   {
      INF_NW_EV_STRUCT event;
      event.uParm = (UINT32)parm;
      VORTP_TRACE_EVENT(event, id);
   }
#endif

}

#if VOIPEVL_SUPPORT
void VoRTP_SetEventLogging( kal_bool enable )
{
   VoRTP_isEventLogging = enable;
   if(enable)
   {
      INF_CONFIG_CMD_STRUCT event;
      event.uTicksPerSecond = NUM_TICK_PER_SECOND;
      event.uTicksWrapped = WRAPPED_TICK;
      VORTP_TRACE_EVENT(event, INF_CONFIG_CMD);
   }
}
#endif

#if defined(VORTP_AUTOREC_SUPPORT_) || defined(VORTP_UNIT_TEST)
static void vortp_AutoRecCallbackInMed( kal_uint32 arg1, void *arg2 )
{
   kal_uint16 *read_ptr;
   kal_int32 read_len;
   kal_uint32 count;

   (void)arg1;
   (void)arg2;
   
   read_len = mediaGetDataCount();
   while( read_len > 0 )
   {
      Media_GetReadBuffer( &read_ptr, &count );
#if !defined(SIM_ON_VC)
      FSAL_Write( &fAutoRec, (kal_uint8 *)read_ptr, count << 1 );
#else
      fwrite((void *)read_ptr, 1, count << 1, fAutoRec);
#endif
      Media_ReadDataDone(count);
      read_len -= count;
   }
}

static void vortp_AutoRecCallback( Media_Event event )
{
   ASSERT( event == MEDIA_DATA_NOTIFICATION );
   L1Audio_InProcCall2( vortp_AutoRecCallbackInMed, 0, 0 );
}

static void vortp_AutoRec_Start()
{
   kal_uint32 buf_len = AUTOREC_MEDIA_BUF_SIZE + 1024;
#if !defined(SIM_ON_VC)
   kal_int16 drv_letter;
   kal_wchar filename[40];
   t_rtc rtc_time;
   int format = 0;

   RTC_GetTime(&rtc_time);
   format = GET_VOIPEVL_FORMAT();
   if(format == 1)
      autoRecordingFormat = MEDIA_FORMAT_WAV_DVI_ADPCM;
   else if(format == 2)
      autoRecordingFormat = MEDIA_FORMAT_VOIPEVL;
   else
      return;

   bWriteToRemDrv = IS_VOIPEVL_IN_RMV_DRV()? KAL_TRUE: KAL_FALSE;
   
   if(bWriteToRemDrv)
      drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );
   else
      drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
   if( autoRecordingFormat==MEDIA_FORMAT_WAV_DVI_ADPCM )
   {
      kal_wsprintf( filename, "%c:\\%d_%02d%02d%02d%02da.wav", drv_letter, uIncNumber++, 
         rtc_time.rtc_mon,
         rtc_time.rtc_day,
         rtc_time.rtc_hour,
         rtc_time.rtc_min );
   }
   else if( autoRecordingFormat==MEDIA_FORMAT_VOIPEVL )
   {
      kal_wsprintf( filename, "%c:\\%d_%02d%02d%02d%02da.evl", drv_letter, uIncNumber++, 
         rtc_time.rtc_mon,
         rtc_time.rtc_day,
         rtc_time.rtc_hour,
         rtc_time.rtc_min );
   }
   else
      return;

   if( FSAL_OK != FSAL_Open( &fAutoRec, filename, FSAL_WRITE ) )
#else
   char filename[40];
   sprintf( filename, "voip_autorec_%d.evl", uIncNumber++ );
   if( ( fAutoRec = fopen(filename, "wb") ) == 0 )
#endif
   {
      kal_prompt_trace(MOD_L1SP, "autorec: source file can't open\n");
      return;
   }

   pAutoRecBuffer = med_alloc_ext_mem(buf_len);
   if( pAutoRecBuffer==NULL )
      return;

   buf_len -= 1024;
#if !defined(SIM_ON_VC)
   FSAL_SetBuffer( &fAutoRec, 1024, (kal_uint8 *)&pAutoRecBuffer[buf_len] );
#endif

   buf_len -= AUTOREC_MEDIA_BUF_SIZE;
   Media_SetBuffer( &pAutoRecBuffer[buf_len], AUTOREC_MEDIA_BUF_SIZE >> 1 );
   Media_SetRBThreshold(1024);
   if( MEDIA_SUCCESS != Media_Record( autoRecordingFormat, vortp_AutoRecCallback, (void *)1 ) )
   {
#if !defined(SIM_ON_VC)
      FSAL_Close( &fAutoRec );
#else
      fclose( fAutoRec );
#endif
      med_free_ext_mem( (void **)&pAutoRecBuffer );
   }

   kal_prompt_trace(MOD_L1SP, "VoIP auto recording, path:%s\n", filename);
}

static void vortp_AutoRec_Stop()
{
   if( pAutoRecBuffer==NULL )
      return;

   Media_Stop();
   Media_SetRBThreshold(MEDIA_RB_DEFAULT_THRESHOLD);

   // Flush all data
   vortp_AutoRecCallback( MEDIA_DATA_NOTIFICATION );
#if !defined(SIM_ON_VC)
   do{ kal_sleep_task(10); }while(mediaGetDataCount() != 0);

   if( autoRecordingFormat == MEDIA_FORMAT_WAV_DVI_ADPCM )
   {
      // Write file header
      kal_uint8 *header_p;
      kal_uint32 header_len;

      Media_GetFileHeader( &header_p, &header_len );
      FSAL_Seek( &fAutoRec, 0 );
      FSAL_Write( &fAutoRec, header_p, header_len );
   }
#endif
   
#if !defined(SIM_ON_VC)
   ASSERT( FSAL_OK == FSAL_Close( &fAutoRec ) );
#else
   fclose( fAutoRec );
#endif
   med_free_ext_mem( (void **)&pAutoRecBuffer );
   kal_prompt_trace(MOD_L1SP, "VoIP auto recording stop\n");
}

#if defined(VORTP_UNIT_TEST)
void VoRTP_SetAutoRecording( kal_uint32 type, kal_bool write_to_rem_drv )
{
   Media_Format media_format;
   switch(type)
   {
      case 1:
         media_format = MEDIA_FORMAT_WAV_DVI_ADPCM;
         break;
#if VOIPEVL_SUPPORT
      case 2:
         media_format = MEDIA_FORMAT_VOIPEVL;
         break;
#endif
      default:
         media_format = (Media_Format)-1;
         break;
   }
   autoRecordingFormat = media_format;
   bWriteToRemDrv = write_to_rem_drv;
}
#endif
#endif

#if defined(VORTP_UNIT_TEST)
static int vortp_AutoSpeak_open_file()
{
#if !defined(SIM_ON_VC)
   kal_int16 drv_letter;
   kal_wchar filename[40];

   if(vortp_auto_speak.bReadFromRemDrv)
      drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );
   else
      drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
   kal_wsprintf( filename, "%c:\\%s", drv_letter, vortp_auto_speak.filename );
   
   if( FSAL_OK != FSAL_Open( &vortp_auto_speak.fAutoSpeak, filename, FSAL_READ ) )
#else
   char filename[40];
   sprintf( filename, "%s", vortp_auto_speak.filename );
   if( ( vortp_auto_speak.fAutoSpeak = fopen(filename, "rb") ) != 0 )
#endif
   {
      kal_prompt_trace(MOD_L1SP, "autospeak: source file can't open\n");
      return 1;
   }

#if !defined(SIM_ON_VC)
   FSAL_Read( &vortp_auto_speak.fAutoSpeak, (kal_uint8 *)&vortp_auto_speak.stWavHdr, sizeof(struct wav_header) );
#else
   fread( (kal_uint8 *)&vortp_auto_speak.stWavHdr, sizeof(struct wav_header), 1, vortp_auto_speak.fAutoSpeak );
#endif
   if( strncmp(vortp_auto_speak.stWavHdr.riff_chunk, "RIFF", 4) != 0 )
      ASSERT(0);
   vortp_auto_speak.sample_elapsed = vortp_auto_speak.stWavHdr.data_size >> 1;
#if !defined(SIM_ON_VC)
   FSAL_SetBuffer( &vortp_auto_speak.fAutoSpeak, 1024, vortp_auto_speak.pFSALBuffer );
#endif
   return 0;
}

static void vortp_AutoSpeak_close_file()
{
#if !defined(SIM_ON_VC)
   FSAL_Close( &vortp_auto_speak.fAutoSpeak );
#else
   fclose( vortp_auto_speak.fAutoSpeak );
#endif
}

static void vortp_AutoSpeakCallbackInMed( kal_uint32 arg1, void *arg2 )
{
   kal_int16 *write_ptr;
   kal_int32 write_len;
   kal_int32 count;
   PCMRB *rb = &vortp_auto_speak.vmi_handle->rb;

   (void)arg1;
   (void)arg2;
   
   write_len = PCMRB_GetFreeSpace( rb );
   while( write_len > 0 )
   {
      PCMRB_GetWriteBlock( rb, &write_ptr, &count );
      if( vortp_auto_speak.sample_elapsed == 0 )
      {
         memset( write_ptr, 0, count << 1 );
      }
      else
      {
         if( vortp_auto_speak.sample_elapsed < count )
            count = vortp_auto_speak.sample_elapsed;
#if !defined(SIM_ON_VC)
         FSAL_Read( &vortp_auto_speak.fAutoSpeak, (kal_uint8 *)write_ptr, count << 1 );
#else
         fread((void *)write_ptr, 1, count << 1, vortp_auto_speak.fAutoSpeak);
#endif
         vortp_auto_speak.sample_elapsed -= count;
      }
      PCMRB_ShiftWritePointer(rb, count);
      write_len -= count;
   }

   if( vortp_auto_speak.sample_elapsed == 0 )
   {
      if( vortp_auto_speak.reopen == 0 )
      {
#if !defined(SIM_ON_VC)
         FSAL_Seek( &vortp_auto_speak.fAutoSpeak, sizeof(struct wav_header) );
#else
         fseek( vortp_auto_speak.fAutoSpeak, sizeof(struct wav_header), SEEK_SET );
#endif
      }
      else
      {
         vortp_AutoSpeak_close_file();
         if( 0 != vortp_AutoSpeak_open_file() )
            return;
      }
      vortp_auto_speak.sample_elapsed = vortp_auto_speak.stWavHdr.data_size >> 1;
   }
}

static void vortp_AutoSpeakCallback( void *host_data, VMI_EVENT event )
{
   if( PCMRB_GetFreeSpace( &vortp_auto_speak.vmi_handle->rb ) >= 1024 )
      L1Audio_InProcCall2( vortp_AutoSpeakCallbackInMed, 0, 0 );
}

static void vortp_AutoSpeak_Start()
{
   kal_uint32 buf_len = 3840+1024;

   vortp_auto_speak.reopen = 0;
   vortp_auto_speak.pAutoSpeakBuffer = med_alloc_ext_mem(buf_len);
   if( vortp_auto_speak.pAutoSpeakBuffer==NULL )
      return;
   buf_len -= 1024;
   vortp_auto_speak.pFSALBuffer = (kal_uint8 *)&vortp_auto_speak.pAutoSpeakBuffer[buf_len];
   if( 0 != vortp_AutoSpeak_open_file() )
      return;

   buf_len -= 3840;
   vortp_auto_speak.vmi_handle = VMI_GetHandle( VMI_DIR_DL, (uint8 *)&vortp_auto_speak.pAutoSpeakBuffer[buf_len], 3840 );
   vortp_auto_speak.vmi_handle->mix = 1;
   vortp_auto_speak.vmi_handle->mic = 1;
   vortp_auto_speak.vmi_handle->session_id = VMI_AUTOSPEAK_SID;
   vortp_auto_speak.vmi_handle->callback = vortp_AutoSpeakCallback;
   vortp_auto_speak.vmi_handle->host_data = 0;
   if( VMI_STATUS_SUCCESS != VMI_Start( vortp_auto_speak.vmi_handle ) )
   {
      vortp_AutoSpeak_close_file();
      med_free_ext_mem( (void **)&vortp_auto_speak.pAutoSpeakBuffer );
   }
   else
   {
      int16*ptr;
      int32 size;
      PCMRB_GetWriteBlock( &vortp_auto_speak.vmi_handle->rb, &ptr, &size );
      memset( (void *)ptr, 0, size*sizeof(int16) );
      PCMRB_ShiftWritePointer( &vortp_auto_speak.vmi_handle->rb, size );
   }
}

static void vortp_AutoSpeak_Stop()
{
   if( vortp_auto_speak.pAutoSpeakBuffer==NULL )
      return;

   VMI_FreeHandle( vortp_auto_speak.vmi_handle );

   vortp_AutoSpeak_close_file();
   med_free_ext_mem( (void **)&vortp_auto_speak.pAutoSpeakBuffer );
}

void VoRTP_SetAutoSpeak( char *filename, kal_bool read_from_rem_drv )
{
   strncpy( vortp_auto_speak.filename, filename, 40 );
   vortp_auto_speak.bReadFromRemDrv = read_from_rem_drv;
   autoSpeakEnable = (filename[0]=='-')? KAL_FALSE: KAL_TRUE;
   vortp_auto_speak.reopen = 1;
}

void _ut_VoRTP_put_dl_packet_from_file( VORTP_DL_HANDLE *handle, void *file_handle )
{
   kal_int32 buffer_size;
   rtp_audio_codec_type codec_type;
#if !defined(SIM_ON_VC)
   STFSAL *fp_dl = (STFSAL *)file_handle;

   if( fp_dl!=NULL && FSAL_Read( fp_dl, ut_VoRTP.packet_buffer, 256 )!=FSAL_OK )
   {
      buffer_size = 0;
      FSAL_Seek( fp_dl, 0 ); // rewind
      return;
   }
#else
   FILE *fp_dl = (FILE *)file_handle;

   if( fp_dl!=NULL && fread( ut_VoRTP.packet_buffer, 1, 256, fp_dl )<256 )
   {
      buffer_size = 0;
      fseek( fp_dl, 0, SEEK_SET ); // rewind
      return;
   }
#endif
   buffer_size = ut_VoRTP.packet_buffer[255];
   codec_type = (rtp_audio_codec_type)(((rtp_hdr_t *)(ut_VoRTP.packet_buffer))->ssrc);

   handle->PutPacket( handle, ut_VoRTP.packet_buffer, buffer_size, codec_type );
}

void l1aud_test_handler( kal_uint32 arg1, void* arg2 )
{
   _ut_VoRTP_PARAM_T *param = (_ut_VoRTP_PARAM_T *)arg2;
   kal_uint32 sid = (kal_uint32)param->host_data;
   kal_uint32 buffer_size;
   rtp_audio_codec_type codec_type;
   kal_int32 packet_count;
   VORTP_UL_HANDLE *uplink = (VORTP_UL_HANDLE *)param->handle;
   //VORTP_DL_HANDLE *downlink = (VORTP_DL_HANDLE *)param->handle;
   VORTP_EVENT event = param->event_t;

   switch( event )
   {
      case VORTP_EVENT_UL_READY:
         ASSERT( uplink==ut_VoRTP.session[sid].uplink );
#if ALLOW_UL_WAIT
         do
#else
         packet_count = uplink->GetPacketCount( uplink );
         while( packet_count>0 )
#endif
         {
            memset( ut_VoRTP.packet_buffer, 0, 256 );
            buffer_size = uplink->GetPacket( 
               uplink, ut_VoRTP.packet_buffer, 
               255, &codec_type );
            if( buffer_size==0 )
#if ALLOW_UL_WAIT
              break;
#else
              ASSERT(0);
#endif
            ut_VoRTP.packet_buffer[255] = (kal_uint8)buffer_size;

            ut_VoRTP.packet_buffer[2] = ( ut_VoRTP.session[sid].ul_seq_no >> 8 ) & 0xff;
            ut_VoRTP.packet_buffer[3] = ut_VoRTP.session[sid].ul_seq_no & 0xff;
            ut_VoRTP.session[sid].ul_seq_no++;

            if( _ut_VoRTP_save_ == 1 )
            {
#if !defined(SIM_ON_VC)
               FSAL_Write( &ut_VoRTP.session[sid].fp_ul, ut_VoRTP.packet_buffer, sizeof(kal_uint8)*256 );
#else
               fwrite( ut_VoRTP.packet_buffer, sizeof(kal_uint8), 256, ut_VoRTP.session[sid].fp_ul );
#endif
            }
            _ut_VoRTP_put_dl_packet_from_file( ut_VoRTP.session[sid].downlink, 
#if !defined(SIM_ON_VC)
               (_ut_VoRTP_loopback_==1)? NULL: (void *)&(ut_VoRTP.session[sid].fp_dl) );
#else
               (_ut_VoRTP_loopback_==1)? NULL: (void *)ut_VoRTP.session[sid].fp_dl );
#endif
            packet_count --;
         } 
#if ALLOW_UL_WAIT
         while(1);
#endif
         break;
      case VORTP_EVENT_DL_ERROR:
         break;
      case VORTP_EVENT_TONE_FINISH:
         break;
      default:
         ASSERT(0);
         break;
   }
}

static void _ut_VoRTP_ul_callback( VORTP_EVENT event, VORTP_UL_HANDLE *handle, void *host_data )
{ // host should send mesage to its current context and then handle it
   _ut_VoRTP_Param.event_t = event;
   _ut_VoRTP_Param.handle = (void *)handle;
   _ut_VoRTP_Param.host_data = (void *)host_data;
   L1Audio_InProcCall( l1aud_test_handler, 0, (void *)&_ut_VoRTP_Param );
}

static void _ut_VoRTP_dl_callback( VORTP_EVENT event, VORTP_DL_HANDLE *handle, void *host_data )
{ // host should send mesage to its current context and then handle it
   _ut_VoRTP_Param.event_t = event;
   _ut_VoRTP_Param.handle = (void *)handle;
   _ut_VoRTP_Param.host_data = (void *)host_data;
   L1Audio_InProcCall( l1aud_test_handler, 0, (void *)&_ut_VoRTP_Param );
}

static void _ut_VoRTP_tone_callback( VORTP_EVENT event, void *host_data )
{ // host should send mesage to its current context and then handle it
   _ut_VoRTP_Param.event_t = event;
   _ut_VoRTP_Param.handle = (void *)0;
   _ut_VoRTP_Param.host_data = (void *)host_data;
   L1Audio_InProcCall( l1aud_test_handler, 0, (void *)&_ut_VoRTP_Param );
}
void VoRTP_WatchInternal()
{
   VORTP_UL_INT *ul;
   VORTP_DL_INT *dl;
   int i;
   
   kal_prompt_trace(MOD_L1SP, "VoRTP_context.audId=%d, VoRTP_context.numStreams=%d\n", 
      VoRTP_context.audId, VoRTP_context.numStreams);
   if(VoRTP_context.numStreams == 0)
      return;

   ul = VoRTP_context.uplinkHead;
   i = 0;
   while(ul != NULL)
   {
      kal_prompt_trace(MOD_L1SP, "UL%d: state=%d, sid=%d\n", 
         i, ul->handle.state, ul->handle.session_id);
      kal_prompt_trace(MOD_L1SP, "UL%d fifo: read=%d, write=%d\n", 
         i, ul->fifo_handle.read, ul->fifo_handle.write);

      ul = ul->next;
      i ++;
   }
   
   dl = VoRTP_context.downlinkHead;
   i = 0;
   while(dl != NULL)
   {
      kal_prompt_trace(MOD_L1SP, "DL%d: state=%d, sid=%d\n", 
         i, dl->handle.state, dl->handle.session_id);

      dl = dl->next;
      i ++;
   }

}

int VoRTP_main(int argc, char **argv)
{
   char *name_str, *sid_str;

   if( argc<2 )
      return -1;
   name_str = argv[0];

   if( strncmp( name_str, "sys.", 4 )==0 )
   {
      name_str += 4;
      if( strcmp( name_str, "save" )==0 )
      {
         _ut_VoRTP_save_ = atoi( argv[1] );
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: sys.save = %d\n", _ut_VoRTP_save_ );
      }
      else if( strcmp( name_str, "loopback" )==0 )
      {
         _ut_VoRTP_loopback_ = atoi( argv[1] );
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: sys.loopback = %d\n", _ut_VoRTP_loopback_ );
      }
      else if( strcmp( name_str, "autorec" )==0 )
      {
         int arg1, arg2;
         arg1 = atoi( argv[1] );
         arg2 = atoi( argv[2] );
         if( ( argc > 3 ) && ( atoi( argv[3] ) == 0 ) )
            is_rec_pcm = KAL_FALSE;
         else
            is_rec_pcm = KAL_TRUE;
         if( ( argc > 4 ) && ( atoi( argv[4] ) == 0 ) )
            is_rec_dl = KAL_FALSE;
         else
            is_rec_dl = KAL_TRUE;
         if( ( argc > 5 ) && ( atoi( argv[5] ) == 0 ) )
            is_rec_ul = KAL_FALSE;
         else
            is_rec_ul = KAL_TRUE;
         VoRTP_SetAutoRecording( arg1, (kal_bool)(arg2>0) );
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: sys.autorec = %d/%d, %d\n", arg1, arg2, autoRecordingFormat );
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: is_rec_pcm = %d\n", is_rec_pcm );
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: is_rec_dl = %d\n", is_rec_dl );
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: is_rec_ul = %d\n", is_rec_ul );
      }
      else if( strcmp( name_str, "autospeak" )==0 )
      {
         int arg2;
         arg2 = atoi( argv[2] );
         VoRTP_SetAutoSpeak( argv[1], (kal_bool)(arg2>0) );
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: sys.autospeak = %s, %d\n", argv[1], arg2 );
      }
      else if( strcmp( name_str, "watch" )==0 )
      {
         if( strcmp( argv[1], "vmi" ) == 0 )
         {
            extern void VMI_WatchInternal( void );
            VMI_WatchInternal();
         }
         else if( strcmp( argv[1], "vortp" ) == 0 )
         {
            VoRTP_WatchInternal();
         }
      }
      else if( strcmp( name_str, "jitter" )==0 )
      {
         if(argc > 2)
         {
            VoIP_MIN_JITTER_TIME = atoi( argv[1] );
            VoIP_MAX_JITTER_TIME = atoi( argv[2] );
         }

         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: sys.jitter = %d, %d\n", VoIP_MIN_JITTER_TIME, VoIP_MAX_JITTER_TIME );
      }
      else if( strcmp( name_str, "set" )==0 )
      {
         if(argc > 1) jitter_var_mul = atoi( argv[1] );
         if(argc > 2) jitter_mean_run = atoi( argv[2] );
         
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: jitter_var_mul = %d\n", jitter_var_mul );
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: jitter_mean_run = %d\n", jitter_mean_run );
      }
      return 0;
   }

   sid_str = argv[1];

   while(1)
   {
      int sid = -1;
      for( ;; )
      {
         char ch = *sid_str;
         if( ch=='\0' )
            break;
         else if( ch>='0' && ch<='9' )
         {
            sid = (int)(ch-'0');
            sid_str++;
            break;
         }
         sid_str++;
      }
      if( sid<0 )
         break;

      if( strcmp( name_str, "open" )==0 )
      {
         ut_VoRTP.session[sid].uplink = VoRTP_OpenULChannel();
         ut_VoRTP.session[sid].downlink = VoRTP_OpenDLChannel();

         if( ut_VoRTP.session[sid].uplink!=NULL && ut_VoRTP.session[sid].downlink!=NULL )
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: open %d success\n", sid );
         else
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: open %d fail\n", sid );

         if( _ut_VoRTP_save_ == 1 )
         {
#if !defined(SIM_ON_VC)
            kal_int16 drv_letter;
            kal_wchar filename[40];
            drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );
            kal_wsprintf( filename, "%c:\\rtp_ul_%d.pkt", drv_letter, sid );
            FSAL_Open( &ut_VoRTP.session[sid].fp_ul, filename, FSAL_WRITE );
            ut_VoRTP.session[sid].fs_buf_ul = (kal_uint8 *)med_alloc_ext_mem(8192);
            FSAL_SetBuffer( &ut_VoRTP.session[sid].fp_ul, 8192, ut_VoRTP.session[sid].fs_buf_ul );
            if(_ut_VoRTP_loopback_==0)
            {
               kal_wsprintf( filename, "%c:\\rtp_dl_%d.pkt", drv_letter, sid );
               ASSERT( FSAL_OK==FSAL_Open( &ut_VoRTP.session[sid].fp_dl, filename, FSAL_READ ) );
               ut_VoRTP.session[sid].fs_buf_dl = (kal_uint8 *)med_alloc_ext_mem(8192);
               FSAL_SetBuffer( &ut_VoRTP.session[sid].fp_dl, 8192, ut_VoRTP.session[sid].fs_buf_dl );
            }
#else
            char filename[40];
            sprintf( filename, "rtp_ul_%d.pkt", sid );
            ut_VoRTP.session[sid].fp_ul = fopen( filename, "wb" );
            if(_ut_VoRTP_loopback_==0)
            {
               sprintf( filename, "rtp_dl_%d.pkt", sid );
               ASSERT( NULL!=(ut_VoRTP.session[sid].fp_dl = fopen( filename, "rb" )) );
            }
#endif
         }
      }
      else if( strncmp( name_str, "query", 5 )==0 )
      {
         rtp_audio_codec_type codec_type;
         kal_bool is_alternated;
         VORTP_UL_HANDLE *handle = ut_VoRTP.session[sid].uplink;

         if( strcmp( name_str, "query" )==0 )
            is_alternated = KAL_FALSE;
         else if( strcmp( name_str, "queryalt" )==0 )
            is_alternated = KAL_TRUE;
         else
            break;

         if( argc<3 )
         {
            if( is_alternated==KAL_TRUE )
               handle->GetAvailableCodecs( handle, &codec_type );
            else
               codec_type = handle->GetAvailableCodecs( handle, NULL );
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: query %d result - %d,%d,%d,%d\n", sid, 
               (codec_type&RTP_AUDIO_G729)>>1, (codec_type&RTP_AUDIO_G7231)>>2, 
               (codec_type&(RTP_AUDIO_G726_16|RTP_AUDIO_G726_24|RTP_AUDIO_G726_32|RTP_AUDIO_G726_40))>>3, 
               (codec_type&(RTP_AUDIO_PCMA|RTP_AUDIO_PCMU))>>7 );
         }
         else
         {
            rtp_audio_codec_cap codec_cap;
            VORTP_STATUS status;
            if( strcmp( argv[3], "g729" )==0 )
            {
               status = handle->GetCodecCapability( handle, RTP_AUDIO_G729, &codec_cap, is_alternated );
               if( status!=VORTP_STATUS_SUCCESS )
                  kal_prompt_trace( MOD_L1SP, "ut_VoRTP: query %d g729 result fail\n", 
                     sid );
               else
                  kal_prompt_trace( MOD_L1SP, "ut_VoRTP: query %d g729 result - ptime=%d, maxptime=%d, annexb=%d\n", 
                     sid, codec_cap.g729.ptime, codec_cap.g729.maxptime, codec_cap.g729.annexb );
            }
            else if( strcmp( argv[3], "g7231" )==0 )
            {
               status = handle->GetCodecCapability( handle, RTP_AUDIO_G7231, &codec_cap, is_alternated );
               if( status!=VORTP_STATUS_SUCCESS )
                  kal_prompt_trace( MOD_L1SP, "ut_VoRTP: query %d g7231 result fail\n", 
                     sid );
               else
                  kal_prompt_trace( MOD_L1SP, "ut_VoRTP: query %d g7231 result - ptime=%d, maxptime=%d, annexa=%d\n", 
                     sid, codec_cap.g7231.ptime, codec_cap.g7231.maxptime, codec_cap.g7231.annexa );
            }
            else if( strcmp( argv[3], "g726" )==0 )
            {
               status = handle->GetCodecCapability( handle, RTP_AUDIO_G726_32, &codec_cap, is_alternated );
               if( status!=VORTP_STATUS_SUCCESS )
                  kal_prompt_trace( MOD_L1SP, "ut_VoRTP: query %d g726_32 result fail\n", 
                     sid );
               else
                  kal_prompt_trace( MOD_L1SP, "ut_VoRTP: query %d g726_32 result - ptime=%d, maxptime=%d, cn=%d\n", 
                     sid, codec_cap.g726.ptime, codec_cap.g726.maxptime, codec_cap.g726.cn_payload );
            }
            else if( strcmp( argv[3], "g711" )==0 )
            {
               status = handle->GetCodecCapability( handle, RTP_AUDIO_PCMA, &codec_cap, is_alternated );
               if( status!=VORTP_STATUS_SUCCESS )
                  kal_prompt_trace( MOD_L1SP, "ut_VoRTP: query %d g711_a result fail\n", 
                     sid );
               else
                  kal_prompt_trace( MOD_L1SP, "ut_VoRTP: query %d g711_a result - ptime=%d, maxptime=%d, cn=%d\n", 
                     sid, codec_cap.g711.ptime, codec_cap.g711.maxptime, codec_cap.g711.cn_payload );
            }
            else
            {
               kal_prompt_trace( MOD_L1SP, "unknown codec\n" );
               break;
            }
         }
      }
      else if( strcmp( name_str, "config" )==0 )
      {
         rtp_cap_bool cn_support = RTP_CAP_UNSPECIFIED;
         rtp_audio_codec_type codec_type;
         rtp_audio_codec_cap codec_cap;
         VORTP_UL_HANDLE *uplink = ut_VoRTP.session[sid].uplink;
         VORTP_DL_HANDLE *downlink = ut_VoRTP.session[sid].downlink;
         VORTP_STATUS status;
         kal_uint32 ul_buffer_size, dl_buffer_size;

         if( argc<3 )
            break;
         if( argc>=4 )
         {
            if( strcmp( argv[3], "y" )==0 )
               cn_support = RTP_CODEC_SUPPORT;
            else if( strcmp( argv[3], "n" )==0 )
               cn_support = RTP_CODEC_UNSUPPORT;
            else
               break;
         }
         if( strcmp( argv[2], "g729" )==0 )
         {
            codec_type = RTP_AUDIO_G729;
            codec_cap.g729.ptime = 20;
            codec_cap.g729.maxptime = 60;
            codec_cap.g729.annexb = cn_support;
         }
         else if( strcmp( argv[2], "g7231_53" )==0 )
         {
            codec_type = RTP_AUDIO_G7231;
            codec_cap.g7231.ptime = 30;
            codec_cap.g7231.maxptime = 60;
            codec_cap.g7231.bitrate = G7231_BITRATE_0530;
            codec_cap.g7231.annexa = cn_support;
         }
         else if( strcmp( argv[2], "g7231_63" )==0 )
         {
            codec_type = RTP_AUDIO_G7231;
            codec_cap.g7231.ptime = 30;
            codec_cap.g7231.maxptime = 60;
            codec_cap.g7231.bitrate = G7231_BITRATE_0630;
            codec_cap.g7231.annexa = cn_support;
         }
         else if( strcmp( argv[2], "g726_16" )==0 )
         {
            codec_type = RTP_AUDIO_G726_16;
            codec_cap.g726.ptime = 10;
            codec_cap.g726.maxptime = 30;
            codec_cap.g726.cn_payload = cn_support;
         }
         else if( strcmp( argv[2], "g726_24" )==0 )
         {
            codec_type = RTP_AUDIO_G726_24;
            codec_cap.g726.ptime = 10;
            codec_cap.g726.maxptime = 30;
            codec_cap.g726.cn_payload = cn_support;
         }
         else if( strcmp( argv[2], "g726_32" )==0 )
         {
            codec_type = RTP_AUDIO_G726_32;
            codec_cap.g726.ptime = 10;
            codec_cap.g726.maxptime = 30;
            codec_cap.g726.cn_payload = cn_support;
         }
         else if( strcmp( argv[2], "g726_40" )==0 )
         {
            codec_type = RTP_AUDIO_G726_40;
            codec_cap.g726.ptime = 10;
            codec_cap.g726.maxptime = 30;
            codec_cap.g726.cn_payload = cn_support;
         }
         else if( strcmp( argv[2], "g711_a" )==0 )
         {
            codec_type = RTP_AUDIO_PCMA;
            codec_cap.g711.ptime = 10;
            codec_cap.g711.maxptime = 20;
            codec_cap.g711.cn_payload = cn_support;
            codec_cap.g711.rate = G711_RATE_8000;
            codec_cap.g711.channel = 1;
         }
         else if( strcmp( argv[2], "g711_u" )==0 )
         {
            codec_type = RTP_AUDIO_PCMU;
            codec_cap.g711.ptime = 10;
            codec_cap.g711.maxptime = 20;
            codec_cap.g711.cn_payload = cn_support;
            codec_cap.g711.rate = G711_RATE_8000;
            codec_cap.g711.channel = 1;
         }
         else
         {
            kal_prompt_trace( MOD_L1SP, "unknown codec\n" );
            break;
         }
         status = uplink->Config( uplink, codec_type, &codec_cap, _ut_VoRTP_ul_callback, (void *)sid, (kal_uint32)sid );
         if( status!= VORTP_STATUS_SUCCESS )
         {
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: config %d uplink fail - %d\n", sid, status );
            break;
         }
         status = downlink->Config( downlink, codec_type, &codec_cap, _ut_VoRTP_dl_callback, (void *)sid, (kal_uint32)sid );
         if( status!= VORTP_STATUS_SUCCESS )
         {
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: config %d downlink fail - %d\n", sid, status );
            break;
         }

         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: config %d ok\n", sid );

         ul_buffer_size = uplink->GetBufferSize( uplink );
         dl_buffer_size = downlink->GetBufferSize( downlink );
         ut_VoRTP.session[sid].app_buffer = (kal_uint8 *)med_alloc_ext_mem( ul_buffer_size+dl_buffer_size );
         status = uplink->SetBuffer( uplink, ut_VoRTP.session[sid].app_buffer, ul_buffer_size );
         if( status!= VORTP_STATUS_SUCCESS )
         {
            med_free_ext_mem( (void **)&ut_VoRTP.session[sid].app_buffer );
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: setbuffer %d uplink fail - %d\n", sid, status );
            break;
         }
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: setbuffer_ul %d, %d ok\n", sid, ul_buffer_size );
         status = downlink->SetBuffer( downlink, ut_VoRTP.session[sid].app_buffer+ul_buffer_size, dl_buffer_size );
         if( status!= VORTP_STATUS_SUCCESS )
         {
            med_free_ext_mem( (void **)&ut_VoRTP.session[sid].app_buffer );
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: setbuffer %d downlink fail - %d\n", sid, status );
            break;
         }
         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: setbuffer_dl %d, %d ok\n", sid, dl_buffer_size );
         break;
      }
      else if( strcmp( name_str, "start" )==0 )
      {
         VORTP_UL_HANDLE *uplink = ut_VoRTP.session[sid].uplink;
         VORTP_DL_HANDLE *downlink = ut_VoRTP.session[sid].downlink;
         VORTP_STATUS status;
         kal_uint32 timestamp = GetCurrentSystime(); // 8K base

         status = uplink->Start( uplink, timestamp );
         if( status!= VORTP_STATUS_SUCCESS )
         {
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: start %d uplink fail - %d\n", sid, status );
            break;
         }
         status = downlink->Start( downlink );
         if( status!= VORTP_STATUS_SUCCESS )
         {
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: start %d downlink fail - %d\n", sid, status );
            break;
         }

         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: start %d ok\n", sid );
      }
      else if( strcmp( name_str, "stop" )==0 )
      {
         VORTP_UL_HANDLE *uplink = ut_VoRTP.session[sid].uplink;
         VORTP_DL_HANDLE *downlink = ut_VoRTP.session[sid].downlink;
         VORTP_STATUS status;

         status = uplink->Stop( uplink );
         if( status!= VORTP_STATUS_SUCCESS )
         {
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: stop %d uplink fail - %d\n", sid, status );
            break;
         }
         status = downlink->Stop( downlink );
         if( status!= VORTP_STATUS_SUCCESS )
         {
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: stop %d downlink fail - %d\n", sid, status );
            break;
         }

         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: stop %d ok\n", sid );
      }
      else if( strcmp( name_str, "close" )==0 )
      {
         VORTP_UL_HANDLE *uplink = ut_VoRTP.session[sid].uplink;
         VORTP_DL_HANDLE *downlink = ut_VoRTP.session[sid].downlink;
         VORTP_STATUS status;

         status = uplink->Close( uplink );
         if( status!= VORTP_STATUS_SUCCESS )
         {
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: close %d uplink fail - %d\n", sid, status );
            break;
         }
         status = downlink->Close( downlink );
         if( status!= VORTP_STATUS_SUCCESS )
         {
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: close %d downlink fail - %d\n", sid, status );
            break;
         }

         if( ut_VoRTP.session[sid].app_buffer!=NULL )
            med_free_ext_mem( (void **)&ut_VoRTP.session[sid].app_buffer );

#if !defined(SIM_ON_VC)
         if( _ut_VoRTP_save_ == 1 )
         {
            FSAL_Close( &ut_VoRTP.session[sid].fp_ul );
            med_free_ext_mem( (void **)&ut_VoRTP.session[sid].fs_buf_ul );
         }
         if(_ut_VoRTP_loopback_==0)
         {
            FSAL_Close( &ut_VoRTP.session[sid].fp_dl );
            med_free_ext_mem( (void **)&ut_VoRTP.session[sid].fs_buf_dl );
         }
#else
         if( _ut_VoRTP_save_ == 1 )
         {
            if( ut_VoRTP.session[sid].fp_ul!=NULL ) fclose( ut_VoRTP.session[sid].fp_ul );
         }
         if(_ut_VoRTP_loopback_==0)
            if( ut_VoRTP.session[sid].fp_dl!=NULL ) fclose( ut_VoRTP.session[sid].fp_dl );
#endif

         kal_prompt_trace( MOD_L1SP, "ut_VoRTP: close %d ok\n", sid );
      }
      else if( strcmp( name_str, "toneon" )==0 )
      {
         kal_uint32 freq1, freq2, duration;
         kal_int32 amp;
         VORTP_STATUS status;

         if( argc<6 )
            break;

         freq1 = atoi( argv[2] );
         freq2 = atoi( argv[3] );
         amp = atoi( argv[4] );
         duration = atoi( argv[5] );

         status = VoRTP_StartInbandTone( freq1, freq2, amp, duration, _ut_VoRTP_tone_callback, NULL );
         if( status==VORTP_STATUS_SUCCESS )
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: toneon ok\n" );
         else
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: toneon fail - %d\n", status );
      }
      else if( strcmp( name_str, "toneoff" )==0 )
      {
         VORTP_STATUS status;
         
         status = VoRTP_StopInbandTone();
         if( status==VORTP_STATUS_SUCCESS )
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: toneoff ok\n" );
         else
            kal_prompt_trace( MOD_L1SP, "ut_VoRTP: toneoff fail - %d\n", status );
      }
      else
      {
         kal_prompt_trace( MOD_L1SP, "unknown command\n" );
         break;
      }
   }
   return 0;
}
#endif

#else

VORTP_UL_HANDLE *VoRTP_OpenULChannel( void )
{
   ASSERT(0);
   return NULL;
}

VORTP_DL_HANDLE *VoRTP_OpenDLChannel( void )
{
   ASSERT(0);
   return NULL;
}

VORTP_STATUS VoRTP_StartInbandTone( kal_uint32 freq1, kal_uint32 freq2, kal_int32 amp_dbm0, kal_uint32 duration_msec, VORTP_TONE_CALLBACK callback, void *host_data  )
{
   ASSERT(0);
   return VORTP_STATUS_FAIL;
}

VORTP_STATUS VoRTP_StopInbandTone( void )
{ 
   ASSERT(0);
   return VORTP_STATUS_FAIL;
}


#endif // ...VORTP_SUPPORT

