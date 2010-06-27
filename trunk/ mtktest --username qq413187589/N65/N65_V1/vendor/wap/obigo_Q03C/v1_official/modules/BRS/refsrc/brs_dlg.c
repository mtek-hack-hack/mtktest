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
/*
 * brs_dlg.c
 *
 * Created by Anders Edenbrant, Mon Sep 30 09:14:59 2002.
 *
 * Revision  history:
 *
 */

#include "msf_def.h"
#include "msf_int.h"
#include "msf_cmmn.h"
#include "msf_core.h"
#include "msf_lib.h"
#include "msf_wid.h"

#include "brs_dlg.h"
#include "brs_main.h"
#include "brs_rc.h"

/**********************************************************************
 * Constants
 **********************************************************************/


/* Number of handles used by different dialog types: */
#define BRS_DLG_WMLS_ALERT_NUM_HANDLES            5
#define BRS_DLG_WMLS_CONFIRM_NUM_HANDLES          7
#define BRS_DLG_WMLS_PROMPT_NUM_HANDLES           8

/* Indices into the array of handles */
#define BRS_DLG_SCREEN_HANDLE                     0
#define BRS_DLG_DIALOG_HANDLE                     1

#define BRS_DLG_WMLS_MESSAGE_HANDLE               2

#define BRS_DLG_WMLS_OK_STRING_HANDLE             3
#define BRS_DLG_WMLS_OK_ACTION_HANDLE             4
#define BRS_DLG_WMLS_CANCEL_STRING_HANDLE         5
#define BRS_DLG_WMLS_CANCEL_ACTION_HANDLE         6

#define BRS_DLG_WMLS_INPUT_HANDLE                 7



/**********************************************************************
 * Type definitions
 **********************************************************************/

struct brs_dlg_st {
  int        type;
  int        response;
  int        num_handles;
  MSF_UINT32 handle[8];
};


/**********************************************************************
 * Local functions
 **********************************************************************/

static brs_dlg_t *
brs_dlg_create (MSF_UINT32 screen_handle, int dialog_type, int num_handles);

static int
brs_dlg_create_wmls_alert_dialog (brs_dlg_t *dlg, const char *message);

static int
brs_dlg_create_wmls_confirm_dialog (brs_dlg_t *dlg, const char *message,
                                    const char *ok, const char *cancel);

static int
brs_dlg_create_wmls_prompt_dialog (brs_dlg_t *dlg, const char *message,
                                   const char *default_input);

static int
brs_dlg_create_object_load_confirm_dialog (brs_dlg_t *dlg, const char *mime_type,
                                           const char *url);

/**********************************************************************
 * Exported functions
 **********************************************************************/

/*
 * Create a dialog.
 * Returns a pointer to a struct brs_dlg_st, or NULL on error.
 */
brs_dlg_t *
brs_dlgCreate (MSF_UINT32 screenHandle, int dialogType,
               int numStrings, const char *strings[])
{
  brs_dlg_t *dlg = NULL;

  switch (dialogType) {
  case BRS_DLG_WMLS_ALERT:
  case BRS_DLG_DISPLAY_SCRIPT_ALERT:
  case BRS_DLG_LE_INPUT_FORMAT_ERROR_ALERT:
    if (numStrings < 1) {
      return NULL;
    }
    dlg = brs_dlg_create (screenHandle, dialogType, BRS_DLG_WMLS_ALERT_NUM_HANDLES);
    brs_dlg_create_wmls_alert_dialog (dlg, strings[0]);
    break;

  case BRS_DLG_WMLS_CONFIRM:
  case BRS_DLG_DISPLAY_I_MODE_UTN_CONFIRM:
    if (numStrings < 3) {
      return NULL;
    }
    dlg = brs_dlg_create (screenHandle, dialogType, BRS_DLG_WMLS_CONFIRM_NUM_HANDLES);
    brs_dlg_create_wmls_confirm_dialog (dlg, strings[0], strings[1], strings[2]);
    break;

  case BRS_DLG_WMLS_PROMPT:
    if (numStrings < 2) {
      return NULL;
    }
    dlg = brs_dlg_create (screenHandle, dialogType, BRS_DLG_WMLS_PROMPT_NUM_HANDLES);
    brs_dlg_create_wmls_prompt_dialog (dlg, strings[0], strings[1]);
    break;

  case BRS_DLG_DISPLAY_OBJECT_LOAD_CONFIRM:
    if (numStrings < 2) {
      return NULL;
    }
    dlg = brs_dlg_create (screenHandle, dialogType, BRS_DLG_WMLS_CONFIRM_NUM_HANDLES);
    brs_dlg_create_object_load_confirm_dialog (dlg, strings[0], strings[1]);
    break;
  case BRS_DLG_LE_INPUT_FORMAT_ERROR_CONFIRM:
    if (numStrings < 1) {
      return NULL;
    }
    dlg = brs_dlg_create (screenHandle, dialogType, BRS_DLG_WMLS_CONFIRM_NUM_HANDLES);
    brs_dlg_create_wmls_confirm_dialog (dlg, strings[0], NULL, NULL);
    break;

  case BRS_DLG_UA_RESEND_POST:
  case BRS_DLG_UA_REDIRECT_POST:
    if (numStrings < 1) {
      return NULL;
    }
    dlg = brs_dlg_create (screenHandle, dialogType, BRS_DLG_WMLS_CONFIRM_NUM_HANDLES);
    brs_dlg_create_wmls_confirm_dialog (dlg, strings[0], NULL, NULL);
    break;

  default:
    break;
  }

  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[BRS_DLG_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[BRS_DLG_DIALOG_HANDLE], 1);
  }

  return dlg;
}

