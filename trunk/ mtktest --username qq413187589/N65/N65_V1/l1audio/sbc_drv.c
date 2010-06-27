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
 *   sbc_drv.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   SBC codec interface and driver, for Bluetooth A2DP
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__BT_A2DP_PROFILE__) || defined(SBC_UNIT_TEST)
#include <string.h>

#include "l1audio_def.h"

#include "dcmgr.h"
#include "am.h"
#include "afe.h"

#include "sbc.h"

#include "kal_trace.h"
#include "l1sp_trc.h"

#include "apm_util.h"
#define SBC_TRACE    kal_trace

//#define SBC_UNIT_TEST   1 // it shall be set in \make\l1audio\l1audio.def
//#define _SBC_DEBUG_NO_QOS_ // QOS indication wouldn't affect current bit rate
//#define SBC_DEBUG_QOS

#ifdef SBC_UNIT_TEST
#define DSP_SB_LOG // save DSP output to dsp_sb.bin in removable disk
#endif

#define _SBC_ENALBLE_DROP_ // enable SBC encoder drop frame when MCU busy

#if defined(DSP_SB_LOG) || defined(SBC_UNIT_TEST)
#include "fsal.h"
#endif

#define SBC_WAV_FIXED_START_RATE 165
#define SBC_WAV_FORMAT ((Media_Format)-1)
#define MCU_SB_BUFFER_LEN  8192 // it shall be a multiple of 128, recommended:8192 ; suggest it is a multiple of 384 for all combination
#define MCU_MIN_SB_BUFFER_SIZE 256

kal_uint32 SaveAndSetIRQMask(void);
void RestoreIRQMask(kal_uint32);

#if defined(__BTMTK__)
extern void bt_a2dp_alg_set_bit_rate_from_qos_init(kal_uint32 bit_rate_cur);
extern kal_uint32 bt_a2dp_alg_set_bit_rate_from_qos(kal_uint8 qos, kal_uint32 bit_rate_prev, kal_uint32 (*SetCodecBitRate)(kal_uint32));
#endif


#if (SBC_IN_TCM == 0)
__align(4)
static kal_int16 mcu_subband_buffer[MCU_MIN_SB_BUFFER_SIZE];
static SBC_Encoder_State SBC_subband_analyzer_state;
static short SBC_subband_sample_buffer[16][2][8];

#elif (SBC_IN_TCM == 1)
static kal_int16 *mcu_subband_buffer;
static short *SBC_subband_sample_buffer;
static SBC_Encoder_State *SBC_subband_analyzer_state;

#else

#if defined(MT6223) || defined(MT6223P)
__align(4)
static kal_int16 mcu_subband_buffer[MCU_SB_BUFFER_LEN];
#else  // not MT6223 or MT6223P
#pragma arm section zidata="SBC_DYNAMIC_ZI"
__align(4)
static kal_int16 mcu_subband_buffer[MCU_SB_BUFFER_LEN];
#pragma arm section
#endif  // end defined(MT6223) || defined(MT6223P)

#endif

#define SBC_FRAME_SUBBAND_DATA_SIZE (sbc.frame_state.subbands * sbc.frame_state.blocks)  //  8 * 16

/* SBC internal functions */
#if (PREFFERED_ALLOCATION_MODE==LOUDNESS)
#define SBC_ALLOCATION_SUPPORT      0x1 // alloc_method: loudness only
#elif (PREFFERED_ALLOCATION_MODE==SNR)
#define SBC_ALLOCATION_SUPPORT      0x2 // alloc_method: snr only
#else
#error wrong definition in sbc.h
#endif

extern kal_uint16 BT_A2DP_MAX_BIT_RATE;
static kal_uint16 max_sbc_bit_rate;
const bt_a2dp_sbc_codec_cap_struct sbc_cap[1] = {
   { // joint-stereo, 44.1, 32, 16Ksps
      19, // min_bit_pool
#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6223) || defined(MT6223P)
      36,
#else
      75, // max_bit_pool
#endif
      0x1, // block_len: 16 only
      0x1, // subband_num: 8 only
      SBC_ALLOCATION_SUPPORT,
      0xf, // sample_rate: all
      0xf, // channel_mode: all
   }
};

static struct sbc_struct {
   kal_uint16         aud_id;
   A2DP_codec_struct  a2dp_codec_hdl;
   A2DP_Callback   callback;
   kal_bool       waiting;
   Media_Format     aud_fmt;
   
#if APM_SUPPORT
   /* APM Information. Swap buffer for upsampling */
   kal_int32        src_sample_rate;   // sampling frequency of source PCM
   kal_int32        rampGain;
   kal_int32        rampFormat;
   kal_int16        preSample[8];      // To keep the sample for upsampling
   APM_TCM          tcm;
#endif

   /* MCU ring buffer for subband sample */
   kal_int16        *subband_buffer;
   kal_uint16       subband_buffer_read;
   kal_uint16       subband_buffer_write;
   
   /* MCU ring buffer for SBC frame */
   kal_uint8        *frame_buffer;
   kal_uint32       frame_buffer_read;
   kal_uint32       frame_buffer_write;   
   kal_uint32       frame_buffer_length;
   kal_uint32       frame_buffer_unfilled_pos;

   kal_uint32       current_bit_rate;
   kal_uint32       current_frame_size;
   kal_uint32       total_payload_size;

   kal_uint8        *fragment_start;
   kal_bool         fragment_flag;
   kal_uint8        fragment_left; // 1~15
   kal_uint16       fragment_left_bytes;
   kal_uint16       fragment_size;
   
   SBC_Frame_State  frame_state;
   kal_uint8        min_bit_pool;
   kal_uint8        max_bit_pool;

   kal_uint32       frame_produced;
   kal_uint32       frame_consumed;
   kal_uint32       frame_dropped;

   kal_bool         subband_analyzer_on;
} sbc;

#ifdef DSP_SB_LOG
#define DSP_SB_BUF_LEN    (640)//(2048) // 1MB space
kal_int16 dsp_sb_buf[DSP_SB_BUF_LEN][128*2];
kal_int16 dsp_sb_buf_index;

static struct wav_header {
	char riff_chunk[4];
	unsigned int riff_size;
	char riff_type[4];
	char fmt_chunk[4];
	unsigned int fmt_size;
	short fmt_codec;
	short channels;
	unsigned int fs;
	unsigned int bytes_per_sec;
	short block_align;
	short bits_per_sample;
	char data_chunk[4];
	unsigned int data_size;
} fixed_wav_hdr = {
   { 'R', 'I', 'F', 'F' },
   DSP_SB_BUF_LEN*128*2*2+36,
   { 'W', 'A', 'V', 'E' },
   { 'f', 'm', 't', (char)0x20 },
   16,
   1, // linear PCM
   2, // 2-CH
   44100,
   44100*2*2,
   4,
   16,
   { 'd', 'a', 't', 'a' },
   DSP_SB_BUF_LEN*128*2*2
}; 
#endif

#ifdef SBC_DEBUG_QOS
struct {
   unsigned char qos_value;
   unsigned char bitrate_old;
   unsigned char bitrate_new;
} qos_log[256];
unsigned int qos_log_idx;
#endif

static kal_uint32 sbc_calc_bitpool_from_bitrate( kal_uint32 bitrate, kal_uint8 nrof_subbands, kal_uint8 nrof_blocks, kal_uint8 channel_mode, kal_uint32 fs, kal_uint32 *frame_length );
void SBC_InitiateBitPool(kal_uint8 channel_mode, kal_uint8 sample_rate, kal_uint8 *min, kal_uint8 *max )
{
   SBC_TRACE( TRACE_FUNC, L1SBC_ENTER_SBC_INITIATEBITPOOL );
   if( min!=NULL ) *min = sbc_cap[0].min_bit_pool;
   if( max!=NULL ) *max = sbc_cap[0].max_bit_pool;
}

