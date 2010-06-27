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
 * sec_ti.h
 *
 * Created by Anna Andréasson, Mon Oct 21 2002.
 *
 */
#ifndef _sec_ti_h
#define _sec_ti_h

#ifndef  _msf_def_h
#include "msf_def.h"
#endif
#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif
#ifndef _sec_if_h
#include "sec_if.h"
#endif

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1))) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS) || defined(SEC_CFG_CAN_SIGN_TEXT))
#ifndef SEC_CFG_USE_CERT
#define SEC_CFG_USE_CERT
#endif
#endif

#if((defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT))
#ifndef SEC_CFG_USE_KEYS
#define SEC_CFG_USE_KEYS
#endif
#endif

/**********************************************************************
 * Constants
 **********************************************************************/

/* Types of dialogues */
#define SEC_TI_CONFIRM_DLG								            1
#define SEC_TI_EXT_CONFIRM_DLG							          2		
#ifdef SEC_CFG_SHOW_WARNINGS
#define SEC_TI_WARNING_DLG								            3
#endif
#define SEC_TI_SHOW_SESSION_INFO_DLG					        4
#ifdef SEC_CFG_USE_CERT
#define SEC_TI_SHOW_CERT_NAMES_DLG						        5
#endif
#ifdef SEC_CFG_USE_KEYS
#define	SEC_TI_CHOOSE_CERT_BY_NAME_DLG					      6
#endif
#ifdef SEC_CFG_USE_CERT
#define SEC_TI_STORE_CERT_DLG                         7
#endif
#define SEC_TI_CONFIRM_DISP_NAME_DLG					        8	
#ifdef SEC_CFG_USE_CERT			
#define SEC_TI_SHOW_CERT_DLG							            9
#define SEC_TI_SHOW_VERIFIED_CERT_DLG							    10
#endif
#ifdef SEC_CFG_USE_KEYS
#define SEC_TI_GENERATE_PIN_DLG						            11
#define SEC_TI_CHANGE_PIN_DLG							            12
#define SEC_TI_PIN_DLG									              13
#ifdef SEC_CFG_DELETE_KEY_VER
#define SEC_TI_ALLOW_DEL_KEYS_DLG						          14
#endif /*SEC_CFG_DELETE_KEY_VER*/
#endif
#ifdef SEC_CFG_USE_CERT
#define SEC_TI_HASH_DLG								                15
#endif
#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
#define SEC_TI_STORED_CONTRACTS_DLG                   16
#define SEC_TI_SHOW_STORED_CONTRACT_DLG				        17
#endif

/* Response types */
#define SEC_TI_RESPONSE_POSITIVE                 1
#define SEC_TI_RESPONSE_NEGATIVE                 2
#define SEC_TI_RESPONSE_CANCEL                   3

/* The time in milliseconds to show a warning dialog */
#define SEC_DIALOG_TIME 5000

/***************************************************/
/* Constants                                       */
/***************************************************/

/* Reasons to call dialog again */
#define SEC_INPUT_TOO_SHORT 100
#define SEC_INPUT_TOO_LONG  101
#define SEC_INPUT_FALSE     102
#define SEC_INPUT_MISMATCH  103
#define SEC_INPUT_ERROR     104

/* Dialog type */
#define SEC_TI_CHANGE_PIN_DIALOG  200
#define SEC_TI_GEN_PIN_DIALOG     201
#define SEC_TI_PIN_DIALOG         202
#define SEC_TI_DELETE_CERT        203
#define SEC_TI_ALLOW_DEL_DIALOG   204

/* PIN cause */
#define SEC_TI_PIN_OPEN_WIM           200
#define SEC_TI_PIN_CONNECT            201
#define SEC_TI_PIN_SIGN_TEXT          202
#define SEC_TI_PIN_STORE_CERT         203
#define SEC_TI_PIN_DEL_CERT           204
#define SEC_TI_PIN_GEN_AUT_KEY        205
#define SEC_TI_PIN_GEN_NR_KEY         206
#define SEC_TI_PIN_PUK                207
#define SEC_TI_PIN_ALLOW_DEL_AUT_KEY  208
#define SEC_TI_PIN_ALLOW_DEL_NR_KEY   209


