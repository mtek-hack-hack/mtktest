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
















#ifndef _brs_dcmn_h
#define _brs_dcmn_h

#ifndef _brs_cfg_h
#include "brs_cfg.h"
#endif




typedef struct brs_d_object_select_event_st  brs_d_object_select_event_t;
typedef struct brs_d_doc_st                  brs_d_doc_t;
typedef struct brs_dt_tree_node_st           brs_dt_tree_node_t;
typedef struct brs_dt_element_st             brs_dt_element_t;
typedef struct brs_dt_tree_walker_st         brs_dt_tree_walker_t;
typedef struct brs_dt_node_iterator_st       brs_dt_node_iterator_t;
typedef struct brs_d_work_item_st            brs_d_work_item_t;
typedef struct brs_d_link_ref_st             brs_d_link_ref_t;
typedef struct brs_d_le_obj_ref_st           brs_d_le_obj_ref_t;
typedef struct brs_d_obj_ref_st              brs_d_obj_ref_t;
typedef struct brs_d_sas_priv_data_st        brs_d_sas_priv_data_t;
typedef void   brs_d_node_action_function_t (brs_d_doc_t *d, brs_dt_tree_node_t *n, int is_entry);
typedef struct brs_d_list_index_st           brs_d_list_index_t;
typedef struct brs_d_image_map_st            brs_d_image_map_t;
typedef struct brs_d_area_def_st             brs_d_area_def_t;
typedef struct brs_d_client_image_map_st     brs_d_client_image_map_t;
typedef struct brs_d_server_image_map_st     brs_d_server_image_map_t;
typedef struct brs_d_file_upload_st          brs_d_file_upload_t;



typedef enum
{
	INPUT_ERR_GENERAL,
	INPUT_ERR_EMPTY,
	INPUT_ERR_LENGTH,
	INPUT_ERR_NUMERIC,
	INPUT_ERR_UPPER,
	INPUT_ERR_LOWER,
	INPUT_ERR_NUMERIC_PUNCT,
	INPUT_ERR_UPPER_PUNCT,
	INPUT_ERR_LOWER_PUNCT
} brs_input_validation_error_t;

#ifdef BRS_CONFIG_WML
typedef struct brs_d_wml_template_do_st      brs_d_wml_do_t;
#endif


#endif
