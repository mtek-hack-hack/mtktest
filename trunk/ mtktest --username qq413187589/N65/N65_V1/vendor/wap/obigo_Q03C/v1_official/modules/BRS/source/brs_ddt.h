/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */







































#ifndef _brs_ddt_h
#define _brs_ddt_h

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif

#ifndef _msf_prsr_h
#include "msf_prsr.h"
#endif

#ifndef _brs_memp_h
#include "brs_memp.h"
#endif









#define BRS_DT_ELEMENT_NODE          0x01
#define BRS_DT_CDATA_NRML_NODE       0x02
#define BRS_DT_CDATA_PRSV_NODE       0x04
#define BRS_DT_ATTRIBUTE_NODE        0x08
#define BRS_DT_VARIABLE_ESC_NODE     0x10
#define BRS_DT_VARIABLE_UNESC_NODE   0x20
#define BRS_DT_VARIABLE_NOESC_NODE   0x40





#define BRS_DT_FILTER_ACCEPT 0x01
#define BRS_DT_FILTER_REJECT 0x02
#define BRS_DT_FILTER_SKIP   0x04






#define BRS_DT_SHOW_ALL                     0xFF
#define BRS_DT_SHOW_ELEMENT                 BRS_DT_ELEMENT_NODE
#define BRS_DT_SHOW_NORMALIZED_TEXT         BRS_DT_CDATA_NRML_NODE
#define BRS_DT_SHOW_PRESERVED_TEXT          BRS_DT_CDATA_PRSV_NODE
#define BRS_DT_SHOW_TEXT                    (BRS_DT_CDATA_NRML_NODE |\
                                             BRS_DT_CDATA_PRSV_NODE)
#define BRS_DT_SHOW_ATTRIBUTE               BRS_DT_ATTRIBUTE_NODE
#define BRS_DT_SHOW_VARIABLES               (BRS_DT_VARIABLE_ESC_NODE |\
                                             BRS_DT_VARIABLE_NOESC_NODE |\
                                             BRS_DT_VARIABLE_UNESC_NODE)
#define BRS_DT_SHOW_TEXT_OR_VARIABLES       (BRS_DT_SHOW_TEXT |\
                                             BRS_DT_SHOW_VARIABLES)

















#define BRS_DT_ROOT_NODE(t) ((t)->parent == NULL)
#define BRS_DT_LAST_NODE(t) ((t)->next == NULL)
#define BRS_DT_EMPTY_NODE(t) ((t)->content == NULL)

















struct brs_dt_tree_node_st
{
  struct brs_dt_tree_node_st  *parent;
  struct brs_dt_tree_node_st  *next;
  struct brs_dt_tree_node_st  *content;
  void                        *data;       
  int                          node_type;  
  void                        *ledata;     
};


typedef int brs_dt_elem_type_t;









struct brs_dt_element_st
{
  brs_dt_elem_type_t     element_type; 
  int                    handle;          

  char                  *current_value;   
  msf_prsr_attribute_t  *attribute_list;  
  int                    n_attributes;
};





typedef enum brs_dt_tree_build_state_st
{
  Null_s,                       
  Start_s,                      
  End_s,                        
  Chardata_s,                   
  TreeComplete_s                
} brs_dt_tree_build_state_t;









typedef struct brs_dt_document_st
{
  brs_dt_tree_build_state_t   state;
  brs_dt_tree_node_t         *current_node;
  brs_dt_tree_node_t         *tree_root;
  brs_mempool_t               mempool;
} brs_dt_document_t;











































































typedef
int
(brs_dt_node_filter_function_t) (brs_dt_tree_node_t *n);




struct brs_dt_node_iterator_st
{
  
  brs_dt_tree_node_t             *root;
  int                             what_to_show;
  brs_dt_node_filter_function_t  *filter;
  int                             expand_entity_ref;

  
  brs_dt_tree_node_t    *current_node;
  int                    state;
};




struct brs_dt_tree_walker_st
{
  
