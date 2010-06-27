/*
 * Copyright (C) Obigo AB, 2002-2005.
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
 * sec_ti.c
 *
 * Created by Anna Andréasson, Mon Oct 21 2002.
 *
 */




#include "sec_ti.h"
#include "sec_if.h"
#include "sec_rc.h" 
#include "sec_pdf.h"
#include "sec_wtls.h"
#include "sec_x509.h"
#include "msf_wid.h"
#include "msf_lib.h"
#include "msf_chrs.h"
#include "msf_cfg.h"
#include "msf_def.h" 
#include "msf_cmmn.h"
#include "msf_int.h"
#include "msf_core.h"

#ifdef WAP_SUPPORT
#include "bra_win.h"
#include "bra_dlg.h"
#include "wap.h"
#include "widget_extension.h"
#endif
/**********************************************************************
 * Constants
 **********************************************************************/

/* Indices into the array of handles */
#define SEC_TI_SCREEN_HANDLE                           0
#define SEC_TI_DIALOG_HANDLE                           1
#define SEC_TI_FORM_HANDLE                             1
#define SEC_TI_MENU_HANDLE                             1

#define SEC_TI_OK_ACTION_HANDLE                        2
#define SEC_TI_CANCEL_ACTION_HANDLE                    3

#define SEC_TI_TEXT_GADGET_STR_HANDLE                  4 
#define SEC_TI_NAME_GADGET_STR_HANDLE                  4 
#define SEC_TI_FINGERPRINT_GADGET_STR_HANDLE           4
                                                 
#define SEC_TI_ISSUER_GADGET_STR_HANDLE                5
#define SEC_TI_SUBJECT_GADGET_STR_HANDLE               6
#define SEC_TI_VALID_NOT_BEF_GADGET_STR_HANDLE         7
#define SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE         8
#define SEC_TI_TEXT_INPUT_GADGET_STR_HANDLE            9

#define SEC_TI_CONN_TYPE_GADGET_STR_HANDLE             4
#define SEC_TI_ENCR_GADGET_STR_HANDLE                  5
#define SEC_TI_ENCR_KEY_LEN_GADGET_STR_HANDLE          6
#define SEC_TI_KEYEXCH_GADGET_STR_HANDLE               7
#define SEC_TI_KEYEXCH_KEY_LEN_GADGET_STR_HANDLE       8
#define SEC_TI_HMAC_GADGET_STR_HANDLE                  9
#define SEC_TI_HMAC_KEY_LEN_GADGET_STR_HANDLE          10

#define SEC_TI_HASH_GADGET_STR_HANDLE                  4
#define SEC_TI_PIN_GADGET_STR_HANDLE                   4
#define SEC_TI_TEXT_INPUT_GADGET_STR_1_HANDLE          5

#define SEC_TI_PIN_GADGET_STR_2_HANDLE                 6
#define SEC_TI_TEXT_INPUT_GADGET_STR_2_HANDLE          7
#define SEC_TI_PIN_GADGET_STR_3_HANDLE                 8
#define SEC_TI_TEXT_INPUT_GADGET_STR_3_HANDLE          9


#define SEC_TI_CONTRACT_GADGET_STR_HANDLE              4
#define SEC_TI_TIME_GADGET_STR_HANDLE                  5
#define SEC_TI_SIG_GADGET_STR_HANDLE                   6


/***************************************************/
/* Macros                                          */
/***************************************************/

#define SEC_GET_STR_ID(strId) MSF_WIDGET_STRING_GET_PREDEFINED(strId)

#define SEC_STRCONV(a)  MSF_WIDGET_STRING_CREATE(MSF_MODID_SEC, a, MsfUtf8, strlen(a)+1, 0)


/**********************************************************************
 * Global variables
 **********************************************************************/

int *ti_index;
int ti_nbrOfCerts;

/* Display Properties*/
MsfSize sec_display_size;

/**********************************************************************
 * Local functions
 **********************************************************************/

MsfWindowHandle 
sec_tiCreateDialog(MsfStringHandle dialogTitle, MsfStringHandle dialogText, 
                MsfDialogType type);

MsfWindowHandle 
sec_tiCreateForm(MsfStringHandle formTitle);

MsfWindowHandle 
sec_tiCreateMenu(MsfStringHandle menuTitle);

#ifdef SEC_CFG_USE_KEYS
int
sec_tiCreateTextAndInput(MsfWindowHandle formHdl, 
                      MsfGadgetHandle *gadgetStr, MsfStringHandle str, 
                      MsfGadgetHandle *textInputGadget,
                      MsfPosition	*stringPos, int maxSize, 
                      MsfTextType textInputType);
#else
int
sec_tiCreateTextAndInput(MsfWindowHandle formHdl, 
                      MsfGadgetHandle *gadgetStr, MsfStringHandle str, 
                      MsfGadgetHandle *textInputGadget,
                      MsfPosition	*stringPos, int maxSize, 
                      MsfTextType textInputType);                      
#endif

/* Gadget functions */

MsfGadgetHandle 
sec_tiCreateStringGadget(MsfWindowHandle formHdl, MsfStringHandle strHdl,
                      MsfPosition	stringPos, MsfSize *stringSize,
                      int singleLine);
MsfGadgetHandle
sec_tiCreateTextInputGadget(MsfWindowHandle formHdl, MsfPosition stringPos, 
                         MsfSize *textInputSize, int maxSize, 
                         MsfTextType textInputType);
MsfGadgetHandle
sec_tiCreateConnTypeGadget(MsfWindowHandle formHdl, int connType, 
                        MsfPosition *stringPos, MsfSize stringSize);
MsfGadgetHandle
sec_tiCreateHmacAlgGadget(MsfWindowHandle formHdl, sec_hash_alg hMacAlg, 
                       MsfPosition *stringPos, MsfSize stringSize);
MsfGadgetHandle
sec_tiCreateHmacKeyLenGadget(MsfWindowHandle formHdl, int hMacKeyLen, 
                          MsfPosition *stringPos, MsfSize stringSize);
MsfGadgetHandle
sec_tiCreateEncrAlgGadget(MsfWindowHandle formHdl, MSF_UINT8 encrAlg, 
                       MsfPosition *stringPos, MsfSize stringSize);
MsfGadgetHandle
sec_tiCreateEncrKeyLenGadget(MsfWindowHandle formHdl, MSF_UINT16 encrKeyLen, 
                          MsfPosition *stringPos, MsfSize stringSize);
MsfGadgetHandle
sec_tiCreateKeyExchAlgGadget(MsfWindowHandle formHdl, int keyExchAlg, 
                          MsfPosition *stringPos, MsfSize stringSize);
MsfGadgetHandle
sec_tiCreateKeyExchSuiteGadget(MsfWindowHandle formHdl, int keyExchSuite, 
                            MsfPosition *stringPos, MsfSize stringSize);
MsfGadgetHandle
sec_tiCreateKeyExchKeyLenGadget(MsfWindowHandle formHdl, int keyExchKeyLen, 
                             MsfPosition *stringPos, MsfSize stringSize);
MsfGadgetHandle
sec_tiCreateValidDateGadget(MsfWindowHandle formHdl, 
                         MSF_UINT32 validDate, MsfStringHandle validStr,
                         MsfPosition *stringPos, MsfSize stringSize);
MsfGadgetHandle
sec_tiCreateFingerprGadget(MsfWindowHandle formHdl, 
                        unsigned char *fingerprint, int fingerprintLen,
                        MsfPosition *stringPos, MsfSize stringSize);
MsfGadgetHandle
sec_tiCreateIssuerGadget(MsfWindowHandle formHdl, 
                      MSF_INT16 charSet, 
                      void *issuer, int issuerLen, 
                      MsfStringHandle issuerStr,
                      MsfPosition *stringPos, MsfSize stringSize);

MsfStringHandle
sec_tiGetIssuerStrHdl(MSF_INT16 charSet, void *issuer, int issuerLen, 
                   MsfStringHandle issuerStr);
int
sec_tiCreatePinForm(MsfWindowHandle *formHdl, MsfActionHandle *ok_action,
                    MsfActionHandle *cancel_action, MsfGadgetHandle *pinGadgetStr,
                    MsfGadgetHandle *textInputGadget,MSF_UINT8 keyType, 
                    MsfStringHandle formTitle,
                    MsfStringHandle textStr, MsfPosition	*stringPos);

int
sec_tiCvtTimeToStr(MSF_UINT32 time, char **timeStr);

int
sec_tiCvtToUtf8(unsigned char *strToCvt, long strToCvtLen, 
             char *dst, long *dstLen, MSF_INT16 charSet);

int
sec_tiStrExtract(MsfGadgetHandle textHandle, char *buf, int *bufLen);

sec_ti_t *
sec_dlg_create (MSF_UINT32 screen_handle ,int dialog_type, int num_handles );

#ifdef WAP_SUPPORT
MsfImageHandle
sec_get_list_num_image(int i);
static void
sec_myTiDelete (bra_win_t* win);
typedef struct sec_win 
{
  MsfWindowHandle win_hdl;
#ifdef __MMI_KLG__
  MsfActionHandle accept;
  MsfActionHandle back;
#endif  
  sec_ti_t *dlg;
} sec_win_t;

MsfWindowHandle certFormHdl = 0;
MsfActionHandle certFormOk  = 0xffff01;
MsfActionHandle certFormDel = 0xffff02;
ctk_screen_handle act_scrid;
extern void widget_send_update_event_to_wap(void);

extern void HDIc_widgetAction(MSF_UINT8 modId, MSF_UINT32 msfHandle, MSF_UINT32 action);

#endif
/**********************************************************************
 * Exported functions
 **********************************************************************/
/*
 * Create a screen.
 * Returns a MsfScreenHande, or 0 on error.
 */
MSF_UINT32
sec_tiCreateScreen (void)
{
  MSF_UINT32 screen;
  MsfDeviceProperties properties;
  
  MSF_WIDGET_DEVICE_GET_PROPERTIES(&properties);
  sec_display_size = properties.displaySize;

#ifdef WAP_SUPPORT
  screen = bra_win_get_screen();
#else
  screen = MSF_WIDGET_SCREEN_CREATE (MSF_MODID_SEC, 1, 0);
#endif

  return screen;
}

/*
 * Delete a screen.
 */
void
sec_tiDeleteScreen (MSF_UINT32 screenHandle)
{
#ifndef WAP_SUPPORT
  if (screenHandle > 0)
    MSF_WIDGET_RELEASE(screenHandle);
#endif
}

/*Sets the screen in/out of focus, option = true or false*/
void
sec_tiFocus(MSF_UINT32 screenHandle, int option)
{
  MSF_WIDGET_SET_IN_FOCUS(screenHandle, option); 
}

/*Sets the menu/dialog/form in/out of focus, option = true or false*/
void 
sec_tiMenuFocus(sec_ti_t *dlg, int option)
{
  MSF_WIDGET_SET_IN_FOCUS(dlg->handle[SEC_TI_MENU_HANDLE], option); 
}
/*
 * Create a confirmation dialog with the supplied message, 
 * yes message, and no message.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateConfirmDlg(MSF_UINT32 screenHandle, int msg, int yesMsg, int noMsg)
{
  MsfWindowHandle dlgHdl;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action = 0;
  MsfStringHandle dialogText;
  MsfStringHandle dialogTitle;
  MsfPosition     nullPos = {0, 0};
  int num_handles = 4; /*Minimum to this dialog*/
  sec_ti_t *dlg;
#ifdef WAP_SUPPORT
  sec_win_t *win;
  if(noMsg == SEC_STR_ID_EMPTY)
    num_handles--;
#endif  
  dlg = sec_dlg_create (screenHandle, SEC_TI_CONFIRM_DLG, num_handles);
  
  dialogText = SEC_GET_STR_ID(msg);
  dialogTitle = SEC_GET_STR_ID(SEC_STR_ID_CONFIRM_TITLE);

  dlgHdl = sec_tiCreateDialog(dialogTitle, dialogText, MsfConfirmation);
  MSF_WIDGET_DIALOG_SET_ATTR(dlgHdl, dialogText, 0);

  /* Action MsfOk / yesMsg */
 	ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC, SEC_GET_STR_ID(yesMsg), 
                                      MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION(dlgHdl, ok_action);
#ifdef WAP_SUPPORT
  if(noMsg != SEC_STR_ID_EMPTY)
  {
#endif
  /* Action MsfCancel / noMsg */
 	cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC, SEC_GET_STR_ID(noMsg), 
                                          MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION(dlgHdl, cancel_action);
#ifdef WAP_SUPPORT
  }
#endif  
  dlg->handle[SEC_TI_DIALOG_HANDLE] = dlgHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
#ifdef WAP_SUPPORT
  if(noMsg != SEC_STR_ID_EMPTY)
#endif
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
#ifdef WAP_SUPPORT
  win = SEC_ALLOCTYPE(sec_win_t);
  win->win_hdl = dlg->handle[SEC_TI_DIALOG_HANDLE];
  win->dlg = dlg;
  bra_win_show_window (BRA_WIN_ID_SEC_DLG, 
                    (bra_win_t*)win,
                    &nullPos, 
                    sec_myTiDelete, 
                    NULL,
                    NULL);
#else
  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], dlgHdl, 
                               &nullPos, 0, 0);
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_DIALOG_HANDLE], 1);
  }  
#endif
  return dlg;
}

#ifdef SEC_CFG_CAN_SIGN_TEXT
/*
 * Create an extended confirmation dialog with the supplied text, 
 * message, yes message, and no message.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateExtConfirmDlg(MSF_UINT32 screenHandle, int msg, const char *text, 
                           int yesMsg, int noMsg)
{
  MsfPosition nullPos = {0,0};
  MsfStringHandle formTitle;
  MsfStringHandle extConfStr;
  MsfPosition	stringPos;
  MsfSize stringSize = {60,200};
  char *tmpStr;
  MsfWindowHandle formHdl;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  MsfGadgetHandle textGadgetStr;
  int num_handles = 5; /*Minimum to this dialog*/
  sec_ti_t *dlg;
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_EXT_CONFIRM_DLG, num_handles);

  formTitle = SEC_GET_STR_ID(SEC_STR_ID_CONFIRM_TITLE);

  tmpStr = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                             SEC_GET_STR_ID(msg),0,MsfUtf8)*sizeof(text)+3);
  MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(msg), tmpStr, MsfUtf8);

  strcat (tmpStr, text);
  extConfStr = SEC_STRCONV(tmpStr);

  SEC_FREE(tmpStr);

  formHdl = sec_tiCreateForm(formTitle);

  /* Action MsfOk / yesMsg */
  ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
                                        SEC_GET_STR_ID(yesMsg), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION(formHdl, ok_action);

  /* Action MsfCancel / noMsg */
	cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
                                            SEC_GET_STR_ID(noMsg), 
                                            MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION(formHdl, cancel_action);

  /* String Gadget extConfStr */
	stringPos.x = SEC_FIRST_X_POS;
	stringPos.y = SEC_FIRST_Y_POS;
  textGadgetStr = sec_tiCreateStringGadget(formHdl, 
                                          extConfStr, stringPos, 
                                          &stringSize, 0);
  if (textGadgetStr == 0)
  {
    MSF_WIDGET_RELEASE(formHdl);
    MSF_WIDGET_RELEASE(ok_action);
    MSF_WIDGET_RELEASE(cancel_action);
    return NULL;
  }
	
  dlg->handle[SEC_TI_FORM_HANDLE] = formHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
  dlg->handle[SEC_TI_TEXT_GADGET_STR_HANDLE]= textGadgetStr;

  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], formHdl, &nullPos, 0, 0);
  
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }  
  return dlg;
}
#endif

#ifdef SEC_CFG_SHOW_WARNINGS
/*
 * Create a warning dialog with the supplied message.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateWarningDlg(MSF_UINT32 screenHandle, int msg)
{
  MsfWindowHandle dlgHdl;
  MsfStringHandle dialogText;
  MsfStringHandle dialogTitle;
  int warning;
  MsfPosition     nullPos = {0, 0};
  int num_handles = 2;
  sec_ti_t *dlg;
#ifdef WAP_SUPPORT
  MsfActionHandle ok_action;
  sec_win_t *win;
  num_handles++;
#endif  
  
  /* Assign the warning message */
  switch (msg)
  {
    case SEC_ERR_MISSING_NR_KEY_SIGN_TEXT:
      warning = SEC_STR_ID_WARNING_MISSING_NR_KEY_SIGN_TEXT;
      break;
    case SEC_ERR_MISSING_AUT_KEY_OPEN_WIM:
      warning = SEC_STR_ID_WARNING_MISSING_AUT_KEY_OPEN_WIM;
      break;
    case SEC_ERR_COULD_NOT_STORE_CONTRACT:
      warning = SEC_STR_ID_WARNING_COULD_NOT_STORE_CONTRACT;
      break;
    case SEC_ERR_INSUFFICIENT_MEMORY:
      warning = SEC_STR_ID_WARNING_INSUFFICIENT_MEMORY;
      break;
    case SEC_ERR_GENERAL_ERROR:
      warning = SEC_STR_ID_WARNING_GENERAL_ERROR;
      break;
    case SEC_ERR_INVALID_PARAMETER:
      warning = SEC_STR_ID_WARNING_INVALID_PARAMETER;
      break;
    case SEC_ERR_MISSING_KEY:
      warning = SEC_STR_ID_WARNING_MISSING_KEY;
      break;
    case SEC_ERR_USER_NOT_VERIFIED:
      warning = SEC_STR_ID_WARNING_USER_NOT_VERIFIED;
      break;
    case SEC_ERR_MISSING_AUT_KEY_HANDSHAKE:
      warning = SEC_STR_ID_WARNING_MISSING_AUT_KEY_HANDSHAKE;
      break;
    #ifdef SEC_CFG_EXTRA_MISSING_KEY_ERROR_CALLS
    case SEC_ERR_MISSING_KEY_CONNECT:
      warning = SEC_STR_ID_WARNING_MISSING_KEY_CONNECT;
      break;
    case SEC_ERR_MISSING_KEY_STORE_CERT:
      warning = SEC_STR_ID_WARNING_MISSING_KEY_STORE_CERT;
      break;
    case SEC_ERR_MISSING_KEY_DELETE_CERT:
      warning = SEC_STR_ID_WARNING_MISSING_KEY_DELETE_CERT;
      break;
    case SEC_ERR_MISSING_KEY_CHANGE_NONREP:
      warning = SEC_STR_ID_WARNING_MISSING_KEY_CHANGE_NONREP;
      break;
    case SEC_ERR_MISSING_KEY_CHANGE_AUTH:
      warning = SEC_STR_ID_WARNING_MISSING_KEY_CHANGE_AUTH;
      break;
    #endif /* SEC_CFG_EXTRA_MISSING_KEY_ERROR_CALLS */
    default:
      return NULL;
  }
  dialogText = SEC_GET_STR_ID(warning);
  dialogTitle = SEC_GET_STR_ID(SEC_STR_ID_WARNING_TITLE);
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_WARNING_DLG, num_handles);

  dlgHdl = sec_tiCreateDialog(dialogTitle, dialogText, 
                                              MsfWarning);
  if (dlgHdl == 0)
    return NULL;  
