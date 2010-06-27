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
 * CustCoordinates.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define control sets and coordinate sets.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"
#ifdef __MMI_DRAW_MANAGER__
#include "kal_non_specific_general_types.h"
#include "CustDataRes.h"
#include "Gui_Setting.h"
#include "wgui.h"
#include "CallManagementIdDef.h"
#include "ToDoListEnum.h"
#include "CallhistoryEnum.h"
#include "wgui_categories_calendar.h"
#include "wgui_categories_list.h"//051507 channel list
#include "wgui_categories_popup.h"
#include "wgui_categories_multimedia.h"
#include "wgui_categories_CM.h"
#include "ComposeRingToneDefs.h"
#include "MessagesresourceData.h"
#include "MessagesresourceData.h"
#include "PhoneBookDef.h"
#include "CallSetUpEnum.h"
#include "SettingDefs.h"
#include "CallSetUpEnum.h"
#include "wgui_virtual_keyboard.h"

#include "CommonScreens.h"
#include "QuickAccessMenuItem_def.h"
#include "SimDetectionDef.h"
#include "EngineerModeDef.h"
#include "FunAndGamesDefs.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "DataAccountResDef.h"
#include "AlarmDef.h"
#include "currencyconvertor.h"
#include "Calorie.h"
#include "HealthMenstural.h"
#include "Bmi.h"
#ifdef __MMI_DICTIONARY__
#include "DictionaryResDef.h"
#endif 
#include "ScreenSaverDefs.h"
#include "ScheduledPowerOnOff.h"
#include "NetworkSetupGProt.h"
#include "CalendarDef.h"
#include "FactoryModeDef.h"
#include "SoundRecorderDef.h"
#include "DebugInitDef.h"
#include "wgui_draw_manager.h"
#include "gui.h"
#include "wgui.h"
#include "PhoEdtResDef.h"
#ifdef __MMI_SCREEN_ROTATE__
#include "ScreenRotationGprot.h"
#if !defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_320X240__)
#error "Only 176x220 240x320 and  320x240 are supported"
#endif 
#endif /* __MMI_SCREEN_ROTATE__ */ 

/* Had to Create new define as the previous ones now use variable in wgui.h */
#define DM_MMI_POP_UP_DIALOG_WIDTH           (MAIN_LCD_DEVICE_WIDTH-40)
#define DM_MMI_POP_UP_DIALOG_HEIGHT       (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_TITLE_HEIGHT-MMI_TITLE_Y-20)
#define DM_MMI_POP_UP_DIALOG_X            ((MAIN_LCD_DEVICE_WIDTH>>1)-(DM_MMI_POP_UP_DIALOG_WIDTH>>1))
#define DM_MMI_POP_UP_DIALOG_Y            (MMI_TITLE_Y+(MMI_TITLE_HEIGHT+10))
#define DM_MMI_POP_UP_DIALOG_FULL_HEIGHT        DM_MMI_POP_UP_DIALOG_HEIGHT

#define DM_MMI_CONTENT_WIDTH_WITH_H_TAB            (MMI_CONTENT_WIDTH)
#define DM_MMI_CONTENT_HEIGHT_WITH_H_TAB           (MMI_CONTENT_HEIGHT + MMI_TITLE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT)
#define DM_MMI_CONTENT_X_WITH_H_TAB                (MMI_CONTENT_X)
#define DM_MMI_CONTENT_Y_WITH_H_TAB                (MMI_CONTENT_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT - MMI_TITLE_HEIGHT)

