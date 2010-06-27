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
 * Events.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for protocol/keypad/interrupt event handler .
 *
 * Author:
 * -------
 * -------
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
 *==============================================================================
 *******************************************************************************/

#include "MMI_include.h"
#include "FrameworkGprot.h"         
#include "FrameworkProt.h"     
#include "ProtocolEvents.h"
#include "WrapperGprot.h"

#include "IdleAppProt.h"
#include "IdleAppDef.h"

#include "SATGProts.h"
#include "Wgui_categories_util.h"

#include "IdleAppDef.h"
#include "CommonScreensenum.h"

#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
#include "QuickAccessMenuItem_def.h"
#ifdef __MMI_WGUI_MINI_TAB_BAR__
#include "wgui_tab_bars.h"
#endif 
/* added by MK */
#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif // #ifdef __MMI_EMAIL__
#include "gv.h"
#include "tst_def.h"
#ifdef __LSK_KEYSEND2_IN_ONE__
#include "MTPNP_PFAL_CC.h"   
#endif/*__LSK_KEYSEND2_IN_ONE__*/

/*
 * Define
 */
/* for profiling */
#if 0
/* under construction !*/
#endif

/*
 * Data Type
 */
typedef enum
{
    MMI_FRM_REPORT_SCREEN_STATE_PASSIVE,   /* only report screen id when receiving request command */
    MMI_FRM_REPORT_SCREEN_STATE_AUTO,      /* only report popup screen id in active */
    MMI_FRM_REPORT_SCREEN_STATE_ACTIVE,    /* report all screen id in active */
    MMI_FRM_REPORT_SCREEN_STATE_MAX
}mmi_frm_report_screen_state_enum;

/* 
 *   Extern Varibales 
 */
extern U8 gIsHelpEnabled;
extern U8 gIsInSATCall;
extern MMI_BOOL  mmi_is_orderly_exit_screen; 

#ifdef __MMI_SUBLCD_MASTER_MODE__
extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];
extern FuncPtr currKeyFuncPtrs_slave[MAX_KEYS][MAX_KEY_TYPE];
extern FuncPtr currKeyFuncPtrs_master[MAX_KEYS][MAX_KEY_TYPE];
#else
extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];
#endif

hiliteInfo maxHiliteInfo[MAX_HILITE_HANDLER];       /* available hilite func ptrs  */
U8 hintData[MAX_SUB_MENUS][MAX_SUB_MENU_HINT_SIZE];
U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
PU8 subMenuDataPtrs[MAX_SUB_MENUS];
PU8 hintDataPtrs[MAX_SUB_MENUS];

/* 
 *   Local Variables 
 */

static FuncPtr curr_tab_exit_func_ptr = NULL;
static MMI_BOOL is_tab_page = MMI_TRUE;

static U16 currMaxHiliteInfo;               /* currently max hilite info */
static U16 currParentID;                    /* current parent item id */
static U16 currHiliteID;
static FuncPtr currEntryFuncPtr;
static U16 currExitScrnID, currTopScrnID;   /* curr exit func ptr with scrn id */
static FuncPtr currExitFuncPtr;
static MMI_BOOL mmu_frm_execute_scrn_exit_handler = MMI_FALSE;
static mmi_frm_report_screen_state_enum mmi_frm_report_screen_state = MMI_FRM_REPORT_SCREEN_STATE_PASSIVE;

/* 
 *   Local Functions 
 */
static void SetGenericExitHandler(U16 scrnID, FuncPtr exitFuncPtr, FuncPtr entryFuncPtr);
static void mmi_frm_dump_screen_id(void);

/* 
 *   Global Functions 
 */
extern void EmergencyCallCheck(S16 keyCode, S16 keyType);
extern U16 GetTotalCallCount(void);

#ifdef __MMI_SCREEN_SNAPSHOT__
extern void mmi_camera_scr_snapshot(void);
#endif 

/*****************************************************************************
 * FUNCTION
 *  InitEvents
 * DESCRIPTION
 *  This function is used for initialize event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitEvents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0;
    U16 keyType = 0;
    U16 count   = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_FUN_EVENT_INIT);

    for (keyCode = 0; keyCode < MAX_KEYS; keyCode++)
    {
        for (keyType = 0; keyType < MAX_KEY_TYPE; keyType++)
        {
            currKeyFuncPtrs[keyCode][keyType] = NULL;
        #ifdef __MMI_SUBLCD_MASTER_MODE__
            currKeyFuncPtrs_slave[keyCode][keyType] = NULL;
            currKeyFuncPtrs_master[keyCode][keyType] = NULL;
        #endif

        }
    }

    currEntryFuncPtr = NULL;

    currExitScrnID   = 0;
    currTopScrnID    = 0;
    currExitFuncPtr  = NULL;

    mmu_frm_execute_scrn_exit_handler = MMI_FALSE;

    /* JL remove to outside init InitHistory(); */

    currMaxHiliteInfo = 0;
    currParentID      = 0;

    maxProtocolEvent  = 0;
    usedProtocolEvent = 0;
