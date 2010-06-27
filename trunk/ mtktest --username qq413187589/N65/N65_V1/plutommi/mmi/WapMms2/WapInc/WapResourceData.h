/*******************************************************************************
 * Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.,
 * All rights reserved.
 * This is unpublished proprietary source code of MobileSoft Technology
 *
 * The copyright notice above does not evidence any actual or intended
 * publication of such source code  
 *******************************************************************************
 */

/*========================================================================
 * Module Name: MmsResourceData.h
 *
 * Module Function: 
 *     Author Name: 
 *     Create Date: 08/29/2005
 *
 *========================================================================
 */
 #ifdef CMS_NEW_APP
#ifndef _CMS_WAP_RESOURCE_DATA_H
#define _CMS_WAP_RESOURCE_DATA_H

// ------include-------------------------
#include "PixtelDataTypes.h"
#include "MmsResourceData.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define WAP_STRING_BASE			(CMS_WAP_BASE + 1)
#define WAP_IMAGE_BASE			(CMS_WAP_BASE + 1)
#define WAP_MENU_BASE				(CMS_WAP_BASE + 1)
#define WAP_SCREEN_BASE			(CMS_WAP_BASE + 1)

#define CMS_WAP_POPUP_DELAY_TIME	 	1000   	/*浏览器DisplayPopup 延时 */				
#define MAX_WAP_PASSWD_LEN  			64		/*认证信息时输入密码最大长度*/
#define MAX_WAP_USERNAME_LEN  		128		/*认证信息时输入用户名最大长度*/
//#define SUPPORT_SWITCH_PROTOCOL		/*定义是否支持浏览器双协议栈切换*/

/***************************************************************************** 
* MMI Resource Data
*****************************************************************************/
/* ---------screen id----- -----*/
typedef enum {
		SCR_ID_WAP_MAIN_MENU = WAP_SCREEN_BASE,	
					
		SCR_ID_WAPOPTION_MAIN_MENU,				/*Option Menu*/		
		SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU,	/*Bookmark Menu*/
		SCR_ID_WAPEMPTYBOOKMARKOPTION_MAIN_MENU,
		SCR_ID_WAPHISTORYOPTION_MAIN_MENU,

		SCR_ID_WAP_BOOKMARK_RENAME_MENU,		/*Bookmark rename*/
		SCR_ID_WAP_BOOKMARK_INPUTURL_MENU,		/*Bookmark input URL*/		
		SCR_ID_WAP_BOOKMARK_ADD_MENU,			/*Book mark add*/
		
		SCR_ID_WAP_LOCALLINK_MENU,			/*Test local link*/
		
		SCR_ID_WAP_HOMEPAGE_MENU,			/*Wap home page*/
		SCR_ID_WAP_OPTION_BOOKMARK_MENU,
		SCR_ID_WAP_BOOKMARK_MENU,			/*Wap bookmark*/	
		SCR_ID_WAP_NEWLINK_MENU,			/*Wap new URL*/
		SCR_ID_WAP_HISTORY_MENU,			/*Wap history record*/
		SCR_ID_WAP_OFFLINE_MENU,				/*native Browser */
		SCR_ID_WAP_SETTINGS_MENU,			/*Wap settings*/
		
		SCR_ID_WAP_SETHOMEPAGE_MENU,		/*Set home page*/	
		SCR_ID_WAP_SETGATEWAY_MENU,		/*Set gateway*/
		SCR_ID_WAP_SETIMAGE_MENU,			/*Set image on*/
		SCR_ID_WAP_SETBGMUSIC_MENU,			/*Set background music*/
		SCR_ID_WAP_SETPUSHMESSAGE_MENU,
		SCR_ID_WAP_SETPSECURITY_MENU,
		SCR_ID_WAP_SETCONNECTMODE_MENU,
		SCR_ID_WAP_SETNETACC_MENU,			/*Set net*/
		SCR_ID_WAP_SETGSMACC_MENU,			/*Set GSM*/
		SCR_ID_WAP_SETGPRSACC_MENU,			/*Set GPRS*/
				
		SCR_ID_WAP_PUSHBOX_MENU,			/*Push Box*/
		SCR_ID_WAP_EDITBOX_MENU,			/**/
		SCR_ID_WAP_PAGEBROWSER_MENU,
		SCR_ID_WAP_INPUTURL_MENU,			/*Input URL*/
		SCR_ID_WAP_INPUTHISTORY_MENU,		/*Input history*/
		SCR_ID_WAP_SAVEFIFLE_MENU,			/*Save file*/
		SCR_ID_WAPPUSHBOXOPTION_MAIN_MENU,
		SCR_ID_WAPOFFLINEOPTION_MAIN_MENU,
		SCR_ID_WAP_SHOWPUSHMESSAGE_MAIN_MENU, /*show push message infor*/
		SCR_ID_WAP_SHOWMESSAGE_MENU,		/*show message infor*/
		
		SCR_ID_WAP_SETTING_SERVICE_ID_MENU,		/*service list*/
		SCR_ID_WAP_SETTING_SERVICE_OPTION_MENU,	/*service option*/
		SCR_ID_WAP_SETTING_SERVICE_EDIT_MENU,		/*edit setting file*/
		SCR_ID_SELECT_OPTION, 					/*select box*/
		SCR_ID_WAP_CURRENTURL_MENU,
		SCR_ID_WAPDONE_MAIN_MENU,			/**/
		SCR_ID_WAP_AUTHENTICATION_EDIT,
		WAP_SCR_ID_DEFINES_MAX
}CMS_WAP_SCREEN_ENUM;

 /* ----- -----string id ----- ----- */
