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
 * media.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Media file recording/playback
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"
#include "afe.h"
#include "l1sp_trc.h"

#if defined( SW_SYN_8K ) || defined( SW_SYN_16K )
#include "midisyn.h"
#elif defined( DSP_WT_SYN )
#include "dspsyn.h"
#endif

#if IS_EV_BOARD
#include "alerter_sw.h"
#endif

#if VERIFY_DATA_TO_DSP
extern void VERIFY_DATA_TO_DSP_START( void );
extern void VERIFY_DATA_TO_DSP_RESUME( void );
extern void VERIFY_DATA_TO_DSP_STOP( void );
#endif

static struct {
   mediaControl   ctrl;
   bool           waiting;   
   bool           paused;
   uint16         aud_id;
   void           (*media_handler)( Media_Event event );
   int32          recorded_time;
} media;

struct {
   kal_uint32 uCurOffset;
   kal_uint32 uResumeFrameOffset;
} audResumeInfo;

/* Functions for Ring Buffer Access */

/* Reset the read/write pointers and odd bye flags of ring buffer */
/* This function should be called in Media_SetBuffer to reset the media buffer */
// Rey: Checked
void rb_ClearRB( void )
{
   media.ctrl.read = 0;
   media.ctrl.write = 0;
   media.ctrl.ob_flag_r = false;
   media.ctrl.ob_flag_w = false;
}

/* Return the count of data (in byte) in ring buffer */
/* Note that the data unit of return value is BYTE!!! */
// Rey: Checked
int32 rb_GetByteCount( void )
{
   int32 count;
   count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   if( count < 0 )
      count += media.ctrl.rb_size;
   count <<= 1;
   if( media.ctrl.ob_flag_r )
      count ++;
   if( media.ctrl.ob_flag_w )
      count ++;
   return count;
}

/* Return the remaining space (in byte) of ring buffer */
/* Note that the data unit of return value is BYTE!!! */
// Rey: Checked
int32 rb_GetFreeSpace( void )
{
   int32 count;
   count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   if( count < 0 )
      count += (int32)media.ctrl.rb_size;
   count <<= 1;
   if( media.ctrl.ob_flag_r )
      count --;
   if( media.ctrl.ob_flag_w )
      count --;
   return count;
}

/* Get a byte from ring buffer */
// Rey: Checked
bool rb_GetByte( uint8* data_8 )
{
   if( rb_GetByteCount()==0 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      *data_8 = media.ctrl.odd_byte_r;
      media.ctrl.ob_flag_r = false;
   }
   else
   {
      // Special Case: there's only one byte in ring buffer and the byte is in odd_byte_w
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_8 = media.ctrl.odd_byte_w;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_8 = (uint8)media.ctrl.rb_base[media.ctrl.read];
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
      media.ctrl.ob_flag_r = true;
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
   }
   return true;
}

/* Get a word from ring buffer */
// Rey: Checked
bool rb_GetWord( uint16* data_16 )
{
   if( rb_GetByteCount() < 2 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      // Special case: there is only one word in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_16 = media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w << 8);
         media.ctrl.ob_flag_r = false;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_16 = media.ctrl.odd_byte_r | (media.ctrl.rb_base[media.ctrl.read] << 8);
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   }
   else
      *data_16 = media.ctrl.rb_base[media.ctrl.read];
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return true;
}

/* Get a double word from ring buffer */
// Rey: Checked
bool rb_GetDWord( uint32* data_32 )
{
   if( rb_GetByteCount() < 4 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      *data_32 = media.ctrl.odd_byte_r;
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 8);
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      // Special Case: there is only one double-word in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_32 |= ((uint32)media.ctrl.odd_byte_w << 24);
         media.ctrl.ob_flag_r = false;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 24);
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   }
   else
   {
      *data_32 = media.ctrl.rb_base[media.ctrl.read];
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 16);
   }
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return true;
}

/* Peek the value of the incoming byte in ring buffer, without moving forward the read pointer */
// Rey: Checked
bool rb_PeekByte( uint8* data_8 )
{
   if( rb_GetByteCount()==0 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
      *data_8 = media.ctrl.odd_byte_r;
   else
   {
      // Special Case: there's only one byte in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
         *data_8 = media.ctrl.odd_byte_w;
      else
         *data_8 = (uint8)media.ctrl.rb_base[media.ctrl.read];
   }
   return true;
}

/* Peek the value of the incoming word in ring buffer, without moving forward the read pointer */
// Rey: Checked
bool rb_PeekWord( uint16* data_16 )
{
   if( rb_GetByteCount() < 2 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      // Special Case: there is only one word in ring buffer
      if( media.ctrl.read == media.ctrl.write )
         *data_16 = media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w << 8);
      else
         *data_16 = media.ctrl.odd_byte_r | (media.ctrl.rb_base[media.ctrl.read] << 8);
   }
   else
      *data_16 = media.ctrl.rb_base[media.ctrl.read];
   return true;
}

/* Peek the value of the incoming double word in ring buffer, without moving forward the read pointer */
// Rey: Checked
bool rb_PeekDWord( uint32* data_32 )
{
   uint32 tmp_read;
   if( rb_GetByteCount() < 4 )
      return false;     // Buffer underflow
   tmp_read = media.ctrl.read;
   if( media.ctrl.ob_flag_r )
   {
      *data_32 = media.ctrl.odd_byte_r;
      *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 8);
      if( ++tmp_read == media.ctrl.rb_size )
         tmp_read = 0;
      if( tmp_read == media.ctrl.write )
         *data_32 |= ((uint32)media.ctrl.odd_byte_w << 24);
      else
         *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 24);
   }
   else
   {
      *data_32 = media.ctrl.rb_base[tmp_read];
      if( ++tmp_read == media.ctrl.rb_size )
         tmp_read = 0;
      *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 16);
   }
   return true;
}

/* Skip N byte in ring buffer, return the number of bytes skipped */
// Rey: Checked
uint32 rb_SkipNByte( uint32 skip_count )
{
   uint32 ret;
   if( skip_count == 0 )
      return 0;
   ret = rb_GetByteCount();
   if( ret <= skip_count )
   {
      rb_ClearRB();
      return ret;
   }
   ret = skip_count;
   if( media.ctrl.ob_flag_r )
   {
      media.ctrl.ob_flag_r = false;
      if( --skip_count == 0 )
         return 1;
   }
   media.ctrl.read += (skip_count >> 1);
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read -= media.ctrl.rb_size;
   skip_count &= 0x01;
   if( skip_count == 0 )
      return ret;
   media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   media.ctrl.ob_flag_r = true;
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return ret;
}

/* Skip N Words in ring buffer, return the number of words skipped */
// Rey: Checked
uint32 rb_SkipNWord( uint32 skip_count )
{
   uint32 ret;
   if( skip_count == 0 )
      return 0;
   ret = rb_GetByteCount();
   if( (ret >> 1) <= skip_count )
   {
      if((ret & 0x01) == 0)   // If ret is even, then the ring buffer should be cleared
      {
         rb_ClearRB();
         return (ret >> 1);
      }
      else
         ret >>= 1;
   }
   else
      ret = skip_count;

   if( ret == 0 )
      return 0;
   media.ctrl.read += ret - 1;
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read -= media.ctrl.rb_size;
   if( media.ctrl.ob_flag_r )
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return ret;
}

