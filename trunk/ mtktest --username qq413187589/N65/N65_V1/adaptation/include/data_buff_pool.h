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
 *   ctrl_buff_pool.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This files defines macros to get/release data buffer from pool
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

#ifndef _DATA_BUFF_POOL_H
#define _DATA_BUFF_POOL_H

/*******************************************************************************
 * Macros With Parameters
 *******************************************************************************/
#ifdef __EGPRS_MODE__
 #define DATA_BUFF_POOL_SIZE_RLCBLK     		(75 + 3)    /* add rlc dl header length */
 #else
 #define DATA_BUFF_POOL_SIZE_RLCBLK     		(56 + 3)    /* add rlc dl header length */
#endif
/* #define NUM_DATA_BUFF_UPLINK_SIZE_RLCBLK 	72 */
#ifdef __EGPRS_MODE__
/*Simon20060117: since max ws is 512, 511 is not enough when the VQ is alwayse not recieved
 . and there should be more margin when mpal allocates buffer, so should be 512+4(margin), and
 the split block case needs margin as well*/
#define NUM_DATA_BUFF_DOWNLINK_SIZE_RLCBLK 	512+4//511  //512-1 //512+63  //window size + max pud size/MCS1
#else
#define NUM_DATA_BUFF_DOWNLINK_SIZE_RLCBLK 	127
#endif
typedef enum {
   RLC_DATA_UP,
   RLC_DATA_DOWN,
   RLC_DATA_INVALID_DIR
} rlc_data_dir;

extern void kal_release_data_buffer_r(void * buff_pt);
   
#if defined(DEBUG_KAL) && defined(DEBUG_BUF)

#define get_data_buffer(size, dir) get_int_data_buffer(size, dir, __FILE__, __LINE__)

#if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR)
#define free_data_buffer(ptr) FREE_BUFFER(ptr, __FILE__, __LINE__)   
#else   /* MTK_KAL_MNT || KAL_ON_OSCAR */
#define free_data_buffer(ptr) kal_release_data_buffer_r(ptr)
#endif   /* MTK_KAL_MNT || KAL_ON_OSCAR*/

#else   /* DEBUG_KAL && DEBUG_BUF */

#define get_data_buffer(size, dir) get_int_data_buffer(size, dir, NULL, 0)

#if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR)
#define free_data_buffer(ptr) FREE_BUFFER(ptr, __FILE__, __LINE__)
#else   /* MTK_KAL_MNT || KAL_ON_OSCAR */
#define free_data_buffer(ptr) kal_release_data_buffer_r(ptr)   
#endif   /* MTK_KAL_MNT || KAL_ON_OSCAR */

#endif   /* DEBUG_KAL && DEBUG_BUF */

/*******************************************************************************
 * Function Declaration
 *******************************************************************************/
void stack_init_data_buff_pool_info(void);

extern kal_bool stack_create_data_buff_pools(void);

#ifdef __ROMSA_SUPPORT__
void* get_int_data_buffer(kal_uint16 buff_size, rlc_data_dir dir, kal_char* file_name, kal_uint32 line);
#else
void* get_int_data_buffer(kal_uint32 buff_size, rlc_data_dir dir, kal_char* file_name, kal_uint32 line);
#endif

#endif /* _DATA_BUFF_POOL_H */

