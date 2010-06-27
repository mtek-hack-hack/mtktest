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
 * spt_analyzer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Audio Spectrum Analyzer for display
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "l1audio_def.h"

#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)

/* -------------------------------------------------------------------------- */
/* Audio/Voice PCM Readback Information                                       */
/* -------------------------------------------------------------------------- */
/* Voice PCM readback:
   +-------------+-----------+------+------+------+------+----------+------+----------+------+----------+------+--------------+------+------+
   |                         |MT6218|MT6217|MT6219|MT6227|MT6227_S01|MT6228|MT6228_S02|MT6229|MT6229_S01|MT6225|MT6223, MT6223|MT6235|MT6238|
   +-------------+-----------+------+------+------+------+----------+------+----------+------+----------+------+--------------+------+------+
   |AMR playback |DM page    |  0   |  0   |  0   |  0   |    0     |  0   |    0     |  2   |    2     |  0   |      0       |  2   |  2   |
   |             |DM addr    |0x3C00|0x3C00|0x3C00|0x3C00|  0x3C00  |0x3C00|  0x3C00  |0x3600|  0x3600  |0x3C00|   0x3600     |0x3600|0x3600|
   |             |DM ptr_addr|0x2D0F|0x2D11|0x2D0F|0x2D11|  0x302E  |0x3114|  0x322D  |0x3912|  0x3927  |0x2E30|   0x383F     |0x3928|0x3928|
   |             |DM buf_len | 368  | 368  | 368  | 368  |   368    | 320  |   320    | 320  |   320    | 320  |    320       | 320  | 320  |
   +-------------+-----------+------+------+------+------+----------+------+----------+------+----------+------+--------------+------+------+
   |AWB playback |DM page    | N/A  | N/A  |  0   |  0   |    0     |  0   |    0     |  2   |    2     |  0   |      0       |  2   |  2   |
   |             |DM addr    | N/A  | N/A  |0x28FA|0x2398|  0x2378  |0x2B98|  0x25F4  |0x1AF4|  0x1AF4  |0x1DF4|    0x1C00    |0x1AF4|0x1AF4|
   |             |DM ptr_addr| N/A  | N/A  |0x3279|0x3288|  0x3295  |0x34B4|  0x352C  |0x3172|  0x3172  |0x38EE|    0x30BE    |0x31B3|0x31B3|
   |             |DM buf_len | N/A  | N/A  | 640  | 640  |   640    | 640  |   640    | 640  |   640    | 640  |     640      | 640  | 640  |
   +-------------+-----------+------+------+------+------+----------+------+----------+------+----------+------+--------------+------+------+

   Audio PCM readback:
   +-------------+------+------+------+------+------+------+------+------+--------+
   |             |MT6218|MT6217|MT6219|MT6227|MT6228|MT6229|MT6225|MT6223| MT6223P|
   +-------------+------+------+------+------+------+------+------+------+--------+
   |SHERIF Addr  |  0   |  0   | 0x49 |0x29B |  0   |  2   |  0   |  1   |    1   |
   +-------------+------+------+------+------+------+------+------+---------------+

*/

#if defined(MT6217)
#define DSP_PCM_START      DSP_DM_ADDR
#define DSP_PCM_GET        IDMA_SHORT_ADDR
#define DSP_PCM_PAGE       0
#define DP_AUDIO_PCM_ADDR  DPRAM_base(0x49)
#define AMR_PCM_BUF_PAGE   0
#define AMR_PCM_BUF_ADDR   0x3C00
#define AMR_PCM_BUF_PTR    0x2D11
#define AMR_PCM_BUF_LEN    368

#elif defined(MT6219)
#define DSP_PCM_START      DSP_DM_ADDR
#define DSP_PCM_GET        IDMA_SHORT_ADDR
#define DSP_PCM_PAGE       0
#define DP_AUDIO_PCM_ADDR  DPRAM_base(0x49)
#define AMR_PCM_BUF_PAGE   0
#define AMR_PCM_BUF_ADDR   0x3C00
#define AMR_PCM_BUF_PTR    0x2D0F
#define AMR_PCM_BUF_LEN    368
#define AWB_PCM_BUF_PAGE   0
#define AWB_PCM_BUF_ADDR   0x28FA
#define AWB_PCM_BUF_PTR    0x3279
#define AWB_PCM_BUF_LEN    640

#elif defined(MT6226_S00) || defined(MT6226M_S00) || defined(MT6227_S00)
#define DSP_PCM_START      DSP_DM_ADDR
#define DSP_PCM_GET        IDMA_SHORT_ADDR
#define DSP_PCM_PAGE       0
#define DP_AUDIO_PCM_ADDR  DPRAM_base(0x49)
#define AMR_PCM_BUF_PAGE   0
#define AMR_PCM_BUF_ADDR   0x3C00
#define AMR_PCM_BUF_PTR    0x2D11
#define AMR_PCM_BUF_LEN    368
#define AWB_PCM_BUF_PAGE   0
#define AWB_PCM_BUF_ADDR   0x2398
#define AWB_PCM_BUF_PTR    0x3288
#define AWB_PCM_BUF_LEN    640

#elif defined(MT6226_S01) || defined(MT6226M_S01) || defined(MT6227_S01) || defined(MT6226_S02) || defined(MT6226M_S02) || defined(MT6227_S02)
#define DSP_PCM_START      DSP_DM_ADDR
#define DSP_PCM_GET        IDMA_SHORT_ADDR
#define DSP_PCM_PAGE       0
#define DP_AUDIO_PCM_ADDR  DPRAM_base(0x49)
#define AMR_PCM_BUF_PAGE   0
#define AMR_PCM_BUF_ADDR   0x3C00
#define AMR_PCM_BUF_PTR    0x302E
#define AMR_PCM_BUF_LEN    368
#define AWB_PCM_BUF_PAGE   0
#define AWB_PCM_BUF_ADDR   0x2378
#define AWB_PCM_BUF_PTR    0x3295
#define AWB_PCM_BUF_LEN    640

