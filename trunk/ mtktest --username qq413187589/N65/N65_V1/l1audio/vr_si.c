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
 *   vr_si.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  VRSI  module  
 *
 * Author:
 * -------
 * -------
 *                      
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(VRSI_CYBERON) 

#include "kal_release.h" 
#include "fat_fs.h"  /* file system */
#include "media.h"  
#include "vr_si.h" 

#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225)
#define PAGE_NUM 0
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PAGE_NUM 2
#elif defined(MT6223) || defined(MT6223P)
#define PAGE_NUM 1
#endif

// VRSI state definition 
#define VRSI_STATE_IDLE  (1<<0)
#define VRSI_STATE_INITIALIZED (1<<1)
#define VRSI_STATE_READY (1<<2)
#define VRSI_STATE_ADD_TAGS (1<<3)
#define VRSI_STATE_TRAIN (1<<4)
#define VRSI_STATE_RECOG (1<<5)
#define VRSI_STATE_DIGIT_RECOG (1<<6)
#define VRSI_STATE_DIGIT_ADAPT (1<<7)
#define VRSI_STATE_TTS (1<<8)
#define VRSI_STATE_PLAY_TAG (1<<9)
#define VRSI_STATE_ABORT (1<<10)

// VRSI flags 
#define VRSI_PLAYING_FLAG  (1<<0)
#define VRSI_RECORDING_FLAG  (1<<1)
#define VRSI_GSMFR_PLAY_FLAG  (1<<2)
#define VRSI_TTS_PLAY_FLAG  (1<<3)
#define VRSI_WAITING_FLAG  (1<<4)
#define VRSI_PROCESS_FLAG  (1<<5)
#define VRSI_RESULT_FLAG   (1<<6) // set when has result , reset when another function start 
#define VRSI_PROMPT_FLAG (1<<7)
#define VRSI_OK_FLAG (1<<8) // prevent process timer time out before error or result 
#define VRSI_HISR_FLAG (1<<9) 
#define VRSI_HISR_STOP_RECORD_FLAG (1<<10) 

//#define VRSI_DEBUG
//#define VRSI_TTS_DEBUG  

#ifdef VRSI_DEBUG 
   static kal_wchar debugFile[50]; 
   static uint16 vrsiPcmDebugBuf[80000]; // for debug 
   static uint16 *pcmDebugPtr; // for debug 
   static uint32 pcmDebugCnt; 
   static uint16 pcmDebugFile = 0;
#endif    

#ifdef VRSI_TTS_DEBUG
   kal_uint32 driveIdx;
   static int32 tts_file_handle; 
   static kal_wchar ttsDebugFile[50]; 
   static uint16 tts_file_idx = 0;
#endif 

#define VRSI_NUM_FLASH_BLOCK 4  

typedef struct 
{
   BSRDBINFO bsrDB[VRSI_NUM_FLASH_BLOCK + 1]; 
   VRSI_AddTags_Result addTagsRes;
   VRSI_Recog_Result recogRes;
   VRSI_Digit_Recog_Result digitRecogRes;
   VRSI_Tag_Param *tag; // point to train-tag param kept in caller
   const uint16 *prompt;
   uint16 dataDir[30]; //*dataDir; 
   void (*vr_handler)( VRSI_Event event ); // evHandler, callback function
   uint16 digitRes[34];
   uint16 *tagNameRes[8];
   uint16 tagIdRes[8];
   int32 tagLongRes[8];
   uint16 *pcmBuf; // PCM data buffer for TTS playback 
   uint16 *packet; // GSMFR data buffer   
   void* audioParam; 
   uint16 state;    // VRSI task status      
   uint16 FLAGS;   
   uint16 funcState; // record function from entry until leave (change to another function)      
   uint16 promptLen; 
   uint16 aud_id;  
   VRSI_ErrMsg errMsg;                                                        
}VRSI_Struct; 

VRSI_Struct *vrsi;  // pointer to vrsi manager memory  
kal_timerid vrsiTimerID;

const unsigned char lpbyteBSR_DIGIT[4] = {
	0x05, 0x01, 0x00, 0x00, 
};

#define DP_D2C_SE_DONE     0xEE01

#define FRAME_BUF_SIZE     160

#if defined(MT6219) || defined(MT6217) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
#define DP_SE_PCM_BUF_SIZE 240
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_SE_PCM_BUF_SIZE 320
#endif

#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225)
#define DP_SE_PCM_BUF_ADDR 0x3E00 
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_SE_PCM_BUF_ADDR 0x3400 
#endif 

#if defined(MT6219)
#define DP_SE_PCM_BUF_PTR  0x2D10
#elif defined(MT6217) || defined(MT6226_S00) || defined(MT6226M_S00) || defined(MT6227_S00)
#define DP_SE_PCM_BUF_PTR  0x2D12
#elif defined(MT6226_S01) || defined(MT6226M_S01) || defined(MT6227_S01) || defined(MT6226_S02) || defined(MT6226M_S02) || defined(MT6227_S02)
#define DP_SE_PCM_BUF_PTR  0x302F
#elif defined(MT6227D) || defined(MT6226D)
#define DP_SE_PCM_BUF_PTR  0x3296
#elif defined(MT6228)
#define DP_SE_PCM_BUF_PTR  0x322E
#elif defined(MT6229_S00) || defined(MT6230_S00)
#define DP_SE_PCM_BUF_PTR  0x3911
#elif defined(MT6229_S01) || defined(MT6230_S01)
#define DP_SE_PCM_BUF_PTR  0x3928
#elif defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T)
#define DP_SE_PCM_BUF_PTR  0x3927
#elif defined(MT6235) || defined(MT6238)
#define DP_SE_PCM_BUF_PTR  0x3929
#elif defined(MT6225)
#define DP_SE_PCM_BUF_PTR  0x2E31
#elif defined(MT6223) || defined(MT6223P)
#define DP_SE_PCM_BUF_PTR  0x3840
#endif 


#define VR_PCM_INPUT

extern void ktLock( void );
extern void ktUnlock( void );  
extern void mdi_audio_vrsi_register_record(void);
extern void mdi_audio_vrsi_unregister_record(void);


void BSR_Assert(char *expr, uint32 info1, uint32 info2, uint32 info3)
{
   EXT_ASSERT(expr, info1, info2, info3);   
}

/*----------------  L1Audio Initialization & Service  -----------------------------*/


void vrsiInit(void) 
{
   vrsi = (VRSI_Struct *) 0;
   vrsiTimerID = kal_create_timer("VRSI");    
}
                                                                       
void vrsiPlayHandler( Media_Event event )
{   
   if(event == MEDIA_END) 
   {
      vrsi->state = VRSI_STATE_READY;
      if(vrsi->funcState == VRSI_STATE_PLAY_TAG)      
         vrsi->vr_handler(VRSI_PLAY_TAG_OK);              
      else if(vrsi->funcState == VRSI_STATE_TTS)               
         vrsi->vr_handler(VRSI_TTS_OK);
                                      
      vrsi->FLAGS &= ~VRSI_PLAYING_FLAG; 
      
      ktUnlock();
   }      
}

#define VRSI_CAPTURE_TIMER 1 
#define VRSI_PLAYBACK_TIMER 2
#define VRSI_PROCESS_TIMER 3
#define VRSI_QUICK_TIMER 4

void vrsiTimerHandler(void *param)
{
   uint32 data = (uint32)param;
   
   switch (data)
   {
      case VRSI_CAPTURE_TIMER:                   
      case VRSI_PLAYBACK_TIMER:                   
      case VRSI_PROCESS_TIMER:                   
      case VRSI_QUICK_TIMER:        
         L1Audio_LSetEvent(vrsi->aud_id, 0);
         break;                     
      default: 
         ASSERT(false);
   } 
      
}


void vrsiEventHandler(void *data)
{
	vrsi->vr_handler(VRSI_PROCESS);      
}


