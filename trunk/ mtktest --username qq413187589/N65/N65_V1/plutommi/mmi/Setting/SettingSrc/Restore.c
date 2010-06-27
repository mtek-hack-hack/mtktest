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
 * Restore.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for restore factory default application
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
/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : Restore.c

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru

   DATE     : 11/14/2003

**************************************************************/
/***************************************************************************** 
* Include
*****************************************************************************/
/*  Include: MMI header file */
#include "MMI_include.h"
#include "CommonScreens.h"
#include "MiscFunctions.h"
#include "AudioInc.h"
#include "MainMenuDef.h"
#include "ProtocolEvents.h"
#include "IdleAppDef.h"
#include "SettingProfile.h"
#include "SettingsGexdcl.h"
#include "settingGprots.h"
#include "settingprot.h"
#include "ScreenSaverDefs.h"
#include "WPSSProtos.h"
#include "ScheduledPowerOnOffGprot.h"
#include "PhonebookGprot.h"
#include "CallSetUpEnum.h"
#include "SimDetectionGexdcl.h"
#include "PhoneSetupGprots.h"
#include "SecuritySetup.h"

#ifdef __MOD_SMSAL__
#include "MessagesExDcl.h"
#endif 

#include "SettingDefs.h"
#include "SettingsGdcl.h"


#ifdef __MMI_TOUCH_SCREEN__
#include "Wgui_touch_screen.h"
#endif 

#include "AlarmFrameWorkProt.h"
#include "nvram_enums.h"

#if !defined(__MTK_TARGET__)
#include "EngineerModeDef.h"
#endif 

#if !defined(MMI_ON_WIN32) && defined(__J2ME__)
#include "jal.h"
#include "j2me_custom.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern U8 CurrentDtType;
extern U8 gCallCost;
extern U8 gIsSimValid;
extern alm_queue_node_struct gAlmQueue[ALM_NUM_OF_ALAMRS];
extern alm_framework_context_struct g_alm_frm_cntx;

