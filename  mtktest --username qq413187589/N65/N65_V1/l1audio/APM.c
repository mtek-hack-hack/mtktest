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
 *   APM.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Audio Post-Processing Manager to handle PCM bit-stream
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

#include "l1audio_def.h"

#if APM_SUPPORT

#include <string.h>
#include "am.h"
#include "kal_trace.h"
#include "l1sp_trc.h"
#include "apm_util.h"
#include "l1audio.h"
#include "dcmgr.h"
#include "sbc.h"

//---- Static structure ----
// MaxInputBufSize must be larger than MaxTempBufSize
// For 3D Surround, it needs more buffer because the block of 3D Surround is 4096 words
#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP) || defined(AUD_REVERB)
#define MaxSampleBufSize   12300
#else
#define MaxSampleBufSize   8200
#endif

#define MaxTempBufSize     2048
#define MaxTaskNum         32

#define PCMRUT_MASK       0x0080
#define PCMRUT_ON         0x0081

#define APM_BUFFERING_ENABLE   0
#define APM_BUFFERING_NUMBER   2048

// To handle the tone rampup or rampdown
#define APM_STATE_INIT     0
#define APM_STATE_OFF      1
#define APM_STATE_OFF2ON   2  
#define APM_STATE_ON       3
#define APM_STATE_ON2OFF   4

// To handle EOF, clear DSP buffer
#define APM_EOF_IDLE       0
#define APM_EOF_WAITING    1
#define APM_EOF_ENDING     2
#define APM_EOF_TAILING    3
#define APM_EOF_FINISH     4
#define APM_EOF_DONE       5

#define APM_EOF_WAIT_FRAME 0

// To handle overloading
#define APM_OVERLOAD_TIMES    3
#define APM_DELAY_FRAME_NUM  200


typedef struct APM_TaskNodeStruct {
   uint32     read;
   uint32     write;
   APM_TCM    tcm; 
   const APM_TASK_PARA *para;
} APM_NODE;

static struct {
   // Fields about APM control
   kal_bool   isTCMLoad;          // whether APM use TCM
   kal_bool   isRemainTCMOccupy;  // whether the remained TCM is occupied
   kal_bool   isHookHisr;         // whether HISHandle is hooked
   kal_semid  sema;
   int        aud_id;
   uint32     regTask;            // Bitwise, the registered task
   uint32     procTask;           // Bitwise, the task needed to process
   uint32     newTask;            // Bitwise, the new registered task
   uint32     delTask;            // Bitwise, the Un-Registered task
   uint32     tcmTask;            // Bitwise, the task needed TCM
   uint32     rwTask;             // Bitwise, the task which is not Read Only
   uint32     regLevel;           // Bitwise, the level had been registered
   APM_Info   info;               // Information of sample (frequebcy, type, and frame size)
   
   // To control the remained TCM buffer
   APM_TCM    remainTCM;
   
   // Debug information
   kal_uint16 frameSize;          // The frame size returned from DSP
   kal_uint16 asp_type;           // The Audio Signal Process Type
   
   // Field to handle tone, reset, AV sync and end of playback
   kal_bool   isReset;            // Whether the playback information is changed
   kal_bool   dropFlagInternal;
   kal_uint8  dropCount;
   kal_uint8  dropFrame;
   kal_bool   rampUp;
   kal_uint8  toneType;
   kal_uint8  toneState;
   kal_uint8  eofState;
   kal_uint8  eofWaitFrame;       // The number of frame had been waited
   kal_int8   eofLevel;
   short      rampGain;           // Ramp up gain
   short      numRemain;          // The number of remained samples at EOF
   uint32     delaySample;        // For AV sync
   void       *hdl;                       // Handle of Audio driver
   void       (*EofHandle)(void *data, Media_Event event);   // Hooked EOF Handle for audio
   Media_Event event;
   
   // The read/write buffer pointer of each post-process
   kal_uint8  taskNum;
   kal_uint8  map[MaxTaskNum];    // The map from ID to level
   APM_NODE   task[MaxTaskNum];
   APM_NODE   *tail;
   
   // Fields about buffer control
   int        read;
   int        write;
   int        rb_size;
   APM_Buffer bufInfo;
   short      SampleBuf[MaxSampleBufSize];
   short      tempInBuf[MaxTempBufSize];
   short      tempOutBuf[MaxTempBufSize];
} APM;


uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );


// ***** Static functions for Audio Post-Processing Manager In Task Level *****

//-------- Buffer Operation --------

__inline int GetReadDataCount(int startPos, int endPos, int size)
{
   int count;

   count = endPos - startPos;
   if (count < 0) {
      count += size;
   }
   return count;
}

