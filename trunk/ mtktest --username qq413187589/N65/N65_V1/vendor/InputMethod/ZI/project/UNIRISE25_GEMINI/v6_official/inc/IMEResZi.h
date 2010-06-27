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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/InputMethod/ZI/project/U25_06B/v6_official/inc/IMEResZi.h,v 1.3 2007/08/06 12:40:55 bw Exp $
*
* $Id: IMEResZi.h,v 1.3 2007/08/06 12:40:55 bw Exp $
*
* $Date: 2007/08/06 12:40:55 $
*
* $Name: 1.3 $
*
* $Locker$
*
* $Revision: 1.3 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: IMEResZi.h,v $
* Revision 1.3  2007/08/06 12:40:55  bw
* UNI@bw_20070806 12:01:01 使用新然输入法,精简资源的数组 ...不能精简
*
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
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   IMEResZi.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is header file for Zi IME Resource for Multiple Bin.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IME_Res_Zi_H_
#define _IME_Res_Zi_H_
// __CUSTPACK_MULTIBIN     Terry   BEGIN

#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_SM_CHINESE__)
#include "Zi8DatZH_Pans.h"
#elif defined(__MMI_ZI_TR_CHINESE__)
#include "Zi8DatZH_Hk.h"
#elif defined(__MMI_ZI_SM_CHINESE__)
#include "Zi8DatZH_Prc.h"
#endif

#if defined(__MMI_ZI_PRC_ENGLISH__)
#include "Zi8DatENPRC.h"
#elif defined(__MMI_ZI_UK_ENGLISH__)
#include "Zi8DatENUK.h"
#endif

#if defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
#include "Zi8DatRU.h"
#elif defined(__MMI_ZI_RUSSIAN__)
#include "Zi8DatRUM.h"
#endif

#if defined(__MMI_ZI_CA_FRENCH__)
#include "Zi8DatFRCA.h"
#elif defined(__MMI_ZI_EU_FRENCH__)
#include "Zi8DatFREU.h"
#endif

#if defined(__MMI_ZI_GERMAN__)
#include "Zi8DatDE.h"
#endif

#if defined(__MMI_ZI_ITALIAN__)
#include "Zi8DatIT.h"
#endif

#if defined(__MMI_ZI_EU_SPANISH__)
#include "Zi8DatESEU.h"
#elif defined(__MMI_ZI_SA_SPANISH__)
#include "Zi8DatESSA.h"
#endif

#if defined(__MMI_ZI_THAI__)
#include "Zi8DatTH.h"
#endif

#if defined(__MMI_ZI_ARABIC__)
#include "Zi8DatAR.h"
#endif

#if defined(__MMI_ZI_HINDI__)
#include "Zi8DatHI.h"
#endif

#if defined(__MMI_ZI_HEBREW__)
#include "Zi8DatIW.h"
#endif

#if defined(__MMI_ZI_EU_PORTUGUESE__)
#include "Zi8DatPTEU.h"
#elif defined(__MMI_ZI_SA_PORTUGUESE__)
#include "Zi8DatPTSA.h"
#elif defined(__MMI_ZI_BZ_PORTUGUESE__)
#include "Zi8DatPTBZ.h"
#endif

#if defined(__MMI_ZI_TURKISH__)
#include "Zi8DatTR.h"
#endif

#if defined(__MMI_ZI_NORWEGIAN__)
#include "Zi8DatNO.h"
#endif

#if defined(__MMI_ZI_POLISH__)
#include "Zi8DatPL.h"
#endif

#if defined(__MMI_ZI_INDONESIAN__)
#include "Zi8DatIN.h"
#endif

#if defined(__MMI_ZI_MALAY__)
#include "Zi8DatMS.h"
#endif

#if defined(__MMI_ZI_VIETNAMESE__)
#include "Zi8DatVI.h"
#endif

#if defined(__MMI_ZI_SLOVAK__)
#include "Zi8DatSKM.h"
#endif