#elif defined(MT6227D) || defined(MT6226D)
#define DSP_PCM_START      DSP_DM_ADDR
#define DSP_PCM_GET        IDMA_SHORT_ADDR
#define DSP_PCM_PAGE       0
#define DP_AUDIO_PCM_ADDR  DPRAM_base(0x49)
#define AMR_PCM_BUF_PAGE   0
#define AMR_PCM_BUF_ADDR   0x3C00
#define AMR_PCM_BUF_PTR    0x303D
#define AMR_PCM_BUF_LEN    368
#define AWB_PCM_BUF_PAGE   0
#define AWB_PCM_BUF_ADDR   0x2378
#define AWB_PCM_BUF_PTR    0x3295
#define AWB_PCM_BUF_LEN    640

#elif defined(MT6228)
#define DSP_PCM_START      DSP_DM_ADDR
#define DSP_PCM_GET        IDMA_SHORT_ADDR
#define DSP_PCM_PAGE       0
#define DP_AUDIO_PCM_ADDR  DPRAM_base(0x2BA)
#define AMR_PCM_BUF_PAGE   0
#define AMR_PCM_BUF_ADDR   0x3C00
#define AMR_PCM_BUF_PTR    0x322D
#define AMR_PCM_BUF_LEN    320
#define AWB_PCM_BUF_PAGE   0
#define AWB_PCM_BUF_ADDR   0x25F4
#define AWB_PCM_BUF_PTR    0x352C
#define AWB_PCM_BUF_LEN    640

#elif defined(MT6229_S00) || defined(MT6230_S00)
#define DSP_PCM_START      DSP2_DM_ADDR
#define DSP_PCM_GET        IDMA2_SHORT_ADDR
#define DSP_PCM_PAGE       2
#define DP_AUDIO_PCM_ADDR  DPRAM2_base(0x237)
#define AMR_PCM_BUF_PAGE   2
#define AMR_PCM_BUF_ADDR   0x3600
#define AMR_PCM_BUF_PTR    0x3912
#define AMR_PCM_BUF_LEN    320
#define AWB_PCM_BUF_PAGE   2
#define AWB_PCM_BUF_ADDR   0x1AF4
#define AWB_PCM_BUF_PTR    0x3172
#define AWB_PCM_BUF_LEN    640

#elif defined(MT6229_S01) || defined(MT6230_S01)
#define DSP_PCM_START      DSP2_DM_ADDR
#define DSP_PCM_GET        IDMA2_SHORT_ADDR
#define DSP_PCM_PAGE       2
#define DP_AUDIO_PCM_ADDR  DPRAM2_base(0x237)
#define AMR_PCM_BUF_PAGE   2
#define AMR_PCM_BUF_ADDR   0x3600
#define AMR_PCM_BUF_PTR    0x3927
#define AMR_PCM_BUF_LEN    320
#define AWB_PCM_BUF_PAGE   2
#define AWB_PCM_BUF_ADDR   0x1AF4
#define AWB_PCM_BUF_PTR    0x3172
#define AWB_PCM_BUF_LEN    640

#elif defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T)
#define DSP_PCM_START      DSP2_DM_ADDR
#define DSP_PCM_GET        IDMA2_SHORT_ADDR
#define DSP_PCM_PAGE       2
#define DP_AUDIO_PCM_ADDR  DPRAM2_base(0x237)
#define AMR_PCM_BUF_PAGE   2
#define AMR_PCM_BUF_ADDR   0x3600
#define AMR_PCM_BUF_PTR    0x3926
#define AMR_PCM_BUF_LEN    320
#define AWB_PCM_BUF_PAGE   2
#define AWB_PCM_BUF_ADDR   0x1AF4
#define AWB_PCM_BUF_PTR    0x3172
#define AWB_PCM_BUF_LEN    640

#elif defined(MT6235) || defined(MT6238)
#define DSP_PCM_START      DSP2_DM_ADDR
#define DSP_PCM_GET        IDMA2_SHORT_ADDR
#define DSP_PCM_PAGE       2
#define DP_AUDIO_PCM_ADDR  DPRAM2_base(0x237)
#define AMR_PCM_BUF_PAGE   2
#define AMR_PCM_BUF_ADDR   0x3600
#define AMR_PCM_BUF_PTR    0x3928
#define AMR_PCM_BUF_LEN    320
#define AWB_PCM_BUF_PAGE   2
#define AWB_PCM_BUF_ADDR   0x1AF4
#define AWB_PCM_BUF_PTR    0x31B3
#define AWB_PCM_BUF_LEN    640

#elif defined(MT6225)
#define DSP_PCM_START      DSP_DM_ADDR
#define DSP_PCM_GET        IDMA_SHORT_ADDR
#define DSP_PCM_PAGE       0
#define DP_AUDIO_PCM_ADDR  DPRAM_base(0x2BA)
#define AMR_PCM_BUF_PAGE   0
#define AMR_PCM_BUF_ADDR   0x3C00
#define AMR_PCM_BUF_PTR    0x2E30
#define AMR_PCM_BUF_LEN    320
#define AWB_PCM_BUF_PAGE   0
#define AWB_PCM_BUF_ADDR   0x1DF4
#define AWB_PCM_BUF_PTR    0x38EE
#define AWB_PCM_BUF_LEN    640

