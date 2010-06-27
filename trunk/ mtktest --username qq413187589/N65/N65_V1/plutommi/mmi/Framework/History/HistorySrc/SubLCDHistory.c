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
 * SubLCDHistory.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sublcd history control
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

/**************************************************************

   FILENAME : SubLCDHistory.c

   PURPOSE     : Implementation of Sub-LCD history stack

   REMARKS     : nil

   AUTHOR      : Deepali

   DATE     : Sept 23, 2003

**************************************************************/

#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr.h"
#include "MMIDataType.h"
#include "FrameworkGprot.h"
#include "FrameworkProt.h"
#include "DebugInitDef.h"
#include "Unicodexdcl.h"

#ifdef __MMI_SUBLCD_MASTER_MODE__
#include "IdleAppProt.h"
#endif/*__MMI_SUBLCD_MASTER_MODE__*/
#include "MMI_trc.h"

#define SUB_LCD_DUMMY_SCRNID     (0x9999)

/* 
 *   Extern Varibales 
 */

/* 
 *   Local Variables 
 */
#ifdef __MMI_SUBLCD__

#ifdef __MMI_SUBLCD_MASTER_MODE__

#include "EventsGprot.h"

#define SUBLCD_MASTER_MODE_ROOT_SCREEN_ENTRY_FUNC	((SubLcdHistoryCBPtr)EntrySubLCDMainMenu)

#define SUBLCD_PREPARE_TO_UPDATE_BY_MAIN_LCD_APP    (0xff)
#define SUBLCD_UPDATE_BY_SUB_LCD_APP                (0x0)
#define SUBLCD_UPDATE_BY_MAIN_LCD_APP               (0x1)

extern BOOL IsClamClose(void);
extern void EntrySubLCDMainMenuScreen(void);

static SubLCDHistoryInternalNode *SubLCDHistoryData; /* array of history data */
static pBOOL IsBackSubLCDHistory = FALSE;
static signed char NodeIndex = -1;
static U16 gCurrTopSubLCDScrnID = 0;
static U16 gCurrExitSubLCDScrnID = 0;
static FuncPtr gCurrExitSubLCDFn = NULL;
static FuncPtr gCurrEntrySubLCDFn = NULL;
static SubLcdHistoryCBPtr ExecuteRootSubLcdHistoryScreenPtr = NULL;

static SubLCDHistoryInternalNode SubLCDHistoryData_slave[MAX_SUBLCD_HISTORY]; /* array of history data */
static pBOOL IsBackSubLCDHistory_slave = FALSE;
static signed char NodeIndex_slave = -1;
static U16 gCurrTopSubLCDScrnID_slave = 0;
static U16 gCurrExitSubLCDScrnID_slave = 0;
static FuncPtr gCurrExitSubLCDFn_slave = NULL;
static FuncPtr gCurrEntrySubLCDFn_slave = NULL;
static SubLcdHistoryCBPtr ExecuteRootSubLcdHistoryScreenPtr_slave = NULL;

static SubLCDHistoryInternalNode SubLCDHistoryData_master[MAX_SUBLCD_HISTORY]; /* array of history data */
static pBOOL IsBackSubLCDHistory_master = FALSE;
static signed char NodeIndex_master = -1;
static U16 gCurrTopSubLCDScrnID_master = 0;
static U16 gCurrExitSubLCDScrnID_master = 0;
static FuncPtr gCurrExitSubLCDFn_master = NULL;
static FuncPtr gCurrEntrySubLCDFn_master = NULL;
static SubLcdHistoryCBPtr ExecuteRootSubLcdHistoryScreenPtr_master = NULL;

static U8 gCurrSubLCDUpdateBy = SUBLCD_UPDATE_BY_MAIN_LCD_APP;

#else/* __MMI_SUBLCD_MASTER_MODE__ */ 

static SubLCDHistoryInternalNode SubLCDHistoryData[MAX_SUBLCD_HISTORY]; /* array of history data */
static pBOOL IsBackSubLCDHistory = FALSE;
static signed char NodeIndex = -1;
static U16 gCurrTopSubLCDScrnID = 0;
static U16 gCurrExitSubLCDScrnID = 0;
static FuncPtr gCurrExitSubLCDFn = NULL;
static FuncPtr gCurrEntrySubLCDFn = NULL;
static SubLcdHistoryCBPtr ExecuteRootSubLcdHistoryScreenPtr = NULL;

#endif/* __MMI_SUBLCD_MASTER_MODE__ */ 

#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExecSubLCDCurrExitHandler
 * DESCRIPTION
 *  Execute the Current Exit handler of SubLCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExecSubLCDCurrExitHandler(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_EXE_SUBLCD_CUR_EXIT_HDLR);
#ifdef __MMI_SUBLCD_MASTER_MODE__
    if (IsClamClose() && (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M ||
                            g_sublcd_master_cntx.state == SUBLCD_MODE_M2S))
    {
	    IsBackSubLCDHistory = FALSE;
        return;
    }
#endif/*__MMI_SUBLCD_MASTER_MODE__*/

    /*
     * When goback history in subLCD, we should execute current exit handler but
     * not allow to add the history.
     */
    if (gCurrExitSubLCDFn != NULL)
    {
        gCurrExitSubLCDFn();
        gCurrExitSubLCDFn = NULL;
    }
    IsBackSubLCDHistory = FALSE;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  AddSubLCDHistory
 * DESCRIPTION
 *  Saves Sublcd function in History
 * PARAMETERS
 *  CurrSubLCDHistory       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AddSubLCDHistory(SubLCDHistoryNode *CurrSubLCDHistory)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_MASTER_MODE__
		if (IsClamClose())
		{
			if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M ||
				g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
			{
            IsBackSubLCDHistory = FALSE;
				return;
			}
		}