  brs_dt_tree_node_t    *root;
  brs_dt_tree_node_t    *current_node;
  
  
  int                              state;
  int                              what_to_show;
  brs_dt_node_filter_function_t   *filter;
  int                              expand_entity_ref;
};









void
brs_dt_init_document (brs_dt_document_t *doc);

void
brs_dt_clean_document (brs_dt_document_t *doc);













void
brs_dt_add_content (brs_dt_tree_node_t *t, brs_dt_tree_node_t *n);
 






void
brs_dt_add_next (brs_dt_tree_node_t *t, brs_dt_tree_node_t *n);






int
brs_dt_convert_chardata_tree (brs_dt_tree_node_t *root, msf_charset_convert_t *converter);






brs_dt_tree_node_t *
brs_dt_new_element_node (int                   type,
                         msf_prsr_attribute_t *attrs,
                         int                   size,
                         brs_dt_document_t    *doc);





brs_dt_tree_node_t *
brs_dt_new_chardata_node (const char *wd, int cdata_type, brs_dt_document_t *doc);




void
brs_dt_delete_node (brs_dt_tree_node_t *t);





brs_dt_element_t*
brs_dt_copy_element (brs_dt_element_t *e);

























brs_dt_node_iterator_t*
brs_dt_create_node_iterator (brs_dt_tree_node_t            *root,
                             int                            what_to_show,
                             brs_dt_node_filter_function_t *filter,
                             int                            expand_entity_ref);




void
brs_dt_init_node_iterator (brs_dt_node_iterator_t *iter,
                           brs_dt_tree_node_t *root, int what_to_show,
                           brs_dt_node_filter_function_t *filter, 
                           int expand_entity_ref);




void
brs_dt_delete_node_iterator (brs_dt_node_iterator_t *it);









brs_dt_tree_node_t*
brs_dt_node_iter_next_node (brs_dt_node_iterator_t *iter);







brs_dt_tree_node_t*
brs_dt_node_iter_previous_node (brs_dt_node_iterator_t *iter);




void
brs_dt_node_iter_detach (brs_dt_node_iterator_t *iter);























brs_dt_tree_walker_t*
brs_dt_create_tree_walker (brs_dt_tree_node_t            *root,
                           int                            what_to_show,
                           brs_dt_node_filter_function_t *filter,
                           int                            expand_entity_ref);




void
brs_dt_init_tree_walker (brs_dt_tree_walker_t *tw,
                         brs_dt_tree_node_t *root, int what_to_show,
                         brs_dt_node_filter_function_t *filter,
                         int expand_entity_ref);




void
brs_dt_delete_tree_walker (brs_dt_tree_walker_t *tw);








brs_dt_tree_node_t*
brs_dt_tw_parent_node (brs_dt_tree_walker_t *tw);







brs_dt_tree_node_t*
brs_dt_tw_first_child (brs_dt_tree_walker_t *tw);






brs_dt_tree_node_t*
brs_dt_tw_last_child (brs_dt_tree_walker_t *tw);






brs_dt_tree_node_t*
brs_dt_tw_previous_sibling (brs_dt_tree_walker_t *tw);






brs_dt_tree_node_t*
brs_dt_tw_next_sibling (brs_dt_tree_walker_t *tw);








brs_dt_tree_node_t*
brs_dt_tw_previous_node (brs_dt_tree_walker_t *tw);







brs_dt_tree_node_t*
brs_dt_tw_next_node (brs_dt_tree_walker_t *tw);




brs_dt_tree_node_t*
brs_dt_tw_get_current_node (brs_dt_tree_walker_t *tw);





void
brs_dt_tw_set_current_node (brs_dt_tree_walker_t *tw, brs_dt_tree_node_t   *n);






void
brs_dt_handle_wml_extra_cell (brs_dt_document_t *doc,
                              brs_dt_tree_node_t *dst, brs_dt_tree_node_t *src);

void
brs_dt_append_child (brs_dt_tree_node_t *ref_node, brs_dt_tree_node_t *new_child);


#endif
