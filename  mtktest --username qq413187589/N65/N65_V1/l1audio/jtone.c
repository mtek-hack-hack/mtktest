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
 * jtone.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Tone sequence playback using DSP 64-tone wavetable synthesizer 
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

#if defined( JTONE_SUPPORT )

#define MIN_TONE_DUR 0 // ms

#define DEFAULT_TONE_VOLUME 100 
#define DEFAULT_TONE_VELOCITY 80 
#define DEFAULT_TONE_PROGRAM 80 // square
#define DEFAULT_REST_TIME  72
#define MIN_REST_TIME 36


#define JTONE_STATE_READY 1
#define JTONE_STATE_PLAYING 2 
#define JTONE_STATE_ABORT 3 
#define JTONE_STATE_PAUSED 4 
#define JTONE_STATE_ENDING 5 
#define JTONE_STATE_STOP_TIME_UP 6


#define DSP_TYPE_NOTE_ON (0x00 << 8) 
#define DSP_TYPE_NOTE_OFF (0x01 << 8) 
#define DSP_TYPE_SET_PROG (0x04 << 8)
#define DSP_TYPE_SET_VOL (0x5 << 8) 


#define SILENCE_NOTE_TAG   101  // + 2 bytes : duration 
#define LONG_DURATION_TAG     102    //  + 2 byte : b31 ~ b16   
#define TAG_MAX  102          

typedef enum {
   RT_NONE,
   RT_SET_PROG, 
   RT_NOTE_OFF, 
   RT_NOTE_ON, 
   RT_PAUSE, 
   RT_STOP, 
   RT_STOP_TIME_UP 
} TONE_RT_CMD_TYPE;

#define TONE_PLAYING_FLAG     0x1 
#define TONE_STOPPING_FLAG    0x2
#define CHANGE_VOLUME_FLAG    0x4
#define CHANGE_TIME_FLAG      0x8    
#define FAST_SOUND_OFF_FLAG   0x10


typedef struct {   
   Media_ToneSeq_Param Tone_Param;
   int32 single_dur;
   int32 left_dur;
   int32 rest_time;
   uint32 speed_factor;
   uint8 *cur_pos;
   MidiChannel *channel;     
   int8  play_note;      
   int8 velocity;
   uint8 program;
   int8  pitch_shift;
   uint8 play_style; // 0: continuous , 1: fix rest_dur , 2: ratio 1/16  
   uint8 FLAGS; 
   TONE_RT_CMD_TYPE rt_command;          
} TONE_Player;

  
static bool GetNextTone(Media_Handle *handle)
{
   TONE_Player *player = (TONE_Player *)(handle->data); 
   kal_uint8 data, *cur_pos;   
   kal_int64 new_dur;                        
         
   cur_pos = player->cur_pos;
   
   if(cur_pos == player->Tone_Param.toneSeq + player->Tone_Param.toneSeqLen )
   {
      if(handle->repeat_count == 1)
         return false; // MEDIA_END case 
      else 
      {
         cur_pos = (uint8*) player->Tone_Param.toneSeq; 
         handle->handler(handle,MEDIA_REPEATED);        
      }   
         
      if(handle->repeat_count > 1)
         handle->repeat_count --;
   }         
              
   while(1) 
   {
      data = *cur_pos ++;
      
      if(data < 128)
      {  
         player->play_note = data;
         player->left_dur += *cur_pos ++;
         player->left_dur += (*cur_pos << 8);
         cur_pos ++;        
         data = *cur_pos;
         if(data == (LONG_DURATION_TAG+0x80)) 
         {  
            cur_pos ++;
            player->left_dur += (*cur_pos << 16);
            cur_pos ++;     
            player->left_dur += (*cur_pos << 24);
            cur_pos ++;               
         }                     
         break;   
      }
      else 
      {  
         data &= 0x7F;
                  
         if(data == SILENCE_NOTE_TAG)
         {
            player->play_note = (int8)128;
            player->left_dur += *cur_pos ++;
            player->left_dur += (*cur_pos << 8);
            cur_pos ++; 
            data = *cur_pos;
            if(data == (LONG_DURATION_TAG+0x80)) 
            {  
               cur_pos ++;
               player->left_dur += (*cur_pos << 16);
               cur_pos ++;     
               player->left_dur += (*cur_pos << 24);
               cur_pos ++;             
            }                     
            break;   
         }
         else                                                   
            player->velocity = data;
         
      }
   }    
   
   if(player->play_note != (int8)128)     
      player->play_note += player->pitch_shift;
   
   if(player->play_note < 0 || player->play_note > 127) 
       player->play_note = (int8)128;
       
   if(player->speed_factor != 0x10000)
   {      
      new_dur = player->left_dur * player->speed_factor;
      new_dur = new_dur >> 16;
      if(new_dur >= 0x7FFFFFFF)
         player->left_dur = 0x7FFFFFFF;
      else                
         player->left_dur = (int32)new_dur;       
   }  
   
   if(player->play_style == 2)
   {
      player->rest_time = player->left_dur >> 3;            
      if(player->rest_time < MIN_REST_TIME)
         player->rest_time = MIN_REST_TIME;
   }   
      
   player->cur_pos = cur_pos;   
   
   return true;
}                   


