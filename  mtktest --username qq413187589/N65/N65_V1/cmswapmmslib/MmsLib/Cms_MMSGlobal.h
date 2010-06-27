/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: bloble.h

    $Revision:

    $vision:       1.00

    $Date:         08/10/2002

    $Author:       hulf

	$Declare:
	This document contains information proprietary to MobileSoft
 Technology (Nanjing),  Corp.    Transmittal, receipt, or possession
 of this document does not express, license, or imply any rights to
 use, sell, design, or manufacture from this information. No reproduction,
 publication, or disclosure of this information, in whole or in part,
 shall be made without prior written authorization from an officer of
 MobileSoft Technology (NanJing), Corp.

Abstract:

Modified By:

Environment:

Revision History:

=====================================================================*/




#ifndef _GLOBLE_H_
#define _GLOBLE_H_
#include "Cms_callback.h"//  Modified by TIPrj[2005/7/14]  
//#include "resource.h"

//#include "Cms_MMSMain.h"
//#include "Cms_MMSSmil.h"

//系统函数的使用均在这里


/*
#define MMSSTRING_DIALOGCOMPANY				"移软科技(南京)欢迎您使用此软件！"
#define MMSSTRING_SHOWRFOLDER				"收件箱内有%d条消息，%d条未读。"
#define MMSSTRING_SHOWSFOLDER				"发件箱内有%d条消息，%d条未发送。"
#define MMSSTRING_SHOWDFOLDER				"草稿箱内有%d条消息。"
#define MMSSTRING_NCMESSAGE					"没有当前消息！"
#define MMSSTRING_SPEEDSLOW					"缓慢"
#define MMSSTRING_SPEEDNORMAL				"普通"
#define MMSSTRING_SPEEDFAST					"紧急"
#define MMSSTRING_DOPEN						"打开"
#define MMSSTRING_NOEMPTY					"收件人和主题都不能为空！"
#define MMSSTRING_MM						"多媒体短消息"
#define MMSSTRING_MM_1						"多媒体短消息(smil)\0*.smil\0\0"
#define MMSSTRING_MM_2						"多媒体短消息(wml)\0*.wml\0\0"
#define MMSSTRING_IMAGEFILE					"图象文件\0*.wbmp;*.gif;*.jpg;*.jpeg\0\0"
#define MMSSTRING_VOICEFILE					"音频文件\0*.wav;*.amr;*.imy\0\0"
#define MMSSTRING_SAVETODRAFT				"需要保存到草稿箱吗？"
#define MMSSTRING_NOTEXT					"文本内容不能为空！"
#define MMSSTRING_INUTTEXT					"输入文本"
#define MMSSTRING_ERRORINPUT				"输入错误！"
#define MMSSTRING_SETCONTENT				"内容设置"
#define MMSSTRING_SETFRAME					"帧设置"
#define MMSSTRING_SETDOCUMENT				"文档设置"
#define MMSSTRING_CEVENTFAILED				"创建事件失败!"
#define MMSSTRING_NOWAVE					"所指定的文件不是有效的wave音频流文件"
#define MMSSTRING_CTHREADFAILED1			"创建播放线程失败"
#define MMSSTRING_CTHREADFAILED2			"创建解码线程失败"
#define MMSSTRING_REVENTFAILED				"重设事件失败"
*/
/*
#define MMSSTRING_DELETEMSG					"真的要删除这条消息吗？"
#define MMSSTRING_MSGSENDOUT				"消息已发出！"
#define MMSSTRING_MSGUNKNOWNERROR			"不明确的错误！"
#define MMSSTRING_SERVICEDENIED				"服务拒绝！"
#define MMSSTRING_FORMATERROR				"格式错误！"
#define MMSSTRING_ADDRESSERROR				"地址错误！"
#define MMSSTRING_NOMSGERROR				"没有消息错误！"
#define MMSSTRING_NETWORKERROR				"网络错误！"
#define MMSSTRING_NOTACCEPTERROR			"对方不接收"
#define MMSSTRING_UNSUPPORTERROR			"不支持消息"
#define MMSSTRING_NBSERROR					"网络忙！发送消息失败！\r\n需要重发吗？"
#define MMSSTRING_NBCERROR					"网络忙！接收消息失败！\r\n需要重收吗？"
#define MMSSTRING_NOBJERROR                 "错误！所请求的对象不存在！"
*/
/*
#define MMSSTRING_NMSGCOMMING				"一条新消息！"
#define MMSSTRING_RECEIVINGMSG				"正在接收消息..."
#define MMSSTRING_MSGRECEIVED				"消息已收到！"
#define MMSSTRING_DI1						"彩信：\r\n到：%s；\r\n日期：%s;\r\n"
#define MMSSTRING_MSGISRECEIVED				"对方已收到！"
#define MMSSTRING_MSGISREJECTED				"消息被拒收！"
#define MMSSTRING_MSGISEXPIRED				"消息已过期！"
#define MMSSTRING_MSGISDEFERRED				"消息被延期！"
#define MMSSTRING_MSGNOTARRIVE				"消息无法传输！"
*/