void SBC_AdjustBitpool( kal_uint8 max_bitpool, kal_uint8 min_bitpool )
{
   SBC_TRACE( TRACE_FUNC, L1SBC_ENTER_SBC_ADJUSTBITPOOL );
   EXT_ASSERT( sbc.aud_id != INVALID_AUDIO_ID, sbc.aud_id, 0, 0 ); // SBC shall be opened first
   if( min_bitpool<sbc_cap[0].min_bit_pool )
      min_bitpool = sbc_cap[0].min_bit_pool;
   if( min_bitpool>sbc_cap[0].max_bit_pool )
      min_bitpool = sbc_cap[0].max_bit_pool;
      
   if( max_bitpool>sbc_cap[0].max_bit_pool )
      max_bitpool = sbc_cap[0].max_bit_pool;
   if( max_bitpool<min_bitpool )
      max_bitpool = min_bitpool;
   
   sbc.min_bit_pool = min_bitpool;
   sbc.max_bit_pool = max_bitpool;
}

static kal_uint32 sbc_initiate_bit_rate( kal_uint8 channel_mode, kal_uint8 sample_rate, Media_Format aud_fmt )
{
   kal_uint32 bit_rate;
#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6223) || defined(MT6223P)
   if( (aud_fmt==MEDIA_FORMAT_WAV) ||
       (aud_fmt==MEDIA_FORMAT_AU) ||
       (aud_fmt==MEDIA_FORMAT_AIFF) )
      bit_rate = SBC_WAV_FIXED_START_RATE;
   else
#endif
//      bit_rate = 39 + sbc_cap[0].max_bit_pool*6;
      bit_rate = max_sbc_bit_rate;
   
   return bit_rate;
}

static kal_uint32 sbc_calc_bitrate_from_bitpool( kal_uint32 bitpool, kal_uint8 nrof_subbands, kal_uint8 nrof_blocks, kal_uint8 channel_mode, kal_uint32 fs, kal_uint32 *frame_length )
{   
   kal_uint8 nrof_channels, join;
   kal_uint32 frame_length_t, bitrate;

   nrof_channels = ( channel_mode==SBC_CM_MONO )? 1: 2;
   join = ( channel_mode==SBC_CM_JOINT_STEREO)? 1: 0;

   frame_length_t = 4 + ( 4 * nrof_subbands * nrof_channels ) / 8;
   if( channel_mode==SBC_CM_MONO || channel_mode==SBC_CM_DUAL_CHANNEL )
      frame_length_t += (nrof_blocks * nrof_channels * bitpool) / 8;
   else if( channel_mode==SBC_CM_STEREO || channel_mode==SBC_CM_JOINT_STEREO )
      frame_length_t += ( join * nrof_subbands + nrof_blocks * bitpool ) / 8;
   else
   {
      EXT_ASSERT( 0, channel_mode, 0, 0 );
      return( 0 );
   }

   bitrate = ( 8 * frame_length_t * fs ) / ( nrof_subbands * nrof_blocks );
   bitrate = (bitrate + 999) / 1000; // in kb/s with rounding

   if( frame_length!=NULL )
      *frame_length = frame_length_t;
   return( bitrate );
}

static kal_uint32 sbc_calc_bitpool_from_bitrate( kal_uint32 bitrate, kal_uint8 nrof_subbands, kal_uint8 nrof_blocks, kal_uint8 channel_mode, kal_uint32 fs, kal_uint32 *frame_length )
{
   kal_uint8 nrof_channels, join;
   kal_uint32 bitpool;
   kal_int32 frame_length_t;

   nrof_channels = ( channel_mode==SBC_CM_MONO )? 1: 2;
   join = ( channel_mode==SBC_CM_JOINT_STEREO)? 1: 0;

   frame_length_t = ( bitrate * 1000 * nrof_subbands * nrof_blocks ) / ( 8 * fs );
    if( frame_length!=NULL )
       *frame_length = frame_length_t;

   frame_length_t -= 4 + ( 4 * nrof_subbands * nrof_channels ) / 8;
   if( frame_length_t<=0 )
      return 0;
   if( channel_mode==SBC_CM_MONO || channel_mode==SBC_CM_DUAL_CHANNEL )
      bitpool = ( 8 * frame_length_t ) / ( nrof_blocks * nrof_channels );
   else if( channel_mode==SBC_CM_STEREO || channel_mode==SBC_CM_JOINT_STEREO )
      bitpool = ( 8 * frame_length_t - join * nrof_subbands ) / nrof_blocks;
   else
   {
      EXT_ASSERT( 0, channel_mode, 0, 0 );
      return 0;
   }

   return ( bitpool );
}