/***************************************************************************** 
* Global Variable
*****************************************************************************/
pBOOL bStatus = FALSE;
U8 gPhonePassword[(MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH];

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* External Function
*****************************************************************************/
extern pBOOL SetProfileDefault(void);
extern void EntryScrnSimBlockRsp(void);

extern void AlmDeInit(void);

#if !defined(MMI_ON_WIN32) && defined(__J2ME__)
extern void javaFileGenerator(game_type_enum type, kal_bool force_remove_all);
#endif

#ifdef __MMI_PREFER_INPUT_METHOD__
extern void SetInputMethodType(U16 inputType);
#endif 
#ifdef __MMI_EBOOK_READER__
#include "EbookManager.h"
#endif /* __MMI_EBOOK_READER__ */
/*****************************************************************************
 * FUNCTION
 *  HighlightRstScr
 * DESCRIPTION
 *  This function is Highlight handler for  "Resotre"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRstScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    /* Register function for left/right soft key */
#ifdef MMI_ON_HARDWARE_P
    SetLeftSoftkeyFunction(EntryRstScr, KEY_EVENT_UP);
#else 
    SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
#endif 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* Register function for left/right arrow keys */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryRstScr
 * DESCRIPTION
 *  This function is Entry function for "Restore"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRstScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __HALF_SECURE_RESTORE__
    if (GetPhoneLock() == MMI_FALSE)
    {
        EntryRstConfirm();
    }
    else
    {
        EntryRstCheckPhoneLock();
    }
#else /* __HALF_SECURE_RESTORE__ */ /* Check phone lock code before restore default */
    EntryRstCheckPhoneLock();
#endif /* __HALF_SECURE_RESTORE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  EntryRstCheckPhoneLock
 * DESCRIPTION
 *  This function is Entry function for Restore->Enter Phone Lock Code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRstCheckPhoneLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] EntryRstCheckPhoneLock()\n");

    /* Call Exit Handler */
    EntryNewScreen(SCR_RESTORE, NULL, EntryRstScr, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_RESTORE);

    /* check the screen flow is from forward or backward */
    if (guiBuffer == NULL)
    {
        memset(gPhonePassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
    }

    /* register the input validation function handler */
    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);

    /* display the corresponding catergory function */
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_RESTORE_PHONE,
        INPUT_TYPE_NUMERIC_PASSWORD,
        gPhonePassword,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        NULL,
        guiBuffer);

    /* Register function with left/right softkey */
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(RstVerifyPhoneLockReq, KEY_EVENT_UP);

    /* register the key handler function for the pound key */
    SetKeyHandler(RstVerifyPhoneLockReq, KEY_POUND, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = RstVerifyPhoneLockReq;

    if (mmi_ucs2strlen((S8*) gPhonePassword) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  RstVerifyPhoneLockReq
 * DESCRIPTION
 *  This function is to send phone lock code to L4 to verify,
 *  this is left softkey handler for Restore->Enter Phone Lock Code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RstVerifyPhoneLockReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;
    U8 tempBuffer[(MAX_SIM_SETTING_PASSWD_LEN + 1)];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] RstVerifyPhoneLockReq()\n");

    /* Validate phonelock password send message to L4  MSG_ID_MMI_VERIFY_PIN_REQ */
    if (mmi_ucs2strlen((S8*) gPhonePassword) < MIN_PASSWORD_LENGTH)
    {
        /* if the password is invalid display error popup */
        DisplayPopup(
            (U8*) GetString(STR_INVALID_PINPUKPLOCK_LENGTH),
            IMG_GLOBAL_WARNING,
            0,
            ST_NOTIFYDURATION,
            (U8) ERROR_TONE);
        if (GetHistoryScrID(SCR_RESTORE, &History) == ST_SUCCESS)
        {
            if (History->inputBuffer != NULL)
            {
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            }
            if (History->guiBuffer != NULL)
            {
                memset(History->guiBuffer, 0, 2);
            }
        }
        memset(gPhonePassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
        DeleteUptoScrID(SCR_RESTORE);
    }
    else
    {
        memset(tempBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));

        SECSETVerifyPINReq(MMI_SETTING_TYPE_PHONELOCK, gPhonePassword, tempBuffer, EntryRstConfirm);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  RstSendRestoreMsgToWap
 * DESCRIPTION
 *  This function is to send  MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RstSendRestoreMsgToWap(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ;

    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryRstConfirm
 * DESCRIPTION
 *  This function is left softkey handler for Yes to reboot
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRstConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MTK_TARGET__)
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) GetString(EM_NOTICE_SUCCESS_REBOOT_TEXT),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
#else /* !defined(__MTK_TARGET__) */ 
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) GetString(STR_SETTING_RESTORE_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
#endif /* !defined(__MTK_TARGET__) */ 

    /* Register function with left/right softkey */
#ifdef __HALF_SECURE_RESTORE__
    if (GetPhoneLock() == MMI_FALSE)
    {
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        SetRightSoftkeyFunction(GoBack2TheHistory, KEY_EVENT_UP);
    }
#else /* __HALF_SECURE_RESTORE__ */ 
    SetRightSoftkeyFunction(GoBack2TheHistory, KEY_EVENT_UP);
#endif /* __HALF_SECURE_RESTORE__ */ 

    SetLeftSoftkeyFunction(RstStartRestore, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryRstRestoreProcessing
 * DESCRIPTION
 *  This function is Entry function to display restore processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRstRestoreProcessing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] EntryRstRestoreProcessing()\n");

    ChangeLeftSoftkey(0, 0);
    ChangeRightSoftkey(0, 0);

    /* Call Exit Handler */
    EntryNewScreen(SCR_RESTORE_PROCESSING, NULL, EntryRstRestoreProcessing, NULL);

    ShowCategory66Screen(
        STR_MENU_RESTORE,
        0,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_SETTING_RESTORE_PROCESSING),
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* clear all key handlers so as to restrict duplicate reqs */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
}


/*****************************************************************************
 * FUNCTION
 *  RstSyncHandler
 * DESCRIPTION
 *  This function is to handle MSG_ID_MMI_EQ_NVRAM_RESET_RSP
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RstSyncHandler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(gAlmQueue, 0xff, sizeof(gAlmQueue));

    g_alm_frm_cntx.EnabledAlarms = 0;

#ifdef __MMI_EBOOK_READER__
    ebr_frm_restore_default_book_shelf_settings();
#endif /* __MMI_EBOOK_READER__ */ 

#if !defined(MMI_ON_WIN32) && defined(__J2ME__)
	javaFileGenerator(GAMETYPE_JAVA_GAME, KAL_TRUE);
