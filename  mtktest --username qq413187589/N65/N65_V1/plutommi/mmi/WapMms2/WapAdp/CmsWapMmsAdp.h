
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
 * Module Name: CmsWapMmsAdp.h
 *
 * Module Function: 
 *     Author Name: 
 *     Create Date: 08/25/2005
 *
 *========================================================================
 */
 #ifdef CMS_NEW_APP
 #ifndef _CMSWAPMMSADP_H
#define _CMSWAPMMSADP_H
 /***************************************************************************** 
* Include files 
*****************************************************************************/
#include "WHTTP2Socket.h"
#include "cmshttp.h"
#include "CmsProvisioning.h"
#include "Custom_data_account.h"
#include "DataAccountCommon.h"
#include "DataAccountProt.h"
#include "PhoneBookTypes.h"
#include "MmsResourceData.h"
#include "cms_wap_custom_config.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/*MTK6218*/
//#define SUPPORT_MTK6218 

/*MTK6219*/
//#define SUPPORT_MTK6219 

/*MTK6217*/
//#define SUPPORT_MTK6217 

/*MTK6226*/
#define SUPPORT_MTK_6226				/*定义支持MTK 6226 平台*/	

//#ifdef SUPPORT_MTK_6228
#if defined(USE_SW_PNG_DECODER) || defined(USE_HW_PNG_DECODER_V1)
#define CMS_SURPPORT_PNG			/*定义支持MTK 6228 PNG BMP 图片*/	
#endif
#define CMS_SURPPORT_BMP

//for 26_06A, liukai 20070228
#if defined(UNIRISE25_GEMINI_BB) || defined(SKYWORTH25_06B_BB) || defined(SKYWORTH23_07A_BB)
#define mmi_wgui_register_pen_down_handler  wgui_register_pen_down_handler
#define mmi_wgui_register_pen_up_handler  wgui_register_pen_up_handler
#define mmi_wgui_register_pen_move_handler  wgui_register_pen_move_handler
#define mmi_wgui_register_pen_repeat_handler  wgui_register_pen_repeat_handler

#define mmi_wgui_general_pen_down_hdlr  wgui_general_pen_down_hdlr
#define mmi_wgui_general_pen_up_hdlr  wgui_general_pen_up_hdlr
#define mmi_wgui_general_pen_move_hdlr  wgui_general_pen_move_hdlr
#define mmi_wgui_general_pen_repeat_hdlr  wgui_general_pen_repeat_hdlr

#define mmi_gui_scrollbar_pen_enum  gui_scrollbar_pen_enum
#define mmi_gui_pen_event_param_struct  gui_pen_event_param_struct

#define pixtel_UI_reset_text_clip                         gui_reset_text_clip
#define pixtel_UI_set_font                                gui_set_font
#define pixtel_UI_set_clip                                gui_set_clip
#define pixtel_UI_set_text_clip                           gui_set_text_clip
#define pixtel_UI_color                                   gui_color
#define pixtel_UI_set_text_color                          gui_set_text_color
#define pixtel_UI_move_text_cursor                        gui_move_text_cursor
#define pixtel_UI_print_text                              gui_print_text
#define pixtel_UI_cancel_timer                            gui_cancel_timer
#define pixtel_UI_vertical_scrollbar_translate_pen_event  gui_vertical_scrollbar_translate_pen_event
#define pixtel_UI_horizontal_scrollbar_translate_pen_event  gui_horizontal_scrollbar_translate_pen_event
#define pixtel_UI_start_timer                             gui_start_timer
#define pixtel_UI_BLT_double_buffer                       gui_BLT_double_buffer
#define pixtel_UI_fill_rectangle                          gui_fill_rectangle
#define pixtel_UI_set_horizontal_progress_indicator_range gui_set_horizontal_progress_indicator_range
#define pixtel_UI_set_horizontal_progress_indicator_value gui_set_horizontal_progress_indicator_value
#define pixtel_UI_show_horizontal_progress_indicator      gui_show_horizontal_progress_indicator
#define pixtel_UI_lock_double_buffer                      gui_lock_double_buffer
#define pixtel_UI_create_horizontal_progress_indicator    gui_create_horizontal_progress_indicator
#define pixtel_UI_unlock_double_buffer                    gui_unlock_double_buffer
#define pixtel_UI_set_vertical_scrollbar_range            gui_set_vertical_scrollbar_range
#define pixtel_UI_set_vertical_scrollbar_scale            gui_set_vertical_scrollbar_scale
#define pixtel_UI_set_vertical_scrollbar_value            gui_set_vertical_scrollbar_value
#define pixtel_UI_show_vertical_scrollbar                 gui_show_vertical_scrollbar
#define pixtel_UI_create_vertical_scrollbar               gui_create_vertical_scrollbar
#define pixtel_UI_push_clip                               gui_push_clip
#define pixtel_UI_set_text_border_color                   gui_set_text_border_color
#define pixtel_UI_print_truncated_borderd_text            gui_print_truncated_borderd_text
#define pixtel_UI_pop_clip                                gui_pop_clip
#define pixtel_UI_show_image                              gui_show_image
#define pixtel_UI_get_character_width                     gui_get_character_width
#define pixtel_UI_draw_rectangle                          gui_draw_rectangle
#define pixtel_UI_line                                    gui_line
#define pixtel_UI_wline                                   gui_wline
#define pixtel_UI_get_character_height  gui_get_character_height
#endif
//end 26_06A

