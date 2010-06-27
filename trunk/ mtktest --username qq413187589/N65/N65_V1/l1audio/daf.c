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
 * daf.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   DAF playback
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "media.h"
#include "ddload.h"
#include "afe.h"

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DSP_DAF_IDMA_ADDR          IDMA2_SHORT_ADDR
#define DSP_DAF_PM_ADDR( _page, _addr )   DSP2_PM_ADDR( _page, _addr )
#else
#define DSP_DAF_IDMA_ADDR          ((volatile uint16*)0x60310000L)
#define DSP_DAF_PM_ADDR( _page, _addr )   ((volatile uint16*)(0x60100000L+((_page)<<16)+((_addr)<<1)))
#endif

#define ONE_EXTRA_SLOT  1

#ifdef DAF_DECODE

static struct{
   mediaControl   *ctrl;
} daf;

static const uint16 DAF_BIT_RATE_TABLE_V1[15]={0, 32, 40, 48, 56, 64, 80, 96, 112,
                                            128, 160, 192, 224, 256, 320};
static const uint16 DAF_BIT_RATE_TABLE_V2[15]={0, 8, 16, 24, 32, 40, 48, 56, 64, 80,
                                            96, 112, 128, 144, 160};
static const uint16 ASP_FS_TABLE[3][3]={ {0x11,0x12,0x00},
                                         {0x21,0x22,0x20},
                                         {0x41,0x42,0x40}};
                                            
/* ------------------------------------------------------------------------------ */
static int32 dafWriteIDMA( const uint16 *buf, int32 len )
{
   int32 I, count;
   uint16 rb_w;

   rb_w = *DAF_MCU_WRITE_PTR;

   do {
      I = (int32)*DAF_DSP_READ_PTR;
   } while( I != (int32)*DAF_DSP_READ_PTR );

   I = I - (int32)rb_w - 1;
   if( I < 0 )
      I += daf.ctrl->dsp_rb_size;

   if( I < len )
      len = I;

   if( len == 0 )
      return 0;

   count = (int32)(daf.ctrl->dsp_rb_end - rb_w);
   if( count > len )
      count = len;

   *(DSP_DAF_PM_ADDR(0, rb_w)) = *buf++;
   for( I = 1; I < count; I++ )
      *(DSP_DAF_IDMA_ADDR) = *buf++;

   rb_w += (uint16)count;
   if( rb_w >= daf.ctrl->dsp_rb_end )
      rb_w = daf.ctrl->dsp_rb_base;
   *DAF_MCU_WRITE_PTR = rb_w;

   count = len - count;
   if( count > 0 ) {
     *(DSP_DAF_PM_ADDR(0, rb_w)) = *buf++;
     for( I = 1; I < count; I++ )
        *(DSP_DAF_IDMA_ADDR) = *buf++;

     *DAF_MCU_WRITE_PTR = rb_w + (uint16)count;
   }

   return len;
}

static void dafWriteToDSP( void )
{
   int32 I, count;

   count = mediaGetDataCount();

   I = daf.ctrl->rb_size - daf.ctrl->read;
   if( I > count )
      I = count;
   count -= I;

   I = dafWriteIDMA( &daf.ctrl->rb_base[daf.ctrl->read], I );
   daf.ctrl->read += I;

   if( daf.ctrl->read >= daf.ctrl->rb_size ){
      daf.ctrl->read = 0;
      if( count > 0 ) {
         I = dafWriteIDMA( &daf.ctrl->rb_base[daf.ctrl->read], count );
         daf.ctrl->read += I;
      }
   }
}

/* ------------------------------------------------------------------------------ */
void dafPlaybackHisr( void )
{
   uint16 *ptr;
   int32 count;

   if( daf.ctrl->end_status == MEDIA_TERMINATED )
      return;
   if( *DAF_MAIN_CONTROL == 0 ) {           /* DSP returns to idle state */
      AM_AudioPlaybackOff( false );
      mediaSetEvent( MEDIA_END );
      return;
   }
   if( daf.ctrl->end_status == MEDIA_END )
      return;
   if( daf.ctrl->dsp_rb_base == 0 ) {
      daf.ctrl->dsp_rb_base = *DAF_FIFO_BASE;
      daf.ctrl->dsp_rb_size = *DAF_FIFO_LENGTH;
      daf.ctrl->dsp_rb_end = daf.ctrl->dsp_rb_base + daf.ctrl->dsp_rb_size;
   }
   if(mediaGetDataCount() > 64 && daf.ctrl->eof){ /* remove ID3v1 */
      count = (int32)daf.ctrl->write - 64;
      if( count < 0 )
         count += daf.ctrl->rb_size;
      ptr = &daf.ctrl->rb_base[count];
      if((*(uint16*)(ptr)==0x4154) && (*(uint8*)(ptr+1)== 0x47)) /* TAG */
         daf.ctrl->write = (uint32)count;
   }
   dafWriteToDSP();
   if( mediaGetDataCount() == 0 && daf.ctrl->eof ) {
      daf.ctrl->end_status = MEDIA_END;
      if( *DAF_MAIN_CONTROL == 1 )
         *DAF_MAIN_CONTROL = 7;
   }
}

