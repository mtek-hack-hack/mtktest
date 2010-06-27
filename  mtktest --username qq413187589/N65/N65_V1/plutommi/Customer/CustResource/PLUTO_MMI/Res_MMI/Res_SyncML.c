/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *    Res_SyncML.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file populates resource for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef _MMI_RES_SYNCML_C
#define _MMI_RES_SYNCML_C

#include "MMI_features.h"

#ifdef __SYNCML_SUPPORT__

#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "custom_mmi_default_value.h"
#include "SyncMLResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"


/*****************************************************************************
 * FUNCTION
 *  SyncMLResourceData
 * DESCRIPTION
 *  Populate all the resources required by SyncML application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SyncMLResourceData(void)
{

#ifndef __MMI_OP01_SYNCML_SETTING__
    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_MAIN,
                              MAIN_MENU_SERVICES_MENUID,
                              2,
                              MENU_ID_SYNCML_SYNC,
                              MENU_ID_SYNCML_SETTINGS,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_MENU, IMG_ID_SYNC_MENU));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_SYNC,
                              MENU_ID_SYNCML_MAIN,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_NOW, IMG_ID_SYNC_MENU));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_SETTINGS,
                              MENU_ID_SYNCML_MAIN,
                          #ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
                              5,
                          #else
                              4,
                          #endif
                              MENU_ID_SYNCML_PROFILE,
                              MENU_ID_SYNCML_APPLICATIONS,
                          #ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
                              MENU_ID_SYNCML_TYPE,
                          #endif
                              MENU_ID_SYNCML_REGULARITY,
                              MENU_ID_SYNCML_REPORT,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_SETTINGS, IMG_ID_SYNC_SETTINGS));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE,
                              MENU_ID_SYNCML_SETTINGS,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_PROFILE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_APPLICATIONS,
                              MENU_ID_SYNCML_SETTINGS,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_APPLICATIONS, 0));
#else
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
#endif /*__MMI_OP01_SYNCML_SETTING__*/

#ifndef __MMI_OP01_SYNCML_SETTING__
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_TYPE,
                              MENU_ID_SYNCML_SETTINGS,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_TYPE, 0));
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_REGULARITY,
                              MENU_ID_SYNCML_SETTINGS,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_REGULARITY, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_REPORT,
                              MENU_ID_SYNCML_SETTINGS,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_REPORT, 0));
#endif /* __MMI_OP01_SYNCML_SETTING__ */

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_OPTIONS,
                              0,
                              2,
                              MENU_ID_SYNCML_PROFILE_ACTIVATE,
                              MENU_ID_SYNCML_PROFILE_EDIT,
                              SHOW, NONMOVEABLE, DISP_LIST,															                              
                              STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_ACTIVATE,
                              MENU_ID_SYNCML_PROFILE_OPTIONS,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_GLOBAL_ACTIVATE, 0));

#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_SYNCML_SETTING__ */
    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_EDIT,
                              MENU_ID_SYNCML_PROFILE_OPTIONS,
                              5,
                              MENU_ID_SYNCML_PROFILE_EDIT_NAME,
                              MENU_ID_SYNCML_PROFILE_EDIT_SERVER,
                              MENU_ID_SYNCML_PROFILE_EDIT_CONTACT,
                              MENU_ID_SYNCML_PROFILE_EDIT_CALENDAR,
                              MENU_ID_SYNCML_PROFILE_EDIT_CONNECTION,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_GLOBAL_EDIT, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_EDIT_NAME,
                              MENU_ID_SYNCML_PROFILE_EDIT,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_PROFILE_NAME, IMG_ID_SYNC_PROFILE));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_EDIT_SERVER,
                              MENU_ID_SYNCML_PROFILE_EDIT,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_PROFILE_SERVER, IMG_ID_SYNC_SERVER));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_EDIT_CONTACT,
                              MENU_ID_SYNCML_PROFILE_EDIT,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_PROFILE_CONTACT, IMG_ID_SYNC_CONTACT));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_EDIT_CALENDAR,
                              MENU_ID_SYNCML_PROFILE_EDIT,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_PROFILE_CALENDAR, IMG_ID_SYNC_CALENDAR));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_EDIT_CONNECTION,
                              MENU_ID_SYNCML_PROFILE_EDIT,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_ID_SYNC_PROFILE_CONNECTION, IMG_ID_SYNC_CONNECTION));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_EDIT_NAME_OPTION,
                              0,
                              2,
                              MENU_ID_SYNCML_PROFILE_EDIT_NAME_DONE,
                              MENU_ID_SYNCML_PROFILE_EDIT_NAME_INPUT,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_EDIT_NAME_DONE,
                              MENU_ID_SYNCML_PROFILE_EDIT_NAME_OPTION,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_GLOBAL_DONE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_SYNCML_PROFILE_EDIT_NAME_INPUT,
                              MENU_ID_SYNCML_PROFILE_EDIT_NAME_OPTION,
                              0,
                              SHOW, NONMOVEABLE, DISP_LIST,
                              STR_GLOBAL_INPUT_METHOD, 0));
