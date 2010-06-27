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
 * tone.c
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   New Tone Interface for MT6205B and later
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"
#include "afe.h"

uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );

#if IS_EV_BOARD
#define KT_INIT_AMP     0x1000
#else
#define KT_INIT_AMP     0x3FFF
#endif

#if IS_EV_BOARD
#define TONE_INIT_AMP   0x1000
#else
#define TONE_INIT_AMP   0x1FFF
#endif
static struct
{
   const L1SP_Tones  *tonelist;
   const L1SP_QTMF   *curr_qtmf;
   void              (*handler)(void);
   uint16            aud_id;
   uint16            amp;
   uint8             gpt;
   bool              bQTMF;
} tone;

static struct
{
   uint16            aud_id;
   uint8             gpt;
   int8              lock;
   uint8             volume1;
   int8             digital_gain_index;
} keytone;

#define DSP_QTMF_FREQ(f1,f2,f3,f4)  {  DSP_TONE_F1A  = (f1);                \
                                       DSP_TONE_F1B  = (f2);                \
                                       DSP_TONE_F2A  = (tone.bQTMF)?(f3):0; \
                                       DSP_TONE_F2B  = (tone.bQTMF)?(f4):0; }
#define DSP_KT_FREQ(f1,f2)    {  DSP_TONE_F2A  = (f1);               \
                                 DSP_TONE_F2B  = (f2);               }

/* ------------------------------------------------------------------------------ */
/*  Functions for Playing Comfort Tones                                           */
/* ------------------------------------------------------------------------------ */
static void tonePlayOff( void *data );

static void toneStop( void *data )
{
   uint16 tone_ctrl;
   
   if( !L1Audio_CheckFlag( tone.aud_id ) )
      return;
   tone_ctrl = (DSP_TONE_CTRL2 << 8) + DSP_TONE_CTRL1;
   switch( tone_ctrl ) {
   case 0:
      tone.bQTMF = false;
      AM_ToneOff();
      DP_KT_ATT = 0;
      AFE_TurnOffSpeaker( L1SP_TONE );
      L1Audio_ClearFlag( tone.aud_id );
      L1Audio_SetEvent( tone.aud_id, 0 );
#if !defined(MT6205B)
      // unapply hardware mute during tone playback 
      *AFE_AMCU_CON1 &= ~0x3C;  
#endif 
#if defined(__BT_SUPPORT__)
      if( L1SP_GetSpeechMode() == SPH_MODE_FM_VIA_BT_CORDLESS )
         *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x1000; // set back to cordless mode
#endif 
      break;
   case 0x202:
      DSP_TONE_CTRL1 = 4;
      DSP_TONE_CTRL2 = 4;
   default:
      GPTI_StartItem( tone.gpt, 1, toneStop, data );
      break;
   }
#if defined(NOKE_DEBUG)
   //noke_dbg_printf("\r\n Huyanwei debug toneStop() \r\n");
#endif
}

static void tonePlayOn( void *data )
{
   uint16 dura;

   if( tone.bQTMF )
      tone.curr_qtmf = (L1SP_QTMF *)tone.tonelist + (uint32)data;
   else
      tone.curr_qtmf = (L1SP_QTMF *)(tone.tonelist + (uint32)data);
   
#if !defined(MT6205B)
   // apply hardware mute during tone playback 
   *AFE_AMCU_CON1 |= 0x3C;   
#endif 
   
   AFE_TurnOnSpeaker( L1SP_TONE );

#if defined(MT6205B)
   if( *DP_AUDIO_PAR & 0x0008 ) {   /* MT6205B 16K PCM is playing */
      DSP_QTMF_FREQ( tone.curr_qtmf->freq1 / 2, tone.curr_qtmf->freq2 / 2,
                     tone.curr_qtmf->freq3 / 2, tone.curr_qtmf->freq4 / 2 );
   }
   else
#endif
   {
      DSP_QTMF_FREQ( tone.curr_qtmf->freq1, tone.curr_qtmf->freq2,
                     tone.curr_qtmf->freq3, tone.curr_qtmf->freq4 );
   }

   DSP_TONE_CTRL1 = 1;
   DSP_TONE_CTRL2 = 1;

   if( ( dura = tone.curr_qtmf->on_duration / 10 ) > 0 ) {
      GPTI_StartItem( tone.gpt, dura, tonePlayOff, 0 );
   }
#if defined(NOKE_DEBUG)
   noke_dbg_printf("\r\n Huyanwei debug tonePlayOn() \r\n");
#endif
}