#ifdef WAP_SUPPORT
  /* Action MsfOk / yesMsg */
  ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
                                        SEC_GET_STR_ID(SEC_STR_ID_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION(dlgHdl, ok_action);
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
#endif    
  MSF_WIDGET_DIALOG_SET_ATTR(dlgHdl, dialogText, SEC_DIALOG_TIME);

  dlg->handle[SEC_TI_DIALOG_HANDLE] = dlgHdl;
#ifdef WAP_SUPPORT
  win = SEC_ALLOCTYPE(sec_win_t);
  win->win_hdl = dlg->handle[SEC_TI_DIALOG_HANDLE];
  win->dlg = dlg;
  bra_win_show_window (BRA_WIN_ID_SEC_DLG, 
                    (bra_win_t*)win,
                    &nullPos, 
                    sec_myTiDelete, 
                    NULL,
                    NULL);
#else
  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], dlgHdl, 
                               &nullPos, 0, 0);
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_DIALOG_HANDLE], 1);
  }  
#endif
  return dlg;
}
#endif

/*
 * Create a form with the supplied session info.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateSessionInfoDlg(MSF_UINT32 screenHandle, sec_session_info_t sessInf)
{
 MsfStringHandle formTitle;
  MsfPosition	stringPos;
  MsfPosition nullPos = {0,0};
  MsfSize stringSize = {20,210};
  MsfWindowHandle formHdl = 0;
  MsfActionHandle ok_action = 0;
  MsfGadgetHandle connTypeGadgetStr = 0;
  MsfGadgetHandle encrGadgetStr = 0;
  MsfGadgetHandle encrKeyLenGadgetStr = 0;
  MsfGadgetHandle keyExchGadgetStr = 0;
  MsfGadgetHandle keyExchKeyLenGadgetStr = 0;
  MsfGadgetHandle hmacGadgetStr = 0;
  MsfGadgetHandle hmacKeyLenGadgetStr = 0;
  sec_ti_t *dlg;
  int num_handles = 11; /*minimum including non existing cancel_action*/

  dlg = sec_dlg_create (screenHandle, SEC_TI_SHOW_SESSION_INFO_DLG, num_handles);
  
  formTitle = SEC_GET_STR_ID(SEC_STR_ID_SESS_INFO_TITLE);

  if ((formHdl = sec_tiCreateForm(formTitle)) == 0)
    goto session_error;

  /* Action MsfOk */
	if ((ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(SEC_STR_ID_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto session_error;

  MSF_WIDGET_ADD_ACTION(formHdl, ok_action);

  stringPos.x = SEC_FIRST_X_POS;
	stringPos.y = SEC_FIRST_Y_POS;

  /* Create connectionType Gadget String */
  connTypeGadgetStr = sec_tiCreateConnTypeGadget(formHdl, 
                                                sessInf.connection_type, 
                                                &stringPos, stringSize);
  if (connTypeGadgetStr == 0)
    goto session_error;

  /* Create HMAC alg Gadget String */
  hmacGadgetStr = sec_tiCreateHmacAlgGadget(formHdl, 
                                            sessInf.hmac_alg, 
                                            &stringPos, stringSize);
  if (hmacGadgetStr == 0)
    goto session_error;

  /* Create HMAC key length Gadget String */
  hmacKeyLenGadgetStr = sec_tiCreateHmacKeyLenGadget(formHdl, 
                                                     sessInf.hmac_len, 
                                                    &stringPos, stringSize);
  if (hmacKeyLenGadgetStr == 0)
    goto session_error;

  /* Create encryption alg Gadget String */
  encrGadgetStr = sec_tiCreateEncrAlgGadget(formHdl, 
                                            sessInf.encryption_alg, 
                                            &stringPos, stringSize);
  if (encrGadgetStr == 0)
    goto session_error;

  /* Create encryption key length Gadget String */
  encrKeyLenGadgetStr = sec_tiCreateEncrKeyLenGadget(formHdl, 
                                                    sessInf.encryption_key_len, 
                                                    &stringPos, stringSize);
  if (encrKeyLenGadgetStr == 0)
    goto session_error;

  /* Create key exchange alg Gadget String */
  if ((sessInf.connection_type == SEC_CONNECTION_TYPE_TLS) || 
      (sessInf.connection_type == SEC_CONNECTION_TYPE_SSL))
    keyExchGadgetStr = sec_tiCreateKeyExchAlgGadget(formHdl, 
                                          sessInf.key_exchange_alg, 
                                          &stringPos, stringSize);
  else
    keyExchGadgetStr = sec_tiCreateKeyExchSuiteGadget(formHdl, 
                                          sessInf.key_exchange_alg, 
                                          &stringPos, stringSize);
  if (keyExchGadgetStr == 0)
    goto session_error;

  /* Create key exchange key length Gadget String */
  keyExchKeyLenGadgetStr = sec_tiCreateKeyExchKeyLenGadget(formHdl, 
                                                    sessInf.key_exchange_key_len, 
                                                    &stringPos, stringSize);
  if (keyExchKeyLenGadgetStr == 0)
    goto session_error;
  
  dlg->handle[SEC_TI_FORM_HANDLE] = formHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE] = 0;
  dlg->handle[SEC_TI_CONN_TYPE_GADGET_STR_HANDLE] = connTypeGadgetStr;
  dlg->handle[SEC_TI_ENCR_GADGET_STR_HANDLE] = encrGadgetStr;
  dlg->handle[SEC_TI_ENCR_KEY_LEN_GADGET_STR_HANDLE] = encrKeyLenGadgetStr;
  dlg->handle[SEC_TI_KEYEXCH_GADGET_STR_HANDLE] = keyExchGadgetStr;
  dlg->handle[SEC_TI_KEYEXCH_KEY_LEN_GADGET_STR_HANDLE]= keyExchKeyLenGadgetStr;
  dlg->handle[SEC_TI_HMAC_GADGET_STR_HANDLE] = hmacGadgetStr;
  dlg->handle[SEC_TI_HMAC_KEY_LEN_GADGET_STR_HANDLE] = hmacKeyLenGadgetStr;


  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], formHdl, 
                               &nullPos, 0, 0);
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }  
  return dlg;

session_error:
  if (formHdl != 0)
    MSF_WIDGET_RELEASE(formHdl);
  if (ok_action != 0)
    MSF_WIDGET_RELEASE(ok_action);
  if (connTypeGadgetStr != 0)
    MSF_WIDGET_RELEASE(connTypeGadgetStr);
  if (hmacGadgetStr != 0)
    MSF_WIDGET_RELEASE(hmacGadgetStr);
  if (hmacKeyLenGadgetStr != 0)
    MSF_WIDGET_RELEASE(hmacKeyLenGadgetStr);
  if (encrGadgetStr != 0)
    MSF_WIDGET_RELEASE(encrGadgetStr);
  if (encrKeyLenGadgetStr != 0)
    MSF_WIDGET_RELEASE(encrKeyLenGadgetStr);
  if (keyExchGadgetStr != 0)
    MSF_WIDGET_RELEASE(keyExchGadgetStr);
  if (keyExchKeyLenGadgetStr != 0)
    MSF_WIDGET_RELEASE(keyExchKeyLenGadgetStr);
  return NULL; 
}

#ifdef SEC_CFG_USE_CERT

#ifdef __MMI_KLG__
static int sec_tiSelectCert;

static void
sec_tiDeleteCertNamesOption (bra_win_t *win)
{
  sec_win_t *p;
  p = (sec_win_t *)(win);

  MSF_WIDGET_REMOVE (bra_win_get_screen (), p->win_hdl); 

  MSF_WIDGET_RELEASE (p->win_hdl); 
  MSF_WIDGET_RELEASE (p->accept);
  MSF_WIDGET_RELEASE (p->back);  
  SEC_FREE (p);
}

static void 
sec_tiCertOptDelConfirmation(MsfActionType response)
{
  extern sec_cert_name_t *glob_certNames;

  if(response != MsfOk)
    return;
 
  bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  SECif_deleteCert (MSF_MODID_SEC, 17, glob_certNames[sec_tiSelectCert].certId);  
  HDIa_widgetExtShowPopup(MSF_MODID_SEC, MSF_WIDGET_STRING_GET_PREDEFINED(WIDGET_STR_ID_DONE), MsfPromptSaveDone,0);
  {
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
    SECif_viewCertNames(MSF_MODID_SEC, 0, SEC_GET_USER_CERT | SEC_GET_ROOT_CERT );
  }
}

static void 
sec_tiCertOptDelAllConfirmation(MsfActionType response)
{
  int i;
  extern int glob_nbrofCerts;
  extern sec_cert_name_t *glob_certNames;

  if(response != MsfOk)
    return;
 
  bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  for(i = 0; i < glob_nbrofCerts; i++)
    SECif_deleteCert (MSF_MODID_SEC, 17, glob_certNames[i].certId);  
  HDIa_widgetExtShowPopup(MSF_MODID_SEC, MSF_WIDGET_STRING_GET_PREDEFINED(WIDGET_STR_ID_DONE), MsfPromptSaveDone,0);
  {
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
    SECif_viewCertNames(MSF_MODID_SEC, 0, SEC_GET_USER_CERT | SEC_GET_ROOT_CERT );
  }
}

static void 
sec_tiActionCertNamesOption (bra_win_t *win, MsfActionHandle sec_action)
{
  sec_win_t *p;

  p = (sec_win_t *)(win);  

  if (sec_action == p->accept)
  {    
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->win_hdl, 0)& MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* view */
      sec_win_t *sec_win;
      msf_widget_action_t* w = SEC_ALLOCTYPE(msf_widget_action_t);
      extern void sec_handleWidgetAction (msf_widget_action_t *w);

      bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);

      sec_win = (sec_win_t*)bra_win_get_window(BRA_WIN_ID_SEC_DLG);      
      w->handle = sec_win->dlg->handle[SEC_TI_DIALOG_HANDLE];
      w->action = sec_win->dlg->handle[SEC_TI_OK_ACTION_HANDLE];
      sec_handleWidgetAction(w);
    }
    else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->win_hdl, 1)& MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* delete */
      bra_dlg_create_dlg (MsfConfirmation,
                          MSF_WIDGET_STRING_GET_PREDEFINED(SEC_STR_ID_DELETE), 
                          MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_YES), 
                          MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_NO),
                          0, 
                          sec_tiCertOptDelConfirmation);
    }
    else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->win_hdl, 2)& MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* delete all */
      bra_dlg_create_dlg (MsfConfirmation,
                          MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_DELETE_ALL), 
                          MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_YES), 
                          MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_NO),
                          0, 
                          sec_tiCertOptDelAllConfirmation);
    }
  }
  else
  {
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  }
}

static void
sec_tiCreateCertNamesOption(void)
{
  sec_win_t* p;
  MsfPosition pos = {0,0};
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  p = SEC_ALLOCTYPE(sec_win_t);
  p->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, SEC_GET_STR_ID(BRA_STR_ID_OK), MsfOk, 3, 0x8000);
  p->back = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRA, SEC_GET_STR_ID(BRA_STR_ID_BACK), MsfBack, 3, 0x8000);
  p->win_hdl = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                       MsfImplicitChoice,
                                       &prop.displaySize,
                                       p->accept,
                                       0, /*Element Position*/
                                       0, /*Bit Mask*/
                                       0x8000,
                                       0 /*Default Style*/);

  MSF_WIDGET_SET_TITLE (p->win_hdl,SEC_GET_STR_ID(SEC_STR_ID_SHOW_CERT_NAMES_TITLE));
  MSF_WIDGET_WINDOW_SET_PROPERTIES (p->win_hdl,MSF_WINDOW_PROPERTY_TITLE);

  MSF_WIDGET_CHOICE_SET_ELEMENT (p->win_hdl, 0, SEC_GET_STR_ID(SEC_STR_ID_VIEW), 0, sec_get_list_num_image(0), 0, 1);
  MSF_WIDGET_CHOICE_SET_ELEMENT (p->win_hdl, 1, SEC_GET_STR_ID(BRA_STR_ID_DELETE), 0, sec_get_list_num_image(1), 0, 1);
  MSF_WIDGET_CHOICE_SET_ELEMENT (p->win_hdl, 2, SEC_GET_STR_ID(BRA_STR_ID_DELETE_ALL), 0, sec_get_list_num_image(2), 0, 1);

  MSF_WIDGET_ADD_ACTION (p->win_hdl, 
								 p->accept);
  MSF_WIDGET_ADD_ACTION (p->win_hdl, 
								 p->back);

  /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_SEC_CERT_OPT_DLG, 
                    (bra_win_t*)p, 
                    &pos, 
                    sec_tiDeleteCertNamesOption, 
                    NULL,
                    sec_tiActionCertNamesOption);
}

static void
sec_tiActionShowCertNamesDlg(bra_win_t *win, MsfActionHandle sec_action)
{
  sec_win_t *p;
  int i;
  extern int glob_nbrofCerts;

  p = (sec_win_t *)(win);

  if (sec_action == p->accept)
  {
    for (i=0; i<glob_nbrofCerts; i++)
    {
      if((MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->win_hdl, i)& MSF_CHOICE_ELEMENT_SELECTED))
      {  
        sec_tiSelectCert = i;
        sec_tiCreateCertNamesOption();
        break;
      }
    }
  }
  else
  {
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  }
}
#endif /* __MMI_KLG__ */

/*
 * Create a menu with the supplied certificate names.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateShowCertNamesDlg(MSF_UINT32 screenHandle, int nbrOfCerts, 
                              sec_cert_name_t *certNames)
{
  MsfStringHandle menuTitle;
  int i;
#ifdef __MMI_KLG__  
  int properties;
#endif  
  MsfPosition nullPos = {0,0};
  MsfStringHandle nameStr = 0;
  MsfWindowHandle menuHdl;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  sec_ti_t *dlg;
  int num_handles = 4; 

#ifdef WAP_SUPPORT
  sec_win_t* win;
  if(nbrOfCerts == 0)
  {
    //extern void BRAif_showDialog (MSF_UINT8 dlg_type, MSF_UINT32 ms);
    //BRAif_showDialog(MsfInfo, MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_EMPTY));
    HDIa_widgetExtShowPopup(MSF_MODID_SEC, MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_EMPTY), MsfPromptEmpty, 0);      
    return NULL;
  }
#endif
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_SHOW_CERT_NAMES_DLG, num_handles);

  menuTitle = SEC_GET_STR_ID(SEC_STR_ID_SHOW_CERT_NAMES_TITLE);
#ifdef __MMI_KLG__
  properties = (MSF_WINDOW_PROPERTY_TITLE | MSF_WINDOW_PROPERTY_SECURE | MSF_WINDOW_PROPERTY_SCROLLBARVER);
  menuHdl = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA, MsfImplicitChoice, &sec_display_size, 0, 0, 0, properties, 0);
  MSF_WIDGET_CHOICE_ATTR_PROPERTY(menuHdl, 0, MSF_CHOICE_ELEMENT_STRING_1);
  MSF_WIDGET_SET_TITLE(menuHdl, menuTitle);
#else  
  menuHdl = sec_tiCreateMenu(menuTitle);
#endif  

  ti_nbrOfCerts = nbrOfCerts;
  if (nbrOfCerts > 0)
  {
    ti_index = (int *)SEC_ALLOC((nbrOfCerts*sizeof(int))+sizeof(int));
    ti_index[0] = 0;
  }
    else
    ti_index = NULL;

  /* Create name strings */
  for (i=0; i<nbrOfCerts; i++)
  {
    if ((certNames[i].nameType == SEC_CERT_NAME_WTLS) || 
        (certNames[i].nameType == SEC_CERT_NAME_X509))
#ifdef WAP_SUPPORT
      nameStr = sec_tiGetIssuerStrHdl(certNames[i].charSet, 
                                      (void *)certNames[i].friendlyName, 
                                      certNames[i].friendlyNameLen,
                                      0);
#else
      nameStr = sec_tiGetIssuerStrHdl(certNames[i].charSet, 
                                      (void *)certNames[i].friendlyName, 
                                      certNames[i].friendlyNameLen,
                                      SEC_GET_STR_ID(SEC_STR_ID_FR_NAME));
#endif
    else if (certNames[i].nameType == SEC_WRITTEN_NAME)
    {
      /* The friendly name is written by the user */
      long tmpNameLen = certNames[i].friendlyNameLen;
      char *tmpStr = (char *)SEC_ALLOC(
        (2*certNames[i].friendlyNameLen+MSF_WIDGET_STRING_GET_LENGTH(
        SEC_GET_STR_ID(SEC_STR_ID_FR_NAME),0,MsfUtf8))+5);
      char *tmpName = tmpStr;

      tmpStr[0] = '\0';
#ifndef WAP_SUPPORT
      MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(SEC_STR_ID_FR_NAME), tmpStr, MsfUtf8);

      tmpName += strlen(tmpStr);
#endif
      /* Convert string to UTF8 */
      if (sec_tiCvtToUtf8((unsigned char *)certNames[i].friendlyName, 
          certNames[i].friendlyNameLen, tmpName, &tmpNameLen, 
          certNames[i].charSet) != SEC_ERR_OK)
      {
        MSF_WIDGET_RELEASE(menuHdl);
        SEC_FREE(tmpStr);
        return NULL;
      }

      nameStr = SEC_STRCONV(tmpStr);
      SEC_FREE(tmpStr);
    }
    if (nameStr == 0)
    {
      MSF_WIDGET_RELEASE(menuHdl);
      return NULL;
    }
    /* Insert elements */
#ifdef WAP_SUPPORT
    ti_index[i] = MSF_WIDGET_CHOICE_SET_ELEMENT( menuHdl, i,/*ti_index[i],*/ 
                                                nameStr, 
                                                SEC_GET_STR_ID(SEC_STR_ID_EMPTY), 
                                                sec_get_list_num_image(i), 0, 1);
    MSF_WIDGET_RELEASE(nameStr);
#else
    ti_index[i] = MSF_WIDGET_CHOICE_SET_ELEMENT( menuHdl, i,/*ti_index[i],*/ 
                                                nameStr, 
                                                SEC_GET_STR_ID(SEC_STR_ID_EMPTY), 
                                                0, 0, 1);
#endif
  } /* for */
  /* Action MsfOk */
#ifdef __MMI_KLG__
  ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA,
                                       SEC_GET_STR_ID(BRA_STR_ID_OPTIONS), 
                                       MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);  
#else  
	ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
                                       SEC_GET_STR_ID(SEC_STR_ID_VIEW), 
                                       MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
#endif                                       
	MSF_WIDGET_ADD_ACTION(menuHdl, ok_action);

  /* Action MsfCancel */
#ifdef __MMI_KLG__
  cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA,
                                           SEC_GET_STR_ID(BRA_STR_ID_BACK), 
                                           MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED);
#else  
  cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
                                           SEC_GET_STR_ID(BRA_STR_ID_BACK), 
                                           MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED);
#endif                                           
	MSF_WIDGET_ADD_ACTION(menuHdl, cancel_action);

  dlg->handle[SEC_TI_MENU_HANDLE] = menuHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE] = cancel_action;

#ifdef WAP_SUPPORT
  win = SEC_ALLOCTYPE(sec_win_t);
  win->win_hdl = dlg->handle[SEC_TI_DIALOG_HANDLE];
#ifdef __MMI_KLG__  
  win->accept = ok_action;
  win->back = cancel_action;  
#endif  
  win->dlg = dlg;
#ifdef __MMI_KLG__
  bra_win_show_window (BRA_WIN_ID_SEC_DLG, 
                    (bra_win_t*)win,
                    &nullPos, 
                    sec_myTiDelete, 
                    NULL,
                    sec_tiActionShowCertNamesDlg);
#else  
  bra_win_show_window (BRA_WIN_ID_SEC_DLG, 
                    (bra_win_t*)win,
                    &nullPos, 
                    sec_myTiDelete, 
                    NULL,
                    NULL);
