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
 *   app_buff_alloc.h
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

#ifndef _APP_BUFF_ALLOC_H
#define _APP_BUFF_ALLOC_H

/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "stack_internal_macros.h"

/*************************************************************************
 * External function
 *************************************************************************/
#ifdef __ROMSA_SUPPORT__
extern void *get_int_ctrl_buffer(kal_uint16 size, kal_char* file_name, kal_uint32 line);
#else 
extern void *get_int_ctrl_buffer(kal_uint32 size, kal_char* file_name, kal_uint32 line);
#endif

/*************************************************************************
* FUNCTION
*  get_ctrl_buffer
*
* DESCRIPTION
*     The function allocates a buffer from control buffer pool greater than
*  or equal to the parameter 'size'. If function fails to allocate a buffer
*  from control buffer pool, stack reset results. This function should be
*  used if the paramter 'size' is not a compile time constant.
*
* PARAMETERS
*   size: Number of bytes to be allocated from control buffer pool
*
* RETURNS
*  A valid pointer on success. Does not return on failure.
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_BUF)
#define get_ctrl_buffer(size) get_int_ctrl_buffer(size, __FILE__, __LINE__)
#else   /* DEBUG_KAL && DEBUG_BUF */
#define get_ctrl_buffer(size) get_int_ctrl_buffer(size, NULL, 0)
#endif   /* DEBUG_KAL && DEBUG_BUF */


/*************************************************************************
* FUNCTION
*  free_ctrl_buffer
*
* DESCRIPTION
*     The function frees a pointer allocated from the control buffer pool.
*
* PARAMETERS
*   ptr : Pointer to be freed.
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#define free_ctrl_buffer(ptr) FREE_BUFFER(ptr, __FILE__, __LINE__)

#endif /* _APP_BUFF_ALLOC_H */

