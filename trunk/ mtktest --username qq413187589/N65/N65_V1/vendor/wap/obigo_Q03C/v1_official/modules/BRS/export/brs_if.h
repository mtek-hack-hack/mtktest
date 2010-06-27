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
 * brs_if.h
 *
 * Created by Petter Wallin, Aug 07 2002.
 *
 * Revision  history:
 *   020903, AED: Updated
 *   021108, STMA: added focus constants.
 */
#ifndef _brs_if_h
#define _brs_if_h

#ifndef  _msf_def_h
#include "msf_def.h"
#endif

#ifndef  _msf_dcvt_h
#include "msf_dcvt.h"
#endif

#ifndef  _msf_int_h
#include "msf_int.h"
#endif

#ifndef _brs_cfg_h
#include "brs_cfg.h"
#endif

/**********************************************************************
 * Signals 
 **********************************************************************/

/* Signals sent to the BRS */
#define BRS_SIG_CREATE_INSTANCE          ((MSF_MODID_BRS << 8) + 0x01)
#define BRS_SIG_DELETE_INSTANCE          ((MSF_MODID_BRS << 8) + 0x02)
#define BRS_SIG_RESIZE_WINDOW            ((MSF_MODID_BRS << 8) + 0x03)
#define BRS_SIG_LOAD_URL                 ((MSF_MODID_BRS << 8) + 0x04)
#define BRS_SIG_ACTIVATE_DO_ELEMENT      ((MSF_MODID_BRS << 8) + 0x05)
#define BRS_SIG_MOVE                     ((MSF_MODID_BRS << 8) + 0x06)
#define BRS_SIG_RELOAD                   ((MSF_MODID_BRS << 8) + 0x07)
#define BRS_SIG_STOP                     ((MSF_MODID_BRS << 8) + 0x08)
#define BRS_SIG_NAVIGATION_CHANGE        ((MSF_MODID_BRS << 8) + 0x09)
#define BRS_SIG_SAVE_PAGE_OFFLINE        ((MSF_MODID_BRS << 8) + 0x0a)
#define BRS_SIG_SET_OFFLINE_MODE         ((MSF_MODID_BRS << 8) + 0x0b)
#define BRS_SIG_DELETE_OFFLINE_PAGE      ((MSF_MODID_BRS << 8) + 0x0c)

/* Signals sent from the BRS */
#define BRS_SIG_CREATED                  ((MSF_MODID_BRS << 8) + 0x0d)
#define BRS_SIG_STATUS                   ((MSF_MODID_BRS << 8) + 0x0e)
#define BRS_SIG_ERROR                    ((MSF_MODID_BRS << 8) + 0x0f)
#define BRS_SIG_DOCUMENT_INFO            ((MSF_MODID_BRS << 8) + 0x10)
#define BRS_SIG_DO_ELEMENTS              ((MSF_MODID_BRS << 8) + 0x11)
#define BRS_SIG_ELEMENT_FOCUSED          ((MSF_MODID_BRS << 8) + 0x12)
#define BRS_SIG_PAGE_NOT_FOUND_OFFLINE   ((MSF_MODID_BRS << 8) + 0x13)



/**********************************************************************
 * Registry keys:
 **********************************************************************/

/*
 * All of the keys below should be set under a path, "/BRS/xyz",
 * where "xyz" is the value of the parameter 'applicationName'
 * in BRSif_createInstance.
 */

/* Registry keys having an integer value: */
#define BRS_REGISTRY_KEY_HISTORY_SIZE             "histsize"
#define BRS_REGISTRY_KEY_REFRESH_ENABLED          "refresh"
#define BRS_REGISTRY_KEY_CSS_ENABLED              "use_css"
#define BRS_REGISTRY_KEY_CONNECTION_TYPE          "con_type"
#define BRS_REGISTRY_KEY_NETWORK_ACCOUNT_ID       "acc_id"
#define BRS_REGISTRY_KEY_PROXY_PORT               "prx_port"
#define BRS_REGISTRY_KEY_PROXY_SECURE_PORT        "prx_secp"
#define BRS_REGISTRY_KEY_WML_INLINE_DO            "inlinedo"
#define BRS_REGISTRY_KEY_OBJECT_LOAD_NULL_MIME    "ldnomime"
#define BRS_REGISTRY_KEY_REQUEST_TIMEOUT          "timeout"
#define BRS_REGISTRY_KEY_SEND_REFERRER            "sndrefrr"
#define BRS_REGISTRY_KEY_NARROW_RENDERING_ENABLED "nrrwrnd"
#define BRS_REGISTRY_KEY_CACHE_ON                 "cacheon"