// Get the successive data and place into APM.tempInBuf
static int GetReadDataToTempBuf(int startPos, int endPos, int bufSize)
{
   int count, segment;
   short *pTemp;

   count = endPos - startPos;
   if (count < 0)
      count += bufSize;

   if (count > MaxTempBufSize)
      count = MaxTempBufSize;

   // Process the first segment
   pTemp = APM.tempInBuf;
   segment = bufSize - startPos;
   if (segment > count)
      segment = count;
   memcpy(pTemp, APM.SampleBuf + startPos, segment*sizeof(short));
   pTemp += segment;

   // Process the second segment
   segment = count - segment;
   if (segment) {
      memcpy(pTemp, APM.SampleBuf, segment*sizeof(short));
   }

   return count;
}

// Save the tempBuf into Input Buffer
// The data is the input data for the next task
static int PutWriteDataFromTempBuf( int startPos, int endPos, int bufSize, int dataLen)
{
   int count, segment;
   short *pTemp;

   count = endPos - startPos;
   if (count < 0)
      count += bufSize;

   if (count > dataLen) {
      count = dataLen;
      kal_trace(TRACE_GROUP_APM, APM_TRUNCATE);
   }

   // Process the first segment
   pTemp = APM.tempOutBuf;
   segment = bufSize - startPos;
   if (segment > count)
      segment = count;
   memcpy(APM.SampleBuf + startPos, pTemp, segment*sizeof(short));
   pTemp += segment;

   // Process the second segment
   segment = count - segment;
   if (segment) {
      memcpy(APM.SampleBuf, pTemp, segment*sizeof(short));
   }

   return count;
}

//-------- Flow Control --------

//  To reset the read/write pointer
static void apm_ResetPtr( void )
{
   int i;
   APM_NODE *pTask;

   pTask = APM.task;
   for (i=APM.taskNum-1; i>=0; i--) {
      pTask->read = pTask->write = 0;
      pTask++;
   }
   kal_prompt_trace(MOD_L1SPHISR, "APM ClrBuf");
}

// To activate the new tasks
static void apm_ActivateTask(void)
{
   int i;
   uint32 newTaskCache;
   APM_NODE *pTask;

   kal_trace(TRACE_GROUP_APM, APM_ACTIVATE_INFO, APM.newTask, APM.info.sampleFreq, 1+(int)APM.info.isStereo);

#if defined(DYNAMIC_CODE_MANAGER)
   if ( !APM.isTCMLoad && (APM.tcmTask & APM.newTask) ) {
      DCM_Load( DYNAMIC_CODE_SBC, 0, 0 );
      APM.isTCMLoad = true;
   }
#endif

   pTask = APM.task;
   newTaskCache = APM.newTask;
   for (i=APM.taskNum-1; i>=0; i--) {
      if ( (1<<pTask->para->apm_Id) & newTaskCache ) {
         if (pTask->para->Activate != NULL) {
            kal_trace(TRACE_GROUP_APM, APM_ACTIVATING, pTask->para->apm_Id);
            pTask->para->Activate(&APM.info);
         }
      }
      pTask++;
   }
   APM.newTask = 0;
}

// To de-ctivate the del tasks
static void apm_DeActivateTask(void)
{
   int i;
   uint32 delTaskCache;
   APM_NODE *pTask;

   kal_trace(TRACE_GROUP_APM, APM_DEACTIVATE_INFO, APM.delTask);

   pTask = APM.task;
   delTaskCache = APM.delTask;
   for (i=APM.taskNum-1; i>=0; i--) {
      if ( (1<<pTask->para->apm_Id) & delTaskCache ) {
         if (pTask->para->Deactivate != NULL) {
            kal_trace(TRACE_GROUP_APM, APM_DEACTIVATING, pTask->para->apm_Id);
            pTask->para->Deactivate();
         }
      }
      pTask++;
   }
   APM.delTask = 0;
   
#if defined(DYNAMIC_CODE_MANAGER)
   if ( APM.isTCMLoad && !(APM.tcmTask&APM.regTask) && !(APM.isRemainTCMOccupy)) {
      DCM_Unload( DYNAMIC_CODE_SBC );
      APM.isTCMLoad = false;
   }
#endif
}

// To update the EOF level
// Set as the next registered level
static void apm_UpdateEofLevel(void)
{
   int i;

   for (i=APM.eofLevel+1; i<32; i++) {
      if ( APM.regLevel & (1<<i) )
         break;
   }
   APM.eofLevel = i;
}


/*
 *  ------------------------------------------------
 *  |          Input Buffer                         |
 *  ------------------------------------------------
 *     |       |                   |            |
 *     |    PP write            PP read         |
 *  witePos                                 readBND (the boundary of source data)
 *
 *  To control flow of function call and feed PCM to each post-process
 *  (1) Activate the new post-processes
 *  (2) Process the registered post-processes
 *  (3) Deactivate the del post-processes (un-registered)
 */