/* ------------------------------------------------------------------------------ */

/***************************************************/
/** check frame length to sync. next frame header **/
/***************************************************/

void dafChkFrameLen(uint16 FHeader1, uint16 FHeader2, int16* daf_frame_length)
{   	
   uint16 MPEGver;
   int32 bit_rate, sample_rate;
   
   MPEGver = (FHeader1>>11) & 3;         /* check MPEG audio version ID */
   sample_rate = (FHeader2 >> 2) & 3; /* sampling rate frequency index */
   
   /* check sampling rate */
   if( MPEGver == 3 && sample_rate == 0 )         /* MPEG1, 44100 */
      sample_rate = 44100;              
   else if( MPEGver == 3 && sample_rate == 1 )    /* MPEG1, 48000 */
      sample_rate = 48000;              
   else if( MPEGver == 3 && sample_rate == 2 )    /* MPEG1, 32000 */
      sample_rate = 32000;              
   else if( MPEGver == 2 && sample_rate == 0 )    /* MPEG2, 22050 */
      sample_rate = 22050;              
   else if( MPEGver == 2 && sample_rate == 1 )    /* MPEG2, 24000 */
      sample_rate = 24000;              
   else if( MPEGver == 2 && sample_rate == 2 )    /* MPEG2, 16000 */
      sample_rate = 16000;              
   else if( MPEGver == 0 && sample_rate == 0 )    /* MPEG2.5, 11025 */
      sample_rate = 11025;              
   else if( MPEGver == 0 && sample_rate == 1 )    /* MPEG2.5, 12000 */
      sample_rate = 12000;              
   else if( MPEGver == 0 && sample_rate == 2 )    /* MPEG2.5, 8000 */
      sample_rate = 8000;
      
   /* check bit rate */
   if( MPEGver == 3 ){                          /* MPEG1 */
      bit_rate = DAF_BIT_RATE_TABLE_V1[(FHeader2 >> 4) & 0x0F];
      *daf_frame_length = (int16)(144*bit_rate*1000/sample_rate);	
   }else{                                    /* MPEG2, MPEG2.5 */
      bit_rate = DAF_BIT_RATE_TABLE_V2[(FHeader2 >> 4) & 0x0F];             
      *daf_frame_length = (int16)(72*bit_rate*1000/sample_rate);	
    }
}

/***************************************************/
/*    Fetch next frame header to check validity    */
/***************************************************/

