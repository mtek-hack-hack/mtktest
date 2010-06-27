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
 *   G711_main.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   G711 codec driver, including G711 a-Law and u-Law, 
 *     support VAD/DTX and CNG/PLC
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
*                     C O M P I L E R   F L A G S
******************************************************************************
*/

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/
#if !defined(SIM_ON_VC)
#include "kal_release.h"
#else
#include "l1audio_def.h"
#endif

#include "LowcFE.h"
#include "G711_CNG.h"
#include "G729.h"
#include "G729B.h"

#if defined(G711_UNIT_TEST) && !defined(__MTK_TARGET__)
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#endif

/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define FRAME_LEN                       80
#define G711_ALAW                       1
#define G711_ULAW                       2
#define SUBFRAME_LEN                    (FRAME_LEN/2)

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/
#if defined(__G7XX_DEBUG__)
typedef unsigned short                  CODE;
#else
typedef unsigned char                   CODE;
#endif

typedef struct {
   int                 law;
   int                 (*compress)( int pcm_val );

   void                *scratch;
   int                 sid_update_countdown;
   // VAD/DTX instance
   short               tmpBuffer[80];
   void                *G729_enc;
   G711_CNG_Cod_state G711_Enc_CN;
} G711_Cod;

typedef struct {
   int                 law;
   unsigned short      *lawTable;

   void                *scratch;
   // PLC/CNG instance
   G711_CNG_Dec_state G711_Dec_CN;
   G711_CNG_Cod_state G711_Enc_CN;
   LowcFE_state        plc_state;
   int                 is_preprocess_prev_frame;
   
   unsigned int        prep_xn_1_2;
   unsigned int        prep_yn_1_2;     
   
} G711_Dec;

/*****************************************************************************
*                        P U B L I C   D A T A
******************************************************************************
*/
extern const unsigned short Alaw_Tab[256];
extern const unsigned short Ulaw_Tab[256];

/*****************************************************************************
*                       P R I V A T E   D A T A
******************************************************************************
*/
#if defined(G711_UNIT_TEST) && !defined(__MTK_TARGET__)
clock_t clocks_per_frame, clocks_max=0, clocks_min=0x7fffffff, clocks_total=0;
int index_clock_max = 0;
int frame = 0;

static struct wav_header 
{
   char             riff_chunk[4];
   unsigned int     riff_size;
   char             riff_type[4];
   char             fmt_chunk[4];
   unsigned int     fmt_size;
   short            fmt_codec;
   short            channels;
   unsigned int     fs;
   unsigned int     bytes_per_sec;
   short            block_align;
   short            bits_per_sample;
   char             data_chunk[4];
   unsigned int     data_size;
} fixed_wav_hdr = {
   { 'R', 'I', 'F', 'F' },
   36,
   { 'W', 'A', 'V', 'E' },
   { 'f', 'm', 't', (char)0x20 },
   16,
   1, // linear PCM
   1, // 2-CH
   8000,
   8000*2,
   2,
   16,
   { 'd', 'a', 't', 'a' },
   0
}; 
#endif

//const unsigned char DefaultRCCoeff[10] = {0x1D, 0x84, 0x63, 0x77, 0x85, 0x7c, 0x7E, 0x7F, 0x7A, 0x79};

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/
#if defined(G711_UNIT_TEST) && !defined(__MTK_TARGET__)
#define ASSERT                          assert
#endif

#define aligned_sizeof(_type)           ((sizeof(_type)+3)&(~3))
#define is_aligned(_ptr)                (0==((unsigned int)(_ptr)&3))

/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/
extern int linear2alaw( int pcm_val );
extern int linear2ulaw( int pcm_val );

extern void RemoveDC(short *speech_in, unsigned int *prep_xn_1_2, unsigned int *prep_yn_1_2);

/*****************************************************************************
*                          F U N C T I O N S
******************************************************************************
*/

