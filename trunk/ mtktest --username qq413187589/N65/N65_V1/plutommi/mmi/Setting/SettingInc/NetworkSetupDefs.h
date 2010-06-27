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
 * NetworkSetupDefs.h
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

#ifndef _NETWORKSETUPDEFS_H
#define _NETWORKSETUPDEFS_H

#define  PLMN_NAME_LENGTH     30
// #define  CS_NOTIFYDURATION    UI_POPUP_NOTIFYDURATION_TIME

/* micha0715 */
#define  NETSETMSGQUEUESIZE   5

/* micha1109 */
#define  SET_GPRS_MODE_DELAY  2000      /* diamond, 2005/06/15 modified to avoid power off during the set GPRS mode period */

enum NETSET_OPERATION
{
    NETSET_OP_NONE,
    NETWORK_SELECTION,
    NETWORK_RESTORE,
    GET_PLMN_LIST,
    BAND_SELECTION
};

#ifdef __MMI_WLAN_FEATURES__
enum NETSET_PREFERRED_MODE
{
    P_GSM_ONLY,
    P_WLAN_ONLY,
    P_GSM_PREFERRED,
    P_WLAN_PREFERRED,
    P_MODE_END
};

enum NETSET_DIAL_MODE
{
    DIAL_MODE_GSM,
    DIAL_MODE_WLAN
};
#endif /* __MMI_WLAN_FEATURES__ */

typedef struct
{
    U8 ItemType;
    FuncPtr CallBackFunc;
    U16 MsgID;
    PsFuncPtr CallBackRspHandler;
} NetworkSetupMsgQueueEntity;

typedef struct
{
    U8 Index;
    U8 Top;
    NetworkSetupMsgQueueEntity Queue[NETSETMSGQUEUESIZE];
} NetworkSetupMsgQueue;

typedef struct
{
    U8 PLMNRequested[MAX_PLMN_LEN + 1]; /* last requested PLMN */
    U8 NetworkSelectAbort;              /* ignore response if user pressed abort */
    U8 BandType;
#ifdef __MMI_GPRS_FEATURES__
    U8 GPRSConnType;
#endif 
    mmi_nw_get_plmn_list_rsp_struct *PlmnList;
    U8 reg_fail_flag;
    U8 forbid_plmn[MAX_PLMN_LIST_LEN];
    U8 forbid_plmn_id[MAX_PLMN_LIST_LEN][MAX_PLMN_LEN + 1];
} NetworkSetupContext;

typedef struct
{
    U16 *PLMNListIcons;
    U8 CurrSelectNetwork;
    /* micha_Man_sel */
    U8 TempCurrSelectNetwork;
    U8 *PLMNName[MAX_PLMN_LIST_LEN];
    U8 CurrSelectBand;
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 
#ifdef __MMI_WLAN_FEATURES__
    U8 PreferredModeCurrentIndex;
    U8 DialModeCurrentIndex;
#ifndef __MMI_UCM__
    U8 DigitScreenDialMode;
#endif
    FuncPtr GSMCallEntryPtr;
    FuncPtr WLANCallEntryPtr;
#endif
} NetworkSetupDisplay;

extern void HighlightNETSETMain(void);
extern void HighlightNETSETSelectionMode(void);
extern void HighlightNETSETSelectionManual(void);
extern void HighlightNETSETSelectionAuto(void);
extern void HighlightNETSETPreferredNetworks(void);
extern void HighlightNETSETBandSelection(void);
extern void HintNETSETBandSelection(U16);
extern void HintNETSETSelectionMode(U16);
extern void HiliteHandlerShowPLMNList(S32);
extern void HiliteHandlerBandSelection(S32);

extern void EntryNETSETMain(void);
extern void EntryNETSETSelectionMode(void);
extern void EntryNETSETShowPlmnList(void);
extern void ExitNETSETShowPLMNList(void);
extern void EntryNETSETBandSelection(void);

extern void NETSETGetPLMNListReq(void);
extern void NETSETGetPLMNListRsp(void *);
extern void NETSETAutoNetworkSearchReq(void);
extern void NETSETAutoNetworkSearchRsp(void *);
extern void NETSETManualSelectNetworkReq(void);
extern void NETSETManuSelectNetworkRsp(void *);
extern void NETSETAbortPLMNListReq(void);
extern void NETSETAbortPLMNListRsp(void *);
extern void NETSETSetBandSelectionReq(void);
extern void NETSETSetBandSelectionRsp(void *);
extern void NETSETGetBandSelectionReq(void);
extern void NETSETGetBandSelectionRsp(void *);

extern void EntryNETSETAutoSearchProgress(void);
extern void ExitNETSETAutoSearchProgress(void);
extern void EntryNETSETManualSearchProgress(void);
extern void ExitNETSETManualSearchProgress(void);
extern void EntryNETSETBandSelectionProgress(void);
extern void ExitNETSETBandSelectionProgress(void);
extern void EntryNETSETManualRegProgress(void);
extern void ExitNETSETManualRegProgress(void);