/*
#define MMSSTRING_GPRSWAITING				"网络正在等待资源，请稍候！"
#define MMSSTRING_GPRSERROR					"网络连接错误！"
#define MMSSTRING_NOUSABLENETERROR			"错误：\r\n没有可用的WAP连接！"
#define MMSSTRING_GPRSFAILED				"网络连接失败，请稍候！"
#define MMSSTRING_GPRSRETRY					"网络连接失败，重试？"
*/
/*
#define MMSSTRING_MSGFORMATERROR			"消息格式错误！"
#define MMSSTRING_MSGNOCONTENT				"消息没有内容！"
#define MMSSTRING_LARGE						"较大"
#define MMSSTRING_NORMAL					"一般"
#define MMSSTRING_SMALL						"较小"
*/
/*
#define MMSSTRING_SENDINGMSG				"正在发送消息..."
#define MMSSTRING_RECEIVEDPUSH				"收到一条PUSH消息！"
#define MMSSTRING_SENDINGRESP				"正在发送响应..."
#define MMSSTRING_SENDINGAKCN				"正在发送报告..."
#define MMSSTRING_CONNECTINGGW				"正在连接WAP网关..."
#define MMSSTRING_CHECKINGNETWORK			"正在检查网络..."
#define MMSSTRING_SEARCHGPRS				"正在查找网络..."
#define MMSSTRING_ESTABLISHGPRS				"正在连接网络..."
#define MMSSTRING_NETWORKOK					"网络连接成功！"
*/
/*
#define MMSSTRING_GETTIMEERROR				"获取时间错误！"
#define MMSSTRING_RMSGFIRST					"请先收取消息！"
#define MMSSTRING_SELECTFILE				"请选择文件："

#define MMSSTRING_NOLASTFRAME				"没有上一帧！"
#define MMSSTRING_NONEXTFRAME				"没有下一帧！"

#define MMSSTRING_SENDER					"发送人："
#define MMSSTRING_RECEIVER					"接收人："
#define MMSSTRING_DATE						"日   期："
#define MMSSTRING_TITLE						"主   题："

#define MMSSTRING_RECVFAILED				"接收消息失败！"
#define MMSSTRING_AUTORECVFAILED			"自动接收失败！"
#define MMSSTRING_STOREMEMORYLOW			"存储空间严重不足！"

#define MMSSTRING_IMAGETOOLARGE				"对不起，图片尺寸过大！"
#define MMSSTRING_ONEIMAGEONLY				"对不起，一页只能含有一个图片！"
#define MMSSTRING_ONETEXTONLY				"对不起，一页只能含有一段文本！"

#define MMSSTRING_EDITORSTATUS				"消息共%d帧，当前第%d帧！"
#define MMSSTRING_ESTATUSREADY				"就绪！"
#define MMSSTRING_ESTATUSEMPTYMSG			"新消息！"

#define MMSSTRING_PHONEADDRESSEMOTY				"此联系人手机号码为空！"
#define MMSSTRING_EMAILADDRESSEMOTY				"此联系人电子邮箱为空！"
#define MMSSTRING_ADDRESSEXIST					"此联系人已经存在！"

#define MMSSTRING_ADDRESSUNKNOEWN				"未命名"
#define MMSSTRING_ADDRESSNAME					"姓名"
#define MMSSTRING_ADDRESSEMAIL					"电子邮箱"
#define MMSSTRING_ADDRESSPHONE					"移动电话"
*/
#define		GWL_HINSTANCE -2
#define		MENU_HEIGHT 26
#define     MMS_FILE_NAME_LEN  128//max length of file name


