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
 * DataAccount.c
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
 * removed!
 *
 * removed!
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

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#include "MMI_include.h"
#ifdef __TCPIP__

#include "DataAccountCommon.h"
#include "ProtocolEvents.h"
#include "PhoneBookTypes.h"

#include "abm_soc_enums.h"
#include "abm_util.h"

#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
#include "CentralConfigAgentGProt.h"
#include "CentralConfigAgentDefs.h"
#include "CentralConfigAgentConst.h"
#include "cbfunc.h"

//#ifdef __CBM_CM_FEATURE__
#include "ConnectManageGprot.h"
//#endif

extern void mmi_dm_set_check_function(dm_setting_type_enum type, DMCheckCBFunc func);
#endif /* defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__) */

extern wgui_inline_item wgui_inline_items[];

void (*g_DTCNTReadyCallback) (void) = NULL;

DataAccountNode g_DataAccount[MAX_DATA_ACCOUNT_GSM_LIMIT];
static DataAccountNodeDisplay g_DataAccount_Display;
static DataAccountNodeDisplay g_DataAccount_Display;

BOOL mmi_dtcnt_check_UCS2(U16 *buf, U16 charNum);

#ifdef OBIGO_Q03C
static void mmi_dtcnt_list_callback_csd(U32 index);
static void mmi_dtcnt_list_callback_gprs(U32 index);
#ifdef __MMI_WLAN_FEATURES__
static void mmi_dtcnt_list_callback_wifi(U32 index);
#endif
static void mmi_ps_dtcnt_list_ind_handler(void *info);
static void mmi_dtcnt_send_msg2ps(void);
static void mmi_ps_dtcnt_main_list(void);
static void mmi_dtcnt_list_highlight_hdlr(S32 nIndex);
static void mmi_dtcnt_list_show(void);
static U8 mmi_dtcnt_list_check_app_para(void);
static void mmi_dtcnt_list_by_app_confirm(U16 msg, FuncPtr lskFuncPtr);
static void mmi_dtcnt_list_by_app_confirm_gprs(void);
static void mmi_dtcnt_list_by_app_confirm_csd(void);
static void mmi_dtcnt_list_confirm(void);
static void mmi_dtcnt_list_go_back_gprs(void);
static void mmi_dtcnt_list_back_handler(void);

#define DTCNT_LIST_BEARER_CSD   0
#define DTCNT_LIST_BEARER_GPRS  1
#endif /* OBIGO_Q03C */

#ifdef __MMI_GPRS_FEATURES__

#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
#else
GPRSDataAccountNode g_GPRS_DataAccount[MAX_DATA_ACCOUNT_GPRS_LIMIT];
#endif /* __MMI_OP01_GPRS_DATACFG__ */

#endif /* __MMI_GPRS_FEATURES__ */ 

typedef struct
{
    U8 bearer;
    U8 bearer_enum;
    U16 name;
    FuncPtr func;
} dtcnt_select_op_struct;

#ifdef OBIGO_Q03C
typedef struct 
{
    U16   appid;              /* appid */
    U32   bearer_scrope;     /* bearer type */
    U32   bearer_type[2];
    U16   menu_id;            /* menu id */
    U8    num_id;
    U32  net_id[2];
    U8    sim_info;
    U8    app_id;
    U8    index;
    U8    highlight_csd;
    U8    highlight_gprs;
    U8    highlight_gprs_csd;
    U8    switch_bearer_flag;
    U8    gprs_bearer_flag;
    U8    csd_bearer_flag;
    U8    wifi_bearer_flag;
    U8    always_ask_flag;
    U8    entry_gprs_list_num;
    U8    bearer_list[DTCNT_LIST_BEARER_TOTAL];
    U16   curr_msg;
    FuncPtr curr_lskFuncPtr;
} dtcnt_list_by_app_struct;

dtcnt_list_by_app_struct g_dtcnt_list_cnt;
#endif /* __Q03C */

void mmi_dtcnt_entry_account_select(void);
void mmi_dtcnt_account_select_highlight_hdlr(S32 nIndex);
void mmi_dtcnt_account_select_ok(void);
void mmi_dtcnt_select_account_entry_option(void);
void mmi_dtcnt_csd_prof_back(void);

//#ifdef __MMI_DUAL_SIM__
#define MMI_DATA_ACCOUNT_SIM1  1
#define MMI_DATA_ACCOUNT_SIM2  2
U8 g_sim_info;
U8 g_entry_option_back_flag;
U8 g_bearer_num_flag;
static void mmi_dtcnt_entry_account_select_ext(void);
static void mmi_dtcnt_select_sim1(void);
static void mmi_dtcnt_select_sim2(void);
#ifdef __DUAL_TEST__
void mmi_dtcnt_sim1_settings(void);
void mmi_dtcnt_sim2_settings(void);
void mmi_dtcnt_sim1_settings_handler(void);
void mmi_dtcnt_sim2_settings_handler(void);
U8 g_sim_setting_flag;
#endif /*__DUAL_TEST__ */
//#endif /* __MMI_DUAL_SIM__ */

#ifdef __CBM_ALWAYS_ASK_FEATURE__
#define DTCNT_ALWAYS_ASK_ID     255
static void mmi_dtcnt_list_callback_always_ask(U32 index);
static void mmi_dtcnt_always_ask(void);
extern void mmi_wlan_entry_network_settings_ext(void);
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */

U8 g_entry_option_back_flag;
U8 g_always_ask_screen_del_handler_flag;
static void mmi_dtcnt_select_account_gprs_back(void);
static void mmi_dtcnt_always_ask_cancel(void);

U8 mmi_dtcnt_always_ask_screen_del_handler(void *in_param);

#ifdef __CBM_ALWAYS_ASK_FEATURE__
#define CBM_SCREEN_LIST_INDEX    1
#else
#define CBM_SCREEN_LIST_INDEX    0
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_pre_entry_app_csd_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_pre_entry_app_csd_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DataAccountReadyCheck(EntryAppDTCNTList);
}


#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_pre_entry_app_gprs_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_pre_entry_app_gprs_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DataAccountReadyCheck(EntryGPRSAppDTCNTList);
}
#endif /* __MMI_GPRS_FEATURES__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_app_wlan_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_app_wlan_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_DataAccount_Display.app_callback)
    {
        kal_uint32 id;

        abm_bearer2nw_id(ABM_E_SOCKET_BEARER_WIFI, 0, &id);
        g_DataAccount_Display.app_callback((U16) id);
        g_DataAccount_Display.app_callback = NULL;
    }
}

#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_app_wlan_select_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_app_wlan_select_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_DataAccount_Display.app_call)
    {
        if (g_DataAccount_Display.app_callback)
        {
            kal_uint32 id;

            abm_bearer2nw_id(ABM_E_SOCKET_BEARER_WIFI, 0, &id);
            g_DataAccount_Display.app_callback((U16) id);
            g_DataAccount_Display.app_callback = NULL;
        }
    }
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    else
    {
        mmi_wlan_entry_network_settings_ext();
    }
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */
}
#endif /* __MMI_WLAN_FEATURES__ */


const dtcnt_select_op_struct g_dtcnt_selections[] = 
{
#ifdef __MMI_DUAL_SIM__
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    {DATA_ACCOUNT_ALWAYS_ASK, DATA_ACCOUNT_ALWAYS_ASK, STR_ID_DTCNT_ALWAYS_ASK,
        mmi_dtcnt_always_ask},
#endif /*__CBM_ALWAYS_ASK_FEATURE__*/
    {DATA_ACCOUNT_SIM1, DATA_ACCOUNT_SIM1, STR_ID_DTCNT_SIM1,
    mmi_dtcnt_select_sim1},
    {DATA_ACCOUNT_SIM2, DATA_ACCOUNT_SIM2, STR_ID_DTCNT_SIM2,
    mmi_dtcnt_select_sim2},
#ifdef __MMI_WLAN_FEATURES__
    {DATA_ACCOUNT_BEARER_WIFI, ABM_E_SOCKET_BEARER_WIFI, SERVICES_DATA_CONNECT_WLAN_STRING_ID,
    mmi_dtcnt_app_wlan_select},
#endif /* __MMI_WLAN_FEATURES__ */ 
    {0, 0, 0, NULL}
#else
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    {DATA_ACCOUNT_ALWAYS_ASK, DATA_ACCOUNT_ALWAYS_ASK, STR_ID_DTCNT_ALWAYS_ASK,
        mmi_dtcnt_always_ask},
#endif /*__CBM_ALWAYS_ASK_FEATURE__*/
    {DATA_ACCOUNT_BEARER_CSD, ABM_E_SOCKET_BEARER_GSM_CSD, SERVICES_DATA_CONNECT_GSM_STRING_ID,
     mmi_dtcnt_pre_entry_app_csd_list},
 #ifdef __MMI_GPRS_FEATURES__
    {DATA_ACCOUNT_BEARER_GPRS, ABM_E_SOCKET_BEARER_GSM_GPRS, SERVICES_DATA_CONNECT_GPRS_STRING_ID,
     mmi_dtcnt_pre_entry_app_gprs_list},
 #endif /* __MMI_GPRS_FEATURES__ */ 
 #ifdef __MMI_WLAN_FEATURES__
    {DATA_ACCOUNT_BEARER_WIFI, ABM_E_SOCKET_BEARER_WIFI, SERVICES_DATA_CONNECT_WLAN_STRING_ID,
     mmi_dtcnt_app_wlan_select},
 #endif /* __MMI_WLAN_FEATURES__ */ 
    {0, 0, 0, NULL}
#endif /* __MMI_DUAL_SIM__ */

};

const dtcnt_select_op_struct g_dtcnt_selections_ext_sim[] = 
{
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    {DATA_ACCOUNT_ALWAYS_ASK, DATA_ACCOUNT_ALWAYS_ASK, STR_ID_DTCNT_ALWAYS_ASK,
        mmi_dtcnt_always_ask},
#endif /*__CBM_ALWAYS_ASK_FEATURE__*/
    {DATA_ACCOUNT_SIM1, DATA_ACCOUNT_SIM1, STR_ID_DTCNT_SIM1,
    mmi_dtcnt_select_sim1},
    {DATA_ACCOUNT_SIM2, DATA_ACCOUNT_SIM2, STR_ID_DTCNT_SIM2,
    mmi_dtcnt_select_sim2},
#ifdef __MMI_WLAN_FEATURES__
    {DATA_ACCOUNT_BEARER_WIFI, ABM_E_SOCKET_BEARER_WIFI, SERVICES_DATA_CONNECT_WLAN_STRING_ID,
    mmi_dtcnt_app_wlan_select_ext},
#endif /* __MMI_WLAN_FEATURES__ */ 
    {0, 0, 0, NULL}
};

const dtcnt_select_op_struct g_dtcnt_selections_ext[] = 
{
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    {DATA_ACCOUNT_ALWAYS_ASK, DATA_ACCOUNT_ALWAYS_ASK, STR_ID_DTCNT_ALWAYS_ASK,
    mmi_dtcnt_always_ask},
#endif /*__CBM_ALWAYS_ASK_FEATURE__*/
    {DATA_ACCOUNT_BEARER_CSD, ABM_E_SOCKET_BEARER_GSM_CSD, SERVICES_DATA_CONNECT_GSM_STRING_ID,
    mmi_dtcnt_pre_entry_app_csd_list},
#ifdef __MMI_GPRS_FEATURES__
    {DATA_ACCOUNT_BEARER_GPRS, ABM_E_SOCKET_BEARER_GSM_GPRS, SERVICES_DATA_CONNECT_GPRS_STRING_ID,
    mmi_dtcnt_pre_entry_app_gprs_list},
#endif /* __MMI_GPRS_FEATURES__ */ 
#ifdef __MMI_WLAN_FEATURES__
    {DATA_ACCOUNT_BEARER_WIFI, ABM_E_SOCKET_BEARER_WIFI, SERVICES_DATA_CONNECT_WLAN_STRING_ID,
    mmi_dtcnt_app_wlan_select_ext},
#endif /* __MMI_WLAN_FEATURES__ */ 
    {0, 0, 0, NULL}
};


//#ifdef __MMI_DUAL_SIM__
const dtcnt_select_op_struct g_dtcnt_selections_dual[] = 
{
    {DATA_ACCOUNT_BEARER_CSD, ABM_E_SOCKET_BEARER_GSM_CSD, SERVICES_DATA_CONNECT_GSM_STRING_ID,
        mmi_dtcnt_pre_entry_app_csd_list},
#ifdef __MMI_GPRS_FEATURES__
    {DATA_ACCOUNT_BEARER_GPRS, ABM_E_SOCKET_BEARER_GSM_GPRS, SERVICES_DATA_CONNECT_GPRS_STRING_ID,
    mmi_dtcnt_pre_entry_app_gprs_list},
#endif /* __MMI_GPRS_FEATURES__ */ 
    {0, 0, 0, NULL}
};
//#endif /* __MMI_DUAL_SIM__ */

