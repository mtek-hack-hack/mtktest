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
 * audioEQ.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Audio EQ Manager
 *
 * Author:
 * -------
 * -------
 *
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
 *******************************************************************************/
#include "am.h"
#include "afe.h"


#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6226D) || defined(MT6227D)
#define EQ_DSP_FIR_CASE
#define MAX_FIR_TAPS    17       /* DSP version */
#elif defined(MT6223) || defined(MT6223P) || defined(MT6225)
#define EQ_HW_FIR_CASE
#define MAX_FIR_TAPS    45       /* HW version */
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6238) || defined(MT6268T)
#define EQ_SW_IIR_CASE
#define MAX_FIR_TAPS    45       /* HW version */
#endif

#if defined(AUDIO_EQUALIZER_ENABLE)

static kal_bool aeq_enable = false;

// ******** Equalizer: Common Code for Firmware FIR and Hardware FIR ********
#if defined(EQ_DSP_FIR_CASE) || defined(EQ_HW_FIR_CASE)

#define MAX_32          (int32)0x7fffffffL
#define MIN_32          (int32)0x80000000L

#define FR_BANK_NO      8
#define FFT_size        128
#define N_FFT_div_2     128
#define N_FFT           256
#define log_2_N         8
#define NPT             128
#define LAP            ((NPT+1) / 25)

extern int16 my_cos( int32 idx );

typedef struct {
   int32  re;
   int32  im;
} complex;

// The boundary of frequency band, unit in Hz
static const int16 freq_boundary[FR_BANK_NO]  = {
   600, 960, 1500, 2400, 3840, 6000, 9600, 15360
};

// The magnitude of each band
static int8 aeq_magnitude[8] = {
   0, 0, 0, 0, 0, 0, 0, 0
};

/* -------------------------------------------------------------------------------- */
/* Basic Operation                                                                  */
/* -------------------------------------------------------------------------------- */

static int32 L_add (int32 L_var1, int32 L_var2)
{
    int32 L_var_out;

    L_var_out = L_var1 + L_var2;

    if (((L_var1 ^ L_var2) & MIN_32) == 0) {
        if ((L_var_out ^ L_var1) & MIN_32) {
            L_var_out = (L_var1 < 0) ? MIN_32 : MAX_32;
        }
    }
    return (L_var_out);
}

static int32 L_sub (int32 L_var1, int32 L_var2)
{
    int32 L_var_out;

    L_var_out = L_var1 - L_var2;

    if ( ((L_var1 ^ L_var2) & MIN_32 ) != 0) {
        if ((L_var_out ^ L_var1) & MIN_32) {
            L_var_out = (L_var1 < 0L) ? MIN_32 : MAX_32;
        }
    }
    return (L_var_out);
}

static int32 L_shr (int32 L_var1, int16 var2)
{
   if (L_var1 < 0)
      return ~((~L_var1) >> var2);
   return L_var1 >> var2;
}

static int32 Mult32_16( int32 L_32, int32 n )
{
   int32 rl = L_sub(L_shr(L_32, 1),  (L_32 >> 16) << 15 );

   L_32 = (int16)(L_32 >>16) * (int16)n;
   L_32 = L_add( L_32, L_32 );
   n = (int16)rl * (int16)n >> 15;
   return L_add( L_32, L_add(n, n) );
}

