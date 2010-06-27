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









#ifndef _uis_keyv_h
#define _uis_keyv_h 




#ifndef _msf_def_h
#include "msf_def.h"
#endif 

#ifndef _uis_main_h
#include "uis_main.h"
#endif





typedef struct{
  MSF_UINT16        propertyArraySize;
  uis_key_value_t  *propertyArray;
} uis_key_value_array_t;





void
uis_key_value_array_init (uis_key_value_array_t* p);




void 
uis_key_value_array_release (uis_key_value_array_t* p);






void
uis_key_value_update (uis_key_value_array_t* p, uis_key_value_array_t* change);




int
uis_cvt_key_value (msf_dcvt_t *obj, uis_key_value_t *p);




int
uis_cvt_key_value_array (uis_key_value_array_t *p, msf_dcvt_t *obj);





int
uis_key_value_array_is_subset (uis_key_value_array_t* p, uis_key_value_array_t* subset);






void
uis_key_value_array_get_subset (uis_key_value_array_t* p, 
                                int keyListSize, const unsigned *keyList, 
                                uis_key_value_array_t *result);


#endif


