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
 * jwav.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Wave playback using DSP 64-tone PCM channels 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined( DSP_WT_SYN )

#include "dspsyn.h" 
#include "g711.h"

#define JWAV_TRACE   kal_prompt_trace
//#define JWAV_TRACE   (void)

// dsp 64-tone PCM channel real-time commands 
#define DSP_TYPE_SET_BUF_ADDR  (0x11 << 8) 
#define DSP_TYPE_SET_PCM_LENGTH (0x12 << 8) 
#define DSP_TYPE_SET_ADPCM_LENGTH (0x13 << 8) 
#define DSP_TYPE_PCM_PLAY (0x14  << 8) 
#define DSP_TYPE_PCM_STOP (0x15  << 8)
#define DSP_TYPE_SET_PCM_VOL (0x1A << 8)
#define DSP_TYPE_SET_PAN (0x6 << 8)  

#define PCM_WAVE_VOLUME_SCALE 4580

// state definitions 
// XWav state 
#define JXWAV_STATE_UNUSED    1 
#define JXWAV_STATE_OPENED    2  
#define JXWAV_STATE_READY     3
#define JXWAV_STATE_PLAYING   4 
#define JXWAV_STATE_ABORT     5 
#define JXWAV_STATE_PAUSED    6 
#define JXWAV_STATE_ENDING    7 
#define JXWAV_STATE_STOP_TIME_UP 8

// Wav state
#define JWAV_STATE_OPENED     21 
#define JWAV_STATE_READY      22
#define JWAV_STATE_PLAYING    23  
#define JWAV_STATE_ABORT      24 
#define JWAV_STATE_PAUSED     25 
#define JWAV_STATE_ENDING     26 

// real-time commands 
typedef enum {
   RT_NONE,    
   RT_START_PLAY, 
   RT_SET_LENGTH, 
   RT_SET_PLAY_PAN, 
   RT_PLAY, 
   RT_PAUSE, 
   RT_STOP, 
   RT_STOP_TIME_UP,
   RT_EOF,   
   RT_REPEAT,
   RT_SET_DIGITAL_GAIN 
} WAV_RT_CMD_TYPE;

// FLAGS list 
// for XWav 
#define XWAV_PLAYING_FLAG     0x1 
#define XWAV_STOPPING_FLAG    0x2 
#define RB_NO_DATA_FLAG       0x4  
#define RB_WAITING_FLAG       0x8
#define BUF_EOF_FLAG          0x10
#define NOT_PROCESS_TIME_FLAG 0x20
#define CHANGE_VOLUME_FLAG    0x40
#define SEND_REPEAT_EVENT     0x80
#define BUF_EOF_STOP_FLAG     0x100

// for Wav 
#define WAV_PLAYING_FLAG      0x1 
#define WAV_STOPPING_FLAG     0x2 
#define REPEAT_FLAG           0x4 
#define DATA_WAITING_FLAG     0x8
#define REACH_WAV_EOF_FLAG    0x10
#define NOT_PROCESS_TIME_FLAG 0x20
#define CHANGE_VOLUME_FLAG    0x40
#define SEND_REPEAT_EVENT     0x80

// for Jwav_Player 
#define XWAV_ON_USE_FLAG      0x1

// other definitions 
#define XBUF_DATA_REQUEST  0x0020
#define BUF_DATA_REQUEST   0x0040
#define MB_DATA_REQUEST    0x0080 

#define JWAV_XWAV_RB_THRESHOLD 500 

#define DEFAULT_XWAV_VOLUME 100
#define DEFAULT_WAV_VOLUME 100

#define DSP_STOP_THEN_START_TIME 4 // 4 * 18ms 
#define MIN_WAV_DUR 36   // 200
#define RELEASE_WAV_DUR    36
#define WAV_CHAN_OFFSET 1

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );

// data structure 
typedef struct{
   uint32 requiredBufSize; 
   uint32 left_data_len; 
   int32 stopTimeCountDown; 
   int16 *data_buf; 
   bool (*WavTransformPutXbuf)(Media_Handle *handle, uint16 free_len);
   dviAdpcm_State dvi_state;
   dviAdpcm_State dvi_state2; 
   uint16 sampling_rate;  
   uint16 buf_read;
   uint16 buf_write;   
   uint16 buf_len; 
   int16 last_fill_sample;         
   uint16 startIndex;
   uint16 blockUnit;      
   uint16 FLAGS;
   uint16 data[7];
   uint8 dvi_count;
   uint8 data_count;
   uint8 minDecodeRbData;
   uint8 dspChannel;
   uint8 pan;   
   WAV_RT_CMD_TYPE rt_command;                     
}XWAV_Player; 

typedef struct 
{
   int32 signal; 
   uint16 step;
}YMH; 

typedef struct{
   Media_Wav_Param Wav_Param;
   uint32 data_len;
   uint32 single_dur; 
   uint32 requiredBufSize;
   uint32 wav_time;
   int16 *data_buf;
   uint16 *data_head;
   uint16 *data_ptr;
   uint16 *data_tail;
   bool (*WavTransformPutBuf)(Media_Handle *handle, uint16 free_len);
   uint8 *data_head8b;
   uint8 *data_ptr8b;
   uint8 *data_tail8b;
   void *callerID;
   YMH ymh;
   dviAdpcm_State dvi_state;
   dviAdpcm_State dvi_state2;
   uint16 buf_len;
   uint16 buf_read;
   uint16 buf_write; 
   uint16 sampling_rate;         
   uint16 startIndex;
   uint16 blockUnit;
   uint16 blockDataSize;
   uint16 FLAGS;
   uint16 data[7]; 
   uint8 dvi_count;
   uint8 data_count;   
   uint8 prepareRepeatTimer;
   uint8 dspChannel;
   uint8 pan;
   WAV_RT_CMD_TYPE rt_command;                
}WAV_Player; 

static struct {
   mediaControl *ctrl;   
   uint16 FLAGS;    
}Jwav_Player;  


/******* wave transform *******/
/* XWav : Wave Transform */
static bool Wav8bitMonoPutXbuf(Media_Handle *handle, uint16 free_len)
{
   XWAV_Player *player = (XWAV_Player *)(handle->data); 
   uint32 rb_data_len, i;  
   uint16 inData, count;
   
   
   if(player->data_count > 0)
   {
      player->data_buf[player->buf_write ++] = player->data[0];      
      free_len -= 1;
   }
   
   while(free_len > 0 && !(player->FLAGS & RB_NO_DATA_FLAG))
   { 
      if(Jwav_Player.ctrl->write >= Jwav_Player.ctrl->read)
      {
         rb_data_len = Jwav_Player.ctrl->write - Jwav_Player.ctrl->read;  
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
            
         if(rb_data_len*2 > free_len)
            count = free_len;
         else{
            count = rb_data_len*2; // 1 16-bit data has 2 sample                    
            if(Jwav_Player.ctrl->eof)               
               player->FLAGS |= BUF_EOF_FLAG;                           
            player->FLAGS |= RB_NO_DATA_FLAG;
         }   
      }else{
         rb_data_len = Jwav_Player.ctrl->rb_size - Jwav_Player.ctrl->read;
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
            
         if(rb_data_len*2 > free_len)
            count = free_len;          
         else
            count = rb_data_len*2; // 1 16-bit data has 2 sample                      
      }
      free_len -= count;
      player->left_data_len -= (count+1)/2;  
      if(player->left_data_len == 0)   
         player->FLAGS |= (BUF_EOF_FLAG + RB_NO_DATA_FLAG); 
      
      for(i = 0; i< count/2; i++){
         inData = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];
         player->data_buf[player->buf_write ++]= (int16)(((inData & 0xFF)<<8)-0x8000);
         player->data_buf[player->buf_write ++]= (int16)((inData & 0xFF00)-0x8000);
      }
      
      if(count & 0x1){  // only possible in rb_data_len*2 > free_len  
         inData = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];
         player->data_buf[player->buf_write ++]= (int16)(((inData & 0xFF)<<8)-0x8000);
         player->data[0] = (int16)((inData & 0xFF00)-0x8000);
         player->data_count = 1;
      }
                  
      if(Jwav_Player.ctrl->read == Jwav_Player.ctrl->rb_size)
         Jwav_Player.ctrl->read = 0;        
   }  
   
   if(free_len > 0)
      return false;
   else
      return true;                                
            
}    

static bool Wav8bitStereoPutXbuf(Media_Handle *handle, uint16 free_len) 
{ 
   XWAV_Player *player = (XWAV_Player *)(handle->data);
   uint32 rb_data_len, i;  
   uint16 count,xtmp;
   
   
   while(free_len > 0 && !(player->FLAGS & RB_NO_DATA_FLAG))
   { 
      if(Jwav_Player.ctrl->write >= Jwav_Player.ctrl->read)
      {
         rb_data_len = Jwav_Player.ctrl->write - Jwav_Player.ctrl->read;
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
           
         if(rb_data_len > free_len)
            count = free_len;
         else{
            count = rb_data_len;                    
            if(Jwav_Player.ctrl->eof)                         
               player->FLAGS |= BUF_EOF_FLAG;    
            player->FLAGS |= RB_NO_DATA_FLAG;                       
         }   
      }else{
         rb_data_len = Jwav_Player.ctrl->rb_size - Jwav_Player.ctrl->read;
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
         
         if(rb_data_len > free_len)
            count = free_len;          
         else
            count = rb_data_len;                   
      }
      free_len -= count;
      player->left_data_len -= count;  
      if(player->left_data_len == 0)   
         player->FLAGS |= (BUF_EOF_FLAG + RB_NO_DATA_FLAG);       
      
      for(i = 0; i< count; i++)
      {
         xtmp = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];
         player->data_buf[player->buf_write ++] = (int16)(((int32)(int16)(((xtmp & 0xFF)<< 8)-0x8000) + (int32)(int16)((xtmp & 0xFF00)-0x8000))/2);
      } 
      if(Jwav_Player.ctrl->read == Jwav_Player.ctrl->rb_size)
         Jwav_Player.ctrl->read = 0;        
   }  
   
   if(free_len > 0)
      return false;
   else
      return true;      
}    

static bool Wav16bitMonoPutXbuf(Media_Handle *handle, uint16 free_len)  
{  
   XWAV_Player *player = (XWAV_Player *)(handle->data) ;
   uint32 rb_data_len, i; 
   uint16 count;
   
   
   while(free_len > 0 && !(player->FLAGS & RB_NO_DATA_FLAG)) 
   { 
      if(Jwav_Player.ctrl->write >= Jwav_Player.ctrl->read)
      {
         rb_data_len = Jwav_Player.ctrl->write - Jwav_Player.ctrl->read; 
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
         
          
         if(rb_data_len > free_len)
            count = free_len;
         else{
            count = rb_data_len;                    
            if(Jwav_Player.ctrl->eof)              
               player->FLAGS |= BUF_EOF_FLAG;                           
            player->FLAGS |= RB_NO_DATA_FLAG;
         }   
      }else{
         rb_data_len = Jwav_Player.ctrl->rb_size - Jwav_Player.ctrl->read;
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
         
         if(rb_data_len > free_len)
            count = free_len;          
         else
            count = rb_data_len;                   
      }
      free_len -= count;
      player->left_data_len -= count;  
      if(player->left_data_len == 0)   
         player->FLAGS |= (BUF_EOF_FLAG + RB_NO_DATA_FLAG); 
            
      for(i = 0; i< count; i++)
         player->data_buf[player->buf_write ++] = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];
      if(Jwav_Player.ctrl->read == Jwav_Player.ctrl->rb_size)
         Jwav_Player.ctrl->read = 0;        
   }  
   
   player->last_fill_sample = player->data_buf[player->buf_write-1];
   
   if(free_len > 0)
      return false;
   else
      return true;  
                                      
}    

