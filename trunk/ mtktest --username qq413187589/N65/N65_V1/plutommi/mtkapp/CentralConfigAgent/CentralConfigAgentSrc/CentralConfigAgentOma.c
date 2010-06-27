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
 *  CentralConfigAgentOma.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA Manipulating OMA Spec Codes
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
#include "MMI_include.h"

#ifdef __MMI_CCA_SUPPORT__

/**************************************************************/
/**********************  Header Files *************************/
/**************************************************************/


#include "CentralConfigAgentGProt.h"


typedef struct cca_oma_deprel_info_struct {
    struct cca_oma_deprel_info_struct *next;
    S32 hNode;
    S8 *cca_node_id;
    S8 *oma_node_id;
    S8 *oma_ref_id;
} cca_oma_deprel_info_struct;


static U8 cca_oma_memfull_flag = 0;

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_handle_memfull
 * DESCRIPTION
 *  handle memfull scenario
 * PARAMETERS
 *  identifier      [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_handle_memfull (U8 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cca_oma_memfull_flag = 1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_is_memfull_during_app_configure
 * DESCRIPTION
 *  indicate whether memfull occurred during application configuration process
 * PARAMETERS
 *  void
 * RETURNS
 *  0 = false, 1 = memfull
 *****************************************************************************/
U8 mmi_cca_oma_is_memfull_during_app_configure (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cca_oma_memfull_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_new_deprel_child
 * DESCRIPTION
 *  create a new dependency relationship child node
 * PARAMETERS
 *  dep_id      [in]
 *  node_id     [in]
 *  ref_id     [in]
 *  hSrcNode    [in]
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_cca_oma_new_deprel_child(U16 dep_id, S8 *node_id, S8 *ref_id, S32 hSrcNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status;
    cca_doc_node_struct *nodeDepRelChild;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nodeDepRelChild = (cca_doc_node_struct*)mmi_cca_doc_new_node(dep_id);
    if (!nodeDepRelChild)
        return 0;
    
    if (mmi_cca_doc_add_nodedata_int((S32)nodeDepRelChild, CCA_NS_HSRCNODE, (const S32)hSrcNode) != CCA_STATUS_OK)
        goto mmi_cca_oma_new_deprel_child_error;
    if (mmi_cca_doc_add_nodedata_int((S32)nodeDepRelChild, CCA_NS_ISUSED, 0) != CCA_STATUS_OK)
        goto mmi_cca_oma_new_deprel_child_error;
    if (mmi_cca_doc_add_nodedata_str((S32)nodeDepRelChild, CCA_NS_NODEID, (const S8*)node_id) != CCA_STATUS_OK)
        goto mmi_cca_oma_new_deprel_child_error;
    if (dep_id == CCA_NS_DEP_PROXY)
        status = mmi_cca_doc_add_nodedata_str((S32)nodeDepRelChild, CCA_NS_REFNAPID, (const S8*)ref_id);
    else
        status = mmi_cca_doc_add_nodedata_str((S32)nodeDepRelChild, CCA_NS_REFPXID, (const S8*)ref_id);
    if (status != CCA_STATUS_OK)
        goto mmi_cca_oma_new_deprel_child_error;

    return (S32)nodeDepRelChild;

mmi_cca_oma_new_deprel_child_error:
    if (nodeDepRelChild)
        mmi_cca_doc_node_release_all((S32)nodeDepRelChild);
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_add_deprel
 * DESCRIPTION
 *  add dependency relation data to dep rel subtree in doc
 * PARAMETERS
 *  hRoot       [in]
 *  dep_id      [in]
 *  node_id     [in]
 *  hSrcNode    [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_oma_add_deprel(S32 hRoot, U16 dep_id, S8 *node_id, S8 *ref_id, S32 hSrcNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *nodeDepRel;
    S32 hDepRelChild;
    U16 symbol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hRoot)
        return CCA_STATUS_INVALID_HANDLE;

    /* get DEP_REL root node */
    symbol = CCA_NS_DEPREL;
    nodeDepRel = (cca_doc_node_struct*)mmi_cca_doc_list_find(
                                            (cca_generic_ptr_struct*)(((cca_doc_node_struct*)hRoot)->child),
                                            mmi_cca_doc_equal_node_id,
                                            (void*)&symbol);
    if (!nodeDepRel)
    {
        nodeDepRel = (cca_doc_node_struct*)mmi_cca_doc_new_node_and_attach(CCA_NS_DEPREL, hRoot);
        if (!nodeDepRel)
            return CCA_STATUS_MEMFULL;
    }

    /* add dep rel data to DEP_REL node */
    hDepRelChild = mmi_cca_oma_new_deprel_child(dep_id, node_id, ref_id, hSrcNode);
    if (!hDepRelChild)
        return CCA_STATUS_MEMFULL;
    mmi_cca_doc_attach_node_to_parent(hDepRelChild, (S32)nodeDepRel);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_mark_depset
 * DESCRIPTION
 *  mark dep rel subtree nodes to "set" if data has been filled
 * PARAMETERS
 *  nodeDepRelBegin  [in]
 *  refIdToMark      [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_mark_depset(cca_doc_node_struct *nodeDepRelBegin, S8 *refIdToMark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *crtNode;
    cca_doc_node_datalist_struct *crtdlist;
    S8 **nodeid;
    S32 *inuse;
    S8 **refnapid;
    S8 **refpxid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    crtNode = nodeDepRelBegin;
    /* for each dep-rel data nodes */
    while (crtNode)
    {
        /* get its parameters */
        crtdlist = crtNode->listchain;
        nodeid = 0;
        inuse = 0;
        refnapid = 0;
        refpxid = 0;
        while (crtdlist)
        {
            switch (crtdlist->data.id)
            {
                case CCA_NS_NODEID:
                    nodeid = crtdlist->data.values.s;
                    break;
                case CCA_NS_ISUSED:
                    inuse = crtdlist->data.values.i;
                    break;
                case CCA_NS_REFNAPID:
                    refnapid = crtdlist->data.values.s;
                    break;
                case CCA_NS_REFPXID:
                    refpxid = crtdlist->data.values.s;
                    break;
            }
            crtdlist = crtdlist->next;
        }

        /* check if ref id matched */
        if ( (refnapid && strcmp(refnapid[0], refIdToMark)==0) ||
             (refpxid && strcmp(refpxid[0], refIdToMark)==0) )
        {
            /* mark in-use only if this node hasnt been marked before */
            if (inuse[0] == 0)
            {
                inuse[0] = 1;
                /* recursively mark nodes that has ref to this node */
                mmi_cca_oma_mark_depset(nodeDepRelBegin, nodeid[0]);
            }
        }

        crtNode = crtNode->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_get_deprel_childs
 * DESCRIPTION
 *  mark dep rel subtree nodes to "set" if data has been filled
 * PARAMETERS
 *  nodeDepRelBegin  [in]
 *  refIdToMark      [in]
 * RETURNS
 *  void
 *****************************************************************************/
cca_status_enum mmi_cca_oma_get_deprel_childs(S32 hConfig, cca_doc_node_struct **nodeDepRelBegin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *iter_nodelist;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nodeDepRelBegin)
        *nodeDepRelBegin = 0;

    /* get dep-rel data nodes iterator */
    status = mmi_cca_doc_get_nodes(hConfig, CCA_NS_DEPREL, &iter_nodelist, 0);
    if (status == CCA_STATUS_MEMFULL)
        return CCA_STATUS_MEMFULL;
    else if (status==CCA_STATUS_OK)
    {
        if (nodeDepRelBegin)
            *nodeDepRelBegin = ((cca_doc_nodelist_struct*)(mmi_cca_iterator_next(iter_nodelist)))->node->child;
        mmi_cca_iterator_release(iter_nodelist);
    }
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_add_dataacctid_to_ref_nodes
 * DESCRIPTION
 *  add data account ID to the associated NAPDEF node
 * PARAMETERS
 *  hConfig         [in]
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_oma_add_dataacctid_to_ref_nodes(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_document_struct *doc;
    cca_doc_node_struct *nodeDepRel;
    cca_doc_node_struct *l1node;
    S32 dtacctid;
    S32 hSrcNode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (cca_document_struct*)hConfig;
    if (!doc)
        return CCA_STATUS_INVALID_HANDLE;

    if (!(doc->dtAcctIDAdded))
        return CCA_STATUS_OK;

    if (mmi_cca_oma_get_deprel_childs(hConfig, &nodeDepRel) == CCA_STATUS_MEMFULL)
        return CCA_STATUS_MEMFULL;

    /* remove all data account ID in nodes
     * needs to be removed first so the order of IDs can be guarranteed
     * (this is to handle cases when multiple data account provisioning apps are in use
     * eg, standard data account + WLAN...etc) */
    l1node = doc->doc_tree->child;
    while (l1node)
    {
        mmi_cca_doc_remove_nodedata((S32)l1node, CCA_NS_DATAACCTID);
        l1node = l1node->next;
    }

    /* add data account IDs to nodes
     */
    while (nodeDepRel)
    {
        if(mmi_cca_doc_nodedata_int_first((S32)nodeDepRel, CCA_NS_DATAACCTID, &dtacctid) != CCA_STATUS_OK ||
           mmi_cca_doc_nodedata_int_first((S32)nodeDepRel, CCA_NS_HSRCNODE, &hSrcNode) != CCA_STATUS_OK)
        {
            nodeDepRel = nodeDepRel->next;
            continue;
        }
        
        if (mmi_cca_doc_add_nodedata_int(hSrcNode, CCA_NS_DATAACCTID, (const S32)dtacctid) != CCA_STATUS_OK)
            return CCA_STATUS_MEMFULL;
        nodeDepRel = nodeDepRel->next;
    }
    doc->dtAcctIDAdded = 0;
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_add_dataacctid
 * DESCRIPTION
 *  add data account ID to the associated NAPDEF node
 * PARAMETERS
 *  hConfig         [in]
 *  nap_node_id     [in]
 *  dataacctid      [in]
 * RETURNS
 *  CCA_STATUS_INVALID_HANDLE
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_oma_add_dataacctid(S32 hConfig, S8 *nap_node_id, S32 dataacctid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_document_struct *doc;
    S8 *refnapid;
    cca_status_enum status;
    cca_doc_node_struct *nodeDepRelBegin;
    cca_doc_node_struct *node;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (cca_document_struct*)hConfig;
    if (!doc)
        return CCA_STATUS_INVALID_HANDLE;

    if (mmi_cca_oma_get_deprel_childs(hConfig, &nodeDepRelBegin) == CCA_STATUS_MEMFULL)
        return CCA_STATUS_MEMFULL;

    /* add data account ID to deprel node */
    node = nodeDepRelBegin;
    while (node)
    {
        status = mmi_cca_doc_nodedata_str_first((S32)node, CCA_NS_REFNAPID, &refnapid);
        if (status!=CCA_STATUS_OK || strcmp(nap_node_id, refnapid)!=0)
        {
            node = node->next;
            continue;
        }

        if (mmi_cca_doc_add_nodedata_int((S32)node, CCA_NS_DATAACCTID, (const S32)dataacctid) != CCA_STATUS_OK)
            return CCA_STATUS_MEMFULL;

        doc->dtAcctIDAdded = 1;
        node = node->next;
    }

    /* recursively mark in-use flag */
    mmi_cca_oma_mark_depset(nodeDepRelBegin, nap_node_id);

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_is_depset
 * DESCRIPTION
 *  check whether a dep rel node contains data
 * PARAMETERS
 *  hConfig         [in]
 *  l1node          [in]
 * RETURNS
 *  CCA_STATUS_FAIL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_oma_is_depset(S32 hConfig, cca_doc_node_struct *l1node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *nodeDepRelBegin;
    S8 *l1node_id;
    cca_doc_node_datalist_struct *datalist;
    U16 symbol;
    U8 found_but_not_inuse;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    found_but_not_inuse = 0;
    if (mmi_cca_oma_get_deprel_childs(hConfig, &nodeDepRelBegin) == CCA_STATUS_MEMFULL)
        return CCA_STATUS_MEMFULL;
    if (!nodeDepRelBegin)
        return CCA_STATUS_OK;

    symbol = CCA_NS_NODEID;
    datalist = (cca_doc_node_datalist_struct*)mmi_cca_doc_list_find(
                                                    (cca_generic_ptr_struct*)(l1node->listchain),
                                                    mmi_cca_doc_equal_param_id,
                                                    (void*)&symbol);
    /* no CCA_NS_NODEID defined */
    if (!datalist)
        return CCA_STATUS_OK;
    
    l1node_id = datalist->data.values.s[0];
    /* for each dep-rel data node */
    while(nodeDepRelBegin)
    {
        /* find matching node_id */
        symbol = CCA_NS_NODEID;
        datalist = (cca_doc_node_datalist_struct*)mmi_cca_doc_list_find(
                                                    (cca_generic_ptr_struct*)(nodeDepRelBegin->listchain),
                                                    mmi_cca_doc_equal_param_id,
                                                    (void*)&symbol);
        if (datalist && strcmp(datalist->data.values.s[0], l1node_id)==0)
        {
            /* check if in-use */
            symbol = CCA_NS_ISUSED;
            datalist = (cca_doc_node_datalist_struct*)mmi_cca_doc_list_find(
                                                    (cca_generic_ptr_struct*)(nodeDepRelBegin->listchain),
                                                    mmi_cca_doc_equal_param_id,
                                                    (void*)&symbol);
            if (datalist && datalist->data.values.i[0]==1)
                return CCA_STATUS_OK;
            found_but_not_inuse = 1;
        }
        nodeDepRelBegin = nodeDepRelBegin->next;
    }
    if (found_but_not_inuse)
        return CCA_STATUS_FAIL;
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_retrieve_all_appids
 * DESCRIPTION
 *  pre: valid hConfig and datalist pointer
 *  retrieve all AppIDs described by this doc and store them in a datalist
 * PARAMETERS
 *  hConfig         [in]
 *  datalist_res    [out]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_oma_retrieve_all_appids(S32 hConfig, cca_doc_node_datalist_struct *datalist_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *l1nodes;
    cca_doc_node_datalist_struct *datalist;
    U16 symbol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l1nodes = ((cca_document_struct*)hConfig)->doc_tree->child;
    symbol = CCA_NS_OMA_APPID;
    while (l1nodes)
    {
        if (l1nodes->node_id == CCA_NS_OMA_APPLICATION)
        {
            datalist = (cca_doc_node_datalist_struct*)mmi_cca_doc_list_find(
                                                        (cca_generic_ptr_struct*)(l1nodes->listchain),
                                                        mmi_cca_doc_equal_param_id,
                                                        (void*)&symbol);
            if (datalist &&
                datalist->data.size>0 &&
                !mmi_cca_doc_coredata_values_exists_str(datalist_res->data.values.s, datalist_res->data.size, datalist->data.values.s[0]))
            {
                if (mmi_cca_doc_coredata_append(&(datalist_res->data), 1, (void*)datalist->data.values.s) == CCA_STATUS_MEMFULL)
                {
                    mmi_cca_doc_coredata_release_values(&(datalist_res->data));
                    return CCA_STATUS_MEMFULL;
                }
            }
        }
        l1nodes = l1nodes->next;
    }
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_retrieve_nodeids
 * DESCRIPTION
 *  pre: valid hConfig and datalist pointer
 *  retrieve all node_id described by this doc and store them in a datalist
 * PARAMETERS
 *  hConfig         [in]
 *  datalist_res    [out]
 * RETURNS
 *  CCA_STATUS_MEMFULL
 *  CCA_STATUS_OK
 *****************************************************************************/
cca_status_enum mmi_cca_oma_retrieve_nodeids(S32 hConfig, cca_doc_node_datalist_struct *datalist_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *l1nodes;
    S32 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l1nodes = ((cca_document_struct*)hConfig)->doc_tree->child;
    while (l1nodes)
    {
        val = (S32)l1nodes->node_id;  // to avoid typecasting U16 pointer to S32 pointer (higher 2 bytes = corrupted data)
        if (mmi_cca_doc_coredata_append(&(datalist_res->data), 1, (void*)&val) == CCA_STATUS_MEMFULL)
        {
            mmi_cca_doc_coredata_release_values(&(datalist_res->data));
            return CCA_STATUS_MEMFULL;
        }
        l1nodes = l1nodes->next;
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_find_proxy_ref_by
 * DESCRIPTION
 *  pre: valid ref_by object struct for storing output
 * PARAMETERS
 *  hConfig   [in]
 *  l1node    [in]
 *  ref_by    [in]
 * RETURNS
 *  CCA_STATUS_MEMFULL if mem full
 *  CCA_STATUS_FAIL if no other nodes has ref to this node
 *  CCA_STATUS_OK if one or more nodes has ref to this node (with reference info stored in ref_by obj)
 *****************************************************************************/
cca_status_enum mmi_cca_oma_find_proxy_ref_by(S32 hConfig, cca_doc_node_struct *l1node, cca_ref_by_struct *ref_by)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_datalist_struct *datalist;
    cca_doc_node_struct *nodeDepRelBegin;
    cca_doc_node_struct *srcNode;
    S32 isused;
    S8 *ref_pxid;
    S8 *l1node_id;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(ref_by, 0, sizeof(cca_ref_by_struct));

    if (mmi_cca_oma_get_deprel_childs(hConfig, &nodeDepRelBegin) == CCA_STATUS_MEMFULL)
        return CCA_STATUS_MEMFULL;

    /* retrieve NODE_ID parameter of this level 1 node */
    datalist = mmi_cca_doc_datalist_find_ptr(l1node->listchain, CCA_NS_NODEID);
    l1node_id = 0;
    if (datalist)
        l1node_id = datalist->data.values.s[0];

    if (!l1node_id)
        return CCA_STATUS_FAIL;

    /* for each of dependency relationship nodes */
    while (nodeDepRelBegin)
    {
        srcNode = 0;
        isused = 0;
        ref_pxid = 0;

        /* extract data */
        datalist = nodeDepRelBegin->listchain;
        while (datalist)
        {
            switch (datalist->data.id)
            {
                case CCA_NS_HSRCNODE:
                    srcNode = (cca_doc_node_struct*)(datalist->data.values.i[0]);
                    break;
                case CCA_NS_ISUSED:
                    isused = datalist->data.values.i[0];
                    break;
                case CCA_NS_REFPXID:
                    ref_pxid = datalist->data.values.s[0];
                    break;
                case CCA_NS_NODEID:
                case CCA_NS_REFNAPID:
                    break;
            }
            datalist = datalist->next;
        }

        /* if found a node with ref to this proxy node */
        if (ref_pxid && isused && strcmp(l1node_id, ref_pxid)==0)
        {
            /* add referenced node symbols */
            if (ref_by->ref_by_node_symbols_count < CCA_MAX_REF_BY_ENTRIES)
            {
                for (i=0; i<ref_by->ref_by_node_symbols_count; i++)
                    if (ref_by->ref_by_node_symbols[i] == srcNode->node_id)
                        break;
                /* do not add APPLICATION symbol to list because APPLICATION nodes are differentiated by appids
                 * --> will cause ambigious if APPLICATION is added as a proxy may be referenced by 1 app and not the another */
                if (i>=ref_by->ref_by_node_symbols_count && srcNode->node_id!=CCA_NS_OMA_APPLICATION)
                {
                    ref_by->ref_by_node_symbols[ref_by->ref_by_node_symbols_count] = srcNode->node_id;
                    ref_by->ref_by_node_symbols_count++;
                }
            }
            /* add referenced node handles */
            if (ref_by->ref_by_node_handles_count < CCA_MAX_REF_BY_ENTRIES)
            {
                for (i=0; i<ref_by->ref_by_node_handles_count; i++)
                    if (ref_by->ref_by_node_handles[i] == (S32)srcNode)
                        break;
                if (i>=ref_by->ref_by_node_handles_count)
                {
                    ref_by->ref_by_node_handles[ref_by->ref_by_node_handles_count] = (S32)srcNode;
                    ref_by->ref_by_node_handles_count++;
                }
            }
            /* add referenced appids */
            if (srcNode->node_id==CCA_NS_OMA_APPLICATION && ref_by->ref_by_appids_count<CCA_MAX_REF_BY_ENTRIES)
            {
                datalist = mmi_cca_doc_datalist_find_ptr(srcNode->listchain, CCA_NS_OMA_APPID);
                if (datalist)
                {
                    for (i=0; i<ref_by->ref_by_appids_count; i++)
                        if (strcmp(ref_by->ref_by_appids[i], datalist->data.values.s[0]) == 0)
                            break;
                    if (i>=ref_by->ref_by_appids_count)
                    {
                        ref_by->ref_by_appids[ref_by->ref_by_appids_count] = datalist->data.values.s[0];
                        ref_by->ref_by_appids_count++;
                    }
                }
            }
        }
        nodeDepRelBegin = nodeDepRelBegin->next;
    }
    
    return (ref_by->ref_by_node_symbols_count || ref_by->ref_by_node_handles_count || ref_by->ref_by_appids_count)?CCA_STATUS_OK:CCA_STATUS_FAIL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_check_in_app_context
 * DESCRIPTION
 *  check whether this level 1 node is in app's context
 * PARAMETERS
 *  hConfig   [in]
 *  l1node    [in]
 * RETURNS
 * CCA_STATUS_OK=node in app context
 * CCA_STATUS_FAIL=node not in app context
 * CCA_STATUS_MEMFULL
 *****************************************************************************/
cca_status_enum mmi_cca_oma_check_in_app_context(S32 hConfig, cca_doc_node_struct *l1node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_document_struct *doc;
    const cca_app_config_struct *crtConfig;
    U16 l1node_symbol;
    S32 i;
    cca_status_enum status;
    cca_doc_node_datalist_struct *datalist;
    cca_ref_by_struct ref_by;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (cca_document_struct*)hConfig;
    crtConfig = &(cca_app_config_g[cca_context_g.crtConfigIndex]);

    if (!doc || !l1node)
        return CCA_STATUS_INVALID_HANDLE;

    l1node_symbol = l1node->node_id;

    /* 0. ensure node symbol is not on proprietary symbols list */
    if (l1node_symbol == CCA_NS_DEPREL)
        return CCA_STATUS_FAIL;

    /* 1. ensure node symbol is defined in APP's config */
    if (!mmi_cca_oma_is_node_symbol_exist(l1node_symbol, crtConfig->l1node_symbols, crtConfig->num_l1node_symbols))
        return CCA_STATUS_FAIL;

    /* 2. ensure node's dependency setting is set (or non exists) */
    if ( (status=mmi_cca_oma_is_depset(hConfig, l1node)) != CCA_STATUS_OK)
        return status;

    /* 3. if node = PROXY --> ensure the referenced APP node has same appid as in APP's config
     *                        and referenced node is defined in node_symbol list */
    if (l1node_symbol == CCA_NS_OMA_PROXY)
    {
        /* get reference information */
        status = mmi_cca_oma_find_proxy_ref_by(hConfig, l1node, &ref_by);
        if (status == CCA_STATUS_MEMFULL)
            return CCA_STATUS_MEMFULL;
        if (status == CCA_STATUS_OK)
        {
            /* check if referenced appid is defined by APP's config */
            for (i=0; i<ref_by.ref_by_appids_count; i++)
                if (mmi_cca_oma_is_appid_exist(ref_by.ref_by_appids[i], crtConfig->appids, crtConfig->num_appids))
                    break;

            /* if not defined by APP's config, check if this proxy is referenced by any node symbol defined by APP's config */
            if (i>=ref_by.ref_by_appids_count)
            {
                for (i=0; i<ref_by.ref_by_node_symbols_count; i++)
                    if (mmi_cca_oma_is_node_symbol_exist(ref_by.ref_by_node_symbols[i], crtConfig->l1node_symbols, crtConfig->num_l1node_symbols))
                        break;
                if (i>=ref_by.ref_by_node_symbols_count)
                    return CCA_STATUS_FAIL;
            }
        }
    }

    /* 4. if node = APP --> ensure node's appid is defined in APP's config */
    if (l1node_symbol == CCA_NS_OMA_APPLICATION)
    {
        datalist = mmi_cca_doc_datalist_find_ptr(l1node->listchain, CCA_NS_OMA_APPID);
        if (!datalist || !mmi_cca_oma_is_appid_exist(datalist->data.values.s[0], crtConfig->appids, crtConfig->num_appids))
            return CCA_STATUS_FAIL;
    }

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_is_appid_exist
 * DESCRIPTION
 *  check whether the app id exists from the app's config setting
 * PARAMETERS
 *  appidToFind  [in]
 *  appids       [in]
 *  numAppIds    [in]
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
U8 mmi_cca_oma_is_appid_exist(S8 *appidToFind, const S8 **appids, const S32 numAppIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<numAppIds; i++)
        if (strcmp(appids[i], appidToFind) == 0)
            return 1;
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_is_node_symbol_exist
 * DESCRIPTION
 *  check whether the node symbol exists from the app's config setting
 * PARAMETERS
 *  symbolToFind        [in]
 *  l1node_symbols      [in]
 *  num_l1node_symbols  [in]
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
U8 mmi_cca_oma_is_node_symbol_exist(U16 symbolToFind, const U16 *l1node_symbols, const S32 num_l1node_symbols)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i < num_l1node_symbols; i++)
        if (symbolToFind == l1node_symbols[i])
            return 1;
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_mark_in_app_context
 * DESCRIPTION
 *  check whether each of the level 1 nodes is in app's context (set flag)
 * PARAMETERS
 *  hConfig        [in]
 * RETURNS
 *  CCA_STATUS_OK=one or more nodes are in app's context (and marked),
 *  CCA_STATUS_FAIL=no nodes are in app's context (and marked),
 *  CCA_STATUS_MEMFULL
 *****************************************************************************/
cca_status_enum mmi_cca_oma_mark_in_app_context(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status;
    cca_doc_node_struct *l1node;
    cca_doc_node_datalist_struct *datalist;
    U8 hasNodeInContext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hConfig)
        return CCA_STATUS_INVALID_HANDLE;

    hasNodeInContext = 0;
    l1node = ((cca_document_struct*)hConfig)->doc_tree->child;
    while (l1node)
    {
        status = mmi_cca_oma_check_in_app_context(hConfig, l1node);
        if (status == CCA_STATUS_MEMFULL)
            return CCA_STATUS_MEMFULL;

        datalist = mmi_cca_doc_datalist_find_ptr(l1node->listchain, CCA_NS_INAPPCONTEXT);
        hasNodeInContext |= (status==CCA_STATUS_OK);
        if (!datalist)
            status = mmi_cca_doc_add_nodedata_int((S32)l1node, CCA_NS_INAPPCONTEXT, (const S32)(status==CCA_STATUS_OK));
        else
            datalist->data.values.i[0] = (S32)(status==CCA_STATUS_OK);

        if (status == CCA_STATUS_MEMFULL)
            return CCA_STATUS_MEMFULL;

        l1node = l1node->next;
    }
    return (hasNodeInContext?CCA_STATUS_OK:CCA_STATUS_FAIL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_is_in_app_context
 * DESCRIPTION
 *  check whether this level 1 nodes is in app's context
 * PARAMETERS
 *  l1node        [in]
 * RETURNS
 *****************************************************************************/
U8 mmi_cca_oma_is_in_app_context(cca_doc_node_struct *l1node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_datalist_struct *datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!l1node)
        return 0;

    datalist = mmi_cca_doc_datalist_find_ptr(l1node->listchain, CCA_NS_INAPPCONTEXT);
    return (!datalist || datalist->data.values.i[0]);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_doc_contains_appid
 * DESCRIPTION
 *  check whether doc contains the specified appid
 * PARAMETERS
 *  hConfig        [in]
 *  appids         [in]
 *  numAppIds      [in]
 * RETURNS
 *  CCA_STATUS_OK=found
 *  CCA_STATUS_NOT_FOUND=not found
 *****************************************************************************/
cca_status_enum mmi_cca_oma_doc_contains_appid(S32 hConfig, const S8 **appids, const S32 numAppIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *iter_nodelist;
    cca_status_enum status;
    S8 *value;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hConfig || !appids || numAppIds<=0)
        return CCA_STATUS_INVALID_HANDLE;
    
    status = mmi_cca_doc_get_nodes(hConfig, CCA_NS_OMA_APPLICATION, &iter_nodelist, 0);
    if (status == CCA_STATUS_MEMFULL)
        return CCA_STATUS_MEMFULL;
    
    if (status==CCA_STATUS_NOT_FOUND)
        return CCA_STATUS_NOT_FOUND;
    
    while (mmi_cca_iterator_next(iter_nodelist))
    {
        status = mmi_cca_doc_get_nodedata_str_first(iter_nodelist, CCA_NS_OMA_APPID, &value);
        if (status == CCA_STATUS_MEMFULL)
        {
            mmi_cca_iterator_release(iter_nodelist);
            return CCA_STATUS_MEMFULL;
        }
        else if (status!=CCA_STATUS_OK)
            continue;

        if (mmi_cca_oma_is_appid_exist(value, appids, numAppIds))
        {
            mmi_cca_iterator_release(iter_nodelist);
            return CCA_STATUS_OK;
        }
    }
    mmi_cca_iterator_release(iter_nodelist);
    return CCA_STATUS_NOT_FOUND;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_construct_appcheck_datalist
 * DESCRIPTION
 *  cosntruct data for the APP_CHECK function callback
 * PARAMETERS
 *  hConfig        [in]
 * RETURNS
 *  constructed object, 0 if memory full
 *****************************************************************************/
cca_iterator_struct* mmi_cca_oma_construct_appcheck_datalist(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *iter_datalist;
    cca_doc_node_datalist_struct *datalist_nodeid;
    cca_doc_node_datalist_struct *datalist_appid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* construct AppIDs list */
    datalist_appid = mmi_cca_doc_datalist_new(CCA_NS_OMA_APPID, CCA_DT_STR);
    if (!datalist_appid)
        return 0;
    if (mmi_cca_oma_retrieve_all_appids(hConfig, datalist_appid) == CCA_STATUS_MEMFULL)
    {
        mmi_cca_doc_datalist_release(datalist_appid, 1);
        return 0;
    }

    /* construct L1 Node IDs list */
    datalist_nodeid = mmi_cca_doc_datalist_new(CCA_NS_L1NODEID, CCA_DT_INT);
    if (!datalist_nodeid)
    {
        mmi_cca_doc_datalist_release(datalist_appid, 1);
        return 0;
    }
    if (mmi_cca_oma_retrieve_nodeids(hConfig, datalist_nodeid) == CCA_STATUS_MEMFULL)
    {
        mmi_cca_doc_datalist_release(datalist_appid, 1);
        mmi_cca_doc_datalist_release(datalist_nodeid, 1);
        return 0;
    }

    /* link the 2 datalist together */
    datalist_nodeid->next = datalist_appid;

    /* construct iterator */
    iter_datalist = mmi_cca_iterator_new(
                        CCA_TR_LIST,
                        CCA_IT_DATALIST,
                        (cca_generic_ptr_struct*)datalist_nodeid,
                        0);

    if (!iter_datalist)
    {
        //mmi_cca_doc_datalist_release(datalist_appid, 1);
        mmi_cca_doc_datalist_release(datalist_nodeid, 1);
    }
    return iter_datalist;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_construct_l1symbols
 * DESCRIPTION
 *  pre: valid hConfig
 *  cosntruct level 1 symbols array
 * PARAMETERS
 *  hConfig         [in]
 *  max_symbols     [in]
 *  num_symbols     [in]
 *  l1symbols       [out]
 *  l1symbols_count [out]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_construct_l1symbols(S32 hConfig, S32 max_symbols, S32 *num_symbols, U16 *l1symbols, S32 *l1symbols_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 crtNumSymbols;
    cca_doc_node_struct *l1nodes;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l1nodes = ((cca_document_struct*)hConfig)->doc_tree->child;
    if (num_symbols)
        *num_symbols = 0;
    if (l1symbols)
        kal_mem_set(l1symbols, 0, max_symbols*sizeof(U16));
    if (l1symbols_count)
        kal_mem_set(l1symbols_count, 0, max_symbols*sizeof(U16));
    if (max_symbols<=0)
        return;

    crtNumSymbols = 0;
    while (l1nodes)
    {
        if (mmi_cca_oma_is_in_app_context(l1nodes))
        {
            for (i=0; i<crtNumSymbols; i++)
                if (l1nodes->node_id == l1symbols[i])
                    break;
            if (i<crtNumSymbols)
                l1symbols_count[i]++;
            else if (crtNumSymbols<max_symbols)
            {
                l1symbols[crtNumSymbols] = l1nodes->node_id;
                l1symbols_count[crtNumSymbols] = 1;
                crtNumSymbols++;
            }
        }
        l1nodes = l1nodes->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_new_doc_continue
 * DESCRIPTION
 *  continue to process next application
 *  func shows MEM FULL / DONE / PROGRESSING dialog if needed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_new_doc_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const cca_app_config_struct *crtConfig;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_OMA_NEW_DOC_CONTINUE, cca_context_g.crtConfigIndex);

    crtConfig = &(cca_app_config_g[cca_context_g.crtConfigIndex]);
    if (mmi_cca_get_config_result(crtConfig->config_id) != CCA_STATUS_NOT_FOUND)
    {
        MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_OMA_NEW_DOC_CONTINUE_FIND_APP, crtConfig->config_id);
        
        /* add data account IDs to all referenced node if not yet done so */
        status = mmi_cca_oma_add_dataacctid_to_ref_nodes(cca_context_g.hConfig);

        /* go through config doc & mark nodes that are in this app's context */
        if (status == CCA_STATUS_OK)
            status = mmi_cca_oma_mark_in_app_context(cca_context_g.hConfig);

        if (status == CCA_STATUS_MEMFULL)
        {
            //mmi_cca_configure_complete();

            /* show mem full dialog */
            //mmi_cca_ui_handle_memfull();
            //return;
            mmi_cca_oma_handle_memfull(CCA_MFID_WITHIN_APP_CONFIGURE);
        }
        if (status == CCA_STATUS_OK)
        {
            /* send configure_ind to app */
            mmi_cca_register_memfull_notify(mmi_cca_oma_handle_memfull, CCA_MFID_WITHIN_APP_CONFIGURE);
            mmi_cca_send_app_configure_ind(cca_context_g.sim_id, crtConfig->config_id, cca_context_g.hConfig);
            return;
        }
    }
    mmi_cca_oma_new_doc_process_next_app();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_new_doc_process_next_app
 * DESCRIPTION
 *  continue to process next application
 *  func shows DONE dialog if needed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_new_doc_process_next_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_OMA_NEW_DOC_PROCESS_NEXT_APP, cca_context_g.crtConfigIndex+1);

    mmi_cca_deregister_memfull_notify(CCA_MFID_WITHIN_APP_CONFIGURE);

    /* next app in config list */
    cca_context_g.crtConfigIndex++;

    /* if next app found */
    if (cca_app_config_g[cca_context_g.crtConfigIndex].config_id != 0xFFFF && !cca_oma_memfull_flag)
    {
        /* send signal to itself to continue process */
        mmi_cca_send_new_doc_continue_ind();
    }
    /* no more app */
    else
    {
        mmi_cca_ui_entry_summary_report();
        if (cca_oma_memfull_flag)
        {
            cca_oma_memfull_flag = 0;
            mmi_cca_ui_handle_memfull();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_sort_new_doc
 * DESCRIPTION
 *  this function ensures all PROXY nodes are ahead of APPLICATION nodes
 * PARAMETERS
 *  hRoot     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_sort_new_doc(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *root;
    cca_doc_node_struct *proxys;
    cca_doc_node_struct *apps;
    cca_doc_node_struct *crt;
    cca_doc_node_struct *tmp;
    cca_doc_node_struct *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(hRoot);
    root = (cca_doc_node_struct*)hRoot;
    if (root->num_child <= 1)
        return;

    proxys = apps = prev = 0;
    crt = root->child;
    while (crt)
    {
        tmp = crt->next;
        if (crt->node_id==CCA_NS_OMA_PROXY || crt->node_id==CCA_NS_OMA_APPLICATION)
        {
            if (prev)
                prev->next = crt->next;
            else
                root->child = crt->next;
            crt->next = 0;

            if (crt->node_id==CCA_NS_OMA_PROXY)
                mmi_cca_doc_link_list_elem_to_last((cca_generic_ptr_struct**)&proxys, (cca_generic_ptr_struct*)crt);
            if (crt->node_id==CCA_NS_OMA_APPLICATION)
                mmi_cca_doc_link_list_elem_to_last((cca_generic_ptr_struct**)&apps, (cca_generic_ptr_struct*)crt);
        }
        else
            prev = crt;
        crt = tmp;
    }
    mmi_cca_doc_link_list_elem_to_last((cca_generic_ptr_struct**)&proxys, (cca_generic_ptr_struct*)apps);
    mmi_cca_doc_link_list_elem_to_last((cca_generic_ptr_struct**)&proxys, (cca_generic_ptr_struct*)(root->child));
    root->child = proxys;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_make_virtual_proxy_id
 * DESCRIPTION
 *  API to generate a PROXY ID for the Virtual Proxy based on the original TO-NAPID
 * PARAMETERS
 *  tonapid         [in]
 * RETURNS
 *  
 *****************************************************************************/
char* mmi_cca_oma_make_virtual_proxy_id(const char *tonapid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *newProxyID;
    S8 idPrefix[] = "@CCA@GEN@";
    int prefix_len, tonapid_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prefix_len = strlen(idPrefix);
    tonapid_len = strlen(tonapid);

    newProxyID = (S8*)mmi_cca_malloc(sizeof(S8)*(prefix_len+tonapid_len+1));
    memset(newProxyID, 0, sizeof(S8)*(prefix_len+tonapid_len+1));
    memcpy(newProxyID, idPrefix, prefix_len);
    memcpy(newProxyID+strlen(idPrefix), tonapid, tonapid_len);

    return newProxyID;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_generate_virtual_proxy_node
 * DESCRIPTION
 *  API to generate a virtual proxy node
 *  caller must NOT release the memory returned in "out_new_pxy_id"
 *  ie, caller must copy the data in "out_new_pxy_id" if it wishes to use it
 * PARAMETERS
 *  tonapid         [in]
 *  cca_node_id     [in]
 *  new_pxy_id      [out]
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_cca_oma_generate_virtual_proxy_node(const char *tonapid, const char *vrpxy_cca_node_id, char **out_new_pxy_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 vrProxy = 0;
    S32 hNodePort = 0;
    S8 *newProxyID = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (out_new_pxy_id)
        *out_new_pxy_id = 0;

    if ((vrProxy=mmi_cca_doc_new_node(CCA_NS_OMA_PROXY)) == 0)
        return 0;

    /* add CCA NODE_ID */
    if (mmi_cca_doc_add_nodedata_str(vrProxy, CCA_NS_NODEID, vrpxy_cca_node_id) == CCA_STATUS_MEMFULL)
        return 0;

    /* add PROXY-ID */
    newProxyID = (S8*)mmi_cca_oma_make_virtual_proxy_id(tonapid);
    if (mmi_cca_doc_add_nodedata_str(vrProxy, CCA_NS_OMA_PROXY_ID, newProxyID) == CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;
    mmi_cca_mfree(newProxyID);
    newProxyID = 0;

    /* add NAME */
    if (mmi_cca_doc_add_nodedata_str(vrProxy, CCA_NS_OMA_NAME, "Virtual Proxy") == CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;

    /* add PXADDR */
    if (mmi_cca_doc_add_nodedata_str(vrProxy, CCA_NS_OMA_PXADDR, "0.0.0.0") == CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;

    /* add PXADDR-TYPE */
    if (mmi_cca_doc_add_nodedata_int(vrProxy, CCA_NS_OMA_PXADDRTYPE, CCA_NS_VAL_IPV4) == CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;

    /* add TO-NAPID */
    if (mmi_cca_doc_add_nodedata_str(vrProxy, CCA_NS_OMA_TO_NAPID, (const S8*)tonapid) == CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;

    /* add PORT */
    if ((hNodePort=mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, vrProxy)) == 0)
        goto virtual_proxy_error;
    if (mmi_cca_doc_add_nodedata_str(hNodePort, CCA_NS_OMA_PORTNBR, "0") == CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;
    if (mmi_cca_doc_add_nodedata_int(hNodePort, CCA_NS_OMA_SERVICE, CCA_NS_VAL_OTA_HTTP_TO) == CCA_STATUS_MEMFULL)
        goto virtual_proxy_error;

    if (out_new_pxy_id)
        mmi_cca_doc_nodedata_str_first(vrProxy, CCA_NS_OMA_PROXY_ID, (S8**)out_new_pxy_id);

    return vrProxy;

virtual_proxy_error:
    if (newProxyID)
        mmi_cca_mfree(newProxyID);
    if (vrProxy)
        mmi_cca_doc_node_release_all(vrProxy);
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_attach_deprel_info_to_list
 * DESCRIPTION
 *  Attach a deprel info element to list
 * PARAMETERS
 *  listhead        [in]
 *  elem            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_attach_deprel_info_to_list(cca_oma_deprel_info_struct **listhead, cca_oma_deprel_info_struct *elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_doc_link_list_elem_to_last((cca_generic_ptr_struct**)listhead, (cca_generic_ptr_struct*)elem);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_new_deprel_info
 * DESCRIPTION
 *  Create a new deprel info element
 * PARAMETERS
 *  void
 * RETURNS
 *  0           memory full
 *  otherwise   created info elem
 *****************************************************************************/
cca_oma_deprel_info_struct* mmi_cca_oma_new_deprel_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_oma_deprel_info_struct *elem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elem = mmi_cca_malloc_type(cca_oma_deprel_info_struct);
    if (elem)
        memset(elem, 0, sizeof(cca_oma_deprel_info_struct));
    return elem;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_release_deprel_info
 * DESCRIPTION
 *  Release a new deprel info memory
 * PARAMETERS
 *  elem        [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_release_deprel_info(cca_oma_deprel_info_struct *elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!elem)
        return;

    /*if (elem->cca_node_id)
        mmi_cca_mfree(elem->cca_node_id);
    if (elem->oma_node_id)
        mmi_cca_mfree(elem->oma_node_id);
    if (elem->oma_ref_id)
        mmi_cca_mfree(elem->oma_ref_id);*/
    mmi_cca_mfree(elem);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_release_deprel_info_list
 * DESCRIPTION
 *  Release a new deprel info list memory
 * PARAMETERS
 *  listhead        [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_release_deprel_info_list(cca_oma_deprel_info_struct *listhead)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_oma_deprel_info_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (listhead)
    {
        next = listhead->next;
        mmi_cca_oma_release_deprel_info(listhead);
        listhead = next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_release_deprel_info_list
 * DESCRIPTION
 *  Release a new deprel info list memory
 * PARAMETERS
 *  listhead        [in]
 *  oma_node_id     [in]
 * RETURNS
 *  the matched deprel info, or 0 if not found
 *****************************************************************************/
cca_oma_deprel_info_struct* mmi_cca_oma_find_deprel_info(cca_oma_deprel_info_struct *listhead, S8 *oma_node_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (listhead)
    {
        if (listhead->oma_node_id && strcmp(listhead->oma_node_id, oma_node_id)==0)
            return listhead;
        listhead = listhead->next;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_deprel_populate_ref_ids
 * DESCRIPTION
 *  helper function to add deprel info data to list from multiple ref_ids
 * PARAMETERS
 *  listhead            [in]
 *  l1node              [in]
 *  oma_node_id_symbol  [in]    (CCA_NS__NULL if no oma_node_id)
 *  oma_ref_ids         [in]
 *  size                [in]
 * RETURNS
 *  CCA_STATUS_OK
 *  CCA_STATUS_MEMFULL
 *****************************************************************************/
cca_status_enum mmi_cca_oma_deprel_populate_ref_ids(cca_oma_deprel_info_struct **listhead, S32 l1node, U16 oma_node_id_symbol, S8 **oma_ref_ids, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    cca_oma_deprel_info_struct *tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!size)
    {
        tmp = mmi_cca_oma_new_deprel_info();
        if (!tmp)
            return CCA_STATUS_MEMFULL;

        tmp->hNode =(S32)l1node;
        if (mmi_cca_doc_nodedata_str_first((S32)l1node, CCA_NS_NODEID, &(tmp->cca_node_id)) != CCA_STATUS_OK)
        {
            mmi_cca_oma_release_deprel_info(tmp);
            return CCA_STATUS_MEMFULL;
        }
        if (oma_node_id_symbol != CCA_NS__NULL &&
            (mmi_cca_doc_nodedata_str_first((S32)l1node, oma_node_id_symbol, &(tmp->oma_node_id)) != CCA_STATUS_OK ||
             tmp->oma_node_id == 0))
        {
            mmi_cca_oma_release_deprel_info(tmp);
            return CCA_STATUS_MEMFULL;
        }
        mmi_cca_oma_attach_deprel_info_to_list(listhead, tmp);
        return CCA_STATUS_OK;
    }

    for (i=0; i<size; i++)
    {
        if (oma_ref_ids[i] == 0)
            continue;

        tmp = mmi_cca_oma_new_deprel_info();
        if (!tmp)
            return CCA_STATUS_MEMFULL;

        tmp->hNode =(S32)l1node;
        tmp->oma_ref_id = oma_ref_ids[i];

        if (mmi_cca_doc_nodedata_str_first((S32)l1node, CCA_NS_NODEID, &(tmp->cca_node_id)) != CCA_STATUS_OK)
        {
            mmi_cca_oma_release_deprel_info(tmp);
            continue;
        }
        if (oma_node_id_symbol != CCA_NS__NULL &&
            (mmi_cca_doc_nodedata_str_first((S32)l1node, oma_node_id_symbol, &(tmp->oma_node_id)) != CCA_STATUS_OK ||
             tmp->oma_node_id == 0))
        {
            mmi_cca_oma_release_deprel_info(tmp);
            continue;
        }

        mmi_cca_oma_attach_deprel_info_to_list(listhead, tmp);
    }
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_deprel_populate_lists
 * DESCRIPTION
 *  helper function to cross reference 2 deprel info lists and create deprel child and insert to deprel node
 * PARAMETERS
 *  deprel      [in]
 *  dep_id      [in]
 *  list1head   [in]
 *  list2head   [in]
 * RETURNS
 *  CCA_STATUS_OK
 *  CCA_STATUS_MEMFULL
 *****************************************************************************/
cca_status_enum mmi_cca_oma_deprel_populate_lists(S32 deprel, U16 dep_id, cca_oma_deprel_info_struct *list1head, cca_oma_deprel_info_struct *list2head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_oma_deprel_info_struct *tmp2;
    S32 deprel_child;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (list1head)
    {
        tmp2 = list2head;
        while (tmp2)
        {
            if (strcmp(list1head->oma_ref_id, tmp2->oma_node_id) == 0)
            {
                deprel_child = mmi_cca_oma_new_deprel_child(dep_id, list1head->cca_node_id, tmp2->cca_node_id, list1head->hNode);
                if (!deprel_child)
                    return CCA_STATUS_MEMFULL;
                mmi_cca_doc_attach_node_to_parent(deprel_child, deprel);
                break;
            }
            tmp2 = tmp2->next;
        }
        list1head = list1head->next;
    }
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_generate_deprel_node
 * DESCRIPTION
 *  API to generate dependency relationship node given the document ROOT node
 *  this API would only consider the dependency relationship between:
 *      PROXY->NAPDEF
 *      APPLICATION->PROXY
 * PARAMETERS
 *  hRoot       [in]
 * RETURNS
 *  0           invalid hRoot / memory full
 *****************************************************************************/
S32 mmi_cca_oma_generate_deprel_node(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 deprel = 0;
    cca_doc_node_struct *l1node;
    cca_oma_deprel_info_struct *pxylist = 0;
    cca_oma_deprel_info_struct *naplist = 0;
    cca_oma_deprel_info_struct *applist = 0;
    S8 **values;
    S32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hRoot)
        return 0;

    deprel = mmi_cca_doc_new_node(CCA_NS_DEPREL);
    if (!deprel)
        return 0;

    l1node = ((cca_doc_node_struct*)hRoot)->child;
    if (!l1node)
        return deprel;

    while (l1node)
    {
        if (l1node->node_id == CCA_NS_OMA_PROXY &&
            mmi_cca_doc_nodedata_strs((S32)l1node, CCA_NS_OMA_TO_NAPID, &values, &size) == CCA_STATUS_OK)
        {
            if (mmi_cca_oma_deprel_populate_ref_ids(&pxylist, (S32)l1node, CCA_NS_OMA_PROXY_ID, values, size) == CCA_STATUS_MEMFULL)
                goto mmi_cca_oma_new_deprel_child_error;
        }
        else if (l1node->node_id == CCA_NS_OMA_APPLICATION &&
            mmi_cca_doc_nodedata_strs((S32)l1node, CCA_NS_OMA_TO_PROXY, &values, &size) == CCA_STATUS_OK)
        {
            if (mmi_cca_oma_deprel_populate_ref_ids(&applist, (S32)l1node, CCA_NS__NULL, values, size) == CCA_STATUS_MEMFULL)
                goto mmi_cca_oma_new_deprel_child_error;
        }
        else if (l1node->node_id == CCA_NS_OMA_NAPDEF)
        {
            if (mmi_cca_oma_deprel_populate_ref_ids(&naplist, (S32)l1node, CCA_NS_OMA_NAPID, 0, 0) == CCA_STATUS_MEMFULL)
                goto mmi_cca_oma_new_deprel_child_error;
        }
        l1node = l1node->next;
    }
    if (mmi_cca_oma_deprel_populate_lists(deprel, CCA_NS_DEP_PROXY, pxylist, naplist) == CCA_STATUS_MEMFULL)
        goto mmi_cca_oma_new_deprel_child_error;
    if (mmi_cca_oma_deprel_populate_lists(deprel, CCA_NS_DEP_APPLICATION, applist, pxylist) == CCA_STATUS_MEMFULL)
        goto mmi_cca_oma_new_deprel_child_error;

    mmi_cca_oma_release_deprel_info_list(pxylist);
    mmi_cca_oma_release_deprel_info_list(naplist);
    mmi_cca_oma_release_deprel_info_list(applist);
    return deprel;

mmi_cca_oma_new_deprel_child_error:
    mmi_cca_doc_node_release_all(deprel);
    mmi_cca_oma_release_deprel_info_list(pxylist);
    mmi_cca_oma_release_deprel_info_list(naplist);
    mmi_cca_oma_release_deprel_info_list(applist);
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_validate_param_values
 * DESCRIPTION
 *  helper function to check if the values of the specified parameter are valid
 *  if value is NULL or value is "\0", remove it, so do not use this api to remove
 *  those valid param without values, such as STARTPAGE parameter.
 * PARAMETERS
 *  hNode       [in]
 *  param       [in]
 * RETURNS
 *  0           no valid value
 *  1           all values are valid
 *****************************************************************************/
S32 mmi_cca_oma_validate_param_values(S32 hNode, U16 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cca_doc_nodedata_by_param(hNode, param, &coredata) == CCA_STATUS_NOT_FOUND)
        return 0;
    else if (!coredata || !(coredata->size) || !(coredata->values.s))
        return 0;
    else if (mmi_cca_doc_coredata_remove_value(coredata, CCA_DT_STR, 0) && !(coredata->size))
        return 0;
    else if (mmi_cca_doc_coredata_remove_value(coredata, CCA_DT_STR, "\0") && !(coredata->size)) 
        return 0;
    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_validate_add_id
 * DESCRIPTION
 *  helper function to add a value to predefined array
 * PARAMETERS
 *  dataarray   [in]
 *  count       [in]
 *  total       [in]
 *  data        [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_validate_add_id(S8** dataarray, S32 count, S32 total, S8* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (count >= total)
    {
        MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_OMA_VALIDATE_ADD_ID, count, total);
        return;
    }
    
    dataarray[count] = data;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_validate_find_id
 * DESCRIPTION
 *  helper function to check whether the value can be found in array
 * PARAMETERS
 *  dataarray   [in]
 *  count       [in]
 *  id          [in]
 * RETURNS
 *  0 if not found
 *  1 if found
 *****************************************************************************/
U8 mmi_cca_oma_validate_find_id(S8** dataarray, S32 count, S8 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<count; i++)
    {
        if (strcmp(dataarray[i], id) == 0)
            return 1;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_validate_add_node
 * DESCRIPTION
 *  helper function to add a node to predefined array
 * PARAMETERS
 *  dataarray   [in]
 *  count       [in]
 *  total       [in]
 *  hNode       [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_validate_add_node(S32* dataarray, S32 count, S32 total, S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (count >= total)
    {
        MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_OMA_VALIDATE_ADD_NODE, count, total);
        return;
    }
    
    dataarray[count] = hNode;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_validate_find_node
 * DESCRIPTION
 *  helper function to check whether the given node contains duplicated data to those stored in array
 * PARAMETERS
 *  dataarray   [in]
 *  count       [in]
 *  hNode       [in]
 * RETURNS
 *  0 if not found
 *  1 if found
 *****************************************************************************/
U8 mmi_cca_oma_validate_find_node(S32* dataarray, S32 count, S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<count; i++)
    {
        if (mmi_cca_doc_node_check_equal_content(dataarray[i], hNode))
            return 1;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_remove_duplicate_port
 * DESCRIPTION
 *  helper function to check and remove duplicated PORT node within the specified parent node
 * PARAMETERS
 *  hParentNode     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_remove_duplicate_port(S32 hParentNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *child;
    cca_doc_node_struct *next;
    S32 portnodes[20];
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hParentNode)
        return;

    memset(portnodes, 0, 20*sizeof(S32));
    child = ((cca_doc_node_struct*)hParentNode)->child;
    while (child)
    {
        if (child->node_id==CCA_NS_OMA_PORT)
        {
            if (mmi_cca_oma_validate_find_node((S32*)portnodes, count, (S32)child))
            {
                next = child->next;
                mmi_cca_doc_node_release_all((S32)child);
                child = next;
                continue;
            }
            else
            {
                mmi_cca_oma_validate_add_node((S32*)portnodes, count++, 20, (S32)child);
            }
        }
        child = child->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_fix_doc
 * DESCRIPTION
 *  API to fix OMA document by
 *      - remove NAPDEF with no NAPID or NAPID is empty string("\0")
 *      - remove NAPDEF with duplicated NAPID
 *      - remove PROXY with no PROXY-ID or PROXY-ID is empty string("\0")
 *      - remove PROXY with duplicated PROXY-ID
 *      - remove PROXY with no TO-NAPID or TO-NAPId is empty string("\0")
 *      - remove PROXY with unmatched TO-NAPID
 *      - remove APPLICATION with no APPID or APPId is empty string("\0")
 *      - remove duplicated PORT node in PROXY
 * PARAMETERS
 *  hRoot       [in]
 * RETURNS
 *  0           document unchanged
 *  1           document modified
 *****************************************************************************/
S32 mmi_cca_oma_fix_doc(S32 hRoot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_doc_node_struct *l1node, *next;
    cca_core_data_struct *coredata;
    S8 *napids[20];
    S8 *proxyids[20];
    U8 remove;
    U8 docChanged = 0;
    S32 i, napidcount, proxyidcount;
    S32 napdef;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hRoot || !(((cca_doc_node_struct*)hRoot)->num_child))
        return 0;
    
    napidcount = 0;
    proxyidcount = 0;
    memset(napids, 0, 20*sizeof(S8*));
    memset(proxyids, 0, 20*sizeof(S8*));
    l1node = ((cca_doc_node_struct*)hRoot)->child;
    while (l1node)
    {
        remove = 0;
        coredata = 0;
        switch (l1node->node_id)
        {
            case CCA_NS_OMA_NAPDEF:
                /* remove NAPDEF with no NAPID or empty NAPID*/
                if (!mmi_cca_oma_validate_param_values((S32)l1node, CCA_NS_OMA_NAPID))
                {
                    remove = 1;
                    break;
                }

                /* remove NAPDEF with duplicated NAPID */
                mmi_cca_doc_nodedata_by_param((S32)l1node, CCA_NS_OMA_NAPID, &coredata);
                if (!mmi_cca_oma_validate_find_id((S8**)napids, napidcount, coredata->values.s[0]))
                {
                    mmi_cca_oma_validate_add_id((S8**)napids, napidcount++, 20, coredata->values.s[0]);
                }
                else
                {
                    remove = 1;
                    break;
                }
                break;

            case CCA_NS_OMA_PROXY:
                /* remove PROXY with no PROXY-ID or empty PROXY-ID or with no TO-NAPID or empty TO-NAPID */
                if (!mmi_cca_oma_validate_param_values((S32)l1node, CCA_NS_OMA_PROXY_ID) ||
                    !mmi_cca_oma_validate_param_values((S32)l1node, CCA_NS_OMA_TO_NAPID))
                {
                    remove = 1;
                    break;
                }

                /* remove PROXY with unmatched TO-NAPID */
                mmi_cca_doc_nodedata_by_param((S32)l1node, CCA_NS_OMA_TO_NAPID, &coredata);
                for (i=0; i<coredata->size; i++)
                {
                    napdef = mmi_cca_doc_find_node_match_param_value(
                                (S32)((cca_doc_node_struct*)hRoot)->child,
                                CCA_NS_OMA_NAPDEF,
                                CCA_NS_OMA_NAPID,
                                CCA_DT_STR,
                                (void*)coredata->values.s[i]);
                    if (!napdef &&
                        mmi_cca_doc_coredata_remove_value(coredata, CCA_DT_STR, (void*)coredata->values.s[i]))
                    {
                        i--;
                    }
                }
                if (!(coredata->size))
                {
                    remove = 1;
                    break;
                }

                /* remove PROXY with duplicated PROXY-ID */
                mmi_cca_doc_nodedata_by_param((S32)l1node, CCA_NS_OMA_PROXY_ID, &coredata);
                if (!mmi_cca_oma_validate_find_id((S8**)proxyids, proxyidcount, coredata->values.s[0]))
                {
                    mmi_cca_oma_validate_add_id((S8**)proxyids, proxyidcount++, 20, coredata->values.s[0]);
                }
                else
                {
                    remove = 1;
                    break;
                }

                /* remove duplicated PORT node in PROXY */
                mmi_cca_oma_remove_duplicate_port((S32)l1node);
                break;

            case CCA_NS_OMA_APPLICATION:
                /* remove APPLICATION with no APPID or empty APPID */
                if (!mmi_cca_oma_validate_param_values((S32)l1node, CCA_NS_OMA_APPID))
                {
                    remove = 1;
                    break;
                }
                break;
        }
    
        next = l1node->next;
        if (remove)
        {
            mmi_cca_doc_node_release_all((S32)l1node);
            docChanged = 1;
        }
        l1node = next;
    }

    return docChanged;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_oma_handle_new_doc
 * DESCRIPTION
 *  handle new OMA doc
 *  func shows MEM FULL / DONE dialog if needed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_oma_handle_new_doc(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_oma_sort_new_doc((S32)((cca_document_struct*)hConfig)->doc_tree);

    /* log the whole cca doc*/
    MMI_CCA_LOG_DOC(hConfig);

    mmi_cca_ui_entry_settings_info();
}

#endif  /* __MMI_CCA_SUPPORT__ */




