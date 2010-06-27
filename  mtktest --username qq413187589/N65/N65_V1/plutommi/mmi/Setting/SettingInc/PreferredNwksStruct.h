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
 * PreferredNwksStruct.h
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
#ifndef _PIXCOM_PREFERREDNWKS_STRUCT_H
#define _PIXCOM_PREFERREDNWKS_STRUCT_H

/* moved to custom_mmi_default_value.h */
/* #define  MAX_PREFFERED_PLMN   MAX_SUPPORT_EF_PLMNSEL_REC */

#define  MAX_PRIORITY_DIGITS  3
#define  CS_NOTIFYDURATION    UI_POPUP_NOTIFYDURATION_TIME
#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
#define MAX_USER_CTRL_PLMN 20
#endif

typedef struct _pref_network_list_struct
{
    U16 PrefListSize;
    U16 SimFileIdx;
    U8 PrefPLMN[MAX_PREFFERED_PLMN][MAX_PLMN_LEN + 1];
    U8 rat[MAX_PREFFERED_PLMN];
    U8 comp_flag;
} PrefNetworkListContext;

typedef struct _pref_network_list_display
{
    S32 PriorityVal;
    S8 PrefNetworkListDislpay[MAX_PREFFERED_PLMN][MAX_LENGTH_DISPLAY_NAME *ENCODING_LENGTH];
    U8 PlmnNew[(MAX_PLMN_LEN + 1) *ENCODING_LENGTH];
    U8 NewNwPriorityDisplay[MAX_PREFFERED_PLMN];
    PU8 nStrItemList[MAX_PREFFERED_PLMN];
    U8 IsNewPrefNetwork;
    U8 CurrSelPrefNetwork;
    U16 CurrSelAddPLMN;
    U8 PrefNwGotResponse;
    U8 SortingMethod;       /* 0: by conntry (default), 1: by alphabet */
    U16 *SortingArray;
    /* 2006/02/16 USIM preferred network implementation */
    S32 CurrSelectService;  /* selected service from 'WCDMA' or 'GSM' */
    U16 PLMNListIcons[MAX_PREFFERED_PLMN];
} PrefNetworkListDisplay;

#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
typedef struct _user_ctrl_plmn_list_struct
{
    U8 PlmnListSize;
    U8 CurrSelPlmn;
    /* idle screen callback variables */
    U8 UnknownOpCheck;
    /* plmn list buffers */
    U8 PrefPLMN[MAX_USER_CTRL_PLMN][24];
    U8 tmpPlmnListData[MAX_USER_CTRL_PLMN][MAX_LENGTH_DISPLAY_NAME *ENCODING_LENGTH];
    /* user added plmn data */
    U8 PlmnAddNumber[(MAX_PLMN_LEN + 1) *ENCODING_LENGTH];
    U8 PlmnAddString[MAX_LENGTH_DISPLAY_NAME *ENCODING_LENGTH];
} UserCtrlPlmnListContext;
#endif /* __MMI_USER_CTRL_PLMN_SUPPORT__ */ 

extern void HighlightNETSETAddPrefNwk(void);
extern void HighlightNETSETEditPrefNwk(void);
extern void HighlightNETSETDelPrefNwk(void);
extern void HighlightNETSETNewPrefNwk(void);
extern void HiliteHandlerPrefList(S32 hiliteIdx);
extern void HiliteHandlerAddNetworkPLMNList(S32 hiliteIdx);

extern void EntryNETSETEditNetwork(void);
extern void EntryNETSETAddNetworkPLMNList(void);
extern pBOOL NETSETGetPrefNetworkListItem(S32, UI_string_type, PU8 *, U8);
extern S32 NETSETGetPrefNetworkListHint(S32, UI_string_type *);
extern void EntryNETSETShowPrefNwkOptions(void);
extern void EntryNETSETShowPreferredList(void);
extern void ExitNETSETShowPreferredListReGet(void);
extern void EntryNETSETNewNetwork(void);
extern void ExitNETSETNewNetwork(void);
extern void EntryNETSETAddNetworkPriority(void);
extern void EntryNETSETConfirmDeleteNetwork(void);
extern void ExitNETSETConfirmDeleteNetwork(void);

extern void NETSETEditNetworkAddPhaseReq(void);
extern void NETSETEditNetworkAddPhaseRsp(void *info);
extern void NETSETEditNetworkDeletePhaseReq(void);
extern void NETSETEditNetworkDeletePhaseRsp(void *info);
extern void NETSETGetPreferredNetworkReq(void);
extern void NETSETGetPreferredNetworkRsp(void *info);
extern void NETSETAddPrefNetworkReq(void);
extern void NETSETAddPrefNetworkRsp(void *info);
extern void NETSETDeletePrefNetworkReq(void);
extern void NETSETDeletePrefNetworkRsp(void *info);

extern U8 IsNetworkDuplicated(void);
extern void ConstructPreferredListHint(U8 **hintArray);
extern PS8 GetCurrentPLMNName(S8 *PlmnNo);
extern U16 GetPrefNwkNameFromPLMN(void);    /* PU8 *Dispnames); */
extern void GoBackNetworkSetup(void);
extern void ChcekThenAddNetwork(void);
extern void GoBackPrefList(void);
extern void SendNewPrr(void);
extern void FillNewPrefNetworkInlineEditStruct(void);
extern void HiliteHandlerPrefNwkHideAddIfFull(S32 index);
extern U8 *InLinePriorityDefault(void);
extern U8 *InLinePriorityMinusOne(void);
extern U8 *InLinePriorityAddOne(void);

extern void playRequestedTone(ALL_TONE_ENUM);
extern void stopRequestedTone(ALL_TONE_ENUM);
extern wgui_inline_item wgui_inline_items[];

#endif /* _PIXCOM_PREFERREDNWKS_STRUCT_H */ 

