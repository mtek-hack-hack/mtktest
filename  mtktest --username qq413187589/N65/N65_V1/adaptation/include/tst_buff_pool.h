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
 *   tst_buff_pool.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains tst module  buffer management routines include header file
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

#ifndef _TST_BUFF_POOL_H
#define _TST_BUFF_POOL_H

/*************************************************************************
 * Macros Without Parameters
 *************************************************************************/
#define RPS_CREATED_TST_BUFF_POOLS        12

/*************************************************************************
 * Type Definitions
 *************************************************************************/
typedef enum {
   TST_BUFF_POOL_SIZE08    = 8,
   TST_BUFF_POOL_SIZE16    = 16,
   TST_BUFF_POOL_SIZE32    = 32,
   TST_BUFF_POOL_SIZE64    = 64,
   TST_BUFF_POOL_SIZE128   = 128,
   TST_BUFF_POOL_SIZE256   = 256,
   TST_BUFF_POOL_SIZE512   = 512,
   TST_BUFF_POOL_SIZE1024  = 1024,
   TST_BUFF_POOL_SIZE2048  = 2048,
   TST_BUFF_POOL_SIZE4096  = 4096,
   TST_BUFF_POOL_SIZE8192  = 8192,
   TST_BUFF_POOL_SIZE16384 = 16384,
   TST_BUFF_POOL_SIZE32768 = 32768,
   TST_BUFF_POOL_SIZE65536 = 65536,
   TST_BUFF_POOL_MAX_BUFF_SIZE = TST_BUFF_POOL_SIZE65536
} tst_buff_pool_size;

#ifdef  __WCDMA_RAT__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__CS_SERVICE__) && defined(__PS_SERVICE__)   /* __WCDMA_RAT__ */
/* GPRS Class B Solution */
typedef enum {
   NUM_TST_BUFF_POOL_SIZE08   = 0,
   NUM_TST_BUFF_POOL_SIZE16   = 0,
   NUM_TST_BUFF_POOL_SIZE32   = 20,
   NUM_TST_BUFF_POOL_SIZE64   = 30,
   NUM_TST_BUFF_POOL_SIZE128  = 40,
   NUM_TST_BUFF_POOL_SIZE256  = 50,
   NUM_TST_BUFF_POOL_SIZE512  = 6,
   NUM_TST_BUFF_POOL_SIZE1024 = 4,
   NUM_TST_BUFF_POOL_SIZE2048 = 2,
   NUM_TST_BUFF_POOL_SIZE4096 = 0,
   NUM_TST_BUFF_POOL_SIZE8192 = 0,
   NUM_TST_BUFF_POOL_SIZE16384 =0,
   NUM_TST_BUFF_POOL_SIZE32768 =0,
   NUM_TST_BUFF_POOL_SIZE65536 =0
} tst_num_buff_pool_size;
#elif defined(__CS_SERVICE__)   /* __WCDMA_RAT__ */
/* XXX!!!. GSM only solution will be tuned after integration */
typedef enum {
   NUM_TST_BUFF_POOL_SIZE08   = 10,
   NUM_TST_BUFF_POOL_SIZE16   = 10,
   NUM_TST_BUFF_POOL_SIZE32   = 20,
   NUM_TST_BUFF_POOL_SIZE64   = 30,
   NUM_TST_BUFF_POOL_SIZE128  = 40,
   NUM_TST_BUFF_POOL_SIZE256  = 30,
   NUM_TST_BUFF_POOL_SIZE512  = 6,
   NUM_TST_BUFF_POOL_SIZE1024 = 4,
   NUM_TST_BUFF_POOL_SIZE2048 = 2,
   NUM_TST_BUFF_POOL_SIZE4096 = 0,
   NUM_TST_BUFF_POOL_SIZE8192 = 0,
   NUM_TST_BUFF_POOL_SIZE16384 =0,
   NUM_TST_BUFF_POOL_SIZE32768 =0,
   NUM_TST_BUFF_POOL_SIZE65536 =0
} tst_num_buff_pool_size;
#endif   /* __WCDMA_RAT__ */

/*************************************************************************
 * Macros With Parameters
 *************************************************************************/
/* XXX!!!. TST use free_ilm(), therefore, free_tst_buffer() must be same to
   free_ctrl_buffer() */
#define free_tst_buffer(ptr)  FREE_BUFFER(ptr, __FILE__, __LINE__)

/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_BUF)
void* get_int_tst_buffer(kal_uint32 buff_size, char* file_name, kal_uint32 line);
   #define get_tst_buffer(size)  get_int_tst_buffer(size, __FILE__, __LINE__)
#else
void* get_int_tst_buffer(kal_uint32 buff_size);
   #define get_tst_buffer(size)  get_int_tst_buffer(size)
#endif /* DEBUG_BUF */

extern void stack_init_tst_buff_pool_info(void);
extern kal_bool stack_create_tst_buff_pools(void);
extern kal_poolid get_tst_pool_id_from_buff_size(kal_uint32 buff_size);

/*************************************************************************
 * Declarations Of Exported Globals
 *************************************************************************/
extern buff_pool_info_struct tst_buff_pool_info_g[RPS_CREATED_TST_BUFF_POOLS];

#endif /* _TST_BUFF_POOL_H */


