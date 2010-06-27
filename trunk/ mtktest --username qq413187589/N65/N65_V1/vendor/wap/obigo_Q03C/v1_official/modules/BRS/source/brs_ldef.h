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






#ifndef _brs_ldef_h
#define _brs_ldef_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif

#ifndef _brs_cfg_h
#include "brs_cfg.h"
#endif

#ifndef _brs_dlg_h
#include "brs_dlg.h"
#endif

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif

#ifndef _brs_dmsh_h
#include "brs_dmsh.h"
#endif

#ifndef _brs_lbxt_h
#include "brs_lbxt.h"
#endif

#ifndef _brs_memp_h
#include "brs_memp.h"
#endif

#ifndef _brs_lrdf_h
#include "brs_lrdf.h"
#endif





#undef BRS_LE_LOG_RENDER
#undef BRS_LE_LOG_RENDER_FLOATS
#define BRS_LE_STOP_PARAMETER_WARNING(x) (x = x)







#define BRS_LE_NO_CONTINUE_ITERATIONS  20





#define BRS_LE_NBR_OF_REDRAW_ELEMENT   4


#define BRS_LE_MARQUEE_SCROLL_SLOW    1
#define BRS_LE_MARQUEE_SCROLL_NORMAL  2
#define BRS_LE_MARQUEE_SCROLL_FAST    3







#define BRS_LE_CSS_VALUE_TABLE_CELL     110
#define BRS_LE_CSS_VALUE_TABLE_CAPTION  111
#define BRS_LE_CSS_VALUE_TABLE_ROW      112
#define BRS_LE_CSS_VALUE_TABLE          113


#define BRS_LE_OK                       0


#define BRS_LE_DONE                     0
#define BRS_LE_MORE_TO_DO               1


#define BRS_LE_WORKLOAD_NONE            0
#define BRS_LE_WORKLOAD_LIGHT           1
#define BRS_LE_WORKLOAD_HARD            2


#define BRS_LE_BOTTOM_POS               0
#define BRS_LE_LEFT_POS                 1
#define BRS_LE_RIGHT_POS                2
#define BRS_LE_TOP_POS                  3


#define BRS_LE_UPPER_LEFT_CORNER        0
#define BRS_LE_UPPER_RIGHT_CORNER       1
#define BRS_LE_LOWER_RIGHT_CORNER       2
#define BRS_LE_LOWER_LEFT_CORNER        3


#define BRS_LE_NAV_UP_KEY               0x01
#define BRS_LE_NAV_DOWN_KEY             0x02
#define BRS_LE_NAV_LEFT_KEY             0x04
#define BRS_LE_NAV_RIGHT_KEY            0x08




#define BRS_LE_NARROW_RESET             0x01


typedef enum {
  BRS_LE_NAV_UP,
  BRS_LE_NAV_DOWN,
  BRS_LE_NAV_LEFT,
  BRS_LE_NAV_RIGHT,
  BRS_LE_NAV_NO_DIRECTION
} brs_le_direction;






#define BRS_LE_CONTAINING_BLOCK_BOX(rend) (rend->box_state.block_boxes->pos ? \
  &rend->box_state.block_boxes->open_box[rend->box_state.block_boxes->pos - 1] : NULL)
#define BRS_LE_INLINE_PARENT_BOX(rend) (rend->box_state.inline_boxes->pos ? \
  &rend->box_state.inline_boxes->open_box[rend->box_state.inline_boxes->pos - 1] : NULL)







typedef struct brs_le_cell_st {
  int                           status;   
  int                           rowspan;
  int                           colspan;
  int                           flags;
  struct brs_le_cellcontent_st *content;  
} brs_le_cell_t;


typedef struct brs_le_cellcontent_st {
  int                 row, col;
  int                 min_width;
  int                 max_width;
  int                 current_max_width;
  int                 current_min_width;
  int                 cumulative_mbp;
  unsigned char       border[4];
  int                 padding[4];
  int                 valign;
  int                 ascent;
  brs_le_boxt_box_t  *box;
  brs_le_boxt_box_t  *content_box;
  brs_dt_tree_node_t *node;
} brs_le_cellcontent_t;