static void JtoneEndHandler( Media_Handle *handle )
{   
   TONE_Player *player = (TONE_Player *)(handle->data);         
   
   if(handle->state != JTONE_STATE_PAUSED)
      handle->state = JTONE_STATE_READY;
    
   player->FLAGS &= ~TONE_PLAYING_FLAG;
      
   if(player->FLAGS & TONE_STOPPING_FLAG)// EOF or STOP_TIME_UP 
   {
      handle->handler(handle, MEDIA_END);      
      player->FLAGS &= ~TONE_STOPPING_FLAG;
   }      
}


static void JtoneGetCommand( Media_Handle *handle, uint16 *dtime, uint16 cmd[4] )
{
   TONE_Player *player = (TONE_Player *)(handle->data);      
   
   if(handle->stop_flag)    
   {
      if(player->FLAGS & FAST_SOUND_OFF_FLAG)
         cmd[0] = 0xFFFE;
      else 
         cmd[0] = 0xFFFF;   
      return;
   }
   
   if(handle->state == JTONE_STATE_PLAYING)
   {     
      if(player->FLAGS & CHANGE_VOLUME_FLAG)
      {
         cmd[0] = 2;
         cmd[1] = DSP_TYPE_SET_VOL + player->channel->dspChannel;
         cmd[2] = handle->volume_level;           
         player->FLAGS &= ~CHANGE_VOLUME_FLAG;
         return;
      }
      
      if(player->rt_command == RT_SET_PROG)    
         *dtime = 0;                  
      
      if(*dtime > 0) 
      {
         handle->current_time += *dtime;
         
         if(handle->stop_time != 0x7FFFFFFF)
         {
            if(handle->current_time >  handle->stop_time)
            {
                player->rt_command = RT_STOP_TIME_UP;
                handle->current_time = handle->stop_time + 10;
            }                                        
         }
         
         if(player->rt_command == RT_NONE) 
         {                  
            player->left_dur -= *dtime;
         
            if(player->play_style == 0)
            {
               if(player->left_dur <= 0) 
                  player->rt_command = RT_NOTE_OFF;
            }
            else  // play_style : 1 , 2  
            {
               if(player->left_dur <= 0)
               {
                  if(GetNextTone(handle))   
                     player->rt_command = RT_NOTE_ON;
                  else 
                     player->rt_command = RT_STOP_TIME_UP;
               }   
               else if(player->left_dur < player->rest_time)
                  player->rt_command = RT_NOTE_OFF;                                      
            }      
         }
                                                                    
         *dtime = 0;      
      }        
      
   
      if(player->rt_command != RT_NONE)
      {
         switch(player->rt_command)
         {
            case RT_SET_PROG:
               cmd[0] = 2;
               cmd[1] = DSP_TYPE_SET_PROG + player->channel->dspChannel;
               cmd[2] = 0x0100 + player->program;  /* Use the second digital gain */
               player->rt_command = RT_NOTE_ON;
               return;
            
            case RT_NOTE_OFF: 
               if(player->play_style == 0)                              
               {
                  if(player->play_note >= 0)
                  {
                     cmd[0] = 2;
                     cmd[1] = DSP_TYPE_NOTE_OFF + player->channel->dspChannel;
                     cmd[2] = player->play_note << 8;
                     if(GetNextTone(handle))                                                      
                        player->rt_command = RT_NOTE_ON;                  
                     else 
                     {                                    
                        player->FLAGS |= TONE_STOPPING_FLAG;
                        player->rt_command = RT_NONE;
                        handle->state = JTONE_STATE_ENDING;
                        //cmd[0] = 0xFFFF; // single channel all notes off (normal release) 
                        cmd[0] = 1;
                        cmd[1] = 0x0C00 + player->channel->dspChannel;
                        DSPSYN_FreeMidiChannel(player->channel);
                        player->channel = (MidiChannel*)0;
                        handle->stop_flag = true;                                 
                     }
                  }
                  else  // silence case 
                  {
                     if(GetNextTone(handle))  
                     {
                        cmd[0] = 2;
                        cmd[1] = DSP_TYPE_NOTE_ON + player->channel->dspChannel; // note-on directly 
                        cmd[2] = (player->play_note << 8) + player->velocity;
                        player->rt_command = RT_NONE;                                             
                     }
                     else 
                     {
                        player->FLAGS |= TONE_STOPPING_FLAG;
                        player->rt_command = RT_NONE;
                        handle->state = JTONE_STATE_ENDING;
                        //cmd[0] = 0xFFFF; // single channel all notes off (normal release)
                        cmd[0] = 1;
                        cmd[1] = 0x0C00 + player->channel->dspChannel;
                        DSPSYN_FreeMidiChannel(player->channel);
                        player->channel = (MidiChannel*)0;
                        handle->stop_flag = true;                                                              
                     }
                  }
               }
               else // play_style : 1, 2  
               {
                  if(player->play_note >= 0)
                  {
                     cmd[0] = 2;
                     cmd[1] = DSP_TYPE_NOTE_OFF + player->channel->dspChannel;
                     cmd[2] = player->play_note << 8;
                     player->rt_command = RT_NONE;                                                               
                  }                                                                           
               }                         
               return;               
                             
            case RT_NOTE_ON: 
               if(player->play_note == (int8)128)  // used to insert silence                
                  cmd[0] = 0;
               else
               {                                                  
                  cmd[0] = 2;
                  cmd[1] = DSP_TYPE_NOTE_ON + player->channel->dspChannel;
                  cmd[2] = (player->play_note << 8) + player->velocity;
               }
               player->rt_command = RT_NONE;
               return; 
            
            case RT_STOP_TIME_UP:                   
               player->FLAGS |= TONE_STOPPING_FLAG;
               player->rt_command = RT_NONE;
               handle->state = JTONE_STATE_STOP_TIME_UP;
               //cmd[0] = 0xFFFF; // single channel all notes off (normal release)  
               cmd[0] = 1;
               cmd[1] = 0x0C00 + player->channel->dspChannel;
               DSPSYN_FreeMidiChannel(player->channel);
               player->channel = (MidiChannel*)0;
               handle->stop_flag = true;                          
               return;
               
            case RT_PAUSE: 
               handle->state = JTONE_STATE_PAUSED;  
               handle->start_time = handle->current_time;
               player->rt_command = RT_NONE;
               //cmd[0] = 0xFFFE; // single channel all sounds off (fast release) 
               cmd[0] = 1;
               cmd[1] = 0x0D00 + player->channel->dspChannel;
               DSPSYN_FreeMidiChannel(player->channel);
               player->channel = (MidiChannel*)0;
               handle->stop_flag = true;                  
               return;
               
            case RT_STOP:
               handle->state = JTONE_STATE_ABORT;                                    
               player->rt_command = RT_NONE;
               //cmd[0] = 0xFFFE; // single channel all sounds off (fast release) 
               cmd[0] = 1;
               cmd[1] = 0x0D00 + player->channel->dspChannel;
               DSPSYN_FreeMidiChannel(player->channel);
               player->channel = (MidiChannel*)0;              
               handle->stop_flag = true;   
               return;            
               
            default: 
               ASSERT(false);              
         }          
      }
   }
   cmd[0] = 0;
}   
   


