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
 *   RTPCodec.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Part of VoRTP driver, including voice codec adaptation layer
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
#include "VoRTP.h"
#include "PCMRB.h"
#include "RTPCodec.h"
#if !defined(SIM_ON_VC)
#include "dcmgr.h"
#endif

#if VORTP_SUPPORT || defined(VORTP_UNIT_TEST)
/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define USE_FAST_MEMORY
/* On MT6228/MT6229, the fast memory for codec is in internal ram 
 * On MT6225, the fast memory for codec is in code-cacheable external ram
 */

#if defined(DYNAMIC_CODE_MANAGER)
#define FAST_MEM_SIZE              DCM_TARGET_SIZE1
#else
#define FAST_MEM_SIZE              20480
#endif
#define G7231_SUPPORT                   1

#define CN_GAIN_G729                    2 /* -66dB */
#define CN_GAIN_G7231                   2 /* -66dB */
#define CN_GAIN_G711                    72 /* -66dB */

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/

/*****************************************************************************
*                       P R I V A T E   D A T A
******************************************************************************
*/
#if defined(USE_FAST_MEMORY)
#if __CC_ARM
#pragma arm section zidata="G729_DYNAMIC_ZI"
#endif
static kal_uint8 RTPCodec_Buffer_Pool[FAST_MEM_SIZE];
#if __CC_ARM
#pragma arm section zidata
#endif

static struct {
   kal_uint8        *shared_buffer;
   kal_uint32       shared_buffer_size;
   kal_uint8        *internal_buffer[4];
   kal_uint32       internal_buffer_size;
   kal_uint32       numUsers;
} rtp_codec_buffer_usage;
#endif

static struct RTPCodecUsage_Struct {
   kal_uint8        numEncodersUsingG729;
   kal_uint8        numDecodersUsingG729;
   kal_uint8        numEncodersUsingG7231;
   kal_uint8        numDecodersUsingG7231;
   kal_uint8        numEncodersUsingG726;
   kal_uint8        numDecodersUsingG726;
   
   kal_uint8        num_non_g711_codec_opened;
   kal_uint8        num_non_g711_g726_codec_opened;
} rtp_codec_usage;

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/

/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/
#if defined(SIM_ON_VC)
extern void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size );
extern void DCM_Unload( kal_int32 dynamic_code_id );
#endif

/*****************************************************************************
*                          F U N C T I O N S
******************************************************************************
*/
/*****************************************************************************
 * FUNCTION
 *   alloc_rtp_codec_buffer
 * DESCRIPTION
 *   This function allocates working buffer from TCM or external for RTP codec.
 * PARAMETERS
 *   size           [IN]      The acquired buffer size
 * RETURNS
 *   kal_uint8 *              The buffer address of allocated
 *****************************************************************************
 */
static kal_uint8 * alloc_rtp_codec_buffer(kal_uint32 size)
{
   kal_uint8 *buf;
#if defined(USE_FAST_MEMORY)
   int i;

   if( size <= rtp_codec_buffer_usage.internal_buffer_size )
   {
      for(i=0; i<4; i++)
      {
         buf = rtp_codec_buffer_usage.internal_buffer[i];
         if( ((kal_uint32)buf & 1) == 0 )
         {
            kal_uint32 *remaining_buf;
            kal_uint32 buf_size;
            rtp_codec_buffer_usage.internal_buffer[i] = (kal_uint8 *)((kal_uint32)(rtp_codec_buffer_usage.internal_buffer[i]) | 1); // set as dirty
#if defined(DYNAMIC_CODE_MANAGER)
            if( rtp_codec_buffer_usage.numUsers == 0 )
               DCM_Load( DYNAMIC_CODE_G729, &remaining_buf, &buf_size );
#endif
            rtp_codec_buffer_usage.numUsers ++;
            memset(buf, 0, size);
            return buf;
         }
      }
   }
#endif

#ifdef NOT_TO_ALLOC_CODEC_BUF_FROM_EXT
   EXT_ASSERT(0, size, rtp_codec_buffer_usage.numUsers, 0);
#else
   // get external buffer
   buf = (kal_uint8 *)med_alloc_ext_mem(size);
   RTP_ASSERT(buf != NULL);
#endif

   return buf;
}

/*****************************************************************************
 * FUNCTION
 *   free_rtp_codec_buffer
 * DESCRIPTION
 *   This function frees working buffer allocated before.
 * PARAMETERS
 *   buf            [IN]      The address of allocated buffer pointer
 * RETURNS
 *   void
 *****************************************************************************
 */
static void free_rtp_codec_buffer(kal_uint8 **ppBuf)
{
#if defined(USE_FAST_MEMORY)
   kal_uint32 ptr;
   int i;

   for(i=0; i<4; i++)
   {
      ptr = (kal_uint32)(rtp_codec_buffer_usage.internal_buffer[i]);
      if( (ptr & (~1)) == (kal_uint32)*ppBuf )
      {
         RTP_ASSERT( (ptr & 1) == 1);
            rtp_codec_buffer_usage.internal_buffer[i] = (kal_uint8 *)((kal_uint32)(rtp_codec_buffer_usage.internal_buffer[i]) & (~1)); // set as clean
         rtp_codec_buffer_usage.numUsers --;
#if defined(DYNAMIC_CODE_MANAGER)
         if( rtp_codec_buffer_usage.numUsers == 0 )
            DCM_Unload(DYNAMIC_CODE_G729);
#endif
         *ppBuf = NULL;
         return;
      }
   }
#endif

#ifdef NOT_TO_ALLOC_CODEC_BUF_FROM_EXT
   EXT_ASSERT(0, 0, rtp_codec_buffer_usage.numUsers, 0);
#else
   // free external buffer
   med_free_ext_mem((void **)ppBuf);
#endif

   return;
}

#define RTPCodecInterface
/*****************************************************************************
 * FUNCTION
 *   RTPCodec_GetAvailableCodecs
 * DESCRIPTION
 *   This function get the current available codec for use.
 *   Considered of MCU loading, on MT6228/29/25, more than one g729+g7231 is prohibited.
 * PARAMETERS
 *   handle         [IN]      The acquired handle
 *   alt_codec_type [IN]      The codec type to be alternated
 * RETURNS
 *   rtp_audio_codec_type     The or-ed codec type enum
 *****************************************************************************
 */
