/*******************************************************************************
 * Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.,
 * All rights reserved.
 * This is unpublished proprietary source code of MobileSoft Technology
 *
 * The copyright notice above does not evidence any actual or intended
 * publication of such source code  
 *******************************************************************************
 */
 
/***************************************************************************** 
* Include files 
*****************************************************************************/
#ifdef CMS_NEW_APP
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "MMI_features.h"
#include "MMIDataType.h"
#include "servicedefs.h"
#include "WapResourceData.h"
#include "MmsResourceData.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

/***************************************************************************** 
*	String Resources
*****************************************************************************/

void PopulateCmsWAPResData (void)
{
/***************************************************************************** 
*	wap Main meun
*****************************************************************************/
 	ADD_APPLICATION_STRING2(STR_WAP_MAIN_MENU_CAPTION,"WAP","WAP Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_LOCALLINK_ID,"LOCALLINK","LOCALLINK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_NEWLINK_ID,"PLEASE INPUT URL","NEWLINK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_HOMEPAGE_ID,"HOMEPAGE","HOMEPAGE  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_HISTORY_ID,"HISTORY","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OFFLINE_ID,"NATIVE BROWSER","BROWSER  Menu Item String");	
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_ID,"SETTINGS","SETTINGS  Menu Item String");

/***************************************************************************** 
*	wap Settings menu
*****************************************************************************/		
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_CLEARINPUTHISTOY_ID,"CLEAR INPUT HISTOYR","WAP Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_CLEARPAGEHISTOY_ID,"CLEAR PAGE HISTORY","LOCALLINK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_CLEARCACHE_ID,"CLEAR CACHE","NEWLINK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_CLEARCOOKIE_ID,"CLEAR COOKIES","CLEAR COOKIE  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETPUSHMESSAGE_ID,"SETTING PUSH","PUSH SETTING  Menu Item String");
	
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETHOMEPAGE_ID,"HOMEPAGE SETTING","HOMEPAGE  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETGATEWAY_ID,"GATEWAY SETTING","HOMEPAGE  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETIMAGE_ID,"IMAGE SETTING","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETBGMUSIC_ID,"MUSIC SETTING","MUSIC  Menu Item String");
	
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_IMAGES_ID,"IMAGE SUPPORT","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_IMAGEOFF_ID,"IMAGE OFF","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_IMAGEON_ID,"IMAGE ON","HISTORY  Menu Item String");
	
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_BGMUSIC_ID,"BGMUSIC SUPPORT","MUSIC  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_BGMUSICOFF_ID,"BGMUSIC OFF","MUSIC  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_BGMUSICON_ID,"BGMUSIC ON","MUISC  Menu Item String");

	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_PUSHMESSAGE_ID,"PUSH","PUSH  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_PUSHMESSAGEOFF_ID,"PUSH OFF","PUSH  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_PUSHMESSAGEON_ID,"PUSH ON","PUSH  Menu Item String");

	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETCERTIFICATES_ID,"Trusted Certificates","Trusted Certificates  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETCERTIFICATESON_ID,"Security On","Trusted Certificates On  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETCERTIFICATESOFF_ID,"Security Off","Trusted Certificates Off Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETCONNECTMODE_ID,"Connect Mode","Connect Mode Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETCONNECTMODE_HTTP_ID,"Http","HTTP Connect Mode Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETCONNECTMODE_WAP_ID,"WAP1.2","WAP1.2 Connect Mode Menu Item String");

	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_GATEWAY_ID,"WAP GATEWAY","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_PORT_ID,"WAP PORT","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_HOMEPAGE_ID,"WAP HOMEPAGE","HISTORY  Menu Item String");	
	
/***************************************************************************** 
*	wap Option menu
*****************************************************************************/	
	ADD_APPLICATION_STRING2(STR_WAP_WAPOPTION_MAIN_MENU,"WAP OPTION","WAP OPTION  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_GOTOLINK_ID,"GO TO LINK","BACK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_BACK_ID,"BACK","BACK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_SAVEHOMEPAGE_ID,"SAVEHOMEPAGE","SAVEHOMEPAGE  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_SAVECURRENTPAGE_ID,"SAVECURRENTPAGE","SAVECURRENTPAGE  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_BROWSERHOMEPAGE_ID,"BROWSERHOMEPAGE","BACK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_BOOK_ID,"ADDBOOKMARK","BACK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_URL_ID,"CURRENTURL","GET CURRENT URL  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_REFRESH_ID,"REFRESH","REFRESH  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_DOWNPIC_ID,"Down Pic","Down picture  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_DOWNMUSIC_ID,"Down Music","Down backgroundmusic  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_NEWLINK_ID,"NEWLINK","SAVEBOOKMARK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_PUSHBOX_ID,"PUSHBOX","SAVEBOOKMARK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OPTION_BROWSEREXIT_ID,"EXIT BROWSER","SAVEBOOKMARK  Menu Item String");			
	ADD_APPLICATION_STRING2(STR_WAP_NEWLINK_URL_ID,"INPUT NEW URL","HISTORY  Menu Item String");	
	
/***************************************************************************** 
*	wap setting Net
*****************************************************************************/		
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETNETACC_ID,"NET ACCOUNT","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETGSMNETACC_ID,"GSM NET ACCOUNT","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SETTINGS_SETGPRSNETACC_ID,"GPRS NET ACCOUNT","HISTORY  Menu Item String");
	
	ADD_APPLICATION_STRING2(STR_WAP_NEWLINK_INPUTURL_ID,"INPUT URL","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_NEWLINK_HISTORYURL_ID,"INPUT HISTORY","HISTORY  Menu Item String");

/***************************************************************************** 
*	wap Bookmark menu
*****************************************************************************/		
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARKOPTION_MAIN_ID,"BOOKMARK OPTION","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARKOPTION_LINK_ID,"LINK","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARKOPTION_EDIT_ID,"EDIT BOOKMARK","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARKOPTION_ADD_ID,"ADD NEW BOOKMARK","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARKOPTION_DELETEALL_ID,"DELETE ALL","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARKOPTION_DELETE_ID,"DELETE","SETTINGS  Menu Item String");
	
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARKOPTION_ADDURL_ID,"Add  Url","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARKOPTION_ADDTITLE_ID,"Add Title","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARKOPTION_ADDFINISH_ID,"Finish","SETTINGS  Menu Item String");
	
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARK_ID,"BOOK MARK","BOOKMARK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_LINK,"LINK","BOOKMARK  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_EDIT,"EDIT","BOOKMARK  Menu Item String");