Media_Handle  *JTone_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_ToneSeq_Param **param )
{
   TONE_Player *player;
   Media_Handle *handle;
   
   if( (handle = DSPSYN_ObtainToneHandle()) == 0 )
      return NULL;
      
   // allocate player memory    
   player = (TONE_Player*) get_ctrl_buffer(sizeof(TONE_Player));   
   
   // handle initialization      
   handle->handler = handler;
   handle->state = JTONE_STATE_READY;   
   handle->param = (void*)&(player->Tone_Param);
   handle->start_time = 0;
   handle->current_time = 0;
   handle->stop_time = 0x7FFFFFFF;
   handle->volume_level = DEFAULT_TONE_VOLUME;
   handle->data = (uint32) player;
      
   // player initialization 
   player->channel = (MidiChannel*) 0;   
   player->velocity = DEFAULT_TONE_VELOCITY;       
   player->pitch_shift = 0;     
   player->speed_factor = 0x10000;    
   player->program = DEFAULT_TONE_PROGRAM;   
   player->play_style = 0;   
   player->rest_time = 0;
   player->FLAGS = 0;
   
   // Tone_Param initialization     
   *param = &(player->Tone_Param);   
   (*param)->toneSeq = NULL;
   (*param)->toneSeqLen = 0; 
   
   return handle;   
}      