typedef enum {
		STR_WAP_MAIN_MENU_CAPTION = WAP_STRING_BASE,
		STR_WAP_LOCALLINK_ID,
		STR_WAP_HOMEPAGE_ID,
		STR_WAP_BOOKMARK_ID,
		STR_WAP_NEWLINK_ID,				
		STR_WAP_HISTORY_ID,
		STR_WAP_SETTINGS_ID,	
		STR_WAP_OFFLINE_ID,
		STR_WAP_PUSHBOX_ID,
				
		STR_WAP_SETTINGS_CLEARINPUTHISTOY_ID,
		STR_WAP_SETTINGS_CLEARPAGEHISTOY_ID,
		STR_WAP_SETTINGS_CLEARCACHE_ID,
		STR_WAP_SETTINGS_CLEARCOOKIE_ID,
		STR_WAP_SETTINGS_SETPUSHMESSAGE_ID,
		STR_WAP_SETTINGS_SETCONNECTMODE_ID,
		STR_WAP_SETTINGS_SETCERTIFICATES_ID,
		STR_WAP_SETTINGS_SETHOMEPAGE_ID,
		STR_WAP_SETTINGS_SETGATEWAY_ID,
		STR_WAP_SETTINGS_SETIMAGE_ID,
		STR_WAP_SETTINGS_SETBGMUSIC_ID,
		
		STR_WAP_WAPOPTION_MAIN_MENU,	

		STR_WAP_NO_BOOKMARK_ID,
		
		STR_WAP_BOOKMARKOPTION_MAIN_ID,
		STR_WAP_BOOKMARKOPTION_LINK_ID,
		STR_WAP_BOOKMARKOPTION_EDIT_ID,
		STR_WAP_BOOKMARKOPTION_ADD_ID,
		STR_WAP_BOOKMARKOPTION_DELETEALL_ID,
		STR_WAP_BOOKMARKOPTION_DELETE_ID,

		STR_WAP_BOOKMARKOPTION_ADDURL_ID,
		STR_WAP_BOOKMARKOPTION_ADDTITLE_ID,
		STR_WAP_BOOKMARKOPTION_ADDFINISH_ID,

		
		STR_WAP_NO_PAGEHISTORY_ID,		
		STR_WAP_HISTORYOPTION_MAIN_MENU_ID,
		STR_WAP_HISTORYOPTION_DELETE_ID,
		STR_WAP_HISTORYOPTION_DELETEALL_ID,
		
		STR_WAP_OPTION_GOTOLINK_ID,
		STR_WAP_OPTION_BACK_ID,
		STR_WAP_OPTION_SAVEHOMEPAGE_ID,
		STR_WAP_OPTION_SAVECURRENTPAGE_ID,	
		STR_WAP_OPTION_URL_ID,
		STR_WAP_OPTION_REFRESH_ID,
		STR_WAP_OPTION_BOOK_ID,
		STR_WAP_OPTION_BROWSERHOMEPAGE_ID,
		STR_WAP_OPTION_NEWLINK_ID,
		STR_WAP_OPTION_PUSHBOX_ID,
		STR_WAP_OPTION_BROWSEREXIT_ID,
		STR_WAP_OPTION_DOWNPIC_ID,
		STR_WAP_OPTION_DOWNMUSIC_ID,

		STR_WAP_SETTINGS_HOMEPAGE_ID,
		STR_WAP_SETTINGS_GATEWAY_ID,
		STR_WAP_SETTINGS_PORT_ID,
		STR_WAP_SETTINGS_IMAGES_ID,
		STR_WAP_SETTINGS_IMAGEON_ID,
		STR_WAP_SETTINGS_IMAGEOFF_ID,
		
		STR_WAP_SETTINGS_BGMUSIC_ID,
		STR_WAP_SETTINGS_BGMUSICON_ID,
		STR_WAP_SETTINGS_BGMUSICOFF_ID,

		STR_WAP_SETTINGS_PUSHMESSAGE_ID,
		STR_WAP_SETTINGS_PUSHMESSAGEON_ID,
		STR_WAP_SETTINGS_PUSHMESSAGEOFF_ID,

		STR_WAP_SETTINGS_SETCERTIFICATESON_ID,
		STR_WAP_SETTINGS_SETCERTIFICATESOFF_ID,
		STR_WAP_SETTINGS_SETCONNECTMODE_HTTP_ID,
		STR_WAP_SETTINGS_SETCONNECTMODE_WAP_ID,
		
		STR_WAP_SETTINGS_SETNETACC_ID,
		STR_WAP_SETTINGS_SETGSMNETACC_ID,
		STR_WAP_SETTINGS_SETGPRSNETACC_ID,
		STR_WAP_NEWLINK_URL_ID,
		STR_WAP_LINK,
		STR_WAP_EDIT,


		STR_WAP_PAGELINK_ID,
		STR_WAP_EDITBOX_ID,


		STR_WAP_NEWLINK_INPUTURL_ID,
		STR_WAP_NEWLINK_HISTORYURL_ID,
		STR_WAP_INPUTHISTORY_ID,

		STR_WAP_SAVEFIFLE_ID,

		STR_WAP_NO_PUSHMESSAGE_ID,
		STR_WAP_PUSHBOXOPTION_MAIN_MENU_ID,
		STR_WAP_PUSHBOXOPTION_LINK_ID,
		STR_WAP_PUSHBOXOPTION_DELETE_ID,
		STR_WAP_PUSHBOXOPTION_DELETEALL_ID,

		STR_WAP_NO_OFFLINE_ID,
		STR_WAP_OFFLINEOPTION_MAIN_MENU_ID,
		STR_WAP_OFFLINEOPTION_LINK_ID,
		STR_WAP_OFFLINEOPTION_DELETE_ID,
		STR_WAP_OFFLINEOPTION_DELETEALL_ID,
		
		STR_WAP_PAGELINKFAILED_ID,
		STR_WAP_HOMEPAGEISNONE_ID,
		STR_WAP_BOOKMARKISFULL_ID,
		STR_WAP_WAPPUSHARRIVED_ID,
		STR_WAP_OFFLINE_FULL_ID,
		STR_WAP_DISPOSEPAGE_ID,
		STR_WAP_PUSHURL_ID,
		STR_WAP_PUSHMESSAGE_ID, 
		STR_WAP_TRUSTED_CERTIFICATES_ID,
		STR_WAP_GATEWAY_ERROR_ID,
		STR_WAP_INFOBOX_ID,
				
		STR_WAP_STATE_DOWNLOAD_FAIL,
		STR_WAP_STATE_DOWNLOADING,
		STR_WAP_STATE_DOWNLOAD_SUCCESS,
		STR_WAP_STATE_DECODE_FAIL,
		STR_WAP_STATE_GATEWAY_DISCONNECT,
		STR_WAP_STATE_HANGUPING,
		STR_WAP_STATE_PARSER_FAIL,
		STR_WAP_STATE_CHARSET_UNSUPPORT,
		STR_WAP_STATE_HOMEPAGE_BLANK,
		STR_WAP_STATE_PAGE_REFRESHING,
		STR_WAP_STATE_PAGE_ERROR,
		STR_WAP_STATE_DOWNLOAD_BEGAIN,
		STR_WAP_STATE_CONNECTING,
		STR_WAP_STATE_DIALING,
		STR_WAP_STATE_DIAL_FAILED,
		STR_WAP_STATE_SENDING,
		STR_WAP_STATE_PARAM_ERROR,
		STR_WAP_STATE_NO_MEMORY,
		STR_WAP_STATE_CONNECT_FAILED,
		STR_WAP_STATE_TIMER_ERROR,
		STR_WAP_STATE_UNKNOWN_ERROR,
		STR_WAP_STATE_WAPSTACK_BUSY,
		STR_WAP_STATE_NETWORK_TIMEOUT,
		STR_WAP_STATE_RECONNECTING,
		STR_WAP_STATE_WAPSTACK_SUSPENDED,
		STR_WAP_STATE_WAPSTACK_RESUME_FAILED,
		STR_WAP_STATE_WAPSTACK_RESUMED,
		STR_WAP_STATE_PARSERING,
		STR_WAP_STATE_LAYOUTING,
		STR_WAP_STATE_DRAWING,
		STR_WAP_STATE_WMLSCRIPT,
		STR_WAP_STATE_WTAI,
		STR_WAP_STATE_TLS_WAIT_CONFIRM,
		STR_WAP_STATE_WTLS_WAIT_CONFIRM,
		STR_WAP_STATE_OS_SOCKET_INVALIED,		
		STR_WAP_STATE_NORMAL,

		STR_WAP_NOT_READY_YET,
		STR_WAP_WARING_NETBUSY,
		STR_WAP_APPLICATION_NOT_SUPPORT,
		STR_WAP_INPUT_USERNAME,
		STR_WAP_INPUT_PASSWORD,
		STR_WAP_AUTHENTICATION_EDIT,
		/* 添加各种提示信息字符串 */
		STR_WAP_RESOURCE_EMPTY, 		//NULL String
		STR_WAP_RESOURCE_BACK,		//"Back"||"返回"
		STR_WAP_RESOURCE_RETRY,		//"Retry"||"重试"
		STR_WAP_RESOURCE_LINK,		//"Link"||"链接"
		STR_WAP_RESOURCE_EDIT,		//"Edit"||"编辑"
		STR_WAP_RESOURCE_SELECT,		//"Select"||"选择"
		STR_WAP_RESOURCE_CANCLE,		//"Cancle"||"取消"
		STR_WAP_RESOURCE_OK,			//"OK"||"确定"
		STR_WAP_RESOURCE_EXIT,  		//"EXIT"||"退出"	
		STR_WAP_NO_SERVER,			//"No server"
		STR_WAP_NO_SUCH_SERVER,		//"No such server"
		STR_WAP_DIALING_FAILED,		//"Dialing failed"
		STR_WAP_CONNECTION_DISC,    	//"Connection disconnected"
		STR_WAP_DIALING_CON_DISC,   	//"Dialing connection is disconnected"
		STR_WAP_DOWN_RING_FAIL,     	//"Download ring failed"
		STR_WAP_DATA_ERROR,             	//"Data error"
		STR_WAP_SERVER_REJECT,          	//"Server reject"
		STR_WAP_INVALID_ADDRESS,        //"Invalid address"
		STR_WAP_INVALID_URL,            	//"Invalid url"
		STR_WAP_ERROR_PAGE,             	//"Error page"
		STR_WAP_ERROR_PAGE_TRY,         //"Error page,please try later"
		
		STR_WAP_GETWAY_ERROR,           	//"Gateway error"
		STR_WAP_GETWAY_NO_RES,          //"Gateway not response"
		STR_WAP_SERVER_ERROR,           	//"Server error"
		STR_WAP_TIME_OUT,               	//"Time out"
		STR_WAP_RES_TIME_OUT,           	//"The server's response time out"
		STR_WAP_UNSUPPORT_FILE,         	//"not support file"
		STR_WAP_UNSUPPORT_SORRY,       //"Sorry! Not support such file type%s%s"

		STR_WAP_SUBMIT,                 		//"submit"
		STR_WAP_BUTTON,                 		//"button"
		STR_WAP_RESET,                  		//"reset"

		STR_WAP_SUBJECT,                		//"Subject :"
		STR_WAP_ISSURER,                		//"Issuer :"
		STR_WAP_VALID_NOTBEFORE,        //"Valid not before :"
		STR_WAP_VALID_NOTAFTER,         //"Valid not after :"
		STR_WAP_MD_ALGORITHMS,          //"MD algorithms : sha1\nDigest value :"
		STR_WAP_SIGN_ALGO,              	//"Signature algorithms :"
		STR_WAP_SIGNATURE,              	//"Signature :\n"

		STR_WAP_VALID_CERT,             	//"valid security certificate"
		STR_WAP_INVALID_CERT,           	//"invalid security certificate or unsupported certificate type"
		STR_WAP_UNTRUST_CERT,           	//"this certificate cannot be verified up to a trusted certificateion authority"
		STR_WAP_REVOKED_CERT,           	//"security certificate revoked"
		STR_WAP_EXPIER_CERT,            	//"security certificate expired or not valid yet"
		STR_WAP_ERPURPOSE_CERT,         //"invalid security certificate purpose"
		STR_WAP_UNMACTH_CERT,           	//"The name on the security certificate is invalid or does not match the name of the site"
		
		STR_WAP_UNKNOWN_ERROR,          //"unknown error"
		STR_WAP_CERT_WARNING_PROBLEM,   //"information you exchange with this site cannot be viewed or changed by others , however , there is a problem with the site's security certificate"
		
		STR_WAP_ENCRYPT_METHOD,         //"%s with %d bits encryption( High ) , RSA with %d bits exchange"
		STR_WAP_CERT_INFO,              	//"security certificate info"
		
		STR_WAP_MALLOC_FAILED,          	//"system malloc failed,exit please!"
		STR_WAP_NET_EXCEPTION,          	//"Net exception, please exit browser"

		STR_WAP_BIG_FILE,               		//"Big file"
		STR_WAP_BIG_FILE_TO_DOWN,     //"File is too big to download"

		STR_WAP_CON_SECURED,			//"Connection Secured"
		STR_WAP_CON_TO_SERVICE,		//"Connecting to service"
		STR_WAP_SECURED_CA,			//"Connecting in security to server,whether continue?"
										
		STR_WAP_DOWNLOADING_IMAGE,   //"Downloading(%d/%d)"
		STR_WAP_DOWNLOADIMG_OK,	  //"Download Finished"

		STR_WAP_DUPLICATE_FILENAME,   
		STR_WAP_INVALID_FILE_NAME,
		STR_WAP_CANNOT_CREATE_FILE,
		STR_WAP_SETTING_ERROR,
		STR_WAP_CANCLE_CONFIRM,
		STR_WAP_NETACCOUNT_ERROR, 	//soc_create error displaypop
		STR_WAP_FAILURE_MEM_CAP_EXCEEDED,
		STR_WAP_NO_TITLE,
		WAP_STRING_ID_DEFINES_MAX

} WAP_STRING_ENUMS;