void vrsiHisr( void *data)
{
   uint32 I;
   volatile uint16 *addr;
   uint16 *buf;  
   
   if(vrsi->FLAGS & VRSI_HISR_STOP_RECORD_FLAG)  
      return;  
   
   if(vrsi->FLAGS & VRSI_RECORDING_FLAG)
   {
      vrsi->FLAGS |= VRSI_HISR_FLAG;
       
#if defined(VR_FR_INPUT)               
      addr = DP_TX_TCH_S( 0, 1 ); // source
      buf = vrsi->packet;
      
      for( I = 17 ; I > 0; I-- )     
         *buf++ = *addr++; 
      
      BSRPutPacket((uint8*)vrsi->packet);
         
#elif defined(VR_PCM_INPUT)  
      
      buf = vrsi->pcmBuf;
                  
      if(vrsi->funcState == VRSI_STATE_TRAIN) 
      { 
         int32 first_data_block_len, second_data_block_len;
         uint16 data_ptr, tmp;
         
         data_ptr = *DSP_DM_ADDR(PAGE_NUM, DP_SE_PCM_BUF_PTR); 
         
         first_data_block_len = DP_SE_PCM_BUF_SIZE - (data_ptr - DP_SE_PCM_BUF_ADDR);
      
         if( first_data_block_len < FRAME_BUF_SIZE )
            second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
         else 
         {
            first_data_block_len = FRAME_BUF_SIZE;
            second_data_block_len = 0;
         }
                           
         tmp = *DSP_DM_ADDR(PAGE_NUM, data_ptr);  /* Read uplink data */
         for ( I = first_data_block_len; I > 0; I-- )
            *buf++ = (*IDMA_SHORT_ADDR);
         if( (I = second_data_block_len) > 0 )
         {
            tmp = *DSP_DM_ADDR(PAGE_NUM, DP_SE_PCM_BUF_ADDR);
            for ( ; I > 0 ;I-- )
               *buf++ = (*IDMA_SHORT_ADDR);
         }      
         
         // get GSM FR data      
         addr = DP_TX_TCH_S( 0, 1 ); // source
                 
         for( I = 17 ; I > 0 ; I-- )     
            *buf++ = *addr++;  
      }      
      else 
      {
         uint16 tmp;
         I = (uint32)(*DSP_PCM_REC_LEN);
         ASSERT( I == FRAME_BUF_SIZE );
         tmp = *DSP_DM_ADDR(PAGE_NUM, *DSP_PCM_REC_ADDR);
         
         
         
         for( ; I > 0 ; I-- )
         {                        
         #ifdef VRSI_DEBUG  
            *buf = (*IDMA_SHORT_ADDR); 
            *pcmDebugPtr++ = *buf++;  
            pcmDebugCnt ++; 
         #else 
            *buf++ = (*IDMA_SHORT_ADDR);   
         #endif    
         }         
      }
      
      BSRPutPacket((uint8*)vrsi->pcmBuf);                        

#endif 
      vrsi->FLAGS &= ~VRSI_HISR_FLAG;                  
   }
           
}

void vrsiErrorRecord(BSR_Err bsrErr)
{
   switch(bsrErr)
   {
      case BSRERR_BUSY: 
         vrsi->errMsg = VRSI_ERR_BUSY;
         break;
      case BSRERR_INSUFFICIENT_MEM_SIZE: 
         vrsi->errMsg = VRSI_ERR_INSUFFICIENT_MEM;
         break;
      case BSRERR_LIBRARY_CORRUPT: 
         vrsi->errMsg = VRSI_ERR_LIBRARY_CORRUPT;
         break;
      case BSRERR_BAD_MODE:
         vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
         break;
      case BSRERR_TTS_TOO_LONG:          
         vrsi->errMsg = VRSI_ERR_TTS_TOO_LONG;
         break;
      case BSRERR_DB_FULL: 
         vrsi->errMsg = VRSI_ERR_DB_FULL;
         break;
      case BSRERR_DB_ERROR: 
         vrsi->errMsg = VRSI_ERR_DB_ERROR;
         break;     
      default:
         vrsi->errMsg = VRSI_ERR_UNKNOWN;
         break;
   }
}   

/*----------------  Host callback functions needed by Cyberon SI BSR engine -----------------*/
// Host_callback functions needed by Cyberon SI BSR engine 
// The audio facility callback functions
void HOST_start_record_callback(void) 
{   
   ktLock();
   mdi_audio_vrsi_register_record();   
   
   L1Audio_SetFlag(vrsi->aud_id); 
   vrsi->FLAGS |= VRSI_RECORDING_FLAG;

#ifdef VRSI_DEBUG   
   pcmDebugPtr = vrsiPcmDebugBuf;
   pcmDebugCnt = 0;
#endif 
   
#if defined(VR_FR_INPUT)    
   L1Audio_HookHisrHandler(DP_D2C_SE_DONE, vrsiHisr, 0);
   AM_VMRecordOn( (uint16)0 ); /* GSM FR */
#elif defined(VR_PCM_INPUT)
   if(vrsi->funcState == VRSI_STATE_TRAIN)
   {
      L1Audio_HookHisrHandler(DP_D2C_SE_DONE, vrsiHisr, 0);
      AM_VMRecordOn( (uint16)0 ); /* GSM FR */
   }
   else 
   {
      uint32 I;
    
   #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      L1Audio_HookHisrHandler(DP_D2C_WAV_REC, vrsiHisr, 0); 
   #else      
      L1Audio_HookHisrHandler(DP_D2C_PCM_R, vrsiHisr, 0);
   #endif    
      *DSP_PCM_REC_CTRL  = 0x200;      
      AM_PCM8K_RecordOn();
      for( I = 0; ; I++ ) 
      {
         if( *DSP_PCM_REC_CTRL == 0x400 )
            break;
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }      
   }      
#else 
   ASSERT(false);      
#endif       
}   

void HOST_stop_record_callback(void) 
{
   if(vrsi->FLAGS & VRSI_RECORDING_FLAG)
   {
      if(vrsi->FLAGS & VRSI_HISR_FLAG)
      {
         vrsi->FLAGS |= VRSI_HISR_STOP_RECORD_FLAG;              
         return;
      }     
      vrsi->FLAGS &= ~VRSI_RECORDING_FLAG;
      *DP_SC_MUTE = 0x0000;  // refer to vmStop() 
   
#if defined(VR_FR_INPUT)         
      AM_VMRecordOff(); 
      AM_FlushQFunction();
      L1Audio_UnhookHisrHandler(DP_D2C_SE_DONE);
#elif defined(VR_PCM_INPUT)   
      if(vrsi->funcState == VRSI_STATE_TRAIN)
      {
         AM_VMRecordOff();
         AM_FlushQFunction(); 
         L1Audio_UnhookHisrHandler(DP_D2C_SE_DONE);
      }
      else 
      {
         uint16 I, ctl;
         for( I = 0; ; I++ ) 
         {
            ctl = *DSP_PCM_REC_CTRL;
            if( ctl == 0 )                /* DSP returns to idle state */
               break;
            if( ctl == 0x400 )
               *DSP_PCM_REC_CTRL = 0x800;  /* give ABORT command to the DSP */
            ASSERT_REBOOT( I < 20 );
            kal_sleep_task( 2 );
         }
         AM_PCM8K_RecordOff( true ); 
         AM_FlushQFunction();
      #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
         L1Audio_UnhookHisrHandler(DP_D2C_WAV_REC); 
      #else         
         L1Audio_UnhookHisrHandler(DP_D2C_PCM_R);
      #endif 
      
      #ifdef VRSI_DEBUG 
      {
         int32 file_handle;
         pcmDebugFile ++;    
         kal_wsprintf(debugFile, "E:\\VRSIdebug%d.pcm",pcmDebugFile);     
         file_handle = FS_Open(debugFile, FS_CREATE);        
         if(file_handle > 0) 
         { 
            FS_Write( file_handle, vrsiPcmDebugBuf, pcmDebugCnt << 1, NULL );
            FS_Close(file_handle); 
         }   
      }  
      #endif   
      }   
#endif 
      L1Audio_ClearFlag(vrsi->aud_id); 
      
      mdi_audio_vrsi_unregister_record();
      ktUnlock();
   }   
}