/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
brs_dlgDelete (brs_dlg_t *dlg)
{
  int i;

  /* NOTE: first the Dialog window must be removed from the Screen.
   * Then we release the Dialog window. This will cause all other
   * widgets that are attached to the Dialog to be removed from
   * the Dialog window.
   * Also, we must take care not to delete the Screen Handle! */
  MSF_WIDGET_REMOVE (dlg->handle[BRS_DLG_SCREEN_HANDLE],
                     dlg->handle[BRS_DLG_DIALOG_HANDLE]);
  MSF_WIDGET_RELEASE (dlg->handle[BRS_DLG_DIALOG_HANDLE]);
  for (i = dlg->num_handles - 1; i > 1; i--) {
    MSF_WIDGET_RELEASE (dlg->handle[i]);
  }
  BRS_MEM_FREE (dlg);
}

/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
brs_dlgAction (brs_dlg_t *dlg, MSF_UINT32 action)
{
  if (dlg != NULL) {
    if (dlg->handle[BRS_DLG_WMLS_OK_ACTION_HANDLE] == action) {
      dlg->response = BRS_DLG_RESPONSE_POSITIVE;
    }
    else {
      dlg->response = BRS_DLG_RESPONSE_CANCEL;
    }
  }
}

/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
brs_dlgGetType (brs_dlg_t *dlg)
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
brs_dlgGetDialogHandle (brs_dlg_t *dlg)
{
  if (dlg != NULL) {
    return dlg->handle[BRS_DLG_DIALOG_HANDLE];
  }

  return 0;
}

/*
 * Return the input string from one of the input fields of
 * this dialog. The index of the requested input field is given
 * as 'idx', with indices starting at 0.
 * Returns NULL on error.
 * NOTE: it is the responsibility of the caller to deallocate
 * the returned string.
 */
char *
brs_dlgGetInput (brs_dlg_t *dlg, int idx)
{
  MsfStringHandle  input;
  char            *buf = NULL;
  int              len;

  if ((dlg != NULL) && (dlg->type == BRS_DLG_WMLS_PROMPT) && (idx == 0) &&
      (dlg->response == BRS_DLG_RESPONSE_POSITIVE)) {
    input = MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_BRS,
                                           dlg->handle[BRS_DLG_DIALOG_HANDLE], 0);
    len = MSF_WIDGET_STRING_GET_LENGTH (input, 1, MsfUtf8);
    buf = BRS_MEM_ALLOC (len + 1);
    if (MSF_WIDGET_STRING_GET_DATA (input, buf, MsfUtf8) < 0) {
      BRS_MEM_FREE (buf);
      buf = NULL;
    }
    MSF_WIDGET_RELEASE (input);
  }

  return buf;
}

/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling brs_dlgAction).
 */
int
brs_dlgGetResponse (brs_dlg_t *dlg)
{
  if (dlg != NULL) {
    return dlg->response;
  }

  return 0;
}


/**********************************************************************
 * Local functions
 **********************************************************************/