#endif /* __MMI_OP01_SYNCML_SETTING__ */

    ADD_APPLICATION_STRING2(STR_ID_SYNC_MENU,              "Synchronization",           "synchronization");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_MENU_SHORT_FORM,   "Sync.",                     "synchronization");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_NOW,               "Sync Now",                  "menu item: sync now");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_SETTINGS,          "Sync Settings",             "menu item: sync settings");   

    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROGRESS,          "Synchronizing",             "synchronizing");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_NO_PROFILE,        "No account!",               "no account!");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_EDIT_QUREY,        "Edit account now?",         "edit account now?");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROFILE,           "Account",                   "menu item: Account");

    ADD_APPLICATION_STRING2(STR_ID_SYNC_APPLICATIONS,      "Applications to Sync",      "menu item: applications to sync");
#ifndef __MMI_OP01_SYNCML_SETTING__    
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REGULARITY,        "Regular Sync",              "menu item: regular sync");
#endif /* __MMI_OP01_SYNCML_SETTING__ */

    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROFILE_NAME,      "Account Name",              "menu item: Account name");

#ifndef __MMI_OP01_SYNCML_SETTING__
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROFILE_SERVER,    "Server Settings",           "menu item: server settings");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROFILE_CONTACT,   "Contact Database Settings", "menu item: contact database settings");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROFILE_CALENDAR,  "Calendar Database Settings","menu item: calendar database settings");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROFILE_CONNECTION,"Connection Settings",       "menu item: connection settings");
#endif /* __MMI_OP01_SYNCML_SETTING__   */    
	
    ADD_APPLICATION_STRING2(STR_ID_SYNC_APP_PHB,           "Phonebook",                 "selection: phonebook");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_APP_TDL,           "To do list",                "selection: to do list");

#ifndef __MMI_OP01_SYNCML_SETTING__ 
    ADD_APPLICATION_STRING2(STR_ID_SYNC_APP_EMAIL,         "Email",                     "selection: email");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REGULARITY_NONE,   "None",                      "selection: none");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REGULARITY_DATA,   "When data is changed",      "selection: when data is changed");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REGULARITY_POWERON,"When handset is turned on", "selection: when handset is turned on");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REGULARITY_DAY,    "Every day",                 "selection: every day");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REGULARITY_WEEK,   "Every week",                "selection: every week");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REGULARITY_MONTH,  "Every month",               "selection: every month");
#endif /* __MMI_OP01_SYNCML_SETTING__ */

    ADD_APPLICATION_STRING2(STR_ID_SYNC_SERVER_ADDRESS,    "Server address",            "Server address");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_CONTACT_ADDRESS,   "Contact database address",  "Contact database address");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_CALENDAR_ADDRESS,  "Calendar database address", "Calendar database address");

#ifndef __MMI_OP01_SYNCML_SETTING__
    ADD_APPLICATION_STRING2(STR_ID_SYNC_BEARER,            "Local bearer",              "Local bearer");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_BEARER_USB,        "Data cable",                "selection: data cable");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_BEARER_BT,         "Bluetooth",                 "selection: bluetooth");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_BEARER_IRDA,       "Infrared",                  "selection: irda");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_TYPE,              "Sync Type",                 "menu item: sync type");
