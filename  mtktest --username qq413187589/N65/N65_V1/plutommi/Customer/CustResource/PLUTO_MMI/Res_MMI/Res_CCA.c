#ifndef RES_CCA_C
#define RES_CCA_C
#include "MMI_features.h"
#ifdef __MMI_CCA_SUPPORT__

#include "MMIDataType.h"
#include "CustomCfg.h"
#include "CentralConfigAgentResDef.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif


#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"


void PopulateCCARes(void)
{
	/*Add Strings*/
	ADD_APPLICATION_STRING2(STR_ID_CCA_PROGRESS_TITLE, "New setting", "Configuration progressing title");
    ADD_APPLICATION_STRING2(STR_ID_CCA_PROGRESS_CONTENT, "Configuring system, please wait...", "Configuration progressing window content");
    ADD_APPLICATION_STRING2(STR_ID_CCA_PREINFO_TITLE, "New setting", "Settings info title");
    ADD_APPLICATION_STRING2(STR_ID_CCA_PREINFO_CONTENT, "Settings for:", "Settings info window content");
    ADD_APPLICATION_STRING2(STR_ID_CCA_POSTINFO_TITLE, "Summary report", "Summary report title");
    ADD_APPLICATION_STRING2(STR_ID_CCA_NEW_SETTING_CONF_TITLE, "New setting", "New setting confirmation title");
    ADD_APPLICATION_STRING2(STR_ID_CCA_NEW_SETTING_CONF_CONTENT, "Install new setting", "New setting confirmation content");
    ADD_APPLICATION_STRING2(STR_ID_CCA_AUTH_TITLE, "New setting", "PIN auth title");
    ADD_APPLICATION_STRING2(STR_ID_CCA_AUTH_CONTENT, "Please enter PIN:", "PIN auth content");

    ADD_APPLICATION_STRING2(STR_ID_CCA_CONFIGURED, "Configured", "Configured");
    ADD_APPLICATION_STRING2(STR_ID_CCA_INVALID_SETTING, "Invalid setting", "Invalid setting");
    ADD_APPLICATION_STRING2(STR_ID_CCA_SETTING_SKIPPED, "Skipped", "Setting skipped");
    ADD_APPLICATION_STRING2(STR_ID_CCA_UNSUPPORTED_SETTING, "Unsupported setting", "Unsupported setting");
    ADD_APPLICATION_STRING2(STR_ID_CCA_CORRUPTED_SETTING, "Corrupted setting", "Corrupted setting");
    ADD_APPLICATION_STRING2(STR_ID_CCA_MISSING_DATA, "Incomplete setting", "Incomplete setting");

    //ADD_APPLICATION_STRING2(STR_ID_CCA_POSTINFO_CONTENT_SUCCEED, "Summary report content (succeed)", "Configuration complete.");
    //ADD_APPLICATION_STRING2(STR_ID_CCA_POSTINFO_CONTENT_FAIL, "Summary report content (fail)", "Configuration failed.");
    //ADD_APPLICATION_STRING2(STR_ID_CCA_POSTINFO_CONTENT_SUCCEEDwError, "Summary report content (succeed with error)", "Configuration complete with error.");

    ADD_APPLICATION_STRING2(STR_ID_CCA_INSTALL_SETTING, "Install setting", "Install setting");
    ADD_APPLICATION_STRING2(STR_ID_CCA_REPLACE_SETTING, "Replace setting", "Replace setting");
    ADD_APPLICATION_STRING2(STR_ID_CCA_SKIP_PROFILE, "Skip this profile?", "Skip this profile?");
    ADD_APPLICATION_STRING2(STR_ID_CCA_PROFILE_IN_USE, "Profile in use", "Profile in use");
    ADD_APPLICATION_STRING2(STR_ID_CCA_SKIP, "Skip", "Skip");
    ADD_APPLICATION_STRING2(STR_ID_CCA_ABORT_ASK, "Cancel?", "Cancel?");

    ADD_APPLICATION_STRING2(STR_ID_CCA_MEMFULL, "Memory full", "Memory full");
    ADD_APPLICATION_STRING2(STR_ID_CCA_PROFILE, "Profile", "Profile");
    ADD_APPLICATION_STRING2(STR_ID_CCA_NEW_SETTING, "New setting", "New setting");
    ADD_APPLICATION_STRING2(STR_ID_CCA_PIN_NO_MORE_RETRY, "Authentication failed", "No more retry prompt");
    ADD_APPLICATION_STRING2(STR_ID_CCA_PIN_RETRY, "Incorrect PIN, please try again", "Incorrect PIN, please try again");
    ADD_APPLICATION_STRING2(STR_ID_CCA_PIN_EMPTY, "PIN must be entered", "PIN must be entered");

    ADD_APPLICATION_STRING2(STR_ID_CCA_NOAPP, "No supported Application", "No supported application");
    ADD_APPLICATION_STRING2(STR_ID_CCA_DTACCT, "Data account", "Data account application name");
    ADD_APPLICATION_STRING2(STR_ID_CCA_BROWSER, "Browser", "Browser application name");
    ADD_APPLICATION_STRING2(STR_ID_CCA_MMS, "MMS", "MMS application name");
    ADD_APPLICATION_STRING2(STR_ID_CCA_SIP, "VoIP", "SIP application name");
    ADD_APPLICATION_STRING2(STR_ID_CCA_WLAN, "Wireless LAN", "WLAN application name");
    ADD_APPLICATION_STRING2(STR_ID_CCA_FOTA, "Firmware upgrade", "FOTA application name");
    ADD_APPLICATION_STRING2(STR_ID_CCA_EMAIL, "Email", "Email application name");
    ADD_APPLICATION_STRING2(STR_ID_CCA_IMPS, "Instant message", "IMPS application name");
    ADD_APPLICATION_STRING2(STR_ID_CCA_SYNCMLDS, "Synchronization", "SyncML DS application name");
    ADD_APPLICATION_STRING2(STR_ID_CCA_SYNCMLDM, "Device management", "SyncML DM application name");
    ADD_APPLICATION_STRING2(STR_ID_CCA_IS_SETTING_ABORTED, "New setting is aborted", "New setting is aborted");

    /* #ifdef __MMI_DUAL_SIM__ */
    ADD_APPLICATION_STRING2(STR_ID_CCA_NEW_SIM1_SETTING, "New SIM1 setting", "New SIM1 setting");
    ADD_APPLICATION_STRING2(STR_ID_CCA_NEW_SIM2_SETTING, "New SIM2 setting", "New SIM2 setting");
    ADD_APPLICATION_STRING2(STR_ID_CCA_INSTALL_NEW_SIM1_SETTING, "Install SIM1 Setting?", "Install SIM1 Setting?");
    ADD_APPLICATION_STRING2(STR_ID_CCA_INSTALL_NEW_SIM2_SETTING, "Install SIM2 setting?", "Install SIM2 setting?");
    /* #endif  __MMI_DUAL_SIM__ */

	/*Add Image*/
	//ADD_APPLICATION_IMAGE2(IMG_ID_VRSI_APP,CUST_IMG_PATH"\\\\MainLCD\\\\VoiceRecg\\\\SB_Speak.pbm","Main Icon for Voice Command App");
	ADD_APPLICATION_IMAGE2(IMG_ID_CCA_MAIN_ICON, CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CCA.png","Main Icon for CCA");  
}


#endif /*END #ifdef DEVELOPER_BUILD_FIRST_PASS*/
#endif /*END #ifdef __MMI_CCA_SUPPORT__ */
#endif /*END #ifndef RES_CCA_C*/