/***************************************************************************** 
* Define
*****************************************************************************/
/*定义移软PC配置软件进行配置*/
#define  CMS_PC_CONFIG_SOFTWARE
//#define IA_JAVA_NOTIFY							/*IA java  notify from cms notify*/
/*网络账户设定*/
#define GPRS_NET_ACCOUNT						MAX_GPRS_PROFILE_NUM
#define GSM_NET_ACCOUNT  						CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#define DEFAULTNETACCID 						CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM//GSM_NET_ACCOUNT+4 /*中国移动默认GPRS账号GPRS设置五*/
/*Socket数据处理*/
#define RECVDATABUF 							1500 
#define RECV_BUFLEN  							1024

/*WAPMMS模块内存预分配*/
#define WAPMMS_MEMORY_SZIE 					800*1024/*WAPMMS初始化分配800K 内存*/
#define WAP_DOWNLOAD_MAX_SIZE 				256*1024/*浏览器最大可下载文件定义*/
#define WAP_JAD_MAX_SIZE						100*1024
#define MAXSTOREOFFLINE 			 			5		/*快照条数*/
#define CMS_SNAPSHOT_SIZE						160*1024/*存放快照*/ //mod by danny 20080215
#define CMS_CACHEDATABUF 						80*1024	/*浏览器Cache Size*/ //mod by danny 20080215
#define CMS_COOKIEBUFFER_LENGTH 				10*1024 /*存储Cookie空间*/

/*浏览页面时是否显示状态栏*/
#define NO_SHOW_STATEBAR						/*浏览时是否显示状态栏*/
//#define WAP_SHOW_ACROSS_SCOLLBAR			/*浏览时是否显示横向滚动条*/
//#define SUPPORT_STAR_PAGEUPDOWN				//*键支持下翻页，#键支持上翻页
/*彩信浏览器账号列表控制*/
#define MMS_MAX_GSM_ACCOUNT_NUM			10			/*平台GSM 账号资料个数*/
#define MMS_MAX_GPRS_ACCOUNT_NUM			10			/*平台GPRS账号资料个数*/
#define SERVICE_LIST_ITEM						10			/*编辑设置项列表个数*/
#define MMS_SERVICE_ACTIVE_ITEM				0			/*彩信当前激活的配置*/
#define WAP_SERVICE_ACTIVE_ITEM				0			/*浏览器当前激活的配置*/

/*彩信浏览器相关文件存储路径控制*/
/*Modify sys and user disk Begin */
#ifdef NAND_SUPPORT
#define CMS_SYS_DISK							"D:\\\\"			/*mms&wap sys disk*/
#define CMS_USER_DISK							"D:\\\\"			/*mms&wap user data disk*/
#define CMS_MMS_DIR_PATH						L"D:\\mms"		/* 彩信目录路径(for create dir) */
#define CMS_WAP_DIR_PATH						L"D:\\wap"		/* WAP浏览器目录路径(for create dir) */
#define CMS_SYSDISK_SPACE						"D:\\"			/*system 磁盘空间路径	*/
#define CMS_USERDISK_SPACE					"D:\\"			/*User  磁盘空间路径	*/
#else
#define CMS_SYS_DISK							"C:\\\\"			/*mms&wap sys disk*/
#define CMS_USER_DISK							"C:\\\\"			/*mms&wap user data disk*/
#define CMS_MMS_DIR_PATH						L"C:\\mms"		/* 彩信目录路径(for create dir) */
#define CMS_WAP_DIR_PATH						L"C:\\wap"		/* WAP浏览器目录路径(for create dir) */
#define CMS_SYSDISK_SPACE						"C:\\"			/*system 磁盘空间路径	*/
#define CMS_USERDISK_SPACE					"C:\\"			/*User  磁盘空间路径	*/
#endif
/*Modify sys and user disk end */