extern uint16 AM_Status( void );
int32 HOST_is_recording_callback(void)
{
   if( AM_Status() == 0)
      return 0;   
   else 
      return 1; // some audio function is using microphone or speaker             
}

void HOST_start_playing_voice_callback(void *lpVoice, uint32 dwLen) // play GSM FR 
{
   uint32 len = dwLen >> 1; 
   
   ktLock();
   Media_SetBuffer((uint16*)lpVoice, len+1);
   Media_WriteDataDone(len);
   Media_DataFinished();
      
   Media_Play(MEDIA_FORMAT_VRSI, vrsiPlayHandler, vrsi->audioParam);
   vrsi->FLAGS |= (VRSI_PLAYING_FLAG + VRSI_GSMFR_PLAY_FLAG);
   
   vrsi->FLAGS &= ~VRSI_PROCESS_FLAG; 
}

int32 HOST_start_playing_PCM_voice_callback(void *lpVoice, uint32 dwNumSample, int32 bCopyAll)
{   
   uint16 *bufPtr, *srcPtr;
   uint32 bufLen, I;
   
   srcPtr = (uint16*) lpVoice;
   
   if(vrsi->FLAGS & VRSI_PLAYING_FLAG)
   {
      uint32 wCount;
  
      // copy data          
      Media_GetWriteBuffer(&bufPtr, &bufLen); 
      if(bufLen >= dwNumSample)      
         bufLen = dwNumSample;    
      
      for(I = bufLen; I > 0; I--)
         *bufPtr++ = *srcPtr++;  
      
      Media_WriteDataDone(bufLen);
      wCount = bufLen;
      
      dwNumSample -= bufLen; 
            
      Media_GetWriteBuffer(&bufPtr, &bufLen);      
      
      if(bufLen > 0 && dwNumSample > 0)
      {
         if(bufLen >= dwNumSample)      
            bufLen = dwNumSample;
         dwNumSample -= bufLen;
            
              
         for(I = bufLen; I > 0; I--)
            *bufPtr++ = *srcPtr++;

         Media_WriteDataDone(bufLen);                                    
         wCount += bufLen;
      }            
      
      
   #ifdef VRSI_TTS_DEBUG 
      {
         uint32 write_count;
         
         FS_Write(tts_file_handle, lpVoice, wCount << 1, &write_count);          
         ASSERT(write_count == wCount << 1);    
      
      }
   #endif 
            
      return wCount;
   }
   else 
   {
      // first call play : Media_SetBuffer and  Media_Play   
      
      ktLock();      
      Media_SetBuffer(vrsi->pcmBuf, 12000);
      Media_GetWriteBuffer(&bufPtr, &bufLen);
      if(bufLen >= dwNumSample)      
         bufLen = dwNumSample;       
      
      for(I = bufLen; I > 0; I--)
         *bufPtr++ = *srcPtr++;  
         
      Media_WriteDataDone(bufLen);   
      Media_Play(MEDIA_FORMAT_PCM_8K, vrsiPlayHandler, (void*)0);
      vrsi->FLAGS |= (VRSI_PLAYING_FLAG + VRSI_TTS_PLAY_FLAG) ;
   #ifdef VRSI_TTS_DEBUG 
      {
         uint32 write_count;
         
         FS_Write(tts_file_handle, lpVoice, bufLen << 1, &write_count);          
         ASSERT(write_count == bufLen << 1);          
      }
   #endif 
       
      return bufLen;
   }       
}   

int32 HOST_is_playing_callback(void)
{
   if(AM_Status() == 0)
      return 0;   
   else 
      return 1; // some audio function is using microphone or speaker    
}   

// timer 
void HOST_capture_timer_callback(void) 
{
   kal_set_timer(vrsiTimerID, vrsiTimerHandler, (void*)VRSI_CAPTURE_TIMER, 13, 0); // 60ms            
}

void HOST_playback_timer_callback(void)
{
   kal_set_timer(vrsiTimerID, vrsiTimerHandler, (void*)VRSI_PLAYBACK_TIMER, 13, 0); // 60ms
}

void HOST_process_timer_callback(void) 
{
   kal_set_timer(vrsiTimerID, vrsiTimerHandler, (void*)VRSI_PROCESS_TIMER, 4, 0); // 20ms
}

void HOST_quick_timer_callback(void) 
{
   kal_set_timer(vrsiTimerID, vrsiTimerHandler, (void*)VRSI_QUICK_TIMER, 1, 0); // <10ms
}

void HOST_stop_timers_callback(void)
{
   kal_cancel_timer(vrsiTimerID);   
}   

// Train tag callback;
void HOST_train_tag_start_callback(void)
{
   vrsi->FLAGS |= VRSI_WAITING_FLAG; 
   vrsi->vr_handler(VRSI_TRAIN_TAG_1ST_MPR);             
}
void HOST_train_tag_say_again_callback(void)
{
   vrsi->FLAGS |= VRSI_WAITING_FLAG; 
   vrsi->vr_handler(VRSI_TRAIN_TAG_2ND_MPR);   
}   

void HOST_train_tag_OK_callback(uint16 *lpwName, uint16 wTagID, int32 lTagLong)
{
   vrsi->FLAGS &= ~VRSI_PROCESS_FLAG;
   vrsi->FLAGS |= VRSI_OK_FLAG;
   vrsi->state = VRSI_STATE_READY;
   
   // record result
   vrsi->tag->tagID = wTagID;       
   vrsi->vr_handler(VRSI_TRAIN_TAG_OK);         
}


void HOST_train_tag_failed_callback(BSR_Err errorCode)
{
   vrsi->FLAGS &= ~VRSI_PROCESS_FLAG;
   vrsi->FLAGS |= VRSI_OK_FLAG;
   vrsi->state = VRSI_STATE_READY;   
   // record error 
   vrsiErrorRecord(errorCode);   
   vrsi->vr_handler(VRSI_ERROR);      
}

void HOST_train_tag_too_different_callback(void) // reserved 
{
   // ASSERT(false);   
}   
   
void HOST_train_tag_too_similar_callback(void) // reserved
{
   // ASSERT(false); 
}

// PSI add names
void HOST_add_tag_start_callback(BSR_Mode eMode)
{
   // do nothing    
}

void HOST_add_tag_res_callback(int32 nTag, uint16 **lppwcTagName, uint16 *lpwTagID, int32 *lpbIsName, int32 *lplTagLong, BSR_Mode eMode, BSR_Err err)
{
   VRSI_AddTags_Result *pAddTags;
   
   vrsi->FLAGS &= ~VRSI_PROCESS_FLAG;
   vrsi->FLAGS |= (VRSI_RESULT_FLAG + VRSI_OK_FLAG);
   vrsi->state = VRSI_STATE_READY;
   // record result    
   pAddTags = &(vrsi->addTagsRes);
   pAddTags->numTag = nTag;
   pAddTags->pTagID = lpwTagID;
   pAddTags->ppTagName = lppwcTagName;  
   vrsi->vr_handler(VRSI_ADD_TAGS_OK);
}


// Recognition : including voice command recognition and digit recognition  
void HOST_recognize_start_callback(BSR_Mode eMode)
{
   vrsi->FLAGS |= VRSI_WAITING_FLAG; 
      
   if(vrsi->state == VRSI_STATE_RECOG)   
      vrsi->vr_handler(VRSI_RECOG_MPR);            
   else         
      vrsi->vr_handler(VRSI_DIGIT_RECOG_MPR);         
}