Media_Status JTone_Close( Media_Handle *handle)
{
   ASSERT(handle != 0);
   ASSERT(handle->state == JTONE_STATE_READY);
   free_ctrl_buffer((TONE_Player*)handle->data);
   DSPSYN_ReleaseToneHandle(handle);
   return MEDIA_SUCCESS;
}



Media_Status  JTone_Play( Media_Handle *handle )
{
   TONE_Player *player = (TONE_Player *)(handle->data);     
   uint8 data, next_data, *cur_pos;
   uint32 start_time, total_dur, seekStartTime;
   kal_int64 new_dur;
   
   if(handle->state != JTONE_STATE_READY)
      return MEDIA_FAIL;        
   
   if(player->Tone_Param.toneSeq == NULL || player->Tone_Param.toneSeqLen == 0)
      return MEDIA_FAIL;
   
   // time process 
   player->single_dur = JTone_GetDuration(handle);
   if(player->single_dur == 0) 
      return MEDIA_FAIL;
   
   handle->repeat_count = player->Tone_Param.repeats;
   
   
   if(handle->repeat_count != 0)
   {
      total_dur = player->single_dur * handle->repeat_count;
      if(handle->start_time >= total_dur - MIN_TONE_DUR) 
         return MEDIA_SEEK_EOF; // MEDIA_FAIL;             
   }
              
   if(handle->start_time >= handle->stop_time - MIN_TONE_DUR)
      return MEDIA_FAIL;      
   
   
   if(handle->repeat_count != 0)
      handle->repeat_count -= handle->start_time / player->single_dur ;  
   
   start_time = handle->start_time % player->single_dur;                      
                            
   // seek play_ptr
   cur_pos = (uint8*) player->Tone_Param.toneSeq;
   seekStartTime = 0;  
   while(seekStartTime <= start_time || player->left_dur < MIN_TONE_DUR)
   {    
      data = *cur_pos++;
      if(data < 128)
      {
         seekStartTime += *cur_pos++;
         seekStartTime += (*cur_pos << 8);
         cur_pos ++;
         next_data = *cur_pos;
         if(next_data == (LONG_DURATION_TAG + 0x80))
         {
            cur_pos ++;
            seekStartTime += (*cur_pos << 16);
            cur_pos ++;
            seekStartTime += (*cur_pos << 24);
            cur_pos ++;
         }
         
         if(seekStartTime > start_time)
         {
            player->play_note = data;
            player->left_dur = seekStartTime - start_time;   
         }                         
      }
      else 
      {
         data &= 0x7F;
         
         if(data == SILENCE_NOTE_TAG)
         {
            seekStartTime += *cur_pos++;
            seekStartTime += (*cur_pos << 8);
            cur_pos ++;
            next_data = *cur_pos;
            if(next_data == (LONG_DURATION_TAG + 0x80))
            {
               cur_pos ++;
               seekStartTime += (*cur_pos << 16);
               cur_pos ++;
               seekStartTime += (*cur_pos << 24);
               cur_pos ++;
            }
            if(seekStartTime > start_time)
            {
               player->play_note = (int8)128;
               player->left_dur = seekStartTime - start_time;  
            }               
         }
         else 
            player->velocity = data;
      }                                                                       
   }    
   
   if(player->play_note != (int8)128)     
      player->play_note += player->pitch_shift;
   
   if(player->play_note < 0 || player->play_note > 127) 
       player->play_note = (int8)128;   
       
   if(player->speed_factor != 0x10000)
   {      
      new_dur = player->left_dur * player->speed_factor;
      new_dur = new_dur >> 16;
      if(new_dur >= 0x7FFFFFFF)
         player->left_dur = 0x7FFFFFFF;
      else                
         player->left_dur = (int32)new_dur;       
   }
   
   if(player->play_style == 2)
   {
      player->rest_time = player->left_dur >> 3;       
      if(player->rest_time < MIN_REST_TIME)
         player->rest_time = MIN_REST_TIME;
   }
   
   player->cur_pos = cur_pos;
   
   player->rt_command = RT_SET_PROG;
   
   player->FLAGS = CHANGE_VOLUME_FLAG;
      
   handle->state = JTONE_STATE_PLAYING;
   handle->stop_flag = false;
      
   ASSERT(player->channel == (MidiChannel*)0);
   player->channel = DSPSYN_GetMidiChannel(false);
   DSPSYN_TONE_Start(handle, JtoneEndHandler , JtoneGetCommand, true); 
   
   player->FLAGS |= TONE_PLAYING_FLAG;
   
   return MEDIA_SUCCESS;   
}         


