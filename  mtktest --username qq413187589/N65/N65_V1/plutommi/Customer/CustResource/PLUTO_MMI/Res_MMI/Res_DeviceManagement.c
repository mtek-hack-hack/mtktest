/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
/*
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

	FILENAME	: Res_DeviceManagement.c

  	PURPOSE		: Populate Resource for 

	REMARKS		: nil

	AUTHOR		: Paul

	DATE		: April-10-2006

**************************************************************/
#include "MMI_features.h"

#include "MMIDataType.h"
#include "CustomCfg.h"


#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

//#if defined(__MMI_DEVICE_MANAGEMENT__)

#include "DeviceManagementResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"


/*********************************
 ** DM FWU Menu Enum
 **********************************/
typedef enum{

#if defined(__MMI_FWU_VIA_TFTP__)
   MMI_DM_FWU_TFTP_MENUCNT_ENUM,             /* TFTP Support */
#endif

#if defined(__MMI_FWU_VIA_HTTP__)
	MMI_DM_FWU_HTTP_MENUCNT_ENUM,            /* HTTP Support */
#endif	

#if defined(__MMI_FWU_VIA_FILE__)
    MMI_DM_FWU_FILE_MENUCNT_ENUM,            /* File */
#endif

	MMI_EM_MENUCNT_NUM
} MMI_DM_FWU_MENUCNT_ENUM;



/**************************************************************

	FUNCTION NAME		: PopulateDMMenuRes()

  	PURPOSE				: Populate the Device Management Menu Res

	INPUT PARAMETERS	: void

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
void PopulateDMMenuRes(void)
{

    /************************ Menu Items ************************/
	ADD_APPLICATION_MENUITEM((SERVICES_FWU_MENU_ID, MAIN_MENU_SERVICES_MENUID, MMI_EM_MENUCNT_NUM,
    #if defined(__MMI_FWU_VIA_TFTP__)	
		FWU_TFTP_MENU_ID, 
    #endif 		
		FWU_HTTP_MENU_ID, 
		FWU_FILE_MENU_ID,
		SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DM_FWU, IMG_ID_DM_FWU));

#if defined(__MMI_FWU_VIA_TFTP__)   
    /* From TFTP */
	ADD_APPLICATION_MENUITEM((FWU_TFTP_MENU_ID, SERVICES_FWU_MENU_ID, 2,
		FWU_TFTP_UPGRADE_MENU_ID, 
		FWU_TFTP_SETTING_MENU_ID,
		SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DM_FWU_TFTP, IMG_ID_DM_FWU_FROM_TFTP));

	ADD_APPLICATION_MENUITEM((FWU_TFTP_UPGRADE_MENU_ID, FWU_TFTP_MENU_ID, 0,
		SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DM_DOWNLOAD_NOW, IMG_GLOBAL_L1));

	ADD_APPLICATION_MENUITEM((FWU_TFTP_SETTING_MENU_ID, FWU_TFTP_MENU_ID, 0,
		SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DM_SETTINGS, IMG_GLOBAL_L2));
#endif /* #if defined(__MMI_FWU_VIA_TFTP__)	*/

#if defined(__MMI_FWU_VIA_HTTP__)
    /* From HTTP */
	ADD_APPLICATION_MENUITEM((FWU_HTTP_MENU_ID, SERVICES_FWU_MENU_ID, 2,
		FWU_HTTP_UPGRADE_MENU_ID, 
		FWU_HTTP_SETTING_MENU_ID,
		SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DM_FWU_HTTP, IMG_ID_DM_FWU_FROM_HTTP));

	ADD_APPLICATION_MENUITEM((FWU_HTTP_UPGRADE_MENU_ID, FWU_HTTP_MENU_ID, 0,
		SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DM_DOWNLOAD_NOW, IMG_GLOBAL_L1));

	ADD_APPLICATION_MENUITEM((FWU_HTTP_SETTING_MENU_ID, FWU_HTTP_MENU_ID, 0,
		SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DM_SETTINGS, IMG_GLOBAL_L2));
#endif /* #if defined(__MMI_FWU_VIA_HTTP__) */

#if defined(__MMI_FWU_VIA_FILE__)
    /* From File */
	ADD_APPLICATION_MENUITEM((FWU_FILE_MENU_ID, SERVICES_FWU_MENU_ID, 0,
		SHOW, NONMOVEABLE, DISP_LIST, STR_ID_DM_FWU_FILE, IMG_ID_DM_FWU_FROM_FILE));
#endif /*__MMI_FWU_VIA_FILE__*/

    /************************ Strings ************************/
	ADD_APPLICATION_STRING2(STR_ID_DM_FWU ,"Firmware Upgrade","Title String for Firmware Upgrade main screen");

#if defined(__MMI_FWU_VIA_TFTP__)
	ADD_APPLICATION_STRING2(STR_ID_DM_FWU_TFTP, "From TFTP", "Title string for From TFTP screen");
    ADD_APPLICATION_STRING2(STR_ID_DM_SERVER_NAME, "Server Name", "Server name of TFTP");
    ADD_APPLICATION_STRING2(STR_ID_DM_PORT, "Port", "Port of TFTP");
    ADD_APPLICATION_STRING2(STR_ID_DM_FILENAME, "File Name", "Filename of TFTP");
