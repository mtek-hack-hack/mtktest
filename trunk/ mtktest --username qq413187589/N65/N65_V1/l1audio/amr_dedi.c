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
 * amr_dedi.c
 *
 * Project:
 * --------
 *   MTK6218B
 *
 * Description:
 * ------------
 *   AMR515 encoder for using in dedicated mode
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
#include "dcmgr.h"

#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#if defined( DEDI_AMR_REC )

#include "cod_amr.h"

#define  AMR515_STATE_READY      1
#define  AMR515_STATE_RECORDING  2
#define  AMR515_STATE_PAUSED     3

#define  FRAME_BUF_SIZE          160
#define  FRAME_BUF_NO            4
#define  FRAME_BUF_MASK          (FRAME_BUF_NO-1)

static struct{
   mediaControl   *ctrl;
   uint16         aud_id;
   uint16         state;
   uint8          tmp_r;
   uint8          tmp_w;
   uint16         *tmp_buf[FRAME_BUF_NO];
   bool           odd_flag;
   uint8          odd_data;
} amr515;

#if defined(MT6205B) || defined(MT6217) || defined(MT6219) || defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228)
#define PAGE_NUM 0
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PAGE_NUM 2
#elif defined(MT6223) || defined(MT6223P)
#define PAGE_NUM 1
#else
#error The new chip should define DM page number
#endif

static void amr515ReadFromDSP( int16 *buf )
{
   int32 first_data_block_len, second_data_block_len;
   int32 I, tmp;

   if(!amr515.ctrl->CSD_Mode){
      ASSERT( *DP_TCH_UL_LEN == FRAME_BUF_SIZE );   /* frame size */
      ASSERT( *DP_TCH_DL_LEN == FRAME_BUF_SIZE );   /* frame size */
      
      first_data_block_len = (int16)*DP_TCH_UL_BUF_LEN - ((int16)*DP_TCH_UL_PTR - (int16)*DP_TCH_UL_BUF_ADDR0);
      if( first_data_block_len < FRAME_BUF_SIZE )
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }
      
      tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_PTR);  /* Read uplink data */
      for ( I = first_data_block_len; I > 0; I-- )
         *buf++ = (int16)(*IDMA_SHORT_ADDR);
      if( (I = second_data_block_len) > 0 ){
         tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_BUF_ADDR0);
         for ( ; I > 0 ;I-- )
            *buf++ = (int16)(*IDMA_SHORT_ADDR);
      }
      
      /* handle downlink data */
      buf -= FRAME_BUF_SIZE;
      first_data_block_len = (int16)*DP_TCH_DL_BUF_LEN - ((int16)*DP_TCH_DL_PTR - (int16)*DP_TCH_DL_BUF_ADDR0);
      if( first_data_block_len < FRAME_BUF_SIZE )
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }
      
      tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_PTR);  /* Read downlink data */
      for( I = first_data_block_len; I > 0; I-- ){
         tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
         *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp<-32768)?-32768:tmp);
      }
      if( (I = second_data_block_len) > 0 ){
         tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_BUF_ADDR0);
         for ( ; I > 0; I-- ){
            tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
            *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp<-32768)?-32768:tmp);
         }
      }
   }else{ /* amr recording in idle mode */
      int32 count;
      uint16 dummy;
      {
         dummy = *DSP_DM_ADDR(PAGE_NUM, *DSP_PCM_REC_ADDR);
         count = (int32)(*DSP_PCM_REC_LEN);
      }

      for( I = count; I > 0; I-- ) {
         *buf++ = (int16)(*IDMA_SHORT_ADDR);
      }

   }

}

static void amr515Encode( void *data )     /* This function works in L1Audio Task */
{
   int32 packed_size;
   uint16 *ptr;

   (void)data;
   while( (uint8)(amr515.tmp_w - amr515.tmp_r) > 0 ) {
      if( mediaGetFreeSpace() > 30 ) {
         int32 I;
         uint16 *mbuf_begin = amr515.ctrl->rb_base;
         uint16 *mbuf_end = mbuf_begin + amr515.ctrl->rb_size;
         uint16 *mbuf_ptr = mbuf_begin + amr515.ctrl->write;
         if( (uint8)(amr515.tmp_w - amr515.tmp_r) >= 3 ) {   /* over loading, drop some frames */
            if( amr515.odd_flag ) {
               *mbuf_ptr = 0x7C00 | amr515.odd_data;
               amr515.odd_flag = false;
               packed_size = 1;
            }
            else {
               amr515.odd_data = 0x7C;
               amr515.odd_flag = true;
               packed_size = 0;
            }
         }
         else {
            ptr = AMR515_Encode( (int32*)amr515.tmp_buf[amr515.tmp_r&FRAME_BUF_MASK], &packed_size );
            if( amr515.odd_flag ) {
               for( I = packed_size; I > 0; I-- ) {
                  *mbuf_ptr++ = (*ptr<<8) | amr515.odd_data;
                  if( mbuf_ptr == mbuf_end )
                     mbuf_ptr = mbuf_begin;
                  amr515.odd_data = (uint8)(*ptr >> 8);
                  ptr++;
               }
            }
            else {
               for( I = packed_size; I > 0; I-- ) {
                  *mbuf_ptr++ = *ptr++;
                  if( mbuf_ptr == mbuf_end )
                     mbuf_ptr = mbuf_begin;
               }
            }
         }
         amr515.ctrl->write += packed_size;
         if( amr515.ctrl->write >= amr515.ctrl->rb_size )
            amr515.ctrl->write -= amr515.ctrl->rb_size;
      }
      amr515.tmp_r++;
      kal_sleep_task(1);
   }
}