/* mmi_bootup_is_sim_valid */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_select_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearers     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dtcnt_select_highlight_handler(U32 acct_id, U8 bearers)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 bearer;
    kal_uint8 id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (abm_nw2bearer_id(acct_id, &bearer, &id) == KAL_TRUE)
    {
        if ((bearers & DATA_ACCOUNT_BEARER_CSD) && (bearer == ABM_E_SOCKET_BEARER_GSM_CSD))
        {
            g_DataAccount_Display.CurrAppSelectItem = id;
        }
#ifdef __MMI_GPRS_FEATURES__
        else if((bearers & DATA_ACCOUNT_BEARER_GPRS) && (bearer == ABM_E_SOCKET_BEARER_GSM_GPRS))
        {
            g_DataAccount_Display.GPRSCurrAppSelectItem = id - 1;
        }
#endif /* __MMI_GPRS_FEATURES__ */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_bearer_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearers     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_dtcnt_get_bearer_type(U32 account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 bearer;
    kal_uint8 id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (abm_nw2bearer_id(account_id, &bearer, &id) == KAL_FALSE)
    {
        return 0; /* Invalid account id */
    }

    switch(bearer)
    {
        case ABM_E_SOCKET_BEARER_GSM_CSD:
            return DATA_ACCOUNT_BEARER_CSD;
            
        case ABM_E_SOCKET_BEARER_GSM_GPRS:
            return DATA_ACCOUNT_BEARER_GPRS;
            
        case ABM_E_SOCKET_BEARER_WIFI:
            return DATA_ACCOUNT_BEARER_WIFI;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_first_account_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearers     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_dtcnt_get_first_account_id(U8 bearers)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, account_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; g_dtcnt_selections_ext[i].bearer > 0; i++)
    {
        if (bearers & g_dtcnt_selections_ext[i].bearer)
        {
            /* Special case for GPRS */
            if (g_dtcnt_selections_ext[i].bearer_enum == ABM_E_SOCKET_BEARER_GSM_GPRS)
            {
                if (abm_bearer2nw_id(g_dtcnt_selections_ext[i].bearer_enum, 1, &account_id) == TRUE)
                {
                    return account_id;
                }
            }
            else
            {
                if (abm_bearer2nw_id(g_dtcnt_selections_ext[i].bearer_enum, 0, &account_id) == TRUE)
                {
                    return account_id;
                }
            }
        }
    }
    ASSERT(0);
    return 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_select_account_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 *  AppMenuID       [IN]        
 *  bearers         [IN]        
 *  account_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_select_account_ext(FuncPtrU32 callback, U16 AppMenuID, U8 bearers, U32 account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 bearer;
    kal_uint8 id;
    U8 i, count = 0;
    FuncPtr funcs[DATA_ACCOUNT_BEARER_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_DataAccount_Display.app_callback = callback;
    g_DataAccount_Display.AppMenuID = AppMenuID;
    g_DataAccount_Display.CurrAppMainSelectItem = 0;
    g_DataAccount_Display.CurrAppSelectItem = 0;
#ifdef __MMI_GPRS_FEATURES__
    g_DataAccount_Display.GPRSCurrAppSelectItem = 0;
#endif /* __MMI_GPRS_FEATURES__ */ 
    g_DataAccount_Display.bearers = bearers;

#ifdef __MMI_DUAL_SIM__
    mmi_dtcnt_entry_account_select();
#else
    for (i = 0; g_dtcnt_selections[i].bearer > 0; i++)
    {
        if (bearers & g_dtcnt_selections[i].bearer)
        {
            funcs[count++] = g_dtcnt_selections[i].func;
        }
    }
#ifdef __MMI_WLAN_FEATURES__
    if(count == 1)
    {
        if((mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY) &&
            ((bearers == DATA_ACCOUNT_BEARER_CSD)||(bearers == DATA_ACCOUNT_BEARER_GPRS)))
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_WARNING, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, ERROR_TONE);
            return;
        }
    }
#endif /* __MMI_WLAN_FEATURES__ */
    if (abm_nw2bearer_id(account_id, &bearer, &id) == KAL_TRUE)
    {
        if ((bearers & DATA_ACCOUNT_BEARER_CSD) && (bearer == ABM_E_SOCKET_BEARER_GSM_CSD))
        {
            g_DataAccount_Display.CurrAppSelectItem = id;
        }
#ifdef __MMI_GPRS_FEATURES__
        else if((bearers & DATA_ACCOUNT_BEARER_GPRS) && (bearer == ABM_E_SOCKET_BEARER_GSM_GPRS))
        {
            g_DataAccount_Display.GPRSCurrAppSelectItem = id - 1;
        }
#endif /* __MMI_GPRS_FEATURES__ */ 
    }

    if (count == 1)
    {
        funcs[0] ();
        return;
    }
    mmi_dtcnt_entry_account_select();
#endif /* __MMI_DUAL_SIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_select_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 *  AppMenuID       [IN]        
 *  bearers         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_select_account(FuncPtrU32 callback, U16 AppMenuID, U8 bearers)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_select_account_ext(callback, AppMenuID, bearers, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_apn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  account_id      [IN]        
 *  dest            [OUT]         
 *  len             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_dtcnt_get_apn(U32 account_id, S8 *dest, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPRS_FEATURES__
    kal_uint8 bearer;
    kal_uint8 id;   /* dummy */
    U8 length;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_GPRS_FEATURES__
    return FALSE;
#else
    if(!dest)
    {
        return FALSE;
    }
    
    length = (len < (MAX_GPRS_MMI_APN_LEN+ 1) * ENCODING_LENGTH) ? len : (MAX_GPRS_MMI_APN_LEN + 1) * ENCODING_LENGTH;
        
    if (abm_nw2bearer_id(account_id, &bearer, &id) == KAL_TRUE)
    {
        if(bearer == ABM_E_SOCKET_BEARER_GSM_GPRS)
        {
            mmi_ucs2ncpy(dest, (S8*) g_GPRS_DataAccount[id - 1].APN, length);
            return TRUE;
        }
    }
    memset(dest, 0, len);
    return FALSE;
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_account_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  account_id      [IN]        
 *  dest            [OUT]         
 *  len             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_dtcnt_get_account_name(U32 account_id, S8 *dest, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 bearer;
    kal_uint8 id;   /* dummy */
    U8 length =
        len <
        (MAX_DATA_ACCOUNT_NAME_LEN + 1) * ENCODING_LENGTH ? len : (MAX_DATA_ACCOUNT_NAME_LEN + 1) * ENCODING_LENGTH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!dest)
    {
        return FALSE;
    }
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    account_id = always_ask_get_original_id_data_account(account_id);
    if(account_id == DTCNT_ALWAYS_ASK_ID)
    {
        mmi_ucs2ncpy(dest, GetString(STR_ID_DTCNT_ALWAYS_ASK), length);
        return TRUE;
    }
#endif /*__CBM_ALWAYS_ASK_FEATURE__*/
    
    if (abm_nw2bearer_id(account_id, &bearer, &id) == KAL_TRUE)
    {
        switch (bearer)
        {
            case ABM_E_SOCKET_BEARER_GSM_CSD:
                mmi_ucs2ncpy(dest, (S8*) g_DataAccount[id].DataAccountName, length);
                return TRUE;
#ifdef __MMI_GPRS_FEATURES__
            case ABM_E_SOCKET_BEARER_GSM_GPRS:
                mmi_ucs2ncpy(dest, (S8*) g_GPRS_DataAccount[id - 1].DataAccountName, length);
                return TRUE;
#endif /* __MMI_GPRS_FEATURES__ */ 
#ifdef __MMI_WLAN_FEATURES__
            case ABM_E_SOCKET_BEARER_WIFI:
                mmi_ucs2ncpy(dest, GetString(SERVICES_DATA_CONNECT_WLAN_STRING_ID), length);
                return TRUE;
#endif /* __MMI_WLAN_FEATURES__ */ 
            default:
                memset(dest, 0, len);
                return FALSE;
        }
    }

    memset(dest, 0, len);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_account_select_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_account_select_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.CurrAppMainSelectItem = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_account_select_ok
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_account_select_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_DataAccount_Display.bearer_callbacks[g_DataAccount_Display.CurrAppMainSelectItem] ();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_entry_account_select
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_entry_account_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem = 0;                 /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_MAIN, NULL, mmi_dtcnt_entry_account_select, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_MAIN);

    for (i = 0; g_dtcnt_selections[i].bearer > 0; i++)
    {
#ifdef __CBM_ALWAYS_ASK_FEATURE__
        if(g_dtcnt_selections[i].bearer == DATA_ACCOUNT_ALWAYS_ASK)
        {
            nStrItemList[nNumofItem] = g_dtcnt_selections[i].name;
            g_DataAccount_Display.bearer_callbacks[nNumofItem] = g_dtcnt_selections[i].func;
            nNumofItem++;
        }
        else 
#endif /* __MMI_WLAN_FEATURES__ */
        if (g_DataAccount_Display.bearers & g_dtcnt_selections[i].bearer)
        {
#ifdef __MMI_WLAN_FEATURES__
            if((g_dtcnt_selections[i].bearer == DATA_ACCOUNT_BEARER_WIFI) &&
                (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY))
            {
                continue;
            }
            else if((g_dtcnt_selections[i].bearer != DATA_ACCOUNT_BEARER_WIFI) &&
                (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY))
            {
                continue;
            }
            else 
#endif /* __MMI_WLAN_FEATURES__ */
            {
            nStrItemList[nNumofItem] = g_dtcnt_selections[i].name;
            g_DataAccount_Display.bearer_callbacks[nNumofItem] = g_dtcnt_selections[i].func;
            nNumofItem++;
        }
    }
    }
    if(nNumofItem == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_WARNING, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_DTCNT_MAIN);
        return;
    }
    RegisterHighlightHandler(mmi_dtcnt_account_select_highlight_hdlr);

    ShowCategory52Screen(
        SERVICES_DATA_CONNECT_MAIN_STRING_ID,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_dtcnt_account_select_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_dtcnt_account_select_ok, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_exit_list_hdlr
 * DESCRIPTION
 *  GoBackHistory wrapper for resetting highlight index.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_dtcnt_exit_list_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.CurrSelectItem = 0;
#ifdef __MMI_GPRS_FEATURES__
    g_DataAccount_Display.GPRSCurrSelectItem = 0;
#endif
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  SetDynaDataAccountName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UCS2Name        [?]         
 *  index           [IN]        
 *  void(?)         [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void SetDynaDataAccountName(S8 *UCS2Name, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 LocalBuffer[8];
    S8 StrVal[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(LocalBuffer, "%d", index + 1);
    mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);

    mmi_ucs2cpy((PS8) UCS2Name, (PS8) GetString(STR_ID_DTCNT_NAME));

    mmi_ucs2cat((PS8) UCS2Name, (PS8) StrVal);
}


/*****************************************************************************
 * FUNCTION
 *  InitDataAccountApp
 * DESCRIPTION
 *  Initialize the Data Account App
 *  
 *  This is used to initialized the Data Account application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitDataAccountApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 ImageLocation = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    InitAlwaysAsk();
    
    for (i = 0; i < MAX_DATA_ACCOUNT_GSM_LIMIT; i++)
    {
        memset(&g_DataAccount[i], '\0', sizeof(DataAccountNode));
        g_DataAccount[i].Present = (U8) '\0';
        g_DataAccount[i].iFdcs = 0;
    }
    for (i = 0; i < MAX_INLINE_ITEM_DATA_ACCOUNT_LIST; i++)
    {
        if (i % 2)
        {
            g_DataAccount_Display.IconList[i] = IMG_ID_DTCNT_LSK_OK;
        }
        else
        {
            g_DataAccount_Display.IconList[i] = IMG_ID_DTCNT_AC_NAME + ImageLocation;
            ImageLocation++;
        }
    }
    g_DataAccount_Display.CurrGetIndex = 0;
    g_DataAccount_Display.CurrSelectItem = 0;
    /* micha0112 */
    g_DataAccount_Display.CurrAppSelectItem = 0;

    g_DTCNTReadyCallback = NULL;
    
    /* micha0913 */
#ifdef __MMI_GPRS_FEATURES__
#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
#else
    for (i = 0; i < MAX_DATA_ACCOUNT_GPRS_LIMIT; i++)
#endif /* __MMI_OP01_GPRS_DATACFG__ */
    {
        memset(&g_GPRS_DataAccount[i], '\0', sizeof(GPRSDataAccountNode));
        g_GPRS_DataAccount[i].Present = (U8) '\0';
        g_GPRS_DataAccount[i].iFdcs = 0;
    }

    ImageLocation = 0;
    for (i = 0; i < MAX_INLINE_ITEM_GPRSDATA_ACCOUNT_LIST; i++)
    {
        if (i % 2)
        {
            g_DataAccount_Display.IconList[i] = IMG_ID_DTCNT_LSK_OK;
        }
        else
        {
            g_DataAccount_Display.IconList[i] = IMG_ID_DTCNT_GPRS_AC_NAME + ImageLocation;
            ImageLocation++;
        }
    }
    g_DataAccount_Display.GPRSCurrGetIndex = 0;
    g_DataAccount_Display.GPRSCurrSelectItem = 0;
    /* micha0112 */
    g_DataAccount_Display.GPRSCurrAppSelectItem = 0;
#endif /* __MMI_GPRS_FEATURES__ */ 

#ifdef __MMI_WLAN_FEATURES__
	mmi_wlan_init();
#endif

#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
	mmi_dm_set_check_function(DM_SETTING_TYPE_DATA_ACCOUNT_HTTP, mmi_dtcnt_dm_check);
    mmi_dm_set_check_function(DM_SETTING_TYPE_DATA_ACCOUNT_WAP, mmi_dtcnt_dm_check);
    mmi_dm_set_check_function(DM_SETTING_TYPE_DATA_ACCOUNT_CSD, mmi_dtcnt_dm_check);
#endif /* SYNCML_DM_SUPPORT */
#ifdef OBIGO_Q03C
    SetProtocolEventHandler(mmi_ps_dtcnt_list_ind_handler, MSG_ID_MMI_PS_DTCNT_LIST_IND);
#endif /* OBIGO_Q03C */
#ifdef __DUAL_TEST__
     SetHiliteHandler(MENU_ID_SIM1, mmi_dtcnt_sim1_settings_handler);
     SetHiliteHandler(MENU_ID_SIM2, mmi_dtcnt_sim2_settings_handler);
#endif /* __DUAL_TEST__ */
}

#ifdef __DUAL_TEST__

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_sim1_settings
 * DESCRIPTION
 *  Initialize Data Account Records
 *  
 *  Called from SAT to enter Data Account Main Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_sim1_settings_handler(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   SetLeftSoftkeyFunction(mmi_dtcnt_sim1_settings, KEY_EVENT_UP);
   SetKeyHandler(mmi_dtcnt_sim1_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_sim2_settings_handler
 * DESCRIPTION
 *  Initialize Data Account Records
 *  
 *  Called from SAT to enter Data Account Main Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_sim2_settings_handler(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   SetLeftSoftkeyFunction(mmi_dtcnt_sim2_settings, KEY_EVENT_UP);
   SetKeyHandler(mmi_dtcnt_sim2_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_sim1_settings
 * DESCRIPTION
 *  Initialize Data Account Records
 *  
 *  Called from SAT to enter Data Account Main Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_sim1_settings(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   g_sim_setting_flag = FALSE;
   DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_WARNING, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_sim2_settings
 * DESCRIPTION
 *  Initialize Data Account Records
 *  
 *  Called from SAT to enter Data Account Main Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_sim2_settings(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   g_sim_setting_flag = TRUE;
   DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_WARNING, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, SUCCESS_TONE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_sim2_settings
 * DESCRIPTION
 *  Initialize Data Account Records
 *  
 *  Called from SAT to enter Data Account Main Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mmi_dtcnt_get_sim_settings(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   return g_sim_setting_flag;
}

#endif /* __DUAL_TEST__ */

/*****************************************************************************
 * FUNCTION
 *  InitializeDataAccountRecords
 * DESCRIPTION
 *  Initialize Data Account Records
 *  
 *  Called from SAT to enter Data Account Main Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitializeDataAccountRecords(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DataAccountReadyCheck(EntryDTCNTList);
}


/*****************************************************************************
 * FUNCTION
 *  DataAccountReadyCheck
 * DESCRIPTION
 *  Chec if data account is ready in global array,
 *  execute call back function when ready.
 * PARAMETERS
 *  ready_callback      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DataAccountReadyCheck(FuncPtr ready_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef SYNCML_DM_SUPPORT
    if(mmi_dtcnt_ready_check())
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_BUSY_TRY_LATER), IMG_GLOBAL_WARNING, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, SUCCESS_TONE);
        return;
    }
#endif /* SYNCML_DM_SUPPORT */

    /*if(mmi_cbm_get_dtcnt_init_sataus())
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_BUSY_TRY_LATER), IMG_GLOBAL_WARNING, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, SUCCESS_TONE);
        return;
    }*/
    
    g_DTCNTReadyCallback = ready_callback;
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);    
#ifdef SYNCML_DM_SUPPORT
    g_DataAccount_Display.check_status = TRUE;
#endif
    DTCNTGetAccountReq(0);
}

#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  DataAccountReadyCheck
 * DESCRIPTION
 *  Chec if data account is ready in global array,
 *  execute call back function when ready.
 * PARAMETERS
 *  ready_callback      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 DataAccountGetCheckStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_DataAccount_Display.check_status;
}
#endif /* defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__) */

/* micha0112 begin */

/*****************************************************************************
 * FUNCTION
 *  HighlightAppDTCNTList
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAppDTCNTList(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.CurrAppSelectItem = (U8) nIndex;
}

/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_csd_list_screen_del_handler
* DESCRIPTION
*  
* PARAMETERS
*  in_param        [?]     
* RETURNS
*  void
*****************************************************************************/
U8 mmi_dtcnt_csd_list_screen_del_handler(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    PRINT_INFORMATION("$$$$$ mmi_dtcnt_csd_list_screen_del_handler app_call = %d, del_handler_flag = %d $$$$$", 
        g_DataAccount_Display.app_call, g_always_ask_screen_del_handler_flag);

    if(IsScreenPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK))
    {
        return FALSE;
    }
    if((!g_DataAccount_Display.app_call) && (!g_always_ask_screen_del_handler_flag))
    {
        g_always_ask_screen_del_handler_flag = TRUE;
        if(g_DataAccount_Display.app_callback_ext)
        {
            g_DataAccount_Display.app_callback_ext( 0, FALSE);
            g_DataAccount_Display.app_callback_ext = NULL;
        }
    }
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  EntryAppDTCNTList
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAppDTCNTList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 i = 0;
    U8 *DataAccountName[MAX_DATA_ACCOUNT_GSM_LIMIT];
    static U8 *PopUpDescription[MAX_DATA_ACCOUNT_GSM_LIMIT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_DATA_ACCOUNT_GSM_LIMIT; i++)
    {
        /* micha0307 */
        DataAccountName[i] = g_DataAccount[i].DataAccountName;
        if (mmi_ucs2strlen((PS8) g_DataAccount[i].DialNumber) > 0)
        {
            PopUpDescription[i] = g_DataAccount[i].DialNumber;
        }
        else
        {
            PopUpDescription[i] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        }
    }

    EntryNewScreen(SCR_ID_DTCNT_LIST, NULL, EntryAppDTCNTList, NULL);

#ifdef OBIGO_Q03C
    DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_CONFIRM);
#endif /* OBIGO_Q03C */

    SetDelScrnIDCallbackHandler(SCR_ID_DTCNT_LIST, (HistoryDelCBPtr) mmi_dtcnt_csd_list_screen_del_handler);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_LIST);
    RegisterHighlightHandler(HighlightAppDTCNTList);

    ShowCategory53Screen(
        STR_GLOBAL_DATA_ACCOUNT,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_DATA_ACCOUNT_GSM_LIMIT,
        (U8 **) DataAccountName,
        (PU16) gIndexIconsImageList,
        PopUpDescription,
        0,
        g_DataAccount_Display.CurrAppSelectItem,
        guiBuffer);
    SetLeftSoftkeyFunction(AppDTCNTSelectOK, KEY_EVENT_UP);
    SetKeyHandler(AppDTCNTSelectOK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

#ifdef OBIGO_Q03C
    SetRightSoftkeyFunction(mmi_dtcnt_list_go_back_gprs, KEY_EVENT_UP);
    SetKeyHandler(mmi_dtcnt_list_go_back_gprs, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#else
    SetRightSoftkeyFunction(mmi_dtcnt_csd_prof_back, KEY_EVENT_UP);
    SetKeyHandler(mmi_dtcnt_csd_prof_back, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /* OBIGO_Q03C */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_csd_prof_back
 * DESCRIPTION
 *  
 *  
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_csd_prof_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.CurrAppSelectItem = 0;
    GoBackHistory();
}
#ifdef OBIGO_Q03C
/*****************************************************************************
 * FUNCTION
 *  AppDTCNTSelectOK
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_go_back_gprs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.CurrAppSelectItem = 0;
    if(g_dtcnt_list_cnt.switch_bearer_flag) 
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_CONFIRM);
#ifdef __MMI_GPRS_FEATURES__
        mmi_dtcnt_list_by_app_confirm(STR_ID_DTCNT_SELECT_GPRS, mmi_dtcnt_list_back_handler);
#endif /* __MMI_GPRS_FEATURES__ */
    }
    else
    {
        if(g_DataAccount_Display.app_call)
        {
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
        }
        if(g_bearer_num_flag)
        {
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_DUAL_SIM);
        }
        
        g_entry_option_back_flag = TRUE;
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  AppDTCNTSelectOK
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_back_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_DTCNT_LIST);
    g_DataAccount_Display.bearers = DATA_ACCOUNT_BEARER_GPRS;
    GoBackHistory();
}
#endif /* OBIGO_Q03C */

/*****************************************************************************
 * FUNCTION
 *  AppDTCNTSelectOK
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AppDTCNTSelectOK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_DataAccount_Display.app_callback)
    {
        kal_uint32 id;

#ifdef OBIGO_Q03C
        DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_CONFIRM);
#endif /* OBIGO_Q03C */

        abm_bearer2nw_id(ABM_E_SOCKET_BEARER_GSM_CSD, g_DataAccount_Display.CurrAppSelectItem, &id);

        MMI_TRACE(TRACE_GROUP_6, MMI_DTCNT_APP_SELECT_OK, id);

#ifdef __MMI_DUAL_SIM__  
            id = always_ask_encode_data_account_id(id, g_sim_info, 0, 0);
#endif
        /* return U32 acct id */
        g_DataAccount_Display.app_callback(id);
        g_DataAccount_Display.app_callback = NULL;
    }
    else if (g_DataAccount_Display.app_callback_ext)
    {
        kal_uint32 id;

        abm_bearer2nw_id(ABM_E_SOCKET_BEARER_GSM_CSD, g_DataAccount_Display.CurrAppSelectItem, &id);

        MMI_TRACE(TRACE_GROUP_6, MMI_DTCNT_APP_SELECT_OK, id);
#ifdef __MMI_DUAL_SIM__
            id = always_ask_encode_data_account_id(id, g_sim_info, 0, 0);
#endif
        /* return U32 acct id */
        
        g_DataAccount_Display.app_callback_ext( id, TRUE);
        g_DataAccount_Display.app_callback_ext = NULL;
    
        if(!g_DataAccount_Display.app_call)
        {
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_DUAL_SIM);
        }
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightDTCNTList
 * DESCRIPTION
 *  gets current hilite item for data account list
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightDTCNTList(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.CurrSelectItem = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryDTCNTList
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryDTCNTList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 i = 0;
    U8 *DataAccountName[MAX_DATA_ACCOUNT_GSM_LIMIT];
    static U8 *PopUpDescription[MAX_DATA_ACCOUNT_GSM_LIMIT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_DATA_ACCOUNT_GSM_LIMIT; i++)
    {
        /* micha0307 */
        DataAccountName[i] = g_DataAccount[i].DataAccountName;
        if (mmi_ucs2strlen((PS8) g_DataAccount[i].DialNumber) > 0)
        {
            PopUpDescription[i] = g_DataAccount[i].DialNumber;
        }
        else
        {
            PopUpDescription[i] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        }
    }

    EntryNewScreen(SCR_ID_DTCNT_LIST, NULL, InitializeDataAccountRecords, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_LIST);
    SetParentHandler(SERVICES_DATA_CONNECT_MAIN_MENU_ID);
    RegisterHighlightHandler(HighlightDTCNTList);

    ShowCategory53Screen(
        SERVICES_DATA_CONNECT_GSM_STRING_ID,//STR_GLOBAL_DATA_ACCOUNT,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_EDIT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_DATA_ACCOUNT_GSM_LIMIT,
        (U8 **) DataAccountName,
        (PU16) gIndexIconsImageList,
        PopUpDescription,
        0,
        g_DataAccount_Display.CurrSelectItem,
        NULL);

    SetLeftSoftkeyFunction(InitInLineDataAccount, KEY_EVENT_UP);
    SetKeyHandler(InitInLineDataAccount, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(SCR_ID_DTCNT_LIST, mmi_dtcnt_exit_list_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  EntryDTCNTEdit
 * DESCRIPTION
 *  Edit Data Account
 *  
 *  This is used to edit Data Account Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryDTCNTEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *inputBuffer;
    U8 *guiBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_EDIT, ExitDTCNTEdit, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_DTCNT_EDIT, &inputBufferSize);     /* added for inline edit history */
    SetParentHandler(MITEM_DATA_ACCOUNT_PARENT_ZERO);
    DataAccountFillInlineStruct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MAX_INLINE_ITEM_DATA_ACCOUNT_LIST, inputBuffer);
    }

    if (VerifyDataAcountChanges() && GetInlineDoneFlag(guiBuffer) == 0)
    {
        SetInlineDoneFlag(guiBuffer);
    }

    ShowCategory57Screen(
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_EDIT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_INLINE_ITEM_DATA_ACCOUNT_LIST,
        g_DataAccount_Display.IconList,
        wgui_inline_items,
        DATA_ACCOUNT_HILITED_ITEM,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(EntryDTCNTSave, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitDTCNTEdit
 * DESCRIPTION
 *  Exit from Edit
 *  
 *  This is used to exit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitDTCNTEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DTCNT_EDIT;
    h.entryFuncPtr = EntryDTCNTEdit;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  InitInLineDataAccount
 * DESCRIPTION
 *  Fill the Inline Structure.
 *  
 *  This is used to edit Data Account Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitInLineDataAccount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = g_DataAccount_Display.CurrSelectItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) g_DataAccount_Display.DataAccountName, (PS8) g_DataAccount[i].DataAccountName);
    mmi_ucs2cpy((PS8) g_DataAccount_Display.DialNumber, (PS8) g_DataAccount[i].DialNumber);
    mmi_asc_to_ucs2((PS8) g_DataAccount_Display.UserName, (PS8) g_DataAccount[i].UserName);
    mmi_asc_to_ucs2((PS8) g_DataAccount_Display.Passwd, (PS8) g_DataAccount[i].Passwd);

    ReturnThreeDigitString(g_DataAccount_Display.IP1, g_DataAccount[i].DnsAddress[0]);
    ReturnThreeDigitString(g_DataAccount_Display.IP2, g_DataAccount[i].DnsAddress[1]);
    ReturnThreeDigitString(g_DataAccount_Display.IP3, g_DataAccount[i].DnsAddress[2]);
    ReturnThreeDigitString(g_DataAccount_Display.IP4, g_DataAccount[i].DnsAddress[3]);

    g_DataAccount_Display.DialType = (S32) g_DataAccount[i].DialType;
    g_DataAccount_Display.DataRate = (S32) g_DataAccount[i].DataRate;

    g_DataAccount_Display.DialTypeOption[0] = (U8*) GetString(STR_ID_DTCNT_ANALOGUE_STR);
    g_DataAccount_Display.DialTypeOption[1] = (U8*) GetString(STR_ID_DTCNT_ISDN_STR);
    g_DataAccount_Display.DialRateOption[0] = (U8*) GetString(STR_ID_DTCNT_RATE_STR_ONE);
    g_DataAccount_Display.DialRateOption[1] = (U8*) GetString(STR_ID_DTCNT_RATE_STR_TWO);
    g_DataAccount_Display.DialRateOption[2] = (U8*) GetString(STR_ID_DTCNT_RATE_STR_THREE);

    EntryDTCNTEdit();
}


