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








#ifndef _brs_lrnd_h
#define _brs_lrnd_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif

#ifndef _brs_lbxt_h
#include "brs_lbxt.h"
#endif
















void
brs_le_output_box(brs_le_boxt_box_t* box, brs_le_render_t* rend);




void
brs_le_output_floated_box(brs_le_boxt_box_t* box, brs_le_render_t* rend, int is_unclean);





brs_le_open_block_box_t*
brs_le_add_block_box (brs_le_render_t* rend, brs_le_open_block_box_t** containing_block);


void
brs_le_remove_block_box(brs_le_render_t* rend);





brs_le_open_inline_box_t*
brs_le_add_inline_box (brs_le_render_t* rend, brs_le_open_inline_box_t** inline_parent);


void
brs_le_remove_inline_box(brs_le_render_t* rend);






void
brs_le_init_align_inline_stacks(brs_le_render_t* rend);





void
brs_le_init_box_stacks(brs_le_render_t* rend);


void
brs_le_free_float_list(brs_le_render_boxes_t* boxes);




void
brs_le_free_inline_box_stack (brs_le_open_inline_box_stack_t* inline_boxes);




void
brs_le_free_box_stacks(brs_le_render_t* rend);




void
brs_le_free_float_box_stacks(brs_le_render_t* rend);




int
brs_le_next_line_width(brs_le_render_t* rend);



int
brs_le_init_line(int is_first, 
                 brs_le_render_t* rend, 
                 int block_height, 
                 int update_floats,
                 int is_final,
                 int is_table_cell_first);


int
brs_le_line_is_complete(brs_le_render_t* rend);








int
brs_le_push_align_stack(brs_le_open_inline_box_t* inl, brs_le_render_t* rend);




void
brs_le_pop_align_stack_children(int index, brs_le_render_t* rend);




void
brs_le_pop_align_stack(brs_le_render_t* rend);




void
brs_le_set_align_item_adh(int index, int a, int d, int h, brs_le_render_t* rend);




void
brs_le_set_align_item_xy(int index, int* x, int* y, brs_le_render_t* rend);






void
brs_le_align_box(brs_le_open_inline_box_t* inl, brs_le_render_t* rend, int is_final);





void
brs_le_report_inline_width(brs_le_open_inline_box_t* inl, 
                           brs_le_render_t* rend,
                           int is_complete);






void
brs_le_report_inline_space (brs_le_render_t* rend, int w);








void
brs_le_report_inline_height(brs_le_align_item_t* child_align_data,
                            brs_le_align_item_t* parent_align_data,
                            int* parent_changed);





void
brs_le_line_create_bdp_stack(brs_le_line_t* line);














void
brs_le_line_break(brs_le_render_t* rend, int is_final);




void
brs_le_require_line_break (brs_dt_tree_node_t* node,
                           brs_le_render_t* rend,
                           int is_final);






void
brs_le_line_report_space_w_parent(brs_le_open_inline_box_t* inl,
                                  brs_le_render_t* rend);


void
brs_le_line_add_inline_box(brs_le_open_inline_box_t* inl,
                           int is_replaced,
                           brs_le_render_t* rend);

void
brs_le_init_element_base_data(brs_dt_tree_node_t* node, brs_le_render_t* rend, brs_css_stack_t* stack);



int
brs_le_collapse_margins(int m1, int m2);





void
brs_le_set_block_x_pos_width(brs_le_boxt_box_t* b,
                             brs_le_boxt_box_t* cb,
                             brs_dt_tree_node_t* node, 
                             brs_le_render_t* rend,
                             int width,
                             int width_auto,
                             int table_b_left,
                             int table_b_right);

void
brs_le_set_block_width_height_xpos(brs_le_boxt_box_t* b,
                                   brs_le_boxt_box_t* cb,
                                   brs_dt_tree_node_t* node, 
                                   brs_le_render_t* rend);






void
brs_le_flow_enter_blocklike_cmmn(brs_le_boxt_box_t* b,
                                 brs_le_render_t* rend);











void
brs_le_flow_leave_blocklike_cmmn(brs_le_boxt_box_t* b,
                                 brs_le_render_t* rend);


#endif
