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
/*
 * phs_dlg.h
 *
 * Created by Kent Olsson, Wed Nov 21 18:23:35 2002.
 *
 * Revision history:
 *
 */

#ifndef _phs_dlg_h
#define _phs_dlg_h


#ifndef  _msf_def_h
#include "msf_def.h"
#endif


/**********************************************************************
 * Constants
 **********************************************************************/

/* Types of dialogues */
#define PHS_DLG_SIA_CONFIRM                       1
#define PHS_DLG_WHITELIST_NO_MATCH                2

/* Response types */
#define PHS_DLG_RESPONSE_POSITIVE                 1
#define PHS_DLG_RESPONSE_NEGATIVE                 2
#define PHS_DLG_RESPONSE_CANCEL                   3

/**********************************************************************
 * Parameters for different dialog types
 **********************************************************************/

/*
 * The call to phs_dlgCreate must have exactly this many elements
 * in the 'strings' array, for each of the Dialog types below:
 *
 * PHS_DLG_SIA_CONFIRM: 3 string parameters
 *   0: the message to display to the user
 *   1: string to display on the Ok button (or empty string/NULL for default)
 *   2: string to display on the Cancel button (or empty string/NULL for default)
 *
 */

/**********************************************************************
 * Type definitions
 **********************************************************************/
struct phs_dlg_st {
  int        type;
  int        response;
  int        num_handles;
  MSF_UINT32 handle[8];
};

typedef struct phs_dlg_st phs_dlg_t;

/**********************************************************************
 * Exported functions
 **********************************************************************/
void
phs_dlg_init (void);

void
phs_dlg_terminate (void);

/*
 * Create a dialog.
 * Returns a pointer to a struct phs_dlg_st, or NULL on error.
 */
phs_dlg_t *
phs_dlgCreate (int dialogType, int numStrings, MSF_UINT32 strings[], char* info);

/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 * If moreDialogs = TRUE, teh screen should be removed and released
 */
void
phs_dlgDelete (phs_dlg_t *dlg, int moreDialogs);

/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
phs_dlgAction (phs_dlg_t *dlg, MSF_UINT32 action);

/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
phs_dlgGetType (phs_dlg_t *dlg);

/*
 * Return the Dialog Handle associated with the specified dialog.
 * Returns 0 on error. 
 */
MSF_UINT32
phs_dlgGetDialogHandle (phs_dlg_t *dlg);

/*
 * Return the input string from one of the input fields of
 * this dialog. The index of the requested input field is given
 * as 'idx', with indices starting at 0.
 * Returns NULL on error.
 * NOTE: it is the responsibility of the caller to deallocate
 * the returned string.
 */
char *
phs_dlgGetInput (phs_dlg_t *dlg, int idx);

/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling phs_dlgAction).
 */
int
phs_dlgGetResponse (phs_dlg_t *dlg);

#endif


