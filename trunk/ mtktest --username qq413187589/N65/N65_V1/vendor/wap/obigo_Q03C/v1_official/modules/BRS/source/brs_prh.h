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






#ifndef _brs_prh_h
#define _brs_prh_h

#ifndef _brs_sig_h
#include "brs_sig.h"
#endif

#ifndef _brs_ua_h
#include "brs_ua.h"
#endif









#define BRS_PRH_SIG_START_PARSING                    BRS_MODULE_PARSER + 1







#define BRS_PRH_SIG_PARSING_ABORTED                  BRS_MODULE_PARSER + 2
#define BRS_PRH_SIG_PARSING_COMPLETED                BRS_MODULE_PARSER + 3













#define BRS_PRH_SIG_PARSE_NEXT                       BRS_MODULE_PARSER + 4 
#define BRS_PRH_SIG_CREATE_PARSER                    BRS_MODULE_PARSER + 5
#define BRS_PRH_SIG_ABORT                            BRS_MODULE_PARSER + 6
















typedef struct {
  int                  instance_id;       
  int                  content_type_int;  
  char*                text_buffer;       
  char*                pipe_name;         
  int                  charset;           
  brs_ua_document_t*   doc;               

} brs_prh_start_parsing_t;









void
brs_prh_main (brs_signal_t* signal);





void
brs_prh_init (void);





void
brs_prh_terminate (void);





void
brs_prh_abort (int objectId);


#endif