#endif                    
#else
  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], menuHdl, 
                               &nullPos, 0, 0);
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_MENU_HANDLE], 1);
  }  
#endif
  return dlg;
}
#endif

#ifdef SEC_CFG_USE_KEYS
/*
 * Create a certificate names menu with the supplied certificate names.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateChooseCertByNameDlg(MSF_UINT32 screenHandle, int title, 
                                int nbrOfCerts, sec_cert_name_t *certNames)
{
  MsfStringHandle menuTitle;
  int i;
  MsfPosition nullPos = {0,0};
  MsfStringHandle nameStr = 0;
  MsfWindowHandle menuHdl;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  sec_ti_t *dlg;
  int num_handles = 4; 
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_CHOOSE_CERT_BY_NAME_DLG, num_handles);

  menuTitle = SEC_GET_STR_ID(title);
  
  if ((menuHdl = sec_tiCreateMenu(menuTitle)) == 0)
    return NULL;
	
	ti_nbrOfCerts = nbrOfCerts;
  if (nbrOfCerts > 0)
  {
    ti_index = (int *)SEC_ALLOC((nbrOfCerts*sizeof(int))+sizeof(int));
    ti_index[0] = 0;
  }
  else
    ti_index = NULL;

  /* Create name strings */
  for (i=0; i<nbrOfCerts; i++)
  {
    if ((certNames[i].nameType == SEC_CERT_NAME_WTLS) || 
        (certNames[i].nameType == SEC_CERT_NAME_X509))
      /* The friendly name is a WTLS or X.509 issuer/subject */
      nameStr = sec_tiGetIssuerStrHdl(certNames[i].charSet, 
                                      (void *)certNames[i].friendlyName, 
                                      certNames[i].friendlyNameLen, 
                                      SEC_GET_STR_ID(SEC_STR_ID_FR_NAME));
    else if (certNames[i].nameType == SEC_WRITTEN_NAME)
    {
      /* The friendly name is written by the user */
      long tmpNameLen = certNames[i].friendlyNameLen * 2;
      char *tmpStr = (char *)SEC_ALLOC(
        (2*certNames[i].friendlyNameLen+MSF_WIDGET_STRING_GET_LENGTH(
        SEC_GET_STR_ID(SEC_STR_ID_FR_NAME),0,MsfUtf8))+1);
      char *tmpName = tmpStr;

      tmpStr[0] = '\0';
      MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(SEC_STR_ID_FR_NAME), tmpStr, MsfUtf8);

      tmpName += strlen(tmpStr);

      /* Convert string to UTF8 */
      if (sec_tiCvtToUtf8((unsigned char *)certNames[i].friendlyName, 
          certNames[i].friendlyNameLen, tmpName, &tmpNameLen, 
          certNames[i].charSet) != SEC_ERR_OK)
      {
        MSF_WIDGET_RELEASE(menuHdl);
        SEC_FREE(tmpStr);
        return NULL;
      }

      nameStr = SEC_STRCONV(tmpStr);
      SEC_FREE(tmpStr);
    }
    if (nameStr == 0)
    {
      MSF_WIDGET_RELEASE(menuHdl);
      return NULL;
    }

    /* Insert elements */
    ti_index[i] = MSF_WIDGET_CHOICE_SET_ELEMENT( menuHdl, i,
                                              nameStr, SEC_GET_STR_ID(SEC_STR_ID_EMPTY), 
                                              0, 0, 1);
  } /* for */

  /* Action MsfOk */
	if ((ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(SEC_STR_ID_VIEW), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
  {
    MSF_WIDGET_RELEASE(menuHdl);
    return NULL;
  }
  MSF_WIDGET_ADD_ACTION(menuHdl, ok_action);

  /* Action MsfCancel */
	if ((cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(SEC_STR_ID_CANCEL), MsfCancel, 3, 
       MSF_ACTION_PROPERTY_ENABLED)) == 0)
  {
    MSF_WIDGET_RELEASE(menuHdl);
    MSF_WIDGET_RELEASE(ok_action);
    return NULL;
  }
  MSF_WIDGET_ADD_ACTION(menuHdl, cancel_action);

  dlg->handle[SEC_TI_MENU_HANDLE] = menuHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE] = cancel_action;

  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], menuHdl, 
                               &nullPos, 0, 0);
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_MENU_HANDLE], 1);
  }  
  return dlg;

}
#else
sec_ti_t *
sec_tiCreateChooseCertByNameDlg(MSF_UINT32 screenHandle, int title, 
                                int nbrOfCerts, sec_cert_name_t *certNames)
{
   return NULL;
}
#endif

#ifdef SEC_CFG_USE_CERT

#ifdef WAP_SUPPORT

static void
sec_tiActionCtkStoreCertDlg(ctk_screen_handle scrid)
{
    HDIc_widgetAction(MSF_MODID_SEC, certFormHdl, certFormOk);
	widget_send_update_event_to_wap();
}

static void
sec_tiCancelCtkStoreCertDlg(ctk_screen_handle scrid)
{
    HDIc_widgetAction(MSF_MODID_SEC, certFormHdl, certFormDel);
	widget_send_update_event_to_wap();
}

sec_ti_t *
sec_tiCreateCtkStoreCertDlg(MSF_UINT32 screenHandle, MSF_INT16 issuerCharSet, 
    	                    void *issuer, int issuerLen, 
                          MSF_UINT32 validNotBefore, 
                          MSF_UINT32 validNotAfter, 
                          MSF_INT16 subjectCharSet, 
                          void *subject, int subjectLen)
{
  kal_uint8    *text;
  kal_uint8    *str;
  int          text_size, l;
  ctk_screen_handle	scrid;
  sec_ti_t *dlg = NULL;  
  MsfPosition	nullPos = {0,0};
  MsfStringHandle strHdl;
  sec_win_t *win;
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_STORE_CERT_DLG, 2);

  /* init text */
  text_size = 512;
  text = (kal_uint8*)SEC_ALLOC(text_size);
  widget_utf8_to_ucs2_string(text, text_size, (kal_uint8*) "");

  /* issuer */    
  text = widget_ucs2str_append_id(MSF_MODID_SEC, text, &text_size, SEC_STR_ID_ISSUER);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n");
  strHdl = sec_tiGetIssuerStrHdl(issuerCharSet, issuer, issuerLen, 0);
  if(strHdl == 0)
    goto show_cert_error;

  l = MSF_WIDGET_STRING_GET_LENGTH(strHdl, 1, MsfUtf8);
  str = (kal_uint8*)SEC_ALLOC(l+1);
  MSF_WIDGET_STRING_GET_DATA (strHdl, (char*)str, MsfUtf8);
  MSF_WIDGET_RELEASE(strHdl);
  str[l] = '\0';
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, str);
  SEC_FREE(str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n\n");

  /* subject */
  text = widget_ucs2str_append_id(MSF_MODID_SEC, text, &text_size, SEC_STR_ID_SUBJECT);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n");
  strHdl = sec_tiGetIssuerStrHdl(subjectCharSet, subject, subjectLen, 0);
  if(strHdl == 0)
    goto show_cert_error;
  l = MSF_WIDGET_STRING_GET_LENGTH(strHdl, 1, MsfUtf8);
  str = (kal_uint8*)SEC_ALLOC(l+1);
  MSF_WIDGET_STRING_GET_DATA (strHdl, (char*)str, MsfUtf8);
  MSF_WIDGET_RELEASE(strHdl);
  str[l] = '\0';
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, str);
  SEC_FREE(str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n\n");

  /* validNotBefore */
  text = widget_ucs2str_append_id(MSF_MODID_SEC, text, &text_size, SEC_STR_ID_VAL_NOT_BEF);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n");
  str = (kal_uint8*)SEC_ALLOC(32);
  sec_tiCvtTimeToStr(validNotBefore, (char**)&str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, str);
  SEC_FREE(str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n\n");

  /* validNotAfter */
  text = widget_ucs2str_append_id(MSF_MODID_SEC, text, &text_size, SEC_STR_ID_VAL_NOT_AFT);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n");
  str = (kal_uint8*)SEC_ALLOC(32);
  sec_tiCvtTimeToStr(validNotAfter, (char**)&str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, str);
  SEC_FREE(str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n\n");

  /* Create widow */
  certFormHdl = HDIa_widgetExtCreateTextView(MSF_MODID_SEC, text, SEC_STR_ID_STORE_CERT_TITLE, 0); 
  dlg->handle[SEC_TI_FORM_HANDLE] = certFormHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = certFormOk;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE] = certFormDel;
  SEC_FREE(text); // release the text
  
  /* Set Key */
  scrid = HDIa_widgetCtkGetScreenHandle(certFormHdl);
  ctk_screen_addLSK_UA(scrid, SEC_STR_ID_OK, 0, NULL, sec_tiActionCtkStoreCertDlg, KAL_TRUE);
  ctk_screen_addRSK_UA(scrid, SEC_STR_ID_CANCEL, 0, NULL, sec_tiCancelCtkStoreCertDlg, KAL_TRUE);

  win = SEC_ALLOCTYPE(sec_win_t);
  win->win_hdl = dlg->handle[SEC_TI_FORM_HANDLE];
  win->dlg = dlg;
  bra_win_show_window (BRA_WIN_ID_SEC_DLG, 
                    (bra_win_t*)win,
                    &nullPos, 
                    sec_myTiDelete, 
                    NULL,
                    NULL);

  return dlg;

show_cert_error:
  SEC_FREE(text);
  return NULL;
}

#endif

/*
 * Create a store certificate form with the supplied certificate fields.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateStoreCertDlg(MSF_UINT32 screenHandle, MSF_INT16 issuerCharSet, 
    	                    void *issuer, int issuerLen, 
                          MSF_UINT32 validNotBefore, 
                          MSF_UINT32 validNotAfter, 
                          MSF_INT16 subjectCharSet, 
                          void *subject, int subjectLen, char certType)
{
  MsfWindowHandle	form_handle = 0;
  MsfActionHandle ok_action = 0;
  MsfActionHandle cancel_action = 0;
  MsfGadgetHandle issuer_gadgetStr = 0;
	MsfGadgetHandle subject_gadgetStr = 0;	
	MsfGadgetHandle valid_not_bef_gadgetStr = 0;
	MsfGadgetHandle valid_not_aft_gadgetStr = 0;
#ifdef WAP_SUPPORT
   MsfGadgetHandle issuer_title_gadgetStr = 0;
   MsfGadgetHandle subject_title_gadgetStr = 0;	
   MsfGadgetHandle valid_not_bef_title_gadgetStr = 0;
   MsfGadgetHandle valid_not_aft_title_gadgetStr = 0;
#endif
  MsfGadgetHandle textGadgetStr = 0;
  MsfGadgetHandle textInputGadget = 0;
  MsfStringHandle formTitle;
  MsfPosition	stringPos;
  MsfPosition	nullPos = {0,0};
#ifdef WAP_SUPPORT
  MsfSize stringSize = {20, 75};
#else
  MsfSize stringSize = {40, 230};
#endif
#ifdef WAP_SUPPORT
  sec_win_t *win;
  int num_handles = 9+4; /*Minimum to this dialog*/
#else
  int num_handles = 9; /*Minimum to this dialog*/
#endif
  sec_ti_t *dlg = NULL;

#ifdef WAP_SUPPORT
  if(certType != SEC_USER_CERT)
  {
    return sec_tiCreateCtkStoreCertDlg(screenHandle, issuerCharSet, issuer, issuerLen, validNotBefore,
        validNotAfter, subjectCharSet, subject, subjectLen);
  }
#endif

  if (certType == SEC_USER_CERT)
    num_handles ++; /*for input of friendly name*/
  dlg = sec_dlg_create (screenHandle, SEC_TI_STORE_CERT_DLG, num_handles);

  formTitle = SEC_GET_STR_ID(SEC_STR_ID_STORE_CERT_TITLE);

  if ((form_handle = sec_tiCreateForm(formTitle)) == 0)
    goto store_cert_error;
  

  /* Action MsfOk */
	if ((ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC, 
        SEC_GET_STR_ID(SEC_STR_ID_STORE), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)  
    goto store_cert_error;
	MSF_WIDGET_ADD_ACTION(form_handle, ok_action);

  /* Action MsfCancel */
	if ((cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
      SEC_GET_STR_ID(SEC_STR_ID_CANCEL), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto store_cert_error;
  MSF_WIDGET_ADD_ACTION(form_handle, cancel_action);

  /* Create string gadgets */
  stringPos.x = SEC_FIRST_X_POS;
	stringPos.y = SEC_FIRST_Y_POS;
  
  textGadgetStr = sec_tiCreateStringGadget(form_handle, 
                                          SEC_GET_STR_ID(SEC_STR_ID_STORE_CERT), 
                                          stringPos, &stringSize, 0);
  if (textGadgetStr == 0)
    goto store_cert_error;

  stringPos.y = (MSF_INT16)(stringPos.y + stringSize.height + 5);
#ifndef WAP_SUPPORT
  stringSize.height = 50;;
  stringSize.width = (MSF_INT16) (sec_display_size.width-10);
#endif
#ifdef WAP_SUPPORT
  issuer_title_gadgetStr = sec_tiCreateStringGadget(form_handle, 
                                          SEC_GET_STR_ID(SEC_STR_ID_ISSUER), 
                                          stringPos, 
                                          &stringSize, 0);

  (stringPos).y = (MSF_INT16)((stringPos).y + stringSize.height + 5);

  issuer_gadgetStr = sec_tiCreateIssuerGadget(form_handle, 
                                              issuerCharSet, issuer, issuerLen, 
                                              0,
                                              &stringPos, stringSize);
#else
  issuer_gadgetStr = sec_tiCreateIssuerGadget(form_handle, 
                                              issuerCharSet, issuer, issuerLen, 
                                              SEC_GET_STR_ID(SEC_STR_ID_ISSUER),
                                              &stringPos, stringSize);
#endif
  if (issuer_gadgetStr == 0)
    goto store_cert_error;
#ifdef WAP_SUPPORT
  subject_title_gadgetStr = sec_tiCreateStringGadget(form_handle, 
                                          SEC_GET_STR_ID(SEC_STR_ID_SUBJECT),
                                          stringPos, 
                                          &stringSize, 0);

  (stringPos).y = (MSF_INT16)((stringPos).y + stringSize.height + 5);

  subject_gadgetStr = sec_tiCreateIssuerGadget(form_handle, subjectCharSet, 
                                               subject, subjectLen, 
                                              0,
                                              &stringPos, stringSize);
#else
  subject_gadgetStr = sec_tiCreateIssuerGadget(form_handle, subjectCharSet, 
                                               subject, subjectLen, 
                                              SEC_GET_STR_ID(SEC_STR_ID_SUBJECT),
                                              &stringPos, stringSize);
#endif
  if (subject_gadgetStr == 0)
    goto store_cert_error;
#ifdef WAP_SUPPORT
  valid_not_bef_title_gadgetStr = sec_tiCreateStringGadget(form_handle, 
                                          SEC_GET_STR_ID(SEC_STR_ID_VAL_NOT_BEF),
                                          stringPos, 
                                          &stringSize, 0);

  (stringPos).y = (MSF_INT16)((stringPos).y + stringSize.height + 5);

  valid_not_bef_gadgetStr = sec_tiCreateValidDateGadget(form_handle, 
                                              validNotBefore, 
                                              0,
                                              &stringPos, stringSize);
#else
  valid_not_bef_gadgetStr = sec_tiCreateValidDateGadget(form_handle, 
                                              validNotBefore, 
                                              SEC_GET_STR_ID(SEC_STR_ID_VAL_NOT_BEF),
                                              &stringPos, stringSize);
#endif
  if (valid_not_bef_gadgetStr == 0)
    goto store_cert_error;
#ifdef WAP_SUPPORT
  valid_not_aft_title_gadgetStr = sec_tiCreateStringGadget(form_handle, 
                                          SEC_GET_STR_ID(SEC_STR_ID_VAL_NOT_AFT),
                                          stringPos, 
                                          &stringSize, 0);

  (stringPos).y = (MSF_INT16)((stringPos).y + stringSize.height + 5);

  valid_not_aft_gadgetStr = sec_tiCreateValidDateGadget(form_handle, 
                                               validNotAfter, 
                                               0,
                                               &stringPos, stringSize);
#else
  valid_not_aft_gadgetStr = sec_tiCreateValidDateGadget(form_handle, 
                                               validNotAfter, 
                                               SEC_GET_STR_ID(SEC_STR_ID_VAL_NOT_AFT),
                                               &stringPos, stringSize);
#endif
  if (valid_not_aft_gadgetStr == 0)
    goto store_cert_error;
  
	/* Text input Gadget if it is a user certificate */
  if (certType == SEC_USER_CERT)
  {
    MsfSize textInputSize = {20,200};
    MsfTextType textInputType;
    
    textInputType = MsfText;
    textInputGadget = sec_tiCreateTextInputGadget(form_handle, 
                                            stringPos, &textInputSize,
                                            SEC_MAX_INPUT_LEN,
                                            textInputType);
    if (textInputGadget == 0)
      goto store_cert_error;
  }

  dlg->handle[SEC_TI_FORM_HANDLE] = form_handle;
  dlg->handle[SEC_TI_TEXT_GADGET_STR_HANDLE] = textGadgetStr;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
  dlg->handle[SEC_TI_ISSUER_GADGET_STR_HANDLE] = issuer_gadgetStr;
	dlg->handle[SEC_TI_SUBJECT_GADGET_STR_HANDLE] = subject_gadgetStr;
	dlg->handle[SEC_TI_VALID_NOT_BEF_GADGET_STR_HANDLE] = valid_not_bef_gadgetStr;
	dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE] = valid_not_aft_gadgetStr;
  if (certType == SEC_USER_CERT)
	  dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_HANDLE] = textInputGadget;

#ifdef WAP_SUPPORT
  if (certType == SEC_USER_CERT)
  {
     dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_HANDLE+1] = issuer_title_gadgetStr;
     dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_HANDLE+2] = subject_title_gadgetStr;
     dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_HANDLE+3] = valid_not_bef_title_gadgetStr;
     dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_HANDLE+4] = valid_not_aft_title_gadgetStr;
  }
  else
  {
     dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE+1] = issuer_title_gadgetStr;
     dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE+2] = subject_title_gadgetStr;
     dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE+3] = valid_not_bef_title_gadgetStr;
     dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE+4] = valid_not_aft_title_gadgetStr;
  }
#endif

#ifdef WAP_SUPPORT
  win = SEC_ALLOCTYPE(sec_win_t);
  win->win_hdl = dlg->handle[SEC_TI_DIALOG_HANDLE];
  win->dlg = dlg;
  bra_win_show_window (BRA_WIN_ID_SEC_DLG, 
                    (bra_win_t*)win,
                    &nullPos, 
                    sec_myTiDelete, 
                    NULL,
                    NULL);
#else
  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], form_handle, 
                               &nullPos, 0, 0);
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
#ifdef WAP_SUPPORT
    {
      extern MsfWindowHandle bra_view_get_paintbox (void);
      extern int bra_view_if_has_viewable_page(void);
      if(!bra_view_if_has_viewable_page())
        MSF_WIDGET_SET_IN_FOCUS (bra_view_get_paintbox(), 0);       
    }
#endif
  }
#endif
  
  return dlg;

