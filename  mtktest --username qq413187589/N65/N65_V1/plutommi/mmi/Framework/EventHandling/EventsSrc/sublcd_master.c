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
 *  sublcd_master.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/***************** Ebook Application implementation *********************/

/**************************************************************

   FILENAME : sublcd_master.c

   PURPOSE     : Framework For SubLCD Master Mode

   REMARKS     : nil

   AUTHOR      : Fugui

   DATE     : 2006-09-10

**************************************************************/

#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr.h"
#include "MMIDataType.h"
#include "MMI_trc.h"
#include "Unicodexdcl.h"
#include "GlobalDefs.h"
#include "Globalmenuitems.h"
#include "FrameworkGprot.h"        
#include "FrameworkProt.h"  
#include "gui_data_types.h"
#include "gui.h"
#include "mdi_datatype.h"
#include "DebugInitDef.h"
#include "gdi_include.h"
#include "wgui_categories.h"
#include "IdleAppProt.h"
#include "IdleAppDef.h"
#include "CallManagementGprot.h"
#include "AlarmFrameWorkProt.h"
#include "Mainmenudef.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerDef.h"
#include "FMRadioProt.h"
#include "FMRadioDef.h"
#include "SimDetectionGexdcl.h" /* g_pwr_context */
#include "SimDetectionGprot.h"
#include "SettingProfile.h"

#ifdef __MMI_SUBLCD_MASTER_MODE__


/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef U8 (*FuncPtrRtn) (void);

typedef struct _sublcd_master_app_info
{
    FuncPtrRtn is_playing_f; /* callback to check if there is any pending event in idle screen */
    FuncPtrRtn entry_sublcd_master_main_f;    /* callback to execute the corresponding function in idle screen  */
} IDLECALLBACKINFO;


/***************************************************************************** 
* Global Variable / Function
*****************************************************************************/
extern BOOL IsClamClose(void);

#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
extern BOOL mmi_sub_audply_entry_main_key_handler(void);
#endif /* __MMI_AUDIO_PLAYER_ON_SUBLCD__ */ 
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
extern BOOL mmi_fmrdo_is_power_on(void);
extern BOOL mmi_fmrdo_sub_entry_main_key_handler(void);
#endif /* __MMI_FM_RADIO_ON_SUBLCD__ */ 


SubLCD_master_cntx_Struct    g_sublcd_master_cntx;
MMI_BOOL is_clam_opening = MMI_FALSE;
FuncPtr OldSubLCDScreenEntryFunc = NULL;

/* new gdi buffer for Sub-AP and Sub-FM using */
#define EXTRA_GDI_BUFFER_SIZE 12288
S32 new_gdi_buffer[EXTRA_GDI_BUFFER_SIZE/4];


/***************************************************************************** 
* Local Variable
*****************************************************************************/
U8 DenyInSubLCDMasterMode(void);
MMI_BOOL FakeEntrySubLCDFunc(void);

U8 AllowInSubLCDMainMenu(void);
MMI_BOOL PrepareEnterSubLCDMainMenu(void);


static const IDLECALLBACKINFO sublcd_master_apps[] = 
{
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
    {mmi_audply_is_playing,  (FuncPtrRtn)mmi_sub_audply_entry_main_key_handler},
#endif /* __MMI_AUDIO_PLAYER_ON_SUBLCD__ */ 
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
    {mmi_fmrdo_is_power_on,  (FuncPtrRtn) mmi_fmrdo_sub_entry_main_from_idle},
#endif /* __MMI_FM_RADIO_ON_SUBLCD__ */ 
    {DenyInSubLCDMasterMode, (FuncPtrRtn)FakeEntrySubLCDFunc    },
    {NULL, NULL}                         
};


static FuncPtr SubLCD_master_long_press_func = NULL;
static MMI_BOOL	is_long_press_present = MMI_FALSE;
static MMI_BOOL entry_master_mode_from_clam_closed = MMI_FALSE;



