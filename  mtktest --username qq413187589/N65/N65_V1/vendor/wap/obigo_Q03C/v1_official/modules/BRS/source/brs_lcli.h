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


















#ifndef _brs_lcli_h
#define _brs_lcli_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif






#define BRS_IS_NUMERIC_LIST_TYPE(x) (x != BRS_CSS_VALUE_DISC && \
 x != BRS_CSS_VALUE_CIRCLE && x != BRS_CSS_VALUE_SQUARE && x != BRS_CSS_VALUE_NONE)

typedef struct {
  int type;
  MSF_UINT32 handle;
  




  brs_dt_tree_node_t* bg_from;
} brs_le_elem_list_item_t;

typedef struct brs_le_elem_list_st brs_le_elem_list_t;






void
brs_le_init_list_icons(void);


void
brs_le_terminate_list_icons(void);


void
brs_le_add_list_level(brs_le_render_t* view);


void
brs_le_remove_list_level(brs_le_render_t* view);


void
brs_le_set_list_item_value(brs_le_render_t* view, int new_value);



void
brs_le_render_list(brs_dt_tree_node_t* node, 
                   brs_le_render_t* view);





void
brs_le_free_list (brs_le_elem_list_t* list);




void
brs_le_free_list_item_marker(void* data);


void
brs_le_free_list_style_images (brs_le_view_t* view);






int
brs_le_list_item_updated (brs_le_view_t*      view,
                          brs_dt_tree_node_t* node, 
                          MsfImageHandle      handle);



brs_le_elem_list_item_t*
brs_le_create_list_item_marker(brs_dt_tree_node_t* node, 
                               brs_le_render_t* rend);



void
brs_le_get_list_item_marker_size(brs_le_render_t* rend,
                                 int* w,
                                 int* a,
                                 int* d,
                                 brs_le_elem_list_item_t* marker,
                                 brs_dt_tree_node_t* node);





int
brs_le_li_marker_position(brs_dt_tree_node_t* node,
                          brs_le_render_t* rend,
                          int width,
                          brs_dt_tree_node_t** bg_css_from);









void
brs_le_li_adjust_marker_vertically(brs_le_render_t* rend, int baseline_vs_li);


void
brs_le_draw_li_marker_box(brs_le_boxt_box_t* box, brs_le_draw_t* draw);

#endif
