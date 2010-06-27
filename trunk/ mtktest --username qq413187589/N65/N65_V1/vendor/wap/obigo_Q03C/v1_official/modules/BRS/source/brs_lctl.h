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






#ifndef _brs_lctl_h
#define _brs_lctl_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif






















void
brs_le_free_control (brs_le_view_t* view);





void
brs_le_reset_control (brs_le_view_t* view);





int
brs_le_more_to_do (const brs_le_view_t* view);









void
brs_le_continue (brs_le_view_t* view);





void
brs_le_stop (brs_le_view_t* view);






void
brs_le_render_document (brs_le_view_t* view, brs_dt_tree_node_t* node);





void
brs_le_rerender_document (int view_id);





void
brs_le_draw_paintbox (int view_id);






int
brs_le_check_complete_redraw_needed (brs_dt_tree_node_t* node, int view_id);




void
brs_le_redraw_element (brs_dt_tree_node_t* node, int view_id);





void
brs_le_node_updated (brs_le_view_t* view, brs_dt_tree_node_t* node);






void
brs_le_object_notify_recieved (brs_le_view_t* view);


#endif
