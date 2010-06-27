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
 * l1sp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   L1SP Interface 
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"
#include "afe.h"
#include "custom_equipment.h" /* custom_cfg_audio_ec_range() */
#include "device.h" /* MAX_VOL_LEVEL,  in ps\l4\include */
#include "l1sp_trc.h"

/* ------------------------------------------------------------------------------ */
/*  Speech Interface                                                              */
/* ------------------------------------------------------------------------------ */
static struct {
   uint16   aud_id;

   uint8    sph_mode;
   uint8    sph_level;
   uint16   sph_c_para[NUM_COMMON_PARAS];
   uint16   sph_m_para[NUM_MODE_PARAS];
   uint8    min_ec_level;
   uint8    max_ec_level;
   uint8    mic_volume;
   uint8    spe_state;
   bool     spe_flag;   
   uint8    state;          
#if defined(__BT_SUPPORT__)
   bool     bt_on;
#endif

   void (*onHandler)(void *); 
   void (*offHandler)(void *); 
} l1sp;

#if defined(__BT_SUPPORT__)
bool L1SP_IsBluetoothOn( void )
{
   return (l1sp.sph_mode==SPH_MODE_BT_CORDLESS || l1sp.sph_mode==SPH_MODE_BT_EARPHONE || 
      l1sp.sph_mode==SPH_MODE_BT_CARKIT || l1sp.sph_mode==SPH_MODE_FM_VIA_BT_CORDLESS);
}
#endif

void L1SP_UpdateSpeechPara( uint16 sph_m_para[NUM_MODE_PARAS] )
{
   memcpy(l1sp.sph_m_para, sph_m_para, NUM_MODE_PARAS*sizeof(uint16));
}
/*******************************************************************/
/*   The new interface for DSP speech enhancement function / Bluetooth */
/*******************************************************************/
#define USE_AEC (defined(AEC_ENABLE) && !(defined(MT6205B) || defined(MT6208) || defined(MT6205) || defined(MT6205C)))
#define USE_EES (defined(EES_ENABLE) && !(defined(MT6205B) || defined(MT6208) || defined(MT6205) || defined(MT6205C)))


uint8 spe_table[SPH_MODE_UNDEFINED] = {
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6227) || defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   #if defined(AEC_ENABLE)          
   /* SPH_MODE_NORMAL */      SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
   #else 
   /* SPH_MODE_NORMAL */      SPE_ES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
   #endif 
   #if defined(AEC_ENABLE)           
   /* SPH_MODE_EARPHONE */    SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
   #else 
   /* SPH_MODE_EARPHONE */    SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
   #endif  
   #if defined(EES_ENABLE)
   /* SPH_MODE_LOUDSPK */     SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
   #else
   /* SPH_MODE_LOUDSPK */     SPE_ES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
   #endif
   #if defined(AEC_ENABLE) && defined(__BT_SUPPORT__)         
   /* SPH_MODE_BT_EARPHONE */ SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
   #else 
   /* SPH_MODE_BT_EARPHONE */ SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
   #endif
   /* SPH_MODE_BT_CORDLESS */ 0,
   #if defined(EES_ENABLE)
   /* SPH_MODE_BT_CARKIT */   SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
   #else 
   /* SPH_MODE_BT_CARKIT */   SPE_ES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
   #endif
#else // MT6205,MT6205B,MT6208,MT6205C,MT6218,MT6218B,MT6219,MT6217 
   #if USE_AEC           
   /* SPH_MODE_NORMAL */      SPE_AEC_FLAG,
   #else 
   /* SPH_MODE_NORMAL */      SPE_ES_FLAG,
   #endif 
   #if USE_AEC           
   /* SPH_MODE_EARPHONE */    SPE_AEC_FLAG,
   #else 
   /* SPH_MODE_EARPHONE */    0,
   #endif  
   #if USE_EES
   /* SPH_MODE_LOUDSPK */     SPE_EES_FLAG,
   #else
   /* SPH_MODE_LOUDSPK */     SPE_ES_FLAG,
   #endif
   #if USE_AEC && defined(__BT_SUPPORT__)         
   /* SPH_MODE_BT_EARPHONE */ SPE_AEC_FLAG,
   #else 
   /* SPH_MODE_BT_EARPHONE */ 0,
   #endif
   /* SPH_MODE_BT_CORDLESS */ 0,
   #if USE_EES
   /* SPH_MODE_BT_CARKIT */   SPE_EES_FLAG,
   #else 
   /* SPH_MODE_BT_CARKIT */   SPE_ES_FLAG,
   #endif
#endif
   /* SPH_MODE_AUX2 */        0,
   /* SPH_MODE_AUX3 */        0            
};   