extern void RestorePreviousNetwork(void);
extern void GoBackNetSelection(void);
extern void AbortManualRegGoBack(void);
extern void AbortManualRegToIdle(void);
extern void AbortAutoSearchGoBack(void);
extern void AbortAutoSearchToIdle(void);
extern void AbortGetPLMNListToIdle(void);

extern void NETSETGetPLMNListCheck(void);
extern void NETSETManualSelectNetworkCheck(void);
extern void NETSETManualNetworkRestoreReq(void);
extern void NETSETSetBandSelectionCheck(void);
extern void NETSETAutoSelectNetworkCheck(void);
extern void NETSETMsgQueueIndexAddOne(void);
extern void NETSETMsgQueueTopAddOne(void);
extern void NETSETMsgQueueTopMinusOne(void);
extern U8 NETSETMsgQueueGetPreviousTop(void);
extern U8 NETSETMsgQueueGetPreviousIndex(void);
extern void NETSETMsgQueueProtocolHandler(void *info);
extern void NETSETMsgQueuePush(U8 ItemType, FuncPtr CallBackFunc, U16 MsgID, PsFuncPtr CallBackRspHandler);
extern U8 NETSETMsgQueueCheckCurrOP(void);
extern U8 NETSETMsgQueueCheckLastOP(void);
extern void ExitNETSETSelectionMode(void);

#ifdef __MMI_GPRS_FEATURES__
extern void HighlightNETSETGPRSConnectionMode(void);
extern void HintNETSETGPRSConnectionMode(U16 index);
extern void NETSETSetGPRSConnModeReq(void);

/* micha1109 */
extern void NETSETSetGPRSConnModeTimeOut(void);
extern void NETSETSetGPRSConnModeRsp(void *info);
extern void NETSETGetGPRSModeReq(void);
extern void NETSETGetGPRSModeRsp(void *info);
#endif /* __MMI_GPRS_FEATURES__ */ 

/* micha_Man_sel */
#ifdef __MANUAL_MODE_NW_SEL__
extern void HighlightNETSETSelectionModeChoice(void);
extern void EntryNETSETSelectionModeReq(void);
extern void EntryNETSETSelectionModeRsp(void *info);
#endif /* __MANUAL_MODE_NW_SEL__ */ 

#ifdef __MMI_WLAN_FEATURES__

extern void mmi_netset_highlight_preferred_mode(void);
extern void mmi_netset_entry_preferred_mode(void);
extern void mmi_netset_hint_preferred_mode(U16);
extern void mmi_netset_preferred_mode_highlight_hdlr(S32);
extern void mmi_netset_preferred_mode_switch_done(void);
extern void mmi_netset_switch_preferred_mode(void);
extern void mmi_netset_pre_check_preferred_mode(void);
extern U8 mmi_netset_get_active_preferred_mode(void);
extern void mmi_netset_update_preferred_mode_menu(void);
extern void mmi_netset_init_wlan_setting(void);
extern void mmi_netset_update_preferred_mode_service_area(void);

#ifdef __MMI_VOIP__
#ifndef __MMI_UCM__
extern void mmi_netset_highlight_dialer_option_dial(void);
extern void mmi_netset_highlight_dialer_option_phonebook_save(void);
extern void mmi_netset_highlight_dialer_option_input_method(void);
extern void mmi_netset_highlight_dialer_option_change_dial_mode(void);
extern void mmi_netset_entry_dialpad_call_by_wlan(void);
extern void mmi_netset_entry_change_dial_mode(void);
extern void mmi_netset_set_dial_mode(U8 mode);
extern U8 mmi_netset_get_dial_mode(void);
extern void mmi_netset_enter_wlan_dialer_option(void);
extern void mmi_netset_register_call_entry_func(FuncPtr gsm_call_ptr, FuncPtr wlan_call_ptr);
extern void mmi_netset_entry_dial_mode_selection(void);
#endif /* __MMI_UCM__ */
extern void mmi_netset_enter_wlan_dialer_screen(void);
#endif /* __MMI_VOIP__ */

extern void mmi_netset_register_wlan_stauts_cb(U16);
extern void mmi_flight_mode_switch_wlan(void);
extern void mmi_phnset_switch_flight_mode(void);
extern void mmi_netset_enter_wlan_flight_mode(void);
extern void mmi_netset_exit_wlan_flight_mode(void);

#endif /* __MMI_WLAN_FEATURES__ */

extern void mmi_netset_entry_add_network_priority_and_service(void);
extern void mmi_netset_retrieve_current_modes(void);

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
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
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 

#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
extern void mmi_netset_highlight_user_ctrl_plmn(void);
extern void mmi_netset_init_user_ctrl_plmn(void);
extern U8 mmi_netset_unknown_operator_check(void);
extern void mmi_netset_unknown_operator_query(void);
#endif /* __MMI_USER_CTRL_PLMN_SUPPORT__ */ 

#ifndef __MTK_TARGET__
extern void mmi_netset_highlight_menu_not_support(void);
#endif

#endif /* _NETWORKSETUPDEFS_H */ 