#ifdef __MMI_DUAL_SIM__
    maxSlaveProtocolEvent = 0;
    usedSlaveProtocolEvent = 0; 
#endif /* __MMI_DUAL_SIM__ */

#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
    /* MTK added by JL for PS interrupt */
    maxInterruptEvent = 0;
#endif

    /* //////// initilaize the timer, protocol & hardware events with func ptrs /////// */
    for (count = 0; count < MAX_PROTOCOL_EVENT; count++)
    {
        protocolEventHandler[count].eventID      = 0;
        protocolEventHandler[count].entryFuncPtr = NULL;
    }

#ifdef __MMI_DUAL_SIM__
    for (count = 0; count < MAX_SLAVE_PROTOCOL_EVENT; count++)
    {
        SlaveProtocolEventHandler[count].eventID      = 0;
        SlaveProtocolEventHandler[count].entryFuncPtr = NULL;
    }
#endif /* __MMI_DUAL_SIM__ */

    for (count = 0; count < MAX_HILITE_HANDLER; count++)
    {
        maxHiliteInfo[count].entryFuncPtr = NULL;
        maxHiliteInfo[count].hintFuncPtr  = NULL;
    }
    for (count = 0; count < MAX_SUB_MENUS; count++)
    {
        subMenuDataPtrs[count] = subMenuData[count];
    }

#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
    /* MTK added by JL for PS interrupt */
    for (count = 0; count < MAX_INTERRUPT_EVENT; count++)
    {
        interruptEventHandler[count].eventID         = (U16) NULL;
        interruptEventHandler[count].entryIntFuncPtr = NULL;
        interruptEventHandler[count].postIntFuncPtr  = NULL;
    }
#endif /* MMI_FRM_BACKWARD_COMPATIBLE_EVENTS */
    /* ////////////////////////////////////////////////////////////////////////////////////// */
    SetProtocolEventHandler(mmi_proc_inject_string, MSG_ID_TST_INJECT_STRING);
}


/*****************************************************************************
 * FUNCTION
 *  DeInitFramework_KeyAndEventHandler
 * DESCRIPTION
 *  This function is used for Deinitialize key and event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitFramework_KeyAndEventHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0;
    U16 keyType = 0;
    U16 count   = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_FUN_EVENT_DEINIT_KEY_EVENT);

    for (keyCode = 0; keyCode < MAX_KEYS; keyCode++)
    {
        for (keyType = 0; keyType < MAX_KEY_TYPE; keyType++)
        {
            currKeyFuncPtrs[keyCode][keyType] = NULL;
        #ifdef __MMI_SUBLCD_MASTER_MODE__
            currKeyFuncPtrs_slave[keyCode][keyType] = NULL;
            currKeyFuncPtrs_master[keyCode][keyType] = NULL;
        #endif
        }
    }

    currEntryFuncPtr = NULL;

    currExitScrnID = 0;
    currTopScrnID = 0;
    currExitFuncPtr = NULL;

    currMaxHiliteInfo = 0;
    currParentID = 0;

    maxProtocolEvent = 0;
    usedProtocolEvent = 0;

    /* //////// initilaize the timer, protocol & hardware events with func ptrs /////// */
    for (count = 0; count < MAX_PROTOCOL_EVENT; count++)
    {
        protocolEventHandler[count].eventID = 0;
        protocolEventHandler[count].entryFuncPtr = NULL;
    }

    for (count = 0; count < MAX_HILITE_HANDLER; count++)
    {
        maxHiliteInfo[count].entryFuncPtr = NULL;
        maxHiliteInfo[count].hintFuncPtr = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  DeInitFramework_History
 * DESCRIPTION
 *  This function is used for Deinitialize History.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitFramework_History(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_FUN_EVENT_DEINIT_HISTORY);

    /* to handle key events before finish power off */
    InitKeypadBeforePWRON();

    DinitHistory();
    DinitSubLCDHistory();
}