unsigned int G711_GetInternalBufferSize(int is_encoder)
{
   unsigned int buffer_size;

   if( is_encoder==1 )
      buffer_size = sizeof(G711_Cod) + G729AB_GetInternalBufferSize(1);
   else
   {
      buffer_size = sizeof(G711_Dec);
   }

   return buffer_size;
}

unsigned int G711_GetSharedBufferSize(int is_encoder)
{
   if( is_encoder==1 )
      return G729AB_GetSharedBufferSize(1);
   else
   {
      return LowcFE_getScratchSize()+G711_CNG_Dec_getScratchSize();
   }
}

void *G711_Open(int law, int is_encoder, 
   unsigned char *internal_buffer, unsigned int internal_buffer_size,
   unsigned char *shared_buffer
){
   unsigned int used_buffer_size, g729_size;
   void *data;

   ASSERT( internal_buffer_size>=G711_GetInternalBufferSize( is_encoder ) );

   if( is_encoder==1 )
   {
      G711_Cod *cod;

      cod = (G711_Cod *)internal_buffer;
      used_buffer_size = aligned_sizeof( G711_Cod );
      internal_buffer += aligned_sizeof( G711_Cod );

      cod->scratch = (void *)shared_buffer;
      cod->sid_update_countdown = 0;

      // KH: add for VAD/CNG
      g729_size = internal_buffer_size - used_buffer_size;
      cod->G729_enc = G729B_Init_Enc(internal_buffer, g729_size, shared_buffer);
      used_buffer_size += g729_size;
      internal_buffer += g729_size;

      // Init CNG
      memset(cod->tmpBuffer, 0, 80*sizeof(short));
      G711_CNG_Init_Enc( &cod->G711_Enc_CN, 80, MODEL_ORDER);

      cod->law = law;
      if( law==G711_ALAW )
         cod->compress = linear2alaw;
      else if( law==G711_ULAW )
         cod->compress = linear2ulaw;
      else
         ASSERT( 0 );

      data = (void *)cod;
   }
   else
   {
      G711_Dec *dec;

      dec = (G711_Dec *)internal_buffer;
      used_buffer_size = aligned_sizeof( G711_Dec );
      internal_buffer += aligned_sizeof( G711_Dec );

      dec->scratch = (void *)shared_buffer;

      // Init CNG
      G711_CNG_Init_Dec( &dec->G711_Dec_CN, 80);
      G711_CNG_Init_Enc( &dec->G711_Enc_CN, 80, MODEL_ORDER);

      dec->law = law;
      if( law==G711_ALAW )
         dec->lawTable = (unsigned short *)Alaw_Tab;
      else if( law==G711_ULAW )
         dec->lawTable = (unsigned short *)Ulaw_Tab;
      else
         ASSERT( 0 );

      // Initialize the value for Packet Loss Concealment
      LowcFE_init(&dec->plc_state);
      dec->is_preprocess_prev_frame = 0;
      
      dec->prep_xn_1_2 = dec->prep_yn_1_2 = 0;

      data = (void *)dec;
   }

   internal_buffer_size = used_buffer_size;
   return(data);
}


void G711_Close(void *data, int is_encoder)
{
}

// KH: add for G729B VAD/CNG
int G711_Encode(void *data, short *speech_in, CODE *bits_out, int VAD_enable, int CNG_enable)
{
   G711_Cod *cod = (G711_Cod *)data;
   int num_octets;
   int vad_result = 1;

   if( VAD_enable==1 )
   {
      // CNG Lookahead 5 ms
      memcpy(cod->tmpBuffer + 40, speech_in, 40*sizeof(short));

      // vad_result
      G729B_Encoder( cod->G729_enc, speech_in, (short *)bits_out, &vad_result);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
      G711_CNG_PreProcess(&cod->G711_Enc_CN, cod->scratch, speech_in);
   }

   if( vad_result==1 )
   { // voice frame
      int i;
      short *pSample;

      if( VAD_enable==1 ) {
         pSample = cod->tmpBuffer;
      } else {
         pSample = speech_in;
      }

      for( i=0; i<FRAME_LEN; i++ )
         bits_out[i] = cod->compress( pSample[i] );

      num_octets = FRAME_LEN*sizeof(CODE);
   }
   else
   { // SID frame or no data
      num_octets = G711_CNG_Encoder(&cod->G711_Enc_CN, cod->scratch, (short *)bits_out);
      if(num_octets > 0)
      {
         vad_result = 2;
      }
   }

   // KH: To update frame type
   if( VAD_enable==1 ) {
      G711_CNG_Update_Enc(&cod->G711_Enc_CN, vad_result);
      memcpy(cod->tmpBuffer, speech_in + 40, 40*sizeof(short));
   }

   return(num_octets);
}