/*****************************************************************************
 * FUNCTION
 *  DataAccountFillInlineStruct
 * DESCRIPTION
 *  Call the Inline Functions.
 *  
 *  This is used to edit Data Account Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DataAccountFillInlineStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 BufferSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation((wgui_inline_items + DATA_ACCOUNT_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + DATA_ACCOUNT_DIAL_NUMBER), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + DATA_ACCOUNT_USER_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + DATA_ACCOUNT_PASSWD), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + DATA_ACCOUNT_DNS_ADDRESS), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + DATA_ACCOUNT_DIAL_TYPE), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + DATA_ACCOUNT_DATA_RATE), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemCaption((wgui_inline_items + DATA_ACCOUNT_NAME_STR), (U8*) GetString(STR_ID_DTCNT_RENAME));
    SetInlineItemCaption(
        (wgui_inline_items + DATA_ACCOUNT_DIAL_NUMBER_STR),
        (U8*) GetString(STR_ID_DTCNT_DIAL_NUMBER));
    SetInlineItemCaption((wgui_inline_items + DATA_ACCOUNT_USER_NAME_STR), (U8*) GetString(STR_ID_DTCNT_USER_NAME));
    SetInlineItemCaption((wgui_inline_items + DATA_ACCOUNT_PASSWD_STR), (U8*) GetString(STR_ID_DTCNT_PASSWD));
    SetInlineItemCaption((wgui_inline_items + DATA_ACCOUNT_DIAL_TYPE_STR), (U8*) GetString(STR_ID_DTCNT_DIAL_TYPE));
    SetInlineItemCaption((wgui_inline_items + DATA_ACCOUNT_DATA_RATE_STR), (U8*) GetString(STR_ID_DTCNT_DATA_RATE));
    SetInlineItemCaption(
        (wgui_inline_items + DATA_ACCOUNT_DNS_ADDRESS_STR),
        (U8*) GetString(STR_ID_DTCNT_DNS_ADDRESS));

    SetInlineItemSelect(
        (wgui_inline_items + DATA_ACCOUNT_DIAL_TYPE),
        (S32) DATA_ACCOUNT_INLINE_DIAL_TYPE_OPTION,
        (U8 **) g_DataAccount_Display.DialTypeOption,
        (S32*) & g_DataAccount_Display.DialType);
    SetInlineItemSelect(
        (wgui_inline_items + DATA_ACCOUNT_DATA_RATE),
        (S32) DATA_ACCOUNT_INLINE_DATA_RATE_OPTION,
        (U8 **) g_DataAccount_Display.DialRateOption,
        (S32*) & g_DataAccount_Display.DataRate);

    BufferSize = MAX_DATA_ACCOUNT_NAME_LEN + 1;

    SetInlineItemFullScreenEdit(
        (wgui_inline_items + DATA_ACCOUNT_NAME),
        STR_ID_DTCNT_RENAME,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_DataAccount_Display.DataAccountName),
        BufferSize,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH);
    SetInlineFullScreenEditCustomFunction(wgui_inline_items + DATA_ACCOUNT_NAME, DataAccountFullLineEditScreen);

    BufferSize = MAX_DIAL_NUM_LEN - 1;  /* 1 because + is handled by UI */
    SetInlineItemTextEdit(
        (wgui_inline_items + DATA_ACCOUNT_DIAL_NUMBER),
        (U8*) (g_DataAccount_Display.DialNumber),
        BufferSize,
        INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);

    BufferSize = MAX_USER_LEN + 1;

    SetInlineItemFullScreenEdit(
        (wgui_inline_items + DATA_ACCOUNT_USER_NAME),
        STR_ID_DTCNT_USER_NAME,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_DataAccount_Display.UserName),
        BufferSize,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(wgui_inline_items + DATA_ACCOUNT_USER_NAME, DataAccountFullLineEditScreen);

    BufferSize = MAX_PASSWD_LEN + 1;
    SetInlineItemFullScreenEdit(
        (wgui_inline_items + DATA_ACCOUNT_PASSWD),
        STR_ID_DTCNT_PASSWD,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_DataAccount_Display.Passwd),
        BufferSize,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(wgui_inline_items + DATA_ACCOUNT_PASSWD, DataAccountFullLineEditScreen);

    SetInlineItemIP4(
        (wgui_inline_items + DATA_ACCOUNT_DNS_ADDRESS),
        (U8*) g_DataAccount_Display.IP1,
        (U8*) g_DataAccount_Display.IP2,
        (U8*) g_DataAccount_Display.IP3,
        (U8*) g_DataAccount_Display.IP4,
        PreparedIPAddressString);
}


/*****************************************************************************
 * FUNCTION
 *  DataAccountFullLineEditScreen
 * DESCRIPTION
 *  Data Account Name for Full Line Edit Screen.
 *  
 *  This is used to edit Data Account.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DataAccountFullLineEditScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);

    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID));

    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  PreparedIPAddressString
 * DESCRIPTION
 *  Prepared the Data Account IP Address to Show on Screen.
 * PARAMETERS
 *  string_buffer       [?]     
 *  IP1                 [?]     
 *  IP2                 [?]     
 *  IP3                 [?]     
 *  IP4                 [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PreparedIPAddressString(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Point[MAX_PART_IP_ADDRESS];
    S32 IPAddress[MAX_PART_IP_ADDRESS];
    U8 LocalBuffer[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) Point, (S8*) ".");

    IPAddress[0] = (S32) gui_atoi((UI_string_type) IP1);
    IPAddress[1] = (S32) gui_atoi((UI_string_type) IP2);
    IPAddress[2] = (S32) gui_atoi((UI_string_type) IP3);
    IPAddress[3] = (S32) gui_atoi((UI_string_type) IP4);

    ReturnThreeDigitString(LocalBuffer, (U8) IPAddress[0]);
    mmi_ucs2cpy((PS8) string_buffer, (PS8) LocalBuffer);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);

    ReturnThreeDigitString(LocalBuffer, (U8) IPAddress[1]);
    mmi_ucs2cat((PS8) string_buffer, (PS8) LocalBuffer);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);

    ReturnThreeDigitString(LocalBuffer, (U8) IPAddress[2]);
    mmi_ucs2cat((PS8) string_buffer, (PS8) LocalBuffer);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);

    ReturnThreeDigitString(LocalBuffer, (U8) IPAddress[3]);
    mmi_ucs2cat((PS8) string_buffer, (PS8) LocalBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  ReturnThreeDigitString
 * DESCRIPTION
 *  This Fun Convert the integer value to String with prefix zero.
 *  
 *  Works only for three digit integer.(0-256)
 * PARAMETERS
 *  StringVal       [IN]        
 *  DigitVal        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ReturnThreeDigitString(PU8 StringVal, U8 DigitVal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 LocalBuffer[8];
    S8 StrVal[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DigitVal == 0)
    {
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) "000");
    }
    else if (DigitVal < 10)
    {
        sprintf(LocalBuffer, "00%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    else if (DigitVal < 100)
    {
        sprintf(LocalBuffer, "0%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    else
    {
        sprintf(LocalBuffer, "%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    mmi_ucs2cpy((PS8) StringVal, (PS8) StrVal);
}


/*****************************************************************************
 * FUNCTION
 *  VerifyDataAcountChanges
 * DESCRIPTION
 *  Verify the Data Account fields.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 VerifyDataAcountChanges(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = g_DataAccount_Display.CurrSelectItem;
    S8 UserName_UCS2[(MAX_USER_LEN + 1) * ENCODING_LENGTH];
    S8 Passwd_UCS2[(MAX_PASSWD_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((PS8) UserName_UCS2, (PS8) g_DataAccount[i].UserName);
    mmi_asc_to_ucs2((PS8) Passwd_UCS2, (PS8) g_DataAccount[i].Passwd);

    if (mmi_ucs2cmp((PS8) g_DataAccount[i].DataAccountName, (PS8) g_DataAccount_Display.DataAccountName))
    {
        return TRUE;
    }
    if (mmi_ucs2cmp((PS8) g_DataAccount[i].DialNumber, (PS8) g_DataAccount_Display.DialNumber))
    {
        return TRUE;
    }
    if (mmi_ucs2cmp((PS8) UserName_UCS2, (PS8) g_DataAccount_Display.UserName))
    {
        return TRUE;
    }
    if (mmi_ucs2cmp((PS8) Passwd_UCS2, (PS8) g_DataAccount_Display.Passwd))
    {
        return TRUE;
    }
    if (((S32) g_DataAccount[i].DialType) != g_DataAccount_Display.DialType)
    {
        return TRUE;
    }
    if (((S32) g_DataAccount[i].DataRate) != g_DataAccount_Display.DataRate)
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  DataAccountSaveChanges
 * DESCRIPTION
 *  Save the Changed fields.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DataAccountSaveChanges(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = g_DataAccount_Display.CurrSelectItem;
    U8 PrevIfdcs = 0;
    U8 StrDigit[MAX_IPADDRES_LEN * ENCODING_LENGTH];
    S32 WordCount = 0;
    S8 AccountNameStr[30 * ENCODING_LENGTH];    /* Assumption:  string "Data Account " length < 30 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);

    PrevIfdcs = g_DataAccount[i].iFdcs;

    memset(&g_DataAccount[i], '\0', sizeof(DataAccountNode));

    /*WordCount = GetInlineEditUCS2Count(&wgui_inline_items[1]);*/

    if(mmi_dtcnt_check_UCS2((U16*)g_DataAccount_Display.DataAccountName, (U16)mmi_ucs2strlen((PS8)g_DataAccount_Display.DataAccountName)))
    {
        WordCount = -1;
    }
    else
    {
        WordCount = 0;
    }

    if (WordCount < 0)
    {
        g_DataAccount[i].iFdcs = mmi_ucs2strlen((PS8) g_DataAccount_Display.DataAccountName);
    }
    else
    {
        g_DataAccount[i].iFdcs = (U8) WordCount;
    }

    SetDynaDataAccountName(AccountNameStr, g_DataAccount_Display.CurrSelectItem);

    if (mmi_ucs2strlen((PS8) g_DataAccount_Display.DataAccountName) == 0)
    {
        mmi_ucs2cpy((PS8) g_DataAccount[i].DataAccountName, (PS8) AccountNameStr);
        g_DataAccount[i].iFdcs = mmi_ucs2strlen((PS8) g_DataAccount[i].DataAccountName);
    }
    else
    {
        mmi_ucs2cpy((PS8) g_DataAccount[i].DataAccountName, (PS8) g_DataAccount_Display.DataAccountName);
    }

    mmi_ucs2cpy((PS8) g_DataAccount[i].DialNumber, (PS8) g_DataAccount_Display.DialNumber);
    mmi_ucs2_to_asc((PS8) g_DataAccount[i].UserName, (PS8) g_DataAccount_Display.UserName);
    mmi_ucs2_to_asc((PS8) g_DataAccount[i].Passwd, (PS8) g_DataAccount_Display.Passwd);

    mmi_ucs2_to_asc((PS8) StrDigit, (PS8) g_DataAccount_Display.IP1);
    g_DataAccount[i].DnsAddress[0] = (U8) atoi((S8*) StrDigit);
    mmi_ucs2_to_asc((PS8) StrDigit, (PS8) g_DataAccount_Display.IP2);
    g_DataAccount[i].DnsAddress[1] = (U8) atoi((S8*) StrDigit);
    mmi_ucs2_to_asc((PS8) StrDigit, (PS8) g_DataAccount_Display.IP3);
    g_DataAccount[i].DnsAddress[2] = (U8) atoi((S8*) StrDigit);
    mmi_ucs2_to_asc((PS8) StrDigit, (PS8) g_DataAccount_Display.IP4);
    g_DataAccount[i].DnsAddress[3] = (U8) atoi((S8*) StrDigit);
    g_DataAccount[i].DialType = (U8) g_DataAccount_Display.DialType;
    g_DataAccount[i].DataRate = (U8) g_DataAccount_Display.DataRate;
    g_DataAccount[i].Present = 'P';
    DTCNTSetAccountReq(i);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_check_UCS2
 * DESCRIPTION
 *  Notification Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

