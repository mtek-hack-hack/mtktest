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






#ifndef _brs_levt_h
#define _brs_levt_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif

#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif

#define IS_NOT_INPUT_IMAGE_IN_SELECT_MODE(evt) !(evt->markable_elements & BRS_MARKABLE_ELEMENT_INPUT_IMAGE) && \
                                                (evt->markable_elements & BRS_MARKABLE_ELEMENT_INPUT)





void
brs_le_free_event (brs_le_event_t* event);

void
brs_le_clean_event (brs_le_event_t* event);












void
brs_le_add_accesskey (brs_le_event_t*     evt,
                      MsfGadgetHandle     handle,
                      brs_dt_tree_node_t* node);





MSF_UINT32
brs_le_find_accesskey_handle (brs_dt_tree_node_t* node, brs_le_event_t* evt);




void
brs_le_handle_widget_access_key (brs_le_event_t* evt, msf_widget_access_key_t* access_key);










void
brs_le_add_gadget (MsfGadgetHandle     handle,
                   brs_dt_tree_node_t* node,
                   brs_le_event_t*     evt);





void
brs_le_remove_all_gadgets (brs_le_event_t* evt);





brs_le_gadget_item_t*
brs_le_find_gadget (MSF_UINT32 handle, brs_le_view_t** res_view);








void
brs_le_add_visible_gadget (MsfGadgetHandle     handle,
                           brs_dt_tree_node_t* node,
                           brs_le_event_t*     evt,
                           MsfPosition*        msf_pos);


void
brs_le_redraw_visible_gadget(MsfGadgetHandle     handle,
                           brs_dt_tree_node_t* node,
                           brs_le_event_t*     evt,
                           MsfPosition*        msf_pos);



void
brs_le_draw_visible_gadgets(brs_le_event_t*    evt);





void
brs_le_remove_visible_gadgets (brs_le_event_t* evt);






int
brs_le_gadget_notify (brs_le_view_t* view, msf_widget_notify_t *notify);





void
brs_le_gadget_focus (brs_dt_tree_node_t* node, brs_le_event_t* evt, int focus);





void
brs_le_focus_active_gadget (brs_le_event_t* evt);





void
brs_le_reselect_input_node (brs_le_event_t* evt, int focus);





void
brs_le_action_activated (MSF_UINT32 action, brs_le_event_t* evt);




void
brs_le_init_actions(void);

void
brs_le_terminate_actions(void);

void
brs_le_handle_userevt(brs_le_event_t* evt, msf_widget_userevt_t* u_evt);

void
brs_le_remove_gadget_actions (brs_le_event_t* evt);

void
brs_le_select_box(brs_le_boxt_box_t* box, brs_le_event_t* evt, MsfEvent* event, brs_le_pos_t* pos);

void
brs_le_select_input (brs_dt_tree_node_t* node, brs_le_event_t* evt);


#endif
