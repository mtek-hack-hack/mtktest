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











#ifndef _brs_lutl_h
#define _brs_lutl_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif






#define BRS_EMPTY_NODE(t) ((t)->content == (t))
#define BRS_IS_INLINE(t) (t ==  BRS_CSS_VALUE_INLINE || !t)

















void
brs_le_convert_coords(int x, int y, MsfPosition* msf_pos);


void
brs_le_convert_pos(const brs_le_pos_t* pos, MsfPosition* msf_pos);


void
brs_le_convert_to_msfsize(const brs_le_size_t* size, MsfSize* msf_size);


void
brs_le_convert_from_msfsize(const MsfSize* msf_size, brs_le_size_t *size);




void
brs_le_convert_to_msfcolor (MSF_UINT32 u, MsfColor *color);




brs_dt_tree_node_t *
brs_le_get_parent (brs_dt_tree_node_t *node, brs_le_view_t *view);








int
brs_le_is_visited (brs_dt_tree_node_t* node, brs_d_doc_t* doc, int* is_link);









brs_dt_tree_node_t*
brs_le_find_node_by_element_id(int element_id, brs_le_common_t* view);




brs_dt_tree_node_t*
brs_le_find_node_by_id_or_name(const char* id, brs_le_render_t* view);





brs_le_boxt_box_t*
brs_le_find_first_corresponding_box(brs_dt_tree_node_t* node,
                                    brs_le_boxt_box_t* root_box,
                                    brs_le_boxt_tree_walker_t* tw,
                                    brs_le_pos_t* pos);




brs_le_boxt_box_t*
brs_le_find_box_of_node(brs_dt_tree_node_t* node,
                        brs_le_boxt_box_t* root_box,
                        brs_le_boxt_tree_walker_t* use_tw);







int
brs_le_get_margin(brs_dt_tree_node_t* node, brs_le_css_t* view, int location);


int
brs_le_get_padding(brs_dt_tree_node_t* node, brs_le_css_t* view, int location);


int
brs_le_get_border(brs_dt_tree_node_t* node, brs_le_css_t* view, int location);




int
brs_le_get_MPB(brs_le_css_t* view, brs_dt_tree_node_t* node, int location);





int
brs_le_set_replaced_size(brs_dt_tree_node_t* node, 
                         brs_le_render_t* rend, 
                         MsfSize* default_size, 
                         MsfSize* result);






int
brs_le_set_screen_size(MsfSize* size, brs_le_common_t* common);








int
brs_le_filter_ignored(brs_dt_tree_node_t* node);




int
brs_le_has_contents(brs_dt_tree_node_t* node);




brs_dt_tree_node_t*
brs_le_get_ancestor(brs_dt_tree_node_t* node, 
                    brs_dt_tree_walker_t* tw, 
                    int* node_type_list,
                    int no_types);







MSF_INT32
brs_le_resolve_percentage (brs_dt_tree_node_t *node, brs_le_common_t *common,
                           int property, MSF_INT32 value, int* value_type,
                           brs_dt_tree_node_t* is_inherited_from);






int
brs_le_has_href(brs_dt_tree_node_t* node);




int
brs_le_is_replaced_element(brs_dt_tree_node_t* node);








void
brs_le_check_screen_overflow(int x, brs_le_render_t* rend);




MsfStyleHandle
brs_le_create_msfstyle (brs_dt_tree_node_t* node, brs_le_render_t* rend);






void
brs_le_update_gadget_msfstyle(MsfGadgetHandle gadget, 
                              brs_dt_tree_node_t* node, 
                              brs_le_render_t* rend);









int
brs_le_node_contents_is_offscreen(brs_dt_tree_node_t* node, 
                                  brs_le_boxt_box_t* search_from,
                                  brs_le_common_t* cmmn, 
                                  brs_le_boxt_box_t** b,
                                  brs_le_pos_t* pos,
                                  int* is_above,
                                  int* is_below,
                                  int* is_left,
                                  int* is_right);






void
brs_le_scroll_to_box(brs_le_boxt_box_t* b, 
                     brs_le_pos_t* pos, 
                     brs_le_common_t* cmmn,
                     int scroll_horizontally,
                     int scroll_vertically);












void
brs_le_init_border_cache (brs_le_common_t *common);




void
brs_le_free_border_cache (brs_le_common_t *common);






int
brs_le_add_to_border_cache (brs_le_common_t *common, int style,
                            int width, MSF_UINT32 color);









int
brs_le_lookup_border_cache (brs_le_common_t *common, int idx,
                            int *style, int *width, MSF_UINT32 *color);


#ifdef BRS_LE_LOG_RENDER
void
brs_le_debug_abs_pos(brs_le_render_t* rend, int* x, int* y);

void
brs_le_debug_log_add_boxt(brs_le_boxt_box_t* box, brs_le_boxt_box_t* parent, char* log_desc);

void
brs_le_debug_log_node_name(brs_dt_tree_node_t* node, 
                           const char* func_name);

void
brs_le_debug_log_boxtree(brs_le_draw_t* draw);

void
brs_le_debug_log_box(const char* func_name,
                     brs_dt_tree_node_t* node,
                     int x,
                     int y,
                     int a,
                     int d,
                     int h,
                     int idx_start, 
                     int no_chars);

void
brs_le_debug_log_node(brs_le_open_inline_box_t* inl, 
                      const char* func_name,
                      brs_le_align_item_t* align_data,
                      int idx_start, 
                      int no_chars);

void
brs_le_debug_log_line(brs_le_render_t* rend, const char* func_name);

#endif

#endif