#endif/*__MMI_SUBLCD_MASTER_MODE__*/

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_HIST_HDLR);

    /* MTK added by JL for back history. */
    if (IsBackSubLCDHistory != TRUE)
    {
        FuncPtr CurrSubLCDEntryFn = CurrSubLCDHistory->entryFuncPtr;

        if (CurrSubLCDEntryFn != NULL)
        {
            SubLCDHistoryData[++NodeIndex].entryFuncPtr = CurrSubLCDEntryFn;
            SubLCDHistoryData[NodeIndex].scrnID = SUB_LCD_DUMMY_SCRNID;
            SubLCDHistoryData[NodeIndex].guiLen = 0;
            SubLCDHistoryData[NodeIndex].guiBuffer = NULL;
        }
    }
    IsBackSubLCDHistory = FALSE;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  AddSubLCDHistoryWithScrID
 * DESCRIPTION
 *  Saves Sublcd function in History with ScrID
 * PARAMETERS
 *  CurrSubLCDHistory       [IN]        
 *  scrID                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AddSubLCDHistoryWithScrID(SubLCDHistoryNode *CurrSubLCDHistory, U16 scrID)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNodeEx subLCDHistory = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_MASTER_MODE__
    if (IsClamClose())
    {
    	if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M ||
    		g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
    	{
            IsBackSubLCDHistory = FALSE;
    		return;
    	}
    }
#endif/*__MMI_SUBLCD_MASTER_MODE__*/

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    subLCDHistory.entryFuncPtr = CurrSubLCDHistory->entryFuncPtr;
    subLCDHistory.scrnID = scrID;
    AddSubLCDHistoryWithScrIDEx(&subLCDHistory, scrID);
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  AddSubLCDHistoryWithScrIDEx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  CurrSubLCDHistory       [?]         
 *  scrID                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AddSubLCDHistoryWithScrIDEx(SubLCDHistoryNodeEx *CurrSubLCDHistory, U16 scrID)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_MASTER_MODE__
    if (IsClamClose())
    {
    	if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M ||
    		g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
    	{
            IsBackSubLCDHistory = FALSE;
    		return;
    	}
    }
#endif/*__MMI_SUBLCD_MASTER_MODE__*/

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_HIST_WITHSCRID_HDLR, scrID);

    /* MTK added by JL for back history. */
    if (IsBackSubLCDHistory != TRUE)
    {
        FuncPtr CurrSubLCDEntryFn = CurrSubLCDHistory->entryFuncPtr;

        if (CurrSubLCDEntryFn != NULL)
        {
            SubLCDHistoryData[++NodeIndex].entryFuncPtr = CurrSubLCDEntryFn;
            SubLCDHistoryData[NodeIndex].scrnID = scrID;

            SubLCDHistoryData[NodeIndex].guiLen = 0;
            SubLCDHistoryData[NodeIndex].guiBuffer = NULL;
            if (mmi_ucs2strlen((PS8) (CurrSubLCDHistory->guiBuffer)))
            {
                SubLCDHistoryData[NodeIndex].guiLen = MAX_GUI_BUFFER;
                SubLCDHistoryData[NodeIndex].guiBuffer = OslMalloc(MAX_GUI_BUFFER);
                memcpy(SubLCDHistoryData[NodeIndex].guiBuffer, CurrSubLCDHistory->guiBuffer, MAX_GUI_BUFFER);
            }
        }
    }
    IsBackSubLCDHistory = FALSE;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  SetSubLCDExitHandler
 * DESCRIPTION
 *  Set Exit handler for Current screen
 * PARAMETERS
 *  CurrSubLCDFn        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetSubLCDExitHandler(FuncPtr CurrSubLCDFn)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_EXIT_HDLR, CurrSubLCDFn);

    gCurrExitSubLCDFn = CurrSubLCDFn;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  SetSubLCDEntryHandler
 * DESCRIPTION
 *  Set Entry handler for Current screen
 * PARAMETERS
 *  CurrSubLCDFn                [IN]        
 *  CurrSubLCDEntryFn(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetSubLCDEntryHandler(FuncPtr CurrSubLCDFn)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_ENTRY_HDLR, CurrSubLCDFn);

    gCurrEntrySubLCDFn = CurrSubLCDFn;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  DecrementSubLCD
 * DESCRIPTION
 *  decrement the global history index of sub-LCD
 *  
 *  decrement the global NodeIndex
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void DecrementSubLCD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NodeIndex >= 0)
    {
        if (SubLCDHistoryData[NodeIndex].guiBuffer)
        {
            OslMfree(SubLCDHistoryData[NodeIndex].guiBuffer);
        }
        memset(&SubLCDHistoryData[NodeIndex], 0, sizeof(SubLCDHistoryNode));
        NodeIndex--;
    }
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  InitSubLCDHistory
 * DESCRIPTION
 *  De-intialize SubLCD Screen history
 * PARAMETERS
 *  sublcd_root_screen_cb_ptr       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void InitSubLCDHistory(SubLcdHistoryCBPtr sublcd_root_screen_cb_ptr)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_INIT, sublcd_root_screen_cb_ptr);

#ifdef __MMI_SUBLCD_MASTER_MODE__
    ExecuteRootSubLcdHistoryScreenPtr_slave = sublcd_root_screen_cb_ptr;
    ExecuteRootSubLcdHistoryScreenPtr_master = SUBLCD_MASTER_MODE_ROOT_SCREEN_ENTRY_FUNC;
    g_sublcd_master_cntx.is_sublcd_force_add_history = TRUE;
    g_sublcd_master_cntx.state = SUBLCD_MODE_M2S;
    SwitchSubLCDHistory();
    g_sublcd_master_cntx.state = SUBLCD_MODE_SLAVE;
#else
    ExecuteRootSubLcdHistoryScreenPtr = (SubLcdHistoryCBPtr)sublcd_root_screen_cb_ptr;
#endif/*__MMI_SUBLCD_MASTER_MODE__*/