#elif defined(MT6223) || defined(MT6223P)
#define DSP_PCM_START      DSP2_DM_ADDR
#define DSP_PCM_GET        IDMA2_SHORT_ADDR
#define DSP_PCM_PAGE       1
#define DP_AUDIO_PCM_ADDR  0x30F0
#define AMR_PCM_BUF_PAGE   1
#define AMR_PCM_BUF_ADDR   0x3600
#define AMR_PCM_BUF_PTR    0x383F
#define AMR_PCM_BUF_LEN    320
#define AWB_PCM_BUF_PAGE   1
#define AWB_PCM_BUF_ADDR   0x1C00
#define AWB_PCM_BUF_PTR    0x30BE
#define AWB_PCM_BUF_LEN    640
#endif


#define DISPLAY_SEGMENTS      16
#define MAX_FFT_SIZE_BITS     9

#if defined(MT6228) || defined(MT6225 ) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
/*Support AudioPP Manager*/


typedef struct {
   int16    val[DISPLAY_SEGMENTS];
   int16    top[DISPLAY_SEGMENTS];
   int16    out[DISPLAY_SEGMENTS];
   int16    *fft_real;
   int16    *fft_imag;
   int16    *fft_buf1;
   int16    *fft_buf2;
   uint16   counter;
   uint16   fft_size;
   uint16   fft_size_bits;
   uint16   lp_factor;
   uint16   count_duration;
   uint32   sampleRate;
   bool     isStereo;
   bool     bFirstProcess;            //true:process is  first time be called
} SPT_Type;

#define SPT_IDLE  1
#define SPT_READY 2

APM_Info   spt_apm_info={false, false, false, 8000};
uint16     spt_state = SPT_IDLE;

#else

typedef struct {
   int16    val[DISPLAY_SEGMENTS];
   int16    top[DISPLAY_SEGMENTS];
   int16    out[DISPLAY_SEGMENTS];
   int16    *fft_real;
   int16    *fft_imag;
   int16    *fft_buf1;
   int16    *fft_buf2;
   uint16   aud_id;
   uint16   counter;
   uint16   magic_no;
   uint16   fft_size;
   uint16   fft_size_bits;
   uint16   lp_factor;
   uint16   count_duration;
   uint16   awb_flag;
   uint16   dsp_fs;
} SPT_Type;

#endif

SPT_Type *spt_disp = (SPT_Type *)0;
int16 my_cos( int32 idx );
void my_fft( int16 *real, int16 *imag, int fft_size_bits );

#define step(shift) \
   if((0x40000000l >> shift) + root <= value) {        \
      value -= (0x40000000l >> shift) + root;          \
      root = (root >> 1) | (0x40000000l >> shift);     \
   }                                                   \
   else {                                              \
      root = root >> 1;                                \
   }

static int my_sqrt( int value )
{
   int root = 0;

   step( 0);
   step( 2);
   step( 4);
   step( 6);
   step( 8);
   step(10);
   step(12);
   step(14);
   step(16);
   step(18);
   step(20);
   step(22);
   step(24);
   step(26);
   step(28);
   step(30);

   // round to the nearest integer, cuts max error in half
   if(root < value)
      ++root;

   return root;
}

/*
 * Hamming Window Equation
 *
 * w(k+1) = 0.54 - 0.46*cos(2pi * k / (n-1)) .......k = 0~(n-1)
 */
/*
int hamming( int index )
{
   return 17694 - (15073 * my_cos( 0x10000 * index / (MY_FFT_SIZE-1)) >> 15);
}
*/


int my_log2(const unsigned int number, const unsigned int number_mantissa_size, const unsigned int log_mantissa_size)
{
	// cpower is chosen so that ((2^(cpower+1))-1)^2 will fit in an unsigned int
	unsigned int cpower = ((sizeof(unsigned int)*8)/2)-1;
	unsigned int one = 1 << cpower;
	unsigned int two = 2 << cpower;
   int l;
	unsigned int n;
   unsigned int mantissa_bit;

	// zero will mess up the algorithm below
	if ( number == 0 )
      return 0;

	l = cpower - number_mantissa_size; // number is actually number/(2^number_mantissa_size), so number_mantissa_size is subtracted from the log (it is done at the beginning to circumvent having to shift number_mantissa_size)
	n = number;

	// make sure one <= n < two (and administrer any shifts in l, l becomes floor(log(number)))
	while(n < one)
	{
		n <<= 1;
		--l;
	}
	while(n >= two)
	{
		n >>= 1;
		++l;
	}

	// now calculate some binary digits
	for( mantissa_bit = 0; mantissa_bit < log_mantissa_size; ++mantissa_bit)
	{
		l <<= 1u;		// make room for an extra bit (shifting a negative signed integer works perfectly!)
		n *= n;			// n_new = n_old^2 = (2^0.yxxx)^2 = 2^y.xxx
		n >>= cpower;	// normalize n to keep n from getting too large
		if ( n >= two )
		{	// apparently y (see the comment behind n *= n) was 1
			l |= 1;	// set the LSB to 1
			n >>= 1;	// divide by two, subtracting 1 from 1.xxx (n/2 = (2^-1)(2^1.xxx) = 2^0.xxx) to prepare for the next step
		}
	}

	return l;
}

/*
 * Bit reverse the number
 *
 * Change 11100000b to 00000111b or vice-versa
 */
static int permute( int index, int fft_size_bits )
{
   int   n1, result, loop;

   n1 = 1 << fft_size_bits;
   result = 0;

   for (loop = 0; loop < fft_size_bits; loop++)  {
      n1 >>= 1;         /* n1 / 2.0 */
      if (index < n1)
         continue;

      result += (1 << loop);
      index -= n1;
   }

   return result;
}

