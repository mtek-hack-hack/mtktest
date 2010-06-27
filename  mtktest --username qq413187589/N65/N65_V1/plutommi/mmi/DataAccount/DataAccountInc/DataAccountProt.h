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
 * DataAccount.h
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
#ifndef _DATA_ACCOUNT_PROT_H
#define _DATA_ACCOUNT_PROT_H

typedef int bf_bool;

extern wgui_inline_item wgui_inline_items[];
extern DataAccountNode g_DataAccount[MAX_DATA_ACCOUNT_GSM_LIMIT];
extern void (*g_DTCNTReadyCallback) (void);

#ifdef __MMI_GPRS_FEATURES__
extern GPRSDataAccountNode g_GPRS_DataAccount[];
#endif 

#ifdef __MMI_WLAN_FEATURES__

extern mmi_wlan_profile_struct g_wlan_prof_list[MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_wlan_profile_struct *g_wlan_profile[MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_wlan_display_struct g_wlan_display_context;
extern mmi_wlan_setting_struct g_wlan_setting_context;

#endif /* __MMI_WLAN_FEATURES__ */ 

extern void EntryDTCNTList(void);
extern void EntryDTCNTEdit(void);
extern void ExitDTCNTEdit(void);
extern void EntryDTCNTSave(void);
extern void EntryDTCNTProgress(void);

extern void DTCNTSetAccountReq(U8 ItemNum);
extern void DTCNTSetAccountRsp(void *info);
extern void DTCNTGetAccountReq(U8 ItemNum);
extern void DTCNTGetAccountRsp(void *info);

extern void HighlightDTCNTList(S32 nIndex);
extern void DataAccountEditNVRAM(void);
extern void InitInLineDataAccount(void);
extern void DataAccountFillInlineStruct(void);
extern U8 VerifyDataAcountChanges(void);
extern void DataAccountSaveChanges(void);
extern void GoToMainDataAccountScreen(void);
extern void ShowDataAccountOKMessage(void);
extern void DataAccountSavingScreenInProgress(U16 msdId);
extern void PreparedIPAddressString(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);
extern void ReturnThreeDigitString(PU8 StringVal, U8 DigitVal);
extern void DataAccountFullLineEditScreen(void);
extern void HighlightAppDTCNTList(S32 nIndex);
extern void EntryAppDTCNTList(void);
extern void AppDTCNTSelectOK(void);
extern void SetDynaDataAccountName(S8 *UCS2Name, U8 index);

#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
extern U8 DataAccountGetCheckStatus(void);
extern U8 mmi_dtcnt_ready_check(void);
extern bf_bool mmi_dtcnt_dm_check(void);
extern void DataAccountReadyCheckForDM(FuncPtr ready_callback);
#endif /* defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__) */

#ifdef __MMI_GPRS_FEATURES__
extern void EntryDTCNTGPRSList(void);
extern void EntryDTCNTGPRSEdit(void);
extern void ExitDTCNTGPRSEdit(void);
extern void EntryDTCNTGPRSSave(void);

extern void DTCNTGPRSGetAccountReq(U8);
extern void DTCNTGPRSGetAccountRsp(void *info);
extern void DTCNTGPRSSetAccountReq(U8);
extern void DTCNTGPRSSetAccountRsp(void *info);

extern void HighlightDTCNTGPRSList(S32);
extern void InitInLineGPRSDataAccount(void);
extern void GPRSDataAccountFillInlineStruct(void);
extern U8 VerifyGPRSDataAcountChanges(void);
extern void GPRSDataAccountSaveChanges(void);

extern void HighlightAppDTCNTMain(S32 nIndex);
extern void EntryDTCNTAppMain(void);
extern void AppDTCNTMainSelectOK(void);
extern void HighlightGPRSAppDTCNTList(S32 nIndex);
extern void EntryGPRSAppDTCNTList(void);
extern void GPRSAppDTCNTSelectOK(void);

#endif /* __MMI_GPRS_FEATURES__ */ 

#ifdef __MMI_WLAN_FEATURES__
extern void mmi_wlan_init(void);
extern void mmi_wlan_entry_eap_type(void);
extern void mmi_wlan_entry_main(void);
extern void mmi_wlan_eap_init_highlight_hdlr(void);

extern void mmi_wlan_send_init_req(void);
extern void mmi_wlan_send_deinit_req(void);
extern void mmi_wlan_send_connect_req(mmi_wlan_profile_struct *data);
extern void mmi_wlan_send_disconnect_req(void);
extern void mmi_wlan_send_ap_list_req(void);

extern void mmi_wlan_abm_ipaddr_change_req_hdlr(void);
extern void mmi_wlan_abm_wifi_init_req_hdlr(void);
extern void mmi_wlan_abm_wifi_init_cnf_hdlr(void *);
extern void mmi_wlan_abm_wifi_deinit_req_hdlr(void);
extern void mmi_wlan_abm_wifi_deinit_cnf_hdlr(void *);
extern void mmi_wlan_abm_wifi_connect_req_hdlr(void *);
extern void mmi_wlan_abm_wifi_connect_cnf_hdlr(void *);
extern void mmi_wlan_abm_wifi_connect_ind_hdlr(void *);
extern void mmi_wlan_abm_wifi_disconnect_req_hdlr(void);
extern void mmi_wlan_abm_wifi_disconnect_cnf_hdlr(void *);
extern void mmi_wlan_abm_wifi_disconnect_ind_hdlr(void *);
extern void mmi_wlan_abm_wifi_ap_list_req_hdlr(void);
extern void mmi_wlan_abm_wifi_ap_list_cnf_hdlr(void *);
extern void mmi_wlan_abm_ipaddr_update_ind_hdlr(void *info);
extern void mmi_wlan_supc_mmi_wifi_curr_ap_info_ind_hdlr(void *);
extern void mmi_wlan_abm_wifi_activate_req_ind_hdlr(void *);
extern void mmi_wlan_abm_wifi_deactivate_req_ind_hdlr(void *);
extern void mmi_wlan_abm_ipaddr_conflict_ind_hdlr(void *info);
extern void mmi_wlan_redraw_conn_status_screen(void);
extern void mmi_wlan_redraw_network_settings_screen(void);

extern void mmi_wlan_update_conn_status_str(void);
extern void mmi_wlan_update_signal_level_icon(void);
extern void mmi_wlan_update_status_icon(U16 image_id, BOOL animate);
extern void mmi_wlan_entry_scan_result(void);
extern mmi_wlan_profile_struct *mmi_wlan_find_profile(U32 profile_id);
extern void mmi_wlan_init_profile(mmi_wlan_profile_struct *profile);
extern void bssinfo_to_profile(
                mmi_wlan_profile_struct *prof,
                supc_abm_bss_info_struct *bssinfo,
                const char *passphrase,
                int keylen);
extern kal_bool encode_eap_profile(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile);

extern void delete_action(wlan_action_struct **handle, wlan_action_enum action);
extern void add_action(wlan_action_struct **handle, wlan_action_enum action, void *data);

extern BOOL hex_to_string(U8 *dest, U8 *src, U8 len);
extern BOOL is_valid_hexstring(U8 *src, U8 len);
extern const char* state2str(wlan_state_enum state);

extern void pbkdf2_sha1(
                const char *passphrase,
                const char *ssid,
                kal_uint16 ssid_len,
                int iterations,
                kal_uint8 *buf,
                kal_uint16 buflen);

#endif /* __MMI_WLAN_FEATURES__ */ 
#endif /* _DATA_ACCOUNT_PROT_H */ 