BOOL mmi_dtcnt_check_UCS2(U16 *buf, U16 charNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *buffer = buf;
    U16 charNumber = charNum;
    U16 c;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < charNumber)
    {
        c = buffer[count];
        if (UI_TEST_UCS2_CHARACTER(c))
        {
            return KAL_TRUE;
        }
        count++;
    }

    return KAL_FALSE;
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/*****************************************************************************
 * FUNCTION
 *  EntryDTCNTSave
 * DESCRIPTION
 *  Notification Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryDTCNTSave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(DataAccountSaveChanges, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoToMainDataAccountScreen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  GoToMainDataAccountScreen
 * DESCRIPTION
 *  Go back 2 history screens to Data Account Main
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToMainDataAccountScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  ShowDataAccountOKMessage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowDataAccountOKMessage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, DATA_ACCOUNT_NOTIFY_TIMEOUT, SUCCESS_TONE);
    /* micha0427 */
    DeleteScreenIfPresent(SCR_ID_DTCNT_EDIT);
#ifdef __MMI_GPRS_FEATURES__
    DeleteScreenIfPresent(SCR_ID_DTCNT_GPRS_EDIT);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  DTCNTSetAccountReq
 * DESCRIPTION
 *  Use the L4 to store the Data Account Record.
 * PARAMETERS
 *  ItemNum     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DTCNTSetAccountReq(U8 ItemNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_cc_set_csd_profile_req_struct *myMsgPtr;

    /* micha0820 */
    U8 ref_count;
    U16 msg_len;

    MYQUEUE Message;
    U8 DataAccountName_ASCII[(MAX_DATA_ACCOUNT_NAME_LEN + 1) * ENCODING_LENGTH];
    U8 pbNumber_ASCII[(MAX_DIAL_NUM_LEN + 1) * ENCODING_LENGTH];
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ItemNum >= MAX_DATA_ACCOUNT_GSM_LIMIT)
    {
        return;
    }

    memset(DataAccountName_ASCII, '\0', (MAX_DATA_ACCOUNT_NAME_LEN + 1) * ENCODING_LENGTH);
    memset(pbNumber_ASCII, '\0', (MAX_DIAL_NUM_LEN + 1) * ENCODING_LENGTH);

    myMsgPtr = (mmi_cc_set_csd_profile_req_struct*) OslConstructDataPtr(sizeof(mmi_cc_set_csd_profile_req_struct));

    /* micha0820 */
    ref_count = myMsgPtr->ref_count;
    msg_len = myMsgPtr->msg_len;
    memset(myMsgPtr, '\0', sizeof(mmi_cc_set_csd_profile_req_struct));
    myMsgPtr->ref_count = ref_count;
    myMsgPtr->msg_len = msg_len;

    myMsgPtr->csd_module = 0;
    myMsgPtr->auth_type = 0;
    myMsgPtr->prof_id = ItemNum;

    if (g_DataAccount[ItemNum].DialType == DIAL_TYPE_ANALOGUE)
    {
        myMsgPtr->type = (U8) CSMCC_ITC_3_1_K_AUDIO;
    }
    else
    {
        myMsgPtr->type = (U8) CSMCC_ITC_UDI;
    }

    if (g_DataAccount[ItemNum].DataRate == DATA_RATE_FOUR_EIGHT - 1)
    {
        myMsgPtr->rate = (U8) CSD_PROF_RATE_4800;
    }
    else if (g_DataAccount[ItemNum].DataRate == DATA_RATE_NINE_SIX - 1)
    {
        myMsgPtr->rate = (U8) CSD_PROF_RATE_9600;
    }
    else if (g_DataAccount[ItemNum].DataRate == DATA_RATE_FOURTEEN_FOUR - 1)
    {
        myMsgPtr->rate = (U8) CSD_PROF_RATE_14400;
    }

    for (i = 0; i < 4; i++)
    {
        myMsgPtr->dns[i] = (U8) g_DataAccount[ItemNum].DnsAddress[i];
    }

    if (g_DataAccount[ItemNum].iFdcs > 0)
    {
        g_DataAccount[ItemNum].iFdcs = mmi_ucs2strlen((PS8) g_DataAccount[ItemNum].DataAccountName) * ENCODING_LENGTH;
        myMsgPtr->name.name_length = g_DataAccount[ItemNum].iFdcs;
        myMsgPtr->name.name_dcs = DATA_ACCOUNT_UCS; /* 0x8 */
        i = 0;
        while (i != g_DataAccount[ItemNum].iFdcs)
        {
            myMsgPtr->name.name[i] = g_DataAccount[ItemNum].DataAccountName[i + 1];
            myMsgPtr->name.name[i + 1] = g_DataAccount[ItemNum].DataAccountName[i];
            i += 2;
        }
        myMsgPtr->name.name[i] = '\0';
        myMsgPtr->name.name[i + 1] = '\0';
    }
    else
    {
        myMsgPtr->name.name_dcs = DATA_ACCOUNT_ASCII;
        mmi_ucs2_to_asc((PS8) DataAccountName_ASCII, (PS8) g_DataAccount[ItemNum].DataAccountName);
        myMsgPtr->name.name_length = strlen((PS8) DataAccountName_ASCII);
        memcpy(myMsgPtr->name.name, DataAccountName_ASCII, strlen((PS8) DataAccountName_ASCII) /* +1 */ );
        g_DataAccount[ItemNum].iFdcs = 0;
    }

    memcpy(myMsgPtr->user_id, g_DataAccount[ItemNum].UserName, strlen((PS8) g_DataAccount[ItemNum].UserName) + 1);

    memcpy(myMsgPtr->passwd, g_DataAccount[ItemNum].Passwd, strlen((PS8) g_DataAccount[ItemNum].Passwd) + 1);

    if (g_DataAccount[ItemNum].DialNumber[0] == '+')
    {
        mmi_ucs2_to_asc((PS8) pbNumber_ASCII, (PS8) g_DataAccount[ItemNum].DialNumber + ENCODING_LENGTH);
        myMsgPtr->dest.type = MMI_CSMCC_INTERNATIONAL_ADDR; /* INTERNATIONAL */
        myMsgPtr->dest.length = strlen((PS8) pbNumber_ASCII) + 1;
        memcpy(myMsgPtr->dest.number, pbNumber_ASCII, strlen((PS8) pbNumber_ASCII) + 1);
    }
    else
    {
        mmi_ucs2_to_asc((PS8) pbNumber_ASCII, (PS8) g_DataAccount[ItemNum].DialNumber);
        myMsgPtr->dest.type = MMI_CSMCC_DEFAULT_ADDR_TYPE;  /* DEFAULT */
        myMsgPtr->dest.length = strlen((PS8) pbNumber_ASCII) + 1;
        memcpy(myMsgPtr->dest.number, pbNumber_ASCII, strlen((PS8) pbNumber_ASCII) + 1);

    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_CC_SET_CSD_PROFILE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(DTCNTSetAccountRsp, PRT_MMI_CC_SET_CSD_PROFILE_RSP);
    OslMsgSendExtQueue(&Message);
    ClearInputEventHandler(MMI_DEVICE_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  EntryDTCNTProgress
 * DESCRIPTION
 *  Progress screen before got response from L4
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryDTCNTProgress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_POPUP, NULL, EntryDTCNTProgress, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_POPUP);

    ShowCategory66Screen
        (STR_GLOBAL_DATA_ACCOUNT, GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID), 0, 0, 0, 0,
         (PU8) GetString(STR_GLOBAL_SAVING), IMG_GLOBAL_SAVE, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  DTCNTSetAccountRsp
 * DESCRIPTION
 *  Handler when set data account complete
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void DTCNTSetAccountRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_set_csd_profile_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_cc_set_csd_profile_rsp_struct*) info;

    if (localPtr->result == KAL_TRUE /* OK */ )
    {
        g_DataAccount[g_DataAccount_Display.CurrSelectItem].Present = 'P';
        ShowDataAccountOKMessage();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        /* micha0427 */
        DeleteScreenIfPresent(SCR_ID_DTCNT_EDIT);
    }

}


/*****************************************************************************
 * FUNCTION
 *  DTCNTGetAccountReq
 * DESCRIPTION
 *  Use the L4 to retrieve the Data Account Record.
 * PARAMETERS
 *  ItemNum     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DTCNTGetAccountReq(U8 ItemNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_cc_get_csd_profile_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    myMsgPtr = (mmi_cc_get_csd_profile_req_struct*) OslConstructDataPtr(sizeof(mmi_cc_get_csd_profile_req_struct));
    myMsgPtr->prof_id = ItemNum;

    SetProtocolEventHandler(DTCNTGetAccountRsp, PRT_MMI_CC_GET_CSD_PROFILE_RSP);
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_CC_GET_CSD_PROFILE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  DTCNTGetAccountRsp
 * DESCRIPTION
 *  Handler when get data account complete
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void DTCNTGetAccountRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_get_csd_profile_rsp_struct *localPtr;
    U8 ItemNum = 0, i = 0;
    S8 AccountNameStr[30 * ENCODING_LENGTH];    /* Assumption:  string "Data Account " length < 30 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_cc_get_csd_profile_rsp_struct*) info;
    ItemNum = g_DataAccount_Display.CurrGetIndex;
    memset(&g_DataAccount[ItemNum], '\0', sizeof(DataAccountNode));
    g_DataAccount[ItemNum].Present = 'P';

    if (localPtr->type == (U8) CSMCC_ITC_3_1_K_AUDIO)
    {
        g_DataAccount[ItemNum].DialType = DIAL_TYPE_ANALOGUE;
    }
    else
    {
        g_DataAccount[ItemNum].DialType = DIAL_TYPE_ISDN;
    }

    if (localPtr->rate == (U8) CSD_PROF_RATE_4800)
    {
        g_DataAccount[ItemNum].DataRate = DATA_RATE_FOUR_EIGHT -1;
    }
    else if (localPtr->rate == (U8) CSD_PROF_RATE_9600)
    {
        g_DataAccount[ItemNum].DataRate = DATA_RATE_NINE_SIX - 1;
    }
    else if (localPtr->rate == (U8) CSD_PROF_RATE_14400)
    {
        g_DataAccount[ItemNum].DataRate = DATA_RATE_FOURTEEN_FOUR - 1;
    }

    for (i = 0; i < 4; i++)
    {
        g_DataAccount[ItemNum].DnsAddress[i] = (U8) localPtr->dns[i];
    }

    SetDynaDataAccountName(AccountNameStr, ItemNum);

    /* micha0307 */
    if (localPtr->name.name_dcs == DATA_ACCOUNT_UCS)
    {
        i = 0;
        g_DataAccount[ItemNum].iFdcs = localPtr->name.name_length + 1;

        if (localPtr->name.name_length == 0)
        {
            mmi_ucs2cpy((PS8) g_DataAccount[ItemNum].DataAccountName, (PS8) AccountNameStr);
        }
        else
        {
            while (i != localPtr->name.name_length)
            {
                g_DataAccount[ItemNum].DataAccountName[i] = localPtr->name.name[i + 1];
                g_DataAccount[ItemNum].DataAccountName[i + 1] = localPtr->name.name[i];
                i += 2;
            }
            g_DataAccount[ItemNum].DataAccountName[localPtr->name.name_length] = 0x00;
            g_DataAccount[ItemNum].DataAccountName[localPtr->name.name_length + 1] = 0x00;
        }
    }
    else if (localPtr->name.name_dcs == DATA_ACCOUNT_ASCII)
    {
        if (localPtr->name.name_length == 0)
        {
            mmi_ucs2cpy((PS8) g_DataAccount[ItemNum].DataAccountName, (PS8) AccountNameStr);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (PS8) g_DataAccount[ItemNum].DataAccountName,
                (PS8) localPtr->name.name,
                localPtr->name.name_length);
        }
        g_DataAccount[ItemNum].iFdcs = 0;
    }

    strcpy((PS8) g_DataAccount[ItemNum].UserName, (PS8) localPtr->user_id);
    strcpy((PS8) g_DataAccount[ItemNum].Passwd, (PS8) localPtr->passwd);

    if ((localPtr->dest.type) & 0x10)
    {
        g_DataAccount[ItemNum].DialNumber[0] = '+';
        mmi_asc_to_ucs2((PS8) g_DataAccount[ItemNum].DialNumber + 2, (PS8) localPtr->dest.number);
    }
    else
    {
        mmi_asc_to_ucs2((PS8) g_DataAccount[ItemNum].DialNumber, (PS8) localPtr->dest.number);
    }

    if ((mmi_ucs2strlen((PS8) g_DataAccount[ItemNum].DataAccountName) == 0) &&
        (mmi_ucs2strlen((PS8) g_DataAccount[ItemNum].DialNumber) == 0))
    {
        g_DataAccount[ItemNum].Present = 'E';
    }

    if (g_DataAccount_Display.CurrGetIndex < MAX_DATA_ACCOUNT_GSM_LIMIT - 1)
    {
        g_DataAccount_Display.CurrGetIndex++;
        DTCNTGetAccountReq(g_DataAccount_Display.CurrGetIndex);
    }
    else
    {
        g_DataAccount_Display.CurrGetIndex = 0;

    #ifdef __MMI_GPRS_FEATURES__
        DTCNTGPRSGetAccountReq(0);
    #else /* __MMI_GPRS_FEATURES__ */ 
        #if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
        g_DataAccount_Display.check_status = FALSE;
        #endif /*  defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__) */
        mmi_cbm_set_dtcnt_init_sataus(FALSE);
        g_DTCNTReadyCallback();
        g_DTCNTReadyCallback = NULL;
    #endif /* __MMI_GPRS_FEATURES__ */ 
    }
}


