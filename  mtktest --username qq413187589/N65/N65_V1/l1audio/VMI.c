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
 *   VMI.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Voice mixer interface and driver, for multi-channel voice i/o, 
 *     with embedded tone synthesizing and mixing function
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
*                     C O M P I L E R   F L A G S
******************************************************************************
*/
#if defined(__MTK_TARGET__)
 /* need semaphore protection if VMI interface function run under different tasks */
#define VMI_NEED_SEMA                   1
#endif
#define SHARE_BUFFER_SPK_TONE           0

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/
#include "VMI.h"
#if !defined(SIM_ON_VC)
#include "kal_trace.h"
#else
#include <stdio.h>
#endif
#include "l1sp_trc.h"

#if VMI_SUPPORT
/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/
typedef struct VoiceToneStruct VMI_TONE;
struct VoiceToneStruct {
   VMI_TONE_PARA    para;
   TONESYN          tonesyn;
   uint32           elapsed_frames;
};

/*****************************************************************************
*                        P U B L I C   D A T A
******************************************************************************
*/
#if defined(SIM_ON_VC)
extern FILE *trace_info;
#endif

/*****************************************************************************
*                       P R I V A T E   D A T A
******************************************************************************
*/
static struct {
   uint32           on:1, 
                    put_all_to_se:1, 
                    unused: 30;
#if VMI_NEED_SEMA
   kal_semid        sema;
#endif

   int16            *mic_buffer;
   VMI_HANDLE       *uplink_head;
   
   int16            *spk_buffer;
   VMI_HANDLE       *downlink_head;

   VMI_HANDLE       *digital_mic;

#if !SHARE_BUFFER_SPK_TONE
   int16            *tone_buffer;
#endif
   VMI_TONE         tone;
   void (*postHandler)(void *);
} VMI;

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/

#if !defined(SIM_ON_VC)
#define VMI_ALLOC(_sz)                  get_ctrl_buffer(_sz)
#define VMI_FREE(_ptr)                  free_ctrl_buffer(_ptr)
#else
#define VMI_ALLOC(_sz)                  malloc(_sz)
#define VMI_FREE(_ptr)                  free(_ptr)
#endif

#if SHARE_BUFFER_SPK_TONE
#define VMI_TONE_BUFFER_P               (VMI.spk_buffer)
#else
#define VMI_TONE_BUFFER_P               (VMI.tone_buffer)
#endif

/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/
#if defined(SIM_ON_VC)
extern void ASSERT(bool cond);
#endif
extern void SetSpeechEnhancement( bool ec );

/*****************************************************************************
*                          F U N C T I O N S
******************************************************************************
*/

static bool vmi_check_all( void )
{
   VMI_HANDLE *handle;

   if( (NULL==VMI.mic_buffer) || (NULL==VMI.spk_buffer) || (NULL==VMI_TONE_BUFFER_P) )
      return false;

   // Check downlink channel
   handle = VMI.downlink_head;
   while( handle!=NULL )
   {
      if( (0==handle->on) || (VMI_DIR_DL!=handle->dir) )
         return false;
      handle = handle->next;
   }

   // Check uplink channel
   handle = VMI.uplink_head;
   while( handle!=NULL)
   {
      if( (0==handle->on) || (VMI_DIR_UL!=handle->dir) )
         return false;
      handle = handle->next;
   }
   
   return true;
}

__inline bool vmi_is_on( void )
{
   return( VMI.on==1 );
}

__inline bool vmi_is_tone_exist( void )
{
   VMI_TONE_PARA *tone_para = &(VMI.tone.para);
   return( (1==tone_para->uplink_en) || (1==tone_para->downlink_en) );
}

__inline bool vmi_is_active( void )
{
   return( (VMI.uplink_head!=NULL) || 
      (VMI.downlink_head!=NULL) || 
      (true==vmi_is_tone_exist()) );
}