/*****************************************************************************
 * FUNCTION
 *  DeInitFramework
 * DESCRIPTION
 *  This function is used for De-initialize history & event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitFramework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_FUN_EVENT_DEINIT);

    DeInitFramework_KeyAndEventHandler();
    DeInitFramework_History();
}


/*****************************************************************************
 * FUNCTION
 *  ExecuteCurrExitHandler
 * DESCRIPTION
 *  This function is used forc executes current exit func handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void UI_common_screen_exit(void);
extern void UI_common_screen_pre_exit(void);

void ExecuteCurrExitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK added by JL 040115 for create a new function without key clear if need. */
    ExecuteCurrExitHandler_Ext();
    /* reset all keypad tone to enabled state */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
    /* it clears all the key handlers, registered by the current screen */
    ClearInputEventHandler(MMI_DEVICE_KEY);
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    mmi_tm_reset_imageid_image_header_pool();
#ifdef __MMI_DLT_CACHE_SUPPORT__
    mmi_tm_clear_ondemand_cache();
#endif 
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    /* MTK end */

#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)
	mmi_frm_resmem_reset(MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND);
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  ReplaceNewScreenHandler
 * DESCRIPTION
 *  This function is used for sets current new screen handlers.
 * PARAMETERS
 *  scrnID              [IN]   The screen ID.     
 *  exitFuncPtr         [IN]   The exit handler.     
 *  entryFuncPtr        [IN]   The entry handler.     
 * RETURNS
 *  void
 *****************************************************************************/
void ReplaceNewScreenHandler(U16 scrnID, FuncPtr exitFuncPtr, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETEXIT_HDLR, scrnID);
    currExitScrnID = scrnID;
    currExitFuncPtr = exitFuncPtr;
    currEntryFuncPtr = entryFuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  EntryNewScreen
 * DESCRIPTION
 *  This function is used for enter the new screen. When the applications call
 *  this function, it executes the previous screen's exit handler, and adds the
 *  previous screen in the history, then clears the key handlers and entries the
 *  new screen with the parameter setting. After the applications call 
 *  EntryNewScreen(), they can draw the specified category screen.
 * PARAMETERS
 *  newscrnID           [IN] The new screen ID will enter.       
 *  newExitHandler      [IN] The exit handler of the new screen. It could be NULL.       
 *  newEntryHandler     [IN] The entry handler of the new screen. It could be NULL.       
 *  flag                [IN] flag parameters.        
 * RETURNS
 *  MMI_TRUE - enter the new screen succeed.
 *  MMI_FALSE - enter the new screen failed.
 *****************************************************************************/
