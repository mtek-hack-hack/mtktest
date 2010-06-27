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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/mcx.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: mcx.h,v 1.1 2007/05/17 07:25:31 bw Exp $
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
* $Log: mcx.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/mcx.h,v 1.1 2007/05/14 09:46:44 bw Exp $
*
* ~Id: mcx.h,v 1.1 2007/05/14 09:46:44 bw Exp $
*
* ~Date: 2007/05/14 09:46:44 $
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
* ~Log: mcx.h,v $
* Revision 1.1  2007/05/14 09:46:44  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/mcx.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: mcx.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: mcx.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _MCX_H
#define _MCX_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define DIALOPTION_BILLING 64
#define DIALOPTION_QUIET 128
#define DIALOPTION_DIALTONE 256
#define MDMVOLFLAG_LOW	1
#define MDMVOLFLAG_MEDIUM	2
#define MDMVOLFLAG_HIGH	4
#define MDMVOL_LOW	0
#define MDMVOL_MEDIUM	1
#define MDMVOL_HIGH	2
#define MDMSPKRFLAG_OFF	1
#define MDMSPKRFLAG_DIAL	2
#define MDMSPKRFLAG_ON	4
#define MDMSPKRFLAG_CALLSETUP	8
#define MDMSPKR_OFF	0
#define MDMSPKR_DIAL 1
#define MDMSPKR_ON	2
#define MDMSPKR_CALLSETUP	3
#define MDM_COMPRESSION	1
#define MDM_ERROR_CONTROL	2
#define MDM_FORCED_EC	4
#define MDM_CELLULAR	8
#define MDM_FLOWCONTROL_HARD	16
#define MDM_FLOWCONTROL_SOFT	32
#define MDM_CCITT_OVERRIDE	64
#define MDM_SPEED_ADJUST	128
#define MDM_TONE_DIAL	256
#define MDM_BLIND_DIAL	512
#define MDM_V23_OVERRIDE	1024
typedef struct _MODEMDEVCAPS {
	DWORD dwActualSize;
	DWORD dwRequiredSize;
	DWORD dwDevSpecificOffset;
	DWORD dwDevSpecificSize;
	DWORD dwModemProviderVersion;
	DWORD dwModemManufacturerOffset;
	DWORD dwModemManufacturerSize;
	DWORD dwModemModelOffset;
	DWORD dwModemModelSize;
	DWORD dwModemVersionOffset;
	DWORD dwModemVersionSize;
	DWORD dwDialOptions;
	DWORD dwCallSetupFailTimer;
	DWORD dwInactivityTimeout;
	DWORD dwSpeakerVolume;
	DWORD dwSpeakerMode;
	DWORD dwModemOptions;
	DWORD dwMaxDTERate;
	DWORD dwMaxDCERate;
	BYTE abVariablePortion[1];
} MODEMDEVCAPS,*PMODEMDEVCAPS,*LPMODEMDEVCAPS;
typedef struct _MODEMSETTINGS {
	DWORD dwActualSize;
	DWORD dwRequiredSize;
	DWORD dwDevSpecificOffset;
	DWORD dwDevSpecificSize;
	DWORD dwCallSetupFailTimer;
	DWORD dwInactivityTimeout;
	DWORD dwSpeakerVolume;
	DWORD dwSpeakerMode;
	DWORD dwPreferredModemOptions;
	DWORD dwNegotiatedModemOptions;
	DWORD dwNegotiatedDCERate;
	BYTE abVariablePortion[1];
} MODEMSETTINGS,*PMODEMSETTINGS,*LPMODEMSETTINGS;
#ifdef __cplusplus
}
#endif
#endif /* _MCX_H */
