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
 *   VoIPev_drv.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  VoIP auto speech record interface
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
#include "media.h"

#if VORTP_SUPPORT || defined(VORTP_UNIT_TEST)
/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define STATE_IDLE                      0     // 1
#define STATE_RECORDING                 1     // 2,0
#define STATE_RECORD_PAUSE              2     // 0,1

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/

/*****************************************************************************
*                        P U B L I C   D A T A
******************************************************************************
*/

/*****************************************************************************
*                       P R I V A T E   D A T A
******************************************************************************
*/
static struct {
   mediaControl     *ctrl;
   uint8            state;
   kal_mutexid      mutex;  // protect ctrl
   kal_uint32       produced_bytes;
} VoIPev_context;

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/

/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/

/*****************************************************************************
*                          F U N C T I O N S
******************************************************************************
*/
void VoIPev_Protect()
{
#if !defined(SIM_ON_VC)
   kal_take_mutex(VoIPev_context.mutex);
#endif
}

void VoIPev_UnProtect()
{
#if !defined(SIM_ON_VC)
   kal_give_mutex(VoIPev_context.mutex);
#endif
}

void VoIPev_AppendData(kal_uint8 *dataPtr, kal_uint32 dataLen)
{
   mediaControl *ctrl;
   int32 dataLenInWords;
   
   if(STATE_RECORDING != VoIPev_context.state)
      return;

   dataLenInWords = (dataLen + 1) >> 1;
   ASSERT(mediaGetFreeSpace() >= dataLenInWords);

   ctrl = VoIPev_context.ctrl;
   while(dataLenInWords > 0)
   {
      uint16 *dest;
      uint32 count;

      Media_GetWriteBuffer(&dest, &count);
      if(count > dataLenInWords)
         count = dataLenInWords;
      memcpy(dest, dataPtr, count<<1);
      ctrl->write += count;
      if( ctrl->write >= ctrl->rb_size )
         ctrl->write = 0;
      dataPtr += count << 1;
      dataLenInWords -= count;
   }
}

void VoIPev_Flush()
{
   if(STATE_RECORDING != VoIPev_context.state)
      return;

   mediaDataNotification();
}

/* Media Recording interface */

void VoIPevInit()
{
   VoIPev_context.state = STATE_IDLE;
   VoIPev_context.mutex = kal_create_mutex("VoIPev");
}

void  VoIPevRecord( mediaControl *ctrl )
{
   ASSERT(STATE_IDLE == VoIPev_context.state);
   VoIPev_context.ctrl = ctrl;
   VoIPev_context.state = STATE_RECORDING;
   VoRTP_SetEventLogging(KAL_TRUE);
}

void  VoIPevStop()
{
   switch(VoIPev_context.state)
   {
      case STATE_IDLE:
         return;
      case STATE_RECORDING:
      case STATE_RECORD_PAUSE:
         VoRTP_SetEventLogging(KAL_FALSE);
         VoIPev_context.state = STATE_IDLE;
         break;
      default:
         ASSERT(0);
         break;
   }
}

void  VoIPevPause()
{
   switch(VoIPev_context.state)
   {
      case STATE_RECORDING:
         VoRTP_SetEventLogging(KAL_FALSE);
         VoIPev_context.state = STATE_RECORD_PAUSE;
         break;
      case STATE_IDLE:
      case STATE_RECORD_PAUSE:
      default:
         ASSERT(0);
         break;
   }
}

void  VoIPevResume()
{
   switch(VoIPev_context.state)
   {
      case STATE_RECORD_PAUSE:
         VoRTP_SetEventLogging(KAL_TRUE);
         VoIPev_context.state = STATE_RECORDING;
         break;
      case STATE_RECORDING:
      case STATE_IDLE:
      default:
         ASSERT(0);
         break;
   }
}

#endif // ... __VOIP__

