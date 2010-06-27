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
 * msm_dlg.c
 *
 * Created by Robert Moricz, Fri Oct 24 2003.
 *
 * Revision  history:
 *
 */

#include "msm_dlg.h"
#include "msf_rc.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_wid.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"
#include "msf_env.h"
#include "bra_if.h"
#endif /* WAP_SUPPORT */

/**********************************************************************
 * Constants
 **********************************************************************/

/* Indices into the array of handles */
#define MSM_DLG_SCREEN_HANDLE                     0
#define MSM_DLG_DIALOG_HANDLE                     1
#define MSM_DLG_OK_ACTION_HANDLE                  2
#define MSM_DLG_CANCEL_ACTION_HANDLE              3

#define MSM_DLG_MAX_NR_OF_HANDLES                 4


/**********************************************************************
 * Type definitions
 **********************************************************************/
struct msm_dlg_st {
#ifdef WAP_SUPPORT
  struct msm_dlg_st  *next;
#endif
  int        type;
  int        choice_elem_cnt;
  int        response;
  MSF_UINT32 handle[MSM_DLG_MAX_NR_OF_HANDLES]; /* handle must be 0 if not used*/
};

#ifdef WAP_SUPPORT
msm_dlg_t *msm_act_dlg_list;

static void msm_dlg_add_act_dlg(msm_dlg_t *dlg)
{
  dlg->next = msm_act_dlg_list;
  msm_act_dlg_list = dlg;
}

static void msm_dlg_remove_act_dlg(msm_dlg_t *dlg)
{
  if(msm_act_dlg_list == dlg)
  {
    msm_act_dlg_list = msm_act_dlg_list->next;
  }
  else
  {
    msm_dlg_t *dlg_list = msm_act_dlg_list;
    while(dlg_list->next)
    {
      if(dlg_list->next == dlg)
      {
        dlg_list->next = dlg->next;
        break;
      }
      dlg_list = dlg_list->next;
    }
  }
  if(msm_act_dlg_list == NULL)
  {
    BRAif_downloadComplete(BRA_DNSTATUS_OK);
  }                  
}

void msm_dlg_destroy_act_dlg(void)
{
  msm_dlg_t *dlg;
  dlg = msm_act_dlg_list;

  while(dlg)
  {
    HDIc_widgetAction(MSF_MODID_MSM, dlg->handle[MSM_DLG_DIALOG_HANDLE],dlg->handle[MSM_DLG_CANCEL_ACTION_HANDLE]);
    dlg = dlg->next;
  }
}
#endif

/**********************************************************************
 * Local functions
 **********************************************************************/

static msm_dlg_t *
msm_dlg_create (MSF_UINT32 screen_handle, int dialog_type);


static int
msm_dlg_create_objact_action_menu (msm_dlg_t *dlg,
                                   int numStrId,
                                   const MSF_INT32 str_ids[]);


static int
msm_dlg_create_objact_no_action_info(msm_dlg_t *dlg);

#if defined(CONTENT_OBJECT_ACTION_DISABLE)
static int
msm_dlg_create_info_dialog (msm_dlg_t *dlg, 
                            int numStrId,
                            const MSF_INT32 str_ids[]);
#endif


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
               int numStrId, const MSF_INT32 str_ids[])
{
  msm_dlg_t *dlg = NULL;

  /* to avoid warnings for params not used */
  numStrings = numStrings;
  strings = strings;

  switch (dialogType) {
  case MSM_DLG_OBJACT_ACTION_MENU:
    if ((numStrings != 0) || (numStrId <= 0)) {
      return NULL;
    }
    dlg = msm_dlg_create (screenHandle, dialogType);
    msm_dlg_create_objact_action_menu (dlg, numStrId, str_ids);
    break;
  case MSM_DLG_OBJACT_NO_ACTION_INFO:
    if ((numStrings != 0) || (numStrId != 0)) {
      return NULL;
    }
    dlg = msm_dlg_create (screenHandle, dialogType);
    msm_dlg_create_objact_no_action_info (dlg);
    break;

#if defined(CONTENT_OBJECT_ACTION_DISABLE)
  case MSM_DLG_GEN_INFO_MENU:
    if (numStrId != 1) {
      return NULL;
    }
    dlg = msm_dlg_create (screenHandle, dialogType);
    msm_dlg_create_info_dialog (dlg, numStrId, str_ids);
    break;
#endif

  default:
    break;
  }

  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[MSM_DLG_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[MSM_DLG_DIALOG_HANDLE], 1);
  }

