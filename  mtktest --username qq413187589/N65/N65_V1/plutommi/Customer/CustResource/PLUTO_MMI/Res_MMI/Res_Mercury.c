#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "GlobalMenuItems.h"
#include "PhoneBookDef.h"
#include "SettingDefs.h"
#include "NetworkSetupGProt.h"
#include "CallSetUpEnum.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __MMI_UCM__
#include "UCMResDef.h"
#endif /* __MMI_UCM__ */

#include "MTPNP_AD_resdef.h"

#include "CallmanagementIdDef.h"
#include "MessagesresourceData.H"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

typedef enum
{
    MENU_ENUM_DM_SETTING,
    MENU_ENUM_PHONE_SETTING,

    MENU_ENUM_TOTAL_SETTING
} E_MTPNP_SETTING;

typedef enum
{
    MENU_ENUM_SETTING_DUALCARD,
    MENU_ENUM_SETTING_CARD1,
    MENU_ENUM_SETTING_CARD2,
    MENU_ENUM_SETTING_FLIGHT,
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    MENU_ENUM_SETTING_QUERY,
#endif                          /* __DM_PWR_ON_QUERY_SUPPORT__ */

    MENU_ENUM_TOTAL_DM_SETTING
} E_MTPNP_DM_SETTING;

#ifdef __DM_PWR_ON_QUERY_SUPPORT__
typedef enum
{
    MENU_ENUM_QUERY_DUALCARD,
    MENU_ENUM_QUERY_CARD1,
    MENU_ENUM_QUERY_CARD2,
    MENU_ENUM_QUERY_FLIGHT,

    MENU_ENUM_TOTAL_QUERY
} E_MTPNP_DM_QUERY;
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */

typedef enum
{
    MENU_ENUM_CTA_QUERY_CARD1,
    MENU_ENUM_CTA_QUERY_CARD2,
    MENU_ENUM_CTA_QUERY_FLIGHT,

    MENU_ENUM_TOTAL_CTA_QUERY
} E_MTPNP_DM_CTA_QUERY;

typedef enum
{
    MTPNP_ENUM_PHBEXTRA,

    MTPNP_ENUM_TOTAL_PHONE_SETTING
} E_MTPNP_PHONE_SETTING;

typedef enum
{
#ifndef __MMI_REMOVE_CALLER_ID__
    MENU_ENUM_SLAVE_CALL_ID,
#endif                          /* __MMI_REMOVE_CALLER_ID__ */
    MENU_ENUM_SLAVE_CALL_WAIT,
    MENU_ENUM_SLAVE_CALL_FORWARD,
    MENU_ENUM_SLAVE_CALL_BARRING,
    MENU_ENUM_SLAVE_LINE_SWITCH,

    MENU_ENUM_TOTAL_CALL_SETTING
} E_MTPNP_CALL_SETTING;

typedef enum
{
    MENU_ENUM_CALL_HISTORY_MISSED,
    MENU_ENUM_CALL_HISTORY_DIALED,
    MENU_ENUM_CALL_HISTORY_RECEIVED,
    MENU_ENUM_CALL_HISTORY_DELETE,
    MENU_ENUM_CALL_HISTORY_CALLTIME,
    MENU_ENUM_CALL_HISTORY_CALLCOST,
    MENU_ENUM_CALL_HISTORY_SMSCOUNTER,
#ifdef __MMI_GPRS_FEATURES__
    MENU_ENUM_CALL_HISTORY_GPRS_COUNTER,
#endif
    MENU_ENUM_TOTAL_CALL_HISTORY
} E_MTPNP_CALLHISTORY;

typedef enum
{
    MTPNP_ENUM_CARD2_PIN_LOCK,
    MTPNP_ENUM_CARD2_FDN_MAIN,
    MTPNP_ENUM_CARD2_CHANGE_PASSWORD,

    MTPNP_ENUM_TOTAL_SECURITY_SETTING
} E_MTPNP_SECURITY_SETTING;

typedef enum
{
    MTPNP_ENUM_CARD1_SECSET,
    MTPNP_ENUM_CARD2_SECSET,
    MTPNP_ENUM_PHONE_LOCK,
#ifdef __MMI_AUTO_KEYPAD_LOCK__
    MTPNP_ENUM_AKPL_TIME,
#endif
    MTPNP_ENUM_CHANGE_PASSWORD,
    MTPNP_ENUM_TOTAL_DM_SECSET
} E_MTPNP_DM_SECSET;

typedef enum
{
    MTPNP_ENUM_CHANGE_PIN1,
    MTPNP_ENUM_CHANGE_PIN2,

    MTPNP_ENUM_TOTAL_CHANGE_PASSWORD
} E_MTPNP_CHANGE_PASSWORD;

/* plmn begin */
typedef enum
{
    MTPNP_ENUM_SELECTION_MODE,
    MTPNP_ENUM_PREFERRED_NETWORKS,
    MTPNP_ENUM_GPRS_CONNECTION,

    MTPNP_ENUM_TOTAL_NETWORK_SETUP
} E_MTPNP_NETWORK_SETUP;

typedef enum
{
    MTPNP_ENUM_SELECTION_MODE_AUTOMATIC,
    MTPNP_ENUM_SELECTION_MODE_MANUAL,
#ifdef __MANUAL_MODE_NW_SEL__
    MTPNP_ENUM_SELECTION_MODE_CHOICE,
#endif

    MTPNP_ENUM_TOTAL_SELECTION_MODE
} E_MTPNP_SELECTION_MODE;
/* plmn end */

/* cell broadcast messages begin */
typedef enum
{
    MTPNP_ENUM_CB_SERVICE,
    MTPNP_ENUM_CB_READ_MESSAGE,
    MTPNP_ENUM_CB_LANGUAGE,
    MTPNP_ENUM_CB_CHANNELS,

    MTPNP_ENUM_TOTAL_CB_MESSAGES
} E_MTPNP_CB_MESSAGES;
/* cell broadcast messages end */

/* message setup begin */
typedef enum
{
    MTPNP_ENUM_SIM1_MSG_SETUP,
    MTPNP_ENUM_SIM2_MSG_SETUP,
#ifndef __MMI_UNIFIED_MESSAGE__
    MTPNP_ENUM_SHOW_STYLE,
#endif /* __MMI_UNIFIED_MESSAGE__ */
    MTPNP_ENUM_TOTAL_DM_MSG_SETUP
} E_MTPNP_DM_MSG_SETUP;

typedef enum
{
    MTPNP_ENUM_PROFILE_SETTING,
    MTPNP_ENUM_COMMONSETTING,
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
    MESSAGES_SLAVE_MENU_MEMSTATUS,
#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    SETUP_SLAVE_MENU_PREFEREDSTORAGE,
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#endif
    MTPNP_ENUM_TOTAL_MESSAGES_SETUP
} E_MTPNP_MESSAGES_SETUP;
/* message setup end */

typedef enum
{
    MTPNP_ENUM_EM_CHK_RSSI,
    MTPNP_ENUM_EM_CALLBACK_PSN,
    MTPNP_ENUM_EM_ASSERT_SLAVE,

    MENU_ENUM_HELPINFO,

    MTPNP_ENUM_EM_TOTAL
} E_MTPNP_EM_DUALMODE;

typedef enum
{
    MTPNP_OUTBOX_SEND_OPT_SIM2SEND_ONLY,
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
    MTPNP_OUTBOX_SEND_OPT_SIM2SEND_TO_MANY,
#endif 
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
    MTPNP_OUTBOX_SEND_OPT_SIM2SEND_BY_GROUP,
#endif 
    NUM_MESSAGES_OUTBOXSIM2SEND_MENU
} E_MTPNP_MESSAGES_OUTBOXSEND_MENU;