#endif /* __MMI_SUBLCD__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  DinitSubLCDHistory
 * DESCRIPTION
 *  De-intialize SubLCD Screen history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DinitSubLCDHistory(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signed char count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_DEINIT);

    if (NodeIndex > -1)
    {
        for (count = NodeIndex; count >= 0; count--)
        {
            /* don't check the return value of delCBHandler */
            ExecHistoryScrnCallBackHandle_ex(NodeIndex, 0);
            DecrementSubLCD();
        }
        NodeIndex = -1;
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDScreen
 * DESCRIPTION
 *  Calls entry function of the specified screen on the
 *  sub-LCD screen
 * PARAMETERS
 *  SubLCDEntryFn       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDScreen(FuncPtr SubLCDEntryFn)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_SHOW_SUBLCD_HDLR, SubLCDEntryFn);
#ifdef __MMI_SUBLCD_MASTER_MODE__
    gCurrSubLCDUpdateBy = SUBLCD_PREPARE_TO_UPDATE_BY_MAIN_LCD_APP;
#endif/*__MMI_SUBLCD_MASTER_MODE__*/
    DisplaySubLCDScreen(SUB_LCD_DUMMY_SCRNID, SubLCDEntryFn, 0);

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ForceSubLCDScreen
 * DESCRIPTION
 *  force to call entry function of a screen SubLCD Screen
 * PARAMETERS
 *  SubLCDEntryFn       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ForceSubLCDScreen(FuncPtr SubLCDEntryFn)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_FORCE_SUBLCD_HDLR, SubLCDEntryFn);
#ifdef __MMI_SUBLCD_MASTER_MODE__
    gCurrSubLCDUpdateBy = SUBLCD_PREPARE_TO_UPDATE_BY_MAIN_LCD_APP;
#endif/*__MMI_SUBLCD_MASTER_MODE__*/
    DisplaySubLCDScreen(SUB_LCD_DUMMY_SCRNID, SubLCDEntryFn, 1);

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  DisplaySubLCDScreen
 * DESCRIPTION
 *  Display a screen SubLCD Screen
 * PARAMETERS
 *  scrnId              [IN]        
 *  SubLCDEntryFn       [IN]        
 *  is_force            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DisplaySubLCDScreen(U16 scrnId, FuncPtr SubLCDEntryFn, MMI_BOOL is_force)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL flag = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_DISPLAY_SUBLCD_HDLR, SubLCDEntryFn, scrnId, is_force);

#ifdef __MMI_SUBLCD_MASTER_MODE__
    if (gCurrSubLCDUpdateBy == SUBLCD_PREPARE_TO_UPDATE_BY_MAIN_LCD_APP)
    {
        /* Display SubLCD screen by main LCD application */
        gCurrSubLCDUpdateBy = SUBLCD_UPDATE_BY_MAIN_LCD_APP;
    }
    else
    {
        /* Display SubLCD screen by sub LCD application (in master mode) */
        gCurrSubLCDUpdateBy = SUBLCD_UPDATE_BY_SUB_LCD_APP;
    }
    
    if (IsClamClose())
    {
        if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M)
        {
            g_sublcd_master_cntx.state = SUBLCD_MODE_MASTER;
        }
        else if (g_sublcd_master_cntx.state == SUBLCD_MODE_MASTER )
			//SubLCDEntryFn != ShowIdleAppSubLcd
        {
            SetSubLCDInSlaveMode();
        }
    }
#endif/*__MMI_SUBLCD_MASTER_MODE__*/

    if (!is_force)
    {
        /* refer ShowSubLCDScreen() */
    #ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__  /* 010706 small screen Calvin */
        if (is_redrawing_old_screens())
        {
            return;
        }
    #endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 
    }

    if (!is_force)
    {
        /* refer ShowSubLCDScreen() */
        if (IsMainLCDHistoryBack())
        {
            /* no need to display the sub LCD screen */
            flag = MMI_FALSE;
        }
    }

    if (flag)
    {
        gCurrTopSubLCDScrnID = scrnId;
        gCurrEntrySubLCDFn = SubLCDEntryFn;
        SubLCDEntryFn();
        gCurrExitSubLCDScrnID = scrnId;
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GoBackSubLCDHistory
 * DESCRIPTION
 *  Go back to history On SubLCD Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackSubLCDHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_MASTER_MODE__
    if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M || 
        g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
    {
        return;
    }
#endif
    GoBackSubLCDHistoryInt();
}


/*****************************************************************************
 * FUNCTION
 *  GoBackSubLCDHistoryInt
 * DESCRIPTION
 *  Go back to history On SubLCD Screen
 * If enable SUBLCD_MASTER_MODE, this function is used for switching mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackSubLCDHistoryInt(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrnId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_GO_BACK_SUBLCD_HDLR);

    if (NodeIndex >= 0)
    {
        IsBackSubLCDHistory = TRUE;

        ExecTopScrnCallbackHandler_ex(0);
        scrnId = SubLCDHistoryData[NodeIndex].scrnID;
        if (SubLCDHistoryData[NodeIndex].entryFuncPtr)
        {
            gCurrTopSubLCDScrnID = scrnId;
            gCurrEntrySubLCDFn = SubLCDHistoryData[NodeIndex].entryFuncPtr;
            SubLCDHistoryData[NodeIndex].entryFuncPtr();
            gCurrExitSubLCDScrnID = scrnId;
        }

        if (SubLCDHistoryData[NodeIndex].scrnID == scrnId)
        {
            DecrementSubLCD();
        }
    }
    else
    {
        ExecTopScrnCallbackHandler_ex(0);
        if (ExecuteRootSubLcdHistoryScreenPtr != NULL)
        {
            gCurrTopSubLCDScrnID = SUB_LCD_DUMMY_SCRNID;
            gCurrEntrySubLCDFn = (FuncPtr) ExecuteRootSubLcdHistoryScreenPtr;
            ExecuteRootSubLcdHistoryScreenPtr(NULL);
            gCurrExitSubLCDScrnID = SUB_LCD_DUMMY_SCRNID;
        }
        NodeIndex = -1;
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GoBacknSubLCDHistory
 * DESCRIPTION
 *  Go back 'n' history On SubLCD Screen
 * PARAMETERS
 *  nHistory        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void GoBacknSubLCDHistory(U16 nHistory)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 Count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_GO_BACK_N_SUBLCD_HDLR, nHistory);

    if (NodeIndex >= nHistory)
    {
        IsBackSubLCDHistory = TRUE;
        for (Count = nHistory; Count >= 0; --Count)
        {
            /* JL, if want to stop to run next decrement will return true. */
            if (ExecHistoryScrnCallBackHandle_ex(NodeIndex, 0) == MMI_HIST_STOP_DELETING)
            {
                break;
            }
            DecrementSubLCD();
        }

        GoBackSubLCDHistory();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GoBackToSubLCDHistory
 * DESCRIPTION
 *  Goes back to specified screen on sub-LCD
 * PARAMETERS
 *  scrnid      [IN]        
 * RETURNS
 *  U8 - status
 *****************************************************************************/