#ifdef __SUPPORT_INFUSIO__
	javaFileGenerator(GAMETYPE_INFUSIO_EUREKA, KAL_TRUE);
#endif /* __SUPPORT_INFUSIO__ */
#ifdef SUPPORT_SURFKITCHEN
	javaFileGenerator(GAMETYPE_SURFKITCHEN, KAL_TRUE);
#endif /* SUPPORT_SURFKITCHEN */
#ifdef SUPPORT_MUSICWAV
	javaFileGenerator(GAMETYPE_MUSICWAV, KAL_TRUE);
#endif /* SUPPORT_MUSICWAV */
#endif

#ifdef WAP_SUPPORT
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] RstSyncHandler: Reset WAP\n");
    SetProtocolEventHandler(RstWapRspHdlr, MSG_ID_WAP_RESTORE_FACTORY_SETTING_CNF);
    RstSendRestoreMsgToWap();
#else /* WAP_SUPPORT */ 
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] RstSyncHandler: Reboot\n");
    AlmATPowerReset(MMI_FALSE, 10); /* shutdown system and reboot in 3 seconds. */
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  RstDetachHandler
 * DESCRIPTION
 *  This function is to handle MSG_ID_MMI_NW_PWROFF_DETACH_RSP
 * PARAMETERS
 *  msg     [IN]        MSG_ID_MMI_NW_PWROFF_DETACH_RSP
 * RETURNS
 *  void
 *****************************************************************************/
void RstDetachHandler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMIEQNVRAMRESETREQ *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_EQ_NVRAM_RESET_REQ;
    local_data = (MMIEQNVRAMRESETREQ*) OslConstructDataPtr(sizeof(MMIEQNVRAMRESETREQ));

    local_data->lid = 0;

    local_data->reset_category = NVRAM_RESET_FACTORY;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(RstSyncHandler, MSG_ID_MMI_EQ_NVRAM_RESET_RSP);
    OslMsgSendExtQueue(&Message);

}


#ifdef __MMI_DUAL_SIM_MASTER__
void MTPNP_AD_FactoryRestore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE	Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //EntryRstRestoreProcessing();

    /* Lock Nvram Cache Access and never release */
    SetFlashAllNVRAMCatchData(MMI_TRUE);
#ifdef __MMI_USB_SUPPORT__
   	ClearProtocolEventHandler(PRT_EQ_USB_DETECT_IND);
#endif
    SetProtocolEventHandler(RstDetachHandler,MSG_ID_MMI_NW_PWROFF_DETACH_RSP);

    /* Deattach network */
    Message.oslSrcId=MOD_MMI;
    Message.oslDestId=MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_NW_PWROFF_DETACH_REQ;

    Message.oslDataPtr = (oslParaType *)NULL;
    Message.oslPeerBuffPtr= NULL;
    OslMsgSendExtQueue(&Message);

    bStatus = MMI_TRUE;

    return;
}

/*****************************************************************************
 * FUNCTION
 *  RstSIM2DetachHandler
 * DESCRIPTION
 *  This function is to handle MSG_ID_MMI_NW_PWROFF_DETACH_RSP
 * PARAMETERS
 *  msg     [IN]        MSG_ID_MMI_NW_PWROFF_DETACH_RSP
 * RETURNS
 *  void
 *****************************************************************************/
void RstSIM2DetachHandler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = MSG_ID_MMI_NW_PWROFF_DETACH_REQ;

    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetSlaveProtocolEventHandler(RstDetachHandler, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
    OslMsgSendExtQueue(&Message);

}
#endif  /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  RstStartRestore
 * DESCRIPTION
 *  This function is start to restore settings to factore default
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RstStartRestore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryRstRestoreProcessing();
    
    /* add alarm deinit function for shutdown crash */
    AlmDeInit();

//#ifndef __MMI_DUAL_SIM_MASTER__
    /* Lock Nvram Cache Access and never relase */
    SetFlashAllNVRAMCatchData(MMI_TRUE);
#ifdef __MMI_USB_SUPPORT__
    ClearProtocolEventHandler(PRT_EQ_USB_DETECT_IND);
#endif 