/* Populate the mercury string : note: the function can be auto generate by RefListMerger.exe*/
static void Mercury_StrPopulate(void)
{
    /* engineer/factory mode begin */
    ADD_APPLICATION_STRING2(STRING_MTPNP_EM, "Dualmode Engineer Mode", "Dualmode Engineer Mode");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CHK_RSSI, "Check rssi", "Check rssi");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PSN_CALLBACK, "PSN Callback", "PSN Callback");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ASSERT_SLAVE, "Assert slave", "Assert slave");
    ADD_APPLICATION_STRING2(STRING_MTPNP_FM_COMM, "DG Communication", "Factory Mode DG Communication");
    ADD_APPLICATION_STRING2(STRING_MTPNP_FM_MIC, "Slave Mic", "Factory Mode Slave Mic");
    ADD_APPLICATION_STRING2(STRING_MTPNP_FM_SPEAKER, "Slave Speaker", "Factory Mode Slave Speaker");
    ADD_APPLICATION_STRING2(STRING_MTPNP_FM_RECEIVER, "Slave Receiver", "Factory Mode Slave Receiver");
    ADD_APPLICATION_STRING2(STRING_MTPNP_FM_HEADSET, "Slave Headset", "Factory Mode Slave Headset");
    /* engineer/factory mode end */

    ADD_APPLICATION_STRING2(STRING_MTPNP_EM_OP_SIDE, "Set Side", "Select Master or Slave");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MASTER_TEST, "Master", "Master");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SLAVE_TEST, "Slave", "Slave");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SWITCH_SAME_MODE, "Switch to the same mode", "Switch to the same mode");
    ADD_APPLICATION_STRING2(STRING_MTPNP_HELPINFO, "MTPNP Help Information", "MTPNP Help Information");
    ADD_APPLICATION_STRING2(STRING_MTPNP_REGISTER, "Register", "Register");
    ADD_APPLICATION_STRING2(STRING_MTPNP_REGISTER_TIP,
                            "Register Tips: Please wait the PSN tool report succeed, plug out the cable and restart phone",
                            "Register Tips");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PSNCALLBACK_TIP,
                            "PSN Callback Tips: Please wait the PSN tool report succeed, plug out the cable and restart phone",
                            "PSN Callback Tips");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING, "Dual SIM setting", "Dual SIM setting");
    ADD_APPLICATION_STRING2(STRING_MTPNP_REGISTER_CONFIRM, "Register mercury", "Register mercury");
    ADD_APPLICATION_STRING2(STRING_MTPNP_DM_SETTING, "Dual SIM setting", "Dual SIM setting");
    ADD_APPLICATION_STRING2(STRING_MTPNP_DM_DUALCARD, "Dual SIM open", "Dual SIM open");
    ADD_APPLICATION_STRING2(STRING_MTPNP_DM_CARD1, "Only SIM1 open", "Only SIM1 open");
    ADD_APPLICATION_STRING2(STRING_MTPNP_DM_CARD2, "Only SIM2 open", "Only SIM2 open");
    ADD_APPLICATION_STRING2(STRING_MTPNP_DM_FLIGHT, "Flight mode", "Flight mode");
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    ADD_APPLICATION_STRING2(STRING_MTPNP_DM_QUERY, "Query mode", "Query mode");
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
    ADD_APPLICATION_STRING2(STRING_MTPNP_DM_ERROR_MODE, "Error mode", "Error mode");
    ADD_APPLICATION_STRING2(STRING_MTPNP_DM_SWITCH, "Dual mode switch", "Dual mode switch");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHONE_SETTING, "Phone setup", "Phone setup");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_EXTRA, "Phonebook extra", "Phonebook extra");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1_OWNER_NUMBER, "SIM1 owner number", "owner number");
    ADD_APPLICATION_STRING2(STRING_MTPNP_OWNER_NUMBER, "SIM2 owner number", "owner number");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1_SDL_NUMBER, "SIM1 SDL number", "SDL number");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SDL_NUMBER, "SIM2 SDL number", "SDL number");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1_SOS_NUMBER, "SIM1 SOS number", "SOS number");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SOS_NUMBER, "SIM2 SOS number", "SOS number");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_SHOW_OWNER_NUMBER, "Show Card1 Owner Number", "Show owner number");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SHOW_OWNER_NUMBER, "Show Card2 Owner Number", "Show owner number");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SEL_POWERMODE, "Select power mode", "Select power mode");
    ADD_APPLICATION_STRING2(STRING_MTPNP_DM_DISABLESWTH, "Disable switch mode", "Disable switch mode");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SWITCH_DC, "Switch to dual card", "Switch to dual card");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SWITCH_CARD1, "Switch to card1", "Switch to card1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SWITCH_CARD2, "Switch to card2", "Switch to card2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SWITCH_QUERY, "Switch to query", "Switch to query");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SWITCH_FLIGHT, "Switch to flight", "Switch to flight");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_CLOSED, "SIM1 Closed", "SIM1 Closed");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD2_CLOSED, "SIM2 Closed", "SIM2 Closed");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_DURUNGCLOSE, "SIM1 Closing", "SIM1 Closing");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD2_DURINGCLOSE, "SIM2 Closing", "SIM2 Closing");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SEARCHING_NW, "Searching", "Searching");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NOSERVICE, "No service", "No service");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LIMITSERVICE, "Emergency", "Limit service");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1ABSENT, "Insert SIM1", "Insert SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD2ABSENT, "Insert SIM2", "Insert SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD2_NOTSUPPORT, "Card2 not support!", "Card2 not support!");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_CALL_SETTING, "Card1 Call setting", "Call setting");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CALL_SETTING, "Card2 Call setting", "Call setting");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CALL_ID, "Call ID", "Call ID");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CLI_SET_NETWORK, "Set by network", "Set by network");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CLI_HIDE_ID, "Hide ID", "Hide ID");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CLI_SEND_ID, "Send ID", "Send ID");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LINE_SWITCH, "Line switch", "Line switch");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LSW_LINE1, "Line 1", "Line 1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LSW_LINE2, "Line 2", "Line 2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LINE1_SET, "Line 1 Selected", "Line 1 Selected");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LINE1_SET_ERR, "Unknown Error", "Unknown Error");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LINE2_SET, "Line 2 Selected", "Line 2 Selected");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LINE2_SET_ERR, "Unknown Error", "Unknown Error");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_LINE_SEL, "Line Select Message", "Sel");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LINE_SET_TITLE, "Line set", "Line set");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_SIM_BLOCK, "SIM1 Blocked", "SIM1 Blocked");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD2_SIM_BLOCK, "SIM2 Blocked", "SIM2 Blocked");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENTER_CARD1PIN, "Card1 PIN Verify", "SIM1 PIN Verify");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENTER_CARD2PIN, "Card2 PIN Verify", "SIM2 PIN Verify");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENTER_CARD1PIN2, "Card1 PIN2 Verify", "SIM1 PIN2 Verify");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENTER_CARD2PIN2, "Card2 PIN2 Verify", "SIM2 PIN2 Verify");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CANCEL_CARD1PIN, "Cancel SIM1 PIN", "Cancel SIM1 PIN");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CANCEL_CARD2PIN, "Cancel SIM2 PIN", "Cancel SIM2 PIN");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_SECURITY_SETTING, "Card1 Security Setting", "Security Setting");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SECURITY_SETTING, "Card2 Security Setting", "Security Setting");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_PINLOCK, "Card1 SIM Lock", "Card1 SIM Lock");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD2_PINLOCK, "Card2 SIM Lock", "Card2 SIM Lock");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CHANGE_PASSWORD, "Change password", "Change password");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CP_PIN1, "Card2 PIN1", "Card2 PIN1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CP_PIN2, "Card2 PIN2", "Card2 PIN2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CP_SIM1PIN1, "Card1 PIN1", "Card1 PIN1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CP_SIM1PIN2, "Card1 PIN2", "Card1 PIN2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SECURITY_CAPTION, "Security setting", "Security setting");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CHANGE_PASSWORD_CAPTION, "Card2 change password", "Card2 change password");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1_PIN_BLOCKED, "Card1 PIN Blocked!", "Card1 PIN Blocked!");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1_PIN2_BLOCKED, "Card1 PIN2 Blocked!", "Card1 PIN Blocked!");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PIN_BLOCKED_PUK, "Card2 PIN Blocked!", "Card2 PIN Blocked!");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PIN_BLOCKED_PUK2, "Card2 PIN2 Blocked!", "Card2 PIN Blocked!");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENTER_CARD1PUK, "Enter Card1 PUK:", "Enter Card1 PUK Screen MSG.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENTER_CARD1_NEW_PIN, "Enter Card1 New PIN:",
                            "Enter Card1 New Pin First Time Screen MSG.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENTER_CARD2PUK, "Enter Card2 PUK:", "Enter Card2 PUK Screen MSG.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENTER_CARD2_NEW_PIN, "Enter Card2 New PIN:",
                            "Enter Card2 New Pin First Time Screen MSG.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENTER_PIN_AGAIN, "Enter Card2 Again:", "Card2 Confirm Pin Screen MSG.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_PIN_DONOT_MATCH, "Different Card1 PIN code!",
                            "Running Text of CARD1 PIN Mismatch Screen.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_PIN2_DONOT_MATCH, "Different Card1 PIN2 code!",
                            "Running Text of CARD1 PIN2 Mismatch Screen.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD2_PIN_DONOT_MATCH, "Different Card2 PIN code!",
                            "Running Text of CARD2 PIN Mismatch Screen.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD2_PIN2_DONOT_MATCH, "Different Card2 PIN2 code!",
                            "Running Text of CARD2 PIN2 Mismatch Screen.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CODE_VERIFIED, "Card2 Code Accepted!",
                            "String associated with Code Verified Screen.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_INCORRECT_CARD1_PUK, "Wrong Card1 PUK!",
                            "Running text for incorrct Card1 PUK.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_INCORRECT_CARD1_PUK2, "Wrong Card1 PUK2!",
                            "Running text for incorrct Card1 PUK.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_INCORRECT_CARD2_PUK, "Wrong Card2 PUK!",
                            "Running text for incorrct Card2 PUK.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_INCORRECT_CARD2_PUK2, "Wrong Card2 PUK2!",
                            "Running text for incorrct Card2 PUK.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_PIN_CHANGE, "Card1 PIN changed successfully!",
                            "Card1 PIN changed successfully Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_PIN2_CHANGE, "Card1 PIN2 changed successfully!",
                            "Card1 PIN2 changed successfully Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD2_PIN_CHANGE, "Card2 PIN changed successfully!",
                            "Card2 PIN changed successfully Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD2_PIN2_CHANGE, "Card2 PIN2 changed successfully!",
                            "Card2 PIN2 changed successfully Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_WRONG_CARD1_PIN, "Wrong Card1 PIN Code!", "Wrong Card1 PIN Code Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_WRONG_CARD1_PIN2, "Wrong Card1 PIN2 Code!", "Wrong Card1 PIN2 Code Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_WRONG_CARD2_PIN, "Wrong Card2 PIN Code!", "Wrong Card2 PIN Code Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_WRONG_CARD2_PIN2, "Wrong Card2 PIN2 Code!", "Wrong Card2 PIN2 Code Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_CARD1_SIM_LOCK, "Card1 SIM Locked!", "card1 SIM Locked.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_CARD1_SIM_UNLOCK, "Card1 SIM Unlocked!", "card1 SIM UnLocked.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_CARD2_SIM_LOCK, "Card2 SIM Locked!", "card2 SIM Locked.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_CARD2_SIM_UNLOCK, "Card2 SIM Unlocked!", "card2 SIM UnLocked.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENABLE_CARD1_PIN, "Card1 PIN Lock Must Be Enabled!",
                            "Enable CARD1 PIN Lock String.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ENABLE_CARD2_PIN, "Card2 PIN Lock Must Be Enabled!",
                            "Enable CARD2 PIN Lock String.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_CARD2_PUK, "Enter Card2 PUK", "Enter CARD2 PUK Screen String.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_OLD_CARD1_PIN, "Enter Card1 Old PIN", "Enter CARD1 Old PIN.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_NEW_CARD1_PIN, "Card1 New PIN", "CARD1 New PIN.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_OLD_CARD1_PIN2, "Enter Card1 Old PIN2", "Enter CARD1 Old PIN2.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_NEW_CARD1_PIN2, "Card1 New PIN2", "CARD1 New PIN2.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_OLD_CARD2_PIN, "Enter Card2 Old PIN", "Enter CARD2 Old PIN.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_NEW_CARD2_PIN, "Card2 New PIN", "CARD2 New PIN.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_OLD_CARD2_PIN2, "Enter Card2 Old PIN2", "Enter CARD2 Old PIN2.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_NEW_CARD2_PIN2, "Card2 New PIN2", "CARD2 New PIN2.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_PIN2_BLOCK_MSG, "Please Contact Service Provider!",
                            "Please Contact Service Provider!");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_SIM1_PUK2, "Enter Card1 PUK2", "Enter PUK2 Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_SIM1_NEW_PIN2, "Enter Card1 New PIN2", "Enter New PIN2 Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_ENTER_PUK2, "Enter Card2 PUK2", "Enter PUK2 Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SETTING_ENTER_NEW_PIN2, "Enter Card2 New PIN2", "Enter New PIN2 Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_MASTER_DONE, "Master Done", "Master Done");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_SLAVE_DONE, "Slave Done", "Slave Done");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MASTER_SEND_OPTIONS_CAPTION, "Master Send Option", "Master Send Option");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SLAVE_SEND_OPTIONS_CAPTION, "Slave Send Option", "Slave Send Option");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MASTER_SENDING_SMS, "Master: Sending SMS", "Master: Sending SMS");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SLAVE_SENDING_SMS, "Slave: Sending SMS", "Slave: Sending SMS");
    ADD_APPLICATION_STRING2(STRING_MTPNP_QUERY_DELETEALL_CARD2, "Delete All card2 phonebook?",
                            "Delete All card2 phonebook?");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MASTER_MSGBOX_FORWARD, "Master Forward", "Master Forward");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SLAVE_MSGBOX_FORWARD, "Slave Forward", "Slave Forward");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_COPY_TO_SIM2, "Copy to SIM2", "SMS copy function Copy to SIM String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_MOVE_TO_SIM2, "Move to SIM2", "SMS move function Move to SIM String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_FROM_SIM2, "From SIM2", "SMS copy function From SIM String");

    /* plmn begin */
    ADD_APPLICATION_STRING2(STRING_MTPNP_CARD1_NETWORK_SETUP, "Card1 Network Setup", "Menu item string for Network Setup");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETWORK_SETUP, "Card2 Network Setup", "Menu item string for Network Setup");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETWORK_SETUP_CAPTION, "Network Setup", "Title string for Network Setup menu");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SELECTION_MODE, "Network Selection", "Menu item string for Selection Mode");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SELECTION_MODE_CAPTION, "Network Selection",
                            "Title string for Selection Mode menu");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PREFERRED_NETWORKS, "Preferred Networks",
                            "Menu item string for Preferred Networks");
    ADD_APPLICATION_STRING2(STRING_MTPNP_GPRS_CONNECTION, "GPRS Connection",
                            "Menu item string for GPRS Connection");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_MANUAL, "Manual", "Menu item string for Selection Mode->Manual");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_AUTOMATIC, "Automatic",
                            "Menu item string for Selection Mode->Automatic");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_NEW_SEARCH, "New Search", "New Search");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_SELECT_NETWORK, "Select Network", "Select Network");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_CHOICE, "Selection Mode", "Network Selection Mode");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_OPTIONS, "Preferred Networks Options",
                            "String for options button in preferred network");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_PRF_NWK_ADD, "Add From List", "Menu Item Add Preferred Network");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_PRF_NWK_NEW, "Create New", "Create New preferred network");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_PRF_NWK_EDIT, "Change Priority", "Menu Item Edit Preferred Network");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_SIM2_INVALID, "Not avaliable for invalid SIM2.",
                            "Invalid SIM network selection text.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_CHANGE, "Change", "LSK Display for Change");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_MANUAL_MODE, "Select Network", "Select Network As Manual Mode");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_PRF_NWK_ADDED_ERR, "Unable To Add Network",
                            "Message String for Deleted Preferred Network Error");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_PRF_ADD_SHW_NWK_TITLE, "PLMN LIST",
                            "Title String for Error Screen Preferred Network");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_PRF_ADD_SHW_NWK_PRIORITY_TITLE, "Priority",
                            "Title String for User Priority Preferred Network");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_PRR_MCC_CAPTION, "MCC/MNC", "MCC/MNC String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_PRR_PR_CAPTION, "Priority", "Priority String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_PRR_SV_CAPTION, "Service", "Service String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PLMN_LIST_SORT_BY_ALPHABET, "Sort by alphabet", "Sort PLMN list");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PLMN_LIST_SORT_BY_DEFAULT, "Sort by default", "Sort PLMN list");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_SEARCHIN_NW, "Searching", "Searching Network Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_REGISTERING_NW, "Registering", "Registering Network Message.");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_NW_SELECT_FAIL, "Fail to register!", "Fail to register!");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_NW_LIST_FAIL, "Fail to search network!", "Fail to search network!");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NETSET_SELECT_NETWORK_CAPTION, "Network List",
                            "Title string for Select Network screen");
    /* plmn end */

    /* cell broadcast messages begin */
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1_CB_MENUENTRY, "SIM1 Broadcast Message",
                            "Cell Broadcast menu item string");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_MENUENTRY, "SIM2 Broadcast Message", "Cell Broadcast menu item string");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_SERVICE, "Receive Mode", "CB Menu Item Service Cell Broadcast String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_READ_MESSAGE, "Read Message", "CB Menu Read Message Cell Broadcast String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHANNELS, "Channel Setting", "CB Menu Channels Cell Broadcast String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_LANGUAGE, "Languages", "CB Menu Language Cell Broadcast String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_MESSAGE_BODY, "Message Body", "CB Menu Message Body String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_SELECT_CHNL, "Select Channel", "CB Menu Select Channel String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHNL_EDITOR, "Channel Editor", "CB Menu Channel Editor String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHNL_TITLE, "Channel Title:", "CB Menu Channel Title: String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHNL_TITLE_FULL_EDIT, "Channel Title", "CB Menu Channel Title String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHNL_NUMBER, "Channel Number:", "CB Menu Channel Number String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHNL_LIST, "Channel List", "CB Menu Channel List String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_LANGUAGE_CAPTION, "Languages",
                            "CB Menu Item Cell Broadcast Language Caption String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHANNELS_CAPTION, "Channels",
                            "CB Menu Item Cell Broadcast Channels Caption String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHANNEL_ENBL_OPTIONS, "Channel Options",
                            "CB Menu Item Cell Broadcast Channels Options Enable String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHANNEL_ENBL_OPTIONS_CAPTION, "Channels",
                            "CB Menu Item Cell Broadcast Channels Options Caption String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_LANGUAGE_UNSPECIFIED, "unspecified",
                            "CB Menu Item Cell Broadcast Language Option Unspecified Language String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_ERROR_MESSAGE, "Failed!", "CB error String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_NOT_READY_YET, "CB Not Ready Yet!", "CB CB Not Ready Yet! String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_CB_CHNL_FULL, "Channel Full!", "Channel Full Message SMS String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHNL_DUPLICATE_NUMBER_NOT_ALLOWED, "Duplicate number not allowed!",
                            "CB Duplicate number not allowed String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_CHNL_NUMBER_LEN_EXCEEDED, "Number Exceeded!", "Number Exceeded! String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_ALL_CHANNELS_FOR_SELECT, "All Channels", "CB All Channels String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_ALL_LANGUAGES_FOR_SELECT, "All Languages", "CB All Languages String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CB_MSG_IND_INFORMATION_CAPTION, "Information", "CB  Information String");
    /* cell broadcast messages end */

    /* voice mail begin */
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1_VMAIL_MENUENTRY, "SIM1 Voice Mail Server", "Voice Mail menu item string");
    ADD_APPLICATION_STRING2(STRING_MTPNP_VMAIL_MENUENTRY, "SIM2 Voice Mail Server", "Voice Mail menu item string");
    ADD_APPLICATION_STRING2(STRING_MTPNP_VOICE_MAIL_NOT_READY_YET, "VM Not Ready Yet!",
                            "Message Voice Mail Not Ready String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_VOICE_MAIL_OPTION_ID, "Voice Mail Option", "Message Voice Mail Option String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_VM_CONNECT_TO_VOICE_ID, "Connect to Voice", "Message Connect to Voice String");
    /* voice mail end */

    /* message setup begin */
    ADD_APPLICATION_STRING2(STRING_MTPNP_MESSAGESETUP_MENUENTRY, "SIM2 Message Settings",
                            "Message setup menu item string");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1_MESSAGESETUP_MENUENTRY, "SIM1 Message Settings",
                            "Message setup menu item string");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_MEMSTATUS_PREFIX_SIM, "SIM: ", "Memory Status display prefix for SIM");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_MEMSTATUS_PREFIX_PHONE, "PHONE: ",
                            "Memory Status display prefix for PHONE");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ME_STORAGE_MENUENTRY, "Phone", "Message ME Memory Setting SMS String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM_STORAGE_MENUENTRY, "SIM", "Message SIM Memory Setting SMS String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PROFILE_SETTING_MENUENTRY, "Profile Setting",
                            "Message Profile Setting  SMS  String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_COMMONSETTING_MENUENTRY, "Common Setting",
                            "Message Setup Common Settings SMS  String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PREFEREDSTORAGE_MENUENTRY, "Preferred Storage",
                            "Message Setup Preferred Storage SMS  String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMSSTATUS_MENUENTRY, "Memory Status", "SMS Status SMS menu item String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMSSTATUS_TITLE, "SMS Status", "SMS Status SMS menu item String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PROFILE_NAME, "Profile Name", "SMS Profile Name String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PROFILE_SC, "SC Address", "SMS Profile Name String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PROFILE_VP, "Valid Period", "SMS Profile Name String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PROFILE_MSG_TYPE, "Message Type", "SMS Profile Name String");
    /* message setup end */

     /* adn begin */
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_COPYALL_SIM1TOPHONE, "From SIM1 To Phone", "CopyAll For Slave");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_COPYALL_PHONETOSIM1, "From Phone To SIM1", "CopyAll For Slave");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_COPYALL_SIM2TOPHONE, "From SIM2 To Phone", "CopyAll For Slave");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_COPYALL_PHONETOSIM2, "From Phone To SIM2", "CopyAll For Slave");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_COPYALL_SIM1TOSIM2, "From SIM1 To SIM2", "CopyAll For Slave");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_COPYALL_SIM2TOSIM1, "From SIM2 To SIM1", "CopyAll For Slave");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_COPY_SIM2TOPHONE, "Copy From SIM2 To Phone",
                            "Copy For Slave From SIM2 to Phone");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_COPY_SIM2TOSIM1, "Copy From SIM2 To SIM1",
                            "Copy For Slave From Phone to SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_MOVE_SIM2TOPHONE, "Move From SIM2 To Phone",
                            "Move For Slave From SIM2 to Phone");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_MOVE_SIM2TOSIM1, "Move From SIM2 To SIM1",
                            "Move For Slave From Phone to SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_VCARD_SAVE_TO_SIM1, "Save to SIM1", "Save to SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_VCARD_SAVE_TO_SIM2, "Save to SIM2", "Save to SIM2");

    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1_STORAGE_FULL, "SIM1 IS Full!", "Message for SIM1 IS Full");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2_STORAGE_FULL, "SIM2 IS Full!", "Message for SIM2 IS Full");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1PHB_ADD_NEW_ENTRY, "To SIM1", "Add New Entry To SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_ADD_NEW_ENTRY, "To SIM2", "Add New Entry To SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_DELETEALL, "From SIM2", "Delete All From SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1PHB_DELETEALL, "SIM1", "Memory Status of SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NLF_SIM1, "Only SIM1", "NLF SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NLF_ALL, "All", "NLF ALL");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1_MEMORY_STATUS, "SIM1", "Memory Status of SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SLAVE_MEMORY_STATUS, "SIM2", "Memory Status of SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_PRESTORAGE, "SIM2", "Memory Status of SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_NLF_SIM2, "SIM2 Only", "Menu item string for List Filter SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_STORAGE_SIM2, "SIM2", "Menu item string for Storage Location SIM2");

    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_COPY_PHONETOSIM2, "Copy From Phone To SIM2",
                            "Copy For Slave From Phone to SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_COPY_SIM1TOSIM2, "Copy From SIM1 To SIM2",
                            "Copy For Slave From SIM1 to SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_MOVE_PHONETOSIM2, "Move From Phone To SIM2",
                            "Move For Slave From Phone to SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_MOVE_SIM1TOSIM2, "Move From SIM1 To SIM2",
                            "Move For Slave From SIM1 to SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_COPY_SIM1TOPHONE, "Copy From SIM1 To Phone",
                            "Copy For Slave From SIM1 To Phone");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_COPY_PHONETOSIM1, "Copy From Phone To SIM1",
                            "Copy For Slave From Phone To SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_MOVE_SIM1TOPHONE, "Move From SIM1 To Phone",
                            "Move For Slave From SIM1 To Phone");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2PHB_MOVE_PHONETOSIM1, "Move From Phone To SIM1",
                            "Move For Slave From Phone To SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_COPY_ALL_FROM_SIM1, "From SIM1", "CopyAll From SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_COPY_ALL_FROM_SIM2, "From SIM2", "CopyAll From SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_COPY_TO_SIM1_DONE, "Copied to SIM1", "Copied to SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_COPY_TO_SIM2_DONE, "Copied to SIM2", "Copied to SIM2");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_MOVE_TO_SIM1_DONE, "Moved to SIM1", "Moved to SIM1");    
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_MOVE_TO_SIM2_DONE, "Moved to SIM2", "Moved to SIM2");    
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_SOSLIST_INSIM1, "in sim1", "in sim1");    
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_SOSLIST_INSIM2, "in sim2", "in sim2");    

     /* adn end */

     /* adn begin */
    ADD_APPLICATION_STRING2(STRING_MTPNP_SLAVE_FIXED_DIAL, "Slave Fixed Dial", "Fixed Dial Menu.");
     /* adn end */

     /*mtpnp call set */
    ADD_APPLICATION_STRING2(STRING_MTPNP_CALL_FORWARD, "Call Forward", "Call Forward");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LINE_WAIT, "Call Wait", "Call Wait");
    ADD_APPLICATION_STRING2(STRING_MTPNP_LINE_BARRING, "Call Barring", "Call Barring");
    /*mtpnp call set */

    /* sms show begin */
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_MASTER_INBOX, "Master Inbox", "Inbox SMS menu item String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_SLAVE_INBOX, "Slave Inbox", "Inbox SMS menu item String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_MASTER_OUTBOX, "Master Outbox", "Outbox SMS menu item String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_SLAVE_OUTBOX, "Slave Outbox", "Outbox SMS menu item String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_SHOW_STYLE, "Show Style", "Outbox SMS menu item String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_SHOW_MIXED, "Show Mixed", "Outbox SMS menu item String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_SHOW_DIVIDED, "Show Divided", "Outbox SMS menu item String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NEW_MASTER_MESSAGE_FROM_ID, "Master Message From ",
                            "SMS New Message From String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_NEW_SLAVE_MESSAGE_FROM_ID, "Slave Message From ",
                            "SMS New Message From String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MASTER_RECEIVED_SMS, "New Master Message!",
                            "SMS while receiving sms Message String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SLAVE_RECEIVED_SMS, "New Slave Message!",
                            "SMS while receiving sms Message String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MASTER_DELIVERY_REPORT_MENUENTRY, "Master Delivery Report",
                            "Message Delivery report SMS String");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SLAVE_DELIVERY_REPORT_MENUENTRY, "Slave Delivery Report",
                            "Message Delivery report SMS String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_DELETE_INBOX_MENUENTRY,	"Delete SIM1 Inbox?",	"SMS Delete SIM1 Inbox Query String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_DELETE_OUTBOX_MENUENTRY,	"Delete SIM1 Outbox?",	"SMS Delete SIM1 Outbox Query String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_DELETE_INBOX_MENUENTRY,	"Delete SIM2 Inbox?",	"SMS Delete SIM2 Inbox Query String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_DELETE_OUTBOX_MENUENTRY,	"Delete SIM2 Outbox?",	"SMS Delete SIM2 Outbox Query String");

	/* sms show end */

	/* sms message waiting begin*/
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_VOICEMAIL_IND,			"New SIM1 Voice Mail!",	"New SIM1 voice Mail SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_EMAIL_IND,			"New SIM1 Fax!",	"New SIM1 Fax SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_FAX_IND,			"New SIM1 E-Mail!",	"New SIM1 E-Mail SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_NET_OTHER_IND,			"New SIM1 network message",	"New SIM1 other SMS Notification Caption String");
	
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_VOICEMAIL_NUM_IND,			"New SIM1 Voice Mail(s)!",	"Number of new SIM1 voice Mail SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_FAX_NUM_IND,			"New SIM1 Fax(es)!",	"Number of new Fax SIM1 SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_EMAIL_NUM_IND,			"New SIM1 E-Mail(s)!",	"Number of new SIM1 E-Mail SMS Notification Caption String");
    ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_NET_OTHER_NUM_IND,			"New SIM1 network message(s)!",	"Number of New SIM1 other SMS Notification Caption String");

	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_VOICEMAIL_IND,			"New SIM2 Voice Mail!",	"New SIM2 voice Mail SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_EMAIL_IND,			"New SIM2 Fax!",	"New SIM2 Fax SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_FAX_IND,			"New SIM2 E-Mail!",	"New SIM2 E-Mail SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_NET_OTHER_IND,			"New SIM2 network message",	"New SIM2 other SMS Notification Caption String");
	
	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_VOICEMAIL_NUM_IND,			"New SIM2 Voice Mail(s)!",	"Number of new SIM2 voice Mail SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_FAX_NUM_IND,			"New SIM2 Fax(es)!",	"Number of new Fax SIM2 SMS Notification Caption String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_EMAIL_NUM_IND,			"New SIM2 E-Mail(s)!",	"Number of new SIM2 E-Mail SMS Notification Caption String");
    ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_NET_OTHER_NUM_IND,			"New SIM2 network message(s)!",	"Number of New SIM2 other SMS Notification Caption String");
	/* sms message waiting end*/

	/* sms memory exceeded begin */
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_SMS_MEMORY_EXCEEDED,		"SIM1 phone Storage Full for New Incoming Message!",	"Memory Exceeded SIM1 Message SMS String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_MASTER_SMS_SIM_MEMORY_EXCEEDED,		"SIM1 SIM Storage Full for New Incoming Message!",	"SIM Memory Exceeded SIM1 Message SMS String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_SMS_MEMORY_EXCEEDED,		"SIM2 phone Storage Full for New Incoming Message!",	"Memory Exceeded SIM2 Message SMS String");
	ADD_APPLICATION_STRING2 (STRING_MTPNP_SLAVE_SMS_SIM_MEMORY_EXCEEDED,		"SIM2 SIM Storage Full for New Incoming Message!",	"SIM Memory Exceeded SIM2 Message SMS String");
	/* sms memory exceeded end */


    /* ucm begin */
    ADD_APPLICATION_STRING2(STRING_MTPNP_ID_UCM_VOICE_ACTIVE, "SIM2 Voice Active", "Voice Active string");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ID_UCM_VOICE_HOLD, "SIM2 Voice Hold", "Voice Hold string");
    ADD_APPLICATION_STRING2(STRING_MTPNP_ID_UCM_DIAL_SIM2, "Dial Card2", "Dial Card2");
    /* ucm end */


    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1DIAL, "SIM1 Dial", "Global String- Dial");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2DIAL, "SIM2 Dial", "Global String- Dial");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_OPTION_IP_DIAL_SIM1, "SIM1 IP Dial",
                            "Menu item string for View options->IP1Dial");
    ADD_APPLICATION_STRING2(STRING_MTPNP_PHB_OPTION_IP_DIAL_SIM2, "SIM2 IP Dial",
                            "Menu item string for View options->IP2 Dial");

