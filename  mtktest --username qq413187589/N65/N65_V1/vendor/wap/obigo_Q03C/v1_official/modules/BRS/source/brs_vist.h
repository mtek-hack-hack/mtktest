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











#ifndef _brs_vist_h
#define _brs_vist_h









void
brs_vist_init (void);




void
brs_vist_terminate (void);




void
brs_vist_clear (void);




void
brs_vist_add_url (const char *url);





int
brs_vist_check_url (const char *url);

#endif