bool dafChkNextFrame(int16 frame_length, bool Odd, int16 tmp_cnt,
                     uint16 header1, uint16 header2)
{
   bool flag;
   uint16 data1, data2;
   if(frame_length%2) /* unit: byte , if byte # is odd, change matching case */
      flag = true;
   else
      flag = false;
      
   if(Odd)
      frame_length = (frame_length+1)>>1;   /* unit: word */
   else{
      frame_length = (frame_length)>>1;
      flag = !flag;
   }
      
   if( (tmp_cnt + frame_length) < daf.ctrl->rb_size )    /* fetch next frame header */
      data1 = daf.ctrl->rb_base[tmp_cnt + frame_length];
   else
      data1 = daf.ctrl->rb_base[tmp_cnt + frame_length - daf.ctrl->rb_size];         
            
   if( (tmp_cnt + 1 + frame_length) < daf.ctrl->rb_size )
      data2 = daf.ctrl->rb_base[tmp_cnt + 1 + frame_length];
   else
      data2 = daf.ctrl->rb_base[tmp_cnt + 1 + frame_length - daf.ctrl->rb_size];
      
   if(flag){  /* change to word alignment */
      if( ((data1 & 0x1800) != 0x0800) && ((data1 & 0xE6FF) == 0xE2FF)
         && ((data2 & 0x00F0) != 0x00F0)&& ((data2 & 0x000C) != 0x000C))
         if( (header1&0xFEFF)==(data1&0xFEFF) && (header2&0x0C)==(data2&0x0C) ){  /* Hit */
            daf.ctrl->read = tmp_cnt;  /* modify data pointer */
            return true;
         }
   
   }else{    /* still remain non-alignment */
       if( (data1 & 0xFF00) == 0xFF00 && (data2 & 0x00E6) == 0x00E2
          && (data2 & 0xF000) != 0xF000 && (data2 & 0x0C00) != 0x0C00 && (data2 & 0x0018) != 0x0008 ){
          data1 = ((data1 >> 8)&0xFF) + ((data2 << 8)&0xFF00);
          data2 = (data2 >> 8)&0xFF;
          
          if( (header1&0xFEFF)==(data1&0xFEFF) && (header2&0x0C)==(data2&0x0C) ){  /* Hit */
             daf.ctrl->read = tmp_cnt;  /* modify data pointer */
             return true;
          }
       }
    }
   return false; /* Next frame is invalid */
}

Media_Status dafPlay( mediaControl *mctrl )
{
   uint16 I, data1, data2, ver;

   daf.ctrl = mctrl;
   daf.ctrl->end_status = MEDIA_NONE;
   daf.ctrl->dsp_rb_base = 0;

   DSP_DynamicDownload( DDID_DAF );   /* DSP code dynamic download */

   data1 = daf.ctrl->rb_base[daf.ctrl->read];   /* Fetch the following two word */
   
   if( daf.ctrl->read+1 < daf.ctrl->rb_size )
      data2 = daf.ctrl->rb_base[daf.ctrl->read+1];
   else
      data2 = daf.ctrl->rb_base[0];

   if( (data1 & 0xFF00) == 0xFF00 && (data2 & 0x00E6) == 0x00E2  /* not word alignment */
      && (data2 & 0xF000) != 0xF000 && (data2 & 0x0C00) != 0x0C00 && (data2 & 0x0018) != 0x0008 ) {
      data1 = ((data1 >> 8)&0xFF) + ((data2 << 8)&0xFF00);
      data2 = (data2 >> 8)&0xFF;
   }

   ver = (data1>>11) & 3;  /* to get MPEG version */
   data1 = (data1>>9) & 3; /* to get Layer # */
   if( ver == 0x01 || data1 != 0x01 )  /* Check MPEG version & Layer III */
      return MEDIA_BAD_FORMAT;
      
   data1 = (data2 >> 2) & 3;
   
   if(data1 == 3)   /* invalid sampling rate */
      return MEDIA_BAD_FORMAT;
   
   if(ver==2||ver==3) /* match lookup table to get sampling rate parameter */
      ver--;
   /* to initiate DSP audio task */      
   AM_AudioPlaybackOn( ASP_TYPE_DAF, ASP_FS_TABLE[ver][data1] ); 

   AFE_SetDigitalGain(L1SP_AUDIO, daf.ctrl->level);
   *DAF_MAIN_CONTROL   = 3;

   for( I = 0; ; I++ ) {
      if( *DAF_MAIN_CONTROL == 1 || daf.ctrl->end_status == MEDIA_END )
         break;
      ASSERT_REBOOT( I < 20 );
      kal_sleep_task( 2 );
   }
   return MEDIA_SUCCESS;
}

void dafStop( void )
{
   uint16 I;

   daf.ctrl->end_status = MEDIA_TERMINATED;

   for( I = 0; ; I++ ) {
      if( *DAF_MAIN_CONTROL == 0 )          /* DSP returns to idle state */
         break;
      if( *DAF_MAIN_CONTROL == 1 ) {
         *DAF_MAIN_CONTROL = 5;             /* give ABORT command to the DSP */
      }
      ASSERT_REBOOT( I < 20 );
      kal_sleep_task( 2 );
   }
   AM_AudioPlaybackOff( true );
}

void dafPause(mediaControl *mctrl)
{
   uint16 I;

   daf.ctrl->end_status = MEDIA_TERMINATED;

   for( I = 0; ; I++ ) {
      if( *DAF_MAIN_CONTROL == 0 )          /* DSP returns to idle state */
         break;
      if( *DAF_MAIN_CONTROL == 1 ) {
         *DAF_MAIN_CONTROL = 5;             /* give ABORT command to the DSP */
      }
      ASSERT_REBOOT( I < 20 );
      kal_sleep_task( 2 );
   }
   AM_AudioPlaybackOff( true );
}