/*
 * Calculate Power Magnitude
 */
static int magnitude( int n, int16 *real, int16 *imag, int fft_size_bits )
{
   n = permute( n, fft_size_bits );
   return (my_sqrt(real[n] * real[n] + imag[n] * imag[n]));
}


static void segmentation( int16 *real, int16 *imag, int fft_size_bits, int16 *out )
{
   const static int16 seg128[DISPLAY_SEGMENTS] =
   { 2,3,4,5,6,7,8,9,12,16,20,24,40,56,72,127 };
   const static int16 seg256[DISPLAY_SEGMENTS] =
   { 2,3,4,5,6,7,8,9,13,17,21,25,41,55,120,255 };
   const int16 *ptr = seg128;
   int fft_size_div2 = 1 << (fft_size_bits-1);
   int I, J, mag, start_pos = 2;

   switch( fft_size_bits ) {
   case 8:  ptr = seg128;  start_pos = 2;    break;
   case 9:  ptr = seg256;  start_pos = 2;    break;
   }
   out[0] = 0;
   for( I = start_pos, J = 0; I < fft_size_div2; I++ ) {
      mag = magnitude(I, real, imag, fft_size_bits );
      mag = (my_log2( mag, 0, 6 ) - 400);
      if( mag > out[J] ) {
         out[J] = (int16)mag;
      }
      if( I == ptr[J] ) {
         J++;
         if( J == DISPLAY_SEGMENTS )
            break;
         else
            out[J] = 0;
      }
   }
}

#if defined( MT6228 ) || defined( MT6225 ) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)

static void spt_internal_reset()
{
   uint32 I, srIdx;
   static const uint16 SRTable[] =
   {8000,  11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000};
   static const uint16 CountDurTable[] = 
   //{800, 1102, 1200, 1600, 2205, 2400, 3200, 4410, 4800}; //100ms for each type of sample rate
   {680, 937, 1020, 1360, 1874, 2040, 2720, 3748, 4080}; //85ms for each type of sample rate

   for( I = 0; I < DISPLAY_SEGMENTS; I++ ) {
      spt_disp->val[I] = 0;
      spt_disp->top[I] = 0;
   }
   
   spt_disp->counter       = 0;
   spt_disp->fft_size      = 1 << 9;
   spt_disp->fft_size_bits = 9;
   
   spt_disp->isStereo   = spt_apm_info.isStereo;
   spt_disp->sampleRate = spt_apm_info.sampleFreq;
   spt_disp->bFirstProcess = true;
   
   kal_prompt_trace( MOD_L1SP, "SPT reset,SR=%d,St=%d",spt_disp->sampleRate,spt_disp->isStereo);
   
   for (I = 0 ; I < 9 ; I++){
      if ( SRTable[I] == spt_disp->sampleRate )
         break;
   }
   srIdx = I;
   ASSERT( srIdx != 9 );
   
   spt_disp->lp_factor = 2;
   spt_disp->count_duration = CountDurTable[srIdx];
}

/*================for AudioPP Manager member function===============*/

void spt_Activate(APM_Info *info)
{
   spt_apm_info.isStereo   = info->isStereo;
   spt_apm_info.sampleFreq = info->sampleFreq;
   
   if( spt_disp == (SPT_Type *)0 )
      return;
   else
      spt_internal_reset();
   spt_state = SPT_READY;
}