extern void mmi_dtcnt_ota_select_profile(void);
/*****************************************************************************
 * FUNCTION
 *  EntryDTCNTMain
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryDTCNTMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *u8GPRSCount[MAX_SUB_MENUS];     /* sms counters for display hint popups */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(SERVICES_DATA_CONNECT_MAIN_MENU_ID);

    if(nNumofItem == 1)
    {
        InitializeDataAccountRecords();
        return;
    }
    
    EntryNewScreen(SCR_ID_DTCNT_MAIN, NULL, EntryDTCNTMain, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_MAIN);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(SERVICES_DATA_CONNECT_MAIN_MENU_ID);
    /* Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(SERVICES_DATA_CONNECT_MAIN_MENU_ID);
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(SERVICES_DATA_CONNECT_MAIN_MENU_ID, nStrItemList);
    /* Set current parent id */
    SetParentHandler(SERVICES_DATA_CONNECT_MAIN_MENU_ID);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* construct hint popups for the menu items */
    ConstructHintsList(SERVICES_DATA_CONNECT_MAIN_MENU_ID, u8GPRSCount);

    /* Display Category52 Screen */
    ShowCategory52Screen(
        SERVICES_DATA_CONNECT_MAIN_STRING_ID,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        u8GPRSCount,
        0,
        0,
        guiBuffer);

    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_GPRS_FEATURES__

/*****************************************************************************
 * FUNCTION
 *  InitializeGPRSDataAccountRecords
 * DESCRIPTION
 *  Retrieve GPRS data account from L4
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitializeGPRSDataAccountRecords(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DataAccountReadyCheck(EntryDTCNTGPRSList);
}


/*****************************************************************************
 * FUNCTION
 *  DTCNTGPRSGetAccountReq
 * DESCRIPTION
 *  Retrieve GPRS data account from L4
 * PARAMETERS
 *  ItemNum     [IN]        //item id
 * RETURNS
 *  void
 *****************************************************************************/
void DTCNTGPRSGetAccountReq(U8 ItemNum)
{
#ifdef __PS_SERVICE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_ps_get_gprs_data_account_req_struct *myMsgPtr;

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    myMsgPtr =
        (mmi_ps_get_gprs_data_account_req_struct*)
        OslConstructDataPtr(sizeof(mmi_ps_get_gprs_data_account_req_struct));

    myMsgPtr->profile_id = ItemNum + 1;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(DTCNTGPRSGetAccountRsp, PRT_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP);
    OslMsgSendExtQueue(&Message);

#endif /* __PS_SERVICE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  DTCNTGPRSGetAccountRsp
 * DESCRIPTION
 *  Handle data account get response
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void DTCNTGPRSGetAccountRsp(void *info)
{
#ifdef __PS_SERVICE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_ps_get_gprs_data_account_rsp_struct *localPtr;
    U8 ItemNum = 0, i = 0;
    S8 AccountNameStr[30 * ENCODING_LENGTH];    /* Assumption:  string "Data Account " length < 30 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    localPtr = (mmi_ps_get_gprs_data_account_rsp_struct*) info;

    ItemNum = g_DataAccount_Display.GPRSCurrGetIndex;

    memset(&g_GPRS_DataAccount[ItemNum], '\0', sizeof(GPRSDataAccountNode));

    g_GPRS_DataAccount[ItemNum].Present = 'P';

    g_GPRS_DataAccount[ItemNum].AuthType = localPtr->gprs_account.authentication_type;

    for (i = 0; i < 4; i++)
    {
        g_GPRS_DataAccount[ItemNum].DnsAddress[i] = (U8) localPtr->gprs_account.dns[i];
    }

    SetDynaDataAccountName(AccountNameStr, ItemNum);

    /* micha0307 */
    if (localPtr->gprs_account.name_dcs == DATA_ACCOUNT_UCS)
    {
        i = 0;
        g_GPRS_DataAccount[ItemNum].iFdcs = localPtr->gprs_account.name_length + 1;

        if (localPtr->gprs_account.name_length == 0)
        {
            mmi_ucs2cpy((PS8) g_GPRS_DataAccount[ItemNum].DataAccountName, (PS8) AccountNameStr);
        }
        else
        {
            while (i != localPtr->gprs_account.name_length)
            {
                g_GPRS_DataAccount[ItemNum].DataAccountName[i] = localPtr->gprs_account.name[i + 1];
                g_GPRS_DataAccount[ItemNum].DataAccountName[i + 1] = localPtr->gprs_account.name[i];
                i += 2;
            }
            g_GPRS_DataAccount[ItemNum].DataAccountName[localPtr->gprs_account.name_length] = 0x00;
            g_GPRS_DataAccount[ItemNum].DataAccountName[localPtr->gprs_account.name_length + 1] = 0x00;
        }
    }
    else if (localPtr->gprs_account.name_dcs == DATA_ACCOUNT_ASCII)
    {
        if (localPtr->gprs_account.name_length == 0)
        {
            mmi_ucs2cpy((PS8) g_GPRS_DataAccount[ItemNum].DataAccountName, (PS8) AccountNameStr);
        }
        else
        {
            mmi_asc_n_to_ucs2(
                (PS8) g_GPRS_DataAccount[ItemNum].DataAccountName,
                (PS8) localPtr->gprs_account.name,
                localPtr->gprs_account.name_length);
        }
        g_GPRS_DataAccount[ItemNum].iFdcs = 0;
    }

    strcpy((PS8) g_GPRS_DataAccount[ItemNum].UserName, (PS8) localPtr->gprs_account.user_name);

    strcpy((PS8) g_GPRS_DataAccount[ItemNum].Passwd, (PS8) localPtr->gprs_account.password);

    mmi_asc_n_to_ucs2(
        (PS8) g_GPRS_DataAccount[ItemNum].APN,
        (PS8) localPtr->gprs_account.apn,
        (U32) localPtr->gprs_account.apn_length);

    if ((mmi_ucs2strlen((PS8) g_GPRS_DataAccount[ItemNum].DataAccountName) == 0) &&
        (mmi_ucs2strlen((PS8) g_GPRS_DataAccount[ItemNum].APN) == 0))
    {
        g_GPRS_DataAccount[ItemNum].Present = 'E';
    }
#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
#else
    if (g_DataAccount_Display.GPRSCurrGetIndex < MAX_DATA_ACCOUNT_GPRS_LIMIT - 1)
#endif /* __MMI_OP01_GPRS_DATACFG__ */
    {
        g_DataAccount_Display.GPRSCurrGetIndex++;
        DTCNTGPRSGetAccountReq(g_DataAccount_Display.GPRSCurrGetIndex);
    }
    else
    {
        g_DataAccount_Display.GPRSCurrGetIndex = 0;
        #if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
        g_DataAccount_Display.check_status = FALSE;
        #endif /* defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__) */
        mmi_cbm_set_dtcnt_init_sataus(FALSE);
        g_DTCNTReadyCallback();
        g_DTCNTReadyCallback = NULL;
    }

#endif /* __PS_SERVICE__ */ 
}

/* micha0112 begin */


/*****************************************************************************
 * FUNCTION
 *  HighlightGPRSAppDTCNTList
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightGPRSAppDTCNTList(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.GPRSCurrAppSelectItem = (U8) nIndex;
}

/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_gprs_list_screen_del_handler
* DESCRIPTION
*  
* PARAMETERS
*  in_param        [?]     
* RETURNS
*  void
*****************************************************************************/
U8 mmi_dtcnt_gprs_list_screen_del_handler(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    PRINT_INFORMATION("$$$$$ mmi_dtcnt_gprs_list_screen_del_handler app_call = %d, del_handler_flag = %d $$$$$", 
        g_DataAccount_Display.app_call, g_always_ask_screen_del_handler_flag);

    if(IsScreenPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK))
    {
        return FALSE;
    }
    if((!g_DataAccount_Display.app_call) && (!g_always_ask_screen_del_handler_flag))
    {
        g_always_ask_screen_del_handler_flag = TRUE;
        if(g_DataAccount_Display.app_callback_ext)
        {
            g_DataAccount_Display.app_callback_ext( 0, FALSE);
            g_DataAccount_Display.app_callback_ext = NULL;
        }
    }
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryGPRSAppDTCNTList
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryGPRSAppDTCNTList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 i = 0;
    U8 *DataAccountName[MAX_DATA_ACCOUNT_GPRS_LIMIT];
    static U8 *PopUpDescription[MAX_DATA_ACCOUNT_GPRS_LIMIT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MAX_DATA_ACCOUNT_GPRS_LIMIT; i++)
    {
        /* micha0307 */
        DataAccountName[i] = g_GPRS_DataAccount[i].DataAccountName;
        if (mmi_ucs2strlen((PS8) g_GPRS_DataAccount[i].APN) > 0)
        {
            PopUpDescription[i] = g_GPRS_DataAccount[i].APN;
        }
        else
        {
            PopUpDescription[i] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        }
    }

    EntryNewScreen(SCR_ID_DTCNT_GPRS_LIST, NULL, EntryGPRSAppDTCNTList, NULL);

#ifdef OBIGO_Q03C
    DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_CONFIRM);
#endif /* OBIGO_Q03C */

    SetDelScrnIDCallbackHandler(SCR_ID_DTCNT_GPRS_LIST, (HistoryDelCBPtr) mmi_dtcnt_gprs_list_screen_del_handler);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_GPRS_LIST);

    RegisterHighlightHandler(HighlightGPRSAppDTCNTList);

    ShowCategory53Screen(
        STR_GLOBAL_DATA_ACCOUNT,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_DATA_ACCOUNT_GPRS_LIMIT,
        (U8 **) DataAccountName,
        (PU16) gIndexIconsImageList,
        PopUpDescription,
        0,
        g_DataAccount_Display.GPRSCurrAppSelectItem,
        guiBuffer);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(GPRSAppDTCNTSelectOK, KEY_EVENT_UP);
    SetKeyHandler(GPRSAppDTCNTSelectOK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(mmi_dtcnt_select_account_gprs_back, KEY_EVENT_UP);
    SetKeyHandler(mmi_dtcnt_select_account_gprs_back, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_bearer_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearers     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dtcnt_select_account_gprs_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.GPRSCurrAppSelectItem = 0;
    if(g_bearer_num_flag)
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_DUAL_SIM);
    }
    g_entry_option_back_flag = TRUE;
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  GPRSAppDTCNTSelectOK
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GPRSAppDTCNTSelectOK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_DataAccount_Display.app_callback)
    {
        kal_uint32 id;
#ifdef OBIGO_Q03C
        if(g_dtcnt_list_cnt.switch_bearer_flag)
        {
            g_DataAccount_Display.app_callback = mmi_dtcnt_list_callback_gprs;
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_CONFIRM);
            mmi_dtcnt_list_by_app_confirm(STR_ID_DTCNT_SELECT_GSM_CSD, mmi_dtcnt_list_by_app_confirm_csd);
       }
#endif /* OBIGO_Q03C */
        abm_bearer2nw_id(ABM_E_SOCKET_BEARER_GSM_GPRS, g_DataAccount_Display.GPRSCurrAppSelectItem + 1, &id);
#ifdef __MMI_DUAL_SIM__
            id = always_ask_encode_data_account_id(id, g_sim_info, 0, 0);
#endif /* __MMI_DUAL_SIM__ */

        /* return U32 acct id */
        g_DataAccount_Display.app_callback(id);
        g_DataAccount_Display.app_callback = NULL;
    }
    else if(g_DataAccount_Display.app_callback_ext)
    {
        kal_uint32 id;

        abm_bearer2nw_id(ABM_E_SOCKET_BEARER_GSM_GPRS, g_DataAccount_Display.GPRSCurrAppSelectItem + 1, &id);
#ifdef __MMI_DUAL_SIM__
            id = always_ask_encode_data_account_id(id, g_sim_info, 0, 0);
#endif /* __MMI_DUAL_SIM__ */

        /* return U32 acct id */
        g_DataAccount_Display.app_callback_ext(id, TRUE);
        g_DataAccount_Display.app_callback_ext = NULL;
        if(!g_DataAccount_Display.app_call)
        {
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_DUAL_SIM);
        }
        GoBackHistory();
    }
}

/* micha0112 end */


/*****************************************************************************
 * FUNCTION
 *  EntryDTCNTGPRSList
 * DESCRIPTION
 *  Main screen for GPRS data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryDTCNTGPRSList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 i = 0;
    U8 *DataAccountName[MAX_DATA_ACCOUNT_GPRS_LIMIT];
    static U8 *PopUpDescription[MAX_DATA_ACCOUNT_GPRS_LIMIT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_DATA_ACCOUNT_GPRS_LIMIT; i++)
    {
        /* micha0307 */
        DataAccountName[i] = g_GPRS_DataAccount[i].DataAccountName;
        if (mmi_ucs2strlen((PS8) g_GPRS_DataAccount[i].APN) > 0)
        {
            PopUpDescription[i] = g_GPRS_DataAccount[i].APN;
        }
        else
        {
            PopUpDescription[i] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        }
    }

    EntryNewScreen(SCR_ID_DTCNT_GPRS_LIST, NULL, InitializeGPRSDataAccountRecords, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_GPRS_LIST);

    SetParentHandler(SERVICES_DATA_CONNECT_GPRS_MENU_ID);

    RegisterHighlightHandler(HighlightDTCNTGPRSList);

    ShowCategory53Screen(
#ifdef __MMI_GPRS_FEATURES__
        SERVICES_DATA_CONNECT_GPRS_STRING_ID,
#else
        STR_GLOBAL_DATA_ACCOUNT,
#endif 
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_EDIT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_DATA_ACCOUNT_GPRS_LIMIT,
        (U8 **) DataAccountName,
        (PU16) gIndexIconsImageList,
        PopUpDescription,
        0,
        g_DataAccount_Display.GPRSCurrSelectItem,
        NULL);


    /* Register function for left soft key */
    SetLeftSoftkeyFunction(InitInLineGPRSDataAccount, KEY_EVENT_UP);
    SetKeyHandler(InitInLineGPRSDataAccount, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(SCR_ID_DTCNT_GPRS_LIST, mmi_dtcnt_exit_list_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightDTCNTGPRSList
 * DESCRIPTION
 *  get current GPRS menu item index
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightDTCNTGPRSList(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.GPRSCurrSelectItem = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  InitInLineGPRSDataAccount
 * DESCRIPTION
 *  Set account data to display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitInLineGPRSDataAccount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i = g_DataAccount_Display.GPRSCurrSelectItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) g_DataAccount_Display.DataAccountName, (PS8) g_GPRS_DataAccount[i].DataAccountName);
    mmi_ucs2cpy((PS8) g_DataAccount_Display.APN, (PS8) g_GPRS_DataAccount[i].APN);
    mmi_asc_to_ucs2((PS8) g_DataAccount_Display.UserName, (PS8) g_GPRS_DataAccount[i].UserName);
    mmi_asc_to_ucs2((PS8) g_DataAccount_Display.Passwd, (PS8) g_GPRS_DataAccount[i].Passwd);

    ReturnThreeDigitString(g_DataAccount_Display.IP1, g_GPRS_DataAccount[i].DnsAddress[0]);
    ReturnThreeDigitString(g_DataAccount_Display.IP2, g_GPRS_DataAccount[i].DnsAddress[1]);
    ReturnThreeDigitString(g_DataAccount_Display.IP3, g_GPRS_DataAccount[i].DnsAddress[2]);
    ReturnThreeDigitString(g_DataAccount_Display.IP4, g_GPRS_DataAccount[i].DnsAddress[3]);

    g_DataAccount_Display.AuthType = (S32) g_GPRS_DataAccount[i].AuthType;

    g_DataAccount_Display.AuthTypeOption[0] = (U8*) GetString(STR_ID_DTCNT_GPRS_PAP_AUTH);
    g_DataAccount_Display.AuthTypeOption[1] = (U8*) GetString(STR_ID_DTCNT_GPRS_CHAP_AUTH);

    EntryDTCNTGPRSEdit();
}


/*****************************************************************************
 * FUNCTION
 *  EntryDTCNTGPRSEdit
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryDTCNTGPRSEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *inputBuffer;    /* added for inline edit history */
    U8 *guiBuffer;      /* Buffer holding history data */
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_EDIT, ExitDTCNTGPRSEdit, NULL, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_GPRS_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_DTCNT_GPRS_EDIT, &inputBufferSize);        /* added for inline edit history */

    SetParentHandler(MITEM_DATA_ACCOUNT_PARENT_ZERO);
    GPRSDataAccountFillInlineStruct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MAX_INLINE_ITEM_GPRSDATA_ACCOUNT_LIST, inputBuffer);
    }

    if (VerifyGPRSDataAcountChanges() && GetInlineDoneFlag(guiBuffer) == 0)
    {
        SetInlineDoneFlag(guiBuffer);
    }

    ShowCategory57Screen(
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_EDIT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_INLINE_ITEM_GPRSDATA_ACCOUNT_LIST,
        g_DataAccount_Display.IconList,
        wgui_inline_items,
        DATA_ACCOUNT_HILITED_ITEM,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(EntryDTCNTGPRSSave, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  ExitDTCNTGPRSEdit
 * DESCRIPTION
 *  exit handler for GPRS account edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitDTCNTGPRSEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DTCNT_GPRS_EDIT;
    h.entryFuncPtr = EntryDTCNTGPRSEdit;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);

}


