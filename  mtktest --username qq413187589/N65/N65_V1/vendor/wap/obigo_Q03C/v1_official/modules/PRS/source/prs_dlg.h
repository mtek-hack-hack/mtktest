/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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







#ifndef _prs_dlg_h
#define _prs_dlg_h

#ifndef _prs_def_h
#include "prs_def.h"
#endif







#define PRS_DLG_PIN                     1   /* --> show confirm install popup */
#define PRS_DLG_PIN_AGAIN               2


#define PRS_DLG_RESPONSE_POSITIVE       1
#define PRS_DLG_RESPONSE_NEGATIVE       2
#define PRS_DLG_RESPONSE_CANCEL         3


#define PRS_DLG_PIN_NUM_HANDLES         6






typedef struct {
  int        type;
  int        response;
  int        num_handles;
  MSF_UINT32 handle[PRS_DLG_PIN_NUM_HANDLES];
} prs_dlg_t;










MSF_UINT32
prs_dlgCreateScreen (void);
  




void
prs_dlgDeleteScreen (MSF_UINT32 screenHandle);





#ifdef __MMI_DUAL_SIM__
prs_dlg_t *
prs_dlgCreate (MSF_UINT32 screenHandle, int dialogType, int msg, int network_account_id);
#else
prs_dlg_t *
prs_dlgCreate (MSF_UINT32 screenHandle, int dialogType, int msg);
#endif






void
prs_dlgDelete (prs_dlg_t* dlg);






void
prs_dlgAction (prs_dlg_t* dlg, MSF_UINT32 action);







int
prs_dlgGetType (prs_dlg_t* dlg);






MSF_UINT32
prs_dlgGetDialogHandle (prs_dlg_t* dlg);










char *
prs_dlgGetInput (prs_dlg_t* dlg, int idx, int* inputLen);







int
prs_dlgGetResponse (prs_dlg_t* dlg);


#endif