static kal_uint32 sbc_config(bt_a2dp_sbc_codec_cap_struct *sbc_config_data, kal_uint32 bit_rate)
{
   kal_uint8 bitpool_t;
   kal_uint32 frame_length_t, savedMask;
   
   if( sbc_config_data!=NULL )
   {
      kal_uint8 header_data = 0;
      
      if( sbc_config_data->block_len==1 )
      {
         sbc.frame_state.blocks = 16;
         header_data = SBC_NB_16<<4;
      }
      else if( sbc_config_data->block_len==2 )
      {
         sbc.frame_state.blocks = 12;
         header_data = SBC_NB_12<<4;
      }
      else if( sbc_config_data->block_len==4 )
      {
         sbc.frame_state.blocks = 8;
         header_data = SBC_NB_8<<4;
      }
      else if( sbc_config_data->block_len==8 )
      {
         sbc.frame_state.blocks = 4;
         header_data = SBC_NB_4<<4;
      }
      else
      {
         EXT_ASSERT(0, sbc_config_data->block_len, 0, 0);
      }

      if( sbc_config_data->subband_num==1 )
      {
         sbc.frame_state.subbands = 8;
         header_data |= SBC_SB_8;
      }
      else if( sbc_config_data->subband_num==2 )
      {
         sbc.frame_state.subbands = 4;
         header_data |= SBC_SB_4;
      }
      else
      {
         EXT_ASSERT(0, sbc_config_data->subband_num, 0, 0);
      }

      if( sbc_config_data->alloc_method==1 )
      {
         sbc.frame_state.allocation_method = SBC_AM_LOUDNESS;
         header_data |= SBC_AM_LOUDNESS<<1;
      }
      else if( sbc_config_data->alloc_method==2 )
      {
         sbc.frame_state.allocation_method = SBC_AM_SNR;
         header_data |= SBC_AM_SNR<<1;
      }
      else
      {
         EXT_ASSERT(0, sbc_config_data->alloc_method, 0, 0);
      }

      if( sbc_config_data->sample_rate==1 )
      {
         sbc.frame_state.sampling_frequency = 48000;
         header_data |= SBC_FS_48<<6;
      }
      else if( sbc_config_data->sample_rate==2 )
      {
         sbc.frame_state.sampling_frequency = 44100;
         header_data |= SBC_FS_44<<6;
      }
      else if( sbc_config_data->sample_rate==4 )
      {
         sbc.frame_state.sampling_frequency = 32000;
         header_data |= SBC_FS_32<<6;
      }
      else if( sbc_config_data->sample_rate==8 )
      {
         sbc.frame_state.sampling_frequency = 16000;
         header_data |= SBC_FS_16<<6;
      }
      else
      {
         EXT_ASSERT(0, sbc_config_data->sample_rate, 0, 0);
      }

      if( sbc_config_data->channel_mode==1 )
      {
         sbc.frame_state.channel_mode = SBC_CM_JOINT_STEREO;
         header_data |= SBC_CM_JOINT_STEREO<<2;
      }
      else if( sbc_config_data->channel_mode==2 )
      {
         sbc.frame_state.channel_mode = SBC_CM_STEREO;
         header_data |= SBC_CM_STEREO<<2;
      }
      else if( sbc_config_data->channel_mode==4 )
      {
         sbc.frame_state.channel_mode = SBC_CM_DUAL_CHANNEL;
         header_data |= SBC_CM_DUAL_CHANNEL<<2;
      }
      else if( sbc_config_data->channel_mode==8 )
      {
         sbc.frame_state.channel_mode = SBC_CM_MONO;
         header_data |= SBC_CM_MONO<<2;
      }
      else
      {
         EXT_ASSERT(0, sbc_config_data->channel_mode, 0, 0);
      }

      if( sbc.frame_state.channel_mode==SBC_CM_MONO )
         sbc.frame_state.channels = 1;
      else
         sbc.frame_state.channels = 2;

      sbc.frame_state.sbc_frame_header_data = header_data;

      sbc.max_bit_pool = sbc_config_data->max_bit_pool;
      sbc.min_bit_pool = sbc_config_data->min_bit_pool;
   }
   
   bitpool_t = (unsigned char)sbc_calc_bitpool_from_bitrate( bit_rate, sbc.frame_state.subbands, sbc.frame_state.blocks, sbc.frame_state.channel_mode, sbc.frame_state.sampling_frequency, NULL );
   if( bitpool_t<sbc.min_bit_pool )
   {
      bitpool_t = sbc.min_bit_pool;
   }
   else if( bitpool_t>sbc.max_bit_pool )
   {
      bitpool_t = sbc.max_bit_pool;
   }
   if( sbc_config_data!=NULL )
   {
      if( sbc.aud_fmt==SBC_WAV_FORMAT )
      {
         sbc.max_bit_pool = (kal_uint8)((int)(bitpool_t * 9) >> 3);
         sbc.min_bit_pool = sbc_config_data->min_bit_pool;
      }
      else
      {
         sbc.min_bit_pool = (kal_uint8)((int)(bitpool_t * 7) >> 3);
         if( sbc.min_bit_pool > 28 ) sbc.min_bit_pool = 28;
         if( sbc.min_bit_pool<sbc_config_data->min_bit_pool )
            sbc.min_bit_pool = sbc_config_data->min_bit_pool;
      }
   }
   bit_rate = sbc_calc_bitrate_from_bitpool( bitpool_t, sbc.frame_state.subbands, sbc.frame_state.blocks, sbc.frame_state.channel_mode, sbc.frame_state.sampling_frequency, &frame_length_t );

savedMask = SaveAndSetIRQMask();
   sbc.frame_state.bitpool = bitpool_t;
   sbc.current_frame_size = frame_length_t;
RestoreIRQMask(savedMask);

   SBC_TRACE( TRACE_INFO, L1SBC_CONFIG_REPORT, 
      sbc.frame_state.sampling_frequency, sbc.frame_state.channel_mode, 
      sbc.min_bit_pool, sbc.frame_state.bitpool, sbc.max_bit_pool );

   return( bit_rate );
}

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6223) || defined(MT6223P)
static void sbc_hisr( void *data )
{
   int total_read_count;
   kal_uint32 data_to_task = 0;

   kal_uint16 dsp_rb_read = DP_SB_READ;
   kal_uint16 dsp_rb_write = DP_SB_WRITE;
   kal_uint16 dsp_param = DP_SB_PARAM;
      /* bit 0: 1 for PM; 0 for DM
         bit 1: unused
         bit 2~3: page number
         bit 4~5: 00 for 16K; 01 for 32K; 10 for 44.1K; 11 for 48K
         bit 6: 1 for stereo; 0 for mono
         bit 7: unused
         bit 8: 1 for PCM; 0 for subband sample
       */
   kal_uint16 dsp_rb_base;
   int dsp_rb_len;
   volatile kal_uint16 *dsp_mem_base;

   if( ( DP_SB_CTRL != 1 ) || 
       ( sbc.aud_id == INVALID_AUDIO_ID ) )
      return;

   // get DSP parameter and ring buffer base address
   {
      kal_bool is_pm = KAL_FALSE; //(dsp_param&0x1);
      kal_uint32 page_num = (dsp_param&0xc) >> 2;

#if defined(MT6223) || defined(MT6223P)
      dsp_rb_base = 0x0000;
#else
      dsp_rb_base = 0x1000;
#endif

#if defined(MT6227D) || defined(MT6226D) || defined(MT6223) || defined(MT6223P)
      dsp_rb_len = 3072;
#else
      dsp_rb_len = 4096; 
#endif

      dsp_mem_base = (is_pm)? DSP_PM_ADDR(page_num, 0): DSP_DM_ADDR(page_num, 0);
      EXT_ASSERT( (dsp_rb_write>=dsp_rb_base) && (dsp_rb_read>=dsp_rb_base),
                   dsp_rb_base, dsp_rb_write, dsp_rb_read );
   }
   
   total_read_count = dsp_rb_write - dsp_rb_read;
   if( total_read_count<=0 )
      total_read_count += dsp_rb_len;

   // judge if buffer OK
   ASSERT( sbc.subband_buffer!=(kal_int16 *)0 );
   {
      int dsp_count = total_read_count;
      int mcu_space = sbc.subband_buffer_read - sbc.subband_buffer_write;
      if( mcu_space<=0 )
         mcu_space += MCU_SB_BUFFER_LEN;
      mcu_space -= 1; // prevent buffer overrun

      if( mcu_space<=dsp_count )
      {
         // drop subband sample
         DP_SB_READ = dsp_rb_write;
         L1Audio_SetEvent( sbc.aud_id, (void *)data_to_task );
         return;
      }
   }

   while( total_read_count>0 )
   {
      int read_dsp_cnt, write_mcu_cnt, cnt, I;
      register int16 *sb_data_ptr;
      
      if( dsp_rb_write>dsp_rb_read )
         read_dsp_cnt = dsp_rb_write - dsp_rb_read;
      else
         read_dsp_cnt = (dsp_rb_base+dsp_rb_len) - dsp_rb_read;
      
      if( sbc.subband_buffer_read>sbc.subband_buffer_write )
         write_mcu_cnt = sbc.subband_buffer_read - sbc.subband_buffer_write;
      else
         write_mcu_cnt = MCU_SB_BUFFER_LEN - sbc.subband_buffer_write;

      cnt = ( read_dsp_cnt>write_mcu_cnt )? write_mcu_cnt: read_dsp_cnt;
      EXT_ASSERT( (cnt&15)==0, cnt, 0, 0 );
      cnt >>= 4;
      /* Move subband sample into MCU buffer */
      sb_data_ptr = &sbc.subband_buffer[sbc.subband_buffer_write];
      
      I = (int16)(*(dsp_mem_base + dsp_rb_read));    /* dummy read */
      for(I=cnt; --I>=0; )
      {
         sb_data_ptr[ 0] = (int16)(*IDMA_SHORT_ADDR);    /* L1 */
         sb_data_ptr[ 1] = (int16)(*IDMA_SHORT_ADDR);    /* L2 */
         sb_data_ptr[ 2] = (int16)(*IDMA_SHORT_ADDR);    /* L3 */
         sb_data_ptr[ 3] = (int16)(*IDMA_SHORT_ADDR);    /* L4 */
         sb_data_ptr[ 4] = (int16)(*IDMA_SHORT_ADDR);    /* L5 */
         sb_data_ptr[ 5] = (int16)(*IDMA_SHORT_ADDR);    /* L6 */
         sb_data_ptr[ 6] = (int16)(*IDMA_SHORT_ADDR);    /* L7 */
         sb_data_ptr[ 7] = (int16)(*IDMA_SHORT_ADDR);    /* L8 */
         sb_data_ptr[ 8] = (int16)(*IDMA_SHORT_ADDR);    /* R1 */
         sb_data_ptr[ 9] = (int16)(*IDMA_SHORT_ADDR);    /* R2 */
         sb_data_ptr[10] = (int16)(*IDMA_SHORT_ADDR);    /* R3 */
         sb_data_ptr[11] = (int16)(*IDMA_SHORT_ADDR);    /* R4 */
         sb_data_ptr[12] = (int16)(*IDMA_SHORT_ADDR);    /* R5 */
         sb_data_ptr[13] = (int16)(*IDMA_SHORT_ADDR);    /* R6 */
         sb_data_ptr[14] = (int16)(*IDMA_SHORT_ADDR);    /* R7 */
         sb_data_ptr[15] = (int16)(*IDMA_SHORT_ADDR);    /* R8 */
         sb_data_ptr += 16;
      }

      cnt <<= 4;
      dsp_rb_read += cnt;
      if( dsp_rb_read==(dsp_rb_base+dsp_rb_len) )
         dsp_rb_read = dsp_rb_base;
      
      sbc.subband_buffer_write += cnt;
      if( sbc.subband_buffer_write==MCU_SB_BUFFER_LEN )
         sbc.subband_buffer_write = 0;
      
      total_read_count -= cnt;
      DP_SB_READ = dsp_rb_read;
   }
   
   L1Audio_SetEvent( sbc.aud_id, (void *)data_to_task );
}

