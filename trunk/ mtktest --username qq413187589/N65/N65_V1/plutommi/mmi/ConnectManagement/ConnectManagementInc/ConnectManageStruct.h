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
 * ConnectManageStruct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#ifndef _PIXTEL_CBM_STRUCT_H
#define _PIXTEL_CBM_STRUCT_H

#include "ConnectManageGprot.h"

#define CBM_TIMER_OUT               1000
#define CBM_MAX_BEARER_NUM          20
#define CBM_MAX_PROFILE_NAME_LEN    31
#define CBM_MAX_DATA_SIZE_LEN       31

#define CBM_DATA_UINT_SIZE          1024
#define CBM_DATA_RATE_UINT          " KB/S"
#define CBM_DATA_SIZE_UINT          " KB"
#define CBM_NO_CONNECTION           "No Connection!"

#define CBM_CONNECT_TIME_HOUR       (60*60)
#define CBM_CONNECT_TIME_MINU       60

#define CBM_ADM_MAX_BUFF_SIZE       (sizeof(CBM_Display_context_struct) * 21)

#define CBM_MAX_BEARER_LIST_NUM     20

#define CBM_BEARER_STATUS_MAX_NUM   20

/* Connect type enum */
typedef enum 
{
    CBM_CONNECT_TYPE_LOCAL,
    CBM_CONNECT_TYPE_DAILUP,
    CBM_CONNECT_TYPE_TOTAL
} cbm_connect_type_enum;

/* Connect type enum */
typedef enum 
{
    CBM_CONNECT_STATUS_ACTIVE,
    CBM_CONNECT_STATUS_DEACTIVE,
    CBM_CONNECT_STATUS_TOTAL
} cbm_connect_status_enum;

#define ALWAYS_ASK_MAX_APP_ID_SIZE      255
#define ALWAYS_ASK_MAX_APP_NAME_LEN     32

#define ENCODE_MASK_ALWAYS_ASK          0x02
#define ENCODE_MASK_SIM                 0x01

#define ALWAYS_ASK_MAX_APP_NUM         20

typedef enum 
{
    CBM_SOC_ASK_ACCT_NULL,
    CBM_SOC_ASK_ACCT_IND,
    CBM_SOC_ASK_ACCT_CNF,
    CBM_SOC_ASK_ACCT_TOTAL
} cbm_soc_ask_acct_enum;

/**/
typedef union
{
    kal_uint32 acct_id;
    struct  
    {
        kal_uint8 ori_acct_id;
        kal_uint8 app_id;
        kal_uint8 mask;
        kal_uint8 reverse;
    }acct_mask;
}acct_union_struct; 

typedef struct always_ask_register
{
    kal_uint8 app_id;
    kal_semid always_ask_sem_id;
}always_ask_register_struct;


typedef struct
{
#ifdef __MMI_GPRS_FEATURES__
	U8      apn[100];
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __MMI__WIFI_FEATURES__
	U8      ap_name[16];	
#endif /* __MMI__WIFI_FEATURES__ */
	U8      csd_number[42];
	U8      bearer_type;
	U8      connect_status;
	U32     send_data_size;
	U32     receive_data_size;
	U32     all_data_size;
	float   down_speed;
	float   up_speed;
	U32     connect_time;
	U8      share_num;
}CBM_bearer_detail_context_struct;


typedef struct CBM_Display_context
{
	U32 profile_id;
    S8  profile_name[(CBM_MAX_PROFILE_NAME_LEN + 1) * ENCODING_LENGTH];
    S8  str_data_size[(CBM_MAX_DATA_SIZE_LEN + 1) * ENCODING_LENGTH];
    U8  connect_type;
    U8  dialup_type;
	U8  valid;
	U8  active_status;
	U32 active_dtcnt_id;
	CBM_bearer_detail_context_struct cbm_bearer_detail_info;
}CBM_Display_context_struct;

typedef struct  
{
    U8 valid;
    U8 list_index;
}CBM_bearer_list_index_struct;

typedef struct  
{
    U8 hour;
    U8 minute;
    U8 second;
}CBM_connect_time_struct;

/* for bearer status api */
typedef struct  
{
    FuncPtrBearerStatus bearer_status_callback;
    U32 mod_id;
    U32 acct_id;
    U8  index;
    U8  app_id;
    U8  valid;
}cbm_bearer_status_struct;

/* for always ask api */
typedef struct  
{
    FuncPtrAccountSelectExt always_ask_callback;
    kal_uint32 mod_id;
    kal_uint32 app_id;
    kal_uint8  valid;
    kal_uint16 app_str_id;
}cbm_always_ask_struct;

typedef struct  
{
    U8 valid;
    U8 app_id;
    U8 sim_info;
    module_type mod_id;
}mmi_cbm_soc_ask_acct_queue_struct;

typedef struct  
{
    FuncPtrAccountSelectExt always_ask_callback;
    kal_uint32 mod_id;
    U8 soc_ind_num;
    cbm_soc_ask_acct_enum soc_cnf_flag;
    mmi_cbm_soc_ask_acct_queue_struct soc_ind_queue[ALWAYS_ASK_MAX_APP_NUM];
}mmi_cbm_soc_ask_acct_struct;

typedef struct  
{
    always_ask_register_type_enum register_type;
    kal_uint32 mod_id;
    kal_uint8  app_id;
    FuncPtrAccountSelectExt callback;
}mmi_cbm_app_register_info_struct;

#endif /* _PIXTEL_CBM_STRUCT_H */ 

