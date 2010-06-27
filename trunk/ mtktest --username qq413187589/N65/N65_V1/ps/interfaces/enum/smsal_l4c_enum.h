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
 *	smsal_l4c_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the enumerations which related to interface of
 *   SMSAL and L4C.
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

#ifndef _SMSAL_L4C_ENUM_H
#define _SMSAL_L4C_ENUM_H


typedef enum
{
   SMSAL_NORMAL_INIT,
   SMSAL_PARAM_INIT_ONLY
} smsal_init_type_enum;

typedef enum
{
   /* follows intended for AT commands and MMI */
   SMSAL_REC_UNREAD = 0,         /* received unread */
   SMSAL_REC_READ,               /* received read */
   SMSAL_STO_UNSENT,             /* stored unsent */
   SMSAL_STO_SENT,               /* stored sent */
   
   SMSAL_ALL,                    /* all (only applicable to +CMGL command) 
                                  * not for MMI
                                  */

   /* follows intended for MMI only */   
   SMSAL_INBOX_PARTIAL,          /* parts of inbox messages */
   SMSAL_OUTBOX_PARTIAL,         /* parts of outbox messages */
   SMSAL_STO_DRAFT,              /* stored draft */
   SMSAL_INVALID_STATUS
} smsal_status_enum;


typedef enum
{
   /* follows intended for AT commands and MMI */
   SMSAL_DEL_INDEXED_MSG = 0,    /* delete specified msg */
   SMSAL_DEL_READ_MSG,           /* delete all read msg */
   SMSAL_DEL_READ_SENT_MSG,      /* delete all read/sent msg */
   SMSAL_DEL_READ_MO_MSG,        /* delete all read/mobile-originated msg */
   SMSAL_DEL_ALL_MSG,            /* delete all msg */
   
   /* follows intended only for MMI */
   SMSAL_DEL_INBOX,
   SMSAL_DEL_OUTBOX,
   SMSAL_DEL_BITMAP             /* delete according bitmap */
} smsal_del_flag_enum;

/*
 * message type identifier 
 */
typedef enum
{
   SMSAL_MTI_DELIVER          = 0x00,
   SMSAL_MTI_DELIVER_REPORT   = 0x00,
   SMSAL_MTI_SUBMIT           = 0x01,
   SMSAL_MTI_SUBMIT_REPORT    = 0x01,
   SMSAL_MTI_STATUS_REPORT    = 0x02,
   SMSAL_MTI_COMMAND          = 0x02,
   
   SMSAL_MTI_UNSPECIFIED      = 0x03   /* MMI shall handle this case,
                                        * eg, displaying "does not support", 
                                        * or "cannot display", etc */
} smsal_mti_enum;

typedef enum
{
   SMSAL_VPF_NOT_PRESENT    = 0x00,
   SMSAL_VPF_ENHANCED       = 0x01,
   SMSAL_VPF_RELATIVE       = 0x02,
   SMSAL_VPF_ABSOLUTE       = 0x03

} smsal_vp_format_enum;


/*
 * CNMI destination code
 */
typedef enum
{
   SMSAL_INVALID_DEST = 0,
   SMSAL_TO_LMI,
   SMSAL_TO_RMI
} smsal_nmi_dest_enum;

typedef enum
{
   NOT_SHOW_HEADER = 0,
   SHOW_HEADER
} smsal_show_header_enum;


/* 
 * the difference between SMSAL_SM_PREFER and SMSAL_MT is :
 *
 * SMSAL_SM_PREFER : in at+cpms? , only SIM storage information will be return
 * SMSAL_MT        : .....         both SIM/ME storage information will be return
 */
typedef enum
{
   SMSAL_SM = 0,            /* SIM only   */
   SMSAL_ME = 1,            /* ME only    */     
   SMSAL_SR = 2,            /* status report (currently NOT support) */   
   SMSAL_BM = 3,            /* broadcast     (currently NOT support) */   
   SMSAL_TA = 4,            /* adaptation    (currently NOT support) */    
   SMSAL_SM_PREFER = 5,     /* SIM prefer, try SIM first, then ME */
   SMSAL_ME_PREFER = 6,     /* ME prefer, try ME first, then SIM */        
   SMSAL_MT = 7,            /* any of storages associated with ME (SIM first) */       
   SMSAL_STORAGE_UNSPECIFIED = 7   
      
} smsal_storage_enum;

typedef enum
{
    SMSAL_SM_FIRST = 0x00,
    SMSAL_ME_FIRST = 0x01
} smsal_sms_prefer_order_enum;

