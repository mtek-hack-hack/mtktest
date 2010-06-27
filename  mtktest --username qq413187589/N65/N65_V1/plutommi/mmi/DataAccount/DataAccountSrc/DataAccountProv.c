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
 * DataAccountProv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for handling provisioning settings.
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#include "DataAccountcommon.h"

#ifdef __MMI_CCA_SUPPORT__

#include "protocolevents.h"
#include "conversions.h"
#include "PhoneBookTypes.h"


#include "CentralConfigAgentGProt.h"
#include "CentralConfigAgentDefs.h"

#define DTCNT_ITEM_PRESENT_YES		'P'
#define DTCNT_ITEM_PRESENT_NO		'E'
#define DTCNT_ITEM_DNS_LENGTH		4

#define MAX_NODE_ID_LEN         (64 + 1)

#define DTCNT_OTA_NAPDEF CCA_NS_OMA_NAPDEF
#define DTCNT_OTA_NAPAUTHINFO CCA_NS_OMA_NAPAUTHINFO

typedef struct dtcnt_ota_item_st
{
    struct dtcnt_ota_item_st *next;
    S8 node_id[MAX_NODE_ID_LEN];                        /* UTF-8, 0-ended   */
    U8 bearer;                                             /* If this item is presented */
    S8 name[MAX_DATA_ACCOUNT_NAME_LEN + 1];      /* Name of a Data Account */
#ifdef __PS_SERVICE__
    S8 address[MAX_GPRS_MMI_APN_LEN + 1];    /* GPRS APN */
#else
    S8 address[MAX_DIAL_NUM_LEN + 1];        /* CSD Dial string */
#endif
    S8 UserName[MAX_USER_LEN + 1];                          /* User of a Data Account */
    S8 Passwd[MAX_PASSWD_LEN + 1];                          /* Password for a Data Account */
    U8 AuthType;                                            /* Authentication Type */
    U8 DialType;                                            /* Boolean : 0.Analoue or 1. SDN */
    U8 DataRate;                                            /* Boolean : 0.9.6 kbit/s or 1. 14.4 Kbit/s */
    U8 DnsAddress[MAX_PART_IP_ADDRESS];                     /* DNS IP Address */
    U8 iFdcs;                                               /* DCS indicator for account name. ascii:0, ucs2:length */
    BOOL valid;
} dtcnt_ota_item_struct;

/*
 * Control block for VoIP OTA provisioning. It will be allocated from 256-
 * bytes control buffer pool. The variables 'src_idx' and 'dst_idx' provide 
 * linkage between this->profile[] and g_wlan_prof_list[].
 */
typedef struct dtcnt_ota_context_st
{
    U16 conf_id;                        /* Configuration ID                  */
    S32 doc_hdl;                        /* Configuration document handle     */
    U8 num_installed;                    /* Num of processed profiles         */
    U8 num_profiles;                    /* Num of profiles installl          */
    U8 index_profile;
    dtcnt_ota_item_struct *active_item;
    dtcnt_ota_item_struct *current_item;
    dtcnt_ota_item_struct *g_dtcnt_ota_items;
} dtcnt_ota_context_struct;

static dtcnt_ota_context_struct g_dtcnt_ota_cntx = {0};

static dtcnt_ota_item_struct *mmi_dtcnt_ota_new_item(void);
static void mmi_dtcnt_ota_charset_convert(S8 *scr, S8 *des, U8 len, U8 covertype);
static U8   mmi_dtcnt_get_profiles_num(void);
static void mmi_dtcnt_ota_profile_skip_confirm(void);
static void mmi_dtcnt_ota_cca_rsp_handler(void);

#ifdef SYNCML_DM_SUPPORT

typedef struct dtcnt_dm_context
{
	U16 app_id;
	U32 prof_id;
	S32 hconfig;
    U8  data_ready_status;
	cca_status_enum  check_status;
	dtcnt_ota_item_struct  dm_item_cntx;
}dtcnt_dm_context_struct;

static dtcnt_dm_context_struct g_dtcnt_dm_cntx;

/* Internal Functions for DM */

static void mmi_dtcnt_ota_dm_retrieve_rsp(void);
static void mmi_dtcnt_get_CCA(U8 bearer);
static cca_status_enum mmi_dtcnt_ota_dm_check(U16 AppId, U32 ProfId, U8 *bearer);
static void mmi_dtcnt_ota_dm_update_rsp(void);
static void mmi_dtcnt_get_prof_by_cca(U8 bearer, S32 hconfig);
static void mmi_dtcnt_get_gsm_prof_by_cca(U8 bearer, S32 hconfig);
static cca_status_enum mmi_dtcnt_dm_proc_cca_nodes(
												   S32 doc_hdl, 
												   S32 node_hdl, 
												   U16 symbol, 
												   cca_iterator_struct *param_list, 
												   void *user_data);
static void mmi_dtcnt_save_prof_info(U8 bearer);
static void mmi_dtcnt_get_cca_by_csd_prof(void);
static void mmi_dtcnt_dm_handle_set_csd_account_rsp(void *info);

static void mmi_dtcnt_get_next_profile_data(void);
static BOOL mmi_dtcnt_ota_has_next_valid_profile(dtcnt_ota_item_struct *iter);

#ifdef __MMI_WLAN_FEATURES__
static void mmi_dtcnt_get_cca_by_wlan_prof(void);
static void mmi_dtcnt_get_wlan_prof_by_cca(S32 hconfig);
#endif

#ifdef __MMI_GPRS_FEATURES__
static void mmi_dtcnt_get_cca_by_gprs_prof(void);
static void mmi_dtcnt_dm_handle_set_gprs_account_rsp(void *info);
#endif

#endif /* SYNCML_DM_SUPPORT */

extern BOOL mmi_dtcnt_check_UCS2(U16 *buf, U16 charNum);
extern void mmi_dtcnt_select_highlight_handler(U32 acct_id, U8 bearers);
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_is_ascii_string
 * DESCRIPTION
 *  This function checks whether the input UTF-8 encoded string is an ASCII
 *  string.
 * PARAMETERS
 *  utf8_str        [IN]            Input UTF-8 encoded string
 * RETURNS
 *  If input string is ASCII string, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_dtcnt_is_ascii_string(const S8 *utf8_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If this is an ASCII string, each octet should be an ASCII character. */
    for ( ; *utf8_str != '\0'; ++utf8_str)
    {
        if (*utf8_str > 0x7F || *utf8_str < 0) 
        {
            return MMI_FALSE;
        }
    }
    
    return MMI_TRUE;
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
static void mmi_dtcnt_ota_handle_set_csd_account_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_set_csd_profile_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_cc_set_csd_profile_rsp_struct*) info;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_handle_set_csd_account_rsp");

    ClearDelScrnIDCallbackHandler(SCR_ID_DTCNT_OTA_MAIN, NULL);
    DeleteScreenIfPresent(SCR_ID_DTCNT_LIST);
    DeleteScreenIfPresent(SCR_ID_DTCNT_OTA_MAIN);

    if (localPtr->result == KAL_TRUE /* OK */ )
    {
        if(GetActiveScreenId() == SCR_ID_DTCNT_LIST)
        {
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
            GoBackHistory();
        }
        else 
        {
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST);
        }
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
        DeleteScreenIfPresent(SCR_ID_DTCNT_POPUP);
    }

     mmi_dtcnt_ota_cca_rsp_handler(); 
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
static void mmi_dtcnt_ota_handle_set_csd_account_req(dtacc_func_enum dtacc_func, U8 item_num)
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
    U16 str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_num >= MAX_DATA_ACCOUNT_GSM_LIMIT)
    {
        return;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_handle_set_csd_account_req");

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
    myMsgPtr->prof_id = item_num;

    if (g_DataAccount[item_num].DialType == DIAL_TYPE_ANALOGUE)
    {
        myMsgPtr->type = (U8) CSMCC_ITC_3_1_K_AUDIO;
    }
    else
    {
        myMsgPtr->type = (U8) CSMCC_ITC_UDI;
    }

    if (g_DataAccount[item_num].DataRate == DATA_RATE_FOUR_EIGHT)
    {
        myMsgPtr->rate = (U8) CSD_PROF_RATE_4800;
    }
    else if (g_DataAccount[item_num].DataRate == DATA_RATE_NINE_SIX)
    {
        myMsgPtr->rate = (U8) CSD_PROF_RATE_9600;
    }
    else if (g_DataAccount[item_num].DataRate == DATA_RATE_FOURTEEN_FOUR)
    {
        myMsgPtr->rate = (U8) CSD_PROF_RATE_14400;
    }

    for (i = 0; i < DTCNT_ITEM_DNS_LENGTH; i++)
    {
        myMsgPtr->dns[i] = (U8) g_DataAccount[item_num].DnsAddress[i];
    }

    if (g_DataAccount[item_num].iFdcs > 0)
    {
        g_DataAccount[item_num].iFdcs = mmi_ucs2strlen((PS8) g_DataAccount[item_num].DataAccountName) * ENCODING_LENGTH;
        myMsgPtr->name.name_length = g_DataAccount[item_num].iFdcs;
        myMsgPtr->name.name_dcs = DATA_ACCOUNT_UCS; /* 0x8 */
        i = 0;
        while (i != g_DataAccount[item_num].iFdcs)
        {
            myMsgPtr->name.name[i] = g_DataAccount[item_num].DataAccountName[i + 1];
            myMsgPtr->name.name[i + 1] = g_DataAccount[item_num].DataAccountName[i];
            i += 2;
        }
        myMsgPtr->name.name[i] = '\0';
        myMsgPtr->name.name[i + 1] = '\0';
    }
    else
    {
        myMsgPtr->name.name_dcs = DATA_ACCOUNT_ASCII;
        mmi_ucs2_to_asc((PS8) DataAccountName_ASCII, (PS8) g_DataAccount[item_num].DataAccountName);
        str_len = sizeof(myMsgPtr->name.name);
        if(str_len >= strlen((PS8) DataAccountName_ASCII))
        {
        myMsgPtr->name.name_length = strlen((PS8) DataAccountName_ASCII);
        }
        else
        {
            myMsgPtr->name.name_length = str_len;
    }

        memcpy(myMsgPtr->name.name, DataAccountName_ASCII, sizeof(myMsgPtr->name.name));
        g_DataAccount[item_num].iFdcs = 0;
    }

    memcpy(myMsgPtr->user_id, g_DataAccount[item_num].UserName, sizeof(myMsgPtr->user_id));

    memcpy(myMsgPtr->passwd, g_DataAccount[item_num].Passwd, sizeof(myMsgPtr->passwd));

    if (g_DataAccount[item_num].DialNumber[0] == '+')
    { 
        /*delete '+'*/
        i = 0;
        while(g_DataAccount[item_num].DialNumber[i])
        {
            g_DataAccount[item_num].DialNumber[i] = g_DataAccount[item_num].DialNumber[i+1];
            i++;
        }

        myMsgPtr->dest.type = MMI_CSMCC_INTERNATIONAL_ADDR; /* INTERNATIONAL */    
    }
    else
    {
        myMsgPtr->dest.type = MMI_CSMCC_DEFAULT_ADDR_TYPE;  /* DEFAULT */
    }

    str_len = sizeof(myMsgPtr->dest.number);
    if(str_len >= strlen((PS8) g_DataAccount[item_num].DialNumber))
    {
        myMsgPtr->dest.length = strlen((PS8) g_DataAccount[item_num].DialNumber);
    }
    else
    {
        myMsgPtr->dest.length = str_len;
    }

    memcpy(myMsgPtr->dest.number, g_DataAccount[item_num].DialNumber, sizeof(myMsgPtr->dest.number));

    if(dtacc_func == DTCNT_FOR_PROVISIONING)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_CC_SET_CSD_PROFILE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
	if(dtacc_func == DTCNT_FOR_PROVISIONING)
	{
    SetProtocolEventHandler(mmi_dtcnt_ota_handle_set_csd_account_rsp, PRT_MMI_CC_SET_CSD_PROFILE_RSP);
		/*EntryDTCNTProgress();*/
	}
#ifdef SYNCML_DM_SUPPORT
	else 
	{
		SetProtocolEventHandler(mmi_dtcnt_dm_handle_set_csd_account_rsp, PRT_MMI_CC_SET_CSD_PROFILE_RSP);
	}
#endif /* SYNCML_DM_SUPPORT */

    OslMsgSendExtQueue(&Message);
}