#ifdef WAP_SUPPORT  
  msm_dlg_add_act_dlg(dlg);
#endif
  return dlg;
}

/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
msm_dlgDelete (msm_dlg_t *dlg)
{
  int i;

  /* NOTE: first the Dialog window must be removed from the Screen.
   * Then we release the Dialog window. This will cause all other
   * widgets that are attached to the Dialog to be removed from
   * the Dialog window.
   * Also, we must take care not to delete the Screen Handle! */
  for (i = MSM_DLG_MAX_NR_OF_HANDLES - 1; i > 1; i--) {
    if (dlg->handle[i] != 0) {
      MSF_WIDGET_REMOVE (dlg->handle[MSM_DLG_DIALOG_HANDLE], dlg->handle[i]);
      MSF_WIDGET_RELEASE (dlg->handle[i]);
    }
  }
  MSF_WIDGET_REMOVE (dlg->handle[MSM_DLG_SCREEN_HANDLE],
                     dlg->handle[MSM_DLG_DIALOG_HANDLE]);
  MSF_WIDGET_RELEASE (dlg->handle[MSM_DLG_DIALOG_HANDLE]);
#ifdef WAP_SUPPORT
  msm_dlg_remove_act_dlg(dlg);
#endif
  MSF_MEM_FREE(MSF_MODID_MSM, dlg);
}

/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
msm_dlgAction (msm_dlg_t *dlg, MSF_UINT32 action)
{
  if (dlg != NULL) {
    if (dlg->handle[MSM_DLG_OK_ACTION_HANDLE] == action) {
      dlg->response = MSM_DLG_RESPONSE_POSITIVE;
    }
    else {
      dlg->response = MSM_DLG_RESPONSE_CANCEL;
    }
  }
}

/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
msm_dlgGetType (msm_dlg_t *dlg)
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
msm_dlgGetDialogHandle (msm_dlg_t *dlg)
{
  if (dlg != NULL) {
    return dlg->handle[MSM_DLG_DIALOG_HANDLE];
  }

  return 0;
}

/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling msm_dlgAction).
 */
int
msm_dlgGetResponse (msm_dlg_t *dlg)
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
msm_dlgGetMenuIndex (msm_dlg_t *dlg)
{
  int             j;
  MsfWindowHandle window_hdl;

  if (dlg == NULL)
    return -1;

  window_hdl = dlg->handle[MSM_DLG_DIALOG_HANDLE];

  for (j = 0; j < dlg->choice_elem_cnt; j++) {
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(window_hdl, j) & 
        MSF_CHOICE_ELEMENT_SELECTED) {
      return j;
    }
  }
  return -1;
}

void
msm_dlg_display_no_action_dialog (msm_dlg_t **window,  MsfScreenHandle *screen)
{
  *screen = MSF_WIDGET_SCREEN_CREATE (MSF_MODID_MSM, 0, 0);

  *window = msm_dlgCreate (*screen, MSM_DLG_OBJACT_NO_ACTION_INFO,
                                0, NULL, 0, NULL);
}

/**********************************************************************
 * Local functions
 **********************************************************************/

static msm_dlg_t *
msm_dlg_create (MSF_UINT32 screen_handle, int dialog_type)
{
  int i;
  msm_dlg_t *dlg = MSF_MEM_ALLOCTYPE (MSF_MODID_MSM, msm_dlg_t);

  for (i = 0; i < MSM_DLG_MAX_NR_OF_HANDLES; i++)
    dlg->handle[i] = 0;
  dlg->type = dialog_type;
  dlg->choice_elem_cnt = 0;
  dlg->response = 0;
  dlg->handle[MSM_DLG_SCREEN_HANDLE] = screen_handle;
 
  return dlg;
}


static int
msm_dlg_create_objact_action_menu (msm_dlg_t *dlg,
                                   int numStrId,
                                   const MSF_INT32 str_ids[])
{
  MsfActionHandle select_hdl;
  MsfActionHandle cancel_hdl;
  MsfWindowHandle window_hdl;
  int             i;
  MsfPosition     position = {0,0};

  select_hdl = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MSM, 
                                        MSF_WIDGET_STRING_GET_PREDEFINED (MSF_STR_ID_DLG_ACTION_OK),     
                                        MsfSelect, 1, 0x8000);
  cancel_hdl = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MSM, 
                                        MSF_WIDGET_STRING_GET_PREDEFINED (MSF_STR_ID_DLG_ACTION_CANCEL), 
                                        MsfCancel  , 1, 0x8000);

  window_hdl = MSF_WIDGET_MENU_APP_CREATE(MSF_MODID_MSM,
                                          select_hdl,
                                          0, /*Element Position*/
                                          MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                          0x8000, /*Property Mask*/
                                          0 /*Default Style*/);