void HOST_recognize_say_again_callback(BSR_Mode eMode) // reserved  
{  
   //ASSERT(false);      
}
void HOST_recognize_OK_callback(uint16 wPreCmd, int32 nTag, uint16 *lpwCmdID, uint16 **lppwcCmdName, int32 *lplCmdLong, uint16 wPostCmd, BSR_Mode eMode)
{
   kal_uint32 I;
   
   vrsi->FLAGS &= ~VRSI_PROCESS_FLAG;
   vrsi->FLAGS |= (VRSI_RESULT_FLAG + VRSI_OK_FLAG);
   vrsi->state = VRSI_STATE_READY;  
   
   // record result 
   if(vrsi->funcState == VRSI_STATE_RECOG)
   {
      VRSI_Recog_Result *pRecogRes = &(vrsi->recogRes);
      
      pRecogRes->preCmd = wPreCmd;
      pRecogRes->postCmd = wPostCmd;
      
      if(nTag > 8)
         nTag = 8;
      
      pRecogRes->numTag = nTag; 
      
      for( I = 0 ; I < nTag ; I ++)
      {
         vrsi->tagIdRes[I] = lpwCmdID[I];
         vrsi->tagLongRes[I] = lplCmdLong[I];   
         vrsi->tagNameRes[I] = lppwcCmdName[I];
      }
      
      pRecogRes->pTagID = vrsi->tagIdRes; 
      pRecogRes->pTagLong = vrsi->tagLongRes; 
      pRecogRes->ppTagName = vrsi->tagNameRes;
      
      if(wPreCmd != 65535)
      {         
         if(nTag == 0)         
            pRecogRes->resType = 1;                     
         else 
         {
            if(wPostCmd == 65535)
               pRecogRes->resType = 2;
            else             
               pRecogRes->resType = 3;                                                          
         }
      }
      else 
      {
         if(wPostCmd == 65535)                                        
            pRecogRes->resType = 4;
         else          
            pRecogRes->resType = 5;
      }                   
      vrsi->vr_handler(VRSI_RECOG_OK);   
   }
   else // VRSI_STATE_DIGIT_RECOG 
   {
      VRSI_Digit_Recog_Result *pDigitRecogRes = &(vrsi->digitRecogRes);      
      if(nTag > 33)
         nTag = 33;
      pDigitRecogRes->digitLen = nTag;
      for( I = 0 ; I < nTag ; I ++)
         vrsi->digitRes[I] = lpwCmdID[I];         
      vrsi->digitRes[I] = 0;          
      pDigitRecogRes->pDigits = vrsi->digitRes;
      vrsi->vr_handler(VRSI_DIGIT_RECOG_OK); 
   }    
         
}

void HOST_recognize_failed_callback(BSR_Mode eMode)
{
   vrsi->FLAGS &= ~VRSI_PROCESS_FLAG;
   vrsi->FLAGS |= VRSI_OK_FLAG;
   vrsi->state = VRSI_STATE_READY; 
   
   // record error 
   if(vrsi->funcState == VRSI_STATE_RECOG)
      vrsi->errMsg = VRSI_ERR_RECOG_FAIL;
   else // VRSI_STATE_DIGIT_RECOG 
      vrsi->errMsg = VRSI_ERR_DIGIT_RECOG_FAIL;   
         
   vrsi->vr_handler(VRSI_ERROR);          
}

// Digit adapation
void HOST_adapt_digit_start_callback(void)
{
   // do nothing 
}

void HOST_adapt_digit_say_callback(const WORD *lpwList, int32 nLen)
{
   kal_uint32 I;
   
   vrsi->FLAGS |= (VRSI_PROMPT_FLAG + VRSI_WAITING_FLAG);
   if(nLen > 33)
      nLen = 33;
   vrsi->promptLen = nLen; 
   for(I = 0; I < nLen; I ++)
      vrsi->digitRes[I] = lpwList[I];
      
   vrsi->digitRes[I] = 0;   
   vrsi->prompt = vrsi->digitRes;              
   vrsi->vr_handler(VRSI_DIGIT_ADAPT_MPR);     
}

void HOST_adapt_digit_failed_callback(void)
{   
   vrsi->FLAGS &= ~(VRSI_PROCESS_FLAG+VRSI_PROMPT_FLAG) ;
   vrsi->state = VRSI_STATE_READY;
   vrsi->errMsg = VRSI_ERR_DIGIT_ADAPT_FAIL;   
   vrsi->vr_handler(VRSI_ERROR);  
}

void HOST_adapt_digit_OK_callback(void)
{
   vrsi->FLAGS &= ~(VRSI_PROCESS_FLAG+VRSI_PROMPT_FLAG) ;
   vrsi->state = VRSI_STATE_READY;
   
   vrsi->vr_handler(VRSI_DIGIT_ADAPT_OK);
}

// TTS
void HOST_TTS_OK_callback(void)
{  
   vrsi->FLAGS &= ~VRSI_PROCESS_FLAG;
   vrsi->FLAGS |= VRSI_OK_FLAG;
   Media_DataFinished();  
#ifdef VRSI_TTS_DEBUG 
   FS_Close(tts_file_handle);
#endif     
}

//----------  Read/Write  Protection -------------

static kal_bool vrsi_common_read(uint16 *vrsiDir, kal_uint32 I, kal_wchar **file_name, kal_uint8 *memory) 
{
   int32  file_handle;
   uint32 file_size, read_len;   
   
   kal_wsprintf(file_name[0], "%wVRSI0%x.dat", vrsiDir, I+1);     
   file_handle = FS_Open(file_name[0], FS_CREATE);
   if(file_handle < 0) 
   {
      vrsi->errMsg = VRSI_ERR_WRONG_DATA_DIR;
      return KAL_FALSE;
   }

   FS_GetFileSize( file_handle, &file_size );
   if( file_size == 0x10000 )
   {                                                           	        		
      FS_Read(file_handle, memory, 65536, &read_len);
      if(read_len != 65536)
      {
         vrsi->errMsg = VRSI_ERR_WRONG_DATA_FILE;
         FS_Close(file_handle);  
         return KAL_FALSE;
      }   
   }         

   FS_Close(file_handle);         		
   
   return KAL_TRUE;
}         

