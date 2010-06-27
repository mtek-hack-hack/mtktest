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













#ifndef _uis_ndx_h_
#define _uis_ndx_h_

#ifndef _uis_msg_h_
  #include "uis_msg.h"
#endif

#ifndef _uis_job_h
  #include "uis_job.h"
#endif





 



#define UIS_NDX_PADDING     0x00

#define UIS_NDX_NEW_MSG     0x01

#define UIS_NDX_DEL_MSG     0x02

#define UIS_NDX_CHANGE_MSG  0x03





#define UIS_NDX_INIT_DELETE(item, handle)   \
  (item)->header = UIS_NDX_DEL_MSG;         \
  (item)->data.del_msg = (handle)

#define UIS_NDX_INIT_NEW(item, msg)   \
  (item)->header = UIS_NDX_NEW_MSG;   \
  (item)->data.new_msg = (msg)

#define UIS_NDX_INIT_CHANGE(item, msg)  \
  (item)->header = UIS_NDX_CHANGE_MSG;  \
  (item)->data.change_msg = (msg)





typedef struct {
  MSF_UINT8  header;
  union {
    uis_msg_item_t* new_msg;
    uis_msg_item_t* change_msg;
    uis_msg_handle_t* del_msg;
  }data;
} uis_ndx_item_t;





void 
uis_ndx_item_init (uis_ndx_item_t *p);

int
uis_ndx_item_init_and_cvt (msf_dcvt_t *obj, uis_ndx_item_t *p);

int 
uis_cvt_ndx_item (msf_dcvt_t *obj, uis_ndx_item_t *p);








void 
uis_ndx_write_item_job (uis_job_q_head_t* queue, int file_id, uis_ndx_item_t *item, 
                        long* result);



#endif