U8 EntryNewScreen(U16 newscrnID, FuncPtr newExitHandler, FuncPtr newEntryHandler, void *flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store the current Top entry screen */

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_ENTRYSCR_HDLR, newscrnID, newExitHandler, newEntryHandler);

    if (flag != MMI_TAB_PAGE)
    {
        is_tab_page = MMI_FALSE;
        currTopScrnID = newscrnID;
        /* entry the new screen */
        if (!mmi_is_orderly_exit_screen ||!IsMainLCDHistoryBack())
        {
            /* disable small screen flatten for full-screen APPs */
            if (flag == MMI_FULL_SCREEN)
            {
                dm_disable_small_screen_flatten();
            }
            else
            {
                dm_enable_small_screen_flatten();
            }
            
            PRINT_INFORMATION("[History] mmi_is_orderly_exit_screen");
            ExecuteCurrExitHandler();
        }
        /* store the exit current Top entry screen */
        currExitScrnID = newscrnID;

        if ((newExitHandler != NULL) || (newEntryHandler != NULL))
        {
            SetGenericExitHandler(newscrnID, newExitHandler, newEntryHandler);
        }
        mmi_frm_dump_screen_id();

        mmi_is_orderly_exit_screen = MMI_FALSE;
    }
    else
    {
        is_tab_page = MMI_TRUE;
        ExecuteCurrExitHandler();
        
        curr_tab_exit_func_ptr = newExitHandler;
    
        SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    
#ifdef __LSK_KEYSEND2_IN_ONE__
    MTPNP_PFAL_CC_SetIsKeyForCall(MMI_FALSE);
#endif/*__LSK_KEYSEND2_IN_ONE__*/

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryNewScreen_Ext
 * DESCRIPTION
 *  The behavior is the same with EntryNewScreen(), but this function doesn't 
 *  clear the key handlers.
 * PARAMETERS
 *  newscrnID           [IN]   The new screen ID will enter.     
 *  newExitHandler      [IN]   The exit handler of the new screen. It could be NULL.      
 *  newEntryHandler     [IN]   The entry handler of the new screen. It could be NULL.     
 *  peerBuf             [IN]   Reserved.       
 * RETURNS
 *  MMI_TRUE - enter the new screen succeed.
 *  MMI_FALSE - enter the new screen failed.
 *****************************************************************************/
U8 EntryNewScreen_Ext(U16 newscrnID, FuncPtr newExitHandler, FuncPtr newEntryHandler, void *peerBuf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store the current Top entry screen */
    currTopScrnID = newscrnID;
    /* entry the new screen */
    ExecuteCurrExitHandler_Ext();
    /* store the exit current Top entry screen */
    currExitScrnID = newscrnID;
    if ((newExitHandler != NULL) || (newEntryHandler != NULL))
    {
        SetGenericExitHandler(newscrnID, newExitHandler, newEntryHandler);
    }
    mmi_frm_dump_screen_id();

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ExecuteCurrExitHandler_Ext
 * DESCRIPTION
 * This function is used for executes current exit func handler without clear keys.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK added by JL for keypad without clearall requirement */
void ExecuteCurrExitHandler_Ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    /* Clear g_mmi_frm_cntx.dump_screen_info.backup_string */
    g_mmi_frm_cntx.dump_screen_info.backup_string[0] = 0;
    g_mmi_frm_cntx.dump_screen_info.backup_string[1] = 0;
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif
    /* Failsafe common function before exit screen */
    UI_common_screen_pre_exit();

    for (count = 0; count < MAX_SUB_MENUS; count++)
    {
        subMenuDataPtrs[count] = subMenuData[count];
    }

    if (currEntryFuncPtr || currExitFuncPtr)
    {
    #ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
        mmi_frm_clear_all_interrupt_event_handler_old();
    #endif
        mmi_frm_reset_interrupt_event_context();
    }

    if (curr_tab_exit_func_ptr)
    {
        (*curr_tab_exit_func_ptr)();
        curr_tab_exit_func_ptr = NULL;        
    }

    /* call GenericExitScreen if currEntryFuncPtr is not NULL */
    if (!is_tab_page)
    {
        if (currEntryFuncPtr)
        {
            GenericExitScreen(currExitScrnID, currEntryFuncPtr);
        }

        if (currExitFuncPtr)
        {
           MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXIT_HDLR);
           mmu_frm_execute_scrn_exit_handler = MMI_TRUE;
           (*currExitFuncPtr) ();
           mmu_frm_execute_scrn_exit_handler = MMI_FALSE;
        }


        currEntryFuncPtr = NULL;
        currExitFuncPtr = NULL;
    }  

    /* Failsafe common screen exit function   */
    UI_common_screen_exit();

    /* it clears all the key handlers, registered by the current screen */
    IsBackHistory = FALSE;

    /* To dump the history memory */
    HistoryDump();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_execute_scrn_exit_func
 * DESCRIPTION
 *  This function is used for check if framework executes the screen's exit 
 *  handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_execute_scrn_exit_func(void)
{
    return mmu_frm_execute_scrn_exit_handler;
}


/*****************************************************************************
 * FUNCTION
 *  ExecuteCurrHiliteHandler
 * DESCRIPTION
 *  This function finds out the current highlight menu item's handler and 
 *  executes it with clear KEY_RIGHT_ARROW key handler. Sometimes the sub menu
 *  items may be hidden and the sub menu item index will be different. This 
 *  function also handle this case.
 * PARAMETERS
 *  hiliteid        [IN]  ID of the item for which highlight handler needs to 
 *                        be executed.      
 * RETURNS
 *  void
 *****************************************************************************/
void ExecuteCurrHiliteHandler(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* To avoid the arrow left key to entry unexpected function, while other APP need they shall register again as BY request. */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    ExecuteCurrHiliteHandler_Ext(hiliteid);

}


/*****************************************************************************
 * FUNCTION
 *  ExecuteCurrHiliteHandler_Ext
 * DESCRIPTION
 *  This function finds out the current highlight menu item's handler and 
 *  executes it without clear KEY_RIGHT_ARROW key handler. Sometimes the sub 
 *  menu items may be hidden and the sub menu item index will be different.
 *  This function also handle this case.
 * PARAMETERS
 *  hiliteid        [IN]  ID of the item for which highlight handler needs to 
 *                        be executed.      
 * RETURNS
 *  void
 *****************************************************************************/
void ExecuteCurrHiliteHandler_Ext(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr currFuncPtr = NULL;
    S32 hiliteItemID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHiliteID = (U16) hiliteid;
    if (currParentID == 0)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_EVENT_EXECURHILIHTE_HDLR);
        return;
    }

    /* check if menuitem is hidden */
    hiliteItemID = GetSeqItemId_Ext((U16) currParentID, (S16) hiliteid);    
    currFuncPtr = maxHiliteInfo[hiliteItemID].entryFuncPtr;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXECURHILIHTE_HDLR, hiliteItemID, currFuncPtr);
    
    if (currFuncPtr)
    {
        (*currFuncPtr) ();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrHiliteID
 * DESCRIPTION
 *  This function is used for query the current highlighted menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns the index of the currently highlighted menu item
 *****************************************************************************/
U16 GetCurrHiliteID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return currHiliteID;
}


