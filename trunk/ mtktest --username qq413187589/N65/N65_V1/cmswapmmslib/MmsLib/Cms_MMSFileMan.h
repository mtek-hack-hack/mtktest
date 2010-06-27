#ifndef _MMSFILEMAN_H
#define _MMSFILEMAN_H

#define	SUPPORT_SMSMMS_COMBINE
#define SUPPORT_OTA_PUSH

#ifndef MMS_FILE_NAME_LEN
#define MMS_FILE_NAME_LEN 128
#endif

#ifndef CMS_MMS_APP_PATH
#define CMS_MMS_APP_PATH						"c:\\\\mms\\\\"	/* 彩信目录路径 */
#endif

#ifndef MMS_MAX_INPUT_SUBJECT_SIZE
#define MMS_MAX_INPUT_SUBJECT_SIZE			41								/* 彩信主题编辑输入最大长度 */
#define MMS_MAX_UTF_SUBJECT_SIZE			MMS_MAX_INPUT_SUBJECT_SIZE*3+1	/* UNICODE(汉字)转为UTF8所需最大长度 */
#define MMS_MAX_SUBJECT_SIZE				MMS_MAX_INPUT_SUBJECT_SIZE*3+2	/* 彩信主题UNICODE数组(全局)最大长度 */
#endif

#ifndef MMS_MAX_INPUT_SEND_TO_SIZE
#define MMS_MAX_INPUT_SEND_TO_SIZE			36		/* 编辑收件人输入的最大长度 */
#endif

#ifndef MMS_MAX_DATE_LEN
#define MMS_MAX_DATE_LEN					32		/* 文件管理器信息日期最大长度 */
#endif

#define MAX_MESSAGE_COUNT					50			/* 信箱最大储存信息数 */
#define MAX_SIZE_MMS_DEFINE					500*1024	/* 预定义信箱最大储存信息大小 */
#define MAX_SIZE_ALL_MMS					Cms_Return_Mms_MaxSize()/* 实际信箱最大储存信息大小 */

#define MMS_MAX_SIZE_OF_MESSAGE				mms_get_send_max_size()		/* 所能编辑发送的彩信最大容量：50 K */
#define MMS_MAX_RECEIVE_SIZE				mms_get_receive_max_size()	/* 所能接收的的彩信最大容量：50 K */
#define MMS_MAX_SIZE_OF_MESSAGEHEAD			1024						/*彩信头的最大长度*/

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

/*message type */
enum
{
	MESSAGE_NULL=0,					/*空*/
	MESSAGE_MMS,						/*彩信消息*/
	MESSAGE_SMS,						/*短信消息*/
	MESSAGE_WAP,						/*WAP 消息*/
	MESSAGE_OTA_SET,					/*WAP OTA SETTING 消息*/
	MESSAGE_OTA_BOOKMARK			/*WAP BOOKMARK    消息*/
};

/*message setting */
typedef enum
{
	SET_MESSAGE_NULL,						/*不操作*/
	SET_MESSAGE_CUR,						/*设定为当前信息*/
	SET_MESSAGE_PUSH						/*设定为当前PUSH信息*/
}SET_MESSAGE;

/* 信箱名定义*/
typedef enum 
{
		MMS_FOLDER_UNKNOWN = 0,
		MMS_RECEIVE_FOLDER,				/* 收件箱 */
		MMS_SEND_FOLDER,					/* 发件箱 */
		MMS_DRAFT_FOLDER					/* 草稿箱 */
}MMS_FOLDER_NAME;

/* message state of box*/
typedef enum 
{
		MMS_MSG_STATE_UNRECEIVED = 0,	/* unreceive */ 
		MMS_MSG_STATE_UNREAD,			/* unread*/			
		MMS_MSG_STATE_READ,				/*read*/
		MMS_MSG_STATE_UNSEND,			/*unsend*/
		MMS_MSG_STATE_SENDFAILED,		/*send failed*/
		MMS_MSG_STATE_SENDED			/*sended*/
}MMS_MSG_STATE;

/*MMS的摘要信息链表*/
typedef struct TAGMESSAGELIST MESSAGELIST;
typedef  MESSAGELIST *P_MESSAGELIST;
struct TAGMESSAGELIST
{
	char				*fileName;				/* 彩信文件名(后缀.mms) */
	char				*subject;				/* 彩信主题 */
	char				*to_address;			/* 彩信收件人/发件人的地址 */
	char				*cc_address;			/* 彩信CC 的地址 */
	char				*bcc_address;			/* 彩信BCC的地址 */
	char				*url;					/* PUSH消息URL地址 */
	char				*date;					/* 日期 */
	int					size;					/* 彩信大小 */
	P_MESSAGELIST		next;					/* 下一条彩信 */
	unsigned char		state;					/* 彩信状态(已读、未读、彩信PUSH) */
	int					expriy_time;			/*消息有效期*/