U8 GoBackToSubLCDHistory(U16 scrnid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Status = ST_FAILURE;

#ifdef __MMI_SUBLCD__
    S16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return ST_SUCCESS;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_GO_BACK_TO_SUBLCD_HDLR, scrnid);

    count = NodeIndex;

    if (!IsSubLCDScreenPresent(scrnid))
    {
        return ST_FAILURE;
    }

    do
    {
        if (NodeIndex >= 0)
        {
            if (SubLCDHistoryData[NodeIndex].scrnID == scrnid)
            {
                Status = ST_SUCCESS;
                break;
            }

            if (ExecHistoryScrnCallBackHandle_ex(NodeIndex, 0) == MMI_HIST_STOP_DELETING)
            {
                Status = ST_SUCCESS;
                break;
            }
            DecrementSubLCD();
        }

    } while ((count != NodeIndex) && (SubLCDHistoryData[NodeIndex].entryFuncPtr != NULL) && (NodeIndex > 0));
    GoBackSubLCDHistory();
#endif /* __MMI_SUBLCD__ */ 

    return Status;

}


/*****************************************************************************
 * FUNCTION
 *  GoBeyondSubLCDMarkerScr
 * DESCRIPTION
 *  Go one node beyond  marker screen on sub-LCD
 * PARAMETERS
 *  scrnid      [IN]        
 * RETURNS
 *  U8 - status
 *****************************************************************************/
U8 GoBeyondSubLCDMarkerScr(U16 scrnid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Status = ST_FAILURE;

#ifdef __MMI_SUBLCD__
    S16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return ST_SUCCESS;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_GO_BEYOND_SUBLCD_HDLR, scrnid);

    count = NodeIndex;

    if (!IsSubLCDScreenPresent(scrnid))
    {
        return ST_FAILURE;
    }

    do
    {
        if (NodeIndex > 0)
        {
            if (SubLCDHistoryData[NodeIndex].scrnID == scrnid)
            {
                Status = ST_SUCCESS;
                break;
            }
            if (ExecHistoryScrnCallBackHandle_ex(NodeIndex, 0) == MMI_HIST_STOP_DELETING)
            {
                Status = ST_FAILURE;
                break;
            }
            DecrementSubLCD();
        }
    } while ((count != NodeIndex) && (SubLCDHistoryData[NodeIndex].entryFuncPtr != NULL));

    MMI_ASSERT(NodeIndex >= 0);

    if (Status)
    {
        /* go one node beyond  marker screen */
        if (ExecHistoryScrnCallBackHandle_ex(NodeIndex, 0) == MMI_HIST_ALLOW_DELETING)
        {
            DecrementSubLCD();
        }
    }
    Status = ST_SUCCESS;

    GoBackSubLCDHistory();

#endif /* __MMI_SUBLCD__ */ 

    return Status;

}


/*****************************************************************************
 * FUNCTION
 *  GoBackBothLCDHistory
 * DESCRIPTION
 *  Go back to history on Main LCD & SubLCD Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackBothLCDHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_BACK_BOTHLCD_HIST_HDLR);
#ifdef __MMI_SUBLCD__
    GoBackSubLCDHistory();
#endif 
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  DeleteUptoSubLCDScrID
 * DESCRIPTION
 *  Go to a screen on sub-LCD and delete history of all ahead of it
 * PARAMETERS
 *  scrnid      [IN]        
 * RETURNS
 *  U8 - status
 *****************************************************************************/
U8 DeleteUptoSubLCDScrID(U16 scrnid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Status = ST_FAILURE;

#ifdef __MMI_SUBLCD__
    S16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return ST_SUCCESS;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_DEL_UPTO_SUBLCD_SCR_HDLR, scrnid);

    count = NodeIndex;
    if (!IsSubLCDScreenPresent(scrnid))
    {
        return ST_FAILURE;
    }

    do
    {
        if (SubLCDHistoryData[NodeIndex].scrnID == scrnid)
        {

            Status = ST_SUCCESS;
            break;
        }
        if (ExecHistoryScrnCallBackHandle_ex(NodeIndex, 0) == MMI_HIST_STOP_DELETING)
        {
            Status = ST_SUCCESS;
            break;
        }
        DecrementSubLCD();

    } while ((count != NodeIndex) && (SubLCDHistoryData[NodeIndex].entryFuncPtr != NULL));

#endif /* __MMI_SUBLCD__ */ 

    return Status;

}


/*****************************************************************************
 * FUNCTION
 *  DeleteNSubLCDScrId
 * DESCRIPTION
 *  Deletes up to screen id on sub-LCD and go  beyond it one node
 * PARAMETERS
 *  scrnid      [IN]        
 * RETURNS
 *  U8 - status
 *****************************************************************************/