__inline void vmi_set_tone_control_word( uint32 tone_control_word )
{
   *((uint32 *)&(VMI.tone.para)) = tone_control_word;
}

static VMI_HANDLE *vmi_find_prev_handle( VMI_HANDLE *head, VMI_HANDLE *hdl )
{
   VMI_HANDLE *prev = NULL;
   while( head!=hdl )
   {
      if( NULL==head )
         return prev;
      prev = head;
      head = head->next;
   }
   return prev;
}


static void vmi_process_one_uplink( VMI_HANDLE *ul, bool mix )
{
   PCMRB *rb = &ul->rb;
   int32 write_t = rb->write; // backup the read pointer

   if( 1==ul->mute_mic )
      PCMRB_Write( rb, (int16 *)NULL, PCM2WAY_FRAME_SIZE );
   else
      PCMRB_Write( rb, VMI.mic_buffer, PCM2WAY_FRAME_SIZE );

   if( (true==mix) && // allow mix
       (1==ul->mix) &&
       (NULL!=VMI.downlink_head) )
   {
      VMI_HANDLE *dl = VMI.downlink_head;

      rb->write = write_t; // restore the read pointer
      do
      {
         if( (1==dl->mix) && (dl->session_id!=ul->session_id) )
         {
            if( PCMRB_GetDataCount( &dl->rb )>=PCM2WAY_FRAME_SIZE )
            {
               PCMRB_Mix( rb, &dl->rb, PCM2WAY_FRAME_SIZE );
            }
         }
         dl = dl->next;
      } while( dl!=NULL );
      PCMRB_ShiftWritePointer( rb, PCM2WAY_FRAME_SIZE );
   }
}

static void vmi_process_one_downlink( VMI_HANDLE *dl, bool skip )
{
   int32 size = PCM2WAY_FRAME_SIZE;
   PCMRB *rb = &dl->rb;

   if( skip )
      PCMRB_ShiftReadPointer( rb, size );
   else
   { // mix downlink channel to spk_buffer
      int16 *read_ptr, *write_ptr = VMI.spk_buffer;
      int32 read_cnt;

      PCMRB_GetReadBlock( rb, &read_ptr, &read_cnt );
      if( read_cnt>size ) read_cnt = size;
      pcm_mix_n( write_ptr, read_ptr, read_cnt );
      PCMRB_ShiftReadPointer( rb, read_cnt );
      size -= read_cnt;

      if( size>0 )
      {
         write_ptr += read_cnt;
         PCMRB_GetReadBlock( rb, &read_ptr, &read_cnt );
         if( read_cnt>size ) read_cnt = size;
         pcm_mix_n( write_ptr, read_ptr, read_cnt );
         PCMRB_ShiftReadPointer( rb, read_cnt );
      }
   }
}

static bool vmi_process_tone( void )
{
   int i;
   VMI_TONE *tone = &VMI.tone;
   TONESYN *tonesyn = &tone->tonesyn;
   int16 *ptr = VMI_TONE_BUFFER_P;

   if( vmi_is_tone_exist() )
   {
      if( tone->elapsed_frames>0 )
      {
         if( tone->elapsed_frames==1 )
         {
            vmi_set_tone_control_word( 0 );
            return true;
         }
         tone->elapsed_frames --;
      }
      for( i=0; i<PCM2WAY_FRAME_SIZE; i+=4 )
      {
         ptr[i+0] = ToneSyn_GetSample( tonesyn );
         ptr[i+1] = ToneSyn_GetSample( tonesyn );
         ptr[i+2] = ToneSyn_GetSample( tonesyn );
         ptr[i+3] = ToneSyn_GetSample( tonesyn );
      }
   }
#if SHARE_BUFFER_SPK_TONE
   else
   {
      memset( VMI_TONE_BUFFER_P, 0, PCM2WAY_FRAME_SIZE*sizeof(int16) );
   }
#endif
   return false;
}

