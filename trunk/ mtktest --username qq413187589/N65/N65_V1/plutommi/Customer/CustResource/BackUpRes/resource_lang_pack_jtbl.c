/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   resource_ime_jtbl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements indirect IME jumps table for multi-load.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

// __CUSTPACK_MULTIBIN     Terry   BEGIN

#include "IMERes.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"//071706 menu resource
#include "FontRes.h"
#include "kal_release.h"
#include "custom_jump_tbl.h"
#include "verno.h"

#if defined(__MMI_T9_V7__)
#if defined(__MMI_T9_TR_CHINESE__)
extern T9ChineseData const T9FARDATA l0104;
#endif
#if defined(__MMI_T9_SM_CHINESE__)
extern T9ChineseData const T9FARDATA l0204;
#endif
#else
#if defined(__MMI_T9_TR_CHINESE__)
extern T9ChineseData const FARDATA l0104;
#endif
#if defined(__MMI_T9_SM_CHINESE__)
extern T9ChineseData const FARDATA l0204;
#endif
#endif

#ifdef __MTK_TARGET__
#pragma arm section rwdata = "RESOURCE_JUMP_TBL"
#endif /* __MTK_TARGET__ */

Type_Preamble_Content LangPackResPreamble = {
	VERNO_STR,
	(kal_uint32)(RESOURCE_TYPE_LANG_PACK + CURRENT_IME_RES_VERSION), 
	CONST_RES_LANG_PACK_ADDR,
	CONST_RES_LANG_PACK_TBL_SIZE,
	CONST_RES_LANG_PACK_CONTENT_SIZE, 
	(kal_uint32)MAGIC_NUMBER
};

#ifdef __MTK_TARGET__
#pragma arm section rwdata
#endif /* __MTK_TARGET__ */

extern const U16 mtk_gMaxDeployedLangs;
extern const sLanguageDetails mtk_gLanguageArray[];

extern const StringResList	mtk_gStringList[];

extern const sIMEModeDetails mtk_gIMEModeArray[];
extern const sIMEModeDetails mtk_gIMEQSearchModeArray[];
extern const sIMELDBDetails mtk_gIMELDBArray[];
extern const sIMEModuleDetails mtk_gIMEModule;
extern const CUSTOM_MENU mtk_nCustMenus[];//071706 menu resource

void* langpack2ndJumpTbl[] = {
					    (void*) mtk_gLanguageArray, (void*) &mtk_gMaxDeployedLangs,

					    (void*) mtk_gStringList,
					    					    
					    (void*) mtk_gIMEModeArray, (void*) mtk_gIMEQSearchModeArray
                                           ,(void*) mtk_gIMELDBArray, (void*) &mtk_gIMEModule
#if defined(__MMI_T9_TR_CHINESE__)
                                          ,(void*) &l0104
#else
                                          ,0
#endif
#if defined(__MMI_T9_SM_CHINESE__)
                                          , (void*) &l0204
#else
                                          ,0
#endif
                                          ,(void*) mtk_nCustMenus//071706 menu resource
                                           };
// __CUSTPACK_MULTIBIN     Terry   END
