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
 *   RTPBuffer.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Part of VoRTP driver, including control of downlink jitter buffer and uplink fifo buffer
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
*                     C O M P I L E R   F L A G S
******************************************************************************
*/

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/
#include "VoRTP.h"
#if defined(SIM_ON_VC)
#include <stdio.h>
#endif

/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define MAX_BUFFER_OVERRUNS                       20
#define RESERVED_JITTER_ENTRY                     4
#define DEFAULT_ESTIMATE_JITTER_RUNS              16
#define DEFAULT_ESTIMATE_JITTER_VAR_NUM           3
#define DEFAULT_NUM_PACKET_TO_EXPIRE_BURST        (10*50)
#define DEFAULT_MAX_NUM_PACKET_TO_EXPIRE_PAUSE_DECREASING       (2*50)
#define DEFAULT_MIN_NUM_PACKET_TO_EXPIRE_PAUSE_DECREASING       (10)
#define NUM_EARLY_PACKETS_BEFORE_FIRST_SHRINK     50
#define NUM_EARLY_PACKETS_BEFORE_LATER_SHRINK     4


/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/

/*****************************************************************************
*                        P U B L I C   D A T A
******************************************************************************
*/

/*****************************************************************************
*                       P R I V A T E   D A T A
******************************************************************************
*/
static kal_mutexid RTPJitterMutex = (kal_mutexid)NULL;

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/
#define MAX(a,b)    ((a)>(b)?(a):(b))

/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/

/*****************************************************************************
*                          F U N C T I O N S
******************************************************************************
*/
#if VORTP_SUPPORT || defined(VORTP_UNIT_TEST)

#define RTPJitter
 static void _trace_jitter_info_( RTP_JITTER_HANDLE *handle, kal_int32 session_id )
{
   kal_uint32 old_ts=0, new_ts=0;

   if( handle->oldestFrame!=NULL ) old_ts = RTP_GetTimestamp( &handle->oldestFrame->rtp );
   if( handle->newestFrame!=NULL ) new_ts = RTP_GetTimestamp( &handle->newestFrame->rtp );

   VORTP_TRACE( TRACE_GROUP_VORTP, VORTP_JITTER_INFO, session_id, 
      handle->currentDepth, handle->currentJitterTime, old_ts, new_ts );
}

static void _trace_jitter_overrun_( RTP_JITTER_HANDLE *handle, kal_uint32 session_id )
{
   VORTP_TRACE( TRACE_GROUP_VORTP, VORTP_JITTER_OVERRUN, session_id, 
      handle->consecutiveBufferOverruns );
}

static void _trace_jitter_prebuffering_( RTP_JITTER_HANDLE *handle, kal_int32 fn, kal_uint32 session_id, kal_uint32 get_ts )
{
   VORTP_TRACE( TRACE_GROUP_VORTP, VORTP_JITTER_PREBUF, session_id, 
      handle->preBuffering, fn );
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_DL())
   {
      INF_VORTP_JITTER_PREBUFFER_STRUCT event;
      event.uSessionID = (UINT8)session_id;
      event.uGetTimestamp = (UINT32)get_ts;
      event.uOldestTimestamp = (UINT32)( (handle->oldestFrame == NULL)? 0: RTP_GetTimestamp( &handle->oldestFrame->rtp ) );
      event.uNewestTimestamp = (UINT32)( (handle->newestFrame == NULL)? 0: RTP_GetTimestamp( &handle->newestFrame->rtp ) );
      event.uCurrentJitterTime = (UINT32)handle->currentJitterTime & 0xffff;
      event.bPrebuffering = (UINT32)handle->preBuffering & 0x1;
      event.uInitiator = (UINT32)fn & 0x7;
      event.uConsecutiveBufferOverruns = (UINT32)handle->consecutiveBufferOverruns & 0x3f;
      event.uConsecutiveMarkerBits = (UINT32)handle->maxConsecutiveMarkerBits & 0x3f;
      VORTP_TRACE_EVENT(event, INF_VORTP_JITTER_PREBUFFER);
   }
#endif
}

static void _trace_jitter_time_change_( RTP_JITTER_HANDLE *handle, kal_uint32 session_id, kal_uint32 timePreviousJittertime )
{
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_DL())
   {
         INF_VORTP_JITTER_TIME2_STRUCT event;
         event.uSessionID = (UINT8)session_id;
         event.uOldestTimestamp = (UINT32)( (handle->oldestFrame == NULL)? 0: RTP_GetTimestamp( &handle->oldestFrame->rtp ) );
         event.uNewestTimestamp = (UINT32)( (handle->newestFrame == NULL)? 0: RTP_GetTimestamp( &handle->newestFrame->rtp ) );
         event.uPreviousJitterTime = (UINT16)timePreviousJittertime;
         event.uCurrentJitterTime = (UINT16)handle->currentJitterTime;
         event.uJitterDepth = (UINT8)handle->currentDepth;
         event.uJitterMean = (INT32)handle->estimateJitterMean;
         event.uJitterVar = (INT32)handle->estimateJitterVar;
         event.uIncThreshold = (INT16)handle->incJitterThreshold;
         event.uDecThreshold = (INT16)handle->decJitterThreshold;
         VORTP_TRACE_EVENT(event, INF_VORTP_JITTER_TIME);
   }