int G711_Decode(void *data, CODE *bits_in, short *speech_out, int num_octets, 
                short frame_erasure, int isCNPayload, int disable_enhancement)
{
   G711_Dec *dec = (G711_Dec *)data;
   int frame_type = 4;
   int packetloss = 0;

   if (num_octets == 0)
   {
      packetloss = 1 - G711_CNG_IsDTX(&dec->G711_Dec_CN);
   }

   if ((frame_erasure == 0) && (packetloss==0))
   {
#ifndef AUTO_DETECT_CN
      if((num_octets >= FRAME_LEN*sizeof(CODE)) && (isCNPayload == 0) )
#else
      if((num_octets >= FRAME_LEN*sizeof(CODE)))
#endif
      { // voice frame
         //CODE *p_bits_in = bits_in;
         short *p_lawTable = (short *)dec->lawTable;
         short *p_speech_out = speech_out;
         unsigned char cn_bits[MODEL_ORDER+1];
         int cn_num_octets = 0;
         int i, j;

         for( i=0; i<FRAME_LEN; i+=4 )
         {
						speech_out[i] = p_lawTable[*bits_in++];
						speech_out[i+1] = p_lawTable[*bits_in++];
						speech_out[i+2] = p_lawTable[*bits_in++];
						speech_out[i+3] = p_lawTable[*bits_in++];
         }

				 // Remove the DC part of decoded speech output signal.
				 // Prevent the low freq noise which comes from G711_CNG_PreProcess
	  		 RemoveDC(speech_out, &dec->prep_xn_1_2, &dec->prep_yn_1_2);

	  
         frame_type = 1;
         if(dec->is_preprocess_prev_frame != 0)
         {           
            for(i=0; i<FRAME_LEN/SUBFRAME_LEN; i++)
            {
               short sample_max = (short)0x8000, sample_min = (short)0x7fff;

               j = SUBFRAME_LEN/2;
               do 
               {
                  short sample;
                  sample = *p_speech_out++ ;
                  if(sample > sample_max)
                  {
                     sample_max = sample;
                  }
                  if(sample < sample_min)
                  {
                     sample_min = sample;
                  }
                  sample = *p_speech_out++ ;
                  if(sample > sample_max)
                  {
                     sample_max = sample;
                  }
                  if(sample < sample_min)
                  {
                     sample_min = sample;
                  }
               } while(--j > 0);
			   
               if(sample_max <= sample_min+32)
               {
                  p_speech_out -= SUBFRAME_LEN;
                  if(cn_num_octets == 0)
                  {
                     cn_num_octets = G711_CNG_Encoder(&dec->G711_Enc_CN, dec->scratch, (short *)cn_bits);
                     cn_bits[0] -= 3;
                     dec->G711_Dec_CN.FrameSize = SUBFRAME_LEN;
                     G711_CNG_Decoder(&dec->G711_Dec_CN, dec->scratch, cn_bits, p_speech_out, cn_num_octets);
                     dec->G711_Dec_CN.FrameSize = FRAME_LEN;
                     frame_type = 4;
                  }
                  else
                  {
                     cngLPCSynthesize(&dec->G711_Dec_CN, p_speech_out, SUBFRAME_LEN);
                  }
                  p_speech_out += SUBFRAME_LEN;
               }
			   
            }
         }
         // Add to PLC history buffer
         LowcFE_addtohistory(&dec->plc_state, dec->scratch, speech_out);
      }

#ifndef AUTO_DETECT_CN
      else if((num_octets == 0) || (isCNPayload == 1))
#else
      else
#endif
      { // SID
         if(num_octets == 1)
         {
            unsigned char cn_bits[MODEL_ORDER+1];
            int cn_level1 = (int)bits_in[0], cn_level2;
            int cn_num_octets = G711_CNG_Encoder(&dec->G711_Enc_CN, dec->scratch, (short *)cn_bits);
            cn_level2 = (int)cn_bits[0];
            cn_bits[0] = (unsigned char)((cn_level1 + cn_level2) >> 1);
            G711_CNG_Decoder(&dec->G711_Dec_CN, dec->scratch, cn_bits, speech_out, cn_num_octets);
         }
         else
         {
            G711_CNG_Decoder(&dec->G711_Dec_CN, dec->scratch, bits_in, speech_out, num_octets);
         }

         if (num_octets == 0)
            frame_type = 0;
         else
            frame_type = 2;
         
         // Add to PLC history buffer
         LowcFE_addtohistory(&dec->plc_state, dec->scratch, speech_out);
      }
#ifndef AUTO_DETECT_CN
      else
      {
         frame_erasure = 1;
      }
#endif
   }

   if ( (frame_erasure==1) || (packetloss==1) )
   { // PLC
      LowcFE_dofe(&dec->plc_state, dec->scratch, speech_out);

      frame_type = 3;
   }

   // Save frame type
   // Voice frame: Reset random seed
   dec->is_preprocess_prev_frame = 0;
   if ((frame_erasure == 0) && (packetloss==0)) {
      // Save Frame Type for CNG
      G711_CNG_Update_Dec(&dec->G711_Dec_CN, frame_type);
      G711_CNG_Update_Enc(&dec->G711_Enc_CN, frame_type);
      if(frame_type == 1 && disable_enhancement == 0)
      {
         G711_CNG_PreProcess(&dec->G711_Enc_CN, dec->scratch, speech_out);
         dec->is_preprocess_prev_frame = 1;
      }
   }
   return(frame_type);
}