void SetSpeechEnhancement( bool ec )
{
   if( (!AM_IsSpeechState() || !l1sp.spe_flag) && !AM_IsVoIPOn() )
      return;
   ASSERT(l1sp.sph_mode<SPH_MODE_UNDEFINED);

   kal_trace( TRACE_INFO, L1SP_APPLY_MODE, (ec)?1:0, l1sp.sph_mode, l1sp.sph_level, l1sp.mic_volume );
   if( ec ) {
      uint8 next_state, keep_on_state, on_state, off_state;  
            
      next_state = spe_table[l1sp.sph_mode];
      
      #if defined(MT6227_S00)
      next_state &= ( SPE_AEC_FLAG + SPE_EES_FLAG + SPE_ES_FLAG );
      #endif 
            
      switch( l1sp.sph_mode ) {
         case SPH_MODE_NORMAL:
#if defined(MT6223) || defined(MT6223P)
            /* Because all speech enhancement code on MT6223 is ROM code, 8K     */
            /* limiter need AEC to provide parameter to it. So don't turn off AEC*/
            /* even when min volume. Set l1sp.min_ec_level = 0 to make it        */
            l1sp.min_ec_level = 0;
#endif
            if ((next_state & SPE_AEC_FLAG) && !(l1sp.sph_level>=l1sp.min_ec_level && l1sp.sph_level<=l1sp.max_ec_level))            
               next_state -= SPE_AEC_FLAG;                      
      
            if(next_state & SPE_ES_FLAG) 
            {
               if( l1sp.sph_level==MAX_VOL_LEVEL-1 )
                  AFE_SetMicrophoneVolume( l1sp.mic_volume - 16 );
               else 
                  next_state -= SPE_ES_FLAG;                                                         
            }                         
            break;
      #if defined(__BT_SUPPORT__)      
         case SPH_MODE_BT_EARPHONE:
         case SPH_MODE_BT_CORDLESS:
         case SPH_MODE_BT_CARKIT:
            ASSERT( AM_IsBluetoothOn() );
            break;
      #endif       
         default:
            break;         	
      }

      keep_on_state = next_state & l1sp.spe_state; 
      on_state = next_state - keep_on_state; 
      off_state = l1sp.spe_state - keep_on_state;
   
      if(off_state != 0) 
         SPE_TurnOffProcess(off_state);   
    
      if(next_state != 0)
      {
         kal_trace( TRACE_INFO, L1SP_SPEECH_ENHANCEMENT, 
            l1sp.sph_m_para[0], l1sp.sph_m_para[1], l1sp.sph_c_para[0], l1sp.sph_c_para[1] );
         if(next_state & SPE_ES_FLAG)
            SPE_LoadSpeechPara_ES(l1sp.sph_m_para[0], l1sp.sph_m_para[1]);                
         
      #if !defined(MT6205B)  
         if(next_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG))
            SPE_LoadSpeechPara(l1sp.sph_c_para, l1sp.sph_m_para);
      #endif 
         
         if(on_state != 0) 
            SPE_TurnOnProcess(on_state);
      }
      
      l1sp.spe_state = next_state;
   #if !defined(MT6205B)
      SPE_Clear_DLL_Entry(l1sp.spe_state);           
   #endif    
   }
   else {
      if(l1sp.spe_state != 0)
      {
         SPE_TurnOffProcess(l1sp.spe_state);  
         l1sp.spe_state = 0; 
      #if !defined(MT6205B)  
         SPE_Clear_DLL_Entry(0);    
      #endif     
      }   
   }

   if( (l1sp.sph_mode==SPH_MODE_LOUDSPK)
#if !USE_AEC
   	 || ( (l1sp.sph_mode==SPH_MODE_NORMAL) && (l1sp.sph_level==MAX_VOL_LEVEL-1) ) 
#endif
      )
      AFE_SetSidetone( false );
   else
      AFE_SetSidetone( true );
   
}

void L1SP_LoadCommonSpeechPara( uint16 c_para[NUM_COMMON_PARAS] )
{
   memcpy(l1sp.sph_c_para, c_para, NUM_COMMON_PARAS*sizeof(uint16));
   SetSpeechEnhancement( true );
   
   // Some common parameters are used in non-speech function
   // Force to load common parameter
#if !defined(MT6205B)
   SPE_LoadSpeechPara(l1sp.sph_c_para, NULL);
#endif
#if defined(MT6227) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6227D) || defined(MT6235) || defined(MT6238)
   // DSP limiter can't run at SPH_MODE_BT_CORDLESS, MCU workaround it
   // The newer chip after MT6223 has fixed it
   if(l1sp.sph_mode == SPH_MODE_BT_CORDLESS)
   {
      SPE_LoadLimiterPara(0);
   }
#endif
}


kal_uint8 L1SP_GetSpeechMode( void )
{
    return l1sp.sph_mode;
}