rtp_audio_codec_type RTPCodec_GetAvailableCodecs( RTP_CODEC_HANDLE *handle, rtp_audio_codec_type *alt_codec_type )
{
   rtp_audio_codec_type available_codecs;
   struct RTPCodecUsage_Struct *usage = &rtp_codec_usage;

   if( alt_codec_type!=NULL )
   {
      usage = get_ctrl_buffer(sizeof(struct RTPCodecUsage_Struct));
      memcpy( usage, &rtp_codec_usage, sizeof(struct RTPCodecUsage_Struct) );
      if( (*alt_codec_type) | RTP_AUDIO_G729 )
      {
         usage->numEncodersUsingG729--;
         usage->numDecodersUsingG729--;
      }
      else if( (*alt_codec_type) | RTP_AUDIO_G7231 )
      {
         usage->numEncodersUsingG7231--;
         usage->numDecodersUsingG7231--;
      }
      else if( (*alt_codec_type) | (RTP_AUDIO_G726_16 | RTP_AUDIO_G726_24 | RTP_AUDIO_G726_32 | RTP_AUDIO_G726_40) )
      {
         usage->numEncodersUsingG726--;
         usage->numDecodersUsingG726--;
      }
   }

   if( (usage->numEncodersUsingG7231+usage->numDecodersUsingG7231)>0 )
   {
      available_codecs = RTP_AUDIO_PCMA | RTP_AUDIO_PCMU;
   }
   else if( (usage->numEncodersUsingG729+usage->numDecodersUsingG729)>0 )
   {
      available_codecs = RTP_AUDIO_PCMA | RTP_AUDIO_PCMU;
   }
   else if( (usage->numEncodersUsingG726+usage->numDecodersUsingG726)>0 )
   {
      available_codecs = RTP_AUDIO_PCMA | RTP_AUDIO_PCMU;
   }
   else
   {
      available_codecs = RTP_AUDIO_G729 | RTP_AUDIO_G7231 |
         RTP_AUDIO_G726_16 | RTP_AUDIO_G726_24 | RTP_AUDIO_G726_32 | RTP_AUDIO_G726_40 |
         RTP_AUDIO_PCMA | RTP_AUDIO_PCMU;
   }

#if !G7231_SUPPORT
   available_codecs &= ~RTP_AUDIO_G7231;
#endif

   if( alt_codec_type!=NULL )
      free_ctrl_buffer( usage );

   return available_codecs;
}

/*****************************************************************************
 * FUNCTION
 *   RTPCodec_GetCodecCapability
 * DESCRIPTION
 *   This function get the capability currently supported.
 * PARAMETERS
 *   handle         [IN]      The acquired handle
 *   codec_type     [IN]      The acquired codec type
 *   codec_cap      [OUT]     The storage for acquired capability
 *   alternated     [IN]      The flag to imply whether the acquired handle will be alternated after
 * RETURNS
 *   rtp_audio_codec_type     The or-ed codec type enum
 *****************************************************************************
 */
