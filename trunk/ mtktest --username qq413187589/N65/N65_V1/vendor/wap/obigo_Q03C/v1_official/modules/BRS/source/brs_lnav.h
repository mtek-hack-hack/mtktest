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








#ifndef _brs_lnav_h
#define _brs_lnav_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif
 





#ifdef BRS_CFG_LE_SUPPORT_KEY_NAVIGATION
void
brs_le_key_navigate (brs_le_event_t* evt, MsfEvent* event);





int
brs_le_is_markable(brs_le_event_t* evt, brs_dt_tree_node_t* node);


#ifdef BRS_CFG_LE_MOVE_GADGET_FOCUS_ON_OK
void
brs_le_navigate_to_next_visible_markable_element (brs_le_event_t* evt);
#endif
#ifdef BRS_CFG_LE_SUPPORT_KEY_NAVIGATION_4WKEY





brs_le_boxt_box_t*
brs_le_4wkey_navigate(brs_le_event_t* evt, 
                    brs_le_nav_node_t* nav_node, 
                    brs_dt_tree_node_t* marked_element,
                    brs_le_direction direction,
                    int* performed_scroll);





brs_l4wn_nav_t*
brs_le_l4wn_create (void);




void
brs_le_l4wn_delete (brs_l4wn_nav_t* nav_4w);




void
brs_le_l4wn_init (brs_le_event_t* nav);


#endif





brs_le_boxt_box_t*
brs_le_get_first_markable_element(brs_le_event_t* evt);






brs_le_boxt_box_t*
brs_le_focus_first_markable_element(brs_le_event_t* evt);


#endif


#ifdef BRS_CFG_LE_SUPPORT_PEN_NAVIGATION




void
brs_le_pen_navigate(brs_le_event_t* evt, 
                    MsfEvent* event);
#endif





void
brs_le_delete_navigation_list(brs_le_event_t* evt);







brs_le_nav_node_t*
brs_le_refresh_navigation_list(brs_le_event_t* evt);







int
brs_le_has_image_map(brs_dt_tree_node_t* node);







void
brs_le_register_node_as_visible(brs_le_event_t* evt, 
                                brs_le_boxt_box_t* box, 
                                int x_offset, 
                                int y_offset);





void
brs_le_store_history_navigation(brs_le_event_t* evt, brs_le_hist_navigation_t* hist_nav);




void
brs_le_set_history_and_marked_element(brs_le_event_t* evt);







int
brs_le_is_selectable (brs_dt_tree_node_t* node);

int
brs_le_is_onscreen_box(brs_le_event_t* evt, brs_le_boxt_box_t* top_box, 
                       int* whole_line, int* above, int* below);

void
brs_le_reset_navigation(brs_le_event_t* evt);



void
brs_le_free_navig_tw(brs_le_event_t* evt);

brs_le_boxt_tree_walker_t*
brs_le_create_navig_tw(brs_le_event_t* evt);


void
brs_le_unfocus_node(brs_dt_tree_node_t* node, brs_le_event_t* evt);

int
brs_le_focus_box(brs_le_boxt_box_t* box, brs_le_event_t* evt);


void
brs_le_set_flags(brs_dt_tree_node_t* node, int flag, int add);


void
brs_le_activate_node(brs_dt_tree_node_t* node, brs_le_event_t* evt);

void
brs_le_unactivate_node(brs_dt_tree_node_t* node, brs_le_event_t* evt);


void
brs_le_redraw_box (brs_le_boxt_box_t* box, int view_id);

void
brs_le_nav_remove_gadget_actions (brs_le_event_t* evt);

void
brs_le_nav_select_box(brs_le_boxt_box_t* box, brs_le_event_t* evt,
                      MsfEvent* event, brs_le_pos_t* pos);

brs_le_boxt_box_t*
brs_le_get_next_markable_box (brs_le_event_t* evt,
                              brs_le_boxt_box_t* marked_box,
                              brs_le_direction direction);

void
brs_le_handle_navigation_change (brs_le_view_t* view, 
                                 MSF_UINT16 new_markable_elements);


#if defined BRS_CFG_LE_SUPPORT_KEY_SUBSCRIPTION



void
brs_le_update_directions(brs_le_event_t* evt);
#endif

#endif