static kal_bool vrsi_proctect_read(uint16 *vrsiDir, kal_uint32 I, kal_wchar **file_name, kal_uint8 *memory) 
{
   int32  file_handle, file_handle1, file_handle2;
   uint32 file_size, read_len, write_len;   
   
   kal_wsprintf(file_name[0], "%wVRSI0%x.dat", vrsiDir, I+1);
   kal_wsprintf(file_name[1], "%wVRSI0%xA.dat", vrsiDir, I+1);
   kal_wsprintf(file_name[2], "%wVRSI0%xB.dat", vrsiDir, I+1);
           
   file_handle = FS_Open(file_name[0], FS_CREATE);
   if(file_handle < 0) 
   {
      vrsi->errMsg = VRSI_ERR_WRONG_DATA_DIR;
      return KAL_FALSE;
   }
   
   FS_GetFileSize( file_handle, &file_size );
   
   if(file_size == 0x10000)
   {        
      file_handle1 = FS_Open(file_name[1], FS_READ_ONLY);
      
      if(file_handle1 > 0)
      {
         FS_GetFileSize( file_handle1, &file_size );
         if(file_size == 0x10000)
         {
            FS_Close(file_handle);
            FS_Read(file_handle1, memory, 65536, &read_len);
         	if(read_len != 65536)
         	{
            	vrsi->errMsg = VRSI_ERR_WRONG_DATA_FILE;
            	FS_Close(file_handle1);  
            	return KAL_FALSE;
         	}                           
            FS_Close(file_handle1);            
            FS_Rename(file_name[0], file_name[2]);                                               
            FS_Rename(file_name[1], file_name[0]); 
            FS_Delete(file_name[2]);             
         }
         else
         {
            FS_Close(file_handle1);
            FS_Delete(file_name[1]);
            FS_Read(file_handle, memory, 65536, &read_len);
         	if(read_len != 65536)
         	{
            	vrsi->errMsg = VRSI_ERR_WRONG_DATA_FILE;
            	FS_Close(file_handle);  
            	return KAL_FALSE;
         	} 
         	FS_Close(file_handle);           
         }               
      }
      else       
      {
         file_handle2 = FS_Open(file_name[2], FS_READ_ONLY);
         if(file_handle2 > 0) 
         {
            FS_Close(file_handle2);
            FS_Delete(file_name[2]);
         }
      }         
   }
   else 
   {
      file_handle1 = FS_Open(file_name[1], FS_READ_ONLY);      
      
      if(file_handle1 > 0) 
      {
         FS_GetFileSize( file_handle1, &file_size );
         if(file_size == 0x10000)
         {
            file_handle2 = FS_Open(file_name[2], FS_READ_ONLY);
            if(file_handle2 > 0)    
            {
               FS_Close(file_handle2);
               FS_Delete(file_name[2]);
            }
            FS_Read(file_handle1, memory, 65536, &read_len);
         	if(read_len != 65536)
         	{
            	vrsi->errMsg = VRSI_ERR_WRONG_DATA_FILE;
            	FS_Close(file_handle);
            	FS_Close(file_handle1);  
            	return KAL_FALSE;
         	}                
            FS_Write( file_handle, memory, 65536, &write_len );
            if(write_len != 65536)
            {
               vrsi->errMsg = VRSI_ERR_WRONG_DATA_FILE;
            	FS_Close(file_handle);
            	FS_Close(file_handle1);  
            	return KAL_FALSE;                              
            }            
            FS_Close(file_handle1);
            FS_Delete(file_name[1]);
            FS_Close(file_handle);                     
         }
         else 
         {        
            FS_Close(file_handle1);
            FS_Delete(file_name[1]);
            FS_Close(file_handle); 
         }  
      }
      else 
      {
         file_handle2 = FS_Open(file_name[2], FS_READ_ONLY);
         if(file_handle2 > 0) 
         {
            FS_GetFileSize( file_handle2, &file_size );
            if(file_size == 0x10000)
            {
               FS_Read(file_handle2, memory, 65536, &read_len);
         	   if(read_len != 65536)
         	   {
            	   vrsi->errMsg = VRSI_ERR_WRONG_DATA_FILE;
            	   FS_Close(file_handle);
            	   FS_Close(file_handle2);  
            	   return KAL_FALSE;
         	   }                
               FS_Write( file_handle, memory, 65536, &write_len );
               if(write_len != 65536)
               {
                  vrsi->errMsg = VRSI_ERR_WRONG_DATA_FILE;
            	   FS_Close(file_handle);
            	   FS_Close(file_handle2);  
            	   return KAL_FALSE;                              
               }            
            }                                    
            FS_Close(file_handle2);
            FS_Delete(file_name[2]);
            FS_Close(file_handle);
         }
      }   
   }
      
   return KAL_TRUE;                 
}


static kal_bool vrsi_proctect_write(uint16 *vrsiDir, kal_uint32 I, kal_wchar **file_name)  
{
   int32  file_handle;    
   uint32 write_len;
   uint8 *dataPtr;
   uint8 proc[4];
   
   kal_wsprintf(file_name[0], "%wProcState1.dat", vrsiDir);   
   //file_handle = FS_Open(file_name[0],  FS_PROTECTION_MODE);
   file_handle = FS_Open(file_name[0],  FS_CREATE);
   proc[0] = 0xAA; 
   proc[1] = I; 
   proc[2] = 1; 
   proc[3] = 0xAA; 
   FS_Write(file_handle, proc, 4, NULL );   
   FS_Close(file_handle);
   // 2nd ProcState infomation 
   kal_wsprintf(file_name[0], "%wProcState2.dat", vrsiDir);      
   file_handle = FS_Open(file_name[0],  FS_CREATE);
   FS_Write(file_handle, proc, 4, NULL );   
   FS_Close(file_handle);     
   
   //---- start protection ----
   kal_wsprintf(file_name[0], "%wVRSI0%x.dat", vrsiDir, I+1);
   kal_wsprintf(file_name[1], "%wVRSI0%xA.dat", vrsiDir, I+1);
   kal_wsprintf(file_name[2], "%wVRSI0%xB.dat", vrsiDir, I+1);
       
   // write to tmp file
   dataPtr = (uint8*) (vrsi->bsrDB[I].dwStart);            
   file_handle = FS_Open(file_name[1],  FS_CREATE);
   if(file_handle < 0) 
   {
      vrsi->errMsg = VRSI_ERR_WRONG_DATA_DIR;
      return KAL_FALSE;                
   }                                          
   FS_Write(file_handle, dataPtr, 65536, &write_len);
   if(write_len != 65536)
   {
      vrsi->errMsg = VRSI_ERR_WRONG_DATA_FILE;
      FS_Close(file_handle);            	 
      return KAL_FALSE;                              
   }               
   FS_Close(file_handle);
                        
   // rename                          
   FS_Rename(file_name[0], file_name[2]);
   FS_Rename(file_name[1], file_name[0]);            
   // delete        
   FS_Delete(file_name[2]);                                                    
   // ----- end protection -----
   kal_wsprintf(file_name[0], "%wProcState1.dat", vrsiDir);      
   file_handle = FS_Open(file_name[0],  FS_CREATE);
   proc[0] = 0; 
   proc[1] = 0; 
   proc[2] = 0; 
   proc[3] = 0; 
   FS_Write(file_handle, proc, 4, NULL );   
   FS_Close(file_handle);
   // 2nd ProcState infomation 
   kal_wsprintf(file_name[0], "%wProcState2.dat", vrsiDir);      
   file_handle = FS_Open(file_name[0],  FS_CREATE);
   FS_Write(file_handle, proc, 4, NULL );   
   FS_Close(file_handle);                     
   
   return KAL_TRUE;
}  

static kal_bool vrsi_read_proc_state(uint16 *vrsiDir, kal_wchar *file_name, uint8 *proc_state) 
{
   int32 file_handle; 
   uint32 file_size, file_size2, read_len;    
   uint32 procState, procState2, procIdx;
   
   kal_wsprintf(file_name, "%wProcState1.dat", vrsiDir);   
   file_handle = FS_Open(file_name,  FS_CREATE);
   
   if(file_handle < 0) 
      return KAL_FALSE;
   
   FS_GetFileSize( file_handle, &file_size );
   
   if(file_size == 0) // first create or lost ?
   {      
      procState = 0;
      FS_Write(file_handle, &procState, 4, NULL );         
      FS_Close(file_handle);      
   }   
   else 
   {        
      FS_Read(file_handle, &procState, 4, &read_len);
      FS_Close(file_handle);
   }   
   
   kal_wsprintf(file_name, "%wProcState2.dat", vrsiDir);   
   file_handle = FS_Open(file_name,  FS_CREATE);
   
   if(file_handle < 0) 
      return KAL_FALSE;
   
   FS_GetFileSize( file_handle, &file_size2 );
   
   if(file_size2 == 0) // first create or lost? 
   {      
      procState2 = 0;
      FS_Write(file_handle, &procState2, 4, NULL );        
      FS_Close(file_handle);      
   }   
   else 
   {         
      FS_Read(file_handle, &procState2, 4, &read_len);
      FS_Close(file_handle);
   }   
       
   
   if(file_size != file_size2 || procState != procState2 )
   {
      *proc_state = 0xF;   
      return KAL_TRUE;
   }
               
   if(procState == 0)   
   {    
      *proc_state = 0; 
      return KAL_TRUE;
   }
   else if(procState & 0xFFFF00FF == 0xAA0100AA)
   {
      procIdx = (procState & 0xFF00) >> 8;  
      
      if(procIdx <= 3)
      {         
         *proc_state = 1 << procIdx;    
         return KAL_TRUE;
      }
   }   
   *proc_state = 0xF;   
   return KAL_TRUE;
}   
      
      
static kal_bool vrsi_update_proc_state(uint16 *vrsiDir, kal_wchar *file_name) 
{
   uint8 proc[4];
   int32 file_handle;
   
   kal_wsprintf(file_name, "%wProcState1.dat", vrsiDir);   
   file_handle = FS_Open(file_name,  FS_CREATE);
   proc[0] = 0; 
   proc[1] = 0; 
   proc[2] = 0; 
   proc[3] = 0; 
   FS_Write(file_handle, proc, 4, NULL );   
   FS_Close(file_handle);    
   // 2nd ProcState infomation 
   kal_wsprintf(file_name, "%wProcState2.dat", vrsiDir);      
   file_handle = FS_Open(file_name,  FS_CREATE);
   FS_Write(file_handle, proc, 4, NULL );   
   FS_Close(file_handle);       
   return KAL_TRUE;
}   

