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
 *   visual_comm.c
 *
 * Project:
 * --------
 *		MT6218B and MT6219
 *
 * Description:
 * ------------
 *   common memory management code for MT6218B and MT6219
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#if defined(__VIDEO_EDITOR__)
#include    "video_comm.h"
#endif	/*__VIDEO_EDITOR__*/

#if ( (defined(MULTIMEDIA_INIT_MT6217_SERIES)) || (defined(MULTIMEDIA_INIT_MT6219_SERIES))  )
//#if ( (!defined(MT6208)) && (!defined(FPGA)) && (!defined(MT6205)) && (!defined(MT6205B)) && (!defined(MT6218)) )
/*(MT6217)||(MT6218B)||(MT6219)||(MT6226)||(MT6227)||(MT6226M)||(MT6228)||(MT6229)*/

#include "visual_comm.h"
#if ( (defined(MULTIMEDIA_INIT_MT6219_SERIES)) )
//#if ( (!defined(MT6217)) && (!defined(MT6218B)) )
/*(MT6219)||(MT6226)||(MT6227)||(MT6226M)||(MT6228)||(MT6229)*/
   #include "imgproc.h"
   #include "imgdma.h"
   #include "resizer.h"
#endif   /*MULTIMEDIA_INIT_MT6219_SERIES*/

VISUAL_MEM_STRUCT visual_mem;
static kal_uint8 slp_handle;
extern void image_data_path_init(void);

void Visual_Init(void)
{
#ifndef __NO_MULTIMEDIA_FEATURE__
   visual_hisr_init();
   image_data_path_init();
#endif   /*__NO_MULTIMEDIA_FEATURE__*/
#ifdef MTK_SLEEP_ENABLE
   slp_handle = L1SM_GetHandle();
#endif   /*MTK_SLEEP_ENABLE*/
}

void extmem_init(void *start_ptr,kal_uint32 length)
{
   ASSERT( (((kal_uint32)start_ptr&0x03)==0)&&(visual_mem.ext_ram_init==KAL_FALSE) );
#if defined(__VIDEO_EDITOR__)
	video_dbg_trace(VISU_EXTMEM_INIT, video_get_current_time());
#endif	/*__VIDEO_EDITOR__*/
   visual_mem.ext_ram_start_ptr = (kal_uint32 *)start_ptr;
   visual_mem.ext_ram_total_length = length;
   visual_mem.ext_ram_index = 0;
   visual_mem.ext_ram_init = KAL_TRUE;
}

void *extmem_get_buffer(kal_uint32 size)
{
   void *ptr;
#if defined(__VIDEO_EDITOR__)
	video_dbg_trace(VISU_EXTMEM_GET_BUFFER, video_get_current_time());
#endif	/*__VIDEO_EDITOR__*/
	ptr = (void *)&visual_mem.ext_ram_start_ptr[visual_mem.ext_ram_index];
	visual_mem.ext_ram_index += ((size+3)>>2);
	if ((visual_mem.ext_ram_index*4) > visual_mem.ext_ram_total_length)
		ASSERT(0);
	return ptr;
}
/*  
 *  This function will check if exterm buffer is full when you want to allocate the size.
 *   
 *  @param  size    the size that you want to allocate
 *  @return KAL_FLASE : extmem is full
 *          KAL_TRUE: extmem is enough to work done.
 * 
 */
kal_bool extmem_is_buffer_available(kal_uint32 size)
{
#if defined(__VIDEO_EDITOR__)
    video_dbg_trace(VISU_EXTMEM_GET_BUFFER, video_get_current_time());
#endif	/*__VIDEO_EDITOR__*/
    if (((visual_mem.ext_ram_index+((size+3)>>2))*4) > visual_mem.ext_ram_total_length)
      return KAL_FALSE;
    else
      return KAL_TRUE;
}

void extmem_deinit(void)
{
#if defined(__VIDEO_EDITOR__)
	video_dbg_trace(VISU_EXTMEM_DEINIT, video_get_current_time());
#endif	/*__VIDEO_EDITOR__*/
   visual_mem.ext_ram_total_length = 0;
   visual_mem.ext_ram_init = KAL_FALSE;
}

void intmem_init(void *start_ptr,kal_uint32 length)
{
#if defined(__VIDEO_EDITOR__)
	video_dbg_trace(VISU_INTMEM_INIT, video_get_current_time());
#endif	/*__VIDEO_EDITOR__*/
   ASSERT( (((kal_uint32)start_ptr&0x03)==0)&&(visual_mem.int_ram_init==KAL_FALSE) );
   visual_mem.int_ram_start_ptr = (kal_uint32 *)start_ptr;
   visual_mem.int_ram_total_length = length;
   visual_mem.int_ram_index = 0;
   visual_mem.int_ram_init = KAL_TRUE;
}

void *intmem_get_buffer(kal_uint32 size)
{
   void *ptr;
#if defined(__VIDEO_EDITOR__)
	video_dbg_trace(VISU_INTMEM_GET_BUFFER, video_get_current_time());
#endif	/*__VIDEO_EDITOR__*/
	ptr = (void *)&visual_mem.int_ram_start_ptr[visual_mem.int_ram_index];
	visual_mem.int_ram_index += (((size+3)>>2));
	if ((visual_mem.int_ram_index*4) > visual_mem.int_ram_total_length)
		ASSERT(0);
	return ptr;
}

void intmem_deinit(void)
{
#if defined(__VIDEO_EDITOR__)
	video_dbg_trace(VISU_INTMEM_DEINIT, video_get_current_time());
#endif	/*__VIDEO_EDITOR__*/
   visual_mem.int_ram_total_length = 0;
   visual_mem.int_ram_init = KAL_FALSE;
}

void visual_disable_sleep(void)
{
   #ifdef MTK_SLEEP_ENABLE
      L1SM_SleepDisable(slp_handle);
   #endif /*MTK_SLEEP_ENABLE*/
}

void visual_enable_sleep(void)
{
   #ifdef MTK_SLEEP_ENABLE
      L1SM_SleepEnable(slp_handle);
   #endif /*MTK_SLEEP_ENABLE*/
}

#endif /* MULTIMEDIA_INIT_MT6217_SERIES, MULTIMEDIA_INIT_MT6219_SERIES */


