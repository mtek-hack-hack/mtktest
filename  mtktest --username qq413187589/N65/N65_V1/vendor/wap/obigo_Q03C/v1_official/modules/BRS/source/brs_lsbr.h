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









#ifndef _brs_lsbr_h
#define _brs_lsbr_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif





void
brs_le_create_scrollbars (brs_le_event_t* evt);





void
brs_le_delete_scrollbars (brs_le_event_t* evt);







void
brs_le_set_visible_scrollbars (brs_le_event_t* evt, int vertical, int horizontal);










int
brs_le_adjust_scrollbars (brs_le_view_t* view);






void
brs_le_reset_scrollbars (brs_le_event_t* evt);





void
brs_le_update_scrollbars (brs_le_event_t* evt);

#endif
