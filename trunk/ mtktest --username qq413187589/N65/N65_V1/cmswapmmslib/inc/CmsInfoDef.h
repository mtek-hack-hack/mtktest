/************************************************************************* 
 * Copyright (c) 2000-2003 MobileSoft Corporation All Rights Reserved.	
 * 日  期：  2005-4-8   	
 * 作  者：  cms    	    	
 * 文  件：  Cms_Info.h 	
 * 描  述：  
 ************************************************************************/
#ifndef _CMS_INFO_H
#define _CMS_INFO_H
#ifdef UNSPPORT_MULTITY_LANGUAGE
unsigned char* Cms_GetInfo(int InfoID, int LanguageDiv);
#endif
unsigned char* Cms_GetCurInfo( int infoId );
typedef enum _Info_Type
{
	Info_NoSuchServer,                       // 该服务器不存在
	Info_Dialing_Failed,                     // 拨号失败
	Info_GPRS_Connection_Is_Disconnected,    // GPRS链接不存在
	Info_DownLoad_Ring_Failed,               // 下载铃声失败
	Info_Unknown_File_Type,                  // 无效的文件类型
	Info_Server_Reject,                      // 服务器拒绝下载
	Info_Invalid_Address,                    // 非法网址
	Info_Wrong_Url,							 // 无效网址
	Info_Error_Page,						 // 错误的页面

	Info_Download_Error,					 // 网关无响应
	Info_Server_Connect_Error,				 // 服务器故障
	Info_Timerout,							 // 服务器超时
	Info_notSupportFile,					 // 不支持该类型

	Info_Submit,                             // 提交
	Info_Button,                             // 按钮
	Info_Reset,                              // 重置

	Info_Subject,                            // 主题 :
	Info_Issuer,                             // 发行者 :
	Info_Valid_Not_Before,                   // 有效期始于 :
	Info_Valid_Not_After,                    // 有效期截至 :
	Info_MDInfo,                             // 指纹码算法 : sha1 \n指纹码 :\n
	Info_Signature_Algo,                     // 签名算法 :
	Info_Signature    ,                      // 数字签名 : \n

	Info_Valid_Server_Cert ,					// 有效的服务器证书
    Info_Invalid_Server_Cert ,					// 错误的服务器证书或不支持的证书类型
	Info_Invalid_CA ,							// 未找到对应CA根证书,无法验证证书的有效性
	Info_Cert_Revoked ,							// 服务器证书已经被撤销
	Info_Cert_Invalid_Date ,					// 服务器证书已经过期或还未生效
	Info_Cert_Purpose ,							// 错误的证书用途
	Info_Cert_Invalid_Name ,					// 证书的标识与所访问的站点不匹配
	Info_Cert_Unknown_Err  ,					// 未知的错误类型
	Info_Invalid_Cert_Confirm_Info ,			// 由于服务器证书存在问题,无法确保你所提交信息的安全性.\n
												//如果你无法确认服务器有效性和安全性,请选择取消以断开与服务器的连接.
	Info_SSL_Exchg_Alg ,						// TLS1.0 , %s(%d位加密(高));RSA(%d位交换).\n\n
	Info_Server_Cert_Info ,						// 服务器证书信息
	Info_malloc_Failed,							//协议栈分配大内存失败
	Info_socket_Erro,							//OS socket erro
	Info_file_TooLarge,							//文件太大,超过接收范围
	Info_connection_secured,                    // 安全连接
	Info_connecting_to_service,                 // 正在连接到服务器
	Info_Connecting_Secured_So_Server,          // 正与服务器进行安全链接，是否继续？
	Info_Downloadingimg,						//正在下载图片标题
	Info_Downloadimgok,							//图片下载完成标题
	Info_AboutCmsWap,							//版本信息
	/* do not remove this entry. */
	Info_MAX_ID 	
} Info_Type;


#endif
