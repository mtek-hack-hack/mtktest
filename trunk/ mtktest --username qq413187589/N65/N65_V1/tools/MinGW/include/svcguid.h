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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/svcguid.h,v 1.1 2007/05/17 07:25:35 bw Exp $
*
* $Id: svcguid.h,v 1.1 2007/05/17 07:25:35 bw Exp $
*
* $Date: 2007/05/17 07:25:35 $
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
* $Log: svcguid.h,v $
* Revision 1.1  2007/05/17 07:25:35  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/svcguid.h,v 1.1 2007/05/14 09:46:52 bw Exp $
*
* ~Id: svcguid.h,v 1.1 2007/05/14 09:46:52 bw Exp $
*
* ~Date: 2007/05/14 09:46:52 $
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
* ~Log: svcguid.h,v $
* Revision 1.1  2007/05/14 09:46:52  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/svcguid.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Id: svcguid.h,v 1.2 2007/04/04 06:51:34 bw Exp $
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
* ~Log: svcguid.h,v $
* Revision 1.2  2007/04/04 06:51:34  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _SVCGUID_H
#define _SVCGUID_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SVCID_NETWARE(_SapId) \
	{ (0x000B << 16) | (_SapId), 0, 0, { 0xC0,0,0,0,0,0,0,0x46 } }

#define SAPID_FROM_SVCID_NETWARE(_g) \
	((WORD)(_g->Data1 & 0xFFFF))

#define SET_NETWARE_SVCID(_g,_SapId) { \
	(_g)->Data1 = (0x000B << 16 ) | (_SapId); \
	(_g)->Data2 = 0; \
	(_g)->Data3 = 0; \
	(_g)->Data4[0] = 0xC0; \
	(_g)->Data4[1] = 0x0; \
	(_g)->Data4[2] = 0x0; \
	(_g)->Data4[3] = 0x0; \
	(_g)->Data4[4] = 0x0; \
	(_g)->Data4[5] = 0x0; \
	(_g)->Data4[6] = 0x0; \
	(_g)->Data4[7] = 0x46; }

#ifdef __cplusplus
}
#endif
#endif