#endif
}

static void _trace_jitter_burst_( RTP_JITTER_HANDLE *handle, kal_int32 session_id, kal_int32 current_jitter, kal_int32 prev_max_jitter, kal_int32 lastestBurstJitter )
{
   VORTP_TRACE( TRACE_INFO, VORTP_JITTER_BURST, session_id, 
      current_jitter, prev_max_jitter, lastestBurstJitter );
}

static RTPJitterEntry *newJitterEntry(kal_uint32 maxPayloadSize, kal_uint32 **buffer_pool){
  RTPJitterEntry *entry;
  entry = (RTPJitterEntry *)*buffer_pool; *buffer_pool += (sizeof(RTPJitterEntry)+3)/4;
  
  entry->next = entry->prev = NULL;
  entry->tick = 0;
  RTP_InitDataFrame(&entry->rtp, maxPayloadSize, buffer_pool);
  return entry;
}

void jitterBurstExpiredCallback(int tid)
{
   RTP_JITTER_HANDLE *handle = (RTP_JITTER_HANDLE *)rtpTimerGetHostData(tid);

   handle->isBurstState = KAL_FALSE;
   handle->latestBurstJitter = 0;
   VORTP_TRACE(TRACE_INFO, VORTP_JITTER_BURST_STATE, handle->rtpSessionId, 0);
}

void jitterPauseDecreasingCallback(int tid)
{
   RTP_JITTER_HANDLE *handle = (RTP_JITTER_HANDLE *)rtpTimerGetHostData(tid);

   handle->isPauseDecreasing = KAL_FALSE;
}

/*
 * RTPJitter method
 */
kal_uint32 RTPJitter_GetBufferSize( RTP_JITTER_HANDLE *handle )
{
   kal_uint32 numJitterEntry;
   kal_uint32 bufferSizeRequiredPerEntry;

   numJitterEntry = handle->maxJitterTime/handle->minPacketTime + 2;
   bufferSizeRequiredPerEntry = (sizeof(RTPJitterEntry)+3)&(~3);
   bufferSizeRequiredPerEntry += ((MIN_HEADER_SIZE+handle->maxPayloadSize)+3)&(~3);
   return( numJitterEntry*bufferSizeRequiredPerEntry );
}

kal_bool RTPJitter_Open( RTP_JITTER_HANDLE *handle, kal_uint8 *buffer, kal_uint32 *buffer_size, kal_uint32 session_id )
{
   int i;
   kal_uint32 used_buffer_size;
   int numJitterEntry;
   kal_uint32 *buffer_pool = (kal_uint32 *)buffer;
   
   used_buffer_size = RTPJitter_GetBufferSize( handle );
   if( *buffer_size>=used_buffer_size )
      *buffer_size = used_buffer_size;
   else
      RTP_ASSERT( 0 );

   handle->rtpSessionId = session_id;
   
   // Jitter buffer is a queue of frames waiting for playback, a list of
   // free frames, and a couple of place holders for the frame that is
   // currently beeing read from the RTP transport or written to the codec.
 
   handle->oldestFrame = handle->newestFrame = handle->currentWriteFrame = NULL;
 
   // Calculate the maximum amount of timestamp units for the jitter buffer
   handle->currentJitterTime = handle->minJitterTime;
   //handle->currentJitterTime = (handle->maxJitterTime - handle->minJitterTime)/3;
 
   // Calculate number of frames to allocate
   numJitterEntry = (handle->maxJitterTime/handle->minPacketTime) + 2;
 
   // Nothing in the buffer so far
   handle->estimateJitterMean = Time2Msec(handle->minJitterTime / 4) * ESTIMATE_JITTER_RATIO;
   handle->previousJitter = 0;
   handle->estimateJitterVar = Time2Msec(handle->minJitterTime / 12) * ESTIMATE_JITTER_RATIO;
   handle->incJitterThreshold = (handle->currentJitterTime * 7 / 8) >> 3;
   handle->decJitterThreshold = 0;
   handle->lastArrivedTimestamp = 0x0;
   handle->lastArrivedTick = 0x0;
   handle->isArrivedInit = KAL_FALSE;

   handle->lastSSRC = 0x0;
   handle->lastTimestamp = 0x0;
   handle->lastSeqNumber = 0x0;
   handle->lastSeqNumberInit = KAL_FALSE;

   handle->numJitterEntry = numJitterEntry;

   handle->currentDepth = 0;
   handle->preBuffering = KAL_TRUE;
   handle->packetsTooLate = 0;
   handle->bufferOverruns = 0;
   handle->consecutiveBufferOverruns = 0;
   handle->consecutiveMarkerBits = 0;

   handle->latestBurstJitter = 0;
   handle->isBurstState = KAL_FALSE;
   handle->tidBurstExpired = rtpCreateTimer(0, jitterBurstExpiredCallback, (void *)handle);
   RTP_ASSERT(handle->tidBurstExpired >= 0);
   handle->isPauseDecreasing = KAL_FALSE;
   handle->tidPauseDecreasing = rtpCreateTimer(0, jitterPauseDecreasingCallback, (void *)handle);
   RTP_ASSERT(handle->tidPauseDecreasing >= 0);
   handle->periodPauseDecreasing = 10;

   handle->consecutiveEarlyPacket = 0;
 
   // Allocate the frames and put them all into the free list
   handle->freeFrames = newJitterEntry(handle->maxPayloadSize, &buffer_pool);
   handle->freeFrames->next = handle->freeFrames->prev = NULL;
 
   for (i = 1; i < numJitterEntry; i++) {
      RTPJitterEntry *entry = newJitterEntry(handle->maxPayloadSize, &buffer_pool);

      entry->prev = NULL;
      entry->next = handle->freeFrames;
      handle->freeFrames->prev = entry;
      handle->freeFrames = entry;
   }
   ASSERT( (kal_uint32)buffer_pool<=(kal_uint32)buffer + (*buffer_size) );
   
   if(RTPJitterMutex == (kal_mutexid)NULL)
      RTPJitterMutex = kal_create_mutex("RTPJitter");

   _trace_jitter_time_change_( handle, handle->rtpSessionId, 0);

   return KAL_TRUE;
}

