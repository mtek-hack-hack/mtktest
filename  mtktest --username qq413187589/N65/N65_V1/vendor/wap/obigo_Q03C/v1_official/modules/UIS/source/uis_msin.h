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







 

#ifndef _uis_msin_h
#define _uis_msin_h

#ifndef _uis_sig_h
#include "uis_sig.h"
#endif










#define UIS_MSG_STORE_SIG_GET_NBR_OF_MSGS       (UIS_MODULE_MSG_STORE + 1)
#define UIS_MSG_STORE_SIG_GET_MSG_LIST          (UIS_MODULE_MSG_STORE + 2)
#define UIS_MSG_STORE_SIG_GET_MSG               (UIS_MODULE_MSG_STORE + 3)
#define UIS_MSG_STORE_SIG_GET_FULL_MSG          (UIS_MODULE_MSG_STORE + 4)
#define UIS_MSG_STORE_SIG_DELETE_MSG            (UIS_MODULE_MSG_STORE + 5)
#define UIS_MSG_STORE_SIG_CHANGE_MSG            (UIS_MODULE_MSG_STORE + 6)
#define UIS_MSG_STORE_SIG_CREATE_MSG            (UIS_MODULE_MSG_STORE + 7)
#define UIS_MSG_STORE_SIG_FILE_NOTIFY           (UIS_MODULE_MSG_STORE + 8)
#define UIS_MSG_STORE_SIG_SET_MSG_PROPERTY      (UIS_MODULE_MSG_STORE + 9)






#define UIS_MSG_STORE_MAX_PATH_LEN          64

#define UIS_MSG_STORE_MSG_DATA_FILE         "/uis/%i/%lu.dat"


#define UIS_MSG_STORE_MSG_HIDDEN_PROP_FILE  "/uis/%i/%lu.hpf"

















void
uis_msg_store_init (void);

void
uis_msg_store_terminate (void);

void
uis_msg_store_terminate_done (void);







#endif


