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






#ifndef _brs_lmn_h
#define _brs_lmn_h
 
#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif













void
brs_le_init (void);






void
brs_le_terminate (void);







void
brs_le_open_view (int              view_id, 
                  MsfScreenHandle  screen_handle,
                  MsfWindowHandle* paint_box,
                  MsfPosition*     pos,
                  MsfSize*         size);





void
brs_le_handle_close_view (int view_id);




























































void
brs_le_stop_page (int view_id);









void
brs_le_abort_page (int view_id, int clear_screen);






void
brs_le_free_ledata (brs_dt_tree_node_t* node);









char*
brs_le_get_focused_object_url (int view_id);


int
brs_le_inputs_valid_formats (int view_id, void* control_iterator);







void
brs_le_get_history_info (int view_id, int* pos_x, int* pos_y, int* node_id);







brs_le_hist_navigation_t*
brs_le_create_history_navigation (int node_id, int x_pos, int y_pos);










void
brs_le_reset_rendering_stop (brs_le_render_t* rend, int add_reset);




brs_le_view_t*
brs_le_find_view (int view_id);





void
brs_le_goto_fragment (brs_le_view_t* view);








int
brs_le_handle_focused_offscreen (brs_le_event_t* evt);






brs_le_view_t*
brs_le_find_view_by_handle_sb (MsfWindowHandle handle, MSF_BOOL* is_scrollbar);

brs_le_view_t*
brs_le_get_views (void);








void
brs_le_render_template_do_element (int view_id, brs_dt_tree_node_t* node);


#ifdef BRS_CFG_LE_SUPPORT_KEY_SUBSCRIPTION






void
brs_le_set_key_subscription(brs_le_event_t * evt);
#endif

#endif