kal_bool RTPJitter_Close( RTP_JITTER_HANDLE *handle )
{
   rtpDeleteTimer(handle->tidBurstExpired);
   rtpDeleteTimer(handle->tidPauseDecreasing);
   return KAL_TRUE;
}

#define calulateMaxJitter(mvJitterMean, mvJitterVar) (((1 * (mvJitterMean)) + (DEFAULT_ESTIMATE_JITTER_VAR_NUM * (mvJitterVar)) + (ESTIMATE_JITTER_RATIO / 2)) / ESTIMATE_JITTER_RATIO)

kal_uint32 RTPJitter_SetJitterTime(RTP_JITTER_HANDLE *handle, kal_uint32 newJitterTime)
{
   kal_uint16 timePreviousJittertime = handle->currentJitterTime;

   if(newJitterTime > handle->maxJitterTime)
   {
      newJitterTime = handle->maxJitterTime;
   }
   else if(newJitterTime < handle->minJitterTime)
   {
      newJitterTime = handle->minJitterTime;
   }

   if(newJitterTime == handle->maxJitterTime)
      handle->incJitterThreshold = 0xffff;
   else
      handle->incJitterThreshold = (kal_uint16)((Time2Msec(newJitterTime) * 6 + 4) / 8);

   if(newJitterTime == handle->minJitterTime)
      handle->decJitterThreshold = 0;
   else
      handle->decJitterThreshold = (kal_uint16)((Time2Msec(newJitterTime) * 5 + 8) / 16);
   handle->currentJitterTime = (kal_uint16)newJitterTime;
   _trace_jitter_time_change_( handle, handle->rtpSessionId, timePreviousJittertime);

   return newJitterTime;
}