#ifdef __MMI_DUAL_SIM_MASTER__
    SetProtocolEventHandler(RstSIM2DetachHandler, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
#else /* __MMI_DUAL_SIM_MASTER__ */
    SetProtocolEventHandler(RstDetachHandler, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /* Deattach network */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_NW_PWROFF_DETACH_REQ;

    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    bStatus = MMI_TRUE;

    return;
//#else	/* __MMI_DUAL_SIM_MASTER__ */
//	//MTPNP_AD_Factory_Restart();
//    MTPNP_AD_FactoryRestore();
//#endif	/* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  RstWapRspHdlr
 * DESCRIPTION
 *  This function is to handle MSG_ID_WAP_RESTORE_FACTORY_SETTING_CNF
 * PARAMETERS
 *  msg     [IN]        MSG_ID_WAP_RESTORE_FACTORY_SETTING_CNF
 * RETURNS
 *  void
 *****************************************************************************/
void RstWapRspHdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] RstWapRspHdlr(): Reboot\n");

    AlmATPowerReset(MMI_FALSE, 10); /* shutdown system and reboot in 3 seconds. */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RstRestoreDisplayPopup
 * DESCRIPTION
 *  This function is to display success/fail popup for restore default
 * PARAMETERS
 *  status      [IN]        Success/fail
 * RETURNS
 *  void
 *****************************************************************************/
void RstRestoreDisplayPopup(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the status is success or not */
    if (status)
    {
        /* if the restore default values is success */
        SpofRestore();

        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestoreDisplayPopup(): Restore Successful. ===\n");
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE /* STR_RESTORE_SUCCESS */ ),
            IMG_GLOBAL_ACTIVATED,
            1,
            ST_NOTIFYDURATION,
            SUCCESS_TONE);
    }
    else
    {
        /* if the restore default values is failure */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestoreDisplayPopup(): Restore Fail. ===\n");
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    }

    /* delete screens for maitaining the history */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestoreDisplayPopup(): Delete Screen. ===\n");
    DeleteScreenIfPresent(SCR_RESTORE);
    DeleteScreenIfPresent(SCR_SETTING_RESTORE_CONFIRM);
    DeleteScreenIfPresent(SCR_RESTORE_PROCESSING);

}


/*****************************************************************************
 * FUNCTION
 *  RstrSettingPasswdScrSoftKeyFunc
 * DESCRIPTION
 *  This function is to change softkey function in screen according to params
 * PARAMETERS
 *  text        [IN]        
 *  cursor      [IN]        
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RstrSettingPasswdScrSoftKeyFunc(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the validity of the input password */
    if ((length) < MIN_PASSWORD_LENGTH)
    {
        /* if length is short then disable lsk */
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
    else
    {
        /* if its valid length then enable lsk */
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(gSecuritySetupContext.PasswdLenCheckCallBack, KEY_POUND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  RstGetNITZStatusDefault
 * DESCRIPTION
 *  This function is to get NITZ status default
 * PARAMETERS
 *  void
 * RETURNS
 *  On/Off
 *****************************************************************************/
U8 RstGetNITZStatusDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gAutoUpdateTime = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive default value for auto update date time status from nvram */
    ReadValue(RESTORE_DEFAULT_AUTOUPDATE_TIME, &gAutoUpdateTime, DS_BYTE, &error);

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] RstGetNITZStatusDefault(): gAutoUpdateTime = %d\n",
                         gAutoUpdateTime);

    /* return default value for auto update date time status */
    return gAutoUpdateTime;
}


/*****************************************************************************
 * FUNCTION
 *  RstGetScrSaverStatusDefault
 * DESCRIPTION
 *  This function is to get screen saver status default value
 * PARAMETERS
 *  void
 * RETURNS
 *  On/Off
 *****************************************************************************/
U8 RstGetScrSaverStatusDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ScrSvrStatus = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive default value for screen saver status  from nvram */
#if defined(__MMI_LCD_PARTIAL_ON__) && defined(__MMI_LCD_PARTIAL_ON_ENABLED__)
    ScrSvrStatus = (U8) SET_SS_STATUS_POWERSAVING;
#else 
    ReadValue(RESTORE_DEFAULT_SCREENSAVER_STATUS, &ScrSvrStatus, DS_BYTE, &error);
#endif 

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] RstGetScrSaverStatusDefault(): ScrSvrStatus = %d\n",
                         ScrSvrStatus);

    /* return default value for screen saver status */
    return ScrSvrStatus;
}