static bool Wav16bitStereoPutXbuf(Media_Handle *handle, uint16 free_len)
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ;   
   uint32 rb_data_len, i;
   int32 xtmp;
   uint16 count;
      
   while(free_len > 0 && !(player->FLAGS & RB_NO_DATA_FLAG))
   { 
      if(Jwav_Player.ctrl->write >= Jwav_Player.ctrl->read)
      {
         rb_data_len = Jwav_Player.ctrl->write - Jwav_Player.ctrl->read;  
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
         
         if(rb_data_len/2 > free_len)
            count = free_len;
         else{
            count = rb_data_len/2;                    
            if(Jwav_Player.ctrl->eof)               
               player->FLAGS |= BUF_EOF_FLAG;                          
            player->FLAGS |= RB_NO_DATA_FLAG;
         }   
      }else{
         rb_data_len = Jwav_Player.ctrl->rb_size - Jwav_Player.ctrl->read;
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
            
         if(rb_data_len/2 > free_len)
            count = free_len;          
         else
            count = rb_data_len/2;                   
      }
      free_len -= count;
      player->left_data_len -= count*2;  
      if(player->left_data_len == 0)   
         player->FLAGS |= (BUF_EOF_FLAG + RB_NO_DATA_FLAG); 
            
      for(i = 0; i< count; i++)
      {  
         xtmp = (int16)Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];  
         player->data_buf[player->buf_write ++] = (int16)((xtmp + (int32)(int16)(Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++]))/2);
      }
      if(Jwav_Player.ctrl->read == Jwav_Player.ctrl->rb_size)
         Jwav_Player.ctrl->read = 0;        
   }  
   
   player->last_fill_sample = player->data_buf[player->buf_write-1];
   
   if(free_len > 0)
      return false;
   else
      return true;         
}   
 
static bool WavAlawMonoPutXbuf(Media_Handle *handle, uint16 free_len)  
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
   uint32 rb_data_len, i;    
   uint16 inData, count;
   
   
   if(player->data_count > 0)
   {
      player->data_buf[player->buf_write ++] = player->data[0];      
      free_len -= 1;
   }
   
   while(free_len > 0 && !(player->FLAGS & RB_NO_DATA_FLAG))
   { 
      if(Jwav_Player.ctrl->write >= Jwav_Player.ctrl->read)
      {
         rb_data_len = Jwav_Player.ctrl->write - Jwav_Player.ctrl->read; 
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
          
         if(rb_data_len*2 > free_len)
            count = free_len;
         else{
            count = rb_data_len*2; // 1 16-bit data has 2 sample                    
            if(Jwav_Player.ctrl->eof)               
               player->FLAGS |= BUF_EOF_FLAG;                          
            player->FLAGS |= RB_NO_DATA_FLAG;
         }   
      }else{
         rb_data_len = Jwav_Player.ctrl->rb_size - Jwav_Player.ctrl->read;
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
         
         if(rb_data_len*2 > free_len)
            count = free_len;          
         else
            count = rb_data_len*2; // 1 16-bit data has 2 sample                      
      }
      free_len -= count;
      player->left_data_len -= (count+1)/2;  
      if(player->left_data_len == 0)   
         player->FLAGS |= (BUF_EOF_FLAG + RB_NO_DATA_FLAG); 
      
      
      for(i = 0; i< count/2; i++){
         inData = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];
         player->data_buf[player->buf_write ++]= alaw2linear((uint8)(inData & 0xFF));
         player->data_buf[player->buf_write ++]= alaw2linear((uint8)(inData >> 8));
      }
      
      if(count & 0x1){  // only possible in rb_data_len*2 > free_len  
         inData = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];
         player->data_buf[player->buf_write ++]= alaw2linear((uint8)(inData & 0xFF));
         player->data[0] = alaw2linear((uint8)(inData >> 8));
         player->data_count = 1;
      }
                  
      if(Jwav_Player.ctrl->read == Jwav_Player.ctrl->rb_size)
         Jwav_Player.ctrl->read = 0;        
   }  
   
   player->last_fill_sample = player->data_buf[player->buf_write-1];
   
   if(free_len > 0)
      return false;
   else
      return true;                              
}    

static bool WavAlawStereoPutXbuf(Media_Handle *handle, uint16 free_len) 
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
   uint32 rb_data_len, i;    
   uint16 count, xtmp;
   

   while(free_len > 0 && !(player->FLAGS & RB_NO_DATA_FLAG))
   { 
      if(Jwav_Player.ctrl->write >= Jwav_Player.ctrl->read)
      {
         rb_data_len = Jwav_Player.ctrl->write - Jwav_Player.ctrl->read;
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
           
         if(rb_data_len > free_len)
            count = free_len;
         else{
            count = rb_data_len;                    
            if(Jwav_Player.ctrl->eof)               
               player->FLAGS |= BUF_EOF_FLAG;                           
            player->FLAGS |= RB_NO_DATA_FLAG;
         }   
      }else{
         rb_data_len = Jwav_Player.ctrl->rb_size - Jwav_Player.ctrl->read;
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
         
         if(rb_data_len > free_len)
            count = free_len;          
         else
            count = rb_data_len;                   
      }
      free_len -= count;
      player->left_data_len -= count;  
      if(player->left_data_len == 0)   
         player->FLAGS |= (BUF_EOF_FLAG + RB_NO_DATA_FLAG); 
            
      for(i = 0; i< count; i++)
      {
         xtmp = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];
         player->data_buf[player->buf_write ++] = (int16)(((int32)(int16)alaw2linear((uint8)(xtmp & 0xFF)) + (int32)(int16)alaw2linear((uint8)(xtmp>>8)))/2);
      } 
      if(Jwav_Player.ctrl->read == Jwav_Player.ctrl->rb_size)
         Jwav_Player.ctrl->read = 0;        
   }  
   
   player->last_fill_sample = player->data_buf[player->buf_write-1];
   if(free_len > 0)
      return false;
   else
      return true;    
}  
  
static bool WavUlawMonoPutXbuf(Media_Handle *handle, uint16 free_len) 
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ;
   uint32 rb_data_len, i;   
   uint16 inData, count;
   
   
   if(player->data_count > 0)
   {
      player->data_buf[player->buf_write ++] = player->data[0];      
      free_len -= 1;
   }
   
   while(free_len > 0 && !(player->FLAGS & RB_NO_DATA_FLAG))
   { 
      if(Jwav_Player.ctrl->write >= Jwav_Player.ctrl->read)
      {
         rb_data_len = Jwav_Player.ctrl->write - Jwav_Player.ctrl->read; 
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
             
         if(rb_data_len*2 > free_len)
            count = free_len;
         else{
            count = rb_data_len*2; // 1 16-bit data has 2 sample                    
            if(Jwav_Player.ctrl->eof)               
               player->FLAGS |= BUF_EOF_FLAG;                          
            player->FLAGS |= RB_NO_DATA_FLAG;
         }   
      }else{
         rb_data_len = Jwav_Player.ctrl->rb_size - Jwav_Player.ctrl->read;
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
         
         if(rb_data_len*2 > free_len)
            count = free_len;          
         else
            count = rb_data_len*2; // 1 16-bit data has 2 sample                      
      }
      free_len -= count;
      player->left_data_len -= (count+1)/2;  
      if(player->left_data_len == 0)   
         player->FLAGS |= (BUF_EOF_FLAG + RB_NO_DATA_FLAG); 
      
      for(i = 0; i< count/2; i++){
         inData = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];
         player->data_buf[player->buf_write ++]= ulaw2linear((uint8)(inData & 0xFF));
         player->data_buf[player->buf_write ++]= ulaw2linear((uint8)(inData >> 8));
      }
      
      if(count & 0x1){  // only possible in rb_data_len*2 > free_len  
         inData = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];
         player->data_buf[player->buf_write ++]= ulaw2linear((uint8)(inData & 0xFF));
         player->data[0] = ulaw2linear((uint8)(inData >> 8));
         player->data_count = 1;
      }
                  
      if(Jwav_Player.ctrl->read == Jwav_Player.ctrl->rb_size)
         Jwav_Player.ctrl->read = 0;        
   }  
   
   player->last_fill_sample = player->data_buf[player->buf_write-1];
   if(free_len > 0)
      return false;
   else
      return true;                                
       
}    

static bool WavUlawStereoPutXbuf(Media_Handle *handle, uint16 free_len) 
{  
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
   uint32 rb_data_len, i;  
   uint16 count, xtmp;
   

   while(free_len > 0 && !(player->FLAGS & RB_NO_DATA_FLAG))
   { 
      if(Jwav_Player.ctrl->write >= Jwav_Player.ctrl->read)
      {
         rb_data_len = Jwav_Player.ctrl->write - Jwav_Player.ctrl->read;  
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
            
         if(rb_data_len > free_len)
            count = free_len;
         else{
            count = rb_data_len;                    
            if(Jwav_Player.ctrl->eof)               
               player->FLAGS |= BUF_EOF_FLAG;                          
            player->FLAGS |= RB_NO_DATA_FLAG;
         }   
      }else{
         rb_data_len = Jwav_Player.ctrl->rb_size - Jwav_Player.ctrl->read;
         if(rb_data_len >= player->left_data_len) 
            rb_data_len = player->left_data_len; 
         
         if(rb_data_len > free_len)
            count = free_len;          
         else
            count = rb_data_len;                   
      }
      free_len -= count;
      player->left_data_len -= count;  
      if(player->left_data_len == 0)   
         player->FLAGS |= (BUF_EOF_FLAG + RB_NO_DATA_FLAG); 
      
      for(i = 0; i< count; i++)
      {
         xtmp = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read++];
         player->data_buf[player->buf_write ++] = (int16)(((int32)(int16)ulaw2linear((uint8)(xtmp & 0xFF)) + (int32)(int16)ulaw2linear((uint8)(xtmp>>8)))/2);
      } 
      if(Jwav_Player.ctrl->read == Jwav_Player.ctrl->rb_size)
         Jwav_Player.ctrl->read = 0;        
   }  
   
   player->last_fill_sample = player->data_buf[player->buf_write-1];
   if(free_len > 0)
      return false;
   else
      return true;     
} 