kal_bool RTPJitter_PutData( RTP_JITTER_HANDLE *handle, const RTP_DataFrame *rtpPacket, rtp_audio_codec_type codec_type ){
   RTPJitterEntry * currentReadFrame;
   kal_bool isPacketDuplicated;
   kal_bool isPacketTooLate;
   kal_bool isPacketBad = KAL_FALSE;
   kal_uint32 timePacketTimestamp = RTP_GetTimestamp((RTP_DataFrame *)rtpPacket);
   kal_uint32 PacketSSRC = RTP_GetSyncSource((RTP_DataFrame *)rtpPacket);
   
   kal_take_mutex(RTPJitterMutex);

   // check if SSRC reset
   if(handle->isArrivedInit != KAL_FALSE)
   {
      if(PacketSSRC != handle->lastSSRC)
      {
         // reset state when SSRC reset
         handle->isArrivedInit = KAL_FALSE;
         if(handle->currentDepth > 0)
         {
            // drop the packet until jitter buffer becomes empty
            kal_give_mutex(RTPJitterMutex);
            return KAL_FALSE;
         }
         else
         {
            handle->lastSeqNumberInit = KAL_FALSE;
         }
      }
   }

   // check if the packet arrives too late
   isPacketTooLate = KAL_FALSE;
   if(handle->isArrivedInit != KAL_FALSE && handle->lastSeqNumberInit != KAL_FALSE)
   {
      int time_diff = (int)(timePacketTimestamp - handle->lastTimestamp);
      if(time_diff < -(int)Msec2Time(3000))
      {
         // reset state when timestamp reset
         handle->isArrivedInit = KAL_FALSE;
         if(handle->currentDepth > 0)
         {
            // drop the packet until jitter buffer becomes empty
            kal_give_mutex(RTPJitterMutex);
            return KAL_FALSE;
         }
         else
         {
            handle->lastSeqNumberInit = KAL_FALSE;
         }
      }
      else if( time_diff < 0)
      {
         isPacketTooLate = KAL_TRUE;

         if(IS_VOIPEVL_LOGGING())
         {
            if(handle->consecutiveEarlyPacket >= NUM_EARLY_PACKETS_BEFORE_FIRST_SHRINK)
            {
               INF_VORTP_JITTER_SHRINK_STRUCT event;
               event.uSessionID = (UINT8)handle->rtpSessionId;
               event.uState = 0;
               event.uConfig = 0;
               event.uDelayDiff = 0;
               VORTP_TRACE_EVENT(event, INF_VORTP_JITTER_SHRINK);
            }
         }
         handle->consecutiveEarlyPacket = 0;
      }
   }
   
   // check if the packet is duplicated
   isPacketDuplicated = KAL_FALSE;
   if(handle->isArrivedInit != KAL_FALSE)
   {
      RTPJitterEntry * frame = handle->newestFrame;

      while(frame != NULL)
      {
         if(RTP_GetTimestamp(&frame->rtp) == timePacketTimestamp)
         {
            isPacketDuplicated = KAL_TRUE;
            break;
         }
         else
         {
            frame = frame->next;
         }
      }
      if(isPacketDuplicated != KAL_FALSE)
      {
         // drop the duplicated packet
	  kal_give_mutex(RTPJitterMutex);
	  return KAL_FALSE;
      }
   }

   // drop the too late packet
   if(isPacketTooLate == KAL_FALSE/* && isPacketDuplicated == KAL_FALSE*/)
   {
      if(handle->freeFrames != NULL) {
         // Take the next free frame and make it the current for reading
         currentReadFrame = handle->freeFrames;
         handle->freeFrames = handle->freeFrames->next;
         if (handle->freeFrames != NULL)
            handle->freeFrames->prev = NULL;
         handle->consecutiveBufferOverruns = 0;
      }
      else {
         // We have a full jitter buffer, need a new frame so take the oldest one
         currentReadFrame = handle->oldestFrame;
         handle->oldestFrame = handle->oldestFrame->next;
         if (handle->oldestFrame != NULL)
            handle->oldestFrame->prev = NULL;
         handle->currentDepth--;
         handle->bufferOverruns++;
         handle->consecutiveBufferOverruns++;
         if (handle->consecutiveBufferOverruns > MAX_BUFFER_OVERRUNS) {
            handle->freeFrames = handle->oldestFrame;
            handle->oldestFrame = handle->newestFrame = NULL;
            if(handle->preBuffering == KAL_FALSE)
            {
               handle->preBuffering = KAL_TRUE;
               _trace_jitter_prebuffering_( handle, 1, handle->rtpSessionId, 0 );
            }
         }
         _trace_jitter_overrun_( handle, handle->rtpSessionId );
      }
   
      currentReadFrame->next = NULL;
      
      kal_give_mutex(RTPJitterMutex);
   
      // Keep reading from the RTP transport frames
      RTP_DuplicatePacket(&currentReadFrame->rtp, rtpPacket);
      RTP_SetCodecType(&currentReadFrame->rtp, codec_type); // overwrite SSRC field
   
      currentReadFrame->tick = Tick();
   
      if (RTP_GetMarker(&currentReadFrame->rtp)) {
         // See if remote appears to be setting marker bit on EVERY packet.
         handle->consecutiveMarkerBits++;
         if (handle->consecutiveMarkerBits < handle->maxConsecutiveMarkerBits)
         {
            if(handle->preBuffering == KAL_FALSE)
            {
               handle->preBuffering = KAL_TRUE;
               _trace_jitter_prebuffering_( handle, 1, handle->rtpSessionId, 0 );
            }
         }
      }
      else
         handle->consecutiveMarkerBits = 0;
   
       // Queue the frame for playing by the thread at other end of handle buffer
       kal_take_mutex(RTPJitterMutex);
   
       // Have been reading a frame, put it into the queue now, at correct position
       if (handle->newestFrame == NULL)
       {
          handle->oldestFrame = handle->newestFrame = currentReadFrame; // Was empty
       }
       else if(handle->isArrivedInit == KAL_FALSE)
       {
          currentReadFrame->prev = handle->newestFrame;
          handle->newestFrame->next = currentReadFrame;
          handle->newestFrame = currentReadFrame;
	}
       else
       {
          kal_uint32 time = RTP_GetTimestamp(&currentReadFrame->rtp);
   
          if (time > RTP_GetTimestamp(&handle->newestFrame->rtp))
          {
             if((kal_int16)(RTP_GetSequenceNumber(&currentReadFrame->rtp) - RTP_GetSequenceNumber(&handle->newestFrame->rtp)) <= 0)
             {
                isPacketBad = KAL_TRUE;
             }
             else
             {
                // Is newer than newst, put at that end of queue
                currentReadFrame->prev = handle->newestFrame;
                handle->newestFrame->next = currentReadFrame;
                handle->newestFrame = currentReadFrame;
             }
          }
          else if (time < RTP_GetTimestamp(&handle->oldestFrame->rtp))
          {
             if((kal_int16)(RTP_GetSequenceNumber(&currentReadFrame->rtp) - RTP_GetSequenceNumber(&handle->oldestFrame->rtp)) >= 0)
             {
                isPacketBad = KAL_TRUE;
             }
             else
             {
                // Is older than the oldest, put at that end of queue
               currentReadFrame->next = handle->oldestFrame;
               handle->oldestFrame->prev = currentReadFrame;
               handle->oldestFrame = currentReadFrame;
             }
          }
          else
          {
             // Somewhere in between, locate its position
             RTPJitterEntry * frame = handle->newestFrame->prev;
             int loop_count = 0;
             while (time < RTP_GetTimestamp(&frame->rtp))
             {
                frame = frame->prev;
                RTP_ASSERT(loop_count++ < 100);
             }
   
             if((kal_int16)(RTP_GetSequenceNumber(&currentReadFrame->rtp) - RTP_GetSequenceNumber(&frame->rtp)) <= 0)
             {
                isPacketBad = KAL_TRUE;
             }
             else
             {
                currentReadFrame->prev = frame;
                currentReadFrame->next = frame->next;
                frame->next->prev = currentReadFrame;
                frame->next = currentReadFrame;
             }
          }
       }

      if(isPacketBad == KAL_FALSE)
      {
         handle->currentDepth++;
      }
      else
      {
         currentReadFrame->next = handle->freeFrames;
         if(handle->freeFrames != NULL)
         {
            handle->freeFrames->prev = currentReadFrame;
         }
         handle->freeFrames = currentReadFrame;
         currentReadFrame = NULL;
      }
      _trace_jitter_info_( handle, handle->rtpSessionId );
   }

   // Too late packet should also be taken into acount
   if((isPacketBad == KAL_FALSE)/* && (isPacketDuplicated == KAL_FALSE)*/)
   {
      kal_uint32 cur_ts = RTP_GetTimestamp((RTP_DataFrame *)rtpPacket);
      if((handle->isArrivedInit == KAL_TRUE) && 
          ((RTP_GetMarker((RTP_DataFrame *)rtpPacket) == 0) && (handle->currentDepth > 1)))
      {
         int timePlayTimeDifference = (int)(cur_ts - handle->lastArrivedTimestamp);
         int tickArriveTimeDifference = (int)GetDurationTick(handle->lastArrivedTick, rtpPacket->tick);
         int stimeEstimateJitterMean = (int)handle->estimateJitterMean;
         int stimeEstimateJitterVar = (int)handle->estimateJitterVar;
         int msecCurrentJitter = Time2Msec((int)(Tick2Time(tickArriveTimeDifference) - timePlayTimeDifference));
         int stimeCurrentJitter;
         int stimeCurrentJitterDifference;
         int msecExpectedBufferTime;
         int timeModifiedJitterTime;
         int startBurstState = 0;
         int previousJitter = (int)handle->previousJitter;

         handle->previousJitter = msecCurrentJitter;
         if(msecCurrentJitter < 0)
         {
            msecCurrentJitter = -msecCurrentJitter;
         }
         stimeCurrentJitter = msecCurrentJitter * ESTIMATE_JITTER_RATIO;

         msecExpectedBufferTime = calulateMaxJitter(stimeEstimateJitterMean, stimeEstimateJitterVar);

         if((msecCurrentJitter > msecExpectedBufferTime) && (msecCurrentJitter > Time2Msec(handle->minJitterTime)))
         {
            /* enable burst mode, reset burst expired value */
            if(msecCurrentJitter > handle->latestBurstJitter)
            {
               if(msecCurrentJitter > Time2Msec(handle->currentJitterTime))
               {
                  startBurstState = 1;
               }
               handle->latestBurstJitter = msecCurrentJitter;
            }
            _trace_jitter_burst_(handle, handle->rtpSessionId, msecCurrentJitter, msecExpectedBufferTime, handle->latestBurstJitter);
            if(msecCurrentJitter > handle->latestBurstJitter/2)
            {
               handle->periodPauseDecreasing = DEFAULT_MAX_NUM_PACKET_TO_EXPIRE_PAUSE_DECREASING;
               handle->isBurstState = KAL_TRUE;
               VORTP_TRACE(TRACE_INFO, VORTP_JITTER_BURST_STATE, handle->rtpSessionId, 1);
               rtpResetTimer(handle->tidBurstExpired, DEFAULT_NUM_PACKET_TO_EXPIRE_BURST);
            }
         }
         
         stimeEstimateJitterMean = stimeEstimateJitterMean + 
            ((stimeCurrentJitter - stimeEstimateJitterMean + (DEFAULT_ESTIMATE_JITTER_RUNS / 2)) / DEFAULT_ESTIMATE_JITTER_RUNS);

         stimeCurrentJitterDifference = (previousJitter - handle->previousJitter) * ESTIMATE_JITTER_RATIO;
         if(stimeCurrentJitterDifference < 0)
         {
            stimeCurrentJitterDifference = -stimeCurrentJitterDifference;
         }
         stimeEstimateJitterVar = stimeEstimateJitterVar + 
           ((stimeCurrentJitterDifference - stimeEstimateJitterVar + (DEFAULT_ESTIMATE_JITTER_RUNS / 2)) / DEFAULT_ESTIMATE_JITTER_RUNS);

         handle->estimateJitterMean = stimeEstimateJitterMean;
         handle->estimateJitterVar = stimeEstimateJitterVar;

         msecExpectedBufferTime = calulateMaxJitter(stimeEstimateJitterMean, stimeEstimateJitterVar);
         
         if(startBurstState > 0 || (msecCurrentJitter > handle->incJitterThreshold))
         {
            if(startBurstState > 0)
               timeModifiedJitterTime = Msec2Time((handle->latestBurstJitter * 5 + 2) / 4);
            else
               timeModifiedJitterTime = Msec2Time((msecCurrentJitter * 6 + 2) / 4);

            RTPJitter_SetJitterTime(handle, timeModifiedJitterTime);

            handle->isPauseDecreasing = KAL_TRUE;
            rtpResetTimer(handle->tidPauseDecreasing, handle->periodPauseDecreasing);
         }
         else if(handle->isBurstState == KAL_FALSE && handle->isPauseDecreasing == KAL_FALSE && msecExpectedBufferTime < handle->decJitterThreshold)
         {
            timeModifiedJitterTime = handle->currentJitterTime / 2;

            RTPJitter_SetJitterTime(handle, timeModifiedJitterTime);

            handle->isPauseDecreasing = KAL_TRUE;
            rtpResetTimer(handle->tidPauseDecreasing, handle->periodPauseDecreasing);
            handle->periodPauseDecreasing -= DEFAULT_MIN_NUM_PACKET_TO_EXPIRE_PAUSE_DECREASING;
            if(handle->periodPauseDecreasing < DEFAULT_MIN_NUM_PACKET_TO_EXPIRE_PAUSE_DECREASING)
               handle->periodPauseDecreasing = DEFAULT_MIN_NUM_PACKET_TO_EXPIRE_PAUSE_DECREASING;
         }
      }

      handle->lastArrivedTick = rtpPacket->tick;
      handle->lastArrivedTimestamp = cur_ts;
      handle->lastSSRC = PacketSSRC; // do not use RTP_GetSyncSource
      handle->isArrivedInit = KAL_TRUE;
   }

    kal_give_mutex(RTPJitterMutex);

    return ((isPacketTooLate == KAL_FALSE/* && isPacketDuplicated == KAL_FALSE*/ && isPacketBad == KAL_FALSE)? KAL_TRUE: KAL_FALSE);
}