#endif /* #if defined(__MMI_FWU_VIA_TFTP__) */

#if defined(__MMI_FWU_VIA_HTTP__)
	ADD_APPLICATION_STRING2(STR_ID_DM_FWU_HTTP, "From HTTP", "Title string for From HTTP screen");
    ADD_APPLICATION_STRING2(STR_ID_DM_URL, "URL", "URL of HTTP");
    ADD_APPLICATION_STRING2(STR_ID_DM_DEFAULT_URL, "http://", "Default URL");
    ADD_APPLICATION_STRING2(STR_ID_DM_HTTP_NETWORK, "HTTP Network", "Http network");    
    ADD_APPLICATION_STRING2(STR_ID_DM_HTTP_DEFAULT, "Default", "Default");        
#endif /* #if defined(__MMI_FWU_VIA_HTTP__) */

	ADD_APPLICATION_STRING2(STR_ID_DM_FWU_FILE, "From File", "Title string for From File screen");
	ADD_APPLICATION_STRING2(STR_ID_DM_DOWNLOAD_NOW, "Download Now", "Do firmware upgrade");
	ADD_APPLICATION_STRING2(STR_ID_DM_SETTINGS, "Settings", "Firmware upgrade settings");
	ADD_APPLICATION_STRING2(STR_ID_DM_EDIT, "Edit", "To edit focused item");
	ADD_APPLICATION_STRING2(STR_ID_DM_SELECT, "Select", "To select focused item");
	ADD_APPLICATION_STRING2(STR_ID_DM_DOWNLOADING, "Downloading", "Upgrading");
	ADD_APPLICATION_STRING2(STR_ID_DM_DOWNLOADING_WARNING, "This function currently not allow", "Upgrading");
	ADD_APPLICATION_STRING2(STR_ID_DM_UPGRADE_NOW, "Done!\n\nUpgrade Now?", "Upgrading");
	ADD_APPLICATION_STRING2(STR_ID_DM_SHUTDOWN_NOTIFY, "Shutdown for Upgrade", "Upgrading");

	ADD_APPLICATION_STRING2(STR_ID_DM_RESULT_FILE_NOT_FOUND, "File Not Found", "Upgrading");
	ADD_APPLICATION_STRING2(STR_ID_DM_RESULT_ACCESS_DENIED, "Access Denied", "Upgrading");
	ADD_APPLICATION_STRING2(STR_ID_DM_RESULT_SOC_ERROR, "Network Error", "Upgrading");
	ADD_APPLICATION_STRING2(STR_ID_DM_RESULT_TIMEOUT, "Time Out", "Upgrading");
	ADD_APPLICATION_STRING2(STR_ID_DM_RESULT_AUTH_FAIL, "Authentication Fail", "Upgrading");    
	ADD_APPLICATION_STRING2(STR_ID_DM_RESULT_FINAL_CHECK_FAIL, "Checksum Fail", "Upgrading");    

	ADD_APPLICATION_STRING2(STR_ID_DM_DOWNLOAD_RETRY, "Retry?", "Retry");    
	ADD_APPLICATION_STRING2(STR_ID_DM_EMPTY_USERNAME, "Empty Username", "Empty Username");    

	ADD_APPLICATION_STRING2(STR_ID_DM_EMPTY_SERVERNAME, "Empty Servername", "Empty Server name");    
	ADD_APPLICATION_STRING2(STR_ID_DM_EMPTY_FILERNAME, "Empty Filename", "Empty File name");    

	ADD_APPLICATION_STRING2(STR_ID_DM_INVALID_PORT, "Invalid Port", "Invalid Port");    

       ADD_APPLICATION_STRING2(STR_ID_DM_PROF_ADDR, "Server Address:", "Profile Setting string");    
       ADD_APPLICATION_STRING2(STR_ID_DM_OTAP_INSTALL_PROFILE, "Install", "Install string");
       ADD_APPLICATION_STRING2(STR_ID_DM_OTAP_EXIT_INSTALL_CONFIRM, "Exit FOTA Provisioning", "Exit FOTA Provisioning string");       

#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
/* under construction !*/
#endif

    /************************ Images ************************/
	ADD_APPLICATION_IMAGE2(IMG_ID_DM_FWU, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\FOTA\\\\FW_Update.pbm","IMG_FIRMWARE_UPGRADE submenu");
    
        ADD_APPLICATION_IMAGE2(IMG_ID_DM_FWU, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\FOTA\\\\FW_wap.pbm","IMG_ID_DM_FWU_FROM_TFTP submenu");
        ADD_APPLICATION_IMAGE2(IMG_ID_DM_FWU, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\FOTA\\\\FW_URL.pbm","IMG_ID_DM_FWU_FROM_HTTP submenu");
        ADD_APPLICATION_IMAGE2(IMG_ID_DM_FWU, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\FOTA\\\\FW_folder.pbm","IMG_ID_DM_FWU_FROM_FILE submenu");
}

#endif  /* DEVELOPER_BUILD_FIRST_PASS */

//#endif  /* __MMI_DEVICE_MANAGEMENT__ */

