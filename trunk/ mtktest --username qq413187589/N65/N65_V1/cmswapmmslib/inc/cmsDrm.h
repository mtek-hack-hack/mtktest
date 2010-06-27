#ifndef _CMSDRM_H
#define _CMSDRM_H

#include "CmsHttp.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BODY_MAX_BOUNDARY_STR_LENGTH 156
#define BODYPART_MAX_HEADER_LENGTH 128
#define BODYPART_MAX_NAME_LENGTH 64	
/* inner the content data(head) maybe include these information */
typedef struct _DRM_MESSAGE_BODYPART_INF
{
	Cms_ContentType_e	subType;		/*子媒体对象content类型*/
	char	id[BODYPART_MAX_NAME_LENGTH];			/*子媒体对象ID*/
	char	location[BODYPART_MAX_NAME_LENGTH];		/*子媒体对象地址*/
	char	encoding[BODYPART_MAX_NAME_LENGTH];		/*子媒体对象传输编码方式*/
	int     contentLen ;					/*子媒体对象长度*/
	unsigned char *bufStart;				/*起始地址指针*/
}DRM_MESSAGE_BODYPART_INF;
typedef DRM_MESSAGE_BODYPART_INF *P_DRM_MESSAGE_BODYPART_INF;

/* content-type block maybe include these information*/
typedef struct _DRM_MESSAGE_BODY_INF 
{
	int                 subBodypartNums;	/*子媒体对象数目*/
	Cms_ContentType_e	drmMessage;			/*multi媒体对象类型*/
	char				boundary_str[BODY_MAX_BOUNDARY_STR_LENGTH]; 
											/*分界线符号串*/
	int                 boundary_str_len;	/*分界线符号串长度*/
	P_DRM_MESSAGE_BODYPART_INF subMideaObject[10];/*支持5种sub body*/
	int					messageBodyLen;
	unsigned char *     messageBodyBuf;
}DRM_MESSAGE_BODY_INF;
typedef DRM_MESSAGE_BODY_INF *P_DRM_MESSAGE_BODY_INF;

P_DRM_MESSAGE_BODY_INF DealWithDrmFile(unsigned char *drmContent,
					const    int   drmContentLen,
					Cms_ContentType_e   drmDealingType);
void destroyDRM(P_DRM_MESSAGE_BODY_INF pDrmBody);
#ifdef __cplusplus
};
#endif

#endif									 







										 
										 