#if defined(G711_UNIT_TEST) && !defined(__MTK_TARGET__)
#include <math.h>
static struct {
   FILE *fplog;
} postproc;

void postproc_init()
{
   postproc.fplog = fopen("postproc.log", "w");
   fprintf(postproc.fplog, "%5s, %7s, %6s, %8s, %8s\n", "Ftyp", "energy", "ZCR", "custom1", "custom2");
}

void postproc_trace(int Ftyp, float energy, int ZCR, int custom1, int custom2)
{
   fprintf(postproc.fplog, "%5d, %-4.2f, %6d, %8d, %8d\n", 
      Ftyp, energy, ZCR, custom1, custom2);
}

int postproc_process(short *pSample, int numSamples, int Ftyp)
{
   int i;
   long sum;
   float energy = 0;
   int custom1 = 0;
   int custom2 = 0;
   int ZCR;

   /* energy calculation */
   for(i = 1, sum = pSample[0] * pSample[0], ZCR = 0; i < numSamples; i ++)
   {
      sum += pSample[i] * pSample[i];
      if(pSample[i] * pSample[i-1] < 0)
      {
         ZCR ++;
      }
   }
   energy = 10*log10(((double)sum / numSamples) / 32768.0);

   postproc_trace(Ftyp, energy, ZCR, custom1, custom2);
   return 0;
}

void postproc_deinit()
{
   fclose(postproc.fplog);
}

unsigned char internal_buffer_pool[10*1024];
unsigned char shared_buffer_pool[10*1024];