static void toneMute( void *data )
{
   int32 dura = (int32)data;
   uint16 tone_ctrl;
   
   tone_ctrl = (DSP_TONE_CTRL2 << 8) + DSP_TONE_CTRL1;
   switch( tone_ctrl ) {
   case 0:
      AFE_TurnOffSpeaker( L1SP_TONE );
      GPTI_StartItem( tone.gpt, dura+1, tonePlayOn, (void *)tone.curr_qtmf->next_tone );
      break;   
   case 0x202:
      DSP_TONE_CTRL1 = 4;
      DSP_TONE_CTRL2 = 4;
   default:
      GPTI_StartItem( tone.gpt, 1, toneMute, (void*)((dura>0)?dura-1:0) );
      break;
   }
#if defined(NOKE_DEBUG)
      noke_dbg_printf("\r\n Huyanwei debug toneMute() \r\n");
#endif
}

static void tonePlayOff( void *data )
{
   uint16 dura = tone.curr_qtmf->off_duration / 10;
#if defined(NOKE_DEBUG)
   noke_dbg_printf("\r\n Huyanwei debug tonePlayOff() \r\n");
#endif   
   if( dura == 0 )
      toneStop( 0 );
   else
      toneMute( (void*)dura );
}

static void toneHandler( void *data )     /* This function works in L1Audio Task */
{
   (void)data;
   if( tone.handler != 0 )
      tone.handler();
}

void toneInit( uint16 aud_id )
{
   tone.aud_id    = aud_id;
   tone.handler   = 0;
   L1Audio_SetEventHandler( aud_id, toneHandler );
   GPTI_GetHandle( &tone.gpt );
   DSP_TONE_CTRL1 = 0;

   tone.amp = TONE_INIT_AMP;
   tone.bQTMF = false;

   DP_KT_ATT      = 0;
   AFE_TurnOnFIR( L1SP_TONE );
}

/* ------------------------------------------------------------------------------ */
/*  Tone Interface                                                                */
/* ------------------------------------------------------------------------------ */
void TONE_SetOutputDevice( uint8 device )
{
   AFE_SetOutputDevice( L1SP_TONE, device );
}

void TONE_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#if defined( MT6205B ) 
   // in MT6205B , digital_gain_index is the role of  volume2 , which is used to set volume of buf1 
   digital_gain_index  =  volume1;     
#endif 
   
   AFE_SetOutputVolume( L1SP_TONE, volume1, digital_gain_index );
}

/*****************************************************************************
* FUNCTION
*  TONE_PlayQTMF
* DESCRIPTION
*   This function is used to play comfort tones.
*   Totally 4 frequencies can be generated
*
* PARAMETERS
*  tonelist - QTMF list
* RETURNS
*  None.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void TONE_PlayQTMF( const L1SP_QTMF *tonelist )
{
   if( L1Audio_CheckFlag( tone.aud_id ) )
      return;
   tone.bQTMF = true;
   TONE_Play((const L1SP_Tones *)tonelist);
}

/*****************************************************************************
* FUNCTION
*  TONE_Play
* DESCRIPTION
*   This function is used to play comfort tones.
*
* PARAMETERS
*  tonelist - Tone list
* RETURNS
*  None.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void TONE_Play( const L1SP_Tones *tonelist )
{
   if( L1Audio_CheckFlag( tone.aud_id ) )
      return;
   if( L1Audio_CheckFlag( keytone.aud_id ) ) {
      KT_Stop();
      while( L1Audio_CheckFlag( keytone.aud_id ) )
         kal_sleep_task( 1 );
   }

   if( AM_IsSpeechOn() )
      DP_KT_ATT = 0x4000;
#if defined(__BT_SUPPORT__)
   if( L1SP_IsBluetoothOn() ){
      if( L1SP_GetSpeechMode() == SPH_MODE_FM_VIA_BT_CORDLESS )
         *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x2000; // set to earphone mode
      DSP_TONE_AMP1 = (TONE_INIT_AMP >> 2);               /* degrade bluetooth tone volume by 12dB */
      DSP_TONE_AMP2 = (TONE_INIT_AMP >> 2);               /* degrade bluetooth tone volume by 12dB */
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
      *DP_VSBT_CTRL |= 0x1;                               // output to both BT and voice DAC