kal_bool RTPCodec_GetCodecCapability( RTP_CODEC_HANDLE *handle, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap, kal_bool alternated )
{
   RTP_AUDIO_CAP config;

   switch( codec_type )
   {
      case RTP_AUDIO_PCMA: case RTP_AUDIO_PCMU:
         config.codec_cap.g711.rate = G711_RATE_8000;
         config.codec_cap.g711.channel = 1;
         config.codec_cap.g711.ptime = 10;
         config.codec_cap.g711.maxptime = 20;
         config.codec_cap.g711.cn_payload = RTP_CODEC_SUPPORT;
         break;
      case RTP_AUDIO_G726_16: case RTP_AUDIO_G726_24: 
      case RTP_AUDIO_G726_32: case RTP_AUDIO_G726_40:
         config.codec_cap.g726.ptime = 10;
         config.codec_cap.g726.maxptime = 30;
         config.codec_cap.g726.cn_payload = RTP_CODEC_SUPPORT;
         break;
      case RTP_AUDIO_G729:
         config.codec_cap.g729.ptime = 20;
         config.codec_cap.g729.maxptime = 60;
         config.codec_cap.g729.annexb = RTP_CODEC_SUPPORT;
         break;
      case RTP_AUDIO_G7231:
#if G7231_SUPPORT
         config.codec_cap.g7231.ptime = 30;
         config.codec_cap.g7231.maxptime = 60;
         config.codec_cap.g7231.bitrate = RTP_CAP_UNSPECIFIED;
         config.codec_cap.g7231.annexa = RTP_CODEC_SUPPORT;
         break;
#endif
      default: // invalid/multiple codec type
         return KAL_FALSE;
   }

   config.codec_type = codec_type;
   memcpy( codec_cap, &config.codec_cap, sizeof(rtp_audio_codec_cap) );
   
   return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *   RTPCodec_Register
 * DESCRIPTION
 *   This function registers the usage of the assigned codec type and capability to the acquired 
 *   handle.
 * PARAMETERS
 *   handle         [INOUT]   The acquired handle
 *   dir            [IN]      The flag to determine whether this is for downlink or uplink
 *   codec_type     [IN]      The assigned codec type
 *   codec_cap      [IN]      The assigned codec capability
 * RETURNS
 *   kal_bool                 Result of the registration
 *****************************************************************************
 */
kal_bool RTPCodec_Register( RTP_CODEC_HANDLE *handle, kal_uint8 dir, rtp_audio_codec_type codec_type, rtp_audio_codec_cap *codec_cap )
{
   kal_bool is_encoder;
   RTP_AUDIO_CAP *config = &handle->config; // preset by master
   RTP_CODEC_PARA *codec_para;
   kal_int32 codec_bitrate = 0, maxptime = 0;

   RTP_ASSERT( handle!=NULL );

   handle->dir = dir;
   is_encoder = ( dir==RTP_DIR_UL )? KAL_TRUE: KAL_FALSE;
   config->codec_type = codec_type;
   switch( codec_type )
   {
      case RTP_AUDIO_PCMA: case RTP_AUDIO_PCMU:
         config->codec_cap_length = sizeof(rtp_audio_g711_cap_struct);
         handle->para = &rtp_g711_para;
         break;
      case RTP_AUDIO_G726_16: case RTP_AUDIO_G726_24:
      case RTP_AUDIO_G726_32: case RTP_AUDIO_G726_40:
         config->codec_cap_length = sizeof(rtp_audio_g726_cap_struct);
         handle->para = &rtp_g726_para;
         
         if(is_encoder)
         {
            RTP_ASSERT(rtp_codec_usage.numEncodersUsingG726  == 0);
            rtp_codec_usage.numEncodersUsingG726 ++;
         }
         else
         {
            RTP_ASSERT(rtp_codec_usage.numDecodersUsingG726 == 0);
            rtp_codec_usage.numDecodersUsingG726 ++;
         }
         break;
      case RTP_AUDIO_G729:
         config->codec_cap_length = sizeof(rtp_audio_g729_cap_struct);
         handle->para = &rtp_g729_para;
         if(is_encoder)
         {
            RTP_ASSERT(rtp_codec_usage.numEncodersUsingG729 == 0);
            rtp_codec_usage.numEncodersUsingG729 ++;
         }
         else
         {
            RTP_ASSERT(rtp_codec_usage.numDecodersUsingG729 == 0);
            rtp_codec_usage.numDecodersUsingG729 ++;
         }
         break;
      case RTP_AUDIO_G7231:
#if G7231_SUPPORT
         config->codec_cap_length = sizeof(rtp_audio_g7231_cap_struct);
         handle->para = &rtp_g7231_para;
         if(is_encoder)
         {
            RTP_ASSERT(rtp_codec_usage.numEncodersUsingG7231 == 0);
            rtp_codec_usage.numEncodersUsingG7231 ++;
         }
         else
         {
            RTP_ASSERT(rtp_codec_usage.numDecodersUsingG7231 == 0);
            rtp_codec_usage.numDecodersUsingG7231 ++;
         }
         break;
#endif
      default:
         RTP_ASSERT( 0 );
         return KAL_FALSE;
   }
   codec_para = (RTP_CODEC_PARA *)handle->para;

   memcpy( &config->codec_cap, codec_cap, sizeof(rtp_audio_codec_cap) );
   switch( config->codec_type )
   {
      case RTP_AUDIO_PCMA: 
         codec_bitrate = 64000;
         kal_sprintf(handle->name_str, "PCMA %c %d", 
            (codec_cap->g711.cn_payload==RTP_CODEC_SUPPORT)? 'y': 'n', 
            config->codec_cap.g711.ptime );
         kal_prompt_trace(MOD_L1SP, "g711 cn=%d\n", codec_cap->g711.cn_payload);
         break;
      case RTP_AUDIO_PCMU:
         codec_bitrate = 64000;
         kal_sprintf(handle->name_str, "PCMU %c %d", 
            (codec_cap->g711.cn_payload==RTP_CODEC_SUPPORT)? 'y': 'n', 
            config->codec_cap.g711.ptime );
         kal_prompt_trace(MOD_L1SP, "g711 cn=%d\n", codec_cap->g711.cn_payload);
         break;
      case RTP_AUDIO_G726_16:
         codec_bitrate = 16000;
         kal_sprintf(handle->name_str, "G726_16 %c %d", 
            (codec_cap->g726.cn_payload==RTP_CODEC_SUPPORT)? 'y': 'n', 
            config->codec_cap.g726.ptime );
         kal_prompt_trace(MOD_L1SP, "g726_16 cn=%d\n", codec_cap->g726.cn_payload);
          break;
      case RTP_AUDIO_G726_24:
         codec_bitrate = 24000;
         kal_sprintf(handle->name_str, "G726_24 %c %d", 
            (codec_cap->g726.cn_payload==RTP_CODEC_SUPPORT)? 'y': 'n', 
            config->codec_cap.g726.ptime );
         kal_prompt_trace(MOD_L1SP, "g726_24 cn=%d\n", codec_cap->g726.cn_payload);
          break;
      case RTP_AUDIO_G726_32:
         codec_bitrate = 32000;
         kal_sprintf(handle->name_str, "G726_32 %c %d", 
            (codec_cap->g726.cn_payload==RTP_CODEC_SUPPORT)? 'y': 'n', 
            config->codec_cap.g726.ptime );
         kal_prompt_trace(MOD_L1SP, "g726_32 cn=%d\n", codec_cap->g726.cn_payload);
          break;
      case RTP_AUDIO_G726_40:
         codec_bitrate = 40000;
         kal_sprintf(handle->name_str, "G726_40 %c %d", 
            (codec_cap->g726.cn_payload==RTP_CODEC_SUPPORT)? 'y': 'n', 
            config->codec_cap.g726.ptime );
         kal_prompt_trace(MOD_L1SP, "g726_40 cn=%d\n", codec_cap->g726.cn_payload);
          break;
      case RTP_AUDIO_G729:
         codec_bitrate = 8000;
         kal_sprintf(handle->name_str, "G729 %c %d", 
            (codec_cap->g729.annexb==RTP_CODEC_SUPPORT)? 'y': 'n', 
            config->codec_cap.g729.ptime );
         kal_prompt_trace(MOD_L1SP, "g729 annexb=%d\n", codec_cap->g729.annexb);
          break;
      case RTP_AUDIO_G7231:
         if( config->codec_cap.g7231.bitrate==G7231_BITRATE_0530 )
            codec_bitrate = 5300;
         else
            codec_bitrate = 6300;
         kal_sprintf(handle->name_str, "G723.1 %c %d", 
            (codec_cap->g7231.annexa==RTP_CODEC_SUPPORT)? 'y': 'n', 
            config->codec_cap.g7231.ptime );
         kal_prompt_trace(MOD_L1SP, "g7231 annexa=%d, bitrate=%d\n", codec_cap->g7231.annexa, codec_bitrate);
          break;
      default:
         break;
   }
   handle->maxFrameSize = (codec_bitrate*codec_para->frameTime+8*8000-1)/(8*8000);

   if( config->codec_type&(RTP_AUDIO_PCMA|RTP_AUDIO_PCMU) )
   {
      maxptime = (is_encoder==KAL_TRUE)? config->codec_cap.g711.ptime: config->codec_cap.g711.maxptime;
   }
   else if( config->codec_type&(RTP_AUDIO_G726_16|RTP_AUDIO_G726_24|RTP_AUDIO_G726_32|RTP_AUDIO_G726_40) )
   {
      maxptime = (is_encoder==KAL_TRUE)? config->codec_cap.g726.ptime: config->codec_cap.g726.maxptime;
   }
   else if( config->codec_type&(RTP_AUDIO_G729) )
   {
      maxptime = (is_encoder==KAL_TRUE)? config->codec_cap.g729.ptime: config->codec_cap.g729.maxptime;
   }
   else if( config->codec_type&(RTP_AUDIO_G7231) )
   {
      maxptime = (is_encoder==KAL_TRUE)? config->codec_cap.g7231.ptime: config->codec_cap.g7231.maxptime;
   }
   handle->maxTxFramesInPacket = (maxptime*8)/codec_para->frameTime;
   
   return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *   RTPCodec_UnRegister
 * DESCRIPTION
 *   This function un-registers the usage of the codec type and capability from the acquired 
 *   handle.
 * PARAMETERS
 *   handle         [INOUT]   The acquired handle
 * RETURNS
 *   kal_bool                 Result of the un-registration
 *****************************************************************************
 */
kal_bool RTPCodec_UnRegister( RTP_CODEC_HANDLE *handle )
{
   rtp_audio_codec_type codec_type = handle->config.codec_type;
   int is_encoder = ( handle->dir==RTP_DIR_UL )? 1: 0;

   RTP_ASSERT( handle->codec_data!=NULL );
   switch( codec_type )
   {
      case RTP_AUDIO_PCMA: case RTP_AUDIO_PCMU:
         break;
      case RTP_AUDIO_G726_16: case RTP_AUDIO_G726_24:
      case RTP_AUDIO_G726_32: case RTP_AUDIO_G726_40:
         if( is_encoder )
            rtp_codec_usage.numEncodersUsingG726 --;
         else
            rtp_codec_usage.numDecodersUsingG726 --;
         break;
         break;
      case RTP_AUDIO_G729:
         if( is_encoder )
            rtp_codec_usage.numEncodersUsingG729 --;
         else
            rtp_codec_usage.numDecodersUsingG729 --;
         break;
#if G7231_SUPPORT
      case RTP_AUDIO_G7231:
         if( is_encoder )
            rtp_codec_usage.numEncodersUsingG7231 --;
         else
            rtp_codec_usage.numDecodersUsingG7231 --;
         break;
#endif
      default:
         RTP_ASSERT( 0 );
         return KAL_FALSE;
   }
  
   return KAL_TRUE;
}

int RTPCodec_QueryMaxSIDPayloadSize(RTP_CODEC_HANDLE *handle)
{
   return(handle->maxFrameSize-1);
}

/*****************************************************************************
 * FUNCTION
 *   RTPCodec_Init
 * DESCRIPTION
 *   This function initializes the module.
 * PARAMETERS
 *   void
 * RETURNS
 *   void
 *****************************************************************************
 */
void RTPCodec_Init()
{
#if defined(USE_FAST_MEMORY)
   const unsigned int shared_buffer_size = 4096;
   const unsigned int internal_buffer_size = 4096;
   kal_uint8 *pool = RTPCodec_Buffer_Pool;
   int i;

   rtp_codec_buffer_usage.shared_buffer = pool;
   rtp_codec_buffer_usage.shared_buffer_size = shared_buffer_size;
   pool += shared_buffer_size;

   for(i=0; i<4; i++)
   {
      rtp_codec_buffer_usage.internal_buffer[i] = pool;
      pool += internal_buffer_size;
   }
   rtp_codec_buffer_usage.internal_buffer_size = internal_buffer_size;
#endif
}

#define RTPCodecEntry
/*****************************************************************************
 * FUNCTION
 *   rtp_g7xx_open
 * DESCRIPTION
 *   The entry to open RTP codec.
 * PARAMETERS
 *   handle         [INOUT]   The acquired handle
 * RETURNS
 *   kal_bool                 Result of the opening
 *****************************************************************************
 */
static kal_bool rtp_g7xx_open( RTP_CODEC_HANDLE *handle )
{
   int is_encoder = ( handle->dir==RTP_DIR_UL )? 1: 0;
   rtp_audio_codec_type codec_type;
   kal_uint32 buffer_size;

   RTP_ASSERT( handle->dir<2 );
   RTP_ASSERT( handle->para!=NULL );

   codec_type = handle->config.codec_type;
   switch( codec_type )
   {
      case RTP_AUDIO_PCMA: case RTP_AUDIO_PCMU:
      {
         int law = (codec_type==RTP_AUDIO_PCMA)? G711_ALAW: G711_ULAW;
         buffer_size = (G711_GetInternalBufferSize(is_encoder)+3)&(~3);
#if defined(USE_FAST_MEMORY)
         RTP_ASSERT( ((G711_GetSharedBufferSize(is_encoder)+3)&(~3)) <= rtp_codec_buffer_usage.shared_buffer_size );
         handle->codec_buffer = alloc_rtp_codec_buffer(buffer_size);
         handle->codec_data = G711_Open( law, is_encoder, 
            handle->codec_buffer, buffer_size,
            rtp_codec_buffer_usage.shared_buffer);
#else
         handle->codec_buffer = alloc_rtp_codec_buffer( buffer_size + ((G711_GetSharedBufferSize(is_encoder)+3)&(~3)) );
         handle->codec_data = G711_Open( law, is_encoder, 
            handle->codec_buffer, buffer_size,
            &handle->codec_buffer[buffer_size]);
#endif
      }
         break;
      case RTP_AUDIO_G726_16: case RTP_AUDIO_G726_24:
      case RTP_AUDIO_G726_32: case RTP_AUDIO_G726_40:
      {
         int rate;
         
         rate = (codec_type==RTP_AUDIO_G726_16)? 2: ((codec_type==RTP_AUDIO_G726_24)? 3: ((codec_type==RTP_AUDIO_G726_32)? 4: 5));
         buffer_size = (G726_GetInternalBufferSize(is_encoder)+3)&(~3);
#if defined(USE_FAST_MEMORY)
         RTP_ASSERT( ((G726_GetSharedBufferSize(is_encoder)+3)&(~3)) <= rtp_codec_buffer_usage.shared_buffer_size );
         handle->codec_buffer = alloc_rtp_codec_buffer(buffer_size);
         handle->codec_data = G726_Open( rate, is_encoder, 
            handle->codec_buffer, buffer_size,
            rtp_codec_buffer_usage.shared_buffer);
#else
         handle->codec_buffer = alloc_rtp_codec_buffer( buffer_size + ((G726_GetSharedBufferSize(is_encoder)+3)&(~3)) );
         handle->codec_data = G726_Open( rate, is_encoder, 
            handle->codec_buffer, buffer_size,
            &handle->codec_buffer[buffer_size]);
#endif
         rtp_codec_usage.num_non_g711_codec_opened ++;
      }
         break;
      case RTP_AUDIO_G729:
         buffer_size = (G729AB_GetInternalBufferSize(is_encoder)+3)&(~3);
#if defined(USE_FAST_MEMORY)
         RTP_ASSERT( ((G729AB_GetSharedBufferSize(is_encoder)+3)&(~3)) <= rtp_codec_buffer_usage.shared_buffer_size );
         handle->codec_buffer = alloc_rtp_codec_buffer(buffer_size);
         handle->codec_data = G729AB_Open( is_encoder, 
            handle->codec_buffer, buffer_size,
            rtp_codec_buffer_usage.shared_buffer);
#else
         handle->codec_buffer = alloc_rtp_codec_buffer( buffer_size + ((G729AB_GetSharedBufferSize(is_encoder)+3)&(~3)) );
         handle->codec_data = G729AB_Open( is_encoder, 
            handle->codec_buffer, buffer_size,
            &handle->codec_buffer[buffer_size]);
#endif
         rtp_codec_usage.num_non_g711_codec_opened ++;
         rtp_codec_usage.num_non_g711_g726_codec_opened ++;
         break;
#if G7231_SUPPORT
      case RTP_AUDIO_G7231:
         buffer_size = (G7231_GetInternalBufferSize(is_encoder)+3)&(~3);
#if defined(USE_FAST_MEMORY)
         RTP_ASSERT( ((G7231_GetSharedBufferSize(is_encoder)+3)&(~3)) <= rtp_codec_buffer_usage.shared_buffer_size );
         handle->codec_buffer = alloc_rtp_codec_buffer(buffer_size);
         {
            int rate, wrkRate;
           
            rate = handle->config.codec_cap.g7231.bitrate;
            if (rate == G7231_BITRATE_0530)
               wrkRate = 1;  // Rate53
            else
               wrkRate = 0;  // Rate63
            handle->codec_data = G7231_Open( wrkRate, is_encoder, 
               handle->codec_buffer, buffer_size,
               rtp_codec_buffer_usage.shared_buffer);
         }
#else
         handle->codec_buffer = alloc_rtp_codec_buffer( buffer_size + ((G7231_GetSharedBufferSize(is_encoder)+3)&(~3)) );
         {
            int rate, wrkRate;
           
            rate = handle->config.codec_cap.g7231.bitrate;
            if (rate == G7231_BITRATE_0530)
               wrkRate = 1;  // Rate53
            else
               wrkRate = 0;  // Rate63
            
            handle->codec_data = G7231_Open( wrkRate, is_encoder, 
               handle->codec_buffer, buffer_size,
               &handle->codec_buffer[buffer_size]);
         }
#endif
         rtp_codec_usage.num_non_g711_codec_opened ++;
         rtp_codec_usage.num_non_g711_g726_codec_opened ++;
         break;
#endif
      default:
         RTP_ASSERT( 0 );
         return( KAL_FALSE );
   }

   return KAL_TRUE;
}

static kal_bool rtp_g7xx_close( RTP_CODEC_HANDLE *handle )
{
   rtp_audio_codec_type codec_type = handle->config.codec_type;
   int is_encoder = ( handle->dir==RTP_DIR_UL )? 1: 0;

   RTP_ASSERT( handle->codec_data!=NULL );
   switch( codec_type )
   {
      case RTP_AUDIO_PCMA: case RTP_AUDIO_PCMU:
         G711_Close( handle->codec_data, is_encoder );
         break;
      case RTP_AUDIO_G726_16: case RTP_AUDIO_G726_24:
      case RTP_AUDIO_G726_32: case RTP_AUDIO_G726_40:
         G726_Close( handle->codec_data, is_encoder );
         rtp_codec_usage.num_non_g711_codec_opened --;
         break;
      case RTP_AUDIO_G729:
         G729AB_Close( handle->codec_data, is_encoder );
         rtp_codec_usage.num_non_g711_codec_opened --;
         rtp_codec_usage.num_non_g711_g726_codec_opened --;
         break;
#if G7231_SUPPORT
      case RTP_AUDIO_G7231:
         G7231_Close( handle->codec_data, is_encoder );
         rtp_codec_usage.num_non_g711_codec_opened --;
         rtp_codec_usage.num_non_g711_g726_codec_opened --;
         break;
#endif
      default:
         RTP_ASSERT( 0 );
         return KAL_FALSE;
   }
   free_rtp_codec_buffer(&handle->codec_buffer);

   return KAL_TRUE;
}

static kal_bool rtp_g729_encode( RTP_CODEC_HANDLE *handle, kal_uint8 *bits_buffer, kal_uint32 *buffer_size, rtp_audio_codec_type *alt_codec_type, kal_bool get_cn )
{
   int16 *read_ptr;
   int32 read_cnt;
   int num_octets;
   int vad_enable = 1;
   int cng_enable;
   kal_bool isSilent;
#if VOIPEVL_SUPPORT
   INF_VORTP_ENCODING_STRUCT event;
#endif

   if(get_cn == KAL_FALSE)
   {
      PCMRB_GetReadBlock( handle->rb, &read_ptr, &read_cnt );
      RTP_ASSERT( read_cnt>=(int32)handle->para->frameTime );

      vad_enable = (handle->config.codec_cap.g729.annexb==RTP_CODEC_SUPPORT)? 1: 0;
///      if(L1Audio_GetDebugInfo(4) == 0)
///         vad_enable = 1;
      if(IS_DTX_DISABLED()) vad_enable = 0;
   }
   cng_enable = vad_enable;

#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_UL())
   {
      event.uCodecType = RTP_AUDIO_G729;
      event.uPCMLength = handle->para->frameTime * sizeof(int16);
      if( !IS_VOIPEVL_LOGGING_ULPCM() )
         event.uPCMLength = 0;
      event.tBegin = Tick();
   }
#endif
   if(get_cn == KAL_FALSE)
   {
      num_octets = G729AB_Encode( handle->codec_data, read_ptr, bits_buffer, vad_enable, cng_enable );
   }
   else if(cng_enable == 1)
   {
      bits_buffer[0] = 0x34;
      bits_buffer[1] = 0x40 | (CN_GAIN_G729 & 0x1f);
      num_octets = 2;
   }
   else
   {
      num_octets = 0;
   }
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_UL())
   {
      event.tEnd = Tick();
      event.uFrameType = num_octets;
      event.uFrameInfo = 0;
      event.uBitstreamLength = num_octets;
      event.uSessionID = VoRTP_current_session_id_l1aud;
      VORTP_CODEC_TRACE_EVENT(event, INF_VORTP_ENCODING, read_ptr, bits_buffer);
   }
#endif

   if(get_cn == KAL_FALSE)
   {
      PCMRB_ShiftReadPointer( handle->rb, handle->para->frameTime );
   }

   *buffer_size = num_octets;

   *alt_codec_type = RTP_AUDIO_G729;

   if( num_octets>0 )
      isSilent = KAL_FALSE;
   else
      isSilent = KAL_TRUE;

   return isSilent;
}

static kal_bool rtp_g729_decode( RTP_CODEC_HANDLE *handle, kal_uint8 *bits_buffer, kal_uint32 *buffer_size, rtp_audio_codec_type alt_codec_type )
{
   int16 *write_ptr;
   int32 write_cnt;
   int num_octets;
   short frame_erasure;
#if VOIPEVL_SUPPORT
   INF_VORTP_DECODING_STRUCT event;
   int FrameType;
#endif

   PCMRB_GetWriteBlock( handle->rb, &write_ptr, &write_cnt );
   RTP_ASSERT( write_cnt>=(int32)handle->para->frameTime );

   // KH modify: Always use CNG
   if( *buffer_size>=handle->maxFrameSize ) {
      num_octets = handle->maxFrameSize;
      *buffer_size = num_octets;
   } else if(*buffer_size>=2 ) {
      num_octets = 2;
      // Consume all payload
   } else {
      num_octets = 0;
      // Consume all payload
   }

   frame_erasure = 0;//(num_octets==0)? 1: 0;
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_DL())
   {
      event.uCodecType = RTP_AUDIO_G729;
      event.uPCMLength = handle->para->frameTime * sizeof(int16);
      if(!IS_VOIPEVL_LOGGING_DLPCM())
         event.uPCMLength = 0;
      event.tBegin = Tick();
   }
#endif
      FrameType = G729AB_Decode( handle->codec_data, bits_buffer, write_ptr, num_octets, frame_erasure );
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_DL())
   {
      event.tEnd = Tick();
      event.uFrameType = FrameType;
      event.uFrameInfo = 0;
      event.uBitstreamLength = num_octets;
      event.uSessionID = VoRTP_current_session_id_l1aud;
      VORTP_CODEC_TRACE_EVENT(event, INF_VORTP_DECODING, write_ptr, bits_buffer);
   }