#ifdef __MMI_GPRS_FEATURES__
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
static void mmi_dtcnt_ota_handle_set_gprs_account_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_set_gprs_data_account_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_ps_set_gprs_data_account_rsp_struct*) info;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_handle_set_gprs_account_rsp");

    ClearDelScrnIDCallbackHandler(SCR_ID_DTCNT_OTA_MAIN, NULL);
    DeleteScreenIfPresent(SCR_ID_DTCNT_GPRS_LIST);
    DeleteScreenIfPresent(SCR_ID_DTCNT_OTA_MAIN);

    if (localPtr->result == KAL_TRUE /* OK */ )
    {
        if(GetActiveScreenId() == SCR_ID_DTCNT_GPRS_LIST)
        {
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
        GoBackHistory();
    }
    else
    {
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST_ALWAYS_ASK);
            DeleteScreenIfPresent(SCR_ID_DTCNT_GPRS_LIST);
        }
        
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
        DeleteScreenIfPresent(SCR_ID_DTCNT_POPUP);
    }

    mmi_dtcnt_ota_cca_rsp_handler();
}

#ifdef __MMI_GPRS_FEATURES__
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
void mmi_dtcnt_ota_handle_set_gprs_account_req(dtacc_func_enum dtacc_func, U8 item_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_set_gprs_data_account_req_struct *myMsgPtr;

    /* micha0820 */
    U8 ref_count;
    U16 msg_len;
    U16 str_len = 0;

    MYQUEUE Message;
    U8 DataAccountName_ASCII[(MAX_GPRS_DATAACCOUNT_NAME + 1) * ENCODING_LENGTH];
    U8 DataAccountAPN_ASCII[MAX_APN_LEN];
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_num > MAX_DATA_ACCOUNT_GPRS_LIMIT)
    {
        ASSERT(0);
        return;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccount.c] mmi_dtcnt_ota_handle_set_gprs_account_req");

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

    myMsgPtr->gprs_account.context_id = item_num + 1;
    myMsgPtr->gprs_account.authentication_type = g_GPRS_DataAccount[item_num].AuthType;

    if (g_GPRS_DataAccount[item_num].iFdcs > 0)
    {
        g_GPRS_DataAccount[item_num].iFdcs = mmi_ucs2strlen((PS8) g_GPRS_DataAccount[item_num].DataAccountName) * ENCODING_LENGTH;
        myMsgPtr->gprs_account.name_length = g_GPRS_DataAccount[item_num].iFdcs;
        myMsgPtr->gprs_account.name_dcs = DATA_ACCOUNT_UCS; /* 0x8 */
        i = 0;
        while (i != g_GPRS_DataAccount[item_num].iFdcs)
        {
            myMsgPtr->gprs_account.name[i] = g_GPRS_DataAccount[item_num].DataAccountName[i + 1];
            myMsgPtr->gprs_account.name[i + 1] = g_GPRS_DataAccount[item_num].DataAccountName[i];
            i += 2;
        }
        myMsgPtr->gprs_account.name[i] = '\0';
        myMsgPtr->gprs_account.name[i + 1] = '\0';
    }
    else
    {
        myMsgPtr->gprs_account.name_dcs = DATA_ACCOUNT_ASCII;
        mmi_ucs2_to_asc((PS8) DataAccountName_ASCII, (PS8) g_GPRS_DataAccount[item_num].DataAccountName);
        str_len = sizeof(myMsgPtr->gprs_account.name);
        if(str_len >= strlen((PS8) DataAccountName_ASCII))
        {
        myMsgPtr->gprs_account.name_length = strlen((PS8) DataAccountName_ASCII);
        }
        else
        {
            myMsgPtr->gprs_account.name_length = str_len;
        }
        
        memcpy(myMsgPtr->gprs_account.name, DataAccountName_ASCII, sizeof(myMsgPtr->gprs_account.name));
        g_GPRS_DataAccount[item_num].iFdcs = 0;
    }

    mmi_ucs2_to_asc((PS8) DataAccountAPN_ASCII, (PS8) g_GPRS_DataAccount[item_num].APN);
    /* micha0202 */
    memcpy(myMsgPtr->gprs_account.apn, DataAccountAPN_ASCII, sizeof(myMsgPtr->gprs_account.apn));
    str_len = sizeof(myMsgPtr->gprs_account.apn);
    PRINT_INFORMATION("$$$$$ Dtcnt provisiong apn length1 = %d $$$$$", str_len);
    if(str_len >= strlen((PS8) DataAccountAPN_ASCII))
    {
    myMsgPtr->gprs_account.apn_length = strlen((PS8) DataAccountAPN_ASCII);
    }
    else
    {
        myMsgPtr->gprs_account.apn_length = str_len;
    }

    memcpy(
        myMsgPtr->gprs_account.user_name,
        g_GPRS_DataAccount[item_num].UserName,
        sizeof(myMsgPtr->gprs_account.user_name));

    memcpy(
        myMsgPtr->gprs_account.password,
        g_GPRS_DataAccount[item_num].Passwd,
        sizeof(myMsgPtr->gprs_account.password));

    for (i = 0; i < DTCNT_ITEM_DNS_LENGTH; i++)
    {
        myMsgPtr->gprs_account.dns[i] = 0;
    }

    if(dtacc_func == DTCNT_FOR_PROVISIONING)
    {
    ClearInputEventHandler(MMI_DEVICE_ALL);
    }
    
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
	if(dtacc_func == DTCNT_FOR_PROVISIONING)
	{
    SetProtocolEventHandler(mmi_dtcnt_ota_handle_set_gprs_account_rsp, PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP);
		/*EntryDTCNTProgress();*/
}
#ifdef SYNCML_DM_SUPPORT
	else
	{
		SetProtocolEventHandler(mmi_dtcnt_dm_handle_set_gprs_account_rsp, PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP);
	}
#endif /* SYNCML_DM_SUPPORT */
	OslMsgSendExtQueue(&Message);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_find_empty_profile
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
void mmi_dtcnt_ota_install_gprs_item(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, acct_id;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_install_gprs_item");

    acct_id = always_ask_get_original_id_data_account(id);
    
    i = acct_id - mmi_dtcnt_get_first_account_id(DATA_ACCOUNT_BEARER_GPRS);

    memset(&g_GPRS_DataAccount[i], 0, sizeof(GPRSDataAccountNode));

    /*mmi_asc_n_to_ucs2((PS8) g_GPRS_DataAccount[i].DataAccountName, 
                          (PS8) g_dtcnt_ota_cntx.current_item->name,
                          (MAX_GPRS_DATAACCOUNT_NAME));*/
        
    if(!mmi_cca_is_ascii_string((PS8) g_dtcnt_ota_cntx.current_item->name))
    {
        /*mmi_dtcnt_ota_charset_convert((PS8)g_dtcnt_ota_cntx.current_item->name, 
        (PS8)g_GPRS_DataAccount[i].DataAccountName, 
            (MAX_DATA_ACCOUNT_NAME_LEN + 1),// *ENCODING_LENGTH,
            MMI_DTCNT_UTF8_UCS2);*/

        mmi_ucs2ncpy((PS8)g_GPRS_DataAccount[i].DataAccountName, 
                     (PS8) g_dtcnt_ota_cntx.current_item->name, 
                     (MAX_DATA_ACCOUNT_NAME_LEN+1));

        if(mmi_dtcnt_check_UCS2((U16*)g_GPRS_DataAccount[i].DataAccountName, (U16)mmi_ucs2strlen((PS8)g_GPRS_DataAccount[i].DataAccountName)))
        {
            g_GPRS_DataAccount[i].iFdcs = mmi_ucs2strlen((PS8) g_GPRS_DataAccount[i].DataAccountName);//*ENCODING_LENGTH ;
        }
    }
    else
    {
        mmi_asc_n_to_ucs2((PS8) g_GPRS_DataAccount[i].DataAccountName, 
            (PS8) g_dtcnt_ota_cntx.current_item->name,
                          (MAX_GPRS_DATAACCOUNT_NAME));

        g_GPRS_DataAccount[i].iFdcs = 0;            
    }
    
    mmi_asc_n_to_ucs2((PS8) g_GPRS_DataAccount[i].APN, 
                          (PS8) g_dtcnt_ota_cntx.current_item->address,
                          (MAX_GPRS_MMI_APN_LEN));

    strcpy((PS8) g_GPRS_DataAccount[i].UserName, (PS8) g_dtcnt_ota_cntx.current_item->UserName);
    strcpy((PS8) g_GPRS_DataAccount[i].Passwd, (PS8) g_dtcnt_ota_cntx.current_item->Passwd);

    memcpy(g_DataAccount[i].DnsAddress, g_dtcnt_ota_cntx.current_item->DnsAddress, DTCNT_ITEM_DNS_LENGTH);
    g_GPRS_DataAccount[i].AuthType = (U8) g_dtcnt_ota_cntx.current_item->AuthType;
    g_GPRS_DataAccount[i].Present = DTCNT_ITEM_PRESENT_YES;

    /* Notify CCA the success of installing each WLAN profile. */
    mmi_cca_oma_add_dataacctid(g_dtcnt_ota_cntx.doc_hdl, (S8 *)g_dtcnt_ota_cntx.current_item->node_id, id);

    /* Install successfully. Update counter. */        
    ++g_dtcnt_ota_cntx.num_installed;

    mmi_dtcnt_ota_handle_set_gprs_account_req(DTCNT_FOR_PROVISIONING, i);

}


