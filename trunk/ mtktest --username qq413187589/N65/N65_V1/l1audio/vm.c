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
 * vm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   VM recording/playback
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
#include "afe.h"

#if !defined(MT6205B)
#define VM_LOG_DEBUG
#endif
//#define VM_VR_RERECORD

#define VM_CTRL_UL         1
#define VM_CTRL_DL         2
#define VM_CTRL_SC_START   2
#define VM_CTRL_SD_START   6

#define VM_STATE_RECORD       0x1
#define VM_STATE_RECORD_PAUSE 0x2
#define VM_STATE_PLAY         0x4
#define VM_STATE_PLAY_PAUSE   0x8
#define VM_STATE_STOP         0x10 

#define VM_FLAG_PREPARE_STOP  0x1
#define VM_FLAG_READY_STOP    0x2

#define VM_BASIC_VM_DATA_SIZE    37 //SyncWord(1), header(1), vm.control(1), counter(1), counter(1), 16*2
#define VM_2G_CTRL_DL_DEBUG_SIZE 44
#define VM_4WAYPCM_DEBUG_SIZE    322
#define VM_3G_DSP_DEBUG_SIZE     17 //DSP 15 + L1_info 2 (word)
#define VM_3G_MCU_DEBUG_SIZE     37 //buffer status 1 + UL 17 + DL 19
#define VM_3G_DEBUG_SIZE         ( VM_3G_DSP_DEBUG_SIZE + VM_3G_MCU_DEBUG_SIZE )
#define VM_3G324M_DSP_DEBUG_SIZE 15 //DSP 15
#define VM_3G324M_MCU_DEBUG_SIZE 37 //buffer status 1 + UL 17 + DL 19
#define VM_3G324M_DEBUG_SIZE     ( VM_3G324M_DSP_DEBUG_SIZE + VM_3G324M_MCU_DEBUG_SIZE )
#define VM_MAXIMUM_SAVE_SIZE     91 //VM_3G_MCU_DEBUG_SIZE + VM_BASIC_VM_DATA_SIZE
#define PCM_SAVE_SIZE            644 
// 0xAA55(1), header(1), vm_lost & pcm_Lost(1),vm_counter(1), PCM (2*2*160)
#define VM_BUFFER_SIZE           512


/* ------------------------------------------------------------------------------ */
static struct{
   mediaControl   *ctrl;   
   uint16          type;
   uint16         control;    /* control word for FR/HR/EFR                         */
                              /* bit  0-1:   Channel usage(bit0:UL,bit1:DL)         */
                              /* bit  2-5:   UL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  6-9:   DL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  10:    DP_TX_TCH_S0_0 data bit 1              */
                              /* bit 11-15:  DP_RX_TCH_S0_0 data bit 1-5            */

                              /* control word for AMR                               */
                              /* bit  0-1:   Channel usage(bit0:UL,bit1:DL)         */
                              /* bit  2-5:   UL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  6-9:   DL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit 10-11:  DP_TX_TCH_S0_0 data bit 0-1            */
                              /* bit 12-15:  DP_RX_TCH_S0_0 data bit 1-3,5          */
   uint32         rb_data_len;  /* actual data size (in word) in ring buffer */
   int16          *vmBuf;    /* point to buffer for VM                              */   
#if !defined(MT6205B)
   int16          *pcmBuf;   /* point to buffer for 1st set UL-DL PCM data         */   
   uint16         debug_info; /* 0  : vm (speech codec data) only                   */
                              /* b1 : record 1st set of UL-DL PCM buffer for SPE    */
                              /* b2 : record 2nd set of UL-DL PCM buffer for SPE    */ 
   uint8          state;
   uint8          FLAGS;   
   uint8          vm_lost; 
   uint8          vm_lost_count;
   uint8          pcm_lost_count;                                                                  
   uint8          sc_mode;
   uint8          sd_mode;
#else 
   uint8          state;
#endif                               
} vm;

#if defined( VM_LOG_DEBUG )
uint8   vm_counter;
#endif

#define VM_PCM_1ST_SET_RECORD_FLAG  0x1 
#define VM_PCM_2ND_SET_RECORD_FLAG  0x2
#define VM_VM_RECORD_FLAG           0x4
#define TCH_VM_INT_FLAG             0x1 
#define TCH_PCM_INT_FLAG            0x2 