/*==============================================================
 * Wap icon enum
==============================================================*/
typedef enum {
		IMG_WAP_BEAIM_IMAGE	= WAP_IMAGE_BASE,
              IMG_WAP_MAIN_MENU_ICON,
		IMG_WAPHOMEPAGE_MAIN_MENU_ICON,
		IMG_WAPSETTINGS_MAIN_MENU_ICON,
		IMG_WAPBOOKMARK_MAIN_MENU_ICON,
		IMG_WAPOFFLINE_MAIN_MENU_ICON,
		IMG_WAPINBOX_MAIN_MENU_ICON,
		IMG_WAPHISTORY_MAIN_MENU_ICON,
		IMG_WAPINPUTURL_MAIN_MENU_ICON,
		IMG_WAPLOCALLINK_MAIN_MENU_ICON,
		IMG_WAPSUCCESS_MAIN_MENU_ICON,
		IMG_WAPDOWNLOADING_MAIN_MENU_ICON,
		IMG_WAPREAD_MAIN_MENU_ICON,
		IMG_WAPUNREAD_MAIN_MENU_ICON,
		IMG_WAPPAGEDOWNLOAD_MAIN_MENU_ICON,
		IMG_WAPIMGDOWNLOAD_MAIN_MENU_ICON,
		IMG_WAPIMGWAIT_MAIN_MENU_ICON,
		IMG_WAPIMGLINKONE_MAIN_MENU_ICON,
		IMG_WAPIMGLINKTWO_MAIN_MENU_ICON,
		IMG_WAPIMGLINTTHREE_MAIN_MENU_ICON,
		IMG_WAPIMGSSLPAGE_MAIN_MENU_ICON,
		IMG_WAPPAGE_PROCESS_ICON,

		IMG_WAP_PICTOGRAM_CORE_ARROW_UP_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_DOWN_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_RIGHT_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_LEFT_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_UPPERRIGHT_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_UPPERLEFT_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_LOWERRIGHT_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_LOWERLEFT_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERUP_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERDOWN_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERRIGHT_ICON,
		IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERLEFT_ICON,

		IMG_WAP_PICTOGRAM_CORE_BUTTON_1_ICON,
		IMG_WAP_PICTOGRAM_CORE_BUTTON_2_ICON,
		IMG_WAP_PICTOGRAM_CORE_BUTTON_3_ICON,
		IMG_WAP_PICTOGRAM_CORE_BUTTON_4_ICON,
		IMG_WAP_PICTOGRAM_CORE_BUTTON_5_ICON,
		IMG_WAP_PICTOGRAM_CORE_BUTTON_6_ICON,
		IMG_WAP_PICTOGRAM_CORE_BUTTON_7_ICON,
		IMG_WAP_PICTOGRAM_CORE_BUTTON_8_ICON,
		IMG_WAP_PICTOGRAM_CORE_BUTTON_9_ICON,
		IMG_WAP_PICTOGRAM_CORE_BUTTON_0_ICON,

		IMG_WAP_PICTOGRAM_CORE_ACTION_MAKEPHONECALL_ICON,
		IMG_WAP_PICTOGRAM_CORE_ACTION_FIND_ICON,
		IMG_WAP_PICTOGRAM_CORE_ACTION_USERAUTHENTICATION_ICON,
		IMG_WAP_PICTOGRAM_CORE_ACTION_NEXTITEM_ICON,
		IMG_WAP_PICTOGRAM_CORE_ACTION_CLEAR_ICON,
		IMG_WAP_PICTOGRAM_CORE_ACTION_STOP_ICON,
		IMG_WAP_PICTOGRAM_CORE_ACTION_TOP_ICON,
		IMG_WAP_PICTOGRAM_CORE_ACTION_NEXT_ICON,
		IMG_WAP_PICTOGRAM_CORE_ACTION_BACK_ICON,

		IMG_WAP_PICTOGRAM_CORE_MESSAGE_RECEIVE_ICON,
		IMG_WAP_PICTOGRAM_CORE_MESSAGE_SEND_ICON,
		IMG_WAP_PICTOGRAM_CORE_MESSAGE_MESSAGE_ICON,
		IMG_WAP_PICTOGRAM_CORE_MESSAGE_ATTACHMENT_ICON,
		IMG_WAP_PICTOGRAM_CORE_MESSAGE_FOLDER_ICON,
		IMG_WAP_PICTOGRAM_CORE_MESSAGE_INBOX_ICON,
		IMG_WAP_PICTOGRAM_CORE_MESSAGE_OUTBOX_ICON,
		
		IMG_WAP_PICTOGRAM_CORE_STATE_SECURE_ICON,
		IMG_WAP_PICTOGRAM_CORE_STATE_INSECURE_ICON,
		IMG_WAP_PICTOGRAM_CORE_STATE_COPYRIGHT_ICON,
		IMG_WAP_PICTOGRAM_CORE_STATE_TRADEMARK_ICON,
		IMG_WAP_PICTOGRAM_CORE_STATE_UNDERCONSTRUCTION_ICON,
		IMG_WAP_PICTOGRAM_CORE_STATE_BEGINNER_ICON,

		IMG_WAP_PICTOGRAM_CORE_MEDIA_BOOK_ICON,
		IMG_WAP_PICTOGRAM_CORE_MEDIA_VIDEO_ICON,
		IMG_WAP_PICTOGRAM_CORE_MEDIA_CD_ICON,
		IMG_WAP_PICTOGRAM_CORE_MEDIA_DVD_ICON,
		IMG_WAP_PICTOGRAM_CORE_MEDIA_GAME_ICON,
		IMG_WAP_PICTOGRAM_CORE_MEDIA_RADIO_ICON,
		IMG_WAP_PICTOGRAM_CORE_MEDIA_TV_ICON,

		IMG_WAP_PICTOGRAM_CORE_INFO_NOTICE_ICON,
		IMG_WAP_PICTOGRAM_CORE_INFO_CHARGED_ICON,
		IMG_WAP_PICTOGRAM_CORE_INFO_FREEOFCHARGE_ICON,
		IMG_WAP_PICTOGRAM_CORE_INFO_NEW_ICON,
		IMG_WAP_PICTOGRAM_CORE_INFO_POSITION_ICON,
		IMG_WAP_PICTOGRAM_CORE_INFO_TOLLFREE_ICON,
		IMG_WAP_PICTOGRAM_CORE_INFO_SHARPDIAL_ICON,
		IMG_WAP_PICTOGRAM_CORE_INFO_RESERVED_ICON,
		IMG_WAP_PICTOGRAM_CORE_INFO_SPEECHINFO_ICON,
		
		WAP_IMAGE_ID_DEFINES_MAX
} WAP_IMAGE_ENUMS;

