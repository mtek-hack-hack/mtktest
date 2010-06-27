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












#ifndef _brs_lcss_h
#define _brs_lcss_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _brs_cfg_h
#include "brs_cfg.h"
#endif
#ifndef _brs_ddt_h
#include "brs_ddt.h"
#endif
#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif









#define BRS_LE_CSS_NO_COLOR                       0xffffffff
#define BRS_LE_CSS_TRANSPARENT_COLOR              0x0fffffff


#define BRS_LE_CSS_PROP_BACKGROUND_POSITION_X                BRS_CSS_NO_PROPERTIES + 1
#define BRS_LE_CSS_PROP_BACKGROUND_POSITION_Y                BRS_CSS_NO_PROPERTIES + 2

#define BRS_LE_CSS_TEXT_DECORATION_VALUE_BLINK 1
#define BRS_LE_CSS_TEXT_DECORATION_VALUE_UNDERLINE 2







typedef MSF_INT32
brs_le_css_resolve_percentage_t (brs_dt_tree_node_t *node, brs_le_common_t *common,
                                 int property, MSF_INT32 value, int* value_type,
                                 brs_dt_tree_node_t* is_inherited_from);








brs_le_css_t *
brs_le_css_init (brs_le_common_t *common, brs_le_css_resolve_percentage_t *resolve);




void
brs_le_css_free (brs_le_css_t *css);




void
brs_le_css_clean (brs_le_css_t *css);






void
brs_le_read_css_info (brs_dt_tree_node_t *node, brs_le_css_t *css, brs_css_stack_t *stack);





void
brs_le_css_update_style_color(brs_dt_tree_node_t *node, 
                              brs_le_css_t *css, 
                              int force_update,
                              int to_integration);










void
brs_le_css_update_style (brs_dt_tree_node_t *node, 
                         brs_le_css_t *css, 
                         int force_update,
                         int is_draw);










void
brs_le_css_update_style_to_node_redraw(brs_dt_tree_node_t* node, 
                                       brs_le_css_t *css,
                                       brs_dt_tree_node_t** redraw_from_node);







void
brs_le_css_update_style_bg_mark (brs_dt_tree_node_t *node, brs_le_css_t *css);






int
brs_le_css_get_border (brs_dt_tree_node_t *node, brs_le_css_t *css,
                       int *style, int *width, MSF_UINT32 *color, int *padding);






MSF_INT32
brs_le_css_get_value_i_t (brs_dt_tree_node_t *node, brs_le_css_t *css, int property, int* value_type);












MSF_INT32
brs_le_css_get_value_p_t (brs_dt_tree_node_t *node, brs_le_css_t *css, int property, int* value_type);

MSF_INT32
brs_le_css_get_value_i (brs_dt_tree_node_t *node, brs_le_css_t *css, int property);






MSF_UINT32
brs_le_css_get_value_c (brs_dt_tree_node_t *node, brs_le_css_t *css, int property);







const char *
brs_le_css_get_value_s (brs_dt_tree_node_t *node, brs_le_css_t *css, int property);






int
brs_le_css_has_value (brs_dt_tree_node_t *node, brs_le_css_t *css, int property);





const char *
brs_le_css_font_size_to_string (const char *font_size, brs_le_common_t *common);





void
brs_le_css_has_mbp(brs_dt_tree_node_t *node, brs_le_css_t* css, int* left_right, int* top_bottom);



void
brs_le_css_set_msf_font (brs_le_css_current_style_t *style, MsfFont *font);




MsfColor
brs_le_css_get_msfcolor (brs_le_css_t*css, int background);

#endif