store_cert_error:
  if (form_handle != 0)
    MSF_WIDGET_RELEASE(form_handle);
  if (ok_action != 0)
    MSF_WIDGET_RELEASE(ok_action);
  if (cancel_action != 0)
    MSF_WIDGET_RELEASE(cancel_action);
  if (subject_gadgetStr != 0)
    MSF_WIDGET_RELEASE(subject_gadgetStr);
  if (issuer_gadgetStr != 0)
    MSF_WIDGET_RELEASE(issuer_gadgetStr);
  if (valid_not_bef_gadgetStr != 0)
    MSF_WIDGET_RELEASE(valid_not_bef_gadgetStr);
  if (valid_not_aft_gadgetStr != 0)
    MSF_WIDGET_RELEASE(valid_not_aft_gadgetStr);
  return NULL;
}
#endif /*SEC_CFG_USE_CERT*/
/* 
 * Create a form with the supplied display name, message,
 * yes message, and no message. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateConfDispNameDlg(MSF_UINT32 screenHandle, MSF_INT16 charSet, 
                       void *displayName, int displayNameLen, 
                       int msg, int yesMsg, int noMsg)
{
  MsfStringHandle formTitle;
  MsfStringHandle nameStr;
#ifdef WAP_SUPPORT
  char *tmpStr, *tmpName;
#else  
  MsfPosition	stringPos;
  MsfSize stringSize = {80,220};
  char *tmpStr, *tmpName;
  long tmpNameLen = 2 * displayNameLen + 3;
#endif  
  MsfWindowHandle formHdl = 0;
  MsfActionHandle ok_action = 0;
  MsfActionHandle cancel_action = 0;
#ifndef WAP_SUPPORT  
  MsfGadgetHandle nameGadgetStr = 0;
#endif  
  MsfPosition	nullPos = {0,0};
#ifdef WAP_SUPPORT
  sec_win_t *win;
  int num_handles = 4; /*Minimum to this dialog*/
#else
  int num_handles = 5; /*Minimum to this dialog*/
#endif
  sec_ti_t *dlg = NULL;

  dlg = sec_dlg_create (screenHandle, SEC_TI_CONFIRM_DISP_NAME_DLG, num_handles);

  formTitle = SEC_GET_STR_ID(SEC_STR_ID_CONF_DISP_NAME_TITLE);

  /* Convert displayName to MsfStringHandle */

  if (charSet == -1) /*X509 certificate*/
  {
#ifdef WAP_SUPPORT
    tmpStr  = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                              SEC_GET_STR_ID(msg),0,MsfUtf8)*(displayNameLen*2)+3);
  
    tmpName = tmpStr;

    tmpStr[0] = '\0';
    MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(msg), tmpStr, MsfUtf8);
    nameStr = SEC_STRCONV(tmpStr);
    SEC_FREE(tmpStr);
#else
    if ( (nameStr = sec_tiGetIssuerStrHdl(charSet, 
       displayName, displayNameLen, SEC_GET_STR_ID(msg))) == 0)
      return 0;
#endif
  }
  else
  {
    tmpStr  = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                              SEC_GET_STR_ID(msg),0,MsfUtf8)*(displayNameLen*2)+3);
  
    tmpName = tmpStr;

    tmpStr[0] = '\0';
    MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(msg), tmpStr, MsfUtf8);

#ifndef WAP_SUPPORT
    tmpName += strlen(tmpStr);
    /* Convert string to UTF8 */
    if (sec_tiCvtToUtf8((unsigned char *)displayName, displayNameLen, 
      tmpName, &tmpNameLen, charSet) != SEC_ERR_OK)
    {
      SEC_FREE(tmpStr);
      return NULL;
    }
#endif  
    nameStr = SEC_STRCONV(tmpStr);
    SEC_FREE(tmpStr);
  }
#ifdef WAP_SUPPORT
  formHdl = sec_tiCreateDialog(formTitle, nameStr, MsfConfirmation);
  MSF_WIDGET_DIALOG_SET_ATTR(formHdl, nameStr, 0);
#else
  if ((formHdl = sec_tiCreateForm(formTitle)) == 0)
    return NULL;
#endif
  /* Action MsfOk */
	if ((ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(yesMsg), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto disp_name_error;

	MSF_WIDGET_ADD_ACTION(formHdl, ok_action);

  /* Action MsfCancel */
	if ((cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(noMsg), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto disp_name_error;

  MSF_WIDGET_ADD_ACTION(formHdl, cancel_action);
#ifndef WAP_SUPPORT
  /* String Gadget nameStr */
	stringPos.x = SEC_FIRST_X_POS;
	stringPos.y = SEC_FIRST_Y_POS;
  nameGadgetStr = sec_tiCreateStringGadget(formHdl, 
                                           nameStr, stringPos, 
                                           &stringSize, 0);
  if (nameGadgetStr == 0)
    goto disp_name_error;
#endif
  dlg->handle[SEC_TI_FORM_HANDLE] = formHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
#ifndef WAP_SUPPORT
  dlg->handle[SEC_TI_NAME_GADGET_STR_HANDLE]= nameGadgetStr;
#endif
#ifdef WAP_SUPPORT
  win = SEC_ALLOCTYPE(sec_win_t);
  win->win_hdl = dlg->handle[SEC_TI_DIALOG_HANDLE];
  win->dlg = dlg;
  bra_win_show_window (BRA_WIN_ID_SEC_DLG, 
                    (bra_win_t*)win,
                    &nullPos, 
                    sec_myTiDelete, 
                    NULL,
                    NULL);
#else
  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], formHdl, &nullPos, 0, 0);
  
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }  
#endif
  return dlg;

disp_name_error:
  if (formHdl != 0)
    MSF_WIDGET_RELEASE(formHdl);
  if (ok_action != 0)
    MSF_WIDGET_RELEASE(ok_action);
  if (cancel_action != 0)
    MSF_WIDGET_RELEASE(cancel_action);
  return NULL;
}

#ifdef SEC_CFG_USE_CERT
/*
 * Create a form with the supplied certificate parts and cancel string.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
#ifdef WAP_SUPPORT

static void
sec_tiSendWidgetActionOk (ctk_screen_handle scrid)
{
  MSF_UINT32             action;
  MSF_UINT32             handle;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;

  CTK_UNUSED(scrid);
  
  handle = certFormHdl;
  action = certFormOk;  
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint32(&cvt_obj, &handle);
  msf_dcvt_uint32(&cvt_obj, &action);
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (MSF_SIG_WIDGET_ACTION, 0,
                                     MSF_MODID_SEC, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint32(&cvt_obj, &handle);
    msf_dcvt_uint32(&cvt_obj, &action);
    MSF_SIGNAL_SEND (signal_buffer);
  }
  widget_send_update_event_to_wap();
} 

static void 
sec_tiCertDelConfirmation(MsfActionType response)
{
  MSF_UINT32             action;
  MSF_UINT32             handle;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;

  if(response != MsfOk)
    return;

  CTK_UNUSED(act_scrid);
  
  handle = certFormHdl;
  action = certFormDel;  
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint32(&cvt_obj, &handle);
  msf_dcvt_uint32(&cvt_obj, &action);
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (MSF_SIG_WIDGET_ACTION, 0,
                                     MSF_MODID_SEC, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint32(&cvt_obj, &handle);
    msf_dcvt_uint32(&cvt_obj, &action);
    MSF_SIGNAL_SEND (signal_buffer);
  }
  widget_send_update_event_to_wap();
  HDIa_widgetExtShowPopup(MSF_MODID_SEC, MSF_WIDGET_STRING_GET_PREDEFINED(WIDGET_STR_ID_DONE), MsfPromptSaveDone,0);
}

static void
sec_tiSendWidgetActionDel (ctk_screen_handle scrid)
{
  act_scrid = scrid;

  bra_dlg_create_dlg (MsfConfirmation,
                      MSF_WIDGET_STRING_GET_PREDEFINED(SEC_STR_ID_DELETE), 
                      MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_YES), 
                      MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_NO),
                      0, 
                      sec_tiCertDelConfirmation);
} 

sec_ti_t *
sec_tiCreateShowCertDlg(MSF_UINT32 screenHandle, MSF_INT16 issuerCharSet, 
                      void *issuer, int issuerLen,
                      MSF_UINT32 validNotBefore, 
                      MSF_UINT32 validNotAfter, 
                      MSF_INT16 subjectCharSet, 
                      void *subject, int subjectLen,
                      unsigned char *fingerprint, int fingerprintLen,
                      int cancelStr)
{
  kal_uint8    *text;
  kal_uint8    *str;
  int          text_size, i, l;
  ctk_screen_handle	scrid;
  sec_ti_t *dlg = NULL;  
  MsfPosition	nullPos = {0,0};
  unsigned char *p1 = fingerprint;
  char *p2;
  MsfStringHandle strHdl;
  sec_win_t *win;
  
  if (cancelStr == SEC_STR_ID_DELETE)
    dlg = sec_dlg_create (screenHandle, SEC_TI_SHOW_CERT_DLG, 2);
  else
    dlg = sec_dlg_create (screenHandle, SEC_TI_SHOW_VERIFIED_CERT_DLG, 2);

  /* init text */
  text_size = 512;
  text = (kal_uint8*)SEC_ALLOC(text_size);
  widget_utf8_to_ucs2_string(text, text_size, (kal_uint8*) "");

  /* issuer */    
  text = widget_ucs2str_append_id(MSF_MODID_SEC, text, &text_size, SEC_STR_ID_ISSUER);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n");
  strHdl = sec_tiGetIssuerStrHdl(issuerCharSet, issuer, issuerLen, 0);
  if(strHdl == 0)
    goto show_cert_error;

  l = MSF_WIDGET_STRING_GET_LENGTH(strHdl, 1, MsfUtf8);
  str = (kal_uint8*)SEC_ALLOC(l+1);
  MSF_WIDGET_STRING_GET_DATA (strHdl, (char*)str, MsfUtf8);
  MSF_WIDGET_RELEASE(strHdl);
  str[l] = '\0';
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, str);
  SEC_FREE(str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n\n");

  /* subject */
  text = widget_ucs2str_append_id(MSF_MODID_SEC, text, &text_size, SEC_STR_ID_SUBJECT);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n");
  strHdl = sec_tiGetIssuerStrHdl(subjectCharSet, subject, subjectLen, 0);
  if(strHdl == 0)
    goto show_cert_error;
  l = MSF_WIDGET_STRING_GET_LENGTH(strHdl, 1, MsfUtf8);
  str = (kal_uint8*)SEC_ALLOC(l+1);
  MSF_WIDGET_STRING_GET_DATA (strHdl, (char*)str, MsfUtf8);
  MSF_WIDGET_RELEASE(strHdl);
  str[l] = '\0';
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, str);
  SEC_FREE(str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n\n");

  /* validNotBefore */
  text = widget_ucs2str_append_id(MSF_MODID_SEC, text, &text_size, SEC_STR_ID_VAL_NOT_BEF);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n");
  str = (kal_uint8*)SEC_ALLOC(32);
  sec_tiCvtTimeToStr(validNotBefore, (char**)&str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, str);
  SEC_FREE(str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n\n");

  /* validNotAfter */
  text = widget_ucs2str_append_id(MSF_MODID_SEC, text, &text_size, SEC_STR_ID_VAL_NOT_AFT);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n");
  str = (kal_uint8*)SEC_ALLOC(32);
  sec_tiCvtTimeToStr(validNotAfter, (char**)&str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, str);
  SEC_FREE(str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n\n");

  /* fingerprint */
  text = widget_ucs2str_append_id(MSF_MODID_SEC, text, &text_size, SEC_STR_ID_FINGERPRINT);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n");
  str = (kal_uint8*)SEC_ALLOC(fingerprintLen*3+2);

  /* Convert fingerprint */
  p2 = (char*)str;
  for (i=0; i<fingerprintLen; i++)
  {
    msf_cmmn_byte2hex (*p1, p2);
    p1++;
    p2 += 2;
    *p2 = ' ';
    p2++;
  }
  p2--;
  *p2 = '\0';
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, str);
  SEC_FREE(str);
  text = widget_ucs2str_append_utf8(MSF_MODID_SEC, text, &text_size, (kal_uint8*)"\n");

  /* Create widow */
  certFormHdl = HDIa_widgetExtCreateTextView(MSF_MODID_SEC, text, SEC_STR_ID_SHOW_CERT_TITLE, 0); 
  dlg->handle[SEC_TI_FORM_HANDLE] = certFormHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = certFormOk;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE] = certFormDel;
  SEC_FREE(text); // release the text
  
  /* Set Key */
  scrid = HDIa_widgetCtkGetScreenHandle(certFormHdl);
#ifdef __MMI_KLG__
  ctk_screen_addRSK_UA(scrid, BRA_STR_ID_BACK, 0, NULL, sec_tiSendWidgetActionOk, KAL_TRUE);
#else
  if(cancelStr != SEC_STR_ID_EMPTY)
  {
    ctk_screen_addRSK_UA(scrid, (ctk_string_id)cancelStr, 0, NULL, sec_tiSendWidgetActionDel, KAL_TRUE);
  }
  ctk_screen_addLSK_UA(scrid, SEC_STR_ID_OK, 0, NULL, sec_tiSendWidgetActionOk, KAL_TRUE);
#endif  

#ifdef WAP_SUPPORT
  win = SEC_ALLOCTYPE(sec_win_t);
  win->win_hdl = dlg->handle[SEC_TI_DIALOG_HANDLE];
  win->dlg = dlg;
  bra_win_show_window (BRA_WIN_ID_SEC_DLG, 
                    (bra_win_t*)win,
                    &nullPos, 
                    sec_myTiDelete, 
                    NULL,
                    NULL);
#else  
  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], certFormHdl, &nullPos, 0, 0);

  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }
#endif  
  return dlg;

show_cert_error:
  SEC_FREE(text);
  return NULL;
}

#else
sec_ti_t *
sec_tiCreateShowCertDlg(MSF_UINT32 screenHandle, MSF_INT16 issuerCharSet, 
                      void *issuer, int issuerLen,
                      MSF_UINT32 validNotBefore, 
                      MSF_UINT32 validNotAfter, 
                      MSF_INT16 subjectCharSet, 
                      void *subject, int subjectLen,
                      unsigned char *fingerprint, int fingerprintLen,
                      int cancelStr)
{
  MsfStringHandle formTitle;
  MsfPosition	stringPos;
#ifdef WAP_SUPPORT
  MsfSize stringSize = {20,75};
#else
  MsfSize stringSize = {40,200};
#endif
  MsfWindowHandle formHdl = 0;
  MsfActionHandle ok_action = 0;
  MsfActionHandle cancel_action = 0;
  MsfGadgetHandle issuerGadgetStr = 0;
  MsfGadgetHandle subjectGadgetStr = 0;
  MsfGadgetHandle validNotBefGadgetStr = 0;
  MsfGadgetHandle validNotAftGadgetStr = 0;
  MsfGadgetHandle fingerprGadgetStr = 0;
#ifdef WAP_SUPPORT
  MsfGadgetHandle issuerTitleGadgetStr = 0;
  MsfGadgetHandle subjectTitleGadgetStr = 0;
  MsfGadgetHandle validNotBefTitleGadgetStr = 0;
  MsfGadgetHandle validNotAftTitleGadgetStr = 0;
  MsfGadgetHandle fingerprTitleGadgetStr = 0;
#endif
  MsfPosition	nullPos = {0,0};
#ifdef WAP_SUPPORT
  int num_handles = 9+5; /*Minimum to this dialog*/
#else
  int num_handles = 9; /*Minimum to this dialog*/
#endif
  sec_ti_t *dlg = NULL;
  
  if (cancelStr == SEC_STR_ID_DELETE)
    dlg = sec_dlg_create (screenHandle, SEC_TI_SHOW_CERT_DLG, num_handles);
  else
    dlg = sec_dlg_create (screenHandle, SEC_TI_SHOW_VERIFIED_CERT_DLG, num_handles);

  formTitle = SEC_GET_STR_ID(SEC_STR_ID_SHOW_CERT_TITLE);

  if ((formHdl = sec_tiCreateForm(formTitle)) == 0)
    goto show_cert_error;

  /* Action MsfOk */
	if ((ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(SEC_STR_ID_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto show_cert_error;

  MSF_WIDGET_ADD_ACTION(formHdl, ok_action);
  
  /* Action MsfCancel */
	if ((cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(cancelStr), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto show_cert_error;

	MSF_WIDGET_ADD_ACTION(formHdl, cancel_action);

  /* Create gadget strings */
  stringPos.x = SEC_FIRST_X_POS;
	stringPos.y = SEC_FIRST_Y_POS;
#ifdef WAP_SUPPORT
  issuerTitleGadgetStr = sec_tiCreateStringGadget(formHdl, 
                                          SEC_GET_STR_ID(SEC_STR_ID_ISSUER), 
                                          stringPos, 
                                          &stringSize, 0);

  (stringPos).y = (MSF_INT16)((stringPos).y + stringSize.height + 5);

  issuerGadgetStr = sec_tiCreateIssuerGadget(formHdl, 
                                          issuerCharSet, issuer, issuerLen, 
                                          0,
                                          &stringPos, stringSize);
#else  
  issuerGadgetStr = sec_tiCreateIssuerGadget(formHdl, 
                                          issuerCharSet, issuer, issuerLen, 
                                          SEC_GET_STR_ID(SEC_STR_ID_ISSUER),
                                          &stringPos, stringSize);
#endif
  if (issuerGadgetStr == 0)
    goto show_cert_error;
#ifdef WAP_SUPPORT
  subjectTitleGadgetStr = sec_tiCreateStringGadget(formHdl, 
                                          SEC_GET_STR_ID(SEC_STR_ID_SUBJECT),
                                          stringPos, 
                                          &stringSize, 0);

  (stringPos).y = (MSF_INT16)((stringPos).y + stringSize.height + 5);

  subjectGadgetStr = sec_tiCreateIssuerGadget(formHdl, 
                                        subjectCharSet, subject, subjectLen, 
                                        0,
                                        &stringPos, stringSize);
#else
  subjectGadgetStr = sec_tiCreateIssuerGadget(formHdl, 
                                        subjectCharSet, subject, subjectLen, 
                                        SEC_GET_STR_ID(SEC_STR_ID_SUBJECT),
                                        &stringPos, stringSize);
#endif
  if (subjectGadgetStr == 0)
    goto show_cert_error;
#ifdef WAP_SUPPORT
  validNotBefTitleGadgetStr = sec_tiCreateStringGadget(formHdl, 
                                          SEC_GET_STR_ID(SEC_STR_ID_VAL_NOT_BEF),
                                          stringPos, 
                                          &stringSize, 0);

  (stringPos).y = (MSF_INT16)((stringPos).y + stringSize.height + 5);

  validNotBefGadgetStr = sec_tiCreateValidDateGadget(formHdl, 
                                              validNotBefore, 
                                              0,
                                              &stringPos, stringSize);
#else
  validNotBefGadgetStr = sec_tiCreateValidDateGadget(formHdl, 
                                              validNotBefore, 
                                              SEC_GET_STR_ID(SEC_STR_ID_VAL_NOT_BEF),
                                              &stringPos, stringSize);
#endif
  if (validNotBefGadgetStr == 0)
    goto show_cert_error;
#ifdef WAP_SUPPORT
  validNotAftTitleGadgetStr = sec_tiCreateStringGadget(formHdl, 
                                          SEC_GET_STR_ID(SEC_STR_ID_VAL_NOT_AFT),
                                          stringPos, 
                                          &stringSize, 0);

  (stringPos).y = (MSF_INT16)((stringPos).y + stringSize.height + 5);

  validNotAftGadgetStr = sec_tiCreateValidDateGadget(formHdl, 
                                                    validNotAfter, 
                                                    0,
                                                   &stringPos, stringSize);
#else
  validNotAftGadgetStr = sec_tiCreateValidDateGadget(formHdl, 
                                                    validNotAfter, 
                                                    SEC_GET_STR_ID(SEC_STR_ID_VAL_NOT_AFT),
                                                   &stringPos, stringSize);
#endif
  if (validNotAftGadgetStr == 0)
    goto show_cert_error;
#ifdef WAP_SUPPORT
  fingerprTitleGadgetStr = sec_tiCreateStringGadget(formHdl, 
                                          SEC_GET_STR_ID(SEC_STR_ID_FINGERPRINT),
                                          stringPos, 
                                          &stringSize, 0);

  (stringPos).y = (MSF_INT16)((stringPos).y + stringSize.height + 5);

  fingerprGadgetStr = sec_tiCreateFingerprGadget(formHdl, 
                                                fingerprint, 
                                                fingerprintLen, 
                                                &stringPos, stringSize);
#else
  fingerprGadgetStr = sec_tiCreateFingerprGadget(formHdl, 
                                                fingerprint, 
                                                fingerprintLen, 
                                                &stringPos, stringSize);
#endif
  if (fingerprGadgetStr == 0)
    goto show_cert_error;

    MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], formHdl, 
                               &nullPos, 0, 0);
  dlg->handle[SEC_TI_FORM_HANDLE] = formHdl;
  dlg->handle[SEC_TI_FINGERPRINT_GADGET_STR_HANDLE] = fingerprGadgetStr;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
  dlg->handle[SEC_TI_ISSUER_GADGET_STR_HANDLE] = issuerGadgetStr;
	dlg->handle[SEC_TI_SUBJECT_GADGET_STR_HANDLE] = subjectGadgetStr;
	dlg->handle[SEC_TI_VALID_NOT_BEF_GADGET_STR_HANDLE] = validNotBefGadgetStr;
	dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE] = validNotAftGadgetStr;
#ifdef WAP_SUPPORT
  dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE+1] = issuerTitleGadgetStr;
  dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE+2] = subjectTitleGadgetStr;
  dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE+3] = validNotBefTitleGadgetStr;
  dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE+4] = validNotAftTitleGadgetStr;
  dlg->handle[SEC_TI_VALID_NOT_AFT_GADGET_STR_HANDLE+5] = fingerprTitleGadgetStr;