#endif /* __MMI_GPRS_FEATURES__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_ota_send_cca_app_configure_res
 * DESCRIPTION
 *  This function sends the response message back to CCA for the result of 
 *  configuration. Once application sends this primitive, no further access
 *  to the configuration document should be made.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  status          [IN]            Configuration result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_ota_send_cca_app_configure_res(U16 conf_id, S32 doc_hdl, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_configure_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_send_cca_app_configure_res");

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_configure_rsp_struct *)OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));

    data->config_id = conf_id;
    data->hConfig   = doc_hdl;
    data->status    = status;

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_CONFIGURE_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_free_otap_cntx
 * DESCRIPTION
 *  The function frees memory of the control block, and clears the global ptr.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_ota_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtcnt_ota_item_struct *iter, *temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_terminate");

    /* Nothing to do. Return. */
    if (g_dtcnt_ota_cntx.g_dtcnt_ota_items == NULL) 
    {
        return;
    }

    iter = g_dtcnt_ota_cntx.g_dtcnt_ota_items;
    
    /* Free all profiles. */
    while(iter)
    {
        temp = iter;
        iter = iter->next;
        OslMfree(temp);
        temp = NULL;
    }
    
    /* Free the control block. */
    memset(&g_dtcnt_ota_cntx, 0, sizeof(g_dtcnt_ota_cntx));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_ota_has_any_valid_profile
 * DESCRIPTION
 *  This function checks if there is any valid profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static BOOL mmi_dtcnt_ota_has_any_valid_profile()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtcnt_ota_item_struct *iter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    /* Nothing to do. Return. */
    if (g_dtcnt_ota_cntx.g_dtcnt_ota_items == NULL)
    {
        return FALSE;
    }

    iter = g_dtcnt_ota_cntx.g_dtcnt_ota_items;
    
    while(iter)
    {
        if(iter->valid && iter->bearer)
        {
            return TRUE;
        }
        iter = iter->next;
    }
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_ota_has_any_valid_profile
 * DESCRIPTION
 *  This function checks if there is any valid profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static BOOL mmi_dtcnt_ota_has_next_valid_profile(dtcnt_ota_item_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    /* Nothing to do. Return. */
    if (iter == NULL)
    {
        return FALSE;
    }
    
    while(iter)
    {
        if(iter->valid)
        {
            return TRUE;
        }
        iter = iter->next;
    }
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_ota_abort_install
 * DESCRIPTION
 *  This function should be called to exit the data account ota application. It is 
 *  registered as a delete screen callback such that it can be called when END
 *  key is pressed to return to idle screen.
 * PARAMETERS
 *  dummy           [IN]            Dummy parameter. Always be zero.
 * RETURNS
 *  When END key is pressed to return to idle screen, return TRUE to stop 
 *  delete other nodes in history stack. Here, always return FALSE.
 *****************************************************************************/
static U8 mmi_dtcnt_ota_abort_install(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_abort_install");

    /* Terminated. Send a response back to CCA and free memory. */    
    ClearDelScrnIDCallbackHandler(SCR_ID_DTCNT_OTA_MAIN, NULL);
    mmi_dtcnt_ota_send_cca_app_configure_res(g_dtcnt_ota_cntx.conf_id, g_dtcnt_ota_cntx.doc_hdl, CCA_STATUS_ENDKEY_PRESSED);
    mmi_dtcnt_ota_terminate();
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_validate_item
 * DESCRIPTION
 *  This function validates.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  cntx            [IN/OUT]        The VoIP OTAP control block
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
/*static BOOL mmi_dtcnt_validate_item(dtcnt_ota_item_struct *item)
{
    if(mmi_ucs2strlen(item->name) <= 0)
    {
        return FALSE;
    }
    else if(mmi_ucs2strlen(item->address) <= 0)
    {
        return FALSE;
    }
    return TRUE;
}*/


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_proc_cca_param_PX_SIP
 * DESCRIPTION
 *  This function processes the parameter of PX-SIP node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  cntx            [IN/OUT]        The VoIP OTAP control block
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
static cca_status_enum mmi_dtcnt_ota_proc_cca_param(const cca_core_data_struct *param, dtcnt_ota_item_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (param->id)
    {
    case CCA_NS_NODEID:

        /* Whether the value is presented and the type is legal. */
        if (param->size <= 0 || param->type != CCA_DT_STR) 
        {
            return CCA_STATUS_FAIL;
        }
        
        /* Whether the string's raw length is legal. */
        if (strlen(param->values.s[0]) + 1 > MAX_NODE_ID_LEN) 
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] NodeID == Error");
            return CCA_STATUS_FAIL;
        }
        
        /* Extract the node id. Store it as UTF-8 string. */
        /*strcpy((S8 *)prof->node_id, param->values.s[0]);*/
        strcpy((S8 *)prof->node_id, param->values.s[0]);

        break;
    case CCA_NS_OMA_NAME: /* PRS_STR_ISP_NAME */
        if(param->values.s[0])
        {
            if(!mmi_cca_is_ascii_string((PS8) param->values.s[0]))
            {
                
                mmi_dtcnt_ota_charset_convert((PS8)param->values.s[0], 
                                              (PS8)prof->name,
                                              (MAX_DATA_ACCOUNT_NAME_LEN+1),
                                              MMI_DTCNT_UTF8_UCS2);
                prof->name[MAX_DATA_ACCOUNT_NAME_LEN] = 0;
                prof->name[MAX_DATA_ACCOUNT_NAME_LEN-1] = 0;
            }
            else
            {
            
            strncpy((S8 *)prof->name, (S8 *)param->values.s[0], MAX_DATA_ACCOUNT_NAME_LEN);
            prof->name[MAX_DATA_ACCOUNT_NAME_LEN] = 0;
        }
            
            
        }
        break;
    case CCA_NS_OMA_AUTHTYPE: /* PRS_STR_PPP_AUTHTYPE */
        if(param->values.i[0] == CCA_NS_VAL_PAP)
        {
            prof->AuthType = 0;
        }
        else if(param->values.i[0] == CCA_NS_VAL_CHAP)
        {
            prof->AuthType = 1;
        }
        else if(param->values.i[0] == CCA_NS_VAL_MD5)
        {
            prof->AuthType = 1;
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] AUTHTYPE == Default PAP! ");
            prof->AuthType = 0;
        }
        break;
    case CCA_NS_OMA_AUTHNAME: /* PRS_STR_PPP_AUTHNAME */
        if(param->values.s[0])
        {
            /*if (strlen(param->values.s[0]) > MAX_USER_LEN) 
            {
                return CCA_STATUS_FAIL;
            }*/
            strncpy((S8 *)prof->UserName, (const S8 *)param->values.s[0], MAX_USER_LEN);
        }
        break;
    case CCA_NS_OMA_AUTHSECRET: /* PRS_STR_PPP_AUTHPW */
        if(param->values.s[0])
        {
            /*if (strlen(param->values.s[0]) > MAX_PASSWD_LEN) 
            {
                return CCA_STATUS_FAIL;
            }*/
            //mmi_ucs2ncpy((S8 *)prof->Passwd, (const S8 *)param->values.s[0], MAX_PASSWD_LEN);
            strncpy((S8 *)prof->Passwd, (const S8 *)param->values.s[0], MAX_PASSWD_LEN);
        }
        break;
    case CCA_NS_OMA_CALLTYPE: /* PRS_STR_CSD_CALLTYPE */
        switch(param->values.i[0])
        {
        case CCA_NS_VAL_ANALOG_MODEM:
            prof->DialType = DIAL_TYPE_ANALOGUE;
            break;
        case CCA_NS_VAL_V120:
        case CCA_NS_VAL_V110:
        case CCA_NS_VAL_X31:
        case CCA_NS_VAL_BIT_TRANSPARENT:
        case CCA_NS_VAL_DIRECT_ASYNC_DATA_SERVICE:
            prof->DialType = DIAL_TYPE_ISDN;
            break;
        default:
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] CALLTYPE == Error");
            //return CCA_STATUS_FAIL;
            break;
        }
        break;
    case CCA_NS_OMA_LINKSPEED: /* PRS_STR_CSD_CALLSPEED */
        if(param->values.i[0] == DATA_RATE_4800)
        {
            prof->DataRate = DATA_RATE_FOUR_EIGHT;
        }
        else if(param->values.i[0] == DATA_RATE_9600)
        {
            prof->DataRate = DATA_RATE_NINE_SIX;
        }
        else if(param->values.i[0] == DATA_RATE_14400)
        {
            prof->DataRate = DATA_RATE_FOURTEEN_FOUR;
        }
        else 
        {
            prof->DataRate = DATA_RATE_FOUR_EIGHT;
        }
        break;
    case CCA_NS_OMA_NAP_ADDRESS: /* PRS_STR_CSD_DAILSTRING */
        if(param->values.s[0])
        {
            if(prof->bearer == DATA_ACCOUNT_BEARER_CSD)
            {
                strncpy((S8 *)prof->address, (S8 *)param->values.s[0], MAX_DIAL_NUM_LEN-1);
                prof->address[MAX_DIAL_NUM_LEN-1] = 0;
                i = 0;
                while(prof->address[i])
                {
                    if(prof->address[i] != 0x2b && (prof->address[i] < 0x30 || prof->address[i] > 0x39))
                    {
                        return CCA_STATUS_FAIL;
                    }
                    i++;
                }
            }
#ifdef __MMI_GPRS_FEATURES__
            else if(prof->bearer == DATA_ACCOUNT_BEARER_GPRS)
            {
                strncpy((S8 *)prof->address, (S8 *)param->values.s[0], MAX_GPRS_MMI_APN_LEN);
                prof->address[MAX_GPRS_MMI_APN_LEN] = 0;
            }
#endif /* __MMI_GPRS_FEATURES__ */
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] NAP_ADDR == Error");
                return CCA_STATUS_FAIL;
            }
            
        }
        break;
    case CCA_NS_OMA_DNS_ADDR:
        if(param->values.s[0])
        {
            U32 dns[4];
            sscanf((char *)param->values.s[0], "%u.%u.%u.%u",&dns[0],&dns[1],&dns[2],&dns[3]);
            if(dns[0] == 0 || dns[0] > 255 || dns[1] > 255 || dns[2] > 255 ||dns[3] > 255)
            {
                prof->DnsAddress[0] = 0;
                prof->DnsAddress[1] = 0;
                prof->DnsAddress[2] = 0;
                prof->DnsAddress[3] = 0;
            }
            else
            {
            prof->DnsAddress[0] = (U8)dns[0];
            prof->DnsAddress[1] = (U8)dns[1];
            prof->DnsAddress[2] = (U8)dns[2];
            prof->DnsAddress[3] = (U8)dns[3];
        }
        }
        break;
    case CCA_NS_OMA_BEARER: /* PRS_STR_CSD_DAILSTRING */
        if(param->values.i[0] == CCA_NS_VAL_GSM_CSD)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] beraer == CSD");
            prof->bearer = DATA_ACCOUNT_BEARER_CSD;
        }
        else if(param->values.i[0] == CCA_NS_VAL_GSM_GPRS)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] beraer == GPRS");
            prof->bearer = DATA_ACCOUNT_BEARER_GPRS;
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] beraer == Error");
            return CCA_STATUS_FAIL;
        }
        break;
    default:
        break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum mmi_dtcnt_ota_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*static dtcnt_ota_item_struct *active_item;*/
    cca_core_data_struct *param;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    switch (symbol)
    {
    case DTCNT_OTA_NAPDEF:
        
        status = CCA_STATUS_OK;             /* Initialize the status variable   */

        /* Processing the first setting now. */
        /* Prepare a storage for the new profile. */
        if(!g_dtcnt_ota_cntx.active_item)
        {
            g_dtcnt_ota_cntx.active_item = mmi_dtcnt_ota_new_item();
            g_dtcnt_ota_cntx.g_dtcnt_ota_items = g_dtcnt_ota_cntx.active_item;
        }
        else
        {
            g_dtcnt_ota_cntx.active_item->next = mmi_dtcnt_ota_new_item();
            g_dtcnt_ota_cntx.active_item = g_dtcnt_ota_cntx.active_item->next;
        }
        
        /* Init control block and save the ID/handle for the response msg. */

        if (!g_dtcnt_ota_cntx.active_item)
        {
            ASSERT(0);
            return CCA_STATUS_FAIL;
        }
    
        while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
        {   
            if(status == CCA_STATUS_OK)
            {
                status = mmi_dtcnt_ota_proc_cca_param(param, g_dtcnt_ota_cntx.active_item);
                if(status == CCA_STATUS_FAIL)
                {
                    g_dtcnt_ota_cntx.active_item->valid = FALSE;
                }
            }
        }

        return CCA_STATUS_OK;
    
    case DTCNT_OTA_NAPAUTHINFO:
        status = CCA_STATUS_OK;             /* Initialize the status variable   */
        
        /* Must be processed after a napdef, active_item cannot be NULL */
        if (!g_dtcnt_ota_cntx.active_item)
        {
            return CCA_STATUS_FAIL;
        }

        while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
        {   
            if(status == CCA_STATUS_OK)
            {
                status = mmi_dtcnt_ota_proc_cca_param(param, g_dtcnt_ota_cntx.active_item);
                if(status == CCA_STATUS_FAIL)
                {
                    g_dtcnt_ota_cntx.active_item->valid = FALSE;
                }
            }
        }

        return CCA_STATUS_OK;
    default:
        return CCA_STATUS_OK;
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_new_otap_cntx
 * DESCRIPTION
 *  This function allocates and initializes the control block of voip OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
static dtcnt_ota_item_struct *mmi_dtcnt_ota_new_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dtcnt_ota_item_struct *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate the control block. Must be successful. */
    p = (dtcnt_ota_item_struct *)OslMalloc(sizeof(dtcnt_ota_item_struct));
    if (p == NULL)
    {
        return NULL;
    }

    /* Clear the entire structure. */
    memset(p, 0, sizeof(dtcnt_ota_item_struct));

    p->valid = TRUE;
    
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_find_empty_profile
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
void mmi_dtcnt_ota_install_csd_item(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, acct_id;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_install_csd_item");

    acct_id = always_ask_get_original_id_data_account(id);

    i = acct_id - mmi_dtcnt_get_first_account_id(DATA_ACCOUNT_BEARER_CSD);

    memset(&g_DataAccount[i], 0, sizeof(DataAccountNode));

    
    if(!mmi_cca_is_ascii_string((PS8)g_dtcnt_ota_cntx.current_item->name))
    {
        mmi_ucs2ncpy((PS8)g_DataAccount[i].DataAccountName, 
                     (PS8) g_dtcnt_ota_cntx.current_item->name, 
                     (MAX_DATA_ACCOUNT_NAME_LEN+1));

        PRINT_INFORMATION("$$$$ DTCNT install csd profile name_1 = %s, len = %d", (S8 *)g_DataAccount[i].DataAccountName, mmi_ucs2strlen((S8 *)g_DataAccount[i].DataAccountName));

        if(mmi_dtcnt_check_UCS2((U16*)g_DataAccount[i].DataAccountName, (U16)mmi_ucs2strlen((PS8)g_DataAccount[i].DataAccountName)))
        {
            g_DataAccount[i].iFdcs = mmi_ucs2strlen((PS8) g_DataAccount[i].DataAccountName);//*ENCODING_LENGTH ;
        }
    }
    else
    {
        mmi_asc_n_to_ucs2((PS8) g_DataAccount[i].DataAccountName, 
            (PS8) g_dtcnt_ota_cntx.current_item->name,
                          (MAX_DATA_ACCOUNT_NAME_LEN));

        g_DataAccount[i].iFdcs = 0;            
    }
    
    /*mmi_asc_n_to_ucs2((PS8)g_DataAccount[i].DialNumber, (PS8) g_dtcnt_ota_cntx.current_item->address, MAX_DIAL_NUM_LEN);*/
    strcpy((PS8) g_DataAccount[i].DialNumber, (PS8) g_dtcnt_ota_cntx.current_item->address);
    strcpy((PS8) g_DataAccount[i].UserName, (PS8) g_dtcnt_ota_cntx.current_item->UserName);
    strcpy((PS8) g_DataAccount[i].Passwd, (PS8) g_dtcnt_ota_cntx.current_item->Passwd);

    memcpy(g_DataAccount[i].DnsAddress, g_dtcnt_ota_cntx.current_item->DnsAddress, DTCNT_ITEM_DNS_LENGTH);
    g_DataAccount[i].DialType = (U8) g_dtcnt_ota_cntx.current_item->DialType;
    g_DataAccount[i].DataRate = (U8) g_dtcnt_ota_cntx.current_item->DataRate;
    g_DataAccount[i].Present = DTCNT_ITEM_PRESENT_YES;

    /* Notify CCA the success of installing each WLAN profile. */
    mmi_cca_oma_add_dataacctid(g_dtcnt_ota_cntx.doc_hdl, (S8 *)g_dtcnt_ota_cntx.current_item->node_id, id);

    /* Install successfully. Update counter. */        
    ++g_dtcnt_ota_cntx.num_installed;

    mmi_dtcnt_ota_handle_set_csd_account_req(DTCNT_FOR_PROVISIONING, i);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_find_empty_profile
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
void mmi_dtcnt_ota_select_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_dtcnt_ota_cntx.current_item);
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_select_profile");

    if(g_dtcnt_ota_cntx.current_item->bearer == DATA_ACCOUNT_BEARER_CSD)
    {
        mmi_dtcnt_select_highlight_handler(0, DATA_ACCOUNT_BEARER_CSD);
        mmi_dtcnt_select_account_option(mmi_dtcnt_ota_install_csd_item, 
                                        SERVICES_DATA_CONNECT_MAIN_MENU_ID, 
                                        DATA_ACCOUNT_BEARER_CSD, 
                                        DTCNT_SELECT_NO_SIM, 
                                        DTCNT_SELECT_NO_ALWAYS_ASK);
    }
#ifdef __PS_SERVICE__
    else if(g_dtcnt_ota_cntx.current_item->bearer == DATA_ACCOUNT_BEARER_GPRS)
    {
        mmi_dtcnt_select_highlight_handler(10, DATA_ACCOUNT_BEARER_GPRS);
        mmi_dtcnt_select_account_option(mmi_dtcnt_ota_install_gprs_item, 
                                        SERVICES_DATA_CONNECT_MAIN_MENU_ID, 
                                        DATA_ACCOUNT_BEARER_GPRS,
                                        DTCNT_SELECT_NO_SIM, 
                                        DTCNT_SELECT_NO_ALWAYS_ASK);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_ota_prepare_prof_info
 * DESCRIPTION
 *  Compose the profile information to be displayed.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_ota_prepare_prof_info(S8 *info, dtcnt_ota_item_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tempBuf[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    S8 tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    S8 tempBufUCS2[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
#ifdef    __MMI_GPRS_FEATURES__
    S8 tempBufGprsAPN[MAX_GPRS_MMI_APN_LEN * ENCODING_LENGTH];
#endif /* __MMI_GPRS_FEATURES__ */
    U8 num_ascii_str[20];
    U8 num_unicode_str[20];
    U8 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(num_ascii_str, 0, 20);
    memset(num_unicode_str, 0, 20);

    /* Data Account Profile num */
    mmi_ucs2cpy(info, GetString(STR_ID_CCA_PROFILE)); 
    mmi_ucs2cat(info, (S8 *)L":  ");
    sprintf((S8 *)num_ascii_str, "%d/%d", (g_dtcnt_ota_cntx.index_profile + 1),
                    g_dtcnt_ota_cntx.num_profiles);

    mmi_asc_n_to_ucs2((PS8) num_unicode_str, (PS8) num_ascii_str, sizeof(num_unicode_str));
    mmi_ucs2cat((PS8) info, (PS8) num_unicode_str);
    mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

    /* Data Account Name */
    mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_RENAME));
    mmi_ucs2cat((PS8) info, (PS8) L":  ");
    memset(tempBufUnicode, 0, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH);
    memset(tempBufUCS2, 0, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH);
    memset(tempBuf, 0, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH);

    mmi_ucs2ncpy(tempBufUnicode, (PS8) p->name, (MAX_DATA_ACCOUNT_NAME_LEN+1));

    PRINT_INFORMATION("$$$$ DTCNT install name = %s, len = %d", (S8 *)tempBufUnicode, mmi_chset_utf8_strlen((const kal_uint8 *)tempBufUnicode));

    if(!mmi_cca_is_ascii_string(p->name))
    {
        PRINT_INFORMATION("$$$$ DTCNT install ucs2 name = %s, len = %d", (S8 *)tempBufUCS2, mmi_ucs2strlen((S8 *)tempBufUCS2));
        mmi_ucs2cat((PS8) info, tempBufUnicode);
    }
    else
    {
    mmi_asc_n_to_ucs2(tempBufUnicode, (PS8) p->name, strlen(p->name));
    mmi_ucs2cat((PS8) info, tempBufUnicode);
    }

    mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

    /* Dial Number or APN */
    if(p->bearer == DATA_ACCOUNT_BEARER_CSD)
    {
        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_DIAL_NUMBER));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        memset(tempBufUnicode, 0, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(tempBufUnicode, (PS8) p->address, strlen(p->address));
        /*mmi_ucs2ncpy(tempBufUnicode, (PS8) p->address, mmi_ucs2strlen(p->address));*/
        mmi_ucs2cat((PS8) info, tempBufUnicode);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");
    }
#ifdef __MMI_GPRS_FEATURES__
    else if(p->bearer == DATA_ACCOUNT_BEARER_GPRS)
    {
        mmi_ucs2cat((PS8) info, GetString(STR_ID_DTCNT_GPRS_APN));
        mmi_ucs2cat((PS8) info, (PS8) L":  ");
        memset(tempBufGprsAPN, 0, MAX_GPRS_MMI_APN_LEN * ENCODING_LENGTH);
        length = strlen(p->address);
        PRINT_INFORMATION("$$$$$ Dtcnt provisiong apn length = %d $$$$$", length);
        mmi_asc_n_to_ucs2(tempBufGprsAPN, (PS8) p->address, MAX_GPRS_MMI_APN_LEN);
        mmi_ucs2cat((PS8) info, tempBufGprsAPN);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_ota_charset_convert
 * DESCRIPTION
 *  This function shows information about a incoming profile. And ask users
 *  whether they want to install the profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_ota_charset_convert(S8 *scr, S8 *des, U8 len, U8 covertype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(covertype)
    {
    case MMI_DTCNT_UCS2_UTF8:
        str_len = mmi_chset_convert(
            MMI_CHSET_UCS2,
            MMI_CHSET_UTF8,
            (PS8)scr,
            (PS8)des,
            len);
    	break;

    case MMI_DTCNT_UTF8_UCS2:
        str_len = mmi_chset_convert(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (PS8)scr,
            (PS8)des,
            len);
        break;
    default:
        break;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_installation
 * DESCRIPTION
 *  This function shows information about a incoming profile. And ask users
 *  whether they want to install the profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_ota_entry_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *info;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_entry_install");

    if(!g_dtcnt_ota_cntx.g_dtcnt_ota_items)
    {
        return;
    }

    EntryNewScreen(SCR_ID_DTCNT_OTA_MAIN, NULL, mmi_dtcnt_ota_entry_install, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DTCNT_OTA_MAIN);

    /* Obtain a temporary buffer to show messages. */
    info = (PS8) subMenuData;

    mmi_dtcnt_ota_prepare_prof_info(info, g_dtcnt_ota_cntx.current_item);

    ShowCategory74Screen(
        STR_ID_CCA_INSTALL_SETTING,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        STR_GLOBAL_INSTALL,
        IMG_GLOBAL_YES,
        STR_ID_CCA_SKIP,
        IMG_GLOBAL_NO,
        (U8 *)info,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dtcnt_ota_select_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dtcnt_ota_profile_skip_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_dtcnt_ota_profile_skip_confirm, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dtcnt_ota_select_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetDelScrnIDCallbackHandler(SCR_ID_DTCNT_OTA_MAIN, mmi_dtcnt_ota_abort_install);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to VoIP
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_ota_profile_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_NOTIFICATION, NULL, mmi_dtcnt_ota_profile_skip_confirm, NULL);
    
    ShowCategory164Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_CCA_SKIP_PROFILE,
        IMG_GLOBAL_QUESTION,
        NULL);

    SetLeftSoftkeyFunction(mmi_dtcnt_ota_cca_rsp_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    playRequestedTone(WARNING_TONE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to VoIP
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_get_next_profile_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_dtcnt_ota_cntx.current_item)
    {
        g_dtcnt_ota_cntx.current_item = g_dtcnt_ota_cntx.g_dtcnt_ota_items;    
    }
    else
    {
        g_dtcnt_ota_cntx.current_item = g_dtcnt_ota_cntx.current_item->next;
    }

    /* Proceed to next valid profile. */
    while(g_dtcnt_ota_cntx.current_item != NULL)
    {
        if(g_dtcnt_ota_cntx.current_item->valid == TRUE)
        {
            break;
        }
        g_dtcnt_ota_cntx.current_item = g_dtcnt_ota_cntx.current_item->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_ota_cca_rsp_handler
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to VoIP
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_ota_cca_rsp_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_cca_rsp_handler");

    if (g_dtcnt_ota_cntx.g_dtcnt_ota_items == NULL) 
    {
        return;
    }

        if((GetActiveScreenId() == SCR_ID_DTCNT_OTA_MAIN) ||
           (GetActiveScreenId() == SCR_ID_DTCNT_LIST))
        {
            /* Clear the delete screen callback. */
            ClearDelScrnIDCallbackHandler(SCR_ID_DTCNT_OTA_MAIN, NULL);
            GoBackHistory();
        }
        else
        {
            /* Clear the delete screen callback. */
            ClearDelScrnIDCallbackHandler(SCR_ID_DTCNT_OTA_MAIN, NULL);
            DeleteScreenIfPresent(SCR_ID_DTCNT_LIST);
            DeleteScreenIfPresent(SCR_ID_DTCNT_OTA_MAIN);
        }
        
    if(GetActiveScreenId() == SCR_ID_DTCNT_NOTIFICATION)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_NOTIFICATION);
    }


    /* If there is no more profile to be installed. */
    if ((!g_dtcnt_ota_cntx.current_item->next) || 
        (!mmi_dtcnt_ota_has_next_valid_profile(g_dtcnt_ota_cntx.current_item->next))) 
    {
        /* Send a response back to CCA and free memory. */
        if(g_dtcnt_ota_cntx.num_installed)
        {
            mmi_dtcnt_ota_send_cca_app_configure_res(g_dtcnt_ota_cntx.conf_id, g_dtcnt_ota_cntx.doc_hdl, CCA_STATUS_OK);
        }
        else
        {
            mmi_dtcnt_ota_send_cca_app_configure_res(g_dtcnt_ota_cntx.conf_id, g_dtcnt_ota_cntx.doc_hdl, CCA_STATUS_SETTING_SKIPPED);
        }
        mmi_dtcnt_ota_terminate();

        return;
    }
    else
    {
        g_dtcnt_ota_cntx.index_profile ++;
        mmi_dtcnt_get_next_profile_data();
        mmi_dtcnt_ota_entry_install();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to VoIP
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_ota_proc_cca_doc(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Mapping table used to extract the VoIP settings for each profile. All 
     * characteristics are included such that unsupported fields can also be
     * found out.
     */
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE, DTCNT_OTA_NAPDEF, DTCNT_OTA_NAPDEF, 0xFFFF,
        CCA_NS_TRIGNODE, DTCNT_OTA_NAPDEF, DTCNT_OTA_NAPAUTHINFO, DTCNT_OTA_NAPAUTHINFO, 0xFFFF
    };

    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_proc_cca_doc");

    /* Whether any other OTA provisioning process is still running. */
    if (g_dtcnt_ota_cntx.g_dtcnt_ota_items != NULL)
    {
        MMI_ASSERT(0);  /* Guaranteed by CCA that this should not happen */
    }

    g_dtcnt_ota_cntx.conf_id = conf_id;
    g_dtcnt_ota_cntx.doc_hdl = doc_hdl;
    
    /* Extract data account settings from CCA configuration document, and store 
       settings in the temporary storage. */
    status = mmi_cca_doc_process(
                doc_hdl, 
                proc_tbl,
                sizeof(proc_tbl) / sizeof(U16),
                NULL, 
                mmi_dtcnt_ota_proc_cca_nodes, 
                &g_dtcnt_ota_cntx);


    /* If there is no correct VoIP profile, send a INVALID_SETTING response message back to CCA. */
    if (!mmi_dtcnt_ota_has_any_valid_profile()) 
    {        
        /* Now, terminate the OTAP OTA provisioning application. */
        mmi_dtcnt_ota_send_cca_app_configure_res(conf_id, doc_hdl, CCA_STATUS_INVALID_SETTING);
        mmi_dtcnt_ota_terminate();
        return;
    }

    g_dtcnt_ota_cntx.num_profiles = mmi_dtcnt_get_profiles_num();

    /* Setup callback to free memory and send message back to CCA when users
       press END key and return to idle screen, or when the app exits. */
    SetDelScrnIDCallbackHandler(SCR_ID_DTCNT_OTA_MAIN, mmi_dtcnt_ota_abort_install);

    /* Ready to install profiles. */
    mmi_dtcnt_get_next_profile_data();
    mmi_dtcnt_ota_entry_install();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_profiles_num
 * DESCRIPTION
 *  This function examines whether the configuration document has any settings
 *  relevant to data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  data_list       [IN]            Level one node IDs and application IDs
 * RETURNS
 *  Return CCA_STATUS_OK if the document is relevant to VoIP data account; 
 *  otherwise, return CCA_STATUS_NOT_FOUND.
 *****************************************************************************/
static U8 mmi_dtcnt_get_profiles_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 prof_num = 0;
    dtcnt_ota_item_struct *iter, *temp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Nothing to do. Return. */
    if (g_dtcnt_ota_cntx.g_dtcnt_ota_items == NULL) 
    {
        return 0;
    }

    iter = g_dtcnt_ota_cntx.g_dtcnt_ota_items;
    
    /* get num of profiles. */
    while(iter)
    {
        temp = iter;
        if(temp->valid)
        {
            prof_num++;
        }
        iter = iter->next;
    }

    return prof_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_is_cca_target
 * DESCRIPTION
 *  This function examines whether the configuration document has any settings
 *  relevant to data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  data_list       [IN]            Level one node IDs and application IDs
 * RETURNS
 *  Return CCA_STATUS_OK if the document is relevant to VoIP data account; 
 *  otherwise, return CCA_STATUS_NOT_FOUND.
 *****************************************************************************/
cca_status_enum mmi_dtcnt_ota_is_cca_target(U16 conf_id, S32 doc_hdl, cca_iterator_struct *data_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *node_list;
    S32 num_nodes;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check whether PX_SIP nodes are presented in the document. */
    status = mmi_cca_doc_get_nodes(doc_hdl, DTCNT_OTA_NAPDEF, &node_list, &num_nodes);
    if (status == CCA_STATUS_NOT_FOUND) {
        return CCA_STATUS_NOT_FOUND;
    }

    /* Release memory and return NOT_FOUND */
    mmi_cca_iterator_release(node_list);
    
    return CCA_STATUS_OK;;
}

/*DM Retrieve lixin 04162007*/
/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_ota_dm_retrieve_ind
* DESCRIPTION
*  DM -> CCA -> APP; Get Profile Indicate
* PARAMETERS
*  Info: Profile info
* RETURNS
* 
*****************************************************************************/
void mmi_dtcnt_ota_dm_retrieve_ind(U16 appid, S32 profid)
{
#ifdef SYNCML_DM_SUPPORT
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 bearer;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] DM_Retrieve_Indicate");

	g_dtcnt_dm_cntx.app_id = appid;
	g_dtcnt_dm_cntx.prof_id = profid;

	g_dtcnt_dm_cntx.check_status = mmi_dtcnt_ota_dm_check(g_dtcnt_dm_cntx.app_id, g_dtcnt_dm_cntx.prof_id, &bearer);

	if(g_dtcnt_dm_cntx.check_status == CCA_STATUS_OK)
	{
		mmi_dtcnt_get_CCA(bearer);
	}
	else
	{
		mmi_dtcnt_ota_dm_retrieve_rsp();
	}
#else
	return;
#endif /* SYNCML_DM_SUPPORT */
}

/*DM Update lixin 04162007*/
/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_ota_dm_update_ind
* DESCRIPTION
*  DM -> CCA -> APP; Update Profile Indicate
* PARAMETERS
*  info: Profile info
* RETURNS
*****************************************************************************/
void mmi_dtcnt_ota_dm_update_ind(U16 appid, S32 profid, S32 hconfig)
{
#ifdef SYNCML_DM_SUPPORT
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 bearer;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] DM_Update_Indicate");

	g_dtcnt_dm_cntx.app_id = appid;
	g_dtcnt_dm_cntx.prof_id = profid;
	g_dtcnt_dm_cntx.hconfig = hconfig;
	
	if(g_dtcnt_dm_cntx.hconfig <= 0)
	{
		ASSERT(0);
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		mmi_dtcnt_ota_dm_update_rsp();
		return;
	}

	g_dtcnt_dm_cntx.check_status = mmi_dtcnt_ota_dm_check(g_dtcnt_dm_cntx.app_id, g_dtcnt_dm_cntx.prof_id, &bearer);

	if(g_dtcnt_dm_cntx.check_status == CCA_STATUS_OK)
	{
		mmi_dtcnt_get_prof_by_cca(bearer, g_dtcnt_dm_cntx.hconfig);
	}
	else
	{
		mmi_dtcnt_ota_dm_update_rsp();
	}
#else
	return;
#endif /* SYNCML_DM_SUPPORT */
}

#ifdef SYNCML_DM_SUPPORT

/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_ota_dm_retrieve_rsp
* DESCRIPTION
*  Get Profile rsp
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
static void mmi_dtcnt_ota_dm_retrieve_rsp()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mmi_cca_app_get_prof_rsp_struct *myMsgPtr;
    MYQUEUE Message;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] DM_Retrieve_Rsp");

	myMsgPtr = (mmi_cca_app_get_prof_rsp_struct*) OslConstructDataPtr(sizeof(mmi_cca_app_get_prof_rsp_struct));
	myMsgPtr->app_id = g_dtcnt_dm_cntx.app_id;
    myMsgPtr->prof_id = g_dtcnt_dm_cntx.prof_id;
	
	if(g_dtcnt_dm_cntx.check_status == CCA_STATUS_OK)
	{
		myMsgPtr->result  = CCA_STATUS_OK;
		myMsgPtr->hConfig = g_dtcnt_dm_cntx.hconfig;
	}
	else
	{
		myMsgPtr->result  = CCA_STATUS_FAIL;
		myMsgPtr->hConfig = 0;
	}

	
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_CCA_APP_GET_PROF_RSP;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_get_CCA
* DESCRIPTION
*  Get Profile info by ProfID
* PARAMETERS
*  bearer : CSD, GPRS, WIFI
* RETURNS
*****************************************************************************/
static void mmi_dtcnt_get_CCA(U8 bearer)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_get_CCA()");

	switch(bearer)
    {
	case DTCNT_BEARER_GSM_CSD:
		 DataAccountReadyCheckForDM(mmi_dtcnt_get_cca_by_csd_prof);
	     break;

#ifdef __MMI_GPRS_FEATURES__
	case DTCNT_BEARER_GSM_GPRS:
		 DataAccountReadyCheckForDM(mmi_dtcnt_get_cca_by_gprs_prof);
		 break;
#endif

#ifdef __MMI_WLAN_FEATURES__
	case DTCNT_BEARER_WIFI:
		mmi_dtcnt_get_cca_by_wlan_prof();
		break;
#endif
	default:
		ASSERT(0);
		break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_ota_dm_check
* DESCRIPTION
*  check ProfID & AppId is Valid
* PARAMETERS
*  AppID: app id
*  ProfId: Profile Id
*  bearer: CSD, GPRS, WIFI
* RETURNS
*  Return CCA_STATUS_OK if the document is relevant to VoIP data account; 
*  otherwise, return CCA_STATUS_NOT_FOUND.
*****************************************************************************/
static cca_status_enum mmi_dtcnt_ota_dm_check(U16 app_id, U32 prof_id, U8 *bearer)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_ota_dm_check()");

	if(app_id != CCA_APP_DTACCT)
	{
		ASSERT(0);
		return CCA_STATUS_FAIL;
	}

	*bearer = mmi_dtcnt_get_bearer_type((U8) prof_id);

	if(*bearer == 0) /*Invalid DataAccount ID*/
	{
		ASSERT(0);
		return CCA_STATUS_FAIL;
	}

	return CCA_STATUS_OK; 

}


/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_get_cca_by_csd_prof
* DESCRIPTION
*  Get CSD Profile Info by id
* PARAMETERS
* 
* RETURNS
*****************************************************************************/
static void mmi_dtcnt_get_cca_by_csd_prof()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 dtcnt_id;
	S32 hConfig, hRoot, hNode;
    S8 temp_uft8_buff[(MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH];
    S8 temp_unicode_buff[(MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH];
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_dtcnt_dm_cntx.data_ready_status = FALSE;

	dtcnt_id = g_dtcnt_dm_cntx.prof_id - mmi_dtcnt_get_first_account_id(DATA_ACCOUNT_BEARER_CSD);
	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_get_cca_by_csd_prof()");

	if((dtcnt_id < 0) || (dtcnt_id >= MAX_DATA_ACCOUNT_GSM_LIMIT))
	{
		ASSERT(0);
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		mmi_dtcnt_ota_dm_retrieve_rsp();
		return;
	}
		
    memset((PS8) temp_uft8_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
	hRoot = mmi_cca_doc_new_rootnode( );
	if (!hRoot)
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		mmi_dtcnt_ota_dm_retrieve_rsp();
		return;
	}
	
	hNode = mmi_cca_doc_new_node_and_attach(DTCNT_OTA_NAPDEF, hRoot);
	if (!hNode)
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		mmi_cca_docroot_release(hRoot);
		mmi_dtcnt_ota_dm_retrieve_rsp();
		return;
	}
	
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_NODEID, (PS8) DTCNT_ITEM_CSD_NODE_ID);

    /* convert dataaccount name to utf8 string */
    mmi_dtcnt_ota_charset_convert((PS8)g_DataAccount[dtcnt_id].DataAccountName, 
                                  (PS8)temp_uft8_buff, 
                                  (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH,
                                  MMI_DTCNT_UCS2_UTF8);

	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAME, (PS8) temp_uft8_buff);

	mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_BEARER, CCA_NS_VAL_GSM_CSD);

    /* convert dataaccount dial_number to utf8 string */
    memset((PS8) temp_uft8_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    mmi_dtcnt_ota_charset_convert((PS8)g_DataAccount[dtcnt_id].DialNumber, 
                                  (PS8)temp_uft8_buff, 
                                  (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH,
                                  MMI_DTCNT_UCS2_UTF8);

	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAP_ADDRESS, (PS8) temp_uft8_buff);

    /* convert dataaccount dns_address to utf8 string */
    memset((PS8) temp_uft8_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    mmi_dtcnt_ota_charset_convert((PS8)g_DataAccount[dtcnt_id].DnsAddress, 
                                  (PS8)temp_uft8_buff, 
                                  (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH,
                                  MMI_DTCNT_UCS2_UTF8);

	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_DNS_ADDR, (PS8) temp_uft8_buff);

	if(g_DataAccount[dtcnt_id].DialType == DIAL_TYPE_ANALOGUE)
	{
		mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_CALLTYPE, CCA_NS_VAL_ANALOG_MODEM);
	}
	else
	{
		mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_CALLTYPE, CCA_NS_VAL_BIT_TRANSPARENT);
	}
	
	mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_LINKSPEED, g_DataAccount[dtcnt_id].DataRate);

	hNode = mmi_cca_doc_new_node_and_attach(DTCNT_OTA_NAPAUTHINFO, hNode);
	
    /* convert dataaccount user_name to utf8 string */
    memset((PS8) temp_uft8_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    memset((PS8) temp_unicode_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    mmi_asc_n_to_ucs2((PS8) temp_unicode_buff, (PS8) g_DataAccount[dtcnt_id].UserName, MAX_USER_LEN);
    mmi_dtcnt_ota_charset_convert((PS8)temp_unicode_buff, 
                                  (PS8)temp_uft8_buff, 
                                  (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH,
                                  MMI_DTCNT_UCS2_UTF8);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_AUTHNAME, (PS8) temp_uft8_buff);

    /* convert dataaccount password to utf8 string */
    memset((PS8) temp_uft8_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    memset((PS8) temp_unicode_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    mmi_asc_n_to_ucs2((PS8) temp_unicode_buff, (PS8) g_DataAccount[dtcnt_id].Passwd, MAX_USER_LEN);
    mmi_dtcnt_ota_charset_convert((PS8)temp_unicode_buff, 
                                  (PS8)temp_uft8_buff, 
                                  (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH,
                                  MMI_DTCNT_UCS2_UTF8);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_AUTHSECRET, (PS8) temp_uft8_buff);
		
	hConfig = mmi_cca_doc_new(hRoot);

	if(hConfig <= 0)
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		mmi_dtcnt_ota_dm_retrieve_rsp();
		return;
	}
	
	g_dtcnt_dm_cntx.hconfig = hConfig;
	g_dtcnt_dm_cntx.check_status = CCA_STATUS_OK;
	mmi_dtcnt_ota_dm_retrieve_rsp();

	return ;
}


#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_get_cca_by_gprs_prof
* DESCRIPTION
*  Get GPRS Profile Info by ID
* PARAMETERS
* 
* RETURNS
*****************************************************************************/
static void mmi_dtcnt_get_cca_by_gprs_prof()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 dtcnt_id;
	S32 hConfig, hRoot, hNode;
    S8 temp_uft8_buff[(MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH];
    S8 temp_unicode_buff[(MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH];
    S8 temp_unicode_apn[(MAX_GPRS_MMI_APN_LEN + 1) *ENCODING_LENGTH];
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_dtcnt_dm_cntx.data_ready_status = FALSE;
#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
/* under construction !*/
#else
    if((g_dtcnt_dm_cntx.prof_id < MAX_DATA_ACCOUNT_GSM_LIMIT) ||
	   (g_dtcnt_dm_cntx.prof_id >= (MAX_DATA_ACCOUNT_GSM_LIMIT + MAX_DATA_ACCOUNT_GPRS_LIMIT)))
#endif /* __MMI_OP01_GPRS_DATACFG__ */
	{
		ASSERT(0);
        g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		mmi_dtcnt_ota_dm_retrieve_rsp();
        return;
	}

	dtcnt_id = g_dtcnt_dm_cntx.prof_id - mmi_dtcnt_get_first_account_id(DATA_ACCOUNT_BEARER_GPRS);
	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_get_cca_by_gprs_prof()");

	hRoot = mmi_cca_doc_new_rootnode( );
	if (!hRoot)
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		mmi_dtcnt_ota_dm_retrieve_rsp();
		return;
	}
	
	hNode = mmi_cca_doc_new_node_and_attach(DTCNT_OTA_NAPDEF, hRoot);
	if (!hNode)
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		mmi_cca_docroot_release(hRoot);
		mmi_dtcnt_ota_dm_retrieve_rsp();
		return;
	}
	
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_NODEID, (PS8) DTCNT_ITEM_GPRS_NODE_ID);

    /* convert dataaccount name to utf8 string */
    memset((PS8) temp_uft8_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    mmi_dtcnt_ota_charset_convert((PS8)g_GPRS_DataAccount[dtcnt_id].DataAccountName, 
                                  (PS8)temp_uft8_buff, 
                                  (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH,
                                  MMI_DTCNT_UCS2_UTF8);

	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAME, (PS8) temp_uft8_buff);

	mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_BEARER, CCA_NS_VAL_GSM_GPRS);

    /* convert dataaccount apn to utf8 string */
    memset((PS8) temp_unicode_apn, 0, (MAX_GPRS_MMI_APN_LEN + 1) *ENCODING_LENGTH);
    mmi_dtcnt_ota_charset_convert((PS8)g_GPRS_DataAccount[dtcnt_id].APN, 
                                  (PS8)temp_unicode_apn, 
                                  (MAX_GPRS_MMI_APN_LEN + 1) *ENCODING_LENGTH,
                                  MMI_DTCNT_UCS2_UTF8);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAP_ADDRESS, (PS8) temp_unicode_apn);

    /* convert dataaccount DnsAddress to utf8 string */
    memset((PS8) temp_uft8_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    mmi_dtcnt_ota_charset_convert((PS8)g_GPRS_DataAccount[dtcnt_id].DnsAddress, 
                                  (PS8)temp_uft8_buff, 
                                  (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH,
                                  MMI_DTCNT_UCS2_UTF8);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_DNS_ADDR, (PS8) temp_uft8_buff);

	mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_CALLTYPE, CCA_NS_VAL_ANALOG_MODEM);

	hNode = mmi_cca_doc_new_node_and_attach(DTCNT_OTA_NAPAUTHINFO, hNode);
	if(g_GPRS_DataAccount[dtcnt_id].AuthType)
	{
		mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_AUTHTYPE, CCA_NS_VAL_CHAP);
	}
	else
	{
		mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_AUTHTYPE, CCA_NS_VAL_PAP);
	}
	
    /* convert dataaccount UserName to utf8 string */
    memset((PS8) temp_uft8_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    memset((PS8) temp_unicode_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    mmi_asc_n_to_ucs2((PS8) temp_unicode_buff, (PS8) g_GPRS_DataAccount[dtcnt_id].UserName, MAX_USER_LEN);
    mmi_dtcnt_ota_charset_convert((PS8)temp_unicode_buff, 
                                  (PS8)temp_uft8_buff, 
                                  (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH,
                                  MMI_DTCNT_UCS2_UTF8);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_AUTHNAME, (PS8) temp_uft8_buff);

    /* convert dataaccount password to utf8 string */
    memset((PS8) temp_uft8_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    memset((PS8) temp_unicode_buff, 0, (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH);
    mmi_asc_n_to_ucs2((PS8) temp_unicode_buff, (PS8) g_GPRS_DataAccount[dtcnt_id].Passwd, MAX_USER_LEN);
    mmi_dtcnt_ota_charset_convert((PS8)temp_unicode_buff, 
                                  (PS8)temp_uft8_buff, 
                                  (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH,
                                  MMI_DTCNT_UCS2_UTF8);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_AUTHSECRET, (PS8) temp_uft8_buff);
		
	hConfig = mmi_cca_doc_new(hRoot);
	
	if(!hConfig)
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		mmi_dtcnt_ota_dm_retrieve_rsp();
		return;
	}
	g_dtcnt_dm_cntx.hconfig = hConfig;
	g_dtcnt_dm_cntx.check_status = CCA_STATUS_OK;
	mmi_dtcnt_ota_dm_retrieve_rsp();

	return;
}
#endif

#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_get_cca_by_wlan_prof
* DESCRIPTION
*  Get WiFI Profile Info
* PARAMETERS
* 
* RETURNS
*****************************************************************************/
static void mmi_dtcnt_get_cca_by_wlan_prof()
{
	return;
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_ota_dm_update_rsp
* DESCRIPTION
*  update profile rsp
* PARAMETERS

* RETURNS
*****************************************************************************/
static void mmi_dtcnt_ota_dm_update_rsp()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mmi_cca_update_prof_rsp_struct *myMsgPtr;
    MYQUEUE Message;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] DM_Update_Rsp");

	myMsgPtr = (mmi_cca_update_prof_rsp_struct*) OslConstructDataPtr(sizeof(mmi_cca_update_prof_rsp_struct));
	myMsgPtr->app_id = g_dtcnt_dm_cntx.app_id;
    myMsgPtr->prof_id = g_dtcnt_dm_cntx.prof_id;
	
	if(g_dtcnt_dm_cntx.check_status == CCA_STATUS_OK)
	{
		myMsgPtr->result  = CCA_STATUS_OK;
		myMsgPtr->hConfig = g_dtcnt_dm_cntx.hconfig;
	}
	else
	{
		myMsgPtr->result  = CCA_STATUS_FAIL;
		myMsgPtr->hConfig = 0;
	}

	
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_get_prof_by_cca
* DESCRIPTION
*  Get profile info by cca hconfig
* PARAMETERS
*  bearer: csd, gprs, wifi
*  hConfig: cca doc handle
* RETURNS
*  Return CCA_STATUS_OK if the document is relevant to VoIP data account; 
*  otherwise, return CCA_STATUS_NOT_FOUND.
*****************************************************************************/
static void mmi_dtcnt_get_prof_by_cca(U8 bearer, s32 hconfig)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_get_prof_by_cca()");

	switch(bearer)
    {
	case DTCNT_BEARER_GSM_CSD:
	case DTCNT_BEARER_GSM_GPRS:
		mmi_dtcnt_get_gsm_prof_by_cca(bearer, hconfig);	
		break;
		
#ifdef __MMI_WLAN_FEATURES__
	case DTCNT_BEARER_WIFI:
		mmi_dtcnt_get_wlan_prof_by_cca(hconfig);
		break;
#endif
	default:
		ASSERT(0);
		break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_get_gsm_prof_by_cca
* DESCRIPTION
*  get gsm profile info 
* PARAMETERS
*  bearer: csd, gprs, wifi
*  hConfig: cca doc handle
* RETURNS
*****************************************************************************/
static void mmi_dtcnt_get_gsm_prof_by_cca(U8 bearer, S32 hconfig)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cca_status_enum status;

    /*
     * Mapping table used to extract the VoIP settings for each profile. All 
     * characteristics are included such that unsupported fields can also be
     * found out.
     */
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE, DTCNT_OTA_NAPDEF, DTCNT_OTA_NAPDEF, 0xFFFF,
        CCA_NS_TRIGNODE, DTCNT_OTA_NAPDEF, DTCNT_OTA_NAPAUTHINFO, DTCNT_OTA_NAPAUTHINFO, 0xFFFF
    };

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_get_gsm_prof_by_cca()");

	/* Extract data account settings from CCA configuration document, and store 
       settings in the temporary storage. */
    status = mmi_cca_doc_process(
                hconfig, 
                proc_tbl,
                sizeof(proc_tbl) / sizeof(U16),
                NULL, 
                mmi_dtcnt_dm_proc_cca_nodes, 
                &g_dtcnt_ota_cntx);

	if(status == CCA_STATUS_OK)
	{
		/*send save req to l4c*/
		mmi_dtcnt_save_prof_info(bearer);
	}
	else
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		mmi_dtcnt_ota_dm_update_rsp();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_dm_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
static cca_status_enum mmi_dtcnt_dm_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *param;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    switch (symbol)
    {
    case DTCNT_OTA_NAPDEF:
        
        status = CCA_STATUS_OK;             /* Initialize the status variable   */

        while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
        {   
            if(status == CCA_STATUS_OK)
            {
                status = mmi_dtcnt_ota_proc_cca_param(param, &g_dtcnt_dm_cntx.dm_item_cntx);
				g_dtcnt_dm_cntx.check_status = status;
            }
        }

        return CCA_STATUS_OK;
    
    case DTCNT_OTA_NAPAUTHINFO:

        status = CCA_STATUS_OK;             /* Initialize the status variable   */
        
        while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
        {   
            if(status == CCA_STATUS_OK)
            {
                status = mmi_dtcnt_ota_proc_cca_param(param, &g_dtcnt_dm_cntx.dm_item_cntx);
                g_dtcnt_dm_cntx.check_status = status;
            }
        }

        return CCA_STATUS_OK;
    default:
        return CCA_STATUS_OK;
    }
    return status;
}


#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_get_wlan_prof_by_cca
* DESCRIPTION
*  get wifi profile info
* PARAMETERS
*  hConfig: cca doc handle
* RETURNS
*****************************************************************************/
static void mmi_dtcnt_get_wlan_prof_by_cca(s32 hConfig)
{
	return;
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_save_prof_info
* DESCRIPTION
*  save profile info to l4c
* PARAMETERS
*  bearer: csd. gprs
* RETURNS
*****************************************************************************/
static void mmi_dtcnt_save_prof_info(U8 bearer)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 dtcnt_gprs_id;
	S32 dtcnt_csd_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(bearer == DTCNT_BEARER_GSM_CSD)
	{
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] Save_CSD_Profile_Info()");

		dtcnt_csd_id = g_dtcnt_dm_cntx.prof_id - mmi_dtcnt_get_first_account_id(DATA_ACCOUNT_BEARER_CSD);
		
		memset(&g_DataAccount[dtcnt_csd_id], 0, sizeof(DataAccountNode));
		
		strncpy((PS8)g_DataAccount[dtcnt_csd_id].DataAccountName, (PS8) g_dtcnt_dm_cntx.dm_item_cntx.name, MAX_DATA_ACCOUNT_NAME_LEN);
		
        if(!mmi_cca_is_ascii_string(g_dtcnt_dm_cntx.dm_item_cntx.name))
		{
            g_DataAccount[dtcnt_csd_id].iFdcs = mmi_ucs2strlen((PS8) g_DataAccount[dtcnt_csd_id].DataAccountName);
		}
		else
		{
			g_DataAccount[dtcnt_csd_id].iFdcs = 0;            
		}
		
		strncpy((PS8)g_DataAccount[dtcnt_csd_id].DialNumber, (PS8) g_dtcnt_dm_cntx.dm_item_cntx.address, MAX_DIAL_NUM_LEN);
		strcpy((char *) g_DataAccount[dtcnt_csd_id].UserName, (PS8) g_dtcnt_dm_cntx.dm_item_cntx.UserName);
		strcpy((char *) g_DataAccount[dtcnt_csd_id].Passwd, (PS8) g_dtcnt_dm_cntx.dm_item_cntx.Passwd);
		
		memcpy(g_DataAccount[dtcnt_csd_id].DnsAddress, g_dtcnt_dm_cntx.dm_item_cntx.DnsAddress, DTCNT_ITEM_DNS_LENGTH);
		g_DataAccount[dtcnt_csd_id].DialType = (U8) g_dtcnt_dm_cntx.dm_item_cntx.DialType;
		g_DataAccount[dtcnt_csd_id].DataRate = (U8) g_dtcnt_dm_cntx.dm_item_cntx.DataRate;
		g_DataAccount[dtcnt_csd_id].Present = DTCNT_ITEM_PRESENT_YES;
		
		mmi_dtcnt_ota_handle_set_csd_account_req(DTCNT_FOR_DM, (U8) dtcnt_csd_id);
	}
#ifdef __MMI_GPRS_FEATURES__
	else if(bearer == DTCNT_BEARER_GSM_GPRS)
	{
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] Save_GPRS_Profile_Info()");

		dtcnt_gprs_id = g_dtcnt_dm_cntx.prof_id - mmi_dtcnt_get_first_account_id(DATA_ACCOUNT_BEARER_GPRS);

		memset(&g_GPRS_DataAccount[dtcnt_gprs_id], 0, sizeof(GPRSDataAccountNode));

		//mmi_asc_n_to_ucs2((PS8)g_GPRS_DataAccount[dtcnt_gprs_id].DataAccountName, (PS8) g_dtcnt_dm_cntx.dm_item_cntx.name, MAX_GPRS_DATAACCOUNT_NAME);
        
        if(!mmi_cca_is_ascii_string(g_dtcnt_dm_cntx.dm_item_cntx.name))
        {
            /*mmi_dtcnt_ota_charset_convert((PS8)g_dtcnt_dm_cntx.dm_item_cntx.name, 
            (PS8)g_GPRS_DataAccount[dtcnt_gprs_id].DataAccountName, 
            (MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH,
            MMI_DTCNT_UTF8_UCS2);*/
        
            mmi_ucs2ncpy((PS8)g_GPRS_DataAccount[dtcnt_gprs_id].DataAccountName, 
                (PS8) g_dtcnt_dm_cntx.dm_item_cntx.name, 
                (MAX_DATA_ACCOUNT_NAME_LEN+1));
        
            if(mmi_dtcnt_check_UCS2((U16*)g_GPRS_DataAccount[dtcnt_gprs_id].DataAccountName, (U16)mmi_ucs2strlen((PS8)g_GPRS_DataAccount[dtcnt_gprs_id].DataAccountName)))
	    {
                g_GPRS_DataAccount[dtcnt_gprs_id].iFdcs = mmi_ucs2strlen((PS8) g_GPRS_DataAccount[dtcnt_gprs_id].DataAccountName) *ENCODING_LENGTH;
			
	    }
        }
	else
	{
            mmi_asc_n_to_ucs2((PS8)g_GPRS_DataAccount[dtcnt_gprs_id].DataAccountName, (PS8) g_dtcnt_dm_cntx.dm_item_cntx.name, MAX_GPRS_DATAACCOUNT_NAME);
			g_GPRS_DataAccount[dtcnt_gprs_id].iFdcs = 0;            
	}
		PRINT_INFORMATION("DATAACCOUNT: DM IFdcs = %d",g_GPRS_DataAccount[dtcnt_gprs_id].iFdcs);
		mmi_asc_n_to_ucs2((PS8)g_GPRS_DataAccount[dtcnt_gprs_id].APN, (PS8) g_dtcnt_dm_cntx.dm_item_cntx.address, MAX_GPRS_MMI_APN_LEN);
		
		strcpy((PS8) g_GPRS_DataAccount[dtcnt_gprs_id].UserName, (PS8) g_dtcnt_dm_cntx.dm_item_cntx.UserName);
		strcpy((PS8) g_GPRS_DataAccount[dtcnt_gprs_id].Passwd, (PS8) g_dtcnt_dm_cntx.dm_item_cntx.Passwd);
		
		memcpy(g_DataAccount[dtcnt_gprs_id].DnsAddress, g_dtcnt_dm_cntx.dm_item_cntx.DnsAddress, DTCNT_ITEM_DNS_LENGTH);
		g_GPRS_DataAccount[dtcnt_gprs_id].AuthType = (U8) g_dtcnt_dm_cntx.dm_item_cntx.AuthType;
		g_GPRS_DataAccount[dtcnt_gprs_id].Present = DTCNT_ITEM_PRESENT_YES;

		mmi_dtcnt_ota_handle_set_gprs_account_req(DTCNT_FOR_DM, (U8) dtcnt_gprs_id);
	}
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_dm_handle_set_csd_account_rsp
* DESCRIPTION
*  save csd profile rsp
* PARAMETERS
*  info: save result
* RETURNS
*****************************************************************************/
static void mmi_dtcnt_dm_handle_set_csd_account_rsp(void *info)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cc_set_csd_profile_rsp_struct *localPtr;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_cc_set_csd_profile_rsp_struct*) info;
	
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_dm_handle_set_csd_account_rsp");

	if(localPtr->result == KAL_TRUE)
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_OK; 
	}
	else
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
	}

    mmi_dtcnt_ota_dm_update_rsp();
}