typedef struct brs_le_row_st {
  brs_dt_tree_node_t *node;
  int                 height;
  int                 max_cells;
  brs_le_cell_t      *cells;
  brs_le_boxt_box_t  *box;
  unsigned char       border[4];
  int                 ascent;
} brs_le_row_t;


typedef struct {
  int text_align;
} brs_le_column_t;


typedef struct brs_le_table_st {
  struct brs_le_table_st *next;

  int                 rowidx;
  int                 colidx;
  int                 next_colidx;
  int                 num_rows;
  int                 num_cols;
  int                 max_rows;
  int                 max_cols;

  brs_le_row_t       *rows;
  brs_le_column_t    *cols;
  brs_le_boxt_box_t  *box;
  brs_le_boxt_box_t  *anon_box;
  brs_le_boxt_box_t  *caption_box;
  brs_dt_tree_node_t *caption;
  brs_dt_tree_node_t *node;
  brs_dt_tree_node_t *setwidthnode;
  int                *col_width;
  int                *min_width;
  int                *max_width;
  int                *width;
  int                *percw;
  int                 minw, maxw, w;
  int                 ow;
  int                 cbw;

  int                 fixed_layout;
  int                 border_collapse;
  int                 border_spacing;
  int                 caption_side;
  int                 cw;
  int                 cellpadding;
  int                 wml_num_columns;

  unsigned char       border[4];
  int                 padding[4];
} brs_le_table_t;


#define BRS_LE_MAX_LIST_NESTING_LEVEL 10
typedef struct brs_le_lists_st {
  int nested_level;
  int current_values[BRS_LE_MAX_LIST_NESTING_LEVEL];
} brs_le_lists_t;

typedef struct brs_le_render_st brs_le_render_t;

typedef
void
(brs_le_post_action_t) (brs_le_render_t* rend, brs_dt_tree_node_t* node);

typedef struct brs_le_state_item_st {
  int state;
  brs_dt_tree_node_t* continue_node;
  brs_dt_tree_node_t* last_node;
  brs_le_post_action_t* post_action;

} brs_le_state_item_t;



typedef struct brs_le_render_states_st {
  int size;
  int nested_level;
  brs_le_state_item_t* current_values[1];
} brs_le_render_states_t;



typedef struct {
  int x;
  int y;
} brs_le_pos_t;

typedef struct {
  int width;
  int height;
} brs_le_size_t;



typedef struct {
  MsfGadgetHandle handle;
  brs_dt_tree_node_t* node;
} brs_le_gadget_item_t;

typedef struct {
  int size;
  int pos;
  brs_le_gadget_item_t item[1];
} brs_le_gadget_list_t;

typedef struct {
  MsfGadgetHandle handle;
  brs_dt_tree_node_t* node;
  MsfPosition pos;
  int added_to_screen;
} brs_le_visible_gadget_item_t;

typedef struct {
  int size;
  int pos;
  brs_le_visible_gadget_item_t item[1];
} brs_le_visible_gadget_list_t;



typedef struct {
  int node_id;
  int screen_pos_x;
  int screen_pos_y;
} brs_le_hist_navigation_t;

typedef struct brs_le_task_st brs_le_task_t;

typedef struct brs_le_background_image_st {
  struct brs_le_background_image_st* next;
  int x;
  int y;
  int w;
  int h;
  int box_w;
  int box_h;
  brs_le_boxt_box_t* box;
  brs_dt_tree_node_t* node;
  MsfImageHandle original_image;
  MsfImageHandle current_image;
  int status;
  int use_original;
}brs_le_background_image_t;

typedef struct brs_le_list_style_image_st {
  struct brs_le_list_style_image_st* next;
  brs_dt_tree_node_t* node;
  MsfImageHandle image;
}brs_le_list_style_image_t;

typedef struct brs_le_elem_area_st
{
  brs_le_boxt_box_t* box;
  brs_d_area_def_t* area;
  struct brs_le_elem_area_st* next;
} brs_le_elem_area_t;

typedef struct brs_le_imagemap_st
{
  brs_dt_tree_node_t* obj_node;
  MsfImageHandle image;
  brs_le_elem_area_t* areas;
  struct brs_le_imagemap_st* next;
} brs_le_imagemap_t;









typedef struct brs_le_view_st brs_le_view_t;




typedef struct brs_le_css_st brs_le_css_t;




#ifdef BRS_CFG_LE_SUPPORT_KEY_NAVIGATION_4WKEY
typedef struct brs_l4wn_nav_st brs_l4wn_nav_t;
#endif






typedef struct {
  MSF_UINT32  bg_color;
  MSF_UINT32  fg_color;
  

  int         font_family; 
  int         font_size;
  int         font_style;
  int         font_variant;
  int         font_weight;
  int         text_decoration;

  
  int         font_ascent;
  int         font_height;
  int         font_xHeight;
  int         space_width;
} brs_le_css_current_style_t;

typedef struct brs_le_border_st {
  int        style;
  int        width;
  MSF_UINT32 color;
} brs_le_border_t;

typedef struct brs_le_border_cache_st {
  int              size;
  int              max_size;
  brs_le_border_t *borders;
} brs_le_border_cache_t;


typedef struct brs_le_common_st {
  int view_id;
  brs_le_view_t* view;
  brs_le_boxt_box_t* box_tree_root;
  brs_le_border_cache_t border_cache;
  
  
  brs_d_doc_t* doc;
  brs_le_css_current_style_t style;

  
  int vertical_size;
  int horizontal_size;
  int vert_offset;
  int horiz_offset;
  
  int fill_body_vertical;

  
  MSF_UINT32 current_draw_area;
  MsfWindowHandle pb;
  MsfBrushHandle  pb_brush;
  int             width;
  int             height;
  int             scrollbar_indent;

  
  int vertical_scrollbar_right;     
  int rerender_when_changing_width; 

  


  int require_clear_screen;

} brs_le_common_t;

typedef struct brs_le_nav_bounds_st {
  int x;
  int y;
  int w;
  int h;
  int cx;
  int cy;
} brs_le_nav_bounds_t;

typedef struct brs_le_nav_bounds_list_st {
  int size;
  brs_le_nav_bounds_t bounds[1];
} brs_le_nav_bounds_list_t;

typedef struct brs_le_nav_node_st
{
  struct brs_le_nav_node_st  *next;
  brs_le_nav_bounds_list_t   *bounds_list;
  brs_le_boxt_box_t          *box;
} brs_le_nav_node_t;


typedef struct brs_le_event_st {
  int marked_fragment;
  
#ifdef BRS_CFG_LE_SUPPORT_KEY_NAVIGATION_4WKEY
  brs_le_nav_node_t* nav_node_list;
#endif

  brs_dt_tree_node_t* marked_element;
  brs_dt_tree_node_t* selected_element;
  brs_dt_tree_node_t* marked_image;


                                      

  brs_le_visible_gadget_list_t* visible_gadgets;
  brs_le_gadget_list_t* all_gadgets;
  brs_le_gadget_list_t* accesskeys;
  
  MsfGadgetHandle active_gadget;
  brs_dlg_t* active_dlg; 
  
  MsfGadgetHandle    sb_vert;  
  MsfGadgetHandle    sb_horiz; 
  int                sb_vert_visible; 
  int                sb_horiz_visible;
  
  MSF_INT16          sb_vert_extent; 
  MSF_INT16          sb_horiz_extent; 

  brs_le_hist_navigation_t* history_nav;

  brs_le_css_t         *css; 
  brs_le_common_t      *common;

  brs_le_pos_t navig_pos;
  brs_le_boxt_tree_walker_t* navig_tw;

  MSF_UINT16 markable_elements; 

#ifdef BRS_CFG_LE_SUPPORT_KEY_SUBSCRIPTION
  int subscribed_keys;       
#endif

#ifdef BRS_CFG_LE_SUPPORT_KEY_NAVIGATION_4WKEY
  brs_l4wn_nav_t *four_way_data;
#endif


} brs_le_event_t;



struct brs_le_render_st{
  brs_dt_tree_walker_t* x_tw;
  brs_dt_tree_walker_t* y_tw;
  brs_dt_tree_walker_t* temp_tw;
  brs_dt_tree_walker_t* temp_y_tw;
  brs_dt_tree_walker_t* parent_tw;
  brs_le_line_t line;
  brs_le_table_t *table;
  brs_objpool_t   tbl_mempool;

  int step_over;

  brs_dt_tree_node_t* template_node;

  
  brs_dt_tree_node_t* continue_node;
  
  brs_dt_tree_node_t* last_node;
  
  brs_dt_tree_node_t* marquee_node;

  brs_le_render_states_t* state_stack;

  
  brs_le_lists_t* lists;

  
  brs_le_common_t* common;

  brs_le_css_t    *css;
  brs_le_event_t  *event;
  int state;

  
  brs_le_render_boxes_t box_state;

  int force_rerender; 

};



typedef struct brs_le_draw_st {
  int state;
  int inside_non_breakable;

  
  brs_le_common_t* common;
  brs_le_event_t*  event;
  brs_le_css_t    *css; 

  

  brs_le_boxt_tree_walker_t* box_tw;
  
  
  brs_le_pos_t draw_box_pos;
  brs_le_pos_t stored_box_pos;
} brs_le_draw_t;


typedef struct brs_le_input_invalid_st {
  brs_dlg_t* dlg;
  brs_dt_tree_node_t* invalid_node;
} brs_le_input_invalid_t;




struct brs_le_view_st {
  struct brs_le_view_st* next;
  int view_id;

  
  int   state_control;     
  int   state_render;      
  int   state_draw;        
  int   state_stopped;     
  int   continue_sig;      
  int   goto_fragment;     
  char* fragment_id;
  brs_dt_tree_node_t* redraw_element[BRS_LE_NBR_OF_REDRAW_ELEMENT];
  int   redraw_element_size; 

  
  brs_d_object_ready_t* loading_objects;
  brs_d_object_ready_t* loaded_objects;
  int remaining_objects;   
  int image_timer;
  int nbr_of_current_loaded_objects; 
  int nbr_of_images; 
  int prev_remaining_objects; 

  
  brs_le_background_image_t* background_images;

  
  brs_le_list_style_image_t* list_style_images;
  
  
  brs_le_imagemap_t* imagemaps;

  
  brs_le_common_t  common;
  brs_le_render_t  render_view;
  brs_le_draw_t    draw_view;
  brs_le_css_t    *css;
  brs_le_event_t   event;

  



  int render_reset;

  


  int narrow_rendering_enabled;

  



  brs_le_input_invalid_t* input_invalid;

#ifdef MTK_TMP_PATCH /* TR19101 */
  int adjust_count;
#endif

};








typedef struct {
  int handle;
  void* data;             
  MSF_UINT32 state_flags;
  int render_type; 
  int flags;       
  MSF_INT16 style_idx;
  MSF_INT16 istyle_idx;
} brs_le_element_t;


typedef struct brs_le_elem_input_st {
  MsfStringHandle string;
  MsfGadgetHandle gadget;
  MsfIconHandle icon;
  MsfImageHandle image;
  MsfTextType inputType;
} brs_le_elem_input_t;


typedef struct {
  int size;
  brs_dt_tree_node_t* node[1];
} brs_le_option_list_t;


typedef struct {
  MsfStringHandle label;
  MsfGadgetHandle gadget;
  brs_le_option_list_t* options;
} brs_le_elem_select_t;

typedef struct {
  brs_dt_tree_node_t* target;
} brs_le_elem_label_t;




#endif
