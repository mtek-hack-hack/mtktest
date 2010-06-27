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

#include "msf_cfg.h"
#include "stk_cfg.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_cmmn.h"
#include "msf_wid.h"
#include "msf_log.h"
#include "msf_int.h"
#include "msf_lib.h"

#include "stk_dlg.h"
#include "stk_rc.h"

#include "bra_if.h"

/* string constants for authentication dialog */
#define  STK_DLG_STRING_OK            MSF_WIDGET_STRING_GET_PREDEFINED (STK_STR_ID_OK)
#define  STK_DLG_STRING_EXIT          MSF_WIDGET_STRING_GET_PREDEFINED (STK_STR_ID_EXIT)
#define  STK_DLG_STRING_TITLE_SERVER  MSF_WIDGET_STRING_GET_PREDEFINED (STK_STR_ID_TITLE_SERVER)
#define  STK_DLG_STRING_TITLE_PROXY   MSF_WIDGET_STRING_GET_PREDEFINED (STK_STR_ID_TITLE_PROXY)
#define  STK_DLG_STRING_USERNAME      MSF_WIDGET_STRING_GET_PREDEFINED (STK_STR_ID_USERNAME)
#define  STK_DLG_STRING_PASSWORD      MSF_WIDGET_STRING_GET_PREDEFINED (STK_STR_ID_PASSWORD)
#define  STK_DLG_STRING_REALM_LABEL   MSF_WIDGET_STRING_GET_PREDEFINED (STK_STR_ID_REALM_LABEL)
#define  STK_DLG_STRING_NON_SECURE    MSF_WIDGET_STRING_GET_PREDEFINED (STK_STR_ID_NON_SECURE)
#define  STK_DLG_STRING_SAVE_PASSWORD MSF_WIDGET_STRING_GET_PREDEFINED (STK_STR_ID_SAVE_PASSWORD)
#define  STK_DLG_STRING_SAVE_USERNAME MSF_WIDGET_STRING_GET_PREDEFINED (STK_STR_ID_SAVE_USERNAME)

#define  STK_DLG_STRCONV(a)  MSF_WIDGET_STRING_CREATE(MSF_MODID_STK, a,MsfUtf8, strlen(a)+1, 0)

#define  STK_DLG_BUFSIZE          50
  
/************************************************************
 * Widget variables
 ************************************************************/

/* authentication form*/
typedef struct stk_dlg_auth_form_st {
  MsfScreenHandle screen_handle;
  MsfWindowHandle window_handle;

  MsfActionHandle action_ok;
  MsfActionHandle action_exit;

  MsfGadgetHandle gadget_ti_UserName;
  MsfGadgetHandle gadget_ti_Password;
  MsfGadgetHandle gadget_string_UserName;
  MsfGadgetHandle gadget_string_Password;
  MsfGadgetHandle gadget_string_RealmLabel;
  MsfGadgetHandle gadget_string_RealmValue;  
  MsfGadgetHandle gadget_string_Warning;
  MsfGadgetHandle gadget_sg_options;
  
  MsfStringHandle string_ok;
  MsfStringHandle string_exit;
  MsfStringHandle string_window_title;
  MsfStringHandle string_UserName;
  MsfStringHandle string_Password;
  MsfStringHandle string_RealmLabel;
  MsfStringHandle string_RealmValue;
  MsfStringHandle string_Warning;
  MsfStringHandle string_SaveUsername;
  MsfStringHandle string_SavePassword;
  MsfStringHandle stringEmpty;
  
  MSF_UINT8       module;
  int             requestId;
} stk_dlg_auth_form_t;

static stk_dlg_auth_form_t *stk_dlg_auth_form;

/************************************************************
 * Local functions
 ************************************************************/

#ifndef WAP_SUPPORT