#ifdef __MMI_MESSAGES_CHAT__
    ADD_APPLICATION_STRING2(STRING_MTPNP_CHOOSE_MASTER_CHAT, "Choose Master", "Choose Master");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CHOOSE_SLAVE_CHAT, "Choose Slave", "Choose Slave");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CHAT_NOT_SUPPORT, "Not Support", "Not Support");
#endif /* __MMI_MESSAGES_CHAT__ */
    ADD_APPLICATION_STRING2(STRING_MTPNP_CALL_SIM1, "SIM1 Dialing", "SIM1 Dialing");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CALL_SIM2, "SIM2 Dialing", "SIM2 Dialing");
    ADD_APPLICATION_STRING2(STRING_MTPNP_INCOMING_SIM1, "SIM1-Incoming", "SIM1-Incoming");
    ADD_APPLICATION_STRING2(STRING_MTPNP_INCOMING_SIM2, "SIM2-Incoming", "SIM2-Incoming");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM1, "SIM1", "SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SIM2, "SIM2", "SIM2");

    ADD_APPLICATION_STRING2(STRING_MTPNP_OUTBOX_MASTER_SEND_SMS, "Send From SIM1", "Send From SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_OUTBOX_SLAVE_SEND_SMS, "Send From SIM2", "Send From SIM2");

    ADD_APPLICATION_STRING2(STRING_MTPNP_SAVE_SMS_TO_SIM1, "Save to SIM1", "Save to SIM1");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SAVE_SMS_TO_SIM2, "Save to SIM2", "Save to SIM1");

}

void Mercury_ResPopulate(void)
{
    /* mercury string */
    Mercury_StrPopulate();
    /* mercury string */

    // mercury image
    ADD_APPLICATION_IMAGE2(IMG_SI_MASTER_SIGNAL_STRENGTH,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Master\\\\SI_SIG1",
                           "Slave Status Icon: Signal strength");
    ADD_APPLICATION_IMAGE2(IMG_SI_MASTER_SIGNAL_STRENGTH_L1,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Master\\\\SI_SIG1_L1",
                           "Status Icon: Signal strength with L1");
    ADD_APPLICATION_IMAGE2(IMG_SI_MASTER_SIGNAL_STRENGTH_L2,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Master\\\\SI_SIG1_L2",
                           "Status Icon: Signal strength with L2");
    ADD_APPLICATION_IMAGE2(IMG_SI_MASTER_SIGNAL_CLOSED,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Master\\\\SI_SIG1_CLOSE\\\\SI_SIG_1_CLOSE.bmp",
                           "Slave Status Icon: rf closed");


    ADD_APPLICATION_IMAGE2(IMG_SI_SLAVE_SIGNAL_STRENGTH,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Slave\\\\SI_SIG2",
                           "Slave Status Icon: Signal strength");
    ADD_APPLICATION_IMAGE2(IMG_SI_SLAVE_SIGNAL_STRENGTH_L1,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Slave\\\\SI_SIG2_L1",
                           "Status Icon: Signal strength with L1");
    ADD_APPLICATION_IMAGE2(IMG_SI_SLAVE_SIGNAL_STRENGTH_L2,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Slave\\\\SI_SIG2_L2",
                           "Status Icon: Signal strength with L2");
    ADD_APPLICATION_IMAGE2(IMG_SI_SLAVE_SIGNAL_CLOSED,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Slave\\\\SI_SIG2_CLOSE\\\\SI_SIG_2_CLOSE.bmp",
                           "Slave Status Icon: rf closed");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_MASTER_NETWORK_CIPHER_GSM,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Callforward\\\\Master\\\\SI_Ncipher.BMP",
                           "Slave Status Icon: master gsm");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_SLAVE_NETWORK_CIPHER_GSM,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_Ncipher.BMP",
                           "Slave Status Icon: slave gsm");

    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_VOICE_L1_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VOML1.bmp",
                           "Master Status Icon: master unread voice L1");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_VOICE_L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VOML2.bmp",
                           "Master Status Icon: master unread voice L2");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_VOICE_L1L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VOML12.bmp",
                           "Master Status Icon: master unread voice L12");

    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_FAX_L1_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_FM1.bmp",
                           "Master Status Icon: master unread fax L1");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_FAX_L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_FM2.bmp",
                           "Master Status Icon: master unread fax L2");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_FAX_L1L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_FM12.bmp",
                           "Master Status Icon: master unread fax L12");

    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_EMAIL_L1_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_EM1.bmp",
                           "Master Status Icon: master unread email L1");
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_EMAIL_L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_EM2.bmp",
                           "Master Status Icon: master unread email L2");
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_EMAIL_L1L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_EM12.bmp",
                           "Master Status Icon: master unread email L12");

    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_NET_L1_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_NETL1.bmp",
                           "Master Status Icon: master unread net L1");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_NET_L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_NETL2.bmp",
                           "Master Status Icon: master unread net L2");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_NET_L1L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_NETL12.bmp",
                           "Master Status Icon: master unread net L12");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_VOICE_L1_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VOML1.bmp",
                           "Master Status Icon: slave unread voice L1");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_VOICE_L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VOML2.bmp",
                           "Slave Status Icon: slave unread voice L2");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_VOICE_L1L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VOML12.bmp",
                           "Slave Status Icon: slave unread voice L12");

    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_FAX_L1_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_FM1.bmp",
                           "Slave Status Icon: slave unread fax L1");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_FAX_L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_FM2.bmp",
                           "Slave Status Icon: slave unread fax L2");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_FAX_L1L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_FM12.bmp",
                           "Slave Status Icon: slave unread fax L12");

    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_EMAIL_L1_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_EM1.bmp",
                           "Slave Status Icon: slave unread email L1");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_EMAIL_L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_EM2.bmp",
                           "Slave Status Icon: slave unread email L2");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_EMAIL_L1L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_EM12.bmp",
                           "Slave Status Icon: slave unread email L12");

    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_NET_L1_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_NETL1.bmp",
                           "Slave Status Icon: slave unread net L1");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_NET_L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_NETL2.bmp",
                           "Slave Status Icon: slave unread net L2");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_NET_L1L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_NETL12.bmp",
                           "Slave Status Icon: slave unread net L12");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_SETTING, CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\SETUP\\\\DM_SETUP.bmp",
                           "mercury setting");
    ADD_APPLICATION_IMAGE2(IMG_SI_SLAVE_CALLSETTING,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\SETUP\\\\CALL_SETUP_2.bmp",
                           "Image for slave call setting");
    ADD_APPLICATION_IMAGE2(IMG_SI_CARD2_PHONESETTING,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\SETUP\\\\PHONE_SETUP_2.bmp",
                           "Image for slave phone setting");
    ADD_APPLICATION_IMAGE2(IMG_SI_SLAVE_NETWORKSETTING,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\SETUP\\\\NETWORK_SETUP_2.bmp",
                           "Image for slave network setting");
    ADD_APPLICATION_IMAGE2(IMG_SI_SLAVE_SECURITYSETTING,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\SETUP\\\\SECURITY_SETUP_2.bmp",
                           "Image for slave security setting");

    ADD_APPLICATION_IMAGE2(IMG_SLAVE_CALL_FORWARD, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_FOR_2.bmp",
                           "Status Icon: slave Call Divert");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_CALL_FORWARD_L1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_FOR_L1_2.bmp",
                           "Status Icon: slave Call Divert L1");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_CALL_FORWARD_L2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_FOR_L2_2.bmp",
                           "Status Icon: slave Call Divert L2");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_SLAVE_ROAMING_INDICATOR, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_RM_2.BMP",
                           "Status Icon: Slave Roaming");
    ADD_APPLICATION_IMAGE2(IMG_SI_SLAVE_SMS_INDICATOR, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Callforward\\\\Slave\\\SI_MGE_2.bmp",
                           "Status Icon: SLAVE Message");

    ADD_APPLICATION_IMAGE2(IMG_SI_MMS_UNREAD_INDICATOR_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\MMS\\\\Master\\\SI_UNREAD_1.bmp",
                           "Status Icon: Master unread mms");

    ADD_APPLICATION_IMAGE2(IMG_SI_MMS_UNREAD_INDICATOR_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\MMS\\\\Slave\\\SI_UNREAD_2.bmp",
                           "Status Icon: Slave unread mms");

    ADD_APPLICATION_IMAGE2(IMG_SI_MMS_BUSY_INDICATOR_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\MMS\\\\Master\\\SI_BUSY_1.bmp",
                           "Status Icon: Master unread mms");

    ADD_APPLICATION_IMAGE2(IMG_SI_MMS_BUSY_INDICATOR_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\MMS\\\\Slave\\\SI_BUSY_2.bmp",
                           "Status Icon: Slave unread mms");

    ADD_APPLICATION_IMAGE2(IMG_SI_EDGE_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\GPRS\\\\Master\\\SI_EDGE_SIM1.bmp",
                           "Status Icon: Master EDGE");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_GPRS_SERVICE_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\GPRS\\\\Master\\\SI_GPRS_SIM1.bmp",
                           "Status Icon: Master GPRS");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_EDGEC_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\GPRS\\\\Master\\\SI_EDGEC_SIM1.bmp",
                           "Status Icon: Master EDGEC");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\GPRS\\\\Master\\\SI_GPRSC_SIM1.bmp",
                           "Status Icon: Master GPRS_ATT_NO_PDP_INDICATOR");

    ADD_APPLICATION_IMAGE2(IMG_SI_EDGE_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_EDGE_SIM2.bmp",
                           "Status Icon: Slave EDGE");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_GPRS_SERVICE_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_GPRS_SIM2.bmp",
                           "Status Icon: Slave GPRS");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_EDGEC_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_EDGEC_SIM2.bmp",
                           "Status Icon: Slave EDGEC");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_GPRSC_SIM2.bmp",
                           "Status Icon: Slave GPRS_ATT_NO_PDP_INDICATOR");

    ADD_APPLICATION_IMAGE2(MAIN_MENU_TITLE_DM_SETTINGS_ICON,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\SETUP\\\\DM_SETUP.bmp", "mercury setting");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_LSW_LINE1, CUST_IMG_BASE_PATH "\\\\NoImage.bmp", "Image for Line 1 option");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_LSW_LINE2, CUST_IMG_BASE_PATH "\\\\NoImage.bmp", "Image for Line 2 option");

    ADD_APPLICATION_IMAGE2(IMG_SLAVE_LINE_SET_TITLE, CUST_IMG_BASE_PATH "\\\\NoImage.bmp", "Image for Line 2 option");

    ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_READ,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\INBOX\\\SS_READ_1.bmp",
                           "read message");
    ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_UNREAD,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\INBOX\\\SS_UNREAD_1.bmp",
                           "unread message");
    ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_SENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\SS_SENT_1.bmp",
                           "sent message");
    ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_UNSENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\SS_UNSENT_1.bmp",
                           "unsent message");
    ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_SS_NCOMP,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\INBOX\\\SS_NCOMP_1.bmp",
                           "ncomp message");

    ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_READ,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\INBOX\\\SS_READ_2.bmp",
                           "read message");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_UNREAD,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\INBOX\\\SS_UNREAD_2.bmp",
                           "unread message");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_SENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\SS_SENT_2.bmp",
                           "sent message");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_UNSENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\SS_UNSENT_2.bmp",
                           "unsent message");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_SS_NCOMP,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\INBOX\\\SS_NCOMP_2.bmp",
                           "ncomp message");
    /*add by hechao*/

	// Huyanwei Touch Here For SMS 
	ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_SIM_READ,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\INBOX\\\ss_sim_read_1.bmp",
                           "read message");
    ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_PHONE_READ,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\INBOX\\\ss_phone_read_1.bmp",
                           "unread message");
	ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_SIM_UNREAD,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\INBOX\\\ss_sim_unread_1.bmp",
                           "read message");
    ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_PHONE_UNREAD,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\INBOX\\\ss_phone_unread_1.bmp",
                           "unread message");

    ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_SIM_SENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\SS_sim_SENT_1.bmp",
                           "read message");
    ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_PHONE_SENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\SS_phone_SENT_1.bmp",
                           "unread message");
	ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_SIM_UNSENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\SS_sim_UNSENT_1.bmp",
                           "read message");
    ADD_APPLICATION_IMAGE2(IMG_MASTER_MESSAGE_PHONE_UNSENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD1\\\\OUTBOX\\\SS_phone_UNSENT_1.bmp",
                           "unread message");
	
	ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_SIM_READ,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\INBOX\\\ss_sim_read_2.bmp",
                           "read message");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_PHONE_READ,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\INBOX\\\ss_phone_read_2.bmp",
                           "unread message");
	ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_SIM_UNREAD,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\INBOX\\\ss_sim_unread_2.bmp",
                           "read message");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_PHONE_UNREAD,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\INBOX\\\ss_phone_unread_2.bmp",
                           "unread message");

	ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_SIM_SENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\ss_SIM_SENT_2.bmp",
                           "read message");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_PHONE_SENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\ss_PHONE_SENT_2.bmp",
                           "unread message");
	ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_SIM_UNSENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\ss_SIM_UNSENT_2.bmp",
                           "read message");
    ADD_APPLICATION_IMAGE2(IMG_SLAVE_MESSAGE_PHONE_UNSENT,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\MESSAGE\\\\CARD2\\\\OUTBOX\\\ss_PHONE_UNSENT_2.bmp",
                           "unread message");
	/*add end*/

    ADD_APPLICATION_IMAGE2(IMG_SI_CARD1MISSED_CALL_INDICATOR,
                            CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Callforward\\\\Master\\\SI_MCA_1.bmp",
                           "Status Icon: Missed Call");
    
    ADD_APPLICATION_IMAGE2(IMG_SI_CARD2MISSED_CALL_INDICATOR,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_MCA_2.BMP",
                           "Status Icon: Missed Call");

    ADD_APPLICATION_IMAGE2(IMG_ID_CARD1_PHB_STORAGE_SIM,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_CHOOSE_CARD1.bmp",
                           "sim card entry");
    ADD_APPLICATION_IMAGE2(IMG_ID_CARD2_PHB_STORAGE_SIM,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_CHOOSE_CARD2.bmp",
                           "sim card entry");
    ADD_APPLICATION_IMAGE2(IMG_ID_MTPNP_PHB_DELALL_FROM_SIM1,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_DEL_FROM1.bmp",
                           "delete all entries form card1");
    ADD_APPLICATION_IMAGE2(IMG_ID_MTPNP_PHB_DELALL_FROM_SIM2,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_DEL_FROM2.bmp",
                           "delete all entries form card2");
    ADD_APPLICATION_IMAGE2(IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM1TOPHONE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_COPY_FROM1TOPHONE.bmp",
                           "copyall form sim1 to phone");
    ADD_APPLICATION_IMAGE2(IMG_ID_MTPNP_PHB_COPYALL_FROM_PHONETOSIM1,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_COPY_FROMPHONETO1.bmp",
                           "copyall form phone to sim");
    ADD_APPLICATION_IMAGE2(IMG_ID_MTPNP_PHB_COPYALL_FROM_PHONETOSIM2,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_COPY_FROMPHONETO2.bmp",
                           "copyall form sim1 to phone");
    ADD_APPLICATION_IMAGE2(IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM2TOPHONE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_COPY_FROM2TOPHONE.bmp",
                           "copyall form phone to sim");
    ADD_APPLICATION_IMAGE2(IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM1TOSIM2,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_COPY_FROM1TO2.bmp",
                           "copyall form sim1 to sim2");
    ADD_APPLICATION_IMAGE2(IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM2TOSIM1,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\PHONEBOOK\\\\PHB_COPY_FROM2TO1.bmp",
                           "copyall form sim2 to sim1");

    ADD_APPLICATION_IMAGE2(IMG_DM_SWITCH_PROGRESS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Progress\\\\PROGRESS.gif",
                           "copyall form sim2 to sim1");
/*
	ADD_APPLICATION_IMAGE2(IMG_DM_SWITCH_PROGRESS,
						   CUST_IMG_PATH "\\\\mercury\\\\active\\\\ModeSwitch\\\\MODESWITCHPROGRESS.gif",
                           "copyall form sim2 to sim1");
*/
    // mercury menu
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SETTING,
                              MAIN_MENU_SETTINGS_MENUID,
                              MENU_ENUM_TOTAL_SETTING,
                              MENU_MTPNP_DM_SETTING,
                              MENU_MTPNP_PHONE_SETTING,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_SETTING, IMG_MTPNP_SETTING));

    /* engineer/factory mode begin */
