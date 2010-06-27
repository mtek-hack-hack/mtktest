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
/*
 * prs_dlg.c
 *
 * Provisioning PIN dialog.
 */

#include "msf_wid.h"
#include "msf_cmmn.h"
#include "msf_lib.h"
#include "msf_int.h"
#include "prs_dlg.h"
#include "prs_rc.h"
#ifdef WAP_SUPPORT
#include "msf_env.h"
#include "bra_cfg.h"
#include "bra_if.h"
#include "wap.h"
#include "ctk.h"
#include "widget_extension.h"
#include "prs_cnst.h"
#endif

#ifdef __MMI_CCA_SUPPORT__
#include "CentralConfigAgentGprot.h"  
#endif


/**********************************************************************
 * Constants
 **********************************************************************/

/* Indices into the array of handles */
#define PRS_DLG_SCREEN_HANDLE                     0
#define PRS_DLG_DIALOG_HANDLE                     1

#define PRS_DLG_MESSAGE_HANDLE                    2

#define PRS_DLG_OK_ACTION_HANDLE                  3
#define PRS_DLG_CANCEL_ACTION_HANDLE              4

#define PRS_DLG_INPUT_HANDLE                      5

#define PRS_DLG_INPUT_MAX_SIZE                    30

#ifdef WAP_SUPPORT
/* set to -1 for unlimited retries */
#define PRS_MAX_PIN_RETRIES                       -1
#endif

/**********************************************************************
 * Local variables
 **********************************************************************/
#ifdef WAP_SUPPORT
static int prs_pin_input_count = 0;
static char pin[PRS_DLG_INPUT_MAX_SIZE];
static int pin_length;
static prs_dlg_t* global_dlg;
#endif

/**********************************************************************
 * Macro definitions
 **********************************************************************/

#define PRS_GET_PREDEF(a)  MSF_WIDGET_STRING_GET_PREDEFINED(a)
#define PRS_DLG_STRCONV(a)  MSF_WIDGET_STRING_CREATE(MSF_MODID_PRS, a,MsfUtf8, strlen(a)+1, 0)

/**********************************************************************
 * Local functions
 **********************************************************************/

static prs_dlg_t*
prs_dlg_create (MSF_UINT32 screen_handle, int dialog_type, int num_handles);

static int
prs_dlg_create_pin_dialog (prs_dlg_t* dlg, int msg);

#ifdef WAP_SUPPORT
static int
prs_dlg_create_confirm_install_dialog (prs_dlg_t* dlg, int network_account_id);

static MsfWindowHandle
prs_dlg_create_ctk_pin_dialog(int msg);

#ifdef __MMI_DUAL_SIM__
extern MSF_UINT16
prs_get_sim_id(int network_account_id);
#endif
#endif

/**********************************************************************
 * Exported functions
 **********************************************************************/

/*
 * Create a screen.
 * Returns a MsfScreenHande, or 0 on error.
 */
MSF_UINT32
prs_dlgCreateScreen (void)
{
  MSF_UINT32 screen;

  screen = MSF_WIDGET_SCREEN_CREATE (MSF_MODID_PRS, 1, 0);

  return screen;
}



/*
 * Delete a screen.
 */
void
prs_dlgDeleteScreen (MSF_UINT32 screenHandle)
{
  if (screenHandle > 0)
    MSF_WIDGET_RELEASE(screenHandle);
}



/*
 * Create a PIN dialog.
 * Returns a pointer to a struct prs_dlg_t, or NULL on error.
 */
#ifdef __MMI_DUAL_SIM__
prs_dlg_t*
prs_dlgCreate (MSF_UINT32 screenHandle, int dialogType, int msg, int network_account_id)
#else
prs_dlg_t*
prs_dlgCreate (MSF_UINT32 screenHandle, int dialogType, int msg)
#endif
{
  int result;
  prs_dlg_t* dlg = NULL;
  dlg = prs_dlg_create (screenHandle, dialogType, PRS_DLG_PIN_NUM_HANDLES);



#ifdef WAP_SUPPORT
  /*
   * PRS_DLG_PIN is now a "install confirmation" screen (drawn by BRA)
   * PRS_DLG_PIN_AGAIN displays PIN input screen (regardless of first PIN input, or successive)
   *
   * Original PRS authentication sequence:
   *    1. prs_authenticate() calls prs_dlgCreate(..., PRS_DLG_PIN, PRS_STR_ID_ENTER_PIN)
   *       to display first PIN input screen
   *    2. widget actions are ALL processed by prs_authenticate(), where it'll delete dialog+screen if CANCEL action
   *       or validate PIN by calc MAC on OK action.
   *    3. if pin failed, prs_authenticate() calls prs_dlgCreate(..., PRS_DLG_PIN_AGAIN, PRS_STR_ID_ENTER_PIN_AGAIN)
   *       to display PIN retry input screen
   *    4. if pin is correct, prs_authenticate triggers PRS to process prov doc, and eventually sends content to BRA.
   *    5. at BRA, content is handled by function bra_prs_handle_provisining_data()
   *
   * New sequence after modification:
   *    1. prs_authenticate() calls prs_dlgCreate(..., PRS_DLG_PIN, PRS_STR_ID_ENTER_PIN)
   *       to display first PIN input screen, but we notify BRA to create install confirmation screen instead.
   *       at the time of notification, we will create a dummy dialog+OK handle + CANCEL handle for BRA to trigger later on
   *    2. PRS will not continue to process its "job" until widget action is triggered from BRA
   *       this means BRA has all the time it needs to display dialogs and getting user to respond.
   *    3. when user accept new setting, BRA triggers widget action associated with the dummy handles created by PRS previously
   *    4. if CANCEL action triggered --> prs_authenticate() deletes dialog+screen
   *       if OK action triggered --> prs_authenticate() attempts to validate the "first pin input"
   *       (because from PRS' perspective, it should have drawn the first PIN input screen)
   *    5. since no pin input were found, first validation by prs_authenticate() will fail,
   *       it'll then call prs_dlgCreate(..., PRS_DLG_PIN_AGAIN, PRS_STR_ID_ENTER_PIN_AGAIN) to draw pin retry screen
   *    6. here we then creates the first pin input screen, and add in our own pin input counter.
   *    7. during pin input screens, if user cancels, or unable to enter correct pin after number of retries,
   *       it MUST notify BRA to abort, otherwise BRA's prov doc handling state will mess up.
   */

  result = FALSE;
  switch(dialogType)
  {
    case PRS_DLG_PIN_AGAIN: // shows Input PIN screen (first entry + all retries)
      if (PRS_MAX_PIN_RETRIES != -1 && prs_pin_input_count >= PRS_MAX_PIN_RETRIES) {
        // show "no more tries" error popup
        HDIa_widgetExtShowPopup(MSF_MODID_PRS, PRS_GET_PREDEF(PRS_STR_ID_ENTER_PIN_AGAIN), MsfError, 2000);
        BRAif_notifyPinnedProvDocAbort();
        break;
      }

      result = prs_dlg_create_pin_dialog(dlg, PRS_STR_ID_ENTER_PIN);
      prs_pin_input_count++;

	  /* to avoid prs_pin_input_count wrap around.. */
	  if (PRS_MAX_PIN_RETRIES==-1 && prs_pin_input_count==0)
		prs_pin_input_count = 2;

      break;

    case PRS_DLG_PIN:   // notify BRA to show Install Confirmation
#ifdef __MMI_DUAL_SIM__
      result = prs_dlg_create_confirm_install_dialog(dlg, network_account_id);
#else
      result = prs_dlg_create_confirm_install_dialog(dlg, 0);
#endif
      prs_pin_input_count = 0;
      return dlg;
  }
#else
  result = prs_dlg_create_pin_dialog(dlg, msg);
#endif

  if (result == FALSE) {
    PRS_FREE(dlg);
    return NULL;
  }
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[PRS_DLG_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[PRS_DLG_DIALOG_HANDLE], 1);
  }

#ifdef WAP_SUPPORT
  if (prs_pin_input_count > 1 && 
	  ( (PRS_MAX_PIN_RETRIES!=-1 && prs_pin_input_count<=PRS_MAX_PIN_RETRIES) ||
	    (PRS_MAX_PIN_RETRIES==-1) )) {
    // show "incorrect pin" error popup
    HDIa_widgetExtPaintDirectly();
    HDIa_widgetExtShowPopup(MSF_MODID_PRS, PRS_GET_PREDEF(PRS_STR_ID_ENTER_PIN_AGAIN), MsfError, 2000);
  }
#endif

  return dlg;
}



/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
prs_dlgDelete (prs_dlg_t* dlg)
{
  int i;

  if (dlg == NULL)
    return;

  /* NOTE: we must not delete the Screen Handle! */
  for (i = dlg->num_handles - 1; i > 0; i--) {
    MSF_WIDGET_REMOVE (dlg->handle[0], dlg->handle[i]);
    MSF_WIDGET_RELEASE (dlg->handle[i]);
  }
  dlg->handle[0] = 0;
  PRS_FREE (dlg);
}



/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
prs_dlgAction (prs_dlg_t* dlg, MSF_UINT32 action)
{
  if (dlg != NULL) {
    if (dlg->handle[PRS_DLG_OK_ACTION_HANDLE] == action) {
      dlg->response = PRS_DLG_RESPONSE_POSITIVE;
    } else {
      dlg->response = PRS_DLG_RESPONSE_CANCEL;

#ifdef WAP_SUPPORT
      if (dlg->type == PRS_DLG_PIN_AGAIN)   // user cancelled pin input
        BRAif_notifyPinnedProvDocAbort();
#endif

    }
  }
}



/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
prs_dlgGetType (prs_dlg_t* dlg)
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
prs_dlgGetDialogHandle (prs_dlg_t* dlg)
{
  if (dlg != NULL) {
    return dlg->handle[PRS_DLG_DIALOG_HANDLE];
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
char*
prs_dlgGetInput (prs_dlg_t* dlg, int idx, int *inputLen)
{
#ifndef WAP_SUPPORT
  MsfStringHandle  input;
  char             buf[128];
#endif
  char*            tmp = NULL;

#ifdef WAP_SUPPORT
  /* only DLG_PIN_AGAIN dialog contains valid pin input, DLG_PIN dialog is now a "install confirmation" screen */
  if ((dlg != NULL) && (dlg->type == PRS_DLG_PIN_AGAIN) && 
#else
  /* origional code */
  if ((dlg != NULL) && ((dlg->type == PRS_DLG_PIN) || 
      (dlg->type == PRS_DLG_PIN_AGAIN)) && 
#endif
      (idx == 0) && (dlg->response == PRS_DLG_RESPONSE_POSITIVE)) {

#ifdef WAP_SUPPORT
    tmp = msf_cmmn_strdup (MSF_MODID_PRS, pin);
    *inputLen = strlen (tmp);
    return tmp;
#else    
    if ((input = MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_PRS,
         dlg->handle[PRS_DLG_DIALOG_HANDLE], 0)) == 0)
      return NULL;
    
    if (MSF_WIDGET_STRING_GET_DATA (input, buf, MsfUtf8) >= 0) {
      tmp = msf_cmmn_strdup (MSF_MODID_PRS, buf);
      *inputLen = strlen (tmp);
    }
    MSF_WIDGET_RELEASE (input);
#endif
  }
  
  return tmp;
}



/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling prs_dlgAction).
 */
int
prs_dlgGetResponse (prs_dlg_t* dlg)
{
  if (dlg != NULL) {
    return dlg->response;
  }

  return 0;
}


/**********************************************************************
 * Local functions
 **********************************************************************/

static prs_dlg_t*
prs_dlg_create (MSF_UINT32 screen_handle, int dialog_type, 
                int num_handles)
{
  prs_dlg_t* dlg = PRS_ALLOC (sizeof (prs_dlg_t) +
                              (num_handles - 1) * sizeof (MSF_UINT32));

  dlg->type = dialog_type;
  dlg->num_handles = num_handles;
  dlg->handle[PRS_DLG_SCREEN_HANDLE] = screen_handle;

  return dlg;
}


/*
 * Return TRUE on success, FALSE otherwise.
 */
static int
prs_dlg_create_pin_dialog (prs_dlg_t* dlg, int msg)
{
  MsfWindowHandle dialog_handle = 0;
  MsfStringHandle msg_handle = 0;
  MsfActionHandle ok_action = 0;
  MsfActionHandle cancel_action = 0;
  MsfGadgetHandle input_handle = 0;
  MsfPosition     null_pos = {0, 0};
#ifndef WAP_SUPPORT
  MsfSize         input_size;
#endif
  
#ifdef WAP_SUPPORT

  memset(pin, 0, PRS_DLG_INPUT_MAX_SIZE);
  
  /* Action OK */
  if ((ok_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_PRS, 
       PRS_GET_PREDEF (PRS_STR_ID_OK), MsfOk, 1, 0x8000)) == 0 ) {
    MSF_WIDGET_RELEASE (dialog_handle);
    return FALSE;
  }
  
  /* Action CANCEL */
  if ( (cancel_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_PRS, 
        PRS_GET_PREDEF (PRS_STR_ID_CANCEL), MsfCancel, 1, 0x8000)) == 0 ) {
    MSF_WIDGET_RELEASE (ok_action);
    MSF_WIDGET_RELEASE (dialog_handle);
    return FALSE;
  }

  dialog_handle = prs_dlg_create_ctk_pin_dialog(msg);
  
  dlg->handle[PRS_DLG_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[PRS_DLG_CANCEL_ACTION_HANDLE] = cancel_action;
  dlg->handle[PRS_DLG_MESSAGE_HANDLE] = msg_handle;
  dlg->handle[PRS_DLG_DIALOG_HANDLE] = dialog_handle;
  dlg->handle[PRS_DLG_INPUT_HANDLE] = input_handle;
  
  BRAif_registerProvAuth(dlg->handle[PRS_DLG_DIALOG_HANDLE], dlg->handle[PRS_DLG_CANCEL_ACTION_HANDLE]);
  MSF_WIDGET_SCREEN_ADD_WINDOW (dlg->handle[PRS_DLG_SCREEN_HANDLE],
                                dialog_handle, &null_pos, 0, 0);
  global_dlg = dlg;
  return TRUE;
  
#else

  /* Create message string */
  if ((msg_handle = PRS_GET_PREDEF (msg)) == 0)
    return FALSE;

  /* Create Dialog */
  dialog_handle = MSF_WIDGET_DIALOG_CREATE (MSF_MODID_PRS, msg_handle, 
                                            MsfPrompt, 0, 0x8000, 0);

  /* Action OK */
  if ((ok_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_PRS, 
       PRS_GET_PREDEF (PRS_STR_ID_OK), MsfOk, 1, 0x8000)) == 0 ) {
    MSF_WIDGET_RELEASE (dialog_handle);
    return FALSE;
  }
  
  /* Action CANCEL */
  if ( (cancel_action = MSF_WIDGET_ACTION_CREATE (MSF_MODID_PRS, 
        PRS_GET_PREDEF (PRS_STR_ID_CANCEL), MsfCancel, 1, 0x8000)) == 0 ) {
    MSF_WIDGET_RELEASE (ok_action);
    MSF_WIDGET_RELEASE (dialog_handle);
    return FALSE;
  }

  input_size.height = 20;
  input_size.width = 150;
  
  if ((input_handle = MSF_WIDGET_STRING_CREATE (MSF_MODID_PRS, 
       NULL, MsfUtf8, 0, 0)) == 0) {
    MSF_WIDGET_RELEASE (cancel_action);
    MSF_WIDGET_RELEASE (ok_action);
    MSF_WIDGET_RELEASE (dialog_handle);
    return FALSE;
  }

  MSF_WIDGET_DIALOG_ADD_INPUT (dialog_handle, 0, 0, 
                               MsfPasswordText, 40);

  MSF_WIDGET_ADD_ACTION (dialog_handle, ok_action);
  MSF_WIDGET_ADD_ACTION (dialog_handle, cancel_action);
  
  dlg->handle[PRS_DLG_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[PRS_DLG_CANCEL_ACTION_HANDLE] = cancel_action;
  dlg->handle[PRS_DLG_MESSAGE_HANDLE] = msg_handle;
  dlg->handle[PRS_DLG_DIALOG_HANDLE] = dialog_handle;
  dlg->handle[PRS_DLG_INPUT_HANDLE] = input_handle;

  MSF_WIDGET_SCREEN_ADD_WINDOW (dlg->handle[PRS_DLG_SCREEN_HANDLE],
                                dialog_handle, &null_pos, 0, 0);

  return TRUE;
#endif
}


#ifdef WAP_SUPPORT
static void
prs_dlg_action_ctk_pin_dialog(ctk_screen_handle scrid)
{
    // CTK
    ctk_layout_handle			layout_id;
    ctk_inline_item_type_enum	item_type;
    ctk_inline_result_union		item_value;

    layout_id = ctk_screen_get_layout(scrid);
	
	ctk_inline_get_result(layout_id, 1,&item_type, &item_value);
	pin_length = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)item_value.input_buffer);

    if(pin_length > 0)
	{
	    widget_ucs2_to_utf8_string((kal_uint8 *)pin, pin_length + 1, (kal_uint8 *)item_value.input_buffer);
	}
    HDIc_widgetAction(MSF_MODID_PRS, global_dlg->handle[PRS_DLG_DIALOG_HANDLE], global_dlg->handle[PRS_DLG_OK_ACTION_HANDLE]);
	widget_send_update_event_to_wap();
}

static void
prs_dlg_cancel_ctk_pin_dialog(ctk_screen_handle scrid)
{
#ifdef PRS_CFG_CANCEL_PROV_CONF
    BRAif_cancelProvConf();
    widget_send_update_event_to_wap();
#else
    HDIc_widgetAction(MSF_MODID_PRS, global_dlg->handle[PRS_DLG_DIALOG_HANDLE], global_dlg->handle[PRS_DLG_CANCEL_ACTION_HANDLE]);
	widget_send_update_event_to_wap();
#endif
}