static bool Wav4bitDviAdpcmMonoPutXbuf(Media_Handle *handle, uint16 free_len) 
{  
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
   uint32 dvi_unit, rb_data_len;  
   int32 i;
   uint16 count, inData1, inData2 ;     
   
    
   if(player->data_count > 0)
   {
      if(player->data_count >= free_len)
         count = free_len;
      else
         count = player->data_count;
      for(i=0; i < count ; i++)
         player->data_buf[player->buf_write ++] = player->data[--player->data_count];
         
      free_len -= count;   
   }
             
   while(free_len > 0 && !(player->FLAGS & RB_NO_DATA_FLAG))
   { 
      rb_data_len = Jwav_Player.ctrl->rb_size + Jwav_Player.ctrl->write - Jwav_Player.ctrl->read;  
      
      if(rb_data_len >= Jwav_Player.ctrl->rb_size)
         rb_data_len -= Jwav_Player.ctrl->rb_size;
         
      if(rb_data_len < 2) 
      {
         if(Jwav_Player.ctrl->eof)            
            player->FLAGS |= BUF_EOF_FLAG;    
         player->FLAGS |= RB_NO_DATA_FLAG;
         player->last_fill_sample = player->data_buf[player->buf_write-1];
         return false;
      }   
      
      if(Jwav_Player.ctrl->read < Jwav_Player.ctrl->rb_size - 1)
      {
         inData1 = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read ++];
         inData2 = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read ++];      
         if(Jwav_Player.ctrl->read == Jwav_Player.ctrl->rb_size)
            Jwav_Player.ctrl->read = 0; 
      }
      else if(Jwav_Player.ctrl->read == Jwav_Player.ctrl->rb_size - 1)
      {
         inData1 = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read ++];
         inData2 = Jwav_Player.ctrl->rb_base[0];  
         Jwav_Player.ctrl->read = 1; 
      }
      else
      {
         inData1 = 0;
         inData2 = 0; 
         ASSERT(false);
      }   
         
         
      if(player->dvi_count == 0) // reset block header 
      {
         player->dvi_state.valpred = (int16)inData1;
         player->dvi_state.index = (uint8)(inData2 & 0xFF);
         player->data_buf[player->buf_write ++]= (int16)inData1;
         free_len -= 1;
      }
      else 
      {
         if(free_len >= 8)
            count = 8;
         else
         {
            count = free_len;    
            player->data_count = 8 - count; 
         }   
            
         dvi_unit = (uint32)inData1 + ((uint32)inData2 << 16);    
         
         for(i = 0; i < count ; i ++)
            player->data_buf[player->buf_write ++] = dviAdpcm_Decode((uint8)((dvi_unit>>4*i)&0xF),&player->dvi_state);
            
         for(i = 7-count ; i >= 0 ; i --)
            player->data[i] = dviAdpcm_Decode((uint8)((dvi_unit>>4*(7-i))&0xF),&player->dvi_state);   
         free_len -= count;
      } 
      
      player->left_data_len -= 2;  
      if(player->left_data_len == 0)   
         player->FLAGS |= (BUF_EOF_FLAG + RB_NO_DATA_FLAG);  
      
      player->dvi_count ++;            
      if(player->dvi_count == player->blockUnit >> 1 )
         player->dvi_count = 0;      
   }
   
   player->last_fill_sample = player->data_buf[player->buf_write-1];
   return true;      
}            
      
     
static bool Wav4bitDviAdpcmStereoPutXbuf(Media_Handle *handle, uint16 free_len)
{ 
   XWAV_Player *player = (XWAV_Player *)(handle->data) ;  
   uint32 dvi_unit, dvi_unit2, rb_data_len;
   int32 sampleL, sampleR, i;  
   uint16 count, inData[4];
  
    
   if(player->data_count > 0)
   {
      if(player->data_count >= free_len)
         count = free_len;
      else
         count = player->data_count;
      for(i=0; i < count ; i++)
         player->data_buf[player->buf_write ++] = player->data[--player->data_count];
         
      free_len -= count;   
   }
             
   while(free_len > 0 && !(player->FLAGS & RB_NO_DATA_FLAG))
   { 
      rb_data_len = Jwav_Player.ctrl->rb_size + Jwav_Player.ctrl->write - Jwav_Player.ctrl->read;  
      
      if(rb_data_len >= Jwav_Player.ctrl->rb_size)
         rb_data_len -= Jwav_Player.ctrl->rb_size;
         
      if(rb_data_len < 4) 
      {
         if(Jwav_Player.ctrl->eof)            
            player->FLAGS |= BUF_EOF_FLAG;  
         player->FLAGS |= RB_NO_DATA_FLAG;
         player->last_fill_sample = player->data_buf[player->buf_write-1];
         return false;
      }   
      
      if(Jwav_Player.ctrl->read < Jwav_Player.ctrl->rb_size - 4)
      {
         inData[0] = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read ++];
         inData[1] = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read ++];
         inData[2] = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read ++];
         inData[3] = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read ++];                        
      }
      else if(Jwav_Player.ctrl->read < Jwav_Player.ctrl->rb_size)
      {
         count = Jwav_Player.ctrl->rb_size - Jwav_Player.ctrl->read;
         for(i = 0 ; i < count ; i ++)
            inData[i] = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read ++];
         Jwav_Player.ctrl->read = 0;
         for(i = count ; i< 4 ; i++)
            inData[i] = Jwav_Player.ctrl->rb_base[Jwav_Player.ctrl->read ++];   
      }
      else
         ASSERT(false);
         
         
      if(player->dvi_count == 0) // reset block header 
      {
         player->dvi_state.valpred = (int16)inData[0];
         player->dvi_state.index = (uint8)(inData[1] & 0xFF);
         player->dvi_state2.valpred = (int16)inData[2];
         player->dvi_state2.index = (uint8)(inData[3] & 0xFF);         
         player->data_buf[player->buf_write ++]= (player->dvi_state.valpred + player->dvi_state2.valpred)/2;
         free_len -= 1;
      }
      else 
      {
         if(free_len >= 8)
            count = 8;
         else
         {
            count = free_len;    
            player->data_count = 8 - count; 
         }   
            
         dvi_unit = (uint32)inData[0] + ((uint32)inData[1] << 16);    
         dvi_unit2 = (uint32)inData[2] + ((uint32)inData[3] << 16); 
         
         for(i = 0; i < count ; i ++)
         {  
            sampleL = (int16)dviAdpcm_Decode((uint8)((dvi_unit>>4*i)&0xF),&player->dvi_state);
            sampleR = (int16)dviAdpcm_Decode((uint8)((dvi_unit2>>4*i)&0xF),&player->dvi_state2);
            player->data_buf[player->buf_write ++] = (sampleL + sampleR)/2;
         } 
            
         for(i = 7-count ; i >= 0 ; i --)
         {
            sampleL = (int16)dviAdpcm_Decode((uint8)((dvi_unit>>4*(7-i))&0xF),&player->dvi_state);   
            sampleR = (int16)dviAdpcm_Decode((uint8)((dvi_unit2>>4*(7-i))&0xF),&player->dvi_state2);   
            player->data[i] = (sampleL + sampleR)/2;
         }   
         free_len -= count;
      } 
      
      player->left_data_len -= 4;  
      if(player->left_data_len == 0)   
         player->FLAGS |= (BUF_EOF_FLAG + RB_NO_DATA_FLAG);  
      
      player->dvi_count ++;
      if(player->dvi_count == player->blockUnit >> 2 )  
         player->dvi_count = 0;      
   }
   
   player->last_fill_sample = player->data_buf[player->buf_write-1];
   return true;               
}    

/* Wav : Wave Transform */ 

static bool Wav8bitMonoPutBuf(Media_Handle *handle, uint16 free_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   uint32 wav_data_len, i;
   uint16 inData, count;
   
   
   if(player->data_count > 0)
   {
      player->data_buf[player->buf_write ++] = player->data[0];      
      free_len -= 1;
   }
   
   if(free_len > 0)
   { 
      wav_data_len = player->data_tail - player->data_ptr;
      
      if(wav_data_len * 2 > free_len) 
         count = free_len;
      else
      {
         count = wav_data_len * 2;
         player->FLAGS |= REACH_WAV_EOF_FLAG;   
      }
            
      free_len -= count;
      for(i = 0; i< count/2; i++){
         inData = *player->data_ptr++;
         player->data_buf[player->buf_write ++]= (int16)(((inData & 0xFF)<<8)-0x8000);
         player->data_buf[player->buf_write ++]= (int16)((inData & 0xFF00)-0x8000);
      }
      
      if(count & 0x1){  // only possible in rb_data_len*2 > free_len  
         inData = *player->data_ptr++;
         player->data_buf[player->buf_write ++]= (int16)(((inData & 0xFF)<<8)-0x8000);
         player->data[0] = (int16)((inData & 0xFF00)-0x8000);
         player->data_count = 1;
      }                              
   }  
   
   if(free_len > 0)
      return false;
   else
      return true;                                
     
} 

static bool Wav8bitStereoPutBuf(Media_Handle *handle, uint16 free_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   uint32 wav_data_len, i;
   uint16 count, xtmp;
   

   
   wav_data_len = player->data_tail - player->data_ptr;
      
   if(wav_data_len > free_len) 
      count = free_len;
   else
   {
      count = wav_data_len;
      player->FLAGS |= REACH_WAV_EOF_FLAG;   
   }
         
   free_len -= count;
   for(i = 0; i< count; i++)
   {
      xtmp = *player->data_ptr++;
      player->data_buf[player->buf_write ++] = (int16)(((int32)(int16)(((xtmp & 0xFF)<< 8)-0x8000) + (int32)(int16)((xtmp & 0xFF00)-0x8000))/2);
   } 
       
   if(free_len > 0)
      return false;
   else
      return true;       
} 

static bool Wav16bitMonoPutBuf(Media_Handle *handle, uint16 free_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   uint32 wav_data_len, i;
   uint16 count;
   

   wav_data_len = player->data_tail - player->data_ptr;
      
   if(wav_data_len > free_len) 
      count = free_len;
   else
   {
      count = wav_data_len;
      player->FLAGS |= REACH_WAV_EOF_FLAG;   
   }
                
   free_len -= count;
   for(i = 0; i< count; i++)   
      player->data_buf[player->buf_write ++] = (int16)*player->data_ptr++;    
   
   if(free_len > 0)
      return false;
   else
      return true;         
} 

static bool Wav16bitStereoPutBuf(Media_Handle *handle, uint16 free_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ; 
   uint32 wav_data_len, i;
   int32 xtmp;
   uint16 count;      

   wav_data_len = player->data_tail - player->data_ptr;
      
   if(wav_data_len/2 > free_len) 
      count = free_len;
   else
   {
      count = wav_data_len/2;
      player->FLAGS |= REACH_WAV_EOF_FLAG;   
   }
                
   free_len -= count;
   for(i = 0; i< count; i++)
   {  
      xtmp = (int16)*player->data_ptr++; 
      player->data_buf[player->buf_write ++] = (int16)((xtmp + (int32)(int16)(*player->data_ptr++))/2);
   }   
   
   if(free_len > 0)
      return false;
   else
      return true;         
} 

static bool WavAlawMonoPutBuf(Media_Handle *handle, uint16 free_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   uint32 wav_data_len, i;
   uint16 inData, count;
   
   
   if(player->data_count > 0)
   {
      player->data_buf[player->buf_write ++] = player->data[0];      
      free_len -= 1;
   }   
   
   if(free_len > 0)
   { 
      wav_data_len = player->data_tail - player->data_ptr;
      
      if(wav_data_len * 2 > free_len) 
         count = free_len;
      else
      {
         count = wav_data_len * 2;
         player->FLAGS |= REACH_WAV_EOF_FLAG;   
      }
            
      free_len -= count;
      for(i = 0; i< count/2; i++){
         inData = *player->data_ptr++;
         player->data_buf[player->buf_write ++] = alaw2linear((uint8)(inData & 0xFF));
         player->data_buf[player->buf_write ++] = alaw2linear((uint8)(inData >> 8));
      }
      
      if(count & 0x1){  // only possible in wav_data_len*2 > free_len  
         inData = *player->data_ptr++;
         player->data_buf[player->buf_write ++] = alaw2linear((uint8)(inData & 0xFF));
         player->data[0] = alaw2linear((uint8)(inData >> 8));
         player->data_count = 1;
      }                          
   }  
   
   if(free_len > 0)
      return false;
   else
      return true;                          
}
 
static bool WavAlawStereoPutBuf(Media_Handle *handle, uint16 free_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ; 
   uint32 wav_data_len, i; 
   uint16 count, xtmp;
   

   wav_data_len = player->data_tail - player->data_ptr;
      
   if(wav_data_len > free_len) 
      count = free_len;
   else
   {
      count = wav_data_len;
      player->FLAGS |= REACH_WAV_EOF_FLAG;   
   }
   
   free_len -= count;
   for(i = 0; i< count; i++)
   {
      xtmp = *player->data_ptr++;
      player->data_buf[player->buf_write ++] = (int16)(((int32)(int16)alaw2linear((uint8)(xtmp & 0xFF)) + (int32)(int16)alaw2linear((uint8)(xtmp>>8)))/2);
   } 
      
   if(free_len > 0)
      return false;
   else
      return true;     
} 