#if defined(__MMI_ZI_DUTCH__)
#include "Zi8DatNLM.h"
#endif

#if defined(__MMI_ZI_SWEDISH__)
#include "Zi8DatSVM.h"
#endif

#if defined(__MMI_ZI_CROATIAN__)
#include "Zi8DatHRM.h"
#endif

#if defined(__MMI_ZI_ROMANIAN__)
#include "Zi8DatROM.h"
#endif

#if defined(__MMI_ZI_SLOVENIAN__)
#include "Zi8DatSLM.h"
#endif

#if defined(__MMI_ZI_GREEK__)
#include "Zi8DatELM.h"
#endif

#if defined(__MMI_ZI_CZECH__)
#include "Zi8DatCSM.h"
#endif

#if defined(__MMI_ZI_FINNISH__)
#include "Zi8DatFIM.h"
#endif

#if defined(__MMI_ZI_DANISH__)
#include "Zi8DatDAM.h"
#endif

#if defined(__MMI_ZI_HUNGARIAN__)
#include "Zi8DatHUM.h"
#endif


#ifndef MMI_ON_HARDWARE_P
__declspec(dllexport)
#endif

ZI8_LANGUAGE_ENTRY ZI8ROMDATA mtk_gIMELDBArray[] =
{
//Chinese
#if defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_ZI_SM_CHINESE__)
    {ZI8_LANG_ZH,     (void ZI8ROMPOINTER)&Zi8DatZH[0]},
#endif 
//English
#if defined(__MMI_ZI_PRC_ENGLISH__)
    {ZI8_LANG_EN,     (void ZI8ROMPOINTER)&Zi8DatENPRC30k[0]},
#elif defined(__MMI_ZI_UK_ENGLISH__)
    {ZI8_LANG_EN,     (void ZI8ROMPOINTER)&Zi8DatENUK30k[0]},
#endif
//Russian
#if defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
     {ZI8_LANG_RU,     (void ZI8ROMPOINTER)&Zi8DatRU[0]},
#elif defined(__MMI_ZI_RUSSIAN__)
        {ZI8_LANG_RU,     (void ZI8ROMPOINTER)&Zi8DatRUM[0]},
#endif
   
//French
#if defined(__MMI_ZI_CA_FRENCH__)
     {ZI8_LANG_FR,     (void ZI8ROMPOINTER)&Zi8DatFRCA[0]},
#elif defined(__MMI_ZI_EU_FRENCH__)
        {ZI8_LANG_FR,     (void ZI8ROMPOINTER)&Zi8DatFREU[0]},
#endif
   
//German
#if defined(__MMI_ZI_GERMAN__)
     {ZI8_LANG_DE,     (void ZI8ROMPOINTER)&Zi8DatDE[0]},
#endif
   
//Italian
#if defined(__MMI_ZI_ITALIAN__)
     {ZI8_LANG_IT,     (void ZI8ROMPOINTER)&Zi8DatIT[0]},
#endif
   
//Spanish
#if defined(__MMI_ZI_EU_SPANISH__)
     {ZI8_LANG_ES,     (void ZI8ROMPOINTER)&Zi8DatESEU[0]},
#elif defined(__MMI_ZI_SA_SPANISH__)
        {ZI8_LANG_ES,     (void ZI8ROMPOINTER)&Zi8DatESSA[0]},
#endif
   
//Thai
#if defined(__MMI_ZI_THAI__)
     {ZI8_LANG_TH,     (void ZI8ROMPOINTER)&Zi8DatTH[0]},
#endif

//Arabic
#if defined(__MMI_ZI_ARABIC__)
     {ZI8_LANG_AR,     (void ZI8ROMPOINTER)&Zi8DatAR[0]},
#endif

#if defined(__MMI_ZI_HINDI__)
     {ZI8_LANG_HI,     (void ZI8ROMPOINTER)&Zi8DatHI[0]},
#endif

#if defined(__MMI_ZI_HEBREW__)
     {ZI8_LANG_IW,     (void ZI8ROMPOINTER)&Zi8DatIW[0]},
#endif

#if defined(__MMI_ZI_EU_PORTUGUESE__)
    {ZI8_LANG_PT,	(void ZI8ROMPOINTER)&Zi8DatPT[0]},
#elif defined(__MMI_ZI_SA_PORTUGUESE__)
    {ZI8_LANG_PT,	(void ZI8ROMPOINTER)&Zi8DatPTSA[0]},
#elif defined(__MMI_ZI_BZ_PORTUGUESE__)
    {ZI8_LANG_PT,	(void ZI8ROMPOINTER)&Zi8DatPTBZ[0]},
#endif

#if defined(__MMI_ZI_TURKISH__)
    {ZI8_LANG_TR,	(void ZI8ROMPOINTER)&Zi8DatTR[0]},
#endif
   
#if defined(__MMI_ZI_INDONESIAN__)
    {ZI8_LANG_IN,     (void ZI8ROMPOINTER)&Zi8DatIN[0]},
#endif
   
#if defined(__MMI_ZI_MALAY__)
    {ZI8_LANG_MS,     (void ZI8ROMPOINTER)&Zi8DatMS[0]},
#endif
   
#if defined(__MMI_ZI_VIETNAMESE__)
    {ZI8_LANG_VI,     (void ZI8ROMPOINTER)&Zi8DatVI[0]},
#endif
   
#if defined(__MMI_ZI_NORWEGIAN__)
    {ZI8_LANG_NO,     (void ZI8ROMPOINTER)&Zi8DatNO[0]},
#endif

#if defined(__MMI_ZI_POLISH__)
    {ZI8_LANG_PL,     (void ZI8ROMPOINTER)&Zi8DatPL[0]},
#endif

#if defined(__MMI_ZI_SLOVAK__)
    {ZI8_LANG_SK,     (void ZI8ROMPOINTER)&Zi8DatSKM[0]},
#endif
 
#if defined(__MMI_ZI_DUTCH__)
    {ZI8_LANG_NL,     (void ZI8ROMPOINTER)&Zi8DatNLM[0]},
#endif  
 
#if defined(__MMI_ZI_SWEDISH__)
    {ZI8_LANG_SV,     (void ZI8ROMPOINTER)&Zi8DatSVM[0]},
#endif

#if defined(__MMI_ZI_CROATIAN__)
    {ZI8_LANG_HR,     (void ZI8ROMPOINTER)&Zi8DatHRM[0]},
#endif

#if defined(__MMI_ZI_ROMANIAN__)
    {ZI8_LANG_RO,     (void ZI8ROMPOINTER)&Zi8DatROM[0]},
#endif 

 #if defined(__MMI_ZI_SLOVENIAN__)
    {ZI8_LANG_SL,     (void ZI8ROMPOINTER)&Zi8DatSLM[0]}, 
#endif

#if defined(__MMI_ZI_GREEK__)
    {ZI8_LANG_EL,     (void ZI8ROMPOINTER)&Zi8DatELM[0]},
#endif

#if defined(__MMI_ZI_CZECH__)
    {ZI8_LANG_CS,     (void ZI8ROMPOINTER)&Zi8DatCSM[0]},
#endif

#if defined(__MMI_ZI_FINNISH__)
    {ZI8_LANG_FI,     (void ZI8ROMPOINTER)&Zi8DatFIM[0]},
#endif 

#if defined(__MMI_ZI_DANISH__)
    {ZI8_LANG_DA,     (void ZI8ROMPOINTER)&Zi8DatDAM[0]},
#endif

#if defined(__MMI_ZI_HUNGARIAN__)
    {ZI8_LANG_HU,     (void ZI8ROMPOINTER)&Zi8DatHUM[0]},
#endif

    {0,0}
};
// __CUSTPACK_MULTIBIN     Terry   END

#endif /*IME_RES_ZI*/