/*----------------  VRSI engine APIs  -----------------------*/


// Initialization   
VRSI_Status VRSI_Init( void (*vrsi_handler)( VRSI_Event event ))
{  
   if(vrsi != (VRSI_Struct *)0) 
      ASSERT(false);  // or just return VRSI_FAIL here 
   
   vrsi = (VRSI_Struct*) get_ctrl_buffer(sizeof(VRSI_Struct));             
   
   vrsi->aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( vrsi->aud_id, vrsiEventHandler );  
   vrsi->state = VRSI_STATE_INITIALIZED;
   vrsi->vr_handler = vrsi_handler;
   vrsi->errMsg = VRSI_ERR_NO; 
        
   return VRSI_OK;
}    
            
kal_uint32 VRSI_GetMemRequest(kal_uint16 maxFixedTag, kal_uint16 maxDynamicTag, kal_uint8 maxSDTag )
{
   kal_uint16 num64K;
   kal_uint32 wMemSize, result; 
   
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   BSRGetRTResourceSize(maxFixedTag + maxDynamicTag, maxDynamicTag , maxSDTag, &num64K , &wMemSize);   
   
   if(num64K > VRSI_NUM_FLASH_BLOCK)
   {
      vrsi->errMsg = VRSI_ERR_TOO_MANY_TAGS;
      ASSERT(false); // or just return 0 
   }   
   
   result = wMemSize;
   
   if(maxFixedTag != 0 || maxDynamicTag != 0 || maxSDTag != 0)       
      result += VRSI_NUM_FLASH_BLOCK * 65536 + 24036 ; // 262144(if 4) + 24000 + 36         
   else 
      result += 24000; // for PCM playback buffer 
   
   return result;   
}            

VRSI_Status VRSI_SetMem(kal_uint8 *memory, kal_uint32 size, kal_uint16 maxFixedTag, kal_uint16 maxDynamicTag, kal_uint8 maxSDTag ,uint16 *vrsiDir) 
{
   kal_uint32 wMemSize; 
   BSRDBINFO *pBsrDB;
   
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
   
   if(vrsi->state == VRSI_STATE_IDLE)
   {
      vrsi->errMsg = VRSI_ERR_UNINITIALIZED;  
      return VRSI_FAIL;            
   }
      
   if(vrsi->state != VRSI_STATE_INITIALIZED)
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;  
      return VRSI_FAIL;      
   } 
   
   wMemSize = VRSI_GetMemRequest(maxFixedTag, maxDynamicTag, maxSDTag);
   
   if(size < wMemSize) 
   {
      vrsi->errMsg = VRSI_ERR_INSUFFICIENT_MEM;  
      return VRSI_FAIL;
   }       
   
   vrsi->pcmBuf = (kal_uint16*) memory;
   memory += 24000;
   size -= 24000; 
     
   pBsrDB = &(vrsi->bsrDB[0]); 
         
   if(maxFixedTag == 0 &&  maxDynamicTag == 0 && maxSDTag == 0) 
   {      
      pBsrDB->dwStart = 0;
      pBsrDB->dwSize = 0;      
   }
   else 
   {      
      kal_wchar *file_name[3];      
      uint32 I;    
      uint8 proc_state;
      kal_bool read_success;
      
      vrsi->packet = (kal_uint16*) memory;
      memory += 36;
      size -= 36;
               
      file_name[0] = (kal_wchar*) get_ctrl_buffer(64);
      file_name[1] = (kal_wchar*) get_ctrl_buffer(64);                  
      file_name[2] = (kal_wchar*) get_ctrl_buffer(64);
      
      // read ProcState.dat 
      if(!vrsi_read_proc_state(vrsiDir, file_name[0], &proc_state))
      {
         free_ctrl_buffer(file_name[0]);
         free_ctrl_buffer(file_name[1]);
         free_ctrl_buffer(file_name[2]);
         vrsi->errMsg = VRSI_ERR_WRONG_DATA_DIR;
         return VRSI_FAIL;                  
      }
                           
      for(I = 0 ; I < VRSI_NUM_FLASH_BLOCK ; I ++)
      {         
         pBsrDB->dwStart = memory;
         pBsrDB->dwSize = 65536;
         
         // read VRSI data file into RAM          
         if(proc_state & 1 << I)  
            read_success = vrsi_proctect_read(vrsiDir, I, file_name, memory);                                 
         else 
            read_success = vrsi_common_read(vrsiDir, I, file_name, memory); 
         
         if(!read_success)
         {
            free_ctrl_buffer(file_name[0]);
            free_ctrl_buffer(file_name[1]);
            free_ctrl_buffer(file_name[2]);
            vrsi->errMsg = VRSI_ERR_WRONG_DATA_DIR;
            return VRSI_FAIL; 
         }   
                                 		
         memory += 65536;
         pBsrDB += 1; 
      }
      
      if(proc_state != 0)
         vrsi_update_proc_state(vrsiDir, file_name[0]);
      
      free_ctrl_buffer(file_name[0]);
      free_ctrl_buffer(file_name[1]);
      free_ctrl_buffer(file_name[2]);      
      pBsrDB->dwStart = 0;
      pBsrDB->dwSize = 0;    
      size -= VRSI_NUM_FLASH_BLOCK * 65536; 
   }
                                      
   if(BSRInit(memory, size, vrsi->bsrDB, maxFixedTag + maxDynamicTag, maxDynamicTag)== BSRRES_FAILED)
   {
      BSR_Err bsrErr;      
      bsrErr = BSRGetLastError();
      vrsiErrorRecord(bsrErr);            
      return VRSI_FAIL;   
   } 
   
   BSRResetModificationFlag();
      
   kal_wstrcpy(vrsi->dataDir, vrsiDir);  
   
   vrsi->FLAGS = 0;
   
   vrsi->state = VRSI_STATE_READY;    
   
   return VRSI_OK;
}            


VRSI_Status VRSI_Stop()
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
   
   if(vrsi->state == VRSI_STATE_READY)
      return VRSI_OK;   
   else if(vrsi->FLAGS & (VRSI_PROCESS_FLAG + VRSI_PLAYING_FLAG))
   {
   
      vrsi->state = VRSI_STATE_ABORT;
   
      // stop audio activities , call Media_Stop() 
      if(vrsi->FLAGS & VRSI_RECORDING_FLAG)
      {         
         HOST_stop_record_callback();
      }
    
      if(vrsi->FLAGS & VRSI_PLAYING_FLAG)
      {
         Media_Stop();
         ktUnlock();
      }
      
      vrsi->FLAGS = 0;
        
      BSRAbortEngine();   
       
      vrsi->state = VRSI_STATE_READY;
      
      return VRSI_OK;
   }
   else 
   {   
      return VRSI_FAIL;   
   }     
}


VRSI_Status VRSI_Close()
{
   uint32 I, modified;
   
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
   
   if(vrsi->state & (VRSI_STATE_INITIALIZED | VRSI_STATE_READY))
   {  
      if(vrsi->state == VRSI_STATE_READY)
      {    
         kal_wchar *file_name[3];                 
                    
         file_name[0] = (kal_wchar*) get_ctrl_buffer(64);
         file_name[1] = (kal_wchar*) get_ctrl_buffer(64);  
         file_name[2] = (kal_wchar*) get_ctrl_buffer(64);
               
         BSRGetModifiedTagBlock(&modified);
         for(I = 0 ; I < VRSI_NUM_FLASH_BLOCK ; I ++)
         {
            if(modified & (1 << I))
            {
               if(!vrsi_proctect_write(vrsi->dataDir, I, file_name))
                  ASSERT(false);                                
            }
         }  
               
         free_ctrl_buffer(file_name[0]);
         free_ctrl_buffer(file_name[1]);
         free_ctrl_buffer(file_name[2]);
      }    
            
      L1Audio_FreeAudioID(vrsi->aud_id);
      free_ctrl_buffer(vrsi);
      vrsi = (VRSI_Struct*) 0; 
      return VRSI_OK;        
   }
   else 
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;   
   }           
}