static MsfWindowHandle 
stk_dlg_create_auth_form(int authType, const char *realm,
                         const char *username, int warnings)
{
  MsfSize         displaySize;
  MsfSize         textInputSize = {20,150};
  MsfSize         stringSize = {20,75};
  MsfSize         warningSize = {20,230};
  MsfSize			    selectGroupSize = {40,230};
  MsfPosition     stringPos, textInputPos, selectGroupPos;
  MsfDeviceProperties properties;
  MsfStringHandle strHandle;
  
  MSF_WIDGET_DEVICE_GET_PROPERTIES(&properties);
  displaySize = properties.displaySize;
  
  /* create msf strings*/
  stk_dlg_auth_form->string_ok           = STK_DLG_STRING_OK;
  stk_dlg_auth_form->string_exit         = STK_DLG_STRING_EXIT;
  if (authType == STK_AUTH_SERVER)
    stk_dlg_auth_form->string_window_title = STK_DLG_STRING_TITLE_SERVER;
  else
    stk_dlg_auth_form->string_window_title = STK_DLG_STRING_TITLE_PROXY;
  stk_dlg_auth_form->string_UserName     = STK_DLG_STRING_USERNAME;
  stk_dlg_auth_form->string_Password     = STK_DLG_STRING_PASSWORD;
  stk_dlg_auth_form->string_RealmLabel   = STK_DLG_STRING_REALM_LABEL;
  stk_dlg_auth_form->string_RealmValue   = STK_DLG_STRCONV (realm);
  stk_dlg_auth_form->string_Warning      = STK_DLG_STRING_NON_SECURE; 
  stk_dlg_auth_form->string_SavePassword = STK_DLG_STRING_SAVE_PASSWORD;
  stk_dlg_auth_form->string_SaveUsername = STK_DLG_STRING_SAVE_USERNAME;
  stk_dlg_auth_form->stringEmpty         = STK_DLG_STRCONV ("");

  stk_dlg_auth_form->window_handle = 
    MSF_WIDGET_FORM_CREATE (MSF_MODID_STK,&displaySize, 0x8000, 0);
  MSF_WIDGET_SET_TITLE (stk_dlg_auth_form->window_handle,
                        stk_dlg_auth_form->string_window_title);
  MSF_WIDGET_WINDOW_SET_PROPERTIES (stk_dlg_auth_form->window_handle, 
                                    MSF_WINDOW_PROPERTY_TITLE);

  /*Action OK*/
  stk_dlg_auth_form->action_ok = 
    MSF_WIDGET_ACTION_CREATE (MSF_MODID_STK, stk_dlg_auth_form->string_ok, MsfOk, 
                              3, MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION (stk_dlg_auth_form->window_handle, stk_dlg_auth_form->action_ok);
  
  /*Action EXIT*/
  stk_dlg_auth_form->action_exit = 
    MSF_WIDGET_ACTION_CREATE (MSF_MODID_STK, stk_dlg_auth_form->string_exit, MsfExit, 
                              3, MSF_ACTION_PROPERTY_ENABLED);
  MSF_WIDGET_ADD_ACTION (stk_dlg_auth_form->window_handle, stk_dlg_auth_form->action_exit);


  stringPos.x = 5;
  stringPos.y = 10;

  /*Gadget Warning*/ 
  if (warnings & STK_AUTH_WARNING_NON_SECURE) {
   
    stk_dlg_auth_form->gadget_string_Warning = 
      MSF_WIDGET_STRING_GADGET_CREATE (MSF_MODID_STK, stk_dlg_auth_form->string_Warning, 
                                      &warningSize, 1, 0x8000, 0);
    MSF_WIDGET_WINDOW_ADD_GADGET (stk_dlg_auth_form->window_handle, 
                                  stk_dlg_auth_form->gadget_string_Warning, 
                                  &stringPos, 0);     
    MSF_WIDGET_GADGET_SET_PROPERTIES (stk_dlg_auth_form->gadget_string_Warning, 0);

    stringPos.y = (MSF_INT16)(stringPos.y + stringSize.height + 10);
  } 
  else {
    stk_dlg_auth_form->gadget_string_Warning = 0;
  }

  /*Gadget Realm*/  
  stk_dlg_auth_form->gadget_string_RealmLabel = 
    MSF_WIDGET_STRING_GADGET_CREATE (MSF_MODID_STK, stk_dlg_auth_form->string_RealmLabel, 
                                    &stringSize, 1, 0x8000, 0);
  MSF_WIDGET_GADGET_SET_PROPERTIES (stk_dlg_auth_form->gadget_string_RealmLabel, 0);
  MSF_WIDGET_WINDOW_ADD_GADGET (stk_dlg_auth_form->window_handle, 
                                stk_dlg_auth_form->gadget_string_RealmLabel, 
                                &stringPos, 0);

  textInputPos.x = (MSF_INT16)(stringSize.width + 10);
  textInputPos.y = stringPos.y;
  stk_dlg_auth_form->gadget_string_RealmValue = 
    MSF_WIDGET_STRING_GADGET_CREATE (MSF_MODID_STK, stk_dlg_auth_form->string_RealmValue, 
                                     &textInputSize, 1, 0x8000, 0);
  MSF_WIDGET_GADGET_SET_PROPERTIES (stk_dlg_auth_form->gadget_string_RealmValue, 0);
  MSF_WIDGET_WINDOW_ADD_GADGET (stk_dlg_auth_form->window_handle, 
                                stk_dlg_auth_form->gadget_string_RealmValue, 
                                &textInputPos, 0);

  /*Gadget UserName*/
  stringPos.y = (MSF_INT16)(stringPos.y + stringSize.height + 5);
  stk_dlg_auth_form->gadget_string_UserName = 
    MSF_WIDGET_STRING_GADGET_CREATE (MSF_MODID_STK, stk_dlg_auth_form->string_UserName, &stringSize, 
                                     1, 0x8000, 0);
  MSF_WIDGET_GADGET_SET_PROPERTIES(stk_dlg_auth_form->gadget_string_UserName, 0);
  MSF_WIDGET_WINDOW_ADD_GADGET (stk_dlg_auth_form->window_handle, 
                                stk_dlg_auth_form->gadget_string_UserName, &stringPos, 
                                0);

  textInputPos.y = stringPos.y;
 
  strHandle = STK_DLG_STRCONV (((username != NULL) ? username : "" ));
  stk_dlg_auth_form->gadget_ti_UserName = 
    MSF_WIDGET_TEXT_INPUT_CREATE (MSF_MODID_STK, 0, strHandle, MsfText, 20, 1, 
                                  &textInputSize, 0x8000, 0);
  MSF_WIDGET_RELEASE (strHandle);

  MSF_WIDGET_GADGET_SET_PROPERTIES (stk_dlg_auth_form->gadget_ti_UserName, 
                                    MSF_GADGET_PROPERTY_BORDER | 
                                    MSF_GADGET_PROPERTY_FOCUS);
  MSF_WIDGET_WINDOW_ADD_GADGET (stk_dlg_auth_form->window_handle, 
                                stk_dlg_auth_form->gadget_ti_UserName, &textInputPos, 
                                0);

  /* Gadget Password*/
  stringPos.y = (MSF_INT16)(stringPos.y + stringSize.height + 5);
  stk_dlg_auth_form->gadget_string_Password = 
    MSF_WIDGET_STRING_GADGET_CREATE (MSF_MODID_STK, stk_dlg_auth_form->string_Password, 
                                     &stringSize, 1, 0x8000, 0);
  MSF_WIDGET_GADGET_SET_PROPERTIES (stk_dlg_auth_form->gadget_string_Password, 0);
  MSF_WIDGET_WINDOW_ADD_GADGET (stk_dlg_auth_form->window_handle, 
                                stk_dlg_auth_form->gadget_string_Password, &stringPos, 
                                0);

  textInputPos.y = stringPos.y;
  stk_dlg_auth_form->gadget_ti_Password = 
    MSF_WIDGET_TEXT_INPUT_CREATE (MSF_MODID_STK, 0,0,MsfPasswordText, 20,
                                  1, &textInputSize, 0x8000,0);
  MSF_WIDGET_GADGET_SET_PROPERTIES (stk_dlg_auth_form->gadget_ti_Password, 
                                    MSF_GADGET_PROPERTY_BORDER | 
                                    MSF_GADGET_PROPERTY_FOCUS);
  MSF_WIDGET_WINDOW_ADD_GADGET (stk_dlg_auth_form->window_handle, 
                                stk_dlg_auth_form->gadget_ti_Password, &textInputPos, 
                                0);
  
  /*Gadget options*/
  selectGroupPos.x = stringPos.x;
	selectGroupPos.y = (MSF_INT16)(stringPos.y + stringSize.height + 5);;
	stk_dlg_auth_form->gadget_sg_options = MSF_WIDGET_SELECTGROUP_CREATE(
                        MSF_MODID_STK, MsfMultipleChoice, &selectGroupSize, 0,
                        MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_ICON, 
                        0x8000, 0);

	MSF_WIDGET_CHOICE_SET_ELEMENT(stk_dlg_auth_form->gadget_sg_options, 0, 
                                stk_dlg_auth_form->string_SavePassword, 
                                stk_dlg_auth_form->stringEmpty, 0, 0, 1); 
  	
  MSF_WIDGET_CHOICE_SET_ELEMENT(stk_dlg_auth_form->gadget_sg_options, 1, 
                                stk_dlg_auth_form->string_SaveUsername, 
                                stk_dlg_auth_form->stringEmpty, 0, 0, 1); 
  
	MSF_WIDGET_GADGET_SET_PROPERTIES(stk_dlg_auth_form->gadget_sg_options, 
                     MSF_GADGET_PROPERTY_BORDER | MSF_GADGET_PROPERTY_FOCUS);
	MSF_WIDGET_WINDOW_ADD_GADGET(stk_dlg_auth_form->window_handle, 
                               stk_dlg_auth_form->gadget_sg_options, 
                               &selectGroupPos, 0);

  return stk_dlg_auth_form->window_handle;
}

#endif

static void
stk_dlg_delete_auth_form (void)  
{ 
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->gadget_ti_UserName);
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->gadget_ti_Password);
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->gadget_string_UserName);
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->gadget_string_Password);
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->gadget_string_RealmLabel);
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->gadget_string_RealmValue);
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->gadget_string_Warning);
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->gadget_sg_options);

  MSF_WIDGET_RELEASE (stk_dlg_auth_form->string_RealmValue);
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->stringEmpty);

  MSF_WIDGET_RELEASE (stk_dlg_auth_form->action_ok);
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->action_exit);

  MSF_WIDGET_RELEASE (stk_dlg_auth_form->window_handle);
  MSF_WIDGET_RELEASE (stk_dlg_auth_form->screen_handle);
  
  MSF_MEM_FREE(MSF_MODID_STK, stk_dlg_auth_form);
  stk_dlg_auth_form = NULL;
}


