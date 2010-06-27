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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/wsnetbs.h,v 1.1 2007/05/17 07:25:37 bw Exp $
*
* $Id: wsnetbs.h,v 1.1 2007/05/17 07:25:37 bw Exp $
*
* $Date: 2007/05/17 07:25:37 $
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
* $Log: wsnetbs.h,v $
* Revision 1.1  2007/05/17 07:25:37  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/wsnetbs.h,v 1.1 2007/05/14 09:46:55 bw Exp $
*
* ~Id: wsnetbs.h,v 1.1 2007/05/14 09:46:55 bw Exp $
*
* ~Date: 2007/05/14 09:46:55 $
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
* ~Log: wsnetbs.h,v $
* Revision 1.1  2007/05/14 09:46:55  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/wsnetbs.h,v 1.2 2007/04/04 06:51:35 bw Exp $
*
* ~Id: wsnetbs.h,v 1.2 2007/04/04 06:51:35 bw Exp $
*
* ~Date: 2007/04/04 06:51:35 $
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
* ~Log: wsnetbs.h,v $
* Revision 1.2  2007/04/04 06:51:35  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _WSNETBS_H
#define _WSNETBS_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#define NETBIOS_NAME_LENGTH	16
#define NETBIOS_UNIQUE_NAME	0
#define NETBIOS_GROUP_NAME	1
#define NETBIOS_TYPE_QUICK_UNIQUE	2
#define NETBIOS_TYPE_QUICK_GROUP	3

#ifndef RC_INVOKED
typedef struct sockaddr_nb {
	short	snb_family;
	u_short	snb_type;
	char	snb_name[NETBIOS_NAME_LENGTH];
} SOCKADDR_NB, *PSOCKADDR_NB, *LPSOCKADDR_NB;
#define SET_NETBIOS_SOCKADDR(_snb,_type,_name,_port) \
{ \
	register int _i; \
	register char *_n = (_name); \
	register PSOCKADDR_NB _s = (_snb); \
	_s->snb_family = AF_NETBIOS; \
	_s->snb_type = (_type); \
	for (_i=0; _n[_i] != '\0' && _i<NETBIOS_NAME_LENGTH-1; _i++) { \
		_s->snb_name[_i] = _n[_i]; \
	} \
	for (; _i<NETBIOS_NAME_LENGTH-1; _i++) { \
		_s->snb_name[_i] = ' '; \
	} \
	_s->snb_name[NETBIOS_NAME_LENGTH-1] = (_port); \
}
#endif   /* RC_INVOKED */
#endif
