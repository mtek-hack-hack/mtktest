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
 * ScheduledPowerOnOff.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is intends for scheduled power on / off application
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
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2004
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * SchedulePowerOnOff.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements schedule power on of applications.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
/***************** Settings Application implementation *********************/

/**************************************************************

   FILENAME : ScheduledPowerOnoff.c

   PURPOSE     : Scheduled power on of fhandling

   REMARKS     : nil

   AUTHOR      : Gautam Saluja

   DATE     : 

**************************************************************/
#include "MMI_include.h"
#ifndef _MMI_SCHEDULEPOWERONOFF_C
#define _MMI_SCHEDULEPOWERONOFF_C

/*  Include: MMI header file */


#include "AlarmFrameworkProt.h"
#include "AlarmGprot.h"
#include "AlarmDef.h"
#include "DateTimeGprot.h"
#include "AlarmResDef.h"
#include "ToDoListResDef.h"

#include "ScheduledPowerOnOff.h"
#include "SettingDefs.h"
#include "CommonScreens.h"
#include "WrapperGprot.h"
#include "SimDetectionGexdcl.h"
#include "gpioInc.h"    /* TurnOnBacklight */

#include "JavaAgencyDef.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif /*__USB_IN_NORMAL_MODE__*/
/* ... Add More MMI header */

/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Define
 */

/* 
 * Typedef 
 */

/* 
 * Local Variable
 */

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
spof_context_struct g_spof_cntx;
extern wgui_inline_item wgui_inline_items[];
extern void playRequestedTone(ALL_TONE_ENUM playtone);

/* 
 * Global Function
 */
extern void ShutdownSystemOperation(void);
#ifdef __J2ME__
extern void jvm_pause_dummy_screen(void);
extern void jvm_resume_dummy_screen(void);
#endif /* __J2ME__ */ 


/*****************************************************************************
 * FUNCTION
 *  SPOFInit
 * DESCRIPTION
 *  Initialize SPOF application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SPOFInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  SPOFInitNvRam
 * DESCRIPTION
 *  Read nvram data of SPOF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SPOFInitNvRam(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_buf[NVRAM_ALM_SPOF_DATA_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_ALM_SPOF_DATA_LID, 1, &nvram_buf, NVRAM_ALM_SPOF_DATA_SIZE, &error);
    memcpy(g_spof_cntx.SPOFList, nvram_buf, sizeof(g_spof_cntx.SPOFList));

    /* zero initialized */
    if (g_spof_cntx.SPOFList[0].Hour > NUM_HRS_DAY)
    {
        memset(&g_spof_cntx.SPOFList, 0, sizeof(g_spof_cntx.SPOFList));
    }

    /* no require to set any alarm */
}


/*****************************************************************************
 * FUNCTION
 *  SPOFExpiryTimeCBH
 * DESCRIPTION
 *  Callback handler to get information of SPOF/SPON expiry setting.
 * PARAMETERS
 *  index           [IN]            
 *  alarmTime       [?]             
 *  Freq            [?]             
 *  WeekDays        [?]             
 *  MYTIME(?)       [IN/OUT]        Expiry time set by user
 *  U8(?)           [IN/OUT]        Expiry days of week
 * RETURNS
 *  void
 *****************************************************************************/
void SPOFExpiryTimeCBH(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME* preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alarmTime->nHour = g_spof_cntx.SPOFList[index].Hour;
    alarmTime->nMin = g_spof_cntx.SPOFList[index].Min;
    *Freq = ALM_FREQ_EVERYDAY;
    *WeekDays = ALM_ALL_DAYS;
}


/*****************************************************************************
 * FUNCTION
 *  SPOFReInitQueueCBH
 * DESCRIPTION
 *  Reinit SPOF to alarm queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SPOFReInitQueueCBH(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUM_OF_SPOF; i++)
    {
        if (g_spof_cntx.SPOFList[i].Status == 1)
        {
            if (g_spof_cntx.SPOFList[i].Type == SPOF_POWERON)
            {
                AlmInsertIntoQueue((U8) (i + ALM_SPON_START), FALSE);
            }
            else
            {
                AlmInsertIntoQueue((U8) (i + ALM_SPOF_START), FALSE);
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  SponExpiryHandler
 * DESCRIPTION
 *  CallBack handler to execute SPON expiry.
 * PARAMETERS
 *  sponIndex       [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 *  BOOL(?)         [IN]        Power status
 *  U8(?)           [IN]        Index of alarm item
 * RETURNS
 *  void
 *****************************************************************************/
