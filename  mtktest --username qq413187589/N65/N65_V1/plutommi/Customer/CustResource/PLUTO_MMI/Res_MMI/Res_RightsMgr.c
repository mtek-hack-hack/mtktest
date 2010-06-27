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
*  LAWS PRINCIPLES.	ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  Res_RightsMgr.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Resource population for Rights Manager  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "CustomCfg.h"
#include "MMI_features.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

#include "RightsMgrResDef.h"

#ifdef __MMI_RMGR__
typedef enum
{
    RMGR_MENU_LIST_RO,
    RMGR_MENU_INFO,
    RMGR_MENU_WHITE_LIST,
    RMGR_MENU_TRANS,
    RMGR_MENU_DB,
    RMGR_MENU_CER_MGR,
    RMGR_MENU_TOTAL
}rmgr_menu_enum;


/*****************************************************************************
 * FUNCTION
 *  PopulateRightsMgrRes
 * DESCRIPTION
 *  Resource population for Rights Manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateRightsMgrRes(void)
{
    U8 i = 0;
    
    /*
     * String
     */
    ADD_APPLICATION_STRING2(STR_ID_RMGR, "Rights Manager", "Rights Manager App Name");

    ADD_APPLICATION_STRING2(STR_ID_RMGR_LIST_RO, "List Rights", "RMGR List Rights");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_TRANS, "Trans. Tracking", "RMGR Trans. Tracking");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_WHITE_LIST, "White List", "RMGR White List");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_INFO, "General Info", "RMGR General Info");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_DB_PROC, "Advance", "STR_ID_RMGR_DB_PROC");    
    ADD_APPLICATION_STRING2(STR_ID_RMGR_SWEEP, "Sweep", "RMGR Sweep");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_BACKUP, "Backup", "STR_ID_RMGR_BACKUP");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_RESTORE, "Restore", "STR_ID_RMGR_RESTORE");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_CERMGR, "Import Certificate", "RMGR Cer Mgr");    
    /* list ro strings */
    ADD_APPLICATION_STRING2(STR_ID_RMGR_LIST_RO_DETAIL, "Detail", "RMGR ListRO - Detail");
        
    /* sweep strings */
    ADD_APPLICATION_STRING2(STR_ID_RMGR_SWEEP_REMOVE_RIGHTS, "Remove Useless Rights", "RMGR Sweep - Remove Useless Rights");

    /* white list strings */
    ADD_APPLICATION_STRING2(STR_ID_RMGR_WHITE_LIST_EDIT_ENTER_ADDRESS, "Enter Address", "RMGR White List Edit - Enter Address");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_WHITE_LIST_EMPTY, "<empty>", "RMGR White List - <empty>");


    /*
     * Image
     */
     
    ADD_APPLICATION_IMAGE2(
        IMG_ID_RMGR_ICON,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_SECUR.PBM",
        "Rights Manager Icon");
     
    /*
     * Menu
     */     
    /* RMGR main menu */
    ADD_APPLICATION_MENUITEM((
        MENU_ID_RMGR,
        MAIN_MENU_SERVICES_MENUID,
        RMGR_MENU_TOTAL,
        MENU_ID_RMGR_LIST_RO,
        MENU_ID_RMGR_INFO,
        MENU_ID_RMGR_WHITE_LIST,
        MENU_ID_RMGR_TRANS,
        MENU_ID_RMGR_DB_PROC,
        MENU_ID_RMGR_CERMGR,
        SHOW, 
        MOVEABLEWITHINPARENT | INSERTABLE,
        DISP_LIST,
        STR_ID_RMGR,
        IMG_ID_RMGR_ICON));

    /* RMGR list ro menu */
    ADD_APPLICATION_MENUITEM((MENU_ID_RMGR_LIST_RO, MENU_ID_RMGR, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ID_RMGR_LIST_RO, (IMG_GLOBAL_L1 + i++)));
    ADD_APPLICATION_MENUITEM((MENU_ID_RMGR_INFO, MENU_ID_RMGR, 0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STR_ID_RMGR_INFO, (IMG_GLOBAL_L1 + i++)));
    ADD_APPLICATION_MENUITEM((MENU_ID_RMGR_WHITE_LIST, MENU_ID_RMGR, 0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STR_ID_RMGR_WHITE_LIST, (IMG_GLOBAL_L1 + i++)));
    ADD_APPLICATION_MENUITEM((MENU_ID_RMGR_TRANS, MENU_ID_RMGR, 0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STR_ID_RMGR_TRANS, (IMG_GLOBAL_L1 + i++)));
    ADD_APPLICATION_MENUITEM((MENU_ID_RMGR_DB_PROC, MENU_ID_RMGR, 0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STR_ID_RMGR_DB_PROC, (IMG_GLOBAL_L1 + i++)));

    ADD_APPLICATION_MENUITEM((MENU_ID_RMGR_CERMGR, MENU_ID_RMGR, 0, SHOW, MOVEABLEACROSSPARENT, DISP_LIST, STR_ID_RMGR_CERMGR, (IMG_GLOBAL_L1 + i++)));

    ADD_APPLICATION_MENUITEM((
        MENU_ID_RMGR_LIST_RO_ALIAS_OPTION,
        0,
        2,
        MENU_ID_RMGR_LIST_RO_DETAIL,
        MENU_ID_RMGR_LIST_RO_DELETE,
        SHOW, 
        MOVEABLEWITHINPARENT | INSERTABLE,
        DISP_LIST,
        0,
        0));

    ADD_APPLICATION_MENUITEM((MENU_ID_RMGR_LIST_RO_DETAIL, MENU_ID_RMGR_LIST_RO_ALIAS_OPTION, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_ID_RMGR_LIST_RO_DETAIL, IMG_GLOBAL_L1));
    ADD_APPLICATION_MENUITEM((MENU_ID_RMGR_LIST_RO_DELETE, MENU_ID_RMGR_LIST_RO_ALIAS_OPTION, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_DELETE, IMG_GLOBAL_L2));
}