/*****************************************************************************
 * FUNCTION
 *  GPRSDataAccountFillInlineStruct
 * DESCRIPTION
 *  fill inline structure for GPRS edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GPRSDataAccountFillInlineStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 BufferSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation((wgui_inline_items + GPRS_DATA_ACCOUNT_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + GPRS_DATA_ACCOUNT_APN), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + GPRS_DATA_ACCOUNT_USER_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + GPRS_DATA_ACCOUNT_PASSWD), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(
        (wgui_inline_items + GPRS_DATA_ACCOUNT_AUTH_TYPE),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    //DNS menu is currently disabled
    //      SetInlineItemActivation((wgui_inline_items+GPRS_DATA_ACCOUNT_DNS_ADDRESS),INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,0);

    SetInlineItemCaption((wgui_inline_items + GPRS_DATA_ACCOUNT_NAME_STR), (U8*) GetString(STR_ID_DTCNT_RENAME));
    SetInlineItemCaption((wgui_inline_items + GPRS_DATA_ACCOUNT_APN_STR), (U8*) GetString(STR_ID_DTCNT_GPRS_APN));
    SetInlineItemCaption(
        (wgui_inline_items + GPRS_DATA_ACCOUNT_USER_NAME_STR),
        (U8*) GetString(STR_ID_DTCNT_USER_NAME));
    SetInlineItemCaption((wgui_inline_items + GPRS_DATA_ACCOUNT_PASSWD_STR), (U8*) GetString(STR_ID_DTCNT_PASSWD));
    SetInlineItemCaption(
        (wgui_inline_items + GPRS_DATA_ACCOUNT_AUTH_TYPE_STR),
        (U8*) GetString(STR_ID_DTCNT_GPRS_AUTH_TYP));
    /* SetInlineItemCaption((wgui_inline_items+GPRS_DATA_ACCOUNT_DNS_ADDRESS_STR),(U8*)GetString(STR_ID_DTCNT_DNS_ADDRESS)); */

    SetInlineItemSelect(
        (wgui_inline_items + GPRS_DATA_ACCOUNT_AUTH_TYPE),
        (S32) GPRS_DATA_ACCOUNT_INLINE_AUTH_TYPE_OPTION,
        (U8 **) g_DataAccount_Display.AuthTypeOption,
        (S32*) & g_DataAccount_Display.AuthType);

    BufferSize = MAX_GPRS_DATAACCOUNT_NAME + 1;

    SetInlineItemFullScreenEdit(
        (wgui_inline_items + GPRS_DATA_ACCOUNT_NAME),
        STR_ID_DTCNT_RENAME,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_DataAccount_Display.DataAccountName),
        BufferSize,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH);
    SetInlineFullScreenEditCustomFunction(wgui_inline_items + GPRS_DATA_ACCOUNT_NAME, DataAccountFullLineEditScreen);

    /* micha0202 */
    BufferSize = MAX_GPRS_MMI_APN_LEN + 1;

    SetInlineItemFullScreenEdit(
        (wgui_inline_items + GPRS_DATA_ACCOUNT_APN),
        STR_ID_DTCNT_GPRS_APN,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_DataAccount_Display.APN),
        BufferSize,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(wgui_inline_items + GPRS_DATA_ACCOUNT_APN, DataAccountFullLineEditScreen);

    BufferSize = MAX_GPRS_USERNAME + 1;

    SetInlineItemFullScreenEdit(
        (wgui_inline_items + GPRS_DATA_ACCOUNT_USER_NAME),
        STR_ID_DTCNT_USER_NAME,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_DataAccount_Display.UserName),
        BufferSize,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(
        wgui_inline_items + GPRS_DATA_ACCOUNT_USER_NAME,
        DataAccountFullLineEditScreen);

    BufferSize = MAX_GPRS_USERPASSWD + 1;
    SetInlineItemFullScreenEdit(
        (wgui_inline_items + GPRS_DATA_ACCOUNT_PASSWD),
        STR_ID_DTCNT_PASSWD,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_DataAccount_Display.Passwd),
        BufferSize,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(wgui_inline_items + GPRS_DATA_ACCOUNT_PASSWD, DataAccountFullLineEditScreen);

    /* SetInlineItemIP4((wgui_inline_items+GPRS_DATA_ACCOUNT_DNS_ADDRESS),(U8*)g_DataAccount_Display.IP1,(U8*)g_DataAccount_Display.IP2,(U8*)g_DataAccount_Display.IP3,(U8*)g_DataAccount_Display.IP4,PreparedIPAddressString); */
}


/*****************************************************************************
 * FUNCTION
 *  VerifyGPRSDataAcountChanges
 * DESCRIPTION
 *  verify changes in GPRS editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 VerifyGPRSDataAcountChanges(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = g_DataAccount_Display.GPRSCurrSelectItem;
    S8 UserName_UCS2[(MAX_GPRS_USERNAME + 1) * ENCODING_LENGTH];
    S8 Passwd_UCS2[(MAX_GPRS_USERPASSWD + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((PS8) UserName_UCS2, (PS8) g_GPRS_DataAccount[i].UserName);
    mmi_asc_to_ucs2((PS8) Passwd_UCS2, (PS8) g_GPRS_DataAccount[i].Passwd);

    if (mmi_ucs2cmp((PS8) g_GPRS_DataAccount[i].DataAccountName, (PS8) g_DataAccount_Display.DataAccountName))
    {
        return TRUE;
    }

    if (mmi_ucs2cmp((PS8) g_GPRS_DataAccount[i].APN, (PS8) g_DataAccount_Display.APN))
    {
        return TRUE;
    }

    if (mmi_ucs2cmp((PS8) UserName_UCS2, (PS8) g_DataAccount_Display.UserName))
    {
        return TRUE;
    }

    if (mmi_ucs2cmp((PS8) Passwd_UCS2, (PS8) g_DataAccount_Display.Passwd))
    {
        return TRUE;
    }

    if (((S32) g_GPRS_DataAccount[i].AuthType) != g_DataAccount_Display.AuthType)
    {
        return TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryDTCNTGPRSSave
 * DESCRIPTION
 *  confirm window for saving GPRS account item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryDTCNTGPRSSave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(GPRSDataAccountSaveChanges, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoToMainDataAccountScreen, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  GPRSDataAccountSaveChanges
 * DESCRIPTION
 *  prepare GPRS data account content to be saved
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GPRSDataAccountSaveChanges(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = g_DataAccount_Display.GPRSCurrSelectItem;
    S8 AccountNameStr[30 * ENCODING_LENGTH];    /* Assumption:  string "Data Account " length < 30 */

    //micha0901
    //DNS menu is currently disabled
#if (0)
/* under construction !*/
#endif /* (0) */ 

    /* micha1103 begin */
    U8 PrevIfdcs = 0;
    S32 WordCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);

    PrevIfdcs = g_GPRS_DataAccount[i].iFdcs;

    memset(&g_GPRS_DataAccount[i], '\0', sizeof(GPRSDataAccountNode));

    /*WordCount = GetInlineEditUCS2Count(&wgui_inline_items[1]);*/

    if(mmi_dtcnt_check_UCS2((U16*)g_DataAccount_Display.DataAccountName, (U16)mmi_ucs2strlen((PS8)g_DataAccount_Display.DataAccountName)))
    {
        WordCount = -1;
    }
    else
    {
        WordCount = 0;
    }

    if (WordCount < 0)
    {
        g_GPRS_DataAccount[i].iFdcs = mmi_ucs2strlen((PS8) g_DataAccount_Display.DataAccountName);
    }
    else
    {
        g_GPRS_DataAccount[i].iFdcs = (U8) WordCount;
    }

    /* micha1103 end */

    SetDynaDataAccountName(AccountNameStr, g_DataAccount_Display.GPRSCurrSelectItem);

    /* micha0307 */
    if (mmi_ucs2strlen((PS8) g_DataAccount_Display.DataAccountName) == 0)
    {
        mmi_ucs2cpy((PS8) g_GPRS_DataAccount[i].DataAccountName, (PS8) AccountNameStr);
        g_GPRS_DataAccount[i].iFdcs = mmi_ucs2strlen((PS8) g_GPRS_DataAccount[i].DataAccountName);
    }
    else
    {
        mmi_ucs2cpy((PS8) g_GPRS_DataAccount[i].DataAccountName, (PS8) g_DataAccount_Display.DataAccountName);
    }

    mmi_ucs2cpy((PS8) g_GPRS_DataAccount[i].APN, (PS8) g_DataAccount_Display.APN);
    mmi_ucs2_to_asc((PS8) g_GPRS_DataAccount[i].UserName, (PS8) g_DataAccount_Display.UserName);
    mmi_ucs2_to_asc((PS8) g_GPRS_DataAccount[i].Passwd, (PS8) g_DataAccount_Display.Passwd);

    /* DNS menu is currently disabled */
#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 

    g_GPRS_DataAccount[i].AuthType = (U8) g_DataAccount_Display.AuthType;
    g_GPRS_DataAccount[i].Present = 'P';

    DTCNTGPRSSetAccountReq(i);

}


/*****************************************************************************
 * FUNCTION
 *  DTCNTGPRSSetAccountReq
 * DESCRIPTION
 *  set GPRS data account through L4
 * PARAMETERS
 *  ItemNum     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DTCNTGPRSSetAccountReq(U8 ItemNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __PS_SERVICE__

    mmi_ps_set_gprs_data_account_req_struct *myMsgPtr;

    /* micha0820 */
    U8 ref_count;
    U16 msg_len;

    MYQUEUE Message;
    U8 DataAccountName_ASCII[(MAX_GPRS_DATAACCOUNT_NAME + 1) * ENCODING_LENGTH];
    U8 DataAccountAPN_ASCII[MAX_APN_LEN];
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ItemNum >= MAX_DATA_ACCOUNT_GPRS_LIMIT)
    {
        return;
    }

    memset(DataAccountName_ASCII, '\0', (MAX_GPRS_DATAACCOUNT_NAME + 1) * ENCODING_LENGTH);
    memset(DataAccountAPN_ASCII, '\0', MAX_APN_LEN);

    myMsgPtr =
        (mmi_ps_set_gprs_data_account_req_struct*)
        OslConstructDataPtr(sizeof(mmi_ps_set_gprs_data_account_req_struct));

    /* micha0820 */
    ref_count = myMsgPtr->ref_count;
    msg_len = myMsgPtr->msg_len;
    memset(myMsgPtr, '\0', sizeof(mmi_ps_set_gprs_data_account_req_struct));
    myMsgPtr->ref_count = ref_count;
    myMsgPtr->msg_len = msg_len;

    myMsgPtr->gprs_account.context_id = ItemNum + 1;
    myMsgPtr->gprs_account.authentication_type = g_GPRS_DataAccount[ItemNum].AuthType;

    if (g_GPRS_DataAccount[ItemNum].iFdcs > 0)
    {
        g_GPRS_DataAccount[ItemNum].iFdcs = mmi_ucs2strlen((PS8) g_GPRS_DataAccount[ItemNum].DataAccountName) * ENCODING_LENGTH;
        myMsgPtr->gprs_account.name_length = g_GPRS_DataAccount[ItemNum].iFdcs;
        myMsgPtr->gprs_account.name_dcs = DATA_ACCOUNT_UCS; /* 0x8 */
        i = 0;
        while (i != g_GPRS_DataAccount[ItemNum].iFdcs)
        {
            myMsgPtr->gprs_account.name[i] = g_GPRS_DataAccount[ItemNum].DataAccountName[i + 1];
            myMsgPtr->gprs_account.name[i + 1] = g_GPRS_DataAccount[ItemNum].DataAccountName[i];
            i += 2;
        }
        myMsgPtr->gprs_account.name[i] = '\0';
        myMsgPtr->gprs_account.name[i + 1] = '\0';
    }
    else
    {
        myMsgPtr->gprs_account.name_dcs = DATA_ACCOUNT_ASCII;
        mmi_ucs2_to_asc((PS8) DataAccountName_ASCII, (PS8) g_GPRS_DataAccount[ItemNum].DataAccountName);
        myMsgPtr->gprs_account.name_length = strlen((PS8) DataAccountName_ASCII);
        memcpy(myMsgPtr->gprs_account.name, DataAccountName_ASCII, strlen((PS8) DataAccountName_ASCII));
        g_GPRS_DataAccount[ItemNum].iFdcs = 0;
    }

    mmi_ucs2_to_asc((PS8) DataAccountAPN_ASCII, (PS8) g_GPRS_DataAccount[ItemNum].APN);
    /* micha0202 */
    memcpy(myMsgPtr->gprs_account.apn, DataAccountAPN_ASCII, strlen((PS8) DataAccountAPN_ASCII) + 1);
    myMsgPtr->gprs_account.apn_length = strlen((PS8) DataAccountAPN_ASCII);

    memcpy(
        myMsgPtr->gprs_account.user_name,
        g_GPRS_DataAccount[ItemNum].UserName,
        strlen((PS8) g_GPRS_DataAccount[ItemNum].UserName) + 1);

    memcpy(
        myMsgPtr->gprs_account.password,
        g_GPRS_DataAccount[ItemNum].Passwd,
        strlen((PS8) g_GPRS_DataAccount[ItemNum].Passwd) + 1);

    for (i = 0; i < 4; i++)
    {
        myMsgPtr->gprs_account.dns[i] = 0;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(DTCNTGPRSSetAccountRsp, PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP);
    OslMsgSendExtQueue(&Message);
    ClearInputEventHandler(MMI_DEVICE_ALL);

#endif /* __PS_SERVICE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  DTCNTGPRSSetAccountRsp
 * DESCRIPTION
 *  message handler for mmi_ps_set_gprs_data_account_rsp_struct
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void DTCNTGPRSSetAccountRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __PS_SERVICE__

    mmi_ps_set_gprs_data_account_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_ps_set_gprs_data_account_rsp_struct*) info;

    if (localPtr->result == KAL_TRUE /* OK */ )
    {
        g_GPRS_DataAccount[g_DataAccount_Display.GPRSCurrSelectItem].Present = 'P';
        ShowDataAccountOKMessage();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        /* micha0427 */
        DeleteScreenIfPresent(SCR_ID_DTCNT_GPRS_EDIT);
    }

#endif /* __PS_SERVICE__ */ 
}

#endif /* __MMI_GPRS_FEATURES__ */ 

