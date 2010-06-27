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








#ifndef _brs_ltbl_h
#define _brs_ltbl_h

#ifndef _brd_ddt_h
#include "brs_ddt.h"
#endif
#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif









void
brs_le_tbl_leaf_min_max (brs_dt_tree_node_t *node, brs_le_render_t *rend,
                         int min_width, int max_width);




void
brs_le_tbl_report_baseline (brs_le_render_t *rend, int ascent);









void
brs_le_tbl_free_table (brs_le_table_t *e_table);




int
brs_le_tbl_enter_element (brs_dt_tree_node_t *node, brs_le_render_t *view);




void
brs_le_tbl_leave_element (brs_dt_tree_node_t *node, brs_le_render_t *view);




void
brs_le_tbl_render_table (brs_dt_tree_node_t *node, brs_le_render_t *view);




void
brs_le_tbl_leave_render_table (brs_dt_tree_node_t *node, brs_le_render_t *view);









void
brs_le_tbl_render_caption (brs_dt_tree_node_t *node, brs_le_render_t *view);




void
brs_le_tbl_leave_render_caption (brs_dt_tree_node_t *node, brs_le_render_t *view);









void
brs_le_tbl_render_tr (brs_dt_tree_node_t *node, brs_le_render_t *view);




void
brs_le_tbl_leave_render_tr (brs_dt_tree_node_t *node, brs_le_render_t *view);









void
brs_le_tbl_render_tc (brs_dt_tree_node_t *node, brs_le_render_t *view);




void
brs_le_tbl_leave_render_tc (brs_dt_tree_node_t *node, brs_le_render_t *view);









void
brs_le_tbl_add_table_attributes (brs_le_render_t *rend, brs_dt_tree_node_t *node,
                                 char *buffer, int *pos);




void
brs_le_tbl_add_caption_attributes (brs_le_render_t *rend, brs_dt_tree_node_t *node,
                                   char *buffer, int *pos);




void
brs_le_tbl_add_cell_attributes (brs_le_render_t *rend, brs_dt_tree_node_t *node,
                                char *buffer, int *pos);

#endif
