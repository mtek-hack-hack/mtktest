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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/plutommi/mmi/MiscFramework/MiscFrameworkSrc/ArabicShapingEngine.c,v 1.2 2007/06/15 05:13:46 bw Exp $
*
* $Id: ArabicShapingEngine.c,v 1.2 2007/06/15 05:13:46 bw Exp $
*
* $Date: 2007/06/15 05:13:46 $
*
* $Name: 1.2 $
*
* $Locker$
*
* $Revision: 1.2 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: ArabicShapingEngine.c,v $
* Revision 1.2  2007/06/15 05:13:46  bw
* UNI@bw_20070614 16:11:36 因ArabicStringShape2 无定义, 使用 ArabicShapeEngine2 替换
*
* Revision 1.1  2007/05/17 07:22:42  bw
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * ArabicShapingEngine.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is implemenation for ArabicShapingEngine
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"


#ifdef __MMI_ARSHAPING_ENGINE__
#include "PixtelDataTypes.h"
#include "ArabicShapingEngine.h"
#include "string.h"

//Huyanwei Add It
#include "ArabicGProt.h"

const ARABIC_SHAPE_TABLE glyph_base_Tb[] = 
{

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA */

    {N_HAMZA, N_HAMZA, N_HAMZA, N_HAMZA},

    /* MADDA_ON_ALEF */

    {N_MADDA_ON_ALEF, L_MADDA_ON_ALEF, R_MADDA_ON_ALEF, M_MADDA_ON_ALEF},

    /* HAMZA_ON_ALEF */

    {N_HAMZA_ON_ALEF, L_HAMZA_ON_ALEF, R_HAMZA_ON_ALEF, M_HAMZA_ON_ALEF},

    /* HAMZA_ON_WOW */

    {N_HAMZA_ON_WOW, L_HAMZA_ON_WOW, R_HAMZA_ON_WOW, M_HAMZA_ON_WOW},

    /* HAMZA_UNDER_ALEF */

    {N_HAMZA_UNDER_ALEF, L_HAMZA_UNDER_ALEF, R_HAMZA_UNDER_ALEF, M_HAMZA_UNDER_ALEF},

    /* HAMZA_ON_YEH */

    {N_HAMZA_ON_YEH, L_HAMZA_ON_YEH, R_HAMZA_ON_YEH, M_HAMZA_ON_YEH},

    /* ALEF */

    {N_ALEF, L_ALEF, R_ALEF, M_ALEF},

    /* BEH */

    {N_BEH, L_BEH, R_BEH, M_BEH},

    /* TEH_MARBUTA */

    {N_TEH_MARBUTA, L_TEH_MARBUTA, R_TEH_MARBUTA, M_TEH_MARBUTA},

    /* TEH */

    {N_TEH, L_TEH, R_TEH, M_TEH},

    /* THEH */

    {N_THEH, L_THEH, R_THEH, M_THEH},

    /* JEEM */

    {N_JEEM, L_JEEM, R_JEEM, M_JEEM},

    /* HAH */

    {N_HAH, L_HAH, R_HAH, M_HAH},

    /* KHAH */

    {N_KHAH, L_KHAH, R_KHAH, M_KHAH},

    /* DAL */

    {N_DAL, L_DAL, R_DAL, M_DAL},

    /* THAL */

    {N_THAL, L_THAL, R_THAL, M_THAL},

    /* REH */

    {N_REH, L_REH, R_REH, M_REH},

    /* ZAIN */

    {N_ZAIN, L_ZAIN, R_ZAIN, M_ZAIN},

    /* SEEN */

    {N_SEEN, L_SEEN, R_SEEN, M_SEEN},

    /* SHEEN */

    {N_SHEEN, L_SHEEN, R_SHEEN, M_SHEEN},

    /* SAD */

    {N_SAD, L_SAD, R_SAD, M_SAD},

    /* DAD */

    {N_DAD, L_DAD, R_DAD, M_DAD},

    /* TAH */

    {N_TAH, L_TAH, R_TAH, M_TAH},

    /* ZAH */

    {N_ZAH, L_ZAH, R_ZAH, M_ZAH},

    /* AIN */

    {N_AIN, L_AIN, R_AIN, M_AIN},

    /* GHAIN */

    {N_GHAIN, L_GHAIN, R_GHAIN, M_GHAIN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TATWEEL */

    {N_TATWEEL, N_TATWEEL, N_TATWEEL, N_TATWEEL},

    /* FEH */

    {N_FEH, L_FEH, R_FEH, M_FEH},

    /* QAF */

    {N_QAF, L_QAF, R_QAF, M_QAF},

    /* KAF */

    {N_KAF, L_KAF, R_KAF, M_KAF},

    /* LAM */

    {N_LAM, L_LAM, R_LAM, M_LAM},

    /* MEEM */

    {N_MEEM, L_MEEM, R_MEEM, M_MEEM},

    /* NOON */

    {N_NOON, L_NOON, R_NOON, M_NOON},

    /* HEH */

    {N_HEH, L_HEH, R_HEH, M_HEH},

    /* WAW */

    {N_WAW, L_WAW, R_WAW, M_WAW},

    /* ALEF_MAKSURA */

    {N_ALEF_MAKSURA, L_ALEF_MAKSURA, R_ALEF_MAKSURA, M_ALEF_MAKSURA},

    /* YEH */

    {N_YEH, L_YEH, R_YEH, M_YEH},
    /* PMT START PERSIAN */

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* PEH */

    {N_PEH, L_PEH, R_PEH, M_PEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TCHEH */

    {N_TCHEH, L_TCHEH, R_TCHEH, M_TCHEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* JEH */

    {N_JEH, L_JEH, R_JEH, M_JEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* KHEHEH */

    {N_KHEHEH, L_KHEHEH, R_KHEHEH, M_KHEHEH},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* GAF */
    {N_GAF, L_GAF, R_GAF, M_GAF},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* FARSIYEH */

    {N_FARSIYEH, L_FARSIYEH, R_FARSIYEH, M_FARSIYEH}

};

/* START PMTARABIC 20060904 */

const ARABIC_SHAPE_TABLE glyph_Tb_B[] = 
{
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA */

    {N_HAMZA_FORM_B, N_HAMZA_FORM_B, N_HAMZA_FORM_B, N_HAMZA_FORM_B},

    /* MADDA_ON_ALEF */

    {N_MADDA_ON_ALEF_FORM_B, L_MADDA_ON_ALEF, R_MADDA_ON_ALEF, M_MADDA_ON_ALEF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA_ON_ALEF */

    {N_HAMZA_ON_ALEF_FORM_B, L_HAMZA_ON_ALEF, R_HAMZA_ON_ALEF, M_HAMZA_ON_ALEF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA_ON_WOW */

    {N_HAMZA_ON_WOW_FORM_B, L_HAMZA_ON_WOW, R_HAMZA_ON_WOW, M_HAMZA_ON_WOW},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA_UNDER_ALEF */

    {N_HAMZA_UNDER_ALEF_FORM_B, L_HAMZA_UNDER_ALEF, R_HAMZA_UNDER_ALEF, M_HAMZA_UNDER_ALEF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA_ON_YEH */

    {N_HAMZA_ON_YEH_FORM_B, L_HAMZA_ON_YEH, R_HAMZA_ON_YEH, M_HAMZA_ON_YEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* ALEF */

    {N_ALEF_FORM_B, L_ALEF, R_ALEF, M_ALEF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* BEH */

    {N_BEH_FORM_B, L_BEH, R_BEH, M_BEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TEH_MARBUTA */

    {N_TEH_MARBUTA_FORM_B, L_TEH_MARBUTA, R_TEH_MARBUTA, M_TEH_MARBUTA},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TEH */

    {N_TEH_FORM_B, L_TEH, R_TEH, M_TEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* THEH */

    {N_THEH_FORM_B, L_THEH, R_THEH, M_THEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* JEEM */

    {N_JEEM_FORM_B, L_JEEM, R_JEEM, M_JEEM},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAH */

    {N_HAH_FORM_B, L_HAH, R_HAH, M_HAH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* KHAH */

    {N_KHAH_FORM_B, L_KHAH, R_KHAH, M_KHAH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* DAL */

    {N_DAL_FORM_B, L_DAL, R_DAL, M_DAL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* THAL */

    {N_THAL_FORM_B, L_THAL, R_THAL, M_THAL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* REH */

    {N_REH_FORM_B, L_REH, R_REH, M_REH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* ZAIN */

    {N_ZAIN_FORM_B, L_ZAIN, R_ZAIN, M_ZAIN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* SEEN */

    {N_SEEN_FORM_B, L_SEEN, R_SEEN, M_SEEN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* SHEEN */

    {N_SHEEN_FORM_B, L_SHEEN, R_SHEEN, M_SHEEN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* SAD */

    {N_SAD_FORM_B, L_SAD, R_SAD, M_SAD},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* DAD */

    {N_DAD_FORM_B, L_DAD, R_DAD, M_DAD},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TAH */

    {N_TAH_FORM_B, L_TAH, R_TAH, M_TAH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* ZAH */

    {N_ZAH_FORM_B, L_ZAH, R_ZAH, M_ZAH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* AIN */

    {N_AIN_FORM_B, L_AIN, R_AIN, M_AIN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* GHAIN */

    {N_GHAIN_FORM_B, L_GHAIN, R_GHAIN, M_GHAIN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},    

    /* FEH */

    {N_FEH_FORM_B, L_FEH, R_FEH, M_FEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* QAF */

    {N_QAF_FORM_B, L_QAF, R_QAF, M_QAF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* KAF */

    {N_KAF_FORM_B, L_KAF, R_KAF, M_KAF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* LAM */

    {N_LAM_FORM_B, L_LAM, R_LAM, M_LAM},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* MEEM */

    {N_MEEM_FORM_B, L_MEEM, R_MEEM, M_MEEM},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NOON */

    {N_NOON_FORM_B, L_NOON, R_NOON, M_NOON},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HEH */

    {N_HEH_FORM_B, L_HEH, R_HEH, M_HEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* WAW */

    {N_WAW_FORM_B, L_WAW, R_WAW, M_WAW},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* ALEF_MAKSURA */

    {N_ALEF_MAKSURA_FORM_B, L_ALEF_MAKSURA, R_ALEF_MAKSURA, M_ALEF_MAKSURA},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* YEH */

    {N_YEH_FORM_B, L_YEH, R_YEH, M_YEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
};


//PMT PERSIAN START - Ailsa
const ARABIC_SHAPE_TABLE glyph_Tb_A[] = 
{
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* PEH */

    {N_PEH_FORM_A, L_PEH, R_PEH, M_PEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TCHEH */

    {N_TCHEH_FORM_A, L_TCHEH, R_TCHEH, M_TCHEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* JEH */

    {N_JEH_FORM_A, L_JEH, R_JEH, M_JEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* KHEHEH */

    {N_KHEHEH_FORM_A, L_KHEHEH, R_KHEHEH, M_KHEHEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* GAF */

    {N_GAF_FORM_A, L_GAF, R_GAF, M_GAF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* FARSIYEH */

    {N_FARSIYEH_FORM_A, L_FARSIYEH, R_FARSIYEH, M_FARSIYEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL}

};
//PMT PERSIAN END - Ailsa

const LIGATURE_INFO_TABLE L_LAM_Tbl[] = 
{

    /* (Lam)l + (Madda_on_alef)r */
    {2, 1, LANGUAGE_FOR_LIGATURE, {L_LAM, R_MADDA_ON_ALEF, 0x0}, {N_MADDA_ON_LAMALEF, 0x0}},
	/* (Lam)l + (Hamza_on_alef)r */
    {2, 1, LANGUAGE_FOR_LIGATURE, {L_LAM, R_HAMZA_ON_ALEF, 0x0}, {N_HAMZA_ON_LAMALEF, 0x0}},
    /* (Lam)l + (Hamza_under_alef)r */
    {2, 1, LANGUAGE_FOR_LIGATURE, {L_LAM, R_HAMZA_UNDER_ALEF, 0x0}, {N_HAMZA_UNDER_LAMALEF, 0x0}},
	/* (Lam)l + (Alef)r */
    {2, 1, LANGUAGE_FOR_LIGATURE, {L_LAM, R_ALEF, 0x0}, {N_LAMALEF, 0x0}},
	/* (Lam)l + (Alef)m + (Hamza)n */
    {3, 1, LANGUAGE_FOR_LIGATURE, {L_LAM, M_ALEF, N_HAMZA, 0x0}, {N_HAMZA_ON_LAMALEF, 0x0}}

};

const LIGATURE_INFO_TABLE M_LAM_Tbl[] = 
{

    /* (Lam)m + (Madda_on_alef)r */
    {2, 1, LANGUAGE_FOR_LIGATURE, {M_LAM, R_MADDA_ON_ALEF, 0x0}, {R_MADDA_ON_LAMALEF, 0x0}},
	/* (Lam)m + (Hamza_on_alef)r */
    {2, 1, LANGUAGE_FOR_LIGATURE, {M_LAM, R_HAMZA_ON_ALEF, 0x0}, {R_HAMZA_ON_LAMALEF, 0x0}},
    /* (Lam)m + (Hamza_under_alef)r */
    {2, 1, LANGUAGE_FOR_LIGATURE, {M_LAM, R_HAMZA_UNDER_ALEF, 0x0}, {R_HAMZA_UNDER_LAMALEF, 0x0}},
	/* (Lam)m + (Alef)r */
    {2, 1, LANGUAGE_FOR_LIGATURE, {M_LAM, R_ALEF, 0x0}, {R_LAMALEF, 0x0}},
	/* (Lam)m + (Alef)m + (Hamza)n */
    {3, 1, LANGUAGE_FOR_LIGATURE, {M_LAM, M_ALEF, N_HAMZA, 0x0}, {R_HAMZA_ON_LAMALEF, 0x0}}

};

const ARABIC_MAIN_TABLE Arabic_base_Tbl[] = 
{
	{NULL, 0, 0} //0x0620
    ,
	{NULL, 0, 0} //0x0621
    ,
	{NULL, 0, 0} //0x0622
    ,
	{NULL, 0, 0} //0x0623
    ,
	{NULL, 0, 0} //0x0624
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
	
};

const ARABIC_MAIN_TABLE Arabic_Tbl_B[] = 
{
	{NULL, 0, 0}   //FE70
    ,
	{NULL, 0, 0}   //FE71
    ,
	{NULL, 0, 0}   //FE72
    ,
	{NULL, 0, 0}   //FE73
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,	
    {L_LAM_Tbl, sizeof(L_LAM_Tbl) / sizeof(L_LAM_Tbl[0]), 3}
    ,
    {M_LAM_Tbl, sizeof(M_LAM_Tbl) / sizeof(M_LAM_Tbl[0]), 3}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    /* PMT END PERSIAN */
};

/* PMT START PERSIAN */
const ARABIC_MAIN_TABLE Arabic_Tbl_A[] = 
{
    {NULL, 0, 0}    /* 0xFB50 */
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}    
};

const U8 g_arabic_base_char_array[] = 
{
    FALSE, //0x0620
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,    
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    FALSE,
    TRUE,
    TRUE,

    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE
};

const U8 g_arabic_form_A_char_array[] = 
{
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE
//PMT PERSIAN start- add by Ailsa
};

const U8 g_arabic_form_B_char_array[] =
{
    FALSE,  //FE70
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,    
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,    
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,    
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,    
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,    
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,    
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,    
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,    
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,    
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,    
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,    
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,    
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,    
    FALSE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,    
    FALSE,
    TRUE,
    FALSE,
    TRUE,
    FALSE,
    FALSE,    
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,    
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE
};

/* PMT END PERSIAN */
/*UNI@bw_20070614 16:11:36 因ArabicStringShape2 无定义, 使用 ArabicShapeEngine2 替换*/
void ArabicStringShape2(PU16 length, PU16 text_buffer, PU16 pOrgToSha, PU16 pShaToOrg)
{
      ArabicShapeEngine2(length, text_buffer, pOrgToSha, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  ArabicShapeEngine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [IN]        
 *  text_buffer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ArabicShapeEngine(PU16 length, PU16 text_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ArabicShapeEngine2(length, text_buffer, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  ArabicShapeEngine2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [IN]        
 *  text_buffer     [IN]        
 *  pOrgToSha       [IN]        
 *  pShaToOrg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ArabicShapeEngine2(PU16 length, PU16 text_buffer, PU16 pOrgToSha, PU16 pShaToOrg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const ARABIC_SHAPE_TABLE *glyph_form = glyph_base_Tb;
    U16 preChar = 0;
    U16 postChar = 0;
    U16 current_character;
    U16 count = 0;
    U16 temp_length = *length;
	BOOL is_arabic_char_present = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (temp_length)
    {
        current_character = text_buffer[count];

        if (UI_ARABIC_FORM_B_RANGE(current_character))
        {
            glyph_form = glyph_Tb_B;
        }
        else if (UI_ARABIC_FORM_A_RANGE(current_character))
        {
            glyph_form = glyph_Tb_A;
        }
        else
        {
            glyph_form = glyph_base_Tb;
        }
        postChar = text_buffer[count + 1];
        if (temp_length == 1)
        {
            postChar = 0;
        }
        
        if (UI_ARABIC_CHARACTER_RANGE(current_character)||UI_ARABIC_FORM_B_RANGE(current_character)) //check for current character in Arabic
        {
			is_arabic_char_present = 1;
            if (UI_ARABIC_CHARACTER_RANGE(preChar)||UI_ARABIC_FORM_B_RANGE(preChar)) //check for previous character in arabic
            {
                if (UI_ARABIC_CHARACTER_RANGE(postChar)||UI_ARABIC_FORM_B_RANGE(postChar)) //check for next character
                {//Middle Form
                    if (WHETHER_JOIN_CHARACTER(preChar)) //check if previous character has joining form
                    {
                        preChar = current_character;
                        if (UI_ARABIC_FORM_B_RANGE(current_character))
                        {
                            current_character = glyph_form[UNICODE_ARABIC_FORM_B(current_character)].middleForm;
                            if (current_character == NULL)
                            {
                                current_character = preChar;
                            }
                        }
                        else if (UI_ARABIC_FORM_A_RANGE(current_character))
                        {
                            current_character = glyph_form[UNICODE_ARABIC_FORM_A(current_character)].middleForm;
                            if (current_character == NULL)
                            {
                                current_character = preChar;
                            }
                        }
                        else
                        {
                            current_character = glyph_form[UNICODE_ARABIC(current_character)].middleForm;
                        }
                    }
                    else //check for previous character not having joining form
                    {
                        preChar = current_character;
                        if (UI_ARABIC_FORM_B_RANGE(current_character))
                        {
                            current_character = glyph_form[UNICODE_ARABIC_FORM_B(current_character)].preForm;
                            if (current_character == NULL)
                            {
                                current_character = preChar;
                            }
                        }
                        else if (UI_ARABIC_FORM_A_RANGE(current_character))
                        {
                            current_character = glyph_form[UNICODE_ARABIC_FORM_A(current_character)].preForm;
                            if (current_character == NULL)
                            {
                                current_character = preChar;
                            }
                        }
                        else
                        {
                            current_character = glyph_form[UNICODE_ARABIC(current_character)].preForm;
                        }
                    }
                }
                else //if previous character is Arabic but next character is not Arabic or null
                {//Post Form
                    if (WHETHER_JOIN_CHARACTER(preChar))
                    {
                        preChar = current_character;
                        if (UI_ARABIC_FORM_B_RANGE(current_character))
                        {
                            current_character = glyph_form[UNICODE_ARABIC_FORM_B(current_character)].postForm;
                            if (current_character == NULL)
                            {
                                current_character = preChar;
                            }
                        }
                        else if (UI_ARABIC_FORM_A_RANGE(current_character))
                        {
                            current_character = glyph_form[UNICODE_ARABIC_FORM_A(current_character)].postForm;
                            if (current_character == NULL)
                            {
                                current_character = preChar;
                            }
                        }
                        else
                        {
                            current_character = glyph_form[UNICODE_ARABIC(current_character)].postForm;
                        }
                    }
                    else
                    {//check for previous character not having joining form
                        preChar = current_character;
                        if (UI_ARABIC_FORM_B_RANGE(current_character))
                        {
                            current_character = glyph_form[UNICODE_ARABIC_FORM_B(current_character)].nominalForm;
                            if (current_character == NULL)
                            {
                                current_character = preChar;
                            }
                        }
                        else if (UI_ARABIC_FORM_A_RANGE(current_character))
                        {
                            current_character = glyph_form[UNICODE_ARABIC_FORM_A(current_character)].nominalForm;
                            if (current_character == NULL)
                            {
                                current_character = preChar;
                            }
                        }
                        else
                        {
                            current_character = glyph_form[UNICODE_ARABIC(current_character)].nominalForm;
                        }
                    }
                }
            }
            else if (UI_ARABIC_CHARACTER_RANGE(postChar)||UI_ARABIC_FORM_B_RANGE(postChar)) //if previous character is null then check for next char in arabic
            {//Pre Form
                preChar = current_character;
                if (UI_ARABIC_FORM_B_RANGE(current_character))
                {
                    current_character = glyph_form[UNICODE_ARABIC_FORM_B(current_character)].preForm;
                    if (current_character == NULL)
                    {
                        current_character = preChar;
                    }
                }
                else if (UI_ARABIC_FORM_A_RANGE(current_character))
                {
                    current_character = glyph_form[UNICODE_ARABIC_FORM_A(current_character)].preForm;
                    if (current_character == NULL)
                    {
                        current_character = preChar;
                    }
                }
                else
                {
                    current_character = glyph_form[UNICODE_ARABIC(current_character)].preForm;
                }
            }
            else //if previous and next characters are not in arabic
            {
                preChar = current_character;
                if (UI_ARABIC_FORM_B_RANGE(current_character))
                {
                    current_character = glyph_form[UNICODE_ARABIC_FORM_B(current_character)].nominalForm;
                    if (current_character == NULL)
                    {
                        current_character = preChar;
                    }
                }
                else if (UI_ARABIC_FORM_A_RANGE(current_character))
                {
                    current_character = glyph_form[UNICODE_ARABIC_FORM_A(current_character)].nominalForm;
                    if (current_character == NULL)
                    {
                        current_character = preChar;
                    }
                }
                else
                {
                    current_character = glyph_form[UNICODE_ARABIC(current_character)].nominalForm;
                }
            }
            if ((current_character == 0x644))
            {
                current_character = 0xFEDD;
            }
            else if ((current_character == 0x647))
            {
                current_character = 0xFEE9;
            }
            text_buffer[count] = current_character;
            
        }
        else //if current character is not in arabic
        {
            preChar = 0;
            postChar = 0;
        }

        count = count + 1;
        temp_length = temp_length - 1;
    }
	if(is_arabic_char_present) //if arabic character present in text_buffer then calls rules API
	{
		arabic_ligature_rules(text_buffer, length, pOrgToSha, pShaToOrg);
	}

}

/*****************************************************************************
 * FUNCTION
 *  arabic_ligature_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_buffer [IN]        
 *  length      [IN]        
 *  pOrgToSha   [IN]        
 *  pShaToOrg   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void arabic_ligature_rules(PU16 text_buffer, PU16 length, PU16 pOrgToSha, PU16 pShaToOrg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    ARABIC_MAIN_TABLE ind_table;
    const LIGATURE_INFO_TABLE *char_table;
	U16 input_buffer[ARABIC_LIGATURE_LENGTH];
	U16 current_character;
	U16 ch_index;	
    S32 size;    
    S32 max_size;    
	U16 count = 0;
	U16 read_count = 0;	
    U8 is_req_orginal_to_shape_position = 0;
    U8 is_req_shape_to_original_position = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (pOrgToSha != NULL)
    {
        is_req_orginal_to_shape_position = 1;
    }

    if (pShaToOrg != NULL)
    {
        is_req_shape_to_original_position = 1;
    }

	while(read_count < *length)
	{
		current_character = text_buffer[read_count];

        if (is_req_orginal_to_shape_position)
        {
            pOrgToSha[read_count] = count;
        }

        text_buffer[count] = current_character;
        if (is_req_shape_to_original_position)
        {
            pShaToOrg[count] = read_count;
        }

        if (UI_ARABIC_FORM_B_RANGE(current_character) || UI_ARABIC_FORM_A_RANGE(current_character))
        {
            if (UI_ARABIC_FORM_A_RANGE(current_character))
            {
                ch_index = UNICODE_ARABIC_FORM_A(current_character);    /* find the index of character in main table */
                ind_table = Arabic_Tbl_A[ch_index]; /* gets the individual charactr's table in main table */
            }
            else
            {
                ch_index = UNICODE_ARABIC_FORM_B(current_character);    /* find the index of character in main table */
                ind_table = Arabic_Tbl_B[ch_index]; /* gets the individual charactr's table in main table */
            }
            char_table = ind_table.glyphinfo;   /* holds the add. of individual character */
            size = ind_table.nsize;
            max_size = ind_table.maxInputGlyphSize;
            if (char_table != NULL)
            {
                S32 i;

                for (i = 0; i < max_size; i++)
                {
                    input_buffer[i] = text_buffer[read_count + i];
                }
                while (size)
                {
                    size--;
                    if (memcmp(char_table[size].Input_glyph, input_buffer, char_table[size].nInputLen * 2) == 0)
                    {
                        memcpy(input_buffer, char_table[size].Output_glyph, char_table[size].nOutputLen * 2);
                        input_buffer[char_table[size].nOutputLen] = (U16) NULL;
                        if (is_req_orginal_to_shape_position)
                        {
                            for(i=read_count;i<read_count+char_table[size].nInputLen;i++)
                            {
                                pOrgToSha[i] = count;
                            }
                        }                
						read_count += char_table[size].nInputLen-1;
						break;
					}
				}
				for(i=0;i<char_table[size].nOutputLen;i++)
				{
					text_buffer[count+i] = input_buffer[i];
				}
                if (is_req_shape_to_original_position)
                {
                    for(i=0;i<char_table[size].nOutputLen-1;i++)
				    {
                        pShaToOrg[count+i+1]=read_count;
                    }
                }
                count+=char_table[size].nOutputLen-1;
			}
			else
			{
				text_buffer[count] = current_character;                
			}
		}
		else
		{
			text_buffer[count] = current_character;
        }

		count++;
		read_count++;
	}
	*length = (U16)count;
	for(;count<read_count;count++)
	{
		text_buffer[count] = (U16) NULL;
	}

}


/*****************************************************************************
 * FUNCTION
 *  ArabicShapeEngine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [IN]        
 *  text_buffer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ArabicShapeEngine_ext(PU16 nLen, PU16 buffer)
{
#if (defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__))&& !defined(__MMI_LANG_URDU__)
    #ifdef __MMI_ZI_V7__
        #if defined(__MMI_ZI_PERSIAN__) && defined(__MMI_ZI_ARABIC__)
            ZiStringShape(ZI8_LANG_FA, nLen, buffer);
        #elif defined (__MMI_ZI_PERSIAN__)
            ZiStringShape(ZI8_LANG_FA, nLen, buffer);
        #elif defined (__MMI_ZI_ARABIC__)
            ZiStringShape(ZI8_LANG_AR, nLen, buffer);
        #endif 
    #else /* __MMI_ZI_V7__ */ 
        ArabicStringShape(nLen, buffer);
    #endif /* __MMI_ZI_V7__ */ 
#else /* defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__) */ 

#if 0
//Huyanwei Modify It    
    ArabicShapeEngine(
        ARABIC_LIGATURE_NONE
        #if defined(__MMI_LANG_ARABIC__)
        | ARABIC_LIGATURE_ARABIC
        #endif
        #if defined(__MMI_LANG_PERSIAN__)
        | ARABIC_LIGATURE_PERSIAN
        #endif
        #if defined(__MMI_LANG_URDU__)
        | ARABIC_LIGATURE_URDU
        #endif
        ,
        nLen, 
        buffer);    /* output will replace the input string after returning */
#else
	ArabicShapeEngine(
        nLen, 
        buffer);    /* output will replace the input string after returning */
#endif

#endif /* defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  ArabicShapeEngine2_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [IN]        
 *  text_buffer     [IN]        
 *  pOrgToSha       [IN]        
 *  pShaToOrg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ArabicShapeEngine2_ext(PU16 length, PU16 text_buffer, PU16 pOrgToSha, PU16 pShaToOrg)
{
 #if (defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__)) && !defined(__MMI_LANG_URDU__)
    #ifdef __MMI_ZI_V7__
        #if defined(__MMI_ZI_ARABIC__) && defined(__MMI_ZI_PERSIAN__)
            ZiStringShapeEx(ZI8_LANG_FA, length, text_buffer, pOrgToSha, pShaToOrg);      /* 19 is the Arabic id */
        #elif defined(__MMI_ZI_PERSIAN__)
            ZiStringShapeEx(ZI8_LANG_FA, length, text_buffer, pOrgToSha, pShaToOrg);      /* 19 is the Arabic id */
        #elif defined(__MMI_ZI_ARABIC__)
            ZiStringShapeEx(ZI8_LANG_AR, length, text_buffer, pOrgToSha, pShaToOrg);      /* 19 is the Arabic id */
        #endif 
    #else /* __MMI_ZI_V7__ */ 
        ArabicStringShape2(length, text_buffer, pOrgToSha, pShaToOrg);
    #endif /* __MMI_ZI_V7__ */ 
#else /* (__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__) */ 

#if 0
//Huyanwei Add It    

    ArabicShapeEngine2(
        ARABIC_LIGATURE_NONE
        #if defined(__MMI_LANG_ARABIC__)
        | ARABIC_LIGATURE_ARABIC
        #endif
        #if defined(__MMI_LANG_PERSIAN__)
        | ARABIC_LIGATURE_PERSIAN
        #endif
        #if defined(__MMI_LANG_URDU__)
        | ARABIC_LIGATURE_URDU
        #endif
        ,length, 
        text_buffer, 
        pOrgToSha, 
        pShaToOrg);
#else
    ArabicShapeEngine2(
        length, 
        text_buffer, 
        pOrgToSha, 
        pShaToOrg);
#endif

#endif /* (__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__) */ 


}
#endif /* __MMI_ARSHAPING_ENGINE__ */ 
/* PMT END PERSIAN */