U8 DeleteNSubLCDScrId(U16 scrnid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Status = ST_FAILURE;

#ifdef __MMI_SUBLCD__
    S16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return ST_SUCCESS;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_DEL_N_SUBLCD_SCR_HDLR, scrnid);

    count = NodeIndex;

    if (!IsSubLCDScreenPresent(scrnid))
    {
        return ST_FAILURE;
    }

    do
    {
        if (SubLCDHistoryData[NodeIndex].scrnID == scrnid)
        {
            Status = ST_SUCCESS;
            break;
        }
        if (ExecHistoryScrnCallBackHandle_ex(NodeIndex, 0) == MMI_HIST_STOP_DELETING)
        {
            Status = ST_FAILURE;
            break;
        }
        DecrementSubLCD();

    } while ((count != NodeIndex) && (SubLCDHistoryData[NodeIndex].entryFuncPtr != NULL));

    if (Status)
    {
        /* delete the one more scrnid of SubLCD history */
        if (ExecHistoryScrnCallBackHandle_ex(NodeIndex, 0) == MMI_HIST_ALLOW_DELETING)
        {
            DecrementSubLCD();
        }
    }
#endif /* __MMI_SUBLCD__ */ 
    return Status;
}


/*****************************************************************************
 * FUNCTION
 *  DeleteSubLCDScreen
 * DESCRIPTION
 *  Deletes Screen from sub-LCD history
 *  This screen id won't be deleted
 * PARAMETERS
 *  ScrId       [IN]        
 * RETURNS
 *  U16 - status
 * REMARK
 *  The behavior is the same with DeleteScreenIfPresent()
 *****************************************************************************/
U16 DeleteSubLCDScreen(U16 ScrId)
{
    U8 Status = ST_SUCCESS;

#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return ST_SUCCESS;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_DEL_SUBLCD_SCR_HDLR, ScrId);

    if (!IsSubLCDScreenPresent(ScrId))
    {
        return ST_FAILURE;
    }

    count = NodeIndex;

    /* Locating the screen */
    while (count)
    {
        if (SubLCDHistoryData[count].scrnID == ScrId)
        {
            /*
             * Not support for stop callback at this funciton 
             * Because the application want to delete the special screen in the history,
             * we don't need to check the return value of the delete callback function.
             * the behavior is the same with DeleteScreenIfPresent()
             */
            ExecHistoryScrnCallBackHandle_ex(count, 0);
            break;
        }
        --count;
    }

    if (Status)
    {
        /* Shifting All the nodes by one notch */
        for (i = count + 1; i <= NodeIndex; i++, count++)
        {
            memcpy(&SubLCDHistoryData[count], &SubLCDHistoryData[i], sizeof(SubLCDHistoryNode));
        }

        --NodeIndex;
        memset(&SubLCDHistoryData[NodeIndex + 1], 0, sizeof(SubLCDHistoryNode));
    }
#endif /* __MMI_SUBLCD__ */ 
    return Status;
}


/*****************************************************************************
 * FUNCTION
 *  DeleteNSubLCDHistory
 * DESCRIPTION
 *  Deletes 'n' history nodes from current Sub LCDhistory index
 *  
 *  This shall pop 'n' history nodes without invoking
 *  entry functions of the deleted nodes
 * PARAMETERS
 *  DeleteCount     [IN]        
 *  n(?)            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteNSubLCDHistory(U16 DeleteCount)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 Count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return ;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_DEL_SUBLCD_SCR_NUM, DeleteCount);

    if (NodeIndex >= DeleteCount)
    {
        /* To make sure the callback will run at topist screen */
        ExecTopScrnCallbackHandler_ex(0);

        for (Count = DeleteCount; Count >= 1; --Count)
        {
            /* JL, if want to stop to run next decrement will return true. */
            if (ExecHistoryScrnCallBackHandle_ex(NodeIndex, 0) == MMI_HIST_STOP_DELETING)
            {
                break;
            }
            DecrementSubLCD();
        }
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  DeleteBeyondSubLCDScrTillScr
 * DESCRIPTION
 *  To delete scrns beyond scrn A
 *  till scrn B
 * PARAMETERS
 *  beyondScrnid        [IN]        
 *  tillScrnid          [IN]        
 *  scrnid1(?)          [IN]        
 *  scrnid2(?)          [IN]        
 * RETURNS
 *  U16 - status
 *****************************************************************************/
U8 DeleteBeyondSubLCDScrTillScr(U16 beyondScrnid, U16 tillScrnid)
{
    U8 Status = ST_SUCCESS;

#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = 0, count1 = 0;
    S16 endScreenPresent = -1, startScreenPresent = -1;
    U16 screensDeleted = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return ST_SUCCESS;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_DEL_BEYOND_TILL_SUBLCD_SCR_HDLR, beyondScrnid, tillScrnid);

    if (!IsSubLCDScreenPresent(beyondScrnid) || !IsSubLCDScreenPresent(tillScrnid))
    {
        return ST_FAILURE;
    }

    if (NodeIndex > 0)
    {
        count = NodeIndex;
        count1 = NodeIndex;
    }

    while (count)
    {
        if (SubLCDHistoryData[count].scrnID == beyondScrnid)
        {
            startScreenPresent = count;
        }
        if (SubLCDHistoryData[count].scrnID == tillScrnid)
        {
            MMI_ASSERT(startScreenPresent != -1);
            endScreenPresent = count;
            break;
        }
        --count;
    }
    MMI_ASSERT((startScreenPresent != -1) && (endScreenPresent != -1));

    for (count = startScreenPresent - 1; count >= endScreenPresent; count--)
    {
        if (ExecHistoryScrnCallBackHandle_ex(count, 0) == MMI_HIST_STOP_DELETING)
        {
            /*
             * The screen won't want to delete. 
             * We stop continue to delete the screens.
             */
            endScreenPresent = count + 1;
            Status = ST_FAILURE;
            break;
        }
        if (SubLCDHistoryData[count].guiBuffer)
        {
            OslMfree(SubLCDHistoryData[count].guiBuffer);
        }
        memset(&SubLCDHistoryData[count], 0, sizeof(SubLCDHistoryNode));
        NodeIndex--;
        screensDeleted++;
    }

    memcpy(
        SubLCDHistoryData + endScreenPresent,
        SubLCDHistoryData + startScreenPresent,
        sizeof(SubLCDHistoryNode) * (count1 - startScreenPresent + 1));
    memset(SubLCDHistoryData + (NodeIndex + 1), 0, (sizeof(SubLCDHistoryNode) * screensDeleted));