static void AudioPP_Manager( void *data )
{
   APM_NODE *pTask;
   int readBND;         // The boundary of available read data from task's view
   int count, bufSize;
   int i;

   kal_take_sem( APM.sema, KAL_INFINITE_WAIT );

   // Reset the initial state of task if needed
   if (APM.isReset) {
      apm_ResetPtr();
      APM.isReset = false;
   }

   // To Activate the registered task
   if (APM.newTask)
      apm_ActivateTask();

   //---- Process Input Buffer ----
   pTask = APM.task;
   readBND = APM.write;
   bufSize = APM.rb_size;
   // Process each task
   for (i=APM.taskNum-1; i>=0; i--) {
      if (APM.dropFlagInternal)
         break;
      
      if ( (1<<pTask->para->apm_Id) & APM.procTask ) {
         /* The process is enabled */
         kal_bool fContinue;
         
         // Check EOF
         APM.info.isEOF = false;
         fContinue = true;
         count = GetReadDataCount(pTask->read, readBND, bufSize);

         if (pTask->para->level < APM.eofLevel) {
            // Skip the post-process
            fContinue = false;
            APM.procTask &= ~(1<<pTask->para->apm_Id);
            pTask->write = readBND;
         }
         
         while ( (fContinue) && (count || APM.info.isChange) && (!APM.dropFlagInternal) ) {
            uint32 oriInLen, incCount;
            
            // Get the successive data and place into APM.tempInBuf
            oriInLen = GetReadDataToTempBuf(pTask->read, readBND, bufSize);
            APM.bufInfo.inBufLen = APM.bufInfo.outBufLen = oriInLen;
            APM.bufInfo.inBuf = APM.tempInBuf;
            APM.bufInfo.outBuf = APM.tempOutBuf;
            
            // EOF checking
            if ( (pTask->para->level==APM.eofLevel) && (count<=MaxTempBufSize) )
               APM.info.isEOF = true;

            // Process the data in APM.tempInBuf
            {
               kal_bool fEOF;
               
               fEOF = pTask->para->Process(&APM.bufInfo, &APM.info);
               
               // Update the EOF level if the process finished the tail of playback
               if ( (fEOF) && (pTask->para->level==APM.eofLevel) ) {
                  APM.procTask &= ~(1<<pTask->para->apm_Id);
                  apm_UpdateEofLevel();
               }
            }
            
            // Check the number of produced/consumed data is legal
            ASSERT(oriInLen >= APM.bufInfo.inBufLen);
            if (APM.eofState >= APM_EOF_ENDING) {
               if (APM.bufInfo.outBufLen >= APM.bufInfo.inBufLen)
                  incCount = APM.bufInfo.outBufLen;
               else
                  incCount = APM.bufInfo.inBufLen;
            } else {
               // Check the amount of produced and consumed data
               if ( pTask->para->property != APM_PROPERTY_READ_ONLY ) {
                  ASSERT(APM.bufInfo.inBufLen == APM.bufInfo.outBufLen);
               }
               incCount = APM.bufInfo.inBufLen;
            }
            
            if ( !APM.dropFlagInternal ) {
               // Update the number of remained data, and check whether continue to feed data
               count -= (int)incCount;
               fContinue = (incCount == 0)? false : true;
             
               // Update task read / write pointer
               // Save the result to APM.InputBuf as the input of next task
               pTask->read += incCount;    // APM.bufInfo.inBufLen
               if (pTask->read >= bufSize)
                  pTask->read -= bufSize;
               
               if ( pTask->para->property != APM_PROPERTY_READ_ONLY ) {
                  PutWriteDataFromTempBuf(pTask->write, pTask->read, bufSize, APM.bufInfo.outBufLen);
               }
               
               pTask->write += incCount;   // APM.bufInfo.outBufLen
               if (pTask->write >= bufSize)
                  pTask->write -= bufSize;
            }
         }
         // Update the boundary of read pointer of source data for the next task
         readBND = pTask->write;
      } else {
         // The process doesn't enable, we only have to update the pointer
         pTask->read = pTask->write = readBND;
      }

      pTask++;
   }
   
   // To Activate the registered task
   if (APM.delTask)
      apm_DeActivateTask();

   // EOF handling
   if ( ((APM.regTask==0)||(APM.eofLevel==32)) &&
   	    ((APM.eofState==APM_EOF_WAITING) || (APM.eofState==APM_EOF_ENDING)) ) {
      int dataCnt;
      
      dataCnt = APM.tail->write - APM.read;
      if (dataCnt < 0)
         dataCnt += MaxSampleBufSize;
      
      APM.eofState = APM_EOF_TAILING;
      APM.numRemain = dataCnt;
   }

   if ( (APM.eofState == APM_EOF_FINISH) ) {
      APM.eofState = APM_EOF_DONE;
      APM.EofHandle(APM.hdl, APM.event);
   }

   // Unload TCM at playbackoff
#if defined(DYNAMIC_CODE_MANAGER)
   if ( (APM.isTCMLoad) && (APM.eofState==APM_EOF_DONE) && !(APM.isRemainTCMOccupy) ) {
      DCM_Unload( DYNAMIC_CODE_SBC );
      APM.isTCMLoad = false;
   }
#endif

   APM.info.isChange = false;
   
   if (APM.dropFlagInternal) {
      APM.dropFrame++;
      if (APM.dropFrame == 1) {
         int i;
         APM_NODE *pTask;   
         uint32 savedMask;

         // To deactivate all registered tasks
         savedMask = SaveAndSetIRQMask();
         APM.read = APM.write = 0;
         RestoreIRQMask( savedMask );

         pTask = APM.task;
         for (i=APM.taskNum-1; i>=0; i--) {
            pTask->read = pTask->write = 0;
            pTask++;
         }
      } else if (APM.dropFrame > APM_DELAY_FRAME_NUM) {
         APM.dropFlagInternal = false;
         APM.dropCount = 0;
         APM.dropFrame = 0;
      }
   }
   
   kal_give_sem( APM.sema );
}