/*==============================================================
 * Wap main menu enum
==============================================================*/
typedef enum
{
		WAP_MENU_HOMEPAGE_MENU, 
		WAP_MENU_BOOKMARK_MENU,
		WAP_MENU_NEWLINK_MENU, 
		WAP_MENU_PAGEHISTORY_MENU, 
		WAP_MENU_OFFLINE_MENU,
		WAP_MENU_SETTINGS_MENU,	
		WAP_MENU_PUSHBOX_MENU,
		NUM_WAP_MAIN_MENU
}CMS_WAP_MENU_ENUMS;

/*==============================================================
 * Wap main menu enum
==============================================================*/
typedef enum
{
		WAP_NEWLINK_MENU_INPUTURL_MENU,
		WAP_NEWLINK_MENU_HISTORY_MENU,
		NUM_WAP_NEWLINK_MAIN_MENU
}CMS_WAP_NEWLINK_MENU_ENUMS;

/*==============================================================
 * Wap setting menu enum
==============================================================*/
typedef enum
{
		WAP_SETTINGS_MENU_SERVICE_ID_MENU,
		WAP_SETTINGS_MENU_CLEARPAGEHISTOY_MENU,
		WAP_SETTINGS_MENU_CLEARCACHE_MENU,
		WAP_SETTINGS_MENE_CLEARCOOKIE_MENU,
		WAP_SETTINGS_MENU_PUSHING_MENU,	
		WAP_SETTINGS_MENU_SETIMAGE_MENU,
		WAP_SETTINGS_MENU_SETBGMUSIC_MENU,	
		WAP_SETTINGS_MENU_SETCERTIFICATES_MENU,
		#ifdef SUPPORT_SWITCH_PROTOCOL
		WAP_SETTINGS_MENU_SETCONNECTMODE_MENU,
		#endif
		NUM_WAP_SETTINGS_MENU
}CMS_WAP_SETTINGS_ENUMS;

