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
 * tonedect.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 * supply tone detection function
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "l1Audio_def.h"
#include "tonedect.h"

#define CON_PAUSE_NUMBER      2
#define FRACTION_THRESHOLD    5  //magnitude threshold of a successful fraction frame

int16 my_cos( int32 idx );
int my_log2(const unsigned int number, const unsigned int number_mantissa_size, const unsigned int log_mantissa_size);

/* Call this routine before every "block" (size=N) of samples. */
void TD_Reset( TD_Handle *hdl )
{
   hdl->Q2 = 0;
   hdl->Q1 = 0;
}

/* Call this once, to precompute the constants. */
void TD_Init( TD_Handle *hdl, int32 target_freq, int32 block_size )
{
   hdl->coeff = my_cos(0x10000 * target_freq / SAMPLING_RATE );
   TD_Reset( hdl );
}

/* Call this routine for every sample. */
void TD_ProcessSample( TD_Handle *hdl, int16 sample )
{
   int32 Q0;

   Q0 = (hdl->Q1 * hdl->coeff >> 14) - hdl->Q2 + (sample>>6);
   hdl->Q2 = hdl->Q1;
   hdl->Q1 = Q0;
}

/* Call this routine for every block. */
void TD_ProcessBlock( TD_Handle *hdl, int16 *buf, int32 len )
{
   int32 Q0, Q1, Q2, coeff;
   Q1 = hdl->Q1;
   Q2 = hdl->Q2;
   coeff = hdl->coeff;

   for( ; len > 0; len--, buf++ ) {
      Q0 = (Q1 * coeff >> 14) - Q2 + (*buf>>6);
      Q2 = Q1;
      Q1 = Q0;
   }
   hdl->Q1 = Q1;
   hdl->Q2 = Q2;
}

/* Optimized Goertzel */
/* Call this after every block to get the RELATIVE magnitude squared. */
static int32 TD_GetMagnitudeSquared( TD_Handle *hdl )
{
   int32 Q1 = hdl->Q1;
   int32 Q2 = hdl->Q2;
   Q1 >>= 4;
   Q2 >>= 4;
   return Q1 * Q1 + Q2 * Q2 - Q1 * (Q2 * hdl->coeff>>14);
}

int32 TD_GetMagnitudeDB( TD_Handle *hdl )
{
   /* dB = 20 * log(x) = 10 * log(2) * log2(x^2) = 3.0103 * log2(x^2) 
      ~= 1024 / 340 * log2(x^2)
   */
   return my_log2( TD_GetMagnitudeSquared( hdl ), 0, 10 ) / 340;
}

/* --------------------------------------------------------------------------------*/

/* --------------------------------------------------------------------------------
    DTMF - Coding Frequencies Digit to be Encoded Low Frequency Values (Hz) 
    Digit to be Encoded 
    1       2        3     A     697 
    4       5        6     B     770 
    7       8        9     C     852 
    *       0        #     D     941 
    1209   1336     1477   1633  
   --------------------------------------------------------------------------------*/

const static int16 DTMF_Freq[8] = { 697, 770, 852, 941, 1209, 1336, 1477, 1633 };
const static int16 dtmfFreqTable[4][4] = {
   { '1', '4', '7', '*' },
   { '2', '5', '8', '0' },
   { '3', '6', '9', '#' },
   { 'A', 'B', 'C', 'D' }
};
signed char noise_threshold[] = {
   16,16,16,16,16,16,16,16,16,16,
   16,16,16,16,16,16,16,16,16,16,
   16,16,16,16,15,13,12,12,12,11,
   11,11,11,11,11,10,10,10, 9, 9,
    7, 6, 5, 5, 4, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
};