U8 SponExpiryHandler(U8 sponIndex, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
#ifdef __J2ME__
    U8 IsJavaPlaying = FALSE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *period = 0;
    if (power_on)
    {
        /* Balance previous SPOF if exists, if first alarm in queue is pending SPOF, cancel it. */
        U8 index = mmi_alm_get_index_from_queue(0);

        if (AlmGetType(index) == ALM_TYPE_SPOF)
        {
        #ifdef __J2ME__
            if (GetActiveScreenId() == SCR_JAVA_APP)
            {
                IsJavaPlaying = TRUE;
                jvm_pause_dummy_screen();
            }
        #endif /* __J2ME__ */ 
            AlmInsertIntoQueue(index, TRUE);
        #ifdef __J2ME__
            if (IsJavaPlaying == TRUE)
            {
                jvm_resume_dummy_screen();
            }
        #endif /* __J2ME__ */ 
        }
    }
    else
    {
        AlmSendPowerOn();
    }
    return ALM_HAS_NO_IND;
}


/*****************************************************************************
 * FUNCTION
 *  SpofExpiryHandler
 * DESCRIPTION
 *  CallBack handler to execute SPOF expiry.
 * PARAMETERS
 *  index           [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 *  BOOL(?)         [IN]        Power status
 *  U8(?)           [IN]        Index of alarm item
 * RETURNS
 *  void
 *****************************************************************************/
