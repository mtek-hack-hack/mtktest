/*
 * Copyright (C) Obigo AB, 2002-2006.
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

























#ifndef _stk_hdrc_h
#define _stk_hdrc_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_cmmn_h
#include "msf_cmmn.h"
#endif

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif

#ifndef _stk_hdr_h
#include "stk_hdr.h"
#endif





extern const msf_strtable_info_t params;




#define HDR_CVT_LENGTH_QUOTE            31
#define HDR_CVT_QUOTE                   127
#define HDR_CVT_DATESTRING_LENGTH       29
#define HDR_CVT_SPACE                   0x20










		
int
hdr_cvt_short_int (msf_dcvt_t* obj, MSF_UINT8* p); 






		
int
hdr_cvt_long_int (msf_dcvt_t* obj, MSF_UINT32* p);






		
int
hdr_cvt_string_length (msf_dcvt_t* obj);









int
hdr_cvt_string (msf_dcvt_t* obj, char** p);









int 
hdr_cvt_text_value (msf_dcvt_t* obj, char** p);







int
hdr_cvt_int_val (msf_dcvt_t* obj, MSF_UINT32* p);










int
hdr_cvt_authenticate (msf_dcvt_t* obj, hdr_element_t* elt);









int
hdr_cvt_profilewarning (msf_dcvt_t* obj, hdr_element_t* elt, int encoding_version);











int
hdr_cvt_cachecontrol (msf_dcvt_t* obj, hdr_cachecontrol_t* p);













int
hdr_cvt_parameters (msf_dcvt_t* obj, int* paramslength, hdr_element_t *elt);







int
hdr_cvt_contenttype (msf_dcvt_t* obj, hdr_element_t *elt, int encoding_version);



int
hdr_cvt_content_md5 (msf_dcvt_t *obj, hdr_element_t *elt, int encoding_version);









int
hdr_cvt_data_string (msf_dcvt_t* obj, hdr_element_t* elt, int encoding_version);










int
hdr_cvt_authorization (msf_dcvt_t* obj, hdr_element_t *elt);









int 
hdr_cvt_encoding_version (msf_dcvt_t* obj, hdr_element_t *elt, int encoding_version);









int
hdr_cvt_quoted_string (msf_dcvt_t* obj, char** p);









int 
hdr_cvt_te (msf_dcvt_t* obj, hdr_element_t *elt, int encoding_version);









int 
hdr_cvt_retry_after (msf_dcvt_t* obj, hdr_element_t *elt, int encoding_version);









int
hdr_cvt_content_disposition (msf_dcvt_t* obj, hdr_element_t *elt, int encoding_version);









int
hdr_cvt_cookie (msf_dcvt_t* obj, hdr_element_t *elt, int encoding_version);















int
hdr_cvt_txt_content_type (char *contentstring, hdr_element_t *elt);









int
hdr_cvt_txt_cache_control(char* str, hdr_cachecontrol_t* cachestruct);















void
hdr_cvt_levelint_to_str (int level, char *s);

#endif
