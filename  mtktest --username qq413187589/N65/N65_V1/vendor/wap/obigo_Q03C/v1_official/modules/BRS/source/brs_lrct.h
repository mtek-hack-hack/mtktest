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








#ifndef _brs_lrct_h
#define _brs_lrct_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif

#ifndef _brs_lbxt_h
#include "brs_lbxt.h"
#endif
















int
brs_le_init_render (brs_le_render_t*      render_view,
                    brs_dt_tree_node_t*   start_node,
                    int                   force_rerender);







int
brs_le_check_rerender (brs_le_render_t*    render_view,
                       brs_dt_tree_node_t* node);







int
brs_le_node_changed (brs_le_render_t*    render_view,
                     brs_dt_tree_node_t* node);







int
brs_le_do_render (brs_le_render_t* render_view);







int
brs_le_cancel_render (brs_le_render_t* render_view);





void
brs_le_free_render (brs_le_render_t* render_view);





void
brs_le_clean_render(brs_le_render_t* render_view);




void
brs_le_clean_box_tree(brs_le_render_t* rend);









void
brs_le_flow_enter_block(brs_dt_tree_node_t* node, 
                        brs_le_render_t* rend,
                        int w,
                        int a,
                        int d,
                        int h,
                        brs_le_boxt_box_t* use_box,
                        int render_replaced_inline);





void
brs_le_flow_leave_block(brs_dt_tree_node_t* node, 
                        brs_le_render_t* rend);

brs_le_state_item_t*
brs_le_pop_state(brs_le_render_t* render_view);

void
brs_le_push_state(brs_le_render_t* render_view, brs_le_state_item_t* item);

brs_le_state_item_t*
brs_le_create_state(int state, 
                    brs_dt_tree_node_t* first, 
                    brs_dt_tree_node_t* last,
                    brs_le_post_action_t* post_action);


#endif