static void sbc_event_handler( void *data )
{
   kal_uint32 savedMask;
#ifdef _SBC_ENALBLE_DROP_
   int drop_frames;
#endif

   const int NUM_FRAME_DATA = SBC_FRAME_SUBBAND_DATA_SIZE*2; // stereo
   register int data_count;
   int usedLen;

   if( sbc.aud_id == INVALID_AUDIO_ID )
      return;

   data_count = sbc.subband_buffer_write -  sbc.subband_buffer_read;
   if( data_count< 0 )
      data_count += MCU_SB_BUFFER_LEN;

///   SBC_TRACE( TRACE_GROUP_SBC, L1SBC_ENTER_SBC_ENCODING );

   usedLen = data_count;
   while( data_count>=NUM_FRAME_DATA )
   {
      kal_uint8 *sbc_frame_ptr;

      {
         int frame_len;
         kal_uint32 write_end = sbc.frame_buffer_write + (sbc.current_frame_size+1);
         if( sbc.frame_buffer_write>=sbc.frame_buffer_read )
         {
            if( write_end >= sbc.frame_buffer_length )
            {
               if( sbc.frame_buffer_read<=(sbc.current_frame_size+1) )
               {
                  if( data_count>=MCU_SB_BUFFER_LEN/3 )
                  {
                     SBC_TRACE( TRACE_WARNING, L1SBC_FRAME_BUFFER_UNDERRUN );
#ifdef _SBC_ENALBLE_DROP_
                     drop_frames = data_count / NUM_FRAME_DATA;
                     sbc.subband_buffer_read += drop_frames*NUM_FRAME_DATA;
                     if( sbc.subband_buffer_read>=MCU_SB_BUFFER_LEN )
                        sbc.subband_buffer_read -= MCU_SB_BUFFER_LEN;
                     sbc.frame_dropped += drop_frames;
#else
                     ASSERT( 0 );
#endif
                  }
                  break;
               }
               else
               {  // update unfille_pos as write pointer, set write pointer to 0
                  sbc.frame_buffer_unfilled_pos = sbc.frame_buffer_write;
                  sbc.frame_buffer_write = 0;
               }
            }
         }
         else
         {
            if( write_end>=sbc.frame_buffer_read )
            {
               if(data_count>=MCU_SB_BUFFER_LEN/3)
               {
                  SBC_TRACE( TRACE_WARNING, L1SBC_FRAME_BUFFER_UNDERRUN );
#ifdef _SBC_ENALBLE_DROP_
                  drop_frames = data_count / NUM_FRAME_DATA;
                  sbc.subband_buffer_read += drop_frames*NUM_FRAME_DATA;
                  if( sbc.subband_buffer_read>=MCU_SB_BUFFER_LEN )
                     sbc.subband_buffer_read -= MCU_SB_BUFFER_LEN;
                  sbc.frame_dropped += drop_frames;
#else
                  ASSERT( 0 );
#endif
               }
               break;
            }
         }

         sbc.frame_state.sb_sample = (short*)(&sbc.subband_buffer[sbc.subband_buffer_read]);

#if defined(DSP_SB_LOG)
         memcpy( (kal_uint8 *)&(dsp_sb_buf[dsp_sb_buf_index][0]), (kal_uint8 *)sbc.frame_state.sb_sample, 4*128 );
         if( DSP_SB_BUF_LEN==(++dsp_sb_buf_index) )
            dsp_sb_buf_index = 0;
#endif

         sbc_frame_ptr = (kal_uint8 *)sbc.frame_buffer + sbc.frame_buffer_write;

         *sbc_frame_ptr++ = (kal_uint8)sbc.current_frame_size;
         sbc_pack_frame(&sbc.frame_state, sbc_frame_ptr, &frame_len);
         if( frame_len!=sbc.current_frame_size )
         {
            EXT_ASSERT( frame_len == sbc.current_frame_size, frame_len, sbc.current_frame_size, 0 );
         }

         sbc.frame_buffer_write += frame_len+1;
savedMask = SaveAndSetIRQMask();
         sbc.total_payload_size += frame_len;
RestoreIRQMask(savedMask);
         EXT_ASSERT(sbc.total_payload_size <= sbc.frame_buffer_length, sbc.frame_buffer_write, sbc.frame_buffer_read, sbc.frame_buffer_unfilled_pos);
         if( sbc.frame_buffer_unfilled_pos<sbc.frame_buffer_write )
            sbc.frame_buffer_unfilled_pos = sbc.frame_buffer_write;
         if( sbc.frame_buffer_write==sbc.frame_buffer_length )
            sbc.frame_buffer_write = 0;

         sbc.frame_produced ++;
      }
      
      sbc.subband_buffer_read += NUM_FRAME_DATA;
      if( sbc.subband_buffer_read==MCU_SB_BUFFER_LEN )
         sbc.subband_buffer_read = 0;
      
      data_count -= NUM_FRAME_DATA;
      usedLen += NUM_FRAME_DATA;
   }

   SBC_TRACE( TRACE_GROUP_SBC, L1SBC_ENCODER_REPORT, 
      usedLen, sbc.total_payload_size, sbc.frame_produced );

   if( sbc.total_payload_size>1024 && sbc.waiting==KAL_FALSE )
   {
      sbc.waiting = KAL_TRUE;
      sbc.callback(A2DP_DATA_NOTIFY, (void*)&sbc.a2dp_codec_hdl);
   }
}
#endif

//============================ Fit the Interface of AudioPP Manager ================
#if APM_SUPPORT

void sbc_Init(APM_TCM *tcm)
{
   kal_int16 *bufBase;
   
   SBC_Init();
   
   sbc.tcm.tcmBuf = tcm->tcmBuf;
   sbc.tcm.tcmBufLen = tcm->tcmBufLen;
   
   bufBase = (kal_int16 *) tcm->tcmBuf;
   mcu_subband_buffer = bufBase;
   bufBase += MCU_MIN_SB_BUFFER_SIZE;
   SBC_subband_sample_buffer = bufBase;
   bufBase += 16*2*8;
   SBC_subband_analyzer_state = (SBC_Encoder_State *) bufBase;
   bufBase += (sizeof(SBC_Encoder_State)+1)>>1;
   sbc_Init_Ptr(bufBase);
}

void sbc_Activate(APM_Info *info)
{
   sbc_Init_ZI();
   sbc.src_sample_rate = info->sampleFreq;
   sbc.rampGain = 0;
   if (sbc.frame_state.sampling_frequency >= 32000) {
      sbc.rampFormat = 15;
   } else if ((sbc.frame_state.sampling_frequency >= 16000)) {
      sbc.rampFormat = 14;
   } else {
      sbc.rampFormat = 13;
   }
   
   memset(sbc.preSample, 0, 8*sizeof(short));
   
}

void sbc_Deactivate(void)
{
   if( sbc.aud_id==INVALID_AUDIO_ID )
      return;

   if(KAL_FALSE == kal_if_hisr())
      SBC_TRACE( TRACE_FUNC, L1SBC_ENTER_SBC_CLOSE );

   {
      L1Audio_FreeAudioID(sbc.aud_id);
      sbc.aud_id = INVALID_AUDIO_ID;
      sbc.subband_buffer = 0; // mcu_subband_buffer is invalid after DCM_Unload
   }
   
   if(KAL_FALSE == kal_if_hisr())
      SBC_TRACE( TRACE_INFO, L1SBC_CLOSE_REPORT, sbc.frame_dropped );

#if defined(DSP_SB_LOG)
   {
      STFSAL fHandle;
      kal_int16 drv_letter;
      kal_wchar filename[40];
      drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );
      kal_wsprintf( filename, "%c:\\dsp_sb.bin", (kal_int8)drv_letter );
      ASSERT( FSAL_OK==FSAL_Open( &fHandle, (void *)filename, FSAL_WRITE ) );
      //ASSERT( FSAL_OK==FSAL_Write( &fHandle, (kal_uint8 *)&fixed_wav_hdr, sizeof(struct wav_header) ) );     
      ASSERT( FSAL_OK==FSAL_Write( &fHandle, (kal_uint8 *)&(dsp_sb_buf[dsp_sb_buf_index][0]), (DSP_SB_BUF_LEN-dsp_sb_buf_index)*512 ) );
      if( dsp_sb_buf_index!=0 )
         ASSERT( FSAL_OK==FSAL_Write( &fHandle, (kal_uint8 *)&(dsp_sb_buf[0][0]), dsp_sb_buf_index*512 ) );
      ASSERT( FSAL_OK==FSAL_Close( &fHandle ) );
   }
#endif
}

static void sbc_copyMono2Stereo( SBC_Frame_State *frame )
{
   int blk;
   SB_BUF_T sb_sample_buf = (SB_BUF_T)(frame->sb_sample);

   for (blk = frame->blocks - 1; blk>=0; blk--) {
      memcpy(sb_sample_buf[blk][1], sb_sample_buf[blk][0], 8*sizeof(short));
   }
}


kal_bool sbc_Process(APM_Buffer *buf, APM_Info *info)
{
   kal_uint32 savedMask;
#ifdef _SBC_ENALBLE_DROP_
   int drop_frames;
#endif

   int NUM_FRAME_DATA;
   int UP_SAMPLING_RATE, NUM_UNSAMPLE_DATA;
   int usedLen = 0;
   kal_int16 *pInBuf = buf->inBuf;
   register int data_count;

   if (info->isEOF) {
      return true;
   }

   UP_SAMPLING_RATE = sbc.frame_state.sampling_frequency / sbc.src_sample_rate;

   EXT_ASSERT( (UP_SAMPLING_RATE==1) || (UP_SAMPLING_RATE==2) || (UP_SAMPLING_RATE==4), 
               UP_SAMPLING_RATE, 0, 0 );
   EXT_ASSERT( sbc.frame_state.sampling_frequency == (UP_SAMPLING_RATE*sbc.src_sample_rate),
           sbc.frame_state.sampling_frequency, UP_SAMPLING_RATE, sbc.src_sample_rate );

   data_count = (buf->inBufLen) * UP_SAMPLING_RATE;
   NUM_UNSAMPLE_DATA = NUM_FRAME_DATA = SBC_FRAME_SUBBAND_DATA_SIZE*2;
   
   if (UP_SAMPLING_RATE == 2) {
      NUM_UNSAMPLE_DATA = NUM_FRAME_DATA >> 1;
   } else if (UP_SAMPLING_RATE == 4) {
      NUM_UNSAMPLE_DATA = NUM_FRAME_DATA >> 2;
   }

   if ( !info->isStereo ) {
      data_count = data_count << 1;
      NUM_UNSAMPLE_DATA = NUM_UNSAMPLE_DATA >> 1;
   }


///   SBC_TRACE( TRACE_GROUP_SBC, L1SBC_ENTER_SBC_ENCODING );

   while( data_count>=NUM_FRAME_DATA )
   {
      kal_uint8 *sbc_frame_ptr;

      {
         int frame_len;
         kal_uint32 write_end = sbc.frame_buffer_write + (sbc.current_frame_size+1);
         if( sbc.frame_buffer_write>=sbc.frame_buffer_read )
         {
            if( write_end >= sbc.frame_buffer_length )
            {
               if( sbc.frame_buffer_read<=(sbc.current_frame_size+1) )
               {
                  SBC_TRACE( TRACE_WARNING, L1SBC_FRAME_BUFFER_UNDERRUN );
#ifdef _SBC_ENALBLE_DROP_
                  drop_frames = data_count / NUM_FRAME_DATA;
                  usedLen += drop_frames*NUM_UNSAMPLE_DATA;
                  sbc.frame_dropped += drop_frames;
#else
                  ASSERT( 0 );
#endif
                  break;
               }
               else
               {  // update unfille_pos as write pointer, set write pointer to 0
                  sbc.frame_buffer_unfilled_pos = sbc.frame_buffer_write;
                  sbc.frame_buffer_write = 0;
               }
            }
         }
         else
         {
            if( write_end>=sbc.frame_buffer_read )
            {
               SBC_TRACE( TRACE_WARNING, L1SBC_FRAME_BUFFER_UNDERRUN );
#ifdef _SBC_ENALBLE_DROP_
               drop_frames = data_count / NUM_FRAME_DATA;
               usedLen += drop_frames*NUM_UNSAMPLE_DATA;
               sbc.frame_dropped += drop_frames;
#else
               ASSERT( 0 );
#endif
               break;
            }
         }

         if( info->isStereo )
         {
            if (UP_SAMPLING_RATE == 1) {
               memcpy(sbc.subband_buffer, pInBuf, MCU_MIN_SB_BUFFER_SIZE*sizeof(kal_int16));
            } else {               
               apm_UpsampleStereo(pInBuf, sbc.subband_buffer, sbc.preSample, (NUM_UNSAMPLE_DATA>>1), UP_SAMPLING_RATE);
            }
            
            sbc.frame_state.sb_sample = (short *)SBC_subband_sample_buffer;
            sbc_RampUpSignal(sbc.subband_buffer, sbc.rampFormat, MCU_MIN_SB_BUFFER_SIZE, &sbc.rampGain, 2);
            sbc_analyze_audio( 2, SBC_subband_analyzer_state, &sbc.frame_state, sbc.subband_buffer );
         }
         else
         {
            int numChannels = sbc.frame_state.channels;
            
            sbc.frame_state.sb_sample = (short *)SBC_subband_sample_buffer;
            if (UP_SAMPLING_RATE == 1) {
               // Copy the data from external to internal
               memcpy(sbc.subband_buffer, pInBuf, MCU_MIN_SB_BUFFER_SIZE*sizeof(kal_int16));
            } else {
               apm_UpsampleMono(pInBuf, sbc.subband_buffer, sbc.preSample, NUM_UNSAMPLE_DATA, UP_SAMPLING_RATE);
            }

            sbc.frame_state.channels = 1;
            sbc_RampUpSignal(sbc.subband_buffer, sbc.rampFormat, MCU_MIN_SB_BUFFER_SIZE>>1, &sbc.rampGain, 1);
            sbc_analyze_audio( 1, SBC_subband_analyzer_state, &sbc.frame_state, sbc.subband_buffer );
            sbc.frame_state.channels = numChannels;

            // Copy mono to stereo
            if (numChannels == 2)
               sbc_copyMono2Stereo( &sbc.frame_state );
         }

#if defined(DSP_SB_LOG)
         memcpy( (kal_uint8 *)&(dsp_sb_buf[dsp_sb_buf_index][0]), (kal_uint8 *)sbc.frame_state.sb_sample, 4*128 );
         if( DSP_SB_BUF_LEN==(++dsp_sb_buf_index) )
            dsp_sb_buf_index = 0;
#endif

         sbc_frame_ptr = (kal_uint8 *)sbc.frame_buffer + sbc.frame_buffer_write;

         *sbc_frame_ptr++ = (kal_uint8)sbc.current_frame_size;
         sbc_pack_frame(&sbc.frame_state, sbc_frame_ptr, &frame_len);
         if( frame_len!=sbc.current_frame_size )
         {
            EXT_ASSERT( frame_len == sbc.current_frame_size, frame_len, sbc.current_frame_size, 0 );
         }

         sbc.frame_buffer_write += frame_len+1;
savedMask = SaveAndSetIRQMask();
         sbc.total_payload_size += frame_len;
RestoreIRQMask(savedMask);
         EXT_ASSERT(sbc.total_payload_size <= sbc.frame_buffer_length, sbc.frame_buffer_write, sbc.frame_buffer_read, sbc.frame_buffer_unfilled_pos);
         if( sbc.frame_buffer_unfilled_pos<sbc.frame_buffer_write )
            sbc.frame_buffer_unfilled_pos = sbc.frame_buffer_write;
         if( sbc.frame_buffer_write==sbc.frame_buffer_length )
            sbc.frame_buffer_write = 0;

         sbc.frame_produced ++;
      }
      
      data_count -= NUM_FRAME_DATA;
      pInBuf += NUM_UNSAMPLE_DATA;
      usedLen += NUM_UNSAMPLE_DATA;
      
   }

   SBC_TRACE( TRACE_GROUP_SBC, L1SBC_ENCODER_REPORT, 
      UP_SAMPLING_RATE*usedLen, sbc.total_payload_size, sbc.frame_produced );

   if( sbc.total_payload_size>1024 && sbc.waiting==KAL_FALSE )
   {
      sbc.waiting = KAL_TRUE;
      sbc.callback(A2DP_DATA_NOTIFY, (void*)&sbc.a2dp_codec_hdl);
   }
   
   buf->inBufLen = usedLen;
   buf->outBufLen = usedLen;

   return false;
}