kal_bool RTPJitter_GetData( RTP_JITTER_HANDLE *handle, RTP_DataFrame *rtpPacket, kal_uint32 timestamp ){
   kal_uint32 oldestTimestamp, newestTimestamp;
   kal_uint32 delay;
   kal_bool isContinued = KAL_TRUE;
   
   /*Free the frame just written to codec, putting it back into
     the free list and clearing the parking spot for it.
    */
   if (handle->currentWriteFrame != NULL) 
   {
      kal_take_mutex(RTPJitterMutex);
  
      // Move frame from current to free list
      handle->currentWriteFrame->next = handle->freeFrames;
      if (handle->freeFrames != NULL)
        handle->freeFrames->prev = handle->currentWriteFrame;
      handle->freeFrames = handle->currentWriteFrame;
  
      handle->currentWriteFrame = NULL;
  
      kal_give_mutex(RTPJitterMutex);
   }
 
   // Default response is an empty frame, ie silence
   RTP_SetPayloadSize(rtpPacket, 0);
 
   kal_take_mutex(RTPJitterMutex);
 
   /*Get the next frame to write to the codec. Takes it from the oldest
     position in the queue, if it is time to do so, and parks it in the
     special member so can unlock the mutex while the writer thread has its
     way with the buffer.
    */
   if (handle->oldestFrame == NULL)
   {
     /*No data to play! We ran the buffer down to empty, restart buffer by
       setting flag that will fill it again before returning any data.
      */
     if(handle->preBuffering == KAL_FALSE)
     {
        handle->preBuffering = KAL_TRUE;
        _trace_jitter_prebuffering_( handle, 2, handle->rtpSessionId, timestamp );
     }
     goto L_RTPJitter_GetData_END;
   }
 
   /* See if time for this packet, if our oldest frame is older than the
      required age, then use it. If it is not time yet, make sure that the
      writer thread isn't falling behind (not enough MIPS). If the time
      between the oldest and the newest entries in the jitter buffer is
      greater than the size specified for the buffer, then return the oldest
      entry regardless, making the writer thread catch up.
   */
 
   oldestTimestamp = RTP_GetTimestamp(&handle->oldestFrame->rtp);
   newestTimestamp = RTP_GetTimestamp(&handle->newestFrame->rtp);
 
   if ((!IS_PREBUFFERING_DISABLED()) && (handle->preBuffering != KAL_FALSE))
   {
      kal_uint32 nearFullTime = handle->currentJitterTime*2/3;
     // Check for requesting something that already exceeds the maximum time,
     // or have filled the jitter buffer, not filling if this is so
     if ((!RTP_isSIDPacket(&handle->oldestFrame->rtp, handle->maxSIDPayloadSize)) &&
         (timestamp < (handle->currentJitterTime + oldestTimestamp)) &&
         (newestTimestamp < (nearFullTime + oldestTimestamp)) ) {
        // Are filling the buffer, don't return anything yet
        goto L_RTPJitter_GetData_END;
     }
 
     handle->preBuffering = KAL_FALSE;
     _trace_jitter_prebuffering_( handle, 2, handle->rtpSessionId, timestamp );
   }

///   if( (timestamp < oldestTimestamp) && ((oldestTimestamp + (handle->currentJitterTime)) > newestTimestamp) )
   if((timestamp < oldestTimestamp) && 
      ((timestamp + handle->currentJitterTime) > newestTimestamp))
   {
     // It is not yet time for something in the buffer
     goto L_RTPJitter_GetData_END;
   }
 
   // Detatch oldest packet from the list, put into parking space
   handle->currentDepth--;
   handle->currentWriteFrame = handle->oldestFrame;
   handle->oldestFrame = handle->currentWriteFrame->next;
   handle->currentWriteFrame->next = NULL;
 
   if(handle->oldestFrame == NULL)
      handle->newestFrame = NULL;
   else 
      handle->oldestFrame->prev = NULL;
 
   delay = Tick2Time(Tick() - handle->currentWriteFrame->tick);
   if(delay > (handle->currentJitterTime + Msec2Time(20)))
   {
      if(handle->oldestFrame != NULL)
      {
         kal_uint32 shrinkState = 0;
         kal_uint32 delayDiff = delay - handle->currentJitterTime;
   
         handle->consecutiveEarlyPacket ++;
         if((handle->consecutiveEarlyPacket == NUM_EARLY_PACKETS_BEFORE_FIRST_SHRINK) || 
            (handle->consecutiveEarlyPacket == (NUM_EARLY_PACKETS_BEFORE_FIRST_SHRINK+NUM_EARLY_PACKETS_BEFORE_LATER_SHRINK)))
         {
#if 1 /* Throw away the oldest frame */
            RTPJitterEntry *wastedFrame;
   
            wastedFrame = handle->oldestFrame;
            handle->oldestFrame = handle->oldestFrame->next;
            if(handle->oldestFrame == NULL)
               handle->newestFrame = NULL;
            else 
               handle->oldestFrame->prev = NULL;
   
            wastedFrame->next = handle->freeFrames;
            if(handle->freeFrames != NULL)
            {
               handle->freeFrames->prev = wastedFrame;
            }
            handle->freeFrames = wastedFrame;
            handle->currentDepth--;
#endif
            shrinkState = 1;
            if(handle->consecutiveEarlyPacket == (NUM_EARLY_PACKETS_BEFORE_FIRST_SHRINK+NUM_EARLY_PACKETS_BEFORE_LATER_SHRINK))
            {
               handle->consecutiveEarlyPacket = NUM_EARLY_PACKETS_BEFORE_FIRST_SHRINK;
               shrinkState = 2;
            }
            if(IS_VOIPEVL_LOGGING())
            {
               INF_VORTP_JITTER_SHRINK_STRUCT event;
               event.uSessionID = (UINT8)handle->rtpSessionId;
               event.uState = shrinkState & 0xf;
               event.uConfig = 0;
               event.uDelayDiff = (UINT16)delayDiff;
               VORTP_TRACE_EVENT(event, INF_VORTP_JITTER_SHRINK);
            }
         }
      }
   }
   else
   {
      if(IS_VOIPEVL_LOGGING())
      {
         if(handle->consecutiveEarlyPacket >= NUM_EARLY_PACKETS_BEFORE_FIRST_SHRINK)
         {
            INF_VORTP_JITTER_SHRINK_STRUCT event;
            event.uSessionID = (UINT8)handle->rtpSessionId;
            event.uState = 0;
            event.uConfig = 0;
            event.uDelayDiff = 0;
            VORTP_TRACE_EVENT(event, INF_VORTP_JITTER_SHRINK);
         }
      }
      handle->consecutiveEarlyPacket = 0;
   }

   {
      kal_uint16 seq_num = RTP_GetSequenceNumber( &handle->currentWriteFrame->rtp );
      kal_uint32 ts = RTP_GetTimestamp( &handle->currentWriteFrame->rtp );
      
      if(handle->lastSeqNumberInit == KAL_TRUE)
      {
         kal_int16 seq_num_diff = (kal_int16)(seq_num - handle->lastSeqNumber - 1);
         if(seq_num_diff > 0)
         {
            handle->packetsTooLate += (kal_uint8)seq_num_diff;
         }
      }
      handle->lastTimestamp = ts;
      handle->lastSeqNumber = seq_num;
      handle->lastSeqNumberInit = KAL_TRUE;
   }
 
   memcpy(rtpPacket, &handle->currentWriteFrame->rtp, sizeof(RTP_DataFrame));

L_RTPJitter_GetData_END:
   kal_give_mutex(RTPJitterMutex);

   _trace_jitter_info_( handle, handle->rtpSessionId );
   return isContinued;
}

