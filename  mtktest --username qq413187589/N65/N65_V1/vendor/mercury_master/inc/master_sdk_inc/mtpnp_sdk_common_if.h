/***********************************************************
 * system name	: MTPNP protocol SDK
 * file name	: MTPNP_SDK_if.h
 * contents		: MTPNP SDK common interface definition for both master side and slave side
 *				:	
 * History		: Feb 23, 2006: Created by HYU
 ***********************************************************/
 
#ifndef _MTPNP_SDK_COMMON_IF_H_
#define _MTPNP_SDK_COMMON_IF_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Module Startup Mode definition */
typedef enum {
	MTPNP_SLAVE_STARTUP_NORMAL,			/* slave startup to normal mode */
	MTPNP_SLAVE_STARTUP_RF_OFF,			/* startup to RF off mode */
	MTPNP_SLAVE_STARTUP_DOWNLOAD,		/* startup to download mode */
	MTPNP_SLAVE_STARTUP_TEST,			/* startup to test mode */
	MTPNP_SLAVE_STARTUP_PRODUCTION_TEST,/* startup to production test mode */
	MTPNP_SLAVE_STARTUP_SYSTEM_TEST,	/* startup to system test mode */
	MTPNP_SLAVE_STARTUP_INITIALIZATION	/* startup to MTPNP-SDK initialization mode */
} E_MTPNP_SLAVE_STARTUP_MODE;

/* Module Shutdown Mode definition */
typedef enum {
	MTPNP_SLAVE_SHUTDOWN_NORMALLY,		/* request slave module shutdown normally */
	MTPNP_SLAVE_SHUTDOWN_RESET			/* request slave module shutdown and reset */
} E_MTPNP_SLAVE_SHUTDOWN_MODE;

typedef enum
{
	MTPNP_SDK_NORMAL_MODE,		/* MTPNP startup as normal mode */
	MTPNP_SDK_INITIALIZING_MODE,	/* MTPNP startup as calibration mode */
	MTPNP_SDK_TOOLS_MODE		/* MTPNP startup as third-party tools mode */
} E_MTPNP_STARTUP_MODE;

typedef enum
{
	MTPNP_FALSE	= 0,
	MTPNP_TRUE	= 1
} MTPNP_BOOL;

#define MTPNP_SESSION_TASK_MAX	5		// define max task which use session transfer
#define MTPNP_SESSION_CAPABILITY_MAX	10		// define max session occurred simultaneity for each session-task

#define MTPNP_NULL 0

#define MTPNP_MAX_VER_INFO_LEN	16

#define MTPNP_CC_CALL_ID_ALL			0xFF
#define MTPNP_CC_CALL_ID_ALL_CONNECTED	0xFC
#define MTPNP_CC_CALL_ID_ALL_INACTIVE	0xFE
#define MTPNP_CC_CALL_ID_ALL_ACTIVE		0xFD
#define MTPNP_CC_MAX_CC_ADDR_LEN 	41

typedef char			MTPNP_CHAR;
typedef signed char		MTPNP_INT8;
typedef signed short	MTPNP_INT16;
typedef signed long		MTPNP_INT32;
typedef signed int		MTPNP_INT;
typedef unsigned char	MTPNP_UINT8;
typedef unsigned short	MTPNP_UINT16;
typedef unsigned long	MTPNP_UINT32;
typedef unsigned char	MTPNP_UCHAR;
typedef unsigned int	MTPNP_UINT;

/* Common definition */
typedef enum
{
	MTPNP_UART0,
	MTPNP_UART1,
	MTPNP_UART2,
	MTPNP_UART3,
	MTPNP_UART4,
	MTPNP_UART5,
	MTPNP_UART6,
	MTPNP_UART7,
	MTPNP_UART8,
	MTPNP_UART9,
	MTPNP_UART10,
	MTPNP_UART11,
	MTPNP_UART12,
	MTPNP_UART13,
	MTPNP_UART14,
	MTPNP_UART15,
	MTPNP_UART16,
	MTPNP_UART_MAX
} E_MTPNP_SDK_UART_DEF;

typedef enum {
	MTPNP_BAUDRATE_HANDSHAKE= 0x0000,
	MTPNP_BAUDRATE_9600		= 0x0001,
	MTPNP_BAUDRATE_14400	= 0x0002,
	MTPNP_BAUDRATE_19200	= 0x0004,
	MTPNP_BAUDRATE_28800	= 0x0008,
	MTPNP_BAUDRATE_33600	= 0x0010,
	MTPNP_BAUDRATE_38400	= 0x0020,
	MTPNP_BAUDRATE_57600	= 0x0040,
	MTPNP_BAUDRATE_LOW_MSK	= 0x0080,
	MTPNP_BAUDRATE_115200	= 0x0100,
	MTPNP_BAUDRATE_230400	= 0x0200,
	MTPNP_BAUDRATE_460800	= 0x0400,
	MTPNP_BAUDRATE_921600	= 0x0800,
	MTPNP_BAUDRATE_RESERVED1	= 0x1000,
	MTPNP_BAUDRATE_RESERVED2	= 0x2000,
	MTPNP_BAUDRATE_RESERVED3	= 0x4000,
	MTPNP_BAUDRATE_HIGH_MSK		= 0x8000
} E_MTPNP_UART_BAUDRATE;

typedef enum
{
	MTPNP_PROGRESS_ERROR,		/* Error occurred during process, progress is continue to next one */
	MTPNP_PROGRESS_ONGOING,		/* Progress ongoing */
	MTPNP_PROGRESS_FINISHED		/* Progress finished */
} E_MTPNP_PROGRESS_STATUS;

/* Define coding scheme */
typedef enum
{
	MTPNP_CODING_SCHEME_DEFAULT,
	MTPNP_CODING_SCHEME_ASCII,
	MTPNP_CODING_SCHEME_UCS2,
	MTPNP_CODING_SCHEME_GB2312,
	MTPNP_CODING_SCHEME_BIG5,
	MTPNP_CODING_SCHEME_STREAM,
	MTPNP_CODING_SCHEME_UNKNOWN
} E_MTPNP_CODING_SCHEME;

/* Define startup failed reason */
typedef enum
{
	MTPNP_STARTUP_FINISHED			= 0,	/* Slave module startup procedure end normally */
	MTPNP_STARTUP_SIM_CARD_ABSENT	= 1,	/* SIM card of slave module is absent, startup procedure finished */
	MTPNP_STARTUP_SIM_CHV1_ENABLED	= 2		/* CHV1 verification is enabled, startup procedure paused */
} E_MTPNP_SLAVE_STARTUP_RESULT;

/* Define SIM card status */
typedef enum
{
	MTPNP_SIM_STATUS_UNNECESSARY	= 0,	/* SIM card is un-necessary for slave module */
	MTPNP_SIM_STATUS_ABSENT			= 1,	/* SIM card absent */
	MTPNP_SIM_STATUS_CHV1_ENABLED	= 2,	/* SIM card is ready for use and CHV1 is enabled */
	MTPNP_SIM_STATUS_CHV1_DISABLED	= 3		/* SIM card is ready for use and CHV1 is disabled */
} E_MTPNP_SIM_STATUS; 

/* Define ISR trigger type */
typedef enum
{
	MTPNP_ISR_TRIGGER_HIGH_LVL,
	MTPNP_ISR_TRIGGER_LOW_LVL,
	MTPNP_ISR_TRIGGER_RISING_EDGE,
	MTPNP_ISR_TRIGGER_FALLING_EDGE
} E_MTPNP_ISR_TRIGGER_TYPE;

/* Define ISR information */
typedef struct
{
	MTPNP_UINT8 number;
	E_MTPNP_ISR_TRIGGER_TYPE type;
} ST_MTPNP_ISR_INFO;

/* Describe SIM card CHV status */
typedef struct 
{
	E_MTPNP_SIM_STATUS SIM_card_status;	// SIM card status: 
										//	MTPNP_SIM_STATUS_UNNECESSARY
										//	MTPNP_SIM_STATUS_ABSENT
										//	MTPNP_SIM_STATUS_CHV1_ENABLED
										//	MTPNP_SIM_STATUS_CHV1_DISABLED
	MTPNP_UINT8 CHV1_status;			// CHV1 status. 
										//	b8: 0:secret code not initialized/1:secret code initialized
										//	b5-b7: RFU
										//	b1-b4: Number of false presentations remaining('0' means blocked)
	MTPNP_UINT8 UNBLOCK_CHV1_status;	// UNBLOCK CHV1 status. 
										//	b8: 0:secret code not initialized/1:secret code initialized
										//	b5-b7: RFU
										//	b1-b4: Number of false presentations remaining('0' means blocked)
	MTPNP_UINT8 CHV2_status;			// CHV2 status. 
										//	b8: 0:secret code not initialized/1:secret code initialized
										//	b5-b7: RFU
										//	b1-b4: Number of false presentations remaining('0' means blocked)
	MTPNP_UINT8 UNBLOCK_CHV2_status;	// UNBLOCK CHV2 status. 
										//	b8: 0:secret code not initialized/1:secret code initialized
										//	b5-b7: RFU
										//	b1-b4: Number of false presentations remaining('0' means blocked)
} ST_MTPNP_DATA_SIM_CARD_CHV_INFO;

/* Define SIM CHV type */
#define MTPNP_SIM_CHV1	1	/* CHV1 of SIM card */
#define MTPNP_SIM_CHV2	2	/* CHV2 of SIM card */

typedef enum
{
	MTPNP_CM_PHS_MODULE,
	MTPNP_CM_GSM_MODULE,
	MTPNP_PC_SIMULATOR,
	MTPNP_CALIBRATION_TOOLS,
	MTPNP_UNKNOWN_MODULE
} E_MTPNP_SLAVE_MODULE_TYPE;

typedef enum
{
	MTPNP_QOS_RPT_STOP	= 0,	/* stop report QOS */
	MTPNP_QOS_RPT_CCH,			/* report QOS only when CCH establish success or failed */
	MTPNP_QOS_RPT_GRID,			/* report QOS only when display grid changed */
	MTPNP_QOS_RPT_LVL,			/* report QOS only when QOS value changed */
	MTPNP_QOS_RPT_ANY			/* report each QOS even if the QOS value is not changed */
} E_MTPNP_QOS_RPT_FREQUENCY;

typedef enum
{
	MTPNP_LOCAL_NUMBER_DETERMINED_BY_NETWORK,	/* Send or Hide is determined by network */
	MTPNP_LOCAL_NUMBER_HIDE,	/* Hide local number to network during MO-call or MO-SMS */
	MTPNP_LOCAL_NUMBER_SEND		/* Send local number to network during MO-call or MO-SMS */
} E_MTPNP_LOCAL_NUMBER_STATUS;

typedef enum
{
	MTPNP_SDK_NOT_INITIALIZED,
	MTPNP_SLAVE_UNPLUGGED,
	MTPNP_SLAVE_PLUGIN,
	MTPNP_SLAVE_POWERON_ONGOING,
	MTPNP_SLAVE_IDLE,
	MTPNP_SLAVE_SHUTDOWN_ONGOING,
	MTPNP_SLAVE_SHUTDOWN
} E_MTPNP_SLAVE_STATUS;

typedef enum
{
	MTPNP_NET_STATUS_LOST,
	MTPNP_NET_STATUS_ATTACH_FAILED,
	MTPNP_NET_STATUS_ATTACHED_HOME,
	MTPNP_NET_STATUS_ATTACHED_ROAM,
    MTPNP_NET_STATUS_UPDATE_PLMN
} E_MTPNP_NETWORK_STATUS;

typedef enum
{
	MTPNP_STORAGE_TYPE_NONE,
	MTPNP_STORAGE_TYPE_SIM,
	MTPNP_STORAGE_TYPE_NATIVE,
	MTPNP_STORAGE_TYPE_ANY
} E_MTPNP_STORAGE_TYPE;

typedef struct {
	E_MTPNP_SLAVE_MODULE_TYPE module_type;	/* indicate slave module type */
	MTPNP_UINT32 normal_feature;				/* indicate slave supported normal feature */
	MTPNP_UINT32 extend_feature;				/* indicate slave supported extend feature */
} ST_MTPNP_SLAVE_MODULE_INFO;

typedef struct {
	E_MTPNP_NETWORK_STATUS current_status;	/* indicate current network status */
	E_MTPNP_CODING_SCHEME coding_scheme;	/* coding scheme of network identifier */
	MTPNP_UINT8 * network_id;
} ST_MTPNP_NETWORK_STATUS;

typedef struct 
{
	MTPNP_UINT8 QOS_grid_value;
	MTPNP_UINT8 QOS_value;
}ST_MTPNP_QOS_INFO;

typedef struct {
	MTPNP_UINT8 type;			/* Authentication type */
	MTPNP_UINT8 retry_left;	/* Authentication Retry times left */
} ST_MTPNP_DATA_AUTH_INFO;

typedef struct {
	MTPNP_UINT8 type;			/* 1: MTPNP_SIM_CHV1 */
								/* 2: MTPNP_SIM_CHV2 */
	MTPNP_UINT8 CHV_value[8];	/* first CHV value, maybe old CHV or unblock CHV value */
	MTPNP_UINT8 new_CHV[8];	/* New CHV value */
} ST_MTPNP_DATA_CHANGE_CHV_INFO;

typedef struct {
	MTPNP_UINT8 type;			/* 1: MTPNP_SIM_CHV1 */
								/* 2: MTPNP_SIM_CHV2 */
	MTPNP_UINT8 CHV_value[8];	/* CHV value, maybe old CHV or unblock CHV value */
} ST_MTPNP_DATA_CHV_VALUE;

typedef struct
{
	MTPNP_UINT8 total_coding_scheme;		/* Total supported coding scheme */
	MTPNP_UINT8 * coding_scheme_list;		/* coding scheme list, each byte indicate one coding scheme */
} ST_MTPNP_DATA_CODING_SCHEME_LIST;

typedef struct
{
	E_MTPNP_STORAGE_TYPE storage;	/* storage type */
	MTPNP_UINT8 max_name_len;		/* max length of name field */
	MTPNP_UINT8 max_number_len;		/* max length of number field */
	MTPNP_UINT16 capacity;			/* capacity of phonebook */
} ST_MTPNP_DATA_PB_CAPACITY;

typedef struct
{
	E_MTPNP_STORAGE_TYPE storage;	/* indicate storage type */
	MTPNP_UINT16 max_content_len;	/* max length of SMS content */
	MTPNP_UINT16 capacity;			/* capacity of SMS */
} ST_MTPNP_DATA_SMS_CAPACITY;

typedef struct
{
	E_MTPNP_CODING_SCHEME coding_scheme;	/* coding scheme of content */
	MTPNP_UINT8 * content;				/* content of transparent EF, terminated with '\0' */
} ST_MTPNP_DATA_TEF_CONTENT;

typedef struct
{
	E_MTPNP_STORAGE_TYPE storage;	/* indicate storage type of record */
	MTPNP_UINT16 idx;				/* index of current record */
									/* When used in MO-SMS, this idx is used to indicate peer side whether this SMS should be saved, 0:false/1:true */
									/* When used in MT-SMS, this idx is used to describe storage index os incoming SMS */
}
ST_MTPNP_DATA_STORAGE_W_IDX;

typedef struct
{
    E_MTPNP_STORAGE_TYPE storage;   /* indicate storage type of record */
    MTPNP_UINT16 idx;
    MTPNP_UINT16 name_length;
} ST_MTPNP_PHB_WRITE_ENTRY_SUCCESS_CONTENT;

typedef struct
{
	E_MTPNP_STORAGE_TYPE storage;	/* indicate storage type of record */
	MTPNP_UINT16 fail_cause;				/* index of current record */
}
ST_MTPNP_DATA_STORAGE_W_FAIL_CAUSE;

typedef struct
{
	ST_MTPNP_DATA_STORAGE_W_IDX index;	/* indicate storage type & index of phonebook record */
	E_MTPNP_CODING_SCHEME coding_scheme;/* coding scheme of name field */
       MTPNP_UINT8 name_length;
	MTPNP_UINT8 * name;			/* name field of ADN record, terminated with '\0' */
	MTPNP_UINT8 TON_NPI;		/* type of number & numbering play indicator */
	MTPNP_UINT8 * number;		/* number field of ADN record, coded in ASCII, terminated with '\0' */
} ST_MTPNP_DATA_PB_RECORD_INFO;

typedef struct
{
    MTPNP_UINT8 storage;
    MTPNP_UINT8 type;
    MTPNP_UINT8 index;
    MTPNP_UINT8 record_index;
    MTPNP_UINT8 tel_length;
    MTPNP_UINT8 *tel_bcd;
    MTPNP_UINT8 name_length;
    MTPNP_UINT8 name_dcs;
    MTPNP_UINT8 *name;
}ST_MTPNP_DATA_ADN_ENTRY;

typedef struct
{
    MTPNP_UINT16 index;
    MTPNP_BOOL is_delete_all;
}ST_MTPNP_DATA_ADN_IS_DELETE_ALL;

typedef struct
{
	MTPNP_CHAR cur_code[3];		/* Currency Code*/
	MTPNP_UINT16 ppu;	/* Price Per Unit*/
}ST_MTPNP_DATA_PUCT_RECORD_INFO;

typedef enum
{
	MTPNP_SMS_STATUS_EMPTY	= 0x0,
	MTPNP_SMS_STATUS_READ	= 0x01,
	MTPNP_SMS_STATUS_TOBE_READ	= 0x03,
	MTPNP_SMS_STATUS_SENT	= 0x05,
	MTPNP_SMS_STATUS_TOBE_SEND	= 0x07,
	MTPNP_SMS_STATUS_LOCKED_READ= 0x09,
	MTPNP_SMS_STATUS_LOCKED_TOBE_READ	= 0x0B,
	MTPNP_SMS_STATUS_LOCKED_SENT= 0x0D,
	MTPNP_SMS_STATUS_LOCKED_TOBE_SEND	= 0x0F,
	MTPNP_SMS_STATUS_ANY	= 0xFF
}E_MTPNP_SMS_STATUS;

typedef struct
{
	MTPNP_UINT8 total_ecc;	/* indicate how many ecc exist */
	MTPNP_UINT8 *ecc_list;	/* contains all ecc number, see GSM 11.11 for coding details */
} ST_MTPNP_DATA_ECC_INFO;

typedef struct
{
	MTPNP_UINT8 total_PLMN;	/* indicate how many PLMN exist */
	MTPNP_UINT8 *PLMN_list;	/* contains all PLMN list, see GSM 11.11 for coding details */
} ST_MTPNP_DATA_PLMN_INFO;

typedef struct
{
	MTPNP_UINT8 total_FPLMN;	/* indicate how many forbidden-PLMN exist */
	MTPNP_UINT8 *FPLMN_list;	/* contains all forbidden-PLMN list, see GSM 11.11 for coding details */
} ST_MTPNP_DATA_FPLMN_INFO;

typedef struct
{
   MTPNP_UINT8 type;
   MTPNP_UINT8 length;
   MTPNP_UINT8 number[MTPNP_CC_MAX_CC_ADDR_LEN];
} ST_MTPNP_L4C_NUMBER_STRUCT;

typedef struct
{
	MTPNP_UINT8 call_id;		/* ID of call */
	MTPNP_UINT8 TON_NPI;		/* type of number & numbering play indicator */
	MTPNP_UINT8 * number;		/* number field, coded in ASCII, terminated with '\0' */
	MTPNP_UINT8 call_type;
	ST_MTPNP_L4C_NUMBER_STRUCT l4c_number;
} ST_MTPNP_DATA_CALL_INFO;

typedef struct
{
	ST_MTPNP_DATA_STORAGE_W_IDX index;	/* indicate storage type & index of SMS record */
	E_MTPNP_SMS_STATUS status;		/* SMS status */
	MTPNP_UINT8 current_fragment;	/* Current Fragment of this SMS */
	MTPNP_UINT8 total_fragment;		/* Total Fragments of this SMS */
	MTPNP_UINT8 time_stamp[7];		/* time stamp of current SMS */
	MTPNP_UINT8 TON_NPI;			/* type of number & numbering play indicator */
	MTPNP_UINT8 * number;			/* number field of SMS record, coded in ASCII, terminated with '\0' */
	E_MTPNP_CODING_SCHEME coding_scheme;	/* indicate which coding scheme is using for the content */
	MTPNP_UINT16 content_len;		/* indicate valid content length */
	MTPNP_UINT8 * content;			/* SMS content */
} ST_MTPNP_DATA_SMS_INFO;

typedef struct {
	MTPNP_UINT16 frequency;	/* Frequency of the tone */
	MTPNP_UINT16 elapse;		/* Elapse time of one tone, in ms */
	MTPNP_UINT16 interval;	/* Interval time between two tones, in ms */
	MTPNP_UINT8 times;		/* Total play times of the tone */
								/* 0: Stop current play tone procedure */
								/* >0: Total play times */
} ST_MTPNP_DATA_PLAY_TONE;

/* Define debug info structure */
typedef struct
{
	MTPNP_UINT8 level;		/* level of debug info */
	MTPNP_UINT8 sender;		/* sender ID of debug info */
	MTPNP_UINT8 * content;	/* content of debug info */
} ST_MTPNP_DATA_DBG_INFO;

/* Define Directly-Data-Transfer info structure */
typedef struct
{
	MTPNP_UINT16 length;		/* Length of DDT body */
	MTPNP_UINT8 * content;	/* Directly Data Transfer content */
} ST_MTPNP_DATA_DDT_CONTENT;

/* Define Call-Forward Type */
typedef enum
{
	MTPNP_CFU,		/* Call Forward Unconditional */
	MTPNP_CFNRC,	/* Call Forward When Not Reachable */
	MTPNP_CFNRY,	/* Call Forward When Not Reply */
	MTPNP_CFA,		/* All Call Forward */
	MTPNP_CFB,		/* Call Forward When Busy */
	MTPNP_CFC		/* Terminating calling forward */
} E_MTPNP_CALL_FOWARD; 

typedef struct
{
	E_MTPNP_CALL_FOWARD Type;		/* the type of calling forward */
	MTPNP_UINT8 Status;				/* calling forward is opened or closed */
	MTPNP_UINT8 *Address;			/* the number which is called forward */
	MTPNP_UINT8 nSeconds;			/* how many seconds are used  when the type is MTPNP_CFU */
}ST_MTPNP_CALL_FORWARD_INFO;

typedef struct
{
	MTPNP_UINT16 index;		/* index of current record */
	E_MTPNP_CODING_SCHEME coding_scheme;	/* coding scheme of name field */
	MTPNP_UINT8 * name;		/* name field of ADN record, terminated with '\0' */
	MTPNP_UINT8 TON_NPI;		/* type of number & numbering play indicator */
	MTPNP_UINT8 * number;		/* number field of FDN record, coded in ASCII, terminated with '\0' */
} ST_MTPNP_DATA_FDN_RECORD_INFO;

typedef struct
{
	MTPNP_UINT8 max_name_len;		/* max length of name field */
	MTPNP_UINT8 max_number_len;	/* max length of number field */
	MTPNP_UINT16 capacity;		/* capacity of FDN */
} ST_MTPNP_DATA_FDN_CAPACITY;

typedef enum
{
	MTPNP_SST_TYPE_ADN = 2,
	MTPNP_SST_TYPE_FDN = 3
}E_MTPNP_SST_TYPE;

#define MTPNP_SST_STATUS_NOT_ALLOCATED 0x00
#define MTPNP_SST_STATUS_ALLOCATED_AND_NOT_ACTIVATED 0x01
#define MTPNP_SST_STATUS_ALLOCATED_AND_ACTIVATED 0x03

typedef struct
{
	E_MTPNP_SST_TYPE type;
	MTPNP_UINT8 state;
}ST_MTPNP_DATA_SST_STATE;

typedef struct
{
	MTPNP_BOOL result;
	E_MTPNP_SST_TYPE type;
	MTPNP_UINT8 reason;
}ST_MTPNP_DATA_SST_UPDATE_INFO;

typedef struct
{
	E_MTPNP_SST_TYPE type;
	MTPNP_UINT8 reason;
}ST_MTPNP_DATA_SST_UPDATE_RECORD;

typedef struct
{
	MTPNP_UINT16 year;	/*the year of the time */ 
	MTPNP_UINT8 month;	/*the month of the time */ 
	MTPNP_UINT8 day;	/*the day of the time */ 
	MTPNP_UINT8 hour;	/*the hour of the time */ 
	MTPNP_UINT8 minute;	/*the minute of the time */ 
	MTPNP_UINT8 second;	/*the second of the time */ 
	MTPNP_UINT8 time_zone;	/*the timezone of the time */ 
}ST_MTPNP_DATE_TIME;

typedef struct
{
	MTPNP_UINT16 index;		/* index of current record */
	E_MTPNP_CODING_SCHEME coding_scheme;	/* coding scheme of name field */
	MTPNP_UINT8 * name;		/* name field of ADN record, terminated with '\0' */
	MTPNP_UINT8 TON_NPI;		/* type of number & numbering play indicator */
	MTPNP_UINT8 * number;		/* number field of ADN record, coded in ASCII, terminated with '\0' */
} ST_MTPNP_DATA_MSISDN_RECORD_INFO;

typedef struct
{
	MTPNP_UINT8 max_name_len;		/* max length of name field */
	MTPNP_UINT8 max_number_len;	/* max length of number field */
	MTPNP_UINT16 capacity;		/* capacity of EFMSISDN */
} ST_MTPNP_DATA_MSISDN_CAPACITY;

typedef enum
{
	MTPNP_SMS_TYPE_WORD,
	MTPNP_SMS_TYPE_FAX,
	MTPNP_SMS_TYPE_CALL,
	MTPNP_SMS_TYPE_EMAIL
}E_MTPNP_SMS_TYPE;	/* the type of sms */

typedef struct
{
	MTPNP_UINT8 index;	/* index of the current record */
	E_MTPNP_CODING_SCHEME name_coding_scheme;	/* coding scheme of name field */
	MTPNP_UINT8 * name;		/* name field of SMSP record, terminated with '\0' */
	MTPNP_UINT8 TON_NPI;/* type of number & numbering play indicator */
	MTPNP_UINT8 * center_address_number;	/* TS - Service Center Address */
	E_MTPNP_SMS_TYPE data_coding_scheme;	/* TP - Data Coding Scheme */
	MTPNP_UINT8 validity_period;	/* TP - Validity period */
}ST_MTPNP_DATA_SMSP_RECORD_INFO;

typedef struct
{
	MTPNP_UINT8 max_name_len;		/* max length of name field */
	MTPNP_UINT8 max_number_len;	/* max length of number field */
	MTPNP_UINT16 capacity;		/* capacity of EFSMSP */
} ST_MTPNP_DATA_SMSP_CAPACITY;

typedef enum
{
	MTPNP_SMS_STAUS_IN_PROGRESS,
	MTPNP_SMS_STAUS_VALIDITY_PERIOD_EXPIRED,
	MTPNP_SMS_STAUS_DELIVERY_FAILED,
	MTPNP_SMS_STAUS_DELIVERY_SUCCESS,
	MTPNP_SMS_STAUS_MESSAGE_CANCELLED,
	MTPNP_SMS_STAUS_MESSAGE_DELETED
}E_MTPNP_SMS_STAUS;

typedef enum
{

	MTPNP_SMS_DELIVERY_ERROR_NO_ERROR_CODE = 0,
	MTPNP_SMS_DELIVERY_ERROR_UNKNOWN_SUBCRIBER = 1,
	MTPNP_SMS_DELIVERY_ERROR_NO_SMS_TELESERVICE = 11,
	MTPNP_SMS_DELIVERY_ERROR_CALL_BARRED = 13,
	MTPNP_SMS_DELIVERY_ERROR_MS_NOT_SUPPORT_SMS = 19,
	MTPNP_SMS_DELIVERY_ERROR_MS_ERROR = 20,
	MTPNP_SMS_DELIVERY_ERROR_FACILITY_NOT_SUPPORTED = 21,
	MTPNP_SMS_DELIVERY_ERROR_ABSENT_SUBSCRIBER = 29,
	MTPNP_SMS_DELIVERY_ERROR_SYSTEM_FAILURE = 36
}E_MTPNP_SMS_DELIVERY_ERROR_CODE;