static void dtmfAnalyzeFreq( DTMF_Handle *hdl, int32 *magtab )
{
   int I, mag, max1, max2, max3, f1, f2;
   int maxLowGroup, maxHighGroup;//max magnitude of Low group ,max magnitude of High group
   int idx1, idx2, idx3;

   max1 = max2 = max3 = f1 = f2 = 0;
   idx1 = idx2 = idx3 = 0;
   for( I = 0; I < 8; I++ ) {
      mag = magtab[I];
      if( mag > max1 ) {   
         max3 = max2;   max2 = max1;   max1 = mag;
         idx3 = idx2;   idx2 = idx1;   idx1 = I;
         f2 = f1;       f1 = I;
      }
      else if( mag > max2 ) { 
         max3 = max2;   max2 = mag;    
         idx3 = idx2;   idx2 = I;
         f2 = I;
      }
      else if( mag > max3 ) { 
         max3 = mag;    idx3 = I;
      }
   }
   maxLowGroup = max1;
   maxHighGroup = max2;

   if( f1 > f2 ) {      /* swap the frequency index */
      I = f1;
      f1 = f2;
      f2 = I;
      maxLowGroup = max2;
      maxHighGroup = max1;
   }
   
   //kal_prompt_trace(MOD_L1SP, " s1(%d)=%2d, s2(%d)=%2d, n(%d)=%2d, (s-n)=%2d\n", idx1, max1, idx2, max2, idx3, max3, max2-max3);
   
   /*non-key or over twist constraint */
   if( f2 < 4 || f1 > 3 || (maxLowGroup-maxHighGroup) > 9 || (maxLowGroup-maxHighGroup) < -9 ) {
      hdl->pauseCount++;
      if ( hdl->pauseCount >= CON_PAUSE_NUMBER ){
         if ( hdl->key_temp > 0 )         /*pause detected, output key in this frame*/
            hdl->key = hdl->key_temp;
         hdl->key_temp = 0;
         hdl->pauseCount = 0;
      }
      hdl->key_pre_second = hdl->key_pre;            /*update second previous key*/
      hdl->key_pre = 0;                              /*update previous key*/
   }
   /*magnitude difference between FRACTION_THRESHOLD and nosie_threshold*/
   else if ( (max2 - max3) >= FRACTION_THRESHOLD && (max2 - max3) < noise_threshold[max3]){
      f2 -= 4;
      max1 = (int32)dtmfFreqTable[f2][f1];
      if ( hdl->key_pre == hdl->key_pre_second && hdl->key_pre > 0 && hdl->key_pre == max1 )
         hdl->key_temp = max1;
      
      hdl->key_pre_second = hdl->key_pre;            /*update second previous key*/
      hdl->key_pre = -max1;                           /*update previous key*/
   }
   /*magnitude difference larger than noise threshold*/
   else if ( (max2 - max3) >= noise_threshold[max3] ){
      f2 -= 4;
      max1 = (int32)dtmfFreqTable[f2][f1];
      if ( hdl->key_pre == max1 && ( hdl->key_pre == -hdl->key_pre_second || hdl->key_pre == hdl->key_pre_second ) )
         hdl->key_temp = max1;
      hdl->key_pre_second = hdl->key_pre;            /*update second previous key*/
      hdl->key_pre = max1;                            /*update previous key*/
      hdl->pauseCount = 0;
      hdl->key_threshold = max2 - max3;
   }
   /*smaller than noise_threshold and FRACTION_THRESHOLD*/
   else{
      hdl->pauseCount++;
      if ( hdl->pauseCount >= CON_PAUSE_NUMBER ){    /*pause detected, output key in this frame*/
         if ( hdl->key_temp > 0 )                    
            hdl->key = hdl->key_temp;
         hdl->key_temp = 0;
         hdl->pauseCount = 0;
      }
      hdl->key_pre_second = hdl->key_pre;            /*update second previous key*/
      hdl->key_pre = 0;                              /*update previous key*/
   }
}

static int16 dtmfGetKey( DTMF_Handle *hdl )
{
   int16 val;

   val = hdl->key;
   if( val <= 0 )
      return 0;   
   hdl->key = - hdl->key;
   return val;
}

static int32 dtmfPutData( DTMF_Handle *hdl, int16 *buf ,int32 len )
{
   int32 I, comsumedLen;
   if ( len + hdl->acum_buf_size >= hdl->block_size ){
      comsumedLen = hdl->block_size - hdl->acum_buf_size;
   }
   else{
      comsumedLen = len;
   }
   for( I = 0; I < 8; I++ )
      TD_ProcessBlock( &hdl->hdl[I], buf, comsumedLen );
   if( hdl->block_no > 1 ) {
      for( I = 0; I < 8; I++ )
         TD_ProcessBlock( &hdl->hdl2[I], buf, comsumedLen );
   }
      
   hdl->acum_buf_size += comsumedLen;
   if ( hdl->acum_buf_size < hdl->block_size )
      return comsumedLen;
   hdl->acum_buf_size = 0;

   hdl->block_count--;
   if( hdl->block_count == 0 ) {
      //printf("Test1 ");
      for( I = 0; I < 8; I++ ) {
         hdl->mag[I] = TD_GetMagnitudeDB( &hdl->hdl[I] );
         TD_Reset( &hdl->hdl[I] );
         //printf( "%2d ", hdl->mag[I] );
      }
      dtmfAnalyzeFreq( hdl, hdl->mag );
      hdl->block_count = hdl->block_no;
   }

   if( hdl->block_no > 1 ) {
      hdl->block_count2--;
      if( hdl->block_count2 == 0 ) {
         //printf("Test2 ");
         for( I = 0; I < 8; I++ ) {
            hdl->mag2[I] = TD_GetMagnitudeDB( &hdl->hdl2[I] );
            TD_Reset( &hdl->hdl2[I] );
            //printf( "%2d ", hdl->mag2[I] );
         }
         dtmfAnalyzeFreq( hdl, hdl->mag2 );
         hdl->block_count2 = hdl->block_no;
      }
   }
   return comsumedLen;
}

void dtmfClose( DTMF_Handle *hdl )
{
   free_ctrl_buffer( hdl );
}

DTMF_Handle *DTMF_Open( int32 block_size, int32 block_no )
{
   int32 I;
   DTMF_Handle *hdl;
   
   hdl = get_ctrl_buffer( sizeof(DTMF_Handle) );

   hdl->block_size = block_size;
   hdl->acum_buf_size = 0;
   hdl->block_no = hdl->block_count = block_no;
   hdl->block_count2 = block_no >> 1;
   hdl->key = 0;
   hdl->key_temp = 0;
   hdl->key_pre = 0;
   hdl->key_pre_second = 0;
   hdl->pauseCount = 0;
   hdl->PutData = dtmfPutData;
   hdl->Close = dtmfClose;
   hdl->GetKey = dtmfGetKey;
   for( I = 0; I < 8;I++ ) {
      TD_Init( &hdl->hdl[I], DTMF_Freq[I], block_size * block_no );
      TD_Init( &hdl->hdl2[I], DTMF_Freq[I], block_size * block_no );
   }
   return hdl;
}
