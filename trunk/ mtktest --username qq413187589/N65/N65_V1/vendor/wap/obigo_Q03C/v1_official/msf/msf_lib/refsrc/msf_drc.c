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
 * msf_drc.c
 *
 * Created by Robert Moricz, Fri Oct 24 2003.
 *
 * Revision  history:
 *
 */

#include "msf_drc.h"
#include "msf_rc.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_wid.h"


/**********************************************************************
 * Constants
 **********************************************************************/

/* Indices into the array of handles */
#define MSF_DRC_SCREEN_HANDLE                     0
#define MSF_DRC_DIALOG_HANDLE                     1
#define MSF_DRC_OK_ACTION_HANDLE                  2
#define MSF_DRC_CANCEL_ACTION_HANDLE              3

#define MSF_DRC_MAX_NR_OF_HANDLES                 4


#define MSF_DRC_OBJACT_SUBMENU_POSITION     {10,10} /* Position in pixels */
#define MSF_DRC_OBJACT_SUBMENU_SIZE_HEIGHT  0.9 /* Size proportional to screen size */
#define MSF_DRC_OBJACT_SUBMENU_SIZE_WIDTH   0.9 /* Size proportional to screen size */


/**********************************************************************
 * Type definitions
 **********************************************************************/
struct msf_drc_st {
  MSF_UINT8  client_modid;
  int        type;
  int        choice_elem_cnt;
  int        response;
  MSF_UINT32 handle[MSF_DRC_MAX_NR_OF_HANDLES]; /* handle must be 0 if not used*/
};


/**********************************************************************
 * Local functions
 **********************************************************************/

static msf_drc_t *
msf_drc_create (MSF_UINT8 client_modid, MSF_UINT32 screen_handle,
                int dialog_type);


static int
msf_drc_create_objact_subaction_menu (msf_drc_t *dlg,
                                      int numStrId,
                                      const MSF_INT32 str_ids[]);


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
               int numStrId, const MSF_INT32 str_ids[])
{
  msf_drc_t *dlg = NULL;

  /* to avoid warnings for params not used */
  numStrings = numStrings;
  strings = strings;

  switch (dialogType) {
  case MSF_DRC_OBJACT_SUBACTION_MENU:
    if ((numStrings != 0) || (numStrId <= 0)) {
      return NULL;
    }
    dlg = msf_drc_create (client_modid, screenHandle, dialogType);
    msf_drc_create_objact_subaction_menu (dlg, numStrId, str_ids);
    break;
    
  default:
    break;
  }

  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[MSF_DRC_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[MSF_DRC_DIALOG_HANDLE], 1);
  }

  return dlg;
}

/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
msf_drcDelete (msf_drc_t *dlg)
{
  int i;

  /* NOTE: first the Dialog window must be removed from the Screen.
   * Then we release the Dialog window. This will cause all other
   * widgets that are attached to the Dialog to be removed from
   * the Dialog window.
   * Also, we must take care not to delete the Screen Handle! */
  for (i = MSF_DRC_MAX_NR_OF_HANDLES - 1; i > 1; i--) {
    if (dlg->handle[i] != 0) {
      MSF_WIDGET_REMOVE (dlg->handle[MSF_DRC_DIALOG_HANDLE], dlg->handle[i]);
      MSF_WIDGET_RELEASE (dlg->handle[i]);
    }
  }
  MSF_WIDGET_REMOVE (dlg->handle[MSF_DRC_SCREEN_HANDLE],
                     dlg->handle[MSF_DRC_DIALOG_HANDLE]);
  MSF_WIDGET_RELEASE (dlg->handle[MSF_DRC_DIALOG_HANDLE]);
  MSF_MEM_FREE(dlg->client_modid, dlg);
}

/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
msf_drcAction (msf_drc_t *dlg, MSF_UINT32 action)
{
  if (dlg != NULL) {
    if (dlg->handle[MSF_DRC_OK_ACTION_HANDLE] == action) {
      dlg->response = MSF_DRC_RESPONSE_POSITIVE;
    }
    else {
      dlg->response = MSF_DRC_RESPONSE_CANCEL;
    }
  }
}