void spt_Deactivate(APM_Info *info)
{
   spt_state = SPT_IDLE;
   return;
}
kal_bool spt_Process(APM_Buffer *buf, APM_Info *info)
{
   uint32 I, len, procCnt=0;
   int16  *ptr1, *ptr2, *ptrIn;
   int32  out, top, val, max1, max2;
   uint32 lpf1_1, lpf1_2, lpf2_1, lpf2_2;               //for (val, top) update factor
   
   buf->outBufLen = buf->inBufLen;
   
   if( spt_state == SPT_IDLE )
      return false;
   if( spt_disp == (SPT_Type *)0 )
      return false;
   if( info->isChange ){
      spt_apm_info.sampleFreq = info->sampleFreq;
      spt_apm_info.isStereo   = info->isStereo;
      spt_internal_reset();
   }
   
   while( procCnt < buf->inBufLen ){
      if( spt_disp->counter < spt_disp->fft_size ){
         if(spt_disp->isStereo)
            len = (spt_disp->fft_size - spt_disp->counter)<<1;
         else
            len = (spt_disp->fft_size - spt_disp->counter);
         if ( (buf->inBufLen - procCnt) < len )
            len = (buf->inBufLen - procCnt);

         ptr1  = spt_disp->fft_buf1 + spt_disp->counter;
         ptr2  = spt_disp->fft_buf2 + spt_disp->counter;
         ptrIn = buf->inBuf + procCnt;
         procCnt += len;
         len = (spt_disp->isStereo)? len>>1 : len;
         for( I = 0 ; I <len ; I++){
            *ptr1++ = *ptrIn++;
            if (spt_disp->isStereo)
               *ptr2++ = *ptrIn++;
            else
               *ptr2++ = 0;
         }
         spt_disp->counter += len;
      }
      
      if( spt_disp->counter < spt_disp->count_duration ){
         if(spt_disp->isStereo)
            len = (spt_disp->count_duration - spt_disp->counter)<<1;
         else
            len = (spt_disp->count_duration - spt_disp->counter);
         
         if( (buf->inBufLen - procCnt) < len )
            len = buf->inBufLen - procCnt;
         procCnt += len;
         len = (spt_disp->isStereo)? len>>1 : len;
         spt_disp->counter += len;
      }
      
      /*   only when counter >= count_duration, do the actual SPT task */
      if( spt_disp->counter >= spt_disp->count_duration ) {
         ptr1 = spt_disp->fft_buf1;
         ptr2 = spt_disp->fft_buf2;
         max1 = max2 = 0;
         for( I = spt_disp->fft_size; I > 0; I-- ) {
            if( (int32)*ptr1 > max1 )
               max1 = (int32)*ptr1;
            else if( -(int32)*ptr1 > max1 )
               max1 = -(int32)*ptr1;
            if( (int32)*ptr2 > max2 )
               max2 = (int32)*ptr2;
            else if( -(int32)*ptr2 > max2 )
               max2 = -(int32)*ptr2;
            ptr1++;
            ptr2++;
         }
         if( max1 >= max2 ) {
            spt_disp->fft_real = spt_disp->fft_buf1;
            spt_disp->fft_imag = spt_disp->fft_buf2;
         }
         else {
            spt_disp->fft_real = spt_disp->fft_buf2;
            spt_disp->fft_imag = spt_disp->fft_buf1;
         }
   
         ptr1 = spt_disp->fft_imag;
         for( I = spt_disp->fft_size; I > 0; I-- )
            *ptr1++ = 0;
   
         my_fft( spt_disp->fft_real, spt_disp->fft_imag, spt_disp->fft_size_bits );  
         segmentation( spt_disp->fft_real, spt_disp->fft_imag, spt_disp->fft_size_bits, spt_disp->out );
         lpf1_1 = spt_disp->lp_factor;
         lpf1_2 = (1<<lpf1_1) - 1;
         lpf2_1 = spt_disp->lp_factor + 3;
         lpf2_2 = (1<<lpf2_1) - 1;
         for( I = 0; I < DISPLAY_SEGMENTS; I++ ) {
            out = spt_disp->out[I];
            val = spt_disp->val[I];
            top = spt_disp->top[I];
            if( out >= val ) {
               val = out;
               if( out > top )
                  top = out;
               else
                  top = (top * lpf2_2 + out) >> lpf2_1;
            }
            else {
               val = (val * lpf1_2 + out) >> lpf1_1;
               top = (top * lpf2_2 + out) >> lpf2_1;
            }
            spt_disp->val[I] = (int16)val;
            spt_disp->top[I] = (int16)top;
         }
   
         spt_disp->counter = 0;
      }
   }
   return true;
}

/*================end AudioPP Manager member function===============*/
#else //else of #if defined( MT6228 ) || defined( MT6225 ) || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION

void SPT_Task( void *data )
{
   int32 I, out, top, val, max1, max2;
   int16 *ptr1, *ptr2;
   uint32 lpf1_1, lpf1_2, lpf2_1, lpf2_2;

   if( spt_disp == (SPT_Type *)0 )
      return;
      
   ptr1 = spt_disp->fft_buf1;
   ptr2 = spt_disp->fft_buf2;
   max1 = max2 = 0;
   for( I = spt_disp->fft_size; I > 0; I-- ) {
      if( (int32)*ptr1 > max1 )
         max1 = (int32)*ptr1;
      else if( -(int32)*ptr1 > max1 )
         max1 = -(int32)*ptr1;
      if( (int32)*ptr2 > max2 )
         max2 = (int32)*ptr2;
      else if( -(int32)*ptr2 > max2 )
         max2 = -(int32)*ptr2;
      ptr1++;
      ptr2++;
   }
   if( max1 >= max2 ) {
      spt_disp->fft_real = spt_disp->fft_buf1;
      spt_disp->fft_imag = spt_disp->fft_buf2;
   }
   else {
      spt_disp->fft_real = spt_disp->fft_buf2;
      spt_disp->fft_imag = spt_disp->fft_buf1;
   }

   ptr1 = spt_disp->fft_imag;
   for( I = spt_disp->fft_size; I > 0; I-- )
      *ptr1++ = 0;

   my_fft( spt_disp->fft_real, spt_disp->fft_imag, spt_disp->fft_size_bits );
   segmentation( spt_disp->fft_real, spt_disp->fft_imag, spt_disp->fft_size_bits, spt_disp->out );
   lpf1_1 = spt_disp->lp_factor;
   lpf1_2 = (1<<lpf1_1) - 1;
   lpf2_1 = spt_disp->lp_factor + 3;
   lpf2_2 = (1<<lpf2_1) - 1;
   for( I = 0; I < DISPLAY_SEGMENTS; I++ ) {
      out = spt_disp->out[I];
      val = spt_disp->val[I];
      top = spt_disp->top[I];
      if( out >= val ) {
         val = out;
         if( out > top )
            top = out;
         else
            top = (top *lpf2_2 + out) >> lpf2_1;
      }
      else {
         val = (val*lpf1_2 + out) >> lpf1_1;
         top = (top *lpf2_2 + out) >> lpf2_1;
      }
      spt_disp->val[I] = (int16)val;
      spt_disp->top[I] = (int16)top;
   }

   kal_prompt_trace( MOD_L1SP, "SPT_Task" );
   spt_disp->counter = 0;
}
#if AMR_AWB_AUDIO_PATH_SUPPORT
/*AMR/AWB from audio path, after 622x sereis. But 6228/6225/6229 will be in APM path*/
static void AMR_ReadbackPcmData( uint32 counter )
{
   int32 I;
   uint16 ptr_addr, temp;
   int16 *ptr1, *ptr2;

   ASSERT( counter > 0 && counter <= spt_disp->count_duration );
   I = *DSP_PCM_START( DSP_PCM_PAGE, *DP_AUDIO_PCM_ADDR );
   ptr1 = spt_disp->fft_buf1 + (counter-1) * 160;
   ptr2 = spt_disp->fft_buf2 + (counter-1) * 160;
   if( counter < spt_disp->count_duration ) {
      for( I = 160; I > 0; I-- ) {
         *ptr1++ = *DSP_PCM_GET;   /* left channel  */
         *ptr2++ = *DSP_PCM_GET;   /* right channel */
      }
   }
   else {
      for( I = spt_disp->fft_size - (counter-1) * 160; I > 0; I-- ) {
         *ptr1++ = *DSP_PCM_GET;   /* left channel  */
         *ptr2++ = *DSP_PCM_GET;   /* right channel */
      }
   }
}