#endif
  
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }
  
  return dlg;

show_cert_error:
  if (formHdl != 0)
    MSF_WIDGET_RELEASE(formHdl);
  if (ok_action != 0)
    MSF_WIDGET_RELEASE(ok_action);
  if (cancel_action != 0)
    MSF_WIDGET_RELEASE(cancel_action);
  if (subjectGadgetStr != 0)
    MSF_WIDGET_RELEASE(subjectGadgetStr);
  if (issuerGadgetStr != 0)
    MSF_WIDGET_RELEASE(issuerGadgetStr);
  if (validNotBefGadgetStr != 0)
    MSF_WIDGET_RELEASE(validNotBefGadgetStr);
  if (validNotAftGadgetStr != 0)
    MSF_WIDGET_RELEASE(validNotAftGadgetStr);
  return NULL;
}
#endif /* WAP_SUPPORT */
#endif /*SEC_CFG_USE_CERT*/

#ifdef SEC_CFG_USE_KEYS
/* 
 * Create a PIN form with one string gadget, one input gadget
 * and two actions in it. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateGenPinDlg(MSF_UINT32 screenHandle, MSF_UINT8 keyType, int reason)
{
  MsfStringHandle formTitle;
  MsfStringHandle textStr;
  MsfPosition	stringPos;
  MsfWindowHandle formHdl;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  MsfGadgetHandle pinGadgetStr;
  MsfGadgetHandle textInputGadget;
  MsfPosition	nullPos = {0,0};
  int num_handles = 6; /*Minimum to this dialog*/
  sec_ti_t *dlg = NULL;
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_GENERATE_PIN_DLG, num_handles);

  formTitle = SEC_GET_STR_ID(SEC_STR_ID_GEN_PIN_TITLE);

  switch (reason)
  {
    case 0:
      /* First time dialog is shown */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_GEN_PIN);
      break;
    case SEC_INPUT_TOO_LONG:
      /* Shown again because too long a PIN was entered */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_TOO_LONG); 
      break;
    case SEC_INPUT_TOO_SHORT:
      /* Shown again because too short a PIN was entered */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_TOO_SHORT);
      break;
    default:
      textStr = SEC_GET_STR_ID(SEC_STR_ID_GEN_PIN);
      break;
  }

  /* Create PIN form with textStr, one input field and actions */
  if (sec_tiCreatePinForm(&formHdl, &ok_action, &cancel_action, &pinGadgetStr,
                          &textInputGadget, keyType, formTitle, 
                          textStr, &stringPos) != SEC_ERR_OK)
    return NULL;

  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], formHdl, 
                               &nullPos, 0, 0);
  dlg->handle[SEC_TI_FORM_HANDLE] = formHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
  dlg->handle[SEC_TI_PIN_GADGET_STR_HANDLE] = pinGadgetStr;
  dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_1_HANDLE] = textInputGadget;
  
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }
  
  return dlg; 
}

/* 
 * Create a PIN form with three string gadgets, three input gadgets,
 * and two actions in it. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateChangePinDlg(MSF_UINT32 screenHandle, MSF_UINT8 keyType, int reason)
{
  MsfStringHandle formTitle;
  MsfStringHandle newPinStr1;
  MsfStringHandle newPinStr2;
  MsfStringHandle newPinStr3;
  MsfPosition	stringPos;
  MsfTextType textInputType;
  MsfWindowHandle formHdl;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  MsfGadgetHandle pinGadgetStr;
  MsfGadgetHandle textInputGadget;
  MsfGadgetHandle pinGadgetStr2;
  MsfGadgetHandle textInputGadget2;
  MsfGadgetHandle pinGadgetStr3;
  MsfGadgetHandle textInputGadget3;
  MsfPosition	nullPos = {0,0};
  int num_handles = 10; /*Minimum to this dialog*/
  sec_ti_t *dlg = NULL;
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_CHANGE_PIN_DLG, num_handles);

  formTitle = SEC_GET_STR_ID(SEC_STR_ID_CHANGE_PIN_TITLE);

  switch (reason)
  {
    case 0:
      /* First time dialog is shown */
      newPinStr1 = SEC_GET_STR_ID(SEC_STR_ID_CHANGE_PIN_NEW);
      break;
    case SEC_INPUT_MISMATCH:
      /* Shown again because first and second new PIN not the same */
      newPinStr1 = SEC_GET_STR_ID(SEC_STR_ID_PIN_MISMATCH);
      break;
    case SEC_INPUT_TOO_LONG:
      /* Shown again because too long a PIN was entered */
      newPinStr1 = SEC_GET_STR_ID(SEC_STR_ID_PIN_TOO_LONG); 
      break;
    case SEC_INPUT_TOO_SHORT:
      /* Shown again because too short a PIN was entered */
      newPinStr1 = SEC_GET_STR_ID(SEC_STR_ID_PIN_TOO_SHORT);
      break;
    case SEC_INPUT_FALSE:
      /* Shown again because the wrong PIN was entered */
      newPinStr1 = SEC_GET_STR_ID(SEC_STR_ID_WRONG_OLD_PIN);
      break;
    case SEC_INPUT_ERROR:
      /* Shown again because some error occured */
      newPinStr1 = SEC_GET_STR_ID(SEC_STR_ID_INPUT_ERROR);
      break;
    default :
      newPinStr1 = SEC_GET_STR_ID(SEC_STR_ID_CHANGE_PIN_NEW);
      break;
  }

	stringPos.x = SEC_FIRST_X_POS;
	stringPos.y = SEC_FIRST_Y_POS;

  /* Create PIN form with newPinStr1, one input field and actions */
  if (sec_tiCreatePinForm(&formHdl, &ok_action, &cancel_action, &pinGadgetStr,
                          &textInputGadget, keyType, formTitle,
                          newPinStr1, &stringPos) != SEC_ERR_OK)
    return NULL;

  /* Create newPinStr2 and one more input field in the form */
  newPinStr2 = SEC_GET_STR_ID(SEC_STR_ID_CHANGE_PIN_NEW2);
  textInputType = MsfPasswordText;
  if (sec_tiCreateTextAndInput(formHdl, 
                               &pinGadgetStr2,
                               newPinStr2, &textInputGadget2,
                               &stringPos, SEC_PIN_MAX_SIZE, 
                               textInputType) != SEC_ERR_OK)
  {
    MSF_WIDGET_RELEASE(formHdl);
    MSF_WIDGET_RELEASE(ok_action);
    MSF_WIDGET_RELEASE(cancel_action);
    MSF_WIDGET_RELEASE(pinGadgetStr);
    MSF_WIDGET_RELEASE(textInputGadget);
    return NULL;
  }

  /* Create newPinStr3 and one more input field in the form */
  newPinStr3 = SEC_GET_STR_ID(SEC_STR_ID_CHANGE_PIN_OLD);
  if (sec_tiCreateTextAndInput(formHdl, 
                               &pinGadgetStr3,
                               newPinStr3, &textInputGadget3,
                               &stringPos, SEC_PIN_MAX_SIZE, 
                               textInputType) != SEC_ERR_OK)
  {
    MSF_WIDGET_RELEASE(formHdl);
    MSF_WIDGET_RELEASE(ok_action);
    MSF_WIDGET_RELEASE(cancel_action);
    MSF_WIDGET_RELEASE(pinGadgetStr);
    MSF_WIDGET_RELEASE(textInputGadget);
    MSF_WIDGET_RELEASE(pinGadgetStr2);
    MSF_WIDGET_RELEASE(textInputGadget2);
    return NULL;
  }
  
  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], formHdl, 
                               &nullPos, 0, 0);
  dlg->handle[SEC_TI_FORM_HANDLE] = formHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
  dlg->handle[SEC_TI_PIN_GADGET_STR_HANDLE] = pinGadgetStr;
  dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_1_HANDLE] = textInputGadget;
  dlg->handle[SEC_TI_PIN_GADGET_STR_2_HANDLE] = pinGadgetStr2;
  dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_2_HANDLE] = textInputGadget2;
  dlg->handle[SEC_TI_PIN_GADGET_STR_3_HANDLE] = pinGadgetStr3;
  dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_3_HANDLE] = textInputGadget3;
  
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }
  
  return dlg;
}

/* 
 * Create a PIN form with one string gadget, one input gadget,
 * and two actions in it. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreatePinDlg(MSF_UINT32 screenHandle, sec_pin_cause_t pinCause, int reason)
{
  MsfStringHandle formTitle;
  MsfStringHandle textStr;
  MsfPosition	stringPos;
  MSF_UINT8 pinType;
  MsfWindowHandle formHdl;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  MsfGadgetHandle pinGadgetStr;
  MsfGadgetHandle textInputGadget;
  MsfPosition	nullPos = {0,0};
  int num_handles = 6; /*Minimum to this dialog*/
  sec_ti_t *dlg = NULL;
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_PIN_DLG, num_handles);

  formTitle = SEC_GET_STR_ID(SEC_STR_ID_PIN_DIALOG_TITLE);

  switch (reason)
  {
    case 0:
      /* First time dialog is shown */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_DIALOG);
      break;
    case SEC_INPUT_TOO_LONG:
    case SEC_INPUT_TOO_SHORT:
    case SEC_INPUT_FALSE:
      /* Shown again because the wrong PIN was entered */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_WRONG_PIN);
      break;
    case SEC_INPUT_ERROR:
      /* Shown again because an error occured */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_INPUT_ERROR);
      break;
    default:
      textStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_DIALOG);
      break;
  }
  switch (pinCause)
  {
    case SEC_PIN_OPEN_WIM:
      pinType = SEC_TI_PIN_OPEN_WIM;
      break;
    case SEC_PIN_CONNECT:
      pinType = SEC_TI_PIN_CONNECT;
      break;
    case SEC_PIN_SIGN_TEXT:
      pinType = SEC_TI_PIN_SIGN_TEXT;
      break;
    case SEC_PIN_STORE_CERT:
      pinType = SEC_TI_PIN_STORE_CERT;
      break;
    case SEC_PIN_DELETE_CERT:
      pinType = SEC_TI_PIN_DEL_CERT;
      break;
    case SEC_PIN_GENERATE_AUTH_KEY:
      pinType = SEC_TI_PIN_GEN_AUT_KEY;
      break;
    case SEC_PIN_GENERATE_NONREP_KEY:
      pinType = SEC_TI_PIN_GEN_NR_KEY;
      break;
    case SEC_PIN_PUK:
      pinType = SEC_TI_PIN_PUK;
      break;
    default:
      return NULL;
  }
  
  /* Create PIN form with textStr, one input field and actions */
  if (sec_tiCreatePinForm(&formHdl, &ok_action, &cancel_action, &pinGadgetStr,
                          &textInputGadget, pinType, formTitle,
                          textStr, &stringPos) != SEC_ERR_OK)
  return NULL;
  
  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], formHdl, 
                               &nullPos, 0, 0);
  dlg->handle[SEC_TI_FORM_HANDLE] = formHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
  dlg->handle[SEC_TI_PIN_GADGET_STR_HANDLE] = pinGadgetStr;
  dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_1_HANDLE] = textInputGadget;
  
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }  
  return dlg;
}

#ifdef SEC_CFG_DELETE_KEY_VER
/* 
 * Create a PUK form with one string gadget, one input gadget,
 * and two actions in it. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateAllowDelDlg(MSF_UINT32 screenHandle, MSF_UINT8 keyType, int reason)
{
  MsfStringHandle formTitle;
  MsfStringHandle textStr;
  MsfPosition	stringPos;
  MSF_UINT8 pinType;
  MsfWindowHandle formHdl;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  MsfGadgetHandle pinGadgetStr;
  MsfGadgetHandle textInputGadget;
  MsfPosition	nullPos = {0,0};
  int num_handles = 6; /*Minimum to this dialog*/
  sec_ti_t *dlg = NULL;
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_ALLOW_DEL_KEYS_DLG, num_handles);

  formTitle = SEC_GET_STR_ID(SEC_STR_ID_ALLOW_DEL_TITLE);

  switch (reason)
  {
    case 0:
      /* First time dialog is shown */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_DIALOG);
      break;
    case SEC_INPUT_TOO_LONG:
    case SEC_INPUT_TOO_SHORT:
    case SEC_INPUT_FALSE:
      /* Shown again because the wrong PUK was entered */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_WRONG_PIN);
      break;

    case SEC_INPUT_ERROR:
      /* Shown again because an error occured */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_INPUT_ERROR);
      break;

    default:
      textStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_DIALOG);
      break;
  }
  if (keyType == SEC_AUTHENTICATION_KEY)
    pinType = SEC_TI_PIN_ALLOW_DEL_AUT_KEY;
  else
    pinType = SEC_TI_PIN_ALLOW_DEL_NR_KEY;

  /* Create PIN form with textStr, one input field and actions */
  if (sec_tiCreatePinForm(&formHdl, &ok_action, &cancel_action, &pinGadgetStr,
                          &textInputGadget, pinType, formTitle, 
                          textStr, &stringPos) != SEC_ERR_OK)
    return NULL;

  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], formHdl, 
                               &nullPos, 0, 0);
  dlg->handle[SEC_TI_FORM_HANDLE] = formHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
  dlg->handle[SEC_TI_PIN_GADGET_STR_HANDLE] = pinGadgetStr;
  dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_1_HANDLE] = textInputGadget;
  
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }
  
  return dlg; 

}
#endif
#else
sec_ti_t *
sec_tiCreateGenPinDlg(MSF_UINT32 screenHandle, MSF_UINT8 keyType, int reason)
{
   return NULL;
}

sec_ti_t *
sec_tiCreateChangePinDlg(MSF_UINT32 screenHandle, MSF_UINT8 keyType, int reason)
{
   return NULL;
}

sec_ti_t *
sec_tiCreatePinDlg(MSF_UINT32 screenHandle, sec_pin_cause_t pinCause, int reason)
{
   return NULL;
}

sec_ti_t *
sec_tiCreateAllowDelDlg(MSF_UINT32 screenHandle, MSF_UINT8 keyType, int reason)
{
   return NULL;
}
#endif