static void vmi_get_from_mic( void )
{
   if( VMI.digital_mic != NULL )
   {
      int16 *read_ptr;
      int32 read_count;

      PCMRB_GetReadBlock( &VMI.digital_mic->rb, &read_ptr, &read_count );
      if( read_count >= PCM2WAY_FRAME_SIZE )
      {
         memcpy( VMI.mic_buffer, read_ptr, PCM2WAY_FRAME_SIZE*sizeof(int16) );
         PCMRB_ShiftReadPointer(&VMI.digital_mic->rb, PCM2WAY_FRAME_SIZE);
      }
      else
      {
         memset( VMI.mic_buffer, 0, PCM2WAY_FRAME_SIZE*sizeof(int16) );
         VMI.digital_mic->skip_frames ++;
      }
      VMI.digital_mic->processed_frames ++;

      if( VMI.digital_mic->callback!=NULL )
         VMI.digital_mic->callback( VMI.digital_mic->host_data, VMI_EVENT_DATA_NOTIFY );
   }
   else
      PCM4WAY_GetFromMic( (uint16 *)VMI.mic_buffer );   //20070612
   if( true==VMI.tone.para.uplink_en )
   {
      if( true==VMI.tone.para.uplink_mix )
         pcm_mix_n( VMI.mic_buffer, VMI_TONE_BUFFER_P, PCM2WAY_FRAME_SIZE );
      else
         memcpy( VMI.mic_buffer, VMI_TONE_BUFFER_P, PCM2WAY_FRAME_SIZE*sizeof(int16) );
   }
}

static void vmi_put_to_spk( void )
{
#if !SHARE_BUFFER_SPK_TONE
   if( true==VMI.tone.para.downlink_en )
   {
      if( true==VMI.tone.para.downlink_mix )
         pcm_mix_n( VMI.spk_buffer, VMI_TONE_BUFFER_P, PCM2WAY_FRAME_SIZE );
      else
         memcpy( VMI.spk_buffer, VMI_TONE_BUFFER_P, PCM2WAY_FRAME_SIZE*sizeof(int16) );
   }
#endif
   PCM4WAY_PutToSpk( (uint16 *)VMI.spk_buffer );   //20070612
}

/*
 * Description
 * ---------
 *   The function is the interrupt handler.
 *   It will handle all of the uplink and downlink channels
 *
 * Syntax
 * ---------
 *   void vmi_hisr( void )
 *
 * Return Value
 * ---------
 *   none
 */
#if VMI_IN_TASK
static void vmi_hisr( void )
{
   VMI_HANDLE *hdl;
   
   if( true!=vmi_is_on() )
      return;

   if( VMI.uplink_head!=NULL )
   {
      hdl = VMI.uplink_head;
      while( hdl->callback==NULL )
      {
         if( hdl->next==NULL )
            break;
         hdl = hdl->next;
      }
      if( hdl->callback!=NULL )
      {
         hdl->callback( hdl->host_data, VMI_EVENT_DATA_NOTIFY );
         return;
      }
   }
   
   if( VMI.downlink_head!=NULL )
   {
      hdl = VMI.downlink_head;
      while( hdl->callback==NULL )
      {
         if( hdl->next==NULL )
            break;
         hdl = hdl->next;
      }
      if( hdl->callback!=NULL )
      {
         hdl->callback( hdl->host_data, VMI_EVENT_DATA_REQUEST );
         return;
      }
   }

//   ASSERT(0);
}

void vmi_process( void )
 #else
