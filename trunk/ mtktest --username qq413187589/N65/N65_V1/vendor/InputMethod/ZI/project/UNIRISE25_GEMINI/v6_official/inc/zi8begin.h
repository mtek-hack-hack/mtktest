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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/InputMethod/ZI/project/U25_06B/v6_official/inc/zi8begin.h,v 1.1 2007/05/17 07:26:36 bw Exp $
*
* $Id: zi8begin.h,v 1.1 2007/05/17 07:26:36 bw Exp $
*
* $Date: 2007/05/17 07:26:36 $
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
* $Log: zi8begin.h,v $
* Revision 1.1  2007/05/17 07:26:36  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/* zi8begin.h
*/
/*****************************************************************************
* COPYRIGHT ZI AND SUBJECT TO CONFIDENTIALITY RESTRICTIONS                   *
*                                                                            *
* This file is the confidential and proprietary property of Zi Corporation   *
* of Canada, Inc. ("Zi") or one of its affiliates.                           *
**************************************************************************** */

/* This file provides a way for causing the compiler to allocate large tables
** in an appropriate portion of the address space of the target system.
** This is normally done through a compiler pragma.
*/

#ifdef ZI8_CHANGE_CONSTSEG
#pragma memory=constseg(ZI8_HUGECONST):huge
#endif 