/*==============================================================
 * Wap setting net enum
==============================================================*/
typedef enum
{
		WAP_SETTINGS_MENU_SETGSMNETACC_MENU,
		WAP_SETTINGS_MENU_SETGPRSNETACC_MENU,
		NUM_WAP_SETTINGS_MENU_SETNETACC_MENU
}CMS_WAP_SETTINGS_MENU_SETNETACC_ENUMS;

/*==============================================================
 * Wap setting gsm net enum
==============================================================*/
typedef enum
{
		WAP_SETTINGS_MENU_SETGSMNETACC1_MENU,
		WAP_SETTINGS_MENU_SETGSMNETACC2_MENU,
		WAP_SETTINGS_MENU_SETGSMNETACC3_MENU,
		WAP_SETTINGS_MENU_SETGSMNETACC4_MENU,
		WAP_SETTINGS_MENU_SETGSMNETACC5_MENU,
		NUM_WAP_SETTINGS_MENU_SETGSMNETACC_MENU
}CMS_WAP_SETTINGS_MENU_SETGSMNETACC_ENUMS;

/*==============================================================
 * Wap setting gprs net enum
==============================================================*/
typedef enum
{
		WAP_SETTINGS_MENU_SETGPRSNETACC1_MENU,
		WAP_SETTINGS_MENU_SETGPRSNETACC2_MENU,
		WAP_SETTINGS_MENU_SETGPRSNETACC3_MENU,
		WAP_SETTINGS_MENU_SETGPRSNETACC4_MENU,
		WAP_SETTINGS_MENU_SETGPRSNETACC5_MENU,
		NUM_WAP_SETTINGS_MENU_SETGPRSNETACC_MENU
}CMS_WAP_SETTINGS_MENU_SETGPRSNETACC_ENUMS;

/*==============================================================
 * Wap setting image enum
==============================================================*/
typedef enum
{
		WAP_SETTINGS_MENU_SETIMAGEOFF_MENU,
		WAP_SETTINGS_MENU_SETIMAGEON_MENU,
		NUM_WAP_SETIMAGE_MENU
}CMS_WAP_SETIMAGE_ENUMS;

/*==============================================================
 * Wap setting background music enum
==============================================================*/
typedef enum
{
		WAP_SETTINGS_MENU_SETBGMUSICOFF_MENU,
		WAP_SETTINGS_MENU_SETBGMUSICON_MENU,
		NUM_WAP_SETBGMUSIC_MENU
}CMS_WAP_SETMUSICON_ENUMS;


/*==============================================================
 * Wap setting push  enum
==============================================================*/
typedef enum
{
		WAP_SETTINGS_MENU_SETPUSHMESSAGEOFF_MENU,
		WAP_SETTINGS_MENU_SETPUSHMESSAGEON_MENU,
		NUM_WAP_SETPUSHMESSAGE_MENU
}CMS_WAP_SETPUSHMESSAGE_ENUMS;
/*==============================================================
 * Wap setting gateway and port enum
==============================================================*/
typedef enum
{
		WAP_SETTINGS_MENU_SETWAPGATEWAY_MENU,
		WAP_SETTINGS_MENU_SETWAPPORT_MENU,
		NUM_WAP_SETGATEWAY_MENU
}CMS_WAP_SETGATEWAY_ENUMS;