/* Get len bytes from ring buffer to buffer */
/* The return value is the actual number of bytes moved */
int rb_GetNByte( uint8 *buffer, int len )
{
   uint8 *dst_ptr;
   const uint8 *src_ptr;
   int len_to_copy, remaining;
   if( len == 0 )
      return 0;
   ASSERT( buffer != NULL );
   len_to_copy = rb_GetByteCount();
   if( len_to_copy == 0 )
      return 0;
   if( len < len_to_copy )
      len_to_copy = len;
   remaining = len_to_copy;
   dst_ptr = buffer;
   if( media.ctrl.ob_flag_r )
   {
      *dst_ptr = media.ctrl.odd_byte_r;
      media.ctrl.ob_flag_r = false;
      if( --remaining == 0 )
         return 1;
      dst_ptr++;
   }
   if( media.ctrl.write < media.ctrl.read )
   {
      len = (media.ctrl.rb_size - media.ctrl.read ) << 1;
      if( len > remaining )
         len = remaining;
      src_ptr = (uint8*)&media.ctrl.rb_base[media.ctrl.read];
#ifdef _TESTENV
      memcpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
#else
      kal_mem_cpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
#endif
      dst_ptr += len;
      media.ctrl.read += (len >> 1);
      if( media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      remaining -= len;
      if( len & 0x01 )
      {
         media.ctrl.ob_flag_r = true;
         media.ctrl.odd_byte_r = *(src_ptr+len);
         if( ++media.ctrl.read == media.ctrl.rb_size )
            media.ctrl.read = 0;
         ASSERT( remaining == 0 );
         return len_to_copy;
      }
   }
   if( remaining )
   {
      src_ptr = (uint8*)&media.ctrl.rb_base[media.ctrl.read];
#ifdef _TESTENV
      memcpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
#else
      kal_mem_cpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
#endif
      media.ctrl.read += (remaining >> 1);
      if( remaining & 0x01 )
      {
         if( media.ctrl.read == media.ctrl.write )
         {
            *(dst_ptr+remaining - 1) = media.ctrl.odd_byte_w;
            media.ctrl.ob_flag_w = false;
         }else
         {
            *(dst_ptr+remaining - 1) = *(src_ptr+remaining - 1);
            media.ctrl.ob_flag_r = true;
            media.ctrl.odd_byte_r = *(src_ptr+remaining);
            media.ctrl.read ++;
         }
      }
   }
   return len_to_copy;
}

/* Put bytes from buffer into ring buffer */
/* The return value is the actual number of bytes moved */
int rb_PutNByte( const uint8 *buffer, int len )
{
   uint8 *dst_ptr;
   const uint8 *src_ptr;
   int len_to_copy, remaining;
   if( len == 0 )
      return 0;
   ASSERT( buffer!=NULL );
   len_to_copy = rb_GetFreeSpace();
   if( len_to_copy == 0 )
      return 0;
   if( len_to_copy > len )
      len_to_copy = len;
   remaining = len_to_copy;
   src_ptr = buffer;
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write]=media.ctrl.odd_byte_w | (uint16)*src_ptr << 8;
      media.ctrl.ob_flag_w = false;
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      if( --remaining == 0 )
         return 1;
      src_ptr++;
   }
   if( media.ctrl.write >= media.ctrl.read )
   {
      // step 1: copy from write index to the end of ring buffer
      len = (media.ctrl.rb_size - media.ctrl.write) << 1;
      if( remaining < len )
         len = remaining;
      dst_ptr = (uint8*)&(media.ctrl.rb_base[media.ctrl.write]);
#ifdef _TESTENV
      memcpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
#else
      kal_mem_cpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
#endif
      src_ptr += len;
      media.ctrl.write += (len >> 1);
      if( media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      remaining -= len;
      if( len & 0x01 )
      {
         media.ctrl.ob_flag_w = true;
         media.ctrl.odd_byte_w = *(src_ptr - 1);
         ASSERT( remaining == 0 );
         return len_to_copy;
      }
   }
   if( remaining )
   {
      dst_ptr = (uint8*)&(media.ctrl.rb_base[media.ctrl.write]);
#ifdef _TESTENV
      memcpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
#else
      kal_mem_cpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
#endif
      media.ctrl.write += (remaining >> 1);
      if( media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      if( remaining & 0x01 )
      {
         media.ctrl.ob_flag_w = true;
         media.ctrl.odd_byte_w = buffer[len_to_copy-1];
      }
   }
   return len_to_copy;
}

/* Put a byte into ringer buffer */
bool rb_PutByte( uint8 data_8 )
{
   if( rb_GetFreeSpace() == 0 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.ob_flag_w = false;
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | ((uint16)data_8 << 8);
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
   }
   else
   {
      media.ctrl.odd_byte_w = data_8;
      media.ctrl.ob_flag_w = true;
   }
   return true;
}

/* Put a word into ring buffer */
bool rb_PutWord( uint16 data_16 )
{
   if( rb_GetFreeSpace() < 2 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | (data_16 << 8);
      media.ctrl.odd_byte_w = (uint8)(data_16 >> 8);
   }
   else
      media.ctrl.rb_base[media.ctrl.write] = data_16;
   if( ++media.ctrl.write == media.ctrl.rb_size )
      media.ctrl.write = 0;
   return true;
}

/* Put a double word into ring buffer */
bool rb_PutDWord( uint32 data_32 )
{
   if( rb_GetFreeSpace() < 4 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | ((uint16)data_32 << 8);
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      media.ctrl.rb_base[media.ctrl.write] = (uint16)(data_32 >> 8);
      media.ctrl.odd_byte_w = (uint8)(data_32 >> 24);
   }
   else
   {
      media.ctrl.rb_base[media.ctrl.write] = (uint16)data_32;
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      media.ctrl.rb_base[media.ctrl.write] = (uint16)(data_32 >> 16);
   }
   if( ++media.ctrl.write == media.ctrl.rb_size )
      media.ctrl.write = 0;
   return true;
}

/* Return media.ctrl.read */
uint32 rb_GetReadIndex( void )
{
   return media.ctrl.read;
}

/* Return media.ctrl.write */
uint32 rb_GetWriteIndex( void )
{
   return media.ctrl.write;
}

/* Return media.ctrl.rb_size */
uint32 rb_GetSize( void )
{
   return media.ctrl.rb_size << 1;
}

/* Return media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w)<<8 */
uint16 rb_GetOddByte( void )
{
   return media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w)<<8;
}

uint16 rb_GetOBFlag( void )
{
   uint16 ret=0;
   if( media.ctrl.ob_flag_r )
      ret |= 1;
   if( media.ctrl.ob_flag_w )
      ret |= 2;
   return ret;
}

/* ------------------------------------------------------------------------------ */
static void mediaDataRequest( void )
{
   if( media.waiting || media.ctrl.eof || (media.ctrl.end_status == MEDIA_END) )
      return;
   if( mediaGetFreeSpace() >= media.ctrl.rb_threshold ) {
      mediaSetEvent( MEDIA_DATA_REQUEST );
      media.waiting = true;
   }
}

void mediaDataNotification( void )
{
   if( media.waiting )
      return;
   if( mediaGetDataCount() >= media.ctrl.rb_threshold) {
      mediaSetEvent( MEDIA_DATA_NOTIFICATION );
      media.waiting = true;
   }
}

#ifndef __L1_STANDALONE__ // avoid link error
void mediaHisr( uint16 flag )
{
   switch( flag ) {
   case DP_D2C_PCM_P:                     /* PCM Playback */
#if defined( SW_SYN_8K ) || defined( SW_SYN_16K )
      if( media.ctrl.format == MEDIA_FORMAT_SMF || media.ctrl.format == MEDIA_FORMAT_IMELODY ) {
         SWSYN_PcmPlaybackHisr( &media.ctrl );
         break;
      }
#endif
      switch( media.ctrl.format )
      {
#if !defined( MT6205B )
#if defined( AU_DECODE )
         case MEDIA_FORMAT_AU:
            auPlaybackHisr();
            break;
#endif
#if defined( AIFF_DECODE )
         case MEDIA_FORMAT_AIFF:
            aiffPlaybackHisr();
            break;
#endif
#endif
         default:
            pcmPlaybackHisr();
      }
      mediaDataRequest();
      break;

   case DP_D2C_PCM_R:                     /* PCM Recording */
   case DP_D2C_PCM_TCH_R:
   case DP_D2C_WAV_REC:
      media.recorded_time += 20;
      if(media.recorded_time <= 0) 
         return;
#if !defined( MT6205B )
      if( media.ctrl.format == MEDIA_FORMAT_WAV || media.ctrl.format == MEDIA_FORMAT_WAV_ALAW
         || media.ctrl.format == MEDIA_FORMAT_WAV_ULAW || media.ctrl.format == MEDIA_FORMAT_WAV_DVI_ADPCM)
         wavRecordHisr();
#if defined( DEDI_AMR_REC )
      else if( media.ctrl.format == MEDIA_FORMAT_AMR )
         amr515RecordHisr();
#endif   /* DEDI_AMR_REC */
      else
#endif
         pcmRecordHisr();
      mediaDataNotification();
      break;

   case DP_D2C_SE_DONE:
      media.recorded_time += 20;
      if(media.recorded_time <= 0) 
         return;
#if VERIFY_AVSYNC
      ut_avsync_record_hisr();
#endif
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      if ( media.ctrl.format == MEDIA_FORMAT_PCM_16K ){
         pcmRecordHisr();
      } else if ( media.ctrl.format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K ){
         wavRecordHisr();
      } else
#endif
#if !defined( MT6205B )
      if (media.ctrl.format == MEDIA_FORMAT_AMR || media.ctrl.format == MEDIA_FORMAT_AMR_WB) {
         amrRecordHisr();
      } else
#endif
      if (media.ctrl.format == MEDIA_FORMAT_VRD || media.ctrl.format == MEDIA_FORMAT_GSM_FR ||
          media.ctrl.format == MEDIA_FORMAT_GSM_HR || media.ctrl.format == MEDIA_FORMAT_GSM_EFR) {
         vmRecordHisr();
      } else {
         ASSERT(0);
      }
      mediaDataNotification();
      break;

   case DP_D2C_SE_SD_DONE:                /* Voice Memo Recording */
      media.recorded_time += 20;
      if(media.recorded_time <= 0) 
         return;
#if VERIFY_AVSYNC
      ut_avsync_record_hisr();
#endif
      if (media.ctrl.format == MEDIA_FORMAT_VRD || media.ctrl.format == MEDIA_FORMAT_GSM_FR ||
          media.ctrl.format == MEDIA_FORMAT_GSM_HR || media.ctrl.format == MEDIA_FORMAT_GSM_EFR) {
         vmRecordHisr();
         mediaDataNotification();
      }
      break;

   case DP_D2C_SD_DONE:                   /* Voice Memo Playback */
#if VERIFY_AVSYNC
      ut_avsync_play_hisr();
#endif
#if !defined( MT6205B )
      if( media.ctrl.format == MEDIA_FORMAT_AMR || media.ctrl.format == MEDIA_FORMAT_AMR_WB)
         amrPlaybackHisr();
      else
#endif
         vmPlaybackHisr();
      mediaDataRequest();
      break;

#ifdef DAF_DECODE
   case DP_D2C_DAF:                       /* DAF Playback */
#if VERIFY_AVSYNC
      ut_avsync_play_hisr();
#endif
      dafPlaybackHisr();
      mediaDataRequest();
      break;
#endif

#ifdef AAC_DECODE
   case DP_D2C_AAC:                       /* AAC Playback */
#if VERIFY_AVSYNC
      ut_avsync_play_hisr();
#endif
      aacPlaybackHisr();
      mediaDataRequest();
      break;
#endif
   }
}
#endif

