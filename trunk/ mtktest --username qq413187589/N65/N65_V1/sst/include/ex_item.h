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
 *   ex_item.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *	Header file for exception handling
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _EX_ITEM_H
#define _EX_ITEM_H


/*******************************************************************************
 * Enum Type Definition
 *******************************************************************************/

typedef enum
{
    Healthy = 0,
    InternalSRAMCorrupted = 1,
    SystemStackCorrupted = 2,
    TaskStackCorrupted = 3,
    HISRStackCorrupted = 4,
    VectorTableCorrupted = 5
} EX_DIAGNOSIS_T;


/*******************************************************************************
 * Data Structure Definition - Common
 *******************************************************************************/

#define EX_STACK_DUMP_LEN 10
#define EX_QUEUE_TRACK 20
#define EX_UNIT_NAME_LEN 8
#define EX_TIMING_CHECK_LEN 6

/* Exception header, used to track the exception type (4Bytes) */
typedef struct ex_exception_record_header_t
{
    exception_type ex_type;
    kal_uint8 ex_nvram;
    kal_uint16 ex_serial_num;
} EX_HEADER_T;

/* Duplicate structure definition to meet different platform requirement */
typedef struct _ex_rtc_struct
{
    kal_uint8 rtc_sec;    /* seconds after the minute */
    kal_uint8 rtc_min;    /* minutes after the hour */
    kal_uint8 rtc_hour;   /* hours after the midnight */
    kal_uint8 rtc_day;    /* day of the month */
    kal_uint8 rtc_mon;    /* months */
    kal_uint8 rtc_wday;   /* days in a week */
    kal_uint8 rtc_year;   /* years */
    kal_uint8 rtc_pad;    /* Padding */
} ex_rtc_struct;

/* Environment information */
typedef struct ex_environment_info_t
{
    boot_mode_type boot_mode;
    ex_rtc_struct rtc;
    kal_char execution_unit[EX_UNIT_NAME_LEN];
    kal_uint8 status;
    kal_uint8 pad[2];
    kal_uint32 stack_ptr;
    kal_uint32 stack_dump[EX_STACK_DUMP_LEN];
    kal_uint16 ext_queue_pending_cnt;
    kal_uint32 ext_queue_pending[EX_QUEUE_TRACK];
    kal_uint32 interrupt_mask[2];
    kal_uint32 processing_lisr;
    kal_uint32 lr;
} EX_ENVINFO_T;

/* Diagnosis information  */
typedef struct ex_diagnosis_info_t
{
    EX_DIAGNOSIS_T diagnosis;
    kal_char owner[EX_UNIT_NAME_LEN];
    kal_uint8 pad[3];
    kal_uint32 timing_check[EX_TIMING_CHECK_LEN];
} EX_DIAGNOSISINFO_T;


/*******************************************************************************
 * Constant Definition - Common
 *******************************************************************************/

#define EX_LOG_SIZE 512
#define EX_HEADER_SIZE sizeof(EX_HEADER_T)
#define EX_SWVER_LEN 12
#define EX_ENVINFO_SIZE sizeof(EX_ENVINFO_T)
#define EX_DIAGINFO_SIZE sizeof(EX_DIAGNOSISINFO_T)
#define EX_GUARD_LEN 4
#define EX_FORCEMEMORYDUMP 0x26409001
#define TOTAL_EXPTR_SIZE EX_LOG_SIZE


/*******************************************************************************
 * Data Structure Definition - Fatal Error in general
 *******************************************************************************/

#define EX_FATALERR_DESCRIPTION_PARAM_LEN 16
#define EX_FATALERR_ANALYSIS_PARAM_LEN 48
#define EX_FATALERR_GUIDELINE_PARAM_LEN 16

/* Special for Fatal Error only! (100Bytes) */
typedef struct ex_fatalerror_code_t
{
    kal_uint32 code1;
    kal_uint32 code2;
} EX_FATALERR_CODE_T;

typedef struct ex_description_t
{
    kal_uint32 trace;
    kal_uint8 param[EX_FATALERR_DESCRIPTION_PARAM_LEN];
} EX_DESCRIPTION_T;

