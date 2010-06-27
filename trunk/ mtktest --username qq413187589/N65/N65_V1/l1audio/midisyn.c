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
 * midisyn.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Software Synthesizer
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
#if defined( SW_SYN_8K ) || defined( SW_SYN_16K ) 

#include "midisyn.h"

/* ------------------------------------------------------------------- */
/* Global variables and functions                                      */
/* ------------------------------------------------------------------- */
int16          polyphony_limit;
int16          current_polyphony;
const uint16   *freqTable;
const uint32   *bendTable;
const int16    *sineTable;
const uint16   *attVolTab;
const uint16   *expVolTab;
const int16    *wavTable;
const int16    **melodicInst;
const int16    **percussiveInst;
ToneGenerator  *toneGen;
MidiChannel    *midiChannel;


/* ------------------------------------------------------------------- */
/* Data/Buffer put in Internal SRAM                                    */
/* ------------------------------------------------------------------- */
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
int16          audio_buffer[256*2];
int32          agc_gain;
int16          agc_init_speed;
int16          agc_steady_speed;
int8           agc_state;
const uint16   alawTable[256] = {
   0xEA80, 0xEB80, 0xE880, 0xE980, 0xEE80, 0xEF80, 0xEC80, 0xED80, 
   0xE280, 0xE380, 0xE080, 0xE180, 0xE680, 0xE780, 0xE480, 0xE580, 
   0xF540, 0xF5C0, 0xF440, 0xF4C0, 0xF740, 0xF7C0, 0xF640, 0xF6C0, 
   0xF140, 0xF1C0, 0xF040, 0xF0C0, 0xF340, 0xF3C0, 0xF240, 0xF2C0, 
   0xAA00, 0xAE00, 0xA200, 0xA600, 0xBA00, 0xBE00, 0xB200, 0xB600, 
   0x8A00, 0x8E00, 0x8200, 0x8600, 0x9A00, 0x9E00, 0x9200, 0x9600, 
   0xD500, 0xD700, 0xD100, 0xD300, 0xDD00, 0xDF00, 0xD900, 0xDB00, 
   0xC500, 0xC700, 0xC100, 0xC300, 0xCD00, 0xCF00, 0xC900, 0xCB00, 
   0xFEA8, 0xFEB8, 0xFE88, 0xFE98, 0xFEE8, 0xFEF8, 0xFEC8, 0xFED8, 
   0xFE28, 0xFE38, 0xFE08, 0xFE18, 0xFE68, 0xFE78, 0xFE48, 0xFE58, 
   0xFFA8, 0xFFB8, 0xFF88, 0xFF98, 0xFFE8, 0xFFF8, 0xFFC8, 0xFFD8, 
   0xFF28, 0xFF38, 0xFF08, 0xFF18, 0xFF68, 0xFF78, 0xFF48, 0xFF58, 
   0xFAA0, 0xFAE0, 0xFA20, 0xFA60, 0xFBA0, 0xFBE0, 0xFB20, 0xFB60, 
   0xF8A0, 0xF8E0, 0xF820, 0xF860, 0xF9A0, 0xF9E0, 0xF920, 0xF960, 
   0xFD50, 0xFD70, 0xFD10, 0xFD30, 0xFDD0, 0xFDF0, 0xFD90, 0xFDB0, 
   0xFC50, 0xFC70, 0xFC10, 0xFC30, 0xFCD0, 0xFCF0, 0xFC90, 0xFCB0, 
   0x1580, 0x1480, 0x1780, 0x1680, 0x1180, 0x1080, 0x1380, 0x1280, 
   0x1D80, 0x1C80, 0x1F80, 0x1E80, 0x1980, 0x1880, 0x1B80, 0x1A80, 
   0x0AC0, 0x0A40, 0x0BC0, 0x0B40, 0x08C0, 0x0840, 0x09C0, 0x0940, 
   0x0EC0, 0x0E40, 0x0FC0, 0x0F40, 0x0CC0, 0x0C40, 0x0DC0, 0x0D40, 
   0x5600, 0x5200, 0x5E00, 0x5A00, 0x4600, 0x4200, 0x4E00, 0x4A00, 
   0x7600, 0x7200, 0x7E00, 0x7A00, 0x6600, 0x6200, 0x6E00, 0x6A00, 
   0x2B00, 0x2900, 0x2F00, 0x2D00, 0x2300, 0x2100, 0x2700, 0x2500, 
   0x3B00, 0x3900, 0x3F00, 0x3D00, 0x3300, 0x3100, 0x3700, 0x3500, 
   0x0158, 0x0148, 0x0178, 0x0168, 0x0118, 0x0108, 0x0138, 0x0128, 
   0x01D8, 0x01C8, 0x01F8, 0x01E8, 0x0198, 0x0188, 0x01B8, 0x01A8, 
   0x0058, 0x0048, 0x0078, 0x0068, 0x0018, 0x0008, 0x0038, 0x0028, 
   0x00D8, 0x00C8, 0x00F8, 0x00E8, 0x0098, 0x0088, 0x00B8, 0x00A8, 
   0x0560, 0x0520, 0x05E0, 0x05A0, 0x0460, 0x0420, 0x04E0, 0x04A0, 
   0x0760, 0x0720, 0x07E0, 0x07A0, 0x0660, 0x0620, 0x06E0, 0x06A0, 
   0x02B0, 0x0290, 0x02F0, 0x02D0, 0x0230, 0x0210, 0x0270, 0x0250, 
   0x03B0, 0x0390, 0x03F0, 0x03D0, 0x0330, 0x0310, 0x0370, 0x0350
};
#pragma arm section rwdata , rodata , zidata


