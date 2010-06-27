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
 * phs_dlg.c
 *
 * Created by Kent Olsson, Wed Nov 21 18:23:35 2002.
 *
 * Revision history:
 *
 */


#include "msf_def.h"
#include "msf_int.h"
#include "msf_cmmn.h"
#include "msf_core.h"
#include "msf_lib.h"
#include "msf_wid.h"

#include "phs_dlg.h"
#include "phs_main.h"
#include "phs_rc.h"

/************************************************************
 * Global variables
 ************************************************************/

int phs_screen_handle;

/**********************************************************************
 * Constants
 **********************************************************************/

/* Number of handles used by different dialog types: */
#define PHS_DLG_SIA_CONFIRM_NUM_HANDLES                     6
#define PHS_DLG_WHITELIST_NO_MATCH_NUM_HANDLES      6

/* Indices into the array of handles */
#define PHS_DLG_DIALOG_HANDLE                     1

#define PHS_DLG_MESSAGE_HANDLE                    2

#define PHS_DLG_OK_STRING_HANDLE                  3
#define PHS_DLG_OK_ACTION_HANDLE                  4
#define PHS_DLG_CANCEL_STRING_HANDLE              5
#define PHS_DLG_CANCEL_ACTION_HANDLE              6

#define PHS_DLG_NO_SCREEN                         0

/**********************************************************************
 * Type definitions
 **********************************************************************/

/**********************************************************************
 * Local functions
 **********************************************************************/

static phs_dlg_t *
phs_dlg_create (int dialog_type, int num_handles);

static int
phs_dlg_create_sia_confirm_dialog (phs_dlg_t *dlg, MSF_UINT32 message,
                                   MSF_UINT32 ok, MSF_UINT32 cancel);

static int
phs_dlg_create_whitelist_no_match_dialog (phs_dlg_t *dlg, MSF_UINT32 message,
                                          MSF_UINT32 ok, MSF_UINT32 cancel, char* info);


/**********************************************************************
 * Exported functions
 **********************************************************************/

void
phs_dlg_init (void)
{
  phs_screen_handle = PHS_DLG_NO_SCREEN;
}

void
phs_dlg_terminate (void)
{
  if (phs_screen_handle != PHS_DLG_NO_SCREEN)
    MSF_WIDGET_RELEASE (phs_screen_handle);
}

/*
 * Create a dialog.
 * Returns a pointer to a struct phs_dlg_st, or NULL on error.
 */
phs_dlg_t *
phs_dlgCreate (int dialogType, int numStrings, MSF_UINT32 strings[], char* info)
{
  phs_dlg_t *dlg = NULL;

  if (phs_screen_handle == PHS_DLG_NO_SCREEN)
    phs_screen_handle = MSF_WIDGET_SCREEN_CREATE (MSF_MODID_PHS, 0, 0);

  switch (dialogType) {
  case PHS_DLG_SIA_CONFIRM:
    if (numStrings < 3) {
      return NULL;
    }
    dlg = phs_dlg_create (dialogType, PHS_DLG_SIA_CONFIRM_NUM_HANDLES);
    phs_dlg_create_sia_confirm_dialog (dlg, strings[0], strings[1], strings[2]);
    break;

  case PHS_DLG_WHITELIST_NO_MATCH:
    if (numStrings < 3) {
      return NULL;
    }
    dlg = phs_dlg_create (dialogType, PHS_DLG_WHITELIST_NO_MATCH_NUM_HANDLES);
    phs_dlg_create_whitelist_no_match_dialog (dlg, strings[0], strings[1], strings[2], info);
    break;
    
  default:
    break;
  }

  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (phs_screen_handle, 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[PHS_DLG_DIALOG_HANDLE], 1);
  }

  return dlg;
}

/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
phs_dlgDelete (phs_dlg_t *dlg, int moreDialogs)
{
  int i;

  /* NOTE: first the Dialog window must be removed from the Screen.
   * Then we release the Dialog window. This will cause all other
   * widgets that are attached to the Dialog to be removed from
   * the Dialog window */
  MSF_WIDGET_REMOVE (phs_screen_handle, dlg->handle[PHS_DLG_DIALOG_HANDLE]);
  MSF_WIDGET_RELEASE (dlg->handle[PHS_DLG_DIALOG_HANDLE]);
  for (i = dlg->num_handles; i > 1; i--) {
    MSF_WIDGET_RELEASE (dlg->handle[i]);
  }

  if (!moreDialogs) {
    MSF_WIDGET_RELEASE (phs_screen_handle);
    phs_screen_handle = PHS_DLG_NO_SCREEN;
  }

  PHS_MEM_FREE (dlg);
}

