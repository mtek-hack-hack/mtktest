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
 *  med_int_smalloc.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"
#include "kal_trace.h"
#include "med_global.h"
#include "med_trc.h"
#include "med_smalloc.h"

typedef struct{

    KAL_ADM_ID int_mem_pool_id;
    kal_uint32 int_mem_alloc_count;
    kal_uint32 int_mem_left_size;
}med_int_mem_struct;

med_int_mem_struct g_med_int_mem_cntx;

/*****************************************************************************
 * FUNCTION
 *  med_int_smalloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
address_t med_int_smalloc(size_type size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size == 0)
    {
        return NULL;
    }
    else
    {
        ptr = kal_adm_alloc(g_med_int_mem_cntx.int_mem_pool_id, size);

        if (ptr!=NULL)
        {
            g_med_int_mem_cntx.int_mem_alloc_count++;
            g_med_int_mem_cntx.int_mem_left_size = kal_adm_get_total_left_size(g_med_int_mem_cntx.int_mem_pool_id);
        }
        MED_MEM_INFO(MED_INT_MEM_SIZE, med_int_left_size(), size, ptr,g_med_int_mem_cntx.int_mem_alloc_count);
        return (address_t) ptr;
    }
}   /* malloc */


/*****************************************************************************
 * FUNCTION
 *  med_int_sfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_int_sfree(address_t ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    address_t old_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_ptr = ptr;
    if (ptr!=NULL)
    {
        kal_adm_free(g_med_int_mem_cntx.int_mem_pool_id, ptr);
        g_med_int_mem_cntx.int_mem_alloc_count--;
        g_med_int_mem_cntx.int_mem_left_size = kal_adm_get_total_left_size(g_med_int_mem_cntx.int_mem_pool_id);
        MED_FREE_MEM_INFO(old_ptr, g_med_int_mem_cntx.int_mem_alloc_count, med_int_left_size());
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_set_int_memory_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  memory      [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_set_int_memory_pool(address_t memory, size_type size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_med_int_mem_cntx.int_mem_pool_id = kal_adm_create(
                                            memory,
                                            size,
                                            NULL,
                                            KAL_FALSE);
    g_med_int_mem_cntx.int_mem_alloc_count = 0;
    g_med_int_mem_cntx.int_mem_left_size = size;

}


/*****************************************************************************
 * FUNCTION
 *  med_int_left_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
size_type med_int_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_med_int_mem_cntx.int_mem_left_size;
}




