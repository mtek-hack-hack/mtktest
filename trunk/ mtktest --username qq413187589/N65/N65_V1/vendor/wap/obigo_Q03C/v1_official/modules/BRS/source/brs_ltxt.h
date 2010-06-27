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








#ifndef _brs_ltxt_h
#define _brs_ltxt_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif
 
 








void
brs_le_draw_text_box(brs_le_boxt_box_t* box, brs_le_draw_t* draw);

void
brs_le_free_text(brs_le_element_t* data);

void
brs_le_enter_table_text(brs_dt_tree_node_t* node, brs_le_render_t* view);

void
brs_le_init_table_text(brs_dt_tree_node_t* node, brs_le_render_t* view);


void
brs_le_txt_init(void);


void
brs_le_txt_terminate(void);



int
brs_le_txt_single_space_width (MsfBrushHandle brush);


void
brs_le_flow_text(brs_dt_tree_node_t* node, brs_le_render_t* rend);

void
brs_le_render_br(brs_le_render_t* rend, int* a, int* d);

#endif