/* Registry keys having a string value: */
#define BRS_REGISTRY_KEY_ACCEPT_HEADER            "accept"
#define BRS_REGISTRY_KEY_ACCEPT_OBJECT_HEADER     "accptobj"
#define BRS_REGISTRY_KEY_ACCEPT_CHARSET_HEADER    "acc_chrs"
#define BRS_REGISTRY_KEY_ACCEPT_LANGUAGE_HEADER   "acc_lang"
#define BRS_REGISTRY_KEY_USER_AGENT_HEADER        "user_agt"
#define BRS_REGISTRY_KEY_IMODE_USER_AGENT_HEADER  "imode_ua"
#define BRS_REGISTRY_KEY_PROXY_ADDRESS            "prx_addr"
#define BRS_REGISTRY_KEY_PROXY_USERNAME           "prx_uid"
#define BRS_REGISTRY_KEY_PROXY_PASSWORD           "prx_pwd"
#define BRS_REGISTRY_KEY_PROXY_REALM              "prx_rlm"
#define BRS_REGISTRY_KEY_OBJECT_LOAD              "obj_load"
#define BRS_REGISTRY_KEY_OBJECT_ASK               "obj_ask"
#define BRS_REGISTRY_KEY_USER_STYLE_SHEET         "cssprefs"



/**********************************************************************
 * Other constants:
 **********************************************************************/

#define BRS_MOVE_BACKWARD                         1
#define BRS_MOVE_FORWARD                          2
#define BRS_MOVE_RELOAD                           3

#define BRS_INFO_FLAG_ENABLE_BACK                 0x01
#define BRS_INFO_FLAG_ENABLE_FORWARD              0x02
#define BRS_INFO_FLAG_NEW_PAGE                    0x04

#define BRS_OPTION_NO_CACHE                       0x01

#define BRS_FOCUSED_ELEMENT_NONE                  0
/* a and anchor*/
#define BRS_FOCUSED_ELEMENT_LINK                  1
/* do elements, if rendered in content*/
#define BRS_FOCUSED_ELEMENT_DO                    2
/* textarea and input type="text"*/
#define BRS_FOCUSED_ELEMENT_TEXTINPUT             3
#define BRS_FOCUSED_ELEMENT_SELECT                4
/* img and object*/
#define BRS_FOCUSED_ELEMENT_IMAGE                 5
#define BRS_FOCUSED_ELEMENT_IMG_NO_SAVE           6
/* input type="image"*/
#define BRS_FOCUSED_ELEMENT_INPUT                 7
/* input type="button" or element button*/
#define BRS_FOCUSED_ELEMENT_BUTTON                8
#define BRS_FOCUSED_ELEMENT_SUBMIT                9
#define BRS_FOCUSED_ELEMENT_RESET                 10
#define BRS_FOCUSED_ELEMENT_FILE_INPUT            11
/* input type="checkbox", "radio" depening on whether they are checked or not.*/
#define BRS_FOCUSED_ELEMENT_INPUT_SELECTED        12
#define BRS_FOCUSED_ELEMENT_INPUT_UNSELECTED      13
/* Area element in imagemaps */
#define BRS_FOCUSED_ELEMENT_AREA                  14
/* Input element with type image */
#define BRS_FOCUSED_ELEMENT_INPUT_IMAGE           15
/************************************************************
 * DRM information for focused element.
 ************************************************************/
#define BRS_FOCUSED_ELEM_DRM_RESTRICTION_NONE         0
#define BRS_FOCUSED_ELEM_DRM_RESTRICTION_FWD_LOCK     1

/************************************************************
 * Status Codes
 ************************************************************/

#define BRS_STATUS_START_TRANSACTION              1
#define BRS_STATUS_END_TRANSACTION                2
#define BRS_STATUS_LOADING_DOCUMENT               3
#define BRS_STATUS_LOADING_DOCUMENT_DONE          4
#define BRS_STATUS_LOADING_DOCUMENT_FAILED        5
#define BRS_STATUS_LOADING_OBJECT                 6
#define BRS_STATUS_LOADING_OBJECT_DONE            7
#define BRS_STATUS_LOADING_OBJECT_FAILED          8
#define BRS_STATUS_OBJECT_NOT_IN_CACHE            9
#define BRS_STATUS_OFFLINE_MODE_ON               10
#define BRS_STATUS_OFFLINE_MODE_OFF              11
#define BRS_STATUS_OFFLINE_PAGE_SAVE_OK          12
#define BRS_STATUS_OFFLINE_PAGE_SAVE_FAILED      13