#pragma arm section code = "INTERNCODE"

/* ------------------------------------------------------------------- */
/* Envelope Generator                                                  */
/* ------------------------------------------------------------------- */
static int SWSYN_EnvelopeGenerator( ToneGenerator *tg )
{
   register int amp = tg->envelope_volume + tg->envelope_increment;

   switch( tg->state ) {
   case EG_ATTACK:
      if( amp >= MAX_ENVELOPE ) {
         if( tg->wt->hold != 0 ) {
            tg->state = EG_HOLD;
            tg->holdTime = 0;
            tg->envelope_increment = 0;
         }
         else {
            tg->state = EG_DECAY;
            tg->envelope_increment = tg->wt->decay;
         }
         amp = MAX_ENVELOPE;
      }
      break;
   case EG_HOLD:
      tg->holdTime++;
      if( tg->holdTime >= tg->wt->hold ) {
         tg->state = EG_DECAY;
         tg->envelope_increment = tg->wt->decay;
      }
      break;
   case EG_DECAY:
      if( amp <= MIN_ENVELOPE ) {
         tg->state = EG_DIE;
         tg->envelope_increment = -(MAX_ENVELOPE / 16);
      }
      else if( amp <= tg->wt->sustain && tg->channel != 9 ) {
         tg->state = EG_SUSTAIN;
         amp = tg->wt->sustain;
         tg->envelope_increment = 0;
      }
      break;
   case EG_RELEASE:
      if( amp <= MIN_ENVELOPE ) {
         tg->state = EG_DIE;
         tg->envelope_increment = -(MAX_ENVELOPE / 16);
      }
      break;
   case EG_DIE:
      if( amp <= 0 ) {
         SWSYN_KillNote( tg );
         return 1;
      }
      break;
   }
   tg->envelope_volume = amp;
   return 0;
}

static void SWSYN_ApplyEnvelope( ToneGenerator *tg )
{
   register int32 temp = tg->envelope_volume >> 15;
   register int32 tremolo;

   temp = (tg->state & (EG_ATTACK))? attVolTab[temp] : expVolTab[temp];
   temp >>= 1;
   if( tg->wt->tremolo_increment &&  !(tg->state & (EG_ATTACK|EG_HOLD))) {
      tg->tremolo_offset = (uint16)(tg->tremolo_offset + tg->wt->tremolo_increment);
      tremolo = (int32)sineTable[tg->tremolo_offset>>8] - 32767;
      tremolo = tremolo * (int32)tg->wt->tremolo_depth >> 15;
      temp = temp * (32767 + tremolo) >> 15;
   }
   tg->left_mix = tg->left_amp * temp >> 16;
}

