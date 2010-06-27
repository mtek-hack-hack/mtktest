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










#ifndef _brs_lrfl_h
#define _brs_lrfl_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif










void
brs_le_create_float_context(brs_dt_tree_node_t* node, 
                            brs_le_render_t* rend, 
                            int width,
                            int height,
                            int side,
                            int css_clear);


void
brs_le_leave_float_context(brs_le_render_t* rend);







void
brs_le_float_update_line(brs_le_render_t* rend, int* left, int* right, int is_final);











void
brs_le_float_update_block_enter(brs_le_render_t* rend);







int
brs_le_float_update_block_leave(brs_le_render_t* rend);








int
brs_le_finalise_floats(brs_le_render_t* rend);






void
brs_le_clear_float_to_linewidth(brs_le_render_t* rend, int fit_width);






void
brs_le_clear_floats(int clear, brs_le_render_t* rend);

#endif