#if !defined(__MMI_DUAL_SIM_SINGLE_CALL__)
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_EM_DUALMODE, ENGINEER_MODE_MENUID, MTPNP_ENUM_EM_TOTAL, MENU_EM_CHK_RSSI,
                              MENU_EM_CALLBACK_PSN,
                              MENU_EM_ASSERT_SLAVE,
                              MENU_MTPNP_HELPINFO, SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_EM, 0));

    ADD_APPLICATION_MENUITEM((MENU_EM_CHK_RSSI, MENU_MTPNP_EM_DUALMODE, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_CHK_RSSI, 0));
    ADD_APPLICATION_MENUITEM((MENU_EM_CALLBACK_PSN, MENU_MTPNP_EM_DUALMODE, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_PSN_CALLBACK, 0));
    ADD_APPLICATION_MENUITEM((MENU_EM_ASSERT_SLAVE, MENU_MTPNP_EM_DUALMODE, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_ASSERT_SLAVE, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FM_COMM, MENU_ID_FM_ROOT, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_FM_COMM, IMG_MTPNP_FM_COMM));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FM_MIC, MENU_ID_FM_ROOT, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_FM_MIC, IMG_MTPNP_FM_MIC));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FM_SPEAKER, MENU_ID_FM_ROOT, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_FM_SPEAKER, IMG_MTPNP_FM_SPEAKER));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FM_RECEIVER, MENU_ID_FM_ROOT, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_FM_RECEIVER, IMG_MTPNP_FM_RECEIVER));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FM_HEADSET, MENU_ID_FM_ROOT, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_FM_HEADSET, IMG_MTPNP_FM_HEADSET));
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
    /* engineer/factory mode end */

    /* help information begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_HELPINFO, MENU_MTPNP_EM_DUALMODE, 0,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_HELPINFO, 0));
    /* help information end */

    /* mode setting */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_SETTING,
                              MAIN_MENU_SETTINGS_MENUID,
                              MENU_ENUM_TOTAL_DM_SETTING,
                              MENU_MTPNP_DM_DUALCARD, MENU_MTPNP_DM_CARD1, MENU_MTPNP_DM_CARD2, MENU_MTPNP_DM_FLIGHT,
                          #ifdef __DM_PWR_ON_QUERY_SUPPORT__
                              MENU_MTPNP_DM_QUERY,
                          #endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_SETTING, IMG_MTPNP_SETTING));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_DUALCARD, MENU_MTPNP_DM_SETTING, 0,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_DUALCARD, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_CARD1, MENU_MTPNP_DM_SETTING, 0,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_CARD1, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_CARD2, MENU_MTPNP_DM_SETTING, 0,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_CARD2, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_FLIGHT, MENU_MTPNP_DM_SETTING, 0,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_FLIGHT, 0));

#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_QUERY, MENU_MTPNP_DM_SETTING, 0,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_QUERY, 0));
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */

#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_QUERY,
                              MAIN_MENU_SETTINGS_MENUID,
                              MENU_ENUM_TOTAL_QUERY,
                              MENU_MTPNP_QUERY_SEL_DUALCARD,
                              MENU_MTPNP_QUERY_SEL_CARD1,
                              MENU_MTPNP_QUERY_SEL_CARD2,
                              MENU_MTPNP_QUERY_SEL_FLIGHT,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_SETTING, IMG_MTPNP_SETTING));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_QUERY_SEL_DUALCARD, MENU_MTPNP_QUERY, 0,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_DUALCARD, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_QUERY_SEL_CARD1, MENU_MTPNP_QUERY, 0,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_CARD1, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_QUERY_SEL_CARD2, MENU_MTPNP_QUERY, 0,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_CARD2, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_QUERY_SEL_FLIGHT, MENU_MTPNP_QUERY, 0,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_DM_FLIGHT, 0));
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
    /* mode setting */

    /* phone setting */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PHONE_SETTING,
                              MENU_MTPNP_SETTING,
                              MTPNP_ENUM_TOTAL_PHONE_SETTING,
                              MENU_MTPNP_CARD2_PHBEXTRA,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_PHONE_SETTING, 0));

    /* owner number begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CARD2_PHBEXTRA,
                              MENU_MTPNP_PHONE_SETTING,
                              1,
                              MENU_MTPNP_SHOW_CARD2_OWNER_NUMBER,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_PHB_EXTRA, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CARD2_OWNER_NUMBER,
                              MENU_ID_PHB_EXTRA_NUMBER,
                              0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_OWNER_NUMBER, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CARD2_SDL_NUMBER,
                              MENU_ID_PHB_EXTRA_NUMBER,
                              0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_SDL_NUMBER, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CARD2_SOS_NUMBER,
                              MENU_ID_PHB_EXTRA_NUMBER,
                              0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_SOS_NUMBER, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_SHOW_OWNER_NUMBER,
                              MENU_IDLE_SCR_DISP,
                              2,
                              MENU_SETTING_SHOW_OWN_NUMBER,
                              MENU_MTPNP_SHOW_CARD2_OWNER_NUMBER,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_OWN_NO, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SHOW_CARD2_OWNER_NUMBER,
                              MENU_MTPNP_DM_SHOW_OWNER_NUMBER,
                              0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_SHOW_OWNER_NUMBER, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CARD2_OWNER_NUMBER_OPTION, 0, 2,
                              MENU_MTPNP_CARD2_OWNER_NUMBER_EDIT,
                              MENU_MTPNP_CARD2_OWNER_NUMBER_ERASE,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CARD2_OWNER_NUMBER_EDIT,
                              MENU_MTPNP_CARD2_OWNER_NUMBER_OPTION, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_EDIT, IMG_MITEM1052));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CARD2_OWNER_NUMBER_ERASE,
                              MENU_MTPNP_CARD2_OWNER_NUMBER_OPTION, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_ERASE, IMG_MITEM1051));
    /* owner number end */

    /* adn begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_ADD_SIM2, MITEM102_PBOOK_NEW_ENTRY, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_SIM2PHB_ADD_NEW_ENTRY,
                              IMG_ID_CARD2_PHB_STORAGE_SIM));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_DELALL_SIM2, MITEM103_PBOOK_DELETE_ALL, 0, SHOW, NONMOVEABLE, DISP_LIST,
                              STRING_MTPNP_SIM2PHB_DELETEALL, IMG_ID_CARD2_PHB_STORAGE_SIM));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_COPY_SIM2TOPHONE, MITEM1013_PBOOK_COPY_ENTRY, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_COPY_SIM2TOPHONE, IMG_ID_PHB_NO_IMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_MOVE_SIM2TOPHONE, MITEM1014_PBOOK_MOVE, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_MOVE_SIM2TOPHONE, IMG_ID_PHB_NO_IMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_COPY_PHONETOSIM2, MITEM1013_PBOOK_COPY_ENTRY, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_COPY_PHONETOSIM2, IMG_ID_PHB_NO_IMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_MOVE_PHONETOSIM2, MITEM1014_PBOOK_MOVE, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_MOVE_PHONETOSIM2, IMG_ID_PHB_NO_IMAGE));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_COPY_SIM2TOSIM1, MITEM1013_PBOOK_COPY_ENTRY, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_SIM2PHB_COPY_SIM2TOSIM1,
                              IMG_ID_PHB_NO_IMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_MOVE_SIM2TOSIM1, MITEM1014_PBOOK_MOVE, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_MOVE_SIM2TOSIM1, IMG_ID_PHB_NO_IMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_COPY_SIM1TOSIM2, MITEM1013_PBOOK_COPY_ENTRY, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_COPY_SIM1TOSIM2, IMG_ID_PHB_NO_IMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_MOVE_SIM1TOSIM2, MITEM1014_PBOOK_MOVE, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_MOVE_SIM1TOSIM2, IMG_ID_PHB_NO_IMAGE));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_COPY_SIM1TOPHONE, MITEM1013_PBOOK_COPY_ENTRY, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_SIM2PHB_COPY_SIM1TOPHONE,
                              IMG_ID_PHB_NO_IMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_MOVE_SIM1TOPHONE, MITEM1014_PBOOK_MOVE, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_MOVE_SIM1TOPHONE, IMG_ID_PHB_NO_IMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_COPY_PHONETOSIM1, MITEM1013_PBOOK_COPY_ENTRY, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_COPY_PHONETOSIM1, IMG_ID_PHB_NO_IMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_MOVE_PHONETOSIM1, MITEM1014_PBOOK_MOVE, 0, SHOW, MOVEABLEWITHINPARENT,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_MOVE_PHONETOSIM1, IMG_ID_PHB_NO_IMAGE));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_COPYALL_SIM2TOPHONE, MITEM104_PBOOK_COPY_ALL, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_SIM2PHB_COPYALL_SIM2TOPHONE,
                              IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM2TOPHONE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_COPYALL_PHONETOSIM2, MITEM104_PBOOK_COPY_ALL, 0, SHOW, NONMOVEABLE,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_COPYALL_PHONETOSIM2,
                              IMG_ID_MTPNP_PHB_COPYALL_FROM_PHONETOSIM2));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_COPYALL_SIM1TOSIM2, MITEM104_PBOOK_COPY_ALL, 0, SHOW, NONMOVEABLE,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_COPYALL_SIM1TOSIM2,
                              IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM1TOSIM2));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_COPYALL_SIM2TOSIM1, MITEM104_PBOOK_COPY_ALL, 0, SHOW, NONMOVEABLE,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_COPYALL_SIM2TOSIM1,
                              IMG_ID_MTPNP_PHB_COPYALL_FROM_SIM2TOSIM1));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PB_PRE_STORAGE_SIM2, MITEM1102_PBOOK_STORAGE_LOCATION, 0, SHOW, NONMOVEABLE,
                              DISP_LIST, STRING_MTPNP_SIM2PHB_PRESTORAGE, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PHB_NLF_SIM2, MENU_ID_PHB_NAME_LIST_FILTER, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_SIM2PHB_NLF_SIM2, 0));
    /* adn end */

    /* fdn begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FDN_MAIN, MENU_MTPNP_SECURITY_SETTING, 2,
                                  MENU_MTPNP_MENU_FDN_MODE,
                                  MENU_MTPNP_MENU_FDN_LIST,
                                  SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_SLAVE_FIXED_DIAL, 0));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MENU_FDN_MODE, MENU_MTPNP_FDN_MAIN, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SETTING_FDL_MODE, 0));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MENU_FDN_LIST, MENU_MTPNP_FDN_MAIN, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SETTING_FDL_LIST, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FDN_VIEW_OPTIONS_MAIN,
                              0, 3,
                              MENU_MTPNP_FDN_VIEW_OPTIONS_ADD,
                              MENU_MTPNP_FDN_VIEW_OPTIONS_EDIT,
                              MENU_MTPNP_FDN_VIEW_OPTIONS_DELETE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FDN_VIEW_OPTIONS_ADD,
                              MENU_MTPNP_FDN_VIEW_OPTIONS_MAIN, 2,
                              MENU_MTPNP_FDN_NAME,
                              MENU_MTPNP_FDN_NUMBER, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_ADD, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FDN_NAME,
                              MENU_MTPNP_FDN_VIEW_OPTIONS_ADD, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SETTING_FDL_NAME, IMG_NAME));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FDN_NUMBER,
                              MENU_MTPNP_FDN_VIEW_OPTIONS_ADD, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SETTING_FDL_NUMBER, IMG_MOBILE_NUMBER));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FDN_VIEW_OPTIONS_EDIT,
                              MENU_MTPNP_FDN_VIEW_OPTIONS_MAIN, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_EDIT, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_FDN_VIEW_OPTIONS_DELETE,
                              MENU_MTPNP_FDN_VIEW_OPTIONS_MAIN, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_DELETE, 0));
    /* fdn end */

    /* call setting */
    ADD_APPLICATION_MENUITEM2((MENU_MTPNP_CALL_SETTING,
                                  MENU_ID_UCM_CALL_SETTING,
                              #ifndef __MMI_REMOVE_CALLER_ID__
                                  MENU_MTPNP_CALL_ID,
                              #endif /* __MMI_REMOVE_CALLER_ID__ */
                                  MENU_MTPNP_CALL_WAIT,
                                  MENU_MTPNP_CALL_FORWARD,
                                  MENU_MTPNP_CALL_BARRING,
                                  MENU_MTPNP_LINE_SWITCH,
                                  MENU_ITEM_END,
                                  SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_CALL_SETTING, 0));

#ifndef __MMI_REMOVE_CALLER_ID__
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_ID,
                              MENU_MTPNP_CALL_SETTING,
                              3,
                              MENU_MTPNP_CALL_ID_AUTO,
                              MENU_MTPNP_CALL_ID_HIDE_ID,
                              MENU_MTPNP_CALL_ID_SHOW_ID, SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_CALL_ID, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_ID_AUTO, MENU_MTPNP_CALL_ID, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_CLI_SET_NETWORK, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_ID_SHOW_ID, MENU_MTPNP_CALL_ID, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_CLI_SEND_ID, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_ID_HIDE_ID, MENU_MTPNP_CALL_ID, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_CLI_HIDE_ID, NULL));
#endif

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_LINE_SWITCH,
                              MENU_MTPNP_CALL_SETTING, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_LINE_SWITCH, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_LSW_LN1, MENU_MTPNP_LINE_SWITCH, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_LSW_LINE1, IMG_SLAVE_LSW_LINE1));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_LSW_LN2, MENU_MTPNP_LINE_SWITCH, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_LSW_LINE2, IMG_SLAVE_LSW_LINE2));

    /*mtpnp call wait */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_WAIT,
                              MENU_MTPNP_CALL_SETTING,
                              3,
                              MENU8237_MNGCALL_CALWAIT_MENU_ON,
                              MENU8237_MNGCALL_CALWAIT_MENU_OFF,
                              MENU8237_MNGCALL_CALWAIT_MENU_QUERY,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_LINE_WAIT, NULL));

    /*mtpnp call forward */
#ifdef __MMI_SS_CF_ALLCOND_MENU__
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_FORWARD,
                              MENU_MTPNP_CALL_SETTING,
                              7,
                              MENU8238_MNGCALL_CALFWD_VOICECALL,
                              MENU8239_CALFWD_VOICECALL_UNREACHABLE,
                              MENU8239_CALFWD_VOICECALL_NOANSWER,
                              MENU8239_CALFWD_VOICECALL_BUSY,
                              MENU8239_CALFWD_VOICECALL_ALLCOND,
                              MENU8238_MNGCALL_CALFWD_DATACALL,
                              MENU_CALL_FWD_CANCELALL, SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_CALL_FORWARD, NULL));
#else
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_FORWARD,
                              MENU_MTPNP_CALL_SETTING,
                              6,
                              MENU8238_MNGCALL_CALFWD_VOICECALL,
                              MENU8239_CALFWD_VOICECALL_UNREACHABLE,
                              MENU8239_CALFWD_VOICECALL_NOANSWER,
                              MENU8239_CALFWD_VOICECALL_BUSY,
                              MENU8238_MNGCALL_CALFWD_DATACALL,
                              MENU_CALL_FWD_CANCELALL, SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_CALL_FORWARD, NULL));
#endif

    /*mtpnp call barring */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_BARRING,
                              MENU_MTPNP_CALL_SETTING,
                              4,
                              MENU_CALL_BARRING_OUTGOING,
                              MENU_CALL_BARRING_INCOMING,
                              MENU_CALL_BARRING_CANCELALL,
                              MENU_CALL_BARRING_CHANGEPASS,
                              SHOW, NONMOVEABLE, DISP_LIST, STRING_MTPNP_LINE_BARRING, NULL));

    /* security setting begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_SECURITY_SETTING,
                              MAIN_MENU_SETTINGS_MENUID,
                              MTPNP_ENUM_TOTAL_DM_SECSET,
                              MENU9101_SECURITY,
                              MENU_MTPNP_SECURITY_SETTING,
                              MENU9165_PHONE_LOCK,
                          #ifdef __MMI_AUTO_KEYPAD_LOCK__
                              MENU9178_AKPL_TIME,
                          #endif
                              MENU9170_CHANGE_PASSWORD,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_MENU9101_SECURITY, IMG_SETTING_SECURITY));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SECURITY_SETTING,
                              MENU_MTPNP_DM_SECURITY_SETTING,
                              MTPNP_ENUM_TOTAL_SECURITY_SETTING,
                              MENU_MTPNP_SIM_LOCK,
                              MENU_MTPNP_FDN_MAIN,
                              MENU_MTPNP_CHANGE_PASSWORD,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_SECURITY_SETTING, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SIM_LOCK, MENU_MTPNP_SECURITY_SETTING, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CARD2_PINLOCK, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CHANGE_PASSWORD,
                              MENU_MTPNP_SECURITY_SETTING,
                              MTPNP_ENUM_TOTAL_CHANGE_PASSWORD,
                              MENU_MTPNP_CP_PIN1,
                              MENU_MTPNP_CP_PIN2,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_CHANGE_PASSWORD, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CP_PIN1, MENU_MTPNP_CHANGE_PASSWORD, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CP_PIN1, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CP_PIN2, MENU_MTPNP_CHANGE_PASSWORD, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CP_PIN2, 0));
    /* security setting end */

    /* plmn begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_NETWORK_SETUP,
                              MAIN_MENU_SETTINGS_MENUID, 2,
                              MENU9185_NETWORK_SETUP,
                              MENU_MTPNP_NETWORK_SETUP,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ID_NETSET_MITEM9185, IMG_SETTING_NETWORK));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_NETWORK_SETUP,
                              MENU_MTPNP_DM_NETWORK_SETUP,
                              MTPNP_ENUM_TOTAL_NETWORK_SETUP,
                              MENU_MTPNP_SELECTION_MODE,
                              MENU_MTPNP_PREFERRED_NETWORKS,
                              MENU_MTPNP_GPRS_CONNECTION,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_NETWORK_SETUP, IMG_SETTING_NETWORK));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SELECTION_MODE,
                              MENU_MTPNP_NETWORK_SETUP,
                              MTPNP_ENUM_TOTAL_SELECTION_MODE,
                              MENU_MTPNP_SELECTION_MODE_AUTOMATIC, MENU_MTPNP_SELECTION_MODE_MANUAL,
                          #ifdef __MANUAL_MODE_NW_SEL__
                              MENU_MTPNP_SELECTION_MODE_CHOICE,
                          #endif /* __MANUAL_MODE_NW_SEL__ */
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STRING_MTPNP_SELECTION_MODE, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PREFERRED_NETWORKS, MENU_MTPNP_NETWORK_SETUP, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_PREFERRED_NETWORKS, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_GPRS_CONNECTION, MENU_MTPNP_NETWORK_SETUP, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_GPRS_CONNECTION, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SELECTION_MODE_AUTOMATIC, MENU_MTPNP_SELECTION_MODE, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                          #ifdef __MANUAL_MODE_NW_SEL__
                              STR_ID_NETSET_SELECTION_NEW_SEARCH,
                          #else /* __MANUAL_MODE_NW_SEL__ */
                              STRING_MTPNP_NETSET_AUTOMATIC
                          #endif /* __MANUAL_MODE_NW_SEL__ */
                              NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SELECTION_MODE_MANUAL, MENU_MTPNP_SELECTION_MODE, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                          #ifdef __MANUAL_MODE_NW_SEL__
                              STRING_MTPNP_NETSET_SELECT_NETWORK,
                          #else /* __MANUAL_MODE_NW_SEL__ */
                              STRING_MTPNP_NETSET_MANUAL
                          #endif /* __MANUAL_MODE_NW_SEL__ */
                              NULL));

#ifdef __MANUAL_MODE_NW_SEL__
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SELECTION_MODE_CHOICE, MENU_MTPNP_SELECTION_MODE, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ID_NETSET_SELECTION_MODE_CHOICE, NULL));
#endif /* __MANUAL_MODE_NW_SEL__ */

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_PRF_NWK_OPTIONS_PSEUDO,
                              0, 4,
                              MITEM_MTPNP_PRR_NWK_ADD,
                              MITEM_MTPNP_PRR_NWK_NEW,
                              MITEM_MTPNP_PRR_NWK_EDIT,
                              MITEM_MTPNP_PRR_NWK_DELETE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_NETSET_OPTIONS, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_PRR_NWK_ADD, MITEM_MTPNP_PRF_NWK_OPTIONS_PSEUDO, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ID_NETSET_MITEM_PRF_NWK_ADD, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_PRR_NWK_NEW, MITEM_PRF_NWK_OPTIONS_PSEUDO, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_NETSET_PRF_NWK_NEW, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_PRR_NWK_EDIT, MITEM_PRF_NWK_OPTIONS_PSEUDO, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_NETSET_PRF_NWK_EDIT, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_PRR_NWK_DELETE, MITEM_PRF_NWK_OPTIONS_PSEUDO, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_DELETE, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_ADD_FROM_LIST_OPTIONS, 0, 3,
                              MENU_MTPNP_ADD_FROM_LIST_DONE,
                              MENU_MTPNP_ADD_FROM_LIST_SORT_BY_DEFAULT,
                              MENU_MTPNP_ADD_FROM_LIST_SORT_BY_ALPHABET,
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STR_GLOBAL_OPTIONS, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_ADD_FROM_LIST_DONE, MENU_MTPNP_ADD_FROM_LIST_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_SELECT, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_ADD_FROM_LIST_SORT_BY_DEFAULT, MENU_MTPNP_ADD_FROM_LIST_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_PLMN_LIST_SORT_BY_DEFAULT, 0));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_ADD_FROM_LIST_SORT_BY_ALPHABET, MENU_MTPNP_ADD_FROM_LIST_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_PLMN_LIST_SORT_BY_ALPHABET, 0));
    /* plmn end */

    /* cell broadcast messages begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_CB_MESSAGES,
                              MAIN_MENU_MESSAGES_MENUID, 2,
                              MESSAGES_MENU_CB_MENUID,
                              MENU_MTPNP_CB_MESSAGES,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_CB_MENUENTRY, IMG_SMS_CB_MENUENTRY));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CB_MESSAGES,
                              MENU_MTPNP_DM_CB_MESSAGES,
                              MTPNP_ENUM_TOTAL_CB_MESSAGES,
                              MITEM_MTPNP_CB_SERVICE,
                              MITEM_MTPNP_CB_READ_MESSAGE,
                              MITEM_MTPNP_CB_LANGUAGE,
                              MITEM_MTPNP_CB_CHANNELS,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CB_MENUENTRY, IMG_SMS_CB_MENUENTRY));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_CB_SERVICE,
                              MENU_MTPNP_CB_MESSAGES, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CB_SERVICE, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_CB_READ_MESSAGE,
                              MENU_MTPNP_CB_MESSAGES, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CB_READ_MESSAGE, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_CB_CHANNELS,
                              MENU_MTPNP_CB_MESSAGES, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CB_CHANNELS, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_CB_LANGUAGE,
                              MENU_MTPNP_CB_MESSAGES, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CB_LANGUAGE, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_CB_CHANNEL_ENBL_OPTIONS,
                              0, 4,
                              MITEM_MTPNP_CB_CHANNEL_SELECT,
                              MITEM_MTPNP_CB_CHANNEL_ADD,
                              MITEM_MTPNP_CB_CHANNEL_EDIT,
                              MITEM_MTPNP_CB_CHANNEL_DELETE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CB_CHANNEL_ENBL_OPTIONS, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_CB_CHANNEL_ADD,
                              MITEM_MTPNP_CB_CHANNEL_ENBL_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_ADD, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_CB_CHANNEL_EDIT,
                              MITEM_MTPNP_CB_CHANNEL_ENBL_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_EDIT, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_CB_CHANNEL_DELETE,
                              MITEM_MTPNP_CB_CHANNEL_ENBL_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_DELETE, NULL));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_CB_CHANNEL_SELECT,
                              MITEM_MTPNP_CB_CHANNEL_ENBL_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_SELECT, NULL));
    /* cell broadcast messages end */

    /* voice mail begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_VMAIL,
                              MAIN_MENU_MESSAGES_MENUID, 2,
                              MESSAGES_MENU_VMAIL_MENUID,
                              MENU_MTPNP_VMAIL,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_VMAIL_MENUENTRY, IMG_SMS_VMAIL_MENUENTRY));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_VMAIL,
                              MENU_MTPNP_DM_VMAIL, 0,
                              SHOW, MOVEABLEWITHINPARENT | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_VMAIL_MENUENTRY, IMG_SMS_VMAIL_MENUENTRY));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_VOICE_MAIL_OPTION,
                              0, 2,
                              MITEM_MTPNP_VM_EDIT,
                              MITEM_MTPNP_VM_CONNECT_TO_VOICE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_VM_EDIT,
                              MITEM_MTPNP_VOICE_MAIL_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_EDIT, IMG_GLOBAL_OK));

    ADD_APPLICATION_MENUITEM((MITEM_MTPNP_VM_CONNECT_TO_VOICE,
                              MITEM_MTPNP_VOICE_MAIL_OPTION,
                              0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_VM_CONNECT_TO_VOICE_ID, IMG_GLOBAL_OK));
    /* voice mail end */

    /* message setup begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DM_MSG_SETTINGS,
                          #ifdef __MMI_UNIFIED_MESSAGE__
                                  MENU_ID_UM_SETTING,
                          #else /* __MMI_UNIFIED_MESSAGE__ */
                              #ifdef __MMI_MESSAGES_MULTI_APP__
                                  MESSAGES_MENU_SMS_MENUID,
                              #else /* __MMI_MESSAGES_MULTI_APP__ */
                                  MAIN_MENU_MESSAGES_MENUID,
                              #endif /* __MMI_MESSAGES_MULTI_APP__ */
                          #endif /* __MMI_UNIFIED_MESSAGE__ */
                              MTPNP_ENUM_TOTAL_DM_MSG_SETUP,
                              MESSAGES_MENU_MSG_SETTINGS_MENUID,
                              MENU_MTPNP_MSG_SETTINGS_MENUID,
                          #ifndef __MMI_UNIFIED_MESSAGE__
                              MENU_MTPNP_SMS_SHOW_STYLE,
                          #endif /* __MMI_UNIFIED_MESSAGE__ */
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                          #ifdef __MMI_UNIFIED_MESSAGE__
                              STR_UM_SMS_ID, IMG_MESSAGE_SMS_MENUENTRY
                          #else /* __MMI_UNIFIED_MESSAGE__ */
                              STR_MESSAGESETUP_MENUENTRY, IMG_SMS_MSG_SETTINGS_MENUENTRY
                          #endif /* __MMI_UNIFIED_MESSAGE__ */
                              ));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MSG_SETTINGS_MENUID,
                              MENU_MTPNP_DM_MSG_SETTINGS,
                              MTPNP_ENUM_TOTAL_MESSAGES_SETUP,
                              MENU_MTPNP_PROFILE_SETTING,
                              MENU_MTPNP_COMMONSETTING,
                      #if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
                              MENU_MTPNP_MEMSTATUS,
                          #ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                              MENU_MTPNP_PREFEREDSTORAGE,
                          #endif
                      #endif
                              SHOW, MOVEABLEACROSSPARENT, DISP_LIST,
                              STRING_MTPNP_MESSAGESETUP_MENUENTRY, IMG_SMS_MSG_SETTINGS_MENUENTRY));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PROFILE_SETTING,
                              MENU_MTPNP_MSG_SETTINGS_MENUID, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_PROFILE_SETTING_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_COMMONSETTING,
                              MENU_MTPNP_MSG_SETTINGS_MENUID, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_COMMONSETTING_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));

#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MEMSTATUS,
                              MENU_MTPNP_MSG_SETTINGS_MENUID, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_SMSSTATUS_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PREFEREDSTORAGE,
                              MENU_MTPNP_MSG_SETTINGS_MENUID, 2,
                              MENU_MTPNP_PREFEREDSTORAGE_SIM,
                              MENU_MTPNP_PREFEREDSTORAGE_ME,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_PREFEREDSTORAGE_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PREFEREDSTORAGE_ME,
                              MENU_MTPNP_PREFEREDSTORAGE, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_ME_STORAGE_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_PREFEREDSTORAGE_SIM,
                              MENU_MTPNP_PREFEREDSTORAGE, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_SIM_STORAGE_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#endif

    /* message setup end */

    /* vcard begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_VCARD_RECV_OPTION_TO_SIM, MENU_ID_VCARD_RECV_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_VCARD_SAVE_TO_SIM2, 0));
    /* vcard end */

    /* SMS */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_EMS_ED_OPT_DONE,
                              EMS_ED_OPTIONS_MENU_ID, NUM_MESSAGES_INBOXSEND_MENU,
                              SEND_OPT_SEND_ONLY_MENUID, SEND_OPT_SAVE_AND_SEND_MENUID, SEND_OPT_SAVE_MENUID,
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
                              SEND_OPT_SEND_TO_MANY_MENUID,
#endif
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
                              SEND_OPT_SEND_BY_GROUP_MENUID,
#endif
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_SMS_SLAVE_DONE, IMG_SMS_COMMON_NOIMAGE));
    /* Outbox Send SMS from SIM2 */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_OUTBOX_OPT_SEND_SMS,
							  SMS_OUTBOX_OPTIONS_MENUID,  
							  NUM_MESSAGES_OUTBOXSIM2SEND_MENU,
							  SEND_OPT_SEND_ONLY_MENUID,
						  #if defined(__MMI_MESSAGES_SEND_TO_MANY__)
							  SEND_OPT_SEND_TO_MANY_MENUID,
						  #endif
						  #if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
							  SEND_OPT_SEND_BY_GROUP_MENUID,
						  #endif
							  SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
							  STRING_MTPNP_OUTBOX_SLAVE_SEND_SMS,    
							  IMG_SMS_COMMON_NOIMAGE));
													
#ifdef __MMI_SEND_BY_SEARCH_NAME__
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_ONLY_MENUID, MENU_MTPNP_EMS_ED_OPT_DONE,
                              2,
                              SEND_OPT_SEND_BY_NUMBER,
                              SEND_OPT_SEND_BY_NAME,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SEND_ONLY_MENU_ITEM, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_BY_NUMBER, SEND_OPT_SEND_ONLY_MENUID,
                              0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ENTER_NUMBER_TO_MANY, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_BY_NAME, SEND_OPT_SEND_ONLY_MENUID,
                              0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SEARCH_PHB_TO_MANY, IMG_SMS_COMMON_NOIMAGE));
#else
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_ONLY_MENUID, MENU_MTPNP_EMS_ED_OPT_DONE,
                              0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SEND_ONLY_MENU_ITEM, IMG_SMS_COMMON_NOIMAGE));
#endif
    ADD_APPLICATION_MENUITEM((SEND_OPT_SAVE_AND_SEND_MENUID,
                              MENU_MTPNP_EMS_ED_OPT_DONE, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STR_SAVE_AND_SEND_MENU_ITEM, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((SEND_OPT_SAVE_MENUID,
                              MENU_MTPNP_EMS_ED_OPT_DONE, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_SAVE, IMG_SMS_COMMON_NOIMAGE));
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_MENUID,
                              MENU_MTPNP_EMS_ED_OPT_DONE, 2,
                              SEND_OPT_SEND_TO_MANY_BY_LIST,
                              SEND_OPT_SEND_TO_MANY_NOW,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SENDTOMANY_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_BY_LIST,
                              SEND_OPT_SEND_TO_MANY_MENUID, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SENDTOMANY_LIST, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_NOW,
                              SEND_OPT_SEND_TO_MANY_MENUID, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SENDTOMANY_NOW, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_BY_LIST_OPTION,
                              0, 2,
                              SEND_OPT_SEND_TO_MANY_BY_LIST_EDIT,
                              SEND_OPT_SEND_TO_MANY_BY_LIST_ERASE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_BY_LIST_EDIT,
                              SEND_OPT_SEND_TO_MANY_BY_LIST_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_EDIT, IMG_GLOBAL_OK));
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_TO_MANY_BY_LIST_ERASE,
                              SEND_OPT_SEND_TO_MANY_BY_LIST_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_VM_2_ERASE_ID, IMG_GLOBAL_OK));
#endif /* defined(__MMI_MESSAGES_SEND_TO_MANY__) */
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
    ADD_APPLICATION_MENUITEM((SEND_OPT_SEND_BY_GROUP_MENUID,
                              MENU_MTPNP_EMS_ED_OPT_DONE, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_SENDBYGROUP_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
#endif /* defined(__MMI_MESSAGES_SEND_BY_GROUP__) */

    /* Forward SMS */
    ADD_APPLICATION_MENUITEM((SMS_INBOX_OPT_FORWARD_MENUID,
                              SMS_INBOX_OPTIONS_MENUID, 2,
                              MENU_MTPNP_MSGBOX_OPT_MASTER_FORWARD,
                              MENU_MTPNP_MSGBOX_OPT_SLAVE_FORWARD,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FORWARD_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MSGBOX_OPT_MASTER_FORWARD,
                              SMS_INBOX_OPT_FORWARD_MENUID, NUM_MESSAGES_INBOX_FORWARD_MENU, SEND_OPT_SEND_ONLY_MENUID,
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
                              SEND_OPT_SEND_TO_MANY_MENUID,
#endif
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
                              SEND_OPT_SEND_BY_GROUP_MENUID,
#endif
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_MASTER_MSGBOX_FORWARD, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MSGBOX_OPT_SLAVE_FORWARD,
                              SMS_INBOX_OPT_FORWARD_MENUID, NUM_MESSAGES_INBOX_FORWARD_MENU, SEND_OPT_SEND_ONLY_MENUID,
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
                              SEND_OPT_SEND_TO_MANY_MENUID,
#endif
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
                              SEND_OPT_SEND_BY_GROUP_MENUID,
#endif
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_SLAVE_MSGBOX_FORWARD, IMG_SMS_COMMON_NOIMAGE));

    ADD_APPLICATION_MENUITEM((SMS_OUTBOX_OPT_FORWARD_MENUID,
                              SMS_OUTBOX_OPTIONS_MENUID, 2,
                              MENU_MTPNP_MSGBOX_OPT_MASTER_FORWARD,
                              MENU_MTPNP_MSGBOX_OPT_SLAVE_FORWARD,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FORWARD_MENUENTRY, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MSGBOX_OPT_MASTER_FORWARD,
                              SMS_OUTBOX_OPT_FORWARD_MENUID, NUM_MESSAGES_OUTBOXSEND_MENU, SEND_OPT_SEND_ONLY_MENUID,
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
                              SEND_OPT_SEND_TO_MANY_MENUID,
#endif
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
                              SEND_OPT_SEND_BY_GROUP_MENUID,
#endif
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_MASTER_MSGBOX_FORWARD, IMG_SMS_COMMON_NOIMAGE));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MSGBOX_OPT_SLAVE_FORWARD,
                              SMS_OUTBOX_OPT_FORWARD_MENUID, NUM_MESSAGES_OUTBOXSEND_MENU, SEND_OPT_SEND_ONLY_MENUID,
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
                              SEND_OPT_SEND_TO_MANY_MENUID,
#endif
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
                              SEND_OPT_SEND_BY_GROUP_MENUID,
#endif
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_SLAVE_MSGBOX_FORWARD, IMG_SMS_COMMON_NOIMAGE));
    /* Forward SMS */

    /* sms show begin */
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_MASTER_INBOX,
                              MESSAGES_MENU_INBOX_MENUID,
                              0,
                              SHOW, MOVEABLEWITHINPARENT | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_SMS_MASTER_INBOX, IMG_SMS_INBOX_MENUENTRY));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SLAVE_INBOX,
                              MESSAGES_MENU_INBOX_MENUID,
                              0,
                              SHOW, MOVEABLEWITHINPARENT | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_SMS_SLAVE_INBOX, IMG_SMS_INBOX_MENUENTRY));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_MASTER_OUTBOX,
                              MESSAGES_MENU_OUTBOX_MENUID,
                              0,
                              SHOW, MOVEABLEWITHINPARENT | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_SMS_MASTER_OUTBOX, IMG_SMS_OUTBOX_MENUENTRY));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SLAVE_OUTBOX,
                              MESSAGES_MENU_OUTBOX_MENUID,
                              0,
                              SHOW, MOVEABLEWITHINPARENT | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_SMS_SLAVE_OUTBOX, IMG_SMS_OUTBOX_MENUENTRY));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SHOW_STYLE,
                              MENU_MTPNP_DM_MSG_SETTINGS, 2,
                              MENU_MTPNP_SMS_SHOW_MIXED,
                              MENU_MTPNP_SMS_SHOW_DIVIDED,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_SMS_SHOW_STYLE, IMG_MESSAGE_SMS_MENUENTRY));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SHOW_MIXED,
                              MENU_MTPNP_SMS_SHOW_STYLE, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_SMS_SHOW_MIXED, IMG_SMS_COMMON_NOIMAGE));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SHOW_DIVIDED,
                              MENU_MTPNP_SMS_SHOW_STYLE, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_SMS_SHOW_DIVIDED, IMG_SMS_COMMON_NOIMAGE));

	/* sms feature: support selce item */
	ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SELECT_OPTION, 0,
                              2,
                              MENU_MTPNP_SMS_SELECT_SIM1_OPTION,
                              MENU_MTPNP_SMS_SELECT_SIM2_OPTION,
                              SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, NULL, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SELECT_SIM1_OPTION, MENU_MTPNP_SMS_SELECT_OPTION,
                              0, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, STRING_MTPNP_OUTBOX_MASTER_SEND_SMS, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SELECT_SIM2_OPTION, MENU_MTPNP_SMS_SELECT_OPTION,
                              0, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, STRING_MTPNP_OUTBOX_SLAVE_SEND_SMS, NULL));

	/* sms feature: support selcet item when save sms*/
	ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SELECT_SAVE_OPTION, 0,
                              2,
                              MENU_MTPNP_SMS_SELECT_SAVE_SIM1_OPTION,
                              MENU_MTPNP_SMS_SELECT_SAVE_SIM2_OPTION,
                              SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, NULL, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SELECT_SAVE_SIM1_OPTION, MENU_MTPNP_SMS_SELECT_SAVE_OPTION,
                              0, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, STRING_MTPNP_SAVE_SMS_TO_SIM1, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SMS_SELECT_SAVE_SIM2_OPTION, MENU_MTPNP_SMS_SELECT_SAVE_OPTION,
                              0, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, STRING_MTPNP_SAVE_SMS_TO_SIM2, NULL));
    /* sms show end */

    /* SMS */

    /*CC Menu */
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION, 0, 46
#ifdef __MMI_SOUND_RECORDER__
                              + 1
