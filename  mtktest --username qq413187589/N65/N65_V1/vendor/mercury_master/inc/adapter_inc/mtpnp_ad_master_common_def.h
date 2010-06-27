/***********************************************
File name : MTPNP_AD_common_def.h
Contents : MTPNP AD main define
History : Create by : Zhang Nan, Feb 26, 2007
************************************************/
#ifndef __MTPNP_AD_MASTER_COMMON_DEFINE_H__
#define __MTPNP_AD_MASTER_COMMON_DEFINE_H__

#include "MTPNP_PFAL_master_Def.h"
#include "MTPNP_AD_common_def.h"
#include "csmcc_common_enums.h" /*for calltype enum*/

#ifdef __cplusplus
extern "C"
{
#endif

#define RCV_GAIN			100
#define SLAVE_NETWORK_ID_LEN 6

#define MTPNP_MAX_IP_NUMBER_LEN   10

#define MTPNP_AD_SMS_INVALID_INDEX	0xffff
#define MTPNP_AD_CALLSTATUS_SPLIT  0x01
#define MTPNP_AD_CALLSTATUS_NONE  0x00

#define MTPNP_AD_MAX_CALLS   7
#define MTPNP_AD_INVALID_CALL_HANDLE   0xFF
#define MTPNP_AD_CC_HANDLE_2ND_INCOMING 0xE0    /* the low half byte is the call id to splict */

#define MTPNP_AD_SPEECH_MODE_NORMAL   1 //normal mode
#define MTPNP_AD_SPEECH_MODE_HEADSET   2        // eatphone mode
#define MTPNP_AD_SPEECH_MODE_HANDFREE   3       //loudspeaker mode
#define MTPNP_AD_SPEECH_MODE_BT_NORMAL   4      //Normal Bt Speech
#define MTPNP_AD_SPEECH_MODE_BT_RESUME   5      //resume Bt Speech
#define MTPNP_AD_SPEECH_MODE_STOP   6      //stop dsp for speech
#define MTPNP_PFAL_MAX_CALLHISTORY_ENTRY  MAX_PHB_LN_ENTRY

#define MTPNP_AD_PB_SIM_MAXNAMELEN	14      //MTK UI SUPPORT
#define MTPNP_AD_PB_SIM_MAXNUMLEN	40      //MTK UI SUPPORT

#define IMEI_BCD_LENGTH	8

#define MTPNP_AD_MAX_STATUS_REPORT_NUM 10

#define MTPNP_AD_MAX_OWNER_DISPLAY_LEN	21

typedef void (*MTPNP_EVENTHANDLER_FuncPtr) (void *);
typedef void (*MTPNP_CDT_FuncPtr) (void *, MTPNP_UINT32);
typedef void (*MTPNP_VEINT_FuncPtr) (MTPNP_UINT8);

/* custom config option */
typedef enum
{
    MTPNP_CTRL_SLAVE_RF = 0,
    MTPNP_CTRL_SLAVE_PWR,
    MTPNP_CTRL_SLAVE_PWRKEY
} E_MTPNP_CTRL_SLAVE_MODE;

typedef enum
{
    MTPNP_PMU_MASTER,
    MTPNP_PMU_SLAVE,

    MTPNP_DUAL_PMU
} E_PMU_CTRL_TYPE;

typedef enum
{
    MTPNP_DM_NORMAL = 0,
    MTPNP_DM_SINGLECALL
} E_MTPNP_DUALMODE_OPTION;
/* custom config option */

/* call management */
typedef enum
{
    MTPNP_CM_CALL_OPER_NULL = 1,        /* current operation isn't cause by user */
    MTPNP_CM_CALL_OPER_USER,    /* current operation is cause by user */
    MTPNP_CM_CALL_OPER_NETWORK, /* current operation is cause by network */
    MTPNP_CM_CALL_OPER_CFT_REJ, /* Master and Slave call conflict */
    MTPNP_CM_CALL_OPER_INCOMING_BLOCK   /* Slave MT Call Block by black list */
} E_MTPNP_AD_CALL_OPERATION;

typedef enum
{
    MTPNP_CM_IDLE_STATE = 0,
    MTPNP_CM_OUTGOING_STATE,    /* Outgoing Call */
    MTPNP_CM_INCOMING_STATE,    /* Incoming Call */
    MTPNP_CM_ACTIVE_STATE,      /* active Call */
    MTPNP_CM_HOLD_STATE,        /* hold Call */
    MTPNP_CM_STATE_UNKNOWN
} E_MTPNP_AD_CALL_STATE;

typedef enum
{
    MTPNP_CM_CALL_MO = 1,
    MTPNP_CM_CALL_MT
} E_MTPNP_AD_CALL_DIR;

typedef enum
{
    MTPNP_AD_CC_CALLTYPE_UNKNOWN = 0,
    MTPNP_AD_CC_CALLTYPE_VOICE, /* Outgoing Call */
    MTPNP_AD_CC_CALLTYPE_SS     /* Incoming Call */
} E_MTPNP_AD_CM_CALL_TYPE;

typedef enum
{
    MTPNP_CM_INCOMING_ALTER = 1,        //Alter normal, No conflict
    MTPNP_CM_INCOMING_ALTER_CFT_REJ,    //donot alter user the incoming call ,Rej the incoming call by ps,for cc conflict
    MTPNP_CM_INCOMING_ALTER_CFT_NOTIFY, //Alter user the incoming call with conflict,one is in active, then there is an incoming
    MTPNP_CM_INCOMING_ALTER_CFT_NOTIFY2,        //Alter user the incoming call with conflict,one is outgoing, then there is an incoming
    MTPNP_CM_INCOMING_REMOTE_CANCEL,    //remoter user cancel the incoming call
    MTPNP_CM_INCOMING_CFT_REJ,  //incoming call was rejected by ps for conflict, for PS release
    MTPNP_CM_INCOMING_LOCAL_USER_REJ,   //Local user reject the incoming call
    MTPNP_CM_INCOMING_LOCAL_USER_ACCEPT,        //Local user accept the incoming call
    MTPNP_CM_INCOMING_BLACK_BLOCK,      //incoming call was rejected by ps for conflict, for PS release
    MTPNP_CM_INCOMING_ALTER_BLACK_REJ,
    MTPNP_CM_OUTGOING_ALTER,    //Local user accept the incoming call
    MTPNP_CM_OUTGOING_FAILD,    //Outgoing call
    MTPNP_CM_OUTGOING_REMOTE_USER_ACCEPT,       //Local user accept the incoming call
    MTPNP_CM_OUTGOING_LOCAL_USER_CANCEL,        //Local user accept the incoming call
    MTPNP_CM_OUTGOING_CFT_CANCEL,       //Slave is outgoing, Master incoming ,Slave cancel outgoing
    MTPNP_CM_OUTGOING_REMOTE_REJECT,    //Slave is outgoing, Remote reject 
    MTPNP_CM_OUTGOING_NET_FAILD,
    MTPNP_CM_OUTGOING_PROCEEDING,
    MTPNP_CM_OUTGOING_SS_PARSING_SUCCESS,
    MTPNP_CM_ACTIVE_LOCAL_DISC,
    MTPNP_CM_HOLD_LOCAL_DISC,
    MTPNP_CM_ACTIVE_REMOTER_DISC,
    MTPNP_CM_HOLD_REMOTER_DISC,
    MTPNP_CM_SS_OPERATION_REQ_FAILED
} E_MTPNP_AD_CM_EVENT;

typedef enum
{
    MTPNP_AD_DIALBACK_TYPE_NONE = 0,
    MTPNP_AD_DIALBACK_TYPE_SLAVE,
    MTPNP_AD_DIALBACK_TYPE_SLAVE_IP,
    MTPNP_AD_DIALBACK_TYPE_MASTER,
    MTPNP_AD_DIALBACK_TYPE_MASTER_IP
} E_MTPNP_AD_DIALBACK_TYPE;

typedef enum
{
    MTPNP_AD_CALL_ALTER_CFT_SHOW = 1,   //to show incomg call screen and play alter tone
    MTPNP_AD_CALL_ALTER_CFT_REJECT_BLACK,       //Reject the call for black list
    MTPNP_AD_CALL_ALTER_CFT_REJECT_CFT, //Reject this incoming call
    MTPNP_AD_CALL_ALTER_CFT_NOTIFY      //Exist another Outgoing if need to cancel the outgoing call
} E_MTPNP_AD_CALL_ALTER;

typedef enum
{
    MTPNP_AD_CALL_CONFLICT_NONE = 0,
    MTPNP_AD_CALL_CONFLICT_ACCEPT_MASTER,       //call conflict, only Master Incoming,  release all and accept master
    MTPNP_AD_CALL_CONFLICT_ACCEPT_SLAVE,        //call conflict, only Slave Incoming,  release all and slave master
    MTPNP_AD_CALL_CONFLICT_ACCEPT_BOTH, //
    MTPNP_AD_CALL_CONFLICT_SHOW_SLAVEINCOMING,  //call conflict, only Master Outgoing, Slave incoming ,cancle  master  show slave
    MTPNP_AD_CALL_CONFLICT_SHOW_MASTERINCOMING  //call conflict, only slave Outgoing, master incoming ,cancle  slave  show master
} E_MTPNP_AD_CALL_CONFLICT_OPERATE;

/* call management */

typedef enum
{
    MTPNP_AD_STARTUP_NORMAL = 0,
    MTPNP_AD_STARTUP_EXCEPTION
} E_MTPNP_AD_STARTUP_MODE;

typedef enum
{
    MTPNP_AD_SHUTDOWN_NORMAL = 0,
    MTPNP_AD_SHUTDOWN_QUICK
} E_MTPNP_AD_SHUTDOWN_MODE;

typedef enum
{
    MTPNP_DLL_WORK = 0,
    MTPNP_DLL_ERROR
} E_MTPNP_AD_DLL_STATUS;

/*
* the enum of dual mode channel
*/
typedef enum
{
    MTPNP_AD_CHANNEL_MASTER = 0x01,
    MTPNP_AD_CHANNEL_SLAVE = 0x02,
    MTPNP_AD_CHANNEL_DEFAULT_MASTER = 0x04,
    MTPNP_AD_CHANNEL_DEFAULT_SLAVE = 0x08,

    MTPNP_AD_CHANNEL_NONE = 0xffff
} E_MTPNP_AD_CHANNELS;

typedef enum
{
    MTPNP_AD_CALL_CHANNEL = 0x01,
    MTPNP_AD_SMS_CHANNEL = 0x02,

    MTPNP_AD_DATA_SERVICE_CHANNEL = 0x04,
    MTPNP_AD_AUDIO_RECORD = 0x08,

    MTPNP_AD_CHANNEL_TOTAL
} E_MTPNP_AD_CHANNELS_OWNER;

typedef enum
{
    MTPNP_AD_CODING_SCHEME_DEFAULT,
    MTPNP_AD_CODING_SCHEME_BCD,
    MTPNP_AD_CODING_SCHEME_ASCII,
    MTPNP_AD_CODING_SCHEME_UCS2,
    MTPNP_AD_CODING_SCHEME_GB2312,
    MTPNP_AD_CODING_SCHEME_BIG5,
    MTPNP_AD_CODING_SCHEME_STREAM,
    MTPNP_AD_CODING_SCHEME_UNKNOWN
} E_MTPNP_AD_CODING_SCHEME;

typedef enum
{
    MTPNP_AD_FLIGHT = 0x00,     /* xxxx xxxx */
    MTPNP_AD_CARD1 = 0x01,      /* xxxx xxx1 */
    MTPNP_AD_CARD2 = 0x02,      /* xxxx xx1x */
    MTPNP_AD_DUALCARD = 0x03,   /* xxxx xx11 */

    MTPNP_AD_MAX = 0xff
} E_MTPNP_AD_STATUS;

typedef enum
{
    MTPNP_AD_DIRECT_SWITCH = 0,
    MTPNP_AD_SWITCH_SUCCEED = 1,
    MTPNP_AD_SWITCH_FAILED = 2
} E_MTPNP_AD_MODE_SWITCH_STATE;

typedef enum
{
    MTPNP_AD_NO_SERVICE = 0,
    MTPNP_AD_LIMITED_SERVICE,
    MTPNP_AD_FULL_SERVICE
} E_MTPNP_AD_SERVICE_TYPE;

typedef enum
{
    MTPNP_AD_NW_STATUS_REGISTER_FAILED = 0,
    MTPNP_AD_NW_STATUS_NETWORK_FLAG,
    MTPNP_AD_NW_STATUS_FLIGHT_MODE,
    MTPNP_AD_NW_STATUS_PLMNSEL_MODE
} E_MTPNP_AD_NW_STATUS;

typedef enum
{
    MTPNP_AD_RF_DURING_POWEROFF = 0,
    MTPNP_AD_RF_POWEROFF,
    MTPNP_AD_RF_DURING_POWERON,
    MTPNP_AD_RF_POWERON
} E_MTPNP_AD_RF_STATUS;

typedef enum
{
    MTPNP_AD_SIMCARD_INVALID = 0x01,    /* xxxx xxxx xxxx xxx1 */
    MTPNP_AD_SIMCARD_ABSENT = 0x02,
    MTPNP_AD_SIMCARD_CHV1_REQUESTED = 0x04,
    MTPNP_AD_SIMCARD_CHVBLOCKED = 0x08,

    MTPNP_AD_SIMCARD_VALID = 0x10,

    MTPNP_AD_SIMCARD_PIN_CANCELED = 0x20,
    MTPNP_AD_SIMCARD_PUK_CANCELED = 0x40
} E_MTPNP_AD_SIMCARD_STATUS;

typedef enum
{
    MTPNP_AD_DUALSIM_UNUSABLE = MTPNP_AD_FLIGHT,
    MTPNP_AD_SIMCARD1_NOSIM_USABLE = MTPNP_AD_CARD1,
    MTPNP_AD_SIMCARD2_NOSIM_USABLE = MTPNP_AD_CARD2,
    MTPNP_AD_SIMCARD1_USABLE = MTPNP_AD_CARD1 | MTPNP_AD_SIMCARD_VALID,
    MTPNP_AD_SIMCARD2_USABLE = MTPNP_AD_CARD2 | MTPNP_AD_SIMCARD_VALID,
    MTPNP_AD_DUALSIM_USABLE = (MTPNP_AD_CARD1 | MTPNP_AD_SIMCARD_VALID) + (MTPNP_AD_CARD2 | MTPNP_AD_SIMCARD_VALID)
} E_MTPNP_AD_SIMCARD_USABLE_SIDE;

typedef enum
{
    MTPNP_AD_ATTACH_NONE = 0,
    MTPNP_AD_HOME,
    MTPNP_AD_ROAM
} E_MTPNP_NET_ATTACH_TYPE;

typedef enum
{
    MTPNP_SMSCOUNT_SENT = 0,
    MTPNP_SMSCOUNT_RECV,

    MTPNP_SMSCOUNT_TOTAL
} E_MTPNP_SMSCOUNT_TYPE;

typedef enum
{
    MTPNP_AUDIO_MASTER = 0,
    MTPNP_AUDIO_SLAVE
} E_MTPNP_AUDIO_CHANEL_TYPE;


/*
* card2 owner display option
*/
typedef enum
{
    MTPNP_AD_MSISDN_DISPLAY_DEFAULT = 0,        /* default display will display name first, if name is null, display number */
    MTPNP_AD_MSISDN_DISPLAY_NAME,
    MTPNP_AD_MSISDN_DISPLAY_NUMBER
} E_MTPNP_AD_MSISDN_DISPLAY_OPTION;

typedef enum
{
    MTPNP_AD_DIALED = 1,
    MTPNP_AD_MISSED,
    MTPNP_AD_RECVED,

    MTPNP_AD_BLOCKED
} E_MTPNP_AD_CALLLOG_OPTION;

typedef enum
{
    MTPNP_AD_MASTER_CALL,
    MTPNP_AD_SLAVE_CALL
} E_MTPNP_AD_CALL_TYPE;

/* mercury resource define */
typedef struct
{
    /* phone control */
    MTPNP_UINT8 nvram_start_mode_id;
    MTPNP_UINT8 nvram_last_dm_status_id;
    /* phone control */

    /* phone setup */
    MTPNP_UINT8 nvram_owner_number_id;
    /* phone setup */

    /* call history */
    MTPNP_UINT8 nvram_sms_recv_count_id;
    MTPNP_UINT8 nvram_sms_sent_count_id;
    /* call history */
} ST_MTPNP_AD_NVRAM_ID;
/* mercury resource define */

typedef struct
{
    E_MTPNP_AD_STATUS MTPNP_AD_Status;
    MTPNP_BOOL MTPNP_AD_SIMCard2_Need_PINVerified;
    MTPNP_BOOL MTPNP_AD_PUK_History_Saved;
    MTPNP_BOOL MTPNP_Slave_Plugged;
    MTPNP_BOOL MTPNP_SDK_Start_Finished;
    E_MTPNP_AD_DLL_STATUS MTPNP_DLL_Status;
    E_MTPNP_AD_POWERON_MODE MTPNP_PowerOn_Mode;
} ST_MTPNP_AD_STATUS;

typedef struct
{
    MTPNP_UINT16 MTPNP_AD_HW_Version;
    MTPNP_UINT16 MTPNP_AD_HW_Code;
    MTPNP_UINT16 MTPNP_AD_FW_Version;
} ST_MTPNP_CHIP_INFO;

typedef struct
{
    MTPNP_INT8 index;
    MTPNP_BOOL hide;
} ST_MTPNP_AD_MODE_SWITCH;

typedef struct
{
    MTPNP_UCHAR imei[IMEI_BCD_LENGTH];  /* BCD encode */
    MTPNP_UINT8 imei_len;
} ST_MTPNP_AD_IMEI;

typedef struct
{
    ST_MTPNP_AD_IMEI master_imei;
    ST_MTPNP_AD_IMEI slave_imei;
} ST_MTPNP_AD_IMEI_INFO;

typedef struct
{
    MTPNP_INT32 master_sdk_revision;
    MTPNP_INT32 slave_sdk_revision;
    MTPNP_UINT16 master_adapter_revision;
    MTPNP_UINT16 slave_adapter_revision;
    MTPNP_CHAR ext_version[10];
    MTPNP_CHAR register_value[50];
} ST_MTPNP_AD_VERSION;

typedef struct
{
    ST_MTPNP_AD_CALL_NUMBER call_number;
    ST_MTPNP_AD_CALL_NAME call_name;
    E_MTPNP_AD_CALL_STATE prev_state;
    E_MTPNP_AD_CALL_STATE curr_state;
    E_MTPNP_AD_CALL_DIR orgination_flag;
    ST_MTPNP_AD_TIME start_time;
    ST_MTPNP_AD_TIME end_time;
    MTPNP_UINT8 status_flag;
    E_MTPNP_AD_CALL_OPERATION call_operater;
    MTPNP_UINT8 call_handle;
    csmcc_call_type_enum call_type;
    ST_MTPNP_L4C_NUMBER_STRUCT l4c_number;    /*for L4C information*/
#ifdef __SAT__
    MTPNP_BOOL stk_call;
#endif /* __SAT__ */
} ST_MTPNP_AD_SLAVE_CALL_INFO;

typedef struct
{
    MTPNP_CHAR name[MTPNP_AD_MAX_NAME_LEN];
    MTPNP_CHAR number[MTPNP_AD_MAX_CC_ADDR_LEN * 2];
} ST_MTPNP_OWNER_NUMBER_RECORD;

typedef struct
{
    E_MTPNP_NET_ATTACH_TYPE card2_net_attach_type;
    E_MTPNP_AD_LINE_TPYE card1_line_id;
    E_MTPNP_AD_LINE_TPYE card2_line_id;
    E_MTPNP_AD_RF_STATUS card1_rf_status;
    E_MTPNP_AD_RF_STATUS card2_rf_status;
    E_MTPNP_AD_SERVICE_TYPE card1_current_servicetype;
    E_MTPNP_AD_SERVICE_TYPE card2_current_servicetype;
    E_MTPNP_AD_NW_STATUS card1_network_status;
    E_MTPNP_AD_NW_STATUS card2_network_status;
    MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN];
} ST_MTPNP_NET_ATTACH_STATUS;

typedef struct
{
    E_MTPNP_SIM_STATUS SIM_status;
    MTPNP_BOOL SIM_PIN_blocked;
    MTPNP_BOOL is_PIN1_verified;
    MTPNP_BOOL is_PIN2_verified;
    MTPNP_UINT8 SIM_CHV1_count;
    MTPNP_UINT8 SIM_CHV2_count;
    MTPNP_UINT8 SIM_CHV1_unblock_count;
    MTPNP_UINT8 SIM_CHV2_unblock_count;
    MTPNP_AD_FuncPtr callback_checkpwdlength;
    MTPNP_AD_FuncPtr VerifyPassSuccessCallBack;
    MTPNP_UINT8 CurrentPassword;
} ST_MTPNP_GSM_SIM_SECURITY_CONTEXT;

typedef struct
{
    E_MTPNP_AD_SIMCARD_STATUS MTPNP_AD_SIMCard1_Status;
    E_MTPNP_AD_SIMCARD_STATUS MTPNP_AD_SIMCard2_Status;
} ST_MTPNP_SIMCARD_STATUS;

typedef struct
{
    MTPNP_BOOL card2_recv_sms;
    MTPNP_UINT8 msgs_report_deliver_ind;
    MTPNP_BOOL card2_status_report[MTPNP_AD_MAX_STATUS_REPORT_NUM];
} ST_MTPNP_SMS_RECV_STATUS;

typedef struct
{
    MTPNP_BOOL Card2_Send_SMS;
} ST_MTPNP_SMS_SEND_STATUS;

typedef struct
{
    MTPNP_BOOL Card2_sms_load_finished;
    MTPNP_BOOL Card2_sms_ready;
    MTPNP_BOOL Card2_sms_storage_avail;
    MTPNP_BOOL Card2_sms_storage_exceed;
} ST_MTPNP_SMS_STATUS;

#ifdef __cplusplus
}
#endif

#endif /* __MTPNP_AD_MASTER_COMMON_DEFINE_H__ */