Media_Status  JTone_Stop( Media_Handle *handle )
{
   TONE_Player *player = (TONE_Player *)(handle->data);    
   uint32 waitTime;
        
   player->FLAGS |= FAST_SOUND_OFF_FLAG;
   
   if(handle->state == JTONE_STATE_PLAYING)
   {
      player->rt_command = RT_STOP;
      
      for(waitTime = 0 ; ; waitTime ++)
      {       
         if(!(player->FLAGS & TONE_PLAYING_FLAG))
            break;
         ASSERT(waitTime < 40);    
         kal_sleep_task(2);
      }                    
   }
   else if(handle->state == JTONE_STATE_PAUSED)
      handle->state = JTONE_STATE_READY;              
   else if(player->FLAGS & TONE_STOPPING_FLAG)// for Case auto stop 
   {
   #if APM_SUPPORT
      if(DSPSYN_APM_Ending())
      {
         player->FLAGS &= ~(TONE_STOPPING_FLAG + FAST_SOUND_OFF_FLAG);
         APM_EXECUTE_END_HANDLER();
      }   
      else 
   #endif    
      {     
         for(waitTime = 0 ; ; waitTime ++)    
         {          
            if(!(player->FLAGS & TONE_PLAYING_FLAG))
                  break;
            ASSERT(waitTime < 40);       
            kal_sleep_task(2);         
         }
      }          
   }
   else 
   //   ASSERT(false);   
      return MEDIA_FAIL;
         
   return MEDIA_SUCCESS;
}


Media_Status  JTone_Pause( Media_Handle *handle ) 
{
   TONE_Player *player = (TONE_Player *)(handle->data);   
   uint32 waitTime;     
   
   player->FLAGS |= FAST_SOUND_OFF_FLAG;
   
   if(handle->state == JTONE_STATE_PLAYING)
   {
      player->rt_command = RT_PAUSE;      
      for(waitTime = 0 ; ; waitTime ++)
      {         
         if(!(player->FLAGS & TONE_PLAYING_FLAG))
            break;
         ASSERT(waitTime < 40); 
         kal_sleep_task(2);
      }               
   }  
   else if(player->FLAGS & TONE_STOPPING_FLAG)
   {
   #if APM_SUPPORT
      if(DSPSYN_APM_Ending())
      {
         player->FLAGS &= ~(TONE_STOPPING_FLAG + FAST_SOUND_OFF_FLAG);
         APM_EXECUTE_END_HANDLER();
      }   
      else 
   #endif    
      {        
         for(waitTime = 0 ; ; waitTime ++)
         {        
            if(!(player->FLAGS & TONE_PLAYING_FLAG))
               break;
            ASSERT(waitTime < 40);    
            kal_sleep_task(2);
         }
      }   
      return MEDIA_FAIL;
   }
   else 
      //ASSERT(false);
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;     
}