typedef enum
{
   SMSAL_PDU_MODE = 0,
   SMSAL_TEXT_MODE,
   NUM_OF_SMSAL_MSG_FORMAT
} smsal_msg_format_enum;

typedef enum
{
   SMSAL_MMS_DISABLE =0,
   SMSAL_MMS_ENABLE_UNTIL_TIMEOUT,
   SMSAL_MMS_ENALBE
} smsal_more_msg_mode_enum;

typedef enum
{
   SMSAL_SERVICE0 = 0,
   SMSAL_SERVICE1
} smsal_service_mode_enum;

typedef enum
{
   EXACTLY_INDEXING,
   NEXT_INDEXING
} smsal_read_type_enum;

typedef enum
{
   SMSAL_SEND_MSG,               
   SMSAL_SEND_CMD           
} smsal_send_type_enum;

/* follow +CGSMS command in 07.07 */
typedef enum
{   
   SMS_GPRS_ONLY = 0,
   SMS_GSM_ONLY,
   SMS_PREFER_GPRS,
   SMS_PREFER_GSM,   
   NUM_OF_SMS_SERVICE_MODE
}sms_bearer_enum;

typedef enum
{
   CNMA_MODE_TEXT_MODE,
   CNMA_MODE_RP_ACK,
   CNMA_MODE_RP_ERROR
} smsal_cnma_mode_enum;

#ifdef SMS_FOR_NEPTUNE
/* This enum is for para_ind in both l4csmsal_set_parameter_req_struct (2 bytes) */
/* and smsal_send_msg_req_struct(1 byte).                                        */
typedef enum
{
   SMSAL_PARA_FO             =   0x01,
   SMSAL_PARA_SCA            =   0x02,
   SMSAL_PARA_PID            =   0x04,
   SMSAL_PARA_DCS            =   0x08,
   SMSAL_PARA_VP             =   0x10,   
   SMSAL_PARA_SUPP_CONCAT    =   0x20,
   SMSAL_PARA_BEARER         =   0x40,
   SMSAL_PARA_DIRECT_DISPLAY =   0x80,
   SMSAL_PARA_PREFER_MEM     = 0x0100,   
   SMSAL_PARA_CBCH_REQ       = 0x0200,   
   SMSAL_PARA_MAILBOX_ADDR   = 0x0400,   
   SMSAL_PARA_PROFILE_NAME   = 0x0800,
   SMSAL_PARA_ALL_CB_LANG    = 0x1000,
   SMSAL_PARA_SAVE_PROFILE   = 0x2000,
   SMSAL_PARA_RESTORE_PROFILE= 0x4000,

   SMSAL_COM_PARA_FO             =   0x0001,
   SMSAL_COM_PARA_BEARER         =   0x0002,
   SMSAL_COM_PARA_PREFER_MEM     =   0x0004,   
   SMSAL_COM_PARA_STATUS_REP     =   0x0008,   
   SMSAL_COM_PARA_REPLY_PATH     =   0x0010,   
   SMSAL_COM_PARA_CBCH_REQ       =   0x0020,   
   SMSAL_COM_PARA_MAILBOX_ADDR   =   0x0040,   
   SMSAL_COM_PARA_ALL_CB_LANG    =   0x0080,
   SMSAL_COM_PARA_RESTORE_PROFILE=   0x0100

} smsal_parameter_enum;

#else
typedef enum
{
   SMSAL_PARA_FO             =   0x01,
   SMSAL_PARA_PID            =   0x02,
   SMSAL_PARA_DCS            =   0x04,
   SMSAL_PARA_VP             =   0x08,   
   SMSAL_PARA_SCA            =   0x10,
   SMSAL_PARA_PROFILE_NAME   =   0x20,
   SMSAL_PARA_SAVE_PROFILE   =   0x40
} smsal_profile_para_enum;

typedef enum
{
   SMSAL_COM_PARA_FO             =   0x0001,
   SMSAL_COM_PARA_BEARER         =   0x0002,
   SMSAL_COM_PARA_PREFER_MEM     =   0x0004,   
   SMSAL_COM_PARA_STATUS_REP     =   0x0008,   
   SMSAL_COM_PARA_REPLY_PATH     =   0x0010,   
   SMSAL_COM_PARA_CBCH_REQ       =   0x0020,   
   SMSAL_COM_PARA_MAILBOX_ADDR   =   0x0040,   
   SMSAL_COM_PARA_ALL_CB_LANG    =   0x0080,
   SMSAL_COM_PARA_RESTORE_PROFILE=   0x0100
} smsal_common_para_enum;
#endif