Media_Status dafResume(mediaControl *mctrl)
{
   uint16 I, count, data1, data2, ver;
   int16 tmp_cnt;
   int16 daf_frame_length;

   data1 = 0;
   data2 = 0; /* To avoid compile-warning */
   daf.ctrl = mctrl;
   daf.ctrl->end_status = MEDIA_NONE;
   daf.ctrl->dsp_rb_base = 0;

   DSP_DynamicDownload( DDID_DAF );   /* DSP code dynamic download */

   count = mediaGetDataCount();
   tmp_cnt = daf.ctrl->read;
   for( I = 0; I < count; I++ ) {    /* Search frame header to find out sampling rate */
      data1 = daf.ctrl->rb_base[tmp_cnt];   /* Fetch the following two word */
      
      if( tmp_cnt+1 < daf.ctrl->rb_size )
         data2 = daf.ctrl->rb_base[tmp_cnt+1];
      else
         data2 = daf.ctrl->rb_base[0];
         
      if( (data1 & 0xFF00) == 0xFF00 && (data2 & 0x00E6) == 0x00E2  /* case 1, not alignment */
         && (data2 & 0xF000) != 0xF000 && (data2 & 0x0C00) != 0x0C00 && (data2 & 0x0018) != 0x0008 ) {
         data1 = ((data1 >> 8)&0xFF) + ((data2 << 8)&0xFF00);
         data2 = (data2 >> 8)&0xFF;

         /***************************************************/
         /** check frame length to sync. next frame header **/
         /***************************************************/

         dafChkFrameLen(data1, data2, &daf_frame_length);
         
         /***************************************************/
         /*    Fetch next frame header to check validity   */
         /***************************************************/
         
         if( dafChkNextFrame(daf_frame_length + ONE_EXTRA_SLOT, 1, tmp_cnt, data1, data2) )
            break;     /* Hit */
         if( dafChkNextFrame(daf_frame_length, 1, tmp_cnt, data1, data2) )
            break;     /* Hit */
      }
      else if( ((data1 & 0x1800) != 0x0800) && ((data1 & 0xE6FF) == 0xE2FF)  /* case 2, word alignment */
            && ((data2 & 0x00F0) != 0x00F0)&& ((data2 & 0x000C) != 0x000C)){

         /***************************************************/
         /** check frame length to sync. next frame header **/
         /***************************************************/

         dafChkFrameLen(data1, data2, &daf_frame_length);
         
         /***************************************************/
         /*    Fetch next frame header to check validity   */
         /***************************************************/
         
         if( dafChkNextFrame(daf_frame_length + ONE_EXTRA_SLOT, 0, tmp_cnt, data1, data2) )
            break;     /* Hit */
         if( dafChkNextFrame(daf_frame_length, 0, tmp_cnt, data1, data2) )
            break;     /* Hit */
      }
      tmp_cnt++;
      if( tmp_cnt == daf.ctrl->rb_size )
         tmp_cnt = 0;
   }
   
   if( I >= count )
      return MEDIA_BAD_FORMAT;
   
   ver = (data1>>11) & 3;
   data1 = (data1>>9) & 3;
   ASSERT(ver!=0x01 && data1 == 0x01);
   
   data1 = (data2 >> 2) & 3;
   ASSERT(data1<3);

   if(ver==2||ver==3) /* to match lookup table */
      ver--;
            
   AM_AudioPlaybackOn( ASP_TYPE_DAF, ASP_FS_TABLE[ver][data1] );

   AFE_SetDigitalGain(L1SP_AUDIO, 100);
   *DAF_MAIN_CONTROL   = 3;

   for( I = 0; ; I++ ) {
      if( *DAF_MAIN_CONTROL == 1 || daf.ctrl->end_status == MEDIA_END )
         break;
      ASSERT_REBOOT( I < 20 );
      kal_sleep_task( 2 );
   }
   return MEDIA_SUCCESS;   
}

void dafUpdateLevel( void )
{
   AFE_SetDigitalGain(L1SP_AUDIO, daf.ctrl->level);
}

/* ------------------------------------------------------------------------------ */

#endif