/************************************************************
 * Error Codes
 ************************************************************/

/* Invalid input */
#define BRS_ERROR_INVALID_INPUT                   14
#define BRS_ERROR_INVALID_URL                     15
#define BRS_ERROR_INVALID_SCHEME                  16

/* Parser error codes. For more information, see msf_prsr.h. */
#define BRS_ERROR_UNKNOWN_CHARSET                 21
#define BRS_ERROR_SYNTAX                          22
#define BRS_ERROR_UNKNOWN_DOCTYPE                 23
#define BRS_ERROR_UNSUPPORTED_WBXML               24
#define BRS_ERROR_UNEXPECTED_END_OF_DOC           25
#define BRS_ERROR_VALIDATION                      26
#define BRS_ERROR_ABORTED                         27
#define BRS_ERROR_REQUIRE_FRAMES                  28

/* 'WMLS' errors, i.e., error in WMLScript */
#define BRS_ERROR_WMLS                            30
#define BRS_ERROR_WMLS_VERIFICATION               31
#define BRS_ERROR_WMLS_LIB                        32
#define BRS_ERROR_WMLS_FUNC_ARGS                  33
#define BRS_ERROR_WMLS_EXTERNAL                   34
#define BRS_ERROR_WMLS_LOAD                       35
#define BRS_ERROR_WMLS_INTERPRETING               36
#define BRS_ERROR_WMLS_ABORT                      37
#define BRS_ERROR_WMLS_EXIT                       38

/* Access restrictions on WML or WMLScript */
#define BRS_ERROR_ACCESS_RESTRICTIONS_WML         40
#define BRS_ERROR_ACCESS_RESTRICTIONS_WMLS        41

/* Communication errors. */
#define BRS_ERROR_COMMUNICATION                   50
#define BRS_ERROR_HOST_NOT_FOUND                  51
#define BRS_ERROR_REQUEST_TIMED_OUT               52
#define BRS_ERROR_CONNECTION_FAILED               53
#define BRS_ERROR_SECURE_CONNECTION_FAILED        54
#define BRS_ERROR_AUTHENTICATION                  55

/* Misc. */
#define BRS_ERROR_INTERNAL                        60
#define BRS_ERROR_RESEND_POST_WARNING             61
#define BRS_ERROR_OUT_OF_MEMORY                   62
#define BRS_ERROR_CONTENT_TOO_LARGE               63

/**********************************************************************
 * Markable elements
 **********************************************************************/
#define BRS_MARKABLE_ELEMENT_A           0x0001
#define BRS_MARKABLE_ELEMENT_ANCHOR      0x0002
#define BRS_MARKABLE_ELEMENT_AREA        0x0004
#define BRS_MARKABLE_ELEMENT_DO          0x0008
#define BRS_MARKABLE_ELEMENT_IMG         0x0010
#define BRS_MARKABLE_ELEMENT_INPUT       0x0020
#define BRS_MARKABLE_ELEMENT_LABEL       0x0040
#define BRS_MARKABLE_ELEMENT_OBJECT      0x0080
#define BRS_MARKABLE_ELEMENT_OPTION      0x0100
#define BRS_MARKABLE_ELEMENT_SELECT      0x0200
#define BRS_MARKABLE_ELEMENT_TEXTAREA    0x0400
#define BRS_MARKABLE_ELEMENT_INPUT_IMAGE 0x0800



#define BRS_MARKABLE_ELEMENT_DEFAULT  (BRS_MARKABLE_ELEMENT_A | BRS_MARKABLE_ELEMENT_ANCHOR | \
                                       BRS_MARKABLE_ELEMENT_AREA | \
                                       BRS_MARKABLE_ELEMENT_DO | BRS_MARKABLE_ELEMENT_INPUT | \
                                       BRS_MARKABLE_ELEMENT_OPTION| \
                                       BRS_MARKABLE_ELEMENT_SELECT | BRS_MARKABLE_ELEMENT_TEXTAREA)


/**********************************************************************
 * Type definitions
 **********************************************************************/

typedef struct {
  MSF_INT16  elementId;     /* Unique ID, used in BRS_SIG_ACTIVATE_DO_ELEMENT */
  char      *eventType;     /* Event type, "accept", "prev", etc. */
  char      *label;         /* Label, an attribute in the DO-element */
  MSF_BOOL   isOptional;    /* TRUE if this DO element is optional */
} brs_do_element_t;