/**********************************************************************
 * Type definitions
 **********************************************************************/

typedef struct {
  int        type;
  int        response;
  int        num_handles;
#ifdef WAP_SUPPORT
  MSF_UINT32 handle[20];  /*Max number of handles in a dialog*/
#else
  MSF_UINT32 handle[11];  /*Max number of handles in a dialog*/
#endif
} sec_ti_t;

/* Define the reasons for asking for the PIN code */
typedef enum
{
	SEC_PIN_OPEN_WIM,
	SEC_PIN_CONNECT,
	SEC_PIN_SIGN_TEXT,
	SEC_PIN_STORE_CERT,
	SEC_PIN_DELETE_CERT,
	SEC_PIN_GENERATE_AUTH_KEY,
	SEC_PIN_GENERATE_NONREP_KEY,
	SEC_PIN_PUK
} sec_pin_cause_t;


typedef struct {
  void *friendlyName;
  MSF_UINT16 friendlyNameLen;
  MSF_INT16 charSet;
  MSF_INT8 nameType;
  int certId;
} sec_cert_name_t;

/* Define the different types of certificates used */
#define SEC_USER_CERT 'U'
#define SEC_CA_CERT   'C'

#define SEC_CERT_NAME_WTLS 1    /* Friendly name is taken from the certificate        */
                                /* and is the name in the Identifier (see WTLS spec.) */
#define SEC_CERT_NAME_X509 2    /* Friendly name is taken from the certificate        */
                                /* and is a X.509 distinguished name                  */
#define SEC_WRITTEN_NAME   3    /* Friendly name is typed in by the user or the       */
                                /* SEC_PUB_KEY_CERT_NAME in sec_cfg.h                 */


/**********************************************************************
 * Exported functions
 **********************************************************************/
/*
 * Create a screen.
 * Returns a MsfScreenHande, or 0 on error.
 */
MSF_UINT32
sec_tiCreateScreen (void);

/*
 * Delete a screen.
 */
void
sec_tiDeleteScreen (MSF_UINT32 screenHandle);

/*
 * Makes a Screen active (option = 1) or hidden (option = 0).
 */
void
sec_tiFocus(MSF_UINT32 screenHandle, int option);

/*
 * Makes a Menu/Dialog/Form active (option = 1) or hidden (option = 0).
 */
void 
sec_tiMenuFocus(sec_ti_t *dlg, int option);

/*
 * Create a confirmation dialog with the supplied message, 
 * yes message, and no message.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateConfirmDlg(MSF_UINT32 screenHandle, int msg, int yesMsg, int noMsg);

#ifdef SEC_CFG_CAN_SIGN_TEXT
/*
 * Create an extended confirmation dialog with the supplied text, 
 * message, yes message, and no message.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateExtConfirmDlg(MSF_UINT32 screenHandle, int msg, const char *text, 
                           int yesMsg, int noMsg);
#endif

#ifdef SEC_CFG_SHOW_WARNINGS
/*
 * Create a warning dialog with the supplied message.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateWarningDlg(MSF_UINT32 screenHandle, int msg);
#endif

/*
 * Create a form with the supplied session info.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateSessionInfoDlg(MSF_UINT32 screenHandle, sec_session_info_t sessInf);

#ifdef SEC_CFG_USE_CERT
/*
 * Create a menu with the supplied certificate names.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateShowCertNamesDlg(MSF_UINT32 screenHandle, int nbrOfCerts, 
                              sec_cert_name_t *certNames);

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
                          void *subject, int subjectLen, char certType); 

/* 
 * Create a form with the supplied display name, message,
 * yes message, and no message. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
#endif /*SEC_CFG_USE_CERT*/