#if defined(AMRWB_DECODE)
static void AWB_ReadbackPcmData( uint32 counter )
{
   int32 I;
   uint16 ptr_addr, temp;
   int16 *ptr1, *ptr2;

   ASSERT( counter > 0 && counter <= spt_disp->count_duration );
   I = *DSP_PCM_START( DSP_PCM_PAGE, *DP_AUDIO_PCM_ADDR );
   ptr1 = spt_disp->fft_buf1 + (counter-1) * 320;
   ptr2 = spt_disp->fft_buf2 + (counter-1) * 320;
   if( counter < spt_disp->count_duration ) {
      for( I = 320; I > 0; I-- ) {
         *ptr1++ = *DSP_PCM_GET;   /* left channel  */
         *ptr2++ = *DSP_PCM_GET;   /* right channel */
      }
   }
   else {
      for( I = spt_disp->fft_size - (counter-1) * 320; I > 0; I-- ) {
         *ptr1++ = *DSP_PCM_GET;   /* left channel  */
         *ptr2++ = *DSP_PCM_GET;   /* right channel */
      }
   }
}
#endif /* AMRWB_DECODE */

#else  //AMR_AWB_AUDIO_PATH_SUPPORT

static void AMR_ReadbackPcmData( uint32 counter )
{
   int32 I;
   uint16 ptr_addr, temp;
   int16 *ptr;

   ASSERT( counter > 0 && counter <= spt_disp->count_duration );
   ptr_addr = *DSP_PCM_START( AMR_PCM_BUF_PAGE, AMR_PCM_BUF_PTR );     /* trigger the IDMA read operation */
   ptr_addr = *DSP_PCM_GET;                                      /* get the required data */
   ASSERT( ptr_addr >= AMR_PCM_BUF_ADDR && ptr_addr < (AMR_PCM_BUF_ADDR + AMR_PCM_BUF_LEN) );
   temp = *DSP_PCM_START( AMR_PCM_BUF_PAGE, ptr_addr );                /* trigger the IDMA read operation */
   ptr = spt_disp->fft_buf1 + (counter-1) * 160;
   if( counter < spt_disp->count_duration ) {
      for( I = 160; I > 0; I-- ) {
         *ptr++ = *DSP_PCM_GET;
         if( (++ptr_addr) == (AMR_PCM_BUF_ADDR + AMR_PCM_BUF_LEN) ) {
            ptr_addr = AMR_PCM_BUF_ADDR;
            temp = *DSP_PCM_START( AMR_PCM_BUF_PAGE, ptr_addr );       /* trigger the IDMA read operation */
         }
      }
   }
   else {
      for( I = spt_disp->fft_size - (counter-1) * 160; I > 0; I-- ) {
         *ptr++ = *DSP_PCM_GET;
         if( (++ptr_addr) == (AMR_PCM_BUF_ADDR + AMR_PCM_BUF_LEN) ) {
            ptr_addr = AMR_PCM_BUF_ADDR;
            temp = *DSP_PCM_START( AMR_PCM_BUF_PAGE, ptr_addr );       /* trigger the IDMA read operation */
         }
      }
      ptr = spt_disp->fft_buf2;
      for( I = spt_disp->fft_size; I > 0; I-- )
         *ptr++ = 0;
   }
}

#if defined(AMRWB_DECODE)
static void AWB_ReadbackPcmData( uint32 counter )
{
   int32 I;
   uint16 ptr_addr, temp;
   int16 *ptr;

   ASSERT( counter > 0 && counter <= spt_disp->count_duration );
   ptr_addr = *DSP_PCM_START( AWB_PCM_BUF_PAGE, AWB_PCM_BUF_PTR );     /* trigger the IDMA read operation */
   ptr_addr = *DSP_PCM_GET;                                      /* get the required data */
   ASSERT( ptr_addr >= AWB_PCM_BUF_ADDR && ptr_addr < (AWB_PCM_BUF_ADDR + AWB_PCM_BUF_LEN) );
   temp = *DSP_PCM_START( AWB_PCM_BUF_PAGE, ptr_addr );                /* trigger the IDMA read operation */
   ptr = spt_disp->fft_buf1 + (counter-1) * 320;
   if( counter < spt_disp->count_duration ) {
      for( I = 320; I > 0; I-- ) {
         *ptr++ = *DSP_PCM_GET;
         if( (++ptr_addr) == (AWB_PCM_BUF_ADDR + AWB_PCM_BUF_LEN) ) {
            ptr_addr = AWB_PCM_BUF_ADDR;
            temp = *DSP_PCM_START( AWB_PCM_BUF_PAGE, ptr_addr );       /* trigger the IDMA read operation */
         }
      }
   }
   else {
      for( I = spt_disp->fft_size - (counter-1) * 320; I > 0; I-- ) {
         *ptr++ = *DSP_PCM_GET;
         if( (++ptr_addr) == (AWB_PCM_BUF_ADDR + AWB_PCM_BUF_LEN) ) {
            ptr_addr = AWB_PCM_BUF_ADDR;
            temp = *DSP_PCM_START( AWB_PCM_BUF_PAGE, ptr_addr );       /* trigger the IDMA read operation */
         }
      }
      ptr = spt_disp->fft_buf2;
      for( I = spt_disp->fft_size; I > 0; I-- )
         *ptr++ = 0;
   }
}
#endif /* AMRWB_DECODE */