/* ------------------------------------------------------------------------------ */
#define  PUT_RECORD_DATA(val)                                  \
   {                                                           \
      if( vm.ctrl->read > vm.ctrl->write ) {                   \
         if( vm.ctrl->read - vm.ctrl->write > 1 )              \
            vm.ctrl->rb_base[vm.ctrl->write++] = (val);        \
      }                                                        \
      else if( vm.ctrl->read == 0 ) {                          \
         if( vm.ctrl->rb_size - vm.ctrl->write > 1 )           \
            vm.ctrl->rb_base[vm.ctrl->write++] = (val);        \
      }                                                        \
      else {                                                   \
         vm.ctrl->rb_base[vm.ctrl->write++] = (val);           \
         if( vm.ctrl->write == vm.ctrl->rb_size )              \
            vm.ctrl->write = 0;                                \
      }                                                        \
   }

#define GET_VM_LENGTH(control)  AM_GetSpeechPatternLength((control >> VM_CTRL_SC_START) & 0x0F) \
                                + AM_GetSpeechPatternLength((control >> VM_CTRL_SD_START) & 0x0F) + 5
                                //0xAA55, format, FN, FN_counter, vm.control

#if defined( VM_LOG_DEBUG )
static uint16 vmRecGetDebugSize(uint16 sc_mode, uint16 sd_mode, uint16 debug_info,uint32 mode)
{
   uint16 count = 0;
   
   if( mode <= 1 && sd_mode > 2 && sd_mode < 11 && (vm.control & VM_CTRL_DL) ){
      count += VM_2G_CTRL_DL_DEBUG_SIZE;
   }
   if( mode >= 1 ){//speech mode
      //if( debug_info & VM_PCM_1ST_SET_RECORD_FLAG )
      //   count += VM_4WAYPCM_DEBUG_SIZE;
      //if( debug_info & VM_PCM_2ND_SET_RECORD_FLAG )
      //   count += VM_4WAYPCM_DEBUG_SIZE;
#if defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   }
   return count;
}
#endif

//use this function instead of Media_WriteDataDone to avoid media.waiting false usage
static void vmWriteDataDone( uint32 len )
{
   vm.ctrl->write += len;
   if( vm.ctrl->write >= vm.ctrl->rb_size )
      vm.ctrl->write = 0;
}

static void vmWriteVmToMB( uint32 vmLen, uint16 *vmBuf ) // a frame of VM must be written to MB
{
   uint16 *bufPtr;
   uint32 bufLen, I;
   
   Media_GetWriteBuffer( &bufPtr, &bufLen );
   if(bufLen > vmLen)      
      bufLen = vmLen;
   for( I = bufLen ; I > 0 ; I-- )
      *bufPtr++ = *vmBuf++;
   vmWriteDataDone( bufLen );
   
   vmLen -= bufLen;
   if( (int32)vmLen > 0 )
   {
      Media_GetWriteBuffer( &bufPtr, &bufLen );
      for( I = vmLen ; I > 0 ; I-- )
         *bufPtr++ = *vmBuf++;
      vmWriteDataDone( vmLen );
   }
   return;
}

void vmRecordHisr( void )
{
   volatile uint16   *addr;
   uint16   I, sc_mode, sd_mode, sc_len, sd_len;
   uint16   *vmBuf;
   uint32   vmLen = 0;

#if defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
#endif

   if (vm.state != VM_STATE_RECORD)
      return;

   vmBuf = (uint16 *)vm.vmBuf;
#if defined( VM_LOG_DEBUG )
   if( vmBuf[0] == 0xAA55 ){//already buffer VM
      I = (uint16)( vmBuf[1] >> 6 ) + GET_VM_LENGTH(vmBuf[4]);
      if( mediaGetFreeSpace() < I )
         return;
      else{
         vmWriteVmToMB( (uint32)I, vmBuf );
         vm.vm_lost_count = 0;
         *(uint32 *)vm.vmBuf = 0;
      }
   }
#endif
#if !defined(MT6205B)
   // From VM_FLAG_PREPARE_STOP to VM_FLAG_READY_STOP period, 
   //                       record 1 vm data for correct playback in vm_drv.c  
   if(vm.FLAGS == VM_FLAG_PREPARE_STOP)
      vm.FLAGS = VM_FLAG_READY_STOP;        
#endif       

   I        = *DP_SC_MODE;
   sc_mode  = (I >> 8) & 0x0F;
   sd_mode  = I & 0x0F;
/*   if( sd_mode > 2 ) {
      sc_mode = (*DP_SC_TCH_MODE >> 8) & 0x0F;
      sd_mode = (*DP_SD_TCH_MODE >> 8) & 0x0F;
   } Turn off by WH Hsu */
   if( sc_mode>2 && sc_mode<11 ){
   	I = *DP_RX_TCH_S(0,17) >> 8;
	sd_mode = I & 0x1F;
   	I = *DP_TX_TCH_S(0,17) >> 8;
	sc_mode = I & 0x1F;
   }
#if defined( VM_LOG_DEBUG )
   /*for catcher log codec information*/
   if( vm.sc_mode != sc_mode || vm.sd_mode != sd_mode ){
      L1Audio_Msg_SPEECH_CODEC( L1SP_Speech_Codec_Mode(sc_mode), L1SP_Speech_Codec_Mode(sd_mode) );
      vm.sc_mode = sc_mode;
      vm.sd_mode = sc_mode;
   }
#if defined(__MA_L1__) || defined(MT6268T)
   {
      uint8 rx_type, tx_type, BFI;
      uint16 rx_debug;
      rx_debug = *DP_RX_TCH_S(0,0);
      tx_type = *DP_RX_TCH_S(0,0) & 0x3;
      rx_type = (rx_debug >> 1) & 0x7;
      BFI = (rx_debug >> 5) & 0x1;   //speechBFI
      if( rx_type < 3 )//non-amr
         rx_type = 8 + (rx_type << 1) + BFI;
      BFI = (rx_debug >> 8) & 0xFF;  //BER
      L1Audio_Msg_SPEECH_FRAME( L1SP_Speech_TX_Type(tx_type), L1SP_Speech_RX_Type(rx_type), BFI);
      L1Audio_Msg_VM_DEBUG( DP2_3G_debug_info0, DP2_3G_debug_info1, DP2_3G_debug_info7 );
   }
#endif
#endif
   
   sc_len = AM_GetSpeechPatternLength(sc_mode);
   sd_len = AM_GetSpeechPatternLength(sd_mode);
   if( sc_mode <= 2 ) {
      vm.control =((*DP_RX_TCH_S(0,0) & 0x3E) << 10) |
                  ((*DP_TX_TCH_S(0,0) & 2)<< 9 ) |
                  (sd_mode << VM_CTRL_SD_START) |
                  (sc_mode << VM_CTRL_SC_START) |
                  (vm.control & 3);
   }
   else {
      I = *DP_RX_TCH_S(0,0) >> 1;
      I = ((I & 0x10)>>1) | (I & 0x07);
      vm.control =(I << 12) |
                  ((*DP_TX_TCH_S(0,0) & 3)<< 10 ) |
                  (sd_mode << VM_CTRL_SD_START) |
                  (sc_mode << VM_CTRL_SC_START) |
                  (vm.control & 3);
   }

#if defined( VM_LOG_DEBUG )
   {
      extern int32 L1T_GetFN( void );
      uint32 J;

      *vmBuf++ = 0xAA55;
      J = L1SP_GetState();
      I = (uint16)( ( vmRecGetDebugSize(sc_mode, sd_mode, vm.debug_info, J) << 6 ) | 
             ( J << 3 ) |    //speech mode
             VM_VM_RECORD_FLAG );          //VM format
      *vmBuf++ = I;
      J = L1T_GetFN();
      I = (uint16)(J & 0xFFFF);
      *vmBuf++ = I;
      I = (uint16)((J >> 16) + ((uint32)vm_counter << 8));
      *vmBuf++ = I;
      vm_counter++;
   }
#endif
#if !defined (VM_VR_RERECORD)
   if( vm.ctrl->format != MEDIA_FORMAT_VRD ){
      *vmBuf++ = vm.control;
      vmLen++;
   }
#endif
   if( vm.control & VM_CTRL_UL ) {
      addr = DP_TX_TCH_S( 0, 1 );
      vmLen += sc_len;
      for( I = 0; I < sc_len; I++ )
         *vmBuf++ = *addr++;
   }

   if( vm.control & VM_CTRL_DL ) {
      addr = DP_RX_TCH_S( 0, 1 );
      vmLen += sc_len;
      for( I = 0; I < sd_len; I++ )
         *vmBuf++ = *addr++;

#if defined( VM_LOG_DEBUG )
      if( sd_mode>2 && sd_mode<11 ){
         addr = DP_RX_TCH_S( 0, 17);
         *vmBuf++ = *addr++;	// Rx
         addr = DP_TX_TCH_S( 0, 17);
         *vmBuf++ = *addr++;	// Tx
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
         addr = (volatile uint16 *)DP_SP_VM_CTRL_base(0x24);
#else
         addr = (volatile uint16 *)DP_SP_VM_CTRL_base(0x1b7);
#endif
         for( I = 0; I < 42 ; I++ )
            *vmBuf++ = *addr++;
      }
#endif
   }
   #if defined( MT6205B )
      vmWriteVmToMB( vmLen, (uint16 *)vm.vmBuf ); // no debug info, direct write into MB
   #endif
}

#define  GET_PLAYBACK_DATA(val)                            \
      if( vm.ctrl->read != vm.ctrl->write ) {              \
         (val) = vm.ctrl->rb_base[vm.ctrl->read++];        \
         vm.rb_data_len -= 1;                              \
         if( vm.ctrl->read >= vm.ctrl->rb_size )           \
            vm.ctrl->read = 0;                             \
      }                                                    \
      else {                                               \
         return;                                           \
      }

static void vm_playback( void )
{
   volatile uint16 *addr;
   uint16   I, control, sc_mode, sd_mode, data_len, data;
#if defined( VM_LOG_DEBUG )
   uint16   dummy_tmp;
#endif

   while( 1 ) {
      if( vm.ctrl->format != MEDIA_FORMAT_VRD && vm.ctrl->format != MEDIA_FORMAT_VRSI) {
#if defined( VM_LOG_DEBUG )
         do {
            GET_PLAYBACK_DATA( control );
         } while( control != 0xAA55 );
         GET_PLAYBACK_DATA( control );       /* ignore frame number(0~15)                 */
         GET_PLAYBACK_DATA( control );       /* ignore frame number(16~24) and time stamp */
#endif
         GET_PLAYBACK_DATA( control );
         if( (control&3) == 0 )
            continue;
      }
      else
         control = 0x401;

      sc_mode = (control >> VM_CTRL_SC_START) & 0x0F;
      sd_mode = (control >> VM_CTRL_SD_START) & 0x0F;
#if !defined(MT6205B)
      if( sc_mode != sd_mode && (sc_mode <= 2 || sd_mode <= 2) )
         continue;
#else
      if( sc_mode > 2 || sc_mode != sd_mode )
         continue;
#endif
      break;
   }

   if( control & VM_CTRL_UL ) {
      addr = DP_SD2_VM_0;
      if( sc_mode <= 2 )
         *addr++ = (control >> 9) & 2;       /* Write real AMR UL data */
      else
         *addr++ = (control >> 10) & 3;      /* Write real AMR UL data */
      data_len = AM_GetSpeechPatternLength(sc_mode);
      for( I = 0; I < data_len; I++ )
         GET_PLAYBACK_DATA( *addr++ );
   }
   else {                                             /* No UL data */
      sc_mode = sd_mode;
      AM_FillSilencePattern( DP_SD2_VM_0, 2, sc_mode );
   }
   if( sc_mode > 2 )
      *DP_SD2_VM_17 = sc_mode;

   if( (control & VM_CTRL_DL) == 0 ) {                /* No DL data */
      sd_mode = sc_mode;
      AM_FillSilencePattern( DP_SD1_VM_0, 0, sd_mode );
   }
   else if( control & 0x8000 ) {                      /* bad speech */
      AM_FillSilencePattern( DP_SD1_VM_0, 0, sd_mode );
      data_len = AM_GetSpeechPatternLength(sd_mode);
      for( I = 0; I < data_len; I++ )
         GET_PLAYBACK_DATA( data );
   }
   else {
      addr = DP_SD1_VM_0;
      if( sd_mode <= 2 )
         *addr++ = (control >> 10) & 0x3E;
      else {
         I = (control >> 12);
         *addr++ = ((I & 8) << 2) + ((I & 7) << 1);
      }
      data_len = AM_GetSpeechPatternLength(sd_mode);
      for( I = 0; I < data_len; I++ )
         GET_PLAYBACK_DATA( *addr++ );
   }
#if defined( VM_LOG_DEBUG )
   if( sd_mode>2 && sd_mode<11 && (control & VM_CTRL_DL) ){
    	GET_PLAYBACK_DATA( dummy_tmp );
    	GET_PLAYBACK_DATA( dummy_tmp );
      for( I = 0; I <42; I++ )
         GET_PLAYBACK_DATA( dummy_tmp );
   }
#endif
   if( sd_mode > 2 )
      *DP_SD1_VM_17 = sd_mode;

   if( (vm.control==0) || ((vm.control & 0x3FC) != (control & 0x3FC)) ) {
      vm.control = control;
      /* Set Digital Gain for Voice Memo */
      AFE_SetDigitalGain( L1SP_VOICE, 100 );
      AM_VMPlaybackOn( control, vm.ctrl->param.vm );
   }
}

/* ------------------------------------------------------------------------------ */
void vmPlaybackHisr( void )
{
   int32 count;

   if (vm.state != VM_STATE_PLAY)
      return;

   vm_playback();
   count = (int32)vm.ctrl->write - (int32)vm.ctrl->read;
   if( count < 0 )
      count += vm.ctrl->rb_size;
   if( vm.ctrl->eof && (count < 17 || (vm.rb_data_len == 0
      && vm.ctrl->format == MEDIA_FORMAT_VRD))) {
      AM_VMPlaybackOff( vm.ctrl->param.vm );
      mediaSetEvent( MEDIA_END );
   }
}
/* ------------------------------------------------------------------------------ */

#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)

#if defined(MT6205B) || defined(MT6217) || defined(MT6218B) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225)
#define PAGE_NUM 0
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PAGE_NUM 2
#elif defined(MT6223) || defined(MT6223P)
#define PAGE_NUM 1
#else
#error The new chip should define DM page number
#endif

// Setting for recording 2nd set UL-DL PCM data 
#if defined(MT6227) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227D)
#define PCM1_UL_PAGE_NUM   0
#define PCM1_UL_BUF_ADDR   0x0950
#define PCM1_DL_PAGE_NUM   0
#define PCM1_DL_BUF_ADDR   0x09F0

#define PCM2_UL_PAGE_NUM   0
#define PCM2_UL_BUF_ADDR   0x810
#define PCM2_DL_PAGE_NUM   0
#define PCM2_DL_BUF_ADDR   0x8B0    
#elif defined(MT6228) || defined(MT6225)
#define PCM1_UL_PAGE_NUM   0
#define PCM1_UL_BUF_ADDR   0x0540
#define PCM1_DL_PAGE_NUM   0
#define PCM1_DL_BUF_ADDR   0x05E0

#define PCM2_UL_PAGE_NUM   0
#define PCM2_UL_BUF_ADDR   0x400
#define PCM2_DL_PAGE_NUM   0
#define PCM2_DL_BUF_ADDR   0x4A0  
#elif defined(MT6223) || defined(MT6223P)
#define PCM1_UL_PAGE_NUM   1
#define PCM1_UL_BUF_ADDR   0x03C1
#define PCM1_DL_PAGE_NUM   1
#define PCM1_DL_BUF_ADDR   0x0461

#define PCM2_UL_PAGE_NUM   1
#define PCM2_UL_BUF_ADDR   0x281
#define PCM2_DL_PAGE_NUM   1
#define PCM2_DL_BUF_ADDR   0x321
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PCM1_UL_PAGE_NUM   2
#define PCM1_UL_BUF_ADDR   0x17C0
#define PCM1_DL_PAGE_NUM   2
#define PCM1_DL_BUF_ADDR   0x1860

#define PCM2_UL_PAGE_NUM   2
#define PCM2_UL_BUF_ADDR   0x1680
#define PCM2_DL_PAGE_NUM   2
#define PCM2_DL_BUF_ADDR   0x1720  
#else 
#define PCM1_UL_PAGE_NUM 0
#define PCM1_UL_BUF_ADDR 0
#define PCM1_DL_PAGE_NUM 0
#define PCM1_DL_BUF_ADDR 0

#define PCM2_UL_PAGE_NUM   0
#define PCM2_UL_BUF_ADDR   0
#define PCM2_DL_PAGE_NUM   0
#define PCM2_DL_BUF_ADDR   0  
#endif 

#define FRAME_BUF_SIZE 160

extern int32 mediaGetFreeSpace( void );

void vmTchPcmRecordHisr(void *param)
{
   uint32 I, tmp = 0;
   uint16 dummy;
   uint16 *buf, *mBuf;
   
   if(vm.FLAGS ==  VM_FLAG_READY_STOP || vm.state != VM_STATE_RECORD )
      return;
   
   //should unmark?
   //if(vm.vm_lost == 1)
   //   return;
   
   buf = (uint16 *)vm.vmBuf;
   if( buf[0] == 0xAA55 ){//already buffer VM
      tmp = ( buf[1] >> 6 ) + PCM_SAVE_SIZE; // debug size
      I = tmp + GET_VM_LENGTH(buf[4]);
   } else {
      tmp = PCM_SAVE_SIZE;  //debug size(only PCM)
      I = PCM_SAVE_SIZE + 2;// plus sync word and format
   }
   if( mediaGetFreeSpace() < I )
   {
      vm.pcm_lost_count++; 
      return;       
   } else {
      buf[0] = 0xAA55;
      buf[1] &= ~0xFFF8;
      buf[1] |= (uint16)(tmp << 6) | 
               ( L1SP_GetState() << 3) |
               ( vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG) );
   }
   Media_GetWriteBuffer( &mBuf, &tmp );
   I -= PCM_SAVE_SIZE;
   if( tmp > I )
      tmp = I;
   for( dummy = (uint16)tmp ; dummy > 0 ; dummy-- )
      *mBuf++ = *buf++;
   vmWriteDataDone( tmp );
   I -= tmp;
   if( (int32)I > 0 ){
      Media_GetWriteBuffer( &mBuf, &tmp );
      for( dummy = (uint16)I ; dummy > 0 ; dummy-- )
         *mBuf++ = *buf++;
      vmWriteDataDone( I );
   }
                  
   ASSERT( *DP_TCH_UL_LEN == FRAME_BUF_SIZE );   // uplink frame size
   ASSERT( *DP_TCH_DL_LEN == FRAME_BUF_SIZE );   // downlink frame size
   
   if(vm.debug_info & VM_PCM_1ST_SET_RECORD_FLAG)
   {
      buf = (uint16 *)vm.pcmBuf; 
      // header for record 1st set of UL-DL PCM data 
      *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
      *buf++ = vm_counter ;
      
      // Uplink
      
      // Uplink
      dummy = *DSP_DM_ADDR(PCM1_UL_PAGE_NUM, PCM1_UL_BUF_ADDR);
      for ( I = FRAME_BUF_SIZE; I > 0; I-- ) {
         *buf = (int16)(*IDMA_SHORT_ADDR);
         buf += 2;
      }
      
      // Downlink 
      buf -= ((FRAME_BUF_SIZE << 1) - 1);
      dummy = *DSP_DM_ADDR(PCM1_DL_PAGE_NUM, PCM1_DL_BUF_ADDR);
      for ( I = FRAME_BUF_SIZE; I > 0; I-- ) {
         *buf = (int16)(*IDMA_SHORT_ADDR);
         buf += 2;
      }
      
      buf = (uint16 *)vm.pcmBuf;
      Media_GetWriteBuffer( &mBuf, &tmp );
      if( tmp > VM_4WAYPCM_DEBUG_SIZE )
         tmp = VM_4WAYPCM_DEBUG_SIZE;
      for( I = tmp ; I > 0 ; I-- )
         *mBuf++ = *buf++;
      vmWriteDataDone( tmp );
      tmp = VM_4WAYPCM_DEBUG_SIZE - tmp;
      if( (int32)tmp > 0 ){
         Media_GetWriteBuffer( &mBuf, &I );
         for( I = tmp ; I > 0 ; I--)
            *mBuf++ = *buf++;
         vmWriteDataDone( tmp );
      }
   }  
#if !(defined(MT6217) || defined(MT6219))      
   if(vm.debug_info & VM_PCM_2ND_SET_RECORD_FLAG)
   {      
      // header for record 2nd set of UL-DL PCM data 
      buf = (uint16 *)vm.pcmBuf;
      *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
      *buf++ = vm_counter ;
      
      // Uplink
      dummy = *DSP_DM_ADDR(PCM2_UL_PAGE_NUM, PCM2_UL_BUF_ADDR);
      for ( I = FRAME_BUF_SIZE; I > 0; I-- ) {
         *buf = (int16)(*IDMA_SHORT_ADDR);
         buf += 2;
      }
      
      // Downlink 
      buf -= ((FRAME_BUF_SIZE << 1) - 1);
      dummy = *DSP_DM_ADDR(PCM2_DL_PAGE_NUM, PCM2_DL_BUF_ADDR);
      for ( I = FRAME_BUF_SIZE; I > 0; I-- ) {
         *buf = (int16)(*IDMA_SHORT_ADDR);
         buf += 2;
      }
      
      buf = (uint16 *)vm.pcmBuf;
      Media_GetWriteBuffer( &mBuf, &tmp );
      if( tmp > VM_4WAYPCM_DEBUG_SIZE )
         tmp = VM_4WAYPCM_DEBUG_SIZE;
      for( I = tmp ; I > 0 ; I--)
         *mBuf++ = *buf++;
      vmWriteDataDone( tmp );
      tmp = VM_4WAYPCM_DEBUG_SIZE - tmp;
      if( (int32)tmp > 0 ){
         Media_GetWriteBuffer( &mBuf, &I );
         for( I = tmp ; I > 0 ; I--)
            *mBuf++ = *buf++;
         vmWriteDataDone( tmp );
      }
   }         
#endif    
   *(int32 *)vm.vmBuf = 0;//reset
   //vm.vm_lost_count = 0;
   vm.pcm_lost_count = 0;
}

