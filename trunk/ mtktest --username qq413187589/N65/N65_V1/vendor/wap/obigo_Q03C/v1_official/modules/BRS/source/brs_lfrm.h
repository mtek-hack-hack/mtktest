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






#ifndef _brs_lfrm_h
#define _brs_lfrm_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif

#ifndef _brs_ddt_h
#include "brs_ddt.h"
#endif










void
brs_le_init_check_radio_icons(void);


void
brs_le_terminate_check_radio_icons(void);


int
brs_le_render_input(brs_dt_tree_node_t* node, brs_le_render_t* view, int* w, int* a, int* d, int* h);


void
brs_le_draw_input_box(brs_le_boxt_box_t* box, brs_le_draw_t* draw);


void
brs_le_render_label(brs_dt_tree_node_t* node, brs_le_render_t* view);


void
brs_le_min_max_label(brs_dt_tree_node_t* node, brs_le_render_t* view);

int
brs_le_render_do(brs_dt_tree_node_t* node, brs_le_render_t* view, int* w, int* a, int* d, int* h);


void
brs_le_draw_do_box(brs_le_boxt_box_t* box, brs_le_draw_t* draw);


void
brs_le_leave_min_max_input(brs_dt_tree_node_t* node, brs_le_render_t* view);


void
brs_le_min_max_input(brs_dt_tree_node_t* node, brs_le_render_t* view);


void
brs_le_min_max_do(brs_dt_tree_node_t* node, brs_le_render_t* view);


void
brs_le_reset_ctrl(brs_dt_tree_node_t* node, brs_le_event_t* view);


void
brs_le_render_select(brs_dt_tree_node_t* node, brs_le_render_t* view, int* w, int* a, int* d, int* h);





void
brs_le_select_option_in_select(brs_dt_tree_node_t* select, brs_le_event_t* evt, int is_action);


void
brs_le_select_option(brs_dt_tree_node_t* option, brs_le_event_t* evt);


void
brs_le_draw_select_box(brs_le_boxt_box_t* box, brs_le_draw_t* draw);






void
brs_le_handle_select_resize(brs_dt_tree_node_t* node, brs_le_view_t* view);


void
brs_le_min_max_select(brs_dt_tree_node_t* node, brs_le_render_t* view);





void
brs_le_free_frm (void* obj, brs_dt_elem_type_t type);







void
brs_le_unset_input(brs_dt_tree_node_t* node, int reset_value);




void
brs_le_draw_accesskey_box(brs_le_boxt_box_t* box, brs_le_draw_t* draw);



void
brs_le_activate_input_dialog(MSF_UINT32 msg, int type, brs_dt_tree_node_t* node, brs_le_view_t* view);








int
brs_le_check_input_vs_format(brs_dt_tree_node_t* node, brs_le_render_t* rend);






int
brs_le_input_image_updated(brs_le_view_t*      view,
                           brs_dt_tree_node_t* node, 
                           MsfImageHandle      handle);
#endif