typedef enum
{
   /* Mailbox */
   SMSAL_LINE_1 = 0,
   SMSAL_LINE_2 = 1,
   SMSAL_MAX_LINES = 2,          

   /* SMS profile parameter */
   SMSAL_PROFILE_1 = 0,
   SMSAL_PROFILE_2 = 1,
   SMSAL_PROFILE_3 = 2,
   SMSAL_PROFILE_4 = 3, /* SMSAL_MAX_PROFILE_NUM (4) */
   SMSAL_PROFILE_NONE = 0xff /* invalid profile ID */
} smsal_dest_no_enum;

typedef enum
{
   /* In current phase, only "Relative" VP is supported */
   
   /* Reply Path NOT request, Status Report NOT request */
   SMSAL_DEFAULT_FO  = 0x11,                       
                     
   /* Reply Path request, Status Report NOT request */                     
   SMSAL_RP_FO       = 0x91,   
   
   /* Reply Path NOT request, Status Report request */                                                          
   SMSAL_SR_FO       = 0x31,   
   
   /* Reply Path request, Status Report request */                                       
   SMSAL_RP_SR_FO    = 0xb1    
} smsal_first_octet_enum;   

typedef enum
{
   SMSAL_DEFAULT_PID = 0x00,   /* Text SMS */
   SMSAL_TELEX_PID   = 0x21,   /* Telex */
   SMSAL_G3_FAX_PID  = 0x22,   /* Group 3 telefax */
   SMSAL_G4_FAX_PID  = 0x23,   /* Group 4 telefax */
   SMSAL_VOICE_PID   = 0x24,   /* Voice Telephone */
   SMSAL_ERMES_PID   = 0x25,   /* ERMES (European Radio Messaging System) */
   SMSAL_PAGING_PID  = 0x26,   /* National Paging system */
   SMSAL_X400_PID    = 0x31,   /* Any public X.400-based message system */
   SMSAL_EMAIL_PID   = 0x32    /* E-mail SMS */
   
} smsal_pid_enum;

typedef enum
{
   SMSAL_DEFAULT_DCS        = 0x00,  /* GSM 7-bit */
   SMSAL_8BIT_DCS           = 0x04,  /* 8-bit */
   SMSAL_UCS2_DCS           = 0x08,  /* UCS2 */  
   SMSAL_RESERVED_DCS       = 0x0c   /* reserved alphabet,
                                        currently, MMI shall display "not support alphabet" 
                                        or "cannot display" when receive dcs indicated this value */ 
} smsal_dcs_enum;


/*
 * This enum is used in SMSAL module internally
 */
typedef enum
{
   SMSAL_GSM7_BIT = 0,    
   SMSAL_EIGHT_BIT,
   SMSAL_UCS2,       
   SMSAL_ALPHABET_UNSPECIFIED       

} smsal_alphabet_enum;

typedef enum
{
   SMSAL_CLASS0 = 0,
   SMSAL_CLASS1,
   SMSAL_CLASS2,
   SMSAL_CLASS3,
   SMSAL_CLASS_UNSPECIFIED,
   
   SMSAL_MW_DISCARD, /* follows are for SMSAL internal use */
   SMSAL_MW_STORE,
   SMSAL_RCM,
   NUM_OF_NMI_MSG_ENUM
} smsal_msg_class_enum;


typedef enum
{
   SMSAL_MSG_TYPE_NORMAL ,
   SMSAL_MSG_TYPE_CLASS0 ,
   SMSAL_MSG_TYPE_UPDATE_ONLY
} smsal_display_type_enum;


/* Enums for Relative format */
typedef enum
{
   SMSAL_VP_1_HR   = 11,   /* 1 hour */
   SMSAL_VP_6_HR   = 71,   /* 6 hours */
   SMSAL_VP_12_HR  = 143,  /* 12 hours */
   SMSAL_VP_24_HR  = 167,  /* 24 hours = 1 day */
   SMSAL_VP_72_HR  = 169,  /* 72 hours = 3 days */
   SMSAL_VP_1_WEEK = 173,  /* 1 week */
   SMSAL_VP_MAX    = 255   /* 63 weeks */
} smsal_vp_enum;

typedef enum
{
   SMSAL_MW_VM = 0,
   SMSAL_MW_FAX,
   SMSAL_MW_EMAIL, 
   SMSAL_MW_OTHER,
   NUM_OF_MSG_WAITING_TYPE
} smsal_msg_waiting_type_enum;

typedef enum
{
   SMSAL_ENQUIRY_CMD = 0,  /* enquiry relating to previously submitted SM */
   SMSAL_CANCEL_SRR_CMD,   /* cancel status report request */
   SMSAL_DEL_CMD,          /* delete previously submitted SM */
   SMSAL_ENABLE_SRR_CMD    /* enable status report request */   
} smsal_cmd_type_enum;