#ifdef SEC_CFG_USE_CERT
/* 
 * Create a hash form with the supplied display name. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateHashDlg(MSF_UINT32 screenHandle, MSF_INT16 charSet, 
                  void *displayName, int displayNameLen, int reason)
{
  MsfStringHandle formTitle;
  MsfStringHandle textStr;
  MsfStringHandle hashStr;
  MsfPosition	stringPos;
  MsfSize stringSize = {60,220};
  MsfSize textInputSize = {20,220};
  char *tmpStr, *tmpName;
  int tmp_len;
  long tmpNameLen = displayNameLen + 3;
  int result;
  MsfTextType textInputType;
  MsfWindowHandle formHdl;
  MsfActionHandle ok_action;
  MsfActionHandle cancel_action;
  char *tmp_displayName;
  MsfGadgetHandle hashGadgetStr;
  MsfGadgetHandle textInputGadget;
  MsfPosition	nullPos = {0,0};
  int num_handles = 5; /*Minimum to this dialog*/
  sec_ti_t *dlg = NULL;
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_HASH_DLG, num_handles);

  ok_action = 0;
  cancel_action = 0;
  

  formTitle = SEC_GET_STR_ID(SEC_STR_ID_HASH_TITLE);

  /* Convert displayName to MsfStringHandle */
  tmp_displayName = (char *)SEC_ALLOC(2*displayNameLen+3);
  tmpName  = (char *)SEC_ALLOC(2*displayNameLen+3);
  result = sec_tiCvtToUtf8((unsigned char *)displayName, displayNameLen, 
                           tmpName, &tmpNameLen, charSet);
  strcpy(tmp_displayName, tmpName);
  SEC_FREE(tmpName);

  switch (reason)
  {
    case 0:
      /* First time dialog is shown */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_ENTER_HASH);
      break;
    case SEC_INPUT_TOO_SHORT:
    case SEC_INPUT_FALSE:
      /* Show again because the wrong hash was entered */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_WRONG_HASH);
      break;
    case SEC_INPUT_ERROR:
      /* Show again because some error occured */
      textStr = SEC_GET_STR_ID(SEC_STR_ID_INPUT_ERROR);
      break;
    default :
      textStr = SEC_GET_STR_ID(SEC_STR_ID_ENTER_HASH);
      break;
  }

  tmpStr  = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                              textStr,0,MsfUtf8)*displayNameLen+3);
  if (!tmpStr)
    return NULL;

  MSF_WIDGET_STRING_GET_DATA(textStr, tmpStr, MsfUtf8);
  
  tmp_len = MSF_WIDGET_STRING_GET_LENGTH(textStr,0,MsfUtf8);
  tmpStr[tmp_len] = '\0';
  strcat (tmpStr, tmp_displayName);
  SEC_FREE(tmp_displayName);

  hashStr = SEC_STRCONV(tmpStr);
  SEC_FREE(tmpStr);

  if ((formHdl = sec_tiCreateForm(formTitle)) == 0)
    goto hash_error;

  /* Action MsfOk */
	if ((ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(SEC_STR_ID_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto hash_error;

	MSF_WIDGET_ADD_ACTION(formHdl, ok_action);

  /* Action MsfCancel */
	if ((cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(SEC_STR_ID_CANCEL), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto hash_error;

	MSF_WIDGET_ADD_ACTION(formHdl, cancel_action);

  /* String Gadget hashStr */
	stringPos.x = SEC_FIRST_X_POS;
	stringPos.y = SEC_FIRST_Y_POS;
  hashGadgetStr = sec_tiCreateStringGadget(formHdl, hashStr, stringPos, 
                                           &stringSize, 0);
  if (hashGadgetStr == 0)
    goto hash_error;
	
	/* Text input Gadget */
	stringPos.y = (MSF_INT16)(stringPos.y + stringSize.height + 5);
  textInputType = MsfText;
  textInputGadget = sec_tiCreateTextInputGadget(formHdl, stringPos, 
                                        &textInputSize, SEC_MAX_INPUT_LEN,
                                        textInputType);
  if (textInputGadget == 0)
    goto hash_error;
  
  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], formHdl, 
                               &nullPos, 0, 0);
  
  dlg->handle[SEC_TI_FORM_HANDLE] = formHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
  dlg->handle[SEC_TI_HASH_GADGET_STR_HANDLE] = hashGadgetStr;
  dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_1_HANDLE] = textInputGadget;
  
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }  
  return dlg;

hash_error:
  if (tmp_displayName)
    SEC_FREE(tmp_displayName);
  if (formHdl != 0)
    MSF_WIDGET_RELEASE(formHdl);
  if (ok_action != 0)
    MSF_WIDGET_RELEASE(ok_action);
  if (cancel_action != 0)
    MSF_WIDGET_RELEASE(cancel_action);
  return NULL;
}
#endif

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
/* 
 * Create a menu with the supplied contracts and signing times. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateStoredContractsDlg(MSF_UINT32 screenHandle, int nbrContracts, 
                                sec_contract_info_t *contractVec)
{
MsfStringHandle menuTitle;
  char *contractTimeStr = NULL;
  MsfStringHandle *contractTime;
  int i;
  int strSize;
  MsfWindowHandle menuHdl;
  char *timeStr;
	MsfActionHandle ok_action;
	MsfActionHandle cancel_action;
  MsfPosition	nullPos = {0,0};
	sec_ti_t *dlg;
  int num_handles = 4; 
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_STORED_CONTRACTS_DLG, num_handles);

  menuTitle = SEC_GET_STR_ID(SEC_STR_ID_STORED_CONTRACTS_TITLE);

  /* Create contract and time string */
  contractTime = (MsfStringHandle *)SEC_ALLOC(nbrContracts*sizeof(MsfStringHandle));
  for (i=0; i<nbrContracts; i++)
  {
    contractTimeStr = (char *)SEC_ALLOC((SEC_CHARS_TO_SHOW_IN_CERT+25));
    strSize = sizeof(contractVec[i].contract);
    if (strSize > SEC_CHARS_TO_SHOW_IN_CERT)
      strSize = SEC_CHARS_TO_SHOW_IN_CERT;
    strcpy(contractTimeStr, contractVec[i].contract);
    contractTimeStr[strSize] = ' ';
    
    /* Add time string */
    timeStr = (char *)SEC_ALLOC(20);
    sec_tiCvtTimeToStr(contractVec[i].time, &timeStr);
    contractTime[i] = SEC_STRCONV(timeStr);
    SEC_FREE(timeStr);
    SEC_FREE(contractTimeStr);
  }
  
  if ((menuHdl = sec_tiCreateMenu(menuTitle)) == 0)
  {
    SEC_FREE(contractTime);
    return NULL;
  }
	
	ti_nbrOfCerts = nbrContracts;
  if (nbrContracts > 0)
  {
    ti_index = (int *)SEC_ALLOC((nbrContracts*sizeof(int))+sizeof(int));
		ti_index[0] = 0;
  }
  else 
    ti_index = NULL;
  
  /* Insert elements */
  for (i=0; i<nbrContracts; i++)
    ti_index[i] = MSF_WIDGET_CHOICE_SET_ELEMENT(menuHdl, i, 
                                    contractTime[i], 
                                    SEC_GET_STR_ID(SEC_STR_ID_EMPTY), 0, 0, 1);

  /* Action MsfOk */
	if ((ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
                                          SEC_GET_STR_ID(SEC_STR_ID_VIEW), 
                                          MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
  {
    SEC_FREE(contractTime);
    MSF_WIDGET_RELEASE(menuHdl);
    return NULL;
  }

	MSF_WIDGET_ADD_ACTION(menuHdl, ok_action);

  /* Action MsfCancel */
	if ((cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
                                              SEC_GET_STR_ID(SEC_STR_ID_CANCEL), 
                                              MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
  {
    SEC_FREE(contractTime);
    MSF_WIDGET_RELEASE(menuHdl);
    MSF_WIDGET_RELEASE(ok_action);
    return NULL;
  }

	MSF_WIDGET_ADD_ACTION(menuHdl, cancel_action);

  SEC_FREE(contractTime);

	dlg->handle[SEC_TI_MENU_HANDLE] = menuHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE] = cancel_action;

  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], menuHdl, 
                               &nullPos, 0, 0);
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_MENU_HANDLE], 1);
  }  
  return dlg;

  return SEC_ERR_OK;
}
/*
 * This function displays the contract with the supplied index, 
 * the signature of the contract, and the time it was signed.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateShowContractDlg(MSF_UINT32 screenHandle, sec_contract_info_t chosen_contract/*int indexPos*/)
{
 MsfStringHandle formTitle;
  MsfStringHandle contract;
  MsfStringHandle timeStr;
  MsfStringHandle signature;
  MsfPosition	stringPos;
  MsfSize stringSize = {60,200};
  char *tmpStr;
  char *tmp_timeStr = NULL;
	MsfActionHandle ok_action;
	MsfActionHandle cancel_action;
  MsfWindowHandle formHdl;
  MsfGadgetHandle contractGadgetStr;
  MsfGadgetHandle timeGadgetStr;
  MsfGadgetHandle sigGadgetStr;
  MsfPosition	nullPos = {0,0};
	sec_ti_t *dlg;
  int num_handles = 6; 
  
  dlg = sec_dlg_create (screenHandle, SEC_TI_SHOW_STORED_CONTRACT_DLG, num_handles);

  formHdl = 0;
  ok_action = 0;
  cancel_action = 0;
  contractGadgetStr = 0;
  timeGadgetStr = 0;
  sigGadgetStr = 0;

  formTitle = SEC_GET_STR_ID(SEC_STR_ID_SHOW_CONTRACTS_TITLE);
  
  if ((formHdl = sec_tiCreateForm(formTitle)) == 0)
    return NULL;

  /* Action MsfOk */
	if ((ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(SEC_STR_ID_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto contract_menu_error;

	MSF_WIDGET_ADD_ACTION(formHdl, ok_action);

  /* Action MsfCancel för delete */
	if ((cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
       SEC_GET_STR_ID(SEC_STR_ID_DELETE), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto contract_menu_error;

	MSF_WIDGET_ADD_ACTION(formHdl, cancel_action);

  /* String Gadget contracts_menu.contracts[indexPos] */
  tmpStr = (char *)SEC_ALLOC((MSF_WIDGET_STRING_GET_LENGTH(
                             SEC_GET_STR_ID(SEC_STR_ID_CONTRACT),0,MsfUtf8)+strlen(
                             chosen_contract.contract))+2);

  if (!tmpStr)
    goto contract_menu_error;

  MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(SEC_STR_ID_CONTRACT), tmpStr, MsfUtf8);
  
  strcat (tmpStr, chosen_contract.contract);
  contract = SEC_STRCONV(tmpStr);
  
  SEC_FREE(tmpStr);

	stringPos.x = SEC_FIRST_X_POS;
	stringPos.y = SEC_FIRST_Y_POS;

  contractGadgetStr = sec_tiCreateStringGadget(formHdl, 
                                              contract, stringPos, 
                                              &stringSize, 0);
  if (contractGadgetStr == 0)
    goto contract_menu_error;
	
  /* Add time string */
  tmp_timeStr = (char *)SEC_ALLOC(20);
  sec_tiCvtTimeToStr(chosen_contract.time, &tmp_timeStr);

  /* String Gadget contracts_menu.timeStr[indexPos] */
  tmpStr = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                             SEC_GET_STR_ID(SEC_STR_ID_TIME),0,MsfUtf8)+25);
  if (!tmpStr)
    goto contract_menu_error;

  MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(SEC_STR_ID_TIME), tmpStr, MsfUtf8);
  
  strcat (tmpStr, tmp_timeStr);
  timeStr = SEC_STRCONV(tmpStr);
  
  SEC_FREE(tmpStr);
  SEC_FREE(tmp_timeStr);

	stringPos.y = (MSF_INT16)(stringPos.y + stringSize.height + 5);
  stringSize.height = 20;
  stringSize.width = 200;
  
  timeGadgetStr = sec_tiCreateStringGadget(formHdl, timeStr, 
                                           stringPos, &stringSize, 1);
  if (timeGadgetStr == 0)
    goto contract_menu_error;
   
  /* String Gadget contracts_menu.signatures[indexPos] */
  tmpStr = (char *)SEC_ALLOC((MSF_WIDGET_STRING_GET_LENGTH(
                             SEC_GET_STR_ID(SEC_STR_ID_SIGNATURE),0,MsfUtf8)+
                             chosen_contract.signatureLen)+2);
  if (!tmpStr)
    goto contract_menu_error;
  
  MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(SEC_STR_ID_SIGNATURE), tmpStr, MsfUtf8);

  strcat (tmpStr, chosen_contract.signature);
  signature = SEC_STRCONV(tmpStr);

  SEC_FREE(tmpStr);

	stringPos.y = (MSF_INT16)(stringPos.y + stringSize.height + 5);
  stringSize.height = 60;
  stringSize.width = 200;

  sigGadgetStr = sec_tiCreateStringGadget(formHdl, 
                                          signature, stringPos, 
                                          &stringSize, 0);
  if (sigGadgetStr == 0)
    goto contract_menu_error;

  MSF_WIDGET_RELEASE(contract);
  MSF_WIDGET_RELEASE(timeStr);
  MSF_WIDGET_RELEASE(signature);

  MSF_WIDGET_SCREEN_ADD_WINDOW(dlg->handle[SEC_TI_SCREEN_HANDLE], formHdl, 
                               &nullPos, 0, 0);
  dlg->handle[SEC_TI_FORM_HANDLE] = formHdl;
  dlg->handle[SEC_TI_OK_ACTION_HANDLE] = ok_action;
  dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE]= cancel_action;
  dlg->handle[SEC_TI_CONTRACT_GADGET_STR_HANDLE] = contractGadgetStr;
  dlg->handle[SEC_TI_TIME_GADGET_STR_HANDLE] = timeGadgetStr;
  dlg->handle[SEC_TI_SIG_GADGET_STR_HANDLE] = sigGadgetStr;
  
  if (dlg != NULL) {
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_SCREEN_HANDLE], 1);
    MSF_WIDGET_SET_IN_FOCUS (dlg->handle[SEC_TI_FORM_HANDLE], 1);
  }  
  return dlg;

contract_menu_error:
  if (formHdl != 0)
    MSF_WIDGET_RELEASE(formHdl);
  if (ok_action!= 0)
    MSF_WIDGET_RELEASE(ok_action);
  if (cancel_action != 0)
    MSF_WIDGET_RELEASE(cancel_action);
  if (contractGadgetStr != 0)
    MSF_WIDGET_RELEASE(contractGadgetStr);
  if (timeGadgetStr != 0)
    MSF_WIDGET_RELEASE(timeGadgetStr);
  return NULL;

}
#endif

#ifdef WAP_SUPPORT
MSF_BOOL sec_ti_closing = FALSE;

static void
sec_myTiDelete (bra_win_t* w)
{
  sec_win_t* win;
  sec_ti_t *dlg;
  extern void sec_handleWidgetAction (msf_widget_action_t *p);
  
  win = (sec_win_t*)w;
  dlg = win->dlg;

  if (dlg->handle[SEC_TI_SCREEN_HANDLE])
  {
    msf_widget_action_t* p = SEC_ALLOCTYPE(msf_widget_action_t);
    p->handle = dlg->handle[SEC_TI_DIALOG_HANDLE];
    if(dlg->type == SEC_TI_SHOW_CERT_DLG
       || dlg->type == SEC_TI_SHOW_VERIFIED_CERT_DLG
#ifdef SEC_CFG_SHOW_WARNINGS
       || dlg->type == SEC_TI_WARNING_DLG
#endif
      )
      p->action = dlg->handle[SEC_TI_OK_ACTION_HANDLE];
    else
      p->action = dlg->handle[SEC_TI_CANCEL_ACTION_HANDLE];
    sec_ti_closing = TRUE;
    sec_handleWidgetAction(p);
  }
  sec_ti_closing = FALSE;
  SEC_FREE(dlg);
  SEC_FREE(win);
}
#endif
/*		
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
sec_tiDelete (sec_ti_t *dlg)
{
  int i;

  if (dlg == NULL)
    return;

#ifdef SEC_CFG_USE_CERT
  if ((dlg->type == SEC_TI_SHOW_CERT_NAMES_DLG)
      #if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
       || (dlg->type == SEC_TI_STORED_CONTRACTS_DLG)
      #endif
#ifdef SEC_CFG_USE_KEYS
       || (dlg->type == SEC_TI_CHOOSE_CERT_BY_NAME_DLG)
      #endif
     )
  {
    for (i=0; i<ti_nbrOfCerts;i++)
      MSF_WIDGET_CHOICE_REMOVE_ELEMENT(dlg->handle[1],ti_index[i]);
    if ((ti_index) && (ti_index[0] >= 0))
    {
      SEC_FREE(ti_index);
      ti_index = NULL;
    }
  }
#endif
  
  MSF_WIDGET_REMOVE (dlg->handle[0], dlg->handle[1]);

  /* NOTE: we must not delete the Screen Handle! */
  for (i = dlg->num_handles - 1; i > 0; i--) 
  {
#ifdef WAP_SUPPORT
    if(i > 1)
      MSF_WIDGET_REMOVE (dlg->handle[1], dlg->handle[i]);
#else
    MSF_WIDGET_REMOVE (dlg->handle[1], dlg->handle[i]);
#endif
    MSF_WIDGET_RELEASE (dlg->handle[i]);
  }
  dlg->handle[0] = 0;
#ifdef WAP_SUPPORT
  if(!sec_ti_closing)
    bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_SEC_DLG);
#else
  SEC_FREE (dlg);
#endif

}

/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
sec_tiAction (sec_ti_t *dlg, MSF_UINT32 action)
{
  if (dlg != NULL) {
    if (dlg->handle[SEC_TI_OK_ACTION_HANDLE] == action) {
      dlg->response = SEC_TI_RESPONSE_POSITIVE;
    }
    else {
      dlg->response = SEC_TI_RESPONSE_CANCEL;
    }
  }
}

/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
sec_tiGetType (sec_ti_t *dlg)
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
sec_tiGetDialogHandle (sec_ti_t *dlg)
{
  if (dlg != NULL) {
    return dlg->handle[SEC_TI_DIALOG_HANDLE];
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
sec_tiGetInput (sec_ti_t *dlg, int idx, int *inputLen)
{
  MsfStringHandle  input = 0;
  char             buf[128];
  char            *tmp = NULL;

  if (dlg != NULL)
  {
    switch (dlg->type)
    {
    #ifdef SEC_CFG_USE_CERT
    case SEC_TI_STORE_CERT_DLG:
      if ((input = MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_SEC,
         dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_HANDLE], 0)) == 0)
         return NULL;
      break;
    #endif
    #ifdef SEC_CFG_USE_KEYS
    case SEC_TI_GENERATE_PIN_DLG:
    case SEC_TI_PIN_DLG:
    #endif
    #ifdef SEC_CFG_USE_CERT
    case SEC_TI_HASH_DLG:
    #endif
    #ifdef SEC_CFG_USE_KEYS
      #ifdef SEC_CFG_DELETE_KEY_VER
    case SEC_TI_ALLOW_DEL_KEYS_DLG:
      #endif
    #endif
      if ((input = MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_SEC,
         dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_1_HANDLE], 0)) == 0)
         return NULL;
      break;
    #ifdef SEC_CFG_USE_KEYS
    case SEC_TI_CHANGE_PIN_DLG:
      switch(idx)
      {
        case 0:
          if ((input = MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_SEC,
          dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_1_HANDLE], 0)) == 0)
          tmp = NULL;
          break;
        case 1:
          if ((input = MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_SEC,
          dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_2_HANDLE], 0)) == 0)
          tmp = NULL;
          break;
        case 2:
          if ((input = MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_SEC,
          dlg->handle[SEC_TI_TEXT_INPUT_GADGET_STR_3_HANDLE], 0)) == 0)
          tmp = NULL;
          break;
      }
      break;
    #endif
    }
    if (input != 0)
    {
      if (MSF_WIDGET_STRING_GET_DATA (input, buf, MsfUtf8) >= 0) {
        tmp = msf_cmmn_strdup (MSF_MODID_SEC, buf);
        *inputLen = strlen (tmp);
      }
      MSF_WIDGET_RELEASE (input);
    }
  }
  idx = idx;
  return tmp;
}


/*
 * Return the index of the choosen element in a menu.
 */
int
sec_tiGetMenuChoice (sec_ti_t *dlg)
{
  int i;
  int chosenIndex;

  for (i=0; i<ti_nbrOfCerts; i++)
  {
    if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(dlg->handle[SEC_TI_MENU_HANDLE], 
                                        ti_index[i]))
    {
      chosenIndex = i;
      return chosenIndex;
    }
  }
  return -1;
}

/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling sec_tiAction).
 */
int
sec_tiGetResponse (sec_ti_t *dlg)
{
  if (dlg != NULL) {
    return dlg->response;
  }

  return 0;
}

/**********************************************************************
 * Local functions
 **********************************************************************/

sec_ti_t *
sec_dlg_create (MSF_UINT32 screen_handle, int dialog_type, int num_handles )
{
  sec_ti_t *dlg;
  
 /* dlg = SEC_ALLOC (sizeof (sec_ti_t) + (num_handles - 1) * sizeof (MSF_UINT32));*/
  dlg = SEC_ALLOCTYPE(sec_ti_t);

  dlg->type = dialog_type;
  dlg->num_handles = num_handles;
  dlg->handle[SEC_TI_SCREEN_HANDLE] = screen_handle;

  return dlg;
}

/* Gadget functions */

/*
 * Create and return a string gadget with the supplied 
 * string handle and add it to the supplied window  
 * handler in the supplied position.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle 
sec_tiCreateStringGadget(MsfWindowHandle formHdl, MsfStringHandle strHdl,
                      MsfPosition	stringPos, MsfSize *stringSize,
                      int singleLine)
{
  MsfGadgetHandle sGadget_str;
#ifdef WAP_SUPPORT
  sGadget_str = MSF_WIDGET_STRING_GADGET_CREATE(MSF_MODID_SEC, strHdl, stringSize, 
                                                1/*singleLine*/, 0x8000, 0);
#else
  sGadget_str = MSF_WIDGET_STRING_GADGET_CREATE(MSF_MODID_SEC, strHdl, stringSize, 
                                                singleLine, MSF_GADGET_PROPERTY_FOCUS, 0);
#endif  
  if (MSF_WIDGET_WINDOW_ADD_GADGET(formHdl, sGadget_str, &stringPos, 0) < 0)
  {
    MSF_WIDGET_RELEASE( sGadget_str);
    return 0;
  }
  return sGadget_str;
}