int stop_sample = 19440;
int sample_processed = 0;
int bypass_bytes = 4;
void main2(int argc, char **argv)
{
   int argi = 1;
   char *pargv;
   int law = G711_ULAW;
   int is_encode = 0;
   int vad_enable = 1;
   FILE *fp_linear, *fp_code;
   int N_linear = FRAME_LEN*sizeof(short);
   short linear_buffer[FRAME_LEN];
   int N_code = FRAME_LEN*sizeof(CODE);
   CODE code_buffer[FRAME_LEN*sizeof(CODE)];
   int num_octets;
   void *data;
   unsigned char *buffer;
   unsigned int buffer_size;
   
   pargv = argv[argi];
   if(strncmp(pargv, "-e", 2) == 0)
   {
      is_encode = 1;
      argi ++;
   }
   else if(strncmp(pargv, "-d", 2) == 0)
   {
      is_encode = 0;
      argi ++;
   }

   pargv = argv[argi];
   if(strncmp(pargv, "--u", 3) == 0)
   {
      law = G711_ULAW;
      argi ++;
   }
   else if(strncmp(pargv, "--a", 3) == 0)
   {
      law = G711_ALAW;
      argi ++;
   }

   memset(internal_buffer_pool, 0, sizeof(internal_buffer_pool));
   memset(shared_buffer_pool, 0, sizeof(shared_buffer_pool));
   
   if(is_encode != 0)
   {
      fp_linear = fopen( argv[argi++], "rb" );
      fp_code = fopen( argv[argi++], "wb" );
      vad_enable = atoi( argv[argi++] );

      buffer = internal_buffer_pool;
      buffer_size = G711_GetInternalBufferSize(1);
      ASSERT(G711_GetSharedBufferSize(1) <= sizeof(shared_buffer_pool));
      data = G711_Open( law, 1, buffer, buffer_size, shared_buffer_pool );
   }
   else
   {
      fp_code = fopen( argv[argi++], "rb" );
      fp_linear = fopen( argv[argi++], "wb" );
      
      buffer = internal_buffer_pool;
      buffer_size = G711_GetInternalBufferSize(0);
      ASSERT(G711_GetSharedBufferSize(0) <= sizeof(shared_buffer_pool));
      data = G711_Open( law, 0, buffer, buffer_size, shared_buffer_pool );
      postproc_init();
   }
   if( fp_linear==NULL || fp_code==NULL )
      return;

   if( is_encode==1)
   {
      int is_wav = 0;
      int elapsed_sample = 0;
      struct wav_header stWavHdr;

      fread(&stWavHdr, sizeof(struct wav_header), 1, fp_linear);
      if( strncmp(stWavHdr.riff_chunk, fixed_wav_hdr.riff_chunk, 4) == 0 )
      {
        if( ( strncmp(stWavHdr.riff_type, fixed_wav_hdr.riff_type, 4) == 0) &&
            ( strncmp(stWavHdr.fmt_chunk, fixed_wav_hdr.fmt_chunk, 4) == 0 ) &&
            ( stWavHdr.fmt_codec == fixed_wav_hdr.fmt_codec ) &&
            ( stWavHdr.channels == fixed_wav_hdr.channels ) &&
            ( stWavHdr.fs == fixed_wav_hdr.fs ) &&
            ( stWavHdr.bytes_per_sec == fixed_wav_hdr.bytes_per_sec ) &&
            ( stWavHdr.block_align == fixed_wav_hdr.block_align ) &&
            ( stWavHdr.bits_per_sample == fixed_wav_hdr.bits_per_sample ) &&
            ( strncmp(stWavHdr.data_chunk, fixed_wav_hdr.data_chunk, 4) == 0 ) )
        {
          is_wav = 1;
          elapsed_sample = stWavHdr.data_size >> 1;
        }
      }

      if(is_wav == 0)
      {
        fseek(fp_linear, 0, SEEK_SET);
        elapsed_sample = 0x7fffffff;
      }

      while( !feof(fp_linear) )
      {
         int nbytes = fread( linear_buffer, 1, N_linear, fp_linear );
         elapsed_sample -= N_linear >> 1;
         if(elapsed_sample<0)
            break;

         if( nbytes==N_linear )
         {
#if defined(__PROFILING__)
            clocks_per_frame = clock();
#endif
            num_octets = G711_Encode( data, linear_buffer, code_buffer, vad_enable, 1 );
#if defined(__PROFILING__)
            clocks_per_frame = clock() - clocks_per_frame;
            if( clocks_max<clocks_per_frame )
            {
               clocks_max = clocks_per_frame;
               index_clock_max = frame;
            }
            if( clocks_min>clocks_per_frame )
               clocks_min = clocks_per_frame;
            clocks_total += clocks_per_frame/128;
            frame ++;
#endif
            
#if !defined(__G7XX_DEBUG__)
            fwrite( &num_octets, 2, 1, fp_code );
#endif
            fwrite( code_buffer, 1, num_octets, fp_code );
         }
      }
   }
   else
   {
      fwrite(&fixed_wav_hdr, sizeof(fixed_wav_hdr), 1, fp_linear);
	  fseek( fp_code, bypass_bytes, SEEK_SET );
      while( !feof(fp_code) )
      {
         int nbytes, Ftyp;
#if defined(__G7XX_DEBUG__)
         nbytes = 1;
         num_octets = 160;
#else
         num_octets = 0;
         nbytes = fread( &num_octets, 2, 1, fp_code );
#endif
         if( nbytes==1 )
         {
            nbytes = fread( code_buffer, 1, num_octets, fp_code );
            if( nbytes==num_octets )
            {
#if defined(__PROFILING__)
               clocks_per_frame = clock();
#endif
               if(sample_processed == stop_sample)
                  printf("stop_sample\n");
               Ftyp = G711_Decode( data, code_buffer, linear_buffer, num_octets, 0, (num_octets >= 1 && num_octets<80)? 1: 0 );
               postproc_process(linear_buffer, 80, Ftyp);
#if defined(__PROFILING__)
               clocks_per_frame = clock() - clocks_per_frame;
               if( clocks_max<clocks_per_frame )
               {
                  clocks_max = clocks_per_frame;
                  index_clock_max = frame;
               }
               if( clocks_min>clocks_per_frame )
                  clocks_min = clocks_per_frame;
               clocks_total += clocks_per_frame/128;
               frame ++;
#endif
               fwrite( linear_buffer, 1, N_linear, fp_linear );
               sample_processed += N_linear >> 1;
            }
         }
      }

      fixed_wav_hdr.riff_size += sample_processed << 1;
      fixed_wav_hdr.data_size += sample_processed << 1;
      fseek(fp_linear, 0, SEEK_SET);
      fwrite(&fixed_wav_hdr, sizeof(fixed_wav_hdr), 1, fp_linear);
   }

   G711_Close( data, is_encode );

   if(is_encode == 0)
      postproc_deinit();

   fclose( fp_linear );
   fclose( fp_code );

#if defined(__PROFILING__)
   printf( "profiling result:\n" );
   printf( "\tAverage=%d cycles (%f MIPS)\n", clocks_total*128/frame,(float)clocks_total*128.0/(float)frame/10000.0 );
   printf( "\tMax=%d cycles (%f MIPS) @%d\n", clocks_max,(float)clocks_max/10000.0, index_clock_max );
   printf( "\tMin=%d cycles (%f MIPS)\n", clocks_min,(float)clocks_min/10000.0 );
#endif
}

void main(int argc, char **argv)
{
   int func = 0;
   char *plaw = argv[1];
   char *pinfilename = argv[2];
   char *poutfilename1 = argv[3], *poutfilename2 = argv[4];
   char *pargv[6];

   switch(func)
   {
      case 0: // Normal test
         main2(argc, argv);
         break;
      case 1: // Loopback test
         pargv[0] = argv[0];
         pargv[1] = "-e";
         pargv[2] = plaw;
         pargv[3] = pinfilename;
         pargv[4] = poutfilename1;
         pargv[5] = "0";
         main2(6, &pargv[0]);
         
         pargv[0] = argv[0];
         pargv[1] = "-d";
         pargv[2] = plaw;
         pargv[3] = poutfilename1;
         pargv[4] = poutfilename2;
         main2(5, &pargv[0]);
         break;
      default:
         break;
   }
}

#endif