#define RTPFifo
kal_uint32 RTPFifo_GetBufferSize( RTP_FIFO_HANDLE *handle )
{
   kal_uint32 bufferSizeRequiredPerEntry;

   bufferSizeRequiredPerEntry = (MIN_HEADER_SIZE + handle->maxPayloadSize + 3)&(~3);
   return( RTP_FIFO_SIZE*bufferSizeRequiredPerEntry );
}

kal_bool RTPFifo_Open( RTP_FIFO_HANDLE *handle, kal_uint8 *buffer, kal_uint32 *buffer_size ){
   kal_uint32 I;
   kal_uint32 *buffer_pool = (kal_uint32 *)buffer;

   for(I=0; I<RTP_FIFO_SIZE; I++)
      RTP_InitDataFrame(&handle->entry[I], handle->maxPayloadSize, &buffer_pool);
   
   handle->read = 0;
   handle->write = 0;

   *buffer_size = (kal_uint8 *)buffer_pool - buffer;
   return KAL_TRUE;
}

kal_bool RTPFifo_Close( RTP_FIFO_HANDLE *handle ){
   return KAL_TRUE;
}

kal_bool RTPFifo_IsFull( RTP_FIFO_HANDLE *handle ){ // for RTPFifo_PutData
   if((handle->write-handle->read)>=RTP_FIFO_SIZE)
      return KAL_TRUE; // full
   else
      return KAL_FALSE;
}