/* ------------------------------------------------------------------------------ */
/*  Media File Playback/Recording Interface                                       */
/* ------------------------------------------------------------------------------ */
extern void AudioPP_AGC_Registry(int device);

void Media_SetOutputDevice( uint8 device )
{
   AFE_SetOutputDevice( L1SP_VOICE, device );
   AFE_SetOutputDevice( L1SP_AUDIO, device );

#if defined(MT6225) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   AudioPP_AGC_Registry(device);
#endif

#if defined(AUDIO_COMPENSATION_ENABLE)
#if defined(MT6217) || defined(MT6219)
   if (*DAF_MAIN_CONTROL & 1)
#endif
      if (AM_IsAudioPlaybackOn() != -1)
         Audio_Compensation_Activate( true );
#endif
}

void  Media_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#if defined( MT6205B ) 
   // in MT6205B , digital_gain_index is the role of  volume2 , which is used to set volume of buf1 
   digital_gain_index  =  volume1;     
#endif 
   
   AFE_SetOutputVolume( L1SP_VOICE, volume1, digital_gain_index );
   AFE_SetOutputVolume( L1SP_AUDIO, volume1, digital_gain_index );
#if IS_EV_BOARD
   SetBuzVolume( volume1 );
#elif defined( EXT_AUDIO_CHIP )
   AbsExtAudChip_SetVolume( &media.ctrl , volume1 );
#endif
}

void  Media_SetLevelVolume( kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level )
{
   AFE_SetLevelVolume( L1SP_VOICE, MaxAnalogGain, step,level);
   AFE_SetLevelVolume( L1SP_AUDIO, MaxAnalogGain, step,level);
}

void Media_SetBuffer( uint16 *buffer, uint32 buf_len )
{
   media.ctrl.rb_base = buffer;
   media.ctrl.rb_size = buf_len;
   rb_ClearRB();
   media.ctrl.eof     = false;
   media.ctrl.file_len = 0;
}

void Media_GetWriteBuffer( uint16 **buffer, uint32 *buf_len )
{
   int32 count;

   if( media.ctrl.read > media.ctrl.write )
      count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   else if( media.ctrl.read == 0 )
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.write - 1;
   else
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.write;

   *buffer = &media.ctrl.rb_base[media.ctrl.write];
   *buf_len = (uint32)count;
}

void Media_WriteDataDone( uint32 len )
{
   media.ctrl.write += len;
   if( media.ctrl.write >= media.ctrl.rb_size )
      media.ctrl.write = 0;
   media.waiting = false;
}

void Media_DataFinished( void )
{
   media.ctrl.eof = true;
}

void Media_GetReadBuffer( uint16 **buffer, uint32 *buf_len )
{
   int32 count;

   if( media.ctrl.write >= media.ctrl.read )
      count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   else
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.read;

   *buffer = &media.ctrl.rb_base[media.ctrl.read];
   *buf_len = (uint32)count;
}

void Media_ReadDataDone( uint32 len )
{
   media.ctrl.read += len;
   media.ctrl.file_len += len;
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read = 0;
   media.waiting = false;
}

int32 mediaGetFreeSpace( void )
{
   int32 count;

   count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   if( count < 0 )
      count += (int32)media.ctrl.rb_size;
   return count;
}

int32 mediaGetDataCount( void )
{
   int32 count;

   count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   if( count < 0 )
      count += media.ctrl.rb_size;
   return count;
}

bool mediaIsDataConsumed( void )
{
   return media.ctrl.isDataConsumed;
}

mediaControl *mediaGetControl( void )
{
   return &media.ctrl;
}

#if !defined( MT6205B )
/* get .wav file header, return starting address pointer & header-length in byte*/
void Media_GetFileHeader( uint8 **header, uint32 *len )
{
   switch (media.ctrl.format) {
      case MEDIA_FORMAT_WAV:     /* linear PCM */
      case MEDIA_FORMAT_WAV_ALAW:     /* G.711 a-law */
      case MEDIA_FORMAT_WAV_ULAW:     /* g.711 mu-law */
      case MEDIA_FORMAT_WAV_DVI_ADPCM:    /* dvi/ima adpcm */
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         wavGetFileHeader( len );
         break;
   }
   *header = (uint8 *)media.ctrl.rb_base;
}
#endif
/* ------------------------------------------------------------------------------ */

#ifndef __L1_STANDALONE__ // avoid link error

