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
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    video_editor_buffer_manager.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines buffer manager of video editor.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__VIDEO_EDITOR__)
#include    "FSAL.h"
#include    "MP4_Parser.h"
#include    "MP4_Producer_Audio.h"
#include    "MP4_Sample_Data_Audio.h"
#include    "rtc_sw.h"
#include    "lcd_if.h"
#include    "bmd.h"
#include    "video_file_creator.h"
#include    "drv_comm.h"
#include    "visual_comm.h"
#include    "video_dec_glb.h"
#include    "video_enc_glb.h"
#include    "video_glb.h"
#include    "video_editor.h"

// This function is only called when video_editor store file
MEDIA_STATUS_CODE video_editor_dec_put_frame_to_buffer(void)
{
   MEDIA_STATUS_CODE result;
   
   video_dbg_trace(MP4_EDT_PUT_FRAME_TO_BUFFER, video_get_current_time());
   result = video_dec_put_frame_to_buffer();
   if (result != MEDIA_STATUS_OK)
   {
      VIDEO_ASSERT(0);
      return result;
   }
   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_enc_store_file(kal_uint32 max_size, kal_uint32 *real_store_size)
{
   //Jensen
   MEDIA_STATUS_CODE result;
   video_dbg_trace(MP4_EDT_ENC_STORE_FILE, video_get_current_time());
   result = video_enc_buffer_store_file(max_size, real_store_size);
   if (result != MEDIA_STATUS_OK)
   {
      VIDEO_ASSERT(0);
      return result;
   }
   return MEDIA_STATUS_OK;
}

// This function is only called when video_editor is end!!
MEDIA_STATUS_CODE video_editor_enc_dump_to_file(kal_uint32 max_size, kal_uint32 *real_store_size)
{
   //Jensen
   MEDIA_STATUS_CODE result;
   
   video_dbg_trace(MP4_EDT_ENC_DUMP_TO_FILE, video_get_current_time());
   result = video_enc_buffer_dump_to_file(max_size, real_store_size);
   if (result != MEDIA_STATUS_OK)
   {
      VIDEO_ASSERT(0);
      return result;
   }
   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_meta_store_file(kal_uint32 max_size, kal_uint32 *real_store_size)
{
   MEDIA_STATUS_CODE result;
   
   video_dbg_trace(MP4_EDT_META_STORE_FILE, video_get_current_time());
   result = meta_enc_buffer_store_file(max_size,real_store_size);
   if (result != MEDIA_STATUS_OK)
   {
      VIDEO_ASSERT(0);
      return result;
   }
   return MEDIA_STATUS_OK;
}
#else /*!__VIDEO_EDITOR__*/
#include    "drv_comm.h"
#endif   /*__VIDEO_EDITOR__*/