// Voice Command Recognition
VRSI_Status VRSI_Add_Tags(const kal_uint8 *grammar, VRSI_AddTags_Param *param )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->state != VRSI_STATE_READY)
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;
   }
   
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
   
   vrsi->state = VRSI_STATE_ADD_TAGS;
   vrsi->funcState = VRSI_STATE_ADD_TAGS;   
   
   vrsi->FLAGS = VRSI_PROCESS_FLAG;  
      
   if(BSRStartAddTag(param->numTag, (const uint16**)param->ppTagName, (const uint8*)param->pIsPeopleName, param->pTagLong) == BSRRES_FAILED) 
   {      
      BSR_Err bsrErr;
      bsrErr = BSRGetLastError();
      vrsiErrorRecord(bsrErr);
      vrsi->state = VRSI_STATE_READY; 
      vrsi->FLAGS = 0;       
      return VRSI_FAIL;   
   } 
           
   return VRSI_OK;   
}


VRSI_Status VRSI_Train_Tag (const kal_uint8 *grammar, VRSI_Tag_Param *param )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->state != VRSI_STATE_READY)
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;
   }
      
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
        
   vrsi->tag = param;    
   vrsi->state = VRSI_STATE_TRAIN;
   vrsi->funcState = VRSI_STATE_TRAIN;
   
   vrsi->FLAGS = VRSI_PROCESS_FLAG;  
   if(BSRStartTrain((const uint16*)param->pTagName, param->tagLong)== BSRRES_FAILED) 
   {      
      BSR_Err bsrErr;
      bsrErr = BSRGetLastError();
      vrsiErrorRecord(bsrErr);
      vrsi->state = VRSI_STATE_READY;  
      vrsi->FLAGS = 0;      
      return VRSI_FAIL;   
   } 
           
   return VRSI_OK;   
}

VRSI_Status VRSI_Recog(const kal_uint8 *grammar )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
   
   if(vrsi->state != VRSI_STATE_READY)
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;
   }
             
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   

   vrsi->state = VRSI_STATE_RECOG; 
   vrsi->funcState = VRSI_STATE_RECOG;         
   
   vrsi->FLAGS = VRSI_PROCESS_FLAG;
   if(BSRStartRecognize()== BSRRES_FAILED)
   {
      BSR_Err bsrErr;
      bsrErr = BSRGetLastError();
      vrsiErrorRecord(bsrErr);
      vrsi->state = VRSI_STATE_READY;  
      vrsi->FLAGS = 0;      
      return VRSI_FAIL;   
   }  
            
   return VRSI_OK;
}

const BSR_Language vrsiLangTable[4] = {BSR_LANG_TAIWAN , BSR_LANG_CHINA , BSR_LANG_AMERICAN , BSR_LANG_BRITISH};

// Digit Recognition & Adaptation
VRSI_Status VRSI_Digit_Recog( VRSI_Language  lang, kal_uint16 limit )
{
   BSR_Language bsrLang;
   
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
   
   if(vrsi->state != VRSI_STATE_READY)
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;
   }
      
   if(BSRSetMode(lpbyteBSR_DIGIT)== BSRRES_FAILED)
   	ASSERT(false);  
   bsrLang = vrsiLangTable[lang];
   if(BSRSetLanguage(bsrLang)== BSRRES_FAILED)
   	ASSERT(false);  
   if(BSRSetLimit(limit) == BSRRES_FAILED)
   	ASSERT(false);  
   
   vrsi->state = VRSI_STATE_DIGIT_RECOG; 
   vrsi->funcState = VRSI_STATE_DIGIT_RECOG;   
   vrsi->FLAGS = VRSI_PROCESS_FLAG; 
   if(BSRStartRecognize() == BSRRES_FAILED)
   {
      BSR_Err bsrErr;
      bsrErr = BSRGetLastError();
      vrsiErrorRecord(bsrErr);
      vrsi->state = VRSI_STATE_READY;  
      vrsi->FLAGS = 0;      
      return VRSI_FAIL;   
   }     	 
    
   return VRSI_OK;       
}


VRSI_Status VRSI_Digit_Adapt( VRSI_Language  lang )
{
   BSR_Language bsrLang;
   
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
   
   if(vrsi->state != VRSI_STATE_READY)
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;
   }
            
   if(BSRSetMode(lpbyteBSR_DIGIT)== BSRRES_FAILED)
   	ASSERT(false);  
   	
   bsrLang = vrsiLangTable[lang];   
   
   if(BSRSetLanguage(bsrLang)== BSRRES_FAILED)
   	ASSERT(false);  
   	
   vrsi->state = VRSI_STATE_DIGIT_ADAPT; 
   vrsi->funcState = VRSI_STATE_DIGIT_ADAPT;
   
   vrsi->FLAGS = VRSI_PROCESS_FLAG;
   if(BSRStartTrain(0, 0)== BSRRES_FAILED)
      ASSERT(false);  
    
   return VRSI_OK;        
}


//	Playback 
VRSI_Status VRSI_Play_Tag(const kal_uint8 *grammar , kal_uint16 tagID ,void* param  )
{
   uint16 bExisted;
   
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
   
   if(vrsi->state != VRSI_STATE_READY)
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;
   }
   
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
           
   BSRTagExists(tagID, &bExisted);
   
   if(bExisted)
   {
      vrsi->state = VRSI_STATE_PLAY_TAG; 
      vrsi->funcState = VRSI_STATE_PLAY_TAG;
      vrsi->audioParam = param;
      vrsi->FLAGS = VRSI_PROCESS_FLAG;    
      if(BSRPlayTagVoice(tagID) == BSRRES_FAILED)
      {
         BSR_Err bsrErr;
         bsrErr = BSRGetLastError();
         vrsiErrorRecord(bsrErr);
         vrsi->state = VRSI_STATE_READY;
         vrsi->FLAGS = 0;  
         return VRSI_FAIL;                           
      }         
      return VRSI_OK; 
   }
   else 
   {
      vrsi->errMsg = VRSI_ERR_NO_MATCH_TAG;
      return VRSI_FAIL;   
   }                
}

VRSI_Status VRSI_TTS_Play( VRSI_Language lang, kal_uint16 *pText )
{
   BSR_Language bsrLang;
   
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   // lang seems to be un-used 
   if(vrsi->state != VRSI_STATE_READY)
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;
   }
   
   bsrLang = vrsiLangTable[lang];
   if(BSRSetLanguage(bsrLang)== BSRRES_FAILED)
   	ASSERT(false);  
   	
   vrsi->state = VRSI_STATE_TTS;
   vrsi->funcState = VRSI_STATE_TTS;
   
   vrsi->FLAGS = VRSI_PROCESS_FLAG;
   
   if(BSRStartPlayTTS(pText, 0)== BSRRES_FAILED)
   {
      BSR_Err bsrErr;
      bsrErr = BSRGetLastError();
      vrsiErrorRecord(bsrErr);
      vrsi->state = VRSI_STATE_READY;
      vrsi->FLAGS = 0;  
      return VRSI_FAIL;
   } 
   
#ifdef VRSI_TTS_DEBUG   
   tts_file_idx ++;  
   kal_wsprintf(ttsDebugFile, "X:\\tts%d.pcm",tts_file_idx); 
   driveIdx = FS_GetDrive( FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
   ttsDebugFile[0] = (kal_wchar) driveIdx;
   tts_file_handle = FS_Open(ttsDebugFile,  FS_CREATE_ALWAYS);   
   ASSERT( tts_file_handle > 0); 
#endif    
     
                   
   return VRSI_OK;     
}