#endif

   if(drop_output == KAL_FALSE)
      PCMRB_ShiftWritePointer( handle->rb, handle->para->frameTime );

   return KAL_TRUE;
}

static kal_bool rtp_g726_encode( RTP_CODEC_HANDLE *handle, kal_uint8 *bits_buffer, kal_uint32 *buffer_size, rtp_audio_codec_type *alt_codec_type, kal_bool get_cn )
{
   int16 *read_ptr;
   int32 read_cnt;
   int num_octets;
   int vad_enable = 1;
   int cng_enable;
   kal_bool isSilent;
   int rate = 0;
#if VOIPEVL_SUPPORT
   INF_VORTP_ENCODING_STRUCT event;
#endif

   if(get_cn == KAL_FALSE)
   {
      PCMRB_GetReadBlock( handle->rb, &read_ptr, &read_cnt );
      RTP_ASSERT( read_cnt>=(int32)handle->para->frameTime );

      vad_enable = (handle->config.codec_cap.g726.cn_payload ==RTP_CODEC_SUPPORT)? 1: 0;
///      if(L1Audio_GetDebugInfo(4) == 0)
///         vad_enable = 1;
      if(vad_enable == 1)
      {
         if(rtp_codec_usage.num_non_g711_g726_codec_opened > 0)
            vad_enable = 0;
      }
      if(IS_DTX_DISABLED()) vad_enable = 0;
   }
   cng_enable = vad_enable;

   if( handle->config.codec_type==RTP_AUDIO_G726_16 )
      rate = 2;
   else if( handle->config.codec_type==RTP_AUDIO_G726_24 )
      rate = 3;
   else if( handle->config.codec_type==RTP_AUDIO_G726_32 )
      rate = 4;
   else if( handle->config.codec_type==RTP_AUDIO_G726_40 )
      rate = 5;
   else
      RTP_ASSERT(0);
   
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_UL())
   {
      event.uCodecType = handle->config.codec_type;
      event.uPCMLength = handle->para->frameTime * sizeof(int16);
      if( !IS_VOIPEVL_LOGGING_ULPCM() )
         event.uPCMLength = 0;
      event.tBegin = Tick();
   }