static brs_dlg_t *
brs_dlg_create (MSF_UINT32 screen_handle, int dialog_type, int num_handles)
{
  brs_dlg_t *dlg = BRS_MEM_ALLOCTYPE (brs_dlg_t);

  dlg->type = dialog_type;
  dlg->num_handles = num_handles;
  dlg->handle[BRS_DLG_SCREEN_HANDLE] = screen_handle;

  return dlg;
}

static int
brs_dlg_create_wmls_alert_dialog (brs_dlg_t *dlg, const char *message)
{
  MSF_UINT32      dialog_handle;
  MsfPosition     null_pos = {0, 0};
  MsfStringHandle msg_handle = 0;
  MsfStringHandle ok_string;
  MsfActionHandle ok_action;
  
  /* Create message string */
  if (message != NULL) {
    msg_handle   = MSF_WIDGET_STRING_CREATE (MSF_MODID_BRS, (char *)message, MsfUtf8,
                                             strlen (message) + 1, 0);
  }

  /* Create Dialog */
  dialog_handle = MSF_WIDGET_DIALOG_CREATE (MSF_MODID_BRS, msg_handle, MsfAlert,
                                            0, 0, 0);

  /* Action OK */
  ok_string = MSF_WIDGET_STRING_GET_PREDEFINED (BRS_STR_ID_OK);
  ok_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRS, ok_string, MsfOk, 1,
                                        MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION (dialog_handle, ok_action);
  dlg->handle[BRS_DLG_WMLS_OK_STRING_HANDLE] = ok_string;
  dlg->handle[BRS_DLG_WMLS_OK_ACTION_HANDLE] = ok_action;

  dlg->handle[BRS_DLG_WMLS_MESSAGE_HANDLE] = msg_handle;
  dlg->handle[BRS_DLG_DIALOG_HANDLE] = dialog_handle;

  MSF_WIDGET_SCREEN_ADD_WINDOW (dlg->handle[BRS_DLG_SCREEN_HANDLE],
                                dialog_handle, &null_pos, 0, 0);

  return 0;
}

static int
brs_dlg_create_wmls_confirm_dialog (brs_dlg_t *dlg, const char *message,
                                    const char *ok, const char *cancel)
{
  MSF_UINT32      dialog_handle;
  MsfPosition     null_pos = {0, 0};
  MsfStringHandle msg_handle = 0;
  MsfStringHandle ok_string;
  MsfStringHandle cancel_string;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  
  /* Create message string */
  if (message != NULL) {
    msg_handle   = MSF_WIDGET_STRING_CREATE (MSF_MODID_BRS, (char *)message, MsfUtf8,
                                             strlen (message) + 1, 0);
  }

  /* Create Dialog */
  dialog_handle = MSF_WIDGET_DIALOG_CREATE (MSF_MODID_BRS, msg_handle, MsfConfirmation,
                                            0, 0, 0);

  /* Action OK */
  if ((ok != NULL) && (strlen (ok) > 0)) {
    ok_string = MSF_WIDGET_STRING_CREATE (MSF_MODID_BRS, (char *)ok, MsfUtf8,
                                          strlen (ok) + 1, 0);
  }
  else {
    ok_string = MSF_WIDGET_STRING_GET_PREDEFINED (BRS_STR_ID_OK);
  }
  ok_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRS, ok_string, MsfOk, 1,
                                        MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION (dialog_handle, ok_action);
  dlg->handle[BRS_DLG_WMLS_OK_STRING_HANDLE] = ok_string;
  dlg->handle[BRS_DLG_WMLS_OK_ACTION_HANDLE] = ok_action;

  /* Action Cancel */
  if ((cancel != NULL) && (strlen (cancel) > 0)) {
    cancel_string = MSF_WIDGET_STRING_CREATE (MSF_MODID_BRS, (char *)cancel, MsfUtf8,
                                              strlen (cancel) + 1, 0);
  }
  else {
    cancel_string = MSF_WIDGET_STRING_GET_PREDEFINED (BRS_STR_ID_CANCEL);
  }
  cancel_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRS, cancel_string, MsfCancel,
                                            1, MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION (dialog_handle, cancel_action);
  dlg->handle[BRS_DLG_WMLS_CANCEL_STRING_HANDLE] = cancel_string;
  dlg->handle[BRS_DLG_WMLS_CANCEL_ACTION_HANDLE] = cancel_action;

  dlg->handle[BRS_DLG_WMLS_MESSAGE_HANDLE] = msg_handle;
  dlg->handle[BRS_DLG_DIALOG_HANDLE] = dialog_handle;

  MSF_WIDGET_SCREEN_ADD_WINDOW (dlg->handle[BRS_DLG_SCREEN_HANDLE],
                                dialog_handle, &null_pos, 0, 0);

  return 0;
}

static int
brs_dlg_create_wmls_prompt_dialog (brs_dlg_t *dlg, const char *message,
                                   const char *default_input)
{
  MSF_UINT32      dialog_handle;
  MsfPosition     null_pos = {0, 0};
  MsfStringHandle msg_handle = 0;
  MsfStringHandle ok_string;
  MsfStringHandle cancel_string;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  MsfStringHandle input_handle = 0;
  
  /* Create message string */
  if (message != NULL) {
    msg_handle   = MSF_WIDGET_STRING_CREATE (MSF_MODID_BRS, (char *)message, MsfUtf8,
                                             strlen (message) + 1, 0);
  }

  /* Create default input string */
  if (default_input != NULL) {
    input_handle   = MSF_WIDGET_STRING_CREATE (MSF_MODID_BRS, (char *)default_input,
                                               MsfUtf8,
                                               strlen (default_input) + 1, 0);
  }

  /* Create Dialog */
  dialog_handle = MSF_WIDGET_DIALOG_CREATE (MSF_MODID_BRS, msg_handle, MsfPrompt,
                                            0, 0, 0);

  /* Action OK */
  ok_string = MSF_WIDGET_STRING_GET_PREDEFINED (BRS_STR_ID_OK);

  ok_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRS, ok_string, MsfOk, 1,
                                        MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ACTION_SET_ATTR(ok_action, MsfOk, -1);
  MSF_WIDGET_ADD_ACTION (dialog_handle, ok_action);
  dlg->handle[BRS_DLG_WMLS_OK_STRING_HANDLE] = ok_string;
  dlg->handle[BRS_DLG_WMLS_OK_ACTION_HANDLE] = ok_action;

  /* Action Cancel */
  cancel_string = MSF_WIDGET_STRING_GET_PREDEFINED (BRS_STR_ID_CANCEL);
  cancel_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRS, cancel_string, MsfCancel,
                                            1, MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ACTION_SET_ATTR(cancel_action, MsfCancel, -1);
  MSF_WIDGET_ADD_ACTION (dialog_handle, cancel_action);
  dlg->handle[BRS_DLG_WMLS_CANCEL_STRING_HANDLE] = cancel_string;
  dlg->handle[BRS_DLG_WMLS_CANCEL_ACTION_HANDLE] = cancel_action;

  /* Add input field */
  MSF_WIDGET_DIALOG_ADD_INPUT (dialog_handle, 0, input_handle, MsfText, 40);

  dlg->handle[BRS_DLG_WMLS_INPUT_HANDLE] = input_handle;
  dlg->handle[BRS_DLG_WMLS_MESSAGE_HANDLE] = msg_handle;
  dlg->handle[BRS_DLG_DIALOG_HANDLE] = dialog_handle;

  MSF_WIDGET_SCREEN_ADD_WINDOW (dlg->handle[BRS_DLG_SCREEN_HANDLE],
                                dialog_handle, &null_pos, 0, 0);

  return 0;
}

static int
brs_dlg_create_object_load_confirm_dialog (brs_dlg_t *dlg, const char *mime_type,
                                           const char *url)
{
  int         len;
  char       *message;
  int         result = 0;
  const char *string;

  MsfStringHandle sh1 = MSF_WIDGET_STRING_GET_PREDEFINED (BRS_STR_ID_NO_MIME_MSG);

  string = BRS_MEM_ALLOC (MSF_WIDGET_STRING_GET_LENGTH (sh1, 1, MsfUtf8));
  MSF_WIDGET_STRING_GET_DATA (sh1, (char *)string, MsfUtf8);
  MSF_WIDGET_RELEASE (sh1);
  
  len = strlen (string);
  message = BRS_MEM_ALLOC (len + 1);
  sprintf (message, "%s", string);
  
  brs_dlg_create_wmls_confirm_dialog (dlg, message, NULL, NULL);
  BRS_MEM_FREE (message);

  BRS_MEM_FREE ((char *)string);
  return result;
}