//	Message Process
VRSI_Status VRSI_Process( void )
{
   FRESULT bsrRes;
   
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
   
   if(vrsi->FLAGS & VRSI_PROCESS_FLAG) 
   {
      if(vrsi->FLAGS & VRSI_WAITING_FLAG)
      {
         kal_cancel_timer(vrsiTimerID);           
         return VRSI_OK;
      }
      if(vrsi->FLAGS & VRSI_HISR_STOP_RECORD_FLAG)
      {
         HOST_stop_record_callback();   
         vrsi->FLAGS &= ~VRSI_HISR_STOP_RECORD_FLAG;
      }   
      
      bsrRes = BSRProcess();
      if(bsrRes == BSRRES_FAILED)
      {
         BSR_Err bsrErr;
         bsrErr = BSRGetLastError();
         vrsiErrorRecord(bsrErr);                 
         vrsi->FLAGS &= ~VRSI_PROCESS_FLAG; 
         vrsi->state = VRSI_STATE_READY;
         return VRSI_FAIL; 
      }
      else
      {
         if(bsrRes == BSRRES_OK)
            vrsi->FLAGS &= ~VRSI_PROCESS_FLAG;                        
         return VRSI_OK;
      }   
   }
   else 
   {
      if(vrsi->FLAGS & VRSI_OK_FLAG) // to prevent process timer time-out before HOST_XXX_OK/failed_callback
         return VRSI_OK; 
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;            
   }                        
}

void VRSI_ReadPrompt (  kal_uint8 *promptLen, const kal_uint16 **prompt )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->FLAGS & VRSI_PROMPT_FLAG)
   {   
      *promptLen = vrsi->promptLen;   
      *prompt = vrsi->prompt;         
   }
   else 
   {
      *promptLen = 0;  
      *prompt = NULL; 
   }   
}


void VRSI_MMI_Confirmed( void )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
        
   if(vrsi->FLAGS & VRSI_WAITING_FLAG)
   {       
      // does confirmed then call BSRProcess() here ? 
      // if MMI doesn't want to do anything and he could call VRSI_MMI_Confirmed() immediately 
      // so do not call BSRProcess here 
      vrsi->FLAGS &= ~VRSI_WAITING_FLAG;    
      kal_set_timer(vrsiTimerID, vrsiTimerHandler,(void*) VRSI_PROCESS_TIMER, 1, 0); // 4.615ms                
   }   
}

void VRSI_ReadResult( void **result )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->FLAGS & VRSI_RESULT_FLAG)
   {
      switch (vrsi->funcState)
      {
         case VRSI_STATE_ADD_TAGS: 
            *result = (void*) &(vrsi->addTagsRes);
            break;
         case VRSI_STATE_RECOG:
            *result = (void*) &(vrsi->recogRes);
            break;
         case VRSI_STATE_DIGIT_RECOG: 
            *result = (void*) &(vrsi->digitRecogRes);
            break;
         default: 
            ASSERT(false);
      }                           
   }
   else 
      *result = NULL;                  
}

// VRSI_GetErrMsg : 
// i> when VRSI API return VRSI_FAIL  
// ii> when receive VRSI_ERROR event 
VRSI_ErrMsg VRSI_GetErrMsg( void )
{  
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
       
   return vrsi->errMsg;   
}

// Database Management 
VRSI_Status VRSI_Gram_GetTagNum(const kal_uint8 *grammar , kal_int32 *tagNum )
{ 
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->state & (VRSI_STATE_IDLE | VRSI_STATE_INITIALIZED))
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;            
   }      
       
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
   
   *tagNum = 0;         
   if(BSRGetNumDynamicTag(tagNum) == BSRRES_FAILED)
      *tagNum = 0;
   return VRSI_OK; 
}   

VRSI_Status VRSI_Gram_ReadTagIDs(const kal_uint8 *grammar, kal_uint16 *pTagID , kal_int32 bufferSize, kal_int32 *readTagNum)
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->state & (VRSI_STATE_IDLE | VRSI_STATE_INITIALIZED))
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;            
   }      
   
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
     
   BSRGetAllDynamicTagID(readTagNum, pTagID, bufferSize); 
   return VRSI_OK;      
}

VRSI_Status VRSI_Gram_DeleteAllTags(const kal_uint8 *grammar )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->state & (VRSI_STATE_IDLE | VRSI_STATE_INITIALIZED))
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;            
   }      
   
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
       
   BSRResetDB();
   return VRSI_OK;
}

VRSI_Status VRSI_DeleteTags(const kal_uint8 *grammar, kal_int32 tagNum, const kal_uint16 *pTagID, kal_int32 *delTagNum, kal_uint16 *pDelTagID )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->state & (VRSI_STATE_IDLE | VRSI_STATE_INITIALIZED))
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;            
   }
   
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }         
   
   BSRDeleteTags(tagNum, pTagID, delTagNum, pDelTagID);  
   
   return VRSI_OK;
}

VRSI_Status VRSI_TagExist(const kal_uint8 *grammar, kal_uint16 tagID, kal_bool *bExist  )
{
   uint16 bExisted;
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);      
         
   if(vrsi->state & (VRSI_STATE_IDLE | VRSI_STATE_INITIALIZED))
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;            
   }      
   
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
      
   BSRTagExists(tagID, &bExisted);
   
   if(bExisted)
      *bExist = true;
   else 
      *bExist = false;         
      
   return VRSI_OK;   
}

VRSI_Status VRSI_ReadTags(const kal_uint8 *grammar, kal_int32 tagNum, const kal_uint16 *pTagID, kal_uint16 **ppTagName, kal_int32 *pTagLong )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->state & (VRSI_STATE_IDLE | VRSI_STATE_INITIALIZED))
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;            
   }      
   
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
   
   BSRGetTagStatus(tagNum, pTagID, ppTagName, pTagLong);      
   
   return VRSI_OK;
}

VRSI_Status VRSI_QueryTagId(const kal_uint8 *grammar, kal_int32 tagLong, kal_uint16 *tagID )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->state & (VRSI_STATE_IDLE | VRSI_STATE_INITIALIZED))
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;            
   }      
   
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
   
   *tagID = BSRQueryTagId(tagLong);
   
   if(*tagID == 65535)
   {
      vrsi->errMsg = VRSI_ERR_NO_MATCH_TAG;   
      return VRSI_FAIL;
   }          
      
   return VRSI_OK;   
}

VRSI_Status VRSI_QueryNextTagId(const kal_uint8 *grammar, kal_uint16 *tagID )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->state & (VRSI_STATE_IDLE | VRSI_STATE_INITIALIZED))
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;            
   }      
   
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
   
   *tagID = BSRQueryNextTagId();
   
   if(*tagID == 65535)
   {
      vrsi->errMsg = VRSI_ERR_NO_MATCH_TAG;   
      return VRSI_FAIL;
   }          
   
   return VRSI_OK;   
}

VRSI_Status VRSI_QueryAllTagIds(const kal_uint8 *grammar, kal_int32 tagLong, kal_uint16 buf_size, kal_uint16 *id_buf, kal_uint16 *tagNum, kal_bool *getAll )
{
   if(vrsi == (VRSI_Struct *)0) 
      ASSERT(false);
      
   if(vrsi->state & (VRSI_STATE_IDLE | VRSI_STATE_INITIALIZED))
   {
      vrsi->errMsg = VRSI_ERR_STATE_UNMATCH;
      return VRSI_FAIL;            
   }      
   
   if(BSRSetMode(grammar)== BSRRES_FAILED)
   {
      vrsi->errMsg = VRSI_ERR_BAD_GRAMMAR;
      return VRSI_FAIL;
   }   
   
   if(BSRQueryAllTagIds(tagLong, buf_size, id_buf, tagNum))
      *getAll = true;
   else 
      *getAll = false;   
   
   return VRSI_OK;   
}

#else
char dummy_vr_si_c;    /* define a dummy variable to avoid warning message */
#endif 


      
   