U8 SpofExpiryHandler(U8 index, U16 *period, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (power_on)
    {
        *period = ALM_DEFAULT_EXPIRY_PERIOD;
        EntryPowerOffConfirmation();
        DeleteScreenIfPresent(SCR_ID_SPOF_CONFIRM);

        return ALM_HAS_IND;
    }
    else
    {
        if (g_alm_frm_cntx.EnabledAlarms > 0)
        {
            g_alm_frm_cntx.IsWaitForPwroff = TRUE;
        }
        else
        {
            AlmSendPowerOff();
        }
        *period = ALM_WITHOUD_EXPIRY_PERIOD;
        return ALM_HAS_NO_IND;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SPOFFCBInit
 * DESCRIPTION
 *  Set callback function needed by alarm framework
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SPOFFCBInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alm_set_start_index(ALM_TYPE_SPON, ALM_SPON_START);
    AlmSetExpiryTimeCB(ALM_TYPE_SPON, SPOFExpiryTimeCBH);
    AlmSetExpiryHandlerCB(ALM_TYPE_SPON, SponExpiryHandler);
    AlmSetInitHandlerCB(ALM_TYPE_SPON, SPOFInitNvRam, SPOFReInitQueueCBH);

    mmi_alm_set_start_index(ALM_TYPE_SPOF, ALM_SPOF_START);
    AlmSetExpiryTimeCB(ALM_TYPE_SPOF, SPOFExpiryTimeCBH);
    AlmSetExpiryHandlerCB(ALM_TYPE_SPOF, SpofExpiryHandler);
    AlmSetStopAlarmCB(ALM_TYPE_SPOF, SpofStopPowerOffConfirmation);

}


/*****************************************************************************
 * FUNCTION
 *  SPOFDeInit
 * DESCRIPTION
 *  Deinitialize SPOF application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SPOFDeInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  EntrySpofApp
 * DESCRIPTION
 *  Entry function of schedule power on off application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySpofApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i;
    S32 num_of_items = NUM_OF_SPOF;
    MYTIME tmpTime;
    U16 spof_states_icon[NUM_OF_SPOF];
    U16 spof_type_icon[NUM_OF_SPOF];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TWO_SPOF__
    num_of_items = 2;
#endif 

    EntryNewScreen(SCR_ID_SPOF_APP, NULL, EntrySpofApp, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SPOF_APP);
    if (guiBuffer == NULL)
    {
        g_spof_cntx.CurrItem = 0;
    }

    /* initialize list to display */
    for (i = 0; i < NUM_OF_SPOF; i++)
    {
        /* get the value of spof_list */
        memset(&tmpTime, 0, sizeof(MYTIME));

        tmpTime.nHour = g_spof_cntx.SPOFList[i].Hour;
        tmpTime.nMin = g_spof_cntx.SPOFList[i].Min;

        time_string(&tmpTime, (UI_string_type) subMenuDataPtrs[i], DT_IDLE_SCREEN);

        /* get the value of spof_vicons */
        if (g_spof_cntx.SPOFList[i].Status == SPOF_DISABLE)
        {
            spof_states_icon[i] = CHECKBOX_OFF_IMAGE_ID;
        }
        else
        {
            spof_states_icon[i] = CHECKBOX_ON_IMAGE_ID;
        }

        /* get the value of spof_type poweon off */
        if (g_spof_cntx.SPOFList[i].Type == SPOF_POWERON)
        {
            spof_type_icon[i] = SPOF_TYPEPOWERON_IMAGEID;
        }
        else
        {
            spof_type_icon[i] = SPOF_TYPEPOWEROFF_IMAGEID;
        }

    }

    ShowCategory73Screen(
        SPOF_MAIN_TITLE_STRINGID,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_EDIT,
        SPOF_EDIT_BUTTON_IMAGEID,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        subMenuDataPtrs,
        spof_states_icon,
        spof_type_icon,
        0,
        guiBuffer,
        1);

    RegisterHighlightHandler(HighlightSpofList);

    SetLeftSoftkeyFunction(EntrySpofEdit, KEY_EVENT_UP);
    SetKeyHandler(EntrySpofEdit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightSpofList
 * DESCRIPTION
 *  Highlight handler of SPOF list
 * PARAMETERS
 *  nIndex      [IN]        Index item
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSpofList(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_spof_cntx.CurrItem = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightSPOFInlineItem
 * DESCRIPTION
 *  Highlight handler of inline editor screen
 * PARAMETERS
 *  nIndex      [IN]        Index of inline item
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSPOFInlineItem(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(SpofSaveData);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySpofEdit
 * DESCRIPTION
 *  Entry function of inline editor screen of schedule power on off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySpofEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 spof_icon_list[] = {SPOF_SETTING_STATUS_IMAGEID, 0, SPOF_TYPEPOWERON_IMAGEID, IMG_TIME};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SPOF_EDITOR, ExitSpofEdit, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SPOF_EDITOR);
    InitializeCategory57Screen();
    SpofFillInlineEditStruct();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_SPOF_EDITOR, &inputBufferSize);    /* added for inline edit history */
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, NUM_ITEM_EDIT_SCREEN, inputBuffer);
    }

    RegisterHighlightHandler(HighlightSPOFInlineItem);
    ShowCategory57Screen(
        SPOF_EDIT_TITLE_STRINGID,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NUM_ITEM_EDIT_SCREEN,
        spof_icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(SpofSaveData, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSpofEdit
 * DESCRIPTION
 *  Exit Handler For SPOF Edit Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSpofEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    U16 inputBufferSize;    /* added for inline edit history */

    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_SPOF_EDITOR;
    CloseCategory57Screen();
    Scr.entryFuncPtr = EntrySpofEdit;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(Scr, inputBufferSize);                  /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  SpofFillInlineEditStruct
 * DESCRIPTION
 *  Initialize inline editor structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpofFillInlineEditStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 dummyString[12];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize string resource for inline selection */
    g_spof_cntx.ActStateList[0] = GetString(SPOF_DISABLE_STRINGID);
    g_spof_cntx.ActStateList[1] = GetString(SPOF_ENABLE_STRINGID);
    g_spof_cntx.OnOffStateList[0] = GetString(STR_GLOBAL_ON);
    g_spof_cntx.OnOffStateList[1] = GetString(STR_GLOBAL_OFF);

    g_spof_cntx.CurrHiliteOnOff = g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Type;
    g_spof_cntx.CurrHiliteActivation = g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Status;

    /* hour buffer */
    sprintf(dummyString, "%02d", g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Hour);
    mmi_asc_to_ucs2(g_spof_cntx.HourBuf, dummyString);

    /* minute buffer */
    sprintf(dummyString, "%02d", g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Min);
    mmi_asc_to_ucs2(g_spof_cntx.MinBuf, dummyString);

    /* caption */
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) GetString(SPOF_STATUS_STRINGID));

    /* activate/inactivate */
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[1],
        SPOF_NUM_STATES_ACTINACT,
        (U8 **) g_spof_cntx.ActStateList,
        &g_spof_cntx.CurrHiliteActivation);

    /* power on/off */
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    DisableInlineItemHighlight(&wgui_inline_items[2]);
    SetInlineItemSelect(
        &wgui_inline_items[2],
        SPOF_NUM_STATES_ONOFF,
        (U8 **) g_spof_cntx.OnOffStateList,
        &g_spof_cntx.CurrHiliteOnOff);

    /* time */
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTime(
        &wgui_inline_items[3],
        (U8*) g_spof_cntx.HourBuf,
        (U8*) g_spof_cntx.MinBuf,
        NULL,
        AlmTimeEditorCallBack /* SOPFTimeEditorCallBack */ );
    DisableInlineItemHighlight(&wgui_inline_items[3]);
}


