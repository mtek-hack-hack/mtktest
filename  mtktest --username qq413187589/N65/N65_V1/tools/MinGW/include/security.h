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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/security.h,v 1.1 2007/05/17 07:25:33 bw Exp $
*
* $Id: security.h,v 1.1 2007/05/17 07:25:33 bw Exp $
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
* $Log: security.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/security.h,v 1.1 2007/05/14 09:46:48 bw Exp $
*
* ~Id: security.h,v 1.1 2007/05/14 09:46:48 bw Exp $
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
* ~Log: security.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/security.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Id: security.h,v 1.2 2007/04/04 06:51:34 bw Exp $
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
* ~Log: security.h,v $
* Revision 1.2  2007/04/04 06:51:34  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _SECURITY_H
#define _SECURITY_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif


#define SEC_E_OK 0
#define SEC_E_CERT_EXPIRED (-2146893016)
#define SEC_E_INCOMPLETE_MESSAGE (-2146893032)
#define SEC_E_INSUFFICIENT_MEMORY (-2146893056)
#define SEC_E_INTERNAL_ERROR (-2146893052)
#define SEC_E_INVALID_HANDLE (-2146893055)
#define SEC_E_INVALID_TOKEN (-2146893048)
#define SEC_E_LOGON_DENIED (-2146893044)
#define SEC_E_NO_AUTHENTICATING_AUTHORITY (-2146893039)
#define SEC_E_NO_CREDENTIALS (-2146893042)
#define SEC_E_TARGET_UNKNOWN (-2146893053)
#define SEC_E_UNSUPPORTED_FUNCTION (-2146893054)
#define SEC_E_UNTRUSTED_ROOT (-2146893019)
#define SEC_E_WRONG_PRINCIPAL (-2146893022)
#define SEC_E_SECPKG_NOT_FOUND (-2146893051)
#define SEC_E_QOP_NOT_SUPPORTED (-2146893046)
#define SEC_E_UNKNOWN_CREDENTIALS (-2146893043)
#define SEC_E_NOT_OWNER (-2146893050)
#define SEC_I_RENEGOTIATE 590625
#define SEC_I_COMPLETE_AND_CONTINUE 590612
#define SEC_I_COMPLETE_NEEDED 590611
#define SEC_I_CONTINUE_NEEDED 590610
#define SEC_I_INCOMPLETE_CREDENTIALS 590624

/* always a char */
typedef char SEC_CHAR;
typedef wchar_t SEC_WCHAR;
typedef long SECURITY_STATUS;
#define SEC_FAR

#include <sspi.h>
#include <ntsecpkg.h>
#include <secext.h>

#endif /* _SECURITY_H */