/*****************************************************************************
 * FUNCTION
 *  SetHiliteHandler
 * DESCRIPTION
 *  This function is used for register the handler for the menu item. If the 
 *  menu items are pre-definable, the applications use this function to set 
 *  the highlight handlers.
 *
 *  Note: Please distinguish the function from RegisterHighlightHandler() 
 *        which is provided by UI layer. SetHiliteHandler() is for single 
 *        menu item; RegisterHighlightHandler() is global for all menu items.
 * PARAMETERS
 *  itemid              [IN]  ID of the item for which highlight handler needs 
 *                            to be set.      
 *  hiliteFuncPtr       [IN]  Function to be executed whenever item with above
 *                            ID is highlighted.      
 * RETURNS
 *  void
 *****************************************************************************/
void SetHiliteHandler(U16 itemid, FuncPtr hiliteFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETCURHILIHTE_HDLR, itemid, hiliteFuncPtr);

    maxHiliteInfo[itemid].entryFuncPtr = hiliteFuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  ClearHiliteHandler
 * DESCRIPTION
 *  This function is used for clear hilite func handlers for a particular menu item
 * PARAMETERS
 *  itemid      [IN] Item ID to for which one want to disable highlight handler.       
 * RETURNS
 *  void
 *****************************************************************************/