typedef struct ex_analysis_t
{
    kal_uint32 trace;
    kal_uint8 param[EX_FATALERR_ANALYSIS_PARAM_LEN];
} EX_ANALYSIS_T;

typedef struct ex_guideline_t
{
    kal_uint32 trace;
    kal_uint8 param[EX_FATALERR_GUIDELINE_PARAM_LEN];
} EX_GUIDELINE_T;


/*******************************************************************************
 * Data Structure Definition - Fatal Error extended
 *******************************************************************************/

typedef struct
{
    kal_char ex_his_owner[8];   /* control buffer owner */
    kal_char ex_his_source[16]; /* source file */
    kal_uint32 ex_his_line; /* line number */
    kal_uint32 ex_his_count;    /* number of identical entries */
} EX_CTRLBUFF_HISTORY_T;

typedef struct
{
    kal_uint32 ex_buf_RTOS_header1;  /* NUCLEUS overhead 1, 0: allocated, else next pointer */
    kal_uint32 ex_buf_RTOS_header2;  /* NUCLEUS overhead 2, pointer to its control block */
    kal_uint32 ex_buf_KAL_header1; /* KAL overhead 1, header (0xF1F1F1F1) */
    kal_uint32 ex_buf_KAL_header2; /* KAL overhead 2, task ID */
    kal_uint32 ex_buf_KAL_header3; /* KAL overhead 3, pointer to its control block) */
    kal_uint32 ex_buf_poolID;      /* Buffer pointer */
    kal_uint32 ex_buf_KAL_footer1; /* KAL footer: 0xF2F2F2F2 */
    kal_uint32 ex_buf_KAL_footer2; /* KAL footer appended after size requested */
} EX_CTRLBUFF_COMMON_T;

typedef struct
{
    kal_char ex_buf_source[12];  /* Source file name */
    kal_uint32 ex_buf_line;        /* line number */
} EX_CTRLBUFF_OWNER_T;

typedef union
{
    EX_CTRLBUFF_HISTORY_T history;
    EX_CTRLBUFF_COMMON_T common;
} EX_CTRLBUFF_INFO_T;

typedef struct
{
    kal_uint32 ex_ctrlbuf_size; /* control buffer size per entry */
    kal_uint32 ex_ctrlbuf_num;  /* total number of entries */
    EX_CTRLBUFF_INFO_T ex_ctrlbuf_top; /* top occupation history node */
    EX_CTRLBUFF_INFO_T ex_ctrlbuf_second;  /* second occupation history node */
    EX_CTRLBUFF_INFO_T ex_ctrlbuf_third;   /* third occupation history node */
    EX_CTRLBUFF_OWNER_T ex_monitor[3];
    kal_uint32 ex_reserved[2];  /* reserved */
} EX_CTRLBUFF_T;

typedef struct
{
    kal_uint8 ex_q_src_mod;        /* source module ID */
    kal_uint8 ex_q_count;          /* total number of identical message */
    kal_uint16 ex_q_msg_id;         /* message ID */
    kal_uint16 ex_q_cur_mes_no;     /* tatal number of messages left in queue */
    kal_uint16 ex_q_config_entry;   /* total number of entries */
} EX_QUEUE_T;

typedef struct
{
    kal_char ex_task_name[8];       /* task name */
    kal_char ex_task_stack_gp[8];   /* guard pattern:STACK_END */
    kal_uint32 ex_task_cur_status;    /* task current status, eg. RUNNING, READY etc */
    EX_QUEUE_T ex_task_external_q;    /* task external queue */
    EX_QUEUE_T ex_task_internal_q;    /* task internal queue */
    kal_uint32 ex_reserved;           /* reserved */
} EX_TASKINFO_T;

/*******************************************************************************
 * Constant Definition and Exported Type - Fatal Error
 *******************************************************************************/

#define EX_MAX_TASK_DUMP 4

typedef struct ex_fatalerror_t
{
    EX_FATALERR_CODE_T error_code;
    EX_DESCRIPTION_T description;
    EX_ANALYSIS_T analysis;
    EX_GUIDELINE_T guideline;
    union
    {
        EX_CTRLBUFF_T ctrl_buff;
        EX_TASKINFO_T task_info[EX_MAX_TASK_DUMP];
    } info;
} EX_FATALERR_T;