void amr515RecordHisr( void )
{
   if (amr515.state != AMR515_STATE_RECORDING)
      return;

   if( amr515.ctrl->end_status == MEDIA_TERMINATED)
      return;

   if(amr515.ctrl->CSD_Mode){
      if( *DSP_PCM_REC_CTRL == 0 ) {   /* DSP returns to idle state */
         return;
      }
   }

   if( (uint8)(amr515.tmp_w - amr515.tmp_r) < FRAME_BUF_NO ) {    /* Insure no overflow */
      amr515ReadFromDSP( (int16 *)amr515.tmp_buf[amr515.tmp_w&FRAME_BUF_MASK] );
      amr515.tmp_w++;
      L1Audio_SetEvent( amr515.aud_id, (void *)0 );      /* Activate the encoder runing in l1audio task */
   }
}

void amr515Record( mediaControl *ctrl )
{
   int32 I;

   amr515.ctrl = ctrl;
   ASSERT( AM_IsSpeechOn() || amr515.ctrl->CSD_Mode);
   ASSERT( ctrl->rb_size > FRAME_BUF_SIZE * FRAME_BUF_NO * 2 );
   ctrl->rb_size -= FRAME_BUF_SIZE * FRAME_BUF_NO; /* temp buffer */
   if( (uint32)&ctrl->rb_base[ctrl->rb_size] & 3 )
      ctrl->rb_size--;                             /* insure every tmp_buf[I] is aligned to 4 bytes */
   for( I = 0; I < FRAME_BUF_NO; I++ )
      amr515.tmp_buf[I] = &ctrl->rb_base[ctrl->rb_size + FRAME_BUF_SIZE*I];
   ASSERT( ((uint32)amr515.tmp_buf[0] & 3) == 0 );
   amr515.tmp_r = 0;
   amr515.tmp_w = 0;
   amr515.odd_flag = false;

   AMR515_Reset();
   ctrl->end_status = MEDIA_NONE;

   if(amr515.ctrl->CSD_Mode){ /* WAV recording in idle mode */
      {
         *DSP_PCM_REC_CTRL  = 0x200;
         AM_PCM8K_RecordOn();
         for( I = 0; ; I++ ) {
            if( *DSP_PCM_REC_CTRL == 0x400 )
               break;
            ASSERT_REBOOT( I < 20 );
            kal_sleep_task( 2 );
         }
      }      
   }else{
      AM_PCM8K_RecordOn();
   }

   amr515.state = AMR515_STATE_RECORDING;
}

static void amr515BufferFlush(void)
{
   uint16 *mbuf_begin = amr515.ctrl->rb_base;
   uint16 *mbuf_ptr = mbuf_begin + amr515.ctrl->write;

   if( amr515.odd_flag ) {
      *mbuf_ptr = 0x7C00 | amr515.odd_data;
      amr515.odd_flag = false;
      amr515.ctrl->write += 1;
      if( amr515.ctrl->write >= amr515.ctrl->rb_size )
         amr515.ctrl->write -= amr515.ctrl->rb_size;
   }
}

void amr515Stop( void )
{
   uint16 I, ctl;

   switch(amr515.state) {
      case AMR515_STATE_RECORDING:
         amr515.ctrl->end_status = MEDIA_TERMINATED;
         for( I = 0; ; I++ ) {
            ctl = *DSP_PCM_REC_CTRL;
            if( ctl == 0 )                /* DSP returns to idle state */
               break;
            if( ctl == 0x400 )
               *DSP_PCM_REC_CTRL = 0x800;  /* give ABORT command to the DSP */
            ASSERT_REBOOT( I < 20 );
            kal_sleep_task( 2 );
         }
         AM_PCM8K_RecordOff( true );
         break;
      case AMR515_STATE_PAUSED:
         break;
      default:
         ASSERT(KAL_FALSE);
   }
   AMR515_End();
   amr515.state = AMR515_STATE_READY;
   amr515BufferFlush();
}

void amr515Pause(mediaControl *mctrl)
{
   uint16 I, ctl;

   ASSERT( amr515.state = AMR515_STATE_RECORDING );

   amr515.ctrl->end_status = MEDIA_TERMINATED;

   for( I = 0; ; I++ ) {
      ctl = *DSP_PCM_REC_CTRL;
      if( ctl == 0 )                /* DSP returns to idle state */
         break;
      if( ctl == 0x400 )
         *DSP_PCM_REC_CTRL = 0x800;  /* give ABORT command to the DSP */
      ASSERT_REBOOT( I < 20 );
      kal_sleep_task( 2 );
   }
   AM_PCM8K_RecordOff( true );
   amr515.state = AMR515_STATE_PAUSED;
}

void amr515Resume(mediaControl *mctrl)
{
   uint16 I;
   ASSERT( AM_IsSpeechOn() || amr515.ctrl->CSD_Mode );
   mctrl->end_status = MEDIA_NONE;

   if(amr515.ctrl->CSD_Mode){ /* WAV recording in idle mode */
      {
         *DSP_PCM_REC_CTRL  = 0x200;
         AM_PCM8K_RecordOn();
         for( I = 0; ; I++ ) {
            if( *DSP_PCM_REC_CTRL == 0x400 )
               break;
            ASSERT_REBOOT( I < 20 );
            kal_sleep_task( 2 );
         }
      }
   }else{
      AM_PCM8K_RecordOn();
   }

   amr515.state = AMR515_STATE_RECORDING;
}

void amr515Init( uint16 aud_id )
{
   amr515.aud_id = aud_id;
   L1Audio_SetEventHandler( amr515.aud_id, amr515Encode );
   amr515.state = AMR515_STATE_READY;
}

#endif   /* DEDI_AMR_REC */
#endif   /* IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION */


