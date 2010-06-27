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






#ifndef _brs_lrdf_h
#define _brs_lrdf_h

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif

#ifndef _brs_lbxt_h
#include "brs_lbxt.h"
#endif







#define BRS_LE_STATE_X        0x01 
#define BRS_LE_STATE_ENTER    0x02 
#define BRS_LE_STATE_DRAW     0x04 
#define BRS_LE_STATE_TABLE    0x08 


#define BRS_LE_STATE_INIT     0x10


#define BRS_LE_STATE_QUIT     0x20 
#define BRS_LE_STATE_RERENDER 0x40




#define BRS_LE_STATE_RESET    0x80

typedef enum {
  BRS_LE_TOP = 1,
  BRS_LE_BOTTOM = 2,
  BRS_LE_LEFT = 4,
  BRS_LE_RIGHT = 8
} brs_le_sides;

typedef enum {
  BRS_LE_NODE_CHANGE_NONE,
  BRS_LE_NODE_CHANGE_REINIT,
  BRS_LE_NODE_CHANGE_RERENDER,
  BRS_LE_NODE_CHANGE_REDRAW
} brs_le_node_change_type_t;



typedef enum {
  BRS_LE_NSTATE_NONE,
  BRS_LE_NSTATE_REINIT,
  BRS_LE_NSTATE_RERENDER_CHILDREN,
  BRS_LE_NSTATE_READY,
  BRS_LE_NSTATE_INCOMPLETE,
  BRS_LE_NSTATE_FLOATING,
  BRS_LE_NSTATE_CHANGED
} brs_le_node_state_t;





#define BRS_LE_NFLAG_IGNORE_DESCENDANTS            0x0010

#define BRS_LE_NFLAG_IGNORE_NODE                   0x0020

#define BRS_LE_NFLAG_TOP_BOTTOM_MBP                0x0040

#define BRS_LE_NFLAG_LEFT_RIGHT_MBP                0x0080


#define BRS_LE_NFLAG_IS_REPLACED                   0x0100

#define BRS_LE_NFLAG_HAS_INLINE_BOXES              0x0200


#define BRS_LE_NFLAG_HAS_UNCLEAN_NESTING           0x0400



#define BRS_LE_NFLAG_HAS_ACCESSKEY                 0x0800


#define BRS_LE_NFLAG_HAS_MARKER                    0x1000


#define BRS_LE_NFLAG_HAS_BACKGROUND_IMAGE          0x2000




#define BRS_LE_NFLAG_WML_TABLE_EXTRA_CELL          0x4000

#define BRS_LE_NFLAG_BLOCK_IN_ANCHOR               0x8000

#define BRS_LE_NSTATE(ledata) ((ledata)->state_flags & 0xF)
#define BRS_LE_NFLAGS(ledata) ((ledata)->state_flags & 0xFFF0)

#define BRS_LE_SET_NFLAGS(ledata, new_flags) ((ledata)->state_flags = BRS_LE_NSTATE(ledata) | (new_flags))
#define BRS_LE_SET_NSTATE(ledata, new_state) ((ledata)->state_flags = BRS_LE_NFLAGS(ledata) | (new_state))

#define BRS_LE_ADD_NFLAG(ledata, new_flag) ((ledata)->state_flags |= (new_flag))
#define BRS_LE_REM_NFLAG(ledata, new_flag) ((ledata)->state_flags &= ~(new_flag))

#define BRS_LE_NSTATE_DIRTY(ledata) ((BRS_LE_NSTATE(ledata) != BRS_LE_NSTATE_READY))





#define BRS_LE_MAXWIDTH -1
#define BRS_LE_MAXHEIGHT -1










typedef struct {
  int a;  
  int d;  

  int h;    
  int valign;
  int* x;   
  int* y;   

  int mbp[4];


  brs_dt_tree_node_t* node;
} brs_le_align_item_t;

typedef struct {
  int size;
  int pos;
  int last_child;
  brs_le_align_item_t a[10];
} brs_le_align_stack_t;

typedef struct {
  brs_le_boxt_box_t* box;
  brs_dt_tree_node_t* node;

  int last_child_right_m_edge; 

  int line_x;  

  int changed; 

  
  int first_box;
  int align_index; 
} brs_le_open_inline_box_t;

typedef struct {
  int size;
  int pos;
  brs_le_open_inline_box_t open_box[10];
} brs_le_open_inline_box_stack_t;

typedef struct {
  brs_le_boxt_box_t* box;
  brs_dt_tree_node_t* node;

  



  brs_le_boxt_box_t* marker_box;
  int marker_baseline;

  int indent;
  int text_align;
  int line_complete;
  int widest_point;
  int abs_x;
  int check_abs_y;
  int abs_y;
  int lowest_point;
  brs_le_open_inline_box_stack_t* prev_inline_context;
  brs_le_align_stack_t* prev_align_context;
} brs_le_open_block_box_t;


typedef struct {
  int size;
  int pos;
  brs_le_open_block_box_t open_box[20];
} brs_le_open_block_box_stack_t;


typedef struct brs_le_float_list_st {
  struct brs_le_float_list_st* next;
  

  brs_le_boxt_box_t* box;
  int state;
  int clear;
  int side;
  int is_unclean;
  int mbp[4];
} brs_le_float_t;

typedef struct {
  

  brs_le_float_t* active;
} brs_le_float_list_t;









typedef struct {
  brs_le_open_block_box_stack_t* block_boxes;
  


  int prev_bottom_border_edge;
  int prev_bottom_margin;

  brs_le_open_inline_box_stack_t* inline_boxes;
  


  int inline_right_mbp_sum;

  



  void* open_inl_marq;

  



  void* open_float;

  





  brs_le_float_list_t floats;

  brs_le_align_stack_t* align_stack;


} brs_le_render_boxes_t;


#define BRS_LE_LINE_BASELINE_TABLE 1
#define BRS_LE_LINE_BASELINE_LI    2

typedef struct {
  int is_baseline_dependency;
                    

  int baseline_anc_mbp;
                    


} brs_le_baseline_dependency_t;


typedef struct {
  int size;
  int pos;
  brs_le_baseline_dependency_t d[5];
} brs_le_baseline_dependency_stack_t;




typedef struct {
  int cur_x;        
  int y;            
  int rem_w;        
  int full_width;   
  int start_x;      
  int changed;      


  brs_le_baseline_dependency_stack_t* dependant;
    






  int prev_ending_spc_w; 

} brs_le_line_t;



#define BRS_LE_FLOAT_CREATED        1


#define BRS_LE_FLOAT_ACTIVE         2











typedef struct {
  brs_le_render_boxes_t prev_render_context;
  brs_le_line_t prev_line;
} brs_le_open_float_box_t;


typedef struct {
  brs_le_align_stack_t* align_stack;
  brs_le_open_inline_box_stack_t* inline_boxes;
  int inline_right_mbp_sum;
  int prev_bottom_border_edge;
  int prev_bottom_margin;
  int line_complete;
  brs_le_line_t prev_line;
  MSF_UINT32 mbp_flags; 

} brs_le_open_inline_marquee_box_t;


#endif