static void
stk_dlg_str_extract(MsfGadgetHandle textHandle,char* buf,int buflen)
{
  MsfStringHandle msfStr;

  buf[buflen - 1] = 0;
  msfStr= MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_STK, textHandle, 0);
  MSF_WIDGET_STRING_GET_DATA (msfStr, buf, MsfUtf8);
  MSF_WIDGET_RELEASE (msfStr); 
}


/************************************************************
 * Exported function
 ************************************************************/

void
stk_dlg_init (void)
{
  stk_dlg_auth_form = NULL;
}

void
stk_dlg_terminate (void)
{
  if (stk_dlg_auth_form != NULL)
    stk_dlg_delete_auth_form ();
}

void
stk_dlg_request_auth (MSF_UINT8 module, int requestId, int authType, 
                      const char *realm, const char* username, int warnings)
{
  extern void WPSif_httpAuthIndication(MSF_UINT8 src, int requestId, int authType,
                                       const char *realm, const char *username, int warnings);

  if(module == MSF_MODID_WPS)
  {
    WPSif_httpAuthIndication(MSF_MODID_STK, requestId, authType, realm, username, warnings);
    return;
  }
  BRAif_showAuthDialog(module, requestId, authType, realm, username, warnings);
}

void
stk_dlg_widget_action (msf_widget_action_t *widget_action)
{  
  MSF_UINT32 action = widget_action->action;
  char *buf, *username, *password;
  int options = 0;

#ifdef WAP_SUPPORT
  if(widget_action->handle == 0xffffffff)
  {
  	 extern char* wps_get_auth_password (int requestId);
  	 extern char* wps_get_auth_username (int requestId);
    /* access the username/password in WPS request info */
    int requestId = (int)widget_action->action;    
    stk_dlg_auth_credentials (MSF_MODID_WPS, requestId, (const char*)wps_get_auth_username(requestId), (const char*)wps_get_auth_password(requestId), 0);
  }
  else if(widget_action->handle == 0xfffffffe)
  {
    /* abort the authentication */
    int requestId = (int)widget_action->action;   
    stk_dlg_auth_credentials (MSF_MODID_WPS, requestId, NULL, NULL, 0);
  }
#endif
  
  if (stk_dlg_auth_form == NULL)
    return;
  if (action == stk_dlg_auth_form->action_ok){  
    buf = MSF_MEM_ALLOC (MSF_MODID_STK, STK_DLG_BUFSIZE);
    
    stk_dlg_str_extract (stk_dlg_auth_form->gadget_ti_UserName, buf, STK_DLG_BUFSIZE);
    username = msf_cmmn_strdup (MSF_MODID_STK, buf);
    
    stk_dlg_str_extract (stk_dlg_auth_form->gadget_ti_Password, buf, STK_DLG_BUFSIZE);
    password = msf_cmmn_strdup (MSF_MODID_STK, buf);
      
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (stk_dlg_auth_form->gadget_sg_options, 0) 
      & MSF_CHOICE_ELEMENT_SELECTED ) {
      options |= STK_AUTH_OPTIONS_SAVE_USERNAME_AND_PASSWORD;
    } 
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (stk_dlg_auth_form->gadget_sg_options, 1) 
        & MSF_CHOICE_ELEMENT_SELECTED ) 
    {
      options |= STK_AUTH_OPTIONS_SAVE_USERNAME;
    }

    stk_dlg_auth_credentials (stk_dlg_auth_form->module,stk_dlg_auth_form->requestId,
                            username, password, options);
    MSF_MEM_FREE (MSF_MODID_STK, username);
    MSF_MEM_FREE (MSF_MODID_STK, password);
    MSF_MEM_FREE (MSF_MODID_STK, buf);
    stk_dlg_delete_auth_form();
  }
  else if (action == stk_dlg_auth_form->action_exit){
    stk_dlg_auth_credentials (stk_dlg_auth_form->module, stk_dlg_auth_form->requestId, 
                            NULL, NULL, 0);
    stk_dlg_delete_auth_form();
  }
}

