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











#ifndef _brs_lbxt_h
#define _brs_lbxt_h

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif

#ifndef _brs_ddt_h
#include "brs_ddt.h"
#endif






#define BRS_LE_BOXT_PARENT_STACK_SIZE 10




#define BRS_LE_BOXT_FLAG_UNCLEAN          0x01
#define BRS_LE_BOXT_FLAG_USE_ENDING_WS    0x02
#define BRS_LE_BOXT_FLAG_BORDER_COLLAPSE  0x04








typedef void
brs_le_free_box_items_t (void* data);


typedef enum {

  BRS_LE_BOX_VIEWPORT, 
  BRS_LE_BOX_BLOCK,
  BRS_LE_BOX_LIST_ITEM,
  BRS_LE_BOX_ANON_BLOCK,


  BRS_LE_BOX_INLINE,
  BRS_LE_BOX_ANON_INLINE, 
  BRS_LE_BOX_INLINE_FIRST_ROW,
  BRS_LE_BOX_INLINE_MIDDLE_ROW,
  BRS_LE_BOX_INLINE_LAST_ROW,


  BRS_LE_BOX_ANON_TABLE,  
  BRS_LE_BOX_TABLE,
  BRS_LE_BOX_TABLE_CELL,
  BRS_LE_BOX_ANON_TABLE_CELL, 
  BRS_LE_BOX_TABLE_CAPTION,
  BRS_LE_BOX_TABLE_ROW,
  BRS_LE_BOX_TABLE_COLUMN,
  BRS_LE_BOX_ANON_TABLE_FLOAT, 
  





  BRS_LE_BOX_INTERNAL_LI_MARKER,
  BRS_LE_BOX_INTERNAL_ACCESSKEY,


  BRS_LE_BOX_NONE,
  BRS_LE_BOX_MARQUEE






















} brs_le_boxtypes_e;

#define BRS_LE_IS_TABLE_BOX(btype) (btype == BRS_LE_BOX_TABLE || \
                                    btype == BRS_LE_BOX_TABLE_ROW || \
                                    btype == BRS_LE_BOX_TABLE_CELL || \
                                    btype == BRS_LE_BOX_TABLE_CAPTION || \
                                    btype == BRS_LE_BOX_TABLE_COLUMN || \
                                    btype == BRS_LE_BOX_ANON_TABLE_CELL || \
                                    btype == BRS_LE_BOX_ANON_TABLE)

typedef struct brs_le_boxt_box_st
{
  struct brs_le_boxt_box_st* next;
  struct brs_le_boxt_box_st* content;
  brs_le_boxtypes_e box_type;
  brs_dt_tree_node_t* node;
  int x;
  int y;
  int w;
  int h;
} brs_le_boxt_box_t;

typedef struct brs_le_boxt_tbox_st
{
  struct brs_le_boxt_box_st* next;
  struct brs_le_boxt_box_st* content;
  brs_le_boxtypes_e box_type;
  brs_dt_tree_node_t* node;
  int x;
  int y;
  int w;
  int h;
  int flags;
  unsigned char border[4];
} brs_le_boxt_tbox_t;

typedef struct brs_le_boxt_cdatabox_st
{
  struct brs_le_boxt_box_st* next;
  struct brs_le_boxt_box_st* content;
  brs_le_boxtypes_e box_type;
  brs_dt_tree_node_t* node;
  int x;
  int y;
  int w;
  int h;
  int index;
  int nbr_chars;
} brs_le_boxt_cdatabox_t;

typedef struct 
{
  struct brs_le_boxt_box_st* next;
  struct brs_le_boxt_box_st* content;
  brs_le_boxtypes_e box_type;
  brs_dt_tree_node_t* node;
  int x;
  int y;
  int w;
  int h;
  void* marker; 
  brs_le_free_box_items_t* delete_data;
} brs_le_boxt_li_box_t;

typedef struct {
  struct brs_le_boxt_box_st* next;
  struct brs_le_boxt_box_st* content;
  brs_le_boxtypes_e box_type;
  brs_dt_tree_node_t* node;
  int x;
  int y;
  int w;
  int h;
  MsfAccessKeyHandle handle;
  MsfWindowHandle pb;
} brs_le_boxt_accesskey_box_t;

typedef struct {
  struct brs_le_boxt_box_st* next;
  struct brs_le_boxt_box_st* content;
  brs_le_boxtypes_e box_type;
  brs_dt_tree_node_t* node;
  int x;
  int y;
  int w;
  int h;
  MsfGadgetHandle marquee_gadget;
  MsfImageHandle marquee_image;
  int marquee_image_w;
  int marquee_image_h;
  MsfMarqueeType marquee_style;
  int marquee_direction;
  int marquee_loop;
  int marquee_speed;
  int marquee_delay;
} brs_le_boxt_marquee_box_t;

typedef struct
{
  int size;
  int pos;
  brs_le_boxt_box_t* box_stack[BRS_LE_BOXT_PARENT_STACK_SIZE];
} brs_le_boxt_box_stack_t;

typedef struct brs_le_boxt_tree_walker_st
{
  brs_le_boxt_box_t* start_box;
  brs_le_boxt_box_t* stop_box;
  brs_le_boxt_box_t* current_box;

  brs_le_boxt_box_stack_t* parent_stack;
} brs_le_boxt_tree_walker_t;











void
brs_le_boxt_add_content(brs_le_boxt_box_t* t, brs_le_boxt_box_t* n);








void
brs_le_boxt_add_next(brs_le_boxt_box_t* t, brs_le_boxt_box_t* n);




void
brs_le_boxt_delete_box(brs_le_boxt_box_t* t);








void
brs_le_boxt_delete_boxtree(brs_le_boxt_box_t* root, brs_le_boxt_box_t* t);














brs_le_boxt_box_t*
brs_le_boxt_new_box(brs_le_boxtypes_e box_type, 
                    brs_dt_tree_node_t* node,
                    brs_le_free_box_items_t* delete_data);


brs_le_boxt_tree_walker_t*
brs_le_boxt_create_tree_walker(brs_le_boxt_box_t* start_box, brs_le_boxt_box_t* stop_box);

void
brs_le_boxt_init_tree_walker(brs_le_boxt_tree_walker_t* tw, brs_le_boxt_box_t* start_box, brs_le_boxt_box_t* stop_box);

void
brs_le_boxt_delete_tree_walker(brs_le_boxt_tree_walker_t* tw);

brs_le_boxt_box_t*
brs_le_boxt_tw_current_box(brs_le_boxt_tree_walker_t* tw);

brs_le_boxt_box_t*
brs_le_boxt_tw_parent_box(brs_le_boxt_tree_walker_t* tw);

brs_le_boxt_box_t*
brs_le_boxt_tw_first_child(brs_le_boxt_tree_walker_t* tw);

brs_le_boxt_box_t*
brs_le_boxt_tw_next_sibling(brs_le_boxt_tree_walker_t* tw);


void
brs_le_boxt_push_parent(brs_le_boxt_tree_walker_t* tw);
void
brs_le_boxt_pop_parent(brs_le_boxt_tree_walker_t* tw);
brs_le_boxt_box_stack_t*
brs_le_boxt_expand_stack(brs_le_boxt_box_stack_t* stack);


#endif
