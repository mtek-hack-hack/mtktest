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









#ifndef _brs_limg_h
#define _brs_limg_h

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif







#define BRS_LE_RENDER_DONE       0
#define BRS_LE_RENDER_MORE_TO_DO 1






typedef struct brs_le_elem_object_st  brs_le_elem_object_t;







































































void
brs_le_free_object (brs_le_elem_object_t* obj);




void
brs_le_get_object_size(brs_le_elem_object_t* obj, int* w, int* h);




void
brs_le_handle_object_loading (brs_le_view_t*        view, 
                              int                   doc_id,
                              brs_d_object_ready_t* object_data);





void
brs_le_handle_object_loaded (brs_le_view_t*        view, 
                             int                   doc_id,
                             brs_d_object_ready_t* object_data);

                             






void
brs_le_handle_pending_objects (brs_le_view_t* view, int status);





void
brs_le_empty_object_list (brs_d_object_ready_t** object_list);







int
brs_le_load_object (brs_le_view_t* view, brs_dt_tree_node_t* node, const char *url,
                    const char *local_src, const char *mime_type, MsfImageHandle *object_handle);

void
brs_le_handle_image_timer_expired(brs_le_view_t* view);




int
brs_le_object_is_loaded (brs_dt_tree_node_t *node);





                                                                             



int
brs_le_render_object (brs_dt_tree_node_t* node, 
                      brs_le_render_t*    rnd, 
                      int*                w, 
                      int*                a, 
                      int*                d, 
                      int*                h);





void
brs_le_min_max_object (brs_dt_tree_node_t* node, brs_le_render_t* rnd);









void
brs_le_draw_object (brs_le_boxt_box_t* box, brs_le_draw_t* draw);









brs_le_background_image_t*
brs_le_find_background_image_by_node (brs_dt_tree_node_t* node, brs_le_view_t* view);






void
brs_le_handle_background_images (brs_le_boxt_box_t* box, brs_le_render_t* rnd);









void
brs_le_make_background_image (brs_le_view_t* view, brs_le_background_image_t* bg_image);





void
brs_le_free_background_images (brs_le_view_t* view);







void
brs_le_clean_background_boxes (brs_le_view_t* view);










char*
brs_le_get_object_url (brs_dt_tree_node_t* n, brs_le_common_t* cmmn);





brs_le_elem_area_t*
brs_le_get_object_areas (brs_le_elem_object_t* obj);




void
brs_le_free_areas (brs_le_view_t* view);




void
brs_le_find_area_image(brs_le_view_t* view, 
                       brs_dt_tree_node_t* img_node, 
                       brs_dt_tree_node_t* area_node,
                       brs_le_imagemap_t** head_area, 
                       brs_le_elem_area_t** area);





brs_dt_tree_node_t*
brs_le_find_image_for_area(brs_le_boxt_box_t* box, brs_le_view_t* view);


#endif