#ifdef OBIGO_Q03C
/*****************************************************************************
 * FUNCTION
 *  mmi_ps_dtcnt_list_ind_handler
 * DESCRIPTION
 *  message handler for mmi_ps_set_gprs_data_account_rsp_struct
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ps_dtcnt_list_ind_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_ps_dtcnt_list_ind_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_ps_dtcnt_list_ind_struct*) info;

    MMI_TRACE(TRACE_GROUP_6, MMI_DTCNT_PS_LIST_IND, localPtr->app_id, localPtr->bearer_scope,localPtr->num_id);

    if (localPtr->app_id == DTCNT_LIST_BY_APP_OK)
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_CONFIRM);
        DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_BY_APP);
        DeleteScreenIfPresent(SCR_ID_DTCNT_LIST);
#ifdef __MMI_GPRS_FEATURES__
        DeleteScreenIfPresent(SCR_ID_DTCNT_GPRS_LIST);
#endif /* __MMI_GPRS_FEATURES__ */
        GoBackHistory();
        return;
    }

    memset(&g_dtcnt_list_cnt, 0, sizeof(dtcnt_list_by_app_struct));

    g_dtcnt_list_cnt.appid = localPtr->app_id;
    g_dtcnt_list_cnt.bearer_scrope = localPtr->bearer_scope;
    g_dtcnt_list_cnt.menu_id = localPtr->menu_id;
    g_dtcnt_list_cnt.num_id = localPtr->num_id;
    g_dtcnt_list_cnt.bearer_type[0] = localPtr->bearer_type[0];
    g_dtcnt_list_cnt.bearer_type[1] = localPtr->bearer_type[1];

    if(g_dtcnt_list_cnt.bearer_type[0] == DATA_ACCOUNT_BEARER_CSD)
    {
        g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_CSD] = localPtr->net_id[0];
        g_dtcnt_list_cnt.sim_info = always_ask_get_sim_info_data_account(localPtr->net_id[0]);
        g_dtcnt_list_cnt.app_id = always_ask_get_app_id_data_account(localPtr->net_id[0]);
    }
    else if(g_dtcnt_list_cnt.bearer_type[1] == DATA_ACCOUNT_BEARER_CSD)
    {
        g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_CSD] = localPtr->net_id[1];
        g_dtcnt_list_cnt.sim_info = always_ask_get_sim_info_data_account(localPtr->net_id[1]);
        g_dtcnt_list_cnt.app_id = always_ask_get_app_id_data_account(localPtr->net_id[1]);
    }

    if(g_dtcnt_list_cnt.bearer_type[0] == DATA_ACCOUNT_BEARER_GPRS)
    {
        g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_GPRS] = localPtr->net_id[0];
        g_dtcnt_list_cnt.sim_info = always_ask_get_sim_info_data_account(localPtr->net_id[0]);
        g_dtcnt_list_cnt.app_id = always_ask_get_app_id_data_account(localPtr->net_id[0]);
    }
    else if(g_dtcnt_list_cnt.bearer_type[1] == DATA_ACCOUNT_BEARER_GPRS)
    {
        g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_GPRS] = localPtr->net_id[1];
        g_dtcnt_list_cnt.sim_info = always_ask_get_sim_info_data_account(localPtr->net_id[1]);
        g_dtcnt_list_cnt.app_id = always_ask_get_app_id_data_account(localPtr->net_id[1]);
    }

    /*check para first*/
    mmi_dtcnt_list_check_app_para();
    mmi_ps_dtcnt_main_list();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_check_app_para
 * DESCRIPTION
 *  message handler for mmi_ps_set_gprs_data_account_rsp_struct
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_dtcnt_list_check_app_para(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_dtcnt_list_cnt.num_id == 2)
    {
        g_dtcnt_list_cnt.highlight_gprs_csd = TRUE;
    }
    else
    {
        if(g_dtcnt_list_cnt.bearer_type[0] == DATA_ACCOUNT_BEARER_CSD)
        {
            g_dtcnt_list_cnt.highlight_csd = TRUE;
        }
        else if(g_dtcnt_list_cnt.bearer_type[0] == DATA_ACCOUNT_BEARER_GPRS)
        {
            g_dtcnt_list_cnt.highlight_gprs = TRUE;
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ps_dtcnt_list_ind_handler
 * DESCRIPTION
 *  message handler for mmi_ps_set_gprs_data_account_rsp_struct
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_ps_dtcnt_main_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlight_index = 0;
    U8 list_num = 0;
    U8 *guiBuffer = NULL;
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_dtcnt_list_cnt.entry_gprs_list_num = 0;
    g_dtcnt_list_cnt.switch_bearer_flag = FALSE;

    EntryNewScreen(SCR_ID_DTCNT_LIST_BY_APP, NULL, mmi_ps_dtcnt_main_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_LIST_BY_APP);
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    if(g_dtcnt_list_cnt.bearer_scrope & DATA_ACCOUNT_BEARER_ALWAYS_ASK)
    {
        nStrItemList[list_num] = STR_ID_DTCNT_ALWAYS_ASK;
        g_dtcnt_list_cnt.bearer_list[list_num] = DTCNT_LIST_BEARER_ALWAYS_ASK;
        if(g_dtcnt_list_cnt.num_id == 1 && g_dtcnt_list_cnt.bearer_type[0] & DATA_ACCOUNT_BEARER_ALWAYS_ASK)
        {
            highlight_index = list_num;
        }
        list_num++;
    }
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */

#ifdef __MMI_WLAN_FEATURES__
    if (( g_dtcnt_list_cnt.bearer_scrope & DATA_ACCOUNT_BEARER_CSD )
        && (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY))
#else
    if ( g_dtcnt_list_cnt.bearer_scrope & DATA_ACCOUNT_BEARER_CSD )
#endif /* __MMI_WLAN_FEATURES__ */
    {
        nStrItemList[list_num] = SERVICES_DATA_CONNECT_GSM_STRING_ID;
        g_dtcnt_list_cnt.bearer_list[list_num] = DTCNT_LIST_BEARER_CSD;
        if(g_dtcnt_list_cnt.num_id == 1 && g_dtcnt_list_cnt.bearer_type[0] & DATA_ACCOUNT_BEARER_CSD)
        {
            highlight_index = list_num;
        }
        list_num++;
    }
#ifdef __MMI_GPRS_FEATURES__
#ifdef __MMI_WLAN_FEATURES__
    if(( g_dtcnt_list_cnt.bearer_scrope & DATA_ACCOUNT_BEARER_GPRS )
        && (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY))
#else
    if( g_dtcnt_list_cnt.bearer_scrope & DATA_ACCOUNT_BEARER_GPRS )
#endif /* __MMI_WLAN_FEATURES__ */
    {
        nStrItemList[list_num] = SERVICES_DATA_CONNECT_GPRS_STRING_ID;
        g_dtcnt_list_cnt.bearer_list[list_num] = DTCNT_LIST_BEARER_GPRS;
        if(g_dtcnt_list_cnt.num_id == 1 && g_dtcnt_list_cnt.bearer_type[0] & DATA_ACCOUNT_BEARER_GPRS)
        {
            highlight_index = list_num;
        }
        list_num++;
    }
#ifdef __MMI_WLAN_FEATURES__
    if(( g_dtcnt_list_cnt.bearer_scrope & DATA_ACCOUNT_BEARER_GPRS_CSD )
        && (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY))
#else
    if( g_dtcnt_list_cnt.bearer_scrope & DATA_ACCOUNT_BEARER_GPRS_CSD ) 
#endif /* __MMI_WLAN_FEATURES__ */
    {
        nStrItemList[list_num] = STR_ID_DTCNT_BEARER_GPRS_CSD;
        g_dtcnt_list_cnt.bearer_list[list_num] = DTCNT_LIST_BEARER_GPRS_CSD;
        if(g_dtcnt_list_cnt.num_id == 2)
        {
            highlight_index = list_num;
        }
        list_num++;
    }
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __MMI_WLAN_FEATURES__
    if(( g_dtcnt_list_cnt.bearer_scrope & DATA_ACCOUNT_BEARER_WIFI ) &&
        (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY))
    {
        nStrItemList[list_num] = SERVICES_DATA_CONNECT_WLAN_STRING_ID;
        g_dtcnt_list_cnt.bearer_list[list_num] = DTCNT_LIST_BEARER_WIFI;
        if(g_dtcnt_list_cnt.num_id == 1 && g_dtcnt_list_cnt.bearer_type[0] & DATA_ACCOUNT_BEARER_WIFI)
        {
            highlight_index = list_num;
        }
        list_num++;
    }
#endif /*__MMI_WLAN_FEATURES__*/

    RegisterHighlightHandler(mmi_dtcnt_list_highlight_hdlr);
    
    ShowCategory52Screen(
        STR_GLOBAL_DATA_ACCOUNT,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        list_num,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        highlight_index,
        guiBuffer);
    
    SetLeftSoftkeyFunction(mmi_dtcnt_list_show, KEY_EVENT_UP);
    SetKeyHandler(mmi_dtcnt_list_show, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtcnt_list_cnt.index = (U8)nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bearer;
    U32 acct_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    bearer = g_dtcnt_list_cnt.bearer_list[g_dtcnt_list_cnt.index];

    MMI_TRACE(TRACE_GROUP_6, MMI_DTCNT_PS_LIST_SHOW_BEARER, bearer);
    
    switch(bearer)
    {
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    case DTCNT_LIST_BEARER_ALWAYS_ASK:
        g_dtcnt_list_cnt.num_id = 1;
        g_dtcnt_list_cnt.always_ask_flag = TRUE;
        /**/
        acct_id = DTCNT_ALWAYS_ASK_ID;
        acct_id = always_ask_encode_data_account_id(acct_id, g_dtcnt_list_cnt.sim_info, g_dtcnt_list_cnt.app_id, TRUE);
        mmi_dtcnt_list_callback_always_ask(acct_id);
        break;
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */

    case DTCNT_LIST_BEARER_CSD:
        g_dtcnt_list_cnt.num_id = 1;
        g_dtcnt_list_cnt.csd_bearer_flag = TRUE;
        if(g_dtcnt_list_cnt.highlight_csd)
        {
            mmi_dtcnt_select_highlight_handler(g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_CSD], DATA_ACCOUNT_BEARER_CSD);
            mmi_dtcnt_select_account_option(mmi_dtcnt_list_callback_csd, 
                                            g_dtcnt_list_cnt.menu_id, 
                                            DATA_ACCOUNT_BEARER_CSD, 
                                            DTCNT_SELECT_NO_SIM, 
                                            DTCNT_SELECT_NO_ALWAYS_ASK);
        }
        else
        {
            mmi_dtcnt_select_highlight_handler(0, DATA_ACCOUNT_BEARER_CSD);
            mmi_dtcnt_select_account_option(mmi_dtcnt_list_callback_csd, 
                                            g_dtcnt_list_cnt.menu_id, 
                                            DATA_ACCOUNT_BEARER_CSD, 
                                            DTCNT_SELECT_NO_SIM, 
                                            DTCNT_SELECT_NO_ALWAYS_ASK);
        }
    	break;
#ifdef __MMI_GPRS_FEATURES__
    case DTCNT_LIST_BEARER_GPRS:
        g_dtcnt_list_cnt.num_id = 1;
        g_dtcnt_list_cnt.gprs_bearer_flag = TRUE;
        if(g_dtcnt_list_cnt.highlight_gprs)
        {
            mmi_dtcnt_select_highlight_handler(g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_GPRS], DATA_ACCOUNT_BEARER_GPRS);
            mmi_dtcnt_select_account_option(mmi_dtcnt_list_callback_gprs, 
                                            g_dtcnt_list_cnt.menu_id, 
                                            DATA_ACCOUNT_BEARER_GPRS,
                                            DTCNT_SELECT_NO_SIM, 
                                            DTCNT_SELECT_NO_ALWAYS_ASK);
        }
        else
        {
            mmi_dtcnt_select_highlight_handler(10, DATA_ACCOUNT_BEARER_GPRS);
            mmi_dtcnt_select_account_option(mmi_dtcnt_list_callback_gprs, 
                                            g_dtcnt_list_cnt.menu_id, 
                                            DATA_ACCOUNT_BEARER_GPRS,
                                            DTCNT_SELECT_NO_SIM, 
                                            DTCNT_SELECT_NO_ALWAYS_ASK);
        }
    	break;

    case DTCNT_LIST_BEARER_GPRS_CSD:
        g_dtcnt_list_cnt.num_id = 2;
        g_dtcnt_list_cnt.switch_bearer_flag = TRUE;
        DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_CONFIRM);
        mmi_dtcnt_list_by_app_confirm(STR_ID_DTCNT_SELECT_GPRS, mmi_dtcnt_list_by_app_confirm_gprs);
        break;
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __MMI_WLAN_FEATURES__
    case DTCNT_LIST_BEARER_WIFI:
        g_dtcnt_list_cnt.num_id = 1;
        g_dtcnt_list_cnt.wifi_bearer_flag = TRUE;
        mmi_dtcnt_list_callback_wifi(DTCNT_WIFI_ID);
        break;
#endif /* __MMI_WLAN_FEATURES__ */
    default:
        ASSERT(0);
        break;
    }

}

#ifdef __CBM_ALWAYS_ASK_FEATURE__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_callback_wifi
 * DESCRIPTION
 *  message handler for mmi_ps_set_gprs_data_account_rsp_struct
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_callback_always_ask(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("list_callback_always_ask, net_id=%d", index);

    //MMI_TRACE(TRACE_GROUP_6, MMI_DTCNT_GPRS_SET_REQ);
    g_dtcnt_list_cnt.net_id[0] = index;
    mmi_dtcnt_send_msg2ps();
}
#endif /*__CBM_ALWAYS_ASK_FEATURE__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_by_app_confirm
 * DESCRIPTION
 *  Common function to display confirmation screem
 * PARAMETERS
 *  msg             [IN]        String index of message to be displayed in confirmation screen
 *  lskFuncPtr      [IN]        LSK handler of the confirmation screen
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_by_app_confirm(U16 msg, FuncPtr lskFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtcnt_list_cnt.curr_msg = msg;
    g_dtcnt_list_cnt.curr_lskFuncPtr = lskFuncPtr;

    mmi_dtcnt_list_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_by_app_confirm
 * DESCRIPTION
 *  Common function to display confirmation screem
 * PARAMETERS
 *  msg             [IN]        String index of message to be displayed in confirmation screen
 *  lskFuncPtr      [IN]        LSK handler of the confirmation screen
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    EntryNewScreen(SCR_ID_DTCNT_LIST_CONFIRM, NULL, mmi_dtcnt_list_confirm, NULL);
    
    ShowCategory164Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        g_dtcnt_list_cnt.curr_msg,
        IMG_GLOBAL_QUESTION,
        NULL);
    
    SetLeftSoftkeyFunction(g_dtcnt_list_cnt.curr_lskFuncPtr, KEY_EVENT_UP);
    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_by_app_confirm_csd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_by_app_confirm_csd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_dtcnt_list_cnt.highlight_gprs_csd)
    {
        mmi_dtcnt_select_highlight_handler(g_dtcnt_list_cnt.net_id[0], DATA_ACCOUNT_BEARER_CSD);
        mmi_dtcnt_select_account_option(mmi_dtcnt_list_callback_csd, 
                                        g_dtcnt_list_cnt.menu_id, 
                                        DATA_ACCOUNT_BEARER_CSD, 
                                        DTCNT_SELECT_NO_SIM, 
                                        DTCNT_SELECT_NO_ALWAYS_ASK);
    }
    else
    {
        mmi_dtcnt_select_highlight_handler(0, DATA_ACCOUNT_BEARER_CSD);
        mmi_dtcnt_select_account_option(mmi_dtcnt_list_callback_csd, g_dtcnt_list_cnt.menu_id, DATA_ACCOUNT_BEARER_CSD, DTCNT_SELECT_NO_SIM, DTCNT_SELECT_NO_ALWAYS_ASK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_by_app_confirm_gprs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_by_app_confirm_gprs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtcnt_list_cnt.switch_bearer_flag = TRUE;
    if(g_dtcnt_list_cnt.highlight_gprs_csd)
    {
        mmi_dtcnt_select_highlight_handler(g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_GPRS], DATA_ACCOUNT_BEARER_GPRS);
        mmi_dtcnt_select_account_option(mmi_dtcnt_list_callback_gprs, 
                                        g_dtcnt_list_cnt.menu_id, 
                                        DATA_ACCOUNT_BEARER_GPRS,
                                        DTCNT_SELECT_NO_SIM, 
                                        DTCNT_SELECT_NO_ALWAYS_ASK);
    }
    else
    {
        mmi_dtcnt_select_highlight_handler(10, DATA_ACCOUNT_BEARER_GPRS);
        mmi_dtcnt_select_account_option(mmi_dtcnt_list_callback_gprs, 
                                        g_dtcnt_list_cnt.menu_id, 
                                        DATA_ACCOUNT_BEARER_GPRS,
                                        DTCNT_SELECT_NO_SIM, 
                                        DTCNT_SELECT_NO_ALWAYS_ASK);
    }
}