#endif
   if(get_cn == KAL_FALSE)
   {
      num_octets = G726_Encode( handle->codec_data, read_ptr, bits_buffer, vad_enable, cng_enable, rate );
   }
   else if(cng_enable == 1)
   {
      bits_buffer[0] = CN_GAIN_G711;
      num_octets = 1;
   }
   else
   {
      num_octets = 0;
   }
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_UL())
   {
      event.tEnd = Tick();
      event.uFrameType = num_octets;
      event.uFrameInfo = 0;
      event.uBitstreamLength = num_octets;
      event.uSessionID = VoRTP_current_session_id_l1aud;
      VORTP_CODEC_TRACE_EVENT(event, INF_VORTP_ENCODING, read_ptr, bits_buffer);
   }
#endif

   if(get_cn == KAL_FALSE)
   {
      PCMRB_ShiftReadPointer( handle->rb, handle->para->frameTime );
   }

   *buffer_size = num_octets;

   // KH assign codec type to be CN
   if ( (num_octets > 1) && (num_octets < handle->maxFrameSize) )
      *alt_codec_type = RTP_AUDIO_CN;
   else
      *alt_codec_type = handle->config.codec_type;

   if( num_octets>0 )
      isSilent = KAL_FALSE;
   else
      isSilent = KAL_TRUE;

   return isSilent;
}

