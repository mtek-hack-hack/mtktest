/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: DigestAuthenticate.h

功能描述		: 提供HTTP摘要认证接口

最近修改时间	: 2/3/2005
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn

================================================================*/
#ifndef DIGESTAUTHENTICATE_H
#define DIGESTAUTHENTICATE_H

#ifdef __cplusplus
extern "C" {
#endif
extern char *getInputUserName(void);
extern char *getInputUserPass(void);
extern char *getDigestLastDealingReult(void);
extern char *getCurrentDownLoadUrl(void);
#define ALGRITHLEN 30
#define HASHLEN 16
typedef char HASH[HASHLEN];
#define HASHHEXLEN 32
typedef char HASHHEX[HASHHEXLEN +1];
#define IN
#define OUT

/* calculate H(A1) as per HTTP Digest spec */
void DigestCalcHA1(
    IN char * pszAlg,
    IN char * pszUserName,
    IN char * pszRealm,
    IN char * pszPassword,
    IN char * pszNonce,
    IN char * pszCNonce,
    OUT HASHHEX SessionKey
    );

/* calculate request-digest/response-digest as per HTTP Digest spec */
void DigestCalcResponse(
    IN HASHHEX HA1,           /* H(A1) */
    IN char * pszNonce,       /* nonce from server */
    IN char * pszNonceCount,  /* 8 hex digits */
    IN char * pszCNonce,      /* client nonce */
    IN char * pszQop,         /* qop-value: "", "auth", "auth-int" */
    IN char * pszMethod,      /* method from the request */
    IN char * pszDigestUri,   /* requested URL */
    IN HASHHEX HEntity,       /* H(entity body) if qop="auth-int" */
    OUT HASHHEX Response      /* request-digest or response-digest */
    );
typedef struct 
{
	char *realm;
	char *domain;
	char *nonce;
	char *qop;
	char *opaques;
	char *stale;
	char *algorithm;
} _DigestResponseInfo;
typedef _DigestResponseInfo *P_DigestResponseInfo;

typedef struct 
{
	char *username;
	char *userpass;
	char *realm;
	char *qop;
	char *opaques;
	char *response;
	char *uri;
	char *cnonce;
	char *nonce;
	char *nc;
	char *method;
	char *algorithm;
} _DigestRequestInfo;
typedef enum
{
	DIGEST_REALM = 0,
	DIGEST_DOMAIN,
	DIGEST_NONCE,
	DIGEST_QOP,
	DIGEST_OPAQUE,
	DIGEST_STALE,
	DIGEST_ALGORITHM
} DIGESTRESPONSE_e;
typedef _DigestRequestInfo *P_DigestRequestInfo;
#ifdef __cplusplus
};
#endif

#endif