#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_callback_wifi
 * DESCRIPTION
 *  message handler for mmi_ps_set_gprs_data_account_rsp_struct
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_callback_wifi(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtcnt_list_cnt.net_id[0] = index;
    mmi_dtcnt_send_msg2ps();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_callback_csd
 * DESCRIPTION
 *  message handler for mmi_ps_set_gprs_data_account_rsp_struct
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_callback_csd(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_DataAccount_Display.app_call)
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
    }
    g_dtcnt_list_cnt.switch_bearer_flag = FALSE;
    g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_CSD] = index;
    mmi_dtcnt_send_msg2ps();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_list_callback
 * DESCRIPTION
 *  message handler for mmi_ps_set_gprs_data_account_rsp_struct
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_list_callback_gprs(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_GPRS] = index;

    if(g_DataAccount_Display.app_call)
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
    }
    if(!g_dtcnt_list_cnt.switch_bearer_flag)
    {
        mmi_dtcnt_send_msg2ps();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_send_msg2ps
 * DESCRIPTION
 *  message handler for mmi_ps_set_gprs_data_account_rsp_struct
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_send_msg2ps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_dtcnt_list_rsp_struct *myMsgPtr;
    MYQUEUE Message;
    U8 ref_count;
    U16 msg_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (mmi_ps_dtcnt_list_rsp_struct*)
        OslConstructDataPtr(sizeof(mmi_ps_dtcnt_list_rsp_struct));
    
    ref_count = myMsgPtr->ref_count;
    msg_len = myMsgPtr->msg_len;
    memset(myMsgPtr, '\0', sizeof(mmi_ps_dtcnt_list_rsp_struct));
    myMsgPtr->ref_count = ref_count;
    myMsgPtr->msg_len = msg_len;

    myMsgPtr->app_id = g_dtcnt_list_cnt.appid;
    if(g_dtcnt_list_cnt.num_id == 1)
    {
        if(g_dtcnt_list_cnt.csd_bearer_flag)
        {
            g_dtcnt_list_cnt.bearer_type[0] = DATA_ACCOUNT_BEARER_CSD;
            myMsgPtr->net_id[0] = always_ask_encode_data_account_id(g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_CSD], g_dtcnt_list_cnt.sim_info, g_dtcnt_list_cnt.app_id, FALSE);
        }
        else if(g_dtcnt_list_cnt.gprs_bearer_flag)
        {
            g_dtcnt_list_cnt.bearer_type[0] = DATA_ACCOUNT_BEARER_GPRS;
            myMsgPtr->net_id[0] = always_ask_encode_data_account_id(g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_GPRS], g_dtcnt_list_cnt.sim_info, g_dtcnt_list_cnt.app_id, FALSE);
        }
        else if(g_dtcnt_list_cnt.wifi_bearer_flag)
        {
            g_dtcnt_list_cnt.bearer_type[0] = DATA_ACCOUNT_BEARER_WIFI;
            myMsgPtr->net_id[0] = g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_CSD];
        }
        else if(g_dtcnt_list_cnt.always_ask_flag)
        {
            g_dtcnt_list_cnt.bearer_type[0] = DATA_ACCOUNT_BEARER_ALWAYS_ASK;
            myMsgPtr->net_id[0] = always_ask_encode_data_account_id(g_dtcnt_list_cnt.net_id[0], g_dtcnt_list_cnt.sim_info, g_dtcnt_list_cnt.app_id, TRUE);
        }
        myMsgPtr->bearer_type[DTCNT_LIST_BEARER_CSD] = g_dtcnt_list_cnt.bearer_type[0];
        myMsgPtr->bearer_scope = g_dtcnt_list_cnt.bearer_type[0]; 
    }
    else if(g_dtcnt_list_cnt.num_id == 2)
    {
        myMsgPtr->bearer_type[DTCNT_LIST_BEARER_CSD] = DATA_ACCOUNT_BEARER_CSD;
        myMsgPtr->bearer_type[DTCNT_LIST_BEARER_GPRS] = DATA_ACCOUNT_BEARER_GPRS;
    
        myMsgPtr->net_id[DTCNT_LIST_BEARER_CSD] = always_ask_encode_data_account_id(g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_CSD], g_dtcnt_list_cnt.sim_info, g_dtcnt_list_cnt.app_id, FALSE);
        myMsgPtr->net_id[DTCNT_LIST_BEARER_GPRS] = always_ask_encode_data_account_id(g_dtcnt_list_cnt.net_id[DTCNT_LIST_BEARER_GPRS], g_dtcnt_list_cnt.sim_info, g_dtcnt_list_cnt.app_id, FALSE);
        myMsgPtr->bearer_scope = DATA_ACCOUNT_BEARER_GPRS_CSD;
    }
    
    myMsgPtr->num_id = g_dtcnt_list_cnt.num_id;
    myMsgPtr->result = TRUE;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_MMI_PS_DTCNT_LIST_RSP;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    ClearInputEventHandler(MMI_DEVICE_ALL);
}
#endif /* OBIGO_Q03C */

/************************************************************************/
/* for Dual-Sim                                                         */
/************************************************************************/
//#ifdef __MMI_DUAL_SIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_entry_account_select_ext
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_entry_account_select_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem = 0;                 /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    for (i = 0; g_dtcnt_selections_dual[i].bearer > 0; i++)
    {
        if (g_DataAccount_Display.bearers & g_dtcnt_selections_dual[i].bearer)
        {
            nStrItemList[nNumofItem] = g_dtcnt_selections_dual[i].name;
            g_DataAccount_Display.bearer_callbacks[nNumofItem] = g_dtcnt_selections_dual[i].func;
            nNumofItem++;
            
        }
    }

    if(nNumofItem == 1)
    {
        g_DataAccount_Display.bearer_callbacks[0]();
        return;
    }
    
    EntryNewScreen(SCR_ID_DTCNT_LIST_DUAL_SIM, NULL, mmi_dtcnt_entry_account_select_ext, NULL);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_LIST_DUAL_SIM);

    RegisterHighlightHandler(mmi_dtcnt_account_select_highlight_hdlr);

    ShowCategory52Screen(
        SERVICES_DATA_CONNECT_MAIN_STRING_ID,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_dtcnt_account_select_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_dtcnt_account_select_ok, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_select_sim1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_select_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sim_info = MMI_DATA_ACCOUNT_SIM1;
    mmi_dtcnt_entry_account_select_ext();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_select_sim2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_select_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sim_info = MMI_DATA_ACCOUNT_SIM2;
    mmi_dtcnt_entry_account_select_ext();
}
//#endif /* __MMI_DUAL_SIM__ */


/************************************************************************/
/* for Always Ask                                                       */
/************************************************************************/
#ifdef __CBM_ALWAYS_ASK_FEATURE__

/*****************************************************************************
 * FUNCTION
 *  mmi_always_ask_delete_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_always_ask_delete_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
    if(GetActiveScreenId() != SCR_ID_DTCNT_LIST_ALWAYS_ASK)
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
    }
    
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_always_ask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_always_ask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 acct_id = DTCNT_ALWAYS_ASK_ID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    acct_id = always_ask_encode_data_account_id(acct_id, MMI_DATA_ACCOUNT_SIM1, 0, TRUE);

    /* return the encode acct id */
    if(g_DataAccount_Display.app_callback)
    {
        g_DataAccount_Display.app_callback((U32) acct_id);
        g_DataAccount_Display.app_callback = NULL;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_wlan_connect_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_wlan_connect_result(U8 wifi_connect_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("$$$$$ CBM always ask wifi cnf result = %d $$$$$", wifi_connect_result);

    abm_bearer2nw_id(ABM_E_SOCKET_BEARER_WIFI, 0, &id);
    if(g_DataAccount_Display.app_callback_ext)
    {
        g_always_ask_screen_del_handler_flag = TRUE;
        g_DataAccount_Display.app_callback_ext(id, wifi_connect_result);
        g_DataAccount_Display.app_callback_ext = NULL;
    }
}
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */

/************************************************************************/
/* for dual-sim || always ask feature common apis                       */
/************************************************************************/
//#if defined (__CBM_ALWAYS_ASK_FEATURE__) || defined (__MMI_DUAL_SIM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_bearer_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearers     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dtcnt_select_account_option(FuncPtrU32 callback, U16 AppMenuID, U8 bearers, dtcnt_select_type_enum sim_info, dtcnt_select_type_enum always_ask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.app_callback = callback;
    g_DataAccount_Display.app_callback_ext = NULL;
    g_DataAccount_Display.AppMenuID = AppMenuID;
    g_DataAccount_Display.CurrAppMainSelectItem = 0;
    g_DataAccount_Display.bearers = bearers;
    
    g_DataAccount_Display.sim_info = sim_info;
    g_DataAccount_Display.always_ask = always_ask;
    g_DataAccount_Display.app_call = TRUE;
    mmi_dtcnt_select_account_entry_option();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_select_account_option_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearers     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dtcnt_select_account_option_ext(FuncPtrU32Ext callback, U16 AppStrID, U16 AppMenuID, U8 bearers, dtcnt_select_type_enum sim_info, dtcnt_select_type_enum always_ask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_DataAccount_Display.app_callback_ext = callback;
    g_DataAccount_Display.app_callback = NULL;
    g_DataAccount_Display.AppMenuID = AppMenuID;
    g_DataAccount_Display.CurrAppMainSelectItem = 0;
    g_DataAccount_Display.CurrAppSelectItem = 0;
#ifdef __MMI_GPRS_FEATURES__
    g_DataAccount_Display.GPRSCurrAppSelectItem = 0;
#endif /* __MMI_GPRS_FEATURES__ */ 
    g_DataAccount_Display.bearers = bearers;
    
    g_DataAccount_Display.sim_info = sim_info;
    g_DataAccount_Display.always_ask = always_ask;
    g_DataAccount_Display.app_call = FALSE;
    g_DataAccount_Display.app_str_id = AppStrID;
    mmi_dtcnt_select_account_entry_option();

}

/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_always_ask_screen_del_handler
* DESCRIPTION
*  
* PARAMETERS
*  in_param        [?]     
* RETURNS
*  void
*****************************************************************************/
U8 mmi_dtcnt_always_ask_screen_del_handler(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("$$$$$ CBM always ask screen end key handler app_call = %d, del_handler_flag = %d $$$$$", 
        g_DataAccount_Display.app_call, g_always_ask_screen_del_handler_flag);

    if((!g_DataAccount_Display.app_call) && (!g_always_ask_screen_del_handler_flag))
    {
        g_always_ask_screen_del_handler_flag = TRUE;
        if(g_DataAccount_Display.app_callback_ext)
        {
            g_DataAccount_Display.app_callback_ext( 0, FALSE);
            g_DataAccount_Display.app_callback_ext = NULL;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_select_account_entry_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearers     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dtcnt_select_account_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem = 0;                 /* Stores no of children in the submenu */
    U16 str_id;
    U16 title_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_entry_option_back_flag = FALSE;
    g_always_ask_screen_del_handler_flag = FALSE;

#ifndef __CBM_ALWAYS_ASK_FEATURE__
    if(g_DataAccount_Display.always_ask == DTCNT_SELECT_ALWAYS_ASK)
    {
        g_DataAccount_Display.always_ask = DTCNT_SELECT_NO_ALWAYS_ASK;
    }
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */

#ifndef __MMI_DUAL_SIM__
    if(g_DataAccount_Display.sim_info == DTCNT_SELECT_SIM)
    {
        g_DataAccount_Display.sim_info = DTCNT_SELECT_NO_SIM;
    }
#endif /* __MMI_DUAL_SIM__ */

    if((g_DataAccount_Display.sim_info == DTCNT_SELECT_SIM) &&
        (g_DataAccount_Display.always_ask == DTCNT_SELECT_ALWAYS_ASK))
    {
        for (i = 0; g_dtcnt_selections_ext_sim[i].bearer > 0; i++)
        {
#ifdef __CBM_ALWAYS_ASK_FEATURE__
            if(g_dtcnt_selections_ext_sim[i].bearer == DATA_ACCOUNT_ALWAYS_ASK)
            {
                nStrItemList[nNumofItem] = g_dtcnt_selections_ext_sim[i].name;
                g_DataAccount_Display.bearer_callbacks[nNumofItem] = g_dtcnt_selections_ext_sim[i].func;
                nNumofItem++;
            }
            else 
#endif /* __MMI_WLAN_FEATURES__ */
            {
#ifdef __MMI_WLAN_FEATURES__
                if((g_dtcnt_selections_ext_sim[i].bearer == DATA_ACCOUNT_BEARER_WIFI) &&
                    (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY))
                {
                    continue;
                }
                else if((g_dtcnt_selections_ext_sim[i].bearer != DATA_ACCOUNT_BEARER_WIFI) &&
                    (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY))
                {
                    continue;
                }
                else 
#endif /* __MMI_WLAN_FEATURES__ */
                {
                    nStrItemList[nNumofItem] = g_dtcnt_selections_ext_sim[i].name;
                    g_DataAccount_Display.bearer_callbacks[nNumofItem] = g_dtcnt_selections_ext_sim[i].func;
                    nNumofItem++;
                }
            }
        }
    }
    else if((g_DataAccount_Display.sim_info == DTCNT_SELECT_SIM) &&
        (g_DataAccount_Display.always_ask == DTCNT_SELECT_NO_ALWAYS_ASK))
    {
        for (i = CBM_SCREEN_LIST_INDEX; g_dtcnt_selections_ext_sim[i].bearer > 0; i++)
        {
#ifdef __MMI_WLAN_FEATURES__
            if((g_dtcnt_selections_ext_sim[i].bearer == DATA_ACCOUNT_BEARER_WIFI) &&
                (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY))
            {
                continue;
            }
            else if((g_dtcnt_selections_ext_sim[i].bearer != DATA_ACCOUNT_BEARER_WIFI) &&
                (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY))
            {
                continue;
            }
            else 
#endif /* __MMI_WLAN_FEATURES__ */
            {
                nStrItemList[nNumofItem] = g_dtcnt_selections_ext_sim[i].name;
                g_DataAccount_Display.bearer_callbacks[nNumofItem] = g_dtcnt_selections_ext_sim[i].func;
                nNumofItem++;
            }
        }
    }
    else if((g_DataAccount_Display.sim_info == DTCNT_SELECT_NO_SIM) &&
        (g_DataAccount_Display.always_ask == DTCNT_SELECT_ALWAYS_ASK))
    {
        for (i = 0; g_dtcnt_selections_ext[i].bearer > 0; i++)
        {
#ifdef __CBM_ALWAYS_ASK_FEATURE__
            if(g_dtcnt_selections_ext[i].bearer == DATA_ACCOUNT_ALWAYS_ASK)
            {
                nStrItemList[nNumofItem] = g_dtcnt_selections_ext[i].name;
                g_DataAccount_Display.bearer_callbacks[nNumofItem] = g_dtcnt_selections_ext[i].func;
                nNumofItem++;
            }
            else 
#endif /* __MMI_WLAN_FEATURES__ */
                if (g_DataAccount_Display.bearers & g_dtcnt_selections_ext[i].bearer)
                {
#ifdef __MMI_WLAN_FEATURES__
                    if((g_dtcnt_selections_ext[i].bearer == DATA_ACCOUNT_BEARER_WIFI) &&
                        (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY))
                    {
                        continue;
                    }
                    else if((g_dtcnt_selections_ext[i].bearer != DATA_ACCOUNT_BEARER_WIFI) &&
                        (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY))
                    {
                        continue;
                    }
                    else 
#endif /* __MMI_WLAN_FEATURES__ */
                    {
                        nStrItemList[nNumofItem] = g_dtcnt_selections_ext[i].name;
                        g_DataAccount_Display.bearer_callbacks[nNumofItem] = g_dtcnt_selections_ext[i].func;
                        nNumofItem++;
                    }
                }
        }
    }
    else 
    {
        for (i = CBM_SCREEN_LIST_INDEX; g_dtcnt_selections_ext[i].bearer > 0; i++)
        {
            if (g_DataAccount_Display.bearers & g_dtcnt_selections_ext[i].bearer)
            {
#ifdef __MMI_WLAN_FEATURES__
                if((g_dtcnt_selections_ext[i].bearer == DATA_ACCOUNT_BEARER_WIFI) &&
                    (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY))
                {
                    continue;
                }
                else if((g_dtcnt_selections_ext[i].bearer != DATA_ACCOUNT_BEARER_WIFI) &&
                    (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY))
                {
                    continue;
                }
                else 
#endif /* __MMI_WLAN_FEATURES__ */
                {
                    nStrItemList[nNumofItem] = g_dtcnt_selections_ext[i].name;
                    g_DataAccount_Display.bearer_callbacks[nNumofItem] = g_dtcnt_selections_ext[i].func;
                    nNumofItem++;
                }
            }
        }
        if((nNumofItem == 1) && (!g_entry_option_back_flag))
        {
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
            g_DataAccount_Display.bearer_callbacks[0]();
            return;
        }
    }

    EntryNewScreen(SCR_ID_DTCNT_LIST_ALWAYS_ASK, NULL, mmi_dtcnt_select_account_entry_option, NULL);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
    
    SetDelScrnIDCallbackHandler(SCR_ID_DTCNT_LIST_ALWAYS_ASK, (HistoryDelCBPtr) mmi_dtcnt_always_ask_screen_del_handler);

    if(g_DataAccount_Display.app_call)
    {
        str_id = STR_GLOBAL_BACK;
        title_id = SERVICES_DATA_CONNECT_MAIN_STRING_ID;
    }
    else
    {
        str_id = STR_GLOBAL_CANCEL;
        title_id = g_DataAccount_Display.app_str_id;
    }
    RegisterHighlightHandler(mmi_dtcnt_account_select_highlight_hdlr);

    g_entry_option_back_flag = FALSE;
    ShowCategory52Screen(
        title_id,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        str_id,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_dtcnt_account_select_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_dtcnt_account_select_ok, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dtcnt_always_ask_cancel, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_dtcnt_always_ask_cancel, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_bearer_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearers     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dtcnt_always_ask_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_always_ask_screen_del_handler_flag = TRUE;
    if(!g_DataAccount_Display.app_call)
    {
        if(g_DataAccount_Display.app_callback_ext)
        {
            g_DataAccount_Display.app_callback_ext( 0, FALSE);
            g_DataAccount_Display.app_callback_ext = NULL;
        }
        
    }
    GoBackHistory();
}
//#endif /* defined (__CBM_ALWAYS_ASK_FEATURE__) || defined (__MMI_DUAL_SIM__) */

#endif /* __TCPIP__ */ 