#define CMS_MMS_APP_PATH						CMS_SYS_DISK##"mms\\\\"	/* 彩信目录路径 */
#define CMS_WAP_APP_PATH						CMS_SYS_DISK##"wap\\\\"		/* WAP浏览器目录路径 */
#define CMS_WAP_DOWNLOAD_PATH				CMS_USER_DISK				/* WAP浏览器保存下载文件路径 */
#define CMS_MMS_IMAGE_SAVE_PATH				CMS_USER_DISK##"Images\\\\"				/* 彩信图片保存 目录路径 */
#define CMS_MMS_AUDIO_SAVE_PATH				CMS_USER_DISK##"Audio\\\\"				/* 彩信音乐保存 目录路径 */
#define CMS_MMS_ACCESSORY_SAVE_PATH			CMS_USER_DISK				/* 彩信附件保存 目录路径 */
#define CMS_WAP_DOWNLOAD_PIC_PATH			CMS_USER_DISK##"Images\\\\"			/* WAP浏览器保存下载图片文件路径 */
#define CMS_WAP_DOWNLOAD_MUSIC_PATH		CMS_USER_DISK##"Audio\\\\"			/* WAP浏览器保存下载声音文件路径 */
#define CMS_WAP_DOWNLOAD_VIDEO_PATH		CMS_USER_DISK##"Video\\\\"			/* WAP浏览器保存下载视频文件路径 */
#define WAP_BOOKMARK_FILENAME				CMS_WAP_APP_PATH##"CmsBook.cnf"		/*浏览器书签文件*/
#define WAP_DEFAULT_BOOKMARK_FILENAME		CMS_WAP_APP_PATH##"CmsBookMarkFile.cnf"	/*浏览器默认书签文件*/
#define WAP_SETUP_FILENAME					CMS_WAP_APP_PATH##"CmsSetup.cnf"		/*浏览器设置文件*/
#define WAP_PUSH_FILENAME					CMS_WAP_APP_PATH##"CmsPushFile.cnf"		/*浏览器服务信息文件*/
#define WAP_CACHE_FILENAME					CMS_WAP_APP_PATH##"CmsCacheFile.cnf"	/*浏览器缓存文件*/
#define WAP_OFFLINE_FILENAME					CMS_WAP_APP_PATH##"CmsBrwOffline.cnf"	/*浏览器离线浏览文件*/
#define WAP_HISTORY_FILENAME					CMS_WAP_APP_PATH##"CmsBrwHistory.cfg"	/*浏览器历史纪录文件*/
#define WAP_COOKIE_FILENAME					CMS_WAP_APP_PATH##"CmsCookie.cnf"		/*浏览器Cookie 文件*/

/*彩信设置文件名与版本控制相关*/
#define MESSAGE_SETTINGS_FILE					CMS_SYS_DISK##"mms\\\\cms_"##MMS_WAP_VERSION"_msgconfig.txt"	/* 信息设置备份文件 */
#define MESSAGE_SETTING_GEN					CMS_SYS_DISK##"mms\\\\mms_set_%dfile.txt"	/* 清除时生成信息文件名 */
#define MESSAGE_RMF_FILE						CMS_MMS_APP_PATH##"rmf.txt"		/*收件箱摘要文件*/
#define MESSAGE_SMF_FILE						CMS_MMS_APP_PATH##"smf.txt"	/*发件箱摘要文件*/
#define MESSAGE_DMF_FILE						CMS_MMS_APP_PATH##"dmf.txt"	/*草稿箱摘要文件*/
/*彩信接入点默认设置*/
#define MMS_CMCC_CENTER_ADDRESS			L"http://mmsc.monternet.com/"		/*彩信中心地址	*/
#define MMS_CMCC_GATEWAY					L"10.0.0.172"						/*彩信网关			*/
#define MMS_CMCC_PORT						L"9201"							/*网关端口号		*/
#define MMS_DEFAULT_FRAME_TIME				L"5"								/*默认页时间		*/