	unsigned char		msgtype;				/*message type :sms/ mms /wap /ota set/bookmark*/
    #ifdef SUPPORT_SMSMMS_COMBINE
	unsigned short int		SmsIndex;				/*sms index */
    #endif

    #ifdef SUPPORT_OTA_PUSH
	/*
	1.ota setting push  use ota_name,ota_id,url(homepage),ota_url(mmscenter)
	2.ota bookmark push use ota_name,url(bookmark)
	*/
	char				*ota_name;				/* */	
	char				*ota_gateway;			/*gateway*/
	char				*ota_port;				/*port*/
	char				*ota_netacc;		/*netaccount*/

	char				*ota_murl;				/*mmscenter */
	char				*ota_smsc;				/*smsaddress*/

	char				*ota_ispname;			/*ispname*/
	char				*ota_csdscode;			/*CSDServiceCode*/
	char				*ota_apn;				/*GPRSAccessPointName*/
	char				*ota_user;				/*user*/
	char				*ota_passw;				/*password*/
	char				*ota_authtype;			/*ota_authtype*/
	char				*ota_logintype;			/*ota_logintype*/
	
	char				*ota_bmurl;				/* bookmark url*/	
	char				*ota_bmname;			/* bookmark name*/	
    #endif	
};	


/* 信箱信息*/
typedef struct TAGMESSAGEFOLDER MESSAGEFOLDER;
typedef  MESSAGEFOLDER *P_MESSAGEFOLDER;
struct TAGMESSAGEFOLDER
{
	int				messageNumber;		/* MMS 文件个数 */
	int				messageSize;			/* 彩信总的字节数 */
	P_MESSAGELIST	currentMessage;			/* 当前彩信 */
	P_MESSAGELIST	root;					/* 第一条彩信 */
	P_MESSAGELIST	pushMessage;			/* 彩信通知，仅当自动接收时使用 */
};


/* 信箱管理器 */
struct TAGMANAGERDOCUMENT
{	
	int					currentEvent;			/* 当前事件(not use now) */
	char				needProtect;			/* 编辑器内容是否需要保存(not use now)*/
											/* 'Y':需要*/
											/* 'N':不需要 */
	P_MESSAGEFOLDER		currentFolder;	/* 当前信箱*/
	P_MESSAGEFOLDER		receiveFolder;	/* 收件箱 */
	P_MESSAGEFOLDER		sendFolder;   	/* 发件箱 */
	P_MESSAGEFOLDER		draftFolder;		/* 草稿箱*/
};
typedef struct TAGMANAGERDOCUMENT MANAGERDOCUMENT;
typedef MANAGERDOCUMENT *P_MANAGER;


void mms_file_manager_init(void);
void mms_file_manager_create(void);
void mms_file_manager_destory(void);
void mms_file_manager_destory_current_folder(void);
void mms_file_manager_free_message(P_MESSAGELIST mlist);
P_MESSAGELIST mms_file_manager_new_message(void);
P_MESSAGELIST mms_file_manager_new_sms_message(void);
void mms_file_manager_delete_message_node(P_MESSAGELIST list);
void mms_file_manager_delete(void);
void mms_file_manager_delete_current_message(void);
void mms_file_manager_delete_message(P_MESSAGELIST list);
void mms_file_manager_set_current_message(P_MESSAGELIST curMsg);
void mms_file_manager_set_push_message(P_MESSAGELIST pushMsg);
P_MESSAGELIST mms_file_manager_get_push_message(void);

void mms_file_manager_modify_current_message_state(MMS_MSG_STATE state);
void mms_file_manager_add_message_to_folder(P_MESSAGELIST mmsDigest, MMS_FOLDER_NAME folder, SET_MESSAGE flag);

void mms_file_manager_store_folder(MMS_FOLDER_NAME folder);
void mms_file_manager_store_current_folder(void);
void mms_file_manager_set_current_folder(MMS_FOLDER_NAME boxName);
MMS_FOLDER_NAME mms_file_manager_get_current_folder(void);
void mms_file_manager_delete_current_folder(void);
void mms_file_manager_read_all_folders(void);
void mms_get_all_boxes_count_size(int* count, int* msize);

#endif