#endif
   }else
#endif
   {
      DSP_TONE_AMP1 = tone.amp;
      DSP_TONE_AMP2 = tone.amp;
   }
   L1Audio_SetFlag( tone.aud_id );
   tone.tonelist = tonelist;
   tonePlayOn( 0 );
   AM_ToneOn();
}

/*****************************************************************************
* FUNCTION
*  TONE_Stop
* DESCRIPTION
*   This function is used to stop playing comfort tones.
*
* PARAMETERS
*  None
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void TONE_Stop( void )
{
   GPTI_StopItem( tone.gpt );
   toneStop( 0 );
}

void TONE_StopAndWait( void )
{
   int I;

   if( !L1Audio_CheckFlag( tone.aud_id ) )
      return;
      
   TONE_Stop();
   
   for( I = 0; ; I++ ) {
      if (DSP_TONE_CTRL1 == 0 && DSP_TONE_CTRL2 == 0)
         break;
      
      ASSERT(I < 20);
      kal_sleep_task(2);
   }
}

void TONE_SetAmplitude( int16 amp )
{
   tone.amp = (uint16)amp;
}

void TONE_SetFIR( bool enable )
{
   if( enable )
      AFE_TurnOnFIR( L1SP_TONE );
   else
      AFE_TurnOffFIR( L1SP_TONE );
}

void TONE_SetHandler( void (*handler)(void) )
{
   tone.handler = handler;
}

/* ------------------------------------------------------------------------------ */
/*  Keytone Interface                                                             */
/* ------------------------------------------------------------------------------ */
static void ktStop( void *data )
{
   if( !L1Audio_CheckFlag( keytone.aud_id ) )
      return;
   switch( DSP_TONE_CTRL2 ) {
   case 0:
      AM_KeyToneOff();
      L1Audio_ClearFlag( keytone.aud_id );
      break;
   case 2:
      DSP_TONE_CTRL2 = 4;
   default:
      GPTI_StartItem( keytone.gpt, 1, ktStop, data );
      break;
   }
}

void ktInit( uint16 aud_id )
{
   keytone.aud_id = aud_id;
   keytone.lock   = 0;
   keytone.volume1 = 160;
   keytone.digital_gain_index = 0;
#if defined( MT6205B ) 
   // in MT6205B , digital_gain_index is the role of  volume2 , which is used to set volume of buf1 
   keytone.digital_gain_index  =  keytone.volume1;     
#endif    

   GPTI_GetHandle( &keytone.gpt );
   DSP_TONE_CTRL2 = 0;
   DSP_TONE_AMP2  = KT_INIT_AMP;
   AFE_TurnOnFIR( L1SP_KEYTONE );
}

void ktLock( void )
{
   uint32 savedMask;

   ASSERT( keytone.lock < 8 );
   savedMask = SaveAndSetIRQMask();
   keytone.lock++;
   RestoreIRQMask(savedMask);
}

void ktUnlock( void )
{
   uint32 savedMask;

   ASSERT( keytone.lock > 0 );
   savedMask = SaveAndSetIRQMask();
   keytone.lock--;
   RestoreIRQMask(savedMask);
}

void KT_SetOutputDevice( uint8 device )
{
   if( L1Audio_CheckFlag( keytone.aud_id ) ) { 
      KT_Stop();
      while( L1Audio_CheckFlag( keytone.aud_id ) )
         kal_sleep_task( 1 );
   }
   AFE_SetOutputDevice( L1SP_KEYTONE, device );
}

void KT_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#if defined( MT6205B ) 
   // in MT6205B , digital_gain_index is the role of  volume2 , which is used to set volume of buf1 
   digital_gain_index  =  volume1;     
#endif 
   
   keytone.volume1 = volume1;
   keytone.digital_gain_index = digital_gain_index;
}