static bool WavUlawMonoPutBuf(Media_Handle *handle, uint16 free_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ; 
   uint32 wav_data_len, i; 
   uint16 inData, count;
   
   
   if(player->data_count > 0)
   {
      player->data_buf[player->buf_write ++] = player->data[0];      
      free_len -= 1;
   }   
   
   if(free_len > 0)
   { 
      wav_data_len = player->data_tail - player->data_ptr;
      
      if(wav_data_len * 2 > free_len) 
         count = free_len;
      else
      {
         count = wav_data_len * 2;
         player->FLAGS |= REACH_WAV_EOF_FLAG;   
      }
            
      free_len -= count;
      for(i = 0; i< count/2; i++){
         inData = *player->data_ptr++;
         player->data_buf[player->buf_write ++] = ulaw2linear((uint8)(inData & 0xFF));
         player->data_buf[player->buf_write ++] = ulaw2linear((uint8)(inData >> 8));
      }
      
      if(count & 0x1){  // only possible in wav_data_len*2 > free_len  
         inData = *player->data_ptr++;
         player->data_buf[player->buf_write ++] = ulaw2linear((uint8)(inData & 0xFF));
         player->data[0] = ulaw2linear((uint8)(inData >> 8));
         player->data_count = 1;
      }                          
   }  
   
   if(free_len > 0)
      return false;
   else
      return true;                            
}
 
static bool WavUlawStereoPutBuf(Media_Handle *handle, uint16 free_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ; 
   uint32 wav_data_len, i;
   uint16 count, xtmp;
   

   wav_data_len = player->data_tail - player->data_ptr;
      
   if(wav_data_len > free_len) 
      count = free_len;
   else
   {
      count = wav_data_len;
      player->FLAGS |= REACH_WAV_EOF_FLAG;   
   }
   
   free_len -= count;
   for(i = 0; i< count; i++)
   {
      xtmp = *player->data_ptr++;
      player->data_buf[player->buf_write ++] = (int16)(((int32)(int16)ulaw2linear((uint8)(xtmp & 0xFF)) + (int32)(int16)ulaw2linear((uint8)(xtmp>>8)))/2);
   } 
      
   if(free_len > 0)
      return false;
   else
      return true;     
} 

static bool Wav4bitDviAdpcmMonoPutBuf(Media_Handle *handle, uint16 free_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   uint32 dvi_unit, wav_data_len; 
   int32 i;
   uint16 count, inData1, inData2 ;      
    
   if(player->data_count > 0)
   {
      if(player->data_count >= free_len)
         count = free_len;
      else
         count = player->data_count;
      for(i=0; i < count ; i++)
         player->data_buf[player->buf_write ++] = player->data[--player->data_count];
         
      free_len -= count;   
   }
             
   
   while(free_len > 0 && !(player->FLAGS & REACH_WAV_EOF_FLAG))
   { 
      wav_data_len = player->data_tail - player->data_ptr;            
         
      if(wav_data_len < 2) 
      {
         player->FLAGS |= REACH_WAV_EOF_FLAG;    
         return false;
      }   
      
     
      inData1 = *player->data_ptr++;
      inData2 = *player->data_ptr++;      
                        
      if(player->dvi_count == 0) // reset block header 
      {
         player->dvi_state.valpred = (int16)inData1;
         player->dvi_state.index = (uint8)(inData2 & 0xFF);
         player->data_buf[player->buf_write ++]= (int16)inData1;
         free_len -= 1;
      }
      else 
      {
         if(free_len >= 8)
            count = 8;
         else
         {
            count = free_len;    
            player->data_count = 8 - count; 
         }   
            
         dvi_unit = (uint32)inData1 + ((uint32)inData2 << 16);    
         
         for(i = 0; i < count ; i ++)
            player->data_buf[player->buf_write ++] = dviAdpcm_Decode((uint8)((dvi_unit>>4*i)&0xF),&player->dvi_state);
            
         for(i = 7-count ; i >= 0 ; i --)
            player->data[i] = dviAdpcm_Decode((uint8)((dvi_unit>>4*(7-i))&0xF),&player->dvi_state);   
         free_len -= count;
      }   
      
      player->dvi_count ++;
      if(player->dvi_count == player->blockUnit >> 1 )
         player->dvi_count = 0;
   }
   
   return true;      
}
 
static bool Wav4bitDviAdpcmStereoPutBuf(Media_Handle *handle, uint16 free_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   uint32 dvi_unit, dvi_unit2, wav_data_len;
   int32 sampleL, sampleR, i;  
   uint16 count, inData[4];  
    
   if(player->data_count > 0)
   {
      if(player->data_count >= free_len)
         count = free_len;
      else
         count = player->data_count;
      for(i=0; i < count ; i++)
         player->data_buf[player->buf_write ++] = player->data[--player->data_count];
         
      free_len -= count;   
   }
   
   while(free_len > 0 && !(player->FLAGS & REACH_WAV_EOF_FLAG))
   { 
      wav_data_len = player->data_tail - player->data_ptr;  
            
      if(wav_data_len < 4) 
      {
         player->FLAGS |= REACH_WAV_EOF_FLAG;    
         return false;
      }   
      
      
      inData[0] = *player->data_ptr++;
      inData[1] = *player->data_ptr++;
      inData[2] = *player->data_ptr++;
      inData[3] = *player->data_ptr++;                        
               
         
      if(player->dvi_count == 0) // reset block header 
      {
         player->dvi_state.valpred = (int16)inData[0];
         player->dvi_state.index = (uint8)(inData[1] & 0xFF);
         player->dvi_state2.valpred = (int16)inData[2];
         player->dvi_state2.index = (uint8)(inData[3] & 0xFF);         
         player->data_buf[player->buf_write ++] = ((int32)player->dvi_state.valpred + (int32)player->dvi_state2.valpred)/2;
         free_len -= 1;
      }
      else 
      {
         if(free_len >= 8)
            count = 8;
         else
         {
            count = free_len;    
            player->data_count = 8 - count; 
         }   
            
         dvi_unit = (uint32)inData[0] + ((uint32)inData[1] << 16);    
         dvi_unit2 = (uint32)inData[2] + ((uint32)inData[3] << 16); 
         
         for(i = 0; i < count ; i ++)
         {  
            sampleL = (int16)dviAdpcm_Decode((uint8)((dvi_unit>>4*i)&0xF),&player->dvi_state);
            sampleR = (int16)dviAdpcm_Decode((uint8)((dvi_unit2>>4*i)&0xF),&player->dvi_state2);
            player->data_buf[player->buf_write ++] = (sampleL + sampleR)/2;
         } 
            
         for(i = 7-count ; i >= 0 ; i --)
         {
            sampleL = (int16)dviAdpcm_Decode((uint8)((dvi_unit>>4*(7-i))&0xF),&player->dvi_state);   
            sampleR = (int16)dviAdpcm_Decode((uint8)((dvi_unit2>>4*(7-i))&0xF),&player->dvi_state2);   
            player->data[i] = (sampleL + sampleR)/2;
         }   
         free_len -= count;
      }   
      
      player->dvi_count ++;
      if(player->dvi_count == player->blockUnit >> 2 )  
         player->dvi_count = 0; 
   }
   
   return true;      
    
} 
 
/* check wave header and assign correct wave transform method */ 
static uint32 Get32bit(uint8 *s )
{
   return ((uint32)s[3] << 24) + ((uint32)s[2] << 16) + ((uint32)s[1] << 8) + (uint32)s[0];
}

static uint16 Get16bit(uint8 *s )
{
   return (uint16)(((uint16)s[1] << 8) + (uint16)s[0]);
}

/* XWav : check header */ 
static bool checkXWavHeader(Media_Handle *handle)
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
   uint8 *wavPtr, *ptr, *endPtr;
   uint32 us32intValue;
   uint16 us16intValue;
       
   wavPtr =(uint8 *)&(Jwav_Player.ctrl->rb_base[0]);  
   if( wavPtr[0] != 'R' || wavPtr[1] != 'I' || wavPtr[2] != 'F' || wavPtr[3] != 'F' )
      return false;
   
   us32intValue =Get32bit(wavPtr+4); 
   if(us32intValue == 0) // this check may be neglected  
      return false;
   
   if( wavPtr[8] != 'W' || wavPtr[9] != 'A' || wavPtr[10] != 'V' || wavPtr[11] != 'E' )
      return false;
   
   if( wavPtr[12] != 'f' || wavPtr[13] != 'm' || wavPtr[14] != 't' || wavPtr[15] != ' ' )
      return false;
   
   us32intValue = Get32bit(wavPtr+16);
   if( (us32intValue != 16) && (us32intValue != 18) && (us32intValue != 20) )
      return false;
      
   ptr = (wavPtr + 20 + us32intValue);
   endPtr = (wavPtr + 2 * Jwav_Player.ctrl->write);
   while(1)
   {
      if( ptr[0] != 'd' || ptr[1] != 'a' || ptr[2] != 't' || ptr[3] != 'a' ) 
      {
         us32intValue = Get32bit(ptr+4);
         ptr += (8 + us32intValue);
         if(ptr > endPtr)
            return false;
      }
      else 
      {
         us32intValue = (uint32)(ptr + 8 - wavPtr);
         player->left_data_len = Get32bit(ptr+4) >> 1;  
         Jwav_Player.ctrl->read += us32intValue >> 1;  
         break;     
      }  
   }
   
   player->minDecodeRbData = 1; 
   
   us16intValue = Get16bit(wavPtr+20);   
   switch(us16intValue){
      case 0x0001: // MEDIA_FORMAT_WAV
         us16intValue = Get16bit(wavPtr+22); // channel 
         if(us16intValue == 1){
            us16intValue = Get16bit(wavPtr+34);
            if(us16intValue == 8) 
               player->WavTransformPutXbuf = Wav8bitMonoPutXbuf;
            else if(us16intValue == 16)
               player->WavTransformPutXbuf = Wav16bitMonoPutXbuf;
            else 
               return false;        
         }
         else if(us16intValue == 2){
            us16intValue = Get16bit(wavPtr+34);
            if(us16intValue == 8) 
               player->WavTransformPutXbuf = Wav8bitStereoPutXbuf;
            else if(us16intValue == 16)
            {
               player->WavTransformPutXbuf = Wav16bitStereoPutXbuf;
               player->minDecodeRbData = 2;
            }   
            else 
               return false;                    
         }
         else
            return false;           
         break;
      case 0x0006: // MEDIA_FORMAT_WAV_ALAW 
         us16intValue = Get16bit(wavPtr+22); // channel 
         if(us16intValue == 1)
            player->WavTransformPutXbuf = WavAlawMonoPutXbuf;   
         else if(us16intValue == 2)
            player->WavTransformPutXbuf = WavAlawStereoPutXbuf;
         else
            return false;                  
         
         break;
      case 0x0007: // MEDIA_FORMAT_WAV_ULAW 
         us16intValue = Get16bit(wavPtr+22); // channel 
         if(us16intValue == 1)
            player->WavTransformPutXbuf = WavUlawMonoPutXbuf;   
         else if(us16intValue == 2)
            player->WavTransformPutXbuf = WavUlawStereoPutXbuf;
         else
            return false;                
              
         break;
      case 0x0011: // MEDIA_FORMAT_WAV_DVI_ADPCM 
         // check DVI-ADPCM case
         us16intValue = Get16bit(wavPtr+34);
         if(us16intValue != 4)  // support 4-bit DVI-ADPCM only
            return false;
         us16intValue = Get16bit(wavPtr+22); // channel
         if(us16intValue == 1)
         {
            player->WavTransformPutXbuf = Wav4bitDviAdpcmMonoPutXbuf;
            player->minDecodeRbData = 2;
         } 
         else if(us16intValue == 2)
         {
            player->WavTransformPutXbuf = Wav4bitDviAdpcmStereoPutXbuf;
            player->minDecodeRbData = 4;
         } 
         else 
            return false;
         us16intValue = Get16bit(wavPtr+32); // block_align 
         player->blockUnit = us16intValue >> 1;               
         player->dvi_count = 0;
         
         break;
      default: 
         return false;
   }                  
  
   us32intValue = Get32bit(wavPtr+24);
   if(us32intValue > 0xFFFF)
      return false;
   else        
      player->sampling_rate = (uint16) us32intValue; 
   
   player->requiredBufSize =  player->sampling_rate * 90 / 1000;  
                  
   return true;
}

/* Wav : check header */ 

