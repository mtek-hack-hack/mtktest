/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/schannel.h,v 1.1 2007/05/17 07:25:33 bw Exp $
*
* $Id: schannel.h,v 1.1 2007/05/17 07:25:33 bw Exp $
*
* $Date: 2007/05/17 07:25:33 $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 1.1 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: schannel.h,v $
* Revision 1.1  2007/05/17 07:25:33  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2007
*
*****************************************************************************/
/*============================================================================
*
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/schannel.h,v 1.1 2007/05/14 09:46:48 bw Exp $
*
* ~Id: schannel.h,v 1.1 2007/05/14 09:46:48 bw Exp $
*
* ~Date: 2007/05/14 09:46:48 $
*
* ~Name: 1.1 $
*
* ~Locker$
*
* ~Revision: 1.1 $
*
* ~State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* ~Log: schannel.h,v $
* Revision 1.1  2007/05/14 09:46:48  bw
* UNI@bw_20070514 17:21:01 MTK初始版本.合并U25V20到U26V28.
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/schannel.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Id: schannel.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Date: 2007/04/04 06:51:34 $
*
* ~Name: 1.2 $
*
* ~Locker$
*
* ~Revision: 1.2 $
*
* ~State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* ~Log: schannel.h,v $
* Revision 1.2  2007/04/04 06:51:34  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _SCHANNEL_H
#define _SCHANNEL_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#include <wincrypt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SCHANNEL_CRED_VERSION 4
#define SCHANNEL_SHUTDOWN 1
/* ? Do these belong here or in wincrypt.h */
#define AUTHTYPE_CLIENT 1
#define AUTHTYPE_SERVER 2

#define SP_PROT_TLS1_CLIENT 128
#define SP_PROT_TLS1_SERVER 64
#define SP_PROT_SSL3_CLIENT 32
#define SP_PROT_SSL3_SERVER 16
#define SP_PROT_SSL2_CLIENT 8
#define SP_PROT_SSL2_SERVER 4
#define SP_PROT_PCT1_SERVER 1
#define SP_PROT_PCT1_CLIENT 2

#define SP_PROT_PCT1 (SP_PROT_PCT1_CLIENT|SP_PROT_PCT1_SERVER)
#define SP_PROT_TLS1 (SP_PROT_TLS1_CLIENT|SP_PROT_TLS1_SERVER)
#define SP_PROT_SSL2 (SP_PROT_SSL2_CLIENT|SP_PROT_SSL2_SERVER)
#define SP_PROT_SSL3 (SP_PROT_SSL3_CLIENT|SP_PROT_SSL3_SERVER)

#define SCH_CRED_NO_SYSTEM_MAPPER 2
#define SCH_CRED_NO_SERVERNAME_CHECK 4
#define SCH_CRED_MANUAL_CRED_VALIDATION 8
#define SCH_CRED_NO_DEFAULT_CREDS 16
#define SCH_CRED_AUTO_CRED_VALIDATION 32
#define SCH_CRED_REVOCATION_CHECK_CHAIN 512
#define SCH_CRED_REVOCATION_CHECK_END_CERT 256
#define SCH_CRED_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT 1024
#define SCH_CRED_IGNORE_NO_REVOCATION_CHECK 2048
#define SCH_CRED_IGNORE_REVOCATION_OFFLINE 4096
#define SCH_CRED_USE_DEFAULT_CREDS 64

typedef struct _SCHANNEL_CRED {
	DWORD dwVersion;
	DWORD cCreds;
	PCCERT_CONTEXT* paCred;
	HCERTSTORE hRootStore;
	DWORD cMappers;
	struct _HMAPPER** aphMappers;
	DWORD cSupportedAlgs;
	ALG_ID* palgSupportedAlgs;
	DWORD grbitEnabledProtocols;
	DWORD dwMinimumCypherStrength;
	DWORD dwMaximumCypherStrength;
	DWORD dwSessionLifespan;
	DWORD dwFlags;
	DWORD reserved;
} SCHANNEL_CRED, *PSCHANNEL_CRED;
typedef struct _SecPkgCred_SupportedAlgs {
	DWORD cSupportedAlgs;
	ALG_ID* palgSupportedAlgs;
} SecPkgCred_SupportedAlgs, *PSecPkgCred_SupportedAlgs;
typedef struct _SecPkgCred_CypherStrengths {
	DWORD dwMinimumCypherStrength;
	DWORD dwMaximumCypherStrength;
} SecPkgCred_CypherStrengths, *PSecPkgCred_CypherStrengths;
typedef struct _SecPkgCred_SupportedProtocols {
	DWORD grbitProtocol;
} SecPkgCred_SupportedProtocols, *PSecPkgCred_SupportedProtocols;
typedef struct _SecPkgContext_IssuerListInfoEx {
	PCERT_NAME_BLOB aIssuers;
	DWORD cIssuers;
} SecPkgContext_IssuerListInfoEx, *PSecPkgContext_IssuerListInfoEx;
typedef struct _SecPkgContext_ConnectionInfo {
	DWORD dwProtocol;
	ALG_ID aiCipher;
	DWORD dwCipherStrength;
	ALG_ID aiHash;
	DWORD dwHashStrength;
	ALG_ID aiExch;
	DWORD dwExchStrength;
} SecPkgContext_ConnectionInfo, *PSecPkgContext_ConnectionInfo;

#ifdef __cplusplus
}
#endif

#endif /* _SCHANNEL_H */