#endif /* __MMI_SUBLCD__ */ 
    return Status;
}


/*****************************************************************************
 * FUNCTION
 *  DeleteBetweenSubLCDScreen
 * DESCRIPTION
 *  Deletes Between two Screens including the boundaries
 * PARAMETERS
 *  StartScrId      [IN]        
 *  EndScrId        [IN]        
 * RETURNS
 *  U16 - status
 *****************************************************************************/
U16 DeleteBetweenSubLCDScreen(U16 StartScrId, U16 EndScrId)
{
    U8 Status = ST_SUCCESS;

#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = 0, count1 = 0;
    S16 endScreenPresent = -1, startScreenPresent = -1;
    U16 screensDeleted = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (redraw_in_small_screen_proceduer())
    {
        return ST_SUCCESS;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_DEL_BETWEEN_SUBLCD_SCR_HDLR, StartScrId, EndScrId);

    if (!IsSubLCDScreenPresent(StartScrId) || !IsSubLCDScreenPresent(EndScrId))
    {
        return ST_FAILURE;
    }

    if (NodeIndex > 0)
    {
        count = NodeIndex;
        count1 = NodeIndex;
    }

    while (count >= 0)
    {
        if (SubLCDHistoryData[count].scrnID == EndScrId)
        {
            startScreenPresent = count;
        }
        if (SubLCDHistoryData[count].scrnID == StartScrId)
        {
            endScreenPresent = count;
            break;
        }
        --count;
    }
    MMI_ASSERT((startScreenPresent != -1) && (endScreenPresent != -1));
    for (count = startScreenPresent; count >= endScreenPresent; count--)
    {
        if (ExecHistoryScrnCallBackHandle_ex(count, 0) == MMI_HIST_STOP_DELETING)
        {
            /*
             * The screen won't want to delete. 
             * We stop continue to delete the screens.
             */
            endScreenPresent = count + 1;
            Status = ST_FAILURE;
            break;
        }
        if (SubLCDHistoryData[count].guiBuffer)
        {
            OslMfree(SubLCDHistoryData[count].guiBuffer);
        }
        memset(&SubLCDHistoryData[count], 0, sizeof(SubLCDHistoryNode));
        NodeIndex--;
        screensDeleted++;
    }

    memcpy(
        SubLCDHistoryData + endScreenPresent,
        SubLCDHistoryData + startScreenPresent + 1,
        sizeof(SubLCDHistoryNode) * (count1 - startScreenPresent + 1));
    memset(SubLCDHistoryData + (NodeIndex + 1), 0, (sizeof(SubLCDHistoryNode) * screensDeleted));

#endif /* __MMI_SUBLCD__ */ 
    return Status;
}


/*****************************************************************************
 * FUNCTION
 *  SubLCDHistoryReplace
 * DESCRIPTION
 *  To replace a specific history
 *  
 *  HistoryReplace will be used for a exist history
 * PARAMETERS
 *  out_scrn_id     [IN]        
 *  in_scrn_id      [IN]        
 *  in_src_func     [IN]        
 * RETURNS
 *  pBool
 *****************************************************************************/
pBOOL SubLCDHistoryReplace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func)
{
#ifdef __MMI_SUBLCD__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_REPLACE_SUBLCD_SCR_HDLR, out_scrn_id, in_scrn_id, in_src_func);

    for (count = 0; ((count < MAX_SUBLCD_HISTORY) && ((count <= NodeIndex) && (NodeIndex != -1))); count++)
    {
        /* Find the matched source history and then to write into destinate history */
        if (SubLCDHistoryData[count].scrnID == out_scrn_id)
        {
            ClearDelScrnIDCallbackHandler(out_scrn_id, NULL);
            SubLCDHistoryData[count].scrnID = in_scrn_id;
            SubLCDHistoryData[count].entryFuncPtr = in_src_func;
            if (SubLCDHistoryData[count].guiBuffer)
            {
                OslMfree(SubLCDHistoryData[count].guiBuffer);
            }
            SubLCDHistoryData[count].guiBuffer = NULL;
            SubLCDHistoryData[count].guiLen = 0;
            return MMI_TRUE;
        }
    }
#endif /* __MMI_SUBLCD__ */ 
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  IsSubLCDHistoryBack
 * DESCRIPTION
 *  Queries SubLCD history is back now or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL IsSubLCDHistoryBack(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IsBackSubLCDHistory;
#endif /* __MMI_SUBLCD__ */ 

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  IsSubLCDScreenPresent
 * DESCRIPTION
 *  Queries history for presence of a screen Id in sub-LCD history
 * PARAMETERS
 *  scrnId          [IN]        
 *  scrnid(?)       [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL IsSubLCDScreenPresent(U16 scrnId)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; ((count < MAX_SUBLCD_HISTORY) && ((count <= NodeIndex) && (NodeIndex != -1))); count++)
    {
        if (SubLCDHistoryData[count].scrnID == scrnId)
        {
            return TRUE;
        }
    }
#endif /* __MMI_SUBLCD__ */ 

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrSubLCDScreenExitFunc
 * DESCRIPTION
 *  Queries present screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
FuncPtr GetCurrSubLCDScreenExitFunc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    return gCurrExitSubLCDFn;
#endif 
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrSubLCDScreenEntryFunc
 * DESCRIPTION
 *  Queries current screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
FuncPtr GetCurrSubLCDScreenEntryFunc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    return gCurrEntrySubLCDFn;
#endif 
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetSubLCDScreenCountInHistory
 * DESCRIPTION
 *  Get the screen numbers in subLCD history
 * PARAMETERS
 *  void
 * RETURNS
 *  S16 - screen count
 *****************************************************************************/
S16 GetSubLCDScreenCountInHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    return (S16)(NodeIndex + 1);
#endif 
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetSubLCDHistory
 * DESCRIPTION
 *  Used to get sub LCD history buffer for a screen id
 * PARAMETERS
 *  scrnId          [IN]        
 *  ptrHistory      [?]         
 *  scrnID(?)       [IN]        History *ptrHistory
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
U8 GetSubLCDHistory(U16 scrnId, SubLCDHistoryNodeEx *ptrHistory)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; ((count < MAX_SUBLCD_HISTORY) && ((count <= NodeIndex) && (NodeIndex != -1))); count++)
    {
        if (SubLCDHistoryData[count].scrnID == scrnId)
        {
            ptrHistory->scrnID = SubLCDHistoryData[count].scrnID;
            ptrHistory->entryFuncPtr = SubLCDHistoryData[count].entryFuncPtr;
            if (SubLCDHistoryData[count].guiLen)
            {
                memcpy(ptrHistory->guiBuffer, SubLCDHistoryData[count].guiBuffer, MAX_GUI_BUFFER);
            }
            else
            {
                memset(ptrHistory->guiBuffer, 0, MAX_GUI_BUFFER);
            }

            return TRUE;
        }
    }
#endif /* __MMI_SUBLCD__ */ 
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrSubLCDGuiBuffer
 * DESCRIPTION
 *  gets current Sub LCD screen gui buffer
 * PARAMETERS
 *  scrnId          [IN]        
 *  scrnid(?)       [IN]        
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
U8 *GetCurrSubLCDGuiBuffer(U16 scrnId)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; ((count < MAX_SUBLCD_HISTORY) && ((count <= NodeIndex) && (NodeIndex != -1))); count++)
    {
        if (SubLCDHistoryData[count].scrnID == scrnId)
        {
            return SubLCDHistoryData[count].guiBuffer;
        }
    }