#endif
                              , SLAVE_NON_ACTIVE_CALL_NET_ACTIVE_MASTER,        //Active non-active call
                              SLAVE_NON_ACTIVE_CALL_NET_ACTIVE_SLAVE, MITEM_INC_OPT_ANSWER,     //anwer master call
                              SLAVE_MENU_CALL_MASTER_INCOMING_REJECT,   //reject master call
                              MITEM_INC_ACT_OPT_HOLD_ACT,       //hold master active call
                              MITEM_INC_ACT_OPT_END_ACT,        //end master active call
                              MITEM_INC_HLD_OPT_RTRV,   //active master hold call
                              MITEM_INC_HLD_OPT_END,    //end master hold call
                              MITEM_IMA_OPT_HOLD_CONF,  //hold master conference call
                              MITEM_IMA_OPT_SPLIT,      //master conference call splict
                              MITEM_IMA_OPT_END_ONE_ACT,        //end one master active call
                              MITEM_IMA_OPT_END_ALL_ACT,        //end all master active call
                              MITEM_INC_MHLD_OPT_RTRV,  //master conference call  switch hold to active
                              MITEM_INC_MHLD_OPT_END,
                              MITEM_IAH_OPT_SWAP,
                              MITEM_IAH_OPT_CONFER,
                              MITEM_IAH_OPT_END_ACT,
                              MITEM_IAH_OPT_END_HLD,
                              MITEM_IAH_OPT_END_ALL,
                              MITEM2019_CM_ALL_ACTIVE_END,
                              MITEM_IAMH_ALL_HELD_END,
                              SLAVE_MENU_CALL_INCOMING_OPT_ANSWER_SLAVE,
                              SLAVE_MENU_CALL_INCOMING_OPT_REJECT_SLAVE,
                              SLAVE_MITEM_INC_ACT_OPT_HOLD_ACT,
                              SLAVE_MITEM_INC_ACT_OPT_END_ACT,
                              SLAVE_MITEM_INC_HLD_OPT_RTRV,
                              SLAVE_MITEM_INC_HLD_OPT_END,
                              SLAVE_MITEM_IMA_OPT_HOLD_CONF,
                              SLAVE_MITEM_IMA_OPT_SPLIT,
                              SLAVE_MITEM_IMA_OPT_END_ONE_ACT,
                              SLAVE_MITEM_IMA_OPT_END_ALL_ACT,
                              SLAVE_MITEM_INC_MHLD_OPT_RTRV,
                              SLAVE_MITEM_INC_MHLD_OPT_END,
                              SLAVE_MITEM_IAH_OPT_SWAP,
                              SLAVE_MITEM_IAH_OPT_CONFER,
                              SLAVE_MITEM_IAH_OPT_END_ACT,
                              SLAVE_MITEM_IAH_OPT_END_HLD,
                              SLAVE_MITEM_IAH_OPT_END_ALL,
                              SLAVE_MITEM2019_CM_ALL_ACTIVE_END,
                              SLAVE_MITEM_IAMH_ALL_HELD_END, MITEM2021_CM_NEWCALL, MITEM2031_CM_PBOOK, MITEM2032_CM_SMS,
#ifdef __MMI_SOUND_RECORDER__
                              MITEM2026_CM_SOUND_RECORDER,
#endif
                              MITEM_INC_ACT_OPT_MUTE,
                              MITEM_INC_ACT_OPT_LOUDSP,
                              MITEM2024_CM_DTMF, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, 0, 0));

    ADD_APPLICATION_MENUITEM((MITEM2031_CM_PBOOK, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_MITEM2031_CM_PBOOK,
                              IMG_MITEM2031_CM_PBOOK));

    ADD_APPLICATION_MENUITEM((MITEM2032_CM_SMS, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_MITEM2032_CM_SMS, IMG_MITEM2032_CM_SMS));
#ifdef __MMI_SOUND_RECORDER__
    ADD_APPLICATION_MENUITEM((MITEM2026_CM_SOUND_RECORDER, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_MITEM2026_CM_SOUND_RECORDER,
                              IMG_MITEM2026_CM_SOUND_RECORDER));
#endif
    ADD_APPLICATION_MENUITEM((MITEM2021_CM_NEWCALL, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_MITEM2021_CM_NEWCALL, 0));
    ADD_APPLICATION_MENUITEM((SLAVE_NON_ACTIVE_CALL_NET_ACTIVE_MASTER, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_ID_CFT_SWAP_TO_MASTER, 0));
    ADD_APPLICATION_MENUITEM((SLAVE_NON_ACTIVE_CALL_NET_ACTIVE_SLAVE, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_ID_CFT_SWAP_TO_SLAVE, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_ID_CFT_SWAP_TO_SLAVE, "Swap to Slave", "Swap to Slave");

    ADD_APPLICATION_STRING2(SLAVE_STR_ID_CFT_SWAP_TO_MASTER, "Swap to Master", "Swap to Master");

    ADD_APPLICATION_MENUITEM((MITEM_INC_OPT_ANSWER, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_OPT_ANSWER_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_OPT_ANSWER_CARD1, "Accept Card1", "Accept Card1");

    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_OPT_ANSWER_SLAVE, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_OPT_ANSWER_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_OPT_ANSWER_CARD2, "Accept Card2", "Accept Card2");


    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_MASTER_INCOMING_REJECT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_OPT_REJECT_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_OPT_REJECT_CARD1, "Reject Card1", "Reject Card1");

    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_OPT_REJECT_SLAVE, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_OPT_REJECT_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_OPT_REJECT_CARD2, "Reject Card2", "Reject Card2");


    ADD_APPLICATION_MENUITEM((MITEM_INC_ACT_OPT_HOLD_ACT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_ACT_OPT_HOLD_ACT_CARD1, 0));

    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_ACT_OPT_HOLD_ACT_CARD1, "Hold Card1", "Hold Card1");

    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_INC_ACT_OPT_HOLD_ACT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_ACT_OPT_HOLD_ACT_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_ACT_OPT_HOLD_ACT_CARD2, "Hold Card2", "Hold Card2");


    ADD_APPLICATION_MENUITEM((MITEM_INC_ACT_OPT_END_ACT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_ACT_OPT_END_ACT_CARD1, 0));

    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_ACT_OPT_END_ACT_CARD1, "End Card1", "End Card1");

    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_INC_ACT_OPT_END_ACT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_ACT_OPT_END_ACT_CARD2, 0));

    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_ACT_OPT_END_ACT_CARD2, "End Card2", "End Card2");



    ADD_APPLICATION_MENUITEM((MITEM_INC_HLD_OPT_RTRV, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_HLD_OPT_RTRV_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_HLD_OPT_RTRV_CARD1, "Retrieve Card1", "Retrieve Card1");
    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_INC_HLD_OPT_RTRV, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_HLD_OPT_RTRV_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_HLD_OPT_RTRV_CARD2, "Retrieve Card2", "Retrieve Card2");

    ADD_APPLICATION_MENUITEM((MITEM_INC_HLD_OPT_END, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_ACT_OPT_END_ACT_CARD1, 0));
    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_INC_HLD_OPT_END, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_ACT_OPT_END_ACT_CARD2, 0));


    ADD_APPLICATION_MENUITEM((MITEM_IMA_OPT_HOLD_CONF, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IMA_OPT_HOLD_CONF_CARD1, 0));

    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IMA_OPT_HOLD_CONF_CARD1, "Hold All Card1", "Hold All Card1");

    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_IMA_OPT_HOLD_CONF, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IMA_OPT_HOLD_CONF_CARD2, 0));

    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IMA_OPT_HOLD_CONF_CARD2, "Hold All Card2", "Hold All Card2");


    ADD_APPLICATION_MENUITEM((MITEM_IMA_OPT_SPLIT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IMA_OPT_SPLIT_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IMA_OPT_SPLIT_CARD1, "Split Card1", "Split Card1");
    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_IMA_OPT_SPLIT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IMA_OPT_SPLIT_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IMA_OPT_SPLIT_CARD2, "Split Card2", "Split Card2");


    ADD_APPLICATION_MENUITEM((MITEM_IMA_OPT_END_ONE_ACT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IMA_OPT_END_ONE_ACT_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IMA_OPT_END_ONE_ACT_CARD1, "End Single Card1", "End Single Card1");
    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_IMA_OPT_END_ONE_ACT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IMA_OPT_END_ONE_ACT_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IMA_OPT_END_ONE_ACT_CARD2, "End Single Card2", "End Single Card2");


    ADD_APPLICATION_MENUITEM((MITEM_IMA_OPT_END_ALL_ACT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IMA_OPT_END_ALL_ACT_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IMA_OPT_END_ALL_ACT_CARD1, "End All Card1", "End All Card1");

    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_IMA_OPT_END_ALL_ACT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IMA_OPT_END_ALL_ACT_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IMA_OPT_END_ALL_ACT_CARD2, "End All Card2", "End All Card2");

    ADD_APPLICATION_MENUITEM((MITEM_INC_MHLD_OPT_RTRV, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_MHLD_OPT_RTRV_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_MHLD_OPT_RTRV_CARD1, "Retrieve All Card1", "Retrieve All Card1");

    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_INC_MHLD_OPT_RTRV, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_MHLD_OPT_RTRV_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_MHLD_OPT_RTRV_CARD2, "Retrieve All Card2", "Retrieve All Card2");

    ADD_APPLICATION_MENUITEM((MITEM_INC_MHLD_OPT_END, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_MHLD_OPT_END_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_MHLD_OPT_END_CARD1, "End All Card1", "String for option End Held Call");

    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_INC_MHLD_OPT_END, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_INC_MHLD_OPT_END_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_INC_MHLD_OPT_END_CARD2, "End All Card2", "End All Card2");

    ADD_APPLICATION_MENUITEM((MITEM_IAH_OPT_SWAP, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAH_OPT_SWAP_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAH_OPT_SWAP_CARD1, "Swap Card1", "Swap Card1");
    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_IAH_OPT_SWAP, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAH_OPT_SWAP_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAH_OPT_SWAP_CARD2, "Swap Card2", "Swap Card2");

    ADD_APPLICATION_MENUITEM((MITEM_IAH_OPT_CONFER, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAH_OPT_CONFER_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAH_OPT_CONFER_CARD1, "Conference Card1", "Conference Card1");
    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_IAH_OPT_CONFER, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAH_OPT_CONFER_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAH_OPT_CONFER_CARD2, "Conference Card2", "Conference Card2");

    ADD_APPLICATION_MENUITEM((MITEM_IAH_OPT_END_ACT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAH_OPT_END_ACT_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAH_OPT_END_ACT_CARD1, "End Active Card1", "End Active Card1");
    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_IAH_OPT_END_ACT, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAH_OPT_END_ACT_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAH_OPT_END_ACT_CARD2, "End Active Card2", "End Active Card2");

    ADD_APPLICATION_MENUITEM((MITEM_IAH_OPT_END_HLD, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAH_OPT_END_HLD_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAH_OPT_END_HLD_CARD1, "End Held Card1", "End Held Card1");

    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_IAH_OPT_END_HLD, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAH_OPT_END_HLD_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAH_OPT_END_HLD_CARD2, "End Held Card2", "End Held Card2");

    ADD_APPLICATION_MENUITEM((MITEM_IAH_OPT_END_ALL, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAH_OPT_END_ALL_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAH_OPT_END_ALL_CARD1, "End All Card1", "End All Card1");
    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_IAH_OPT_END_ALL, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAH_OPT_END_ALL_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAH_OPT_END_ALL_CARD2, "End All Card2", "End All Card2");

    ADD_APPLICATION_MENUITEM((MITEM2019_CM_ALL_ACTIVE_END, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM2019_CM_ALL_ACTIVE_END_CARD1,
                              0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM2019_CM_ALL_ACTIVE_END_CARD1, "End All Active Card1",
                            "End All Active Card1");
    ADD_APPLICATION_MENUITEM((SLAVE_MITEM2019_CM_ALL_ACTIVE_END, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM2019_CM_ALL_ACTIVE_END_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM2019_CM_ALL_ACTIVE_END_CARD2, "End All Active Card2",
                            "End All Active Card2");

    ADD_APPLICATION_MENUITEM((MITEM_IAMH_ALL_HELD_END, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAMH_ALL_HELD_END_CARD1, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAMH_ALL_HELD_END_CARD1, "End All Held Card1", "End All Held Card1");
    ADD_APPLICATION_MENUITEM((SLAVE_MITEM_IAMH_ALL_HELD_END, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_MITEM_IAMH_ALL_HELD_END_CARD2, 0));
    ADD_APPLICATION_STRING2(SLAVE_STR_MITEM_IAMH_ALL_HELD_END_CARD2, "End All Held Card2", "End All Held Card2");

    ADD_APPLICATION_MENUITEM((MITEM_INC_ACT_OPT_MUTE, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_MITEM_INC_ACT_OPT_MUTE, 0));
    ADD_APPLICATION_MENUITEM((MITEM_INC_ACT_OPT_LOUDSP, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_MITEM_INC_ACT_OPT_LOUDSP, 0));
    ADD_APPLICATION_MENUITEM((MITEM2024_CM_DTMF, SLAVE_MENU_CM_INCOMING_AND_ACTIVE_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_MITEM2024_CM_DTMF, IMG_MITEM2024_CM_DTMF));
    ADD_APPLICATION_STRING2(STR_TITLE_SCR_USSN_MSG_CARD1, "Card 1 Information", "Title String for USSN Msg Display");
    ADD_APPLICATION_STRING2(STR_TITLE_SCR_USSD_MSG_CARD1, "Card 1 Information", "Title String for USSD Msg Display");
    ADD_APPLICATION_STRING2(STR_USSD_REQ_CAPTION_CARD1, "Card 1 Sending Request",
                            "Display Caption for USSD req screen");
    ADD_APPLICATION_STRING2(STR_TITLE_SCR_USSR_EDIT_MSG_CARD1, "Card 1 USSR-Edit", "Title String for USSR Msg Edit");
    ADD_APPLICATION_STRING2(STR_TITLE_SCR_USSD_MSG_CARD2, "Card 2 Information", "Title String for USSN Msg Display");
    ADD_APPLICATION_STRING2(STR_TITLE_SCR_USSN_MSG_CARD2, "Card 2 Information", "Title String for USSD Msg Display");
    ADD_APPLICATION_STRING2(STR_TITLE_SCR_USSR_MSG_CARD1, "Card 1 Information", "Title String for USSR Msg Display");
    ADD_APPLICATION_STRING2(STR_TITLE_SCR_USSR_MSG_CARD2, "Card 2 Information", "Title String for USSR Msg Display");
    ADD_APPLICATION_STRING2(STR_TITLE_SCR_USSR_EDIT_MSG_CARD2, "Card 2 Sending Request",
                            "Display Caption for USSD req screen");
    ADD_APPLICATION_STRING2(STR_USSD_REQ_CAPTION_CARD2, "Card 2 USSR-Edit", "Title String for USSR Msg Edit");
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_FORBIDDEN, "Dial Forbidden", "Slave Dial Forbidden");
    ADD_APPLICATION_STRING2(SLAVE_STR_ID_CFT_SWAP_TO_MASTER, "Swap to Card1", "Swap to Master Call");
    ADD_APPLICATION_STRING2(SLAVE_STR_ID_CFT_ACTIVE_MASTER_CALL, "Active Master Call", "Active Master Call");
    ADD_APPLICATION_STRING2(SLAVE_STR_ID_CFT_ACTIVE_SLAVE_CALL, "Active Slave Call", "Active Slave Call");

    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CC_MO_SELETECT_NET, 0,
                              2,
                              SLAVE_MENU_CC_MO_SELETECT_NET_CARD1,
                              SLAVE_MENU_CC_MO_SELETECT_NET_CARD2,
                              SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, NULL, NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CC_MO_SELETECT_NET_CARD1, SLAVE_MENU_CC_MO_SELETECT_NET,
                              0, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, SLAVE_STR_CC_MO_SELETECT_NET_CARD1, NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CC_MO_SELETECT_NET_CARD2, SLAVE_MENU_CC_MO_SELETECT_NET,
                              0, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, SLAVE_STR_CC_MO_SELETECT_NET_CARD2, NULL));

    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CC_CSK_SELETECT_CARD, 0,
                              2,
                              SLAVE_MENU_CC_CSK_SELETECT_CARD1,
                              SLAVE_MENU_CC_CSK_SELETECT_CARD2, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, NULL, NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CC_CSK_SELETECT_CARD1, SLAVE_MENU_CC_CSK_SELETECT_CARD,
                              0, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, SLAVE_STR_CC_CSK_SELETECT_CARD1, NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CC_CSK_SELETECT_CARD2, SLAVE_MENU_CC_CSK_SELETECT_CARD,
                              0, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, SLAVE_STR_CC_CSK_SELETECT_CARD2, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SELECT_CARD, 0,
                              2,
                              MENU_MTPNP_SELECT_CARD_1SELECTED,
                              MENU_MTPNP_SELECT_CARD_2SELECTED, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, NULL, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SELECT_CARD_1SELECTED, MENU_MTPNP_SELECT_CARD,
                              0, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, SLAVE_STR_CC_CSK_SELETECT_CARD1, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SELECT_CARD_2SELECTED, MENU_MTPNP_SELECT_CARD,
                              0, SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, SLAVE_STR_CC_CSK_SELETECT_CARD2, NULL));

    ADD_APPLICATION_STRING2(SLAVE_STR_CC_MO_SELETECT_SELECT_NET, "Net Selection", "Net Selection");
    ADD_APPLICATION_STRING2(SLAVE_STR_CC_MO_SELETECT_NET_CARD1, "Card 1 Call", "Card 1 Call");
    ADD_APPLICATION_STRING2(SLAVE_STR_CC_MO_SELETECT_NET_CARD2, "Card 2 Call", "Card 2 Call");
    ADD_APPLICATION_STRING2(SLAVE_STR_CC_SP_SELETECT_SELECT_NET, "Net Selection", "Net Selection");
    ADD_APPLICATION_STRING2(SLAVE_STR_CC_CSK_SELECT_NET, "Net Selection", "Net Selection");
    ADD_APPLICATION_STRING2(SLAVE_STR_CC_CSK_SELETECT_CARD1, "Card 1 Call", "Card 1 Call");
    ADD_APPLICATION_STRING2(SLAVE_STR_CC_CSK_SELETECT_CARD2, "Card 2 Call", "Card 2 Call");
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_MIX_OPTION, 0,
                              4,
                              SLAVE_MENU_CALL_INCOMING_MIX_OPT_ACCEPT_BOTH,
                              SLAVE_MENU_CALL_INCOMING_MIX_OPT_REJECT_BOTH,
                              SLAVE_MENU_CALL_INCOMING_MIX_OPT_ACCEPTCARD1,
                              SLAVE_MENU_CALL_INCOMING_MIX_OPT_ACCEPTCARD2,
                              SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, NULL, NULL));

    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_MIX_OPT_ACCEPT_BOTH, SLAVE_MENU_CALL_INCOMING_MIX_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_CALL_INCOMING_MIX_OPT_ACCEPT_BOTH,
                              NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_MIX_OPT_REJECT_BOTH, SLAVE_MENU_CALL_INCOMING_MIX_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_CALL_INCOMING_MIX_OPT_REJECT_BOTH,
                              NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_MIX_OPT_ACCEPTCARD1, SLAVE_MENU_CALL_INCOMING_MIX_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_CALL_INCOMING_MIX_OPT_ACCEPTCARD1,
                              NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_MIX_OPT_ACCEPTCARD2, SLAVE_MENU_CALL_INCOMING_MIX_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_CALL_INCOMING_MIX_OPT_ACCEPTCARD2,
                              NULL));
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_INCOMING_MIX_OPT_ACCEPT_BOTH, "Accept Both", "Accept Both");
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_INCOMING_MIX_OPT_REJECT_BOTH, "Reject Both", "Reject Both");
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_INCOMING_MIX_OPT_ACCEPTCARD1, "Accept Card1", "Accept Card1");
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_INCOMING_MIX_OPT_ACCEPTCARD2, "Accept Card2", "Accept Card2");

    ADD_APPLICATION_IMAGE2(IMG_BOTH_INCOMING, CUST_IMG_PATH "\\\\mercury\\\\active\\\\Incoming\\\\CL_BOTH_INCOM.gif",
                           "Image for Both Incoming");

    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_OPTION, 0,