/**********************************************************************
 * Signal parameters 
 **********************************************************************/

/* For the signal BRS_SIG_CREATE_INSTANCE */ 
typedef struct { 
  MsfScreenHandle  screenHandle;
  MSF_INT16        windowPositionX;
  MSF_INT16        windowPositionY;
  MSF_INT16        windowSizeHeight;
  MSF_INT16        windowSizeWidth;
  char            *applicationName;
} brs_create_instance_t;

/* For the signal BRS_SIG_CREATED */ 
typedef struct { 
  MsfWindowHandle paintBox;
  MSF_INT16 instanceId;
  MSF_INT16 errorCode;
} brs_created_t;

/* For the signal BRS_SIG_DELETE_INSTANCE */ 
typedef struct { 
  MSF_INT16 instanceId;
} brs_delete_instance_t;

/* For the signal BRS_SIG_RESIZE_WINDOW */ 
typedef struct { 
  MSF_INT16 instanceId;
  MSF_INT16 windowPositionX;
  MSF_INT16 windowPositionY;
  MSF_INT16 windowSizeHeight;
  MSF_INT16 windowSizeWidth;
} brs_resize_window_t;

/* For the signal BRS_SIG_LOAD_URL */ 
typedef struct { 
  MSF_INT16  instanceId;
  MSF_INT16  options; 
  char      *url;
} brs_load_url_t;

/* For the signal BRS_SIG_ACTIVATE_DO_ELEMENT */
typedef struct {
  MSF_INT16 instanceId;
  MSF_INT16 elementId;
} brs_activate_do_element_t;

/* For the signal BRS_SIG_MOVE */ 
typedef struct { 
  MSF_INT16 instanceId; 
  MSF_INT16 direction; 
  MSF_INT16 steps;
} brs_move_t;

/* For the signal BRS_SIG_RELOAD */ 
typedef struct { 
  MSF_INT16 instanceId; 
} brs_reload_t;

/* For the signal BRS_SIG_STOP */ 
typedef struct { 
  MSF_INT16 instanceId;
} brs_stop_t;


/* For the signal BRS_SIG_STATUS */
typedef struct {
  MSF_INT16  instanceId;
  MSF_INT16  status;
  MSF_INT16  transactionId;
  char      *url;
  MSF_INT32  size;
} brs_status_t;

/* For the signal BRS_SIG_ERROR */
typedef struct {
  MSF_INT16 instanceId;
  MSF_INT16 errorCode;
  MSF_INT16 stkError; /**< If errorCode is one of the Communication errors,
                        *   then this field may hold further information in
                        *   the form of an error code from STK, or one of
                        *   the STK HTTP status codes. Otherwise it is 0. */
} brs_error_t;

/* For the signal BRS_SIG_DOCUMENT_INFO */
typedef struct {
  MSF_INT16   instanceId; 
  MSF_INT16   documentId; 
  MSF_INT16   flags; 
  char       *url; 
  char       *title;
  MSF_INT32   size; 
  MSF_UINT32  lastModified;
  MSF_INT16   docType;
  MSF_INT32   socketId;
  MSF_INT32   securityId;
  MSF_INT16   protocol;
} brs_document_info_t;

/* For the signal BRS_SIG_DO_ELEMENTS */
typedef struct {
  MSF_INT16         instanceId;
  MSF_INT16         numElements;
  brs_do_element_t *elements;
} brs_do_elements_t;

/* For the signal BRS_SIG_ELEMENT_FOCUSED */
typedef struct {
  MSF_INT16  instanceId;
  MSF_INT16  type;
  MSF_INT16  drm_restriction;
  char*      title;
  char*      url;
  char*      object_url;
  char*      object_mime;
  char*      object_filePath;
} brs_element_focused_t;

/* For the signal BRS_SIG_NAVIGATION_CHANGE */
typedef struct {
  MSF_INT16 instanceId;
  MSF_INT16 elements;
} brs_navigation_change_t;


/* Offline browsing */

/* For the signal BRS_SIG_SAVE_PAGE_OFFLINE */
typedef struct {
  MSF_INT16  instanceId;
  char      *url;
  char      *restrictions;
} brs_save_page_offline_t;

/* For the signal BRS_SIG_SET_OFFLINE_MODE */
typedef struct {
  MSF_INT16  instanceId;
  MSF_INT16  mode;
} brs_set_offline_mode_t;