static bool checkWavHeader(Media_Handle *handle)  
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;  
   uint8 *wavPtr, *ptr;
   uint32 us32intValue, riff_size;
   uint16 us16intValue;
   
   wavPtr = (uint8 *)player->Wav_Param.wavefile;   
      
    
   if( wavPtr[0] != 'R' || wavPtr[1] != 'I' || wavPtr[2] != 'F' || wavPtr[3] != 'F' )
      return false;
   
   riff_size =Get32bit(wavPtr+4); 
   if(riff_size == 0) // this check may be neglected  
      return false;
      
   if(player->Wav_Param.filesize < riff_size)
      return false;  // failed at filesize check                  
   
   if( wavPtr[8] != 'W' || wavPtr[9] != 'A' || wavPtr[10] != 'V' || wavPtr[11] != 'E' )
      return false;
   
   if( wavPtr[12] != 'f' || wavPtr[13] != 'm' || wavPtr[14] != 't' || wavPtr[15] != ' ' )
      return false;
   
   us32intValue = Get32bit(wavPtr+16);
   if( (us32intValue != 16) && (us32intValue != 18) && (us32intValue != 20) )
      return false;

   ptr = (wavPtr + 20 + us32intValue); 

   while(1) 
   {
      if( ptr[0] != 'd' || ptr[1] != 'a' || ptr[2] != 't' || ptr[3] != 'a' )
      {
         us32intValue = Get32bit(ptr + 4);
         ptr += (8 + us32intValue);
         if(ptr > wavPtr + 8 + riff_size) 
            return false;      
      }   
      else 
      {
         us32intValue = Get32bit(ptr + 4);  
         player->data_len = us32intValue;
         player->data_head = (uint16 *)(ptr + 8); 
         player->data_tail = (uint16 *)(ptr + 8 + us32intValue); 
         break;
      }   
   }

   
   us16intValue = Get16bit(wavPtr+20);  // format type   
   switch(us16intValue){
      case 0x0001: // MEDIA_FORMAT_WAV         
         us16intValue = Get16bit(wavPtr+22); // channel 
         if(us16intValue == 1){
            us16intValue = Get16bit(wavPtr+34);
            if(us16intValue == 8)
            {
               player->blockUnit = 1;
               player->blockDataSize = 2;                   
               player->WavTransformPutBuf = Wav8bitMonoPutBuf;                                           
            }   
            else if(us16intValue == 16)
            {           
               player->blockUnit = 1;
               player->blockDataSize = 1;                   
               player->data_len >>= 1;      
               player->WavTransformPutBuf = Wav16bitMonoPutBuf;                   
            }   
            else 
               return false;        
         }
         else if(us16intValue == 2){
            us16intValue = Get16bit(wavPtr+34);
            if(us16intValue == 8) 
            {
               player->blockUnit = 1;
               player->blockDataSize = 1;
               player->data_len >>= 1; 
               player->WavTransformPutBuf  = Wav8bitStereoPutBuf;
            }
            else if(us16intValue == 16)
            {
               player->blockUnit = 2;
               player->blockDataSize = 1;
               player->data_len >>= 2; 
               player->WavTransformPutBuf  = Wav16bitStereoPutBuf;
            }
            else 
               return false;                    
         }
         else
            return false;  
         
         break;
      case 0x0006: // MEDIA_FORMAT_WAV_ALAW 
         
         us16intValue = Get16bit(wavPtr+22); // channel 
         if(us16intValue == 1)
         {
            player->blockUnit = 1;
            player->blockDataSize = 2;
            player->WavTransformPutBuf  = WavAlawMonoPutBuf;   
         }   
         else if(us16intValue == 2)
         {
            player->blockUnit = 1;
            player->blockDataSize = 1;
            player->data_len >>= 1; 
            player->WavTransformPutBuf  = WavAlawStereoPutBuf;
         }
         else
            return false;

         break;
      case 0x0007: // MEDIA_FORMAT_WAV_ULAW 

         us16intValue = Get16bit(wavPtr+22); // channel 
         if(us16intValue == 1)
         {
            player->blockUnit = 1;
            player->blockDataSize = 2;
            player->WavTransformPutBuf  = WavUlawMonoPutBuf;   
         }
         else if(us16intValue == 2)
         {
            player->blockUnit = 1;
            player->blockDataSize = 1;
            player->data_len >>= 1; 
            player->WavTransformPutBuf  = WavUlawStereoPutBuf;
         }
         else
            return false;
         
              
         break;
      case 0x0011: // MEDIA_FORMAT_WAV_DVI_ADPCM 
         // check DVI-ADPCM case
         
         us16intValue = Get16bit(wavPtr+34); // bits per sample 
         if(us16intValue != 4)  // support only 4-bit DVI-ADPCM  
            return false;             
         us16intValue = Get16bit(wavPtr+22); // channel
         if(us16intValue == 1)
         {
            uint32 data_len;
            us16intValue = Get16bit(wavPtr+32); // block_align 
            player->blockUnit = us16intValue >> 1;
            data_len = player->data_len; 
            player->data_len /= us16intValue;
            data_len -= player->data_len * us16intValue;
            player->blockDataSize = ((us16intValue - 4) * 2 + 1);  
            player->data_len *= player->blockDataSize; 
            if(data_len >= 4) 
               player->data_len += ((data_len-4) *2 + 1);
            player->WavTransformPutBuf  = Wav4bitDviAdpcmMonoPutBuf;
         }
         else if(us16intValue == 2)
         {
            uint32 data_len;
            us16intValue = Get16bit(wavPtr+32); // block_align
            if (us16intValue == 0)
               return false;
            player->blockUnit = us16intValue >> 1;  
            data_len = player->data_len; 
            player->data_len /= us16intValue;  
            data_len -= player->data_len * us16intValue;
            player->blockDataSize = (((us16intValue >> 1) - 4) * 2 + 1);           
            player->data_len *= player->blockDataSize;
            if(data_len >= 8) 
               player->data_len += (((data_len >> 1) - 4) *2 + 1);
            player->WavTransformPutBuf  = Wav4bitDviAdpcmStereoPutBuf;
         }   
         else 
            return false;                             
         player->dvi_count = 0;         
         break;
      default: 
         return false;
   }                  
   
   
   us32intValue = Get32bit(wavPtr+24);
   if(us32intValue > 0xFFFF)
      return false;
   else  
      player->sampling_rate = (uint16) us32intValue; 
       
   player->requiredBufSize = player->sampling_rate * 54 / 1000;        
                   
   return true;
}

/*** Wave Data to DSP Buffer ***/

static void wavWriteToXWavBuffer(Media_Handle *handle)
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ;
   uint32 rb_data_len, i;   
   uint16 free_space, count;   
   int16 last_fill_sample;
   
   if(Jwav_Player.ctrl->read== Jwav_Player.ctrl->write) // check if MediaBuffer has data 
   {
      if(Jwav_Player.ctrl->eof)                
         player->FLAGS |= BUF_EOF_FLAG;
         
      player->FLAGS |= RB_NO_DATA_FLAG;      
   }   
   else  
   {
      rb_data_len = Jwav_Player.ctrl->rb_size + Jwav_Player.ctrl->write - Jwav_Player.ctrl->read;  
      
      if(rb_data_len >= Jwav_Player.ctrl->rb_size)
         rb_data_len -= Jwav_Player.ctrl->rb_size;
         
      if(rb_data_len < player->minDecodeRbData)
            player->FLAGS |= RB_NO_DATA_FLAG;             
      else    
         player->FLAGS &= ~RB_NO_DATA_FLAG;      
   }     
      
   player->buf_read = DSP_WAV_PLAYEDINDEX(handle->index); 
   
   free_space = player->buf_len - 1 + player->buf_read - player->buf_write;
   if(free_space >= player->buf_len)
      free_space -= player->buf_len;

   if(player->data_count > 0)
   {
      if(player->data_count >= free_space)
         count = free_space;
      else
         count = player->data_count;
      for(i=0; i < count ; i++)
      {
         player->data_buf[player->buf_write ++] = player->data[--player->data_count];
         if(player->buf_write == player->buf_len)
            player->buf_write = 0;
      }
         
      free_space -= count; 
      player->last_fill_sample = player->data_buf[player->buf_write-1];     
   }
   
    
   if(player->FLAGS & BUF_EOF_FLAG)
      return; 
      
   last_fill_sample = player->last_fill_sample;
   while(free_space > 0 && (player->FLAGS & RB_NO_DATA_FLAG))
   {
      if((player->buf_read-1) >= player->buf_write)
         count = player->buf_read-1-player->buf_write;
      else{
         if(player->buf_read == 0) 
            count = player->buf_len -1 - player->buf_write;
         else 
            count = player->buf_len - player->buf_write;          
      }
      
      for(i = 0 ; i < count ; i++)        
        player->data_buf[player->buf_write ++] = last_fill_sample; 
      
      free_space -= count;
      if(player->buf_write == player->buf_len)
         player->buf_write = 0;
   }                         

   while(free_space > 0 && !(player->FLAGS & RB_NO_DATA_FLAG))
   {
      if((player->buf_read-1) >= player->buf_write)
         count = player->buf_read-1-player->buf_write;
      else{
         if(player->buf_read == 0) 
            count = player->buf_len -1 - player->buf_write;
         else 
            count = player->buf_len - player->buf_write;          
      }
      
      if(player->WavTransformPutXbuf(handle, count))
         free_space -= count;
      if(player->buf_write == player->buf_len)
         player->buf_write = 0;
   }                          
}      
        
        
void JXwav_WriteDataDone(Media_Handle *handle, uint32 len )
{
   Jwav_Player.ctrl->write += len;
   if( Jwav_Player.ctrl->write >= Jwav_Player.ctrl->rb_size )
      Jwav_Player.ctrl->write = 0;
 
   ((XWAV_Player*)handle->data)->FLAGS &= ~RB_WAITING_FLAG;
}


static void wavWriteToWavBuf(Media_Handle *handle)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   uint16 free_space, count;
        
   if(player->FLAGS& REACH_WAV_EOF_FLAG ) // check if has data 
      return;   
            
   
   player->buf_read = DSP_WAV_PLAYEDINDEX(handle->index); 
   
   free_space = player->buf_len - 1 + player->buf_read - player->buf_write;
   if(free_space >= player->buf_len)
      free_space -= player->buf_len;
         
   while(free_space > 0 && !(player->FLAGS & REACH_WAV_EOF_FLAG))
   {
      if((player->buf_read-1) >= player->buf_write)
         count = player->buf_read-1-player->buf_write;
      else{
         if(player->buf_read == 0) 
            count = player->buf_len -1 - player->buf_write;
         else 
            count = player->buf_len - player->buf_write;          
      }
      
      if(player->WavTransformPutBuf(handle,count))
         free_space -= count;
      if(player->buf_write == player->buf_len)
         player->buf_write = 0;
   }                         
}


static void JXWavEndHandler(Media_Handle *handle)
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ;  
   if(handle->state != JXWAV_STATE_PAUSED)
      handle->state = JXWAV_STATE_READY;
   
   player->FLAGS &= ~XWAV_PLAYING_FLAG;
    
   if(player->FLAGS & XWAV_STOPPING_FLAG)// EOF or STOP_TIME_UP
   {
      handle->handler(handle, MEDIA_END);        
      player->FLAGS &= ~XWAV_STOPPING_FLAG;
   }      
           
}


static void JWavEndHandler(Media_Handle *handle)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;  
      
   if(handle->state != JWAV_STATE_PAUSED)
      handle->state = JWAV_STATE_READY;
   
   player->FLAGS &= ~WAV_PLAYING_FLAG;
   
   JWAV_TRACE( MOD_L1SP, "JWEHnd %d", handle );
   if(player->FLAGS & WAV_STOPPING_FLAG) // EOF or STOP_TIME_UP
   {
      handle->handler(handle, MEDIA_END);
      player->FLAGS &=  ~WAV_STOPPING_FLAG;      
   }      
}


/*** Real-Time Command Process ***/