#ifdef __IP_NUMBER__
                              6,
#else
                              4,
#endif
                              SLAVE_MENU_CALL_INCOMING_OPT_ACCEPT,
                              SLAVE_MENU_CALL_INCOMING_OPT_REJECT,
                              SLAVE_MENU_CALL_INCOMING_OPT_CARD1_DIALBACK, SLAVE_MENU_CALL_INCOMING_OPT_CARD2_DIALBACK,
#ifdef __IP_NUMBER__
                              SLAVE_MENU_CALL_INCOMING_OPT_CARD1_IP_DIALBACK,
                              SLAVE_MENU_CALL_INCOMING_OPT_CARD2_IP_DIALBACK,
#endif
                              SHOW, NONMOVEABLE | INSERTABLE, DISP_LIST, NULL, NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_OPT_ACCEPT, SLAVE_MENU_CALL_INCOMING_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_CALL_INCOMING_OPT_ACCEPT, NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_OPT_REJECT, SLAVE_MENU_CALL_INCOMING_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_CALL_INCOMING_OPT_REJECT, NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_OPT_CARD1_DIALBACK, SLAVE_MENU_CALL_INCOMING_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_CALL_INCOMING_OPT_CARD1_DIALBACK,
                              NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_OPT_CARD2_DIALBACK, SLAVE_MENU_CALL_INCOMING_OPTION, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_CALL_INCOMING_OPT_CARD2_DIALBACK, NULL));
#ifdef __IP_NUMBER__
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_OPT_CARD1_IP_DIALBACK, SLAVE_MENU_CALL_INCOMING_OPTION,
                              0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_CALL_INCOMING_OPT_CARD1_IP_DIALBACK,
                              NULL));
    ADD_APPLICATION_MENUITEM((SLAVE_MENU_CALL_INCOMING_OPT_CARD2_IP_DIALBACK, SLAVE_MENU_CALL_INCOMING_OPTION, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, SLAVE_STR_CALL_INCOMING_OPT_CARD2_IP_DIALBACK, NULL));
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_INCOMING_OPT_CARD1_IP_DIALBACK, "Card1 IP Dial back", "Card1 IP Dial back");
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_INCOMING_OPT_CARD2_IP_DIALBACK, "Card2 IP Dial back", "Card2 IP Dial back");
#endif
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_INCOMING_OPT_ACCEPT, "Accept", "Accept");
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_INCOMING_OPT_REJECT, "Reject", "Reject");
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_INCOMING_OPT_CARD1_DIALBACK, "Card1 Dial back", "Card1 Dial back");
    ADD_APPLICATION_STRING2(SLAVE_STR_CALL_INCOMING_OPT_CARD2_DIALBACK, "Card2 Dial back", "Card2 Dial back");
    /*mtpnp ip dial */
#ifdef __IP_NUMBER__
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_IP_NUM_ACTIVATE, MENU_SETTING_IP_NUM_OPN, 0,
                              0, NONMOVEABLE, 1, STRINT_MTPNP_IP_ACTIVATE, NULL));
    ADD_APPLICATION_STRING2(STRINT_MTPNP_IP_ACTIVATE, "Active Slave", "Active Slave");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_VICON_M, CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\IPdial\\\IP 1.bmp", "master ip");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_VICON_S, CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\IPdial\\\IP 2.bmp", "slave ip");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_VICON_BOTH, CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\IPdial\\\IP 12.bmp",
                           "both ip");
#endif
#ifdef __MMI_UCM__
    ADD_APPLICATION_MENUITEM((MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2,
                              MENU_ID_UCM_NEW_CALL_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_ID_UCM_DIAL_SIM2, 0));
#endif /* __MMI_UCM__ */
    /*call history */
    Mercury_CHResPopulate();
    /*call history */

}

void Mercury_CHResPopulate(void)
{
    Mercury_CLResPopulate();
    Mercury_CHSMSCounterResPopulate();
    Mercury_CHResetResPopulate();
    Mercury_CHCallTimes();
    Mercury_CHCallCost();
    Mercury_CHMissNotify();
#ifndef __SENDKEY2_SUPPORT__
    Mercury_CHISTDualMixedCallLog();
#endif /* __SENDKEY2_SUPPORT__ */
#ifdef __MMI_GPRS_FEATURES__
    Mercury_CHGPRSCounterResPopulate();
#endif
}

void Mercury_CLResPopulate(void)
{
    ADD_APPLICATION_MENUITEM2((MENU_MTPNP_DM_CALL_HISTORY,
                      #ifdef __MMI_UCM__
                              MAIN_MENU_CALL_CENTER,
                      #else /* __MMI_UCM__ */
                          #ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
                              MAIN_MENU_PIM_MENU_ID,
                          #else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */
                              IDLE_SCREEN_MENU_ID,
                          #endif /* __MMI_UCM__ */
                      #endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */
                              MAIN_MENU_CALL_HISTORY,
                              MENU_MTPNP_CALL_HISTORY,
                              MENU_ITEM_END,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, MAIN_MENU_CALL_HISTORY_TEXT,
                          #ifdef __MMI_UCM__
                              IMG_ID_UCM_CALL_HISTORY
                          #else
                              MAIN_MENU_CALL_HISTORY_ICON
                          #endif
                              ));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY,
                              MENU_MTPNP_DM_CALL_HISTORY,
                              MENU_ENUM_TOTAL_CALL_HISTORY,
                              MENU_MTPNP_CALL_HISTORY_MISSED,
                              MENU_MTPNP_CALL_HISTORY_DIALED,
                              MENU_MTPNP_CALL_HISTORY_RECVD,
                              MENU_MTPNP_CALL_HISTORY_DELETE,
                              MENU_MTPNP_CALL_HISTORY_CALLTIME,
                              MENU_MTPNP_CALL_HISTORY_CALLCOST,
                              MENU_MTPNP_CALL_HISTORY_SMSCOUNTER,
                         #ifdef __MMI_GPRS_FEATURES__
                              MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER,
                         #endif
                              SHOW, MOVEABLEWITHINPARENT | INSERTABLE,
                              DISP_LIST, STRING_MTPNP_CALL_HISTORY, IMG_MTPNP_CALL_HISTORY));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_MISSED, MENU_MTPNP_CALL_HISTORY, 0, SHOW,
                              MOVEABLEWITHINPARENT | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_MENU8103_MISSED_CALLS, IMG_MTPNP_MENU8103_MISSED_CALLS));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_DIALED, MENU_MTPNP_CALL_HISTORY, 0, SHOW,
                              MOVEABLEWITHINPARENT | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_MENU8102_DIALED_CALLS, IMG_MTPNP_MENU8102_DIALED_CALLS));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_RECVD,
                              MENU_MTPNP_CALL_HISTORY, 0, SHOW,
                              MOVEABLEWITHINPARENT | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_MENU8101_RECEIVED_CALLS, IMG_MTPNP_MENU8101_RECEIVED_CALLS));

    ADD_APPLICATION_STRING(STRING_MTPNP_CARD1_CALL_HISTORY, "Card1 Call History");
    ADD_APPLICATION_STRING(STRING_MTPNP_CALL_HISTORY, "Card2 Call History");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU8101_RECEIVED_CALLS, "Received Calls", "String for call Received");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU8102_DIALED_CALLS, "Dialed Calls", "String for Call Dialled");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU8103_MISSED_CALLS, "Missed Calls", "String for Missed Calls option");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU8101_SIM1_RECEIVED_CALLS, "SIM1 Received Calls", "String for call Received");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU8102_SIM1_DIALED_CALLS, "SIM1 Dialed Calls", "String for Call Dialled");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU8103_SIM1_MISSED_CALLS, "SIM1 Missed Calls", "String for Missed Calls option");

    ADD_APPLICATION_IMAGE(IMG_MTPNP_CALL_HISTORY, CUST_IMG_PATH "\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_CA.gif");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MENU8101_RECEIVED_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\RECVED_CALL_2.bmp",
                           "Recd. call list options DELETE ALL entry image");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MENU8102_DIALED_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\DIALED_CALL_2.bmp",
                           "Recd. call list options DELETE ALL entry image");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MENU8103_MISSED_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\MISSED_CALL_2.bmp",
                           "Recd. call list options DELETE ALL entry image");

}

void Mercury_CHSMSCounterResPopulate(void)
{
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_SIM1_SMS_CAPTION, "SIM1 sms counter", "SIM1 sms counter");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_SIM2_SMS_CAPTION, "SMS Counter", "SMS COUNTER SCR CAPTION");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SENT_SMS_COUNT, "Sent", "SMS COUNTER SCR SENT ");
    ADD_APPLICATION_STRING2(STRING_MTPNP_RECV_SMS_COUNT, "Received", "SMS COUNTER RECV ");

    ADD_APPLICATION_STRING2(STRING_MTPNP_SCR_RESET_RCVD_SMS_CONFIRM_TEXT, "Delete", "Reset sent/recvd sms counters");

    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_NO_NUMBER, "No msg", "No Messages");
    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_STRING, "msgs", "Messages counter string");

    ADD_APPLICATION_STRING2(STRING_MTPNP_SMS_COUNTER_LSK, "Reset", "SMS COUNTER RESET ");
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_SMSCOUNTER,
                              MENU_MTPNP_CALL_HISTORY, 2,
                              MENU_MTPNP_CALL_HISTORY_SENT,
                              MENU_MTPNP_CALL_HISTORY_RECEIVED, SHOW,
                              MOVEABLEACROSSPARENT | SHORTCUTABLE,
                              DISP_LIST, STRING_MTPNP_MENU_SIM2_SMS_CAPTION, IMG_MTPNP_CARD2_SMS_COUNTER_MENU));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_SENT,
                              MENU_MTPNP_CALL_HISTORY_SMSCOUNTER, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_SENT_SMS_COUNT, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_RECEIVED,
                              MENU_MTPNP_CALL_HISTORY_SMSCOUNTER, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_RECV_SMS_COUNT, NULL));
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD2_SMS_COUNTER_MENU,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\SMS_COUNT_2.bmp",
                           "DELETE ALL entry image");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD1_SMS_COUNTER_MENU,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD1\\\\SMS_COUNT_1.bmp",
                           "DELETE ALL entry image");
}

void Mercury_CHResetResPopulate(void)
{
#ifdef __MMI_CH_DELETE_ALL_LOGS__
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_DELETE,
                              MENU_MTPNP_CALL_HISTORY, 4,
                              MENU_MTPNP_DELLOG_MISSED_CALLS,
                              MENU_MTPNP_DELLOG_DIALED_CALLS,
                              MENU_MTPNP_DELLOG_RECEIVED_CALLS,
                              MENU_MTPNP_ALL_CALLS, SHOW,
                              MOVEABLEWITHINPARENT | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_MENU_CALLHISTORY_RESETCALL, IMG_MTPNP_CARD2_MENU_DELETE_CALLS));
#else
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_DELETE,
                              MENU_MTPNP_CALL_HISTORY, 3,
                              MENU_MTPNP_DELLOG_MISSED_CALLS,
                              MENU_MTPNP_DELLOG_DIALED_CALLS,
                              MENU_MTPNP_DELLOG_RECEIVED_CALLS,
                              SHOW,
                              MOVEABLEWITHINPARENT | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_MENU_CALLHISTORY_RESETCALL, IMG_MTPNP_CARD2_MENU_DELETE_CALLS));
#endif
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DELLOG_RECEIVED_CALLS,
                              MENU_MTPNP_CALL_HISTORY_DELETE, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_MENU_RECEIVED_CALLS, IMG_MTPNP_CARD2_MENU_RECEIVED_CALLS));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DELLOG_DIALED_CALLS,
                              MENU_MTPNP_CALL_HISTORY_DELETE, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_MENU_DIALED_CALLS, IMG_MTPNP_CARD2_MENU_DIALED_CALLS));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DELLOG_MISSED_CALLS,
                              MENU_MTPNP_CALL_HISTORY_DELETE, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_MENU_MISSED_CALLS, IMG_MTPNP_CARD2_MENU_MISSED_CALLS));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_ALL_CALLS, MENU_MTPNP_CALL_HISTORY_DELETE, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                              STR_MTPNP_GLOBAL_DELETE_ALL, 
	                    #ifdef __MMI_DUAL_SIM_MASTER__
                              IMG_MTPNP_CARD2_MENU_DELETE_CALLS
                           #else /* __MMI_DUAL_SIM_MASTER__ */
	                       IMG_MTPNP_SCR_RESETCALLS
	                    #endif /* __MMI_DUAL_SIM_MASTER__ */                         
                              ));
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_SIM1_CALLHISTORY_RESETCALL, "SIM1 Delete Call Log", "RESET ALL CALLS MENU STR");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALLHISTORY_RESETCALL, "Delete Call Log", "RESET ALL CALLS MENU STR");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_RECEIVED_CALLS, "Received Calls", "String for call Received");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_DIALED_CALLS, "Dialed Calls", "String for Call Dialled");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_MISSED_CALLS, "Missed Calls", "String for Missed Calls option");
    ADD_APPLICATION_STRING2(STR_MTPNP_GLOBAL_DELETE_ALL, "Delete All", "String for Missed Calls option");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD2_MENU_RECEIVED_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\RECVED_CALL_2.bmp",
                           "Image for recd Calls option");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD1_MENU_RECEIVED_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD1\\\\RECVED_CALL_1.bmp",
                           "Image for recd Calls option");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD2_MENU_DIALED_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\DIALED_CALL_2.bmp",
                           "Image for Dialed Calls option");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD1_MENU_DIALED_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD1\\\\DIALED_CALL_1.bmp",
                           "Image for Dialed Calls option");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD2_MENU_MISSED_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\MISSED_CALL_2.bmp",
                           "Image for Missed Calls option");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD1_MENU_MISSED_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD1\\\\MISSED_CALL_1.bmp",
                           "Image for Missed Calls option");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_SCR_RESETCALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CRSET.PBM",
                           "RESET CALLS CONFIRM SCR  RSK IMG ");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_SCR_RESETCALLS_CONFIRM,
                           CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_DEL.gif",
                           "RESET CALLS CONFIRM SCR  RSK IMG ");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MENU_CARD1_CALL_HISTORY_CAPTION,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CALL_HISTORY_1.bmp",
                           "Image for Missed Calls option");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MENU_CARD2_CALL_HISTORY_CAPTION,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CALL_HISTORY_2.bmp",
                           "Image for Missed Calls option");


    ADD_APPLICATION_STRING2(STR_MTPNP_SCR_RESETCALLS_CONFIRM_CAPTION, "Delete", "RESET CALLS CONFIRM text ");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_SCR_RESETCALLS_CONFIRM,
                           CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_DEL.gif",
                           "RESET CALLS CONFIRM SCR  RSK IMG ");

    ADD_APPLICATION_STRING2(STRING_MTPNP_CHIST_OPTION_SENDSMS, "Send SMS", "Send SMS message to caller");
    ADD_APPLICATION_STRING2(STRING_MTPNP_CHIST_OPTION_SENDMMS, "Send MMS", "Send MMS message to caller");

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS, 0, 7,
                              MENU_MTPNP_RECEIVED_CALL_MENU_INFO,
                              MENU_MTPNP_RECEIVED_CALL_MENU_DELETE,
                              MENU_MTPNP_RECEIVED_CALL_MENU_SAVE,
                              MENU_MTPNP_RECEIVED_CALL_MENU_CALL,
                              MENU_MTPNP_RECEIVED_CALL_MENU_EDIT,
                              MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS,
                              MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS,
                              SHOW, INSERTABLE, DISP_LIST,
                              STRING_MTPNP_RECEIVED_CALL_LIST_OPTIONS, IMG_MTPNP_CARD2_MENU_RECEIVED_CALLS));

    ADD_APPLICATION_STRING2(STRING_MTPNP_RECEIVED_CALL_LIST_OPTIONS, "Received Call Info Option",
                            "Recd. call list options title string");


    ADD_APPLICATION_STRING2(STRING_MTPNP_RECD_SAVE_MENUENTRY, "Save to Phone book",
                            "Recd call list options Save to phone book entry string");

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
#endif
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_RECEIVED_CALL_MENU_INFO,
                              MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_VIEW, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_RECEIVED_CALL_MENU_CALL,
                              MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_DIAL, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_RECEIVED_CALL_MENU_SAVE,
                              MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_RECD_SAVE_MENUENTRY, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_RECEIVED_CALL_MENU_DELETE,
                              MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_DELETE, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_RECEIVED_CALL_MENU_EDIT,
                              MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_EDIT, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS,
                              MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CHIST_OPTION_SENDSMS, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS,
                              MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CHIST_OPTION_SENDMMS, NULL));

        /******************** Dialed call list ****************/

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DIALED_CALL_LIST_OPTIONS, 0, 7,
                              MENU_MTPNP_DIALED_CALL_MENU_INFO,
                              MENU_MTPNP_DIALED_CALL_MENU_DELETE,
                              MENU_MTPNP_DIALED_CALL_MENU_SAVE,
                              MENU_MTPNP_DIALED_CALL_MENU_CALL,
                              MENU_MTPNP_DIALED_CALL_MENU_EDIT,
                              MENU_MTPNP_DIALED_CALL_MENU_SENDSMS,
                              MENU_MTPNP_DIALED_CALL_MENU_SENDMMS,
                              SHOW, INSERTABLE, DISP_LIST,
                              STRING_MTPNP_DIALED_CALL_LIST_OPTIONS, IMG_MTPNP_CARD2_MENU_DIALED_CALLS));
    ADD_APPLICATION_STRING2(STRING_MTPNP_DIALED_CALL_LIST_OPTIONS, "Dialed Call Info Option",
                            "Dialed call list options title string");


    ADD_APPLICATION_STRING2(STRING_MTPNP_DIALED_SAVE_MENUENTRY, "Save to Phone book",
                            "Dialed call list options Save entry string");
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DIALED_CALL_MENU_INFO,
                              MENU_MTPNP_DIALED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_VIEW, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DIALED_CALL_MENU_CALL,
                              MENU_MTPNP_DIALED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_DIAL, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DIALED_CALL_MENU_SAVE,
                              MENU_MTPNP_DIALED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_DIALED_SAVE_MENUENTRY, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DIALED_CALL_MENU_DELETE,
                              MENU_MTPNP_DIALED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_DELETE, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DIALED_CALL_MENU_EDIT,
                              MENU_MTPNP_DIALED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_EDIT, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DIALED_CALL_MENU_SENDSMS,
                              MENU_MTPNP_DIALED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CHIST_OPTION_SENDSMS, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_DIALED_CALL_MENU_SENDMMS,
                              MENU_MTPNP_DIALED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CHIST_OPTION_SENDMMS, NULL));

        /******************** Missed call list ****************/

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_LIST_OPTIONS, 0, 7,
                              MENU_MTPNP_MISSED_CALL_MENU_INFO,
                              MENU_MTPNP_MISSED_CALL_MENU_DELETE,
                              MENU_MTPNP_MISSED_CALL_MENU_SAVE,
                              MENU_MTPNP_MISSED_CALL_MENU_CALL,
                              MENU_MTPNP_MISSED_CALL_MENU_EDIT,
                              MENU_MTPNP_MISSED_CALL_MENU_SENDSMS,
                              MENU_MTPNP_MISSED_CALL_MENU_SENDMMS,
                              SHOW, INSERTABLE, DISP_LIST,
                              STRING_MTPNP_MISSED_CALL_LIST_OPTIONS, IMG_MTPNP_CARD2_MENU_MISSED_CALLS));

    ADD_APPLICATION_STRING2(STRING_MTPNP_MISSED_CALL_LIST_OPTIONS, "Missed Call Info Option",
                            "Missed call list options title string");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MISSED_SAVE_MENUENTRY, "Save to Phone book",
                            "Missed call list options Save entry string");
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_MENU_INFO,
                              MENU_MTPNP_MISSED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_VIEW, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_MENU_CALL,
                              MENU_MTPNP_MISSED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_DIAL, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_MENU_SAVE,
                              MENU_MTPNP_MISSED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_MISSED_SAVE_MENUENTRY, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_MENU_DELETE,
                              MENU_MTPNP_MISSED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_DELETE, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_MENU_EDIT,
                              MENU_MTPNP_MISSED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_EDIT, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_MENU_SENDSMS,
                              MENU_MTPNP_MISSED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CHIST_OPTION_SENDSMS, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_MENU_SENDMMS,
                              MENU_MTPNP_MISSED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_CHIST_OPTION_SENDMMS, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SIM1_RECEIVED_NUM_CALL,
                              RECEIVED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_SIM2DIAL, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SIM1_DIALED_NUM_CALL,
                              DIALED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_SIM2DIAL, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_SIM1_MISSED_NUM_CALL,
                              MISSED_CALL_LIST_OPTIONS, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_SIM2DIAL, NULL));

    /*      Recd Call list */
    ADD_APPLICATION_STRING2(STR_RECEIVED_CAPTION, "Received Calls", "Recd. call list caption string");
    ADD_APPLICATION_IMAGE2(IMG_RECEIVED_CAPTION, CUST_IMG_PATH "\\\\MainLCD\\\\TitleBar\\\\TB_CA.PBM",
                           "Recd. call list caption image");
    /*      Missed Call list */
    ADD_APPLICATION_STRING2(STR_MISSED_CAPTION, "Missed Calls", "Missed call list caption string");
    ADD_APPLICATION_IMAGE2(IMG_MISSED_CAPTION, CUST_IMG_PATH "\\\\MainLCD\\\\TitleBar\\\\TB_CA.PBM",
                           "Missed call list caption  image");
    /*      Dialed Call list */
    ADD_APPLICATION_STRING2(STR_DIALED_CAPTION, "Dialed Calls", "Dialed call list caption string");
    ADD_APPLICATION_IMAGE2(IMG_DIALED_CAPTION, CUST_IMG_PATH "\\\\MainLCD\\\\TitleBar\\\\TB_CA.PBM",
                           "Dialed call list caption image");

    /* Delete Call Logs */
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD1_MENU_DELETE_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD1\\\\DELETE_CALL_1.bmp",
                           "Delete Call Logs");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD2_MENU_DELETE_CALLS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\DELETE_CALL_2.bmp",
                           "Delete Call Logs");

}