/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
phs_dlgAction (phs_dlg_t *dlg, MSF_UINT32 action)
{
  if (dlg != NULL) {
    if (dlg->handle[PHS_DLG_OK_ACTION_HANDLE] == action) {
      dlg->response = PHS_DLG_RESPONSE_POSITIVE;
    }
    else {
      dlg->response = PHS_DLG_RESPONSE_CANCEL;
    }
  }
}

/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
phs_dlgGetType (phs_dlg_t *dlg)
{
  if (dlg == NULL)
    return 0;

  return dlg->type;
}

/*
 * Return the Dialog Handle associated with the specified dialog.
 * Returns 0 on error. 
 */
MSF_UINT32
phs_dlgGetDialogHandle (phs_dlg_t *dlg)
{
  if (dlg != NULL) {
    return dlg->handle[PHS_DLG_DIALOG_HANDLE];
  }

  return 0;
}

/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling phs_dlgAction).
 */
int
phs_dlgGetResponse (phs_dlg_t *dlg)
{
  if (dlg != NULL) {
    return dlg->response;
  }

  return 0;
}


/**********************************************************************
 * Local functions
 **********************************************************************/

static phs_dlg_t *
phs_dlg_create (int dialog_type, int num_handles)
{
  phs_dlg_t *dlg = PHS_MEM_ALLOCTYPE (phs_dlg_t);

  dlg->type = dialog_type;
  dlg->num_handles = num_handles;

  return dlg;
}


static int
phs_dlg_create_sia_confirm_dialog (phs_dlg_t *dlg, MSF_UINT32 message,
                                   MSF_UINT32 ok, MSF_UINT32 cancel)
{
  MSF_UINT32      dialog_handle;
  MsfPosition     null_pos = {0, 0};
  MsfStringHandle msg_handle = 0;
  MsfStringHandle ok_string;
  MsfStringHandle cancel_string;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  
  /* Create message string */
  if (message != 0) {
    msg_handle   = MSF_WIDGET_STRING_GET_PREDEFINED (message);
    /*MSF_WIDGET_STRING_CREATE (MSF_MODID_PHS, (char *)message, MsfUtf8,
                                             strlen (message) + 1, 0);*/
  }

  /* Create Dialog */
  dialog_handle = MSF_WIDGET_DIALOG_CREATE (MSF_MODID_PHS, msg_handle, MsfConfirmation,
                                            0, 0, 0);

  /* Action Ok */
  if (ok != 0) {
    ok_string = MSF_WIDGET_STRING_GET_PREDEFINED (ok);
    /*MSF_WIDGET_STRING_CREATE (MSF_MODID_PHS, (char *)ok, MsfUtf8,
                                          strlen (ok) + 1, 0);*/
  }
  else {
    ok_string =  MSF_WIDGET_STRING_GET_PREDEFINED (PHS_STR_ID_OK);
    
    /*MSF_WIDGET_STRING_CREATE (MSF_MODID_PHS, PHS_DLG_STRING_OK, MsfUtf8,
                                          strlen (PHS_DLG_STRING_OK) + 1, 0);
                                          */

  }
  ok_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_PHS, ok_string, MsfOk, 1, 
                                        MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION (dialog_handle, ok_action);
  dlg->handle[PHS_DLG_OK_STRING_HANDLE] = ok_string;
  dlg->handle[PHS_DLG_OK_ACTION_HANDLE] = ok_action;

  /* Action Cancel */
  if (cancel != 0) {
    cancel_string = MSF_WIDGET_STRING_GET_PREDEFINED (cancel);
    /*MSF_WIDGET_STRING_CREATE (MSF_MODID_PHS, (char *)cancel, MsfUtf8,
                                              strlen (cancel) + 1, 0);*/
  }
  else {
    cancel_string = MSF_WIDGET_STRING_GET_PREDEFINED (PHS_STR_ID_CANCEL);
    /*MSF_WIDGET_STRING_CREATE (MSF_MODID_PHS, PHS_DLG_STRING_CANCEL,
                                              MsfUtf8,
                                              strlen (PHS_DLG_STRING_CANCEL) + 1, 0);*/
  }
  cancel_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_PHS, cancel_string, MsfCancel,
                                            1, MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION (dialog_handle, cancel_action);
  dlg->handle[PHS_DLG_CANCEL_STRING_HANDLE] = cancel_string;
  dlg->handle[PHS_DLG_CANCEL_ACTION_HANDLE] = cancel_action;

  dlg->handle[PHS_DLG_MESSAGE_HANDLE] = msg_handle;
  dlg->handle[PHS_DLG_DIALOG_HANDLE] = dialog_handle;

  MSF_WIDGET_SCREEN_ADD_WINDOW (phs_screen_handle,
                                dialog_handle, &null_pos, 0, 0);

  return 0;
}

