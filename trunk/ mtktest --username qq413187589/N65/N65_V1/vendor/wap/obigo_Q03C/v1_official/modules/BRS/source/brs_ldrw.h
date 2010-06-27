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






#ifndef _brs_ldrw_h
#define _brs_ldrw_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif












int
brs_le_init_draw_paintbox (brs_le_draw_t* view);







int
brs_le_init_draw_element (brs_le_draw_t* view, brs_dt_tree_node_t* node);








int
brs_le_do_draw (brs_le_draw_t* draw);






void
brs_le_free_draw(brs_le_draw_t* draw_view);





void
brs_le_clean_draw(brs_le_draw_t* draw_view);







void
brs_le_clear_screen (brs_le_draw_t* draw, int stand_alone);




void
brs_le_draw_button_bg_border(brs_le_boxt_box_t* box, brs_le_draw_t* draw);

#endif