Media_Status  JTone_Resume( Media_Handle *handle )    
{
   TONE_Player *player = (TONE_Player *)(handle->data);    
   uint8 data, next_data, *cur_pos;
   uint32 start_time, total_dur, seekStartTime;
   kal_int64 new_dur;
               
   //ASSERT(handle->state == JTONE_STATE_PAUSED)     
   if(handle->state != JTONE_STATE_PAUSED) 
      return MEDIA_FAIL;
   
   // time process 
   handle->repeat_count = player->Tone_Param.repeats;   
   
   if(handle->repeat_count != 0)
   {
      total_dur = player->single_dur * handle->repeat_count;
      if(handle->start_time >= total_dur - MIN_TONE_DUR) 
         return MEDIA_FAIL;             
   }
              
   if(handle->start_time >= handle->stop_time - MIN_TONE_DUR)
      return MEDIA_FAIL;      
   
   
   if(handle->repeat_count != 0)
      handle->repeat_count -= handle->start_time / player->single_dur ;  
   
   start_time = handle->start_time % player->single_dur;                      
                               
   // seek play_ptr
   cur_pos = (uint8*) player->Tone_Param.toneSeq;
   seekStartTime = 0;  
   while(seekStartTime <= start_time || player->left_dur < MIN_TONE_DUR)
   {    
      data = *cur_pos++;
      if(data < 128)
      {
         seekStartTime += *cur_pos++;
         seekStartTime += (*cur_pos << 8);
         cur_pos ++;
         next_data = *cur_pos;
         if(next_data == (LONG_DURATION_TAG + 0x80))
         {
            cur_pos ++;
            seekStartTime += (*cur_pos << 16);
            cur_pos ++;
            seekStartTime += (*cur_pos << 24);
            cur_pos ++;
         }
         
         if(seekStartTime > start_time)
         {
            player->play_note = data;
            player->left_dur = seekStartTime - start_time;   
         }                         
      }
      else 
      {
         data &= 0x7F;
         
         if(data == SILENCE_NOTE_TAG)
         {
            seekStartTime += *cur_pos++;
            seekStartTime += (*cur_pos << 8);
            cur_pos ++;
            next_data = *cur_pos;
            if(next_data == (LONG_DURATION_TAG + 0x80))
            {
               cur_pos ++;
               seekStartTime += (*cur_pos << 16);
               cur_pos ++;
               seekStartTime += (*cur_pos << 24);
               cur_pos ++;
            }
            if(seekStartTime > start_time)
            {
               player->play_note = (int8)128;
               player->left_dur = seekStartTime - start_time;  
            }               
         }
         else 
            player->velocity = data;
      }                                                                       
   }      
   
   if(player->play_note != 128)     
      player->play_note += player->pitch_shift;
   
   if(player->play_note < 0 || player->play_note > 127) 
       player->play_note = (int8)128;           
       
   if(player->speed_factor != 0x10000)
   {      
      new_dur = player->left_dur * player->speed_factor;
      new_dur = new_dur >> 16;
      if(new_dur >= 0x7FFFFFFF)
         player->left_dur = 0x7FFFFFFF;
      else                
         player->left_dur = (int32)new_dur;       
   }        
   
   if(player->play_style == 2)
   {
      player->rest_time = player->left_dur >> 3;      
      if(player->rest_time < MIN_REST_TIME)
         player->rest_time = MIN_REST_TIME;
   }      
               
   player->rt_command = RT_SET_PROG; 
   
   player->FLAGS = CHANGE_VOLUME_FLAG;
        
   handle->state = JTONE_STATE_PLAYING; 
   handle->stop_flag = false;
   
   ASSERT(player->channel == (MidiChannel*)0);
   player->channel = DSPSYN_GetMidiChannel(false);
   DSPSYN_TONE_Start(handle, JtoneEndHandler , JtoneGetCommand, true); 
            
   player->FLAGS |= TONE_PLAYING_FLAG;
   
   return MEDIA_SUCCESS;
}  


Media_Status  JTone_SetStartTime( Media_Handle *handle, kal_int32 msStartTime )
{
   if(handle->state == JTONE_STATE_PAUSED)
      return MEDIA_FAIL;       
   handle->start_time = msStartTime;
   handle->current_time = msStartTime;
   return MEDIA_SUCCESS;
}

 
Media_Status  JTone_SetStopTime( Media_Handle *handle, kal_int32 msStopTime )
{
   handle->stop_time = msStopTime;
   return MEDIA_SUCCESS;    
}