#endif /* __MMI_OP01_SYNCML_SETTING__ */

    ADD_APPLICATION_STRING2(STR_ID_SYNC_HINT_PHB_ONLY,     "Phonebook only",            "hint: Phonebook only");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_HINT_TDL_ONLY,     "To-do-list only",           "hint: To-do-list only");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_HINT_PHB_TDL,      "Phonebook and to-do-list",  "hint: Phonebook and to-do-list");

    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROXY_USAGE,        "Use Proxy",                "proxy");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROXY_SERVER,       "Proxy IP",                 "proxy");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROXY_PORT,         "Proxy Port",               "proxy");

    ADD_APPLICATION_STRING2(STR_ID_SYNC_PHB_BUSY,           "Phonebook busy now!",      "warning: phonebook busy");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_INCOMPLETE_PROFILE, "Incomplete account!",      "warning: incomplete account");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_NO_APPLICATION,     "No application!",          "no application!");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_BACKGROUND_QUERY,   "Do you want to abort the sync?\n Press Yes to abort or press No to keep the sync in the background.", "background sync");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PLEASE_WAIT,        "Synchronizing,\nplease wait","background sync");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_WAP_NOT_READY,      "Sync service not ready!",  "warning: wap not ready");

    ADD_APPLICATION_STRING2(STR_ID_SYNC_INVALID_CREDENTIAL, "Invalid credentials!",     "Invalid credentials!");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_MISSING_CREDENTIAL, "Missing credentials!",     "Missing credentials!");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PAYMENT_REQUIRED,   "Payment Required!",        "Payment Required!");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_DONE,               "Sync Done",                "Sync done");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_FAIL,               "Sync Unfinished\n(500)",   "Sync Unfinished");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_LOCALDB_FULL,       "Sync Unfinished,\nLocal device full!",       "Local device full!");            
    ADD_APPLICATION_STRING2(STR_ID_SYNC_CODE_FORBIDDEN,     "Synchronizing,\nRetry later!",               "Server busy!");            
    ADD_APPLICATION_STRING2(STR_ID_SYNC_INCOMPLETE_CMD,     "Sync Unfinished\n(412)",                     "Incomplete command!");            
    ADD_APPLICATION_STRING2(STR_ID_SYNC_SVR_DEVICE_FULL,    "Sync Unfinished,\nServer device full!",      "Server device full!");  
    ADD_APPLICATION_STRING2(STR_ID_SYNC_SERVICE_UNAVAILABLE,"Server busy,\nRetry later!",                 "Server busy!");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_DATASTORE_FAIL,     "Sync Unfinished,\nCheck Data store setting!","Data store failure!");            
    ADD_APPLICATION_STRING2(STR_ID_SYNC_SVR_FAIL,           "Sync Unfinished\n(511)",                     "Server failure!");            
    ADD_APPLICATION_STRING2(STR_ID_SYNC_ERR_OCCUR,          "Sync Unfinished\n(512)",                     "Error occurred!");            
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROTOCOL_UNSUPPORT, "Sync Unfinished\n(513)",                     "Protocol version not supported!");            
	ADD_APPLICATION_STRING2(STR_ID_SYNC_DEFAULT_FAIL,       "Sync Unfinished",                            "default string for unknown error");            


#ifndef __MMI_OP01_SYNCML_SETTING__
    ADD_APPLICATION_STRING2(STR_ID_SYNC_ALARM_EXPIRED_QUERY,"Sync alarm expired!\nDo you want start sync?", "sync regularity");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_POWER_ON_QUERY,     "Do you want start sync for this power on?",    "sync regularity");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_DATA_CHANGED_QUERY, "Data was changed!\nDo you want start sync?",   "sync regularity");
#endif /* __MMI_OP01_SYNCML_SETTING__ */

    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_LINK_ESTABLISHED,           "Connected",             "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_LINK_DISCONNECTED,          "Disconnected",          "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_RX_FAILED,                  "Receiving failed",      "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_TX_FAILED,                  "Sending failed",        "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_TASK_DATASTORE_SENDING,     "Sending to-do-list",    "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_CONTACT_DATASTORE_SENDING,  "Sending phonebook",     "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_TASK_DATASTORE_RECEIVED,    "Receiving to-do-list",  "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_CONTACT_DATASTORE_RECEIVED, "Receiving phonebook",   "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_TASK_DATASTORE_DONE,        "To-do-list sync done",  "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_CONTACT_DATASTORE_DONE,     "Phonebook sync done",   "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_TASK_DATASTORE_FAILED,      "To-do-list sync failed","Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_CONTACT_DATASTORE_FAILED,   "Phonebook sync failed", "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_LINK_REDIRECTED,            "URL redirected",        "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_SESSION_DONE,               "Sync session done",     "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_TASK_DATASTORE_UPDATING,    "Updating to-do-list",   "Progression info");
    ADD_APPLICATION_STRING2(STR_ID_PROGRESS_CONTACT_DATASTORE_UPDATING, "Updating phonebook",    "Progression info");