/* -------------------------------------------------------------------------------- */
/* Sin/Cos/Pow functions                                                            */
/* -------------------------------------------------------------------------------- */
static const uint16 powtab[] = {
   434,   439,   445,   450,   455,   460,   466,   471,
   476,   482,   487,   493,   499,   505,   510,   516,
   522,   528,   535,   541,   547,   553,   560,   566,
   573,   579,   586,   593,   600,   607,   614,   621,
   628,   635,   643,   650,   658,   665,   673,   681,
   689,   697,   705,   713,   721,   730,   738,   747,
   755,   764,   773,   782,   791,   800,   809,   819,
   828,   838,   847,   857,   867,   877,   887,   898,
   908,   919,   929,   940,   951,   962,   973,   984,
   996,  1007,  1019,  1031,  1043,  1055,  1067,  1079,
  1092,  1105,  1117,  1130,  1143,  1157,  1170,  1184,
  1197,  1211,  1225,  1239,  1254,  1268,  1283,  1298,
  1313,  1328,  1343,  1359,  1375,  1391,  1407,  1423,
  1440,  1456,  1473,  1490,  1507,  1525,  1543,  1560,
  1579,  1597,  1615,  1634,  1653,  1672,  1691,  1711,
  1731,  1751,  1771,  1792,  1812,  1833,  1855,  1876,
  1898,  1920,  1942,  1965,  1987,  2010,  2034,  2057,
  2081,  2105,  2130,  2154,  2179,  2204,  2230,  2256,
  2282,  2308,  2335,  2362,  2389,  2417,  2445,  2473,
  2502,  2531,  2560,  2590,  2620,  2650,  2681,  2712,
  2744,  2775,  2807,  2840,  2873,  2906,  2940,  2974,
  3008,  3043,  3078,  3114,  3150,  3187,  3223,  3261,
  3299,  3337,  3375,  3414,  3454,  3494,  3535,  3575,
  3617,  3659,  3701,  3744,  3787,  3831,  3876,  3920,
  3966,  4012,  4058,  4105,  4153,  4201,  4250,  4299,
  4349,  4399,  4450,  4501,  4553,  4606,  4660,  4714,
  4768,  4823,  4879,  4936,  4993,  5051,  5109,  5168,
  5228,  5289,  5350,  5412,  5475,  5538,  5602,  5667,
  5733,  5799,  5866,  5934,  6003,  6072,  6143,  6214,
  6286,  6359,  6432,  6507,  6582,  6658,  6735,  6813,
  6892,  6972,  7053,  7134,  7217,  7301,  7385,  7471,
  7557,  7645,  7733,  7823,  7913,  8005,  8098,  8192
};

static int16 twid_factor( int re, int idx )
{
   extern const int16 sintab[];  /* defined in wav_codec.c */

   ASSERT( idx >= 0 && idx < N_FFT_div_2 );
   idx = idx * 512 / N_FFT_div_2;
   if ( re ) {
      if( idx < 256 )
         return sintab[256 - idx];
      return -sintab[idx - 256];
   } else {
      if( idx < 256 )
         return sintab[idx];
      return sintab[512 - idx];
   }
}

/* -------------------------------------------------------------------------------- */
/* FFT                                                                              */
/*    data is the input/ouput                                                       */
/*    isign : 1 ==> FFT                                                             */
/*    isign : -1 ==> iFFT                                                           */
/* -------------------------------------------------------------------------------- */

static void fft( complex *data, int16 isign )
{
   int32 node_space, twid_idx, N_bflys_per_group, N_group;
   int32 I, J, k, x0_idx, x1_idx;
   int32 temp1, temp2;

   /* initialization */
   N_bflys_per_group = 1;
   N_group = N_FFT_div_2;
   //twid_modifier=1;
   node_space = 1;

   J = 0;
   // This is the bit-reversal section of the routine.
   for (I=0; I < N_FFT-1; I++) {
      //	if (J > I) {temp=data[J];data[J]=data[I];data[I]=temp;} //Exchange the two complex numbers.
      if (J > I) {
         complex temp;
         temp = data[J];
         data[J] = data[I];
         data[I] = temp;
      }
      k = N_FFT_div_2;
      while( k >= 2 && J >=k ) {
         J -= k;
         k >>= 1;
      }
      J += k;
   }

   // stage loop
   for (I=0; I < log_2_N; I++) {
      x0_idx = 0;
      x1_idx = x0_idx+node_space;
      // group loop
      for (J=0; J < N_group; J++) {
         twid_idx = 0;
         // butterfly loop
         for (k=0;k < N_bflys_per_group; k++) {
          	//y1(C)+x1(-S)
            temp1 = Mult32_16(data[x1_idx].im, twid_factor(1, twid_idx)) +
               Mult32_16(data[x1_idx].re, (-isign * twid_factor(0, twid_idx)));
            temp2 = Mult32_16(data[x1_idx].re, twid_factor(1, twid_idx)) -
               Mult32_16(data[x1_idx].im, (-isign * twid_factor(0, twid_idx)));

            data[x1_idx].im = data[x0_idx].im - temp1;
            data[x1_idx].re = data[x0_idx].re - temp2;
            data[x0_idx].re = data[x0_idx].re + temp2;
            data[x0_idx].im = data[x0_idx].im + temp1;

            x0_idx++;   //point to next butterfly
            x1_idx++;
            twid_idx += N_group;
         }
         x0_idx += node_space;
         x1_idx += node_space;
      }
      N_bflys_per_group <<= 1;
      node_space = N_bflys_per_group;
      N_group >>= 1;
   }
   if ( isign == -1 ) {
      for( I = 0; I < N_FFT; I++ ) {
         data[I].re /= N_FFT;
         data[I].im /= N_FFT;
      }
   }
}