static int
phs_dlg_create_whitelist_no_match_dialog (phs_dlg_t *dlg, MSF_UINT32 message,
                                          MSF_UINT32 ok, MSF_UINT32 cancel, char* info)
{
  MSF_UINT32        dialog_handle;
  MsfPosition       null_pos = {0, 0};
  MsfStringHandle   msg_handle = 0;
  MsfStringHandle   ok_string;
  MsfStringHandle   cancel_string;
  MsfStringHandle   message_text_handle = 0;
  MsfActionHandle   ok_action;
  MsfActionHandle   cancel_action;
  char             *predefined_text, *new_text = NULL;
  int               predefined_text_len;
  
  /* Create message string */
  if (message != 0) {
    msg_handle   = MSF_WIDGET_STRING_GET_PREDEFINED (message);
    predefined_text_len = MSF_WIDGET_STRING_GET_LENGTH (msg_handle, 1, MsfUtf8) + 1;
    predefined_text = PHS_MEM_ALLOC (predefined_text_len);
    MSF_WIDGET_STRING_GET_DATA (msg_handle, predefined_text, MsfUtf8);
    new_text = PHS_MEM_ALLOC (predefined_text_len + strlen (info));
    sprintf(new_text, "%s: %s",predefined_text, info);
    MSF_WIDGET_RELEASE (msg_handle);
    PHS_MEM_FREE (predefined_text);
    message_text_handle = MSF_WIDGET_STRING_CREATE (MSF_MODID_PHS, new_text, MsfUtf8,
                                                    strlen (new_text) + 1, 0);
  }

  /* Create Dialog */
  dialog_handle = MSF_WIDGET_DIALOG_CREATE (MSF_MODID_PHS, message_text_handle, MsfConfirmation,
                                            0, 0, 0);

  /* Action Ok */
  if (ok != 0) {
    ok_string = MSF_WIDGET_STRING_GET_PREDEFINED (ok);
    /*MSF_WIDGET_STRING_CREATE (MSF_MODID_PHS, (char *)ok, MsfUtf8,
                                          strlen (ok) + 1, 0);*/
  }
  else {
    ok_string =  MSF_WIDGET_STRING_GET_PREDEFINED (PHS_STR_ID_OK);
    
    /*MSF_WIDGET_STRING_CREATE (MSF_MODID_PHS, PHS_DLG_STRING_OK, MsfUtf8,
                                          strlen (PHS_DLG_STRING_OK) + 1, 0);
                                          */

  }
  ok_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_PHS, ok_string, MsfOk, 1, 
                                        MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION (dialog_handle, ok_action);
  dlg->handle[PHS_DLG_OK_STRING_HANDLE] = ok_string;
  dlg->handle[PHS_DLG_OK_ACTION_HANDLE] = ok_action;

  /* Action Cancel */
  if (cancel != 0) {
    cancel_string = MSF_WIDGET_STRING_GET_PREDEFINED (cancel);
    /*MSF_WIDGET_STRING_CREATE (MSF_MODID_PHS, (char *)cancel, MsfUtf8,
                                              strlen (cancel) + 1, 0);*/
  }
  else {
    cancel_string = MSF_WIDGET_STRING_GET_PREDEFINED (PHS_STR_ID_CANCEL);
    /*MSF_WIDGET_STRING_CREATE (MSF_MODID_PHS, PHS_DLG_STRING_CANCEL,
                                              MsfUtf8,
                                              strlen (PHS_DLG_STRING_CANCEL) + 1, 0);*/
  }
  cancel_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_PHS, cancel_string, MsfCancel,
                                            1, MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION (dialog_handle, cancel_action);
  dlg->handle[PHS_DLG_CANCEL_STRING_HANDLE] = cancel_string;
  dlg->handle[PHS_DLG_CANCEL_ACTION_HANDLE] = cancel_action;

  dlg->handle[PHS_DLG_MESSAGE_HANDLE] = message_text_handle;
  dlg->handle[PHS_DLG_DIALOG_HANDLE] = dialog_handle;

  MSF_WIDGET_SCREEN_ADD_WINDOW (phs_screen_handle,
                                dialog_handle, &null_pos, 0, 0);
  return 0;
}