void vmTchRecordHisr(void *param)
{
   if(vm.FLAGS == VM_FLAG_READY_STOP || vm.state != VM_STATE_RECORD) 
      return;
      
   if(mediaGetFreeSpace() < VM_MAXIMUM_SAVE_SIZE)
   {
      vm.vm_lost = 1; 
      vm.vm_lost_count ++;
      mediaDataNotification();
      return;       
   }   
   
   vm.vm_lost = 0;
   vmRecordHisr();
   mediaDataNotification();        
}

extern void SP3G_Start_VM( void ); 
extern void SP3G_Stop_VM( void ); 
extern bool SP3G_VM_Status( void ); 

void vmSpeechOnHandler( void *state ) 
{
   if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))
   {     
      AM_PCM8K_RecordOn();
   }
#if defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   if( (uint32)state == L1SP_STATE_2G_SPEECH_ON ){
      L1Audio_HookHisrHandler( DP_D2C_SE_SD_DONE, vmTchRecordHisr, 0 );
      AM_VMRecordOn( (uint16)vm.type );
   }
}

void vmSpeechOffHandler( void *state ) 
{      
   if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))
   {      
      AM_PCM8K_RecordOff(false);      
   }
#if defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   if( (uint32)state == L1SP_STATE_2G_SPEECH_ON ){
      *DP_SC_MUTE = 0x0000;
      L1Audio_UnhookHisrHandler( DP_D2C_SE_SD_DONE );
      AM_VMRecordOff();
   }
}