/* -------------------------------------------------------------------------------- */
/* FIR           : output FIR coefficient                                           */
/*     Length        : FIR Length ( 17 for 621x , 45 for 622x )                     */
/*     Sampling_rate : 8, 11.025, 12, 16, 22.05, 24, 32, 44.1, 48                   */
/*     FR_boundary   : freq. response boundary from DC to Nyquist rate              */
/*     FreqR_mmi_db  : Desired frequency reponse for related freq.                  */
/*                     bank reange from -25.5dB to 0dB                              */
/* -------------------------------------------------------------------------------- */
static void EQ_FIR( int32 len, int32 Sampling_rate, const int16 *FR_boundary,
            const int8 *FreqR_mmi_db, int32 *buf )
{
   int32 I, J, nb, ne, bank_no;
   complex *H = (complex*)buf;

   ASSERT( Sampling_rate > 0 );
   for (I=0; I < FR_BANK_NO; I++) {
      if ( I > 0 )
         ASSERT( FR_boundary[I] > FR_boundary[I-1] );
      ASSERT( FR_boundary[I] > 0 );
      if ( FR_boundary[I]*2 >= Sampling_rate )
         break;
   }
   bank_no = I;

   if( len & 1 )
      len--;

   nb = 0;
   for (I=0; I <= bank_no; I++) {
      if( I == bank_no )
         ne = NPT;
      else
         ne = (2 * FR_boundary[I] * (NPT+1) / Sampling_rate ) - 1;

      for (J = nb; J <= ne; J++) {
         if ( I == 0 ) {
            H[J].re = powtab[FreqR_mmi_db[0] + 128];
         } else if (I == bank_no) {
            H[J].re = powtab[FreqR_mmi_db[I-1] + 128];
         } else {
            int32 dBindex;
            
            if (ne > nb) {
               dBindex = FreqR_mmi_db[I-1]*(ne-J) + FreqR_mmi_db[I]*(J-nb);
               dBindex = dBindex / (ne-nb);
            } else {
               dBindex = FreqR_mmi_db[I-1];
            }
            H[J].re = powtab[dBindex + 128];
         }
      }
      nb = ne + 1;
   }

   for (I=0; I <= NPT; I++) {
      H[I].im = (H[I].re * my_cos(0x4000 + 0x4000 * len * I / NPT) >> 13);
      H[I].re = (H[I].re * my_cos(0x4000 * len * I / NPT) >>13);
   }

   for (I=1; I < FFT_size; I++) {
      H[FFT_size + FFT_size - I].re = H[I].re;
      H[FFT_size + FFT_size - I].im = -H[I].im;
   }

   fft( H, -1 );

   for (I=0; I < (len + 1); I++) {
      buf[I] = (H[I].re * 553 >> 10) - (Mult32_16(H[I].re * 471, my_cos( (I << 16) / len)) >> 10);
   }
}

#endif  //defined(EQ_DSP_FIR_CASE) || defined(EQ_HW_FIR_CASE) // Common Code

/* -------------------------------------------------------------------------------- */
/* Driver                                                                           */
/* -------------------------------------------------------------------------------- */

#if defined(EQ_DSP_FIR_CASE)

/* -------------------------------------------------------------------------------- */
/* DSP FIR Driver                                                              */
/* -------------------------------------------------------------------------------- */