static void vmi_hisr( void )
#endif
{
   bool uplink_mix_other_source, skip_downlink;
   VMI_TONE_PARA *tone_para = &VMI.tone.para;
   
   if( true!=vmi_is_on() )
      return;
   ASSERT( true==vmi_check_all() );
   ASSERT( true==vmi_is_active() );

   /* setup tone buffer */
   if( true==vmi_process_tone() )
   {
#if !VMI_IN_TASK
      if( NULL!=tone_para->callback )
         tone_para->callback( tone_para->host_data, VMI_EVENT_TONE_OFF );
#endif
   }

   uplink_mix_other_source = ( (true==tone_para->uplink_en) && (false==tone_para->uplink_mix) )? false: true;
   skip_downlink = ( (true==tone_para->downlink_en) && (false==tone_para->downlink_mix) )? true: false;

   /* serve uplink channel first */
   if( VMI.uplink_head!=NULL )
   {
      VMI_HANDLE *ul = VMI.uplink_head;

      vmi_get_from_mic();

      do
      {
          if( (0!=ul->on) && (0==ul->mute) )
         {
            if( PCMRB_GetFreeSpace( &ul->rb )>=PCM2WAY_FRAME_SIZE )
            { // available for writing
               vmi_process_one_uplink( ul, uplink_mix_other_source );
            }
            else
            { // unavailable for writing, the data in the slot will be skipped
               ul->skip_frames ++;
            }
            ul->processed_frames ++;
#if !VMI_IN_TASK
            if( ul->callback!=NULL )
               ul->callback( ul->host_data, VMI_EVENT_DATA_NOTIFY );
#endif
         }
         ul = ul->next;
      } while( ul!=NULL );
   }
 
   /* serve downlink channel later */
#if !SHARE_BUFFER_SPK_TONE
   memset( VMI.spk_buffer, 0, PCM2WAY_FRAME_SIZE*sizeof(int16) );
#endif
   if( VMI.downlink_head!=NULL )
   {
      VMI_HANDLE *dl= VMI.downlink_head;
      
      do
      { 
         if( (0!=dl->on) && (0==dl->mute) )
         {
            if( PCMRB_GetDataCount( &dl->rb )>=PCM2WAY_FRAME_SIZE )
            { // available for reading
               vmi_process_one_downlink( dl, skip_downlink );
            }
            else
            { // unavailable for reading, the data in the slot will be delayed
               dl->skip_frames ++;
            }
            dl->processed_frames ++;
#if !VMI_IN_TASK
            if( dl->callback!=NULL )
               dl->callback( dl->host_data, VMI_EVENT_DATA_REQUEST );
#endif
         }
         dl = dl->next;
      } while( dl!=NULL );
   }
   if (VMI.put_all_to_se==1)
   { 	
   	 pcm_mix_n( VMI.mic_buffer, VMI.spk_buffer, PCM2WAY_FRAME_SIZE );
	    PCM4WAY_PutToSE( (uint16 *)VMI.mic_buffer );	    
   }
   if( VMI.postHandler != NULL )
      VMI.postHandler( (void *)VMI.spk_buffer );
   vmi_put_to_spk();

   return;
}

static void vmi_turn_on( void )
{
   if( (false==vmi_is_on()) && (true==vmi_is_active())  )
   {
#if SHARE_BUFFER_SPK_TONE
      uint8 *buffer = (uint8 *)VMI_ALLOC(2*PCM2WAY_FRAME_SIZE*sizeof(int16));
      ASSERT( buffer!=NULL );
      memset( buffer, 0, 2*PCM2WAY_FRAME_SIZE*sizeof(int16) );
      VMI.mic_buffer = (int16 *)buffer;
      buffer += PCM2WAY_FRAME_SIZE*sizeof(int16);
      VMI.spk_buffer = (int16 *)buffer;
#else
      uint8 *buffer = (uint8 *)VMI_ALLOC(3*PCM2WAY_FRAME_SIZE*sizeof(int16));
      ASSERT( buffer!=NULL );
      memset( buffer, 0, 3*PCM2WAY_FRAME_SIZE*sizeof(int16) );
      VMI.mic_buffer = (int16 *)buffer;
      buffer += PCM2WAY_FRAME_SIZE*sizeof(int16);
      VMI.spk_buffer = (int16 *)buffer;
      buffer += PCM2WAY_FRAME_SIZE*sizeof(int16);
      VMI.tone_buffer = (int16 *)buffer;
#endif
      VMI.on = 1;
      PCM4WAY_Start( vmi_hisr, 2 );   
      SetSpeechEnhancement( true );
   }
}