#endif 

void vmRecord( mediaControl *ctrl, uint16 type )
{
   vm.ctrl = ctrl;
   vm.type = type;
   vm.state = VM_STATE_RECORD;

   vm.vmBuf = (int16 *)get_ctrl_buffer( VM_BUFFER_SIZE );
   memset( vm.vmBuf, 0, VM_BUFFER_SIZE );

   if( AM_IsSpeechOn() ) {
      vm.control = 0x0003;
#if defined(MT6205B)
      AM_VMRecordOn( (uint16)type );
#else
      vm.debug_info = L1Audio_GetDebugInfo(VM_DEBUG_INFO);      
#if defined(MT6217) || defined(MT6219)    
      vm.debug_info &= VM_PCM_1ST_SET_RECORD_FLAG;
#endif 
      if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))   
      {
         vm.pcmBuf = (int16*)get_ctrl_buffer( VM_4WAYPCM_DEBUG_SIZE * 2 );
         vm.pcm_lost_count = 0; 
         vm.vm_lost  = 1; // to force save VM first     
         vm.vm_lost_count = 0;
         L1Audio_HookHisrHandler( DP_D2C_PCM_TCH_R, vmTchPcmRecordHisr, 0 );
         AM_PCM8K_RecordOn();         
      }
      vm.FLAGS = 0;