/*****************************************************************************
 * FUNCTION
 *  SpofSaveData
 * DESCRIPTION
 *  Save SPOF data to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpofSaveData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 NewHour, NewMin;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NewHour = (g_spof_cntx.HourBuf[0] - '0') * 10 + (g_spof_cntx.HourBuf[ENCODING_LENGTH] - '0');
    NewMin = (g_spof_cntx.MinBuf[0] - '0') * 10 + (g_spof_cntx.MinBuf[ENCODING_LENGTH] - '0');

    if (SpofIsTimeClash(NewHour, NewMin))
    {
        DisplayPopup(
            (PU8) GetString(SPOF_TIME_CONFLICT),
            IMG_GLOBAL_UNFINISHED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

    /* if setting changed */
    if (g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Hour != NewHour ||
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Min != NewMin ||
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Type != (U8) g_spof_cntx.CurrHiliteOnOff ||
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Status != g_spof_cntx.CurrHiliteActivation)
    {
        /* fill the SPOFList structure depending on the selected values */
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Status = (U8) g_spof_cntx.CurrHiliteActivation;
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Type = (U8) g_spof_cntx.CurrHiliteOnOff;
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Hour = NewHour;
        g_spof_cntx.SPOFList[g_spof_cntx.CurrItem].Min = NewMin;

        /* save the alarm in the nvram */
        SpofWritetoNvram();

        if (g_spof_cntx.CurrHiliteActivation == SPOF_ENABLE)
        {
            if (g_spof_cntx.CurrHiliteOnOff == SPOF_POWERON)
            {
                AlmCancelAlarm((U8) (g_spof_cntx.CurrItem + ALM_SPOF_START));
                AlmSetAlarm((U8) (g_spof_cntx.CurrItem + ALM_SPON_START));
            }
            else
            {
                AlmCancelAlarm((U8) (g_spof_cntx.CurrItem + ALM_SPON_START));
                AlmSetAlarm((U8) (g_spof_cntx.CurrItem + ALM_SPOF_START));
            }
        }
        else
        {
            AlmCancelAlarm((U8) (g_spof_cntx.CurrItem + ALM_SPON_START));
            AlmCancelAlarm((U8) (g_spof_cntx.CurrItem + ALM_SPOF_START));
        }
    }

    if (!g_spof_cntx.IsRestoreDefault)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_SPOF_APP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SpofWritetoNvram
 * DESCRIPTION
 *  Write SPOF Value to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpofWritetoNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_buf[NVRAM_ALM_SPOF_DATA_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(nvram_buf, 0, NVRAM_ALM_SPOF_DATA_SIZE);
    memcpy(nvram_buf, g_spof_cntx.SPOFList, sizeof(g_spof_cntx.SPOFList));
    WriteRecord(NVRAM_EF_ALM_SPOF_DATA_LID, 1, (void*)nvram_buf, NVRAM_ALM_SPOF_DATA_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  SpofHandler
 * DESCRIPTION
 *  Match The ALARM With SPOF Index, If Matches
 *  1. If Phone is off, switch on the phone else normally expire the alarm if POWERON Expire
 *  2. If Phone is on, switch off the phone else normally expire the alarm if PowerOff Expire
 * PARAMETERS
 *  index       [IN]        
 *  id(?)       [IN]        Index of spof alarm
 * RETURNS
 *  void
 *****************************************************************************/
void SpofHandler(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= ALM_SPOF_START)
    {
        index -= ALM_SPOF_START;
    }

    /* depending on the index check whether it was power on or off */

    if ((g_spof_cntx.SPOFList[index].Type == SPOF_POWERON) && (g_alm_frm_cntx.IsPwronAlarm == TRUE))
    {
        AlmSendPowerOn();
    }
    else if ((g_spof_cntx.SPOFList[index].Type == SPOF_POWEROFF) && (g_alm_frm_cntx.IsPwronAlarm == FALSE))
    {
        ShutdownSystemOperation();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SpofRestore
 * DESCRIPTION
 *  Restore default value of SPOF variables and save to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpofRestore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_spof_cntx.CurrHiliteActivation = SPOF_DISABLE;
    g_spof_cntx.CurrHiliteOnOff = SPOF_POWERON;

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== SpofRestore(): Cancel SPOF Aalrm. ===\n");

    for (i = 0; i < NUM_OF_SPOF; i++)
        if (g_spof_cntx.SPOFList[i].Status == SPOF_ENABLE)
        {
            AlmCancelAlarm((U8) (ALM_SPOF_START + i));
            AlmCancelAlarm((U8) (ALM_SPON_START + i));
        }

    memset(g_spof_cntx.SPOFList, 0, sizeof(g_spof_cntx.SPOFList));
    SpofWritetoNvram();
}


/*****************************************************************************
 * FUNCTION
 *  SpofIsTimeClash
 * DESCRIPTION
 *  To check if the setting time clashes with other SPOF alarm
 * PARAMETERS
 *  hour        [IN]        Hour to be compared.
 *  min         [IN]        Min to be compared.
 * RETURNS
 *  TRUE if clash, otherwise FALSE.
 *****************************************************************************/
BOOL SpofIsTimeClash(U8 hour, U8 min)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_spof_cntx.CurrHiliteActivation == SPOF_ENABLE)
    {
        for (i = 0; i < NUM_OF_SPOF; i++)
        {
            if (i != g_spof_cntx.CurrItem)
                if (g_spof_cntx.SPOFList[i].Status == SPOF_ENABLE && hour == g_spof_cntx.SPOFList[i].Hour &&
                    min == g_spof_cntx.SPOFList[i].Min)
                {
                    return TRUE;
                }
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryPowerOffConfirmation
 * DESCRIPTION
 *  Display confirmation screen to decide power off or not.
 * PARAMETERS
 *  void
 *  U8.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPowerOffConfirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SPOF_CONFIRM, ExitPowerOffConfirmation, EntryPowerOffConfirmation, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_SPOF_CONFIRM, (HistoryDelCBPtr) mmi_spof_del_scr_callback);

    TurnOnBacklight(1);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SPOF_CONFIRM);

    if (!mmi_is_redrawing_bk_screens())
    {
        StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, ALM_EXPIRE_DURATION, AlmHandleAlarmTimeout);
    }
    
    ShowCategory123Screen(
        SPOF_MAIN_TITLE_STRINGID,
        ALARMS_MAIN_TITLE_IMAGEID,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        SPOF_POWER_OFF_CONFIRM,
        IMG_GLOBAL_QUESTION,
        guiBuffer);
    playRequestedTone(WARNING_TONE);
    SetLeftSoftkeyFunction(ShutdownSystemOperation, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SpofStopPowerOffConfirmation, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(ShutdownSystemOperation, KEY_END, KEY_LONG_PRESS);

}