/* TP-Status(TP-ST) in Status Report */
typedef enum
{
   /* 
    * Short message transaction completed 
    */
   ST_COMP_MSG_RECV_BY_SME      = 0x00,  /* Short message received by the SME */
   ST_COMP_MSG_FORWARD_NOT_CONF = 0x01,  /* Short message forwarded by the SC to the SME 
                                            but the SC is unable to confirm deliver */
   ST_COMP_MSG_REPLACE          = 0x02,  /* Short message replaced by the SC */
   
   /* 
    * Temporary error, SC still trying to transfer SM 
    */
   ST_TE1_CONGESTION           = 0x20,  /* Congestion */
   ST_TE1_SME_BUSY             = 0x21,  /* SME busy */
   ST_TE1_NO_RSP_FROM_SME      = 0x22,  /* No response from SME */
   ST_TE1_SERVICE_REJECT       = 0x23,  /* Service rejected */
   ST_TE1_QOS_NOT_AVAIL        = 0x24,  /* Quality of service not available */
   ST_TE1_ERROR_IN_SME         = 0x25,  /* Error in SME */
   
   /* 
    * Permanent error, SC is not making any more transfer attempts 
    */
   ST_PE_REMOTE_PROC_ERROR    = 0x40,  /* Remote procedure error */
   ST_PE_INCOMP_DEST          = 0x41,  /* Incompatible destination */
   ST_PE_CONN_REJ_BY_SME      = 0x42,  /* Connection rejected by SME */
   ST_PE_NOT_OBTAINABLE       = 0x43,  /* Not obtainable */
   ST_PE_QOS_NOT_AVAIL        = 0x44,  /* Quality of service not available */
   ST_PE_NO_INTERWK_AVAIL     = 0x45,  /* No interworking available */
   ST_PE_VP_EXPIRED           = 0x46,  /* SM Validity Period Expired */
   ST_PE_DEL_BY_ORI_SME       = 0x47,  /* SM Deleted by originating SME */
   ST_PE_DEL_BY_SC            = 0x48,  /* SM Deleted by SC Administration */
   ST_PE_NOT_EXIST            = 0x49,  /* SM does not exist */
         
   /* 
    * Temporary error, SC is not making any more transfer attempts
    */
   ST_TE2_CONGESTION           = 0x60,  /* Congestion */
   ST_TE2_SME_BUSY             = 0x61,  /* SME busy */
   ST_TE2_NO_RSP_FROM_SME      = 0x62,  /* No response from SME */
   ST_TE2_SERVICE_REJECT       = 0x63,  /* Service rejected */
   ST_TE2_QOS_NOT_AVAIL        = 0x64,  /* Quality of service not available */
   ST_TE2_ERROR_IN_SME         = 0x65,  /* Error in SME */ 
    
   ST_SERVICE_REJECT           = 0xff   /* all reserved values interpreted as "service reject" */
   
} smsal_st_enum;

typedef enum
{
   SMSAL_CB_MI          = 0x01,
   SMSAL_CB_MIR         = 0x02,
   SMSAL_CB_DCS         = 0x04,
   SMSAL_CB_MI_MASK     = 0x08,
   SMSAL_CB_MIR_MASK    = 0x10,
   SMSAL_CB_DCS_MASK    = 0x20,
   SMSAL_CB_ALL_LANG    = 0x40
} smsal_cb_para_enum;
   
typedef enum
{
   SMSAL_MEM_FULL_NORMAL, /* both SIM and ME are full */
   SMSAL_SM_FULL_ONLY,
   SMSAL_ME_FULL_ONLY
} smsal_mem_full_enum;
 
typedef enum
{
   SMSAL_MEM_EXCEED_NORMAL,
   SMSAL_SM_EXCEED_WITH_CLASS2
} smsal_mem_exceed_enum;

typedef enum
{
   SMSAL_MEM_AVAIL_NORMAL, /* corresponding to SMSAL_MEM_FULL_NORMAL */
                           /* one of storage is avail. it will be sent */
   SMSAL_SM_AVAIL_ONLY,    /* corresponding to SMSAL_SM_FULL_ONLY */
   SMSAL_ME_AVAIL_ONLY     /* corresponding to SMSAL_SM_FULL_ONLY */
} smsal_mem_avail_enum;

typedef enum
{
   SMSAL_COPY_MSG,
   SMSAL_MOVE_MSG
} smsal_copy_action_enum;
 
#endif /* _SMSAL_L4C_ENUM_H */


