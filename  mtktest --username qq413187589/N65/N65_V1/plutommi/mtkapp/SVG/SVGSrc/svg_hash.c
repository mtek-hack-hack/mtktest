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
 *  svg
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SVG tiny basic library
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"
#if defined(SVG_SUPPORT)


#include "svg_internal.h"


/*****************************************************************************
 * FUNCTION
 *  svg_hash_raw_hash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [?]         
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
__inline U32 svg_hash_raw_hash(U8 *s, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        i = 31 * i + *s;
        s++;
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  svg_hash_raw_cmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s1          [?]         
 *  s1_len      [IN]        
 *  s2          [?]         
 *  s2_len      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
__inline S32 svg_hash_raw_cmp(U8 *s1, U32 s1_len, U8 *s2, U32 s2_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, cmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmp = s1_len - s2_len;
    if (cmp)
    {
        return cmp;
    }

    i = s1_len;
    while (i--)
    {
        cmp = *s1 - *s2;
        if (cmp)
        {
            return cmp;
        }
        s1++, s2++;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  svg_hash_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  table_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_hash_t *svg_hash_create(U32 table_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_hash_t *hash = (svg_hash_t*) svg_mem_malloc(sizeof(svg_hash_t));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hash)
    {
        return NULL;
    }

    hash->table_size = table_size;
    hash->table = (svg_hash_node_t **) svg_mem_malloc(sizeof(svg_hash_node_t*) * table_size);
    if (!hash->table)
    {
        return NULL;
    }

    memset(hash->table, 0, sizeof(svg_hash_node_t*) * table_size);

    return hash;
}


/*****************************************************************************
 * FUNCTION
 *  svg_hash_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_hash_free(svg_hash_t *hash)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < hash->table_size; i++)
        if (hash->table[i])
        {
            svg_hash_node_t *node, *next;

            next = hash->table[i];
            do
            {
                node = next;
                next = node->next;

                if (node->key)
                {
                    svg_mem_free(node->key);
                }
                svg_mem_free(node);
            } while (next);
        }
    svg_mem_free(hash->table);
    svg_mem_free(hash);
}


/*****************************************************************************
 * FUNCTION
 *  svg_hash_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash        [?]         
 *  key         [?]         
 *  data        [?]         
 *  ret_key     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_hash_add(svg_hash_t *hash, U8 *key, void *data, U8 **ret_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len = STRLEN(key) + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return svg_hash_add_raw(hash, key, len, data, ret_key, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  svg_hash_add_raw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash            [?]         
 *  key             [?]         
 *  key_len         [IN]        
 *  data            [?]         
 *  ret_key         [IN]        
 *  ret_key_len     [?]         
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_hash_add_raw(svg_hash_t *hash, U8 *key, U32 key_len, void *data, U8 **ret_key, U32 *ret_key_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_hash_node_t *node, *parent;
    U32 index = svg_hash_raw_hash(key, key_len) % hash->table_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent = NULL;
    if (hash->table[index])
    {
        node = hash->table[index];
        while (node)
        {
            S32 cmp;

            cmp = svg_hash_raw_cmp(node->key, node->key_len, key, key_len);
            if (cmp < 0)
            {
                parent = node;
                node = node->next;
            }
            else if (cmp == 0)
            {
                node->data = data;

                /* return key */
                if (ret_key)
                {
                    *ret_key = node->key;
                }
                if (ret_key_len)
                {
                    *ret_key_len = node->key_len;
                }
                return SVG_HASH_REPLACE;
            }
            else
            {
                break;
            }
        }
    }

    /* insert new node */
    {
        svg_hash_node_t *new_node = (svg_hash_node_t*) svg_mem_malloc(sizeof(svg_hash_node_t));

        if (!new_node)
        {
            return SVG_FAIL_NO_MEMORY;
        }

        new_node->key = svg_mem_malloc(key_len);
        if (!new_node->key)
        {
            return SVG_FAIL_NO_MEMORY;
        }

        memcpy(new_node->key, key, key_len);
        new_node->key_len = key_len;

        new_node->data = data;

        /* insert to current position */
        if (parent == NULL)
        {
            new_node->next = hash->table[index];
            hash->table[index] = new_node;
        }
        else
        {
            new_node->next = parent->next;
            parent->next = new_node;
        }

        /* return key */
        if (ret_key)
        {
            *ret_key = new_node->key;
        }
        if (ret_key_len)
        {
            *ret_key_len = new_node->key_len;
        }

    }
    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_hash_find
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash        [?]         
 *  key         [?]         
 *  ret_key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *svg_hash_find(svg_hash_t *hash, U8 *key, U8 **ret_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len = STRLEN(key) + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return svg_hash_find_raw(hash, key, len, ret_key, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  svg_hash_find_raw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash            [?]         
 *  key             [?]         
 *  key_len         [IN]        
 *  ret_key         [IN]        
 *  ret_key_len     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void *svg_hash_find_raw(svg_hash_t *hash, U8 *key, U32 key_len, U8 **ret_key, U32 *ret_key_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = svg_hash_raw_hash(key, key_len) % hash->table_size;
    svg_hash_node_t *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hash->table[index])
    {
        node = hash->table[index];
        while (node)
        {
            S32 cmp;

            cmp = svg_hash_raw_cmp(node->key, node->key_len, key, key_len);
            if (cmp < 0)
            {
                node = node->next;
            }
            else if (cmp == 0)
            {
                if (ret_key)
                {
                    *ret_key = node->key;
                }
                if (ret_key_len)
                {
                    *ret_key_len = node->key_len;
                }
                return node->data;
            }
            else
            {
                break;
            }
        }
    }
    return NULL;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */

