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

/*******************************************************************************
 * Filename:
 * ---------
 *	rmmi_common_enum.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/



#ifndef _RMMI_COMMON_ENUM_H
#define _RMMI_COMMON_ENUM_H


#ifdef __EM_AT_ONLY__
#define MAX_DATA_QUEUE_LENGTH       256
#elif defined (__SLIM_AT__)
#define MAX_DATA_QUEUE_LENGTH       350
#elif defined (__MMI_FMI__)
#define MAX_DATA_QUEUE_LENGTH       512
#else
#define MAX_DATA_QUEUE_LENGTH       1024
#endif

#define MAX_UART_LENGTH             128

#define RMMI_MAX_EXT_CMD_NAME_LEN   10

#define RMMI_MAX_ERR_STR_LEN	      80
//#define RMMI_MAX_ERROR_NUM          256
#define RMMI_MAX_ERROR_NUM          160

#define RMMI_MAX_ARG_NUM		      16

#define RMMI_VALIDATOR_ERROR        255
#define RMMI_DEF_VALUE              0

#define RMMI_SHORT_RSP_LEN          80

#define RMMI_MAX_MELODY_LEN			64

#ifdef __CMUX_SUPPORT__
#define RMMI_MAX_CHANNEL_NUMBER	3   //  for __CMUX_SUPPORT 
#elif defined(__BTMTK__)
//#define RMMI_MAX_CHANNEL_NUMBER 5 //one physical uart RMMI_SRC, two SPP, one DUN, and one HF 
										/*1 + 2 + 1 + 1 = 5*/
#define RMMI_MAX_CHANNEL_NUMBER 1+VIRTUAL_PORTS_NUM /*one physical uart RMMI_SRC + virtual port for BT*/
#else
#define RMMI_MAX_CHANNEL_NUMBER	1   
#endif


enum
{
   MAX_MULTIPLE_CMD_INFO_LEN  = 40,
   MAX_SINGLE_CMD_INFO_LEN    = 700,
   MAX_PRE_ALLOCATED_BASIC_CMD_STRUCT_NODES  =  3

};

typedef enum
{
    RMMI_NONE_PRESENT = 0,
    RMMI_EXTENDED_COMMAND_PRESENT,
    RMMI_BASIC_COMMAND_PRESENT,
    RMMI_WRONG_PREV_COMMAND,
    RMMI_EXECUTION_COMMAND_PRESENT
} rmmi_cmd_present_enum;

typedef enum
{
   RMMI_DISABLE_REPORT = 0,
   RMMI_ENABLE_REPORT

} rmmi_report_mode_enum;

typedef enum
{
   RMMI_DISABLE_NW_REG_REPORT,
   RMMI_ENABLE_NW_REG_REPORT,
   RMMI_ENABLE_LOC_REPORT
} rmmi_nw_reg_report_mode_enum;


typedef enum
{
   RMMI_ECHO_OFF,
   RMMI_ECHO_ON
} rmmi_cmd_echo_enum;


typedef enum
{
   RMMI_SUPPRESS_OFF,
   RMMI_SUPRESS_ON
} rmmi_result_code_suppress_enum;


typedef enum
{
   RMMI_NUM_PARTIAL_HEAD_TAIL,
   RMMI_VERBOSE_FULL_HEAD_TAIL
} rmmi_result_code_format;

typedef enum
{
   RMMI_SIMPLE_ERROR,
   RMMI_NUMERIC_ERROR,
   RMMI_TEXT_ERROR
} rmmi_error_report_mode_enum;


typedef enum
{
   RMMI_INVALID_CMD_TYPE = 0,
   RMMI_PREV_CMD,
   RMMI_BASIC_CMD,
   RMMI_EXTENDED_CMD,
   RMMI_CUSTOMER_CMD
} rmmi_cmd_type_enum;

typedef enum
{
   RMMI_WRONG_MODE,
   RMMI_SET_OR_EXECUTE_MODE,
   RMMI_READ_MODE,
   RMMI_TEST_MODE,
   RMMI_ACTIVE_MODE
} rmmi_cmd_mode_enum;

typedef enum
{
   RMMI_CHSET_IRA,
   RMMI_CHSET_HEX,
   RMMI_CHSET_GSM,
   RMMI_CHSET_PCCP437,
   RMMI_CHSET_PCDN,
   RMMI_CHSET_88591,
   RMMI_CHSET_UCS2,
#ifdef __PHB_0x81_SUPPORT__
   RMMI_CHSET_UCS2_0X81,
#endif /*__PHB_0x81_SUPPORT__*/
   RMMI_CHSET_TOTAL_NUM			        		
} rmmi_chset_enum;

typedef enum
{
   RMMI_PLMN_LONG_ALPHA,
   RMMI_PLMN_SHORT_ALPHA,
   RMMI_PLMN_NUMERIC

} rmmi_plmn_format_enum;




typedef enum
{
   RMMI_NO_CMD,
   RMMI_CMD_ATA,
   RMMI_CMD_ATE,
   RMMI_CMD_ATH,
   RMMI_CMD_ATI,
   RMMI_CMD_ATL,
   RMMI_CMD_ATO,
   RMMI_CMD_ATQ,
   RMMI_CMD_ATS0,
   RMMI_CMD_ATS3,
   RMMI_CMD_ATS4,
   RMMI_CMD_ATS5,
   RMMI_CMD_ATS6,
   RMMI_CMD_ATS7,
   RMMI_CMD_ATS8,
   RMMI_CMD_ATS10,
   RMMI_CMD_ATV,
   RMMI_CMD_ATX,
   RMMI_CMD_ATZ,
   RMMI_CMD_ATAMPC,
   RMMI_CMD_ATAMPD
} rmmi_basic_cmd_id_enum;


typedef enum
{
   RMMI_RCODE_OK,
   RMMI_RCODE_CONNECT,
   RMMI_RCODE_RING,
   RMMI_RCODE_NO_CARRIER,
   RMMI_RCODE_ERROR,
   RMMI_RCODE_BUSY = 7   
} rmmi_rsp_type_enum;


typedef enum
{
   RMMI_SPACE                 = ' ',
   RMMI_EQUAL                 = '=',
   RMMI_COMMA                 = ',',
   RMMI_SEMICOLON             = ';',
   RMMI_COLON                 = ':',
   RMMI_AT                    = '@',
   RMMI_HAT                   = '^',
   RMMI_DOUBLE_QUOTE          = '"',
   RMMI_QUESTION_MARK         = '?',
   RMMI_EXCLAMATION_MARK      = '!',
   RMMI_FORWARD_SLASH         = '/',
   RMMI_L_ANGLE_BRACKET       = '<',
   RMMI_R_ANGLE_BRACKET       = '>',
   RMMI_L_SQ_BRACKET          = '[',
   RMMI_R_SQ_BRACKET          = ']',
   RMMI_L_CURLY_BRACKET		  = '{',
   RMMI_R_CURLY_BRACKET		  = '}',   
   RMMI_CHAR_STAR             = '*',
   RMMI_CHAR_POUND            = '#',
   RMMI_CHAR_AMPSAND          = '&',
   RMMI_CHAR_PERCENT          = '%',
   RMMI_CHAR_PLUS             = '+',
   RMMI_CHAR_MINUS            = '-',
   RMMI_CHAR_DOT              = '.',
   RMMI_CHAR_ULINE				='_',
   RMMI_CHAR_TILDE           = '~',
   RMMI_CHAR_REVERSE_SOLIDUS  = '\\',
   RMMI_CHAR_VERTICAL_LINE  = '|',
   RMMI_END_OF_STRING_CHAR    = '\0',
   RMMI_CHAR_0                = '0',
   RMMI_CHAR_1                = '1',
   RMMI_CHAR_2                = '2',
   RMMI_CHAR_3                = '3',
   RMMI_CHAR_4                = '4',
   RMMI_CHAR_5                = '5',
   RMMI_CHAR_6                = '6',
   RMMI_CHAR_7                = '7',
   RMMI_CHAR_8                = '8',
   RMMI_CHAR_9                = '9',
   RMMI_CHAR_A                = 'A',
   RMMI_CHAR_B                = 'B',
   RMMI_CHAR_C                = 'C',
   RMMI_CHAR_D                = 'D',
   RMMI_CHAR_E                = 'E',
   RMMI_CHAR_F                = 'F',
   RMMI_CHAR_G                = 'G',
   RMMI_CHAR_H                = 'H',
   RMMI_CHAR_I                = 'I',
   RMMI_CHAR_J                = 'J',
   RMMI_CHAR_K                = 'K',
   RMMI_CHAR_L                = 'L',
   RMMI_CHAR_M                = 'M',
   RMMI_CHAR_N                = 'N',
   RMMI_CHAR_O                = 'O',
   RMMI_CHAR_P                = 'P',
   RMMI_CHAR_Q                = 'Q',
   RMMI_CHAR_R                = 'R',
   RMMI_CHAR_S                = 'S',
   RMMI_CHAR_T                = 'T',
   RMMI_CHAR_U                = 'U',
   RMMI_CHAR_V                = 'V',
   RMMI_CHAR_W                = 'W',
   RMMI_CHAR_X                = 'X',
   RMMI_CHAR_Y                = 'Y',
   RMMI_CHAR_Z                = 'Z',
   rmmi_char_a                = 'a',
   rmmi_char_b                = 'b',
   rmmi_char_c                = 'c',
   rmmi_char_d                = 'd',
   rmmi_char_e                = 'e',
   rmmi_char_f                = 'f',
   rmmi_char_g                = 'g',
   rmmi_char_h                = 'h',
   rmmi_char_i                = 'i',
   rmmi_char_j                = 'j',
   rmmi_char_k                = 'k',
   rmmi_char_l                = 'l',
   rmmi_char_m                = 'm',
   rmmi_char_n                = 'n',
   rmmi_char_o                = 'o',
   rmmi_char_p                = 'p',
   rmmi_char_q                = 'q',
   rmmi_char_r                = 'r',
   rmmi_char_s                = 's',
   rmmi_char_t                = 't',
   rmmi_char_u                = 'u',
   rmmi_char_v                = 'v',
   rmmi_char_w                = 'w',
   rmmi_char_x                = 'x',
   rmmi_char_y                = 'y',
   rmmi_char_z                = 'z'
} rmmi_char_enum;


typedef enum
{
   /* 07.07 Sec 9.2.1 */
   RMMI_ERR_PHONE_FAILURE,
   OPERATION_NOT_ALLOWED_ERR=3,
   RMMI_ERR_OPERATION_NOT_SUPPORTED = 4,
   PH_SIM_PIN_REQUIRED = 5,
   SIM_NOT_INSERTED = 10,
   SIM_PIN_REQUIRED = 11,
   SIM_PUK_REQUIRED = 12,
   SIM_FAILURE = 13,
   SIM_BUSY = 14,
   SIM_WRONG = 15,
   INCORRECT_PASSWD = 16,
   SIM_PIN2_REQUIRED = 17,
   SIM_PUK2_REQUIRED = 18,
   RMMI_ERR_MEM_FULL = 20,
   RMMI_ERR_INVALID_INDEX = 21,
   RMMI_ERR_NO_FOUND=22,
   TEXT_ERRSTRING_TOO_LONG_ERR=24,
   INVALID_CHARACTERS_IN_TEXT_ERRSTRING_ERR=25,
   INVALID_CHARACTERS_IN_DIAL_ERRSTRING_ERR=27,
   NO_NW_SERVICE = 30,
   RMMI_ERR_NETWORK_TIMEOUT = 31,
   RMMI_ERR_NETWORK_NOT_ALLOWED = 32,
   RMMI_ERR_NW_PERSON_PIN_REQUIRED = 40,
   RMMI_ERR_NW_PERSON_PUK_REQUIRED = 41,
   RMMI_ERR_NW_SUB_PERSON_PIN_REQUIRED = 42,
   RMMI_ERR_NW_SUB_PERSON_PUK_REQUIRED = 43,
   RMMI_ERR_SP_PERSON_PIN_REQUIRED = 44,
   RMMI_ERR_SP_PERSON_PUK_REQUIRED = 45,
   RMMI_ERR_CORP_PERSON_PIN_REQUIRED = 46,
   RMMI_ERR_CORP_PERSON_PUK_REQUIRED = 47,   
   RMMI_ERR_UNKNOWN = 100,

   RMMI_ERR_ILLEGAL_MS = 103,
   RMMI_ERR_ILLEGAL_ME = 106,
   RMMI_ERR_GPRS_NOT_ALLOWED = 107,
   RMMI_ERR_PLMN_NOT_ALLOWED = 111,
   RMMI_ERR_LA_NOT_ALLOWED =112,
   RMMI_ERR_ROAMING_AREA_NOT_ALLOWED = 113,
   RMMI_ERR_SERV_OPTION_NOT_SUPPORTED = 132,
   RMMI_ERR_REQ_SERV_OPTION_NOT_SUBSCRIBED = 133,
   RMMI_ERR_SERV_OPTION_TEMP_OUT_OF_ORDER = 134,
   RMMI_ERR_GPRS_UNSPECIFIED_ERROR = 148,
   RMMI_ERR_PDP_AUTH_FAIL = 149,
   RMMI_ERR_INVALID_MOBILE_CLASS = 150,   

   /* following are proprietary error cause : the cause below WON'T be showed as +CME ERROR. */
   RMMI_ERR_COMMAND_CONFLICT = 302,   //same as operation not allowed in 07.05 Sec 3.2.5
   										// will be convert to +CME ERROR: 3  or +CMS ERROR: 302
   RMMI_NO_ERR = 600,

   /* following: error is related to syntax, invalid parameters..*/
   /* according to spec 07.07 Sec 9.1, only "ERROR" will be returned to TE side */
   RMMI_ERR_UNRECOGNIZED_CMD = 601,
   RMMI_ERR_RETURN_ERROR = 602,
   RMMI_ERR_SYNTEX_ERROR = 603,
   RMMI_ERR_UNSPECIFIED = 604,		//unspecified parsing error
   RMMI_ERR_DATA_TRANSFER_ALREADY = 605,
   RMMI_ERR_ACTION_ALREADY = 606,
   RMMI_ERR_NOT_AT_CMD = 607,
   RMMI_ERR_MULTI_CMD_TOO_LONG = 608,
   RMMI_ERR_ABORT_COPS = 609,
   RMMI_ERR_NO_CALL_DISC = 610
} rmmi_err_id_enum;

typedef enum
{
   FAC_NOT_SUPPORTED,
   SS_FAC_BEGIN = L4_BAOC,
   SS_FAC_END = L4_BIC,
#ifdef __MOD_SMU__
   SIM_FAC_BEGIN = TYPE_CHV1,          /*need to add sim sec type*/
   SIM_FAC_END = TYPE_CP
#endif /* __MOD_SMU__ */
} rmmi_clck_fac_enum;

typedef enum
{
   CLIR_INVOKE,
   CLIR_SUPPRESS,
   CLIR_AUTO
} rmmi_clir_enum;

typedef enum
{
   CVMS_PLAY = 1,
   CVMS_DELETE,
   CVMS_APPEND,
   CVMS_RECORD,
   CVMS_RESUME,
   CVMS_STOP,
   CVMS_PAUSE,
   CVMS_ABORT

} rmmi_cvms_mode_enum;

typedef enum
{
   RMMI_PLAY = 1,
   RMMI_STOP,
   RMMI_PAUSE,
   RMMI_RESUME


} rmmi_audio_mode_enum;

typedef enum
{
   CCBS_Interrotage = 14,
   CCBS_EarseCCEntry = 77


} rmmi_ccbs_opcode_enum;

typedef enum
{
   RMMI_FS_OPEN,
   RMMI_FS_CLOSE,
   RMMI_FS_READ,
   RMMI_FS_WRITE,
   RMMI_FS_DELETE,
   RMMI_FS_DIR,
   RMMI_FS_CREATEDIR,
   RMMI_FS_DELETEDIR,
   RMMI_FS_RENAME
} rmmi_fs_opcode_enum;

typedef enum
{
	CSSI_CFU_ACTIVE,
	CSSI_CFC_ACTIVE,
	CSSI_CALL_FORWARDED,
	CSSI_CALL_WAITING,
	CSSI_CUG_CALL,
	CSSI_OUTGOING_BARRED,
	CSSI_INCOMING_BARRED,
	CSSI_CLIR_REJECTED,
	CSSI_CALL_DEFLECTED
} rmmi_cssi_enum; //refer to 07.07 +CSSN

typedef enum
{
	CSSU_FORWARDED_CALL,
	CSSU_CUG_CALL,
	CSSU_CALL_HOLD,
	CSSU_CALL_RETRIEVED,
	CSSU_MPTY_CALL,
	CSSU_HOLDCALL_RELEASED,
	CSSU_FORWARD_CHECK_SS,
	CSSU_ECT_ALERTING,
	CSSU_ECT_ACTIVE,
	CSSU_DEFLECTED_CALL,
	CSSU_INCOMING_FORWARDED
}rmmi_cssu_enum; //refer to 07.07 +CSSN

/* mtk00714 add on 2004/03/02 */
/* first 10 items (except GPRS_REQ) 
   should be consistant with "l4ccsm_cc_call_mode_enum" */
typedef enum
{
   RMMI_CRING_VOICE,
   RMMI_CRING_DATA,
   RMMI_CRING_FAX,
   RMMI_CRING_VOICE_DATA,
   RMMI_CRING_ALT_VOICE_DATA,
   RMMI_CRING_ALT_VOICE_FAX,
   RMMI_CRING_DATA_VOICE,
   RMMI_CRING_ALT_DATA_VOICE,
   RMMI_CRING_ALT_FAX_VOICE,
   RMMI_CRING_UNKNOWN_TYPE,
   RMMI_CRING_GPRS
} rmmi_cring_type_enum; 

typedef enum
{
   RMMI_DCS_DEFAULT        = 0x00, /* GSM 7-bit */
   RMMI_DCS_8BIT           = 0x04, /* 8-bit */
   RMMI_DCS_UCS2           = 0x08  /* UCS2 */   
} 
rmmi_dcs_enum;

typedef enum
{
   RMMI_PARSE_OK,
   RMMI_PARSE_ERROR, //out of range
   RMMI_PARSE_NOT_FOUND,
   RMMI_PARSE_TEXT_TOO_LONG
} rmmi_validator_cause_enum;

typedef enum {
   RMMI_PHB_NONE,
   RMMI_PHB_SM,
   RMMI_PHB_ME,
   RMMI_PHB_FD,
   RMMI_PHB_LD,
   RMMI_PHB_MC,
   RMMI_PHB_RC,
   RMMI_PHB_MT
} rmmi_phb_type_enum;

typedef enum {
   RMMI_EIND_SMS_READY_BIT,
   RMMI_EIND_PHB_READY_BIT = 1,
   RMMI_EIND_AT_READY_BIT = 7 
} rmmi_eind_bit_enum;

typedef enum
{
   RMMI_IMEI_NO_ACTION = 0,
   RMMI_IMEI_READ,
   RMMI_IMEI_WRITE,
   RMMI_IMEI_2_WRITE,
   RMMI_SVN_READ,
   RMMI_SVN_WRITE
} rmmi_imei_action_enum;

/* battchg    1 */
/* signal     2 */
/* service    3 */
/* message    4 */
/* call       5 */
/* roam       6 */
/* smsfull    7 */
/* call_setup 8 */

#if defined( __BTMTK__)
//defined later
typedef enum
{
   RMMI_CIND_BEGIN = 0,
  RMMI_CIND_SERVICE,
   RMMI_CIND_CALL,
   RMMI_CIND_CALLSETUP,
   RMMI_CIND_CALLHELD,
   RMMI_CIND_BATTCHG,
   RMMI_CIND_SIGNAL,
   RMMI_CIND_ROAM,
   RMMI_CIND_END
} rmmi_cind_enum;
#else
typedef enum
{
   RMMI_CIND_BEGIN = 0,
   RMMI_CIND_BATTCHG,
   RMMI_CIND_SIGNAL,
   RMMI_CIND_SERVICE,
   RMMI_CIND_MESSAGE,
   RMMI_CIND_CALL,
   RMMI_CIND_ROAM,
   RMMI_CIND_SMSFULL,
   RMMI_CIND_CALLSETUP,
   RMMI_CIND_END
} rmmi_cind_enum;
#endif

typedef enum
{
   RMMI_CIND_CSUP_NONE = 0,
   RMMI_CIND_CSUP_INCOMING,
   RMMI_CIND_CSUP_OUTGOING,
   RMMI_CIND_CSUP_ALERT,
   RMMI_CIND_CSU_PEND
} rmmi_cind_callsetup;

typedef enum
{
   RMMI_CIND_CC_NONE = 0,
   RMMI_CIND_CC_ACTIVE = 1
 } rmmi_cind_call ;

typedef enum
{
   RMMI_CIND_HELD_NONE = 0,
   RMMI_CIND_HELD_ACTIVE_HOLD = 1,
   RMMI_CIND_HELD_HOLD = 2
 } rmmi_cind_callheld;

/*
typedef enum
{
   	RMMI_CCSR_IDLE,
   	RMMI_CCSR_CALLING,
   	RMMI_CCSR_CONNECTING,
   	RMMI_CCSR_ACTIVE,
   	RMMI_CCSR_HOLD,
   	RMMI_CCSR_WAITING,
   	RMMI_CCSR_ALERTING,
   	RMMI_CCSR_BUSY

} rmmi_ccsr_rsp_code_enum;

*/

typedef enum
{
   RMMI_EADP_NO_ACTION = 0,
   RMMI_EADP_GET,
   RMMI_EADP_SET
} rmmi_eadp_action_enum;

/*For VoIP, call management is controlled by MMI*/
typedef enum
{
	RMMI_CM_ATD = 0,
	RMMI_CM_ATH,
	RMMI_CM_ATA,
	RMMI_CM_CHLD,
	RMMI_CM_BLDN

}rmmi_cm_action_enum; 

//For VOIP 2.0  mtk01616_070707
typedef enum
{
	RMMI_UCM_ATD = 0,
	RMMI_UCM_ATH,
	RMMI_UCM_ATA,
	RMMI_UCM_BLDN,
	RMMI_UCM_CHLD,
	RMMI_UCM_CHUP,
	RMMI_UCM_BLDN_2,//BLDN from SIM2
	RMMI_UCM_MEM_DIAL, //mem dial from SIM1
	RMMI_UCM_MEM_DIAL_2	 //mem dial from SIM2
}rmmi_ucm_action_enum; 

typedef enum{
	RMMI_UCM_CAUSE_NONE=0,
	RMMI_UCM_CAUSE_ATD_NOT_ALLOWED,
	RMMI_UCM_CAUSE_ATA_NOT_ALLOWED,
	RMMI_UCM_CAUSE_ATH_NOT_ALLOWED,		
	RMMI_UCM_CAUSE_CHLD_NOT_ALLOWED,		
	RMMI_UCM_CAUSE_NO_CALL_TO_ANSWER, //specific cause for ATA
	RMMI_UCM_CAUSE_NO_CALL_TO_HANGUP, //specific cause  for ATH   
	RMMI_UCM_CAUSE_NO_CALL_TO_HOLD, //specific cause  for CHLD   		
	RMMI_UCM_CAUSE_NO_CALL_TO_REL, //specific cause for CHLD
	RMMI_UCM_CAUSE_NO_CALL_TO_ECT, //specific cause for CHLD
	RMMI_UCM_CAUSE_NO_CALL_TO_CONFERENCE, // specific cause for CHLD   		
	RMMI_UCM_CAUSE_INVALID_CALLID, //specific cause for CHLD
	RMMI_UCM_CAUSE_NO_NUM_EXIST //specific cause for memory dial or bldn when number not exist ( BQB expect return "ERROR")	
}rmmi_ucm_cause_enum;

typedef enum{
	RMMI_UCM_RCODE_OK,
	RMMI_UCM_RCODE_CONNECT,
	RMMI_UCM_RCODE_RING,
	RMMI_UCM_RCODE_NO_CARRIER,
	RMMI_UCM_RCODE_ERROR,
	RMMI_UCM_RCODE_CCWA
}rmmi_rcode_type_enum;

/*for +EMMISTR proprietary command*/
typedef enum
{
	RMMI_EMMISTR_DISABLE = 0,
	RMMI_EMMISTR_ENABLE,
	RMMI_EMMISTR_DATA_FROM_MMI

}rmmi_emmistr_action_enum; 

#endif /* rmmi_common_enum.h */