static MsfWindowHandle
prs_dlg_create_ctk_pin_dialog(int msg)
{
	// Widget
	MsfWindowHandle			wnd;

	// CTK
	ctk_screen_handle				scrid;
	ctk_layout_handle				layoutid;
	ctk_inline_create_struct		layout_create;
	
	ctk_inline_item_single_line_copy_struct	single_line_create;
	ctk_inline_item_caption_copy_struct		caption_create;

	// Create CTK screen
	scrid = widget_ctk_screen_create();

	// set key
	ctk_screen_add_inline_Done_UA(scrid, NULL, prs_dlg_action_ctk_pin_dialog, KAL_TRUE);

	// Create layout
	CTK_INIT_STRUCT(layout_create);
	layout_create.in_num_items = 2;
	layout_create.in_highlighted = 1;

#ifdef __MMI_CCA_SUPPORT__              
	layout_create.in_img_title = IMG_ID_CCA_MAIN_ICON;  
#else
    layout_create.in_img_title = WAP_IMAGE_WAP_LOGO;
#endif

	layout_create.in_str_title = (ctk_string_id)PRS_STR_ID_PIN_TITLE;
	layout_create.in_cancel_fp = prs_dlg_cancel_ctk_pin_dialog;
	layout_create.in_set_LSK = KAL_TRUE;
	layout_create.in_disable_done = KAL_TRUE; /* Let RSK be Clear/Back */
	
	layoutid  = ctk_inline_create(HDIa_widgetCtkGetApp(), &layout_create);

	// insert inline items
	CTK_INIT_STRUCT(caption_create);
	caption_create.title = (ctk_string_id)msg;
	ctk_inline_set_item_copy(layoutid, 0, 0, 0, CTK_INLINE_ITEM_TYPE_CAPTION, &caption_create);

	CTK_INIT_STRUCT(single_line_create);
	single_line_create.input_type = CTK_INPUT_TYPE_PASSWORD_NUMBER;
	single_line_create.max_len = PRS_DLG_INPUT_MAX_SIZE;
	single_line_create.default_text = NULL;
	single_line_create.is_UTF8 = KAL_TRUE;
	single_line_create.activation = CTK_INLINE_ACTIVATION_AUTO;
	ctk_inline_set_item_copy(layoutid, 1, 0, 0, CTK_INLINE_ITEM_TYPE_SINGLE_LINE, &single_line_create);

	// start to display
	ctk_screen_attach_layout(scrid, layoutid);

	wnd = HDIa_widgetCtkCreate(MSF_MODID_PRS, scrid);
    return wnd;
}

/*
 * Creates a dummy dialog, OK handle, CANCEL handle for BRA to trigger later on
 * Function notifies BRA to show install confirmation screen.
 * Return TRUE on success, FALSE otherwise.
 */
static int
prs_dlg_create_confirm_install_dialog (prs_dlg_t* dlg, int network_account_id) {
  MSF_UINT32 sim_id;

  dlg->handle[PRS_DLG_MESSAGE_HANDLE] = PRS_GET_PREDEF(BRA_STR_ID_PRS_INSTAL);

  dlg->handle[PRS_DLG_DIALOG_HANDLE] = MSF_WIDGET_DIALOG_CREATE (MSF_MODID_PRS, dlg->handle[PRS_DLG_MESSAGE_HANDLE], 
                                            MsfConfirmation, 0, 0x8000, 0);

  dlg->handle[PRS_DLG_OK_ACTION_HANDLE] = MSF_WIDGET_ACTION_CREATE(MSF_MODID_PRS, PRS_GET_PREDEF(BRA_STR_ID_YES), MsfOk, 1, 0x8000);
  MSF_WIDGET_ADD_ACTION (dlg->handle[PRS_DLG_DIALOG_HANDLE], dlg->handle[PRS_DLG_OK_ACTION_HANDLE]);

  dlg->handle[PRS_DLG_CANCEL_ACTION_HANDLE] = MSF_WIDGET_ACTION_CREATE(MSF_MODID_PRS, PRS_GET_PREDEF(BRA_STR_ID_NO), MsfCancel, 1, 0x8000);
  MSF_WIDGET_ADD_ACTION (dlg->handle[PRS_DLG_DIALOG_HANDLE], dlg->handle[PRS_DLG_CANCEL_ACTION_HANDLE]);

  dlg->handle[PRS_DLG_INPUT_HANDLE] = 0;

  // call BRAif_show confirm install dialog
#ifdef __MMI_DUAL_SIM__
  sim_id = (MSF_UINT32)prs_get_sim_id(network_account_id);
#else
  sim_id = PRS_VAL_SIM_1;
#endif

  BRAif_notifyPinnedProvDocNew(dlg->handle[PRS_DLG_DIALOG_HANDLE], dlg->handle[PRS_DLG_OK_ACTION_HANDLE], dlg->handle[PRS_DLG_CANCEL_ACTION_HANDLE], sim_id);

  return TRUE;
}
#endif