static void vmi_turn_off( void )
{
   if( (true==vmi_is_on()) && (false==vmi_is_active()) )
   {
      VMI.on = 0;
      SetSpeechEnhancement( false );
      PCM4WAY_Stop(2);  
      VMI_FREE( VMI.mic_buffer );
      VMI.mic_buffer = NULL;
      VMI.spk_buffer = NULL;
#if !SHARE_BUFFER_SPK_TONE
      VMI.tone_buffer = NULL;
#endif
   }
}

/*
 * Description
 * ---------
 *   The function initializes the context.
 *   Use this in system startup.
 *
 * Syntax
 * ---------
 *   void VMI_Init( void )
 *
 * Return Value
 * ---------
 *   none
 */
void VMI_Init( void )
{
   memset( &VMI, 0, sizeof(VMI) );
#if VMI_NEED_SEMA
   VMI.sema = kal_create_sem( "VMI", 1 );
#endif
}

/*
 * Description
 * ---------
 *   The function get one available handle and attaches its ring buffer
 *
 * Syntax
 * ---------
 *   VMI_HANDLE *VMI_GetHandle( uint32 dir, uint32 *buffer, int32 buffer_size )
 *
 * where
 *   dir               uplink or downlink
 *   buffer        Address of the memory allocated for the ring buffer used by the new handle
 *   buffer_size   Size of the memory allocated for the ring buffer used by the new handle
 *
 * Return Value
 * ---------
 *   the new handle
 */
VMI_HANDLE *VMI_GetHandle( uint32 dir, uint8 *buffer, int32 buffer_size )
{
   VMI_HANDLE *handle;

   ASSERT( (dir==VMI_DIR_UL) || (dir==VMI_DIR_DL) );
   ASSERT( buffer!=NULL );
   ASSERT( buffer_size>PCM2WAY_FRAME_SIZE*sizeof(int16) );

   handle = (VMI_HANDLE *)VMI_ALLOC( sizeof(VMI_HANDLE) );
   if( NULL==handle )
      return NULL;

   memset( handle, 0, sizeof(VMI_HANDLE) );
   handle->dir = dir;
   if( false==PCMRB_Init( &handle->rb, (int16 *)buffer, buffer_size/sizeof(int16) ) )
   {
      VMI_FREE( handle );
      return NULL;
   }

   return handle;
}

/*
 * Description
 * ---------
 *   The function stop and then free the handle
 *
 * Syntax
 * ---------
 *   VMI_STATUS VMI_FreeHandle( VMI_HANDLE *handle )
 *
 * where
 *   handle         the handle
 *
 * Return Value
 * ---------
 *   VMI_STATUS_SUCCESS
 */
VMI_STATUS VMI_FreeHandle( VMI_HANDLE *handle )
{
   VMI_HANDLE **my_head;

   ASSERT( handle!=NULL );
   ASSERT( handle->on == 1 );
#if VMI_NEED_SEMA
   kal_take_sem( VMI.sema, KAL_INFINITE_WAIT );
#endif

   // Stop it first: removed from queue
   if( handle == VMI.digital_mic )
   {
      VMI.digital_mic = NULL;
   }
   else
   {
      my_head = ( VMI_DIR_UL==handle->dir )? (&VMI.uplink_head): (&VMI.downlink_head);
   
      ASSERT( NULL!=*my_head );
      if( handle==*my_head )
         *my_head = handle->next;
      else
      {
         VMI_HANDLE *my_prev = vmi_find_prev_handle( *my_head, handle );
         ASSERT( handle==my_prev->next );
         my_prev->next = handle->next;
      }
   }
   handle->on = 0;
   vmi_turn_off();
   VMI_FREE( handle );
   
#if VMI_NEED_SEMA
   kal_give_sem( VMI.sema );
#endif
   return VMI_STATUS_SUCCESS;
}