/***************************************************************************** 
*	wap History record  menu
*****************************************************************************/		
	ADD_APPLICATION_STRING2(STR_WAP_HISTORYOPTION_MAIN_MENU_ID,"HISTORY OPTION","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_HISTORYOPTION_DELETE_ID,"DELETE SELECT","HISTORY  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_HISTORYOPTION_DELETEALL_ID,"DELETE ALL","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_WAPPUSHARRIVED_ID,"Wap Push arrived!","SETTINGS  Menu Item String");
	
/***************************************************************************** 
*	wap Push menu
*****************************************************************************/		
	ADD_APPLICATION_STRING2(STR_WAP_PUSHBOX_ID,"PUSH SERVICE","SETTINGS  Menu Item String");		
	
	ADD_APPLICATION_STRING2(STR_WAP_PUSHBOXOPTION_MAIN_MENU_ID,"PushBox option","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_PUSHBOXOPTION_LINK_ID,"LINK","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_PUSHBOXOPTION_DELETE_ID,"Delete","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_PUSHBOXOPTION_DELETEALL_ID,"Delete All Wap Push","SETTINGS  Menu Item String");
/*============================================================
Wap Offline menu
=============================================================*/
	ADD_APPLICATION_STRING2(STR_WAP_OFFLINEOPTION_MAIN_MENU_ID,"Offline option","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OFFLINEOPTION_LINK_ID,"Browser","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OFFLINEOPTION_DELETE_ID,"Delete","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OFFLINEOPTION_DELETEALL_ID,"Delete All","SETTINGS  Menu Item String");
/*============================================================
Wap Pushmessage show menu
=============================================================*/	
	ADD_APPLICATION_STRING2(STR_WAP_PUSHMESSAGE_ID,"MESSAGE:","show push message");
	ADD_APPLICATION_STRING2(STR_WAP_PUSHURL_ID,"URL:","show push url");
/***************************************************************************** 
*	Tip and other
*****************************************************************************/	
	ADD_APPLICATION_STRING2(STR_WAP_PAGELINK_ID,"Page Downloading...","SETTINGS  Menu Item String");	
	ADD_APPLICATION_STRING2(STR_WAP_PAGELINKFAILED_ID,"Page DownLoad Failed, Retry?","SETTINGS  Menu Item String");	
	
	ADD_APPLICATION_STRING2(STR_WAP_NO_BOOKMARK_ID,"Book Mark Empty!","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_NO_PAGEHISTORY_ID,"Page History Empty!","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_NO_PUSHMESSAGE_ID,"Push Message Empty!","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_NO_OFFLINE_ID,"Offline Message Empty!","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_HOMEPAGEISNONE_ID,"Home Page No set!","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_BOOKMARKISFULL_ID,"Book Mark is Full!","SETTINGS  Menu Item String");
	
	ADD_APPLICATION_STRING2(STR_WAP_EDITBOX_ID,"Input imformation","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_SAVEFIFLE_ID,"Input FileName","SETTINGS  Menu Item String");
	ADD_APPLICATION_STRING2(STR_WAP_OFFLINE_FULL_ID,"Offline Page is full,please delete","Offline Page is full,please delete");
	ADD_APPLICATION_STRING2(STR_WAP_TRUSTED_CERTIFICATES_ID, "Trusted Certificates", "Trusted Certificates");
	ADD_APPLICATION_STRING2(STR_WAP_GATEWAY_ERROR_ID, "Gateway Set Error", "Gateway Set Error");
	
	ADD_APPLICATION_STRING2(STR_WAP_STATE_DOWNLOAD_FAIL, "Download Failed", "Download Failed");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_DOWNLOADING, "Downloading...", "Downloading...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_DOWNLOAD_SUCCESS, "Download Success", "Download Success");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_DECODE_FAIL, "Decode Failed", "Decode Failed");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_GATEWAY_DISCONNECT, "Gateway Disconnected", "Gateway Disconnected");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_HANGUPING, "Hanguping...", "Hanguping...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_PARSER_FAIL, "Parser Failed", "Parser Failed");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_CHARSET_UNSUPPORT, "Charset Not Supported", "Charset Not Supported");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_HOMEPAGE_BLANK, "Homepage Blank", "Homepage Blank");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_PAGE_REFRESHING, "Page Refreshing...", "Page Refreshing...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_PAGE_ERROR, "Page Error", "Page Error");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_DOWNLOAD_BEGAIN, "Download...", "Download...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_CONNECTING, "Connecting...", "Connecting...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_DIALING, "Dialing...", "Dialing...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_DIAL_FAILED, "Dial Failed", "Dial Failed");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_SENDING, "Sending...", "Sending...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_PARAM_ERROR, "Param Error", "Param Error");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_NO_MEMORY, "No Memory", "No Memory");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_CONNECT_FAILED, "Connect Failed", "Connect Failed");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_TIMER_ERROR, "Timer Error", "Timer Error");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_UNKNOWN_ERROR, "Unknown Error", "Unknown Error");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_WAPSTACK_BUSY, "WAP Stack Busy", "WAP Stack Busy");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_NETWORK_TIMEOUT, "Network Timeout", "Network Timeout");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_RECONNECTING, "Reconnecting...", "Reconnecting...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_WAPSTACK_SUSPENDED, "WAP Stack Suspended", "WAP Stack Suspended");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_WAPSTACK_RESUME_FAILED, "WAP Stack Resume Failed", "WAP Stack Resume Failed");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_WAPSTACK_RESUMED, "WAP Stack Resumed", "WAP Stack Resumed");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_PARSERING, "Parsering...", "Parsering...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_LAYOUTING, "Layouting...", "Layouting...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_DRAWING, "Drawing...", "Drawing...");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_WMLSCRIPT, "Wml Script Status", "Wml Script Status");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_WTAI, "WTAI", "WTAI");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_TLS_WAIT_CONFIRM, "Wait TLS Confirm", "Wait TLS Confirm");		
	ADD_APPLICATION_STRING2(STR_WAP_STATE_WTLS_WAIT_CONFIRM, "Wait WTLS Confirm", "Wait WTLS Confirm");
	ADD_APPLICATION_STRING2(STR_WAP_STATE_OS_SOCKET_INVALIED, "Socket Invalied", "Socket Invalied");	
	ADD_APPLICATION_STRING2(STR_WAP_STATE_NORMAL, "Normal", "Normal");			
	ADD_APPLICATION_STRING2(STR_WAP_WARING_NETBUSY, "Net busy, please retry later", "Net busy, please retry later");	

	ADD_APPLICATION_STRING2(STR_WAP_INFOBOX_ID, "Information", "Info Box");	
	ADD_APPLICATION_STRING2(STR_WAP_NOT_READY_YET,		"WAP Not Ready Yet!",			"WAP not ready yet String");
	ADD_APPLICATION_STRING2(STR_WAP_APPLICATION_NOT_SUPPORT,		"Application Not Support!",			"Application Not Support String");
	ADD_APPLICATION_STRING2(STR_WAP_INPUT_USERNAME, "Enter Username","Enter Username String.");
	ADD_APPLICATION_STRING2(STR_WAP_INPUT_PASSWORD, "Enter Password","Enter Password String.");
	ADD_APPLICATION_STRING2(STR_WAP_AUTHENTICATION_EDIT, "Authentication Edit","Enter Authentication Edit.");

	ADD_APPLICATION_STRING2(STR_WAP_NO_SERVER, "No Server","The Server is not exited String.");
	ADD_APPLICATION_STRING2(STR_WAP_NO_SUCH_SERVER, "The Server is not exited!","The Server is not exited String.");
	ADD_APPLICATION_STRING2(STR_WAP_DIALING_FAILED, "Dial failed!","Dial failed String.");
	ADD_APPLICATION_STRING2(STR_WAP_CONNECTION_DISC, "Connection disconnected!","Connection disconnected String.");
	ADD_APPLICATION_STRING2(STR_WAP_DIALING_CON_DISC, "Dialing connection is disconnected!","Dialing connection is disconnected String.");
	ADD_APPLICATION_STRING2(STR_WAP_DOWN_RING_FAIL, "Download ring failed!","Download ring failed String.");
	ADD_APPLICATION_STRING2(STR_WAP_DATA_ERROR, "Data error!","Data error String.");
	ADD_APPLICATION_STRING2(STR_WAP_SERVER_REJECT, "Server reject!","Server reject String.");
	ADD_APPLICATION_STRING2(STR_WAP_INVALID_ADDRESS, "Invalid address!","Invalid address String.");
	ADD_APPLICATION_STRING2(STR_WAP_INVALID_URL, "Invalid url!","Invalid url String.");
	ADD_APPLICATION_STRING2(STR_WAP_ERROR_PAGE, "Error page!","Error page String.");
	ADD_APPLICATION_STRING2(STR_WAP_ERROR_PAGE_TRY, "Error page,please try later!","Error page,please try later String.");
	ADD_APPLICATION_STRING2(STR_WAP_GETWAY_ERROR, "Gateway error!","Gateway error String.");
	ADD_APPLICATION_STRING2(STR_WAP_GETWAY_NO_RES, "Gateway not response!","Gateway not response String.");
	ADD_APPLICATION_STRING2(STR_WAP_SERVER_ERROR, "Server error!","Server error String.");
	ADD_APPLICATION_STRING2(STR_WAP_TIME_OUT, "Time out!","Time out String.");
	ADD_APPLICATION_STRING2(STR_WAP_RES_TIME_OUT, "The server's response time out!","TThe server's response time out String.");
	ADD_APPLICATION_STRING2(STR_WAP_UNSUPPORT_FILE, "Unsupport file!","Unsupport file String.");
	ADD_APPLICATION_STRING2(STR_WAP_UNSUPPORT_SORRY, "Sorry! Not support such file type!","Sorry! Not support such file type String.");
	ADD_APPLICATION_STRING2(STR_WAP_SUBMIT, "submit","submit String.");
	ADD_APPLICATION_STRING2(STR_WAP_BUTTON, "button","button String.");
	ADD_APPLICATION_STRING2(STR_WAP_RESET, "reset","reset String.");
	ADD_APPLICATION_STRING2(STR_WAP_SUBJECT, "Subject :","Subject : String.");
	ADD_APPLICATION_STRING2(STR_WAP_ISSURER, "Issuer :","Issuer : String.");
	ADD_APPLICATION_STRING2(STR_WAP_VALID_NOTBEFORE, "Valid not before :","Valid not before : String.");
	ADD_APPLICATION_STRING2(STR_WAP_VALID_NOTAFTER, "Valid not after :","Valid not after : String.");
	ADD_APPLICATION_STRING2(STR_WAP_MD_ALGORITHMS, "MD algorithms :","MD algorithms : String.");
	ADD_APPLICATION_STRING2(STR_WAP_SIGN_ALGO, "Signature algorithms :","Signature algorithms : String.");
	ADD_APPLICATION_STRING2(STR_WAP_SIGNATURE, "Signature :","Signature : String.");
	ADD_APPLICATION_STRING2(STR_WAP_VALID_CERT, "Valid security certificate","Valid security certificate String.");
	ADD_APPLICATION_STRING2(STR_WAP_INVALID_CERT, "Invalid security certificate or unsupported certificate type","Invalid security certificate or unsupported certificate type String.");
	ADD_APPLICATION_STRING2(STR_WAP_UNTRUST_CERT, "this certificate cannot be verified up to a trusted certificateion authority","this certificate cannot be verified up to a trusted certificateion authority String.");
	ADD_APPLICATION_STRING2(STR_WAP_REVOKED_CERT, "Security certificate revoked","Security certificate revoked String.");
	ADD_APPLICATION_STRING2(STR_WAP_EXPIER_CERT, "Security certificate expired or not valid yet","Security certificate expired or not valid yet String.");
	ADD_APPLICATION_STRING2(STR_WAP_ERPURPOSE_CERT, "Invalid security certificate purpose","Invalid security certificate purpose String.");
	ADD_APPLICATION_STRING2(STR_WAP_UNMACTH_CERT, "The name on the security certificate is invalid or does not match the name of the site.","The name on the security certificate is invalid or does not match the name of the site String.");
	ADD_APPLICATION_STRING2(STR_WAP_UNKNOWN_ERROR, "Unknown error","Unknown error String.");
	ADD_APPLICATION_STRING2(STR_WAP_CERT_WARNING_PROBLEM, "Information you exchange with this site cannot be viewed or changed by others , however , there is a problem with the site's security certificate","information you exchange with this site cannot be viewed or changed by others , however , there is a problem with the site's security certificate String.");
	ADD_APPLICATION_STRING2(STR_WAP_ENCRYPT_METHOD, "%s with %d bits encryption( High ) , RSA with %d bits exchange","%s with %d bits encryption( High ) , RSA with %d bits exchange String.");
	ADD_APPLICATION_STRING2(STR_WAP_CERT_INFO, "Security certificate info","Security certificate info.");
	ADD_APPLICATION_STRING2(STR_WAP_MALLOC_FAILED, "system malloc failed,exit please!","system malloc failed,exit please info String.");
	ADD_APPLICATION_STRING2(STR_WAP_NET_EXCEPTION, "Net exception, please exit browser","Net exception, please exit browser info String.");
	ADD_APPLICATION_STRING2(STR_WAP_BIG_FILE, "Big file,","Big file String.");
	ADD_APPLICATION_STRING2(STR_WAP_BIG_FILE_TO_DOWN, "File is too big to download,","File is too big to download String.");
	ADD_APPLICATION_STRING2(STR_WAP_CON_SECURED, "Connection Secured,","Connection Secured String.");
	ADD_APPLICATION_STRING2(STR_WAP_CON_TO_SERVICE, "Connecting to server,","Connecting to server String.");
	ADD_APPLICATION_STRING2(STR_WAP_SECURED_CA, "Connecting in security to server,whether continue?,","Connecting in security to server,whether continue String.");
	ADD_APPLICATION_STRING2(STR_WAP_DOWNLOADING_IMAGE, "Downloading(%d/%d),","Downloading(%d/%d) String.");
	ADD_APPLICATION_STRING2(STR_WAP_DOWNLOADIMG_OK, "Download Finished,","Download Finished String.");

	ADD_APPLICATION_STRING2(STR_WAP_DUPLICATE_FILENAME, "Duplicated Filename","Duplicated Filename");
	ADD_APPLICATION_STRING2(STR_WAP_INVALID_FILE_NAME, "Invalid Filename","Invalid Filename");
	ADD_APPLICATION_STRING2(STR_WAP_CANNOT_CREATE_FILE, "Create File Failed","Can not create file");
	ADD_APPLICATION_STRING2(STR_WAP_SETTING_ERROR, "WAP Setting Error","WAP Setting Error String");
	ADD_APPLICATION_STRING2(STR_WAP_CANCLE_CONFIRM, "Exit browser","Exit browser String");
	ADD_APPLICATION_STRING2(STR_WAP_NETACCOUNT_ERROR, "WAP Netaccount Error","WAP Netaccount Error");
	ADD_APPLICATION_STRING2(STR_WAP_FAILURE_MEM_CAP_EXCEEDED, "Memory Capacity Exceeded!","Memory Capacity Exceeded Error Message String");
	ADD_APPLICATION_STRING2(STR_WAP_NO_TITLE, "*No Title*","*No Title*");