typedef struct
{
	MTPNP_UINT8 index;
	MTPNP_UINT8 time_stamp[7];
	MTPNP_UINT8 dest_TON_NPI;
	MTPNP_UINT8 * dest_number;
	MTPNP_UINT8 src_TON_NPI;
	MTPNP_UINT8 * src_number;
	MTPNP_UINT8 discharge_time[14];
	MTPNP_UINT8 status;
	MTPNP_UINT8 delivery_error_code;
}ST_MTPNP_DATA_SMS_STATUS_REPORT;

typedef struct
{
	MTPNP_UINT8 dest_addr_len;
	MTPNP_UINT8 src_addr_len;
	MTPNP_UINT8 content_len;
	MTPNP_UINT8 * content;
}ST_MTPNP_DATA_SMS_STATUS_REPORT_CONTENT;

typedef struct
{
	MTPNP_UINT8 QOS_value;	/* the value of QOS */
	MTPNP_UINT8 network_info_length;	/* the length of network information */
	MTPNP_UINT8 * network_info;	/* the net work information */
}ST_MTPNP_DATA_QOS_NETWORK_INFO;

typedef struct
{
	MTPNP_UINT32 psn_info;	/* the primitive information of psn */
	MTPNP_UINT32 e_psn_info;/* the encrypted information of psn */
}ST_MTPNP_DATA_PSN_INFO;

typedef struct
{
	MTPNP_UINT8 call_id;	/* the released call */
	MTPNP_UINT16 release_reason;/* the reason for released call */
}ST_MTPNP_DATA_RELEASE_CALL_INFO;

/********************************************************************
* Public SDK Interface functions
********************************************************************/
MTPNP_BOOL MTPNP_Direct_Data_Transfer(MTPNP_UINT data_len, MTPNP_UINT8 * data);
MTPNP_BOOL MTPNP_HP_Direct_Data_Transfer(
		MTPNP_UINT data_len, 
		MTPNP_UINT8 * data);

MTPNP_BOOL MTPNP_Write_PSN_info(const MTPNP_UINT8 *record);
MTPNP_BOOL MTPNP_Report_PSN(void);
MTPNP_BOOL MTPNP_Startup_Read_PSN(void);
MTPNP_BOOL MTPNP_Read_Local_PSN_Info(MTPNP_UINT8 PSN_info[8]);
MTPNP_BOOL MTPNP_Write_SDK_CFG_Data(const MTPNP_UINT8 * cfg_data);
MTPNP_BOOL MTPNP_Read_SDK_CFG_Data(void);
MTPNP_BOOL MTPNP_Erase_SDK_CFG_Data(void);

void MTPNP_SDK_Shutdown(const MTPNP_BOOL gracefully);
void MTPNP_Dispatcher(const MTPNP_UINT8 * msg);
MTPNP_INT32 MTPNP_Get_SDK_Revision(void);

/********************************************************************
* Fixed Callback functions which must implemented in SDK customer side
********************************************************************/
/* Output string to debug-trace system */
void MTPNP_FCB_Output_Local_Debug_String(const MTPNP_UINT8 * dbg_info);

void MTPNP_FCB_Snd_Data_To_App(const void * pData, const MTPNP_UINT16 len);

/* Enable Wakeup Signal*/
void MTPNP_FCB_Enable_Wakeup_Signal(void);

/* Disable Wakeup Signal*/
void MTPNP_FCB_Disable_Wakeup_Signal(void);

/* write the configuration data */
void MTPNP_FCB_write_config_data(MTPNP_UINT8 * cfg_data, MTPNP_INT cfg_data_len);

/* read the configuration data */
void MTPNP_FCB_read_config_data(MTPNP_UINT8 * cfg_data, MTPNP_INT cfg_data_len);

/* read the unique ID information */
void MTPNP_FCB_get_UID(MTPNP_UCHAR uid[15]);

/* read the current time information */
void MTPNP_FCB_get_Current_Time(ST_MTPNP_DATE_TIME * date_time);

#define MTPNP_DEFAULT_QOS_REPORT_FREQUENCY	MTPNP_QOS_RPT_GRID

#ifdef __cplusplus
}
#endif

#endif