kal_bool RTPFifo_IsEmpty( RTP_FIFO_HANDLE *handle ){ // for RTPFifo_GetData
   if(handle->read==handle->write)
      return KAL_TRUE; // empty
   else
      return KAL_FALSE;
}

kal_bool RTPFifo_PutData( RTP_FIFO_HANDLE *handle, const RTP_DataFrame *rtpPacket ){
   if((handle->write-handle->read)>=RTP_FIFO_SIZE)
      return KAL_FALSE;
   
   RTP_DuplicatePacket(&(handle->entry[handle->write&(RTP_FIFO_SIZE-1)]), rtpPacket);
   handle->write ++;
   
   return KAL_TRUE;
}

kal_bool RTPFifo_GetData( RTP_FIFO_HANDLE *handle, RTP_DataFrame *rtpPacket ){
   if(handle->read==handle->write)
      return KAL_FALSE;
   
   memcpy(rtpPacket, &(handle->entry[handle->read&(RTP_FIFO_SIZE-1)]), sizeof(RTP_DataFrame));
   handle->read ++;
   
   return KAL_TRUE;
}

#define RTPMethod
void RTP_SetContribSource(RTP_DataFrame *rtp, kal_int32 idx, kal_uint32 src) {
   ASSERT( idx <= 15 );

   if (idx >= RTP_GetContribSrcCount(rtp)) {
      kal_uint8 *oldPayload = RTP_GetPayloadPtr(rtp);
      rtp->theArray[0] &= 0xf0;
      rtp->theArray[0] |= idx+1;
      rtp->packetSize = RTP_GetHeaderSize(rtp) + rtp->payloadSize;
      memmove(RTP_GetPayloadPtr(rtp), oldPayload, rtp->payloadSize);
   }

   ((kal_uint32 *)&(rtp->theArray[MIN_HEADER_SIZE]))[idx] = src;
}