/*******************************************************************************
 * Constant Definition and Exported Type - Assert Failure
 *******************************************************************************/

#define EX_ASSERTFAIL_FILENAME_LEN 24
#define EX_ASSERTFAIL_SIZE EX_ASSERTFAIL_FILENAME_LEN + \
                           sizeof(kal_uint32) * 4 + \
                           EX_GUARD_LEN
#define EX_ASSERTFAIL_DUMP_LEN  EX_LOG_SIZE - (EX_HEADER_SIZE + EX_SWVER_LEN + \
                                EX_ENVINFO_SIZE + EX_DIAGINFO_SIZE + EX_ASSERTFAIL_SIZE)

typedef struct ex_assert_fail_t
{
    kal_char filename[EX_ASSERTFAIL_FILENAME_LEN];
    kal_uint32 linenumber;
    kal_uint32 parameters[3];
    kal_uint8 dump[EX_ASSERTFAIL_DUMP_LEN];
    kal_uint8 guard[EX_GUARD_LEN];
} EX_ASSERTFAIL_T;


/*******************************************************************************
 * Globally Exported Data Structure
 *******************************************************************************/

typedef union
{
    EX_FATALERR_T fatalerr;
    EX_ASSERTFAIL_T assert;
} EX_CONTENT_T;

/* Standard strutcure of an exception log */
typedef struct ex_exception_log_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_SWVER_LEN];
    EX_ENVINFO_T envinfo;
    EX_DIAGNOSISINFO_T diaginfo;
    EX_CONTENT_T content;
} EX_LOG_T;

/* backward compatible structure (for CATCHER only) */
typedef struct ex_assertfail_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_SWVER_LEN];
    EX_ENVINFO_T envinfo;
    EX_DIAGNOSISINFO_T diaginfo;
    EX_ASSERTFAIL_T assert;
} ex_assertfail_record;

/* backward compatible structure (for CATCHER only) */
typedef struct ex_assertdumpextended_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_LOG_SIZE - EX_HEADER_SIZE];
} ex_assertdumpextended_record;

/* backward compatible structure (for CATCHER only) */
typedef struct ex_exception_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_SWVER_LEN];
    EX_ENVINFO_T envinfo;
    EX_DIAGNOSISINFO_T diaginfo;
    EX_FATALERR_CODE_T error_code;
    EX_DESCRIPTION_T description;
    EX_ANALYSIS_T analysis;
    EX_GUIDELINE_T guideline;
    EX_TASKINFO_T task_info[EX_MAX_TASK_DUMP];
} ex_exception_record;

/* backward compatible structure (for CATCHER only) */
typedef struct ex_stackfatalerr_task_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_SWVER_LEN];
    EX_ENVINFO_T envinfo;
    EX_DIAGNOSISINFO_T diaginfo;
    EX_FATALERR_CODE_T error_code;
    EX_DESCRIPTION_T description;
    EX_ANALYSIS_T analysis;
    EX_GUIDELINE_T guideline;
    EX_TASKINFO_T task_info[EX_MAX_TASK_DUMP];
} ex_stackfatalerr_task_record;

/* backward compatible structure (for CATCHER only) */
typedef struct ex_stackfatalerr_ctrlbuf_record_t
{
    EX_HEADER_T header;
    kal_char sw_version[EX_SWVER_LEN];
    EX_ENVINFO_T envinfo;
    EX_DIAGNOSISINFO_T diaginfo;
    EX_FATALERR_CODE_T error_code;
    EX_DESCRIPTION_T description;
    EX_ANALYSIS_T analysis;
    EX_GUIDELINE_T guideline;
    EX_CTRLBUFF_T ctrl_buff;
} ex_stackfatalerr_ctrlbuf_record;

/* parameter to ex_init_log */
typedef struct
{
    exception_type type;
    kal_bool ext;
    kal_uint32 *code1;
    kal_uint32 *code2;
    kal_uint32 e1;
    kal_uint32 e2;
    kal_uint32 e3;
    kal_uint32 interrupt_mask1;
    kal_uint32 interrupt_mask2;
    ASSERT_DUMP_PARAM_T *dump_param;
} EX_INIT_LOG_PARAM_T;


