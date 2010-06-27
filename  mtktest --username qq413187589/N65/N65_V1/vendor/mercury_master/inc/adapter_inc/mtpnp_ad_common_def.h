#ifndef __MTPNP_AD_COMMON_DEF_H__
#define __MTPNP_AD_COMMON_DEF_H__

#include "MTPNP_SDK_common_if.h"
#include "MTPNP_PFAL_COMMON_Def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define MTPNP_AD_MAX_CC_ADDR_LEN 	41
#define MTPNP_AD_MAX_NAME_LEN	62
#define MTPNP_AD_MAX_MSG_LEN 		160

#define MTPNP_AD_MAX_PLMN_LEN 6
#define MTPNP_AD_MAX_SUPPORT_EF_PLMNSEL_REC 150
#define MTPNP_AD_MAX_PLMN_LIST_LEN 16

#define MTPNP_AD_MAX_NW_NAME_LEN 24

typedef enum
{
    MTPNP_AD_PHB_BCD = 0x01,
    MTPNP_AD_PHB_ASCII = 0x00,
    MTPNP_AD_PHB_UCS2 = 0x08,
    MTPNP_AD_PHB_UCS2_81 = 0x09,
    MTPNP_AD_PHB_UCS2_82 = 0x10
} E_MTPNP_AD_PHB_CHARSET;

typedef enum
{
    MTPNP_AD_LND = 0,
    MTPNP_AD_LNR,
    MTPNP_AD_LNM,

    MTPNP_AD_LNB,   /* black list, log blocked */

    MTPNP_AD_LOGTYPE_MAX
} E_MTPNP_AD_CALLLOG_TYPE;

/*
* virtual eint enum define
*/
typedef enum
{
    MTPNP_PFAL_VEINT_0,
    MTPNP_PFAL_VEINT_1,
    MTPNP_PFAL_VEINT_2,
    MTPNP_PFAL_VEINT_3,
    MTPNP_PFAL_VEINT_4,
    MTPNP_PFAL_VEINT_5,
    MTPNP_PFAL_VEINT_6,
    MTPNP_PFAL_VEINT_7,

    MTPNP_PFAL_VEINT_MAX
} E_MTPNP_PFAL_EINT_NO;

typedef enum
{
    MTPNP_AD_POWERON_KEYPAD = 0,
    MTPNP_AD_POWERON_ALARM,
    MTPNP_AD_POWERON_CHARGER_IN,
    MTPNP_AD_POWERON_EXCEPTION,
    MTPNP_AD_POWERON_USB,
    MTPNP_AD_POWERON_UNINIT,
    MTPNP_AD_POWERON_PRECHARGE,

    MTPNP_AD_POWERON_MAX
} E_MTPNP_AD_POWERON_MODE;

typedef enum
{
    MTPNP_AD_PLMN_MANUAL,
    MTPNP_AD_PLMN_AUTOMATIC
} E_MTPNP_AD_PLMN_MODE;

typedef enum
{
    MTPNP_AD_LINE_NONE = 0,
    MTPNP_AD_LINE_1,
    MTPNP_AD_LINE_2
} E_MTPNP_AD_LINE_TPYE;

typedef enum
{
    MTPNP_DDT_NOT_SUPPORT = 0,
    MTPNP_DDT_SEND_FAILED,
    MTPNP_DDT_SEND_SUCCEED
} E_MTPNP_DDT_STATUS;

typedef enum
{
    MTPNP_VEINT_NOT_SUPPORT = 0,
    MTPNP_VEINT_SEND_FAILED,
    MTPNP_VEINT_SEND_SUCCEED
} E_MTPNP_VEINT_STATUS;

typedef enum
{
    MTPNP_AD_DEFAULT_PID = 0x00,        /* Text SMS */
    MTPNP_AD_TELEX_PID = 0x21,  /* Telex */
    MTPNP_AD_G3_FAX_PID = 0x22, /* Group 3 telefax */
    MTPNP_AD_G4_FAX_PID = 0x23, /* Group 4 telefax */
    MTPNP_AD_VOICE_PID = 0x24,  /* Voice Telephone */
    MTPNP_AD_ERMES_PID = 0x25,  /* ERMES (European Radio Messaging System) */
    MTPNP_AD_PAGING_PID = 0x26, /* National Paging system */
    MTPNP_AD_X400_PID = 0x31,   /* Any public X.400-based message system */
    MTPNP_AD_EMAIL_PID = 0x32   /* E-mail SMS */
} E_MTPNP_AD_SMS_PID;

typedef enum
{
    /* follows intended for AT commands and MMI */
    MTPNP_AD_DEL_INDEXED_MSG = 0,       /* delete specified msg */
    MTPNP_AD_DEL_READ_MSG,      /* delete all read msg */
    MTPNP_AD_DEL_READ_SENT_MSG, /* delete all read/sent msg */
    MTPNP_AD_DEL_READ_MO_MSG,   /* delete all read/mobile-originated msg */
    MTPNP_AD_DEL_ALL_MSG,       /* delete all msg */

    /* follows intended only for MMI */
    MTPNP_AD_DEL_INBOX,
    MTPNP_AD_DEL_OUTBOX,
    MTPNP_AD_DEL_BITMAP         /* delete according bitmap */
} E_MTPNP_AD_SMS_DEL_FLAG;

typedef enum
{
    MTPNP_AD_CSMCC_DEFAULT_ADDR = 0x81,
    MTPNP_AD_CSMCC_INTERNATIONAL_ADDR = 0x91
} E_MTPNP_AD_CSMCC_ADDR_TYPE;

/* TP-Status(TP-ST) in Status Report */
typedef enum
{
    /* 
     * Short message transaction completed 
     */
    MTPNP_AD_ST_COMP_MSG_RECV_BY_SME = 0x00,    /* Short message received by the SME */
    MTPNP_AD_ST_COMP_MSG_FORWARD_NOT_CONF = 0x01,       /* Short message forwarded by the SC to the SME 
                                                           but the SC is unable to confirm deliver */
    MTPNP_AD_ST_COMP_MSG_REPLACE = 0x02,        /* Short message replaced by the SC */

    /* 
     * Temporary error, SC still trying to transfer SM 
     */
    MTPNP_AD_ST_TE1_CONGESTION = 0x20,  /* Congestion */
    MTPNP_AD_ST_TE1_SME_BUSY = 0x21,    /* SME busy */
    MTPNP_AD_ST_TE1_NO_RSP_FROM_SME = 0x22,     /* No response from SME */
    MTPNP_AD_ST_TE1_SERVICE_REJECT = 0x23,      /* Service rejected */
    MTPNP_AD_ST_TE1_QOS_NOT_AVAIL = 0x24,       /* Quality of service not available */
    MTPNP_AD_ST_TE1_ERROR_IN_SME = 0x25,        /* Error in SME */

    /* 
     * Permanent error, SC is not making any more transfer attempts 
     */
    MTPNP_AD_ST_PE_REMOTE_PROC_ERROR = 0x40,    /* Remote procedure error */
    MTPNP_AD_ST_PE_INCOMP_DEST = 0x41,  /* Incompatible destination */
    MTPNP_AD_ST_PE_CONN_REJ_BY_SME = 0x42,      /* Connection rejected by SME */
    MTPNP_AD_ST_PE_NOT_OBTAINABLE = 0x43,       /* Not obtainable */
    MTPNP_AD_ST_PE_QOS_NOT_AVAIL = 0x44,        /* Quality of service not available */
    MTPNP_AD_ST_PE_NO_INTERWK_AVAIL = 0x45,     /* No interworking available */
    MTPNP_AD_ST_PE_VP_EXPIRED = 0x46,   /* SM Validity Period Expired */
    MTPNP_AD_ST_PE_DEL_BY_ORI_SME = 0x47,       /* SM Deleted by originating SME */
    MTPNP_AD_ST_PE_DEL_BY_SC = 0x48,    /* SM Deleted by SC Administration */
    MTPNP_AD_ST_PE_NOT_EXIST = 0x49,    /* SM does not exist */

    /* 
     * Temporary error, SC is not making any more transfer attempts
     */
    MTPNP_AD_ST_TE2_CONGESTION = 0x60,  /* Congestion */
    MTPNP_AD_ST_TE2_SME_BUSY = 0x61,    /* SME busy */
    MTPNP_AD_ST_TE2_NO_RSP_FROM_SME = 0x62,     /* No response from SME */
    MTPNP_AD_ST_TE2_SERVICE_REJECT = 0x63,      /* Service rejected */
    MTPNP_AD_ST_TE2_QOS_NOT_AVAIL = 0x64,       /* Quality of service not available */
    MTPNP_AD_ST_TE2_ERROR_IN_SME = 0x65,        /* Error in SME */

    MTPNP_AD_ST_SERVICE_REJECT = 0xff   /* all reserved values interpreted as "service reject" */
} E_MTPNP_AD_ST;

typedef enum
{
    MTPNP_AD_MEM_FULL_NORMAL,   /* both SIM and ME are full */
    MTPNP_AD_SM_FULL_ONLY,
    MTPNP_AD_ME_FULL_ONLY
} E_MTPNP_AD_SMS_MEMORY_FULL;

typedef enum
{
    MTPNP_AD_MEM_EXCEED_NORMAL,
    MTPNP_AD_SM_EXCEED_WITH_CLASS2
} E_MTPNP_AD_SMS_MEMORY_EXCEED;

typedef enum
{
    MTPNP_AD_MEM_AVAIL_NORMAL,  /* corresponding to SMSAL_MEM_FULL_NORMAL */
    /* one of storage is avail. it will be sent */
    MTPNP_AD_SM_AVAIL_ONLY,     /* corresponding to SMSAL_SM_FULL_ONLY */
    MTPNP_AD_ME_AVAIL_ONLY      /* corresponding to SMSAL_SM_FULL_ONLY */
} E_MTPNP_AD_SMS_MEMORY_AVAIL;

typedef enum
{
    MTPNP_AD_REC_UNREAD = 0,    /* received unread */
    MTPNP_AD_REC_READ,          /* received read */
    MTPNP_AD_STO_UNSENT,        /* stored unsent */
    MTPNP_AD_STO_SENT,          /* stored sent */

    MTPNP_AD_ALL,               /* all (only applicable to +CMGL command) */
    /* follows intended for MMI only */
    MTPNP_AD_INBOX_PARTIAL,     /* parts of inbox messages */
    MTPNP_AD_OUTBOX_PARTIAL,    /* parts of outbox messages */
    MTPNP_AD_INVALID_STATUS
} E_MTPNP_AD_SMS_STATUS;

#if defined(WIN32)
#pragma pack(push)
#pragma pack(4)
#endif /* WIN32 */

typedef struct
{
    MTPNP_UINT32 DLL_task_mod_id;
    MTPNP_UINT32 MMI_task_mod_id;
    MTPNP_UINT32 PNP_task_startup_msg_id;
    MTPNP_UINT32 PNP_task_stop_msg_id;
    MTPNP_UINT32 PNP_stack_sap_id;
    MTPNP_UINT32 PNP_data_msg_id;
    MTPNP_UINT32 PNP_DLL_resume_msg_id;
    MTPNP_UINT16 PNP_restart_timer_id;
    MTPNP_UINT32 Startup_req_msg_id;
} ST_MTPNP_AD_SYS_ID;

/* call management */
typedef struct
{
    MTPNP_UINT16 nYear;
    MTPNP_UINT8 nMonth;
    MTPNP_UINT8 nDay;
    MTPNP_UINT8 nHour;
    MTPNP_UINT8 nMin;
    MTPNP_UINT8 nSec;
    MTPNP_UINT8 DayIndex;       /* 0=Sunday */
} ST_MTPNP_AD_TIME;

typedef struct
{
    MTPNP_UINT8 ton_npi;
    MTPNP_UINT8 number_len;
    MTPNP_INT8 number[(MTPNP_AD_MAX_CC_ADDR_LEN + 1) * 2];
} ST_MTPNP_AD_CALL_NUMBER;      /*unicode encode */

typedef struct
{
    MTPNP_UINT8 dcs;
    MTPNP_UINT8 name_len;
    MTPNP_UINT8 name[MTPNP_AD_MAX_NAME_LEN];
} ST_MTPNP_AD_CALL_NAME;

typedef struct
{
    MTPNP_UINT8 type;
    MTPNP_UINT8 length;
    MTPNP_UINT8 number[MTPNP_AD_MAX_CC_ADDR_LEN];
} ST_MTPNP_AD_PHONE_NUMBER;


typedef struct
{
    MTPNP_UINT8 dcs;
    MTPNP_UINT8 length;
    MTPNP_UINT8 ussd_string[183];
} ST_MTPNP_AD_CC_USSR_IND;

typedef struct
{
    MTPNP_UINT8 dcs;
    MTPNP_UINT8 length;
    MTPNP_UINT8 ussd_string[183];
} ST_MTPNP_AD_CC_USSN_IND;

typedef struct
{
    MTPNP_UINT8 flag;
    MTPNP_UINT16 cause;
} ST_MTPNP_AD_CC_RESULT;

typedef struct
{
    ST_MTPNP_AD_CC_RESULT result;
    MTPNP_UINT8 para_present;
    MTPNP_UINT8 op_code;
    MTPNP_UINT8 dcs;
    MTPNP_UINT8 length;
    MTPNP_UINT8 ussd_string[183];
} ST_MTPNP_AD_CC_USSD_RSP;
/* call management */

typedef struct
{
    MTPNP_UINT16 ref;           /* concat. message reference */
    MTPNP_UINT8 total_seg;      /* total segments */
    MTPNP_UINT8 seg;            /* indicate which segment */
} ST_MTPNP_AD_SMS_CONCAT;

typedef struct
{
    MTPNP_BOOL need_saved;
    MTPNP_UINT8 profile;
    MTPNP_UINT16 reply_index;
    ST_MTPNP_AD_PHONE_NUMBER dest;
    MTPNP_UINT8 para;
    ST_MTPNP_AD_PHONE_NUMBER sc_addr;
    MTPNP_UINT8 vp;
    MTPNP_UINT8 pid;            /* E_MTPNP_AD_SMS_PID */
    MTPNP_UINT8 udhi;
    MTPNP_UINT8 dcs;            /* E_MTPNP_CODING_SCHEME */
    MTPNP_UINT16 length;
    MTPNP_UINT8 msg[MTPNP_AD_MAX_MSG_LEN];
    MTPNP_UINT8 seq_num;
    MTPNP_UINT8 mms_mode;
} ST_MTPNP_AD_SMS_SEND_MSG;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
    MTPNP_UINT8 mr;
    MTPNP_UINT8 scts[7];
    MTPNP_UINT8 seq_num;
    ST_MTPNP_AD_SMS_CONCAT concat_info;
} ST_MTPNP_AD_SMS_SEND_RSP;

typedef struct
{
    MTPNP_UINT8 profile;
    MTPNP_UINT8 status;
    ST_MTPNP_AD_PHONE_NUMBER dest;
    MTPNP_UINT8 para;
    ST_MTPNP_AD_PHONE_NUMBER sc_addr;
    MTPNP_UINT8 scts[7];
    MTPNP_UINT8 vp;
    MTPNP_UINT8 pid;            /* E_MTPNP_AD_SMS_PID */
    MTPNP_UINT8 udhi;
    MTPNP_UINT8 dcs;            /* E_MTPNP_CODING_SCHEME */
    MTPNP_UINT16 index;
    MTPNP_UINT16 length;
    MTPNP_UINT8 msg[MTPNP_AD_MAX_MSG_LEN];
} ST_MTPNP_AD_SMS_SAVE_MSG;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
    MTPNP_UINT16 index;
    MTPNP_UINT8 status;
    MTPNP_UINT8 storage_type;
} ST_MTPNP_AD_SMS_SAVE_RSP;

typedef struct
{
    MTPNP_UINT8 startup_seq_num;
    MTPNP_UINT8 mti;
    MTPNP_UINT8 status;
    MTPNP_UINT8 storage_type;
    MTPNP_UINT8 fo;
    MTPNP_UINT16 index;
    MTPNP_UINT8 scts[7];
    ST_MTPNP_AD_PHONE_NUMBER addr_number;
    MTPNP_UINT8 pid;
    MTPNP_UINT8 dcs;
    MTPNP_UINT8 ori_dcs;
    MTPNP_UINT8 vp;
    MTPNP_UINT8 mr;
    MTPNP_UINT8 dt[7];
    MTPNP_UINT8 st;
    MTPNP_UINT16 dest_port;
    MTPNP_UINT16 src_port;
    MTPNP_UINT32 concat_info;
    MTPNP_UINT16 no_msg_data;
    MTPNP_UINT8 msg_data[1];
} ST_MTPNP_AD_SMS_LOAD_ONGOING;

typedef struct
{
    MTPNP_UINT8 fo;
    MTPNP_UINT8 scts[7];
    MTPNP_UINT8 dt[7];
    ST_MTPNP_AD_PHONE_NUMBER ra_number;
    MTPNP_UINT8 st;             /* E_MTPNP_AD_ST */
    MTPNP_UINT8 pid;            /* E_MTPNP_AD_SMS_PID */
    MTPNP_UINT8 dcs;            /* E_MTPNP_CODING_SCHEME */
    MTPNP_UINT8 mr;
    MTPNP_UINT16 no_msg_data;
    MTPNP_UINT8 msg_data[1];
} ST_MTPNP_AD_SMS_STATUS_REPORT;

typedef struct
{
    MTPNP_UINT8 fo;
    MTPNP_UINT8 scts[7];
    ST_MTPNP_AD_PHONE_NUMBER sca_number;
    ST_MTPNP_AD_PHONE_NUMBER oa_number;
    MTPNP_UINT8 pid;            /* E_MTPNP_AD_SMS_PID */
    MTPNP_UINT8 dcs;            /* E_MTPNP_CODING_SCHEME */
    MTPNP_UINT8 ori_dcs;
    MTPNP_UINT16 index;
    MTPNP_UINT16 dest_port;
    MTPNP_UINT16 src_port;
    MTPNP_UINT8 mti;
    MTPNP_UINT8 display_type;
    MTPNP_UINT8 storage_type;
    MTPNP_UINT32 concat_info;
    MTPNP_UINT16 no_msg_data;
    MTPNP_UINT8 msg_data[1];
} ST_MTPNP_AD_DELIVER_SMS;

typedef struct
{
    MTPNP_UINT16 dest_mod_id;
    MTPNP_UINT16 dest_port;
    MTPNP_UINT16 src_port;
    MTPNP_UINT8 dcs;
    MTPNP_UINT8 mti;
    MTPNP_UINT16 message_len;
    MTPNP_UINT32 concat_info[(sizeof(ST_MTPNP_AD_SMS_CONCAT) + 3) / 4];
    ST_MTPNP_AD_PHONE_NUMBER oa;
    MTPNP_UINT8 scts[7];
    MTPNP_UINT8 msg_data[MTPNP_AD_MAX_MSG_LEN];
}
ST_MTPNP_AD_APP_DATA;

typedef struct
{
    MTPNP_UINT16 index;
    MTPNP_BOOL change_status;
} ST_MTPNP_AD_SMS_GET_REQ;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
    ST_MTPNP_AD_SMS_CONCAT concat_info;
    MTPNP_UINT8 mti;
    MTPNP_UINT8 status;
    MTPNP_UINT8 storage_type;
    MTPNP_UINT8 fo;
    MTPNP_UINT8 scts[7];
    ST_MTPNP_AD_PHONE_NUMBER sca_number;
    ST_MTPNP_AD_PHONE_NUMBER addr_number;
    MTPNP_UINT8 pid;
    MTPNP_UINT8 dcs;
    MTPNP_UINT8 ori_dcs;
    MTPNP_UINT8 vp;
    MTPNP_UINT8 mr;
    MTPNP_UINT8 dt[7];
    MTPNP_UINT8 st;
    MTPNP_UINT16 dest_port;
    MTPNP_UINT16 src_port;
    MTPNP_UINT16 no_msg_data;
    MTPNP_UINT8 msg_data[1];
} ST_MTPNP_AD_SMS_GET_RSP;

typedef struct
{
    MTPNP_UINT8 del_flag;       /* E_MTPNP_AD_SMS_DEL_FLAG */
    MTPNP_UINT16 index;
    MTPNP_UINT16 bitmap_len;
    MTPNP_UINT8 del_bitmap[1];
} ST_MTPNP_AD_SMS_DEL_REQ;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
    MTPNP_UINT8 del_flag;       /* E_MTPNP_AD_SMS_DEL_FLAG */
    MTPNP_UINT16 index;
    MTPNP_UINT8 storage_type;
    MTPNP_UINT16 bitmap_len;
    MTPNP_UINT8 del_bitmap[1];
} ST_MTPNP_AD_SMS_DEL_RSP;

typedef struct
{
    MTPNP_UINT8 action;
    MTPNP_UINT8 dst_storage;
    MTPNP_UINT16 src_index;
} ST_MTPNP_AD_SMS_COPY_REQ;

typedef struct
{
    MTPNP_UINT8 result;
    MTPNP_UINT16 cause;
    MTPNP_UINT8 action;
    MTPNP_UINT8 dst_storage;
    MTPNP_UINT16 src_index;
    MTPNP_UINT16 dst_index;
} ST_MTPNP_AD_SMS_COPY_RSP;

/* message setup begin */
typedef struct
{
    MTPNP_UINT8 name_length;
    MTPNP_UINT8 name_dcs;
    MTPNP_UINT8 name[32];
} ST_MTPNP_AD_NAME;

typedef struct
{
    MTPNP_UINT8 mem1;
    MTPNP_UINT8 mem2;
    MTPNP_UINT8 mem3;
    MTPNP_UINT8 used1;
    MTPNP_UINT8 used2;
    MTPNP_UINT8 used3;
    MTPNP_UINT8 total1;
    MTPNP_UINT8 total2;
    MTPNP_UINT8 total3;
} ST_MTPNP_AD_SMS_PREFER_STORAGE;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT8 profile_no;
    MTPNP_UINT8 name_len;
} ST_MTPNP_AD_SMS_GET_PROFILE_NUM_RSP;

typedef struct
{
    MTPNP_UINT16 para_ind;
    MTPNP_UINT8 profile_no;
    MTPNP_UINT8 pid;
    MTPNP_UINT8 dcs;
    MTPNP_UINT8 vp;
    ST_MTPNP_AD_PHONE_NUMBER sc_addr;
    ST_MTPNP_AD_NAME profile_name;
} ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_REQ;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
} ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_RSP;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT8 pid;
    MTPNP_UINT8 dcs;
    MTPNP_UINT8 vp;
    ST_MTPNP_AD_PHONE_NUMBER sc_addr;
    ST_MTPNP_AD_NAME profile_name;
} ST_MTPNP_AD_SMS_GET_PROFILE_PARAMS_RSP;

typedef struct
{
    MTPNP_UINT16 para_ind;
    MTPNP_UINT8 fo;
    MTPNP_UINT8 bearer_service;
    MTPNP_UINT8 status_report;
    MTPNP_UINT8 reply_path;
} ST_MTPNP_AD_SMS_SET_COMMON_PARAMS_REQ;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
} ST_MTPNP_AD_SMS_SET_COMMON_PARAMS_RSP;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT8 fo;
    MTPNP_UINT8 bearer_service;
    MTPNP_UINT8 status_report;
    MTPNP_UINT8 reply_path;
} ST_MTPNP_AD_SMS_GET_COMMON_PARAMS_RSP;

typedef struct
{
    MTPNP_UINT8 mem1;
    MTPNP_UINT8 mem2;
    MTPNP_UINT8 mem3;
} ST_MTPNP_AD_SMS_SET_PREFER_STORAGE_REQ;

typedef struct
{
    MTPNP_BOOL result;
    ST_MTPNP_AD_SMS_PREFER_STORAGE param;
} ST_MTPNP_AD_SMS_SET_PREFER_STORAGE_RSP;

typedef struct
{
    MTPNP_BOOL result;
    ST_MTPNP_AD_SMS_PREFER_STORAGE info;
} ST_MTPNP_AD_SMS_GET_PREFER_STORAGE_RSP;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_BOOL is_sim_card_change;
    MTPNP_UINT16 in_sim_no;
    MTPNP_UINT16 in_me_no;
    MTPNP_UINT16 out_sim_no;
    MTPNP_UINT16 out_me_no;
    MTPNP_UINT16 unread_msg_num;
    MTPNP_UINT16 total_sim_num;
    MTPNP_UINT16 total_me_num;
} ST_MTPNP_AD_SMS_GET_MSG_NUM_RSP;

typedef struct
{
    MTPNP_UINT8 line_no;
    MTPNP_UINT8 waiting_num;
    MTPNP_UINT8 ind_type;
    MTPNP_BOOL is_show_num;
    MTPNP_BOOL is_clear;
    MTPNP_BOOL is_from_storage;
} ST_MTPNP_AD_SMS_MSG_WAITING_IND;
/* message setup end */

/* plmn begin */
typedef struct
{
    MTPNP_UINT8 index;
    MTPNP_UINT8 opcode;
    MTPNP_UINT8 oper[MTPNP_AD_MAX_PLMN_LEN + 1];
    MTPNP_UINT8 rat;
} ST_MTPNP_AD_SET_PREFERRED_NETWORK_REQ;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
} ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP;

typedef struct
{
    MTPNP_UINT8 index;
    MTPNP_UINT16 num;
    MTPNP_UINT16 file_idx_req;
} ST_MTPNP_AD_GET_PREFERRED_NETWORK_REQ;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 retnum;
    MTPNP_UINT8 oper_list[MTPNP_AD_MAX_SUPPORT_EF_PLMNSEL_REC * 7];
    MTPNP_UINT8 rat_list[MTPNP_AD_MAX_SUPPORT_EF_PLMNSEL_REC * 2];
    MTPNP_UINT16 file_idx_rsp;
} ST_MTPNP_AD_GET_PREFERRED_NETWORK_RSP;

typedef struct
{
    MTPNP_UINT8 flag;
    MTPNP_UINT16 cause;
} ST_MTPNP_AD_RESULT;

typedef struct
{
    MTPNP_UINT8 plmn_id[MTPNP_AD_MAX_PLMN_LEN + 1];
    MTPNP_UINT8 status;
    MTPNP_UINT8 rat;
} ST_MTPNP_AD_RAT_PLMN_INFO;

typedef struct
{
    MTPNP_UINT8 opcode;
    MTPNP_UINT8 oper[MTPNP_AD_MAX_PLMN_LEN + 1];
    MTPNP_UINT8 rat;
} ST_MTPNP_AD_SET_PLMN_REQ;

typedef struct
{
    ST_MTPNP_AD_RESULT result;
    MTPNP_UINT8 status;
    MTPNP_UINT8 plmn[MTPNP_AD_MAX_PLMN_LEN + 1];
    MTPNP_UINT8 rat;
} ST_MTPNP_AD_SET_PLMN_RSP;

typedef struct
{
    ST_MTPNP_AD_RESULT result;
    MTPNP_UINT8 length;
    ST_MTPNP_AD_RAT_PLMN_INFO list[MTPNP_AD_MAX_PLMN_LIST_LEN];
} ST_MTPNP_AD_GET_PLMN_LIST_RSP;

typedef struct
{
    MTPNP_UINT8 full_nw_nameP;
    MTPNP_UINT8 full_nw_name_dcs;
    MTPNP_BOOL full_nw_name_add_ci;
    MTPNP_UINT8 full_nw_name_len;
    MTPNP_UINT8 full_nw_name[MTPNP_AD_MAX_NW_NAME_LEN];
    MTPNP_UINT8 short_nw_nameP;
    MTPNP_UINT8 short_nw_name_dcs;
    MTPNP_BOOL short_nw_name_add_ci;
    MTPNP_UINT8 short_nw_name_len;
    MTPNP_UINT8 short_nw_name[MTPNP_AD_MAX_NW_NAME_LEN];
    MTPNP_UINT8 nw_time_zoneP;
    MTPNP_UINT8 nw_time_zone;
    MTPNP_UINT8 nw_time_zone_timeP;
    ST_MTPNP_AD_TIME nw_time_zone_time;
    MTPNP_UINT8 lsa_idP;
    MTPNP_UINT8 lsa_id_len;
    MTPNP_UINT8 lsa_id[3];
    MTPNP_UINT8 nw_day_light_saving_timeP;
    MTPNP_UINT8 nw_day_light_saving_time;
}ST_MTPNP_AD_NW_TIME_ZONE_IND;
/* plmn end */

/* cell broadcast messages begin */
typedef struct
{
    MTPNP_UINT16 mid[40];
    MTPNP_UINT16 dcs[15];
    MTPNP_UINT16 mir[30];
    MTPNP_UINT8 mid_mask[40];
    MTPNP_UINT8 mir_mask[15];
    MTPNP_UINT8 dcs_mask[15];
    MTPNP_UINT8 para_ind;
    MTPNP_BOOL is_all_language_on;
    MTPNP_BOOL is_cb_ready;
    MTPNP_BOOL is_sim_change;
} ST_MTPNP_AD_CB_INFO;

typedef struct
{
    MTPNP_UINT16 sn;
    MTPNP_UINT16 mi;
    MTPNP_UINT8 dcs;
    MTPNP_UINT8 page;
    MTPNP_UINT8 pages;
    MTPNP_UINT16 msg_length;
    MTPNP_UINT8 msg_data[1];
} ST_MTPNP_AD_CB_MSG_IND;

typedef struct
{
    ST_MTPNP_AD_CB_INFO info;
} ST_MTPNP_AD_SET_CB_MODE_REQ;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
} ST_MTPNP_AD_SET_CB_MODE_RSP;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT8 mode;
    MTPNP_UINT8 total_mid_num;
    MTPNP_UINT8 total_mir_num;
    MTPNP_UINT8 total_dcs_num;
    ST_MTPNP_AD_CB_INFO info;
} ST_MTPNP_AD_GET_CB_MODE_RSP;
/* cell broadcast messages end */

/* voice mail begin */
typedef struct
{
    ST_MTPNP_AD_NAME name;
    ST_MTPNP_AD_PHONE_NUMBER number_info;
} ST_MTPNP_AD_MAILBOX_INFO;

typedef struct
{
    MTPNP_UINT8 mailbox_num;
    ST_MTPNP_AD_PHONE_NUMBER num_addr;
    ST_MTPNP_AD_NAME name;
} ST_MTPNP_AD_SET_MAILBOX_ADDRESS_REQ;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
} ST_MTPNP_AD_SET_MAILBOX_ADDRESS_RSP;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT8 mailbox_num;
    MTPNP_UINT8 alpha_length;
    ST_MTPNP_AD_MAILBOX_INFO mailbox_info[2];
} ST_MTPNP_AD_GET_MAILBOX_ADDRESS_RSP;
/* voice mail end */

typedef struct
{
    E_MTPNP_AD_CALLLOG_TYPE hitoryType;       /* LND,LNM,LNR */
    MTPNP_UINT8 hitoryIndex;    /*History index */
    MTPNP_UINT16 no_of_times;   /* times of index */
    ST_MTPNP_AD_CALL_NUMBER number;
    ST_MTPNP_AD_CALL_NAME name;
    ST_MTPNP_AD_TIME startTime; /* start time */
    ST_MTPNP_AD_TIME duration;
} MTPNP_AD_REQ_CALL_RECORD_SCT;

typedef struct
{
    MTPNP_BOOL result;          /* MTPNP_TRUE Success, MTPNP_FALSE Failed */
    MTPNP_UINT8 hitoryIndex;    /*History index */
    MTPNP_UINT16 cause;         /* if failed , return cause */
} MTPNP_AD_RSP_SET_CALL_SCT;

typedef struct
{
    E_MTPNP_AD_CALLLOG_TYPE hitoryType;       /* LND,LNM,LNR */
    MTPNP_UINT8 hitoryIndex;    /* 1~0xFE delete specific record, 0xFF delete all */
} MTPNP_AD_REQ_DEL_CALL_SCT;

typedef struct
{
    MTPNP_BOOL result;          /* MTPNP_TRUE Success, MTPNP_FALSE Failed */
    MTPNP_UINT8 hitoryIndex;    /* 0~0xFE delete specific record, 0xFF delete all */
    MTPNP_UINT16 cause;         /* if failed , return cause */
} MTPNP_AD_RSP_DEL_CALL_SCT;

typedef struct
{
    E_MTPNP_AD_CALLLOG_TYPE hitoryType;       /* LND,LNM,LNR */
    MTPNP_UINT8 sequence_ID;    /* batch number */
} MTPNP_AD_REQ_LOAD_CALL_SCT;

typedef struct
{
    MTPNP_BOOL result;          /* MTPNP_TRUE Success, MTPNP_FALSE Failed */
    MTPNP_UINT8 no_list;
    MTPNP_UINT16 cause;         /* if failed , return cause */
    MTPNP_UINT8 type;
    MTPNP_UINT8 more_data;
    MTPNP_AD_REQ_CALL_RECORD_SCT list[1];
} MTPNP_AD_RSP_LOAD_CALL_SCT;

