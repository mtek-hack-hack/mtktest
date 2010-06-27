/*==================================================================

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2001-2002
 ALL RIGHTS RESERVED

==================================================================

 Project Name: CMS&CTL Download PROJ Ver 1.00
 
 File Name   : CmsCTLDownload.h

 Description : CMS&CTL DOWNLOAD HEAD

 Last Modify : 02/03/2005
 
 Written By  : Mobilesoft Technology

==================================================================*/
#include "CmsNetwork.h"

typedef enum
{
	CTL_CMS_WAP = 0,
	CTL_CMS_MMS = 1,
	CTL_CMS_SYNCML

}CTL_APP_ID;

typedef enum
{  
	WAPDL_NO_ERROR = 0,                    
	WAPDL_PARAM_ERROR,
	WAPDL_MEMORY_ERROR,                   
	WAPDL_NET_ERROR,
	WAPDL_SEND_ABORT,
	WAPDL_RECV_ABORT,
	WAPDL_TIMEOUT_ERROR, 
    WAPDL_CONNECT_ERROR,
    WAPDL_DISCONNECT_ERROR,
	WAPDL_NO_DATA_ERROR,
	WAPDL_NOT_FOUND_ERROR,
	WAPDL_OBJ_MOVED_ACCESS,
	WAPDL_DATA_ERROR,

	WAPDL_CONNECT_SERVER_FAILED,
	WAPDL_DOWNLOAD_FAILED,
	WAPDL_LOCAL_NET_ERRO,
	WAPDL_DNS_ERROR,
	WAPDL_PROTCAL_STACK_BUSY,
	WAPDL_CURRENTTASK_ABNORMAL,
	WAPDL_SERVER_WRONG,

	//SYNCML反馈信息
	WADL_NETINITING,
	WAPDL_REDIRECTION, //发生前转，即重定向
	WAPDL_AUTHENTICATION,//正在同步初始化，鉴全，认证
	WAPDL_DATASENDING,// 正在发送数据
	WAPDL_DATARECEIVING,//正在接受数据
	WAPDL_SERVERCONFLICT		//服务器冲突	
	
}CMS_CTL_DL_ERRCODE;
/*
typedef enum
{
	EVENT_NETLINK_RETURN,
	EVENT_NETCLOSE_RETURN,
	EVENT_SOCKETCONNECT_RETURN,
	EVENT_GETHOSTIP_RETURN,
	EVENT_DATARRIVED,
	EVENT_SOCKETCLOSED_RETURN,
	EVENT_REMOTESOCKETCLOSED,
	EVENT_DATASENT_RETURN

} NET_EVENT_E;

typedef enum
{
	NETLINK_SUCCESS,
	NETLINK_FAILED,
	NETCLOSE_SUCEESS,
	NETCLOSE_FAILED,
	SOCKETCONNECT_SUCCESS,
	SOCKETCONNECT_FAILED
	
} NET_EVENT_PARAM_E;
*/
typedef enum
{  
	CONNECTSTACK_WHTTP,
	CONNECTSTACK_WAP
	
}CMS_CTL_CONNECTSTACK;
#define SYNCMAL_TASK 2
typedef struct _tag_CMS_CTL_ConnectProfile
{
	unsigned char Gateway[128];
	unsigned int port;
	CMS_CTL_CONNECTSTACK stack;
	int      SyncmlTaskFlag;//0,unknow;1,SYNCML task

}CMS_CTL_ConnectProfile;

typedef void (*wap_callback)(unsigned int error_code ,char *error_msg ,char *pcontent ,unsigned int length );

#ifndef TI //  Modified by TIPrj[2005/6/29]
#if defined ( __cplusplus) && __cplusplus
extern "C" {
#endif
#endif
void SYNCML_Access_HttpData(unsigned int error_code ,char *error_msg ,char *pcontent ,unsigned int length );

extern unsigned int CTL_UDP_RecvData(unsigned char *precv , unsigned int *plength , unsigned char *phost, unsigned int port);
extern CMS_CTL_ConnectProfile *CTL_GetConnectProfileByAppID(void);

/*函数参数说明： 	type 	网络事件的类型 param 	网络事件结果*/		
void CmsNetPostEvent(NET_EVENT_E type,NET_EVENT_PARAM_E param);
unsigned char CmsNetDownloadInit(void);
void CmsNetCancelDownload (void);
void CmsNetDownloadClose(void);
void CmsNetGetMethod(unsigned char *pUrl, wap_callback WAPDLCallback);
void CmsNetPostMethod(unsigned char *pUrl ,unsigned char *pContentType ,unsigned char *pContent ,unsigned int length, wap_callback WAPDLCallback);

#ifndef TI //  Modified by TIPrj[2005/6/29]
#if defined ( __cplusplus) && __cplusplus
}
#endif
#endif