//End String resource

/***************************************************************************** 
* Image Resources 
*****************************************************************************/		 
	ADD_APPLICATION_IMAGE2(IMG_WAP_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\Browser.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPLOCALLINK_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\test.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPHOMEPAGE_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\Homepage.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPSETTINGS_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\WapSet.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPBOOKMARK_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\BookMark.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPOFFLINE_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\Nativepage.gif", "WAP Menu Item Icon");	
	ADD_APPLICATION_IMAGE2(IMG_WAPINBOX_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\PushBox.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPHISTORY_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\History.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPINPUTURL_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\NewLink.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPSUCCESS_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\Success.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPREAD_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\Read.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPUNREAD_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\Unread.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPPAGEDOWNLOAD_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\PageDownLoad .gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPIMGDOWNLOAD_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\DLFail.bmp", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPIMGWAIT_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\wait.gif", "WAP Menu Item Icon");

	ADD_APPLICATION_IMAGE2(IMG_WAPIMGLINKONE_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\LinkOne.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPIMGLINKTWO_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\LinkTwo.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPIMGLINTTHREE_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\LinkThree.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPIMGSSLPAGE_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\SslPage.gif", "WAP Menu Item Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPPAGE_PROCESS_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\WapWaiting.gif", "WAP Page Wating Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAPDOWNLOADING_MAIN_MENU_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Wap\\\\Downloading.gif", "WAP Page Downloading Icon");

	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_UP_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\up.gif", "WAP Pictogram core/arrow/up Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_DOWN_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\down.gif", "WAP Pictogram core/arrow/down Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_RIGHT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\right.gif", "WAP Pictogram core/arrow/right Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_LEFT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\left.gif", "WAP Pictogram core/arrow/left Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_UPPERRIGHT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\upperRight.gif", "WAP Pictogram core/arrow/upperRight Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_UPPERLEFT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\upperLeft.gif", "WAP Pictogram core/arrow/upperLeft Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_LOWERRIGHT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\lowerRight.gif", "WAP Pictogram core/arrow/lowerRight Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_LOWERLEFT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\lowerLeft.gif", "WAP Pictogram core/arrow/lowerLeft Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERUP_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\fingerUp.gif", "WAP Pictogram core/arrow/fingerUp Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERDOWN_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\fingerDown.gif", "WAP Pictogram core/arrow/fingerDown Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERRIGHT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\fingerRight.gif", "WAP Pictogram core/arrow/fingerRight Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERLEFT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\fingerLeft.gif", "WAP Pictogram core/arrow/fingerLeft Icon");

	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_BUTTON_1_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\1.gif", "WAP Pictogram core/button/1 Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_BUTTON_2_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\2.gif", "WAP Pictogram core/button/2 Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_BUTTON_3_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\3.gif", "WAP Pictogram core/button/3 Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_BUTTON_4_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\4.gif", "WAP Pictogram core/button/4 Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_BUTTON_5_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\5.gif", "WAP Pictogram core/button/5 Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_BUTTON_6_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\6.gif", "WAP Pictogram core/button/6 Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_BUTTON_7_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\7.gif", "WAP Pictogram core/button/7 Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_BUTTON_8_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\8.gif", "WAP Pictogram core/button/8 Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_BUTTON_9_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\9.gif", "WAP Pictogram core/button/9 Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_BUTTON_0_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\0.gif", "WAP Pictogram core/button/0 Icon");

	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ACTION_MAKEPHONECALL_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\makePhoneCall.gif", "WAP Pictogram core/action/makePhoneCall Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ACTION_FIND_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\find.gif", "WAP Pictogram core/action/find Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ACTION_USERAUTHENTICATION_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\userAuthentication.gif", "WAP Pictogram core/action/userAuthentication Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ACTION_NEXTITEM_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\nextltem.gif", "WAP Pictogram core/action/nextltem Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ACTION_CLEAR_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\clear.gif", "WAP Pictogram core/action/clear Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ACTION_STOP_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\stop.gif", "WAP Pictogram core/action/stop Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ACTION_TOP_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\top.gif", "WAP Pictogram core/action/top Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ACTION_NEXT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\next.gif", "WAP Pictogram core/action/next Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_ACTION_BACK_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\back.gif", "WAP Pictogram core/action/back Icon");

	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MESSAGE_RECEIVE_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\receive.gif", "WAP Pictogram core/message/receive Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MESSAGE_SEND_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\send.gif", "WAP Pictogram core/message/send Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MESSAGE_MESSAGE_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\message.gif", "WAP Pictogram core/message/message Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MESSAGE_ATTACHMENT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\attachment.gif", "WAP Pictogram core/message/attachment Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MESSAGE_FOLDER_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\folder.gif", "WAP Pictogram core/message/folder Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MESSAGE_INBOX_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\inbox.gif", "WAP Pictogram core/message/inbox Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MESSAGE_OUTBOX_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\outbox.gif", "WAP Pictogram core/message/outbox Icon");

	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_STATE_SECURE_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\secure.gif", "WAP Pictogram core/state/secure Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_STATE_INSECURE_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\insecure.gif", "WAP Pictogram core/state/insecure Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_STATE_COPYRIGHT_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\copyright.gif", "WAP Pictogram core/state/copyright Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_STATE_TRADEMARK_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\trademark.gif", "WAP Pictogram core/state/trademark Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_STATE_UNDERCONSTRUCTION_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\underConstruction.gif", "WAP Pictogram core/state/underConstruction Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_STATE_BEGINNER_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\beginner.gif", "WAP Pictogram core/state/beginner Icon");

	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MEDIA_BOOK_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\book.gif", "WAP Pictogram core/media/book Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MEDIA_VIDEO_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\video.gif", "WAP Pictogram core/media/video Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MEDIA_CD_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\cd.gif", "WAP Pictogram core/media/cd Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MEDIA_DVD_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\dvd.gif", "WAP Pictogram core/media/dvd Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MEDIA_GAME_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\game.gif", "WAP Pictogram core/media/game Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MEDIA_RADIO_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\radio.gif", "WAP Pictogram core/media/radio Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_MEDIA_TV_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\tv.gif", "WAP Pictogram core/media/tv Icon");

	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_INFO_NOTICE_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\notice.gif", "WAP Pictogram core/info/notice Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_INFO_CHARGED_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\charged.gif", "WAP Pictogram core/info/charged Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_INFO_FREEOFCHARGE_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\freeofcharge.gif", "WAP Pictogram core/info/freeofcharge Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_INFO_NEW_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\new.gif", "WAP Pictogram core/info/new Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_INFO_POSITION_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\position.gif", "WAP Pictogram core/info/position Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_INFO_TOLLFREE_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\tollfree.gif", "WAP Pictogram core/info/tollfree Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_INFO_SHARPDIAL_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\sharpdial.gif", "WAP Pictogram core/info/sharpdial Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_INFO_RESERVED_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\reserved.gif", "WAP Pictogram core/info/reserved Icon");
	ADD_APPLICATION_IMAGE2(IMG_WAP_PICTOGRAM_CORE_INFO_SPEECHINFO_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Pictogram\\\\speechinfo.gif", "WAP Pictogram core/info/speechinfo Icon");

//End Image resource
 
/***************************************************************************** 
* MENU Resources
*****************************************************************************/	 

/***************************************************************************** 
*  Wap browser main menu setting
*****************************************************************************/	 
	ADD_APPLICATION_MENUITEM((SERVICES_WAP_MENU_ID, MAIN_MENU_SERVICES_MENUID,
			   					#ifndef SUPPORT_SMSMMS_COMBINE
								NUM_WAP_MAIN_MENU,
								#else
								NUM_WAP_MAIN_MENU-1,/*-1 for push list*/
								#endif
								WAP_MENU_HOMEPAGE_MENU_ID, 
								WAP_MENU_BOOKMARK_MENU_ID,
			   					WAP_MENU_NEWLINK_MENU_ID, 			   					
			   					WAP_MENU_HISTORY_MENU_ID, 
			   					WAP_MENU_OFFLINE_MENU_ID,
			   					WAP_MENU_SETTINGS_MENU_ID,
			   					#ifndef SUPPORT_SMSMMS_COMBINE
			   					WAP_MENU_PUSHBOX_MENU_ID,	
			   					#endif
								HIDE,MOVEABLEACROSSPARENT,DISP_LIST, 
								/*/SERVICES_WAP_STRING_ID/*/STR_WAP_MAIN_MENU_CAPTION/**/, IMG_WAP_MAIN_MENU_ICON)); 

 	ADD_APPLICATION_MENUITEM((WAP_MENU_LOCALLINK_MENU_ID, SERVICES_WAP_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_LOCALLINK_ID, IMG_WAPLOCALLINK_MAIN_MENU_ICON)); 

	ADD_APPLICATION_MENUITEM((WAP_MENU_BOOKMARK_MENU_ID, SERVICES_WAP_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_BOOKMARK_ID, IMG_WAPBOOKMARK_MAIN_MENU_ICON));

	ADD_APPLICATION_MENUITEM((WAP_MENU_NEWLINK_MENU_ID, SERVICES_WAP_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_NEWLINK_ID, IMG_WAPINPUTURL_MAIN_MENU_ICON));
	
	ADD_APPLICATION_MENUITEM((WAP_MENU_HOMEPAGE_MENU_ID, SERVICES_WAP_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_HOMEPAGE_ID, IMG_WAPHOMEPAGE_MAIN_MENU_ICON));

	ADD_APPLICATION_MENUITEM((WAP_MENU_HISTORY_MENU_ID, SERVICES_WAP_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_HISTORY_ID, IMG_WAPHISTORY_MAIN_MENU_ICON));

	ADD_APPLICATION_MENUITEM((WAP_MENU_OFFLINE_MENU_ID, SERVICES_WAP_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OFFLINE_ID, IMG_WAPOFFLINE_MAIN_MENU_ICON));
								
/*Begin Of The Wap Setting Options*/								
	ADD_APPLICATION_MENUITEM((WAP_MENU_SETTINGS_MENU_ID, SERVICES_WAP_MENU_ID,NUM_WAP_SETTINGS_MENU,
								WAP_SETTINGS_MENU_SERVICE_ID_MENU_ID,
								WAP_SETTINGS_MENU_CLEARPAGEHISTOY_MENU_ID,
								WAP_SETTINGS_MENU_CLEARCACHE_MENU_ID,
								WAP_SETTINGS_MENU_CLEARCOOKIE_MENU_ID,
								WAP_SETTINGS_MENU_SETPUSHMESSAGE_MENU_ID,
								WAP_SETTINGS_MENU_SETIMAGE_MENU_ID,
								WAP_SETTINGS_MENU_SETBGMUSIC_MENU_ID, 
								WAP_SETTINGS_MENU_SETCERTIFICATES_MENU_ID,
								#ifdef SUPPORT_SWITCH_PROTOCOL
								WAP_SETTINGS_MENU_SETCONNECTMODE_MENU_ID,
								#endif
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_ID, IMG_WAPSETTINGS_MAIN_MENU_ICON));
	/*Service List Option*/
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SERVICE_OPTIONS_MENU_ID,NULL,2,
								WAP_SETTINGS_MENU_SERVICE_SET_MENU_ID,
								WAP_SETTINGS_MENU_SERVICE_EDIT_MENU_ID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_GLOBAL_OPTIONS,NULL));
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SERVICE_SET_MENU_ID,WAP_SETTINGS_MENU_SERVICE_OPTIONS_MENU_ID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_GLOBAL_ACTIVATE,IMG_GLOBAL_L1));
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SERVICE_EDIT_MENU_ID,WAP_SETTINGS_MENU_SERVICE_OPTIONS_MENU_ID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_GLOBAL_EDIT,IMG_GLOBAL_L2));

	/*±‡º≠…Ë÷√—°œÓ(1/2/3/4) */	
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SERVICE_MODIFY_ID_MENU_ID, WAP_SETTINGS_MENU_SERVICE_EDIT_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_SETHOMEPAGE_ID, IMG_GLOBAL_L1));
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETHOMEPAGE_MENU_ID, WAP_SETTINGS_MENU_SERVICE_EDIT_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_SETHOMEPAGE_ID, IMG_GLOBAL_L2));
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETGATEWAY_MENU_ID, WAP_SETTINGS_MENU_SERVICE_EDIT_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_MMS_SETTINGS_NETWORK_CFG_GATEWAY, IMG_GLOBAL_L3));
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETGATEWAY_MENU_ID, WAP_SETTINGS_MENU_SERVICE_EDIT_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_MMS_PORT, IMG_GLOBAL_L4));
	/*SERVICE LIST */	
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SERVICE_ID_MENU_ID, WAP_MENU_SETTINGS_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_MMS_WAP_EDIT_SETTING, IMG_GLOBAL_L1));
	/*HISTOY(ON/OFF)*/	
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_CLEARPAGEHISTOY_MENU_ID, WAP_MENU_SETTINGS_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_CLEARPAGEHISTOY_ID, IMG_GLOBAL_L2));
	/*CACHE(ON/OFF)*/
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_CLEARCACHE_MENU_ID, WAP_MENU_SETTINGS_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_CLEARCACHE_ID, IMG_GLOBAL_L3));

	/*COOKIES(ON/OFF)*/
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_CLEARCOOKIE_MENU_ID, WAP_MENU_SETTINGS_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_CLEARCOOKIE_ID, IMG_GLOBAL_L4));	
	/*PUSH(ON/OFF)*/
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETPUSHMESSAGE_MENU_ID, WAP_MENU_SETTINGS_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_SETPUSHMESSAGE_ID, IMG_GLOBAL_L5));
	
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETPUSHMESSAGEON_MENU_ID, WAP_SETTINGS_MENU_SETPUSHMESSAGE_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_PUSHMESSAGEON_ID, IMG_GLOBAL_L1));

	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETPUSHMESSAGEOFF_MENU_ID, WAP_SETTINGS_MENU_SETPUSHMESSAGE_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_PUSHMESSAGEOFF_ID, IMG_GLOBAL_L2));	

	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETIMAGE_MENU_ID, WAP_MENU_SETTINGS_MENU_ID,NUM_WAP_SETIMAGE_MENU,
								WAP_SETTINGS_MENU_SETIMAGEON_MENU_ID,
								WAP_SETTINGS_MENU_SETIMAGEOFF_MENU_ID,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_SETIMAGE_ID, IMG_GLOBAL_L6));	
		
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETIMAGEON_MENU_ID, WAP_SETTINGS_MENU_SETIMAGE_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_IMAGEON_ID, IMG_GLOBAL_L1));

	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETIMAGEOFF_MENU_ID, WAP_SETTINGS_MENU_SETIMAGE_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_IMAGEOFF_ID, IMG_GLOBAL_L2));
	
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETBGMUSIC_MENU_ID, WAP_MENU_SETTINGS_MENU_ID,NUM_WAP_SETBGMUSIC_MENU,
								WAP_SETTINGS_MENU_SETBGMUSICON_MENU_ID,
								WAP_SETTINGS_MENU_SETBGMUSICOFF_MENU_ID,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_SETBGMUSIC_ID, IMG_GLOBAL_L7));
	
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETBGMUSICON_MENU_ID, WAP_SETTINGS_MENU_SETBGMUSIC_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_BGMUSICON_ID, IMG_GLOBAL_L1));

	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETBGMUSICOFF_MENU_ID, WAP_SETTINGS_MENU_SETBGMUSIC_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_BGMUSICOFF_ID, IMG_GLOBAL_L2));	

	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETNETACC_MENU_ID, NULL,NUM_WAP_SETTINGS_MENU_SETNETACC_MENU,
								WAP_SETTINGS_MENU_SETGSMNETACC_MENU_ID,
								WAP_SETTINGS_MENU_SETGPRSNETACC_MENU_ID,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_SETNETACC_ID, IMG_GLOBAL_L5));

	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETGSMNETACC_MENU_ID,WAP_SETTINGS_MENU_SETNETACC_MENU_ID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_WAP_SETTINGS_SETGSMNETACC_ID,IMG_GLOBAL_L1));
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETGPRSNETACC_MENU_ID,WAP_SETTINGS_MENU_SETNETACC_MENU_ID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_WAP_SETTINGS_SETGPRSNETACC_ID,IMG_GLOBAL_L2));
	
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETCERTIFICATES_MENU_ID, WAP_MENU_SETTINGS_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_SETCERTIFICATES_ID, IMG_GLOBAL_L8));
#ifdef SUPPORT_SWITCH_PROTOCOL
	ADD_APPLICATION_MENUITEM((WAP_SETTINGS_MENU_SETCONNECTMODE_MENU_ID, WAP_MENU_SETTINGS_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_SETTINGS_SETCONNECTMODE_ID, IMG_GLOBAL_L9));