void L1SP_SetSpeechMode( uint8 mode, uint16 m_para[NUM_MODE_PARAS] )
{
   uint8 prev_sph_mode = l1sp.sph_mode;
   l1sp.sph_mode = mode;

#if defined(__BT_SUPPORT__)   
   // Turn off the BT related function
   if( prev_sph_mode == SPH_MODE_BT_CORDLESS ) {
      AM_BTCordlessOff();
   }
#if defined(__BT_FM_VIA_SCO__)
   if( prev_sph_mode == SPH_MODE_FM_VIA_BT_CORDLESS ){
      AM_PCM8K_RecordOff( true );
   }
#endif
      if(l1sp.bt_on)
      {
         AM_BluetoothOff();
         l1sp.bt_on = false;
      }

   if( mode == SPH_MODE_BT_CORDLESS || mode == SPH_MODE_BT_EARPHONE || 
      mode == SPH_MODE_BT_CARKIT || mode == SPH_MODE_FM_VIA_BT_CORDLESS )
   {
      if ((mode==SPH_MODE_BT_CORDLESS || mode==SPH_MODE_FM_VIA_BT_CORDLESS)) {
         KT_StopAndWait();
         TONE_StopAndWait();
         AM_BluetoothOn(1);
      } else {
         AM_BluetoothOn(2);
      }
      
      l1sp.bt_on = true;
      
      if (mode == SPH_MODE_BT_CORDLESS) {
         AM_BTCordlessOn();
      }
#if defined(__BT_FM_VIA_SCO__)
      if( mode == SPH_MODE_FM_VIA_BT_CORDLESS ){
         AM_PCM8K_RecordOn();
      }
#endif
   } 
#endif 
         
   memcpy(l1sp.sph_m_para, m_para, NUM_MODE_PARAS*sizeof(uint16));

   kal_trace( TRACE_INFO, L1SP_SET_MODE, l1sp.sph_mode, l1sp.sph_level, l1sp.mic_volume );
   SetSpeechEnhancement( true );

#if defined(MT6227) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6227D) || defined(MT6235) || defined(MT6238)
   // DSP limiter can't run at SPH_MODE_BT_CORDLESS, MCU workaround it
   // The newer chip after MT6223 has fixed it
   if(prev_sph_mode != SPH_MODE_BT_CORDLESS && l1sp.sph_mode == SPH_MODE_BT_CORDLESS)
   {
      SPE_LoadLimiterPara(0);
   }
   else if(prev_sph_mode == SPH_MODE_BT_CORDLESS && l1sp.sph_mode != SPH_MODE_BT_CORDLESS)
   {
      SPE_LoadLimiterPara(l1sp.sph_c_para[1]);
   }
#endif
}

void L1SP_SetOutputDevice( uint8 device )
{
   AFE_SetOutputDevice( L1SP_SPEECH, device );   
}

void L1SP_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#if defined( MT6205B ) 
   // in MT6205B , digital_gain_index is the role of  volume2 , which is used to set volume of buf1 
   digital_gain_index  =  volume1;     
#endif 
   AFE_SetOutputVolume( L1SP_SPEECH, volume1, digital_gain_index );   
}

void L1SP_SetSpeechVolumeLevel( kal_uint8 level )
{
   if( level<MAX_VOL_LEVEL ) {
      l1sp.sph_level = level;

      kal_trace( TRACE_INFO, L1SP_SET_MODE, l1sp.sph_mode, l1sp.sph_level, l1sp.mic_volume );
      SetSpeechEnhancement( true );
   }
}

void L1SP_SetInputSource( uint8 src )
{
   AFE_SetInputSource( src );
}

uint8 L1SP_GetInputSource( void )
{
   return AFE_GetInputSource();
}

void L1SP_SetMicrophoneVolume( uint8 mic_volume )
{
   AFE_SetMicrophoneVolume( mic_volume );
   l1sp.mic_volume = mic_volume;

   kal_trace( TRACE_INFO, L1SP_SET_MODE, l1sp.sph_mode, l1sp.sph_level, l1sp.mic_volume );
   SetSpeechEnhancement( true );
}

uint8 L1SP_GetMicrophoneVolume( void )
{
   return AFE_GetMicrophoneVolume();
}

void L1SP_SetSidetoneVolume( uint8 sidetone )
{
   AFE_SetSidetoneVolume( sidetone );
}

uint8 L1SP_GetSidetoneVolume( void )
{
   return AFE_GetSidetoneVolume();
}

void L1SP_MuteMicrophone( bool mute )
{
   AFE_MuteMicrophone( mute );
   AM_MuteULSpeech( mute );
}

bool L1SP_IsMicrophoneMuted( void )
{
   return AM_IsULSpeechMuted();
}