// ***** Static functions for PCM Routing In HISR Level *****
//---- Buffer Control ----
static kal_bool apm_WriteToDSP_RampUp(short *readPtr, int len, short *gain)
{
   int i, segment;
   int tempGain;

   if (len == 0)
      return true;

   tempGain = *gain;
   segment = 1024 - tempGain;
   if (segment > len)
      segment = len;

   for (i=segment-1; i>=0; i--) {
      *IDMA_SHORT_ADDR = (tempGain++)*(*readPtr++)>>10;
   }

   if (segment < len) {
      // If the rampup segment is finished, write the original data
      for (i=len-segment-1; i>=0; i--)
         *IDMA_SHORT_ADDR = *readPtr++;
   }

   *gain = tempGain;
   if (tempGain >= 1024)
      return false;
   else
      return true;
}



//-------- HISR Level --------
static void apm_ReadFromDSP( uint16 bufAddr, uint16 pageNum, uint16 dataLen, int toneOn )
{
   int count, segment, i;
   int16 *writePtr;

   // While tone is on and DSP doesn't decode, APM doesn't get/write data from/to DSP
   if (toneOn) {
      APM.rampUp = true;
      APM.rampGain = 0;
      if (APM.toneType==2)
         return;
   }

   // Get the size of free space in APM.DSP_Buf
   // The size should be even
   count = APM.read - APM.write - 2;
   if (count < 0)
      count += APM.rb_size;
   if (APM.info.isStereo)
      count = (count & ~0x0001);

   // Compare with dataLen
   if (count >= dataLen) {
      count = dataLen;
   } else {
      kal_prompt_trace( MOD_L1SPHISR, "APM_IN OVFLOW");
   }

   //-- First segment
   segment = APM.rb_size - APM.write;
   if (segment > count)
      segment = count;
   
   // dummy read
   i = *DSP_DM_ADDR(pageNum, bufAddr);
   // Get data from DSP
   writePtr = APM.SampleBuf + APM.write;
   if (APM.eofState >= APM_EOF_ENDING) {
      memset(writePtr, 0, segment*sizeof(short));
   } else {
      for (i=segment-1; i>=0; i--) {
         *writePtr++ = (int16)(*IDMA_SHORT_ADDR);
      }
   }
   APM.write += segment;
   if (APM.write >= APM.rb_size)
      APM.write = 0;
   
   //-- Second segment
   segment = count - segment;
   if (segment > 0) {
      writePtr = APM.SampleBuf;
      if (APM.eofState >= APM_EOF_ENDING) {
         memset(writePtr, 0, segment*sizeof(short));
      } else {
         for (i=segment-1; i>=0; i--) {
            *writePtr++ = (int16)(*IDMA_SHORT_ADDR);
         }
      }
      APM.write = segment;
   }
}

