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
 * msf_pdec.h
 *
 * XML and HTML parser: WBXML decoder
 */

#ifndef _msf_pdec_h
#define _msf_pdec_h

#ifndef _msf_ptxt_h
#include "msf_ptxt.h"
#endif


/**************************************************************
 * Functions                                                  *
 **************************************************************/

int
msf_dec_prologueDecoder (msf_prsr_parser_t*  parser,
                         const char*         s,
                         const char*         end,
                         const char*        *nextPtr,
                         int                 limit);

/*
 * Common WBXML opaque data handler. Writes opaque data as normal
 * text. This means opaque data can be be a part of any string
 * in character data callbacks.
 *
 * If WBXML opaque data is not to be ignored, then in the
 * initiation callback, set d->specific = msf_dec_opaqueSpecific.
 */
/* Declared in msf_prsr.h.
int 
msf_dec_opaqueSpecific (msf_prsr_parser_t*  parser,
                        const char*        *s,
                        const char*         end,
                        int                 size,
                        int                 type);
*/


/*
 * Push opaque data handler. Write 7 bytes from attribute opaque
 * data and fill with zeros if indata is less than 7 bytes.
 */
int 
msf_dec_pushSpecific (msf_prsr_parser_t*  parser,
                      const char*        *s,
                      const char*         end,
                      int                 size,
                      int                 type);

/*
 * WML variable handler. Decodes WML extention tokens into variables.
 */ 
int 
msf_dec_wmlSpecific (msf_prsr_parser_t*  parser,
                     const char*        *s,
                     const char*         end,
                     int                 tok,
                     int                 isElement);



#endif