void ClearHiliteHandler(U16 itemid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRCURHILIHTE_HDLR, itemid);

    maxHiliteInfo[itemid].entryFuncPtr = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  ConstructHintsList
 * DESCRIPTION
 *  Constructs Hint List for a static menu screen
 * PARAMETERS
 *  parentID        [IN]   The parent screen ID to construct enough hint list 
 *                         string array.     
 *  hintArray       [OUT]  The application fill the hint string into the output
 *                         array.     
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_frm_test_menu_item_hide(U16 menu_item_id);
void ConstructHintsList(U16 parentID, U8 **hintArray)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, noOfChild;
    U16 hiliteItemID[MAX_SUB_MENUS];
    U8 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    noOfChild = (U8) GetNumOfChild(parentID);
    for (i = 0; i < noOfChild; i++)
    {
        hiliteItemID[i] = GetSeqItemId((U16) parentID, (S16) i);
        /* check if menuitem is hidden */
        if (!mmi_frm_test_menu_item_hide(hiliteItemID[i]))  /* the menuitem is not hidden */
        {
            if (maxHiliteInfo[hiliteItemID[i]].hintFuncPtr)
            {
                (*maxHiliteInfo[hiliteItemID[i]].hintFuncPtr) (idx);
                hintArray[idx] = hintData[idx];
                idx++;
            }
            else
            {
                hintArray[idx++] = NULL;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetHintHandler
 * DESCRIPTION
 *  This function is used for register the handler for the menu item. The 
 *  registered should be responsible for providing hint content of one menu 
 *  item.
 * PARAMETERS
 *  itemid          [IN]   ID of the item for which hint handler needs to be set.
 *  hintFuncPtr     [IN]   Function to be executed whenever item with above ID 
 *                         is highlighted.     
 * RETURNS
 *  void
 *****************************************************************************/
void SetHintHandler(U16 itemid, FuncPtrShort hintFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETHINT_HDLR, itemid, hintFuncPtr);

    maxHiliteInfo[itemid].hintFuncPtr = hintFuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  ClearHintHandler
 * DESCRIPTION
 *  This is used to clear hint function handler associated with ItemID.
 * PARAMETERS
 *  itemid      [IN]  Item ID to for which one want to disable hint handler      
 * RETURNS
 *  void
 *****************************************************************************/
void ClearHintHandler(U16 itemid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRHINT_HDLR, itemid);

    maxHiliteInfo[itemid].hintFuncPtr = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  SetParentHandler
 * DESCRIPTION
 *  This is used to set current parent menu item ID. After the application 
 *  set the parent menu item ID, the framework understand which menu is the 
 *  application in and handle the highlight and hint handler.
 * PARAMETERS
 *  parentID        [IN]  The parent menu item ID.      
 * RETURNS
 *  void
 *****************************************************************************/
void SetParentHandler(U16 parentID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETPARENT_HDLR, parentID);

    currParentID = parentID;
}

/* MTK Brian added for AT+CVIB, 2003/11/23 */


/*****************************************************************************
 * FUNCTION
 *  GetParentHandler
 * DESCRIPTION
 *  This is used to get current parent menu item ID.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the parent item ID.
 *****************************************************************************/
U16 GetParentHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return currParentID;
}


/*****************************************************************************
 * FUNCTION
 *  ClearInputEventHandler
 * DESCRIPTION
 *  This function is used for clear all input device handlers associated 
 *  with current screen.
 *  The input value should be one of following devices:
 *    MMI_DEVICE_KEY   Key events
 *    MMI_DEVICE_PEN   Pen events
 *    MMI_DEVICE_ALL   All of above device events.
 *
 * PARAMETERS
 *  device      [IN]        Which device handlers would be  cleared
 * RETURNS
 *  void
 *****************************************************************************/
void ClearInputEventHandler(U16 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (device & MMI_DEVICE_KEY)
    {
        ClearAllKeyHandler();
    }

#ifdef  __MMI_TOUCH_SCREEN__
    if ( device & MMI_DEVICE_PEN )
    {
        wgui_clear_pen_handlers();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SetEntryHandler
 * DESCRIPTION
 *  This is used to sets current screen entry handlers
 * PARAMETERS
 *  scrnID              [IN]   The current screen ID.     
 *  entryFuncPtr        [IN]   The entry handler of the current screen.     
 * RETURNS
 *  void
 *****************************************************************************/
void SetEntryHandler(U16 scrnID, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETENTRY_HDLR, scrnID);
    currEntryFuncPtr = entryFuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  ClearEntryHandler
 * DESCRIPTION
 *  This is used to clears current screen e1ntry handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearEntryHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRENTRY_HDLR);
    currEntryFuncPtr = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  SetGenericExitHandler
 * DESCRIPTION
 *  Generic function to set exit screen handler.
 *  Store current screen id, exit function, and entry function.
 * PARAMETERS
 *  scrnID              [IN]        Screen ID
 *  exitFuncPtr         [IN]        Exit function pointer
 *  entryFuncPtr        [IN]        Entry function pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void SetGenericExitHandler(U16 scrnID, FuncPtr exitFuncPtr, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETGEN_EXIT_HDLR, scrnID);

    currExitScrnID = scrnID;
    currExitFuncPtr = exitFuncPtr;
    currEntryFuncPtr = entryFuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  GenericExitInlineScreen
 * DESCRIPTION
 *  This function is the general inline screen's exit handler. If the previous 
 *  screen is the inline editor screen and needs to add in the history, the 
 *  framework calls this function to execute the general exit handler first, 
 *  then tries to call its exit handler.
 * PARAMETERS
 *  scrnID              [IN]        The specified screen ID will exit.
 *  entryFuncPtr        [IN]        The entry handler of the specified screen. 
 *                                  The specified screen should be inline editor
 *                                  screen.
 * RETURNS
 *  void
 *****************************************************************************/
void GenericExitInlineScreen(U16 scrnID, FuncPtr entryFuncPtr)
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
    h.scrnID = scrnID;
    h.entryFuncPtr = entryFuncPtr;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  GenericExitScreen
 * DESCRIPTION
 *  This function is the general screen's exit handler. If the previous screen
 *  is the normal screen (not inline editor screen) and needs to add in the 
 *  history, the framework calls this function to execute the general exit 
 *  handler first, then tries to call its exit handler.
 * PARAMETERS
 *  scrnID              [IN]        The specified screen ID will exit.
 *  entryFuncPtr        [IN]        The entry handler of the specified screen. 
 *                                  The specified screen without inputBuffer[ ].
 * RETURNS
 *  void
 *****************************************************************************/
void GenericExitScreen(U16 scrnID, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXEGEN_EXIT_HDLR, scrnID);

    h.scrnID = scrnID;
    h.entryFuncPtr = entryFuncPtr;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
    /* mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_disable_mini_tab_bar();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  GetExitScrnID
 * DESCRIPTION
 *  This function is used for query the screen ID that will be exited. 
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the screen ID that will be exited.
 *****************************************************************************/
U16 GetExitScrnID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_GETGEN_EXIT_HDLR,currExitScrnID);

    return currExitScrnID;
}