#endif
/*End Of The Wap Setting Options*/

	ADD_APPLICATION_MENUITEM((WAP_MENU_PUSHBOX_MENU_ID, SERVICES_WAP_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_PUSHBOX_ID, IMG_WAPINBOX_MAIN_MENU_ICON));

	ADD_APPLICATION_MENUITEM((WAPOPTION_MAIN_MENU, NULL,NUM_WAP_OPTION,								
								WAP_OPTION_MENU_BACK_MENU_ID,
								WAP_OPTION_MENU_REFRESH_MENU_ID,
								WAP_OPTION_MENU_URL_MENU_ID,
								WAP_OPTION_MENU_SAVEHOMEPAGE_MENU_ID,
								WAP_OPTION_MENU_SAVECURRENTPAGE_MENU_ID,
								WAP_OPTION_MENU_BOOK_MENU_ID,								
								WAP_OPTION_MENU_BROWSERHOMEPAGE_MENU_ID,								
								WAP_OPTION_MENU_BROWSEREXIT_MENU_ID,
								HIDE,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_MAIN_MENU_CAPTION, IMG_WAP_MAIN_MENU_ICON)); 

	ADD_APPLICATION_MENUITEM((WAP_OPTION_MENU_BACK_MENU_ID, WAPOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OPTION_BACK_ID, IMG_GLOBAL_L2));
	ADD_APPLICATION_MENUITEM((WAP_OPTION_MENU_REFRESH_MENU_ID, WAPOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OPTION_REFRESH_ID, IMG_GLOBAL_L2));
	
	ADD_APPLICATION_MENUITEM((WAP_OPTION_MENU_URL_MENU_ID, WAPOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OPTION_URL_ID, IMG_GLOBAL_L3));

	ADD_APPLICATION_MENUITEM((WAP_OPTION_MENU_SAVEHOMEPAGE_MENU_ID, WAPOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OPTION_SAVEHOMEPAGE_ID, IMG_GLOBAL_L3));

	ADD_APPLICATION_MENUITEM((WAP_OPTION_MENU_SAVECURRENTPAGE_MENU_ID, WAPOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OPTION_SAVECURRENTPAGE_ID, IMG_GLOBAL_L3));

	ADD_APPLICATION_MENUITEM((WAP_OPTION_MENU_BOOK_MENU_ID, WAPOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OPTION_BOOK_ID, IMG_GLOBAL_L4));
	
	
	ADD_APPLICATION_MENUITEM((WAP_OPTION_MENU_BROWSERHOMEPAGE_MENU_ID, WAPOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OPTION_BROWSERHOMEPAGE_ID, IMG_GLOBAL_L5)); 
	
	ADD_APPLICATION_MENUITEM((WAP_OPTION_MENU_BROWSEREXIT_MENU_ID, WAPOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OPTION_BROWSEREXIT_ID, IMG_GLOBAL_L6)); 
		
	ADD_APPLICATION_MENUITEM((WAPBOOKMARKOPTION_MAIN_MENU, NULL,NUM_WAP_BOOKMARKOPTION,	
								WAP_BOOKMARKOPTION_MENU_LINK_MENU_ID,
								WAP_BOOKMARKOPTION_MENU_EDIT_MENU_ID,
								WAP_BOOKMARKOPTION_MENU_DELETE_MENU_ID,
								WAP_BOOKMARKOPTION_MENU_DELETEALL_MENU_ID,
								WAP_BOOKMARKOPTION_MENU_ADD_MENU_ID,
								HIDE,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_MAIN_MENU_CAPTION, IMG_WAP_MAIN_MENU_ICON)); 
	
	ADD_APPLICATION_MENUITEM((WAP_BOOKMARKOPTION_MENU_LINK_MENU_ID, WAPBOOKMARKOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_BOOKMARKOPTION_LINK_ID, IMG_GLOBAL_L1)); 
	
	ADD_APPLICATION_MENUITEM((WAP_BOOKMARKOPTION_MENU_EDIT_MENU_ID, WAPBOOKMARKOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_BOOKMARKOPTION_EDIT_ID, IMG_GLOBAL_L2)); 
	 	
	ADD_APPLICATION_MENUITEM((WAP_BOOKMARKOPTION_MENU_DELETE_MENU_ID, WAPBOOKMARKOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_BOOKMARKOPTION_DELETE_ID, IMG_GLOBAL_L3));

	ADD_APPLICATION_MENUITEM((WAP_BOOKMARKOPTION_MENU_DELETEALL_MENU_ID, WAPBOOKMARKOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_BOOKMARKOPTION_DELETEALL_ID, IMG_GLOBAL_L4));

	ADD_APPLICATION_MENUITEM((WAP_BOOKMARKOPTION_MENU_ADD_MENU_ID, WAPBOOKMARKOPTION_MAIN_MENU,NUM_WAP_BOOKMARKADD,
								WAP_BOOKMARKOPTION_MENU_ADDURL_MENU_ID,
								WAP_BOOKMARKOPTION_MENU_ADDTITLE_MENU_ID,
								WAP_BOOKMARKOPTION_MENU_ADDFINISH_MENU_ID,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_BOOKMARKOPTION_ADD_ID, IMG_GLOBAL_L5));
		//Bookmark option when bookmark null//
	ADD_APPLICATION_MENUITEM((WAPEMPTYBOOKMARKOPTION_MAIN_MENU, NULL,1,
								WAP_BOOKMARKOPTION_MENU_ADD_MENU_ID,
								HIDE,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_MAIN_MENU_CAPTION, IMG_WAP_MAIN_MENU_ICON));

	ADD_APPLICATION_MENUITEM((WAP_BOOKMARKOPTION_MENU_ADDURL_MENU_ID, WAP_BOOKMARKOPTION_MENU_ADD_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_BOOKMARKOPTION_ADDURL_ID, IMG_GLOBAL_L1));

	ADD_APPLICATION_MENUITEM((WAP_BOOKMARKOPTION_MENU_ADDTITLE_MENU_ID, WAP_BOOKMARKOPTION_MENU_ADD_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_BOOKMARKOPTION_ADDTITLE_ID, IMG_GLOBAL_L2));

	ADD_APPLICATION_MENUITEM((WAP_BOOKMARKOPTION_MENU_ADDFINISH_MENU_ID, WAP_BOOKMARKOPTION_MENU_ADD_MENU_ID,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_BOOKMARKOPTION_ADDFINISH_ID, IMG_GLOBAL_L3));

	ADD_APPLICATION_MENUITEM((WAPHISTORYOPTION_MAIN_MENU, NULL,NUM_WAP_HISTORYOPTION,
								WAP_HISTORYOPTION_MENU_DELETE_MENU_ID,
								WAP_HISTORYOPTION_MENU_DELETEALL_MENU_ID,
								HIDE,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_MAIN_MENU_CAPTION, IMG_WAP_MAIN_MENU_ICON)); 

	ADD_APPLICATION_MENUITEM((WAP_HISTORYOPTION_MENU_DELETE_MENU_ID, WAPHISTORYOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_HISTORYOPTION_DELETE_ID, NULL)); 

	ADD_APPLICATION_MENUITEM((WAP_HISTORYOPTION_MENU_DELETEALL_MENU_ID, WAPHISTORYOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_HISTORYOPTION_DELETEALL_ID, NULL));