/*浏览器接入点默认设置*/
#define WAP_CMCC_GATEWAY_ADDRESS_DEFAULT	L"10.0.0.172"		/*浏览器网关中心地址	*/
#define WAP_CMCC_GATEWAY_PORT_DEFAULT		80		              /*浏览器网关端口号默认	*/

/*是否需要开启WAPMMS模块MMI Tracer*/
#define TRACE_FOR_MTK					/*定义是否开启Trace*/	

#define SUPPORT_MTK_PLATFORM					/*定义支持MTK 平台*/	

//#define CMS_RESET_UNDELETE_MMSFILE			/*恢复出厂设置时是否删除彩信文件*/

//#define CMS_RESET_UNDELETE_WAPPUSHFILE		/*恢复出厂设置时是否删除浏览器PUSH 文件*/

/********************以下是支持的国家及地区运营商配置****************************/
#define CURRENT_WAP_SUPPORT_AREA				CMS_WAPMMS_SUPPOTR_CHINA/*定义当前出口地*/

typedef enum
{
	CMS_WAPMMS_SUPPOTR_CHINA,			//中国大陆
	CMS_WAPMMS_SUPPOTR_TAIWAN,			//中国台湾
	CMS_WAPMMS_SUPPOTR_HONGKONG,		//中国香港
	CMS_WAPMMS_SUPPOTR_THAILAND,		//泰国
	CMS_WAPMMS_SUPPOTR_SPAIN,			//西班牙
	CMS_WAPMMS_SUPPOTR_FRANCE,			//法国
	CMS_WAPMMS_SUPPOTR_ENGLISH,		//英国
	CMS_WAPMMS_SUPPOTR_ITALY,			//意大利
	CMS_WAPMMS_SUPPOTR_GERMANY,		//德国
	CMS_WAPMMS_SUPPOTR_MEXICO,			//墨西哥
	CMS_WAPMMS_SUPPOTR_INDIA,			//印度
	/*客户可在此处增加后续国家*/
	CMS_WAPMMS_AREA_NUM	
}CMS_WAPMMS_SUPPORT_AREA;	



#ifdef TRACE_FOR_MTK
#define wap_Tracer(str)     				cms_wap_Tracer((char*)str)
#define browser_mmi_tracer(data,data1)    cms_browser_mmi_tracer((char*) data, (char*)data1)
#define adp_Tracer(str) 	 				cms_adp_Tracer((char*)str)
#ifdef SUPPORT_CMS_SYNCML_MODULE
#define syn_Tracer(str)	 				cms_syncml_Tracer((char*)str)
#endif
#define adp_mmi_tracer(data,data1)		cms_adp_mmi_tracer((char*) data, (char*)data1)
#define mms_mmi_tracer(data,data1)		cms_mms_mmi_tracer((char*) data, (char*)data1)
#ifdef SUPPORT_CMS_SYNCML_MODULE
#define syn_mmi_tracer(data,data1)		cms_syncml_mmi_tracer((char*) data, (char*)data1)
#endif
#else
#define wap_Tracer(str) 
#define browser_mmi_tracer(data,data1)
#define adp_Tracer(str) 
#define adp_mmi_tracer(data,data1)
#define mms_mmi_tracer(data,data1)
#ifdef SUPPORT_CMS_SYNCML_MODULE
#define syn_Tracer(str)
#define syn_mmi_tracer(data,data1)
#endif
#endif

typedef enum
{
	CMS_MMS_STATE_NULL,	//不在彩信模块
	CMS_MMS_STATE_BUSY 	//已进入彩信模块
}CMS_MMS_STATE;

typedef enum
{
	CMS_WAP_STATE_NULL,	//不在浏览器模块
	CMS_WAP_STATE_BUSY	//已进入浏览器模块
}CMS_WAP_STATE;

typedef enum
{
	CMS_WAP_CONNECT_WAP,	//浏览器连接模式WAP1.2.1
	CMS_WAP_CONNECT_HTTP	//浏览器连接模式HTTP
}CMS_WAP_CONNECT_MODE;	

typedef enum
{
	CMS_PHB_NULL,	//电话本标志为空
	CMS_PHB_MMS,	//彩信模块进入电话本
	CMS_PHB_EMAIL,	//电邮模块进入电话本
	CMS_PHB_SYNC	//同步模块进入电话本
}CMS_PHB_TYPE;