/*****************************************************************************
 * FUNCTION
 *  ExitPowerOffConfirmation
 * DESCRIPTION
 *  Exit function of SPOF confirm screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPowerOffConfirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_is_redrawing_bk_screens())
    {
        StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
        if (GetActiveScreenId() != SCR_ID_ALM_INDICATION && GetActiveScreenId() != SCR_TDL_REMINDER && GetActiveScreenId() != SCR_ID_SPOF_CONFIRM)
        {
            g_alm_frm_cntx.CurrAlmIndex = 0xff;
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  SpofStopPowerOffConfirmation
 * DESCRIPTION
 *  Stop power off confirm screen manually.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SpofStopPowerOffConfirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    GoBackHistory();

    if (g_alm_frm_cntx.IsExitByTimer == FALSE)
    {
        if (g_alm_frm_cntx.IsPwronAlarm)
        {
            AlmExecPwrOffAlarm();
        }
        else
        {
            AlmExecPwrOnAlarm();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spof_del_scr_callback
 * DESCRIPTION
 *  Callback handler of delete spof confirm screen from history stack.
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_spof_del_scr_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the confirm screen is in history stack, display confirm screen again */
    if (GetExitScrnID() == SCR_ID_SPOF_CONFIRM
#ifdef __USB_IN_NORMAL_MODE__        
        || mmi_usb_is_in_mass_storage_mode()
#endif        
        )
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}
#endif /* _MMI_SCHEDULEPOWERONOFF_C */ // #ifndef _MMI_SCHEDULEPOWERONOFF_C