//#define		RUN_ON_POCKETPC
//#define		PUSH_OVER_SMS
//#define		_MMS_DEBUG_

/****************************** Basic Data types *****************************/
/*------------------------------------------------------------------------
 *
 *
 *
 *						struct padding
 *
 *
 *
------------------------------------------------------------------------*/
#ifndef CENT_FILL_FIELD1
#define CENT_FILL_FIELD1  char  unuseful1;
#endif

#ifndef CENT_FILL_FIELD2
#define CENT_FILL_FIELD2  char  unuseful1;\
							char  unuseful2;
#endif

#ifndef CENT_FILL_FIELD3
#define CENT_FILL_FIELD3  char  unuseful1;\
							char unuseful2; \
						char unuseful3;
#endif

/* Typedefs for integer types */

#ifndef TRUE 
#define TRUE 1
#endif

#ifndef FALSE 
#define FALSE 0
#endif

#ifndef     MMSHANDLE
#define		MMSHANDLE		void*
#endif
typedef unsigned int COLOR;
#ifndef RGB
	#define RGB(r,g,b)	((CMS_MMS_U32)((CMS_MMS_U8)r|(CMS_MMS_U32)((CMS_MMS_U8)g<<8)|(CMS_MMS_U32)((CMS_MMS_U8)b<<16)))
#endif



/*------------------------------------------------------------------------
 *
 *
 *
 *                 不同的MMS头字段宏定义
 *
 *
 *
------------------------------------------------------------------------*/
#ifndef     MMS_BCC
#define		MMS_BCC					0x01
#endif

#ifndef		MMS_CC
#define		MMS_CC					0x02
#endif

#ifndef		MMS_CONTENT_LOCATION
#define		MMS_CONTENT_LOCATION	0x03
#endif

#ifndef		MMS_CONTENT_TYPE
#define		MMS_CONTENT_TYPE		0x04
#endif

#ifndef		MMS_DATE	
#define		MMS_DATE				0x05
#endif

#ifndef		MMS_DELIVERY_REPORT
#define		MMS_DELIVERY_REPORT		0x06
#endif

#ifndef		MMS_DELIVERY_TIME
#define		MMS_DELIVERY_TIME		0x07
#endif

#ifndef		MMS_EXPIRY
#define		MMS_EXPIRY				0x08
#endif

#ifndef		MMS_FROM
#define		MMS_FROM				0x09
#endif

#ifndef		MMS_MESSAGE_CLASS
#define		MMS_MESSAGE_CLASS		0x0a
#endif

#ifndef		MMS_MESSAGE_ID
#define		MMS_MESSAGE_ID			0x0b
#endif

#ifndef		MMS_MESSAGE_TYPE
#define		MMS_MESSAGE_TYPE		0x0c
#endif

#ifndef		MMS_MMS_VERSION
#define		MMS_MMS_VERSION			0x0d
#endif

#ifndef		MMS_MESSAGE_SIZE
#define		MMS_MESSAGE_SIZE		0x0e
#endif

#ifndef		MMS_PRIORITY
#define		MMS_PRIORITY			0x0f
#endif

#ifndef		MMS_READ_REPLY
#define		MMS_READ_REPLY			0x10
#endif

#ifndef		MMS_REPORT_ALLOWED
#define		MMS_REPORT_ALLOWED		0x11
#endif

#ifndef		MMS_RESPONSE_STATUS
#define		MMS_RESPONSE_STATUS		0x12
#endif

#ifndef		MMS_RESPONSE_TEXT
#define		MMS_RESPONSE_TEXT		0x13
#endif
#ifndef		MMS_SENDER_VISIBILITY
#define		MMS_SENDER_VISIBILITY	0x14
#endif

#ifndef		MMS_STATUS
#define		MMS_STATUS				0x15
#endif