#endif /* __MMI_SUBLCD__ */ 
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetPreviousSubLCDScrnIdOf
 * DESCRIPTION
 *  Queries previous scrn id of this Id
 * PARAMETERS
 *  scrnId              [IN]        
 *  previousScrnId      [?]         
 *  scrnid(?)           [IN]        
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
pBOOL GetPreviousSubLCDScrnIdOf(U16 scrnId, U16 *previousScrnId)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; ((count < MAX_SUBLCD_HISTORY) && ((count <= NodeIndex) && (NodeIndex != -1))); count++)
    {
        if (SubLCDHistoryData[count].scrnID == scrnId)
        {
            if ((count - 1) >= 0)
            {
                *previousScrnId = SubLCDHistoryData[count - 1].scrnID;
                return MMI_TRUE;
            }
            return MMI_FALSE;
        }
    }
#endif /* __MMI_SUBLCD__ */ 
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  GetNextSubLCDScrnIdOf
 * DESCRIPTION
 *  Queries next scrn id of this Id
 * PARAMETERS
 *  scrnId          [IN]        
 *  nextScrnId      [?]         
 *  scrnid(?)       [IN]        
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
pBOOL GetNextSubLCDScrnIdOf(U16 scrnId, U16 *nextScrnId)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; ((count < MAX_SUBLCD_HISTORY) && ((count <= NodeIndex) && (NodeIndex != -1))); count++)
    {
        if (SubLCDHistoryData[count].scrnID == scrnId)
        {
            if ((count + 1) <= NodeIndex)
            {
                *nextScrnId = SubLCDHistoryData[count + 1].scrnID;
                return MMI_TRUE;
            }
            return MMI_FALSE;
        }
    }
#endif /* __MMI_SUBLCD__ */ 
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  GetSubLCActiveScreenId
 * DESCRIPTION
 *  Get current screen id of Sub LCD
 *  
 *  This is used to clear all the interrupt event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetSubLCActiveScreenId(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCurrTopSubLCDScrnID;
#endif /* __MMI_SUBLCD__ */ 
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetSubLCDExitScrnId
 * DESCRIPTION
 *  Gets current exit screen id of Sub LCD
 * PARAMETERS
 *  void
 *  U16(?)      [IN]        Scrnid
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
U16 GetSubLCDExitScrnId(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCurrExitSubLCDScrnID;
#endif /* __MMI_SUBLCD__ */ 
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetSubLCDScrnId
 * DESCRIPTION
 *  Gets the id of Sub LCD screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
U16 GetSubLCDScrnId(U16 index)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index <= NodeIndex)
    {
        return (SubLCDHistoryData[index].scrnID);
    }
#endif /* __MMI_SUBLCD__ */ 
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SubLCDHistoryDump
 * DESCRIPTION
 *  Dumps the Sub-LCD history to file or debug window
 *  
 *  SubLCDHistoryDump will be used for dbugging purposes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDHistoryDump(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NodeIndex >= 0)
    {
        count = NodeIndex;

        do
        {
            MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_DUMP_HDLR,
                       count, SubLCDHistoryData[count].scrnID, SubLCDHistoryData[count].entryFuncPtr);

            if (count > 0 && count < MAX_SUBLCD_HISTORY)
            {
                --count;
            }
            else
            {
                break;
            }

        } while ((count != NodeIndex) && (SubLCDHistoryData[count].entryFuncPtr != NULL));
    }

    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_SUBHIST_DUMP_ROOTHDLR);

#endif /* __MMI_SUBLCD__ */ 
}