/*****************************************************************************
 * FUNCTION
 *  GetExitScrnID_r
 * DESCRIPTION
 *  Thead-safe version of GetExitScrnID()
 * PARAMETERS
 *  void
 * RETURNS
 *  Current screen ID
 *****************************************************************************/
U16 GetExitScrnID_r(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* This function should be kept as simple as possible. MMI_TRACE() cannot be used */
    return currExitScrnID;
}


/*****************************************************************************
 * FUNCTION
 *  ClearExitHandler
 * DESCRIPTION
 *  This function is used for special scenarios. If the applications enter 
 *  the special screen A and want to go back to the idle screen directly 
 *  after exiting the screen A, they could use this function to clear the 
 *  pervious screen's exit hanler before enter the special screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearExitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLREXIT_HDLR);
    currExitScrnID = 0;
    currExitFuncPtr = NULL;
    currEntryFuncPtr = NULL;

}

/*****************************************************************************
 * FUNCTION
 *  MaskItems
 * DESCRIPTION
 *  This function is used for gets the items from the item array using the 
 *  given mask.  The data type of item should U16. 
 * PARAMETERS
 *  maskList        [IN/OUT]  The array of items.      
 *  noOfItems       [IN]      The number of the list.     
 *  maskingWord     [IN]      the mask word.   
 * RETURNS
 *  The number of item be marked.
 *****************************************************************************/
U8 MaskItems(U16 *maskList, U8 noOfItems, U32 maskingWord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < noOfItems; i++)
        if (IsBitSet(maskingWord, i))
        {
            maskList[count++] = maskList[i];
        }
    return (U8) count;
}


/*****************************************************************************
 * FUNCTION
 *  MaskItemsU8
 * DESCRIPTION
 *  This function is used for gets the items from the item array using the 
 *  given mask.  The data type of item should U8. 
 * PARAMETERS
 *  maskList        [IN/OUT]  The array of items.      
 *  noOfItems       [IN]      The number of the list.  
 *  maskingWord     [IN]      the mask word.   
 * RETURNS
 *  The number of item be marked.
 *****************************************************************************/
U8 MaskItemsU8(U8 *maskList, U8 noOfItems, U32 maskingWord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < noOfItems; i++)
        if (IsBitSet(maskingWord, i))
        {
            maskList[count++] = maskList[i];
        }
    return (U8) count;
}


/*****************************************************************************
 * FUNCTION
 *  MaskStringItems
 * DESCRIPTION
 *  This function is used for gets the strings from the string array 
 *  using the given mask.  The data type of item should the pointer to U8. 
 * PARAMETERS
 *  maskList        [IN/OUT]  The array of items.      
 *  noOfItems       [IN]      The number of the list.  
 *  maskingWord     [IN]      the mask word.      
 * RETURNS
 *  U8
 *****************************************************************************/
U8 MaskStringItems(U8 **maskList, U8 noOfItems, U32 maskingWord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < noOfItems; i++)
        if (IsBitSet(maskingWord, i))
        {
            maskList[count++] = maskList[i];
        }
    return (U8) count;
}


/*****************************************************************************
 * FUNCTION
 *  MaskHiliteItems
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parentID        [IN]        
 *  maskingWord     [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 MaskHiliteItems(U16 parentID, U32 maskingWord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0, noOfChild, i;
    U16 hiliteItemID[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    noOfChild = (U8) GetNumOfChild(parentID);
    for (i = 0; i < noOfChild; i++)
    {
        hiliteItemID[i] = GetSeqItemId((U16) parentID, (S16) i);
    }
    for (i = 0; i < noOfChild; i++)
        if (IsBitSet(maskingWord, i))
        {
            maxHiliteInfo[hiliteItemID[count++]].entryFuncPtr = maxHiliteInfo[hiliteItemID[i]].entryFuncPtr;
        }
    return (U8) count;
}


/*****************************************************************************
 * FUNCTION
 *  GetActiveScreenId
 * DESCRIPTION
 *  This function is used for query the current active screen ID. The 
 *  application use this function to get the current active screen ID in 
 *  different occasions.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the screen ID
 *****************************************************************************/
U16 GetActiveScreenId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return currTopScrnID;
}


/*****************************************************************************
 * FUNCTION
 *  SetActiveScreenId
 * DESCRIPTION
 *  Sets the current active screen ID.
 * PARAMETERS
 *  scrnId      [IN]  the screen ID      
 * RETURNS
 *  void
 *****************************************************************************/