#ifndef		MMS_SUBJECT
#define		MMS_SUBJECT				0x16
#endif

#ifndef		MMS_TO
#define		MMS_TO					0x17
#endif

#ifndef		MMS_TRANSACTION_ID
#define		MMS_TRANSACTION_ID		0x18
#endif


/*------------------------------------------------------------------------
 *
 *
 *
 *                 MMS消息类型值宏定义
 *
 *
 *
------------------------------------------------------------------------*/
#ifndef		MMS_MESSAGE_TYPE_SEND_REQ
#define		MMS_MESSAGE_TYPE_SEND_REQ			128
#endif

#ifndef     MMS_MESSAGE_TYPE_SEND_CONF
#define		MMS_MESSAGE_TYPE_SEND_CONF			129
#endif
#ifndef     MMS_MESSAGE_TYPE_NOTIFICATION_IND
#define		MMS_MESSAGE_TYPE_NOTIFICATION_IND	130
#endif

#ifndef     MMS_MESSAGE_TYPE_NOTIFYRESP_IND
#define		MMS_MESSAGE_TYPE_NOTIFYRESP_IND		131
#endif

#ifndef     MMS_MESSAGE_TYPE_RETRIVE_CONF
#define		MMS_MESSAGE_TYPE_RETRIVE_CONF		132
#endif

#ifndef     MMS_MESSAGE_TYPE_ACKNOWLEDGE_IND
#define		MMS_MESSAGE_TYPE_ACKNOWLEDGE_IND	133
#endif

#ifndef     MMS_MESSAGE_TYPE_DELIVERY_IND
#define		MMS_MESSAGE_TYPE_DELIVERY_IND		134
#endif





typedef enum
{
	NETLINK_RETURN = 0,
	SENDDATA_RETURN,
	DATAARRIVED,
	NETCLOSELINK_RETURN,
	FILEOPRATE_RETURN,
	DIR_OPREATE_RETURN,
	//CECW_TIMER_MSG,//超时　
	WTP_TIMEROUT_MSG
}CenMsgType;

typedef enum
{
	MMS_NETLINK_FAILED,
	MMS_NETLINK_SUCCESS
}MMS_NETLINK_RETURN_VALUE;//网络连接后  //  Modified by TIPrj[2005/7/13]

typedef enum
{
	SENDDATA_FAILED,
	SENDDATA_SUCCESS
}SENDDATA_RETURN_VALUE;//发送数据后返回消息


typedef enum 
{
	NETCLOSELINK_ERROR,
	NETCLOSELINK_SUCCESS
}NETCLOSELINK_RETURN_VALUE;
/*
typedef enum
{
	FILEOPEN_SUCCESS,
	FILEOPEN_FAILED,
	FILEREAD_SUCCESS,
	FILEREAD_FAILED,
	FILEWRITE_SUCCESS,
	FILEWRITE_FAILED,
	FILECLOSE_SUCCESS,
	FILECLOSE_FAILED,
	FILEREMOVE_SUCCESS,
	FILEREMOVE_FAILED,
	FILESEEK_SUCCESS,
	FILESEEK_FAILED,
}FILEOPRATE_RETURN_VALUE;//文件操作返回值
*/
/*
typedef enum
{
	MKDIR_SUCCESS,
	MKDIR_FAILED,
	RMDIR_SUCCESS,
	RMDIR_FAILED,
	GETCWD_SUCCESS,
	GETCWD_FAILED,
}DIR_OPREATE_RETURN_VALUE;   //目录操作返回值
*/
/*------------------------------------------------------------------------
 *
 *
 *
 *                 MMS库回调函数mmsproc参数定义
 *					向上层反映库的状态
 *
 *
------------------------------------------------------------------------*/
 