void RTP_InitDataFrame(RTP_DataFrame *rtp, kal_uint32 maxPayloadSize, kal_uint32 **buffer_pool){
   rtp->theArray = (kal_uint8 *)*buffer_pool; *buffer_pool += (MIN_HEADER_SIZE+maxPayloadSize+3)/4;
   rtp->theArraySize = MIN_HEADER_SIZE+maxPayloadSize;
   memset(rtp->theArray, 0, rtp->theArraySize);
   rtp->theArray[0] = 0x80; // set protocol version to 2
   rtp->packetSize = 0;
   rtp->payloadSize = 0;
   rtp->tick = 0xffffffff;
}

void RTP_AssociatePacket(RTP_DataFrame *rtp, const kal_uint8 *packetBuf, kal_uint32 packetLen){
   kal_int32 padding;
   rtp->theArray = (kal_uint8 *)packetBuf;
   rtp->theArraySize = rtp->packetSize = packetLen;
   padding = RTP_GetPaddingSize(rtp);
   RTP_SetPayloadSize(rtp, packetLen-RTP_GetHeaderSize(rtp)-padding);
}

void RTP_DuplicatePacket(RTP_DataFrame *dest, const RTP_DataFrame *src){ // dest should be initialized first
   int count = src->packetSize;
   if( src->packetSize > dest->theArraySize )
   {
      kal_prompt_trace(MOD_L1SP, "[VoRTP] Warning: src packet size = %d, dest array size = %d\n", 
         src->packetSize, dest->theArraySize);
      count = dest->theArraySize;
   }
   //ASSERT(src->packetSize <= dest->theArraySize);
   memcpy(dest->theArray, src->theArray, count);
   if(count == src->packetSize)
   {
      dest->packetSize = src->packetSize;
      dest->payloadSize = src->payloadSize;
   }
   else
   {
      dest->packetSize = count;
      dest->payloadSize = count - MIN_HEADER_SIZE;
   }
   dest->tick = src->tick;
}


RTP_SendReceiveStatus RTP_ReceiveData(RTP_DataFrame *rtp, const kal_uint8 *packetBuf, kal_uint32 packetLen){
   if(packetBuf==NULL || packetLen<MIN_HEADER_SIZE)
      return e_IgnorePacket;

   RTP_AssociatePacket(rtp, packetBuf, packetLen);
   return e_ProcessPacket;
}

kal_bool RTP_isSIDPacket(RTP_DataFrame *rtp, int maxSIDPayloadSize)
{
   return(rtp->payloadSize<=maxSIDPayloadSize);
}

#endif