#endif//end of #if AMR_AWB_AUDIO_PATH_SUPPORT

void SPT_PutPcmData( const int16 *pcm, int32 len, bool mono )    /* this functions runs in WAV/AIFF HISR */
{
   int16 *ptr1, *ptr2;
   int I;

   if( spt_disp == (SPT_Type *)0 )  /* spectrum display not enabled */
      return;

   if( spt_disp->magic_no != DP_D2C_PCM_P ) {   /* The first time get in */
      spt_disp->lp_factor = 2;
      spt_disp->fft_size_bits = 9;
      spt_disp->fft_size = 1 << 9;
      spt_disp->count_duration = (1 << 9) * 6;
      spt_disp->counter = 0;              /* reset the counter */
      spt_disp->magic_no = DP_D2C_PCM_P;
   }
   if( spt_disp->counter >= spt_disp->count_duration )
      return;
   if( !mono )    /* if stereo */
      len >>= 1;
   if( spt_disp->counter < spt_disp->fft_size ) {
      ptr1 = spt_disp->fft_buf1 + spt_disp->counter;
      ptr2 = spt_disp->fft_buf2 + spt_disp->counter;

      I = ( len > spt_disp->fft_size - spt_disp->counter )? spt_disp->fft_size - spt_disp->counter : len;
      for( ; I > 0; I-- ) {
         *ptr1++ = *pcm++;
         if( mono )
            *ptr2++ = 0;
         else
            *ptr2++ = *pcm++;
      }
   }
   spt_disp->counter += len;
   if( spt_disp->counter >= spt_disp->count_duration )
      L1Audio_SetEvent( spt_disp->aud_id, 0 );
}

static void SPT_PostHisr( void *data )
{
   int32 I, amr_change = 0;
   int16 *ptr1, *ptr2;
   uint16 dsp_fs;

   if( spt_disp == (SPT_Type *)0 )
      return;

   if( (uint32)data == DP_D2C_PCM_P ||   /* For PCM, use SPT_PutPcmData() */
       (uint32)data == D2C_MAGIC_NO_SBC )   /* Ignore SBC interrupt */
      return;
   if( (uint32)data == DP_D2C_SD_DONE ) {
      if( (*DP_SC_MODE & 0xFF) >= 0x20 ) {   /* AMR-WB */
         if( spt_disp->awb_flag == 0 ) {     /* AMR */
            amr_change = 1;
            spt_disp->awb_flag = 1;
         }
      }
      else {                                 /* AMR */
         if( spt_disp->awb_flag ) {     /* AMR-WB */
            amr_change = 1;
            spt_disp->awb_flag = 0;
         }
      }
   }

   dsp_fs = *DP_ASP_FS;
   if( (uint32)data != spt_disp->magic_no || spt_disp->dsp_fs != dsp_fs || amr_change ) {   /* the first time to enable PostHisr */
      switch( (uint32)data ) {
         case DP_D2C_DAF:
            spt_disp->count_duration = (dsp_fs == 0x40 || dsp_fs == 0x41 || dsp_fs == 0x42 || dsp_fs == 0x21 || dsp_fs == 0x22)? 2:1;
            spt_disp->lp_factor = (dsp_fs == 0x00)? 1:2;
            spt_disp->fft_size_bits = 9;
            spt_disp->fft_size = 1 << 9;
            break;
         case DP_D2C_WT:
            spt_disp->count_duration = 2;
            spt_disp->lp_factor = 3;
            spt_disp->fft_size_bits = 9;
            spt_disp->fft_size = 1 << 9;
            break;
         case DP_D2C_AAC:
            spt_disp->count_duration = (dsp_fs == 0x40 || dsp_fs == 0x41 || dsp_fs == 0x42)? 2:1;
            spt_disp->lp_factor = 2;
            spt_disp->fft_size_bits = 9;
            spt_disp->fft_size = 1 << 9;
            break;
         case DP_D2C_WMA:
            spt_disp->count_duration = 1;
            spt_disp->lp_factor = (dsp_fs == 0x00 || dsp_fs == 0x11 || dsp_fs == 0x12)? 1:2;
            spt_disp->fft_size_bits = 9;
            spt_disp->fft_size = 1 << 9;
            break;
         case DP_D2C_SD_DONE:
            spt_disp->count_duration = (spt_disp->awb_flag)? 2 : 4;
            spt_disp->lp_factor = 2;
            spt_disp->fft_size_bits = 9;
            spt_disp->fft_size = 1 << 9;
            break;
         default:
            if( spt_disp->fft_size_bits == 0 )  /* currently playing un-supported media format */
               return;
            for( I = 0; I < DISPLAY_SEGMENTS; I++ ) {
               spt_disp->val[I] = 0;
               spt_disp->top[I] = 0;
            }
            spt_disp->fft_size_bits = 0;
            return;
            break;
      }
      kal_prompt_trace( MOD_L1SP, "SPT D%d F%d T%d", spt_disp->count_duration, dsp_fs, (uint32)data);
      spt_disp->counter = 0;     /* reset the counter */
      spt_disp->dsp_fs = dsp_fs;
      spt_disp->magic_no = (uint32)data;
   }

   if( spt_disp->counter >= spt_disp->count_duration )
      return;
   spt_disp->counter++;

   if( spt_disp->magic_no == DP_D2C_SD_DONE ) { /* for playing AMR/AWB */
#if defined(AMRWB_DECODE)
      if( spt_disp->awb_flag )
         AWB_ReadbackPcmData( spt_disp->counter );
      else
#endif /* AMRWB_DECODE */
         AMR_ReadbackPcmData( spt_disp->counter );
      if( spt_disp->counter == spt_disp->count_duration )
         L1Audio_SetEvent( spt_disp->aud_id, 0 );
      return;
   }

   if( spt_disp->counter < spt_disp->count_duration )
      return;

   ptr1 = spt_disp->fft_buf1;
   ptr2 = spt_disp->fft_buf2;
#if defined(MT6223) || defined(MT6223P) // special case for MT6223
   {
      uint16 addr;
      addr = *DSP_PCM_START( DSP_PCM_PAGE, DP_AUDIO_PCM_ADDR );
      if( (uint32)data == DP_D2C_DAF ){
         if( addr == 0x1380 )
            addr = 0xF00;
         else if(addr == 0xF00)
            addr = 0x1380;
         else ASSERT("Spt addr is not correct");
      }
      I = *DSP_PCM_START( DSP_PCM_PAGE, addr );
   }
#else
   I = *DSP_PCM_START( DSP_PCM_PAGE, *DP_AUDIO_PCM_ADDR );
#endif
   for( I = spt_disp->fft_size; I > 0; I-- ) {
      *ptr1++ = (int32)(int16)*DSP_PCM_GET;    /* left channel */
      *ptr2++ = (int32)(int16)*DSP_PCM_GET;    /* right channel */
   }
   L1Audio_SetEvent( spt_disp->aud_id, 0 );
}