#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_dm_handle_set_gprs_account_rsp
* DESCRIPTION
*  save gprs profile info rsp
* PARAMETERS
*  info: save result
* RETURNS
*****************************************************************************/
static void mmi_dtcnt_dm_handle_set_gprs_account_rsp(void *info)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_set_gprs_data_account_rsp_struct *localPtr;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_ps_set_gprs_data_account_rsp_struct*) info;
	
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_dm_handle_set_gprs_account_rsp");

	if(localPtr->result == KAL_TRUE)
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_OK; 
	}
	else
	{
		g_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
	}

    mmi_dtcnt_ota_dm_update_rsp();
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_dtcnt_dm_check
* DESCRIPTION
*  save gprs profile info rsp
* PARAMETERS
*  info: save result
* RETURNS
*****************************************************************************/
bf_bool mmi_dtcnt_dm_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] mmi_dtcnt_dm_check");

    if((GetActiveScreenId() == SCR_ID_DTCNT_MAIN) ||
       (IsScreenPresent(SCR_ID_DTCNT_MAIN)) ||
       (GetActiveScreenId() == SCR_ID_DTCNT_LIST) ||
       (IsScreenPresent(SCR_ID_DTCNT_LIST)) ||
       (DataAccountGetCheckStatus()))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
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
void DataAccountReadyCheckForDM(FuncPtr ready_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountProv.c] DataAccountReadyCheckForDM");

    g_dtcnt_dm_cntx.data_ready_status = TRUE;
    g_DTCNTReadyCallback = ready_callback;
	DTCNTGetAccountReq(0);
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
U8 mmi_dtcnt_ready_check(void)
{
    return g_dtcnt_dm_cntx.data_ready_status;
}

#endif /* SYNCML_DM_SUPPORT */
#endif /* __MMI_CCA_SUPPORT__ */