extern void CSR_SP3G_Callback( SP3G_Event event, void *data );
extern void vt_SP3G_Callback( kal_uint8 event, void *data );

#if defined( __WCDMA_RAT__ )
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void L1SP_SetState(uint8 state)
{
   l1sp.state = state; 
   L1Audio_Msg_Speech_State(L1Audio_Speech_State(state));
}

uint8 L1SP_GetState( void )
{
   return l1sp.state; 
}

//====================================================================
void L1SP_Speech_On( uint8 RAT_Mode )
{
   if( AM_IsSpeechOn() )
      return;

#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   AFE_SetDigitalGain(L1SP_SPEECH, 100);
#endif    

#if defined(AEC_ENABLE) || defined(EES_ENABLE) || IS_CHIP_MT6217 || defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   DSP_DynamicDownload( DDID_NOISE_REDUCTION );   
#endif

#if defined(MT6217) || defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   SPE_SetSBSD( true );
#endif

   l1sp.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( l1sp.aud_id );     /* To lock sleep mode */

#if defined( __WCDMA_RAT__ )
/* under construction !*/
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
                    
   AM_SpeechOn(RAT_Mode);
   
   switch(RAT_Mode)
   {
      case RAT_2G_MODE:
         L1SP_SetState(L1SP_STATE_2G_SPEECH_ON);     
         break;
#if defined( __WCDMA_RAT__ )
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
      default: 
         ASSERT(false);
   }                           
      
   SetSpeechEnhancement( true );
   if(l1sp.onHandler != NULL)
      l1sp.onHandler( (void *)l1sp.state );
#if defined( __WCDMA_RAT__ )
/* under construction !*/
/* under construction !*/
#endif
}

void L1SP_Register_Service(void (*onHandler)(void *), void (*offHandler)(void *))
{
   l1sp.onHandler = onHandler;   
   l1sp.offHandler = offHandler;
}

void L1SP_UnRegister_Service( void )
{
   l1sp.onHandler = NULL;   
   l1sp.offHandler = NULL;
}

void L1SP_Speech_Off( void )
{
   if( !AM_IsSpeechOn() )
      return;
   
   if(l1sp.offHandler != NULL)
      l1sp.offHandler( (void *)l1sp.state );
   SetSpeechEnhancement( false );
   AM_SpeechOff();

#if defined( __WCDMA_RAT__ )
/* under construction !*/
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   L1SP_SetState( L1SP_STATE_IDLE );
   
   L1Audio_ClearFlag( l1sp.aud_id );
   L1Audio_FreeAudioID( l1sp.aud_id );

#if defined(MT6217) || defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   SPE_SetSBSD( false );
#endif

}

void L1SP_Set_DAI_Mode( uint8 mode )
{
   AM_SetDAIMode( mode );
}

void L1SP_SetAfeLoopback( bool enable )
{
   if( enable )
      AFE_TurnOnLoopback();
   else
      AFE_TurnOffLoopback();
}

void L1SP_SetFIR( bool enable )
{
   if( enable )
      AFE_TurnOnFIR( L1SP_SPEECH );
   else
      AFE_TurnOffFIR( L1SP_SPEECH );
}

void L1SP_Write_Audio_Coefficients( const int16 in_coeff[45], const int16 out_coeff[45] )
{
   AM_WriteFirCoeffs( in_coeff, out_coeff );
}


void L1SP_EnableSpeechEnhancement( bool enable )
{
   if(enable)
   {
      l1sp.spe_flag = true;
      SetSpeechEnhancement(true);
   }
   else 
   {
      SetSpeechEnhancement(false);
      l1sp.spe_flag = false;
   }      
}

#if !defined(MT6205B)
void L1SP_LoadSpeechPara( void ) 
{
   SPE_LoadSpeechPara(l1sp.sph_c_para, l1sp.sph_m_para);      
}
#endif 

void L1SP_Init( void )
{
   l1sp.sph_mode = SPH_MODE_UNDEFINED;
#ifndef __L1_STANDALONE__
   custom_cfg_audio_ec_range( &l1sp.min_ec_level, &l1sp.max_ec_level );
#else
   l1sp.min_ec_level = 1;
   l1sp.max_ec_level = 6;
#endif
   memset(&l1sp.sph_c_para, 0, 12*2);
   memset(&l1sp.sph_m_para, 0, 8*2);
   l1sp.mic_volume = AFE_GetMicrophoneVolume(); // get initial value

#if defined(__BT_SUPPORT__)   
   l1sp.bt_on = false;
#endif

   SPE_Init();
   l1sp.spe_flag = true;
   l1sp.spe_state = 0;
   
   l1sp.onHandler = NULL;
   l1sp.offHandler = NULL;
   L1SP_SetState(L1SP_STATE_IDLE);
}   