/*****************************************************************************
 * FUNCTION
 *  RstGetScrSaverWaitingDefault
 * DESCRIPTION
 *  This function is to get screen saver waiting time default value
 * PARAMETERS
 *  void
 * RETURNS
 *  Waiting time in seconds
 *****************************************************************************/
U8 RstGetScrSaverWaitingDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gRestorScrWaitingVal = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive default value for screen saver waiting value from nvram */
    ReadValue(RESTORE_DEFAULT_SCREENSAVER_WAITING, &gRestorScrWaitingVal, DS_BYTE, &error);
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] RstGetScrSaverWaitingDefault(): gRestorScrWaitingVal =%d\n",
                         gRestorScrWaitingVal);

    /* return default value for screen saver waiting value */
    return gRestorScrWaitingVal;
}


/*****************************************************************************
 * FUNCTION
 *  RstGetScrSaverImgIdDefault
 * DESCRIPTION
 *  This function is to get screen saver image id default value
 * PARAMETERS
 *  void
 * RETURNS
 *  Image ID
 *****************************************************************************/
U16 RstGetScrSaverImgIdDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 gScreenSaverId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive default value for screen saver id from nvram */
    mmi_dispchar_get_img_id(RESTORE_DEFAULT_CURRENT_SCREENSVER_ID, &gScreenSaverId);
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] RstGetScrSaverImgIdDefault(): gScreenSaverId = %d\n",
                         gScreenSaverId);

    /* return default value for screen saver id */
    return gScreenSaverId;
}


/*****************************************************************************
 * FUNCTION
 *  RstGetWallpaperImgIdDefault
 * DESCRIPTION
 *  This function is to get wallpaper image id default value
 * PARAMETERS
 *  void
 * RETURNS
 *  Image ID
 *****************************************************************************/
U16 RstGetWallpaperImgIdDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 gWallPaperId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive value for wall paper id from nvram */
    mmi_dispchar_get_img_id(RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER, &(gWallPaperId));
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] RstGetScrSaverImgIdDefault(): gWallPaperId = %d\n",
                         gWallPaperId);

    /* return default value for wall paper id */
    return gWallPaperId;
}

#ifdef __MMI_SUB_WALLPAPER__


/*****************************************************************************
 * FUNCTION
 *  RstGetWallpaperSubImgIdDefault
 * DESCRIPTION
 *  This function is to get sub wallpaper image id default value
 * PARAMETERS
 *  void
 * RETURNS
 *  Image ID
 *****************************************************************************/
U16 RstGetWallpaperSubImgIdDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 gSubWallPaperId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive value for wall paper id from nvram */
    mmi_dispchar_get_img_id(RESTORE_DEFAULT_SETWALLPAPER_SUB, &gSubWallPaperId);
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[RST Factory] RstGetWallpaperSubImgIdDefault(): gSubWallPaperId = %d\n",
                         gSubWallPaperId);

    /* return default value for wall paper id */
    return gSubWallPaperId;
}
#endif /* __MMI_SUB_WALLPAPER__ */ 

#if __MMI_PHNSET_COMMENT__


/*****************************************************************************
 * FUNCTION
 *  RstRestorePhoneSetup
 * DESCRIPTION
 *  This function is to restore phone setup default values
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL RstRestorePhoneSetup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

#ifdef __MMI_PREFER_INPUT_METHOD__
    U16 data16 = 0;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PREFER_INPUT_METHOD__
    /* Restore Prefer input method */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestorePhoneSetup(): Start restore InputMethod. ===\n");
    data16 = RstGetPreferedInputMethodDefault();
    WriteValue(NVRAM_SETTING_PREFER_INPUT_METHOD, &data16, DS_SHORT, &error);
    SetInputMethodType(data16);
#endif /* __MMI_PREFER_INPUT_METHOD__ */ 

    /* Restore speed dial status */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestorePhoneSetup(): Start restore Speed dial status. ===\n");
    data = RstGetSpeedDialStatusDefault();
    WriteValue(NVRAM_SETTING_SPEED_DIAL, &data, DS_BYTE, &error);

    /* Restore contrast level for main lcd */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestorePhoneSetup(): Start restore Contrast Level. ===\n");
    data = RstGetContrastLevelMainDefault();
    PhnsetChangeMainLCDContrastValue(data);
    PhnsetMainLCDContrast(data);
    WriteValue(NVRAM_SETTING_CONTRAST_LEVEL, &data, DS_BYTE, &error);