static void apm_WriteToDSP( uint16 bufAddr, uint16 pageNum, uint16 dataLen, int toneOn )
{
   int count, segment, i;
   int16 *readPtr;

   ASSERT(APM.tail != NULL);

   if (APM.eofState == APM_EOF_TAILING) {
      APM.numRemain -= dataLen;
      if (APM.numRemain <= 0)
         APM.eofState = APM_EOF_FINISH;
   }

   // If all tasks are Read-Only, then APM needn't write data to DSP
   if ( (APM.rwTask & APM.regTask) == 0 ) {
      APM.read = APM.tail->write;
      return;
   }

   // Get the data amount of APM.MCU_Buf
   if (APM.isReset || APM.dropFlagInternal)
      count = 0;
   else
      count = APM.tail->write - APM.read;
   
   if (count < 0)
      count += APM.rb_size;
   if (APM.info.isStereo)
      count = (count & ~0x0001);

#if APM_BUFFERING_ENABLE
   if ( (count < APM_BUFFERING_NUMBER) && (APM.eofState != APM_EOF_TAILING) ) {
      count = 0;
   }
#endif

   if (APM.dropFlagInternal)
      count = 0;

   // Compare with dataLen
   if (count >= dataLen) {
      count = dataLen;
      APM.dropCount = 0;
   } else if (APM.eofState < APM_EOF_TAILING) {
      count = 0;
      kal_prompt_trace( MOD_L1SPHISR, "APM_OUT UDFLOW");
      if (APM.read != 0) {
         APM.dropCount++;
         if (APM.dropCount == APM_OVERLOAD_TIMES)
            APM.dropFlagInternal = true;
      }
   }

   // Do not write data to DSP if key tone is turnon
   if (toneOn) {
      // If DSP decodes, we drop the data in APM
      if (APM.toneType != 2) {
         APM.read += count;
         if (APM.read >= APM.rb_size)
            APM.read -= APM.rb_size;
      }
      
      // If the media format is audio, write zero to DSP to avoid the noise at tone playbackoff
      count = 0;
   }

   //-- First segment
   segment = APM.rb_size - APM.read;
   if (segment > count)
      segment = count;
   
   // Write data to DSP
   readPtr = APM.SampleBuf + APM.read;
   if (segment > 0) {
      if (APM.rampUp) {
         *DSP_DM_ADDR(pageNum, bufAddr) = (APM.rampGain++)*(*readPtr++)>>10;
         APM.rampUp = apm_WriteToDSP_RampUp(readPtr, segment-1, &APM.rampGain);   // Rampup 1024 samples
         if (APM.rampGain >= 1024)
            APM.rampUp = false;
      } else {
         *DSP_DM_ADDR(pageNum, bufAddr) = *readPtr++;
         for (i=segment-2; i>=0; i--)
            *IDMA_SHORT_ADDR = *readPtr++;
      }
   }
   APM.read += segment;
   if (APM.read >= APM.rb_size)
      APM.read = 0;
   
   //-- Second segment
   segment = count - segment;
   if (segment > 0) {
      readPtr = APM.SampleBuf;
      if (APM.rampUp) {
         apm_WriteToDSP_RampUp(readPtr, segment, &APM.rampGain);   // Rampup 1024 samples
         if (APM.rampGain >= 1024)
            APM.rampUp = false;
      } else {
         for (i=segment-1; i>=0; i--)
            *IDMA_SHORT_ADDR = *readPtr++;
      }
      APM.read += segment;
   }
   
   // Put silence if MCU buffer is empty
   if (count < dataLen) {
      // Write zero to DSP
      segment = dataLen - count;
      APM.delaySample += segment;
      if (count == 0) {
         *DSP_DM_ADDR(pageNum, bufAddr) = 0;
         segment--;
      }
      for (i=segment-1; i>=0; i--) {
         *IDMA_SHORT_ADDR = 0;
      }
   }
}


static void pcmrut_hisr( void *data )
{
   uint16 bufAddr, pageNum, dataLen;
   int channelNum, toneOn;

#if defined(MT6225)
   ASSERT( ((*DP2_AUDIO_PP_CTRL)&0x0040)==0 );
#endif

   if (APM.eofState == APM_EOF_WAITING) {
      APM.eofWaitFrame++;
      if (APM.eofWaitFrame > APM_EOF_WAIT_FRAME) {
         APM.eofState = APM_EOF_ENDING;
         APM.eofLevel = 0;
         apm_UpdateEofLevel();
      }
   }

   if (APM.regTask == 0) {
      if ((APM.eofState != APM_EOF_IDLE) && (APM.eofState != APM_EOF_DONE)) {
         APM.eofState = APM_EOF_FINISH;
         L1Audio_SetEvent( APM.aud_id, (void *) 0 );
      }
      switch (APM.toneState) {
         case APM_STATE_INIT:
            APM.toneState = APM_STATE_OFF;
            return;
         case APM_STATE_OFF:
            return;
         case APM_STATE_OFF2ON:
         case APM_STATE_ON:
         case APM_STATE_ON2OFF:
            if (!APM.rampUp) {
               APM.toneState = APM_STATE_OFF;
               APM.read = APM.write = 0;
               apm_ResetPtr();
               return;
            }
            // Should do ramp down
            break;
      }
   } else {
      switch (APM.toneState) {
         case APM_STATE_INIT:
            APM.toneState = APM_STATE_ON;
            break;
         case APM_STATE_OFF:
            APM.toneState = APM_STATE_OFF2ON;
            APM.rampUp = true;
            APM.rampGain = 0;
            break;
         case APM_STATE_OFF2ON:
            if (!APM.rampUp)
               APM.toneState = APM_STATE_ON;
            break;
         case APM_STATE_ON:
         case APM_STATE_ON2OFF:
            break;
      }
   }

   if ((*DP2_AUDIO_PP_CTRL & 0x0081) != 0x0081)
      return;

   bufAddr = (*PCMRUT_BUF_ADDR) & 0x3FFF;
   pageNum = ((*PCMRUT_BUF_ADDR) >> 14) & 0x0003;
   dataLen = (*PCMRUT_BUF_LENGTH) & 0x3FFF;
   channelNum = ((*PCMRUT_BUF_LENGTH) >> 15) & 0x0001;
   if (DSP_TONE_CTRL1 || DSP_TONE_CTRL2) {
      toneOn = 1;
   } else {
      toneOn = 0;
   }
   
   if (APM.isReset) {
      APM.info.isStereo = channelNum;
   } else if ( (APM.info.isStereo != channelNum)||(APM.frameSize != dataLen) ) {
      APM.read = APM.write = 0;
      APM.tail->write = 0;
      APM.info.isChange = true;
      APM.info.isStereo = channelNum;
      APM.isReset = true;
   }
   
   APM.frameSize = dataLen;

   apm_ReadFromDSP(bufAddr, pageNum, dataLen, toneOn);
   apm_WriteToDSP(bufAddr, pageNum, dataLen, toneOn);

   if (APM.dropFlagInternal) {
      APM.read = APM.write = 0;
   }

   L1Audio_SetEvent( APM.aud_id, (void *) 0 );
}


