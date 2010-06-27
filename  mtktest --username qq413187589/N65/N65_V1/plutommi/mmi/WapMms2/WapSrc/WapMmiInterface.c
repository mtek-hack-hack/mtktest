
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
 * Module Name: MmsMmiInterface.c
 *
 * Module Function: 
 *     Author Name: 
 *     Create Date: 08/29/2005
 *
 *========================================================================
 */
 #ifdef CMS_NEW_APP
 #ifdef __MOD_SMSAL__
/***************************************************************************** 
* Include files 
*****************************************************************************/

// Include: MMI header file ------------------
#define __NEWSIMULATOR 
#include "MMI_features.h" 
#include "stdC.h"
#include "L4Dr1.h"
//#include <windows.h>
#include "PixtelDataTypes.h"

//... Add More MMI header
#include "EventsGprot.h"
#include "HistoryGprot.h"
#include "GlobalMenuItems.h"
#include "GlobalConstants.h"
#include "Globaldefs.h"
#include "wgui_categories.h"
#include "wgui_categories_inputs.h"
#include "CustMenuRes.h"
#include "CommonScreens.h"
#include "Unicodexdcl.h"
#include "TimerEvents.h"
#include "DebugInitDef.h"

//...Add MSG header
#include "customer_ps_inc.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "WapResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SmsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "CellBroadcastType.h"

#ifdef __MMI_MESSAGES_CHAT__
/* under construction !*/
/* under construction !*/
#endif

#include "Gui_ems.h"
#include "GSM7BitDefaultAlphabet.h"

#include "smsal_l4c_enum.h"

#include "NVRAMEnum.h"
#include "NVRAMProt.h"
#include "NVRAMType.h"

#include "CSP.h"
#include "FrameworkStruct.h"
#include "MainMenuDef.h"
#include "CallHistoryGProts.h"
#include "CallManagementGprot.h"
#include "CallhistoryEnum.h"
#include "MiscFunctions.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "PhoneBookGprot.h"
#include "IdleAppProt.h"
#include "AlarmFrameworkProt.h"

#include "wgui_status_icons.h"
#include "gpioInc.h"
#include "KeyBrd.h"
#include "SubLCDHistoryGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "MmsResourceData.h"
#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif
#undef __NEWSIMULATOR

/*for arm compile*/
#include "GlobalDefs.h"
#include "stack_config.h"
#include "kal_release.h" 
#include "kal_trace.h"
#include "PixtelDataTypes.h"
#include "CustomCfg.h"
#include "Unicodexdcl.h"
#include "EventsGprot.h"
#include "ProtocolEvents.h"
#include "mmi_msg_struct.h"

#include "HardwareEvents.h"
#include "TimerEvents.h"
#include "FileMgr.h"
#include "fs_func.h"
#include  "SettingProfile.h"
#include  "stack_msgs.h"
#include  "Soc_api.h"
#include "SettingDefs.h"
#include "SettingGprots.h"
#include "MessagesResourceData.h"
#include "fs_type.h"
#include "fs_func.h"
#include "WrapperGprot.h"
#include "Gdi_image_wbmp.h"
#ifdef CMS_SURPPORT_PNG
#include "Gdi_image_png.h"
#endif
#ifdef CMS_SURPPORT_BMP
#include "Gdi_image_bmp.h"

#endif
#include "Gdi_image_jpeg.h"
#include "Gdi_image_gif.h"
#include "Gdi_include.h"
/************************************************************************/
/* 彩信整合函数声明                                                    				 */
/************************************************************************/
#include "Cms_MMSGlobal.h"
#include "CMSPushSMS.h"
#include "Cms_MMSClib.h"
/************************************************************************/
/*					replant declare										*/							
/************************************************************************/
#include "CmsBrowserPublic.h"
#include "CmsBrowserCfg.h"
#include "Cms_BRWGlobal.h"
#include "CmsBrowserAPI.h"
#include "CmsPushbox.h"
#include "CmsFunc.h"
#include "CmsWapMmsAdp.h"
#include "Cms_WHTTPCookieMemery.h"
#include "Cms_whttp_public.h"
#include "CmsBrowserSetup.h"
#include "CmsHistory.h"
#include "CmsBookmark.h"
#include "CmsInitBrowser.h"
#include "CmsSaveAs.h"
#include "CmsBRAccesskeyBGSound.h"
#include "CmsSelectCtrl.h"
/************************************************************************/
/*					Macro define											*/
/************************************************************************/

#define MTKMESSAGELOOP

#define SOCKET_RET_CODE_TO_HDI(errno)  sms_socket_retcode(errno)

/*Edit size for MTK input number */
#define CMS_EDIT_SIZE 					64//不能修改为128
#define CMS_EDIT_SEND_SIZE 			512
int 	IputModuleLength=30;
/************************************************************************/
/*					scroll bar  define			   							*/
/************************************************************************/
vertical_scrollbar categoryWap_vbar;
#ifdef WAP_SHOW_ACROSS_SCOLLBAR
horizontal_scrollbar categoryWap_hbar;
#endif
/************************************************************************/
/*					Global varibale define									*/
/************************************************************************/
kal_int8 			Socket_Id[3] = {-10,-10,-10};
kal_uint8 		sms_push_buf[RECV_BUFLEN]; 
kal_int32 		pdu_len; 
kal_uint8			wap_filename[MMS_FILE_NAME_LEN];
WAP_CONFIG 		gWapTemp;
sockaddr_struct 	sock_addr;
sockaddr_struct 	mms_sock_addr;

int 				cms_UIIsPassword=0;
int 				cms_UIIsNumber=0;
int   				cms_bPostMessageFlag=0;

/*netacc_id for MTK net account changed*/    					
int netacc_id = -1;

extern P_CMS_BROWSERINFO   	pBrowserInfo;
extern mms_flag 				mmsflag;
extern GPRSDataAccountNode 	g_GPRS_DataAccount[MAX_DATA_ACCOUNT_GPRS_LIMIT];
extern DataAccountNode 		g_DataAccount[MAX_DATA_ACCOUNT_GSM_LIMIT];
extern BOOL  					gif_play_from_mms;	/*		*/

extern U8					servicelist[SERVICE_LIST_ITEM][60];
extern S32					ghiliindex;
extern MMS_CONFIG			gconfig;
#ifdef CMS_PC_CONFIG_SOFTWARE
extern cms_wap_profile_struct  cms_wap_profile_default;
extern cms_mms_profile_struct  cms_mms_profile_default;
extern cms_wap_bookmark_struct cms_wap_bookmark_default;
extern cms_wap_config_struct   cms_wap_config_default;
extern cms_mms_config_struct   cms_mms_config_default;
#endif
/************************************************************************/
/*          extern int variable for check memory                                				 */
/************************************************************************/

/************************************************************************/
/* Flag  define  for MTK wap browser                                   						 */
/************************************************************************/
int 		SuspendFlag = 0;  			/*for MTK wap browser enter browser Option flag*/
int 		browserflag =0;   			/*是否进入浏览器模块，1，成功启动start，0，退出*/
int 		ResourceValue_State = -1;  	/*for MTK Wap browser get foucs key statue*/
U16 		BrowserScreen_ID;	  		/*Current Screen ID*/
int 		exteriorbrowserpage = 0; 	/*for MTK exterior enter browser*/
							 		//0 browsermenu. 1 homepage.  2 input url.
kal_bool 	IsBookMarkNull = KAL_TRUE;	
S8		TLSUnicodeBuf[MAX_SHOW_STRING_BUF*16];/*显示证书信息*/

/************************************************************************/
/* Index define   for MTK Get item index and for browser operation     				 */
/************************************************************************/
long BookmarkIndex = 0;		/*for MTK wap bowser bookmark item index*/
long HistoryUrlIndex = 0;		/*for MTK wap bowser input history item index*/
long HistoryIndex = 0;		/*for MTK wap bowser page history item index*/
long PushboxIndex = 0;		/*for MTK wap bowser push message item index*/
long GsmAccIndex = 0;		/*for MTK wap bowser Gsm account ID item index*/
long GprsAccIndex = 0;		/*for MTK wap bowser Gprs account ID item index*/
long ImageSetIndex = 0;		/*for MTK wap bowser Image set item index*/
long BGMusicSetIndex = 0;	/*for MTK wap bowser Image set item index*/
long PushMessageSetIndex=0;
long OfflineSetIndex=0;
long WapDoneIndex = 0;		/*for MTK wap bowser Wap Done item index*/
long WapSecurityIndex = 0;		/*for MTK wap bowser Wap Security item index*/
long WapConnectModeIndex=0;
/************************************************************************/
/* Num define	for MTK wap browser Num count                           					*/
/************************************************************************/
int UnreadPushMessageNum = 0;	/*for MTK get unread push message number*/
int HistoryMessageNum = 0;		/*for MTK get history message total number*/
CmsSelectCtrlItems g_CtrlItems;	/*for MTK get select box infor*///changed by yangjun 06-02-07 for selectbox form
/************************************************************************/
/*                                                                      								*/
/************************************************************************/
#define BOOK_URL_LENGTH	128
#define BOOK_TITLE_LENGTH	64

U8 NewLink_UrlEdit[260];		/*New link URL,homepage URL*/
U8 InputContent_Edit[1024];
U8 BookMark_UrlEdit[1026];
U8 Setting_Gateway[65] = {0};
U8 Setting_Port[10] = {0};

S8 Old_gprs_mode = 0;//add for goback when setting is wrong
int CancleDownload = 0;
int BrowserByHotkey=0;
int BackToIdle=0;
int MMSPushByBrowser=0;
int MainMenu_State;/*WAP_MENU_HOMEPAGE_MENU, 	WAP_MENU_BOOKMARK_MENU,	WAP_MENU_NEWLINK_MENU, 
		WAP_MENU_PAGEHISTORY_MENU, 	WAP_MENU_OFFLINE_MENU,	WAP_MENU_SETTINGS_MENU,	WAP_MENU_PUSHBOX_MENU,
		NUM_WAP_MAIN_MENU,	*/
int OptionMenu_State;/*WAP_OPTION_BOOKMARKRENAME,	WAP_OPTION_BOOKMARKTITLEADD,	WAP_OPTION_BOOKMARKURLADD,
			WAP_OPTION_NEWLINK,	WAP_OPTION_HOMEPAGE,	WAP_OPTION_GATEWAY,	WAP_OPTION_PORT,
			NUM_WAP_OPTIONSELECT*/
typedef struct {
	U8 Password[MAX_WAP_PASSWD_LEN];
	U8 Username[MAX_WAP_USERNAME_LEN];
	U8 ConfirmPassword[MAX_WAP_PASSWD_LEN];
} CmsSecurityContext;
CmsSecurityContext gSecurityContext;
P_CMS_BROWSER_U8 JpgImageBuf = NULL;
/************************************************************************/
/* Download variable define		for MTK wapbrowser download             			*/
/************************************************************************/
char * DownLoad_DataBuf = NULL;		/*Download buf get from wapbrowser must free*/ 
int	 DownLoad_FileType;				/*Download file type */
int 	 DownLoad_DataLen;				/*Download buf length*/
int	 Option_Ok=0;				/*down picture menu*/
int 	 Down_Scrollbar_OK=0;
int 	 BorwserFormPush=0;
/************************************************************************/
/* Cache Set define		for MTK Cache implement                        				 */
/************************************************************************/

/************************************************************************/
/* count malloc and free number for MTK wapbrowser check memory OK     			 */
/************************************************************************/
/************************************************************************/
/*			                         extern function declare                              			 */
/************************************************************************/
extern void initURL(void);
extern void ClearAllMarqueeMovie(void);
extern void mmi_get_index(S32 nIndex);
extern void Cms_Browser_SetBackFalse(void);
extern P_CMS_BROWSER_U8 Cms_Browser_GetPUSHTimeById(CMS_BROWSER_U32 inputid);
extern P_CMS_BROWSER_U8 Cms_Browser_GetPUSHUrlById(CMS_BROWSER_U32 inputid);
extern CMS_BROWSER_RET Cms_Browser_SaveItemEvent( int item );
extern int	CmsIsImageSelected( void );
extern CMS_BROWSER_U32 Cms_browser_GetBGMusicStatus(void);
extern CMS_BROWSER_VOID Cms_Browser_StopBrowserTimer(CMS_BROWSER_VOID);
extern CMS_BROWSER_VOID Cms_Browser_ClearAllHistory( CMS_BROWSER_VOID );
extern CMS_BROWSER_U32 Cms_Brw_Get_DisplayState(void);
extern CMS_BROWSER_S32 Cms_Browser_IsZeroURL( void );
extern CMS_BROWSER_BOOL Cms_Browser_GetWTAPhoneNumber(P_CMS_APPLICATION_DATA appdata);
extern int  cms_utf2unicode(unsigned char*utf8,int utf_len,unsigned short *unicode,int uni_len);
/************************************************************************/
/*			                         function declare                              				 */
/************************************************************************/
void mmi_wap_settings_service_list(void);
void mmi_wap_settings_service_list_set(void);
void mmi_wap_settings_service_list_edit(void);
void EntryScrWapServiceIdListMenu(void);
void wap_set_curr_file_to_setting(void);
void wap_set_setting_file_for_default_active(void);
void EntryScrWapServiceEditMenuPre(void);
void EntryScrWapServiceEditMenu(void);
void EntryScrWapCleareCookieMenu(void);
void EntryScrWapConnectModeSet(void);
void wap_init_all_pre_setting_file(void);
void Cms_hex_trace(kal_uint8 *buf,kal_int32 pdu_len);
int sms_socketBind (kal_int8 socketId, sockaddr_struct *addr);
int sms_socket_retcode(kal_int8 ret);
void Cms_Browser_GetEditContent(void);
void Cms_Browser_EditBoxNochange(void);
static U8 WapClamEventHandler(void* ptr);
void EntryScrWapBrowserByHotkey(U16 ScreenId);
extern CMS_BROWSER_VOID Cms_Brw_CancelPageDownload(CMS_BROWSER_VOID);

pBOOL mmi_wap_done_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask );
S32 mmi_wap_done_list_get_hint( S32 item_index, UI_string_type *hint_array );

pBOOL mmi_wap_bookmark_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask );
S32 mmi_wap_bookmark_list_get_hint( S32 item_index, UI_string_type *hint_array );

pBOOL mmi_wap_setimage_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask );
S32 mmi_wap_setimage_list_get_hint( S32 item_index, UI_string_type *hint_array );

pBOOL mmi_wap_setmusic_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask );
S32 mmi_wap_setmusic_list_get_hint( S32 item_index, UI_string_type *hint_array );

pBOOL mmi_wap_history_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask );
S32 mmi_wap_history_list_get_hint( S32 item_index, UI_string_type *hint_array );

pBOOL mmi_wap_gsmacc_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask );
S32 mmi_wap_gsmacc_list_get_hint( S32 item_index, UI_string_type *hint_array );

pBOOL mmi_wap_gprsacc_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask );
S32 mmi_wap_gprsacc_list_get_hint( S32 item_index, UI_string_type *hint_array );

pBOOL mmi_wap_setsecurity_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask );
S32 mmi_wap_setsecurity_list_get_hint( S32 item_index, UI_string_type *hint_array );
void mmi_wap_setting_service_list_hint(U16 index);
pBOOL mmi_wap_setprotocal_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask );
S32 mmi_wap_setprotocal_list_get_hint( S32 item_index, UI_string_type *hint_array );
void mmi_wap_setting_push_hint(U16 index);
void mmi_wap_setting_image_hint(U16 index);
void mmi_wap_setting_music_hint(U16 index);
void mmi_wap_setting_cerfiticates_hint(U16 index);
void mmi_wap_setting_protocal_hint(U16 index);
int mmi_wap_judge_wap_setting(void);
void Brw_Keystar_Uppage(void);
void Brw_Keystar_Downpage(void);
/*==============================================================
*   Function Name:	mmi_msg_set_msg_menu_highlight_handler
*   Input        :  void
*   Output       :  void
*   description  : Set message menu highlight handler
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_set_wap_menu_highlight_handler(void)	//wapbrowser main menu item handle set
{
	SetHiliteHandler(WAP_MENU_HOMEPAGE_MENU_ID, mmi_wap_main_homepage);
	SetHiliteHandler(WAP_MENU_BOOKMARK_MENU_ID, mmi_wap_main_bookmark);
	SetHiliteHandler(WAP_MENU_NEWLINK_MENU_ID, mmi_wap_main_newlink);
	SetHiliteHandler(WAP_MENU_HISTORY_MENU_ID, mmi_wap_main_history);
	SetHiliteHandler(WAP_MENU_OFFLINE_MENU_ID, mmi_wap_main_offline);
	SetHiliteHandler(WAP_MENU_SETTINGS_MENU_ID, mmi_wap_main_settings);
	#ifndef SUPPORT_SMSMMS_COMBINE
	SetHiliteHandler(WAP_MENU_PUSHBOX_MENU_ID, mmi_wap_main_pushbox);
	#endif
}
/*==============================================================
*   Function Name: mmi_wap_set_wapoption_menu_highlight_handler
*   Input        :  void
*   Output       :  void
*   description  : Set option menu highlight handler
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_set_wapoption_menu_highlight_handler(void) //page browser option menu item handle set
{
	SetHiliteHandler(WAP_OPTION_MENU_SAVEHOMEPAGE_MENU_ID, mmi_wap_option_savehomepage);
	SetHiliteHandler(WAP_OPTION_MENU_BROWSEREXIT_MENU_ID, mmi_wap_option_exitbrowser);
	SetHiliteHandler(WAP_OPTION_MENU_BACK_MENU_ID, mmi_wap_option_back);
	SetHiliteHandler(WAP_OPTION_MENU_BOOK_MENU_ID, mmi_wap_option_savebookmark);
	SetHiliteHandler(WAP_OPTION_MENU_URL_MENU_ID, mmi_wap_option_currentURL);
	SetHiliteHandler(WAP_OPTION_MENU_REFRESH_MENU_ID, mmi_wap_option_refresh);
	SetHiliteHandler(WAP_OPTION_MENU_SAVECURRENTPAGE_MENU_ID, mmi_wap_option_savecurrentpage);
	SetHiliteHandler(WAP_OPTION_MENU_BROWSERHOMEPAGE_MENU_ID, mmi_wap_option_homepage);
}
/*==============================================================
*   Function Name: mmi_wap_set_wapbookmarkoption_menu_highlight_handler
*   Input        :  void
*   Output       :  void
*   description  : Set bookmark menu highlight handler
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_set_wapbookmarkoption_menu_highlight_handler(void) //bookmark manage option item handle set
{
	SetHiliteHandler(WAP_BOOKMARKOPTION_MENU_LINK_MENU_ID, mmi_wap_bookmark_link);
	SetHiliteHandler(WAP_BOOKMARKOPTION_MENU_EDIT_MENU_ID, mmi_wap_bookmark_rename);
	SetHiliteHandler(WAP_BOOKMARKOPTION_MENU_DELETEALL_MENU_ID, mmi_wap_bookmark_deleteall);
	SetHiliteHandler(WAP_BOOKMARKOPTION_MENU_DELETE_MENU_ID, mmi_wap_bookmark_delete);
	SetHiliteHandler(WAP_BOOKMARKOPTION_MENU_ADD_MENU_ID, mmi_wap_bookmark_add);
}

void mmi_wap_set_wapemptybookmarkoption_menu_highlight_handler(void) //bookmark manage option item handle set
{
	SetHiliteHandler(WAP_BOOKMARKOPTION_MENU_ADD_MENU_ID, mmi_wap_bookmark_add);
}
/*==============================================================
*   Function Name: mmi_wap_set_wappushboxoption_menu_highlight_handler
*   Input        :  void
*   Output       :  void
*   description  : Set pushbox menu highlight handler
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_set_wappushboxoption_menu_highlight_handler(void) //push box option item handle set
{
	SetHiliteHandler(WAP_PUSHBOXOPTION_MENU_LINK_MENU_ID, mmi_wap_push_link);
	SetHiliteHandler(WAP_PUSHBOXOPTION_MENU_DELETE_MENU_ID, mmi_wap_push_delete);
	SetHiliteHandler(WAP_PUSHBOXOPTION_MENU_DELETEALL_MENU_ID, mmi_wap_push_deleteall);
}
/*==============================================================
*   Function Name: mmi_wap_set_wapofflineoption_menu_highlight_handler
*   Input        :  void
*   Output       :  void
*   description  : Set pushbox menu highlight handler
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_set_wapofflineoption_menu_highlight_handler(void) //push box option item handle set
{
	SetHiliteHandler(WAP_OFFLINEOPTION_MENU_LINK_MENU_ID, mmi_wap_offline_link);
	SetHiliteHandler(WAP_OFFLINEOPTION_MENU_DELETE_MENU_ID, mmi_wap_offline_delete);
	SetHiliteHandler(WAP_OFFLINEOPTION_MENU_DELETEALL_MENU_ID, mmi_wap_offline_deleteall);
}
/*==============================================================
*   Function Name: mmi_wap_set_wapsettings_menu_highlight_handler
*   Input        :  void
*   Output       :  void
*   description  : Set settings menu highlight handler
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_set_wapsettings_menu_highlight_handler(void)	//wapbrowser setting item handle set
{
	SetHiliteHandler(WAP_SETTINGS_MENU_SERVICE_ID_MENU_ID, mmi_wap_settings_service_list);
	SetHiliteHandler(WAP_SETTINGS_MENU_CLEARPAGEHISTOY_MENU_ID, mmi_wap_settings_clearhistory);
	SetHiliteHandler(WAP_SETTINGS_MENU_CLEARCACHE_MENU_ID, mmi_wap_settings_clearcache);
	SetHiliteHandler(WAP_SETTINGS_MENU_CLEARCOOKIE_MENU_ID, mmi_wap_settings_clearcookie);
	SetHiliteHandler(WAP_SETTINGS_MENU_SETPUSHMESSAGE_MENU_ID, mmi_wap_settings_pushmessage);
	SetHiliteHandler(WAP_SETTINGS_MENU_SETIMAGE_MENU_ID, mmi_wap_settings_image);
	SetHiliteHandler(WAP_SETTINGS_MENU_SETBGMUSIC_MENU_ID, mmi_wap_settings_bgmusic);
	SetHiliteHandler(WAP_SETTINGS_MENU_SETCERTIFICATES_MENU_ID, mmi_wap_settings_certificates);	

	SetHintHandler(WAP_SETTINGS_MENU_SERVICE_ID_MENU_ID, mmi_wap_setting_service_list_hint);
	SetHintHandler(WAP_SETTINGS_MENU_SETPUSHMESSAGE_MENU_ID, mmi_wap_setting_push_hint);
	SetHintHandler(WAP_SETTINGS_MENU_SETIMAGE_MENU_ID, mmi_wap_setting_image_hint);
	SetHintHandler(WAP_SETTINGS_MENU_SETBGMUSIC_MENU_ID, mmi_wap_setting_music_hint);
	SetHintHandler(WAP_SETTINGS_MENU_SETCERTIFICATES_MENU_ID, mmi_wap_setting_cerfiticates_hint);
#ifdef SUPPORT_SWITCH_PROTOCOL
	SetHiliteHandler(WAP_SETTINGS_MENU_SETCONNECTMODE_MENU_ID, mmi_wap_settings_protocal);	
	SetHintHandler(WAP_SETTINGS_MENU_SETCONNECTMODE_MENU_ID, mmi_wap_setting_protocal_hint);
#endif	
}
/*==============================================================
*   Function Name: mmi_wap_set_wapsetnetacc_menu_highlight_handler
*   Input        :  void
*   Output       :  void
*   description  : Set net menu highlight handler
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_set_service_list_option_menu_highlight_handler(void) 
{
	SetHiliteHandler(WAP_SETTINGS_MENU_SERVICE_SET_MENU_ID, mmi_wap_settings_service_list_set);
	SetHiliteHandler(WAP_SETTINGS_MENU_SERVICE_EDIT_MENU_ID, mmi_wap_settings_service_list_edit);
}
/*==============================================================
*   Function Name: mmi_wap_set_wapsetnetacc_menu_highlight_handler
*   Input        :  void
*   Output       :  void
*   description  : Set net menu highlight handler
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_set_wapsetnetacc_menu_highlight_handler(void) //wapbrowser net account setting menu item handle set
{
	SetHiliteHandler(WAP_SETTINGS_MENU_SETGSMNETACC_MENU_ID, mmi_wap_setnet_gsm);
	SetHiliteHandler(WAP_SETTINGS_MENU_SETGPRSNETACC_MENU_ID, mmi_wap_setnet_gprs);
}
/************************************************************************/
/* 浏览器相关  Index 菜单号获取                                         */
/************************************************************************/
void GetBookmarkIndex(S32 nIndex)	//bookmark index
{
	BookmarkIndex	=	nIndex;
}
void GetHistoryUrlIndex(S32 nIndex)	//input history index
{
	HistoryUrlIndex = nIndex;
}
void GetHistoryIndex(S32 nIndex)		//page history index
{
	HistoryIndex = nIndex;
}
void GetPushboxIndex(S32 nIndex)		//push message index
{
	PushboxIndex = nIndex;
}
void GetGsmAccIndex(S32 nIndex)		//gsm account index
{
	GsmAccIndex = nIndex;
}
void GetGprsAccIndex(S32 nIndex)		//gprs account index
{
	GprsAccIndex = nIndex;
}
void GetImageSetIndex(S32 nIndex)		//image setting index
{
	ImageSetIndex = nIndex;
}
void GetBGMusicSetIndex(S32 nIndex)	//music setting index
{
	BGMusicSetIndex=nIndex;
}
void GetPushMessageSetIndex(S32 nIndex)//pushbox setting index
{
	PushMessageSetIndex=nIndex;
}
void GetOfflineSetIndex(S32 nIndex)	//offline setting index
{
	OfflineSetIndex=nIndex;
}
void GetWapDoneIndex(S32 nIndex)	//wap done index
{
	WapDoneIndex = nIndex;
}
void GetWapSecurityIndex(S32 nIndex)	//wap security index
{
	WapSecurityIndex = nIndex;
}

void GetWapConnectModeIndex(S32 nIndex)	//wap connect mode index
{
	WapConnectModeIndex = nIndex;
}
/*==============================================================
*   Function Name:	EntryScrWapBrowserMenuList
*   Input        :  void
*   Output       :  void
*   description  :	Entry WAP main menu screen
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapBrowserMenuList(void)
{	
	U8* guiBuffer=NULL;
	U16 numItems=0;
	U16 nStrItemList[MAX_SUB_MENUS];
	U16 itemIcons[MAX_SUB_MENUS];
	U8* popUpList[MAX_SUB_MENUS];
	U32 menuItemId=-1;

	U32 maskingByte=-1;
	U8** pPopUpList=NULL;
#ifdef __USB_IN_NORMAL_MODE__    
    /* check is in mass storage mode */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
//等待平台初始化完毕，如果需要速度快，把下面这个判断可以去掉，但建议最好不要去掉。
#ifdef SUPPORT_SMSMMS_COMBINE
	if(!g_msg_cntx.msg_init)
	{
		DisplayPopup((PU8)GetString(STR_WAP_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
		return;
	}
#endif
	/*判断当前网络资源是否被彩信模块占用*/
	if(mmsflag.gsend_recv == TRUE)
	{
		DisplayPopup((U8*)GetString(STR_WAP_WARING_NETBUSY), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
//判断完毕	
	Option_Ok=0;
	Down_Scrollbar_OK=0;
	BrowserByHotkey=0;
	MMSPushByBrowser=0;
	BorwserFormPush=0;
	cms_bPostMessageFlag=0;
	wap_Tracer("EntryScrWapBrowserMenuList in");
	if (browserflag == 0)
	{
		SuspendFlag = 0;
		Cms_LoadFile();

		cms_memset(NewLink_UrlEdit, 0x0, sizeof(NewLink_UrlEdit));
		cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
		wap_Tracer("Cms_Browser_StartEvent enter......");
		if (Cms_Browser_StartEvent())
		{			
			exteriorbrowserpage = 0;
			browserflag = 1;			
			CancleDownload = 0;
		}
		else
		{
			wap_Tracer("no memory!");
			//FS_Delete(L"C:\\wap\\CmsCaCheHistory");
			cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
			Cms_GetWapCachefilename(wap_filename);	
			Cms_Adp_fdelete((const unsigned short * )wap_filename);	
			wap_Tracer("no memory!");
			return;
		}
	
		wap_net_data_init();
	}

	EntryNewScreen(SCR_ID_WAP_MAIN_MENU,	NULL, EntryScrWapBrowserMenuList, NULL);	
	BrowserScreen_ID= SCR_ID_WAP_MAIN_MENU;
	
	SetParentHandler(SERVICES_WAP_MENU_ID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	numItems = GetNumOfChild(SERVICES_WAP_MENU_ID);
	GetSequenceStringIds(SERVICES_WAP_MENU_ID, nStrItemList);
	GetSequenceImageIds(SERVICES_WAP_MENU_ID, itemIcons);

	mmi_wap_set_wap_menu_highlight_handler();
	
	menuItemId = GetChildMenuIDIndexByParentMenuID(SERVICES_WAP_MENU_ID, WAP_MENU_HOMEPAGE_MENU_ID);
	if(menuItemId!=-1)
	{
		if(IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP,CSP_SM_MT))
			ResetBit(maskingByte,menuItemId);
	}

	menuItemId = GetChildMenuIDIndexByParentMenuID(SERVICES_WAP_MENU_ID, WAP_MENU_BOOKMARK_MENU_ID);
	if(menuItemId!=-1)
	{
		if(IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP,CSP_SM_MT))
			ResetBit(maskingByte,menuItemId);
	}
	
	menuItemId = GetChildMenuIDIndexByParentMenuID(SERVICES_WAP_MENU_ID, WAP_MENU_NEWLINK_MENU_ID);
	if(menuItemId!=-1)
	{
		if(IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP,CSP_SM_MT))
			ResetBit(maskingByte,menuItemId);
	}
	
	menuItemId = GetChildMenuIDIndexByParentMenuID(SERVICES_WAP_MENU_ID, WAP_MENU_HISTORY_MENU_ID);
	if(menuItemId!=-1)
	{
		if(IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP,CSP_SM_MT))
			ResetBit(maskingByte,menuItemId);
	}

	menuItemId = GetChildMenuIDIndexByParentMenuID(SERVICES_WAP_MENU_ID, WAP_MENU_OFFLINE_MENU_ID);
	if(menuItemId!=-1)
	{
		if(IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP,CSP_SM_MT))
			ResetBit(maskingByte,menuItemId);
	}
	
	menuItemId = GetChildMenuIDIndexByParentMenuID(SERVICES_WAP_MENU_ID, WAP_MENU_SETTINGS_MENU_ID);
	if(menuItemId!=-1)
	{
		if(IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP,CSP_SM_MT))
			ResetBit(maskingByte,menuItemId);
	}
	
	menuItemId = GetChildMenuIDIndexByParentMenuID(SERVICES_WAP_MENU_ID, WAP_MENU_PUSHBOX_MENU_ID);
	if(menuItemId!=-1)
	{
		if(IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP,CSP_SM_MT))
			ResetBit(maskingByte,menuItemId);
	}
	
	MaskStringItems(popUpList,(U8)numItems,maskingByte);
	MaskItems(itemIcons,(U8)numItems,maskingByte);
	MaskHiliteItems(SERVICES_WAP_MENU_ID,maskingByte);
	numItems=MaskItems(nStrItemList,(U8)numItems,maskingByte);
	SetMessagesCurrScrnID(SCR_ID_WAP_MAIN_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_MAIN_MENU);	
	
	ShowCategory52Screen(STR_WAP_MAIN_MENU_CAPTION, IMG_WAP_MAIN_MENU_ICON,
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer );

	SetRightSoftkeyFunction(ExitWapBrowser, KEY_EVENT_UP);
//	SetKeyHandler(ExitWapBrowser, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
#ifdef __MMI_CLAMSHELL__
//	SetInterruptEventHandler(WapClamEventHandler, NULL,MSG_ID_MMI_EQ_GPIO_DETECT_IND);
	/* __MMI_CLAMSHELL__ */
#endif 
}
/*==============================================================
*   Function Name:	ExitWapBrowser
*   Input        :  void
*   Output       :  void
*   description  :	exit wapbrowser by back key
*   author       :  
*   date         :	
==============================================================*/
void ExitWapBrowser(void)
{ 
	cms_bPostMessageFlag=0;
	wap_Tracer("ExitWapBrowser");
        //chaozhu.zhou move
    	cms_show_wappush_icon();
	GoBackHistory();
	if (browserflag == 1)
	{
		wap_Tracer("ExitWapBrowser==1");
		CmsSelectCtrlItemsCleanUp(&g_CtrlItems);
		Cms_Browser_SavePUSH();
		Cms_Browser_FreePUSHInfo();	
		Cms_Browser_SaveBrowserSetupToFile();
		Cms_SavePushFile();	
		//Cms_SaveFile();
		Cms_Browser_WriteUIHistory();
		Cms_Browser_WriteOfflineRecord();
		Cms_Browser_ExitEvent();
		Cms_close_soc(2);
		browserflag = 0;		
	}	 
}
/*==============================================================
*   Function Name:	ExitWapBrowserByKey
*   Input        :  void
*   Output       :  void
*   description  :	exit wapbrowser if enter form hot key
*   author       :  
*   date         :	
==============================================================*/
void ExitWapBrowserByKey(void)
{ 
	wap_Tracer("ExitWapBrowser");
	cms_bPostMessageFlag=0;
	cms_show_wappush_icon();	
	DisplayIdleScreen();
	if (browserflag == 1)
	{
		wap_Tracer("ExitWapBrowser==1");
		CmsSelectCtrlItemsCleanUp(&g_CtrlItems);
		Cms_Browser_SavePUSH();
		Cms_Browser_FreePUSHInfo();
		Cms_Browser_SaveBrowserSetupToFile();
		Cms_SavePushFile();	
		Cms_Browser_WriteUIHistory();
		Cms_Browser_WriteOfflineRecord();
		Cms_Browser_ExitEvent();
		Cms_close_soc(2);
		browserflag = 0;
	}	

}
/*==============================================================
*   Function Name:	ExitWapBrowserByEndkey
*   Input        :  void
*   Output       :  void
*   description  :	exit wap browser by endkey
*   author       :  
*   date         :	
==============================================================*/
void ExitWapBrowserByEndkey(void)
{ 
	cms_bPostMessageFlag=0;
	if(BrowserByHotkey==1)
	{
		wap_Tracer("BrowserByHotkey==1");	
		BackToIdle=1;
		DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_WAP_SETTINGS_CLEARCOOKIE_ID),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
		SetLeftSoftkeyFunction(ExitWapBrowserByKey, KEY_EVENT_UP);
		SetRightSoftkeyFunction(OptionRefreshCurrentPageEvent, KEY_EVENT_UP);
	}
	else
	{
		cms_show_wappush_icon();	
		DisplayIdleScreen();
		if (browserflag == 1)
		{
			CmsSelectCtrlItemsCleanUp(&g_CtrlItems);
			Cms_Browser_SavePUSH();
			Cms_Browser_FreePUSHInfo();
			Cms_Browser_SaveBrowserSetupToFile();
			Cms_SaveFile();
			Cms_Browser_ExitEvent();
			Cms_close_soc(2);
			browserflag = 0;
		}	 
	}
}
/*==============================================================
*   Function Name:	mmi_wap_main_homepage
*   Input        :  void
*   Output       :  void
*   description  :	entry of homepage browser
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_main_homepage(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapHomePageMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapHomePageMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	CMS_LOCALLINK_Entry
*   Input        :  void
*   Output       :  void
*   description  :	entry of local file browser
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_main_locallink(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapLocalLinkMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapLocalLinkMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_main_bookmark
*   Input        :  void
*   Output       :  void
*   description  :	entry of bookmark manage
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_main_bookmark(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapBookMarkMenuList, KEY_EVENT_UP);
	//sSetKeyHandler(EntryScrWapBookMarkMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_main_newlink
*   Input        :  void
*   Output       :  void
*   description  :	entry of new url link
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_main_newlink(void)
{
	cms_memset(NewLink_UrlEdit, 0x0, sizeof(NewLink_UrlEdit));
	pfnUnicodeStrcpy((S8 *)NewLink_UrlEdit, (const S8 *)(L"http://"));
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapNewLinkMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapNewLinkMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_main_history
*   Input        :  void
*   Output       :  void
*   description  :	entry of page history list
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_main_history(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapHistoryMenuList, KEY_EVENT_UP);
//	SetKeyHandler(EntryScrWapHistoryMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_main_offline
*   Input        :  void
*   Output       :  void
*   description  :	entry snapshot list
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_main_offline()
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapOffLineMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapOffLineMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_main_settings
*   Input        :  void
*   Output       :  void
*   description  :	entry of setting menu
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_main_settings(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(main_settings_entryScr, KEY_EVENT_UP);
	//SetKeyHandler(main_settings_entryScr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_main_pushbox
*   Input        :  void
*   Output       :  void
*   description  :	entry of pusbox message list
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_main_pushbox(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapPushboxMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapPushboxMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*=============================================================
                                                 wap main menu function list
===============================================================*/
/*==============================================================
*   Function Name:	EntryScrWapHomePageMenuList
*   Input        :  void
*   Output       :  void
*   description  :	enter homepage browser
*   author       :
*   date         :
==============================================================*/
void EntryScrWapHomePageMenuList(void) 
{
	U8 temp[130] = {0};
	wap_Tracer("==EntryScrWapHomePageMenuList=====");
	if(mmsflag.gsend_recv == TRUE)
	{
		DisplayPopup((U8*)GetString(STR_WAP_WARING_NETBUSY), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	Cms_Browser_GetHomepageSetup((P_CMS_BROWSER_U8)temp);
	if (temp[0] == NULL)
	{
		DisplayPopup((U8*)GetString(STR_WAP_HOMEPAGEISNONE_ID), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}

	if(1 == CmsIsImgStackDL())
		CmsAbortDownload();
	MainMenu_State = WAP_MENU_HOMEPAGE_MENU;
	if(Option_Ok==1) 
		GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);	
	else
		Browser_page();	
}
/*==============================================================
*   Function Name:	EntryScrWapLocalLinkMenuList
*   Input        :  void
*   Output       :  void
*   description  :	enter loacl file browser
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapLocalLinkMenuList(void)
{
	Browser_page();
}

/*==============================================================
*   Function Name:	EntryScrWapOPtionBookMarkMenuList
*   Input        :  void
*   Output       :  void
*   description  :	entry wapbookmark menu list screen
*   author       : 
*   date         :
==============================================================*/
void EntryScrWapOPtionBookMarkMenuList(void)
{	
	U8*  guiBuffer;
	S32  hiliteitem;
	int  BookNum = 0;
	P_CMS_BROWSER_U8 title = NULL;
	guiBuffer=NULL;
	
	hiliteitem=0;
	
	/*Get bookmark number*/
	BookNum = 0;
	title = (P_CMS_BROWSER_U8)Cms_Browser_GetBookmarkTitleById((CMS_BROWSER_U32)BookNum);

	browser_mmi_tracer("title=%s",(char*)title);
	
	while( NULL !=  title )
	{
		BookNum ++;
		title = (P_CMS_BROWSER_U8)Cms_Browser_GetBookmarkTitleById((CMS_BROWSER_U32)BookNum);
	}

	browser_mmi_tracer("BookNum=%s",(char*)title);
	
	if (0 == BookNum)
	{ 
		IsBookMarkNull = KAL_TRUE;
		if(Option_Ok==1)//add by xiaoyongq 20060116 for BUG 31551
		{
			DisplayPopup((U8*)GetString(STR_WAP_NO_BOOKMARK_ID), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
			return;
		}
		BookNum = 1;
	}
	else if( BookNum > 0)
	{
		IsBookMarkNull = KAL_FALSE;
	}

	EntryNewScreen(SCR_ID_WAP_OPTION_BOOKMARK_MENU, NULL, EntryScrWapOPtionBookMarkMenuList, NULL);	

	BrowserScreen_ID = SCR_ID_WAP_OPTION_BOOKMARK_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_OPTION_BOOKMARK_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_OPTION_BOOKMARK_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_OPTION_BOOKMARK_MENU);              
	RegisterHighlightHandler(GetBookmarkIndex);
	ShowCategory184Screen(STR_WAP_BOOKMARK_ID, IMG_WAP_MAIN_MENU_ICON, 
							STR_WAP_LINK, IMG_GLOBAL_OK,
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							BookNum, mmi_wap_bookmark_list_get_item, 
							mmi_wap_bookmark_list_get_hint , hiliteitem, guiBuffer);

	if (BookNum == 0)
	{
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	}
	else
	{
		set_left_softkey_label((UI_string_type)GetString(STR_WAP_LINK));
		show_left_softkey();
		SetLeftSoftkeyFunction(EntryScrWapBookMarkLink, KEY_EVENT_UP);
 		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
 		
	}	
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);
	//SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	EntryScrWapBookMarkMenuList
*   Input        :  void
*   Output       :  void
*   description  :	entry wapbookmark menu list screen
*   author       : 
*   date         :
==============================================================*/
void EntryScrWapBookMarkMenuList(void)
{	
	U8*  guiBuffer;
	S32  hiliteitem;
	int  BookNum = 0;
	P_CMS_BROWSER_U8 title = NULL;
	guiBuffer=NULL;
	
	hiliteitem=0;
	
	/*Get bookmark number*/
	BookNum = 0;
	title = (P_CMS_BROWSER_U8)Cms_Browser_GetBookmarkTitleById((CMS_BROWSER_U32)BookNum);

	browser_mmi_tracer("title=%s",(char*)title);
	
	while( NULL !=  title )
	{
		BookNum ++;
		title = (P_CMS_BROWSER_U8)Cms_Browser_GetBookmarkTitleById((CMS_BROWSER_U32)BookNum);
	}

	browser_mmi_tracer("BookNum=%d",(char*)BookNum);
	
	if (0 == BookNum)
	{ 
		IsBookMarkNull = KAL_TRUE;
		BookNum = 1;
	}
	else if( BookNum > 0)
	{
		IsBookMarkNull = KAL_FALSE;
	}

	EntryNewScreen(SCR_ID_WAP_BOOKMARK_MENU, NULL, EntryScrWapBookMarkMenuList, NULL);	

	BrowserScreen_ID = SCR_ID_WAP_BOOKMARK_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_BOOKMARK_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_BOOKMARK_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_BOOKMARK_MENU);              
	RegisterHighlightHandler(GetBookmarkIndex);
	ShowCategory184Screen(STR_WAP_BOOKMARK_ID, IMG_WAP_MAIN_MENU_ICON, 
							/*STR_GLOBAL_OK, IMG_GLOBAL_OK, modify by xiaoyongq for skyworth 20060911*/STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							BookNum, mmi_wap_bookmark_list_get_item, 
							mmi_wap_bookmark_list_get_hint , hiliteitem, guiBuffer);

	if (BookNum == 0)
	{
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	}
	else
	{
		//set_left_softkey_label((UI_string_type)GetString(STR_GLOBAL_OPTIONS));
		//show_left_softkey();//防止大屏幕上显示出问题
		if(IsBookMarkNull == KAL_TRUE)
		{
			SetLeftSoftkeyFunction(BrowserEmptyBookMarkOption, KEY_EVENT_UP);
		}
		else
		{
			SetLeftSoftkeyFunction(BrowserBookMarkOption, KEY_EVENT_UP);
		}
 		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	}
	
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);
	//SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_bookmark_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :	get bookmark item
*   author       : 
*   date         :
==============================================================*/
pBOOL mmi_wap_bookmark_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	
	/*显示历史记录数据　　同时将历史纪录编码转换为unicode*/	
	CMS_BROWSER_U32    string_len  = 0, i =0;
	P_CMS_BROWSER_U8   string_conv = NULL;
	P_CMS_BROWSER_U8   pTitle;
	P_CMS_BROWSER_U8 temp_16 = NULL;
	CMS_BROWSER_U32  uni16Len = 0;

	if( IsBookMarkNull == KAL_TRUE)
	{
		pfnUnicodeStrcpy((char*)str_buff, GetString(STR_WAP_NO_BOOKMARK_ID));
		*img_buff_p = NULL;
		return TRUE;
	}
	pTitle = (P_CMS_BROWSER_U8)Cms_Browser_GetBookmarkTitleById(item_index);

	 if (NULL != pTitle) 
    	 {
		uni16Len     = Cms_UTF8toUTF16Len(pTitle);
		temp_16 = (P_CMS_BROWSER_U8)cms_malloc(uni16Len+2);
		Cms_UTF8toUTF16(pTitle, cms_strlen((const char*)pTitle), uni16Len, temp_16);
		string_len = 2*Cms_UTF16Strlen(temp_16)+2;
		
		string_conv = (P_CMS_BROWSER_U8)cms_malloc(string_len);
		for(i=0;i<string_len;i+=2)
		{
			*(string_conv+i) = *(temp_16+i+1);
			*(string_conv+i+1) = *(temp_16+i);
		}
     
		pfnUnicodeStrcpy((char*)str_buff, (const char *)string_conv);
		cms_free(string_conv);
		string_conv = NULL;
		cms_free(temp_16);
		temp_16 = NULL;
    	}
	*img_buff_p = (UI_image_type)GetImage(IMG_GLOBAL_L1+item_index);

	return TRUE;	
}
/*==============================================================
*   Function Name:	mmi_wap_bookmark_list_get_hint
*   Input        :  void
*   Output       :  void
*   description  :	get bookmark hint
*   author       : 
*   date         :
==============================================================*/
S32 mmi_wap_bookmark_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	BrowserBookMarkOption
*   Input        :  void
*   Output       :  void
*   description  :	entry bookmark option menu
*   author       :  
*   date         :
==============================================================*/
void BrowserBookMarkOption(void)
{
	U8*	guiBuffer=NULL;
	U16	numItems=0;
	U16	nStrItemList[MAX_SUB_MENUS];
		
	EntryNewScreen(SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU, NULL, BrowserBookMarkOption, NULL);
 
	BrowserScreen_ID = SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU;
	
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU);
	
	numItems = GetNumOfChild (WAPBOOKMARKOPTION_MAIN_MENU);	
	GetSequenceStringIds(WAPBOOKMARKOPTION_MAIN_MENU, nStrItemList);	
	SetParentHandler(WAPBOOKMARKOPTION_MAIN_MENU);
	
	RegisterHighlightHandler (ExecuteCurrHiliteHandler);
	mmi_wap_set_wapbookmarkoption_menu_highlight_handler();
	SetMessagesCurrScrnID(SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU);
	
	ShowCategory52Screen(STR_WAP_BOOKMARKOPTION_MAIN_ID,	IMG_WAP_MAIN_MENU_ICON, 
						STR_GLOBAL_OK,		IMG_GLOBAL_OK,
						STR_GLOBAL_BACK,	IMG_GLOBAL_BACK,
						numItems, nStrItemList, (U16 *)gIndexIconsImageList, NULL,
						0, 0,	guiBuffer );
	
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}

/*==============================================================
*   Function Name:	BrowserEmptyBookMarkOption
*   Input        :  void
*   Output       :  void
*   description  :	entry bookmark option menu
*   author       :  yangjun
*   date         :	4-11-2005
==============================================================*/
void BrowserEmptyBookMarkOption(void)
{
	U8*	guiBuffer=NULL;
	U16	numItems=0;
	U16	nStrItemList[MAX_SUB_MENUS];
		
	EntryNewScreen(SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU, NULL, BrowserEmptyBookMarkOption, NULL);

	BrowserScreen_ID = SCR_ID_WAPEMPTYBOOKMARKOPTION_MAIN_MENU;
	
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAPEMPTYBOOKMARKOPTION_MAIN_MENU);
	
	numItems = GetNumOfChild (WAPEMPTYBOOKMARKOPTION_MAIN_MENU);	
	GetSequenceStringIds(WAPEMPTYBOOKMARKOPTION_MAIN_MENU, nStrItemList);	
	SetParentHandler(WAPEMPTYBOOKMARKOPTION_MAIN_MENU);
	
	RegisterHighlightHandler (ExecuteCurrHiliteHandler);
	mmi_wap_set_wapemptybookmarkoption_menu_highlight_handler();
	SetMessagesCurrScrnID(SCR_ID_WAPEMPTYBOOKMARKOPTION_MAIN_MENU);
	
	ShowCategory52Screen(SCR_ID_WAPEMPTYBOOKMARKOPTION_MAIN_MENU,	IMG_WAP_MAIN_MENU_ICON, 
						STR_GLOBAL_OK,		IMG_GLOBAL_OK,
						STR_GLOBAL_BACK,	IMG_GLOBAL_BACK,
						numItems, nStrItemList, (U16 *)gIndexIconsImageList, NULL,
						0, 0,	guiBuffer );
	
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	EntryScrWapNewLinkMenuList
*   Input        :  void
*   Output       :  void
*   description  :	newlink input menu list
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapNewLinkMenuList(void)
{
	U8* guiBuffer = NULL;
	wap_Tracer((char *)"EntryScrWapNewLinkMenuList() in");
	OptionMenu_State = WAP_OPTION_NEWLINK;
	EntryNewScreen(SCR_ID_WAP_INPUTURL_MENU, NULL, EntryScrWapNewLinkMenuList, NULL);
	
	BrowserScreen_ID = SCR_ID_WAP_INPUTURL_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_INPUTURL_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_INPUTURL_MENU);
	
	ShowCategory5Screen(STR_WAP_NEWLINK_URL_ID,NULL,/*STR_GLOBAL_OPTIONS*/STR_GLOBAL_OK,
		/*IMG_GLOBAL_OPTIONS*/IMG_GLOBAL_OK,STR_GLOBAL_BACK,IMG_GLOBAL_BACK,
		INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
		NewLink_UrlEdit,CMS_EDIT_SIZE,guiBuffer);
	SetLeftSoftkeyFunction(/*EntryScrWapDoneMenuList*/EntryScrWapDoneSet, KEY_EVENT_UP);
	SetCategory5RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	EntryScrWapHistoryMenuList
*   Input        :  void
*   Output       :  void
*   description  :	entry wap history menu list
*   author       :
*   date         :
==============================================================*/
void EntryScrWapHistoryMenuList(void)
{
	U8*  guiBuffer;
	S32  hiliteitem;
	P_CMS_BROWSER_U8 title = NULL;
	P_CMS_BROWSER_U8 url = NULL;

	guiBuffer=NULL;
	HistoryMessageNum = 0;
	hiliteitem = 0;
	/*获得网页历史记录的数目 HistoryMessageNum*/
	wap_Tracer((char *)"Enter history menu list");
	title = (P_CMS_BROWSER_U8)Cms_Browser_GetUIHistoryTitle((CMS_BROWSER_U32)HistoryMessageNum);
	url = (P_CMS_BROWSER_U8)Cms_Browser_GetUIHistoryUrl((CMS_BROWSER_U32)HistoryMessageNum);

	while( NULL != url )/*插入历史记录时仅对url判断*/
	{
		HistoryMessageNum ++;
		title = (P_CMS_BROWSER_U8)Cms_Browser_GetUIHistoryTitle((CMS_BROWSER_U32)HistoryMessageNum);
		url = (P_CMS_BROWSER_U8)Cms_Browser_GetUIHistoryUrl((CMS_BROWSER_U32)HistoryMessageNum);
	}
		
	if (0 == HistoryMessageNum)
	{
		DisplayPopup((U8*)GetString(STR_WAP_NO_PAGEHISTORY_ID), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}

	EntryNewScreen(SCR_ID_WAP_HISTORY_MENU, NULL, EntryScrWapHistoryMenuList, NULL);	
	
	BrowserScreen_ID = SCR_ID_WAP_HISTORY_MENU;

	SetMessagesCurrScrnID(SCR_ID_WAP_HISTORY_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_HISTORY_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_HISTORY_MENU);              
	RegisterHighlightHandler(GetHistoryIndex);
	ShowCategory184Screen(STR_WAP_HISTORY_ID, IMG_WAP_MAIN_MENU_ICON, 
		STR_WAP_LINK, IMG_GLOBAL_OK,
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
		HistoryMessageNum, mmi_wap_history_list_get_item, 
		mmi_wap_history_list_get_hint , hiliteitem, guiBuffer);
	
	if (HistoryMessageNum == 0)
	{
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	}
	else
	{
		SetLeftSoftkeyFunction(EntryScrWapHistoryLink, KEY_EVENT_UP);
//		SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
		set_left_softkey_label((UI_string_type)GetString(STR_WAP_LINK));
		show_left_softkey();
	}
	
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);
	
	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_history_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :	entry wap history menu item
*   author       :
*   date         :
==============================================================*/
pBOOL mmi_wap_history_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	
	/*　显示历史记录数据　　同时将历史纪录编码转换为unicode*/	
	CMS_BROWSER_U32    string_len  = 0, i =0;
	P_CMS_BROWSER_U8   string_conv = NULL;
	P_CMS_BROWSER_U8   pTitle=NULL;
	P_CMS_BROWSER_U8   pUrl=NULL;
	P_CMS_BROWSER_U8 temp_16 = NULL;
	CMS_BROWSER_U32  uni16Len = 0;

	pTitle = (P_CMS_BROWSER_U8)Cms_Browser_GetUIHistoryTitle(HistoryMessageNum - item_index -1);
	pUrl = (P_CMS_BROWSER_U8)Cms_Browser_GetUIHistoryUrl(HistoryMessageNum - item_index -1);
	
	 if ((NULL != pTitle)) 
	 {
	 	if(cms_strcmp((char*)pTitle,"*No Title*")==0)
	 	{
	 		pfnUnicodeStrcpy((char*)str_buff, GetString(STR_WAP_NO_TITLE));
	 	}
		else
		{
			uni16Len     = Cms_UTF8toUTF16Len(pTitle);
			temp_16 = (P_CMS_BROWSER_U8)cms_malloc(uni16Len+2);
			Cms_UTF8toUTF16(pTitle, cms_strlen((const char*)pTitle), uni16Len, temp_16);
			string_len = 2*Cms_UTF16Strlen(temp_16)+2;
			string_conv = (P_CMS_BROWSER_U8)cms_malloc(string_len);
			for(i=0;i<string_len;i+=2)
			{
				*(string_conv+i) = *(temp_16+i+1);
				*(string_conv+i+1) = *(temp_16+i);
			}		
			pfnUnicodeStrcpy((char*)str_buff, (const char *)string_conv);
			cms_free(string_conv);
			string_conv = NULL;
			cms_free(temp_16);
			temp_16 = NULL;
	 	}
    	}
	else if(NULL != pUrl)
	{
		pfnUnicodeStrcpy((char*)str_buff, GetString(STR_WAP_NO_TITLE));//add a string
	}
	*img_buff_p = (UI_image_type)GetImage(IMG_GLOBAL_L1+item_index);
	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_history_list_get_hint
*   Input        :  void
*   Output       :  void
*   description  :	entry wap history list hint
*   author       :
*   date         :
==============================================================*/
S32 mmi_wap_history_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	EntryScrWapHistoryLink
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :
*   date         :
==============================================================*/
void EntryScrWapHistoryLink(void)
{
	MainMenu_State = WAP_MENU_PAGEHISTORY_MENU;
	Browser_page();
}
/*==============================================================
*   Function Name:	mmi_wap_offline_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :
*   date         :
==============================================================*/
pBOOL mmi_wap_offline_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{		
	CMS_BROWSER_U32    string_len  = 0, i =0;
	P_CMS_BROWSER_U8   string_conv = NULL;
	P_CMS_BROWSER_U8   pTitle;
	P_CMS_BROWSER_U8 temp_16 = NULL;
	CMS_BROWSER_U32  uni16Len = 0;

	if(item_index >= MAXSTOREOFFLINE)
	{
		return TRUE;;
	}
	
	pTitle = (P_CMS_BROWSER_U8)Cms_Browser_GetOfflineTitleById(item_index);
	if (NULL != pTitle) 
	{
		uni16Len     = Cms_UTF8toUTF16Len(pTitle);
		temp_16 = (P_CMS_BROWSER_U8)cms_malloc(uni16Len+2);
		Cms_UTF8toUTF16(pTitle, cms_strlen((const char*)pTitle), uni16Len, temp_16);
		string_len = 2*Cms_UTF16Strlen(temp_16)+2;
		
		string_conv = (P_CMS_BROWSER_U8)cms_malloc(string_len);
		for(i=0;i<string_len;i+=2)
		{
			*(string_conv+i) = *(temp_16+i+1);
			*(string_conv+i+1) = *(temp_16+i);
		}

		pfnUnicodeStrcpy((char*)str_buff, (const char *)string_conv);
		cms_free(string_conv);
		string_conv = NULL;
		cms_free(temp_16);
		temp_16 = NULL;
	}	
	*img_buff_p = (UI_image_type)GetImage(IMG_GLOBAL_L1+item_index);
	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_pushbox_list_get_hint
*   Input        :  S32 item_index
					UI_string_type *hint_array
*   Output       :  void
*   description  :	push box message list get hint str_buf
*   author       :  
*   date         :
==============================================================*/
S32 mmi_wap_offline_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	EntryScrWapOffLineMenuList
*   Input        :  void
*   Output       :  void
*   description  :	entry wapbrowser offline menu list
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapOffLineMenuList(void)
{	
	U8*  guiBuffer = NULL;
	S32  hiliteitem = 0;
	S32	 OfflineNum = 0;
	P_CMS_BROWSER_U8 title = NULL;
	
	wap_Tracer("EntryScrWapOffLineMenuList");
	title = (P_CMS_BROWSER_U8)Cms_Browser_GetOfflineTitleById((CMS_BROWSER_U32)OfflineNum);

	while( NULL !=  title )
	{
		OfflineNum++;
		title = (P_CMS_BROWSER_U8)Cms_Browser_GetOfflineTitleById((CMS_BROWSER_U32)OfflineNum);

		if(OfflineNum >= MAXSTOREOFFLINE)
		{
			title = NULL;
			break;
		}
	}
	if (0 == OfflineNum)
	{
		DisplayPopup((U8*)GetString(STR_WAP_NO_OFFLINE_ID), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	
	EntryNewScreen(SCR_ID_WAP_OFFLINE_MENU, NULL, EntryScrWapOffLineMenuList, NULL);	

	BrowserScreen_ID = SCR_ID_WAP_OFFLINE_MENU;

	SetMessagesCurrScrnID(SCR_ID_WAP_OFFLINE_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_OFFLINE_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_OFFLINE_MENU);              
	RegisterHighlightHandler(GetOfflineSetIndex);
	ShowCategory184Screen(STR_WAP_OFFLINE_ID, IMG_WAP_MAIN_MENU_ICON, 
							STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK,
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							OfflineNum, mmi_wap_offline_list_get_item, 
							mmi_wap_offline_list_get_hint , hiliteitem, guiBuffer);

	if (OfflineNum == 0)
	{
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	}
	else
	{
		SetLeftSoftkeyFunction(BrowserOfflineOption, KEY_EVENT_UP);	
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	}

	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
	
}
/*==============================================================
*   Function Name:	main_settings_entryScr
*   Input        :  void
*   Output       :  void
*   description  :	entry wapbrowser setting menu list
*   author       :  
*   date         :
==============================================================*/
void main_settings_entryScr(void)
{
	U8* guiBuffer=NULL;
	U16 numItems=0;
	U16 nStrItemList[MAX_SUB_MENUS];
	U16 itemIcons[MAX_SUB_MENUS];
	U8* pPopUpList[MAX_SUB_MENUS];

	wap_Tracer("main_settings_entryScr");
	EntryNewScreen(SCR_ID_WAP_SETTINGS_MENU,	NULL, main_settings_entryScr, NULL);

	BrowserScreen_ID = SCR_ID_WAP_SETTINGS_MENU;

	mmi_wap_set_wapsettings_menu_highlight_handler();
	
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETTINGS_MENU);	
	numItems = GetNumOfChild(WAP_MENU_SETTINGS_MENU_ID);
	GetSequenceStringIds(WAP_MENU_SETTINGS_MENU_ID, nStrItemList);
	GetSequenceImageIds(WAP_MENU_SETTINGS_MENU_ID, itemIcons);	
	SetParentHandler(WAP_MENU_SETTINGS_MENU_ID);

	ConstructHintsList(WAP_MENU_SETTINGS_MENU_ID, pPopUpList);
	SetMessagesCurrScrnID(STR_WAP_SETTINGS_ID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);	
	
	ShowCategory52Screen(STR_WAP_SETTINGS_ID, IMG_WAP_MAIN_MENU_ICON,
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer );

	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN); 
}
/*==============================================================
*   Function Name:	mmi_wap_option_savehomepage
*   Input        :  void
*   Output       :  void
*   description  :	entry of save current page as homepage
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_option_savehomepage(void)
{
	if (MainMenu_State == 20)
	{
		SaveHomepageEvent();
	}
}
/*==============================================================
*   Function Name:	mmi_wap_option_exitbrowser
*   Input        :  void
*   Output       :  void
*   description  :	exit browser page 
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_option_exitbrowser(void)
{
	if(BrowserByHotkey==1)
	{
		wap_Tracer("BrowserByHotkey==1");
		ExitWapBrowserByEndkey();
	}	
#ifdef SUPPORT_SMSMMS_COMBINE
	else if(MMSPushByBrowser==1)
	{
		wap_Tracer("MMSPushByBrowser==1");
		if (browserflag == 1)
		{
			Cms_Browser_SavePUSH();
			Cms_Browser_FreePUSHInfo();
			Cms_Browser_SaveBrowserSetupToFile();
			Cms_SaveFile();
			Cms_Browser_ExitEvent();
			Cms_close_soc(2);
			browserflag = 0;
		}
		
		DeleteUptoScrID(SCR_ID_MMS_INBOX);
		GoBackHistory();
	}
#endif
	else
	{
		wap_Tracer("BrowserByHotkey==0");
		BackToMainMenuEvent();
	}	
}
/*==============================================================
*   Function Name:	mmi_wap_option_back
*   Input        :  void
*   Output       :  void
*   description  :	browser pre page
*   author       : 
*   date         :
==============================================================*/
void mmi_wap_option_back(void)
{
	if (MainMenu_State == 20)
	{
		OptionBackEvent();
	}		
}

void mmi_wap_option_currentURL(void)
{
	if (MainMenu_State == 20)
	{
		OptionGetCurrentURLEvent();
	}	
}

void mmi_wap_option_refresh(void)
{
	if (MainMenu_State == 20)
	{
		OptionRefreshCurrentPageEvent();
	}		
}
/*==============================================================
*   Function Name:	mmi_wap_option_savebookmark
*   Input        :  void
*   Output       :  void
*   description  :	save current page as a bookmark entry
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_option_savebookmark(void)
{
	if (MainMenu_State == 20)
	{
		SaveBookmarkEvent();
	}
}
/*==============================================================
*   Function Name:	mmi_wap_option_savecurrentpage
*   Input        :  void
*   Output       :  void
*   description  :	save current page 
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_option_savecurrentpage(void)
{
	if (MainMenu_State == 20)
	{
		SaveCurrentPageEvent();
	}
}	
/*==============================================================
*   Function Name:	mmi_wap_option_homepage
*   Input        :  void
*   Output       :  void
*   description  :	entry of homepage browser
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_option_homepage(void)
{
	EntryScrWapHomePageMenuList();
}
/*==============================================================
*   Function Name:	SaveHomepageEvent
*   Input        :  void
*   Output       :  void
*   description  :	save homepage finish
*   author       : 
*   date         :
==============================================================*/
void SaveHomepageEvent(void)
{
	CMS_BROWSER_U8 tempurl[MMS_MAX_INPUT_CENTRE_ADDR_LENGTH] = {0};
	P_CMS_BROWSER_U8 homeurl=NULL;
	CMS_BROWSER_U8 tempurllen = 0;
	CMS_BROWSER_U8 tempcount = 0;
	
	Cms_Browser_SetHomepageEvent();
	homeurl=Cms_Browser_GetCurrentURL();
	tempurllen = Cms_Browser_StrLen(homeurl);
	if(tempurllen > MMS_MAX_INPUT_CENTRE_ADDR_LENGTH)
	{
		Cms_Browser_StrNCpy(tempurl,homeurl, MMS_MAX_INPUT_CENTRE_ADDR_LENGTH);
		memset(gWapTemp.centre_addr, 0, MMS_MAX_CENTRE_ADDR_LENGTH);
		while(tempcount < MMS_MAX_INPUT_CENTRE_ADDR_LENGTH)
		{
			gWapTemp.centre_addr[tempcount*2] = tempurl[tempcount];
			tempcount++;
		}
	}
	else
	{
		Cms_Browser_StrCpy(tempurl, homeurl);
		memset(gWapTemp.centre_addr, 0, MMS_MAX_CENTRE_ADDR_LENGTH);
		while(tempcount < tempurllen)
		{
			gWapTemp.centre_addr[tempcount*2] = tempurl[tempcount];
			tempcount++;
		}
	}
			
	wap_write_setting_file_by_index(gconfig.wap_service_activeitem);
	DisplayPopup((U8*)GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
//	Cms_Browser_SetHomepageEvent();
//	DisplayPopup((U8*)GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
}
/*==============================================================
*   Function Name:	OptionGetCurrentURLEvent
*   Input        :  void
*   Output       :  void
*   description  :	Get current page URL and show URL info
*   author       : 
*   date         :
==============================================================*/
extern S8   UnicodeBuf[MAX_SHOW_STRING_BUF*12];

void OptionGetCurrentURLEvent(void)
{
	U8* guiBuffer = NULL;
	PU8 pCurrentURL=NULL;
	S32	 str_len = 0;
	int i = 0,j=0;
	U8 Current_Url[512];
	cms_memset(Current_Url, 0x0, sizeof(Current_Url));
	cms_memset(UnicodeBuf, 0x0, sizeof(UnicodeBuf));
	
	wap_Tracer((char *)"OptionGetCurrentURLEvent() in");
	pCurrentURL=(PU8)Cms_Browser_GetCurrentURL();	
	//browser_mmi_tracer("Current_Url=%s",(char*)pCurrentURL);
	if(pCurrentURL[0]!=NULL)
	{
		if(pCurrentURL[0]=='/')	i=1;
	}	
	while (pCurrentURL[i] != NULL &&  i<=254)//changed by yangjun 060714 修改获取url乱码
	{
		Current_Url[j*2] = pCurrentURL[i];
		i++;
		j++;
	}

	pfnUnicodeStrcpy((PS8)UnicodeBuf,(PS8)Current_Url);

	str_len=pfnUnicodeStrlen((PS8)UnicodeBuf);
	EntryNewScreen(SCR_ID_WAP_CURRENTURL_MENU, NULL,OptionGetCurrentURLEvent, NULL);

	BrowserScreen_ID = SCR_ID_WAP_CURRENTURL_MENU;
	SetMessagesCurrScrnID(SCR_ID_WAP_CURRENTURL_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_CURRENTURL_MENU);

	browser_mmi_tracer("len=%d",(char*)str_len);
	ShowCategory74Screen(STR_WAP_OPTION_URL_ID,IMG_WAP_MAIN_MENU_ICON,
						NULL,NULL,STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						(PU8)UnicodeBuf, str_len, guiBuffer);

	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
	SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*==============================================================
*   Function Name:	OptionRefreshCurrentPageEvent
*   Input        :  void
*   Output       :  void
*   description  :	Refresh current page
*   author       : 
*   date         :
==============================================================*/
void OptionRefreshCurrentPageEvent(void)
{
	RefreshEvent();
}
/*==============================================================
*   Function Name:	SaveBookmarkEvent
*   Input        :  void
*   Output       :  void
*   description  :	save current page as bookmark finish
*   author       :  
*   date         :
==============================================================*/
void SaveBookmarkEvent(void)
{ 
	if(Cms_Browser_BookmarkFull())
	{
		DisplayPopup((U8*)GetString(STR_WAP_BOOKMARKISFULL_ID), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	else
	{
		P_CMS_BROWSER_U8   pTitle;
		pTitle = Cms_Browser_GetCurrentTitle();
		if(pTitle==NULL)
		{
			//pTitle=cms_malloc(10);
			//s_strcpy((char*)pTitle,"*NoTitle");
			pTitle=(P_CMS_BROWSER_U8)Cms_mms_uni16_8((char*)GetString(STR_WAP_NO_TITLE));
			Cms_Browser_AddBookmark(pTitle);
			cms_free(pTitle);
		}
		else
			Cms_Browser_AddBookmark(pTitle);
		Cms_SaveBookMarkFile();//add by xiaoyongq 20060822 书签添加完成立即保存文件
		
		DisplayPopup((U8*)GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
	}	
}
/*==============================================================
*   Function Name:	SaveCurrentPageEvent
*   Input        :  void
*   Output       : void
*   description :save current page as bookmark event
*   author       :  
*   date         :
==============================================================*/
void SaveCurrentPageEvent(void)
{
	Cms_Browser_SavePageEvent();
	Cms_Browser_WriteOfflineRecord();//add by xiaoyongq 20060822 保存完成立即写文件
	
/*
	if(Cms_Browser_SavePageEvent()<MAXSTOREOFFLINE)
		DisplayPopup((U8*)GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);	
	else
		wap_Tracer((char*)"==SaveCurrentPageEvent()==");
*/		
}
//end option
/*==============================================================
                                                              Wap Browser Message Loop
===============================================================*/
/*==============================================================
*   Function Name:	Cms_Browser_PostMessage
*   Input        :  CMS_BROWSER_U32 MessageID
*   Output       :  void
*   description  :	post message to MTK task and implement asynchronous operation
*   author       :  
*   date         :
==============================================================*/
extern void SocCloseSuccessEvent(void);
extern void SocCloseFailEvent(void);
CMS_BROWSER_VOID Cms_Browser_PostMessage(CMS_BROWSER_U32 MessageID)
{
	ilm_struct *send_ilm;
	browser_mmi_tracer("Cms_Browser_PostMessage message id = %d", (char *)MessageID);
       if(cms_bPostMessageFlag==1)
	   	return;
	if(mmsflag.gsend_recv == TRUE && MessageID == CMS_MESSAGE_BROWSERNEWURI)
	{
		DevDeactivate();
		DisplayPopup((U8*)GetString(STR_WAP_WARING_NETBUSY), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	if( (MessageID != CMS_MESSAGE_BROWSERNEWURI) && (CancleDownload == 1))
	{
		wap_Tracer((char*)"==aaaa()==");
		return;
	}
#ifndef SUPPORT_EMAIL_APPLICATION
	if(MessageID == CMS_MESSAGE_BROWSERMAILADDRESS)
	{
		wap_Tracer((char*)"==CMS_MESSAGE_BROWSERMAILADDRESS==");
		MainMenu_State=11;/*20060424 xiaoyongqu add for bug35520*/
		DisplayPopup((U8*)GetString(STR_WAP_APPLICATION_NOT_SUPPORT), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
#endif
    	send_ilm = allocate_ilm(MOD_MMI);
	send_ilm->src_mod_id = MOD_MMI;
	send_ilm->dest_mod_id = MOD_CMSWAP;
	send_ilm->sap_id = 0;

	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_ParserEvent,  MSG_ID_CMS_WAP_PARSER);
	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_LayoutEvent,  MSG_ID_CMS_WAP_LAYOUT);
	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_DrawEvent,  MSG_ID_CMS_WAP_DRAW);
	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_DownloadEvent,  MSG_ID_CMS_WAP_NEWINPUTURL);
	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_UpPageEvent,  MSG_ID_CMS_WAP_PAGEUP);
	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_DownPageEvent,  MSG_ID_CMS_WAP_PAGEDOWN);
	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_EditBox,  MSG_ID_CMS_WAP_EDITBOX);
	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_SendMail,  MSG_ID_CMS_WAP_MAILADDRESS);
	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_CallRequest,  MSG_ID_CMS_WAP_CALLREQUEST);
	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_StorePhonenum,  MSG_ID_CMS_WAP_STOREPHONENUM);
	SetProtocolEventHandler((PsFuncPtr)NextLinkFocusEvent,  MSG_ID_CMS_WAP_NEXTLINKFOCUS);
	SetProtocolEventHandler((PsFuncPtr)LastLinkFocusEvent,  MSG_ID_CMS_WAP_LASTLINKFOCUS);

	SetProtocolEventHandler((PsFuncPtr)RightLinkFocusEvent,  MSG_ID_CMS_WAP_RIGHTLINKFOCUS);
	SetProtocolEventHandler((PsFuncPtr)LeftLinkFocusEvent,  MSG_ID_CMS_WAP_LEFTLINKFOCUS);

	SetProtocolEventHandler((PsFuncPtr)SocCloseSuccessEvent,  MSG_ID_CMS_WAP_SOCCLOSESUCCESS);
	SetProtocolEventHandler((PsFuncPtr)SocCloseFailEvent,  MSG_ID_CMS_WAP_SOCCLOSEFAIL);

	SetProtocolEventHandler((PsFuncPtr)Brw_Keystar_Uppage,  MSG_ID_CMS_WAP_UPPAGE);
	SetProtocolEventHandler((PsFuncPtr)Brw_Keystar_Downpage,  MSG_ID_CMS_WAP_DOWNPAGE);

	SetProtocolEventHandler((PsFuncPtr)Cms_OnTouchPanelDownEvent,  MSG_ID_CMS_WAP_TOUCHPENDOWN);
	SetProtocolEventHandler((PsFuncPtr)Cms_OnTouchPanelUPEvent,  MSG_ID_CMS_WAP_TOUCHPENUP);
	SetProtocolEventHandler((PsFuncPtr)Cms_Browser_PageRefreshEvent,  MSG_ID_CMS_WAP_PAGEREFRESH);
	//changed by yangjun 06-07-25
	//修改一键上网帐号错误的死机问题
	SetProtocolEventHandler((PsFuncPtr)OptExitBrowser,  MSG_ID_CMS_WAP_DEVDEACTIVEATE);

	switch(MessageID) 
	{
	case 1292://CMS_MESSAGE_BROWSERREFRESHPAGE:
		send_ilm->msg_id = MSG_ID_CMS_WAP_PAGEREFRESH;
		break;
		
	case 1294://CMS_MESSAGE_BROWSERPARSER:
		send_ilm->msg_id = MSG_ID_CMS_WAP_PARSER;
		break;
		
	case 1295://CMS_MESSAGE_BROWSERLAYOUT:
		send_ilm->msg_id = MSG_ID_CMS_WAP_LAYOUT;
		break;
		
	case 1296://CMS_MESSAGE_BROWSERDRAW:
		send_ilm->msg_id = MSG_ID_CMS_WAP_DRAW;
		break;
		
	case 1282://CMS_MESSAGE_BROWSERNEWURI:
		send_ilm->msg_id = MSG_ID_CMS_WAP_NEWINPUTURL;
		break;
		
	case 1287://CMS_MESSAGE_BROWSERUPPAGE:
		send_ilm->msg_id = MSG_ID_CMS_WAP_PAGEUP;
		break;
		
	case 1288://CMS_MESSAGE_BROWSERDOWNPAGE:
		send_ilm->msg_id = MSG_ID_CMS_WAP_PAGEDOWN;
		break;
		
	case 1297://CMS_MESSAGE_BROWSEREDITBOX:
		send_ilm->msg_id = MSG_ID_CMS_WAP_EDITBOX;
		Cms_Browser_GetEditContent();/*edit get last content*/
		break;

	case 1321://CMS_MESSAGE_BROWSERMAILADDRESS:
		send_ilm->msg_id = MSG_ID_CMS_WAP_MAILADDRESS;
		break;
		
	case 1322://CMS_MESSAGE_BROWSERCALLREQUEST:
		send_ilm->msg_id = MSG_ID_CMS_WAP_CALLREQUEST;
		break;
		
	case 1323://CMS_MESSAGE_BROWSERSTOREPHONENUM:
		send_ilm->msg_id = MSG_ID_CMS_WAP_STOREPHONENUM;
		break;		

	case 1325://CMS_MESSAGE_BROWSERNEXTLINKFOCUS:
		send_ilm->msg_id = MSG_ID_CMS_WAP_NEXTLINKFOCUS;
		break;

	case 1326://CMS_MESSAGE_BROWSERLASTLINKFOCUS:
		send_ilm->msg_id = MSG_ID_CMS_WAP_LASTLINKFOCUS;
		break;
	case 1327:
		send_ilm->msg_id = MSG_ID_CMS_WAP_RIGHTLINKFOCUS;
		break;
	case 1328:
		send_ilm->msg_id = MSG_ID_CMS_WAP_LEFTLINKFOCUS;
		break;
	case 1330://CMS_MESSAGE_BROWSERSOCCLOSESUCCESS
		send_ilm->msg_id = MSG_ID_CMS_WAP_SOCCLOSESUCCESS;
		break;
	case 1331://CMS_MESSAGE_BROWSERSOCCLOSEFAIL
		send_ilm->msg_id = MSG_ID_CMS_WAP_SOCCLOSEFAIL;
		break;

	case 1381://CMS_MESSAGE_BROWSERPAGEDOWN:
		send_ilm->msg_id = MSG_ID_CMS_WAP_DOWNPAGE;
		break;

	case 1382://CMS_MESSAGE_BROWSERPAGEUP:
		send_ilm->msg_id = MSG_ID_CMS_WAP_UPPAGE;
		break;	
		
	case 1383://CMS_MESSAGE_BROWSERTOUCHPENDOWN
		send_ilm->msg_id = MSG_ID_CMS_WAP_TOUCHPENDOWN;
		break;

	case 1384://CMS_MESSAGE_BROWSERTOUCHPENUP
		send_ilm->msg_id = MSG_ID_CMS_WAP_TOUCHPENUP;
		break;
		
	//changed by yangjun 06-07-25
	//修改一键上网帐号错误的死机问题
	case 1385://CMS_MESSAGE_BROWSERDEVDEACTIVEATE
		send_ilm->msg_id = MSG_ID_CMS_WAP_DEVDEACTIVEATE;
		break;
		
	default:
		return;
	}
       wap_Tracer((char*)"-------------------Cms_Browser_PostMessage boun2-------------------");
	send_ilm->peer_buff_ptr = NULL;
	send_ilm->local_para_ptr = NULL;	
	msg_send_ext_queue(send_ilm);
}
/*==============================================================
                                                              Wap Browser Touch Event
===============================================================*/
int readDataing=0;
int TouchPanelFlag=0;
unsigned	short __xPenpos,  __yPenpos ;
void SetNetSocketReadState(void)
{
	cms_wap_Tracer("SetNetSocketReadState ");	
	readDataing=1;
}

void SetNetSocketReadEndState(void)
{
	cms_wap_Tracer("SetNetSocketReadEndState  ");	
	readDataing=0;
}
#ifdef __MMI_TOUCH_SCREEN__
#include "TouchScreenGprot.h"
#include "wgui_touch_screen.h"

int GetNetSocketReadState(void)
{
	return readDataing;
}
/*==============================================================
*   Function Name:	mmi_wap_pen_down_hdlr
*   Input        :  dot postion
*   Output       :  void
*   description  :	pend down event
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_pen_down_hdlr(mmi_pen_point_struct pos)
{
	MMI_BOOL ret=MMI_FALSE;
	U16 x, y;
	U32 index;
	mmi_gui_scrollbar_pen_enum scrollbar_event; 
	mmi_gui_pen_event_param_struct scrollbar_param;		
	x = pos.x;
	y = pos.y;
	cms_wap_Tracer("mmi_wap_pen_down_hdlr ");
	if(GetNetSocketReadState()==1)
	{
		cms_wap_Tracer("read GetNetSocketReadState ");		
		return ;
	}	
	if ( PEN_CHECK_BOUND (x, y, categoryWap_vbar.x, categoryWap_vbar.y, categoryWap_vbar.width, categoryWap_vbar.height) )
	{
		if(Down_Scrollbar_OK==0)
		{
		index = categoryWap_vbar.value;
		pixtel_UI_vertical_scrollbar_translate_pen_event(&categoryWap_vbar, MMI_PEN_EVENT_DOWN, x, y, &scrollbar_event, &scrollbar_param);
		if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
		{
			if((S32) scrollbar_param._u.i > index)
			{
					Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERPAGEDOWN);
				}
				else
				{					
					Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERPAGEUP);
				}
			}
			ret = MMI_TRUE;
		}
	}
#ifdef WAP_SHOW_ACROSS_SCOLLBAR
	else if ( PEN_CHECK_BOUND (x, y, categoryWap_hbar.x, categoryWap_hbar.y, categoryWap_hbar.width, categoryWap_hbar.height) )
	{
		if(Down_Scrollbar_OK==0)
		{
		index = categoryWap_hbar.value;
		pixtel_UI_horizontal_scrollbar_translate_pen_event(&categoryWap_hbar, MMI_PEN_EVENT_DOWN, x, y, &scrollbar_event, &scrollbar_param);
		if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
		{
			if((S32) scrollbar_param._u.i > index)
			{
					Cms_Browser_PostMessage(1327);
				}
				else
				{					
					Cms_Browser_PostMessage(1328);
				}
			}
			ret = MMI_TRUE;
		}
	}
#endif
	else if(y>ORIGIN_Y && y<(Cms_GetSCREEN_H()-Cms_GetSELECTHIGHT()))
	{
		if(TouchPanelFlag==0&&Down_Scrollbar_OK==0)
		{
			__xPenpos=x;
			__yPenpos=y;
			Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERTOUCHPENDOWN);
			//Cms_OnTouchPanelEvent(CTPE_PEN_DOWN, x, y);
			TouchPanelFlag=1;
		}	
		ret = MMI_TRUE;
	}
	if (MMI_FALSE == ret)
	{
      		mmi_wgui_general_pen_down_hdlr(pos);
   	}
}

/*==============================================================
*   Function Name:	mmi_wap_pen_up_hdlr
*   Input        :   postion x.y
*   Output       :  void
*   description  :	pend up event
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_pen_up_hdlr(mmi_pen_point_struct pos)
{
	MMI_BOOL ret=MMI_FALSE;
	U16 x, y;
	mmi_gui_scrollbar_pen_enum scrollbar_event; 
	mmi_gui_pen_event_param_struct scrollbar_param;	
		
	x = pos.x;
	y = pos.y;
	cms_wap_Tracer("mmi_wap_pen_up_hdlr ");
	if(GetNetSocketReadState()==1)
	{
		cms_wap_Tracer("read GetNetSocketReadState ");	
		return ;
	}
	if ( PEN_CHECK_BOUND (x, y, categoryWap_vbar.x, categoryWap_vbar.y, categoryWap_vbar.width, categoryWap_vbar.height) )
	{
		if(Down_Scrollbar_OK==0)
		{
			pixtel_UI_vertical_scrollbar_translate_pen_event(&categoryWap_vbar, MMI_PEN_EVENT_UP, x, y, &scrollbar_event, &scrollbar_param);
		}
		ret = MMI_TRUE;
	}
#ifdef WAP_SHOW_ACROSS_SCOLLBAR
	else if ( PEN_CHECK_BOUND (x, y, categoryWap_hbar.x, categoryWap_hbar.y, categoryWap_hbar.width, categoryWap_hbar.height) )
	{
		if(Down_Scrollbar_OK==0)
		{
			pixtel_UI_horizontal_scrollbar_translate_pen_event(&categoryWap_hbar, MMI_PEN_EVENT_UP, x, y, &scrollbar_event, &scrollbar_param);
		}
		ret = MMI_TRUE;
	}
#endif
	else if(y>ORIGIN_Y && y<(Cms_GetSCREEN_H()-Cms_GetSELECTHIGHT()))
	{
		if(TouchPanelFlag==1&&Down_Scrollbar_OK==0)
		{
			__xPenpos=x;
			__yPenpos=y;
			Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERTOUCHPENUP);
			//Cms_OnTouchPanelEvent(CTPE_PEN_UP, x, y);
			TouchPanelFlag=0;
		}	
		ret = MMI_TRUE;
	}
	if (MMI_FALSE == ret)
    	{
      		mmi_wgui_general_pen_up_hdlr(pos);
    	}
}
/*==============================================================
*   Function Name:	mmi_wap_pen_repeat_hdlr
*   Input        :   postion x.y
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
	MMI_BOOL ret=MMI_FALSE;
	U16 x, y;
	U32 index;
	mmi_gui_scrollbar_pen_enum scrollbar_event; 
	mmi_gui_pen_event_param_struct scrollbar_param;	
		
	x = pos.x;
	y = pos.y;
	cms_wap_Tracer("mmi_wap_pen_repeat_hdlr ");
	if(GetNetSocketReadState()==1)
	{	
		cms_wap_Tracer("read GetNetSocketReadState ");	
		return ;
	}	

	if ( PEN_CHECK_BOUND (x, y, categoryWap_vbar.x, categoryWap_vbar.y, categoryWap_vbar.width, categoryWap_vbar.height) )
	{
		index = categoryWap_vbar.value;
		if(Down_Scrollbar_OK==0)
		{
			pixtel_UI_vertical_scrollbar_translate_pen_event(&categoryWap_vbar, MMI_PEN_EVENT_REPEAT, x, y, &scrollbar_event, &scrollbar_param);
			if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
			{
				if((S32) scrollbar_param._u.i > index)
				{
					Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDOWNPAGE/*CMS_MESSAGE_BROWSERPAGEDOWN*/);
				}
				else
				{
					Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERUPPAGE/*CMS_MESSAGE_BROWSERPAGEUP*/);
				}
			}
		}
		ret = MMI_TRUE;
	}
	if (MMI_FALSE == ret)
    {
      mmi_wgui_general_pen_repeat_hdlr(pos);
    }
}

/*==============================================================
*   Function Name:	mmi_wap_pen_move_hdlr
*   Input        :   postion x.y
*   Output       :  void
*   description  :pend move	
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_pen_move_hdlr(mmi_pen_point_struct pos)
{
	MMI_BOOL ret=MMI_FALSE;
	U16 x, y;
	U32 index;
	mmi_gui_scrollbar_pen_enum scrollbar_event; 
	mmi_gui_pen_event_param_struct scrollbar_param;	
		
	x = pos.x;
	y = pos.y;
	if(GetNetSocketReadState()==1)
	{
		cms_wap_Tracer("read GetNetSocketReadState ");	
		return ;
	}	

	if ( PEN_CHECK_BOUND (x, y, categoryWap_vbar.x, categoryWap_vbar.y, categoryWap_vbar.width, categoryWap_vbar.height) )
	{
		index = categoryWap_vbar.value;
		if(Down_Scrollbar_OK==0)
		{
		pixtel_UI_vertical_scrollbar_translate_pen_event(&categoryWap_vbar, MMI_PEN_EVENT_MOVE, x, y, &scrollbar_event, &scrollbar_param);
		if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
		{
			if((S32) scrollbar_param._u.i > index)
			{
					Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDOWNPAGE/*CMS_MESSAGE_BROWSERPAGEDOWN*/);
				}
				else
				{
					Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERUPPAGE/*CMS_MESSAGE_BROWSERPAGEUP*/);
				}
			}
		}
		ret = MMI_TRUE;
	}
#ifdef WAP_SHOW_ACROSS_SCOLLBAR
	else if ( PEN_CHECK_BOUND (x, y, categoryWap_hbar.x, categoryWap_hbar.y, categoryWap_hbar.width, categoryWap_hbar.height) )
	{
		if(Down_Scrollbar_OK==0)
		{
		index = categoryWap_hbar.value;
		pixtel_UI_horizontal_scrollbar_translate_pen_event(&categoryWap_hbar, MMI_PEN_EVENT_DOWN, x, y, &scrollbar_event, &scrollbar_param);
		if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
		{
			if((S32) scrollbar_param._u.i > index)
			{
					Cms_Browser_PostMessage(1327);
				}
				else
				{					
					Cms_Browser_PostMessage(1328);
				}
			}
			ret = MMI_TRUE;
		}
	}
#endif
    else
    {
        pixtel_UI_vertical_scrollbar_translate_pen_event(&categoryWap_vbar, MMI_PEN_EVENT_MOVE, x, y, &scrollbar_event, &scrollbar_param);
    }
	if (MMI_FALSE == ret)
    {
      mmi_wgui_general_pen_move_hdlr(pos);
       }
}
#endif
/*==============================================================
*   Function Name:	show_wap_vbar
*   Input        :  void
*   Output       :  void
*   description  :浏览器滚动条
*   author       :  
*   date         :
==============================================================*/
void show_wap_vbar(void)
{
#if(UI_DOUBLE_BUFFER_SUPPORT)
	pixtel_UI_lock_double_buffer();
#endif
	pixtel_UI_show_vertical_scrollbar( &categoryWap_vbar );
#ifdef WAP_SHOW_ACROSS_SCOLLBAR
	pixtel_UI_show_horizontal_scrollbar( &categoryWap_hbar );
#endif
#if(UI_DOUBLE_BUFFER_SUPPORT)
	pixtel_UI_unlock_double_buffer();
//xiaoyongq 20061214	Cms_Browser_RefreshScreen();
#endif
}
/*==============================================================
*   Function Name:	ExitBrowser_page
*   Input        :  void
*   Output       :  void
*   description  :	exit Browser_page screen browser wap page
*   author       :  
*   date         :
==============================================================*/
void ExitBrowser_page(void)
{
	wap_Tracer((char*)"==ExitBrowser_page()==");
	SuspendFlag = 1;
}
/*==============================================================
*   Function Name:	Browser_page
*   Input        :  void
*   Output       :  void
*   description  :	entry Browser_page screen browser wap page
*   author       :  
*   date         :
==============================================================*/
void Browser_page(void)
{
	U8* guiBuffer=NULL;
	SuspendFlag = 0;

	wap_Tracer((char*)"==Browser_page()==");
/*20060913 xiaoyong modify*/
	EntryNewScreen(SCR_ID_WAP_PAGEBROWSER_MENU,	ExitBrowser_page, Browser_page, NULL);

	BrowserScreen_ID = SCR_ID_WAP_PAGEBROWSER_MENU;
	
	SetParentHandler(NULL);

	SetMessagesCurrScrnID(SCR_ID_WAP_PAGEBROWSER_MENU);	

	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_PAGEBROWSER_MENU);

	gdi_layer_lock_frame_buffer();

	switch(MainMenu_State) 
	{
		case WAP_MENU_HOMEPAGE_MENU:
			ShowCategory221Screen(STR_WAP_PAGELINK_ID, IMG_WAPDOWNLOADING_MAIN_MENU_ICON,
									NULL, NULL,
									STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
									GDI_COLOR_WHITE, NULL);
			
			Browser_Enter();
			Cms_Browser_GotoHomepageEvent(FALSE);
			break;

		case WAP_MENU_BOOKMARK_MENU:
			ShowCategory221Screen(STR_WAP_PAGELINK_ID, IMG_WAPDOWNLOADING_MAIN_MENU_ICON,
									NULL, NULL,
									STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
									GDI_COLOR_WHITE, NULL);			
			Browser_Enter();
			
			Cms_Browser_LinkBookmark( (CMS_BROWSER_U32)(BookmarkIndex) );
			break;

		case WAP_MENU_NEWLINK_MENU:
			ShowCategory221Screen(STR_WAP_PAGELINK_ID, IMG_WAPDOWNLOADING_MAIN_MENU_ICON,
									NULL, NULL,
									STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
									GDI_COLOR_WHITE, NULL);			
			Browser_Enter();		
			Cms_Browser_NewInputURIEvent();//modify by xiaoyongq 20060417 
			break;

		case WAP_MENU_PAGEHISTORY_MENU:
			ShowCategory221Screen(STR_WAP_PAGELINK_ID, IMG_WAPDOWNLOADING_MAIN_MENU_ICON,
									NULL, NULL,
									STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
									GDI_COLOR_WHITE, NULL);
			
			Browser_Enter();
			Clear_FileToSave();
			Clear_GoPrevFlag();//xiaoyongq 20060410 add for bug history record
			Cms_Browser_UILinkPageHistory( (CMS_BROWSER_U32)(HistoryMessageNum - HistoryIndex - 1) );
			break;
			
		case WAP_MENU_PUSHBOX_MENU:
			ShowCategory221Screen(STR_WAP_PAGELINK_ID, IMG_WAPDOWNLOADING_MAIN_MENU_ICON,
									NULL, NULL,
									STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
									GDI_COLOR_WHITE, NULL);
			
			Browser_Enter();
			BorwserFormPush=1;
			Cms_Browser_DownloadPUSHContent( (CMS_BROWSER_U32)(PushboxIndex) );
			break;

		case WAP_MENU_OFFLINE_MENU:
			ShowCategory221Screen(STR_WAP_PAGELINK_ID, IMG_WAPDOWNLOADING_MAIN_MENU_ICON,
									NULL, NULL,
									STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
									GDI_COLOR_WHITE, NULL);
			Browser_Enter();
			cms_Brw_Offline_Browser( (CMS_BROWSER_U32)(OfflineSetIndex) );
			break;
			
		case MAIN_MENU_STATE_AUTHENTICATION://for Authentication
			ShowCategory221Screen(STR_WAP_PAGELINK_ID, IMG_WAPDOWNLOADING_MAIN_MENU_ICON,
									NULL, NULL,
									STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
									GDI_COLOR_WHITE, NULL);
			Browser_Enter();
			break;
		case 11://for call request
			ShowCategory221Screen(STR_WAP_PAGELINK_ID, IMG_WAPDOWNLOADING_MAIN_MENU_ICON,
									NULL, NULL,
									STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
									GDI_COLOR_WHITE, NULL);
			
			Browser_Enter();			
			Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDRAW);
			break;

		case 12://for exitoption
			ShowCategory221Screen(STR_WAP_PAGELINK_ID, IMG_WAPDOWNLOADING_MAIN_MENU_ICON,
									NULL, NULL,
									STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
									GDI_COLOR_WHITE, NULL);
			Browser_Enter();
			break;
		default:
			{
				ShowCategory221Screen(STR_WAP_PAGELINK_ID, IMG_WAP_MAIN_MENU_ICON,
									NULL, NULL,
									STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
									GDI_COLOR_WHITE, NULL);						
					if (MainMenu_State == 18)
					{
						Browser_Enter();
						MainMenu_State = 18;
						Cms_Browser_LinkPageMessage();
						if (ResourceValue_State == CMS_STR_RESOURCE_RETRY)
						{
							wap_Tracer("CMS_STR_RESOURCE_RETRY");
							DisplayConfirm(STR_GLOBAL_OK, IMG_GLOBAL_OK,
								STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
								(UI_string_type)GetString(STR_WAP_PAGELINKFAILED_ID),
								IMG_GLOBAL_QUESTION, WARNING_TONE);
							SetLeftSoftkeyFunction(Cms_Browser_PageReLink, KEY_EVENT_UP);
							SetRightSoftkeyFunction(Cms_Browser_PageLinkReturn, KEY_EVENT_UP);
							SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
						}
						else
						{
							ResourceValue_State = -1;
						}
						
					}
					else if(MainMenu_State == 19)
					{
						Browser_Enter();
					}
					else
					{
						Browser_Enter();
						Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDRAW);	
					}
			}
			break;
	}

#ifdef __MMI_TOUCH_SCREEN__
		mmi_wgui_register_pen_down_handler(mmi_wap_pen_down_hdlr);
		mmi_wgui_register_pen_up_handler(mmi_wap_pen_up_hdlr);
		mmi_wgui_register_pen_move_handler(mmi_wap_pen_move_hdlr);
		mmi_wgui_register_pen_repeat_handler(mmi_wap_pen_repeat_hdlr);
#endif	

#ifdef NO_SHOW_STATEBAR
	pixtel_UI_create_vertical_scrollbar(&categoryWap_vbar,
			UI_device_width-Cms_GetSCROLLBAR_W(),Cms_GetORIGIN_Y(),Cms_GetSCROLLBAR_W(),MMI_content_height-1);

#ifdef WAP_SHOW_ACROSS_SCOLLBAR
	/*Cms_Horizontal_GetSCROLLBAR_W() 是模仿Cms_GetSCROLLBAR_W(),但是它所返回的值是后者返回值得一半,目的在于使横向滚动条宽度变窄*/
	pixtel_UI_create_horizontal_scrollbar(&categoryWap_hbar,
			0,MMI_title_y+MMI_title_height+MMI_content_height-Cms_Horizontal_GetSCROLLBAR_W(), UI_device_width-Cms_GetSCROLLBAR_W(),Cms_Horizontal_GetSCROLLBAR_W());
#endif
#else
	pixtel_UI_create_vertical_scrollbar(&categoryWap_vbar,
			UI_device_width-Cms_GetSCROLLBAR_W(),Cms_GetORIGIN_Y(),Cms_GetSCROLLBAR_W(),MMI_content_height-MMI_button_bar_height-1);

#ifdef WAP_SHOW_ACROSS_SCOLLBAR
	/*Cms_Horizontal_GetSCROLLBAR_W() 是模仿Cms_GetSCROLLBAR_W(),但是它所返回的值是后者返回值得一半,目的在于使横向滚动条宽度变窄*/
	pixtel_UI_create_horizontal_scrollbar(&categoryWap_hbar,
			0,MMI_title_y+MMI_title_height+MMI_content_height-MMI_button_bar_height-Cms_Horizontal_GetSCROLLBAR_W(),UI_device_width-Cms_GetSCROLLBAR_W(),Cms_Horizontal_GetSCROLLBAR_W());
#endif
#endif

	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);	
	RedrawCategoryFunction = RedrawCategoryWMLScreen;
	RedrawCategoryWMLScreen();
	return ;
}
/*==============================================================
*   Function Name:	Browser_Enter
*   Input        :  void
*   Output       :  void
*   description  :	ready to browser_enter set some key function
*   author       :  
*   date         :
==============================================================*/
void Browser_Enter(void)
{ 
	wap_Tracer("Browser_Enter in");
	Option_Ok=0;
	Down_Scrollbar_OK=1;
	BackToIdle=0;
	Cms_Browser_StopBrowserTimer();
	ClearAllMarqueeMovie();//add by xiaoyongqu 060809
	Cms_Brw_Clear_Cancel_OK();
	ChangeRightSoftkey(STR_GLOBAL_CANCEL, IMG_GLOBAL_BACK);

	SetRightSoftkeyFunction(Cms_Brw_Cancle, KEY_EVENT_UP);

	ChangeLeftSoftkey(NULL, NULL);
	SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);		
	SetKeyHandler(NULL, KEY_SEND, KEY_EVENT_DOWN);
	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);		
	SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
	/*注册侧键*/
	SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_DOWN);
	SetKeyHandler(NULL, KEY_STAR, KEY_EVENT_DOWN);	
	SetKeyHandler(NULL, KEY_POUND, KEY_EVENT_DOWN);	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
	MainMenu_State = 19; 
}
void Cms_Brw_Cancle(void)
{
	Cms_Brw_CancelPageDownload();
#ifdef SUPPORT_SMSMMS_COMBINE	
	if((1 == Cms_IsFirstURL()) && MMSPushByBrowser)
	{
		/*第一次进入时取消返回彩信收件箱列表*/
		Cms_StopMusic();
		ClearAllMarqueeMovie();
		//GoBackHistory();/*20060322 zhou.chaozhu for bug34069 */
	}	
#endif	
}
/*==============================================================
*   Function Name:	RedrawCategoryWMLScreen
*   Input        :  void
*   Output       :  void
*   description  :	redraw wml screen
*   author       :  
*   date         :
==============================================================*/
void RedrawCategoryWMLScreen(void)
{
	show_softkey_background();
	show_left_softkey();
	show_right_softkey();

#if (UI_DOUBLE_BUFFER_SUPPORT)	
	pixtel_UI_unlock_double_buffer();
	pixtel_UI_BLT_double_buffer(0,MMI_title_y+MMI_title_height, UI_device_width-1, UI_device_height-1-MMI_button_bar_height);
#endif 
}
//End wap Browser
/*================================================================
	                                          Settings menu function interface			
================================================================*/
/*==============================================================
*   Function Name:	mmi_wap_settings_service_list
*   Input        :  void
*   Output       :  void
*   description  :	entry of service list
*   author       : 
*   date         :
==============================================================*/
void mmi_wap_settings_service_list(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapServiceIdListMenu, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapServiceIdListMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*==============================================================
*   Function Name:	mmi_wap_settings_clearhistory
*   Input        :  void
*   Output       :  void
*   description  :	entry of clear pagehistory
*   author       : 
*   date         :
==============================================================*/
void mmi_wap_settings_clearhistory(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapClearPageHistory, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapClearPageHistory, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_settings_clearcache
*   Input        :  void
*   Output       :  void
*   description  :	entry of clear cache
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_settings_clearcache(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapClearCache, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapClearCache, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*==============================================================
*   Function Name:	mmi_wap_settings_clearcookies
*   Input        :  void
*   Output       :  void
*   description  :	entry of clear cache
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_settings_clearcookie(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapCleareCookieMenu, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapCleareCookieMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*==============================================================
*   Function Name:	mmi_wap_settings_pushmessage
*   Input        :  void
*   Output       :  void
*   description  :	entry of push setting
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_settings_pushmessage(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapSetPushMessageMenuList, KEY_EVENT_UP);
//	SetKeyHandler(EntryScrWapSetPushMessageMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
void mmi_wap_setting_service_list_hint(U16 index)
{	
	cms_memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));	
	wap_read_setting_file_by_index(gconfig.wap_service_activeitem);
	if(pfnUnicodeStrlen((S8*)gWapTemp.service_id)>0)
	{
		pfnUnicodeStrcpy((S8*)hintData[index],(S8*)gWapTemp.service_id);		
	}
	else
	{
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_GLOBAL_EMPTY));
	}
	return;
}
void mmi_wap_setting_push_hint(U16 index)
{	
	cms_memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));	
	if (Cms_Browser_GetPushMessageSetting() == 1)
	{	
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_WAP_SETTINGS_PUSHMESSAGEON_ID));		
	}
	else
	{
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_WAP_SETTINGS_PUSHMESSAGEOFF_ID));
	}
	return;
}

void mmi_wap_setting_image_hint(U16 index)
{
	cms_memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));	
	if (Cms_Browser_GetImageSetting() == 1)
	{	
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_WAP_SETTINGS_PUSHMESSAGEON_ID));		
	}
	else
	{
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_WAP_SETTINGS_PUSHMESSAGEOFF_ID));
	}
	return;

}

void mmi_wap_setting_music_hint(U16 index)
{
	cms_memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));	
	if (Cms_Browser_GetMusicSetting() == 1)
	{	
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_WAP_SETTINGS_PUSHMESSAGEON_ID));		
	}
	else
	{
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_WAP_SETTINGS_PUSHMESSAGEOFF_ID));
	}
	return;
}

void mmi_wap_setting_cerfiticates_hint(U16 index)
{
	cms_memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));	
	if (Cms_Brower_GetSecuritySetting() == 1)
	{	
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_WAP_SETTINGS_PUSHMESSAGEON_ID));		
	}
	else
	{
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_WAP_SETTINGS_PUSHMESSAGEOFF_ID));
	}
	return;
}

void mmi_wap_setting_protocal_hint(U16 index)
{
	cms_memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));	
	if (CmsGetNetType() == CMS_WAP_CONNECT_HTTP)
	{	
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_WAP_SETTINGS_SETCONNECTMODE_HTTP_ID));		
	}
	else
	{
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_WAP_SETTINGS_SETCONNECTMODE_WAP_ID));
	}
	return;
}
/*==============================================================
*   Function Name:	mmi_wap_settings_homepage
*   Input        :  void
*   Output       :  void
*   description  :	entry of homepage setting
*   author       : 
*   date         :
==============================================================*/
void mmi_wap_settings_homepage(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapSettingHomepage , KEY_EVENT_UP);
	//sSetKeyHandler(EntryScrWapSettingHomepage, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_settings_gateway	
*   Input        :  void
*   Output       :  void
*   description  : entry of gateway setting
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_settings_gateway(void)
{ 
	Cms_Browser_GetGateWaySetup((P_CMS_BROWSER_U8)Setting_Gateway, (P_CMS_BROWSER_U8)Setting_Port);
 	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapGateWaySettingsMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapGateWaySettingsMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}
/*==============================================================
*   Function Name:	mmi_wap_settings_image
*   Input        :  void
*   Output       :  void
*   description  :	entry of image setting
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_settings_image(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapSetImageMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapSetImageMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_settings_bgmusic
*   Input        :  void
*   Output       :  void
*   description  :	entry of background music setting
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_settings_bgmusic()
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapSetBGMusicMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapSetBGMusicMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_settings_netacc
*   Input        :  void
*   Output       :  void
*   description  :	entry of netacc setting menu list
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_settings_netacc(void)
{ 
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapSetNetAccMenuListPrep, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapSetNetAccMenuListPrep, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); 
}
/*==============================================================
*   Function Name:	mmi_wap_settings_certificates
*   Input        :  void
*   Output       :  void
*   description  :	entry of certificates setting menu list
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_settings_certificates(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapSetSecurityMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapSetSecurityMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); 
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);	
}


void mmi_wap_settings_protocal(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapSetConnectModeMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapSetConnectModeMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); 
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);	
}
/*==============================================================
*   Function Name:	mmi_wap_settings_service_list_set
*   Input        :  void
*   Output       :  void
*   description  :	entry of certificates setting menu list
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_settings_service_list_set(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(wap_set_curr_file_to_setting, KEY_EVENT_UP);
	//SetKeyHandler(wap_set_curr_file_to_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); 
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);	
}

/*==============================================================
*   Function Name:	mmi_wap_settings_certificates
*   Input        :  void
*   Output       :  void
*   description  :	entry of certificates setting menu list
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_settings_service_list_edit(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapServiceEditMenuPre, KEY_EVENT_UP);
//	SetKeyHandler(EntryScrWapServiceEditMenuPre, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); 
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);	
}
/*==============================================================
*   Function Name:	WapClearCookie
*   Input        :  void
*   Output       :  void
*   description  :	entry of clear cookie setting menu list
*   author       :  
*   date         :
==============================================================*/
void WapClearCookie(void)
{  
	GoBackHistory();
	//FS_Delete(L"C:\\wap\\CmsCookie.cnf");	
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapCookiefilename(wap_filename);
	Cms_Adp_fdelete((const unsigned short *) wap_filename);	
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);	
	
}
/*==============================================================
*   Function Name:	EntryScrWapCleareCookieMenu
*   Input        :  void
*   Output       :  void
*   description  :	entry of Clear Cookies setting menu list
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapCleareCookieMenu(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_WAP_SETTINGS_CLEARCOOKIE_ID),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(WapClearCookie, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*================================================================
							Settings menu function event			
================================================================*/
/*==============================================================
*   Function Name:	
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapServiceEditMenuPre(void)
{
	wap_read_setting_file_by_index(ghiliindex);
	DataAccountReadyCheck(EntryScrWapServiceEditMenu);
}

/*==============================================================
*   Function Name:	
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void wap_setting_save_and_exit()
{
	wap_write_setting_file_by_index(ghiliindex);
	ExitDisplayPopupConfirm();
	if(IsScreenPresent(SCR_ID_WAP_SETTING_SERVICE_ID_MENU))
		GoBackToHistory(SCR_ID_WAP_SETTING_SERVICE_ID_MENU);
	else
	{
		GoBackHistory();
	}
	if(gconfig.wap_service_activeitem==ghiliindex)
	{
		wap_set_curr_file_to_setting();
	}
	else
	{
		DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	}
}
/*==============================================================
*   Function Name:	
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void wap_setting_no_save_and_exit()
{
 	if(IsScreenPresent(SCR_ID_WAP_SETTING_SERVICE_ID_MENU))
		GoBackToHistory(SCR_ID_WAP_SETTING_SERVICE_ID_MENU);
	else
	{
		GoBackHistory();
	}
}
/*==============================================================
*   Function Name:	
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void wap_settings_confirm(void)
{
	if((gWapTemp.port[0] == NULL)||(gWapTemp.gateway[0] == NULL) )
	{
		DisplayPopup((U8*)GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		gWapTemp.gprs_mode = Old_gprs_mode;
		return ;
	}
	if(mmi_wap_judge_wap_setting() == 0)
	{
		DisplayPopup((U8*)GetString(STR_WAP_SETTING_ERROR), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, 
					STR_GLOBAL_NO, IMG_GLOBAL_NO,
					(UI_string_type)GetString(STR_GLOBAL_SAVE), IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(wap_setting_save_and_exit, KEY_EVENT_UP);
	SetRightSoftkeyFunction(wap_setting_no_save_and_exit, KEY_EVENT_UP);

}

/*==============================================================
*   Function Name:	wap_setting_edit
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void wap_setting_edit(void)
{
	SetInputMethodAndDoneCaptionIcon(IMG_WAP_MAIN_MENU_ICON);
	ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
	SetLeftSoftkeyFunction (EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}
/*==============================================================
*   Function Name:	mmi_wap_judge_wap_setting
*   Input        :  void
*   Output       :  void
*   description  :judge the wap setting	
*   author       :  
*   date         :
==============================================================*/
int mmi_wap_judge_wap_setting(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	U8 tempgateport[65] = {0};
	sockaddr_struct sock_addr_temp;

	wap_Tracer("mmi_wap_judge_wap_setting in");
	cms_memset(&sock_addr_temp,0x00,sizeof(sockaddr_struct));
	while (gWapTemp.gateway[i*2] != NULL)
	{
		if (gWapTemp.gateway[i*2] != '.')
		{
			tempgateport[j] = gWapTemp.gateway[i*2];
			j++;	
		}
		else if (k<=2)
		{
			sock_addr_temp.addr[k] = Cms_Browser_atoi(tempgateport);
			cms_memset(tempgateport, 0 , 10);
			j = 0;
			k++;
		}
		i++;
	}
		
	sock_addr_temp.addr[k] = Cms_Browser_atoi(tempgateport);
	cms_memset(tempgateport, 0 , 10);		
		
	i = 0;
	while (gWapTemp.port[i*2] != NULL)
	{
		tempgateport[i] = gWapTemp.port[i*2]; 
		i ++;
	}
	sock_addr_temp.port = Cms_Browser_atoi(tempgateport);
	adp_mmi_tracer((char *)"sock_addr_temp.addr[0]...................= %d", (char *)sock_addr_temp.addr[0]);
	adp_mmi_tracer((char *)"sock_addr_temp.addr[1]...................= %d", (char *)sock_addr_temp.addr[1]);
	adp_mmi_tracer((char *)"sock_addr_temp.addr[2]...................= %d", (char *)sock_addr_temp.addr[2]);
	adp_mmi_tracer((char *)"sock_addr_temp.addr[3]...................= %d", (char *)sock_addr_temp.addr[3]);
	adp_mmi_tracer((char *)"sock_addr_temp.port...................= %d", (char *)sock_addr_temp.port);
	
	if( sock_addr_temp.port ==0 || sock_addr_temp.addr[0] ==0 ||(sock_addr_temp.addr[1] ==0 && sock_addr_temp.addr[2] ==0 && sock_addr_temp.addr[3] ==0))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
/*==============================================================
*   Function Name:	
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_set_network_highlight(S32 item_index)
{
	if(item_index==9)
	{
		ChangeLeftSoftkey( STR_GLOBAL_SELECT, IMG_GLOBAL_OK);
		SetCategory57LeftSoftkeyFunction(EntryScrWapSetNetAccMenuListPrep);
	}
}

/*==============================================================
*   Function Name:	
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_setting_inline_struct()
{

	SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString (STR_MMS_WAP_MODIFY_SERVICE_ID));
	SetInlineItemActivation(&wgui_inline_items[1],KEY_LSK,KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&wgui_inline_items[1],STR_MMS_WAP_MODIFY_SERVICE_ID, 
									IMG_WAP_MAIN_MENU_ICON, gWapTemp.service_id, 
									MMS_MAX_INPUT_SERVICE_ID_LENGTH, INPUT_TYPE_ALPHANUMERIC_LOWERCASE);
	SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], wap_setting_edit);
 	RightJustifyInlineItem(&wgui_inline_items[1]);	
	
	SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString (STR_WAP_SETTINGS_HOMEPAGE_ID));
	SetInlineItemActivation(&wgui_inline_items[3],KEY_LSK,KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&wgui_inline_items[3],STR_WAP_SETTINGS_HOMEPAGE_ID, 
									IMG_WAP_MAIN_MENU_ICON, gWapTemp.centre_addr, 
									MMS_MAX_INPUT_CENTRE_ADDR_LENGTH, INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
	SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], wap_setting_edit);
 	RightJustifyInlineItem(&wgui_inline_items[3]);
	
	SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_WAP_SETTINGS_GATEWAY_ID));
	SetInlineItemActivation(&(wgui_inline_items[5]),KEY_LSK, KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&(wgui_inline_items[5]), STR_WAP_SETTINGS_GATEWAY_ID, NULL,
								gWapTemp.gateway,MMS_MAX_INPUT_GATEWAY_LENGTH,INPUT_TYPE_NUMERIC_CHANGEABLE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
	SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[5]), wap_setting_edit);
	RightJustifyInlineItem(&wgui_inline_items[5]);
	
	SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString(STR_WAP_SETTINGS_PORT_ID));					
	SetInlineItemActivation(&(wgui_inline_items[7]),KEY_LSK, KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&(wgui_inline_items[7]), STR_WAP_SETTINGS_PORT_ID, NULL, 
								gWapTemp.port,MMS_MAX_INPUT_PORT_LENGTH,INPUT_TYPE_NUMERIC);
	SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[7]), wap_setting_edit);
	RightJustifyInlineItem(&wgui_inline_items[7]);
	

	SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString (STR_WAP_SETTINGS_SETNETACC_ID));
	if(gWapTemp.gprs_mode<GSM_NET_ACCOUNT)
	{
		SetInlineItemDisplayOnly(&wgui_inline_items[9], (U8*)g_DataAccount[gWapTemp.gprs_mode].DataAccountName);
	}
	else
	{
		SetInlineItemDisplayOnly(&wgui_inline_items[9], (U8*)g_GPRS_DataAccount[gWapTemp.gprs_mode-GSM_NET_ACCOUNT].DataAccountName);
	}
	RegisterHighlightHandler(mmi_wap_set_network_highlight);

}
/*==============================================================
*   Function Name:	
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void ExitWapServiceEditMenu(void)
{
	history	h;
	U16 inputBufferSize;
	CloseCategory57Screen();
	h.scrnID = SCR_ID_WAP_SETTING_SERVICE_EDIT_MENU;
	h.entryFuncPtr = EntryScrWapServiceEditMenu;
	GetCategoryHistory(h.guiBuffer);
	inputBufferSize =(U16)GetCategory57DataSize( ); 
	GetCategory57Data ((U8*) h.inputBuffer );  
	AddNHistory(h, inputBufferSize);           	
}
/*==============================================================
*   Function Name:	
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapServiceEditMenu(void)
{
	U8* inputBuffer;
	U16 inputBufferSize;
	U8* guiBuffer=NULL;
	U16 itemicon[MAX_SUB_MENUS];
	U16 screenId = SCR_ID_WAP_SETTING_SERVICE_EDIT_MENU;
	
	EntryNewScreen(screenId, ExitWapServiceEditMenu ,
					NULL, NULL);
	
	itemicon[0] = IMG_GLOBAL_L1;
	itemicon[1] = 0;
	itemicon[2] = IMG_GLOBAL_L2;
	itemicon[3] = 0;
	itemicon[4] = IMG_GLOBAL_L3;
	itemicon[5] = 0;
	itemicon[6] = IMG_GLOBAL_L4;
	itemicon[7] = 0;
	itemicon[8] = IMG_GLOBAL_L5;
	itemicon[9] = 0;

	InitializeCategory57Screen();
	mmi_wap_setting_inline_struct();

	guiBuffer = GetCurrGuiBuffer (screenId);	
	inputBuffer = GetCurrNInputBuffer(SCR_ID_WAP_SETTING_SERVICE_EDIT_MENU, &inputBufferSize );
	if(inputBuffer != NULL)		
		SetCategory57Data(wgui_inline_items, 10, inputBuffer);

	ShowCategory57Screen(STR_MMS_WAP_EDIT_SETTING, IMG_WAP_MAIN_MENU_ICON, 
							STR_GLOBAL_OK, NULL,
							STR_GLOBAL_BACK, NULL,
							10,itemicon, wgui_inline_items, 0, guiBuffer);	


	SetCategory57RightSoftkeyFunctions(wap_settings_confirm,GoBackHistory);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);

}

/*==============================================================
*   Function Name:	
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapServiceOption(void)
{
	U8* guiBuffer=NULL;
	U16 numItems=0;
	U16 nStrItemList[MAX_SUB_MENUS];
	U16 itemIcons[MAX_SUB_MENUS];
	U16 screenId=SCR_ID_WAP_SETTING_SERVICE_OPTION_MENU;
	U8** pPopUpList=NULL;
	
	EntryNewScreen(screenId, NULL,
					EntryScrWapServiceOption, NULL);

	mmi_wap_set_service_list_option_menu_highlight_handler	();

	guiBuffer = GetCurrGuiBuffer(screenId);		
	SetParentHandler(WAP_SETTINGS_MENU_SERVICE_OPTIONS_MENU_ID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	numItems = GetNumOfChild(WAP_SETTINGS_MENU_SERVICE_OPTIONS_MENU_ID);
	GetSequenceStringIds(WAP_SETTINGS_MENU_SERVICE_OPTIONS_MENU_ID, nStrItemList);
	GetSequenceImageIds(WAP_SETTINGS_MENU_SERVICE_OPTIONS_MENU_ID, itemIcons);
	
	ShowCategory52Screen(STR_GLOBAL_OPTIONS, IMG_WAP_MAIN_MENU_ICON, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,guiBuffer );
	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/*==============================================================
*   Function Name:	
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapServiceIdListMenu(void)
{
	int i = 0;
	U8 temp[130] = {0};	
	U8* guiBuffer = NULL;
	S32 hiliteitem = 0;
	U16 setnumber=0;
	U16 screenId = SCR_ID_WAP_SETTING_SERVICE_ID_MENU;
	PU8	pservicelist[SERVICE_LIST_ITEM]={0};

	memset(servicelist,0,sizeof(servicelist));
	memset(NewLink_UrlEdit, 0, sizeof(NewLink_UrlEdit));
	Cms_Browser_GetHomepageSetup((P_CMS_BROWSER_U8)temp);
	if (temp[0] != NULL)
	{
		while (temp[i] != NULL)
		{
			NewLink_UrlEdit[i*2] = temp[i];
			i++;
		}
	}
	
	for(;setnumber<SERVICE_LIST_ITEM;setnumber++)
	{
		wap_read_setting_file_by_index(setnumber);
		if(pfnUnicodeStrlen((S8*)gWapTemp.service_id)==0)
		{
			pfnUnicodeStrcpy((PS8)servicelist[setnumber],(PS8)L"<");
			pfnUnicodeStrcat((PS8)servicelist[setnumber],(S8 *)GetString(STR_GLOBAL_EMPTY));
			pfnUnicodeStrcat((PS8)servicelist[setnumber],(PS8)L">");
		}
		else
		{
			pfnUnicodeStrcpy((S8*)servicelist[setnumber], (S8*)gWapTemp.service_id);
		}
		pservicelist[setnumber]=(PU8)servicelist[setnumber];
	
	}

	EntryNewScreen(screenId, NULL,
					EntryScrWapServiceIdListMenu, NULL);
	
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
	RegisterHighlightHandler(mmi_get_index);

	if (guiBuffer)
	{
		hiliteitem = ghiliindex;
	}
	else
	{
		hiliteitem=gconfig.wap_service_activeitem;
	}
	
	ShowCategory36Screen( STR_MMS_WAP_EDIT_SETTING, IMG_WAP_MAIN_MENU_ICON,
						  	STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE,
						  	STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  	SERVICE_LIST_ITEM, (U8**)pservicelist, (U16)hiliteitem, guiBuffer);
	
	SetLeftSoftkeyFunction(EntryScrWapServiceOption, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}

/*==============================================================
*   Function Name:	EntryScrWapClearPageHistory
*   Input        :  void
*   Output       :  void
*   description  :	clear page history implement
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapClearPageHistory(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_WAP_SETTINGS_CLEARPAGEHISTOY_ID),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(WapClearPageHistory, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	WapClearPageHistory
*   Input        :  void
*   Output       :  void
*   description  :	clear page history
*   author       :  
*   date         :
==============================================================*/
void WapClearPageHistory(void)
{ 
	Cms_Browser_UIClearPageHistory(); 	
	GoBackHistory();
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
}
/*================================================================
	Set Clear cache menu function interface				
================================================================*/
/*==============================================================
*   Function Name:	EntryScrWapClearCache
*   Input        :  void
*   Output       :  void
*   description  :	clear cache implement
*   author       : 
*   date         :
==============================================================*/
void EntryScrWapClearCache(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_WAP_SETTINGS_CLEARCACHE_ID),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(WapClearCache, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	EntryScrWapClearCache
*   Input        :  void
*   Output       :  void
*   description  :	clear cache page
*   author       : 
*   date         :
==============================================================*/
void WapClearCache(void)
{ 
	Cms_Browser_ClearCache();	 
	GoBackHistory();
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);	
}
/*================================================================
	Set Homepage menu function interface				
================================================================*/
/*==============================================================
*   Function Name:	EntryScrWapSettingHomepage
*   Input        :  void
*   Output       :  void
*   description  :	edit homepage control
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSettingHomepage(void)
{ 
	U8 temp[130] = {0};
	int i = 0;
	cms_memset(NewLink_UrlEdit, 0x0, sizeof(NewLink_UrlEdit));
	Cms_Browser_GetHomepageSetup((P_CMS_BROWSER_U8)temp);
	if (temp[0] == NULL)
	{
		pfnUnicodeStrcpy((S8 *)NewLink_UrlEdit, (const S8 *)(L"http://"));
	}
	else
	{
		while (temp[i] != NULL)
		{
			NewLink_UrlEdit[i*2] = temp[i];
			i++;
		}
	} 
	EntryScrWapSetHomePageMenuList();
}
/*==============================================================
*   Function Name:	EntryScrWapSetHomePageMenuList
*   Input        :  void
*   Output       :  void
*   description  :	set homepage menu list
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSetHomePageMenuList(void)
{
	U8* guiBuffer = NULL;

	wap_Tracer((char *)"EntryScrWapSetHomePageMenuList() in");
	OptionMenu_State = WAP_OPTION_HOMEPAGE;
	EntryNewScreen(SCR_ID_WAP_SETHOMEPAGE_MENU, NULL, EntryScrWapSetHomePageMenuList, NULL);
	
	BrowserScreen_ID = SCR_ID_WAP_SETHOMEPAGE_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_SETHOMEPAGE_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETHOMEPAGE_MENU);
	
	ShowCategory5Screen(STR_WAP_SETTINGS_SETHOMEPAGE_ID,NULL,/*STR_GLOBAL_OPTIONS*/STR_GLOBAL_OK,
		/*IMG_GLOBAL_OPTIONS*/IMG_GLOBAL_OK,STR_GLOBAL_BACK,IMG_GLOBAL_BACK,
		INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
		NewLink_UrlEdit,CMS_EDIT_SIZE,guiBuffer);
	SetLeftSoftkeyFunction(/*EntryScrWapDoneMenuList*/EntryScrWapDoneSet, KEY_EVENT_UP);
	SetCategory5RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	EntryScrWapDoneMenuList
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapDoneMenuList(void)
{
	U8*  guiBuffer =NULL;
	S32  hiliteitem = 0;
	EntryNewScreen(SCR_ID_WAPDONE_MAIN_MENU, NULL, EntryScrWapDoneMenuList, NULL);	
	BrowserScreen_ID = SCR_ID_WAPDONE_MAIN_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAPDONE_MAIN_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAPDONE_MAIN_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAPDONE_MAIN_MENU);              
	RegisterHighlightHandler(GetWapDoneIndex);
	ShowCategory184Screen(STR_GLOBAL_DONE, IMG_WAP_MAIN_MENU_ICON, 
		STR_GLOBAL_OK, IMG_GLOBAL_OK,
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
		1, mmi_wap_done_list_get_item, 
		mmi_wap_done_list_get_hint , hiliteitem, guiBuffer);

	SetLeftSoftkeyFunction(EntryScrWapDoneSet, KEY_EVENT_UP);

	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (EntryScrWapNotDoneSet, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_done_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
pBOOL mmi_wap_done_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	
	pfnUnicodeStrcpy((S8*)str_buff, GetString(STR_GLOBAL_DONE+item_index));
	*img_buff_p = (UI_image_type)GetImage(IMG_GLOBAL_L1+item_index);
	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_done_list_get_hint
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
S32 mmi_wap_done_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
							Setting Gateway menu interface function
==============================================================*/
/*==============================================================
*   Function Name:	EntryScrWapGateWaySettingsMenuList
*   Input        :  void
*   Output       :  void
*   description  :	entry wap gateway settingmenu
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapGateWaySettingsMenuList(void)
{
	U16 WapGateWaySettingsIcons[4] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0 };
	U8* guiBuffer;

	U8* inputBuffer;
	U16 inputBufferSize;

	EntryNewScreen(SCR_ID_WAP_SETGATEWAY_MENU,ExitEntryScrWapGateWaySettings,NULL,  NULL);

	BrowserScreen_ID = SCR_ID_WAP_SETGATEWAY_MENU;
	
	InitializeCategory57Screen();
	WapGateWaySettingsFillInlineStruct();


	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETGATEWAY_MENU);
	inputBuffer = GetCurrNInputBuffer(SCR_ID_WAP_SETGATEWAY_MENU, &inputBufferSize );
	if(inputBuffer != NULL)		
		SetCategory57Data(wgui_inline_items, 4, inputBuffer);

	ShowCategory57Screen(STR_WAP_SETTINGS_SETGATEWAY_ID,IMG_WAP_MAIN_MENU_ICON,
						STR_GLOBAL_OK,IMG_GLOBAL_OK,
						STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						4,
						WapGateWaySettingsIcons,wgui_inline_items,1,guiBuffer);

	SetCategory57RightSoftkeyFunctions(WapGateWaySettingsConfirm, GoBackHistory);
	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	WapGateWaySettingsConfirm
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void WapGateWaySettingsConfirm(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_GLOBAL_OK),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(WapGateWaySettingsFinish, KEY_EVENT_UP);
	SetRightSoftkeyFunction(WapGateWaySettingsNoChanged, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	WapGateWaySettingsFinish
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void WapGateWaySettingsFinish(void)
{ 
	if ( (Setting_Port[0] == NULL) || (Setting_Gateway[0] == NULL) )
	{
		DisplayPopup((U8*)GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
	}
	else
	{
		Cms_Browser_SetupPort((unsigned char *)Setting_Port);
		Cms_Browser_SetupGateWay((unsigned char *)Setting_Gateway);
		DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
		
		wap_net_data_init();

		if( sock_addr.port ==0 || sock_addr.addr[0] ==0 ||(sock_addr.addr[1] ==0 && sock_addr.addr[2] ==0 && sock_addr.addr[3] ==0))
		{
			GoBackHistory();
			/*如设置错误就恢复初始设置*/
			Cms_Browser_SetupGateWay((unsigned char *)WAP_CMCC_GATEWAY_ADDRESS_DEFAULT);		
			wap_net_data_init();
			DisplayPopup((U8*)GetString(STR_WAP_GATEWAY_ERROR_ID), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
			return ;
		}
	} 
	Cms_Browser_SaveBrowserSetupToFile();
	Cms_SaveSetupFile();
	
	GoBackToHistory(SCR_ID_WAP_SETTINGS_MENU);
}

/*==============================================================
 					 description  :	gateway port setting control
==============================================================*/
/*==============================================================
*   Function Name:	WapGateWaySettingsFillInlineStruct
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void WapGateWaySettingsFillInlineStruct(void)
{
	SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_WAP_SETTINGS_GATEWAY_ID));

	SetInlineItemActivation(&(wgui_inline_items[1]),KEY_LSK, KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&(wgui_inline_items[1]), STR_WAP_SETTINGS_GATEWAY_ID, NULL, Setting_Gateway,32,
		INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
	SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[1]), WapGateWaySettingsEdit);
	RightJustifyInlineItem(&wgui_inline_items[1]);
	
	SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_WAP_SETTINGS_PORT_ID));
					
	SetInlineItemActivation(&(wgui_inline_items[3]),KEY_LSK, KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&(wgui_inline_items[3]), STR_WAP_SETTINGS_PORT_ID, NULL, Setting_Port,5,
		INPUT_TYPE_NUMERIC);
	SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[3]), WapGateWaySettingsEdit);
	RightJustifyInlineItem(&wgui_inline_items[3]);
}
/*==============================================================
*   Function Name:	WapGateWaySettingsNoChanged
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void WapGateWaySettingsNoChanged(void)
{
	GoBackToHistory(SCR_ID_WAP_SETTINGS_MENU);
}
/*==============================================================
*   Function Name:	WapGateWaySettingsEdit
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void WapGateWaySettingsEdit(void)
{
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(WapGateWaySettingsEditOption, KEY_EVENT_UP);
}
/*==============================================================
*   Function Name:	WapGateWaySettingsEditOption
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void WapGateWaySettingsEditOption(void)
{ 
	OptionMenu_State = WAP_OPTION_GATEWAY;
	ConfirmInlineFullScreenEdit(); 
}
/*==============================================================
*   description  :	wapbrowser edit done set
==============================================================*/
/*==============================================================
*   Function Name:	EntryScrWapDoneSet
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapDoneSet(void)
{
	if (WapDoneIndex == 0)
	{
		switch(OptionMenu_State)
		{
		case WAP_OPTION_BOOKMARKRENAME:
			RenameSelectBookMark();
			break;
			
		case WAP_OPTION_NEWLINK:
			NewLinkBrowser();
			break;
			
		case WAP_OPTION_BOOKMARKTITLEADD:
			break;
			
		case WAP_OPTION_BOOKMARKURLADD:
			break;
			
		case WAP_OPTION_HOMEPAGE:
			WapHomePageSettingsFinish();
			break;
			
		case WAP_OPTION_GATEWAY:
			ConfirmInlineFullScreenEdit();
			break;
			
		case WAP_OPTION_PORT:
			break;
			
		default:
			break;
		}	
	}
}
/*==============================================================
				  description  :	rename select bookmark implement
==============================================================*/
/*==============================================================
*   Function Name:	RenameSelectBookMark
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void RenameSelectBookMark(void)
{ 
	int i =0;
	U8 temp_16[130]={0};
	P_CMS_BROWSER_U8 temp_8 = NULL;

	if (InputContent_Edit[0] == NULL)
	{
		GoBackToHistory(SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU);
		DisplayPopup((U8*)GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);	
		return;
	}
	while (InputContent_Edit[i] != NULL)
	{
		temp_16[i] = InputContent_Edit[i+1];
		temp_16[i+1] = InputContent_Edit[i];
		i = i+2;
	}
	temp_8 = cms_malloc(65*3);
	memset(temp_8, 0, 65*3);
	Cms_Browser_Uni16_8(temp_16,temp_8);
	wap_Tracer("RenameSelectBookMark");
	Cms_Browser_RenameBookmarkTitle(BookmarkIndex, temp_8);

	cms_free(temp_8);
	temp_8 = NULL;
	GoBackToHistory(SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU); 
}

/*==============================================================
						description  :	browser newlink url page
==============================================================*/
/*==============================================================
*   Function Name:	NewLinkBrowser
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void NewLinkBrowser(void)
{ 
	int InputRight;
	int i = 0;
	int j;
	U8 url[65] = {0};
	U8 temp[136] = {0};
	if (NewLink_UrlEdit[0] == NULL)
	{
		DisplayPopup((U8*)GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	while ((NULL != NewLink_UrlEdit[i])&& i<130)
	{
		j = i/2;
		url[j] = NewLink_UrlEdit[i];
		i = i +2;
	}
	if(1 == CmsIsImgStackDL()) //add by xiaoyongq for bug31000
		CmsAbortDownload();
	ClearAllMarqueeMovie();
	/*free net struct*/
 	initURL();
	Cms_Browser_SetBackFalse();
	if(!(MMS_strstr((char*)url,"http://" )||MMS_strstr((char*)url,"Http://")||MMS_strstr((char*)url,"https://")))/*20060105 cocoma modify for BUG 30821*/
	{
		cms_strcpy((char*)temp,"http://");
		cms_strcat((char*)temp,(char*)url);
		InputRight = Cms_Browser_AddInputHistoryEvent((unsigned char *)temp); 
	}
	else
	{
		InputRight = Cms_Browser_AddInputHistoryEvent((unsigned char *)url); 
	}
	MainMenu_State = WAP_MENU_NEWLINK_MENU;	
	
	if(Option_Ok==1) 
		GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);	
	else
		Browser_page();
}
/*==============================================================
*   Function Name:	WapHomePageSettingsFinish
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void WapHomePageSettingsFinish(void)
{ 
	int i = 0;
	int j;
	U8 url[65] = {0};
	U8 Tempurl[128] = {0};
	
	while ((NULL != NewLink_UrlEdit[i])&& i<130)
	{
		j = i/2;
		url[j] = NewLink_UrlEdit[i];
		i = i +2;
	}

	if(!MMS_strstr((char*)url,"http://"))
	{
		cms_strcpy((char*)Tempurl,"http://");
		cms_strcat((char*)Tempurl,(char*)url);		
		Cms_Browser_SetupHomePage((unsigned char *)Tempurl); 
	}
	else
	{
		Cms_Browser_SetupHomePage((unsigned char *)url); 
	}	

	Cms_Browser_SaveBrowserSetupToFile();
	Cms_SaveSetupFile();
	
	GoBackToHistory(SCR_ID_WAP_SETTINGS_MENU);
}
/*==============================================================
					description  :	wapbrowser edit not done set
==============================================================*/
/*==============================================================
*   Function Name:	EntryScrWapNotDoneSet
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapNotDoneSet(void)
{
	wap_Tracer("EntryScrWapNotDoneSet");
	switch(OptionMenu_State)
	{
	case WAP_OPTION_BOOKMARKRENAME:
		GoBackHistory();
		break;
		
	case WAP_OPTION_NEWLINK:
		GoBackHistory();
		break;
		
	case WAP_OPTION_BOOKMARKTITLEADD:
		break;
		
	case WAP_OPTION_BOOKMARKURLADD:
		break;
		
	case WAP_OPTION_HOMEPAGE:
		GoBackHistory();
		break;
		
	case WAP_OPTION_GATEWAY:
		CancelInlineFullScreenEdit();
		break;
		
	case WAP_OPTION_PORT:
		break;
		
	default:
		break;
	}	
}
/*================================================================
					Set gateway music menu function interface				
================================================================*/
/*****************************************************************************
*  ExitEntryScrWapGateWaySettings
*   退出并进入Inline编辑菜单
*****************************************************************************/
void ExitEntryScrWapGateWaySettings(void)
{
	history	h;
	U16 inputBufferSize;
	CloseCategory57Screen();
	h.scrnID = SCR_ID_WAP_SETGATEWAY_MENU;
	h.entryFuncPtr = EntryScrWapGateWaySettingsMenuList;
	GetCategoryHistory(h.guiBuffer);
	inputBufferSize =(U16)GetCategory57DataSize( ); 
	GetCategory57Data ((U8*) h.inputBuffer );  
	AddNHistory(h, inputBufferSize);           	
}
/*================================================================
					Set Image music menu function interface				
================================================================*/
/*==============================================================
*   Function Name:	EntryScrWapSetImageMenuList
*   Input        :  void
*   Output       :  void
*   description  :	entry of wap image setting menu list
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSetImageMenuList(void)
{ 
	U8*  guiBuffer=NULL;
	S32  hiliteitem;	

	
	if ( Cms_Browser_GetImgSetup() )
	{
		hiliteitem = 0;
	}
	else
	{
		hiliteitem = 1;
	}
	
	EntryNewScreen(SCR_ID_WAP_SETIMAGE_MENU, NULL, EntryScrWapSetImageMenuList, NULL);
	
	BrowserScreen_ID = SCR_ID_WAP_SETIMAGE_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_SETIMAGE_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_SETIMAGE_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETIMAGE_MENU);              
	RegisterHighlightHandler(GetImageSetIndex);
	ShowCategory184Screen(STR_WAP_SETTINGS_IMAGES_ID, IMG_WAP_MAIN_MENU_ICON, 
		STR_GLOBAL_OK, IMG_GLOBAL_OK,
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
		2, mmi_wap_setimage_list_get_item, 
		mmi_wap_setimage_list_get_hint , hiliteitem, guiBuffer);

	SetLeftSoftkeyFunction(EntryScrWapImageSet, KEY_EVENT_UP);

	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
 
}
/*==============================================================
*   Function Name:	mmi_wap_setimage_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
pBOOL mmi_wap_setimage_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	 
	pfnUnicodeStrcpy((S8*)str_buff, GetString(STR_WAP_SETTINGS_IMAGEON_ID+item_index));
	
	if( (Cms_Browser_GetImgSetup() && (item_index == 0)) || ((!Cms_Browser_GetImgSetup()) && (item_index == 1)) )
	{
		*img_buff_p = (UI_image_type)GetImage(IMG_WAP_MAIN_MENU_ICON);
	}
	else
	{
		*img_buff_p = NULL;
	}	 
	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_setimage_list_get_hint
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
S32 mmi_wap_setimage_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	EntryScrWapImageSet
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapImageSet(void)
{ 
	if(ImageSetIndex == 0)
	{
		Cms_Browser_SetupImgOn();
	}
	else
	{
		Cms_Browser_SetupImgOff();
	} 
	Cms_Browser_SaveBrowserSetupToFile();
	Cms_SaveSetupFile();
	
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
	return;
}
/*================================================================
	Set Background music menu function interface				
================================================================*/
/*==============================================================
*   Function Name:	EntryScrWapSetBGMusicMenuList
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSetBGMusicMenuList(void)
{
	U8*  guiBuffer=NULL;
	S32  hiliteitem;	
	
	if ( Cms_Browser_GetMusicSetting() )
	{
		hiliteitem = 0;
	}
	else
	{
		hiliteitem = 1;
	}
	
	EntryNewScreen(SCR_ID_WAP_SETBGMUSIC_MENU, NULL, EntryScrWapSetBGMusicMenuList, NULL);
	
	BrowserScreen_ID = SCR_ID_WAP_SETBGMUSIC_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_SETBGMUSIC_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_SETBGMUSIC_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETBGMUSIC_MENU);              
	RegisterHighlightHandler(GetBGMusicSetIndex);
	ShowCategory184Screen(STR_WAP_SETTINGS_BGMUSIC_ID, IMG_WAP_MAIN_MENU_ICON, 
		STR_GLOBAL_OK, IMG_GLOBAL_OK,
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
		2, mmi_wap_setmusic_list_get_item, 
		mmi_wap_setmusic_list_get_hint , hiliteitem, guiBuffer);

	SetLeftSoftkeyFunction(EntryScrWapBGMusicSet, KEY_EVENT_UP);

	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_setmusic_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
pBOOL mmi_wap_setmusic_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	 
	pfnUnicodeStrcpy((S8*)str_buff, GetString(STR_WAP_SETTINGS_BGMUSICON_ID+item_index));
	
	if( (Cms_Browser_GetMusicSetting() && (item_index == 0)) || ((!Cms_Browser_GetMusicSetting()) && (item_index == 1)) )
	{
		*img_buff_p = (UI_image_type)GetImage(IMG_WAP_MAIN_MENU_ICON);
	}
	else
	{
		*img_buff_p = NULL;
	}	 
	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_setmusic_list_get_hint
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
S32 mmi_wap_setmusic_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	EntryScrWapBGMusicSet
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapBGMusicSet(void)
{
	if(BGMusicSetIndex == 0)
	{
		Cms_Browser_SetupMusicOn();
	}
	else
	{
		Cms_Browser_SetupMusicOff();
	} 

	Cms_Browser_SaveBrowserSetupToFile();
	Cms_SaveSetupFile();
	
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
	return;
}
/*================================================================
							PushMessage menu function interface				
================================================================*/
/*==============================================================
*   Function Name:	mmi_wap_setpushmessage_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
pBOOL mmi_wap_setpushmessage_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	 
	pfnUnicodeStrcpy((S8*)str_buff, GetString(STR_WAP_SETTINGS_PUSHMESSAGEON_ID+item_index));
	
	if( (Cms_Browser_GetPushMessageSetting() && (item_index == 0)) || ((!Cms_Browser_GetPushMessageSetting()) && (item_index == 1)) )
	{
		*img_buff_p = (UI_image_type)GetImage(IMG_WAP_MAIN_MENU_ICON);
	}
	else
	{
		*img_buff_p = NULL;
	}	 
	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_setpushmessage_list_get_hint
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
S32 mmi_wap_setpushmessage_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	EntryScrWapPushMessageSet
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapPushMessageSet(void)
{
	if(PushMessageSetIndex == 0)
	{
		Cms_Browser_SetupPushMessageOn();
	}
	else
	{
		Cms_Browser_SetupPushMessageOff();
	} 
	Cms_Browser_SaveBrowserSetupToFile();
	Cms_SaveSetupFile();
	
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
	return;
}
/*==============================================================
*   Function Name:	EntryScrWapSetPushMessageMenuList
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSetPushMessageMenuList(void)
{
	U8*  guiBuffer=NULL;
	S32  hiliteitem;		
	
	
	if ( Cms_Browser_GetPushMessageSetting() )
	{
		hiliteitem = 0;
	}
	else
	{
		hiliteitem = 1;
	}
	
	EntryNewScreen(SCR_ID_WAP_SETPUSHMESSAGE_MENU, NULL, EntryScrWapSetPushMessageMenuList, NULL);
	
	BrowserScreen_ID = SCR_ID_WAP_SETPUSHMESSAGE_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_SETPUSHMESSAGE_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_SETPUSHMESSAGE_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETPUSHMESSAGE_MENU);              
	RegisterHighlightHandler(GetPushMessageSetIndex);
	ShowCategory184Screen(STR_WAP_SETTINGS_PUSHMESSAGE_ID, IMG_WAP_MAIN_MENU_ICON, 
		STR_GLOBAL_OK, IMG_GLOBAL_OK,
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
		2, mmi_wap_setpushmessage_list_get_item, 
		mmi_wap_setpushmessage_list_get_hint , hiliteitem, guiBuffer);

	SetLeftSoftkeyFunction(EntryScrWapPushMessageSet, KEY_EVENT_UP);

	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
//End Push message function
/*================================================================
							SetNet menu function interface				
================================================================*/
/*==============================================================
*   Function Name:	EntryScrWapSetNetAccMenuListPrep
*   Input        :  void
*   Output       :  void
*   description  :	浏览器连接设置准备(读账号资料)
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSetNetAccMenuListPrep(void)
{
	EntryScrWapSetNetAccMenuList();
}
/*==============================================================
*   Function Name:	EntryScrWapSetNetAccMenuList
*   Input        :  void
*   Output       :  void
*   description  :	entry wap set net acc menu list
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSetNetAccMenuList(void)
{
	U8* guiBuffer=NULL;
	U16 numItems=0;
	U16 nStrItemList[MAX_SUB_MENUS];
	U16 itemIcons[MAX_SUB_MENUS];
	U8** pPopUpList=NULL;
	
	if (gWapTemp.gprs_mode == -1)
	{
		gWapTemp.gprs_mode = DEFAULTNETACCID;
	}
	
	EntryNewScreen(SCR_ID_WAP_SETNETACC_MENU,NULL, 
					EntryScrWapSetNetAccMenuList, NULL);
	
	BrowserScreen_ID = SCR_ID_WAP_SETNETACC_MENU;

	mmi_wap_set_wapsetnetacc_menu_highlight_handler();
	
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETNETACC_MENU);	
	SetParentHandler(WAP_SETTINGS_MENU_SETNETACC_MENU_ID);
	numItems = GetNumOfChild(WAP_SETTINGS_MENU_SETNETACC_MENU_ID);
	GetSequenceStringIds(WAP_SETTINGS_MENU_SETNETACC_MENU_ID, nStrItemList);
	GetSequenceImageIds(WAP_SETTINGS_MENU_SETNETACC_MENU_ID, itemIcons);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	ShowCategory52Screen(STR_WAP_SETTINGS_SETNETACC_ID, IMG_WAP_MAIN_MENU_ICON,
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer );

	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}

/*==============================================================
*   Function Name:	mmi_wap_setnet_gsm
*   Input        :  void
*   Output       :  void
*   description  :	Set Gsm net account entry
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_setnet_gsm(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapSetGsmAccMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapSetGsmAccMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_setnet_gprs
*   Input        :  void
*   Output       :  void
*   description  :	Set Gprs net account entry
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_setnet_gprs(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapSetGprsAccMenuList, KEY_EVENT_UP);
	//SetKeyHandler(EntryScrWapSetGprsAccMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	EntryScrWapSetGsmAccMenuList
*   Input        :  void
*   Output       :  void
*   description  :	entry gsm account menu list
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSetGsmAccMenuList(void)
{
	U8*  guiBuffer;
	S32  hiliteitem;
	guiBuffer=NULL;
	
	if (gWapTemp.gprs_mode<GSM_NET_ACCOUNT)
	{
		hiliteitem = gWapTemp.gprs_mode;
	}
	else
	{
		hiliteitem=0;
	}	
	EntryNewScreen(SCR_ID_WAP_SETGSMACC_MENU, NULL, EntryScrWapSetGsmAccMenuList, NULL);	

	BrowserScreen_ID = SCR_ID_WAP_SETGSMACC_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_SETGSMACC_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_SETGSMACC_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETGSMACC_MENU);              
	RegisterHighlightHandler(GetGsmAccIndex);
	ShowCategory184Screen(STR_WAP_SETTINGS_SETGSMNETACC_ID, IMG_WAP_MAIN_MENU_ICON, 
		STR_GLOBAL_OK, IMG_GLOBAL_OK,
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
		GSM_NET_ACCOUNT, mmi_wap_gsmacc_list_get_item, 
		mmi_wap_gsmacc_list_get_hint , hiliteitem, guiBuffer);

	SetLeftSoftkeyFunction(EntryScrWapGsmAccSet, KEY_EVENT_UP);

	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);
	
	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_gsmacc_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
pBOOL mmi_wap_gsmacc_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	
	pfnUnicodeStrcpy((S8*)str_buff, (S8*)g_DataAccount[item_index].DataAccountName);
	if (gWapTemp.gprs_mode<GSM_NET_ACCOUNT)
	{
		if (item_index == gWapTemp.gprs_mode)
		{
			*img_buff_p = (UI_image_type)GetImage(IMG_WAP_MAIN_MENU_ICON);
		}
		else
		{
			*img_buff_p = NULL;
		}
	}
	else
	{
		*img_buff_p = NULL;
	}
	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_gsmacc_list_get_hint
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
S32 mmi_wap_gsmacc_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	EntryScrWapGsmAccSet
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapGsmAccSet(void)
{
	Old_gprs_mode = gWapTemp.gprs_mode;
	gWapTemp.gprs_mode = GsmAccIndex;
	wap_settings_confirm();
	
	return;
}
/*==============================================================
*   Function Name:	EntryScrWapSetGprsAccMenuList
*   Input        :  void
*   Output       :  void
*   description  :	entry wap set gprs acc menu list
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSetGprsAccMenuList(void)
{
	U8*  guiBuffer;
	S32  hiliteitem;
	guiBuffer=NULL;
	
	if (gWapTemp.gprs_mode>=GSM_NET_ACCOUNT)
	{
		hiliteitem = gWapTemp.gprs_mode - GSM_NET_ACCOUNT;
	}
	else
	{
		hiliteitem=0;
	}

	EntryNewScreen(SCR_ID_WAP_SETGPRSACC_MENU, NULL, EntryScrWapSetGprsAccMenuList, NULL);	

	BrowserScreen_ID = SCR_ID_WAP_SETGPRSACC_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_SETGPRSACC_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_SETGPRSACC_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETGPRSACC_MENU);              
	RegisterHighlightHandler(GetGprsAccIndex);
	ShowCategory184Screen(STR_WAP_SETTINGS_SETGPRSNETACC_ID, IMG_WAP_MAIN_MENU_ICON, 
		STR_GLOBAL_OK, IMG_GLOBAL_OK,
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
		GPRS_NET_ACCOUNT, mmi_wap_gprsacc_list_get_item, 
		mmi_wap_gprsacc_list_get_hint , hiliteitem, guiBuffer);

	SetLeftSoftkeyFunction(EntryScrWapGprsAccSet, KEY_EVENT_UP);

	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);
	
	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_gprsacc_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
pBOOL mmi_wap_gprsacc_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	
	pfnUnicodeStrcpy((S8*)str_buff, (S8*)g_GPRS_DataAccount[item_index].DataAccountName);
	if (gWapTemp.gprs_mode>=GSM_NET_ACCOUNT)
	{
		if (item_index == (gWapTemp.gprs_mode-GSM_NET_ACCOUNT))
		{
			*img_buff_p = (UI_image_type)GetImage(IMG_WAP_MAIN_MENU_ICON);
		}
		else
		{
			*img_buff_p = NULL;
		}
	}
	else
	{
		*img_buff_p = NULL;
	}

	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_gprsacc_list_get_hint
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
S32 mmi_wap_gprsacc_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	EntryScrWapGprsAccSet
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapGprsAccSet(void)
{
	Old_gprs_mode = gWapTemp.gprs_mode;	
	gWapTemp.gprs_mode = GprsAccIndex+GSM_NET_ACCOUNT;
	wap_settings_confirm();
	return;
}
/*================================================================
	Security menu function interface				
================================================================*/
/*==============================================================
*   Function Name:	EntryScrWapSetBGMusicMenuList
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSetSecurityMenuList(void)
{
	U8*  guiBuffer=NULL;
	S32  hiliteitem;
	
	
	if ( Cms_Brower_GetSecuritySetting() )
	{
		hiliteitem = 0;
	}
	else
	{
		hiliteitem = 1;
	}
	
	EntryNewScreen(SCR_ID_WAP_SETPSECURITY_MENU, NULL, EntryScrWapSetSecurityMenuList, NULL);
	
	BrowserScreen_ID = SCR_ID_WAP_SETPSECURITY_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_SETPSECURITY_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_SETPSECURITY_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETPSECURITY_MENU);              
	RegisterHighlightHandler(GetWapSecurityIndex);
	ShowCategory184Screen(STR_WAP_SETTINGS_SETCERTIFICATES_ID, IMG_WAP_MAIN_MENU_ICON, 
		STR_GLOBAL_OK, IMG_GLOBAL_OK,
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
		2, mmi_wap_setsecurity_list_get_item, 
		mmi_wap_setsecurity_list_get_hint , hiliteitem, guiBuffer);

	SetLeftSoftkeyFunction(EntryScrWapSecuritySet, KEY_EVENT_UP);

	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_setmusic_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
pBOOL mmi_wap_setsecurity_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	 
	pfnUnicodeStrcpy((S8*)str_buff, GetString(STR_WAP_SETTINGS_SETCERTIFICATESON_ID+item_index));
	
	if( (Cms_Brower_GetSecuritySetting() && (item_index == 0)) || ((!Cms_Brower_GetSecuritySetting()) && (item_index == 1)) )
	{
		*img_buff_p = (UI_image_type)GetImage(IMG_WAP_MAIN_MENU_ICON);
	}
	else
	{
		*img_buff_p = NULL;
	}	 
	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_setmusic_list_get_hint
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
S32 mmi_wap_setsecurity_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	EntryScrWapSecuritySet
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSecuritySet(void)
{
	if(WapSecurityIndex == 0)
	{
		Cms_Browser_SetupSecurityOn();
	}
	else
	{
		Cms_Browser_SetupSecurityOff();
	} 

	Cms_Browser_SaveBrowserSetupToFile();
	Cms_SaveSetupFile();
	
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
	return;
}

/*================================================================
	Protocal menu function interface				
================================================================*/
/*==============================================================
*   Function Name:	EntryScrWapSetBGMusicMenuList
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapSetConnectModeMenuList(void)
{
	U8*  guiBuffer=NULL;
	S32  hiliteitem;
	
	if ( CmsGetNetType() == CMS_WAP_CONNECT_HTTP)
	{
		hiliteitem = 0;
	}
	else
	{
		hiliteitem = 1;
	}
	
	EntryNewScreen(SCR_ID_WAP_SETCONNECTMODE_MENU, NULL, EntryScrWapSetConnectModeMenuList, NULL);
	
	BrowserScreen_ID = SCR_ID_WAP_SETCONNECTMODE_MENU;
	
	SetMessagesCurrScrnID(SCR_ID_WAP_SETCONNECTMODE_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_SETCONNECTMODE_MENU);

	
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SETCONNECTMODE_MENU);              
	RegisterHighlightHandler(GetWapConnectModeIndex);
	ShowCategory184Screen(STR_WAP_SETTINGS_SETCONNECTMODE_ID, IMG_WAP_MAIN_MENU_ICON, 
		STR_GLOBAL_OK, IMG_GLOBAL_OK,
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
		2, mmi_wap_setprotocal_list_get_item, 
		mmi_wap_setprotocal_list_get_hint , hiliteitem, guiBuffer);

	SetLeftSoftkeyFunction(EntryScrWapConnectModeSet, KEY_EVENT_UP);

	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_setmusic_list_get_item
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
pBOOL mmi_wap_setprotocal_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	 
	pfnUnicodeStrcpy((S8*)str_buff, GetString(STR_WAP_SETTINGS_SETCONNECTMODE_HTTP_ID+item_index));
	
	if( (CmsGetNetType() && (item_index == 0)) || ((!CmsGetNetType()) && (item_index == 1)) )
	{
		*img_buff_p = (UI_image_type)GetImage(IMG_WAP_MAIN_MENU_ICON);
	}
	else
	{
		*img_buff_p = NULL;
	}	 
	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_setmusic_list_get_hint
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
S32 mmi_wap_setprotocal_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	EntryScrWapConnectModeSet
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapConnectModeSet(void)
{
	if(WapConnectModeIndex == 0)
	{
		Cms_Browser_SetupNetTypeHttp();
	}
	else
	{
		Cms_Browser_SetupNetTypeWap();
	} 

	Cms_Browser_SaveBrowserSetupToFile();
	Cms_SaveSetupFile();
	
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
	return;
}
//End Settings
/*==============================================================
							bookmark option menu function
==============================================================*/
/*==============================================================
*   Function Name:	CMS_BOOKMARKRELINK_Entry
*   Input        :  void
*   Output       :  void
*   description  :	entry bookmark link
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_bookmark_link(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	if(IsBookMarkNull == KAL_TRUE)
	{
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	}
	else	
	{
		SetLeftSoftkeyFunction(EntryScrWapBookMarkLink, KEY_EVENT_UP);
	}
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	EntryScrWapBookMarkLink
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapBookMarkLink(void)
{	
	//add by xiaoyongq free net struct
	if( 1 == CmsIsImgStackDL() )
	{
		cms_trace("EntryScrWapBookMarkLink");
		CmsAbortDownload();
	}	
 	initURL();
	/*清除跑马灯*/
	ClearAllMarqueeMovie();
	MainMenu_State = WAP_MENU_BOOKMARK_MENU;
 	if(Option_Ok==1) 
		GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);	
	else
		Browser_page();
}
/*==============================================================
*   Function Name:	mmi_wap_bookmark_rename
*   Input        :  void
*   Output       :  void
*   description  :	entry bookmark rename
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_bookmark_rename(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);	
	if(IsBookMarkNull == KAL_TRUE)
	{
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	}
	else	
	{
		SetLeftSoftkeyFunction(WapBookMarkEditEvent, KEY_EVENT_UP);
	}
	
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_bookmark_deleteall
*   Input        :  void
*   Output       :  void
*   description  :	delete all bookmark entry
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_bookmark_deleteall(void)
{	
	if(IsBookMarkNull == KAL_TRUE)
	{
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	}
	else	
	{
		SetLeftSoftkeyFunction(Bookmark_deleteall_Entry, KEY_EVENT_UP);
	}
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_bookmark_delete
*   Input        :  void
*   Output       :  void
*   description  :	delete select bookmark entry
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_bookmark_delete(void)
{	
	if(IsBookMarkNull == KAL_TRUE)
	{
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	}
	else	
	{
		SetLeftSoftkeyFunction(Bookmark_delete_Entry, KEY_EVENT_UP);
	}
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_bookmark_add
*   Input        :  void
*   Output       :  void
*   description  :	entry of add a new bookmark
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_bookmark_add(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(WapBookMarkAddMenuList, KEY_EVENT_UP);
	//SetKeyHandler(WapBookMarkAddMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*================================================================
							Bookmark menu function event				
================================================================*/
/*==============================================================
*   Function Name:	Bookmark_deleteall_Entry
*   Input        :  void
*   Output       :  void
*   description  :	delete all book mark implement
*   author       : 
*   date         :
==============================================================*/
void Bookmark_deleteall_Entry(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
		STR_GLOBAL_NO, IMG_GLOBAL_BACK,
		(UI_string_type)GetString(STR_WAP_BOOKMARKOPTION_DELETEALL_ID),
		IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(DeleteAllBookMark, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	Bookmark_delete_Entry
*   Input        :  void
*   Output       :  void
*   description  :	delete select bookmark implement
*   author       : 
*   date         :
==============================================================*/
void Bookmark_delete_Entry(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_WAP_BOOKMARKOPTION_DELETE_ID),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(DeleteSelectBookMark, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	DeleteAllBookMark
*   Input        :  void
*   Output       :  void
*   description  :	confirm delete all bookmark
*   author       :  
*   date         :
==============================================================*/
void DeleteAllBookMark(void)
{
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
	Cms_Browser_DeleteAllBookmark();
	GoBackToHistory(SCR_ID_WAP_BOOKMARK_MENU);
}
/*==============================================================
*   Function Name:	DeleteSelectBookMark
*   Input        :  void
*   Output       :  void
*   description  :	confirm delete select bookmark
*   author       :  
*   date         :
==============================================================*/
void DeleteSelectBookMark(void)
{
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
	Cms_Browser_DeleteBookmark(BookmarkIndex);
	GoBackToHistory(SCR_ID_WAP_BOOKMARK_MENU);
}
/*==============================================================
*   Function Name:	WapAddBookMarkNoChanged
*   Input        :  void
*   Output       :  void
*   description  :	add bookmark cancle
*   author       :  
*   date         :
==============================================================*/
void WapAddBookMarkNoChanged(void)
{
	GoBackToHistory(SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU);
}
/*==============================================================
*   Function Name:	WapBookMarkAddMenuList
*   Input        :  void
*   Output       :  void
*   description  :	add bookmark menu list
*   author       :  
*   date         :
==============================================================*/
void WapBookMarkAddMenuList(void)
{
	if(Cms_Browser_BookmarkFull())
	{
		DisplayPopup((U8*)GetString(STR_WAP_BOOKMARKISFULL_ID), IMG_GLOBAL_WARNING, NULL, 2000, WARNING_TONE);
		return;
	}
	else
	{
		cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
		cms_memset(NewLink_UrlEdit, 0x0, sizeof(NewLink_UrlEdit));
		
		pfnUnicodeStrcpy((S8 *)NewLink_UrlEdit, (const S8 *)(L"http://"));
		EntryScrWapBookMarkAddMenuList();
	}	
}
/*****************************************************************************
* FUNCTION
*  ExitScrWapBookMarkEdit
* DESCRIPTION
*   退出并进入Inline编辑菜单
*
* PARAMETERS
*  none
* RETURNS
*  none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void ExitScrWapBookMarkEdit(void)
{
	history	h;
	U16 inputBufferSize;
	CloseCategory57Screen();
	h.scrnID = SCR_ID_WAP_BOOKMARK_RENAME_MENU;
	h.entryFuncPtr = EntryScrWapBookMarkEditMenuList;
	GetCategoryHistory(h.guiBuffer);
	inputBufferSize =(U16)GetCategory57DataSize( ); 
	GetCategory57Data ((U8*) h.inputBuffer );  
	AddNHistory(h, inputBufferSize);           	
}
/*==============================================================
*   Function Name:	WapAddBookMarkEdit
*   Input        :  void
*   Output       :  void
*   description  :	edit new bookmark contain url and title
*   author       :  
*   date         :
==============================================================*/
void WapChangeBookMarkEdit(void)
{
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(WapBookMarkEditOption, KEY_EVENT_UP);
}
/*==============================================================
*   Function Name:	WapAddBookMarkEditOption
*   Input        :  void
*   Output       :  void
*   description  :	full screen edit control
*   author       :  
*   date         :
==============================================================*/
void WapBookMarkEditOption(void)
{
	ConfirmInlineFullScreenEdit();
}
/*==============================================================
*   Function Name:	WapBookMarkAddFillInlineStruct
*   Input        :  void
*   Output       :  void
*   description  :	multiply edit box input 
*   author       :  
*   date         :
==============================================================*/
void WapBookMarkAddFillInlineStruct(void)
{
	SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_WAP_BOOKMARKOPTION_ADDTITLE_ID));

	SetInlineItemActivation(&(wgui_inline_items[1]),KEY_LSK, KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&(wgui_inline_items[1]), STR_WAP_BOOKMARKOPTION_ADDTITLE_ID, NULL, InputContent_Edit,BOOK_TITLE_LENGTH+1,
		INPUT_TYPE_ALPHANUMERIC_LOWERCASE);
	SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[1]), WapAddBookMarkEdit);
	RightJustifyInlineItem(&wgui_inline_items[1]);
	
	SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_WAP_BOOKMARKOPTION_ADDURL_ID));
					
	SetInlineItemActivation(&(wgui_inline_items[3]),KEY_LSK, KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&(wgui_inline_items[3]), STR_WAP_BOOKMARKOPTION_ADDURL_ID, NULL, NewLink_UrlEdit,BOOK_URL_LENGTH+1,
		INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
	SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[3]), WapAddBookMarkEdit);
	RightJustifyInlineItem(&wgui_inline_items[3]);
}
/*==============================================================
*   Function Name:	WapAddBookMarkEdit
*   Input        :  void
*   Output       :  void
*   description  :	edit new bookmark contain url and title
*   author       :  
*   date         :
==============================================================*/
void WapAddBookMarkEdit(void)
{
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(WapAddBookMarkEditOption, KEY_EVENT_UP);
}
/*==============================================================
*   Function Name:	WapAddBookMarkEditOption
*   Input        :  void
*   Output       :  void
*   description  :	full screen edit control
*   author       :  
*   date         :
==============================================================*/
void WapAddBookMarkEditOption(void)
{
	ConfirmInlineFullScreenEdit();
}
/*==============================================================
*   Function Name:	WapAddBookMarkConfirm
*   Input        :  void
*   Output       :  void
*   description  :	bookmark add confirm
*   author       :  
*   date         :
==============================================================*/
void WapEditBookMarkConfirm(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_GLOBAL_OK),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(WapEditBookMarkFinish, KEY_EVENT_UP);
	SetRightSoftkeyFunction(WapEditBookMarkNoChanged, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	WapAddBookMarkFinish
*   Input        :  void
*   Output       :  void
*   description  :	add book mark confirm finish 
*   author       :  
*   date         :
==============================================================*/
void WapEditBookMarkFinish(void)
{	 
	if ( (InputContent_Edit[0] == NULL && InputContent_Edit[1] == NULL) || (BookMark_UrlEdit[0] == NULL) )
	{

		DisplayPopup((U8*)GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	else
	{
		CMS_BROWSER_U8 editbookmarktitle[190] = {0};
	  	  P_CMS_BROWSER_U8 editbookmarkurl = NULL;
		  int i =0;
		  U8 temp_16[BOOK_URL_LENGTH*2+2]={0};
	  
		  while (i<BOOK_URL_LENGTH*2+2 &&(InputContent_Edit[i] != NULL||InputContent_Edit[i+1]!=NULL) )
		  {
		   	temp_16[i] = InputContent_Edit[i+1];
			 temp_16[i+1] = InputContent_Edit[i];
			 i = i+2;
		  }
		  Cms_Browser_Uni16_8(temp_16,editbookmarktitle);
		 
		  cms_memset(temp_16, 0x0, BOOK_URL_LENGTH*2+2);
		  i = 0;

		editbookmarkurl = cms_malloc(BOOK_URL_LENGTH*2+2);
		cms_memset(editbookmarkurl, 0x0, BOOK_URL_LENGTH*2+2);
		while (BookMark_UrlEdit[i*2] != NULL&&i<BOOK_URL_LENGTH*2+2)
		{
			editbookmarkurl[i] = BookMark_UrlEdit[i*2];
			i++;
		}
	
		Cms_Browser_EditBookmark(BookmarkIndex, editbookmarktitle, editbookmarkurl);
		cms_free(editbookmarkurl);
		editbookmarkurl = NULL;

		GoBackToHistory(SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU);
		DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);	

	} 
}	
/*==============================================================
*   Function Name:	WapAddBookMarkNoChanged
*   Input        :  void
*   Output       :  void
*   description  :	edit bookmark cancle
*   author       :  
*   date         :
==============================================================*/
void WapEditBookMarkNoChanged(void)
{
	GoBackToHistory(SCR_ID_WAPBOOKMARKOPTION_MAIN_MENU);
}
/*==============================================================
*   Function Name:	EntryScrWapBookMarkAddMenuList
*   Input        :  void
*   Output       :  void
*   description  :	add bookmark menu list entry
*   author       :   
*   date         : 
==============================================================*/
void EntryScrWapBookMarkAddMenuList(void)
{ 
	U8* inputBuffer;
	U8* guiBuffer;
	U16 inputBufferSize;
	U16 WapBookMarkAddIcons[4] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0 };
	EntryNewScreen(SCR_ID_WAP_BOOKMARK_ADD_MENU,ExitScrWapBookMarkAdd,NULL,  NULL);
 
	BrowserScreen_ID = SCR_ID_WAP_BOOKMARK_ADD_MENU;

	InitializeCategory57Screen();
	WapBookMarkAddFillInlineStruct();
 
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_BOOKMARK_ADD_MENU);
	inputBuffer = GetCurrNInputBuffer(SCR_ID_WAP_BOOKMARK_ADD_MENU, &inputBufferSize );
	if(inputBuffer != NULL)		
		SetCategory57Data(wgui_inline_items, 4, inputBuffer);
 
	ShowCategory57Screen(STR_WAP_BOOKMARKOPTION_ADD_ID,IMG_WAP_MAIN_MENU_ICON,
						STR_GLOBAL_OK,IMG_GLOBAL_OK,
						STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						4,
						WapBookMarkAddIcons,wgui_inline_items,1,guiBuffer);

	SetCategory57RightSoftkeyFunctions(WapAddBookMarkConfirm, GoBackHistory);
 
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*****************************************************************************
* FUNCTION
*  ExitScrWapBookMarkAddMenuList
* DESCRIPTION
*   退出并进入Inline编辑菜单
*
* PARAMETERS
*  none
* RETURNS
*  none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void ExitScrWapBookMarkAdd(void)
{
	history	h;
	U16 inputBufferSize;
	CloseCategory57Screen();
	h.scrnID = SCR_ID_WAP_BOOKMARK_ADD_MENU;
	h.entryFuncPtr = EntryScrWapBookMarkAddMenuList;
	GetCategoryHistory(h.guiBuffer);
	inputBufferSize =(U16)GetCategory57DataSize( ); 
	GetCategory57Data ((U8*) h.inputBuffer );  
	AddNHistory(h, inputBufferSize);           	
}
/*==============================================================
*   Function Name:	WapAddBookMarkConfirm
*   Input        :  void
*   Output       :  void
*   description  :	bookmark add confirm
*   author       :  
*   date         :
==============================================================*/
void WapAddBookMarkConfirm(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_GLOBAL_OK),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(WapAddBookMarkFinish, KEY_EVENT_UP);
	SetRightSoftkeyFunction(WapAddBookMarkNoChanged, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	WapAddBookMarkFinish
*   Input        :  void
*   Output       :  void
*   description  :	add book mark confirm finish 
*   author       :  
*   date         :
==============================================================*/
void WapAddBookMarkFinish(void)
{ 
	 if ( (InputContent_Edit[0] == NULL && InputContent_Edit[1] == NULL ) || (NewLink_UrlEdit[0] == NULL) )
	 {
	  	 DisplayPopup((U8*)GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
	 	return;
	 
	 }
	 else
	 {
	 	  CMS_BROWSER_U8 addbookmarktitle[190] = {0};
	  	  P_CMS_BROWSER_U8 addbookmarkurl = NULL;
		  int i =0;
		  U8 temp_16[BOOK_URL_LENGTH*2+2]={0};
	  
		  while (i<BOOK_URL_LENGTH*2+2&&(InputContent_Edit[i] != NULL||InputContent_Edit[i+1]!=NULL) )
		  {
		   	temp_16[i] = InputContent_Edit[i+1];
			 temp_16[i+1] = InputContent_Edit[i];
			 i = i+2;
		  }
		  Cms_Browser_Uni16_8(temp_16,addbookmarktitle);
		 
		  cms_memset(temp_16, 0x0, BOOK_URL_LENGTH*2+2);
		  i = 0;
		  while (NewLink_UrlEdit[i] != NULL&&i<BOOK_URL_LENGTH*2+2)
		  {
			   temp_16[i] = NewLink_UrlEdit[i+1];
			   temp_16[i+1] = NewLink_UrlEdit[i];
			   i = i+2;
		  }
		  addbookmarkurl = cms_malloc(BOOK_URL_LENGTH*2+2);
		  cms_memset(addbookmarkurl, 0x0, BOOK_URL_LENGTH*2+2);
		  Cms_Browser_Uni16_8(temp_16,addbookmarkurl);
		  wap_Tracer("===WapAddBookMarkFinish()==");
		  Cms_Browser_NewBookmarkAdd(addbookmarktitle, addbookmarkurl);
		  cms_free(addbookmarkurl);
		  addbookmarkurl = NULL;
		  wap_Tracer("===WapAddBookMarkFinish()==");
		  Cms_SaveBookMarkFile();
		  cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit)); 
		  GoBackToHistory(SCR_ID_WAP_BOOKMARK_MENU);
		  DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);

	 } 
}
/*==============================================================
*   Function Name:	WapBookMarkEditFillInlineStruct
*   Input        :  void
*   Output       :  void
*   description  :	multiply edit box input 
*   author       :  
*   date         :
==============================================================*/
void WapBookMarkEditFillInlineStruct(void)
{
	SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_WAP_BOOKMARKOPTION_ADDTITLE_ID));

	SetInlineItemActivation(&(wgui_inline_items[1]),KEY_LSK, KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&(wgui_inline_items[1]), STR_WAP_BOOKMARKOPTION_ADDTITLE_ID, NULL, InputContent_Edit,BOOK_TITLE_LENGTH+1,
		INPUT_TYPE_ALPHANUMERIC_LOWERCASE);
	SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[1]), WapChangeBookMarkEdit);
	RightJustifyInlineItem(&wgui_inline_items[1]);
	SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_WAP_BOOKMARKOPTION_ADDURL_ID));
					
	SetInlineItemActivation(&(wgui_inline_items[3]),KEY_LSK, KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&(wgui_inline_items[3]), STR_WAP_BOOKMARKOPTION_ADDURL_ID, NULL, BookMark_UrlEdit,BOOK_URL_LENGTH+1,
		INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
	SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[3]), WapChangeBookMarkEdit);
	RightJustifyInlineItem(&wgui_inline_items[3]);
}
/*==============================================================
*   Function Name:	EntryScrWapBookMarkEditMenuList
*   Input        :  void
*   Output       :  void
*   description  :	edit bookmark menu list entry
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapBookMarkEditMenuList(void)
{
	U8* inputBuffer;
	U8* guiBuffer;
	U16 WapBookMarkEditIcons[4] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0 };
	U16 inputBufferSize;

	EntryNewScreen(SCR_ID_WAP_BOOKMARK_RENAME_MENU,ExitScrWapBookMarkEdit, NULL, NULL);

	BrowserScreen_ID = SCR_ID_WAP_BOOKMARK_RENAME_MENU;

	InitializeCategory57Screen();
	WapBookMarkEditFillInlineStruct();

	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_BOOKMARK_RENAME_MENU);
	inputBuffer = GetCurrNInputBuffer(SCR_ID_WAP_BOOKMARK_RENAME_MENU, &inputBufferSize );
	if(inputBuffer != NULL)		
 		SetCategory57Data(wgui_inline_items, 4, inputBuffer);
	ShowCategory57Screen(STR_WAP_BOOKMARKOPTION_EDIT_ID,IMG_WAP_MAIN_MENU_ICON,
						STR_GLOBAL_OK,IMG_GLOBAL_OK,
						STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						4,
						WapBookMarkEditIcons,wgui_inline_items,1,guiBuffer);

	SetCategory57RightSoftkeyFunctions(WapEditBookMarkConfirm, GoBackHistory);

	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	WapBookMarkEditEvent
*   Input        :  void
*   Output       :  void
*   description  :	edit the title of select bookmark url and title
*   author       : 
*   date         :
==============================================================*/
void WapBookMarkEditEvent(void)
{
	//　显示历史记录数据　　同时将历史纪录编码转换为unicode	
	CMS_BROWSER_U32    string_len  = 0, i =0;
	P_CMS_BROWSER_U8   string_conv = NULL;
	P_CMS_BROWSER_U8   pTitle;
	P_CMS_BROWSER_U8   pUrl;
	P_CMS_BROWSER_U8 temp_16 = NULL;
	CMS_BROWSER_U32  uni16Len = 0;
	cms_memset(InputContent_Edit, 0x0 ,sizeof(InputContent_Edit));
	cms_memset(BookMark_UrlEdit, 0x0 , sizeof(BookMark_UrlEdit));
	pTitle = (P_CMS_BROWSER_U8)Cms_Browser_GetBookmarkTitleById(BookmarkIndex);
	pUrl = (P_CMS_BROWSER_U8)Cms_Browser_GetBookmarkUrlById(BookmarkIndex);
 	if (NULL != pTitle) 
      {
		uni16Len     = Cms_UTF8toUTF16Len(pTitle);
		temp_16 = (P_CMS_BROWSER_U8)cms_malloc(uni16Len+2);
		Cms_UTF8toUTF16(pTitle, cms_strlen((const char*)pTitle), uni16Len, temp_16);
		string_len = 2*Cms_UTF16Strlen(temp_16)+2;
		
		string_conv = (P_CMS_BROWSER_U8)cms_malloc(string_len);
		//for(i=0;i<string_len;i+=2)  //标题和显示长度不匹配
		//changed by xiaoyongqu 20060809
		for(i=0;i<string_len&&i<BOOK_URL_LENGTH;i+=2)
		{
			*(string_conv+i) = *(temp_16+i+1);
			*(string_conv+i+1) = *(temp_16+i);
		}

		pfnUnicodeStrcpy((char*)InputContent_Edit, (const char *)string_conv);
		cms_free(string_conv);
		string_conv = NULL;
		cms_free(temp_16);
		temp_16 = NULL;
       }

	i = 0;
	while( (pUrl[i] != NULL) && (i<BOOK_URL_LENGTH) ) //modify by xiaoyongq 20060109 for bug 31126 
	{
		BookMark_UrlEdit[i*2] = pUrl[i];
		i++;
	}	
	EntryScrWapBookMarkEditMenuList();
}
/*===============================================================
Push Module Function
================================================================*/

/*==============================================================
*   Function Name:	mmi_wap_pushbox_list_get_item
*   Input        :  S32 item_index
					UI_string_type str_buff
					UI_image_type* img_buff_p
					U8 str_img_mask
*   Output       :  void
*   description  :	get push message item str_buf and image buf
*   author       : 
*   date         :
==============================================================*/
pBOOL mmi_wap_pushbox_list_get_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{	
	/*　显示Push记录数据　　同时将Push纪录编码转换为unicode	*/
	P_CMS_BROWSER_U8   pTitle;
	P_CMS_BROWSER_U8 temp_16 = NULL;
	CMS_BROWSER_U32  uni8Len = 0;

	if(item_index >= CMS_MAX_PUSH)
	{
		return TRUE;;
	}
	
	pTitle = (P_CMS_BROWSER_U8)Cms_Browser_GetPUSHTitleById(item_index);
    	if (NULL != pTitle) 
    	{
		uni8Len = Cms_Browser_Uni8_strlen(pTitle);
		temp_16 = cms_malloc(2*uni8Len+2);		
		Cms_Browser_Uni8_16_big(pTitle,temp_16);

		pfnUnicodeStrcpy((char*)str_buff, (const char *)temp_16);
		cms_free(temp_16);
		temp_16 = NULL;
    }
	
	if ( Cms_Browser_GetPUSHDownloadInfo(item_index) )
	{
		*img_buff_p = (UI_image_type)GetImage(IMG_WAPREAD_MAIN_MENU_ICON);
	}
	else
	{
		*img_buff_p = (UI_image_type)GetImage(IMG_WAPUNREAD_MAIN_MENU_ICON);
	}
	return TRUE;
}
/*==============================================================
*   Function Name:	mmi_wap_pushbox_list_get_hint
*   Input        :  S32 item_index
					UI_string_type *hint_array
*   Output       :  void
*   description  :	push box message list get hint str_buf
*   author       :  
*   date         :
==============================================================*/
S32 mmi_wap_pushbox_list_get_hint( S32 item_index, UI_string_type *hint_array )
{
	*hint_array = NULL;
	return 1;
}
/*==============================================================
*   Function Name:	MtkGetUnreadPushMessageNum
*   Input        :  void
*   Output       :  void
*   description  :	notify MTK unread push message Num
*   author       :  
*   date         :
==============================================================*/
void MtkGetUnreadPushMessageNum(void)
{
	/*当Num改变的时候调用此函数*/
	browser_mmi_tracer((char *)"========MtkGetUnreadPushMessageNum = %d", (char *)UnreadPushMessageNum);
	cms_show_wappush_icon();
}
/*==============================================================
*   Function Name:	EntryScrWapPushboxMenuList
*   Input        :  void
*   Output       :  void
*   description  :	entry pushbox message list menu
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapPushboxMenuList(void)
{
	U8*  guiBuffer = NULL;
	S32  hiliteitem = 0;
	int	 PushMessageNum = 0;
	P_CMS_BROWSER_U8 title = NULL;
	
	wap_Tracer("enter pushbox.... entry");
	title = (P_CMS_BROWSER_U8)Cms_Browser_GetPUSHTitleById((CMS_BROWSER_U32)PushMessageNum);

	while( NULL !=  title )
	{
		PushMessageNum++;
		title = (P_CMS_BROWSER_U8)Cms_Browser_GetPUSHTitleById((CMS_BROWSER_U32)PushMessageNum);

		if(PushMessageNum >= CMS_MAX_PUSH)
		{
			title = NULL;
			break;
		}
	}
	if (0 == PushMessageNum)
	{
		DisplayPopup((U8*)GetString(STR_WAP_NO_PUSHMESSAGE_ID), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	
	EntryNewScreen(SCR_ID_WAP_PUSHBOX_MENU, NULL, EntryScrWapPushboxMenuList, NULL);	

	BrowserScreen_ID = SCR_ID_WAP_PUSHBOX_MENU;

	SetMessagesCurrScrnID(SCR_ID_WAP_PUSHBOX_MENU);            
	SetMessagesScrnIdToDelHistoryNodes(SCR_ID_WAP_PUSHBOX_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_PUSHBOX_MENU);              
	RegisterHighlightHandler(GetPushboxIndex);
	ShowCategory184Screen(STR_WAP_PUSHBOX_ID, IMG_WAP_MAIN_MENU_ICON, 
							STR_GLOBAL_VIEW, IMG_GLOBAL_OK,
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							PushMessageNum, mmi_wap_pushbox_list_get_item, 
							mmi_wap_pushbox_list_get_hint , hiliteitem, guiBuffer);

	if (PushMessageNum == 0)
	{
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	}
	else
	{
		SetLeftSoftkeyFunction(EntryScrWapPushMessageShow, KEY_EVENT_UP);	
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	}

	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);

	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*Show Push Info*/
void WapGeneralPushShow(void)
{
	int i = 0;
	P_CMS_BROWSER_U8 pushstr = NULL;
	char temp[26] = {0};
	P_CMS_BROWSER_U8 temp_16 = NULL;
	CMS_BROWSER_U32  uni8Len = 0;
	cms_memset(UnicodeBuf,0,sizeof(UnicodeBuf));
	//添加push 创建时间
	pushstr = (P_CMS_BROWSER_U8)Cms_Browser_GetPUSHTimeById(PushboxIndex);
	while(i<12)
	{
		temp[i*2] = pushstr[i];
		i++;
	}
	i = 0;
	Cms_hex_trace((kal_uint8 *)temp, (kal_int32)(sizeof(char)*12*2));
	
	pfnUnicodeStrncpy((PS8)UnicodeBuf,(PS8)temp,4);

	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"-");

	pfnUnicodeStrncat((PS8)UnicodeBuf,(PS8)(temp+8),2);

	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"-");

	pfnUnicodeStrncat((PS8)UnicodeBuf,(PS8)(temp+12),2);

	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"-");

	pfnUnicodeStrncat((PS8)UnicodeBuf,(PS8)(temp+16),2);

	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"-");

	pfnUnicodeStrncat((PS8)UnicodeBuf,(PS8)(temp+20),2);
	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_WAP_PUSHURL_ID ));
	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");

	//添加push 指向的网址
	pushstr = (P_CMS_BROWSER_U8)Cms_Browser_GetPUSHUrlById(PushboxIndex);
	{
		uni8Len = Cms_Browser_Uni8_strlen(pushstr);
		temp_16 = cms_malloc(2*uni8Len+2);		
		Cms_Browser_Uni8_16_big(pushstr,temp_16);
		
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)temp_16);

		i = 0;
		uni8Len = 0;
		cms_free(temp_16);
		temp_16 = NULL;
	}	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_WAP_PUSHMESSAGE_ID ));

	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	
	//添加push的标题
	pushstr = Cms_Browser_GetPUSHTitleById(PushboxIndex);
	{
		uni8Len = Cms_Browser_Uni8_strlen(pushstr);
		Cms_hex_trace(pushstr, uni8Len);
		temp_16 = cms_malloc(2*uni8Len+2);		
		Cms_Browser_Uni8_16_big(pushstr,temp_16);
		Cms_hex_trace(temp_16, 2*uni8Len+2);
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)temp_16);

		uni8Len = 0;
		cms_free(temp_16);
		temp_16 = NULL;
	}	
	
}

void WapOTABookmarkPushShow(void)
{
	int i = 0;
	P_CMS_BROWSER_U8 pushstr = NULL;
	P_CMS_BROWSER_U8 temp_16 = NULL;
	CMS_BROWSER_U32  uni8Len = 0;
	cms_memset(UnicodeBuf,0,sizeof(UnicodeBuf));

	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_WAP_BOOKMARK_ID ));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	
	//添加push的标题
	pushstr = Cms_Browser_GetPUSHTitleById(PushboxIndex);
	{
		uni8Len = Cms_Browser_Uni8_strlen(pushstr);
		Cms_hex_trace(pushstr, uni8Len);
		temp_16 = cms_malloc(2*uni8Len+2);		
		Cms_Browser_Uni8_16_big(pushstr,temp_16);
		Cms_hex_trace(temp_16, 2*uni8Len+2);
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)temp_16);

		uni8Len = 0;
		cms_free(temp_16);
		temp_16 = NULL;
	}	
	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_WAP_PUSHURL_ID ));	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");

	//添加push 指向的网址
	pushstr = (P_CMS_BROWSER_U8)Cms_Browser_GetPUSHUrlById(PushboxIndex);
	{
		uni8Len = Cms_Browser_Uni8_strlen(pushstr);
		temp_16 = cms_malloc(2*uni8Len+2);		
		Cms_Browser_Uni8_16_big(pushstr,temp_16);
		
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)temp_16);

		i = 0;
		uni8Len = 0;
		cms_free(temp_16);
		temp_16 = NULL;
	}	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	
}

void WapOTASettingPushShow(void)
{
	int i = 0;
	P_CMS_BROWSER_U8 pushstr = NULL;
	P_CMS_BROWSER_U8 temp_16 = NULL;
	CMS_BROWSER_U32  uni8Len = 0;
	cms_memset(UnicodeBuf,0,sizeof(UnicodeBuf));
	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_WAP_HOMEPAGE_ID ));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	
	//添加push的标题
	pushstr = Cms_Browser_GetPUSHTitleById(PushboxIndex);
	{
		uni8Len = Cms_Browser_Uni8_strlen(pushstr);
		Cms_hex_trace(pushstr, uni8Len);
		temp_16 = cms_malloc(2*uni8Len+2);		
		Cms_Browser_Uni8_16_big(pushstr,temp_16);
		Cms_hex_trace(temp_16, 2*uni8Len+2);
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)temp_16);

		uni8Len = 0;
		cms_free(temp_16);
		temp_16 = NULL;
	}	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_WAP_PUSHURL_ID ));	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");

	//添加push 指向的网址
	pushstr = (P_CMS_BROWSER_U8)Cms_Browser_GetPUSHUrlById(PushboxIndex);
	{
		uni8Len = Cms_Browser_Uni8_strlen(pushstr);
		temp_16 = cms_malloc(2*uni8Len+2);		
		Cms_Browser_Uni8_16_big(pushstr,temp_16);
		
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)temp_16);

		i = 0;
		uni8Len = 0;
		cms_free(temp_16);
		temp_16 = NULL;
	}	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
}

/*==============================================================
*   Function Name:	EntryScrWapPushMessageShow
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapPushMessageShow(void)
{
	U8*		guiBuffer=NULL;
	S32		str_len = 0;
	CMS_BROWSER_U32 PushType=0;
	PushType=Cms_Browser_GetPushTypeByID(PushboxIndex);
	if(PushType==0)
		WapGeneralPushShow();
	else if(PushType==1)
		WapOTABookmarkPushShow();
	else if(PushType==2)
		WapOTASettingPushShow();
	else 
		return;
	/*刷新PUSH ICON*/
	if (!(Cms_Browser_GetPUSHDownloadInfo(PushboxIndex)))
	{
		UnreadPushMessageNum --;
		MtkGetUnreadPushMessageNum();
		cms_show_wappush_icon();
	}	
	str_len=pfnUnicodeStrlen((PS8)UnicodeBuf);
	
	Cms_Browser_SetPUSHDownloadInfo(PushboxIndex, CMS_BROWSER_TRUE);
	
	EntryNewScreen(SCR_ID_WAP_SHOWPUSHMESSAGE_MAIN_MENU, NULL,
				EntryScrWapPushMessageShow, NULL);
	
	SetMessagesCurrScrnID(SCR_ID_WAP_SHOWPUSHMESSAGE_MAIN_MENU);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SHOWPUSHMESSAGE_MAIN_MENU);
	
	ShowCategory74Screen(STR_WAP_PUSHMESSAGE_ID,IMG_WAP_MAIN_MENU_ICON,
						STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS,STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						(PU8)UnicodeBuf, str_len, guiBuffer);

	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
	SetLeftSoftkeyFunction(BrowserPushBoxOption, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*==============================================================
*   Function Name:	mmi_wap_push_link
*   Input        :  void
*   Output       :  void
*   description  :	entry of push message link
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_push_link(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapPushMessageLink, KEY_EVENT_UP);
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);	
}
 /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_wap_ota_to_setting(void)
 {
 	char* temp=NULL;
	P_CMS_BROWSER_U8 SettingTitle=NULL,SettingURL=NULL,SettingGateWay=NULL,SettingPort=NULL;

	SettingTitle=Cms_Browser_GetPUSHTitleById(PushboxIndex);
	SettingURL=Cms_Browser_GetPUSHUrlById(PushboxIndex);
	SettingGateWay=Cms_Browser_GetPushGatewayById(PushboxIndex);
	SettingPort=Cms_Browser_GetPushPortById(PushboxIndex);
	/*将配置信息加入预设配置*/
	cms_memset(&gWapTemp, 0x0, sizeof(WAP_CONFIG));	

	if(SettingTitle!=NULL)
	{	
		temp=Cms_mms_uni8_16((char*)SettingTitle);
		pfnUnicodeStrcpy((PS8)gWapTemp.service_id,(PS8)temp);
		mms_Free(temp);
		temp = NULL;
	}
	if(SettingURL!=NULL)
	{
		temp=Cms_mms_uni8_16((char*)SettingURL);
		pfnUnicodeStrcpy((PS8)gWapTemp.centre_addr,(PS8)temp);
		mms_Free(temp);
		temp = NULL;
	}
	if(SettingGateWay!=NULL)
	{	
		temp=Cms_mms_uni8_16((char*)SettingGateWay);
		pfnUnicodeStrcpy((PS8)gWapTemp.gateway,(PS8)temp);
		mms_Free(temp);
		temp = NULL;
	}
	if(SettingPort!=NULL)
	{
		temp=Cms_mms_uni8_16((char*)SettingPort);
		pfnUnicodeStrcpy((PS8)gWapTemp.port,(PS8)temp);
		mms_Free(temp);
		temp = NULL;
	}
	wap_write_setting_file_by_index(ghiliindex);		
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	return ;
}

 /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */

void mmi_wap_ota_to_setting_list(void)
{
	U8* guiBuffer = NULL;
	S32 hiliteitem = 0;
	U16 setnumber=0;
	U16 screenId = SCR_ID_WAP_SETTING_SERVICE_ID_MENU;
	PU8	pservicelist[SERVICE_LIST_ITEM]={0};

	memset(servicelist,0,sizeof(servicelist));	
	for(;setnumber<SERVICE_LIST_ITEM;setnumber++)
	{
		wap_read_setting_file_by_index(setnumber);
		if(pfnUnicodeStrlen((S8*)gWapTemp.service_id)==0)
		{
			pfnUnicodeStrcpy((PS8)servicelist[setnumber],(PS8)L"<");
			pfnUnicodeStrcat((PS8)servicelist[setnumber],(S8 *)GetString(STR_GLOBAL_EMPTY));
			pfnUnicodeStrcat((PS8)servicelist[setnumber],(PS8)L">");
		}
		else
		{
			pfnUnicodeStrcpy((S8*)servicelist[setnumber], (S8*)gWapTemp.service_id);
		}
		pservicelist[setnumber]=(PU8)servicelist[setnumber];
	
	}

	EntryNewScreen(screenId, NULL,mmi_wap_ota_to_setting_list, NULL);
	
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
	RegisterHighlightHandler(mmi_get_index);

	if (guiBuffer)
	{
		hiliteitem = ghiliindex;
	}
	else
	{
		hiliteitem=gconfig.wap_service_activeitem;
	}
	
	ShowCategory36Screen( STR_MMS_WAP_EDIT_SETTING, IMG_MESSAGE_MMS_MENUENTRY,
						  	STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  	STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  	SERVICE_LIST_ITEM, (U8**)pservicelist, (U16)hiliteitem, guiBuffer);
	
	SetLeftSoftkeyFunction(mmi_wap_ota_to_setting, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}

/*==============================================================
*   Function Name:	EntryScrWapPushMessageLink
*   Input        :  void
*   Output       :  void
*   description  :	link push message
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapPushMessageLink(void)
{
	CMS_BROWSER_U32 PushType=0;
	PushType=Cms_Browser_GetPushTypeByID(PushboxIndex);
	if(PushType==0)
	{
		//general push
		if (!(Cms_Browser_GetPUSHDownloadInfo(PushboxIndex)))
		{
			UnreadPushMessageNum --;
			MtkGetUnreadPushMessageNum();
			cms_show_wappush_icon();
		}
		MainMenu_State = WAP_MENU_PUSHBOX_MENU;
		Browser_page();
	}
	else if(PushType==1)
	{
		//OTA push bookmark
		P_CMS_BROWSER_U8	BookmarkName=NULL,BookmarkURL=NULL;
		BookmarkName=Cms_Browser_GetPUSHTitleById(PushboxIndex);
		BookmarkURL=Cms_Browser_GetPUSHUrlById(PushboxIndex);
		wap_Tracer("=bookmark push==");	
		if(BookmarkURL==NULL||BookmarkName==NULL)
			return;
		if(Cms_Browser_NewBookmarkAdd(BookmarkName,BookmarkURL)==E_CMS_BM_RECORDFULL)
		{
			cms_trace(": mms_wap_ota_add_bookmark>20");
			DisplayPopup((U8*)GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		}
		DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_OK, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
		GoBackToHistory(SCR_ID_WAP_PUSHBOX_MENU);
	}
	else if(PushType==2)
	{
		//OTA push setting
		wap_Tracer("=setting push==");
		mmi_wap_ota_to_setting_list();
		
	}else
	{
		wap_Tracer("=error==");
	}
}
/*==============================================================
*   Function Name:	mmi_wap_push_delete
*   Input        :  void
*   Output       :  void
*   description  :	entry of push message delete
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_push_delete(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(push_delete_Entry, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	push_delete_Entry
*   Input        :  void
*   Output       :  void
*   description  :	delete select push message entry
*   author       :  
*   date         :
==============================================================*/
void push_delete_Entry(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_WAP_BOOKMARKOPTION_DELETE_ID),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(DeleteSelectPush, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	DeleteSelectPush
*   Input        :  void
*   Output       :  void
*   description  :	delete select push message confirm
*   author       :  
*   date         :
==============================================================*/
void DeleteSelectPush(void)
{
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);

	if (!(Cms_Browser_GetPUSHDownloadInfo(PushboxIndex)))
	{
		UnreadPushMessageNum --;
		MtkGetUnreadPushMessageNum();
		cms_show_wappush_icon();
	}
			
	Cms_Browser_DeletePUSHInfo(PushboxIndex);
	GoBackToHistory(SCR_ID_WAP_PUSHBOX_MENU);
}
/*==============================================================
*   Function Name:	mmi_wap_push_deleteall
*   Input        :  void
*   Output       :  void
*   description  :	delete all push message entry
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_push_deleteall(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(push_deleteall_Entry, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	push_deleteall_Entry
*   Input        :  void
*   Output       :  void
*   description  :	delete all push message complement
*   author       :  
*   date         :
==============================================================*/
void push_deleteall_Entry(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
		STR_GLOBAL_NO, IMG_GLOBAL_BACK,
		(UI_string_type)GetString(STR_WAP_BOOKMARKOPTION_DELETEALL_ID),
		IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(DeleteAllPush, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	DeleteAllPush
*   Input        :  void
*   Output       :  void
*   description  :	delete all push message confirm
*   author       :  
*   date         :
==============================================================*/
void DeleteAllPush(void)
{
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);

	UnreadPushMessageNum = 0;
	MtkGetUnreadPushMessageNum();
	cms_show_wappush_icon();
	Cms_Browser_DeleteAllPUSHInfo();
	GoBackToHistory(SCR_ID_WAP_MAIN_MENU);
}
/*==============================================================
*   Function Name:	BrowserPushBoxOption
*   Input        :  void
*   Output       :  void
*   description  :	entry borwser pushbox option
*   author       :  
*   date         :
==============================================================*/
void BrowserPushBoxOption(void)
{
	U8*	guiBuffer=NULL;
	U16	numItems=0;
	U16	nStrItemList[MAX_SUB_MENUS];
	U16 PushType=0;
	
	EntryNewScreen(SCR_ID_WAPPUSHBOXOPTION_MAIN_MENU, NULL, BrowserPushBoxOption, NULL);	

	BrowserScreen_ID = SCR_ID_WAPPUSHBOXOPTION_MAIN_MENU;
	
	
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAPPUSHBOXOPTION_MAIN_MENU);
	
	numItems = GetNumOfChild (WAPPUSHBOXOPTION_MAIN_MENU);	
	GetSequenceStringIds(WAPPUSHBOXOPTION_MAIN_MENU, nStrItemList);	
	SetParentHandler(WAPPUSHBOXOPTION_MAIN_MENU);

	PushType=Cms_Browser_GetPushTypeByID(PushboxIndex);
	if(PushType==1)
		nStrItemList[0]=STR_MMS_WAP_OTA_ADD_BOOKMARK;
	else if(PushType==2)
		nStrItemList[0]=STR_MMS_WAP_OTA_ADD_SETTING;
	
	RegisterHighlightHandler (ExecuteCurrHiliteHandler);
	mmi_wap_set_wappushboxoption_menu_highlight_handler();
	SetMessagesCurrScrnID(SCR_ID_WAPPUSHBOXOPTION_MAIN_MENU);
	
	ShowCategory52Screen(STR_WAP_PUSHBOXOPTION_MAIN_MENU_ID,	IMG_WAP_MAIN_MENU_ICON, 
						STR_GLOBAL_OK,		IMG_GLOBAL_OK,
						STR_GLOBAL_BACK,	IMG_GLOBAL_BACK,
						numItems, nStrItemList, (U16 *)gIndexIconsImageList, NULL,
						0, 0,	guiBuffer );
	
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
//End Push function

/*===============================================================
									Offline browser
================================================================*/
/*==============================================================
*   Function Name:	EntryScrWapOfflineBrowser
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapOfflineBrowser(void)
{
	MainMenu_State=WAP_MENU_OFFLINE_MENU;
	Browser_page();	
}
/*==============================================================
*   Function Name:	mmi_wap_offline_link
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_offline_link(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(EntryScrWapOfflineBrowser, KEY_EVENT_UP);
	//SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);	
}
/*==============================================================
*   Function Name:	Brw_Offline_GetFileContent
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
unsigned char *Brw_Offline_GetFileContent(unsigned char* OfflineFileName,unsigned int* Sizelen)
{
	int mtkReadOffline = NULL;
	unsigned char* TempContentBuff=NULL;
	unsigned int nread;
	unsigned int size=0;

	if(OfflineFileName==NULL)
		return NULL;	
	
	browser_mmi_tracer("OfflineFileName=%s",OfflineFileName);
	wap_Tracer("==Brw_Offline_GetFileContent=");
	FS_SetCurrentDir((const WCHAR*)CMS_WAP_DIR_PATH);
	mtkReadOffline = Cms_Adp_fopen((S8*)OfflineFileName,FS_READ_ONLY);
	if (mtkReadOffline < 0)
	{
		wap_Tracer("read mtkOffline failed");
		return NULL;
	}
	
	FS_GetFileSize(mtkReadOffline, &size);
	if(size<=0)
	{
		wap_Tracer("file size ==0");
		return NULL;
	}
	TempContentBuff = (unsigned char*)GetSnapShotPtr();
	browser_mmi_tracer("size=%d",size);
	cms_memset(TempContentBuff, 0x0, Cms_Browser_SavePageSize());
	FS_Read(mtkReadOffline, TempContentBuff, size, &nread);		
	FS_Close(mtkReadOffline);	

	*Sizelen=size;
	browser_mmi_tracer("Sizelen=%d",*Sizelen);
	wap_Tracer("==Brw_Offline_GetFileContent out=");
	return TempContentBuff;

}
/*==============================================================
*   Function Name:	Offline_Delete_Selected
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void Offline_Delete_Selected(void)
{
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);			
	Cms_Browser_Delete_Offline(OfflineSetIndex);
	GoBackToHistory(SCR_ID_WAP_OFFLINE_MENU);
}
/*==============================================================
*   Function Name:	Offline_Delete_Selected
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void Offline_Delete_Entry(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_WAP_BOOKMARKOPTION_DELETE_ID),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(Offline_Delete_Selected, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_offline_delete
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_offline_delete(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);	
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(Offline_Delete_Entry, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);

}
/*==============================================================
*   Function Name:	Offline_delete_All
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void Offline_delete_All()
{
	DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
	Cms_Browser_DeleteAll_Offline();
	GoBackToHistory(SCR_ID_WAP_MAIN_MENU);
}
/*==============================================================
*   Function Name:	Offline_deleteall_Entry
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void Offline_deleteall_Entry(void)
{
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
		STR_GLOBAL_NO, IMG_GLOBAL_BACK,
		(UI_string_type)GetString(STR_WAP_BOOKMARKOPTION_DELETEALL_ID),
		IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(Offline_delete_All, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_offline_deleteall
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_offline_deleteall(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(Offline_deleteall_Entry, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	mmi_wap_offline_messagebox
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void mmi_wap_offline_messagebox(void)
{
	DisplayPopup((U8*)GetString(STR_WAP_OFFLINE_FULL_ID), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
}

void mmi_wap_offline_msgbox(void)
{
	DisplayPopup((U8*)GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);	
}
/*==============================================================
*   Function Name:	BrowserOfflineBoxOption
*   Input        :  void
*   Output       :  void
*   description  :	entry borwser pushbox option
*   author       :  
*   date         :
==============================================================*/
void BrowserOfflineOption(void)
{
	U8*	guiBuffer=NULL;
	U16	numItems=0;
	U16	nStrItemList[MAX_SUB_MENUS];
	
	EntryNewScreen(SCR_ID_WAPOFFLINEOPTION_MAIN_MENU, NULL, BrowserOfflineOption, NULL);	

	BrowserScreen_ID = SCR_ID_WAPOFFLINEOPTION_MAIN_MENU;
	
	
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAPOFFLINEOPTION_MAIN_MENU);
	
	numItems = GetNumOfChild (WAPOFFLINEOPTION_MAIN_MENU);	
	GetSequenceStringIds(WAPOFFLINEOPTION_MAIN_MENU, nStrItemList);	
	SetParentHandler(WAPOFFLINEOPTION_MAIN_MENU);
	
	RegisterHighlightHandler (ExecuteCurrHiliteHandler);
	mmi_wap_set_wapofflineoption_menu_highlight_handler();
	SetMessagesCurrScrnID(SCR_ID_WAPOFFLINEOPTION_MAIN_MENU);
	
	ShowCategory52Screen(STR_WAP_OFFLINEOPTION_MAIN_MENU_ID,	IMG_WAP_MAIN_MENU_ICON, 
						STR_GLOBAL_OK,		IMG_GLOBAL_OK,
						STR_GLOBAL_BACK,	IMG_GLOBAL_BACK,
						numItems, nStrItemList, (U16 *)gIndexIconsImageList, NULL,
						0, 0,	guiBuffer );
	
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}

//End Offline function
/*===============================================================
								Save file function					
================================================================*/

/*==============================================================
*   Function Name:	Cms_LoadFile
*   Input        :  void
*   Output       :  void
*   description  :	load file to virtual file
*   author       :
*   date         :
==============================================================*/
void Cms_LoadFile(void)
{
	Cms_LoadBookMarkFile();	
	Cms_LoadSetupFile();
	Cms_LoadPushFile();	
}
/* ----------------------------------------------------------------------------
 * Function Name: Cms_SaveFile
 *       Purpose: save virtual file to file  
 *         Input:  None.
 *        Output: None.
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void Cms_SaveFile(void)
{
	Cms_Browser_WriteUIHistory();
	Cms_Browser_WriteOfflineRecord();
	Cms_SaveBookMarkFile();
	Cms_SaveSetupFile();
	Cms_SavePushFile();	
}
/* ----------------------------------------------------------------------------
 * Function Name: CmsBrwJavaJadFile
 *       Purpose: save jad file  
 *         Input:  buf(file data),len(file length),url(the jad file link url)
 *        Output: None.
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int CmsBrwJavaJadFile (char* buf, short len, char* url)
{
	wap_Tracer((char *)"CmsBrwJavaJadFile");
	if (len > 0)
	{	
		DownLoad_DataLen = len;
		DownLoad_DataBuf = (char*)buf;
	}
	else
	{		
		if(buf != NULL)
		{
			cms_free(buf);
			buf = NULL;
		}
		MainMenu_State = 12;
		Cms_Browser_PageRefreshEvent();
		return 0;
	}	
	CmsStopAllGif();
	cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
#ifdef SUPPORT_JAVA_DOWNLOAD	
	/*将Jad文件提交Java应用识别决定是否需要下载并提示用户*/
#else
	Browser_SaveFileName();
#endif
	return 1;
}
 /* ----------------------------------------------------------------------------
 * Function Name: CmsBrwJavaJarFile
 *       Purpose: save jar file  
 *         Input:  buf(file data),len(file length)
 *        Output: None.
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void CmsBrwJavaJarFile(char * jardata,int jarlen)
{
	wap_Tracer((char *)"CmsBrwJavaJarFile");
	if (jarlen > 0)
	{	
		DownLoad_DataLen = jarlen;
	//	DownLoad_FileType = type;
		DownLoad_DataBuf = (char*)jardata;
	}
	else
	{		
		if(jardata != NULL)
		{
			cms_free(jardata);
			jardata = NULL;
		}
		MainMenu_State = 12;
		Cms_Browser_PageRefreshEvent();
		return;
	}
	
	CmsStopAllGif();
	cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
	Browser_SaveFileName();
}
 
/*==============================================================
*   Function Name:	Cms_SaveData
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void Cms_SaveData(unsigned char * data, int datalen, Cms_ContentType_e type, int forwardtype)
{
	wap_Tracer((char *)"Cms_SaveData()in");
	browser_mmi_tracer("BrowserScreen_ID=%d",(char*)BrowserScreen_ID);
	wap_Tracer((char *)"Cms_Brw_SaveFile");
	if((BrowserScreen_ID != SCR_ID_WAP_PAGEBROWSER_MENU && Option_Ok == 0)
		||(browserflag == 0))//add by yangjun 06-03-22
	{
		if(data != NULL)
		{
			cms_free(data);
			data = NULL;
		}
		return;
	}
		
	if (datalen > 0)
	{	
		DownLoad_DataLen = datalen;
		DownLoad_FileType = type;
		DownLoad_DataBuf = (char*)data;
	}
	else
	{		
		if(data != NULL)
		{
			cms_free(data);
			data = NULL;
		}
		MainMenu_State = 12;
		Cms_Browser_PageRefreshEvent();
		return;
	}
	
	CmsStopAllGif();
	cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
	Browser_SaveFileName();
}
/*==============================================================
*   Function Name:	Browser_SaveFileName
*   Input        :  void
*   Output       :  void
*   description  :	save file as the name input
*   author       :  
*   date         :
==============================================================*/
void Browser_SaveFileName(void)
{
	U8* guiBuffer = NULL;
	EntryNewScreen(SCR_ID_WAP_SAVEFIFLE_MENU, NULL, Browser_SaveFileName, NULL);

	wap_Tracer((char *)"Browser_SaveFileName() in");
	BrowserScreen_ID = SCR_ID_WAP_SAVEFIFLE_MENU;	
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_SAVEFIFLE_MENU);
	
	ShowCategory5Screen(STR_WAP_SAVEFIFLE_ID,NULL,STR_GLOBAL_OK,
		NULL,STR_GLOBAL_BACK,NULL,
		INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
		InputContent_Edit,16,guiBuffer);
	
	set_left_softkey_label((UI_string_type)GetString(STR_GLOBAL_OK));
	show_left_softkey();

	SetLeftSoftkeyFunction(Browser_GetFilename, KEY_EVENT_UP);

	//end 退出浏览器
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
	
	SetCategory5RightSoftkeyFunction(Browser_SaveFileCancle,KEY_EVENT_UP);
}
/*==============================================================
*   Function Name:	Browser_SaveFileCancle
*   Input        :  void
*   Output       :  void
*   description  :	cancle to save file
*   author       :  
*   date         :
==============================================================*/
void Browser_SaveFileCancle(void)
{	
	if(DownLoad_DataBuf != NULL)
	{
		cms_free(DownLoad_DataBuf);
		DownLoad_DataBuf = NULL;
	}
	if(Option_Ok==1)
		GoBackHistory();	
	else
	{
		if(BorwserFormPush==1)//add by xiaoyongq 20060310 for bug 33625
		{
			BorwserFormPush=0;
			mmi_wap_option_exitbrowser();
			return;
		}
		ClearRefreshWhenGoPrev();//add by xiaoyongq 20061118
		GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
		Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDRAW);
	}	
}
/*==============================================================
*   Function Name:	RefreshEvent
*   Input        :  void
*   Output       :  void
*   description  :	relink the current connect url
*   author       :  
*   date         :
==============================================================*/
void RefreshEvent(void)
{
	Clear_FileToSave();/*清空变量，防止*/
	MainMenu_State = 12;
	GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
	Cms_Browser_PageRefreshEvent();	
}
/*==============================================================
*   Function Name:	Browser_GetFilename
*   Input        :  void
*   Output       :  void
*   description  :	get input filename and save the file
*   author       :  
*   date         :
*   modfiy         : by yangjun 05-11-8 change the type macro
==============================================================*/
void Browser_GetFilename(void)
{
	char *fname_uni = NULL;
	char pathname[150]={0};
	char fname[150] ={0};
	unsigned char * p;
	int         flag=0;
   	unsigned short unic;
	
	if(pfnUnicodeStrlen((S8*)InputContent_Edit) == 0)
	{
		DisplayPopup((U8*)GetString(STR_WAP_INVALID_FILE_NAME), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	for(p = (unsigned char *)InputContent_Edit;  !(*p == 0 && *(p+1) == 0); p += 2 )
	{
		unic = *p + (*(p+1) << 8);
		if ((unic==';') || (unic=='/') || (unic=='\\') ||
		(unic=='?') || (unic==':') || (unic=='@') ||
		(unic=='&') || (unic=='$') || (unic=='=') || 
		(unic=='+') || (unic==',') || (unic=='|') ||
		(unic=='<') || (unic=='>') || (unic=='"') ||
		(unic=='%' )|| (unic==' ') ||(unic=='.')) 
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		DisplayPopup((U8*)GetString(STR_WAP_INVALID_FILE_NAME), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;		
	}
	//chaozhu.zhou 2006.11.1 modify for save data path
	fname_uni = (char *)Cms_mms_uni16_8((char *)InputContent_Edit);
	cms_strncat(fname, (const char*)fname_uni,64);
	switch(DownLoad_FileType) 
	{
	case CMS_HTTP_CONTENT_GIF:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PIC_PATH);
		strcat(fname, ".gif");
		break;
	
	case CMS_HTTP_CONTENT_JPEG:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PIC_PATH);
		strcat(fname, ".jpg");
		break;
	
	case CMS_HTTP_CONTENT_WBMP:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PIC_PATH);
		strcat(fname, ".wbmp");
		break;
	
	case CMS_HTTP_CONTENT_BMP:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PIC_PATH);
		strcat(fname, ".bmp");
		break;
	
	case CMS_HTTP_CONTENT_PNG:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PIC_PATH);
		strcat(fname, ".png");
		break;
	
	case CMS_HTTP_CONTENT_MSVG:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PIC_PATH);
		strcat(fname, ".msv");
		break;
	
	case CMS_HTTP_CONTENT_MIDI:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_MUSIC_PATH);
		strcat(fname, ".mid");
		break;
	
	case CMS_HTTP_BROWSER_MUSIC_SMAF:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_MUSIC_PATH);
		strcat(fname, ".smaf");
		break;
	
	case CMS_HTTP_CONTENT_IMY: //待加 2005-11-8
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_MUSIC_PATH);
		strcat(fname, ".imy");
		break;
	case CMS_HTTP_CONTENT_X_WAVE: //待加 2005-11-10
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_MUSIC_PATH);
		strcat(fname, ".wav");
		break;

	case CMS_HTTP_CONTENT_3GP:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_VIDEO_PATH);
		strcat(fname, ".3gp");
		break;

	case CMS_HTTP_CONTENT_AAC: //待加 2005-11-10
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_MUSIC_PATH);
		strcat(fname, ".aac");
		break;
	case CMS_HTTP_CONTENT_MPEG4: //待加 2005-11-10
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_VIDEO_PATH);
		strcat(fname, ".mpeg");
		break;

	case CMS_HTTP_CONTENT_MP3: //待加 2005-11-10
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_MUSIC_PATH);
		strcat(fname, ".mp3");
		break;

	case CMS_HTTP_CONTENT_AMR:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_MUSIC_PATH);
		strcat(fname, ".amr");
		break;
	
	case CMS_HTTP_CONTENT_FJAD:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PATH);
		strcat(fname, ".jad");
		break;
	
	case CMS_HTTP_CONTENT_FJAR:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PATH);
		strcat(fname, ".jar");
		break;
	
	case CMS_HTTP_CONTENT_DLING_FILE:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PIC_PATH);
		strcat(fname, ".gif");
		break;
	
	case CMS_HTTP_CONTENT_DLING_IMG:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PIC_PATH);
		strcat(fname, ".img");
		break;

	case CMS_HTTP_CONTENT_DLFAILED:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PIC_PATH);
		strcat(fname, ".gif");
		break;

	case CMS_HTTP_CONTENT_CHAOTEX_CIM:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PATH);
		strcat(fname, ".wdf");
		break;

	//20060725 yangjun add
	case CMS_HTTP_CONTENT_DZD:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PATH);
		strcat(fname, ".dzd");
		break;
	//20070105 chaozhu.zhou add for lenovo kjj
	case CMS_HTTP_CONTENT_IMAGE_KJJ:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PATH);
		strcat(fname, ".kjj");
		break;		
	case CMS_HTTP_CONTENT_DRM_MESSAGE:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PATH);
		strcat(fname, ".DM");
		break;	
	case CMS_HTTP_CONTENT_DRM_CONTENT:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PATH);
		strcat(fname, ".DCF");
		break;
	case CMS_HTTP_CONTENT_DRM_RIGHTS_XML:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PATH);
		strcat(fname, ".DR");
		break;
	case CMS_HTTP_CONTENT_DRM_RIGHTS_WBXML:
		cms_strcpy(pathname, (const char*)CMS_WAP_DOWNLOAD_PATH);
		strcat(fname, ".DRC");
		break;
	default:
		break;
	}

	cms_strcat(pathname,fname);
	cms_memset(fname,0,sizeof(fname));
	cms_strcpy(fname,pathname);
	
	if (Cms_Adp_FileExists(fname))
	{
		cms_free(fname_uni);
		fname_uni = NULL;
		DisplayPopup((U8*)GetString(STR_WAP_DUPLICATE_FILENAME), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);	
		return;
	}
	else
	{
		int fh = NULL;
		fh = Cms_Adp_fopen((S8*)fname, FS_CREATE_ALWAYS);
		if(fh < 0)
		{
			cms_free(fname_uni);
			fname_uni = NULL;
			wap_Tracer((char *)"save file name invalid");
			DisplayPopup((U8*)GetString(STR_WAP_CANNOT_CREATE_FILE), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
			return;
		}
		else
		{
			unsigned int nwrite=0;
			if(Cms_Adp_JudgeDSpace((int)DownLoad_DataLen))	
			{
				cms_free(fname_uni);
				fname_uni = NULL;
				Cms_Adp_fclose(fh);
				wap_Tracer((char *)"Save music: not enough storage!");
				DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				return;		
			}			
			Cms_Adp_fwrite(fh,DownLoad_DataBuf, DownLoad_DataLen, &nwrite);
			Cms_Adp_fclose(fh);
			DisplayPopup((U8*)GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
			cms_free(fname_uni);
			fname_uni = NULL;
		}
	}
	
	if(DownLoad_DataBuf != NULL)
	{
		cms_free(DownLoad_DataBuf);
		DownLoad_DataBuf = NULL;
	}		
	if(Option_Ok==1)
	{
		GoBackToHistory(SCR_ID_WAPOPTION_MAIN_MENU);
	}
	else
	{
		if(BorwserFormPush==1)//add by xiaoyongq 20060107 for bug 30688
		{
			BorwserFormPush=0;
			mmi_wap_option_exitbrowser();
			return;
		}
		BorwserFormPush=0;
		ClearRefreshWhenGoPrev();//add by xiaoyongq 20061118
		GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
		Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDRAW);
	}
	
}
/*==============================================================
*   Function Name:	Cms_LoadBookMarkFile
*   Input        :  void
*   Output       :  void
*   description  :	load bookmark file to virtual file 
*   author       : 
*   date         :
==============================================================*/
void Cms_LoadBookMarkFile(void)
{
	int cmsbookfd;
	int mtkbookfd = 0;
	unsigned char *tempbuf;
	unsigned int nread;
	unsigned int size;
	wap_Tracer("==Cms_LoadBookMarkFile=");
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapBookfilename(wap_filename);
	mtkbookfd = Cms_Adp_fopen((S8*)wap_filename, FS_READ_ONLY);
	//mtkbookfd = FS_Open(L"C:\\wap\\CmsBook.cnf",FS_READ_ONLY);
	if (mtkbookfd < 0)
	{
		wap_Tracer("read BookMark failed");
		return;
	}
	FS_GetFileSize(mtkbookfd, &size);
	tempbuf = (unsigned char *)cms_malloc(size);
	if (tempbuf == NULL)
	{
		FS_Close(mtkbookfd);
		return;
	}
	memset(tempbuf, 0, size);
	FS_Read(mtkbookfd, tempbuf, size, &nread);	
	cmsbookfd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)"D:\\cmswapfile\\cmsbook.cnf", CMS_FILE_WRITEONLY);
	if (cmsbookfd > 0)
	{
		Cms_Browser_FileWrite(tempbuf, size, 1, cmsbookfd);
		Cms_Browser_FileClose(cmsbookfd);
	}
	else
	{
		wap_Tracer("open cmsbook virtual failed");
	}
	cms_free(tempbuf);
	FS_Close(mtkbookfd);
}
/*==============================================================
*   Function Name:	Cms_LoadSetupFile
*   Input        :  void
*   Output       :  void
*   description  :	load setup file to virtual file 
*   author       :  
*   date         :
==============================================================*/
void Cms_LoadSetupFile(void)
{
	int cmssetupfd;
	int mtksetupfd = NULL;
	unsigned char *tempbuf;
	unsigned int nread;
	unsigned int size;
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapSetupfilename(wap_filename);	
	mtksetupfd = Cms_Adp_fopen((S8*)wap_filename, FS_READ_ONLY);
	//mtksetupfd = FS_Open(L"C:\\wap\\CmsSetup.cnf",FS_READ_ONLY);
	if (mtksetupfd < 0)
	{
		return;
	}
	FS_GetFileSize(mtksetupfd, &size);
	tempbuf = (unsigned char *)cms_malloc(size);
	if (tempbuf == NULL)
	{
		FS_Close(mtksetupfd);
		return;
	}
	memset(tempbuf, 0, size);
	FS_Read(mtksetupfd, tempbuf, size, &nread);	

	cmssetupfd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)"D:\\cmswapfile\\cmssetup.cnf", CMS_FILE_WRITEONLY);
	if (cmssetupfd > 0)
	{
		Cms_Browser_FileWrite(tempbuf, size, 1, cmssetupfd);
		Cms_Browser_FileClose(cmssetupfd);
	}
	cms_free(tempbuf);
	FS_Close(mtksetupfd);
}

/*==============================================================
*   Function Name:	Cms_LoadPushFile
*   Input        :  void
*   Output       :  void
*   description  :	load push file to virtual file
*   author       :  
*   date         :
==============================================================*/
void Cms_LoadPushFile(void)
{
	int cmspushfd;
	int mtkpushfd = NULL;
	unsigned char *tempbuf;
	unsigned int nread;
	unsigned int size;
	int mtkfsret;
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapPushfilename(wap_filename);	
	mtkpushfd = Cms_Adp_fopen((S8*)wap_filename, FS_READ_ONLY);
	//mtkpushfd = FS_Open(L"C:\\wap\\CmsPushFile.cnf",FS_READ_ONLY);
	browser_mmi_tracer("mtkpushfd Cms_LoadPushFile = %d", mtkpushfd);
	
	if (mtkpushfd < 0)
	{
		return;
	}
	
	mtkfsret = FS_GetFileSize(mtkpushfd, &size);
	browser_mmi_tracer("Cms_LoadPushFile  size= %d", size);
	if(mtkfsret == FS_NO_ERROR)
	{
		tempbuf = (unsigned char *)cms_malloc(size);
		if (tempbuf == NULL)
		{
			FS_Close(mtkpushfd);
			return;
		}
		memset(tempbuf, 0, size);
		mtkfsret = FS_Read(mtkpushfd, tempbuf, size, &nread);
		if(mtkfsret == FS_NO_ERROR)
		{
			cmspushfd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)"D:\\cmswapfile\\cmspushfile.cnf", CMS_FILE_WRITEONLY);
			if (cmspushfd > 0)
			{
				Cms_Browser_FileWrite(tempbuf, size, 1, cmspushfd);
				Cms_Browser_FileClose(cmspushfd);
			}
		}
	}
	cms_free(tempbuf);
	FS_Close(mtkpushfd);
}
/*==============================================================
*   Function Name:	Cms_SaveBookMarkFile
*   Input        :  void
*   Output       :  void
*   description  :	save bookmark virtual file to file
*   author       :  
*   date         :
==============================================================*/
void Cms_SaveBookMarkFile(void)
{
	int cmsbookfd;	
	int writeLen=0;
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapBookfilename(wap_filename);
	Cms_Adp_fdelete((const unsigned short *) wap_filename);
	//FS_Delete(L"C:\\wap\\CmsBook.cnf");
	cmsbookfd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)"D:\\cmswapfile\\cmsbook.cnf", CMS_FILE_READONLY);
	if (cmsbookfd > 0)
	{
		int filelen = 0;
		filelen = Cms_Browser_GetFileLength(cmsbookfd);
		if (filelen > 0)
		{
			unsigned char *tempbuf;
			unsigned int nwrite;
			int mtkbookfd = NULL;
			mtkbookfd = Cms_Adp_fopen((S8*)wap_filename, FS_CREATE);
			//mtkbookfd = FS_Open(L"C:\\wap\\CmsBook.cnf",FS_CREATE);
			if (mtkbookfd < 0)
			{
				wap_Tracer("mtkbookfd<0");
				return;
			}
			tempbuf = (unsigned char *)cms_malloc(filelen);
			memset(tempbuf, 0, filelen);
			Cms_Browser_FileRead(tempbuf, filelen, 1, cmsbookfd);
			if(Cms_Adp_JudgeCSpace((int)filelen))	
			{
				FS_Close(mtkbookfd);
				DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				return;		
			}
			writeLen=FS_Write(mtkbookfd, tempbuf, (unsigned int)filelen, &nwrite);
			cms_free(tempbuf);
			FS_Close(mtkbookfd);
			Cms_Browser_FileClose(cmsbookfd);
		}
		else
			wap_Tracer("file len <0");
	}
	else
	{
		wap_Tracer("Save bookmark failed cmsbookfd <=0");
	}
}
/*==============================================================
*   Function Name:	Cms_SaveSetupFile
*   Input        :  void
*   Output       :  void
*   description  :	save setup virtual file to file
*   author       :  
*   date         :
==============================================================*/
void Cms_SaveSetupFile(void)
{
	int cmssetupfd;
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapSetupfilename(wap_filename);	
	Cms_Adp_fdelete((const unsigned short *) wap_filename);
	//FS_Delete(L"C:\\wap\\CmsSetup.cnf");
	cmssetupfd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)"D:\\cmswapfile\\cmssetup.cnf", CMS_FILE_READONLY);
	if (cmssetupfd > 0)
	{
		int filelen = 0;
		filelen = Cms_Browser_GetFileLength(cmssetupfd);
		if (filelen > 0)
		{
			unsigned char *tempbuf;
			unsigned int nwrite;
			int mtksetup = NULL;
			mtksetup = Cms_Adp_fopen((S8*)wap_filename, FS_CREATE);
			//mtksetup = FS_Open(L"C:\\wap\\CmsSetup.cnf",FS_CREATE);
			if (mtksetup < 0)
			{
				Cms_Browser_FileClose(cmssetupfd);
				return;
			}
			tempbuf = (unsigned char *)cms_malloc(filelen+1);
			memset(tempbuf, 0, filelen);
			Cms_Browser_FileRead(tempbuf, filelen+1, 1, cmssetupfd);
	
			FS_Write(mtksetup, tempbuf, (unsigned int)filelen+1, &nwrite);
			cms_free(tempbuf);
			FS_Close(mtksetup);
			Cms_Browser_FileClose(cmssetupfd);
		}
		else
		{
			Cms_Browser_FileClose(cmssetupfd);
		}
	}
}
/*==============================================================
*   Function Name:	Cms_SavePushFile
*   Input        :  void
*   Output       :  void
*   description  :	save push virtual file to file
*   author       :  
*   date         :
==============================================================*/
void Cms_SavePushFile(void)
{
	int cmspushfd;
	int mtkfsret;
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapPushfilename(wap_filename);	
	Cms_Adp_fdelete((const unsigned short * )wap_filename);
	//FS_Delete(L"C:\\wap\\CmsPushFile.cnf");
	wap_Tracer("Cms_SavePushFile");
	cmspushfd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)"D:\\cmswapfile\\cmspushfile.cnf", CMS_FILE_READONLY);
	browser_mmi_tracer("cmspushfd cmspushfd = %d", cmspushfd);
	if (cmspushfd > 0)
	{
		int filelen = 0;
		filelen = Cms_Browser_GetFileLength(cmspushfd);
		if (filelen > 0)
		{
			unsigned char *tempbuf;
			unsigned int nwrite;
			int mtkpushfd = NULL;

			mtkpushfd = Cms_Adp_fopen((S8*)wap_filename, FS_CREATE);
			//mtkpushfd = FS_Open(L"C:\\wap\\CmsPushFile.cnf",FS_CREATE);
			if (mtkpushfd > 0)
			{
				tempbuf = (unsigned char *)cms_malloc(filelen);
				if(tempbuf == NULL)
				{
					FS_Close(mtkpushfd);
					Cms_Browser_FileClose(cmspushfd);
					return;
				}
				
				memset(tempbuf, 0, filelen);
				Cms_Browser_FileRead(tempbuf, filelen, 1, cmspushfd);
				if(Cms_Adp_JudgeCSpace((int)filelen))	
				{
					FS_Close(mtkpushfd);
					DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
					return;		
				}				
				mtkfsret= FS_Write(mtkpushfd, tempbuf, (unsigned int)filelen, &nwrite);
				if(mtkfsret != FS_NO_ERROR)
				{
					//FS_Delete(L"C:\\wap\\CmsPushFile.cnf");
					cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
					Cms_GetWapPushfilename(wap_filename);	
					Cms_Adp_fdelete((const unsigned short * )wap_filename);
				}
				cms_free(tempbuf);
				tempbuf = NULL;
				FS_Close(mtkpushfd);
			}
			Cms_Browser_FileClose(cmspushfd);
		}
	}
}

/*==============================================================
Event:lastlink/nextlink/linkmessage ect
===============================================================*/
/*==============================================================
*   Function Name:	brw_GetResourceByID
*   Input        :  int id
*   Output       :  void
*   description  :	get key statue
*   author       :  
*   date         :
==============================================================*/
unsigned char * brw_GetResourceByID(int id)
{
	browser_mmi_tracer(" brw_GetResourceByID Id = %d ", id);	
	ResourceValue_State	= id;
	MainMenu_State = 20;

	if( ( BrowserScreen_ID != SCR_ID_WAP_PAGEBROWSER_MENU ) || (CancleDownload == 1) )
	{
		wap_Tracer((char *)"bge");
		return NULL;
	}	
	
	switch(id)
	{
	case CMS_STR_RESOURCE_EMPTY:
		ResourceValue_State = CMS_STR_RESOURCE_EMPTY;
		if (SuspendFlag == 1)
		{
			break;
		}	
#ifdef WAP_BROWSER_OPTION_MODE1		
		//changed by yangjun 06-02-07 for left soft key display
		if(Cms_Browser_HasFocus() != CMS_BROWSER_TRUE)
			ChangeLeftSoftkey(NULL, IMG_GLOBAL_YES);
#endif		
		wap_Tracer("CMS_STR_RESOURCE_EMPTY");
		break;

	case CMS_STR_RESOURCE_BACK:
		wap_Tracer("CMS_STR_RESOURCE_BACK");
		break;

	case CMS_STR_RESOURCE_RETRY:
		ResourceValue_State = CMS_STR_RESOURCE_RETRY;
		if (SuspendFlag == 1)
		{
			break;
		}
		wap_Tracer("CMS_STR_RESOURCE_RETRY");
#ifdef WAP_BROWSER_OPTION_MODE1		
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeRightSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);		
		SetRightSoftkeyFunction(BrowserOption, KEY_EVENT_UP);
		SetLeftSoftkeyFunction(Cms_Browser_PageReLink, KEY_EVENT_UP);
#else
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);		
		SetLeftSoftkeyFunction(BrowserOption, KEY_EVENT_UP);
		SetRightSoftkeyFunction(Cms_Browser_PageReLink, KEY_EVENT_UP);
#endif
		SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);	
		return NULL;		

	case CMS_STR_RESOURCE_LINK:
		wap_Tracer("CMS_STR_RESOURCE_LINK");
		ResourceValue_State = CMS_STR_RESOURCE_LINK;
		if (SuspendFlag == 1)
		{
			break;
		}	
#ifdef WAP_BROWSER_OPTION_MODE1			
		if(Cms_Browser_HasFocus() == CMS_BROWSER_TRUE)
			ChangeLeftSoftkey(STR_WAP_LINK, IMG_GLOBAL_YES);
		else
			wap_Tracer("no link CMS_STR_RESOURCE_LINK");
#else
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);		
#endif
		break;
	case CMS_STR_RESOURCE_EDIT:
		ResourceValue_State = CMS_STR_RESOURCE_EDIT;
#ifdef WAP_BROWSER_OPTION_MODE1		
		ChangeLeftSoftkey(STR_WAP_EDIT, IMG_GLOBAL_YES);
#else
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
#endif
		wap_Tracer("CMS_STR_RESOURCE_EDIT");
		break;

	case CMS_STR_RESOURCE_SELECT:
		ResourceValue_State = CMS_STR_RESOURCE_SELECT;
#ifdef WAP_BROWSER_OPTION_MODE1			
		ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_YES);
		Cms_Brw_LeftSodtKeyReg();
#else
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
#endif		
		wap_Tracer("CMS_STR_RESOURCE_SELECT");
		break;

	case CMS_STR_RESOURCE_CANCLE:
		wap_Tracer("CMS_STR_RESOURCE_CANCLE");
		return NULL;

	case CMS_STR_RESOURCE_OK:
		ResourceValue_State = CMS_STR_RESOURCE_OK;
#ifdef WAP_BROWSER_OPTION_MODE1		
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
#endif
		Cms_Brw_LeftSodtKeyReg();
		wap_Tracer("CMS_STR_RESOURCE_OK");
		return NULL;

	case CMS_STR_RESOURCE_EXIT:
		wap_Tracer("CMS_STR_RESOURCE_EXIT");
		return NULL;

	default:
		return NULL;
	}

	if(SuspendFlag == 0)
	{
		browser_mmi_tracer("-----KeyStatue=%d",ResourceValue_State);		
		if(ResourceValue_State==CMS_STR_RESOURCE_EMPTY)
		{
			SetKeyHandler(NULL, KEY_SEND, KEY_EVENT_DOWN);
			SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
			SetKeyHandler(CMS_NextLinkFocusEvent, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
			SetKeyHandler(CMS_LastLinkFocusEvent, KEY_UP_ARROW, KEY_EVENT_DOWN);	
			/*注册侧键*/
			SetKeyHandler(CMS_NextLinkFocusEvent, KEY_VOL_DOWN, KEY_EVENT_DOWN);
			SetKeyHandler(CMS_LastLinkFocusEvent, KEY_VOL_UP, KEY_EVENT_DOWN);	

			SetKeyHandler(CMS_RightLinkFocusEvent, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
			SetKeyHandler(CMS_LeftLinkFocusEvent, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

			SetKeyHandler(Cms_Browser_PageUp, KEY_STAR, KEY_EVENT_DOWN);	
			SetKeyHandler(Cms_Browser_PageDown, KEY_POUND, KEY_EVENT_DOWN);	
		}
		else
		{
			SetKeyHandler(CMS_NextLinkFocusEvent, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
			SetKeyHandler(CMS_LastLinkFocusEvent, KEY_UP_ARROW, KEY_EVENT_DOWN);	
			/*注册侧键*/
			SetKeyHandler(CMS_NextLinkFocusEvent, KEY_VOL_DOWN, KEY_EVENT_DOWN);
			SetKeyHandler(CMS_LastLinkFocusEvent, KEY_VOL_UP, KEY_EVENT_DOWN);	
			SetKeyHandler(CMS_RightLinkFocusEvent, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
			SetKeyHandler(CMS_LeftLinkFocusEvent, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
			
			SetKeyHandler(GoLinkFocusEventByKey, KEY_SEND, KEY_EVENT_UP);
			SetKeyHandler(GoLinkFocusEventByKey, KEY_ENTER, KEY_EVENT_UP);
			
			SetKeyHandler(Cms_Browser_PageUp, KEY_STAR, KEY_EVENT_DOWN);	
			SetKeyHandler(Cms_Browser_PageDown, KEY_POUND, KEY_EVENT_DOWN);	
		}
		
	}
	return NULL;
}
void TipMessageBoxExit(void)
{
	wap_Tracer("TipMessageBoxExit==1");
       cms_bPostMessageFlag=1;
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			NULL, NULL,
			(UI_string_type)GetString(STR_WAP_FAILURE_MEM_CAP_EXCEEDED),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(ExitWapBrowserByKey, KEY_EVENT_UP);
}
/*==============================================================
*   Function Name:	DevDeactivate
*   Input        :  void
*   Output       :  void
*   description  :	back to main menu if back when current page is the last page
*   author       :  
*   date         :
==============================================================*/
void DevDeactivate(void)
{
	Option_Ok=0;
	BrowserScreen_ID = -1;
	Cms_Browser_StopBrowserTimer();
	Cms_StopMusic();
	Cms_Browser_ClearAllHistory();
	ClearAllMarqueeMovie();
	if(1 == CmsIsImgStackDL())
		CmsAbortDownload();
	
	
	Cms_Browser_PostMessage(1385);//CMS_MESSAGE_BROWSERDEVDEACTIVEATE);

	#if 0
	if(BrowserByHotkey==1)
	{
		wap_Tracer("DevDeactivate==1");
		BackToIdle=1;
		DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_WAP_CANCLE_CONFIRM),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
		SetLeftSoftkeyFunction(ExitWapBrowserByKey, KEY_EVENT_UP);
		SetRightSoftkeyFunction(OptionRefreshCurrentPageEvent, KEY_EVENT_UP);
	}	
#ifdef SUPPORT_SMSMMS_COMBINE
	else if(MMSPushByBrowser==1)
	{
		wap_Tracer("MMSPushByBrowser==1");	
		if (browserflag == 1)
		{
			Cms_Browser_SavePUSH();
			Cms_Browser_FreePUSHInfo();
			Cms_Browser_SaveBrowserSetupToFile();
			Cms_SaveFile();
			Cms_Browser_ExitEvent();
			Cms_close_soc(2);
			browserflag = 0;
		}	 
		
		if ( IsScreenPresent( SCR_ID_MMS_INBOX))
			DeleteUptoScrID(SCR_ID_MMS_INBOX);
		GoBackHistory();//changed by halice yang 060306 for bug 33510 
	}
#endif
	else
	{
		Option_Ok=0;//changed by yangjun 060801 for save data box
		wap_Tracer("DevDeactivate==0");
		BackToMainMenuEvent();
	}	
	return;
	#endif
}

void OptExitBrowser(void)
{
	if(BrowserByHotkey==1)
	{
		wap_Tracer("DevDeactivate==1");
		BackToIdle=1;
		DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_OK,
			STR_GLOBAL_NO, IMG_GLOBAL_BACK,
			(UI_string_type)GetString(STR_WAP_CANCLE_CONFIRM),
			IMG_GLOBAL_QUESTION, WARNING_TONE);
		SetLeftSoftkeyFunction(ExitWapBrowserByKey, KEY_EVENT_UP);
		SetRightSoftkeyFunction(OptionRefreshCurrentPageEvent, KEY_EVENT_UP);
	}	
#ifdef SUPPORT_SMSMMS_COMBINE
	else if(MMSPushByBrowser==1)
	{
		wap_Tracer("MMSPushByBrowser==1");	
		if (browserflag == 1)
		{
			Cms_Browser_SavePUSH();
			Cms_Browser_FreePUSHInfo();
			Cms_Browser_SaveBrowserSetupToFile();
			Cms_SaveFile();
			Cms_Browser_ExitEvent();
			Cms_close_soc(2);
			browserflag = 0;
		}	 
		
		if ( IsScreenPresent( SCR_ID_MMS_INBOX))
			DeleteUptoScrID(SCR_ID_MMS_INBOX);
		GoBackHistory();//changed by halice yang 060306 for bug 33510 
	}
#endif
	else
	{
		Option_Ok=0;//changed by yangjun 060801 for save data box
		wap_Tracer("DevDeactivate==0");
		BackToMainMenuEvent();
	}	
	return;
}
/*==============================================================
*   Function Name:	GoLinkFocusEventByKey
*   Input        :  void
*   Output       :  void
*   description  :	link appointed foucs by sendkey or enterkey
*   author       :  
*   date         :
==============================================================*/
void GoLinkFocusEventByKey(void)
{	
	if(cms_bPostMessageFlag==1)
		return;
	if(Cms_Browser_HasFocus() == CMS_BROWSER_TRUE) 
	{
		SetKeyHandler(NULL, KEY_SEND, KEY_EVENT_DOWN);
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
		
		SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_DOWN);
		SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_DOWN);	
		Cms_Browser_LinkPageMessage();
		Cms_GetSoftKey(0);
	}
}
/*==============================================================
*   Function Name:	Cms_Browser_AccessKeyEvent
*   Input        :  void
*   Output       :  void
*   description  :	快捷连接
*   author       :  
*   date         :
==============================================================*/
void Cms_Browser_AccessKeyEvent(void)
{
	unsigned int keyCode = 0;
	unsigned int keyType = 0; 	
	CMS_BROWSER_U8 Access_Key[3];
	if(cms_bPostMessageFlag==1)
		return;
	cms_memset(Access_Key,0x0,3);
	GetkeyInfo((U16*)&keyCode, (U16*)&keyType);
	sprintf((char *)(Access_Key),"%d",keyCode);
	if(CMS_BROWSER_TRUE == Cms_Browser_AccessKey(Access_Key))
	{
		SetKeyHandler(NULL, KEY_SEND, KEY_EVENT_DOWN);
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
		SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
		SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);	
		/*注册侧键*/
		SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_DOWN);
		SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_DOWN);	
		SetKeyHandler(NULL, KEY_STAR, KEY_EVENT_DOWN);	
		SetKeyHandler(NULL, KEY_POUND, KEY_EVENT_DOWN);	
		Browser_Enter();
	}
}
/*==============================================================
*   Function Name:	Cms_NextLinkFocusEvent
*   Input        :  void
*   Output       :  void
*   description  :	select next focus
*   author       :  
*   date         :
==============================================================*/
void CMS_NextLinkFocusEvent(void)
{
	NextLinkFocusEvent();
	//Cms_Browser_PostMessage(1325);//CMS_MESSAGE_BROWSERNEXTLINKFOCUS);
}
/*==============================================================
*   Function Name:	CMS_LastLinkFocusEvent
*   Input        :  void
*   Output       :  void
*   description  :	select last focus
*   author       :
*   date         :
==============================================================*/
void CMS_LastLinkFocusEvent(void)
{
	LastLinkFocusEvent();
	//Cms_Browser_PostMessage(1326);//CMS_MESSAGE_BROWSERLASTLINKFOCUS);
}
/*==============================================================
*   Function Name:	CMS_RightLinkFocusEvent
*   Input        :  void
*   Output       :  void
*   description  :	select rightt focus
*   author       :  
*   date         :
==============================================================*/
void CMS_RightLinkFocusEvent(void)
{
	Cms_Browser_PostMessage(1327);//MSG_ID_CMS_WAP_RIGHTLINKFOCUS);
}
/*==============================================================
*   Function Name:	CMS_LeftLinkFocusEvent
*   Input        :  void
*   Output       :  void
*   description  :	select Left focus
*   author       :
*   date         :
==============================================================*/
void CMS_LeftLinkFocusEvent(void)
{
	Cms_Browser_PostMessage(1328);//MSG_ID_CMS_WAP_LEFTLINKFOCUS);
}
/*==============================================================
*   Function Name:	NextLinkFocusEvent
*   Input        :  void
*   Output       :  void
*   description  :	select next link foucs implement
*   author       :  
*   date         :
==============================================================*/
void NextLinkFocusEvent(void)
{
       if(cms_bPostMessageFlag==1)
		return;
	SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN); //add by xiaoyongq 20061212	
	Cms_Browser_NextLinkFocusEvent();
}


void Brw_Keystar_Uppage()
{
	SetKeyHandler(NULL, KEY_STAR, KEY_EVENT_DOWN);	
	Cms_Browser_PageUp();	
}

void Brw_Keystar_Downpage()
{
	SetKeyHandler(NULL, KEY_POUND, KEY_EVENT_DOWN);	
	Cms_Browser_PageDown();	
}
/*==============================================================
*   Function Name:	LastLinkFocusEvent
*   Input        :  void
*   Output       :  void
*   description  :	select last link foucs implement
*   author       :  
*   date         :
==============================================================*/
void LastLinkFocusEvent(void)
{
	if(cms_bPostMessageFlag==1)
		return;
	SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
	Cms_Browser_LastLinkFocusEvent();	
}
/*==============================================================
*   Function Name:	LastLinkFocusEvent
*   Input        :  void
*   Output       :  void
*   description  :	select last link foucs implement
*   author       :  
*   date         :
==============================================================*/
void RightLinkFocusEvent(void)
{
	if(cms_bPostMessageFlag==1)
		return;
	CmsBrwMoveLinkFocus(4);
}
/*==============================================================
*   Function Name:	LastLinkFocusEvent
*   Input        :  void
*   Output       :  void
*   description  :	select last link foucs implement
*   author       :  
*   date         :
==============================================================*/
void LeftLinkFocusEvent(void)
{
	if(cms_bPostMessageFlag==1)
		return;
	CmsBrwMoveLinkFocus(3);
}
/*==============================================================
*   Function Name:	Cms_Browser_LinkPageMessage
*   Input        :  void
*   Output       :  void
*   description  :	notify MTK when browser is download net page
*   author       :  
*   date         :
==============================================================*/
void Cms_Browser_LinkPageMessage(void)
{
	//add 页面内操作流程
	if(cms_Brw_GetPageinEle()==1)
	{
		return ;
	}
	else
	{
		//if(Cms_IsFirstURL()==1)/*根据客户建议每次打开页面都刷新标题*/
	  	{
	  		ChangeTitle(IMG_WAPDOWNLOADING_MAIN_MENU_ICON, (U8*)GetString(STR_WAP_PAGELINK_ID));
			draw_title();
		}
		MainMenu_State=12;//xiaoyongq 20060404 for bug 34684
		Down_Scrollbar_OK = 1;// 20060925 wantaol 屏蔽滚动条(链接时)
		wap_Tracer((char *)"Cms_Browser_LinkPageMessage");
		ChangeRightSoftkey(STR_GLOBAL_CANCEL, IMG_GLOBAL_BACK);
		SetRightSoftkeyFunction(Cms_Brw_CancelPageDownload, KEY_EVENT_UP);

		//屏蔽左软键操作
		ChangeLeftSoftkey(NULL, NULL);
		SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	}
}
/*==============================================================
*   Function Name:	Cms_Browser_PageLinkReturn
*   Input        :  void
*   Output       :  void
*   description  :	link prev page when retry back
*   author       :  
*   date         :
==============================================================*/
void Cms_Browser_PageLinkReturn(void)
{
	MainMenu_State = 12;

	GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);	
	Cms_Browser_GoPrevURIEvent();	
	return;
}
/*==============================================================
*   Function Name:	Cms_Browser_PageReLink
*   Input        :  void
*   Output       :  void
*   description  :	page retry link when page download failed
*   author       :  
*   date         :
==============================================================*/
void Cms_Browser_PageReLink(void)
{
	MainMenu_State = 12;
	if(cms_bPostMessageFlag==1)
		return;
	GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
	SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
	/*注册侧键*/
	SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_DOWN);
	SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
	SetKeyHandler(NULL, KEY_STAR, KEY_EVENT_DOWN);	
	SetKeyHandler(NULL, KEY_POUND, KEY_EVENT_DOWN);	
	Browser_Enter();
 	Cms_GetSoftKey(0);
}
/*==============================================================
*   Function Name:	Cms_Browser_SendMail
*   Input        :  void
*   Output       :  void
*   description  :	browser transfer MTK Send Email interface
*   author       :  cocoma xu
*   date         :
==============================================================*/
void Cms_Browser_SendMail(void)
{
#ifdef SUPPORT_EMAIL_APPLICATION	
	P_CMS_APPLICATION_DATA appdata = NULL;
	wap_Tracer((char *)"Cms_Browser_SendMail in");
	appdata = cms_malloc(sizeof(CMS_APPLICATION_DATA));
	if (appdata == NULL)
	{
		return;
	}
	if(Cms_Browser_GetApplicationData(appdata,  CMS_EMAIL))
	{
		U8 strEmail[128] = {0};
		P_CMS_BROWSER_U8 CmsEmail;
		int i = 0;
		int j;
		MainMenu_State = 11;
		CmsEmail = appdata->Cms_MAIL_Address;
		
		while (NULL != *(CmsEmail+i)) 
		{
			j = i*2;
			strEmail[j] = *(CmsEmail+i);
			i = i+1;
		}
		DisplayPopup((PU8)GetString(STR_WAP_APPLICATION_NOT_SUPPORT), IMG_GLOBAL_WARNING, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
		/*如支持Email可在此完善应用*/
	}
	cms_free(appdata->Cms_MAIL_Address);
	cms_free(appdata);
#else
	DisplayPopup((PU8)GetString(STR_WAP_APPLICATION_NOT_SUPPORT), IMG_GLOBAL_WARNING, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
	return;
#endif
}
/*==============================================================
*   Function Name:	Cms_Browser_CallRequest
*   Input        :  void
*   Output       :  void
*   description  :	browser transfer MTK call interface
*   author       :  cocoma xu
*   date         :
==============================================================*/
U8 strPhonenumber[100] = {0};

void Cms_Browser_CallRequest(void)
{
	P_CMS_APPLICATION_DATA appdata = NULL;
	appdata = cms_malloc(sizeof(CMS_APPLICATION_DATA));
	if (appdata == NULL)
	{
		return;
	}

	if(Cms_Browser_GetApplicationData(appdata,  CMS_WTA))
	{		
		P_CMS_BROWSER_U8 CmsPhonenumber;
		int i = 0;
		int j = 0;
		MainMenu_State = 11;
		cms_memset(strPhonenumber,0x0,100);
		CmsPhonenumber = appdata->Cms_WTAI_Phonenumber;
		
		while (NULL != *(CmsPhonenumber+i)) 
		{
			j = i*2;
			strPhonenumber[j] = *(CmsPhonenumber+i);
			i = i+1;
		}	
		
		MakeCall( (PS8)(strPhonenumber));
	}
	cms_free(appdata->Cms_WTAI_Phonenumber);
	cms_free(appdata);


}
/*==============================================================
*   Function Name:	Cms_Browser_StorePhonenum
*   Input        :  void
*   Output       :  void
*   description  :browser transfer MTK Store Phone Num Interface
*   author       :  cocoma xu
*   date         :
==============================================================*/
void Cms_Browser_StorePhonenum(void)
{
	P_CMS_APPLICATION_DATA appdata = NULL;
	int     is_phonenum = 1;
	
	appdata = cms_malloc(sizeof(CMS_APPLICATION_DATA));

	if (appdata == NULL)
	{
		return;
	}

	if( Cms_Browser_GetWTAPhoneNumber(appdata) )
	{
		U8 strPhonenumber[100] = {0};
		P_CMS_BROWSER_U8 CmsPhonenumber;
		int i = 0;
		int j=0;
		MainMenu_State = 11;
		CmsPhonenumber = appdata->Cms_WTAI_Phonenumber;

		for(i=0;i<strlen((char *)(CmsPhonenumber));i++)
		{
			if(*(CmsPhonenumber+ i) < '0' || *(CmsPhonenumber + i) > '9')
			{
				is_phonenum = 0;
				break;
			}
		}

		if(is_phonenum)
		{
            		i=0;//add by xiaoyongq 200611007
			while (NULL != *(CmsPhonenumber+i) && j<100) 
			{
				j = i*2;
				strPhonenumber[j] = *(CmsPhonenumber+i);
				i = i+1;
			}
			SaveNumberFromIdleScrn((PS8)strPhonenumber, 0);/*存储号码*/
		}
		else
		{
			DisplayPopup((PU8)GetString(STR_WAP_APPLICATION_NOT_SUPPORT), IMG_GLOBAL_WARNING, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
		}
	}
	cms_free(appdata->Cms_WTAI_Phonenumber);
	cms_free(appdata);
}

/*================================================================
								image  function						
================================================================*/

/*==============================================================
*   Function Name:	Cms_DrawErrorImg
*   Input        :  CMS_BROWSER_U32 x
					CMS_BROWSER_U32 y
*   Output       :  void
*   description  :	show fail image to not image download failed
*   author       : 
*   date         :
==============================================================*/
void Cms_DrawErrorImg(int x, int y)
{
	if (SuspendFlag == 1)
	{
		return;
	}
	pixtel_UI_show_image(x, y, (UI_image_type)GetImage(IMG_WAPIMGDOWNLOAD_MAIN_MENU_ICON));
	return;
}
/*==============================================================
*   Function Name:	CmsPlayWbmp
*   Input        :  char *filename
					int x
					int y
*   Output       :  void
*   description  :	show specify wbmp
*   author       : 
*   date         :
==============================================================*/
void CmsPlayWbmp(char *filename, int x, int y, int display_width, int display_height)
{
	CMS_BROWSER_FILEHANDLE fd = NULL;
	P_CMS_BROWSER_U8 ImageBuf = NULL;
	int len =0;
	S32 image_width,image_height,resized_width,resized_height;
	
	GDI_RESULT result = 0;	
	
	if (SuspendFlag == 1)
	{
		return;
	}

#ifdef NO_SHOW_STATEBAR
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#else	
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif
	fd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)filename,CMS_FILE_READONLY);
	
	browser_mmi_tracer((char *)"CmsPlayWbmp filename = %s", filename);
	browser_mmi_tracer((char *)"CmsPlayWbmp display_width = %d", display_width);
	browser_mmi_tracer((char *)"CmsPlayWbmp display_height = %d", display_height);
	if (fd)
	{
		len = Cms_Browser_GetFileLength(fd);
		if (len > 0)
		{
			ImageBuf = cms_malloc(len+1);
			if (ImageBuf == NULL)
			{
				return;
			}
			cms_memset(ImageBuf, 0, len+1);
			Cms_Browser_FileRead((P_CMS_BROWSER_U8)ImageBuf, 1, len+1, fd);			
			Cms_Browser_FileClose(fd);
		}
		else
		{
			return;
		}
		
	}
	else
	{
		return; 
	}

	result = gdi_image_wbmp_get_dimension(ImageBuf, &image_width, &image_height);

	if ((image_width>PAGEDISPLAY_W) ||(image_height>PAGEDISPLAY_H))
	{
		//if((image_width/PAGEDISPLAY_W) >(image_height/PAGEDISPLAY_H))
		//changed by yangjun 060215 for changed the pic display error
		if((float)((float)image_width/(float)PAGEDISPLAY_W) >(float)((float)image_height/(float)PAGEDISPLAY_H))
		{
			resized_width = PAGEDISPLAY_W;
			resized_height = image_height*PAGEDISPLAY_W/image_width;
		}
		else
		{
			resized_height = PAGEDISPLAY_H;
			resized_width = image_width*PAGEDISPLAY_H/image_height;
		}
	}
	else
	{
		resized_width = image_width;
		resized_height = image_height;
	}
	
	if( result>= 0 )
	{
		if(0 == display_width && 0 == display_height)
		{
			browser_mmi_tracer((char *)"0 == display_width && 0 == display_height", "");
			gdi_image_wbmp_draw_resized(x, y,resized_width,resized_height,ImageBuf,len);
		}
		else
		{
			browser_mmi_tracer((char *)"0 == display_width && 0 == display_height***", "");
			if(display_width>resized_width||display_height>resized_height)
				gdi_image_wbmp_draw_resized(x, y,resized_width,resized_height,ImageBuf,len);	
			else
				gdi_image_wbmp_draw_resized(x, y,display_width,display_height,ImageBuf,len);
		}
	}
	if (ImageBuf != NULL)
	{
		cms_free(ImageBuf);
		ImageBuf = NULL;
	}
	return;
}
#ifdef CMS_SURPPORT_BMP
/*==============================================================
*   Function Name:	CmsPlayBmp
*   Input        :  char *filename
					int x
					int y
*   Output       :  void
*   description  :	show specify wbmp
*   author       : xiaoyongq 
*   date         : 20061031
==============================================================*/
void CmsPlayBmp(char *filename, int x, int y, int display_width, int display_height)
{
	CMS_BROWSER_FILEHANDLE fd = NULL;
	P_CMS_BROWSER_U8 ImageBuf = NULL;
	int len =0;
	S32 image_width,image_height,resized_width,resized_height;
	
	GDI_RESULT result = 0;	
	
	if (SuspendFlag == 1)
	{
		return;
	}

#ifdef NO_SHOW_STATEBAR
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#else	
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif
	fd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)filename,CMS_FILE_READONLY);
	
	browser_mmi_tracer((char *)"CmsPlaybmp filename = %s", filename);
	browser_mmi_tracer((char *)"CmsPlaybmp display_width = %d", display_width);
	browser_mmi_tracer((char *)"CmsPlaybmp display_height = %d", display_height);
	if (fd)
	{
		len = Cms_Browser_GetFileLength(fd);
		if (len > 0)
		{
			ImageBuf = mms_Malloc(len+1);
			if (ImageBuf == NULL)
			{
				return;
			}
			cms_memset(ImageBuf, 0, len+1);
			Cms_Browser_FileRead((P_CMS_BROWSER_U8)ImageBuf, 1, len+1, fd);			
			Cms_Browser_FileClose(fd);
		}
		else
		{
			return;
		}
		
	}
	else
	{
		return; 
	}

	result = gdi_image_bmp_get_dimension(ImageBuf, &image_width, &image_height);

	if ((image_width>PAGEDISPLAY_W) ||(image_height>PAGEDISPLAY_H))
	{
		//if((image_width/PAGEDISPLAY_W) >(image_height/PAGEDISPLAY_H))
		//changed by yangjun 060215 for changed the pic display error
		if((float)((float)image_width/(float)PAGEDISPLAY_W) >(float)((float)image_height/(float)PAGEDISPLAY_H))
		{
			resized_width = PAGEDISPLAY_W;
			resized_height = image_height*PAGEDISPLAY_W/image_width;
		}
		else
		{
			resized_height = PAGEDISPLAY_H;
			resized_width = image_width*PAGEDISPLAY_H/image_height;
		}
	}
	else
	{
		resized_width = image_width;
		resized_height = image_height;
	}
	
	if( result>= 0 )
	{
		if(0 == display_width && 0 == display_height)
		{
			browser_mmi_tracer((char *)"0 == display_width && 0 == display_height", "");
			gdi_image_bmp_draw_resized(x, y,resized_width,resized_height,ImageBuf,len);
		}
		else
		{
			browser_mmi_tracer((char *)"0 == display_width && 0 == display_height***", "");
			if(display_width>resized_width||display_height>resized_height)
				gdi_image_bmp_draw_resized(x, y,resized_width,resized_height,ImageBuf,len);	
			else
				gdi_image_bmp_draw_resized(x, y,display_width,display_height,ImageBuf,len);
		}
	}
	if (ImageBuf != NULL)
	{
		mms_Free(ImageBuf);
		ImageBuf = NULL;
	}
	return;
}
int GetBmpInformation(char *filename,int screenwidth,int *pwidth,int *pheight)
{
	CMS_BROWSER_FILEHANDLE fd = NULL;
	P_CMS_BROWSER_U8 ImageBuf = NULL;
	int len =0;
	S32 image_width,image_height,resized_width,resized_height;	
	GDI_RESULT result = 0;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef NO_SHOW_STATEBAR	
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif
	fd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)filename,CMS_FILE_READONLY);
	
	if (fd)
	{
		len = Cms_Browser_GetFileLength(fd);
		if (len > 0)
		{
			ImageBuf = cms_malloc(len+1);
			if (ImageBuf == NULL)
			{
				return 0;
			}
			memset(ImageBuf, 0, len+1);
			Cms_Browser_FileRead((P_CMS_BROWSER_U8)ImageBuf, 1, len+1, fd);			
			Cms_Browser_FileClose(fd);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0; 
	}
	
	result = gdi_image_bmp_get_dimension(ImageBuf, &image_width, &image_height);

	if ((image_width>PAGEDISPLAY_W) ||(image_height>PAGEDISPLAY_H))
	{
		if((float)((float)image_width/(float)PAGEDISPLAY_W) >(float)((float)image_height/(float)PAGEDISPLAY_H))
		{
			resized_width = PAGEDISPLAY_W;
			resized_height = image_height*PAGEDISPLAY_W/image_width;
		}
		else
		{
			resized_height = PAGEDISPLAY_H;
			resized_width = image_width*PAGEDISPLAY_H/image_height;
		}
	}
	else
	{
		resized_width = image_width;
		resized_height = image_height;
	}
	
	if( result>= 0 )
	{
		*pwidth = resized_width;
		*pheight = resized_height;
	}
	if (ImageBuf != NULL)
	{
		cms_free(ImageBuf);
		ImageBuf = NULL;
	}
	return 0;
}
#else
void CmsPlayBmp(char *filename, int x, int y, int display_width, int display_height)
{
	return;
}
int GetBmpInformation(char *filename,int screenwidth,int *pwidth,int *pheight)
{
	*pwidth=16;
	*pheight=16;
	return 0;
}
#endif
#ifdef CMS_SURPPORT_PNG
/*==============================================================
*   Function Name:	CmsPlayWbmPng
*   Input        :  char *filename
					int x
					int y
*   Output       :  void
*   description  :	show specify wbmp
*   author       : xiaoyongq 
*   date         : 20061031
==============================================================*/
void CmsPlayPng(char *filename, int x, int y, int display_width, int display_height)
{
	CMS_BROWSER_FILEHANDLE fd = NULL;
	P_CMS_BROWSER_U8 ImageBuf = NULL;
	int len =0;
	S32 image_width,image_height,resized_width,resized_height;
	
	GDI_RESULT result = 0;	
	
	if (SuspendFlag == 1)
	{
		return;
	}

#ifdef NO_SHOW_STATEBAR
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#else	
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif
	fd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)filename,CMS_FILE_READONLY);
	
	browser_mmi_tracer((char *)"CmsPlaypng filename = %s", filename);
	browser_mmi_tracer((char *)"CmsPlaypng display_width = %d", display_width);
	browser_mmi_tracer((char *)"CmsPlaypng display_height = %d", display_height);
	if (fd)
	{
		len = Cms_Browser_GetFileLength(fd);
		if (len > 0)
		{
			ImageBuf = mms_Malloc(len+1);
			if (ImageBuf == NULL)
			{
				return;
			}
			cms_memset(ImageBuf, 0, len+1);
			Cms_Browser_FileRead((P_CMS_BROWSER_U8)ImageBuf, 1, len+1, fd);			
			Cms_Browser_FileClose(fd);
		}
		else
		{
			return;
		}
		
	}
	else
	{
		return; 
	}

	result = gdi_image_png_get_dimension(ImageBuf,len, &image_width, &image_height);

	if ((image_width>PAGEDISPLAY_W) ||(image_height>PAGEDISPLAY_H))
	{
		//if((image_width/PAGEDISPLAY_W) >(image_height/PAGEDISPLAY_H))
		//changed by yangjun 060215 for changed the pic display error
		if((float)((float)image_width/(float)PAGEDISPLAY_W) >(float)((float)image_height/(float)PAGEDISPLAY_H))
		{
			resized_width = PAGEDISPLAY_W;
			resized_height = image_height*PAGEDISPLAY_W/image_width;
		}
		else
		{
			resized_height = PAGEDISPLAY_H;
			resized_width = image_width*PAGEDISPLAY_H/image_height;
		}
	}
	else
	{
		resized_width = image_width;
		resized_height = image_height;
	}
	
	if( result>= 0 )
	{
		if(0 == display_width && 0 == display_height)
		{
			browser_mmi_tracer((char *)"0 == display_width && 0 == display_height", "");
			gdi_image_png_draw_resized(x, y,resized_width,resized_height,ImageBuf,len);
		}
		else
		{
			browser_mmi_tracer((char *)"0 == display_width && 0 == display_height***", "");
			if(display_width>resized_width||display_height>resized_height)
				gdi_image_png_draw_resized(x, y,resized_width,resized_height,ImageBuf,len);	
			else
				gdi_image_png_draw_resized(x, y,display_width,display_height,ImageBuf,len);
		}
	}
	if (ImageBuf != NULL)
	{
		mms_Free(ImageBuf);
		ImageBuf = NULL;
	}
	return;
}
/*==============================================================
*   Function Name:	GetPngInformation
*   Input        :  char *filename
					int screenwidth
					int *pwidth
					int *pheight
*   Output       :  void
*   description  :	get specify png's information
*   author       :
*   date         :
==============================================================*/
int GetPngInformation(char *filename,int screenwidth,int *pwidth,int *pheight)
{
	CMS_BROWSER_FILEHANDLE fd = NULL;
	P_CMS_BROWSER_U8 ImageBuf = NULL;
	int len =0;
	S32 image_width,image_height,resized_width,resized_height;	
	GDI_RESULT result = 0;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef NO_SHOW_STATEBAR	
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif
	fd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)filename,CMS_FILE_READONLY);
	
	if (fd)
	{
		len = Cms_Browser_GetFileLength(fd);
		if (len > 0)
		{
			ImageBuf = cms_malloc(len+1);
			if (ImageBuf == NULL)
			{
				return 0;
			}
			memset(ImageBuf, 0, len+1);
			Cms_Browser_FileRead((P_CMS_BROWSER_U8)ImageBuf, 1, len+1, fd);			
			Cms_Browser_FileClose(fd);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0; 
	}
	
	result = gdi_image_png_get_dimension(ImageBuf, len, &image_width, &image_height);

	if ((image_width>PAGEDISPLAY_W) ||(image_height>PAGEDISPLAY_H))
	{
		if((float)((float)image_width/(float)PAGEDISPLAY_W) >(float)((float)image_height/(float)PAGEDISPLAY_H))
		{
			resized_width = PAGEDISPLAY_W;
			resized_height = image_height*PAGEDISPLAY_W/image_width;
		}
		else
		{
			resized_height = PAGEDISPLAY_H;
			resized_width = image_width*PAGEDISPLAY_H/image_height;
		}
	}
	else
	{
		resized_width = image_width;
		resized_height = image_height;
	}
	
	if( result>= 0 )
	{
		*pwidth = resized_width;
		*pheight = resized_height;
	}
	if (ImageBuf != NULL)
	{
		cms_free(ImageBuf);
		ImageBuf = NULL;
	}
	return 0;
}
#else
void CmsPlayPng(char *filename, int x, int y, int display_width, int display_height)
{
	if (SuspendFlag == 1)
	{
		return;
	}
	pixtel_UI_show_image(x, y, (UI_image_type)GetImage(IMG_WAPIMGDOWNLOAD_MAIN_MENU_ICON));
	return;
}
int GetPngInformation(char *filename,int screenwidth,int *pwidth,int *pheight)
{
	*pwidth=16;
	*pheight=16;
	return 0;
}
#endif //CMS_SURPPORT_PNG_BMP
/*==============================================================
*   Function Name:	CmsPlayJpeg
*   Input        :	char *filename
					int x
					int y
*   Output       :  void
*   description  :	show specify jpeg
*   author       :  
*   date         :
==============================================================*/
void CmsPlayJpeg(char *filename, int x, int y,int display_width, int display_height)
{
	CMS_BROWSER_FILEHANDLE fd = NULL;
	
	int len =0;
	S32 image_width,image_height, resized_width,resized_height;
	
	GDI_RESULT result = 0;
	
	if (SuspendFlag == 1)
	{
		return;
	}

	if (JpgImageBuf != NULL)
	{
		cms_free(JpgImageBuf);
		JpgImageBuf = NULL;
	}
	
#ifdef NO_SHOW_STATEBAR	
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif

	fd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)filename,CMS_FILE_READONLY);
	
	browser_mmi_tracer((char *)"CmsPlayJpeg filename = %s", filename);

	if (fd)
	{
		browser_mmi_tracer((char *)"CmsPlayJpeg filename = %s", filename);
		len = Cms_Browser_GetFileLength(fd);
		if (len > 0)
		{
			JpgImageBuf = cms_malloc(len+1);
			if (JpgImageBuf == NULL)
			{
				return;
			}
			cms_memset(JpgImageBuf, 0, len+1);
			Cms_Browser_FileRead((P_CMS_BROWSER_U8)JpgImageBuf, 1, len+1, fd);			
			Cms_Browser_FileClose(fd);
		}
		else
		{
			wap_Tracer((char *)"CmsPlayJpg error ");	
			return;
		}
		
	}
	else
	{
		wap_Tracer((char *)"CmsPlayJpg return");
		return; 
	}
	
	wap_Tracer((char *)"CmsPlayJpg 000 ");
	result = gdi_image_jpeg_get_dimension(JpgImageBuf, len, &image_width, &image_height);

	if ((image_width>PAGEDISPLAY_W) ||(image_height>PAGEDISPLAY_H))
	{
		if((float)((float)image_width/(float)PAGEDISPLAY_W) >(float)((float)image_height/(float)PAGEDISPLAY_H))
		{
			resized_width = PAGEDISPLAY_W;
			resized_height = image_height*PAGEDISPLAY_W/image_width;
		}
		else
		{
			resized_height = PAGEDISPLAY_H;
			resized_width = image_width*PAGEDISPLAY_H/image_height;
		}
	}
	else
	{
		resized_width = image_width;
		resized_height = image_height;
	}

	if( result>= 0 )
	{
		browser_mmi_tracer("x==%d",(char*)x);
		browser_mmi_tracer("y==%d",(char*)y);
		browser_mmi_tracer("len==%d",(char*)len);	
		if(0 == display_width && 0 == display_height)
		{
			gdi_image_jpeg_draw_resized(x, y,resized_width,resized_height,JpgImageBuf,len);
		}
		else
		{
			gdi_image_jpeg_draw_resized(x, y,display_width,display_height,JpgImageBuf,len);
		}
		//gdi_image_jpeg_draw(x, y, ImageBuf,len);
	}
	else
	{
		wap_Tracer((char *)"jpg result<0");
	}
	
	return;	
}
/*==============================================================
*   Function Name:	GetJpegInformation
*   Input        :  char *filename
					int screenwidth
					int *pwidth
					int *pheight
*   Output       :  void
*   description  :	get specify jpeg's information
*   author       :
*   date         :
==============================================================*/
int GetJpegInformation(char *filename,int screenwidth,int *pwidth,int *pheight)
{
	CMS_BROWSER_FILEHANDLE fd = NULL;
	P_CMS_BROWSER_U8 ImageBuf = NULL;
	int len =0;
	S32 image_width,image_height,resized_width,resized_height;	
	GDI_RESULT result = 0;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef NO_SHOW_STATEBAR	
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif
	fd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)filename,CMS_FILE_READONLY);
	
	if (fd)
	{
		len = Cms_Browser_GetFileLength(fd);
		if (len > 0)
		{
			ImageBuf = cms_malloc(len+1);
			if (ImageBuf == NULL)
			{
				return 0;
			}
			memset(ImageBuf, 0, len+1);
			Cms_Browser_FileRead((P_CMS_BROWSER_U8)ImageBuf, 1, len+1, fd);			
			Cms_Browser_FileClose(fd);
		}
		else
		{
			return 0;
		}		
	}
	else
	{
		return 0; 
	}
	
	result = gdi_image_jpeg_get_dimension(ImageBuf, len, &image_width, &image_height);

	if ((image_width>PAGEDISPLAY_W) ||(image_height>PAGEDISPLAY_H))
	{
		if((float)((float)image_width/(float)PAGEDISPLAY_W) >(float)((float)image_height/(float)PAGEDISPLAY_H))
		{
			resized_width = PAGEDISPLAY_W;
			resized_height = image_height*PAGEDISPLAY_W/image_width;
		}
		else
		{
			resized_height = PAGEDISPLAY_H;
			resized_width = image_width*PAGEDISPLAY_H/image_height;
		}
	}
	else
	{
		resized_width = image_width;
		resized_height = image_height;
	}
	
	if( result>= 0 )
	{
		*pwidth = resized_width;
		*pheight = resized_height;
	}
	if (ImageBuf != NULL)
	{
		cms_free(ImageBuf);
		ImageBuf = NULL;
	}
	return 0;
}

/*==============================================================
*   Function Name:	GetGifInformation
*   Input        :  char *filename
					P_CMS_BROWSER_U32 pWidth
					P_CMS_BROWSER_U32 pHeight
*   Output       :  void
*   description  :	get gif information by the filename
*   author       :  
*   date         :
==============================================================*/
CMS_BROWSER_BOOL GetGifInformation(char *filename, P_CMS_BROWSER_U32 pWidth, P_CMS_BROWSER_U32 pHeight)
{
  	CMS_BROWSER_FILEHANDLE fd = NULL;
	P_CMS_BROWSER_U8 ImageBuf = NULL;
	int len =0;
	S32 image_width,image_height,frame_count,
		resized_width,resized_height;
	
	GDI_RESULT result = 0;	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(filename==NULL || pHeight==NULL || pHeight==NULL)
    	{
        	return CMS_BROWSER_FALSE;
	}


#ifdef NO_SHOW_STATEBAR
/*20060912 add by xiaoyong for display gif while exist across scollbar*/
#ifdef WAP_SHOW_ACROSS_SCOLLBAR
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_Horizontal_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height-Cms_Horizontal_GetSCROLLBAR_W()-1);
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#endif
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif
	gdi_image_gif_reset();
	fd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)filename,CMS_FILE_READONLY);
	
	if (fd)
	{
		len = Cms_Browser_GetFileLength(fd);
		if (len > 0)
		{
			ImageBuf = cms_malloc(len+1);
			if (ImageBuf == NULL)
			{
				return 0;
			}
			memset(ImageBuf, 0, len+1);
			Cms_Browser_FileRead((P_CMS_BROWSER_U8)ImageBuf, 1, len+1, fd);			
			Cms_Browser_FileClose(fd);
		}
		else
		{
			return 0;
		}
		
	}
	else
	{
		return 0; 
	}
	
	result = gdi_image_gif_get_dimension(ImageBuf, &image_width, &image_height);

	if ((image_width>PAGEDISPLAY_W) ||(image_height>PAGEDISPLAY_H))
	{
		if((float)((float)image_width/(float)PAGEDISPLAY_W) >(float)((float)image_height/(float)PAGEDISPLAY_H))
		{
			resized_width = PAGEDISPLAY_W;
			resized_height = image_height*PAGEDISPLAY_W/image_width;
		}
		else
		{
			resized_height = PAGEDISPLAY_H;
			resized_width = image_width*PAGEDISPLAY_H/image_height;
		}
	}
	else
	{
		resized_width = image_width;
		resized_height = image_height;
	}
	
	if (result>=0)
	{
		*pWidth = resized_width;
		*pHeight = resized_height;
	}
	
	gdi_image_gif_get_frame_count(ImageBuf, len, &frame_count);

	if (ImageBuf != NULL)
	{
		cms_free(ImageBuf);
		ImageBuf = NULL;
	}

    return CMS_BROWSER_TRUE;
}
/*==============================================================
*   Function Name:	CmsPlayGif
*   Input        :  char *filename
					int x
					int y
					double x_proportion
					double y_proportion
*   Output       :  void
*   description  :	show gif play on the specify x, y position
*   author       :  
*   date         :
==============================================================*/
void CmsPlayGif(char *filename, int x, int y, int display_width, int display_height)
{
	CMS_BROWSER_FILEHANDLE fd = NULL;
	P_CMS_BROWSER_U8 ImageBuf = NULL;
	int len =0;
	S32 image_width,image_height,frame_count,
		resized_width,resized_height;
	
	GDI_RESULT result = 0;		
	if (SuspendFlag == 1)
	{
		return;
	}
	wap_Tracer((char *)"CmsPlayGif() in");	
#ifdef NO_SHOW_STATEBAR
/*20060912 add by xiaoyong for display gif while across scollbar exist*/
#ifdef WAP_SHOW_ACROSS_SCOLLBAR
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_Horizontal_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height-Cms_Horizontal_GetSCROLLBAR_W()-1);
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#endif
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif
	fd = Cms_Browser_FileOpen((P_CMS_BROWSER_U8)filename,CMS_FILE_READONLY);
	browser_mmi_tracer((char *)"CmsPlayGif filename = %s", filename);
	browser_mmi_tracer((char *)"CmsPlayGif display_width = %d", display_width);
	browser_mmi_tracer((char *)"CmsPlayGif display_height = %d", display_height);
	browser_mmi_tracer((char *)"CmsPlayGif x = %d", x);
	browser_mmi_tracer((char *)"CmsPlayGif y = %d", y);
	if (fd)
	{
		len = Cms_Browser_GetFileLength(fd);
		if (len > 0)
		{
			ImageBuf = cms_malloc(len+9);
			if (ImageBuf == NULL)
			{
				return;
			}
			memset(ImageBuf, 0, len+9);
			{
				ImageBuf[0]=IMAGE_TYPE_GIF;
				ImageBuf[1]=NULL;
				ImageBuf[2] = (U8) ( len& 0x000000ff);
				ImageBuf[3] = (U8) ((len >> 8) & 0x000000ff);
				ImageBuf[4] = (U8) ((len >> 16) & 0x000000ff);
				ImageBuf[5] = (U8) ((len >> 24) & 0x000000ff);
				ImageBuf[6]=NULL;
				ImageBuf[7]=NULL;
			}	
			Cms_Browser_FileRead((P_CMS_BROWSER_U8)ImageBuf+8, 1, len+1, fd);			
			Cms_Browser_FileClose(fd);
		}
		else
		{
			return;
		}
		
	}
	else
	{
		wap_Tracer((char *)"CmsPlayGif() error return");	
		return; 
	}
	
	//gdi_image_stop_animation_all(); //chaozhu.zhou 2006.11.1 delete for gif stop play
	gdi_image_gif_reset();
	
	result = gdi_image_gif_get_dimension(ImageBuf+8, &image_width, &image_height);

	if ((image_width>PAGEDISPLAY_W) ||(image_height>PAGEDISPLAY_H))
	{
		if((float)((float)image_width/(float)PAGEDISPLAY_W) >(float)((float)image_height/(float)PAGEDISPLAY_H))
		{
			resized_width = PAGEDISPLAY_W;
			resized_height = image_height*PAGEDISPLAY_W/image_width;
		}
		else
		{
			resized_height = PAGEDISPLAY_H;
			resized_width = image_width*PAGEDISPLAY_H/image_height;
		}
	}
	else
	{
		resized_width = image_width;
		resized_height = image_height;
	}
	
	gdi_image_gif_get_frame_count(ImageBuf+8, len, &frame_count);
	if( result>= 0 )
	{
		 if (frame_count == 1)
               {
                 	if(0 == display_width && 0 == display_height)
			{
				browser_mmi_tracer((char *)"display_width=0 gif", "");
				gdi_image_gif_draw_resized(x, y+1,resized_width,resized_height,ImageBuf+8,len,(U16)frame_count);
			}
			else
			{				
				browser_mmi_tracer((char *)"CmsPlayGif f#$%^&*()", "");
				gdi_image_gif_draw_resized(x, y+1,display_width,display_height,ImageBuf+8,len,(U16)frame_count);
			}
		 }	
		else
		{
			browser_mmi_tracer((char *)"test gif", "");
			if ((image_width>PAGEDISPLAY_W) ||(image_height>PAGEDISPLAY_H))
			{
				gdi_image_gif_draw_resized(x, y+1,resized_width,resized_height,ImageBuf+8,len,(U16)frame_count);
			}
			else
			{
				gif_play_from_mms = TRUE;
				gdi_image_draw_animation(x, y, ImageBuf,NULL);	
				resized_height = image_height;
			}
	       }
	
	}
	if (ImageBuf != NULL)
	{
		cms_free(ImageBuf);
		ImageBuf = NULL;
	}
	return;
}
/*==============================================================
*   Function Name:	CmsStopAllGif
*   Input        :  void
*   Output       :  void
*   description  :	transfer by browser to stop all gif play
*   author       :  
*   date         :
==============================================================*/
void CmsStopAllGif(void)
{
	gif_play_from_mms = FALSE;
	if (JpgImageBuf != NULL)
	{
		cms_free(JpgImageBuf);
		JpgImageBuf = NULL;
	}
	gdi_image_stop_animation_all();
}
//end image function

//modify by xiaoyongq 20051115 for dynamic option menu 
U16	nStrItemList[MAX_SUB_MENUS];
S32	option_CurActionItem = 0;

/*Get current select item index*/
void mmi_get_cur_sub_Index(S32 hiliteid)
{
	option_CurActionItem = hiliteid;
}  

/* Option Leftkey Event*/
void OK_BrowserOption(void)
{
	switch(nStrItemList[option_CurActionItem])
	{
	case STR_WAP_OPTION_BACK_ID:
		{
			mmi_wap_option_back();
		}
	break;
	
	case STR_WAP_OPTION_REFRESH_ID:
		{
			mmi_wap_option_refresh();
		}
	break;

	case STR_WAP_OPTION_URL_ID:
		{
			mmi_wap_option_currentURL();
		}
	break;

	case STR_WAP_OPTION_SAVECURRENTPAGE_ID:
		{
			mmi_wap_option_savecurrentpage();
		}
	break;

	case STR_WAP_OPTION_BOOK_ID:
		{
			mmi_wap_option_savebookmark();
		}
	break;

	case STR_WAP_OPTION_SAVEHOMEPAGE_ID:
		{
			mmi_wap_option_savehomepage();
		}
	break;

	case STR_WAP_OPTION_BROWSEREXIT_ID:
		{
			mmi_wap_option_exitbrowser();
		}
	break;
	
	case STR_WAP_OPTION_BROWSERHOMEPAGE_ID:
		{
			mmi_wap_option_homepage();
		}
	break;
	
	case STR_WAP_OPTION_DOWNMUSIC_ID:
		{
			Cms_Browser_SaveBGSound();
		}
	break;

	case STR_WAP_OPTION_DOWNPIC_ID:
		{
			Cms_Browser_SaveItemEvent(0);
		}
	break;
	
	case STR_WAP_NEWLINK_ID:
		{
			cms_memset(NewLink_UrlEdit, 0x0, sizeof(NewLink_UrlEdit));
			pfnUnicodeStrcpy((S8 *)NewLink_UrlEdit, (const S8 *)(L"http://"));
			EntryScrWapNewLinkMenuList();		
		}
	break;
	case STR_WAP_BOOKMARK_ID:
		{
			EntryScrWapOPtionBookMarkMenuList();//EntryScrWapBookMarkMenuList();
		}
		break;
	default:
		break;
	}
	
}
/*==============================================================
*   Function Name:	BrowserOption
*   Input        :  void
*   Output       :  void
*   description  :	entry page browser option menu
*   author       :  
*   date         :
==============================================================*/
void BrowserOption(void)
{
	int ii=0;
	U32	maskingByte=-1;
	U8*	guiBuffer=NULL;
	U16	numItems=0;
	
	U16 		itemIcons[MAX_SUB_MENUS];
	U8* 		popUpList[MAX_SUB_MENUS];
	U16 		screenId = SCR_ID_WAPOPTION_MAIN_MENU;
	SuspendFlag = 1;
	option_CurActionItem = 0;

	CmsStopAllGif();

	EntryNewScreen(SCR_ID_WAPOPTION_MAIN_MENU, NULL, BrowserOption, NULL);	
	SetMessagesCurrScrnID(STR_WAP_WAPOPTION_MAIN_MENU);

	BrowserScreen_ID = SCR_ID_WAPOPTION_MAIN_MENU;	
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAPOPTION_MAIN_MENU);	

	nStrItemList[0] = STR_WAP_OPTION_BACK_ID;	
	itemIcons[0] = IMG_GLOBAL_L1;		
	ii=ii+1;
	
	nStrItemList[ii] = STR_WAP_OPTION_REFRESH_ID;
	itemIcons[ii] = IMG_GLOBAL_L1 + ii;
	ii=ii+1;

	nStrItemList[ii] = STR_WAP_OPTION_URL_ID;
	itemIcons[ii] = IMG_GLOBAL_L1 + ii;
	ii=ii+1;

	nStrItemList[ii] = STR_WAP_NEWLINK_ID;
	itemIcons[ii] = IMG_GLOBAL_L1 + ii;
	ii=ii+1;

	nStrItemList[ii] = STR_WAP_BOOKMARK_ID;
	itemIcons[ii] = IMG_GLOBAL_L1 + ii;
	ii=ii+1;

	
	if(CmsIsImageSelected()==1&&Cms_Browser_GetImgSetup()==1)
	{
		nStrItemList[ii] = STR_WAP_OPTION_DOWNPIC_ID;//Down picture select
		itemIcons[ii] = IMG_GLOBAL_L1 + ii;
		ii=ii+1;
	}

	if(Cms_browser_GetBGMusicStatus()==3)
	{
		nStrItemList[ii] = STR_WAP_OPTION_DOWNMUSIC_ID;//Down Music select 
		itemIcons[ii] = IMG_GLOBAL_L1 + ii;
		ii=ii+1;
	}

	nStrItemList[ii] = STR_WAP_OPTION_BOOK_ID;
	itemIcons[ii] = IMG_GLOBAL_L1 + ii;
	ii=ii+1;
	
	
	
	nStrItemList[ii] = STR_WAP_OPTION_SAVECURRENTPAGE_ID;
	itemIcons[ii] = IMG_GLOBAL_L1 +ii;
	ii=ii+1;

	nStrItemList[ii] =STR_WAP_OPTION_SAVEHOMEPAGE_ID  ;
	itemIcons[ii] = IMG_GLOBAL_L1 + ii;
	ii=ii+1;	

	nStrItemList[ii] = STR_WAP_OPTION_BROWSERHOMEPAGE_ID;
	itemIcons[ii] = IMG_GLOBAL_L1 + ii;
	ii=ii+1;
	
	
	nStrItemList[ii] = STR_WAP_OPTION_BROWSEREXIT_ID;
	itemIcons[ii] = IMG_GLOBAL_L1 + ii;
	ii=ii+1;
	
	numItems =ii;
	guiBuffer = GetCurrGuiBuffer(screenId);
	
	
	MaskStringItems(popUpList,(U8)numItems,maskingByte);
	MaskItems(itemIcons,(U8)numItems,maskingByte);
	MaskHiliteItems(MMS_WMESSAGE_CONTENT_OPTIONS_MENUID,maskingByte);
 	numItems=MaskItems(nStrItemList,(U8)numItems,maskingByte);
	
	RegisterHighlightHandler (mmi_get_cur_sub_Index);	
	Option_Ok=1;

	ShowCategory52Screen(STR_WAP_WAPOPTION_MAIN_MENU, IMG_WAP_MAIN_MENU_ICON, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, (U16 *)gIndexIconsImageList,
						  NULL, 0, 0,
						  guiBuffer);
	SetLeftSoftkeyFunction(OK_BrowserOption, KEY_EVENT_UP);
	SetRightSoftkeyFunction(Exit_BrowserOption, KEY_EVENT_UP);
//	SetKeyHandler(Exit_BrowserOption, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	Exit_BrowserOption
*   Input        :  void
*   Output       :  void
*   description  :	exit browseroption menu
*   author       :  
*   date         :
==============================================================*/
void Exit_BrowserOption(void)
{
	SuspendFlag = 0;
	if (MainMenu_State == 18)
	{
		MainMenu_State = 12;
		GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
		Cms_Browser_LinkPageMessage();
		if (ResourceValue_State == CMS_STR_RESOURCE_RETRY)
		{
			wap_Tracer("CMS_STR_RESOURCE_RETRY");
			DisplayConfirm(STR_GLOBAL_OK, IMG_GLOBAL_OK,
				STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
				(UI_string_type)GetString(STR_WAP_PAGELINKFAILED_ID),
				IMG_GLOBAL_QUESTION, WARNING_TONE);
			SetLeftSoftkeyFunction(Cms_Browser_PageReLink, KEY_EVENT_UP);
			SetRightSoftkeyFunction(Cms_Browser_PageLinkReturn, KEY_EVENT_UP);
			SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
		}
		ResourceValue_State = -1;
	}
	else if(MainMenu_State == 20)
	{
		MainMenu_State = 12;
		GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
		Option_Ok=0;
		Down_Scrollbar_OK=0;
		Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDRAW);	
	}
	
}
/*==============================================================
*   Function Name:	BackToMainMenuEvent
*   Input        :  void
*   Output       :  void
*   description  :	back to wap main menu
*   author       :  
*   date         :
==============================================================*/
void BackToMainMenuEvent(void)
{
	wap_Tracer("BackToMainMenuEvent");
	Cms_Browser_StopBrowserTimer();

	switch(exteriorbrowserpage)
	{
	case 0:		
		Cms_StopMusic();
		Cms_Browser_WriteUIHistory();
		Cms_Browser_ClearAllHistory();
		ClearAllMarqueeMovie();
		if(1 == CmsIsImgStackDL())
			CmsAbortDownload();
		wap_Tracer("exteriorbrowserpage==0");
		//返回浏览器主菜单
		//soc_close_nwk_account(MOD_MMI);//add by yangjun 060811
		GoBackToHistory(SCR_ID_WAP_MAIN_MENU);
		break;
		
	case 1:
		if (browserflag == 1)
		{
			Cms_Browser_SaveBrowserSetupToFile();
			Cms_SaveFile();
			Cms_Browser_ExitEvent();
			Cms_close_soc(2);
			browserflag = 0;
		}			
		//返回访问主页进入的菜单
		DisplayIdleScreen();		
		break;
		
	case 2:
		if (browserflag == 1)
		{
                            U16 PrevScrId;
			Cms_Browser_SaveBrowserSetupToFile();
			Cms_SaveFile();
			Cms_Browser_ExitEvent();
			Cms_close_soc(2);
			browserflag = 0;
                            if(GetPreviousScrnIdOf(SCR_ID_WAP_PAGEBROWSER_MENU, &PrevScrId))
                            {
                			GoBackToHistory(PrevScrId);
                            }
                            else
                            {
                                DisplayIdleScreen();
                            }
		}			
		break;	

	default:
		DisplayIdleScreen();
		break;
	}	
}
/*==============================================================
*   Function Name:	OptionBackEvent
*   Input        :  void
*   Output       :  void
*   description  :	browser prev url page 
*   author       : 
*   date         :
==============================================================*/
void OptionBackEvent(void)
{		
	SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);

	Cms_StopMusic();
	wap_Tracer("==OptionBackEvent==");
	if(1 == CmsIsImgStackDL())
		CmsAbortDownload();
	
	Cms_Browser_GoPrevURIEvent();
	if(browserflag == 0||BackToIdle==1)
		return;
	MainMenu_State = 12;
	if( BrowserScreen_ID != SCR_ID_WAP_MAIN_MENU )
	{
		GoBackHistory();
	}
}
/*==============================================================
*   Function Name:	CmsWapBackEvent
*   Input        :  void
*   Output       :  void
*   description  :	browser prev url page 
*   author       : 
*   date         :
==============================================================*/
void CmsWapBackEvent(void)
{		
	SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);

	Cms_StopMusic();
	wap_Tracer("==CmsWapBackEvent==");
	if(1 == CmsIsImgStackDL())
		CmsAbortDownload();
	
	Cms_Browser_GoPrevURIEvent();
	if(browserflag == 0||BackToIdle==1)
		return;
	MainMenu_State = 12;
	if( BrowserScreen_ID != SCR_ID_WAP_MAIN_MENU )
	{
		Cms_Browser_LinkPageMessage();
	}	
}
/*===============================================================
Edit 
================================================================*/
/*==============================================================
*   Function Name:	Cms_PageEditor
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
char *Cms_PageEditor(char * formatstr, char * title, char * defaultvalue, unsigned short  len)
{
	int i =0;	
	CMS_BROWSER_U32 originalLength=0;
	wap_Tracer("==Cms_PageEditor==");
	if(defaultvalue != NULL)
	{		
		originalLength=Cms_UTF16Strlen((P_CMS_BROWSER_U8)defaultvalue);
		originalLength= 2*originalLength;
		if(originalLength>=2*CMS_EDIT_SEND_SIZE)
			originalLength=2*(CMS_EDIT_SEND_SIZE-1);
		if(originalLength>2*len-2)
			originalLength=2*len-2;//add by xiaoyong for BUG 48542
		browser_mmi_tracer("originalLength=%d",originalLength);
		cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
		while (((NULL != defaultvalue[i])||(NULL != defaultvalue[i+1])) && i <= originalLength)
		{
			InputContent_Edit[i+1] = defaultvalue[i];
			InputContent_Edit[i] = defaultvalue[i+1];
			i= i+2;
		}		
		IputModuleLength=len;
		browser_mmi_tracer("%s",InputContent_Edit);
	}
	else
	{
		wap_Tracer("originalparam == NULL");
		IputModuleLength=len;
		cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));		
	}	
	if(cms_strcmp(formatstr,"N")==0)
	{
		cms_UIIsNumber=1;
	}	
	else if(cms_strcmp(formatstr,"*N")==0)
	{
		if(IputModuleLength>=20)//chaozhu.zhou modify for *N >=12
			IputModuleLength=20;
		cms_UIIsNumber=1;
	}	
	else			
		cms_UIIsNumber=0;
	
	Cms_Browser_EditBox();
	return ;
}
/*==============================================================
*   Function Name:	Cms_Browser_GetEditContent
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
void Cms_Browser_GetEditContent(void)
{
	int i =0;
	P_CMS_BROWSER_U8 originalparam = NULL;
	CMS_BROWSER_U32 originalLength=0;

	originalparam = Cms_Browser_GetOriginParam();
	if(originalparam != NULL)
	{		
		originalLength=Cms_UTF16Strlen(originalparam);
		originalLength= 2*originalLength;
		if(originalLength>=2*CMS_EDIT_SEND_SIZE)
			originalLength=2*(CMS_EDIT_SEND_SIZE-1);
		browser_mmi_tracer("originalLength=%d",originalLength);
		cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
		while (((NULL != originalparam[i])||(NULL != originalparam[i+1])) && i <= originalLength)
		{
			InputContent_Edit[i+1] = originalparam[i];
			InputContent_Edit[i] = originalparam[i+1];
			i= i+2;
		}		
		browser_mmi_tracer("%s",InputContent_Edit);
		cms_free(originalparam);
		originalparam = NULL;
	}
	else
	{
		wap_Tracer("originalparam == NULL");
		cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));		
	}	
	return;
}
/*==============================================================
*   Function Name:	Cms_Browser_EditBox
*   Input        :  void
*   Output       :  void
*   description  :	transfered by wapbrowserlib when select a input box in page
*   author       :  
*   date         :
==============================================================*/
void Cms_Browser_EditBox(void)
{
	U8* guiBuffer = NULL;
	SuspendFlag = 1;

	wap_Tracer("==Cms_Browser_EditBox()===");


	CmsStopAllGif();
	EntryNewScreen(SCR_ID_WAP_EDITBOX_MENU, NULL, Cms_Browser_EditBox, NULL);

	BrowserScreen_ID = SCR_ID_WAP_EDITBOX_MENU;
	
	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_EDITBOX_MENU);
	if(cms_UIIsNumber==1)
	{
		ShowCategory5Screen(STR_WAP_EDITBOX_ID,NULL,STR_GLOBAL_OK,
	       NULL,STR_GLOBAL_BACK,NULL,
		INPUT_TYPE_NUMERIC,/*20060410 cocoma xu 修改输入法*/
         	 InputContent_Edit,IputModuleLength+1,guiBuffer);
	}
	else
	{
	if(cms_UIIsPassword==TRUE)
	{
		wap_Tracer("cms_IsPassword");
		ShowCategory5Screen(STR_WAP_EDITBOX_ID,NULL,STR_GLOBAL_OK,
	       NULL,STR_GLOBAL_BACK,NULL,
		INPUT_TYPE_ALPHANUMERIC_PASSWORD|INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
         	 InputContent_Edit,IputModuleLength+1,guiBuffer);
	}
	else
	{
		wap_Tracer(" not cms_IsPassword");
		ShowCategory5Screen(STR_WAP_EDITBOX_ID,NULL,STR_GLOBAL_OK,
		NULL,STR_GLOBAL_BACK,NULL,
		INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
		InputContent_Edit,IputModuleLength+1,guiBuffer);
	}
	}		
	set_left_softkey_label((UI_string_type)GetString(STR_GLOBAL_OK));
	show_left_softkey();

	SetLeftSoftkeyFunction(Browser_GetInputParam, KEY_EVENT_UP);
	SetCategory5RightSoftkeyFunction(Cms_Browser_EditBoxNochange,KEY_EVENT_UP);
	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	Cms_Browser_EditBoxNochange
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
void Cms_Browser_EditBoxNochange(void)
{
	MainMenu_State = 20;
	wap_Tracer("Cms_Browser_EditBoxNochange");
	Cms_Browser_GetInputParam(NULL);
	Exit_BrowserOption();
}
/*==============================================================
*   Function Name:	Browser_GetInputParam
*   Input        :  void
*   Output       :  void
*   description  :	transfer input param to lib
*   author       :  
*   date         :	
==============================================================*/
void Browser_GetInputParam(void)
{
	int i =0;
	U8 temp[2*CMS_EDIT_SEND_SIZE] = {0};
	SuspendFlag = 0;
	MainMenu_State = 12;
	GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
	while (((NULL != InputContent_Edit[i])||(NULL != InputContent_Edit[i+1])) && i <2*(CMS_EDIT_SEND_SIZE-1) )
	{
		temp[i+1] = InputContent_Edit[i];
		temp[i] = InputContent_Edit[i+1];
		i= i+2;
	}
	wap_Tracer("==Browser_GetInputParam()===");
	browser_mmi_tracer("InputContent_Edit==%s",InputContent_Edit);
	Cms_Browser_GetInputParam((P_CMS_BROWSER_U8)temp);

	browser_mmi_tracer("temp==%s",temp);
	cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));

	Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDRAW);
}
//End Edit function
/*==============================================================
*   Function Name:	Cms_DisplayState
*   Input        :  void
*   Output       :  void
*   description  :	display the http state
*   author       :  
*   date         :	
==============================================================*/
void Cms_DisplayState(int state)
{
	browser_mmi_tracer("+++Cms_DisplayState+++ = %d", state);
#ifndef NO_SHOW_STATEBAR
	if(BrowserScreen_ID !=SCR_ID_WAP_PAGEBROWSER_MENU)
		return;
	if (SuspendFlag == 1||BrowserScreen_ID == SCR_ID_WAP_SAVEFIFLE_MENU) 
	{
		return;
	}
	pixtel_UI_set_clip(0, UI_device_height-MMI_button_bar_height*2, UI_device_width-1, UI_device_height-MMI_button_bar_height-1);
	pixtel_UI_reset_text_clip();
	#ifdef __MMI_TOUCH_SCREEN__
		pixtel_UI_fill_rectangle(0, UI_device_height-MMI_button_bar_height*2, UI_device_width-1,UI_device_height- MMI_button_bar_height-1, pixtel_UI_color(0,200,0));
		pixtel_UI_set_text_color(pixtel_UI_color(200,200,200));
	#else
		pixtel_UI_fill_rectangle(0, UI_device_height-MMI_button_bar_height*2, UI_device_width-1,UI_device_height- MMI_button_bar_height-1, pixtel_UI_color(0,255,0));
		pixtel_UI_set_text_color(pixtel_UI_color(255,255,255));
	#endif
	pixtel_UI_set_font((UI_font_type)&MMI_medium_font);
	
	pixtel_UI_move_text_cursor(0, UI_device_height-MMI_button_bar_height*2+1);
	switch(state)
	{
	case STATE_DOWNLOAD_FAILED:		//"Download Failed!"||"下载失败"
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_DOWNLOAD_FAIL)));
		break;
	case STATE_DOWNLOADING:			//"Downloading . . . "||"正在下载 . . ."         
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_DOWNLOADING)));
	#ifdef __MMI_TOUCH_SCREEN__
		Browser_Enter();//add by xiaoyongq 20051222
	#endif	
		break;
	case STATE_DOWNLOAD_SUCCESS:		//"Download success "||"下载成功"             
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_DOWNLOAD_SUCCESS)));
		break;
	case STATE_DECODE_FAILED:		//"Decode Failed!"||"解码失败"                 
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_DECODE_FAIL)));
		break;
	case STATE_GATEWAY_DISCONNECTED:	//"Gateway disconnected"||"网关已断开"      
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_GATEWAY_DISCONNECT)));
		break;
	case STATE_HANGUPING:			//"Hanguping . . . "||"挂断中 . . ."      
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_HANGUPING)));
		break;
	case STATE_PARSER_FAILED:		//"parser failed!"||"解析网页失败!"               
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_PARSER_FAIL)));
		break;
	case STATE_CHARSET_BEYOND:		//"Charset not supported!"||"不支持的字符集"         
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_CHARSET_UNSUPPORT)));
		break;
	case STATE_ABOUT_BLANK:			//"about blank"||"主页未设置"   
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_HOMEPAGE_BLANK)));
		break;
	case STATE_PAGE_REFRESHING:	    //"Page refreshing..."||"自动装载:请稍等..."          
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_PAGE_REFRESHING)));
		break;
	case STATE_PAGE_ERROR:			//"Page error!"||"页面错误!"                          
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_PAGE_ERROR)));
		break;
	case STATE_DOWNLOAD_BEGAIN:		//"Download  . . ."||"准备下载 . . ."             
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_DOWNLOAD_BEGAIN)));
		break;
	case STATE_CONNECTING:			//"Connecting . . . "||"连接中 . . ."
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_CONNECTING)));
		break;
	case STATE_DIALING:				//"Dialing . . . "||"拨号中 . . ."
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_DIALING)));
		break;
	case STATE_DIAL_FAILED:			//"Dial failed "||"拨号失败"                         
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_DIAL_FAILED)));
		break;
	case STATE_SENDING:				//"Sending . . ."||"正在发送数据 . . ."           
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_SENDING)));
		break;
	case STATE_PARAM_ERROR:			//"Param error!"||"应用参数错误！"         
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_PARAM_ERROR)));
		break;
	case STATE_NO_MEMORY:			//"No memory!"||"资源不足！"                     
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_NO_MEMORY)));
		break;
	case STATE_CONNECT_FAILED:		//"Connect failed!"||"网关连接失败"              
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_CONNECT_FAILED)));
		break;
	case STATE_TIMER_ERROR:			//"Timer error!"||"定时器操作错误！"          
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_TIMER_ERROR)));
		break;
	case STATE_UNKNOWN_ERROR:		//"Unknown error!"||"未知错误类型！"              
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_UNKNOWN_ERROR)));
		break;
	case STATE_WAPSTACK_BUSY:		//"WAP stack busy!"||"协议栈忙！"                                  
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_WAPSTACK_BUSY)));
		break;
	case STATE_NETWORK_TIMEOUT:		//"Network Timeout!"||"网络超时！"                           
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_NETWORK_TIMEOUT)));
		break;
	case STATE_RECONNECTING:			//"Reconnecting . . . "||"重连接网关"                                     
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_RECONNECTING)));
		break;
	case STATE_WAPSTACK_SUSPENDED:	//"WAP stack suspended!"||"协议栈已挂起！"                         
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_WAPSTACK_SUSPENDED)));
		break;
	case STATE_WAPSTACK_RESUME_FAILED:	//"WAP stack resume failed!"||"协议栈恢复失败！"              
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_WAPSTACK_RESUME_FAILED)));
		break;
	case STATE_WAPSTACK_RESUMED:		//"WAP stack resumed!"||"协议栈已恢复！" 
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_WAPSTACK_RESUMED)));
		break;
	case STATE_PARSERING:			//Parsering
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_PARSERING)));
		break;
	case STATE_LAYOUTING:			//Layouting
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_LAYOUTING)));
		break;
	case STATE_DRAWING:				//Drawing
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_DRAWING)));
		break;
	case STATE_WMLSCRIPT:			/* wml script status */
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_WMLSCRIPT)));
		break;
	case STATE_WTAI:
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_WTAI)));
		break;
	case STATE_TLS_WAIT_CONFIRM  :	/* tls 连接建立时等待用户确认服务器证书.  */
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_TLS_WAIT_CONFIRM)));
		break;
	case STATE_WTLS_WAIT_CONFIRM :	/* wtls 连接建立时等待用户确认服务器证书. */
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_WTLS_WAIT_CONFIRM)));
		break;
	case STATE_OS_SOCKET_INVALIED:	/*系统创建socket失败，浏览器退出*/
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_OS_SOCKET_INVALIED)));
		break;
	case STATE_NORMAL:				/* 既然定了那么多状态，不做任何动作也应该是一种状态 */ //  Modified by TIPrj[2005/6/29]	
		pixtel_UI_print_text((UI_string_type)(GetString(STR_WAP_STATE_NORMAL)));
		break;	
	default:
		return;	
	}
	pixtel_UI_BLT_double_buffer(0, UI_device_height-MMI_button_bar_height*2, UI_device_width-1, UI_device_height-MMI_button_bar_height-1);	
#endif	
	return ;
}
/*==============================================================
*   Function Name:	Cms_Brw_LeftSodtKeyReg
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
void Cms_Brw_LeftSodtKeyReg(void)
{
	SetKeyHandler(CMS_NextLinkFocusEvent, KEY_DOWN_ARROW, KEY_EVENT_DOWN); //add by xiaoyongq 20061212
	SetKeyHandler(CMS_LastLinkFocusEvent, KEY_UP_ARROW, KEY_EVENT_DOWN);	

	SetKeyHandler(Brw_Keystar_Uppage, KEY_STAR, KEY_EVENT_DOWN);	
	SetKeyHandler(Brw_Keystar_Downpage, KEY_POUND, KEY_EVENT_DOWN);
	if (SuspendFlag == 1) 
	{
		return;
	}
#ifdef WAP_BROWSER_OPTION_MODE1		
	SetLeftSoftkeyFunction(GoLinkFocusEventByKey, KEY_EVENT_UP);
#else
	SetKeyHandler(GoLinkFocusEventByKey, KEY_SEND, KEY_EVENT_UP);
	SetKeyHandler(GoLinkFocusEventByKey, KEY_ENTER, KEY_EVENT_UP);	
#endif
}
void Cms_Brw_RightKeyCancleReg(void)
{
	wap_Tracer("==Cms_Brw_RightKeyCancleReg()===");
	if(Option_Ok==1)
		return;
	SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);	
}
/*==============================================================
*   Function Name:	Cms_DisplaySoftKey
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
void  Cms_DisplaySoftKey(unsigned char  *pls,  unsigned char  *rls)
{
	//wap_Tracer("Cms_DisplaySoftKey in");	
	return ;
}
void CmsDebugFunc(unsigned char *prompt_string,short data_size,void *p_data)
{
	return ;
}
void Cms_DrawInfoBox (unsigned char *string)
{

	CMS_BROWSER_U32    string_len  = 0, i =0;
	P_CMS_BROWSER_U8   string_conv = NULL;
	browser_mmi_tracer("Cms_DrawInfoBox Cms_DrawInfoBox",""); 
	 if (NULL != string) 
    	 {
		string_len = 2*pfnUnicodeStrlen((S8*)string)+2;
		string_conv = (P_CMS_BROWSER_U8)cms_malloc(string_len);
		for(i=0;i<string_len;i+=2)
		{
			*(string_conv+i) = *(string+i+1);
			*(string_conv+i+1) = *(string+i);
		}	
		memset(UnicodeBuf,0,sizeof(UnicodeBuf));
		pfnUnicodeStrcpy((char*)UnicodeBuf, (const char *)string_conv);
		cms_free(string_conv);
		string_conv = NULL;		  	 	
    	}
	else
	{
		return;
	}	
	DisplayPopup((U8*)UnicodeBuf, IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
}
/*==============================================================
*   Function Name:	Cms_Browser_SoftLeftOK
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
void Cms_Browser_SoftLeftOK(void)
{
	GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
	Browser_Enter();
	Cms_GetSoftKey( 0 );
}
/*==============================================================
*   Function Name:	Cms_Browser_SoftRightOK
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
void Cms_Browser_SoftRightOK(void)
{
	GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
	Cms_Brw_CancelPageDownload();
}
/*==============================================================
*   Function Name:	Cms_DrawMessage
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
int leftbutton_use;
int rightbutton_use;
void Cms_DrawMessage( unsigned char* title , unsigned short lid , unsigned short rid , unsigned char luse , unsigned char ruse )
{
	
	CMS_BROWSER_U32    string_len  = 0, i =0;
	P_CMS_BROWSER_U8   string_conv = NULL;
	wap_Tracer("========enter Cms_DrawMessage===========");
	 if (NULL != title) 
    	 {
		string_len = 2*pfnUnicodeStrlen((S8*)title)+2;
		cms_trace( "string_len %d:\n" , string_len );
		string_conv = (P_CMS_BROWSER_U8)cms_malloc(string_len);
		for(i=0;i<string_len;i+=2)
		{
			*(string_conv+i) = *(title+i+1);
			*(string_conv+i+1) = *(title+i);
		}	
		memset(TLSUnicodeBuf,0,sizeof(TLSUnicodeBuf));
		pfnUnicodeStrcpy((char*)TLSUnicodeBuf, (const char *)string_conv);
		cms_free(string_conv);
		string_conv = NULL;	
    	}
	else
	{
		return;
	}
	leftbutton_use = (int)luse;
	rightbutton_use = (int)ruse;
	cms_trace( "leftbutton_use %d:\n" , leftbutton_use );
	cms_trace( "rightbutton_use %d:\n" , rightbutton_use );
	EntryScrDrawMessage();

}
/*==============================================================
*   Function Name:	EntryScrDrawMessage
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
void EntryScrDrawMessage(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 	guiBuffer=NULL;		/* Buffer holding history data */
	U16	 	screenId=SCR_ID_WAP_SHOWMESSAGE_MENU;
	S32		str_len = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	wap_Tracer("========enter EntryScrDrawMessage===========");
	EntryNewScreen(screenId, NULL,EntryScrDrawSecutityMessage, NULL);
	str_len=pfnUnicodeStrlen((PS8)TLSUnicodeBuf);
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);
	ShowCategory74Screen(STR_WAP_INFOBOX_ID,IMG_WAPIMGSSLPAGE_MAIN_MENU_ICON,
						Cms_get_softkey_type(leftbutton_use),IMG_GLOBAL_OK,Cms_get_softkey_type(rightbutton_use), IMG_GLOBAL_BACK,
						(PU8)TLSUnicodeBuf, str_len, guiBuffer);
	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
	if(leftbutton_use != CMS_STR_RESOURCE_EMPTY)
		SetLeftSoftkeyFunction(Cms_Browser_SoftLeftOK, KEY_EVENT_UP);
	if(rightbutton_use != CMS_STR_RESOURCE_EMPTY)
		SetRightSoftkeyFunction(Cms_Browser_SoftRightOK, KEY_EVENT_UP);
}
/*==============================================================
*   Function Name:	Cms_get_softkey_type
*   Input        :  void
*   Output       :  void
*   description  :获取软键名称
*   author       :  
*   date         :	
==============================================================*/
U16 Cms_get_softkey_type(int soft_type)
{
	switch(soft_type)
	{
	case CMS_STR_RESOURCE_EMPTY:
		return NULL;
	case CMS_STR_RESOURCE_BACK:
		return STR_GLOBAL_BACK;
	case CMS_STR_RESOURCE_RETRY:
		return STR_GLOBAL_OK;
	case CMS_STR_RESOURCE_LINK:
		return STR_GLOBAL_OK;
	case CMS_STR_RESOURCE_EDIT:
		return STR_GLOBAL_EDIT;		
	case CMS_STR_RESOURCE_SELECT:
		return STR_GLOBAL_SELECT;		
	case CMS_STR_RESOURCE_CANCLE:
		return STR_GLOBAL_CANCEL;
	case CMS_STR_RESOURCE_OK:
		return STR_GLOBAL_OK;		
	case CMS_STR_RESOURCE_EXIT:
		return STR_GLOBAL_QUIT;	
	default:
		return NULL;
	}	
}
/*==============================================================
*   Function Name:	Cms_DrawMessage
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
void Cms_DrawSecutityMessage( unsigned char* title , unsigned short lid , unsigned short rid , unsigned char luse , unsigned char ruse )
{
	 if (NULL != title) 
    	 {
		pfnUnicodeStrcpy((char*)TLSUnicodeBuf, (const char *)title);
    	}
	else
	{
		return;
	}
	EntryScrDrawSecutityMessage();

}
/*==============================================================
*   Function Name:	EntryScrDrawSecutityMessage
*   Input        :  void
*   Output       :  void
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
void EntryScrDrawSecutityMessage(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 	guiBuffer=NULL;		/* Buffer holding history data */
	U16	 	screenId=SCR_ID_WAP_SHOWMESSAGE_MENU;
	S32		str_len = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	EntryNewScreen(screenId, NULL,EntryScrDrawSecutityMessage, NULL);
	str_len=pfnUnicodeStrlen((PS8)TLSUnicodeBuf);
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);

	//add 20060804
	MainMenu_State = MAIN_MENU_STATE_AUTHENTICATION;
	
	ShowCategory74Screen(STR_WAP_TRUSTED_CERTIFICATES_ID,IMG_WAPIMGSSLPAGE_MAIN_MENU_ICON,
						STR_GLOBAL_OK,IMG_GLOBAL_OK,STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						(PU8)TLSUnicodeBuf, str_len, guiBuffer);
	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
	SetLeftSoftkeyFunction(Cms_Browser_SoftLeftOK, KEY_EVENT_UP);
	SetRightSoftkeyFunction(Cms_Browser_SoftRightOK, KEY_EVENT_UP);
}
/*==============================================================
*   Function Name:	Cms_Browser_Download_Progress
*   Input        :  void
*   Output       :  void
*   description  :下载进度	
*   author       :  
*   date         :	
==============================================================*/
void Cms_Browser_Download_Progress(int v_RecvBytes , int v_TotalBytes)
{
#ifndef NO_SHOW_STATEBAR
	int state;
	unsigned char* StrDraw = NULL;
	unsigned char* StrU16Draw=NULL;
	CMS_BROWSER_U32 StrLen=0;
	wap_Tracer("Cms_Browser_Download_Progress");
	browser_mmi_tracer("v_RecvBytes==%d",v_RecvBytes);
	browser_mmi_tracer("v_TotalBytes==%d",v_TotalBytes);
	if(BrowserScreen_ID !=SCR_ID_WAP_PAGEBROWSER_MENU)
		return;

	if (SuspendFlag == 1||BrowserScreen_ID == SCR_ID_WAP_SAVEFIFLE_MENU) 
	{
		return;
	}
	state=Cms_Brw_Get_DisplayState();
	pixtel_UI_set_clip(0, UI_device_height-MMI_button_bar_height*2, UI_device_width-1, UI_device_height-MMI_button_bar_height-1);
	pixtel_UI_reset_text_clip();

	#ifdef __MMI_TOUCH_SCREEN__
		pixtel_UI_fill_rectangle(0, UI_device_height-MMI_button_bar_height*2, UI_device_width-1,UI_device_height- MMI_button_bar_height-1, pixtel_UI_color(0,200,0));
		pixtel_UI_set_text_color(pixtel_UI_color(200,200,200));
	#else
		pixtel_UI_fill_rectangle(0, UI_device_height-MMI_button_bar_height*2, UI_device_width-1,UI_device_height- MMI_button_bar_height-1, pixtel_UI_color(64,128,128));
		pixtel_UI_set_text_color(pixtel_UI_color(255,255,255));
	#endif

	pixtel_UI_set_font((UI_font_type)&MMI_medium_font);	
	pixtel_UI_move_text_cursor(0, UI_device_height-MMI_button_bar_height*2+1);

	StrDraw = (unsigned char*)cms_malloc(100);
	Cms_Browser_MemSet(StrDraw, 0x0, 100);
	sprintf((char*)StrDraw,"%d/%dK %dS",v_RecvBytes/1024,v_TotalBytes/1024,1+(v_TotalBytes-v_RecvBytes)/6000);	

	StrLen = Cms_Browser_Uni8_strlen(StrDraw);		
	StrU16Draw=cms_malloc(2*StrLen+2);
	Cms_Browser_Uni8_16_big(StrDraw,StrU16Draw);
	pixtel_UI_print_text((UI_string_type)StrU16Draw);

	if(NULL != StrDraw)
	{
		cms_free(StrDraw);
		StrDraw = NULL;
	}
	
	if(NULL != StrU16Draw)
	{
		cms_free(StrU16Draw);
		StrDraw = NULL;
	}
	pixtel_UI_BLT_double_buffer(0, UI_device_height-MMI_button_bar_height*2, UI_device_width-1, UI_device_height-MMI_button_bar_height-1);	
#else
	P_CMS_BROWSER_U8 StrDraw = NULL;
	P_CMS_BROWSER_U8 StrU16Draw=NULL;
	CMS_BROWSER_U32 StrLen=0;

	 if(BrowserScreen_ID !=SCR_ID_WAP_PAGEBROWSER_MENU)
		return;
	 if (SuspendFlag == 1||BrowserScreen_ID == SCR_ID_WAP_SAVEFIFLE_MENU) 
	    {
	       return;
	    }

	    StrDraw = (P_CMS_BROWSER_U8)cms_malloc(100);
	    if(NULL == StrDraw)
	    {
	       return;
	    }
	    Cms_Browser_MemSet(StrDraw, 0x0, 100);
	    sprintf((char*)StrDraw,"%d/%dK %dS",v_RecvBytes/1024,v_TotalBytes/1024,1+(v_TotalBytes-v_RecvBytes)/6000);  

	    StrLen    = Cms_UTF8toUTF16Len(StrDraw);
	    StrU16Draw = (P_CMS_BROWSER_U8)cms_malloc(StrLen+2);
	    if(NULL == StrU16Draw)
	    {
	       return;
	    }
	       Cms_UTF8toUTF16(StrDraw, cms_strlen((const char*)StrDraw), StrLen, StrU16Draw);
	    Cms_Browser_DrawTitle((P_CMS_BROWSER_U8)StrU16Draw);
	    if(NULL != StrDraw)
	    {
	       cms_free(StrDraw);
	       StrDraw = NULL;
	    }
	    
	    if(NULL != StrU16Draw)
	    {
	       cms_free(StrU16Draw);
	       StrDraw = NULL;
	    }
#endif		
}
void Cms_Browser_Download_Result(int result)
{
}
/*==============================================================
*   Function Name:	Cms_AuthenticationEditor
*   Input        :  
*   Output       :  
*   description  :	input username and password
*   author       :  
*   date         :
==============================================================*/
void Cms_AuthenticationEditor()
{
	wap_Tracer("Cms_AuthenticationEditor in");
	cms_memset(gSecurityContext.Username, 0, MAX_WAP_USERNAME_LEN);
	cms_memset(gSecurityContext.Password, 0, MAX_WAP_PASSWD_LEN);
	EntryScrWapAuthenticationEdit();
}

void Cms_PostMessage_DrawEvent()
{
	destroyAuthenticationManager();
	SocCloseSuccessEvent();
	GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
	Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDRAW);
}
/*==============================================================
*   Function Name:	EntryScrWapAuthenticationEdit
*   Input        :  
*   Output       :  
*   description  :	edit username and password
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapAuthenticationEdit(void)
{
	U16 WapAuthenticationIcons[4] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0 };
	U8* guiBuffer;

	U8* inputBuffer;
	U16 inputBufferSize;

	wap_Tracer("EntryScrWapAuthenticationEdit in");
	EntryNewScreen(SCR_ID_WAP_AUTHENTICATION_EDIT,ExitEntryScrWapAuthenticationEdit,NULL,  NULL);

	BrowserScreen_ID = SCR_ID_WAP_AUTHENTICATION_EDIT;
	
	InitializeCategory57Screen();
	WapAuthenticationEditFillInlineStruct();


	guiBuffer = GetCurrGuiBuffer(SCR_ID_WAP_AUTHENTICATION_EDIT);
	inputBuffer = GetCurrNInputBuffer(SCR_ID_WAP_AUTHENTICATION_EDIT, &inputBufferSize );
	if(inputBuffer != NULL)		
		SetCategory57Data(wgui_inline_items, 4, inputBuffer);

	ShowCategory57Screen(STR_WAP_AUTHENTICATION_EDIT,IMG_WAP_MAIN_MENU_ICON,
						STR_GLOBAL_OK,IMG_GLOBAL_OK,
						STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						4,
						WapAuthenticationIcons,wgui_inline_items,1,guiBuffer);

	SetCategory57RightSoftkeyFunctions(WapAuthenticationEditFinish,Cms_PostMessage_DrawEvent ); //xiaoyongq 20060412Cms_Brw_CancelPageDownload);
	
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
}
/*==============================================================
*   Function Name:	WapAuthenticationEditFillInlineStruct
*   Input        :  
*   Output       :  
*   description  :	init username and password struct
*   author       :  
*   date         :
==============================================================*/
void WapAuthenticationEditFillInlineStruct(void)
{
	SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_WAP_INPUT_USERNAME));

	SetInlineItemActivation(&(wgui_inline_items[1]),KEY_LSK, KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&(wgui_inline_items[1]), STR_WAP_INPUT_USERNAME, NULL, gSecurityContext.Username,MAX_WAP_USERNAME_LEN,
		INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
	SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[1]), WapAuthenticationEdit);
	RightJustifyInlineItem(&wgui_inline_items[1]);
	
	SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_WAP_INPUT_PASSWORD));
					
	SetInlineItemActivation(&(wgui_inline_items[3]),KEY_LSK, KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&(wgui_inline_items[3]), STR_WAP_INPUT_PASSWORD, NULL, gSecurityContext.Password,MAX_WAP_PASSWD_LEN,
		INPUT_TYPE_ALPHANUMERIC_PASSWORD|INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
	SetInlineFullScreenEditCustomFunction(&(wgui_inline_items[3]), WapAuthenticationEdit);
	RightJustifyInlineItem(&wgui_inline_items[3]);
}
/*==============================================================
*   Function Name:	ExitEntryScrWapAuthenticationEdit
*   Input        :  
*   Output       :  
*   description  :	exit username and password screen
*   author       :  
*   date         :
==============================================================*/
void ExitEntryScrWapAuthenticationEdit(void)
{
	history	h;
	U16 inputBufferSize;
	CloseCategory57Screen();
	h.scrnID = SCR_ID_WAP_AUTHENTICATION_EDIT;
	h.entryFuncPtr = EntryScrWapAuthenticationEdit;
	GetCategoryHistory(h.guiBuffer);
	inputBufferSize =(U16)GetCategory57DataSize( ); 
	GetCategory57Data ((U8*) h.inputBuffer );  
	AddNHistory(h, inputBufferSize);           	
}
/*==============================================================
*   Function Name:	WapAuthenticationEditFinish
*   Input        :  
*   Output       :  
*   description  :	enter new screen
*   author       :  
*   date         :
==============================================================*/
void WapAuthenticationEditFinish(void)
{
    	unsigned char *pUTF16UserID = NULL;
    	unsigned char *pUTF16PSW    = NULL;
	wap_Tracer("WapAuthenticationEditFinish in");	
	{
		CMS_BROWSER_U32	usnm_len  = 0, pwd_len = 0, i =0, j = 0;
		usnm_len = 2*pfnUnicodeStrlen((S8*)gSecurityContext.Username)+2;
		browser_mmi_tracer("the username len:%d", usnm_len);
		pUTF16UserID = (P_CMS_BROWSER_U8)cms_malloc(usnm_len);
		for(i=0;i<usnm_len;i+=2)
		{
			*(pUTF16UserID+i) = *(gSecurityContext.Username+i+1);
			*(pUTF16UserID+i+1) = *(gSecurityContext.Username+i);
		}	

		pwd_len = 2*pfnUnicodeStrlen((S8*)gSecurityContext.Password)+2;
		browser_mmi_tracer("the password len:%d", pwd_len);
		pUTF16PSW = (P_CMS_BROWSER_U8)cms_malloc(pwd_len);
		for(j=0;j<pwd_len;j+=2)
		{
			*(pUTF16PSW+j) = *(gSecurityContext.Password+j+1);
			*(pUTF16PSW+j+1) = *(gSecurityContext.Password+j);
		}
	}
	MainMenu_State = MAIN_MENU_STATE_AUTHENTICATION;
	Browser_page();
	Cms_Authentication_GetInputParam(pUTF16UserID,pUTF16PSW);
	cms_free(pUTF16UserID);
	pUTF16UserID = NULL;
	cms_free(pUTF16PSW);
	pUTF16PSW = NULL;
}
void WapAuthenticationEdit(void)
{
	wap_Tracer("WapAuthenticationEdit in");	
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(ConfirmInlineFullScreenEdit, KEY_EVENT_UP);
}
/*==============================================================
*   Function Name:	Cms_GetCharacterWidth
*   Input        :  CMS_BROWSER_U8 font
					CMS_BROWSER_U16 Utf16
*   Output       :  CMS_BROWSER_U32
*   description  :	get utf16 charazcter width
*   author       :  
*   date         :
==============================================================*/
unsigned int Cms_GetCharacterWidth(CMS_BROWSER_U8 font,CMS_BROWSER_U16 Utf16)
{	
	return pixtel_UI_get_character_width(Utf16);
}

/*==============================================================
*   Function Name:	Cms_Browser_DrawRect
*   Input        :  int x -- X postion
					int y -- Y postion
					int width -- rect width
					int height -- rect heigh
					int Clear -- rect attribute
*   Output       :  int, return 1 success
*   description  :	draw rect specify
*   author       :  
*   date         :
==============================================================*/
int Cms_Browser_DrawRect(int x,  int y, int width, 
									  int height, 
									  int Mark)
{
	wap_Tracer("========enter Cms_Browser_DrawRect===========");
	if (SuspendFlag == 1)
	{
		wap_Tracer("DrawRect");
		return;
	}
#ifdef NO_SHOW_STATEBAR
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-2);//chaozhuzh modify-1
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif
	
	MainMenu_State = 20;
	if(SuspendFlag == 0)
	{	
		//wap_Tracer((char*)"aaaa");
		browser_mmi_tracer("-----KeyStatue=%d",ResourceValue_State);
		SetKeyHandler(GoLinkFocusEventByKey, KEY_SEND, KEY_EVENT_UP);
		SetKeyHandler(GoLinkFocusEventByKey, KEY_ENTER, KEY_EVENT_UP);
		
		SetKeyHandler(CMS_NextLinkFocusEvent, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
		SetKeyHandler(CMS_LastLinkFocusEvent, KEY_UP_ARROW, KEY_EVENT_DOWN);
		/*注册侧键*/
		SetKeyHandler(CMS_NextLinkFocusEvent, KEY_VOL_DOWN, KEY_EVENT_DOWN);
		SetKeyHandler(CMS_LastLinkFocusEvent, KEY_VOL_UP, KEY_EVENT_DOWN);

		//SetKeyHandler(CMS_RightLinkFocusEvent, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		//SetKeyHandler(CMS_LeftLinkFocusEvent, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
		SetKeyHandler(Brw_Keystar_Uppage, KEY_STAR, KEY_EVENT_DOWN);	
		SetKeyHandler(Brw_Keystar_Downpage, KEY_POUND, KEY_EVENT_DOWN);	
	}

	browser_mmi_tracer("clear=%d",(char*)Mark);
	switch(Mark)
	{
	case 0:
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(0,0,0));
		break;

	case 1:
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(0,0,0));
		break;

	case 2:
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(0,0,0));
		break;	

	case 3:
		ResourceValue_State = CMS_STR_RESOURCE_SELECT;
#ifdef __MMI_TOUCH_SCREEN__
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(0,200,0));
#else
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(0,255,0));
#endif
		break;
		
	case 4:
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(0,0,0));
		break;
		
	case 5:
#ifdef __MMI_TOUCH_SCREEN__
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(0,0,200));//05.11.17 pan modify
#else
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(0,0,247));
#endif
		break;
		
	case 7:
#ifdef __MMI_TOUCH_SCREEN__
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(200,0,0));
#else
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(255,0,0));
#endif
		break;

	default:
		pixtel_UI_draw_rectangle(x, y, x+width, y+height, pixtel_UI_color(0,0,0));
		break;
	}
	return 1;
}
/*==============================================================
*   Function Name:	Cms_Browser_ClearRect
*   Input        :  int x -- X postion
					int y -- Y postion
					int width -- rect width
					int height -- rect heigh
*   Output       :  int, return 1 success
*   description  :	draw rect specify
*   author       :  
*   date         :	
==============================================================*/
int Cms_Browser_ClearRect(unsigned int x, unsigned int y, 
						  unsigned int width, unsigned int height,
						  unsigned int BackGroudColor)
{
	unsigned int Red=0;
	unsigned int Green=0;
	unsigned int Blue=0;

	if (SuspendFlag == 1)
	{
		wap_Tracer("ClearRect");
		return;
	}
	MainMenu_State = 20;
#ifdef NO_SHOW_STATEBAR
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif
	browser_mmi_tracer("BackGroudColor=%d",(char*)BackGroudColor);
	browser_mmi_tracer("width=%d",(char*)width);
	browser_mmi_tracer("height=%d",(char*)height);

	Red=(BackGroudColor&0xFF);
	Green=(BackGroudColor>>8)&(0xFF);
	Blue=(BackGroudColor>>16);
	if(Blue == 255 && Red== 255 && Green == 255)
	{
		pixtel_UI_fill_rectangle(x, y-1, x+width, y+height-1 , pixtel_UI_color(Red,Green,Blue));
		return 1;
	}
#if defined (__MMI_TOUCH_SCREEN__)||defined(SUPPORT_MTK_6226)
	if(Blue == 255)
	{
		Blue =200;
	}

	if(Red == 255)
	{
		Red =200;
	}	

	if(Green == 255)
	{
		Green =200;
	}	
#endif
	pixtel_UI_fill_rectangle(x, y-1, x+width, y+height-1, pixtel_UI_color(Red,Green,Blue));
	
	return 1;
}
/*==============================================================
*   Function Name:	Cms_Browser_ClearRect
*   Input        :  
*   Output       :  
*   description  :	
*   author       :  
*   date         :	
==============================================================*/
 int Cms_DisplayString (unsigned char font_type, /*(in)字体类型 */
					   int x, /*(in) 起始点的横坐标*/
                       int y, /*(in) 起始点的纵坐标*/
                       unsigned char *str, /* (in)待显示的字符串*/
                       unsigned int stringcolor, /*(in)字体颜色 */
                       unsigned char Mark, /*(in)是否标记显示*/
                       int isAnchor)/*(in)*/
 {
	unsigned char* StrDraw = NULL;
	int offset = 0,j=0,k=0;
	const char enterkey[] = {0X0D, 0X00, 0X0A, 0X00,};

	//wap_Tracer((char*)"======Cms_DisplayString=====");
	//20060913 xiaoyong modify
	if (SuspendFlag == 1||BrowserScreen_ID != SCR_ID_WAP_PAGEBROWSER_MENU)
	{
		wap_Tracer("SuspendFlag == 1");
		return;
	}
	MainMenu_State = 20;
	offset=Cms_UTF16Strlen(str);
	StrDraw = (unsigned char*)cms_malloc(2*offset+2);
	Cms_Browser_MemSet(StrDraw, 0x0, 2*offset+2);	
		
	for(j=0;j<2*offset;j=j+2)
	{
		if((str[j]==enterkey[0] && str[j+1]==enterkey[1])||(str[j]==enterkey[2] && str[j+1]==enterkey[3]))
		{
			
			wap_Tracer("0d00 0a00");
			break;
		}
		else
		{
			StrDraw[k] = str[j];
			StrDraw[k+1] = str[j+1];
			k=k+2;
		}		
	}

#ifdef NO_SHOW_STATEBAR
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width,UI_device_height-MMI_button_bar_height-1);
#else
	pixtel_UI_set_clip(0,ORIGIN_Y,UI_device_width-Cms_GetSCROLLBAR_W()-1,UI_device_height-MMI_button_bar_height*2-1);
#endif		
	pixtel_UI_reset_text_clip();
	pixtel_UI_set_font((UI_font_type)&MMI_medium_font);
	
	
	if( 1 == Mark )
	{
		/* 选中色 */
#if defined (__MMI_TOUCH_SCREEN__)||defined(SUPPORT_MTK_6226)/*在MTK6226平台上会出现链接字符为白色,无法显示*/
		pixtel_UI_set_text_color(pixtel_UI_color(200,0,0));
#else
		pixtel_UI_set_text_color(pixtel_UI_color(255,0,0));
#endif
	}
	else if( 0 != stringcolor )
	{	
		unsigned int r;
		unsigned int g;
		unsigned int b;
		//cms_trace("0 != stringcolor");
		r = (stringcolor%256);
		g = (stringcolor/256)%256;
		b = ((stringcolor/256)/256)%256;
#if defined (__MMI_TOUCH_SCREEN__)||defined(SUPPORT_MTK_6226)/*在MTK6226平台上会出现链接字符为白色,无法显示*/
		if(stringcolor != 16777215)
		{
			if(b == 255)
			{
				b = 200;
			}
			if(r == 255)
			{
				r = 200;
			}		
			if(g == 255)
			{
				g = 200;
			}
		}
#endif	 
		pixtel_UI_set_text_color(pixtel_UI_color(r,g,b));
		
	}
	else
	{
	switch ( isAnchor )
	{
	case 0:/*text*/
	//	cms_trace("text0");
		pixtel_UI_set_text_color(pixtel_UI_color(0,0,0));
		break;
		case 1:	/* link color */
#if defined (__MMI_TOUCH_SCREEN__)||defined(SUPPORT_MTK_6226)
			pixtel_UI_set_text_color(pixtel_UI_color(0,0,200));//05.11.17 pan modify
#else
			pixtel_UI_set_text_color(pixtel_UI_color(0,0,255));//05.11.17 pan modify
#endif
			break;

	    	case 2:	/* select color */
#if defined (__MMI_TOUCH_SCREEN__)||defined(SUPPORT_MTK_6226)
			pixtel_UI_set_text_color(pixtel_UI_color(200,0,0));			
#else
			pixtel_UI_set_text_color(pixtel_UI_color(255,0,0));			
#endif
			break;
		case 3:
		pixtel_UI_set_text_color(pixtel_UI_color(0,0,0));
		break;
	default:
	//	cms_trace("default");
		pixtel_UI_set_text_color(pixtel_UI_color(255,255,255));
		break;
	}	
	}
	
	pixtel_UI_move_text_cursor(x,y);
	pixtel_UI_print_text((UI_string_type)StrDraw);

	if(NULL != StrDraw)
	{
		cms_free(StrDraw);
		StrDraw = NULL;
	}
	return 1;
 }

 int Cms_DrawLine(int x, int y, int length, int Horizontal) 
{

	if (SuspendFlag == 1) 
	{
		return;
	}
#ifdef __MMI_TOUCH_SCREEN__
	pixtel_UI_line(x,y,x+length,y,pixtel_UI_color(0,0,200));
#else
	pixtel_UI_line(x,y+1,x+length,y+1,pixtel_UI_color(0,0,247));
#endif
	return 1;	
}
 
int Cms_DrawString(unsigned char font_type,int x,	int y,
					unsigned char *string,int space,
					unsigned int color,	unsigned char Mark,
					int isAnchor,	unsigned char updateflag)
{

	int len = 0;
	int i = 0;
	unsigned short uniCODE = 0;
	unsigned char  zf[4];
	char tempchar = 0;	
	
	while( 0 != string[i] || 0 != string[i+1] )
	{
		uniCODE = (CMS_BROWSER_U16)(string[i]*256 + string[i+1]);

#ifdef SUPPORT_UNICODE		
		tempchar = string[i];
		string[i] = string[i+1];
		string[i+1] = tempchar;
#endif
		zf[0] = string[i];
		zf[1] = string[i+1];
		zf[2] = 0;
		zf[3] = 0;

		Cms_DisplayString(font_type,x+len,y,zf,color,Mark,isAnchor);	

		len += Cms_GetCharacterWidth(CMSFONT, uniCODE);		
		len += space;		

		i += 2;
	}

	if( 1 == isAnchor )
	{
#if defined(__MMI_MAINLCD_240X320__)
		Cms_DrawLine( x, y+CMSFONT_HEIGHT + 2, len ,1 );
#else
		Cms_DrawLine( x, y+CMSFONT_HEIGHT, len ,1 );
#endif
	}
	return 1;

}
/*==============================================================
*   Function Name:	Cms_Browser_RefreshScreen
*   Input        :  void
*   Output       :  void
*   description  :	refresh screen or update screen
*   author       :  
*   date         :
==============================================================*/
void Cms_Browser_RefreshScreen(void)
{
	if (SuspendFlag == 1)
	{
		return;
	}
#ifdef NO_SHOW_STATEBAR
	pixtel_UI_BLT_double_buffer(0,MMI_title_y+MMI_title_height, UI_device_width-1, UI_device_height-1-MMI_button_bar_height);	
#else
	pixtel_UI_BLT_double_buffer(0,MMI_title_y+MMI_title_height, UI_device_width-1, UI_device_height-1-MMI_button_bar_height*2);	
#endif
 	return;
}
/*==============================================================
*   Function Name:	Cms_Browser_DrawTitle
*   Input        :  P_CMS_BROWSER_U8 pTitle
*   Output       :  void
*   description  :	draw current page title
*   author       :  
*   date         :
==============================================================*/
void Cms_Browser_DrawTitle(P_CMS_BROWSER_U8 pTitle)
{
	CMS_BROWSER_U32    string_len  = 0, i =0;
	P_CMS_BROWSER_U8   string_conv = NULL;
	if (SuspendFlag == 1)
	{
		return;
	}
	if(BrowserScreen_ID != SCR_ID_WAP_PAGEBROWSER_MENU)
	{
		return;
	}
	if(Cms_Brw_Get_Cancel_OK()==1&& 1 == Cms_Browser_IsZeroURL())
	{
		ChangeTitle(IMG_WAPSUCCESS_MAIN_MENU_ICON,(U8*)GetString(STR_WAP_MAIN_MENU_CAPTION));
		draw_title();
		return ;
	}
    	if (NULL != pTitle) 
    	{
		string_len = 2*Cms_UTF16Strlen(pTitle)+2;
		string_conv = (P_CMS_BROWSER_U8)cms_malloc(string_len);
		for(i=0;i<string_len;i+=2)
		{
			*(string_conv+i) = *(pTitle+i+1);
			*(string_conv+i+1) = *(pTitle+i);
		}
		if(getSafeConnectType()==1)
		{
			wap_Tracer("==getSafeConnectType=");	
			ChangeTitle(IMG_WAPIMGSSLPAGE_MAIN_MENU_ICON, (U8*)string_conv);
		}	
		else
			ChangeTitle(IMG_WAPSUCCESS_MAIN_MENU_ICON, (U8*)string_conv);
		draw_title();
		cms_free(string_conv);
		string_conv = NULL;
    	}
}
/*==============================================================
*   Function Name:	Cms_Browser_DrawPoint
*   Input        :  P_CMS_BROWSER_U8 pTitle
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
int Cms_Browser_DrawPoint(unsigned int x, unsigned int y, unsigned int color)
{
	return 1;
}
/*==============================================================
*   Function Name:	Cms_DrawColorLine
*   Input        :  P_CMS_BROWSER_U8 pTitle
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
int Cms_DrawColorLine (int  type, unsigned int width, unsigned int color, int bx, int by, int ex, int ey) 
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	red = (color%256);
	green = (color/256)%256;
	blue = ((color/256)/256)%256;	
	if (SuspendFlag == 1)
	{
		return;
	}
	pixtel_UI_wline(bx,by,ex,ey,pixtel_UI_color(red,green,blue),width);
}
/*==============================================================
*   Function Name:	Cms_Scroll
*   Input        :  
*   Output       :  void
*   description  :	
*   author       :  
*   date         :
==============================================================*/
void Cms_Scroll(int all_pages, int current_page, int scroll_type)
{
	if (SuspendFlag == 1)
	{
		return;
	}
			
	if(scroll_type == 0)
	{
		browser_mmi_tracer("-----------sroll: total %d", (char*)all_pages);
		browser_mmi_tracer("-----------sroll: cur %d \n", (char*)current_page);
		pixtel_UI_set_vertical_scrollbar_range(&categoryWap_vbar,all_pages);
		pixtel_UI_set_vertical_scrollbar_scale(&categoryWap_vbar,2);
		pixtel_UI_set_vertical_scrollbar_value(&categoryWap_vbar,current_page-1);
	}
#ifdef WAP_SHOW_ACROSS_SCOLLBAR
	else if(scroll_type == 1)
	{
		pixtel_UI_set_horizontal_scrollbar_range(&categoryWap_hbar,all_pages);
		pixtel_UI_set_horizontal_scrollbar_scale(&categoryWap_hbar,2);
		pixtel_UI_set_horizontal_scrollbar_value(&categoryWap_hbar,current_page-1);
	}
#endif
	show_wap_vbar();
}

//End Draw Scrollbar
/*==============================================================
*   Function Name:	Cms_UpdateScreen
*   Input        :  
*   Output       :  void
*   description  : 更新屏幕	
*   author       :  
*   date         :
==============================================================*/
void Cms_UpdateScreen(unsigned int left, unsigned int top,unsigned int right, unsigned int bottom)
{
	wap_Tracer("========Cms_UpdateScreen===========");	
	if (SuspendFlag == 1)
	{
		return;
	}
	pixtel_UI_BLT_double_buffer(left,top,right,bottom);
}
void brw_SaveLastPageURL(char * url)
{
}
/*==============================================================
*   Function Name:	 cms_show_wappush_icon
*   Input        :  void
*   Output       :  void
*   description  :	notify MTK unread push message Num
*   author       :  yangjun
*   date         :	4-12-2005
==============================================================*/
void cms_show_wappush_icon()
{
#ifndef SUPPORT_SMSMMS_COMBINE
	if(UnreadPushMessageNum>0)
	{
		ShowStatusIcon(STATUS_ICON_WAP);
	}
	else
	{
		HideStatusIcon(STATUS_ICON_WAP);
	}
	//UpdateStatusIcons();
#endif
}
/*==============================================================
*   Function Name:	CmsGetUnreadPushMessageNum
*   Input        :  void
*   Output       :  void
*   description  :	get unread push message num
*   author       :  yangjun
*   date         :	
==============================================================*/
extern CMS_BROWSER_U8 pushmessagenum;
void CmsGetUnreadPushMessageNum(void)
{
#if 0
	int mtkpushfd;
	unsigned char *tempbuf = NULL;
	unsigned int nread;
	unsigned int size;
	UnreadPushMessageNum = 0;
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapPushfilename(wap_filename);	
	mtkpushfd = Cms_Adp_fopen((S8*)wap_filename, FS_READ_ONLY);
	//mtkpushfd = FS_Open(L"C:\\wap\\CmsPushFile.cnf",FS_READ_ONLY);
	if (mtkpushfd < 0)
	{
		return;		
	}
	else
	{
		FS_GetFileSize(mtkpushfd, &size);
		tempbuf = (unsigned char *)mms_Malloc(size);
		if (tempbuf == NULL)
		{
			FS_Close(mtkpushfd);
			return;
		}
		memset(tempbuf, 0, size);
		FS_Read(mtkpushfd, tempbuf, size, &nread);
			
		UnreadPushMessageNum = CmsBrowserGetUnreadPushMessageNum(tempbuf, nread);

		mms_Free(tempbuf);
		FS_Close(mtkpushfd);
	}
#endif
	UnreadPushMessageNum=pushmessagenum;
	MtkGetUnreadPushMessageNum();
	cms_show_wappush_icon();
}

/*===============================================================
Net function
===============================================================*/

/*==============================================================
*   Function Name:	wap_net_data_init
*   Input        :  void
*   Output       :  void
*   description : init wap net data
*   author       :  
*   date         :
==============================================================*/
void wap_net_data_init(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	U8 tempgateport[65] = {0};
	cms_memset(&sock_addr,0x00,sizeof(sockaddr_struct));
	sock_addr.addr_len=4;
	
	cms_memset(Setting_Gateway, 0, 65);
	cms_memset(Setting_Port, 0, 10);
	Cms_Browser_GetGateWaySetup((P_CMS_BROWSER_U8)Setting_Gateway, (P_CMS_BROWSER_U8)Setting_Port);
	if (Setting_Gateway[0] == NULL)
	{
		if(CmsGetNetType() == CMS_WAP_CONNECT_HTTP)	
			sock_addr.port = 80; 
		else
			sock_addr.port = 9201; 
		
		sock_addr.addr[0] = 10;  
		sock_addr.addr[1] =0;
		sock_addr.addr[2] = 0;
		sock_addr.addr[3] = 172;
	}
	else
	{
		
		while (Setting_Gateway[i*2] != NULL)
		{
			if (Setting_Gateway[i*2] != '.')
			{
				tempgateport[j] = Setting_Gateway[i*2];
				j++;	
			}
			else if (k<=2)
			{
				sock_addr.addr[k] = Cms_Browser_atoi(tempgateport);
				cms_memset(tempgateport, 0 , 10);
				j = 0;
				k++;
			}
			i++;
		}
		
		sock_addr.addr[k] = Cms_Browser_atoi(tempgateport);
		cms_memset(tempgateport, 0 , 10);		
		
		if(CmsGetNetType() == CMS_WAP_CONNECT_HTTP)
		{
			i = 0;
			while (Setting_Port[i*2] != NULL)
			{
				tempgateport[i] = Setting_Port[i*2]; 
				i ++;
			}
			sock_addr.port = Cms_Browser_atoi(tempgateport);
		}
		else/*WAP1.2.1模式下默认端口固定为9201*/
		{
			sock_addr.port = 9201;
		}	
	}	
}

//End Net function

/*==============================================================
Wap Init function
===============================================================*/
/*==============================================================
*   Function Name:	wap_init_bookmark_from_pc_file
*   Input        :  void
*   Output       :  void
*   description  :	add default bookmark form pc c file
*   author       : 
*   date         :
==============================================================*/
#ifdef CMS_PC_CONFIG_SOFTWARE
void wap_init_bookmark_from_pc_file(void)
{
	U8 N_Cfg=0;
	
	for(N_Cfg=0;N_Cfg<cms_wap_bookmark_default.max_n_bkms;N_Cfg++)
	{
		if(cms_wap_bookmark_default.bkm[N_Cfg].empty==1)
		{
			Cms_Browser_NewBookmarkAdd((P_CMS_BROWSER_U8)cms_wap_bookmark_default.bkm[N_Cfg].bkm_name,\
					(P_CMS_BROWSER_U8)cms_wap_bookmark_default.bkm[N_Cfg].bkm_url);
		}
	}
}
#endif
/*==============================================================
*   Function Name:	MtkAddDefaultBookMark
*   Input        :  void
*   Output       :  void
*   description  :	add default bookmark when format MTK phone
*   author       : 
*   date         :
==============================================================*/
void MtkAddDefaultBookMark(void)
{
	int mtkflagfd;
	wap_Tracer("=MtkAddDefaultBookMark()==");
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapBookmarkfilename(wap_filename);	
	mtkflagfd = Cms_Adp_fopen((S8*)wap_filename, FS_READ_ONLY);
	browser_mmi_tracer("mtkflagfd==%d",(char*)mtkflagfd);
	if (mtkflagfd < 0)
	{		
		if (Cms_Browser_StartEvent())
		{
#ifdef CMS_PC_CONFIG_SOFTWARE
			wap_init_bookmark_from_pc_file();
#else
			//请转换为UTF-8(ASCII编辑) 编码格式的书签名字输入
			Cms_Browser_NewBookmarkAdd((P_CMS_BROWSER_U8)"Yahoo", (P_CMS_BROWSER_U8)"http://wap.yahoo.com");
			Cms_Browser_NewBookmarkAdd((P_CMS_BROWSER_U8)"163 neteast", (P_CMS_BROWSER_U8)"http://wap.163.com");
			Cms_Browser_NewBookmarkAdd((P_CMS_BROWSER_U8)"imobile", (P_CMS_BROWSER_U8)"http://wap.imobile.com.cn");
#endif
		}
		else
		{
			wap_Tracer("=Cms_Browser_StartEvent<0=");
			return;
		}
		wap_set_setting_file_for_default_active();/*浏览器默认设定配置*/	
		Cms_Browser_SetupPushMessageOn();//默认开启PUSH	
		Cms_Browser_SetupSecurityOn();//默认开启安全层	
		Cms_Browser_SetupMusicOn();//默认开启播放背景音乐
		Cms_Browser_SetupImgOn();//默认开启图片下载
#ifdef SUPPORT_SWITCH_PROTOCOL
		Cms_Browser_SetupNetTypeHttp();//默认浏览器HTTP
#endif		
		Cms_Browser_SaveBrowserSetupToFile();
		Cms_SaveSetupFile();
		Cms_SaveBookMarkFile();
		Cms_Browser_ExitEvent();
#ifdef CMS_RESET_UNDELETE_WAPPUSHFILE
		if (!Cms_Adp_FileExists((S8*)WAP_PUSH_FILENAME))
#endif
		{
			cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
			Cms_GetWapBookmarkfilename(wap_filename);	
			mtkflagfd = Cms_Adp_fopen((S8*)wap_filename, FS_CREATE);
			//mtkflagfd = FS_Open(L"C:\\wap\\CmsBookMarkFile.cnf",FS_CREATE);
			if (mtkflagfd >0)
			{
				FS_Close(mtkflagfd);
			}
			wap_Tracer("=mtkflagfd end");
		}
		return;	
	}
	else
	{
		Cms_LoadPushFile();
		if (Cms_Browser_StartEvent())
		{
			wap_set_setting_file_for_default_active();/*浏览器默认设定配置*/	
			Cms_Browser_ExitEvent();
		}
		wap_Tracer("=MtkAddDefaultBookMark end");
		FS_Close(mtkflagfd);
	}
}
/*==============================================================
*   Function Name:	wap_init_app
*   Input        :  void
*   Output       :  void
*   description  :	add default bookmark and HomePage when format MTK phone
*   author       : 
*   date         :
==============================================================*/

void wap_init_app()
{
#if defined(NOKE_DEBUG)
	noke_dbg_printf("==wap_init_app=\n\r");
#endif
	//wap_init_all_pre_setting_file();
	MtkAddDefaultBookMark();
	CmsGetUnreadPushMessageNum();
}
//End Init function

/*==========================================================
RLSoftKey,Cancle opteration Function
==========================================================*/
void CmsBrwPageBrowserSuccess(void)
{
	int i;
	browser_mmi_tracer("MainMenu_State==%d",(char*)MainMenu_State);

	if(BrowserScreen_ID == SCR_ID_WAP_MAIN_MENU||BrowserScreen_ID==SCR_ID_WAP_OFFLINE_MENU)
	{
		wap_Tracer("CmsBrwPageBrowserSuccess return");
		return;
	}
	wap_Tracer("CmsBrwPageBrowserSuccess Down_Scrollbar_OK=0");
	Down_Scrollbar_OK=0;
	SetNetSocketReadEndState();
	if(ResourceValue_State == CMS_STR_RESOURCE_SELECT||ResourceValue_State ==CMS_STR_RESOURCE_EMPTY) 
	{
		if(Option_Ok==0&&SuspendFlag == 0)
		{	
			wap_Tracer("Option_OK==0");
#ifdef WAP_BROWSER_OPTION_MODE1				
			ChangeRightSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);		
			SetRightSoftkeyFunction(BrowserOption, KEY_EVENT_UP);
#else
			ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);		
			SetLeftSoftkeyFunction(BrowserOption, KEY_EVENT_UP);
			ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
			SetRightSoftkeyFunction(CmsWapBackEvent, KEY_EVENT_UP);			
#endif
			return;
		}	
	}
	
	if(SuspendFlag == 0)
	{		
		wap_Tracer("==CmsBrwPageBrowserSuccess=");
		MainMenu_State= 20;//add by xiaoyongq 20060606 for bug 36361		
#ifdef WAP_BROWSER_OPTION_MODE1		
		ChangeRightSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);		
		SetRightSoftkeyFunction(BrowserOption, KEY_EVENT_UP);
#else
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);		
		SetLeftSoftkeyFunction(BrowserOption, KEY_EVENT_UP);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetRightSoftkeyFunction(CmsWapBackEvent, KEY_EVENT_UP);
#endif
		if((ResourceValue_State!=CMS_STR_RESOURCE_OK) && (ResourceValue_State!=CMS_STR_RESOURCE_EDIT) && (Cms_Browser_HasFocus() == CMS_BROWSER_TRUE))//for bug 29164
		{
#ifdef WAP_BROWSER_OPTION_MODE1			
			ChangeLeftSoftkey(STR_WAP_LINK, IMG_GLOBAL_YES);
			SetLeftSoftkeyFunction(GoLinkFocusEventByKey, KEY_EVENT_UP);
#else
			ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
			SetRightSoftkeyFunction(CmsWapBackEvent, KEY_EVENT_UP);
#endif			
		}	
	
		SetKeyHandler(GoLinkFocusEventByKey, KEY_SEND, KEY_EVENT_UP);
		SetKeyHandler(GoLinkFocusEventByKey, KEY_ENTER, KEY_EVENT_UP);		
		SetKeyHandler(CMS_NextLinkFocusEvent, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
		SetKeyHandler(CMS_LastLinkFocusEvent, KEY_UP_ARROW, KEY_EVENT_DOWN);	
		/*注册侧键*/
		SetKeyHandler(CMS_NextLinkFocusEvent, KEY_VOL_DOWN, KEY_EVENT_DOWN);
		SetKeyHandler(CMS_LastLinkFocusEvent, KEY_VOL_UP, KEY_EVENT_DOWN);	
		SetKeyHandler(Brw_Keystar_Uppage, KEY_STAR, KEY_EVENT_DOWN);	
		SetKeyHandler(Brw_Keystar_Downpage, KEY_POUND, KEY_EVENT_DOWN);	
		for(i = 0; i<=KEY_9;i++)
		{
			SetKeyHandler(Cms_Browser_AccessKeyEvent, KEY_0+i,  KEY_EVENT_DOWN);
		}		
#ifdef WAP_BROWSER_OPTION_MODE1		
		if(Cms_Browser_HasFocus() != CMS_BROWSER_TRUE) //add by xiaoyongq 20051226 for bug 30464
			ChangeLeftSoftkey(NULL, IMG_GLOBAL_YES);
#else
		if(Cms_Browser_HasFocus() != CMS_BROWSER_TRUE) 
		{
			/*Disable KEY_SEND and KEY_ENTER for link event*/
			SetKeyHandler(NULL, KEY_SEND, KEY_EVENT_DOWN);
			SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
		}
#endif		
	}
	return;
}

/*==============================================================
*   Function Name:	Browser_GoPrevURIEventByRightKey
*   Input        :  void
*   Output       :  void
*   description  :	browser prev url page by RightKey
*   author       :  
*   date         :
==============================================================*/
void Browser_GoPrevURIEventByRightKey(void)
{
	SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
	Cms_Browser_GoPrevURIEvent();	
}
/*===========================================================
 浏览器合盖事件处理
===========================================================*/
#ifdef __MMI_CLAMSHELL__
U8 WapClamEventHandler(void* ptr)
{
	if (browserflag == 1)
	{
		Cms_Browser_SaveBrowserSetupToFile();
		Cms_SaveFile();
		Cms_Browser_ExitEvent();
		Cms_close_soc(2);
		browserflag = 0;		
	}	
	cms_show_wappush_icon();
	DisplayIdleScreen();
	return 0;//1;liukai mod. for keylock when exit
}
#endif
/*=========================================================
Select Ctrl Show Function
==========================================================*/
//changed by yangjun 06-02-07 for selectbox form
/*
void ShowSelectCtrl( U16 nItemsCount , U16 nCurSelect , U8* pItems[])
{
	g_nItemsCount = nItemsCount; 
       g_nCurSelect = nCurSelect;
	g_pItems = pItems;
	EntryScrWapSelectBoxOption();
}*/
void ShowSelectCtrl(CmsSelectCtrlItems   CtrlItems)
{
	g_CtrlItems = CtrlItems;
	EntryScrWapSelectBoxOption();
}	

void EntryScrWapSelectBoxOption(void)
{
	U8*	 	guiBuffer=NULL;		/* Buffer holding history data */
	U16	 	screenId= SCR_ID_SELECT_OPTION;
	Option_Ok = 1;
	BrowserScreen_ID = SCR_ID_SELECT_OPTION;
	wap_Tracer("=====ShowSelectCtrl()= in===");
	EntryNewScreen(screenId, NULL,EntryScrWapSelectBoxOption, NULL);


	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
	RegisterHighlightHandler(mmi_get_index);
	
	ShowCategory36Screen( STR_MMS_WAP_EDIT_SETTING, IMG_WAP_MAIN_MENU_ICON,
						  	//STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE,//changed by yangjun 20060626
						  	STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE,
						  	STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  	g_CtrlItems.nItemsCount, (U8**)g_CtrlItems.pItems, (U16)g_CtrlItems.nCurrSelected, NULL);
	
	SetLeftSoftkeyFunction(CmsWapSelectboxFinish, KEY_EVENT_UP);
	SetRightSoftkeyFunction(CmsWapSelectboxCancel, KEY_EVENT_UP);
	SetKeyHandler(ExitWapBrowserByEndkey, KEY_END, KEY_EVENT_DOWN);
	wap_Tracer("=====ShowSelectCtrl()=out===");
}

void CmsWapSelectboxFinish(void)
{
	wap_Tracer("=====CmsWapSelectboxFinish()= in===");
	CmsSelectCtrlItemsCleanUp(&g_CtrlItems);
	Cms_Browser_SelectCtrl_UserSelecteItem(ghiliindex);
	MainMenu_State = 12;
	Option_Ok=0;
	Down_Scrollbar_OK=0;
	GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
	//xiaooyong 20060419 Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDRAW);
}

void CmsWapSelectboxCancel(void)
{	
	wap_Tracer("=====CmsWapSelectboxCancel()= in===");
	CmsSelectCtrlItemsCleanUp(&g_CtrlItems);
	MainMenu_State = 12;
	GoBackToHistory(SCR_ID_WAP_PAGEBROWSER_MENU);
	Option_Ok=0;
	Down_Scrollbar_OK=0;
	Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERDRAW);
}


void Cms_Browser_DrawSelectCtrl(CmsSelectCtrlItems CtrlItems)
{
	 if( !CtrlItems.nItemsCount || !CtrlItems.pItems)	return;
	 if( CtrlItems.nCurrSelected >= CtrlItems.nItemsCount )	CtrlItems.nCurrSelected = CtrlItems.nItemsCount - 1;
	 browser_mmi_tracer("nItemsCount==%d",(char*)CtrlItems.nItemsCount);
 	 browser_mmi_tracer("nCurrSelected==%d",(char*)CtrlItems.nCurrSelected);
	 ShowSelectCtrl( CtrlItems );
	 wap_Tracer("=====Cms_Browser_DrawSelectCtrl()====");
}
//changed by yangjun 06-02-07 for selectbox form over...
//End Select Ctrl function
/*=======================================================
Cookie functon
========================================================*/
extern Cms_cookie_buf *cookie_buf;
unsigned char pgCookieBuffer[CMS_COOKIEBUFFER_LENGTH] = {0};
/*==============================================================
*   Function Name:	Cms_SaveCookie
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
 void Cms_SaveCookie(void)
 {
	unsigned int nwrite;	
	int mtkcookie = NULL;

	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapCookiefilename(wap_filename);
	Cms_Adp_fdelete((const unsigned short *) wap_filename);
	mtkcookie = Cms_Adp_fopen((S8*)wap_filename, FS_CREATE);
	if (mtkcookie < 0)
	{
		cms_trace("Save cookies mtkcookie<0");
		return;
	}	
	if(Cms_Adp_JudgeCSpace((int)cookie_buf->length))	
	{
		FS_Close(mtkcookie);
		DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;		
	}	
	FS_Write(mtkcookie,pgCookieBuffer ,CMS_COOKIEBUFFER_LENGTH,&nwrite);
	FS_Close(mtkcookie);	
 }
/*==============================================================
*   Function Name:	Cms_GetCookie
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
 unsigned char *Cms_GetCookie(unsigned int *buflen)
 {
	 CMS_BROWSER_U32 Filesize=0,nread=0;	
 	 int mtkcookie = NULL;
	 unsigned char *tempcontent=NULL;
	 
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapCookiefilename(wap_filename);	 
	mtkcookie = Cms_Adp_fopen((S8*)wap_filename, FS_READ_ONLY);
	 if (mtkcookie < 0)//不存在cookies文件分配默认cache大小
	{
		cms_memset(pgCookieBuffer, 0, CMS_COOKIEBUFFER_LENGTH);
		*buflen=CMS_COOKIEBUFFER_LENGTH;
		return pgCookieBuffer;
	}
	FS_GetFileSize(mtkcookie, &Filesize);
	if(Filesize<=0)
	{
		*buflen=CMS_COOKIEBUFFER_LENGTH;
		cms_memset(pgCookieBuffer, 0, CMS_COOKIEBUFFER_LENGTH);
		return pgCookieBuffer;
	}
	*buflen=CMS_COOKIEBUFFER_LENGTH;
	cms_memset(pgCookieBuffer, 0, CMS_COOKIEBUFFER_LENGTH);
	FS_Read(mtkcookie, pgCookieBuffer, Filesize, &nread);
	FS_Close(mtkcookie);
	return pgCookieBuffer;
 }

//End cookies
/*=============================================================
History function
==============================================================*/
#include "cmshistory.h"
extern P_BRWHISTORY BrwHistory;

/*==============================================================
*   description  :	Read History record in file system to struct BrwHistory.
*   author       :  xiaoyongq 
*   date         :20051008
==============================================================*/
 void Cms_Browser_ReadUIHistory()
{
	int mtkhistory = NULL;
	unsigned char *tempcontent=NULL;
	unsigned int nread;
	P_CMS_BROWSER_U8 title = NULL, url = NULL;
	CMS_BROWSER_U32 i = 0,j=0,Filesize=0;	
	CMS_BROWSER_U64 leng = 0;
	CMS_BROWSER_S32 flag = 0, ch = 0;
	CMS_BROWSER_BOOL isItem = CMS_BROWSER_TRUE;
	CMS_BROWSER_U8 item[10];
	CMS_BROWSER_U8  content[URLLEN];
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapHistoryfilename(wap_filename);	
	mtkhistory = Cms_Adp_fopen((S8*)wap_filename, FS_READ_ONLY);
	//mtkhistory = FS_Open(L"C:\\wap\\CmsBrwHistory.cnf",FS_READ_ONLY);
	if (mtkhistory < 0)
	{
		return;
	}
	FS_GetFileSize(mtkhistory, &Filesize);
	cms_trace("Filesize==%d",Filesize);
	if(Filesize<=0)
	{
		FS_Close(mtkhistory);
		return ;
	}
	tempcontent = (unsigned char *)cms_malloc(Filesize);
	if (tempcontent == NULL)
	{
		FS_Close(mtkhistory);
		return;
	}
	cms_memset(tempcontent, 0, Filesize);
	FS_Read(mtkhistory, tempcontent, Filesize, &nread);
	FS_Close(mtkhistory);
	
	while(leng<=(CMS_BROWSER_U32)Filesize && i<MAXSTOREHISTORY)
	{
		flag = tempcontent[leng];
		leng++;
					
		if(flag == '\n')
		{
			if(isItem == CMS_BROWSER_TRUE)
			{
				/*=== 读出书签项名称 ===*/
				for(j=0; j<10 && ch!='\n' && leng<=(CMS_BROWSER_U32)Filesize; j++)
				{
					ch = tempcontent[leng];
					leng++;
					if(leng<=(CMS_BROWSER_U32)Filesize)
					{
						item[j] = (CMS_BROWSER_U8)ch;
					}
				}
				
				if(leng>(CMS_BROWSER_U32)Filesize || j>10)
				{
					break;
				}
				
				if(j>0)
				{
					item[j-1] = 0;
				}
				
				if(Cms_Browser_StrCmp((P_CMS_BROWSER_U8)item, (P_CMS_BROWSER_U8)"cmstitle")==0)
				{			
					/*=== 读出书签项标题 ===*/
					ch = 0;
					
					for(j=0; j<URLLEN && ch != CMS_CONFIG_SPACEMARK && leng<=(CMS_BROWSER_U32)Filesize; j++)
					{
						ch = tempcontent[leng];
						leng++;
						if(leng<=(CMS_BROWSER_U32)Filesize)
						{
							content[j] = (CMS_BROWSER_U8)ch;
						}
					}
					
					if(leng>(CMS_BROWSER_U32)Filesize || j>URLLEN)
					{
						break;
					}
					
					if(j>0)
					{
						content[j-1] = 0;
					}
					
					title = (P_CMS_BROWSER_U8)cms_malloc(j);
					if(title != NULL)
					{
						if(BrwHistory->title[i] != NULL)
						{
							cms_free(BrwHistory->title[i]);
							BrwHistory->title[i]= NULL;
						}
						BrwHistory->title[i] = title;
						Cms_Browser_StrCpy(BrwHistory->title[i], (P_CMS_BROWSER_U8)content);
					}
					else
					{							
						break;
					}
				}
				else if(Cms_Browser_StrCmp((P_CMS_BROWSER_U8)item, (P_CMS_BROWSER_U8)"cmsurl")==0)
				{
					/*=== 读出书签对应的URL ===*/
					ch = 0;
					
					for(j=0; j<URLLEN && ch != '\n' &&
						leng<=(CMS_BROWSER_U32)Filesize; j++)
					{
						ch = tempcontent[leng];
						leng++;
						if(leng<=(CMS_BROWSER_U32)Filesize)
						{
							content[j] = (CMS_BROWSER_U8)ch;
						}
					}
					
					if(j>URLLEN)
					{
						cms_free(BrwHistory->title[i]);
						BrwHistory->title[i] = NULL;
						break;
					}
					
					if(j>0)
					{
						content[j-1] = 0;
					}
					
					url = (P_CMS_BROWSER_U8)cms_malloc(j);
					if(url != NULL)
					{	
						if(BrwHistory->url[i] != NULL)
						{
							cms_free(BrwHistory->url[i]);
							BrwHistory->url[i] = NULL;
						}
						BrwHistory->url[i] = url;
						Cms_Browser_StrCpy(BrwHistory->url[i], (P_CMS_BROWSER_U8)content);
					}
					else
					{
						cms_free(BrwHistory->title[i]);
						BrwHistory->title[i] = NULL;
						break;
					}
				}
				else
				{
					if(BrwHistory->url[i] ==NULL &&BrwHistory->title[i]!=NULL)
					{
						cms_free(BrwHistory->title[i]);
						BrwHistory->title[i] = NULL;
					}
					break;
				}
				
				leng--;
				ch = 0;
			}
			else
			{
				isItem = CMS_BROWSER_FALSE;
			}
			
			if(BrwHistory->url[i] != NULL)
			{		
				i++;
			}
		}
		else if(leng>(CMS_BROWSER_U32)Filesize)
		{
			break;
		}		
	}
	if(tempcontent!=NULL)
	{
		cms_free(tempcontent);
		tempcontent=NULL;
	}
	BrwHistory->urlCurrent=i-1;	
}

/*==============================================================
*   description  :	Write History record in file system
*   author       :  xiaoyongq 
*   date         :20051008
==============================================================*/
void Cms_Browser_WriteUIHistory()
{	
	unsigned int nwrite;	
	int mtkhistory = NULL;
	P_CMS_BROWSER_U8 title = NULL, url = NULL;
	CMS_BROWSER_U32 i = 0;	
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapHistoryfilename(wap_filename);	
	Cms_Adp_fdelete((const unsigned short *) wap_filename);
	mtkhistory = Cms_Adp_fopen((S8*)wap_filename, FS_CREATE);
	//FS_Delete(L"C:\\wap\\CmsBrwHistory.cnf");		
	//mtkhistory = FS_Open(L"C:\\wap\\CmsBrwHistory.cnf",FS_CREATE);
	if (mtkhistory < 0)
	{
		return;
	}
	else
	{
		if(BrwHistory==NULL)
			return ;		
		while(i<MAXSTOREHISTORY)
		{
			if( BrwHistory->title[i]!=NULL &&BrwHistory->url[i]!=NULL)
			{	
			title =  BrwHistory->title[i];
			url =BrwHistory->url[i];
			FS_Write(mtkhistory, "\n",1, &nwrite);
			FS_Write(mtkhistory, (P_CMS_BROWSER_U8)"cmstitle", 8, &nwrite);
			FS_Write(mtkhistory, "\n",1, &nwrite);
			FS_Write(mtkhistory, (P_CMS_BROWSER_U8)title,  Cms_Browser_StrLen(title), &nwrite);
			FS_Write(mtkhistory, "\n",1, &nwrite);
			FS_Write(mtkhistory, (P_CMS_BROWSER_U8)"cmsurl", 6, &nwrite);
			FS_Write(mtkhistory, "\n",1, &nwrite);
			FS_Write(mtkhistory, (P_CMS_BROWSER_U8)url, Cms_Browser_StrLen(url),&nwrite);		 
			}
			i++;
		}	
		
		FS_Close(mtkhistory);
	}
}
//End history function
/*==============================================================
*   Function Name:	ClearWapDAta
*   Input        :  CMS_BROWSER_VOID
*   Output       :  CMS_BROWSER_VOID
*   description  :	Clear Wap Data
*   author       :  kangzh
*   date         :	08-02-2005
==============================================================*/
CMS_BROWSER_VOID  ClearWapUserData(CMS_BROWSER_VOID) 
{
	U16	setnumber=0;
	S8	setfilename[MMS_FILE_NAME_LEN]={0};

  	Cms_Browser_StartEvent();                 
	/*清除历史数据*/ 
	Cms_Browser_UIClearPageHistory();	 
	/*清除缓存*/ 
	Cms_Browser_ClearCache(); 
	/*服务收件箱*/ 
#ifndef CMS_RESET_UNDELETE_WAPPUSHFILE		
	Cms_Browser_DeleteAllPUSHInfo(); 
	{
		cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
		Cms_GetWapPushfilename(wap_filename);	
		Cms_Adp_fdelete((const unsigned short * )wap_filename);
		//FS_Delete(L"C:\\wap\\CmsPushFile.cnf");
	}
#endif
	/*清除快照*/
	Cms_Browser_DeleteAll_Offline();
	
	/*如果CmsBookMarkFile.cnf  文件不存在，则会自动去配置
	默认主页设置和默认的收藏夹*/
 
	/*删除收藏夹*/
	{
		cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
		Cms_GetWapBookmarkfilename(wap_filename);
		Cms_Adp_fdelete((const unsigned short * )wap_filename);	
		//FS_Delete(L"C:\\wap\\CmsBookMarkFile.cnf");
	}	
	{
		cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
		Cms_GetWapBookfilename(wap_filename);
		Cms_Adp_fdelete((const unsigned short * )wap_filename);
		//FS_Delete(L"C:\\wap\\CmsBook.cnf");
	}
	/*如果CmsSetup.cnf  文件不存在，则会自动配置默认的
	网关设置和默认的图片显示设置*/
 	{
		cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
		Cms_GetWapSetupfilename(wap_filename);
		Cms_Adp_fdelete((const unsigned short * )wap_filename);
		//FS_Delete(L"C:\\wap\\CmsSetup.cnf");                
	}

	/*删除网络列表配置文件*/
	for(;setnumber<SERVICE_LIST_ITEM;setnumber++)
	{
		memset(setfilename,0,MMS_FILE_NAME_LEN);
		sprintf(setfilename,"%swap_set_%dfile.txt",CMS_WAP_APP_PATH,(int)setnumber);
		if(Cms_Adp_FileExists(setfilename))
		{
			Cms_Adp_fdelete((const unsigned short *)(setfilename));
		}
	}
	Cms_Browser_ExitEvent();
}
/* ----------------------------------------------------------------------------
 * Function CmsGetCurrentWapState: 
 *       Purpose:获取当前浏览器状态，是否进入过浏览器模块
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
int CmsGetCurrentWapState()
{
	if(browserflag)
	{
		return CMS_WAP_STATE_BUSY;
	}
	else
	{
		return CMS_WAP_STATE_NULL;
	}
}
/*==============================================================
*   Function Name:	EntryScrWapBrowserByHotkey
*   Input        :  CMS_BROWSER_VOID
*   Output       :  CMS_BROWSER_VOID
*   description  :	一键上网
*   author       :  
*   date         :	
==============================================================*/
void EntryScrWapBrowserByHotkey(U16 ScreenId)
{
	if(!g_msg_cntx.msg_init)
	{
		DisplayPopup((PU8)GetString(STR_WAP_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
		return;
	}
	if(mmsflag.gsend_recv == TRUE)
	{
		DisplayPopup((U8*)GetString(STR_WAP_WARING_NETBUSY), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	Option_Ok=0;
	Down_Scrollbar_OK=0;
	BrowserByHotkey=1;
	BackToIdle=0;
	wap_Tracer("EntryScrWapBrowserByHotkey in");
	if (browserflag == 0)
	{
		SuspendFlag = 0;
		Cms_LoadFile();

		cms_memset(NewLink_UrlEdit, 0x0, sizeof(NewLink_UrlEdit));
		cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
		wap_Tracer("Cms_Browser_StartEvent enter......");
		if (Cms_Browser_StartEvent())
		{			
			exteriorbrowserpage = 0;
			browserflag = 1;			
			CancleDownload = 0;
		}
		else
		{
			wap_Tracer("no memory!");
			//FS_Delete(L"C:\\wap\\CmsCaCheHistory");
			cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
			Cms_GetWapCachefilename(wap_filename);	
			Cms_Adp_fdelete((const unsigned short * )wap_filename);				
			wap_Tracer("no memory!");
			return;
		}
	
		wap_net_data_init();
	}	
#ifdef __MMI_CLAMSHELL__
//	SetInterruptEventHandler(WapClamEventHandler, NULL,MSG_ID_MMI_EQ_GPIO_DETECT_IND);
	/* __MMI_CLAMSHELL__ */
#endif 
	mmi_wap_option_homepage();
	return ;	
}
/*==============================================================
*   Function Name:	MMS_PushLinkBrowser
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
extern P_MESSAGELIST mms_file_manager_get_current_message(void);
void MMS_PushLinkBrowser(void)
{ 
	P_MESSAGELIST		pMsg = NULL;
	
	if(mmsflag.gsend_recv == TRUE)
	{
		DisplayPopup((U8*)GetString(STR_WAP_WARING_NETBUSY), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	MMSPushByBrowser=1;
	Option_Ok=0;	
	wap_Tracer("MMS_PushLinkBrowser in");
	if (browserflag == 0)
	{
		SuspendFlag = 0;
		Cms_LoadFile();

		cms_memset(NewLink_UrlEdit, 0x0, sizeof(NewLink_UrlEdit));
		cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
		wap_Tracer("Cms_Browser_StartEvent enter......");
		if (Cms_Browser_StartEvent())
		{			
			exteriorbrowserpage = 0;
			browserflag = 1;			
			CancleDownload = 0;
		}
		else
		{
			wap_Tracer("no memory!");
			//FS_Delete(L"C:\\wap\\CmsCaCheHistory");
			cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
			Cms_GetWapCachefilename(wap_filename);	
			Cms_Adp_fdelete((const unsigned short * )wap_filename);				
			wap_Tracer("no memory!");
			return;
		}
	
		wap_net_data_init();
	}	
	/*free net struct*/
 	initURL();
	Cms_Browser_SetBackFalse();
	pMsg=(P_MESSAGELIST)mms_file_manager_get_current_message();
	
	Cms_Browser_AddInputHistoryEvent((unsigned char *)pMsg->url); 
	MainMenu_State = WAP_MENU_NEWLINK_MENU;	
	BorwserFormPush=1;
	Browser_page();
}
/*==============================================================
*   Function Name:	EntryScrWapBrowserByUrl
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void EntryScrWapBrowserByUrl(char * url)
{
	if(!g_msg_cntx.msg_init)
	{
		DisplayPopup((PU8)GetString(STR_WAP_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
		return;
	}
	if(mmsflag.gsend_recv == TRUE)
	{
		DisplayPopup((U8*)GetString(STR_WAP_WARING_NETBUSY), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	Option_Ok=0;	
	MMSPushByBrowser=1;/*退出时采用*/
	wap_Tracer("EntryScrWapBrowserByUrl in");
	if (browserflag == 0)
	{
		SuspendFlag = 0;
		Cms_LoadFile();

		cms_memset(NewLink_UrlEdit, 0x0, sizeof(NewLink_UrlEdit));
		cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
		wap_Tracer("Cms_Browser_StartEvent enter......");
		if (Cms_Browser_StartEvent())
		{			
			exteriorbrowserpage = 2;
			browserflag = 1;			
			CancleDownload = 0;
		}
		else
		{
			wap_Tracer("no memory!");
			//FS_Delete(L"C:\\wap\\CmsCaCheHistory");
			cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
			Cms_GetWapCachefilename(wap_filename);	
			Cms_Adp_fdelete((const unsigned short * )wap_filename);				
			wap_Tracer("no memory!");
			return;
		}	
		wap_net_data_init();
	}	
	/*free net struct*/
 	initURL();
	Cms_Browser_SetBackFalse();
	
	/*20060303 cocoma xu add for bug33327*/
	{
		char temp[256]={0};
		if(!(MMS_strstr((char*)url,"http://" )||MMS_strstr((char*)url,"Http://")||MMS_strstr((char*)url,"https://")))
		{
			cms_strcpy((char*)temp,"http://");
			cms_strcat((char*)temp,(char*)url);	
			Cms_Browser_AddInputHistoryEvent((unsigned char *)temp);
		}
		else
		{
			Cms_Browser_AddInputHistoryEvent((unsigned char *)url); 
		}			
	}
	MainMenu_State = WAP_MENU_NEWLINK_MENU;	
	Browser_page();
}
/*=========================================================
Service Id List
==========================================================*/

/*中国移动*/
void wap_init_pre_setting_file_chinamobile()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_CHINAMOBILE);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"China Mobile");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://wap.monternet.com");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"10.0.0.172");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"80");
		
		gWapTemp.gprs_mode = WAP_SERVICE_CHINAMOBILE+GSM_NET_ACCOUNT;

		wap_write_setting_file_by_index(WAP_SERVICE_CHINAMOBILE);
	}
}

/*中華電信*/
void wap_init_pre_setting_file_cht()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_CHT);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"CHT");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://wap.emome.net");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"010.001.001.001");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"8080");
		
		gWapTemp.gprs_mode = WAP_SERVICE_CHT+GSM_NET_ACCOUNT;

		wap_write_setting_file_by_index(WAP_SERVICE_CHT);
	}
}

/*遠傳電信*/
void wap_init_pre_setting_file_fet()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_FET);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"FET");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://mobile.fetnet.net");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"210.241.199.199");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"80");
		
		gWapTemp.gprs_mode = WAP_SERVICE_FET+GSM_NET_ACCOUNT;;

		wap_write_setting_file_by_index(WAP_SERVICE_FET);
	}
}

/*和信電訊*/
void wap_init_pre_setting_file_kgt()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_KGT);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"KGT");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr,(S8*) L"http://mobile1.fetnet.net");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway,(S8*) L"210.241.199.199");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"80");
		
		gWapTemp.gprs_mode = WAP_SERVICE_KGT+GSM_NET_ACCOUNT;
		wap_write_setting_file_by_index(WAP_SERVICE_KGT);
	}
}


/*泛亞電信*/
void wap_init_pre_setting_file_tat()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_TAT);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"TAT");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://www.hank.net.tw");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"211.078.224.100");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"80");
		
		gWapTemp.gprs_mode = WAP_SERVICE_TAT+GSM_NET_ACCOUNT;;

		wap_write_setting_file_by_index(WAP_SERVICE_TAT);
	}
}


/*東信電訊*/
void wap_init_pre_setting_file_mbt()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_MBT);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"MBT");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://www.mobeelife.net");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"192.168.077.005");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"80");
		
		gWapTemp.gprs_mode = WAP_SERVICE_MBT+GSM_NET_ACCOUNT;;
		
		wap_write_setting_file_by_index(WAP_SERVICE_MBT);
	}
}

/* 台灣大哥大*/
void wap_init_pre_setting_file_tcc()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_TCC);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"TCC");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://catch");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"010.001.001.002");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"80");

		gWapTemp.gprs_mode = WAP_SERVICE_TCC+GSM_NET_ACCOUNT;

		wap_write_setting_file_by_index(WAP_SERVICE_TCC);
	}
}
/*西班牙运营商配置情况*/
/* 西班牙Movistar*/
void wap_init_pre_setting_file_spain_movistar(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_SPAIN_MOVISTAR);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"Movistar");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://wap.movistar.com");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"192.168.080.021");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"9201");

		gWapTemp.gprs_mode = WAP_SERVICE_SPAIN_MOVISTAR+GSM_NET_ACCOUNT;

		wap_write_setting_file_by_index(WAP_SERVICE_SPAIN_MOVISTAR);
	}
}
/* 西班牙Vondafone*/
void wap_init_pre_setting_file_spain_vondafone(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_SPAIN_VODAFONE);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"Vondafone");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://wap.vodafone.es");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"212.73.32.10");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"9201");

		gWapTemp.gprs_mode = WAP_SERVICE_SPAIN_VODAFONE+GSM_NET_ACCOUNT;

		wap_write_setting_file_by_index(WAP_SERVICE_SPAIN_VODAFONE);
	}
}
/* 西班牙Vondafone*/
void wap_init_pre_setting_file_spain_amena(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_SPAIN_AMENA);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"AMENA");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://serverwap/");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"010.132.061.010");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"9201");

		gWapTemp.gprs_mode = WAP_SERVICE_SPAIN_AMENA+GSM_NET_ACCOUNT;

		wap_write_setting_file_by_index(WAP_SERVICE_SPAIN_AMENA);
	}
}

/***************泰国运营商彩信配置*********************/
/* 泰国AIS*/
void wap_init_pre_setting_file_thailand_ais(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_THAILAND_AIS);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"AIS");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://wap.mobilelife.co.th");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"203.170.229.34");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"9201");

		gWapTemp.gprs_mode = WAP_SERVICE_THAILAND_AIS+GSM_NET_ACCOUNT;

		wap_write_setting_file_by_index(WAP_SERVICE_THAILAND_AIS);
	}
}
/* 泰国DTAC*/
void wap_init_pre_setting_file_thailand_dtac(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_THAILAND_DTAC);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"DTAC");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://wap.djuice.co.th");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"203.155.200.133");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"9201");

		gWapTemp.gprs_mode = WAP_SERVICE_THAILAND_DTAC+GSM_NET_ACCOUNT;

		wap_write_setting_file_by_index(WAP_SERVICE_THAILAND_DTAC);
	}
}
/* 西班牙Vondafone*/
void wap_init_pre_setting_file_thailand_orange(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)WAP_SERVICE_THAILAND_ORANGE);
	strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)L"Orange");
		pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)L"http://wap.orange.co.th");
		pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)L"10.4.4.4");
		pfnUnicodeStrcpy((S8*)gWapTemp.port,(S8*)L"9201");

		gWapTemp.gprs_mode = WAP_SERVICE_THAILAND_ORANGE+GSM_NET_ACCOUNT;

		wap_write_setting_file_by_index(WAP_SERVICE_THAILAND_ORANGE);
	}
}
#ifdef CMS_PC_CONFIG_SOFTWARE
void wap_init_all_pre_setting_from_pc_file(void)
{
	U8 N_Cfg=0;
	
	for(N_Cfg=0;N_Cfg<cms_wap_profile_default.n_wap_profiles;N_Cfg++)
	{
		if(cms_wap_profile_default.profile[N_Cfg].empty==1)
		{
			S8		tempname[MMS_FILE_NAME_LEN]={0};
			S8		setfilename[MMS_FILE_NAME_LEN]={0};
			S8		tempstr[MMS_MAX_CENTRE_ADDR_LENGTH]={0};
			
			strcpy(setfilename, CMS_WAP_APP_PATH);
			sprintf(tempname,"wap_set_%dfile.txt",(int)N_Cfg);
			strcat(setfilename,tempname );
			memset(&gWapTemp, 0, sizeof(WAP_CONFIG));
			
			cms_utf2unicode((unsigned char*)cms_wap_profile_default.profile[N_Cfg].profile_name,\
							strlen((char*)cms_wap_profile_default.profile[N_Cfg].profile_name),\
							(unsigned short*)tempstr,MMS_MAX_CENTRE_ADDR_LENGTH);
			pfnUnicodeStrcpy((S8*)gWapTemp.service_id, (S8*)tempstr);

			memset(tempstr,0,MMS_MAX_CENTRE_ADDR_LENGTH);
			AnsiiToUnicodeString((S8 *)tempstr, (S8*)cms_wap_profile_default.profile[N_Cfg].homepage_url);
			pfnUnicodeStrcpy((S8*)gWapTemp.centre_addr, (S8*)tempstr);

			memset(tempstr,0,MMS_MAX_CENTRE_ADDR_LENGTH);
			AnsiiToUnicodeString((S8 *)tempstr, (S8*)cms_wap_profile_default.profile[N_Cfg].proxy_ip);
			pfnUnicodeStrcpy((S8*)gWapTemp.gateway, (S8*)tempstr);

			memset(tempstr,0,MMS_MAX_CENTRE_ADDR_LENGTH);
			AnsiiToUnicodeString((S8 *)tempstr, (S8*)cms_wap_profile_default.profile[N_Cfg].proxy_port);
			pfnUnicodeStrcpy((S8*)gWapTemp.port, (S8*)tempstr);

			gWapTemp.gprs_mode = cms_wap_profile_default.profile[N_Cfg].data_account;
			wap_write_setting_file_by_index(N_Cfg);
		}
	}
}
#endif
/*==============================================================
*   Function Name:	wap_init_all_pre_setting_file
*   Input        :  void
*   Output       :  void
*   description  :
*   author       :  
*   date         :
==============================================================*/
void wap_init_all_pre_setting_file(void)
{
#ifdef CMS_PC_CONFIG_SOFTWARE
	wap_init_all_pre_setting_from_pc_file();
#else
	/*中国移动*/
	if(CmsGetWapSupportArea() == CMS_WAPMMS_SUPPOTR_CHINA)
	{
		wap_init_pre_setting_file_chinamobile();
	}
	/*中国台湾六大运营商*/
	else if(CmsGetWapSupportArea() == CMS_WAPMMS_SUPPOTR_TAIWAN)
	{
		wap_init_pre_setting_file_cht();
		wap_init_pre_setting_file_fet();
		wap_init_pre_setting_file_kgt();
		wap_init_pre_setting_file_mbt();
		wap_init_pre_setting_file_tat();
		wap_init_pre_setting_file_tcc();
	}
	/*西班牙运营商*/
	else if(CmsGetWapSupportArea() == CMS_WAPMMS_SUPPOTR_SPAIN)
	{
		wap_init_pre_setting_file_spain_movistar();
		wap_init_pre_setting_file_spain_vondafone();
		wap_init_pre_setting_file_spain_amena();
	}
	/*泰国运营商*/
	else if(CmsGetWapSupportArea() == CMS_WAPMMS_SUPPOTR_THAILAND)
	{
		wap_init_pre_setting_file_thailand_ais();
		wap_init_pre_setting_file_thailand_dtac();
		wap_init_pre_setting_file_thailand_orange();
	}
#endif
}
/*****************************************************************************
* FUNCTION
*  wap_write_setting_file_by_index
* DESCRIPTION
*  保存网络设置内容到文件(根据运营商的ID)

*****************************************************************************/

void wap_write_setting_file_by_index(U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	FS_HANDLE 	fp = 0;
	S8			tempname[MMS_FILE_NAME_LEN]={0};
	S8			setfilename[MMS_FILE_NAME_LEN]={0};
	char* 		buffer = NULL;
	char* 		buffer_pos = NULL; 
	S32 			max_len = 0, buffer_len = 0, len = 0;
	U16 			rd = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)index);
	strcat(setfilename,tempname );
	
	/* buffer最大长度为地址长度和网关长度之和，另外再分配64个字节 */
	max_len = MMS_MAX_SERVICE_ID_LENGTH+MMS_MAX_CENTRE_ADDR_LENGTH + \
			MMS_MAX_GATEWAY_LENGTH +MMS_MAX_PORT_LENGTH + 64;

	buffer = (char*)mms_Malloc(max_len);
	if (!buffer)
	{
		mms_Tracer((char*)"confirm config file buffer error!!! ");
		return;
	}
	memset(buffer, 0, max_len);
	buffer_pos = buffer;

	/* 开始将数据写入buffer */
	mms_Tracer((char*)"*****************start put into buffer***************");
	/*写入运营商ID  */
	*buffer_pos = (S8)WAP_CFG_SERVICE_ID;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gWapTemp.service_id)+2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gWapTemp.service_id, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of service_id ***************");
	/*写入运营商地址*/
	*buffer_pos = (S8)WAP_CFG_CENTRE;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gWapTemp.centre_addr)+2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gWapTemp.centre_addr, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of centre address***************");
	/*写入运营商网关*/
	*buffer_pos = (S8)WAP_CFG_GATEWAY;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gWapTemp.gateway) + 2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gWapTemp.gateway, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of gateway***************");
	/*写入运营商端口号*/
	*buffer_pos = (S8)WAP_CFG_PORT;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gWapTemp.port) + 2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gWapTemp.port, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of gateway***************");
	/*写入GPRS设定*/
	*buffer_pos = (S8)WAP_CFG_GPRS;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gWapTemp.gprs_mode;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of gprs mode***************");
	
	/* 完成将数据写入buffer */
	fp = Cms_Adp_fopen((S8*)setfilename, FS_CREATE_ALWAYS);
	if (fp < 0)
	{
		mms_Tracer((char*)"confirm config file error!!! ");
		if (buffer)
		{
			mms_Free(buffer);
			buffer = NULL;
			buffer_pos = NULL;
		}
		Cms_Adp_fclose(fp);
		return;
	}
	if (0 != Cms_Adp_fwrite(fp, buffer, buffer_len, ( unsigned int *)(&rd))) 
	{
		Cms_Adp_fclose(fp);
		return;
	}
	Cms_Adp_fclose(fp);
	/* 释放内存资源 */
	if (buffer)
	{
		mms_Free(buffer);
		buffer = NULL;
		buffer_pos = NULL;
	}	
}
/*****************************************************************************
* FUNCTION
*  wap_read_setting_file_by_index
* DESCRIPTION
*   读取信息设置配置存放至gWapTemp结构的成员中(根据运营商的ID)
*
*****************************************************************************/
void wap_read_setting_file_by_index(U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	FS_HANDLE 	fp = 0;
	S32 			file_len = 0;
	S32 			file_pos = 0;
	char* 		file_buf = NULL;
	S8*			ptr_buf = NULL;
	S8			tempname[MMS_FILE_NAME_LEN]={0};
	S8			setfilename[MMS_FILE_NAME_LEN]={0};
	int 			flag_continue = 0;
	U16 			rd = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	strcpy(setfilename, CMS_WAP_APP_PATH);
	sprintf(tempname,"wap_set_%dfile.txt",(int)index);
	cms_strcat(setfilename,tempname );
	memset(&gWapTemp, 0, sizeof(WAP_CONFIG));
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		mms_Tracer((char*)"msg setting file not exists!!!!!!");
		return;
	}
	fp = Cms_Adp_fopen((S8*)setfilename, FS_READ_ONLY);
	if (fp < 0)
	{
		mms_Tracer((char*)"file not exists!!!");
		return ;
	}
	Cms_Adp_GetFileSize(fp, (unsigned int*)(&file_len));
	
	if(file_len <= 0)
	{
		Cms_Adp_fclose(fp);
		mms_Tracer((char*)"file is empty!!!");
		return ;
	}
	/* 防止越界多分配16个字节 */
	file_buf = (char*)mms_Malloc(file_len + 16);

	if (!file_buf)
	{
		mms_Tracer((char*)"fail to allocate memory!!!");
		Cms_Adp_fclose(fp);
		return;
	}
	memset(file_buf, 0, file_len + 16);
	if (0 != Cms_Adp_fread(fp, file_buf, file_len, (unsigned int*)(&rd))) 
	{
		mms_Tracer((char*)"mms_init_message_settings read error!");
		Cms_Adp_fclose(fp);
		mms_Free(file_buf);
		file_buf = NULL;
		return;
	}
	Cms_Adp_fclose(fp);

	while (1)
	{
		/* 文件末尾退出外循环 */
		if(file_pos >= file_len)
		{
			break;
		}
		flag_continue = 1;

		while(flag_continue)    /* 内循环BEGIN  */
		{
			S8 msg_cfg_field = WAP_CFG_UNKNOWN;
			U8 msg_cfg_field_len = 0;
			
			/* 出现异常情况 */
			if(file_pos >= file_len)
			{ 
				mms_Free(file_buf);
				file_buf = NULL;
				mms_Tracer((char*)"error!!! read config!!!");
				return ;				
			}			
			/* 读出每个field的类型和长度 */
			msg_cfg_field = (S8)(*(file_buf + file_pos));
			msg_cfg_field_len = (U8)(*(file_buf + file_pos + 1));
			/* 指向field的值 */
			ptr_buf = file_buf + file_pos + 2;
			file_pos += (msg_cfg_field_len + 2);
			
			if(file_pos > file_len)
			{
				mms_Free(file_buf);
				file_buf = NULL;
				return ;
			}			
			switch(msg_cfg_field)
			{
				/*运营商ID */
			case WAP_CFG_SERVICE_ID:
				if(msg_cfg_field_len != 0)
				{
					memset(gWapTemp.service_id, 0, MMS_MAX_SERVICE_ID_LENGTH);
					memcpy(gWapTemp.service_id, ptr_buf, msg_cfg_field_len);
				}
				break;
				/*运营商地址*/
			case WAP_CFG_CENTRE:
				if(msg_cfg_field_len != 0)
				{
					memset(gWapTemp.centre_addr, 0, MMS_MAX_CENTRE_ADDR_LENGTH);
					memcpy(gWapTemp.centre_addr, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* 网关 */
			case WAP_CFG_GATEWAY:
				if(msg_cfg_field_len != 0)
				{
					memset(gWapTemp.gateway, 0, MMS_MAX_GATEWAY_LENGTH);
					memcpy(gWapTemp.gateway, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* 端口 */
			case WAP_CFG_PORT:
				if(msg_cfg_field_len != 0)
				{
					memset(gWapTemp.port, 0, MMS_MAX_PORT_LENGTH);
					memcpy(gWapTemp.port, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* GPRS设定 */
			case WAP_CFG_GPRS:
				if(msg_cfg_field_len != 0)
				{
					gWapTemp.gprs_mode = (S32)(*ptr_buf);
				}
				/* 状态标记在末尾,退出内循环 */
				flag_continue = 0;
				break;
			default:
				mms_Free(file_buf);
				file_buf = NULL;
				return ;					
			}
		}   /* 内循环结束END */
	}
	if (file_buf)
	{
		mms_Free(file_buf);
		file_buf = NULL;
	}
}

void wap_set_curr_file_to_setting(void)
{
	int i = 0;
	int j;
	U8 url[BOOK_URL_LENGTH*2+2] = {0};

	wap_read_setting_file_by_index(ghiliindex);
	{
		memset(NewLink_UrlEdit, 0, sizeof(NewLink_UrlEdit));
		memset(Setting_Gateway, 0, sizeof(Setting_Gateway));
		memset(Setting_Port, 0, sizeof(Setting_Port));
		pfnUnicodeStrcpy((S8*)NewLink_UrlEdit, (S8*)gWapTemp.centre_addr);
		pfnUnicodeStrcpy((S8*)Setting_Gateway, (S8*)gWapTemp.gateway);
		pfnUnicodeStrcpy((S8*)Setting_Port,(S8*)gWapTemp.port);

		netacc_id= gWapTemp.gprs_mode;
		while ((NULL != NewLink_UrlEdit[i])&& i<sizeof(NewLink_UrlEdit))
		{
			j = i/2;
			url[j] = NewLink_UrlEdit[i];
			i = i +2;
		}
		Cms_Browser_SetupHomePage((unsigned char *)url);
		Cms_Browser_SetupPort((unsigned char *)Setting_Port);
		Cms_Browser_SetupGateWay((unsigned char *)Setting_Gateway);
		
		wap_net_data_init();
		if( sock_addr.port ==0 || sock_addr.addr[0] ==0 ||(sock_addr.addr[1] ==0 && sock_addr.addr[2] ==0 && sock_addr.addr[3] ==0))
		{
			/*如设置错误就恢复初始设置*/
			Cms_Browser_SetupGateWay((unsigned char *)WAP_CMCC_GATEWAY_ADDRESS_DEFAULT);		
			wap_net_data_init();
			DisplayPopup((U8*)GetString(STR_WAP_GATEWAY_ERROR_ID), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
			return ;
		}
		Cms_Browser_SaveBrowserSetupToFile();
		Cms_SaveSetupFile();
	}
	gconfig.wap_service_activeitem=ghiliindex;
	mms_write_message_settings_file();
	DisplayPopupCallBack((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE, GoBack2History);
}

void wap_set_setting_file_for_default_active(void)
{
	int i = 0;
	int j;
	U8 url[BOOK_URL_LENGTH*2+2] = {0};

	wap_read_setting_file_by_index(gconfig.wap_service_activeitem);
	{
		memset(NewLink_UrlEdit, 0, sizeof(NewLink_UrlEdit));
		memset(Setting_Gateway, 0, sizeof(Setting_Gateway));
		memset(Setting_Port, 0, sizeof(Setting_Port));
		pfnUnicodeStrcpy((S8*)NewLink_UrlEdit, (S8*)gWapTemp.centre_addr);
		pfnUnicodeStrcpy((S8*)Setting_Gateway, (S8*)gWapTemp.gateway);
		pfnUnicodeStrcpy((S8*)Setting_Port,(S8*)gWapTemp.port);

		netacc_id= gWapTemp.gprs_mode;
		while ((NULL != NewLink_UrlEdit[i])&& i<sizeof(NewLink_UrlEdit))
		{
			j = i/2;
			url[j] = NewLink_UrlEdit[i];
			i = i +2;
		}
		Cms_Browser_SetupHomePage((unsigned char *)url);
		Cms_Browser_SetupPort((unsigned char *)Setting_Port);
		Cms_Browser_SetupGateWay((unsigned char *)Setting_Gateway);
		
		wap_net_data_init();
		if( sock_addr.port ==0 || sock_addr.addr[0] ==0 ||(sock_addr.addr[1] ==0 && sock_addr.addr[2] ==0 && sock_addr.addr[3] ==0))
		{
			/*如设置错误就恢复初始设置*/
			Cms_Browser_SetupGateWay((unsigned char *)WAP_CMCC_GATEWAY_ADDRESS_DEFAULT);		
			wap_net_data_init();
			DisplayPopup((U8*)GetString(STR_WAP_GATEWAY_ERROR_ID), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
			return ;
		}
	}
}

//浏览器java 下载接口
void CmsPostJavaxxxReport(char *pUrl, unsigned char *pContent, int len, 
							  brwproc call_back, int report_status)
{
	/*init wap browser */
	wap_Tracer("CmsPostJavaxxxReport enter......");
	if (browserflag == 0)
	{
		SuspendFlag = 0;
		Cms_LoadFile();

		cms_memset(NewLink_UrlEdit, 0x0, sizeof(NewLink_UrlEdit));
		cms_memset(InputContent_Edit, 0x0, sizeof(InputContent_Edit));
		wap_Tracer("CmsPostJavaxxxReport browserflag......");
		
		if (Cms_Browser_StartEvent())
		{			
			exteriorbrowserpage = 0;
			browserflag = 1;			
			CancleDownload = 0;
		}
		else
		{
			wap_Tracer("no memory!");
			cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
			Cms_GetWapCachefilename(wap_filename);	
			Cms_Adp_fdelete((const unsigned short * )wap_filename);				
			return;
		}
		wap_net_data_init();
	}
	wap_Tracer("CmsPostJavaxxxReport enter don't init");
	CmsPostJarDownloadReport(pUrl, pContent, len,call_back, report_status);
	
}
	
#endif // __MOD_SMSAL__
#endif