#ifdef WAP_SUPPORT
	MSF_WIDGET_SET_TITLE(window_hdl,MSF_WIDGET_STRING_GET_PREDEFINED(WIDGET_STR_ID_OPTION));
#else
  MSF_WIDGET_SET_TITLE(window_hdl,0);
#endif
	MSF_WIDGET_WINDOW_SET_PROPERTIES(window_hdl, MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION(window_hdl, cancel_hdl);

  for (i = 0; i < numStrId; i++)
  {
    MSF_WIDGET_CHOICE_SET_ELEMENT (window_hdl, i, MSF_WIDGET_STRING_GET_PREDEFINED(str_ids[i]), 0, 0, 0, TRUE);
  }
  
  dlg->choice_elem_cnt = numStrId;
  dlg->handle[MSM_DLG_CANCEL_ACTION_HANDLE] = cancel_hdl;
  dlg->handle[MSM_DLG_OK_ACTION_HANDLE] = select_hdl;
  dlg->handle[MSM_DLG_DIALOG_HANDLE] = window_hdl;

  MSF_WIDGET_SCREEN_ADD_WINDOW (dlg->handle[MSM_DLG_SCREEN_HANDLE], window_hdl, &position, 0, 0 );

  return 0;
}


static int
msm_dlg_create_objact_no_action_info(msm_dlg_t *dlg)
{
  MsfActionHandle select_hdl;
  MsfWindowHandle window_hdl;
  MsfPosition     position = {0,0};

  select_hdl = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MSM, 
                                        MSF_WIDGET_STRING_GET_PREDEFINED (MSF_STR_ID_DLG_ACTION_OK),     
                                        MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);

  window_hdl = MSF_WIDGET_DIALOG_CREATE (MSF_MODID_MSM, 
                                         MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_MIME_ACTION_NONE),
                                         MsfInfo,
                                         0, 0, 0);

  /* Presently we use no titel 
  MSF_WIDGET_SET_TITLE(window_hdl, 0);
	MSF_WIDGET_WINDOW_SET_PROPERTIES(window_hdl, MSF_WINDOW_PROPERTY_TITLE);
  */

	MSF_WIDGET_ADD_ACTION(window_hdl, select_hdl);

  dlg->handle[MSM_DLG_OK_ACTION_HANDLE] = select_hdl;
  dlg->handle[MSM_DLG_DIALOG_HANDLE] = window_hdl;

  MSF_WIDGET_SCREEN_ADD_WINDOW (dlg->handle[MSM_DLG_SCREEN_HANDLE], window_hdl, &position, 0, 0 );

  return 0;
}

#if defined(CONTENT_OBJECT_ACTION_DISABLE)
static int
msm_dlg_create_info_dialog (msm_dlg_t *dlg, 
                            int numStrId,
                            const MSF_INT32 str_ids[])
{
  MSF_UINT32      dialog_handle;
  MsfPosition     null_pos = {0, 0};
  MsfStringHandle ok_string;
  MsfActionHandle ok_action;
  numStrId = numStrId;
  /* Create Dialog */
  dialog_handle = MSF_WIDGET_DIALOG_CREATE (MSF_MODID_MSM, str_ids[0], MsfInfo,
                                            0, 0, 0);
  /* Action OK */
  ok_string = MSF_WIDGET_STRING_GET_PREDEFINED (MSF_STR_ID_DLG_ACTION_OK);
  ok_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_MSM, ok_string, MsfOk, 1, MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION (dialog_handle, ok_action);
  dlg->handle[MSM_DLG_OK_ACTION_HANDLE] = ok_action;

  dlg->handle[MSM_DLG_DIALOG_HANDLE] = dialog_handle;

  MSF_WIDGET_SCREEN_ADD_WINDOW (dlg->handle[MSM_DLG_SCREEN_HANDLE],
                                dialog_handle, &null_pos, 0, 0);

  MSF_WIDGET_SET_IN_FOCUS (dlg->handle[MSM_DLG_DIALOG_HANDLE], 1);

  return 0;  
}
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