/***************************************************************************** 
*  Pushbox option
*****************************************************************************/	
	ADD_APPLICATION_MENUITEM((WAPPUSHBOXOPTION_MAIN_MENU, NULL,NUM_WAP_PUSHBOXOPTION,			
								WAP_PUSHBOXOPTION_MENU_LINK_MENU_ID,
								WAP_PUSHBOXOPTION_MENU_DELETE_MENU_ID,
								WAP_PUSHBOXOPTION_MENU_DELETEALL_MENU_ID,
								HIDE,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_MAIN_MENU_CAPTION, IMG_WAP_MAIN_MENU_ICON)); 
	
	ADD_APPLICATION_MENUITEM((WAP_PUSHBOXOPTION_MENU_LINK_MENU_ID, WAPPUSHBOXOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_PUSHBOXOPTION_LINK_ID, IMG_GLOBAL_L1)); 
	
	ADD_APPLICATION_MENUITEM((WAP_PUSHBOXOPTION_MENU_DELETE_MENU_ID, WAPPUSHBOXOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_PUSHBOXOPTION_DELETE_ID, IMG_GLOBAL_L2)); 

	ADD_APPLICATION_MENUITEM((WAP_PUSHBOXOPTION_MENU_DELETEALL_MENU_ID, WAPPUSHBOXOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_PUSHBOXOPTION_DELETEALL_ID, IMG_GLOBAL_L3));	 	
	
