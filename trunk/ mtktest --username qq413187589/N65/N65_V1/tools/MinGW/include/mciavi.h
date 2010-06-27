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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/mciavi.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: mciavi.h,v 1.1 2007/05/17 07:25:31 bw Exp $
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
* $Log: mciavi.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/mciavi.h,v 1.1 2007/05/14 09:46:43 bw Exp $
*
* ~Id: mciavi.h,v 1.1 2007/05/14 09:46:43 bw Exp $
*
* ~Date: 2007/05/14 09:46:43 $
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
* ~Log: mciavi.h,v $
* Revision 1.1  2007/05/14 09:46:43  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/mciavi.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: mciavi.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: mciavi.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _MCIAVI_H
#define _MCIAVI_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#define MCI_MCIAVI_PLAY_WINDOW 0x1000000
#define	MCI_MCIAVI_PLAY_FULLSCREEN 0x2000000
#define MCI_MCIAVI_PLAY_FULLBY2	0x4000000
#define MCI_AVI_STATUS_FRAMES_SKIPPED 0x8001
#define MCI_AVI_STATUS_LAST_PLAY_SPEED	0x8002
#define MCI_AVI_STATUS_AUDIO_BREAKS	0x8003
#define MCI_AVI_SETVIDEO_DRAW_PROCEDURE	0x8000
#define MCI_AVI_SETVIDEO_PALETTE_COLOR	0x8100
#define MCI_AVI_SETVIDEO_PALETTE_HALFTONE 0x0000FFFF
#define MCIERR_AVI_OLDAVIFORMAT	(MCIERR_CUSTOM_DRIVER_BASE+100)
#define MCIERR_AVI_NOTINTERLEAVED	(MCIERR_CUSTOM_DRIVER_BASE+101)
#define MCIERR_AVI_NODISPDIB	(MCIERR_CUSTOM_DRIVER_BASE+102)
#define MCIERR_AVI_CANTPLAYFULLSCREEN	(MCIERR_CUSTOM_DRIVER_BASE+103)
#define MCIERR_AVI_TOOBIGFORVGA	(MCIERR_CUSTOM_DRIVER_BASE+104)
#define MCIERR_AVI_NOCOMPRESSOR (MCIERR_CUSTOM_DRIVER_BASE+105)
#define MCIERR_AVI_DISPLAYERROR (MCIERR_CUSTOM_DRIVER_BASE+106)
#define MCIERR_AVI_AUDIOERROR	(MCIERR_CUSTOM_DRIVER_BASE+107)
#define MCIERR_AVI_BADPALETTE	(MCIERR_CUSTOM_DRIVER_BASE+108)
#endif
