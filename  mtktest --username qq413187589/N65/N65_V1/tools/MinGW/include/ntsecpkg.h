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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/ntsecpkg.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: ntsecpkg.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Date: 2007/05/17 07:25:31 $
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
* $Log: ntsecpkg.h,v $
* Revision 1.1  2007/05/17 07:25:31  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/ntsecpkg.h,v 1.1 2007/05/14 09:46:45 bw Exp $
*
* ~Id: ntsecpkg.h,v 1.1 2007/05/14 09:46:45 bw Exp $
*
* ~Date: 2007/05/14 09:46:45 $
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
* ~Log: ntsecpkg.h,v $
* Revision 1.1  2007/05/14 09:46:45  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/ntsecpkg.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: ntsecpkg.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Date: 2007/04/04 06:51:32 $
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
* ~Log: ntsecpkg.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _NTSECPKG_H
#define _NTSECPKG_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#define ISC_REQ_DELEGATE 1
#define ISC_REQ_MUTUAL_AUTH 2
#define ISC_REQ_REPLAY_DETECT 4
#define ISC_REQ_SEQUENCE_DETECT 8
#define ISC_REQ_CONFIDENTIALITY  16
#define ISC_REQ_USE_SESSION_KEY 32
#define ISC_REQ_PROMPT_FOR_CREDS 64
#define ISC_REQ_USE_SUPPLIED_CREDS  128
#define ISC_REQ_ALLOCATE_MEMORY 256
#define ISC_REQ_USE_DCE_STYLE 512
#define ISC_REQ_DATAGRAM 1024
#define ISC_REQ_CONNECTION 2048
#define ISC_REQ_EXTENDED_ERROR 16384
#define ISC_REQ_STREAM 32768
#define ISC_REQ_INTEGRITY 65536
#define ISC_REQ_MANUAL_CRED_VALIDATION 524288
#define ISC_REQ_HTTP  268435456

#define ISC_RET_EXTENDED_ERROR 16384

#define ASC_REQ_DELEGATE 1
#define ASC_REQ_MUTUAL_AUTH 2
#define ASC_REQ_REPLAY_DETECT 4
#define ASC_REQ_SEQUENCE_DETECT 8
#define ASC_REQ_CONFIDENTIALITY 16
#define ASC_REQ_USE_SESSION_KEY 32
#define ASC_REQ_ALLOCATE_MEMORY 256
#define ASC_REQ_USE_DCE_STYLE 512
#define ASC_REQ_DATAGRAM 1024
#define ASC_REQ_CONNECTION 2048
#define ASC_REQ_EXTENDED_ERROR 32768
#define ASC_REQ_STREAM 65536
#define ASC_REQ_INTEGRITY 131072

#define SECURITY_NATIVE_DREP  16
#define SECURITY_NETWORK_DREP 0

#endif /* _NTSECPKG_H */