/*****************************************************************************
* FUNCTION
*  KT_Play
* DESCRIPTION
*   This function is used to play keytone.
*
* PARAMETERS
*  freq1 - The first frequency
*  freq2 - The second frequency
*  duration - Duration of the tone
* RETURNS
*  None.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef BT_Loopback_Test
kal_bool	BT_PROCESS_END;

extern uint32 BT_Loopback_Start(void(*callback)( void ) , kal_char *play_filename , kal_char *record_filename);

void BT_Loopback_Callback(void)
{
	BT_PROCESS_END = true;
}

#define SPH_MODE_BT_CORDLESS 4
uint16 m_para[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

void Key1Event( void )
{
   L1SP_Speech_Off();
   L1SP_SetOutputDevice(L1SP_SPEAKER1);
   L1SP_SetSpeechMode(SPH_MODE_BT_CORDLESS, m_para);
   L1SP_Speech_On(0);

   return;   
}

void Key2Event( void )
{   
   {
      uint16 m_para_BT_Earphone[8] = {64,   223,     0,     30,    7,  20510,   400,     0};
      
      L1SP_Speech_Off();
      L1SP_SetOutputDevice(L1SP_SPEAKER1);
      L1SP_SetSpeechMode(SPH_MODE_BT_EARPHONE, m_para_BT_Earphone);
      L1SP_Speech_On(0);
   }
   return;   
}

void Key3Event( void )
{

   L1SP_Speech_Off();
   L1SP_SetOutputDevice(L1SP_SPEAKER1);
   L1SP_SetSpeechMode(SPH_MODE_BT_CORDLESS, m_para);
   return;   
}

void Key4Event( void )
{   
      uint16 m_para_BT_Earphone[8] = {64,   223,     0,     30,    7,  20510,   400,     0};
      
      L1SP_Speech_Off();
      L1SP_SetOutputDevice(L1SP_SPEAKER1);
      L1SP_SetSpeechMode(SPH_MODE_BT_EARPHONE, m_para_BT_Earphone); 
   return;   
}

void Key5Event( void )
{    

   return;   
}

void Key6Event( void )
{  
   BT_Loopback_Start(BT_Loopback_Callback,"1.wav","BTout1.pcm");    
   return;   
}

void Key7Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"2.wav","BTout2.pcm");    
   return;   
}

void Key8Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"3.wav","BTout3.pcm");     
   return;   
}

void Key9Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"4.wav","BTout4.pcm");  
   return;   
}

static uint8 KeyFlags = 0;
static uint8 KeyCommand = 0;
#endif


void KT_Play( uint16 freq1, uint16 freq2, uint16 duration )
{
#ifdef BT_Loopback_Test
   uint8 pressed_key;   
   
   pressed_key = 0;
   
   switch(freq1) {
      case 697:
         pressed_key = 1;
         break;
      case 770:
         pressed_key = 4;
         break;
      case 852:
         pressed_key = 7;
         break;
      case 941:
         pressed_key = 10;  //*
         break;
   }
   switch(freq2) {
      case 1209:
         pressed_key += 0;
         break;
      case 1336:
         pressed_key += 1;
         break;
      case 1477:
         pressed_key += 2;
         break;
   }

//===================================================================
	
   if(pressed_key == 10)  // * 
      KeyFlags = 0x1;
   else if(pressed_key == 12)  // #   
   {
      if(KeyFlags == 0x3)
      {
         switch(KeyCommand)
         {
            case 1:  
               Key1Event();
               break;
            case 2:
               Key2Event();               
               break;
            case 3:               
               Key3Event();   
               break;
            case 4:             
               Key4Event();                             
               break;
            case 5:  
               Key5Event();                      
               break;            
            case 6: 
               Key6Event();             
               break;   
            case 7: 
               Key7Event();                     
               break;            
            case 8:
               Key8Event();                            
               break; 
            case 9:                            
               Key9Event();
               break;
            default: 
               ASSERT(false);                           
         }            
      }      
      KeyFlags = 0;                           
   }
   else 
   {
      if(KeyFlags == 0x1)
      {
         switch(pressed_key)
         {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: 
            case 6: 
            case 7:
            case 8:
            case 9: 
               KeyCommand = pressed_key;      
               KeyFlags = 0x3;
               break;
            default:
               KeyCommand = 0;
               KeyFlags = 0;
         }
      }
      else 
         KeyFlags = 0;
   }                                                   

      return;                     
#endif

   if( keytone.lock > 0 || keytone.volume1 == 0 )
      return;
   if( mediaKeytoneForbidden() || AM_IsDAIMode() )
      return;
   if( L1Audio_CheckFlag( keytone.aud_id ) || L1Audio_CheckFlag( tone.aud_id ) )
      return;

   L1Audio_SetFlag( keytone.aud_id );

   /* keytone in speech mode, need special care */