/*******************************************************************************
 * Globally Constant definition
 *******************************************************************************/
#define TIMER_HISR_CORRUPT   "SYSHISR"
#define SYSTEM_STACK_CORRUPT "SYSPOOL"
#define INTSRAM_CODE_CORRUPT "INTSRAM"
#define VECTOR_TABLE_CORRUPT "INTVECT"
#define MED_REG_DUMP_ADDR 0x80600000
#define MED_REG_DUMP_OFFSET 16
#define MED_REG_DUMP_LEN 0xA00
#define MED_REG_DUMP_TOTAL_LEN 0x100000
#define PPP_REG_DUMP_ADDR 0x80190000
#define PPP_REG_DUMP_LEN 0x4C
#define MSDC_REG_DUMP_ADDR 0x802A0000
#define MSDC_REG_DUMP_LEN 0x70
#define SIM_REG_DUMP_ADDR 0x80140000
#define SIM_REG_DUMP_LEN 0x70
#define CHE_REG_DUMP_ADDR 0x80170000
#define CHE_REG_DUMP_LEN 0xD4
#define PDN_REG_DUMP_ADDR 0x80000300
#define PDN_REG_DUMP_LEN 0x14
#define I2C_REG_DUMP_ADDR 0x80070000
#define I2C_REG_DUMP_LEN 0x74
#define LCD_REG_DUMP_ADDR LCD_base
#define LCD_REG_DUMP_LEN 0x124


/*******************************************************************************
 * Globally Exported macro
 *******************************************************************************/

#ifdef __TST_MODULE__
   #define SET_EX_LOG_DESCRIPTION_TRACE(t) \
        do { \
            if (ex_log_ptr->content.fatalerr.description.trace == 0) \
                ex_log_ptr->content.fatalerr.description.trace = t; \
        } while (0)
#else
   #define SET_EX_LOG_DESCRIPTION_TRACE(t)
#endif

#define EX_LOG_DESCRIPTION_PARAM ex_log_ptr->content.fatalerr.description.param

#ifdef __TST_MODULE__
   #define SET_EX_LOG_ANALYSIS_TRACE(t) \
        do { \
            if (ex_log_ptr->content.fatalerr.analysis.trace == 0) \
                ex_log_ptr->content.fatalerr.analysis.trace = t; \
        } while (0)
#else
   #define SET_EX_LOG_ANALYSIS_TRACE(t)
#endif

#define EX_LOG_ANALYSIS_PARAM ex_log_ptr->content.fatalerr.analysis.param

#ifdef __TST_MODULE__
   #define SET_EX_LOG_GUIDELINE_TRACE(t) \
        do { \
            if (ex_log_ptr->content.fatalerr.guideline.trace == 0) \
                ex_log_ptr->content.fatalerr.guideline.trace = t; \
        } while (0)
#else
   #define SET_EX_LOG_GUIDELINE_TRACE(t)
#endif

#define EX_LOG_GUIDELINE_PARAM ex_log_ptr->content.fatalerr.guideline.param


/*******************************************************************************
 * Globally Exported Function Prorotype
 *******************************************************************************/

extern void ex_init_log(EX_INIT_LOG_PARAM_T *param);
extern void ex_save_log(EX_INIT_LOG_PARAM_T *param);
#ifdef __MTK_TARGET__
extern void ex_reset_hw(void);
extern void ex_reboot(void);
#endif  /* __MTK_TARGET__ */
extern void ex_output_log(void);
#ifdef __MTK_TARGET__
extern void ex_query_bbreg_info(kal_uint32 **addr, kal_uint32 *cnt);
#endif  /* __MTK_TARGET__ */

extern kal_int8 ex_init_ctrl_buff_log(kal_uint32 *target_ptr, kal_uint32 code1, kal_uint32 code2);


/*******************************************************************************
 * Globally Exported variables
 *******************************************************************************/

extern kal_uint32 INT_MemoryDumpFlag;
extern EX_LOG_T *ex_log_ptr;

#endif /* _EX_ITEM_H */