/*
 * Create and return a text input gadget of the supplied  
 * type, size, and max size and add it to the supplied  
 * window handler in the supplied position.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateTextInputGadget(MsfWindowHandle formHdl, MsfPosition stringPos, 
                         MsfSize *textInputSize, int maxSize, 
                         MsfTextType textInputType)
{
  MsfPosition textInputPos;
  MsfGadgetHandle gadgetTextInput;

  textInputPos.x = SEC_FIRST_X_POS;
  textInputPos.y = stringPos.y;
  gadgetTextInput = MSF_WIDGET_TEXT_INPUT_CREATE(MSF_MODID_SEC, 
                                                 0,0, textInputType, maxSize, 
                                                 1, textInputSize, 
                                                 MSF_GADGET_PROPERTY_FOCUS, 0);
  if (gadgetTextInput == 0)
    return 0;

  if (MSF_WIDGET_WINDOW_ADD_GADGET(formHdl, gadgetTextInput, &textInputPos, 0) < 0)
  {
    MSF_WIDGET_RELEASE( gadgetTextInput);
    return 0;
  }
  return gadgetTextInput;
}

/*
 * Create and return a gadget with the supplied 
 * connection type and add it to the   
 * supplied window handler in the supplied position.
 * The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateConnTypeGadget(MsfWindowHandle formHdl, int connType, 
                        MsfPosition *stringPos, MsfSize stringSize)
{
  MsfStringHandle strHdl;
  MsfGadgetHandle gadgetStr;

  switch (connType)
  {
    case SEC_CONNECTION_TYPE_TLS:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_TLS);
      break;
    case SEC_CONNECTION_TYPE_WTLS:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_WTLS);
      break;
    case SEC_CONNECTION_TYPE_SSL:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_SSL);
      break;
    default:
      return 0;
  }
  gadgetStr = sec_tiCreateStringGadget(formHdl, strHdl, *stringPos, &stringSize, 1);
  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return gadgetStr;
}

/*
 * Create and return a gadget with the supplied 
 * HMAC algorithm and add it to the supplied   
 * window handler in the supplied position.
 * The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateHmacAlgGadget(MsfWindowHandle formHdl, sec_hash_alg hMacAlg, 
                       MsfPosition *stringPos, MsfSize stringSize)
{
  MsfStringHandle strHdl;
  MsfGadgetHandle gadgetStr;

  switch (hMacAlg)
  {
    case SEC_HASH_MD5:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_MD5);
      break;
    case SEC_HASH_SHA:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_SHA1);
      break;
    default:
      return 0;
  }
  gadgetStr = sec_tiCreateStringGadget(formHdl, strHdl, *stringPos, &stringSize, 1);
  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return gadgetStr;
}

/*
 * Create and return a gadget with the supplied 
 * HMAC key length and add it to the supplied   
 * window handler in the supplied position.
 * The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateHmacKeyLenGadget(MsfWindowHandle formHdl, int hMacKeyLen, 
                          MsfPosition *stringPos, MsfSize stringSize)
{
  MsfStringHandle strHdl;
  MsfGadgetHandle gadgetStr;
  char *tmpStr1, *tmpStr2;

  tmpStr2 = (char *)SEC_ALLOC(4);
  sprintf(tmpStr2, "%d", hMacKeyLen);
  tmpStr1 = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                             SEC_GET_STR_ID(SEC_STR_ID_SESS_HMAC_KEYLEN),0,MsfUtf8)+5);
  MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(SEC_STR_ID_SESS_HMAC_KEYLEN), tmpStr1, MsfUtf8);
  strcat (tmpStr1, tmpStr2);
  strHdl = SEC_STRCONV(tmpStr1);
  SEC_FREE(tmpStr1);
  SEC_FREE(tmpStr2);

  gadgetStr = sec_tiCreateStringGadget(formHdl, strHdl, *stringPos, &stringSize, 1);
  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return gadgetStr;
}

/*
 * Create and return a gadget with the supplied encryption 
 * algorithm and add it to the supplied window handler
 * in the supplied position. The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateEncrAlgGadget(MsfWindowHandle formHdl, MSF_UINT8 encrAlg, 
                       MsfPosition *stringPos, MsfSize stringSize)
{
  MsfStringHandle strHdl;
  MsfGadgetHandle gadgetStr;

  switch (encrAlg)
  {
    case SEC_CIPHER_NULL:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_ENCR_NULL);
      break;
    case SEC_CIPHER_RC5_CBC_40:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_ENCR_RC5_40);
      break;
    case SEC_CIPHER_RC5_CBC_56:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_ENCR_RC5_56);
      break;
    case SEC_CIPHER_RC5_CBC:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_ENCR_RC5);
      break;
    case SEC_CIPHER_3DES_CBC_EDE:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_ENCR_3DES);
      break;
    case SEC_CIPHER_RC5_CBC_64:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_ENCR_RC5_64);
      break;
    case SEC_CIPHER_RC4_40:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_ENCR_RC4_40);
      break;
    case SEC_CIPHER_RC4_128:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_ENCR_RC4_128);
      break;
    default:
      return 0;
  }
  gadgetStr = sec_tiCreateStringGadget(formHdl, strHdl, *stringPos, &stringSize, 1);
  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return gadgetStr;
}

/*
 * Create and return a gadget with the supplied encryption 
 * key length and add it to the supplied window handler
 * in the supplied position. The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateEncrKeyLenGadget(MsfWindowHandle formHdl, MSF_UINT16 encrKeyLen, 
                          MsfPosition *stringPos, MsfSize stringSize)
{
  MsfStringHandle strHdl;
  MsfGadgetHandle gadgetStr;
  char *tmpStr1, *tmpStr2;

  tmpStr2 = (char *)SEC_ALLOC(4);
  sprintf(tmpStr2, "%d", encrKeyLen);
  tmpStr1 = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                              SEC_GET_STR_ID(SEC_STR_ID_SESS_ENCR_KEYLEN),0,MsfUtf8)+5);
  MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(SEC_STR_ID_SESS_ENCR_KEYLEN), tmpStr1, MsfUtf8);
  strcat (tmpStr1, tmpStr2);
  SEC_FREE(tmpStr2);
  strHdl = SEC_STRCONV(tmpStr1);
  SEC_FREE(tmpStr1);

  gadgetStr = sec_tiCreateStringGadget(formHdl, strHdl, *stringPos, &stringSize, 1);
  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return gadgetStr;
}


/*
 * Create and return a gadget with the supplied key exchange 
 * algorithm and add it to the supplied window handler
 * in the supplied position. The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateKeyExchAlgGadget(MsfWindowHandle formHdl, int keyExchAlg, 
                          MsfPosition *stringPos, MsfSize stringSize)
{
  MsfStringHandle strHdl;
  MsfGadgetHandle gadgetStr;

  switch (keyExchAlg)
  {
    case SEC_TLS_KEYEXCH_NULL:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_NULL);
      break;
    case SEC_TLS_KEYEXCH_RSA:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_RSA);
      break;
    case SEC_TLS_KEYEXCH_DHE_DSS:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_DHE_DSS);
      break;
    default:
      return 0;
  }

  gadgetStr = sec_tiCreateStringGadget(formHdl, strHdl, *stringPos, &stringSize, 1);
  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return gadgetStr;
}

/*
 * Create and return a gadget with the supplied key exchange 
 * suite and add it to the supplied window handler
 * in the supplied position. The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateKeyExchSuiteGadget(MsfWindowHandle formHdl, int keyExchSuite, 
                            MsfPosition *stringPos, MsfSize stringSize)
{
  MsfStringHandle strHdl;
  MsfGadgetHandle gadgetStr;

  switch (keyExchSuite)
  {
    case SEC_WTLS_KEY_EXCH_NULL:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_NULL);
      break;
    case SEC_WTLS_KEY_EXCH_RSA_ANON:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_RSA_ANON);
      break;
    case SEC_WTLS_KEY_EXCH_RSA_ANON_512:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_RSA_ANON_512);
      break;
    case SEC_WTLS_KEY_EXCH_RSA_ANON_768:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_RSA_ANON_768);
      break;
    case SEC_WTLS_KEY_EXCH_RSA:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_RSA);
      break;
    case SEC_WTLS_KEY_EXCH_RSA_512:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_RSA_512);
      break;
    case SEC_WTLS_KEY_EXCH_RSA_768:
      strHdl = SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_RSA_768);
      break;
    default:
      return SEC_ERR_INVALID_PARAMETER;
  }
  gadgetStr = sec_tiCreateStringGadget(formHdl, strHdl, *stringPos, &stringSize, 1);
  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return gadgetStr;
}

/*
 * Create and return a gadget with the supplied key exchange 
 * key length and add it to the supplied window handler
 * in the supplied position. The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateKeyExchKeyLenGadget(MsfWindowHandle formHdl, int keyExchKeyLen, 
                             MsfPosition *stringPos, MsfSize stringSize)
{
  MsfStringHandle strHdl;
  MsfGadgetHandle gadgetStr;
  char *tmpStr1, *tmpStr2;

  tmpStr2 = (char *)SEC_ALLOC(6);
  sprintf(tmpStr2, "%d", keyExchKeyLen);
  tmpStr1 = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                             SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_KEYLEN),0,MsfUtf8)+5);
  MSF_WIDGET_STRING_GET_DATA(SEC_GET_STR_ID(SEC_STR_ID_SESS_KEYEXCH_KEYLEN), 
                             tmpStr1, MsfUtf8);
  strcat (tmpStr1, tmpStr2);
  strHdl = SEC_STRCONV(tmpStr1);
  SEC_FREE(tmpStr1);
  SEC_FREE(tmpStr2);

  gadgetStr = sec_tiCreateStringGadget(formHdl, strHdl, *stringPos, &stringSize, 1);
  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return gadgetStr;
}


/* Window functions */

/*
 * Create and return a dialog with the supplied title, 
 * dialog text, and of the supplied type. 
 * In case of error, 0 is returned.
 */
MsfWindowHandle 
sec_tiCreateDialog(MsfStringHandle dialogTitle, MsfStringHandle dialogText, 
                MsfDialogType type)
{
 	int properties;
  MsfWindowHandle dialogHdl;

  if (type == MsfWarning)  /*MSF_WINDOW_PROPERTY_NOTIFY */
    properties = MSF_WINDOW_PROPERTY_TITLE | MSF_WINDOW_PROPERTY_SECURE | MSF_WINDOW_PROPERTY_SCROLLBARHOR | MSF_WINDOW_PROPERTY_NOTIFY;
  else
    properties = MSF_WINDOW_PROPERTY_TITLE | MSF_WINDOW_PROPERTY_SECURE | MSF_WINDOW_PROPERTY_SCROLLBARHOR;

  if ( (dialogHdl = MSF_WIDGET_DIALOG_CREATE(MSF_MODID_SEC, 
        dialogText, type, 0, properties, 0)) == 0)
    return 0;

  if (MSF_WIDGET_SET_TITLE(dialogHdl, dialogTitle) <= 0)
  {
    MSF_WIDGET_RELEASE(dialogHdl);
    return 0;
  }

  return dialogHdl;
}

/*
 * Create and return a form with the supplied title.
 * In case of error, 0 is returned.
 */
MsfWindowHandle 
sec_tiCreateForm(MsfStringHandle formTitle)
{
 	MsfWindowHandle formHdl;
  int properties = /*MSF_WINDOW_PROPERTY_SCROLLBARHOR|*/ MSF_WINDOW_PROPERTY_SCROLLBARVER | MSF_WINDOW_PROPERTY_TITLE | MSF_WINDOW_PROPERTY_SECURE;

  if ( (formHdl = MSF_WIDGET_FORM_CREATE(MSF_MODID_SEC, &sec_display_size, properties, 0)) == 0)
    return 0;

  if (MSF_WIDGET_SET_TITLE(formHdl, formTitle) <= 0)
  {
    MSF_WIDGET_RELEASE( formHdl);
    return 0;
  }

  return formHdl;
}

/*
 * Create and return a menu with the supplied title.
 * In case of error, 0 is returned.
 */
MsfWindowHandle 
sec_tiCreateMenu(MsfStringHandle menuTitle)
{
  MsfWindowHandle menuHdl;
  int properties = (MSF_WINDOW_PROPERTY_TITLE | MSF_WINDOW_PROPERTY_SECURE | 
                  MSF_WINDOW_PROPERTY_SCROLLBARVER /*| MSF_WINDOW_PROPERTY_SCROLLBARHOR*/);
#ifdef WAP_SUPPORT
  if ( (menuHdl = MSF_WIDGET_MENU_CREATE(MSF_MODID_SEC, 
        MsfImplicitChoice, &sec_display_size, 0, 0, 0, properties, 0)) == 0)
#else
  if ( (menuHdl = MSF_WIDGET_MENU_CREATE(MSF_MODID_SEC, 
        MsfExclusiveChoice, &sec_display_size, 0, 0, 0, properties, 0)) == 0)
#endif
    return 0;
  
	if (MSF_WIDGET_CHOICE_ATTR_PROPERTY(menuHdl, 0, 
      MSF_CHOICE_ELEMENT_STRING_1) <= 0)
  {
    MSF_WIDGET_RELEASE(menuHdl);
    return 0;
  }

  if (MSF_WIDGET_SET_TITLE(menuHdl, menuTitle) <= 0)
  {
    MSF_WIDGET_RELEASE(menuHdl);
    return 0;
  }

  return menuHdl;
}

#if((defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT))
/* 
 * Create one string gadget and one input field in the supplied form 
 */
int
sec_tiCreateTextAndInput(MsfWindowHandle formHdl, 
                      MsfGadgetHandle *gadgetStr, MsfStringHandle str, 
                      MsfGadgetHandle *textInputGadget,
                      MsfPosition	*stringPos, int maxSize, 
                      MsfTextType textInputType)
{
  MsfSize stringSize = {20,150};
  MsfSize textInputSize = {20,150};

  /* String Gadget */
  (*gadgetStr) = sec_tiCreateStringGadget(formHdl, str, *stringPos, &stringSize, 1);
  if ((*gadgetStr) == 0) 
    return SEC_ERR_GENERAL_ERROR;
	
	/* Text input Gadget */
	(*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  (*textInputGadget) = sec_tiCreateTextInputGadget(formHdl, 
                                                *stringPos, &textInputSize, 
                                                maxSize, textInputType);
  if ((*textInputGadget) == 0)  
  {
    MSF_WIDGET_RELEASE( *gadgetStr);
    return SEC_ERR_GENERAL_ERROR;
  }
	(*stringPos).y = (MSF_INT16)((*stringPos).y + textInputSize.height + 5);
  return SEC_ERR_OK;
}
#endif


/* ** */

/*
 * Converts the supported time to a string of the
 * format "date month year". 
 */
int
sec_tiCvtTimeToStr(MSF_UINT32 time, char **timeStr)
{
  MSF_UINT32 tmpTime = time;
  MSF_UINT32 days;
#ifdef WAP_SUPPORT
  MSF_UINT32 month = 0;
#endif
  MSF_UINT32 daysIn31month = 31;
  MSF_UINT32 daysIn30month = 30;
  MSF_UINT32 daysIn29month = 29;
  MSF_UINT32 daysIn28month = 28;
  int nbrYears = 0, leapYear;
  MSF_UINT32 year;
  char *yearStr;
  char *monthStr;
  int monthStrLen = 0;
  char *dayStr;
  int dayStrLen;
  int l, j = 0;
  MsfStringHandle tmpStr = 0;

  /* Get minutes since 1/1 1970 */
  tmpTime /= 60;  
  /* Get hours since 1/1 1970 */
  tmpTime /= 60;
  /* Get days since 1/1 1970 */
  days = tmpTime / 24;
  /* Get years since 1/1 1970 */
  tmpTime = days / 365;
  year = 1970 + tmpTime;
  yearStr = (char *)SEC_ALLOC(6);
  sprintf(yearStr, "%lu", year);

  /* 1972 is the first leap year after 1970 */
  leapYear = 1;
  /* For each year since 1970 subtract the days in each month */
  while ((days > 0) && (nbrYears >= 0))
  {
    leapYear++;
    if (days <= 30)   /* January */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_JAN);
      month = 1;
      break;
    }
    days -= daysIn31month;    
    if (leapYear == 4)
    {
      if (days <= 28) /* February */
      {
        tmpStr = SEC_GET_STR_ID(SEC_STR_ID_FEB);
        month = 2;
        break;
      }
      days -= daysIn29month;  
    }
    else
    {
      if (days <= 27) /* February */
      {
        tmpStr = SEC_GET_STR_ID(SEC_STR_ID_FEB);
        month = 2;
        break;
      }
      days -= daysIn28month;  
    }
    if (days <= 30)   /* March */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_MARCH);
      month = 3;
      break;
    }
    days -= daysIn31month;    
    if (days <= 29)   /* April */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_APR);
      month = 4;
      break;
    }
    days -= daysIn30month;    
    if (days <= 30)   /* May */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_MAY);
      month = 5;
      break;
    }
    days -= daysIn31month;    
    if (days <= 29)   /* June */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_JUNE);
      month = 6;
      break;
    }
    days -= daysIn30month;    
    if (days <= 30)   /* July */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_JULY);
      month = 7;
      break;
    }
    days -= daysIn31month;    
    if (days <= 30)   /* August */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_AUG);
      month = 8;
      break;
    }
    days -= daysIn31month;    
    if (days <= 29)   /* September */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_SEP);
      month = 9;
      break;
    }
    days -= daysIn30month;    
    if (days <= 30)   /* October */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_OCT);
      month = 10;
      break;
    }
    days -= daysIn31month;   
    if (days <= 29)   /* November */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_NOV);
      month = 11;
      break;
    }
    days -= daysIn30month;    
    if (days <= 30)   /* December */
    {
      tmpStr = SEC_GET_STR_ID(SEC_STR_ID_DEC);
      month = 12;
      break;
    }
    days -= daysIn31month;    
    nbrYears++;
    if (leapYear == 4)
      leapYear = 0;
  } /* while */
  if ((days == 0) && (tmpStr == 0))
  {
    tmpStr = SEC_GET_STR_ID(SEC_STR_ID_JAN);
    month = 1;
  }
  if (tmpStr == 0)
  {
    SEC_FREE(yearStr);
    return SEC_ERR_INVALID_PARAMETER;
  }
#ifdef WAP_SUPPORT  
  monthStr = (char *)SEC_ALLOC(10);
  sprintf(monthStr, "%lu", month);
  monthStrLen = strlen(monthStr);
#else
  monthStrLen = MSF_WIDGET_STRING_GET_LENGTH(tmpStr,0,MsfUtf8);
  monthStr = (char *)SEC_ALLOC(monthStrLen+2);
  if (!monthStr)
  {
    SEC_FREE(yearStr);
    return SEC_ERR_INVALID_PARAMETER;
  }
  MSF_WIDGET_STRING_GET_DATA(tmpStr, monthStr, MsfUtf8);
#endif  
  days++;   /* To get the correct date, since 0 is no a date */
  dayStr = (char *)SEC_ALLOC(4);
  sprintf(dayStr, "%lu", days);
  if (days < 10)
    dayStrLen = 1;
  else
    dayStrLen = 2;

  for (l=0; l<monthStrLen; l++)
    (*timeStr)[j++] = monthStr[l];
  (*timeStr)[j++] = '-';
  for (l=0; l<dayStrLen; l++)
    (*timeStr)[j++] = dayStr[l];
  (*timeStr)[j++] = '-';
  for (l=0; l<4; l++)
    (*timeStr)[j++] = yearStr[l];
  (*timeStr)[j++] = '\0';

  SEC_FREE(dayStr);
  SEC_FREE(yearStr);
  MSF_WIDGET_RELEASE(tmpStr);
  SEC_FREE(monthStr);
  return SEC_ERR_OK;
}

