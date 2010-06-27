/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *	Res_DMUI.c
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *	This file populates resource for DMUI application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *
 *****************************************************************************/

#include "MMI_features.h"

#ifdef SYNCML_DM_SUPPORT
#include "MMIDataType.h"
 
#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
 
#include "GlobalDefs.h"

#include "DMUIResdef.h"

/*****************************************************************************
 * FUNCTION
 *  PopulateDMUIRes
 * DESCRIPTION
 *  populate all resource fo DMUI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void PopulateDMUIRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* resource ID check */
    if ((SCR_ID_DMUI_END > DMUI_BASE_MAX) ||
        (STR_ID_DMUI_END > DMUI_BASE_MAX) ||
        (IMG_ID_DMUI_END > DMUI_BASE_MAX))
    {
        RESOURCE_ID_OUT_OF_RANGE_HANDLER();
    }


    /* add string resource */
    ADD_APPLICATION_STRING2(STR_ID_DMUI_MAIN,"Device Management","DM Setting");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_OPTION_CAPTION,"Option","DM Option");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_OP_ERASE,"Erase","DM Option Erase");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_ERASED,"Erased","DM Setting Erased");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_LIST_EMPTY,"<empty>","DM List Empty");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_WAITING,"Waiting...","DM Message Waiting");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_ACTIVATED,"Activated","DM Message Waiting");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_INFO_CAPTION,"Setting Information","DM Setting Information");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_SERVERID,"Server ID","DM Info Server ID");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_SERVER_PASSWORD,"Server Password","DM Info Server Password");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_CONNECTION_SETTING,"Connection Setting","DM Connection Settings");    
    ADD_APPLICATION_STRING2(STR_ID_DMUI_SERVER_ADDRESS,"Server Address","DM Info Server Address");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_USERNAME,"User Name","DM Info Username");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_USER_PASSWORD,"User Password","DM Info User Password");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_AUTHTYPE,"Auth Type","DM Info Auth Type");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_AUTHTYPE_NONE,"NONE","DM Info Auth Type None");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_AUTHTYPE_BASIC,"BASIC","DM Info Auth Type Basic");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_AUTHTYPE_MD5,"MD5","DM Info Auth Type MD5");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_AUTHTYPE_HMAC,"HMAC","DM Info Auth Type HMAC");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_CS_DATA_ACCOUNT,"Data Account","DM CS Info APN");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_CS_USE_PROXY,"Use Proxy","DM CS Info Use Proxy");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_CS_IP,"Proxy IP","DM CS Info Proxy IP");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_CS_PORT,"Proxy Port","DM CS Info Proxy Port");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_CS_PROXY_USERNAME,"Proxy Username","DM CS Info Proxy Username");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_CS_PROXY_PASSWORD,"Proxy Password","DM CS Info Proxy Password");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_CS_INVALID_PORT,"Invalid Proxy Port","DM CS Info Invalid Proxy Port");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_CS_INVALID_IP,"Invalid Proxy IP","DM CS Info Invalid Proxy IP");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_INFO_INVALID_SERVER_ADDRESS,"Invalid Server Address","DM Info Invalid URL");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_INFO_SERVERID_EMPTY,"Server ID is empty!","DM Info Server ID empty");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_INFO_SERVERID_EXIST,"Server ID existed!","DM Info Server ID Existed");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_INFO_SERVERID_INVALID,"Server ID is invalid!","DM Info Server ID invalid");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_INIT_SESSION,"Init Session","Init Session");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_ENTER_PIN,"Enter PIN","Enter PIN Input");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_DOWNLOAD_CAPTION,"Download?","DM Init Confirm Screen");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_DOWNLOAD_TITLE,"Do you want to download this file?","Download Text");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_DOWNLOAD_INFO,"Download Information:","Download Information");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_UPDATE_CAPTION,"Update?","DM Update Caption");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_UPDATE_TITLE,"Do you want to update?","Update Text");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_UPDATE_INFO,"Update Information:","Update Information");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_UPDATE_REBOOT,"Phone will reboot later","");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_NAME,"Name :","Name");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_TYPE,"Type :","Type");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_SIZE,"Size :","Size");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_DESCRIPTION,"Description :","Description");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_UPDATE_DEFER,"Defer","Update Defer");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_UPDATE_REQUEST,"FOTA Update","Update Notification");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_DOWNLOAD_REQUEST,"FOTA Download","Download Notification");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_USER_CANCELLED,"User Cancelled","STR_ID_DMUI_USER_CANCELLED");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_REBOOT,"Reboot","Reboot");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_NOTIF_REBOOT_PROGRESS,"Handset Reboot","Handset Reboot");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_DOWNLOAD_PROGRESS,"Download Progress","Download Progress");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_ALERT_DM_INFO_CAPTION,"DM Alert","DM Alert Message");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_DELETE_ASK, "Delete?","Delete Ask");
    ADD_APPLICATION_STRING2(STR_ID_DMUI_SAVE_ASK, "Save?","Save Ask");

    /* DM OTA string resource */
    ADD_APPLICATION_STRING2(STR_ID_DM_OTA_PROFILE,"Profile","DM OTA Profile");
    ADD_APPLICATION_STRING2(STR_ID_DM_OTA_SERVERID_EXIST_REPLACE,"Server ID Exist \n Replace?","DM OTA Server ID Exist");
    ADD_APPLICATION_STRING2(STR_ID_DM_OTA_SERVERID_FULL_REPLACE,"Server ID List is Full \n Replace?","DM Alert Message");

    /* add images resource */
    ADD_APPLICATION_IMAGE2(IMG_ID_DMUI_MAIN,CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Device_manangerment.pbm","Default image");
    ADD_APPLICATION_IMAGE2(IMG_ID_DMUI_NO_IMAGE,CUST_IMG_BASE_PATH"\\\\NoImage.bmp","DMUI_NOIMAGE");
    ADD_APPLICATION_IMAGE2(IMG_ID_DMUI_SEL_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_V.bmp", "DMUI_SEL_IMAGE");
    ADD_APPLICATION_IMAGE2(IMG_ID_DMUI_SERVERID,CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Server_ID.pbm","DMUI_NOIMAGE");
    ADD_APPLICATION_IMAGE2(IMG_ID_DMUI_SERVER_PASSWORD,CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Server_Password.pbm","DMUI_NOIMAGE");
    ADD_APPLICATION_IMAGE2(IMG_ID_DMUI_CONNECTION_SETTING,CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Date_account.pbm","DMUI_NOIMAGE");
    ADD_APPLICATION_IMAGE2(IMG_ID_DMUI_SERVER_ADDRESS,CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Server_add.pbm","DMUI_NOIMAGE");
    ADD_APPLICATION_IMAGE2(IMG_ID_DMUI_USERNAME,CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_User_name.pbm","DMUI_NOIMAGE");
    ADD_APPLICATION_IMAGE2(IMG_ID_DMUI_USER_PASSWORD,CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_User_password.pbm","DMUI_NOIMAGE");
    ADD_APPLICATION_IMAGE2(IMG_ID_DMUI_AUTHTYPE,CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Auth_type.pbm","DMUI_NOIMAGE");
    

    /* add menu resource */
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_MENU_9MATRIX__ */
    ADD_APPLICATION_MENUITEM ((MENU_ID_DMUI_MAIN, MAIN_MENU_SERVICES_MENUID,
        0,
        SHOW, NONMOVEABLE, DISP_LIST,
        STR_ID_DMUI_MAIN, IMG_ID_DMUI_MAIN));
#endif  /* __MMI_OP01_MENU_9MATRIX__ */

    ADD_APPLICATION_MENUITEM((MENU_ID_DMUI_OPTION, 0, 3,
                              MENU_ID_DMUI_OP_ACTIVATE,
                              MENU_ID_DMUI_OP_EDIT,
                              MENU_ID_DMUI_OP_ERASE,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DMUI_OPTION_CAPTION, 0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_DMUI_OP_ACTIVATE, MENU_ID_DMUI_OPTION, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_ACTIVATE, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_DMUI_OP_EDIT, MENU_ID_DMUI_OPTION, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_EDIT, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_DMUI_OP_ERASE, MENU_ID_DMUI_OPTION, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DMUI_OP_ERASE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_DMUI_OPTION_EMPTY, 0, 2,
                              MENU_ID_DMUI_OP_EDIT,
                              MENU_ID_DMUI_OP_ERASE,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DMUI_OPTION_CAPTION, 0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_DMUI_OP_EDIT, MENU_ID_DMUI_OPTION_EMPTY, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_EDIT, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_DMUI_OP_ERASE, MENU_ID_DMUI_OPTION_EMPTY, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DMUI_OP_ERASE, 0));

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
    ADD_APPLICATION_MENUITEM((MENU_ID_DMUI_OPTION_DEFAULT_PROFILE, 0, 2,
        MENU_ID_DMUI_OP_ACTIVATE,
        MENU_ID_DMUI_OP_EDIT,
        SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DMUI_OPTION_CAPTION, 0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_DMUI_OP_ACTIVATE, MENU_ID_DMUI_OPTION_DEFAULT_PROFILE, 0,
        SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_ACTIVATE, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_DMUI_OP_EDIT, MENU_ID_DMUI_OPTION_DEFAULT_PROFILE, 0,
                              SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_EDIT, 0));
#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */
}

#endif /* SYNCML_DM_SUPPORT */