/* ------------------------------------------------------------------- */
void SWSYN_ResampleVoice( ToneGenerator *tg, int32 *sample )
{
   register int m, left_amp;
   register int32 smp, dta;
   int I = 0, J;
   const int16 *pcmtable      = tg->wt_table;
   int32 loopEnd              = tg->wt->loopEnd;
   int32 loopLength           = tg->wt->loopLength;
   int32 sample_increment;
   const int16 *pcm_ptr;
   const uint8 *alaw_ptr;

   m = tg->sample_offset;
   do {
      if( SWSYN_EnvelopeGenerator( tg ) )
         return;
      SWSYN_ApplyEnvelope( tg );
      left_amp = tg->left_mix;
      sample_increment = tg->sample_increment;
      /* Resampling */
      J = 0;
      if( tg->compressed ) {
         do {
            alaw_ptr = &((const uint8*)pcmtable)[m>>12];
            smp = (int32)(int16)alawTable[*alaw_ptr];
            dta = ((int32)(int16)alawTable[*(alaw_ptr+1)] - smp);
            *sample+++= ((( (m & 0xFFF) * dta ) >> 12 ) + smp) * left_amp;
            if( (m += sample_increment) >= loopEnd ) {
               if( loopLength )
                  m -= loopLength;
               else {
                  SWSYN_KillNote( tg );
                  return;
               }
            }
         } while( ++J < SAMPLES_PER_MS );
      }
      else {
         do {
            pcm_ptr = &pcmtable[m>>12];
            smp = (int32)*pcm_ptr;
            dta = ((int32)*(pcm_ptr+1) - smp);
            *sample+++= ((( (m & 0xFFF) * dta ) >> 12 ) + smp) * left_amp;
            if( (m += sample_increment) >= loopEnd ) {
               if( loopLength )
                  m -= loopLength;
               else {
                  SWSYN_KillNote( tg );
                  return;
               }
            }
         } while( ++J < SAMPLES_PER_MS );
      }
   } while( ++I < BLOCK_PERIOD );
   tg->sample_offset = m;
}


/* ------------------------------------------------------------------- */
/* The Audio AGC                                                       */
/* ------------------------------------------------------------------- */
#if defined( ENABLE_AGC )
static void agcStepDown( int32 max_amp, int32 master_volume )
{
   int32    I, J, tmp, tmp_gain;
   int32    *ptr32 = (int32*)audio_buffer;
   int16    *ptr16 = audio_buffer;
   int32    step = (agc_gain - agc_gain * 32767 / max_amp) / BLOCK_PERIOD + 1;

   I = 0;
   do {
      agc_gain -= step;
      J = 0;
      tmp_gain = agc_gain * master_volume >> AGC_GAIN_FACTOR;
      do {
         tmp = *ptr32++ * tmp_gain >> AGC_GAIN_FACTOR;
         *ptr16++ = (int16)((tmp>32767)? 32767 : (tmp<-32768)?-32768:tmp);
      } while( ++J < BLOCK_SAMPLE_NO/BLOCK_PERIOD );
   } while( ++I < BLOCK_PERIOD );
}
#endif

void SWSYN_Agc( int32 master_volume )
{
   int      I = 0;
   int32    *ptr32 = (int32*)audio_buffer;
   int16    *ptr16 = audio_buffer;
   int32    tmp, tmp_gain;
   int32    max_amp = 0;

   do {
      tmp = *ptr32 >> 14;
      if( tmp > max_amp )
         max_amp = tmp;
      else if( tmp < -max_amp )
         max_amp = - tmp;
      *ptr32++ = tmp;
   } while( ++I < BLOCK_SAMPLE_NO );

#if defined( ENABLE_AGC )
   if( max_amp > 1000 ) {     /* maximum amplitude should be larger than the threshold */
      if( agc_state == AGC_INIT_STATE ) {
         tmp = max_amp * (agc_gain + agc_init_speed) >> AGC_GAIN_FACTOR;
         if( tmp < 32767 ) {
            agc_gain = agc_gain + agc_init_speed;
            if( agc_gain > 65535 )
               agc_gain = 65535;
         }
         else {
            agc_state = AGC_STEADY_STATE;
            tmp = max_amp * agc_gain >> AGC_GAIN_FACTOR;
            if( tmp > 32767 ) {
               agcStepDown( tmp, master_volume );
               return;
            }
         }
      }
      else {   /* AGC in steady state */
         tmp = max_amp * agc_gain >> AGC_GAIN_FACTOR;
         if( tmp < 32000 ) {
            agc_gain = agc_gain + agc_steady_speed;
            if( agc_gain > 65535 )
               agc_gain = 65535;
         }
         else if( tmp > 32767 ) {
            agcStepDown( tmp, master_volume );
            return;
         }
      }
   }

#endif
   ptr32 = (int32*)audio_buffer;
   I = 0;
#if defined( ENABLE_AGC )
   tmp_gain = agc_gain * master_volume >> AGC_GAIN_FACTOR;
#else
   tmp_gain = master_volume;
#endif
   do {
      tmp = *ptr32++ * tmp_gain >> AGC_GAIN_FACTOR;
#if defined( ENABLE_AGC )
      *ptr16++ = (int16)tmp;
#else
      *ptr16++ = (int16)((tmp > 32767)? 32767 : (tmp < -32768)? -32768:tmp);
#endif
   } while( ++I < BLOCK_SAMPLE_NO );
}

#pragma arm section code


#else

#include "midisyn.h"
int32 countMSB(uint32 data)
{
   int32 lz;                		
   __asm{		   	
      clz lz,data; 			
   }   
   return (int32)(31-lz); 
} 

#endif