#ifdef SEC_CFG_USE_KEYS
/*
 * Create a certificate names menu with the supplied certificate names.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateChooseCertByNameDlg(MSF_UINT32 screenHandle, int title, 
                                int nbrOfCerts, sec_cert_name_t *certNames);
#endif /*SEC_CFG_USE_KEYS*/

sec_ti_t *
sec_tiCreateConfDispNameDlg(MSF_UINT32 screenHandle, MSF_INT16 charSet, 
                       void *displayName, int displayNameLen, 
                       int msg, int yesMsg, int noMsg);

/*
 * Create a form with the supplied certificate parts and cancel string.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
#ifdef SEC_CFG_USE_CERT
sec_ti_t *
sec_tiCreateShowCertDlg(MSF_UINT32 screenHandle, MSF_INT16 issuerCharSet, 
                      void *issuer, int issuerLen,
                      MSF_UINT32 validNotBefore, 
                      MSF_UINT32 validNotAfter, 
                      MSF_INT16 subjectCharSet, 
                      void *subject, int subjectLen,
                      unsigned char *fingerprint, int fingerprintLen,
                      int cancelStr);
#endif /*SEC_CFG_USE_CERT*/

#ifdef SEC_CFG_USE_KEYS
/* 
 * Create a PIN form with one string gadget, one input gadget
 * and two actions in it. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateGenPinDlg(MSF_UINT32 screenHandle, MSF_UINT8 keyType, int reason);

/* 
 * Create a PIN form with three string gadgets, three input gadgets,
 * and two actions in it. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateChangePinDlg(MSF_UINT32 screenHandle, MSF_UINT8 keyType, int reason);

/* 
 * Create a PIN form with one string gadget, one input gadget,
 * and two actions in it. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreatePinDlg(MSF_UINT32 screenHandle, sec_pin_cause_t pinCause, int reason);

#ifdef SEC_CFG_DELETE_KEY_VER
/* 
 * Create a PUK form with one string gadget, one input gadget,
 * and two actions in it. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateAllowDelDlg(MSF_UINT32 screenHandle, MSF_UINT8 keyType, int reason);
#endif
#endif

#ifdef SEC_CFG_USE_CERT
/* 
 * Create a hash form with the supplied display name. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateHashDlg(MSF_UINT32 screenHandle, MSF_INT16 charSet, 
                  void *displayName, int displayNameLen, int reason);
#endif

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
/* 
 * Create a menu with the supplied contracts and signing times. 
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateStoredContractsDlg(MSF_UINT32 screenHandle, int nbrContracts, 
                                sec_contract_info_t *contractVec);
/*
 * This function displays the supplied contract, 
 * the signature of the contract, and the time it was signed.
 * Returns a pointer to a struct sec_ti_t, or NULL on error.
 */
sec_ti_t *
sec_tiCreateShowContractDlg(MSF_UINT32 screenHandle, sec_contract_info_t chosen_contract);
#endif

/*		
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
sec_tiDelete (sec_ti_t *dlg);

/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
sec_tiAction (sec_ti_t *dlg, MSF_UINT32 action);

/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
sec_tiGetType (sec_ti_t *dlg);

/*
 * Return the Dialog Handle associated with the specified dialog.
 * Returns 0 on error. 
 */
MSF_UINT32
sec_tiGetDialogHandle (sec_ti_t *dlg);

/*
 * Return the input string from one of the input fields of
 * this dialog. The index of the requested input field is given
 * as 'idx', with indices starting at 0.
 * Returns NULL on error.
 * NOTE: it is the responsibility of the caller to deallocate
 * the returned string.
 */
char *
sec_tiGetInput(sec_ti_t *dlg, int idx, int *inputLen);

/*
 * Return the index of the choosen element in a menu.
 */
int
sec_tiGetMenuChoice (sec_ti_t *dlg);

/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling sec_tiAction).
 */
int
sec_tiGetResponse (sec_ti_t *dlg);

#endif