#endif /* __MMI_RMGR__ */

#ifdef __DRM_SUPPORT__
void PopulateDRMRes(void)
{
#if __DRM_V02__    
    ADD_APPLICATION_STRING2(STR_ID_DRM_REGISTRATION_SUCCESS,"Registration success", "Registration success message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_RO_ACQUISITION_SUCCESS,"Rights Object acquisition successful", "RO acquisition success message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_DOMAIN_JOIN_SUCCESS,"Successfully joined domain", "Domain join success message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_DOMAIN_LEAVE_SUCCESS,"Successfully left domain", "Doamin leave success message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_REG_FAILED,"Registration with Rights Issuer failed!", "Register failed message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ROAP_XML_ERROR,"ROAP XML parsing error!", "ROAP XML parsing error message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ROAP_CANCELLED,"ROAP messages was cancelled!", "ROAP cancelled message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ROAP_GENERAL_ERROR,"General error during handling of the ROAP trigger", "ROAP -- general error message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ROAP_SOCKET_ERROR,"Socket error", "ROAP -- Socket error message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ROAP_HOST_NOT_FOUND,"Host not found", "ROAP -- Host not found message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ROAP_NOT_EXPECTED,"Not expected server response", "ROAP -- server error message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_NOT_IN_DOMAIN,"Not registered with the specified domain.", "Not in domain message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_DOMAIN_JOIN_FAILED,"Failed to join the domain!", "Join domain fail message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_DOMAIN_LEAVE_FAILED,"Failed to leave the domain!", "Leave domain fail message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ROAP_GENERAL_FAILURE,"General ROAP failure!", "ROAP -- general failure message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ROAP_UNHANDLED_EXC,"Unhandled exception while handling ROAP trigger", "ROAP -- unhandled execption message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_DB_ROLLBACK,"Your data files are out of date or have been tampered.", "Database rollback meessage");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ROAP_UNKNOWN_ERROR,"Unknown error during handling of the ROAP trigger.", "ROAP -- Unknown error message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ERROR_CODE,"Error code", "Error code string");
    ADD_APPLICATION_STRING2(STR_ID_DRM_NOT_REGISTERED,"You are not registered with the Rights Issuer.", "Not registered message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_RIGHTS_ISSUER,"Rights Issuer", "Right Issuer string");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ALLOW_REGISTER,"Would you like to register ??", "Allow register question");
    ADD_APPLICATION_STRING2(STR_ID_DRM_URL,"Url", "Url string");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ALLOW_JOIN,"This domain has expired. Would you like to re-register to this domain?", "Join domain question");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ALLOW_DOMAIN_LEAVE,"Do you want to leave the domain anyway?", "Leave domain question");
    ADD_APPLICATION_STRING2(STR_ID_DRM_DOMAIN,"Domain", "domain string");
    ADD_APPLICATION_STRING2(STR_ID_DRM_UNKNOWN,"Unknown", "unknown string");
    ADD_APPLICATION_STRING2(STR_ID_DRM_CONTENT,"Content", "Content string");
    ADD_APPLICATION_STRING2(STR_ID_DRM_GOTO_RI,"There are no valid rights available for this content. Would you like to go online to activate this content?", "Activate content question 1");
    ADD_APPLICATION_STRING2(STR_ID_DRM_GOTO_RI_DOMAIN,"There are rights available for this content that are not currently usable. Would you like to go online to find out more about these rights?", "Activate content question 2");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ALLOW_PREVIEW_DOWNLOAD,"Would you like to download free preview rights for this content?", "Preview download question");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ALLOW_SILENT_DOWNLOAD,"Would you like to download free rights for this content?", "Silent download question");
    ADD_APPLICATION_STRING2(STR_ID_DRM_BECAME_PLAYABLE,"The following contents became playable.", "Become playable message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_NOTE_FUTURERIGHTS,"Note: You already have rights that will be valid in the future for this content.", "Future rights message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_NOTE_VALIDRIGHTS,"Note: You already have valid rights for this content.", "Have valid rights message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_SERVER_ERRORMESSAGE,"Server returned error message.", "Server error message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ERROR_REDIRECT_URL,"Do you want to visit the url below to resolve the error?", "Redirect URL question");
    ADD_APPLICATION_STRING2(STR_ID_DRM_BROWSE_REGISTER,"There are rights available for this content that were issued by an unknown Rights Issuer. Would you like to go online to find out more about these rights?", "Activate content question 3");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ALLOW_TIMESYNC,"DRM Time synchronization is required to use some time-based rights. Do you want to synchronize?", "Time sync question");
    ADD_APPLICATION_STRING2(STR_ID_DRM_IS_DEVICETIME_CORRECT,"The Rights Issuer reported a DRM Time different from this device's DRM Time. Is this the current time??", "Device time correct question");
    ADD_APPLICATION_STRING2(STR_ID_DRM_TIMEBASED_NOT_PLAYABLE,"The DRM Time on this device became untrusted. While the DRM Time is untrusted, you cannot use time-based rights.", "Time is untrusted message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_ADDITIONAL_RIGHTS,"Would you like to go online to acquire new rights for this content?", "Activate content question 4");

    ADD_APPLICATION_STRING2(STR_ID_DRM_NOT_FOUND               ,"Not Found"                    ,"not found message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_NO_MEMORY               ,"No Memory"                    ,"no memory message");

    ADD_APPLICATION_STRING2(STR_ID_DRM_KEY_NOT_FOUND           ,"Key Not Found"                ,"key not found message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_CERT_NOT_FOUND          ,"Certificate Not Found"   ,"cert root not found message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_INVALID_KEY             ,"Invalid Key"                  ,"corrupt message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_CERT_EXPIRED            ,"Certificate Expired"          ,"cert expired message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_INVALID_CERT            ,"Invalid Certificate Status"   ,"invalid cert status message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_INVALID_RO              ,"Invalid Rights"               ,"invalid ro message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_DOMAIN_EXPIRED          ,"Domain Expired"               ,"domain expired message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_NEED_DOMAIN_UPGD        ,"Need Domain Upgrated"         ,"need domain upgd message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_INVALID_DRMTIME         ,"Invalid DRM Time"             ,"invalid drmtime message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_DB_GENERAL_ERROR        ,"Database Error"               ,"db general error message");

    ADD_APPLICATION_STRING2(STR_ID_DRM_NO_RIGHTS               ,"No Rights"                    ,"no rights message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_NETWORK_ERROR             ,"Server or Network Error"      ,"network error message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_DATABASE_ERROR            ,"Database Error"               ,"database error message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_TIME_UNTRUSTED            ,"Time Untrusted"               ,"timer untrusted message");

    ADD_APPLICATION_STRING2(STR_ID_DRM_START_REGISTER_AGENT  ,"Registering."              ,"Start Register Agent message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_START_ACQUIRE_RO      ,"Getting activation rights.","Start Acquire RO message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_START_DOMAIN_JOIN     ,"Joining the domain."       ,"Start Join Domain message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_START_DOMAIN_LEAVE    ,"Leaving the domain."       ,"Start Leave Domain message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_START_PREVIEW_DOWNLOAD,"Downloading."              ,"Start Download Preview message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_START_SILENT_DOWNLOAD ,"Downloading."              ,"Start Download Silent message");
    ADD_APPLICATION_STRING2(STR_ID_DRM_START_TIME_SYNC       ,"Synchronizing the Time."   ,"Start Sync Time message");

    ADD_APPLICATION_STRING2(STR_ID_DRM_REGISTER        ,"Register"         , "Title of Register"       );
    ADD_APPLICATION_STRING2(STR_ID_DRM_ACQUIRE         ,"Acquire Rights"   , "Title of Acquire RO"     );
    ADD_APPLICATION_STRING2(STR_ID_DRM_JOIN            ,"Join Domain"      , "Title of Join"           );
    ADD_APPLICATION_STRING2(STR_ID_DRM_LEAVE           ,"Leave Domain"     , "Title of Leave"          );
#endif /* __DRM_V02__ */

	ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_RIGHT,"Copyright", "STR_FMGR_DETAIL_RIGHT");
	ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_PROTECTED,"Protected", "STR_FMGR_DRM_PROTECTED");
	ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_UNPROTECTED,"Not Protected", "STR_FMGR_DRM_NOT_PROTECTED");
	ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_UNLIMITED,"Unlimited", "STR_FMGR_DRM_UNLIMITED");	
	ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_COUNT,"Count", "STR_FMGR_DETAIL_COUNT");
	ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_START,"Start Time", "STR_FMGR_DETAIL_START");
	ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_END,"End Time", "STR_FMGR_DETAIL_END");

    ADD_APPLICATION_STRING2(STR_ID_RMGR_SUMMARY         ,"Summary:"   , "STR_ID_DRM_SUMMARY");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_SHARED_RO       ,"Shared:"   , "STR_ID_DRM_SHARED_RO");

    ADD_APPLICATION_STRING2(STR_ID_RMGR_VERSION, "Version:", "Version");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_TIME,    "Time:",    "Time");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_STATUS,  "Need To Sync.:",  "Status");

    ADD_APPLICATION_STRING2(STR_ID_DRM_PLAY            ,"[Play]"     , "String of Permission");
    ADD_APPLICATION_STRING2(STR_ID_DRM_DISPLAY         ,"[Display]"  , "String of Permission");
    ADD_APPLICATION_STRING2(STR_ID_DRM_EXECUTE         ,"[Execute]"  , "String of Permission");
    ADD_APPLICATION_STRING2(STR_ID_DRM_PRINT           ,"[Print]"    , "String of Permission");

#if __DRM_V02__
    ADD_APPLICATION_STRING2(STR_ID_DRM_EXPORT          ,"[Export]"   , "String of Permission");

    ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_ACCUMULATED        ,"Remain:",            "String of Constraint");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_TIMEDCOUNT         ,"Count With Time:",   "String of Constraint");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_TIMEDCOUNT_TIME    ,"Time(s) More Than ", "String of Constraint");
    ADD_APPLICATION_STRING2(STR_ID_RMGR_DETAIL_SEC                ," Second(s)",         "String of Constraint");

	ADD_APPLICATION_STRING2(STR_ID_RMGR_MULTI_PART,  "Multipart", "STR_ID_RMGR_MULTI_PART");
#endif /* __DRM_V02__ */
}
#endif
#endif /* DEVELOPER_BUILD_FIRST_PASS */
