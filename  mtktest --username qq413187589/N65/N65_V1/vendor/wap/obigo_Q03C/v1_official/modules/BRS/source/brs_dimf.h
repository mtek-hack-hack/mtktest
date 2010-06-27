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














#ifndef _brs_dimf_h
#define _brs_dimf_h

#ifndef _brs_cfg_h
#include "brs_cfg.h"
#endif

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif
#ifndef _brs_dmsh_h
#include "brs_dmsh.h"
#endif
#ifndef _brs_ddt_h
#include "brs_ddt.h"
#endif





typedef struct brs_d_point_st {
  long int x;
  long int y;
} brs_d_point_t;

typedef struct brs_d_line_st {
  brs_d_point_t p1;
  brs_d_point_t p2;
} brs_d_line_t;

typedef struct brs_d_rect_st {
  long int  left_x;
  long int  top_y;
  long int  right_x;
  long int  bottom_y;
} brs_d_rect_t;

typedef struct brs_d_circle_st {
  long int    radius;
  brs_d_point_t  centre;
} brs_d_circle_t;

typedef struct brs_d_polygon_st {
  int         start_index;
  int         size;
  brs_d_point_t *points;
} brs_d_polygon_t;

typedef union brs_d_shape_st {
  brs_d_rect_t    *rect;
  brs_d_circle_t  *circle;
  brs_d_polygon_t *poly;
} brs_d_shape_u;

struct brs_d_area_def_st {
  struct brs_d_area_def_st  *next;
  int                     type;
  brs_d_shape_u              shape;
  brs_dt_tree_node_t         *area_node;
};

struct brs_d_server_image_map_st {
  int             handle;
  brs_dt_tree_node_t *href_node; 
};

struct brs_d_client_image_map_st {
  int              handle;
  const char      *name;       
  brs_d_area_def_t   *area_defs;  
};

typedef union brs_d_image_map_data_u {
  brs_d_server_image_map_t *server_map;
  brs_d_client_image_map_t *client_map;
} brs_d_image_map_data_t;

struct brs_d_image_map_st {
  struct brs_d_image_map_st *next;
  int                     image_map_type;  
  brs_d_image_map_data_t     map_data;
};




void
brs_d_add_new_image_map (brs_d_doc_t *d, brs_dt_tree_node_t *map_node);

void
brs_d_close_current_image_map (brs_d_doc_t *d);

void
brs_d_add_area_definition (brs_d_doc_t *d, brs_dt_tree_node_t *area_node);

brs_d_image_map_t*
brs_d_find_image_map (brs_d_doc_t *d, int handle);

brs_d_image_map_t*
brs_d_find_client_map (brs_d_doc_t *d, const char *map_name);

brs_d_area_def_t*
brs_d_find_client_map_area (brs_d_image_map_t *image_map, brs_d_object_select_event_t *event);

brs_d_image_map_t*
brs_d_new_server_image_map (brs_d_doc_t *d, brs_dt_tree_node_t *map_node);

void
brs_d_delete_server_image_map (brs_d_server_image_map_t *server_map);

brs_d_image_map_t*
brs_d_new_client_image_map (brs_d_doc_t *d, brs_dt_tree_node_t *map_node);

void
brs_d_delete_client_image_map (brs_d_client_image_map_t *client_map);

brs_d_image_map_t*
brs_d_new_image_map (brs_d_doc_t *d, int map_type);

void
brs_d_delete_image_map (brs_d_image_map_t *image_map);







int
brs_d_add_image_ref (brs_d_doc_t *d, brs_dt_tree_node_t *image_node);

#endif

#endif