/*==============================================================
 * Wap option menu enum
==============================================================*/
typedef enum
{
	//	WAP_OPTION_MENU_GOTOLINK_MENU,
		WAP_OPTION_MENU_CURRENTURL_MENU,
		WAP_OPTION_MENU_REFRESH_MENU,
		WAP_OPTION_MENU_BROWSERHOMEPAGE_MENU,
		WAP_OPTION_MENU_BACK_MENU,
		WAP_OPTION_MENU_SAVEHOMEPAGE_MENU,
		WAP_OPTION_MENU_BOOK_MENU,
		WAP_OPTION_MENU_SAVECURRENTPAGE_MENU,	//add by xiaoyong for save current page
		WAP_OPTION_MENU_BROWSEREXIT_MENU,
		NUM_WAP_OPTION
}WAP_OPTION_NUMS;


/*==============================================================
 * Wap bookmark menu enum
==============================================================*/
typedef enum
{
		WAP_BOOKMARKOPTION_MENU_LINK_MENU,
		WAP_BOOKMARKOPTION_MENU_EDIT,
		WAP_BOOKMARKOPTION_MENU_ADD,
		WAP_BOOKMARKOPTION_MENU_DELETEALL,
		WAP_BOOKMARKOPTION_MENU_DELETE,
		NUM_WAP_BOOKMARKOPTION
}WAP_BOOKMARKOPTION_NUMS;

/*==============================================================
 * Wap add a new bookmark enum
==============================================================*/
typedef enum
{
		WAP_BOOKMARKOPTION_MENU_ADDURL_MENU,
		WAP_BOOKMARKOPTION_MENU_ADDTITLE_MENU,
		WAP_BOOKMARKOPTION_MENU_ADDFINISH_MENU,
		NUM_WAP_BOOKMARKADD
}WAP_BOOKMARKADD_NUMS;
/*==============================================================
 * 
==============================================================*/
typedef enum
{
		WAP_HISTORYOPTION_MENU_DELETE,
		WAP_HISTORYOPTION_MENU_DELETEALL,
		NUM_WAP_HISTORYOPTION	
}WAP_HISTORYOPTION_NUMS;
/*==============================================================
 * Wap push option menu enum
==============================================================*/
typedef enum
{
		WAP_PUSHBOXOPTION_MENU_LINK_MENU,
		WAP_PUSHBOXOPTION_MENU_DELETE,
		WAP_PUSHBOXOPTION_MENU_DELETEALL,
		NUM_WAP_PUSHBOXOPTION	
}WAP_PUSHBOXOPTION_NUMS;

/*==============================================================
 * Wap offline option menu enum
==============================================================*/
typedef enum
{
		WAP_OFFLINEOPTION_MENU_LINK_MENU,
		WAP_OFFLINEOPTION_MENU_DELETE,
		WAP_OFFLINEOPTION_MENU_DELETEALL,
		NUM_WAP_OFFLINEOPTION	
}WAP_OFFLINEOPTION_NUMS;

/*==============================================================
 * Wap option state enum
==============================================================*/
typedef enum
{
		WAP_OPTION_BOOKMARKRENAME,
		WAP_OPTION_BOOKMARKTITLEADD,
		WAP_OPTION_BOOKMARKURLADD,
		WAP_OPTION_NEWLINK,
		WAP_OPTION_HOMEPAGE,
		WAP_OPTION_GATEWAY,
		WAP_OPTION_PORT,
		NUM_WAP_OPTIONSELECT
}WAP_OPTIONSELECT_NUMS;
typedef enum
{
		MAIN_MENU_STATE_HOMEPAGE, 
		MAIN_MENU_STATE_BOOKMARK,
		MAIN_MENU_STATE_NEWLINK, 
		MAIN_MENU_STATE_PAGEHISTORY, 
		MAIN_MENU_STATE_OFFLINE,
		MAIN_MENU_STATE_SETTINGS,	
		MAIN_MENU_STATE_PUSHBOX,
		MAIN_MENU_STATE_AUTHENTICATION
}CMS_MAIN_MENU_STATE_ENUMS;
/*==============================================================
 * Wap touchpanel state enum
==============================================================*/
enum CMS_TOUCHPANEL_EVENT
{
	CTPE_TOUCHPANEL_BASIC_MASK		= 0X00FF ,
	CTPE_TOUCHPANEL_ADVOPTION_MASK	= 0XFF00 ,

	CTPE_PEN_DOWN	=	1,
	CTPE_PEN_UP		=	2,
	CTPE_PEN_MOVE	=	3
};

/*==============================================================
 * Wap Setting -Service List 
==============================================================*/
enum
{
	WAP_CFG_UNKNOWN = 0,
	WAP_CFG_SERVICE_ID,		/* 运营商ID */
	WAP_CFG_CENTRE,			/* 运营商主页地址 */
	WAP_CFG_GATEWAY,			/* 网关 */
	WAP_CFG_PORT,				/* 端口 */
	WAP_CFG_GPRS				/* GPRS模式设定 */
};

typedef struct _WAP_CONFIG
{
	U8	service_id[MMS_MAX_SERVICE_ID_LENGTH];			/* 存放运营商ID*/
	U8	centre_addr[MMS_MAX_CENTRE_ADDR_LENGTH];		/* 存放运营商地址*/
	U8	gateway[MMS_MAX_GATEWAY_LENGTH];				/* 存放运营商网关*/
	U8	port[MMS_MAX_PORT_LENGTH];						/* 存放运营商端口*/
	S8 	gprs_mode;										/* GPRS模式  */
}
WAP_CONFIG;	/*WAP网络设置结构 */