#if defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
      { //2G
         L1Audio_HookHisrHandler( DP_D2C_SE_SD_DONE, vmTchRecordHisr, 0 );
         AM_VMRecordOn( (uint16)type );
      }
      L1SP_Register_Service(vmSpeechOnHandler, vmSpeechOffHandler);
#endif          
   }
   else {
      // for idle-mode recording , will use DP_D2C_SE_DONE , through mediaHisr -> vmRecordHisr
      vm.control = 0x0001;
      *DP_SC_MUTE = 0x0002;
      AM_VMRecordOn( (uint16)type );
   }
}

Media_Status vmPlay( mediaControl *ctrl )
{
   uint32 dummy_32;

   vm.ctrl = ctrl;
   vm.state = VM_STATE_PLAY;
   vm.control = 0;

/* VRD parser */
   if(vm.ctrl->format == MEDIA_FORMAT_VRD){
         /* Check to see if header is invalid, "MTKV" or "CYBV" chunk descriptor */
      if( rb_GetDWord( &dummy_32 ) == false || (dummy_32 != 0x564B544D && dummy_32 != 0x56425943))
         return MEDIA_BAD_FORMAT;

      rb_SkipNWord( 3 ); /* skip chunk size and ID field*/

      if( rb_GetDWord( &dummy_32 ) == false || dummy_32 != 0x45434F56 ) /* "VOCE" chunk descriptor */
         return MEDIA_BAD_FORMAT;

         // Get the VOCE ckSize
      if( rb_GetDWord( &vm.rb_data_len ) == false )
         return MEDIA_BAD_FORMAT;

      vm.rb_data_len >>= 1; /* change data length in word */
   }

   vm_playback();
   return MEDIA_SUCCESS;
}

