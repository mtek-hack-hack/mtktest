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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/InputMethod/ZI/adaptation/src/zi8sdata.c,v 1.1 2007/05/17 07:26:35 bw Exp $
*
* $Id: zi8sdata.c,v 1.1 2007/05/17 07:26:35 bw Exp $
*
* $Date: 2007/05/17 07:26:35 $
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
* $Log: zi8sdata.c,v $
* Revision 1.1  2007/05/17 07:26:35  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*
 * zi8sdata.c
 * // This module contains a static language table that references
 * // The compiled version of data. This file is referenced from
 * // Zi8Initialize. 
 * //
 * // THIS FILE MUST BE MODIFIED TO PROVIDE THE DESIRED CONFIGURATION OF
 * // LANGUAGES. REFERENCES FROM THIS MODULE WILL CAUSE THE APPROPRIATE 
 * // DATASETS TO BE LINKED FROM THE LIBRARY. 
 */
#include "zi8api.h"
#include "MMI_features.h"
#if 0
#ifdef __MMI_ZI_DYNAMIC_LAN_LIB_INIT__
/* under construction !*/
#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_TAIWAN__)
/* under construction !*/
#elif defined(__MMI_ZI_TR_CHINESE__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_SM_CHINESE__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_PRC_ENGLISH__)
/* under construction !*/
#elif defined(__MMI_ZI_UK_ENGLISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
/* under construction !*/
#elif defined(__MMI_ZI_RUSSIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_CA_FRENCH__)
/* under construction !*/
#elif defined(__MMI_ZI_EU_FRENCH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_GERMAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_ITALIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_EU_SPANISH__)
/* under construction !*/
#elif defined(__MMI_ZI_SA_SPANISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_THAI__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_ARABIC__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_HINDI__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_HEBREW__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_EU_PORTUGUESE__)
/* under construction !*/
#elif defined(__MMI_ZI_SA_PORTUGUESE__)
/* under construction !*/
#elif defined(__MMI_ZI_BZ_PORTUGUESE__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_TURKISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_INDONESIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_MALAY__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_VIETNAMESE__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_POLISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_NORWEGIAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_SLOVAK__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_DUTCH__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_SWEDISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_CROATIAN__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_ROMANIAN__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_SLOVENIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_GREEK__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_CZECH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_FINNISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_DANISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_HUNGARIAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_PRC_ENGLISH__) ||defined(__MMI_ZI_UK_ENGLISH__) 
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_ZI_SM_CHINESE__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_GERMAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_ITALIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_THAI__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_ARABIC__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_HINDI__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_HEBREW__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_EU_PORTUGUESE__)||defined(__MMI_ZI_SA_PORTUGUESE__)||defined(__MMI_ZI_BZ_PORTUGUESE__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_TURKISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_INDONESIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_MALAY__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_VIETNAMESE__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_POLISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_NORWEGIAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_SLOVAK__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_DUTCH__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_SWEDISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_CROATIAN__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_ROMANIAN__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_SLOVENIAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_GREEK__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_CZECH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_FINNISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_DANISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_HUNGARIAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_TAIWAN__)
/* under construction !*/
/* under construction !*/
	#if defined(__MMI_ZI_PRC_ENGLISH__)
/* under construction !*/
/* under construction !*/
	#elif defined(__MMI_ZI_UK_ENGLISH__) 
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
	#if defined(__MMI_ZI_TR_CHINESE__)
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
    #if defined(__MMI_ZI_THAI__)
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_RUSSIAN__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_ZI_CA_FRENCH__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_ZI_EU_FRENCH__)
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_ZI_GERMAN__)
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_ZI_ITALIAN__)
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_ZI_EU_SPANISH__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_ZI_SA_SPANISH__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI_ARABIC__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
		  #if defined(__MMI_ZI_HINDI__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
/* under construction !*/
		  #if defined(__MMI_ZI_HEBREW__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
#if defined(__MMI_ZI_EU_PORTUGUESE__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_ZI_SA_PORTUGUESE__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_ZI_BZ_PORTUGUESE__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI_TURKISH__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
        #if defined(__MMI_ZI_INDONESIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
        #if defined(__MMI_ZI_MALAY__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
        #if defined(__MMI_ZI_VIETNAMESE__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI_POLISH__)
/* under construction !*/
/* under construction !*/
	     #endif
        #if defined(__MMI_ZI_NORWEGIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI_SWEDISH__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI_SLOVAK__)
/* under construction !*/
/* under construction !*/
	     #endif
		 #if defined(__MMI_ZI_DUTCH__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
        #if defined(__MMI_ZI_CROATIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
        #if defined(__MMI_ZI_ROMANIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
        #if defined(__MMI_ZI_SLOVENIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
        #if defined(__MMI_ZI_GREEK__)
/* under construction !*/
/* under construction !*/
	     #endif
        #if defined(__MMI_ZI_CZECH__)
/* under construction !*/
/* under construction !*/
	     #endif
        #if defined(__MMI_ZI_FINNISH__)
/* under construction !*/
/* under construction !*/
	     #endif
		  #if defined(__MMI_ZI_DANISH__)
/* under construction !*/
/* under construction !*/
	     #endif
		  #if defined(__MMI_ZI_HUNGARIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_SM_CHINESE__)