typedef enum
{
	MMSNETLINKING,
	MMSNETLINK_SUCCESS,
	WAPCONNECT_SUCCESS,
	MMS_RECEIVING,
	MMS_SENDING,
	MMSNETLINK_FAILED,
	MMSWAPCONNECT_FAILED,
	//MMSSEND_FAILED,
	//MMSSEND_SUCCESS,
	MMSRECV_FAILED,
	MMSRECV_FAILED_BY_NOT_FOUND,
	MMSRECV_FINISHED,
	MMSRECV_SUCCESS,
	MMSOPR_CANCEL,
	MMSWAP_DISCONNECTED,
	MMSSYSTEM_ERROR,
	MMSUNKNOWN_ERROR,
	MMSNET_DISCONNECTED,
	MMSNET_DISCONNECTING,
	/* macro define of Response status value */
	MMS_RESPONSE_STATUS_VALUE_OK					=128,
	MMS_RESPONSE_STATUS_VALUE_E_UNSPECIFIED			=129,
	MMS_RESPONSE_STATUS_VALUE_E_SERVICE_DENIED		=130,
	MMS_RESPONSE_STATUS_VALUE_E_FORMAT_CORRUPT		=131,
	MMS_RESPONSE_STATUS_VALUE_E_ADDRESS_UNRESOLVED	=132,
	MMS_RESPONSE_STATUS_VALUE_E_MESSAGE_NOT_FOUND	=133,
	MMS_RESPONSE_STATUS_VALUE_E_NETWORK_PROBLEM		=134,
	MMS_RESPONSE_STATUS_VALUE_E_NOT_ACCEPTED		=135,
	MMS_RESPONSE_STATUS_VALUE_E_UNSUPORTED_MESSAGE	=136,
	MMS_RESPONSE_STATUS_VALUE_E_UNKNOW_ERROR        =999

}MMS_LIBSTATUS_VALUE;


typedef enum
{
	SMS_TYPE_DELIVERY_IND,             //当你方收到后，发送方会收到确认
	SMS_TYPE_NOTIFICATION_IND,          //通知你有人给你发MMS了
	SMS_TYPE_UNKNOW
}SMS_HANDLE_STATUS;


typedef enum mmsliberrcode{
	MMS_NO_ERROR = 0,                             //没有错误
	MMSMEMORY_ERROR,
	MMSSEND_ABORT,
	MMSRECV_ABORT,
	MMSTEXT_TOOLARGE,
	MMSIMAGEAUDIO_TOOLARGE,
	MMSMSG_TOOLARGE
}MMSLIBERRCODE;

/*
typedef enum 
{
	MMS_RECVRETURN_MSGSENDED,
}LIB_STATUS_SENDRETURN_VALUE;
typedef enum 
{
	MMS_RECVRETURN_ERROR,   
	MMS_RECVRETURN_SUCCESS,
}LIB_STATUS_RECVRETURN_VALUE; 
*/


#define USER_MSG_BASE			0x8800

/* define user message */

#define UM_SEND_REQUEST			USER_MSG_BASE+1
#define UM_SEND_CONFIRM			USER_MSG_BASE+2
#define UM_ON_NOTI_INDICATE		USER_MSG_BASE+3
#define UM_NOTIRESP_INDICATE	USER_MSG_BASE+4
#define UM_GET_REQUEST			USER_MSG_BASE+5
#define UM_RETRIVE_CONFIRM		USER_MSG_BASE+6
#define UM_ACKN_INDICATE		USER_MSG_BASE+7
#define UM_ON_DELI_INDICATE		USER_MSG_BASE+8
#define UM_PUSH_PROCESS			USER_MSG_BASE+9
#define UM_NET_EVENT			USER_MSG_BASE+10
#define	UC_FILEINPUT			USER_MSG_BASE+11
#define UM_SAVE_MLIST			USER_MSG_BASE+12

#define IDL_MESSAGE_LIST		USER_MSG_BASE+101
#define ID_LISTVIEW				USER_MSG_BASE+102


#define UM_ID_NEW_M				ID_NEW_M
#define UM_ID_BROWSE_M			ID_BROWSE_M
#define UM_ID_REPLY_M			ID_REPLY_M
#define UM_ID_MODIFY_M			ID_MODIFY_M
#define UM_ID_SEND_M			ID_SEND_M
#define UM_ID_DELETE_M			ID_DELETE_M

/* define message box type */

#define MMS_MB_OK                       0x00000000L
#define MMS_MB_OKCANCEL                 0x00000001L
#define MMS_MB_ABORTRETRYIGNORE         0x00000002L
#define MMS_MB_YESNOCANCEL              0x00000003L
#define MMS_MB_YESNO                    0x00000004L
#define MMS_MB_RETRYCANCEL              0x00000005L