#ifdef __MMI_SUBLCD_MASTER_MODE__
/*****************************************************************************
 * FUNCTION
 *  SwitchSubLCDHistory
 * DESCRIPTION
 *  Switch SubLCD History(master mode to slave mode or slave mode to master mode)
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SwitchSubLCDHistory(void)
{
    if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M)
    {
        MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_SUBHIST_SWITCH_MODE_S2M);

        IsBackSubLCDHistory_slave = IsBackSubLCDHistory;
        NodeIndex_slave = NodeIndex;
        gCurrTopSubLCDScrnID_slave = gCurrTopSubLCDScrnID;
        gCurrExitSubLCDScrnID_slave = gCurrExitSubLCDScrnID;
        gCurrExitSubLCDFn_slave = gCurrExitSubLCDFn;
        gCurrEntrySubLCDFn_slave = gCurrEntrySubLCDFn;

        SubLCDHistoryData = SubLCDHistoryData_master;
        IsBackSubLCDHistory = IsBackSubLCDHistory_master;
        NodeIndex = NodeIndex_master;
        gCurrTopSubLCDScrnID = 0;
        gCurrExitSubLCDScrnID = 0;
        gCurrExitSubLCDFn = NULL;
        gCurrEntrySubLCDFn = NULL;
        ExecuteRootSubLcdHistoryScreenPtr = (SubLcdHistoryCBPtr)ExecuteRootSubLcdHistoryScreenPtr_master;
    }
    else if (g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
    {
        MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_SUBHIST_SWITCH_MODE_M2S);

        IsBackSubLCDHistory_master = IsBackSubLCDHistory;
        NodeIndex_master = NodeIndex;
        gCurrTopSubLCDScrnID_master = gCurrTopSubLCDScrnID;
        gCurrExitSubLCDScrnID_master = gCurrExitSubLCDScrnID;
        gCurrExitSubLCDFn_master = gCurrExitSubLCDFn;
        gCurrEntrySubLCDFn_master = gCurrEntrySubLCDFn;
        
        SubLCDHistoryData = SubLCDHistoryData_slave;
        IsBackSubLCDHistory = IsBackSubLCDHistory_slave;
        NodeIndex = NodeIndex_slave;
        gCurrTopSubLCDScrnID = 0;
        gCurrExitSubLCDScrnID = 0;
        gCurrExitSubLCDFn = NULL;
        gCurrEntrySubLCDFn = NULL;
        ExecuteRootSubLcdHistoryScreenPtr = (SubLcdHistoryCBPtr)ExecuteRootSubLcdHistoryScreenPtr_slave;
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ClearSubLCDMasterHistory
 * DESCRIPTION
 *  Clear SubLCD History Data
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void ClearSubLCDMasterHistory(void)
{
    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_SUBHIST_CLEAR_MASTER_HIST);

    IsBackSubLCDHistory_master = FALSE;
    NodeIndex_master = -1;
    gCurrTopSubLCDScrnID_master = 0;
    gCurrExitSubLCDScrnID_master = 0;
    gCurrExitSubLCDFn_master = NULL;
    gCurrEntrySubLCDFn_master = NULL;
    ExecuteRootSubLcdHistoryScreenPtr_master = SUBLCD_MASTER_MODE_ROOT_SCREEN_ENTRY_FUNC;
}


/*****************************************************************************
 * FUNCTION
 *  IsSubLCDMasterHistoryEmpty
 * DESCRIPTION
 *  Is SubLCD Master History Empty
 * PARAMETERS
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
BOOL IsSubLCDMasterHistoryEmpty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (NodeIndex_master == -1);
}


/*****************************************************************************
 * FUNCTION
 *  GetScreenCountInSubLCDMasterModeHistory
 * DESCRIPTION
 *  Get the screen numbers in subLCD master mode history
 * PARAMETERS
 *  void
 * RETURNS
 *  S16 - screen count
 *****************************************************************************/
S16 GetScreenCountInSubLCDMasterModeHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return NodeIndex_master;
}


/*****************************************************************************
 * FUNCTION
 *  ForceExitCurrScr
 * DESCRIPTION
 *  Force Exit Current Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void ForceExitCurrScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_SUBHIST_FORCE_EXIT_CURR_SCR);

    ClearDelScrnIDCallbackHandler(GetSubLCDExitScrnId(), NULL);
    if (gCurrExitSubLCDFn != NULL)
    {
        gCurrExitSubLCDFn();
    }

    if (gCurrEntrySubLCDFn != NULL && g_sublcd_master_cntx.is_sublcd_force_add_history == TRUE)
    {
        SubLCDHistoryData[++NodeIndex].entryFuncPtr = gCurrEntrySubLCDFn;
        SubLCDHistoryData[NodeIndex].scrnID = gCurrTopSubLCDScrnID;
        SubLCDHistoryData[NodeIndex].guiLen = 0;
        SubLCDHistoryData[NodeIndex].guiBuffer = NULL;
    }
    g_sublcd_master_cntx.is_sublcd_force_add_history = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SubLCDMasterGoBackHistory
 * DESCRIPTION
 *  SubLCD Master Go Back History
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDMasterGoBackHistory(void)
{
	if (IsClamClose())
	{
        MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_SUBHIST_MASTER_GOBACK_HIST);

		if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M ||
			g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
		{
			if (NodeIndex >= 0)
			{
                GoBackSubLCDHistoryInt();
			}
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrSubLCDUpdateBySubLCDApp
 * DESCRIPTION
 *  Set current subLCD is updated by mainLCD application or subLCD application
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrSubLCDUpdateBySubLCDApp(MMI_BOOL enable)
{
    if (enable == MMI_TRUE)
    {
        gCurrSubLCDUpdateBy = SUBLCD_UPDATE_BY_SUB_LCD_APP;
    }
    else
    {
        gCurrSubLCDUpdateBy = SUBLCD_UPDATE_BY_MAIN_LCD_APP;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrSubLCDUpdateBySubLCDApp
 * DESCRIPTION
 *  Set current subLCD is updated by mainLCD application or subLCD application
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL GetCurrSubLCDUpdateBySubLCDApp(void)
{
    if (gCurrSubLCDUpdateBy == SUBLCD_UPDATE_BY_SUB_LCD_APP)
    {
        return MMI_TRUE;
    }
    else if (gCurrSubLCDUpdateBy == SUBLCD_UPDATE_BY_MAIN_LCD_APP)
    {
        return MMI_FALSE;
    }
    else
    {
        MMI_ASSERT(gCurrSubLCDUpdateBy != SUBLCD_UPDATE_BY_MAIN_LCD_APP && 
                   gCurrSubLCDUpdateBy != SUBLCD_UPDATE_BY_SUB_LCD_APP);
        return MMI_FALSE;
    }
}


#endif/*__MMI_SUBLCD_MASTER_MODE__*/