#endif // endif of #if defined( MT6228 ) || defined( MT6225 ) || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
void SPT_Open( void )
{
#if defined( MT6228 ) || defined( MT6225 ) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)

   SPT_Type *spt;
   spt = (SPT_Type *)get_ctrl_buffer( sizeof(SPT_Type) );
   spt->fft_buf1 = (int16*)get_ctrl_buffer( (1<<MAX_FFT_SIZE_BITS)*sizeof(int16) );
   spt->fft_buf2 = (int16*)get_ctrl_buffer( (1<<MAX_FFT_SIZE_BITS)*sizeof(int16) );
   spt_disp = spt;
   spt_internal_reset();
   HOST_APM_Register(APM_TASKID_SPT);
#else

   int I;
   SPT_Type *spt;
   spt = (SPT_Type *)get_ctrl_buffer( sizeof(SPT_Type) );
   spt->fft_buf1 = (int16*)get_ctrl_buffer( (1<<MAX_FFT_SIZE_BITS)*sizeof(int16) );
   spt->fft_buf2 = (int16*)get_ctrl_buffer( (1<<MAX_FFT_SIZE_BITS)*sizeof(int16) );
   spt->counter = 0;
   spt->magic_no = 0;
   spt->awb_flag = 0;
   spt->aud_id = L1Audio_GetAudioID();
   spt->dsp_fs = 0;
   L1Audio_SetEventHandler( spt->aud_id, SPT_Task );

   for( I = 0; I < DISPLAY_SEGMENTS; I++ ) {
      spt->val[I] = 0;
      spt->top[I] = 0;
   }
   spt_disp = spt;
   L1Audio_SetPostHisrHandler( SPT_PostHisr );
   
   kal_prompt_trace( MOD_L1SP, "SPT_Open");
#endif
}

void SPT_Close( void )
{
#if defined( MT6228 ) || defined( MT6225 ) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   HOST_APM_UnRegister(APM_TASKID_SPT);   
   spt_state = SPT_IDLE;
   free_ctrl_buffer( spt_disp->fft_buf1 );
   free_ctrl_buffer( spt_disp->fft_buf2 );
   free_ctrl_buffer( spt_disp );
   spt_disp = (SPT_Type *)0;
   
#else

   L1Audio_ResetPostHisrHandler();
   L1Audio_FreeAudioID( spt_disp->aud_id );
   free_ctrl_buffer( spt_disp->fft_buf1 );
   free_ctrl_buffer( spt_disp->fft_buf2 );
   free_ctrl_buffer( spt_disp );
   spt_disp = (SPT_Type *)0;
   
#endif
}

void SPT_GetSpectrum( uint8 top[16], uint8 val[16] )
{
#if 0
   int32 I;
   ASSERT( spt_disp != (SPT_Type *)0 );
   for( I = 0; I < DISPLAY_SEGMENTS; I++ ) {
      val[I] = (uint8)((spt_disp->val[I] > 255)? 255:spt_disp->val[I]);
      top[I] = (uint8)((spt_disp->top[I] > 255)? 255:spt_disp->top[I]);
   }
   #else
   int32 I;
   if ( spt_disp != (SPT_Type *)0 )
   {
   	for( I = 0; I < DISPLAY_SEGMENTS; I++ ) 
	{
	      val[I] = (uint8)((spt_disp->val[I] > 255)? 255:spt_disp->val[I]);
	      top[I] = (uint8)((spt_disp->top[I] > 255)? 255:spt_disp->top[I]);
	}
   }
   else
   {
   	for( I = 0; I < DISPLAY_SEGMENTS; I++ ) 
	{
	      val[I] = 1;
	      top[I] = 1;
	}
   }
   #endif
}

#endif   /* IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION */
