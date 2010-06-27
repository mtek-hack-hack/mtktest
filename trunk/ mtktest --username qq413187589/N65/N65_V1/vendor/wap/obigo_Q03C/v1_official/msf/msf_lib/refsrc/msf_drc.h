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
 * msf_drc.h (msf dialog resources)
 *
 * Created by Robert Moricz, Fri Oct 24 2003.
 *
 * Revision  history:
 *   031024, rmz: Created
 *
 */
#ifndef _msf_drc_h
#define _msf_drc_h

#ifndef  _msf_def_h
#include "msf_def.h"
#endif

/**********************************************************************
 * Constants
 **********************************************************************/

/* Object action (objact) types of menues & dialogues */
#define MSF_DRC_OBJACT_SUBACTION_MENU             1

/* Response types */
#define MSF_DRC_RESPONSE_POSITIVE                 1
#define MSF_DRC_RESPONSE_NEGATIVE                 2
#define MSF_DRC_RESPONSE_CANCEL                   3


/**********************************************************************
 * Parameters for different dialog types
 **********************************************************************/

/*
 * The call to msf_dlgCreate must have exactly this many elements
 * in the 'strings' array and str_ids array, for each of the Dialog
 * types below:
 *
 * MSF_DRC_OBJACT_SUBACTION_MENU:				        
 *   0 string parameter and n str_id parameters (n > 0): 
 * 
 */

/**********************************************************************
 * Type definitions
 **********************************************************************/

typedef struct msf_drc_st msf_drc_t;


/**********************************************************************
 * Exported functions
 **********************************************************************/

/*
 * Create a dialog.
 * Returns a pointer to a struct msf_drc_st, or NULL on error.
 */
msf_drc_t *
msf_drcCreate (MSF_UINT8 client_modid, MSF_UINT32 screenHandle,
               int dialogType, int numStrings, const char *strings[],
               int numStrId, const MSF_INT32 str_ids[]);

/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
msf_drcDelete (msf_drc_t *dlg);

/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
msf_drcAction (msf_drc_t *dlg, MSF_UINT32 action);

/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
msf_drcGetType (msf_drc_t *dlg);

/*
 * Return the Dialog Handle associated with the specified dialog.
 * Returns 0 on error. 
 */
MSF_UINT32
msf_drcGetDialogHandle (msf_drc_t *dlg);


/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling msf_drcAction).
 */
int
msf_drcGetResponse (msf_drc_t *dlg);

/*
 * Return the selected index incase of a menu Item
 * Returns -1 if index not found.
 */
int
msf_drcGetMenuIndex (msf_drc_t *dlg);


#endif
