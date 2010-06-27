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
 *  CentralConfigAgentDocument.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA Document Manipulation Functions
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
#include "MMI_include.h"

#ifdef __MMI_CCA_SUPPORT__

/**************************************************************/
/**********************  Header Files *************************/
/**************************************************************/

#include "CentralConfigAgentGProt.h"




/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_new
 * DESCRIPTION
 *  API to create a new CCA document with root node set to hRootNode
 * PARAMETERS
 *  hRootNode    [in]
 * RETURNS
 *  constructed document handle, 0=memory full or unable to construct
 *****************************************************************************/
S32 mmi_cca_doc_new(S32 hRootNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_document_struct *doc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hRootNode)
        return 0;

    doc = mmi_cca_malloc_type(cca_document_struct);
    if (doc)
    {
        memset(doc, 0, sizeof(cca_document_struct));

        doc->doc_tree = (cca_doc_node_struct*)hRootNode;
        doc->iter_nodes_list = mmi_cca_doc_construct_iter_nodes_list(doc->doc_tree);
        if (!(doc->iter_nodes_list))
        {
            mmi_cca_mfree(doc);
            doc = 0;
        }
    }
    return (S32)doc;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_new_rootnode
 * DESCRIPTION
 *  API to create a new CCA root node
 * PARAMETERS
 *  void
 * RETURNS
 *  constructed node handle, 0=memory full
 *****************************************************************************/