/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
msf_drcGetType (msf_drc_t *dlg)
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
msf_drcGetDialogHandle (msf_drc_t *dlg)
{
  if (dlg != NULL) {
    return dlg->handle[MSF_DRC_DIALOG_HANDLE];
  }

  return 0;
}

/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling msf_drcAction).
 */
int
msf_drcGetResponse (msf_drc_t *dlg)
{
  if (dlg != NULL) {
    return dlg->response;
  }

  return 0;
}

/*
 * Return the selected index incase of a menu Item
 * Returns -1 if index not found.
 */
int
msf_drcGetMenuIndex (msf_drc_t *dlg)
{
  int j;
  MsfWindowHandle window_hdl;

  if (dlg == NULL)
    return -1;

  window_hdl = dlg->handle[MSF_DRC_DIALOG_HANDLE];

  for (j = 0; j < dlg->choice_elem_cnt; j++) {
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(window_hdl, j) &
        MSF_CHOICE_ELEMENT_FOCUSED) {
      return j;
    }
  }
  return -1;
}


/**********************************************************************
 * Local functions
 **********************************************************************/

static msf_drc_t *
msf_drc_create (MSF_UINT8 client_modid, MSF_UINT32 screen_handle,
                int dialog_type)
{
  int i;
  msf_drc_t *dlg = MSF_MEM_ALLOCTYPE (client_modid, msf_drc_t);

  for (i = 0; i < MSF_DRC_MAX_NR_OF_HANDLES; i++)
    dlg->handle[i] = 0;
  dlg->client_modid = client_modid;
  dlg->type = dialog_type;
  dlg->choice_elem_cnt = 0;
  dlg->response = 0;
  dlg->handle[MSF_DRC_SCREEN_HANDLE] = screen_handle;
 
  return dlg;
}


static int
msf_drc_create_objact_subaction_menu (msf_drc_t *dlg,
                                      int numStrId,
                                      const MSF_INT32 str_ids[])
{
  MsfDeviceProperties  prop;
  MsfPosition          windowPosition = MSF_DRC_OBJACT_SUBMENU_POSITION;
  MsfActionHandle      select_hdl;
  MsfActionHandle      cancel_hdl;
  MsfWindowHandle      window_hdl;
  int                  i;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  prop.displaySize.height = (short) (prop.displaySize.height * MSF_DRC_OBJACT_SUBMENU_SIZE_HEIGHT); 
  prop.displaySize.width = (short) (prop.displaySize.width * MSF_DRC_OBJACT_SUBMENU_SIZE_WIDTH);
  
  window_hdl =  MSF_WIDGET_MENU_CREATE(dlg->client_modid,
                                       MsfExclusiveChoice,
												               &prop.displaySize,
												               0,
                                       0, /*Element Position*/
                                       MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                       0x8000, /*Property Mask*/
                                       0 /*Default Style*/
                                       );

  MSF_WIDGET_WINDOW_SET_PROPERTIES (window_hdl,0);

  for (i = 0; i < numStrId; i++)
  {
    MSF_WIDGET_CHOICE_SET_ELEMENT (window_hdl, i, MSF_WIDGET_STRING_GET_PREDEFINED(str_ids[i]), 0, 0, 0, TRUE);
  }
	
	cancel_hdl = MSF_WIDGET_ACTION_CREATE (dlg->client_modid,
                             MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_SAS_ACTION_CANCEL), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (window_hdl, cancel_hdl);

	select_hdl = MSF_WIDGET_ACTION_CREATE (dlg->client_modid,
                             MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (window_hdl, select_hdl);

  dlg->choice_elem_cnt = numStrId;
  dlg->handle[MSF_DRC_CANCEL_ACTION_HANDLE] = cancel_hdl;
  dlg->handle[MSF_DRC_OK_ACTION_HANDLE] = select_hdl;
  dlg->handle[MSF_DRC_DIALOG_HANDLE] = window_hdl;

  MSF_WIDGET_SCREEN_ADD_WINDOW (dlg->handle[MSF_DRC_SCREEN_HANDLE], window_hdl,
                                &windowPosition, 0, 0);
  return 0;
}