/***************************************************************************** 
* Global Variable
*****************************************************************************/
#define CONTROL_SET_START
#if defined ( __MMI_MAINLCD_176X220__) || defined ( __MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__)
const U8 dm_base_control_set[] = 
{
    3,
    DM_STATUS_BAR1,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set[] = 
{
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_TITLE_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* defined ( __MMI_MAINLCD_176X220__) || defined ( __MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) */ 
const U8 dm_base_control_set[] = 
{
    2,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set[] = 
{
    DM_DEFAULT_TITLE_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined ( __MMI_MAINLCD_176X220__) || defined ( __MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) */ 

#if defined(__MMI_SCREEN_ROTATE__)

/* DM_SCR_BG is mandatory for rotated screen */
const U8 dm_base_rotated_control_set[] = 
{
    /* Double layer in popup screen do not need SCR_BG now */
    2,//3,
    //DM_SCR_BG,
    DM_TITLE1,
    DM_BUTTON_BAR1
};

const S16 dm_base_rotated_coordinate_set[] = 
{
    DM_DEFAULT_TITLE_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_ROTATED_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

const U8 dm_base_control_set2[] = 
{
    2,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set2[] = 
{
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#if defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
#if defined(GUI_SUBMENU_SHOW_STATUS_ICON)
const U8 dm_base_control_set_submenu[] = 
{
    3,
    DM_STATUS_BAR1,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set_submenu[] = 
{
    DM_DEFAULT_STATUS_BAR_FLAG,
#if defined(GUI_SUBMENU_USE_THICK_TITLE)
    MMI_TITLE_X, MMI_TITLE_Y, MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT, DM_TITLE_SET_THICK,
#else /* defined(GUI_SUBMENU_USE_THICK_TITLE) */
    MMI_TITLE_X, MMI_TITLE_Y, MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_SUBMENU_USE_THICK_TITLE) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* defined(GUI_SUBMENU_SHOW_STATUS_ICON) */
const U8 dm_base_control_set_submenu[] = 
{
    2,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set_submenu[] = 
{
#if defined(GUI_SUBMENU_USE_THICK_TITLE)
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT, DM_TITLE_SET_THICK,
#else /* defined(GUI_SUBMENU_USE_THICK_TITLE) */
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_SUBMENU_USE_THICK_TITLE) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(GUI_SUBMENU_SHOW_STATUS_ICON) */
#endif /* defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */

#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
const U8 dm_base_control_set_common[] = 
{
    3,
    DM_STATUS_BAR1,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set_common[] = 
{
    DM_DEFAULT_STATUS_BAR_FLAG,
#if defined(GUI_COMMON_USE_THICK_TITLE)
    MMI_TITLE_X, MMI_TITLE_Y, MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT, DM_TITLE_SET_THICK,
#else /* defined(GUI_COMMON_USE_THICK_TITLE) */
    MMI_TITLE_X, MMI_TITLE_Y, MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_COMMON_USE_THICK_TITLE) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
const U8 dm_base_control_set_common[] = 
{
    2,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set_common[] = 
{
#if defined(GUI_COMMON_USE_THICK_TITLE)
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT, DM_TITLE_SET_THICK,
#else /* defined(GUI_COMMON_USE_THICK_TITLE) */
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_COMMON_USE_THICK_TITLE) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */

const U8 category_controlled_set[] = 
{
    1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 category_controlled_coordinate_set[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE
};

const U8 fixed_list_menu_category[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_LIST1
};

const U8 dynamic_list_menu_category[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_DYNAMIC_LIST1
};

const U8 asyncdynamic_list_menu_category[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_ASYNCDYNAMIC_LIST1
};

const S16 list_coordinate_set[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_SUBMENU_CONTENT_X, MMI_SUBMENU_CONTENT_Y, MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

const U8 category_control_category_normal[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const U8 category_control_category_normal_bg[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 common_coordinate_set[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

#if defined(__MMI_SCREEN_ROTATE__)      // TODO: revise
const S16 common_rotated_coordinate_set[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

const U8 base_control_set_with_list_and_category_control[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_LIST1
};
const S16 coordinate_set_base_control_set_with_list_and_category_control[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

const U8 category_control_category_status_icon[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 category_control_coordinate_set_status_icon[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category5[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set5[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_EDITOR_CONTENT_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};

const U8 category7[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set7[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_TITLE_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_NO_FLAGS
};

const U8 category9[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_IMAGE,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set9[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

/* START VIJAY PMT 20050930 */
#ifdef UI_SMALL_LIST_SCREEN
const U8 category10[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_LIST1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set10[] = 
{
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* Category Screen Coordinates */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* greyscale rectangle */
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET + 1, MMI_CONTENT_HEIGHT - 2 * MMI_SMALL_SCREEN_Y_OFFSET + 1, DM_NO_FLAGS,    /* control area */
    0,0,0,0,DM_CATEGORY_CONTROL_COORDINATES, /* List */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
    DM_BUTTON_BAR_UP_ARROW | DM_BUTTON_BAR_DOWN_ARROW, MMI_SOFTKEY_WIDTH        /* Button Bar */
};
#endif /* UI_SMALL_LIST_SCREEN */ 
/* END VIJAY PMT 20050930 */

const U8 category14_list[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
#if defined __MMI_UI_TECHNO_MAINMENU__ || defined __MMI_UI_DALMATIAN_MAINMENU__
    DM_CATEGORY_CONTROLLED_AREA,
#else
    DM_LIST1,
#endif /* __MMI_UI_TECHNO_MAINMENU__ || defined __MMI_UI_DALMATIAN_MAINMENU__ */
    DM_BUTTON_BAR1
};
const S16 coordinate_set14_List_Page[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
#ifdef __MMI_UI_MM_HORIZONTAL_PAGE_STYLE__    
    DM_DEFAULT_BUTTON_BAR, DM_BUTTON_BAR_LEFT_ARROW | DM_BUTTON_BAR_RIGHT_ARROW, MMI_SOFTKEY_WIDTH
#else    
    DM_DEFAULT_BUTTON_BAR, DM_BUTTON_BAR_UP_ARROW | DM_BUTTON_BAR_DOWN_ARROW, MMI_SOFTKEY_WIDTH
#endif
};

#ifndef GUI_MAINMENU_SHOW_STATUS_ICON
/* without status bar */
const U8 category14_matrix[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_TITLE1,
    DM_MATRIX_MENU1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set14_Matrix[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS,
    0, MMI_THIN_TITLE_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS, 
    DM_DEFAULT_BUTTON_BAR, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH
};

#else /* GUI_MAINMENU_SHOW_STATUS_ICON */

const U8 category14_matrix[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MATRIX_MENU1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set14_Matrix[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR,
        DM_BUTTON_BAR_LEFT_ARROW | DM_BUTTON_BAR_RIGHT_ARROW | DM_BUTTON_BAR_UP_ARROW | DM_BUTTON_BAR_DOWN_ARROW,
        MMI_SOFTKEY_WIDTH
};

#endif /* GUI_MAINMENU_SHOW_STATUS_ICON */ 

const U8 category14_circular_3d[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CIRCULAR_MENU1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set14_Circular[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_CONTENT_X, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR,
        DM_BUTTON_BAR_LEFT_ARROW | DM_BUTTON_BAR_RIGHT_ARROW | DM_BUTTON_BAR_UP_ARROW | DM_BUTTON_BAR_DOWN_ARROW,
        MMI_SOFTKEY_WIDTH
};

const S16 coordinate_set14_Rotate[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_CONTENT_X, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR,
#ifdef ROTATE_HORI
    DM_BUTTON_BAR_LEFT_ARROW | DM_BUTTON_BAR_RIGHT_ARROW,
#else 
    DM_BUTTON_BAR_UP_ARROW | DM_BUTTON_BAR_DOWN_ARROW,
#endif 
    MMI_SOFTKEY_WIDTH
};

const U8 category15_matrix[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MATRIX_MENU1
};

#if (defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__)) && defined (__MMI_TOUCH_DIAL_SCREEN__)
const U8 category16[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    DM_DIALER_INPUT_BOX1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set16[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_DIALING_KEYPAD_LAYER_X, MMI_DIALING_KEYPAD_LAYER_Y, MMI_DIALING_KEYPAD_LAYER_WIDTH,
        MMI_DIALING_KEYPAD_LAYER_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_DIALING_KEYPAD_LAYER_WIDTH, MMI_DIALING_KEYPAD_LAYER_HEIGHT, DM_NO_FLAGS,
    MMI_DIALING_KEYPAD_LAYER_X, MMI_DIALING_KEYPAD_LAYER_Y - MMI_DIALING_BOX_HEIGHT, MMI_DIALING_KEYPAD_LAYER_WIDTH,
        MMI_DIALING_BOX_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif defined (__MMI_MAINLCD_176X220__) && defined (__MMI_TOUCH_DIAL_SCREEN__)
const U8 category16[] = 
{
    6,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_DIALER_INPUT_BOX1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set16[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_DIALING_KEYPAD_LAYER_X, MMI_DIALING_KEYPAD_LAYER_Y, MMI_DIALING_KEYPAD_LAYER_WIDTH,
        MMI_DIALING_KEYPAD_LAYER_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_DIALING_KEYPAD_LAYER_WIDTH, 150, DM_NO_FLAGS,
    DM_DEFAULT_STATUS_BAR_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, 32, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
/* 061507 128x160 touch Start */
#elif defined (__MMI_MAINLCD_128X160__) && defined (__MMI_TOUCH_DIAL_SCREEN__)//061607 128x160 touch
const U8 category16[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    //DM_STATUS_BAR1,
    DM_DIALER_INPUT_BOX1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set16[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_DIALING_KEYPAD_LAYER_X, MMI_DIALING_KEYPAD_LAYER_Y, MMI_DIALING_KEYPAD_LAYER_WIDTH,
        MMI_DIALING_KEYPAD_LAYER_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_DIALING_KEYPAD_LAYER_WIDTH, 150, DM_NO_FLAGS,
    //DM_DEFAULT_STATUS_BAR_FLAG,
    0, 0/*MMI_STATUS_BAR_HEIGHT*/, MAIN_LCD_DEVICE_WIDTH, MMI_DIALING_BOX_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
/* 061507 128x160 touch Start */
#elif defined (__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)|| defined (__MMI_MAINLCD_320X240__)
/* 176x220 w/o touch screen have transparent softkey background in dialing screen. */
const U8 category16[] = 
{
    6,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set16[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_STATUS_BAR, DM_SPECIFIC_HIDE_STATUS_BAR,
    DM_DEFAULT_BUTTON_BAR, DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH
};
#else
/* 128x128 and 128x160 do not have transparent softkey background in dialing screen. */
const U8 category16[] = 
{
    6,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set16[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_STATUS_BAR, DM_SPECIFIC_HIDE_STATUS_BAR,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif 

const U8 category18[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set18[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category19[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_LIST1,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set19[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, 0, MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category20[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set20[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category21[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};

const U8 category22[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_MATRIX_MENU1
};
const S16 coordinate_set22[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
};

const U8 category28[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_EMS_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA
};

const U8 category32[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_MULTILINE_INPUTBOX1,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set32[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, ((MMI_MENUITEM_HEIGHT << 1) + 6 /* editor border */), DM_NO_FLAGS,
    0, ((MMI_MENUITEM_HEIGHT << 1) + 6 /* editor border */), MAIN_LCD_DEVICE_WIDTH,
        MAIN_LCD_DEVICE_HEIGHT - ((MMI_MENUITEM_HEIGHT << 1) + 6 /* editor border */) - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category33[] = 
{
    4,
    DM_WALL_PAPER,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set33[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
#if defined (__MMI_IDLE_FULL_SCREEN__)
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
        DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH
#else /* defined (__MMI_IDLE_FULL_SCREEN__) */ 
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
#endif /* defined (__MMI_IDLE_FULL_SCREEN__) */ 
};

const U8 category34[] =
{
    4,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_BUTTON_BAR1
};
const S16 coordinate_set34[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
#if defined (__MMI_IDLE_FULL_SCREEN__)
            0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
                DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH,
#else /* defined (__MMI_IDLE_FULL_SCREEN__) */ 
            DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
#endif /* defined (__MMI_IDLE_FULL_SCREEN__) */ 
};


const U8 category35[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_STATUS_BAR1
};
const S16 coordinate_set35[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, (MMI_STATUS_BAR_HEIGHT + MMI_TITLE_HEIGHT) << 1, MAIN_LCD_DEVICE_WIDTH,
        MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT - MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category39[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
#if(UI_DISABLE_EMS_INPUT_BOX)
    DM_MULTILINE_INPUTBOX1
#else 
    DM_EMS_INPUTBOX1
#endif 
};

const U8 category57[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_INLINE_FIXED_LIST1
};
const S16 coordinate_set57[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

/* Should be revised for 240x320 screen */
const S16 coordinate_set57_top_infobox[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_CONTENT_X, MMI_CONTENT_Y, MAIN_LCD_DEVICE_WIDTH, 96, DM_NO_FLAGS,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};

const U8 category61[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_IMAGE,
    DM_NEW_LAYER_START,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set61[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    CAT61_INFO_X, CAT61_INFO_Y, CAT61_INFO_W, CAT61_INFO_H, DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE
};

const U8 category62[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_NEW_LAYER_START,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};

#if (defined __MMI_MAINLCD_240X320__) || (defined __MMI_MAINLCD_320X240__)
const S16 coordinate_set62[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + 6, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - 12, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};
#elif (defined __MMI_MAINLCD_176X220__)
const S16 coordinate_set62[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + 1, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - 1, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};
#else
const S16 coordinate_set62[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D, 
#else
    DM_POPUP_SCREEN_COORDINATE, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
#endif
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};
#endif

const U8 category64[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_NEW_LAYER_START,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set64[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,    /* Category Screen Coordinates//092005 grayscale Calvin */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};

#if defined(__MMI_SCREEN_ROTATE__)
const S16 rotated_coordinate_set64[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, DM_DRAW_POPUP_BACKGROUND_3D,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

#ifdef __MMI_MAINLCD_240X320__
const U8 category66_normal[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,    
    DM_POPUP_BACKGROUND,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set66_normal[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, /*DM_POPUP_BACKGROUND_GREYSCALE | */DM_DRAW_POPUP_BACKGROUND_3D,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

#if defined(__MMI_SCREEN_ROTATE__)
const S16 coordinate_set66_normal_rotated[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, /*DM_POPUP_BACKGROUND_GREYSCALE | */DM_DRAW_POPUP_BACKGROUND_3D,
    MMI_ROTATED_POP_UP_DIALOG_X + 6, MMI_ROTATED_POP_UP_DIALOG_Y + 6, MMI_ROTATED_POP_UP_DIALOG_WIDTH - 12,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - 12,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

#else /* __MMI_MAINLCD_240X320__ */ 
const U8 category66_normal[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_POPUP_BACKGROUND,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set66_normal[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_DRAW_POPUP_BACKGROUND_3D,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
    DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

#if defined(__MMI_SCREEN_ROTATE__)
const S16 coordinate_set66_normal_rotated[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, /*DM_POPUP_BACKGROUND_GREYSCALE | */DM_DRAW_POPUP_BACKGROUND_3D, 
    MMI_ROTATED_POP_UP_DIALOG_X + 6, MMI_ROTATED_POP_UP_DIALOG_Y + 6, MMI_ROTATED_POP_UP_DIALOG_WIDTH - 12,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - 12,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

#endif /* __MMI_MAINLCD_240X320__ */ 

#ifdef __MMI_MAINLCD_240X320__
const U8 category66_status_icon[] = 
{
    9,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_NEW_LAYER_START,
    DM_STATUS_BAR1,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
const S16 coordinate_set66_status_icon[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* __MMI_MAINLCD_240X320__ */ 
const U8 category66_status_icon[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_STATUS_BAR1,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
const S16 coordinate_set66_status_icon[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,    
    DM_DEFAULT_STATUS_BAR_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT,
        0,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* __MMI_MAINLCD_240X320__ */ 

#if (defined __MMI_MAINLCD_240X320__) || (defined __MMI_MAINLCD_320X240__)
const U8 category66_none[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_NEW_LAYER_START,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
const S16 coordinate_set66_none[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#if defined(__MMI_SCREEN_ROTATE__)
const S16 coordinate_set66_none_rotated[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE,  DM_NO_FLAGS,        
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

#elif defined(__MMI_MAINLCD_176X220__) /* (defined __MMI_MAINLCD_240X320__) || (defined __MMI_MAINLCD_320X240__) */ 
const U8 category66_none[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_NEW_LAYER_START,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
const S16 coordinate_set66_none[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#if defined(__MMI_SCREEN_ROTATE__)
const S16 coordinate_set66_none_rotated[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, DM_NO_FLAGS,        
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

#else /* (defined __MMI_MAINLCD_240X320__) || (defined __MMI_MAINLCD_320X240__) */ 
const U8 category66_none[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
const S16 coordinate_set66_none[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_TITLE_HEIGHT, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT,
        DM_NO_FLAGS,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#if defined(__MMI_SCREEN_ROTATE__)
const S16 coordinate_set66_none_rotated[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    //DM_POPUP_SCREEN_COORDINATE, /*DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D */ DM_NO_FLAGS,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

#endif /* (defined __MMI_MAINLCD_240X320__) || (defined __MMI_MAINLCD_320X240__) */ 


const U8 category67[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    //DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set67[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,    /* Category Screen Coordinates//092005 grayscale Calvin */
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    //DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};

#if defined(__MMI_SCREEN_ROTATE__)
const S16 rotated_coordinate_set67[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, DM_DRAW_POPUP_BACKGROUND_3D,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    //DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 


const U8 category69[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_SINGLELINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set69[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X + CAT69_MARGIN, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH - (CAT69_MARGIN << 1), MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

const U8 category74[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set74[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};
#ifdef __MMI_TOUCH_SCREEN__
const U8 category75[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
#else
const U8 category75[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
#endif
const S16 coordinate_set75[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};
#ifdef __MMI_TOUCH_SCREEN__
const U8 category77[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA
};
#else
const U8 category77[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_MULTILINE_INPUTBOX1
};
#endif
const S16 coordinate_set77[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};

#if defined(__MMI_MAINLCD_176X220__)
const U8 category83[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_CALENDAR,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_STATUS_BAR_HEIGHT, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED
};
const U8 category83_no_status[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_CALENDAR,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83_no_status[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_STATUS_BAR_HEIGHT, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED
};
#elif defined(__MMI_MAINLCD_240X320__)
const U8 category83[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_CALENDAR,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, 22, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED
};
const U8 category83_no_status[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_CALENDAR,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83_no_status[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, 22, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED
};
#else
const U8 category83[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CALENDAR,
    DM_BUTTON_BAR1
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif

const U8 category85[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON,
    DM_BUTTON
};
#if defined ( __MMI_MAINLCD_176X220__) || defined ( __MMI_MAINLCD_240X320__)
const S16 coordinate_set85[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    //MMI_CONTENT_X, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y,        /* List Menu */
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};
#else /* defined ( __MMI_MAINLCD_176X220__) || defined ( __MMI_MAINLCD_240X320__) */
const S16 coordinate_set85[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    //MMI_CONTENT_X, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y,        /* List Menu */
    MMI_TITLEBAR_BUTTON_GAP,
        (MMI_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1),
        MMI_TITLEBAR_BUTTON_WIDTH, MMI_TITLEBAR_BUTTON_HEIGHT, DM_NO_FLAGS,
    (MAIN_LCD_DEVICE_WIDTH) - (MMI_TITLEBAR_BUTTON_GAP) - (MMI_TITLEBAR_BUTTON_WIDTH),
        (MMI_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1),
        MMI_TITLEBAR_BUTTON_WIDTH, MMI_TITLEBAR_BUTTON_HEIGHT, DM_NO_FLAGS
};
#endif

const U8 category85_no_button[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1
};


#if 0//def __MMI_WALLPAPER_ON_BOTTOM__
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
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */ 
const U8 category86[] = 
{
    7,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set86[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

const U8 category88[] = 
{
    7,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_SLIDE_CONTROL,
    DM_SLIDE_CONTROL,
    DM_SLIDE_CONTROL
};

#ifdef __MMI_MAINLCD_320X240__
const S16 coordinate_set88_3_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_CONTENT_X, MMI_CONTENT_Y, MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, MMI_CONTENT_Y + 10, MMI_CONTENT_WIDTH, 20, DM_SLIDE_CONTROL_VALUE_POS_TAIL,
    MMI_CONTENT_X, MMI_CONTENT_Y + 60, MMI_CONTENT_WIDTH, 20, DM_SLIDE_CONTROL_VALUE_POS_TAIL,
    MMI_CONTENT_X, MMI_CONTENT_Y + 110, MMI_CONTENT_WIDTH, 20, DM_SLIDE_CONTROL_VALUE_POS_TAIL
};

const S16 coordinate_set88_2_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_CONTENT_X, MMI_CONTENT_Y, MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, MMI_CONTENT_Y + 20, MMI_CONTENT_WIDTH, 20, DM_SLIDE_CONTROL_VALUE_POS_TAIL,
    MMI_CONTENT_X, MMI_CONTENT_Y + 80, MMI_CONTENT_WIDTH, 20, DM_SLIDE_CONTROL_VALUE_POS_TAIL,
    DM_NULL_COORDINATE
};

#elif defined __MMI_MAINLCD_240X320__
const S16 coordinate_set88_3_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 10, MMI_COMMON_CONTENT_WIDTH, 20, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 85, MMI_COMMON_CONTENT_WIDTH, 20, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 160, MMI_COMMON_CONTENT_WIDTH, 20, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE
};

const S16 coordinate_set88_2_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 10, MMI_COMMON_CONTENT_WIDTH, 20, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 120, MMI_COMMON_CONTENT_WIDTH, 20, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
    DM_NULL_COORDINATE
};

#elif defined __MMI_MAINLCD_176X220__
const S16 coordinate_set88_3_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 10, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 60, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 110, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD
};

const S16 coordinate_set88_2_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 15, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 90, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1,
        DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
    DM_NULL_COORDINATE
};

#elif defined __MMI_MAINLCD_128X160__
const S16 coordinate_set88_3_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 2, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 39, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 76, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD
};
const S16 coordinate_set88_2_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 10, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 75, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD,
    DM_NULL_COORDINATE
};
#elif defined __MMI_MAINLCD_128X128__
const S16 coordinate_set88_3_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y , MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 30, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 60, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_HEAD
};
const S16 coordinate_set88_2_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 10, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_TAIL,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 55, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1, DM_SLIDE_CONTROL_VALUE_POS_TAIL,
    DM_NULL_COORDINATE
};
#endif 

const S16 coordinate_set88_1_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MAIN_LCD_DEVICE_HEIGHT >> 1, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT >> 1,
        DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
    DM_NULL_COORDINATE,
    DM_NULL_COORDINATE
};

const U8 category91[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_CONTROL_SET_COMMON,
};
const S16 coordinate_set91[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

/* 121106 HID Start */
#ifdef __GDI_MEMORY_PROFILE_2__
const U8 category95[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_PANEL,
    DM_BUTTON_BAR1
};
const S16 coordinate_set95[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT/* - MMI_BUTTON_BAR_HEIGHT*/, DM_NO_FLAGS,
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH    /* Button Bar */
};
#else
const U8 category95[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_PANEL,
    DM_BUTTON_BAR1
};
const S16 coordinate_set95[] = 
{
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH    /* Button Bar */
};
#endif
/* 121106 HID End */

/* START VIJAY PMT 20050930 */
#ifdef UI_SMALL_CATEGORY_EDITOR
const U8 category100[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_TITLE1,
    DM_MULTILINE_INPUTBOX1,
    DM_RECTANGLE,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set100[] = 
{
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* Category Screen Coordinates */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* greyscale rectangle */
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_HEIGHT, DM_NO_FLAGS,      /* title */
    MMI_SMALL_SCREEN_X_OFFSET, 1, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET, MMI_CONTENT_HEIGHT - 2 * MMI_SMALL_SCREEN_Y_OFFSET - MMI_TITLE_HEIGHT + 1, DM_PREVIOUS_CONTROL_END_Y,    /* Multiline inputbox */
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET, MMI_CONTENT_HEIGHT - 2 * MMI_SMALL_SCREEN_Y_OFFSET + 1, DM_NO_FLAGS,        /* Rectangle */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH,    /* Button Bar */
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + 2 * MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET, MMI_CONTENT_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET - 1, MMI_CONTENT_HEIGHT - 2 * (MMI_SMALL_SCREEN_Y_OFFSET) - MMI_TITLE_HEIGHT + /* MMI_MULTITAP_HEIGHT */ +1, DM_NO_FLAGS,      /* Category Controlled Area */
};
#endif /* UI_SMALL_CATEGORY_EDITOR */ 
/* END VIJAY PMT 20050930 */

#if defined(__MMI_WALLPAPER_ON_BOTTOM__)     /* 081206 volume control */
#if defined(__MMI_MAINLCD_320X240__)
const U8 category105[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BUTTON_BAR1,
    DM_BUTTON,
    DM_BUTTON
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    265, 166, 19, 23, DM_NO_FLAGS,
    39, 166, 19, 23, DM_NO_FLAGS
};
#elif defined(__MMI_MAINLCD_240X320__)
const U8 category105[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
    DM_BUTTON,
    DM_BUTTON
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /*shaokai modify it start.090831*/
    //36, 68-25, 42, 29, DM_NO_FLAGS,
    //36, 233-25, 42, 29, DM_NO_FLAGS
    36, 233, 42, 29, DM_NO_FLAGS,
    163, 233, 42, 29, DM_NO_FLAGS
    /*shaokai modify it start.090831*/
};
#elif defined(__MMI_MAINLCD_176X220__)
const U8 category105[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#else /* defined(__MMI_MAINLCD_240X320__) */
const U8 category105[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET1,
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#endif /* defined(__MMI_MAINLCD_240X320__) */
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
const U8 category105[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_IMAGE
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_NO_FLAGS
};
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 

#ifdef __MMI_TOUCH_SCREEN__
const U8 category111[] = 
{
    7,
    DM_BASE_LAYER_START,
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    DM_BACK_FILL_AREA,
#else
    DM_SCR_BG,
#endif
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
    DM_SINGLELINE_INPUTBOX1,
    DM_SCROLL_TEXT,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set111[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    DM_FULL_SCREEN_COORDINATE_FLAG,
#endif
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), (MMI_MENUITEM_HEIGHT << 1), DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP, /* Because there is not title, so we move start y */
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, CAT111_GAP, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_MENUITEM_HEIGHT, DM_PREVIOUS_CONTROL_END_Y,
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, CAT111_GAP, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_MENUITEM_HEIGHT, DM_PREVIOUS_CONTROL_END_Y,
    DM_DUMMY_COORDINATE
};
#else
const U8 category111[] = 
{
    8,
    DM_BASE_LAYER_START,
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    DM_BACK_FILL_AREA,
#else
    DM_SCR_BG,
#endif
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_SINGLELINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_SCROLL_TEXT
};
const S16 coordinate_set111[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    DM_FULL_SCREEN_COORDINATE_FLAG,
#endif
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1), DM_NO_FLAGS, /* Because there is not title, so we move start y */
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1) + MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_MENUITEM_HEIGHT, DM_NO_FLAGS    /* Because there is not title, so we move start y */
};
#endif 

#ifdef UI_SMALL_PIN_EDITOR_SCREEN
const U8 category112[] = 
{
    9,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_NEW_LAYER_START,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_SINGLELINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_SCROLL_TEXT,
    DM_BUTTON_BAR1,
};
const S16 coordinate_set112[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__)
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT - MMI_VKBD_TRAY_HEIGHT - 5, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
#else
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
#endif
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__)
    MMI_POP_UP_DIALOG_X + MMI_POP_UP_CONTENT_MARGIN_X, MMI_POP_UP_DIALOG_Y + MMI_POP_UP_CONTENT_MARGIN_Y, MMI_POP_UP_DIALOG_WIDTH - MMI_POP_UP_CONTENT_MARGIN_X*2, MMI_POP_UP_DIALOG_HEIGHT - MMI_POP_UP_CONTENT_MARGIN_Y*2 - MMI_SINGLELINE_INPUTBOX_HEIGHT - MMI_VKBD_TRAY_HEIGHT - 5, DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
#else
    MMI_POP_UP_DIALOG_X + MMI_POP_UP_CONTENT_MARGIN_X, MMI_POP_UP_DIALOG_Y + MMI_POP_UP_CONTENT_MARGIN_Y, MMI_POP_UP_DIALOG_WIDTH - MMI_POP_UP_CONTENT_MARGIN_X*2, MMI_POP_UP_DIALOG_HEIGHT - MMI_POP_UP_CONTENT_MARGIN_Y*2 - MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
#endif
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__)
    MMI_POP_UP_DIALOG_X + MMI_POP_UP_CONTENT_MARGIN_X, MMI_POP_UP_DIALOG_Y + MMI_POP_UP_DIALOG_HEIGHT - MMI_SINGLELINE_INPUTBOX_HEIGHT - MMI_POP_UP_CONTENT_MARGIN_Y - MMI_VKBD_TRAY_HEIGHT - 5, MMI_POP_UP_DIALOG_WIDTH - MMI_POP_UP_CONTENT_MARGIN_X*2, MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_NO_FLAGS,
#else
    MMI_POP_UP_DIALOG_X + MMI_POP_UP_CONTENT_MARGIN_X, MMI_POP_UP_DIALOG_Y + MMI_POP_UP_DIALOG_HEIGHT - MMI_SINGLELINE_INPUTBOX_HEIGHT - MMI_POP_UP_CONTENT_MARGIN_Y, MMI_POP_UP_DIALOG_WIDTH - MMI_POP_UP_CONTENT_MARGIN_X*2, MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_NO_FLAGS,
#endif
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* UI_SMALL_PIN_EDITOR_SCREEN */ 

const U8 category119[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_IMAGE,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set119[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

const U8 category120[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_DATE_TIME_DISPLAY,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1,
    DM_NEW_LAYER_START,
    DM_IMAGE
};
const S16 coordinate_set120[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_IDLE_STRING_MARGIN_GAP, CAT120_START_Y, MAIN_LCD_DEVICE_WIDTH - (MMI_IDLE_STRING_MARGIN_GAP << 1), MMI_SINGLELINE_INPUTBOX_HEIGHT + 3, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, CAT120_START_Y + MMI_SINGLELINE_INPUTBOX_HEIGHT + 3, MAIN_LCD_DEVICE_WIDTH, MMI_CONTENT_HEIGHT, DM_CENTRE_ALIGN_X,
};

const U8 category121[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_NEW_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set121[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT,  DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,//092206 alarm popup
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

const U8 category122[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
};
const S16 coordinate_set122[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};


const U8 category123[] = 
{
    10,                              /* Justin */
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,    /* Justin: first item is processed last in pen handler */
    DM_SCR_BG,
    DM_POPUP_BACKGROUND,
    DM_STATUS_BAR1,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
const S16 coordinate_set123[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG, /* Justin: for category controlled area */
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};


#if 0//def __MMI_WALLPAPER_ON_BOTTOM__
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
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */ 
const U8 category128[] = 
{
    7,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set128[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

/* MTK Leo start, use new layer instead of scr_bg layer to display wallpaper */
const U8 category129[] =
{
    6,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON
};

const S16 coordinate_set129[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};

const S16 coordinate_set129_no_button[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_NULL_COORDINATE,
    DM_NULL_COORDINATE
};


const U8 category130[] =
{
    6,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON
};

const S16 coordinate_set130[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};

const U8 category132[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_IMAGE,
    DM_BASE_CONTROL_SET_COMMON,    
};

const S16 coordinate_set132[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

const U8 category131[] = 
{
    4,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_DATE_TIME_DISPLAY
};

const S16 coordinate_set131[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

const U8 category141_normal[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_IMAGE,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set141[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

const U8 category141_status_icon[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_STATUS_BAR1,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_IMAGE,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
const S16 coordinate_set141_status_icon[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT,
        DM_NO_FLAGS,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

/* START VIJAY PMT 20050930 */
#ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN
const U8 category146[] = 
{
    6,
    DM_RECTANGLE,
    DM_BASE_LAYER_START,
    DM_BACK_FILL_AREA,
    DM_TITLE1,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set146[] = 
{
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* Category Screen Coordinates */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* greyscale rectangle */
    MMI_SMALL_SCREEN_X_OFFSET - 1, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET-1, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET + 2, MMI_CONTENT_HEIGHT - 2 * MMI_SMALL_SCREEN_Y_OFFSET + 2, DM_NO_FLAGS,    /* back fill area *///101706 image select
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_HEIGHT, DM_NO_FLAGS,      /* title */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH,    /* Button Bar */
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + 2 * MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET+1, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET, MMI_CONTENT_HEIGHT - 2 * MMI_SMALL_SCREEN_Y_OFFSET - MMI_TITLE_HEIGHT-1, DM_NO_FLAGS, /* category control area */
};
#endif /* UI_SMALL_IMAGE_SELECTOR_SCREEN */ 
/* END VIJAY PMT 20050930 */

const U8 category151[] = 
{
    9,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_POPUP_BACKGROUND,
    DM_STATUS_BAR1,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};

#ifdef __MMI_MAINLCD_240X320__
const S16 coordinate_set151[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    0, 0, 0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS,
    MMI_POP_UP_DIALOG_X + 6, MMI_POP_UP_DIALOG_Y + 6, MMI_POP_UP_DIALOG_WIDTH - 12, MMI_POP_UP_DIALOG_HEIGHT - 12,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL |
        DM_ALLIGNED_AREA_MULTILINE_SCROLL_IF_REQUIRED,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* __MMI_MAINLCD_240X320__ */ 
const S16 coordinate_set151[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    0, 0, 0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS,
    MMI_POP_UP_DIALOG_X + 2, MMI_POP_UP_DIALOG_Y + 4, MMI_POP_UP_DIALOG_WIDTH - 4, MMI_POP_UP_DIALOG_HEIGHT - 8,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL |
        DM_ALLIGNED_AREA_MULTILINE_SCROLL_IF_REQUIRED,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* __MMI_MAINLCD_240X320__ */ 
const U8 category152[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set152[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};


const U8 category154_normal[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set154_normal[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
const U8 category154_status_icon[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set154_status_icon[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    DM_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};


const U8 category157[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_NEW_LAYER_START,
    DM_INLINE_FIXED_LIST1
};
const S16 coordinate_set157[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

const U8 category162[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_NEW_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set162[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT,
        DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

const U8 category164[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_NEW_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set164[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT,
        DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

#if defined(__MMI_SCREEN_ROTATE__)
const S16 rotated_coordinate_set164[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X, MMI_ROTATED_POP_UP_DIALOG_Y, MMI_ROTATED_POP_UP_DIALOG_WIDTH,
        MMI_ROTATED_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2, DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

const U8 category166[] = 
{
    2,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set166[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};

const U8 category171[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set171[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_EDITOR_CONTENT_COORDINATE_FLAG
};


const U8 category200[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_SINGLELINE_INPUTBOX1
};

const S16 coordinate_set200[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    CAT200_INPUTBOX_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_SINGLELINE_INPUTBOX_HEIGHT - 2, MAIN_LCD_DEVICE_WIDTH - CAT200_INPUTBOX_X - CAT200_MARGIN_WIDTH - 1 /* border */, MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_NO_FLAGS
};

const U8 category201[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_DYNAMIC_LIST1,
    DM_MULTILINE_INPUTBOX1,
};
const S16 coordinate_set201[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined ( __MMI_MAINLCD_320X240__)        
    MMI_SUBMENU_CONTENT_X, 0, MMI_SUBMENU_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - CAT201_EDITOR_HEIGHT, DM_NO_FLAGS,
    MMI_SUBMENU_CONTENT_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - CAT201_EDITOR_HEIGHT, MMI_SUBMENU_CONTENT_WIDTH, CAT201_EDITOR_HEIGHT, DM_NO_FLAGS,   /* Single Line Input box */
#else
    MMI_SUBMENU_CONTENT_X, MMI_SUBMENU_CONTENT_Y, MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT - CAT201_EDITOR_HEIGHT, DM_NO_FLAGS,
    MMI_SUBMENU_CONTENT_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - CAT201_EDITOR_HEIGHT, MMI_SUBMENU_CONTENT_WIDTH, CAT201_EDITOR_HEIGHT, DM_NO_FLAGS,   /* Single Line Input box */
#endif
};
const U8 category204[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_SINGLELINE_INPUTBOX1,
    DM_IMAGE,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set204[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

const U8 category205[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set205[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MAIN_LCD_DEVICE_HEIGHT >> 1, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT >> 1, DM_CENTRE_ALIGN_X,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category212[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_DYNAMIC_LIST1
};
const S16 coordinate_set212[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    0, 1, MMI_SUBMENU_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 1,
        DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};

const U8 category213[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
};

const U8 category214[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA
};

const U8 category221[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set221[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#if defined(__MMI_SCREEN_ROTATE__)

const S16 rotated_coordinate_set221[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,                         /* Category Screen Coordinates */
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_ROTATED_SOFTKEY_WIDTH   /* Button Bar */
};

#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

const U8 category222[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};

const U8 category229[] =
{
    5,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON
};

const S16 coordinate_set229[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};

const U8 category257[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_RECTANGLE,
    DM_IMAGE,
    DM_INLINE_FIXED_LIST1
};
const S16 coordinate_set257[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    3, MMI_CONTENT_Y, DM_CALCULATED_WIDTH, DM_CALCULATED_HEIGHT, DM_LEFT_ALIGN_X | DM_TOP_ALIGN_Y,
    MMI_CONTENT_X, 0, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};

const U8 categoryNSM275[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_setNSM275[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category263[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set263[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    MMI_CONTENT_X, 1, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 1, DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y        /* List Menu */
};

const U8 category264[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_IMAGE
};
const S16 coordinate_set264[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE,DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + ((MMI_POP_UP_DIALOG_WIDTH - 20) >> 1), MMI_POP_UP_DIALOG_Y + 20, 20, 20, DM_NO_FLAGS
};

#ifdef __MMI_CAT265_SUPPORT__//051507 channel list
const U8 category265[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1
};
#if defined ( __MMI_MAINLCD_176X220__) || defined ( __MMI_MAINLCD_240X320__)
const S16 coordinate_set265[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, CAT265_CONTROL_AREA_Y, MAIN_LCD_DEVICE_WIDTH, CAT265_CONTROL_AREA_HEIGHT, DM_NO_FLAGS,
    0, CAT265_LIST_Y, MAIN_LCD_DEVICE_WIDTH, CAT265_LIST_HEIGHT, DM_NO_FLAGS
};
#else /* defined ( __MMI_MAINLCD_176X220__) || defined ( __MMI_MAINLCD_240X320__) */
const S16 coordinate_set265[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, CAT265_CONTROL_AREA_Y, MAIN_LCD_DEVICE_WIDTH, CAT265_CONTROL_AREA_HEIGHT, DM_NO_FLAGS,
    0, CAT265_LIST_Y, MAIN_LCD_DEVICE_WIDTH, CAT265_LIST_HEIGHT, DM_NO_FLAGS
};
#endif
#endif

const U8 category275[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set275[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

/* We are showing status bar in MMS view category screen for that we have to add one extra field(DM_STATUS_BAR1) for status bar */
#ifdef __MMI_TOUCH_SCREEN__
const U8 category276[] = 
{
#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
    7,
#else 
    6,
#endif 
    DM_BASE_LAYER_START,
#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
    DM_STATUS_BAR1,
#endif 
    DM_CATEGORY_CONTROLLED_AREA,
    DM_TITLE1,
    DM_BUTTON_BAR1,
    DM_BUTTON,
    DM_BUTTON
};

const S16 coordinate_set276[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
    DM_DEFAULT_STATUS_BAR_FLAG,
#endif 
    DM_CONTENT_COORDINATE_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    MMI_TITLEBAR_BUTTON_GAP, (MMI_STATUS_BAR_HEIGHT) + (MMI_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1),
    MMI_TITLEBAR_BUTTON_WIDTH, MMI_TITLEBAR_BUTTON_HEIGHT, DM_NO_FLAGS,
    (MAIN_LCD_DEVICE_WIDTH) - (MMI_TITLEBAR_BUTTON_GAP) - (MMI_TITLEBAR_BUTTON_WIDTH),
    (MMI_STATUS_BAR_HEIGHT) + (MMI_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1),
    MMI_TITLEBAR_BUTTON_WIDTH, MMI_TITLEBAR_BUTTON_HEIGHT, DM_NO_FLAGS
};
#else /* __MMI_TOUCH_SCREEN__ */
const U8 category276[] = 
{
#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
    4,
#else 
    3,
#endif 
    DM_BASE_LAYER_START,
#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
    DM_STATUS_BAR1,
#endif 
    /* DM_SCR_BG, */
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set276[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
    DM_DEFAULT_STATUS_BAR_FLAG,
#endif 
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__
#ifdef __MMI_MAINLCD_320X240__
const U8 category280[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set280[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#else /* __MMI_MAINLCD_320X240__ */
const U8 category280[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set280[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#endif
#endif /* __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__ */

#ifdef __MMI_SUBLCD__
const U8 category301[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_IMAGE
};
const S16 coordinate_set301[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH - 1, SUB_LCD_DEVICE_HEIGHT - 1, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH, DM_CALCULATED_HEIGHT, DM_CENTRE_ALIGN_X | DM_PREVIOUS_CONTROL_END_Y
};

const U8 category303[] = {4,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_DATE_TIME_DISPLAY,
    DM_CATEGORY_CONTROLLED_AREA,
};
const S16 coordinate_set303[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH - 1, SUB_LCD_DEVICE_HEIGHT - 1, DM_NO_FLAGS
};

#ifndef __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__
const U8 category304[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_IMAGE
};
const S16 coordinate_set304[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    0, 14, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT - 14, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#else /* __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__ */ 
const U8 category304[] = 
{
    2,
    DM_BASE_LAYER_START,
    DM_IMAGE
};
const S16 coordinate_set304[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif /* __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__ */ 

const U8 category310[] = 
{
    2,
    DM_BASE_LAYER_START,
    DM_STRING
};
const S16 coordinate_set310[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

const U8 category311[] = {4,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_IMAGE
};
const S16 coordinate_set311[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH - 1, SUB_LCD_DEVICE_HEIGHT - 1, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH, DM_CALCULATED_HEIGHT, DM_CENTRE_ALIGN_X | DM_PREVIOUS_CONTROL_END_Y
};

const U8 category312[] = {4,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_DATE_TIME_DISPLAY,
    DM_STRING
};
const S16 coordinate_set312[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH, DM_CALCULATED_HEIGHT, DM_CENTRE_ALIGN_X | DM_PREVIOUS_CONTROL_END_Y_OFFSET_HEIGHT
};

const U8 category313[] = 
{
    2,
    DM_BASE_LAYER_START,
    DM_IMAGE
};
const S16 coordinate_set313[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
};

const U8 category314[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_TITLE1,
    DM_LIST1
};
const S16 coordinate_set314[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, SUB_LCD_DEVICE_WIDTH, MMI_SUBLCD_TITLE_HEIGHT, DM_NO_FLAGS,
    0, MMI_SUBLCD_TITLE_HEIGHT, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT - MMI_SUBLCD_TITLE_HEIGHT, DM_NO_FLAGS
};

const U8 category315[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_TITLE1,
    DM_DYNAMIC_LIST1
};
const S16 coordinate_set315[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, SUB_LCD_DEVICE_WIDTH, MMI_SUBLCD_TITLE_HEIGHT, DM_NO_FLAGS,
    0, MMI_SUBLCD_TITLE_HEIGHT, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT - MMI_SUBLCD_TITLE_HEIGHT, DM_NO_FLAGS
};
#endif /* __MMI_SUBLCD__ */ 

const U8 category305[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set305[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category306[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_NWAY_STOPWATCH,
    DM_BUTTON_BAR1
};

#if defined (__MMI_MAINLCD_128X128__)
const S16 coordinate_set306[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /*  Stop Watch */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    /* Way_maintimer_start */
    0, 0,
    /* nWay_maintimer_end */
    MAIN_LCD_DEVICE_WIDTH, MMI_MENUITEM_HEIGHT,
    /* nWay_dialog_start */
    0, MMI_MENUITEM_HEIGHT,
    /* nWay_dialog_end */
    MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3,
    /* Separator Height */
    0,
    /* Button Bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif defined (__MMI_MAINLCD_128X160__)
const S16 coordinate_set306[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* Stop Watch */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    /* Way_maintimer_start */
    0, 0,
    /* nWay_maintimer_end */
    MAIN_LCD_DEVICE_WIDTH, MMI_MENUITEM_HEIGHT,
    /* nWay_dialog_start */
    0, MMI_MENUITEM_HEIGHT,
    /* nWay_dialog_end */
    MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3,
    /* Separator Height */
    MMI_MENUITEM_HEIGHT,
    /* Button Bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif defined (__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__)
const S16 coordinate_set306[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* Stop Watch */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    /* Way_maintimer_start */
    10, 10,
    /* nWay_maintimer_end */
    MAIN_LCD_DEVICE_WIDTH - 10, 40,
    /* nWay_dialog_start */
    10, 40,
    /* nWay_dialog_end */
    MAIN_LCD_DEVICE_WIDTH - 10, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 10,
    /* Separator Height */
    30,
    /* Button Bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif 

#if defined(__MMI_MAINLCD_240X320__)
const U8 category307[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_TYPICAL_STOPWATCH,
    DM_BASE_CONTROL_SET2
};
#else /* defined(__MMI_MAINLCD_240X320__) */
const U8 category307[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_TYPICAL_STOPWATCH,
    DM_BUTTON_BAR1
};
#endif /* defined(__MMI_MAINLCD_240X320__) */

#if defined (__MMI_MAINLCD_128X128__)
const S16 coordinate_set307[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* Stop Watch */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    /* typ_timer */
    (MAIN_LCD_DEVICE_WIDTH >> 1), 70,
    /* typ_milsec */
    (MAIN_LCD_DEVICE_WIDTH >> 1), 85,
    /* typ_history_height */
    ((MMI_MENUITEM_HEIGHT << 1) + 2),
    /* Button Bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif defined (__MMI_MAINLCD_128X160__)
const S16 coordinate_set307[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* Stop Watch */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    /* typ_timer */
    (MAIN_LCD_DEVICE_WIDTH >> 1), 88,
    /* typ_milsec */
    (MAIN_LCD_DEVICE_WIDTH >> 1), 105,
    /* typ_history_height */
    ((MMI_MENUITEM_HEIGHT << 1) + 2),
    /* Button Bar */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
        MMI_SOFTKEY_WIDTH
};
#elif defined (__MMI_MAINLCD_176X220__)
const S16 coordinate_set307[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* Stop Watch */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    /* typ_timer */
    (MAIN_LCD_DEVICE_WIDTH >> 1), (MMI_MENUITEM_HEIGHT << 2) + 61,
    /* typ_milsec */
    (MAIN_LCD_DEVICE_WIDTH >> 1), (MMI_MENUITEM_HEIGHT << 2) + 73,
    /* typ_history_height */
    ((MMI_MENUITEM_HEIGHT << 2) + 2),
    /* Button Bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif defined(__MMI_MAINLCD_240X320__)
const S16 coordinate_set307[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* Stop Watch */
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH,
        MAIN_LCD_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    /* typ_timer */
    (MAIN_LCD_DEVICE_WIDTH >> 1), (MMI_MENUITEM_HEIGHT << 2) + 67,
    /* typ_milsec */
    (MAIN_LCD_DEVICE_WIDTH >> 1), (MMI_MENUITEM_HEIGHT << 2) + 90,
    /* typ_history_height */
    (MMI_MENUITEM_HEIGHT << 2) + 2
};
#elif defined(__MMI_MAINLCD_320X240__)
const S16 coordinate_set307[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* Stop Watch */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    /* typ_timer */
    (MAIN_LCD_DEVICE_WIDTH >> 1) + 10, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 52,
    /* typ_milsec */
    (MAIN_LCD_DEVICE_WIDTH >> 1) + 100, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 52,
    /* typ_history_height */
    MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 82,
    /* Button Bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else
const S16 coordinate_set307[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* Stop Watch */
    0, 0, 0, 0, DM_NO_FLAGS,
    /* typ_timer */
    0, 0,
    /* typ_milsec */
    0, 0,
    /* typ_history_height */
    0,
    /* Button Bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif 


const U8 category357[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_IMAGE,
    DM_INLINE_FIXED_LIST1
};
const S16 coordinate_set357[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_COMMON_CONTENT_Y, DM_CALCULATED_WIDTH, DM_CALCULATED_HEIGHT, DM_LEFT_ALIGN_X | DM_TOP_ALIGN_Y,
    MMI_COMMON_CONTENT_X, 0, MMI_COMMON_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};

#ifdef __MMI_DUAL_SIM_MASTER__
const s16 category363[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_LIST1
};
#endif  /* __MMI_DUAL_SIM_MASTER__ */

const U8 category384[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_DYNAMIC_LIST1
};

const S16 coordinate_set384[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CATEGORY_CONTROL_COORDINATES
};

const U8 category402[]=
{
	4,
	DM_BASE_LAYER_START,
	DM_BASE_CONTROL_SET_COMMON,
	DM_SCROLL_TEXT,
	DM_PERCENTAGE_BAR
};

const S16 coordinate_set402[]=
{
	DM_FULL_SCREEN_COORDINATE_FLAG,
	MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y+5, MAIN_LCD_DEVICE_WIDTH,1 , DM_CENTRE_ALIGN_X|DM_SCROLL_TEXT_USE_FONT_HEIGHT,
	MMI_COMMON_CONTENT_X, 1, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-1, DM_PREVIOUS_CONTROL_END_Y|DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};
#if defined (__MMI_MAINLCD_320X240__)
const U8 category403[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_IMAGE,
    DM_DATE_TIME_DISPLAY,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set403[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
    MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, 1, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
    DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* defined (__MMI_MAINLCD_320X240__) */
const U8 category403[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_IMAGE,
    DM_DATE_TIME_DISPLAY,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set403[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
    MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, 1, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
    DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined (__MMI_MAINLCD_320X240__) */
const U8 category404[] = 
{
    6,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set404[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,     /* DM_NEW_LAYER_START */
    DM_FULL_SCREEN_COORDINATE_FLAG,     /* DM_IMAGE */
    DM_DEFAULT_STATUS_BAR_FLAG,         /* STATUS_BAR */
    CAT404_INPUTBOX_X, CAT404_INPUTBOX_Y, CAT404_INPUTBOX_WIDTH, CAT404_INPUTBOX_HEIGHT, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP,    /* DM_MULTILINE_INPUTBOX1 */
    DM_DEFAULT_BUTTON_BAR,DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH   /* DM_BUTTON_BAR1 */
};

const U8 category412[]=
{
	5,
	DM_BASE_LAYER_START,
    DM_SCR_BG,
	DM_BASE_CONTROL_SET_COMMON,
	DM_IMAGE,
	DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set412[]=
{
	DM_FULL_SCREEN_COORDINATE_FLAG,
	MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, (MMI_MENUITEM_HEIGHT << 1), DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + (MMI_MENUITEM_HEIGHT << 1), MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_WIDTH - (MMI_MENUITEM_HEIGHT << 1), DM_NO_FLAGS
};

/* bi-degree main menu */
const U8 category414[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_TITLE1,
    DM_LIST1,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA
};

#if defined(__MMI_MAINLCD_240X320__)

const S16 coordinate_set414[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, MMI_TITLE_HEIGHT, 65, MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR,
        DM_BUTTON_DISABLE_BACKGROUND | DM_BUTTON_BAR_LEFT_ARROW | DM_BUTTON_BAR_RIGHT_ARROW | DM_BUTTON_BAR_UP_ARROW |
        DM_BUTTON_BAR_DOWN_ARROW, MMI_SOFTKEY_WIDTH,
    65, MMI_TITLE_HEIGHT, MAIN_LCD_DEVICE_WIDTH - 65, MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_NO_FLAGS
};

#elif defined(__MMI_MAINLCD_320X240__) /* defined(__MMI_MAINLCD_240X320__) */

/* must be the same to MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH in wgui_categories_MM.c. */
// TODO: Use MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH here by moving it to wgui.h.
#define BI_DEREREE_TAB_WIDTH 36 

const S16 coordinate_set414[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    BI_DEREREE_TAB_WIDTH, 0, MAIN_LCD_DEVICE_WIDTH - BI_DEREREE_TAB_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
    0, 0, BI_DEREREE_TAB_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR, DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH,
    BI_DEREREE_TAB_WIDTH, MMI_TITLE_HEIGHT, MAIN_LCD_DEVICE_WIDTH - BI_DEREREE_TAB_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS
};

#else /* defined(__MMI_MAINLCD_240X320__) */ 

const S16 coordinate_set414[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, MMI_TITLE_HEIGHT, 40, MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR,
        DM_BUTTON_DISABLE_BACKGROUND | DM_BUTTON_BAR_LEFT_ARROW | DM_BUTTON_BAR_RIGHT_ARROW | DM_BUTTON_BAR_UP_ARROW |
        DM_BUTTON_BAR_DOWN_ARROW, MMI_SOFTKEY_WIDTH,
    40, MMI_TITLE_HEIGHT, MAIN_LCD_DEVICE_WIDTH - 50, MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_NO_FLAGS
};

#endif /* defined(__MMI_MAINLCD_240X320__) */ 

const U8 category420[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set420[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__)

const U8 category425[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set425[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category425_no_tab[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set425_no_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

#elif defined(__MMI_MAINLCD_128X160__)

const U8 category425[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set425[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category425_no_tab[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET1,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set425_no_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

#else /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) */ 

const U8 category425[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set425[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category425_no_tab[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set425_no_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

#endif /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) */ 

#ifndef __MMI_MAINLCD_128X128__
const U8 category426[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set426[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif

const U8 category430[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set430[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__)

const U8 category435[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set435[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#else /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) */ 

const U8 category435[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_HORIZONTAL_TAB_BAR,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set435[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#endif /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) */ 

#ifdef __MMI_CAT44X_SUPPORT__     
const U8 category440[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_MULTILINE_INPUTBOX1,
    DM_PANEL
};
const S16 coordinate_set440[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, CAT440_TOP_TEXT_AREA_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + CAT440_TOP_TEXT_AREA_HEIGHT, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - CAT440_TOP_TEXT_AREA_HEIGHT - CAT440_BOTTOM_PANEL_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + MMI_COMMON_CONTENT_HEIGHT - CAT440_BOTTOM_PANEL_HEIGHT, MMI_COMMON_CONTENT_WIDTH, CAT440_BOTTOM_PANEL_HEIGHT, DM_NO_FLAGS
};

const U8 category443[] = 
{
    6,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_PANEL
};
const S16 coordinate_set443[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - CAT443_PANEL_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - CAT443_PANEL_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - CAT443_PANEL_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + MMI_COMMON_CONTENT_HEIGHT - CAT443_PANEL_HEIGHT, MMI_COMMON_CONTENT_WIDTH, CAT443_PANEL_HEIGHT, DM_NO_FLAGS
};

const U8 category445[] = 
{
    6,
    DM_BASE_LAYER_START,    
    DM_SCR_BG,
    DM_STRING,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set445[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_TITLE_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    10, MMI_TITLE_HEIGHT, MMI_CONTENT_WIDTH-20, MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - CAT445_CONTROL_AREA_HEIGHT - MMI_TITLE_HEIGHT, DM_NO_FLAGS,
    0, MMI_TITLE_HEIGHT + (MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - CAT445_CONTROL_AREA_HEIGHT - MMI_TITLE_HEIGHT), MMI_CONTENT_WIDTH, CAT445_CONTROL_AREA_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};


const U8 category447[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set447[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};


const U8 category448[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_RECTANGLE,
    DM_IMAGE,        
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set448[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,        
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X|DM_CENTER_ALIGN_Y|DM_BACK_FILL,
    DM_FULL_SCREEN_COORDINATE_FLAG
};


const U8 category449[] = 
{
    7,
    DM_NEW_LAYER_START,
    DM_RECTANGLE,
    DM_RECTANGLE,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set449[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,  
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_CENTRE_ALIGN_X|DM_CENTER_ALIGN_Y|DM_BACK_FILL,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

#endif /* __MMI_CAT44X_SUPPORT__ */


const U8 category525[]=
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,    
    DM_BUTTON_BAR1
};


const S16 coordinate_set525[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y|DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};


const U8 categoryEMS[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_SINGLELINE_INPUTBOX1,
    DM_MATRIX_MENU1
};
const S16 coordinate_setEMS[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_SUBMENU_CONTENT_X, MMI_SUBMENU_CONTENT_Y + CATEMS_AREA_GAP, MMI_SUBMENU_CONTENT_WIDTH, MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_CENTRE_ALIGN_X|DM_SINGLE_LINE_INPUTBOX_SPECIFIC_HEIGHT,
    MMI_SUBMENU_CONTENT_X, CATEMS_AREA_GAP, MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT - MMI_SINGLELINE_INPUTBOX_HEIGHT - (CATEMS_AREA_GAP << 1), DM_PREVIOUS_CONTROL_END_Y
};

const U8 category620[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_STRING,
    DM_STRING,
    DM_IMAGE,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set620[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};


#ifdef __UI_MMS_VIEWER_CATEGORY__
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
const U8 category630[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set630[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
	DM_DEFAULT_STATUS_BAR_FLAG, 
	MMI_CONTENT_X, MMI_STATUS_BAR_HEIGHT, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_STATUS_BAR_HEIGHT,DM_NO_FLAGS,
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
	
};
#else /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */
const U8 category630[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set630[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
	MMI_CONTENT_X, 0, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
    DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y,DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */
#endif /* __UI_MMS_VIEWER_CATEGORY__ */


const U8 categoryWcScreen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_WcScreen[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 categoryVdoScreen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_VdoScreen[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE
};

/* 061506 double buffer Start */
const U8 categoryVdoScreen_button[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_TITLE1,
    DM_BUTTON_BAR1,
    DM_BUTTON,
    DM_BUTTON,
    DM_CATEGORY_CONTROLLED_AREA
};

#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
const S16 coordinate_VdoScreen_button[] = 
{
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
    MMI_COMMON_TITLE_X, MMI_COMMON_TITLE_Y, MMI_COMMON_TITLE_WIDTH, MMI_COMMON_TITLE_HEIGHT, DM_NO_FLAGS,
#else /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG,
    DM_DUMMY_COORDINATE
};
#else /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */
const S16 coordinate_VdoScreen_button[] = 
{
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
    MMI_COMMON_TITLE_X, MMI_COMMON_TITLE_Y, MMI_COMMON_TITLE_WIDTH, MMI_COMMON_TITLE_HEIGHT, DM_NO_FLAGS,
#else /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG,
    DM_DUMMY_COORDINATE
};
#endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */
/* 061506 double buffer End */

#if 0 /* remove not used category */
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
/* under construction !*/
#endif

/* PMT Pankaj start 12042005 */
const U8 category334[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};

/* PMT Pankaj End */
#if 0 /* remove not used category */
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
/* under construction !*/
#ifdef __MMI_MAINLCD_176X220__
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
#elif defined ( __MMI_MAINLCD_240X320__ )
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
#else 
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
/* under construction !*/
#if defined(__MMI_SCREEN_ROTATE__)
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
/* under construction !*/
#ifdef __MMI_MAINLCD_176X220__
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
#elif defined __MMI_MAINLCD_240X320__
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
#else 
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
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 
/* under construction !*/
#endif /* remove not used category */

/* PMT Pankaj Start 12022005 */
const S16 coordinate_set334[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

/* PMT Pankaj End */

const U8 category227Screen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set227[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

#if defined ( __MMI_MAINLCD_240X320__)
const U8 category230Screen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET2,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set230[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG
};
#elif defined ( __MMI_MAINLCD_320X240__)
const U8 category230Screen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set230[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif/* defined ( __MMI_MAINLCD_240X320__) */

#ifdef __MMI_BROWSER_2__
const U8 category431[] =
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET1,
    DM_CATEGORY_CONTROLLED_AREA,
};

const S16 coordinate_set431[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,                     /* category screen coordinate */
    CAT431_X, CAT431_Y, CAT431_W, CAT431_H, DM_NO_FLAGS /* DM_CATEGORY_CONTROLLED_AREA */
};

const U8 category431_fullscreen[] =
{
    3,
    DM_BASE_LAYER_START,
    DM_TITLE1,
    DM_CATEGORY_CONTROLLED_AREA,
};

const S16 coordinate_set431_fullscreen[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG, /* category screen coordinate */
                                    /* DM_TITLE */
    0, 0, MMI_TITLE_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
                                    /* DM_CATEGORY_CONTROLLED_AREA */
    CAT431_FULLSCREEN_X, CAT431_FULLSCREEN_Y, CAT431_FULLSCREEN_W, CAT431_FULLSCREEN_H, DM_NO_FLAGS
};
#endif /* __MMI_BROWSER_2__ */

#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__)
const U8 category626[]=
{
    6, 
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const s16 coordinate_set626[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,//status bar
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif defined(__MMI_MAINLCD_128X160__)
const U8 category626[]=
{
    5, 
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const s16 coordinate_set626[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) */
const U8 category626[]=
{
    4, 
    DM_BASE_LAYER_START,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const s16 coordinate_set626[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) */

#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__)
const U8 category657[]=
{
    6, 
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_INLINE_FIXED_LIST1,
    DM_BUTTON_BAR1
};
const s16 coordinate_set657[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,//status bar
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH
};
#elif defined(__MMI_MAINLCD_128X160__)
const U8 category657[]=
{
    5, 
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_INLINE_FIXED_LIST1,
    DM_BUTTON_BAR1
};
const s16 coordinate_set657[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH
};
#else /* defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) */
const U8 category657[]=
{
    4, 
    DM_BASE_LAYER_START,
    DM_HORIZONTAL_TAB_BAR,
    DM_INLINE_FIXED_LIST1,
    DM_BUTTON_BAR1
};
const s16 coordinate_set657[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) */



const dm_category_id_control_set_map_struct g_categories_controls_map[] =
    /* The sequence of category id should be listed in ascending order */
{
    {MMI_CATEGORY5_ID, (U8 *) category5, (S16 *) coordinate_set5, NULL},
    {MMI_CATEGORY6_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY7_ID, (U8 *) category7, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY9_ID, (U8 *) category9, (S16 *) coordinate_set9, NULL},
    /* START VIJAY PMT 20050930 */
#ifdef UI_SMALL_LIST_SCREEN
    {MMI_CATEGORY10_ID, (U8 *) category10, (S16 *) coordinate_set10},
#endif 
    /* END VIJAY PMT 20050930 */
    {MMI_CATEGORY12_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY14_LIST_ID, (U8 *) category14_list, (S16 *) coordinate_set14_List_Page, NULL},
    {MMI_CATEGORY14_MATRIX_ID, (U8 *) category14_matrix, (S16 *) coordinate_set14_Matrix, NULL},
    {MMI_CATEGORY14_CIRCULAR_ID, (U8 *) category14_circular_3d, (S16 *) coordinate_set14_Circular, NULL},
    {MMI_CATEGORY14_ROTATE_ID, (U8 *) category14_circular_3d, (S16 *) coordinate_set14_Rotate, NULL},
    {MMI_CATEGORY15_LIST_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY15_MATRIX_ID, (U8 *) category15_matrix, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY16_ID, (U8 *) category16, (S16 *) coordinate_set16, NULL},
    {MMI_CATEGORY18_ID, (U8 *) category18, (S16 *) coordinate_set18, NULL},
    {MMI_CATEGORY19_ID, (U8 *) category19, (S16 *) coordinate_set19, NULL},
    {MMI_CATEGORY20_ID, (U8 *) category20, (S16 *) coordinate_set20, NULL},
    {MMI_CATEGORY21_ID, (U8 *) category21, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY22_ID, (U8 *) category22, (S16 *) coordinate_set22, NULL},
    {MMI_CATEGORY28_ID, (U8 *) category28, (S16 *) coordinate_set5, NULL},
    {MMI_CATEGORY32_ID, (U8 *) category32, (S16 *) coordinate_set32, NULL},
    {MMI_CATEGORY33_ID, (U8 *) category33, (S16 *) coordinate_set33, NULL},
    {MMI_CATEGORY34_ID, (U8 *) category34, (S16 *) coordinate_set34, NULL},
    {MMI_CATEGORY35_ID, (U8 *) category35, (S16 *) coordinate_set35, NULL},
#if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY36_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set,
     (S16 *) common_rotated_coordinate_set},
    {MMI_CATEGORY39_ID, (U8 *) category39, (S16 *) common_coordinate_set, (S16 *) common_rotated_coordinate_set},
    {MMI_CATEGORY52_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set,
     (S16 *) common_rotated_coordinate_set},
#else /* defined(__MMI_SCREEN_ROTATE__) */ 
    {MMI_CATEGORY36_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY39_ID, (U8 *) category39, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY52_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

    {MMI_CATEGORY57_ID, (U8 *) category57, (S16 *) coordinate_set57, NULL},
    {MMI_CATEGORY61_ID, (U8 *) category61, (S16 *) coordinate_set61, NULL},
    {MMI_CATEGORY62_ID, (U8 *) category62, (S16 *) coordinate_set62, NULL},
 #if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY64_ID, (U8 *) category64, (S16 *) coordinate_set64, (S16 *) rotated_coordinate_set64},
    {MMI_CATEGORY66_NORMAL_ID, (U8 *) category66_normal, (S16 *) coordinate_set66_normal,
     (S16 *) coordinate_set66_normal_rotated},
    {MMI_CATEGORY66_STATUS_ICON_ID, (U8 *) category66_status_icon, (S16 *) coordinate_set66_status_icon, NULL},
    {MMI_CATEGORY66_NONE_ID, (U8 *) category66_none, (S16 *) coordinate_set66_none, (S16 *) coordinate_set66_none_rotated},
    {MMI_CATEGORY67_ID, (U8 *) category67, (S16 *) coordinate_set67, (S16 *) rotated_coordinate_set67},
 #else /* defined(__MMI_SCREEN_ROTATE__) */ 
    {MMI_CATEGORY64_ID, (U8 *) category64, (S16 *) coordinate_set64, NULL},
    {MMI_CATEGORY66_NORMAL_ID, (U8 *) category66_normal, (S16 *) coordinate_set66_normal, NULL},
    {MMI_CATEGORY66_STATUS_ICON_ID, (U8 *) category66_status_icon, (S16 *) coordinate_set66_status_icon, NULL},
    {MMI_CATEGORY66_NONE_ID, (U8 *) category66_none, (S16 *) coordinate_set66_none, NULL},
    {MMI_CATEGORY67_ID, (U8 *) category67, (S16 *) coordinate_set67, NULL},
 #endif /* defined(__MMI_SCREEN_ROTATE__) */ 
    {MMI_CATEGORY69_ID, (U8 *) category69, (S16 *) coordinate_set69, NULL},
    {MMI_CATEGORY72_ID, (U8 *) category_control_category_normal_bg, (S16 *) category_controlled_coordinate_set, NULL},
    {MMI_CATEGORY73_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
 #if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY74_ID, (U8 *) category74, (S16 *) coordinate_set74, (S16 *) common_rotated_coordinate_set},
    {MMI_CATEGORY75_ID, (U8 *) category75, (S16 *) coordinate_set75, (S16 *) NULL},
    {MMI_CATEGORY76_ID, (U8 *) category74, (S16 *) coordinate_set74, (S16 *) common_rotated_coordinate_set},
    {MMI_CATEGORY77_ID, (U8 *) category77, (S16 *) coordinate_set77, NULL},
    {MMI_CATEGORY78_ID, (U8 *) category74, (S16 *) coordinate_set74, (S16 *) common_rotated_coordinate_set},
 #else /* defined(__MMI_SCREEN_ROTATE__) */ 
    {MMI_CATEGORY74_ID, (U8 *) category74, (S16 *) coordinate_set74, NULL},
    {MMI_CATEGORY75_ID, (U8 *) category75, (S16 *) coordinate_set75, NULL},
    {MMI_CATEGORY76_ID, (U8 *) category74, (S16 *) coordinate_set74, NULL},
    {MMI_CATEGORY77_ID, (U8 *) category77, (S16 *) coordinate_set77, NULL},
    {MMI_CATEGORY78_ID, (U8 *) category74, (S16 *) coordinate_set74, NULL},
 #endif /* defined(__MMI_SCREEN_ROTATE__) */ 
    {MMI_CATEGORY83_ID, (U8 *) category83, (S16 *) coordinate_set83, NULL},//072406 new calendar
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)    
    {MMI_CATEGORY83_ID_NO_STATUS, (U8 *) category83_no_status, (S16 *) coordinate_set83_no_status, NULL},
#endif    
    {MMI_CATEGORY84_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY85_ID, (U8 *) category85, (S16 *) coordinate_set85, NULL},//072406 new calendar
    {MMI_CATEGORY85_NO_BUTTON_ID, (U8 *) category85_no_button, (S16 *) coordinate_set85, NULL},//072406 new calendar
    {MMI_CATEGORY86_ID, (U8 *) category86, (S16 *) coordinate_set86, NULL},
    {MMI_CATEGORY88_1ITEM_ID, (U8 *) category88, (S16 *) coordinate_set88_1_item, NULL},
    {MMI_CATEGORY88_2ITEM_ID, (U8 *) category88, (S16 *) coordinate_set88_2_item, NULL},
    {MMI_CATEGORY88_3ITEM_ID, (U8 *) category88, (S16 *) coordinate_set88_3_item, NULL},
    {MMI_CATEGORY89_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY90_ID, (U8 *) category_control_category_normal, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY91_ID, (U8 *) category91, (S16 *) coordinate_set91, NULL},
    {MMI_CATEGORY95_ID, (U8 *) category95, (S16 *) coordinate_set95, NULL},
    /* START VIJAY PMT 20050930 */
 #ifdef UI_SMALL_CATEGORY_EDITOR
    {MMI_CATEGORY100_ID, (U8 *) category100, (S16 *) coordinate_set100},
 #endif 
    /* END VIJAY PMT 20050930 */
    {MMI_CATEGORY105_ID, (U8 *) category105, (S16 *) coordinate_set105, NULL},
    {MMI_CATEGORY109_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY111_ID, (U8 *) category111, (S16 *) coordinate_set111, NULL},
    /* START VIJAY PMT 20050930 */
 #ifdef UI_SMALL_PIN_EDITOR_SCREEN
    {MMI_CATEGORY112_ID, (U8 *) category112, (S16 *) coordinate_set112},
 #endif 
    /* END VIJAY PMT 20050930 */
    {MMI_CATEGORY119_ID, (U8 *) category119, (S16 *) coordinate_set119, NULL},
    {MMI_CATEGORY120_ID, (U8 *) category120, (S16 *) coordinate_set120, NULL},
    {MMI_CATEGORY121_ID, (U8 *) category121, (S16 *) coordinate_set121, NULL},
    {MMI_CATEGORY122_ID, (U8 *) category122, (S16 *) coordinate_set122, NULL},
    {MMI_CATEGORY123_ID, (U8 *) category123, (S16 *) coordinate_set123, NULL},
    {MMI_CATEGORY125_ID, (U8 *) base_control_set_with_list_and_category_control,
     (S16 *) coordinate_set_base_control_set_with_list_and_category_control, NULL},
    {MMI_CATEGORY128_ID, (U8 *) category128, (S16 *) coordinate_set128, NULL},
    {MMI_CATEGORY129_ID, (U8 *) category129, (S16 *) coordinate_set129, NULL},
    {MMI_CATEGORY130_ID, (U8 *) category130, (S16 *) coordinate_set130, NULL},
    {MMI_CATEGORY131_ID, (U8 *) category131, (S16 *) coordinate_set131, NULL},
    {MMI_CATEGORY132_ID, (U8 *) category132, (S16 *) coordinate_set132, NULL},
    {MMI_CATEGORY140_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY141_ID, (U8 *) category141_normal, (S16 *) coordinate_set141, NULL},
    {MMI_CATEGORY141_STATUS_ICON_ID, (U8 *) category141_status_icon, (S16 *) coordinate_set141_status_icon, NULL},
    {MMI_CATEGORY142_ID, (U8 *) category_control_category_normal, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY142_STATUS_ICON_ID, (U8 *) category_control_category_status_icon,
     (S16 *) category_control_coordinate_set_status_icon, NULL},
    {MMI_CATEGORY143_ID, (U8 *) category_control_category_normal_bg, (S16 *) category_controlled_coordinate_set, NULL},
    {MMI_CATEGORY144_ID, (U8 *) category_control_category_normal_bg, (S16 *) category_controlled_coordinate_set},
    {MMI_CATEGORY145_ID, (U8 *) category_control_category_normal, (S16 *) category_controlled_coordinate_set, NULL},
 #ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN
    {MMI_CATEGORY146_ID, (U8 *) category146, (S16 *) coordinate_set146},
 #endif 
    {MMI_CATEGORY150_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY151_ID, (U8 *) category151, (S16 *) coordinate_set151, NULL},
    {MMI_CATEGORY152_ID, (U8 *) category152, (S16 *) coordinate_set152, NULL},
    {MMI_CATEGORY154_ID, (U8 *) category154_normal, (S16 *) coordinate_set154_normal, NULL},
    {MMI_CATEGORY154_STATUS_ICON_ID, (U8 *) category154_status_icon, (S16 *) coordinate_set154_status_icon, NULL},
    {MMI_CATEGORY157_ID, (U8 *) category157, (S16 *) coordinate_set157, NULL},
    {MMI_CATEGORY162_ID, (U8 *) category162, (S16 *) coordinate_set162, NULL},
 #if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY164_ID, (U8 *) category164, (S16 *) coordinate_set164, (S16 *) rotated_coordinate_set164},
 #else 
    {MMI_CATEGORY164_ID, (U8 *) category164, (S16 *) coordinate_set164, NULL},
 #endif 
    {MMI_CATEGORY166_ID, (U8 *) category166, (S16 *) coordinate_set166, NULL},
    {MMI_CATEGORY170_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY171_ID, (U8 *) category171, (S16 *) coordinate_set171, NULL},
    {MMI_CATEGORY172_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY174_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY184_ID, (U8 *) dynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY186_ID, (U8 *) dynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY200_ID, (U8 *) category200, (S16 *) coordinate_set200, NULL},
    {MMI_CATEGORY201_ID, (U8 *) category201, (S16 *) coordinate_set201, NULL},
    {MMI_CATEGORY204_ID, (U8 *) category204, (S16 *) coordinate_set204, NULL},
    {MMI_CATEGORY205_ID, (U8 *) category205, (S16 *) coordinate_set205, NULL},
    {MMI_CATEGORY212_ID, (U8 *) category212, (S16 *) coordinate_set212, NULL},
    {MMI_CATEGORY213_ID, (U8 *) category213, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY214_ID, (U8 *) category214, (S16 *) common_coordinate_set, NULL},
 #if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY221_ID, (U8 *) category221, (S16 *) coordinate_set221, (S16 *) rotated_coordinate_set221},
 #else 
    {MMI_CATEGORY221_ID, (U8 *) category221, (S16 *) coordinate_set221, NULL},
 #endif 
    {MMI_CATEGORY222_ID, (U8 *) category222, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY223_ID, (U8 *) category221, (S16 *) coordinate_set221, NULL},
#if 0         
 #if defined ( __MMI_SCREEN_ROTATE__)
/* under construction !*/
/* under construction !*/
 #else /* defined ( __MMI_SCREEN_ROTATE__) */ 
/* under construction !*/
/* under construction !*/
 #endif /* defined ( __MMI_SCREEN_ROTATE__) */ 
#endif 
    {MMI_CATEGORY227_ID, (U8 *) category227Screen, (S16 *) coordinate_set227, NULL},
    {MMI_CATEGORY228_ID, (U8 *) category74, (S16 *) coordinate_set74, NULL},
    {MMI_CATEGORY229_ID, (U8 *) category229, (S16 *) coordinate_set229, NULL},
#if defined ( __MMI_MAINLCD_240X320__) || defined ( __MMI_MAINLCD_320X240__)
    {MMI_CATEGORY230_ID, (U8 *) category230Screen, (S16 *) coordinate_set230, NULL},//052206 NITZ category Calvin
 #endif
    {MMI_CATEGORY257_ID, (U8 *) category257, (S16 *) coordinate_set257, NULL},
    {MMI_CATEGORY261_ID, (U8 *) asyncdynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY262_ID, (U8 *) asyncdynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY263_ID, (U8 *) category263, (S16 *) coordinate_set263, NULL},
    {MMI_CATEGORY264_ID, (U8 *) category264, (S16 *) coordinate_set264, NULL},
#ifdef __MMI_CAT265_SUPPORT__//051507 channel list
    {MMI_CATEGORY265_ID, (U8 *) category265, (S16 *) coordinate_set265, NULL},
#endif
 #ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    {MMI_CATEGORY273_ID, (U8 *) dynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
 #endif 
    {MMI_CATEGORY275_ID, (U8 *) category275, (S16 *) coordinate_set275, NULL},
    {MMI_CATEGORY276_ID, (U8 *) category276, (S16 *) coordinate_set276, NULL},
#ifdef __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__
	{MMI_CATEGORY280_ID, (U8 *) category280, (S16 *) coordinate_set280, NULL},
#endif /* __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__ */
 #ifdef __MMI_SUBLCD__
    {MMI_CATEGORY301_ID, (U8 *) category301, (S16 *) coordinate_set301, NULL},
    {MMI_CATEGORY303_ID, (U8 *) category303, (S16 *) coordinate_set303, NULL},
    {MMI_CATEGORY304_ID, (U8 *) category304, (S16 *) coordinate_set304, NULL},
 #endif /* __MMI_SUBLCD__ */ 
    {MMI_CATEGORY305_ID, (U8 *) category305, (S16 *) coordinate_set305, NULL},
    {MMI_CATEGORY306_ID, (U8 *) category306, (S16 *) coordinate_set306, NULL},
    {MMI_CATEGORY307_ID, (U8 *) category307, (S16 *) coordinate_set307, NULL},
 #ifdef __MMI_SUBLCD__
    {MMI_CATEGORY310_ID, (U8 *) category310, (S16 *) coordinate_set310, NULL},
    {MMI_CATEGORY311_ID, (U8 *) category311, (S16 *) coordinate_set311, NULL},
    {MMI_CATEGORY312_ID, (U8 *) category312, (S16 *) coordinate_set312, NULL},
    {MMI_CATEGORY313_ID, (U8 *) category313, (S16 *) coordinate_set313, NULL},
    {MMI_CATEGORY314_ID, (U8 *) category314, (S16 *) coordinate_set314, NULL},
    {MMI_CATEGORY315_ID, (U8 *) category315, (S16 *) coordinate_set315, NULL},
 #endif /* __MMI_SUBLCD__ */ 
    /* PMT Pankaj Start 12042005 */
    {MMI_CATEGORY334_ID, (U8 *) category334, (S16 *) coordinate_set334, NULL},
    /* PMT Pankaj End */
    {MMI_CATEGORY357_ID, (U8 *) category357, (S16 *) coordinate_set357, NULL},
#ifdef __MMI_DUAL_SIM_MASTER__
#if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY363_ID, (U8 *) category363, (s16 *) list_coordinate_set, (s16 *) common_rotated_coordinate_set},
#else /* __MMI_SCREEN_ROTATE__ */
    {MMI_CATEGORY363_ID, (U8 *) category363, (s16 *) list_coordinate_set, NULL},
#endif /* __MMI_SCREEN_ROTATE__ */
#endif   /* __MMI_DUAL_SIM_MASTER__ */    
    {MMI_CATEGORY384_ID, (U8 *) category384, (S16 *) coordinate_set384, NULL},
    {MMI_CATEGORY402_ID, (U8 *) category402, (S16 *) coordinate_set402, NULL},
    {MMI_CATEGORY403_ID, (U8 *) category403, (S16 *) coordinate_set403, NULL},
    {MMI_CATEGORY404_ID, (U8 *) category404, (S16 *) coordinate_set404, NULL},
    {MMI_CATEGORY412_ID, (U8 *) category412, (S16 *) coordinate_set412, NULL},
    {MMI_CATEGORY414_ID, (U8 *) category414, (S16 *) coordinate_set414, NULL},
    {MMI_CATEGORY420_ID, (U8 *) category420, (S16 *) coordinate_set420, NULL},
    {MMI_CATEGORY425_ID, (U8 *) category425, (S16 *) coordinate_set425, NULL},
    {MMI_CATEGORY425_NO_TAB_ID, (U8 *) category425_no_tab, (S16 *) coordinate_set425_no_tab, NULL},
#ifndef __MMI_MAINLCD_128X128__
    {MMI_CATEGORY426_ID, (U8 *) category426, (S16 *) coordinate_set426, NULL},
#endif
    {MMI_CATEGORY427_ID, (U8 *) asyncdynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY430_ID, (U8 *) category430, (S16 *) coordinate_set430, NULL},
#ifdef __MMI_BROWSER_2__
    {MMI_CATEGORY431_ID, (U8 *) category431, (S16 *) coordinate_set431, NULL},
    {MMI_CATEGORY431_FULL_ID, (U8 *) category431_fullscreen, (S16 *) coordinate_set431_fullscreen, NULL},
#endif /* __MMI_BROWSER_2__ */
    {MMI_CATEGORY435_ID, (U8 *) category435, (S16 *) coordinate_set435, NULL},
#ifdef __MMI_CAT44X_SUPPORT__        
    {MMI_CATEGORY440_ID, (U8 *) category440, (S16 *) coordinate_set440, NULL},
    {MMI_CATEGORY443_ID, (U8 *) category443, (S16 *) coordinate_set443, NULL},
    {MMI_CATEGORY445_ID, (U8 *) category445, (S16 *) coordinate_set445, NULL},    
    {MMI_CATEGORY447_ID, (U8 *) category447, (S16 *) coordinate_set447, NULL},  
    {MMI_CATEGORY448_ID, (U8 *) category448, (S16 *) coordinate_set448, NULL}, 
    {MMI_CATEGORY449_ID, (U8 *) category449, (S16 *) coordinate_set449, NULL}, 
#endif /* __MMI_CAT44X_SUPPORT__ */ 
    {MMI_CATEGORY525_ID, (U8 *) category525, (S16 *) coordinate_set525, NULL},
    {MMI_CATEGORY620_ID, (U8 *) category620, (S16 *) coordinate_set620, NULL},
#ifdef __UI_MMS_VIEWER_CATEGORY__
    {MMI_CATEGORY630_ID, (U8 *) category630, (S16 *) coordinate_set630, NULL},
#endif
    {MMI_CATEGORY_EMS_ID, (U8 *) categoryEMS, (S16 *) coordinate_setEMS, NULL},
    {MMI_CATEGORY_WCLOCK, (U8 *) categoryWcScreen, (S16 *) coordinate_WcScreen, NULL},
    {MMI_CATEGORY_VDOPLY, (U8 *) categoryVdoScreen, (S16 *) coordinate_VdoScreen, NULL},
    {MMI_CATEGORY_VDOPLY_BUTTON, (U8 *) categoryVdoScreen_button, (S16 *) coordinate_VdoScreen_button, NULL},
    {MMI_CATEGORY_NSM275, (U8 *) categoryNSM275, (S16 *) coordinate_setNSM275, NULL},
    {MMI_CATEGORY626_ID, (U8 *) category626, (S16 *) coordinate_set626, NULL},
    {MMI_CATEGORY657_ID, (U8 *) category657, (S16 *) coordinate_set657, NULL}
};

//This array must contain sorted screen ids, since binary search will be used on this array
//const S16 g_screenid_coordinate_sets_map_entries_count = 70;

const dm_screen_id_coordinate_set_map_struct g_screenid_coordinate_sets_map[] = 
{
#ifndef UI_SMALL_CATEGORY_EDITOR
    {SCR_SEARCH_NAME_ENTRY, (S16 *) coordinate_set5},
#endif 
#if defined(__MMI_CALORIE__)
/* under construction !*/
#endif 

#if defined(__MMI_MENSTRUAL__)
    {SCR_ID_MENS_WELCOME, (S16 *) coordinate_set129_no_button}, /* 5901 */
#endif 

#if defined(__MMI_BMI__)
    {SCR_BMI_WELCOME, (S16 *) coordinate_set129_no_button}, /* 5951 */
#endif 
#if defined(__MMI_DICTIONARY_WELCOME_SCREEN__)
    {SCR_DICTIONARY_WELCOME_SCREEN, (S16 *) coordinate_set129_no_button}, /* 5951 */
#endif 
#ifdef __MMI_FACTORY_MODE__ //080106 cat57
    {SCR_ID_FM_CAMERA, (S16 *) coordinate_set57_top_infobox}, /* 28643 */
#endif

#if defined(__DOWNLOAD__)
    {SCR_IMAGEVIEW, (S16 *) coordinate_set129_no_button},   /* 29010 */
#endif 
#if defined(__MMI_DICTIONARY__)
    {SCR_DICTIONARY_WELCOME_SCREEN, (S16 *) coordinate_set129_no_button},       /* 39156 */
#endif 
    {SCR_ID_PHOART_TEXT_SELECT, (S16 *) coordinate_set57_top_infobox}
};

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  dm_get_coordinate_sets_count
 * DESCRIPTION
 *  get coordiante set address by category id
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of corresponding coordinate set
 *****************************************************************************/
S32 dm_get_coordinate_sets_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(g_screenid_coordinate_sets_map) / sizeof(dm_screen_id_coordinate_set_map_struct);
}   /* end of dm_get_screenid_coordinate_sets_map_entries_count */


/*****************************************************************************
 * FUNCTION
 *  dm_get_control_sets_count
 * DESCRIPTION
 *  get coordiante set address by category id
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of corresponding coordinate set
 *****************************************************************************/
S32 dm_get_control_sets_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(g_categories_controls_map) / sizeof(dm_category_id_control_set_map_struct);
}   /* end of dm_get_screenid_coordinate_sets_map_entries_count */


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_control_set
 * DESCRIPTION
 *  get address of base control set
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of base control set
 *****************************************************************************/
U8 *dm_get_base_control_set(void)
{
#ifdef __MMI_SCREEN_ROTATE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_is_screen_width_height_swapped())
    {
        return (U8*) dm_base_rotated_control_set;
    }
    else
    {
        return (U8*) dm_base_control_set;
    }
#else /* __MMI_SCREEN_ROTATE__ */ 
    return (U8*) dm_base_control_set;
#endif /* __MMI_SCREEN_ROTATE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_coordinate_set
 * DESCRIPTION
 *  get address of base coordinate set
 * PARAMETERS
 *  void
 * RETURNS
 *  address of base coordinate set
 *****************************************************************************/
S16 *dm_get_base_coordinate_set(void)
{
#ifdef __MMI_SCREEN_ROTATE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_is_screen_width_height_swapped())
    {
        return (S16*) dm_base_rotated_coordinate_set;
    }
    else
    {
        return (S16*) dm_base_coordinate_set;
    }
#else /* __MMI_SCREEN_ROTATE__ */ 
    return (S16*) dm_base_coordinate_set;
#endif /* __MMI_SCREEN_ROTATE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_control_set2
 * DESCRIPTION
 *  get address of base control set 2
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of base control set 2
 *****************************************************************************/
U8 *dm_get_base_control_set2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) dm_base_control_set2;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_coordinate_set2
 * DESCRIPTION
 *  get address of base coordinate set 2
 * PARAMETERS
 *  void
 * RETURNS
 *  address of base coordinate set 2
 *****************************************************************************/
S16 *dm_get_base_coordinate_set2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S16*) dm_base_coordinate_set2;
}


#if defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
/*****************************************************************************
 * FUNCTION
 *  dm_get_base_control_set_submenu
 * DESCRIPTION
 *  get address of base control set of submenu
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of base control set of submenu
 *****************************************************************************/
U8 *dm_get_base_control_set_submenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) dm_base_control_set_submenu;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_coordinate_set_submenu
 * DESCRIPTION
 *  get address of base coordinate set of submenu
 * PARAMETERS
 *  void
 * RETURNS
 *  address of base coordinate set of submenu
 *****************************************************************************/
S16 *dm_get_base_coordinate_set_submenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S16*) dm_base_coordinate_set_submenu;
}
#endif /* defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */


#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
/*****************************************************************************
 * FUNCTION
 *  dm_get_base_control_set_common
 * DESCRIPTION
 *  get address of base control set of common
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of base control set of common
 *****************************************************************************/
U8 *dm_get_base_control_set_common(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) dm_base_control_set_common;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_coordinate_set_COMMON
 * DESCRIPTION
 *  get address of base coordinate set of COMMON
 * PARAMETERS
 *  void
 * RETURNS
 *  address of base coordinate set common
 *****************************************************************************/
S16 *dm_get_base_coordinate_set_common(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S16*) dm_base_coordinate_set_common;
}
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */


#endif /* __MMI_DRAW_MANAGER__ */ /* end of __MMI_DRAW_MANAGER__ */
