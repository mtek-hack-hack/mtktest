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
 * mempoolcontainer.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements memry pool realted functions
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
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : MemPoolContainer.c

   PURPOSE     : Container for various memory Pools

   REMARKS     :  Manages the various memory pools and tries to keep a contiguous
               range of pools
   AUTHOR      : Vikram

   DATE     : 

**************************************************************/
/**************************************************************/

/***********  Include: MMI header file **************/
#include "MMI_include.h"
#include "MemPoolContainerProt.h"
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable (Local to this file - static)
*****************************************************************************/

/***************************************************************************** 
* Local Function (local to this file - static)
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_create_container
 * DESCRIPTION
 *  Create memory container to use
 * PARAMETERS
 *  num_pool                [IN]        Number of memory pool
 *  unit_per_pool           [IN]        Number of memory unit per pool
 *  buffer                  [IN]        Address point to whole pool
 *  unit_size               [IN]        Size of each memory unit
 *  mem_pool_container      [OUT]       Address point to the container to be initialized
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_create_container(
        S16 num_pool,
        S16 unit_per_pool,
        void *buffer,
        S16 unit_size,
        mem_pool_container_struct *mem_pool_container)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize pool container */
    mem_pool_container->num_pool = num_pool;
    mem_pool_container->unit_per_pool = unit_per_pool;
    mem_pool_container->num_used_pool = 0;
    mem_pool_container->pBuffer = buffer;
    mem_pool_container->unit_size = unit_size;

    /* why +1 ? keep a buffer for memory shifting */
    mem_pool_container->mem_pools = (mem_pool_struct*) OslMalloc(sizeof(mem_pool_struct) * (num_pool + 1));

    for (i = 0; i < num_pool + 1; ++i)
    {
        mem_pool_container->mem_pools[i].nMinId = -1;
        mem_pool_container->mem_pools[i].nMaxId = -1;
        mem_pool_container->mem_pools[i].unit_list = (void **)OslMalloc(sizeof(S8*) * unit_per_pool);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_destroy_container
 * DESCRIPTION
 *  Destory a memory pool container
 * PARAMETERS
 *  mem_pool_container      [IN]        Container to be destroyed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_destroy_container(mem_pool_container_struct *mem_pool_container)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mem_pool_container->mem_pools)
    {
        for (i = 0; i < mem_pool_container->num_pool + 1; ++i)
        {
            OslMfree(mem_pool_container->mem_pools[i].unit_list);
        }

        OslMfree(mem_pool_container->mem_pools);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_insert_pool
 * DESCRIPTION
 *  Insert a memory pool into container
 * PARAMETERS
 *  mem_pool_container      [IN]        Container to insert
 *  mem_pool                [IN]        Memory pool to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_insert_pool(mem_pool_container_struct *mem_pool_container, mem_pool_struct *mem_pool)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nIndex;
    S32 nTemp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nIndex = mmi_mem_get_free_pool(mem_pool_container, mem_pool);

    mem_pool_container->mem_pools[nIndex].nMaxId = mem_pool->nMaxId;
    mem_pool_container->mem_pools[nIndex].nMinId = mem_pool->nMinId;

    /* copy list of unit address to memory pool */
    memcpy(
        (S8 **) (mem_pool_container->mem_pools[nIndex].unit_list),
        (S8 **) (mem_pool->unit_list),
        (mem_pool_container->unit_per_pool * sizeof(S8 **)));

    if (nIndex > 0)
    {
        /* If the pool returned is the first pool then no need to move the data up. Leave the last pool e28t? */
        if (mem_pool_container->num_used_pool >= mem_pool_container->num_pool)
        {
            nTemp = nIndex - 1;
            if (mem_pool->nMinId > mem_pool_container->mem_pools[0].nMaxId + 1) /* Delete the 0th Data only if u do not require it. Else remove the last one */
            {
                for (nTemp = 0; nTemp < mem_pool_container->num_pool; ++nTemp)
                {
                    mem_pool_container->mem_pools[nTemp].nMaxId = mem_pool_container->mem_pools[nTemp + 1].nMaxId;
                    mem_pool_container->mem_pools[nTemp].nMinId = mem_pool_container->mem_pools[nTemp + 1].nMinId;
                    memcpy(
                        (S8 **) (mem_pool_container->mem_pools[nTemp].unit_list),
                        (S8 **) (mem_pool_container->mem_pools[nTemp + 1].unit_list),
                        (mem_pool_container->unit_per_pool * sizeof(S8 **)));
                }
            }
        }
    }

    if (mem_pool_container->num_used_pool < mem_pool_container->num_pool)
    {
        ++mem_pool_container->num_used_pool;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_delete_pool
 * DESCRIPTION
 *  Delete a memory pool from container
 * PARAMETERS
 *  mem_pool_container      [IN]        Container to delete
 *  nMinId                  [IN]        Min id of memory pool to be deleted
 *  nMaxId                  [IN]        Max id of memory pool to be deleted
 * RETURNS
 *  TRUE means delete success; FALSE means delete failure
 *****************************************************************************/
BOOL mmi_mem_delete_pool(mem_pool_container_struct *mem_pool_container, S32 nMinId, S32 nMaxId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nCount = 0;
    S32 nToCopy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* copy/shift memory pool down and insert current pool into best position */
	while(nCount < mem_pool_container->num_used_pool)
	{
		if(mem_pool_container->mem_pools[nCount].nMinId == nMinId && mem_pool_container->mem_pools[nCount].nMaxId == nMaxId)
		{
			if(nCount != (mem_pool_container->num_used_pool - 1))
			{
				nToCopy = nCount + 1;
				while (nCount < (mem_pool_container->num_used_pool - 1))
				{
					mem_pool_container->mem_pools[nCount].nMaxId = mem_pool_container->mem_pools[nToCopy].nMaxId;
					mem_pool_container->mem_pools[nCount].nMinId = mem_pool_container->mem_pools[nToCopy].nMinId;
					memcpy(
						(S8**)(mem_pool_container->mem_pools[nCount].unit_list),
						(S8**)(mem_pool_container->mem_pools[nToCopy].unit_list),
						(mem_pool_container->unit_per_pool * sizeof(S8**)));
					++nCount;
					++nToCopy;
				}
			}
			--mem_pool_container->num_used_pool;
			return TRUE;
		}
		++nCount;
	}

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_get_free_pool
 * DESCRIPTION
 *  Get a free/appropriate position for new interting pool
 * PARAMETERS
 *  mem_pool_container      [OUT]       Container of memory pool
 *  mem_pools               [IN]        Memory pool to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
/* There is one extra buffer then the total pools. So all the pools are shifted one down to get the correct buffer
   The basic advantage is to remove all the checks and always get the maximum continuous data.
   Consider a case of three pools with data 12-35, 36-47, 48-59. Now if a user asks to add pool with id 1, then 
   the resulting data should be 0-11, 12-35, 36-47 instead of having 0-11, 36-47, 48-59 */
S32 mmi_mem_get_free_pool(mem_pool_container_struct *mem_pool_container, mem_pool_struct *mem_pools)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nCount = mem_pool_container->num_used_pool - 1;
    S32 nToCopy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pool is empty, return first pool */
    if (nCount < 0)
    {
        return 0;
    }

    nToCopy = nCount + 1;

    /* copy/shift memory pool down and insert current pool into best position */
    while (mem_pool_container->mem_pools[nCount].nMinId > mem_pools->nMinId && nCount >= 0)
    {
        mem_pool_container->mem_pools[nToCopy].nMaxId = mem_pool_container->mem_pools[nCount].nMaxId;
        mem_pool_container->mem_pools[nToCopy].nMinId = mem_pool_container->mem_pools[nCount].nMinId;
        memcpy(
            (S8 **) (mem_pool_container->mem_pools[nToCopy].unit_list),
            (S8 **) (mem_pool_container->mem_pools[nCount].unit_list),
            (mem_pool_container->unit_per_pool * sizeof(S8 **)));
        --nCount;
        --nToCopy;
    }

    return nToCopy;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_get_free_mem
 * DESCRIPTION
 *  Get address of free memory location in read buffer of memory units
 * PARAMETERS
 *  mem_pool_container      [OUT]       Container of memory pool
 *  mem_pools               [IN]        Memory pool to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_mem_get_free_mem(mem_pool_container_struct *mem_pool_container, mem_pool_struct *mem_pools)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nCount = mem_pool_container->num_used_pool - 1;
    S32 nToCopy;
    S32 nTemp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mem_pool_container->num_used_pool < mem_pool_container->num_pool)
    {
        nToCopy = mem_pool_container->num_used_pool;
    }
    else
    {
        nToCopy = nCount + 1;
        while (mem_pool_container->mem_pools[nCount].nMinId > mem_pools->nMinId && nCount >= 0)
        {
            --nCount;
            --nToCopy;
        }

        if (nToCopy > 0)    /* If finally we plan to use a buffer greater then the first buffer */
        {
            if (mem_pools->nMinId > mem_pool_container->mem_pools[0].nMaxId + 1)        /* Delete the 0th Data only if u do not require it. Else remove the last one */
            {
                /* This means the index is 0 that will be freed. Return the buffer pointed by the zero index pool */
                return (S8*) mem_pool_container->mem_pools[0].unit_list[0];
            }
            else
            {
                return (S8*) mem_pool_container->mem_pools[mem_pool_container->num_used_pool - 1].unit_list[0];
            }
        }
        else
        {
            return (S8*) mem_pool_container->mem_pools[mem_pool_container->num_used_pool - 1].unit_list[0];
        }
    }

    nTemp = nToCopy * mem_pool_container->unit_size * mem_pool_container->unit_per_pool;

    return ((S8*) (mem_pool_container->pBuffer) + nTemp);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_get_values
 * DESCRIPTION
 *  Retrieve real body of memory pool units if available
 * PARAMETERS
 *  mem_pool_container      [IN]        Container of memory pool
 *  nMinId                  [IN]        Min boundary of searching
 *  nMaxId                  [IN]        Max boundary of searching
 *  pValueList              [OUT]       Buffer to store search result
 *  pNotAvailPool           [OUT]       E28t?
 * RETURNS
 *  void
 *****************************************************************************/
mmi_mem_pool_ret_enum mmi_mem_get_values(
                        mem_pool_container_struct *mem_pool_container,
                        S16 nMinId,
                        S16 nMaxId,
                        void **pValueList,
                        S16 *pNotAvailPool)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nSearchId = nMinId;
    S16 nIndex;
    S16 n_units_found = 0;  /* number of units found */
    S16 nStrtIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((nIndex = mmi_mem_search_unit(mem_pool_container, nSearchId)) >= 0)
    {
        nStrtIndex = nSearchId - mem_pool_container->mem_pools[nIndex].nMinId;
        if (nMaxId <= mem_pool_container->mem_pools[nIndex].nMaxId)
        {
            memcpy(
                ((S8 **) (pValueList) + n_units_found),
                ((S8 **) (mem_pool_container->mem_pools[nIndex].unit_list) + nStrtIndex),
                (nMaxId - nSearchId + 1) * sizeof(S8 **));

            n_units_found += (nMaxId - nSearchId + 1);
        }
        else
        {
            memcpy(
                ((S8 **) (pValueList) + n_units_found),
                ((S8 **) (mem_pool_container->mem_pools[nIndex].unit_list) + nStrtIndex),
                (mem_pool_container->mem_pools[nIndex].nMaxId - nSearchId + 1) * sizeof(S8 **));
            n_units_found += (mem_pool_container->mem_pools[nIndex].nMaxId - nSearchId + 1);
        }

        if (n_units_found == nMaxId - nMinId + 1)   /* number of units found equals to num of units required */
        {
            return MEM_CT_SUCCESS;
        }
        else
        {
            nSearchId = mem_pool_container->mem_pools[nIndex].nMaxId + 1;       /* search next index */
        }
    }

    *pNotAvailPool = (nSearchId) / mem_pool_container->unit_per_pool;   /* index of not available pool */
    return MEM_CT_POOL_NOT_AVAILABLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_search_unit
 * DESCRIPTION
 *  Search memory pool index in which a unit locates
 * PARAMETERS
 *  mem_pool_container      [IN]        Container of memory pool
 *  nId                     [IN]        Index of the unit
 * RETURNS
 *  Index of pool if found; otherwisre, (-1)
 *****************************************************************************/
S32 mmi_mem_search_unit(mem_pool_container_struct *mem_pool_container, S16 nId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mem_pool_container->num_used_pool; ++i)
        if (nId >= mem_pool_container->mem_pools[i].nMinId && nId <= mem_pool_container->mem_pools[i].nMaxId)
        {
            return i;
        }

    return (-1);
}

