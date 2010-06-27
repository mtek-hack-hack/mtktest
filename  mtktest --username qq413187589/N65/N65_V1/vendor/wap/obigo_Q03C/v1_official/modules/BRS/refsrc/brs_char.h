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
/*
 * brs_char.h
 *
 * Created by Örjan Percy
 *
 * Revision history:
 *
 */
#ifndef _brs_char_h
#define _brs_char_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_int_h
#include "msf_int.h"
#endif

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif

/**********************************************************************
 * Exported functions
 **********************************************************************/

int
brs_wml_input_validate_value(const char *format,
                             int is_valid_format,
                             char **value,
                             int empty_ok,
                             int *is_modified,
                             int *err_pos,
                             brs_input_validation_error_t *err_type);

int
brs_wml_input_format_correct(MsfStringHandle* string,
                             int* use_str_out,
                             const char* format,
                             int is_valid_format,
                             int empty_ok);

void
brs_text_transform(char** str, int transform);
#endif