/*
 * Convert the supplied strToCvt to UTF-8 and store in the
 * supplied dst. Returns 0 on success and -1 otherwise.
 */
int
sec_tiCvtToUtf8(unsigned char *strToCvt, long strToCvtLen, 
                char *dst, long *dstLen, MSF_INT16 charSet)
{
  int result = SEC_ERR_OK;

  /* I WTLS: IANA defined character sets */
  switch (charSet)
  {
    case MSF_CHARSET_UTF_8:           /* WTLS charSet */ 
    case SEC_ASN_1_UTF8STRING:        /* X.509 charSet */ 
      memcpy(dst, strToCvt, strToCvtLen);
      *dstLen = strToCvtLen;
      break;

    case MSF_CHARSET_LATIN_1:         /* WTLS charSet */
    case SEC_ASN_1_T61STRING:         /* X.509 charSet, TeletexString */
    case SEC_ASN_1_PRINTTABLESTRING:  /* X.509 charSet */
    case SEC_ASN_1_EMAIL_IA5STRING:   /* X.509 charSet */
      result = msf_charset_latin1_to_utf8 ((const char *)strToCvt,
                                         &strToCvtLen, dst, dstLen);
      break;

    case SEC_ASN_1_UNIVERSALSTRING:   /* X.509 charSets */
    case SEC_ASN_1_BMPSTRING:         /* X.509 charSets */
      result = msf_charset_ucs2_to_utf8 ((const char *)strToCvt, 
                                         &strToCvtLen, dst, dstLen);
      break;
      
    default:
      return -1;
  }
  dst[*dstLen] = '\0';
  return result;
}


/*
 * Extracts a string from the supplied textHandle.
 * bufLen is the size of buf. If buf ends with null, 
 * bufLen is the length of buf including null.
 */
int
sec_tiStrExtract(MsfGadgetHandle textHandle, char *buf, int *bufLen)
{
  MsfStringHandle msfStr;
  int tmpLen;
  
  buf[(*bufLen) - 1] = 0;
  
  /* index (now 0) only used in"...MsfDialog of type MsfPrompt." [MSF-INT]*/
  if ((msfStr = MSF_WIDGET_STRING_CREATE_TEXT(MSF_MODID_SEC, textHandle, 0)) == 0)
  {
    *bufLen = 0;
    return SEC_ERR_GENERAL_ERROR;
  }

  if ((tmpLen = MSF_WIDGET_STRING_GET_LENGTH(msfStr,0,MsfUtf8)) > (*bufLen))
  {
    *bufLen = 0;
    return SEC_ERR_GENERAL_ERROR;
  }

  *bufLen = 0;
  if (MSF_WIDGET_STRING_GET_DATA(msfStr, buf, MsfUtf8) < 0)
    return SEC_ERR_GENERAL_ERROR;
  
  if (MSF_WIDGET_RELEASE(msfStr) < 0)
    return SEC_ERR_GENERAL_ERROR;
  *bufLen = tmpLen;
  return SEC_ERR_OK;
}

/* ** */

/*
 * Create and return a gadget with the supplied 
 * string handle and valid date and add it to the   
 * supplied window handler in the supplied position.
 * The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateValidDateGadget(MsfWindowHandle formHdl, 
                            MSF_UINT32 validDate, MsfStringHandle validStr,
                            MsfPosition *stringPos, MsfSize stringSize)
{
  MsfGadgetHandle strGadget;
  MsfStringHandle strHdl;
  char tmpDate[30];
  char *tmpPtr = tmpDate;
  char *tmpStr;
  int tmpDateLen;

  sec_tiCvtTimeToStr(validDate, &tmpPtr);
  tmpDateLen = strlen((const char *)tmpDate);
#ifdef WAP_SUPPORT
  if(!validStr)
    tmpStr = (char *)SEC_ALLOC(tmpDateLen+5);
  else
    tmpStr = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                               validStr,0,MsfUtf8)+tmpDateLen+5);
#else
  tmpStr = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                             validStr,0,MsfUtf8)*tmpDateLen+5);
#endif

  tmpStr[0] = '\0';
#ifndef WAP_SUPPORT
  MSF_WIDGET_STRING_GET_DATA(validStr, tmpStr, MsfUtf8);
#endif
  
  strcat (tmpStr, tmpDate);

  strHdl = SEC_STRCONV(tmpStr);
  SEC_FREE(tmpStr);

  /* Create String Gadget */
  strGadget = sec_tiCreateStringGadget(formHdl, strHdl, 
                                       *stringPos, &stringSize, 1);

  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return strGadget;
}

/*
 * Create and return a gadget with the supplied fingerprint 
 * and add it to the supplied window handler in the 
 * supplied position. The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateFingerprGadget(MsfWindowHandle formHdl, 
                           unsigned char *fingerprint, int fingerprintLen,
                           MsfPosition *stringPos, MsfSize stringSize)
{
  MsfGadgetHandle strGadget;
  MsfStringHandle strHdl;
  char *tmpStr;
  int i;
  unsigned char *p1 = fingerprint;
  char *p2;

  /* Convert fingerprint */
  tmpStr = (char *)SEC_ALLOC(fingerprintLen*3+2);
  p2 = tmpStr;
  for (i=0; i<fingerprintLen; i++)
  {
    msf_cmmn_byte2hex (*p1, p2);
    p1++;
    p2 += 2;
    *p2 = ' ';
    p2++;
  }
  p2--;
  *p2 = '\0';
  strHdl = SEC_STRCONV(tmpStr);
  SEC_FREE(tmpStr);

  /* Create String Gadget */
  strGadget = sec_tiCreateStringGadget(formHdl, strHdl, *stringPos, 
                                       &stringSize, 1);
  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return strGadget;
}


/*
 * Create and return a string handle with the supplied 
 * string handle and issuer.
 * In case of error, 0 is returned.
 */
MsfStringHandle
sec_tiGetIssuerStrHdl(MSF_INT16 charSet, void *issuer, int issuerLen, 
                      MsfStringHandle issuerStr)
{
  MsfStringHandle strHdl;
  MSF_UINT8 nbrIssuerAtts;
  sec_name_attribute_t *issuerAtt = NULL;
  int i, attLen, attStrPos;
  char *attStr, *tmpStr;
  long tmpStrLen;
  int result = 0;
  MSF_UINT32 tmpType = 0;

  /* Use parser to get issuer attributes. */
  if (charSet == -1)  /* X.509 certificate */
  {
    SEC_x509GetNbrIssuerStrings(issuer, (MSF_UINT16)issuerLen, &nbrIssuerAtts);
    issuerAtt = (sec_name_attribute_t *)SEC_ALLOC(nbrIssuerAtts*sizeof(
                                                sec_name_attribute_t));
    SEC_x509GetIssuerAttributes(MSF_MODID_SEC, (const unsigned char *)issuer, 
                                (MSF_UINT16)issuerLen, &nbrIssuerAtts, 
                                issuerAtt);
  }
  else                /* WTLS certificate */
  {
    SEC_wtlsGetIssuerAttributes(MSF_MODID_SEC, issuer, (MSF_UINT16)issuerLen, 
                                &nbrIssuerAtts, NULL);
    issuerAtt = (sec_name_attribute_t *)SEC_ALLOC(nbrIssuerAtts*sizeof(
                                                sec_name_attribute_t));
    SEC_wtlsGetIssuerAttributes(MSF_MODID_SEC, (const unsigned char *)issuer, 
                                (MSF_UINT16)issuerLen, &nbrIssuerAtts, 
                                issuerAtt);
    for (i=0; i<nbrIssuerAtts; i++)
      issuerAtt[i].attributeCharSet = charSet;
  }
  /* Get length of string to show */
  attLen = 0;
  for (i=0; i<nbrIssuerAtts; i++)
    attLen += issuerAtt[i].attributeValueLen * 2;
#ifdef WAP_SUPPORT
  if(!issuerStr)
    attStrPos = 0;
  else
#endif
  attStrPos = MSF_WIDGET_STRING_GET_LENGTH(issuerStr,0,MsfUtf8);

  attStr = (char *)SEC_ALLOC((attLen*2 + attStrPos + nbrIssuerAtts + 5));
  if (!attStr)
  {
    for (i=0; i<nbrIssuerAtts; i++)
      SEC_FREE(issuerAtt[i].attributeValue);
    SEC_FREE(issuerAtt);
    return 0;
  }
#ifdef WAP_SUPPORT
  if(issuerStr)
#endif
  MSF_WIDGET_STRING_GET_DATA(issuerStr, attStr, MsfUtf8);

  if (attStrPos == -1)
    attStrPos = 0;
  
  tmpStr = attStr;
  tmpStr += attStrPos;

#ifdef SEC_CFG_SHOW_COUNTRY_NAME
  tmpType |= SEC_CFG_SHOW_COUNTRY_NAME;
#endif
#ifdef SEC_CFG_SHOW_ORGANISATION_NAME
  tmpType |= SEC_CFG_SHOW_ORGANISATION_NAME;
#endif
#ifdef SEC_CFG_SHOW_ORGANISATIONAL_UNIT_NAME
  tmpType |= SEC_CFG_SHOW_ORGANISATIONAL_UNIT_NAME;
#endif
#ifdef SEC_CFG_SHOW_STATE_OR_PROVINCE_NAME
  tmpType |= SEC_CFG_SHOW_STATE_OR_PROVINCE_NAME;
#endif
#ifdef SEC_CFG_SHOW_COMMON_NAME
  tmpType |= SEC_CFG_SHOW_COMMON_NAME;
#endif
#ifdef SEC_CFG_SHOW_DOMAIN_COMPONENT
  tmpType |= SEC_CFG_SHOW_DOMAIN_COMPONENT;
#endif
#ifdef SEC_CFG_SHOW_SERIAL_NUMBER
  tmpType |= SEC_CFG_SHOW_SERIAL_NUMBER;
#endif
#ifdef SEC_CFG_SHOW_DN_QUALIFIER
  tmpType |= SEC_CFG_SHOW_DN_QUALIFIER;
#endif
#ifdef SEC_CFG_SHOW_LOCALITY_NAME
  tmpType |= SEC_CFG_SHOW_LOCALITY_NAME;
#endif
#ifdef SEC_CFG_SHOW_TITLE
  tmpType |= SEC_CFG_SHOW_TITLE;
#endif
#ifdef SEC_CFG_SHOW_SURNAME
  tmpType |= SEC_CFG_SHOW_SURNAME;
#endif
#ifdef SEC_CFG_SHOW_GIVENNAME
  tmpType |= SEC_CFG_SHOW_GIVENNAME;
#endif
#ifdef SEC_CFG_SHOW_INITIALS
  tmpType |= SEC_CFG_SHOW_INITIALS;
#endif
#ifdef SEC_CFG_SHOW_GENERATION_QUALIFIER
  tmpType |= SEC_CFG_SHOW_GENERATION_QUALIFIER;
#endif
#ifdef SEC_CFG_SHOW_NAME
  tmpType |= SEC_CFG_SHOW_NAME;
#endif
#ifdef SEC_CFG_SHOW_EMAIL_ADDRESS
  tmpType |= SEC_CFG_SHOW_EMAIL_ADDRESS;
#endif
#ifdef SEC_CFG_SHOW_UNKNOWN_ATTRIBUTE_TYPE
  tmpType |= SEC_CFG_SHOW_UNKNOWN_ATTRIBUTE_TYPE;
#endif

  for (i=0; i<nbrIssuerAtts; i++)
  {
    tmpStrLen = (issuerAtt[i].attributeValueLen * 2) + 2;

    if (((issuerAtt[i].attributeType) & tmpType) != 0)
    {
      result = sec_tiCvtToUtf8(issuerAtt[i].attributeValue, 
                               issuerAtt[i].attributeValueLen, 
                               tmpStr, &tmpStrLen, 
                               issuerAtt[i].attributeCharSet);
      if (result != SEC_ERR_OK)
        return 0;

      attStrPos += tmpStrLen;
      tmpStr += (tmpStrLen + 1);
      attStr[attStrPos++] = ' ';
    }
  } /* for */
  attStrPos--;
  attStr[attStrPos] = '\0';
  for (i=0; i<nbrIssuerAtts; i++)
    SEC_FREE(issuerAtt[i].attributeValue);
  SEC_FREE(issuerAtt);
  
  strHdl = SEC_STRCONV(attStr);
  
  SEC_FREE(attStr);
  return strHdl;
}


/*
 * Create and return a gadget with the supplied 
 * string handle and issuer and add it to the   
 * supplied window handler in the supplied position.
 * The position is then updated.
 * In case of error, 0 is returned.
 */
MsfGadgetHandle
sec_tiCreateIssuerGadget(MsfWindowHandle formHdl, MSF_INT16 charSet, 
                         void *issuer, int issuerLen, 
                         MsfStringHandle issuerStr,
                         MsfPosition *stringPos, MsfSize stringSize)
{
  MsfGadgetHandle strGadget;
  MsfStringHandle strHdl;

  if ( (strHdl = sec_tiGetIssuerStrHdl(charSet, 
        issuer, issuerLen, issuerStr)) == 0)
    return 0;
  
  strGadget = sec_tiCreateStringGadget(formHdl, strHdl, *stringPos, 
                                       &stringSize, 0);

  (*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  return strGadget;
}

#ifdef SEC_CFG_USE_KEYS
/* 
 * Create a PIN form with one string gadget, one input gadget
 * and two actions in it. 
 * Returns SEC_ERR_OK on success, SEC_ERR_GENERAL_ERROR otherwise.
 */
int
sec_tiCreatePinForm(MsfWindowHandle *formHdl, MsfActionHandle *ok_action,
                    MsfActionHandle *cancel_action, MsfGadgetHandle *pinGadgetStr,
                    MsfGadgetHandle *textInputGadget,MSF_UINT8 keyType, 
                    MsfStringHandle formTitle,
                    MsfStringHandle textStr, MsfPosition	*stringPos)
{
  MsfStringHandle keyTypeStr;
  MsfStringHandle pinStr;
  MsfSize textInputSize = {20,150};
  char *tmpStr, *tmpStr2;
  MsfTextType textInputType;
  MsfSize stringSize = {60, 210};

  switch (keyType)
  {
    case SEC_NON_REPUDIATION_KEY:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_NONREP_KEY);
      break;
    case SEC_AUTHENTICATION_KEY:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_AUTH_KEY);
      break;
    case SEC_TI_PIN_OPEN_WIM:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_OPEN_WIM);
      break;
    case SEC_TI_PIN_CONNECT:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_CONNECT);
      break;
    case SEC_TI_PIN_SIGN_TEXT:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_SIGN_TEXT);
      break;
    case SEC_TI_PIN_STORE_CERT:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_STORE_CERT);
      break;
    case SEC_TI_PIN_DEL_CERT:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_DEL_CERT);
      break;
    case SEC_TI_PIN_GEN_AUT_KEY:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_GEN_AUT_KEY);
      break;
    case SEC_TI_PIN_GEN_NR_KEY:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_GEN_NR_KEY);
      break;
    case SEC_TI_PIN_PUK:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_PUK);
      break;
    case SEC_TI_PIN_ALLOW_DEL_AUT_KEY:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_ALLOW_DEL_AUT);
      break;
    case SEC_TI_PIN_ALLOW_DEL_NR_KEY:
      keyTypeStr = SEC_GET_STR_ID(SEC_STR_ID_PIN_ALLOW_DEL_NR);
      break;
    default:
      keyTypeStr = SEC_STRCONV(NULL);
      break;
  }

  tmpStr  = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(
                              keyTypeStr,0,MsfUtf8)*MSF_WIDGET_STRING_GET_LENGTH(
                              textStr,0,MsfUtf8)+2);
  tmpStr2 = (char *)SEC_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(keyTypeStr,0,MsfUtf8)+2);

  MSF_WIDGET_STRING_GET_DATA(textStr, tmpStr, MsfUtf8);
  MSF_WIDGET_STRING_GET_DATA(keyTypeStr, tmpStr2, MsfUtf8);
  strcat (tmpStr, tmpStr2);
  SEC_FREE(tmpStr2);
  pinStr = SEC_STRCONV(tmpStr);
  SEC_FREE(tmpStr);

  if ((*formHdl = sec_tiCreateForm(formTitle)) == 0)
    return SEC_ERR_GENERAL_ERROR;

  /* Action MsfOk */
	if ((*ok_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
                                SEC_GET_STR_ID(SEC_STR_ID_OK), MsfOk, 3,
                                MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto pin_error;

	MSF_WIDGET_ADD_ACTION(*formHdl, *ok_action);

  /* Action MsfCancel */
	if ((*cancel_action = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SEC,
                                    SEC_GET_STR_ID(SEC_STR_ID_CANCEL), 
                                    MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED)) == 0)
    goto pin_error;

  MSF_WIDGET_ADD_ACTION(*formHdl, *cancel_action);

  /* String Gadget pinStr */
	(*stringPos).x = SEC_FIRST_X_POS;
	(*stringPos).y = SEC_FIRST_Y_POS;
  
  *pinGadgetStr = sec_tiCreateStringGadget((*formHdl), pinStr, *stringPos, 
                                         &stringSize, 0);
  if ((*pinGadgetStr) == 0)
    goto pin_error;
	
	/* Text input Gadget */
	(*stringPos).y = (MSF_INT16)((*stringPos).y + stringSize.height + 5);
  textInputType = MsfPasswordText;
  *textInputGadget = sec_tiCreateTextInputGadget((*formHdl), (*stringPos), 
                                  &textInputSize, SEC_PIN_MAX_SIZE,
                                  textInputType);
  if ((*textInputGadget) == 0)
    goto pin_error;

  (*stringPos).y = (MSF_INT16)((*stringPos).y + textInputSize.height + 5);
  return SEC_ERR_OK;

pin_error:
  if (formHdl != 0)
    MSF_WIDGET_RELEASE(*formHdl);
  if (ok_action != 0)
    MSF_WIDGET_RELEASE(*ok_action);
  if (cancel_action != 0)
    MSF_WIDGET_RELEASE(*cancel_action);
  if (pinGadgetStr != 0)
    MSF_WIDGET_RELEASE(*pinGadgetStr);
  return SEC_ERR_GENERAL_ERROR;
}

#else
int
sec_tiCreatePinForm(MsfWindowHandle *formHdl, MsfActionHandle *ok_action,
                    MsfActionHandle *cancel_action, MsfGadgetHandle *pinGadgetStr,
                    MsfGadgetHandle *textInputGadget,MSF_UINT8 keyType, 
                    MsfStringHandle formTitle,
                    MsfStringHandle textStr, MsfPosition	*stringPos)
{
   return 0;
}
#endif

#ifdef WAP_SUPPORT
MsfImageHandle
sec_get_list_num_image(int i)
{
    return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_USERNAME,0);
    
   i++;
   switch(i)
   {
   case 1:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB1,0);
   case 2:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB2,0);
   case 3:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB3,0);
   case 4:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB4,0);
   case 5:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB5,0);
   case 6:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB6,0);
   case 7:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB7,0);
   case 8:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB8,0);
   case 9:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB9,0);
   case 10:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB10,0);
   case 11:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB11,0);
   case 12:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB12,0);
   case 13:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB13,0);
   case 14:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB14,0);
   case 15:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB15,0);
   case 16:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB16,0);
   case 17:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB17,0);
   case 18:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB18,0);
   case 19:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB19,0);
   case 20:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB20,0);
   default:
     return 0;
   }
}
#endif