static kal_bool rtp_g726_g711_decode( RTP_CODEC_HANDLE *handle, kal_uint8 *bits_buffer, kal_uint32 *buffer_size, rtp_audio_codec_type alt_codec_type )
{
   int16 *write_ptr;
   int32 write_cnt;
   int num_octets;
   short frame_erasure;
   int (*G7xx_Decode)(void *, unsigned char  *, short *, int , short, int, int );
#if VOIPEVL_SUPPORT
   INF_VORTP_DECODING_STRUCT event;
   int FrameType;
#endif
   int disable_enhancement = 0;

   if(handle->config.codec_type&(RTP_AUDIO_PCMA|RTP_AUDIO_PCMU))
   {
      G7xx_Decode = G711_Decode;
      if(rtp_codec_usage.num_non_g711_codec_opened > 0)
      {
         disable_enhancement = 1;
      }
   }
   else
   {
      G7xx_Decode = G726_Decode;
      if(rtp_codec_usage.num_non_g711_g726_codec_opened > 0)
      {
         disable_enhancement = 1;
      }
   }

   PCMRB_GetWriteBlock( handle->rb, &write_ptr, &write_cnt );
   RTP_ASSERT( write_cnt>=(int32)handle->para->frameTime );

   if( *buffer_size>=handle->maxFrameSize )
   {
      num_octets = handle->maxFrameSize;
      *buffer_size = num_octets;
   }
   else if( *buffer_size>0 && alt_codec_type==RTP_AUDIO_CN )
      num_octets = *buffer_size;
   else
      num_octets = 0;

   frame_erasure = 0;

#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_DL())
   {
      event.uCodecType = handle->config.codec_type;
      event.uPCMLength = handle->para->frameTime * sizeof(int16);
      if(!IS_VOIPEVL_LOGGING_DLPCM())
         event.uPCMLength = 0;
      event.tBegin = Tick();
   }
#endif
      FrameType = G7xx_Decode( handle->codec_data, bits_buffer, write_ptr, num_octets, 
                               frame_erasure, (alt_codec_type==RTP_AUDIO_CN)? 1: 0, 
                               disable_enhancement );
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_DL())
   {
      event.tEnd = Tick();
      event.uFrameType = FrameType;
      event.uFrameInfo = 0;
      event.uBitstreamLength = num_octets;
      event.uSessionID = VoRTP_current_session_id_l1aud;
      VORTP_CODEC_TRACE_EVENT(event, INF_VORTP_DECODING, write_ptr, bits_buffer);
   }