static void JXWavGetCommand(Media_Handle *handle, uint16 *dtime, uint16 cmd[4])
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
   uint32 xbuf_data_len,autoStopTime;
   
   if(cmd == 0)
   {
      uint32 savedMask;
      wavWriteToXWavBuffer(handle);        
      if((player->FLAGS & RB_WAITING_FLAG)||Jwav_Player.ctrl->eof) 
         return;
      if(mediaGetFreeSpace() >= JWAV_XWAV_RB_THRESHOLD){ 
         savedMask = SaveAndSetIRQMask();
         player->FLAGS |= RB_WAITING_FLAG;
         RestoreIRQMask( savedMask );
         handle->handler(handle, MEDIA_DATA_REQUEST);                                           
      }          
      return;                    
   }
      
   if(handle->stop_flag)
   {
      if(handle->state == JXWAV_STATE_ENDING || handle->state == JXWAV_STATE_STOP_TIME_UP)
         cmd[0] = DSPSYN_CMD_END;
      else 
         cmd[0] = DSPSYN_CMD_STOP; // PAUSED or ABORT    
      return;
   }
   
   if(handle->state == JXWAV_STATE_PLAYING)
   {
   #if !(defined(MT6223) || defined(MT6223P))	      
      if(player->FLAGS & CHANGE_VOLUME_FLAG) 
      {
         cmd[0] = 2;      
         cmd[1] = DSP_TYPE_SET_PCM_VOL + player->dspChannel;                 
         cmd[2] = (uint16)(((uint32) handle->volume_level * PCM_WAVE_VOLUME_SCALE) / 100) ;                   
         player->FLAGS  &= ~CHANGE_VOLUME_FLAG;
         return;
      }   
	#endif       
      if(player->FLAGS & NOT_PROCESS_TIME_FLAG)
      {       
         *dtime = 0; // do not process time here , since we want to send PC start at this moment                      // this process should expand to play & resume cases     
      }
      else if(*dtime > 0) // process time only one time 
      {                 
         handle->current_time += *dtime;                              
         player->stopTimeCountDown -= *dtime;
         if(player->stopTimeCountDown < 36) // stop case by stopTime   
         {
            handle->current_time += player->stopTimeCountDown;             
            if(player->FLAGS & BUF_EOF_FLAG)
               player->rt_command = RT_EOF;
            else      
               player->rt_command = RT_STOP_TIME_UP;
         }
         *dtime = 0;
      }
      
      if(player->rt_command != RT_NONE)
      {
         switch(player->rt_command){
            case RT_START_PLAY: 
               cmd[0] = 3;
               cmd[1] = DSP_TYPE_SET_BUF_ADDR + player->dspChannel;
               cmd[2] = (uint16)((uint32)player->data_buf & 0xFFFF);
               cmd[3] = (uint16)(((uint32)player->data_buf)>>16);
               player->FLAGS &=  ~NOT_PROCESS_TIME_FLAG;
               player->rt_command = RT_SET_LENGTH;
               return;
            case RT_SET_LENGTH: 
               cmd[0] = 3;
               cmd[1] = DSP_TYPE_SET_PCM_LENGTH + player->dspChannel;
               cmd[2] = player->buf_len;
               cmd[3] = player->sampling_rate;
               player->rt_command = RT_SET_PLAY_PAN;
               return;
            case RT_SET_PLAY_PAN: 
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_SET_PAN + player->dspChannel;
               cmd[2] = 64;
               player->rt_command = RT_SET_DIGITAL_GAIN;
               return;
            case RT_SET_DIGITAL_GAIN:
               cmd[0] = 2;
               cmd[1] = 0x400 + player->dspChannel;
               cmd[2] = 0x100;
               player->rt_command = RT_PLAY;
               return;   
            case RT_PLAY: 
               cmd[0] = 3;
               cmd[1] = DSP_TYPE_PCM_PLAY + player->dspChannel;        
               cmd[2] = player->startIndex; 
            #if defined(MT6223) || defined(MT6223P)   
               cmd[3] = (uint16)(((uint32) handle->volume_level * 16000) / 100);   
            #else               
               cmd[3] = (uint16)(((uint32) handle->volume_level * PCM_WAVE_VOLUME_SCALE) / 100);
            #endif    
               player->rt_command = RT_NONE;
               return;
            case RT_PAUSE:    
               handle->state = JXWAV_STATE_PAUSED;
               player->buf_read = DSP_WAV_PLAYEDINDEX(handle->index); 
               player->startIndex = player->buf_read;
               handle->start_time = handle->current_time;
               handle->stop_flag = true;
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_PCM_STOP + player->dspChannel;
               cmd[2] = 0;
               player->rt_command = RT_NONE;
               return;
               
            case RT_STOP:
               handle->state = JXWAV_STATE_ABORT;
               handle->stop_flag = true;
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_PCM_STOP + player->dspChannel;
               cmd[2] = 0;
               player->rt_command = RT_NONE;
               return;
            
            case RT_STOP_TIME_UP: 
               handle->state = JXWAV_STATE_STOP_TIME_UP;
               handle->stop_flag = true;
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_PCM_STOP + player->dspChannel;
               cmd[2] = 0;               
               player->FLAGS |= XWAV_STOPPING_FLAG;
               player->rt_command = RT_NONE;   
               return;
               
            case RT_EOF: 
               handle->state = JXWAV_STATE_ENDING;
               handle->stop_flag = true;
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_PCM_STOP + player->dspChannel;
               cmd[2] = 0;               
               player->FLAGS |= XWAV_STOPPING_FLAG;
               player->rt_command = RT_NONE;   
               return;   
               
            default:
               ASSERT(false);
        }
      }else{                
         if(!(player->FLAGS & BUF_EOF_STOP_FLAG))
         { 
            player->buf_read = DSP_WAV_PLAYEDINDEX(handle->index);            
            if(player->FLAGS & BUF_EOF_FLAG)
            {
               xbuf_data_len = player->buf_write + player->buf_len - player->buf_read;
               if(xbuf_data_len >= player->buf_len)                
                  xbuf_data_len -= player->buf_len;
               
               autoStopTime = (xbuf_data_len * 1000) / player->sampling_rate;
               if(autoStopTime < 36)// stop instantly 
               {
                  handle->current_time += autoStopTime;
                  handle->state = JXWAV_STATE_ENDING;
                  handle->stop_flag = true;
                  cmd[0] = 2;
                  cmd[1] = DSP_TYPE_PCM_STOP + player->dspChannel;
                  cmd[2] = 0;                  
                  player->FLAGS |= XWAV_STOPPING_FLAG;
                  player->rt_command = RT_NONE;
               }
               
               if(autoStopTime < player->stopTimeCountDown)
                  player->stopTimeCountDown = autoStopTime;
                         
               player->FLAGS |= BUF_EOF_STOP_FLAG;
            }// end of if(player->FLAGS & BUF_EOF_FLAG)                                     
         }//end of  if(!(player->FLAGS & BUF_EOF_STOP_FLAG))
      }//end of else of if(Jwav.XWav.rt_command != RT_NONE)
   } // end of if(state == PLAYING)
  
   cmd[0]= 0;
}
 
 

static void JWavGetCommand(Media_Handle *handle, uint16 *dtime, uint16 cmd[4])
{
   WAV_Player *player = (WAV_Player *)(handle->data) ; 
   
   if(cmd == 0)
   {
      uint32 savedMask;
      wavWriteToWavBuf(handle);
      if(player->FLAGS & SEND_REPEAT_EVENT)
         handle->handler(handle,MEDIA_REPEATED);
      savedMask = SaveAndSetIRQMask();
      player->FLAGS &= ~(DATA_WAITING_FLAG + SEND_REPEAT_EVENT);
      RestoreIRQMask( savedMask ); 
      return;
   }
          
   if(handle->stop_flag)
   {
      if(handle->state == JWAV_STATE_ENDING)      
         cmd[0] = DSPSYN_CMD_END;
      else 
         cmd[0] = DSPSYN_CMD_STOP; // PAUSED or ABORT    
         
      JWAV_TRACE( MOD_L1SPHISR, "JWSFlag %d %d", handle, cmd[0] );         
      return;
   }     
   
   if(player->FLAGS & REPEAT_FLAG)
   {
      player->prepareRepeatTimer = DSP_STOP_THEN_START_TIME;      
      player->FLAGS &= ~REPEAT_FLAG;
      cmd[0] = 0;
      return;
   }
   
   if(player->prepareRepeatTimer > 0) 
   {
      if(player->rt_command == RT_STOP)
      {
         handle->state = JWAV_STATE_ABORT;
         handle->stop_flag = true;
         cmd[0] = DSPSYN_CMD_STOP;
         return;           
      }
      if(player->rt_command == RT_PAUSE)
      {                                    
         player->prepareRepeatTimer = 0;
         handle->state = JWAV_STATE_PAUSED;
         handle->stop_flag = true;
         handle->start_time = handle->current_time;               
         player->buf_read = DSP_WAV_PLAYEDINDEX(handle->index); 
         player->startIndex = player->buf_read;  
         cmd[0] = DSPSYN_CMD_STOP;
         return;   
      }  
      player->prepareRepeatTimer --;
      if(player->prepareRepeatTimer ==0)
      {         
            player->buf_read = 0;
            player->buf_write = 0;
            player->dvi_count = 0;
            player->data_count = 0;
            player->wav_time = 0;
            player->data_ptr = player->data_head;            
            player->FLAGS |= DATA_WAITING_FLAG; 
            player->FLAGS &= ~REACH_WAV_EOF_FLAG;   
        
         player->startIndex = 0; 
         DSP_WAV_PLAYEDINDEX(handle->index) = player->startIndex;
         player->rt_command = RT_START_PLAY;            
         player->FLAGS |= (NOT_PROCESS_TIME_FLAG + SEND_REPEAT_EVENT);   
         
         //handle->handler(handle,MEDIA_REPEATED);                                                                         
      }
      else 
      {
         cmd[0] = 0;
         return;
      }
   }
   
   
   if(handle->state == JWAV_STATE_PLAYING)
   {
	#if !(defined(MT6223) || defined(MT6223P))   	
      if( player->FLAGS & CHANGE_VOLUME_FLAG ) 
      {
         cmd[0] = 2;       
         cmd[1] = DSP_TYPE_SET_PCM_VOL + player->dspChannel;         
         cmd[2] = (uint16)(((uint32) handle->volume_level * PCM_WAVE_VOLUME_SCALE) / 100);          
         player->FLAGS  &= ~CHANGE_VOLUME_FLAG;
         return;
      }   
	#endif       
      if(player->FLAGS & NOT_PROCESS_TIME_FLAG)
      {       
         *dtime = 0; // do not process time here , since we want to send PC start at this moment                      // this process should expand to play & resume cases     
      }
      else if(*dtime > 0) // process time only one time 
      {                 
         handle->current_time += *dtime;              
         player->wav_time += *dtime;
         
         if(handle->stop_time != 0x7FFFFFFF)      
         {
            if(handle->current_time >  handle->stop_time - RELEASE_WAV_DUR)
            {
                player->rt_command = RT_EOF; 
                handle->current_time = handle->stop_time; 
            }                
         }
         
         
         if(player->wav_time > player->single_dur - RELEASE_WAV_DUR && player->rt_command != RT_EOF && player->rt_command != RT_STOP)   
         {             
            if(handle->repeat_count == 1)
            {
               player->rt_command = RT_EOF;                                  
            }
            else 
            {
               if(handle->repeat_count > 1) 
                  handle->repeat_count -= 1; 
                  
               if(player->rt_command != RT_PAUSE)                 
                  player->rt_command = RT_REPEAT;   
            }
            
            handle->current_time += player->single_dur - player->wav_time;    
         }
         *dtime = 0;
      }
      
      if(player->rt_command != RT_NONE)
      {
         switch(player->rt_command){
            case RT_START_PLAY: 
               if(player->FLAGS & DATA_WAITING_FLAG)
               {
                  cmd[0] = 0;
                  return;
               }   
               cmd[0] = 3;
               cmd[1] = DSP_TYPE_SET_BUF_ADDR + player->dspChannel;
               cmd[2] = (uint16)((uint32)player->data_buf & 0xFFFF);
               cmd[3] = (uint16)(((uint32)player->data_buf)>>16);
               player->FLAGS &=  ~NOT_PROCESS_TIME_FLAG;
               player->rt_command = RT_SET_LENGTH;
               return;
            case RT_SET_LENGTH: 
               cmd[0] = 3;
               cmd[1] = DSP_TYPE_SET_PCM_LENGTH + player->dspChannel;
               cmd[2] = player->buf_len;
               cmd[3] = player->sampling_rate;
               player->rt_command = RT_SET_PLAY_PAN;
               return;
            case RT_SET_PLAY_PAN: 
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_SET_PAN + player->dspChannel;
               cmd[2] = player->pan;
               player->rt_command = RT_SET_DIGITAL_GAIN;
               return;
            case RT_SET_DIGITAL_GAIN:
               cmd[0] = 2;
               cmd[1] = 0x400 + player->dspChannel;
               cmd[2] = 0x100;
               player->rt_command = RT_PLAY;
               return;   
            case RT_PLAY: 
               cmd[0] = 3;
               cmd[1] = DSP_TYPE_PCM_PLAY + player->dspChannel;        
               cmd[2] = player->startIndex;   
            #if defined(MT6223) || defined(MT6223P)   
               cmd[3] = (uint16)(((uint32) handle->volume_level * 16000) / 100);  
            #else                
               cmd[3] = (uint16)(((uint32) handle->volume_level * PCM_WAVE_VOLUME_SCALE) / 100);                
            #endif    
               player->rt_command = RT_NONE;
               return;              
            case RT_PAUSE:    
               handle->state = JWAV_STATE_PAUSED;              
               handle->start_time = handle->current_time;
               handle->stop_flag = true;
               player->buf_read = DSP_WAV_PLAYEDINDEX(handle->index); 
               player->startIndex = player->buf_read;
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_PCM_STOP + player->dspChannel;
               cmd[2] = 0;
               player->rt_command = RT_NONE;
               return;
               
            case RT_STOP:
               handle->state = JWAV_STATE_ABORT;
               handle->stop_flag = true;
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_PCM_STOP + player->dspChannel;
               cmd[2] = 0;
               player->rt_command = RT_NONE;
               JWAV_TRACE( MOD_L1SPHISR, "JWStop %d", handle ); 
               return;                     
               
            case RT_EOF: 
               handle->state = JWAV_STATE_ENDING;
               handle->stop_flag = true;
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_PCM_STOP + player->dspChannel;
               cmd[2] = 0;
               player->FLAGS |= WAV_STOPPING_FLAG;
               player->rt_command = RT_NONE;  
               JWAV_TRACE( MOD_L1SPHISR, "JWEnd %d", handle ); 
               return;  
               
               
            case RT_REPEAT:
               player->FLAGS |= REPEAT_FLAG;
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_PCM_STOP + player->dspChannel;
               cmd[2] = 0;
               player->rt_command = RT_NONE; 
               JWAV_TRACE( MOD_L1SPHISR, "JWRep %d", handle );   
               return;
            default:
               ASSERT(false);
        }
      }      
   } // end of if(state == PLAYING)
        
   cmd[0]= 0;
}
     
