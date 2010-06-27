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
 * BTMMIHIDScr.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MMI screen of bluetooth HID application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#include "CommonScreens.h"
#include "MainMenuDef.h"        /* for MAIN_MENU_TITLE_EXTRA_APP_ICON  */
#include "SettingProfile.h"     /* for tone ID */

#ifdef __MMI_BT_MTK_SUPPORT__
#ifdef __MMI_HIDD_SUPPORT__

#include "BTMMICm.h"
#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"
#include "BTMMIHidScr.h"
#include "BTMMIHidScrGprots.h"

#include "BTMMIHidd.h"
#include "BTMMIHiddGprots.h"

/* Trace Header Files */


#include "ExtDeviceDefs.h"
#include "CallManagementGprot.h" /*GetCmMarkerScrnID*/
#include "gpioInc.h"    /* TurnOnBacklight */

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern U8 g_enable_pts_test;

/***************************************************************************** 
* External functions
*****************************************************************************/
/***************************************************************************** 
* Globol Variable
*****************************************************************************/
mmi_bt_hid_scr_cntx_struct g_mmi_bt_hid_scr_cntx;
U8  delay_repeat_event = 0;
U8 hid_key_cmd[MMI_HID_MAX_CTRL_DATA_LENGHT]={0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const mmi_bt_hid_key_control_data_struct hid_control_data_desktop[MMI_HID_NUM_OF_CTRL_DATA]=
{
 { KEY_1, 				KEY_EVENT_UP, {0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },                              
 { KEY_2, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_3, 				KEY_EVENT_UP, {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },                              
 { KEY_4, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_5, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_6, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_7, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_8, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_9, 				KEY_EVENT_UP, {0x01, 0x04, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00} }, /* NULL */
 { KEY_STAR, 			KEY_EVENT_UP, {0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} }, 
 { KEY_0, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_POUND, 		    KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },/* NULL */
 { KEY_UP_ARROW, 		KEY_EVENT_UP, {0x02, 0x00, 0x00, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00} },                             
 { KEY_DOWN_ARROW, 	    KEY_EVENT_UP, {0x02, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00} },                              
 { KEY_LEFT_ARROW, 	    KEY_EVENT_UP, {0x02, 0x00, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },                             
 { KEY_RIGHT_ARROW, 	KEY_EVENT_UP, {0x02, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },                              
 { KEY_UP_ARROW, 		KEY_REPEAT, 	{0x02, 0x00, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00} },                             
 { KEY_DOWN_ARROW, 	    KEY_REPEAT, 	{0x02, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00} },                              
 { KEY_LEFT_ARROW, 	    KEY_REPEAT, 	{0x02, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },                             
 { KEY_RIGHT_ARROW, 	KEY_REPEAT, 	{0x02, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} }                              
 
};

const mmi_bt_hid_key_control_data_struct hid_control_data_media_player[MMI_HID_NUM_OF_CTRL_DATA]=
{
 { KEY_1, 				KEY_EVENT_UP, {0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_2, 				KEY_EVENT_UP, {0x01, 0x01, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_3, 				KEY_EVENT_UP, {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_4, 				KEY_EVENT_UP, {0x01, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_5, 				KEY_EVENT_UP, {0x01, 0x01, 0x00, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_6, 				KEY_EVENT_UP, {0x01, 0x01, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_7, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_8, 				KEY_EVENT_UP, {0x01, 0x04, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_9, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} }, /* NULL */
 { KEY_STAR, 			KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00} }, 
 { KEY_0, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_POUND, 		    KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },/* NULL */
 { KEY_UP_ARROW, 		KEY_EVENT_UP, {0x02, 0x00, 0x00, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_DOWN_ARROW, 	    KEY_EVENT_UP, {0x02, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_LEFT_ARROW, 	    KEY_EVENT_UP, {0x02, 0x00, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },    
 { KEY_RIGHT_ARROW, 	KEY_EVENT_UP, {0x02, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_UP_ARROW, 		KEY_REPEAT, 	{0x02, 0x00, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00} },                             
 { KEY_DOWN_ARROW, 	    KEY_REPEAT, 	{0x02, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00} },                              
 { KEY_LEFT_ARROW, 	    KEY_REPEAT, 	{0x02, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },                             
 { KEY_RIGHT_ARROW, 	KEY_REPEAT, 	{0x02, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} }                              
 
 
};

const mmi_bt_hid_key_control_data_struct hid_control_data_presenter[MMI_HID_NUM_OF_CTRL_DATA]=
{
 { KEY_1, 				KEY_EVENT_UP, {0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_2, 				KEY_EVENT_UP, {0x02, 0x00, 0x00, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_3, 				KEY_EVENT_UP, {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_4, 				KEY_EVENT_UP, {0x02, 0x00, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_5, 				KEY_EVENT_UP, {0x02, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_6, 				KEY_EVENT_UP, {0x02, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_7, 				KEY_EVENT_UP, {0x01, 0x02, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_8, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_9, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_STAR, 			KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00} }, 
 { KEY_0, 				KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_POUND, 		    KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },/* NULL */
 { KEY_UP_ARROW, 		KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x4B, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_DOWN_ARROW, 	    KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x4E, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_LEFT_ARROW, 	    KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x00, 0x00, 0x00} },    
 { KEY_RIGHT_ARROW, 	KEY_EVENT_UP, {0x01, 0x00, 0x00, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x00} },    
 { KEY_2, 				KEY_REPEAT, 	{0x02, 0x00, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_4, 				KEY_REPEAT, 	{0x02, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_5, 				KEY_REPEAT, 	{0x02, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_6, 				KEY_REPEAT, 	{0x02, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} }
 
};

#if defined(__MMI_MAINLCD_128X128__)
const S32 hid_icon_pos[17][4] = {  
						{  5,  48, 39 , 15},
                    { 45,  48, 39 , 15},
                    { 83,  48, 39 , 15},
                    {  5,  62, 39 , 15},
                    { 45,  62, 39 , 15},
                    { 83,  62, 39 , 15},
                    {  5,  77, 39 , 15},
                    { 45,  77, 39 , 15},
                    { 83,  77, 39 , 15},
                    {  5,  92, 39 , 15},
                    { 45,  92, 39 , 15},
                    { 83,  92, 39 , 15},
                    { 42,  15, 43, 16},
                    { 42,  31, 43, 16},
                    { 23,  19, 20, 23},
                    { 85,  19, 20, 23},
                    { 42,  31, 43, 16}    };
#elif defined(__MMI_MAINLCD_128X160__)
const S32 hid_icon_pos[17][4] = {  
						{  5,  66, 39 , 18},
                    { 44,  66, 39 , 18},
                    { 83,  66, 39 , 18},
                    {  5,  84, 39 , 18},
                    { 44,  84, 39 , 18},
                    { 83,  84, 39 , 18},
                    {  5, 103, 39 , 18},
                    { 44, 103, 39 , 18},
                    { 83, 103, 39 , 18},
                    {  5, 121, 39 , 18},
                    { 44, 121, 39 , 18},
                    { 83, 121, 39 , 18},
                    { 42,  23, 43, 14},
                    { 42,  50, 43, 14},
                    { 21,  27, 20, 33},
                    { 85,  27, 20, 33},
                    { 42,  37, 43, 13}    };
#elif defined(__MMI_MAINLCD_176X220__)
const S32 hid_icon_pos[17][4] = {  
						{ 38,  98, 32 , 22},
                    { 72,  98, 32 , 22},
                    {107,  98, 32 , 22},
                    { 38, 121, 32 , 22},
                    { 72, 121, 32 , 22},
                    {107, 121, 32 , 22},
                    { 38, 146, 32 , 22},
                    { 72, 146, 32 , 22},
                    {107, 146, 32 , 22},
                    { 38, 169, 32 , 22},
                    { 72, 169, 32 , 22},
                    {107, 169, 32 , 22},
                    { 78,  24, 24, 23},
                    { 78,  71, 24, 23},
                    { 55,  47, 23, 24},
                    {102,  47, 23, 24},
                    { 78,  47, 24, 24}    };
#elif defined(__MMI_MAINLCD_240X320__)
const S32 hid_icon_pos[17][4] = {  
					   { 55, 143, 40 , 33},
                    {100, 143, 40 , 33},
                    {145, 143, 40 , 33},
                    { 55, 180, 40 , 33},
                    {100, 180, 40 , 33},
                    {145, 180, 40 , 33},
                    { 55, 215, 40 , 33},
                    {100, 215, 40 , 33},
                    {143, 215, 40 , 33},
                    { 55, 251, 40 , 33},
                    {100, 251, 40 , 33},
                    {145, 251, 40 , 33},
                    {106,  41, 33, 29},
                    {106, 108, 33, 29},
                    { 74,  73, 31, 33},
                    {140,  73, 31, 33},
                    {106,  73, 33, 33}    };
#elif defined(__MMI_MAINLCD_320X240__)
const S32 hid_icon_pos[17][4] = {  
					   { 41, 104, 77 , 27},
                    {125, 104, 77 , 27},
                    {210, 104, 77 , 27},
                    { 41, 130, 77 , 27},
                    {125, 130, 77 , 27},
                    {210, 130, 77 , 27},
                    { 41, 158, 77 , 27},
                    {125, 158, 77 , 27},
                    {210, 158, 77 , 27},
                    { 41, 184, 77 , 27},
                    {125, 184, 77 , 27},
                    {210, 184, 77 , 27},
                    {125,  37, 74, 24},
                    {125, 78, 74, 24},
                    { 82,  48, 39, 47},
                    {203,  48, 39, 47},
                    {149,  62, 19, 15}    };
#endif
/***************************************************************************** 
* Functions
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hid_scr_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hid_scr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mmi_bt_hid_scr_cntx, 0, sizeof(mmi_bt_hid_scr_cntx_struct));
    mmi_bt_hid_scr_init_menu_highlight_hdlr();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_init_menu_highlight_hdlr
 * DESCRIPTION
 *  This function is to initialize the mmi bt hightlight handler.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hid_scr_init_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_CONN_BT_REMOTE_CONTROL, mmi_bt_remote_control_menu_hilight_handler);
    SetHintHandler(MENU_CONN_BT_REMOTE_CONTROL, mmi_bt_remote_control_menu_hint_handler);
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_remote_control_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_remote_control_menu_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_BT_HILIGHT_HDLR();
    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_bt_entry_remote_control, KEY_EVENT_UP);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_remote_control_menu_hint_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  index       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_remote_control_menu_hint_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 hintStr[60]; /* string buffer for BD_ADDR: %02x:%02x:%02x:%02x:%02x:%02x string */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* BT address: NAP, UAP, LAP */
    if (g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap == 0 &&
        g_mmi_bth_hidd_cntx.last_connected_bd_addr.uap == 0 && 
        g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap == 0 )
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8)L""/*GetString(STR_BT_REMOTE_CTRL_NO_LAST_DEV_INFO)*/);
    }
    else
    {
        kal_wsprintf(
	        (U16*) hintStr,
	        "BD_ADDR: %02x:%02x:%02x:%02x:%02x:%02x",
	        ((g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap & 0xff00) >> 8),
	        (g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap & 0x00ff),
	        (g_mmi_bth_hidd_cntx.last_connected_bd_addr.uap),
	        ((g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap & 0xff0000) >> 16),
	        ((g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap & 0x00ff00) >> 8),
	        (g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap & 0x0000ff));
        mmi_ucs2cpy((PS8) hintData[index], (PS8)hintStr);
    }



}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth__hidd_add_history_before_cm_marker
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hid_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = scrn_id;
    Scr.entryFuncPtr = func_ptr;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) L"");

    InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), Scr);
}

void mmi_bt_hid_conn_confirm(void)
{
    mmi_bt_hid_entry_conn_confirm_scr();
    playRequestedTone(WARNING_TONE);
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_entry_conn_confirm_scr
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_entry_conn_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dev_name_tmp[MMI_BT_SCR_BD_NAME_LEN];
    U8 cnf_str[140];   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_HID_LOG(MMI_BT_HID_ENTRY_CONN_CONFIRM_SCR);
    memset(dev_name_tmp, 0, MMI_BT_SCR_BD_NAME_LEN);

    /* common notify string */
    kal_wstrcpy((U16*) cnf_str, (U16*) GetString(STR_BT_REMOTE_CTRL_CONN_AUTH));

    /* build dev_name string */
    mmi_bth_hidd_get_dev_name(dev_name_tmp);
    kal_wstrcat((U16*) cnf_str, (U16*) L" ");
    kal_wstrcat((U16*) cnf_str, (U16*) dev_name_tmp);
    kal_wstrcat((U16*) cnf_str, (U16*) L"?");

    EntryNewScreen(SCR_BT_REMOTE_CONTROL_CONN_REQ, NULL, mmi_bt_hid_entry_conn_confirm_scr, NULL);

    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_CONN_REQ, NULL);
    DeleteScreenIfPresent(SCR_BT_REMOTE_CONTROL_CONN_REQ);

    ShowCategory7Screen(
        STR_BT_MENU_TITLE,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (U8*) cnf_str,
        NULL);

    SetLeftSoftkeyFunction(mmi_bth_hidd_accept_conn, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bth_hidd_reject_conn, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_CONN_REQ, mmi_bth_hidd_authorize_confirm_del_cb);
    TurnOnBacklight(1);
}


/*****************************************************************************
* FUNCTION
*  mmi_bt_entry_remote_control
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_entry_remote_control(void)
{
#ifndef __MMI_HID_PAIRED_DEV_MENU__

    /* to avoid the twice operation while bt is just on and wanna enter remote control menu */
    mmi_bt_unmask_scr_extended_flag(MMI_BT_EXT_CONFIRM_POWER_ON);

    if (mmi_bt_is_power_on(MMI_FALSE) == MMI_FALSE)
    {
        mmi_bt_entry_hid_power_on_confirm();
        //mmi_bt_power_on_confirm(MMI_BT_EXT_CONFIRM_POWER_ON, mmi_bt_entry_power_switch, void (*rsk_func_ptr) (void), void (*endkey_func_ptr) (void), mmi_bt_entry_remote_control)
        return;           
    }


    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* prohibited by simap, shall deactivate simap first */
    if (mmi_bt_is_simap_server_activate())
    {
        mmi_bt_popup_prohibited_by_simap();
        return;
    }

    if (g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap == 0 &&
        g_mmi_bth_hidd_cntx.last_connected_bd_addr.uap == 0 && 
        g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap == 0 )
    {
        mmi_bt_hid_no_last_dev_info();
    }
    else
    {
        mmi_bt_hid_connect_last_dev();
    }


#else

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ItemList[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_REMOTE_CONTROL, NULL, mmi_bt_entry_remote_control, NULL);

    if ((mmi_bt_is_hw_ready) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* to avoid the error operation while bt module is busy */
    if ((mmi_bt_is_permission) (MMI_TRUE) == MMI_FALSE)
    {
        return;
    }

    /* prohibited by simap, shall deactivate simap first */
    if (mmi_bt_is_simap_server_activate())
    {
        mmi_bt_popup_prohibited_by_simap();
        return;
    }


    guiBuffer = GetCurrGuiBuffer(SCR_BT_REMOTE_CONTROL);

    /* BT address: NAP, UAP, LAP */
    if (g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap == 0 &&
        g_mmi_bth_hidd_cntx.last_connected_bd_addr.uap == 0 && 
        g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap == 0 )
    {
        hintDataPtrs[0] = NULL;
    }
    else
    {
        kal_wsprintf(
            (U16*) hintData[0],
            "BD_ADDR: %02x:%02x:%02x:%02x:%02x:%02x",
            ((g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap & 0xff00) >> 8),
            (g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap & 0x00ff),
            (g_mmi_bth_hidd_cntx.last_connected_bd_addr.uap),
            ((g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap & 0xff0000) >> 16),
            ((g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap & 0x00ff00) >> 8),
            (g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap & 0x0000ff));
        
        hintDataPtrs[0] = hintData[0];
    }
    ItemList[0] = (U8*)GetString(STR_BT_REMOTE_CTRL_LAST_DEV);
    nItems = 2;
    hintDataPtrs[1] = NULL;
    ItemList[1] = (U8*)GetString(STR_BT_REMOTE_CTRL_PAIRED_DEV);

        

    SetParentHandler(MENU_CONN_BT_MAIN);

    RegisterHighlightHandler(mmi_bt_remote_control_hilite_hdlr);
    
    ShowCategory53Screen(
        STR_BT_REMOTE_CONTROL,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        (U8 **) ItemList,
        (PU16) gIndexIconsImageList,
        hintDataPtrs,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif    
}
/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_remote_control
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_exit_remote_control(void);
/*****************************************************************************
* FUNCTION
*  mmi_bt_remote_control_hilite_hdlr
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_remote_control_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, idx);

    switch (idx)
    {
        case 0:
            if (g_mmi_bth_hidd_cntx.last_connected_bd_addr.nap == 0 &&
                g_mmi_bth_hidd_cntx.last_connected_bd_addr.uap == 0 && 
                g_mmi_bth_hidd_cntx.last_connected_bd_addr.lap == 0 )
            {
                SetLeftSoftkeyFunction(mmi_bt_hid_no_last_dev_info, KEY_EVENT_UP);
            }
            else
            {
                SetLeftSoftkeyFunction(mmi_bt_hid_connect_last_dev, KEY_EVENT_UP);
            }
           break;
           
        case 1:
            SetLeftSoftkeyFunction(mmi_bt_entry_remote_control_device_select_screen, KEY_EVENT_UP);
            break;
        default:
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
            break;
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_entry_hid_power_on_confirm
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_entry_hid_power_on_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_store_endkey_hdlr();

    mmi_bt_mask_scr_extended_flag(MMI_BT_EXT_CONFIRM_POWER_ON);
    mmi_bt_register_power_on_callback(mmi_bt_entry_remote_control);
    
    mmi_bt_show_confirm_scr(
        SCR_BT_REMOTE_CONTROL_POWER_ON_CONFIRM,
        STR_BT_PWR_ON_CNF,
        mmi_bt_exit_hid_power_on_confirm,
        mmi_bt_entry_hid_power_on_confirm);
    SetLeftSoftkeyFunction(mmi_bt_entry_power_switch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bt_hid_power_on_confirm_goback, KEY_EVENT_UP);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_hid_power_on_confirm_endkey, KEY_END, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_POWER_ON_CONFIRM, (HistoryDelCBPtr) mmi_bt_hid_power_on_confirm_del_cb);


}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_hid_power_on_confirm
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_exit_hid_power_on_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_clear_endkey_hdlr();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hid_power_on_confirm_goback
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hid_power_on_confirm_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_POWER_ON_CONFIRM, (HistoryDelCBPtr) NULL);
    mmi_bt_unmask_scr_extended_flag(MMI_BT_EXT_CONFIRM_POWER_ON);
    mmi_bt_clear_endkey_hdlr();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hid_power_on_confirm_endkey
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hid_power_on_confirm_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_POWER_ON_CONFIRM, (HistoryDelCBPtr) NULL);
    mmi_bt_unmask_scr_extended_flag(MMI_BT_EXT_CONFIRM_POWER_ON);
    mmi_bt_exe_endkey_hdlr();
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_power_on_confirm_del_cb
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U8 mmi_bt_hid_power_on_confirm_del_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_POWER_ON_CONFIRM, (HistoryDelCBPtr) NULL);
    mmi_bt_unmask_scr_extended_flag(MMI_BT_EXT_CONFIRM_POWER_ON);
    mmi_bt_clear_endkey_hdlr();
    return MMI_FALSE;

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_connect_last_dev
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_connect_last_dev(void)
{
	mmi_bt_clear_endkey_hdlr();
	mmi_bth_hidd_connect_last_dev();
	mmi_bt_show_progress_scr(
            SCR_BT_CONNECTING,
            STR_BT_CONNECT,
            STR_BT_CONNECTING,
            NULL,
            MMI_FALSE,
            NULL);
      g_mmi_bt_hid_scr_cntx.flag=(U8)MMI_TRUE;
}
/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_connect_selected_dev
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_connect_selected_dev(mmi_bth_bt_addr device_addr)
{
	mmi_bt_clear_endkey_hdlr();
	mmi_bth_hidd_connect_req_hdler(device_addr);
	mmi_bt_show_progress_scr(
            SCR_BT_CONNECTING,
            STR_BT_CONNECT,
            STR_BT_CONNECTING,
            NULL,
            MMI_FALSE,
            NULL);

}


/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_no_last_dev_info
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_no_last_dev_info(void)
{
   DisplayPopup((U8*)GetString(STR_BT_REMOTE_CTRL_NO_LAST_DEV_INFO), 
    				IMG_GLOBAL_WARNING, 
    				MMI_FALSE, 
    				UI_POPUP_NOTIFYDURATION_TIME, 
    				(U8) WARNING_TONE);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_entry_hid_app_select
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_entry_hid_app_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ItemList[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_DEV_SELECT, (HistoryDelCBPtr) mmi_bt_hid_app_select_del_cb);
    
    EntryNewScreen(SCR_BT_REMOTE_CONTROL_DEV_SELECT, NULL, mmi_bt_entry_hid_app_select, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_REMOTE_CONTROL_DEV_SELECT);

    if (!g_enable_pts_test)
    {
        nItems = 3;
        ItemList[0] = (U8*)GetString(STR_BT_REMOTE_CTRL_DESKTOP);
        ItemList[1] = (U8*)GetString(STR_BT_REMOTE_CTRL_MEDIA_PLAYER);
        ItemList[2] = (U8*)GetString(STR_BT_REMOTE_CTRL_PRESENTER);
    }
    else
    {
        nItems = 4;
        ItemList[0] = (U8*)GetString(STR_BT_REMOTE_CTRL_DESKTOP);
        ItemList[1] = (U8*)GetString(STR_BT_REMOTE_CTRL_MEDIA_PLAYER);
        ItemList[2] = (U8*)GetString(STR_BT_REMOTE_CTRL_PRESENTER);
        ItemList[3] = (U8*)GetString(STR_BT_REMOTE_CTRL_KEYBOARD);
    }


    RegisterHighlightHandler(mmi_bt_hid_app_select_hilit_hdler);
    
    ShowCategory53Screen(
        STR_BT_REMOTE_CONTROL,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        (U8 **) ItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_bt_entry_disconnect_hid_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_entry_disconnect_hid_confirm, KEY_LEFT_ARROW, KEY_EVENT_DOWN);


}
/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_hid_app_select
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_exit_hid_app_select(void);
/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_app_select_hilit_hdler
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_app_select_hilit_hdler(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, idx);

    switch (idx)
    {
        case 0:
            SetLeftSoftkeyFunction(mmi_bt_entry_hid_desktop, KEY_EVENT_UP);
            break;
        case 1:
            SetLeftSoftkeyFunction(mmi_bt_entry_hid_media_player, KEY_EVENT_UP);
            break;
        case 2:
            SetLeftSoftkeyFunction(mmi_bt_entry_hid_presenter, KEY_EVENT_UP);
            break;
        case 3:
            SetLeftSoftkeyFunction(mmi_bt_entry_hid_keyboard, KEY_EVENT_UP);
            break;
        default:
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
            break;
    }


}
/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_app_select_del_cb
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U8 mmi_bt_hid_app_select_del_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_DEV_SELECT, (HistoryDelCBPtr) NULL);
    mmi_bth_hidd_disconnect_all();

    return MMI_FALSE;

}


/*****************************************************************************
* FUNCTION
*  mmi_bt_entry_disconnect_hid_confirm
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_entry_disconnect_hid_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_store_endkey_hdlr();

    mmi_bt_show_confirm_scr(
        SCR_BT_REMOTE_CONTROL_DISCONNECT_CONFIRM,
        STR_BT_REMOTE_CONTROL_DISCONNECT_CONFIRM,
        mmi_bt_exit_disconnect_hid_confirm,
        mmi_bt_entry_disconnect_hid_confirm);
    SetLeftSoftkeyFunction(mmi_bt_disconnect_hid, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bt_disconnect_hid_confirm_goback, KEY_EVENT_UP);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_disconnect_hid_confirm_endkey, KEY_END, KEY_EVENT_DOWN);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_exit_disconnect_hid_confirm
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_exit_disconnect_hid_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_clear_endkey_hdlr();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_disconnect_hid_confirm_goback
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_disconnect_hid_confirm_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_clear_endkey_hdlr();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_disconnect_hid_confirm_endkey
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_disconnect_hid_confirm_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_exe_endkey_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_disconnect_hid
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_disconnect_hid(void)
{
    SetDelScrnIDCallbackHandler(SCR_BT_REMOTE_CONTROL_DEV_SELECT, (HistoryDelCBPtr) NULL);
	mmi_bt_clear_endkey_hdlr();
	mmi_bth_hidd_disconnect_all();
	mmi_bt_show_progress_scr(
            SCR_BT_DISC_PROC,
            STR_BT_DISCONNECT,
            STR_BT_DISCONNECTING,
            NULL,
            MMI_FALSE,
            NULL);
    g_mmi_bt_hid_scr_cntx.flag=(U8)MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_desktop_key_up_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_desktop_key_up_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    PRINT_INFORMATION("key code = %d,  key type = %d\n", keycode, keytype);
    
    delay_repeat_event = 0;

    
    for (key_idx=0; key_idx < MMI_HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
		if (hid_control_data_desktop[key_idx].key_code == keycode &&
		    hid_control_data_desktop[key_idx].key_type == keytype )
	    {
			break;
	    }
    }

    if (key_idx >= MMI_HID_NUM_OF_CTRL_DATA)
    {
    	return;
    }

    if(hid_control_data_desktop[key_idx].ctrl_data[0] == 0x02)
    {
		data_len = 4;
    }
    else
    {
		data_len = 9;
	}
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_desktop[key_idx].ctrl_data);
}
/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_desktop_key_repeat_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_desktop_key_repeat_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    for (key_idx=0; key_idx < MMI_HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
    	if (keycode >= KEY_UP_ARROW && keycode <= KEY_RIGHT_ARROW)
    	{
			if (hid_control_data_desktop[key_idx].key_code == keycode &&
			    hid_control_data_desktop[key_idx].key_type == KEY_EVENT_UP )
		    {
				break;
		    }
    	}
    	else
	    {
			if (hid_control_data_desktop[key_idx].key_code == keycode &&
			    hid_control_data_desktop[key_idx].key_type == KEY_EVENT_UP )
		    {
				break;
		    }
	    }
    }

    if (key_idx >= MMI_HID_NUM_OF_CTRL_DATA)
    {
    	return;
    }

    if (!(keycode >= KEY_UP_ARROW && keycode <= KEY_RIGHT_ARROW))
    {
        if (delay_repeat_event > MMI_HID_KEY_DELAY_REPEAT_PERIOD)
        {   
            delay_repeat_event = 0;
        }
        else
        {

            delay_repeat_event++;
            return;
        }
    }

    if(hid_control_data_desktop[key_idx].ctrl_data[0] == 0x02)
    {
		data_len = 4;
    }
    else
    {
		data_len = 9;
	}
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_desktop[key_idx].ctrl_data);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_hid_desktop
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_hid_desktop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    wgui_cat95_panel_element_struct element[17];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_REMOTE_CONTROL_DESKTOP, NULL, mmi_bt_entry_hid_desktop, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_REMOTE_CONTROL_DESKTOP);

    for(i = 0; i < 12; i++)//1, 2, 3, 4, 5, 6, 7, 8, 9, *, 0, #
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_1+i;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_bt_hid_desktop_key_up_event_callback;
        element[i].repeat_event_callback = mmi_bt_hid_desktop_key_repeat_event_callback;
        element[i].disable_imageid = DESKTOP_IMG_01_DISALBE+i*4;
        element[i].off_imageid = DESKTOP_IMG_01_OFF+i*4;
        element[i].on_imageid = DESKTOP_IMG_01_ON+i*4;
        element[i].down_imageid = DESKTOP_IMG_01_DOWN+i*4;
    }
    element[9].keycode = KEY_STAR;
    element[10].keycode = KEY_0;
    element[11].keycode = KEY_POUND;

    
    for(i = 12; i < 16; i++)//up, donw, left, right
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_UP_ARROW+i-12;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_bt_hid_desktop_key_up_event_callback;
        element[i].repeat_event_callback = mmi_bt_hid_desktop_key_repeat_event_callback;
        element[i].disable_imageid = MOUSE_IMG_UP_DISALBE+(i-12)*4;
        element[i].off_imageid = MOUSE_IMG_UP_OFF+(i-12)*4;
        element[i].on_imageid = MOUSE_IMG_UP_ON+(i-12)*4;
        element[i].down_imageid = MOUSE_IMG_UP_DOWN+(i-12)*4;
    }
    
    //center key for displaing mouse only, no key handler
    element[16].x = hid_icon_pos[16][0];
    element[16].y = hid_icon_pos[16][1];
    element[16].width = hid_icon_pos[16][2];
    element[16].height = hid_icon_pos[16][3];
    element[16].keycode = KEY_INVALID;
    element[16].down_event_callback = NULL; 
    element[16].up_event_callback = mmi_bt_hid_desktop_key_up_event_callback;
    element[16].repeat_event_callback = mmi_bt_hid_desktop_key_repeat_event_callback;
    element[16].disable_imageid = MOUSE_IMG_COMMON;
    element[16].off_imageid = MOUSE_IMG_COMMON;
    element[16].on_imageid = MOUSE_IMG_COMMON;
    element[16].down_imageid = MOUSE_IMG_COMMON;
    
    ShowCategory95Screen(
        (U8 *)GetString(STR_BT_REMOTE_CTRL_DESKTOP), 
        (U16)NULL, 
        (U16)NULL, 
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        HID_IMG_BG, 
        element, 
        17, 
        0, 
        MMI_HID_KEY_REPEAT_PERIOD,
        guiBuffer);

	/* disable LSK */ 
    //ChangeLeftSoftkey(0, 0);
    //SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_hid_desktop
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_hid_desktop(void);

/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_media_player_key_up_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_media_player_key_up_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    PRINT_INFORMATION("key code = %d,  key type = %d\n", keycode, keytype);
    
    delay_repeat_event = 0;
   
    for (key_idx=0; key_idx < MMI_HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
		if (hid_control_data_media_player[key_idx].key_code == keycode &&
		    hid_control_data_media_player[key_idx].key_type == keytype )
	    {
			break;
	    }
    }

    if (key_idx >= MMI_HID_NUM_OF_CTRL_DATA)
    {
    	return;
    }

    if(hid_control_data_media_player[key_idx].ctrl_data[0] == 0x02)
    {
		data_len = 4;
    }
    else
    {
		data_len = 9;
	}
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_media_player[key_idx].ctrl_data);
}
/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_media_player_key_repeat_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_media_player_key_repeat_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    for (key_idx=0; key_idx < MMI_HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
    	if (keycode >= KEY_UP_ARROW && keycode <= KEY_RIGHT_ARROW)
    	{
			if (hid_control_data_media_player[key_idx].key_code == keycode &&
			    hid_control_data_media_player[key_idx].key_type == KEY_EVENT_UP )
		    {
				break;
		    }
    	}
    	else
    	{
			if (hid_control_data_media_player[key_idx].key_code == keycode &&
			    hid_control_data_media_player[key_idx].key_type == KEY_EVENT_UP )
		    {
				break;
		    }
    	}
    }

    if (key_idx >= MMI_HID_NUM_OF_CTRL_DATA)
    {
    	return;
    }

    if (!(keycode >= KEY_UP_ARROW && keycode <= KEY_RIGHT_ARROW))
    {
        if (delay_repeat_event > MMI_HID_KEY_DELAY_REPEAT_PERIOD)
        {   
            delay_repeat_event = 0;
        }
        else
        {

            delay_repeat_event++;
            return;
        }
    }


    if(hid_control_data_media_player[key_idx].ctrl_data[0] == 0x02)
    {
		data_len = 4;
    }
    else
    {
		data_len = 9;
	}
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_media_player[key_idx].ctrl_data);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_hid_media_player
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_hid_media_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    wgui_cat95_panel_element_struct element[17];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_REMOTE_CONTROL_DESKTOP, NULL, mmi_bt_entry_hid_media_player, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_REMOTE_CONTROL_MEDIA_PLAYER);

    for(i = 0; i < 12; i++)//1, 2, 3, 4, 5, 6, 7, 8, 9, *, 0, #
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_1+i;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_bt_hid_media_player_key_up_event_callback;
        element[i].repeat_event_callback = mmi_bt_hid_media_player_key_repeat_event_callback;
        element[i].disable_imageid = MEDIA_PLAYER_IMG_01_DISALBE+i*4;
        element[i].off_imageid = MEDIA_PLAYER_IMG_01_OFF+i*4;
        element[i].on_imageid = MEDIA_PLAYER_IMG_01_ON+i*4;
        element[i].down_imageid = MEDIA_PLAYER_IMG_01_DOWN+i*4;
    }
    element[9].keycode = KEY_STAR;
    element[10].keycode = KEY_0;
    element[11].keycode = KEY_POUND;

    
    for(i = 12; i < 16; i++)//up, donw, left, right
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_UP_ARROW+i-12;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_bt_hid_media_player_key_up_event_callback;
        element[i].repeat_event_callback = mmi_bt_hid_media_player_key_repeat_event_callback;
        element[i].disable_imageid = MOUSE_IMG_UP_DISALBE+(i-12)*4;
        element[i].off_imageid = MOUSE_IMG_UP_OFF+(i-12)*4;
        element[i].on_imageid = MOUSE_IMG_UP_ON+(i-12)*4;
        element[i].down_imageid = MOUSE_IMG_UP_DOWN+(i-12)*4;
    }
    
    //center key for displaing mouse only, no key handler
    element[16].x = hid_icon_pos[16][0];
    element[16].y = hid_icon_pos[16][1];
    element[16].width = hid_icon_pos[16][2];
    element[16].height = hid_icon_pos[16][3];
    element[16].keycode = KEY_INVALID;
    element[16].down_event_callback = NULL; 
    element[16].up_event_callback = mmi_bt_hid_media_player_key_up_event_callback;
    element[16].repeat_event_callback = mmi_bt_hid_media_player_key_repeat_event_callback;
    element[16].disable_imageid = MOUSE_IMG_COMMON;
    element[16].off_imageid = MOUSE_IMG_COMMON;
    element[16].on_imageid = MOUSE_IMG_COMMON;
    element[16].down_imageid = MOUSE_IMG_COMMON;
    
    ShowCategory95Screen(
        (U8 *)GetString(STR_BT_REMOTE_CTRL_MEDIA_PLAYER), 
        (U16)NULL, 
        (U16)NULL, 
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        HID_IMG_BG, 
        element, 
        17, 
        0, 
        MMI_HID_KEY_REPEAT_PERIOD,
        guiBuffer);
 
	/* disable LSK */ 
    //ChangeLeftSoftkey(0, 0);
    //SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_hid_media_player
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_hid_media_player(void);
/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_presenter_key_up_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_presenter_key_up_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    PRINT_INFORMATION("key code = %d,  key type = %d\n", keycode, keytype);
    
    delay_repeat_event = 0;

    
    for (key_idx=0; key_idx < MMI_HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
		if (hid_control_data_presenter[key_idx].key_code == keycode &&
		    hid_control_data_presenter[key_idx].key_type == keytype )
	    {
			break;
	    }
    }

    if (key_idx >= MMI_HID_NUM_OF_CTRL_DATA)
    {
    	return;
    }

    if(hid_control_data_presenter[key_idx].ctrl_data[0] == 0x02)
    {
		data_len = 4;
    }
    else
    {
		data_len = 9;
	}
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_presenter[key_idx].ctrl_data);
}
/*****************************************************************************
* FUNCTION
*  mmi_bt_hid_presenter_key_repeat_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_hid_presenter_key_repeat_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    for (key_idx=0; key_idx < MMI_HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
    	if (keycode == KEY_2 || keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6)
    	{
			if (hid_control_data_presenter[key_idx].key_code == keycode &&
			    hid_control_data_presenter[key_idx].key_type == KEY_EVENT_UP )
		    {
				break;
		    }
    	}
    	else
	    {
			if (hid_control_data_presenter[key_idx].key_code == keycode &&
			    hid_control_data_presenter[key_idx].key_type == KEY_EVENT_UP )
		    {
				break;
		    }
	    }
    
    }

    if (key_idx >= MMI_HID_NUM_OF_CTRL_DATA)
    {
    	return;
    }

    if (!(keycode == KEY_2 || keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6))
    {
        if (delay_repeat_event > MMI_HID_KEY_DELAY_REPEAT_PERIOD)
        {   
            delay_repeat_event = 0;
        }
        else
        {

            delay_repeat_event++;
            return;
        }
    }

    if(hid_control_data_presenter[key_idx].ctrl_data[0] == 0x02)
    {
		data_len = 4;
    }
    else
    {
		data_len = 9;
	}
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_presenter[key_idx].ctrl_data);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_hid_presenter
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_hid_presenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    wgui_cat95_panel_element_struct element[17];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BT_REMOTE_CONTROL_DESKTOP, NULL, mmi_bt_entry_hid_presenter, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BT_REMOTE_CONTROL_PRESENTER);

    for(i = 0; i < 12; i++)//1, 2, 3, 4, 5, 6, 7, 8, 9, *, 0, #
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_1+i;
        element[i].down_event_callback = NULL;        
        element[i].up_event_callback = mmi_bt_hid_presenter_key_up_event_callback;
        element[i].repeat_event_callback = mmi_bt_hid_presenter_key_repeat_event_callback;
        element[i].disable_imageid = PRESENTER_IMG_01_DISALBE+i*4;
        element[i].off_imageid = PRESENTER_IMG_01_OFF+i*4;
        element[i].on_imageid = PRESENTER_IMG_01_ON+i*4;
        element[i].down_imageid = PRESENTER_IMG_01_DOWN+i*4;
    }
    element[9].keycode = KEY_STAR;
    element[10].keycode = KEY_0;
    element[11].keycode = KEY_POUND;

    
    for(i = 12; i < 16; i++)//up, donw, left, right
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_UP_ARROW+i-12;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_bt_hid_presenter_key_up_event_callback;
        element[i].repeat_event_callback = mmi_bt_hid_presenter_key_repeat_event_callback;
        element[i].disable_imageid = PRESENTER_MOUSE_IMG_UP_DISALBE+(i-12)*4;
        element[i].off_imageid = PRESENTER_MOUSE_IMG_UP_OFF+(i-12)*4;
        element[i].on_imageid = PRESENTER_MOUSE_IMG_UP_ON+(i-12)*4;
        element[i].down_imageid = PRESENTER_MOUSE_IMG_UP_DOWN+(i-12)*4;
    }
    
    ShowCategory95Screen(
        (U8 *)GetString(STR_BT_REMOTE_CTRL_PRESENTER), 
        (U16)NULL, 
        (U16)NULL, 
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        HID_IMG_BG, 
        element, 
        16, 
        0, 
        MMI_HID_KEY_REPEAT_PERIOD,
        guiBuffer);
 
	/* disable LSK */ 
    //ChangeLeftSoftkey(0, 0);
    //SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_hid_presenter
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_hid_presenter(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_hid_keyboard
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_hid_keyboard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_BT_REMOTE_CONTROL_KEYBOARD, NULL, mmi_bt_entry_hid_keyboard, NULL);

    if ((gui_buffer = GetCurrGuiBuffer(SCR_BT_REMOTE_CONTROL_KEYBOARD)) == NULL)
    {
        memset(g_mmi_bt_hid_scr_cntx.key_cmd, 0, (MMI_HID_MAX_KBD_CMD+1)*ENCODING_LENGTH);
    }

    ShowCategory5Screen_ext(
        STR_BT_REMOTE_CTRL_KEYBOARD,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        (U8*) (g_mmi_bt_hid_scr_cntx.key_cmd),
        2,
        gui_buffer,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL,
        NULL);

    SetLeftSoftkeyFunction(mmi_bt_hid_keyboard_send_cmd, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(GoBackHistory);
    return;


}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_hid_keyboard
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_hid_keyboard(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hid_keyboard_send_cmd
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hid_keyboard_send_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_mmi_bt_hid_scr_cntx.key_cmd) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_BT_UNSUPPORTED_KEY_CMD),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        
    }
    else
    {   
        /* the key cmd is defined in the keyboard/keypad page section of the HID Usage Table(HUT) specification */
        if ((g_mmi_bt_hid_scr_cntx.key_cmd[0] >= 'a' && g_mmi_bt_hid_scr_cntx.key_cmd[0] <= 'z') ) 
        {
            hid_key_cmd[3] = g_mmi_bt_hid_scr_cntx.key_cmd[0]-0x61+0x04;
        }
        else if((g_mmi_bt_hid_scr_cntx.key_cmd[0] >= 'A' && g_mmi_bt_hid_scr_cntx.key_cmd[0] <= 'Z'))
        {
            hid_key_cmd[3] = g_mmi_bt_hid_scr_cntx.key_cmd[0]-0x41+0x04;
        }
        else if((g_mmi_bt_hid_scr_cntx.key_cmd[0] >= '0' && g_mmi_bt_hid_scr_cntx.key_cmd[0] <= '9'))
        {
            if (g_mmi_bt_hid_scr_cntx.key_cmd[0] == '0')
            {
                hid_key_cmd[3] = 0x27;
            }
            else
            {
                hid_key_cmd[3] = g_mmi_bt_hid_scr_cntx.key_cmd[0]-0x31+0x1E;
            }
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_BT_UNSUPPORTED_KEY_CMD),
                IMG_GLOBAL_ERROR,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            return;
        }
        
        /* send this kbd cmd to remote device */    
        mmi_bth_hidd_interrupt_data_req_hdler(MMI_HID_MAX_CTRL_DATA_LENGHT, (U8 *)hid_key_cmd);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hid_authorized_failed_ind
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hid_authorized_failed_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *str_prof, *str_conn_res;
    U8 str_output[60], str_ucs2_space[4], str_asc_space[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_prof = (U8*) GetString(STR_BT_PROF_HID);
    str_conn_res = (U8*) GetString(STR_BT_DISCON_ED);

    memset(str_output, 0, sizeof(U8) * 60);
    memset(str_asc_space, 0, sizeof(U8) * 2);
    memset(str_ucs2_space, 0, sizeof(U8) * 4);

    kal_sprintf((S8*) str_asc_space, " ");
    mmi_asc_to_ucs2((S8*) str_ucs2_space, (S8*) str_asc_space);

    mmi_ucs2cpy((S8*) str_output, (const S8*)str_prof);
    /* space is reserved in ref_list.txt for alphabetical languages */ 
    /* for Chinese language, space is not required */
    //mmi_ucs2cat((S8*) str_output, (const S8*)str_ucs2_space);
    /* check if str_prof string length + 2 + str_conn_res string length >= str_output */
    MMI_BT_ASSERT(((mmi_ucs2strlen((const S8*)str_prof) * ENCODING_LENGTH) + 2 +
                   (mmi_ucs2strlen((const S8*)str_conn_res) * ENCODING_LENGTH)) < (sizeof(U8) * 60));
    mmi_ucs2cat((S8*) str_output, (const S8*)str_conn_res);


    DisplayPopup(str_output, 
    				IMG_GLOBAL_WARNING, 
    				MMI_FALSE, 
    				UI_POPUP_NOTIFYDURATION_TIME, 
    				(U8) WARNING_TONE);
    DeleteScreenIfPresent(SCR_BT_CONNECT_ACCEPT_CNF);
    DeleteScreenIfPresent(SCR_BT_REMOTE_CONTROL_CONN_REQ);
	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_clear_last_dev_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_hid_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bth_hidd_cntx.state >= MMI_BTH_HIDD_STAT_IDLE && g_mmi_bth_hidd_cntx.state <= MMI_BTH_HIDD_STAT_CONNECTED)
    {
    	result = MMI_FALSE;
    }

    return result;
}


#endif /* __MMI_HIDD_SUPPORT__ */
#endif /* __MMI_BT_MTK_SUPPORT__ */

