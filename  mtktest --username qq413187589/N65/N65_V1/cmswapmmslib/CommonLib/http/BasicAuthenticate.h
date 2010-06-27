/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			:AuthenticationManager.c

功能描述		: 提供HTTP基本认证接口

最近修改时间	: 10/7/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn

================================================================*/
#ifndef BASICAUTHENTICATE_H
#define BASICAUTHENTICATE_H

#include "AuthenticationManager.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int EncodeBase64(const unsigned char* pSrc, char* pDst, int nSrcLen);


#ifdef __cplusplus
};
#endif

#endif