/* define message box caption */

#define MMS_MC_MESSAGE			"信息"
#define MMS_MC_REQUEST			"询问"
#define MMS_MC_ALERT			"警告"
#define MMS_MC_ERROR			"错误"

#define MMS_STATE_MANAGER		1
#define MMS_STATE_EDITOR		2
#define MMS_STATE_BROWSER		3

/******************类型定义****************************/
typedef unsigned char CMS_MMS_U8; 		/*=== unsigned 8 bit data  ===*/
typedef unsigned short CMS_MMS_U16; 	/*=== unsigned 16 bit data ===*/
typedef unsigned int CMS_MMS_U32; 		/*=== unsigned 32 bit data ===*/
typedef unsigned long CMS_MMS_U64; 		/*=== unsigned 64 bit data ===*/
typedef char CMS_MMS_S8; 				/*=== signed 8 bit data  ===*/
typedef short CMS_MMS_S16; 				/*=== signed 16 bit data ===*/
typedef int CMS_MMS_S32; 				/*=== signed 32 bit data ===*/
typedef long CMS_MMS_S64; 				/*=== signed 64 bit data ===*/
typedef void CMS_MMS_VOID;				/*=== void ===*/

typedef CMS_MMS_U8 * P_CMS_MMS_U8;
typedef CMS_MMS_U16 * P_CMS_MMS_U16; 
typedef CMS_MMS_U32 * P_CMS_MMS_U32;
typedef CMS_MMS_U64 * P_CMS_MMS_U64;  
typedef CMS_MMS_S8 * P_CMS_MMS_S8;
typedef CMS_MMS_S16 * P_CMS_MMS_S16;  
typedef CMS_MMS_S32 * P_CMS_MMS_S32; 
typedef CMS_MMS_S64 * P_CMS_MMS_S64;
typedef CMS_MMS_VOID * P_CMS_MMS_VOID;

typedef CMS_MMS_S32 CMS_MMS_BOOL;

/*------------------------------------------------------------------------
 *
 *
 *
 *                 发送接收前需要设置的数据结构
 *					
 *
 *
------------------------------------------------------------------------*/
typedef struct tag_send_setting
{
	char *send_vfilename;
	char *conf_vfilename;
}MMS_SEND_SETTING;

typedef struct tag_recv_setting
{
	char *get_url;
	char *recv_vfilename;
	CMS_MMS_BOOL immediate_recv;   //是否立即接收
	int recv_msgsize;
}MMS_RECV_SETTING;

typedef struct tag_mmsconfig_setting
{
	unsigned char *wap_gateway;  //网关地址，中移动的为"10.0.0.172"2003.11.03
	char *mms_centery;  //彩信中心，中移动的为"Http://mmsc.monternet.com/"
	int   wap_port;     //wap wtp端口号  9201
}MMS_CONFIG_SETTING;
/*------------------------------------------------------------------------
 *
 *
 *
 *                 向上层显示发件人的电话，主题等结构
 *					
 *
 *
------------------------------------------------------------------------*/
typedef struct tag_sms_msg
{
	int  msgsize;                      //消息大小
	long de_date;					   //delivery report date
	int  de_status;                    //delivery report status

	char *de_msgid;                    //delivery report message id
	char *de_to;                        //delivery report receiver


    char *mms_url;                     //MMS所在的URL
    char *phone_number;                //发件人的电话
    char *subject;                     //MMS主题
	char *tid;                          //transaction ID
	/*20051010 chaozhuzh add for expriy begin*/
	long  expriy_time;		  //消息有效期
	/*20051010 chaozhuzh add for expriy end*/
}NOTIFICATION_IND_SMS_MSG;