#define MIN_DIGI_GAIN   0

#if defined(MT6217) || defined(MT6219)
#define DIFF_DIGI_GAIN  30
#else
#define DIFF_DIGI_GAIN  0x1000
#endif

void writeNorm( int16 max )
{
#if defined(MT6217) || defined(MT6219)
   *DSP_PM_ADDR(0, 0x3F63) = max;
#else
   *DSP_DM_ADDR(0, 0x29E1) = max;
#endif
}

void AEQ_Activate( int16 asp_fs, bool rampup )
{
   int32 max, I;
   int32 *buf, sampling_rate = 8000;
   int16 aeq_norm;

   if ( !aeq_enable ) {
      // Write normal effect to hardware
      *DP_AEQ_CTRL = 0;
      return;
   }

   switch( asp_fs ) {
      case ASP_FS_8K:   sampling_rate = 8000;   break;
      case ASP_FS_11K:  sampling_rate = 11025;  break;
      case ASP_FS_12K:  sampling_rate = 12000;  break;
      case ASP_FS_16K:  sampling_rate = 16000;  break;
      case ASP_FS_22K:  sampling_rate = 22050;  break;
      case ASP_FS_24K:  sampling_rate = 24000;  break;
      case ASP_FS_32K:  sampling_rate = 32000;  break;
      case ASP_FS_44K:  sampling_rate = 44100;  break;
      case ASP_FS_48K:  sampling_rate = 48000;  break;
      default: ASSERT(false); break;
   }
   
   buf = (int32 *)get_ctrl_buffer( 2048 );
   EQ_FIR( MAX_FIR_TAPS, sampling_rate, freq_boundary, aeq_magnitude, buf );
   max = buf[MAX_FIR_TAPS/2];
   ASSERT( max > 0 );

   {
      int sumCoef = 0;
      
      for (I=0; I < MAX_FIR_TAPS; I++) {
         if (buf[I] < 0) {
            sumCoef -= buf[I];
         } else {
            sumCoef += buf[I];
         }
      }
      
      // Normalize the FIR coefficients
      if (sumCoef < 32767) {
         for (I=0; I < MAX_FIR_TAPS; I++)    /* Normalization */
            buf[I] = buf[I] * 32767 / sumCoef;
      }
   }
   
   // ramp down
#if defined(MT6217) || defined(MT6219)
   aeq_norm = 256;
#else
   aeq_norm = 32767;
#endif
   if (rampup) {
      while( aeq_norm > MIN_DIGI_GAIN ) {
         aeq_norm = (aeq_norm > DIFF_DIGI_GAIN)? (aeq_norm-DIFF_DIGI_GAIN):0;
         writeNorm( aeq_norm );
         kal_sleep_task(1);
      }
   }


   {
      volatile uint16* dsp_ptr;
      
#if defined(MT6217) || defined(MT6219)   
      dsp_ptr = DSP_PM_ADDR(0, 0x3F52);
#else
      dsp_ptr = DSP_DM_ADDR(0, 0x29D0);
#endif

      for( I = 0; I < MAX_FIR_TAPS; I++ )
         *dsp_ptr++ = (int16)buf[I];
   }
   
#if defined(MT6217) || defined(MT6219)
   aeq_norm = 256;
#else
   aeq_norm = 32767;
#endif

   if ( !rampup ) {
      writeNorm( aeq_norm );
   } else {
      for ( max = MIN_DIGI_GAIN; max < aeq_norm; max += DIFF_DIGI_GAIN ) {
         writeNorm( max );
         kal_sleep_task(1);
      }
      writeNorm( aeq_norm );
   }
   
   free_ctrl_buffer( buf );
   
   // Turn on audio equalizer
   *DP_AEQ_CTRL = 3;
}

