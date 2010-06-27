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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/rpcnterr.h,v 1.1 2007/05/17 07:25:33 bw Exp $
*
* $Id: rpcnterr.h,v 1.1 2007/05/17 07:25:33 bw Exp $
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
* $Log: rpcnterr.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/rpcnterr.h,v 1.1 2007/05/14 09:46:48 bw Exp $
*
* ~Id: rpcnterr.h,v 1.1 2007/05/14 09:46:48 bw Exp $
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
* ~Log: rpcnterr.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/rpcnterr.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Id: rpcnterr.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Date: 2007/04/04 06:51:33 $
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
* ~Log: rpcnterr.h,v $
* Revision 1.2  2007/04/04 06:51:33  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _RPCNTERR_H
#define _RPCNTERR_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#define RPC_S_OK ERROR_SUCCESS
#define RPC_S_INVALID_ARG ERROR_INVALID_PARAMETER
#define RPC_S_OUT_OF_MEMORY ERROR_OUTOFMEMORY
#define RPC_S_OUT_OF_THREADS ERROR_MAX_THRDS_REACHED
#define RPC_S_INVALID_LEVEL ERROR_INVALID_PARAMETER
#define RPC_S_BUFFER_TOO_SMALL ERROR_INSUFFICIENT_BUFFER
#define RPC_S_INVALID_SECURITY_DESC ERROR_INVALID_SECURITY_DESCR
#define RPC_S_ACCESS_DENIED ERROR_ACCESS_DENIED
#define RPC_S_SERVER_OUT_OF_MEMORY ERROR_NOT_ENOUGH_SERVER_MEMORY
#define RPC_X_NO_MEMORY RPC_S_OUT_OF_MEMORY
#define RPC_X_INVALID_BOUND RPC_S_INVALID_BOUND
#define RPC_X_INVALID_TAG RPC_S_INVALID_TAG
#define RPC_X_ENUM_VALUE_TOO_LARGE RPC_X_ENUM_VALUE_OUT_OF_RANGE
#define RPC_X_SS_CONTEXT_MISMATCH ERROR_INVALID_HANDLE
#define RPC_X_INVALID_BUFFER ERROR_INVALID_USER_BUFFER
#define RPC_X_INVALID_PIPE_OPERATION RPC_X_WRONG_PIPE_ORDER
#endif
