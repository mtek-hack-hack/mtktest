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
 *   kal_debug_nucleus.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#if !defined(_KAL_DEBUG_NUCLEUS_H)
#define  _KAL_DEBUG_NUCLEUS_H

#if defined(KAL_ON_NUCLEUS)

/*************************************************************************
 * Macros Without Parameters
 *************************************************************************/
#define KAL_HEAD_PRINT_SIZE            4
#define KAL_FOOT_PRINT_SIZE            4
#define KAL_TASKID_PTR_SIZE            4
#define KAL_POOLID_PTR_SIZE            4

#define KAL_BUFF_HEADER_SIZE           (KAL_HEAD_PRINT_SIZE\
                                     + KAL_TASKID_PTR_SIZE\
                                     + KAL_POOLID_PTR_SIZE)

#define KAL_BUFF_FOOTER_SIZE           KAL_FOOT_PRINT_SIZE

#define KAL_TASKID_OFFSET              4
#define KAL_POOLID_OFFSET              8

#define KAL_GET_TASKID_PTR_IN_BUFF_HEADER(buf_ptr) ((kal_char*)buf_ptr-KAL_POOLID_PTR_SIZE-KAL_TASKID_PTR_SIZE)
#define KAL_GET_POOLID_PTR_IN_BUFF_HEADER(buf_ptr) ((kal_char*)buf_ptr-KAL_POOLID_PTR_SIZE)


/*************************************************************************
 * Define exported function prototype
 *************************************************************************/

#if defined(DEBUG_KAL)

extern void kal_update_buff_footer(void *buff_ptr, kal_uint32 buff_size);

#if defined(DEBUG_BUF)
extern void kal_update_buff_header(void *buff_ptr, kal_taskid ext_task_id, kal_poolid ext_pool_id);
extern void kal_is_valid_buffer(void* buff_ptr, kal_bool *status);
#endif  /* DEBUG_BUF */

#endif  /* DEBUG_KAL */


#endif /* KAL_ON_NUCLEUS */

#endif /* _KAL_DEBUG_NUCLEUS_H */

