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
 * Filename:
 * ---------
 *  gdd_main.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Command executor.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
* $ Log $
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDC_INCLUDE_H_
#define _GDC_INCLUDE_H_

#if (defined(MT6205B) || ((defined(MT6223)|| defined(MT6223P)) && defined(LOW_COST_SUPPORT)))
    #if !defined(__MMI_FILE_MANAGER__) && !defined(__MMI_IMAGE_VIEWER__) && !defined(__MMI_PICT_BRIDGE_SUPPORT__)
        #define GDC_MAX_JOB             2
    #endif
#endif

#if !defined(GDC_MAX_JOB)
    #define GDC_MAX_JOB             16
#endif

extern kal_taskid gdc_thread_id;
extern void gdc_job_set_parameter(
                            gdc_job_flag_enum job_flag,
                            S32 anim_count,
                            void (*anim_before_frame_callback)(GDI_RESULT result,gdi_handle handle),
                            void (*anim_after_frame_callback)(GDI_RESULT result,gdi_handle handle),
                            void (*anim_last_frame_callback)(GDI_RESULT result),
                            void (*done_callback)(GDI_RESULT result,gdi_handle handle));

extern GDI_RESULT gdc_job_add_image(
                            gdi_image_src_enum src_type,
                            U8 *img_src,
                            U8 img_type,
                            S32 img_size,
                            S32 x,
                            S32 y,
                            S32 w,
                            S32 h,
                            U32 img_flag,
                            U32 frame_pos,
                            gdc_job_flag_enum job_flag,
                            gdi_handle *job_handle);

extern GDI_RESULT gdc_job_del_all(void);
extern GDI_RESULT gdc_job_del_image(gdi_handle job_handle);
extern void gdc_msg_send_callback_req(void* callback,GDI_RESULT result, gdi_handle handle);
extern void gdc_msg_dispatch(void *data);

#endif /* _GDC_INCLUDE_H_ */ 