typedef unsigned char		CMS_BROWSER_U8;			/*=== unsigned 8 bit data  ===*/
typedef unsigned short		CMS_BROWSER_U16;		/*=== unsigned 16 bit data ===*/
typedef unsigned int		CMS_BROWSER_U32;		/*=== unsigned 32 bit data ===*/
typedef unsigned long		CMS_BROWSER_U64;		/*=== unsigned 64 bit data ===*/
typedef char			    	CMS_BROWSER_S8;			/*=== signed 8 bit data  ===*/
typedef short	        		CMS_BROWSER_S16;		/*=== signed 16 bit data ===*/
typedef int		        	CMS_BROWSER_S32;		/*=== signed 32 bit data ===*/
typedef long	    			CMS_BROWSER_S64;		/*=== signed 64 bit data ===*/

typedef CMS_BROWSER_U8 *	P_CMS_BROWSER_U8;
typedef CMS_BROWSER_U16 *	P_CMS_BROWSER_U16; 
typedef CMS_BROWSER_U32 *	P_CMS_BROWSER_U32;
typedef CMS_BROWSER_U64 *	P_CMS_BROWSER_U64;  
typedef CMS_BROWSER_S8 *	P_CMS_BROWSER_S8;
typedef CMS_BROWSER_S16 *	P_CMS_BROWSER_S16;  
typedef CMS_BROWSER_S32 *	P_CMS_BROWSER_S32; 
typedef CMS_BROWSER_S64 *	P_CMS_BROWSER_S64;

#ifdef SUPPORT_MTK_PLATFORM
#define MMS_FILE_HANDLE FS_HANDLE
#else
#define MMS_FILE_HANDLE FILE_HANDLE
#endif

void mms_Tracer(char* pData);
long CmsGetCurrentTime(void);
void CTLprovisioning(P_CMS_SETTING pBrowerSetting,P_CMS_BOOKMARK pBookmarkSetting);

void cms_socket_notify(void* inMsg);
void cms_gethost_by_name_notify(void* inMsg);

void mms_NetConnect(void);
void mms_NetDisconnect(void);
void Cms_SendPDU(void *pp_data,long vp_length,unsigned char *host,int port);
void Cms_RecvPDU(void *pp_data,long *pp_length,unsigned char *host,int port);
int sms_socket_retcode(kal_int8 ret);
static void mms_net_data_init(void);
void cms_net_mms_data_init_again(unsigned char* ip_addr, unsigned short port);
void SocketStart(int flag);
void sms_recv_data(void);
void  Cms_Reset_Soc(void);
int  Cms_close_soc(int flag);

pBOOL		Cms_Adp_FileExists(S8* filename);
int			Cms_Adp_fopen(S8* FileName, unsigned int Flag);
int			Cms_Adp_fclose(MMS_FILE_HANDLE FileHandle);
int			Cms_Adp_GetFileSize (MMS_FILE_HANDLE FileHandle, unsigned int * Size);
int			Cms_Adp_fread(MMS_FILE_HANDLE FileHandle, void * DataPtr, unsigned int Length, unsigned int * Read);
int			Cms_Adp_fwrite(MMS_FILE_HANDLE FileHandle, void * DataPtr, unsigned int Length, unsigned int * Written);
int			Cms_Adp_fdelete(const unsigned short * FileName);
long		Cms_Return_Mms_MaxSize(void);
BOOL 	Cms_Adp_JudgeDSpace(int size);
BOOL 	Cms_Adp_JudgeCSpace(int size);

void mmi_cms_search_phb_callback(MMI_PHB_VCARD_STRUCT *entity);
void mmi_cms_entry_search_from_phb(void);
char *		Cms_mms_uni8_16(char *buf_utf8);
char *		Cms_mms_uni16_8(char *buf_uni);
void		Cms_Browser_Uni8_16(P_CMS_BROWSER_U8 uni_8,P_CMS_BROWSER_U8 uni_16);
char *		Cms_mms_uni8_16_2Sub(char *buf_utf8);
CMS_BROWSER_U32 Cms_Browser_Uni16_Uni8_strlen_big(P_CMS_BROWSER_U8 string);
CMS_BROWSER_U32 Cms_Browser_Uni8_strlen(P_CMS_BROWSER_U8 string);
CMS_BROWSER_U32 Cms_Browser_Uni16_strlen(P_CMS_BROWSER_U8 string);
CMS_BROWSER_VOID Cms_Browser_Uni8_16_big(P_CMS_BROWSER_U8 uni_8,P_CMS_BROWSER_U8 uni_16);
 CMS_BROWSER_U32 mmi_get_utf16_width(CMS_BROWSER_U8 font,CMS_BROWSER_U16 Utf16);