/*------------------------------------------------------------------------
 *
 *
 *
 *                 管理器的数据结构用不到
 *					
 *
 *
------------------------------------------------------------------------*/
#if 0
typedef struct tagMSETTING MSETTING;
typedef MSETTING *p_MSetting;
struct tagMSETTING
{
	/* system setting */
	CMS_MMS_S8		wapaddress[64];
	CMS_MMS_S8		mmscaddress[40];
	CMS_MMS_S8		sender[64];
	/* opration setting */
	CMS_MMS_U8		ask_coming;		// promnt a new message
	CMS_MMS_U8		auto_receive;	// auto receive message
	CMS_MMS_U8		ask_received;	// promnt a new message is receive
	CMS_MMS_U8		ask_delivery;	// promnt delivery report
	/* style setting */
	CMS_MMS_U8		prompt_sendout;
	CMS_MMS_U8		prompt_received;
	CMS_MMS_U8		prompt_read;
	CMS_MMS_U8		show_address;
	CMS_MMS_U8		priority;
};

/* struct define: messagelist */
typedef struct tagMessagelist MESSAGELIST;
typedef  MESSAGELIST *pMessageList;
struct tagMessagelist
{
	CMS_MMS_S8				filename[128];
	CMS_MMS_U8				state;
	CMS_MMS_S8				title[40];
	CMS_MMS_S8				date[32];
	CMS_MMS_S8				sender[64];
	CMS_MMS_S8				receiver[64];
	pMessageList	next;
};

/* struct define: messagelist */
typedef struct tagMessageFolder MESSAGEFOLDER;
typedef  MESSAGEFOLDER *pMessageFolder;
struct tagMessageFolder
{
	CMS_MMS_U32				messagenumber;
	CMS_MMS_U32				unsettlednumber;
	pMessageList	currentmessage;
	pMessageList	root;
};


/* struct define: CmsMMSDocument
 *  CmsMMSDocument describe a mms pdu
 */
typedef struct _ManagerDocument
{
	CMS_MMS_U8				state;
	CMS_MMS_U32				netstate;
	void			*gprshandle;
	void			*netthread;
	CMS_MMS_U32				currentevent;
	pMessageFolder	currentfolder;
	pMessageFolder	receivefolder;
	pMessageFolder	sendfolder;
	pMessageFolder	draftfolder;
	p_MSetting		setting;

	/* main window handle */
	/*HINSTANCE		mhInst;
	HWND			mhWnd;*/
}ManagerDocument;
typedef ManagerDocument *P_ManagerDocument;

#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
P_ManagerDocument	getmanagerdocument();

CMS_MMS_U64		getusablememory();
*/
/*
void	char2wchar(char *str, WCHAR *wstr, int length);
void	wchar2char(WCHAR *wstr, char *str, int length);
*/
/*
void	mms_make_timestring(CMS_MMS_S8 filename[64]);

void	manager_post_message(CMS_MMS_U32 message, CMS_MMS_U32 WPARAM, CMS_MMS_S64 LPARAM);
CMS_MMS_S32		manager_message_box(CMS_MMS_S8 *text, CMS_MMS_S8 *caption, CMS_MMS_U32 type);
CMS_MMS_S32		sender_message_box(CMS_MMS_S8 *text, CMS_MMS_S8 *caption, CMS_MMS_U32 type);
*/
/*这部分加到MMS文档结构的头文件中去，不在全局*/
/*
void	mms_add_to_send_list(MMSHANDLE	mmsdoc, CMS_MMS_U8 state);
void	mms_add_to_receive_list(MMSHANDLE	mmsdoc, CMS_MMS_U8 state);
void	mms_add_to_draft_list(MMSHANDLE	mmsdoc);

void	mms_set_send_message_state(CMS_MMS_S8 *filename, CMS_MMS_U8 state);
void	mms_set_receive_message_state(CMS_MMS_S8 *filename, CMS_MMS_U8 state);

void	deletetempfile();
void	long2chardate(CMS_MMS_U64 ldate, CMS_MMS_S8 *cdate);
void	mms_get_time(long *ltime);
*/
//void	remove(char *filename);
/*
CMS_MMS_S32		manager_hide(HWND hWnd);
CMS_MMS_S32		manager_show(HWND hWnd);
CMS_MMS_S32		editor_hide(HWND hWnd);
CMS_MMS_S32		editor_show(HWND hWnd);
*/




#ifdef __cplusplus
}
#endif
#endif /* _GLOBLE_H_ */
 