#ifndef __MMI_OP01_SYNCML_SETTING__
    ADD_APPLICATION_STRING2(STR_ID_SYNC_TWOWAY,             "Two-way Sync",                      "sync type: two way");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_BACKUP,             "Backup to server",                  "sync type: backup");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_RESTORE,            "Restore from server",               "sync type: restore");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_EXPORT,             "Export to server",                  "sync type: export");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_IMPORT,             "Import from server",                "sync type: import");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_BACKUP_WARNING,     "All remote records will be deleted before sync! Continue?", "sync type: backup");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_RESTORE_WARNING,    "All local records will be deleted before sync! Continue?", "sync type: restore");
#endif /* __MMI_OP01_SYNCML_SETTING__ */

    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT,             "Sync Report",                       "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_CON_OK,      "Contact done",                      "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_CAL_OK,      "Calendar done",                     "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_CON_NG,      "Contact unfinished",                "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_CAL_NG,      "Calendar unfinished",               "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_CON_CK,      "Please check contact settings",     "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_CAL_CK,      "Please check calendar settings",    "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_CON_NO,      "Contact not sync",                  "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_CAL_NO,      "Calendar not sync",                 "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_REPLACE,     "Replace",                           "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_SERVER,      "Server",                            "Sync Report");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPORT_CLIENT,      "Client",                            "Sync Report");

#ifdef __MMI_WLAN_FEATURES__
    ADD_APPLICATION_STRING2(STR_ID_SYNC_INVALID_DATA_ACCOUNT, "Invalid data account!", "Invalid data account!");
#endif

    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROFILE_ID1,        "Account 1",                "Account");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROFILE_ID2,        "Account 2",                "Account");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROFILE_ID3,        "Account 3",                "Account");

    ADD_APPLICATION_STRING2(STR_ID_SYNC_PROFILE_DEACTIVATED,"Account deactivated!",     "Account");

    ADD_APPLICATION_STRING2(STR_ID_SYNC_CONN_TYPE,          "Connection Type", "Connection");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_CONN_HTTP,          "HTTP", "Connection");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_CONN_WAP,           "WAP", "Connection");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_INVALID_INPUT,      "Invalid input!", "Connection");

#ifdef __MMI_SYNCML_CCA_SUPPORT__
    ADD_APPLICATION_STRING2(STR_ID_SYNC_REPLACE_CONFIRM,      "Do you want to replace this account?",                      "install setting");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_ERROR_PROFILE_IN_USE, "The target account is in use and can not be replaced!",     "install setting");
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */

#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
    ADD_APPLICATION_STRING2(STR_ID_SYNC_SAS_NOTIFICATION,    "Server Alerted Sync", "server alerted sync");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_SAS_CONTEXT_1,       "requires to start sync from your handset.", "server alerted sync");
    ADD_APPLICATION_STRING2(STR_ID_SYNC_SAS_CONTEXT_2,       "Do you want to aceept?", "server alerted sync");
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

    ADD_APPLICATION_IMAGE2(IMG_ID_SYNC_MENU,       CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\SyncML\\\\SML_Sync.pbm",     "Sync image");
    ADD_APPLICATION_IMAGE2(IMG_ID_SYNC_NOW,        CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\SyncML\\\\Synchronzing"__MMI_RES_TYPE_POPUP_SCREEN__, "Sync image");
    ADD_APPLICATION_IMAGE2(IMG_ID_SYNC_SETTINGS,   CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\SyncML\\\\SML_SyncSet.pbm",  "Sync image");
    ADD_APPLICATION_IMAGE2(IMG_ID_SYNC_CONTACT,    CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\SyncML\\\\SML_PHONEBOOK.pbm","Sync image");
    ADD_APPLICATION_IMAGE2(IMG_ID_SYNC_CALENDAR,   CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\SyncML\\\\SML_TODOLIST.pbm", "Sync image");
    ADD_APPLICATION_IMAGE2(IMG_ID_SYNC_PROFILE,    CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\DataAccount\\\\SV_ACCN.PBM", "Shared from GPRS Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_SYNC_SERVER,     CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\DataAccount\\\\SV_TYPE.PBM", "Shared from GPRS Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_SYNC_CONNECTION, CUST_IMG_PATH"\\\\MainLCD\\\\submenu\\\\SERVICES\\\\DataAccount\\\\SB_DATA.PBM", "Shared from GPRS Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_SYNC_USERNAME,   CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\DataAccount\\\\SV_NAME.PBM", "Shared from GPRS Data Account");
    ADD_APPLICATION_IMAGE2(IMG_ID_SYNC_PASSWORD,   CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\DataAccount\\\\SV_PASS.PBM", "Shared from GPRS Data Account");
}

#endif /* DEVELOPER_BUILD_FIRST_PASS */
#endif /* __SYNCML_SUPPORT__ */
#endif /* _MMI_RES_SYNCML_C */
