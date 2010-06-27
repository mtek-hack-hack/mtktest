/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: Cms_WHTTPHeader.h

功能描述		: This module handles lists of callback funtions for generaring 
				  and parsing protocal headers

最近修改时间	: 7/30/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn

================================================================*/
#ifndef _CMS_WHTTPHEADER_H
#define _CMS_WHTTPHEADER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HTTPCodingInf
{
	CMS_BOOL		CodingState;
	unsigned char	*outBuffer;
	int			resultLength;
} HTCodingInf;

typedef struct _HTTPResponseInf
{
	unsigned char * StatusLine;
	unsigned char * HeadField;
	unsigned char * EntityField;
} HTResponseInf;
/*extern P_CMS_CHAR HTNextField(&value);//可以在header struct里寻找*/
extern int HTTPHeader_MIMEParse(Cms_BR_HttpData_Ptr pCallBackBuf);/*解析Response Inf,解析的数据填入HTTPResponseInf中*/
extern int GetStatusCode(CMS_VOID);
extern CMS_VOID DealingKD2Headers(Cms_BR_HttpData_Ptr pCallBackBuf);

#ifdef __cplusplus
};
#endif

#endif