
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
 *     Create Date: 08/25/2005
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
#include "fmt_def.h"
#include "EventsGprot.h"
#include "HistoryGprot.h"
#include "GlobalMenuItems.h"
#include "GlobalConstants.h"
#include "Globaldefs.h"
#include "gui_setting.h"
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
#include "MmsResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SmsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "CellBroadcastType.h"
#ifdef __MMI_MESSAGES_CHAT__
/* under construction !*/
/* under construction !*/
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
#include "PhoneBookDef.h"

#include "wgui_status_icons.h"
#include "gpioInc.h"
#include "KeyBrd.h"
#include "SubLCDHistoryGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "Soc_api.h"
#include "audioInc.h"
#include "aud_defs.h"
#include "wap.h"
#ifndef __GDI_MEMORY_PROFILE_2__
	#define __GDI_MEMORY_PROFILE_2__
#endif

#ifdef __MMI_TOUCH_SCREEN__
#include "TouchScreenGprot.h"
#include "wgui_touch_screen.h"
#endif

#include "gdi_include.h"
#ifdef CMS_SURPPORT_PNG_BMP
#include "gdi_image_png.h"
#endif
#include "WrapperGprot.h"
#include "stdlib.h"
#include "HelpProt.h"

//...mms header begin
#include "Cms_MMSDoc.h"
#include "Cms_MMSProvide.h"

#include "CmsBrowserPublic.h"
#include "CmsBrowserAPI.h"
#include "CmsFunc.h"

#include "Cms_BRWProvide.h"
#include "Cms_BrwCfg.h"
#include "Cms_BRWGlobal.h"
#include "CMSPushSMS.h"
#include "CmsBrowserCfg.h"
#include "cmswapmmsadp.h"
#include "CmsMMFile.h"
//...mms header end

#include "gpioInc.h"
#include "SmsGuiInterfaceProt.h"
#include "SmsGuiInterfaceType.h"

#include "Wgui_status_icons.h"

#include "CmsWapMmsAdp.h"
#include "WapResourceData.h"

#include "SMSApi.h"
#include "SMSStruct.h"

#include "mmi_msg_context.h"
#include "SmsGuiInterfaceType.h"
#include "FileManagerDef.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#undef __NEWSIMULATOR


#define FMGR_SELECT_FILE   							0x01   

//彩信消息循环定义
#define CMS_MESSAGE_MMS_START_ID					0x0100		/*=== 彩信消息号起始值 ===*/
#define CMS_MESSAGE_MMS_SMS_ARRIVE				CMS_MESSAGE_MMS_START_ID		  /*=== 短消息收到开始处理 ===*/
#define CMS_MESSAGE_MMS_RECVD                  			(CMS_MESSAGE_MMS_START_ID+1)      /*=== 收到彩信数据开始处理 ===*/
#define CMS_MESSAGE_MMS_SEND_OK					(CMS_MESSAGE_MMS_START_ID+2)      /*=== 发送彩信成功 ===*/
#define CMS_MESSAGE_MMS_RECVD_FAILED            		(CMS_MESSAGE_MMS_START_ID+3)      /*=== 接收彩信失败 ===*/
#define CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN    (CMS_MESSAGE_MMS_START_ID+4)      /*=== 发送彩信失败 ===*/
#define CMS_MESSAGE_MMS_SEND_MESSAGE			(CMS_MESSAGE_MMS_START_ID+5)      /*=== 发送彩信		===*/
#define CMS_MESSAGE_MMS_RECEIVE_MESSAGE		(CMS_MESSAGE_MMS_START_ID+6)      /*=== 接收彩信		===*/
#define CMS_MESSAGE_MMS_CONNECT_FAILED			(CMS_MESSAGE_MMS_START_ID+7)      /*=== 创建连接失败 ===*/
#define CMS_MESSAGE_MMS_PLAY_MESSAGE			(CMS_MESSAGE_MMS_START_ID+8)      /*=== 播放彩信		===*/
//彩信消息循环定义


#define 		MMI_ORIGIN_Y 			Cms_GetORIGIN_Y()
#define		MMI_LINE_HEIGHT 		Cms_GetLINE_HIGHT()
#define		MMI_SCREEN_LINE      	Cms_GetSCREEN_LINE()
#define		MMI_MMS_TITLE_HIGHT   Cms_GetORIGIN_Y()

#if defined(__MMI_MAINLCD_240X320__)
 #define MMS_PROGRESS_INDICATOR_HEIGHT MMI_CONTENT_HEIGHT /*客户根据屏幕参数进行调整*/
#else
 #define MMS_PROGRESS_INDICATOR_HEIGHT MMI_CONTENT_HEIGHT /*客户根据屏幕参数进行调整*/
#endif

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern P_CMS_BROWSERINFO   		pBrowserInfo;
extern GPRSDataAccountNode 		g_GPRS_DataAccount[MAX_DATA_ACCOUNT_GPRS_LIMIT];
extern S8 						pbEmailAddress[];

extern int 						SuspendFlag;
extern int 						browserflag;
extern const audio_resource_struct 	mtk_resource_mms_sounds[4];/*为彩信模版而增加*/
#ifdef SUPPORT_MTK_6226
extern idle_keylock_struct			g_keylock_context;
#else
extern U16	 					gKeyPadLockFlag;
#endif
extern mmi_frm_sms_msgbox_struct 	mmi_frm_sms_msg_box[];
extern WAP_CONFIG 				gWapTemp;

extern U8						gphb_flag;
extern U8						phb_callbuf[MMS_MAX_SEND_TO_SIZE];

extern const U16 gIndexIconsImageList[];
#ifdef CMS_PC_CONFIG_SOFTWARE
extern cms_wap_profile_struct  cms_wap_profile_default;
extern cms_mms_profile_struct  cms_mms_profile_default;
extern cms_wap_bookmark_struct cms_wap_bookmark_default;
extern cms_wap_config_struct   cms_wap_config_default;
extern cms_mms_config_struct   cms_mms_config_default;
#endif
/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern S8** mmi_msg_mms_get_numbers_from_text(U8* text, U16 bufLen, U16*  numbersCount);
extern void MMS_PushLinkBrowser(void);
extern void mms_get_randstring(CMS_MMS_S8 filename[64]);
extern U8* mmi_frm_sms_get_sms_timestamp (U8 type, U16 index);
extern void mmi_frm_sms_get_sms_list_index (U8* type, U16* index, U16 msgbox_index);
extern int  cms_utf2unicode(unsigned char*utf8,int utf_len,unsigned short *unicode,int uni_len);
/***************************************************************************** 
* Typedef 
*****************************************************************************/
enum
{
	MSG_HDR_TYPE_UNKNOWN = 0,
	MSG_HDR_TYPE_FILENAME,		/* MMS文件名 起始字段 */
	MSG_HDR_TYPE_ADDRESS,		/* MMS(retrieve)发件人/(send req)第一个收件人 */
	MSG_HDR_TYPE_CC_ADDRESS,
       MSG_HDR_TYPE_BCC_ADDRESS,
	MSG_HDR_TYPE_SUBJECT,		/* 主题 */
	MSG_HDR_TYPE_DATE,			/* MMS(retrieve)接收时间/ (send req)发送时间*/
	MSG_HDR_TYPE_URL,				/* PUSH消息的URL */
	MSG_HDR_TYPE_STATE,			/* MMS状态信息 结束字段 */
	MSG_HDR_TYPE_SIZE	,			/* 信息大小 */
	MSG_HDR_TYPE_EXPRIY,			/*消息有效期*/
#ifdef SUPPORT_OTA_PUSH
	MSG_HDR_TYPE_OTA_NAME,			/*OTA_NAME		*/

	MSG_HDR_TYPE_OTA_GATEWAY,		/*OTA_GATEWAY	*/
	MSG_HDR_TYPE_OTA_PORT,			/*OTA_PORT		*/
	MSG_HDR_TYPE_OTA_NETACC,		/*OTA_NETACC	*/

	MSG_HDR_TYPE_OTA_MURL,			/*OTA_MURL		*/
	MSG_HDR_TYPE_OTA_SMSC,			/*OTA_SMSC		*/

	MSG_HDR_TYPE_OTA_ISPNAME,		/*OTA_ISPNAME		*/
	MSG_HDR_TYPE_OTA_CSDSCODE,		/*OTA_CSDSCODE	*/
	MSG_HDR_TYPE_OTA_APN,			/*OTA_APN		*/
	MSG_HDR_TYPE_OTA_USER,			/*OTA_USER		*/
	MSG_HDR_TYPE_OTA_PASSW,			/*OTA_PASSW	*/
	MSG_HDR_TYPE_OTA_AUTHTYPE,		/*AUTHTYPE		*/
	MSG_HDR_TYPE_OTA_LOGINTYPE,		/*LOGINTYPE		*/
	
	MSG_HDR_TYPE_OTA_BMURL,			/*OTA_BMURL	*/
	MSG_HDR_TYPE_OTA_BMNAME,		/*OTA_BMNAME	*/
#endif
	MSG_HDR_TYPE_MSGTYPE		/* 信息类型 */
};
	
enum
{
	MSG_CFG_UNKNOWN = 0,
	MSG_CFG_SERVICE_ID,			/* 运营商ID */
	MSG_CFG_CENTRE,				/* 彩信中心地址 */
	MSG_CFG_GATEWAY,				/* 网关 */
	MSG_CFG_PORT,					/* 端口 */
	MSG_CFG_EXPIRES,				/* 有效期*/
	MSG_CFG_SENDSIZE,				/* 发送大小 */
	MSG_CFG_RETRIEVESIZE,			/* 接收大小*/
	MSG_CFG_FRAMETIME,			/* 页时间 */
	MSG_CFG_REPORT,				/* 发送报告 */
	MSG_CFG_ANONYMOUS,			/* 匿名发送 */
	MSG_CFG_READ_RPT,				/* 阅读报告 */
	MSG_CFG_PRIORITY,				/* 优先级 */
	MSG_CFG_RETRIEVE,				/* 接收方式 */
	MSG_CFG_GPRS,					/* GPRS模式设定 */
	MSG_CFG_MMS_ACTIVEITEM,		/* 当前MMS 启用的运营商*/
	MSG_CFG_WAP_ACTIVEITEM		/* 当前WAP 启用的运营商*/
	
};

enum
{
	BOX_OPTIONS_UNKNOWN = 0,	
	BOX_OPTIONS_REPLY,			/* 回复 */
	BOX_OPTIONS_FORWARD,			/* 转发 */
	BOX_OPTIONS_EDIT				/* 编辑 */
};

enum
{
	INPUT_OPTION_UNKNOWN = 0,
	INPUT_OPTION_TEXT,			/* 文本 */
	INPUT_OPTION_SUBJECT,			/* 主题 */
	INPUT_OPTION_SERVICE_ID,		/* 运营商ID*/
	INPUT_OPTION_CENTRE_ADDR,	/* 彩信中心 */
	INPUT_OPTION_GATEWAY,		/* 网关 */
	INPUT_OPTION_PORT,			/* 端口 */
	INPUT_OPTION_SAVE_MUSIC,		/* 保存音乐 */
	INPUT_OPTION_SAVE_IMAGE	,	/* 保存图像 */
	INPUT_OPTION_SAVE_ACCESSORY		/* 保存附件 */
};

/***************************************************************************** 
*  Global Variable
*****************************************************************************/

P_MANAGER	    	pgManager = NULL;			/*文件管理*/
pMMS_EDocument	gpeditor_doc = NULL;			/*编辑时的彩信结构		*/
TEXT_EDIT       	gedit;						/*编辑时的全局结构		*/
MMS_CONFIG		gconfig,gconfigtemp;			/* 信息设置结构/预置项	*/
pSENDTO_LIST	pgsendtolist = NULL;			/*收件人链表				*/
pSENDTO_LIST	pgsendcclist = NULL;			/*CC  链表					*/
pSENDTO_LIST	pgsendbcclist = NULL;			/*BCC 链表					*/

mms_flag 		mmsflag;					/*彩信标志结构	*/
S32				ghiliindex = 0;
S32				ghiliindex1 = 0;
S32				gCurActionItem = 0;

U16				gnStrItemList[12] = {0};		/*编辑选项的STRING ID				*/
U16				ginput_screen = 0;			/*确定是那个INPUT输入框的		*/
U16				gbox_operation = 0;			/*确定是信箱编辑选择			*/
U16				gsendto_options = 0;			/*确定是那个TO/CC/BCC的Screen	*/

U8*             		gaudio_buf;					/*释放声音BUF		*/
U8*             		ganimation_buf;				/*释放动画BUF		*/
BOOL  			gif_play_from_mms=FALSE;	/*		*/
BOOL  			cms_wapmms_init=FALSE;	/*CMS WAPMMS模块初始化标志*/

S8   				UnicodeBuf[MAX_SHOW_STRING_BUF*16];/*显示unicde 编码(如信息详情)*/
S32				gauto_recmmssize=0;		/*自动接收时消息大小		*/
S32				send_recmmssize=0;			/*接收发送消息大小			*/
int             		sendover = 0;
pBOOL			gbmmsflag = FALSE;			/*标注是否进入彩信模块*/
P_MESSAGELIST	pCurFwrReMsg=NULL;			/*当前转发回复( 发件箱发送)的彩信节点指针*/

S32 				progress_value=0;			/*	进度条进度值	*/
vertical_scrollbar 					play_show_vbar;	/*	滚动条	*/
horizontal_progress_indicator	 	show_process_bar;	/*	进度条	*/

S8				gNewind_fname[MAX_URL_LENGTH];		/*新消息到来时的唯一的ID*/
U8				MmsDialnumber[MAX_USE_NUMBERS][40]={0};		/*彩信号码列表*/
U8 				servicelist[SERVICE_LIST_ITEM][MMS_MAX_SERVICE_ID_LENGTH]={0};		/*运营商列表*/
U16 				mmsProCapStrId=0;
U16 				mmsProbodyStrId=0;
U16 				mmsProAnimationId=0;
U16 				mmsProRSKStrId=0;

/***************************************************************************** 
* Functions Decleration 
*****************************************************************************/
static void mms_init_app(void);
static void mms_init_global_param(void);
static void mms_init_sms_net(void);
static void mmi_mms_menu_init(void);
static S32 mmi_box_list_get_hint(S32 item_index, UI_string_type *hint_array);
static void mmi_mms_highlight_inbox(void);
static void mmi_mms_highlight_outbox(void);
static void mmi_mms_highlight_draftbox(void);
static void mmi_mms_highlight_setting(void);
static void mmi_mms_highlight_setting_edit_option(void);
static void mmi_mms_highlight_setting_edit_option_edit(void);
static void mmi_mms_highlight_setting_edit_option_activate(void);

static void mms_init_all_pre_setting_file(void);
static void mms_write_msg_setting_file_by_index(U16 index);
static void mms_read_msg_setting_file_by_index(U16 index);
static void mms_set_curr_file_to_setting(void);
static void mms_set_setting_file_for_default_active(void);
static void mmi_mms_highlight_memoty_status(void);
static void mmi_mms_highlight_new_msg(void);
static void mmi_mms_inbox_hint(U16 index);
static void mmi_mms_outbox_hint(U16 index);
static void mmi_mms_draftbox_hint(U16 index);
static void mmi_mms_highlight_add_to(void);
static void mmi_mms_highlight_add_cc(void);
static void mmi_mms_highlight_add_bcc(void);
static void mmi_mms_highlight_subject(void);
static void mmi_mms_highlight_edit_content(void);
static void mmi_mms_highlight_send_options(void);
static void mmi_mms_to_hint(U16 index);
static void mmi_mms_cc_hint(U16 index);
static void mmi_mms_bcc_hint(U16 index);
static void mmi_mms_save_message_and_exit(void);
static  void mmi_mms_no_save_message_and_exit(void);

static BOOL mmi_mms_check_phone_number (U8* phoneAddr);
static void mmi_mms_subject_hint(U16 index);
static void mmi_mms_content_hint(U16 index);
static void mmi_mms_highlight_add_number_input(void);
static void mmi_mms_highlight_add_email_input(void);
static void mmi_mms_highlight_amend_sendto(void);
static void mmi_mms_highlight_del_sendto(void);
static void mmi_mms_highlight_del_all_sendto(void);
static void mmi_mms_highlight_edit_text(void);
static void mmi_mms_highlight_new_frame(void);
static void mmi_mms_highlight_add_image(void);
static void mmi_mms_highlight_add_music(void);
static void mmi_mms_highlight_add_accessory(void);
static void mmi_mms_highlight_set_frametime(void);
static void mmi_mms_highlight_del_image(void);
static void mmi_mms_highlight_del_music(void);
static void mmi_mms_highlight_del_accessory(void);
static void mmi_mms_highlight_del_frame(void);
static void mmi_mms_highlight_empty_text(void);
static void mmi_mms_highlight_next_frame(void);
static void mmi_mms_highlight_pre_frame(void);
static void mmi_mms_highlight_send(void);
static void mmi_mms_highlight_play(void);
static void mmi_mms_highlight_box_play(void);
static void mmi_mms_highlight_save(void);
static void mmi_mms_highlight_save_send(void);
static void mmi_mms_highlight_reply(void);
static void mmi_mms_highlight_details(void);
static void mmi_mms_highlight_forward(void);
static void mmi_mms_highlight_save_image(void);
static void mmi_mms_highlight_save_music(void);
static void mmi_mms_highlight_save_accessory(void);
static void mmi_mms_highlight_get_number(void);
static void mmi_mms_highlight_del(void);
static void mmi_mms_highlight_del_all(void);

static void mmi_mms_highlight_inbox_push_download(void);
static void mmi_mms_highlight_draftbox_edit(void);
static void mmi_mms_highlight_draftbox_send(void);
static void mmi_mms_highlight_draftbox_send_and_save(void);

static void mmi_mms_highlight_template(void);
static void mmi_mms_highlight_template_preview(void);
static void mmi_mms_highlight_template_details(void);
static void mmi_mms_highlight_template_write_message(void);

static void mmi_mms_entry_empty_box(void);
static void mmi_mms_highlight_empty_box(void);
static void mmi_mms_highlight_empty_inbox(void);
static void mmi_mms_highlight_empty_outbox(void);
static void mmi_mms_highlight_empty_draftbox(void);
static void mmi_mms_highlight_empty_allbox(void);
static void mmi_mms_highlight_setting_sending(void);
static void mmi_mms_highlight_setting_retrieving(void);

void mmi_update_mms_idel_icon(void);
void mmi_mms_exit_to_idle(void);
static void mmi_mms_exit_main_menu(void);

static void mms_play_message_callback(void);
static void mmi_mms_indication_save_message(void);
static void mmi_mms_entry_sendto_list(void);

static void mms_get_box_index(S32 nIndex);
static pBOOL mmi_sendto_list_get_item(S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask);
static S32 mmi_sendto_list_get_hint(S32 item_index, UI_string_type *hint_array);

static void mmi_mms_entry_sendtolist_options(void);
static void mmi_mms_exit_sendto_menulist(void);
static void mmi_mms_entry_input_options(void);
static void mmi_mms_exit_sub_input(void);
static void mmi_mms_exit_to_box_options(void);

static void mmi_get_cur_sub_hiliIndex(S32 hiliteid);
static void mmi_mms_edit_options_hander(void);
static void mmi_mms_entry_edit_message(void);
static void mmi_mms_entry_edit_text_input(void);
static void mmi_mms_edit_down_frame(void);
static void mmi_mms_edit_up_frame(void);
static void mmi_mms_edit_next_frame(void);
static void mmi_mms_edit_previous_frame(void);

static void mmi_mms_edit_empty_text(void);
static void mmi_mms_edit_delete_image(void);
static void mmi_mms_edit_delete_music(void);
static void mmi_mms_edit_delete_accessory(void);
static void mmi_mms_edit_pre_set_frame_time(void);
static void mmi_mms_edit_set_frame_time(void);
unsigned int mms_get_slidetime_setting(void);

static void mmi_mms_edit_show_message(void);
static void mmi_mms_frame_time_confirm(void);
static void mmi_mms_edit_new_frame(void);
static void mmi_mms_edit_delete_frame(void);

static void mmi_mms_box_play_message(void);
static void mmi_mms_play_message(void);
static void mmi_mms_redraw_edit_show_message(void);
static void mmi_mms_redraw_play(void);
static  void mmi_mms_exit_play(void);
static void mmi_mms_play_previous_frame(void);
static void mmi_mms_play_next_frame(void);
static void mmi_mms_play_down_frame(void);
static void mmi_mms_play_up_frame(void);
static void mmi_mms_stop_play_frame(void);
static void mmi_mms_stop_play_message(void);
static void mms_play_music(void);
static void mmi_mms_entry_send_message(void);
static void mms_before_draftbox_send_message(void);
static void mms_before_draftbox_send_and_save(void);
static void mmi_mms_highlight_outbox_send(void);
static void mms_before_box_send_message(void);

static void mms_before_send_message(void);

static void mms_cancel_send_retrieve(void);
void mmi_get_index(S32 nIndex);
static pBOOL mmi_box_list_get_item(S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask);
static void mmi_mms_inbox_judge_msg_type(void);
static void mmi_mms_enter_inbox_push_options(void);
static void mmi_mms_entry_amend_sendto(void);
static void mmi_mms_enter_outbox_options(void);

static void mmi_mms_entry_templates(void);
static void mmi_mms_entry_template_preview(void);
static void mmi_mms_entry_template_details(void);
static void mmi_mms_entry_template_write_message(void);
static void mmi_mms_get_template_index(S32 nIndex);
static void mmi_mms_entry_template_options(void);

static int mms_get_receive_max_size(void);
static int mms_get_send_max_size(void);
static U8 mmi_mms_clam_event_hander(void* ptr);

P_MESSAGELIST mms_file_manager_get_current_message(void);
static void mmi_mms_enter_inbox_message_options(void);
static void mms_get_save_index(S32 nIndex);
static pBOOL mmi_image_list_get_item(S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask);
static pBOOL mmi_accessory_list_get_item(S32 item_index, UI_string_type str_buff, UI_image_type* acc_buff_p, U8 str_acc_mask);
static S32 mmi_image_list_get_hint(S32 item_index, UI_string_type *hint_array);
static S32 mmi_accessory_list_get_hint(S32 item_index, UI_string_type *hint_array);
static void mmi_mms_entry_view_save_image(void);
static void mmi_mms_entry_view_save_accessory(void);
static void mmi_mms_image_filename_input(void);
static void mmi_mms_accessory_filename_input(void);
static void mmi_mms_redraw_view_image(void);
static pBOOL mmi_music_list_get_item(S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask);
static S32 mmi_music_list_get_hint(S32 item_index, UI_string_type *hint_array);
static void mmi_mms_play_save_music(void);
static void mmi_mms_music_filename_input(void);
static void mms_save_phone_number_confirm(void);

static void mms_sendto_input_empty_lsk_hdlr (void);
static void mms_sendto_input_no_empty_lsk_hdlr(void);
static int mms_judge_mms_box_size_count(P_MESSAGELIST pMsg);
static void mms_judge_receive_push_del_msg(void);
int mmi_mms_print_hz_onscr(int x, int y, unsigned char* str);
int mmi_mms_text_line(P_CMS_BROWSER_U8 str, CMS_BROWSER_U32  x, CMS_BROWSER_U32  y);

int mms_lib_callback(int status,void *prompt,int status_value);

void mmi_mms_exit_send_retrieve_message(void);	
static void mmi_mms_entry_retrieve_message(void);
static void mms_get_image_frame_count(U16* count);
static void mms_get_accessory_frame_count(U16* count);
static void mms_get_music_frame_count(U16* count);
static void mmi_mms_enter_before_outbox_options(void);
static void mmi_mms_enter_draftbox_options(void);

static void mmi_mms_enter_before_draftbox_options(void);
static void mmi_mms_exit_send_setting_inline(void);
static void mmi_mms_send_setting_inline_struct(void);
static void mmi_mms_show_send_receive_status(S32 value);

static void mms_set_frametime_validation(U8* string,S32 buffer_size);
static void mmi_mms_exit_retrieving_setting_inline(void);
static void mmi_mms_retrieving_setting_inline_struct(void);
static void mmi_mms_exit_mmsc_net_setting(void);
static void mmi_mms_indication_save_mms_setting(void);
static void mmi_mms_mmsc_net_setting_inline_struct(void);
static void mmi_mms_indication_save_service_list_item(void);
static void mms_message_save_service_list_item_confirm(void);
static void mms_message_no_save_service_list_item(void);

static void mms_set_service_id(void);
static void mms_set_centre_address(void);
static void mms_set_gateway(void);
static void mms_set_port(void);
static void mms_message_settings_confirm(void);
static void mms_message_settings_no_save(void);
static void mmi_mms_edit_insert_image(char* image_buf, S32 buf_size, U16 image_type);
static void mmi_mms_edit_insert_accessory(char* accessory_buf, S32 buf_size, U16 accessory_type);

static void mmi_mms_indication_delete_message(void);
static void mmi_mms_save_message(void);
static void mmi_mms_indication_delete_all_messages (void);
static void mmi_mms_exit_to_sendlist(void);

static void mmi_mmsbox_find_message_by_index(S32 item_index);
static void mmi_mms_display_confirm (UI_string_type strId, FuncPtr lskFuncs, FuncPtr rskFuns);
static void mmi_mms_delete_message(void);
static void mmi_mms_delete_all_messages(void);
static void mms_draw_picture_for_play(U8* str, U32* tx,U32* ty,U32 length, U16 type);
static void mms_view_message(void);
static void mms_play_show_text_image(void);
static void mmi_mms_setting_service_list_hint(U16 index);
static void mms_recv_failed(void *ptr);
static void mms_recvd_ok(void);
static void mms_send_ok(void *ptr);
static void mms_send_failed(void *ptr);

static void mms_edit_show_text_image(void);
static void mms_draw_text(U8* str, U32* tx,U32* ty,U32 length);
static CMS_BROWSER_U32 mmi_mms_getline_fit(P_CMS_BROWSER_U8 str, CMS_BROWSER_U32 m_end, P_CMS_BROWSER_U32 max_width);
static void mmi_change_title_string(void);
static void mms_stop_animation(void);
static void mms_stop_music(void);
static void mmi_mms_entry_image_folder(void);
static void mmi_select_image_callback(void *filePath);
static void mmi_mms_entry_music_folder(void);
static void mmi_mms_entry_accessory_folder(void);
static void mmi_select_accessory_callback(void *filePath);
static void mms_add_text_content_confirm(void);
static void mms_amend_sendto_address_confirm(void);
static void mms_amend_sendto_input_not_empty_lsk_hdlr (void);
static void mmi_mms_entry_mmsc_net_settingcheck(void);

static void mms_add_phone_email_to_sendto_list(void);
static void mms_save_music_handler(void);
static void mms_save_image_handler(void);
static void mms_save_accessory_handler(void);
static void mmi_select_music_callback(void *filePath);
static U16 mms_get_media_type(U8* buffer, S32 size, char* fname);
static void mms_file_manager_init(void);
static void mms_file_manager_create(void);
static void mms_file_manager_destory(void);
static void mms_file_manager_destory_current_folder(void);
void mms_file_manager_free_message(P_MESSAGELIST mlist);
P_MESSAGELIST mms_file_manager_new_message(void);
static void mms_file_manager_delete_message_node(P_MESSAGELIST list);
static void mms_file_manager_delete(void);
static void mms_file_manager_delete_current_message(void);
static void mms_file_manager_delete_message(P_MESSAGELIST list);
static void mms_file_manager_set_current_message(P_MESSAGELIST curMsg);
static void mms_file_manager_set_push_message(P_MESSAGELIST pushMsg);
static P_MESSAGELIST mms_file_manager_get_push_message(void);

static void mms_file_manager_modify_current_message_state(MMS_MSG_STATE state);
void mms_file_manager_add_message_to_folder(P_MESSAGELIST mmsDigest, MMS_FOLDER_NAME folder, SET_MESSAGE flag);

static void mms_file_manager_store_folder(MMS_FOLDER_NAME folder);
static void mms_file_manager_store_current_folder(void);
static void mms_file_manager_set_current_folder(MMS_FOLDER_NAME boxName);
static MMS_FOLDER_NAME mms_file_manager_get_current_folder(void);
static void mms_file_manager_delete_current_folder(void);
static void mms_file_manager_read_all_folders(void);
static void mms_init_message_settings(void);
static pMMS_EDocument mmi_mms_newdoc(void);
int cms_memory_to_flash(char* filename);
static void mms_del_content(pMMS_EDocument editor_doc, pMMS_Slide slide, U16 del_type);
static void mms_notification_arrive(void *ptr);
int sms_handle_callback(int status,void *prompt,int status_value);

static void mms_parse_message_file(void);
void mms_get_all_boxes_count_size(U16* count, S32* msize);
static int mmi_mms_get_manager_msg_state(void);
static void cms_insert_image_into_new_mms(char* image_buf, S32 buf_size, U16 image_type);
static void cms_insert_music_into_new_mms(char* music_buf, S32 buf_size, U16 music_type);
static void cms_insert_accessory_into_new_mms(char* accessory_buf, S32 buf_size, U16 accessory_type);
static void mmi_mms_icon_ind(unsigned int type);
static int cms_judge_gpeditor_content(void);

static void mms_send_message(void);
static void mms_retrieve_message(void *ptr);
static void mmi_mms_post_message(unsigned int MessageID,void *ptr);
static  void mmi_mms_post_play_message(void);

static void cms_remove_message_file_from_flash(char* filename);
static void cms_remove_memory_file(void);

static void cms_empty_sendto_list(void);
static void cms_empty_sendto_to_list(void);
static void cms_empty_sendto_cc_list(void);
static void cms_empty_sendto_bcc_list(void);
static pSENDTO_LIST cms_new_sendto_list_node(void);
static void cms_parse_sendto_address(P_MESSAGELIST	pMsg,set_to flag);

static void mms_remove_from_sendto_list_confirm(void);
static void mms_remove_all_from_sendto_list_confirm(void);
static void cms_free_sendto_node(pSENDTO_LIST plist);
static U16 cms_get_sendtolist_count(set_to flag);
static int cms_get_sendto_list_len(pSENDTO_LIST plist);
static U16 get_sendtolist_count(pSENDTO_LIST addr);
static void cms_getmedia_fllename(char* inputfimename);

void mmi_mms_highlight_inbox_reply(void);
void mmi_mms_entry_mms_reply_option(void);
void mmi_mms_msg_highlight_reply (void);
void mmi_mms_msg_reply_msg_to_entry (void);
void mmi_mms_msg_entry_write_msg (void);
void mmi_mms_msg_go_back_from_write_msg (void);
void mmi_mms_msg_entry_send_option(void);

void mmi_mms_highlight_dial_number(void);
void mmi_mms_highlight_save_number(void);
void  mmi_mms_entry_use_number_option(void);
void  mmi_mms_dial_use_number(void);
int mmi_mms_judge_mms_setting(void);
#ifdef __MMI_TOUCH_SCREEN__
void mmi_mms_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_mms_pen_up_hdlr(mmi_pen_point_struct pos);
void mmi_mms_pen_repeat_hdlr(mmi_pen_point_struct pos);
void mmi_mms_pen_move_hdlr(mmi_pen_point_struct pos);
#endif

#ifdef SUPPORT_SMSMMS_COMBINE
void mmi_mms_highlight_new_sms_mms(void);
void mmi_mms_highlight_sms_mms_templates(void);
void mmi_mms_highlight_sms_mms_setting(void);
void mmi_mms_highlight_sms_mms_memory_status(void);

void mmi_mms_entry_new_sms_mms(void);
void mmi_mms_entry_sms_mms_template(void);
void mmi_mms_entry_sms_mms_setting(void);
void mmi_mms_entry_sms_mms_memory_status(void);

void mmi_smsmms_add_sms_to_list (mmi_frm_sms_msgbox_struct* data,U16 index);
void mmi_smsmms_delete_sms_from_list(U16 index);
void mmi_mms_del_all_sms_mms_msg(void);

U16 mmi_wapmms_inbox_get_push_count(void);
void mmi_mms_highlight_wap_push_link(void);
void mmi_mms_enter_inbox_wap_push_options(void);
void mmi_mmswap_show_wap_push_icon(void);
void mms_wap_ota_add_bookmark(void);
void mms_wap_ota_to_setting(void);
void mmi_mms_wap_ota_to_setting_list(void);
void mmi_mms_ota_to_setting_list(void);

#endif

#ifdef SUPPORT_MMS_IDLE_IND
void mmi_mms_get_new_msg_file_name(P_MESSAGELIST plist);
void mmi_mms_idle_play_or_down_msg(void);
void mmi_mms_idle_post_play_or_down(void);
P_MESSAGELIST mmi_mms_inbox_find_ind_new_message(void);
#endif

void mmi_confirm_input_text_handler(void);

 void mmi_msg_mms_text_template_callback(PS8  ucs2);
/*
特别函数
*/
S8** mmi_msg_mms_get_numbers_from_text(U8* text, U16 bufLen, U16*  numbersCount)
{
	*numbersCount=ObtainNumbersFromMessageText(NULL,text,bufLen,0);
	return (S8**)(g_msg_cntx.numbersList);
}

void mmi_msg_mms_template_callback()
{
	S8*	templ;
	templ = g_msg_cntx.templates[g_msg_cntx.currHiliteIndex];
	
	if (templ)
	{
		mmi_msg_mms_text_template_callback(templ);
	}
} 

void mmi_msg_entry_mms_text_template_list(void)
{
	mmi_msg_entry_template_list();
}
//特别函数结束

 /******************************************************************************
 *                           MMS System Init                           *
 ******************************************************************************/
 void CmsMmsHiliteHandler(void)
{
	SetLeftSoftkeyFunction(EntryScrMMSMenuList,KEY_EVENT_UP);
//	SetKeyHandler(EntryScrMMSMenuList,KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
}

 void CmsWapHiliteHandler(void)
{
	SetLeftSoftkeyFunction(EntryScrWapBrowserMenuList,KEY_EVENT_UP);
//	SetKeyHandler(EntryScrWapBrowserMenuList,KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
}

/* ----------------------------------------------------------------------------
 * Function Name: init_cms_mms_app
 *       Purpose: init wap and mms module
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void init_cms_mms_app(void)
{
	if(!cms_wapmms_init)
	{
        SetHiliteHandler(SERVICES_WAP_MENU_ID,CmsWapHiliteHandler);
        SetHiliteHandler(MESSAGES_MENU_MMS_MENUID,CmsMmsHiliteHandler);
		cms_init_mem_pool();	/*初始化内存*/
		mms_init_app();			/*初始化彩信全局变量*/
		cms_wapmms_init = TRUE;
	}
	wap_init_app();			/*初始化浏览器全局变量*/
	//Cms_Dataaccount_Init();	/*初始化网络账号*/
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_init_app
 *       Purpose: init mms module
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_app(void)
{
	mms_init_global_param();
	mms_file_manager_init();
	mms_init_sms_net();
	mmi_mms_menu_init();
	mmi_update_mms_idel_icon();
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_init_global_param
 *       Purpose: init mms global param 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_global_param(void)
{
	memset(&gedit,0,sizeof(TEXT_EDIT));
	memset(&gconfig, 0, sizeof(MMS_CONFIG));
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));
	
	if (!Cms_Adp_FileExists((S8*)MESSAGE_SETTINGS_FILE))
	{
		int 		i = 0, attr;	
		/* 创建WAP 文件夹 */
#ifdef CMS_RESET_UNDELETE_WAPPUSHFILE
		if (!Cms_Adp_FileExists((S8*)WAP_PUSH_FILENAME))
#endif
		{
#if defined(UNIRISE25_GEMINI_BB) || defined(SKYWORTH25_06B_BB)||defined (SKYWORTH23_07A_BB)
			FS_XDelete((const WCHAR*)CMS_WAP_DIR_PATH, (FS_FILE_TYPE|FS_DIR_TYPE|FS_RECURSIVE_TYPE), NULL, 0);
#else
			FS_XDelete((const WCHAR*)CMS_WAP_DIR_PATH, (FS_FILE_TYPE|FS_DIR_TYPE|FS_RECURSIVE_TYPE));
#endif
			i = FS_CreateDir((const WCHAR*)CMS_WAP_DIR_PATH);
			mms_mmi_tracer("FS_CreateDir return %d", (char *)i);
                attr = FS_GetAttributes((const WCHAR*)CMS_WAP_DIR_PATH);
               	if (attr >= FS_NO_ERROR)
            		FS_SetAttributes((const WCHAR*)CMS_WAP_DIR_PATH, attr | FS_ATTR_HIDDEN);
		}
		/* 创建MMS 文件夹 */
#ifdef CMS_RESET_UNDELETE_MMSFILE		
		if (!Cms_Adp_FileExists((S8*)MESSAGE_RMF_FILE) && !Cms_Adp_FileExists((S8*)MESSAGE_SMF_FILE) && !Cms_Adp_FileExists((S8*)MESSAGE_DMF_FILE))
#endif		
		{
#if defined(UNIRISE25_GEMINI_BB) || defined(SKYWORTH25_06B_BB)||defined (SKYWORTH23_07A_BB)
			FS_XDelete((const WCHAR*)CMS_MMS_DIR_PATH, (FS_FILE_TYPE|FS_DIR_TYPE|FS_RECURSIVE_TYPE), NULL, 0);
#else
			FS_XDelete((const WCHAR*)CMS_MMS_DIR_PATH, (FS_FILE_TYPE|FS_DIR_TYPE|FS_RECURSIVE_TYPE));
#endif
			i = FS_CreateDir((const WCHAR*)CMS_MMS_DIR_PATH);
			mms_mmi_tracer("FS_CreateDir return %d", (char *)i);
                attr = FS_GetAttributes((const WCHAR*)CMS_MMS_DIR_PATH);
               	if (attr >= FS_NO_ERROR)
            		FS_SetAttributes((const WCHAR*)CMS_MMS_DIR_PATH, attr | FS_ATTR_HIDDEN);
		}	

		i = FS_SetCurrentDir((const WCHAR*)CMS_MMS_DIR_PATH);

		
		/*彩信全局变量初始化设置*/
		pfnUnicodeStrcpy((S8*)gconfig.service_id, (S8*)L"China Mobile");
		pfnUnicodeStrcpy((S8*)gconfig.centre_addr, (S8*)MMS_CMCC_CENTER_ADDRESS);
		pfnUnicodeStrcpy((S8*)gconfig.gateway, (S8*)MMS_CMCC_GATEWAY);
		pfnUnicodeStrcpy((S8*)gconfig.port, (S8*)MMS_CMCC_PORT);
		pfnUnicodeStrcpy((S8*)gconfig.frametime, (S8*)MMS_DEFAULT_FRAME_TIME);

		gconfig.expires= MMS_SETTINGS_MAX;
		gconfig.sendsize= MMS_SETTINGS_50K;
		gconfig.retrievesize= MMS_SETTINGS_50K;
		gconfig.anonymous = MMS_SETTINGS_OFF;
		gconfig.read_rpt= MMS_SETTINGS_OFF;
		
		gconfig.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfig.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfig.gprs_mode = MMS_NET_SETTINGS_NETWORK_CFG_GPRS1;
		gconfig.delivery_rpt = MMS_SETTINGS_OFF;

		gconfig.mms_service_activeitem= MMS_SERVICE_ACTIVE_ITEM;
		gconfig.wap_service_activeitem= WAP_SERVICE_ACTIVE_ITEM;
		
		mms_write_message_settings_file();
		mms_init_all_pre_setting_file();
		wap_init_all_pre_setting_file();/*20060714 cocoma xu add防止重新开机后之前设置被覆盖*/
	}
	else
	{
		mms_init_message_settings();
	}
	gpeditor_doc =(pMMS_EDocument) mmi_mms_newdoc();	

	mmsflag.gexit_toidle=FALSE;
	mmsflag.gmanual_recv=FALSE;
	mmsflag.gmmsbox_full=FALSE;
	mmsflag.gmms_memory=FALSE;
	mmsflag.gmsg_saved=FALSE;
	mmsflag.gnew_message=TRUE;
	mmsflag.gplay_state=FALSE;
	mmsflag.gsend_recv=FALSE;
	mmsflag.gsend_save=FALSE;
	
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_init_sms_net
 *       Purpose: init sms net
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_sms_net(void)
{
	SocketStart(0);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_menu_init
 *       Purpose: init mms highlight handlers
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_menu_init(void)
{
	/*----------------------------------------------------------------*/
	/* 1main menu                                                      */
	/*----------------------------------------------------------------*/
	
	SetHiliteHandler(MMS_MENU_WMESSAGE_MENUID, 	mmi_mms_highlight_new_msg);
	SetHiliteHandler(MMS_MENU_INBOX_MENUID, 		mmi_mms_highlight_inbox);
	SetHiliteHandler(MMS_MENU_OUTBOX_MENUID, 		mmi_mms_highlight_outbox);
	SetHiliteHandler(MMS_MENU_DRAFTBOX_MENUID,		mmi_mms_highlight_draftbox );
	#ifdef SUPPORT_MMS_TEMPLATES
	SetHiliteHandler(MMS_MENU_TEMPLATES_MENUID, mmi_mms_highlight_template);
	SetHiliteHandler(MMS_TEMPLATE_OPTION_VIEW_MENUID, mmi_mms_highlight_template_preview);
	SetHiliteHandler(MMS_TEMPLATE_OPTION_PROPERTIES_MENUID, mmi_mms_highlight_template_details);
	SetHiliteHandler(MMS_TEMPLATE_OPTION_WRITE_MENUID,mmi_mms_highlight_template_write_message);
	#endif
	#ifdef SUPPORT_EMPTY_BOX
	SetHiliteHandler(MMS_MENU_EMPTY_BOX_MENUID, mmi_mms_highlight_empty_box);
	SetHiliteHandler(MMS_MENU_EMPTY_INBOX_MENUID, mmi_mms_highlight_empty_inbox);
	SetHiliteHandler(MMS_MENU_EMPTY_OUTBOX_MENUID, mmi_mms_highlight_empty_outbox);
	SetHiliteHandler(MMS_MENU_EMPTY_DRAFTBOX_MENUID, mmi_mms_highlight_empty_draftbox);
	SetHiliteHandler(MMS_MENU_EMPTY_ALLBOX_MENUID, mmi_mms_highlight_empty_allbox);

	SetHintHandler(MMS_MENU_EMPTY_INBOX_MENUID, mmi_mms_inbox_hint);
	SetHintHandler(MMS_MENU_EMPTY_OUTBOX_MENUID, mmi_mms_outbox_hint);
	SetHintHandler(MMS_MENU_EMPTY_DRAFTBOX_MENUID, mmi_mms_draftbox_hint);
	#endif
	SetHiliteHandler(MMS_MENU_MSG_SETTINGS_MENUID, 	mmi_mms_highlight_setting);
	SetHiliteHandler(MMS_MENU_MEMORY_STATUS_MENUID, 	mmi_mms_highlight_memoty_status);

	/*------- 1 --------------- main menu hint -------------------------*/
	SetHintHandler(MMS_MENU_INBOX_MENUID, 		mmi_mms_inbox_hint);
	SetHintHandler(MMS_MENU_OUTBOX_MENUID,	mmi_mms_outbox_hint);
	SetHintHandler(MMS_MENU_DRAFTBOX_MENUID, 	mmi_mms_draftbox_hint);

	/*------- 1-1 --------------- new message -----------------------------*/
    #ifdef SUPPORT_SMSMMS_COMBINE
       SetHiliteHandler(SMSMMS_MENU_WMESSAGE_MENUID, mmi_mms_highlight_new_sms_mms);
       SetHiliteHandler(SMSMMS_MENU_TEMPLATES_MENUID,mmi_mms_highlight_sms_mms_templates);
       SetHiliteHandler(SMSMMS_MENU_SETTING_MENUID, mmi_mms_highlight_sms_mms_setting);	
       SetHiliteHandler(SMSMMS_MENU_MEMORY_STATUS_MENUID, mmi_mms_highlight_sms_mms_memory_status);	

       SetHiliteHandler(MMS_INBOX_WAP_OPTIONS_LINK, mmi_mms_highlight_wap_push_link);	
	SetHiliteHandler(MMS_INBOX_WAP_OPTIONS_DELETE, mmi_mms_highlight_del);
	SetHiliteHandler(MMS_INBOX_WAP_OPTIONS_DELETE_ALL, mmi_mms_highlight_del_all);
    #endif
       /*------- 1-1-2 --------------- new mms message -----------------------------*/
	SetHiliteHandler(MMS_WMESSAGE_TO_MENUID, mmi_mms_highlight_add_to);
	SetHiliteHandler(MMS_WMESSAGE_CC_MENUID, mmi_mms_highlight_add_cc);
	SetHiliteHandler(MMS_WMESSAGE_BCC_MENUID, mmi_mms_highlight_add_bcc);
	SetHiliteHandler(MMS_WMESSAGE_SUBJECT_MENUID, mmi_mms_highlight_subject);
	SetHiliteHandler(MMS_WMESSAGE_CONTENT_MENUID,mmi_mms_highlight_edit_content );
	SetHiliteHandler(MMS_SEND_OPTIONS_MENUID, mmi_mms_highlight_send_options);
	
	/*--------1-1 ---------------new message hint----------------------------*/
	SetHintHandler(MMS_WMESSAGE_TO_MENUID, mmi_mms_to_hint);
	SetHintHandler(MMS_WMESSAGE_CC_MENUID, mmi_mms_cc_hint);
	SetHintHandler(MMS_WMESSAGE_BCC_MENUID, mmi_mms_bcc_hint);
	SetHintHandler(MMS_WMESSAGE_SUBJECT_MENUID, mmi_mms_subject_hint);
	SetHintHandler(MMS_WMESSAGE_CONTENT_MENUID, mmi_mms_content_hint);
		
	/*-------- 1-1-1-1--------------- send to option----------------------------*/
	SetHiliteHandler(MMS_SENDTO_OPTIONS_ADD_NUMBER_MENUID,mmi_mms_highlight_add_number_input );
	SetHiliteHandler(MMS_SENDTO_OPTIONS_ADD_EMAIL_MENUID, mmi_mms_highlight_add_email_input);
	SetHiliteHandler(MMS_SENDTO_OPTIONS_AMEND_MENUID,mmi_mms_highlight_amend_sendto);
	SetHiliteHandler(MMS_SENDTO_OPTIONS_DELETE_MENUID,mmi_mms_highlight_del_sendto);
	SetHiliteHandler(MMS_SENDTO_OPTIONS_DELETE_ALL_MENUID, mmi_mms_highlight_del_all_sendto);
	
	/*-------- 1-1-3-------------- new message->edit option -----------------------------*/
	SetHiliteHandler(MMS_CONTENT_OPTIONS_EDIT_TEXT_MENUID,mmi_mms_highlight_edit_text );
	SetHiliteHandler(MMS_CONTENT_OPTIONS_INSERTNEWFRAME_MENUID, mmi_mms_highlight_new_frame);	
	SetHiliteHandler(MMS_CONTENT_OPTIONS_ADDIMAGE_MENUID, mmi_mms_highlight_add_image);
	SetHiliteHandler(MMS_CONTENT_OPTIONS_ADDMUSIC_MENUID,mmi_mms_highlight_add_music );
	
	SetHiliteHandler(MMS_CONTENT_OPTIONS_MUSICTIMESETTING_MENUID, mmi_mms_highlight_set_frametime);
	SetHiliteHandler(MMS_CONTENT_OPTIONS_DELCURRENTIMAGE_MENUID, mmi_mms_highlight_del_image);
	SetHiliteHandler(MMS_CONTENT_OPTIONS_DELCURRENTMUSIC_MENUID, mmi_mms_highlight_del_music);
	SetHiliteHandler(MMS_CONTENT_OPTIONS_DELCURRENTFRAME_MENUID, mmi_mms_highlight_del_frame);
	SetHiliteHandler(MMS_CONTENT_OPTIONS_EMPTYTEXT_MENUID, mmi_mms_highlight_empty_text);
	/*--------- 0 ------------- play next or prev -----------------------------*/
	SetHiliteHandler(MMS_NEXT_SLIDE_MENUID, mmi_mms_highlight_next_frame);
	SetHiliteHandler(MMS_PREV_SLIDE_MENUID, mmi_mms_highlight_pre_frame);

	/*--------- 1-1-4 --------- send option  ---------------------------------*/
	SetHiliteHandler(MMS_SEND_OPTIONS_SEND_MENUID, mmi_mms_highlight_send);
	SetHiliteHandler(MMS_SEND_OPTIONS_VIEW_MENUID, mmi_mms_highlight_play);
	SetHiliteHandler(MMS_SEND_OPTIONS_SAVE_MENUID, mmi_mms_highlight_save);
	SetHiliteHandler(MMS_SEND_OPTIONS_SEND_SAVE_MENUID, mmi_mms_highlight_save_send);
		
	/*--------- 1-2-1 --------- inbox  message option--------------------------*/
	SetHiliteHandler(MMS_INBOX_OPTIONS_PLAY_MENUID, mmi_mms_highlight_box_play);
#ifdef SUPPORT_SMSMMS_COMBINE
	SetHiliteHandler(MMS_INBOX_OPTIONS_REPLY_MENUID, mmi_mms_highlight_inbox_reply);
	SetHiliteHandler(MMS_INBOX_OPTIONS_MMS_REPLY_MENUID, mmi_mms_highlight_reply);
	SetHiliteHandler(MMS_INBOX_OPTIONS_SMS_REPLY_MENUID, mmi_mms_msg_highlight_reply);	
#else
	SetHiliteHandler(MMS_INBOX_OPTIONS_REPLY_MENUID, mmi_mms_highlight_reply);
#endif
	SetHiliteHandler(MMS_INBOX_OPTIONS_DETAILS_MENUID, mmi_mms_highlight_details);
	SetHiliteHandler(MMS_INBOX_OPTIONS_FORWARD_MENUID, mmi_mms_highlight_forward);
	SetHiliteHandler(MMS_INBOX_OPTIONS_SAVE_IMAGE_MENUID, mmi_mms_highlight_save_image);	
	SetHiliteHandler(MMS_INBOX_OPTIONS_SAVE_MUSIC_MENUID, mmi_mms_highlight_save_music);
	SetHiliteHandler(MMS_INBOX_OPTIONS_SAVE_ACCESSORY_MENUID, mmi_mms_highlight_save_accessory);	

	SetHiliteHandler(MMS_INBOX_OPTIONS_GET_DETAILS_MENUID, mmi_mms_highlight_get_number);
	SetHiliteHandler(MMS_INBOX_OPTIONS_DIAL_NUMBER_MENUID, mmi_mms_highlight_dial_number);
	SetHiliteHandler(MMS_INBOX_OPTIONS_SAVE_NUMBER_MENUID, mmi_mms_highlight_save_number);

	SetHiliteHandler(MMS_INBOX_OPTIONS_DELETE_MENUID, mmi_mms_highlight_del);
	SetHiliteHandler(MMS_INBOX_OPTIONS_DELETE_ALL_MENUID, mmi_mms_highlight_del_all);
	/*--------- 1-2-2 -------- inbox push option------------------------------*/
	SetHiliteHandler(MMS_INBOX_OPTIONS_DOWNLOAD_MENUID, mmi_mms_highlight_inbox_push_download);
	SetHiliteHandler(MMS_INBOX_OPTIONS_PUSH_DETAILS_MENUID, mmi_mms_highlight_details);
	SetHiliteHandler(MMS_INBOX_OPTIONS_PUSH_DELETE_MENUID, mmi_mms_highlight_del);
	SetHiliteHandler(MMS_INBOX_OPTIONS_PUSH_DELETE_ALL_MENUID, mmi_mms_highlight_del_all);
	
	/*--------- 1-3 ---------- outbox option----------------------------------*/
	SetHiliteHandler(MMS_OUTBOX_OPTIONS_SEND_MENUID, mmi_mms_highlight_outbox_send);
	SetHiliteHandler(MMS_OUTBOX_OPTIONS_FORWARD_MENUID, mmi_mms_highlight_forward);
	SetHiliteHandler(MMS_OUTBOX_OPTIONS_PLAY_MENUID, mmi_mms_highlight_box_play);
	SetHiliteHandler(MMS_OUTBOX_OPTIONS_DETAIL_MENUID, mmi_mms_highlight_details);
	SetHiliteHandler(MMS_OUTBOX_OPTIONS_DELETE_MENUID, mmi_mms_highlight_del);
	SetHiliteHandler(MMS_OUTBOX_OPTIONS_DELETE_ALL_MENUID, mmi_mms_highlight_del_all);

	
	/*--------- 1-4 --------------draftbox option---------------------------*/
	SetHiliteHandler(MMS_DRAFTBOX_OPTIONS_SEND_MENUID, mmi_mms_highlight_draftbox_send);
	SetHiliteHandler(MMS_DRAFTBOX_OPTIONS_PLAY_MENUID, mmi_mms_highlight_box_play);
	SetHiliteHandler(MMS_DRAFTBOX_OPTIONS_EDIT_MENUID, mmi_mms_highlight_draftbox_edit);
	SetHiliteHandler(MMS_DRAFTBOX_OPTIONS_DETAIL_MENUID, mmi_mms_highlight_details);
	SetHiliteHandler(MMS_DRAFTBOX_OPTIONS_DELETE_MENUID, mmi_mms_highlight_del);
	SetHiliteHandler(MMS_DRAFTBOX_OPTIONS_DELETE_ALL_MENUID, mmi_mms_highlight_del_all);
	SetHiliteHandler(MMS_DRAFTBOX_OPTIONS_SEND_SAVE_MENUID, mmi_mms_highlight_draftbox_send_and_save);
	
	/*--------- 1-6 ------------ message setting -----------------------------*/
	SetHiliteHandler(MMS_SEND_SETTINGS_MENUID, mmi_mms_highlight_setting_sending);
	SetHiliteHandler(MMS_RETRIEVING_SETTINGS_MENUID, mmi_mms_highlight_setting_retrieving);
	SetHiliteHandler(MMS_EDIT_SETTING_OPTION_MENUID, mmi_mms_highlight_setting_edit_option);
	/*--------- 1-6 --------------- setting menu hint -------------------------*/
	SetHintHandler(MMS_EDIT_SETTING_OPTION_MENUID, mmi_mms_setting_service_list_hint);

	/*--------- 1-6-3 ------------ message setting (edit)-----------------------*/
	SetHiliteHandler(MMS_MSG_SETTINGS_SERVICE_SET_MENUID, mmi_mms_highlight_setting_edit_option_activate);
	SetHiliteHandler(MMS_MSG_SETTINGS_SERVICE_EDIT_MENUID, mmi_mms_highlight_setting_edit_option_edit);

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_update_mms_idel_icon
 *       Purpose: show mms icon on idle for unread/full message.
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_update_mms_idel_icon(void)
{
	S32 mms_manager_status;

	 /* 查看是否信息正在收取*/
 	if(mmsflag.gsend_recv==TRUE)
 	{
  		mmi_mms_icon_ind(CMS_MMS_STATUS_BUSY);
 	}
	mms_manager_status =mmi_mms_get_manager_msg_state();

	mmi_mms_icon_ind((unsigned int)mms_manager_status);
#ifdef SUPPORT_SMSMMS_COMBINE
	mmi_mmswap_show_wap_push_icon();
#endif	
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
void mmi_mms_entry_init_param(void)
{
	if (!mmsflag.gmms_memory)
	{
		mmsflag.gmms_memory= TRUE;
	}
	else
	{
		mmsflag.gnew_message= FALSE;
	}
	
	{
		memset(gedit.text_buf, 0, MMS_MAX_TEXT_SIZE);
		memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
		memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);
		gedit.media_type = 0;
		gedit.start_height = 0;
		gedit.total_height = 0;
		
		cms_empty_sendto_list();
		pgsendtolist=NULL;
		pgsendcclist=NULL;
		pgsendbcclist=NULL;
		
		MMSDelAllSlide(gpeditor_doc);
		gpeditor_doc->totalsize = 0;
		
		ghiliindex = 0;
		ghiliindex1 = 0;
		gCurActionItem = 0;
		
		gbox_operation = 0;
		gsendto_options=0;
		ginput_screen = INPUT_OPTION_UNKNOWN;

		if (!mmsflag.gsend_recv)
		{
			/*没有自动接收，清理内存文件*/
			destroy_mms_mem_file_info();
		}
	}
}

 /******************************************************************************
 *                           MMS System MMI                           *
 ******************************************************************************/

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_mms_menu
 *       Purpose: entry mms menu screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void EntryScrMMSMenuList(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 guiBuffer=NULL;		/* Buffer holding history data */
	U16	 numItems=0;		/* Stores no of children in the submenu*/
	U16	 nStrItemList[MAX_SUB_MENUS];	/* Stores the strings id of submenus returned */
	U16	 itemIcons[MAX_SUB_MENUS];		/* Stores the icon id of submenus returned */
	U16	 screenId=SCR_ID_MMS_MAIN_MENU;
	U8*	 pPopUpList[MAX_SUB_MENUS];	
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__    
    /* check is in mass storage mode */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
#ifdef SUPPORT_SMSMMS_COMBINE
	if(!g_msg_cntx.msg_init)
	{
		DisplayPopup((PU8)GetString(STR_MSG_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
		return;
	}
#endif
	EntryNewScreen(screenId, 
					mmi_msg_exit_generic, 
					EntryScrMMSMenuList, NULL);

	mmi_mms_entry_init_param();
	
	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(MESSAGES_MENU_MMS_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(MESSAGES_MENU_MMS_MENUID, nStrItemList);
	GetSequenceImageIds(MESSAGES_MENU_MMS_MENUID, itemIcons);
	
	/* construct hint popup strings for menu items */
	ConstructHintsList(MESSAGES_MENU_MMS_MENUID, pPopUpList);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(MESSAGES_MENU_MMS_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	/* Display the call history main screen */
	#ifdef SUPPORT_SMSMMS_COMBINE
	ShowCategory52Screen(STR_CMS_MESSAGE_MENUENTRY, IMG_MESSAGE_SIM_MMS_MENUENTRY,
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  pPopUpList, 0, 0,
						  guiBuffer);
	#else
	ShowCategory52Screen(STR_CMS_MMS_MENUENTRY, IMG_MESSAGE_SIM_MMS_MENUENTRY,
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  pPopUpList, 0, 0,
						  guiBuffer);
	#endif

	
	/*增加判断收件箱 是否到达最大限制*/
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_main_menu, KEY_EVENT_UP);

#ifdef __MMI_CLAMSHELL__
	SetInterruptEventHandler(mmi_mms_clam_event_hander, NULL,MSG_ID_MMI_EQ_GPIO_DETECT_IND);
#endif 
}


/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_main_menu
 *       Purpose: exit mms main menu screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */

void mmi_mms_exit_main_menu(void)
{
	if (!mmsflag.gsend_recv)
	{
		/*没有自动接收*/
		destroy_mms_mem_file_info(); 
	}
	
	mmsflag.gsend_save = FALSE;
	mmsflag.gmmsbox_full = FALSE;
	mmsflag.gmms_memory= FALSE;
	
	mmi_update_mms_idel_icon();
	GoBackHistory();

}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_to_main_menu
 *       Purpose: exit to mms main menu screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_to_main_menu(void)
{
	memset(gedit.phone_buf, 0 , MMS_MAX_SEND_TO_SIZE);
	memset(gedit.text_buf, 0, MMS_MAX_TEXT_SIZE);
	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);
	
	gpeditor_doc->totalsize = 0;
	MMSDelAllSlide(gpeditor_doc);
	cms_empty_sendto_list();
	pgsendtolist=NULL;
	pgsendcclist=NULL;
	pgsendbcclist=NULL;

	ExitDisplayPopupConfirm();
	if(IsScreenPresent(SCR_ID_MMS_MAIN_MENU))
	{
		GoBackToHistory(SCR_ID_MMS_MAIN_MENU);
	}
	else
	{
		/*当外部调用时，返回到入口处*/
		DeleteNScrId(SCR_ID_MMS_WMESSAGE_MENU);
		GoBackHistory();
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_to_idle
 *       Purpose: exit to idle screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_to_idle(void)
{

	U16	scr_ID = GetMessagesCurrScrnID();
	/*解决通话过程中进入彩信模块后合盖或退出处理*/
	if (isInCall())
	{
		HangupAllCalls();
		return;
	}
	mms_stop_animation();
	
	if (scr_ID == SCR_ID_SENDING_RETRIEVING_MESSAGE)
	{
		mmsflag.gexit_toidle= TRUE;
		mms_cancel_send_retrieve();
	}
	if (mmsflag.gplay_state)
	{
		mmsflag.gplay_state = FALSE;
		pixtel_UI_cancel_timer(mms_play_message_callback);
		mms_stop_music();
	}
	else
	{
		mms_stop_music();
	}

	if (gedit.media_buf)
	{
		switch(gedit.media_type)
		{
		case MMS_TYPE_WAV:
			StopAudioWavStream();
			break;
		case MMS_TYPE_IMY:
			StopAudioStream();
			break;
		case MMS_TYPE_MIDI:
			StopAudioMidiStream();
			break;
		case MMS_TYPE_AMR:
			StopAudioStream();	
			break;
		default:
			break;
		}
		mms_Free(gedit.media_buf);
		gedit.media_buf = NULL;
		gedit.media_len = 0;
		gedit.media_type = 0;
	}
	memset(&gedit, 0, sizeof(TEXT_EDIT));
	
	{
		mmsflag.gnew_message= FALSE;
		mmsflag.gsend_save = FALSE;
		mmsflag.gmms_memory = FALSE;
		mmsflag.gmmsbox_full=FALSE;
		mmsflag.gexit_toidle= FALSE;
		
		pCurFwrReMsg=NULL;
		cms_empty_sendto_list();
		pgsendtolist=NULL;
		pgsendcclist=NULL;
		pgsendbcclist=NULL;
		
		MMSDelAllSlide(gpeditor_doc);
		gpeditor_doc->totalsize = 0;
	

		gbox_operation = 0;
		gsendto_options=0;

		ghiliindex = 0;
		ghiliindex1 = 0;
		gCurActionItem = 0;
		ginput_screen = INPUT_OPTION_UNKNOWN;		
	}
	if (!mmsflag.gsend_recv)
	{
		/*非收发状态*/
		destroy_mms_mem_file_info();
	}
	
	mmi_update_mms_idel_icon();
	DisplayIdleScreen();

}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_to_new_msg
 *       Purpose: exit to new message screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_to_new_msg(void)
{
	mms_stop_animation();
	/*是否为新建信息*/
	if (mmsflag.gnew_message)
	{	
		if(IsScreenPresent(SCR_ID_MMS_WMESSAGE_MENU))
		{
			GoBackToHistory(SCR_ID_MMS_WMESSAGE_MENU);
		}
		else
		{
			GoBackHistory();
		}
	}
	else	/*转发或回复*/
	{
		if(IsScreenPresent(SCR_ID_MMS_EDIT_MESSAGE))
		{
			GoBackToHistory(SCR_ID_MMS_EDIT_MESSAGE);
		}
		else
		{
			GoBackHistory();
		}
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_exit_display_to_history
 *       Purpose: 先退出popupconfirm再返回上级history screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_exit_display_to_history(void)
{
	ExitDisplayPopupConfirm();
	GoBackHistory();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_save_medialist
 *       Purpose: 退出保存图像(音乐)列表
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_save_medialist(void)
{
	ghiliindex1 = 0;
	GoBackHistory();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_save_media_filename_input
 *       Purpose:  退出保存图像、音乐界面
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_save_media_filename_input(void)
{
	mms_stop_animation();
	mms_stop_music();
	GoBackHistory();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_boxes
 *       Purpose: exit box screen(inbox/outbox/new message)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_boxes(void)
{
	if (gpeditor_doc->slide_root)
	{
		MMSDelAllSlide(gpeditor_doc);
		gpeditor_doc->totalsize = 0;
	}
	
	pCurFwrReMsg =NULL;
	ghiliindex = 0;
	ghiliindex1 = 0;
	pgManager->currentFolder=NULL;
	GoBackHistory();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_to_box_options
 *       Purpose: 退出编辑彩信菜单清空收件人、主题等
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_to_box_options()
{
	memset(gedit.phone_buf, 0 , MMS_MAX_SEND_TO_SIZE);
	memset(gedit.text_buf, 0, MMS_MAX_TEXT_SIZE);
	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);

	cms_empty_sendto_list();
	pgsendtolist=NULL;
	pgsendcclist=NULL;
	pgsendbcclist=NULL;
	
	MMSDelAllSlide(gpeditor_doc);
	gpeditor_doc->totalsize = 0;

	ExitDisplayPopupConfirm();
	switch(mms_file_manager_get_current_folder())
	{
	case MMS_RECEIVE_FOLDER:
	{
		if(IsScreenPresent(SCR_ID_MMS_INBOX_OPTIONS1))
		{
			GoBackToHistory(SCR_ID_MMS_INBOX_OPTIONS1);
		}
		else
		{
			GoBackHistory();
		}
		break;
	}
	case MMS_SEND_FOLDER:
	{
		if(IsScreenPresent(SCR_ID_MMS_OUTBOX_OPTIONS))
		{
			GoBackToHistory(SCR_ID_MMS_OUTBOX_OPTIONS);
		}
		else
		{
			GoBackHistory();
		}
		break;
	}
	case MMS_DRAFT_FOLDER:
	{
		if(IsScreenPresent(SCR_ID_MMS_DRAFTBOX_OPTIONS))
		{
			GoBackToHistory(SCR_ID_MMS_DRAFTBOX_OPTIONS);
		}
		else
		{
			GoBackHistory();
		}
		break;
	}
	default:
		break;
	}

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_box_options
 *       Purpose:  退出信箱选项返回信箱之前清空内存文件
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_box_options(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGELIST pMsg = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	pMsg = (P_MESSAGELIST)mms_file_manager_get_current_message();
	if (!pMsg)
	{
		GoBackHistory();
		DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR),  IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return;
	}
	if (mmsf_ifFileExited(pMsg->fileName) > 0)
	{
		mmsf_Remove(pMsg->fileName);
	}
	GoBackHistory();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_clam_event_hander
 *       Purpose: exit to idle screen when clam
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 #ifdef __MMI_CLAMSHELL__
U8 mmi_mms_clam_event_hander(void* ptr)
{
	mmi_mms_exit_to_idle();
	return 0;//1;liukai mod. for keylock when exit
}
#endif


/*--------------------------------- New Message  -------------------------------*/

/*-----------------------------------------------------------------------------*/
/* 彩信支持短彩合一                                                    */
/*-----------------------------------------------------------------------------*/

#ifdef SUPPORT_SMSMMS_COMBINE
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_new_sms_mms
 *       Purpose: entry new message menu screen(1.sms --2.mms)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void mmi_mms_entry_new_sms_mms(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*  guiBuffer=NULL;        			/* Buffer holding history data */
	U16  numItems=0;        			/* Stores no of children in the submenu*/
	U16  nStrItemList[MAX_SUB_MENUS];   	/* Stores the strings id of submenus returned */
	U16  itemIcons[MAX_SUB_MENUS];      	/* Stores the icon id of submenus returned */
	U16  screenId=SCR_ID_SMSMMS_WMESSAGE_MENU;
	U8*  pPopUpList[MAX_SUB_MENUS]; 
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef SUPPORT_SMSMMS_COMBINE
	if(!g_msg_cntx.msg_init)
	{
		/*对从快捷菜单进入时做判断*/
		DisplayPopup((PU8)GetString(STR_MSG_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
		return;
	}	
#endif
	EntryNewScreen(screenId, mmi_msg_exit_generic, 
					mmi_mms_entry_new_sms_mms, NULL);

	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(SMSMMS_MENU_WMESSAGE_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(SMSMMS_MENU_WMESSAGE_MENUID, nStrItemList);
	GetSequenceImageIds(SMSMMS_MENU_WMESSAGE_MENUID, itemIcons);
	    
	/* construct hint popup strings for menu items */
	ConstructHintsList(SMSMMS_MENU_WMESSAGE_MENUID, pPopUpList);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(SMSMMS_MENU_WMESSAGE_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler); 

	/* Display the call history main screen */
	ShowCategory52Screen(STR_NEW_SMS_MMS, IMG_MESSAGE_SIM_MMS_MENUENTRY,
	                          		STR_GLOBAL_OK, IMG_GLOBAL_OK,
	                          		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
	                         		numItems, nStrItemList, itemIcons,
	                          		pPopUpList, 0, 0,guiBuffer);
#ifdef __MMI_CLAMSHELL__
	SetInterruptEventHandler(mmi_mms_clam_event_hander, NULL,MSG_ID_MMI_EQ_GPIO_DETECT_IND);
#endif 	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_sms_mms_template
 *       Purpose:
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void mmi_mms_entry_sms_mms_template(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*  guiBuffer=NULL;        			/* Buffer holding history data */
	U16  numItems=0;        			/* Stores no of children in the submenu*/
	U16  nStrItemList[MAX_SUB_MENUS];   	/* Stores the strings id of submenus returned */
	U16  itemIcons[MAX_SUB_MENUS];      	/* Stores the icon id of submenus returned */
	U16  screenId=SCR_ID_SMSMMS_TEMPLATES_MENU;
	U8*  pPopUpList[MAX_SUB_MENUS]; 
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL, 
					mmi_mms_entry_sms_mms_template, NULL);

	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(SMSMMS_MENU_TEMPLATES_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(SMSMMS_MENU_TEMPLATES_MENUID, nStrItemList);
	GetSequenceImageIds(SMSMMS_MENU_TEMPLATES_MENUID, itemIcons);
	    
	/* construct hint popup strings for menu items */
	ConstructHintsList(SMSMMS_MENU_TEMPLATES_MENUID, pPopUpList);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(SMSMMS_MENU_TEMPLATES_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler); 

	/* Display the call history main screen */
	ShowCategory52Screen(STR_SMS_MMS_TEMPLATES, IMG_MESSAGE_SIM_MMS_MENUENTRY,
	                          		STR_GLOBAL_OK, IMG_GLOBAL_OK,
	                          		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
	                         		numItems, nStrItemList, itemIcons,
	                          		pPopUpList, 0, 0,guiBuffer);
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_sms_mms_setting
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void mmi_mms_entry_sms_mms_setting(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*  guiBuffer=NULL;        			/* Buffer holding history data */
	U16  numItems=0;        			/* Stores no of children in the submenu*/
	U16  nStrItemList[MAX_SUB_MENUS];   	/* Stores the strings id of submenus returned */
	U16  itemIcons[MAX_SUB_MENUS];      	/* Stores the icon id of submenus returned */
	U16  screenId=SCR_ID_SMSMMS_SETTING_MENU;
	U8*  pPopUpList[MAX_SUB_MENUS]; 
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL, 
					mmi_mms_entry_sms_mms_setting, NULL);

	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(SMSMMS_MENU_SETTING_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(SMSMMS_MENU_SETTING_MENUID, nStrItemList);
	GetSequenceImageIds(SMSMMS_MENU_SETTING_MENUID, itemIcons);
	    
	/* construct hint popup strings for menu items */
	ConstructHintsList(SMSMMS_MENU_SETTING_MENUID, pPopUpList);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(SMSMMS_MENU_SETTING_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler); 

	/* Display the call history main screen */
	ShowCategory52Screen(STR_SMS_MMS_SETTING, IMG_MESSAGE_SIM_MMS_MENUENTRY,
	                          		STR_GLOBAL_OK, IMG_GLOBAL_OK,
	                          		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
	                         		numItems, nStrItemList, itemIcons,
	                          		pPopUpList, 0, 0,guiBuffer);
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_sms_mms_memory_status
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void mmi_mms_entry_sms_mms_memory_status(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*  guiBuffer=NULL;        			/* Buffer holding history data */
	U16  numItems=0;        			/* Stores no of children in the submenu*/
	U16  nStrItemList[MAX_SUB_MENUS];   	/* Stores the strings id of submenus returned */
	U16  itemIcons[MAX_SUB_MENUS];      	/* Stores the icon id of submenus returned */
	U16  screenId=SCR_ID_SMSMMS_MEMORY_STATUS_MENU;
	U8*  pPopUpList[MAX_SUB_MENUS]; 
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL, 
					mmi_mms_entry_sms_mms_memory_status, NULL);

	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(SMSMMS_MENU_MEMORY_STATUS_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(SMSMMS_MENU_MEMORY_STATUS_MENUID, nStrItemList);
	GetSequenceImageIds(SMSMMS_MENU_MEMORY_STATUS_MENUID, itemIcons);
	    
	/* construct hint popup strings for menu items */
	ConstructHintsList(SMSMMS_MENU_MEMORY_STATUS_MENUID, pPopUpList);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(SMSMMS_MENU_MEMORY_STATUS_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler); 

	/* Display the call history main screen */
	ShowCategory52Screen(STR_SMS_MMS_MEMORY_STATUS, IMG_MESSAGE_SIM_MMS_MENUENTRY,
	                          		STR_GLOBAL_OK, IMG_GLOBAL_OK,
	                          		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
	                         		numItems, nStrItemList, itemIcons,
	                          		pPopUpList, 0, 0,guiBuffer);
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_view_wap_push_detail
 *       Purpose: view message details 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_view_wap_push_detail(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 		i = 0, j = 0;
	U8*		guiBuffer=NULL;
	U16		screenId=SCR_ID_MMS_INBOX_WAP_DETAILS;
	char*	temp = NULL;
	char		time[MMS_MAX_DATE_LEN] = {0};
	S32		str_len = 0;
	
	char		ansiiTempBuff[MAX_SHOW_STRING_BUF*8];
	char		ucs2TempBuff[MAX_SHOW_STRING_BUF*8];
	P_MESSAGELIST pMsg = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	pMsg = mms_file_manager_get_current_message();
	if (!pMsg)
	{
		return;
	}
	while (i < 14)	
	{
		time[j++] = pMsg->date[i++];
		if (i == 4 || i == 6)
		{
			time[j++] = '-';
		}
		else if (i == 8)
		{
			time[j++] = '\n';
		}
		else if (i == 10 || i == 12)
		{
			time[j++] = ':';
		}
	}

	memset(UnicodeBuf,0,sizeof(UnicodeBuf));
	/* 主题*/
	if(pMsg->msgtype==MESSAGE_WAP)
	{
		pfnUnicodeStrcpy((PS8)UnicodeBuf,(S8 *)GetString(STR_WAP_PUSHMESSAGE_ID));
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	}
	else if(pMsg->msgtype==MESSAGE_OTA_BOOKMARK)
	{
		pfnUnicodeStrcpy((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_WAP_OTA_BOOKMARK));
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
	}
	else if(pMsg->msgtype==MESSAGE_OTA_SET)
	{		
		pfnUnicodeStrcpy((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_WAP_OTA_SETTING));
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
	}
	if(pMsg->subject!=NULL)
	{	
		temp=Cms_mms_uni8_16(pMsg->subject);
		pfnUnicodeStrncat((PS8)UnicodeBuf,(PS8)temp,40);
		mms_Free(temp);
		temp = NULL;
	}
	else
	{
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"<");
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_GLOBAL_EMPTY));
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L">");
	}
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n\n");

	/*	URL	*/

	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_WAP_PUSHURL_ID));
	if(pMsg->url!=NULL)
	{	
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		sprintf( (S8 *)ansiiTempBuff, "\n%s",pMsg->url);
		memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
		AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
	}
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n\n");
#ifdef SUPPORT_OTA_PUSH
 	if(pMsg->msgtype==MESSAGE_OTA_SET)
	{	
		/*gateway*/
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_WAP_SETTINGS_GATEWAY_ID));		
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
		if(pMsg->ota_gateway!=NULL){
			memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
			sprintf( (S8 *)ansiiTempBuff, "%s\n\n",pMsg->ota_gateway);
			memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
			AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
			pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
		}

		/*port*/
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_WAP_SETTINGS_PORT_ID));		
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
		if(pMsg->ota_port!=NULL){
			memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
			sprintf( (S8 *)ansiiTempBuff, "%s\n\n",pMsg->ota_port);
			memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
			AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
			pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
		}
		/*MMS Center*/
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_SETTING_MMSC_OPTIONS));		
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
		if(pMsg->ota_murl!=NULL){
			memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
			sprintf( (S8 *)ansiiTempBuff, "%s\n\n",pMsg->ota_murl);
			memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
			AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
			pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
		}
		/*APN*/
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_ID_DTCNT_GPRS_APN));		
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
		if(pMsg->ota_apn!=NULL){
			memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
			sprintf( (S8 *)ansiiTempBuff, "%s\n\n",pMsg->ota_apn);
			memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
			AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
			pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
		}
		
		/*GPRS/CSD.......*/
	}
#endif	
	/*接收时间*/
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_SENT));

	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	sprintf( (S8 *)ansiiTempBuff, ":\n%s\n\n",time);
	memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);

	str_len=pfnUnicodeStrlen((PS8)UnicodeBuf);
	
	EntryNewScreen(screenId, NULL,
				mmi_mms_view_wap_push_detail, NULL);
	
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
	
	ShowCategory74Screen(STR_MMS_INBOX_OPTIONS_DETAILS,IMG_MESSAGE_SIM_MMS_MENUENTRY,
						STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS,STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						(PU8)UnicodeBuf, str_len, guiBuffer);
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetLeftSoftkeyFunction(mmi_mms_enter_inbox_wap_push_options, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_enter_inbox_wap_push_options
 *       Purpose: enter inbox options
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_enter_inbox_wap_push_options(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer=NULL;
	U16 		numItems=0;
	U16 		nStrItemList[MAX_SUB_MENUS];
	U16 		itemIcons[MAX_SUB_MENUS];
	U16 		screenId=SCR_ID_MMS_INBOX_WAP_OPTIONS;
	U8** 	pPopUpList=NULL;
	P_MESSAGELIST pMsg = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_Tracer("mmi_mms_enter_inbox_wap_push_options in ");
	pMsg = mms_file_manager_get_current_message();
	EntryNewScreen(screenId,NULL,
				mmi_mms_enter_inbox_wap_push_options, NULL);

	guiBuffer = GetCurrGuiBuffer(screenId);		
	numItems = GetNumOfChild(MMS_INBOX_WAP_OPTIONS_MENUID);
	GetSequenceStringIds(MMS_INBOX_WAP_OPTIONS_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_INBOX_WAP_OPTIONS_MENUID, itemIcons);
	if(pMsg->msgtype==MESSAGE_OTA_BOOKMARK)
	{
		nStrItemList[0]=STR_MMS_WAP_OTA_ADD_BOOKMARK;
	}
	else if(pMsg->msgtype==MESSAGE_OTA_SET)
	{
		nStrItemList[0]=STR_MMS_WAP_OTA_ADD_SETTING;
	}
	nStrItemList[2]=STR_WAP_PUSHBOXOPTION_DELETEALL_ID;
	SetMessagesCurrScrnID(screenId);
	SetParentHandler(MMS_INBOX_WAP_OPTIONS_MENUID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	
	ShowCategory52Screen(STR_MMS_INBOX_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer );
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_box_options, KEY_EVENT_UP);	
}
 #endif
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_new_mms_full_indication
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
U16 mms_edit_new_mms_full_indication(void)
{
	/*判断是否到达最大限制*/
	U16 count = 0;
	S32 msize = 0;
		
	mms_get_all_boxes_count_size(&count, &msize);
	if ((count + 1) > MAX_MESSAGE_COUNT)
	{
		DisplayPopup((U8*)GetString(STR_MMS_COUNT_REACHED_MAX), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return TRUE;
	}
	if (MAX_SIZE_ALL_MMS <= MMS_MAX_SIZE_OF_MESSAGE)
	{
		char		buffer[MAX_SHOW_STRING_BUF] = {0};
		char		temp_buffer[20]={0};
		char		temp[20] = {0};

		pfnUnicodeStrcpy(buffer, (const char*)GetString(STR_MMS_QUOTA_EXCEEDED));
		sprintf(temp_buffer,"%d K\n",(int)(MAX_SIZE_ALL_MMS/1024));
		AnsiiToUnicodeString ((S8*)temp, temp_buffer);
		pfnUnicodeStrcat(buffer, (const char*)temp);
		DisplayPopup((U8*)buffer, IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return TRUE;
	}
	return FALSE;
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_new_message
 *       Purpose: entry new message menu screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void mmi_mms_entry_new_message(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 guiBuffer=NULL;		/* Buffer holding history data */
	U16	 numItems=0;		/* Stores no of children in the submenu*/
	U16	 nStrItemList[MAX_SUB_MENUS];	/* Stores the strings id of submenus returned */
	U16	 itemIcons[MAX_SUB_MENUS];		/* Stores the icon id of submenus returned */
	U16	 screenId=SCR_ID_MMS_WMESSAGE_MENU;
	U8*	 pPopUpList[MAX_SUB_MENUS];	
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(!g_msg_cntx.msg_init)
	{
		/*对从快捷菜单进入时做判断*/
		DisplayPopup((PU8)GetString(STR_MSG_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
		return;
	}
	if(mms_edit_new_mms_full_indication()==TRUE)
	{
		return;
	}
	mms_Tracer("mmi_mms_entry_new_message");
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_new_message, NULL);
	
	mmsflag.gnew_message=TRUE;
	gsendto_options=SENDTO_UNKNOWN;
	mms_file_manager_set_current_folder(MMS_FOLDER_UNKNOWN);
	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(MMS_MENU_WMESSAGE_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(MMS_MENU_WMESSAGE_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_MENU_WMESSAGE_MENUID, itemIcons);
	
	/* Construct hint popup strings for menu items */
	ConstructHintsList(MMS_MENU_WMESSAGE_MENUID, pPopUpList);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	SetMessagesScrnIdToDelHistoryNodes(screenId);
	/*  Set current parent id*/
	SetParentHandler(MMS_MENU_WMESSAGE_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	/* Display the call history main screen */
	ShowCategory52Screen(STR_MMS_WMESSAGE, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						   pPopUpList, 0, 0, guiBuffer);
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_indication_save_message, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_sendto_option
 *       Purpose: entry send to phone number or email sreen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_to_option(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 guiBuffer=NULL;		/* Buffer holding history data */
	U16	 numItems=0;		/* Stores no of children in the submenu*/
	U16	 nStrItemList[MAX_SUB_MENUS];	/* Stores the strings id of submenus returned */
	U16	 itemIcons[MAX_SUB_MENUS];		/* Stores the icon id of submenus returned */
	U16	 screenId=SCR_ID_MMS_SEND_TO_MENU;
	U8** pPopUpList=NULL;
		
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_to_option, NULL);
	mms_Tracer((char *) "mmi_mms_entry_to_option");
	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(MMS_WMESSAGE_TO_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(MMS_WMESSAGE_TO_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_WMESSAGE_TO_MENUID, itemIcons);

	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(MMS_WMESSAGE_TO_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	/* Display the call history main screen */
	ShowCategory52Screen(STR_MMS_TO_ID, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						   (U8 **) pPopUpList, 0, 0, guiBuffer);
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_cc_option
 *       Purpose: entry add cc option screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_cc_option(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 guiBuffer=NULL;		/* Buffer holding history data */
	U16	 numItems=0;		/* Stores no of children in the submenu*/
	U16	 nStrItemList[MAX_SUB_MENUS];	/* Stores the strings id of submenus returned */
	U16	 itemIcons[MAX_SUB_MENUS];		/* Stores the icon id of submenus returned */
	U16	 screenId=SCR_ID_MMS_SEND_TO_MENU;
	U8** pPopUpList=NULL;	
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_cc_option, NULL);
	mms_Tracer((char *) "mmi_mms_entry_cc_option");
	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(MMS_WMESSAGE_CC_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(MMS_WMESSAGE_CC_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_WMESSAGE_CC_MENUID, itemIcons);

	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(MMS_WMESSAGE_CC_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	/* Display the call history main screen */
	ShowCategory52Screen(STR_MMS_CC_ID, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						   (U8 **) pPopUpList, 0, 0, guiBuffer);
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_bcc_option
 *       Purpose: entry bcc option screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_bcc_option(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 guiBuffer=NULL;		/* Buffer holding history data */
	U16	 numItems=0;		/* Stores no of children in the submenu*/
	U16	 nStrItemList[MAX_SUB_MENUS];	/* Stores the strings id of submenus returned */
	U16	 itemIcons[MAX_SUB_MENUS];		/* Stores the icon id of submenus returned */
	U16	 screenId=SCR_ID_MMS_SEND_TO_MENU;
	U8** pPopUpList=NULL;	
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_bcc_option, NULL);
	mms_Tracer((char *) "mmi_mms_entry_bcc_option");

	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(MMS_WMESSAGE_BCC_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(MMS_WMESSAGE_BCC_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_WMESSAGE_BCC_MENUID, itemIcons);

	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(MMS_WMESSAGE_BCC_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	/* Display the call history main screen */
	ShowCategory52Screen(STR_MMS_BCC_ID, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						   (U8 **) pPopUpList, 0, 0, guiBuffer);
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_to_option_or_list
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_to_option_or_list(void)
{
	S32 		 		i = 0;
	pSENDTO_LIST 	plist = NULL;

	gsendto_options=SENDTO_TO;
	
	for (plist = pgsendtolist; plist; plist = plist->next)
	{
		i++;
	}
	if(i==0)
	{
		mmi_mms_entry_to_option();
	}
	else
	{
		mmi_mms_entry_sendto_list();
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_cc_option_or_list
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_cc_option_or_list(void)
{
	S32 		 		i = 0;
	pSENDTO_LIST 	plist = NULL;

	gsendto_options=SENDTO_CC;
	
	for (plist = pgsendcclist; plist; plist = plist->next)
	{
		i++;
	}
	if(i==0)
	{
		mmi_mms_entry_cc_option();
	}
	else
	{
		mmi_mms_entry_sendto_list();
	}

}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_bcc_option_or_list
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_bcc_option_or_list(void)
{
	S32 		 		i = 0;
	pSENDTO_LIST 	plist = NULL;

	gsendto_options=SENDTO_BCC;
	
	for (plist = pgsendbcclist; plist; plist = plist->next)
	{
		i++;
	}
	if(i==0)
	{
		mmi_mms_entry_bcc_option();
	}
	else
	{
		mmi_mms_entry_sendto_list();
	}
}


/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_sendto_list
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_sendto_list(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 				guiBuffer = NULL;
	S32 				hiliteitem = 0, to= 0,cc=0,bcc=0;
	pSENDTO_LIST 	plist = NULL;
	U16 				screenId = SCR_ID_MMS_SEND_TO_LIST;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
				mmi_mms_entry_sendto_list, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);
	
	RegisterHighlightHandler(mms_get_box_index);
	
	if (guiBuffer)
	{
		hiliteitem = ghiliindex;
	}

	switch(gsendto_options)
	{
	case SENDTO_TO:
		for (plist = pgsendtolist; plist; plist = plist->next)
		{
			to++;
		}
		mms_mmi_tracer("sendto_list==to==%d", (char*)to);
		ShowCategory184Screen(STR_MMS_TO_ID, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
								STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK,
								STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
								to, mmi_sendto_list_get_item,
								mmi_sendto_list_get_hint, hiliteitem, 0);
		break;
	case SENDTO_CC:
		for (plist = pgsendcclist; plist; plist = plist->next)
		{
			cc++;
		}		
		mms_mmi_tracer("sendto_list==cc==%d", (char*)cc);
		ShowCategory184Screen(STR_MMS_CC_ID, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
								STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK,
								STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
								cc, mmi_sendto_list_get_item,
								mmi_sendto_list_get_hint, hiliteitem, 0);
		break;
	case SENDTO_BCC:
		for (plist = pgsendbcclist; plist; plist = plist->next)
		{
			bcc++;
		}
		mms_mmi_tracer("sendto_list==bcc==%d", (char*)bcc);
		ShowCategory184Screen(STR_MMS_BCC_ID, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
								STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK,
								STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
								bcc, mmi_sendto_list_get_item,
								mmi_sendto_list_get_hint, hiliteitem, 0);
			break;
	default:
		break;
	}

	SetLeftSoftkeyFunction(mmi_mms_entry_sendtolist_options, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_sendto_menulist, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_sendto_menulist
 *       Purpose: 退出收件人列表
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_sendto_menulist(void)
{
	ghiliindex = 0;
	if(mmsflag.gnew_message==TRUE)
	{
		if(IsScreenPresent(SCR_ID_MMS_WMESSAGE_MENU))
		{
			GoBackToHistory(SCR_ID_MMS_WMESSAGE_MENU);
		}
		else
		{
			GoBackHistory();
		}	
	}
	else
	{
		if(IsScreenPresent(SCR_ID_MMS_EDIT_MESSAGE))
		{
			GoBackToHistory(SCR_ID_MMS_EDIT_MESSAGE);
		}
		else
		{
			GoBackHistory();
		}	
	}	
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_to_sendlist
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_to_sendlist(void)
{
	ExitDisplayPopupConfirm();
	if(IsScreenPresent(SCR_ID_MMS_SEND_TO_LIST))
	{
		GoBackToHistory(SCR_ID_MMS_SEND_TO_LIST);
	}
	else
	{
		GoBackHistory();
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_to_history
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_to_history(void)
{
	ExitDisplayPopupConfirm();
	GoBackHistory();
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
void mmi_mms_entry_sendtolist_options(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer=NULL;
	U16 		numItems=0;
	U16 		nStrItemList[MAX_SUB_MENUS];
	U16 		itemIcons[MAX_SUB_MENUS];
	U16 		screenId=SCR_ID_MMS_SENDTO_OPTIONS;	
	U8*		popUpList[MAX_SUB_MENUS];	
	U32 		maskingByte=-1;
	U8** 	pPopUpList=NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, 
					NULL,
					mmi_mms_entry_sendtolist_options, NULL);
	mms_Tracer((char * )"mmi_mms_entry_sendtolist_options");
	guiBuffer = GetCurrGuiBuffer(screenId);		

	numItems = GetNumOfChild(MMS_SENDTO_OPTIONS_MENUID);
	GetSequenceStringIds(MMS_SENDTO_OPTIONS_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_SENDTO_OPTIONS_MENUID, itemIcons);
	mms_mmi_tracer((kal_char *) "GetNumOfChild  numItems==%d", (char *) numItems);
	mms_mmi_tracer((kal_char *) "GetSequenceStringIds ==%d", (char *) nStrItemList);
	
	MaskStringItems(popUpList,(U8)numItems,maskingByte);
	MaskItems(itemIcons,(U8)numItems,maskingByte);
	MaskHiliteItems(MMS_SENDTO_OPTIONS_MENUID, maskingByte);
	
	numItems=MaskItems(nStrItemList,(U8)numItems,maskingByte);
	mms_mmi_tracer((kal_char *) "GetSequence  numItems==%d", (char *) numItems);
	SetMessagesCurrScrnID(screenId);
	SetParentHandler(MMS_SENDTO_OPTIONS_MENUID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	
	ShowCategory52Screen(STR_MMS_SENDTO_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer );
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_phone_number
 *       Purpose: entry phone number screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_phone_number(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 	guiBuffer=NULL;		/* Buffer holding history data */
	U16	 	screenId=SCR_ID_MMS_ADD_NUMBER;
	int		to_count=0;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	to_count=cms_get_sendtolist_count(SENDTO_TO)\
			+cms_get_sendtolist_count(SENDTO_CC)\
			+cms_get_sendtolist_count(SENDTO_BCC);
	if ( to_count>= MAX_MMS_SENDTO_COUNT)
	{
		mms_Tracer((char*)"sendto list is full!!!");
		DisplayPopup((U8*)GetString(STR_MORE_ADDRESS), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_phone_number, NULL);

	/* Get current screen to gui buffer  for history purposes*/
	if (pfnUnicodeStrlen ((S8*)phb_callbuf))
	{
		memset(gedit.phone_buf, 0 , MMS_MAX_SEND_TO_SIZE);
		pfnUnicodeStrcpy((S8*)gedit.phone_buf,(S8*)phb_callbuf);
		memset(phb_callbuf, 0 , sizeof(phb_callbuf));
		guiBuffer = NULL;
	}
	else
	{	
		guiBuffer = GetCurrGuiBuffer(screenId);
	}
	
	gphb_flag=CMS_PHB_MMS;
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);

	RegisterInputBoxEmptyFunction(mms_sendto_input_empty_lsk_hdlr);
	RegisterInputBoxNotEmptyFunction (mms_sendto_input_no_empty_lsk_hdlr);
	/* Display the call history main screen */
	ShowCategory5Screen(STR_MMS_ID_ADD_NUMBER, IMG_MESSAGE_SIM_MMS_MENUENTRY,STR_GLOBAL_OK,
						NULL,STR_GLOBAL_BACK,NULL, /*INPUT_TYPE_NUMERIC*/INPUT_TYPE_PHONE_NUMBER,
						gedit.phone_buf, MMS_MAX_INPUT_SEND_TO_SIZE,guiBuffer);
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}



/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_email
 *       Purpose: entry email screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_email(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 	guiBuffer=NULL;		/* Buffer holding history data */
	U16	 	screenId=SCR_ID_MMS_ADD_EMAIL;
	int		to_count=0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	to_count=cms_get_sendtolist_count(SENDTO_TO)\
			+cms_get_sendtolist_count(SENDTO_CC)\
			+cms_get_sendtolist_count(SENDTO_BCC);	
	if (to_count>= MAX_MMS_SENDTO_COUNT)
	{
		mms_Tracer((char*)"sendto list is full!!!");
		DisplayPopup((U8*)GetString(STR_MORE_ADDRESS), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_email, NULL);

	/* Get current screen to gui buffer  for history purposes*/
	if (pfnUnicodeStrlen ((S8*)phb_callbuf))
	{
		memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
		pfnUnicodeStrcpy((S8*)gedit.phone_buf,(S8*)phb_callbuf);
		memset(phb_callbuf, 0 , sizeof(phb_callbuf));
		guiBuffer = NULL;
	}
	else
	{
		guiBuffer = GetCurrGuiBuffer(screenId);
	}
	gphb_flag=CMS_PHB_EMAIL;
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);

	RegisterInputBoxEmptyFunction(mms_sendto_input_empty_lsk_hdlr);
	RegisterInputBoxNotEmptyFunction (mms_sendto_input_no_empty_lsk_hdlr);
	/* Display the call history main screen */
	ShowCategory5Screen(STR_MMS_ID_ADD_EMAIL, IMG_MESSAGE_SIM_MMS_MENUENTRY,
						STR_GLOBAL_OK,NULL,STR_GLOBAL_BACK,NULL, 
						INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
						gedit.phone_buf, MMS_MAX_INPUT_SEND_TO_SIZE,guiBuffer);
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_pre_amend_sendto
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_pre_amend_sendto(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 				i = 0;
	char* 			temp = NULL;
	pSENDTO_LIST 	plist = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch(gsendto_options)
	{
	case SENDTO_TO:
		plist=pgsendtolist;
		break;
	case SENDTO_CC:
		plist=pgsendcclist;
		break;
	case SENDTO_BCC:
		plist=pgsendbcclist;
		break;
	default:
		break;
	}
	
	while (i < ghiliindex)
	{
		plist = plist->next;
		i++;
	}
	
	temp = Cms_mms_uni8_16(plist->number);
	memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
	pfnUnicodeStrcpy((S8*)gedit.phone_buf, temp);
	mms_Free(temp);
	temp = NULL;
	gphb_flag=mmi_mms_check_phone_number ((U8*) gedit.phone_buf);
	mmi_mms_entry_amend_sendto();

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_amend_sendto
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_amend_sendto(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer = NULL;
	U16 		screenId = SCR_ID_MMS_AMEND_SENDTO;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	mms_Tracer((char *)"EntryNewScreen mmi_mms_entry_amend_sendto");
	EntryNewScreen(screenId, 
					NULL,
					mmi_mms_entry_amend_sendto, NULL);
	
	SetMessagesCurrScrnID(screenId);	
	if (pfnUnicodeStrlen ((S8*)phb_callbuf))
	{
		memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
		pfnUnicodeStrcpy((S8*)gedit.phone_buf,(S8*)phb_callbuf);
		memset(phb_callbuf, 0 , sizeof(phb_callbuf));
		guiBuffer = NULL;
	}
	else
	{
		guiBuffer = GetCurrGuiBuffer(screenId);
	}

	switch(gphb_flag)
	{
	/*EMAIL*/
	case CMS_PHB_EMAIL:
		
		RegisterInputBoxEmptyFunction(mms_sendto_input_empty_lsk_hdlr);
       	RegisterInputBoxNotEmptyFunction (mms_amend_sendto_input_not_empty_lsk_hdlr);

		ShowCategory5Screen(STR_MMS_TO_ID, IMG_MESSAGE_SIM_MMS_MENUENTRY,STR_GLOBAL_OK,
							IMG_GLOBAL_OK,STR_GLOBAL_BACK,IMG_GLOBAL_BACK,
							INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
							gedit.phone_buf, MMS_MAX_INPUT_SEND_TO_SIZE, guiBuffer);
		break;
		
	/*PHONE*/	
	case CMS_PHB_MMS:

		RegisterInputBoxEmptyFunction(mms_sendto_input_empty_lsk_hdlr);
       	RegisterInputBoxNotEmptyFunction (mms_amend_sendto_input_not_empty_lsk_hdlr);
		
		ShowCategory5Screen(STR_MMS_TO_ID, IMG_MESSAGE_SIM_MMS_MENUENTRY,STR_GLOBAL_OK,
							NULL,STR_GLOBAL_BACK,NULL, INPUT_TYPE_NUMERIC,
							gedit.phone_buf, MMS_MAX_INPUT_SEND_TO_SIZE,guiBuffer);
		break;
	}
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_del_sendto
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_del_sendto(void)
{
	mms_Tracer((char *)"mmi_mms_entry_del_sendto");
	mmi_mms_display_confirm((UI_string_type)get_string(STR_REMOVE_CONFIRM),
							mms_remove_from_sendto_list_confirm, mmi_mms_exit_to_sendlist);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_del_all_sendto
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_del_all_sendto(void)
{
	mms_Tracer((char *)"mmi_mms_entry_del_all_sendto");
	mmi_mms_display_confirm((UI_string_type)get_string(STR_REMOVE_CONFIRM),
							mms_remove_all_from_sendto_list_confirm, mmi_mms_exit_to_sendlist);

}
/* ----------------------------------------------------------------------------
 * Function Name: mms_sendto_input_empty_lsk_hdlr
 *       Purpose:  收件人输入框为空时左键响应函数
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_sendto_input_empty_lsk_hdlr (void)
{
	ChangeLeftSoftkey (STR_SMS_COMMON_SEARCH, IMG_GLOBAL_OPTIONS);
	SetLeftSoftkeyFunction (mmi_cms_entry_search_from_phb, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_sendto_input_no_empty_lsk_hdlr
 *       Purpose:  收件人输入框不空时左键响应函数
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_sendto_input_no_empty_lsk_hdlr (void)
{
	ChangeLeftSoftkey (STR_GLOBAL_OK, IMG_GLOBAL_OK);
	SetLeftSoftkeyFunction (mms_add_phone_email_to_sendto_list, KEY_EVENT_UP);
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_amend_sendto_input_not_empty_lsk_hdlr
 *       Purpose:  修改收件人输入框不空时左键响应函数
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_amend_sendto_input_not_empty_lsk_hdlr (void)
{
	ChangeLeftSoftkey (STR_GLOBAL_OK, IMG_GLOBAL_OK);
	SetLeftSoftkeyFunction (mms_amend_sendto_address_confirm, KEY_EVENT_UP);
}

void mms_input_box_set_lsk(void)
{
	ChangeLeftSoftkey (STR_GLOBAL_OK, IMG_GLOBAL_OK);
	SetLeftSoftkeyFunction (mmi_confirm_input_text_handler, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_subject_input
 *       Purpose: entry mms subject input screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_subject_input(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 guiBuffer=NULL;		/* Buffer holding history data */
	U16	 screenId=SCR_ID_MMS_SUBJECT_EDIT;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_subject_input, NULL);

	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);

	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(MMS_MENU_WMESSAGE_MENUID);

	ginput_screen = INPUT_OPTION_SUBJECT;
	memset(gedit.temp, 0, MMS_MAX_CENTRE_ADDR_LENGTH);
	memcpy(gedit.temp, gedit.sub_buf, MMS_MAX_SUBJECT_SIZE);
	RegisterInputBoxEmptyFunction(mms_input_box_set_lsk);
       	RegisterInputBoxNotEmptyFunction (mms_input_box_set_lsk);
	/* Display the call history main screen */
	ShowCategory5Screen(STR_MMS_SUBJECT_ID,IMG_MESSAGE_SIM_MMS_MENUENTRY,STR_GLOBAL_OK,
						IMG_GLOBAL_OK,STR_GLOBAL_BACK,IMG_GLOBAL_BACK,
						INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
						gedit.sub_buf,MMS_MAX_INPUT_SUBJECT_SIZE,guiBuffer);
	
	/* Register function with right softkey */
	SetLeftSoftkeyFunction(/*mmi_mms_entry_input_options*/mmi_confirm_input_text_handler, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetCategory5RightSoftkeyFunction(mmi_mms_exit_sub_input, KEY_EVENT_UP);	
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_sub_input
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_sub_input(void)
{
	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);
	memcpy(gedit.sub_buf, gedit.temp, MMS_MAX_SUBJECT_SIZE);
	mmi_mms_exit_to_new_msg();
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
void mmi_mms_entry_edit_message(void)
{
	pMMS_Content content = NULL;
	pMMS_Slide slide = NULL;
	if (gpeditor_doc)
	{
		if (!gpeditor_doc->slide_cur)
		{
			slide = MMS_New_Slide(gpeditor_doc);
		}
		else
		{
			slide = gpeditor_doc->slide_cur;
		}
		content = slide->content_cur;
	}
	mmsflag.gmsg_saved= FALSE;
	mmi_mms_edit_show_message();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_edit_content
 *       Purpose: entry mms message edit content menu
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_edit_content(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer=NULL;
	U16 		numItems=0;
	U16 		nStrItemList[MAX_SUB_MENUS];
	U16 		itemIcons[MAX_SUB_MENUS];
	U16 		screenId = SCR_ID_MMS_EDIT_MESSAGE;
	U8* 		pPopUpList[MAX_SUB_MENUS];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
				mmi_mms_entry_edit_content, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);

	numItems = GetNumOfChild(MMS_MENU_WMESSAGE_MENUID);
	GetSequenceStringIds(MMS_MENU_WMESSAGE_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_MENU_WMESSAGE_MENUID, itemIcons);

	SetMessagesCurrScrnID(screenId);
	SetParentHandler(MMS_MENU_WMESSAGE_MENUID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	ConstructHintsList(MMS_MENU_WMESSAGE_MENUID, pPopUpList);
	switch(gbox_operation)
	{
	case BOX_OPTIONS_EDIT:
		ShowCategory52Screen(STR_MMS_EDIT, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  pPopUpList, 0, 0, guiBuffer);
		break;
	case BOX_OPTIONS_REPLY:
		ShowCategory52Screen(STR_MMS_INBOX_OPTIONS_REPLY, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						   pPopUpList, 0, 0, guiBuffer);
		break;
	case BOX_OPTIONS_FORWARD:
		ShowCategory52Screen(STR_MMS_INBOX_OPTIONS_FORWARD, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						   pPopUpList, 0, 0, guiBuffer);
		break;
	default:
		break;
	}
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_indication_save_message, KEY_EVENT_UP);
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
void mmi_mms_entry_edit_content_options(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 		i = 1;
	U8* 		guiBuffer=NULL;
	U16 		numItems=0;

	U16 		itemIcons[MAX_SUB_MENUS];
	U16 		screenId = SCR_ID_MMS_CONTENT_OPTIONS;
	U8* 		popUpList[MAX_SUB_MENUS];
	U32 		maskingByte=-1;
	U8** 	pPopUpList=NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_stop_animation();
	memset(gnStrItemList, 0, 12);
	gCurActionItem = 0;

	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_edit_content_options, NULL);
	SetMessagesCurrScrnID(screenId);
	{
		gnStrItemList[0] = STR_MMS_CONTENT_OPTIONS_EDITTEXT;	/*文本编辑*/
		itemIcons[0] = IMG_GLOBAL_L1;

		if (gpeditor_doc->slide_cur->image_flag == 0)	/*加入图像*/
		{
			gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_INSERTNEWIMAGE;
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
		if (gpeditor_doc->slide_cur->audiosize <= 0)		/*加入音乐*/
		{
			gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_ADDMUSIC;
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
#if 1       //only one accessory can contained in a MMS  add by jinliang 20070809
#if 0
		if (gpeditor_doc->slide_cur->accessory_flag == 0)		/*加入accessory*/
		{
			pMMS_Slide 		slide=NULL;
			slide = gpeditor_doc->slide_root;
			while(slide->accessory_flag == 0 && slide != gpeditor_doc->slide_cur)
			{
				slide = slide->next;
			}
			if(slide == gpeditor_doc->slide_cur)
			{
				gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_INSERTNEWACCESSORY;
				itemIcons[i] = IMG_GLOBAL_L1 + i;
				i++;
			}
		}
#endif			
#else
		if (gpeditor_doc->slide_cur->accessory_flag == 0)		/*加入accessory*/
		{
			gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_INSERTNEWACCESSORY;
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
#endif
		if (gpeditor_doc->slide_cur->text_flag == 1)		/*清空文字*/
		{
			gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_EMPTYTEXT;
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
		if (gpeditor_doc->slide_cur->image_flag == 1)	/*移除图像*/
		{
			gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_DELCURRENTIMAGE;
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
		if (gpeditor_doc->slide_cur->audiosize > 0)		/*移除音乐*/
		{
			gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_DELCURRENTMUSIC;
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
#if 1       //only one accessory can contained in a MMS  add by jinliang 20070809
#if 0
		if (gpeditor_doc->slide_cur->accessory_flag == 1)		/*移除accessory*/
		{
			gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_DELCURRENTACCESSORY;
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
		else
		{
			pMMS_Slide 		slide=NULL;
			slide = gpeditor_doc->slide_root;
			while(slide->accessory_flag == 0 && slide != gpeditor_doc->slide_cur)
			{
				slide = slide->next;				
			}
			if(slide->accessory_flag == 1)
			{
				gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_DELCURRENTACCESSORY;
				itemIcons[i] = IMG_GLOBAL_L1 + i;
				i++;
			}
			
		}
#endif
#else
	
		if (gpeditor_doc->slide_cur->accessory_flag == 1)		/*移除accessory*/
		{
			gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_DELCURRENTACCESSORY;
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
#endif
		gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_FRAMETIME;	/*本页播放时间*/
		itemIcons[i] = IMG_GLOBAL_L1 + i;
		i++;
		if (gpeditor_doc->slide_cur->prev)				/*上一页*/
		{
			gnStrItemList[i] = STR_MMS_PREV_SLIDE;
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
		if (gpeditor_doc->slide_cur->next)				/*下一页*/
		{
			gnStrItemList[i] = STR_MMS_NEXT_SLIDE;
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
		#if 1
		if (MMSGetSlideCount(gpeditor_doc) < MAX_MMS_SLIDE_MMS)
		{
			gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_INSERTNEWFRAME;	/*新加一页*/
			itemIcons[i] = IMG_GLOBAL_L1 + i;
			i++;
		}
		#endif
		gnStrItemList[i] = STR_MMS_CONTENT_OPTIONS_DELCURRENTFRAME;	/*删除本页*/
		itemIcons[i] = IMG_GLOBAL_L1 + i;
		i++;

		gnStrItemList[i] = STR_MMS_SEND_OPTIONS_VIEW;	/*预览*/
		itemIcons[i] = IMG_GLOBAL_L1 + i;
		i++;
	}
	numItems = i;
	guiBuffer = GetCurrGuiBuffer(screenId);
	
	MaskStringItems(popUpList,(U8)numItems,maskingByte);
	MaskItems(itemIcons,(U8)numItems,maskingByte);
	MaskHiliteItems(MMS_WMESSAGE_CONTENT_OPTIONS_MENUID,maskingByte);
 	numItems=MaskItems(gnStrItemList,(U8)numItems,maskingByte);
	
	RegisterHighlightHandler(mmi_get_cur_sub_hiliIndex);

	ShowCategory52Screen(STR_EDIT_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, gnStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer);
	SetLeftSoftkeyFunction(mmi_mms_edit_options_hander, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
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
void mmi_mms_edit_options_hander(void)
{
	switch(gnStrItemList[gCurActionItem])
	{
	case STR_MMS_CONTENT_OPTIONS_EDITTEXT:
		{
			int 			buf_size = 0;
			FILE_HANDLE 	fd = 0;
			pMMS_Content content = gpeditor_doc->slide_cur->content_root;
			
			memset(gedit.text_buf, 0, MMS_MAX_TEXT_SIZE);
			for (; content; content = content->next)
			{
				if (content->type == MMS_TYPE_TEXT)
				{
					fd = mmsf_Open(content->filename, "r");
					if (fd > 0)
					{
						memset(gedit.text_buf, 0, MMS_MAX_TEXT_SIZE);
						mmsf_Read((char *)(&buf_size),sizeof(unsigned short),1,fd);
						if (buf_size > 2000)
						{
							buf_size = 2000;
						}
						mmsf_Read((char*)gedit.text_buf, 1,buf_size, fd);
						mmsf_Close(fd);
					}
					break;
				}
			}
		}
		mmi_mms_entry_edit_text_input();
		break;
	case STR_MMS_CONTENT_OPTIONS_INSERTNEWIMAGE:
		mmi_mms_entry_image_folder();
		break;
	case STR_MMS_CONTENT_OPTIONS_ADDMUSIC:
		mmi_mms_entry_music_folder();
		break;
	case STR_MMS_CONTENT_OPTIONS_INSERTNEWACCESSORY:
		mmi_mms_entry_accessory_folder();
		break;
	case STR_MMS_CONTENT_OPTIONS_INSERTNEWFRAME:
		mmi_mms_edit_new_frame();
		break;
	case STR_MMS_CONTENT_OPTIONS_FRAMETIME:
		mmi_mms_edit_pre_set_frame_time();
		break;
	case STR_MMS_CONTENT_OPTIONS_DELCURRENTIMAGE:
		mmi_mms_edit_delete_image();
		break;
	case STR_MMS_CONTENT_OPTIONS_DELCURRENTMUSIC:
		mmi_mms_edit_delete_music();
		break;
	case STR_MMS_CONTENT_OPTIONS_DELCURRENTACCESSORY:
		mmi_mms_edit_delete_accessory();
		break;
	case STR_MMS_CONTENT_OPTIONS_DELCURRENTFRAME:
		mmi_mms_edit_delete_frame();
		break;
	case STR_MMS_CONTENT_OPTIONS_EMPTYTEXT:
		mmi_mms_edit_empty_text();
		break;
	case STR_MMS_NEXT_SLIDE:
		if(!MMS_NextSlide(gpeditor_doc))
		{
			return ;
		}
		gedit.start_height = 0;
		gedit.total_height = 0;
		if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
		{
			GoBackToHistory(SCR_ID_SHOW_MESSAGE);
		}
		else
		{
			GoBackHistory();
		}
		break;
	case STR_MMS_PREV_SLIDE:
		if(!MMS_PrevSlide(gpeditor_doc))
		{
			return ;
		}
		gedit.start_height = 0;
		gedit.total_height = 0;
		if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
		{
			GoBackToHistory(SCR_ID_SHOW_MESSAGE);
		}
		else
		{
			GoBackHistory();
		}
		break;
	case STR_MMS_SEND_OPTIONS_VIEW:
		mmi_mms_play_message();
		break;
	default:
		break;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_edit_text_input
 *       Purpose: entry mms text input screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_edit_text_input(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer = NULL;
	U16 		screenId = SCR_ID_MMS_WMESSAGE_EDIT_TEXT;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
				mmi_mms_entry_edit_text_input, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);
	ginput_screen = INPUT_OPTION_TEXT;
	SetMessagesCurrScrnID(screenId);
	
	RegisterInputBoxEmptyFunction(mms_input_box_set_lsk);
       	RegisterInputBoxNotEmptyFunction (mms_input_box_set_lsk);
	ShowCategory5Screen(STR_MMS_CONTENT_ID,IMG_MESSAGE_SIM_MMS_MENUENTRY,
						/*STR_GLOBAL_OPTIONS*/STR_GLOBAL_OK,NULL,STR_GLOBAL_BACK,NULL,
						INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
						gedit.text_buf,MMS_MAX_INPUT_TEXT_SIZE,guiBuffer);
	SetLeftSoftkeyFunction(/*mmi_mms_entry_input_options*/mmi_confirm_input_text_handler, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetCategory5RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_empty_text
 *       Purpose: empty text when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_empty_text(void)
{

	mms_del_content(gpeditor_doc, gpeditor_doc->slide_cur, MMS_TYPE_TEXT);
	gpeditor_doc->slide_cur->text_flag = 0;
	gedit.start_height = 0;
	gedit.total_height = 0;
	GoBackToHistory(SCR_ID_SHOW_MESSAGE);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_insert_image
 *       Purpose: add image to mms message when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_insert_image(char* image_buf, S32 buf_size, U16 image_type)
{

	pMMS_Content 	content = NULL;	
	pMMS_Slide 		slide = gpeditor_doc->slide_cur;
	char 			img_fname[MMS_MAX_FILE_NAME_LENGTH] = {0};
	FILE_HANDLE 		fd = 0;

	if ((gpeditor_doc->totalsize + buf_size) > MMS_MAX_SIZE_OF_MESSAGE-MMS_MAX_SIZE_OF_MESSAGEHEAD)//changed by yangjun 060817
	{
		DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		DeleteNHistory(2);
		return ;
	}
	mms_get_randstring(img_fname);
	switch(image_type)
	{
	case MMS_TYPE_GIF:
		strcat(img_fname,".gif");
		break;
	case MMS_TYPE_JPEG:
		strcat(img_fname,".jpg");
		break;
	case MMS_TYPE_PNG:
		strcat(img_fname,".png");
		break;
	case MMS_TYPE_WBMP:
		strcat(img_fname,".wbmp");
		break;
	case MMS_TYPE_BMP1:
		strcat(img_fname,".bmp");
		break;
	}
	fd = mmsf_Open((char*)img_fname,"w");
	if (fd <= 0)
	{
		return ;
	}
	mmsf_Write(image_buf, 1, buf_size, fd);
	mmsf_Close(fd);
	content = MMS_New_Content((unsigned char*)img_fname,image_type,slide,gpeditor_doc);
	gedit.total_height = 0;
	if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
	{
		GoBackToHistory(SCR_ID_SHOW_MESSAGE);
	}
	else
	{
		GoBackHistory();
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_delete_image
 *       Purpose: delete image for mms message when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_delete_image(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	//U16			 	type = 0;
	pMMS_Content 	content = NULL;
	pMMS_Slide   		slide = gpeditor_doc->slide_cur; 
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(slide->image_flag)
	{
		content = slide->content_root;
		while (content)
		{
			if (content->type == MMS_TYPE_GIF ||
				content->type == MMS_TYPE_JPEG ||
				content->type == MMS_TYPE_WBMP ||
				content->type == MMS_TYPE_MP4||
				content->type == MMS_TYPE_PNG ||
				content->type == MMS_TYPE_BMP1)
			{
				//type = content->type;// 20060818 wantao modify begin
				mms_del_content(gpeditor_doc, slide, content->type);
				//break;
			}
			content = content->next;
		}
		//mms_del_content(gpeditor_doc, slide, type);// 20060818 wantao modify end
		slide->image_flag = 0;
		gedit.start_height = 0;
		gedit.total_height = 0;
		if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
		{
			GoBackToHistory(SCR_ID_SHOW_MESSAGE);
		}
		else
		{
			GoBackHistory();
		}
	}
	
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_insert_music
 *       Purpose: add audio to mms message when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_insert_music(char* music_buf, S32 buf_size, U16 music_type)
{	
	pMMS_Slide slide = gpeditor_doc->slide_cur;
	char msc_fname[MMS_MAX_FILE_NAME_LENGTH];
	FILE_HANDLE fd = 0;

	if ((gpeditor_doc->totalsize + buf_size) > MMS_MAX_SIZE_OF_MESSAGE-MMS_MAX_SIZE_OF_MESSAGEHEAD)//changed by yangjun 060817
	{
		DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		DeleteNHistory(2);
		return ;
	}
	mms_get_randstring(msc_fname);

	switch(music_type)
	{
	case MMS_TYPE_WAV:
		strcat(msc_fname, ".wav");
		break;
	case MMS_TYPE_MIDI:
		strcat(msc_fname, ".mid");
		break;
	case MMS_TYPE_IMY:
		strcat(msc_fname, ".imy");
		break;
	case MMS_TYPE_MMF:
		strcat(msc_fname, ".mmf");
		break;
	case MMS_TYPE_MP3:
		strcat(msc_fname, ".mp3");
		break;
	case MMS_TYPE_AMR:
		strcat(msc_fname, ".amr");
		break;
	default:
		break;	
	}

	fd = mmsf_Open((char*)msc_fname,"w");	
	if (fd <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	mmsf_Write(music_buf, 1, buf_size, fd);
	mmsf_Close(fd);

	if(!MMS_New_Audio((U8*)msc_fname,music_type,slide,gpeditor_doc))
	{
		return ;
	}
	if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
	{
		GoBackToHistory(SCR_ID_SHOW_MESSAGE);
	}
	else
	{
		GoBackHistory();
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_delete_music
 *       Purpose: deldete audio from mms message when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_delete_music(void)
{
	if (gpeditor_doc->slide_cur->audiosize > 0)
	{
		MMS_DelAudio(gpeditor_doc->slide_cur, gpeditor_doc);
		if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
		{
			GoBackToHistory(SCR_ID_SHOW_MESSAGE);
		}
		else
		{
			GoBackHistory();
		}
	}	
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_insert_accessory
 *       Purpose: add accessory to mms message when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_insert_accessory(char* accessory_buf, S32 buf_size, U16 accessory_type)
{
	pMMS_Content 	content = NULL;	
	pMMS_Slide 		slide = gpeditor_doc->slide_cur;
	char 			accessory_fname[MMS_MAX_FILE_NAME_LENGTH] = {0};
	FILE_HANDLE 		fd = 0;

	if ((gpeditor_doc->totalsize + buf_size) > MMS_MAX_SIZE_OF_MESSAGE-MMS_MAX_SIZE_OF_MESSAGEHEAD)//changed by yangjun 060817
	{
		DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		DeleteNHistory(2);
		return ;
	}
	mms_get_randstring(accessory_fname);
	switch(accessory_type)
	{
	case MMS_TYPE_VCF:
		strcat(accessory_fname,".vcf");
		break;
	case MMS_TYPE_VCS:
		strcat(accessory_fname,".vcs");
		break;
	}
	fd = mmsf_Open((char*)accessory_fname,"w");
	if (fd <= 0)
	{
		return ;
	}
	mmsf_Write(accessory_buf, 1, buf_size, fd);
	mmsf_Close(fd);
	content = MMS_New_Content((unsigned char*)accessory_fname,accessory_type,slide,gpeditor_doc);
	gedit.total_height = 0;
	if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
	{
		GoBackToHistory(SCR_ID_SHOW_MESSAGE);
	}
	else
	{
		GoBackHistory();
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_delete_accessory
 *       Purpose: delete accessory for mms message when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_delete_accessory(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	//U16			 	type = 0;
	pMMS_Slide 		slide=NULL;
	pMMS_Content 	content = NULL;
	slide = gpeditor_doc->slide_root;
	while(slide->accessory_flag == 0 && slide != gpeditor_doc->slide_cur)
	{
		slide = slide->next;				
	}
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(slide->accessory_flag)
	{
		content = slide->content_root;
		while (content)
		{
			if (content->type == MMS_TYPE_VCF ||
			    content->type == MMS_TYPE_VCS
			   )
			{
				//type = content->type;// 20060818 wantao modify begin
				mms_del_content(gpeditor_doc, slide, content->type);
				//break;
			}
			content = content->next;
		}
		//mms_del_content(gpeditor_doc, slide, type);// 20060818 wantao modify end
		slide->accessory_flag = 0;
		gedit.start_height = 0;
		gedit.total_height = 0;
		if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
		{
			GoBackToHistory(SCR_ID_SHOW_MESSAGE);
		}
		else
		{
			GoBackHistory();
		}
	}
	
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_pre_set_frame_time
 *       Purpose:  Prepare data for set time for play frame
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_pre_set_frame_time(void)
{
	memset(gedit.frametime, 0, MMS_MAX_FRAME_TIME_LENGTH);
	mmi_mms_edit_set_frame_time();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_set_frame_time
 *       Purpose: set time for play frame
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_set_frame_time(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer = NULL;
	U16 		screenId = SCR_ID_MMS_SLIDE_TIME_SETTING;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	EntryNewScreen(screenId, NULL,mmi_mms_edit_set_frame_time, NULL);

	CMS_itoa_unicode((U16)(gpeditor_doc->slide_cur->times / 1000), gedit.frametime);

	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);
	
	ShowCategory5Screen(STR_MMS_CONTENT_OPTIONS_FRAMETIME, IMG_MESSAGE_SIM_MMS_MENUENTRY, STR_GLOBAL_OK,
						NULL, STR_GLOBAL_BACK, NULL,
						INPUT_TYPE_NUMERIC,
						(U8*)gedit.frametime, MMS_MAX_INPUT_FRAME_TIME_LENGTH, guiBuffer);
	
	SetLeftSoftkeyFunction(mmi_mms_frame_time_confirm, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetCategory5RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
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
unsigned int mms_get_slidetime_setting()
{
	if (!(gconfig.frametime[0] == '\0' && gconfig.frametime[1] == '\0'))
	{
		if (!(gconfig.frametime[0] == 48 && gconfig.frametime[2] == 48))
		{
			if (gconfig.frametime[2] != '\0')
			{
				if ((gconfig.frametime[0] - 48) * 10 + (gconfig.frametime[2] - 48) >= 60)
				{
					return (int)60000;
				}
				else
				{
                  			return (int)((gconfig.frametime[0] - 48) * 10 + (gconfig.frametime[2] - 48)) * 1000;
				}
			}
			else
			{		
				if (gconfig.frametime[0]==48)
				{
					return (int)DEFAULT_MMS_SLIDE_TIMES;
				}
				else
				{
                 			return (int)(gconfig.frametime[0] - 48) * 1000;
				}
			}
		}
		else
		{
			return (int)DEFAULT_MMS_SLIDE_TIMES;
		}
	}
	return DEFAULT_MMS_SLIDE_TIMES;
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_new_frame
 *       Purpose: add new frame to mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_new_frame(void)
{
	pMMS_Slide slide = NULL;

	//2006/07/19 chaozhu.zhou add +100 bytes for max size of message
	if ((gpeditor_doc->totalsize + 100) > MMS_MAX_SIZE_OF_MESSAGE)
	{
		DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	
	if (gpeditor_doc)
	{
		slide = MMS_New_Slide(gpeditor_doc);
		
		if (slide)
		{
			gedit.start_height = 0;
			gedit.total_height = 0;
			if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
			{
				GoBackToHistory(SCR_ID_SHOW_MESSAGE);
			}
			else
			{
				GoBackHistory();
			}
		}
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_delete_frame
 *       Purpose: delete the frame from mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_delete_frame(void)
{
	if(gpeditor_doc->slide_cur)
	{
		/*先清空文本*/
		if(gpeditor_doc->slide_cur->text_flag==1)
		{
			mms_del_content(gpeditor_doc, gpeditor_doc->slide_cur, MMS_TYPE_TEXT);
			gpeditor_doc->slide_cur->text_flag = 0;
		}
		
		if (gpeditor_doc->slide_cur == gpeditor_doc->slide_root)	/*删除的为首*/
		{
			if (gpeditor_doc->slide_root->next)					/*页数超过一页*/
			{
				MMS_DelSlide(gpeditor_doc);
			}
			else												/*仅有首页*/
			{
				MMS_DelSlide(gpeditor_doc);
				MMS_New_Slide(gpeditor_doc);
			}
		}
		else
		{
			MMS_DelSlide(gpeditor_doc);
		}
	}
	gedit.start_height = 0;
	gedit.total_height = 0;
	if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
	{
		GoBackToHistory(SCR_ID_SHOW_MESSAGE);
	}
	else
	{
		GoBackHistory();
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_show_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_show_message(void)
{
	U16 screenId=SCR_ID_SHOW_MESSAGE;

	EntryNewScreen(screenId, NULL,
					mmi_mms_edit_show_message, NULL);
	SetMessagesCurrScrnID(screenId);

	if (gpeditor_doc->slide_cur->audiosize > 0)
	{
		ShowCategory221Screen(NULL, IMG_MMS_MUSIC_ADDED,
								STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK,
 								STR_GLOBAL_BACK, IMG_GLOBAL_BACK, GDI_COLOR_WHITE, NULL);
	}
	else
	{
		ShowCategory221Screen(NULL, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
								STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK,
 								STR_GLOBAL_BACK, IMG_GLOBAL_BACK, GDI_COLOR_WHITE, NULL);
	}
	
	#ifdef __MMI_TOUCH_SCREEN__
		mmi_wgui_register_pen_down_handler(mmi_mms_pen_down_hdlr);
		mmi_wgui_register_pen_up_handler(mmi_mms_pen_up_hdlr);
		mmi_wgui_register_pen_move_handler(mmi_mms_pen_move_hdlr);
		mmi_wgui_register_pen_repeat_handler(mmi_mms_pen_repeat_hdlr);
	#endif
	pixtel_UI_create_vertical_scrollbar(&play_show_vbar,UI_device_width-current_MMI_theme->scrollbar_size,
									MMI_MMS_TITLE_HIGHT+1,current_MMI_theme->scrollbar_size,MMI_content_height-1);
	RedrawCategoryFunction = mmi_mms_redraw_edit_show_message;
	mmi_mms_redraw_edit_show_message();
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
void mmi_mms_redraw_edit_show_message(void)
{
	gedit.start_height = 0;
	gedit.total_height = 0;
	
	mmi_change_title_string();

	gdi_layer_lock_frame_buffer();

	if (gpeditor_doc->slide_cur->audiosize > 0)
	{
		ChangeTitle(IMG_MMS_MUSIC_ADDED, (U8*)gedit.title);
	}
	else
	{
		ChangeTitle(IMG_MESSAGE_SIM_MMS_MENUENTRY, (U8*)gedit.title);
	}
	draw_title();
	
	show_softkey_background();
	show_left_softkey();
	show_right_softkey();
	gdi_layer_unlock_frame_buffer();
	
	gdi_layer_blt_base_layer( 0, 0, UI_device_width-1, UI_device_height-1);

	SetLeftSoftkeyFunction(mmi_mms_entry_edit_content_options,KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_mms_exit_to_new_msg,KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_edit_down_frame, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_edit_up_frame, KEY_UP_ARROW, KEY_EVENT_DOWN);
		/*注册侧键*/
	SetKeyHandler(mmi_mms_play_down_frame, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_up_frame, KEY_VOL_UP, KEY_EVENT_DOWN);	

	SetKeyHandler(mmi_mms_edit_previous_frame, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_edit_next_frame, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	
	gdi_layer_lock_frame_buffer();	
    	gdi_layer_push_clip();
	gdi_layer_push_text_clip();

	gdi_layer_set_clip(0, MMI_MMS_TITLE_HIGHT + 1, UI_device_width-1, 
		MMI_MMS_TITLE_HIGHT + MMI_content_height - 2);
	gdi_layer_set_text_clip(0, MMI_MMS_TITLE_HIGHT + 1, UI_device_width-1, 
		MMI_MMS_TITLE_HIGHT + MMI_content_height-2);

	mms_edit_show_text_image();

	gdi_layer_pop_text_clip();
	gdi_layer_pop_clip();
	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_base_layer(0, 0, UI_device_width-1, UI_device_height-1);
	
}
 
/* ----------------------------------------------------------------------------
 * Function Name: mms_edit_show_text_image
 *       Purpose: 编辑彩信时显示文本、图像内容
 *         Input: (GLOBALS)gedit.total_height
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_edit_show_text_image(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 		x = 0, y = gedit.start_height+1;//20060113 cocoma xu modify for bug 30675
	U32 		len = 0,size=0;
	U8* 		str = NULL;
	FILE_HANDLE 		fd = 0;
	pMMS_Content 	content = NULL;
	U32		image_flag=0;// 20060817 wantao add flag for debug when show image
	U32		accessory_flag=0;// add by jinliang 20070726
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	pixtel_UI_set_clip(0,MMI_MMS_TITLE_HIGHT+1,UI_device_width-current_MMI_theme->scrollbar_size-1,UI_device_height-MMI_button_bar_height-1);
	pixtel_UI_fill_rectangle(0,MMI_MMS_TITLE_HIGHT+1,UI_device_width-1,UI_device_height-MMI_button_bar_height-1,pixtel_UI_color(255,255,255));

	content = gpeditor_doc->slide_cur->content_root;
	mms_mmi_tracer("content->type = %d", (char*)content->type);
	mms_mmi_tracer("content->filename = %s", (char*)content->filename);
	
	for(;content;content = content->next)
	{
		switch(content->type)
		{
		case MMS_TYPE_TEXT:
			{
				fd = mmsf_Open(content->filename,"r");
				if (fd)
				{
					mms_Tracer((char*)":MMS_TYPE_TEXT in");
					mmsf_Read((char *)(&len),1,sizeof(unsigned short),fd);		
					str = (U8*)mms_Malloc(len+2);
					if (str == NULL)
					{
						mms_Tracer((char*)"error::str=NULL");
						return;
					}
					memset(str,0,len);
					mmsf_Read((char *)str,1,len,fd);
					mmsf_Close(fd);
					mms_draw_text(str, &x, &y, len);					
					mms_Free(str);
					str = NULL;
					mms_Tracer((char*)"end of draw");
				}
			}
			break;
		case MMS_TYPE_GIF:
			{
				if(image_flag>=1)// 20060817 wantao add flag for debug when show image
				{
					break;
				}
				image_flag = 1;
				fd = mmsf_Open(content->filename,"r");
				if (fd)
				{	
					mms_stop_animation();
					
                    			size=content->contentsize;					
					len = content->contentsize+9;
					
					str = (U8*)mms_Malloc(len+2);
					if (str == NULL)
					{
						return ;
					}
					memset(str, 0, len+2);
					{
						str[0]=IMAGE_TYPE_GIF;
						str[1]=NULL;
						str[2] = (U8) ( size& 0x000000ff);
						str[3] = (U8) ((size >> 8) & 0x000000ff);
						str[4] = (U8) ((size >> 16) & 0x000000ff);
						str[5] = (U8) ((size >> 24) & 0x000000ff);
						str[6]=NULL;
						str[7]=NULL;
					}	
					mmsf_Read((char*)str+8, 1, size+1, fd);					
					mmsf_Close(fd);
					
					ganimation_buf=str;	
					
					mms_Tracer((char*)"mms_draw_picture_for_play_gif");
					mms_draw_picture_for_play(str, &x, &y, len, content->type);

				}
				else
				{
				}
			}
			break;
		case MMS_TYPE_WBMP:
		case MMS_TYPE_JPEG:
		case MMS_TYPE_PNG:
		case MMS_TYPE_BMP1:
			{
				if(image_flag>=1)// 20060817 wantao add flag for debug when show image
				{
					break;
				}
				image_flag = 1;
				fd = mmsf_Open(content->filename,"r");
				if (fd)
				{
					len = content->contentsize;
					str = (U8*)mms_Malloc(len+2);
					if (!str)
					{
						return ;
					}
					memset(str, 0, len+2);
					
					mms_Tracer((char*)"mms_draw_picture_for_play_jpeg");

					mmsf_Read((char*)str, 1, len, fd);
					mmsf_Close(fd);
					mms_draw_picture_for_play(str, &x, &y, len, content->type);

					mms_Free(str);
					str = NULL;
				}
				else
				{
				}
			}
			break;
		case MMS_TYPE_VCF:
		case MMS_TYPE_VCS:
			{
				if(accessory_flag>=1)
				{
					break;
				}
				accessory_flag = 1;
				fd = mmsf_Open(content->filename,"r");
				if (fd)
				{
					len = content->contentsize;
					str = (U8*)mms_Malloc(len+2);
					if (!str)
					{
						return ;
					}
					memset(str, 0, len+2);
					
					mms_Tracer((char*)"MMS_TYPE_VCF or MMS_TYPE_VCS");

					mmsf_Read((char*)str, 1, len, fd);
					mmsf_Close(fd);
					//mms_draw_picture_for_play(str, &x, &y, len, content->type);

					mms_Free(str);
					str = NULL;
				}
				else
				{
				}
			}
			break;
		default:
			break;	
		}
	}
	if (gedit.total_height <= 0)
	{
		gedit.total_height = y;
	}
	/* show vertical scrollbar range*/
	if(gedit.total_height<=MMI_content_height)
	{
		pixtel_UI_set_vertical_scrollbar_range(&play_show_vbar,1);
		pixtel_UI_set_vertical_scrollbar_scale(&play_show_vbar,1);
		pixtel_UI_set_vertical_scrollbar_value(&play_show_vbar,1);
	}
	else
	{
		pixtel_UI_set_vertical_scrollbar_range(&play_show_vbar,(gedit.total_height));
		pixtel_UI_set_vertical_scrollbar_scale(&play_show_vbar,MMI_content_height);
		pixtel_UI_set_vertical_scrollbar_value(&play_show_vbar,(-gedit.start_height));
	}
	mms_mmi_tracer("hello,gedit.total_height=%d", (char*)gedit.total_height);
	mms_mmi_tracer("hello,gedit.start_height=%d", (char*)gedit.start_height);
	pixtel_UI_show_vertical_scrollbar( &play_show_vbar );
	
	#if (UI_DOUBLE_BUFFER_SUPPORT)	
		pixtel_UI_BLT_double_buffer(0,0,UI_device_width-1,UI_device_height-1);
	#endif
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_next_frame
 *       Purpose: show next frame when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_next_frame(void)
{
	if(!MMS_NextSlide(gpeditor_doc))
	{
		return ;
	}
	mms_stop_animation();
	gedit.start_height = 0;
	gedit.total_height = 0;
	mmi_change_title_string();
	
	gdi_layer_lock_frame_buffer();
	if (gpeditor_doc->slide_cur->audiosize > 0)
	{
		ChangeTitle(IMG_MMS_MUSIC_ADDED, (U8*)gedit.title);
	}
	else
	{
		ChangeTitle(IMG_MESSAGE_SIM_MMS_MENUENTRY, (U8*)gedit.title);
	}
	draw_title();
	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_base_layer( 0, 0, UI_device_width-1, UI_device_height-1);

	mms_edit_show_text_image();	
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_previous_frame
 *       Purpose: previous next frame when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_previous_frame(void)
{
	if(!MMS_PrevSlide(gpeditor_doc))
	{
		return ;
	}
	mms_stop_animation();
	gedit.start_height = 0;
	gedit.total_height = 0;
	mmi_change_title_string();

	gdi_layer_lock_frame_buffer();
	if (gpeditor_doc->slide_cur->audiosize > 0)
	{
		ChangeTitle(IMG_MMS_MUSIC_ADDED, (U8*)gedit.title);
	}
	else
	{
		ChangeTitle(IMG_MESSAGE_SIM_MMS_MENUENTRY, (U8*)gedit.title);
	}
	draw_title();
	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_base_layer( 0, 0, UI_device_width-1, UI_device_height-1);

	mms_edit_show_text_image();	
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_up_frame
 *       Purpose: up  frame when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_up_frame(void)
{
	if (gedit.start_height >= 0)
	{
		return ;
	}
	gedit.start_height += MMI_LINE_HEIGHT;
	if (gedit.start_height > 0)
	{
		gedit.start_height = 0;
	}
	mms_edit_show_text_image();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_down_frame
 *       Purpose: down frame when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_edit_down_frame(void)
{
	if (gedit.total_height <= (MMI_content_height - 2))
	{
		return ;
	}
	
	if ((gedit.start_height + gedit.total_height + MMI_ORIGIN_Y) == (MMI_content_height + MMI_MMS_TITLE_HIGHT - 1))
	{
		return;
	}
	if ((gedit.start_height + gedit.total_height + MMI_ORIGIN_Y) < (MMI_content_height + MMI_MMS_TITLE_HIGHT - 1))	
	{
		return;
	}
	gedit.start_height -= MMI_LINE_HEIGHT;
		
	mms_edit_show_text_image();

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_post_play_message
 *       Purpose:before play message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void mmi_mms_post_play_message()
{
	mmi_mms_post_message(CMS_MESSAGE_MMS_PLAY_MESSAGE, NULL);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_box_play_message
 *       Purpose:before play message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void mmi_mms_box_play_message()
{
	mms_parse_message_file();
	mmi_mms_play_message();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_play_message
 *       Purpose: play message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_play_message(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16 screenId = SCR_ID_MMS_PREVIEW_MESSAGE;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(GetActiveScreenId()==screenId)
	{
		return;
	}
	if ((int)MMSGetSlideCount(gpeditor_doc) <= 0)
	{
		DisplayPopup((U8*)GetString(STR_CONTENT_NULL),IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	mms_Tracer("enter mmi_mms_play_message");   
	EntryNewScreen(screenId, mmi_mms_exit_play, 
					mmi_mms_play_message, NULL);
	
	SetMessagesCurrScrnID(screenId);

	if (gpeditor_doc->slide_cur->audiosize > 0)
	{
		ShowCategory221Screen(NULL, IMG_MMS_MUSIC_ADDED, NULL, NULL,
								STR_MMS_STOPPREV, IMG_GLOBAL_OK,
 								GDI_COLOR_WHITE, NULL);
	}
	else
	{
		ShowCategory221Screen(NULL, IMG_MESSAGE_SIM_MMS_MENUENTRY, NULL, NULL,	
								STR_MMS_STOPPREV, IMG_GLOBAL_OK,
 								GDI_COLOR_WHITE, NULL);
	}
	#ifdef __MMI_TOUCH_SCREEN__
		mmi_wgui_register_pen_down_handler(mmi_mms_pen_down_hdlr);
		mmi_wgui_register_pen_up_handler(mmi_mms_pen_up_hdlr);
		mmi_wgui_register_pen_move_handler(mmi_mms_pen_move_hdlr);
		mmi_wgui_register_pen_repeat_handler(mmi_mms_pen_repeat_hdlr);
	#endif	
	pixtel_UI_create_vertical_scrollbar(&play_show_vbar,UI_device_width-current_MMI_theme->scrollbar_size,
									MMI_MMS_TITLE_HIGHT+1,current_MMI_theme->scrollbar_size,MMI_content_height-1);
	RedrawCategoryFunction = mmi_mms_redraw_play;
	mmi_mms_redraw_play();
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
void mmi_mms_redraw_play(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	gedit.start_height = 0;
	gedit.total_height = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_Tracer("enter mmi_mms_redraw_play");   
	MMS_HeadSlide(gpeditor_doc);

    	reset_left_softkey();
	reset_right_softkey();

	mms_stop_animation();
	mms_stop_music();

	mmi_change_title_string();
	if (gpeditor_doc->slide_cur->audiosize > 0){
		ChangeTitle(IMG_MMS_MUSIC_ADDED, (U8*)gedit.title);
	}
	else{
		ChangeTitle(IMG_MESSAGE_SIM_MMS_MENUENTRY, (U8*)gedit.title);
	}
	draw_title();

	/*开始播放*/
	gdi_layer_lock_frame_buffer();
	gdi_layer_push_clip();
	gdi_layer_push_text_clip();

	gdi_layer_set_clip(0, MMI_MMS_TITLE_HIGHT + 1, UI_device_width-1, 
		MMI_MMS_TITLE_HIGHT + MMI_content_height - 2);
	gdi_layer_set_text_clip(0, MMI_MMS_TITLE_HIGHT + 1, UI_device_width-1, 
		MMI_MMS_TITLE_HIGHT + MMI_content_height - 2);

	mms_view_message();

	gdi_layer_pop_text_clip();
	gdi_layer_pop_clip();

	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_base_layer( 0, 0, UI_device_width-1, UI_device_height-1);
	
	show_softkey_background();
	
	if (!mmsflag.gplay_state)
	{
		show_left_softkey();
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	}
	else
	{
		clear_left_softkey();
	}
	show_right_softkey();

	/*注册侧键*/
	SetKeyHandler(mmi_mms_play_previous_frame, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_next_frame, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_down_frame, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_up_frame, KEY_UP_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_down_frame, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_up_frame, KEY_VOL_UP, KEY_EVENT_DOWN);	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_stop_play_message, KEY_EVENT_UP);
	
	mms_Tracer("out  mmi_mms_redraw_play");   	
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_play
 *       Purpose: exit play when some thing come on
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_play(void)
{
	if(mmsflag.gplay_state)
	{
		mmi_mms_stop_play_message();
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_next_frame
 *       Purpose: show next frame when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_play_next_frame(void)
{
	if(!MMS_NextSlide(gpeditor_doc))
	{
		return ;
	}
	
	mms_stop_animation();
	mms_stop_music();
	
	gedit.start_height = 0;
	gedit.total_height = 0;

	mmi_change_title_string();

	gdi_layer_lock_frame_buffer();

	if (gpeditor_doc->slide_cur->audiosize > 0)
	{
		ChangeTitle(IMG_MMS_MUSIC_ADDED, (U8*)gedit.title);
	}
	else
	{
		ChangeTitle(IMG_MESSAGE_SIM_MMS_MENUENTRY, (U8*)gedit.title);
	}
	draw_title();

	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_base_layer( 0, 0, UI_device_width-1, UI_device_height-1);
	//play mms
	mms_play_music();
	mms_play_show_text_image();
	
	if (!mmsflag.gplay_state)
	{
		clear_left_softkey();
              ChangeLeftSoftkey(STR_MMS_PLAY, IMG_GLOBAL_OK);
	       SetLeftSoftkeyFunction(mmi_mms_redraw_play, KEY_EVENT_UP);

	        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetRightSoftkeyFunction(mmi_mms_stop_play_frame, KEY_EVENT_UP); 
	}
	else
	{
		if(gpeditor_doc->slide_cur->times>MMS_MAX_PLAY_TIME*1000)
		{
			pixtel_UI_start_timer((s32)MMS_MAX_PLAY_TIME*1000,mms_play_message_callback);
		}
		else
		{
			pixtel_UI_start_timer((s32)gpeditor_doc->slide_cur->times,mms_play_message_callback);
		}
		clear_left_softkey();
		SetRightSoftkeyFunction(mmi_mms_stop_play_message, KEY_EVENT_UP);
	}
	/*注册侧键*/
	SetKeyHandler(mmi_mms_play_previous_frame, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_next_frame, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_down_frame, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_up_frame, KEY_UP_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_down_frame, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_up_frame, KEY_VOL_UP, KEY_EVENT_DOWN);	
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_previous_frame
 *       Purpose: previous next frame when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_play_previous_frame(void)
{
	if(!MMS_PrevSlide(gpeditor_doc))
	{
		return ;
	}
	mms_stop_animation();
	mms_stop_music();
	gedit.start_height = 0;
	gedit.total_height = 0;

	mmi_change_title_string();

	gdi_layer_lock_frame_buffer();

	if (gpeditor_doc->slide_cur->audiosize > 0)
	{
		ChangeTitle(IMG_MMS_MUSIC_ADDED, (U8*)gedit.title);
	}
	else
	{
		ChangeTitle(IMG_MESSAGE_SIM_MMS_MENUENTRY, (U8*)gedit.title);
	}
	draw_title();


	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_base_layer( 0, 0, UI_device_width-1, UI_device_height-1);
	
	mms_play_music();
	mms_play_show_text_image();

	if (!mmsflag.gplay_state)
	{
		clear_left_softkey();
	
		ChangeLeftSoftkey(STR_MMS_PLAY, IMG_GLOBAL_OK);
		SetLeftSoftkeyFunction(mmi_mms_redraw_play, KEY_EVENT_UP);

		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetRightSoftkeyFunction(mmi_mms_stop_play_frame, KEY_EVENT_UP);
	}
	else
	{
		if(gpeditor_doc->slide_cur->times>MMS_MAX_PLAY_TIME*1000)
		{
			pixtel_UI_start_timer((s32)MMS_MAX_PLAY_TIME*1000,mms_play_message_callback);
		}
		else
		{
			pixtel_UI_start_timer((s32)gpeditor_doc->slide_cur->times,mms_play_message_callback);
		}
		clear_left_softkey();
		SetRightSoftkeyFunction(mmi_mms_stop_play_message, KEY_EVENT_UP);
	}
	/*注册侧键*/
	SetKeyHandler(mmi_mms_play_previous_frame, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_next_frame, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_down_frame, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_up_frame, KEY_UP_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_down_frame, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_up_frame, KEY_VOL_UP, KEY_EVENT_DOWN);	
	
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_up_frame
 *       Purpose: up  frame when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_play_up_frame(void)
{
	if (gedit.start_height >= 0)
	{
		return ;
	}
	gedit.start_height += MMI_LINE_HEIGHT;

	if (gedit.start_height > 0)
	{
		gedit.start_height = 0;
	}
	
	mms_play_show_text_image();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_edit_down_frame
 *       Purpose: down frame when edit mms message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_play_down_frame(void)
{
	if (gedit.total_height <= (MMI_content_height - 2))
	{
		return ;
	}
	if ((gedit.start_height + gedit.total_height + MMI_ORIGIN_Y) == (MMI_content_height + MMI_MMS_TITLE_HIGHT - 1))
	{
		return;
	}
	if ((gedit.start_height + gedit.total_height + MMI_ORIGIN_Y) < (MMI_content_height + MMI_MMS_TITLE_HIGHT - 1))
	{
		return;
	}
	gedit.start_height -= MMI_LINE_HEIGHT;
	mms_play_show_text_image();
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_stop_play_frame
 *       Purpose: stop playing audio and animation 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_stop_play_frame(void)
{
	mms_stop_animation();
	mms_stop_music();
	GoBackHistory();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_stop_play_message
 *       Purpose: stop playing message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_stop_play_message(void)
{
	mmsflag.gplay_state= FALSE;
	
	mms_play_message_callback();
	show_left_softkey();
	
	ChangeLeftSoftkey(STR_MMS_PLAY, IMG_GLOBAL_OK);
	EnableLeftSoftkey(STR_MMS_PLAY, IMG_GLOBAL_OK);
	SetLeftSoftkeyFunction(mmi_mms_redraw_play, KEY_EVENT_UP);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	
	/*注册侧键*/
	SetKeyHandler(mmi_mms_play_previous_frame, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_next_frame, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_down_frame, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_up_frame, KEY_UP_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_down_frame, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_play_up_frame, KEY_VOL_UP, KEY_EVENT_DOWN);	
	
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_send_options
 *       Purpose: entry send mms options screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_send_options(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer=NULL;
	U16 		numItems=0;
	U16 		nStrItemList[MAX_SUB_MENUS];
	U16 		itemIcons[MAX_SUB_MENUS];
	U16 		screenId = SCR_ID_MMS_SEND_OPTIONS;
	U8** 	pPopUpList=NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_send_options, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);	
	numItems = GetNumOfChild(MMS_SEND_OPTIONS_MENUID);
	GetSequenceStringIds(MMS_SEND_OPTIONS_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_SEND_OPTIONS_MENUID, itemIcons);

	SetMessagesCurrScrnID(screenId);
	SetParentHandler(MMS_SEND_OPTIONS_MENUID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	
	ShowCategory52Screen(STR_MMS_SEND_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **)pPopUpList, 0, 0,
						  guiBuffer);
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_before_draftbox_send_message
 *       Purpose: 草稿箱发送信息
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_before_draftbox_send_message(void)
{
	char *sub_uni = NULL;
	P_MESSAGELIST pMsg = mms_file_manager_get_current_message();
	
	if (mmsflag.gsend_recv) 
	{
		DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING),IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	if(pMsg->size>MMS_MAX_SIZE_OF_MESSAGE)
	{
		DisplayPopup((U8*)GetString(STR_MMS_SIZE_TOO_BIG), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;

	}
	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);
	sub_uni = Cms_mms_uni8_16(pMsg->subject);
	pfnUnicodeStrcpy((S8 *)gedit.sub_buf,sub_uni);
	mms_Free(sub_uni);
	sub_uni = NULL;
	mms_parse_message_file();
	cms_parse_sendto_address(pMsg,SENDTO_TO);
	cms_parse_sendto_address(pMsg,SENDTO_CC);
	cms_parse_sendto_address(pMsg,SENDTO_BCC);

	mmsflag.gsend_save=FALSE;
	mms_before_send_message();

}
/* ----------------------------------------------------------------------------
 * Function Name: mms_before_draftbox_send_and_save
 *       Purpose: 草稿箱发送信息
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_before_draftbox_send_and_save(void)
{
	char *sub_uni = NULL;
	P_MESSAGELIST pMsg = mms_file_manager_get_current_message();
	
	if (mmsflag.gsend_recv) 
	{
		DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING),IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	if(pMsg->size>MMS_MAX_SIZE_OF_MESSAGE)
	{
		DisplayPopup((U8*)GetString(STR_MMS_SIZE_TOO_BIG), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);
	sub_uni = Cms_mms_uni8_16(pMsg->subject);
	pfnUnicodeStrcpy((S8 *)gedit.sub_buf,sub_uni);
	mms_Free(sub_uni);
	sub_uni = NULL;
	mms_parse_message_file();
	cms_parse_sendto_address(pMsg,SENDTO_TO);
	cms_parse_sendto_address(pMsg,SENDTO_CC);
	cms_parse_sendto_address(pMsg,SENDTO_BCC);
	
	mmsflag.gsend_save=TRUE;
	mms_before_send_message();

}
/* ----------------------------------------------------------------------------
 * Function Name: mms_before_send_message
 *       Purpose: 判断发送条件是否符合
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_before_send_message(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	pSENDTO_LIST	plist = NULL,plist1=NULL,plist2=NULL;
	pBOOL			flag  = TRUE;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if (mmsflag.gsend_recv) 
	{	/*若正在收发*/
		DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING),
						IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	if(cms_judge_gpeditor_content()<1)
	{
		DisplayPopup((U8*)GetString(STR_CONTENT_NULL), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}	
	if (!gpeditor_doc->slide_root)
	{
		DisplayPopup((U8*)GetString(STR_CONTENT_NULL),IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE); 
		flag = FALSE;
		return;
 	}
	plist = pgsendtolist;
	plist1=pgsendcclist;
	plist2=pgsendbcclist;
	if ((!plist)&&(!plist1)&&(!plist2))
	{
		DisplayPopup((U8*)GetString(STR_SEND_LIST_NULL),IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		flag = FALSE;
		return;

	}
	else
	{
		if ((!plist->number)&&(!plist1->number)&&(!plist2->number))
		{
			DisplayPopup((U8*)GetString(STR_SEND_LIST_NULL),IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			flag = FALSE;
			return;

		}
	}
	
	{
		/*判断是否到达最大限制*/
		U16 count = 0;
		S32 msize = 0;
		mms_get_all_boxes_count_size(&count, &msize);
		if ((count + 1) > MAX_MESSAGE_COUNT)
		{
			DisplayPopup((U8*)GetString(STR_MMS_COUNT_REACHED_MAX), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			flag = FALSE;
		}
		else if ((gpeditor_doc->totalsize) > MAX_SIZE_ALL_MMS)
		{
			char		buffer[MMS_MAX_DETAILS_LENGTH] = {0};
			char		temp_buffer[20]={0};
			char		temp[20] = {0};

			pfnUnicodeStrcpy(buffer, (const char*)GetString(STR_MMS_QUOTA_EXCEEDED));
			sprintf(temp_buffer,"%d K\n",(int)(MAX_SIZE_ALL_MMS/1024));
			AnsiiToUnicodeString ((S8*)temp, temp_buffer);
			pfnUnicodeStrcat(buffer, (const char*)temp);
			DisplayPopup((U8*)buffer, IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			flag = FALSE;
		}
		if(gpeditor_doc->totalsize>MMS_MAX_SIZE_OF_MESSAGE)
		{
			DisplayPopup((U8*)GetString(STR_MMS_SIZE_TOO_BIG), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			flag = FALSE;
		}
	}
	mms_mmi_tracer("^_^flag===%d",(char*)flag);
	if (flag)
	{
		mmi_mms_entry_send_message();
		#if 1		
			mms_send_message();	
		#else
			mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_MESSAGE, NULL);
		#endif
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_send_message
 *       Purpose: entry send message screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_send_message(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16 screenId = SCR_ID_SENDING_RETRIEVING_MESSAGE;
	SuspendFlag = 0;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, mmi_mms_exit_send_retrieve_message,
					mmi_mms_entry_send_message, NULL);
	
	SetMessagesCurrScrnID(screenId);
	ShowCategory66Screen(STR_MMS_SENDING, IMG_MESSAGE_SIM_MMS_MENUENTRY,
						  NULL,NULL, STR_GLOBAL_CANCEL, IMG_GLOBAL_BACK,
							  NULL,IMG_MMS_SENDING, NULL);

	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mms_cancel_send_retrieve, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	SetKeyHandler(NULL,KEY_ENTER, KEY_EVENT_UP);
	
#if (UI_DOUBLE_BUFFER_SUPPORT)
	pixtel_UI_lock_double_buffer();
#endif
	
	if (!mmsflag.gsend_recv)
	{
		pixtel_UI_create_horizontal_progress_indicator(&show_process_bar,
						(UI_device_width-100)>>1,MMS_PROGRESS_INDICATOR_HEIGHT,100,10);
		mmsflag.gsend_recv = TRUE;
		progress_value=0;
	}
	else
	{
		mmi_mms_show_send_receive_status(progress_value);
	}
#if (UI_DOUBLE_BUFFER_SUPPORT)	
	pixtel_UI_unlock_double_buffer();
	pixtel_UI_BLT_double_buffer(0,0,UI_device_width-1,UI_device_height-1);
#endif

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_send_and_save_message
 *       Purpose: send and save message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_send_and_save_message(void)
{
	mmsflag.gsend_save = TRUE;
	mms_before_send_message();
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
void mmi_mms_show_send_receive_status(S32 value)
{
	if (SuspendFlag == 1)
	{
		mms_Tracer("SuspendFlag");
		return;
	}
	if(/*gauto_recmmssize==0&&*/mmsflag.gsend_recv==TRUE
	&&(SCR_ID_SENDING_RETRIEVING_MESSAGE==GetMessagesCurrScrnID()))
	{
/*		pixtel_UI_set_clip(0,MMS_PROGRESS_INDICATOR_HEIGHT,UI_device_width-1,
						MMI_MMS_TITLE_HIGHT+MMI_content_height - 1);
		pixtel_UI_fill_rectangle(0,MMS_PROGRESS_INDICATOR_HEIGHT,UI_device_width-1,
						MMI_MMS_TITLE_HIGHT+MMI_content_height - 1,pixtel_UI_color(255,255,255));
*/
		pixtel_UI_set_horizontal_progress_indicator_range(&show_process_bar,100);
		pixtel_UI_set_horizontal_progress_indicator_value(&show_process_bar,value);
		pixtel_UI_show_horizontal_progress_indicator( &show_process_bar);

		#if (UI_DOUBLE_BUFFER_SUPPORT)	
			pixtel_UI_BLT_double_buffer(0,0,UI_device_width-1,UI_device_height-1);
		#endif
	}
}
/*--------------------------------- In box  -----------------------------*/

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_inbox
 *       Purpose: entry inbox screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_inbox(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*  guiBuffer=NULL;
	S32	 hiliteitem = 0;
	U16 	 screenId = SCR_ID_MMS_INBOX;
	P_MESSAGELIST pMsg = NULL;
	int  i = 0;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef SUPPORT_SMSMMS_COMBINE
	if(!g_msg_cntx.msg_init)
	{
		GoBackHistory();
		return;
	}
#endif
	
	i = pgManager->receiveFolder->messageNumber;
	if (i <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_INBOX_IS_EMPTY), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}

	mms_file_manager_set_current_folder(MMS_RECEIVE_FOLDER);
	pMsg = (P_MESSAGELIST)mms_file_manager_get_current_message();
	if (pMsg&&(mmsflag.gsend_recv==FALSE))
	{
		mmsf_Remove(pMsg->fileName);
	}
	
	g_msg_cntx.msg_ind_in_idle=FALSE;
	mmsflag.gnewmsg_idle=FALSE;
	
	EntryNewScreen(screenId, NULL, mmi_mms_entry_inbox, NULL);
	
	if(!IsScreenPresent(SCR_ID_MMS_MAIN_MENU))
	{
		mmi_mms_entry_init_param();
	}
	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);    
	SetMessagesScrnIdToDelHistoryNodes(screenId);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(mmi_get_index);
	if (guiBuffer)
	{
		hiliteitem = ghiliindex;
	}
	/* Display the call history main screen */
	ShowCategory184Screen(STR_MMS_INBOX, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
							STR_GLOBAL_OK, IMG_GLOBAL_OK,
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							i, mmi_box_list_get_item, 
							mmi_box_list_get_hint, hiliteitem, guiBuffer);
#ifdef NO_LSK
	/* Register function with right softkey */
	//SetLeftSoftkeyFunction(mmi_mms_inbox_judge_msg_type, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_inbox_judge_msg_type, KEY_SEND1, KEY_EVENT_UP);//ghw222
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	
	SetRightSoftkeyFunction(mmi_mms_exit_boxes, KEY_EVENT_UP);
	//SetKeyHandler(mmi_mms_exit_boxes, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
//	SetKeyHandler(mmi_mms_inbox_judge_msg_type, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_inbox_judge_msg_type, KEY_LSK, KEY_EVENT_DOWN);//ghw222

#else
	/* Register function with right softkey */
	SetLeftSoftkeyFunction(mmi_mms_inbox_judge_msg_type, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_boxes, KEY_EVENT_UP);
	//SetKeyHandler(mmi_mms_exit_boxes, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
//	SetKeyHandler(mmi_mms_inbox_judge_msg_type, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_inbox_judge_msg_type, KEY_ENTER, KEY_EVENT_DOWN);

#endif	
}


/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_inbox_judge_msg_type
 *       Purpose: judge message type (message or push)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_inbox_judge_msg_type(void)
{
	U16 		index;
	U8 		type;
	P_MESSAGELIST pMsg = NULL;

	if(mmsflag.gsend_recv)/*正在接收*/
	{
		DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	mmi_mmsbox_find_message_by_index(ghiliindex);
	pMsg = (P_MESSAGELIST)mms_file_manager_get_current_message();
	if (!pMsg)
	{
		return ;
	}

#ifdef SUPPORT_SMSMMS_COMBINE
	if(pMsg->msgtype==MESSAGE_SMS)
	{
		mmi_frm_sms_get_sms_list_index(&type,&index,pMsg->SmsIndex);
		g_msg_cntx.currBoxIndex=index;
		g_msg_cntx.toDisplayMessageList=TO_DISPLAY_MESSAGE_LIST_INBOX;
		mmi_msg_get_msg_req(MMI_FRM_SMS_APP_INBOX, index);      
		return ;
	}
	else if(pMsg->msgtype==MESSAGE_WAP||
		pMsg->msgtype==MESSAGE_OTA_SET||
		pMsg->msgtype==MESSAGE_OTA_BOOKMARK)
	{		
		mms_Tracer("^_^ judge msg is wap push ");
		if (pMsg->url||pMsg->ota_murl)
		{
			if(mmsflag.gsend_recv)/*正在接收*/
			{
				DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			}
			else
			{
				if (pMsg->state == 'U')
				{
					mms_Tracer("read wap push");
					mms_file_manager_modify_current_message_state(MMS_MSG_STATE_READ);
					mmi_update_mms_idel_icon();
				}
				mmi_mms_view_wap_push_detail();
			}	
		}
		return ;
	}
#endif

	if(mmsflag.gnewmsg_idle==TRUE)
	{
		if(strcmp(gNewind_fname,pMsg->fileName)==0)
		{
			mmsflag.gnewmsg_idle=FALSE;
		}
	}
	
	if (pMsg->url)
	{
		if(mmsflag.gsend_recv)/*正在接收*/
		{
			DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		}
		else
		{
			if (pMsg->state == 'U')
			{
				mms_Tracer("read push");
				mms_file_manager_modify_current_message_state(MMS_MSG_STATE_READ);
				mmi_update_mms_idel_icon();
			}
			mmi_mms_enter_inbox_push_options();
		}	
	}
	else
	{
		/*
		if (pMsg->state == 'N')
		{
			mms_file_manager_modify_current_message_state(MMS_MSG_STATE_READ);
			mmi_update_mms_idel_icon();
		}
		*/
		mmi_mms_enter_inbox_message_options();
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_enter_inbox_push_options
 *       Purpose: enter inbox options
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_enter_inbox_push_options(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer=NULL;
	U16 		numItems=0;
	U16 		nStrItemList[MAX_SUB_MENUS];
	U16 		itemIcons[MAX_SUB_MENUS];
	U16 		screenId=SCR_ID_MMS_INBOX_OPTIONS2;
	U8* 		popUpList[MAX_SUB_MENUS];
	U32 		maskingByte=-1;
	U8** 	pPopUpList=NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_Tracer("mmi_mms_enter_inbox_push_options in ");
	EntryNewScreen(screenId,NULL,
				mmi_mms_enter_inbox_push_options, NULL);

	guiBuffer = GetCurrGuiBuffer(screenId);		
	numItems = GetNumOfChild(MMS_INBOX_OPTIONS2_MENUID);
	GetSequenceStringIds(MMS_INBOX_OPTIONS2_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_INBOX_OPTIONS2_MENUID, itemIcons);
	
	MaskStringItems(popUpList,(U8)numItems,maskingByte);
	MaskItems(itemIcons,(U8)numItems,maskingByte);
	MaskHiliteItems(MMS_INBOX_OPTIONS2_MENUID, maskingByte);
	numItems=MaskItems(nStrItemList,(U8)numItems,maskingByte);
	
	SetMessagesCurrScrnID(screenId);
	SetParentHandler(MMS_INBOX_OPTIONS2_MENUID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	
	ShowCategory52Screen(STR_MMS_INBOX_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer );
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_box_options, KEY_EVENT_UP);	
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_enter_inbox_message_options
 *       Purpose: enter inbox options
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_enter_inbox_message_options(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer=NULL;
	U16 		numItems=0;
	U16 		nStrItemList[MAX_SUB_MENUS];
	U16 		itemIcons[MAX_SUB_MENUS];
	U16 		screenId=SCR_ID_MMS_INBOX_OPTIONS1;
	U8* 		popUpList[MAX_SUB_MENUS];
	U32 		maskingByte=-1;
	U8** 	pPopUpList=NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_enter_inbox_message_options, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);
	numItems = GetNumOfChild(MMS_INBOX_OPTIONS1_MENUID);
	GetSequenceStringIds(MMS_INBOX_OPTIONS1_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_INBOX_OPTIONS1_MENUID, itemIcons);
	
	MaskStringItems(popUpList,(U8)numItems,maskingByte);	
	MaskItems(itemIcons,(U8)numItems,maskingByte);
	MaskHiliteItems(MMS_INBOX_OPTIONS1_MENUID, maskingByte);
	numItems=MaskItems(nStrItemList,(U8)numItems,maskingByte);
	
	SetMessagesCurrScrnID(screenId);
	SetParentHandler(MMS_INBOX_OPTIONS1_MENUID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	ShowCategory52Screen(STR_MMS_INBOX_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer );
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_box_options, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_reply
 *       Purpose: reply the message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_reply(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGELIST 	pMsg = NULL;
	pSENDTO_LIST  	plist = NULL;
    	char          		subject[128] = {0};
	char				colon[128] = {0};
	char*		  	temp = NULL;
	char*			colon_temp = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmsflag.gnew_message=FALSE;
	gbox_operation = BOX_OPTIONS_REPLY;
	pMsg = mms_file_manager_get_current_message();

	if (pMsg->state == 'N'&&mms_file_manager_get_current_folder()==MMS_RECEIVE_FOLDER)
	{
		mms_file_manager_modify_current_message_state(MMS_MSG_STATE_READ);
		mmi_update_mms_idel_icon();
	}
	
	pCurFwrReMsg=pMsg;
	cms_empty_sendto_list();
	pgsendtolist=NULL;
	pgsendcclist=NULL;
	pgsendbcclist=NULL;

	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);

	pfnUnicodeStrcpy((S8*)gedit.sub_buf, GetString(STR_MMS_REPLY));
	strcpy((char*)colon, ":");
	colon_temp = Cms_mms_uni8_16_2Sub(colon);
	pfnUnicodeStrcat((S8*)gedit.sub_buf, colon_temp);
	mms_Free(colon_temp);
	colon_temp = NULL;
	if(pMsg->subject)
	{
		strcpy((char*)subject, pMsg->subject);
		temp = Cms_mms_uni8_16_2Sub(subject);
		pfnUnicodeStrcat((S8*)gedit.sub_buf, temp);
		mms_Free(temp);
		temp = NULL;
	}
	else
	{
		mms_mmi_tracer("********RE**********","");
	}
	/*添加回复人*/
	plist = (pSENDTO_LIST)mms_Malloc(sizeof(SENDTO_LIST));	
	if (!plist)
	{
		return;
	}
	memset(plist, 0, sizeof(SENDTO_LIST));

	plist->number = (S8*)mms_Malloc(MMS_MAX_INPUT_SEND_TO_SIZE);
	
	if (!plist->number)
	{
		mms_Free(plist);
		plist = NULL;
		return;
	}
	memset(plist->number, 0, MMS_MAX_INPUT_SEND_TO_SIZE);
	strcpy(plist->number, pMsg->to_address);

#ifdef SUPPORT_SMSMMS_COMBINE
	if(pMsg->msgtype==MESSAGE_SMS)
	{
		strcpy(plist->number, (char*)mmi_frm_sms_msg_box[pMsg->SmsIndex].number);   
	}
#endif

	pgsendtolist = plist;
	pgsendtolist->next = NULL;
	/*添加回复人(over)*/
	
	MMSDelAllSlide(gpeditor_doc);
	gpeditor_doc->totalsize = 0;
	mmi_mms_entry_edit_content();
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_forward
 *       Purpose: forward message 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_forward(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGELIST 	pMsg = NULL;
	char				subject[128] = {0};
	char				colon[128] = {0};
	char*			temp = NULL;
	char*			colon_temp = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmsflag.gnew_message=FALSE;//20060118 cocoma xu add for bug31617
	pMsg = mms_file_manager_get_current_message();
	pCurFwrReMsg=pMsg;
	
	if (pMsg->state == 'N'&&mms_file_manager_get_current_folder()==MMS_RECEIVE_FOLDER)
	{
		mms_file_manager_modify_current_message_state(MMS_MSG_STATE_READ);
		mmi_update_mms_idel_icon();
	}
	if (pMsg->size > MMS_MAX_SIZE_OF_MESSAGE)
	{
		if(gconfig.sendsize==MMS_SETTINGS_30K)
		{
			DisplayPopup((U8*)GetString(STR_MMS_MAX_30K_FORWARD), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		}
		else if(gconfig.sendsize==MMS_SETTINGS_50K)
		{
			DisplayPopup((U8*)GetString(STR_MMS_MAX_50K_FORWARD), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		}
		else if(gconfig.sendsize==MMS_SETTINGS_70K)
		{
			DisplayPopup((U8*)GetString(STR_MMS_MAX_70K_FORWARD), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		}
		else if(gconfig.sendsize==MMS_SETTINGS_100K)
		{
			DisplayPopup((U8*)GetString(STR_MMS_MAX_100K_FORWARD), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		}
		return ;
	}
	MMSDelAllSlide(gpeditor_doc);
	gpeditor_doc->totalsize = 0;
	gbox_operation = BOX_OPTIONS_FORWARD;

	memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);

	pfnUnicodeStrcpy((S8*)gedit.sub_buf, GetString(STR_MMS_FORWARD));
	/* 冒号*/
	strcpy((char*)colon, ":");
	colon_temp = Cms_mms_uni8_16_2Sub(colon);
	pfnUnicodeStrcat((S8*)gedit.sub_buf, colon_temp);
	mms_Free(colon_temp);
	colon_temp = NULL;
	/* 主题*/
	if(pMsg->subject!=NULL)
	{
		strcpy((char*)subject, pMsg->subject);
		temp = Cms_mms_uni8_16_2Sub(subject);
		pfnUnicodeStrcat((S8*)gedit.sub_buf, temp);
		mms_Free(temp);
		temp = NULL;
	}
	else
	{
	}
	mms_parse_message_file();

	cms_empty_sendto_list();
	pgsendtolist=NULL;
	pgsendcclist=NULL;
	pgsendbcclist=NULL;
	
	if (MMSGetSlideCount(gpeditor_doc) > 20)
	{
		MMSDelAllSlide(gpeditor_doc);
		gpeditor_doc->totalsize = 0;
		memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);
		mmsf_Remove(pMsg->fileName);
		DisplayPopup((U8*)GetString(STR_MMS_MORE_FRAME_FORWARD), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);		
		return ;
	}

	mmi_mms_entry_edit_content();
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_inbox_save_image
 *       Purpose: save image of mms message in inbox
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_inbox_save_image(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* guiBuffer=NULL;
	S32 hiliteitem = 0;
	U16 screenId = SCR_ID_MMS_SAVE_IMAGE_LIST;	
	int i = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_parse_message_file();
	mms_get_image_frame_count((U16 *)(&i));
	if (i <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_INBOX_NO_IMAGE), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	if (gedit.media_buf)
	{
		mms_Free(gedit.media_buf);
		gedit.media_buf = NULL;
		gedit.media_len = 0;
		gedit.media_type = 0;
	}
	EntryNewScreen(screenId, NULL, 
				mmi_mms_entry_inbox_save_image, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);            
	SetMessagesScrnIdToDelHistoryNodes(screenId);
	
	if ((guiBuffer!=NULL))
	{
		hiliteitem = (ghiliindex1 < i) ? ghiliindex1 : 0;
	}
	RegisterHighlightHandler(mms_get_save_index);
	ShowCategory184Screen(STR_IMAGE_SAVE, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
							STR_GLOBAL_VIEW, IMG_GLOBAL_OK,
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							i, mmi_image_list_get_item, 
							mmi_image_list_get_hint, hiliteitem, guiBuffer);
	SetLeftSoftkeyFunction(mmi_mms_entry_view_save_image, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_save_medialist, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_inbox_save_accessory
 *       Purpose: save accessory of mms message in inbox
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_inbox_save_accessory(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* guiBuffer=NULL;
	S32 hiliteitem = 0;
	U16 screenId = SCR_ID_MMS_SAVE_ACCESSORY_LIST;	
	int i = 0;

	mms_Tracer((char *) "in mmi_mms_entry_inbox_save_accessory");
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_parse_message_file();
	mms_get_accessory_frame_count((U16 *)(&i));

	mms_mmi_tracer("i = %d", (char*)i);
	   
	if (i <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_INBOX_NO_ACCESSORY), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	if (gedit.media_buf)
	{
		mms_Free(gedit.media_buf);
		gedit.media_buf = NULL;
		gedit.media_len = 0;
		gedit.media_type = 0;
	}
	EntryNewScreen(screenId, NULL, 
				mmi_mms_entry_inbox_save_accessory, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);            
	SetMessagesScrnIdToDelHistoryNodes(screenId);
	
	if ((guiBuffer!=NULL))
	{
		hiliteitem = (ghiliindex1 < i) ? ghiliindex1 : 0;
	}

	mms_Tracer((char *) "111111");
	
	RegisterHighlightHandler(mms_get_save_index);
	ShowCategory184Screen(STR_ACCESSORY_SAVE, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
							STR_GLOBAL_SAVE, IMG_GLOBAL_OK,
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							i, mmi_accessory_list_get_item, 
							mmi_accessory_list_get_hint, hiliteitem, guiBuffer);
	//SetLeftSoftkeyFunction(mmi_mms_entry_view_save_accessory, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(mmi_mms_accessory_filename_input, KEY_EVENT_UP);	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_save_medialist, KEY_EVENT_UP);

	mms_Tracer((char *) "222222");

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
void mmi_mms_entry_view_save_accessory(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 		i = 0;
	U8* 		guiBuffer=NULL;
	U32 		len = 0,size=0;
	U32 		x = 0;
	U32 		y = 0;
	U16 		screenId=SCR_ID_MMS_VIEW_SAVE_ACCESSORY;
	pMMS_Content 	content = NULL;
	pMMS_Slide 		slide = NULL;
	FILE_HANDLE 		fd = NULL;


	mms_Tracer((char *) "in mmi_mms_entry_view_save_accessory");
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	slide = gpeditor_doc->slide_root;
	
	while (i <= ghiliindex1 && slide)
	{
		mms_Tracer((char *) "in while");
		mms_mmi_tracer("not if accessory_flag = %d", (char*)slide->accessory_flag);
		if (slide->accessory_flag == 1)   //temp ********************************************************
		{
			mms_mmi_tracer("in if accessory_flag = %d", (char*)slide->accessory_flag);
			content = slide->content_root;
			while (content)
			{
				if (content->type == MMS_TYPE_VCF ||
					content->type == MMS_TYPE_VCS
					)
				{
					mms_Tracer((char *) "in MMS_TYPE_VCF or MMS_TYPE_VCS");
					break;
				}
				content = content->next;
			}
			i++;
		}
		slide = slide->next;
	}	
	mms_Tracer((char *) "test");
	mms_mmi_tracer("content i = %d", (char*)i);
	if (!content)
	{
		DisplayPopup((U8*)GetString(STR_GLOBAL_UNSUPPORTED_FORMAT), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
#if 0
	/*get default vCard filename*/
	cms_getmedia_fllename((char*)content->filename);
	
	mms_mmi_tracer("filename = %s", (char*)content->filename);

	fd = mmsf_Open(content->filename,"r");
	
	gedit.media_type = content->type;
	gedit.media_len = content->contentsize;

	mms_mmi_tracer("ss  type = %s", (char*)content->type);
	mms_mmi_tracer("dd  type = %d", (char*)content->type);
#endif
	EntryNewScreen(screenId, NULL,
				mmi_mms_entry_view_save_accessory, NULL);
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
	
	clear_screen();
	
	ShowCategory221Screen(STR_MMS_INBOX_OPTIONS_SAVE_ACCESSORY, IMG_MESSAGE_SIM_MMS_MENUENTRY,
							STR_MMS_SEND_OPTIONS_SAVE, IMG_GLOBAL_OK, 
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							GDI_COLOR_WHITE, NULL);
	
	//SetLeftSoftkeyFunction(mmi_mms_accessory_filename_input,KEY_EVENT_UP);
	SetLeftSoftkeyFunction(mms_save_accessory_handler,KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_save_media_filename_input,KEY_EVENT_UP);

/*	
	gdi_layer_lock_frame_buffer();
    	gdi_layer_push_clip();

	gdi_layer_set_clip(0, MMI_MMS_TITLE_HIGHT + 1, UI_device_width-1, 
		MMI_MMS_TITLE_HIGHT + MMI_content_height - 2);

	mms_draw_picture_for_play(gedit.media_buf, &x, &y, len, content->type);

	gdi_layer_pop_clip();
	gdi_layer_unlock_frame_buffer();
	
	RedrawCategoryFunction = mmi_mms_redraw_view_image;    
	mmi_mms_redraw_view_image();
*/

}
/*
* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_view_save_image(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 		i = 0;
	U8* 		guiBuffer=NULL;
	U32 		len = 0,size=0;
	U32 		x = 0;
	U32 		y = 0;
	U16 		screenId=SCR_ID_MMS_VIEW_SAVE_IMAGE;
	pMMS_Content 	content = NULL;
	pMMS_Slide 		slide = NULL;
	FILE_HANDLE 		fd = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	slide = gpeditor_doc->slide_root;
	
	while (i <= ghiliindex1 && slide)
	{
		if (slide->image_flag == 1)
		{
			content = slide->content_root;
			while (content)
			{
				if (content->type == MMS_TYPE_JPEG ||
					content->type == MMS_TYPE_WBMP ||
					content->type == MMS_TYPE_PNG ||
					content->type == MMS_TYPE_GIF ||
					content->type == MMS_TYPE_BMP1)
				{
					break;
				}
				content = content->next;
			}
			i++;
		}
		slide = slide->next;
	}	
	if (!content)
	{
		DisplayPopup((U8*)GetString(STR_GLOBAL_UNSUPPORTED_FORMAT), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	/*get default image filename*/
	cms_getmedia_fllename((char*)content->filename);
	fd = mmsf_Open(content->filename,"r");
	
	if (content->type==MMS_TYPE_GIF)
	{
		if (fd)
		{
		size = content->contentsize;
		len = content->contentsize+8;

		gedit.media_buf = (U8*)mms_Malloc(len);
		memset(gedit.media_buf, 0, len);
		{
			gedit.media_buf[0]=IMAGE_TYPE_GIF;
			gedit.media_buf[1]=NULL;
			gedit.media_buf[5] = (U8) ((size >> 24) & 0x000000ff);
			gedit.media_buf[4] = (U8) ((size >> 16) & 0x000000ff);
			gedit.media_buf[3] = (U8) ((size >> 8) & 0x000000ff);
			gedit.media_buf[2] = (U8) ( size& 0x000000ff);
			gedit.media_buf[6]=NULL;
			gedit.media_buf[7]=NULL;
		}		
		if (gedit.media_buf)
		{
			mmsf_Read((char*)gedit.media_buf+8, 1, len, fd);			
		}
		mmsf_Close(fd);
		}
		else
		{
		}
	}
	else
	{
		if (fd)
		{
			len = content->contentsize;
			gedit.media_buf = (U8*)mms_Malloc(content->contentsize);
			memset(gedit.media_buf, 0, content->contentsize);
			
			if (gedit.media_buf)
			{
				mmsf_Read((char*)gedit.media_buf, 1, len, fd);			
			}
			mmsf_Close(fd);
		}
		else
		{
		}
   	}
	
	gedit.media_type = content->type;
	gedit.media_len = content->contentsize;

	EntryNewScreen(screenId, NULL,
				mmi_mms_entry_view_save_image, NULL);
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
	
	clear_screen();
	
	ShowCategory221Screen(STR_MMS_INBOX_OPTIONS_SAVE_IMAGE, IMG_MESSAGE_SIM_MMS_MENUENTRY,
							STR_MMS_SEND_OPTIONS_SAVE, IMG_GLOBAL_OK, 
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							GDI_COLOR_WHITE, NULL);
	
	SetLeftSoftkeyFunction(mmi_mms_image_filename_input,KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_save_media_filename_input,KEY_EVENT_UP);
	
	gdi_layer_lock_frame_buffer();
    	gdi_layer_push_clip();

	gdi_layer_set_clip(0, MMI_MMS_TITLE_HIGHT + 1, UI_device_width-1, 
		MMI_MMS_TITLE_HIGHT + MMI_content_height - 2);

	mms_draw_picture_for_play(gedit.media_buf, &x, &y, len, content->type);

	gdi_layer_pop_clip();
	gdi_layer_unlock_frame_buffer();
	
	RedrawCategoryFunction = mmi_mms_redraw_view_image;    
	mmi_mms_redraw_view_image();
}


/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_redraw_view_image
 *       Purpose: 加入图片后redraw
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_redraw_view_image(void)
{
	gdi_layer_lock_frame_buffer();

	draw_title();	
	show_softkey_background();	
	show_left_softkey();	
	show_right_softkey();

	gdi_layer_unlock_frame_buffer();	
	gdi_layer_blt_base_layer( 0, 0, UI_device_width-1, UI_device_height-1);

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
void mmi_mms_image_filename_input(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer = NULL;
	U16 		screenId = SCR_ID_MMS_INPUT_IMAGE_NAME;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_stop_animation();
	EntryNewScreen(screenId, NULL,
				mmi_mms_image_filename_input, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);

	ginput_screen = INPUT_OPTION_SAVE_IMAGE;
	
	RegisterInputBoxEmptyFunction(mms_input_box_set_lsk);
       	RegisterInputBoxNotEmptyFunction (mms_input_box_set_lsk);
	ShowCategory5Screen(STR_MMS_INBOX_OPTIONS_SAVE_IMAGE,
						IMG_MESSAGE_SIM_MMS_MENUENTRY,STR_GLOBAL_OK,
						NULL,STR_GLOBAL_BACK,NULL,
						INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
						gedit.save_media_fname, MMS_MAX_SAVE_MEDIA_FILENAME_INPUT, 
						guiBuffer);
	SetLeftSoftkeyFunction(/*mmi_mms_entry_input_options*/mmi_confirm_input_text_handler, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetCategory5RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_inbox_save_music
 *       Purpose: save music of mms message in inbox
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_inbox_save_music(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer=NULL;
	S32 		hiliteitem = 0;
	U16 		screenId = SCR_ID_MMS_SAVE_MUSIC_LIST;	
	int 		i = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_parse_message_file();
	mms_get_music_frame_count((U16*)(&i));
	
	if (i <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_INBOX_NO_MUSIC), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	mms_Tracer((char *) "mmi_mms_entry_inbox_save_music");

	if (gedit.media_buf)
	{
		mms_Tracer((char *) "save music list buf");
		StopAudioStream();
		mms_Free(gedit.media_buf);
		gedit.media_buf = NULL;
		gedit.media_len = 0;
		gedit.media_type = 0;
	}
	EntryNewScreen(screenId, NULL, 
				mmi_mms_entry_inbox_save_music, NULL);	
	
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);            
	SetMessagesScrnIdToDelHistoryNodes(screenId);

	if ((guiBuffer!=NULL))
	{
		hiliteitem = (ghiliindex1 < i) ? ghiliindex1 : 0;
	}
	RegisterHighlightHandler(mms_get_save_index);

	ShowCategory184Screen(STR_MUSIC_SAVE, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
							STR_GLOBAL_OK, IMG_GLOBAL_OK,
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							i, mmi_music_list_get_item, 
							mmi_music_list_get_hint, hiliteitem, guiBuffer);
	
	SetLeftSoftkeyFunction(mmi_mms_play_save_music, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_save_medialist, KEY_EVENT_UP);
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
void mmi_mms_play_save_music(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 				i = 0;
	U8* 				guiBuffer=NULL;
	FILE_HANDLE 		fd = NULL;
	pMMS_Slide 		slide = NULL, slide1 = NULL;
	U16 				screenId = SCR_ID_MMS_PLAY_SAVE_MUSIC;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	slide1 = gpeditor_doc->slide_root;
	while (slide1 && i <= ghiliindex1)
	{
		if (slide1->audiosize > 0)
		{
			i++;
			slide = slide1;
		}
		slide1 = slide1->next;
	}
	/*get default image filename*/
	cms_getmedia_fllename((char*)slide->audiofile);
	fd = mmsf_Open(slide->audiofile, "r");

	if (fd)
	{
		gedit.media_buf = (U8*)mms_Malloc(slide->audiosize);
		memset(gedit.media_buf, 0, slide->audiosize);

		if (gedit.media_buf)
		{
			mmsf_Read((S8*)gedit.media_buf, 1, slide->audiosize, fd);
		}
		mmsf_Close(fd);
	}
	gedit.media_type = slide->audio_type;
	gedit.media_len = slide->audiosize;
	if(gedit.media_type == MMS_TYPE_WAV ||gedit.media_type == MMS_TYPE_IMY||gedit.media_type == MMS_TYPE_MIDI||gedit.media_type == MMS_TYPE_AMR)
	{
		mms_Tracer((char*)"Audio Type OK");
	}
	else
	{
		DisplayPopup((U8*)GetString(STR_GLOBAL_UNSUPPORTED_FORMAT), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return;
	}
	EntryNewScreen(screenId, NULL,
				mmi_mms_play_save_music, NULL);
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
	
	ShowCategory66Screen(STR_MMS_INBOX_OPTIONS_SAVE_MUSIC, IMG_MMS_MUSIC_ADDED,
						  STR_MMS_SEND_OPTIONS_SAVE, IMG_GLOBAL_OK, 
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  NULL, IMG_MMS_PLAY_SAVE_MUSIC, guiBuffer);
	SetLeftSoftkeyFunction(mmi_mms_music_filename_input,KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_save_media_filename_input, KEY_EVENT_UP);

#if (UI_DOUBLE_BUFFER_SUPPORT)	
	pixtel_UI_lock_double_buffer();
#endif
	switch(gedit.media_type)
	{
	case MMS_TYPE_WAV:
		PlayAudioWavStream(gedit.media_buf, slide->audiosize, DEVICE_AUDIO_PLAY_INFINITE);
		break;
	case MMS_TYPE_IMY:
		PlayAudioStream(gedit.media_buf, slide->audiosize,MEDIA_IMELODY,DEVICE_AUDIO_PLAY_INFINITE);
		break;
	case MMS_TYPE_MIDI:
		PlayAudioMidiStream(gedit.media_buf, slide->audiosize, DEVICE_AUDIO_PLAY_INFINITE);
		break;
	case MMS_TYPE_AMR:
		PlayAudioStream(gedit.media_buf, slide->audiosize, MEDIA_AMR,DEVICE_AUDIO_PLAY_INFINITE);
		break;		
	default:
		break;
	}
#if (UI_DOUBLE_BUFFER_SUPPORT)	
	pixtel_UI_unlock_double_buffer();
	pixtel_UI_BLT_double_buffer(0,0,UI_device_width-1,UI_device_height-1);
#endif
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
void mmi_mms_music_filename_input(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer = NULL;
	U16 		screenId = SCR_ID_MMS_INPUT_MUSIC_NAME;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	switch(gedit.media_type)
	{
	case MMS_TYPE_WAV:
		StopAudioWavStream();
		break;
	case MMS_TYPE_IMY:
		StopAudioStream();
		break;
	case MMS_TYPE_MIDI:
		StopAudioMidiStream();
		break;
	case MMS_TYPE_AMR:	
		StopAudioStream();
		break;		
	default:	
		return;
	}
	EntryNewScreen(screenId, NULL,
				mmi_mms_music_filename_input, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);
	
	ginput_screen = INPUT_OPTION_SAVE_MUSIC;
	RegisterInputBoxEmptyFunction(mms_input_box_set_lsk);
       	RegisterInputBoxNotEmptyFunction (mms_input_box_set_lsk);
	ShowCategory5Screen(STR_MMS_INBOX_OPTIONS_SAVE_MUSIC,
						IMG_MESSAGE_SIM_MMS_MENUENTRY,STR_GLOBAL_OK,
						NULL,STR_GLOBAL_BACK,NULL,
						INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
						gedit.save_media_fname, 
						MMS_MAX_SAVE_MEDIA_FILENAME_INPUT, 
						guiBuffer);
	
	SetLeftSoftkeyFunction(/*mmi_mms_entry_input_options*/mmi_confirm_input_text_handler, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetCategory5RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
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
void mmi_mms_accessory_filename_input(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer = NULL;
	U16 		screenId = SCR_ID_MMS_INPUT_ACCESSORY_NAME;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	mms_Tracer((char *) "in  mmi_mms_accessory_filename_input");

	
/*
	switch(gedit.media_type)
	{
	case MMS_TYPE_WAV:
		StopAudioWavStream();
		break;
	case MMS_TYPE_IMY:
		StopAudioStream();
		break;
	case MMS_TYPE_MIDI:
		StopAudioMidiStream();
		break;
	case MMS_TYPE_AMR:	
		StopAudioStream();
		break;		
	default:	
		return;
	}
*/	
	EntryNewScreen(screenId, NULL,
				mmi_mms_accessory_filename_input, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);
	
	ginput_screen = INPUT_OPTION_SAVE_ACCESSORY;
	ShowCategory5Screen(STR_MMS_INBOX_OPTIONS_SAVE_ACCESSORY,
						IMG_MESSAGE_SIM_MMS_MENUENTRY,STR_GLOBAL_OK,
						NULL,STR_GLOBAL_BACK,NULL,
						INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
						gedit.save_media_fname, 
						MMS_MAX_SAVE_MEDIA_FILENAME_INPUT, 
						guiBuffer);
	
	SetLeftSoftkeyFunction(mmi_mms_entry_input_options, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetCategory5RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
}
/*
* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_inbox_get_phone_number_list
 *       Purpose: save phone number of the mms message in inbox
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_inbox_get_phone_number_list(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	char* 		str = NULL;
	U8* 			guiBuffer = NULL;
	U16 			itemIcons[MAX_USE_NUMBERS];
	U8*			nStrItemList[MAX_USE_NUMBERS];
	U16			numbersCount=0,count=0;
	U16 			screenId = SCR_ID_MMS_GET_PHONE_NUMBER;
	P_MESSAGELIST pMsg = NULL;


	pMMS_Content 	content = NULL;
	pMMS_Slide 		slide1=NULL;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
	memset(MmsDialnumber, 0, sizeof(MmsDialnumber));
	pMsg = mms_file_manager_get_current_message();

	str = Cms_mms_uni8_16(pMsg->to_address);
	pfnUnicodeStrcpy((char*)MmsDialnumber[0] ,(const char*)str);
	mms_Free(str);
	str = NULL;
	
	nStrItemList[0]=MmsDialnumber[0];	
	itemIcons[0] = IMG_GLOBAL_L1;	
	numbersCount=1;

	mms_parse_message_file();
	slide1 = gpeditor_doc->slide_root;
	while(slide1)
	{
			mms_Tracer((char*)"slide1||numbersCount<6");
			if(numbersCount>=MAX_USE_NUMBERS)
			{
				break;
			}
			if (slide1->text_flag)
			{
				U32 		len = 0;
				U8* 		textstr = NULL;
				S8**	numberbuf=NULL;
				FILE_HANDLE 		fd = 0;
				//changed by Jun.Yang 060823
				//content = gpeditor_doc->slide_cur->content_root;
				content = slide1->content_root;
				for(;content;content = content->next)
				{
					fd = mmsf_Open(content->filename,"r");
					mms_Tracer((char*)"if (slide1->text_flag)");

					if (fd)
					{	
						mmsf_Read((char *)(&len),1,sizeof(unsigned short),fd);
						textstr = (U8*)mms_Malloc(len);
						if (textstr == NULL)
						{
							mms_Tracer((char*)"error::textstr=NULL");
							mmsf_Close(fd);
							break;
						}
						memset(textstr,0,len);
						mmsf_Read((char *)textstr,1,len,fd);
						mmsf_Close(fd);
						mms_Tracer((char*)"read close");
						
						numberbuf=mmi_msg_mms_get_numbers_from_text((U8*)textstr,len,&count);
						mms_mmi_tracer("count=%d", (char*)count);
						mms_mmi_tracer("str_len=%d", (char*)len);
						if(numberbuf)
						{
							int 		j=0;
							for(;j<count;j++)
							{
								mms_Tracer((char*)"for(;j<numbersCount;j++)");
								if(numbersCount<MAX_USE_NUMBERS)
								{
									mms_mmi_tracer("numbersCount=%d",numbersCount);
									pfnUnicodeStrcpy((char*)MmsDialnumber[numbersCount] ,(S8 *)numberbuf[j]);
									nStrItemList[numbersCount]=MmsDialnumber[numbersCount];	
									itemIcons[numbersCount] = IMG_GLOBAL_L1+numbersCount;	
									numbersCount+=1;
								}
							}
						}
						mms_Free(textstr);
						textstr = NULL;
						numberbuf=NULL;
						mms_Tracer((char*)"end of get nuber");
					}
				}
			}
				
		slide1 = slide1->next;
	}

	EntryNewScreen(screenId, NULL,
				mmi_mms_entry_inbox_get_phone_number_list, NULL);
	
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);
	RegisterHighlightHandler(mmi_get_index);
	ShowCategory53Screen(STR_USE_NUMBER_CAPTION, IMG_SMS_ENTRY_SCRN_CAPTION, 
						STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE,
						STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						numbersCount, (U8**)nStrItemList, (U16 *)itemIcons,
						NULL , 0, 0, guiBuffer );
	SetLeftSoftkeyFunction(mmi_mms_entry_use_number_option, KEY_EVENT_UP);
//	SetKeyHandler(mmi_mms_entry_use_number_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_dial_use_number, KEY_SEND, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_use_number_option
 *       Purpose: 保存电话号码选 项
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void  mmi_mms_entry_use_number_option()
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 guiBuffer=NULL;		/* Buffer holding history data */
	U16	 numItems=0;		/* Stores no of children in the submenu*/
	U16	 nStrItemList[MAX_SUB_MENUS];	/* Stores the strings id of submenus returned */
	U16	 itemIcons[MAX_SUB_MENUS];		/* Stores the icon id of submenus returned */
	U16	 screenId=SCR_ID_MMS_USE_NUMBER_OPTION;
	U8** pPopUpList=NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_use_number_option, NULL);

	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);

	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(MMS_INBOX_OPTIONS_GET_DETAILS_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(MMS_INBOX_OPTIONS_GET_DETAILS_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_INBOX_OPTIONS_GET_DETAILS_MENUID, itemIcons);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	SetParentHandler(MMS_INBOX_OPTIONS_GET_DETAILS_MENUID);

	RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	/* Display the call history main screen */
	ShowCategory52Screen(STR_GLOBAL_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  2, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0, guiBuffer );
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_dial_use_number
 *       Purpose: Dial the number
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void  mmi_mms_dial_use_number()
{
	mms_Tracer("mmi_mms_dial_use_number");
	if (pfnUnicodeStrlen((char*)MmsDialnumber[ghiliindex]))
		MakeCall((char*)MmsDialnumber[ghiliindex]);
	else
		DisplayPopup ((PU8)GetString (STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_save_phone_number_confirm
 *       Purpose: 保存电话号码
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_save_phone_number_confirm(void)
{
	mms_Tracer("mmi_mms_dial_use_number");
	SaveNumberFromIdleScrn((PS8)MmsDialnumber[ghiliindex], 0);
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_before_retrieve_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_before_retrieve_message(void)
{
	P_MESSAGELIST pMsg = NULL;

	pMsg = mms_file_manager_get_current_message();
	
	if (pMsg)
	{
		if( !mms_judge_mms_box_size_count(pMsg))
		{
			return;
		}
	}
	else
	{
		return;
	}
	
	if (mmsflag.gsend_recv) 
	{	
		/*若正在收发*/
		DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING),
						IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	if(pMsg->size>MMS_MAX_RECEIVE_SIZE)
	{
		DisplayPopup((U8*)GetString(STR_MMS_SIZE_TOO_BIG), 
						IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	{
		char		buffer[MMS_MAX_DETAILS_LENGTH] = {0};
		char    	ucs2TempBuff[MAX_HINT_BUF]= {0};
		char		ansiiTempBuff[MAX_HINT_BUF*2]= {0};
		float		resize = 0;
		
		resize=(float)pMsg->size;
		pfnUnicodeStrcpy(buffer, (const char*)GetString(STR_CMS_MMS_MENUENTRY));//chaozhu.zhou 2006-10-24 modify
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
		if(resize >= 1024)
		{
			sprintf(ansiiTempBuff," %.1f KB ",(float)(resize/1024));
		}
		else
		{
			sprintf(ansiiTempBuff," %d B ",(int)pMsg->size);		
		}
		AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
		pfnUnicodeStrcat(buffer, (S8 *)ucs2TempBuff);	
		pfnUnicodeStrcat(buffer, (const char*)GetString(STR_MMS_DOWNLOAD_CHECK));
		
		DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO,
					IMG_GLOBAL_NO, (UI_string_type)buffer,
					IMG_GLOBAL_QUESTION, WARNING_TONE);
		SetLeftSoftkeyFunction(mmi_mms_entry_retrieve_message, KEY_EVENT_UP);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);		
	}	
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_send_retrieve_message
 *       Purpose: exit the send or retrieve screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_send_retrieve_message(void)
{
	SuspendFlag = 1;
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_retrieve_message
 *       Purpose: receive the push message in inbox
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_retrieve_message(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16 		screenId = SCR_ID_SENDING_RETRIEVING_MESSAGE;
	P_MESSAGELIST pMsg = NULL;
	SuspendFlag = 0;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	pMsg = mms_file_manager_get_current_message();
	if(pMsg!=NULL)
	{
		mms_file_manager_set_push_message(pMsg);
	}
	if (!pMsg) 
	{
		mmsflag.gsend_recv= FALSE;
		return;
	}
	EntryNewScreen(screenId, 
					NULL,
					mmi_mms_entry_retrieve_message, NULL);
	
	SetMessagesCurrScrnID(screenId);
	ShowCategory66Screen(STR_MMS_RETRIEVING, IMG_MESSAGE_SIM_MMS_MENUENTRY,
						  NULL,NULL, STR_GLOBAL_CANCEL, IMG_GLOBAL_BACK,
						  NULL,IMG_MMS_RETRIEVING, NULL);

	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mms_cancel_send_retrieve, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	SetKeyHandler(NULL,KEY_ENTER, KEY_EVENT_UP);
	
	mmsflag.gmanual_recv = TRUE;

#if (UI_DOUBLE_BUFFER_SUPPORT)
	pixtel_UI_lock_double_buffer();
#endif

	if(!mmsflag.gsend_recv)
	{
		pixtel_UI_create_horizontal_progress_indicator(&show_process_bar,
						(UI_device_width-100)>>1,MMS_PROGRESS_INDICATOR_HEIGHT,100,10);
		mmsflag.gsend_recv = TRUE;
		progress_value=0;
		#if 1
		mms_retrieve_message(NULL);
		#else
		mmi_mms_post_message(CMS_MESSAGE_MMS_RECEIVE_MESSAGE, NULL);
		#endif

	}
	else
	{
		mmi_mms_show_send_receive_status(progress_value);
	}
#if (UI_DOUBLE_BUFFER_SUPPORT)	
	pixtel_UI_unlock_double_buffer();
	pixtel_UI_BLT_double_buffer(0,0,UI_device_width-1,UI_device_height-1);
#endif

}


/* ----------------------------------------------------------------------------
 * Function Name: mms_get_image_frame_count
 *       Purpose:  获取有图片的页数量
 *         Input: void
 *        Output: None.
 *       Returns: *count: 返回数量.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_get_image_frame_count(U16* count)
{
	pMMS_Slide slide = gpeditor_doc->slide_root;

	while (slide)
	{
		if (slide->image_flag == 1)
		{
			(*count)++;
		}
		slide = slide->next;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_get_music_frame_count
 *       Purpose: 获取有音乐的页数量
 *         Input: void
 *        Output: None.
 *       Returns: *count: 返回数量.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_get_music_frame_count(U16* count)
{
	pMMS_Slide slide = gpeditor_doc->slide_root;

	while (slide)
	{
		if (slide->audiosize > 0)
		{
			(*count)++;
		}
		slide = slide->next;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_get_accessory_frame_count
 *       Purpose:  获取有附件的页数量
 *         Input: void
 *        Output: None.
 *       Returns: *count: 返回数量.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_get_accessory_frame_count(U16* count)
{
	pMMS_Slide slide = gpeditor_doc->slide_root;

	while (slide)
	{
		mms_Tracer((char *) "in slide accessory");
		if (slide->accessory_flag == 1)
		{
			mms_Tracer((char *) "in accessory_flag");
			(*count)++;
		}
		slide = slide->next;
	}
}
/*--------------------------------- out box  -----------------------------*/

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_outbox
 *       Purpose: entry out box screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_outbox(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*  guiBuffer=NULL;
	S32	 hiliteitem = 0;
	U16	 screenId = SCR_ID_MMS_OUTBOX;
	P_MESSAGELIST pMsg = NULL;
	int 	 i = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	i = pgManager->sendFolder->messageNumber;
	if (i <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_OUTBOX_IS_EMPTY), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	
	mms_file_manager_set_current_folder(MMS_SEND_FOLDER);
	pMsg = mms_file_manager_get_current_message();
	
	if (pMsg&&(mmsflag.gsend_recv==FALSE))
	{
		mmsf_Remove(pMsg->fileName);
	}
	
	EntryNewScreen(screenId, NULL, mmi_mms_entry_outbox, NULL);	

	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);    
	SetMessagesScrnIdToDelHistoryNodes(screenId);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(mmi_get_index);
	if (guiBuffer)
	{
		hiliteitem = ghiliindex;
	}
	/* Display the call history main screen */
	mms_mmi_tracer("^_^mmi_mms_entry_outbox:ghiliindex = %d",(char*)ghiliindex);

	ShowCategory184Screen(STR_MMS_OUTBOX, IMG_MESSAGE_SIM_MMS_MENUENTRY,
							STR_GLOBAL_OK, IMG_GLOBAL_OK,
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							i, mmi_box_list_get_item, 
							mmi_box_list_get_hint, hiliteitem, guiBuffer);
	
	/* Register function with right softkey */
#ifdef NO_LSK
	//SetLeftSoftkeyFunction(mmi_mms_enter_before_outbox_options, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_enter_before_outbox_options, KEY_SEND1, KEY_EVENT_UP);//ghw222
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	
	SetRightSoftkeyFunction(mmi_mms_exit_boxes, KEY_EVENT_UP);
//	SetKeyHandler(mmi_mms_exit_boxes, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
//	SetKeyHandler(mmi_mms_enter_before_outbox_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_enter_before_outbox_options, KEY_LSK, KEY_EVENT_DOWN);//ghw222

#else
	SetLeftSoftkeyFunction(mmi_mms_enter_before_outbox_options, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_boxes, KEY_EVENT_UP);
//	SetKeyHandler(mmi_mms_exit_boxes, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
//	SetKeyHandler(mmi_mms_enter_before_outbox_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_enter_before_outbox_options, KEY_ENTER, KEY_EVENT_DOWN);

#endif
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_enter_before_outbox_options
 *       Purpose: enter outbox options
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_enter_before_outbox_options(void)
{
	U8 		type;
	U16 		index;
	P_MESSAGELIST 	pMsg;
	
	mmi_mmsbox_find_message_by_index(ghiliindex);

#ifdef SUPPORT_SMSMMS_COMBINE
	pMsg=pgManager->currentFolder->currentMessage;
	if (!pMsg)
	{
		return ;
	}
	if( pMsg ->msgtype==MESSAGE_SMS)
    	{
        	mmi_frm_sms_get_sms_list_index(&type,&index,pMsg->SmsIndex);
		g_msg_cntx.currBoxIndex=index;
		g_msg_cntx.toDisplayMessageList=TO_DISPLAY_MESSAGE_LIST_OUTBOX;
		mmi_msg_get_msg_req(MMI_FRM_SMS_APP_OUTBOX, index);      
    		return;
	}
#endif
	mmi_mms_enter_outbox_options();
	mms_Tracer((char*)"^_^mmi_mms_enter_before_outbox_options ^_^end");

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_enter_outbox_options
 *       Purpose: enter outbox option
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_enter_outbox_options(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer=NULL;
	U16 		numItems=0;
	U16 		nStrItemList[MAX_SUB_MENUS];
	U16 		itemIcons[MAX_SUB_MENUS];
	U16 		screenId=SCR_ID_MMS_OUTBOX_OPTIONS;
	U8* 		popUpList[MAX_SUB_MENUS];
	U32 		maskingByte=-1;
	U8** 	pPopUpList=NULL;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_enter_outbox_options, NULL);
	
	mms_Tracer((char*)"^_^mmi_mms_enter_outbox_options");
	
	if(pCurFwrReMsg!=NULL)
	{
		mms_file_manager_set_current_message(pCurFwrReMsg);
		pCurFwrReMsg=NULL;
	}
	guiBuffer = GetCurrGuiBuffer(screenId);	
	numItems = GetNumOfChild(MMS_OUTBOX_OPTIONS_MENUID);
	GetSequenceStringIds(MMS_OUTBOX_OPTIONS_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_OUTBOX_OPTIONS_MENUID, itemIcons);

	MaskStringItems(popUpList,(U8)numItems,maskingByte);
	MaskItems(itemIcons,(U8)numItems,maskingByte);
	MaskHiliteItems(MMS_OUTBOX_OPTIONS_MENUID, maskingByte);
	numItems=MaskItems(nStrItemList,(U8)numItems,maskingByte);
	
	SetMessagesCurrScrnID(screenId);
	SetParentHandler(MMS_OUTBOX_OPTIONS_MENUID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	
	ShowCategory52Screen(STR_MMS_OUTBOX_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer );
	
	mms_Tracer((char*)"^_^ShowCategory52Screen");

	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_box_options, KEY_EVENT_UP);
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_before_box_send_message
 *       Purpose: 信箱发送信息
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_before_box_send_message(void)
{
	char *sub_uni = NULL;
	P_MESSAGELIST pMsg = mms_file_manager_get_current_message();
	
	if (mmsflag.gsend_recv) 
	{
		DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING),IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	if(pMsg->size>MMS_MAX_SIZE_OF_MESSAGE)
	{
		DisplayPopup((U8*)GetString(STR_MMS_SIZE_TOO_BIG), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);
	sub_uni = Cms_mms_uni8_16(pMsg->subject);
	pfnUnicodeStrcpy((S8 *)gedit.sub_buf,sub_uni);
	mms_Free(sub_uni);
	sub_uni = NULL;
	mms_parse_message_file();
	cms_parse_sendto_address(pMsg,SENDTO_TO);
	cms_parse_sendto_address(pMsg,SENDTO_CC);
	cms_parse_sendto_address(pMsg,SENDTO_BCC);
	pCurFwrReMsg=pMsg;
	mmsflag.gsend_save=FALSE;
	mms_before_send_message();

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_view_msg_detail
 *       Purpose: view message details 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_view_msg_detail(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 		i = 0, j = 0;
	U8*		guiBuffer=NULL;
	U16		screenId=SCR_ID_MMS_VIEW_DETAILS;
	char*	temp = NULL;
	char		time[MMS_MAX_DATE_LEN] = {0};
	S32		str_len = 0;
	float		resize=0;
	
	char		ansiiTempBuff[512]={0};
	char		ucs2TempBuff[1024]={0};
	P_MESSAGELIST pMsg = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	pMsg = mms_file_manager_get_current_message();
	if (!pMsg)
	{
		return;
	}
	while (i < 14)	
	{
		time[j++] = pMsg->date[i++];
		if (i == 4 || i == 6)
		{
			time[j++] = '-';
		}
		else if (i == 8)
		{
			time[j++] = '\n';
		}
		else if (i == 10 || i == 12)
		{
			time[j++] = ':';
		}
	}

	memset(UnicodeBuf,0,sizeof(UnicodeBuf));
	/*收件人/发件人*/
	switch(mms_file_manager_get_current_folder())
	{
	case MMS_RECEIVE_FOLDER:
		pfnUnicodeStrcpy((PS8)UnicodeBuf,(S8 *)GetString( STR_MMS_SENDER ));
		break;
	case MMS_SEND_FOLDER:
	case MMS_DRAFT_FOLDER:
		pfnUnicodeStrcpy((PS8)UnicodeBuf,(S8 *)GetString( STR_MMS_TO_ID ));
		break;
	default:
		break;
	}
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");

	if(pMsg->to_address) 
	{
		pSENDTO_LIST plist = NULL;
		cms_parse_sendto_address(pMsg,SENDTO_TO);
		plist = pgsendtolist;
		while (plist)
		{
			memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
			sprintf( (S8 *)ansiiTempBuff, "%s\n",plist->number);
			memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
			AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
			pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
			plist = plist->next;
		}
		cms_empty_sendto_to_list();
		pgsendtolist=NULL;
	}
	else
	{
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"<");
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_GLOBAL_EMPTY));
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L">\n");
	}
	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	/*抄送*/
	if(pMsg->url==NULL)
	{
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_CC_ID));
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
		if(pMsg->cc_address) 
		{
			pSENDTO_LIST plist = NULL;
			cms_parse_sendto_address(pMsg,SENDTO_CC);
			plist = pgsendcclist;
			while (plist)
			{
				memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
				sprintf( (S8 *)ansiiTempBuff, " %s\n",plist->number);
				memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
				AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
				pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
				plist = plist->next;
			}
			cms_empty_sendto_cc_list();
			pgsendcclist=NULL;
		}
		else
		{
			pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"<");
			pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_GLOBAL_EMPTY));
			pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L">\n");
		}
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	}
	
	/* 主题*/
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_SUBJECT_ID));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
	if(pMsg->subject!=NULL)
	{	
		temp=Cms_mms_uni8_16(pMsg->subject);
		pfnUnicodeStrncat((PS8)UnicodeBuf,(PS8)temp,40);
		mms_Free(temp);
		temp = NULL;
	}
	else
	{
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"<");
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_GLOBAL_EMPTY));
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L">");
	}
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n\n");

	/*发送/接收时间*/
	switch(mms_file_manager_get_current_folder())
	{
	case MMS_RECEIVE_FOLDER:
	case MMS_SEND_FOLDER:
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_SENT));
		break;
	case MMS_DRAFT_FOLDER:
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_CREATE));
		break;
	default:
		break;
	}
	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	sprintf( (S8 *)ansiiTempBuff, ":\n%s\n\n",time);
	memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);

	/*信息大小*/
	resize=(float)pMsg->size;
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_MSG_SIZE));
	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	sprintf( (S8 *)ansiiTempBuff, ":\n%.1f K\n\n",(float)(resize/1024));
	memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);

	/*有效期*/
	if(pMsg->url!=NULL)
	{	
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_SETTINGS_EXPIRES));
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		sprintf( (S8 *)ansiiTempBuff, ":\n%d",(int)(pMsg->expriy_time));
		memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
		AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_HOUR));
	}

	str_len=pfnUnicodeStrlen((PS8)UnicodeBuf);
	
	EntryNewScreen(screenId, NULL,
				mmi_mms_view_msg_detail, NULL);
	
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
	
	ShowCategory74Screen(STR_MMS_INBOX_OPTIONS_DETAILS,IMG_MESSAGE_SIM_MMS_MENUENTRY,NULL,
						NULL,STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						(PU8)UnicodeBuf, str_len, guiBuffer);

	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*--------------------------------- draft box  -----------------------------*/

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_draftbox
 *       Purpose: entry draft box
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_draftbox(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*  guiBuffer=NULL;
	S32	 hiliteitem = 0;
	U16	 screenId = SCR_ID_MMS_DRAFTBOX;
	P_MESSAGELIST pMsg = NULL;
	int 	 i = 0;
		
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	i = pgManager->draftFolder->messageNumber;
	if (i <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_DRAFTBOX_IS_EMPTY), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	
	mms_file_manager_set_current_folder(MMS_DRAFT_FOLDER);
	pMsg = mms_file_manager_get_current_message();

	if (pMsg&&(mmsflag.gsend_recv==FALSE))
	{
		mmsf_Remove(pMsg->fileName);
	}
	
	EntryNewScreen(screenId, NULL, mmi_mms_entry_draftbox, NULL);	

	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);    
	SetMessagesScrnIdToDelHistoryNodes(screenId);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(mmi_get_index);
	if (guiBuffer)
	{
		hiliteitem = ghiliindex;
	}
	/* Display the call history main screen */
	ShowCategory184Screen(STR_MMS_DRAFTBOX, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						STR_GLOBAL_OK, IMG_GLOBAL_OK,
						STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						i, mmi_box_list_get_item, 
						mmi_box_list_get_hint, hiliteitem, guiBuffer);
	
	/* Register function with right softkey */
#ifdef NO_LSK
	//SetLeftSoftkeyFunction(mmi_mms_enter_before_draftbox_options, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_enter_before_draftbox_options, KEY_SEND1, KEY_EVENT_UP);//ghw222
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (mmi_mms_exit_boxes, KEY_EVENT_UP);
//	SetKeyHandler(mmi_mms_exit_boxes, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
//	SetKeyHandler(mmi_mms_enter_before_draftbox_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_enter_before_draftbox_options, KEY_LSK, KEY_EVENT_DOWN);//ghw222

#else
	SetLeftSoftkeyFunction(mmi_mms_enter_before_draftbox_options, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction (mmi_mms_exit_boxes, KEY_EVENT_UP);
//	SetKeyHandler(mmi_mms_exit_boxes, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
//	SetKeyHandler(mmi_mms_enter_before_draftbox_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_mms_enter_before_draftbox_options, KEY_ENTER, KEY_EVENT_DOWN);

#endif
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_enter_draftbox_options
 *       Purpose: enter draftbox option
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_enter_before_draftbox_options(void)
{
    	U16 	index;
    	U8 	type;
    	P_MESSAGELIST pMsg;

	mms_Tracer((char*)"^_^mmi_mms_enter_before_draftbox_options^_^");
	mmi_mmsbox_find_message_by_index(ghiliindex);

#ifdef SUPPORT_SMSMMS_COMBINE
	pMsg = (P_MESSAGELIST)mms_file_manager_get_current_message();
	if (!pMsg)
	{
		return ;
	}
	if( pMsg->msgtype==MESSAGE_SMS)
	{		
		mmi_frm_sms_get_sms_list_index(&type,&index,pMsg->SmsIndex);
		g_msg_cntx.currBoxIndex=index;
        
		g_msg_cntx.toDisplayMessageList=TO_DISPLAY_MESSAGE_LIST_DRAFTBOX;
		mmi_msg_get_msg_req(MMI_FRM_SMS_APP_DRAFTS, index);      
		return;
	}
#endif

	mmi_mms_enter_draftbox_options();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_enter_draftbox_options
 *       Purpose: enter draftbox option
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_enter_draftbox_options(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 		guiBuffer=NULL;
	U16 		numItems=0;
	U16 		nStrItemList[MAX_SUB_MENUS];
	U16 		itemIcons[MAX_SUB_MENUS];
	U16 		screenId=SCR_ID_MMS_DRAFTBOX_OPTIONS;
	U8* 		popUpList[MAX_SUB_MENUS];
	U32 		maskingByte=-1;
	U8** 	pPopUpList=NULL;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL, 
					mmi_mms_enter_draftbox_options, NULL);	
	mms_Tracer((char*)"^_^mmi_mms_enter_draftbox_options^_^");

	guiBuffer = GetCurrGuiBuffer(screenId);	
	numItems = GetNumOfChild(MMS_DRAFTBOX_OPTIONS_MENUID);
	GetSequenceStringIds(MMS_DRAFTBOX_OPTIONS_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_DRAFTBOX_OPTIONS_MENUID, itemIcons);

	MaskStringItems(popUpList,(U8)numItems,maskingByte);
	MaskItems(itemIcons,(U8)numItems,maskingByte);
	MaskHiliteItems(MMS_DRAFTBOX_OPTIONS_MENUID, maskingByte);
	numItems=MaskItems(nStrItemList,(U8)numItems,maskingByte);

	SetMessagesCurrScrnID(screenId);
	SetParentHandler(MMS_DRAFTBOX_OPTIONS_MENUID);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	/* Display the call history main screen */
	ShowCategory52Screen(STR_MMS_DRAFTBOX_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer );
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(mmi_mms_exit_box_options, KEY_EVENT_UP);

}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_draftbox_edit_content
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_draftbox_edit_content(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	char*		  	temp = NULL;
	P_MESSAGELIST 	pMsg = mms_file_manager_get_current_message();

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	gbox_operation = BOX_OPTIONS_EDIT;
	memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);

	temp = Cms_mms_uni8_16(pMsg->subject);
	pfnUnicodeStrcpy((S8 *)gedit.sub_buf,temp);
	mms_Free(temp);
	temp = NULL;

	mms_parse_message_file();
	cms_parse_sendto_address(pMsg,SENDTO_TO);
	cms_parse_sendto_address(pMsg,SENDTO_CC);
	cms_parse_sendto_address(pMsg,SENDTO_BCC);

	mmi_mms_entry_edit_content();
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
#if 0
#endif
/*--------------------------------- mms template -----------------------------*/

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_templates
 *       Purpose:  进入模板选项
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_templates(void)
{
      	U8* 		guiBuffer=NULL;
	U16 		numItems=0;
	U16 		nStrItemList[MAX_SUB_MENUS];
	U16 		itemIcons[MAX_SUB_MENUS];
	U16 		screenId=SCR_ID_MMS_TEMPLATES;
	U8* 		popUpList[MAX_SUB_MENUS];
	U32 		maskingByte=-1;
	U8** 	pPopUpList=NULL;


	mms_Tracer("enter mmi_mms_entry_templates");   
      	EntryNewScreen(screenId, 
					NULL,mmi_mms_entry_templates, NULL);

	mms_file_manager_set_current_folder(MMS_FOLDER_UNKNOWN);
	SetParentHandler(MMS_MENU_TEMPLATES_MENUID);
	RegisterHighlightHandler(mmi_mms_get_template_index);
	numItems = GetNumOfChild(MMS_MENU_TEMPLATES_MENUID);
	GetSequenceStringIds(MMS_MENU_TEMPLATES_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_MENU_TEMPLATES_MENUID, itemIcons);
	
	MaskStringItems(popUpList,(U8)numItems,maskingByte);
	
	MaskItems(itemIcons,(U8)numItems,maskingByte);
	MaskHiliteItems(MMS_MENU_TEMPLATES_MENUID, maskingByte);
	numItems=MaskItems(nStrItemList,(U8)numItems,maskingByte);
	
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);	
	

	ShowCategory52Screen(STR_MMS_TEMPLATES, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,
						  guiBuffer );
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
       SetLeftSoftkeyFunction(mmi_mms_entry_template_options,KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	mms_Tracer("out mmi_mms_entry_templates");   
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_get_template_index
 *       Purpose: 获取模板项索引
 *         Input:  S32 nIndex : 当前菜单项索引
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_get_template_index(S32 nIndex)
{
	ghiliindex = nIndex;    
}


/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_template_options
 *       Purpose:  模板选项
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_template_options(void)
{
      	U8*		guiBuffer=NULL;
	U16		numItems=0;
	U16		nStrItemList[MAX_SUB_MENUS];

	mms_Tracer("enter mmi_mms_entry_template_options");   
	EntryNewScreen(SCR_ID_MMS_TEMPLATES_OPTIONS, NULL, 
					mmi_mms_entry_template_options, NULL);	
	
	guiBuffer = GetCurrGuiBuffer (SCR_ID_MMS_TEMPLATES_OPTIONS);
	numItems = GetNumOfChild (MMS_TEMPLATES_OPTION_MENUID);	
	GetSequenceStringIds(MMS_TEMPLATES_OPTION_MENUID, nStrItemList);	
	SetParentHandler (MMS_TEMPLATES_OPTION_MENUID);
	
	RegisterHighlightHandler (ExecuteCurrHiliteHandler);
	SetMessagesCurrScrnID(SCR_ID_MMS_TEMPLATES_OPTIONS);
	SetMessagesScrnIdToDelHistoryNodes (SCR_ID_MMS_TEMPLATES_OPTIONS);
		
	GetCurrEndKeyDownHandler();
	ShowCategory52Screen(STR_GLOBAL_OPTIONS,	IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  			STR_GLOBAL_OK,		IMG_GLOBAL_OK,
						  			STR_GLOBAL_BACK,	IMG_GLOBAL_BACK,
						  			numItems, nStrItemList, (U16 *)gIndexIconsImageList, NULL,
						  			0, 0,	guiBuffer );
	mms_Tracer("out mmi_mms_entry_template_options");   
       SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_template_details
 *       Purpose:  模板选项详情
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_template_details(void)
{
        U8*         guiBuffer = NULL;
	 U16         screenId = SCR_MMS_TEMPLATE_DETAILS;
	 float	 resize=0;
	 char	 ansiiTempBuff[MAX_SHOW_STRING_BUF];
	 char	 ucs2TempBuff[MAX_SHOW_STRING_BUF];
	 S32        str_len = 0;
        S8*        image_buf = NULL;
	 S32        size = 0;
	 MYTIME	t;

	 mms_Tracer("enter mmi_mms_entry_template_details");   
	 mms_mmi_tracer("ghiliindex=:%d", ghiliindex);
	 memset(UnicodeBuf,0,sizeof(UnicodeBuf));  
	 pfnUnicodeStrcpy((PS8)UnicodeBuf,(S8 *)GetString( STR_MMS_SENDER ));
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"<");
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_GLOBAL_EMPTY));
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L">\n");

	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_CC_ID));
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"<");
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_GLOBAL_EMPTY));
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L">\n\n");

	/* 主题*/
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_SUBJECT_ID));
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");	 
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_TEMPLATES_TITLE_01+ghiliindex));
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n\n");

	/* 时间*/	 
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_CREATE));
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
	 GetDateTime(&t);
	 memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	 sprintf(ansiiTempBuff,"%4d-%d%d-%d%d\n%d%d:%d%d:%d%d\n\n",
		(int)t.nYear,(int)(t.nMonth/10),(int)(t.nMonth%10),
		(int)(t.nDay/10),(int)(t.nDay%10),(int)(t.nHour/10),(int)(t.nHour%10),
		(int)(t.nMin/10),(int)(t.nMin%10),(int)(t.nSec/10),(int)(t.nSec%10));
	 memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	 AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);

	/* 大小*/
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_MSG_SIZE));
	 
        image_buf = GetImage(IMG_MMS_TEMPLATES_01+ghiliindex);
        size =((*(image_buf+3))<<8)+(*(image_buf+2));
        size+= mtk_resource_mms_sounds[ghiliindex].len;
	 resize = (float)size;	
	 sprintf( (S8 *)ansiiTempBuff, ":\n%.1f K\n\n",(float)(resize/1024));	
 	 memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	 AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	 pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);

	 str_len=pfnUnicodeStrlen((PS8)UnicodeBuf);
	 /*进入新屏幕*/
	 EntryNewScreen(screenId, NULL,
		mmi_mms_entry_template_details, NULL);
	 SetMessagesCurrScrnID(screenId);
	 guiBuffer = GetCurrGuiBuffer(screenId);	 
	 ShowCategory74Screen(STR_MMS_INBOX_OPTIONS_DETAILS,IMG_MESSAGE_SIM_MMS_MENUENTRY,NULL,
						NULL,STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						(PU8)UnicodeBuf, str_len, guiBuffer);
	mms_Tracer("out mmi_mms_entry_template_details");   
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);	

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_template_write_message
 *       Purpose:  模板项新建信息
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_template_write_message(void)
{
       char 		img_fname[MMS_MAX_FILE_NAME_LENGTH] = {0};
 	char		 	text_name[MMS_FILE_NAME_LEN];
      	S8*  		image_buf = NULL;
       S32  		size = 0;
       FILE_HANDLE  fd = 0;
	pMMS_Content 	content = NULL;	
	unsigned short     	buff_size = 0;
	pMMS_Slide 		slide;

	MMSDelAllSlide(gpeditor_doc);
	gpeditor_doc->totalsize = 0;
       slide = MMS_New_Slide(gpeditor_doc);
      
	memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);
	pfnUnicodeStrcpy((S8*)gedit.sub_buf, GetString(STR_MMS_TEMPLATES_TITLE_01+ghiliindex));
      	pfnUnicodeStrcpy((S8*)gedit.text_buf,GetString(STR_MMS_TEMPLATES_TITLE_01+ghiliindex));

	mms_get_randstring(text_name);   
	strcat(text_name,".txt");
	
	fd = mmsf_Open(text_name,"w");
	if(fd <= 0)
	{
		mms_Tracer("error--fd<=0");
		DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	buff_size = 2*Cms_Browser_Uni16_strlen(gedit.text_buf)+2;
	mmsf_Write((char *)(&buff_size),1,sizeof(unsigned short),fd);
	mmsf_Write((char *)(gedit.text_buf),1,buff_size,fd);
	mmsf_Close(fd);

	content = MMS_New_Content((U8*)text_name,MMS_TYPE_TEXT,slide,gpeditor_doc);
	if (!content)
	{
		mms_Tracer(": add new content error!!!!!!!!!!");
		return;
	}
       mms_get_randstring(img_fname);
	strcat(img_fname,".gif");
	fd = mmsf_Open((char*)img_fname,"w");
	if (fd <= 0)
	{
		return ;
	}
       
       image_buf = GetImage(IMG_MMS_TEMPLATES_01+ghiliindex);
       size =((*(image_buf+3))<<8)+(*(image_buf+2));
	mmsf_Write((S8*)(image_buf+8), 1, size, fd);
	mmsf_Close(fd);
	content = MMS_New_Content((unsigned char*)img_fname,MMS_TYPE_GIF,slide,gpeditor_doc);
       if (!content)
	{
		mms_Tracer(": add new content error!!!!!!!!!!");
		return;
	}
       cms_insert_music_into_new_mms((char *)mtk_resource_mms_sounds[ghiliindex].data,mtk_resource_mms_sounds[ghiliindex].len,MMS_TYPE_MIDI);
       gedit.total_height = 0; 
	   
	mmi_mms_entry_new_message();

}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_template_preview
 *       Purpose:  模板项预览
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_template_preview(void)
{
       S32 				size = 0;
	unsigned short     	buff_size = 0;
	pMMS_Slide 		slide;
       S8*  			image_buf = NULL;
       FILE_HANDLE  	fd = 0;
	pMMS_Content 	content = NULL;	
	char		 		text_name[MMS_FILE_NAME_LEN];
	   
	mms_Tracer("enter mmi_mms_entry_template_preview");   
	MMSDelAllSlide(gpeditor_doc);
	gpeditor_doc->totalsize = 0;
       slide = MMS_New_Slide(gpeditor_doc);
	
       pfnUnicodeStrcpy((S8*)gedit.text_buf,GetString(STR_MMS_TEMPLATES_TITLE_01+ghiliindex));
       kal_prompt_trace(MOD_NVRAM, "ghiliindex is %d", ghiliindex);
	mms_get_randstring(text_name);   
	strcat(text_name,".txt");
	fd = mmsf_Open(text_name,"w");
	
	if(fd <= 0)
	{
		mms_Tracer("error--fd<=0");
		DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	buff_size = 2*Cms_Browser_Uni16_strlen(gedit.text_buf)+2;
	mmsf_Write((char *)(&buff_size),1,sizeof(unsigned short),fd);
	mmsf_Write((char *)(gedit.text_buf),1,buff_size,fd);
	mmsf_Close(fd);

	content = MMS_New_Content((U8*)text_name,MMS_TYPE_TEXT,slide,gpeditor_doc);
	if (!content)
	{
		mms_Tracer(": add new content error!!!!!!!!!!");
		return;
	}
	
	mms_mmi_tracer("the image ghiliindex is %d", ghiliindex);
       image_buf = GetImage(IMG_MMS_TEMPLATES_01+ghiliindex);
	if(image_buf != NULL)
	{
       	size =((*(image_buf+3))<<8)+(*(image_buf+2));
      	 	cms_insert_image_into_new_mms((char *) image_buf+8, (S32) size, MMS_TYPE_GIF);
	}		
       cms_insert_music_into_new_mms((char *)mtk_resource_mms_sounds[ghiliindex].data,mtk_resource_mms_sounds[ghiliindex].len,MMS_TYPE_MIDI);

	mmi_mms_play_message();
}

#if 0
#endif
/*--------------------------------- empty box -----------------------------*/
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_set_processing_screen
 *       Purpose:  设定进程字符串
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_set_processing_screen (U16 captionStrId, U16 bodyStrId, U16 animationImageId, U16 rskStrId)
{
	mmsProCapStrId=captionStrId;
	mmsProbodyStrId=bodyStrId;
	mmsProAnimationId=animationImageId;
	mmsProRSKStrId=rskStrId;
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_processing_generic
 *       Purpose: 进程退出处理
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_processing_generic (void)
{
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_processing_generic
 *       Purpose:  进程处理函数
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_processing_generic (void)
{
	EntryNewScreen(SCR_ID_MSG_PROCESSING, NULL,
					mmi_mms_entry_processing_generic, NULL);
	
	ShowCategory8Screen (mmsProCapStrId, IMG_MESSAGE_SIM_MMS_MENUENTRY,
						0, 0, mmsProRSKStrId, 0, mmsProbodyStrId, mmsProAnimationId, NULL);


	ClearAllKeyHandler ();
	ClearKeyHandler(KEY_END, KEY_EVENT_UP);
	ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
	ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
	ClearKeyHandler(KEY_END, KEY_REPEAT);
	if(isInCall())
		SetKeyHandler(HangupAllCalls, KEY_END, KEY_EVENT_DOWN);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_empty_box
 *       Purpose: entry empty box
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_empty_box(void)
{
	U8* guiBuffer=NULL;
	U16 numItems=0;
	U16 nStrItemList[MAX_SUB_MENUS];
	U16 screenId=SCR_ID_MMS_EMPTY_BOX;
	U8* pPopUpList[MAX_SUB_MENUS];
	
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_empty_box, NULL);

	mms_file_manager_set_current_folder(MMS_FOLDER_UNKNOWN);
	guiBuffer = GetCurrGuiBuffer(screenId);	
	numItems = GetNumOfChild(MMS_MENU_EMPTY_BOX_MENUID);
	GetSequenceStringIds(MMS_MENU_EMPTY_BOX_MENUID, nStrItemList);

	SetMessagesCurrScrnID(screenId);
	SetParentHandler(MMS_MENU_EMPTY_BOX_MENUID);

	ConstructHintsList(MMS_MENU_EMPTY_BOX_MENUID, pPopUpList);
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);	

	ShowCategory52Screen(STR_EMPTY_BOX, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, (U16 *)gIndexIconsImageList,
						  pPopUpList, 0, 0,guiBuffer );

	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
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
void mmi_mms_sms_emptybox_callback(void* dummy, module_type mod, U16 result)
{
	if(result==MMI_FRM_SMS_OK)
	{
	    g_msg_cntx.currBoxIndex=0;
		/*if(mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX))
		{
		     	g_msg_cntx.msg_full_ind=FALSE;
		     	mmi_msg_set_msg_icon(FALSE, FALSE);
		}*/
		mmi_msg_set_msg_icon(FALSE, FALSE);
		mmi_update_mms_idel_icon();
		
		ExitDisplayPopupConfirm();
		DeleteUptoScrID(SCR_ID_MMS_EMPTY_BOX);
		GoBackHistory();
		DisplayPopup((U8*)GetString(STR_DELETE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	}
	else
	{

		DeleteUptoScrID(SCR_ID_MMS_EMPTY_BOX);
		GoBackHistory();
		DisplayPopup((U8*)GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
	}
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
void mms_emptybox_inbox(void)
{
	mms_file_manager_set_current_folder(MMS_RECEIVE_FOLDER);
	mms_file_manager_delete_current_folder();
#ifdef SUPPORT_SMSMMS_COMBINE
	mmi_frm_sms_delete_sms(mmi_mms_sms_emptybox_callback, MOD_MMI, MMI_FRM_SMS_APP_INBOX, MMI_FRM_SMS_INVALID_INDEX);
	mmi_mms_set_processing_screen (STR_EMPTY_BOX, STR_FMGR_DELETING, IMG_GLOBAL_PROGRESS, NULL);
	mmi_mms_entry_processing_generic();
#else
	ExitDisplayPopupConfirm();
	GoBackHistory();
	DisplayPopup((U8*)GetString(STR_DELETE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
#endif
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
void mms_emptybox_outbox(void)
{

	mms_file_manager_set_current_folder(MMS_SEND_FOLDER);
	mms_file_manager_delete_current_folder();

#ifdef SUPPORT_SMSMMS_COMBINE
	mmi_frm_sms_delete_sms(mmi_mms_sms_emptybox_callback, MOD_MMI, MMI_FRM_SMS_APP_OUTBOX, MMI_FRM_SMS_INVALID_INDEX);
	mmi_mms_set_processing_screen (STR_EMPTY_BOX, STR_FMGR_DELETING, IMG_GLOBAL_PROGRESS, NULL);
	mmi_mms_entry_processing_generic();
#else
	ExitDisplayPopupConfirm();
	GoBackHistory();
	DisplayPopup((U8*)GetString(STR_DELETE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
#endif
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
void mms_emptybox_draftbox(void)
{
	mms_file_manager_set_current_folder(MMS_DRAFT_FOLDER);
	mms_file_manager_delete_current_folder();
	
#ifdef SUPPORT_SMSMMS_COMBINE
	mmi_frm_sms_delete_sms(mmi_mms_sms_emptybox_callback, MOD_MMI, MMI_FRM_SMS_APP_DRAFTS, MMI_FRM_SMS_INVALID_INDEX);
	mmi_mms_set_processing_screen (STR_EMPTY_BOX, STR_FMGR_DELETING, IMG_GLOBAL_PROGRESS, NULL);
	mmi_mms_entry_processing_generic();
#else
	ExitDisplayPopupConfirm();
	GoBackHistory();
	DisplayPopup((U8*)GetString(STR_DELETE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
#endif
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
void mms_emptybox_allbox(void)
{
	mms_file_manager_set_current_folder(MMS_RECEIVE_FOLDER);
	mms_file_manager_delete_current_folder();
	mms_file_manager_set_current_folder(MMS_SEND_FOLDER);
	mms_file_manager_delete_current_folder();
	mms_file_manager_set_current_folder(MMS_DRAFT_FOLDER);
	mms_file_manager_delete_current_folder();
#ifdef SUPPORT_SMSMMS_COMBINE
	mmi_frm_sms_delete_sms(mmi_mms_sms_emptybox_callback, MOD_MMI, MMI_FRM_SMS_APP_INBOX | \
							MMI_FRM_SMS_APP_OUTBOX| MMI_FRM_SMS_APP_DRAFTS, MMI_FRM_SMS_INVALID_INDEX);
	mmi_mms_set_processing_screen (STR_EMPTY_BOX, STR_FMGR_DELETING, IMG_GLOBAL_PROGRESS, NULL);
	mmi_mms_entry_processing_generic();
#else
	ExitDisplayPopupConfirm();
	GoBackHistory();
	DisplayPopup((U8*)GetString(STR_DELETE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
#endif
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
void mmi_mms_indication_empty_inbox(void)
{
	if(mmsflag.gsend_recv==TRUE)
	{
		DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING),IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}

	if (pgManager->receiveFolder->messageNumber <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_INBOX_IS_EMPTY), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO,
					IMG_GLOBAL_NO, (UI_string_type)GetString(STR_EMPTY_INBOX),
					IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(mms_emptybox_inbox, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_mms_exit_to_history, KEY_EVENT_UP);	
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
void mmi_mms_indication_empty_outbox(void)
{
	if (pgManager->sendFolder->messageNumber <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_OUTBOX_IS_EMPTY), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO,
					IMG_GLOBAL_NO, (UI_string_type)GetString(STR_EMPTY_OUTBOX),
					IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(mms_emptybox_outbox, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_mms_exit_to_history, KEY_EVENT_UP);
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
void mmi_mms_indication_empty_draftbox(void)
{
	if (pgManager->draftFolder->messageNumber <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_DRAFTBOX_IS_EMPTY), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO,
					IMG_GLOBAL_NO, (UI_string_type)GetString(STR_EMPTY_DRAFTBOX),
					IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(mms_emptybox_draftbox, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_mms_exit_to_history, KEY_EVENT_UP);
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
void mmi_mms_indication_empty_allbox(void)
{
	if(mmsflag.gsend_recv==TRUE)
	{
		DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING),IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	
	if ((pgManager->receiveFolder->messageNumber + 
		pgManager->sendFolder->messageNumber + 
		pgManager->draftFolder->messageNumber) <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_ALLBOXES_ARE_EMPTY), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO,
					IMG_GLOBAL_NO, (UI_string_type)GetString(STR_EMPTY_ALLBOX),
					IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(mms_emptybox_allbox, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_mms_exit_to_history, KEY_EVENT_UP);
}

#if 0
#endif
/*--------------------------------- mms setting -----------------------------*/

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_mms_setting
 *       Purpose: entry mms setting
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_mms_setting(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 guiBuffer=NULL;		/* Buffer holding history data */
	U16	 numItems=0;		/* Stores no of children in the submenu*/
	U16	 nStrItemList[MAX_SUB_MENUS];	/* Stores the strings id of submenus returned */
	U16	 itemIcons[MAX_SUB_MENUS];		/* Stores the icon id of submenus returned */
	U16	 screenId=SCR_ID_MMS_SETTING_MENU;
	U8*	 pPopUpList[MAX_SUB_MENUS];	
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_mms_setting, NULL);
	mms_Tracer((char*)"^_^mmi_mms_entry_mms_setting^_^");

	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(MMS_MENU_MSG_SETTINGS_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(MMS_MENU_MSG_SETTINGS_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_MENU_MSG_SETTINGS_MENUID, itemIcons);
	
	/* Construct hint popup strings for menu items */
	ConstructHintsList(MMS_MENU_MSG_SETTINGS_MENUID, pPopUpList);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(MMS_MENU_MSG_SETTINGS_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	/* Display the call history main screen */
	ShowCategory52Screen(STR_MMS_SETTING_MENUENTRY, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						   pPopUpList, 0, 0, guiBuffer);
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_send_message_setting
 *       Purpose: entry send message setting
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_send_message_setting(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* inputBuffer;
	U16 inputBufferSize;
	U8* guiBuffer=NULL;
	U16 itemicon[MAX_SUB_MENUS];
	U16 screenId = SCR_ID_MMS_SETTING_SEND_OPTIONS;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, 
				mmi_mms_exit_send_setting_inline,NULL , NULL);
	
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
	itemicon[10] = IMG_GLOBAL_L6;
	itemicon[11] = 0;
	
	guiBuffer = GetCurrGuiBuffer (screenId);	
	inputBuffer = GetCurrNInputBuffer(SCR_ID_MMS_SETTING_SEND_OPTIONS, &inputBufferSize );

	InitializeCategory57Screen();
	mmi_mms_send_setting_inline_struct();
	
	if(inputBuffer != NULL)		
		SetCategory57Data(wgui_inline_items, NUM_MMS_MSG_SETTINGS_INLINE, inputBuffer);

	ShowCategory57Screen(STR_MMS_SETTING_SEND_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
							STR_GLOBAL_OK, NULL,
							STR_GLOBAL_BACK, NULL,
							NUM_MMS_MSG_SETTINGS_INLINE,
							itemicon, wgui_inline_items, 0, guiBuffer);	

	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);

	SetCategory57RightSoftkeyFunctions(mmi_mms_indication_save_mms_setting,GoBackHistory);
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
void mmi_mms_exit_send_setting_inline(void)
{
	history	h;
	U16 inputBufferSize;
	
	CloseCategory57Screen();
	h.scrnID = SCR_ID_MMS_SETTING_SEND_OPTIONS;
	h.entryFuncPtr = mmi_mms_exit_send_setting_inline;
	GetCategoryHistory(h.guiBuffer);
	inputBufferSize =(U16)GetCategory57DataSize( ); 
	GetCategory57Data ((U8*) h.inputBuffer );  
	AddNHistory(h, inputBufferSize);           
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
void mmi_mms_send_setting_inline_struct(void)
{

	mms_init_message_settings();

	mms_Tracer((char*)"^_^mmi_mms_send_setting_inline_struct^_^");
	gconfig.time[0]=(U8*)GetString (STR_MMS_ONE_HOUR);
	gconfig.time[1]=(U8*)GetString (STR_MMS_ONE_DAY);
	gconfig.time[2]=(U8*)GetString (STR_MMS_ONE_WEEK);
	gconfig.time[3]=(U8*)GetString (STR_MMS_MAX);
		
	gconfig.onoff[0] = (U8*) GetString (STR_MSG_SETTINGS_OFF);
	gconfig.onoff[1] = (U8*) GetString (STR_MSG_SETTINGS_ON);
	
	gconfig.priority[0] = (U8*)GetString (STR_MMS_SETTINGS_PRIORITY_LOW);
	gconfig.priority[1] = (U8*)GetString (STR_MMS_SETTINGS_PRIORITY_NORMAL);
	gconfig.priority[2] = (U8*)GetString (STR_MMS_SETTINGS_PRIORITY_HIGH);
	
	gconfig.retrieve[0] = (U8*) GetString (STR_MSG_SETTINGS_RETRIEVEMODE_AUTO);
	gconfig.retrieve[1] = (U8*) GetString (STR_MSG_SETTINGS_RETRIEVEMODE_MANUAL);

	gconfig.maxsize[0]=(U8*) GetString (STR_MMS_30K);
	gconfig.maxsize[1]=(U8*) GetString (STR_MMS_50K);
	gconfig.maxsize[2]=(U8*) GetString (STR_MMS_70K);
	gconfig.maxsize[3]=(U8*) GetString (STR_MMS_100K);
	
	SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString (STR_MMS_SETTINGS_EXPIRES));
	SetInlineItemActivation (&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
	SetInlineItemSelect(&wgui_inline_items[1],NUM_MMS_EXPIRES_SETTINGS,gconfig.time,&gconfig.expires);
	CenterJustifyInlineItem(&wgui_inline_items[1]);

	SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString (STR_MMS_SETTINGS_DELIVERY_RPT));
	SetInlineItemActivation (&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
	SetInlineItemSelect(&wgui_inline_items[3],NUM_MMS_SETTINGS_ONOFF,gconfig.onoff,&gconfig.delivery_rpt);
	CenterJustifyInlineItem(&wgui_inline_items[3]);
#ifdef ANONYMOUS
	SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString (STR_MMS_SETTINGS_ANONYMOUS));
	SetInlineItemActivation (&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
	SetInlineItemSelect (&wgui_inline_items[5], NUM_MMS_SETTINGS_ONOFF,gconfig.onoff,&gconfig.anonymous);
	CenterJustifyInlineItem(&wgui_inline_items[5]);
#else
	SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString (STR_MMS_SETTINGS_READ_REPORT));
	SetInlineItemActivation (&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
	SetInlineItemSelect (&wgui_inline_items[5], NUM_MMS_SETTINGS_ONOFF,gconfig.onoff,&gconfig.read_rpt);
	CenterJustifyInlineItem(&wgui_inline_items[5]);
#endif
	SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString (STR_MMS_SETTINGS_PRIORITY));
	SetInlineItemActivation (&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
	SetInlineItemSelect (&wgui_inline_items[7], NUM_MMS_SETTINGS_PRIORITY,gconfig.priority,&gconfig.prior);
	CenterJustifyInlineItem(&wgui_inline_items[7]);

	SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString (STR_MMS_SETTINGS_MAX_SEND));
	SetInlineItemActivation (&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
	SetInlineItemSelect (&wgui_inline_items[9], NUM_MMS_MAX_SIZE_SETTINGS,gconfig.maxsize,&gconfig.sendsize);
	CenterJustifyInlineItem(&wgui_inline_items[9]);

	SetInlineItemCaption(&wgui_inline_items[10], (U8*) GetString (STR_MMS_SETTINGS_FRAME_TIME));
	SetInlineItemActivation (&wgui_inline_items[11], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
	SetInlineItemTextEdit(&wgui_inline_items[11],(U8*)(gconfig.frametime),3,INPUT_TYPE_NUMERIC);
	RegisterInlineTextEditCompleteHandler(&wgui_inline_items[11],mms_set_frametime_validation);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_retrieving_message_setting
 *       Purpose: entry receive message setting
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_retrieving_message_setting(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* inputBuffer;
	U16 inputBufferSize;
	U8* guiBuffer=NULL;
	U16 itemicon[MAX_SUB_MENUS];
	U16 screenId = SCR_ID_MMS_SETTING_RETRIEVE_OPTIONS;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, 
				mmi_mms_exit_retrieving_setting_inline,NULL , NULL);
	mms_Tracer((char*)"^_^mmi_mms_entry_retrieving_message_setting^_^");
	itemicon[0] = IMG_GLOBAL_L1;
	itemicon[1] = 0;
	itemicon[2] = IMG_GLOBAL_L2;
	itemicon[3] = 0;

	InitializeCategory57Screen();
	mmi_mms_retrieving_setting_inline_struct();
	
	guiBuffer = GetCurrGuiBuffer (screenId);	
	inputBuffer = GetCurrNInputBuffer(SCR_ID_MMS_SETTING_RETRIEVE_OPTIONS, &inputBufferSize );
	if(inputBuffer != NULL)		
		SetCategory57Data(wgui_inline_items, NUM_MMS_RETRIEVING_SETTINGS_INLINE, inputBuffer);

	ShowCategory57Screen(STR_MMS_SETTING_RECEIVE_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
							STR_GLOBAL_OK, NULL,
							STR_GLOBAL_BACK, NULL,
							NUM_MMS_RETRIEVING_SETTINGS_INLINE,
							itemicon, wgui_inline_items, 0, guiBuffer);	

	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);

	SetCategory57RightSoftkeyFunctions(mmi_mms_indication_save_mms_setting,GoBackHistory);
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
void mmi_mms_exit_retrieving_setting_inline(void)
{
	history	h;
	U16 		inputBufferSize;
	
	CloseCategory57Screen();
	h.scrnID = SCR_ID_MMS_SETTING_RETRIEVE_OPTIONS;
	h.entryFuncPtr = mmi_mms_entry_retrieving_message_setting;
	GetCategoryHistory(h.guiBuffer);
	
	inputBufferSize =(U16)GetCategory57DataSize( ); 
	GetCategory57Data ((U8*) h.inputBuffer );  
	AddNHistory(h, inputBufferSize);           
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
void mmi_mms_retrieving_setting_inline_struct(void)
{
	mms_Tracer((char*)"^_^mmi_mms_retrieving_setting_inline_struct^_^");
	gconfig.retrieve[0] = (U8*) GetString (STR_MSG_SETTINGS_RETRIEVEMODE_AUTO);
	gconfig.retrieve[1] = (U8*) GetString (STR_MSG_SETTINGS_RETRIEVEMODE_MANUAL);

	gconfig.maxsize[0]=(U8*) GetString (STR_MMS_30K);
	gconfig.maxsize[1]=(U8*) GetString (STR_MMS_50K);
	gconfig.maxsize[2]=(U8*) GetString (STR_MMS_70K);
	gconfig.maxsize[3]=(U8*) GetString (STR_MMS_100K);	
	
	SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString (STR_MMS_SETTINGS_RETRIEVE_MODE));
	SetInlineItemActivation (&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
	SetInlineItemSelect(&wgui_inline_items[1],NUM_MMS_SETTINGS_RETRIEVE,gconfig.retrieve,&gconfig.retrieve_mode);
	CenterJustifyInlineItem(&wgui_inline_items[1]);

	SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString (STR_MMS_SETTINGS_MAX_RECEIVE));
	SetInlineItemActivation (&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
	SetInlineItemSelect (&wgui_inline_items[3], NUM_MMS_MAX_SIZE_SETTINGS,gconfig.maxsize,&gconfig.retrievesize);
	CenterJustifyInlineItem(&wgui_inline_items[3]);
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
void mmi_mms_entry_service_list_option(void)
{
	U8* guiBuffer=NULL;
	U16 numItems=0;
	U16 nStrItemList[MAX_SUB_MENUS];
	U16 itemIcons[MAX_SUB_MENUS];
	U16 screenId=SCR_ID_MMS_SETTING_SERVICE_OPTION_MENU;
	U8** pPopUpList=NULL;

	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_service_list_option, NULL);

	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(MMS_MSG_SETTINGS_SERVICE_OPTION_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(MMS_MSG_SETTINGS_SERVICE_OPTION_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_MSG_SETTINGS_SERVICE_OPTION_MENUID, itemIcons);
	
	SetParentHandler(MMS_MSG_SETTINGS_SERVICE_OPTION_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	ShowCategory52Screen(STR_GLOBAL_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						  (U8 **) pPopUpList, 0, 0,guiBuffer );
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
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
void mmi_mms_entry_service_list(void)
{
	U8* guiBuffer = NULL;
	S32 hiliteitem = 0;
	U16 setnumber=0;
	U16 screenId = SCR_ID_MMS_SETTING_SERVICE_ID_MENU;
	PU8	pservicelist[SERVICE_LIST_ITEM]={0};
	memset(servicelist,0,sizeof(servicelist));
	for(;setnumber<SERVICE_LIST_ITEM;setnumber++)
	{
		mms_read_msg_setting_file_by_index(setnumber);
		if(pfnUnicodeStrlen((S8*)gconfigtemp.service_id)==0)
		{
			pfnUnicodeStrcpy((PS8)servicelist[setnumber],(PS8)L"<");
			pfnUnicodeStrcat((PS8)servicelist[setnumber],(S8 *)GetString(STR_GLOBAL_EMPTY));
			pfnUnicodeStrcat((PS8)servicelist[setnumber],(PS8)L">");
		}
		else
		{
			pfnUnicodeStrcpy((S8*)servicelist[setnumber], (S8*)gconfigtemp.service_id);
		}
		pservicelist[setnumber]=(PU8)servicelist[setnumber];
	}

	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_service_list, NULL);
	
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
	RegisterHighlightHandler(mmi_get_index);

	if (guiBuffer)
	{
		hiliteitem = ghiliindex;
	}
	else
	{
		hiliteitem=gconfig.mms_service_activeitem;
	}
	
	ShowCategory36Screen( STR_MMS_WAP_EDIT_SETTING, IMG_MESSAGE_SIM_MMS_MENUENTRY,
						  	STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE,
						  	STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  	SERVICE_LIST_ITEM, (U8**)pservicelist, (U16)hiliteitem, guiBuffer);
	
	SetLeftSoftkeyFunction(mmi_mms_entry_service_list_option, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
}


/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_mmsc_net_setting
 *       Purpose: entry mmsc setting
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_mmsc_net_setting(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* inputBuffer;
	U16 inputBufferSize;
	U8* guiBuffer=NULL;
	U16 itemicon[MAX_SUB_MENUS];
	U16 screenId = SCR_ID_MMS_SETTING_MMSC_OPTIONS;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, 
				mmi_mms_exit_mmsc_net_setting,NULL , NULL);
	mms_Tracer((char*)"^_^mmi_mms_exit_mmsc_net_setting^_^");
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
	mmi_mms_mmsc_net_setting_inline_struct();
	
	guiBuffer = GetCurrGuiBuffer (screenId);	
	inputBuffer = GetCurrNInputBuffer(SCR_ID_MMS_SETTING_MMSC_OPTIONS, &inputBufferSize );
	if(inputBuffer != NULL)		
		SetCategory57Data(wgui_inline_items, NUM_MMS_MMSC_SETTINGS_INLINE, inputBuffer);

	ShowCategory57Screen(STR_MMS_WAP_EDIT_SETTING, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
							STR_GLOBAL_OK, NULL,
							STR_GLOBAL_BACK, NULL,
							NUM_MMS_MMSC_SETTINGS_INLINE,
							itemicon, wgui_inline_items, 0, guiBuffer);	

	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetCategory57RightSoftkeyFunctions(mmi_mms_indication_save_service_list_item,GoBackHistory);
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
void mmi_mms_exit_mmsc_net_setting(void)
{
	history	h;
	U16 		inputBufferSize;
	
	CloseCategory57Screen();
	h.scrnID = SCR_ID_MMS_SETTING_MMSC_OPTIONS;
	h.entryFuncPtr = mmi_mms_entry_mmsc_net_setting;
	GetCategoryHistory(h.guiBuffer);
	
	inputBufferSize =(U16)GetCategory57DataSize( ); 
	GetCategory57Data ((U8*) h.inputBuffer );  
	AddNHistory(h, inputBufferSize);           
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
void mmi_mms_mmsc_net_setting_inline_struct(void)
{
	int i=0;
	for (i = 0; i <  MMS_MAX_GPRS_ACCOUNT_NUM; i++)
	{
		gconfigtemp.gprs[i] = g_GPRS_DataAccount[i].DataAccountName;
	}	

	SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString (STR_MMS_WAP_MODIFY_SERVICE_ID));
	SetInlineItemActivation(&wgui_inline_items[1],KEY_LSK,KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&wgui_inline_items[1],STR_MMS_WAP_MODIFY_SERVICE_ID, 
									IMG_MESSAGE_SIM_MMS_MENUENTRY, gconfigtemp.service_id, 
									MMS_MAX_INPUT_SERVICE_ID_LENGTH, INPUT_TYPE_ALPHANUMERIC_LOWERCASE);
	SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mms_set_service_id);
 	RightJustifyInlineItem(&wgui_inline_items[1]);	
	
	SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString (STR_MMS_SETTINGS_NETWORK_CFG_MMSCENTRE));
	SetInlineItemActivation(&wgui_inline_items[3],KEY_LSK,KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&wgui_inline_items[3],STR_MMS_SETTINGS_NETWORK_CFG_MMSCENTRE, 
									IMG_MESSAGE_SIM_MMS_MENUENTRY, gconfigtemp.centre_addr, 
									MMS_MAX_INPUT_CENTRE_ADDR_LENGTH, INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
	SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mms_set_centre_address);
 	RightJustifyInlineItem(&wgui_inline_items[3]);

	SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString (STR_MMS_SETTINGS_NETWORK_CFG_GATEWAY));
	SetInlineItemActivation(&wgui_inline_items[5],KEY_LSK,KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&wgui_inline_items[5], STR_MMS_SETTINGS_NETWORK_CFG_GATEWAY, 
								IMG_MESSAGE_SIM_MMS_MENUENTRY, gconfigtemp.gateway, 
								MMS_MAX_INPUT_GATEWAY_LENGTH,INPUT_TYPE_NUMERIC_CHANGEABLE|INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
	SetInlineFullScreenEditCustomFunction(&wgui_inline_items[5], mms_set_gateway);
	RightJustifyInlineItem(&wgui_inline_items[5]);

	SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString (STR_MMS_PORT));
	SetInlineItemActivation(&wgui_inline_items[7],KEY_LSK,KEY_EVENT_UP);
	SetInlineItemFullScreenEdit(&wgui_inline_items[7],STR_MMS_PORT, 
									IMG_MESSAGE_SIM_MMS_MENUENTRY, gconfigtemp.port, 
									MMS_MAX_INPUT_PORT_LENGTH, INPUT_TYPE_NUMERIC);
	SetInlineFullScreenEditCustomFunction(&wgui_inline_items[7], mms_set_port);
 	RightJustifyInlineItem(&wgui_inline_items[7]);

	SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString (STR_MMS_SETTINGS_GPRS_MODE));
	SetInlineItemActivation (&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, KEY_EVENT_UP);
	SetInlineItemSelect (&wgui_inline_items[9], MAX_DATA_ACCOUNT_GPRS_LIMIT,gconfigtemp.gprs,&gconfigtemp.gprs_mode);
 	CenterJustifyInlineItem(&wgui_inline_items[9]);
	
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_set_service_id
 *       Purpose: 设定彩信中心地址
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_set_service_id(void)
{
	ginput_screen = INPUT_OPTION_SERVICE_ID;	
	SetLeftSoftkeyFunction(mmi_mms_entry_input_options, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

/* ----------------------------------------------------------------------------
 * Function Name: mms_set_centre_address
 *       Purpose: 设定彩信中心地址
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_set_centre_address(void)
{
	ginput_screen = INPUT_OPTION_CENTRE_ADDR;	
	SetLeftSoftkeyFunction(mmi_mms_entry_input_options, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
/* ----------------------------------------------------------------------------
 * Function Name: mms_set_gateway
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_set_gateway(void)
{
	ginput_screen = INPUT_OPTION_GATEWAY;
	SetLeftSoftkeyFunction(mmi_mms_entry_input_options, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
/* ----------------------------------------------------------------------------
 * Function Name: mms_set_port
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_set_port(void)
{
	ginput_screen = INPUT_OPTION_PORT;
	SetLeftSoftkeyFunction(mmi_mms_entry_input_options, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
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
void mms_set_frametime_validation(U8* string,S32 buffer_size)
{
	if (!(string[0] == '\0' && string[1] == '\0'))
	{
		if (!(string[0] == 48 && string[2] == 48))
		{
			if (string[2] != '\0')
			{
				if ((string[0] - 48) * 10 + (string[2] - 48) > 60)
				{
					/*提示字段内容大于60，非法，设定最大页时间*/
						memset(string,0,sizeof(string));
						pfnUnicodeStrcpy((S8*)string,(S8*)L"60");
				}
			}
			else
			{	
				if (string[0]==48)
				{
					/*输入为0 提示字段内容等于0，非法，设定默认页时间*/
					memset(string,0,sizeof(string));
					pfnUnicodeStrcpy((S8*)string,(S8*)L"5");
				}
			}
		}
		else
		{
			/*输入为00 提示字段内容等于0，非法，设定默认页时间*/
			memset(string,0,sizeof(string));
			pfnUnicodeStrcpy((S8*)string,(S8*)L"5");
		}
	}
	else
	{
		/*输入为空，提示此字段不能为空*/
		memset(string,0,sizeof(string));
		pfnUnicodeStrcpy((S8*)string,(S8*)L"5");
	}
	return ;
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_indication_save_service_list_item
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_indication_save_service_list_item(void)
{
	if(mmi_mms_judge_mms_setting() == 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_SETTING_ERROR), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return;
	}		
	mmi_mms_display_confirm((UI_string_type)get_string(STR_MMS_SETTING_SAVE),
					mms_message_save_service_list_item_confirm, mms_message_no_save_service_list_item);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_judge_mms_setting
 *       Purpose: judge mms setting 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int mmi_mms_judge_mms_setting(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	U8 tempgateport[65] = {0};
	sockaddr_struct sock_addr_temp;

	cms_memset(&sock_addr_temp,0x00,sizeof(sockaddr_struct));
	while (gconfigtemp.gateway[i*2] != NULL)
	{
		if (gconfigtemp.gateway[i*2] != '.')
		{
			tempgateport[j] = gconfigtemp.gateway[i*2];
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
	while (gconfigtemp.port[i*2] != NULL)
	{
		tempgateport[i] = gconfigtemp.port[i*2]; 
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
/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_message_save_service_list_item_confirm(void)
{
	mms_write_msg_setting_file_by_index(ghiliindex);
	ExitDisplayPopupConfirm();
	if(IsScreenPresent(SCR_ID_MMS_SETTING_SERVICE_ID_MENU))
	{
		GoBackToHistory(SCR_ID_MMS_SETTING_SERVICE_ID_MENU);
	}
	else
	{
		GoBackHistory();
	}
	if(gconfig.mms_service_activeitem==ghiliindex)
	{
		mms_set_curr_file_to_setting();
	}
	else
	{
		DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	}
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
void mms_message_no_save_service_list_item(void)
{
	if(IsScreenPresent(SCR_ID_MMS_SETTING_SERVICE_ID_MENU))
	{
		GoBackToHistory(SCR_ID_MMS_SETTING_SERVICE_ID_MENU);
	}
	else
	{
		GoBackHistory();
	}
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
void mmi_mms_indication_save_mms_setting(void)
{
	mms_Tracer((char*)"^_^mmi_mms_indication_save_mms_setting^_^");
	mmi_mms_display_confirm((UI_string_type)get_string(STR_MMS_SETTING_SAVE),
							mms_message_settings_confirm, mms_message_settings_no_save);
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
void mms_message_settings_confirm(void)
{
	mms_Tracer((char*)"^_^mms_message_settings_confirm^_^");
	mms_write_message_settings_file();
	ExitDisplayPopupConfirm();
	if(IsScreenPresent(SCR_ID_MMS_SETTING_MENU))
	{
		GoBackToHistory(SCR_ID_MMS_SETTING_MENU);
	}
	else
	{
		GoBackHistory();
	}
	DisplayPopup((U8*)GetString(STR_SAVE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);

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
void mms_message_settings_no_save(void)
{
	mms_init_message_settings();
	if(IsScreenPresent(SCR_ID_MMS_SETTING_MENU))
	{
		GoBackToHistory(SCR_ID_MMS_SETTING_MENU);
	}
	else
	{
		GoBackHistory();
	}
}
/*--------------------------------- mms memory status -----------------------------*/

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_view_memory_status
 *       Purpose: view memory use status
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_view_memory_status(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 	guiBuffer=NULL;		/* Buffer holding history data */
	U16	 	screenId=SCR_ID_MMS_MEMORY_STATUS;
	S32		str_len = 0;
	U16 		count = 0,wapcount=0;
	S32 		msize = 0;
	float		resize=0;
	float		total_msg_mun = 0;
	S32		total_msg_size = 0;
	char		ansiiTempBuff[MAX_SHOW_STRING_BUF/2];
	char		ucs2TempBuff[MAX_SHOW_STRING_BUF];

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_view_memory_status, NULL);
		
	total_msg_mun = MAX_MESSAGE_COUNT;
	total_msg_size = MAX_SIZE_ALL_MMS/1024;
	mms_get_all_boxes_count_size(&count, &msize);
	
	memset(UnicodeBuf,0,sizeof(UnicodeBuf));

#ifdef SUPPORT_SMSMMS_COMBINE
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_CMS_MMS_MENUENTRY));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)L"\n");
#else
	pfnUnicodeStrcpy((PS8)UnicodeBuf,(PS8)L"\n");
#endif	
	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_MMS_NUM_USAGE ));
	sprintf( (S8 *)ansiiTempBuff, ": %d/%d\n", (int)count,(int)total_msg_mun);
	memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
	resize=(float)msize;
	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_MMS_MEMORY_USED ));
	sprintf( (S8 *)ansiiTempBuff, ": %.1f K\n",(float)(resize/1024));
	memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);

	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_MMS_MEMORY_REMAIN ));
	if(total_msg_size>=0){
		sprintf( (S8 *)ansiiTempBuff, ": %.1f K\n",(float)(total_msg_size));
	}else{
		sprintf( (S8 *)ansiiTempBuff, ": %.1f K\n",(float)(0));
	}
	
	memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);


#ifdef SUPPORT_SMSMMS_COMBINE
	wapcount=mmi_wapmms_inbox_get_push_count();
	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)L"\n");
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString( STR_MMS_WAP_PUSH_MESSAGE));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)L"\n");
	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_NUM_USAGE));
	sprintf( (S8 *)ansiiTempBuff, ": %d/%d\n",(int)wapcount,CMS_MAX_PUSH);
	memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
	
#endif

	str_len=pfnUnicodeStrlen((PS8)UnicodeBuf);

	
	guiBuffer = GetCurrGuiBuffer(screenId);
	SetMessagesCurrScrnID(screenId);

	ShowCategory74Screen(STR_MMS_MEMORY_STATUS,IMG_MESSAGE_SIM_MMS_MENUENTRY,
						NULL,NULL,STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						(PU8)UnicodeBuf, str_len, guiBuffer);
	
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#ifdef __MMI_TOUCH_SCREEN__

/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_pen_down_hdlr(mmi_pen_point_struct pos)
{
	U16 		x, y;
	U32 		index;
	MMI_BOOL 	ret=MMI_FALSE;
	U16			scr_ID = GetMessagesCurrScrnID();

	mmi_gui_scrollbar_pen_enum scrollbar_event; 
	mmi_gui_pen_event_param_struct scrollbar_param;		
	x = pos.x;
	y = pos.y;
	if ( PEN_CHECK_BOUND (x, y, play_show_vbar.x, play_show_vbar.y, play_show_vbar.width, play_show_vbar.height) )
	{
		index = play_show_vbar.value;
		pixtel_UI_vertical_scrollbar_translate_pen_event(&play_show_vbar, MMI_PEN_EVENT_DOWN, x, y, &scrollbar_event, &scrollbar_param);

		if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
		{
			if((S32) scrollbar_param._u.i > index)
			{
				if(scr_ID==SCR_ID_MMS_PREVIEW_MESSAGE)
				{
					mmi_mms_play_down_frame();
				}
				else
				{
					mmi_mms_edit_down_frame();
				}			
			}
			else
			{
				if(scr_ID==SCR_ID_MMS_PREVIEW_MESSAGE)
				{
					mmi_mms_play_up_frame();
				}
				else
				{
					mmi_mms_edit_up_frame();
				}
			}
		}
		ret = MMI_TRUE;
	}
	
	if (MMI_FALSE == ret)
   	{
     		 mmi_wgui_general_pen_down_hdlr(pos);
   	}
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
void mmi_mms_pen_up_hdlr(mmi_pen_point_struct pos)
{
	U16 		x, y;
	U32 		index;
	MMI_BOOL 	ret=MMI_FALSE;
	U16			scr_ID = GetMessagesCurrScrnID();

	mmi_gui_scrollbar_pen_enum scrollbar_event; 
	mmi_gui_pen_event_param_struct scrollbar_param;		
	x = pos.x;
	y = pos.y;
	if ( PEN_CHECK_BOUND (x, y, play_show_vbar.x, play_show_vbar.y, play_show_vbar.width, play_show_vbar.height) )
	{
		index = play_show_vbar.value;
		pixtel_UI_vertical_scrollbar_translate_pen_event(&play_show_vbar, MMI_PEN_EVENT_UP, x, y, &scrollbar_event, &scrollbar_param);
		if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
		{
			if((S32) scrollbar_param._u.i > index)
			{
				if(scr_ID==SCR_ID_MMS_PREVIEW_MESSAGE)
				{
					mmi_mms_play_down_frame();
				}
				else
				{
					mmi_mms_edit_down_frame();
				}			
			}
			else
			{
				if(scr_ID==SCR_ID_MMS_PREVIEW_MESSAGE)
				{
					mmi_mms_play_up_frame();
				}
				else
				{
					mmi_mms_edit_up_frame();
				}
			}
		}
		ret = MMI_TRUE;
	}
	
	if (MMI_FALSE == ret)
   	{
     		 mmi_wgui_general_pen_up_hdlr(pos);
   	}
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
 void mmi_mms_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
	U16 		x, y;
	U32 		index;
	MMI_BOOL 	ret=MMI_FALSE;
	U16			scr_ID = GetMessagesCurrScrnID();

	mmi_gui_scrollbar_pen_enum scrollbar_event; 
	mmi_gui_pen_event_param_struct scrollbar_param;		
	x = pos.x;
	y = pos.y;
	if ( PEN_CHECK_BOUND (x, y, play_show_vbar.x, play_show_vbar.y, play_show_vbar.width, play_show_vbar.height) )
	{
		index = play_show_vbar.value;
		pixtel_UI_vertical_scrollbar_translate_pen_event(&play_show_vbar, MMI_PEN_EVENT_REPEAT, x, y, &scrollbar_event, &scrollbar_param);

		if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
		{
			if((S32) scrollbar_param._u.i > index)
			{
				if(scr_ID==SCR_ID_MMS_PREVIEW_MESSAGE)
				{
					mmi_mms_play_down_frame();
				}
				else
				{
					mmi_mms_edit_down_frame();
				}			
			}
			else
			{
				if(scr_ID==SCR_ID_MMS_PREVIEW_MESSAGE)
				{
					mmi_mms_play_up_frame();
				}
				else
				{
					mmi_mms_edit_up_frame();
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
 /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void mmi_mms_pen_move_hdlr(mmi_pen_point_struct pos)
{
	U16 		x, y;
	U32 		index;
	MMI_BOOL ret=MMI_FALSE;
	U16		scr_ID = GetMessagesCurrScrnID();
	mmi_gui_scrollbar_pen_enum scrollbar_event; 
	mmi_gui_pen_event_param_struct scrollbar_param;		
	x = pos.x;
	y = pos.y;
	if ( PEN_CHECK_BOUND (x, y, play_show_vbar.x, play_show_vbar.y, play_show_vbar.width, play_show_vbar.height) )
	{
		index = play_show_vbar.value;
		pixtel_UI_vertical_scrollbar_translate_pen_event(&play_show_vbar, MMI_PEN_EVENT_MOVE, x, y, &scrollbar_event, &scrollbar_param);

		if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
		{
			if((S32) scrollbar_param._u.i > index)
			{
				if(scr_ID==SCR_ID_MMS_PREVIEW_MESSAGE)
				{
					mmi_mms_play_down_frame();
				}
				else
				{
					mmi_mms_edit_down_frame();
				}			
			}
			else
			{
				if(scr_ID==SCR_ID_MMS_PREVIEW_MESSAGE)
				{
					mmi_mms_play_up_frame();
				}
				else
				{
					mmi_mms_edit_up_frame();
				}
			}
		}
		
		ret = MMI_TRUE;
	}
	else
	{
        		pixtel_UI_vertical_scrollbar_translate_pen_event(&play_show_vbar, MMI_PEN_EVENT_MOVE, x, y, &scrollbar_event, &scrollbar_param);
	}
    
	if (MMI_FALSE == ret)
   	{
     		 mmi_wgui_general_pen_move_hdlr(pos);
   	}
}

#endif


#if 1

/*--------------------------------- highlight setting -----------------------------*/

/*****************************************************************************
 * Function Name: mmi_mms_highlight_generic
 *       Purpose:  Highlight generic function for mms app
 *         Input: 
 *  			a  IN		left soft key function
 *  			b IN			right soft key function
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
*****************************************************************************/
void mmi_mms_highlight_generic (FuncPtr lskfunc, FuncPtr rskfunc)
{
	SetLeftSoftkeyFunction(lskfunc, KEY_EVENT_UP);
//	SetKeyHandler(rskfunc, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
//	SetKeyHandler(lskfunc, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*-----------------------------------------------------------------------------*/
/* 彩信支持短彩合一                                                    */
/*-----------------------------------------------------------------------------*/

#ifdef SUPPORT_SMSMMS_COMBINE
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_highlight_new_sms_mms
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void mmi_mms_highlight_new_sms_mms (void)
{    
	mmi_mms_highlight_generic(mmi_mms_entry_new_sms_mms,GoBackHistory);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_highlight_sms_mms_templates
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void mmi_mms_highlight_sms_mms_templates (void)
{    
	mmi_mms_highlight_generic(mmi_mms_entry_sms_mms_template,GoBackHistory);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_highlight_sms_mms_setting
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void mmi_mms_highlight_sms_mms_setting (void)
{    
	mmi_mms_highlight_generic(mmi_mms_entry_sms_mms_setting,GoBackHistory);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_highlight_sms_mms_memory_status
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void mmi_mms_highlight_sms_mms_memory_status(void)
{    
	mmi_mms_highlight_generic(mmi_mms_entry_sms_mms_memory_status,GoBackHistory);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_highlight_wap_push_link
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void mmi_mms_highlight_wap_push_link(void)
{    
	P_MESSAGELIST pMsg = NULL;
	pMsg = mms_file_manager_get_current_message();
	if(pMsg->msgtype==MESSAGE_OTA_BOOKMARK)
	{
		mmi_mms_highlight_generic(mms_wap_ota_add_bookmark,GoBackHistory);	
	}
	else if(pMsg->msgtype==MESSAGE_OTA_SET)
	{
		if(pMsg->ota_murl!=NULL&&(strlen(pMsg->ota_murl)>0)){
			mms_Tracer("mms ota push");
			mmi_mms_highlight_generic(mmi_mms_ota_to_setting_list,GoBackHistory);
		}
		else{
			mms_Tracer("wap ota push");
			mmi_mms_highlight_generic(mmi_mms_wap_ota_to_setting_list,GoBackHistory);
		}
	}
	else
	{
		mmi_mms_highlight_generic(MMS_PushLinkBrowser,GoBackHistory);
	}
}

#endif
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_highlight_new_msg
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_highlight_new_msg(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_new_message,GoBackHistory);
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
void mmi_mms_highlight_inbox(void)
{
#ifdef SUPPORT_SMSMMS_COMBINE
	mmi_mms_highlight_generic(mmi_msg_pre_entry_inbox_list,GoBackHistory);
#else
	mmi_mms_highlight_generic(mmi_mms_entry_inbox,GoBackHistory);
#endif
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
void mmi_mms_highlight_outbox(void)
{
#ifdef SUPPORT_SMSMMS_COMBINE
	mmi_mms_highlight_generic(mmi_msg_pre_entry_outbox_list,GoBackHistory);
#else
	mmi_mms_highlight_generic(mmi_mms_entry_outbox,GoBackHistory);
#endif
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
void mmi_mms_highlight_draftbox(void)
{
#ifdef SUPPORT_SMSMMS_COMBINE
	mmi_mms_highlight_generic(mmi_msg_pre_entry_draftbox_list,GoBackHistory);
#else
	mmi_mms_highlight_generic(mmi_mms_entry_draftbox,GoBackHistory);
#endif
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
void mmi_mms_highlight_empty_box(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_empty_box,GoBackHistory);
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
void mmi_mms_highlight_setting(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_mms_setting,GoBackHistory);
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
void mmi_mms_highlight_memoty_status(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_view_memory_status,GoBackHistory);
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
void mmi_mms_highlight_add_to(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_to_option_or_list,GoBackHistory);
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
void mmi_mms_highlight_add_cc(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_cc_option_or_list,GoBackHistory);
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
void mmi_mms_highlight_add_bcc(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_bcc_option_or_list,GoBackHistory);
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
void mmi_mms_highlight_subject(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_subject_input,GoBackHistory);
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
void mmi_mms_highlight_edit_content(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_edit_message,GoBackHistory);
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
void mmi_mms_highlight_send_options(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_send_options,GoBackHistory);
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
void mmi_mms_highlight_send(void)
{
	mmi_mms_highlight_generic(mms_before_send_message,GoBackHistory);
	mmsflag.gsend_save=FALSE;
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
void mmi_mms_highlight_draftbox_send(void)
{
	mmi_mms_highlight_generic(mms_before_draftbox_send_message,GoBackHistory);
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
void mmi_mms_highlight_draftbox_send_and_save(void)
{
	mmi_mms_highlight_generic(mms_before_draftbox_send_and_save,GoBackHistory);
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
void mmi_mms_highlight_add_number_input(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_phone_number,GoBackHistory);
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
void mmi_mms_highlight_add_email_input(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_email,GoBackHistory);
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
void mmi_mms_highlight_amend_sendto(void)
{
	mms_Tracer((char *)"EntryNewScreen mmi_mms_entry_amend_sendto");
	mmi_mms_highlight_generic(mmi_mms_entry_pre_amend_sendto,GoBackHistory);
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
void mmi_mms_highlight_del_sendto(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_del_sendto,GoBackHistory);
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
void mmi_mms_highlight_del_all_sendto(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_del_all_sendto,GoBackHistory);
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
void mmi_mms_highlight_edit_text(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_edit_text_input,GoBackHistory);
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
void mmi_mms_highlight_add_image(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_image_folder,GoBackHistory);
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
void mmi_mms_highlight_add_music(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_music_folder,GoBackHistory);
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
void mmi_mms_highlight_add_accessory(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_accessory_folder,GoBackHistory);
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
void mmi_mms_highlight_set_frametime(void)
{
	mmi_mms_highlight_generic(mmi_mms_edit_pre_set_frame_time,GoBackHistory);
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
void mmi_mms_highlight_del_image(void)
{
	mmi_mms_highlight_generic(mmi_mms_edit_delete_image,GoBackHistory);
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
void mmi_mms_highlight_del_music(void)
{
	mmi_mms_highlight_generic(mmi_mms_edit_delete_music,GoBackHistory);
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
void mmi_mms_highlight_del_accessory(void)
{
	mmi_mms_highlight_generic(mmi_mms_edit_delete_accessory,GoBackHistory);
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
void mmi_mms_highlight_new_frame(void)
{
	mmi_mms_highlight_generic(mmi_mms_edit_new_frame,GoBackHistory);
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
void mmi_mms_highlight_del_frame(void)
{
	mmi_mms_highlight_generic(mmi_mms_edit_delete_frame,GoBackHistory);
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
void mmi_mms_highlight_empty_text(void)
{
	mmi_mms_highlight_generic(mmi_mms_edit_empty_text,GoBackHistory);
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
void mmi_mms_highlight_next_frame(void)
{
	mmi_mms_highlight_generic(mmi_mms_play_next_frame,GoBackHistory);
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
void mmi_mms_highlight_pre_frame(void)
{
	mmi_mms_highlight_generic(mmi_mms_edit_previous_frame,GoBackHistory);
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
void mmi_mms_highlight_inbox_push_download(void)
{
	mms_Tracer("mmi_mms_highlight_inbox_push_download in ");
	mmi_mms_highlight_generic(mms_before_retrieve_message,GoBackHistory);
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
void mmi_mms_highlight_play(void)
{
	mmi_mms_highlight_generic(mmi_mms_play_message,GoBackHistory);
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
void mmi_mms_highlight_box_play(void)
{
	mms_Tracer((char*)"mmi_mms_highlight_box_play");
	mmi_mms_highlight_generic(mmi_mms_post_play_message,GoBackHistory);
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
void mmi_mms_highlight_reply(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_reply,GoBackHistory);
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
void mmi_mms_highlight_details(void)
{
	mmi_mms_highlight_generic(mmi_mms_view_msg_detail,GoBackHistory);
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
void mmi_mms_highlight_outbox_send(void)
{
	mmi_mms_highlight_generic(mms_before_box_send_message,GoBackHistory);
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
void mmi_mms_highlight_forward(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_forward,GoBackHistory);
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
void mmi_mms_highlight_save_image(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_inbox_save_image,GoBackHistory);
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
void mmi_mms_highlight_save_music(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_inbox_save_music,GoBackHistory);
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
void mmi_mms_highlight_save_accessory(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_inbox_save_accessory,GoBackHistory);
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
void mmi_mms_highlight_get_number(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_inbox_get_phone_number_list,GoBackHistory);
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
void mmi_mms_highlight_dial_number(void)
{
	mms_Tracer("mmi_mms_highlight_dial_number");
	mmi_mms_highlight_generic(mmi_mms_dial_use_number,GoBackHistory);
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
void mmi_mms_highlight_save_number(void)
{
	mms_Tracer("mmi_mms_highlight_save_number");
	mmi_mms_highlight_generic(mms_save_phone_number_confirm,GoBackHistory);
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
void mmi_mms_highlight_draftbox_edit(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_draftbox_edit_content,GoBackHistory);
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
void mmi_mms_highlight_del(void)
{
	mmi_mms_highlight_generic(mmi_mms_indication_delete_message,GoBackHistory);
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
void mmi_mms_highlight_del_all(void)
{
	mmi_mms_highlight_generic(mmi_mms_indication_delete_all_messages,GoBackHistory);
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
void mmi_mms_highlight_save_send(void)
{
	mmi_mms_highlight_generic(mmi_mms_send_and_save_message,GoBackHistory);
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
void mmi_mms_highlight_save(void)
{
	mmi_mms_highlight_generic(mmi_mms_save_message,GoBackHistory);
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
void mmi_mms_highlight_setting_sending(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_send_message_setting,GoBackHistory);
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
void mmi_mms_highlight_template(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_templates,GoBackHistory);
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
void mmi_mms_highlight_template_preview(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_template_preview,GoBackHistory);
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
void mmi_mms_highlight_template_details(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_template_details,GoBackHistory);
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
void mmi_mms_highlight_template_write_message(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_template_write_message,GoBackHistory);
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
void mmi_mms_highlight_setting_retrieving(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_retrieving_message_setting,GoBackHistory);
	mms_Tracer((char*)"^_^mmi_mms_highlight_setting_retrieving^_^");
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
void mmi_mms_highlight_empty_inbox(void)
{
	mmi_mms_highlight_generic(mmi_mms_indication_empty_inbox,GoBackHistory);
}/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_highlight_empty_outbox(void)
{
	mmi_mms_highlight_generic(mmi_mms_indication_empty_outbox,GoBackHistory);
}/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_highlight_empty_draftbox(void)
{
	mmi_mms_highlight_generic(mmi_mms_indication_empty_draftbox,GoBackHistory);
}/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_highlight_empty_allbox(void)
{
	mmi_mms_highlight_generic(mmi_mms_indication_empty_allbox,GoBackHistory);
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
void mmi_mms_highlight_setting_edit_option(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_service_list,GoBackHistory);
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
void mmi_mms_highlight_setting_edit_option_activate(void)
{
	mmi_mms_highlight_generic(mms_set_curr_file_to_setting,GoBackHistory);
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
void mmi_mms_highlight_setting_edit_option_edit(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_mmsc_net_settingcheck,GoBackHistory);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_mmsc_net_settingcheck
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_mmsc_net_settingcheck(void)
{
	mms_read_msg_setting_file_by_index(ghiliindex);
	DataAccountReadyCheck((FuncPtr)mmi_mms_entry_mmsc_net_setting);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_mmsc_net_settingcheck
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */

extern U16 g_phb_name_index[MAX_PB_ENTRIES];
void mmi_extern_entry_op_send_mms(void)
{
	U16 store_index=0;
	U8 tempNumber[MMS_MAX_FILE_NAME_LENGTH];
	

	store_index = g_phb_name_index[g_phb_cntx.active_index];
	if(store_index>=0)
	{
		mmi_phb_convert_get_ucs2_number(tempNumber, store_index);
		mmi_mms_extern_entry_new_mms(NULL,tempNumber);
	}

}

void mmi_extern_highlight_op_send_mms(void)
{
	mmi_mms_highlight_generic(mmi_extern_entry_op_send_mms,GoBackHistory);
}
#endif	 

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_inbox_hint
 *       Purpose: get hint for inbox on main mms screen and empty box screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_inbox_hint(U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16    number = 0;
	U8     ansiiTempBuff[MAX_HINT_BUF];
 	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset((PS8)hintData[index], 0, sizeof(hintData[index]));
	mms_mmi_tracer("the hint data len=%d", sizeof(hintData[index]));
	number = pgManager->receiveFolder->messageNumber;
	
	if (number < 0)
	{
		return;
	}
	else
	{
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		sprintf( (S8 *) ansiiTempBuff, "%d ", number);
		AnsiiToUnicodeString( (PS8)hintData[index], (PS8)ansiiTempBuff );
		pfnUnicodeStrcat((PS8)hintData[index],(S8 *)GetString( STR_MMS_HINT_MESSAGES ));
	}
	return;
	
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_outbox_hint
 *       Purpose: get hint for outbox on main mms screen and empty box screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_outbox_hint(U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16     number = 0;
	U8     ansiiTempBuff[MAX_HINT_BUF];

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset((PS8)hintData[index], 0, sizeof(hintData[index]));	
	number = pgManager->sendFolder->messageNumber;
	
	if (number < 0)
	{
		return;
	}
	else
	{
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		sprintf( (S8 *) ansiiTempBuff, "%d ", number);
		AnsiiToUnicodeString( (PS8)hintData[index], (PS8)ansiiTempBuff );
		pfnUnicodeStrcat((PS8)hintData[index],(S8 *)GetString( STR_MMS_HINT_MESSAGES ));
	}
	return;
	
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_draftbox_hint
 *       Purpose: get hint for draftbox on main mms screen and empty box screen
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_draftbox_hint(U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16     number = 0;
	U8     ansiiTempBuff[MAX_HINT_BUF];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset((PS8)hintData[index], 0, sizeof(hintData[index]));
	number = pgManager->draftFolder->messageNumber;
	
	if (number <0)
	{
		return;
	}
	else
	{
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		sprintf( (S8 *) ansiiTempBuff, "%d ", number);
		AnsiiToUnicodeString( (PS8)hintData[index], (PS8)ansiiTempBuff );
		pfnUnicodeStrcat((PS8)hintData[index],(S8 *)GetString( STR_MMS_HINT_MESSAGES ));
	}
	return;
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
void mmi_mms_to_hint(U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16   count = 0;
	U8     ucs2TempBuff[MAX_HINT_BUF];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));
	count = cms_get_sendtolist_count(SENDTO_TO);
	
	if (count == 1)
	{	
		AnsiiToUnicodeString( (PS8)hintData[index], (s8 *)pgsendtolist->number);
	}
	else if(count>1||count==0)
	{
		sprintf( (S8 *) ucs2TempBuff, "%d ", count);
		AnsiiToUnicodeString( (PS8)hintData[index], (PS8)ucs2TempBuff );
		pfnUnicodeStrncat((PS8)hintData[index],(S8 *)GetString( STR_MMS_HINT_RECEIVER),32);
	}
	return;
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
void mmi_mms_cc_hint(U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16   count = 0;
	U8     ucs2TempBuff[MAX_HINT_BUF];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));
	count = cms_get_sendtolist_count(SENDTO_CC);
	
	if (count == 1)
	{	
		AnsiiToUnicodeString( (PS8)hintData[index], (s8 *)pgsendcclist->number);
	}
	else if(count>1||count==0)
	{
		sprintf( (S8 *) ucs2TempBuff, "%d ", count);
		AnsiiToUnicodeString( (PS8)hintData[index], (PS8)ucs2TempBuff );
		pfnUnicodeStrncat((PS8)hintData[index],(S8 *)GetString( STR_MMS_HINT_RECEIVER),32);
	}
	return;
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
void mmi_mms_bcc_hint(U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16   count = 0;
	U8     ucs2TempBuff[MAX_HINT_BUF];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));
	count = cms_get_sendtolist_count(SENDTO_BCC);
	
	if (count == 1)
	{	
		AnsiiToUnicodeString( (PS8)hintData[index], (s8 *)pgsendbcclist->number);
	}
	else if(count>1||count==0)
	{
		sprintf( (S8 *) ucs2TempBuff, "%d ", count);
		AnsiiToUnicodeString( (PS8)hintData[index], (PS8)ucs2TempBuff );
		pfnUnicodeStrncat((PS8)hintData[index],(S8 *)GetString( STR_MMS_HINT_RECEIVER),32);
	}
	return;
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
void mmi_mms_subject_hint(U16 index)
{
	memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));
	if(pfnUnicodeStrlen((S8*)gedit.sub_buf)==0)
	{
		pfnUnicodeStrcpy(( PS8 ) hintData[(index)], GetString(STR_NO_SUBJECT));
	}
	else
	{
		pfnUnicodeStrncpy(( PS8 ) hintData[(index)], (char*)gedit.sub_buf,40);
	}
	return;
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
void mmi_mms_content_hint(U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	float 	resize = 0;
	char		ansiiTempBuff[MAX_HINT_BUF*2];
	char		ucs2TempBuff[MAX_HINT_BUF*2];
	U16  	slide_count = MMSGetSlideCount(gpeditor_doc);
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));
	
	if (slide_count <= 0)
	{
		pfnUnicodeStrcpy(( PS8 ) hintData[(index)], GetString(STR_GLOBAL_EMPTY));
		return;
	}
	else if(slide_count > 0)	
	{
		resize = (float)gpeditor_doc->totalsize;
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		sprintf(ansiiTempBuff, "%d ", slide_count);
		AnsiiToUnicodeString( (PS8)hintData[index], (PS8)ansiiTempBuff );
		pfnUnicodeStrcat((PS8)hintData[index],(S8 *)GetString( STR_MMS_HINT_FRAMES));
	
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
		sprintf(ansiiTempBuff,"(%.1f K)", (float)(resize/1024));
		AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
		pfnUnicodeStrcat((PS8)hintData[index],(S8 *)ucs2TempBuff);
	}
	return;
	
}
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_image_list_get_item
 *       Purpose: 获取待保存图片列表项
 *         Input:  item_index: 列表项序号	str_buff: 显示的字符串 
 *  			  img_buff_p: 图标icon	str_img_mask: 
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
pBOOL mmi_image_list_get_item(S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 		num = 0, i = 0;
	char		ansiiTempBuff[MAX_HINT_BUF];
	char		ucs2TempBuff[MAX_HINT_BUF];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	pMMS_Slide slide = gpeditor_doc->slide_root;
	while (slide && i <= item_index)
	{
		if (slide->image_flag == 1)
		{
			i++;
		}
		slide = slide->next;
		num++;
	}
	
	pfnUnicodeStrcpy((S8*)str_buff, (const char*)GetString(STR_MMS_SLIDE_NUM));
	sprintf(ansiiTempBuff," %d ",(int)num);
	AnsiiToUnicodeString ((S8*)ucs2TempBuff, ansiiTempBuff);
	pfnUnicodeStrcat((S8*)str_buff, (const char*)ucs2TempBuff);
	pfnUnicodeStrcat((S8*)str_buff, (const char*)GetString(STR_MMS_FRAME));		
	
	*img_buff_p = (UI_image_type)GetImage(IMG_GLOBAL_L1 + item_index);

	return TRUE;

}
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_accessory_list_get_item
 *       Purpose: 获取待保存附件列表项
 *         Input:  item_index: 列表项序号	str_buff: 显示的字符串 
 *  			  acc_buff_p: 图标icon	str_acc_mask: 
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
pBOOL mmi_accessory_list_get_item(S32 item_index, UI_string_type str_buff, UI_image_type* acc_buff_p, U8 str_acc_mask)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 		num = 0, i = 0;
	char		ansiiTempBuff[MAX_HINT_BUF];
	char		ucs2TempBuff[MAX_HINT_BUF];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	pMMS_Slide slide = gpeditor_doc->slide_root;
	while (slide && i <= item_index)
	{
		if (slide->accessory_flag == 1)
		{
			i++;
		}
		slide = slide->next;
		num++;
	}
	
	pfnUnicodeStrcpy((S8*)str_buff, (const char*)GetString(STR_MMS_SLIDE_NUM));
	sprintf(ansiiTempBuff," %d ",(int)num);
	AnsiiToUnicodeString ((S8*)ucs2TempBuff, ansiiTempBuff);
	pfnUnicodeStrcat((S8*)str_buff, (const char*)ucs2TempBuff);
	pfnUnicodeStrcat((S8*)str_buff, (const char*)GetString(STR_MMS_FRAME));		
	
	*acc_buff_p = (UI_image_type)GetImage(IMG_GLOBAL_L1 + item_index);

	return TRUE;

}
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_image_list_get_hint
 *       Purpose: 获取待保存图片列表项hint信息
 *         Input: item_index: 列表项序号	*hint_array: hint信息字符串
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
S32 mmi_image_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
	*hint_array = NULL;
	return 1;
}
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_accessory_list_get_hint
 *       Purpose: 获取待保存附件列表项hint信息
 *         Input: item_index: 列表项序号	*hint_array: hint信息字符串
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
S32 mmi_accessory_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
	*hint_array = NULL;
	return 1;
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_image_list_get_item
 *       Purpose: 获取待保存音乐列表项
 *         Input:  item_index: 列表项序号	str_buff: 显示的字符串
 *  			  img_buff_p: 图标icon	str_img_mask: 
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
pBOOL mmi_music_list_get_item(S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 		num = 0, i = 0;
	char		ansiiTempBuff[MAX_HINT_BUF];
	char		ucs2TempBuff[MAX_HINT_BUF];

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	pMMS_Slide slide = gpeditor_doc->slide_root;
	while (slide && i <= item_index)
	{
		if (slide->audiosize > 0)
		{
			i++;
		}
		slide = slide->next;
		num++;
	}

	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	pfnUnicodeStrcpy((S8*)str_buff, (const char*)GetString(STR_MMS_SLIDE_NUM));
	sprintf(ansiiTempBuff," %d ",(int)num);
	AnsiiToUnicodeString ((S8*)ucs2TempBuff, ansiiTempBuff);
	pfnUnicodeStrcat((S8*)str_buff, (const char*)ucs2TempBuff);
	pfnUnicodeStrcat((S8*)str_buff, (const char*)GetString(STR_MMS_FRAME));		
	
	*img_buff_p = (UI_image_type)GetImage(IMG_GLOBAL_L1 + item_index);

	return TRUE;

}
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_music_list_get_hint
 *       Purpose: 获取待保存音乐列表项hint信息
 *         Input: item_index: 列表项序号	*hint_array: hint信息字符串
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
S32 mmi_music_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
	*hint_array = NULL;
	return 1;
}
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_sendto_list_get_item
 *       Purpose:   获取收件人列表项
 *         Input:		item_index: 列表项序号	*hint_array: hint信息字符串
 *  				*img_buff_p: 图标icon	str_img_mask: 
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
pBOOL mmi_sendto_list_get_item(S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 				i = 0;
	char* 			str = NULL;
	PS8  			name;
	pSENDTO_LIST	plist = NULL;
	U8     			ucs2TempBuff[MMS_MAX_SEND_TO_SIZE];
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch (gsendto_options)
      {
           case SENDTO_TO:
		   	plist = pgsendtolist;
			break;
	    case SENDTO_CC:
			plist = pgsendcclist;
                    break;
		case SENDTO_BCC:
			plist = pgsendbcclist;
			break;	
           default :
		   	break;
	}
	for (; i < item_index; i++)
	{
		plist = plist->next;
	}
	
	str = plist->number;
	mms_mmi_tracer("sendto_list==item_index==%d", (char*)item_index);

	AnsiiToUnicodeString((S8*)ucs2TempBuff,(S8*)str);
	name = lookUpNumber((PS8)ucs2TempBuff);
	if (name  &&  pfnUnicodeStrlen(name))
	{
		pfnUnicodeStrcpy((S8*)str_buff, (S8*)name);	
	}
	else
	{
		pfnUnicodeStrcpy((S8*)str_buff, (S8*)ucs2TempBuff);
	}

	*img_buff_p = (UI_image_type)GetImage(IMG_GLOBAL_L1 + item_index);

	return TRUE;

}
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_sendto_list_get_hint
 *       Purpose:获取收件人列表项hint信息
 *         Input: item_index: 列表项序号	*hint_array: hint信息字符串
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
S32 mmi_sendto_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 		i = 0;
	PS8  	name;
	char		ucs2TempBuff[MMS_MAX_SEND_TO_SIZE];
	pSENDTO_LIST plist = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch (gsendto_options)
      {
           case SENDTO_TO:
		   	plist = pgsendtolist;
			break;
	    case SENDTO_CC:
			plist = pgsendcclist;
                    break;
		case SENDTO_BCC:
			plist = pgsendbcclist;
			break;	
           default :
		   	break;
	}
	for (; i < item_index; i++)
	{
		plist = plist->next;
	}
	
	AnsiiToUnicodeString((S8*)ucs2TempBuff,(S8*)plist->number);
	name = lookUpNumber(ucs2TempBuff);	
	if (name  &&  pfnUnicodeStrlen(name))
	{
		pfnUnicodeStrcpy((S8*)hint_array[0], (S8*)ucs2TempBuff);	
		return 1;		
	}
	else
	{
		return 0;
	}

}
 
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_box_list_get_item
 *       Purpose:   获取信箱列表项(即彩信或彩信通知信息)
 *         Input:		item_index: 列表项序号	*hint_array: hint信息字符串
 *  				*img_buff_p: 图标icon	str_img_mask: 
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
pBOOL mmi_box_list_get_item(S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	char *	 	str = NULL;
	char* 		temp = NULL;
	int			l = 0;
	PS8 			name;
	P_MESSAGELIST message = NULL;
	U8 type;
        U16 index;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_Tracer("enter mmi_box_list_get_item");
	message = pgManager->currentFolder->root;
	
	for (;l < item_index && message; l++)
	{
		message = message->next;
	}
	
#ifdef SUPPORT_SMSMMS_COMBINE
	if( message->msgtype==MESSAGE_SMS)
	{
	    	mmi_frm_sms_get_sms_list_index(&type,&index,message->SmsIndex);
			
		if (pgManager->currentFolder == pgManager->receiveFolder)
		{
			mmi_msg_inbox_list_get_item(index,str_buff,img_buff_p,str_img_mask);
			g_msg_cntx.toDisplayMessageList=TO_DISPLAY_MESSAGE_LIST_INBOX;
			g_msg_cntx.currBoxIndex=index;
		}
		else if (pgManager->currentFolder == pgManager->sendFolder)
		{
			mmi_msg_outbox_list_get_item(index,str_buff,img_buff_p,str_img_mask);
			g_msg_cntx.toDisplayMessageList=TO_DISPLAY_MESSAGE_LIST_OUTBOX;
			g_msg_cntx.currBoxIndex=index;
		}
		#ifdef __MMI_MESSAGES_DRAFT_BOX__
		else if (pgManager->currentFolder == pgManager->draftFolder)
		{
			mmi_msg_draftbox_list_get_item(index,str_buff,img_buff_p,str_img_mask);
			g_msg_cntx.toDisplayMessageList=TO_DISPLAY_MESSAGE_LIST_DRAFTBOX;
			g_msg_cntx.currBoxIndex=index;
		}
		#endif
    //chaozhu.zhou 2006-10-24 modify
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		return TRUE;
	}
	else if(message->msgtype==MESSAGE_WAP||
		message->msgtype==MESSAGE_OTA_SET||
		message->msgtype==MESSAGE_OTA_BOOKMARK)
	{
		char *str_uni = NULL;
		str=message->subject;
		mms_Tracer("^_^wap push subject in8");
		Cms_hex_trace((kal_uint8 * )message->subject, 30);
		if(str)
		{
			str_uni = Cms_mms_uni8_16(str);
			pfnUnicodeStrcpy((S8*)str_buff, (S8*)str_uni);
			mms_Free(str_uni);
			str_uni = NULL;
		}
		else
		{
			mms_Tracer("get wappush item subject is NULL ");
			pfnUnicodeStrcpy((S8*)str_buff,(PS8)L"<");
			pfnUnicodeStrcat((S8*)str_buff,(S8 *)GetString(STR_GLOBAL_EMPTY));
			pfnUnicodeStrcat((S8*)str_buff,(PS8)L">");
		}
		
		if (message->state=='U')
		{
			*img_buff_p = (UI_image_type)GetImage(IMG_WAPUNREAD_MAIN_MENU_ICON );
		}
		else
		{
			*img_buff_p = (UI_image_type)GetImage(IMG_WAPREAD_MAIN_MENU_ICON);
		}
    //chaozhu.zhou 2006-10-24 modify
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		return TRUE;
	}
#endif

	if (pgManager->currentFolder == pgManager->draftFolder)
	{
		str = message->subject;
	}
	else
	{
		cms_parse_sendto_address(message,SENDTO_TO);
		if (pgsendtolist)
		{
			str = pgsendtolist->number;
		}
	}
	if (str== NULL)
	{
		
		if(message->to_address)
		{
			temp = Cms_mms_uni8_16(message->to_address);	
			name = lookUpNumber((PS8)temp);
			if (name  &&  pfnUnicodeStrlen(name))
			{
				pfnUnicodeStrcpy((S8*)str_buff, (S8*)name);	
			}
			else
			{
				pfnUnicodeStrcpy((S8*)str_buff, (S8*)temp);
			}
			mms_Free(temp);
			temp = NULL;
		}
		else if(message->url!= NULL)
		{
			pfnUnicodeStrcpy((S8*)str_buff, GetString(STR_NOTIFICATION));
		}
		else
		{
			pfnUnicodeStrcpy((S8*)str_buff, GetString(STR_NO_SUBJECT));
		}
	}
	else
	{
		char *str_uni = NULL;
		str_uni = Cms_mms_uni8_16(str);
	
		if (pgManager->currentFolder == pgManager->draftFolder)
		{
			pfnUnicodeStrcpy((S8*)str_buff, (S8*)str_uni);
		}
		else	
		{
			name = lookUpNumber((PS8)str_uni);
			if (name  &&  pfnUnicodeStrlen(name))
			{
				pfnUnicodeStrcpy((S8*)str_buff, (S8*)name);	
			}
			else
			{
				pfnUnicodeStrcpy((S8*)str_buff, (S8*)str_uni);
			}
		}	
		mms_Free(str_uni);
		str_uni = NULL;
	}
	if (pgsendtolist)
	{
		cms_empty_sendto_to_list();
		pgsendtolist = NULL;
	}

	if (pgManager->currentFolder == pgManager->receiveFolder)
	{
		switch(message->state)	/*根据状态使用图标*/
		{
		case 'U':	/*未收*/
			*img_buff_p = (UI_image_type)GetImage(IMG_MMS_INBOX_PUSH_UNREAD);
			break;
		case 'N':	/*已收未读*/
			*img_buff_p = (UI_image_type)GetImage(IMG_MMS_INBOX_UNREAD);
			break;
		case 'Y':	/*已读*/
			if(message->url!=NULL)/*PUSH消息已读*/
			{
				*img_buff_p = (UI_image_type)GetImage(IMG_MMS_INBOX_PUSH_READ);
			}
			else
			{
				*img_buff_p = (UI_image_type)GetImage(IMG_MMS_INBOX_READ);
			}
			break;
		case 'R':	/*发送报告*/
			*img_buff_p = (UI_image_type)GetImage(IMG_MMS_INBOX_RPT);
			break;
		default:
			mms_Tracer((char*)"Inbox: default!!!");
			break;
		}
	}
	else if (pgManager->currentFolder == pgManager->sendFolder)
	{
		switch(message->state)
		{
		case 'Y':
			*img_buff_p = (UI_image_type)GetImage(IMG_MMS_OUTBOX_SENDT);
			break;
		case 'N':
			*img_buff_p = (UI_image_type)GetImage(IMG_MMS_OUTBOX_SENDF);
			break;
		default:
			mms_Tracer((char*)"Outbox: default!!!");
			break;
		}
	}
	else
	{	
		*img_buff_p = (UI_image_type)GetImage(IMG_MMS_DRAFTBOX_DRAFT);
	}
  //chaozhu.zhou 2006-10-24 modify
  ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
	return TRUE;

}

 /* ----------------------------------------------------------------------------
 * Function Name: mmi_box_list_get_hint
 *       Purpose: 获取信箱列表项hint信息
 *         Input: item_index: 列表项序号	*hint_array: hint信息字符串
 *        Output: None.
 *       Returns: 1
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
S32 mmi_box_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	char* 	temp = NULL;
	int 		l = 0;
	P_MESSAGELIST pMsg = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	pMsg = pgManager->currentFolder->root;

	for (;l < item_index && pMsg; l++)
	{
		pMsg = pMsg->next;
	}
	if (!pMsg)
	{
		return 0;
	}
#ifdef SUPPORT_SMSMMS_COMBINE
	if(pMsg->msgtype==MESSAGE_SMS)
	{
		if(mms_file_manager_get_current_folder()==MMS_RECEIVE_FOLDER)
		{	
			int		i=0,j=0;
			char		time[MMS_MAX_DATE_LEN] = {0};
			char    	ucs2TempBuff[MAX_HINT_BUF]={0};

			while (i < 8)	
			{
				time[j++] = pMsg->date[i++];
				if (i == 4 || i == 6)
				{
					time[j++] = '-';
				}
			}		
			AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)time);
			pfnUnicodeStrcpy((S8*)(*hint_array), (S8 *)ucs2TempBuff);
			return 1;
		}
		return 0;
	}
	else if(pMsg->msgtype==MESSAGE_WAP||
		pMsg->msgtype==MESSAGE_OTA_SET||
		pMsg->msgtype==MESSAGE_OTA_BOOKMARK)
	{	
		int		i=0,j=0;
		char		time[MMS_MAX_DATE_LEN] = {0};
		char    	ucs2TempBuff[MAX_HINT_BUF]={0};

		while (i < 8)	
		{
			time[j++] = pMsg->date[i++];
			if (i == 4 || i == 6)
			{
				time[j++] = '-';
			}
		}		
		AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)time);
		pfnUnicodeStrcpy((S8*)(*hint_array), (S8 *)ucs2TempBuff);
		return 1;
	}
#endif
	switch(mms_file_manager_get_current_folder())
	{
	case MMS_SEND_FOLDER:
	case MMS_RECEIVE_FOLDER:
		if (pMsg->subject) 
		{	
			if (pMsg->subject[0] == 0 && pMsg->url)
			{
				pfnUnicodeStrcpy((S8*)(*hint_array), GetString(STR_NO_SUBJECT));
			}
			else
			{
			
				temp = Cms_mms_uni8_16(pMsg->subject);
				pfnUnicodeStrncpy((S8*)(*hint_array), temp,40);	
				mms_Free(temp);
				temp = NULL;
			}
		}
		else
		{
			pfnUnicodeStrcpy((S8*)(*hint_array), GetString(STR_NO_SUBJECT));
		}
		break;
	case MMS_DRAFT_FOLDER:
		return 0;
		break;
	default:
		break;
	}
	return 1;

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
void mmi_mmsbox_find_message_by_index(S32 item_index)
{
	P_MESSAGELIST pMsg = NULL;
	int i = 0;
	pMsg = pgManager->currentFolder->root;
	for (;i < item_index;i++)
	{
		pMsg = pMsg->next;
	}
	if(pMsg)
	{
		mms_file_manager_set_current_message(pMsg);
		mms_mmi_tracer("^_^find_message_by_index^_^: item_index = %d ", (char*)item_index);
		mms_mmi_tracer("^_^find_message_by_index^_^: filename = %s ", (char*)pMsg->fileName);

		if (pgManager->currentFolder == pgManager->receiveFolder)
		{
			if (pMsg->state == 'N'&&pMsg->url!=NULL)
			{
				mms_file_manager_modify_current_message_state(MMS_MSG_STATE_READ);
				mmi_update_mms_idel_icon();
			}
		}
	}
	memset(gedit.text_buf, 0, MMS_MAX_TEXT_SIZE);
	memset(gedit.sub_buf, 0, MMS_MAX_SUBJECT_SIZE);
	MMSDelAllSlide(gpeditor_doc);
	gpeditor_doc->totalsize = 0;
	mms_Tracer((char*)"^_^mmi_mmsbox_find_message_by_index end^_^");
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_setting_service_list_hint
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
static void mmi_mms_setting_service_list_hint(U16 index)
{	
	cms_memset( ( PS8 ) hintData[(index)], 0, sizeof(hintData[(index)]));	
	mms_read_msg_setting_file_by_index(gconfig.mms_service_activeitem);
	if(pfnUnicodeStrlen((S8*)gconfigtemp.service_id)>0)
	{
		pfnUnicodeStrcpy((S8*)hintData[index],(S8*)gconfigtemp.service_id);		
	}
	else
	{
		pfnUnicodeStrcpy((S8*)hintData[index], GetString(STR_GLOBAL_EMPTY));
	}
	return;
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_get_box_index
 *       Purpose: 获取信箱中选中信息的index 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_get_box_index(S32 nIndex)
{
	ghiliindex = nIndex;
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_get_save_index
 *       Purpose: 获取保存图片/音乐列表选中的index 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_get_save_index(S32 nIndex)
{
	ghiliindex1 = nIndex;
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_get_cur_sub_hiliIndex
 *       Purpose: 获取当前选中菜单的序号
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_get_cur_sub_hiliIndex(S32 hiliteid)
{
	gCurActionItem = hiliteid;
}  
/* ----------------------------------------------------------------------------
 * Function Name: mmi_get_index
 *       Purpose: 
 *         Input: S32 nIndex
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_get_index(S32 nIndex)
{
	ghiliindex = nIndex;
}
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_check_phone_number
 *       Purpose: To check if an phoneAddr address is valid
 *         Input: phoneAddr		IN			address to be checked (in UCS).
 *        Output: None.
 *       Returns: TRUE if valid; otherwise FALSE..
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
BOOL mmi_mms_check_phone_number (U8* phoneAddr)
{
	S32		addrlen=0;
	S32 		count = 0;
	S8 		foundAt=0;
	char		ansiiTempBuff[MMS_MAX_INPUT_SEND_TO_SIZE];

	UnicodeToAnsii((S8 *)ansiiTempBuff, (S8 * )phoneAddr);
	addrlen=UCS2Strlen((S8 *)phoneAddr);
	for(;count<addrlen;count++)
	{
		if(ansiiTempBuff[count]>='0'&&ansiiTempBuff[count]<='9')
		{
			foundAt++;
		}
	}
	mms_mmi_tracer("^_^check_phone_number^_^: count = %d ", (char*)count);
	mms_mmi_tracer("^_^check_phone_number^_^: foundAt = %d ", (char*)foundAt);
	if(count==foundAt)
	{
		return CMS_PHB_MMS;
	}
	else
	{
		return CMS_PHB_EMAIL;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_display_confirm
 *       Purpose: display confirm
 *         Input: U16 strId, FuncPtr lskFuncs, FuncPtr rskFuns
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_display_confirm (UI_string_type strId, FuncPtr lskFuncs, FuncPtr rskFuns)
{

	DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, 
					STR_GLOBAL_NO, IMG_GLOBAL_NO, 
					(UI_string_type)strId,IMG_GLOBAL_QUESTION, WARNING_TONE);
	
	SetLeftSoftkeyFunction (lskFuncs, KEY_EVENT_UP);
	SetRightSoftkeyFunction (rskFuns, KEY_EVENT_UP);
	playRequestedTone (WARNING_TONE);
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
void mmi_mms_indication_delete_message(void)
{
	mmi_mms_display_confirm((UI_string_type)get_string(STR_MMS_DELETE),
							mmi_mms_delete_message, mmi_exit_display_to_history);
}

 
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_indication_delete_all_messages
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_indication_delete_all_messages (void)
{
	U16 	delcaptionStrId=0;
	P_MESSAGELIST pCurmsg=NULL;
	
	pCurmsg=mms_file_manager_get_current_message();
	if(pCurmsg->msgtype==MESSAGE_MMS)
	{
		delcaptionStrId=STR_MMS_DELETE_ALL_MMS;
	}
	else if(pCurmsg->msgtype==MESSAGE_WAP||pCurmsg->msgtype==MESSAGE_OTA_BOOKMARK||pCurmsg->msgtype==MESSAGE_OTA_SET)
	{
		delcaptionStrId=STR_WAP_PUSHBOXOPTION_DELETEALL_ID;
	}
	mmi_mms_display_confirm((UI_string_type)get_string(delcaptionStrId), 
							mmi_mms_delete_all_messages, mmi_exit_display_to_history);
	return;

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
void mmi_mms_indication_save_message(void)
{

	if(!mmsflag.gmsg_saved)
	{
		if (gpeditor_doc->slide_root)
		{
			mmi_mms_display_confirm((UI_string_type)get_string(STR_SAVE_MESSAGE), 
								mmi_mms_save_message_and_exit, mmi_mms_no_save_message_and_exit);
		}
		else
		{
			mmi_mms_no_save_message_and_exit();
		}
	}
	else
	{
		mmi_mms_no_save_message_and_exit();
	}

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_frame_time_confirm
 *       Purpose: 设置本页播放时间
 *         Input: gpeditor_doc
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_frame_time_confirm(void)
{
	if (!(gedit.frametime[0] == '\0' && gedit.frametime[1] == '\0'))
	{
		if (!(gedit.frametime[0] == 48 && gedit.frametime[2] == 48))
		{
			if (gedit.frametime[2] != '\0')
			{
				if ((gedit.frametime[0] - 48) * 10 + (gedit.frametime[2] - 48) >= 60)
				{
                 			  gpeditor_doc->slide_cur->times = (U16)(60) * 1000;                  
				}
				else
				{
                  			   gpeditor_doc->slide_cur->times = (U16)((gedit.frametime[0] - 48) * 10 + (gedit.frametime[2] - 48)) * 1000;
				}
			}
			else
			{		
				if (gedit.frametime[0]==48)
				{
					gpeditor_doc->slide_cur->times = (U16)(5) * 1000;
				}
		
				else
				{
                 			gpeditor_doc->slide_cur->times = (U16)(gedit.frametime[0] - 48) * 1000;
				}
			}
		}
		else
		{
			gpeditor_doc->slide_cur->times = (U16)(5) * 1000;
		}
	}
	GoBackHistory();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_delete_message
 *       Purpose: delete message in inbox
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_delete_message(void)
{
	mms_file_manager_delete_current_message();

	if (pgManager->currentFolder->messageNumber < ghiliindex)
	{
		ghiliindex = pgManager->currentFolder->messageNumber;
	}
	
	ExitDisplayPopupConfirm();
	
	if(pgManager->currentFolder == pgManager->receiveFolder)
	{
		if (pgManager->receiveFolder->messageNumber <= 0)
		{
			if(IsScreenPresent(SCR_ID_MMS_MAIN_MENU))
			{
				GoBackToHistory(SCR_ID_MMS_MAIN_MENU);
			}
			else
			{
				//GoBackHistory();
				mmi_mms_exit_to_idle();
			}
		}
		else
		{
			if(IsScreenPresent(SCR_ID_MMS_INBOX))
			{
				GoBackToHistory(SCR_ID_MMS_INBOX);
			}
			else
			{
				GoBackHistory();
			}
		}
	}
	else if(pgManager->currentFolder == pgManager->sendFolder)
	{
		if (pgManager->sendFolder->messageNumber <= 0)
		{
			if(IsScreenPresent(SCR_ID_MMS_MAIN_MENU))
			{
				GoBackToHistory(SCR_ID_MMS_MAIN_MENU);
			}
			else
			{
				GoBackHistory();
			}
		}
		else
		{
			if(IsScreenPresent(SCR_ID_MMS_OUTBOX))
			{
				GoBackToHistory(SCR_ID_MMS_OUTBOX);
			}
			else
			{
				GoBackHistory();
			}
		}
	}
	else if(pgManager->currentFolder == pgManager->draftFolder)
	{
		if (pgManager->draftFolder->messageNumber <= 0)
		{
			if(IsScreenPresent(SCR_ID_MMS_MAIN_MENU))
			{
				GoBackToHistory(SCR_ID_MMS_MAIN_MENU);
			}
			else
			{
				GoBackHistory();
			}
		}
		else
		{
			if(IsScreenPresent(SCR_ID_MMS_DRAFTBOX))
			{
				GoBackToHistory(SCR_ID_MMS_DRAFTBOX);
			}
			else
			{
				GoBackHistory();
			}	
		}
	}
	DisplayPopup((U8*)GetString(STR_DELETE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	mmi_update_mms_idel_icon();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_delete_all_messages
 *       Purpose: delete all messages in inbox
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_delete_all_messages(void)
{

	if(mmsflag.gsend_recv&&(MMS_RECEIVE_FOLDER==mms_file_manager_get_current_folder()))
	{
		DisplayPopup((U8*)GetString(STR_MMS_PUSH_OPERATING), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	else
	{	
		#ifdef SUPPORT_SMSMMS_COMBINE
		{	
			P_MESSAGELIST pMsg = NULL,pTemp=NULL,pCurnsg=NULL;

			pMsg = pgManager->currentFolder->root;
			pCurnsg=mms_file_manager_get_current_message();
			if(pCurnsg->msgtype==MESSAGE_WAP||
				pCurnsg->msgtype==MESSAGE_OTA_SET||
				pCurnsg->msgtype==MESSAGE_OTA_BOOKMARK)
			{
				for(;pMsg;)
		  		{
					pTemp=pMsg->next;
				#ifdef SUPPORT_OTA_PUSH
					if((!pMsg->fileName)&&(pMsg->url||pMsg->ota_murl))
				#else
					if((!pMsg->fileName)&&(pMsg->url))
				#endif
					{
						mms_Tracer("delete a mms message ");
						mms_file_manager_set_current_message(pMsg);
						mms_file_manager_delete_current_message();
					}
					pMsg=pTemp;
				}
			}
			else
			{
		  		for(;pMsg;)
		  		{
					pTemp=pMsg->next;
					if(pMsg->fileName)
					{
						mms_Tracer("delete a mms message ");
						mms_file_manager_set_current_message(pMsg);
						mms_file_manager_delete_current_message();
					}
					pMsg=pTemp;
				}
			}
		}
		#else
		mms_file_manager_delete_current_folder();
		#endif
		ExitDisplayPopupConfirm();
		if(IsScreenPresent(SCR_ID_MMS_MAIN_MENU))
		{
		#ifdef SUPPORT_SMSMMS_COMBINE
			if( pgManager->currentFolder->messageNumber>0)
			{
				if(pgManager->currentFolder == pgManager->receiveFolder)
				{
					if(IsScreenPresent(SCR_ID_MMS_INBOX))
					{
						GoBackToHistory(SCR_ID_MMS_INBOX);
					}
					else
					{
						GoBackHistory();
					}
				}
				else if(pgManager->currentFolder == pgManager->sendFolder)
				{
					if(IsScreenPresent(SCR_ID_MMS_OUTBOX))
					{
						GoBackToHistory(SCR_ID_MMS_OUTBOX);
					}
					else
					{
						GoBackHistory();
					}
				}
				else if(pgManager->currentFolder == pgManager->draftFolder)
				{
					if(IsScreenPresent(SCR_ID_MMS_DRAFTBOX))
					{
						GoBackToHistory(SCR_ID_MMS_DRAFTBOX);
					}
					else
					{
						GoBackHistory();
					}	
				}
			}
			else
		#endif
			GoBackToHistory(SCR_ID_MMS_MAIN_MENU);
		}
		else
		{
			//GoBackHistory();
			mmi_mms_exit_to_idle();
		}	
		DisplayPopup((U8*)GetString(STR_DELETE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	}
	mmi_update_mms_idel_icon();
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_view_message
 *       Purpose: 预览/播放前
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_view_message(void)
{
	mms_Tracer("enter mms_view_message");   
	if (!mmsflag.gplay_state)
	{
		//DisableLeftSoftkey(NULL,NULL);
		//clear_left_softkey();
		ChangeLeftSoftkey(0, 0);
		ChangeRightSoftkey(STR_MMS_STOPPREV, IMG_GLOBAL_BACK);
		SetRightSoftkeyFunction(mmi_mms_stop_play_message, KEY_EVENT_UP);
		mmsflag.gplay_state = TRUE;
	}
	
	if (gpeditor_doc->slide_cur != gpeditor_doc->slide_root)
	{
		MMS_HeadSlide(gpeditor_doc);
	}

	mms_play_music();
	mms_play_show_text_image();
	/*开始计时*/
	mms_mmi_tracer("mms_call_back:gpeditor_doc->slide_cur->times=%d", (char*)gpeditor_doc->slide_cur->times);
	if(gpeditor_doc->slide_cur->times>MMS_MAX_PLAY_TIME*1000)
	{
		pixtel_UI_start_timer((s32)MMS_MAX_PLAY_TIME*1000,mms_play_message_callback);
	}
	else
	{
		pixtel_UI_start_timer((s32)gpeditor_doc->slide_cur->times,mms_play_message_callback);
	}	
	mms_Tracer("out mms_view_message");   
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_play_message_callback
 *       Purpose: 预览/播放彩信回调
 *         Input:  (GLOBALS)gedit.total_height, gedit.start_height, gbplay_stat
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_play_message_callback(void)
{		
	mms_stop_music();
	mms_stop_animation();

	pixtel_UI_cancel_timer(mms_play_message_callback);

	if (!mmsflag.gplay_state)
	{
		return ;
	}
	
	if(MMS_NextSlide(gpeditor_doc))
	{
		gedit.start_height = 0;
		gedit.total_height = 0;
		mmi_change_title_string();
		
		gdi_layer_lock_frame_buffer();
		if (gpeditor_doc->slide_cur->audiosize > 0)
		{
			ChangeTitle(IMG_MMS_MUSIC_ADDED, (U8*)gedit.title);
		}
		else
		{
			ChangeTitle(IMG_MESSAGE_SIM_MMS_MENUENTRY, (U8*)gedit.title);
		}
		draw_title();
		gdi_layer_unlock_frame_buffer();
		gdi_layer_blt_base_layer(0, 0, UI_device_width-1, UI_device_height-1);
		mms_mmi_tracer("mms_call_back:gpeditor_doc->slide_cur->times=%d", (char*)gpeditor_doc->slide_cur->times);
		if(gpeditor_doc->slide_cur->times>MMS_MAX_PLAY_TIME*1000)
		{
			pixtel_UI_start_timer((s32)MMS_MAX_PLAY_TIME*1000,mms_play_message_callback);
		}
		else
		{
			pixtel_UI_start_timer((s32)gpeditor_doc->slide_cur->times,mms_play_message_callback);
		}
		
		mms_play_music();
		mms_play_show_text_image();	
	}
	else
	{
		mmsflag.gplay_state = FALSE;
		show_left_softkey();
		ChangeLeftSoftkey(STR_MMS_PLAY, IMG_GLOBAL_OK);
		EnableLeftSoftkey(STR_MMS_PLAY, IMG_GLOBAL_OK);
		SetLeftSoftkeyFunction(mmi_mms_redraw_play, KEY_EVENT_UP);
		ChangeRightSoftkey(STR_GLOBAL_BACK,IMG_GLOBAL_BACK);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_play_show_text_image
 *       Purpose: 播放/预览彩信时显示文本、图像内容
 *         Input: (GLOBALS)gedit.total_height
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_play_show_text_image(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 		x = 0, y = gedit.start_height+2;
	U32 		len = 0,size=0;
	U8* 		str = NULL;
	FILE_HANDLE 		fd = 0;
	pMMS_Content 	content = NULL;
	U32		image_flag=0;// 20060817 wantao add flag for debug when show image
	U32		text_flag=0;//add by jinliang 20070726
	U32		accessory_flag=0;//add by jinliang 20070726
	/*----------------------------------------------------------------*/
	/* Code Body                                                    */
	/*----------------------------------------------------------------*/
	pixtel_UI_set_clip(0,MMI_MMS_TITLE_HIGHT+1,UI_device_width-current_MMI_theme->scrollbar_size-1,UI_device_height-MMI_button_bar_height-1);
	pixtel_UI_fill_rectangle(0,MMI_MMS_TITLE_HIGHT+1,UI_device_width-1,UI_device_height-MMI_button_bar_height-1,pixtel_UI_color(255,255,255));

	content = gpeditor_doc->slide_cur->content_root;

	for(;content;content = content->next)
	{
		mms_mmi_tracer("hello,y=%d", (char*)y);

		switch(content->type)
		{
		case MMS_TYPE_TEXT:
			{
				if(text_flag>=1)// add by jinliang
				{
					break;
				}
				text_flag = 1;
				fd = mmsf_Open(content->filename,"r");
				if (fd)
				{
					mms_Tracer((char*)":MMS_TYPE_TEXT in");
					mmsf_Read((char *)(&len),1,sizeof(unsigned short),fd);

					str = (U8*)mms_Malloc(len+2);
					if (str == NULL)
					{
						mms_Tracer((char*)"error::str=NULL");
						return;
					}
					memset(str,0,len + 2);
					mmsf_Read((char *)str,1,len,fd);
					mmsf_Close(fd);
					mms_draw_text(str, &x, &y, len);					
					mms_Free(str);
					str = NULL;
					mms_Tracer((char*)"end of draw");
				}
			}
			break;
		case MMS_TYPE_GIF:
			{
				if(image_flag>=1)// 20060817 wantao add flag for debug when show image
				{
					break;
				}
				image_flag = 1;
				fd = mmsf_Open(content->filename,"r");
				if (fd)
				{	
					mms_stop_animation();
					
                    			size=content->contentsize;					
					len = content->contentsize+9;
					
					str = (U8*)mms_Malloc(len+2);
					if (str == NULL)
					{
						return ;
					}
					memset(str, 0, len+2);
					{
						str[0]=IMAGE_TYPE_GIF;
						str[1]=NULL;
						str[2] = (U8) ( size& 0x000000ff);
						str[3] = (U8) ((size >> 8) & 0x000000ff);
						str[4] = (U8) ((size >> 16) & 0x000000ff);
						str[5] = (U8) ((size >> 24) & 0x000000ff);
						str[6]=NULL;
						str[7]=NULL;
					}	
					mmsf_Read((char*)str+8, 1, size+1, fd);					
					mmsf_Close(fd);
					
					ganimation_buf=str;	
					
					mms_draw_picture_for_play(str, &x, &y, len, content->type);

				}
				else
				{
					mms_Tracer((char*)"sorry, do not find the file");
				}
			}
			break;
		case MMS_TYPE_WBMP:
		case MMS_TYPE_JPEG:
		case MMS_TYPE_PNG:
		case MMS_TYPE_BMP1:
			{
				if(image_flag>=1)// 20060817 wantao add flag for debug when show image
				{
					break;
				}
				image_flag = 1;
				fd = mmsf_Open(content->filename,"r");
				if (fd)
				{
					len = content->contentsize;
					str = (U8*)mms_Malloc(len+2);
					if (!str)
					{
						return ;
					}
					memset(str, 0, len+2);
					
					mmsf_Read((char*)str, 1, len, fd);
					mmsf_Close(fd);
					mms_draw_picture_for_play(str, &x, &y, len, content->type);

					mms_Free(str);
					str = NULL;
				}
				else
				{
					mms_Tracer((char*)"sorry, do not find the file");
				}
			}
			break;
		case MMS_TYPE_VCF:
		case MMS_TYPE_VCS:
			{
				if(accessory_flag>=1)
				{
					break;
				}
				accessory_flag = 1;
				fd = mmsf_Open(content->filename,"r");
				if (fd)
				{
					len = content->contentsize;
					str = (U8*)mms_Malloc(len+2);
					if (!str)
					{
						return ;
					}
					memset(str, 0, len+2);
					
					mmsf_Read((char*)str, 1, len, fd);
					mmsf_Close(fd);
					//mms_draw_picture_for_play(str, &x, &y, len, content->type);

					mms_Free(str);
					str = NULL;
				}
				else
				{
					mms_Tracer((char*)"sorry, do not find the file");
				}
			}
			break;
		default:
			mms_Tracer((char*)"sorry, unkonw media type");
			break;	
		}
	}
	if (gedit.total_height <= 0)
	{
		gedit.total_height = y;
	}
	/* show vertical scrollbar range*/
	if(gedit.total_height<=MMI_content_height)
	{
		pixtel_UI_set_vertical_scrollbar_range(&play_show_vbar,1);
		pixtel_UI_set_vertical_scrollbar_scale(&play_show_vbar,1);
		pixtel_UI_set_vertical_scrollbar_value(&play_show_vbar,1);
	}
	else
	{
		pixtel_UI_set_vertical_scrollbar_range(&play_show_vbar,(gedit.total_height));
		pixtel_UI_set_vertical_scrollbar_scale(&play_show_vbar,MMI_content_height);
		pixtel_UI_set_vertical_scrollbar_value(&play_show_vbar,(-gedit.start_height));
	}
	mms_mmi_tracer("hello,gedit.total_height=%d", (char*)gedit.total_height);
	mms_mmi_tracer("hello,gedit.start_height=%d", (char*)gedit.start_height);
	pixtel_UI_show_vertical_scrollbar( &play_show_vbar );
	
	draw_title();
	show_softkey_background();
	if (!mmsflag.gplay_state)
	{
		show_left_softkey();
	}
	else
	{
		clear_left_softkey();
	}
	show_right_softkey();

	#if (UI_DOUBLE_BUFFER_SUPPORT)	
		pixtel_UI_BLT_double_buffer(0,0,UI_device_width-1,UI_device_height-1);
	#endif
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_play_music
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_play_music(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8* 			mstr = NULL;
	U32			mlen = 0;
	FILE_HANDLE 	fh = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (gpeditor_doc->slide_cur->audiosize <= 0)
	{
		return ;
	}
	fh = mmsf_Open(gpeditor_doc->slide_cur->audiofile, "r");	
	if (fh <= 0)
	{
		return ;
	}
	mlen = (U32)gpeditor_doc->slide_cur->audiosize;
	mstr = (U8*)mms_Malloc(mlen);
	if (!mstr)
	{
		return ;
	}
	mmsf_Read((char*)mstr, 1, mlen, fh);
	mmsf_Close(fh);
	
	gaudio_buf=mstr;
	switch(gpeditor_doc->slide_cur->audio_type)
	{
	case MMS_TYPE_WAV:
		PlayAudioWavStream(mstr, mlen, DEVICE_AUDIO_PLAY_INFINITE);
		break;
	case MMS_TYPE_IMY:
		PlayAudioStream(mstr, mlen,MEDIA_IMELODY,DEVICE_AUDIO_PLAY_INFINITE);
		break;
	case MMS_TYPE_MIDI:
		PlayAudioMidiStream(mstr, mlen, DEVICE_AUDIO_PLAY_INFINITE);
		break;	
	case MMS_TYPE_AMR:
		PlayAudioStream(mstr, mlen, MEDIA_AMR,DEVICE_AUDIO_PLAY_INFINITE);
		break;
	default:
		if (gaudio_buf!=NULL)
		{
			mms_Free(gaudio_buf);
			gaudio_buf=NULL;
		}
		break;	
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_draw_picture_for_play
 *       Purpose:   预览/播放彩信时图像内容排版
 *         Input: *  	str: 图像数据地址
 *			*	tx: 起始点横坐标  
 *			*	ty: 起始点纵坐标  length: 文本长度
 *  			*   	type: 图像类型(包括gif,jpeg,wbmp,bmp)
 *        Output: None.
 *       Returns: *tx,*ty: 返回排版显示成功后坐标(只用到纵坐标)   .
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_draw_picture_for_play(U8* str, U32* tx,U32* ty,U32 length, U16 type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 		image_width,image_height,offset_x,offset_y,frame_count,
			resized_offset_x,resized_offset_y,resized_width,resized_height;
	U32 		x = 0, y = 0;
	U32 		resized_hight = 0;
	GDI_RESULT result = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	x = *tx;
	y = *ty;
	mms_mmi_tracer("type = %d", (char*)type);

	switch(type)
	{
	case MMS_TYPE_GIF:
		{
			gdi_image_gif_reset();
			result = gdi_image_gif_get_dimension(str+8, 
										&image_width, &image_height);
			
			gdi_image_gif_get_frame_count(str+8, length, &frame_count);

			if( result >= 0 )
                     {
                            if (frame_count == 1)
                            {
                             	if((UI_device_width >= image_width) && (MMI_content_height >= image_height))
					{
						offset_x = (UI_device_width-image_width)>>1;
						offset_y = (UI_device_height-image_height)>>1;
						mms_Tracer((char *) "gdi_image_gif_draw");
                                   	//gdi_image_gif_draw(offset_x, y+MMI_ORIGIN_Y, str, length, frame_count);
						gdi_image_gif_draw_resized(offset_x, y+MMI_ORIGIN_Y, image_width, image_height, str+8, length, frame_count);
						resized_hight = image_height;

                                   }
                                   else
					{
						gdi_image_util_fit_bbox(UI_device_width,  MMI_content_height, 
											image_width, image_height, 
											&resized_offset_x, &resized_offset_y, 
											&resized_width, &resized_height);
						mms_Tracer((char *) "gdi_image_gif_draw_resized");
                                         	gdi_image_gif_draw_resized(resized_offset_x, y+MMI_ORIGIN_Y, resized_width, resized_height, 
                                                                                        str+8, length, frame_count);
						resized_hight = resized_height;				 
                                    }

 				}
				else
				{
					if((UI_device_width >= image_width) && (MMI_content_height >= image_height))
					{
						offset_x = (UI_device_width-image_width)>>1;	
						offset_y = (UI_device_height-image_height)>>1;
 					   gif_play_from_mms = FALSE;/*解决GIF重影问题*/
						mms_Tracer((char *) "gdi_image_draw_animation");
						gdi_image_draw_animation(offset_x, y+MMI_ORIGIN_Y, str,NULL);
						resized_hight = image_height;	
					}
					else/*对超出屏幕大小的GIF动画当静态图片处理*/
					{
						gdi_image_util_fit_bbox(UI_device_width,  MMI_content_height, 
											image_width, image_height, 
											&resized_offset_x, &resized_offset_y, 
											&resized_width, &resized_height);
											mms_Tracer((char *) "gdi_image_gif_draw_resized");
                     //gdi_image_gif_draw_resized(resized_offset_x, y+MMI_ORIGIN_Y, resized_width, resized_height,  str+8, length, frame_count);
						gdi_image_draw_animation_resized(resized_offset_x, y+MMI_ORIGIN_Y, resized_width, resized_height,  str,NULL);
						resized_hight = resized_height;							
					}
                   		}
			}
			break;
		}		
	case MMS_TYPE_JPEG:
		{
			int	jpeg_decode_flag = 0;
			result = gdi_image_jpeg_get_dimension(str, length,
													&image_width,
													&image_height);
			if (result >= 0)
			{
				if ((UI_device_width >= image_width) && (MMI_content_height >= image_height))
				{
					offset_x = (UI_device_width-image_width)>>1;
					
					offset_y = (UI_device_height-image_height)>>1;

					jpeg_decode_flag = gdi_image_jpeg_draw(offset_x, y+MMI_ORIGIN_Y, str, length);
					resized_hight = image_height;
				}
				else
				{
					gdi_image_util_fit_bbox(UI_device_width,  MMI_content_height, 
											image_width, image_height, 
											&resized_offset_x, &resized_offset_y, 
											&resized_width, &resized_height);
					image_height = resized_height;

					jpeg_decode_flag = gdi_image_jpeg_draw_resized(resized_offset_x, y+MMI_ORIGIN_Y, resized_width, resized_height, 
												str, length);
					resized_hight = resized_height;
				}
				/*针对不支持的JPEG progressive类型作处理*/
				if(jpeg_decode_flag < 0)
				{
					S8*  	image_buf = NULL;
					int		temp_length = 0;
					mms_Tracer("can not support the jpeg type");
					image_buf = GetImage(IMG_MMS_PLAY_UNKNOW_MEDIATYPE);
					temp_length =((*(image_buf+3))<<8)+(*(image_buf+2))-8;
					result = gdi_image_gif_get_dimension((U8*)(image_buf+8), 
										&image_width, &image_height);						
					if((UI_device_width >= image_width) && (MMI_content_height >= image_height))
					{
						offset_x = (UI_device_width-image_width)>>1;
						offset_y = (UI_device_height-image_height)>>1;
	                            	gdi_image_gif_draw(offset_x, y+MMI_ORIGIN_Y, (U8*)(image_buf+8), temp_length, 1);
						resized_hight = image_height;
	                     	}
				}
			}
			break;
		}
#ifdef CMS_SURPPORT_PNG
	case MMS_TYPE_PNG:
		{
			result = gdi_image_png_get_dimension(str, length,
													&image_width,
													&image_height);
			if (result >= 0)
			{
				if ((UI_device_width >= image_width) && (MMI_content_height >= image_height))
				{
					offset_x = (UI_device_width-image_width)>>1;
					
					offset_y = (UI_device_height-image_height)>>1;

					gdi_image_png_draw(offset_x, y+MMI_ORIGIN_Y, str, length);
					
					resized_hight = image_height;
				}
				else
				{
					gdi_image_util_fit_bbox(UI_device_width,  MMI_content_height, 
											image_width, image_height, 
											&resized_offset_x, &resized_offset_y, 
											&resized_width, &resized_height);
					image_height = resized_height;
					gdi_image_png_draw_resized(resized_offset_x, y+MMI_ORIGIN_Y, resized_width, resized_height, 
												str, length);				
					resized_hight = resized_height;
				}
			}
			break;
		}
#endif
	case MMS_TYPE_WBMP:
		{
			result = gdi_image_wbmp_get_dimension(str, &image_width,
													&image_height);
			if (result >= 0)
			{
				if ((UI_device_width >= image_width) && (MMI_content_height >= image_height))
				{
					offset_x = (UI_device_width-image_width)>>1;
					
					offset_y = (UI_device_height-image_height)>>1;

					gdi_image_wbmp_draw(offset_x, y+MMI_ORIGIN_Y, str, length);
					
					resized_hight = image_height;
				}
				else
				{
					gdi_image_util_fit_bbox(UI_device_width,  MMI_content_height, 
											image_width, image_height, 
											&resized_offset_x, &resized_offset_y, 
											&resized_width, &resized_height);
					image_height = resized_height;
					gdi_image_wbmp_draw_resized(resized_offset_x, y+MMI_ORIGIN_Y, resized_width, resized_height, 
												str, length);				
					resized_hight = resized_height;
				}
			}
			break;
		}
	case MMS_TYPE_BMP1:
		{
			result = gdi_image_bmp_get_dimension(str, &image_width,
													&image_height);
			if (result >= 0)
			{
				if ((UI_device_width >= image_width) && (MMI_content_height >= image_height))
				{
					offset_x = (UI_device_width-image_width)>>1;
					
					offset_y = (UI_device_height-image_height)>>1;

					gdi_image_bmp_draw(offset_x, y+MMI_ORIGIN_Y, str, length);
					
					resized_hight = image_height;
				}
				else
				{
					gdi_image_util_fit_bbox(UI_device_width,  MMI_content_height, 
											image_width, image_height, 
											&resized_offset_x, &resized_offset_y, 
											&resized_width, &resized_height);
					image_height = resized_height;
					gdi_image_bmp_draw_resized(resized_offset_x, y+MMI_ORIGIN_Y, resized_width, resized_height, 
												str, length);
					resized_hight = resized_height;
				}
			}
			break;
		}
	default:
		{
			S8*  	image_buf = NULL;
			int		temp_length = 0;
			mms_Tracer("can not support the jpeg type");
			image_buf = GetImage(IMG_MMS_PLAY_UNKNOW_MEDIATYPE);
			temp_length =((*(image_buf+3))<<8)+(*(image_buf+2))-8;
			result = gdi_image_gif_get_dimension((U8*)(image_buf+8), 
								&image_width, &image_height);						
			if((UI_device_width >= image_width) && (MMI_content_height >= image_height))
			{
				offset_x = (UI_device_width-image_width)>>1;
				offset_y = (UI_device_height-image_height)>>1;
                        	gdi_image_gif_draw(offset_x, y+MMI_ORIGIN_Y, (U8*)(image_buf+8), temp_length, 1);
				resized_hight = image_height;
                 	}
		}
	}
	
	*ty += resized_hight + MMI_LINE_HEIGHT - resized_hight%MMI_LINE_HEIGHT;
	
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_draw_text
 *       Purpose: 文本内容排版
 *         Input: str: 文本字符串地址  
 *			*tx: 起始点横坐标  
 *			*ty: 起始点纵坐标  
 *			length: 文本长度
 *        Output: None.
 *       Returns: *tx,*ty: 返回排版显示成功后坐标(只用到纵坐标) .
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_draw_text(U8* str, U32* tx,U32* ty,U32 length)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 		x1 = 0,x2 = 0;
	U32 		y = 0;
	U32 		max_width = 0;
	int	 	retvalue = 0,i = 0;
	CMS_BROWSER_S16 	end = 0, num = 0;
	CMS_BROWSER_U8 	buf[128] = {0};
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	end=(CMS_BROWSER_S16)length;
	x1 = *tx;
	y=(CMS_BROWSER_S16)(*ty);
	max_width = UI_device_width-current_MMI_theme->scrollbar_size;

	num = (CMS_BROWSER_S16)mmi_mms_getline_fit(str, end, (P_CMS_BROWSER_U32)(&max_width));
	//end = (CMS_BROWSER_S16)(end - num);
	mms_mmi_tracer("textline, num= %d",(char*)num);
	mms_mmi_tracer("textline, end= %d",(char*)end);
	mms_mmi_tracer("textline, length= %d",(char*)length);

	if(num>=0)
	{
		if(num>0)
		{
			for(i=0;i<num;i++)
			{
				buf[i]=*(str++);
			}
			buf[i]=0;
			buf[i+1]=0;
			x2=x1+max_width;
			
			if(y >=0 && (y/MMI_LINE_HEIGHT) < MMI_SCREEN_LINE)
			{
				mms_mmi_tracer("textline, 1y= %d",(char*) y);
				mms_mmi_tracer("textline, buflen= %d",(char*) i);
				retvalue = mmi_mms_text_line(buf, x1, y);
			}
		}
		y += MMI_LINE_HEIGHT;
		while(end>0)
		{
			x1=0;
			end = (CMS_BROWSER_S16)(end - num);
			num = (CMS_BROWSER_S16)mmi_mms_getline_fit(str, end, (P_CMS_BROWSER_U32)(&max_width));
			if(num>0)
			{
				for(i=0;i<num;i++)
					buf[i]=*(str++);
				buf[i]=0;
				buf[i+1]=0;
				x2=x1+max_width;
				if(y >=0 && (y/MMI_LINE_HEIGHT) < MMI_SCREEN_LINE)
				{
					mms_mmi_tracer("textline, 2y= %d",(char*) y);
					mmi_mms_text_line(buf, x1, y);
				}
			}
			y+=MMI_LINE_HEIGHT;
		}
	}
	*ty =  y;
	mms_mmi_tracer("textline, 3y= %d",(char*)y);
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_text_line
 *       Purpose: 文字排版
 *         Input:  x: 显示文字的起始横坐标 y: 起始纵坐标 str: 文字字符串
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int mmi_mms_text_line(P_CMS_BROWSER_U8 str, CMS_BROWSER_U32  x, CMS_BROWSER_U32  y)
{
	mmi_mms_print_hz_onscr(x, y+MMI_ORIGIN_Y, str);
	return 1;	
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
int mmi_mms_print_hz_onscr(int x, int y, unsigned char* str)
{
	pixtel_UI_reset_text_clip();
	pixtel_UI_set_font((UI_font_type)&MMI_medium_font);
	mms_Tracer((char * )"mmi_mms_print_hz_onscr");
	//Cms_hex_trace((kal_uint8 * )str,( kal_int32 )20);
	pixtel_UI_set_clip(0, MMI_MMS_TITLE_HIGHT + 1, UI_device_width - 1, 
		MMI_MMS_TITLE_HIGHT + MMI_content_height - 2);
	pixtel_UI_set_text_clip(0, MMI_MMS_TITLE_HIGHT + 1, UI_device_width, 
		MMI_MMS_TITLE_HIGHT + MMI_content_height - 2);
	pixtel_UI_set_text_color(pixtel_UI_color(0,0,0));
				
	pixtel_UI_move_text_cursor(x,y);
	pixtel_UI_print_text((UI_string_type)str);
	return 1;	
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
CMS_BROWSER_U32 mmi_mms_getline_fit(P_CMS_BROWSER_U8 str, CMS_BROWSER_U32 m_end, P_CMS_BROWSER_U32 max_width)
{
	CMS_BROWSER_U32	  	textlong=0,f=0;
	CMS_BROWSER_U16		uni_16 = 0;
		  
	if(str==NULL || max_width==NULL)
	{
		return 0;
	}
	while (f<m_end && textlong<=*max_width)
	{
		uni_16 = (CMS_BROWSER_U16 )(*(str+f+1)*256 + *(str+f)) ;
		textlong = textlong + mmi_get_utf16_width(CMSFONT, uni_16);
			  
		f+=2;
		if((*(str+f-2))=='\r'&&(*(str+f))=='\n')
		{
			f+=2;
			break;
		}
	}
	if(textlong>*max_width)
	{
		f -= 2;
	}
	return f;
}
/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 更改title string
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_change_title_string(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	char 	ansiiTitle[24] = {0};
	char 	unicodeTitle[24] = {0};
	U16		cur_count = 1;
	float		resize=0;
	U16		total_count = MMSGetSlideCount(gpeditor_doc);
	pMMS_Slide slide = gpeditor_doc->slide_root;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (; slide && cur_count < total_count; slide = slide->next)
	{
		if (slide == gpeditor_doc->slide_cur)
		{
			break;
		}
		cur_count++;
	}
	
	resize=gpeditor_doc->totalsize;

	sprintf(ansiiTitle,"%d/%d (%.1f K)",(int)cur_count,(int)total_count,(float)(resize/1024));
	AnsiiToUnicodeString ((S8*)unicodeTitle, (S8*)ansiiTitle);

	memset(gedit.title, 0, MMS_MAX_TITLE_LENGTH);
	pfnUnicodeStrcpy((char*)gedit.title, unicodeTitle);		
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
void mms_stop_animation(void)
{
	if (ganimation_buf!=NULL)
	{
		mms_Tracer((char *) "^_^mms_stop_animation free^_^");
		mms_Free(ganimation_buf);
		ganimation_buf=NULL;
	}
	gif_play_from_mms = FALSE;
	gdi_image_stop_animation_all();
	mms_mmi_tracer("mms_stop_animation,ganimation_buf=%d",(char*)ganimation_buf);
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
void mms_stop_music(void)
{
	if (gpeditor_doc->slide_cur->audiosize > 0)
	{
 		switch(gpeditor_doc->slide_cur->audio_type)
		{
		case MMS_TYPE_WAV:
			StopAudioWavStream();
			break;
		case MMS_TYPE_IMY:
			StopAudioStream();
			break;
		case MMS_TYPE_MIDI:
			StopAudioMidiStream();
			break;
		case MMS_TYPE_AMR:
			StopAudioStream();
			break;
 		}
	}
	if (gaudio_buf!=NULL)
	{
		StopAudioStream();
		mms_Tracer((char *) "mms_stop_music free^_^");
		mms_Free(gaudio_buf);
		gaudio_buf=NULL;
	}
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


/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 退出保存信息操作，
 *				New message TO 主菜单
 *				Edit message	TO 信箱列表
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_save_message_and_exit(void)
{
	mmi_mms_save_message();
	
	if(mmsflag.gnew_message)
	{
		mmi_mms_exit_to_main_menu();
		return;
	}
	switch(mms_file_manager_get_current_folder())
	{
	case MMS_SEND_FOLDER:
	case MMS_RECEIVE_FOLDER:
	case MMS_DRAFT_FOLDER:
		mmi_mms_exit_to_box_options();
		break;
	default:
		break;
	}
	return;

}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_no_save_message_and_exit
 *       Purpose: 退出不保存信息操作，
 *				New message TO 主菜单
 *				Edit message	TO 信箱列表
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void mmi_mms_no_save_message_and_exit(void)
{	
	if(mmsflag.gnew_message)
	{
		mmi_mms_exit_to_main_menu();
		return;
	}
	switch(mms_file_manager_get_current_folder())
	{
	case MMS_SEND_FOLDER:
	case MMS_RECEIVE_FOLDER:
	case MMS_DRAFT_FOLDER:
		mmi_mms_exit_to_box_options();
		break;
	default:
		break;
	}
	return;
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_judge_gpeditor_content
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int cms_judge_gpeditor_content(void)
{
	pMMS_Content content = NULL;
	pMMS_Slide slide = NULL;   
	int i = 0;
	slide = gpeditor_doc->slide_root;
	mms_Tracer((char*)"enter cms_judge_gpeditor_content");
	while (slide)
	{
		if (slide != NULL)                  
		{                                        
			if(slide->audiosize>0)
				i++;
			content = slide->content_root;         
			while (content)                        
			{                                      
				if (content != NULL)    
				{                                    
					i++;                             
				} 
				content = content->next;             
			}                                                                    
		}                                        
		slide = slide->next;      		
	} 
	return i;  
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_save_message
 *       Purpose: save message
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_save_message(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	char					fname[MMS_MAX_FILE_NAME_LENGTH] = {0};
	P_MMS_DOCUMENT	pMms_Doc = NULL;
	P_MESSAGELIST      	pMsg = NULL;
	pSENDTO_LIST		plist = NULL;
	U8*					to_list = NULL;
	U8*					cc_list = NULL;
	U8*					bcc_list = NULL;
	int                 			phone_list_len = 0;
	U16 					count = 0;
	S32 					msize = 0;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	mms_get_all_boxes_count_size(&count, &msize);
	if ((count + 1) > MAX_MESSAGE_COUNT)
	{
		DisplayPopup((U8*)GetString(STR_MMS_COUNT_REACHED_MAX), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}

	if ((gpeditor_doc->totalsize+ gauto_recmmssize) > MAX_SIZE_ALL_MMS)
	{
		char		buffer[MMS_MAX_DETAILS_LENGTH] = {0};
		char    	ucs2TempBuff[MAX_HINT_BUF];
		char		ansiiTempBuff[MAX_HINT_BUF*2];

		pfnUnicodeStrcpy(buffer, (const char*)GetString(STR_MMS_QUOTA_EXCEEDED));
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
		sprintf(ansiiTempBuff,"%d K\n",(int)((MAX_SIZE_ALL_MMS/1024) -(gauto_recmmssize/1024)));
		AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
		pfnUnicodeStrcat(buffer, (S8 *)ucs2TempBuff);
		DisplayPopup((U8*)buffer, IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return;
	}
	
	mms_get_randstring(fname);
	strcat(fname, ".mms");
	mms_Tracer((char*)"^_^start to save message^_^");
	if(cms_judge_gpeditor_content()<1)
	{
		DisplayPopup((U8*)GetString(STR_CONTENT_NULL), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	if (!gpeditor_doc->slide_root)
	{
		DisplayPopup((U8*)GetString(STR_CONTENT_NULL), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	pMms_Doc = (P_MMS_DOCUMENT)cms_integrate_mms(gpeditor_doc);
	mms_Tracer((char*)"^_^cms_integrate_mms^_^");

	if (!pMms_Doc)
	{
		mms_Tracer((char*)"error:pMms_Doc == NULL");
		return ;
	}
	if(!MMS_SetMmsFile(pMms_Doc,fname))
	{
		mms_Tracer((char*)"error:MMS_SetMmsFile failed");
		if (pMms_Doc)
		{
			MMS_DeleteMms(pMms_Doc);
			pMms_Doc = NULL;
		}
		return;
	}
	mms_Tracer((char*)"^_^MMS_SetMmsFile^_^");

	if (pgsendtolist)
	{
		/*TO*/
		plist = pgsendtolist;
		phone_list_len = cms_get_sendto_list_len(pgsendtolist)+1;
		to_list	   = (U8 *)mms_Malloc(phone_list_len);	
		memset(to_list,0,phone_list_len);	
		strcpy((char *)to_list, plist->number);	
		while (plist->next)
		{
			plist = plist->next;
			strcat((char *)to_list,",");
			strcat((char *)to_list, plist->number);
		}
	}
	if(pgsendcclist)
	{
		/*CC*/
		plist = pgsendcclist;
		phone_list_len = cms_get_sendto_list_len(pgsendcclist)+1;
		cc_list	   = (U8 *)mms_Malloc(phone_list_len);	
		memset(cc_list,0,phone_list_len);	
		strcpy((char *)cc_list, plist->number);	
		while (plist->next)
		{
			plist = plist->next;
			strcat((char *)cc_list,",");
			strcat((char *)cc_list, plist->number);
		}
	}
	if(pgsendbcclist)
	{
		/*BCC*/
		plist = pgsendbcclist;
		phone_list_len = cms_get_sendto_list_len(pgsendbcclist)+1;
		bcc_list	   = (U8 *)mms_Malloc(phone_list_len);	
		memset(bcc_list,0,phone_list_len);	
		strcpy((char *)bcc_list, plist->number);	
		while (plist->next)
		{
			plist = plist->next;
			strcat((char *)bcc_list,",");
			strcat((char *)bcc_list, plist->number);
		}
	}

	MMS_SetMmsHeadField(pMms_Doc, MMS_MESSAGE_CLASS, (long)MMS_MESSAGE_CLASS_TYPE_PERSONAL, (char *)0);
	if (gconfig.anonymous == MMS_SETTINGS_ON)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_SENDER_VISIBILITY,(long)MMS_SENDER_VISIBILITY_HIDE, (char *)0);
	}
	else
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_SENDER_VISIBILITY,(long)MMS_SENDER_VISIBILITY_SHOW, (char *)0);
	}
	if (gconfig.read_rpt== MMS_SETTINGS_ON)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_READ_REPLY,(long)MMS_READ_REPORT_YES, (char *)0);
	}
	else
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_READ_REPLY,(long)MMS_READ_REPORT_NO, (char *)0);
	}
	if (gconfig.prior == MMS_SETTINGS_PRIORITY_LOW)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_PRIORITY, (long)MMS_PRIORITY_VALUE_LOW, (char *)0);
	}
	else if (gconfig.prior == MMS_SETTINGS_PRIORITY_NORMAL)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_PRIORITY, (long)MMS_PRIORITY_VALUE_NORMAL, (char *)0);
	}
	else
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_PRIORITY, (long)MMS_PRIORITY_VALUE_HIGH, (char *)0);
	}
	if (gconfig.delivery_rpt == MMS_SETTINGS_ON)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_DELIVERY_REPORT, (long)MMS_DELIVERY_REPORT_YES, (char *)0);
	}
	else
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_DELIVERY_REPORT, (long)MMS_DELIVERY_REPORT_NO, (char *)0);
	}
	if (gconfig.expires== MMS_SETTINGS_HOUR)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_EXPIRY, (long)1*3600, (char *)0);
	}
	else if(gconfig.expires== MMS_SETTINGS_DAY)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_EXPIRY, (long)24*3600, (char *)0);
	}
	else if(gconfig.expires== MMS_SETTINGS_WEEK)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_EXPIRY, (long)168*3600, (char *)0);
	}
	else if(gconfig.expires== MMS_SETTINGS_MAX)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_EXPIRY, (long)168*3600, (char *)0);
	}
		
	if (gedit.sub_buf[0] == '\0' && gedit.sub_buf[1] == '\0')
	{
		mms_Tracer((char*)"gedit .sub_buf==NULL");
		pfnUnicodeStrcpy((S8 *)gedit.sub_buf,GetString(STR_NO_SUBJECT));	
	}

	MMS_SetMmsHeadField(pMms_Doc, MMS_SUBJECT, (long)0, (char *)(gedit.sub_buf));

 	mms_mmi_tracer("size = %d",(char*)gpeditor_doc->totalsize);
	if(!MMS_EncodeMms(pMms_Doc))
	{
		mms_Tracer((char*)"error:MMS_EncodeMms failed");
		if (pMms_Doc)
		{
			MMS_DeleteMms(pMms_Doc);
			pMms_Doc = NULL;
		}
		if (to_list)
		{
			mms_Free(to_list);
			to_list = NULL;
		}
		if (cc_list)
		{
			mms_Free(cc_list);
			cc_list = NULL;
		}		
		if (bcc_list)
		{
			mms_Free(bcc_list);
			bcc_list = NULL;
		}
		mmsf_Remove(fname);
		return ;
	}
	MMS_DeleteMms(pMms_Doc);
	pMms_Doc = NULL;
	
	if(!cms_memory_to_flash(fname))
	{
		mms_Tracer((char*)"memory to flash error.......^_^...");
		if (pMms_Doc)
		{
			MMS_DeleteMms(pMms_Doc);
			pMms_Doc = NULL;
		}		
		if (to_list)
		{
			mms_Free(to_list);
			to_list = NULL;
		}
		if (cc_list)
		{
			mms_Free(cc_list);
			cc_list = NULL;
		}		
		if (bcc_list)
		{
			mms_Free(bcc_list);
			bcc_list = NULL;
		}
		mmsf_Remove(fname);
		DisplayPopup((U8*)GetString(STR_MMS_FLASH_WRITE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	mms_Tracer((char*)"^_^cms_memory_to_flash^_^");

	pMsg = mms_file_manager_new_message();
	if (!pMsg)
	{
		if (to_list)
		{
			mms_Free(to_list);
			to_list = NULL;
		}
		if (cc_list)
		{
			mms_Free(cc_list);
			cc_list = NULL;
		}		
		if (bcc_list)
		{
			mms_Free(bcc_list);
			bcc_list = NULL;
		}
		cms_remove_message_file_from_flash(fname);
		return;
	}
	
	{
		char* sub = NULL;
		mms_Tracer((char*)"Save message: start save MSG!!!");
		strcpy(pMsg->fileName, fname);
		CmsTime2String(pMsg->date);
		if (to_list)
		{
			strcpy(pMsg->to_address, (const char*)to_list);
			mms_Free(to_list);
			to_list = NULL;
		}
		if (cc_list)
		{
			strcpy(pMsg->cc_address, (const char*)cc_list);
			mms_Free(cc_list);
			cc_list = NULL;
		}		
		if (bcc_list)
		{
			strcpy(pMsg->bcc_address, (const char*)bcc_list);
			mms_Free(bcc_list);
			bcc_list = NULL;
		}
		if (gedit.sub_buf[0] == '\0' && gedit.sub_buf[1] == '\0')
		{
			mms_Tracer((char*)"no subject");
			pfnUnicodeStrcpy((S8*)gedit.sub_buf, GetString(STR_NO_SUBJECT));
		}
		sub = Cms_mms_uni16_8((char*)gedit.sub_buf);
		strcpy(pMsg->subject, sub);
		mms_Free(sub);
		sub = NULL;

		pMsg->state = 'N';
		pMsg->size = (S32)gpeditor_doc->totalsize;

		mms_file_manager_add_message_to_folder(pMsg, MMS_DRAFT_FOLDER, SET_MESSAGE_NULL);		

		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		mms_Tracer((char*)"end of save MSG");
	}
	mmsflag.gmsg_saved = TRUE;
	
	DisplayPopup((U8*)GetString(STR_SAVE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	mms_Tracer((char*)"^_^end of save message^_^");
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
void mmi_mms_entry_image_folder(void)
{
	FMGR_FILTER filter;	
	
	FMGR_FILTER_INIT(&filter);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_BMP);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_JPG);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_GIF);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_WBMP);
#ifdef CMS_SURPPORT_PNG
	FMGR_FILTER_SET(&filter,FMGR_TYPE_PNG);
#endif
	FMGR_FILTER_SET(&filter,FMGR_TYPE_FOLDER);

	mmi_fmgr_select_path_and_enter(APP_MULTIMEDIA, FMGR_SELECT_FILE, 
									filter, (S8*)L"root", (PsExtFuncPtr)mmi_select_image_callback);
}

 /* ----------------------------------------------------------------------------
 * Function Name: mmi_select_image_callback
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_select_image_callback(void *filePath)
{
	if(filePath==NULL)
	{
		if(IsScreenPresent(SCR_ID_MMS_CONTENT_OPTIONS))
		{
			GoBackToHistory(SCR_ID_MMS_CONTENT_OPTIONS);
		}
		else
		{
			GoBackHistory();
		}	
		return;
	}
	else
	{
		char* buf = NULL;
		char* temp_name = NULL;
		S32 filelen = 0;
		U16 type = 0;
       	 int   i = 0;
		MMS_FILE_HANDLE fp = 0;

		fp = FS_Open((unsigned short*)filePath, FS_READ_ONLY);

		if (fp < 0)
		{
			if(IsScreenPresent(SCR_ID_MMS_CONTENT_OPTIONS))
			{
				GoBackToHistory(SCR_ID_MMS_CONTENT_OPTIONS);
			}
			else
			{
				GoBackHistory();
			}
			DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			return ;
		}
		Cms_Adp_GetFileSize(fp, (unsigned int*)(&filelen));
		if (filelen > MMS_MAX_SIZE_OF_MESSAGE)		/*文件过大*/
		{
			Cms_Adp_fclose(fp);
			DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			DeleteNHistory(2);
			return;
		}
		if (filelen <= 0)
		{
			Cms_Adp_fclose(fp);
			DisplayPopup((U8*)GetString(STR_MMS_MEDIA_FILE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			DeleteNHistory(2);
			return;
		}
		buf = (char *)mms_Malloc(filelen);
		if (!buf)
		{
			return ;
		}
		if (0 != Cms_Adp_fread(fp, buf, filelen, (unsigned int*)(&i))) 
		{
			mms_Free(buf);
			buf = NULL;
			Cms_Adp_fclose(fp);
			return ;
		}
		Cms_Adp_fclose(fp);
		temp_name = Cms_mms_uni16_8(filePath);
		if (temp_name)
		{
			type = mms_get_media_type((U8*)buf, strlen(temp_name), temp_name);
			mms_Free(temp_name);
			temp_name = NULL;
		}
		if (type == 0)
		{
			mms_Free(buf);
			buf = NULL;
			DisplayPopup((U8*)GetString(STR_TYPE_ERROR),IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			DeleteNHistory(2);
			return ;
		}
		mmi_mms_edit_insert_image((char*)buf, filelen, type);
		mms_Free(buf);
		buf = NULL;
	}
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
void mmi_mms_entry_music_folder(void)
{
	FMGR_FILTER filter;	

	FMGR_FILTER_INIT(&filter);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_IMY);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_MID);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_WAV);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_AMR);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_FOLDER);

	mmi_fmgr_select_path_and_enter(APP_MULTIMEDIA, FMGR_SELECT_FILE, filter, 
									(S8*)L"root", (PsExtFuncPtr)mmi_select_music_callback);
}

 /* ----------------------------------------------------------------------------
 * Function Name: mmi_select_music_callback
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_select_music_callback(void *filePath)
{
	if(filePath==NULL)
	{
		if(IsScreenPresent(SCR_ID_MMS_CONTENT_OPTIONS))
		{
			GoBackToHistory(SCR_ID_MMS_CONTENT_OPTIONS);
		}
		else
		{
			GoBackHistory();
		}
		return;
	}
	else 
	{
		char* buf = NULL;
		char* temp_name = NULL;
		S32 filelen = 0;
		U16 type = 0;		
		{
			MMS_FILE_HANDLE fp = 0;
			int i = 0;
			fp = FS_Open(filePath, FS_READ_ONLY);
			
			if (fp < 0)
			{
				DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
				return ;
			}
			FS_GetFileSize(fp, (unsigned int *)(&filelen));
			if (filelen > MMS_MAX_SIZE_OF_MESSAGE)		/*文件过大*/
			{
				Cms_Adp_fclose(fp);
				DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				DeleteNHistory(2);
				return;
			}
			if (filelen <= 0)
			{
				Cms_Adp_fclose(fp);
				DisplayPopup((U8*)GetString(STR_MMS_MEDIA_FILE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
				DeleteNHistory(2);
				return;
			}
			buf = (char *)mms_Malloc(filelen);
			if (!buf)
			{
				return ;
			}
			if (0 != Cms_Adp_fread(fp, buf, filelen,( unsigned int *)(&i))) 
			{
				mms_Free(buf);
				buf = NULL;
				return ;
			}
			Cms_Adp_fclose(fp);
		}
		temp_name = Cms_mms_uni16_8(filePath);
		if (temp_name)
		{
			type = mms_get_media_type((U8*)buf, strlen(temp_name), temp_name);
			mms_Free(temp_name);
			temp_name = NULL;
		}
		if (type == 0)
		{
			DisplayPopup((U8*)GetString(STR_TYPE_ERROR),IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			DeleteNHistory(2);
			mms_Free(buf);
			buf = NULL;
			return ;
		}
		mmi_mms_edit_insert_music((char*)buf, filelen, type);
		mms_Free(buf);
		buf = NULL;
	}
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
void mmi_mms_entry_accessory_folder(void)
{
	FMGR_FILTER filter;	
	
	FMGR_FILTER_INIT(&filter);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_VCF);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_VCS);
	FMGR_FILTER_SET(&filter,FMGR_TYPE_FOLDER);

	mmi_fmgr_select_path_and_enter(APP_MULTIMEDIA, FMGR_SELECT_FILE, 
									filter, (S8*)L"root", (PsExtFuncPtr)mmi_select_accessory_callback);
}
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_select_accessory_callback
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_select_accessory_callback(void *filePath)
{
	if(filePath==NULL)
	{
		if(IsScreenPresent(SCR_ID_MMS_CONTENT_OPTIONS))
		{
			GoBackToHistory(SCR_ID_MMS_CONTENT_OPTIONS);
		}
		else
		{
			GoBackHistory();
		}	
		return;
	}
	else
	{
		char* buf = NULL;
		char* temp_name = NULL;
		S32 filelen = 0;
		U16 type = 0;
       	 int   i = 0;
		MMS_FILE_HANDLE fp = 0;

		fp = FS_Open((unsigned short*)filePath, FS_READ_ONLY);

		if (fp < 0)
		{
			if(IsScreenPresent(SCR_ID_MMS_CONTENT_OPTIONS))
			{
				GoBackToHistory(SCR_ID_MMS_CONTENT_OPTIONS);
			}
			else
			{
				GoBackHistory();
			}
			DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			return ;
		}
		Cms_Adp_GetFileSize(fp, (unsigned int*)(&filelen));
		if (filelen > MMS_MAX_SIZE_OF_MESSAGE)		/*文件过大*/
		{
			Cms_Adp_fclose(fp);
			DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			DeleteNHistory(2);
			return;
		}
		if (filelen <= 0)
		{
			Cms_Adp_fclose(fp);
			DisplayPopup((U8*)GetString(STR_MMS_MEDIA_FILE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			DeleteNHistory(2);
			return;
		}
		buf = (char *)mms_Malloc(filelen);
		if (!buf)
		{
			return ;
		}
		if (0 != Cms_Adp_fread(fp, buf, filelen, (unsigned int*)(&i))) 
		{
			mms_Free(buf);
			buf = NULL;
			Cms_Adp_fclose(fp);
			return ;
		}
		Cms_Adp_fclose(fp);
		temp_name = Cms_mms_uni16_8(filePath);
		if (temp_name)
		{
			type = mms_get_media_type((U8*)buf, strlen(temp_name), temp_name);
			mms_Free(temp_name);
			temp_name = NULL;
		}
		if (type == 0)
		{
			mms_Free(buf);
			buf = NULL;
			DisplayPopup((U8*)GetString(STR_TYPE_ERROR),IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			DeleteNHistory(2);
			return ;
		}
		mmi_mms_edit_insert_accessory((char*)buf, filelen, type);
		mms_Free(buf);
		buf = NULL;
	}
}
 
/* ----------------------------------------------------------------------------
 * Function Name: mms_get_media_type
 *       Purpose: 获取媒体文件类型
 *         Input: buffer: 媒体流 size: 文件名长度 fname: 媒体文件名(包含路径)
 *        Output: None.
 *       Returns:  媒体类型.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
U16 mms_get_media_type(U8* buffer, S32 size, char* fname)
{
	U16 ret = 0;

	if (!strncmp((const char*)buffer,"GIF",3))
		ret = MMS_TYPE_GIF;
	else if((buffer[0] == 0xFF) && \
		(buffer[1] == 0xD8) && \
		(buffer[2] == 0xFF) && \
		(buffer[3] == 0xE0) && \
		(!strncmp((char*)(buffer+6),"JFIF",4)))
		ret = MMS_TYPE_JPEG;
	else if((fname[size-4]=='.') && \
		(fname[size-3]=='J' || fname[size-3]=='j') && \
		(fname[size-2]=='P' || fname[size-2]=='p') && \
		(fname[size-1]=='G' || fname[size-1]=='g'))
		ret = MMS_TYPE_JPEG;
	else if((fname[size-5]=='.') && \
		(fname[size-4]=='J' || fname[size-4]=='j') && \
		(fname[size-3]=='P' || fname[size-3]=='p') && \
		(fname[size-2]=='E' || fname[size-2]=='e') && \
		(fname[size-1]=='G' || fname[size-1]=='g'))
		ret = MMS_TYPE_JPEG;
	else if((fname[size-4]=='.') && \
		(fname[size-3]=='P' || fname[size-3]=='p') && \
		(fname[size-2]=='N' || fname[size-2]=='n') && \
		(fname[size-1]=='G' || fname[size-1]=='g'))
		ret = MMS_TYPE_PNG;
	else if((fname[size-4]=='.') &&
		(fname[size-3]=='B' || fname[size-3]=='b') &&
		(fname[size-2]=='M' || fname[size-2]=='m') &&
		(fname[size-1]=='P' || fname[size-1]=='p'))
		ret = MMS_TYPE_BMP1;
	else if((fname[size-5]=='.') &&
		(fname[size-4]=='W' || fname[size-4]=='w') &&
		(fname[size-3]=='B' || fname[size-3]=='b') &&
		(fname[size-2]=='M' || fname[size-2]=='m') &&
		(fname[size-1]=='P' || fname[size-1]=='p'))
		ret = MMS_TYPE_WBMP;
	else if(!strncmp((const char *)buffer,(const char *)"MThd",4))
		ret = MMS_TYPE_MIDI;
	else if(!strncmp((const char *)buffer,(const char *)"RIFF",4))
		{
		if((fname[size-4]=='.') &&
		(fname[size-3]=='A' || fname[size-3]=='a') &&
		(fname[size-2]=='V' || fname[size-2]=='v') &&
		(fname[size-1]=='I' || fname[size-1]=='i'))
			ret=0;
		else
			ret = MMS_TYPE_WAV;
		}
	else if(!strncmp((const char *)buffer,(const char *)"MMMD",4))
		ret = MMS_TYPE_MMF;
	else if((fname[size-4]=='.') &&
		(fname[size-3]=='W' || fname[size-3]=='w') &&
		(fname[size-2]=='A' || fname[size-2]=='a') &&
		(fname[size-1]=='V' || fname[size-1]=='v'))
		ret = MMS_TYPE_WAV;
	else if((fname[size-4]=='.') &&
		(fname[size-3]=='A' || fname[size-3]=='a') &&
		(fname[size-2]=='M' || fname[size-2]=='m') &&
		(fname[size-1]=='R' || fname[size-1]=='r'))
		ret = MMS_TYPE_AMR;
	else if((fname[size-4]=='.') &&
		(fname[size-3]=='M' || fname[size-3]=='m') &&
		(fname[size-2]=='P' || fname[size-2]=='p') &&
		(fname[size-1]=='3'))
		ret = MMS_TYPE_MP3;
	else if((fname[size-4]=='.') &&
		(fname[size-3]=='M' || fname[size-3]=='m') &&
		(fname[size-2]=='I' || fname[size-2]=='i') &&
		(fname[size-1]=='D' || fname[size-1]=='d'))
		ret = MMS_TYPE_MIDI;
	else if((fname[size-4]=='.') &&
		(fname[size-3]=='I' || fname[size-3]=='i') &&
		(fname[size-2]=='M' || fname[size-2]=='m') &&
		(fname[size-1]=='Y' || fname[size-1]=='y'))
		ret = MMS_TYPE_IMY;
	else if((fname[size-4]=='.') &&
		(fname[size-3]=='M' || fname[size-3]=='m') &&
		(fname[size-2]=='M' || fname[size-2]=='m') &&
		(fname[size-1]=='F' || fname[size-1]=='f'))
		ret = MMS_TYPE_MMF;
	else if((fname[size-4]=='.') &&
		(fname[size-3]=='V' || fname[size-3]=='v') &&
		(fname[size-2]=='C' || fname[size-2]=='c') &&
		(fname[size-1]=='F' || fname[size-1]=='f'))
		ret = MMS_TYPE_VCF;
	else if((fname[size-4]=='.') &&
		(fname[size-3]=='V' || fname[size-3]=='v') &&
		(fname[size-2]=='C' || fname[size-2]=='c') &&
		(fname[size-1]=='S' || fname[size-1]=='s'))
		ret = MMS_TYPE_VCS;
	else
		ret = 0;
	return ret;
}


 /* ----------------------------------------------------------------------------
 * Function Name: mmi_confirm_input_text_handler
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_confirm_input_text_handler(void)
{
	switch(gCurActionItem)
	{
	case 0:		/*完成*/
		switch(ginput_screen)
		{
		case INPUT_OPTION_TEXT:
			mms_add_text_content_confirm();
			break;
		case INPUT_OPTION_SUBJECT:
			mmi_mms_exit_to_new_msg();
			break;
		case INPUT_OPTION_SERVICE_ID:
		case INPUT_OPTION_CENTRE_ADDR:
		case INPUT_OPTION_GATEWAY:
		case INPUT_OPTION_PORT:
			ConfirmInlineFullScreenEdit();
			break;
		case INPUT_OPTION_SAVE_MUSIC:
			mms_save_music_handler();
			break;
		case INPUT_OPTION_SAVE_IMAGE:
			mms_save_image_handler();
			break;
		case INPUT_OPTION_SAVE_ACCESSORY:
			mms_Tracer((char *) "case 0 INPUT_OPTION_SAVE_ACCESSORY in");
			mms_save_accessory_handler();
			break;
		default:
			break;
		}
		break;
	case 1:		/*取消*/
		switch(ginput_screen)
		{
		case INPUT_OPTION_TEXT:
			memset(gedit.text_buf, 0, MMS_MAX_TEXT_SIZE);
			if(IsScreenPresent(SCR_ID_MMS_CONTENT_OPTIONS))
			{
				GoBackToHistory(SCR_ID_MMS_CONTENT_OPTIONS);
			}
			else
			{
				GoBackHistory();
			}
			break;
		case INPUT_OPTION_SUBJECT:
			mmi_mms_exit_sub_input();
			break;
		case INPUT_OPTION_SERVICE_ID:
		case INPUT_OPTION_CENTRE_ADDR:
		case INPUT_OPTION_GATEWAY:
		case INPUT_OPTION_PORT:
			CancelInlineFullScreenEdit();
			break;
		case INPUT_OPTION_SAVE_MUSIC:
			memset(gedit.save_media_fname, 0, MMS_MAX_SAVE_MEDIA_FILENAME_INPUT);
			if(IsScreenPresent(SCR_ID_MMS_SAVE_MUSIC_LIST))
			{
				GoBackToHistory(SCR_ID_MMS_SAVE_MUSIC_LIST);
			}
			else
			{
				GoBackHistory();
			}
			break;
		case INPUT_OPTION_SAVE_IMAGE:
			memset(gedit.save_media_fname, 0, MMS_MAX_SAVE_MEDIA_FILENAME_INPUT);
			if(IsScreenPresent(SCR_ID_MMS_SAVE_IMAGE_LIST))
			{
				GoBackToHistory(SCR_ID_MMS_SAVE_IMAGE_LIST);
			}
			else
			{
				GoBackHistory();
			}
			break;
		case INPUT_OPTION_SAVE_ACCESSORY:
			memset(gedit.save_media_fname, 0, MMS_MAX_SAVE_MEDIA_FILENAME_INPUT);
			if(IsScreenPresent(SCR_ID_MMS_SAVE_ACCESSORY_LIST))
			{
				GoBackToHistory(SCR_ID_MMS_SAVE_ACCESSORY_LIST);
			}
			else
			{
				GoBackHistory();
			}
			break;
		default:
			break;
		}
		break;
	case 2:/*常用短语*/
		{
			mms_Tracer((char *) "mmi_msg_entry_mms_text_template_list^_^");
			mmi_msg_entry_mms_text_template_list();
		}
		break;
	default:
		break;
	}
}
 
 /* ----------------------------------------------------------------------------
 * Function Name: mms_add_text_content_confirm
 *       Purpose: 将编辑完成的文本内容信息写入gpeditor_doc 结构
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_add_text_content_confirm(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	FILE_HANDLE  	fd = 0;
	pMMS_Content 	content = NULL;	
	char				 text_name[MMS_FILE_NAME_LEN];
	unsigned short     	buff_size = 0;
	pMMS_Slide	 	slide = gpeditor_doc->slide_cur;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if (gedit.text_buf[0] == '\0' && gedit.text_buf[1] == '\0')
	{
		DisplayPopup((U8*)GetString(STR_MMS_INPUT_EMPTY), IMG_GLOBAL_EMPTY, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	if (slide->text_flag)	/*判断当前是否已有文本类型？*/
	{
		mms_del_content(gpeditor_doc, slide, MMS_TYPE_TEXT);
		slide->text_flag = 0;
	}
	mms_mmi_tracer(" BEFORE gpeditor_doc->totalsize = %d", (char*)gpeditor_doc->totalsize);
	//2006/07/19 chaozhu.zhou +300betys(180) for the gpeditor_doc totalsize after inserted textbuf 
	if (gpeditor_doc->totalsize + Cms_Browser_Uni16_Uni8_strlen_big((P_CMS_BROWSER_U8)gedit.text_buf) +300> MMS_MAX_SIZE_OF_MESSAGE)
	{
		DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	mms_mmi_tracer("  gpeditor_doc->totalsize = %d", (char*)gpeditor_doc->totalsize);

	mms_get_randstring(text_name);   
	strcat(text_name,".txt");
	
	fd = mmsf_Open(text_name,"w");	
	if(fd <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	buff_size = 2*UCS2Strlen((S8*)gedit.text_buf)+2;
	mms_mmi_tracer("add_text_content_confirm, buff_size= %d",(char*)buff_size);

	mmsf_Write((char *)(&buff_size),1,sizeof(unsigned short),fd);
	mmsf_Write((char *)(gedit.text_buf),1,buff_size,fd);
	mmsf_Close(fd);

	content = MMS_New_Content((U8*)text_name,MMS_TYPE_TEXT,gpeditor_doc->slide_cur,gpeditor_doc);
	if (!content)
	{
		return;
	}
	gedit.total_height = 0;
	if(IsScreenPresent(SCR_ID_SHOW_MESSAGE))
	{
		GoBackToHistory(SCR_ID_SHOW_MESSAGE);
	}
	else
	{
		GoBackHistory();
	}
}
 
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_msg_mms_text_template_callback
 *       Purpose: 彩信插入文本模版回调接口ucs2:  用户选择得到的Unicode文本
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void mmi_msg_mms_text_template_callback(PS8  ucs2)
{
	if(ucs2==NULL)
	{
		mms_Tracer("^_^ insert text is NULL");
		if(IsScreenPresent(SCR_ID_MMS_WMESSAGE_EDIT_TEXT))
		{
			GoBackToHistory(SCR_ID_MMS_WMESSAGE_EDIT_TEXT);
		}
		else
		{
			GoBackHistory();
		}
	}
	else 
	{
		history temphistory;
		historyNode *History;
		memset (& temphistory, 0, sizeof (temphistory));
		GetHistory (SCR_ID_MMS_WMESSAGE_EDIT_TEXT, &temphistory);
		AppendCategory5String(INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,gedit.text_buf,
					MMS_MAX_TEXT_SIZE,(U8*)ucs2, temphistory.guiBuffer);

		if(GetHistoryScrID(SCR_ID_MMS_WMESSAGE_EDIT_TEXT,&History)==ST_SUCCESS)
            	memcpy(History->guiBuffer, temphistory.guiBuffer,MAX_GUI_BUFFER);
		GoBacknHistory (1);
	}

	return;
} 
 /* ----------------------------------------------------------------------------
 * Function Name: mms_save_music_handler
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_save_music_handler(void)
{
	if (gedit.save_media_fname[0] == '\0' && gedit.save_media_fname[1] == '\0')
	{
		DisplayPopup((U8*)GetString(STR_ILLEGAL_INPUT), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	else
	{	/*保存至音乐文件夹*/
		char *fname_uni = NULL;
		char fname[64] ={0};
		
		strcpy(fname, (const char*)CMS_MMS_AUDIO_SAVE_PATH);
		
		fname_uni = Cms_mms_uni16_8((char *)gedit.save_media_fname);
		strcat(fname, (const char*)fname_uni);
		/*音乐类型,后缀名!*/
		switch(gedit.media_type)
		{
		case MMS_TYPE_WAV:
			strcat(fname,".wav");
			break;
		case MMS_TYPE_IMY:
			strcat(fname,".imy");
			break;
		case MMS_TYPE_MIDI:
			strcat(fname,".mid");
			break;
		case MMS_TYPE_AMR:
			strcat(fname,".amr");
			break;
		default:
			mms_Free(fname_uni);
			fname_uni = NULL;
			DisplayPopup((U8*)GetString(STR_MMS_SAVE_MEDIA_FORMAT_UNKNOWN), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			return;
		}
		if (Cms_Adp_FileExists(fname))
		{
			mms_Free(fname_uni);
			fname_uni = NULL;
			DisplayPopup((U8*)GetString(STR_FILE_EXISTED), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			return ;
		}
		else
		{
			FS_HANDLE fh = 0;
			U16 wd = 0;
			fh = Cms_Adp_fopen((S8*)fname, FS_CREATE_ALWAYS);
			if(fh < 0)
			{
				DisplayPopup((U8*)GetString(STR_ILLEGAL_INPUT), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
				mms_Free(fname_uni);
				fname_uni = NULL;
				return ;
			}
			if(Cms_Adp_JudgeDSpace((int)gedit.media_len))	
			{
				FS_Close(fh);
				DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				return;		
			}				
			if(0 != Cms_Adp_fwrite(fh, gedit.media_buf, (U32)gedit.media_len, (unsigned int*)(&wd)))
			{
				Cms_Adp_fclose(fh);
				mms_Free(fname_uni);
				fname_uni = NULL;
				if(IsScreenPresent(SCR_ID_MMS_SAVE_MUSIC_LIST))
				{
					GoBackToHistory(SCR_ID_MMS_SAVE_MUSIC_LIST);
				}
				else
				{
					GoBackHistory();
				}
				DisplayPopup((U8*)GetString(STR_MMS_FLASH_WRITE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
				return;
			}
			Cms_Adp_fclose(fh);
			mms_Free(fname_uni);
			fname_uni = NULL;

			memset(gedit.save_media_fname, 0, MMS_MAX_SAVE_MEDIA_FILENAME_INPUT);
			if(IsScreenPresent(SCR_ID_MMS_SAVE_MUSIC_LIST))
			{
				GoBackToHistory(SCR_ID_MMS_SAVE_MUSIC_LIST);
			}
			else
			{
				GoBackHistory();
			}
			DisplayPopup((U8*)GetString(STR_SAVE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
			
		}
	}
}
 /* ----------------------------------------------------------------------------
 * Function Name: mms_save_image_handler
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_save_image_handler(void)
{

	if (gedit.save_media_fname[0] == '\0' && gedit.save_media_fname[1] == '\0')
	{
		DisplayPopup((U8*)GetString(STR_ILLEGAL_INPUT), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	else
	{
		char *	fname_uni = NULL;
		char 	fname[64] = {0};
		strcpy(fname, (const char*)CMS_MMS_IMAGE_SAVE_PATH);

		fname_uni = Cms_mms_uni16_8((char *)gedit.save_media_fname);
		strcat(fname, (const char*)fname_uni);
		/*图像类型,后缀名*/
		switch(gedit.media_type)
		{
		case MMS_TYPE_GIF:
			strcat(fname,".gif");
			break;
		case MMS_TYPE_JPEG:
			strcat(fname,".jpg");
			break;
#ifdef CMS_SURPPORT_PNG
		case MMS_TYPE_PNG:
			strcat(fname,".png");
			break;
#endif
		case MMS_TYPE_WBMP:
			strcat(fname,".wbmp");
			break;
		case MMS_TYPE_BMP1:
			strcat(fname, ".bmp");
			break;
		default:
			mms_Free(fname_uni);
			fname_uni = NULL;
			DisplayPopup((U8*)GetString(STR_MMS_SAVE_MEDIA_FORMAT_UNKNOWN), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			return;
		}
		if (Cms_Adp_FileExists(fname))
		{
			mms_Free(fname_uni);
			fname_uni = NULL;
			DisplayPopup((U8*)GetString(STR_FILE_EXISTED), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			return ;
		}
		else
		{
			FS_HANDLE fh = 0;
			U16 wd = 0;
			fh = Cms_Adp_fopen((S8*)fname, FS_CREATE_ALWAYS);
			if(fh < 0)
			{
				DisplayPopup((U8*)GetString(STR_ILLEGAL_INPUT), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
				mms_Free(fname_uni);
				fname_uni = NULL;
				return ;
			}
			if(Cms_Adp_JudgeDSpace((int)gedit.media_len))	
			{
				FS_Close(fh);
				DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				return;		
			}
			if (gedit.media_type==MMS_TYPE_GIF)
			{
				if(0 != Cms_Adp_fwrite(fh, (char*)gedit.media_buf+8, (U32)gedit.media_len, (unsigned int*)(&wd)))
				{
					Cms_Adp_fclose(fh);
					mms_Free(fname_uni);
					fname_uni = NULL;			
					if(IsScreenPresent(SCR_ID_MMS_SAVE_IMAGE_LIST))
					{
						GoBackToHistory(SCR_ID_MMS_SAVE_IMAGE_LIST);
					}
					else
					{
						GoBackHistory();
					}
					DisplayPopup((U8*)GetString(STR_MMS_FLASH_WRITE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
					return;
				}
			Cms_Adp_fclose(fh);
			}
			else
			{
				if(0 != Cms_Adp_fwrite(fh, (char*)gedit.media_buf, (U32)gedit.media_len, (unsigned int*)(&wd)))
				{
					Cms_Adp_fclose(fh);
					mms_Free(fname_uni);
					fname_uni = NULL;
					if(IsScreenPresent(SCR_ID_MMS_SAVE_IMAGE_LIST))
					{
						GoBackToHistory(SCR_ID_MMS_SAVE_IMAGE_LIST);
					}
					else
					{
						GoBackHistory();
					}
					DisplayPopup((U8*)GetString(STR_MMS_FLASH_WRITE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
					return;
				}
			Cms_Adp_fclose(fh);
			}
			mms_Free(fname_uni);
			fname_uni = NULL;
			memset(gedit.save_media_fname, 0, MMS_MAX_SAVE_MEDIA_FILENAME_INPUT);
			if(IsScreenPresent(SCR_ID_MMS_SAVE_IMAGE_LIST))
			{
				GoBackToHistory(SCR_ID_MMS_SAVE_IMAGE_LIST);
			}
			else
			{
				GoBackHistory();
			}
			DisplayPopup((U8*)GetString(STR_SAVE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
		}
	}
}
 /* ----------------------------------------------------------------------------
 * Function Name: mms_save_accessory_handler
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_save_accessory_handler(void)
{
	mms_Tracer((char *) "mms_save_accessory_handler in");
	if (gedit.save_media_fname[0] == '\0' && gedit.save_media_fname[1] == '\0')
	{
		DisplayPopup((U8*)GetString(STR_ILLEGAL_INPUT), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	else
	{	
		//char *fname_uni = NULL;
		char 	fname[MMS_MAX_FILE_NAME_LENGTH] ={0};
		char *	fname_uni = NULL;
		pMMS_Content 	content = NULL;
		pMMS_Slide 		slide=NULL;
		char* 			accessorybuf=NULL; 
		FS_HANDLE 		FD=0;
		U16 				wd = 0;
		int                         i = 0;
		
		strcpy(fname, (const char*)CMS_MMS_ACCESSORY_SAVE_PATH);
		
		fname_uni = Cms_mms_uni16_8((char *)gedit.save_media_fname);
		strcat(fname, (const char*)fname_uni);

		mms_Free(fname_uni);
		fname_uni=NULL;

		
#if 0		
		/*图像类型,后缀名*/
		switch(gedit.media_type)
		{
		case MMS_TYPE_VCF:
			strcat(fname,".vcf");
			mms_Tracer((char *) "in MMS_TYPE_VCF");
			mms_mmi_tracer("11fname = %s", (char*)fname);
			break;
		case MMS_TYPE_VCS:
			strcat(fname,".vcs");
			mms_Tracer((char *) "in MMS_TYPE_VCS");
			mms_mmi_tracer("22fname = %s", (char*)fname);
			break;
		default:
			break;
		}
#endif		

		slide = gpeditor_doc->slide_root;
		
		while (i <= ghiliindex1 && slide)
		{
			if (slide->accessory_flag == 1)   
			{
				content = slide->content_root;
				while (content)
				{
					#if 0
					if (content->type == MMS_TYPE_VCF ||
						content->type == MMS_TYPE_VCS
						)
					{
						mms_Tracer((char *) "in MMS_TYPE_VCF or MMS_TYPE_VCS");
						break;
					}
					#endif
					
					if (content->type == MMS_TYPE_VCF)
					{
						strcat(fname,".vcf");
						mms_Tracer((char *) "in MMS_TYPE_VCF");
						mms_mmi_tracer("11fname = %s", (char*)fname);
						break;
					}
					if (content->type == MMS_TYPE_VCS)
					{
						strcat(fname,".vcs");
						mms_Tracer((char *) "in MMS_TYPE_VCS");
						mms_mmi_tracer("22fname = %s", (char*)fname);
						break;
					}
					
					content = content->next;
				}
				i++;
			}
			slide = slide->next;
		}	
		
		/*get default vCard filename*/
		cms_getmedia_fllename((char*)content->filename);
		
		mms_mmi_tracer("filename = %s", (char*)content->filename);

		FD = mmsf_Open(content->filename,"r");
		accessorybuf=cms_malloc(content->contentsize+1);
		memset(accessorybuf,0,content->contentsize+1);
		mmsf_Read((char*)accessorybuf, 1, content->contentsize, FD);
		mmsf_Close( FD);
			
		FD = Cms_Adp_fopen((S8*)fname, FS_CREATE_ALWAYS);
		if(FD < 0)
		{
			DisplayPopup((U8*)GetString(STR_ILLEGAL_INPUT), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			mms_Free(accessorybuf);
			accessorybuf = NULL;
			return ;
		}
		if(Cms_Adp_JudgeDSpace((int)content->contentsize))	
		{
			mms_Free(accessorybuf);
			accessorybuf = NULL;
			FS_Close(FD);
			DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			return;		
		}
		
		if(0 != Cms_Adp_fwrite(FD, accessorybuf, (U32)content->contentsize, (unsigned int*)(&wd)))
		{
			Cms_Adp_fclose(FD);
			mms_Free(accessorybuf);
			accessorybuf = NULL;
			if(IsScreenPresent(SCR_ID_MMS_SAVE_ACCESSORY_LIST))
			{
				GoBackToHistory(SCR_ID_MMS_SAVE_ACCESSORY_LIST);
			}
			else
			{
				GoBackHistory();
			}
			DisplayPopup((U8*)GetString(STR_MMS_FLASH_WRITE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			return;
		}
		Cms_Adp_fclose(FD);
		mms_Free(accessorybuf);
		accessorybuf = NULL;
		memset(gedit.save_media_fname, 0, MMS_MAX_SAVE_MEDIA_FILENAME_INPUT);
		if(IsScreenPresent(SCR_ID_MMS_SAVE_ACCESSORY_LIST))
		{
			GoBackToHistory(SCR_ID_MMS_SAVE_ACCESSORY_LIST);
		}
		else
		{
			GoBackHistory();
		}
		DisplayPopup((U8*)GetString(STR_SAVE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);

	}
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_input_options
 *       Purpose: entry input screen (finish/cancel)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_input_options(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 guiBuffer=NULL;		/* Buffer holding history data */
	U16	 nStrItemList[MAX_SUB_MENUS];	/* Stores the strings id of submenus returned */
	U16	 itemIcons[MAX_SUB_MENUS];		/* Stores the icon id of submenus returned */
	U16	 screenId=SCR_ID_INPUT_OPTION;
	U8** pPopUpList=NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_input_options, NULL);

	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	nStrItemList[0] = STR_GLOBAL_DONE;
	nStrItemList[1] = STR_GLOBAL_CANCEL;
	itemIcons[0] = IMG_GLOBAL_L1;
	itemIcons[1] = IMG_GLOBAL_L2;
	if(ginput_screen == INPUT_OPTION_TEXT)
	{
		nStrItemList[2] = STR_GLOBAL_USE_TEMPLATE;
		itemIcons[2] = IMG_GLOBAL_L3;

		RegisterHighlightHandler(mmi_get_cur_sub_hiliIndex);
		/* set current screen id */
		SetMessagesCurrScrnID(screenId);

		/* Display the call history main screen */
		ShowCategory52Screen(STR_GLOBAL_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
							  STR_GLOBAL_OK, IMG_GLOBAL_OK,
							  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							  2, nStrItemList, itemIcons,
							  (U8 **) pPopUpList, 0, 0,
							  guiBuffer );
	}
	else
	{
		RegisterHighlightHandler(mmi_get_cur_sub_hiliIndex);
		
		/* set current screen id */
		SetMessagesCurrScrnID(screenId);

		/* Display the call history main screen */
		ShowCategory52Screen(STR_GLOBAL_OPTIONS, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
							  STR_GLOBAL_OK, IMG_GLOBAL_OK,
							  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							  2, nStrItemList, itemIcons,
							  (U8 **) pPopUpList, 0, 0,
							  guiBuffer );
	}
	/* Register function with right softkey */
	SetLeftSoftkeyFunction(mmi_confirm_input_text_handler, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


 #if 1
 /******************************************************************************
 *                           MMS FILE MANAGER                           *
 ******************************************************************************/

/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_init
 *       Purpose: init mms file manager
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_init(void)
{
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	  mms_Tracer((char*)"mms_file_manager_init in");
	  if(pgManager != NULL)
	  {
		  mms_file_manager_destory();
	  }
	  /* 创建管理器 */
	  mms_file_manager_create();
	  /* 将各个信箱的摘要信息读到管理其中 */
	  mms_file_manager_read_all_folders();
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_create
 *       Purpose: create mms file manager
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
static void mms_file_manager_create(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGEFOLDER	folder = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/	
	if(pgManager)
	{
		return ;
	}
	/* 创建管理器 */
	pgManager = (P_MANAGER)mms_Malloc(sizeof(MANAGERDOCUMENT));
	
	if(!pgManager)
	{
		mms_Tracer((char*)"manager init error!!!");
		return ;
	}
	memset(pgManager, 0, sizeof(MANAGERDOCUMENT));
	/* 创建收件箱 */
	folder = (P_MESSAGEFOLDER)mms_Malloc(sizeof(MESSAGEFOLDER));
	if(folder)
	{
		memset(folder, 0, sizeof(MESSAGEFOLDER));
		pgManager->receiveFolder = folder;
	}
	/* 创建发件箱 */
	folder = NULL;
	folder = (P_MESSAGEFOLDER)mms_Malloc(sizeof(MESSAGEFOLDER));
	if(folder)
	{
		memset(folder, 0, sizeof(MESSAGEFOLDER));
		pgManager->sendFolder = folder;
	}
	/* 创建草稿箱 */
	folder = NULL;
	folder = (P_MESSAGEFOLDER)mms_Malloc(sizeof(MESSAGEFOLDER));
	if(folder)
	{
		memset(folder, 0, sizeof(MESSAGEFOLDER));
		pgManager->draftFolder = folder;
	}
	return ;
}

/* ----------------------------------------------------------------------------
 * Function Name:mms_file_manager_destory 
 *       Purpose: destory mms file manager 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_destory(void)
{

	if (pgManager)
	{
		mms_file_manager_delete();
	}
}
/* ----------------------------------------------------------------------------
 * Function Name:mms_file_manager_delete 
 *       Purpose: delete mms file manager 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_delete(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGEFOLDER	del_folder = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if(!pgManager)
	{
		mms_Tracer((char*)"file manager not exists!!!");
		return ;
	}
	/* 先删除收件箱 */
	del_folder = pgManager->receiveFolder;
	if(del_folder)
	{
		mms_file_manager_set_current_folder(MMS_RECEIVE_FOLDER);
		mms_file_manager_destory_current_folder();
		mms_Free(del_folder);
		del_folder = NULL;
	}	
	/* 再删除发件箱 */
	del_folder = pgManager->sendFolder;
	if(del_folder)
	{
		mms_file_manager_set_current_folder(MMS_SEND_FOLDER);
		mms_file_manager_destory_current_folder();
		mms_Free(del_folder);
		del_folder = NULL;
	}
	/* 再删除草稿箱 */
	del_folder = pgManager->draftFolder;
	if(del_folder)
	{
		mms_file_manager_set_current_folder(MMS_DRAFT_FOLDER);
		mms_file_manager_destory_current_folder();
		mms_Free(del_folder);
		del_folder = NULL;
	}
	/* 最后删除管理器 */
	mms_Free(pgManager);
	pgManager = NULL;	
	return ;
}

/* ----------------------------------------------------------------------------
 * Function Name:mms_file_manager_destory_current_folder 
 *       Purpose: destory mms current folder
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_destory_current_folder(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGELIST		tlist = NULL;
	P_MESSAGELIST		temp = NULL;
	P_MESSAGEFOLDER 	folder =  NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	/* 入口条件判断 */
	if(!pgManager)
	{
		mms_Tracer((char*)"file manager not exists!!!");
		return ;
	}
	if(!pgManager->currentFolder)
	{
		mms_Tracer((char*)"current folder not exists!!!");
		return ;
	}
	/* 清除当前信箱所占内存资源 */
	folder = pgManager->currentFolder;
	if(folder != NULL)
	{
		for(tlist=folder->root; tlist!=NULL;)
		{
			temp = tlist->next;
			mms_file_manager_delete_message_node(tlist);
			mms_file_manager_free_message(tlist);
			tlist = temp;
		}
	}
	folder->root = NULL;
	folder->messageNumber = 0;
	folder->currentMessage = NULL;
	folder->pushMessage = NULL;
	return;
}
#ifdef SUPPORT_SMSMMS_COMBINE
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_new_sms_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
P_MESSAGELIST mms_file_manager_new_sms_message(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGELIST tlist = NULL;	
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	tlist = (P_MESSAGELIST)mms_Malloc(sizeof(MESSAGELIST));
	if (!tlist)
	{
		return NULL;
	}
	memset(tlist, 0, sizeof(MESSAGELIST));
	
	tlist->date = (S8*)mms_Malloc(MMS_MAX_DATE_LEN);
	if (!tlist->date)
	{
		mms_file_manager_free_message(tlist);
		tlist = NULL;
		return NULL;
	}
	memset(tlist->date, 0, MMS_MAX_DATE_LEN);
	
	tlist->size = 0;
	tlist->state = 'N';
	tlist->expriy_time=0;
	tlist->msgtype=MESSAGE_NULL;
	tlist->SmsIndex=0;
	
	return tlist;
}
#endif
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_new_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
P_MESSAGELIST mms_file_manager_new_message(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGELIST tlist = NULL;	
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	tlist = (P_MESSAGELIST)mms_Malloc(sizeof(MESSAGELIST));
	if (!tlist)
	{
		return NULL;
	}
	memset(tlist, 0, sizeof(MESSAGELIST));
	
	tlist->fileName = (S8*)mms_Malloc(MMS_MAX_FILE_NAME_LENGTH);
	if (!tlist->fileName)
	{
		mms_file_manager_free_message(tlist);
		tlist = NULL;
		return NULL;
	}
	tlist->subject = (S8*)mms_Malloc(MMS_MAX_UTF_SUBJECT_SIZE);
	if (!tlist->subject)
	{
		mms_file_manager_free_message(tlist);
		tlist = NULL;
		return NULL;
	}
	tlist->to_address = (S8*)mms_Malloc(MMS_MAX_INPUT_SEND_TO_SIZE * 10 +20);
	if (!tlist->to_address)
	{
		mms_file_manager_free_message(tlist);
		tlist = NULL;
		return NULL;
	}
      tlist->cc_address = (S8*)mms_Malloc(MMS_MAX_INPUT_SEND_TO_SIZE * 10 +20);
	if (!tlist->cc_address)
	{
		mms_file_manager_free_message(tlist);
		tlist = NULL;
		return NULL;
	}
      tlist->bcc_address = (S8*)mms_Malloc(MMS_MAX_INPUT_SEND_TO_SIZE * 10 +20);
	if (!tlist->bcc_address)
	{
		mms_file_manager_free_message(tlist);
		tlist = NULL;
		return NULL;
	}
	tlist->date = (S8*)mms_Malloc(MMS_MAX_DATE_LEN);
	if (!tlist->date)
	{
		mms_file_manager_free_message(tlist);
		tlist = NULL;
		return NULL;
	}
	memset(tlist->fileName, 0, MMS_MAX_FILE_NAME_LENGTH);
	memset(tlist->subject, 0, MMS_MAX_UTF_SUBJECT_SIZE);	
	memset(tlist->to_address, 0, MMS_MAX_INPUT_SEND_TO_SIZE * 10 +20);
	memset(tlist->cc_address, 0, MMS_MAX_INPUT_SEND_TO_SIZE * 10 +20);
	memset(tlist->bcc_address, 0, MMS_MAX_INPUT_SEND_TO_SIZE * 10 +20);
	memset(tlist->date, 0, MMS_MAX_DATE_LEN);
	
	tlist->size = 0;
	tlist->state = 'N';
	tlist->expriy_time=0;
	tlist->msgtype=MESSAGE_NULL;

#ifdef SUPPORT_SMSMMS_COMBINE
	tlist->SmsIndex=0;
#endif
	return tlist;
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_free_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_free_message(P_MESSAGELIST mlist)
{	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (mlist->fileName)
	{
		mms_Free(mlist->fileName);
		mlist->fileName = NULL;
	}
	if (mlist->subject)
	{
		mms_Free(mlist->subject);
		mlist->subject = NULL;
	}
	if (mlist->date)
	{
		mms_Free(mlist->date);
		mlist->date = NULL;
	}
	if (mlist->to_address)
	{
		mms_Free(mlist->to_address);
		mlist->to_address = NULL;
	}
       if (mlist->cc_address)
	{
		mms_Free(mlist->cc_address);
		mlist->cc_address = NULL;
	}
       if (mlist->bcc_address)
	{
		mms_Free(mlist->bcc_address);
		mlist->bcc_address = NULL;
	}
	if (mlist->url)
	{
		mms_Free(mlist->url);
		mlist->url = NULL;
	}
#ifdef SUPPORT_OTA_PUSH
	if (mlist->ota_name)
	{
		mms_Free(mlist->ota_name);
		mlist->ota_name = NULL;
	}
	if (mlist->ota_gateway)
	{
		mms_Free(mlist->ota_gateway);
		mlist->ota_gateway = NULL;
	}
	if (mlist->ota_port)
	{
		mms_Free(mlist->ota_port);
		mlist->ota_port = NULL;
	}
	if (mlist->ota_netacc)
	{
		mms_Free(mlist->ota_netacc);
		mlist->ota_netacc = NULL;
	}
	if (mlist->ota_murl)
	{
		mms_Free(mlist->ota_murl);
		mlist->ota_murl = NULL;
	}
	
	if (mlist->ota_smsc)
	{
		mms_Free(mlist->ota_smsc);
		mlist->ota_smsc= NULL;
	}	
	if (mlist->ota_ispname)
	{
		mms_Free(mlist->ota_ispname);
		mlist->ota_ispname= NULL;
	}
	if (mlist->ota_csdscode)
	{
		mms_Free(mlist->ota_csdscode);
		mlist->ota_csdscode= NULL;
	}	
	if (mlist->ota_apn)
	{
		mms_Free(mlist->ota_apn);
		mlist->ota_apn= NULL;
	}
	if (mlist->ota_user)
	{
		mms_Free(mlist->ota_user);
		mlist->ota_user= NULL;
	}	
	if (mlist->ota_passw)
	{
		mms_Free(mlist->ota_passw);
		mlist->ota_passw= NULL;
	}
	if (mlist->ota_authtype)
	{
		mms_Free(mlist->ota_authtype);
		mlist->ota_authtype= NULL;
	}	
	if (mlist->ota_logintype)
	{
		mms_Free(mlist->ota_logintype);
		mlist->ota_logintype= NULL;
	}
	if (mlist->ota_bmurl)
	{
		mms_Free(mlist->ota_bmurl);
		mlist->ota_bmurl= NULL;
	}
	
	if (mlist->ota_bmname)
	{
		mms_Free(mlist->ota_bmname);
		mlist->ota_bmname= NULL;
	}
#endif
	
	mlist->next = NULL;
	mlist->size = 0;
	mlist->expriy_time=0;
	mlist->state = NULL;
	mlist->msgtype=MESSAGE_NULL;
	mms_Free(mlist);
	
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_add_message_to_current_folder
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_add_message_to_current_folder(P_MESSAGELIST mmsDigest)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGELIST list = NULL;
	  	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	  if(mmsDigest == NULL)
	  {
		  mms_Tracer((char*)"error:--mmsDigest == NULL");
		  return ;
	  }
	  if(pgManager->currentFolder == NULL)
	  {
		  mms_Tracer((char*)"error:--pgManager->currentFolder == NULL");		  
		  return ;
	  }
	  if((pgManager->currentFolder != pgManager->receiveFolder) \
		  && (pgManager->currentFolder != pgManager->sendFolder)\
		  && (pgManager->currentFolder != pgManager->draftFolder))
	  {		  
		  mms_Tracer((char*)"error:--no folder exist");
		  return ;
	  }
	  /* 生成一个新节点存放待添加的mms摘要信息 */
	  list = (P_MESSAGELIST)mms_Malloc(sizeof(MESSAGELIST));
	  if(!list)
	  {
		  mms_Tracer((char*)"error:--list malloc failed");
		  return ;
	  }

	  memset(list, 0, sizeof(MESSAGELIST));

	  list->state = mmsDigest->state;
	  list->size = mmsDigest->size;	
	  list->expriy_time= mmsDigest->expriy_time;	
	  list->msgtype= mmsDigest->msgtype;	
	  /* 将待添加mms的文件名拷贝到新节点中 */
	  if(mmsDigest->fileName != NULL)
	  {
		  list->fileName = (S8*)mms_Malloc(strlen(mmsDigest->fileName) + 1);
		  if(list->fileName == NULL)
		  {
			  mms_Tracer((char*)"error:--list->fileName malloc failed");
			  mms_file_manager_free_message(list);
			  list = NULL;
			  return ;
		  }
		  memset(list->fileName, 0, strlen(mmsDigest->fileName) + 1);
		  strcpy(list->fileName, mmsDigest->fileName);
	  }
	  
	  /* 将待添加mms的地址(TO)信息拷贝到新节点中 */
	  if (mmsDigest->to_address != NULL)
	  {
		  if (mmsDigest->to_address[0] != 0)
		  {
			  list->to_address = (S8*)mms_Malloc(strlen(mmsDigest->to_address) + 1);
			  if(list->to_address == NULL)
			  {
				  mms_Tracer((char*)"error:--list->address malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->to_address,0, strlen(mmsDigest->to_address) + 1);
			  strcpy(list->to_address,mmsDigest->to_address);
		  }
	  }
	   /* 将待添加mms的地址(CC)信息拷贝到新节点中 */
	  if (mmsDigest->cc_address != NULL)
	  {
		  if (mmsDigest->cc_address[0] != 0)
		  {
			  list->cc_address = (S8*)mms_Malloc(strlen(mmsDigest->cc_address) + 1);
			  if(list->cc_address == NULL)
			  {
				  mms_Tracer((char*)"error:--list->cc_address malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->cc_address,0, strlen(mmsDigest->cc_address) + 1);
			  strcpy(list->cc_address,mmsDigest->cc_address);
		  }
	  }
	 /* 将待添加mms的地址(BCC)信息拷贝到新节点中 */
	  if (mmsDigest->bcc_address != NULL)
	  {
		  if (mmsDigest->bcc_address[0] != 0)
		  {
			  list->bcc_address = (S8*)mms_Malloc(strlen(mmsDigest->bcc_address) + 1);
			  if(list->bcc_address == NULL)
			  {
				  mms_Tracer((char*)"error:--list->bcc_address malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->bcc_address,0, strlen(mmsDigest->bcc_address) + 1);
			  strcpy(list->bcc_address,mmsDigest->bcc_address);
		  }
	  }
	  /* 将待添加mms的主题信息拷贝到新节点中 */
	  if (mmsDigest->subject != NULL)
	  {
		  if (mmsDigest->subject[0] != 0)
		  {
			  list->subject = (S8*)mms_Malloc(strlen(mmsDigest->subject) + 1);
			  if(list->subject == NULL)
			  {
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->subject, 0, strlen(mmsDigest->subject) + 1);
			  strcpy(list->subject, mmsDigest->subject);
		  }
	  }
	  /* 将待添加mms的url信息拷贝到新节点中 */
	  if (mmsDigest->url != NULL)
	  {
		  if (mmsDigest->url[0] != 0) 
		  {
			  list->url = (S8*)mms_Malloc(strlen(mmsDigest->url) + 1);
			  if(list->url == NULL)
			  {
				  mms_Tracer((char*)"error:--list->url malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->url, 0, strlen(mmsDigest->url) + 1);
			  strcpy(list->url, mmsDigest->url);
		  }
	  }
	  /* 将待添加mms的日期信息拷贝到新节点中 */
	  if (mmsDigest->date != NULL)
	  {
		  if (mmsDigest->date[0] != 0) 
		  {
			  list->date = (S8*)mms_Malloc(strlen(mmsDigest->date) + 1);
			  if(list->date == NULL)
			  {
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->date, 0, strlen(mmsDigest->date) + 1);
			  strcpy(list->date, mmsDigest->date);
		  }
	  }
	  /* 待添加的节点放在管理器对应的根节点 */
	  list->next = pgManager->currentFolder->root;
	  pgManager->currentFolder->root = list;
	  
	  /* 新添加的mms设为当前的mms */
	  pgManager->currentFolder->currentMessage = list;
	  
	  /* 管理器对应的mms总数增1 */
	  pgManager->currentFolder->messageNumber++;
	  pgManager->currentFolder->messageSize += list->size;

	  mms_file_manager_store_current_folder();
	  mms_file_manager_set_current_message(list);  
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_add_message_to_folder
 *       Purpose: add mms to folder
 *         Input: P_MESSAGELIST mmsDigest, MMS_FOLDER_NAME folder, SET_MESSAGE flag
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_add_message_to_folder(P_MESSAGELIST mmsDigest, MMS_FOLDER_NAME folder, SET_MESSAGE flag)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	  P_MESSAGELIST 		list = NULL;
	  P_MESSAGEFOLDER 	box = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	  if(mmsDigest == NULL)
	  {
		  mms_Tracer((char*)"error:--mmsDigest == NULL");
		  return ;
	  }
	  switch(folder)
	  {
	  case MMS_FOLDER_UNKNOWN:
		  mms_Tracer((char*)"error:--no folder exist");
		  return;
	  case MMS_RECEIVE_FOLDER:
		  box = pgManager->receiveFolder;
	  	  break;
	  case MMS_SEND_FOLDER:
		  box = pgManager->sendFolder;
	  	  break;
	  case MMS_DRAFT_FOLDER:
		  box = pgManager->draftFolder;
	  	  break;
	  }
	  /* 生成一个新节点存放待添加的mms摘要信息 */
	  list = (P_MESSAGELIST)mms_Malloc(sizeof(MESSAGELIST));
	  if(!list)
	  {
		  mms_Tracer((char*)"error:--list malloc failed");
		  return ;
	  }
	  memset(list, 0, sizeof(MESSAGELIST));

#ifdef SUPPORT_SMSMMS_COMBINE
	if(mmsDigest->msgtype==MESSAGE_SMS)
	{
		list->msgtype=mmsDigest->msgtype;
		list->SmsIndex=mmsDigest->SmsIndex;
		list->size=mmsDigest->size;
		/* 将待添加mms的日期信息拷贝到新节点中 */
		if (mmsDigest->date != NULL)
		{
			if (mmsDigest->date[0] != 0)
			{
				list->date = (S8*)mms_Malloc(strlen(mmsDigest->date) + 1);
				if(list->date == NULL)
				{
					mms_Tracer((char*)"error:--list->date malloc failed");
					mms_file_manager_free_message(list);
					list = NULL;
					return ;
				}
				memset(list->date, 0, strlen(mmsDigest->date) + 1);
				strcpy(list->date, mmsDigest->date);
				mms_mmi_tracer("^_^sms list->date=%s", (char*)list->date);

			}
		}
		
		/* 待添加的节点放在管理器对应的根节点 */
		if(box->root==NULL)
		{
			box->root=list;
			box->root->next=NULL;
			mms_Tracer((char*)"add sms box->root==NULL");
		}
		/* 如果pnode等于开头节点则是插入第一个节点 */
		else
		{
			P_MESSAGELIST ptemplist=NULL,pprelist=NULL;
			ptemplist=box->root;
			pprelist=ptemplist;
			while((strcmp((char*)ptemplist->date,(char*)list->date)>0)&&(ptemplist->next!=NULL))/*插入的时间小于前面的时间&&不是头节点*/
			{

				pprelist=ptemplist;/*使pprelist指向刚才ptemplist指向的结点*/
				ptemplist=ptemplist->next;/*ptemplist向后移一个结点*/
			}
			if((strcmp((char*)ptemplist->date,(char*)list->date)<=0)&&(ptemplist->next==NULL))
			{
				  mms_Tracer((char*)"add sms if strcmp date <=0 && ptemplist->next==NUL");
				  if(ptemplist==box->root)/*插入到原来第一个节点之前*/
				  {
				  	box->root=list;			
				  }
				  else/*插入到pprelist节点之后*/
				  {
				  	pprelist->next=list;
				  }
				  list->next=ptemplist;  
			}
		  	else if(strcmp((char*)ptemplist->date,(char*)list->date)<=0)
			{
				if(ptemplist==box->root)/*插入到原来第一个节点之前*/
				{
					box->root=list;			
				}
				else/*插入到pprelist节点之后*/
				{
					pprelist->next=list;
				}
				list->next=ptemplist;
			}
			else
			{
				/*插入到最后的结点之后*/
				ptemplist->next=list;
				list->next=NULL;
			}
		}

		/* 管理器对应的message 总数增1 */
		box->messageNumber++;
		box->messageSize += list->size;	
		return;
	}
	else if(mmsDigest->msgtype==MESSAGE_WAP||
		mmsDigest->msgtype==MESSAGE_OTA_SET||
		mmsDigest->msgtype==MESSAGE_OTA_BOOKMARK)
	{
		/*Add Wap push */
		list->msgtype=mmsDigest->msgtype;
	}
	else/*Mms message*/
#endif
	/*非短彩合一时仅有一种类型*/
	{
		list->msgtype=MESSAGE_MMS;
	}


	  list->state = mmsDigest->state;
	  list->size = mmsDigest->size;	
	  list->expriy_time= mmsDigest->expriy_time;
	  
	  /* 将待添加mms的文件名拷贝到新节点中 */
	  if(mmsDigest->fileName != NULL)
	  {
		  list->fileName = (S8*)mms_Malloc(strlen(mmsDigest->fileName) + 1);
		  if(list->fileName == NULL)
		  {
			  mms_Tracer((char*)"error:--list->fileName malloc failed");
			  mms_file_manager_free_message(list);
			  list = NULL;
			  return ;
		  }
		  memset(list->fileName, 0, strlen(mmsDigest->fileName) + 1);
		  strcpy(list->fileName, mmsDigest->fileName);
	  }
	  /* 将待添加mms的地址(TO)信息拷贝到新节点中 */
	  if (mmsDigest->to_address != NULL)
	  {
		  if (mmsDigest->to_address[0] != 0)
		  {
			  list->to_address = (S8*)mms_Malloc(strlen(mmsDigest->to_address) + 1);
			  if(list->to_address == NULL)
			  {
				  mms_Tracer((char*)"error:--list->address malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->to_address,0, strlen(mmsDigest->to_address) + 1);
			  strcpy(list->to_address,mmsDigest->to_address);
		  }
	  }
	 /* 将待添加mms的地址(CC)信息拷贝到新节点中 */
	  if (mmsDigest->cc_address != NULL)
	  {
		  if (mmsDigest->cc_address[0] != 0)
		  {
			  list->cc_address = (S8*)mms_Malloc(strlen(mmsDigest->cc_address) + 1);
			  if(list->cc_address == NULL)
			  {
				  mms_Tracer((char*)"error:--list->cc_address malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->cc_address,0, strlen(mmsDigest->cc_address) + 1);
			  strcpy(list->cc_address,mmsDigest->cc_address);
		  }
	  }
	 /* 将待添加mms的地址(BCC)信息拷贝到新节点中 */
	  if (mmsDigest->bcc_address != NULL)
	  {
		  if (mmsDigest->bcc_address[0] != 0)
		  {
			  list->bcc_address = (S8*)mms_Malloc(strlen(mmsDigest->bcc_address) + 1);
			  if(list->bcc_address == NULL)
			  {
				  mms_Tracer((char*)"error:--list->bcc_address malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->bcc_address,0, strlen(mmsDigest->bcc_address) + 1);
			  strcpy(list->bcc_address,mmsDigest->bcc_address);
		  }
	  }
	  /* 将待添加mms的主题信息拷贝到新节点中 */
	  if (mmsDigest->subject != NULL)
	  {
		  if (mmsDigest->subject[0] != 0)
		  {
			  list->subject = (S8*)mms_Malloc(strlen(mmsDigest->subject) + 1);
			  if(list->subject == NULL)
			  {
				  mms_Tracer((char*)"error:--list->subject malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->subject, 0, strlen(mmsDigest->subject) + 1);
			  strcpy(list->subject,mmsDigest->subject);

		  }
	  }
	  /* 将待添加mms的url信息拷贝到新节点中 */
	  if (mmsDigest->url != NULL)
	  {
		  if (mmsDigest->url[0] != 0)
		  {
			  list->url = (S8*)mms_Malloc(strlen(mmsDigest->url) + 1);
			  if(list->url == NULL)
			  {
				  mms_Tracer((char*)"error:--list->url malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->url, 0, strlen(mmsDigest->url) + 1);
			  strcpy(list->url, mmsDigest->url);
		  }
	  }
	  /* 将待添加mms的日期信息拷贝到新节点中 */
	  if (mmsDigest->date != NULL)
	  {
		  if (mmsDigest->date[0] != 0)
		  {
			  list->date = (S8*)mms_Malloc(strlen(mmsDigest->date) + 1);
			  if(list->date == NULL)
			  {
				  mms_Tracer((char*)"error:--list->date malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->date, 0, strlen(mmsDigest->date) + 1);
			  strcpy(list->date, mmsDigest->date);
		  }
	  }

#ifdef SUPPORT_OTA_PUSH
	  /* 将待添加ota push的ota_name信息拷贝到新节点中 */
	  if (mmsDigest->ota_name!= NULL)
	  {
		  if (mmsDigest->ota_name[0] != 0)
		  {
			  list->ota_name = (S8*)mms_Malloc(strlen(mmsDigest->ota_name) + 1);
			  if(list->ota_name == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_name malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_name, 0, strlen(mmsDigest->ota_name) + 1);
			  strcpy(list->ota_name, mmsDigest->ota_name);
		  }
	  }
	  /* 将待添加ota push的ota_gateway信息拷贝到新节点中 */
	  if (mmsDigest->ota_gateway!= NULL)
	  {
		  if (mmsDigest->ota_gateway[0] != 0)
		  {
			  list->ota_gateway = (S8*)mms_Malloc(strlen(mmsDigest->ota_gateway) + 1);
			  if(list->ota_gateway == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_gateway malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_gateway, 0, strlen(mmsDigest->ota_gateway) + 1);
			  strcpy(list->ota_gateway, mmsDigest->ota_gateway);
		  }
	  }
	  /* 将待添加ota push的ota_port信息拷贝到新节点中 */
	  if (mmsDigest->ota_port!= NULL)
	  {
		  if (mmsDigest->ota_port[0] != 0)
		  {
			  list->ota_port = (S8*)mms_Malloc(strlen(mmsDigest->ota_port) + 1);
			  if(list->ota_port == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_port malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_port, 0, strlen(mmsDigest->ota_port) + 1);
			  strcpy(list->ota_port, mmsDigest->ota_port);
		  }
	  }	
	  /* 将待添加ota push的ota_netacc信息拷贝到新节点中 */
	  if (mmsDigest->ota_netacc!= NULL)
	  {
		  if (mmsDigest->ota_netacc[0] != 0)
		  {
			  list->ota_netacc = (S8*)mms_Malloc(strlen(mmsDigest->ota_netacc) + 1);
			  if(list->ota_netacc == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_netacc malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_netacc, 0, strlen(mmsDigest->ota_netacc) + 1);
			  strcpy(list->ota_netacc, mmsDigest->ota_netacc);
		  }
	  }		 
	  /* 将待添加ota push的ota_murl信息拷贝到新节点中 */
	  if (mmsDigest->ota_murl!= NULL)
	  {
		  if (mmsDigest->ota_murl[0] != 0)
		  {
			  list->ota_murl = (S8*)mms_Malloc(strlen(mmsDigest->ota_murl) + 1);
			  if(list->ota_murl == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_murl malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_murl, 0, strlen(mmsDigest->ota_murl) + 1);
			  strcpy(list->ota_murl, mmsDigest->ota_murl);
		  }
	  }		  
	  /* 将待添加ota push的ota_smsc信息拷贝到新节点中 */
	  if (mmsDigest->ota_smsc!= NULL)
	  {
		  if (mmsDigest->ota_smsc[0] != 0)
		  {
			  list->ota_smsc = (S8*)mms_Malloc(strlen(mmsDigest->ota_smsc) + 1);
			  if(list->ota_smsc == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_smsc malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_smsc, 0, strlen(mmsDigest->ota_smsc) + 1);
			  strcpy(list->ota_smsc, mmsDigest->ota_smsc);
		  }
	  }		 
	  /* 将待添加ota push的ota_ispname信息拷贝到新节点中 */
	  if (mmsDigest->ota_ispname!= NULL)
	  {
		  if (mmsDigest->ota_ispname[0] != 0)
		  {
			  list->ota_ispname = (S8*)mms_Malloc(strlen(mmsDigest->ota_ispname) + 1);
			  if(list->ota_ispname == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_ispname malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_ispname, 0, strlen(mmsDigest->ota_ispname) + 1);
			  strcpy(list->ota_ispname, mmsDigest->ota_ispname);
		  }
	  }		 
	  /* 将待添加ota push的ota_csdscode信息拷贝到新节点中 */
	  if (mmsDigest->ota_csdscode!= NULL)
	  {
		  if (mmsDigest->ota_csdscode[0] != 0)
		  {
			  list->ota_csdscode = (S8*)mms_Malloc(strlen(mmsDigest->ota_csdscode) + 1);
			  if(list->ota_csdscode == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_csdscode malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_csdscode, 0, strlen(mmsDigest->ota_csdscode) + 1);
			  strcpy(list->ota_csdscode, mmsDigest->ota_csdscode);
		  }
	  }		  
	  /* 将待添加ota push的ota_url信息拷贝到新节点中 */
	  if (mmsDigest->ota_apn!= NULL)
	  {
		  if (mmsDigest->ota_apn[0] != 0)
		  {
			  list->ota_apn = (S8*)mms_Malloc(strlen(mmsDigest->ota_apn) + 1);
			  if(list->ota_apn == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_apn malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_apn, 0, strlen(mmsDigest->ota_apn) + 1);
			  strcpy(list->ota_apn, mmsDigest->ota_apn);
		  }
	  }
	  /* 将待添加ota push的ota_user信息拷贝到新节点中 */
	  if (mmsDigest->ota_user!= NULL)
	  {
		  if (mmsDigest->ota_user[0] != 0)
		  {
			  list->ota_user = (S8*)mms_Malloc(strlen(mmsDigest->ota_user) + 1);
			  if(list->ota_user == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_user malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_user, 0, strlen(mmsDigest->ota_user) + 1);
			  strcpy(list->ota_user, mmsDigest->ota_user);
		  }
	  }		  
	  /* 将待添加ota push的ota_passw信息拷贝到新节点中 */
	  if (mmsDigest->ota_passw!= NULL)
	  {
		  if (mmsDigest->ota_passw[0] != 0)
		  {
			  list->ota_passw = (S8*)mms_Malloc(strlen(mmsDigest->ota_passw) + 1);
			  if(list->ota_passw == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_passw malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_passw, 0, strlen(mmsDigest->ota_passw) + 1);
			  strcpy(list->ota_passw, mmsDigest->ota_passw);
		  }
	  }

	  /* 将待添加ota push的ota_authtype信息拷贝到新节点中 */
	  if (mmsDigest->ota_authtype!= NULL)
	  {
		  if (mmsDigest->ota_authtype[0] != 0)
		  {
			  list->ota_authtype = (S8*)mms_Malloc(strlen(mmsDigest->ota_authtype) + 1);
			  if(list->ota_authtype == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_authtype malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_authtype, 0, strlen(mmsDigest->ota_authtype) + 1);
			  strcpy(list->ota_authtype, mmsDigest->ota_authtype);
		  }
	  }		  
	  /* 将待添加ota push的ota_logintype信息拷贝到新节点中 */
	  if (mmsDigest->ota_logintype!= NULL)
	  {
		  if (mmsDigest->ota_logintype[0] != 0)
		  {
			  list->ota_logintype = (S8*)mms_Malloc(strlen(mmsDigest->ota_logintype) + 1);
			  if(list->ota_logintype == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_logintype malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_logintype, 0, strlen(mmsDigest->ota_logintype) + 1);
			  strcpy(list->ota_logintype, mmsDigest->ota_logintype);
		  }
	  }	
	  /* 将待添加ota push的ota_bmurl信息拷贝到新节点中 */
	  if (mmsDigest->ota_bmurl!= NULL)
	  {
		  if (mmsDigest->ota_bmurl[0] != 0)
		  {
			  list->ota_bmurl = (S8*)mms_Malloc(strlen(mmsDigest->ota_bmurl) + 1);
			  if(list->ota_bmurl == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_bmurl malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_bmurl, 0, strlen(mmsDigest->ota_bmurl) + 1);
			  strcpy(list->ota_bmurl, mmsDigest->ota_bmurl);
		  }
	  }		  
	  /* 将待添加ota push的ota_bmname信息拷贝到新节点中 */
	  if (mmsDigest->ota_bmname!= NULL)
	  {
		  if (mmsDigest->ota_bmname[0] != 0)
		  {
			  list->ota_bmname = (S8*)mms_Malloc(strlen(mmsDigest->ota_bmname) + 1);
			  if(list->ota_bmname == NULL)
			  {
				  mms_Tracer((char*)"error:--list->ota_bmname malloc failed");
				  mms_file_manager_free_message(list);
				  list = NULL;
				  return ;
			  }
			  memset(list->ota_bmname, 0, strlen(mmsDigest->ota_bmname) + 1);
			  strcpy(list->ota_bmname, mmsDigest->ota_bmname);
		  }
	  }
#endif

	  /* 待添加的节点放在管理器对应的根节点 */
	  #if 1
	  if(box->root==NULL)
	  {
			box->root=list;
			box->root->next=NULL;
			mms_Tracer((char*)"add mms box->root==NULL");
	  }
	  /* 如果pnode等于开头节点则是插入第一个节点 */
	  else
	  {
		  P_MESSAGELIST ptemplist=NULL,pprelist=NULL;
		  mms_Tracer((char*)"add mms box->root!=NULL");
		  ptemplist=box->root;
		  pprelist=ptemplist;
		  mms_mmi_tracer("^_^prelist->date=%s", (char*)list->date);	
		  mms_mmi_tracer("^_^preptemplist->date=%s", (char*)ptemplist->date);	
		  while((strcmp((char*)ptemplist->date,(char*)list->date)>0)&&(ptemplist->next!=NULL))/*插入的时间小于前面的时间&&不是头节点*/
		  {
			  mms_Tracer((char*)"add mms find while");
			  mms_mmi_tracer("^_^list->date=%s", (char*)list->date);	
			  mms_mmi_tracer("^_^ptemplist->date=%s", (char*)ptemplist->date);	
			  pprelist=ptemplist;/*使pprelist指向刚才ptemplist指向的结点*/
			  ptemplist=ptemplist->next;/*ptemplist向后移一个结点*/
		  }
		  if((strcmp((char*)ptemplist->date,(char*)list->date)<=0)&&(ptemplist->next==NULL))
		  {
			  mms_Tracer((char*)"add sms if strcmp date <=0 && ptemplist->next==NUL");
			  if(ptemplist==box->root)/*插入到原来第一个节点之前*/
			  {
			  	box->root=list;			
			  }
			  else/*插入到pprelist节点之后*/
			  {
			  	pprelist->next=list;
			  }
			  list->next=ptemplist;  
		  }
		  else if(strcmp((char*)ptemplist->date,(char*)list->date)<=0)
		  {
			  mms_Tracer((char*)"add mms if strcmp date <=0");
			  if(ptemplist==box->root)/*插入到原来第一个节点之前*/
			  {
			  	box->root=list;			
			  }
			  else/*插入到pprelist节点之后*/
			  {
			  	pprelist->next=list;
			  }
			  list->next=ptemplist;
		  }
		  else if(ptemplist->next==NULL)
		  {
			  mms_Tracer((char*)"ptemplist->next==NUL");
			  /*插入到最后的结点之后*/
			  ptemplist->next=list;
			  list->next=NULL;
		  }
	  }
	  #else
	  list->next = box->root;
	  box->root = list;
	  #endif
	  /* 管理器对应的mms总数增1 */
	  box->messageNumber++;
	  if (!list->url)
	  {
		box->messageSize += list->size;
	  }
	  switch(flag)
	  {
	  case SET_MESSAGE_NULL:
	  	break;
	  case SET_MESSAGE_CUR:
		box->currentMessage = list;
		break;
	  case SET_MESSAGE_PUSH:
	  	pgManager->receiveFolder->pushMessage = list;
		break;
	  }
 	mms_file_manager_store_folder(folder);
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_delete_message_node
 *       Purpose: delete this message node,don't delete the file from flash
 *         Input: P_MESSAGELIST list
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_delete_message_node(P_MESSAGELIST list)
{
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (list == NULL)
	{
		return;
	}
	/* 删除地址信息 */
	if (list->to_address != NULL)
	{
		mms_Free(list->to_address);
		list->to_address = NULL;
	}
        if (list->cc_address != NULL)
	{
		mms_Free(list->cc_address);
		list->cc_address = NULL;
	}

      if (list->bcc_address != NULL)
	{
		mms_Free(list->bcc_address);
		list->bcc_address = NULL;
	}
	/* 删除MMS文件名信息及闪存中对应文件 */
	if (list->fileName != NULL)
	{
		if (mmsf_ifFileExited(list->fileName))
		{
			mmsf_Remove(list->fileName);
		}
		mms_Free(list->fileName);
		list->fileName = NULL;
	}	
	/* 删除主题 */
	if (list->subject != NULL)
	{
		mms_Free(list->subject);
		list->subject = NULL;
	}
	/* 删除时间 */
	if (list->date != NULL)
	{
		mms_Free(list->date);
		list->date = NULL;
	}
	if (list->url)
	{
		mms_Free(list->url);
		list->url = NULL;
	}
#ifdef SUPPORT_OTA_PUSH
	if (list->ota_name)
	{
		mms_Free(list->ota_name);
		list->ota_name = NULL;
	}
	if (list->ota_gateway)
	{
		mms_Free(list->ota_gateway);
		list->ota_gateway = NULL;
	}
	if (list->ota_port)
	{
		mms_Free(list->ota_port);
		list->ota_port = NULL;
	}
	if (list->ota_netacc)
	{
		mms_Free(list->ota_netacc);
		list->ota_netacc = NULL;
	}
	if (list->ota_murl)
	{
		mms_Free(list->ota_murl);
		list->ota_murl = NULL;
	}
	
	if (list->ota_smsc)
	{
		mms_Free(list->ota_smsc);
		list->ota_smsc= NULL;
	}	
	if (list->ota_ispname)
	{
		mms_Free(list->ota_ispname);
		list->ota_ispname= NULL;
	}
	if (list->ota_csdscode)
	{
		mms_Free(list->ota_csdscode);
		list->ota_csdscode= NULL;
	}	
	if (list->ota_apn)
	{
		mms_Free(list->ota_apn);
		list->ota_apn= NULL;
	}
	if (list->ota_user)
	{
		mms_Free(list->ota_user);
		list->ota_user= NULL;
	}	
	if (list->ota_passw)
	{
		mms_Free(list->ota_passw);
		list->ota_passw= NULL;
	}
	if (list->ota_authtype)
	{
		mms_Free(list->ota_authtype);
		list->ota_authtype= NULL;
	}	
	if (list->ota_logintype)
	{
		mms_Free(list->ota_logintype);
		list->ota_logintype= NULL;
	}
	if (list->ota_bmurl)
	{
		mms_Free(list->ota_bmurl);
		list->ota_bmurl= NULL;
	}
	
	if (list->ota_bmname)
	{
		mms_Free(list->ota_bmname);
		list->ota_bmname= NULL;
	}	
#endif
	list->next = NULL;
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_delete_message
 *       Purpose: delete this message ,delete the file from flash
 *         Input: P_MESSAGELIST list
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_delete_message(P_MESSAGELIST list)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	char fname[MMS_MAX_FILE_NAME_LENGTH] = {0};
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if (list == NULL)
	{
		return;
	}
	/* 删除地址信息 */
	if (list->to_address != NULL)
	{
		mms_Free(list->to_address);
		list->to_address = NULL;
	}
        if (list->cc_address != NULL)
	{
		mms_Free(list->cc_address);
		list->cc_address = NULL;
	}

      if (list->bcc_address != NULL)
	{
		mms_Free(list->bcc_address);
		list->bcc_address = NULL;
	}
	/* 删除MMS文件名信息及闪存中对应文件 */
	if (list->fileName != NULL)
	{
		if (!list->url)
		{
			if (mmsf_ifFileExited(list->fileName))
			{
				mmsf_Remove(list->fileName);
			}
			strcpy(fname, (const char*)CMS_MMS_APP_PATH);
			strcat(fname, (const char*)list->fileName);
			if (Cms_Adp_FileExists(fname))
			{
				Cms_Adp_fdelete((const unsigned short *)(fname));
			}
		}
		mms_Free(list->fileName);
		list->fileName = NULL;
	}
	/* 删除主题 */
	if (list->subject != NULL)
	{
		mms_Free(list->subject);
		list->subject = NULL;
	}
	/* 删除时间 */
	if (list->date != NULL)
	{
		mms_Free(list->date);
		list->date = NULL;
	}
	if (list->url != NULL)
	{
		mms_Free(list->url);
		list->url = NULL;
	}

#ifdef SUPPORT_OTA_PUSH
	if (list->ota_name)
	{
		mms_Free(list->ota_name);
		list->ota_name = NULL;
	}
	if (list->ota_gateway)
	{
		mms_Free(list->ota_gateway);
		list->ota_gateway = NULL;
	}
	if (list->ota_port)
	{
		mms_Free(list->ota_port);
		list->ota_port = NULL;
	}
	if (list->ota_netacc)
	{
		mms_Free(list->ota_netacc);
		list->ota_netacc = NULL;
	}
	if (list->ota_murl)
	{
		mms_Free(list->ota_murl);
		list->ota_murl = NULL;
	}
	
	if (list->ota_smsc)
	{
		mms_Free(list->ota_smsc);
		list->ota_smsc= NULL;
	}	
	if (list->ota_ispname)
	{
		mms_Free(list->ota_ispname);
		list->ota_ispname= NULL;
	}
	if (list->ota_csdscode)
	{
		mms_Free(list->ota_csdscode);
		list->ota_csdscode= NULL;
	}	
	if (list->ota_apn)
	{
		mms_Free(list->ota_apn);
		list->ota_apn= NULL;
	}
	if (list->ota_user)
	{
		mms_Free(list->ota_user);
		list->ota_user= NULL;
	}	
	if (list->ota_passw)
	{
		mms_Free(list->ota_passw);
		list->ota_passw= NULL;
	}
	if (list->ota_authtype)
	{
		mms_Free(list->ota_authtype);
		list->ota_authtype= NULL;
	}	
	if (list->ota_logintype)
	{
		mms_Free(list->ota_logintype);
		list->ota_logintype= NULL;
	}
	if (list->ota_bmurl)
	{
		mms_Free(list->ota_bmurl);
		list->ota_bmurl= NULL;
	}
	
	if (list->ota_bmname)
	{
		mms_Free(list->ota_bmname);
		list->ota_bmname= NULL;
	}	
#endif
	if(list->size)
	{
		list->size = 0;
	}
	if(list->expriy_time)
	{
		list->expriy_time= 0;
	}
	if(list->msgtype)
	{
		list->msgtype= 0;
	}
	list->next = NULL;
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_delete_message_from_box
 *       Purpose: delete this message ,delete the file from flash
 *         Input: P_MESSAGELIST pMsg, MMS_FOLDER_NAME box
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_delete_message_from_box(P_MESSAGELIST pMsg, MMS_FOLDER_NAME box)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGEFOLDER	folder = NULL;
	P_MESSAGELIST		tlist = NULL;
	U8					delok = 0;
	S32					del_size = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	  /* 入口条件判断 */
	  if(!pgManager)
	  {
		  return ;
	  }
	  if (!pMsg) 
	  {
		  return;
	  }
	  switch(box)
	  {
	  case MMS_RECEIVE_FOLDER:
		  folder = pgManager->receiveFolder;
	  	  break;
	  case MMS_SEND_FOLDER:
		  folder = pgManager->sendFolder;
	  	  break;
	  case MMS_DRAFT_FOLDER:
		  folder = pgManager->draftFolder;
	  	  break;
	  }
	  mms_Tracer((char*)"DelMsg1111");
	  if (!pMsg->url) 
	  {
		  del_size = pMsg->size;
	  }
	  /* 如果删除的节点为根节点 */
	  if(folder->root == pMsg)
	  {
		  mms_Tracer((char*)"!!!the node to be deleted is root node!!!!");
		  /* 记录待删除节点的彩信状态 */
		  delok = pMsg->state;
		  /* 将下一个节点设为根节点 */
		  folder->root = folder->root->next;
		  mms_file_manager_delete_message(pMsg);
		  mms_file_manager_free_message(pMsg);
	  }
	  else  /* 如果删除的节点为中间的节点 */
	  {
		  for(tlist=folder->root; tlist; tlist=tlist->next)
		  {
			  if(tlist->next == pMsg)
			  {
				  mms_Tracer((char*)"DelMsg2222");
				  /* 记录待删除节点的彩信状态 */
				  delok = pMsg->state;
				  
				  /* 将当前节点从链表中解除 */				
				  tlist->next = pMsg->next;

				  mms_file_manager_delete_message(pMsg);
				  mms_file_manager_free_message(pMsg);
				  break;
			  }
		  }
	  }
	  /* MMS总个数减一个 */
	  folder->messageNumber--;
	  if (folder->messageNumber == 0) 
	  {
		  folder->currentMessage = NULL;
		  folder->pushMessage = NULL;
	  }
	  folder->messageSize -= del_size;
	  /* 保存当前的信息箱 */
	  mms_file_manager_store_folder(box);  
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_delete_current_message
 *       Purpose: delete this current_message ,delete the file from flash
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_delete_current_message(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	  P_MESSAGEFOLDER	folder = NULL;
	  P_MESSAGELIST		tlist = NULL;
	  U8					delok = 0;
	  S32				del_size = 0;	
	  S8					pathname[MMS_FILE_NAME_LEN];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	  /* 入口条件判断 */
	  if(!pgManager)
	  {
		  return ;
	  }
	  if(!pgManager->currentFolder)
	  {
		  return ;		
	  }
	  if(!pgManager->currentFolder->currentMessage)
	  {
		  return ;
	  }
	  memset(pathname,0,sizeof(pathname));
	  
	  folder = pgManager->currentFolder;
	  
	  if (!folder->currentMessage->url)
	  {
		  del_size = folder->currentMessage->size;
	  }
	  /* 如果删除的节点为根节点 */
	  if(folder->root == folder->currentMessage)
	  {
		  mms_Tracer((char*)"!!!!!!!!!!the node to be deleted is root node!!!!!!!");
		  /* 记录待删除节点的彩信状态 */
		  delok = folder->currentMessage->state;
		  /* 将下一个节点设为根节点 */
		  folder->root = folder->root->next;

		  mms_file_manager_delete_message(folder->currentMessage);		  
		  mms_file_manager_free_message(folder->currentMessage);
		  /* 将新的根节点设为当前节点 */
		  folder->currentMessage = folder->root;
	  }
	  else  /* 如果删除的节点为中间的节点 */
	  {
		  for(tlist=folder->root; tlist; tlist=tlist->next)
		  {
			  if(tlist->next == folder->currentMessage)
			  {
				  /* 记录待删除节点的彩信状态 */
				  delok = folder->currentMessage->state;
				  
				  /* 将当前节点从链表中解除 */				
				  tlist->next = folder->currentMessage->next;

				  mms_file_manager_delete_message(folder->currentMessage);
				  mms_file_manager_free_message(folder->currentMessage);
				  /* 当前节点的下一个节点不为空，设为当前节点 */
				  if(tlist->next)
				  {
					  folder->currentMessage = tlist->next;
				  }
				  else /* 当前节点下一个节点为空，则将上一个节点设为当前节点 */
				  {
					  mms_Tracer((char*)"delete the last node");
					  folder->currentMessage = tlist;
				  }
				  break;
			  }
		  }
	  }
	  /* MMS总个数减一个 */
	  folder->messageNumber--;
	  if (folder->messageNumber == 0) 
	  {
		  folder->currentMessage = NULL;
		  folder->pushMessage = NULL;
	  }
	  folder->messageSize -= del_size;
	  /* 保存当前的信息箱 */
	  mms_file_manager_store_current_folder();
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_set_current_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_set_current_message(P_MESSAGELIST curMsg)
{
	if(pgManager)
	  {
		  if(pgManager->currentFolder )
		  {
			  pgManager->currentFolder->currentMessage = curMsg;
		  }
	  }
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_get_current_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
P_MESSAGELIST mms_file_manager_get_current_message(void)
{
	  if(pgManager)
	  {
		  if(pgManager->currentFolder )
		  {
			  return pgManager->currentFolder->currentMessage;
		  }
	  }
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_set_push_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_set_push_message(P_MESSAGELIST pushMsg)
{
	if(pgManager)
	  {
		  if(pgManager->receiveFolder)
		  {
			  pgManager->receiveFolder->pushMessage= pushMsg;
		  }
	  }
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_get_push_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
P_MESSAGELIST mms_file_manager_get_push_message(void)
{
	  if(pgManager)
	  {
		  if(pgManager->receiveFolder )
		  {
			  return pgManager->receiveFolder->pushMessage;
		  }
	  }
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_modify_current_message_state
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_modify_current_message_state(MMS_MSG_STATE state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	 P_MESSAGELIST	pMsg = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	  if(pgManager == NULL)
	  {
		  return ;
	  }
	  if(pgManager->currentFolder == NULL)
	  {
		  return ;
	  }
	  if((pgManager->currentFolder != pgManager->receiveFolder)\
		  && (pgManager->currentFolder != pgManager->sendFolder)\
		  && (pgManager->currentFolder != pgManager->draftFolder))
	  {
		  return ;
	  }	
	  pMsg = pgManager->currentFolder->currentMessage;
	  if(pMsg == NULL)
	  {
		  return ;
	  }
	  if(pMsg->state == 'R')
	  {
		  return;
	  }
	  switch(state)
	  {
		  
	  case MMS_MSG_STATE_UNSEND:
		  pMsg->state = 'U';
		  break;
	  case MMS_MSG_STATE_SENDFAILED:
		  pMsg->state = 'N';
		  break;
	  case MMS_MSG_STATE_SENDED:
		  pMsg->state = 'Y';
		  break;
		  /* 将消息状态改成未读 */
	  case MMS_MSG_STATE_UNREAD:
		  pMsg->state = 'N';
		  break;
		  /* 将消息状态改成已读 */
	  case MMS_MSG_STATE_READ:
		  pMsg->state = 'Y';
		  break;
		  /* 不能将消息状态改成未接收 */
	  case MMS_MSG_STATE_UNRECEIVED:
		  break;
	  default:
		  break;
	  }
	  /* 当前信箱摘要信息保存到对应的文件中 */
	  mms_file_manager_store_current_folder();
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


/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_store_folder
 *       Purpose: 
 *         Input: MMS_FOLDER_NAME folder
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_store_folder(MMS_FOLDER_NAME folder)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	  MMS_FILE_HANDLE	fp = 0;
	  P_MESSAGELIST		tlist = NULL;
	  P_MESSAGEFOLDER	box = NULL;
	  S8					digestfile[MMS_FILE_NAME_LEN] = {0};
	  S8*				buffer_file = NULL;
	  S8*				buffer_pos = NULL;  /* 相对buffer_file的位置 */
	  S32				buffer_len = 0;
	  UINT				rd = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	  
	  mms_Tracer((char*)"start of MmsManagerStoreFolder");

	  if(!pgManager)
	  {
		  mms_Tracer((char*)"error:MmsManagerStoreFolder--pgManage is NULL");
		  return ;
	  }	  

	  memset(digestfile, 0, MMS_FILE_NAME_LEN);

	  /* 待保存的是收件箱还是发件箱 */
	  strcpy(digestfile, CMS_MMS_APP_PATH);
	  if(folder == MMS_RECEIVE_FOLDER)
	  {
		  mms_Tracer((char*)"MmsManagerStoreFolder--it is a receiveFolder");
		  box = pgManager->receiveFolder;
		  strcat(digestfile, "rmf.txt");
	  }
	  else if(folder == MMS_SEND_FOLDER)
	  {
		  mms_Tracer((char*)"MmsManagerStoreFolder--it is a sendFolder");
		  box = pgManager->sendFolder;
		  strcat(digestfile, "smf.txt");
	  }
	  else if(folder == MMS_DRAFT_FOLDER)
	  {
		  mms_Tracer((char*)"MmsManagerStoreFolder--it is a draftFolder");
		  box = pgManager->draftFolder;
		  strcat(digestfile, "dmf.txt");
	  }
	  else
	  {
		  mms_Tracer((char*)"MmsManagerStoreFolder--it is a unknownFolder");
		  return;
	  }
	  if (box->messageNumber == 0)
	  {
		  mms_Tracer((char*)"44444444444444444444444");
		  /* 删除摘要文件 */
		  if (Cms_Adp_FileExists(digestfile))
		  {
			  Cms_Adp_fdelete((const unsigned short*)digestfile);
		  }		
		  return;
	  }
#ifdef SUPPORT_SMSMMS_COMBINE
	{
		  U16	mmsNumber=0;

		  for(tlist = box->root; tlist; tlist = tlist->next)
		  {
#ifdef SUPPORT_OTA_PUSH
		  	if((tlist->fileName)||(tlist->url)||(tlist->ota_murl))
#else
		  	if((tlist->fileName)||(tlist->url))
#endif
		  	{
		  		mmsNumber++;
		  	}
		  }
			
		  /* 如果当前信箱中的mms个数不为零，根据MMS个数分配内存 */
		  if(mmsNumber > 0 && mmsNumber <= MAX_MESSAGE_COUNT+CMS_MAX_PUSH);
		  {	
		  	  /* 多分配100个字节 */
			  buffer_file = (S8*)mms_Malloc(900*(mmsNumber)+100);//700->900 
			  if(buffer_file)
			  {
				  mms_Tracer((char*)"666666666666666666666");
				  memset(buffer_file, 0, (900*(mmsNumber)+100));//700->900 
				  buffer_pos = buffer_file;
			  }
			  else
			  {
				  mms_Tracer((char*)"error:MmsManagerStoreFolder--buffer_file is NULL");
				  return ;
			  }
		  }
	}
#else
	  /* 如果当前信箱中的mms个数不为零，根据MMS个数分配内存 */
	  if(box->messageNumber > 0 && box->messageNumber <= MAX_MESSAGE_COUNT);
	  {	
	  	  /* 多分配100个字节 */
		  buffer_file = (S8*)mms_Malloc(900*(box->messageNumber)+100);//700->900 
		  if(buffer_file)
		  {
			  mms_Tracer((char*)"666666666666666666666");
			  memset(buffer_file, 0, (900*(box->messageNumber)+100));//700->900 
			  buffer_pos = buffer_file;
		  }
		  else
		  {
			  mms_Tracer((char*)"error:MmsManagerStoreFolder--buffer_file is NULL");
			  return ;
		  }
	  }
#endif
	  /* 根据MMS摘要信息编码到内存(中间没有结束符) */
	  for(tlist = box->root; tlist; tlist = tlist->next)
	  {
		  S8 len = 0;	
#ifdef SUPPORT_OTA_PUSH
		  if((!tlist->fileName)&&(!tlist->url)&&(!tlist->ota_murl))
#else		  
		  if((!tlist->fileName)&&(!tlist->url))
#endif
		{
		 	 mms_Tracer((char*)"^_^not store sms node ");
			 continue;
		  }
		  mms_mmi_tracer("^_^store ind^_^: filename = %s", (char*)tlist->fileName);
		  mms_mmi_tracer("^_^store ind^_^: url = %s", (char*)tlist->url);
		  
		  /* 记录mms的文件名信息  filename 必须放在第一个 */
		  if (tlist->fileName != NULL)
		  {
		  	if (tlist->fileName[0] != 0)
		  	{
				mms_Tracer((char*)"8888888888888888888888");
				*buffer_pos = (S8)MSG_HDR_TYPE_FILENAME;
				buffer_pos += 1;
				len = strlen(tlist->fileName)+1;
				*buffer_pos = (S8)len;
				buffer_pos += 1;
				memcpy(buffer_pos, tlist->fileName, len);
				buffer_pos += len;
				buffer_len += 2+len;
		  	}
		  }
		  /* 记录mms的收件人(TO)信息 */
		  if (tlist->to_address != NULL)
		  {
			  if (tlist->to_address[0] != 0)
			  {
				  U16 tLen = 0;
				  *buffer_pos = (S8)MSG_HDR_TYPE_ADDRESS;
				  buffer_pos += 1;
				  tLen = strlen(tlist->to_address) + 1;
				  len = (tLen&0xff00)>>8;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  len = tLen&0xff;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->to_address,tLen);
				  buffer_pos += tLen;
				  buffer_len += 3+tLen;
			  }
		  }
		  /* 记录mms的收件人(CC)信息 */
		  if (tlist->cc_address != NULL)
		  {
			  if (tlist->cc_address[0] != 0)
			  {
				  U16 tLen = 0;
				  *buffer_pos = (S8)MSG_HDR_TYPE_CC_ADDRESS;
				  buffer_pos += 1;
				  tLen = strlen(tlist->cc_address) + 1;
				  len = (tLen&0xff00)>>8;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  len = tLen&0xff;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->cc_address,tLen);
				  buffer_pos += tLen;
				  buffer_len += 3+tLen;
			  }
		  }
		  /* 记录mms的收件人(BCC)信息 */
		  if (tlist->bcc_address != NULL)
		  {
			  if (tlist->bcc_address[0] != 0)
			  {
				  U16 tLen = 0;
				  *buffer_pos = (S8)MSG_HDR_TYPE_BCC_ADDRESS;
				  buffer_pos += 1;
				  tLen = strlen(tlist->bcc_address) + 1;
				  len = (tLen&0xff00)>>8;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  len = tLen&0xff;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->bcc_address,tLen);
				  buffer_pos += tLen;
				  buffer_len += 3+tLen;
			  }
		  }
		  /* 记录mms的主题信息 */
		  if (tlist->subject)
		  {
			  if (tlist->subject[0] != 0)
			  {
				  mms_Tracer((char*)"000000000000000000");			  
				  *buffer_pos = (S8)MSG_HDR_TYPE_SUBJECT;
				  buffer_pos += 1;
				  len = strlen(tlist->subject) + 1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->subject,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		
		  /* 记录mms的时间信息 */
		  if (tlist->date != NULL)
		  {			
			  mms_Tracer((char*)"aaaaaaaaaaaaaaaaaaaa");
			  if (tlist->date[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_DATE;
				  buffer_pos += 1;
				  len = strlen(tlist->date)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->date,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }
		  /* 记录PUSH消息的URL */
		  if (tlist->url)
		  {
			  mms_Tracer((char*)"aaaaaaaaaa2222222222222222");
			  if (tlist->url[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_URL;
				  buffer_pos += 1;
				  len = strlen(tlist->url)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->url,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }
#ifdef SUPPORT_OTA_PUSH
		  /* 记录OTA PUSH消息的ota_name */
		  if (tlist->ota_name)
		  {
			  mms_Tracer((char*)"ota_name");
			  if (tlist->ota_name[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_NAME;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_name)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_name,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }
		  /* 记录OTA PUSH消息的ota_gateway */
		  if (tlist->ota_gateway)
		  {
			  mms_Tracer((char*)"ota_gateway");
			  if (tlist->ota_gateway[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_GATEWAY;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_gateway)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_gateway,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }
		  /* 记录OTA PUSH消息的ota_port */
		  if (tlist->ota_port)
		  {
			  mms_Tracer((char*)"ota_port");
			  if (tlist->ota_port[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_PORT;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_port)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_port,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		 
		  /* 记录OTA PUSH消息的ota_netacc */
		  if (tlist->ota_netacc)
		  {
			  mms_Tracer((char*)"ota_netacc");
			  if (tlist->ota_netacc[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_NETACC;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_netacc)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_netacc,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_murl */
		  if (tlist->ota_murl)
		  {
			  mms_Tracer((char*)"ota_murl");
			  if (tlist->ota_murl[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_MURL;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_murl)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_murl,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_smsc */
		  if (tlist->ota_smsc)
		  {
			  mms_Tracer((char*)"ota_smsc");
			  if (tlist->ota_smsc[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_SMSC;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_smsc)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_smsc,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_ispname */
		  if (tlist->ota_ispname)
		  {
			  mms_Tracer((char*)"ota_ispname");
			  if (tlist->ota_ispname[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_ISPNAME;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_ispname)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_ispname,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_csdscode */
		  if (tlist->ota_csdscode)
		  {
			  mms_Tracer((char*)"ota_csdscode");
			  if (tlist->ota_csdscode[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_CSDSCODE;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_csdscode)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_csdscode,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_apn */
		  if (tlist->ota_apn)
		  {
			  mms_Tracer((char*)"ota_apn");
			  if (tlist->ota_apn[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_APN;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_apn)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_apn,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_user */
		  if (tlist->ota_user)
		  {
			  mms_Tracer((char*)"ota_user");
			  if (tlist->ota_user[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_USER;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_user)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_user,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_passw */
		  if (tlist->ota_passw)
		  {
			  mms_Tracer((char*)"ota_passw");
			  if (tlist->ota_passw[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_PASSW;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_passw)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_passw,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		 
		  /* 记录OTA PUSH消息的ota_authtype */
		  if (tlist->ota_authtype)
		  {
			  mms_Tracer((char*)"ota_authtype");
			  if (tlist->ota_authtype[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_AUTHTYPE;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_authtype)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_authtype,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_logintype */
		  if (tlist->ota_logintype)
		  {
			  mms_Tracer((char*)"ota_logintype");
			  if (tlist->ota_logintype[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_LOGINTYPE;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_logintype)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_logintype,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }			 
		  /* 记录OTA PUSH消息的ota_bmurl */
		  if (tlist->ota_bmurl)
		  {
			  mms_Tracer((char*)"ota_bmurl");
			  if (tlist->ota_bmurl[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_BMURL;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_bmurl)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_bmurl,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_bmname */
		  if (tlist->ota_bmname)
		  {
			  mms_Tracer((char*)"ota_bmname");
			  if (tlist->ota_bmname[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_BMNAME;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_bmname)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_bmname,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }
#endif
		  if (tlist->size >= 0)
		  {
			  U32 SLen = 0;
			  U16 tLen = 0;

			  mms_Tracer((char*)"aaaaaaaaaa3333333333333333333");
			  *buffer_pos = (S8)MSG_HDR_TYPE_SIZE;
			  buffer_pos += 1;		  
			  SLen = tlist->size;
			  tLen=(SLen&0xffff0000)>>16;
			  len = (tLen & 0xff00)>>8;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  len = tLen & 0xff;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;

			  tLen=SLen&0xffff;
			  len = (tLen & 0xff00)>>8;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  len = tLen & 0xff;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  
			  buffer_len += 5;
		  }
		  /* 记录信息有效期 */
		  if (tlist->size >= 0)
		  {
			  U16 tLen = 0;
			  mms_Tracer((char*)"aaaaaaaaaa4444444444444");
			  *buffer_pos = (S8)MSG_HDR_TYPE_EXPRIY;
			  buffer_pos += 1;
			  tLen = tlist->expriy_time;
			  len = (tLen & 0xff00)>>8;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  len = tLen & 0xff;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  buffer_len += 3;
		  }
		  /* 记录节点信息类型*/		
		  if (tlist->msgtype>0)
		  {
			  mms_Tracer((char*)"bbbbbbbbbbbbfgsdbbbbbbbb");
			  *buffer_pos = (S8)MSG_HDR_TYPE_MSGTYPE;
			  buffer_pos += 1;
			  len = 1;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  *buffer_pos = (S8)tlist->msgtype;
			  buffer_pos += 1;
			  buffer_len += len + 2;
		  }		  
		  /* 记录mms的状态信息，状态信息为最后一个 */		
		  if (tlist->state == 'N' ||tlist->state == 'Y'||tlist->state == 'U'||tlist->state == 'R')
		  {
			  mms_Tracer((char*)"bbbbbbbbbbbbbbbbbbb");
			  *buffer_pos = (S8)MSG_HDR_TYPE_STATE;
			  buffer_pos += 1;
			  len = 1;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  *buffer_pos = (S8)tlist->state;
			  buffer_pos += 1;
			  buffer_len += len + 2;
		  }
		  else
		  {
			  mms_Tracer((char*)"error:MmsManagerStoreFolder--tlist->state is invalid");
			  mms_Free(buffer_file);
			  buffer_file = NULL;
			  buffer_pos = NULL;
			  return ;
		  }
	  }
	  /* 将内存中的摘要信息记录到摘要文件中 */
	  fp = Cms_Adp_fopen(digestfile, FS_CREATE_ALWAYS);
	  if(fp < 0)
	  {
		  mms_Tracer((char*)"open digestfile error!");
		  mms_Free(buffer_file);
		  buffer_file = NULL;
		  buffer_pos = NULL;
		  Cms_Adp_fclose(fp);
		  return ;
	  }
	  
	  if(0 != Cms_Adp_fwrite(fp, buffer_file, buffer_len, &rd))
	  {
		  mms_Tracer((char*)"storefolder write error!");
	  }
	  Cms_Adp_fclose(fp);
	  /* 释放内存资源 */
	  if (buffer_file)
	  {
		  mms_Free(buffer_file);
		  buffer_file = NULL;
		  buffer_pos = NULL;
	  }
	  mms_Tracer((char*)"end of MmsManagerStoreFolder");	  
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_store_current_folder
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_store_current_folder(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	  MMS_FILE_HANDLE	fp = 0;
	  P_MESSAGELIST		tlist = NULL;
	  P_MESSAGEFOLDER	folder = NULL;
	  S8					digestfile[MMS_FILE_NAME_LEN];
	  S8					pathname[MMS_FILE_NAME_LEN];
	  S8*				buffer_file = NULL;
	  S8*				buffer_pos = NULL;  /* 相对buffer_file的位置 */
	  S32				buffer_len = 0;
	  UINT				rd = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	  
	  mms_Tracer((char*)"start of mms_file_manager_store_current_folder");
	  if(!pgManager)
	  {
		  mms_Tracer((char*)"error:mms_file_manager_store_current_folder--pgManage is NULL");
		  return ;
	  }
	  folder = pgManager->currentFolder;
	  
	  mms_Tracer((char*)"1111111111111111111");
	  if(!folder)
	  {
		  mms_Tracer((char*)"error:mms_file_manager_store_current_folder--folder is NULL");
		  return ;
	  }	
	  memset(digestfile,0,sizeof(digestfile));
	  mms_Tracer((char*)"22222222222222222222");
	  
	  /* 待保存的是收件箱还是发件箱 */
	  strcpy(digestfile, CMS_MMS_APP_PATH);
	  if(folder == pgManager->receiveFolder)
	  {
		  mms_Tracer((char*)"mms_file_manager_store_current_folder--it is a receiveFolder");
		  strcat(digestfile, "rmf.txt");
	  }
	  else if(folder == pgManager->sendFolder)
	  {
		  mms_Tracer((char*)"mms_file_manager_store_current_folder--it is a sendFolder");
		  strcat(digestfile, "smf.txt");
	  }
	  else if(folder == pgManager->draftFolder)
	  {
		  mms_Tracer((char*)"mms_file_manager_store_current_folder--it is a draftFolder");
		  strcat(digestfile, "dmf.txt");
	  }
	  else
	  {
		  mms_Tracer((char*)"mms_file_manager_store_current_folder--it is a unknownFolder");
		  return;
	  }	
	  mms_mmi_tracer("digestfile = %s",digestfile);
	  memset(pathname,0,sizeof(pathname));

	  /* 管理器中的MMS的个数为0，则将对应的摘要文件删除,返回 */
	  mms_Tracer((char*)"3333333333333333333333");

	  if (folder->messageNumber == 0)
	  {
		  mms_Tracer((char*)"44444444444444444444444");
		  /* 删除当前指向的mms文件 */
		  if (folder->currentMessage != NULL)
		  {
			  mms_Tracer((char*)"uuuuuuuuuuuuuuuuuuuuu");
			  mms_file_manager_delete_current_message();
		  }
		  /* 删除摘要文件 */
		  if (Cms_Adp_FileExists(digestfile))
		  {
			  Cms_Adp_fdelete((const unsigned short*)digestfile);
		  }		
		  return;
	  }

#ifdef SUPPORT_SMSMMS_COMBINE
	{
		  U16	mmsNumber=0;

		  for(tlist = folder->root; tlist; tlist = tlist->next)
		  {
#ifdef SUPPORT_OTA_PUSH
		  	if((tlist->fileName)||(tlist->url)||(tlist->ota_murl))
#else
		  	if((tlist->fileName)||(tlist->url))
#endif
			{
		  		mmsNumber++;
		  	}
		  }
			
		  /* 如果当前信箱中的mms个数不为零，根据MMS个数分配内存 */
		  if(mmsNumber > 0 && mmsNumber <= MAX_MESSAGE_COUNT+CMS_MAX_PUSH);
		  {	
		  	  /* 多分配100个字节 */
			  buffer_file = (S8*)mms_Malloc(900*(mmsNumber)+100);//700->900 
			  if(buffer_file)
			  {
				  mms_Tracer((char*)"666666666666666666666");
				  memset(buffer_file, 0, (900*(mmsNumber)+100));//700->900 
				  buffer_pos = buffer_file;
			  }
			  else
			  {
				  mms_Tracer((char*)"error:MmsManagerStoreFolder--buffer_file is NULL");
				  return ;
			  }
		  }
	}
#else
	  /* 如果当前信箱中的mms个数不为零，根据MMS个数分配内存 */
	  if(folder->messageNumber > 0 && folder->messageNumber <= MAX_MESSAGE_COUNT);
	  {	
	  	/* 多分配100个字节 */
		  mms_Tracer((char*)"55555555555555555555555");
		  buffer_file = (S8*)mms_Malloc(900*(folder->messageNumber)+100);	//100->700 
		  if(buffer_file)
		  {
			  memset(buffer_file, 0, (900*(folder->messageNumber)+100));
			  buffer_pos = buffer_file;
		  }
		  else
		  {
			  mms_Tracer((char*)"error:mms_file_manager_store_current_folder--buffer_file is NULL");
			  return ;
		  }
	  }
#endif
	  /* 根据MMS摘要信息编码到内存(中间没有结束符) */
	  for(tlist = folder->root; tlist; tlist = tlist->next)
	  {
		  S8 len = 0;
		  
		  mms_Tracer((char*)"^_^store current mms node ");
#ifdef SUPPORT_OTA_PUSH
		  if((!tlist->fileName)&&(!tlist->url)&&(!tlist->ota_murl))
#else		  
		  if((!tlist->fileName)&&(!tlist->url))
#endif
		{
			continue;
		  }
		  
		  /* 记录mms的文件名信息  filename 必须放在第一个 */
		  if (tlist->fileName != NULL)
		  {
		  if (tlist->fileName[0] != 0)
		  {
			  *buffer_pos = (S8)MSG_HDR_TYPE_FILENAME;
			  buffer_pos += 1;
			  len = strlen(tlist->fileName)+1;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  memcpy(buffer_pos,tlist->fileName,len);
			  buffer_pos += len;
			  buffer_len += 2+len;
			  }
		  }
		  /* 记录mms的收件人(TO)信息 */
		  if (tlist->to_address != NULL)
		  {
			  if (tlist->to_address[0] != 0)
			  {
				  U16 tLen = 0;
				  *buffer_pos = (S8)MSG_HDR_TYPE_ADDRESS;
				  buffer_pos += 1;
				  tLen = strlen(tlist->to_address) + 1;
				  len = (tLen&0xff00)>>8;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  len = tLen&0xff;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->to_address,tLen);
				  buffer_pos += tLen;
				  buffer_len += 3+tLen;
			  }
		  }
		  /* 记录mms的收件人(CC)信息 */
		  if (tlist->cc_address != NULL)
		  {
			  if (tlist->cc_address[0] != 0)
			  {
				  U16 tLen = 0;
				  *buffer_pos = (S8)MSG_HDR_TYPE_CC_ADDRESS;
				  buffer_pos += 1;
				  tLen = strlen(tlist->cc_address) + 1;
				  len = (tLen&0xff00)>>8;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  len = tLen&0xff;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->cc_address,tLen);
				  buffer_pos += tLen;
				  buffer_len += 3+tLen;
			  }
		  }
		  /* 记录mms的收件人(BCC)信息 */
		  if (tlist->bcc_address != NULL)
		  {
			  if (tlist->bcc_address[0] != 0)
			  {
				  U16 tLen = 0;
				  *buffer_pos = (S8)MSG_HDR_TYPE_BCC_ADDRESS;
				  buffer_pos += 1;
				  tLen = strlen(tlist->bcc_address) + 1;
				  len = (tLen&0xff00)>>8;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  len = tLen&0xff;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->bcc_address,tLen);
				  buffer_pos += tLen;
				  buffer_len += 3+tLen;
			  }
		  }
		  /* 记录mms的主题信息 */
		  if (tlist->subject != NULL)
		  {
			  if (tlist->subject[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_SUBJECT;
				  buffer_pos += 1;
				  len = strlen(tlist->subject) + 1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->subject,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		
		  /* 记录mms的时间信息 */
		  if (tlist->date[0] != 0)
		  {
			  *buffer_pos = (S8)MSG_HDR_TYPE_DATE;
			  buffer_pos += 1;
			  len = strlen(tlist->date)+1;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  memcpy(buffer_pos,tlist->date,len);
			  buffer_pos += len;
			  buffer_len += 2+len;
		  }
		  /* 记录PUSH消息的URL */
		  if (tlist->url)
		  {
			  *buffer_pos = (S8)MSG_HDR_TYPE_URL;
			  buffer_pos += 1;
			  len = strlen(tlist->url)+1;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  memcpy(buffer_pos,tlist->url,len);
			  buffer_pos += len;
			  buffer_len += 2+len;
		  }
#ifdef SUPPORT_OTA_PUSH
		  /* 记录OTA PUSH消息的ota_name */
		  if (tlist->ota_name)
		  {
			  mms_Tracer((char*)"ota_name");
			  if (tlist->ota_name[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_NAME;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_name)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_name,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }
		  /* 记录OTA PUSH消息的ota_gateway */
		  if (tlist->ota_gateway)
		  {
			  mms_Tracer((char*)"ota_gateway");
			  if (tlist->ota_gateway[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_GATEWAY;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_gateway)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_gateway,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }
		  /* 记录OTA PUSH消息的ota_port */
		  if (tlist->ota_port)
		  {
			  mms_Tracer((char*)"ota_port");
			  if (tlist->ota_port[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_PORT;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_port)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_port,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		 
		  /* 记录OTA PUSH消息的ota_netacc */
		  if (tlist->ota_netacc)
		  {
			  mms_Tracer((char*)"ota_netacc");
			  if (tlist->ota_netacc[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_NETACC;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_netacc)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_netacc,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_murl */
		  if (tlist->ota_murl)
		  {
			  mms_Tracer((char*)"ota_murl");
			  if (tlist->ota_murl[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_MURL;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_murl)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_murl,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_smsc */
		  if (tlist->ota_smsc)
		  {
			  mms_Tracer((char*)"ota_smsc");
			  if (tlist->ota_smsc[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_SMSC;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_smsc)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_smsc,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_ispname */
		  if (tlist->ota_ispname)
		  {
			  mms_Tracer((char*)"ota_ispname");
			  if (tlist->ota_ispname[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_ISPNAME;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_ispname)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_ispname,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_csdscode */
		  if (tlist->ota_csdscode)
		  {
			  mms_Tracer((char*)"ota_csdscode");
			  if (tlist->ota_csdscode[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_CSDSCODE;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_csdscode)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_csdscode,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_apn */
		  if (tlist->ota_apn)
		  {
			  mms_Tracer((char*)"ota_apn");
			  if (tlist->ota_apn[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_APN;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_apn)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_apn,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_user */
		  if (tlist->ota_user)
		  {
			  mms_Tracer((char*)"ota_user");
			  if (tlist->ota_user[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_USER;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_user)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_user,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_passw */
		  if (tlist->ota_passw)
		  {
			  mms_Tracer((char*)"ota_passw");
			  if (tlist->ota_passw[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_PASSW;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_passw)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_passw,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		 
		  /* 记录OTA PUSH消息的ota_authtype */
		  if (tlist->ota_authtype)
		  {
			  mms_Tracer((char*)"ota_authtype");
			  if (tlist->ota_authtype[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_AUTHTYPE;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_authtype)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_authtype,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_logintype */
		  if (tlist->ota_logintype)
		  {
			  mms_Tracer((char*)"ota_logintype");
			  if (tlist->ota_logintype[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_LOGINTYPE;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_logintype)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_logintype,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }	
		  /* 记录OTA PUSH消息的ota_bmurl */
		  if (tlist->ota_bmurl)
		  {
			  mms_Tracer((char*)"ota_bmurl");
			  if (tlist->ota_bmurl[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_BMURL;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_bmurl)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_bmurl,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }		  
		  /* 记录OTA PUSH消息的ota_bmname */
		  if (tlist->ota_bmname)
		  {
			  mms_Tracer((char*)"ota_bmname");
			  if (tlist->ota_bmname[0] != 0)
			  {
				  *buffer_pos = (S8)MSG_HDR_TYPE_OTA_BMNAME;
				  buffer_pos += 1;
				  len = strlen(tlist->ota_bmname)+1;
				  *buffer_pos = (S8)len;
				  buffer_pos += 1;
				  memcpy(buffer_pos,tlist->ota_bmname,len);
				  buffer_pos += len;
				  buffer_len += 2+len;
			  }
		  }
#endif
		  if (tlist->size >= 0)
		  {
			  U32 SLen = 0;
			  U16 tLen = 0;

			  mms_Tracer((char*)"aaaaaaaaaa3333333333333333333");
			  *buffer_pos = (S8)MSG_HDR_TYPE_SIZE;
			  buffer_pos += 1;		  
			  SLen = tlist->size;
			  tLen=(SLen&0xffff0000)>>16;
			  len = (tLen & 0xff00)>>8;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  len = tLen & 0xff;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;

			  tLen=SLen&0xffff;
			  len = (tLen & 0xff00)>>8;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  len = tLen & 0xff;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  
			  buffer_len += 5;
		  }		   
		  /* 记录信息有效*/
		  if (tlist->size >= 0)
		  {
			  U16 tLen = 0;
			  *buffer_pos = (S8)MSG_HDR_TYPE_EXPRIY;
			  buffer_pos += 1;
			  tLen = tlist->expriy_time;
			  len = (tLen & 0xff00)>>8;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  len = tLen & 0xff;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  buffer_len += 3;
		  }
		   /* 记录节点信息类型*/		
		  if (tlist->msgtype>0)
		  {
			  mms_Tracer((char*)"bbbbbbbbbbbbfgsdbbbbbbbb");
			  *buffer_pos = (S8)MSG_HDR_TYPE_MSGTYPE;
			  buffer_pos += 1;
			  len = 1;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  *buffer_pos = (S8)tlist->msgtype;
			  buffer_pos += 1;
			  buffer_len += len + 2;
		  }	
		  /* 记录mms的状态信息，状态信息为最后一个 */		
		  if (tlist->state == 'N' ||tlist->state == 'Y'||tlist->state == 'U'||tlist->state == 'R')
		  {			  
			  mms_Tracer((char*)"aaaaaaaaaa4444444444444");
			  *buffer_pos = (S8)MSG_HDR_TYPE_STATE;
			  buffer_pos += 1;
			  len = 1;
			  *buffer_pos = (S8)len;
			  buffer_pos += 1;
			  *buffer_pos = (S8)tlist->state;
			  buffer_pos += 1;
			  buffer_len += len + 2;
		  }
		  else
		  {
			  mms_Tracer((char*)"error:mms_file_manager_store_current_folder--tlist->state is invalid");
			  mms_Free(buffer_file);
			  buffer_file = NULL;
			  buffer_pos = NULL;
			  return ;
		  }
	  }
	  /* 将内存中的摘要信息记录到摘要文件中 */
	  fp = Cms_Adp_fopen(digestfile, FS_CREATE_ALWAYS);
	  if(fp < 0)
	  {
		 DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		  mms_Free(buffer_file);
		  buffer_file = NULL;
		  buffer_pos = NULL;
		  Cms_Adp_fclose(fp);
		  return ;
	  }
	  if(0 != Cms_Adp_fwrite(fp, buffer_file, buffer_len, &rd))
	  {
		  mms_Tracer((char*)"storecurfolder write error!");
	  }
	  Cms_Adp_fclose(fp);
	  /* 释放内存资源 */
	  if (buffer_file)
	  {
		  mms_Free(buffer_file);
		  buffer_file = NULL;
		  buffer_pos = NULL;
	  }
	  mms_Tracer((char*)"end of mms_file_manager_store_current_folder");	 
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_store_all_folders
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_store_all_folders(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S8		pathname[MMS_FILE_NAME_LEN];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/  
	  if(!pgManager)
	  {
		  return ;
	  }
	  memset(pathname,0,sizeof(pathname));
	  
	  /* 保存收件箱 */
	  pgManager->currentFolder = pgManager->receiveFolder;
	  if(pgManager->currentFolder != NULL)
	  {
		  mms_file_manager_store_current_folder();
	  }
	  /* 保存发件箱 */
	  pgManager->currentFolder = pgManager->sendFolder;
	  if(pgManager->currentFolder != NULL)
	  {
		  mms_file_manager_store_current_folder();
	  }
	  /* 保存草稿箱 */
	  pgManager->currentFolder = pgManager->draftFolder;
	  if(pgManager->currentFolder != NULL)
	  {
		  mms_file_manager_store_current_folder();
	  }	
	  return ;
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_set_current_folder
 *       Purpose: 
 *         Input: MMS_FOLDER_NAME boxName
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_set_current_folder(MMS_FOLDER_NAME boxName)
{
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(!pgManager)
	  {
		  return ;
	  }
	  if((boxName != MMS_RECEIVE_FOLDER) && (boxName != MMS_SEND_FOLDER) && (boxName != MMS_DRAFT_FOLDER))
	  {
		  pgManager->currentFolder=NULL;
		  return ;
	  }
	  switch(boxName)
	  {
	  case MMS_RECEIVE_FOLDER:
		  pgManager->currentFolder = pgManager->receiveFolder;
		  break;
	  case MMS_SEND_FOLDER:
		  pgManager->currentFolder = pgManager->sendFolder;
		  break;
	  case MMS_DRAFT_FOLDER:
		  pgManager->currentFolder = pgManager->draftFolder;
		  break;
	  }
	  
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_get_current_folder
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: boxname
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
MMS_FOLDER_NAME mms_file_manager_get_current_folder(void)
{	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(pgManager == NULL)
	  {
		  return NULL;
	  }
	  
	  if (pgManager->currentFolder == pgManager->sendFolder)
	  {
		  return MMS_SEND_FOLDER;
	  }
	  else if (pgManager->currentFolder == pgManager->receiveFolder)
	  {
		  return MMS_RECEIVE_FOLDER;
	  }
	  else if (pgManager->currentFolder == pgManager->draftFolder)
	  {
		  return MMS_DRAFT_FOLDER;
	  }
	  else
	  {
		  return MMS_FOLDER_UNKNOWN;
	  }
	  
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_delete_current_folder
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_delete_current_folder(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	  P_MESSAGELIST			tlist = NULL;
	  P_MESSAGELIST			temp = NULL;
	  P_MESSAGEFOLDER		folder =  NULL;
	  S8						pathname[MMS_FILE_NAME_LEN];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/	  
	  if(!pgManager)
	  {
		  return ;
	  }
	  if(!pgManager->currentFolder)
	  {
		  return ;
	  }
	  memset(pathname,0,MMS_FILE_NAME_LEN);

	  folder = pgManager->currentFolder;
	  /* 逐个删除管理中的内存资源和对应的mms文件 */
	  if(folder != NULL)
	  {
		  for(tlist=folder->root; tlist!=NULL;)
		  {
			  temp = tlist->next;

			  mms_file_manager_delete_message(tlist);
			  mms_file_manager_free_message(tlist);
			  tlist = temp;
		  }
	  }
	  /* 将当前的信箱对应的摘要文件删除 */
	  folder->root = NULL;
	  folder->messageNumber = 0;
	  folder->messageSize = 0;
	  strcpy(pathname, CMS_MMS_APP_PATH);
	  if(folder == pgManager->receiveFolder)
	  {
		  strcat(pathname, "rmf.txt");
	  }
	  else if(folder == pgManager->sendFolder)
	  {
		  strcat(pathname, "smf.txt");
	  }
	  else if(folder == pgManager->draftFolder)
	  {
		  strcat(pathname, "dmf.txt");
	  }
	  else
	  {
	  }
	  if (Cms_Adp_FileExists(pathname))
	  {
		  Cms_Adp_fdelete((const unsigned short*)pathname);
	  }
	  folder->currentMessage = NULL;
	  folder->pushMessage = NULL;
	  pgManager->currentFolder=NULL;
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_read_one_folder
 *       Purpose: 
 *         Input: P_MESSAGEFOLDER folder,S8* file
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
S32 mms_file_manager_read_one_folder(P_MESSAGEFOLDER folder,S8* file)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGELIST		messagelist = NULL, tlist = NULL;
	MMS_FILE_HANDLE 	fp = 0;
	S32					file_len = 0;
	S8* 					file_buffer = NULL;   /* 摘要内存的开始 */
	
	S32	 				file_pos = 0;   
	S8  					flag_continue = 0;
	S8*					ptr_buf = NULL;
	U16 					rd = 0;
			
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_Tracer((char*)"^_^mms_file_manager_read_one_folder");
	/* 入口条件判断 */
	if(!folder)
	{
		mms_Tracer((char*)"the folder is empty!!!");
		return 0;
	}
	fp = Cms_Adp_fopen(file, FS_READ_ONLY);
	if(fp < 0)
	{
		mms_Tracer((char*)"file open error!!!");
		Cms_Adp_fclose(fp);
		return 0;	/* 读取文件错误 */
	}
	
	Cms_Adp_GetFileSize(fp, (unsigned int*)(&file_len));
	
	
	if(file_len <= 0)
	{
		Cms_Adp_fclose(fp);
		mms_Tracer((char*)"file is empty!!!");
		return 0;
	}
	/* 防止越界多分配256个字节 */
	file_buffer = (S8*)mms_Malloc(sizeof(S8)*(file_len + 256));
	if(!file_buffer)
	{
		mms_Tracer((char*)"allocate file_buffer error!!!");
		Cms_Adp_fclose(fp);
		return 0;
	}
	memset(file_buffer, 0, (file_len + 256));

	if (0 != Cms_Adp_fread(fp, file_buffer, file_len, (unsigned int*)(&rd))) 
	{
		mms_Tracer((char*)"^_^I can not find mms node file!");
		Cms_Adp_fclose(fp);
		mms_Free(file_buffer);
		file_buffer = NULL;
		return 0;
	}
	Cms_Adp_fclose(fp);
	
	file_pos = 0;
	
	/* 一个外循环为检索一个摘要节点 */
	while(1)   /* 外循环BEGIN */
	{
		/* 文件末尾退出外循环 */
		if(file_pos >= file_len)
		{
			break;
		}		
		messagelist = (P_MESSAGELIST)mms_Malloc(sizeof(MESSAGELIST));
		if(!messagelist)
		{
			mms_Tracer((char*)"ReadOneMessageFolder:messagelist malloc failed");
			mms_Free(file_buffer);
			file_buffer = NULL;
			return 0;
		}
		memset(messagelist, 0, sizeof(MESSAGELIST));
		messagelist->next = NULL;

		flag_continue = 1;

		/* 一个内循环为检索一个摘要节点内部信息 */
		while(flag_continue)    /* 内循环BEGIN  */
		{
			S8 msg_hdr_type = MSG_HDR_TYPE_UNKNOWN;
			U8 msg_hdr_type_len = 0;
			U8 msg_hdr_type_len_2 = 0;
			U8 msg_hdr_type_len_3 = 0;
			U8 msg_hdr_type_len_4 = 0;
			
			/* 出现异常情况 */
			if(file_pos >= file_len)
			{ 
				mms_Free(file_buffer);
				file_buffer = NULL;
				mms_file_manager_delete_message(messagelist);
				mms_file_manager_free_message(messagelist);
				messagelist = NULL;
				return 0;				
			}
			/* 读出每个field的类型和长度 */
			msg_hdr_type = (S8)(*(file_buffer + file_pos));
			mms_mmi_tracer("msg_hdr_type = %d", msg_hdr_type);

			if (msg_hdr_type == MSG_HDR_TYPE_ADDRESS)
			{
				msg_hdr_type_len = (U8)(*(file_buffer + file_pos + 1));
				msg_hdr_type_len_2 = (U8)(*(file_buffer + file_pos + 2));
				/* 指向field的值 */
				ptr_buf = file_buffer + file_pos + 3;
				file_pos += (msg_hdr_type_len *256  + msg_hdr_type_len_2 + 3);
			}
			else if (msg_hdr_type == MSG_HDR_TYPE_CC_ADDRESS)
			{
				msg_hdr_type_len = (U8)(*(file_buffer + file_pos +1));
				msg_hdr_type_len_2 = (U8)(*(file_buffer + file_pos + 2));
				/* 指向field的值 */
				ptr_buf = file_buffer + file_pos + 3;
				file_pos += (msg_hdr_type_len *256  + msg_hdr_type_len_2 + 3);
			}
                   else if (msg_hdr_type == MSG_HDR_TYPE_BCC_ADDRESS)
			{
				msg_hdr_type_len = (U8)(*(file_buffer + file_pos + 1));
				msg_hdr_type_len_2 = (U8)(*(file_buffer + file_pos + 2));
				/* 指向field的值 */
				ptr_buf = file_buffer + file_pos + 3;
				file_pos += (msg_hdr_type_len *256  + msg_hdr_type_len_2 + 3);
			}
			else if (msg_hdr_type == MSG_HDR_TYPE_SIZE)
			{
				msg_hdr_type_len = (U8)(*(file_buffer + file_pos + 1));
				msg_hdr_type_len_2 = (U8)(*(file_buffer + file_pos + 2));
				msg_hdr_type_len_3 = (U8)(*(file_buffer + file_pos + 3));
				msg_hdr_type_len_4 = (U8)(*(file_buffer + file_pos + 4));
				ptr_buf = file_buffer + file_pos + 5;
				file_pos += 5;
			}
			else if (msg_hdr_type == MSG_HDR_TYPE_EXPRIY)
			{
				msg_hdr_type_len = (U8)(*(file_buffer + file_pos + 1));
				msg_hdr_type_len_2 = (U8)(*(file_buffer + file_pos + 2));
				ptr_buf = file_buffer + file_pos + 3;
				file_pos += 3;
			}
			else
			{
				msg_hdr_type_len = (U8)(*(file_buffer + file_pos + 1));
				/* 指向field的值 */
				ptr_buf = file_buffer + file_pos + 2;
				file_pos += (msg_hdr_type_len + 2);
			}
			if(file_pos > file_len)
			{
				mms_Tracer((char*)"ReadOneMessageFolder: file_len error , Data may be corrupted!");
				mms_Free(file_buffer);
				file_buffer = NULL;
				mms_file_manager_delete_message(messagelist);
				mms_file_manager_free_message(messagelist);
				messagelist = NULL;
				return 0;
			}			
			switch(msg_hdr_type)
			{
				/* 开头为mms的文件名 */
			case MSG_HDR_TYPE_FILENAME:
				if(msg_hdr_type_len != 0)
				{
					messagelist->fileName = (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if(!messagelist->fileName)
					{
						mms_Free(file_buffer);
						file_buffer = NULL;
						mms_file_manager_delete_message(messagelist);
						mms_file_manager_free_message(messagelist);
						messagelist = NULL;
						return 0;
					}
					if(messagelist->fileName)
					{
						memset(messagelist->fileName, 0, msg_hdr_type_len+1+2);
						memcpy(messagelist->fileName, ptr_buf, msg_hdr_type_len);
					}
				}
				break;
				/* 地址信息 */
			case MSG_HDR_TYPE_ADDRESS:
				if((msg_hdr_type_len *256  + msg_hdr_type_len_2) != 0)
				{
					messagelist->to_address = (S8 *)mms_Malloc((msg_hdr_type_len *256  + msg_hdr_type_len_2)+1+2);
					if(messagelist->to_address)
					{
						memset(messagelist->to_address, 0, (msg_hdr_type_len * 256 + msg_hdr_type_len_2)+1+2);
						memcpy(messagelist->to_address, ptr_buf, (msg_hdr_type_len * 256 + msg_hdr_type_len_2));
					}
				}
				break;
				
			case MSG_HDR_TYPE_CC_ADDRESS:
				if((msg_hdr_type_len *256  + msg_hdr_type_len_2) != 0)
				{
					
                                 messagelist->cc_address = (S8 *)mms_Malloc((msg_hdr_type_len *256  + msg_hdr_type_len_2)+1+2);
                                 if(messagelist->cc_address)
					{
						memset(messagelist->cc_address, 0, (msg_hdr_type_len * 256 + msg_hdr_type_len_2)+1+2);
						memcpy(messagelist->cc_address, ptr_buf, (msg_hdr_type_len * 256 + msg_hdr_type_len_2));
					}
				}
				break;

                      case MSG_HDR_TYPE_BCC_ADDRESS:
				if((msg_hdr_type_len *256  + msg_hdr_type_len_2) != 0)
				{
					
                                 messagelist->bcc_address = (S8 *)mms_Malloc((msg_hdr_type_len *256  + msg_hdr_type_len_2)+1+2);
                                 if(messagelist->bcc_address)
					{
						memset(messagelist->bcc_address, 0, (msg_hdr_type_len * 256 + msg_hdr_type_len_2)+1+2);
						memcpy(messagelist->bcc_address, ptr_buf, (msg_hdr_type_len * 256 + msg_hdr_type_len_2));
					}
				}
				break;
				/* 主题信息 */
			case MSG_HDR_TYPE_SUBJECT:
				if(msg_hdr_type_len != 0)
				{
					messagelist->subject = (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if(messagelist->subject != NULL)
					{
						memset(messagelist->subject, 0, msg_hdr_type_len+1+2);
						memcpy(messagelist->subject, ptr_buf, msg_hdr_type_len);
					}
				}
				break;
				/* 时间信息 */
			case MSG_HDR_TYPE_DATE:
				if (msg_hdr_type_len != 0)
				{
					messagelist->date = (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->date != NULL)
					{
						memset(messagelist->date,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->date, ptr_buf, msg_hdr_type_len);
					}
				}
				break;
				/* URL */
			case MSG_HDR_TYPE_URL:
				if (msg_hdr_type_len != 0)
				{
					messagelist->url = (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->url != NULL)
					{
						memset(messagelist->url,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->url, ptr_buf, msg_hdr_type_len);
					}
				}
				break;

#ifdef SUPPORT_OTA_PUSH
			/* OTA_NAME */
			case MSG_HDR_TYPE_OTA_NAME:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_name = (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_name != NULL)
					{
						memset(messagelist->ota_name,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_name, ptr_buf, msg_hdr_type_len);
					}
				}
				break;
			/* OTA_GATEWAY */
			case MSG_HDR_TYPE_OTA_GATEWAY:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_gateway= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_gateway!= NULL)
					{
						memset(messagelist->ota_gateway,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_gateway, ptr_buf, msg_hdr_type_len);
					}
				}
				break;
			/* ota_port */
			case MSG_HDR_TYPE_OTA_PORT:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_port= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_port!= NULL)
					{
						memset(messagelist->ota_port,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_port, ptr_buf, msg_hdr_type_len);
					}
				}
				break;			
				/* ota_netacc */
			case MSG_HDR_TYPE_OTA_NETACC:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_netacc= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_netacc!= NULL)
					{
						memset(messagelist->ota_netacc,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_netacc, ptr_buf, msg_hdr_type_len);
					}
				}
				break;			
				/* ota_murl */
			case MSG_HDR_TYPE_OTA_MURL:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_murl= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_murl!= NULL)
					{
						memset(messagelist->ota_murl,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_murl, ptr_buf, msg_hdr_type_len);
					}
				}
				break;			
				/* ota_smsc */
			case MSG_HDR_TYPE_OTA_SMSC:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_smsc= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_smsc!= NULL)
					{
						memset(messagelist->ota_smsc,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_smsc, ptr_buf, msg_hdr_type_len);
					}
				}
				break;			

				/* ota_ispname */
			case MSG_HDR_TYPE_OTA_ISPNAME:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_ispname= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_ispname!= NULL)
					{
						memset(messagelist->ota_ispname,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_ispname, ptr_buf, msg_hdr_type_len);
					}
				}
				break;			
				/* ota_csdscode */
			case MSG_HDR_TYPE_OTA_CSDSCODE:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_csdscode= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_csdscode!= NULL)
					{
						memset(messagelist->ota_csdscode,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_csdscode, ptr_buf, msg_hdr_type_len);
					}
				}
				break;			
				/* ota_apn */
			case MSG_HDR_TYPE_OTA_APN:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_apn= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_apn!= NULL)
					{
						memset(messagelist->ota_apn,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_apn, ptr_buf, msg_hdr_type_len);
					}
				}
				break;			
				/* ota_user */
			case MSG_HDR_TYPE_OTA_USER:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_user= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_user!= NULL)
					{
						memset(messagelist->ota_user,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_user, ptr_buf, msg_hdr_type_len);
					}
				}
				break;			
				/* ota_passw */
			case MSG_HDR_TYPE_OTA_PASSW:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_passw= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_passw!= NULL)
					{
						memset(messagelist->ota_passw,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_passw, ptr_buf, msg_hdr_type_len);
					}
				}
				break;	
				/* ota_authtype */
			case MSG_HDR_TYPE_OTA_AUTHTYPE:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_authtype= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_authtype!= NULL)
					{
						memset(messagelist->ota_authtype,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_authtype, ptr_buf, msg_hdr_type_len);
					}
				}
				break;			
				/* ota_passw */
			case MSG_HDR_TYPE_OTA_LOGINTYPE:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_logintype= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_logintype!= NULL)
					{
						memset(messagelist->ota_logintype,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_logintype, ptr_buf, msg_hdr_type_len);
					}
				}
				break;	
				/* ota_bmurl */
			case MSG_HDR_TYPE_OTA_BMURL:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_bmurl= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_bmurl!= NULL)
					{
						memset(messagelist->ota_bmurl,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_bmurl, ptr_buf, msg_hdr_type_len);
					}
				}
				break;			
				/* ota_bmname */
			case MSG_HDR_TYPE_OTA_BMNAME:
				if (msg_hdr_type_len != 0)
				{
					messagelist->ota_bmname= (S8 *)mms_Malloc(msg_hdr_type_len+1+2);
					
					if (messagelist->ota_bmname!= NULL)
					{
						memset(messagelist->ota_bmname,0,msg_hdr_type_len+1+2);
						memcpy(messagelist->ota_bmname, ptr_buf, msg_hdr_type_len);
					}
				}
				break;
#endif

			case MSG_HDR_TYPE_SIZE:
				messagelist->size =msg_hdr_type_len * 256*256*256+ msg_hdr_type_len_2 * 256*256
								+msg_hdr_type_len_3 * 256 + msg_hdr_type_len_4;
				break;
			case MSG_HDR_TYPE_EXPRIY:
				messagelist->expriy_time= msg_hdr_type_len * 256 + msg_hdr_type_len_2;
				break;
			case MSG_HDR_TYPE_MSGTYPE:
				memcpy((char*)&messagelist->msgtype, ptr_buf, msg_hdr_type_len);
				break;
				/* MMS状态信息，最后一个字节 */
			case MSG_HDR_TYPE_STATE:
				/*用以标识状态的长度只可能是1，否则数据必定已损坏*/
				if(msg_hdr_type_len != 1)
				{
					mms_Free(file_buffer);
					file_buffer = NULL;
					mms_file_manager_delete_message(messagelist);
					mms_file_manager_free_message(messagelist);
					messagelist = NULL;
					return 0;				
				}
				memcpy((char*)&messagelist->state, ptr_buf, msg_hdr_type_len);
				/* 状态标记在末尾,退出内循环 */
				flag_continue = 0;
				break;
				
			default:
				mms_Free(file_buffer);
				file_buffer = NULL;
				mms_file_manager_delete_message(messagelist);
				mms_file_manager_free_message(messagelist);
				messagelist = NULL;
				return 0;					
			}
		}   /* 内循环结束END */
		/* 一个节点读完，插入到管理器中的链表中 */
		if(folder->root == NULL)
		{
			folder->root = messagelist;
		}
		else
		{
			for(tlist = folder->root; tlist->next; tlist = tlist->next)
			{/*Doing nothing, Just to seek to the end*/
				;
			}
			tlist->next = messagelist;
		}
		/* 总字节数增加 */

		if(messagelist->url!=NULL)
		{
			folder->messageSize +=0;
		}
		else
		{
			folder->messageSize+=messagelist->size;
		}

		/* MMS总数加1 */
		folder->messageNumber++;
	}  /* 外循环END */
	mms_Free(file_buffer);
	file_buffer = NULL;
	file_pos = NULL;
	return 1;
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_file_manager_read_all_folders
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_file_manager_read_all_folders(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S8		receive_file[MMS_FILE_NAME_LEN];
	S8		send_file[MMS_FILE_NAME_LEN];
	S8		draft_file[MMS_FILE_NAME_LEN];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/	  
	  if(!pgManager)
	  {
		  mms_Tracer((char*)"ReadAllMessageFolder:pgManager == NULL");
		  return ;
	  }
	  else
	  {
		  if(!pgManager->sendFolder && !pgManager->draftFolder && !pgManager->receiveFolder)
		  {
		      mms_Tracer((char*)"ReadAllMessageFolder:folders are NULL");
			  return ;
		  }
	  }	
	  memset(receive_file, 0, MMS_FILE_NAME_LEN);
	  memset(send_file, 0, MMS_FILE_NAME_LEN);
	  memset(draft_file, 0, MMS_FILE_NAME_LEN);
	  
	  /* 先读收件箱 */
	  strcpy(receive_file, CMS_MMS_APP_PATH);
	  strcat(receive_file, "rmf.txt");
	  if (Cms_Adp_FileExists(receive_file))
	  {
		  mms_file_manager_read_one_folder(pgManager->receiveFolder,receive_file);
	  }
	  
	  /* 再读发件箱 */
	  strcpy(send_file, CMS_MMS_APP_PATH);
	  strcat(send_file, "smf.txt");
	  if (Cms_Adp_FileExists(send_file))
	  {
		  mms_file_manager_read_one_folder(pgManager->sendFolder,send_file);
	  }
	  
	  /* 再读草稿箱 */
	  strcpy(draft_file, CMS_MMS_APP_PATH);
	  strcat(draft_file, "dmf.txt");
	  if (Cms_Adp_FileExists(draft_file))
	  {
		  mms_file_manager_read_one_folder(pgManager->draftFolder,draft_file);
	  }
}

#endif	 
 /******************************************************************************
 *                                                                          *
 ******************************************************************************/
 
/* ----------------------------------------------------------------------------
 * Function Name: mms_init_message_settings
 *       Purpose: 读取信息设置配置存放至gconfig结构的成员中
 *         Input: gconfig结构成员
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_message_settings(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	FS_HANDLE 	fp = 0;
	S32 			file_len = 0;
	S32 			file_pos = 0;
	char* 		file_buf = NULL;
	S8*			ptr_buf = NULL;
	int 			flag_continue = 0;
	U16 			rd = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if (!Cms_Adp_FileExists((S8*)MESSAGE_SETTINGS_FILE))
	{
		mms_Tracer((char*)"msg setting file not exists!!!!!!");
		return;
	}
	fp = Cms_Adp_fopen((S8*)MESSAGE_SETTINGS_FILE, FS_READ_ONLY);
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
			S8 msg_cfg_field = MSG_CFG_UNKNOWN;
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
			case MSG_CFG_SERVICE_ID:
				if(msg_cfg_field_len != 0)
				{
					memset(gconfig.service_id, 0, MMS_MAX_SERVICE_ID_LENGTH);
					memcpy(gconfig.service_id, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* 彩信中心 */
			case MSG_CFG_CENTRE:
				if(msg_cfg_field_len != 0)
				{
					memset(gconfig.centre_addr, 0, MMS_MAX_CENTRE_ADDR_LENGTH);
					memcpy(gconfig.centre_addr, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* 网关 */
			case MSG_CFG_GATEWAY:
				if(msg_cfg_field_len != 0)
				{
					memset(gconfig.gateway, 0, MMS_MAX_GATEWAY_LENGTH);
					memcpy(gconfig.gateway, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* 端口 */
			case MSG_CFG_PORT:
				if(msg_cfg_field_len != 0)
				{
					memset(gconfig.port, 0, MMS_MAX_PORT_LENGTH);
					memcpy(gconfig.port, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* 页时间 */
			case MSG_CFG_FRAMETIME:
				if(msg_cfg_field_len != 0)
				{	
					memset(gconfig.frametime, 0, MMS_MAX_FRAME_TIME_LENGTH);
					memcpy(gconfig.frametime, ptr_buf, msg_cfg_field_len);
				}
				break;	
				/* 有效期 */
			case MSG_CFG_EXPIRES:
				if(msg_cfg_field_len != 0)
				{
					gconfig.expires= (S32)(*ptr_buf);
				}
				break;
				/* 发送大小 */
			case MSG_CFG_SENDSIZE:
				if(msg_cfg_field_len != 0)
				{
					gconfig.sendsize= (S32)(*ptr_buf);
				}
				break;
				/* 接收大小 */
			case MSG_CFG_RETRIEVESIZE:
				if(msg_cfg_field_len != 0)
				{
					gconfig.retrievesize= (S32)(*ptr_buf);
				}
				break;
				/* 发送报告 */
			case MSG_CFG_REPORT:
				if(msg_cfg_field_len != 0)
				{
					gconfig.delivery_rpt = (S32)(*ptr_buf);
				}
				break;
				/* 匿名发送 */
			case MSG_CFG_ANONYMOUS:
				if(msg_cfg_field_len != 0)
				{
					gconfig.anonymous = (S32)(*ptr_buf);
				}
				break;
				/* 阅读报告 */
			case MSG_CFG_READ_RPT:
				if(msg_cfg_field_len != 0)
				{
					gconfig.read_rpt= (S32)(*ptr_buf);
				}
				break;
				/* 优先级 */
			case MSG_CFG_PRIORITY:
				if(msg_cfg_field_len != 0)
				{
					gconfig.prior = (S32)(*ptr_buf);
				}
				break;
				/* 接收方式 */
			case MSG_CFG_RETRIEVE:
				if(msg_cfg_field_len != 0)
				{
					gconfig.retrieve_mode = (S32)(*ptr_buf);
				}
				break;
				/* 当前MMS 启用的运营商项*/
			case MSG_CFG_MMS_ACTIVEITEM:
				if(msg_cfg_field_len != 0)
				{
					gconfig.mms_service_activeitem= (S32)(*ptr_buf);
				}
				break;
				/* 当前WAP 启用的运营商项*/
			case MSG_CFG_WAP_ACTIVEITEM:
				if(msg_cfg_field_len != 0)
				{
					gconfig.wap_service_activeitem= (S32)(*ptr_buf);
				}
				break;
				/* GPRS设定 */
			case MSG_CFG_GPRS:
				if(msg_cfg_field_len != 0)
				{
					gconfig.gprs_mode = (S32)(*ptr_buf);
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
/* ----------------------------------------------------------------------------
 * Function Name: mms_write_message_settings_file
 *       Purpose: 保存信息设置内容到文件
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_write_message_settings_file(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	FS_HANDLE 	fp = 0;
	char* 		buffer = NULL;
	char* 		buffer_pos = NULL;  /* 相对buffer的位置 */
	S32 			max_len = 0, buffer_len = 0, len = 0;
	U16 			rd = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	/* buffer最大长度为地址长度和网关长度之和，另外再分配64个字节 */
	max_len = MMS_MAX_CENTRE_ADDR_LENGTH + MMS_MAX_GATEWAY_LENGTH +\
				MMS_MAX_PORT_LENGTH +MMS_MAX_FRAME_TIME_LENGTH+ 64;

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
	*buffer_pos = (S8)MSG_CFG_SERVICE_ID;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gconfig.service_id)+2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gconfig.service_id, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of service_id ***************");
	/*写入彩信中心地址*/
	*buffer_pos = (S8)MSG_CFG_CENTRE;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gconfig.centre_addr)+2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gconfig.centre_addr, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of centre address***************");
	/*写入彩信网关*/
	*buffer_pos = (S8)MSG_CFG_GATEWAY;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gconfig.gateway) + 2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gconfig.gateway, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of gateway***************");
	/*写入彩信端口号*/
	*buffer_pos = (S8)MSG_CFG_PORT;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gconfig.port) + 2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gconfig.port, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of gateway***************");
	/*写入页时间*/
	*buffer_pos = (S8)MSG_CFG_FRAMETIME;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gconfig.frametime) + 2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gconfig.frametime, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of frametime***************");
	/*写入有效期*/
	*buffer_pos = (S8)MSG_CFG_EXPIRES;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.expires;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of expires***************");
	/*写入发送大小*/
	*buffer_pos = (S8)MSG_CFG_SENDSIZE;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.sendsize;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of sendsize***************");
	/*写入接收大小*/
	*buffer_pos = (S8)MSG_CFG_RETRIEVESIZE;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.retrievesize;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of retrievesize***************");
	/*写入发送报告*/
	*buffer_pos = (S8)MSG_CFG_REPORT;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.delivery_rpt;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of report***************");
	/*写入匿名发送*/
	*buffer_pos = (S8)MSG_CFG_ANONYMOUS;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.anonymous;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of anonymous***************");
	/*写入阅读报告*/
	*buffer_pos = (S8)MSG_CFG_READ_RPT;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.read_rpt;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of read report***************");
	/*写入优先级*/
	*buffer_pos = (S8)MSG_CFG_PRIORITY;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.prior;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of priority***************");
	/*写入接收方式*/
	*buffer_pos = (S8)MSG_CFG_RETRIEVE;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.retrieve_mode;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of retrieve***************");
	/*写入当前MMS 启用的运营商项*/
	*buffer_pos = (S8)MSG_CFG_MMS_ACTIVEITEM;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.mms_service_activeitem;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of mms_service_activeitem***************");
	/*写入当前WAP 启用的运营商项*/
	*buffer_pos = (S8)MSG_CFG_WAP_ACTIVEITEM;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.wap_service_activeitem;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of wap_service_activeitem***************");
	/*写入GPRS设定*/
	*buffer_pos = (S8)MSG_CFG_GPRS;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfig.gprs_mode;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of gprs mode***************");
	
	/* 完成将数据写入buffer */
	fp = Cms_Adp_fopen((S8*)MESSAGE_SETTINGS_FILE, FS_CREATE_ALWAYS);
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
/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose:   新建彩信结构(仅初始化时使用一次)
 *         Input: void
 *        Output: None.
 *       Returns: pMMS_EDocument.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
pMMS_EDocument mmi_mms_newdoc(void)
{
	pMMS_EDocument pDocument = NULL;
	pDocument=(pMMS_EDocument)(MMSNewDocument());
	if(pDocument)
	{
		pDocument->height = MMI_content_height;	
		pDocument->width = UI_device_width;
		
		pDocument->totalsize = 0;	
		pDocument->ftype = DOCUMENT_TYPE_MMS;
	}
	return pDocument;
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_del_content
 *       Purpose:  删除彩信结构中对应类型的内容(目前仅用来删除文本内容)
 *         Input:   editor_doc: 彩信结构地址 slide: 所在页地址 del_type: 待删除内容的类
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_del_content(pMMS_EDocument editor_doc, pMMS_Slide slide, U16 del_type)
{
	pMMS_Content content = NULL;
	
	content = slide->content_root;

	while(content)
	{
		if(content->type == del_type)
		{
			slide->content_cur = content;

			MMS_DelContent(slide,editor_doc);
			return;
		}
		content = content->next;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_remove_message_file_from_flash
 *       Purpose:  删除flash中彩信文件(后缀名为mms)
 *         Input: filename: 待删除文件名?
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_remove_message_file_from_flash(char* filename)
{
	char fname[128] = {0};
	strcpy(fname, (const char*)CMS_MMS_APP_PATH);
	strcat(fname, (const char*)filename);
	if (Cms_Adp_FileExists(fname))
	{
		Cms_Adp_fdelete((const unsigned short *)(fname));
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_flash_to_memory
 *       Purpose:  读取flash上文件到内存文件中
 *         Input: filename: 不带路径的文件名
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_flash_to_memory(char* filename)
{
	FS_HANDLE	fh = 0;
	char*		buffer = NULL;
	int			len = 0, rd = 0;
	S8			pathname [MMS_FILE_NAME_LEN] = {0};
	
	strcpy(pathname,CMS_MMS_APP_PATH);
	strcat(pathname,filename);

	if (mmsf_ifFileExited(filename))
	{
		mms_Tracer((char*)"file exists in memory!!!");
		return;
	}
	fh = Cms_Adp_fopen(pathname, FS_READ_ONLY);
	if (fh < 0)
	{
	    	FS_Close(fh);
		mms_Tracer((char*)"flash:fail to open flash file!!!");
		return ;
	}
	Cms_Adp_GetFileSize (fh, (unsigned int *)(&len));

	buffer = (char*)mms_Malloc(len);
	if (!buffer)
	{
		mms_Tracer((char*)"fail to allocate memory!!!");
		return ;
	}
	if(0 != FS_Read(fh, buffer, len, (unsigned int *)(&rd)))
	{
		mms_Tracer((char*)"read flash error!");
		FS_Close(fh);
		mms_Free(buffer);
		buffer = NULL;
		return;
	}
	FS_Close(fh);
	
	if (!buffer)
	{
		mms_Tracer((char*)"fail to GetConstFileData!!!");
		return ;
	}
	cmsf_SetFileData(filename, buffer, len);
}

/* ----------------------------------------------------------------------------
 * Function Name: cms_memory_to_flash
 *       Purpose:   将内存文件写入flash
 *         Input: filename: 不带路径的文件名
 *        Output: None.
 *       Returns: 0: 失败 1: 成功
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int cms_memory_to_flash(char* filename)
{
	FS_HANDLE	fh = 0;
	char*		buffer = NULL;
	int			len = 0, rd = 0;
    	S8			pathname [MMS_FILE_NAME_LEN] = {0};

	strcpy(pathname,CMS_MMS_APP_PATH);
	strcat(pathname,filename);

	mms_Tracer((char*)"cms_memory_to_flash: start________________");
	mmsf_GetConstFileData(filename,&buffer,&len);

	if (!buffer)
	{
		mms_Tracer((char*)"fail to GetConstFileData!!!");
		return 0;
	}
	if(Cms_Adp_JudgeCSpace((int)len)	)
	{
		FS_Close(fh);
		DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return 0;		
	}		
	fh = Cms_Adp_fopen(pathname, FS_CREATE_ALWAYS);
	if (fh < 0)
	{
	    FS_Close(fh);
		mms_Tracer((char*)"memory:fail to open flash file!!!");
		return 0;
	}
	if(0 != FS_Write(fh, buffer, len, (unsigned int *)(&rd)))
	{
		FS_Close(fh);
		return 0;
	}
	FS_Close(fh);
	mmsf_Remove(filename); 
	mms_Tracer((char*)"cms_memory_to_flash: complete remove filename!!!");
	return 1;
}

/* ----------------------------------------------------------------------------
 * Function Name: Cms_file_2_file
 *       Purpose:flash文件复制(C:\\)
 *         Input:  FName_des: 目标文件 FName_src: 源文件
 *        Output: None.
 *       Returns:0: 失败 1: 成功
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
int Cms_file_2_file(S8* FName_des, S8* FName_src)
{
	FS_HANDLE	fs = 0;
	char*		buffer = NULL;
	S32			fsize = 0;
	U16			rd = 0, wd = 0;
	char			file_scr[128] = {0};
	char			file_des[128] = {0};
	
	strcpy(file_scr, CMS_MMS_APP_PATH);
	strcat(file_scr, FName_src);
	strcpy(file_des, CMS_MMS_APP_PATH);
	strcat(file_des, FName_des);
	fs = Cms_Adp_fopen(file_scr, FS_READ_ONLY);
	
	if (fs < 0)
	{
		return 0;
	}
	Cms_Adp_GetFileSize(fs, (unsigned int*)(&fsize));
	if (fsize <= 0)
	{
		Cms_Adp_fclose(fs);
		return 0;
	}
	buffer = (char*)mms_Malloc(fsize);
	if (!buffer)
	{
		Cms_Adp_fclose(fs);
		return 0;
	}
	if (0 != Cms_Adp_fread(fs, buffer, fsize, (unsigned int*)(&rd))) 
	{
		mms_Free(buffer);
		buffer = NULL;
		Cms_Adp_fclose(fs);
		return 0;
	}
	Cms_Adp_fclose(fs);
	fs = 0;
	fs = Cms_Adp_fopen(file_des, FS_CREATE_ALWAYS);
	if (fs < 0)
	{
		mms_Free(buffer);
		buffer = NULL;
		Cms_Adp_fclose(fs);
		return 0;
	}
	if(Cms_Adp_JudgeCSpace((int)fsize))	
	{
		mms_Free(buffer);
		buffer = NULL;
		Cms_Adp_fclose(fs);
		DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return 0;		
	}	
	if (0 != Cms_Adp_fwrite(fs, buffer, fsize, (unsigned int*)(&wd))) 
	{
		Cms_Adp_fclose(fs);
		return 0;
	}
	Cms_Adp_fclose(fs);

	mms_Free(buffer);
	buffer = NULL;
	return 1;
}

/* ----------------------------------------------------------------------------
 * Function Name: cms_remove_memory_file
 *       Purpose:
 *         Input:
 *        Output: None.
 *       Returns:0: 失败 1: 成功
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void cms_remove_memory_file(void)
{
	if (gedit.mms_fname[0] != 0)
	{
		mms_Tracer((char*)"remove mms_fname!!!");
		mmsf_Remove(gedit.mms_fname);
	}
	if (pgManager->receiveFolder->pushMessage)
	{
		if(pgManager->receiveFolder->pushMessage->fileName!=NULL)
			mmsf_Remove(pgManager->receiveFolder->pushMessage->fileName);
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_parse_message_file
 *       Purpose: 对信息进行操作前解析当前选中信息mms文件 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_parse_message_file(void)
{
	P_MESSAGELIST pMsg = mms_file_manager_get_current_message();

	if (pMsg->state == 'N'&&mms_file_manager_get_current_folder()==MMS_RECEIVE_FOLDER)
	{
		mms_file_manager_modify_current_message_state(MMS_MSG_STATE_READ);
		mmi_update_mms_idel_icon();
	}
	if (!gpeditor_doc->slide_root)
	{
		gpeditor_doc->ftype = DOCUMENT_TYPE_MMS;
		gpeditor_doc->totalsize = 0;
		cms_flash_to_memory(pMsg->fileName);

		if(!cms_parse_mms(pMsg->fileName, gpeditor_doc))
		{
			return ;
		}
		MMS_HeadSlide(gpeditor_doc);
	}
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

#if 0
#endif

/* ----------------------------------------------------------------------------
 * Function Name: mms_judge_mms_box_size_count
 *       Purpose: 判断彩信大小和条数是否已满
 *         Input: P_MESSAGELIST pMsg
 *        Output: 1,0.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int mms_judge_mms_box_size_count(P_MESSAGELIST pMsg)
{
	U16 		count = 0;
	S32 		msize = 0;
	
	mms_get_all_boxes_count_size(&count, &msize);
	if (count > MAX_MESSAGE_COUNT)
	{
		DisplayPopup((U8*)GetString(STR_MMS_COUNT_REACHED_MAX), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return 0;
	}
	else if ((pMsg->size) >= MAX_SIZE_ALL_MMS)
	{
		char		buffer[MMS_MAX_DETAILS_LENGTH] = {0};
		char    	ucs2TempBuff[MAX_HINT_BUF];
		char		ansiiTempBuff[MAX_HINT_BUF*2];

		pfnUnicodeStrcpy(buffer, (const char*)GetString(STR_MMS_QUOTA_EXCEEDED));
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
		sprintf(ansiiTempBuff,"%d K\n",(int)(MAX_SIZE_ALL_MMS/1024));
		AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
		pfnUnicodeStrcat(buffer, (S8 *)ucs2TempBuff);
		
		DisplayPopup((U8*)buffer, IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return 0;
	}
	else if (pMsg->size>MMS_MAX_RECEIVE_SIZE)
	{
		DisplayPopup((U8*)GetString(STR_MMS_SIZE_TOO_BIG), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return 0;
	}
	return 1;
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_get_send_max_size
 *       Purpose: 判断彩信发送最大大小
 *         Input: P_MESSAGELIST pMsg
 *        Output: 1,0.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int mms_get_send_max_size()
{
	if(gconfig.sendsize==MMS_SETTINGS_30K)
	{
		return 30*1024;
	}
	else if(gconfig.sendsize==MMS_SETTINGS_50K)
	{
		return 50*1024;
	}		
	else if(gconfig.sendsize==MMS_SETTINGS_70K)
	{
		return 70*1024;
	}	
	else if(gconfig.sendsize==MMS_SETTINGS_100K)
	{
		return 100*1024;
	}
	else
	{
		return 50*1024;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_get_receive_max_size
 *       Purpose: 判断彩信接收最大大小
 *         Input: P_MESSAGELIST pMsg
 *        Output: 1,0.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int mms_get_receive_max_size()
{
	if(gconfig.retrievesize==MMS_SETTINGS_30K)
	{
		return 30*1024;
	}
	else if(gconfig.retrievesize==MMS_SETTINGS_50K)
	{
		return 50*1024;
	}		
	else if(gconfig.retrievesize==MMS_SETTINGS_70K)
	{
		return 70*1024;
	}	
	else if(gconfig.retrievesize==MMS_SETTINGS_100K)
	{
		return 100*1024;
	}
	else
	{
		return 50*1024;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_get_all_boxes_count_size
 *       Purpose: 获取所有信箱的彩信总数量及总大小
 *         Input:  *count: 返回彩信数量 *msize: 返回信箱大小
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_get_all_boxes_count_size(U16* count, S32* msize)
{
	U16 i = 0;
	S32	j = 0;
#ifdef SUPPORT_SMSMMS_COMBINE
	U16 k=0;
	P_MESSAGELIST pMsg;

	i = *count;
	j = *msize;
	if (!pgManager)
	{
		return ;
	}
	if (pgManager->receiveFolder)
	{
		pMsg = pgManager->receiveFolder->root;
		for (k=0;k< pgManager->receiveFolder->messageNumber && pMsg; k++)
		{
			if(pMsg->fileName!=NULL)
			{
				i+=1;
				if(!pMsg->url)
					j+=pMsg->size;
			}
			pMsg = pMsg->next;
		}
	}
	if (pgManager->sendFolder)
	{
		pMsg = pgManager->sendFolder->root;
		for (k=0;k< pgManager->sendFolder->messageNumber && pMsg; k++)
		{
			if(pMsg->fileName!=NULL)
			{
				i+=1;
				if(!pMsg->url)
					j+=pMsg->size;
			}
			pMsg = pMsg->next;
		}
	}
	if (pgManager->draftFolder)
	{
		pMsg = pgManager->draftFolder->root;
		for (k=0;k< pgManager->draftFolder->messageNumber && pMsg; k++)
		{
			if(pMsg->fileName!=NULL)
			{
				i+=1;
				if(!pMsg->url)
				 	j+=pMsg->size;
			}
			pMsg = pMsg->next;
		}
	}
	*count = i;
	*msize = j;
#else
	i = *count;
	j = *msize;
	if (!pgManager)
	{
		return ;
	}
	if (pgManager->receiveFolder)
	{
		i += pgManager->receiveFolder->messageNumber;
		j += pgManager->receiveFolder->messageSize;
	}
	if (pgManager->sendFolder)
	{
		i += pgManager->sendFolder->messageNumber;
		j += pgManager->sendFolder->messageSize;
	}
	if (pgManager->draftFolder)
	{
		i += pgManager->draftFolder->messageNumber;
		j += pgManager->draftFolder->messageSize;
	}
	*count = i;
	*msize = j;
#endif
}
/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 得到是否有新未读消息及空间已满并在桌面显示
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int mmi_mms_get_manager_msg_state(void)
{
	U16 count = 0;
	S32 msize = 0;
	P_MESSAGELIST pMsg_temp;

	mms_get_all_boxes_count_size(&count, &msize);
 
 	/* 空间已满*/
 	if(count>=MAX_MESSAGE_COUNT||(MAX_SIZE_ALL_MMS <= MMS_MAX_SIZE_OF_MESSAGE))
 	{
  		return CMS_MMS_STATUS_FULL;
 	}
 
	 /* 是否有未读消息*/
 	if(pgManager->receiveFolder->messageNumber>0)
 	{ 
  		pMsg_temp=pgManager->receiveFolder->root;
  		while(pMsg_temp!=NULL)
  		{ 
   			if((pMsg_temp->state=='U' && pMsg_temp->fileName!=NULL) || (pMsg_temp->state=='N'))
   			{
    				pMsg_temp = NULL;
    				return CMS_MMS_STATUS_NEW_MESSAGE;
			}
   			else
   			{   				
    				pMsg_temp=pMsg_temp->next;	
   			}
  		}		
  		pMsg_temp = NULL;
 	}
 
 	return CMS_MMS_STATUS_OFF;
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_icon_ind
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_icon_ind(unsigned int type)
{
	switch( type)
	{				
	 case CMS_MMS_STATUS_OFF:
	 	mms_Tracer((char*)("CMS_MMS_STATUS_OFF"));
		HideStatusIcon(STATUS_ICON_MMS_UNREAD);
		HideStatusIcon(STATUS_ICON_MMS_BUSY);
		break;
        case CMS_MMS_STATUS_NEW_MESSAGE:
		mms_Tracer((char*)("CMS_MMS_STATUS_NEW_MESSAGE"));
		HideStatusIcon(STATUS_ICON_MMS_BUSY);
		HideStatusIcon(STATUS_ICON_MMS_UNREAD);
		ShowStatusIcon(STATUS_ICON_MMS_UNREAD);
		break;
        case CMS_MMS_STATUS_BUSY:
		mms_Tracer((char*)("CMS_MMS_STATUS_BUSY"));
		HideStatusIcon(STATUS_ICON_MMS_UNREAD);
		HideStatusIcon(STATUS_ICON_MMS_BUSY);
   	    	BlinkStatusIcon(STATUS_ICON_MMS_BUSY);
		break;
	 case CMS_MMS_STATUS_FULL:
	 	mms_Tracer((char*)("CMS_MMS_STATUS_FULL"));
		HideStatusIcon(STATUS_ICON_MMS_UNREAD);
		HideStatusIcon(STATUS_ICON_MMS_BUSY);
		BlinkStatusIcon(STATUS_ICON_MMS_UNREAD);
		break;	
        default:
		mms_Tracer((char*)("CMS_MMS_STATUS_NULL"));	
		HideStatusIcon(STATUS_ICON_MMS_UNREAD);
		HideStatusIcon(STATUS_ICON_MMS_BUSY);
		break;
	}	
	//UpdateStatusIcons();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_new_msg_ind
 *       Purpose: play tone for new message come in 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_new_msg_ind(void)
{
	TurnOnBacklight(1);
	PlayMessageArrivalTone();	
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_suspend_mms_operation
 *       Purpose: 挂起彩信时停止播放彩信、gif动画
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_suspend_mms_operation(void)
{
	mms_stop_animation();
	mms_stop_music();
	if (mmsflag.gplay_state)
	{
		pixtel_UI_cancel_timer(mms_play_message_callback);
		mmsflag.gplay_state = FALSE;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_create_new_mms
 *       Purpose:  从文件目录选中某媒体文件创建新彩信
 *         Input: filePath: 选中的媒体文件名(含路径)
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_create_new_mms(void* filePath)
{
	mms_Tracer((char*)"start of cms_create_new_mms");
	if(filePath == NULL)
	{
		mms_Tracer((char*)"cms_create_new_mms:goback");
		GoBackHistory();  
		return;
	}
	{
		char* buf = NULL;
		char* temp_name = NULL;
		S32 filelen = 0;
		U16 type = 0;
       	 int   i = 0;
		MMS_FILE_HANDLE fp = 0;

		fp = FS_Open((unsigned short*)filePath, FS_READ_ONLY);
		if (fp < 0)
		{
			mms_Tracer((char*)"read file error!!!");					

			if(IsScreenPresent(SCR_ID_MMS_CONTENT_OPTIONS))
			{
				GoBackToHistory(SCR_ID_MMS_CONTENT_OPTIONS);
			}
			else
			{
				GoBackHistory();
			}
			return ;
		}
		mms_Tracer((char*)"get file size");
		
		Cms_Adp_GetFileSize(fp, (unsigned int*)(&filelen));
		
		mms_mmi_tracer("filelen = %d",(char*)filelen);
		
		buf = (char *)mms_Malloc(filelen);
		if (!buf)
		{
			mms_Tracer((char*)"allocate memory error!!!");
			return ;
		}
		if (0 != Cms_Adp_fread(fp, buf, filelen, (unsigned int*)(&i))) 
		{
			mms_Tracer((char*)"cms_create_new_mms: read error!");
			Cms_Adp_fclose(fp);
			mms_Free(buf);
			buf = NULL;
			return;
		}
		Cms_Adp_fclose(fp);

		temp_name = Cms_mms_uni16_8(filePath);
		if (temp_name)
		{
			type = mms_get_media_type((U8*)buf, strlen(temp_name), temp_name);
			mms_Free(temp_name);
			temp_name = NULL;
		}

		if (type == 0)
		{
			mms_Tracer((char*)"get media type error!!!");
			mms_Free(buf);
			buf = NULL;
			GoBackHistory(); 
			DisplayPopup((U8*)GetString(STR_TYPE_ERROR),IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			return ;
		}
		memset(&gedit, 0, sizeof(TEXT_EDIT));
		cms_empty_sendto_list();
		pgsendtolist=NULL;
		pgsendcclist=NULL;
		pgsendbcclist=NULL;
		
		if (gpeditor_doc->slide_root)
		{
			MMSDelAllSlide(gpeditor_doc);
			gpeditor_doc->totalsize = 0;
		}
		if(!MMS_New_Slide(gpeditor_doc))
		{
			mms_Free(buf);
			buf = NULL;
			return ;
		}
		switch(type)
		{
		case MMS_TYPE_GIF:
		case MMS_TYPE_JPEG:
#ifdef CMS_SURPPORT_PNG_BMP
		case MMS_TYPE_PNG:
#endif
		case MMS_TYPE_WBMP:
		case MMS_TYPE_BMP1:
			cms_insert_image_into_new_mms(buf, filelen, type);
			break;
		case MMS_TYPE_MIDI:
		case MMS_TYPE_WAV:
		case MMS_TYPE_IMY:
		case MMS_TYPE_AMR:
			cms_insert_music_into_new_mms(buf, filelen, type);
			break;
		case MMS_TYPE_VCF:
		case MMS_TYPE_VCS:
			cms_insert_accessory_into_new_mms(buf, filelen, type);
			break;
		default:
			mms_Free(buf);
			buf = NULL;
			return ;
		}
		mms_Free(buf);
		buf = NULL;
	}
	mmi_mms_entry_new_message();
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_insert_image_into_new_mms
 *       Purpose: 图像加入至新建彩信
 *         Input: char* image_buf, S32 buf_size, U16 image_type
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */

void cms_insert_image_into_new_mms(char* image_buf, S32 buf_size, U16 image_type)
{
	pMMS_Content 	content = NULL;	
	pMMS_Slide 		slide = gpeditor_doc->slide_cur;
	char 			img_fname[MMS_MAX_FILE_NAME_LENGTH];
	FILE_HANDLE 		fd = 0;

	mms_Tracer("enter cms_insert_image_into_new_mms");   
	if ((gpeditor_doc->totalsize + buf_size) > MMS_MAX_SIZE_OF_MESSAGE)
	{
		mms_Tracer((char*)"error:cms_insert_image_handler--gpeditor_doc->totalsize > MMS_MAX_SIZE_OF_MESSAGE");
		DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	mms_get_randstring(img_fname);

	switch(image_type)
	{
	case MMS_TYPE_GIF:
		strcat(img_fname,".gif");
		break;
	case MMS_TYPE_JPEG:
		strcat(img_fname,".jpg");
		break;
	case MMS_TYPE_PNG:
		strcat(img_fname,".png");
		break;
	case MMS_TYPE_WBMP:
		strcat(img_fname,".wbmp");
		break;
	case MMS_TYPE_BMP1:
		strcat(img_fname, ".bmp");
		break;
	default:
		break;
	}
	fd = mmsf_Open((char*)img_fname,"w");
	if (fd <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	mmsf_Write(image_buf, 1, buf_size, fd);
	mmsf_Close(fd);
	content = MMS_New_Content((unsigned char*)img_fname,image_type,slide,gpeditor_doc);
	gedit.total_height = 0;
	if (!content)
	{
		mms_Tracer((char*)"cms_insert_image_into_new_mms: new content error!!!");
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_insert_music_into_new_mms
 *       Purpose: 音乐加入至新建彩信
 *         Input: char* music_buf, S32 buf_size, U16 music_type
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 
void cms_insert_music_into_new_mms(char* music_buf, S32 buf_size, U16 music_type)
{
	pMMS_Slide 	slide = gpeditor_doc->slide_cur;
	char 		msc_fname[MMS_MAX_FILE_NAME_LENGTH];
	FILE_HANDLE 	fd = 0;


	if ((gpeditor_doc->totalsize + buf_size) > MMS_MAX_SIZE_OF_MESSAGE)
	{
		mms_Tracer((char*)"error:cms_insert_music_handler--gpeditor_doc->totalsize > MMS_MAX_SIZE_OF_MESSAGE");
		DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	mms_get_randstring(msc_fname);

	switch(music_type)
	{
	case MMS_TYPE_WAV:
		strcat(msc_fname, ".wav");
		break;
	case MMS_TYPE_MIDI:
		strcat(msc_fname, ".mid");
		break;
	case MMS_TYPE_IMY:
		strcat(msc_fname, ".imy");
		break;
	case MMS_TYPE_MMF:
		strcat(msc_fname, ".mmf");
		break;
	case MMS_TYPE_MP3:
		strcat(msc_fname, ".mp3");
		break;
	case MMS_TYPE_AMR:
		strcat(msc_fname, ".amr");
		break;
	}
	fd = mmsf_Open((char*)msc_fname,"w");
	
	if (fd <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	mmsf_Write(music_buf, 1, buf_size, fd);
	mmsf_Close(fd);

	if(!MMS_New_Audio((U8*)msc_fname,music_type,slide,gpeditor_doc))
	{
		mms_Tracer((char*)"fail to insert music!!!");
		return ;
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: cms_insert_accessory_into_new_mms
 *       Purpose: 附件加入至新建彩信
 *         Input: char* accessory_buf, S32 buf_size, U16 accessory_type
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */

void cms_insert_accessory_into_new_mms(char* accessory_buf, S32 buf_size, U16 accessory_type)
{
	pMMS_Content 	content = NULL;	
	pMMS_Slide 		slide = gpeditor_doc->slide_cur;
	char 			acc_fname[MMS_MAX_FILE_NAME_LENGTH];
	FILE_HANDLE 		fd = 0;

	mms_Tracer("enter cms_insert_accessory_into_new_mms");   
	if ((gpeditor_doc->totalsize + buf_size) > MMS_MAX_SIZE_OF_MESSAGE)
	{
		mms_Tracer((char*)"error:cms_insert_accessory_handler--gpeditor_doc->totalsize > MMS_MAX_SIZE_OF_MESSAGE");
		DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	mms_get_randstring(acc_fname);

	switch(accessory_type)
	{
	case MMS_TYPE_VCF:
		strcat(acc_fname,".vcf");
		break;
	case MMS_TYPE_VCS:
		strcat(acc_fname,".vcs");
		break;
	default:
		break;
	}
	fd = mmsf_Open((char*)acc_fname,"w");
	if (fd <= 0)
	{
		DisplayPopup((U8*)GetString(STR_MMS_FILE_PROCESS_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	mmsf_Write(accessory_buf, 1, buf_size, fd);
	mmsf_Close(fd);
	content = MMS_New_Content((unsigned char*)acc_fname,accessory_type,slide,gpeditor_doc);
	gedit.total_height = 0;
	if (!content)
	{
		mms_Tracer((char*)"cms_insert_accessory_into_new_mms: new content error!!!");
	}
}
/***************************************************************************** 
* 发送接收相关接口及消息队列
*****************************************************************************/

/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 加入消息队列
 *         Input: MessageID: 消息ID     ptr: 设为NULL即可
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_post_message(unsigned int MessageID,void *ptr)
{
	ilm_struct *send_ilm;
    	send_ilm = allocate_ilm(MOD_MMI);
	send_ilm->src_mod_id = MOD_MMI;
	send_ilm->dest_mod_id = MOD_CMSMMS;
	send_ilm->sap_id = 0;

	SetProtocolEventHandler((PsFuncPtr)mms_notification_arrive,MSG_ID_CMS_MMS_NOTIFICATION_ARRIVE);
	SetProtocolEventHandler((PsFuncPtr)mms_recvd_ok,MSG_ID_CMS_MMS_RECV_SUCCESS);
	SetProtocolEventHandler((PsFuncPtr)mms_send_ok,MSG_ID_CMS_MMS_SEND_SUCCESS); 
	SetProtocolEventHandler((PsFuncPtr)mms_recv_failed,MSG_ID_CMS_MMS_RECV_FAILED); 
	SetProtocolEventHandler((PsFuncPtr)mms_send_failed,MSG_ID_CMS_MMS_SEND_FAILED_UNKNOWN); 

	SetProtocolEventHandler((PsFuncPtr)mms_send_message,MSG_ID_CMS_MMS_SEND_MESSAGE); 
	SetProtocolEventHandler((PsFuncPtr)mms_retrieve_message,MSG_ID_CMS_MMS_RECEIVE_MESSAGE); 
	//SetProtocolEventHandler((PsFuncPtr)NULL,MSG_ID_CMS_MMS_CONNECT_FAILED); //还没改
	SetProtocolEventHandler((PsFuncPtr)mmi_mms_box_play_message,MSG_ID_CMS_MMS_PLAY_MESSAGE); 

	switch(MessageID) 
	{
	case 256:/*CMS_MESSAGE_MMS_SMS_ARRIVE:*/
		send_ilm->msg_id = MSG_ID_CMS_MMS_NOTIFICATION_ARRIVE;
		break;	
	case 257:/*CMS_MESSAGE_MMS_RECVD:		*/
		send_ilm->msg_id = MSG_ID_CMS_MMS_RECV_SUCCESS;
		break;	
	case 258:/*CMS_MESSAGE_MMS_SEND_OK*/
		send_ilm->msg_id = MSG_ID_CMS_MMS_SEND_SUCCESS;
		break;
	case 259:/*CMS_MESSAGE_MMS_RECVD_FAILED*/
		send_ilm->msg_id = MSG_ID_CMS_MMS_RECV_FAILED;
		break;	
	case 260:/*CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN:*/
		send_ilm->msg_id = MSG_ID_CMS_MMS_SEND_FAILED_UNKNOWN;
		break;
		
	case 261:/*CMS_MESSAGE_MMS_SEND_MESSAGE:*/
		send_ilm->msg_id = MSG_ID_CMS_MMS_SEND_MESSAGE;
		break;		
	case 262:/*CMS_MESSAGE_MMS_RECEIVE_MESSAGE:*/
		send_ilm->msg_id = MSG_ID_CMS_MMS_RECEIVE_MESSAGE;
		break;		
	case 263:/*CMS_MESSAGE_MMS_CONNECT_FAILED:*/
		send_ilm->msg_id = MSG_ID_CMS_MMS_CONNECT_FAILED;
		break;	
	case 264:/*CMS_MESSAGE_MMS_PLAY_MESSAGE:*/
		send_ilm->msg_id = MSG_ID_CMS_MMS_PLAY_MESSAGE;
		break;
	default:
		return;
	}
	send_ilm->peer_buff_ptr = NULL;
	send_ilm->local_para_ptr = ptr;
	msg_send_ext_queue(send_ilm);

}
/* ----------------------------------------------------------------------------
 * Function Name: mms_lib_callback
 *       Purpose: 彩信收发回调函数
 *         Input: 
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int mms_lib_callback(int status,void *prompt,int status_value)
{
	switch(status)
	{
	case LIB_STATUS_NORMAL_STATUS:
		/*	可以在此处在状态栏上显示当前状况，
			如正在连接网关，正在发送数据，正在
			接收数据等是正常处理过程中的状态显示*/
		{
			switch(status_value)
			{
			case MMSNETLINKING:
				progress_value=5;
				mmi_mms_show_send_receive_status(progress_value);
				mms_Tracer((char*)"正在连接GPRS网络");
				break;
			case  MMSNETLINK_SUCCESS:
				progress_value=10;
				mmi_mms_show_send_receive_status(progress_value);				
				mms_Tracer((char*)"网络连接成功");
				break;
			case  WAPCONNECT_SUCCESS:
				progress_value=15;
				mmi_mms_show_send_receive_status(progress_value);
				mms_Tracer((char*)"wap网关连接成功");
				break;
			case  MMS_RECEIVING:
				mms_Tracer((char*)"正在接收彩信...");
				break;
			case  MMS_SENDING:
				mms_Tracer((char*)"正在发送彩信...");
				break;
			default:
				break;
			}
		}
		break;
	case  LIB_STATUS_SENDRETURN:
		{
			switch(status_value)
			{
			case MMS_RESPONSE_STATUS_VALUE_OK:
				progress_value=100;
				mmi_mms_show_send_receive_status(progress_value);
				mms_Tracer((char*)"发送成功！");
				sendover = 1;
				{
					/*若发件箱信息发送成功，修改状态改成已修改 */
					P_MESSAGELIST pMsg = pgManager->sendFolder->currentMessage;
					if(!mmsflag.gsend_save)
					{
						mms_file_manager_delete_message_from_box(pMsg, MMS_SEND_FOLDER);
						/*删除发送时生成的MMS后再找到原来的那条再修改其状态*/
						if(pgManager->currentFolder==pgManager->sendFolder)
						{
							P_MESSAGELIST message = NULL;
							U16  i=0;
							
							mms_Tracer("enter get sendfolder cur message");
							message = pgManager->sendFolder->root;
							
							for (;i < ghiliindex && message; i++)
							{
								message = message->next;
							}
							mms_Tracer((char*)"sendbox curmsg state is Y");
							message->state='Y';
							mms_file_manager_store_current_folder();
						}
					}
					else
					{
						MMS_FOLDER_NAME curfolder=0;
						mms_Tracer((char*)"gsend_save is TRUE");
						mmsflag.gmsg_saved=TRUE;
						pMsg->state='Y';
						curfolder = mms_file_manager_get_current_folder();
						mms_file_manager_set_current_folder(MMS_SEND_FOLDER);
						mms_file_manager_store_current_folder();
						mms_file_manager_set_current_folder(curfolder);
						
					}
				}
				cms_remove_memory_file();
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_OK, NULL);
				break;
			case MMS_RESPONSE_STATUS_VALUE_E_UNSPECIFIED:
				mms_Tracer((char*)"未指定的错误！");
				sendover = 1;
				cms_remove_memory_file();
				/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				DisplayPopup((U8*)GetString(STR_SEND_FAILED), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL);  
				break;
			case MMS_RESPONSE_STATUS_VALUE_E_SERVICE_DENIED:
				mms_Tracer((char*)"服务被拒绝！");
				sendover = 1;
				cms_remove_memory_file();
				/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				DisplayPopup((U8*)GetString(STR_SEND_FAILED), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL); 
				
				break;
			case MMS_RESPONSE_STATUS_VALUE_E_FORMAT_CORRUPT:
				mms_Tracer((char*)"消息格式被损坏！");
				sendover = 1;
				cms_remove_memory_file();
				/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				DisplayPopup((U8*)GetString(STR_SEND_FAILED),IMG_GLOBAL_WARNING,  NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL); 
				break;
			case MMS_RESPONSE_STATUS_VALUE_E_ADDRESS_UNRESOLVED:
				mms_Tracer((char*)"接收人地址错误！");
				sendover = 1;
				cms_remove_memory_file();
				if (mms_file_manager_get_current_folder() == MMS_DRAFT_FOLDER)
				{			
					if(IsScreenPresent(SCR_ID_MMS_DRAFTBOX_OPTIONS))
					{
						GoBackToHistory(SCR_ID_MMS_DRAFTBOX_OPTIONS);
					}
					else
					{
						GoBackHistory();
					}
				}
				else
				{
					if(IsScreenPresent(SCR_ID_MMS_SEND_OPTIONS))
					{
						GoBackToHistory(SCR_ID_MMS_SEND_OPTIONS);
					}
					else
					{
						GoBackHistory();
					}
				}
				DisplayPopup((U8*)GetString(STR_ADDRESS_ERROR), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL); 
				
				break;
				
			case MMS_RESPONSE_STATUS_VALUE_E_MESSAGE_NOT_FOUND:
				mms_Tracer((char*)"消息未找到！");
				sendover = 1;
				cms_remove_memory_file();
				/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				DisplayPopup((U8*)GetString(STR_SEND_FAILED), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL);  
				
				break;
			case MMS_RESPONSE_STATUS_VALUE_E_NETWORK_PROBLEM:
				mms_Tracer((char*)"服务器过忙！");
				sendover = 1;
				cms_remove_memory_file();
				/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				DisplayPopup((U8*)GetString(STR_SEND_FAILED), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL);
				break;
			case MMS_RESPONSE_STATUS_VALUE_E_NOT_ACCEPTED:
				mms_Tracer((char*)"消息内容不可接受");
				sendover = 1;
				cms_remove_memory_file();
				/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				DisplayPopup((U8*)GetString(STR_SEND_FAILED), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL); 
				break;
			case MMS_RESPONSE_STATUS_VALUE_E_UNSUPORTED_MESSAGE:
				mms_Tracer((char*)"该消息不被服务器支持");
				sendover = 1;
				cms_remove_memory_file();
					/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				DisplayPopup((U8*)GetString(STR_SEND_FAILED), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL); 
				break;
			case MMS_RESPONSE_STATUS_VALUE_E_UNKNOW_ERROR:
				sendover = 1;
				mms_Tracer((char*)"发送失败,未知错误!");
				cms_remove_memory_file();
				/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				DisplayPopup((U8*)GetString(STR_SEND_FAILED), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL);
				break;
				
			/*发送时gprs网络拨号失败同样返回发送失败*/
			case MMSNETLINK_FAILED:
				sendover = 1;
				mms_Tracer((char*)"网络拨号失败!");
				cms_remove_memory_file();
				/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				DisplayPopup((U8*)GetString(STR_SEND_FAILED), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL);  
				break;
				
			/*发送时用户取消发送则返回发送取消*/
			case MMSOPR_CANCEL:
				mms_Tracer((char*)"用户取消发送");
				sendover = 1;
				if (pgManager->currentFolder == pgManager->sendFolder)
				{
					/*将发件箱中未发送成功的当前信息删除*/
					P_MESSAGELIST pMsg = pgManager->sendFolder->currentMessage;
					if (pMsg)
					{
						if (pMsg->state == 'N')
						{
							mms_file_manager_delete_message_from_box(pMsg, MMS_SEND_FOLDER);

						}
					}
				}
				cms_remove_memory_file();
				if (!mmsflag.gexit_toidle)
				{		
					GoBackHistory();
					DisplayPopup((U8*)GetString(STR_MMS_CANCLE_SUCESS),IMG_GLOBAL_ACTIVATED, NULL, 2000, SUCCESS_TONE);	
				}
				mmi_mms_post_message(CMS_MESSAGE_MMS_SEND_FAILED_UNKNOWN,NULL);  
				break;
			}
		}
		break;
	case  LIB_STATUS_RECVRETURN:
		{
			
			switch(status_value)
			{
			case MMSRECV_SUCCESS:
				progress_value=100;
				mmi_mms_show_send_receive_status(progress_value);
				//kal_prompt_trace(MOD_NVRAM,"###接收成功###");
				mms_Tracer((char*)"###接收成功###");
				sendover = 1;
				mmi_mms_post_message(CMS_MESSAGE_MMS_RECVD,NULL);
				break;
			case MMSRECV_FAILED:
				mms_Tracer((char*)"接收失败");
				sendover = 1;
				//kal_prompt_trace(MOD_NVRAM,"###接收失败###");
				mms_Tracer((char*)"###接收失败###");
				mmi_mms_post_message(CMS_MESSAGE_MMS_RECVD_FAILED,NULL);
				break;
			case MMSOPR_CANCEL:
				mms_Tracer((char*)"接收取消");
				{
					sendover = 1;
					if (!mmsflag.gexit_toidle)
					{
						GoBackHistory();
						DisplayPopup((U8*)GetString(STR_MMS_CANCLE_SUCESS),IMG_GLOBAL_ACTIVATED, NULL, 2000, SUCCESS_TONE);
					}
				}
				mmi_mms_post_message(CMS_MESSAGE_MMS_RECVD_FAILED,NULL);
				break;
			case MMSNETLINK_FAILED:
				mms_Tracer((char*)"gprs网络连接失败，接收失败");
				sendover = 1;
				/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				mmi_mms_post_message(CMS_MESSAGE_MMS_RECVD_FAILED,NULL);			
				break;
			case MMSRECV_FAILED_BY_NOT_FOUND:
				sendover = 1;
				/* if it's in send receive screen */
				if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
				{		
					GoBackHistory ();
				}
				else
				{	
					/* it's not in progressing screen, maybe in call or something else */
					DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
				}
				mms_Tracer((char*)"接收失败，该MMS未找到");
				mmi_mms_post_message(CMS_MESSAGE_MMS_RECVD_FAILED,NULL);
				break;
			}
		}
		break;
    case LIB_STATUS_SENDED_BYTES:		
		{
			mms_Tracer((char*)"发送的字节数");
			kal_prompt_trace(MOD_NVRAM, (kal_char *)"sended bytes = %d", (kal_char *)status_value);
			kal_prompt_trace(MOD_NVRAM, (kal_char *)"send_rec bytes = %d", (kal_char *)send_recmmssize);
			kal_prompt_trace(MOD_NVRAM, (kal_char *)"value bytes = %d", (kal_char *)progress_value);

			if(send_recmmssize!=0)
			{
				progress_value=(status_value*80)/send_recmmssize+20;
				mmi_mms_show_send_receive_status(progress_value);
			}
			mms_mmi_tracer("sended bytes = %d", (char*)status_value);			
		}                 
		break;
	case LIB_STATUS_RECVED_BYTES:
		{
			mms_Tracer((char*)"接收的字节数");
			kal_prompt_trace(MOD_NVRAM, (kal_char *)"receive bytes = %d", (kal_char *)status_value);
			kal_prompt_trace(MOD_NVRAM, (kal_char *)"send_recmmssize bytes = %d", (kal_char *)send_recmmssize);

			kal_prompt_trace(MOD_NVRAM, (kal_char *)"value bytes = %d", (kal_char *)progress_value);


			if(send_recmmssize!=0)
			{
				progress_value=(status_value*80)/send_recmmssize+20;
				mmi_mms_show_send_receive_status(progress_value);
			}
			mms_mmi_tracer("receive bytes = %d", (char*)status_value);			
		}                 
		break;
	}
	return 1;
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_send_message
 *       Purpose:  发送彩信
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_send_message(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	MYTIME					currTime;
	MMS_CONFIG_SETTING  	cfgset;
	MMS_SEND_SETTING    		sendset;
	P_MMS_DOCUMENT		pMms_Doc = NULL;
	P_MESSAGELIST			pMsg = NULL;
	pSENDTO_LIST			plist = NULL;
	U8*						to_list = NULL;
	U8*						cc_list = NULL;
	U8*						bcc_list = NULL;
	int						phone_list_len = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	memset(gedit.mms_fname, 0, MMS_MAX_FILE_NAME_LENGTH);
	mms_get_randstring(gedit.mms_fname);
	strcat(gedit.mms_fname, ".mms");

	mms_Tracer((char*)"start of send message");

	memset(&currTime,0,sizeof(MYTIME));	
	memset(&cfgset,0,sizeof(MMS_CONFIG_SETTING));
	memset(&sendset,0,sizeof(sendset));

	pMms_Doc = (P_MMS_DOCUMENT)cms_integrate_mms(gpeditor_doc);
	mms_Tracer((char*)"111111111111111111");
	if (!pMms_Doc)
	{
		mms_Tracer((char*)"error:pMms_Doc == NULL");
		mmsflag.gsend_recv = FALSE;
		GoBackHistory();
		return ;
	}
	if(!MMS_SetMmsFile(pMms_Doc,gedit.mms_fname))
	{
		mms_Tracer((char*)"error:MMS_SetMmsFile failed");
		if (pMms_Doc)
		{
			MMS_DeleteMms(pMms_Doc);
			pMms_Doc = NULL;
		}
		mmsflag.gsend_recv= FALSE;
		GoBackHistory();
		return;
	}
 	mms_mmi_tracer("size = %d",(char*)gpeditor_doc->totalsize);
	if (pgsendtolist)
	{
		/*TO*/
		plist = pgsendtolist;
		phone_list_len = cms_get_sendto_list_len(pgsendtolist)+1;
		to_list	   = (U8 *)mms_Malloc(phone_list_len);	
		memset(to_list,0,phone_list_len);	
		strcpy((char *)to_list, plist->number);	
		while (plist->next)
		{
			plist = plist->next;
			strcat((char *)to_list,",");
			strcat((char *)to_list, plist->number);
		}
	}
	if (pgsendcclist)
	{	
		/*CC*/
		plist = pgsendcclist;
		phone_list_len = cms_get_sendto_list_len(pgsendcclist)+1;
		cc_list	   = (U8 *)mms_Malloc(phone_list_len);	
		memset(cc_list,0,phone_list_len);	
		strcpy((char *)cc_list, plist->number);	
		while (plist->next)
		{
			plist = plist->next;
			strcat((char *)cc_list,",");
			strcat((char *)cc_list, plist->number);
		}
	}
	if (pgsendbcclist)
	{
		/*BCC*/
		plist = pgsendbcclist;
		phone_list_len = cms_get_sendto_list_len(pgsendbcclist)+1;
		bcc_list	   = (U8 *)mms_Malloc(phone_list_len);	
		memset(bcc_list,0,phone_list_len);	
		strcpy((char *)bcc_list, plist->number);	
		while (plist->next)
		{
			plist = plist->next;
			strcat((char *)bcc_list,",");
			strcat((char *)bcc_list, plist->number);
		}
	}

	mms_Tracer((char*)"2222222222222222");
	if (to_list)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_TO, (long)0, (char *)to_list);
	}
	if (cc_list)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_CC, (long)0, (char *)cc_list);
	}
	if (bcc_list)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_BCC, (long)0, (char *)bcc_list);
	}
	
	MMS_SetMmsHeadField(pMms_Doc, MMS_MESSAGE_CLASS, (long)MMS_MESSAGE_CLASS_TYPE_PERSONAL, (char *)0);

	if (gconfig.anonymous == MMS_SETTINGS_ON)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_SENDER_VISIBILITY,(long)MMS_SENDER_VISIBILITY_HIDE, (char *)0);
	}
	else
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_SENDER_VISIBILITY,(long)MMS_SENDER_VISIBILITY_SHOW, (char *)0);
	}
	if (gconfig.read_rpt== MMS_SETTINGS_ON)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_READ_REPLY,(long)MMS_READ_REPORT_YES, (char *)0);
	}
	else
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_READ_REPLY,(long)MMS_READ_REPORT_NO, (char *)0);
	}
	if (gconfig.prior == MMS_SETTINGS_PRIORITY_LOW)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_PRIORITY, (long)MMS_PRIORITY_VALUE_LOW, (char *)0);
	}
	else if (gconfig.prior == MMS_SETTINGS_PRIORITY_NORMAL)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_PRIORITY, (long)MMS_PRIORITY_VALUE_NORMAL, (char *)0);
	}
	else
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_PRIORITY, (long)MMS_PRIORITY_VALUE_HIGH, (char *)0);
	}
	if (gconfig.delivery_rpt == MMS_SETTINGS_ON)
	{
		mms_Tracer((char*)"start of MMS_DELIVERY_REPORT on");
		MMS_SetMmsHeadField(pMms_Doc, MMS_DELIVERY_REPORT, (long)MMS_DELIVERY_REPORT_YES, (char *)0);
	}
	else
	{
		mms_Tracer((char*)"start of MMS_DELIVERY_REPORT off");
		MMS_SetMmsHeadField(pMms_Doc, MMS_DELIVERY_REPORT, (long)MMS_DELIVERY_REPORT_NO, (char *)0);
	}
	if (gconfig.expires== MMS_SETTINGS_HOUR)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_EXPIRY, (long)1*3600, (char *)0);
	}
	else if(gconfig.expires== MMS_SETTINGS_DAY)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_EXPIRY, (long)24*3600, (char *)0);
	}
	else if(gconfig.expires== MMS_SETTINGS_WEEK)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_EXPIRY, (long)168*3600, (char *)0);
	}
	else if(gconfig.expires== MMS_SETTINGS_MAX)
	{
		MMS_SetMmsHeadField(pMms_Doc, MMS_EXPIRY, (long)168*3600, (char *)0);
	}
	
	if (gedit.sub_buf[0] == '\0' && gedit.sub_buf[1] == '\0')
	{
		mms_Tracer((char*)"gedit .sub_buf==NULL");
		pfnUnicodeStrcpy((S8 *)gedit.sub_buf,GetString(STR_NO_SUBJECT));	
	}
	MMS_SetMmsHeadField(pMms_Doc, MMS_SUBJECT, (long)0, (char*)gedit.sub_buf);
	mms_Tracer((char*)"start of MMS_EncodeMms");

	if(!MMS_EncodeMms(pMms_Doc))
	{
		mms_Tracer((char*)"error:MMS_EncodeMms failed");
		if (pMms_Doc)
		{
			MMS_DeleteMms(pMms_Doc);
			pMms_Doc = NULL;
		}
		if (to_list)
		{
			mms_Free(to_list);
			to_list = NULL;
		}
		if (cc_list)
		{
			mms_Free(cc_list);
			cc_list = NULL;
		}		
		if (bcc_list)
		{
			mms_Free(bcc_list);
			bcc_list = NULL;
		}
		mmsflag.gsend_recv = FALSE;
		mmsf_Remove(gedit.mms_fname);
		GoBackHistory();
		return ;
	}
	MMS_DeleteMms(pMms_Doc);
	pMms_Doc = NULL;
	mms_Tracer((char*)"333333333333333333");

	if(!cms_memory_to_flash(gedit.mms_fname))
	{
		mms_Tracer((char*)"memory to flash error................");
		if (to_list)
		{
			mms_Free(to_list);
			to_list = NULL;
		}
		if (cc_list)
		{
			mms_Free(cc_list);
			cc_list = NULL;
		}		
		if (bcc_list)
		{
			mms_Free(bcc_list);
			bcc_list = NULL;
		}
		mmsflag.gsend_recv = FALSE;
		mmsf_Remove(gedit.mms_fname);
		cms_remove_message_file_from_flash(gedit.mms_fname);
		mms_Tracer((char*)"memory to flash error...........remove.....");
		GoBackHistory();
		DisplayPopup((U8*)GetString(STR_MMS_FLASH_WRITE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	mms_Tracer((char*)"444444444444444444");
	/*保存至发件箱 */
	pMsg =mms_file_manager_new_message();
	if (!pMsg)
	{
		mms_Tracer((char*)"message node error!!!");
		if (to_list)
		{
			mms_Free(to_list);
			to_list = NULL;
		}
		if (cc_list)
		{
			mms_Free(cc_list);
			cc_list = NULL;
		}		
		if (bcc_list)
		{
			mms_Free(bcc_list);
			bcc_list = NULL;
		}
		mmsflag.gsend_recv = FALSE;
		GoBackHistory();
		return ;
	}	
	{
		char* sub = NULL;
	/*文件名*/
		strcpy(pMsg->fileName, gedit.mms_fname);
	/*时间*/
		CmsTime2String(pMsg->date);
	/*收件人*/
		if (to_list)
		{
			strcpy(pMsg->to_address, (const char *)to_list);
			mms_Free(to_list);
			to_list = NULL;
		}
		if (cc_list)
		{
			strcpy(pMsg->cc_address, (const char *)cc_list);
			mms_Free(cc_list);
			cc_list = NULL;
		}		
		if (bcc_list)
		{
			strcpy(pMsg->bcc_address, (const char *)bcc_list);		
			mms_Free(bcc_list);
			bcc_list = NULL;
		}
	/*主题*/
		if (gedit.sub_buf[0] == '\0' && gedit.sub_buf[1] == '\0')
		{
 			mms_Tracer((char*)"no subject");
			pfnUnicodeStrcpy((S8*)gedit.sub_buf, GetString(STR_NO_SUBJECT));
		}
		sub = Cms_mms_uni16_8((char*)gedit.sub_buf);				
		strcpy(pMsg->subject, sub);
		mms_Free(sub);
		sub = NULL;
		/*状态、大小*/
		pMsg->state = 'N';
		pMsg->size = (S32)gpeditor_doc->totalsize;
		send_recmmssize=(S32)gpeditor_doc->totalsize;
		{
			{
				mms_file_manager_add_message_to_folder(pMsg, MMS_SEND_FOLDER, SET_MESSAGE_CUR);			
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				/*保存至发件箱完毕*/
				mms_Tracer((char*)"MMS start net init\n");
				cms_flash_to_memory(gedit.mms_fname);
				
				cfgset.wap_gateway = (unsigned char *)Cms_mms_uni16_8((S8*)gconfig.gateway);
				cfgset.mms_centery = Cms_mms_uni16_8((S8*)gconfig.centre_addr);
				
				mms_Tracer((char*)"Sending..............................");
				{
					int	i = 0;
					U8 tempgateport[16] = {0};
					while (gconfig.port[i*2] != NULL)
					{
						tempgateport[i] = gconfig.port[i*2];
						i++;
					}
					cfgset.wap_port = Cms_Browser_atoi(tempgateport);
				}
				{
					if(!cfgset.wap_gateway||strlen((char *)cfgset.wap_gateway)==0)
					{
						mms_Tracer((char*)"the mms_gateway is NULL");
						mmsflag.gsend_recv = FALSE;
						mms_Free(cfgset.wap_gateway);
						cfgset.wap_gateway = NULL;
						mms_Free(cfgset.mms_centery);
						cfgset.mms_centery = NULL;
						GoBackHistory();
						DisplayPopup((U8*)GetString(STR_MMS_SETTING_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
						return;
					}
					if(cfgset.mms_centery==NULL||strlen(cfgset.mms_centery)==0)
					{
						mms_Tracer((char*)"the mms_centery is NULL");
						mmsflag.gsend_recv = FALSE;
						mms_Free(cfgset.wap_gateway);
						cfgset.wap_gateway = NULL;
						mms_Free(cfgset.mms_centery);
						cfgset.mms_centery = NULL;
						GoBackHistory();
						DisplayPopup((U8*)GetString(STR_MMS_SETTING_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
						return;
					}	
					if(!cfgset.wap_port)
					{
						mms_Tracer((char*)"the mms_port is NULL");
						mmsflag.gsend_recv = FALSE;
						mms_Free(cfgset.wap_gateway);
						cfgset.wap_gateway = NULL;
						mms_Free(cfgset.mms_centery);
						cfgset.mms_centery = NULL;
						GoBackHistory();
						DisplayPopup((U8*)GetString(STR_MMS_SETTING_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
						return;
					}					
				}	
				MMS_Init();
				/*有了MMS全局状态机后，就可以设置最大的发送接收MMS的大小了*/
				MMS_SetMaxSize(gconfig.sendsize, gconfig.retrievesize);

				if(!MMS_Machine_Config(&cfgset))
				{
					mms_Tracer((char*)"error:MMS_Machine_Config(&cfgset) failed");
					mmsflag.gsend_recv = FALSE;
					mms_Free(cfgset.wap_gateway);
					cfgset.wap_gateway = NULL;
					mms_Free(cfgset.mms_centery);
					cfgset.mms_centery = NULL;
					GoBackHistory();
					DisplayPopup((U8*)GetString(STR_MMS_SETTING_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
					return;
				}
				mms_Free(cfgset.wap_gateway);
				cfgset.wap_gateway = NULL;
				mms_Free(cfgset.mms_centery);
				cfgset.mms_centery = NULL;
				
				mms_Tracer((char*)"^_^:MMS_SendMms(&mms_lib_callback) ");

				sendset.send_vfilename = gedit.mms_fname;
				sendset.conf_vfilename = (char*)"confirm.mms";
				if(!MMS_SendMms(&sendset, mms_lib_callback))
				{
					mms_Tracer((char*)"MMS_SendMms fail");
					mmsflag.gsend_recv = FALSE;
					GoBackHistory();
					return;
				}
				mms_Tracer((char*)"end of send mms");
			}
		}
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_retrieve_message
 *       Purpose: 接收彩信
 *         Input: pMsg: 待接收彩信节点地址
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_retrieve_message(void *ptr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	MMS_RECV_SETTING 	recvset;
	MMS_CONFIG_SETTING cfgset;
	P_MESSAGELIST 		pMsg = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	pMsg=mms_file_manager_get_push_message();
	if (!pMsg->url)
	{
		mms_Tracer((char*)"cms_receive_message: the PUSH msg is wrong!!!");
		gauto_recmmssize = 0;
		mmsflag.gsend_recv = FALSE;
		GoBackHistory(); 
		DisplayPopup((U8*)GetString(STR_MMS_WRONG_NOTIFICATION), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	if (!mmsflag.gsend_recv)
	{
		mmsflag.gsend_recv = TRUE;
	}
	
	mms_Tracer((char*)"start of cms_receive_message");
	cfgset.wap_gateway = (unsigned char *)Cms_mms_uni16_8((S8*)gconfig.gateway);
	cfgset.mms_centery = Cms_mms_uni16_8((S8*)gconfig.centre_addr);
	{
		int	i = 0;
		U8 tempgateport[16] = {0};
		while (gconfig.port[i*2] != NULL)
		{
			tempgateport[i] = gconfig.port[i*2];
			i++;
		}
		cfgset.wap_port = Cms_Browser_atoi(tempgateport);
	}
	{
		if(!cfgset.wap_gateway||strlen((char *)cfgset.wap_gateway)==0)
		{
			mms_Tracer((char*)"the mms_gateway is NULL");
			mmsflag.gsend_recv = FALSE;
			mms_Free(cfgset.wap_gateway);
			cfgset.wap_gateway = NULL;
			mms_Free(cfgset.mms_centery);
			cfgset.mms_centery = NULL;
			gauto_recmmssize = 0;
			mmsflag.gmanual_recv= FALSE;
			GoBackHistory();
			DisplayPopup((U8*)GetString(STR_MMS_SETTING_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			return;
		}
		if(cfgset.mms_centery==NULL||strlen(cfgset.mms_centery)==0)
		{
			mms_Tracer((char*)"the mms_centery is NULL");
			mmsflag.gsend_recv = FALSE;
			mms_Free(cfgset.wap_gateway);
			cfgset.wap_gateway = NULL;
			mms_Free(cfgset.mms_centery);
			cfgset.mms_centery = NULL;
			gauto_recmmssize = 0;
			mmsflag.gmanual_recv= FALSE;
			GoBackHistory();
			DisplayPopup((U8*)GetString(STR_MMS_SETTING_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			return;
		}	
		if(!cfgset.wap_port)
		{
			mms_Tracer((char*)"the mms_port is NULL");
			mmsflag.gsend_recv = FALSE;
			mms_Free(cfgset.wap_gateway);
			cfgset.wap_gateway = NULL;
			mms_Free(cfgset.mms_centery);
			cfgset.mms_centery = NULL;
			gauto_recmmssize = 0;
			mmsflag.gmanual_recv = FALSE;
			GoBackHistory();
			DisplayPopup((U8*)GetString(STR_MMS_SETTING_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			return;
		}					
	}	
	if(MMS_Init() == 0)
	{
		mms_Tracer((char*)"call MMS_Init fail");
		mmsflag.gsend_recv = FALSE;
		gauto_recmmssize = 0;
		mmsflag.gmanual_recv = FALSE;
		return;
	}
	
	if(!MMS_Machine_Config(&cfgset))
	{
		mms_Tracer((char*)"error:MMS_Machine_Config(&cfgset) failed");
		mms_Free(cfgset.wap_gateway);
		cfgset.wap_gateway = NULL;
		mms_Free(cfgset.mms_centery);
		cfgset.mms_centery = NULL;
		mmsflag.gsend_recv = FALSE;
		gauto_recmmssize = 0;
		mmsflag.gmanual_recv= FALSE;
		GoBackHistory();
		DisplayPopup((U8*)GetString(STR_MMS_SETTING_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return;
	}
	mms_Free(cfgset.wap_gateway);
	cfgset.wap_gateway = NULL;
	mms_Free(cfgset.mms_centery);
	cfgset.mms_centery = NULL;
	recvset.immediate_recv = 1;
	recvset.get_url = pMsg->url;
	mms_mmi_tracer("pMsg->url = %s",(char*)pMsg->url);
	recvset.recv_vfilename = pMsg->fileName;
	mms_mmi_tracer("pMsg->fileName = %s",(char*)pMsg->fileName);
	recvset.recv_msgsize = pMsg->size;
	send_recmmssize=pMsg->size;
	mms_mmi_tracer("pMsg->size = %s",(char*)send_recmmssize);

	if(!MMS_ReceiveMms(&recvset,mms_lib_callback))
	{
		mms_Tracer((char*)"error:mms recv failed");
		mmsflag.gsend_recv = FALSE;
		gauto_recmmssize = 0;
		mmsflag.gmanual_recv = FALSE;
		GoBackHistory();
		return;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_cancel_send_retrieve
 *       Purpose: 取消发送、接收
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_cancel_send_retrieve()
{
	mmsflag.gsend_recv = FALSE;
	send_recmmssize=0;
	MMS_SendRecvCancel();

}
/* ----------------------------------------------------------------------------
 * Function Name: mms_recv_failed_handle_back
 *       Purpose: 彩信接收失败处理并返回（无提示对话框）
 *         Input:  ptr: 设为NULL即可
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_recv_failed_handle_back()
{
	MMS_Close();
	cms_remove_memory_file();
	
	pgManager->receiveFolder->pushMessage = NULL;
	mmsflag.gsend_recv = FALSE;
	
	if (!mmsflag.gmms_memory)
	{
		/*不在彩信界面*/
		mms_Tracer((char*)"###不在彩信界面###");
		destroy_mms_mem_file_info();
	}
	else
	{
		if(mmsflag.gmanual_recv)
		{
			mmsflag.gmanual_recv = FALSE;
			if(GetCurrScreenID() ==SCR_ID_SENDING_RETRIEVING_MESSAGE )
			{
				if(IsScreenPresent(SCR_ID_MMS_INBOX))
					GoBackToHistory(SCR_ID_MMS_INBOX);
				else
				{
					GoBackHistory();
				}
			}
			else
			{
				DeleteUptoScrID(SCR_ID_MMS_INBOX);	
				GoBackHistory();
			}	
		}	
	}
	send_recmmssize=0;
	gauto_recmmssize=0;				
	mmi_update_mms_idel_icon();
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_recv_failed
 *       Purpose: 彩信接收失败
 *         Input:  ptr: 设为NULL即可
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_recv_failed(void *ptr)
{
	mms_recv_failed_handle_back();
	DisplayPopup((U8*)GetString(STR_RETRIEVE_FAILED),IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_send_failed
 *       Purpose:  彩信发送失败，未知原因
 *         Input: ptr: 设为NULL即可
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_send_failed(void *ptr)
{
	MMS_Close();
	memset(gedit.mms_fname, 0, MMS_MAX_FILE_NAME_LENGTH);
	mmsflag.gsend_recv = FALSE;
	mmsflag.gsend_save = FALSE;
	send_recmmssize=0;
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_recvd_ok
 *       Purpose:  彩信接收完成
 *         Input: ptr: 设为NULL即可
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_recvd_ok()
{
	P_MESSAGELIST		pMsg = NULL, ptMsg = NULL;
	P_MMS_DOCUMENT	pdoc = NULL;
    	S8*					subject = NULL;
	char*				temp = NULL;

	mms_Tracer("enter cms_retrieve_ok");
	if (pgManager->receiveFolder->pushMessage)
	{
		ptMsg = pgManager->receiveFolder->pushMessage;
	}
	else
	{
		ptMsg =mms_file_manager_get_current_message();
	}
	pMsg = (P_MESSAGELIST)mms_Malloc(sizeof(MESSAGELIST));
	if (!pMsg)
	{
		mms_Tracer((char*)"fail to get current message node!!!");
		mms_recv_failed(NULL);
		return ;
	}
	memset(pMsg, 0, sizeof(MESSAGELIST));
	/* filename */
	pMsg->fileName = (S8*)mms_Malloc(MMS_MAX_FILE_NAME_LENGTH);
	if (!pMsg->fileName)
	{
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		mms_recv_failed(NULL);
		return ;
	}
	memset(pMsg->fileName, 0, MMS_MAX_FILE_NAME_LENGTH);
	strcpy(pMsg->fileName, ptMsg->fileName);
	pdoc = (MMSHANDLE)MMS_NewMms();
	if(!pdoc)
	{
		mms_Tracer((char*)"Receiving...fail to init decode!!!");
		mms_recv_failed(NULL);
		return ;
	}
	MMS_SetMmsFile(pdoc, pMsg->fileName);
	MMS_DecodeMms(pdoc);
	mms_mmi_tracer("pdoc->mms_totalsize:%d", (char*)pdoc->mms_totalsize);
	/* ADDRESS TO*/
	pMsg->to_address = (S8*)mms_Malloc(MMS_MAX_ADDRESS_LENGTH*10+20);//changed by wantao.liu 20060822
	if (!pMsg->to_address)
	{
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		MMS_DeleteMms(pdoc);
		pdoc = NULL;
		mms_recv_failed(NULL);
		return ;
	}
	memset(pMsg->to_address, 0, MMS_MAX_ADDRESS_LENGTH*10+20);
   	MMS_GetMmsHeadField(pdoc, MMS_FROM, 0, pMsg->to_address);
	/* ADDRESS CC */
	pMsg->cc_address = (S8*)mms_Malloc(MMS_MAX_ADDRESS_LENGTH*10+20);//changed by wantao.liu 20060822
	if (!pMsg->cc_address)
	{
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		MMS_DeleteMms(pdoc);
		pdoc = NULL;
		mms_recv_failed(NULL);
		return ;
	}
	memset(pMsg->cc_address, 0, MMS_MAX_ADDRESS_LENGTH*10+20);
   	MMS_GetMmsHeadField(pdoc, MMS_CC, 0, pMsg->cc_address);
	/* SUBJECT */
	subject = (S8*)mms_Malloc(MMS_MAX_SUBJECT_SIZE +2);
	if (!subject)
	{
		mms_Tracer((char*)"fail to allocate subject!!!");
		MMS_DeleteMms(pdoc);
		pdoc = NULL;
		mms_recv_failed(NULL);
		return ;
	}
	memset(subject, 0, MMS_MAX_SUBJECT_SIZE +2);
	mms_mmi_tracer("ready to call MMS_GetMmsHeadField", "");
    	MMS_GetMmsHeadField(pdoc, MMS_SUBJECT, 0, subject); 
	temp = Cms_mms_uni16_8(subject + 2);

	pMsg->subject = (S8*)mms_Malloc(MMS_MAX_UTF_SUBJECT_SIZE);
	if (!pMsg->subject)
	{
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		MMS_DeleteMms(pdoc);
		pdoc = NULL;
		mms_Free(subject);
		subject = NULL;
		mms_Free(temp);
		temp = NULL;
		mms_recv_failed(NULL);
		return ;
	}
	memset(pMsg->subject, 0, MMS_MAX_UTF_SUBJECT_SIZE);
	strcpy(pMsg->subject, temp);
	mms_Free(subject);
	subject = NULL;
	mms_Free(temp);
	temp = NULL;
	
	/* datetime */
	pMsg->date = (S8*)mms_Malloc(MMS_MAX_DATE_LEN);
	if (!pMsg->date)
	{
		mms_Tracer((char*)"fail to allocate date!!!");
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		MMS_DeleteMms(pdoc);
		pdoc = NULL;
		mms_recv_failed(NULL);
		return ;
	}
	memset(pMsg->date, 0, MMS_MAX_DATE_LEN);
	
	strcpy(pMsg->date, ptMsg->date);
	/* 状态、大小 */
	pMsg->state = 'N';
	mms_mmi_tracer("pdoc->mms_totalsize:%d", (char*)pdoc->mms_totalsize);

	pMsg->size = pdoc->mms_totalsize;
	mms_mmi_tracer("pMsg->size:%d", (char*)pMsg->size);

	MMS_DeleteMms(pdoc);
	pdoc = NULL;
	kal_prompt_trace(MOD_NVRAM,"###ready call cms_memory_to_flash###");
	if(!cms_memory_to_flash(pMsg->fileName))
	{
		mmsf_Remove(pMsg->fileName);
		mms_recv_failed_handle_back();
		DisplayPopup((U8*)GetString(STR_MMS_FLASH_WRITE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
		return ;
	}
	mms_file_manager_delete_message_from_box(ptMsg, MMS_RECEIVE_FOLDER);

	mms_file_manager_add_message_to_folder(pMsg, MMS_RECEIVE_FOLDER, SET_MESSAGE_NULL);
	#ifdef SUPPORT_MMS_IDLE_IND
	mmi_mms_get_new_msg_file_name(pMsg);
	#endif
	mms_file_manager_free_message(pMsg);
	pMsg = NULL;
	
	mms_Tracer((char*)"MMS Save finish");
	kal_prompt_trace(MOD_NVRAM,"###ready call MMS_Close###");
	MMS_Close();
	kal_prompt_trace(MOD_NVRAM,"###ready call cms_remove_memory_file###");
	cms_remove_memory_file();

	pgManager->receiveFolder->pushMessage = NULL;

	if (!mmsflag.gmms_memory)
	{
		/*不在彩信界面*/
		destroy_mms_mem_file_info();		
	}
	else
	{
		if((gconfig.retrieve_mode != MMS_SETTINGS_RETRIEVE_AUTO)||mmsflag.gmanual_recv)
		{	
			if(IsScreenPresent(SCR_ID_MMS_INBOX))
			{
				if(mmsflag.gmanual_recv)
				{
					mmsflag.gmanual_recv = FALSE;
				}
				GoBackToHistory(SCR_ID_MMS_INBOX);
			}
			else
			{
				mms_Tracer("not goback");
				//GoBackHistory();//chaozhu.zhou del for bug49983
			}
		}
		else
		{
			mms_Tracer("not goback");
		}		
	}
	gauto_recmmssize=0;
	send_recmmssize=0;
	mmsflag.gsend_recv = FALSE;

	mmi_update_mms_idel_icon();
	DisplayPopup((U8*)GetString(STR_RETRIEVE_OK),IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	kal_prompt_trace(MOD_NVRAM,"###end cms_retrieve_ok###");
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_send_ok
 *       Purpose:  彩信发送成功
 *         Input: ptr: 设为NULL即可
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_send_ok(void *ptr)
{
	MMS_Close();
	memset(gedit.mms_fname, 0, MMS_MAX_FILE_NAME_LENGTH);
	/* if it's in send receive screen */
	if (GetExitScrnID () == SCR_ID_SENDING_RETRIEVING_MESSAGE)
	{		
		GoBackHistory ();
	}
	else
	{	
		/* it's not in progressing screen, maybe in call or something else */
		DeleteScreenIfPresent (SCR_ID_SENDING_RETRIEVING_MESSAGE);
	}
	
	mmsflag.gsend_recv = FALSE;
	send_recmmssize=0;

	if(mmsflag.gsend_save==TRUE)
	{
		mmsflag.gsend_save=FALSE;
		mms_Tracer((char*)"STR_SEND_SAVE_OK");
		DisplayPopup((U8*)GetString(STR_SEND_SAVE_OK),IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	}	
	else
	{
		mms_Tracer((char*)"gsend_save is FALSE");
		DisplayPopup((U8*)GetString(STR_SEND_OK),IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	}	
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_notification_arrive
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_notification_arrive(void *ptr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 push_size = 0;
	char* temp = NULL;
	P_MESSAGELIST pMsg = NULL;
	NOTIFICATION_IND_SMS_MSG *msg = NULL;
	msg = (NOTIFICATION_IND_SMS_MSG *)ptr;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	pMsg = (P_MESSAGELIST)mms_Malloc(sizeof(MESSAGELIST));
	if (!pMsg)
	{
		mms_Tracer((char*)"fail to allocate pMsg!!!");
		return ;
	}
	memset(pMsg, 0, sizeof(MESSAGELIST));
	/* FILENAME */
	pMsg->fileName = (S8*)mms_Malloc(MMS_MAX_FILE_NAME_LENGTH);
	if (!pMsg->fileName)
	{
		mms_Tracer((char*)"fail to allocate filename!!!");
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		return ;
	}
	memset(pMsg->fileName, 0, MMS_MAX_FILE_NAME_LENGTH);
	mms_get_randstring(pMsg->fileName);
	strcat(pMsg->fileName,".mms");
	/* SUBJECT */
	if (msg->subject)
	{
		if (!(msg->subject[0] == 0 && msg->subject[1] == 0))
		{	
			/*有主题*/
			pMsg->subject = (S8*)mms_Malloc(MMS_MAX_UTF_SUBJECT_SIZE);
			if (!pMsg->subject)
			{
				mms_Tracer((char*)"fail to allocate subject!!!");
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				return ;
			}
			memset(pMsg->subject, 0, MMS_MAX_UTF_SUBJECT_SIZE);
			temp = Cms_mms_uni16_8(msg->subject + 2);
			strcpy(pMsg->subject, temp);
			mms_Free(temp);
			temp = NULL;
		}
	}
	/* ADDRESS */
	if (msg->phone_number)
	{
		
		if (msg->phone_number[0] != 0) 
		{
			mms_Tracer((char*)"****get the form phone_number****");
			pMsg->to_address = (S8*)mms_Malloc(MMS_MAX_ADDRESS_LENGTH);
			if (!pMsg->to_address)
			{
				mms_Tracer((char*)"fail to allocate address!!!");
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				return ;
			}
			memset(pMsg->to_address, 0, MMS_MAX_ADDRESS_LENGTH);			
			strcpy(pMsg->to_address, msg->phone_number);
		}
 	}
	/* URL */
	pMsg->url = (S8*)mms_Malloc(MAX_URL_LENGTH);
	if (!pMsg->url)
	{
		mms_Tracer((char*)"fail to allocate url!!!");
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		return ;
	}
	memset(pMsg->url, 0, MAX_URL_LENGTH);
	if (msg->mms_url) 
	{
		strcpy(pMsg->url, msg->mms_url);
	}
	/* DATE */
	pMsg->date = (S8*)mms_Malloc(MMS_MAX_DATE_LEN);
	if (!pMsg->date)
	{
		mms_Tracer((char*)"Receiving...fail to allocate date!!!");
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		return ;
	}
	memset(pMsg->date, 0, MMS_MAX_DATE_LEN);
	CmsTime2String(pMsg->date);

	/* STATE */
	pMsg->state = 'U';
	pMsg->size = (S32)msg->msgsize;
	
	push_size = pMsg->size;
	/*EXPRIY*/
	mms_mmi_tracer("mms_notification_arrive: msg->expriy_time = %d", msg->expriy_time);
	if(msg->expriy_time<=168)
	{
		pMsg->expriy_time=(S32)msg->expriy_time;
	}
	else
	{
		if((msg->expriy_time%3600)>1800)
		{
			pMsg->expriy_time=(int)(msg->expriy_time/3600)+1;
		}
		else
		{
			pMsg->expriy_time=(int)(msg->expriy_time/3600);
		}
	}
	mms_mmi_tracer("mms_notification_arrive: msg->expriy_time = %d", msg->expriy_time);
	
	DisplayPopup((U8*)GetString(STR_MESSAGE_ARRIVED), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	mmi_mms_new_msg_ind();
	
	mms_judge_receive_push_del_msg();
	
	if (!mmsflag.gsend_recv && gconfig.retrieve_mode == MMS_SETTINGS_RETRIEVE_AUTO &&!browserflag )
	{
		/*满足自动接受条件*/	
		gauto_recmmssize=pMsg->size;
		mms_mmi_tracer("auto recv gauto_recmmssize=%d",(char*) gauto_recmmssize);
		mms_file_manager_add_message_to_folder(pMsg, MMS_RECEIVE_FOLDER, SET_MESSAGE_PUSH);
		if( !mms_judge_mms_box_size_count(pMsg))
		{
			mms_file_manager_free_message(pMsg);
			pMsg = NULL;
			gauto_recmmssize=0;
			return;
		}		
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		mmi_update_mms_idel_icon();
		mms_Tracer((char*)"auto retrieve!!!");
		mmi_mms_post_message(CMS_MESSAGE_MMS_RECEIVE_MESSAGE, NULL);
	}
	else
	{
		mms_file_manager_add_message_to_folder(pMsg, MMS_RECEIVE_FOLDER, SET_MESSAGE_NULL);
		#ifdef SUPPORT_MMS_IDLE_IND
		mmi_mms_get_new_msg_file_name(pMsg);
		#endif
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;	
		mmi_update_mms_idel_icon();
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: sms_handle_callback
 *       Purpose:  判断当前是否能再收push 消息，不能则要删除一条
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_judge_receive_push_del_msg()
{
	U16 count = 0;
	S32 msize = 0;
	P_MESSAGELIST pMsg_del=NULL,pMsg_tmp=NULL,pMsg_Cur=NULL;

	pMsg_Cur=mms_file_manager_get_current_message();
	mms_get_all_boxes_count_size(&count, &msize);
	
	while (count>=MAX_MESSAGE_COUNT)
	{
		/*draftbox*/
		if(pgManager->draftFolder->messageNumber>0)
		{	
			pMsg_tmp=pgManager->draftFolder->root;
			while(pMsg_tmp!=NULL)
			{	
				if((pMsg_tmp->fileName!=NULL)&&(pMsg_Cur!=pMsg_tmp))
				{
					pMsg_del=pMsg_tmp;
				}	
				pMsg_tmp=pMsg_tmp->next;			
			}
			
			if(pMsg_del!=NULL)
			{
				mms_file_manager_delete_message_from_box(pMsg_del, MMS_DRAFT_FOLDER);
				count=count-1;
				return;
			}
		}
		/*sendbox*/
		if(pgManager->sendFolder->messageNumber>0)
		{
			pMsg_tmp=pgManager->sendFolder->root;
			while(pMsg_tmp!=NULL)
			{
				if((pMsg_tmp->fileName!=NULL)&&(pMsg_Cur!=pMsg_tmp)&&(pMsg_tmp!=pgManager->sendFolder->currentMessage))
				{
					pMsg_del=pMsg_tmp;
					if(pCurFwrReMsg==pMsg_tmp)
					{
						pMsg_del=NULL;
					}
				}
				pMsg_tmp=pMsg_tmp->next;
			}
			if(pMsg_del!=NULL)
			{
				mms_file_manager_delete_message_from_box(pMsg_del, MMS_SEND_FOLDER);
				count=count-1;
				return;
			}
		}
		/*inbox*/
		if(pgManager->receiveFolder->messageNumber>0)
		{
			pMsg_tmp=pgManager->receiveFolder->root;
			while(pMsg_tmp!=NULL)
			{
				if((pMsg_tmp->fileName!=NULL)&&(pMsg_Cur!=pMsg_tmp))
				{
					pMsg_del=pMsg_tmp;
				}
				pMsg_tmp=pMsg_tmp->next;
			}

			if(pMsg_del!=NULL)
			{
				mms_file_manager_delete_message_from_box(pMsg_del, MMS_RECEIVE_FOLDER);
				count=count-1;
				return;
			}
		}
	}

}
/* ----------------------------------------------------------------------------
 * Function Name: sms_handle_callback
 *       Purpose: 短消息处理回调函数(发送报告、彩信通知) 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int sms_handle_callback(int status,void *prompt,int status_value)
{
	NOTIFICATION_IND_SMS_MSG *msg = NULL;
	switch(status)
	{
	case SMS_TYPE_DELIVERY_IND:

		msg = (NOTIFICATION_IND_SMS_MSG *)prompt;
		mms_Tracer((char*)"^_^recved the delivery report!^_^");
		mms_mmi_tracer("the msg type is:%d",(char*)msg->de_status );

		{
			char* str = NULL;
			PS8  name;
			
			if (mmsflag.gplay_state)
			{
				mmi_mms_stop_play_message();
			}
			if (mmsflag.gsend_recv)
			{
				mms_Tracer((char*)"network is busy!\n");
				return 1;
			}
			{
				str = Cms_mms_uni8_16(msg->de_to);
				if (str)
				{
					S8  temp[256] = {0};
					/*根据电话号码查找用户名 */
					name = lookUpNumber((PS8)str);
					if (name  &&  pfnUnicodeStrlen(name))
					{
						mms_Tracer((char*)"find name!\n");
						if(pfnUnicodeStrlen(name)>11)
						{
							pfnUnicodeStrncpy((S8*)temp, (S8*)name,8);
							pfnUnicodeStrcat((S8*)temp, (PS8)L"...");
						}
						else
						{
							pfnUnicodeStrcpy((S8*)temp, (S8*)name);	
						}
					}
					else
					{
						mms_Tracer((char*)"do not find name!\n");
						if(pfnUnicodeStrlen(str)>11)
						{
							pfnUnicodeStrncpy((S8*)temp, (S8*)str,8);
							pfnUnicodeStrcat((S8*)temp, (PS8)L"...");
						}
						else
						{
							pfnUnicodeStrcpy((S8*)temp, (S8*)str);	
						}
					}
					pfnUnicodeStrcat((S8*)temp, (PS8)L" ");
					/*根据消息类型拷贝不同字串 */
					if(msg->de_status == MMS_STATUS_VALUE_RETRIVED)
					{
						mms_Tracer((char*)"MMS_STATUS_VALUE_RETRIVED\n");
						pfnUnicodeStrcat((S8*)temp, (const S8*)GetString(STR_RETRIEVED_MMS));
						/* 弹出对话框提示用户接收方已接收彩信*/
						DisplayConfirm(NULL, NULL,STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (UI_string_type)temp, IMG_GLOBAL_ACTIVATED, WARNING_TONE);
					}
					else if(msg->de_status == MMS_STATUS_VALUE_EXPIRED)
					{
						mms_Tracer((char*)"MMS_STATUS_VALUE_EXPIRED\n");
						pfnUnicodeStrcat((S8*)temp, (const S8*)GetString(STR_EXPIRED_MMS));
						/* 弹出对话框提示用户彩信已过期*/
						DisplayConfirm(NULL, NULL,STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (UI_string_type)temp, IMG_GLOBAL_WARNING, WARNING_TONE);
					}
					else if(msg->de_status == MMS_STATUS_VALUE_REJECTED)
					{
						mms_Tracer((char*)"MMS_STATUS_VALUE_REJECTED\n");					
						pfnUnicodeStrcat((S8*)temp, (const S8*)GetString(STR_REJECTED_MMS));
						/* 弹出对话框提示用户接收方拒绝接收*/
						DisplayConfirm(NULL, NULL,STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (UI_string_type)temp, IMG_GLOBAL_WARNING, WARNING_TONE);
					}
					else
					{
						mms_Tracer((char*)"unknown msg type!\n");
						mms_Free(str);
						str = NULL;
						return 1;
					}
					mms_Free(str);
					str = NULL;
					SetRightSoftkeyFunction(mmi_mms_exit_to_history, KEY_EVENT_UP);
				}
			}
		}		
	
		break;
	case SMS_TYPE_NOTIFICATION_IND:

		msg = (NOTIFICATION_IND_SMS_MSG *)prompt;
		mms_Tracer((char*)"callback:SMS_TYPE_NOTIFICATION_IND");
		mms_notification_arrive((void *)msg);
		
		break;
	case SMS_TYPE_UNKNOW:
		break;
	}
	return 1;
}
/***************************************************************************** 
* 以下是为保证编译通过新增加的接口
*****************************************************************************/
/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_cms_mms_phb_callback(S8* name, S8* number) 
{
}

/*彩信看门狗 */
void mms_watchdog(void)
{

}

/***************************************************************************** 
* 收件人列表接口
*****************************************************************************/
/* ----------------------------------------------------------------------------
 * Function Name: mms_add_phone_email_to_sendto_list
 *       Purpose: 增加号码和电邮到列表中去，并判断是否重复
 *			   再进入收件人列表窗口(TO/CC/BCC)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_add_phone_email_to_sendto_list(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	pSENDTO_LIST 	plist = NULL;
	U16			 	count = 0;
	int			 	flag = 0;
	char				ansiiTempBuff[MMS_MAX_INPUT_SEND_TO_SIZE];

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	plist = (pSENDTO_LIST)mms_Malloc(sizeof(SENDTO_LIST));
	
	if (!plist)
	{
		mms_Tracer((char*)"Sendto list: fail to allocate phone list!!!");
		return;
	}
	memset(plist, 0, sizeof(SENDTO_LIST));
	
	plist->number = (S8*)mms_Malloc(MMS_MAX_INPUT_SEND_TO_SIZE);
	
	if (!plist->number)
	{
		mms_Tracer((char*)"malloc plist: fail to allocate number!!!");
		mms_Free(plist);
		plist = NULL;
		return;
	}
	memset(plist->number, 0, MMS_MAX_INPUT_SEND_TO_SIZE);
	UnicodeToAnsii((S8*)ansiiTempBuff,(S8*)gedit.phone_buf);
	strcpy(plist->number,ansiiTempBuff);
	
       switch (gsendto_options)
       {
       case SENDTO_TO:	
	         count = get_sendtolist_count(pgsendtolist);

		   if(pgsendtolist ==NULL)
	         {
	       	pgsendtolist = plist;
			pgsendtolist->next = NULL;
	              mms_mmi_tracer("To->number is %s",pgsendtolist->number);
		   }   
		  else 
		  {
			pSENDTO_LIST pTemp1 = NULL,pTemp2 = NULL;
	            
			mms_Tracer((char*)"5555555551111111TO");

			pTemp1 = pgsendtolist;
			pTemp2 = pTemp2;
			while (pTemp1)	/*找到末节点*/
			{
				if(strcmp(pTemp1->number,plist->number) == 0)
				{
	                          	DisplayPopup((U8*)GetString(STR_MMS_NUMBER_REPEAT), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
	                          	mms_Free(plist);
				      	plist = NULL;
					return;  

				}
	                    else
	                    {
	                          	pTemp2 = pTemp1;
					pTemp1 = pTemp1->next;		  
				}

			}
			pTemp2->next = plist;
			flag = 1;
		 }
        	break;
	 case SENDTO_CC:
               count = get_sendtolist_count(pgsendcclist);
	        if(pgsendcclist ==NULL)
               {
       	       pgsendcclist = plist;
		       pgsendcclist->next = NULL;
               }
	   
	         else 
	         {
		        pSENDTO_LIST pTemp1 = NULL,pTemp2 = NULL;
            
		mms_Tracer((char*)"5555555551111111TO");

		pTemp1 = pgsendcclist;
		pTemp2 = pTemp2;
		while (pTemp1)
		{
			if(strcmp(pTemp1->number,plist->number) == 0)
			{
                          	DisplayPopup((U8*)GetString(STR_MMS_NUMBER_REPEAT), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
                          	mms_Free(plist);
			     	plist = NULL;
				return;  

			}
                    else
                    {
                          	pTemp2 = pTemp1;
				pTemp1 = pTemp1->next;		  
			}

		}
		pTemp2->next = plist;
		flag = 1;
	       }

             break;
	 case SENDTO_BCC:
	 	  count = get_sendtolist_count(pgsendbcclist);
		  if(pgsendbcclist ==NULL)
               {
       	       pgsendbcclist = plist;
		       pgsendbcclist->next = NULL;
               }
	   
	         else 
	         {
		       pSENDTO_LIST pTemp1 = NULL,pTemp2 = NULL;
       		mms_Tracer((char*)"5555555551111111TO");
       
       		pTemp1 = pgsendbcclist;
       		pTemp2 = pTemp2;
       		while (pTemp1)
       		{
       			if(strcmp(pTemp1->number,plist->number) == 0)
       			{
                                 	DisplayPopup((U8*)GetString(STR_MMS_NUMBER_REPEAT), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
                                 	mms_Free(plist);
       			      	plist = NULL;
       				return;  
       
       			}
                           else
                           {
                                 	pTemp2 = pTemp1;
       				pTemp1 = pTemp1->next;		  
       			}
       
       		}
       		pTemp2->next = plist;
       		flag = 1;
	      }

                break;
            default:
			break;
	   }
	count++;
	mms_mmi_tracer("count = %d",(char*)count);
	ghiliindex = count - 1;
   
	memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
	if (flag == 0)
	{
             mms_mmi_tracer("Flag = %d",flag);
		mmi_mms_entry_sendto_list();
	}
	else
	{		
		if(IsScreenPresent(SCR_ID_MMS_SEND_TO_LIST))
		{
			GoBackToHistory(SCR_ID_MMS_SEND_TO_LIST);
		}
		else
		{
			GoBackHistory();
		}
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_amend_sendto_address_confirm
 *       Purpose: 修改收件人地址确认，并返回到收件人列表(to/cc/bcc)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_amend_sendto_address_confirm(void)
{
	int 				i = 0;
	char				ansiiTempBuff[MMS_MAX_INPUT_SEND_TO_SIZE];
	pSENDTO_LIST 	plist = NULL,pTemp1=NULL;

	switch (gsendto_options)
      	{
	   case SENDTO_TO:
	   	plist = pgsendtolist;
             	pTemp1 = pgsendtolist;
		while (i < ghiliindex)
       	{
       		plist = plist->next;
       		i++;
       	}
		UnicodeToAnsii((S8*)ansiiTempBuff,(S8*)gedit.phone_buf);
		memset(plist->number, 0, MMS_MAX_INPUT_SEND_TO_SIZE);
             while(pTemp1)
             	{
             	   	if(strcmp(pTemp1->number,ansiiTempBuff)==0)
             	   	{
				DisplayPopup((U8*)GetString(STR_MMS_NUMBER_REPEAT), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			 	pTemp1 = NULL;
                    		return;
             	   	}
		   	else
		   	{
		     		pTemp1 = pTemp1->next;
		   	}
             	}      	
		strcpy(plist->number, ansiiTempBuff);
       	memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
		if(IsScreenPresent(SCR_ID_MMS_SEND_TO_LIST))
		{
			GoBackToHistory(SCR_ID_MMS_SEND_TO_LIST);
		}
		else
		{
			GoBackHistory();
		}
              break;
			  
	  case SENDTO_CC:
		plist = pgsendcclist;
             	pTemp1 = pgsendcclist;
		while (i < ghiliindex)
       	{
       		plist = plist->next;
       		i++;
       	}
		UnicodeToAnsii((S8*)ansiiTempBuff,(S8*)gedit.phone_buf);
       	memset(plist->number, 0, MMS_MAX_INPUT_SEND_TO_SIZE);
             	while(pTemp1)
             	{
			if(strcmp(pTemp1->number,ansiiTempBuff)==0)
			{
				DisplayPopup((U8*)GetString(STR_MMS_NUMBER_REPEAT), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				pTemp1 = NULL;
				return;
	             	   }
			   else
			   {
			      	pTemp1 = pTemp1->next;
			   }
             	}
		strcpy(plist->number, ansiiTempBuff);
       	memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
 		if(IsScreenPresent(SCR_ID_MMS_SEND_TO_LIST))
		{
			GoBackToHistory(SCR_ID_MMS_SEND_TO_LIST);
		}
		else
		{
			GoBackHistory();
		}
              break;
			  
	  case SENDTO_BCC:
	  	plist = pgsendbcclist;
             	pTemp1 = pgsendbcclist;
		while (i < ghiliindex)
       	{
       		plist = plist->next;
       		i++;
       	}
		UnicodeToAnsii((S8*)ansiiTempBuff,(S8*)gedit.phone_buf);
       	memset(plist->number, 0, MMS_MAX_INPUT_SEND_TO_SIZE);
             	while(pTemp1)
             	{
             	   	if(strcmp(pTemp1->number,ansiiTempBuff)==0)
             	   	{
             	       	DisplayPopup((U8*)GetString(STR_MMS_NUMBER_REPEAT), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			 	pTemp1 = NULL;
                     	return;
             	   	}
		   	else
		   	{
		      		pTemp1 = pTemp1->next;
		   	}
             	}
		strcpy(plist->number, ansiiTempBuff);
       	memset(gedit.phone_buf, 0, MMS_MAX_SEND_TO_SIZE);
		if(IsScreenPresent(SCR_ID_MMS_SEND_TO_LIST))
		{
			GoBackToHistory(SCR_ID_MMS_SEND_TO_LIST);
		}
		else
		{
			GoBackHistory();
		}
	       break;
	  }
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_remove_from_sendto_list_confirm
 *       Purpose: 移去收件人确认，返回到相应的screen，
 *			  无收件人时到编辑界面，有时到列表
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_remove_from_sendto_list_confirm(void)
{
	int 				i = 0;
	U16    			count = 0;
	pSENDTO_LIST 	plist = NULL, ptemp = NULL;
	
        switch (gsendto_options)
      	{
             case SENDTO_TO:
       		ptemp = pgsendtolist;
              	plist =pgsendtolist;
              	mms_mmi_tracer("ghiliindex = %d",(char*)ghiliindex);
				
              	for (; i < ghiliindex; i++)
              	{
              		if (i == ghiliindex - 1)
              		{
              			ptemp = plist; /*若删除节点非根节点，则获取前一节点*/
              		}
              		plist = plist->next;
              	} 
              
              	if (plist == pgsendtolist) /*待删除的为根节点*/
              	{
              		mms_Tracer((char*)"111111111111");
              		ptemp = plist->next;
               		cms_free_sendto_node(pgsendtolist);
               		mms_Free(pgsendtolist);
               		pgsendtolist = NULL;
               
               		if(ptemp)
               		{
               			pgsendtolist = ptemp;
               		}
               
              	}
              	else
              	{
              	    	mms_Tracer((char*)"22222222222");
              		ptemp->next = plist->next; 	/*将前一节点的next设为后一节点*/
              		cms_free_sendto_node(plist);
              		mms_Free(plist);
              		plist = NULL;
              	}
                    count = get_sendtolist_count(pgsendtolist);
       		break;
		case SENDTO_CC:
			ptemp = pgsendcclist;
              	plist =pgsendcclist;
              	mms_mmi_tracer("ghiliindex = %d",(char*)ghiliindex);
              	for (; i < ghiliindex; i++)
              	{
              		if (i == ghiliindex - 1)
              		{
              			ptemp = plist; 
              		}
              		plist = plist->next;
              	} 
              
              	if (plist == pgsendcclist) 
              	{
              		mms_Tracer((char*)"111111111111");
              		ptemp = plist->next;
       			cms_free_sendto_node(pgsendcclist);
       			mms_Free(pgsendcclist);
       			pgsendcclist = NULL;
       
	       		if(ptemp)
	       		{
	       			pgsendcclist= ptemp;
	       		}
              	}
              	else
              	{
              	    	mms_Tracer((char*)"22222222222");
              		ptemp->next = plist->next; 
              		cms_free_sendto_node(plist);
              		mms_Free(plist);
              		plist = NULL;
              	}
              	count = get_sendtolist_count(pgsendcclist);		
       		break;
			
		case SENDTO_BCC:
			ptemp = pgsendbcclist;
              	plist =pgsendbcclist;
             		mms_mmi_tracer("ghiliindex = %d",(char*)ghiliindex);
              	for (; i < ghiliindex; i++)
              	{
              		if (i == ghiliindex - 1)
              		{
              			ptemp = plist;
              		}
              		plist = plist->next;
              	} 
              
              	if (plist == pgsendbcclist) 
              	{
              		mms_Tracer((char*)"111111111111");
              		ptemp = plist->next;
	       		cms_free_sendto_node(pgsendbcclist);
	       		mms_Free(pgsendbcclist);
	       		pgsendbcclist = NULL;

	       		if(ptemp)
	       		{
	       			pgsendbcclist = ptemp;
	       		}
              	}
              	else
              	{
              	    	mms_Tracer((char*)"22222222222");
              		ptemp->next = plist->next;
              		cms_free_sendto_node(plist);
              		mms_Free(plist);
              		plist = NULL;
              	}
                     count = get_sendtolist_count(pgsendbcclist);
       		break;
			
      	}
	if(count != 0)
	{
		ghiliindex = (ghiliindex >= count) ? (count-1) : ghiliindex;
	}
	else
	{
		ghiliindex = 0;
	}
	mms_mmi_tracer("ghiliindex = %d",(char*)ghiliindex);	
	ExitDisplayPopupConfirm();
	if ((int)count <= 0)
	{
		if (mmsflag.gnew_message)	/*若为新建信息*/
		{
			if(IsScreenPresent(SCR_ID_MMS_WMESSAGE_MENU))
			{
				GoBackToHistory(SCR_ID_MMS_WMESSAGE_MENU);
			}
			else
			{
				GoBackHistory();
			}
		}
		else	/*若为转发、回复、修改信息*/
		{
			if(IsScreenPresent(SCR_ID_MMS_EDIT_MESSAGE))
			{
				GoBackToHistory(SCR_ID_MMS_EDIT_MESSAGE);
			}
			else
			{
				GoBackHistory();
			}
		}
	}
	else
	{
		if(IsScreenPresent(SCR_ID_MMS_SEND_TO_LIST))
		{
			GoBackToHistory(SCR_ID_MMS_SEND_TO_LIST);
		}
		else
		{
			GoBackHistory();
		}
	}
	DisplayPopup((U8*)GetString(STR_REMOVE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);

}
/* ----------------------------------------------------------------------------
 * Function Name: mms_remove_all_from_sendto_list_confirm
 *       Purpose: 移去所有收件人确认，并返回到编辑界面 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_remove_all_from_sendto_list_confirm(void)
{    
	pSENDTO_LIST plist = NULL;
     	pSENDTO_LIST ptemp = NULL;
		
    	switch (gsendto_options)
    	{
	 case SENDTO_TO:
       	plist = pgsendtolist;
        	pgsendtolist = NULL;
	 	break;
     	case SENDTO_CC:
	 	plist = pgsendcclist;
        	pgsendcclist = NULL;
	 	break;
     	case SENDTO_BCC:
	 	plist = pgsendbcclist;
        	pgsendbcclist = NULL;
	 	break;
    	} 
	while (plist)
	{
		ptemp = plist->next;
		cms_free_sendto_node(plist);
		mms_Free(plist);
		plist = ptemp;
	}
       plist = NULL;
       ptemp = NULL;
	   
	ghiliindex = 0;
	ExitDisplayPopupConfirm();
	if (mmsflag.gnew_message)
	{
		if(IsScreenPresent(SCR_ID_MMS_WMESSAGE_MENU))
		{
			GoBackToHistory(SCR_ID_MMS_WMESSAGE_MENU);
		}
		else
		{
			GoBackHistory();
		}
	}
	else	
	{
		if(IsScreenPresent(SCR_ID_MMS_EDIT_MESSAGE))
		{
			GoBackToHistory(SCR_ID_MMS_EDIT_MESSAGE);
		}
		else
		{
			GoBackHistory();
		}
	}
	DisplayPopup((U8*)GetString(STR_REMOVE_OK), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);

}
/* ----------------------------------------------------------------------------
 * Function Name: cms_empty_sendto_list
 *       Purpose: 清空列表plist。
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_empty_sendto_list(void)
{
	cms_empty_sendto_to_list();
	cms_empty_sendto_cc_list();
	cms_empty_sendto_bcc_list();	
}

/* ----------------------------------------------------------------------------
 * Function Name: cms_empty_sendto_to_list
 *       Purpose: 清空列表plist。
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_empty_sendto_to_list(void)
{
	pSENDTO_LIST plist = NULL;
	pSENDTO_LIST ptemp = NULL;
	
	/*--release to--*/
	if (!pgsendtolist)
	{
		mms_Tracer("the to sendto list is already null!!!!");
		//return;
	}
       plist = pgsendtolist;
	while (plist)
	{
		ptemp = plist->next;
		cms_free_sendto_node(plist);
		mms_Free(plist);
		plist = ptemp;
	}
       plist = NULL;
       ptemp = NULL;	   
}

/* ----------------------------------------------------------------------------
 * Function Name: cms_empty_sendto_cc_list
 *       Purpose: 清空列表plist。
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_empty_sendto_cc_list(void)
{
	pSENDTO_LIST plist = NULL;
	pSENDTO_LIST ptemp = NULL;
	
	/*--release to--*/
	if (!pgsendcclist)
	{
		mms_Tracer("the to sendto list is already null!!!!");
	}
       plist = pgsendcclist;
	while (plist)
	{
		ptemp = plist->next;
		cms_free_sendto_node(plist);
		mms_Free(plist);
		plist = ptemp;
	}
       plist = NULL;
       ptemp = NULL;	   
}

/* ----------------------------------------------------------------------------
 * Function Name: cms_empty_sendto_bcc_list
 *       Purpose: 清空列表plist。
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_empty_sendto_bcc_list(void)
{
	pSENDTO_LIST plist = NULL;
	pSENDTO_LIST ptemp = NULL;
	
	/*--release to--*/
	if (!pgsendbcclist)
	{
		mms_Tracer("the to sendto list is already null!!!!");
	}
       plist = pgsendbcclist;
	while (plist)
	{
		ptemp = plist->next;
		cms_free_sendto_node(plist);
		mms_Free(plist);
		plist = ptemp;
	}
       plist = NULL;
       ptemp = NULL;	   
}

/* ----------------------------------------------------------------------------
 * Function Name: cms_free_sendto_node
 *       Purpose: 释放列表结点
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_free_sendto_node(pSENDTO_LIST plist)
{
	if (plist->number)
	{
		mms_Free(plist->number);
		plist->number = NULL;
	}
	plist->next = NULL;
	mms_Tracer((char*)"cms_free_sendto_node");
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_get_sendtolist_count
 *       Purpose: 得到收件人的个数(有多少个人)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
U16 cms_get_sendtolist_count(set_to flag)
{
	pSENDTO_LIST 	plist = NULL;
	pSENDTO_LIST 	ptemp = NULL;
	U16			 	count = 0;
	switch(flag)
	{
	case SENDTO_TO:
		plist=pgsendtolist;
		break;
	case SENDTO_CC:
		plist=pgsendcclist;
		break;
	case SENDTO_BCC:
		plist=pgsendbcclist;
		break;
	}
       if( plist != NULL)
	{
		for (ptemp = plist; ptemp; ptemp = ptemp->next)
		{
			count++;
		}
	}
	else
	{
		mms_Tracer((char*)"cms_get_sendtolist_count:pgsendtolist = NULL");
	}
	return count;
}

/* ----------------------------------------------------------------------------
 * Function Name: get_sendtolist_count
 *       Purpose:  获取收件人地址计数
 *         Input: addr
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
U16 get_sendtolist_count(pSENDTO_LIST addr)
{
       U16 count = 0;
        while(addr != NULL)
       {
             count++;
	       addr = addr->next;
       }
       return count; 
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_get_sendto_list_len
 *       Purpose: 得到收件人的长度(有多少个字节)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int cms_get_sendto_list_len(pSENDTO_LIST addr)
{
	int          			len = 0;
	pSENDTO_LIST plist = NULL;

       plist = addr;
	while(plist)
	 {
		 len += strlen(plist->number) + 1;
		  plist = plist->next;
	  }
 	return len;
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_parse_sendto_address
 *       Purpose: 解析mms 文件得到收件人(TO/CC/BCC)
 *         Input: P_MESSAGELIST	pMsg ( mms 文件)
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_parse_sendto_address(P_MESSAGELIST	pMsg,set_to flag)
{
	U16				len = 0;
	int				i = 0;
	int				j = 0;
	pSENDTO_LIST	plist = NULL;
	pSENDTO_LIST	ptemp = NULL;

	if (!pMsg)
	{
		mms_Tracer((char*)": get current message error!!!!");
		return ;
	}

      switch (flag)
      	{
	case SENDTO_TO:
        	if (!pMsg->to_address)
       	{
      		        mms_Tracer((char*)": message no address!!!!");
      		        return ;
       	}
        	len = strlen(pMsg->to_address);
    	      if ((int)len <= 0)
 	     	{
 		   return;
 	     	}
 	      if (pgsendtolist)
          	{
			mms_Tracer(": parse send to before empty!");
          		cms_empty_sendto_to_list();
          		pgsendtolist = NULL;
          	}
		plist = cms_new_sendto_list_node();
		if (!plist)
		{
			return ;
		}
		pgsendtolist= plist;
		while (i < len)
		{
			if (pMsg->to_address[i] == ','||pMsg->to_address[i] == ';')
			{
				if (pMsg->to_address[i + 1] == '\0')	/*最后一个逗号*/
				{
					break;
				}
				ptemp = plist;
				plist->next = cms_new_sendto_list_node();
				if (!plist->next)
				{
					return ;
				}
				plist = plist->next;
				i++;
				j = 0;
				continue;
			}
			plist->number[j++] = pMsg->to_address[i++];
		  }
	         break;
	case SENDTO_CC:
        	if (!pMsg->cc_address)
       	{
      		        mms_Tracer((char*)": message no address!!!!");
      		        return ;
       	}
        	len = strlen(pMsg->cc_address);
    	       if ((int)len <= 0)
 	     	{
 		   return;
 	     	}
 	       if (pgsendcclist)
          	{
			mms_Tracer(": parse send cc before empty!");
          		cms_empty_sendto_cc_list();
          		pgsendcclist = NULL;
          	}
		plist = cms_new_sendto_list_node();
		if (!plist)
		{
			return ;
		}
		pgsendcclist = plist;
		while (i < len)
		{
			if (pMsg->cc_address[i] == ','||pMsg->cc_address[i] == ';')
			{
				if (pMsg->cc_address[i + 1] == '\0')	/*最后一个逗号*/
				{
					break;
				}
				ptemp = plist;
				plist->next = cms_new_sendto_list_node();
				if (!plist->next)
				{
					return ;
				}
				plist = plist->next;
				i++;
				j = 0;
				continue;
			}
			plist->number[j++] = pMsg->cc_address[i++];
		  }
	         break;
	case SENDTO_BCC:
        	if (!pMsg->bcc_address)
       	{
      		        mms_Tracer((char*)": message no address!!!!");
      		        return ;
       	}
        	len = strlen(pMsg->bcc_address);
    	      if ((int)len <= 0)
 	    	{
 		   return;
 	     	}
 	      if (pgsendbcclist)
          	{
          		cms_empty_sendto_bcc_list();
          		pgsendbcclist = NULL;
          	}
		plist = cms_new_sendto_list_node();
		if (!plist)
		{
			return ;
		}
		pgsendbcclist = plist;
		while (i < len)
		{
			if (pMsg->bcc_address[i] == ','||pMsg->bcc_address[i] == ';')
			{
				if (pMsg->bcc_address[i + 1] == '\0')	/*最后一个逗号*/
				{
					break;
				}
				ptemp = plist;
				plist->next = cms_new_sendto_list_node();
				if (!plist->next)
				{
					return ;
				}
				plist = plist->next;
				i++;
				j = 0;
				continue;
			}
			plist->number[j++] = pMsg->bcc_address[i++];
		  }
	         break;
      default:
	  	break;
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: cms_new_sendto_list_node
 *       Purpose: 新建一个收件人节点
 *         Input: void
 *        Output: None.
 *       Returns: pSENDTO_LIST 节点地址.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
pSENDTO_LIST cms_new_sendto_list_node(void)
{
	pSENDTO_LIST plist = NULL;

	plist = (pSENDTO_LIST)mms_Malloc(sizeof(SENDTO_LIST));
	if (!plist)
	{
		return NULL;
	}
	memset(plist, 0, sizeof(SENDTO_LIST));
	plist->number = (S8*)mms_Malloc(MMS_MAX_INPUT_SEND_TO_SIZE);
	if (!plist->number)
	{
		mms_Tracer((char*)"malloc plist: fail to allocate number!!!");
		mms_Free(plist);
		plist = NULL;
		return NULL;
	}
	memset(plist->number, 0, MMS_MAX_INPUT_SEND_TO_SIZE);
	return plist;
}
/* ----------------------------------------------------------------------------
 * Function Name: cms_getmedia_fllename
 *       Purpose: get default meadia filename
 *         Input: void
 *        Output: None.
 *       Returns: pSENDTO_LIST 节点地址.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_getmedia_fllename(char* inputfimename)
{
	char* str;
	int len, i;
	str = Cms_mms_uni8_16(inputfimename);
	len = pfnUnicodeStrlen((S8*)str);
	for(i=0; i<len; i++)
	{
		if(((U16*)str)[i] == 0x002e)//'.'
		{
			((U16*)str)[i] = 0;
		}
	}
	pfnUnicodeStrcpy((S8*)gedit.save_media_fname, (const S8*)str);
	mms_Free(str);
	str = NULL;
}
/***************************************************************************** 
* 以下是短彩合一部份接口
*****************************************************************************/
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_highlight_inbox_reply
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_highlight_inbox_reply(void)
{
	mmi_mms_highlight_generic(mmi_mms_entry_mms_reply_option,GoBackHistory);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_mms_reply_option
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_mms_reply_option(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8*	 guiBuffer=NULL;		/* Buffer holding history data */
	U16	 numItems=0;		/* Stores no of children in the submenu*/
	U16	 nStrItemList[MAX_SUB_MENUS];	/* Stores the strings id of submenus returned */
	U16	 itemIcons[MAX_SUB_MENUS];		/* Stores the icon id of submenus returned */
	U16	 screenId=SCR_ID_MMS_REPLY_OPTIONS;
	U8*	 pPopUpList[MAX_SUB_MENUS];	
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	EntryNewScreen(screenId, NULL,
					mmi_mms_entry_mms_reply_option, NULL);
	mms_Tracer((char*)"^_^mmi_mms_entry_mms_reply_option^_^");

	/* Get current screen to gui buffer  for history purposes*/
	guiBuffer = GetCurrGuiBuffer(screenId);
	/*  Retrieve no of child of menu item to be displayed */
	numItems = GetNumOfChild(MMS_INBOX_OPTIONS_REPLY_MENUID);
	/*  Retrieve string and icon ids in sequence of given menu item to be displayed */
	GetSequenceStringIds(MMS_INBOX_OPTIONS_REPLY_MENUID, nStrItemList);
	GetSequenceImageIds(MMS_INBOX_OPTIONS_REPLY_MENUID, itemIcons);
	
	/* Construct hint popup strings for menu items */
	ConstructHintsList(MMS_INBOX_OPTIONS_REPLY_MENUID, pPopUpList);
	/* set current screen id */
	SetMessagesCurrScrnID(screenId);
	/*  Set current parent id*/
	SetParentHandler(MMS_INBOX_OPTIONS_REPLY_MENUID);
	/*  Register highlight handler to be called in menu screen */
	RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#ifdef SUPPORT_SMSMMS_COMBINE
	{
		P_MESSAGELIST 	pMsg = NULL;
		pSENDTO_LIST 	plist = NULL;
		
		memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS+1)*ENCODING_LENGTH);
		pMsg = mms_file_manager_get_current_message();
		cms_parse_sendto_address(pMsg,SENDTO_TO);
		plist = pgsendtolist;
		while (plist)
		{
			memcpy(g_msg_cntx.smsPhoneNumber, plist->number, MMS_MAX_INPUT_SEND_TO_SIZE);
			plist = plist->next;
		}
		cms_empty_sendto_to_list();
		pgsendtolist=NULL;
		mms_mmi_tracer("g_msg_cntx.smsPhoneNumber is:%s", (char*)g_msg_cntx.smsPhoneNumber);
	}
#endif
	/* Display the call history main screen */
	ShowCategory52Screen(STR_MMS_INBOX_OPTIONS_REPLY, IMG_MESSAGE_SIM_MMS_MENUENTRY, 
						  STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  numItems, nStrItemList, itemIcons,
						   pPopUpList, 0, 0, guiBuffer);
	
	/* Register function with right softkey */
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_msg_reply_msg_to_entry
 *       Purpose: 彩信中以短消息形式回复
 *         Input: void
 *        Output: None.
 *       Returns: void
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_msg_highlight_reply (void)
{
	mmi_mms_highlight_generic(mmi_mms_msg_reply_msg_to_entry, GoBackHistory);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_msg_reply_msg_to_entry
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_msg_reply_msg_to_entry (void)
{
	char* 			str = NULL;	
	P_MESSAGELIST 	pMsg = NULL;
	
	pMsg = mms_file_manager_get_current_message();
	str = Cms_mms_uni8_16(pMsg->to_address);
	mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);
	mmi_msg_get_number_from_phb(NULL, (PU8)str);
	mms_Free(str);
	//g_msg_cntx.sendMessageCase = SEND_CASE_REPLY;
	//mmi_msg_entry_write_msg();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_msg_entry_write_msg
 *       Purpose: 彩信中编辑待回复的短消息内容
 *         Input: void
 *        Output: None.
 *       Returns: void
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_msg_entry_write_msg (void)
{
	U8* 		guiBuffer=NULL;
	EMSData*	pEMS;
	
	/* disallow re-entering SMS application when there is a pending SMS job running in the background */
	if(mmi_frm_sms_check_action_pending())
	{
		DisplayPopup((PU8)GetString(STR_SMS_MSG_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
		return;
	}
	EntryNewScreen(SCR_ID_MSG_WRITE, mmi_msg_exit_generic, mmi_mms_msg_entry_write_msg, NULL);
	//AlmDisableSPOF();
	
	guiBuffer = GetCurrGuiBuffer (SCR_ID_MSG_WRITE);	

	SetMessagesCurrScrnID(SCR_ID_MSG_WRITE);

	//GetEMSDataForEdit (& pEMS, 0);

	SetMessagesCurrScrnID(SCR_ID_MSG_WRITE);
	ShowCategory28Screen (STR_WMESSAGE_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION,
						  			STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE,
						  			STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE,
						  			pEMS, guiBuffer );
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetLeftSoftkeyFunction (mmi_msg_entry_option_write, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_msg_entry_send_option, KEY_SEND, KEY_EVENT_UP);
	RegisterInputMethodScreenCloseFunction (Messages2GoBackHistory);
	SetCategory28RightSoftkeyFunction (mmi_mms_msg_go_back_from_write_msg, KEY_EVENT_UP);
	
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_msg_go_back_from_write_msg
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_msg_go_back_from_write_msg (void)
{
	GoBackHistory();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_msg_entry_send_option
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_msg_entry_send_option(void)
{

	g_msg_cntx.msg_send_info.CurrSendSmsNumbers=0;
	g_msg_cntx.msg_send_info.TotalSendSmsNumbers=1;	
	mmi_msg_send_msg_req((U8*)g_msg_cntx.smsPhoneNumber, g_msg_cntx.currBoxIndex,1);
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_msg_entry_option_write
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_msg_entry_option_write (void)
{
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	mmi_msg_entry_option_write();
}



/*-----------------------------------------------------------------------------*/
/* 彩信支持外部发送(我的文档、电话本等应用)                                                    */
/*-----------------------------------------------------------------------------*/

#ifdef SUPPORT_EXTERN_SEND
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_extern_entry_new_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_extern_entry_new_mms(void* filePath,void* phbnumber)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	char* 	buf = NULL;
	char* 	temp_name = NULL;
	S32 		filelen = 0;
	U16 		type = 0;
        int   	i = 0;
	MMS_FILE_HANDLE fp = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_Tracer("mmi_mms_extern_entry_new_mms");
	if(filePath == NULL&&phbnumber==NULL)
	{
		mms_Tracer("mmi_mms_extern_entry_new_mms filepath==NULL");
		GoBackHistory();  
		return;
	}
	else
	{	
		/*初始化变量及标志位*/
		{
			memset(&gedit, 0, sizeof(TEXT_EDIT));
			cms_empty_sendto_list();
			pgsendtolist=NULL;
			pgsendcclist=NULL;
			pgsendbcclist=NULL;
			MMSDelAllSlide(gpeditor_doc);
			gpeditor_doc->totalsize = 0;	

			ghiliindex = 0;
			gbox_operation = 0;
			gsendto_options=0;
			ginput_screen = INPUT_OPTION_UNKNOWN;
			mmsflag.gnew_message=TRUE;
			mmsflag.gmsg_saved = FALSE;
			gsendto_options=SENDTO_UNKNOWN;

		}
		/*New slide for new mms*/
		if(!MMS_New_Slide(gpeditor_doc))
		{
			mms_Free(buf);
			buf = NULL;
			return ;
		}
		/*Open this file to new mms */
		if(filePath != NULL)
		{
		 	fp = FS_Open((unsigned short*)filePath, FS_READ_ONLY);
			if (fp < 0)
			{
				mms_Tracer("FS_Open file error!!!");
				return ;
			}
			
			mms_Tracer("get file size");		
			Cms_Adp_GetFileSize(fp, (unsigned int*)(&filelen));	
			mms_mmi_tracer("filelen = %d",filelen);
			
			if (filelen > MMS_MAX_SIZE_OF_MESSAGE)		/*文件过大*/
			{
				Cms_Adp_fclose(fp);
				DisplayPopup((U8*)GetString(STR_SIZE_OVERFLOW), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				return;
			}
			if (filelen <= 0)
			{
				Cms_Adp_fclose(fp);
				DisplayPopup((U8*)GetString(STR_MMS_MEDIA_FILE_ERROR), IMG_GLOBAL_ERROR, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
				return;
			}
			
			buf = (char *)mms_Malloc(filelen);
			
			if (!buf)
			{
				mms_Tracer("buf allocate memory error!!!");
				return ;
			}
			
			if (0 != Cms_Adp_fread(fp, buf, filelen, (unsigned int*)(&i))) 
			{
				mms_Tracer("cms_create_new_mms: read error!");
				Cms_Adp_fclose(fp);
				mms_Free(buf);
				buf = NULL;
				return;
			}
			
			Cms_Adp_fclose(fp);
			temp_name = Cms_mms_uni16_8(filePath);
			
			if (temp_name)
			{
				type = mms_get_media_type((U8*)buf, strlen(temp_name), temp_name);
				mms_Free(temp_name);
				temp_name = NULL;
			}

			if (type == 0||type==MMS_TYPE_MP3)
			{
				mms_Tracer("get media type error!!!");
				mms_Free(buf);
				buf = NULL;
				GoBackHistory(); 
				DisplayPopup((U8*)GetString(STR_TYPE_ERROR),IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				return ;
			}
			/*Add image or audio to new mms struct*/
			switch(type)
			{
				case MMS_TYPE_GIF:
				case MMS_TYPE_JPEG:
#ifdef CMS_SURPPORT_PNG_BMP
				case MMS_TYPE_PNG:
#endif
				case MMS_TYPE_WBMP:
				case MMS_TYPE_BMP1:
					cms_insert_image_into_new_mms(buf, filelen, type);
					break;
				case MMS_TYPE_MIDI:
				case MMS_TYPE_WAV:
				case MMS_TYPE_IMY:
				case MMS_TYPE_AMR:
					cms_insert_music_into_new_mms(buf, filelen, type);
					break;
				case MMS_TYPE_VCF:
				case MMS_TYPE_VCS:
					cms_insert_accessory_into_new_mms(buf, filelen, type);
					break;
				default:
					mms_Free(buf);
					buf = NULL;
					return ;
			}
			mms_Free(buf);
			buf = NULL;
			
		}
		/*Add phbnumber to new message*/
		else if(phbnumber !=NULL)
		{
			pSENDTO_LIST 	plist = NULL;
			char				ansiiTempBuff[MMS_MAX_INPUT_SEND_TO_SIZE];
			mms_Tracer("Add phbnumber to new mms message");
			if(pfnUnicodeStrlen((S8*)phbnumber)>35)
			{
				DisplayPopup((PU8)GetString(STR_SMS_NUM_LEN_EXCEEDED), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);			
				return;
			}
			plist = (pSENDTO_LIST)mms_Malloc(sizeof(SENDTO_LIST));
				
			if (!plist)
			{
				mms_Tracer((char*)"Sendto list: fail to allocate phone list!!!");
				return;
			}
			memset(plist, 0, sizeof(SENDTO_LIST));	
			plist->number = (S8*)mms_Malloc(MMS_MAX_INPUT_SEND_TO_SIZE);
				
			if (!plist->number)
			{
				mms_Tracer((char*)"malloc plist: fail to allocate number!!!");
				mms_Free(plist);
				plist = NULL;
				return;
			}
			memset(plist->number, 0, MMS_MAX_INPUT_SEND_TO_SIZE);
			UnicodeToAnsii((S8*)ansiiTempBuff,(S8*)phbnumber);
			strcpy(plist->number,ansiiTempBuff);
			if(pgsendtolist ==NULL)
			{
				pgsendtolist = plist;
				pgsendtolist->next = NULL;
				mms_mmi_tracer("To->number is %s",pgsendtolist->number);
			} 			
		}
	}
#ifdef __MMI_CLAMSHELL__
	SetInterruptEventHandler(mmi_mms_clam_event_hander, NULL,MSG_ID_MMI_EQ_GPIO_DETECT_IND);
#endif 
	mmi_mms_entry_new_message();
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_extern_exit_new_message
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_extern_exit_new_message()
{
	/*这里将会清理内存及标志位变量复位*/
	mms_stop_animation();
	
	if (gedit.media_buf)
	{
		switch(gedit.media_type)
		{
		case MMS_TYPE_WAV:
			StopAudioWavStream();
			break;
		case MMS_TYPE_IMY:
			StopAudioStream();
			break;
		case MMS_TYPE_MIDI:
			StopAudioMidiStream();
			break;
		case MMS_TYPE_AMR:
			StopAudioStream();	
			break;
		default:
			break;
		}
		mms_Free(gedit.media_buf);
		gedit.media_buf = NULL;
		gedit.media_len = 0;
		gedit.media_type = 0;
	}
	
	memset(&gedit, 0, sizeof(TEXT_EDIT));
	
	{
		mmsflag.gnew_message= FALSE;
		mmsflag.gsend_save = FALSE;
		mmsflag.gmms_memory = FALSE;
		mmsflag.gmmsbox_full=FALSE;
		mmsflag.gexit_toidle= FALSE;
		
		cms_empty_sendto_list();
		pgsendtolist=NULL;
		pgsendcclist=NULL;
		pgsendbcclist=NULL;
		
		MMSDelAllSlide(gpeditor_doc);
		gpeditor_doc->totalsize = 0;
	

		gbox_operation = 0;
		gsendto_options=0;

		ghiliindex = 0;
		ghiliindex1 = 0;
		gCurActionItem = 0;
		ginput_screen = INPUT_OPTION_UNKNOWN;		
	}

	if (!mmsflag.gsend_recv)
	{
		/*非收发状态*/
		destroy_mms_mem_file_info();
	}
	
}
#endif


/*-----------------------------------------------------------------------------*/
/* 彩信支持短彩合一                                                    */
/*-----------------------------------------------------------------------------*/
#ifdef SUPPORT_SMSMMS_COMBINE
#include "CmsBookmark.h"
/*-----------------------------------------------------------------------------*/
/* 短信加入到彩信列表         */
/*-----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------
 * Function Name: mmi_smsmms_add_sms_to_list
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_smsmms_add_sms_to_list (mmi_frm_sms_msgbox_struct* data,U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 		boxtype;
	U16 		smsindex;
	U8* 		smsdate;
	U8 		type=MMI_FRM_SMS_NOBOX;
    	P_MESSAGELIST 		pMsg=NULL;
    	MMS_FOLDER_NAME 	folder;


	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_Tracer("^_^mmi_smsmms_add_sms_to_list in");
      if((data->msgtype&MMI_FRM_SMS_UNREAD)==MMI_FRM_SMS_UNREAD)
            type=MMI_FRM_SMS_UNREAD;
      else if((data->msgtype&MMI_FRM_SMS_INBOX)==MMI_FRM_SMS_INBOX)
            type=MMI_FRM_SMS_INBOX;
      else if((data->msgtype&MMI_FRM_SMS_OUTBOX)==MMI_FRM_SMS_OUTBOX)
            type=MMI_FRM_SMS_OUTBOX;
      else if((data->msgtype&MMI_FRM_SMS_DRAFTS)==MMI_FRM_SMS_DRAFTS)
      #ifdef __MMI_MESSAGES_DRAFT_BOX__
            type=MMI_FRM_SMS_DRAFTS;
      #else
            type=MMI_FRM_SMS_OUTBOX;
      #endif
	if(!cms_wapmms_init)
	{
		cms_init_mem_pool();	/*初始化内存*/
		mms_init_app();			/*初始化彩信全局变量*/
		cms_wapmms_init = TRUE;
	}
	pMsg = mms_file_manager_new_sms_message();
	if(pMsg == NULL)
	{
		return;
	}
	mmi_frm_sms_get_sms_list_index(&boxtype,&smsindex,index);
	/* DATE */
	smsdate=(U8*)mmi_frm_sms_get_sms_timestamp(boxtype, smsindex);
	if((type==MMI_FRM_SMS_DRAFTS)||(type==MMI_FRM_SMS_OUTBOX))
	{
		CmsTime2String(pMsg->date);
	}
	else
	{
		sprintf(pMsg->date,"20%d%d%d%d%d%d%d%d%d%d%d%d",
			(int)(smsdate[0]/10),(int)(smsdate[0]%10),
			(int)(smsdate[1]/10),(int)(smsdate[1]%10),
			(int)(smsdate[2]/10),(int)(smsdate[2]%10),
			(int)(smsdate[3]/10),(int)(smsdate[3]%10),
			(int)(smsdate[4]/10),(int)(smsdate[4]%10),
			(int)(smsdate[5]/10),(int)(smsdate[5]%10));
	}
	mms_mmi_tracer("^_^pmsg->date=%s", (char*)pMsg->date);	
	
	switch(type)
	{
	case MMI_FRM_SMS_INBOX:
	case MMI_FRM_SMS_UNREAD:
	{	
		pMsg->msgtype=MESSAGE_SMS;
		pMsg->SmsIndex=index;
		folder=MMS_RECEIVE_FOLDER;

		mms_file_manager_add_message_to_folder(pMsg,folder,SET_MESSAGE_NULL);
		mms_file_manager_free_message(pMsg);
	}
	break;
	
	case MMI_FRM_SMS_OUTBOX:
	#ifndef __MMI_MESSAGES_DRAFT_BOX__
	case MMI_FRM_SMS_DRAFTS:
	#endif
	{
		pMsg->msgtype=MESSAGE_SMS;
		pMsg->SmsIndex=index;
		folder=MMS_SEND_FOLDER;

		mms_file_manager_add_message_to_folder(pMsg,folder,SET_MESSAGE_NULL);
		mms_file_manager_free_message(pMsg);
	}
	break;
	
	#ifdef __MMI_MESSAGES_DRAFT_BOX__	
	case MMI_FRM_SMS_DRAFTS:
	{
		pMsg->msgtype=MESSAGE_SMS;
		pMsg->SmsIndex=index;
		folder=MMS_DRAFT_FOLDER;

		mms_file_manager_add_message_to_folder(pMsg,folder,SET_MESSAGE_NULL);
		mms_file_manager_free_message(pMsg);
	}
	break;
	#endif
	
	default:
		mms_file_manager_free_message(pMsg);
		break;	
	}
	return;
}

/* ----------------------------------------------------------------------------
 * Function Name: mms_get_curmsg_by_sms_index
 *       Purpose: 
 *         Input:
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
P_MESSAGELIST mms_get_curmsg_by_sms_index(U16 sms_index,MMS_FOLDER_NAME* box)
{
	U16 		i;
	P_MESSAGELIST message = NULL;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	mms_Tracer("enter mmi_box_list_get_item");
	message = pgManager->receiveFolder->root;
    
	for (i=0;i < pgManager->receiveFolder->messageNumber && message; i++)
	{
		if((message->msgtype==MESSAGE_SMS)&&message->SmsIndex==sms_index)
		{
			*box=MMS_RECEIVE_FOLDER;
			return message;
		}
		message = message->next;
	}
    
	message = pgManager->sendFolder->root;
	for (i=0;i < pgManager->sendFolder->messageNumber && message; i++)
	{
		if((message->msgtype==MESSAGE_SMS)&&message->SmsIndex==sms_index)
		{
			*box=MMS_SEND_FOLDER;
			return message;
		}
		message = message->next;
	}
	
	message = pgManager->draftFolder->root;  
	for (i=0;i < pgManager->draftFolder->messageNumber && message; i++)
	{
		if((message->msgtype==MESSAGE_SMS)&&message->SmsIndex==sms_index)
		{
			*box=MMS_DRAFT_FOLDER;
			return message;
		}
		message = message->next;
	}
	return NULL;
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_smsmms_delete_sms_from_list
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_smsmms_delete_sms_from_list( U16 index)
{
	P_MESSAGELIST pMsg=NULL,pTemp=NULL;
	MMS_FOLDER_NAME box;

	mms_mmi_tracer("^_^delete sms index = %d",index);
	if( pgManager->currentFolder->root==NULL)
	{
		return;
	}
	if(index==MMI_FRM_SMS_INVALID_INDEX)
	{
		pMsg = pgManager->currentFolder->root;
		for(;pMsg;)
		{
			pTemp=pMsg->next;
			if(pMsg->msgtype==MESSAGE_SMS)
			{
				mms_Tracer("delete a mms message ");
				mms_file_manager_set_current_message(pMsg);
				mms_file_manager_delete_current_message();
			}
			pMsg=pTemp;
		}
		return ;
	}
	/*get pmsg from the index*/
	pMsg= mms_get_curmsg_by_sms_index(index,&box);
	if(pMsg!=NULL)
		mms_file_manager_delete_message_from_box(pMsg,box);

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
 void mmi_mms_del_all_sms_mms_msg(void)
{
	switch(mms_file_manager_get_current_folder())
	{
	case MMS_RECEIVE_FOLDER:
		mmi_msg_delete_msg_all_inbox();
		break;
	case MMS_SEND_FOLDER:
		mmi_msg_delete_msg_all_outbox();
		break;
	#ifdef __MMI_MESSAGES_DRAFT_BOX__
	case MMS_DRAFT_FOLDER:
		mmi_msg_delete_msg_all_draftbox();
		break;
	#endif
	default:
		break;
	}
	mmi_update_mms_idel_icon();
	/*确认消息返回界面，返回到彩信界面*/
}


/*-----------------------------------------------------------------------------*/
/* WAP 消息加入到彩信列表         */
/*-----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------
 * Function Name: mmi_wapmms_add_push_to_list
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_wapmms_add_push_to_list (P_CMS_BROWSER_PUSH inPush)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	P_MESSAGELIST 		pMsg=NULL;
	P_CMS_ALL_PUSH 		pSILPUSH=NULL;
	MMS_FOLDER_NAME 	folder;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	mms_Tracer("^_^mmi_wapmms_add_push_to_list in");
	pSILPUSH = (P_CMS_ALL_PUSH)inPush->pPUSHData;
	pMsg = mms_file_manager_new_message();

	pMsg->msgtype=MESSAGE_WAP;
	pMsg->fileName=NULL;
	
	/* url */
	pMsg->url = (S8*)mms_Malloc(MAX_URL_LENGTH);
	if (!pMsg->url)
	{
		mms_Tracer((char*)"add wap node...fail to allocate date!!!");
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		return ;
	}
	memset(pMsg->url, 0, MAX_URL_LENGTH);
	strcpy(pMsg->url,(char*)pSILPUSH->pURL);
	mms_mmi_tracer("^_^pmsg->date=%s", (char*)pMsg->url);	

	/* subject */

	if (pSILPUSH->pTitle!=NULL) 
	{
		strcpy(pMsg->subject,(char*)pSILPUSH->pTitle);
	}

	/* date */
	CmsTime2String(pMsg->date);
	mms_mmi_tracer("^_^pmsg->date=%s", (char*)pMsg->date);	

	/* expriy_time */		
	pMsg->state='U';
	folder=MMS_RECEIVE_FOLDER;

	mms_file_manager_add_message_to_folder(pMsg,folder,SET_MESSAGE_NULL);
	#ifdef SUPPORT_MMS_IDLE_IND
	mmi_mms_get_new_msg_file_name(pMsg);
	#endif
	mms_file_manager_free_message(pMsg);

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
U16 mmi_wapmms_inbox_get_push_count()
{
	U16 i = 0;
	U16 k=0;
	P_MESSAGELIST pMsg;
	
	if (!pgManager)
	{
		return 0;
	}
	if (pgManager->receiveFolder)
	{
		pMsg = pgManager->receiveFolder->root;
		for (k=0;k< pgManager->receiveFolder->messageNumber && pMsg; k++)
		{
			if((pMsg->fileName==NULL)&&(pMsg->url!=NULL))
			{
				i+=1;
			}
			pMsg = pMsg->next;
		}
	}
	return i;
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
void mmi_wapmms_judge_recv_wappush_del_last()
{
	U16	count=0;
	P_MESSAGELIST pMsg_del=NULL,pMsg_tmp=NULL;

	count=mmi_wapmms_inbox_get_push_count();
	if(count>=CMS_MAX_PUSH)
	{	
		pMsg_tmp=pgManager->receiveFolder->root;
			
		for(;pMsg_tmp->next!=NULL;pMsg_tmp=pMsg_tmp->next)
		{	
			if((pMsg_tmp->fileName==NULL)&&(pMsg_tmp->url!=NULL))
			{
				pMsg_del=pMsg_tmp;
			}		
		}
			
		if(pMsg_del!=NULL)
		{
			mms_file_manager_delete_message_from_box(pMsg_del, MMS_RECEIVE_FOLDER);			
			return ;
		}
	}
}
 
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mmswap_show_wap_push_icon
 *       Purpose: 得到是否有新未读WAP PUSH 消息在桌面显示
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mmswap_show_wap_push_icon(void)
{
	U16 				Have_WapInd = 0;
	P_MESSAGELIST 	pMsg_temp;

	 /* 是否有未读WAP PUSH 消息*/
 	if(pgManager->receiveFolder->messageNumber>0)
 	{ 
  		pMsg_temp=pgManager->receiveFolder->root;
  		while(pMsg_temp!=NULL)
  		{ 
   			if(pMsg_temp->state=='U'&&pMsg_temp->fileName==NULL&&pMsg_temp->url!=NULL)
   			{
    				pMsg_temp = NULL;
				Have_WapInd++;
			}
   			else
   			{   				
    				pMsg_temp=pMsg_temp->next;	
   			}
  		}		
  		pMsg_temp = NULL;
 	}
	if(Have_WapInd>0)
	{
		ShowStatusIcon(STATUS_ICON_WAP);
	}
	else
	{
		HideStatusIcon(STATUS_ICON_WAP);
	}
	//UpdateStatusIcons();
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
void mms_wap_ota_add_bookmark(void)
 {
 	U16		NotDoneflag =FALSE;
 	P_MESSAGELIST pMsg = NULL;
	pMsg = mms_file_manager_get_current_message();
	if(NULL !=pMsg->subject|| NULL != pMsg->url)
	{
		cms_trace(": mms_wap_ota_add_bookmark");
		Cms_LoadBookMarkFile();
		Cms_Browser_StartEvent();
		if(Cms_Browser_NewBookmarkAdd((P_CMS_BROWSER_U8)pMsg->subject, (P_CMS_BROWSER_U8)pMsg->url)==E_CMS_BM_RECORDFULL)
		{
			cms_trace(": mms_wap_ota_add_bookmark>20");
			DisplayPopup((U8*)GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);
			NotDoneflag = TRUE;
		}
		Cms_SaveBookMarkFile();
		Cms_Browser_ExitEvent();
	}
	
	if(IsScreenPresent(SCR_ID_MMS_INBOX_WAP_DETAILS))
	{
		GoBackToHistory(SCR_ID_MMS_INBOX_WAP_DETAILS);
	}
	else
	{
		GoBackHistory();
	}
	if(NotDoneflag ==FALSE)
	{
		DisplayPopup((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED,NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE);
	}
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
void mmi_mms_wap_ota_to_setting_list(void)
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

	EntryNewScreen(screenId, NULL,
					mmi_mms_wap_ota_to_setting_list, NULL);
	
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
	
	SetLeftSoftkeyFunction(mms_wap_ota_to_setting, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
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
void mms_wap_ota_to_setting(void)
 {
 	char* temp=NULL;
  	P_MESSAGELIST pMsg = NULL;

	if(gconfig.wap_service_activeitem==ghiliindex)
	{
		DisplayPopup((U8*)GetString(STR_MMS_WAP_OTA_CANNOT_SET), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	pMsg = mms_file_manager_get_current_message();

	/*将配置信息加入预设配置*/
	wap_read_setting_file_by_index(ghiliindex);
	if(pMsg->subject!=NULL)
	{	
		temp=Cms_mms_uni8_16(pMsg->subject);
		memset(gWapTemp.service_id,0,sizeof(gWapTemp.service_id));
		pfnUnicodeStrcpy((PS8)gWapTemp.service_id,(PS8)temp);
		mms_Free(temp);
		temp = NULL;
	}
	if(pMsg->url!=NULL)
	{
		temp=Cms_mms_uni8_16(pMsg->url);
		memset(gWapTemp.centre_addr,0,sizeof(gWapTemp.centre_addr));
		pfnUnicodeStrcpy((PS8)gWapTemp.centre_addr,(PS8)temp);
		mms_Free(temp);
		temp = NULL;
	}
	if(pMsg->ota_gateway!=NULL)
	{	
		temp=Cms_mms_uni8_16(pMsg->ota_gateway);
		memset(gWapTemp.gateway,0,sizeof(gWapTemp.gateway));
		pfnUnicodeStrcpy((PS8)gWapTemp.gateway,(PS8)temp);
		mms_Free(temp);
		temp = NULL;
	}
	if(pMsg->ota_port!=NULL)
	{
		temp=Cms_mms_uni8_16(pMsg->ota_port);
		memset(gWapTemp.port,0,sizeof(gWapTemp.port));
		pfnUnicodeStrcpy((PS8)gWapTemp.port,(PS8)temp);
		mms_Free(temp);
		temp = NULL;
	}
	wap_write_setting_file_by_index(ghiliindex);
	if(IsScreenPresent(SCR_ID_MMS_INBOX_WAP_DETAILS))
	{
		GoBackToHistory(SCR_ID_MMS_INBOX_WAP_DETAILS);
	}
	else
	{
		GoBackHistory();
	}
	
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
void mms_ota_to_mms_setting(void)
 {
 	char* temp=NULL;
  	P_MESSAGELIST pMsg = NULL;
	int setnumber=0;
	
	if(gconfig.mms_service_activeitem==ghiliindex)
	{
		DisplayPopup((U8*)GetString(STR_MMS_WAP_OTA_CANNOT_SET), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		return ;
	}
	pMsg = mms_file_manager_get_current_message();

	if(pMsg->ota_murl!=NULL)
	{
		for(;setnumber<SERVICE_LIST_ITEM;setnumber++)
		{
			mms_read_msg_setting_file_by_index(setnumber);
			if(pfnUnicodeStrlen((S8*)gconfigtemp.service_id)==0)
				break;
		}
		/*将配置信息加入预设配置*/
		if(pMsg->subject!=NULL)
		{	
			temp=Cms_mms_uni8_16(pMsg->subject);
			memset(gconfigtemp.service_id,0,sizeof(gconfigtemp.service_id));
			pfnUnicodeStrcpy((PS8)gconfigtemp.service_id,(PS8)temp);
			mms_Free(temp);
			temp = NULL;
		}
		if(pMsg->ota_murl!=NULL)
		{
			temp=Cms_mms_uni8_16(pMsg->ota_murl);
			memset(gconfigtemp.centre_addr,0,sizeof(gconfigtemp.centre_addr));
			pfnUnicodeStrcpy((PS8)gconfigtemp.centre_addr,(PS8)temp);
			mms_Free(temp);
			temp = NULL;
		}
		if(pMsg->ota_gateway!=NULL)
		{	
			temp=Cms_mms_uni8_16(pMsg->ota_gateway);
			memset(gconfigtemp.gateway,0,sizeof(gconfigtemp.gateway));
			pfnUnicodeStrcpy((PS8)gconfigtemp.gateway,(PS8)temp);
			mms_Free(temp);
			temp = NULL;
		}
		if(pMsg->ota_port!=NULL)
		{
			temp=Cms_mms_uni8_16(pMsg->ota_port);
			memset(gconfigtemp.port,0,sizeof(gconfigtemp.port));
			pfnUnicodeStrcpy((PS8)gconfigtemp.port,(PS8)temp);
			mms_Free(temp);
			temp = NULL;
		}
		mms_write_msg_setting_file_by_index(setnumber);
	}
	
	if(IsScreenPresent(SCR_ID_MMS_INBOX_WAP_DETAILS))
	{
		GoBackToHistory(SCR_ID_MMS_INBOX_WAP_DETAILS);
	}
	else
	{
		GoBackHistory();
	}
	
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
void mmi_mms_ota_to_setting_list(void)
{
	U8* guiBuffer = NULL;
	S32 hiliteitem = 0;
	U16 setnumber=0;
	U16 screenId = SCR_ID_WAP_SETTING_SERVICE_ID_MENU;
	PU8	pservicelist[SERVICE_LIST_ITEM]={0};

	memset(servicelist,0,sizeof(servicelist));	
	for(;setnumber<SERVICE_LIST_ITEM;setnumber++)
	{
		mms_read_msg_setting_file_by_index(setnumber);
		if(pfnUnicodeStrlen((S8*)gconfigtemp.service_id)==0)
		{
			pfnUnicodeStrcpy((PS8)servicelist[setnumber],(PS8)L"<");
			pfnUnicodeStrcat((PS8)servicelist[setnumber],(S8 *)GetString(STR_GLOBAL_EMPTY));
			pfnUnicodeStrcat((PS8)servicelist[setnumber],(PS8)L">");
		}
		else
		{
			pfnUnicodeStrcpy((S8*)servicelist[setnumber], (S8*)gconfigtemp.service_id);
		}
		pservicelist[setnumber]=(PU8)servicelist[setnumber];
	
	}

	EntryNewScreen(screenId, NULL,
					mmi_mms_ota_to_setting_list, NULL);
	
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
	RegisterHighlightHandler(mmi_get_index);

	if (guiBuffer)
	{
		hiliteitem = ghiliindex;
	}
	else
	{
		hiliteitem=gconfig.mms_service_activeitem;
	}
	
	ShowCategory36Screen( STR_MMS_WAP_EDIT_SETTING, IMG_MESSAGE_MMS_MENUENTRY,
						  	STR_GLOBAL_OK, IMG_GLOBAL_OK,
						  	STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
						  	SERVICE_LIST_ITEM, (U8**)pservicelist, (U16)hiliteitem, guiBuffer);
	
	SetLeftSoftkeyFunction(mms_ota_to_mms_setting, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
}
 /*-----------------------------------------------------------------------------*/
/*                                                    */
/*-----------------------------------------------------------------------------*/
 
 /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void EntryCombMsgMainMenu(void)
{
	EntryScrMMSMenuList();
}
void mmi_msg_entry_comb_inbox_list(void)
{
	mmi_mms_entry_inbox();
}
void mmi_msg_entry_comb_outbox_list(void)
{
	mmi_mms_entry_outbox();
}
void mmi_msg_entry_comb_draftbox_list (void)
{
	mmi_mms_entry_draftbox();
}
#else
/*-----------------------------------------------------------------------------*/
/*为在短彩合一版本中调试非短彩合一版本增加，关闭宏时为链接工程*/
/*-----------------------------------------------------------------------------*/
void mmi_smsmms_add_sms_to_list (mmi_frm_sms_msgbox_struct* data,U16 index)
{}
void mmi_smsmms_delete_sms_from_list( U16 index)
{}
void EntryCombMsgMainMenu(void)
{
}
void mmi_msg_entry_comb_inbox_list(void)
{
}
void mmi_msg_entry_comb_outbox_list(void)
{
}
void mmi_msg_entry_comb_draftbox_list (void)
{
}
#endif


/*-----------------------------------------------------------------------------*/
/* 彩信IDLE 界面新消息提示                                                    */
/*-----------------------------------------------------------------------------*/

#ifdef SUPPORT_MMS_IDLE_IND

  /* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_idle_play_or_down_msg
 *       Purpose: IDLE界面提示时进入不同的选 项(PUSH/MMS)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_idle_play_or_down_msg()
{
	P_MESSAGELIST pMsg = NULL;
	
	mmi_mms_entry_init_param();
	
	mms_file_manager_set_current_folder(MMS_RECEIVE_FOLDER);
	pMsg=(P_MESSAGELIST)mmi_mms_inbox_find_ind_new_message();
	mms_file_manager_set_current_message(pMsg);
	if (!pMsg)
	{
		mms_Tracer("No find pmessage");
		return ;
	}
	
	if(pMsg->url)
	{
		mms_Tracer("PUSH in ");
		mmi_mms_enter_inbox_push_options();
	}
	else
	{
		mms_Tracer("MMS in ");
		mmi_mms_enter_inbox_message_options();
	}

}
  /* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_inbox_find_ind_new_message
 *       Purpose: 根据彩信文件名来查找对应的内存节点
 *         Input: void
 *        Output: P_MESSAGELIST :对应的彩信内存结点/WAP_PUSH
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
P_MESSAGELIST mmi_mms_inbox_find_ind_new_message(void)
{

	P_MESSAGELIST pMsg = NULL;	
	pMsg = pgManager->receiveFolder->root;
	while(pMsg!=NULL)
	{
		if(strcmp(gNewind_fname,pMsg->fileName)==0)
		{
			mms_mmi_tracer("^_^Fnd_ind_new^_^11: gNewind = %s ", (char*)gNewind_fname);
			mms_mmi_tracer("^_^Find_ind_new^_^11: filename = %s ", (char*)pMsg->fileName);
			return pMsg;
		}
		if(strcmp(gNewind_fname,pMsg->url)==0)
		{
			mms_mmi_tracer("^_^Fnd_wap_push^_^22: gNewind = %s ", (char*)gNewind_fname);
			return pMsg;
		}		
		pMsg = pMsg->next;
	}
	return NULL;

}
  /* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_inbox_list_dummy
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_new_ind_dummy(void)
{
	history currHistory;
	memset (& currHistory, 0, sizeof (currHistory));
	currHistory.scrnID = SCR_ID_MMS_INBOX;
	currHistory.entryFuncPtr = mmi_mms_entry_inbox;
	memset ((S8*)currHistory.inputBuffer, 0, ENCODING_LENGTH);
	AddHistory (currHistory);
}

  /* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_new_msg_details
 *       Purpose: IDLE 界面进入时的信息详情提示
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_new_msg_details(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	int 		i = 0, j = 0;
	U8*		guiBuffer=NULL;
	U16		screenId=SCR_ID_MMS_SHOW_DETAILS_ON_IDLE;
	char*	temp = NULL;
	char		time[MMS_MAX_DATE_LEN] = {0};
	S32		str_len = 0;
	float		resize=0;
	
	char		ansiiTempBuff[MAX_SHOW_STRING_BUF/2];
	char		ucs2TempBuff[MAX_SHOW_STRING_BUF];
	P_MESSAGELIST pMsg = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	pMsg=mmi_mms_inbox_find_ind_new_message();
	if (!pMsg)
	{
		return;
	}
	mms_file_manager_set_current_folder(MMS_RECEIVE_FOLDER);
	mms_file_manager_set_current_message(pMsg);

	if ((pMsg->state == 'N')||(pMsg->state == 'U'))
	{
		mms_Tracer("modify state");
		mms_file_manager_modify_current_message_state(MMS_MSG_STATE_READ);
		mmi_update_mms_idel_icon();

	}
	while (i < 14)	
	{
		time[j++] = pMsg->date[i++];
		if (i == 4 || i == 6)
		{
			time[j++] = '-';
		}
		else if (i == 8)
		{
			time[j++] = '\n';
		}
		else if (i == 10 || i == 12)
		{
			time[j++] = ':';
		}
	}
	
	memset(UnicodeBuf,0,sizeof(UnicodeBuf));
	/*收件人*/
	
	pfnUnicodeStrcpy((PS8)UnicodeBuf,(S8 *)GetString( STR_MMS_SENDER ));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");

	if(pMsg->to_address) 
	{
		pSENDTO_LIST plist = NULL;
		cms_parse_sendto_address(pMsg,SENDTO_TO);
		plist = pgsendtolist;
		while (plist)
		{
			memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
			sprintf( (S8 *)ansiiTempBuff, "%s\n",plist->number);
			memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
			AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
			pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
			plist = plist->next;
		}
		cms_empty_sendto_to_list();
		pgsendtolist=NULL;
	}
	else
	{
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"<");
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_GLOBAL_EMPTY));
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L">\n");
	}
	
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	/*抄送*/
	if(pMsg->url==NULL)
	{
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_CC_ID));
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
		if(pMsg->cc_address) 
		{
			pSENDTO_LIST plist = NULL;
			cms_parse_sendto_address(pMsg,SENDTO_CC);
			plist = pgsendcclist;
			while (plist)
			{
				memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
				sprintf( (S8 *)ansiiTempBuff, " %s\n",plist->number);
				memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
				AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
				pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
				plist = plist->next;
			}
			cms_empty_sendto_cc_list();
			pgsendcclist=NULL;
		}
		else
		{
			pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"<");
			pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_GLOBAL_EMPTY));
			pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L">\n");
		}
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n");
	}
	
	/* 主题*/
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_SUBJECT_ID));
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L":\n");
	if(pMsg->subject!=NULL)
	{	
		temp=Cms_mms_uni8_16(pMsg->subject);
		pfnUnicodeStrncat((PS8)UnicodeBuf,(PS8)temp,40);
		mms_Free(temp);
		temp = NULL;
	}
	else
	{
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"<");
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_GLOBAL_EMPTY));
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L">");
	}
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)L"\n\n");

	/*发送/接收时间*/

	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_SENT));
	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	sprintf( (S8 *)ansiiTempBuff, ":\n%s\n\n",time);
	memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);

	/*信息大小*/
	resize=(float)pMsg->size;
	pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_MSG_SIZE));
	memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
	sprintf( (S8 *)ansiiTempBuff, ":\n%.1f K\n\n",(float)(resize/1024));
	memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
	AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
	pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);

	/*有效期*/
	if(pMsg->url!=NULL)
	{	
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_SETTINGS_EXPIRES));
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		sprintf( (S8 *)ansiiTempBuff, ":\n%d",(int)(pMsg->expriy_time));
		memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
		AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
		pfnUnicodeStrcat((PS8)UnicodeBuf,(PS8)ucs2TempBuff);
		pfnUnicodeStrcat((PS8)UnicodeBuf,(S8 *)GetString(STR_MMS_HOUR));
	}

	str_len=pfnUnicodeStrlen((PS8)UnicodeBuf);


	EntryNewScreen(screenId, NULL,
				mmi_mms_entry_new_msg_details, NULL);
	
	SetMessagesCurrScrnID(screenId);
	guiBuffer = GetCurrGuiBuffer(screenId);
 
	ShowCategory74Screen(STR_MMS_INBOX_OPTIONS_DETAILS,IMG_MESSAGE_SIM_MMS_MENUENTRY,
							STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS,
							STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
							(PU8)UnicodeBuf, str_len, guiBuffer);
 
	SetLeftSoftkeyFunction(mmi_mms_idle_play_or_down_msg, KEY_EVENT_UP);
	SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
}

void mmi_mms_entry_new_ind(void)
{
	P_MESSAGELIST pMsg = NULL;
	mmi_mms_entry_init_param();
	mmi_mms_exit_new_ind_dummy();
	pMsg = mmi_mms_inbox_find_ind_new_message();
#ifdef SUPPORT_SMSMMS_COMBINE
	if(pMsg->fileName == NULL && (pMsg->url != NULL||pMsg->ota_murl!= NULL))//wap push
	{
		if (pMsg->state == 'U')
		{
			mms_Tracer("read wap push");
			mms_file_manager_set_current_folder(MMS_RECEIVE_FOLDER);
			mms_file_manager_set_current_message(pMsg);
			mms_file_manager_modify_current_message_state(MMS_MSG_STATE_READ);
			mmi_update_mms_idel_icon();
		}
		mmi_mms_view_wap_push_detail();
	}
	else
#endif
	{
		mmi_mms_entry_new_msg_details();
	}
}

  /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 得到需要提示MMS 文件名(以此来查找对应内存节点)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_get_new_msg_file_name(P_MESSAGELIST plist)
{
	/* 将待添加mms的文件名拷贝到新节点中 */
	if(plist->fileName != NULL)
	{
		memset(gNewind_fname, 0, sizeof(gNewind_fname));
		strcpy(gNewind_fname, plist->fileName);
		mmsflag.gnewmsg_idle=TRUE;
		return;
	}
	else if(plist->url != NULL)
	{
		memset(gNewind_fname, 0, sizeof(gNewind_fname));
		strcpy(gNewind_fname, plist->url);
		mmsflag.gnewmsg_idle=TRUE;
		return;
	}
}
  
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_get_new_msg_ind_string
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
U8* mmi_mms_get_new_msg_ind_string (void)
{
	static S8 buffer [120]={0};
	PS8 		name;
	char		ansiiTempBuff[MAX_HINT_BUF*2]={0};
	char		ucs2TempBuff[MAX_HINT_BUF*2]={0};
	P_MESSAGELIST pMsg = NULL;

	pMsg=mmi_mms_inbox_find_ind_new_message();

	if(pMsg->fileName == NULL)//wap push
	{
		return NULL;
	}
	if(pMsg->to_address) 
	{
		pSENDTO_LIST plist = NULL;
		cms_parse_sendto_address(pMsg,SENDTO_TO);
		plist = pgsendtolist;
		memset(ansiiTempBuff,0,sizeof(ansiiTempBuff));
		memset(ucs2TempBuff,0,sizeof(ucs2TempBuff));
		sprintf( (S8 *)ansiiTempBuff, "%s",plist->number);
		mms_mmi_tracer("^_^ind = %s ", (char*)ansiiTempBuff);
		AnsiiToUnicodeString( (PS8)ucs2TempBuff, (PS8)ansiiTempBuff);
		cms_empty_sendto_to_list();
		pgsendtolist=NULL;
	}
	name = lookUpNumber((PS8)ucs2TempBuff);
	if (name  &&  pfnUnicodeStrlen(name))
	{
		mms_Tracer("name");
		pfnUnicodeStrcpy((S8*)buffer, (S8*)name);	
	}
	else
	{
		mms_Tracer("number");
		pfnUnicodeStrcpy((S8*)buffer, (S8*)ucs2TempBuff);
	}
	return (U8*)buffer;
}  
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_exit_new_msg_ind
 *       Purpose: 退出提示界面
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_exit_new_msg_ind()
{
	mmsflag.gnewmsg_idle=FALSE;
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_entry_new_msg_ind
 *       Purpose: 新彩信到来，IDLE界面提示
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_entry_new_msg_ind (void)
{
	U8*				mestr = NULL;
	P_MESSAGELIST 	pMsg = NULL;
	EntryNewScreen(SCR_ID_MSG_NEW_MSG_IND, 
					mmi_mms_exit_new_msg_ind,NULL, NULL);
	
	SetMessagesCurrScrnID(SCR_ID_MSG_NEW_MSG_IND);
	mmsflag.gnewmsg_idle=FALSE;

	pMsg=mmi_mms_inbox_find_ind_new_message();

	if(pMsg->fileName == NULL)//wap push
	{
		mestr = (PU8) GetString (STR_WAP_WAPPUSHARRIVED_ID);
	}
	else
	{
		mestr = (PU8) GetString (STR_MMS_NEW_MESSAGE_FROM);
	}
#ifdef SUPPORT_MTK_6226
	if(g_keylock_context.gKeyPadLockFlag ==0)
#else	
	if(gKeyPadLockFlag==0)
#endif
	{
		ShowCategory154Screen(0, 0,
								STR_SCR6035_LSK, IMG_SMS_COMMON_NOIMAGE,
								STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE,
								(PU8)mestr, 
								(PU8)mmi_mms_get_new_msg_ind_string(),
								IMG_NEW_MESSAGE_NOTIFICATION_MSG, NULL);
			
		SetRightSoftkeyFunction(mmi_mms_exit_to_idle, KEY_EVENT_UP);
		SetLeftSoftkeyFunction(mmi_mms_entry_new_ind, KEY_EVENT_UP);
		SetKeyHandler(mmi_mms_exit_to_idle, KEY_END, KEY_EVENT_DOWN);
	}
	else /* keypad is locked */
	{
           #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
			ShowCategory154Screen(0, 0, 0, 0, KEYPAD_LOCKED_RSK_TEXT, 0,
									(PU8)mestr, 
									NULL,IMG_NEW_MESSAGE_NOTIFICATION_MSG, NULL);
		   
	   #else /* __MMI_KEYPAD_LOCK_PATTERN_2__*/
			ShowCategory154Screen(0, 0, KEYPAD_LOCKED_RSK_TEXT, 0, 0, 0,
									(PU8)GetString (STR_MMS_NEW_MESSAGE_FROM), 
									NULL, IMG_NEW_MESSAGE_NOTIFICATION_MSG, NULL);
	   #endif
	   	ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
	}
 }
 /* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_need_new_msg_ind
 *       Purpose: 是否需要在IDLEl界面提示
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 BOOL mmi_mms_need_new_msg_ind (void)
 {
 	if(mmsflag.gnewmsg_idle)
 	{
 		return TRUE;
 	}
	else
	{
	 	return FALSE ;
	}
 }

#endif


/*-----------------------------------------------------------------------------*/
/* 彩信配置列表       Begin  */
/*-----------------------------------------------------------------------------*/
#if 1
/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 中国移动
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_pre_setting_file_chinamobile()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_CHINAMOBILE);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"China Mobile");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mmsc.monternet.com/");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"10.0.0.172");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_CHINAMOBILE;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_CHINAMOBILE);
	}
}
/***************中国台湾地区运营商彩信配置*********************/
/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 中華電信
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_pre_setting_file_cht()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_CHT);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"CHT");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mms.emome.net:8002");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"010.001.001.001");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_CHT;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_CHT);
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 中華電信
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_pre_setting_file_fet()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_FET);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"FET");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mms/");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"210.241.199.199");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_FET;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_FET);
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 和信電訊
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_pre_setting_file_kgt()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_KGT);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"KGT");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr,(S8*) L"http://mms.kgtmms.net.tw/mms/wapenc");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway,(S8*) L"172.028.033.005");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_KGT;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_KGT);
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 泛亞電信
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_pre_setting_file_tat()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_TAT);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"TAT");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mms/");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"211.078.224.100");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_TAT;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_TAT);
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 東信電訊
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_pre_setting_file_mbt()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_MBT);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"MBT");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mms.mobeelife.net/mms/wapenc");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"192.168.077.005");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_MBT;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_MBT);
	}
}

/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 台灣大哥大
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_pre_setting_file_tcc()
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_TCC);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"TCC");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mms/");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"010.001.001.002");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_TCC;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_TCC);
	}
}
/***************西班牙运营商彩信配置*********************/
/* 西班牙Movistar*/
void mms_init_pre_setting_file_spain_movistar(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_SPAIN_MOVISTAR);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"Movistar");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mms.movistar.com");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"10.138.255.001");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_SPAIN_MOVISTAR;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_SPAIN_MOVISTAR);
	}
}
/* 西班牙Vodafone*/
void mms_init_pre_setting_file_spain_vodafone(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_SPAIN_VODAFONE);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"Vondafone");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mmsc.vodafone.es/servlets/mms");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"212.73.32.10");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_SPAIN_VODAFONE;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_SPAIN_VODAFONE);
	}
}
/* 西班牙Amena*/
void mms_init_pre_setting_file_spain_amena(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_SPAIN_AMENA);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"AMENA");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mms.amena.com");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"172.22.188.25");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_SPAIN_AMENA;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_SPAIN_AMENA);
	}
}
/******************************泰国彩信配置****************************/
/* 泰国AIS*/
void mms_init_pre_setting_file_thailand_ais(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_THAILAND_AIS);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"AIS");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mms.mobilelife.co.th");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"203.170.229.34");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_THAILAND_AIS;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_THAILAND_AIS);
	}
}
/* 泰国DTAC*/
void mms_init_pre_setting_file_thailand_dtac(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_THAILAND_DTAC);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"DTAC");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mms.dtac.co.th:8002");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"203.155.200.133");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_THAILAND_DTAC;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_THAILAND_DTAC);
	}
}
/*泰国Orange*/
void mms_init_pre_setting_file_thailand_orange(void)
{
	S8		tempname[MMS_FILE_NAME_LEN]={0};
	S8		setfilename[MMS_FILE_NAME_LEN]={0};

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)MMS_SERVICE_THAILAND_ORANGE);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));	
	
	if (!Cms_Adp_FileExists((S8*)setfilename))
	{
		pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)L"Orange");
		pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)L"http://mms.orange.co.th:8002");
		pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)L"10.4.7.39");
		pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)L"9201");
		
		gconfigtemp.anonymous = MMS_SETTINGS_OFF;
		gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
		gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
		gconfigtemp.gprs_mode = MMS_SERVICE_THAILAND_ORANGE;
		gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
		mms_write_msg_setting_file_by_index(MMS_SERVICE_THAILAND_ORANGE);
	}
}
#ifdef CMS_PC_CONFIG_SOFTWARE
void mms_init_all_pre_setting_from_pc_file(void)
{
	U8 N_Cfg=0;
	
	for(N_Cfg=0;N_Cfg<cms_mms_profile_default.n_mms_profiles;N_Cfg++)
	{
		if(cms_mms_profile_default.profile[N_Cfg].empty==1)
		{
			S8		tempname[MMS_FILE_NAME_LEN]={0};
			S8		setfilename[MMS_FILE_NAME_LEN]={0};
			S8		tempstr[MMS_MAX_CENTRE_ADDR_LENGTH]={0};
			
			strcpy(setfilename, CMS_MMS_APP_PATH);
			sprintf(tempname,"mms_set_%dfile.txt",(int)N_Cfg);
			strcat(setfilename,tempname );
			memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));

			cms_utf2unicode((unsigned char*)cms_mms_profile_default.profile[N_Cfg].profile_name,\
							strlen((char*)cms_mms_profile_default.profile[N_Cfg].profile_name),\
							(unsigned short*)tempstr,MMS_MAX_CENTRE_ADDR_LENGTH);
			
			pfnUnicodeStrcpy((S8*)gconfigtemp.service_id, (S8*)tempstr);
			
			memset(tempstr,0,MMS_MAX_CENTRE_ADDR_LENGTH);
			AnsiiToUnicodeString((S8 *)tempstr, (S8*)cms_mms_profile_default.profile[N_Cfg].homepage_url);
			pfnUnicodeStrcpy((S8*)gconfigtemp.centre_addr, (S8*)tempstr);
			
			memset(tempstr,0,MMS_MAX_CENTRE_ADDR_LENGTH);
			AnsiiToUnicodeString((S8 *)tempstr, (S8*)cms_mms_profile_default.profile[N_Cfg].proxy_ip);
			pfnUnicodeStrcpy((S8*)gconfigtemp.gateway, (S8*)tempstr);

			memset(tempstr,0,MMS_MAX_CENTRE_ADDR_LENGTH);
			AnsiiToUnicodeString((S8 *)tempstr, (S8*)cms_mms_profile_default.profile[N_Cfg].proxy_port);
			pfnUnicodeStrcpy((S8*)gconfigtemp.port,(S8*)tempstr);

			gconfigtemp.gprs_mode = cms_mms_profile_default.profile[N_Cfg].data_account;	
			gconfigtemp.anonymous = MMS_SETTINGS_OFF;
			gconfigtemp.retrieve_mode = MMS_SETTINGS_RETRIEVE_MANUAL;
			gconfigtemp.prior = MMS_SETTINGS_PRIORITY_NORMAL;
			gconfigtemp.delivery_rpt = MMS_SETTINGS_OFF;
			mms_write_msg_setting_file_by_index(N_Cfg);
		}
	}
	
}
#endif
/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_init_all_pre_setting_file(void)
{
#ifdef CMS_PC_CONFIG_SOFTWARE
	/*客户从移软PC配置软件进行配置*/
	mms_init_all_pre_setting_from_pc_file();
#else
	/*中国移动*/
	if(CmsGetWapSupportArea() == CMS_WAPMMS_SUPPOTR_CHINA)
	{
		mms_init_pre_setting_file_chinamobile();
	}
	/*中国台湾六大运营商*/
	else if(CmsGetWapSupportArea() == CMS_WAPMMS_SUPPOTR_TAIWAN)
	{
		mms_init_pre_setting_file_cht();
		mms_init_pre_setting_file_fet();
		mms_init_pre_setting_file_kgt();
		mms_init_pre_setting_file_mbt();
		mms_init_pre_setting_file_tat();
		mms_init_pre_setting_file_tcc();
	}
	/*西班牙运营商*/
	else if(CmsGetWapSupportArea() == CMS_WAPMMS_SUPPOTR_SPAIN)
	{
		mms_init_pre_setting_file_spain_movistar();
		mms_init_pre_setting_file_spain_vodafone();
		mms_init_pre_setting_file_spain_amena();
	}
	/*泰国运营商*/
	else if(CmsGetWapSupportArea() == CMS_WAPMMS_SUPPOTR_THAILAND)
	{
		mms_init_pre_setting_file_thailand_ais();
		mms_init_pre_setting_file_thailand_dtac();
		mms_init_pre_setting_file_thailand_orange();
	}
	/*客户配置时可以从此往下增加*/
#endif
	mms_set_setting_file_for_default_active();/*默认彩信设定配置*/
}

/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 保存信息设置内容到文件(根据运营商的ID)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_write_msg_setting_file_by_index(U16 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	FS_HANDLE 	fp = 0;
	S8			tempname[MMS_FILE_NAME_LEN]={0};
	S8			setfilename[MMS_FILE_NAME_LEN]={0};
	char* 		buffer = NULL;
	char* 		buffer_pos = NULL;  /* 相对buffer的位置 */
	S32 			max_len = 0, buffer_len = 0, len = 0;
	U16 			rd = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)index);
	strcat(setfilename,tempname );
	
	/* buffer最大长度为地址长度和网关长度之和，另外再分配64个字节 */
	max_len = MMS_MAX_SERVICE_ID_LENGTH+MMS_MAX_CENTRE_ADDR_LENGTH + \
			MMS_MAX_GATEWAY_LENGTH +MMS_MAX_PORT_LENGTH +MMS_MAX_FRAME_TIME_LENGTH+ 64;

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
	*buffer_pos = (S8)MSG_CFG_SERVICE_ID;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gconfigtemp.service_id)+2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gconfigtemp.service_id, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of service_id ***************");
	/*写入彩信中心地址*/
	*buffer_pos = (S8)MSG_CFG_CENTRE;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gconfigtemp.centre_addr)+2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gconfigtemp.centre_addr, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of centre address***************");
	/*写入彩信网关*/
	*buffer_pos = (S8)MSG_CFG_GATEWAY;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gconfigtemp.gateway) + 2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gconfigtemp.gateway, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of gateway***************");
	/*写入彩信端口号*/
	*buffer_pos = (S8)MSG_CFG_PORT;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gconfigtemp.port) + 2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gconfigtemp.port, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of gateway***************");
	/*写入页时间*/
	*buffer_pos = (S8)MSG_CFG_FRAMETIME;
	buffer_pos += 1;
	len = 2*Cms_Browser_Uni16_strlen((P_CMS_BROWSER_U8 )gconfigtemp.frametime) + 2;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	memcpy(buffer_pos, gconfigtemp.frametime, len);
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of frametime***************");
	/*写入有效期*/
	*buffer_pos = (S8)MSG_CFG_EXPIRES;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfigtemp.expires;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of expires***************");
	/*写入发送大小*/
	*buffer_pos = (S8)MSG_CFG_SENDSIZE;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfigtemp.sendsize;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of sendsize***************");
	/*写入接收大小*/
	*buffer_pos = (S8)MSG_CFG_RETRIEVESIZE;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfigtemp.retrievesize;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of retrievesize***************");
	/*写入发送报告*/
	*buffer_pos = (S8)MSG_CFG_REPORT;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfigtemp.delivery_rpt;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of report***************");
	/*写入匿名发送*/
	*buffer_pos = (S8)MSG_CFG_ANONYMOUS;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfigtemp.anonymous;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of anonymous***************");
	/*写入阅读报告*/
	*buffer_pos = (S8)MSG_CFG_READ_RPT;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfigtemp.read_rpt;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of read report***************");
	/*写入优先级*/
	*buffer_pos = (S8)MSG_CFG_PRIORITY;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfigtemp.prior;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of priority***************");
	/*写入接收方式*/
	*buffer_pos = (S8)MSG_CFG_RETRIEVE;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfigtemp.retrieve_mode;
	buffer_pos += len;
	buffer_len += 2+len;
	mms_Tracer((char*)"*****************end of retrieve***************");
	/*写入GPRS设定*/
	*buffer_pos = (S8)MSG_CFG_GPRS;
	buffer_pos += 1;
	len = 1;
	*buffer_pos = (S8)len;
	buffer_pos += 1;
	*buffer_pos = (S8)gconfigtemp.gprs_mode;
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

/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose:  读取信息设置配置存放至gconfigtemp结构的成员中
 * 				 (根据运营商的ID)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */

void mms_read_msg_setting_file_by_index(U16 index)
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
	strcpy(setfilename, CMS_MMS_APP_PATH);
	sprintf(tempname,"mms_set_%dfile.txt",(int)index);
	strcat(setfilename,tempname );
	memset(&gconfigtemp, 0, sizeof(MMS_CONFIG));
	
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
			S8 msg_cfg_field = MSG_CFG_UNKNOWN;
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
			case MSG_CFG_SERVICE_ID:
				if(msg_cfg_field_len != 0)
				{
					memset(gconfigtemp.service_id, 0, MMS_MAX_SERVICE_ID_LENGTH);
					memcpy(gconfigtemp.service_id, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* 彩信中心 */
			case MSG_CFG_CENTRE:
				if(msg_cfg_field_len != 0)
				{
					memset(gconfigtemp.centre_addr, 0, MMS_MAX_CENTRE_ADDR_LENGTH);
					memcpy(gconfigtemp.centre_addr, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* 网关 */
			case MSG_CFG_GATEWAY:
				if(msg_cfg_field_len != 0)
				{
					memset(gconfigtemp.gateway, 0, MMS_MAX_GATEWAY_LENGTH);
					memcpy(gconfigtemp.gateway, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* 端口 */
			case MSG_CFG_PORT:
				if(msg_cfg_field_len != 0)
				{
					memset(gconfigtemp.port, 0, MMS_MAX_PORT_LENGTH);
					memcpy(gconfigtemp.port, ptr_buf, msg_cfg_field_len);
				}
				break;
				/* 页时间 */
			case MSG_CFG_FRAMETIME:
				if(msg_cfg_field_len != 0)
				{	
					memset(gconfigtemp.frametime, 0, MMS_MAX_FRAME_TIME_LENGTH);
					memcpy(gconfigtemp.frametime, ptr_buf, msg_cfg_field_len);
				}
				break;	
				/* 有效期 */
			case MSG_CFG_EXPIRES:
				if(msg_cfg_field_len != 0)
				{
					gconfigtemp.expires= (S32)(*ptr_buf);
				}
				break;
				/* 发送大小 */
			case MSG_CFG_SENDSIZE:
				if(msg_cfg_field_len != 0)
				{
					gconfigtemp.sendsize= (S32)(*ptr_buf);
				}
				break;
				/* 接收大小 */
			case MSG_CFG_RETRIEVESIZE:
				if(msg_cfg_field_len != 0)
				{
					gconfigtemp.retrievesize= (S32)(*ptr_buf);
				}
				break;
				/* 发送报告 */
			case MSG_CFG_REPORT:
				if(msg_cfg_field_len != 0)
				{
					gconfigtemp.delivery_rpt = (S32)(*ptr_buf);
				}
				break;
				/* 匿名发送 */
			case MSG_CFG_ANONYMOUS:
				if(msg_cfg_field_len != 0)
				{
					gconfigtemp.anonymous = (S32)(*ptr_buf);
				}
				break;
				/* 阅读报告 */
			case MSG_CFG_READ_RPT:
				if(msg_cfg_field_len != 0)
				{
					gconfigtemp.read_rpt= (S32)(*ptr_buf);
				}
				break;
				/* 优先级 */
			case MSG_CFG_PRIORITY:
				if(msg_cfg_field_len != 0)
				{
					gconfigtemp.prior = (S32)(*ptr_buf);
				}
				break;
				/* 接收方式 */
			case MSG_CFG_RETRIEVE:
				if(msg_cfg_field_len != 0)
				{
					gconfigtemp.retrieve_mode = (S32)(*ptr_buf);
				}
				break;
				/* GPRS设定 */
			case MSG_CFG_GPRS:
				if(msg_cfg_field_len != 0)
				{
					gconfigtemp.gprs_mode = (S32)(*ptr_buf);
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

/* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_set_curr_file_to_setting(void)
{
	mms_read_msg_setting_file_by_index(ghiliindex);
	{
		memset(gconfig.service_id, 0, MMS_MAX_SERVICE_ID_LENGTH);
		memset(gconfig.centre_addr, 0, MMS_MAX_CENTRE_ADDR_LENGTH);
		memset(gconfig.gateway, 0, MMS_MAX_GATEWAY_LENGTH);
		memset(gconfig.port, 0, MMS_MAX_PORT_LENGTH);
		pfnUnicodeStrcpy((S8*)gconfig.service_id, (S8*)gconfigtemp.service_id);
		pfnUnicodeStrcpy((S8*)gconfig.centre_addr, (S8*)gconfigtemp.centre_addr);
		pfnUnicodeStrcpy((S8*)gconfig.gateway, (S8*)gconfigtemp.gateway);
		pfnUnicodeStrcpy((S8*)gconfig.port,(S8*)gconfigtemp.port);
		gconfig.gprs_mode=gconfigtemp.gprs_mode;

		gconfig.mms_service_activeitem=ghiliindex;
	}
	mms_write_message_settings_file();
	DisplayPopupCallBack((U8*)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, NULL, CMS_MMS_POPUP_DELAY_TIME, SUCCESS_TONE, GoBackHistory);
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
void mms_set_setting_file_for_default_active(void)
{
	mms_read_msg_setting_file_by_index(gconfig.mms_service_activeitem);
	{
		memset(gconfig.service_id, 0, MMS_MAX_SERVICE_ID_LENGTH);
		memset(gconfig.centre_addr, 0, MMS_MAX_CENTRE_ADDR_LENGTH);
		memset(gconfig.gateway, 0, MMS_MAX_GATEWAY_LENGTH);
		memset(gconfig.port, 0, MMS_MAX_PORT_LENGTH);
		pfnUnicodeStrcpy((S8*)gconfig.service_id, (S8*)gconfigtemp.service_id);
		pfnUnicodeStrcpy((S8*)gconfig.centre_addr, (S8*)gconfigtemp.centre_addr);
		pfnUnicodeStrcpy((S8*)gconfig.gateway, (S8*)gconfigtemp.gateway);
		pfnUnicodeStrcpy((S8*)gconfig.port,(S8*)gconfigtemp.port);
		gconfig.gprs_mode=gconfigtemp.gprs_mode;
	}
	mms_write_message_settings_file();
}

#endif

/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_extern_clearuserdata
 *       Purpose: 清除彩信设置文件(恢复出厂设置时调用)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_mms_extern_clearuserdata(void)
{
	char* temp = NULL;
	U16	setnumber=0;
	S8	setfilename[MMS_FILE_NAME_LEN]={0};
#ifndef CMS_RESET_UNDELETE_MMSFILE		
	/*删除收件箱*/
	mms_file_manager_set_current_folder(MMS_RECEIVE_FOLDER);
	mms_file_manager_delete_current_folder();
	
	/*删除草稿箱*/
	mms_file_manager_set_current_folder(MMS_DRAFT_FOLDER);
	mms_file_manager_delete_current_folder();
	
	/*删除发件箱*/
	mms_file_manager_set_current_folder(MMS_SEND_FOLDER);
	mms_file_manager_delete_current_folder();
#endif
	/*如果cmsgconfig.txt 文件不存在，将自动配置默认的彩信设置*/
	temp = Cms_mms_uni8_16((S8*)MESSAGE_SETTINGS_FILE);
	FS_Delete((const WCHAR *)temp);
	mms_Free(temp);
	temp = NULL;
	/*删除网络列表配置文件*/
	for(;setnumber<SERVICE_LIST_ITEM;setnumber++)
	{
		memset(setfilename,0,MMS_FILE_NAME_LEN);
		sprintf(setfilename,MESSAGE_SETTING_GEN,(int)setnumber);
		if(Cms_Adp_FileExists(setfilename))
		{
			Cms_Adp_fdelete((const unsigned short *)(setfilename));
		}
	}
	
}
/* ----------------------------------------------------------------------------
 * Function CmsGetCurrentMmsState: 
 *       Purpose:获取当前彩信状态，是否进入过彩信模块
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
int CmsGetCurrentMmsState()
{
	if(gbmmsflag)
	{
		return CMS_MMS_STATE_BUSY;
	}
	else
	{
		return CMS_MMS_STATE_NULL;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_mms_extern_clearuserdata
 *       Purpose: 清除彩信设置文件(恢复出厂设置时调用)
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void	ClearMmsUserData(void)
{
	mmi_mms_extern_clearuserdata();
}
/* ----------------------------------------------------------------------------
 * Function Name: CmsGetMmsNetState
 *       Purpose: 获取当前彩信网络状态
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int CmsGetMmsNetState(void)
{
	return mmsflag.gsend_recv;
}

//05.11.25 pan add
void mmi_mms_main_quite_to_app(void)
{

	U16	scr_ID = GetMessagesCurrScrnID();
	
	mms_stop_animation();
	
	if (scr_ID == SCR_ID_SENDING_RETRIEVING_MESSAGE)
	{
		mmsflag.gexit_toidle= TRUE;
		mms_cancel_send_retrieve();
	}
	if (mmsflag.gplay_state)
	{
		mmsflag.gplay_state = FALSE;
		pixtel_UI_cancel_timer(mms_play_message_callback);
		mms_stop_music();
	}
	else
	{
		mms_stop_music();
	}

	if (gedit.media_buf)
	{
		switch(gedit.media_type)
		{
		case MMS_TYPE_WAV:
			StopAudioWavStream();
			break;
		case MMS_TYPE_IMY:
			StopAudioStream();
			break;
		case MMS_TYPE_MIDI:
			StopAudioMidiStream();
			break;
		case MMS_TYPE_AMR:
			StopAudioStream();	
			break;
		default:
			break;
		}
		mms_Free(gedit.media_buf);
		gedit.media_buf = NULL;
		gedit.media_len = 0;
		gedit.media_type = 0;
	}
	memset(&gedit, 0, sizeof(TEXT_EDIT));
	
	{
		mmsflag.gnew_message= FALSE;
		mmsflag.gsend_save = FALSE;
		mmsflag.gmms_memory = FALSE;
		mmsflag.gmmsbox_full=FALSE;
		mmsflag.gexit_toidle= FALSE;
		
		pCurFwrReMsg=NULL;
		cms_empty_sendto_list();
		pgsendtolist=NULL;
		pgsendcclist=NULL;
		pgsendbcclist=NULL;
		
		MMSDelAllSlide(gpeditor_doc);
		gpeditor_doc->totalsize = 0;
	

		gbox_operation = 0;
		gsendto_options=0;

		ghiliindex = 0;
		ghiliindex1 = 0;
		gCurActionItem = 0;
		ginput_screen = INPUT_OPTION_UNKNOWN;		
	}
	if (!mmsflag.gsend_recv)
	{
		/*非收发状态*/
		destroy_mms_mem_file_info();
	}
	
	mmi_update_mms_idel_icon();
//	DisplayIdleScreen();

}

#endif
#endif