#if defined(__BT_SUPPORT__)
   if( L1SP_IsBluetoothOn() ) {
      DSP_TONE_AMP2 = KT_INIT_AMP >> 2; /* degrade bluetooth keytone volume by 12dB */
      AFE_SetOutputVolume( L1SP_KEYTONE, keytone.volume1, keytone.digital_gain_index );
   }
   else
#endif
   if( ( AM_IsSpeechOn() || AM_IsVoIPOn() ) && AFE_GetOutputDevice(L1SP_KEYTONE)==AFE_GetOutputDevice(L1SP_SPEECH) ) {
      uint8 speech_vol1;
      int8 speech_digital_gain;
      int32 vol, dgain;
      AFE_GetOutputVolume( L1SP_SPEECH, &speech_vol1, &speech_digital_gain );
      AFE_SetOutputVolume( L1SP_KEYTONE, speech_vol1, speech_digital_gain );
      vol = (speech_vol1>>4) - (keytone.volume1>>4);
      dgain= KT_INIT_AMP;
      if( AFE_GetOutputDevice(L1SP_KEYTONE) & L1SP_BUFFER_ST ) {
         while( vol > 0 ) {
            dgain = (dgain * 725) >> 10;    vol--;   /* 3dB down */
         }
         while( vol < 0 ) {
            dgain = (dgain * 1446) >> 10;   vol++;   /* 3dB up */
         }
      }
      else {
         while( vol > 0 ) {
            dgain = (dgain * 813) >> 10;    vol--;   /* 2dB down */
         }
         while( vol < 0 ) {
            dgain = (dgain * 1289) >> 10;   vol++;   /* 2dB up */
         }
      }
      if( dgain >= 0x8000 )
         dgain = 0x7FFF;
      DSP_TONE_AMP2 = dgain;
   }
   else {
      DSP_TONE_AMP2 = KT_INIT_AMP;
      AFE_SetOutputVolume( L1SP_KEYTONE, keytone.volume1, keytone.digital_gain_index );
   }

#if defined(MT6205B)
   if( *DP_AUDIO_PAR & 0x0008 ) {   /* MT6205B 16K PCM is playing */
      DSP_KT_FREQ( freq1/2, freq2/2 );
   }
   else
#endif
   {
      DSP_KT_FREQ( freq1, freq2 );
   }
   DSP_TONE_CTRL2 = 1;
   if( (duration = duration / 10) > 0 ) {
      GPTI_StartItem( keytone.gpt, duration, ktStop, 0 );
   }
   AM_KeyToneOn();
}

/*****************************************************************************
* FUNCTION
*  KT_Stop
* DESCRIPTION
*   This function is used to stop key tone playing.
*****************************************************************************/
void KT_Stop( void )
{
   GPTI_StopItem( keytone.gpt );
   ktStop( 0 );
}

void KT_StopAndWait(void)
{
   int I;
   
   if( !L1Audio_CheckFlag( keytone.aud_id ) )
      return;
      
   KT_Stop();
   
   for( I = 0; ; I++ ) {
      if (DSP_TONE_CTRL2 == 0)
         break;
      
      ASSERT(I < 20);
      kal_sleep_task(2);
   }
}

void KT_SetAmplitude( int16 amp )
{
   DSP_TONE_AMP2   = amp;
}

void KT_SetFIR( bool enable )
{
   if( enable )
      AFE_TurnOnFIR( L1SP_KEYTONE );
   else
      AFE_TurnOffFIR( L1SP_KEYTONE);
}