/*
 * Description
 * ---------
 *   The function starts the handle running
 *
 * Syntax
 * ---------
 *   VMI_STATUS VMI_Start( VMI_HANDLE *handle )
 *
 * where
 *   handle
 *
 * Return Value
 * ---------
 *   VMI_STATUS_SUCCESS
 */
VMI_STATUS VMI_Start( VMI_HANDLE *handle )
{
   VMI_HANDLE **my_head;
    
   ASSERT( handle != NULL );
   ASSERT( handle->on == 0 );
#if VMI_NEED_SEMA
   kal_take_sem( VMI.sema, KAL_INFINITE_WAIT );
#endif

   if( ( handle->mic==1 ) && ( VMI_DIR_DL==handle->dir ) )
   {
      if( VMI.digital_mic != NULL )
      {
#if VMI_NEED_SEMA
         kal_give_sem( VMI.sema );
#endif
         return VMI_STATUS_FAIL;
      }
      handle->on = 1;
      VMI.digital_mic = handle;
   }
   else
   {
      my_head = ( VMI_DIR_UL==handle->dir )? (&VMI.uplink_head): (&VMI.downlink_head);
      handle->on = 1;
      handle->next = *my_head;
      *my_head = handle;
   }

   vmi_turn_on();

#if VMI_NEED_SEMA
   kal_give_sem( VMI.sema );
#endif
   return VMI_STATUS_SUCCESS;
}

/*
 * Description
 * ---------
 *   The function sets the mute function to the handle
 *
 * Syntax
 * ---------
 *   VMI_STATUS VMI_Mute( VMI_HANDLE *handle, bool mute )
 *
 * where
 *   handle   The handle
 *   mute        the enable flag of muting
 *
 * Return Value
 * ---------
 *   VMI_STATUS_SUCCESS
 */
VMI_STATUS VMI_Mute( VMI_HANDLE *handle, bool mute )
{
   ASSERT( handle!=NULL );
#if VMI_NEED_SEMA
   kal_take_sem( VMI.sema, KAL_INFINITE_WAIT );
#endif

   handle->mute = ( true==mute )? 1: 0;

#if VMI_NEED_SEMA
   kal_give_sem( VMI.sema );
#endif
   return VMI_STATUS_SUCCESS;
}

/*
 * Description
 * ---------
 *   The function turns on the tone function
 *
 * Syntax
 * ---------
 *   VMI_STATUS VMI_ToneOn( VMI_TONE_PARA *para )
 *
 * where
 *   para         the tone playing parameter
 *
 * Return Value
 * ---------
 *   VMI_STATUS_SUCCESS
 *   VMI_STATUS_FAIL
 */
VMI_STATUS VMI_ToneOn( VMI_TONE_PARA *para )
{
   VMI_TONE *tone;

   ASSERT( (1==para->uplink_en) || (1==para->downlink_en) );
 
#if VMI_NEED_SEMA
      kal_take_sem( VMI.sema, KAL_INFINITE_WAIT );
#endif
   if( (true==vmi_is_tone_exist()) || 
       ( (para->duration<PCM2WAY_FRAME_TIME) && (para->duration>0) ) )
   {
#if VMI_NEED_SEMA
      kal_give_sem( VMI.sema );
#endif
      return VMI_STATUS_FAIL; // tone channel is allocated before
   }

   // reset and activate the tone channel
   tone = &VMI.tone;
   ToneSyn_Init( &tone->tonesyn, para->freq1, para->freq2, para->gain );
   tone->elapsed_frames = ( 0==para->duration )? 0: 
      ((para->duration+PCM2WAY_FRAME_TIME+(PCM2WAY_FRAME_TIME>>1))/PCM2WAY_FRAME_TIME);
   memcpy( ((uint8 *)&(tone->para))+4, ((uint8 *)para)+4, sizeof(VMI_TONE_PARA)-4 );
   vmi_set_tone_control_word( *(uint32 *)para );

   // turn on PCM2WAY if necessary
   vmi_turn_on();
   
#if VMI_NEED_SEMA
   kal_give_sem( VMI.sema );
#endif
   return VMI_STATUS_SUCCESS;
}

