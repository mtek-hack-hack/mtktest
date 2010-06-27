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
 * BT_PcmLoopback.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 * Bluetooth Pcm loopback function
 *
 * Author:
 * -------
 * -------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "media.h"
#include "l1Audio_def.h"
#include "tonedect.h"

//#define BTLB_DEBUG

#ifdef BTLB_DEBUG 
#include "fat_fs.h"  /* file system */
   static kal_wchar debugFile[50]; 
   static uint16 btlbPcmDebugBuf[80000]; // for debug 
   static uint16 *pcmDebugPtr; // for debug 
   static uint32 pcmDebugCnt;
#endif    

#define BLOCK_SIZE         320      //size of a process block (sizeof(int16))
#define TARGET_TONE        697

#define BTLB_BLOCK_IN_BUFFER       1/*number of speech block in buffer*/
#define BTLB_BUF_LEN (BLOCK_SIZE * BTLB_BLOCK_IN_BUFFER) /*the size will set to media buffer size, sizeof(int16)*/
#define BTLB_TONE_MAG_DB_THRESHOLD 55 /*if larger than this definition, then the tone exists*/

extern kal_uint8 BT_CHIP_ID;         //defined in custom\common\bt_common_config.c
static kal_uint32 dspVol = 0x0200;
//do nothing, just to fit Media_Record second argument
static void BTLB_Handler(Media_Event event)
{
   return;
}

void BTLB_SetDigitalGain(kal_uint32 gain)
{
	if ( gain > 0x7FFF )
	   gain = 0x7FFF;
	dspVol = gain;
}

kal_bool BT_PcmLoopbackTest(void)
{
   kal_int16 i, count = 0;
   kal_uint16 *buf;
   kal_uint32 len = 0, acmLen = 0;
   kal_int32 magDB = 0;
   TD_Handle hdl;
   kal_uint16 *rb_base;
   
   AM_BluetoothOn(2);//2:open earphone mode, 1: open cordless mode
   AM_FlushQFunction();
   
   kal_prompt_trace(MOD_L1SP, "after set,DP_VOL_OUT_PCM= %d",*DP_VOL_OUT_PCM);
   
   /*initialize*/
   rb_base = (kal_uint16 *)get_ctrl_buffer(BTLB_BUF_LEN << 1);
   Media_SetBuffer( rb_base, BTLB_BUF_LEN );
   TD_Init( &hdl, TARGET_TONE, BLOCK_SIZE);

#ifdef BTLB_DEBUG
   pcmDebugCnt = 0;
   pcmDebugPtr = btlbPcmDebugBuf;
#endif
   /*start tone_play and record*/
   
   KT_Play(TARGET_TONE, 0, 0); /*play single tone , continuous play*/
   Media_Record(MEDIA_FORMAT_PCM_8K, BTLB_Handler, (void *)0);

   for (i = 0 ; i < 100 ; i++)/*if delay is large, we should enlarge this waiting*/
   {
      Media_GetReadBuffer(&buf ,&len);
      if ( len==0 )
         kal_sleep_task(1);
      else{
         if ( (len + acmLen) >= BLOCK_SIZE ){/*acumulated length >= BLOCK_SIZE*/
            len = BLOCK_SIZE - acmLen;/*recount samples to fit block*/
         }
         TD_ProcessBlock(&hdl, (kal_int16 *)buf, len);
#ifdef BTLB_DEBUG
{
         int j;
         for(j = 0 ; j < len ; j++ )
            if( pcmDebugCnt < 80000 )
            {
               *pcmDebugPtr++ = buf[j];
               pcmDebugCnt ++;
            }
}
#endif
         Media_ReadDataDone( len );
         acmLen += len;
         if ( acmLen >= BLOCK_SIZE){
            magDB = TD_GetMagnitudeDB( &hdl );
            kal_prompt_trace( MOD_L1SP, "magDB = %d", magDB);
            if( magDB > BTLB_TONE_MAG_DB_THRESHOLD )
              count ++;
            TD_Reset( &hdl );
            acmLen=0;//reset
         
            if ( count > 2)
               break;
         }
      }
   }

#ifdef BTLB_DEBUG
{
      int file_handle;
      kal_prompt_trace(MOD_L1SP, "prepare to dump pcm file");
      kal_wsprintf(debugFile, "d:\\BTLBdebug.pcm");
      file_handle = FS_Open(debugFile, FS_CREATE);
      if(file_handle > 0) 
      { 
         FS_Write( file_handle, (void *)btlbPcmDebugBuf, pcmDebugCnt << 1, NULL );
         FS_Close(file_handle);
         kal_prompt_trace(MOD_L1SP, "finish dump pcm file BTLBdebug.pcm");
      }
      else{
      	kal_prompt_trace(MOD_L1SP, "unable to dump file");
      }
      
}
#endif
   KT_StopAndWait();
   Media_Stop();
   AM_BluetoothOff();//close earphone mode
   /*close loopback path, should be removed in the future*/
   //*AFE_VAC_CON1 &= ~0x02;
   
   free_ctrl_buffer( rb_base );
   
   if ( count > 2){
      return true;
   }else
      return false;
}