CMS_BROWSER_VOID Cms_Browser_Uni16_8_big(P_CMS_BROWSER_U8 uni_16_8, P_CMS_BROWSER_U8 uni_8);
CMS_BROWSER_VOID Cms_Browser_Uni16_8(P_CMS_BROWSER_U8 uni_16_8, P_CMS_BROWSER_U8 uni_8);

void cms_init_mem_pool(void);
BOOL cms_check_mem_size(S32 mem_size);
void CMS_itoa_unicode(U16 i, char* str);

void cms_mms_mmi_tracer(kal_char * data, kal_char * data1);
void cms_adp_mmi_tracer(kal_char * data, kal_char * data1);
void cms_adp_Tracer(kal_char * data);
void cms_syncml_mmi_tracer(kal_char * data, kal_char * data1);
void cms_syncml_Tracer(kal_char * data);
void Cms_hex_trace(kal_uint8 *buf,kal_int32 pdu_len);
void cms_browser_mmi_tracer(kal_char * data, kal_char * data1);
void cms_wap_Tracer(kal_char * data);
int mmsGetNetType(void);
int Cms_Brower_GetSecuritySetting( void );
int Cms_Mms_GetSecuritySetting( void );
void Cms_Browser_ReadOfflineRecord(void);
CMS_BROWSER_U32 Cms_Wap_GetOfflineNum(void);
void CmsProcessIdleEvent(void);
int Cms_GetDownloadMaxSize(void);
int Cms_GetJadMaxSize(void);
unsigned char* Cms_GetResourceByID(int infoId);
void CmsTime2String(S8* datetime);
CMS_BROWSER_S32 Cms_GetLINE_HIGHT(CMS_BROWSER_VOID);
CMS_BROWSER_S32 Cms_GetSCREEN_LINE(CMS_BROWSER_VOID);
CMS_BROWSER_S32 Cms_GetORIGIN_Y(CMS_BROWSER_VOID);
void Cms_StopMusic (void);
P_CMS_BROWSER_U8 Cms_Browser_GetOfflineTitleById(CMS_BROWSER_U32 inputid);
void cms_Brw_Offline_Browser(CMS_BROWSER_U32 id);
int Cms_Browser_GetMusicSetting( void );
void Cms_Browser_SetupMusicOn(void);
void Cms_Browser_SetupMusicOff(void); 	 
int Cms_Browser_GetPushMessageSetting( void );
void Cms_Browser_SetupPushMessageOn(void);
void Cms_Browser_SetupPushMessageOff(void) ;
void Cms_Browser_SetupSecurityOn(void);
void Cms_Browser_SetupSecurityOff(void);
void Cms_Browser_SetupNetTypeHttp(void);
void Cms_Browser_SetupNetTypeWap(void);
int Cms_Browser_SavePageSize(void);
CMS_BROWSER_VOID Cms_Browser_Delete_Offline(CMS_BROWSER_U32 id);
CMS_BROWSER_VOID Cms_Browser_DeleteAll_Offline(CMS_BROWSER_VOID);
void Cms_Browser_WriteOfflineRecord(void);
int cms_getpictogram(char *pict_name,	Cms_ContentType_e  *pict_type,	unsigned	int	  *pict_size,unsigned	char **pict_content );
S32 Cms_GetCacheBlockLength(void);
void initaccountfuc(void);
void Cms_Dataaccount_Init(void);
int	CmsGetWapSupportArea(void);
void WmlTimerOut(void *time);
int Cms_Browser_GetImageSetting( void );
void Cms_GetWapSetupfilename(unsigned char *filename);
void Cms_GetWapBookfilename(unsigned char *filename);
void Cms_GetWapBookmarkfilename(unsigned char *filename);
void Cms_GetWapPushfilename(unsigned char *filename);
void Cms_GetWapCachefilename(unsigned char *filename);
void Cms_GetWapOfflinefilename(unsigned char *filename);
void Cms_GetWapHistoryfilename(unsigned char *filename);
void Cms_GetWapCookiefilename(unsigned char *filename);
CMS_BROWSER_S32 Cms_GetFONT_W(void);
 #endif /*_CMSWAPMMSADP_H*/
 #endif