void vmStop( void )
{

#if !defined(MT6205B)
   if(vm.control & 0x02)
   {
      uint32 I;
      if( L1SP_GetState() == L1SP_STATE_2G_SPEECH_ON ){
         vm.FLAGS = VM_FLAG_PREPARE_STOP;
         for( I = 0; ; I++ )
         {
            if(vm.state == VM_STATE_RECORD_PAUSE)
               vm.FLAGS = VM_FLAG_READY_STOP;
            if(vm.FLAGS == VM_FLAG_READY_STOP)
               break;
            ASSERT( I < 40 );
            kal_sleep_task(1);   
         }
      }
      
      if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))  
      {    
         AM_PCM8K_RecordOff(false);
         L1Audio_UnhookHisrHandler( DP_D2C_PCM_TCH_R );
         free_ctrl_buffer(vm.pcmBuf);
         
      }
      if( L1SP_GetState() == L1SP_STATE_2G_SPEECH_ON )
         L1Audio_UnhookHisrHandler(DP_D2C_SE_SD_DONE);
      L1SP_UnRegister_Service();
   }   
#endif    
      
   switch(vm.state) {
      case VM_STATE_RECORD:
      case VM_STATE_RECORD_PAUSE:     
         *DP_SC_MUTE = 0x0000;
#if defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            AM_VMRecordOff();
         break;
      case VM_STATE_PLAY:
      case VM_STATE_PLAY_PAUSE:
         AM_VMPlaybackOff(vm.ctrl->param.vm);
         break;
      default:
         ASSERT(KAL_FALSE);
   }

   if( vm.vmBuf != NULL ){
      free_ctrl_buffer( vm.vmBuf );
      vm.vmBuf = NULL;
   }

   vm.state = VM_STATE_STOP;
}