/*****************************************************************************
 * FUNCTION
 *  DenyInSubLCDMasterMode
 * DESCRIPTION
 *  Check if deny enter subLCD master mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 DenyInSubLCDMasterMode(void)
{
    if (entry_master_mode_from_clam_closed)
    {
        /* Clam is closed but don't enter subLCD master mode automatically */
        return (U8) MMI_TRUE;
    }
    
    return (U8) MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  FakeEntrySubLCDFunc
 * DESCRIPTION
 *  The fake function to returns MMI_TRUE and let the caller of 
 *  EntrySubLCDMasterFromIdle() doesn't show it screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL FakeEntrySubLCDFunc(void)
{
    /* Have to return MMI_TRUE to let caller of EntrySubLCDMasterFromIdle() doesn't show it screen. */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLCDMasterFromIdle
 * DESCRIPTION
 *  Entry SubLCD Master Mode From Sub Idle 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL EntrySubLCDMasterFromIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsClamClose() || is_clam_opening || g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
    {
        /*
         * We don't allow entry subLCD master mode from subLCD idle screen in below situations.
         * 1. Clam is open
         * 2. g_sublcd_master_cntx.state is SUBLCD_MODE_M2S
         *     If SubLCD in master_to_slave mode, we don't entry subLCD master mode again.
         */
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ENTRY_SUBLCDMASTER_FROM_IDLE);

     
    if (!IsSubLCDMasterHistoryEmpty() || IsSubLCDHistoryBack())
    {
        /*
         * (1) subLCD is in master mode and history isn't empty or
         * (2) in goback subLCD history process,
         * we freeze subLCD screen to avoid the screen context when interrupt occurs.
         *
         * In goback subLCD history process
         *     Because executing GoBackSubLCDHistory() in slave mode may enter subLCD idle screen 
         *     to trigger entry SubLCD master mode more than one time,
         *     it will cause the switch master/slave mode mechanism failed.
         */
        UI_set_sub_LCD_graphics_context();
        gdi_lcd_freeze(TRUE);
        UI_set_main_LCD_graphics_context();
        return MMI_FALSE;
    }
   
    for (i = 0; sublcd_master_apps[i].is_playing_f != NULL; i++)
    {
        if ((*sublcd_master_apps[i].is_playing_f) ())
        {
            if (sublcd_master_apps[i].entry_sublcd_master_main_f != NULL)
            {
				if (sublcd_master_apps[i].entry_sublcd_master_main_f)
				{
				    return (MMI_BOOL)sublcd_master_apps[i].entry_sublcd_master_main_f();
				}
				else
				{
				    return MMI_FALSE;
				}
            }
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  SubLCDMasterLongPressKeyUpHdlr
 * DESCRIPTION
 *  tmp function for SetSubLCDMasterLongPressHandler
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDMasterLongPressKeyUpHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (is_long_press_present && SubLCD_master_long_press_func)
	{
		SubLCD_master_long_press_func();
	}
	is_long_press_present = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  SubLCDMasterLongPressHdlr
 * DESCRIPTION
 *  tmp function for SetSubLCDMasterLongPressHandler
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDMasterLongPressHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	is_long_press_present = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SetSubLCDMasterLongPressHandler
 * DESCRIPTION
 *  New register long press key handler function (Executed until key up)
 * PARAMETERS
 *  funcPtr              [IN]        
 *  keyCode              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetSubLCDMasterLongPressHandler(FuncPtr funcPtr, U16 keyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SubLCD_master_long_press_func = funcPtr;
    SetKeyHandler( SubLCDMasterLongPressKeyUpHdlr, keyCode, KEY_EVENT_UP);
    SetKeyHandler( SubLCDMasterLongPressHdlr, keyCode, KEY_EVENT_LONG_PRESS);
}


/*****************************************************************************
 * FUNCTION
 *  ForceEntrySubLCDMaster
 * DESCRIPTION
 *  Force Entry SubLCD Master mode
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void ForceEntrySubLCDMaster(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_FORCE_ENTRY_SUBLCD_MASTER);
    g_sublcd_master_cntx.is_sublcd_force_add_history = FALSE;
	SetSubLCDInMasterMode();
	g_sublcd_master_cntx.state = SUBLCD_MODE_MASTER;
	UI_set_sub_LCD_graphics_context();
	gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    UI_set_main_LCD_graphics_context();
}


/*****************************************************************************
 * FUNCTION
 *  ForceEntrySubLCDSlave
 * DESCRIPTION
 *  Force Entry SubLCD Slave mode
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void ForceEntrySubLCDSlave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_FORCE_ENTRY_SUBLCD_SLAVE);
	SetSubLCDInSlaveMode();
	UI_set_sub_LCD_graphics_context();
	gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    UI_set_main_LCD_graphics_context();
}


/*****************************************************************************
 * FUNCTION
 *  SubLCDMasterKeyHandler
 * DESCRIPTION
 *  default key handler for sublcd master mode
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDMasterKeyHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsClamClose())
    {
        /* If the clam is opened, we do nothing. */
        return;
    }
    if (isInCall() || mmi_alm_is_in_alarm()||!mmi_bootup_is_searching_or_idle_reached())
	{
		return;
	}
    if (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD || g_pwr_context.PowerOnMode == POWER_ON_EXCEPTION)
    {
	
        /*
         * There are screen in subLCD master mode.
         * call ForceEntrySubLCDMaster() directly.
         */
	ForceEntrySubLCDMaster();
     }
}


/*****************************************************************************
 * FUNCTION
 *  SetSubLCDMasterKeyHandler
 * DESCRIPTION
 *  Set default key handler for sublcd master mode
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SetSubLCDMasterKeyHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler( (FuncPtr)SubLCDMasterKeyHandler, KEY_PLAY_STOP, KEY_EVENT_LONG_PRESS);
    
}


/*****************************************************************************
 * FUNCTION
 *  ExitMainLCDDummyScreenTimeOut
 * DESCRIPTION
 *  ExitMainLCDDummyScreenTimeOut
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void ExitMainLCDDummyScreenTimeOut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_EXIT_MAINLCD_DUMMY_SCRN_TIMEOUT);
    UI_set_sub_LCD_graphics_context();
    gdi_lcd_freeze(FALSE);   
    UI_set_main_LCD_graphics_context();
	if (g_sublcd_master_cntx.state == SUBLCD_MODE_SLAVE &&
		GetCurrSubLCDScreenEntryFunc() == OldSubLCDScreenEntryFunc)
	{
        ForceEntrySubLCDMaster();
	}
	else
	{
	    UI_set_sub_LCD_graphics_context();
		gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
	    UI_set_main_LCD_graphics_context();
	}
    
	OldSubLCDScreenEntryFunc = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  ExitMainLCDDummyScreen
 * DESCRIPTION
 *  Exit MainLCD Dummy Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void ExitMainLCDDummyScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsClamClose() )
    {
        return;
    }
    if ( g_sublcd_master_cntx.state == SUBLCD_MODE_MASTER)
    {
		SetSubLCDInSlaveMode();
        OldSubLCDScreenEntryFunc = GetCurrSubLCDScreenEntryFunc();
        /* We assume the current subLCD screen is updated by subLCD application */
        SetCurrSubLCDUpdateBySubLCDApp(MMI_TRUE);
        UI_set_sub_LCD_graphics_context();
        gdi_lcd_freeze(TRUE);
        UI_set_main_LCD_graphics_context();
        gui_start_timer(100, ExitMainLCDDummyScreenTimeOut);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryMainLCDDummyScreen
 * DESCRIPTION
 *  Entry MainLCD Dummy Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainLCDDummyScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ENTRY_MAINLCD_DUMMY_SCRN);
    
    if (!IsClamClose() )
    {
        return;
    }
    if ( g_sublcd_master_cntx.state == SUBLCD_MODE_SLAVE)
    {
        ForceEntrySubLCDMaster();
    }
    else if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M)
    {
        if (IsScreenPresent(IDLE_SCREEN_ID_DUMMY))
        {
            ClearDelScrnIDCallbackHandler(IDLE_SCREEN_ID_DUMMY,NULL);
            DeleteScreenIfPresent(IDLE_SCREEN_ID_DUMMY);
        }
        UI_set_main_LCD_graphics_context();
        EntryNewScreen(IDLE_SCREEN_ID_DUMMY, ExitMainLCDDummyScreen, EntryMainLCDDummyScreen, NULL);
		ShowCategory9Screen(STR_IDLE_DUMMY_SCREEN, IMG_GLOBAL_PROGRESS, NULL);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetSubLCDInMasterMode
 * DESCRIPTION
 *  Entry SubLCD Master Mode
 * PARAMETERS
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MMI_BOOL SetSubLCDInMasterMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SET_SUBLCD_IN_MASTER_MODE);
    
    if (!IsClamClose() ||
		g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
    {
        return MMI_FALSE;
    }
    if ( g_sublcd_master_cntx.state == SUBLCD_MODE_MASTER )
    {
		g_sublcd_master_cntx.state = SUBLCD_MODE_S2M;
        return MMI_TRUE;
    }
    if ( g_sublcd_master_cntx.state == SUBLCD_MODE_S2M)
    {
        return MMI_TRUE;
    }

    g_sublcd_master_cntx.state = SUBLCD_MODE_S2M;

    EntryMainLCDDummyScreen();
    
    UI_set_sub_LCD_graphics_context();
    gdi_lcd_freeze(TRUE);
    UI_set_main_LCD_graphics_context();
    ForceExitCurrScr();
    SwitchSubLCDHistory();  
    SwitchKeyFuncPtrs();
    ClearAllKeyHandler();
    GoBackSubLCDHistoryInt();
    UI_set_sub_LCD_graphics_context();
    gdi_lcd_freeze(FALSE);   
    UI_set_main_LCD_graphics_context();
   
    if ( g_sublcd_master_cntx.state != SUBLCD_MODE_S2M)
    {
        g_sublcd_master_cntx.state = SUBLCD_MODE_S2M;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SetSubLCDInSlaveMode
 * DESCRIPTION
 *  Exit SubLCD Master Mode
 * PARAMETERS
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MMI_BOOL SetSubLCDInSlaveMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SET_SUBLCD_IN_SLAVE_MODE);
    if (!IsClamClose() ||
		g_sublcd_master_cntx.state == SUBLCD_MODE_S2M)
    {
        return MMI_FALSE;
    }
    if ( g_sublcd_master_cntx.state == SUBLCD_MODE_SLAVE ||
		g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
    {
        return MMI_TRUE;
    }

    g_sublcd_master_cntx.state = SUBLCD_MODE_M2S;
    UI_set_sub_LCD_graphics_context();
    gdi_lcd_freeze(TRUE);
    UI_set_main_LCD_graphics_context();
    ForceExitCurrScr();
    SwitchSubLCDHistory();    
    SwitchKeyFuncPtrs();
    ClearAllKeyHandler();
    GoBackSubLCDHistoryInt();
    UI_set_sub_LCD_graphics_context();
    gdi_lcd_freeze(FALSE);    
    UI_set_main_LCD_graphics_context();
	g_sublcd_master_cntx.state = SUBLCD_MODE_SLAVE;

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  IsSubLCDInMasterMode
 * DESCRIPTION
 *  Check if in Master mode
 * PARAMETERS
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MMI_BOOL IsSubLCDInMasterMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_sublcd_master_cntx.state == SUBLCD_MODE_MASTER);
}