void SetActiveScreenId(U16 scrnId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currTopScrnID = scrnId;
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrEntryFuncPtr
 * DESCRIPTION
 *  Get current entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to the current entry function.
 *****************************************************************************/
FuncPtr GetCurrEntryFuncPtr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return currEntryFuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrEntryFuncPtr
 * DESCRIPTION
 *  Sets current entry function
 * PARAMETERS
 *  ptr     [IN]  The pointer to the entry function.      
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrEntryFuncPtr(FuncPtr ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currEntryFuncPtr = ptr;
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrExitFuncPtr
 * DESCRIPTION
 *  Get current exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to the current exit function
 *****************************************************************************/
FuncPtr GetCurrExitFuncPtr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return currExitFuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrExitFuncPtr
 * DESCRIPTION
 *  Sets current exit function
 * PARAMETERS
 *  ptr     [IN]  The pointer to the exit function.      
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrExitFuncPtr(FuncPtr ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currExitFuncPtr = ptr;
}


/*****************************************************************************
 * FUNCTION
 *  ExecuteItemHiliteHandler
 * DESCRIPTION
 *  Execute the hilite handler of specified menu item
 * PARAMETERS
 *  hiliteItemID        [IN]  ID of the item for which highlight handler needs 
 *                            to be executed.       
 * RETURNS
 *  void
 *****************************************************************************/
void ExecuteItemHiliteHandler(U16 hiliteItemID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (maxHiliteInfo[hiliteItemID].entryFuncPtr != NULL)
    {
        maxHiliteInfo[hiliteItemID].entryFuncPtr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_dump_screen_id
 * DESCRIPTION
 *  This function will dump active screen id
 * CALLS
 *  
 * PARAMETERS
 *  inject_str      [IN]        Injection string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_dump_screen_id(void)
{
    MMI_BOOL need_dump = MMI_FALSE;
    
    switch (mmi_frm_report_screen_state)
    {
    case MMI_FRM_REPORT_SCREEN_STATE_PASSIVE:   /* only report screen id when receiving request command */
        /* do nothing */
        break;
    case MMI_FRM_REPORT_SCREEN_STATE_AUTO:      /* only report popup screen id in active */
        if ((currExitScrnID == currTopScrnID) &&
            (currExitScrnID == POPUP_SCREENID ||
             currExitScrnID == SCR_POPUP_SCREEN ||
             currExitScrnID == SCR_CONFIRM_SCREEN))
        {
            need_dump = MMI_TRUE;
        }
        break;
    case MMI_FRM_REPORT_SCREEN_STATE_ACTIVE:    /* report all screen id in active */
        need_dump = MMI_TRUE;
        break;
    default:
        break;
    }
    
    if (need_dump)
    {
		MYQUEUE Message;
        mmi_inject_string_rsp_struct *rsp;

        rsp = (mmi_inject_string_rsp_struct*) OslConstructDataPtr(sizeof(mmi_inject_string_rsp_struct));
        rsp->scrnid = (kal_uint16)currExitScrnID;
        
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = MSG_ID_MMI_INJECT_STRING_RSP;
        Message.oslDataPtr = (oslParaType*) rsp;
        Message.oslPeerBuffPtr = NULL;
    
        OslMsgSendExtQueue(&Message);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_proc_inject_string
 * DESCRIPTION
 *  This function will process injection string
 * CALLS
 *  
 * PARAMETERS
 *  inject_str      [IN]        Injection string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_proc_inject_string(void * in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tst_inject_string_struct *inject_str = (tst_inject_string_struct *)in;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We could parser the string to execute the different actions. */
    if (strcmp((const kal_char*)inject_str->string, "mtk+scrnid?") == 0)
    {
        mmi_frm_report_screen_state_enum org_setting = mmi_frm_report_screen_state;
        
        mmi_frm_report_screen_state = MMI_FRM_REPORT_SCREEN_STATE_ACTIVE;
        mmi_frm_dump_screen_id();
        mmi_frm_report_screen_state = org_setting;
    }
    else if (strcmp((const kal_char*)inject_str->string, "mtk+config") == 0)
    {
        if (inject_str->index < MMI_FRM_REPORT_SCREEN_STATE_MAX)
        {
            mmi_frm_report_screen_state = (mmi_frm_report_screen_state_enum)inject_str->index;
        }
        return;
    }

    switch(inject_str->index)
    {
        case 1:
            /* add the code here */
            break;
        case 2:
            /* add the code here */
            break;    
        
        default:
            /* add the code here */
            break;
    }
}



