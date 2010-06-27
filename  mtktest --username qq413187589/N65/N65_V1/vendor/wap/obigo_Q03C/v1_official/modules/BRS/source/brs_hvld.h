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







#ifndef _brs_hvld_h
#define _brs_hvld_h

#ifndef _msf_prsr_h
#include "msf_prsr.h"
#endif

#ifndef _msf_chrs_h
#include "msf_chrs.h"
#endif

#ifndef _brs_ua_h
#include "brs_ua.h"
#endif






#define BRS_HVLD_STATE_START        0
#define BRS_HVLD_STATE_HTML         1
#define BRS_HVLD_STATE_HEAD         2
#define BRS_HVLD_STATE_BODY         3
#define BRS_HVLD_STATE_FRAMESET     4
#define BRS_HVLD_STATE_NOFRAMES     5
#define BRS_HVLD_STATE_FRAMESET_END 6
#define BRS_HVLD_STATE_WML_START    7
#define BRS_HVLD_STATE_WML          8


#define BRS_HVLD_MAX_DEPTH          60







typedef struct {
  int                  instanceId;
  brs_ua_document_t   *document;
  char                *pipeName;
  int                  datasourceHandle;
  const MSF_UINT8     *elementClass;
  const MSF_UINT32    *acceptedChildren;
  const MSF_UINT8      (*restrictionsTable)[2];
  int                  depth;
  int                  state;
  int                  contentType;
  MSF_UINT8            stack[BRS_HVLD_MAX_DEPTH];
  MSF_UINT8            restrictions[BRS_HVLD_MAX_DEPTH + 1];
  brs_dt_tree_node_t  *last_whitespace_node; 
  char                *last_whitespace_char; 
  msf_prsr_parser_t   *parser;
  char                *text_buffer;
  int                  charset;
#ifdef BRS_LOG_PARSER
  int                  textMode;
#endif

} brs_hvld_UserData;



















int
brs_hvld_initParserObject (msf_prsr_parserData_t*  p,
                           msf_prsr_decoderData_t* d,
                           const char*             doctype_str,
                           int                     len,
                           int                     doctype_int,
                           int                     charset);









int 
brs_hvld_piHandler (void*              userData,
                    msf_prsr_parser_t* parser,
                    const char*        target,
                    const char*        data,
                    const char*        end);

















int
brs_hvld_finishDocument (brs_hvld_UserData* userData);






void
brs_hvld_changeCharset (void* userData, msf_charset_convert_t* cvtFunct);

#endif
