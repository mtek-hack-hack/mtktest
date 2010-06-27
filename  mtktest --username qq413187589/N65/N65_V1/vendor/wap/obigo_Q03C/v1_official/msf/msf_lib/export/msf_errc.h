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
#ifndef _msf_errc_h
#define _msf_errc_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif

/* System errors */
#define MSF_ERR_SYSTEM_REG_ABORTED                  HDI_ERR_SYSTEM_REG_ABORTED
#define MSF_ERR_SYSTEM_REG_FILE_CORRUPT             HDI_ERR_SYSTEM_REG_FILE_CORRUPT
#define MSF_ERR_SYSTEM_FATAL                        HDI_ERR_SYSTEM_FATAL
#define MSF_ERR_SYSTEM_REG_TXT_FILE                 HDI_ERR_SYSTEM_REG_TXT_FILE
#define MSF_ERR_SYSTEM_REG_TXT_PARSE                HDI_ERR_SYSTEM_REG_TXT_PARSE

/* Module errors */
#define MSF_ERR_MODULE_OUT_OF_MEMORY                HDI_ERR_MODULE_OUT_OF_MEMORY


#define MSF_ERROR                                   HDIa_error

#endif