/*****************************************************************************
 * FUNCTION
 *  SubLCDMasterModeClamOpen
 * DESCRIPTION
 *  Callback for Clam Open
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDMasterModeClamOpen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_MASTER_MODE_CLAM_OPEN);
    if (mmi_bootup_is_searching_or_idle_reached())
    {
        is_clam_opening = TRUE;
        ExecSubLCDCurrExitHandler();
        DinitSubLCDHistory();
    
        ForceEntrySubLCDSlave();
        ClearSubLCDMasterHistory();
        if (GetActiveScreenId() == IDLE_SCREEN_ID_DUMMY)
        {
            GoBackHistory();
        }
        else
        {
            if (IsScreenPresent(IDLE_SCREEN_ID_DUMMY))
            {
                ClearDelScrnIDCallbackHandler(IDLE_SCREEN_ID_DUMMY,NULL);
                DeleteScreenIfPresent(IDLE_SCREEN_ID_DUMMY);
            }
        }
        is_clam_opening = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SubLCDMasterModeClamclosed
 * DESCRIPTION
 *  Callback for Clam closed
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDMasterModeClamclosed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_MASTER_MODE_CLAM_OPEN);
    if(mmi_bootup_is_searching_or_idle_reached() &&
       !IsSubLCDInMasterMode())
    {
        entry_master_mode_from_clam_closed = MMI_TRUE;
        SubLCDIdleScreen();
        entry_master_mode_from_clam_closed = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ChangeInterruptToneInMasterMode
 * DESCRIPTION
 *  Check if need to change the interrupt tone in master mode
 * PARAMETERS
 * RETURNS
 *  U8    tone id
 *****************************************************************************/
U8 ChangeInterruptToneInMasterMode(U8 in_tone)
{
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
#endif
    /* Because SMS/MMS will show popup at subLCD, we don't need to change the message tone */
    return in_tone;
}


/*****************************************************************************
 * FUNCTION
 *  UnFreezeSubLCD
 * DESCRIPTION
 *  This function is used for unfreezes the Sub LCD.
 *  When we entry subLCD master mode from sub idle, we may freeze subLCD screen
 *  to avoid the screen context abnormal update if interrupt occurs. Then we should
 *  call this fuction to unfreeze the Sub LCD after sub lcd freezed.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void UnFreezeSubLCD(void)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_set_sub_LCD_graphics_context();
    if (gdi_lcd_get_freeze())
    {
    gdi_lcd_freeze(FALSE);    
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
    UI_set_main_LCD_graphics_context();    
}


#endif/*__MMI_SUBLCD_MASTER_MODE__*/