#endif


//============================ A2DP Service ===============================
kal_uint32 SBC_SetQualityLevel(kal_uint32 level)
{
   kal_uint32 result_level = 0;
   switch(level)
   {
      case SBC_BEST_QUALITY:
#if defined(MT6225) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
         {
            max_sbc_bit_rate = 478;
            result_level = SBC_BEST_QUALITY;
            break;
         }
#endif
      case SBC_HIGH_QUALITY:
         {
            max_sbc_bit_rate = 328;
            result_level = SBC_HIGH_QUALITY;
            break;
         }
      case SBC_MID_QUALITY:
         max_sbc_bit_rate = 232;
         result_level = SBC_MID_QUALITY;
         break;
      default:
         EXT_ASSERT(0, level, 0, 0);
         break;
   }
   if( max_sbc_bit_rate>BT_A2DP_MAX_BIT_RATE ) max_sbc_bit_rate = BT_A2DP_MAX_BIT_RATE;
   return result_level;
}

static kal_uint32 sbc_SetBitRate(kal_uint32 bit_rate)
{
   if( bit_rate>max_sbc_bit_rate ) bit_rate = max_sbc_bit_rate;

   bit_rate = sbc_config( NULL, bit_rate );
   return( bit_rate );
}

static kal_uint32 sbc_AdjustBitRateFromQos(kal_uint8 qos) // return adjusted bit rate
{
   kal_uint32 bit_rate_prev = sbc.current_bit_rate;;

///   SBC_TRACE( TRACE_FUNC, L1SBC_ENTER_SBC_ADJUSTBITRATEFROMQOS );

#if defined(__BTMTK__) && !defined(_SBC_DEBUG_NO_QOS_)
   sbc.current_bit_rate = bt_a2dp_alg_set_bit_rate_from_qos( qos, sbc.current_bit_rate, sbc_SetBitRate );
#ifdef SBC_DEBUG_QOS
   qos_log[qos_log_idx].qos_value = qos;
   qos_log[qos_log_idx].bitrate_old = bit_rate_prev;
   qos_log[qos_log_idx].bitrate_new = sbc.current_bit_rate;
   if( ++qos_log_idx==(sizeof(qos_log)/sizeof(qos_log[0])) ) qos_log_idx = 0;
#endif
#endif

   SBC_TRACE( TRACE_INFO, L1SBC_QOS_REPORT, 
      qos, bit_rate_prev, sbc.current_bit_rate );

   return( sbc.current_bit_rate );
}

static void sbc_QueryPayloadSize(uint32 *min, uint32 *total)
{
   SBC_TRACE( TRACE_GROUP_SBC, L1SBC_ENTER_SBC_QUERYPAYLOADSIZE );
   if( sbc.subband_buffer==0 || sbc.total_payload_size == 0) // sbc is closed or no data
   {
      *min = *total = 0;
      return;
   }
   {
      if( sbc.fragment_flag==KAL_TRUE )
      {
         *min = *total = 1 + (sbc.fragment_size>sbc.fragment_left_bytes)? 
                              sbc.fragment_left_bytes: 
                              sbc.fragment_size; // fixed payload size, 1 is for payload header
      }
      else
      {
         if( sbc.frame_buffer_read==sbc.frame_buffer_unfilled_pos && 
             sbc.frame_buffer_write<sbc.frame_buffer_unfilled_pos )
            sbc.frame_buffer_read = 0;
         *min = 1 + sbc.frame_buffer[sbc.frame_buffer_read];  // 1 is for payload header
         *total = 1 + sbc.total_payload_size;
      }
   }
}