/* CallCost */
typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
} MTPNP_AD_RSP_RESET_CALLCOST_SCT;

typedef struct
{
    MTPNP_UINT8 pin[9];
    MTPNP_UINT8 currency[3];
    MTPNP_UINT8 ppu[18];
} MTPNP_AD_REQ_RESET_CALLCOST_SCT;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT8 currency[3];
    double ppu;
} MTPNP_AD_RSP_READ_CALLCOST_SCT;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT32 ccm;
} MTPNP_AD_RSP_READ_CCM_SCT;
/* CallCost */

/* 
* virtual eint struct
*/
typedef struct
{
    E_MTPNP_PFAL_EINT_NO eint_no;
    MTPNP_UINT8 eint_state;
} ST_MTPNP_AD_VEINT_DATA;

/* 
* cc struct for ddt
*/
typedef struct
{
    MTPNP_UINT8 call_id;
    MTPNP_UINT8 call_state;
    MTPNP_UINT8 mpty;
    MTPNP_UINT8 number[MTPNP_AD_MAX_CC_ADDR_LEN];
} MTPNP_CALL_LIST_ENTRY_STRUCT;

typedef struct
{
    MTPNP_UINT8 length;
    MTPNP_CALL_LIST_ENTRY_STRUCT list[7];
} MTPNP_CALL_LIST_STRUCT;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_CALL_LIST_STRUCT call_list;
} MTPNP_GET_CALL_LIST_RSP;

typedef struct
{
    ST_MTPNP_AD_RESULT result;
    MTPNP_UINT8 para_present;
    MTPNP_UINT8 opcode;
    MTPNP_UINT8 count;
    MTPNP_UINT8 status;
    MTPNP_UINT8 list[13];
} MTPNP_SS_CALL_WAIT_RSP;

typedef struct
{
    MTPNP_UINT8 bs_code;
    MTPNP_UINT8 ss_status;
} MTPNP_BARRING_LIST;

typedef struct
{
    ST_MTPNP_AD_RESULT result;
    MTPNP_UINT8 para_present;
    MTPNP_UINT8 opcode;         /* l4_op_code_enum */
    MTPNP_UINT8 type;
    MTPNP_UINT8 count;
    MTPNP_BARRING_LIST list[13];
} MTPNP_SS_CALL_BARRING_RSP;

typedef struct
{
    MTPNP_UINT8 action;
    MTPNP_UINT8 line_num;
} ST_MTPNP_AD_CFU_IND;

typedef struct
{
    MTPNP_BOOL on_off;          /* calling  is on or off */
    MTPNP_UINT8 rat;            /* calling rat */
} ST_MTPNP_SPEECH_IND_INFO;

typedef struct
{
    E_MTPNP_AD_CALLLOG_TYPE log_type;
    MTPNP_CHAR log_name[MTPNP_AD_MAX_NAME_LEN];
    MTPNP_UCHAR log_num[MTPNP_AD_MAX_CC_ADDR_LEN * 2];
    ST_MTPNP_AD_TIME start_time;
    ST_MTPNP_AD_TIME end_time;
} ST_MTPNP_AD_SET_CALLLOG;
/*struct cc end*/

/* Engineer Mode */
typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT8 mode;
    MTPNP_UINT8 melody[7];
    MTPNP_UINT8 sound[7];
    MTPNP_UINT8 keytone[7];
    MTPNP_UINT8 speech[7];
    MTPNP_UINT8 mic[7];
    MTPNP_UINT8 sidetone;
    MTPNP_UINT8 max_melody_volume_gain;
    MTPNP_UINT8 melody_volume_gain_step;
    MTPNP_UINT8 tv_out_volume_gain[7];
} ST_MTPNP_AD_AUDIO_PROFILE;

typedef struct
{
    MTPNP_BOOL result;
    MTPNP_UINT16 cause;
} ST_MTPNP_AD_SET_AUDIO_PROF_RSP;
/* Engineer Mode */

/*
typedef struct
{
   MTPNP_UINT8 type;
   MTPNP_UINT8 length;
   MTPNP_UINT8 number[MTPNP_AD_MAX_CC_ADDR_LEN];
} ST_MTPNP_L4C_NUMBER_STRUCT;
*/

typedef struct
{
    MTPNP_LOCAL_PARA_HDR
    ST_MTPNP_L4C_NUMBER_STRUCT   dest;
    MTPNP_UINT8   call_type; /* csmcc_call_type_enum */
    MTPNP_UINT8   clir_flag; /* csmcc_clir_info_enum */
    MTPNP_BOOL    cug_option;
} ST_MTPNP_AD_CC_DIAL_REQ_IND;

#if defined(WIN32)
#pragma pack(pop)
#endif /* WIN32 */

#ifdef __cplusplus
}
#endif

#endif  /* __MTPNP_AD_COMMON_DEF_H__ */