void vmPause(mediaControl *ctrl)
{
   switch(vm.state) {
      case VM_STATE_RECORD:
#if !defined(MT6205B)
         if((vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG)) && AM_IsSpeechOn())               
            AM_PCM8K_RecordOff(false);                       
#endif             
         *DP_SC_MUTE = 0x0000;
#if defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            AM_VMRecordOff();
         vm.state = VM_STATE_RECORD_PAUSE;
         break;
      case VM_STATE_PLAY:
         AM_VMPlaybackOff(vm.ctrl->param.vm);
         vm.state = VM_STATE_PLAY_PAUSE;
         break;
      default:
         ASSERT(KAL_FALSE);
   }

}

void vmResume(mediaControl *ctrl)
{
   switch(vm.state) {
      case VM_STATE_RECORD_PAUSE:
         if( AM_IsSpeechOn() ) {
            vm.control = 0x0003;
#if !defined(MT6205B)
            if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))  
            {
               AM_PCM8K_RecordOn();
            }   
#endif             
         }
         else {
            vm.control = 0x0001;
            *DP_SC_MUTE = 0x0002;
         }
         AM_VMRecordOn( (uint16)vm.type );
         vm.state = VM_STATE_RECORD;
         break;
      case VM_STATE_PLAY_PAUSE:
         vm.state = VM_STATE_PLAY;
         vm.control = 0;
         vm_playback();
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}
/* ------------------------------------------------------------------------------ */

extern int32 L1T_GetFN( void );
#if defined( __WCDMA_RAT__ )
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
#if defined(__MA_L1__) || defined(MT6268T)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // __WCDMA_RAT__