/*
 * Description
 * ---------
 *   The function stops the tone playing
 *
 * Syntax
 * ---------
 *   VMI_STATUS VMI_ToneOff( void )
 *
 * where
 *
 * Return Value
 * ---------
 *   VMI_STATUS_SUCCESS
 *   VMI_STATUS_FAIL
 */
VMI_STATUS VMI_ToneOff( void )
{
#if VMI_NEED_SEMA
   kal_take_sem( VMI.sema, KAL_INFINITE_WAIT );
#endif

   if( false==vmi_is_tone_exist() )
   {
#if VMI_NEED_SEMA
      kal_give_sem( VMI.sema );
#endif
      return VMI_STATUS_FAIL; // tone channel is closed before
   }

   // deactivate the tone channel
   vmi_set_tone_control_word( 0 );

   // turn off PCM2WAY if necessary
   vmi_turn_off();

#if VMI_NEED_SEMA
   kal_give_sem( VMI.sema );
#endif
   return VMI_STATUS_SUCCESS;
}

VMI_STATUS VMI_PutAllToSE(bool enable)
{
   VMI.put_all_to_se = (enable == true)? 1: 0;
   return VMI_STATUS_SUCCESS;   	
}

void VMI_HookPostHandler( void (*PostHandler)(void *) )
{
   VMI.postHandler = PostHandler;
}

void VMI_UnhookPostHandler( void )
{
   VMI.postHandler = NULL;
}

#if defined(VORTP_UNIT_TEST)
void VMI_WatchInternal()
{
   VMI_HANDLE *this;
   int i;
   
   kal_prompt_trace(MOD_L1SP, "VMI.on=%d\n", VMI.on);
   if(VMI.on == 0)
      return;

   this = VMI.uplink_head;
   i = 0;
   while(this != NULL)
   {
      kal_prompt_trace(MOD_L1SP, "UL%d: dir=%d, on=%d, mute=%d, mix=%d, mute_mic=%d, mic=%d\n", 
         i, this->dir, this->on, this->mute, this->mix, this->mute_mic, this->mic);
      kal_prompt_trace(MOD_L1SP, "UL%d: sid=0x%x, processed_frames=%d, skip_frames=%d\n", 
         i, this->session_id, this->processed_frames, this->skip_frames);

      this = this->next;
      i ++;
   }
   
   this = VMI.downlink_head;
   i = 0;
   while(this != NULL)
   {
      kal_prompt_trace(MOD_L1SP, "DL%d: dir=%d, on=%d, mute=%d, mix=%d, mute_mic=%d, mic=%d\n", 
         i, this->dir, this->on, this->mute, this->mix, this->mute_mic, this->mic);
      kal_prompt_trace(MOD_L1SP, "DL%d: sid=0x%x, processed_frames=%d, skip_frames=%d\n", 
         i, this->session_id, this->processed_frames, this->skip_frames);

      this = this->next;
      i ++;
   }

   this = VMI.digital_mic;
   if(this != NULL)
   {
      kal_prompt_trace(MOD_L1SP, "MIC: dir=%d, on=%d, mute=%d, mix=%d, mute_mic=%d, mic=%d\n", 
         this->dir, this->on, this->mute, this->mix, this->mute_mic, this->mic);
      kal_prompt_trace(MOD_L1SP, "MIC: sid=0x%x, processed_frames=%d, skip_frames=%d\n", 
         this->session_id, this->processed_frames, this->skip_frames);
   }

}
#endif

#endif // ...VMI_SUPPORT

