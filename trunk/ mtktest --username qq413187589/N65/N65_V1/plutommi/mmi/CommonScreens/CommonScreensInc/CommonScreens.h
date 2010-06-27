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
 *  CommonScreens.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : CommonScreens.h

   PURPOSE     : Common screens used by applications

   REMARKS     : 

   AUTHOR      : manju

   DATE     : Aug-06-2003

**************************************************************/

/* MTK Add Terry  for multi language IME */
#include "MMI_features.h"
/* MTK End */
#include "GlobalConstants.h"
#include "GlobalDefs.h"
#include "CustMenuRes.h"
#include "CustDataRes.h"
#include "FrameworkStruct.h"
#include "EventsGprot.h"
#include "HistoryGprot.h"
#include "wgui_categories.h"
#include "Unicodexdcl.h"
#include "IdleAppDef.h"
#include "CommonScreensenum.h"
#include "ScreenRotationGprot.h"

#ifndef __COMMONSCREENS_H__
#define __COMMONSCREENS_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /*  POPUP behavior defined by mask */
#define  POPUP_ALL_OFF  0x00
#define  POPUP_DSPL_ON  0x01
#define  POPUP_TONE_ON  0x02
#define  POPUP_PMIC_ON  0x04
#define  POPUP_ALL_ON   0xFF

    /*  POPUP screen attribute  */
#define UI_POPUP_NOTIFYDURATION_TIME            1000
#define UI_POPUP_NOTIFYDURATION_TIME_2000       2000

    /* MTK Terry : Multitap for Star and Pound */
    extern void EntryQuickSearchInputMethodScreen(void);
    extern void ExitQuickSearchInputMethodScreen(void);

    extern void EntryInputMethodScreen(void);
    extern void ExitInputMethodScreen(void);
    extern void EntryAPRequiredInputMethodScreen(void);
    extern void ExitAPRequiredInputMethodScreen(void);

    extern void EntryInLineMultilineEditorOption(void);
    extern void ExitInLineMultilineEditorOption(void);
    extern void RegisterInputMethodScreenCloseFunction(void (*f) (void));
    extern void RegisterInputMethodScreenEntryCallback(void (*f) (void));
    extern void RegisterInputMethodScreenExitCallback(void (*f) (void));
    extern void RegisterSymbolTableScreenEntryCallback(void (*f) (void));
    extern void RegisterSymbolTableScreenExitCallback(void (*f) (void));
    extern void ResetInputMethodScreenEntryCallback(void);
    extern void ResetInputMethodScreenExitCallback(void);
    extern void ResetSymbolTableScreenEntryCallback(void);
    extern void ResetSymbolTableScreenExitCallback(void);
    extern void ConfirmInlineFullScreenEdit(void);
    extern void CancelInlineFullScreenEdit(void);

    extern void EntrySymbolPickerScreen(void);
    extern void ExitSymbolPickerScreen(void);
    extern void SymbolPickerHandleLSKFromMenuList(void);
    extern void SymbolPickerHandleRSKFromMenuList(void);
    extern void EntrySymbolPickerScreenFromMenuList(void);
    extern void ExitSymbolPickerScreenFromMenuList(void);
    extern void SetInputMethodAndDoneCaptionIcon(U16 IconId);
    extern void EntryScrForInputMethodAndDone(void);
    extern void ExitScrForInputMethodAndDone(void);
    extern void PrepareSymbolTableAndShowCategory(U8 *guiBuffer);

    extern const U16 gIndexIconsImageList[];

    extern void DisplayPopup(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId);
#ifdef __MMI_SCREEN_ROTATE__
    extern void DisplayPopupRotated(
                    U8 *string,
                    U16 imageId,
                    U8 imageOnBottom,
                    U32 popupDuration,
                    U8 toneId,
                    mmi_frm_screen_rotate_enum rotation);
#endif /* __MMI_SCREEN_ROTATE__ */ 
    extern void ExitDisplayPopup(void);
    extern void DisplayPopupCallBack(
                    U8 *string,
                    U16 imageId,
                    U8 imageOnBottom,
                    U32 popupDuration,
                    U8 toneId,
                    FuncPtr f);
    extern void ExitDisplayPopupCallBack(void);
    extern void PopupTimerFlagEnable(void);
    extern void PopupCloseByPressAnyKey(void);
    extern void PopupTimerOver(void);
    extern void PopupTimerOverCallBack(void);
#if !defined(__MTK_TARGET__)
    extern void PopupNoSupport(void);
#endif 
    extern void DisplayConfirm(
                    U16 LSK_str,
                    U16 LSK_img,
                    U16 RSK_str,
                    U16 RSK_img,
                    UI_string_type message,
                    MMI_ID_TYPE message_image,
                    U8 toneId);
    extern void DisplayConfirmExt(
                    U16 LSK_str,
                    U16 LSK_img,
                    U16 RSK_str,
                    U16 RSK_img,
                    U16 CSK_str,
                    U16 CSK_img,
                    UI_string_type message,
                    MMI_ID_TYPE message_image,
                    U8 toneId);
#ifdef __MMI_SCREEN_ROTATE__
    extern void DisplayConfirmRotated(
                    U16 LSK_str,
                    U16 LSK_img,
                    U16 RSK_str,
                    U16 RSK_img,
                    UI_string_type message,
                    MMI_ID_TYPE message_image,
                    U8 toneId,
                    mmi_frm_screen_rotate_enum rotation);
    extern void DisplayConfirmRotatedExt(
                    U16 LSK_str,
                    U16 LSK_img,
                    U16 RSK_str,
                    U16 RSK_img,
                    U16 CSK_str,
                    U16 CSK_img,
                    UI_string_type message,
                    MMI_ID_TYPE message_image,
                    U8 toneId,
                    mmi_frm_screen_rotate_enum rotation);
#endif /* __MMI_SCREEN_ROTATE__ */ 
    extern void DisplayConfirmCountDown(
                    U16 LSK_str,
                    U16 LSK_img,
                    U16 RSK_str,
                    U16 RSK_img,
                    UI_string_type message,
                    MMI_ID_TYPE message_image,
                    U8 toneId,
                    U32 duration,
                    FuncPtr callback);
    extern void ExitDisplayPopupConfirm(void);
    extern void mmi_frm_set_highlight_handler(void);

    extern void DisplaySubLcdPopup(U16 imageId);
    extern void SetInterruptPopupDisplay(U8 flag);  /* To set the popup screen is allow to display or not. */
    extern U8 GetInterruptPopupDisplay(void);       /* To get the popup screen is allow to display or not. */

#ifdef __cplusplus
}
#endif 

#endif /* __COMMONSCREENS_H__ */ 