//-------- L1audio Internal Use --------

/*
 *  Initialize the state and data of PCM Route
 *  Link all post process in the linked list
 */
extern const APM_TASK_PARA *apmTaskList[];
void APM_Init( void )
{
   int i;
   int level;
   uint32 validTcmSize;
   uint32 *TcmBuf;
   uint32 levelSize[32];   // The maximal TCM size in each level

   memset(&APM, 0, sizeof(APM));
   APM.sema      = kal_create_sem( "APM_Sema", 1 );
   APM.rb_size = MaxSampleBufSize;
   APM.bufInfo.inBuf = APM.tempInBuf;
   APM.bufInfo.outBuf = APM.tempOutBuf;

   //-- Two phase pass
   // Phase 1: to check the argument, and find out the maximal TCM size in each level
   level = 0;
   memset(levelSize, 0, 32*sizeof(uint32));
   for (i=0; apmTaskList[i]!=NULL; i++) {
      uint8 tempID, tempLevel;
      
      // The maximal number is 32
      ASSERT(i<32);
      
      tempID = apmTaskList[i]->apm_Id;
      tempLevel = apmTaskList[i]->level;
      ASSERT(tempID<32);
      ASSERT(tempLevel<32);
      ASSERT(level <= tempLevel);
      // Hook task
      APM.task[i].para = apmTaskList[i];
      APM.map[tempID] = tempLevel;
      level = tempLevel;
      
      if (apmTaskList[i]->property == APM_PROPERTY_READ_WRITE)
         APM.rwTask |= (1<<tempID);
      
      if (apmTaskList[i]->tcmSize > levelSize[tempLevel])
         levelSize[tempLevel] = apmTaskList[i]->tcmSize;
   }
   APM.taskNum = i;
   if (i>0) {
      APM.tail = &APM.task[i-1];
   } else {
      APM.tail = &APM.task[0];
   }
   
   // Phase 2: to assign TCM and initialize
   TcmBuf = NULL;
   validTcmSize = 0;
   level = apmTaskList[0]->level;
#if defined(DYNAMIC_CODE_MANAGER)
   DCM_Load( DYNAMIC_CODE_SBC, &TcmBuf, &validTcmSize );
   DCM_Unload(DYNAMIC_CODE_SBC);
#endif

   for (i=0; apmTaskList[i]!=NULL; i++) {
#if defined(DYNAMIC_CODE_MANAGER)
      uint8 tempID, tempLevel;
      uint32 tempSize;

      // Update TCM buffer and size
      tempID = apmTaskList[i]->apm_Id;
      tempLevel = apmTaskList[i]->level;
      if (level != tempLevel) {
         tempSize = (levelSize[level]+3)>>2;
         level = tempLevel;
         TcmBuf += tempSize;
         validTcmSize -= (tempSize<<2);
      }
      
      // Assing TCM buffer
      ASSERT(validTcmSize >= apmTaskList[i]->tcmSize);
      if (apmTaskList[i]->tcmSize > 0) {
         APM.tcmTask |= (1<<tempID);
         APM.task[i].tcm.tcmBuf = TcmBuf;
         APM.task[i].tcm.tcmBufLen = levelSize[tempLevel];
      }
      else
#endif
      {
         APM.task[i].tcm.tcmBuf = NULL;
         APM.task[i].tcm.tcmBufLen = 0;
      }

      if (apmTaskList[i]->Init != NULL)
         apmTaskList[i]->Init(&APM.task[i].tcm);
   }

#if defined(DYNAMIC_CODE_MANAGER)
   if (APM.taskNum>0) {
      uint32 tempSize;
      
      tempSize = (levelSize[level]+3)>>2;
      TcmBuf += tempSize;
      validTcmSize -= (tempSize<<2);
   }
#endif
   
   APM.remainTCM.tcmBuf = TcmBuf;
   APM.remainTCM.tcmBufLen = validTcmSize;

   APM.aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( APM.aud_id, AudioPP_Manager );
}

/*
 *  Activate DSP to route PCM data to MCU
 *  Set the value of the related sherif
 */
