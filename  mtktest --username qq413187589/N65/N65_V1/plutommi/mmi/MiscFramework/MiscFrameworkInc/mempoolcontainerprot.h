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
 * mempoolcontainerprot.h.
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines prototypes for memry pool realted functions
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
/**
 * Copyright Notice
 * ?2003 - 2004, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : MemPoolContainerProt.h

   PURPOSE     : Function & structure declarations for MemPoolContainer

   REMARKS     : nil

   AUTHOR      : Vikram

   DATE     : 

**************************************************************/
#ifndef _MMI_MEM_POOL_CONT_PROT_H
#define _MMI_MEM_POOL_CONT_PROT_H

#include "MMIDataType.h"

/***************************************************************************** 
* Define
*****************************************************************************/
typedef enum
{
    MEM_CT_SUCCESS,
    MEM_CT_FAILURE,
    MEM_CT_FREE_POOL_ALLOC_ERROR,
    MEM_CT_NO_POOL_MEM_AVAIL,
    MEM_CT_POOL_NOT_AVAILABLE
} mmi_mem_pool_ret_enum;

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    S16 nMinId;
    S16 nMaxId;
    void **unit_list;
} mem_pool_struct;

typedef struct
{
    mem_pool_struct *mem_pools;
    S32 num_used_pool;  /* number of used pool */
    S32 unit_size;      /* size of each unit */
    void *pBuffer;      /* pointer to whole memory pool */
    S16 num_pool;       /* number of pool */
    S16 unit_per_pool;  /* number of units per pool */
} mem_pool_container_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern void mmi_mem_insert_pool(mem_pool_container_struct *mem_pool_container, mem_pool_struct *mem_pools);
extern void mmi_mem_create_container(
                S16 num_pool,
                S16 unit_per_pool,
                void *p_buff,
                S16 unit_size,
                mem_pool_container_struct *mem_pool_container);
extern void mmi_mem_destroy_container(mem_pool_container_struct *mem_pool_container);
extern S32 mmi_mem_get_free_pool(mem_pool_container_struct *mem_pool_container, mem_pool_struct *mem_pools);
extern mmi_mem_pool_ret_enum mmi_mem_get_values(
                                mem_pool_container_struct *mem_pool_container,
                                S16 nMinId,
                                S16 nMaxId,
                                void **pValueList,
                                S16 *pNotAvailPool);
extern S32 mmi_mem_search_unit(mem_pool_container_struct *mem_pool_container, S16 nId);
extern void *mmi_mem_get_free_mem(mem_pool_container_struct *mem_pool_container, mem_pool_struct *mem_pools);
extern BOOL mmi_mem_delete_pool(mem_pool_container_struct *mem_pool_container, S32 nMinId, S32 nMaxId);

#endif /* _MMI_MEM_POOL_CONT_PROT_H */ 