#endif

   if(drop_output == KAL_FALSE)
      PCMRB_ShiftWritePointer( handle->rb, handle->para->frameTime );

   return KAL_TRUE;
}

static kal_bool rtp_g711_encode( RTP_CODEC_HANDLE *handle, kal_uint8 *bits_buffer, kal_uint32 *buffer_size, rtp_audio_codec_type *alt_codec_type, kal_bool get_cn )
{
   int16 *read_ptr;
   int32 read_cnt;
   int num_octets;
   int vad_enable = 1;
   int cng_enable;
   kal_bool isSilent;
#if VOIPEVL_SUPPORT
   INF_VORTP_ENCODING_STRUCT event;
#endif

   if(get_cn == KAL_FALSE)
   {
      PCMRB_GetReadBlock( handle->rb, &read_ptr, &read_cnt );
      RTP_ASSERT( read_cnt>=(int32)handle->para->frameTime );

      vad_enable = (handle->config.codec_cap.g711.cn_payload ==RTP_CODEC_SUPPORT)? 1: 0;
///      if(L1Audio_GetDebugInfo(4) == 0)
///         vad_enable = 1;
      if(vad_enable == 1)
      {
         if(rtp_codec_usage.num_non_g711_codec_opened > 0)
            vad_enable = 0;
      }
      if(IS_DTX_DISABLED()) vad_enable = 0;
   }
   cng_enable = vad_enable;

#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_UL())
   {
      event.uCodecType = handle->config.codec_type;
      event.uPCMLength = handle->para->frameTime * sizeof(int16);
      if(!IS_VOIPEVL_LOGGING_ULPCM())
         event.uPCMLength = 0;
      event.tBegin = Tick();
   }
#endif
   if(get_cn == KAL_FALSE)
   {
      num_octets = G711_Encode( handle->codec_data, read_ptr, bits_buffer, vad_enable, cng_enable );
   }
   else if(cng_enable == 1)
   {
      bits_buffer[0] = CN_GAIN_G711;
      num_octets = 1;
   }
   else
   {
      num_octets = 0;
   }
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_UL())
   {
      event.tEnd = Tick();
      event.uFrameType = num_octets;
      event.uFrameInfo = 0;
      event.uBitstreamLength = num_octets;
      event.uSessionID = VoRTP_current_session_id_l1aud;
      VORTP_CODEC_TRACE_EVENT(event, INF_VORTP_ENCODING, read_ptr, bits_buffer);
   }