/* For the signal BRS_SIG_DELETE_OFFLINE_PAGE */
typedef struct {
  char       *url;
} brs_delete_offline_page_t;

/* For the signal BRS_SIG_PAGE_NOT_FOUND_OFFLINE */
typedef struct {
  MSF_INT16  instance_id;
  char      *url;
} brs_page_not_found_offline_t;


/*
 * Called by any other module that wants to use the BRS module.
 */
void
BRSif_startInterface (void);


/**********************************************************************
 * Signal-sending API
 * These functions should be used by any other module that wants to
 * send a signal to the BRS module.
 **********************************************************************/

/*  */
void
BRSif_createInstance (MSF_UINT8 src,
                      MsfScreenHandle screenHandle,
                      int windowPositionX, int windowPositionY,
                      int windowSizeHeight, int windowSizeWidth,
                      char *applicationName);

/* */
void
BRSif_deleteInstance (MSF_UINT8 src, int instanceId);

/* */
void
BRSif_resizeWindow (MSF_UINT8 src, int instanceId,
                    int windowPositionX, int windowPositionY,
                    int windowSizeHeight, int windowSizeWidth);

/* */
void
BRSif_loadUrl (MSF_UINT8 src, int instanceId, int options, const char *url);

/* */
void
BRSif_activateDoElement (MSF_UINT8 src, int instanceId, int elementId);

/* */
void
BRSif_move (MSF_UINT8 src, int instanceId, int direction, int steps);

/* */
void
BRSif_reload (MSF_UINT8 src, int instanceId);

/* */
void
BRSif_stop (MSF_UINT8 src, int instanceId);

/* */
void
BRSif_navigationChange (MSF_UINT8 src, int instanceId, MSF_UINT16 elements);


#ifdef BRS_CFG_OFFLINE_PAGES 
/* */
void
BRSif_savePageOffline (MSF_UINT8 src, int instanceId, 
                       const char* url, const char *restrictions);

/* */
void
BRSif_setOfflineMode (MSF_UINT8 src, int instanceId, int mode);

/* */
void
BRSif_deleteOfflinePage (MSF_UINT8 src, const char* url);
#endif

/**********************************************************************
 * Conversion routines for all signals owned by this module.
 * None of these functions should be called directly by another module.
 **********************************************************************/

int
brs_cvt_create_instance (msf_dcvt_t *obj, brs_create_instance_t *p);

int
brs_cvt_created (msf_dcvt_t *obj, brs_created_t *p);

int
brs_cvt_delete_instance (msf_dcvt_t *obj, brs_delete_instance_t *p);

int
brs_cvt_resize_window (msf_dcvt_t *obj, brs_resize_window_t *p);

int
brs_cvt_load_url (msf_dcvt_t *obj, brs_load_url_t *p);

int
brs_cvt_activate_do_element (msf_dcvt_t *obj, brs_activate_do_element_t *p);

int
brs_cvt_move (msf_dcvt_t *obj, brs_move_t *p);

int
brs_cvt_reload (msf_dcvt_t *obj, brs_reload_t *p);

int
brs_cvt_stop (msf_dcvt_t *obj, brs_stop_t *p);

int
brs_cvt_status (msf_dcvt_t *obj, brs_status_t *p);

int
brs_cvt_error (msf_dcvt_t *obj, brs_error_t *p);

int
brs_cvt_document_info (msf_dcvt_t *obj, brs_document_info_t *p);

int
brs_cvt_do_elements (msf_dcvt_t *obj, brs_do_elements_t *p);

int
brs_cvt_element_focused (msf_dcvt_t *obj, brs_element_focused_t *p);

int
brs_cvt_navigation_change (msf_dcvt_t *obj, brs_navigation_change_t *p);


#ifdef BRS_CFG_OFFLINE_PAGES 
int
brs_cvt_save_page_offline (msf_dcvt_t *obj, brs_save_page_offline_t *p);

int
brs_cvt_set_offline_mode (msf_dcvt_t *obj, brs_set_offline_mode_t *p);

int
brs_cvt_delete_offline_page (msf_dcvt_t *obj, brs_delete_offline_page_t *p);

int
brs_cvt_page_not_found_offline (msf_dcvt_t *obj, brs_page_not_found_offline_t *p);
#endif

void *
brs_convert (MSF_UINT8 module, MSF_UINT16 signal, void *buffer);

void
brs_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);


#endif