/* under construction !*/
/* under construction !*/
	#if defined(__MMI_ZI_PRC_ENGLISH__)
/* under construction !*/
/* under construction !*/
	#elif defined(__MMI_ZI_UK_ENGLISH__) 
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
	#if defined(__MMI_ZI_SM_CHINESE__)
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
    #if defined(__MMI_ZI_THAI__)
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_RUSSIAN__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_ZI_CA_FRENCH__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_ZI_EU_FRENCH__)
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_ZI_GERMAN__)
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_ZI_ITALIAN__)
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_ZI_EU_SPANISH__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_ZI_SA_SPANISH__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI_ARABIC__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
		  #if defined(__MMI_ZI_HINDI__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
/* under construction !*/
	     #if defined(__MMI_ZI_HEBREW__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
#if defined(__MMI_ZI_EU_PORTUGUESE__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_ZI_SA_PORTUGUESE__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_ZI_BZ_PORTUGUESE__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI_TURKISH__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
        #if defined(__MMI_ZI_INDONESIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
        #if defined(__MMI_ZI_MALAY__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
        #if defined(__MMI_ZI_VIETNAMESE__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI_POLISH__)
/* under construction !*/
/* under construction !*/
	     #endif
	     #if defined(__MMI_ZI_NORWEGIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI_SLOVAK__)
/* under construction !*/
/* under construction !*/
	     #endif
		 #if defined(__MMI_ZI_DUTCH__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_ZI_SWEDISH__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
        #if defined(__MMI_ZI_CROATIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
        #if defined(__MMI_ZI_ROMANIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
        #if defined(__MMI_ZI_SLOVENIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
   #if defined(__MMI_ZI_GREEK__)
/* under construction !*/
/* under construction !*/
	     #endif
        #if defined(__MMI_ZI_CZECH__)
/* under construction !*/
/* under construction !*/
	     #endif
        #if defined(__MMI_ZI_FINNISH__)
/* under construction !*/
/* under construction !*/
	     #endif
		  #if defined(__MMI_ZI_DANISH__)
/* under construction !*/
/* under construction !*/
	     #endif
		  #if defined(__MMI_ZI_HUNGARIAN__)
/* under construction !*/
/* under construction !*/
	     #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_SM_CHINESE__)
/* under construction !*/
#elif defined(__MMI_ZI_TR_CHINESE__)
/* under construction !*/
#elif defined(__MMI_ZI_SM_CHINESE__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_PRC_ENGLISH__)
/* under construction !*/
#elif defined(__MMI_ZI_UK_ENGLISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
/* under construction !*/
#elif defined(__MMI_ZI_RUSSIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_CA_FRENCH__)
/* under construction !*/
#elif defined(__MMI_ZI_EU_FRENCH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_GERMAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_ITALIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_EU_SPANISH__)
/* under construction !*/
#elif defined(__MMI_ZI_SA_SPANISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_THAI__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_ARABIC__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_HINDI__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_HEBREW__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_EU_PORTUGUESE__)
/* under construction !*/
#elif defined(__MMI_ZI_SA_PORTUGUESE__)
/* under construction !*/
#elif defined(__MMI_ZI_BZ_PORTUGUESE__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_TURKISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_INDONESIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_MALAY__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_VIETNAMESE__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_POLISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_NORWEGIAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_SLOVAK__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_DUTCH__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_SWEDISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_CROATIAN__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_ROMANIAN__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_SLOVENIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_GREEK__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_CZECH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_FINNISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_DANISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_HUNGARIAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_ZI_SM_CHINESE__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_ZI_PRC_ENGLISH__)
/* under construction !*/
#elif defined(__MMI_ZI_UK_ENGLISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
/* under construction !*/
#elif defined(__MMI_ZI_RUSSIAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_CA_FRENCH__)
/* under construction !*/
#elif defined(__MMI_ZI_EU_FRENCH__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_GERMAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_ITALIAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_EU_SPANISH__)
/* under construction !*/
#elif defined(__MMI_ZI_SA_SPANISH__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_THAI__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_ARABIC__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_HINDI__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_HEBREW__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_EU_PORTUGUESE__)
/* under construction !*/
#elif defined(__MMI_ZI_SA_PORTUGUESE__)
/* under construction !*/
#elif defined(__MMI_ZI_BZ_PORTUGUESE__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_TURKISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_INDONESIAN__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_MALAY__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_VIETNAMESE__)
/* under construction !*/
#endif
/* under construction !*/
 #if defined(__MMI_ZI_POLISH__)
/* under construction !*/
#endif
	 #if defined(__MMI_ZI_NORWEGIAN__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_SLOVAK__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_DUTCH__)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#if defined(__MMI_ZI_SWEDISH__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ZI_CROATIAN__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_ROMANIAN__)
/* under construction !*/
#endif  
#if defined(__MMI_ZI_SLOVENIAN__)
/* under construction !*/
#endif   
/* under construction !*/
#if defined(__MMI_ZI_GREEK__)
/* under construction !*/
#endif  
#if defined(__MMI_ZI_CZECH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_FINNISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_DANISH__)
/* under construction !*/
#endif
#if defined(__MMI_ZI_HUNGARIAN__)
/* under construction !*/
#endif  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* 0 */ /* for Lang Pack */