/**** Initialization ****/ 
         
void JWav_Init(mediaControl *ctrl) 
{
   Jwav_Player.ctrl = ctrl;  
   Jwav_Player.FLAGS = 0;
}    

/**** Control APIs ****/
/* XWav : Control APIs */

Media_Handle  *JXWav_Open( void (*handler)( Media_Handle *handle, Media_Event event ))
{
   XWAV_Player *player;
   Media_Handle *handle;
   
   //if(Jwav_Player.XWavHandle->state != JXWAV_STATE_UNUSED)
   if(Jwav_Player.FLAGS & XWAV_ON_USE_FLAG)
      return NULL;
      
   if( (handle = DSPSYN_ObtainWavHandle()) == 0 )
      return NULL;   
   
   Jwav_Player.FLAGS |= XWAV_ON_USE_FLAG;    
   
   player = (XWAV_Player *)get_ctrl_buffer(sizeof(XWAV_Player));
   handle->data = (uint32)player;
   
   player->dspChannel = WAV_CHANNEL + handle->index;   
         
   handle->state = JXWAV_STATE_OPENED;
      
   handle->handler = handler;   
   handle->stop_time = 0x7FFFFFFF;   
   handle->volume_level = DEFAULT_XWAV_VOLUME;   
 
   player->data_buf = NULL;
   player->buf_len = 0; 
   player->FLAGS = 0;          
 
   return handle;          
}   

Media_Status  JXWav_Close( Media_Handle *handle )
{   
   ASSERT(handle!=0);
   ASSERT(handle->state == JXWAV_STATE_READY||handle->state == JXWAV_STATE_OPENED);      
   free_ctrl_buffer((XWAV_Player*)handle->data);     
   DSPSYN_ReleaseWavHandle(handle);
   Jwav_Player.FLAGS &= ~XWAV_ON_USE_FLAG;
   return MEDIA_SUCCESS;
}          

Media_Status JXWav_Load(Media_Handle *handle, uint32 *requiredBufSize) 
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
   
   if(handle->state != JXWAV_STATE_OPENED)
      return MEDIA_FAIL;
                        
   // check the ring buffer data for first data input from AUD 
   if(Jwav_Player.ctrl->write == Jwav_Player.ctrl->read)
      return MEDIA_FAIL;  // no data input from AUD 
      
   // perform the wav data check 
   // here perform AUD_Buffer data size must greater than minimum header 
   if(Jwav_Player.ctrl->write < 30) 
      return MEDIA_FAIL;
   else 
   {        
      if(!checkXWavHeader(handle))//wavPtr, &player->sampling_rate))
         return MEDIA_FAIL;
   }                                 
   
   *requiredBufSize = player->requiredBufSize;
   handle->state = JXWAV_STATE_READY;   
   return MEDIA_SUCCESS;             
}

void JXWav_SetBuffer(Media_Handle *handle, int16 *buffer, uint32 buf_len)
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ;    
   player->data_buf = buffer;
   player->buf_len = (uint16)buf_len;
}   



Media_Status  JXWav_Play( Media_Handle *handle )
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
         
   if(handle->state != JXWAV_STATE_READY)
      return MEDIA_FAIL; 
   
   // check the buffer allocation for L1Audio and DSP data communication 
   if((player->data_buf == NULL) || (player->buf_len < player->requiredBufSize)) 
      return MEDIA_FAIL; 
   
   
   handle->start_time = 0; // each time call Play , must play from head 
   handle->current_time = 0; 
   
   player->buf_read = 0;
   player->buf_write = 0;
 
   player->data_count = 0;
   player->last_fill_sample = 0;
 
#if defined(MT6223) || defined(MT6223P)
 	player->FLAGS = 0;
#else 
   player->FLAGS = CHANGE_VOLUME_FLAG;
#endif   
   
   player->startIndex = 0; 
   DSP_WAV_PLAYEDINDEX(handle->index) = player->startIndex;   
   
   // move and transform data from ring buffer to XWav_Buffer     
   wavWriteToXWavBuffer(handle);         
      
   player->rt_command = RT_START_PLAY;
   handle->state = JXWAV_STATE_PLAYING; // to enable sending rt_command in Tick()
   handle->stop_flag = false;
   player->stopTimeCountDown = handle->stop_time - handle->start_time;
   
   player->FLAGS |= NOT_PROCESS_TIME_FLAG;
   DSPSYN_WAV_Start(handle, JXWavEndHandler, JXWavGetCommand, true);     
   
   player->FLAGS |= XWAV_PLAYING_FLAG;
        
   return MEDIA_SUCCESS;
}       


Media_Status  JXWav_Stop( Media_Handle *handle )
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
   uint32 waitTime;
   
   if(handle->state == JXWAV_STATE_READY)
      return MEDIA_SUCCESS;
   else if(handle->state == JXWAV_STATE_PLAYING)
   {
      player->rt_command = RT_STOP;
      for(waitTime = 0; ;waitTime ++)
      {         
         if(!(player->FLAGS & XWAV_PLAYING_FLAG))
            break;
         ASSERT(waitTime < 40);   
         kal_sleep_task(2);
      }                  
   }
   else if(handle->state == JXWAV_STATE_PAUSED)
      handle->state = JXWAV_STATE_READY;  
   else if(player->FLAGS & XWAV_STOPPING_FLAG) // for auto-stop case 
   {
      for(waitTime = 0 ; ; waitTime ++)
      {     
         if(!(player->FLAGS & XWAV_PLAYING_FLAG))
            break;
         ASSERT(waitTime < 40);     
         kal_sleep_task(2);
      }
   }
   else 
   //   ASSERT(false);      
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;         
}


Media_Status JXWav_Pause( Media_Handle *handle )
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
   uint32 waitTime;
 
   if(handle->state == JXWAV_STATE_PLAYING)
   {
      player->rt_command = RT_PAUSE;
      for(waitTime = 0; ;waitTime ++)
      {
         if(!(player->FLAGS & XWAV_PLAYING_FLAG))
            break;
         ASSERT(waitTime < 40);   
         kal_sleep_task(2);
      }                          
   }  
   else if(player->FLAGS & XWAV_STOPPING_FLAG) // for auto-stop case   
   {
      for(waitTime = 0; ;waitTime ++)
      {       
         if(!(player->FLAGS & XWAV_PLAYING_FLAG))
            break;
         ASSERT(waitTime < 40);   
         kal_sleep_task(2);
      }   
      return MEDIA_FAIL; 
   }
   else 
      //ASSERT(false);        
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;               
}


Media_Status JXWav_Resume( Media_Handle *handle )
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ; 
   
   //ASSERT(handle->state == JXWAV_STATE_PAUSED);
   if(handle->state != JXWAV_STATE_PAUSED)
      return MEDIA_FAIL;
      
#if defined(MT6223) || defined(MT6223P)
 	player->FLAGS = 0;
#else 
   player->FLAGS = CHANGE_VOLUME_FLAG;
#endif   
   
   DSP_WAV_PLAYEDINDEX(handle->index) = player->startIndex;      
   // move and transform data from ring buffer to XWav_Buffer         
   wavWriteToXWavBuffer(handle);   
   
   player->rt_command = RT_START_PLAY;
   handle->state = JXWAV_STATE_PLAYING; // to enable sending rt_command in Tick()
   handle->stop_flag = false;
   
   player->stopTimeCountDown = handle->stop_time - handle->start_time; 
   
   player->FLAGS |= NOT_PROCESS_TIME_FLAG;
   
   DSPSYN_WAV_Start(handle, JXWavEndHandler, JXWavGetCommand, false);     
      
   player->FLAGS |= XWAV_PLAYING_FLAG;
        
   return MEDIA_SUCCESS;
      
}   

Media_Status  JXWav_SetLevel( Media_Handle *handle, uint8 level )
{
   XWAV_Player *player = (XWAV_Player *)(handle->data) ;      
   if(level > 100) 
      return MEDIA_FAIL;
   
   handle->volume_level = level; 

#if !(defined(MT6223) || defined(MT6223P))     
   player->FLAGS  |= CHANGE_VOLUME_FLAG;
#endif    
      
   return MEDIA_SUCCESS;            
}                     
   
kal_uint8 JXWav_GetLevel( Media_Handle *handle )
{
   return handle->volume_level;         
}     


kal_int32 JXWav_GetCurrentTime( Media_Handle *handle )                
{
   return handle->current_time;
}        


/* Wav : Control APIs */