kal_int32 JTone_GetCurrentTime( Media_Handle *handle )
{     
   return handle->current_time;
}

kal_int32  JTone_GetDuration( Media_Handle *handle )
{
   TONE_Player *player = (TONE_Player *)(handle->data);  
   uint8 volume_type_count, data, *cur_pos;
   uint32 duration;             
   
   duration = 0; 
   cur_pos = (uint8*) player->Tone_Param.toneSeq;
   volume_type_count = 0;
   
   while(cur_pos < player->Tone_Param.toneSeq + player->Tone_Param.toneSeqLen)
   {
      data = *cur_pos++;
      if(data <128) // note;
      {
         duration += *cur_pos++;
         duration += (*cur_pos) << 8;
         cur_pos++;
         data = *cur_pos;
         if(data == (LONG_DURATION_TAG + 0x80))
         {
            cur_pos ++;
            duration += (*cur_pos << 16);
            cur_pos ++;
            duration += (*cur_pos << 24);
            cur_pos ++;
         }               
         volume_type_count = 0;
      }
      else 
      {
         data &= 0x7F;
         if(data > TAG_MAX)
            return 0;  // wrong tone sequence data 
         
         if(data == SILENCE_NOTE_TAG)
         {
            duration += *cur_pos++;
            duration += (*cur_pos) << 8;
            cur_pos++;
            data = *cur_pos;
            if(data == (LONG_DURATION_TAG + 0x80))
            {
               cur_pos ++;
               duration += (*cur_pos << 16);
               cur_pos ++;
               duration += (*cur_pos << 24);
               cur_pos ++;
            }
            
            volume_type_count = 0;
         }       
         else if(data == LONG_DURATION_TAG)
            return 0; // wrong tone sequence data 
         else
         {
            volume_type_count ++;
            if(volume_type_count > 1) // wrong tone sequence data 
               return 0;
         }
      }
   }
   
   if(cur_pos > player->Tone_Param.toneSeq + player->Tone_Param.toneSeqLen)
      return 0; // wrong tone sequence data 
         
   return duration;
}   

Media_Status JTone_SetLevel( Media_Handle *handle, kal_uint8 level )
{   
   if(level > 100) 
      return MEDIA_FAIL;
   
   handle->volume_level = level;
   
   ((TONE_Player *)(handle->data))->FLAGS |= CHANGE_VOLUME_FLAG;
      
   
   return MEDIA_SUCCESS;
}


kal_uint8 JTone_GetLevel( Media_Handle *handle )           
{
   return handle->volume_level;
}        
  
Media_Status JTone_SetPitchShift(Media_Handle *handle, kal_int8 pitch_shift)
{
   if(pitch_shift > 100 || pitch_shift < -100) 
      return MEDIA_FAIL;
   
   ((TONE_Player *)(handle->data))->pitch_shift = pitch_shift;
   
   return MEDIA_SUCCESS;
   
}   
        

kal_int8 JTone_GetPitchShift(Media_Handle *handle)
{
   return ((TONE_Player *)(handle->data))->pitch_shift;  
}   


Media_Status JTone_SetSpeed(Media_Handle *handle, kal_uint32 new_rate)
{   
   ((TONE_Player *)(handle->data))->speed_factor = new_rate;     
   return MEDIA_SUCCESS;
}

Media_Status JTone_SetProgram(Media_Handle *handle, kal_uint8 program)
{
   ((TONE_Player *)(handle->data))->program = program;
   return MEDIA_SUCCESS;   
}

Media_Status JTone_SetPlayStyle(Media_Handle *handle, kal_uint8 play_style)
{
   TONE_Player *player = (TONE_Player *)(handle->data);  
   
   player->play_style = play_style;
   
   if(play_style == 0)
      player->rest_time = 0;
   else if(play_style == 1)
      player->rest_time = DEFAULT_REST_TIME;
   else if(play_style > 2)
      return MEDIA_FAIL;      
      
   return MEDIA_SUCCESS;            
}
#endif // end of JTONE_SUPPORT
#else                                                                        
char dummy_jtone_c;    /* define a dummy variable to avoid warning message */  
#endif            