void AudioPP_Equalizer_SetMag( kal_int8 magnitude[8] )
{
   int32 I;
   int32 maxMag, shiftOffset;
   int16 asp_fs;
   
   maxMag = magnitude[0];;
   for (I=1; I<8; I++) {
      if (maxMag < magnitude[I])
         maxMag = magnitude[I];
   }
   
   // Shift the maximal valut to be 0dB (127)
   shiftOffset = 127 - maxMag;
   for (I=0; I < 8; I++) {
      aeq_magnitude[I] = (int8) (magnitude[I] + shiftOffset);
   }

#if defined(MT6217) || defined(MT6219)
   if ( (asp_fs = AM_IsAudioPlaybackOn()) != -1 && (*DAF_MAIN_CONTROL&1) ) {
#else
   if ( (asp_fs = AM_IsAudioPlaybackOn()) != -1 ) {
#endif
      AEQ_Activate( asp_fs, true );
   }
}

void AudioPP_Equalizer_TurnOn( void )
{
   int16 asp_fs;
   
   aeq_enable = true;

#if defined(MT6217) || defined(MT6219)
   if ( (asp_fs = AM_IsAudioPlaybackOn()) != -1 && (*DAF_MAIN_CONTROL&1) ) {
#else
   if ( (asp_fs = AM_IsAudioPlaybackOn()) != -1 ) {
#endif
      AEQ_Activate( asp_fs, true );
   }
}

void AudioPP_Equalizer_TurnOff( void )
{
   aeq_enable = false;
   if (AM_IsAudioPlaybackOn() != -1) {
      // Turn off audio equalizer
      *DP_AEQ_CTRL = 0;
   }
}

kal_bool AudioPP_Equalizer_IsEnable( void )
{
   return aeq_enable;
}

#elif defined(EQ_HW_FIR_CASE)

/* -------------------------------------------------------------------------------- */
/* Hardware FIR Driver                                                              */
/* -------------------------------------------------------------------------------- */

static void AudioPP_Equalizer_ApplyEffect( int16 *pEffect, kal_bool rampup )
{
   int32 I, J;
   int16 *buf;
   kal_bool isControlBuf = false;
   
   buf = pEffect;
   if (pEffect == NULL) {
      isControlBuf = true;
      buf = (int16 *)get_ctrl_buffer( MAX_FIR_TAPS*sizeof(int16) );
      memset( buf, 0, MAX_FIR_TAPS*sizeof(int16) );
      buf[0] = 32767;
   }

   if ( rampup ) {
      // Use hardware mute to aovid noise during transition
      AFE_SetHardwareMute(true);
   } else {
      // When we want to use hardware FIR, audio power must be turned on
      AFE_TurnOnAudioPower();
   }
   
   // Because hardware accepts the coefficient only at a certain time,
   // We write several times to work around
   for (I=0; I < MAX_FIR_TAPS; I++) {
      for (J=0; J < 400; J++) {
         *(AFE_EQCOEF+2*I) = buf[I];
      }
   }
   
   // read back for fixing a MT6228 hardware issue
   for (I=0; I < MAX_FIR_TAPS; I++)
      J = *(AFE_EQCOEF+2*I);

   // Disable hardware mute
   if ( rampup )
      AFE_SetHardwareMute(false);

   if (isControlBuf)
      free_ctrl_buffer( buf );
}

void AEQ_Activate( int16 asp_fs, bool rampup )
{
   int32 max, I;
   int32 *buf, sampling_rate = 8000;

   if ( !aeq_enable ) {
      // Write normal effect to hardware
      AudioPP_Equalizer_ApplyEffect(NULL, rampup);
      return;
   }

   switch( asp_fs ) {
      case ASP_FS_8K:   sampling_rate = 8000;   break;
      case ASP_FS_11K:  sampling_rate = 11025;  break;
      case ASP_FS_12K:  sampling_rate = 12000;  break;
      case ASP_FS_16K:  sampling_rate = 16000;  break;
      case ASP_FS_22K:  sampling_rate = 22050;  break;
      case ASP_FS_24K:  sampling_rate = 24000;  break;
      case ASP_FS_32K:  sampling_rate = 32000;  break;
      case ASP_FS_44K:  sampling_rate = 44100;  break;
      case ASP_FS_48K:  sampling_rate = 48000;  break;
      default: ASSERT(false); break;
   }
   
   buf = (int32 *)get_ctrl_buffer( 2048 );
   EQ_FIR( MAX_FIR_TAPS, sampling_rate, freq_boundary, aeq_magnitude, buf );
   max = buf[MAX_FIR_TAPS/2];
   ASSERT( max > 0 );

   {
      int sumCoef = 0;
      
      for (I=0; I < MAX_FIR_TAPS; I++) {
         if (buf[I] < 0) {
            sumCoef -= buf[I];
         } else {
            sumCoef += buf[I];
         }
      }
      
      // Normalize the FIR coefficients
      if (sumCoef < 32767) {
         for (I=0; I < MAX_FIR_TAPS; I++)    /* Normalization */
            buf[I] = buf[I] * 32767 / sumCoef;
      }
   }
   
   AudioPP_Equalizer_ApplyEffect( (int16 *)buf, rampup);
   
   free_ctrl_buffer( buf );
}

void AudioPP_Equalizer_SetMag( kal_int8 magnitude[8] )
{
   int32 I;
   int32 maxMag, shiftOffset;
   int16 asp_fs;
   
   maxMag = magnitude[0];;
   for (I=1; I<8; I++) {
      if (maxMag < magnitude[I])
         maxMag = magnitude[I];
   }
   
   // Shift the maximal valut to be 0dB (127)
   shiftOffset = 127 - maxMag;
   for (I=0; I < 8; I++) {
      aeq_magnitude[I] = (int8) (magnitude[I] + shiftOffset);
   }
   
   if ( (asp_fs = AM_IsAudioPlaybackOn()) != -1 ) {
      AEQ_Activate( asp_fs, true );
   }
}

void AudioPP_Equalizer_TurnOn( void )
{
   int16 asp_fs;
   
   aeq_enable = true;
   
   if ( (asp_fs = AM_IsAudioPlaybackOn()) != -1 ) {
      AEQ_Activate( asp_fs, true );
   }
}

void AudioPP_Equalizer_TurnOff( void )
{
   aeq_enable = false;
   if (AM_IsAudioPlaybackOn() != -1) {
      // Write normal effect to hardware
      AudioPP_Equalizer_ApplyEffect( NULL, true );
   }
}

kal_bool AudioPP_Equalizer_IsEnable( void )
{
   return aeq_enable;
}

#elif defined(EQ_SW_IIR_CASE)

/* -------------------------------------------------------------------------------- */
/* Software IIR Driver                                                              */
/* -------------------------------------------------------------------------------- */

void AudioPP_Equalizer_TurnOn( void )
{
   HOST_APM_Register(APM_TASKID_EQ);
   aeq_enable = true;
}

void AudioPP_Equalizer_TurnOff( void )
{
   aeq_enable = false;
   HOST_APM_UnRegister(APM_TASKID_EQ);
}

kal_bool AudioPP_Equalizer_IsEnable( void )
{
   return aeq_enable;
}

void AudioPP_EQ_Init(APM_TCM *tcm)
{
   aeq_enable = false;
}

#endif

#endif  // defined(AUDIO_EQUALIZER_ENABLE)


// ******** Audio Compensation Filter ********
#if defined(AUDIO_COMPENSATION_ENABLE)

#define ACF_LOUDSPEAKER_MODE 0
#define ACF_EARPHONE_MODE    1
static kal_int16 AudioCompensationFilter_LoudSpeaker[MAX_FIR_TAPS];
static kal_int16 AudioCompensationFilter_Earphone[MAX_FIR_TAPS];
static kal_int32 AudioCompMode = -1;

#if (MAX_FIR_TAPS == 17)

/* -------------------------------------------------------------------------------- */
/* Firmware FIR Driver                                                              */
/* -------------------------------------------------------------------------------- */

void Audio_Compensation_Activate( kal_bool check )
{
   volatile uint16* dsp_ptr;
   kal_int16 *buf;
   kal_int32 oriMode = AudioCompMode;
   int I;
   
   if ( AFE_IsAudioLoudSpk() ) {
      buf = AudioCompensationFilter_LoudSpeaker;
      AudioCompMode = ACF_LOUDSPEAKER_MODE;
   } else {
      buf = AudioCompensationFilter_Earphone;
      AudioCompMode = ACF_EARPHONE_MODE;
   }
   
   // If the mode is unchanged, then we don't apply again
   if ( check && (AudioCompMode == oriMode) ) {
      return;
   }
   
#if defined(MT6217) || defined(MT6219)   
   dsp_ptr = DSP_PM_ADDR(0, 0x3F52);
#else
   dsp_ptr = DSP_DM_ADDR(0, 0x29D0);
#endif

   for (I=0; I < MAX_FIR_TAPS; I++)
      *dsp_ptr++ = buf[I];

   // Write norm
#if defined(MT6217) || defined(MT6219)   
   *DSP_PM_ADDR(0, 0x3F63) = 256;
#else
   *DSP_DM_ADDR(0, 0x29E1) = 32767;
#endif

   *DP_AEQ_CTRL = 3;
}


#elif (MAX_FIR_TAPS == 45)

/* -------------------------------------------------------------------------------- */
/* Hardware FIR Driver                                                              */
/* -------------------------------------------------------------------------------- */

void Audio_Compensation_Activate( kal_bool check )
{
   int I, J;
   kal_int16 *buf;
   kal_int32 oriMode = AudioCompMode;

   if ( AFE_IsAudioLoudSpk() ) {
      buf = AudioCompensationFilter_LoudSpeaker;
      AudioCompMode = ACF_LOUDSPEAKER_MODE;
   } else {
      buf = AudioCompensationFilter_Earphone;
      AudioCompMode = ACF_EARPHONE_MODE;
   }

   // If the mode is unchanged, then we don't apply again
   if (AudioCompMode == oriMode) {
      return;
   }

   if ( check ) {
      // Use hardware mute to aovid noise during transition
      AFE_SetHardwareMute(true);
   } else {
      // When we want to use hardware FIR, audio power must be turned on
      AFE_TurnOnAudioPower();
   }
   
   // Because hardware accepts the coefficient only at a certain time,
   // We write several times to work around
   for (I=0; I < MAX_FIR_TAPS; I++) {
      for (J=0; J < 400; J++) {
         *(AFE_EQCOEF+2*I) = buf[I];
      }
   }
   
   // read back for fixing a MT6228 hardware issue
   for (I=0; I < MAX_FIR_TAPS; I++)
      J = *(AFE_EQCOEF+2*I);

   // To disable hardware mute
   if ( check ) {
      AFE_SetHardwareMute(false);
   }
}

#endif

void Media_SetAudioCompensation(Media_Aud_Comp_Mode mode, kal_int16 *coeff)
{
   if (mode == MEDIA_AUD_COMP_LOUDSPEAKER) {
      memcpy(AudioCompensationFilter_LoudSpeaker, coeff, MAX_FIR_TAPS*sizeof(kal_int16));
   } else if (mode == MEDIA_AUD_COMP_EARPHONE) {
      memcpy(AudioCompensationFilter_Earphone, coeff, MAX_FIR_TAPS*sizeof(kal_int16));
   } else {
      ASSERT( 0 );
   }
}

#endif // defined(AUDIO_COMPENSATION_ENABLE)


#if !defined(AUDIO_EQUALIZER_ENABLE) && !defined(AUDIO_COMPENSATION_ENABLE) && ( defined(MT6223) || defined(MT6223P) || defined(MT6225) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6238) || defined(MT6268T) )
//#error Please contact with Build Master to set AUDIO_COMPENSATION_ENABLE

void Audio_HW_FIR_Reset( void )
{
   int I, J;

   // When we want to use hardware FIR, audio power must be turned on
   AFE_TurnOnAudioPower();
   
   // Because hardware accepts the coefficient only at a certain time,
   // We write several times to work around
   for (J=0; J < 400; J++) {
      *AFE_EQCOEF = 32767;
   }
   for (I=1; I < MAX_FIR_TAPS; I++) {
      for (J=0; J < 400; J++) {
         *(AFE_EQCOEF+2*I) = 0;
      }
   }
   
   // read back for fixing a MT6228 hardware issue
   for (I=0; I < MAX_FIR_TAPS; I++)
      J = *(AFE_EQCOEF+2*I);
}
#endif