/***************************************************************************** 
* 
*****************************************************************************/
/*调整如下数值，可调整服务设置列表*/
enum
{
	WAP_SERVICE_CHINAMOBILE = 0	/*中国移动 		*/
};
/*中国台湾运营商配置*/
enum
{
	WAP_SERVICE_TCC = 0,				/*台灣大哥大	*/
	WAP_SERVICE_CHT,				/*中華電信 		*/
	WAP_SERVICE_FET,				/*遠傳電信		*/
	WAP_SERVICE_KGT,				/*和信MMS		*/
	WAP_SERVICE_TAT,				/*泛亞電信 		*/
	WAP_SERVICE_MBT				/*東信電訊 		*/
};
/*西班牙运营商配置*/
enum
{
	WAP_SERVICE_SPAIN_MOVISTAR = 0,	/*西班牙Movistar	*/
	WAP_SERVICE_SPAIN_VODAFONE,		/*西班牙Vodafone	*/
	WAP_SERVICE_SPAIN_AMENA		/*西班牙Amena	*/
};
/*泰国运营商配置*/
enum
{
	WAP_SERVICE_THAILAND_AIS = 0,	/*泰国AIS		*/
	WAP_SERVICE_THAILAND_DTAC,		/*泰国DTAC	*/
	WAP_SERVICE_THAILAND_ORANGE	/*泰国Orange	*/
};
/***************************************************************************** 
* Functions Decleration
*****************************************************************************/
void Cms_Browser_PostMessage(unsigned int);
void EntryScrWapBrowserMenuList(void);

void mmi_wap_main_homepage(void);
void mmi_wap_main_bookmark(void);
void mmi_wap_main_newlink(void);
void mmi_wap_main_history(void);
void mmi_wap_main_offline(void);
void mmi_wap_main_settings(void);
void mmi_wap_main_pushbox(void);
void mmi_wap_option_gotolink(void);
void mmi_wap_option_savehomepage(void);
void mmi_wap_option_exitbrowser(void);
void mmi_wap_option_back(void);
void mmi_wap_option_currentURL(void);
void mmi_wap_option_refresh(void);
void mmi_wap_option_savebookmark(void);
void mmi_wap_option_savecurrentpage(void);
void mmi_wap_option_homepage (void);
void mmi_wap_bookmark_link(void);
void mmi_wap_bookmark_rename(void);
void mmi_wap_bookmark_deleteall(void);


void mmi_wap_bookmark_delete(void);
void mmi_wap_bookmark_add(void);
void mmi_wap_push_link(void);
void mmi_wap_push_delete(void);
void mmi_wap_push_deleteall(void);
void mmi_wap_offline_link(void);
void mmi_wap_offline_delete(void);
void mmi_wap_offline_deleteall(void);
void mmi_wap_offline_messagebox(void);
void mmi_wap_offline_msgbox(void);
void mmi_wap_settings_clearhistory(void);
void mmi_wap_settings_clearcache(void);
void mmi_wap_settings_clearcookie(void);
void mmi_wap_settings_pushmessage(void);
void mmi_wap_settings_homepage(void);
void mmi_wap_settings_gateway(void);
void mmi_wap_settings_image(void);
void mmi_wap_settings_bgmusic(void);
void mmi_wap_settings_netacc(void);
void mmi_wap_setnet_gsm(void);
void mmi_wap_setnet_gprs(void);	
void mmi_wap_settings_protocal(void);
void mmi_wap_settings_certificates(void);

void WAPBOOKMARKRENAME(void);
void DeleteSelectBookMark(void);

unsigned char *Brw_Offline_GetFileContent(unsigned char* OfflineFileName,unsigned int* Sizelen);

void CmsBrwPageBrowserSuccess(void);
void Browser_GoPrevURIEventByRightKey(void);

void SaveHomepageEvent(void);
void OptionBackEvent(void);
void OptionGetCurrentURLEvent(void);
void OptionRefreshCurrentPageEvent(void);
void RefreshEvent(void);
void SaveBookmarkEvent(void);
void SaveCurrentPageEvent(void);

void WapBookMarkRename(void);
void BackToMainMenuEvent(void);
 void WapBookMarkEditEvent(void);
void Bookmark_deleteall_Entry(void);
void Bookmark_delete_Entry(void);
void push_delete_Entry(void);
void push_deleteall_Entry(void);

void RenameSelectBookMark(void);
void ChangeSelectBookMarkUrl(void);

void DeleteSelectHistory(void);
void DeleteAllBookMark(void);
void DeleteAllHistory(void);

void DeleteSelectPush(void);
void DeleteAllPush(void);

void mmi_wap_setnet_gsm(void);
void mmi_wap_setnet_gprs(void);

void GetBookmarkIndex(S32 nIndex);
void GetHistoryIndex(S32 nIndex);
void GetPushboxIndex(S32 nIndex);
void GetGsmAccIndex(S32 nIndex);
void GetGprsAccIndex(S32 nIndex);
void GetImageSetIndex(S32 nIndex);
void GetWapDoneIndex(S32 nIndex);

void NewLinkBrowser(void);

void WapGateWaySettingsFillInlineStruct(void);
void EntryScrWapLocalLinkMenuList(void); 
void EntryScrWapHomePageMenuList(void);

void EntryScrWapOPtionBookMarkMenuList(void);
void EntryScrWapBookMarkMenuList(void);
void BrowserBookMarkOption(void);
void BrowserEmptyBookMarkOption(void);

void EntryScrWapNewLinkMenuList(void);
void EntryScrWapHistoryMenuList(void);
void EntryScrWapOffLineMenuList(void);
void main_settings_entryScr(void);
void EntryScrWapPushboxMenuList(void);
void EntryScrWapPushMessageShow(void);

void EntryScrWapInputUrlMenuList(void);
void EntryScrWapHistoryUrlMenuList(void);

void EntryScrWapSetHomePageMenuList(void);
void EntryScrWapGateWaySettingsMenuList(void);
void EntryScrWapSetImageMenuList(void);
void EntryScrWapSetBGMusicMenuList(void);
void EntryScrWapSetPushMessageMenuList(void);
void EntryScrWapSetNetAccMenuList(void);
void EntryScrWapSetCertificatesMenuList(void);
void EntryScrWapBookMarkLink(void);
void EntryScrWapHistoryLink(void);
void EntryScrWapHistoryUrlLink(void);

void EntryScrWapPushMessageLink(void);

void EntryScrWapBookMarkRename(void);
void EntryScrWapBookMarkUrlCh(void);
void ExitScrWapBookMarkAdd(void);
void EntryScrWapBookMarkAddMenuList(void);
void ExitScrWapBookMarkEdit(void);
void EntryScrWapBookMarkEditMenuList(void);

void EntryScrWapSettingHomepage(void);