void APM_Activate( short asp_type, short freqInd)
{
   int freq;
   
      APM.asp_type = asp_type;

   // Set the process type while warning tone is on
   if ((asp_type==ASP_TYPE_PCM_HI)||(asp_type==ASP_TYPE_MELODY_16K)||(asp_type==ASP_TYPE_AMR)) {
      // WAV, MIDI, AMR : DSP continues to decode
      // So, APM should get data from DSP, consume buffer, and write zero to DSP
      APM.toneType = 1;
   } else {
      // DAF, AAC, AAC_Plus, WMA : DSP doesn't decode
      // So, APM should not get/write data from/to DSP, and write zero to DSP
      APM.toneType = 2;
   }
   
   // Convert frequency index to frequency
   // Keep the information to notify task in future
   switch (freqInd) {
      case 0x00:  freq =  8000;  break;
      case 0x11:  freq = 11025;  break;
      case 0x12:  freq = 12000;  break;
      case 0x20:  freq = 16000;  break;
      case 0x21:  freq = 22050;  break;
      case 0x22:  freq = 24000;  break;
      case 0x40:  freq = 32000;  break;
      case 0x41:  freq = 44100;  break;
      case 0x42:  freq = 48000;  break;
      default:
         freq = 0;    // Avoid compile warning
         ASSERT(0);   // Unknown
   }
   APM.info.sampleFreq = freq;

   L1Audio_HookHisrHandler(DP_D2C_PCM_RUT, pcmrut_hisr, 0);
   APM.isHookHisr = true;

   APM.delTask = 0;
   APM.newTask = APM.regTask;
   APM.procTask = APM.regTask;
   APM.eofLevel = -1;
   APM.delaySample = 0;

   APM.isReset = true;
   APM.dropFlagInternal = false;
   APM.dropCount = 0;
   APM.dropFrame = 0;
   APM.rampUp = false;
   APM.rampGain = 0;
   APM.toneState = APM_STATE_INIT;
   APM.eofState = APM_EOF_IDLE;
   APM.eofWaitFrame = 0;
   APM.hdl = NULL;
   APM.EofHandle = NULL;
   APM.read = APM.write = 0;
   APM.tail->write = 0;
   APM.info.isChange = true;
   AM_SetPostProcessCtrl( PCMRUT_MASK, PCMRUT_ON);
}

/*
 *  Deactivate DSP to route PCM data to MCU
 *  Clear the value of the related sherif
 *  The work of deactivating all post-process is done in L1Audio task in later time
 */
void APM_Deactivate(void)
{
   uint32 savedMask;

   AM_ClearPostProcessCtrl( PCMRUT_MASK );

   // To deactivate all registered tasks
   savedMask = SaveAndSetIRQMask();
   APM.procTask = 0;
   APM.delTask = APM.regTask;
   APM.eofState = APM_EOF_DONE;
   APM.read = APM.write = 0;
   APM.tail->write = 0;
   APM.dropFlagInternal = false;
   APM.dropCount = 0;
   APM.dropFrame = 0;
   RestoreIRQMask( savedMask );
   
   // Notify APM to deactivate all post process
   L1Audio_SetEvent( APM.aud_id, (void *) 0 );
   
   if (APM.isHookHisr) {
      APM.isHookHisr = false;
      L1Audio_UnhookHisrHandler( DP_D2C_PCM_RUT );
   }
}

/*
 *  To clear all buffer of APM when the speed is changed by Time Stretch
 */
void APM_ClearBuffer(void)
{
   uint32 savedMask;
   int i;
   APM_NODE *pTask;   
   
   kal_take_sem( APM.sema, KAL_INFINITE_WAIT );
   
   savedMask = SaveAndSetIRQMask();
   APM.read = APM.write = 0;
   pTask = APM.task;
   for (i=APM.taskNum-1; i>=0; i--) {
      pTask->read = pTask->write = 0;
      pTask++;
   }
   RestoreIRQMask( savedMask );
   
   kal_give_sem( APM.sema );
}

// For AV-Sync
kal_int32 APM_AV_DelayCount(void)
{
   int numInt, tempSample;
   
   tempSample = APM.delaySample;
   numInt = tempSample / 6;
   APM.delaySample = tempSample - (numInt*6);
   
   return numInt;
}

void APM_AV_ConsumeDelay(kal_int32 numInt)
{
   numInt = numInt*6;
   if (APM.delaySample >= numInt)
      APM.delaySample -= (numInt*6);
   else
      APM.delaySample = 0;
}


void APM_NOTIFY_MEDIA_END(void (*HookFunc)(void *data, Media_Event event), void *data, kal_bool isNew, Media_Event event)
{
   kal_bool immediate;

   APM.event = event;
   immediate = false;
   if ( (APM.regTask == 0) || (AM_IsAudioPlaybackOn()==-1) ) {
      immediate = true;
   } else {
      if (APM.eofState != APM_EOF_IDLE)
         return;
      
      if (isNew) {
         MHdl *hdl;
         Media_Format mediaType;
         
         hdl = (MHdl *)data;
         mediaType = hdl->mediaType;
         // Bypass the event if it is VM format
         if ( (mediaType == MEDIA_FORMAT_GSM_EFR) ||
              (mediaType == MEDIA_FORMAT_VRD) ||
              (mediaType == MEDIA_FORMAT_VRSI) ) {
            immediate = true;
         }
      }
   }
   
   if (immediate) {
      APM.eofState = APM_EOF_DONE;
      HookFunc(data, event);
   } else {
      APM.hdl = data;
      APM.EofHandle = HookFunc;
      APM.eofState = APM_EOF_WAITING;
   }
}

