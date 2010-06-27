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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/cderr.h,v 1.1 2007/05/17 07:25:26 bw Exp $
*
* $Id: cderr.h,v 1.1 2007/05/17 07:25:26 bw Exp $
*
* $Date: 2007/05/17 07:25:26 $
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
* $Log: cderr.h,v $
* Revision 1.1  2007/05/17 07:25:26  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/cderr.h,v 1.1 2007/05/14 09:46:36 bw Exp $
*
* ~Id: cderr.h,v 1.1 2007/05/14 09:46:36 bw Exp $
*
* ~Date: 2007/05/14 09:46:36 $
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
* ~Log: cderr.h,v $
* Revision 1.1  2007/05/14 09:46:36  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/cderr.h,v 1.2 2007/04/04 06:51:30 bw Exp $
*
* ~Id: cderr.h,v 1.2 2007/04/04 06:51:30 bw Exp $
*
* ~Date: 2007/04/04 06:51:30 $
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
* ~Log: cderr.h,v $
* Revision 1.2  2007/04/04 06:51:30  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _CDERR_H
#define _CDERR_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#define CDERR_DIALOGFAILURE	0xFFFF
#define CDERR_GENERALCODES	0x0000
#define CDERR_STRUCTSIZE	0x0001
#define CDERR_INITIALIZATION	0x0002
#define CDERR_NOTEMPLATE	0x0003
#define CDERR_NOHINSTANCE	0x0004
#define CDERR_LOADSTRFAILURE	0x0005
#define CDERR_FINDRESFAILURE	0x0006
#define CDERR_LOADRESFAILURE	0x0007
#define CDERR_LOCKRESFAILURE	0x0008
#define CDERR_MEMALLOCFAILURE	0x0009
#define CDERR_MEMLOCKFAILURE	0x000A
#define CDERR_NOHOOK	0x000B
#define CDERR_REGISTERMSGFAIL	0x000C
#define PDERR_PRINTERCODES	0x1000
#define PDERR_SETUPFAILURE	0x1001
#define PDERR_PARSEFAILURE	0x1002
#define PDERR_RETDEFFAILURE	0x1003
#define PDERR_LOADDRVFAILURE	0x1004
#define PDERR_GETDEVMODEFAIL	0x1005
#define PDERR_INITFAILURE	0x1006
#define PDERR_NODEVICES	0x1007
#define PDERR_NODEFAULTPRN	0x1008
#define PDERR_DNDMMISMATCH	0x1009
#define PDERR_CREATEICFAILURE	0x100A
#define PDERR_PRINTERNOTFOUND	0x100B
#define PDERR_DEFAULTDIFFERENT	0x100C
#define CFERR_CHOOSEFONTCODES	0x2000
#define CFERR_NOFONTS	0x2001
#define CFERR_MAXLESSTHANMIN	0x2002
#define FNERR_FILENAMECODES	0x3000
#define FNERR_SUBCLASSFAILURE	0x3001
#define FNERR_INVALIDFILENAME	0x3002
#define FNERR_BUFFERTOOSMALL	0x3003
#define FRERR_FINDREPLACECODES	0x4000
#define FRERR_BUFFERLENGTHZERO	0x4001
#define CCERR_CHOOSECOLORCODES	0x5000
#endif