void Mercury_CHCallTimes(void)
{
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_CALLTIME, MENU_MTPNP_CALL_HISTORY, 4,
                              MENU_MTPNP_LAST_CALL_TIME,
                              MENU_MTPNP_CALL_OUT_TIME,
                              MENU_MTPNP_CALL_IN_TIME,
                              MENU_MTPNP_ALL_CALL_TIME,
                              SHOW,
                              MOVEABLEACROSSPARENT | INSERTABLE | SHORTCUTABLE, DISP_LIST,
                              STRING_MTPNP_MENU_SIM2_CALL_TIME_SETUP, IMG_MTPNP_CARD2_CALL_TIMES_MAIN_MENU));
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_LAST_CALL_TIME, MENU_MTPNP_CALL_HISTORY_CALLTIME, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_MENU_LAST_CALL_TIME, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_OUT_TIME, MENU_MTPNP_CALL_HISTORY_CALLTIME, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_MENU_CALL_OUT_TIME, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_IN_TIME, MENU_MTPNP_CALL_HISTORY_CALLTIME, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_MENU_CALL_IN_TIME, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_ALL_CALL_TIME, MENU_MTPNP_CALL_HISTORY_CALLTIME, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_MENU_ALL_CALL_TIME, NULL));

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_SIM1_CALL_TIME_SETUP, "SIM1 call time", "String for Missed Calls option");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_SIM2_CALL_TIME_SETUP, "Call Time", "CALL TIME SET MAIN ");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_QUICK_END, "Auto quick end", "QUICK END SET MAIN ");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_QUICK_END_SET, "Set", "QUICK END SET ON OFF");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_QUICK_END_DURATION, "Duration (1~9999 sec.)", "QUICK END SET DURATION ");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_LAST_CALL_TIME, "Last Call Time", "LAST CALL TIME STRING");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALL_OUT_TIME, "Total Sent", "CALL OUT TIME  STRING");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALL_IN_TIME, "Total Received", "CALL IN TIME STRING");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_ALL_CALL_TIME, "Reset All Time", "ALL CALL TIMES STRING ");

    ADD_APPLICATION_STRING2(STRING_MTPNP_RESET_ALL_CALL_TIME, "Deleted", "ALL CALL TIMES RESETED ");
    ADD_APPLICATION_STRING2(STRING_MTPNP_RESET_ALL_CALL_TIME_CONFIRM, "Delete", "ALL CALL TIMES RESET STRING? ");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MENU_CALL_TIMES,
                           CUST_IMG_PATH "\\\\MainLCD\\\\TitleBar\\\\TB_CA.PBM", "CALL TIMES IMG  ");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD2_CALL_TIMES_MAIN_MENU,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\CALL_TIME_2.bmp",
                           "RESET CALLS CONFIRM SCR  RSK IMG ");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD1_CALL_TIMES_MAIN_MENU,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD1\\\\CALL_TIME_1.bmp",
                           "RESET CALLS CONFIRM SCR  RSK IMG ");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_QUICK_END_MAIN_MENU,
                           CUST_IMG_PATH "\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CEND.PBM", "AUTO QUICK END IMG ");
}

void Mercury_CHCallCost(void)
{
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_CALLCOST, MENU_MTPNP_CALL_HISTORY, 5,
                              MENU_MTPNP_CALL_COST_LASTCALL,
                              MENU_MTPNP_CALL_COST_ALLCOST,
                              MENU_MTPNP_CALL_COST_RESETCOUNTER,
                              MENU_MTPNP_CALL_COST_MAXCOUNT,
                              MENU_MTPNP_CALL_COST_PRICEUNIT, 0,
                              MOVEABLEACROSSPARENT | INSERTABLE | SHORTCUTABLE, 1,
                              STRING_MTPNP_MENU_SIM2_CALL_COST_MAIN, IMG_MTPNP_CARD2_CALL_COST_MAIN_MENU));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_COST_LASTCALL,
                              MENU_MTPNP_CALL_HISTORY_CALLCOST, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_MENU_CALL_COST_LASTCALL, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_COST_ALLCOST,
                              MENU_MTPNP_CALL_HISTORY_CALLCOST, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_MENU_CALL_COST_ALLCOST, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_COST_PRICEUNIT,
                              MENU_MTPNP_CALL_HISTORY_CALLCOST, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_MENU_CALL_COST_PRICEUNIT, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_COST_RESETCOUNTER,
                              MENU_MTPNP_CALL_HISTORY_CALLCOST, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_MENU_CALL_COST_RESETCOUNTER, NULL));

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_COST_MAXCOUNT,
                              MENU_MTPNP_CALL_HISTORY_CALLCOST, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_MENU_CALL_COST_MAXCOUNT, NULL));
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALL_COST_PROCESSING, "Processing", "Processing");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_SIM1_CALL_COST_MAIN, "SIM1 call cost", "SIM1 call cost");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_SIM2_CALL_COST_MAIN, "Call Cost", "CALL COST MAIN CAPTION ");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALL_COST_LASTCALL, "Last Call Cost", "LAST CALL COST ");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALL_COST_ALLCOST, "Total Cost", "ALL CALL COST ");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALL_COST_PRICEUNIT, "Price Per Unit", "PRICE AND UNIT");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALL_COST_RESETCOUNTER, "Reset Cost", "RESET COUNTER ");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALL_COST_MAXCOUNT, "Max Cost", "MAX COST");

    ADD_APPLICATION_STRING2(STRING_MTPNP_ALL_CALL_COSTS_ERROR_MSG, "Invalid Input", "ERROR MSG ALL COST ");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_SCR_CALL_COST_MAIN_CAP,
                           CUST_IMG_PATH "\\\\MainLCD\\\\TitleBar\\\\TB_CA.PBM", "CALL COST MAIN CAPTION IMG  ");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_SCR_CALL_COST_PROCESS,
                           CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Progress\\\\PROGRESS.gif",
                           "Processing Phonebook message icon");


    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD2_CALL_COST_MAIN_MENU,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\CALL_COST_2.bmp",
                           "RESET CALLS CONFIRM SCR  RSK IMG ");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD1_CALL_COST_MAIN_MENU,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD1\\\\CALL_COST_1.bmp",
                           "RESET CALLS CONFIRM SCR  RSK IMG ");

    ADD_APPLICATION_STRING2(STRING_MTPNP_CALL_COST_PRICEANDUNIT_VIEW_LSK, "Set", "STR_CALL_COST_PRICEANDUNIT_VIEW_LSK");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_SCR_CALL_COST_PRICEANDUNIT_SET, "Set",
                            "STR_MENU_SCR_CALL_COST_PRICEANDUNIT_SET");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALL_COST_PRICEANDUNIT_SET_PRICE, "Price",
                            "STR_MENU_CALL_COST_PRICEANDUNIT_SET_PRICE");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_CALL_COST_PRICEANDUNIT_SET_UNIT, "Unit",
                            "STR_MENU_CALL_COST_PRICEANDUNIT_SET_UNIT");

    ADD_APPLICATION_STRING2(STRING_MTPNP_MAX_COST_SET_CAPTION, "Set Max Cost ", "STR_MAX_COST_SET_CAPTION");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_SCR_CALL_COST_PRICEANDUNIT_SET_CAPTION,
                           CUST_IMG_PATH "\\\\MainLCD\\\\TitleBar\\\\TB_CA.PBM",
                           "IMG_SCR_CALL_COST_PRICEANDUNIT_SET_CAPTION  ");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_SCR_MAX_COST_GET_CAPTION,
                           CUST_IMG_PATH "\\\\MainLCD\\\\TitleBar\\\\TB_CA.PBM", "IMG_SCR_MAX_COST_GET_CAPTION  ");

}

#ifndef __SENDKEY2_SUPPORT__
void Mercury_CHISTDualMixedCallLog(void)
{
    ADD_APPLICATION_MENUITEM((MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG,
                              0,
                              2,
                              MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG_MASTER,
                              MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG_SLAVE,
                              SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_MISSED_CALL_NOTIFY, IMG_ID_UCM_CALL_HISTORY));
    ADD_APPLICATION_MENUITEM((MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG_MASTER,
                              MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG,
                              0,
                              SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_CARD1_CALL_HISTORY, IMG_MTPNP_MISSED_CALL_NOTIFY_MASTER));
    ADD_APPLICATION_MENUITEM((MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG_SLAVE,
                              MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG,
                              0,
                              SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_CALL_HISTORY, IMG_MTPNP_MISSED_CALL_NOTIFY_SLAVE));

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MISSED_CALL_NOTIFY,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\notify1.bmp",
                           "total missed call nunbers notify");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MISSED_CALL_NOTIFY_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\notify1.bmp",
                           "master missed call nunbers notify");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MISSED_CALL_NOTIFY_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\notify2.bmp",
                           "slave missed call nunbers notify");
}
#endif /* __SENDKEY2_SUPPORT__ */

void Mercury_CHMissNotify(void)
{
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_NOTIFY,
                              0,
                              2,
                              MENU_MTPNP_MISSED_CALL_NOTIFY_MASTER,
                              MENU_MTPNP_MISSED_CALL_NOTIFY_SLAVE,
                              SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_MISSED_CALL_NOTIFY, IMG_MTPNP_MISSED_CALL_NOTIFY));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_NOTIFY_MASTER,
                              MENU_MTPNP_MISSED_CALL_NOTIFY,
                              0,
                              SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_MISSED_CALL_NOTIFY_MASTER, IMG_MTPNP_MISSED_CALL_NOTIFY_MASTER));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_MISSED_CALL_NOTIFY_SLAVE,
                              MENU_MTPNP_MISSED_CALL_NOTIFY,
                              0,
                              SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST,
                              STRING_MTPNP_MISSED_CALL_NOTIFY_SLAVE, IMG_MTPNP_MISSED_CALL_NOTIFY_SLAVE));

    ADD_APPLICATION_STRING2(STRING_MTPNP_MISSED_CALL_NOTIFY, "Missed Calls", "Missed Calls");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MISSED_CALL_NOTIFY_MASTER, "Missed Calls Master", "Missed Calls Master");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MISSED_CALL_NOTIFY_SLAVE, "Missed Calls Slave", "Missed Calls Slave");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MISSED_CALL_NOTIFY,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\notify1.bmp",
                           "total missed call nunbers notify");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MISSED_CALL_NOTIFY_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\notify1.bmp",
                           "master missed call nunbers notify");
    ADD_APPLICATION_IMAGE2(IMG_MTPNP_MISSED_CALL_NOTIFY_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\notify2.bmp",
                           "slave missed call nunbers notify");
}

#ifdef __MMI_GPRS_FEATURES__
void Mercury_CHGPRSCounterResPopulate(void)
{
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_SIM1_GPRS_CAPTION, "SIM1 gprs counter", "SIM1 gprs counter");
    ADD_APPLICATION_STRING2(STRING_MTPNP_MENU_SIM2_GPRS_CAPTION, "GPRS Counter", "GPRS COUNTER SCR CAPTION");
    ADD_APPLICATION_STRING2(STRING_MTPNP_GPRS_LAST_SENT, "Last Sent", "GPRS COUNTER LAST SENT");
    ADD_APPLICATION_STRING2(STRING_MTPNP_GPRS_LAST_RECEIVED, "Last Received", "GPRS COUNTER LAST RECEIVED");
    ADD_APPLICATION_STRING2(STRING_MTPNP_GPRS_ALL_SENT, "All Sent", "GPRS COUNTER ALL SENT");
    ADD_APPLICATION_STRING2(STRING_MTPNP_GPRS_ALL_RECEIVED, "All Received", "GPRS COUNTER ALL RECEIVED");
    ADD_APPLICATION_STRING2(STRING_MTPNP_GPRS_RESET_COUNTER, "Reset Counter", "GPRS COUNTER RESET COUNTER");

    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER,
                              MENU_MTPNP_CALL_HISTORY, 5,
                              MENU_MTPNP_CALL_HISTORY_GPRS_LASTSENT,
                              MENU_MTPNP_CALL_HISTORY_GPRS_LASTRECEIVED,
                              MENU_MTPNP_CALL_HISTORY_GPRS_ALLSENT,
                              MENU_MTPNP_CALL_HISTORY_GPRS_ALLRECEIVED,
                              MENU_MTPNP_CALL_HISTORY_GPRS_RESETCOUNTER,
                              SHOW, MOVEABLEACROSSPARENT | INSERTABLE | SHORTCUTABLE,
                              DISP_LIST, STRING_MTPNP_MENU_SIM2_GPRS_CAPTION, IMG_MTPNP_CARD2_GPRS_COUNTER_MENU));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_GPRS_LASTSENT,
                              MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_GPRS_LAST_SENT, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_GPRS_LASTRECEIVED,
                              MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_GPRS_LAST_RECEIVED, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_GPRS_ALLSENT,
                              MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_GPRS_ALL_SENT, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_GPRS_ALLRECEIVED,
                              MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_GPRS_ALL_RECEIVED, NULL));
    ADD_APPLICATION_MENUITEM((MENU_MTPNP_CALL_HISTORY_GPRS_RESETCOUNTER,
                              MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER, 0, SHOW,
                              MOVEABLEWITHINPARENT, DISP_LIST, STRING_MTPNP_GPRS_RESET_COUNTER, NULL));

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD1_GPRS_COUNTER_MENU,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD1\\\\GPRS_COUNT_1.bmp", "GPRS counter");

    ADD_APPLICATION_IMAGE2(IMG_MTPNP_CARD2_GPRS_COUNTER_MENU,
                           CUST_IMG_PATH "\\\\MainLCD\\\\DualSIM\\\\CHIS\\\\CARD2\\\\GPRS_COUNT_2.bmp", "GPRS counter");

}
#endif

#endif
#endif /* __MMI_DUAL_SIM_MASTER__ */
