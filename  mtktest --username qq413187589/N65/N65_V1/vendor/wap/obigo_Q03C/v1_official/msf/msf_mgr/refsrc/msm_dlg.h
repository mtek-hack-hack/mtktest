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
 * msm_dlg.h
 *
 * Created by Robert Moricz, Fri Oct 24 2003.
 *
 * Revision  history:
 *   031024, rmz: Created
 *
 */
#ifndef _msm_dlg_h
#define _msm_dlg_h

#ifndef  _msf_def_h
#include "msf_def.h"
#endif

#include "msf_int.h"

/**********************************************************************
 * Constants
 **********************************************************************/

/* Object action (objact) types of menues & dialogues */
#define MSM_DLG_OBJACT_ACTION_MENU                1
#define MSM_DLG_OBJACT_NO_ACTION_INFO             2

#if defined(CONTENT_OBJECT_ACTION_DISABLE)
#define MSM_DLG_GEN_INFO_MENU                     3
#endif

/* Response types */
#define MSM_DLG_RESPONSE_POSITIVE                 1
#define MSM_DLG_RESPONSE_NEGATIVE                 2
#define MSM_DLG_RESPONSE_CANCEL                   3


/**********************************************************************
 * Parameters for different dialog types
 **********************************************************************/

/*
 * The call to msf_dlgCreate must have exactly this many elements
 * in the 'strings' array and str_ids array, for each of the Dialog
 * types below:
 *
 * MSM_DLG_OBJACT_NO_ACTION_INFO :
 *   0 string parameters & str_id parameters 
 *
 * MSM_DLG_OBJACT_ACTION_MENU:				        
 *   0 string parameter and n str_id parameters (n > 0): 
 *
 */

/**********************************************************************
 * Type definitions
 **********************************************************************/

typedef struct msm_dlg_st msm_dlg_t;


/**********************************************************************
 * Exported functions
 **********************************************************************/

/*
 * Create a dialog.
 * Returns a pointer to a struct msm_dlg_st, or NULL on error.
 */
msm_dlg_t *
msm_dlgCreate (MSF_UINT32 screenHandle, int dialogType,
               int numStrings, const char *strings[],
               int numStrId, const MSF_INT32 str_ids[]);


/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
msm_dlgDelete (msm_dlg_t *dlg);

/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
msm_dlgAction (msm_dlg_t *dlg, MSF_UINT32 action);

/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
msm_dlgGetType (msm_dlg_t *dlg);

/*
 * Return the Dialog Handle associated with the specified dialog.
 * Returns 0 on error. 
 */
MSF_UINT32
msm_dlgGetDialogHandle (msm_dlg_t *dlg);


/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling msm_dlgAction).
 */
int
msm_dlgGetResponse (msm_dlg_t *dlg);

/*
 * Return the selected index incase of a menu Item
 * Returns -1 if index not found.
 */
int
msm_dlgGetMenuIndex (msm_dlg_t *dlg);


/*
 * Display a no action dialog
 *
 * parameters:
 *  screen ** is set to address of op->screeen
 *  window  * is set to address of op->window
 * 
 */

void
msm_dlg_display_no_action_dialog (msm_dlg_t **window,  MsfScreenHandle *screen);


#endif
