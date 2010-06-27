/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */








#ifndef _uis_msg_h_
#define _uis_msg_h_




#ifndef _uis_main_h
#include "uis_main.h"
#endif

#ifndef _uis_keyv_h
#include "uis_keyv.h"
#endif





#define UIS_MSG_ITEM_HAS_DATA_FILE_MASK                0x01
#define UIS_MSG_ITEM_HAS_HIDDEN_PROPERTIES_FILE_MASK   0x02
#define UIA_MSG_ITEM_IS_TOUCED_FILE_MASK               0x04

typedef struct  {
  uis_msg_handle_t                    handle;
  uis_key_value_array_t               propertyArray;
  MSF_UINT32                          fileId;
  MSF_UINT8                           flags;
  
  
  int                                 handle_hash; 
} uis_msg_item_t;







void 
uis_msg_handle_init (uis_msg_handle_t *p);


int
uis_msg_handle_init_and_cvt(msf_dcvt_t *obj, uis_msg_handle_t *p);

void
uis_msg_handle_release(uis_msg_handle_t *p);

int
uis_cvt_msg_handle (msf_dcvt_t *obj, uis_msg_handle_t *p);









#define UIS_MSG_HAS_DATA_FILE(p) \
  ((p)->flags & UIS_MSG_ITEM_HAS_DATA_FILE_MASK)


#define UIS_MSG_HAS_HIDDEN_PROPERTIES_FILE(p) \
  ((p)->flags & UIS_MSG_ITEM_HAS_HIDDEN_PROPERTIES_FILE_MASK)


#define UIS_MSG_IS_TOUCHED(p) \
  ((p)->flags & UIA_MSG_ITEM_IS_TOUCED_FILE_MASK)

#define UIS_MSG_SET_FILE_ID(p, value) \
  ((p)->fileId = (value))

#define UIS_MSG_GET_FILE_ID(p) \
  ((p)->fileId)

#define UIS_MSG_SET_HAS_DATA_FILE(p) \
  ((p)->flags |= UIS_MSG_ITEM_HAS_DATA_FILE_MASK) 

#define UIS_MSG_SET_HAS_NO_DATA_FILE(p) \
  ((p)->flags &= ~UIS_MSG_ITEM_HAS_DATA_FILE_MASK) 
  
#define UIS_MSG_SET_HAS_HIDDEN_PROPERTIES_FILE(p) \
 ((p)->flags |= UIS_MSG_ITEM_HAS_HIDDEN_PROPERTIES_FILE_MASK) 

#define UIS_MSG_TOUCH(p) \
  ((p)->flags |= UIA_MSG_ITEM_IS_TOUCED_FILE_MASK) 


#define UIS_MSG_GET_PROPERTY_ARRAY(p) \
  (&((p)->propertyArray))


#define UIS_MSG_ITEM_CHANGE_HANDLE(msg, h) \
  UIS_MSG_HANDLE_SWAP(&((msg)->handle), (h))







void
uis_msg_init (uis_msg_item_t *p);


int 
uis_msg_init_and_cvt(msf_dcvt_t *obj, uis_msg_item_t *p);


void 
uis_msg_release (uis_msg_item_t *p);


void
uis_msg_set_handle (uis_msg_item_t *p, const uis_msg_handle_t *handle);


void 
uis_msg_change (uis_msg_item_t *org, uis_msg_item_t *msg);


int 
uis_msg_hash (uis_msg_item_t* data);


int 
uis_msg_compare (uis_msg_item_t* key_a, uis_msg_item_t* key_b);

int
uis_cvt_msg_item (msf_dcvt_t *obj, uis_msg_item_t *p);




int
uis_cvt_msg_list_item (msf_dcvt_t *obj, uis_msg_list_item_t *p);

#endif 


