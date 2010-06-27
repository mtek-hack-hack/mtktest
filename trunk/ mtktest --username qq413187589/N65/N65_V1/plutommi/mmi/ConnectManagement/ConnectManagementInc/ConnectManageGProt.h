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
 * ConnectManageGProt.h
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DATA_CBM_GPROT_H
#define _DATA_CBM_GPROT_H

typedef enum
{
    CBM_BEARER_STATE_ACTIVATING,
    CBM_BEARER_STATE_ACTIVATED,
    CBM_BEARER_STATE_DEACTIVATING,
    CBM_BEARER_STATE_DEACTIVATED,
    CBM_BEARER_STATE_TOTAL
} mmi_cbm_bearer_state_enum;


/* for bearer status api */
typedef void (*FuncPtrBearerStatus) (mmi_cbm_bearer_state_enum, kal_uint32);

/* for always ask api */
typedef void (*FuncPtrAccountSelectExt) (kal_uint32, kal_bool);

typedef enum
{
    ALWAYS_ASK_SIM_INFO_DEFAULT,
    ALWAYS_ASK_SIM_INFO_SIM1,
    ALWAYS_ASK_SIM_INFO_SIM2,
    ALWAYS_ASK_SIM_INFO_TOTAL
} always_ask_sim_info_enum;

typedef enum
{
    REGISTER_TYPE_CALLBACK,
    REGISTER_TYPE_PRIMITIVE,
    REGISTER_TYPE_TOTAL
} always_ask_register_type_enum;

typedef enum 
{
    MMI_CBM_ENTRY_LIST_SCREEN,
    MMI_CBM_ENTRY_DETAIL_SCREEN,
    MMI_CBM_ENTRY_TOTAL
} mmi_cbm_entry_type_enum;

extern void InitAlwaysAsk(void);
/* for bearer status api */
extern kal_uint8 mmi_cbm_add_bearer_status_notify_hdlr(FuncPtrBearerStatus event_callback, kal_uint32 acct_id);
extern kal_bool mmi_cbm_del_bearer_status_notify_hdlr(kal_uint8 index, kal_uint32 acct_id);

extern kal_uint8 always_ask_register_app_id (kal_uint16 app_str_id);
extern kal_bool always_ask_deregister_app_id (kal_uint8 app_id);
extern kal_bool always_ask_register_acct_select_notify(kal_uint8 app_id, always_ask_register_type_enum register_type, kal_uint32 mod_id, FuncPtrAccountSelectExt callback);
extern kal_bool always_ask_deregister_acct_select_notify(kal_uint8 app_id, always_ask_register_type_enum register_type, kal_uint32 mod_id, FuncPtrAccountSelectExt callback);
extern kal_uint8 always_ask_get_original_id_data_account (kal_uint32 acct_id);
extern kal_uint8 always_ask_get_app_id_data_account(kal_uint32 acct_id);
extern always_ask_sim_info_enum always_ask_get_sim_info_data_account(kal_uint32 acct_id);
extern kal_bool always_ask_is_always_ask_data_account(kal_uint32 acct_id);
extern kal_bool always_ask_decode_data_account_id(kal_uint32 acct_id, always_ask_sim_info_enum *sim_src, kal_uint8 *app_id, kal_bool *always_ask, kal_uint32* ori_acct_id);
extern kal_uint32 always_ask_encode_app_id_data_account_id(kal_uint32 acct_id, kal_uint8 app_id);
extern kal_uint32 always_ask_encode_data_account_id(kal_uint32 acct_id, always_ask_sim_info_enum sim_src, kal_uint8 app_id, kal_bool always_ask);
extern kal_bool always_ask_register_app_check_id(kal_uint8 app_id);
extern kal_bool always_ask_register_get_app_name(kal_uint8 app_id, kal_uint16 *app_str_id);

#endif /* _DATA_CBM_GPROT_H */ 