#endif

   if(get_cn == KAL_FALSE)
   {
      PCMRB_ShiftReadPointer( handle->rb, handle->para->frameTime );
   }

   *buffer_size = num_octets;

   // KH assign codec type to be CN
   if ((num_octets >= 1) && (num_octets < handle->maxFrameSize))
      *alt_codec_type = RTP_AUDIO_CN;
   else
      *alt_codec_type = handle->config.codec_type;

   if( num_octets>0 )
      isSilent = KAL_FALSE;
   else
      isSilent = KAL_TRUE;

   return isSilent;
}

static kal_bool rtp_g7231_encode( RTP_CODEC_HANDLE *handle, kal_uint8 *bits_buffer, kal_uint32 *buffer_size, rtp_audio_codec_type *alt_codec_type, kal_bool get_cn )
{
   int16 *read_ptr;
   int32 read_cnt;
   int num_octets;
   int vad_enable = 1;
   int cng_enable;
   kal_bool isSilent;
#if VOIPEVL_SUPPORT
   INF_VORTP_ENCODING_STRUCT event;
#endif

   if(get_cn == KAL_FALSE)
   {
      PCMRB_GetReadBlock( handle->rb, &read_ptr, &read_cnt );
      RTP_ASSERT( read_cnt>=(int32)handle->para->frameTime );

      vad_enable = (handle->config.codec_cap.g7231.annexa==RTP_CODEC_SUPPORT)? 1: 0;
///      if(L1Audio_GetDebugInfo(4) == 0)
///         vad_enable = 1;
      if(IS_DTX_DISABLED()) vad_enable = 0;
   }
   cng_enable = vad_enable;
   
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_UL())
   {
      event.uCodecType = RTP_AUDIO_G7231;
      event.uPCMLength = handle->para->frameTime * sizeof(int16);
      if(!IS_VOIPEVL_LOGGING_ULPCM())
         event.uPCMLength = 0;
      event.tBegin = Tick();
   }
#endif
   if(get_cn == KAL_FALSE)
   {
      num_octets = G723_1_Encode( handle->codec_data, read_ptr, bits_buffer, vad_enable, cng_enable );
   }
   else if(cng_enable == 1)
   {
      bits_buffer[0] = 0xF6;
      bits_buffer[1] = 0x3A;
      bits_buffer[2] = 0x8A;
      bits_buffer[3] = 0x02 | ((CN_GAIN_G7231 & 0x3f)<<2);
      num_octets = 4;
   }
   else
   {
      num_octets = 0;
   }
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_UL())
   {
      event.tEnd = Tick();
      event.uFrameType = num_octets;
      event.uFrameInfo = 0;
      event.uBitstreamLength = num_octets;
      event.uSessionID = VoRTP_current_session_id_l1aud;
      VORTP_CODEC_TRACE_EVENT(event, INF_VORTP_ENCODING, read_ptr, bits_buffer);
   }
#endif

   if(get_cn == KAL_FALSE)
   {
      PCMRB_ShiftReadPointer( handle->rb, handle->para->frameTime );
   }

   *buffer_size = num_octets;

   *alt_codec_type = RTP_AUDIO_G7231;

   if( num_octets > 0 )
      isSilent = KAL_FALSE;
   else
      isSilent = KAL_TRUE;

   return isSilent;
}

static kal_bool rtp_g7231_decode( RTP_CODEC_HANDLE *handle, kal_uint8 *bits_buffer, kal_uint32 *buffer_size, rtp_audio_codec_type alt_codec_type )
{
   int16 *write_ptr;
   int32 write_cnt;
   int num_octets;
   short frame_erasure = 0;
#if VOIPEVL_SUPPORT
   INF_VORTP_DECODING_STRUCT event;
   int FrameType;
#endif

   PCMRB_GetWriteBlock( handle->rb, &write_ptr, &write_cnt );
   RTP_ASSERT( write_cnt>=(int32)handle->para->frameTime );

   // KH modify: Always use CNG
   if (*buffer_size == 0) {
      num_octets = 0;
   } else {
      num_octets = G7231_GetDecodeFrameSize(bits_buffer[0]);
      if ( *buffer_size >= num_octets ) {
         *buffer_size = num_octets;
      } else {
         // consume the damaged packet, treat as CNG
         num_octets = 0;
      }
   }

   frame_erasure = 0;//(num_octets==0)? 1: 0;
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_DL())
   {
      event.uCodecType = RTP_AUDIO_G7231;
      event.uPCMLength = handle->para->frameTime * sizeof(int16);
      if(!IS_VOIPEVL_LOGGING_DLPCM())
         event.uPCMLength = 0;
      event.tBegin = Tick();
   }
#endif
      FrameType = G723_1_Decode( handle->codec_data, bits_buffer, write_ptr, num_octets, frame_erasure );
#if VOIPEVL_SUPPORT
   if(IS_VOIPEVL_LOGGING_DL())
   {
      event.tEnd = Tick();
      event.uFrameType = FrameType;
      event.uFrameInfo = 0;
      event.uBitstreamLength = num_octets;
      event.uSessionID = VoRTP_current_session_id_l1aud;
      VORTP_CODEC_TRACE_EVENT(event, INF_VORTP_DECODING, write_ptr, bits_buffer);
   }
#endif

   if(drop_output == KAL_FALSE)
      PCMRB_ShiftWritePointer( handle->rb, handle->para->frameTime );

   return KAL_TRUE;
}

/*****************************************************************************
*                        P U B L I C   D A T A
******************************************************************************
*/
const RTP_CODEC_PARA rtp_g729_para = {
   80,
   320,
   rtp_g7xx_open,
   rtp_g7xx_close,
   rtp_g729_encode,
   rtp_g729_decode
};

const RTP_CODEC_PARA rtp_g726_para = {
   80,
   320,
   rtp_g7xx_open,
   rtp_g7xx_close,
   rtp_g726_encode,
   rtp_g726_g711_decode
};

const RTP_CODEC_PARA rtp_g711_para = {
   80,
   320,
   rtp_g7xx_open,
   rtp_g7xx_close,
   rtp_g711_encode,
   rtp_g726_g711_decode
};

const RTP_CODEC_PARA rtp_g7231_para = {
   240,
   480,
   rtp_g7xx_open,
   rtp_g7xx_close,
   rtp_g7231_encode,
   rtp_g7231_decode
};

#endif