Media_Status Media_Play( Media_Format format, void (*media_handler)( Media_Event event ), void *param )
{
   Media_Status retval;

   if( L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_REENTRY;
   if( media_handler == 0 )
      return MEDIA_NO_HANDLER;

   L1Audio_SetFlag( media.aud_id );

   KT_Stop();

   media.media_handler = media_handler;
   media.ctrl.format = format;
   media.waiting = false;
   media.paused = false;
   media.ctrl.in_speech = false;
   media.ctrl.CSD_Mode = false;
   media.ctrl.end_status = MEDIA_NONE;
   media.ctrl.isDataConsumed =true;

#if VERIFY_AVSYNC
   ut_a2v_play_dsp_start();
#endif

#if VERIFY_DATA_TO_DSP
   VERIFY_DATA_TO_DSP_START();
#endif

   switch( format ) {
      case MEDIA_FORMAT_VRD:
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
      case MEDIA_FORMAT_VRSI:
#if IS_EV_BOARD
         media.ctrl.param.vm = (int32)MEDIA_VMP_AS_SPEECH;
#else
         media.ctrl.param.vm = (int32)param;
#endif
         if( (retval = vmPlay( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
         break;

#if !defined( MT6205B )
      case MEDIA_FORMAT_AMR:
#if IS_EV_BOARD
         media.ctrl.param.vm = (int32)MEDIA_VMP_AS_SPEECH;
#else
         media.ctrl.param.vm = (int32)param;
#endif
         if( (retval = amrPlay( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
         break;
#if defined( AU_DECODE )
      case MEDIA_FORMAT_AU:
         media.ctrl.isDataConsumed = false;
         if( (retval = auPlay( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
         break;
#endif
#if defined( AIFF_DECODE )
      case MEDIA_FORMAT_AIFF:
         media.ctrl.isDataConsumed = false;
         if( (retval = aiffPlay( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
         break;
#endif
#endif

#ifdef DAF_DECODE
      case MEDIA_FORMAT_DAF:
         if( (retval = dafPlay( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
         break;
#endif
#ifdef AAC_DECODE
      case MEDIA_FORMAT_AAC:
         if( (retval = aacPlay( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
         break;
#endif
#if defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR_WB:
#if IS_EV_BOARD
         media.ctrl.param.vm = (int32)MEDIA_VMP_AS_SPEECH;
#else
         media.ctrl.param.vm = (int32)param;
#endif
         if( (retval = amrPlay( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
         break;
#endif /* AMRWB_DECODE */

      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         pcmPlay( &media.ctrl );
         break;

      case MEDIA_FORMAT_SMF:
         media.ctrl.param.smf = *(Media_SMF_Param *)param;
         if( param == 0 || media.ctrl.param.smf.smffile == 0 ) {
            L1Audio_ClearFlag( media.aud_id );
            return MEDIA_BAD_PARAMETER;
         }
#if defined( SIN_WAV_SYN ) || defined( ORDNANCE )
         if( (retval = midiPlay( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
#elif defined( SW_SYN_8K ) || defined( SW_SYN_16K )
         if( (retval = smfStart( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
#elif defined( EXT_AUDIO_CHIP )
         if( (retval = AbsExtAudChip_Play( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
#else
         ASSERT( false );
#endif
         break;

      case MEDIA_FORMAT_IMELODY:
         media.ctrl.param.imy = *(Media_iMelody_Param *)param;
         if( param == 0 || media.ctrl.param.imy.imyfile == 0 ) {
            L1Audio_ClearFlag( media.aud_id );
            return MEDIA_BAD_PARAMETER;
         }
#if IS_EV_BOARD
         if( (retval = iMelodyPlay( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
#elif defined( SW_SYN_8K ) || defined( SW_SYN_16K )
         if( (retval = imyStart( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
#elif defined( EXT_AUDIO_CHIP )
         if( (retval = AbsExtAudChip_Play( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
#else
         ASSERT( false );
#endif
         break;

      case MEDIA_FORMAT_MMF:
#if defined( EXT_AUDIO_CHIP )
         media.ctrl.param.smf = *(Media_SMF_Param *)param;
         if( (retval = AbsExtAudChip_Play( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
#else
         ASSERT( false );
#endif
         break;
      default:
         L1Audio_ClearFlag( media.aud_id );
         return MEDIA_BAD_FORMAT;
   }
   return MEDIA_SUCCESS;
}

#endif

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#ifdef PCM_EX_UNIT_TEST
#include "pcm4way.h"
static uint32 pcm_ex_test_on = 0;
static uint16 PCM_BUF[160];
static uint16 PCM_UL_BUF[8][160];
static uint16 PCM_DL_BUF[8][160];
static uint32 pcm_buf_rw;

void pcm4way_hisrHdl()
{
   uint32 I;
   int16 *buf1, *buf2;

   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      *buf2++ = (*buf1++) >> 2;
   PCM4WAY_GetFromMic((uint16*)PCM_UL_BUF[pcm_buf_rw]);
   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      (*buf2++) += (*buf1++) >> 2 * 3;
   PCM4WAY_PutToSE((const uint16*)PCM_BUF);

   buf1 = (int16*)PCM_DL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      *buf2++ = (*buf1++) >> 2;
   PCM4WAY_GetFromSD((uint16*)PCM_DL_BUF[pcm_buf_rw]);
   buf1 = (int16*)PCM_DL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      (*buf2++) += (*buf1++) >> 2 * 3;
   PCM4WAY_PutToSpk((const uint16*)PCM_BUF);

   pcm_buf_rw ++;
   pcm_buf_rw &= 0x7;
}

void pcm2way_hisrHdl()
{
   uint32 I;
   int16 *buf1, *buf2;

   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      *buf2++ = (*buf1++) >> 2;
   PCM2WAY_GetFromMic((uint16*)PCM_UL_BUF[pcm_buf_rw]);
   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      (*buf2++) += (*buf1++) >> 2 * 3;
   PCM2WAY_PutToSpk((const uint16*)PCM_BUF);

   pcm_buf_rw ++;
   pcm_buf_rw &= 0x7;
}

#endif
#endif

kal_uint32 Media_GetRecordedTime( void )
{
   if(media.recorded_time <= 0) 
      return 0;
   return media.recorded_time;      
}

kal_bool Media_IsCSDMode(void)
{
   kal_uint16 uCsdMode, uGSM_Mode;

   uCsdMode = *DP_TCH_S0_FLAGS;
   uGSM_Mode = *DP_GSM_MODE;
   uCsdMode &= 0x1F;
   uGSM_Mode &= 0x01;

   if( (uCsdMode>=0x06) && (uCsdMode<=0x0B) && (uGSM_Mode == 0x01))
      return true;
   
   return false;
}

#ifndef __L1_STANDALONE__ // avoid link error

Media_Status Media_Record( Media_Format format, void (*media_handler)( Media_Event event ), void *param )
{
   if( L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_REENTRY;
   if( media_handler == 0 )
      return MEDIA_NO_HANDLER;
   if( media.ctrl.rb_base == (uint16*)0 )
      return MEDIA_NOT_INITIALIZED;

   L1Audio_SetFlag( media.aud_id );

   media.media_handler = media_handler;
   media.ctrl.format = format;
   media.waiting = false;
   media.ctrl.in_speech = AM_IsSpeechOn();
   media.ctrl.CSD_Mode = Media_IsCSDMode();
   media.recorded_time = -40; // skip two speech frames 

#if VERIFY_AVSYNC
   ut_a2v_record_dsp_start();
#endif

   switch( format ) {
      case MEDIA_FORMAT_VRD:
         if( media.ctrl.in_speech ){
         	  L1Audio_ClearFlag( media.aud_id );
            return MEDIA_FAIL;
          }
      case MEDIA_FORMAT_GSM_FR:
         vmRecord( &media.ctrl, 0 );
         break;
      case MEDIA_FORMAT_GSM_HR:
         vmRecord( &media.ctrl, 1 );
         break;
      case MEDIA_FORMAT_GSM_EFR:
         vmRecord( &media.ctrl, 2 );
         break;
#if !defined( MT6205B )
      case MEDIA_FORMAT_AMR:
#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      #ifdef PCM_EX_UNIT_TEST
         memset( (kal_uint8 *)PCM_UL_BUF, 0x0, 2560 );
         memset( (kal_uint8 *)PCM_DL_BUF, 0x0, 2560 );
         pcm_buf_rw = 0;
         if(media.ctrl.in_speech)
         {
            L1SP_EnableSpeechEnhancement(false);
            PCM4WAY_Start(pcm4way_hisrHdl,0);
            pcm_ex_test_on = 1;
         }
         else
         {
            PCM4WAY_Start(pcm4way_hisrHdl,2);
            pcm_ex_test_on = 2;
         }
         return MEDIA_SUCCESS;
      #endif
#endif

#if defined( DEDI_AMR_REC )
         if( media.ctrl.in_speech || media.ctrl.CSD_Mode )
            amr515Record(&media.ctrl);
         else
#endif   /* DEDI_AMR_REC */
         {
            ASSERT(!media.ctrl.CSD_Mode);
            if( (uint32)param >= 3 && (uint32)param <= 10 )
               amrRecord( &media.ctrl, (uint16)(uint32)param );
            else
               amrRecord( &media.ctrl, 9 ); /* 0x03 - 0x0A */
         }
         break;
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
#endif
         wavRecord( &media.ctrl );
         break;
#endif
#if defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
         ASSERT(!media.ctrl.in_speech);
         if( (uint32)param >= 0x20 && (uint32)param <= 0x28 )/* 0x20 - 0x28 */
            amrRecord( &media.ctrl, (uint16)(uint32)param );
         else
            amrRecord( &media.ctrl, 0x20 ); 
         break;
#endif
      case MEDIA_FORMAT_PCM_8K:
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      case MEDIA_FORMAT_PCM_16K:
#endif
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         pcmRecord( &media.ctrl );
         break;
#if defined(__VOIP__)
      case MEDIA_FORMAT_VOIPEVL:
         VoIPevRecord( &media.ctrl );
         break;
#endif
      default:
      	 L1Audio_ClearFlag( media.aud_id );
         return MEDIA_BAD_FORMAT;
   }
   return MEDIA_SUCCESS;
}
#endif

#ifndef __L1_STANDALONE__ // avoid link error
Media_Status Media_Pause( void )
{
#if !defined( MT6205B )
   Media_Status retval;
#endif

   if( !L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_FAIL;

   L1Audio_ClearFlag( media.aud_id );
   media.paused = true;

   switch( media.ctrl.format ) {
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         pcmPause( &media.ctrl );
         break;
      case MEDIA_FORMAT_VRD:
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
         vmPause( &media.ctrl );
         break;
#if !defined( MT6205B )
      case MEDIA_FORMAT_AMR:
#if defined( DEDI_AMR_REC )
         if( media.ctrl.in_speech || media.ctrl.CSD_Mode)
            amr515Pause( &media.ctrl );
         else
#endif   /* DEDI_AMR_REC */
         {
            ASSERT(!media.ctrl.CSD_Mode);
            amrPause( &media.ctrl );
         }
         break;
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         wavPause( &media.ctrl );
         break;
#if defined( AU_DECODE )
      case MEDIA_FORMAT_AU:
         auPause( &media.ctrl );
         break;
#endif
#if defined( AIFF_DECODE )
      case MEDIA_FORMAT_AIFF:
         aiffPause( &media.ctrl );
         break;
#endif
#endif

#ifdef DAF_DECODE
      case MEDIA_FORMAT_DAF:
         dafPause( &media.ctrl );
         break;
#endif
#ifdef AAC_DECODE
      case MEDIA_FORMAT_AAC:
         if( (retval = aacPause( &media.ctrl ) ) != MEDIA_SUCCESS ) {
            /* If MEDIA_UNSUPPORTED_OPERATION returned, the aac may be in ADIF format */
            L1Audio_SetFlag( media.aud_id );    /* Resume L1 audio flag */
            media.paused = false;               /* Resume media.paused flag */
            return retval;
         }
         break;
#endif
#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
         amrPause( &media.ctrl );
         break;
#endif

      case MEDIA_FORMAT_SMF:
#if defined( EXT_AUDIO_CHIP )
         AbsExtAudChip_Pause( &media.ctrl );
#endif
         break;
      case MEDIA_FORMAT_IMELODY:
#if defined( EXT_AUDIO_CHIP )
         AbsExtAudChip_Pause( &media.ctrl );
#endif
         break;
      case MEDIA_FORMAT_MMF:
#if defined( EXT_AUDIO_CHIP )
         AbsExtAudChip_Pause( &media.ctrl );
#endif
         break;
#if defined(__VOIP__)
      case MEDIA_FORMAT_VOIPEVL:
         VoIPevPause();
         break;
#endif
      default:
         ASSERT(KAL_FALSE);
   }
#if VERIFY_DATA_TO_DSP
   VERIFY_DATA_TO_DSP_STOP();
#endif
   return MEDIA_SUCCESS;
}
#endif

#ifndef __L1_STANDALONE__ // avoid link error
Media_Status Media_Resume( void )
{
#if !defined( MT6205B )
   Media_Status retval;
#endif

   if( L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_FAIL;

   ASSERT( media.paused == true );
   media.paused = false;

   L1Audio_SetFlag( media.aud_id );

#if VERIFY_DATA_TO_DSP
   VERIFY_DATA_TO_DSP_RESUME();
#endif

   switch( media.ctrl.format ) {
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         pcmResume( &media.ctrl );
         break;
      case MEDIA_FORMAT_VRD:
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
         vmResume( &media.ctrl );
         break;
#if !defined( MT6205B )
      case MEDIA_FORMAT_AMR:
#if defined( DEDI_AMR_REC )
         if( media.ctrl.in_speech || media.ctrl.CSD_Mode )
            amr515Resume( &media.ctrl );
         else
#endif   /* DEDI_AMR_REC */
         {
            ASSERT(!media.ctrl.CSD_Mode);
            amrResume( &media.ctrl );
         }
         break;
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         wavResume( &media.ctrl );
         break;
#if defined( AU_DECODE )
      case MEDIA_FORMAT_AU:
         auResume( &media.ctrl );
         break;
#endif
#if defined( AIFF_DECODE )
      case MEDIA_FORMAT_AIFF:
         aiffResume( &media.ctrl );
         break;
#endif
#endif

#ifdef DAF_DECODE
      case MEDIA_FORMAT_DAF:
         if( (retval = dafResume( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
         break;
#endif
#ifdef AAC_DECODE
      case MEDIA_FORMAT_AAC:
         if( (retval = aacResume( &media.ctrl )) != MEDIA_SUCCESS ) {
            L1Audio_ClearFlag( media.aud_id );
            return retval;
         }
         break;
#endif
#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
         amrResume( &media.ctrl );
         break;
#endif

      case MEDIA_FORMAT_SMF:
#if defined( EXT_AUDIO_CHIP )
         AbsExtAudChip_Resume( &media.ctrl );
#endif
         break;
      case MEDIA_FORMAT_IMELODY:
#if defined( EXT_AUDIO_CHIP )
         AbsExtAudChip_Resume( &media.ctrl );
#endif
         break;
      case MEDIA_FORMAT_MMF:
#if defined( EXT_AUDIO_CHIP )
         AbsExtAudChip_Resume( &media.ctrl );
#endif
         break;
#if defined(__VOIP__)
      case MEDIA_FORMAT_VOIPEVL:
         VoIPevResume();
         break;
#endif
      default:
         ASSERT(KAL_FALSE);
  }
  return MEDIA_SUCCESS;
}
#endif

#ifndef __L1_STANDALONE__ // avoid link error
void Media_Stop( void )
{
   if( media.paused == true ) {
      ASSERT( !L1Audio_CheckFlag( media.aud_id ) );
      L1Audio_SetFlag( media.aud_id );
      media.paused = false;
   }

   if( !L1Audio_CheckFlag( media.aud_id ) )
      return;

   L1Audio_ClearFlag( media.aud_id );

#if VERIFY_AVSYNC
   ut_a2v_dsp_stop();
#endif

   media.waiting = true;      /* Forbid data request */
   switch( media.ctrl.format ) {
      case MEDIA_FORMAT_VRD:
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
      case MEDIA_FORMAT_VRSI:
         vmStop();
         break;
#if !defined( MT6205B )
      case MEDIA_FORMAT_AMR:
#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)  || defined(MT6235) || defined(MT6238)
      #ifdef PCM_EX_UNIT_TEST
      if(pcm_ex_test_on == 1)
         PCM4WAY_Stop(0);
      else if(pcm_ex_test_on == 2)
         PCM4WAY_Stop(2);
      pcm_ex_test_on = 0;
      return;
      #endif
#endif
#if defined( DEDI_AMR_REC )
         if( media.ctrl.in_speech || media.ctrl.CSD_Mode )
            amr515Stop();
         else
#endif   /* DEDI_AMR_REC */
         {
            ASSERT(!media.ctrl.CSD_Mode);
            amrStop();
         }
         break;
#if defined( AU_DECODE )
      case MEDIA_FORMAT_AU:
         auStop();
         break;
#endif
#if defined( AIFF_DECODE )
      case MEDIA_FORMAT_AIFF:
         aiffStop();
         break;
#endif
#endif

#ifdef DAF_DECODE
      case MEDIA_FORMAT_DAF:
         dafStop();
         break;
#endif
#ifdef AAC_DECODE
      case MEDIA_FORMAT_AAC:
         aacStop();
         break;
#endif
#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
         amrStop();
         break;
#endif

      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         pcmStop();
         break;
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         wavStop();
         break;

      case MEDIA_FORMAT_SMF:
#if defined( SIN_WAV_SYN ) || defined( ORDNANCE )
         midiStop();
#elif defined( SW_SYN_8K ) || defined( SW_SYN_16K )
         smfStop();
#elif defined( EXT_AUDIO_CHIP )
         AbsExtAudChip_Stop( &media.ctrl );
#endif
         break;
      case MEDIA_FORMAT_IMELODY:
#if IS_EV_BOARD
         iMelodyStop();
#elif defined( SW_SYN_8K ) || defined( SW_SYN_16K )
         imyStop();
#elif defined( EXT_AUDIO_CHIP )
         AbsExtAudChip_Stop( &media.ctrl );
#endif
         break;

      case MEDIA_FORMAT_MMF:
#if defined( EXT_AUDIO_CHIP )
         AbsExtAudChip_Stop( &media.ctrl );
#endif
         break;
#if defined(__VOIP__)
      case MEDIA_FORMAT_VOIPEVL:
         VoIPevStop();
         break;
#endif
      default:
         ASSERT(KAL_FALSE);
   }
#if VERIFY_DATA_TO_DSP
   VERIFY_DATA_TO_DSP_STOP();
#endif
}
#endif

Media_Status Media_Control( Media_Ctrl ctrl_no, int32 ctrl_val )
{
   switch( ctrl_no ) {
   case MEDIA_CTRL_MAX_SWING:
#if defined( SW_SYN_8K ) || defined( SW_SYN_16K )
      if( ctrl_val > 32767 || ctrl_val < 0 )
         return MEDIA_BAD_PARAMETER;
      media.ctrl.max_swing = ctrl_val >> 3;
#else
      return MEDIA_BAD_COMMAND;
#endif
      break;

   case MEDIA_CTRL_KEY_SHIFT:
#if defined( SW_SYN_8K ) || defined( SW_SYN_16K )
      if( ctrl_val > 64 || ctrl_val < -64 )
         return MEDIA_BAD_PARAMETER;
      media.ctrl.key_shift = ctrl_val;
#else
      return MEDIA_BAD_COMMAND;
#endif
      break;
   default:
      return MEDIA_BAD_COMMAND;
   }
   return MEDIA_SUCCESS;
}


void Media_SetMelodyFilter( uint16 len, const int16 *filter )
{      
#ifdef DSP_WT_SYN  
   int32 I;    
   ASSERT( len == 25 );             
   for( I = 0; I < 25; I++ )
      media.ctrl.Media_FIR_Melody32K_1[I] = filter[I];             
#endif         
}

Media_Status Media_SetLevel( kal_uint8 level )
{
   media.ctrl.level = level;
   if( !L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_SUCCESS;
   switch( media.ctrl.format ) {
#if !defined( MT6205B )
      case MEDIA_FORMAT_AMR:
         amrUpdateLevel();
         break;
      case MEDIA_FORMAT_WAV:
         wavUpdateLevel();
         break;
#if defined( AU_DECODE )
      case MEDIA_FORMAT_AU:
         auUpdateLevel();
         break;
#endif
#if defined( AIFF_DECODE )
      case MEDIA_FORMAT_AIFF:
         aiffUpdateLevel();
         break;
#endif
#endif

#ifdef DAF_DECODE
      case MEDIA_FORMAT_DAF:
         dafUpdateLevel();
         break;
#endif
#ifdef AAC_DECODE
      case MEDIA_FORMAT_AAC:
         aacUpdateLevel();
         break;
#endif
#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
         amrUpdateLevel();
         break;
#endif

      default:
         ASSERT(KAL_FALSE);
   }

   return MEDIA_SUCCESS;
}

kal_uint8 Media_GetLevel( void )
{
   return media.ctrl.level;
}

/* ------------------------------------------------------------------------------ */
void mediaHandler( void *data )     /* This function works in L1Audio Task */
{
   Media_Event event = (Media_Event)(int32)data;

   if( event == MEDIA_TERMINATED || !L1Audio_CheckFlag( media.aud_id ))      /* MEDIA_TERMINATED is no longer used */
      return;
   if( event == MEDIA_END || event == MEDIA_ERROR ) {
      L1Audio_ClearFlag( media.aud_id );
      media.waiting = false;
   }
   media.media_handler( event );
}
/* ------------------------------------------------------------------------------ */
kal_semid  WAVsema;

void mediaInit( uint16 aud_id )
{
   WAVsema = kal_create_sem( "wav_sema", 1 );

   media.aud_id = aud_id;
   L1Audio_SetEventHandler( media.aud_id, mediaHandler );
#if IS_EV_BOARD
   iMelodyInit( L1Audio_GetAudioID() );
#endif

#if !defined( MT6205B )
#if defined( DEDI_AMR_REC )
   amr515Init( L1Audio_GetAudioID() );
#endif   /* DEDI_AMR_REC */
   wavInit( L1Audio_GetAudioID() );
#endif

#if defined( SIN_WAV_SYN ) || defined( ORDNANCE )
   gmiInit( L1Audio_GetAudioID() );
#elif defined( SW_SYN_8K ) || defined( SW_SYN_16K )
   smfInit( L1Audio_GetAudioID() );
   imyInit( L1Audio_GetAudioID() );
#elif defined( EXT_AUDIO_CHIP )
   AbsExtAudChip_Init( L1Audio_GetAudioID() );
#elif defined( DSP_WT_SYN )
   DSPSYN_Init();
   JSmf_Init();
   JImy_Init();
   JWav_Init( &media.ctrl );
#if defined(__VOIP__)
   VoIPevInit();
#endif

   Media_SetMelodyFilter( 25, Melody_FIR );
#endif

   media.ctrl.rb_threshold = MEDIA_RB_DEFAULT_THRESHOLD;
   media.ctrl.max_swing = (int32)Media_Playback_Maximum_Swing >> 3;
   media.ctrl.key_shift = 0;
   media.ctrl.level = 100;
   media.ctrl.rb_base = (uint16*)0;
   GPTI_GetHandle( &media.ctrl.gpt );
}

/* If the event is MEDIA_END or MEDIA_ERROR, make sure DSP has been stopped
   before calling this function. Refer to the function: mediaHandler */
void mediaSetEvent( Media_Event event )
{
   L1Audio_SetEvent( media.aud_id, (void *)event );
}

bool mediaKeytoneForbidden( void )
{
#if defined( SW_SYN_8K ) || defined( SW_SYN_16K ) || defined( DSP_WT_SYN )
   if( L1Audio_CheckFlag( media.aud_id ) )
      return true;
#endif
   return false;
}

void Media_SetRBThreshold( uint16 threshold )
{
   media.ctrl.rb_threshold = threshold;
}

#ifndef __L1_STANDALONE__ // avoid link error
// Audio Framewrok Revise

static void mhdlSetBuffer( MHdl *hdl, kal_uint8 *buffer, kal_uint32 buf_len )
{
   hdl->rb_base = buffer;
   hdl->rb_size = buf_len;
   hdl->write = 0;
   hdl->read = 0;
   hdl->eof = false;
   hdl->waiting = false;
}

static void mhdlGetWriteBuffer( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   int32 count;

   if( hdl->read > hdl->write )
      count = hdl->read - hdl->write - 1;
   else if( hdl->read == 0 )
      count = hdl->rb_size - hdl->write - 1;
   else
      count = hdl->rb_size - hdl->write;

   ASSERT( count>=0 );
   *buffer = (uint8 *)&hdl->rb_base[hdl->write];
   *buf_len = count;
}

static void mhdlGetReadBuffer( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   int32 count;

   if( hdl->write >= hdl->read )
      count = hdl->write - hdl->read;
   else
      count = hdl->rb_size - hdl->read;

   ASSERT( count>=0 );
   *buffer = (uint8 *)&hdl->rb_base[hdl->read];
   *buf_len = count;
}

static Media_Status mhdlSetLevel( MHdl *hdl, kal_uint8 level )
{
   ASSERT( level <= 100 );
   hdl->volume_level = level;
   AFE_SetDigitalGain( L1SP_AUDIO, level );
   AFE_SetDigitalGain( L1SP_VOICE, level );
   return MEDIA_SUCCESS;
}

static void mhdlWriteDataDone( MHdl *hdl, kal_uint32 len ) // in bytes
{
   hdl->write += len;

   ASSERT(hdl->write <= hdl->rb_size);
   if( hdl->write == hdl->rb_size )
      hdl->write = 0;
}

static void mhdlReadDataDone( MHdl *hdl, kal_uint32 len ) // in bytes
{
   hdl->read += len;

   ASSERT(hdl->read <= hdl->rb_size);
   if( hdl->read == hdl->rb_size )
      hdl->read = 0;
   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_READ_BYTE, len );
}

static void mhdlDataFinished( MHdl *hdl )
{
   hdl->eof = true;
}
#if !defined( MT6205B )
static void mhdlFinishWriteData( MHdl *hdl )
{
   hdl->waiting = false;
}

static void mhdlResetMediaBuf( MHdl *hdl )
{
   hdl->write = 0;
   hdl->read = 0;
   hdl->eof = false;
   hdl->waiting = false;
}
#endif // #if !defined( MT6205B )
static kal_uint8 mhdlGetLevel( MHdl *hdl )
{
   return hdl->volume_level;
}

static Media_Status mhdlSetStartTime( MHdl *hdl, kal_uint32 msStartTime )
{
   hdl->start_time = msStartTime;
   hdl->uSeekProgress = 0;
   hdl->uCurSeekFrm = 0;
   kal_trace( TRACE_FUNC, L1AUDIO_SET_START_TIME, msStartTime, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static Media_Status mhdlSetStopTime( MHdl *hdl, kal_uint32 msStopTime )
{
   hdl->stop_time = msStopTime;
   kal_trace( TRACE_FUNC, L1AUDIO_SET_STOP_TIME, msStopTime, hdl->mediaType );
   return MEDIA_SUCCESS;
}

static void mhdlSetStoreFlag( MHdl *hdl, kal_bool fStoreLastFileOffset )
{
   hdl->fStoreFileOffset = fStoreLastFileOffset;
}

static void mhdlStoreFileOffset(MHdl *hdl)
{
   audResumeInfo.uResumeFrameOffset = audResumeInfo.uCurOffset;
}

static kal_uint32 mhdlGetFileOffset(MHdl *hdl)
{
   return audResumeInfo.uCurOffset;
}

static void mhdlSetFileOffset( MHdl *hdl, kal_uint32 uCurOffset)
{
   audResumeInfo.uResumeFrameOffset = uCurOffset;
}

static kal_uint32 mhdlGetCurrentTime( MHdl *hdl )
{
   hdl->fStoreFileOffset = false;
   return hdl->current_time;
}

static kal_uint32 mhdlGetTotalDuration( MHdl *hdl )
{
   return hdl->uTotalDuration;
}

static int32 mhdlGetFreeSpace( MHdl *hdl )
{
   int32 count;

   count = hdl->read - hdl->write - 1;
   if( count < 0 )
      count += hdl->rb_size;
   return count; // free size in byte
}

static int32 mhdlGetDataCount( MHdl *hdl )
{
   return hdl->rb_size - mhdlGetFreeSpace(hdl) - 1;
}

static void mhdlCallbackTask( void *data )
{
   MHdl *hdl = (MHdl *)data;
   hdl->handler( hdl, (Media_Event)hdl->data );
}

#if APM_SUPPORT
static void mhdlEndHandler( void *data, Media_Event event )
{
    MHdl *hdl;
    
    hdl = (MHdl *) data;
    hdl->data = (uint32)event;
    L1Audio_SetEvent( hdl->aud_id, hdl );
}
#endif

void mhdlException( MHdl *hdl, Media_Event event )
{
#if APM_SUPPORT
   if (event==MEDIA_END || event == MEDIA_STOP_TIME_UP) {
      APM_NOTIFY_MEDIA_END(mhdlEndHandler, (void *)hdl, true, event);
   }
   else
#endif
   {
      hdl->data = (uint32)event;
      L1Audio_SetEvent( hdl->aud_id, hdl );
   }
}

void mhdlAllowSleep( MHdl *hdl )
{
   L1Audio_ClearFlag( hdl->aud_id );
   ktUnlock();
}

void mhdlDisallowSleep( MHdl *hdl )
{
   L1Audio_SetFlag( hdl->aud_id ); // disable sleep mode
   ktLock();
}

void mhdlDataRequest( MHdl *hdl, Media_Event end_status)
{
   if( hdl->waiting || hdl->eof || (end_status == MEDIA_END) )
      return;
   if( hdl->GetFreeSpace(hdl) >= (MEDIA_RB_DEFAULT_THRESHOLD << 2) ) {
      mhdlException( hdl, MEDIA_DATA_REQUEST );
      hdl->waiting = true;
   }
}

void mhdlDataNotification( MHdl *hdl )
{
   if( hdl->waiting )
      return;
   if( hdl->GetDataCount(hdl) >= (MEDIA_RB_DEFAULT_THRESHOLD << 2) ) {
      mhdlException( hdl, MEDIA_DATA_NOTIFICATION );
      hdl->waiting = true;
   }
}

void mhdlInit( MHdl *hdl, uint32 hisrMagic, void hisrHdlr( void *data ) )
{
   ASSERT(hdl);

   memset(hdl, 0, sizeof(MHdl));

   hdl->SetBuffer = mhdlSetBuffer;
   hdl->GetWriteBuffer = mhdlGetWriteBuffer;
   hdl->GetReadBuffer = mhdlGetReadBuffer;
   hdl->WriteDataDone = mhdlWriteDataDone;
#if !defined( MT6205B )
   hdl->FinishWriteData = mhdlFinishWriteData;
   hdl->ResetMediaBuf = mhdlResetMediaBuf;
#endif // #if !defined( MT6205B )
   hdl->ReadDataDone = mhdlReadDataDone;
   hdl->DataFinished = mhdlDataFinished;
   hdl->GetFreeSpace = mhdlGetFreeSpace;
   hdl->GetDataCount = mhdlGetDataCount;
   hdl->SetLevel = mhdlSetLevel;
   hdl->GetLevel = mhdlGetLevel;
   hdl->SetStartTime = mhdlSetStartTime;
   hdl->SetStopTime = mhdlSetStopTime;
   hdl->GetCurrentTime = mhdlGetCurrentTime;
   hdl->GetTotalDuration = mhdlGetTotalDuration;
   hdl->SetStoreFlag = mhdlSetStoreFlag;
   hdl->StoreFileOffset = mhdlStoreFileOffset;
   hdl->GetFileOffset = mhdlGetFileOffset;
   hdl->SetFileOffset = mhdlSetFileOffset;

   if(0xFFFF != hisrMagic){
      mhdlSetLevel( hdl, 100 );
      hdl->stop_time = 0xFFFFFFFF;
      hdl->aud_id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( hdl->aud_id, mhdlCallbackTask );
      L1Audio_HookHisrHandler( hisrMagic, hisrHdlr, (void*)hdl );
   }
}

void mhdlInitEx( MHdl *hdl, uint32 hisrMagic, void hisrHdlr( void *data ) )
{
   ASSERT(hdl);

   memset(hdl, 0, sizeof(MHdl));
   hdl->stop_time = 0xFFFFFFFF;

   hdl->SetBuffer = mhdlSetBuffer;
   hdl->GetWriteBuffer = mhdlGetWriteBuffer;
   hdl->GetReadBuffer = mhdlGetReadBuffer;
   hdl->WriteDataDone = mhdlWriteDataDone;
#if !defined( MT6205B )
   hdl->FinishWriteData = mhdlFinishWriteData;
   hdl->ResetMediaBuf = mhdlResetMediaBuf;
#endif // #if !defined( MT6205B )
   hdl->ReadDataDone = mhdlReadDataDone;
   hdl->DataFinished = mhdlDataFinished;
   hdl->GetFreeSpace = mhdlGetFreeSpace;
   hdl->GetDataCount = mhdlGetDataCount;
   hdl->SetLevel = mhdlSetLevel;
   hdl->GetLevel = mhdlGetLevel;
   hdl->SetStartTime = mhdlSetStartTime;
   hdl->SetStopTime = mhdlSetStopTime;
   hdl->GetCurrentTime = mhdlGetCurrentTime;
   hdl->GetTotalDuration = mhdlGetTotalDuration;
   hdl->SetStoreFlag = mhdlSetStoreFlag;
   hdl->StoreFileOffset = mhdlStoreFileOffset;
   hdl->GetFileOffset = mhdlGetFileOffset;
   hdl->SetFileOffset = mhdlSetFileOffset;
}

void mhdlFinalize( MHdl *hdl, uint32 hisrMagic )
{
   if(0xFFFF != hisrMagic){
   	  mhdlSetLevel( hdl, 100 );
      L1Audio_UnhookHisrHandler( hisrMagic );
      L1Audio_FreeAudioID( hdl->aud_id );
   }
}

kal_uint8 autGetBitsFromBuf(kal_uint8 *pBuf, kal_uint32 *puBitCnt, kal_uint32 uBitLen)
{
	static kal_uint8 bCurByte;
	kal_uint8 bMask;
	kal_uint32 uCurBitPos;
	kal_uint8 bValue;

   ASSERT(puBitCnt!=NULL);
	ASSERT(uBitLen>=1 && uBitLen<=8);

	uCurBitPos = *puBitCnt % 8;

	if(uCurBitPos==0) {
	   bCurByte = pBuf[*puBitCnt/8];
	}

	*puBitCnt += uBitLen;

	if(uCurBitPos+uBitLen<=8) {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		bValue = (unsigned char)((bCurByte&bMask) >> (8-(uCurBitPos+uBitLen)));
	} else {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		bValue = (unsigned char)((bCurByte&bMask) << (uBitLen-(8-uCurBitPos)));
		bCurByte = pBuf[*puBitCnt/8];
		bValue |= bCurByte>>(16-uBitLen-uCurBitPos);
	}
	return bValue;
}

kal_int32 autGetBytesFromFile(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr)
{
   kal_uint32 file_size, data_size;

   FSAL_GetFileSize(pstFSAL, &file_size);
   data_size = file_size - fileOffset;

   if(data_size <= num_bytes){  // EOF
      num_bytes = data_size;
      hdl->DataFinished(hdl);
   }

   FSAL_Seek( pstFSAL, fileOffset);
   if(FSAL_Read_Bytes( pstFSAL, ptr, num_bytes) != FSAL_OK)
      return -1; // Playback should be terminated

   if(hdl->eof && ((hdl->write + num_bytes)&0x01)){ // zero padding in last odd byte
      ptr[num_bytes] = 0;
      num_bytes++;
   }
   return num_bytes;
}

kal_int32 autGetBytes(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 uLen, kal_uint8 *pbBuf)
{
   kal_uint32 uDataSize, uFileSize, uCurPos;

   if(uLen == 0) return 0;
   FSAL_GetCurPos(pstFSAL, &uCurPos);
   FSAL_GetFileSize(pstFSAL, &uFileSize);
   uDataSize = uFileSize - uCurPos;

   if(uDataSize <= uLen){
      uLen = uDataSize;
      hdl->DataFinished(hdl);
   }
   if(uLen == 0) return 0;

   if(FSAL_Read_Bytes( pstFSAL, pbBuf, uLen) != FSAL_OK)
      return -1;

   if(hdl->eof && ((hdl->write + uLen)&0x01)){
      pbBuf[uLen] = 0;
      uLen++;
   }
   return uLen;
}

void autSkipID3Tag( MHdl *hdl, STFSAL *pstFSAL, kal_uint32 *fileOffset, kal_uint8 *ptr )
{
   kal_uint32 num_bytes, file_size, tagsize;

   while(1){
      tagsize = 0;
      num_bytes = autGetBytesFromFile(hdl, pstFSAL, *fileOffset, ID3V2_HEADER_LEN, ptr);
      if(num_bytes != ID3V2_HEADER_LEN) return;
      
      if (kal_mem_cmp(ptr, "ID3", 3) == 0)
	   {
         tagsize = (ptr[6] << 21) | (ptr[7] << 14) |
               (ptr[8] <<  7) | (ptr[9] <<  0);
      
         FSAL_GetFileSize(pstFSAL, &file_size);
         if(file_size >= (tagsize + 10)){ // Don't skip ID3 tag if tagsize is invalid
            *fileOffset += (tagsize+10);            
         }else{
             return;
          }
         
      }else
         return;
   }
}
/* return dspDataConsume in word */
static kal_int32 autWriteDataByIDMA( MHdl *hdl, volatile kal_uint16 *dspWritePtr, volatile kal_uint16 *dspReadPtr, kal_uint32 pageNum, kal_int32 mblenInWord )
{
   kal_int32 I, count, DSP_FreeLenLow, DSP_R, DSP_FreeLen;
   kal_uint16 DSP_W;
   const kal_uint16 *buf;
   DSP_W = *dspWritePtr;

   buf = (uint16 *)&hdl->rb_base[hdl->read];

   do {
      DSP_R = (int32)*dspReadPtr;
   } while( DSP_R != (int32)*dspReadPtr );

   DSP_FreeLen = DSP_R - (int32)DSP_W - 1;
   if( DSP_FreeLen < 0 )
      DSP_FreeLen += hdl->dsp_rb_size;

   if(hdl->mono2stereo){
      mblenInWord <<= 1;
      if(DSP_FreeLen <= 1)
         return 0;
      DSP_FreeLen &= 0xFFFE;
   }

   if( DSP_FreeLen < mblenInWord )
      mblenInWord = DSP_FreeLen;

   if( mblenInWord == 0 )
      return 0;

   switch (hdl->mediaType) {
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_AIFF:
      case MEDIA_FORMAT_AU:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         DSP_FreeLenLow = (int32)(hdl->dsp_rb_size - DSP_W);
         break;
      default:
         DSP_FreeLenLow = (int32)(hdl->dsp_rb_end - DSP_W);
   }

   if( DSP_FreeLenLow > mblenInWord )
      DSP_FreeLenLow = mblenInWord;

   switch (hdl->mediaType) {
      uint16 tmp;
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_AIFF:
      case MEDIA_FORMAT_AU:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         tmp = *buf++;
         DSP_WRITE( DSP_DM_ADDR(pageNum, (DSP_W+hdl->dsp_rb_base) ), tmp );
         kal_prompt_trace( MOD_L1SPHISR, "1stDSPStrAddr=%d, Len=%d", (DSP_W+hdl->dsp_rb_base), DSP_FreeLenLow );
         if(hdl->mono2stereo)
            DSP_WRITE( IDMA_SHORT_ADDR, tmp );
         break;
      case MEDIA_FORMAT_WMA:
      case MEDIA_FORMAT_MUSICAM:
         DSP_WRITE( DSP_DM_ADDR(pageNum, DSP_W), *buf++ );
         kal_prompt_trace( MOD_L1SPHISR, "1stDSPStrAddr=%d, Len=%d", DSP_W, DSP_FreeLenLow );
         break;
      default:
         DSP_WRITE( DSP_PM_ADDR(pageNum, DSP_W), *buf++ );
         kal_prompt_trace( MOD_L1SPHISR, "1stDSPStrAddr=%d, Len=%d", DSP_W, DSP_FreeLenLow );
   }

   if(hdl->mono2stereo)
      for( I = DSP_FreeLenLow-2; I > 0; I-=2 ){
         DSP_WRITE( IDMA_SHORT_ADDR, *buf );
         DSP_WRITE( IDMA_SHORT_ADDR, *buf++ );
      }
   else
      for( I = DSP_FreeLenLow-1; I > 0; I-- ){
         DSP_WRITE( IDMA_SHORT_ADDR, *buf++ );
      }

   DSP_W += (uint16)DSP_FreeLenLow;
   switch (hdl->mediaType) {
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_AIFF:
      case MEDIA_FORMAT_AU:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         if( DSP_W >= hdl->dsp_rb_size )
            DSP_W = 0;
         break;
      default:
         if( DSP_W >= hdl->dsp_rb_end )
            DSP_W = hdl->dsp_rb_base;
   }

   *dspWritePtr = DSP_W;

   count = mblenInWord - DSP_FreeLenLow;

   if( count > 0 ) {
       switch (hdl->mediaType) {
         uint16 tmp;
         case MEDIA_FORMAT_WAV:
         case MEDIA_FORMAT_AIFF:
         case MEDIA_FORMAT_AU:
         case MEDIA_FORMAT_PCM_8K:
         case MEDIA_FORMAT_PCM_16K:
         case MEDIA_FORMAT_G711_ALAW:
         case MEDIA_FORMAT_G711_ULAW:
         case MEDIA_FORMAT_DVI_ADPCM:
            tmp = *buf++;
            DSP_WRITE( DSP_DM_ADDR(pageNum, (DSP_W+hdl->dsp_rb_base)), tmp );
            kal_prompt_trace( MOD_L1SPHISR, "2ndDSPStrAddr=%d, Len=%d", (DSP_W+hdl->dsp_rb_base), count );
            if(hdl->mono2stereo)
               DSP_WRITE( IDMA_SHORT_ADDR, tmp );
            break;
         case MEDIA_FORMAT_WMA:
         case MEDIA_FORMAT_MUSICAM:
            DSP_WRITE( DSP_DM_ADDR(pageNum, DSP_W), *buf++ );
            kal_prompt_trace( MOD_L1SPHISR, "2ndDSPStrAddr=%d, Len=%d", DSP_W, count );
            break;
         default:
            DSP_WRITE( DSP_PM_ADDR(pageNum, DSP_W), *buf++ );
            kal_prompt_trace( MOD_L1SPHISR, "2ndDSPStrAddr=%d, Len=%d", DSP_W, count );
      }

      if(hdl->mono2stereo)
         for( I = count-2; I > 0; I-=2 ){
            DSP_WRITE( IDMA_SHORT_ADDR, *buf );
            DSP_WRITE( IDMA_SHORT_ADDR, *buf++ );
         }
      else
         for( I = count-1; I > 0; I-- ){
            DSP_WRITE( IDMA_SHORT_ADDR, *buf++ );
         }

      *dspWritePtr = DSP_W + (uint16)count;
   }
   
   if(hdl->mono2stereo)
      return (mblenInWord>>1);
   else
      return mblenInWord;
}

void autWriteDataToDSP( MHdl *hdl, kal_uint16 *dspWritePtr, kal_uint16 *dspReadPtr, kal_uint32 pageNum,
   void(*incTime)( MHdl *handle, uint32 num_bytes ))
{
   kal_int32 mbDataLen, mbDataLenLow, mbDataLenHigh;
   SSHdl *my_ss_handle = hdl->ss_handle;

   mbDataLen = hdl->GetDataCount(hdl) >> 1; // in word
   mbDataLenLow = (hdl->rb_size - hdl->read) >> 1; // in word
   if( mbDataLenLow > mbDataLen )
      mbDataLenLow = mbDataLen;
   mbDataLenHigh = mbDataLen - mbDataLenLow;

   mbDataLenLow = autWriteDataByIDMA( hdl, dspWritePtr, dspReadPtr, pageNum, mbDataLenLow );
   kal_prompt_trace( MOD_L1SPHISR, "1st,MBR=%d,%dW", hdl->read, mbDataLenLow );
   mbDataLenLow <<= 1; // in Byte
   incTime(hdl, mbDataLenLow);
   if( is_SSHdl_valid(my_ss_handle) )
      my_ss_handle->PutData(my_ss_handle, &hdl->rb_base[hdl->read], mbDataLenLow);
   hdl->read += mbDataLenLow;

   if( hdl->read >= hdl->rb_size ){
      hdl->read = 0;
      if( mbDataLenHigh > 0 ) {
         mbDataLenHigh = autWriteDataByIDMA( hdl, dspWritePtr, dspReadPtr, pageNum, mbDataLenHigh );
         kal_prompt_trace( MOD_L1SPHISR, "2nd,MBR=%d,%dW", hdl->read, mbDataLenHigh );
         mbDataLenHigh <<= 1; // in Byte
         incTime(hdl, mbDataLenHigh);
         if( is_SSHdl_valid(my_ss_handle) )
            my_ss_handle->PutData(my_ss_handle, &hdl->rb_base[hdl->read], mbDataLenHigh);
         hdl->read += mbDataLenHigh;
      }
   }
}

#endif // #ifndef __L1_STANDALONE__
/* ------------------------------------------------------------------------------ */
