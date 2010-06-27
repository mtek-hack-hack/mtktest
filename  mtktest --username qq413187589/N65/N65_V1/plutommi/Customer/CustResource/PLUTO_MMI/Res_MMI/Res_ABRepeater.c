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
 *  Res_ABRepeater.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Resource population.
 *
 *  Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"   /* add if you use any compile options defined in MMI_features.h */

#ifdef __MMI_AB_REPEATER__
#include "MMIDataType.h"    /* for resource base */

#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
#include "GlobalDefs.h"             /* for global string */
#include "ABRepeaterResDef.h" /* for resource ID */
#include "FunAndGamesResDef.h"

void populateABRepeaterMenu(void)
{
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_TITLE, "AB Repeater", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABENTER_TITLE, "Enter AB", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_SWITCH, "Switch Screen", "AB Repeater String" );
    ADD_APPLICATION_STRING2(STR_ID_ABREPEAT_NO_CARD,"Drive Not Found", "AB Repeater String");
    ADD_APPLICATION_STRING2(STR_ID_ABREPEAT_STORAGE,"Storage", "AB Repeater String");
    ADD_APPLICATION_STRING2(STR_ID_ABREPEAT_STORAGE_PHONE,"Phone", "AB Repeater String");
    ADD_APPLICATION_STRING2(STR_ID_ABREPEAT_STORAGE_CARD,"Card", "AB Repeater String");
    
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_DISC_FULL, "Disc Full", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_OPEN_FILE_ERROR, "Can't Open", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_CANNOT_PAUSE, "Can't Pause", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_COMMAND_ERROR, "Failed To Play", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_DEVICE_BUSY, "Device Busy", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_BAD_FORMAT, "Bad Format", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_INVALID_FORMAT, "Invalid Format", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_NO_SPACE, "Exceed File Limit", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_ERROR, "Audio Content Error", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_UNSUPPORTED_CHANNEL, "Unsupported Channel", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_UNSUPPORTED_FREQ, "Unsupported Frequency", "AB Repeater StringA" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_UNSUPPORTED_TYPE, "Unsupported Type", "AB Repeater String" );
    ADD_APPLICATION_STRING2( STR_ID_ABREPEAT_BUILDING_CACHE, "Building Cache", "AB Repeater String" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_MAIN_SKIN1_BG, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_MAIN_BG.gif", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_PROGRESS_BAR, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_progress_bar.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_INDICATOR, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_INDICATOR.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_BUTTON0, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_BUTTON0.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_BUTTON1, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_BUTTON1.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_BUTTON2, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_BUTTON2.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_BUTTON3, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_BUTTON3.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_BUTTON4, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_BUTTON4.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_BUTTON5, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_BUTTON5.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_BUTTON6, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_BUTTON6.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_BUTTON7, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_BUTTON7.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_BUTTON8, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_BUTTON8.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_BUTTON9, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_BUTTON9.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_ABSECTION_PLAYING, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_PLAY.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_ABSECTION_RECORDING, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_REC_UP.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_ABSECTION_RECORDING_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_REC_DOWN.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_AB_SETSECTION, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_SET_UP.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_AB_SETSECTION_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_SET_DOWN.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_AB_NONSETSECTION, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_NONSET_UP.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_AB_NONSETSECTION_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SECTION_NONSET_DOWN.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_VOLUME, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_VOLUME.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_VOLUME_DEC_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_VOLUME_dec_up.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_VOLUME_DEC_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_VOLUME_dec_down.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_VOLUME_INC_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_VOLUME_inc_up.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_VOLUME_INC_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_VOLUME_inc_down.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_STOP_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_STOP_DOWN.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_STOP_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_STOP_UP.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_PROG_BAR_EMPTY, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_PROG_BAR_RECT_EMPTY.pbm", "ab repeater image" );
    //	ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_PROG_BAR_FILL, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_PROG_BAR_RECT_FILL.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_FWD_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_FWD_DOWN.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_FWD_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_FWD_UP.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_REW_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_REW_DOWN.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_REW_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_REW_UP.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_PAUSE_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_PAUSE_DOWN.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_PAUSE_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_PAUSE_UP.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_PLAY_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_PLAY_DOWN.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_PLAY_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_PLAY_UP.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_REPEAT_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_REPEAT_DOWN.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_REPEAT_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_REPEAT_UP.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_REPEAT_OFF_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_REPEAT_ONCE_DOWN.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_REPEAT_OFF_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_REPEAT_ONCE_UP.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_REPEAT_DISABLE, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_REPEAT_DISABLE.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_SETTING_MODE_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SETTING_DOWN.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_SETTING_MODE_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SETTING_UP.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_PLAY_MODE_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SETTING_OFF_DOWN.pbm", "ab repeater image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_PLAY_MODE_UP, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_SETTING_OFF_UP.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_SUBMENU_ICON, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\SB_ABrepeater.pbm", "ab repeater image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_ABREPEAT_STORAGE, CUST_IMG_PATH"\\\\MainLCD\\\\ABRepeater\\\\AB_STORAGE_ICON.pbm", "ab repeater image" );
    
    
    
    
    ADD_APPLICATION_MENUITEM((MENU_ID_AB_REPEATER_MAIN, MAIN_MENU_MULTIMEDIA_MENUID, 0,
        SHOW, MOVEABLEACROSSPARENT | SHORTCUTABLE, 0, STR_ID_ABREPEAT_TITLE, IMG_ID_ABREPEAT_SUBMENU_ICON ));
    ADD_APPLICATION_MENUITEM((MENU_ID_AB_REPEATER_OPTION, 0,2, MENU_ID_AB_REPEAT_ENTER, MENU_ID_AB_REPEAT_STORAGE,
        SHOW, NONMOVEABLE, 0, STR_ID_ABREPEAT_TITLE, 0 ));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_AB_REPEAT_ENTER, MENU_ID_AB_REPEATER_OPTION, 0,
        SHOW, MOVEABLEWITHINPARENT, 0, STR_ID_ABENTER_TITLE, 0 ));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_AB_REPEAT_EMPTY_FOLDER_OPTION, 0,1, MENU_ID_AB_REPEAT_STORAGE,
        SHOW, MOVEABLEWITHINPARENT, 0, STR_ID_ABREPEAT_TITLE, 0 ));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_AB_REPEAT_STORAGE, 0,2, MENU_ID_AB_REPEAT_PHONE,MENU_ID_AB_REPEAT_CARD,
        SHOW, MOVEABLEWITHINPARENT, 0, STR_ID_ABREPEAT_STORAGE, 0 ));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_AB_REPEAT_PHONE, MENU_ID_AB_REPEAT_STORAGE, 0,
        SHOW, MOVEABLEWITHINPARENT, 0, 0, 0 ));
    ADD_APPLICATION_MENUITEM((MENU_ID_AB_REPEAT_CARD, MENU_ID_AB_REPEAT_STORAGE, 0,
        SHOW, MOVEABLEWITHINPARENT, 0, 0, 0 ));
    
}

#endif /* __MMI_AB_REPEATER__ */


