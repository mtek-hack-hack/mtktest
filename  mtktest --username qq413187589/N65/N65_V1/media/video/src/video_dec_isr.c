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
 *   video_dec_isr.c
 *
 * Project:
 * --------
 *		MT6218B and MT6219
 *
 * Description:
 * ------------
 *   This file defines the isr handler when mpeg4 decode.
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
 * removed!
 ****************************************************************************/
#ifdef MP4_CODEC
#include "drv_comm.h"
#include "med_status.h"
#include "visual_comm.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "l1audio.h"
#include "lcd_if.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "bmd.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"
#include "stack_common.h"
#include "syscomp_config.h" /*MOD_BMT*/
#include "stack_msgs.h"
#include "app_ltlcom.h"     /* Task message communiction */
#include "stacklib.h"       /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"     /* Event scheduler */
#include "stack_timer.h"    /*Timer*/
#include "app_buff_alloc.h" /*buffer*/
#include "task_config.h"    /* Task creation */
#include "stack_ltlcom.h"   /*msg_send_ext_queue.....definitions*/

#include "video_hw.h"
#include "intrCtrl.h"
#include "visualhisr.h"
#include "gpt_sw.h"


/* Init and set seek LISR and HISR functions 
 * @param None.   
 * @return None                                                        
 */
void video_set_seek_isr(DECODE_TYPE decode_type)
{
    kal_uint32 savedMask;

    if((decode_type == DECODE_TYPE_MPEG4) || (decode_type == DECODE_TYPE_H263))  
    {
        savedMask = SaveAndSetIRQMask();
    #ifdef DRV_MP4_V1
        IRQMask(IRQ_MPEG4_CODE); 
    #else  /*!DRV_MP4_V1*/
        IRQMask(IRQ_MPEG4_DEC_CODE);
    #endif /*DRV_MP4_V1*/
        RestoreIRQMask(savedMask);
    
        //savedMask = SaveAndSetIRQMask();

        mpeg4_dec_init_isr_param();
        g_mpeg4_dec_info_ptr->dec_state = MPEG4_DEC_STATE_SEEK;
    #ifdef MP4_MOVE_LISR_TO_HISR     
        VISUAL_Register_HISR(VISUAL_MPEG4_SEEK_FIRST_HISR_ID, mpeg4_dec_seek_first_HISR);
    #endif           
        VISUAL_Register_HISR(VISUAL_MP4_SEEK_HISR_ID, mpeg4_dec_seek_HISR);
    #ifdef DRV_MP4_V1
        IRQ_Register_LISR(IRQ_MPEG4_CODE, mpeg4_dec_seek_LISR, "MPEG4Seek");
        IRQSensitivity(IRQ_MPEG4_CODE, LEVEL_SENSITIVE);
        IRQUnmask(IRQ_MPEG4_CODE);
    #else /*!DRV_MP4_V1*/
        IRQ_Register_LISR(IRQ_MPEG4_DEC_CODE, mpeg4_dec_seek_LISR, "MPEG4Seek");
        IRQSensitivity(IRQ_MPEG4_DEC_CODE, LEVEL_SENSITIVE);
        IRQUnmask(IRQ_MPEG4_DEC_CODE);
    #endif /*DRV_MP4_V1*/

        //RestoreIRQMask(savedMask);
    }
}


/* Init and set decode LISR and HISR functions 
 * @param None.   
 * @return None                                                        
 */
void video_set_dec_isr(DECODE_TYPE decode_type)
{
    kal_uint32 savedMask;
    
    if((decode_type == DECODE_TYPE_MPEG4) || (decode_type == DECODE_TYPE_H263))  
    {
        savedMask = SaveAndSetIRQMask();
    #ifdef DRV_MP4_V1
        IRQMask(IRQ_MPEG4_CODE); 
    #else  /*!DRV_MP4_V1*/
        IRQMask(IRQ_MPEG4_DEC_CODE);
    #endif /*DRV_MP4_V1*/
        RestoreIRQMask(savedMask);
    
        //savedMask = SaveAndSetIRQMask();

        mpeg4_dec_init_isr_param();
        g_mpeg4_dec_info_ptr->dec_state = MPEG4_DEC_STATE_NORMAL;
    #ifdef MP4_MOVE_LISR_TO_HISR
        VISUAL_Register_HISR(VISUAL_MPEG4_DEC_FIRST_HISR_ID, mpeg4_dec_first_HISR);
    #endif
        VISUAL_Register_HISR(VISUAL_MPEG4_DEC_HISR_ID, mpeg4_dec_HISR);
        //video_dec_set_enable_av_callback(mpeg4_dec_LISR);

        //RestoreIRQMask(savedMask);
    }
}


/* Init and enable decode LISR function
 * @param None.   
 * @return None                                                        
 */
void video_enable_dec_isr(DECODE_TYPE decode_type)
{
    if((decode_type == DECODE_TYPE_MPEG4) || (decode_type == DECODE_TYPE_H263))  
    {
        video_dec_set_enable_av_callback(mpeg4_dec_LISR);
    }
}


/* Disable decode interrupt  
 * @param None.   
 * @return None                                                        
 */
void video_dec_disable_irq(DECODE_TYPE decode_type)
{
    kal_uint32 savedMask;
    
    if((decode_type == DECODE_TYPE_MPEG4) || (decode_type == DECODE_TYPE_H263))  
    {
        savedMask = SaveAndSetIRQMask();
    #ifdef DRV_MP4_V1
        IRQMask(IRQ_MPEG4_CODE); 
    #else  /*!DRV_MP4_V1*/
        IRQMask(IRQ_MPEG4_DEC_CODE);
    #endif /*DRV_MP4_V1*/

        if(g_mpeg4_dec_isr_param.gpt_exception_protect_handle!=0)
            g_mpeg4_dec_isr_param.b_gpt_active = KAL_FALSE;
        RestoreIRQMask(savedMask);

       if(g_mpeg4_dec_isr_param.gpt_exception_protect_handle!=0)
            GPTI_StopItem(g_mpeg4_dec_isr_param.gpt_exception_protect_handle);

        //video_dec_stop_av();
        video_dec_set_av_callback(NULL);
    }
}

#else  /*MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