static uint32 sbc_GetPayload(uint8 *buf , uint32 buf_len, uint32 *sample_cnt)
{
   register kal_uint8 *ptr_src, *ptr_des;
   int data_cnt, frame_cnt;
   int req_buf_len;
   kal_uint32 savedMask;

///   SBC_TRACE( TRACE_GROUP_SBC, L1SBC_ENTER_SBC_GETPAYLOAD );
   if( ( sbc.aud_id == INVALID_AUDIO_ID ) || 
       (sbc.subband_buffer == 0) || 
       (sbc.total_payload_size == 0) || 
       (sbc.frame_buffer_write == sbc.frame_buffer_read)) // sbc is closed or no data
   {
      *sample_cnt = 0;
      sbc.waiting = KAL_FALSE;
      return 0;
   }
   req_buf_len = buf_len;
   ptr_des = buf+1;
   buf_len -= 1; // reserved for payload header
   
   data_cnt = 0;
   frame_cnt = 0;
   *sample_cnt = 0;

   {
      if( sbc.fragment_flag==KAL_TRUE )
      { // continue and end fragment
         int payload_len;
         
         if(sbc.fragment_left_bytes >= sbc.fragment_size)
            payload_len = sbc.fragment_size;
         else
            payload_len = sbc.fragment_left_bytes;
      
         if(buf_len >= payload_len)
         {
            int I;
            
            ptr_src = sbc.fragment_start;
            sbc.fragment_left --;
            
            for( I=payload_len; --I>=0; )
               ptr_des[I] = ptr_src[I];
            ptr_des += payload_len;
            ptr_src += payload_len;
      
            sbc.fragment_start = ptr_src;
            sbc.fragment_left_bytes -= payload_len;
            data_cnt = payload_len;
savedMask = SaveAndSetIRQMask();
            sbc.total_payload_size -= data_cnt;
RestoreIRQMask(savedMask);
            sbc.frame_buffer_read += payload_len;
            
            if(sbc.fragment_left == 1)
            {
               if( sbc.fragment_left_bytes!=0 )
               {
                  ASSERT( 0 ); // there should be no data left
               }
               if( sbc.frame_buffer_read==sbc.frame_buffer_unfilled_pos &&
                   sbc.frame_buffer_write<sbc.frame_buffer_unfilled_pos )
                  sbc.frame_buffer_read = 0;
               if( sbc.frame_buffer_read>sbc.frame_buffer_unfilled_pos )
               {
                  ASSERT( 0 ); // read ptr shall not exceed unfilled_pos
               }
               
               sbc.fragment_flag = KAL_FALSE;
               
               *buf = 0xA0 + sbc.fragment_left;
               *sample_cnt = SBC_FRAME_SUBBAND_DATA_SIZE;
               frame_cnt = 1; // consume 1 frame  
               sbc.frame_consumed ++;
            }
            else
            {
               *buf = 0x80 + sbc.fragment_left;
               *sample_cnt = 0;
            }
      
         }
         else
         {
            ASSERT(0); // request not enough buf_len
         }
      }
      else
      {
         kal_bool bAllowFragment;
         int frame_len;
      
         bAllowFragment = KAL_TRUE;
         while(1)
         {
            if( sbc.frame_buffer_read==sbc.frame_buffer_unfilled_pos &&
                sbc.frame_buffer_write<sbc.frame_buffer_unfilled_pos )
               sbc.frame_buffer_read = 0;
            ptr_src = sbc.frame_buffer + sbc.frame_buffer_read;
            frame_len = *ptr_src++;

            EXT_ASSERT(*ptr_src == 0x9c, *ptr_src, frame_len, sbc.total_payload_size);
            if(buf_len >= frame_len)
            {
               int I;
               
               bAllowFragment = KAL_FALSE;
               
               for( I=frame_len; --I>=0; )
                  ptr_des[I] = ptr_src[I];
               ptr_des += frame_len;
               ptr_src += frame_len;
      
               buf_len -= frame_len;
               data_cnt += frame_len;
savedMask = SaveAndSetIRQMask();
               sbc.total_payload_size -= frame_len;
               if((sbc.frame_buffer_write == sbc.frame_buffer_read) && 
                  (sbc.total_payload_size != 0))
               {
                  //kal_prompt_trace(MOD_L1SP, "SBC WARN: r=w=%d, plsz=%d", sbc.frame_buffer_write, sbc.total_payload_size);
                  sbc.total_payload_size = 0;
               }
RestoreIRQMask(savedMask);
               sbc.frame_buffer_read += 1 + frame_len;
               if( sbc.frame_buffer_read==sbc.frame_buffer_unfilled_pos && 
                   sbc.frame_buffer_write<sbc.frame_buffer_unfilled_pos )
                  sbc.frame_buffer_read = 0;
               if( sbc.frame_buffer_read>sbc.frame_buffer_unfilled_pos )
               {
                  EXT_ASSERT( sbc.frame_buffer_read <= sbc.frame_buffer_unfilled_pos,
                              sbc.frame_buffer_read, sbc.frame_buffer_unfilled_pos, frame_len); // read ptr shall not exceed unfilled_pos
               }
               
               frame_cnt += 1;
               sbc.frame_consumed ++;
               
               if( (frame_cnt == 15) || 
                   (sbc.total_payload_size == 0))
               { // last frame
                  *buf = frame_cnt; // store payload header
                  *sample_cnt = frame_cnt * SBC_FRAME_SUBBAND_DATA_SIZE;
                  break;
               }
            }
            else
            {
               if( bAllowFragment==KAL_TRUE )
               { // start fragment
                  if( (buf_len*15) >= frame_len)
                  {
                     int I;
                     
                     ASSERT( *ptr_src == 0x9C ); // check SBC frame header
                     sbc.fragment_flag = KAL_TRUE;
                     sbc.fragment_size = buf_len;
                     sbc.fragment_left = (kal_uint8)((frame_len + buf_len - 1)/buf_len);
                     
                     for( I=buf_len; --I>=0; )
                        ptr_des[I] = ptr_src[I];
                     ptr_des += buf_len;
                     ptr_src += buf_len;
      
                     sbc.fragment_start = ptr_src;
                     sbc.fragment_left_bytes = frame_len - sbc.fragment_size;
      
                     data_cnt = buf_len; // it shall be equivalent to sbc.fragment_size here
savedMask = SaveAndSetIRQMask();
                     sbc.total_payload_size -= data_cnt;
RestoreIRQMask(savedMask);
                     sbc.frame_buffer_read += 1 + buf_len;
                     
                     *buf = 0xC0 + sbc.fragment_left;
                     *sample_cnt = 0;
                  }
                  else
                  {
                     ASSERT(0); // request less data than minimum
                  }
               }
               else
               { // last frame
                  *buf = frame_cnt; // store payload header
                  *sample_cnt = frame_cnt * SBC_FRAME_SUBBAND_DATA_SIZE;
               }
               break;
            }
         }
      }
      
      if(data_cnt != 0)
      {
         data_cnt += 1;
      }
   }

   SBC_TRACE( TRACE_GROUP_SBC, L1SBC_PAYLOAD_REPORT, req_buf_len, data_cnt, frame_cnt , sbc.total_payload_size );

   // sbc.waiting = KAL_FALSE;
   return( data_cnt );
}

static void sbc_GetPayloadDone()
{
   sbc.waiting = KAL_FALSE;
}

/* SBC driver interface */

void SBC_Init()
{
   memset( &sbc, 0, sizeof(sbc) );
   sbc.aud_id = INVALID_AUDIO_ID;
   sbc.current_bit_rate = 520;
   SBC_SetQualityLevel(SBC_BEST_QUALITY);
}

kal_uint32 SBC_GetMemReq(void)
{
   SBC_TRACE( TRACE_FUNC, L1SBC_ENTER_SBC_GETMEMREQ );
   return 8*1024; // recommended minimum sbc frame buffer length , it is adjustable
}

A2DP_codec_struct *SBC_Open(
   Media_Format aud_fmt, 
   A2DP_Callback pHandler, 
   bt_a2dp_sbc_codec_cap_struct *sbc_config_data, 
   kal_uint8 *buf, 
   kal_uint32 buf_len )
{
   SBC_TRACE( TRACE_FUNC, L1SBC_ENTER_SBC_OPEN );
   EXT_ASSERT( buf_len>=SBC_GetMemReq(), buf_len, 0, 0 );
   EXT_ASSERT( 0 == DP_SB_CTRL, DP_SB_CTRL, 0, 0 );

#if defined(DSP_SB_LOG)
   memset( (kal_uint8 *)dsp_sb_buf, 0x0, DSP_SB_BUF_LEN*512 );
   dsp_sb_buf_index = 0;
#endif
#ifdef SBC_DEBUG_QOS
   qos_log_idx = 0;
   memset( (void *)&qos_log, 0, sizeof(qos_log) );
#endif

   {
      kal_uint32 bit_rate;

#if !APM_SUPPORT
      if( !DCM_Isloaded( DYNAMIC_CODE_SBC ) )
         DCM_Load( DYNAMIC_CODE_SBC, 0, 0 );
#endif

      sbc.aud_id = L1Audio_GetAudioID();
      sbc.a2dp_codec_hdl.GetPayload = sbc_GetPayload;
      sbc.a2dp_codec_hdl.GetPayloadDone = sbc_GetPayloadDone;
      sbc.a2dp_codec_hdl.QueryPayloadSize = sbc_QueryPayloadSize;
      sbc.a2dp_codec_hdl.AdjustBitRateFromQos = sbc_AdjustBitRateFromQos;
      sbc.a2dp_codec_hdl.SetBitRate = sbc_SetBitRate;

      sbc.callback = pHandler;
      sbc.waiting = KAL_FALSE;
      
      sbc.subband_buffer = mcu_subband_buffer; // mcu_subband_buffer is vaild after DCM_Load
      sbc.subband_buffer_read = 0;
      sbc.subband_buffer_write = 0;
      
      sbc.frame_buffer = buf;
      sbc.frame_buffer_write = 0;
      sbc.frame_buffer_read = 0;
      sbc.frame_buffer_length = buf_len;
      sbc.frame_buffer_unfilled_pos = sbc.frame_buffer_length;
      
#if APM_SUPPORT
      memset(sbc.preSample, 0, 8*sizeof(kal_int16));
      sbc.subband_analyzer_on = KAL_TRUE;
#else
      sbc.subband_analyzer_on = KAL_FALSE;
#endif

      bit_rate = sbc_initiate_bit_rate( sbc_config_data->channel_mode, sbc_config_data->sample_rate, aud_fmt );
      { // take previous status as reference
         if( sbc.frame_state.sampling_frequency >= 44100 && 
             sbc.frame_state.channels == 2 &&
             sbc.current_bit_rate < bit_rate &&
             sbc.aud_fmt != SBC_WAV_FORMAT )
         {
            bit_rate = sbc.current_bit_rate;
         }
      }
#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6223) || defined(MT6223P)
      if( (aud_fmt==MEDIA_FORMAT_WAV) ||
          (aud_fmt==MEDIA_FORMAT_AU) ||
          (aud_fmt==MEDIA_FORMAT_AIFF) )
      {
         sbc.a2dp_codec_hdl.state = 1;
         sbc.aud_fmt = SBC_WAV_FORMAT;
      }
      else
#endif
      {
         sbc.a2dp_codec_hdl.state = 0;
         sbc.aud_fmt = aud_fmt;
      }
   
      sbc.current_bit_rate = sbc_config( sbc_config_data, bit_rate ); // sbc.current_frame_size shall be set here
#if defined(__BTMTK__) && !defined(_SBC_DEBUG_NO_QOS_)
      bt_a2dp_alg_set_bit_rate_from_qos_init( sbc.current_bit_rate );
#endif
      
      sbc.total_payload_size = 0;
      
      sbc.fragment_flag = KAL_FALSE;
      sbc.fragment_start = NULL;
      sbc.fragment_left = 0;
      sbc.fragment_left_bytes = 0;
      sbc.fragment_size = 0;

      sbc.frame_produced = 0;
      sbc.frame_consumed = 0;
      sbc.frame_dropped = 0;

#if APM_SUPPORT
      HOST_APM_Register(APM_TASKID_SBC);
#elif defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6223) || defined(MT6223P)
      L1Audio_SetEventHandler(sbc.aud_id, sbc_event_handler);
      L1Audio_HookHisrHandler( D2C_MAGIC_NO_SBC, (L1Audio_EventHandler)sbc_hisr, 0 );

#if defined(MT6223) || defined(MT6223P)
      DP_SB_READ = 0xA4BC;
      DP_SB_WRITE = 0xA4BC;
#endif

      DP_SB_CTRL = 1;
#endif

   }
   SBC_TRACE( TRACE_INFO, L1SBC_OPEN_REPORT, 
      sbc.aud_id, sbc.current_bit_rate, ((sbc.subband_analyzer_on)? 1: 0), sbc.aud_fmt );
   return &sbc.a2dp_codec_hdl;
}

