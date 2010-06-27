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
/*
 * msf_dcvt.h
 *
 * Created by Anders Edenbrandt.
 *
 * Revision history:
 *   010612, AED: New function, data_cvt_change_pos.
 *   011025, AED: Cleanup.
 *   020402, IPN: Changed to fit Mobile Suite Framework.
 *
 */
/************************************************************
 * Functions to convert between an external and an internal
 * representation.
 *
 * All decoding and encoding functions take a pointer to a
 * "conversion object" (see type definition below) as
 * the first argument. Usually, the second argument is a pointer
 * to an element of the type to be converted.
 *
 * There are four different conversion operations:
 *   MSF_DCVT_DECODE         convert from external to internal representation
 *   MSF_DCVT_ENCODE         convert from internal to external representation
 *   MSF_DCVT_ENCODE_SIZE    calculate the buffer size required to do an
 *                             encoding operation
 *   MSF_DCVT_FREE           deallocate any memory that was allocated as
 *                             part of a previous decoding operation
 *
 * Each function returns TRUE on success and FALSE on error.
 *
 ************************************************************/
#ifndef _msf_dcvt_h
#define _msf_dcvt_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

/************************************************************
 * Macro definitions
 ************************************************************/

#define MSF_DCVT_GET_BYTE(obj)    ((obj)->data[(obj)->pos++])
#define MSF_DCVT_PUT_BYTE(obj, b) ((obj)->data[(obj)->pos++] = (unsigned char)(b))

/*
 * Return the number of bytes remaining in the buffer.
 */
#define MSF_DCVT_REM_LENGTH(str) ((str)->length - (str)->pos)


#define MSF_DCVT_DECODE             1
#define MSF_DCVT_ENCODE             2
#define MSF_DCVT_ENCODE_SIZE        3
#define MSF_DCVT_FREE               4

/*
 * The object used for converting between internal
 * and external data representation.
 */
typedef struct {
  long           pos;
  long           length;
  short          operation;
  unsigned char *data;
  MSF_UINT8      module;
} msf_dcvt_t;

typedef int msf_dcvt_element_t (msf_dcvt_t *obj, void *p);

void
msf_dcvt_init (msf_dcvt_t *obj, short operation,
               void *buf, long length, MSF_UINT8 modId);

/*
 * Change the current buffer position of the conversion object.
 * Returns TRUE if the change can be accomodated within
 * the bounds of the buffer, FALSE otherwise.
 */
int
msf_dcvt_change_pos (msf_dcvt_t* obj, long steps);

int
msf_dcvt_uint8 (msf_dcvt_t *obj, MSF_UINT8 *p);

int
msf_dcvt_int8 (msf_dcvt_t *obj, MSF_INT8 *p);

int
msf_dcvt_uint16 (msf_dcvt_t *obj, MSF_UINT16 *p);

int
msf_dcvt_int16 (msf_dcvt_t *obj, MSF_INT16 *p);

int
msf_dcvt_uint32 (msf_dcvt_t *obj, MSF_UINT32 *p);

int
msf_dcvt_int32 (msf_dcvt_t *obj, MSF_INT32 *p);

int
msf_dcvt_bool (msf_dcvt_t *obj, MSF_BOOL *p);

int
msf_dcvt_uintvar_len (MSF_UINT32 n);

int
msf_dcvt_uintvar (msf_dcvt_t *obj, MSF_UINT32 *p);

int
msf_dcvt_static_uchar_vector (msf_dcvt_t *obj, long length, unsigned char *p);

int
msf_dcvt_uchar_vector (msf_dcvt_t *obj, long length, unsigned char **p);

int
msf_dcvt_string (msf_dcvt_t *obj, char **p);

#ifdef CFG_MSF_HAS_FLOAT
int
msf_dcvt_float32 (msf_dcvt_t *obj, MSF_FLOAT32 *p);
#endif

int
msf_dcvt_array (msf_dcvt_t *obj, int element_size,
                int num_elements, void **array,
                msf_dcvt_element_t *cvt_element);

#endif
