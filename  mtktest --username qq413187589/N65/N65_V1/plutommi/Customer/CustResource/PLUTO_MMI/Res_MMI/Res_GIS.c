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
 * Filename:
 * ---------
 *  Res_MB_GIS.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Mapbar GIS Resource
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_MAPBAR_GIS__) || defined(__MMI_SUNAVI_GIS__) 

#ifdef __MMI_MAPBAR_GIS__
#include "MB_GISResDef.h"
#endif

#ifdef __MMI_SUNAVI_GIS__
#include "SN_GISResDef.h"
#endif

#include "PopulateRes.h"
#include "CustResDef.h"

void PopulateGISRes(void)
{
    /* Image */
    ADD_APPLICATION_IMAGE2(IMG_ID_GIS,		CUST_IMG_PATH"\\\\MainLCD\\\\GIS\\\\SB_GIS.pbm", 			"GIS icon" );

    /* String */
    ADD_APPLICATION_STRING2(STR_ID_GIS, "GIS", "GIS String");

    ADD_APPLICATION_STRING2(STR_ID_GIS_DEMO_LIST1, "Start render", "GIS String");
    ADD_APPLICATION_STRING2(STR_ID_GIS_DEMO_LIST2, "Stop render", "GIS String");
    ADD_APPLICATION_STRING2(STR_ID_GIS_DEMO_LIST3, "Start search", "GIS String");
    ADD_APPLICATION_STRING2(STR_ID_GIS_DEMO_LIST4, "Stop search", "GIS String");
    ADD_APPLICATION_STRING2(STR_ID_GIS_DEMO_LIST5, "Get search result", "GIS String");
    ADD_APPLICATION_STRING2(STR_ID_GIS_DEMO_LIST6, "Setting", "GIS String");
    ADD_APPLICATION_STRING2(STR_ID_GIS_INPUT_EDITOR_OPTION_DONE, "Done", "GIS String");
    ADD_APPLICATION_STRING2( STR_ID_GIS_INPUT_EDITOR_OPTION_MEHTHOD, "Input Method", "GIS String");
    ADD_APPLICATION_STRING2( STR_ID_GIS_INPUT_EDITOR_OPTION_CANCEL, "Cancel", "GIS String");
    
    ADD_APPLICATION_STRING2 (STR_ID_GIS_MAIN, "GIS", "GIS main str");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_APP, "Enter GIS", "GIS Application");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_SETTING, "Receiver Setting", "GIS Receiver setting");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_RECEIVER, "Receiver", "GIS Receiver setting");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_BTDEVICE, "Bluetooth Device", "GIS Receiver BlueTooth device");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_RECEIVER_ON, "On", "GIS Receiver ON");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_RECEIVER_OFF, "Off", "GIS Receiver OFF");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_RECEIVER_EXT, "External", "GIS Receiver use external");

    ADD_APPLICATION_STRING2 (STR_ID_GIS_SELECT, "Select",  "LSK select");//search bluetooth device
    ADD_APPLICATION_STRING2 (STR_ID_GIS_SAVE, "Save", "label save");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_ASK_SAVE_SETTING,                "The setting is not save, save it now?",                     "ask user if save setting");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_ASK_CHOOSE_GPS, "GPS module is not connected, set it first?", "ask user to set GPS");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_SAVE_OK, "Save OK", " ");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_GPS_SIGNAL_ERR, "GPS Signal Error", " ");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_GPS_SIGNAL_OK, "GPS Singal OK", " ");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_ASK_SAVE_CHANGED_IF_SAVE, "Setting changed, do you want to save the change?", "Ask user if save the setting");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_GPS_REJECT, "GPS Reject The Connection", "GPS reject the connection");
    
    ADD_APPLICATION_STRING2 (STR_ID_GIS_GPS_CONN_ERR, "GPS Connection Error", "GPS connection error");

    ADD_APPLICATION_STRING2 (STR_ID_GIS_UART01, "UART1", "Uart choose list item");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_UART02, "UART2", "Uart choose list item");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_UART03, "UART3", "Uart choose list item");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_UART04, "UART4", "Uart choose list item");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_UART05, "UART5", "Uart choose list item");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_UART06, "UART6", "Uart choose list item");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_UART07, "UART7", "Uart choose list item");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_UART08, "UART8", "Uart choose list item");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_UART09, "UART9", "Uart choose list item");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_UART10, "UART10", "Uart choose list item");
    ADD_APPLICATION_STRING2 (STR_ID_GIS_PAIRING_SELECTED_BT, "Pairing selected bluetooth device", "Pairing selected bluetooth device");

    ADD_APPLICATION_STRING2 (STR_ID_GIS_NONE, "None", " ");

    ADD_APPLICATION_MENUITEM((MENU_ID_GIS,MAIN_MENU_FUNANDGAMES_MENUID,2,
            MENU_ID_GIS_APP,
            MENU_ID_GIS_SETTING,
            SHOW,NONMOVEABLE,DISP_LIST, STR_ID_GIS,IMG_ID_GIS));

    ADD_APPLICATION_MENUITEM((MENU_ID_GIS_APP,MENU_ID_GIS,0,SHOW,NONMOVEABLE,DISP_LIST, STR_ID_GIS_APP,IMG_GLOBAL_L1));

    ADD_APPLICATION_MENUITEM((MENU_ID_GIS_SETTING,MENU_ID_GIS,2,
            MENU_ID_GIS_RECEIVER,
            MENU_ID_GIS_BTDEVICE,
            SHOW, NONMOVEABLE, DISP_LIST, STR_ID_GIS_SETTING, IMG_GLOBAL_L2));

    ADD_APPLICATION_MENUITEM((MENU_ID_GIS_RECEIVER,MENU_ID_GIS_SETTING,0,SHOW,NONMOVEABLE,DISP_LIST,
            STR_ID_GIS_RECEIVER,IMG_GLOBAL_L1));
    ADD_APPLICATION_MENUITEM((MENU_ID_GIS_BTDEVICE,MENU_ID_GIS_SETTING,0,SHOW,NONMOVEABLE,DISP_LIST,
            STR_ID_GIS_BTDEVICE,IMG_GLOBAL_L2));

    ADD_APPLICATION_MENUITEM((MENU_ID_GIS_INPUT_EDITOR_OPTION,0,3,
            MENU_ID_GIS_INPUT_EDITOR_OPTION_DONE,
            MENU_ID_GIS_INPUT_EDITOR_OPTION_MEHTHOD,
            MENU_ID_GIS_INPUT_EDITOR_OPTION_CANCEL,
	     SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));
   ADD_APPLICATION_MENUITEM((MENU_ID_GIS_INPUT_EDITOR_OPTION_DONE,MENU_ID_GIS_INPUT_EDITOR_OPTION,0,
	     SHOW, NONMOVEABLE, DISP_LIST,STR_ID_GIS_INPUT_EDITOR_OPTION_DONE,IMG_ID_GIS));
   ADD_APPLICATION_MENUITEM((MENU_ID_GIS_INPUT_EDITOR_OPTION_MEHTHOD,MENU_ID_GIS_INPUT_EDITOR_OPTION,0,
	     SHOW, NONMOVEABLE, DISP_LIST,STR_ID_GIS_INPUT_EDITOR_OPTION_MEHTHOD,IMG_ID_GIS));
   ADD_APPLICATION_MENUITEM((MENU_ID_GIS_INPUT_EDITOR_OPTION_CANCEL,MENU_ID_GIS_INPUT_EDITOR_OPTION,0,
	     SHOW, NONMOVEABLE, DISP_LIST,STR_ID_GIS_INPUT_EDITOR_OPTION_CANCEL,IMG_ID_GIS));
}

#endif /* __MMI_MAPBAR_GIS__ || __MMI_SUNAVI_GIS__ */