#if APM_SUPPORT

void SBC_Close(void)
{
   HOST_APM_UnRegister(APM_TASKID_SBC);
}

#else

void SBC_Close(void)
{
   uint16 aud_id;
   kal_uint32 mask;
   
   mask = SaveAndSetIRQMask();
   aud_id = sbc.aud_id;
   sbc.aud_id = INVALID_AUDIO_ID;
   RestoreIRQMask(mask);

   if( aud_id==INVALID_AUDIO_ID )
      return;

   if(KAL_FALSE == kal_if_hisr())
      SBC_TRACE( TRACE_FUNC, L1SBC_ENTER_SBC_CLOSE );

   {
      L1Audio_UnhookHisrHandler(D2C_MAGIC_NO_SBC);
      DP_SB_CTRL = 0;

      if(KAL_FALSE == kal_if_hisr())
         kal_sleep_task(87); // about 400ms, delay to let DSP clear aacPlus buffer

      DP_SB_READ = 0;
      DP_SB_WRITE = 0;

      L1Audio_FreeAudioID(aud_id);
      sbc.subband_buffer = 0; // mcu_subband_buffer is invalid after DCM_Unload

      if( DCM_Isloaded( DYNAMIC_CODE_SBC ) )
         DCM_Unload(DYNAMIC_CODE_SBC);
   }
   
   if(KAL_FALSE == kal_if_hisr())
      SBC_TRACE( TRACE_INFO, L1SBC_CLOSE_REPORT, sbc.frame_dropped );

#if defined(DSP_SB_LOG)
   {
      STFSAL fHandle;
      kal_int16 drv_letter;
      kal_wchar filename[40];
      drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );
      kal_wsprintf( filename, "%c:\\dsp_sb.bin", (kal_int8)drv_letter );
      ASSERT( FSAL_OK==FSAL_Open( &fHandle, (void *)filename, FSAL_WRITE ) );
      //ASSERT( FSAL_OK==FSAL_Write( &fHandle, (kal_uint8 *)&fixed_wav_hdr, sizeof(struct wav_header) ) );     
      ASSERT( FSAL_OK==FSAL_Write( &fHandle, (kal_uint8 *)&(dsp_sb_buf[dsp_sb_buf_index][0]), (DSP_SB_BUF_LEN-dsp_sb_buf_index)*512 ) );
      if( dsp_sb_buf_index!=0 )
         ASSERT( FSAL_OK==FSAL_Write( &fHandle, (kal_uint8 *)&(dsp_sb_buf[0][0]), dsp_sb_buf_index*512 ) );
      ASSERT( FSAL_OK==FSAL_Close( &fHandle ) );
   }
#endif
}
#endif

#if defined(SBC_UNIT_TEST)
#define SIZE_TASK_BUFFER2    128*1024
static kal_uint8 task_buffer1[8192];
static kal_uint8 task_buffer2[SIZE_TASK_BUFFER2]; // 1MB
static kal_uint8 task_buffer3[512];
static kal_uint32 task_buffer2_index;
static A2DP_codec_struct *sbc_handle = 0;
static bt_a2dp_sbc_codec_cap_struct sbc_config_data = {
      10, // min_bit_pool
      47, // max_bit_pool
      0x1, // block_len: 16 only
      0x1, // subband_num: 8 only
      0x1, // alloc_method: loudness only
      0x2, // sample_rate: 44.1Ksps
      0x1, // channel_mode: joint-stereo
};

void _sbc_unit_test_( kal_uint32 data );

static void _sbc_ut_callback( A2DP_Event event, void *data )
{
   if( event==A2DP_DATA_NOTIFY )
   {
      kal_uint32 min, nBytes, nSamples;

      sbc.waiting = KAL_FALSE;
      
      while( 1 )
      {
         kal_uint32 count, count2;

         sbc_handle->QueryPayloadSize( &min, &nBytes );
         count = nBytes;

         if( count>512 ) // assume maximum 512 bytes per packet
            count  = 512;
         else if ( count<512 )
            break;
         count = sbc_handle->GetPayload( task_buffer3, count, &nSamples );
         nBytes -= count;

         if( SIZE_TASK_BUFFER2>512 )
         {
            count -= 1;
            if( (count2=SIZE_TASK_BUFFER2-task_buffer2_index)>count )
               count2 = count;
            memcpy( &task_buffer2[task_buffer2_index], task_buffer3+1, count2 );
            count -= count2;
            task_buffer2_index += count2;
            if( task_buffer2_index==SIZE_TASK_BUFFER2 )
               task_buffer2_index = 0;
   
            if( count>0 )
               memcpy( &task_buffer2[task_buffer2_index], task_buffer3+1+count2, count );
            task_buffer2_index += count;
         }
      }
      if( (kal_uint32)data==0 )
         return;
   }
   else
      ASSERT( 0 );

   // stop
   _sbc_unit_test_(0);
}

static kal_bool is_test_qos = KAL_FALSE;
void _sbc_unit_test_( kal_uint32 data )
{
   if( data ) // start
   {
      if( sbc_handle!=0 )
         return;

      { // check memory request
         kal_uint32 buf_len;
         buf_len = SBC_GetMemReq();
      }

      memset( task_buffer2, 0x0, SIZE_TASK_BUFFER2 );
      task_buffer2_index = 0;

      sbc_handle = SBC_Open( _sbc_ut_callback, &sbc_config_data, task_buffer1, 8192 );
#if IS_EV_BOARD
      AFE_MuteSpeaker( L1SP_SPEECH, KAL_FALSE );
#else
      AFE_MuteSpeaker( L1SP_MEDIA, KAL_FALSE );
#endif

   }
   else // stop
   {
      if( sbc_handle==0 )
         return;
      
      SBC_Close();
      
      sbc_handle = 0;
      if( SIZE_TASK_BUFFER2>512 )
      { // open storage
         STFSAL fHandle;
         kal_int16 drv_letter;
         kal_wchar filename[40];
         drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );
         kal_wsprintf( filename, "%c:\\a2dp_pl.sbc", drv_letter );
         ASSERT( FSAL_OK==FSAL_Open( &fHandle, (void *)filename, FSAL_WRITE ) );
         ASSERT( FSAL_OK==FSAL_Write( &fHandle, &task_buffer2[task_buffer2_index], SIZE_TASK_BUFFER2-task_buffer2_index ) );
         if( task_buffer2_index!=0 )
            ASSERT( FSAL_OK==FSAL_Write( &fHandle, &task_buffer2[0], task_buffer2_index ) );
         ASSERT( FSAL_OK==FSAL_Close( &fHandle ) );
      }
   }
}
#endif
#endif // ...defined(__BT_A2DP_SUPPORT__) || defined(SBC_UNIT_TEST)

