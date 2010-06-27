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
 * med_v_global.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes global context definitions of media task.
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
 *==============================================================================
 *******************************************************************************/

#ifndef MED_V_NOT_PRESENT

#ifndef _MED_V_CONTEXT_H
#define _MED_V_CONTEXT_H

/*==== CONSTANTS ==========*/

#define VISUAL_IDLE  0
#define VISUAL_RECORD   1
#define VISUAL_PLAY     2

/* visual */
#define VIS_ENTER_STATE(_s_) (med_v_context_p->state = _s_)

#define VIS_IN_STATE(_s_) (med_v_context_p->state == _s_)

/* Media V task Context Struct */
typedef struct
{
    kal_uint16 my_mod_id;
    module_type src_mod;
    kal_uint8 state;

    stack_timer_struct base_timer;
    event_scheduler *event_scheduler_ptr;

    void *int_mem_p;
    void *ext_mem_p;

    kal_uint8 display_after_seek;
    kal_eventgrpid aud_cache_event;

#ifdef ISP_SUPPORT
    kal_uint32 intmem_start_address;    /* internal memory start address for hardware engine buffer */
    kal_uint32 intmem_size;             /* internal memory size for hardware engine buffer */
    kal_uint32 extmem_start_address;    /* external memroy start address for hardware engine buffer */
    kal_uint32 extmem_size;             /* external memory size for hardware engine buffer */

#endif /* ISP_SUPPORT */ 
    kal_wchar current_file_name[MAX_FILE_NAME_LEN]; /* file name for recording */
    kal_wchar storing_path[MAX_FILE_NAME_LEN];      /* file path for recording */
    kal_wchar storing_path2[MAX_FILE_NAME_LEN];
}
med_v_context_struct;

/*==== GLOBAL VARIABLES ============*/

/* context of media task */
extern med_v_context_struct med_v_context;
extern med_v_context_struct *med_v_context_p;

#endif /* _MED_V_CONTEXT_H */ 

#endif /* MED_V_NOT_PRESENT */ 