void APM_EXECUTE_END_HANDLER(void)
{
   if (APM.eofState == APM_EOF_DONE)
      return;

   if (APM.EofHandle != NULL) {
      APM.eofState = APM_EOF_DONE;
      APM.EofHandle(APM.hdl, APM.event);
   }
}

/*
 *  To assign the remained TCM buffer
 *  Only one block of memory is provided
 *  Return:
 *	    the buffer address, if the size is enough
 *	    NULL, otherwise
 */
kal_uint8 *APM_Allocate_Buffer(uint32 bufSize)
{
   
#if defined(DYNAMIC_CODE_MANAGER)
   if (APM.isRemainTCMOccupy)
      return NULL;
   
   if (APM.remainTCM.tcmBufLen < bufSize) {
      return NULL;
   } else {
      kal_take_sem( APM.sema, KAL_INFINITE_WAIT );
      APM.isRemainTCMOccupy = true;
      if ( !APM.isTCMLoad ) {
         DCM_Load( DYNAMIC_CODE_SBC, 0, 0 );
         APM.isTCMLoad = true;
      }
      kal_give_sem( APM.sema );
      return (kal_uint8 *)APM.remainTCM.tcmBuf;
   }
#else
   return NULL;
#endif
}

/*
 *  To release the remained TCM buffer
 */
void APM_Release_Buffer(void)
{
   kal_take_sem( APM.sema, KAL_INFINITE_WAIT );

#if defined(DYNAMIC_CODE_MANAGER)
   if ( APM.isTCMLoad &&
        ( (APM.eofState==APM_EOF_DONE) || !(APM.tcmTask&APM.regTask) ) ) {
      DCM_Unload( DYNAMIC_CODE_SBC );
      APM.isTCMLoad = false;
   }
#endif
   APM.isRemainTCMOccupy = false;

   kal_give_sem( APM.sema );
}

// ***** API for HOST Post-Process *****

/*
 *  To registry process ID to APM
 *    Then APM wil be activated, and APM will feed data to the post-process
 *  The goal of registry is to reduce data movement and to save power consumption
 *  If there is no registered process, APM doesn't need to move data from/to DSP
 */
void HOST_APM_Register(APM_TaskID taskID)
{
   uint32 savedMask;
   
   //kal_trace(TRACE_GROUP_APM, APM_REGISTER, taskID, APM.regTask);
   kal_prompt_trace(MOD_L1SPHISR, "APM RegID %d, OriTask %d", taskID, APM.regTask);
   
   ASSERT( taskID<32 );
   
   if ( (APM.regTask & (1<<taskID))==0 ) {
      ASSERT( (APM.regLevel & (1<<APM.map[taskID])) == 0);
      savedMask = SaveAndSetIRQMask();
      APM.regTask |= (1<<taskID);
      APM.procTask |= (1<<taskID);
      APM.newTask |= (1<<taskID);
      APM.delTask &= ~(1<<taskID);
      APM.regLevel |= (1<<APM.map[taskID]);
      RestoreIRQMask( savedMask );
   }
}

/*
 *  To un-registry process ID to APM
 *  The goal of registry is to reduce data movement and to save power consumption
 *  If there is no registered process, APM doesn't need to move data from/to DSP
 */
void HOST_APM_UnRegister(APM_TaskID taskID)
{
   uint32 savedMask;
   
   //kal_trace(TRACE_GROUP_APM, APM_UNREGISTER, taskID, APM.regTask);
   kal_prompt_trace(MOD_L1SPHISR, "APM UnRegID %d, OriTask %d", taskID, APM.regTask);
   
   ASSERT( taskID<32 );
   
   savedMask = SaveAndSetIRQMask();   
   if (APM.regTask & (1<<taskID)) {
      APM.regTask &= ~(1<<taskID);
      APM.procTask &= ~(1<<taskID);
      APM.newTask &= ~(1<<taskID);
      APM.delTask |= (1<<taskID);
      APM.regLevel &= ~(1<<APM.map[taskID]);
   }
   RestoreIRQMask( savedMask );
   
   // In order to deactivate the post-process, Unload TCM, and Close Audio Playback (if needed)
   // This is necessary to Unload TCM immediately
   // However, it is not timing critical to load TCM in HOST_APM_Register
   if ( (APM.delTask!=0) && (AM_IsAudioPlaybackOn()!=-1) ) {
      L1Audio_SetEvent( APM.aud_id, (void *) 0 );
   }
}

#else
// Dummy function for other chips

#include "l1audio.h"

kal_int32 APM_AV_DelayCount(void)
{
   return 0;
}

void APM_AV_ConsumeDelay(kal_int32 numInt)
{

}

#endif