Media_Handle  *JWav_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_Wav_Param **param )
{
   WAV_Player *player;
   Media_Handle *handle;
   
   if( (handle = DSPSYN_ObtainWavHandle()) == 0 )
      return NULL;
     
   handle->state = JWAV_STATE_OPENED;   
   player = (WAV_Player *)get_ctrl_buffer(sizeof(WAV_Player));
   handle->data = (uint32)player;
   
   player->dspChannel = WAV_CHANNEL + handle->index;   
   
   handle->param = (void *)&(player->Wav_Param); 
   handle->handler = handler;   
   handle->start_time = 0;
   handle->current_time = 0;
   handle->stop_time = 0x7FFFFFFF;   
   handle->volume_level = DEFAULT_WAV_VOLUME;
    
   *param = &(player->Wav_Param);
   (*param)->wavefile = NULL;
   (*param)->filesize = 0;           
   (*param)->repeats = 1;
   (*param)->format = -1;
   
   player->single_dur = 0;
   player->pan = 64; // default 
   player->FLAGS = 0;
   
   JWAV_TRACE( MOD_L1SP, "JWOpen %d", handle );
     
   return handle;          
}   

Media_Status  JWav_Close( Media_Handle *handle )
{   
   ASSERT(handle!=0);
   ASSERT(handle->state == JWAV_STATE_READY || handle->state == JWAV_STATE_OPENED);    
   free_ctrl_buffer((WAV_Player*)handle->data); 
   JWAV_TRACE( MOD_L1SP, "JWCls %d", handle );    
   DSPSYN_ReleaseWavHandle(handle);
   return MEDIA_SUCCESS;
}         


Media_Status JWav_Load(Media_Handle *handle, uint32 *requiredBufSize) 
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   
   if(handle->state != JWAV_STATE_OPENED)
      return MEDIA_FAIL;      
      
   if((player->Wav_Param.wavefile == NULL) || (player->Wav_Param.filesize == 0)) 
      return MEDIA_FAIL;       
   
   // wave file process              
   // perform the wav data check    
   if(!checkWavHeader(handle))
         return MEDIA_FAIL;
   
   if (player->sampling_rate == 0)
      return MEDIA_FAIL;
   
   player->single_dur = (player->data_len * 1000) / player->sampling_rate;
   if (player->single_dur == 0)
      return MEDIA_FAIL;
   
   *requiredBufSize = player->requiredBufSize;
   
   player->data_buf = NULL;
   player->buf_len = 0;
   
   handle->state = JWAV_STATE_READY;   
   return MEDIA_SUCCESS;             
}

void JWav_SetBuffer(Media_Handle *handle, int16 *buffer, uint32 buf_len)
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   player->data_buf = buffer;
   player->buf_len = (uint16)buf_len;
}   
     
Media_Status  JWav_Play( Media_Handle *handle )
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   uint32 total_dur, start_time, start_offset; 
      
   if(handle->state != JWAV_STATE_READY)
      return MEDIA_FAIL; 
         
   // check assigned buffer size 
   if((player->data_buf == NULL) || (player->buf_len < player->requiredBufSize)) 
      return MEDIA_FAIL;   

#if defined(MT6223) || defined(MT6223P)
 	player->FLAGS = 0;
#else 
   player->FLAGS = CHANGE_VOLUME_FLAG; // keep only CHANGE_VOLUME_FLAG , others reset
#endif       
           
   // time process    
   handle->repeat_count = player->Wav_Param.repeats;
                                             
   if(handle->repeat_count != 0)
   {
      total_dur = player->single_dur * handle->repeat_count;
      if(handle->start_time >= total_dur - RELEASE_WAV_DUR) 
         return MEDIA_SEEK_EOF;  //MEDIA_FAIL; 
      if(handle->current_time >= total_dur - RELEASE_WAV_DUR) 
         return MEDIA_SEEK_EOF;  //MEDIA_FAIL;                  
   }
              
   if(handle->start_time > handle->stop_time - RELEASE_WAV_DUR)
      return MEDIA_FAIL;      
   
   
   if(handle->repeat_count != 0)
      handle->repeat_count -= handle->start_time / player->single_dur;  
   
   start_time = handle->start_time % player->single_dur;    
      
   if(start_time > player->single_dur - RELEASE_WAV_DUR)
   {
      if(handle->repeat_count == 1)
         return MEDIA_SEEK_EOF;  //MEDIA_FAIL;
   
      if(handle->repeat_count != 0)
         handle->repeat_count -= 1;  
      
      handle->current_time += (player->single_dur - start_time);
      start_time = 0;      
   }
   
   player->wav_time = start_time;      
   
   player->startIndex = 0; 
   DSP_WAV_PLAYEDINDEX(handle->index) = player->startIndex; 
   
   // data process 
   start_offset = start_time * player->sampling_rate / 1000;
   
   start_offset /= player->blockDataSize;
   start_offset *= player->blockUnit; // base on 16-bit  
   player->data_ptr = player->data_head + start_offset; 
   player->buf_read = 0;
   player->buf_write = 0;
   player->dvi_count = 0; 
   player->data_count = 0; 
   wavWriteToWavBuf(handle);             
          
   player->rt_command = RT_START_PLAY;
   handle->state = JWAV_STATE_PLAYING; // to enable sending rt_command in Tick()
   
   handle->stop_flag = false;
   player->FLAGS &= ~REPEAT_FLAG; 
   player->prepareRepeatTimer = 0;
   
   player->FLAGS |= NOT_PROCESS_TIME_FLAG;
      
   DSPSYN_WAV_Start(handle, JWavEndHandler, JWavGetCommand, true);     
   
   player->FLAGS |= WAV_PLAYING_FLAG; 
   
   JWAV_TRACE( MOD_L1SP, "JWPlay %d", handle );           
   return MEDIA_SUCCESS;
}               
  
Media_Status  JWav_Stop( Media_Handle *handle )
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   uint32 waitTime;   
   
   JWAV_TRACE( MOD_L1SP, "JWStop %d", handle );   
   
   if(handle->state == JWAV_STATE_READY)
      return MEDIA_SUCCESS;      
   else if(handle->state == JWAV_STATE_PLAYING)
   {
      player->rt_command = RT_STOP;
      for(waitTime = 0; ;waitTime ++)
      {
         if(!(player->FLAGS & WAV_PLAYING_FLAG))
            break;
         ASSERT(waitTime < 40); 
         kal_sleep_task(2);
      }                
   }
   else if(handle->state == JWAV_STATE_PAUSED)
      handle->state = JWAV_STATE_READY;  
   else if(player->FLAGS & WAV_STOPPING_FLAG) // for auto-stop case   
   {
      for(waitTime = 0 ; ; waitTime ++)
      {
         if(!(player->FLAGS & WAV_PLAYING_FLAG))
            break;
         ASSERT(waitTime < 40); 
         kal_sleep_task(2);
      }
   }
   else 
   //   ASSERT(false);      
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;         
}   


Media_Status JWav_Pause( Media_Handle *handle )
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   uint32 waitTime;
         
   if(handle->state == JWAV_STATE_PLAYING)
   {
      player->rt_command = RT_PAUSE;
      for(waitTime = 0; ;waitTime ++)
      {
         if(!(player->FLAGS & WAV_PLAYING_FLAG))
            break;
         ASSERT(waitTime < 40); 
         kal_sleep_task(2);
      }                              
   }
   else if(player->FLAGS & WAV_STOPPING_FLAG)// for auto-stop case      
   {
      for(waitTime = 0; ;waitTime ++)
      {
         if(!(player->FLAGS & WAV_PLAYING_FLAG))
            break;
         ASSERT(waitTime < 40); 
         kal_sleep_task(2);
      }   
      return MEDIA_SEEK_EOF;       // return MEDIA_FAIL;    }
   else 
      //ASSERT(false);        
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;               
}
 


Media_Status JWav_Resume( Media_Handle *handle )
{
   WAV_Player *player = (WAV_Player *)(handle->data) ; 
   uint32 total_dur, start_time, start_offset; 
   
   //ASSERT(handle->state == JWAV_STATE_PAUSED);
   if(handle->state == JWAV_STATE_READY)
   {
      if(handle->repeat_count != 0)
      {
         total_dur = player->single_dur * handle->repeat_count;         
         if(handle->current_time >= total_dur - RELEASE_WAV_DUR) 
         {
            handle->handler(handle, MEDIA_END);
            return MEDIA_SUCCESS;                  
         }   
      }
   }    
            
   if(handle->state != JWAV_STATE_PAUSED)
      return MEDIA_FAIL;
   
   player->FLAGS &= ~(REPEAT_FLAG+REACH_WAV_EOF_FLAG+DATA_WAITING_FLAG); 
 
#if !(defined(MT6223) || defined(MT6223P)) 
   player->FLAGS |= CHANGE_VOLUME_FLAG;               
#endif 
                 
   // time process          
   if(handle->repeat_count != 0)
   {
      total_dur = player->single_dur * handle->repeat_count;
      if(handle->start_time >= total_dur - RELEASE_WAV_DUR) 
         return MEDIA_FAIL;             
   }
              
   if(handle->start_time > handle->stop_time - RELEASE_WAV_DUR)
      return MEDIA_FAIL;      
   
   
   if(handle->repeat_count != 0)
      handle->repeat_count -= handle->start_time / player->single_dur;  
   
   start_time = handle->start_time % player->single_dur;    
      
   if(start_time > player->single_dur - RELEASE_WAV_DUR)
   {
      if(handle->repeat_count == 1)
      {
         handle->handler(handle, MEDIA_END);
         handle->state = JWAV_STATE_READY;
         return MEDIA_SUCCESS;
      }   
   
      if(handle->repeat_count != 0)
         handle->repeat_count -= 1;  
      
      handle->current_time += (player->single_dur - start_time);
      start_time = 0;      
   }
   
   player->wav_time = start_time;             

   player->startIndex = 0; 
   DSP_WAV_PLAYEDINDEX(handle->index) = player->startIndex;
    
   // data process 
   start_offset = start_time * player->sampling_rate / 1000;
   
   start_offset /= player->blockDataSize;
   start_offset *= player->blockUnit; // base on 16-bit  
   player->data_ptr = player->data_head + start_offset;
   player->buf_read = 0;
   player->buf_write = 0;
   player->dvi_count = 0;
   player->data_count = 0; 
   wavWriteToWavBuf(handle);                 
          
   player->rt_command = RT_START_PLAY;
   handle->state = JWAV_STATE_PLAYING; // to enable sending rt_command in Tick()
   
   handle->stop_flag = false;
   player->FLAGS &= ~REPEAT_FLAG; 
   player->prepareRepeatTimer = 0;
   
   player->FLAGS |= NOT_PROCESS_TIME_FLAG;
      
   DSPSYN_WAV_Start(handle, JWavEndHandler, JWavGetCommand, false);     
   
   player->FLAGS |= WAV_PLAYING_FLAG; 
        
   return MEDIA_SUCCESS;      
} 


Media_Status  JWav_SetStartTime( Media_Handle *handle, kal_int32 msStartTime )
{  
   if(handle->state == JWAV_STATE_PLAYING)
      return MEDIA_FAIL;    
      
   handle->start_time = msStartTime;
   handle->current_time = msStartTime;
   return MEDIA_SUCCESS;
}

 
Media_Status  JWav_SetStopTime( Media_Handle *handle, kal_int32 msStopTime )
{        
   handle->stop_time = msStopTime;
   return MEDIA_SUCCESS;    
}    

kal_int32 JWav_GetCurrentTime( Media_Handle *handle )                
{
   return handle->current_time;
}         

kal_int32 JWav_GetDuration( Media_Handle *handle )
{
   
   return (int32)((WAV_Player *)(handle->data))->single_dur;     
}   

Media_Status  JWav_SetLevel( Media_Handle *handle, uint8 level )
{     
   if(level > 100) 
      return MEDIA_FAIL;
       
   handle->volume_level = level;
#if !(defined(MT6223) || defined(MT6223P))   
   ((WAV_Player *)(handle->data))->FLAGS |= CHANGE_VOLUME_FLAG;
#endif    
      
   return MEDIA_SUCCESS;            
}     
     
kal_uint8 JWav_GetLevel( Media_Handle *handle )
{
   return handle->volume_level;         
}     

#else                                                                        
char dummy_jwav_c;    /* define a dummy variable to avoid warning message */
#endif