/***************************************************************************** 
*  Offline option
*****************************************************************************/	
	ADD_APPLICATION_MENUITEM((WAPOFFLINEOPTION_MAIN_MENU, NULL,NUM_WAP_OFFLINEOPTION,			
								WAP_OFFLINEOPTION_MENU_LINK_MENU_ID,
								WAP_OFFLINEOPTION_MENU_DELETE_MENU_ID,
								WAP_OFFLINEOPTION_MENU_DELETEALL_MENU_ID,
								HIDE,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_MAIN_MENU_CAPTION, IMG_WAP_MAIN_MENU_ICON)); 
	
	ADD_APPLICATION_MENUITEM((WAP_OFFLINEOPTION_MENU_LINK_MENU_ID, WAPPUSHBOXOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OFFLINEOPTION_LINK_ID, IMG_GLOBAL_L1)); 
	
	ADD_APPLICATION_MENUITEM((WAP_OFFLINEOPTION_MENU_DELETE_MENU_ID, WAPPUSHBOXOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OFFLINEOPTION_DELETE_ID, IMG_GLOBAL_L2)); 

	ADD_APPLICATION_MENUITEM((WAP_OFFLINEOPTION_MENU_DELETEALL_MENU_ID, WAPPUSHBOXOPTION_MAIN_MENU,0,
								SHOW,MOVEABLEACROSSPARENT,DISP_LIST, 
								STR_WAP_OFFLINEOPTION_DELETEALL_ID, IMG_GLOBAL_L3));		

}
#endif
#endif