#ifdef __MMI_SUBLCD__
    /* Restore contrast lever for sub lcd */
    data = RstGetContrastLevelSubDefault();
    PhnsetChangeSubLCDContrastValue(data);
    PhnsetSubLCDContrast(data);
    WriteValue(NVRAM_SETTING_CONTRAST_SUBLCD_LEVEL, &data, DS_BYTE, &error);
#endif /* __MMI_SUBLCD__ */ 

    /* Restore greeting text status */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestorePhoneSetup(): Start restore greeting text. ===\n");
    data = RstGetGreetingTextStatusDefault();
    WriteValue(NVRAM_SETTING_WELCOME_TEXT, &data, DS_BYTE, &error);
    memset(WelcomeText, 0, MAX_SETTING_WELCOME_TEXT * ENCODING_LENGTH);
    mmi_asc_to_ucs2((S8*) WelcomeText, (S8*) "Welcome"); /* MTK add, Robin 1110 */
    WriteRecord(
        NVRAM_EF_SETTING_LID,
        1,
        (void*)WelcomeText,
        (U16) (MAX_SETTING_WELCOME_TEXT * ENCODING_LENGTH),
        &error);

#if defined(__MMI_APHORISM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_APHORISM__) */ 

    /* Restore show own number status */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestorePhoneSetup(): Start restore OwnerNumber. ===\n");
    data = RstGetOwnerNumStatusDefault();
    WriteValue(NVRAM_SETTING_OWNER_NO, &data, DS_BYTE, &error);
    /* CurrentDtType = 1;//default on */
    PhnsetSetShowDTStatus(1);

    /* Restore show date/time status */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestorePhoneSetup(): Start restore DateTime Status. ===\n");
    data = RstGetShowDTStatusDefault();
    WriteValue(NVRAM_SETTING_STATUS_DT_TIME, &data, DS_BYTE, &error);

    /* Restore auto update date/time status */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestorePhoneSetup(): Start restore NITZ. ===\n");
    data = RstGetNITZStatusDefault();
    WriteValue(NVRAM_SETTING_AUTOUPDATE_DT_TIME, &data, DS_BYTE, &error);

    /* Restore speed dial */
    /*
     * data = PhbRestoreSpeedDial();    
     * if(error == NVRAM_WRITE_SUCCESS)
     * return TRUE;
     * else
     * return FALSE;
     */

    /* Restore speed dial */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestorePhoneSetup(): Start restore Speed dial. ===\n");
    if (PhbRestoreSpeedDial() == MMI_FALSE)
    {
        return FALSE;
    }

    /* Restore date format  */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestorePhoneSetup(): Start restore Date Format. ===\n");
    data = RstGetDateFormatDefault();
    if (PhnsetSetDateFormat(data) != NVRAM_WRITE_SUCCESS)   /* dd-mmm-yyyy */
    {
        return FALSE;
    }

    /* Restore time format */
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstRestorePhoneSetup(): Start restore Time Format. ===\n");
    data = RstGetTimeFormatDefault();
    if (PhnsetSetTimeFormat(data) != NVRAM_WRITE_SUCCESS)   /* 12hr format as per the error */
    {
        return FALSE;
    }

    return TRUE;

}

#ifdef __MMI_PREFER_INPUT_METHOD__


/*****************************************************************************
 * FUNCTION
 *  RstGetPreferedInputMethodDefault
 * DESCRIPTION
 *  This function is to get prefered Input Method restore default value
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U16 RstGetPreferedInputMethodDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 data16 = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive preferred input method by reading default value from nvram */
    ReadValue(RESTORE_PREFER_INPUT_METHOD, &data16, DS_SHORT, &error);
    /* return the preferred input method */
    return data16;
}
#endif /* __MMI_PREFER_INPUT_METHOD__ */ 


/*****************************************************************************
 * FUNCTION
 *  RstGetSpeedDialStatusDefault
 * DESCRIPTION
 *  This function is to get speed dial status restore default value
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 RstGetSpeedDialStatusDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gSpeedDialStatus = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstGetSpeedDialStatusDefault() ===\n");

    /* retrive default speed dial status from nvram */
    ReadValue(RESTORE_DEFAULT_SPEED_DIAL, &gSpeedDialStatus, DS_BYTE, &error);
    /* return the default speed dial status */
    return gSpeedDialStatus;
}