void WapBookMarkAddMenuList(void);

void WapBookMarkEdit(void);
void WapBookMarkEditFillInlineStruct(void);
void WapChangeBookMarkEdit(void);
void WapBookMarkEditOption(void);
void WapEditBookMarkConfirm(void);
void WapEditBookMarkFinish(void);
void WapEditBookMarkNoChanged(void);


void WapAddBookMarkEdit(void);
void WapAddBookMarkFinish(void);
void WapAddBookMarkEditOption(void);
void WapAddBookMarkConfirm(void);
void WapAddBookMarkNoChanged(void);

void EntryScrWapDoneMenuList(void);
void EntryScrWapDoneSet(void);
void EntryScrWapNotDoneSet(void);

void WapSetImageOn(void);
void WapSetImageOff(void);

void EntryScrWapSetGsmAccMenuList(void);
void EntryScrWapSetGprsAccMenuList(void);

void EntryScrWapGsmAccSet(void);
void EntryScrWapGprsAccSet(void);

void EntryScrWapImageSet(void);
void EntryScrWapBGMusicSet(void);

void WapGateWaySettingsFinish(void);
void WapGateWaySettingsEdit(void);
void WapGateWaySettingsConfirm(void);
void WapGateWaySettingsEditOption(void);
void WapGateWaySettingsNoChanged(void);
void ExitEntryScrWapGateWaySettings(void);
void EntryScrWapSetNetAccMenuListPrep(void);
void EntryScrWapSecuritySet(void);
void EntryScrWapSetSecurityMenuList(void);
void EntryScrWapSetConnectModeMenuList(void);
void WapHomePageSettingsFinish(void);
void EntryScrWapClearInputHistory(void);
void EntryScrWapClearPageHistory(void);
void EntryScrWapClearCache(void);
void EntryScrDrawSecutityMessage(void);
void EntryScrDrawMessage(void);

void EntryScrWapAuthenticationEdit(void);
void WapAuthenticationEditFillInlineStruct(void);
void WapAuthenticationEdit(void);
void WapAuthenticationEditConfirm(void);
void WapAuthenticationEditFinish(void);
void ExitEntryScrWapAuthenticationEdit(void);

void EntryScrWapSelectBoxOption(void);
void CmsWapSelectboxFinish(void);
void CmsWapSelectboxCancel(void);

void WapClearPageHistory(void);
void WapClearCache(void);
void RedrawCategoryWMLScreen(void);
//gui interface
int PrintHZOnScr(int x, int y, unsigned char* string, int isAnchor, int isSelect);

int Cms_Browser_DrawRect(int x,  int y, int width, 
									  int height, 
									  int Mark);

int Cms_Browser_DrawLine(int x, int y, int length, int Horizontal) ;
int Cms_Browser_ClearRect(unsigned int x, unsigned int y, 
						  unsigned int width, unsigned int height,
						  unsigned int BackGroudColor);


void Cms_Browser_RefreshScreen(void);

void Browser_Enter(void);
void Cms_Brw_Cancle(void);
void ExitWapBrowser(void);
void ExitWapBrowserByKey(void);
void ExitWapBrowserByEndkey(void);
void BrowserOption(void);

void bookmark_optin_menu(void);
U16 Cms_get_softkey_type(int soft_type);
void BrowserHistoryOption(void);
void BrowserPushBoxOption(void);
void BrowserOfflineOption(void);
void GoLinkFocusEvent(void);
void GoLinkFocusEventByKey(void);
void NextLinkFocusEvent(void);
void LastLinkFocusEvent(void);
void RightLinkFocusEvent(void);
void LeftLinkFocusEvent(void);
int SocketConnect(void);
void wap_net_data_init(void);
void  udpinit(unsigned char* host, unsigned short port);
void Cms_Browser_EditBox(void);
void Cms_Mtk_Browser_LayoutEvent(void);
void PageDownloadGifPlay(void);
void Browser_GetInputParam(void);
void Browser_GetFilename(void);
void Browser_SaveFileCancle(void);
void Browser_SaveFileName(void);
void Exit_BrowserOption(void);
void Browser_page(void);
void ExitBrowser_page(void);
void BackToMainMenu(void);

void CMS_NextLinkFocusEvent(void);
void CMS_LastLinkFocusEvent(void);
void CMS_RightLinkFocusEvent(void);
void CMS_LeftLinkFocusEvent(void);

void Cms_Browser_PageReLink(void);
void Cms_Browser_PageLinkReturn(void);
void Cms_Browser_SendMail(void);
void Cms_Browser_CallRequest(void);
void Cms_Browser_StorePhonenum(void);
void Cms_Browser_PageDownGif(void);

void CmsWapBackEvent(void);
 void MtkAddDefaultBookMark(void);
void CmsGetUnreadPushMessageNum(void);
void	cms_show_wappush_icon(void);

void EntryScrWapBrowserByHomepageKey(void);
void Cms_Browser_LinkPageMessage(void);
void CmsStopAllGif(void);

void Cms_Browser_GetPageLayoutInfo(void);
unsigned char * brw_GetResourceByID(int id);
void Cms_Brw_LeftSodtKeyReg(void);
void Cms_Brw_RightKeyCancleReg(void);

int CmsGetCurrentWapState(void);
void EntryScrWapBrowserByUrl(char * url);
/***************************************************************************** 
* File System Functions Decleration
*****************************************************************************/
void Cms_LoadFile(void);
void Cms_SaveFile(void);

void Cms_LoadBookMarkFile(void);
void Cms_LoadSetupFile(void);
void Cms_LoadPushFile(void);

void Cms_SaveBookMarkFile(void);
void Cms_SaveSetupFile(void);
void Cms_SavePushFile(void);

void wap_init_app(void);
 void Cms_SaveCookie(void);
 unsigned char *Cms_GetCookie(unsigned int *buflen);
 void Cms_Browser_WriteUIHistory(void);
void Cms_Browser_DrawTitle(unsigned char* title);
void TipMessageBoxExit(void);
 void DevDeactivate(void);
 void OptExitBrowser(void);
 
void  SetNetSocketReadState(void);
void SetNetSocketReadEndState(void);
void wap_write_setting_file_by_index(U16 index);
void wap_read_setting_file_by_index(U16 index);
#endif	/* _CMS_WAP_RESOURCE_DATA_H */
#endif
