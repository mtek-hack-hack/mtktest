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
 * DataAccountGProt.h
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
 *============================================================================
 ****************************************************************************/
#ifndef _DATA_ACCOUNT_GPROT_H
#define _DATA_ACCOUNT_GPROT_H

#include "FrameworkStruct.h"

typedef void (*FuncPtrU32) (U32);

typedef void (*FuncPtrU32Ext) (U32, BOOL);

#ifdef OBIGO_Q03C

#define MAX_MULITI_BEARER_NUM	    2   /*use for data account select screen*/

typedef struct
{
     U8      ref_count;       
     U16    msg_len;
     U16    app_id;             /* app id */
     U16    menu_id;           /* menu id */
     U32    num_id;
     U32    bearer_scope;
     U32    bearer_type[MAX_MULITI_BEARER_NUM];     /* bearer type */
     U32    net_id[MAX_MULITI_BEARER_NUM];
} mmi_ps_dtcnt_list_ind_struct;

      
typedef struct
{
    U8     ref_count;        
    U16   msg_len;
    U8     result;
    U16   app_id;      /* app id */
    U32   num_id;
    U32   bearer_scope;
    U32   bearer_type[MAX_MULITI_BEARER_NUM];
    U32   net_id[MAX_MULITI_BEARER_NUM];
} mmi_ps_dtcnt_list_rsp_struct;
    


typedef enum
{
    DTCNT_LIST_BY_MMS,
    DTCNT_LIST_BY_WAP,
    DTCNT_LIST_BY_APP_OK,
    DTCNT_LIST_BY_NULL
} dtcnt_list_by_app_enum;
#endif /*OBIGO_Q03C*/

typedef enum
{
    DTCNT_BEARER_STATE_INACTIVE,
    DTCNT_BEARER_STATE_INITIALIZED,
    DTCNT_BEARER_STATE_CONNECTED,
    DTCNT_BEARER_STATE_TOTAL
} dtcnt_bearer_state_enum;

typedef enum
{
    DTCNT_SELECT_NO_SIM,
    DTCNT_SELECT_SIM,
    DTCNT_SELECT_NO_ALWAYS_ASK,
    DTCNT_SELECT_ALWAYS_ASK,
    DTCNT_SELECT_END
} dtcnt_select_type_enum;



#define MAX_DATA_ACCOUNT_NAME_LEN            31

#define DATA_ACCOUNT_ALWAYS_ASK     0xFF
#define DATA_ACCOUNT_SIM1                0xFE
#define DATA_ACCOUNT_SIM2                0xFD



#define DATA_ACCOUNT_BEARER_CSD  0x01
#define DATA_ACCOUNT_BEARER_GPRS 0x02
#define DATA_ACCOUNT_BEARER_WIFI 0x04
#define DATA_ACCOUNT_BEARER_ALL        DATA_ACCOUNT_BEARER_CSD | DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI
#define DATA_ACCOUNT_BEARER_PS_ONLY    DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI      /* Packet Switching Bearer only */
#define DATA_ACCOUNT_BEARER_CS_ONLY    DATA_ACCOUNT_BEARER_CSD  /* Circuit Switching Bearer only */
#define DATA_ACCOUNT_BEARER_TOTAL   3

#ifdef OBIGO_Q03C
//#ifdef __CBM_ALWAYS_ASK_FEATURE__
#define DATA_ACCOUNT_BEARER_ALWAYS_ASK 0x10
//#endif /* __CBM_ALWAYS_ASK_FEATURE__ */
#define DATA_ACCOUNT_BEARER_GPRS_CSD 0x08
#define DATA_ACCOUNT_LIST_MAX_BEARER 2
#endif/*OBIGO_Q03C*/

extern void InitDataAccountApp(void);
extern void InitializeDataAccountRecords(void);
extern BOOL mmi_dtcnt_get_apn(U32 account_id, S8 *dest, U8 len);
extern BOOL mmi_dtcnt_get_account_name(U32 account_id, S8 *dest, U8 len);
extern void mmi_dtcnt_select_account(FuncPtrU32 callback, U16 AppMenuID, U8 bearers);
extern void mmi_dtcnt_select_account_ext(FuncPtrU32 callback, U16 AppMenuID, U8 bearers, U32 account_id);
extern U32 mmi_dtcnt_get_first_account_id(U8 bearers);
extern void DataAccountReadyCheck(FuncPtr ready_callback);
extern void EntryDTCNTMain(void);
extern U8 mmi_dtcnt_get_bearer_type(U32 account_id);
extern void mmi_dtcnt_select_account_option(FuncPtrU32 callback, U16 AppMenuID, U8 bearers, dtcnt_select_type_enum sim_info, dtcnt_select_type_enum always_ask);
extern void mmi_dtcnt_select_account_option_ext(FuncPtrU32Ext callback, U16 AppStrID, U16 AppMenuID, U8 bearers, dtcnt_select_type_enum sim_info, dtcnt_select_type_enum always_ask);
#ifdef __MMI_CCA_SUPPORT__
extern void mmi_dtcnt_ota_dm_retrieve_ind(U16 appid, S32 profid);
extern void mmi_dtcnt_ota_dm_update_ind(U16 appid, S32 profid, S32 hconfig);
#endif /* __MMI_CCA_SUPPORT__ */

#ifdef __MMI_GPRS_FEATURES__
extern void InitializeGPRSDataAccountRecords(void);
#endif /* __MMI_GPRS_FEATURES__ */ 

#ifdef __MMI_WLAN_FEATURES__
extern void mmi_wlan_post_init(void);
extern BOOL mmi_wlan_add_event_notify_hdlr(FuncPtrShort event_callback);
extern BOOL mmi_wlan_remove_event_notify_hdlr(FuncPtrShort event_callback);
extern void mmi_wlan_init_highlight_hdlr(void);
extern void mmi_wlan_reset_hw_on(FuncPtr callback);
extern void mmi_wlan_reset_hw_off(FuncPtr callback);
extern void mmi_dtcnt_entry_ipaddr_conflict_ind(void);
extern BOOL mmi_dtcnt_need_ipaddr_conflict_ind(void);
extern BOOL mmi_wlan_get_connected_ap_ssid(S8 *dest, U8 len);
#endif /* __MMI_WLAN_FEATURES__ */ 

#endif /* _DATA_ACCOUNT_GPROT_H */ 