S32 mmi_cca_doc_new_rootnode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_cca_doc_new_node(CCA_NS_DOCROOT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_new_node
 * DESCRIPTION
 *  API to create a new CCA node
 * PARAMETERS
 *  node_symbol     [in]
 * RETURNS
 *  constructed node handle, 0=memory full
 *****************************************************************************/
S32 mmi_cca_doc_new_node(U16 node_symbol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = mmi_cca_malloc_type(cca_doc_node_struct);
    if (node)
    {
        /* init root node's sibling / child / datalist */
        node->next = 0;
        node->parent = 0;
        node->child = 0;
        node->listchain = 0;

        /* init root node's statistic */
        node->node_id = node_symbol;
        node->num_data = 0;
        node->num_child = 0;
    }
    return (S32)node;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_doc_duplicate_node
 * DESCRIPTION
 *  API to duplicate a CCA node,
 *  Including all parameters within this node,
 *  as well as re-constructing the source's child nodes hierachy.
 *  Parent of the duplicated node will be set to 0.
 * PARAMETERS
 *  node     [in]
 * RETURNS
 *  constructed node handle, 0=memory full
 *****************************************************************************/
S32 mmi_doc_duplicate_node(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *nodedup;
    cca_doc_node_struct *nodesrc;
    cca_doc_node_struct *nodechild;
    cca_doc_node_struct *nodechilddup;
    cca_doc_node_datalist_struct *listchain;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return 0;
    nodesrc = (cca_doc_node_struct*)hNode;

    /* create new node */
    nodedup = (cca_doc_node_struct*)mmi_cca_doc_new_node(nodesrc->node_id);
    if (!nodedup)
        return 0;

    /* duplicate datalist */
    listchain = nodesrc->listchain;
    while (listchain)
    {
        /* add all data in a parameter to node */
        if (listchain->data.type == CCA_DT_INT)
            status = mmi_cca_doc_add_nodedata_ints((S32)nodedup, listchain->data.id, listchain->data.size, listchain->data.values.i);
        else    /* CCA_DT_STR */
            status = mmi_cca_doc_add_nodedata_strs((S32)nodedup, listchain->data.id, listchain->data.size, (const S8**)(listchain->data.values.s));

        /* check if mem full */
        if (status == CCA_STATUS_MEMFULL)
        {
            mmi_cca_doc_node_release(nodedup, 1);
            return 0;
        }
        ASSERT(status == CCA_STATUS_OK);

        listchain = listchain->next;
    }

    /* duplicate child nodes */
    nodechild = nodesrc->child;
    while (nodechild)
    {
        nodechilddup = (cca_doc_node_struct*)mmi_doc_duplicate_node((S32)nodechild);
        if (!nodechilddup)
        {
            mmi_cca_doc_node_release(nodedup, 1);
            return 0;
        }
        mmi_cca_doc_attach_node_to_parent((S32)nodechilddup, (S32)nodedup);
        nodechild = nodechild->next;
    }

    return (S32)nodedup;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_new_node_and_attach
 * DESCRIPTION
 *  API to create a new CCA node and attach to the specified parent node
 * PARAMETERS
 *  node_symbol     [in]
 *  hParentNode     [in]
 * RETURNS
 *  constructed node handle, 0=memory full
 *****************************************************************************/
S32 mmi_cca_doc_new_node_and_attach(U16 node_symbol, S32 hParentNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (cca_doc_node_struct*)mmi_cca_doc_new_node(node_symbol);
    if (node)
    {
        if (mmi_cca_doc_attach_node_to_parent((S32)node, hParentNode) != CCA_STATUS_OK)
        {
            mmi_cca_mfree(node);
            node = 0;
        }
    }
    return (S32)node;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_attach_node_to_parent
 * DESCRIPTION
 *  API to attach a node to the specified parent node
 * PARAMETERS
 *  hNode           [in]
 *  hParentNode     [in]
 * RETURNS
 *  CCA_STATUS_OK
 *  CCA_STATUS_FAIL
 *****************************************************************************/
cca_status_enum mmi_cca_doc_attach_node_to_parent(S32 hNode, S32 hParentNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *nodeParent;
    cca_doc_node_struct *nodeChild;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nodeParent = (cca_doc_node_struct*)hParentNode;
    nodeChild = (cca_doc_node_struct*)hNode;
    if (!nodeParent)
        return CCA_STATUS_FAIL;

    mmi_cca_doc_link_list_elem_to_last(
        (cca_generic_ptr_struct**)&(nodeParent->child),
        (cca_generic_ptr_struct*)nodeChild);

    nodeChild->parent = nodeParent;
    nodeParent->num_child++;
    
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_add_node_to_parent
 * DESCRIPTION
 *  API to add a node to the specified parent node
 *  this API will duplicate the hNode first, then attach to parent node.
 * PARAMETERS
 *  hNode           [in]
 *  hParentNode     [in]
 * RETURNS
 *  CCA_STATUS_OK
 *  CCA_STATUS_FAIL
 *  CCA_STATUS_MEMFULL
 *****************************************************************************/
cca_status_enum mmi_cca_doc_add_node_to_parent(S32 hNode, S32 hParentNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hParentNode)
        return CCA_STATUS_FAIL;

    hNode = mmi_doc_duplicate_node(hNode);
    if (!hNode)
        return CCA_STATUS_MEMFULL;

    return mmi_cca_doc_attach_node_to_parent(hNode, hParentNode);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_datalist_new
 * DESCRIPTION
 *  create a new datalist object
 * PARAMETERS
 *  param_id    [in]
 *  data_type   [in]
 * RETURNS
 *  constructed datalist or 0 if memory full
 *****************************************************************************/
cca_doc_node_datalist_struct* mmi_cca_doc_datalist_new(U16 param_id, cca_data_type_enum data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_datalist_struct *datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((datalist=mmi_cca_malloc_type(cca_doc_node_datalist_struct))!=0)
    {
        datalist->next = 0;
        datalist->data.id = param_id;
        datalist->data.size = 0;
        datalist->data.type = data_type;
        if (data_type == CCA_DT_INT)
            datalist->data.values.i = 0;
        else
            datalist->data.values.s = 0;
    }

    return datalist;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_datalist_find_ptr
 * DESCRIPTION
 *  find the matched datalist with the specified param_id
 * PARAMETERS
 *  datalist    [in]
 *  param_id    [in]
 * RETURNS
 *  function returns the datalist pointer pointing to the one containing the specified param_id
 *  datalist can be a NULL pointer, in this case, NULL pointer will be returned
 *****************************************************************************/
cca_doc_node_datalist_struct* mmi_cca_doc_datalist_find_ptr(cca_doc_node_datalist_struct *datalist, U16 param_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(datalist)
    {
        if (datalist->data.id == param_id)
            return datalist;
        datalist = datalist->next;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_datalist_has_param_value
 * DESCRIPTION
 *  check if the specified param and value pair exists in datalist
 * PARAMETERS
 *  datalist    [in]
 *  param_id    [in]
 *  datatype    [in]
 *  value       [in]    (S32 if int, S8* if str)
 * RETURNS
 *  0 if not found
 *  1 if found
 *****************************************************************************/
U8 mmi_cca_doc_datalist_has_param_value(cca_doc_node_datalist_struct *datalist, U16 param_id, cca_data_type_enum datatype, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (datalist)
    {
        if (datalist->data.id == param_id &&
            datalist->data.type == datatype &&
            ((datalist->data.type==CCA_DT_INT && mmi_cca_doc_coredata_exists_int(&(datalist->data), (S32)value)) ||
             (datalist->data.type==CCA_DT_STR && mmi_cca_doc_coredata_exists_str(&(datalist->data), (S8*)value)) ) )
        {
            return 1;
        }
        datalist = datalist->next;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_link_list_elem_to_last
 * DESCRIPTION
 *  link the element to the end of a generic list
 * PARAMETERS
 *  start    [in]
 *  elem     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_link_list_elem_to_last(cca_generic_ptr_struct **start, cca_generic_ptr_struct *elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_generic_ptr_struct *crt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(*start))
    {
        /* list is empty */
        *start = elem;
    }
    else
    {
        /* find last elem in list */
        crt = *start;
        while (crt->next)
            crt = crt->next;

        /* attach elem to end of list */
        crt->next = elem;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_datalist_attach_to_node
 * DESCRIPTION
 *  attach a datalist to a node, caller MUST ensures param associated with this datalist does not exists in node
 * PARAMETERS
 *  node        [in]
 *  datalist    [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_datalist_attach_to_node(cca_doc_node_struct* node, cca_doc_node_datalist_struct* datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node->num_data++;
    mmi_cca_doc_link_list_elem_to_last(
        (cca_generic_ptr_struct**)&(node->listchain),
        (cca_generic_ptr_struct*)datalist);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_detach_datalist
 * DESCRIPTION
 *  detach datalist object matching the param_id
 * PARAMETERS
 *  hNode       [in]
 *  param_id    [in]
 * RETURNS
 *  0 if not found
 *****************************************************************************/
cca_doc_node_datalist_struct* mmi_cca_doc_detach_datalist(cca_doc_node_struct *node, U16 param_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_datalist_struct *prev;
    cca_doc_node_datalist_struct *datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev = 0;
    datalist = node->listchain;
    while (datalist)
    {
        if (datalist->data.id == param_id)
        {
            if (!prev)
                node->listchain = datalist->next;
            else
                prev->next = datalist->next;
            datalist->next = 0;
            node->num_data--;
            return datalist;
        }
        prev = datalist;
        datalist = datalist->next;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_coredata_extend
 * DESCRIPTION
 *  pre: valid coredata obj ptr & initialised
 *  extend the size of coredata value array by the specified num_extend
 * PARAMETERS
 *  data_obj        [in]
 *  num_extend      [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_coredata_extend(cca_core_data_struct *data_obj, U32 num_extend)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *values_i;
    S8  **values_s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    values_i = 0;
    values_s = 0;
    if (data_obj->type == CCA_DT_INT)
    {
        values_i = (S32*)mmi_cca_malloc((num_extend+data_obj->size)*sizeof(S32));
        if (!values_i)
            return CCA_STATUS_MEMFULL;

        kal_mem_set(values_i, 0, (num_extend+data_obj->size)*sizeof(S32));
        if (data_obj->values.i)
        {
            kal_mem_cpy(values_i, data_obj->values.i, data_obj->size*sizeof(S32));
            mmi_cca_mfree(data_obj->values.i);
        }
        data_obj->values.i = values_i;
        data_obj->size += num_extend;
    }
    else if (data_obj->type == CCA_DT_STR)
    {
        values_s = (S8**)mmi_cca_malloc((num_extend+data_obj->size)*sizeof(S8*));
        if (!values_s)
            return CCA_STATUS_MEMFULL;

        kal_mem_set(values_s, 0, (num_extend+data_obj->size)*sizeof(S8*));
        if (data_obj->values.s)
        {
            kal_mem_cpy(values_s, data_obj->values.s, data_obj->size*sizeof(S8*));
            mmi_cca_mfree(data_obj->values.s);
        }
        data_obj->values.s = values_s;
        data_obj->size += num_extend;
    }
    else
        ASSERT(0);
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_coredata_append
 * DESCRIPTION
 *  pre: valid coredata obj ptr & initialised & coredata type matches "type" parameter
 *  append values array to the existing coredata
 * PARAMETERS
 *  data_obj        [in]
 *  values          [in]    type of values: S32* if int, S8** if str 
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_coredata_append(cca_core_data_struct *data_obj, S32 size, void *values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, offset, txtsize, absindex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cca_doc_coredata_extend(data_obj, size) == CCA_STATUS_MEMFULL)
        return CCA_STATUS_MEMFULL;

    offset = data_obj->size - size;
    if (data_obj->type == CCA_DT_INT)
    {
        kal_mem_cpy(data_obj->values.i+offset, values, size*sizeof(S32));
    }
    else
    {
        for (i=0; i<size; i++)
        {
            absindex = i+offset;
            if (((S8**)values)[i])
                txtsize = strlen((const char*)((S8**)values)[i]) + 1;
            else
                txtsize = 0;

            if (!txtsize)
            {
                data_obj->values.s[absindex] = 0;
                continue;
            }

            data_obj->values.s[absindex] = (S8*)mmi_cca_malloc(txtsize*sizeof(S8));
            if (data_obj->values.s[absindex])
            {
                data_obj->values.s[absindex][0] = 0;
                if (((S8**)values)[i])
                    kal_mem_cpy(data_obj->values.s[absindex], (void*)((S8**)values)[i], txtsize*sizeof(S8));
            }
            else
            {
                /* free all alloc string mem just then */
                i--;    /* ignore index of last elem that just malloc as alloc failed */
                while ( (i-=1)>=0 )
                    mmi_cca_mfree(data_obj->values.s[i+offset]);

                /* restore coredata size state (the extended mem slots arent freed 'cos too much troubles
                    to alloc another array with less elements and re-copy all data back in)
                    the extended mem will still be freed later on when coredata is freed */
                data_obj->size -= size;
                if (data_obj->size == 0)
                {
                    mmi_cca_mfree(data_obj->values.s);
                    data_obj->values.s = 0;
                }
                return CCA_STATUS_MEMFULL;
            }
        }
    }
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_coredata_release_values
 * DESCRIPTION
 *  free all memory occupied by the value array in coredata
 * PARAMETERS
 *  coredata        [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_coredata_release_values(cca_core_data_struct *coredata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!coredata)
        return;

    if (coredata->type == CCA_DT_INT)
    {
        if (coredata->values.i)
            mmi_cca_mfree(coredata->values.i);
        coredata->values.i = 0;
    }
    else
    {
        if (coredata->values.s)
        {
            for (i=0; i<coredata->size; i++)
                if (coredata->values.s[i])
                    mmi_cca_mfree(coredata->values.s[i]);
            mmi_cca_mfree(coredata->values.s);
            coredata->values.s = 0;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_coredata_reset
 * DESCRIPTION
 *  free all memory occupied by the value array in coredata and reset all its parameters
 * PARAMETERS
 *  coredata        [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_coredata_reset(cca_core_data_struct* coredata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!coredata)
        return;

    mmi_cca_doc_coredata_release_values(coredata);

    coredata->id = 0;
    coredata->size = 0;
    coredata->type = CCA_DT_INT;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_datalist_release
 * DESCRIPTION
 *  release all memory occupied by datalist,
 *  setting deep_delete to 1 will delete all datalist linked to it
 * PARAMETERS
 *  datalist        [in]
 *  deep_delete     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_datalist_release(cca_doc_node_datalist_struct *datalist, U8 deep_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_datalist_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (datalist)
    {
        next = datalist->next;
        if (deep_delete)
            mmi_cca_doc_coredata_release_values(&(datalist->data));
        mmi_cca_mfree(datalist);
        datalist = next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_node_release
 * DESCRIPTION
 *  release all memory occupied by this node
 * PARAMETERS
 *  node            [in]
 *  deep_delete     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_node_release(cca_doc_node_struct *node, U8 deep_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!node)
        return;

    if (deep_delete && node->listchain)
        mmi_cca_doc_datalist_release(node->listchain, 1);
    mmi_cca_mfree(node);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_nodelist_release
 * DESCRIPTION
 *  release all memory occupied by this nodelist
 *  setting deep_delete will delete all nodelist obj linked to it
 * PARAMETERS
 *  nodelist        [in]
 *  deep_delete     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_nodelist_release(cca_doc_nodelist_struct *nodelist, U8 deep_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_nodelist_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nodelist)
    {
        next = nodelist->next;
        if (deep_delete && nodelist->node)
            mmi_cca_doc_node_release(nodelist->node, 1);
        mmi_cca_mfree(nodelist);
        nodelist = next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_iter_nodes_list_release
 * DESCRIPTION
 *  release all memory occupied by this iter_nodes_list
 *  releaseLevel:
 *      0 = free each elem ptr only
 *      1 = free each elem ptr + free each nodelist elem ptr
 *      2 = free each elem ptr + free each nodelist elem ptr + free all nodes in nodelist
 * PARAMETERS
 *  iter_nodes_list     [in]
 *  releaseLevel        [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_iter_nodes_list_release(cca_doc_iter_nodes_struct *iter_nodes_list, U8 releaseLevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_iter_nodes_struct *next;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (iter_nodes_list)
    {
        next = iter_nodes_list->next;
        if (iter_nodes_list->nodes)
            mmi_cca_doc_nodelist_release(iter_nodes_list->nodes, (U8)(releaseLevel-1));
        mmi_cca_mfree(iter_nodes_list);
        iter_nodes_list = next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_node_detach
 * DESCRIPTION
 *  detach a node from its parent and sibling
 *  this API does not free the node
 * PARAMETERS
 *  hRoot     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_node_detach(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;
    cca_doc_node_struct *sibling;
    cca_doc_node_struct *parent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (cca_doc_node_struct*)hNode;
    if (!node)
        return;

    parent = node->parent;
    if (!parent)
    {
        /* if node has no parent, then it should not be connected to any sibling either */
        ASSERT(!(node->next));
        return;
    }

    sibling = parent->child;
    /* if parent's first child = specified node */
    if (sibling == node)
    {
        parent->child = node->next;
        parent->num_child--;
        node->next = 0;
        node->parent = 0;
        return;
    }

    while (sibling->next)
    {
        if (sibling->next == node)
        {
            sibling->next = node->next;
            parent->num_child--;
            node->next = 0;
            node->parent = 0;
            break;
        }
        sibling = sibling->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_node_release_all_recur
 * DESCRIPTION
 *  helper function used for mmi_cca_doc_node_release_all()
 * PARAMETERS
 *  hRoot     [in]
 * RETURNS
 *  void
 *****************************************************************************/
static void
mmi_cca_doc_node_release_all_recur(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* not memory efficient! --> too many context switches... may need to rewrite using loop approach */
    node = (cca_doc_node_struct*)hNode;
    if (!node)
        return;

    mmi_cca_doc_node_release_all_recur((S32)(node->child));
    mmi_cca_doc_node_release_all_recur((S32)(node->next));

    mmi_cca_doc_node_release(node, 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_node_release_all
 * DESCRIPTION
 *  release all memory held by this node and all its sub-nodes (ie, the entire tree)
 * PARAMETERS
 *  hRoot     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_node_release_all(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return;

    mmi_cca_doc_node_detach(hNode);
    mmi_cca_doc_node_release_all_recur(hNode);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_docroot_release
 * DESCRIPTION
 *  release all memory held by this node and all its sub-nodes (ie, the entire tree)
 * PARAMETERS
 *  hRoot     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_docroot_release(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_doc_node_release_all(hRoot);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_release
 * DESCRIPTION
 *  release all memory held by this document object
 * PARAMETERS
 *  hConfig     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_doc_release(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_document_struct *doc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (cca_document_struct*)hConfig;
    if (!doc)
        return;

    mmi_cca_docroot_release((S32)(doc->doc_tree));
    mmi_cca_doc_iter_nodes_list_release(doc->iter_nodes_list, 1);

    mmi_cca_mfree(doc);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_add_nodedata_int
 * DESCRIPTION
 *  append an int data to this node
 * PARAMETERS
 *  hNode     [in]
 *  param_id  [in]
 *  value     [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_add_nodedata_int(S32 hNode, U16 param_id, const S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;
    cca_doc_node_datalist_struct *datalist;
    U8 isNewList;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (cca_doc_node_struct*)hNode;
    datalist = mmi_cca_doc_datalist_find_ptr(node->listchain, param_id);
    isNewList = 0;

    /* retrieve datalist or create new */
    if (!datalist)
    {
        /* create a new datalist if datalist of this param cannot be found */
        datalist = mmi_cca_doc_datalist_new(param_id, CCA_DT_INT);
        if (!datalist)
            return CCA_STATUS_MEMFULL;
        isNewList = 1;
    }
    else
    {
        /* datalist of this param already exists, check existing datalist type */
        if (datalist->data.type != CCA_DT_INT)
            return CCA_STATUS_TYPE_MISMATCHED;
    }

    /* append values to end of data array */
    if (mmi_cca_doc_coredata_append(&(datalist->data), 1, (void*)&value) != CCA_STATUS_OK)
    {
        if (isNewList)
        {
            /* only needs to free datalist ptr mem as the coredata would
               have been dealloc completely if coredata_append failed */
            mmi_cca_mfree(datalist);
        }
        return CCA_STATUS_MEMFULL;
    }

    /* attach datalist to node if datalist is newly created */
    if (isNewList)
        mmi_cca_doc_datalist_attach_to_node(node, datalist);
    
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_add_nodedata_str
 * DESCRIPTION
 *  append a str data to this node
 * PARAMETERS
 *  hNode     [in]
 *  param_id  [in]
 *  value     [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_add_nodedata_str(S32 hNode, U16 param_id, const S8 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;
    cca_doc_node_datalist_struct *datalist;
    U8 isNewList;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (cca_doc_node_struct*)hNode;
    datalist = mmi_cca_doc_datalist_find_ptr(node->listchain, param_id);
    isNewList = 0;

    /* retrieve datalist or create new */
    if (!datalist)
    {
        /* create a new datalist if datalist of this param cannot be found */
        datalist = mmi_cca_doc_datalist_new(param_id, CCA_DT_STR);
        if (!datalist)
            return CCA_STATUS_MEMFULL;
        isNewList = 1;
    }
    else
    {
        /* datalist of this param already exists, check existing datalist type */
        if (datalist->data.type != CCA_DT_STR)
            return CCA_STATUS_TYPE_MISMATCHED;
    }

    /* append values to end of data array */
    if (mmi_cca_doc_coredata_append(&(datalist->data), 1, (void*)&value) != CCA_STATUS_OK)
    {
        if (isNewList)
        {
            /* only needs to free datalist ptr mem as the coredata would
               have been dealloc completely if coredata_append failed */
            mmi_cca_mfree(datalist);
        }
        return CCA_STATUS_MEMFULL;
    }

    /* attach datalist to node if datalist is newly created */
    if (isNewList)
        mmi_cca_doc_datalist_attach_to_node(node, datalist);
    
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_add_nodedata_ints
 * DESCRIPTION
 *  append all values in an int array to this node
 * PARAMETERS
 *  hNode     [in]
 *  param_id  [in]
 *  size      [in]
 *  values    [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_add_nodedata_ints(S32 hNode, U16 param_id, S32 size, const S32 *values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;
    cca_doc_node_datalist_struct *datalist;
    U8 isNewList;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (cca_doc_node_struct*)hNode;
    datalist = mmi_cca_doc_datalist_find_ptr(node->listchain, param_id);
    isNewList = 0;

    /* retrieve datalist or create new */
    if (!datalist)
    {
        /* create a new datalist if datalist of this param cannot be found */
        datalist = mmi_cca_doc_datalist_new(param_id, CCA_DT_INT);
        if (!datalist)
            return CCA_STATUS_MEMFULL;
        isNewList = 1;
    }
    else
    {
        /* datalist of this param already exists, check existing datalist type */
        if (datalist->data.type != CCA_DT_INT)
            return CCA_STATUS_TYPE_MISMATCHED;
    }

    /* append values to end of data array */
    if (mmi_cca_doc_coredata_append(&(datalist->data), size, (void*)values) != CCA_STATUS_OK)
    {
        if (isNewList)
        {
            /* only needs to free datalist ptr mem as the coredata would
               have been dealloc completely if coredata_append failed */
            mmi_cca_mfree(datalist);
        }
        return CCA_STATUS_MEMFULL;
    }

    /* attach datalist to node if datalist is newly created */
    if (isNewList)
        mmi_cca_doc_datalist_attach_to_node(node, datalist);
    
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_add_nodedata_strs
 * DESCRIPTION
 *  append all values in a str array to this node
 * PARAMETERS
 *  hNode     [in]
 *  param_id  [in]
 *  size      [in]
 *  values    [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_add_nodedata_strs(S32 hNode, U16 param_id, S32 size, const S8 **values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;
    cca_doc_node_datalist_struct *datalist;
    U8 isNewList;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (cca_doc_node_struct*)hNode;
    datalist = mmi_cca_doc_datalist_find_ptr(node->listchain, param_id);
    isNewList = 0;

    /* retrieve datalist or create new */
    if (!datalist)
    {
        /* create a new datalist if datalist of this param cannot be found */
        datalist = mmi_cca_doc_datalist_new(param_id, CCA_DT_STR);
        if (!datalist)
            return CCA_STATUS_MEMFULL;
        isNewList = 1;
    }
    else
    {
        /* datalist of this param already exists, check existing datalist type */
        if (datalist->data.type != CCA_DT_STR)
            return CCA_STATUS_TYPE_MISMATCHED;
    }

    /* append values to end of data array */
    if (mmi_cca_doc_coredata_append(&(datalist->data), size, (void*)values) != CCA_STATUS_OK)
    {
        if (isNewList)
        {
            /* only needs to free datalist ptr mem as the coredata would
               have been dealloc completely if coredata_append failed */
            mmi_cca_mfree(datalist);
        }
        return CCA_STATUS_MEMFULL;
    }

    /* attach datalist to node if datalist is newly created */
    if (isNewList)
        mmi_cca_doc_datalist_attach_to_node(node, datalist);
    
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_coredata_exists_int
 * DESCRIPTION
 *  check whether this coredata contain specified value
 * PARAMETERS
 *  coredata    [in]
 *  val         [in]
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
U8 mmi_cca_doc_coredata_exists_int(cca_core_data_struct *coredata, S32 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (coredata->type != CCA_DT_INT)
        return 0;
    return mmi_cca_doc_coredata_values_exists_int(coredata->values.i, coredata->size, val);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_coredata_values_exists_int
 * DESCRIPTION
 *  check whether this coredata contain specified value
 * PARAMETERS
 *  values_i    [in]
 *  size        [in]
 *  val         [in]
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
U8 mmi_cca_doc_coredata_values_exists_int(S32 *values_i, S32 size, S32 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ( (size-=1)>=0 )
    {
        if (values_i[size] == val)
            return 1;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_coredata_exists_str
 * DESCRIPTION
 *  check whether this coredata contain specified value
 * PARAMETERS
 *  coredata    [in]
 *  str         [in]
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
U8 mmi_cca_doc_coredata_exists_str(cca_core_data_struct *coredata, S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (coredata->type != CCA_DT_STR)
        return 0;
    return mmi_cca_doc_coredata_values_exists_str(coredata->values.s, coredata->size, str);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_coredata_values_exists_str
 * DESCRIPTION
 *  check whether this coredata contain specified value
 * PARAMETERS
 *  values_s    [in]
 *  size        [in]
 *  str         [in]
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
U8 mmi_cca_doc_coredata_values_exists_str(S8 **values_s, S32 size, S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ( (size-=1)>=0 )
    {
        if (strcmp(values_s[size], str) == 0)
            return 1;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_coredata_remove_value
 * DESCRIPTION
 *  remove value + release its memory from the coredata
 * PARAMETERS
 *  coredata    [in]
 *  type        [in]
 *  value       [in]    (S32 if int, S8* if str)
 * RETURNS
 *  0           value not removed
 *  1           value removed from coredata
 *****************************************************************************/
U8 mmi_cca_doc_coredata_remove_value(cca_core_data_struct *coredata, cca_data_type_enum type, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    U8 toRemove;
    U8 removed = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!coredata || coredata->type != type)
        return 0;

    for (i=0; i<coredata->size; i++)
    {
        toRemove = 0;
        if (type==CCA_DT_INT && coredata->values.i[i]==(S32)value)
            toRemove = 1;
        if (type==CCA_DT_STR &&
            (coredata->values.s[i]==(S8*)value || 
             (coredata->values.s[i] && value && strcmp(coredata->values.s[i], (S8*)value)==0)))
        {
            if (coredata->values.s[i])
                mmi_cca_mfree(coredata->values.s[i]);
            coredata->values.s[i] = 0;
            toRemove = 1;
        }
        if (toRemove)
        {
            for (j=i; j<coredata->size-1; j++)
            {
                if (type == CCA_DT_INT)
                    coredata->values.i[j] = coredata->values.i[j+1];
                else
                    coredata->values.s[j] = coredata->values.s[j+1];
            }
            if (type == CCA_DT_INT)
                coredata->values.i[coredata->size-1] = 0;
            else
                coredata->values.s[coredata->size-1] = 0;
            coredata->size--;
            i--;
            removed = 1;
        }
    }
    if (!(coredata->size))
    {
        if (type == CCA_DT_INT)
        {
            if (coredata->values.i)
                mmi_cca_mfree(coredata->values.i);
            coredata->values.i = 0;
        }
        else
        {
            if (coredata->values.s)
                mmi_cca_mfree(coredata->values.s);
            coredata->values.s = 0;
        }
    }
    return removed;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_remove_nodedata
 * DESCRIPTION
 *  detach + release the datalist & coredata object matching the specified param_id within this node
 * PARAMETERS
 *  hNode       [in]
 *  param_id    [in]
 * RETURNS
 *  CCA_STATUS_OK
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_INVALID_HANDLE
 *****************************************************************************/
cca_status_enum mmi_cca_doc_remove_nodedata(S32 hNode, U16 param_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_datalist_struct *datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return CCA_STATUS_INVALID_HANDLE;

    datalist = mmi_cca_doc_detach_datalist((cca_doc_node_struct*)hNode, param_id);
    if (!datalist)
        return CCA_STATUS_NOT_FOUND;

    mmi_cca_doc_datalist_release(datalist, 1);
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_iterator_fill
 * DESCRIPTION
 *  pre: valid iterator
 *  fill in iterator parameters to the already constructed iterator object
 * PARAMETERS
 *  iter        [in/out]
 *  trType      [in]
 *  itType      [in]
 *  begin       [in]
 *  dpDel       [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_iterator_fill(cca_iterator_struct *iter,
                            cca_traverse_type_enum trType,
                            cca_iter_type_enum itType,
                            cca_generic_ptr_struct* begin,
                            U8 dpDel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter->current = 0;
    iter->head_node = begin;
    iter->prev_node = 0;
    iter->traverse_type = trType;
    iter->iter_type = itType;
    iter->deep_delete = dpDel;
    iter->crt_level = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_iterator_new
 * DESCRIPTION
 *  construct a new iterator with specified parameters
 * PARAMETERS
 *  trType      [in]
 *  itType      [in]
 *  begin       [in]
 *  dpDel       [in]
 * RETURNS
 *  constructed iterator object or 0 (mem full)
 *****************************************************************************/
cca_iterator_struct* mmi_cca_iterator_new(cca_traverse_type_enum trType, cca_iter_type_enum itType, cca_generic_ptr_struct* begin, U8 dpDel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *iter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter = mmi_cca_malloc_type(cca_iterator_struct);
    if (iter)
        mmi_cca_iterator_fill(iter, trType, itType, begin, dpDel);

	return iter;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_iterator_next_preorder_node
 * DESCRIPTION
 *  performs a preorder traversal and move to next node in iterator
 * PARAMETERS
 *  iter      [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_iterator_next_preorder_node(cca_iterator_struct* iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (iter->current == 0)
		return;
	
	if (iter->current->next)
		iter->current = iter->current->next;
	else
    {
		iter->current = iter->current->parent;
        /* crt_level = -1 when all nodes/childs traversed.. ie, end of traversal */
        iter->crt_level--;
		mmi_cca_iterator_next_preorder_node(iter);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_iterator_next
 * DESCRIPTION
 *  move to next node in iterator
 * PARAMETERS
 *  iter      [in]
 * RETURNS
 *  pointed data
 *****************************************************************************/
void* mmi_cca_iterator_next(cca_iterator_struct* iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!iter)
        return 0;

	iter->prev_node = iter->current;

	if (iter->current == 0)
    {
		iter->current = iter->head_node;
        iter->crt_level = 0;
	}
    else if (iter->traverse_type == CCA_TR_LIST)
    {
		iter->current = iter->current->next;
	}
    else if (iter->traverse_type == CCA_TR_PREORDER)
    {
		if (iter->current->child)
        {
			iter->current = iter->current->child;
            iter->crt_level++;
        }
		else
			mmi_cca_iterator_next_preorder_node(iter);
	}
	
	return (void*)iter->current;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_iterator_release
 * DESCRIPTION
 *  release memory occupied by iterator only, and not its pointed data
 * PARAMETERS
 *  iter      [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_iterator_release(cca_iterator_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!iter)
        return;

    /* currently deep_delete is not considered... will be implemented in future if needed */
    mmi_cca_mfree(iter);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_iterator_restart
 * DESCRIPTION
 *  reset iterator to its begin state
 * PARAMETERS
 *  iter      [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_iterator_restart(cca_iterator_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iter)
    {
        iter->current = 0;
        iter->prev_node = 0;
        iter->crt_level = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_get_nodedata
 * DESCRIPTION
 *  retrieve the iterator to the datalist (ie, list of parameters) held in the node pointed by this iterator
 * PARAMETERS
 *  iter_nodelist   [in]
 *  iter_datalist   [out]   can be NULL pointer
 *  size            [out]   can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_ITER
 *  CCA_STATUS_ENDLIST
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_get_nodedata(cca_iterator_struct *iter_nodelist, cca_iterator_struct **iter_datalist, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iter_datalist)
        *iter_datalist = 0;
    if (size)
        *size = 0;

    if (!iter_nodelist || (iter_nodelist->iter_type!=CCA_IT_NODELIST && iter_nodelist->iter_type!=CCA_IT_NODECHAIN))
        return CCA_STATUS_INVALID_ITER;

    if (!(iter_nodelist->current))
        return CCA_STATUS_ENDLIST;

    if (iter_nodelist->iter_type==CCA_IT_NODELIST)
        node = ((cca_doc_nodelist_struct*)(iter_nodelist->current))->node;
    else
        node = (cca_doc_node_struct*)(iter_nodelist->current);

    if (!node || !(node->listchain))
        return CCA_STATUS_NOT_FOUND;

    if (iter_datalist)
    {
        *iter_datalist = mmi_cca_iterator_new(
                            CCA_TR_LIST,
                            CCA_IT_DATALIST,
                            (cca_generic_ptr_struct*)(node->listchain),
                            0);
        if (!(*iter_datalist))
            return CCA_STATUS_MEMFULL;
    }

    if (size)
        *size = node->num_data;

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_get_nodedata_by_param
 * DESCRIPTION
 *  retrieve the coredata object matching the specified param_id in the node pointed by this iterator
 * PARAMETERS
 *  iter       [in]     can be a valid nodelist iterator or a valid datalist iterator
 *  param_id   [in]
 *  data_obj   [out]
 * RETURNS
 *  CCA_STATUS_INVALID_ITER
 *  CCA_STATUS_ENDLIST
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_get_nodedata_by_param(cca_iterator_struct *iter, U16 param_id, cca_core_data_struct **data_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *iter_datalist;
    cca_status_enum status;
    cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_obj)
        *data_obj = 0;

    if (!iter)
        return CCA_STATUS_INVALID_ITER;

    if (iter->iter_type == CCA_IT_DATALIST)
    {
        iter_datalist = iter;
    }
    else if (iter->iter_type == CCA_IT_NODELIST || iter->iter_type == CCA_IT_NODECHAIN)
    {
        if (!(iter->current))
            return CCA_STATUS_ENDLIST;

        status = mmi_cca_doc_get_nodedata(iter, &iter_datalist, 0);
        if (status != CCA_STATUS_OK)
            return status;
    }
    else
        ASSERT(0);

    if (!data_obj)
    {
        if (iter->iter_type == CCA_IT_NODELIST || iter->iter_type == CCA_IT_NODECHAIN)
            mmi_cca_iterator_release(iter_datalist);
        return CCA_STATUS_OK;
    }

    mmi_cca_iterator_restart(iter_datalist);
    while(mmi_cca_iterator_next(iter_datalist))
    {
        coredata = &(((cca_doc_node_datalist_struct*)(iter_datalist->current))->data);
        if (coredata->id == param_id)
        {
            *data_obj = coredata;
            if (iter->iter_type == CCA_IT_NODELIST || iter->iter_type == CCA_IT_NODECHAIN)
                mmi_cca_iterator_release(iter_datalist);
            return CCA_STATUS_OK;
        }
    }
    if (iter->iter_type == CCA_IT_NODELIST || iter->iter_type == CCA_IT_NODECHAIN)
        mmi_cca_iterator_release(iter_datalist);
    return CCA_STATUS_NOT_FOUND;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_nodedata_by_param
 * DESCRIPTION
 *  retrieve the coredata object matching the specified param_id in the specified node
 * PARAMETERS
 *  hNode      [in]
 *  param_id   [in]
 *  data_obj   [out]    can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_nodedata_by_param(S32 hNode, U16 param_id, cca_core_data_struct **data_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_datalist_struct* datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return CCA_STATUS_INVALID_HANDLE;

    datalist = mmi_cca_doc_datalist_find_ptr(((cca_doc_node_struct*)hNode)->listchain, param_id);
    if (!datalist)
        return CCA_STATUS_NOT_FOUND;

    if (data_obj)
        *data_obj = &(datalist->data);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_nodedata_int_first
 * DESCRIPTION
 *  retrieve the first int data of the matching the specified param_id in the specified node
 * PARAMETERS
 *  hNode      [in]
 *  param_id   [in]
 *  value      [out]    can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_nodedata_int_first(S32 hNode, U16 param_id, S32 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct* coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return CCA_STATUS_INVALID_HANDLE;

    if (mmi_cca_doc_nodedata_by_param(hNode, param_id, &coredata) == CCA_STATUS_NOT_FOUND)
        return CCA_STATUS_NOT_FOUND;

    if (coredata->type != CCA_DT_INT)
        return CCA_STATUS_TYPE_MISMATCHED;

    if (value)
        *value = (coredata->size?coredata->values.i[0]:0);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_get_nodedata_int_first
 * DESCRIPTION
 *  retrieve the first int data of the matching the specified param_id in the node pointed by the iterator
 * PARAMETERS
 *  iter       [in]     can be a valid nodelist iterator or a valid datalist iterator
 *  param_id   [in]
 *  value      [out]    can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_ITER
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_get_nodedata_int_first(cca_iterator_struct *iter, U16 param_id, S32 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *coredata;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_get_nodedata_by_param(iter, param_id, &coredata);
    if (status != CCA_STATUS_OK)
        return status;

    if (coredata->type != CCA_DT_INT)
        return CCA_STATUS_TYPE_MISMATCHED;

    if (value)
        *value = (coredata->size?coredata->values.i[0]:0);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_nodedata_str_first
 * DESCRIPTION
 *  retrieve the first str data of the matching the specified param_id in the specified node
 * PARAMETERS
 *  hNode      [in]
 *  param_id   [in]
 *  value      [out]    can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_nodedata_str_first(S32 hNode, U16 param_id, S8 **value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct* coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return CCA_STATUS_INVALID_HANDLE;

    if (mmi_cca_doc_nodedata_by_param(hNode, param_id, &coredata) == CCA_STATUS_NOT_FOUND)
        return CCA_STATUS_NOT_FOUND;

    if (coredata->type != CCA_DT_STR)
        return CCA_STATUS_TYPE_MISMATCHED;

    if (value)
        *value = (coredata->size?coredata->values.s[0]:0);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_get_nodedata_str_first
 * DESCRIPTION
 *  retrieve the first str data of the matching the specified param_id in the node pointed by the iterator
 * PARAMETERS
 *  iter       [in]     can be a valid nodelist iterator or a valid datalist iterator
 *  param_id   [in]
 *  value      [out]    can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_ITER
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_get_nodedata_str_first(cca_iterator_struct *iter, U16 param_id, S8 **value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *coredata;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_get_nodedata_by_param(iter, param_id, &coredata);
    if (status != CCA_STATUS_OK)
        return status;

    if (coredata->type != CCA_DT_STR)
        return CCA_STATUS_TYPE_MISMATCHED;

    if (value)
        *value = (coredata->size?coredata->values.s[0]:0);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_nodedata_ints
 * DESCRIPTION
 *  retrieve the int array data of the matching the specified param_id in the specified node
 * PARAMETERS
 *  hNode      [in]
 *  param_id   [in]
 *  values     [out]    can be NULL pointer
 *  size       [out]    can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_nodedata_ints(S32 hNode, U16 param_id, S32 **values, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct* coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return CCA_STATUS_INVALID_HANDLE;

    if (mmi_cca_doc_nodedata_by_param(hNode, param_id, &coredata) == CCA_STATUS_NOT_FOUND)
        return CCA_STATUS_NOT_FOUND;

    if (coredata->type != CCA_DT_INT)
        return CCA_STATUS_TYPE_MISMATCHED;

    if (size)
        *size = coredata->size;

    if (values)
        *values = (coredata->size?coredata->values.i:0);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_get_nodedata_ints
 * DESCRIPTION
 *  retrieve the int array of the matching the specified param_id in the node pointed by the iterator
 * PARAMETERS
 *  iter       [in]     can be a valid nodelist iterator or a valid datalist iterator
 *  param_id   [in]
 *  values     [out]    can be NULL pointer
 *  size       [out]    can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_ITER
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_get_nodedata_ints(cca_iterator_struct *iter, U16 param_id, S32 **values, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *coredata;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_get_nodedata_by_param(iter, param_id, &coredata);
    if (status != CCA_STATUS_OK)
        return status;

    if (coredata->type != CCA_DT_INT)
        return CCA_STATUS_TYPE_MISMATCHED;

    if (size)
        *size = coredata->size;

    if (values)
        *values = (coredata->size?coredata->values.i:0);


    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_nodedata_strs
 * DESCRIPTION
 *  retrieve the str array data of the matching the specified param_id in the specified node
 * PARAMETERS
 *  hNode      [in]
 *  param_id   [in]
 *  values     [out]    can be NULL pointer
 *  size       [out]    can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_nodedata_strs(S32 hNode, U16 param_id, S8 ***values, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct* coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return CCA_STATUS_INVALID_HANDLE;

    if (mmi_cca_doc_nodedata_by_param(hNode, param_id, &coredata) == CCA_STATUS_NOT_FOUND)
        return CCA_STATUS_NOT_FOUND;

    if (coredata->type != CCA_DT_STR)
        return CCA_STATUS_TYPE_MISMATCHED;

    if (size)
        *size = coredata->size;

    if (values)
        *values = (coredata->size?coredata->values.s:0);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_get_nodedata_ints
 * DESCRIPTION
 *  retrieve the str array of the matching the specified param_id in the node pointed by the iterator
 * PARAMETERS
 *  iter       [in]     can be a valid nodelist iterator or a valid datalist iterator
 *  param_id   [in]
 *  values     [out]    can be NULL pointer
 *  size       [out]    can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_ITER
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_TYPE_MISMATCHED
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_get_nodedata_strs(cca_iterator_struct *iter, U16 param_id, S8 ***values, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *coredata;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_get_nodedata_by_param(iter, param_id, &coredata);
    if (status != CCA_STATUS_OK)
        return status;

    if (coredata->type != CCA_DT_STR)
        return CCA_STATUS_TYPE_MISMATCHED;

    if (size)
        *size = coredata->size;

    if (values)
        *values = (coredata->size?coredata->values.s:0);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_update_coredata_int
 * DESCRIPTION
 *  replaces values in coredata with specified value (ie, remove all old value and add new value)
 *  the new data type will be set to "int" should operation succeeded
 * PARAMETERS
 *  data_obj    [in]
 *  value       [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_update_coredata_int(cca_core_data_struct *data_obj, const S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_doc_coredata_release_values(data_obj);
    data_obj->type = CCA_DT_INT;
    data_obj->size = 0;
    
    return mmi_cca_doc_coredata_append(data_obj, 1, (void*)&value);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_update_coredata_str
 * DESCRIPTION
 *  replaces values in coredata with specified value (ie, remove all old value and add new value)
 *  the new data type will be set to "str" should operation succeeded
 * PARAMETERS
 *  data_obj    [in]
 *  value       [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_update_coredata_str(cca_core_data_struct *data_obj, const S8 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_doc_coredata_release_values(data_obj);
    data_obj->type = CCA_DT_STR;
    data_obj->size = 0;
    
    return mmi_cca_doc_coredata_append(data_obj, 1, (void*)&value);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_update_coredata_ints
 * DESCRIPTION
 *  replaces values in coredata with specified value (ie, remove all old value and add new value)
 *  the new data type will be set to "int" should operation succeeded
 * PARAMETERS
 *  data_obj    [in]
 *  value       [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_update_coredata_ints(cca_core_data_struct *data_obj, S32 size, const S32 *values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_doc_coredata_release_values(data_obj);
    data_obj->type = CCA_DT_INT;
    data_obj->size = 0;
    
    return mmi_cca_doc_coredata_append(data_obj, size, (void*)values);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_update_coredata_strs
 * DESCRIPTION
 *  replaces values in coredata with specified value (ie, remove all old value and add new value)
 *  the new data type will be set to "str" should operation succeeded
 * PARAMETERS
 *  data_obj    [in]
 *  value       [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_update_coredata_strs(cca_core_data_struct *data_obj, S32 size, const S8 **values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_doc_coredata_release_values(data_obj);
    data_obj->type = CCA_DT_STR;
    data_obj->size = 0;
    
    return mmi_cca_doc_coredata_append(data_obj, size, (void*)values);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_update_nodedata_int
 * DESCRIPTION
 *  replaces values in coredata matching the specified param_id within the node to the specified value
 *  the new data type will be set to "int" should operation succeeded
 * PARAMETERS
 *  hNode       [in]
 *  param_id    [in]
 *  value       [in]
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_update_nodedata_int(S32 hNode, U16 param_id, const S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status;
    cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_nodedata_by_param(hNode, param_id, &coredata);
    if (status != CCA_STATUS_OK)
        return status;

    return mmi_cca_doc_update_coredata_int(coredata, value);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_update_nodedata_str
 * DESCRIPTION
 *  replaces values in coredata matching the specified param_id within the node to the specified value
 *  the new data type will be set to "str" should operation succeeded
 * PARAMETERS
 *  hNode       [in]
 *  param_id    [in]
 *  value       [in]
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_update_nodedata_str(S32 hNode, U16 param_id, const S8 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status;
    cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_nodedata_by_param(hNode, param_id, &coredata);
    if (status != CCA_STATUS_OK)
        return status;

    return mmi_cca_doc_update_coredata_str(coredata, value);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_update_nodedata_ints
 * DESCRIPTION
 *  replaces values in coredata matching the specified param_id within the node to the specified value
 *  the new data type will be set to "int" should operation succeeded
 * PARAMETERS
 *  hNode       [in]
 *  param_id    [in]
 *  value       [in]
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_update_nodedata_ints(S32 hNode, U16 param_id, S32 size, const S32 *values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status;
    cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_nodedata_by_param(hNode, param_id, &coredata);
    if (status != CCA_STATUS_OK)
        return status;

    return mmi_cca_doc_update_coredata_ints(coredata, size, values);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_update_nodedata_strs
 * DESCRIPTION
 *  replaces values in coredata matching the specified param_id within the node to the specified value
 *  the new data type will be set to "str" should operation succeeded
 * PARAMETERS
 *  hNode       [in]
 *  param_id    [in]
 *  value       [in]
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_update_nodedata_strs(S32 hNode, U16 param_id, S32 size, const S8 **values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status;
    cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_nodedata_by_param(hNode, param_id, &coredata);
    if (status != CCA_STATUS_OK)
        return status;

    return mmi_cca_doc_update_coredata_strs(coredata, size, values);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_nodedata_next
 * DESCRIPTION
 *  retrieve the coredata obj of the next pointed datalist
 * PARAMETERS
 *  iter_datalist       [in]
 *  data_obj            [out]    can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_ITER
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_nodedata_next(cca_iterator_struct *iter_datalist, cca_core_data_struct **data_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_datalist_struct *crtDatalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_obj)
        *data_obj = 0;

    if (!iter_datalist || iter_datalist->iter_type != CCA_IT_DATALIST)
        return CCA_STATUS_INVALID_ITER;

    crtDatalist = (cca_doc_node_datalist_struct*)mmi_cca_iterator_next(iter_datalist);
    if (!crtDatalist)
        return CCA_STATUS_ENDLIST;

    if (data_obj)
        *data_obj = &(crtDatalist->data);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_nodelist_new
 * DESCRIPTION
 *  pre: valid node object
 *  construct a new nodelist object wrapping this node
 * PARAMETERS
 *  node        [in]
 * RETURNS
 *  constructed nodelist object or 0 if mem full
 *****************************************************************************/
cca_doc_nodelist_struct* mmi_cca_doc_nodelist_new(cca_doc_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_nodelist_struct *nodelist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!node)
        return 0;

    nodelist = mmi_cca_malloc_type(cca_doc_nodelist_struct);
    if (nodelist)
    {
        nodelist->next = 0;
        nodelist->node = node;
    }
    return nodelist;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_iter_nodes_new
 * DESCRIPTION
 *  construct an iter_nodes object (for document structural info)
 * PARAMETERS
 *  node_id        [in]
 * RETURNS
 *  constructed iter_nodes object or 0 if mem full
 *****************************************************************************/
cca_doc_iter_nodes_struct* mmi_cca_doc_iter_nodes_new(U16 node_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_iter_nodes_struct *iter_nodes_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter_nodes_list = mmi_cca_malloc_type(cca_doc_iter_nodes_struct);
    if (iter_nodes_list)
    {
        iter_nodes_list->nodes = 0;
        iter_nodes_list->next = 0;
        iter_nodes_list->num_nodes = 0;
        iter_nodes_list->node_id = node_id;
    }
    return iter_nodes_list;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_iter_nodes_find
 * DESCRIPTION
 *  find the matching iter_nodes of the node_id
 * PARAMETERS
 *  node_id        [in]
 * RETURNS
 *  constructed iter_nodes object or 0 if mem full
 *****************************************************************************/
cca_doc_iter_nodes_struct* mmi_cca_doc_iter_nodes_find(cca_doc_iter_nodes_struct *iter_nodes_list, U16 node_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (iter_nodes_list)
    {
        if (iter_nodes_list->node_id == node_id)
            return iter_nodes_list;
        iter_nodes_list = iter_nodes_list->next;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_construct_iter_nodes_list
 * DESCRIPTION
 *  analyse this doc tree and construct an iterator to the iter_nodes object for document structural info
 * PARAMETERS
 *  root        [in]
 * RETURNS
 *  constructed object or 0 if mem full
 *****************************************************************************/
cca_doc_iter_nodes_struct* mmi_cca_doc_construct_iter_nodes_list(cca_doc_node_struct *root)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *iter_doc;
    cca_doc_node_struct *crtNode;
    cca_doc_iter_nodes_struct *iter_nodes_list;
    cca_doc_iter_nodes_struct *matched_iter_nodes_list;
    cca_doc_nodelist_struct *nodelist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!root)
        return 0;

    iter_doc = mmi_cca_iterator_new(
                    CCA_TR_PREORDER,
                    CCA_IT_DOC,
                    (cca_generic_ptr_struct*)root,
                    0);

    if (!iter_doc)
        return 0;

    iter_nodes_list = 0;
    while ( (crtNode=(cca_doc_node_struct*)mmi_cca_iterator_next(iter_doc))!=0 )
    {
        /* attempt to find existing iter_nodes_list elem */
        matched_iter_nodes_list = mmi_cca_doc_iter_nodes_find(iter_nodes_list, crtNode->node_id);

        /* create an empty iter_nodes_list if not found */
        if (!matched_iter_nodes_list)
        {
            matched_iter_nodes_list = mmi_cca_doc_iter_nodes_new(crtNode->node_id);
            if (!matched_iter_nodes_list)
            {
                /* need to release iter_nodes_list!!! */
                mmi_cca_doc_iter_nodes_list_release(iter_nodes_list, 1);
                iter_nodes_list = 0;
                break;
            }
            mmi_cca_doc_link_list_elem_to_last(
                (cca_generic_ptr_struct**)&iter_nodes_list,
                (cca_generic_ptr_struct*)matched_iter_nodes_list);
        }

        /* add node to nodelist of the iter_nodes_list just then */
        nodelist = mmi_cca_doc_nodelist_new(crtNode);
        if (!nodelist)
        {
            /* need to release iter_nodes_list!!! */
            mmi_cca_doc_iter_nodes_list_release(iter_nodes_list, 1);
            iter_nodes_list = 0;
            break;
        }
        else
        {
            mmi_cca_doc_link_list_elem_to_last(
                (cca_generic_ptr_struct**)&(matched_iter_nodes_list->nodes),
                (cca_generic_ptr_struct*)nodelist);

            matched_iter_nodes_list->num_nodes++;
        }
    }

    mmi_cca_iterator_release(iter_doc);
    return iter_nodes_list;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_get_nodes
 * DESCRIPTION
 *  retrieve an interator of nodelist of the same node_symbol
 * PARAMETERS
 *  hConfig         [in]
 *  node_symbol     [in]
 *  iter_nodelist   [out]   can be NULL pointer
 *  size            [out]   can be NULL pointer
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_NOT_FOUND
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_doc_get_nodes(S32 hConfig, U16 node_symbol, cca_iterator_struct **iter_nodelist, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_document_struct *doc;
    cca_doc_iter_nodes_struct *iter_nodes_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (cca_document_struct*)hConfig;
    if (iter_nodelist)
        *iter_nodelist = 0;
    if (size)
        *size = 0;

    if (!doc)
        return CCA_STATUS_INVALID_HANDLE;

    iter_nodes_list = mmi_cca_doc_iter_nodes_find(doc->iter_nodes_list, node_symbol);
    if (!iter_nodes_list)
        return CCA_STATUS_NOT_FOUND;

    if (size)
        *size = iter_nodes_list->num_nodes;

    if (iter_nodelist && iter_nodes_list->nodes)
    {
        *iter_nodelist = mmi_cca_iterator_new(
            CCA_TR_LIST,
            CCA_IT_NODELIST,
            (cca_generic_ptr_struct*)iter_nodes_list->nodes,
            0);

        if (!iter_nodelist)
        {
            if (size)
                *size = 0;
            return CCA_STATUS_MEMFULL;
        }
    }

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_coredata_is_equal
 * DESCRIPTION
 *  check whether the 2 coredata have the same contents (the order of values in array is not considered)
 * PARAMETERS
 *  coredata1   [in]
 *  coredata2   [in]
 * RETURNS
 *  0 = not equal
 *  1 = equal
 *****************************************************************************/
U8 mmi_cca_doc_coredata_is_equal(cca_core_data_struct *cd1, cca_core_data_struct *cd2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cd1->id!=cd2->id || cd1->type!=cd2->type || cd1->size!=cd2->size)
        return 0;

    for (count=0; count<cd1->size; count++)
    {
        if ((cd1->type==CCA_DT_INT && !mmi_cca_doc_coredata_exists_int(cd2, cd1->values.i[count])) ||
            (cd1->type==CCA_DT_STR && !mmi_cca_doc_coredata_exists_str(cd2, cd1->values.s[count])))
        {
            return 0;
        }
    }
    for (count=0; count<cd2->size; count++)
    {
        if ((cd2->type==CCA_DT_INT && !mmi_cca_doc_coredata_exists_int(cd1, cd2->values.i[count])) ||
            (cd2->type==CCA_DT_STR && !mmi_cca_doc_coredata_exists_str(cd1, cd2->values.s[count])))
        {
            return 0;
        }
    }
    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_node_equals
 * DESCRIPTION
 *  check whether the 2 nodes have the same contents (ie, all param+values match the another)
 *  this func does not check for the node's siblings or its child
 *  please note that this API is an expensive operation, and is not recommanded to be used frequently
 * PARAMETERS
 *  hNode1          [in]
 *  hNode2          [in]
 * RETURNS
 *  0 = not equal
 *  1 = equal
 *****************************************************************************/
U8 mmi_cca_doc_node_check_equal_content(S32 hNode1, S32 hNode2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node1;
    cca_doc_node_struct *node2;
    cca_doc_node_datalist_struct *datalist1;
    cca_doc_node_datalist_struct *datalist2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hNode1 == hNode2)
        return 1;
    if ((hNode1 && !hNode2) || (!hNode1 && hNode2))
        return 0;

    node1 = (cca_doc_node_struct*)hNode1;
    node2 = (cca_doc_node_struct*)hNode2;
    if ((node1->node_id != node2->node_id) || (node1->num_data != node2->num_data))
        return 0;

    datalist1 = node1->listchain;
    datalist2 = node2->listchain;
    if (datalist1 == datalist2)
        return 1;
    if ((datalist1 && !datalist2) || (!datalist1 && datalist2))
        return 0;
    
    while (datalist1)
    {
        datalist2 = node2->listchain;
        while (datalist2)
        {
            if (mmi_cca_doc_coredata_is_equal(&(datalist1->data), &(datalist2->data)))
                break;
            datalist2 = datalist2->next;
        }
        if (!datalist2)
            return 0;
        datalist1 = datalist1->next;
    }

    datalist1 = node1->listchain;
    datalist2 = node2->listchain;
    while (datalist2)
    {
        datalist1 = node1->listchain;
        while (datalist1)
        {
            if (mmi_cca_doc_coredata_is_equal(&(datalist2->data), &(datalist1->data)))
                break;
            datalist1 = datalist1->next;
        }
        if (!datalist1)
            return 0;
        datalist2 = datalist2->next;
    }
    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_node_has_param_value
 * DESCRIPTION
 *  check whether the node contains the specified parameter + value pair
 * PARAMETERS
 *  hNode           [in]
 *  param           [in]
 *  datatype        [in]
 *  value           [in]    (S32 if int, S8* if str)
 * RETURNS
 *  0 = not found
 *  1 = found
 *****************************************************************************/
U8 mmi_cca_doc_node_has_param_value(S32 hNode, U16 param, cca_data_type_enum datatype, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return 0;
    return mmi_cca_doc_datalist_has_param_value(((cca_doc_node_struct*)hNode)->listchain, param, datatype, value);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_find_node_match_param_value
 * DESCRIPTION
 *  return the first node matching the node_symbol + values in the specified param
 * PARAMETERS
 *  hStartNode      [in]
 *  node_symbol     [in]    CCA_NS__NULL to skip this arguement
 *  param           [in]
 *  datatype        [in]
 *  value           [in]    (S32 if int, S8* if str)
 * RETURNS
 *  0 = not found
 *  otherwise the matched node
 *****************************************************************************/
S32 mmi_cca_doc_find_node_match_param_value(S32 hStartNode, U16 node_symbol, U16 param, cca_data_type_enum datatype, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hStartNode)
        return 0;

    node = (cca_doc_node_struct*)hStartNode;
    while (node)
    {
        if ((node_symbol==CCA_NS__NULL || node->node_id==node_symbol) &&
            mmi_cca_doc_node_has_param_value((S32)node, param, datatype, value))
        {
            return (S32)node;
        }
        node = node->next;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_equal_node_id
 * DESCRIPTION
 *  check whether elem matches the user_data
 * PARAMETERS
 *  elem          [in]      node
 *  user_data     [in]      node_id
 * RETURNS
 *  0 = not equal
 *  1 = equal
 *****************************************************************************/
U8 mmi_cca_doc_equal_node_id(void* elem, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *node;
    U16 node_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (cca_doc_node_struct*)elem;
    node_id = *((U16*)user_data);
    return (U8)(node->node_id==node_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_equal_param_id
 * DESCRIPTION
 *  check whether elem matches the user_data
 * PARAMETERS
 *  elem          [in]      datalist
 *  user_data     [in]      param_id
 * RETURNS
 *  0 = not equal
 *  1 = equal
 *****************************************************************************/
U8 mmi_cca_doc_equal_param_id(void* elem, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_datalist_struct *datalist;
    U16 param_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    datalist = (cca_doc_node_datalist_struct*)elem;
    param_id = *((U16*)user_data);
    return (U8)(datalist->data.id==param_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_list_find
 * DESCRIPTION
 *  to find an elem from the specified list
 * PARAMETERS
 *  list          [in]
 *  fpEqual       [in]
 *  user_data     [in]
 * RETURNS
 *  matched object, 0 if not found
 *****************************************************************************/
void* mmi_cca_doc_list_find(cca_generic_ptr_struct *list, CCA_FP_LIST_ELEM_EQUAL fpEqual, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (list)
    {
        if (fpEqual((void*)list, user_data))
            return (void*)list;
        list = list->next;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_parse_mapping_table
 * DESCRIPTION
 *  pre: well-formed mapping table
 *  parse target application specified mapping table to a CCA tree
 * PARAMETERS
 *  table      [in]
 *  size       [in]
 * RETURNS
 *  constructed tree
 *****************************************************************************/
cca_doc_node_struct* mmi_cca_doc_parse_mapping_table(const U16 *table, const S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 trigType;
    U16 crtSymbol;
    U16 entryID;
    U16 mappedSymbol;
    S32 index;
    cca_doc_node_struct *root;
    cca_doc_node_struct *crtNode;
    cca_doc_node_struct *matchedChild;
    U8 state;  /* 0:new entry, 1:parsing node hierachy, 2:mapped symbol identified */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root = (cca_doc_node_struct*)mmi_cca_doc_new_node(CCA_NS_DOCROOT);
    if (!root)
        return 0;

    mappedSymbol = 0;
    entryID = 0;
    trigType = 0;
    state = 0;
    crtNode = root;
    for (index=0; index<size; index++)
    {
        crtSymbol = table[index];

        if (state == 0)
        {
            trigType = crtSymbol;
            state++;
        }
        else if (state == 1)
        {
            if (trigType == CCA_NS_TRIGPARM && table[index+2] == 0xFFFF)
            {
                entryID = crtSymbol;
                mappedSymbol = table[index+1];
                state++;
                index++;
                continue;
            }
            if (table[index+1] == 0xFFFF)   /* trigType = CCA_NS_TRIGNODE only */
            {
                entryID = CCA_NS_TRIGNODE;
                mappedSymbol = crtSymbol;
                state++;
                continue;
            }
            matchedChild = (cca_doc_node_struct*)mmi_cca_doc_list_find(
                                                    (cca_generic_ptr_struct*)(crtNode->child),
                                                    mmi_cca_doc_equal_node_id,
                                                    (void*)&crtSymbol);
            if (!matchedChild)
            {
                matchedChild = (cca_doc_node_struct*)mmi_cca_doc_new_node_and_attach(crtSymbol, (S32)crtNode);
                if (!matchedChild)
                {
                    /* cleanup!!! */
                    mmi_cca_docroot_release((S32)root);
                    root = 0;
                    break;
                }
            }
            crtNode = matchedChild;
        }
        else if (state == 2)
        {
            ASSERT(crtSymbol == 0xFFFF);
            if (mmi_cca_doc_add_nodedata_int((S32)crtNode, entryID, (const S32)mappedSymbol) != CCA_STATUS_OK)
            {
                /* cleanup!! */
                mmi_cca_docroot_release((S32)root);
                root = 0;
                break;
            }
            state = 0;
            crtNode = root;
        }
    }
    return root;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_match
 * DESCRIPTION
 *  pre: each child node of a same parent node must have different node ID
 *       path must start from CCA_NS_DOCROOT, and last node matching the path will be returned.
 *  attempt to find the node of the specified path from the specified doc tree (from "root")
 * PARAMETERS
 *  root      [in]
 *  path       [in]
 *  size       [in]
 * RETURNS
 *  matched node, 0 otherwise
 *****************************************************************************/
cca_doc_node_struct *mmi_cca_doc_match(cca_doc_node_struct *root, U16 *path, S8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 level;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    level = 0;
    while (root && level<size)
    {
        if (root->node_id != path[level])
        {
            root = root->next;
            continue;
        }

        if (level==size-1)
            return root;

        level++;
        root = root->child;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_doc_process
 * DESCRIPTION
 *  the main processing function for application (ie, doc traversal->eliminate irrelevant nodes), symbol conversion)
 * PARAMETERS
 *  hConfig         [in]
 *  mapping_table   [in]
 *  size            [in]
 *  param_callback  [in]
 *  node_callback   [in]
 *  user_data       [in]
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_ABORT
 *  CCA_STATUS_OK
 *  ...or callback returned status
 *****************************************************************************/
cca_status_enum mmi_cca_doc_process(S32 hConfig, const U16 *mapping_table, const S32 size, CCA_FP_PARAM_PROC param_callback, CCA_FP_NODE_PROC node_callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_document_struct *doc;
    cca_doc_node_struct *tableRoot;

    cca_doc_node_struct *crtNode;
    cca_doc_node_struct *matchedTableNode;

    cca_iterator_struct *iter_docDatalist;
    cca_iterator_struct *iter_tableDatalist;

    cca_core_data_struct *tableCoredata;
    cca_core_data_struct *docCoredata;

    S32 symbol;
    U16 pathSymbols[CCA_TREE_MAX_LEVELS];
    cca_status_enum retStatus, procStatus;
    S8 crtLevel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (cca_document_struct*)hConfig;
    if (!doc || !mapping_table)
        return CCA_STATUS_INVALID_HANDLE;

    //MMI_CCA_LOG_DOC(hConfig);

    if ((tableRoot=mmi_cca_doc_parse_mapping_table(mapping_table, size))==0)
        return CCA_STATUS_MEMFULL;

    retStatus = CCA_STATUS_OK;
    crtLevel = 0;
    crtNode = doc->doc_tree;
    while (crtNode)
    {
        kal_mem_set(pathSymbols+crtLevel, 0, (CCA_TREE_MAX_LEVELS-crtLevel)*sizeof(U16));
        pathSymbols[crtLevel] = crtNode->node_id;

        matchedTableNode = mmi_cca_doc_match(tableRoot, (U16*)pathSymbols, (S8)(crtLevel+1));
        if (matchedTableNode)
        {
            //test_print_path(pathSymbols, (S8)(crtLevel+1));

            if (crtLevel == 1)
            {
                /* ***** check whether this node's in app's context + has dependency setting available ***** */
                if (!mmi_cca_oma_is_in_app_context(crtNode))
                    goto process_visit_next;
            }

            /* ***** trigger callback(s) ***** */
            /* init datalist iterators */
            iter_tableDatalist = mmi_cca_iterator_new(CCA_TR_LIST, CCA_IT_DATALIST, (cca_generic_ptr_struct*)(matchedTableNode->listchain), 0);
            iter_docDatalist = mmi_cca_iterator_new(CCA_TR_LIST, CCA_IT_DATALIST, (cca_generic_ptr_struct*)(crtNode->listchain), 0);

            /* always trigger node callback first if defined in mapping table */
            if (node_callback && mmi_cca_doc_get_nodedata_by_param(iter_tableDatalist, CCA_NS_TRIGNODE, &tableCoredata) == CCA_STATUS_OK)
            {
                /* namespace conversion */
                symbol = crtNode->node_id;
                crtNode->node_id = tableCoredata->values.i[0];
                /* trigger callback */
                procStatus = node_callback(hConfig, (S32)crtNode, crtNode->node_id, iter_docDatalist, user_data);
                /* restore namespace */
                crtNode->node_id = symbol;

                if (procStatus != CCA_STATUS_OK)
                    retStatus = procStatus;

                if (retStatus==CCA_STATUS_ABORT)
                {
                    mmi_cca_iterator_release(iter_docDatalist);
                    mmi_cca_iterator_release(iter_tableDatalist);
                    mmi_cca_docroot_release((S32)tableRoot);
                    return CCA_STATUS_ABORT;
                }
            }   /* end if (node_callback ...) */

            /* trigger param callback */
            if (param_callback)
            {
                mmi_cca_iterator_restart(iter_tableDatalist);
                /* loop through all interested param entries of this node as defined in mapping table */
                while (mmi_cca_doc_nodedata_next(iter_tableDatalist, &tableCoredata) == CCA_STATUS_OK)
                {
                    /* ignore trigger by node entry */
                    if (tableCoredata->id == CCA_NS_TRIGNODE)
                        continue;

                    /* move to next param entry in mapping table if this param is not found in config doc */
                    if (mmi_cca_doc_get_nodedata_by_param(iter_docDatalist, tableCoredata->id, &docCoredata) != CCA_STATUS_OK)
                        continue;

                    /* namespace conversion */
                    symbol = docCoredata->id;
                    docCoredata->id = tableCoredata->values.i[0];
                    /* trigger callback */
                    procStatus = param_callback(hConfig, docCoredata->id, docCoredata, user_data);
                    /* restore namespace */
                    docCoredata->id = symbol;

                    if (procStatus != CCA_STATUS_OK)
                        retStatus = procStatus;

                    if (retStatus == CCA_STATUS_ABORT)
                    {
                        mmi_cca_iterator_release(iter_docDatalist);
                        mmi_cca_iterator_release(iter_tableDatalist);
                        mmi_cca_docroot_release((S32)tableRoot);
                        return CCA_STATUS_ABORT;
                    }
                }
            }   /* end if (param_callback ...) */

            mmi_cca_iterator_release(iter_docDatalist);
            mmi_cca_iterator_release(iter_tableDatalist);

            /* visit child */
            if (crtNode->child)
            {
                crtNode = crtNode->child;
                crtLevel++;
                continue;
            }
        }   /* end if (matchedTableNode) */

process_visit_next:
        /* if path not defined in mapping table --> dont bother visit its child */
        /* OR a defined node has no child --> find next node to visit */
        /* find next node to visit (ie, next sibling node, or parent's sibling node if this node is a leaf node) */
        while (crtNode && !(crtNode->next))
        {
            crtNode = crtNode->parent;
            crtLevel--;
        }
        if (crtNode)
            crtNode = crtNode->next;

    }   /* end while(crtNode) */
    mmi_cca_docroot_release((S32)tableRoot);
    return retStatus;
}




cca_status_enum mmi_cca_doc_get_node_stats(cca_iterator_struct *iter_nodelist, cca_flag_enum stats_flag, cca_node_stats_struct **node_stat_obj);

void mmi_cca_doc_nodestats_release(cca_node_stats_struct *stats_obj);


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_log
 * DESCRIPTION
 *  CCA LOG function
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_cca_log(S8 *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char log[256];
    va_list arg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_cca_log_is_enabled())
        return;

    va_start(arg_list, format);
#ifdef __MTK_TARGET__
    vsnprintf(log, 256, format, arg_list);
#else
    _vsnprintf(log, 256, format, arg_list);
#endif
    va_end(arg_list);

#ifdef __MTK_TARGET__
/*
    PRINT_INFORMATION_2(CCA_TRACE_INFO, "%s", log);
*/
#else
	kal_printf("%s", log);
#endif
}

/**************************************************************/
/*********** SIMULATOR USED LOGGING FUNCTIONS *****************/
/**************************************************************/
#ifndef __MTK_TARGET__
void mmi_cca_log_print_iter_datalist(cca_iterator_struct *iter_datalist) {
    cca_doc_node_datalist_struct *datalist;

    while ((datalist=(cca_doc_node_datalist_struct*)mmi_cca_iterator_next(iter_datalist)))
        mmi_cca_log_print_coredata(&(datalist->data));
}

void mmi_cca_log_print_iter_nodelist(cca_iterator_struct *iter_nodelist) {
    cca_doc_nodelist_struct *nodelist;

    while ((nodelist=(cca_doc_nodelist_struct*)mmi_cca_iterator_next(iter_nodelist)))
        mmi_cca_log_print_node(nodelist->node);
}

void mmi_cca_log_print_node(cca_doc_node_struct *node) {
    cca_iterator_struct *iterDatalist;
    cca_core_data_struct *coredata;

    if (!node)
        return;

    kal_printf("Node ID: %X\tNum Data: %d\tNum Child: %d\n", node->node_id, node->num_data, node->num_child);

    iterDatalist = mmi_cca_iterator_new(CCA_TR_LIST, CCA_IT_DATALIST, (cca_generic_ptr_struct*)node->listchain, 0);
    while (mmi_cca_doc_nodedata_next(iterDatalist, &coredata) == CCA_STATUS_OK)
        mmi_cca_log_print_coredata(coredata);
    mmi_cca_iterator_release(iterDatalist);
}

void mmi_cca_log_print_coredata(cca_core_data_struct *coredata) {
    S32 i;

    if (!coredata)
        return;

    kal_printf("\tParam ID: %X\tType: %d\tSize: %d\tData: {",coredata->id, coredata->type, coredata->size);
    for (i=0; i<coredata->size; i++) {
        if (coredata->type == 0)
            kal_printf("%x", coredata->values.i[i]);
        else
        {
            if (coredata->values.s[i])
                kal_printf("\"%s\"", coredata->values.s[i]);
            else
                kal_printf("<null>");
        }

        if (i<coredata->size-1)
            kal_printf(", ");
        else
            kal_printf("}\n");
    }
}

void mmi_cca_log_print_doc(cca_generic_ptr_struct* root) {
    cca_iterator_struct *iter;
    cca_doc_node_struct *crtNode;

    iter = mmi_cca_iterator_new(CCA_TR_PREORDER, CCA_IT_DOC, root, 0);
    while ((crtNode=(cca_doc_node_struct*)mmi_cca_iterator_next(iter)))
    {
        kal_printf("LEVEL %d\t", iter->crt_level);
        mmi_cca_log_print_node(crtNode);
    }

    mmi_cca_iterator_release(iter);
}
#endif  /* __MTK_TARGET__ */




#endif  /* __MMI_CCA_SUPPORT__ */