/*****************************************************************************
 * FUNCTION
 *  RstGetDateFormatDefault
 * DESCRIPTION
 *  This function is to get date format restore default
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 RstGetDateFormatDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gDateFormat = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstGetDateFormatDefault() ===\n");

    /* retrive default date format from nvram */
    ReadValue(RESTORE_DEFAULT_DATE_FORMAT, &gDateFormat, DS_BYTE, &error);
    /* return the default date format */
    return gDateFormat;
}


/*****************************************************************************
 * FUNCTION
 *  RstGetTimeFormatDefault
 * DESCRIPTION
 *  This function is to get time format restore default
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 RstGetTimeFormatDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gTimeFormat = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstGetTimeFormatDefault() ===\n");

    /* retrive default time format from nvram */
    ReadValue(RESTORE_DEFAULT_TIME_FORMAT, &gTimeFormat, DS_BYTE, &error);
    /* return the default time format */
    return gTimeFormat;
}


/*****************************************************************************
 * FUNCTION
 *  RstGetContrastLevelSubDefault
 * DESCRIPTION
 *  This function is to get sub lcd constract level restore default value
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 RstGetContrastLevelSubDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gContrastSubLcd = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstGetContrastLevelSubDefault() ===\n");

    /* retrive the default contrast level for sub lcd from nvram */
    ReadValue(RESTORE_DEFAULT_CONTRAST_SUBLCD_LEVEL, &gContrastSubLcd, DS_BYTE, &error);
    /* return the default contrast level for sub lcd */
    return gContrastSubLcd;
}


/*****************************************************************************
 * FUNCTION
 *  RstGetContrastLevelMainDefault
 * DESCRIPTION
 *  This function is to get main lcd constract level restore default value
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 RstGetContrastLevelMainDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gContrastLcd = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstGetContrastLevelMainDefault() ===\n");

    /* retrive the default contrast level for main lcd from nvram */
    ReadValue(RESTORE_DEFAULT_CONTRAST_LEVEL, &gContrastLcd, DS_BYTE, &error);
    /* return the default contrast level for main lcd */
    return gContrastLcd;
}


/*****************************************************************************
 * FUNCTION
 *  RstGetGreetingTextStatusDefault
 * DESCRIPTION
 *  This function is to get greeting text on/off status default value
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 RstGetGreetingTextStatusDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gWelcomeText = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstGetGreetingTextStatusDefault() ===\n");

    /* retrive the default greeting text status from nvram */
    ReadValue(RESTORE_DEFAULT_WELCOME_TEXT, &gWelcomeText, DS_BYTE, &error);
    /* return the default greeting text status */
    return gWelcomeText;
}


/*****************************************************************************
 * FUNCTION
 *  RetGetAphorismTextStatusDefault
 * DESCRIPTION
 *  This function is to get Aphorism on/off status default value
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_APHORISM__)
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
#endif /* defined(__MMI_APHORISM__) */ 


/*****************************************************************************
 * FUNCTION
 *  RstGetOwnerNumStatusDefault
 * DESCRIPTION
 *  This function is to
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 RstGetOwnerNumStatusDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gOwnerNo = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstGetOwnerNumStatusDefault() ===\n");

    /* retrive the default value for owner number status from nvram */
    ReadValue(RESTORE_DEFAULT_OWNER_NO, &gOwnerNo, DS_BYTE, &error);
    /* return the default owner numbers status */
    return gOwnerNo;
}


/*****************************************************************************
 * FUNCTION
 *  RstGetShowDTStatusDefault
 * DESCRIPTION
 *  This function is to get show date and time status default value
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U8 RstGetShowDTStatusDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gStatusShowDtTime = 0;
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== RstGetShowDTStatusDefault() ===\n");

    /* retrive default value for display date time status from nvram */
    ReadValue(RESTORE_DEFAULT_STATUS_SHOW_DT_TIME, &gStatusShowDtTime, DS_BYTE, &error);
    /* return default value for display date time status */
    return gStatusShowDtTime;
}
#endif /* __MMI_PHNSET_COMMENT__ */ 

