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
 *    t9def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   string id, image id, and screen id definition
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __T9DEF_H__
#define __T9DEF_H__

#include "MMIDataType.h"

/* screen ids */
typedef enum
{
    SCR_INPUT_METHOD = INPUT_METHOD_BASE + 1
} SCREENID_LIST_T9_INPUT_METHOD;

/* string ids */
typedef enum
{
    STR_T9_EXP_UP_ABC = INPUT_METHOD_BASE + 1,
    STR_T9_EXP_LO_abc,
    STR_T9_AMB_UP_ABC,
    STR_T9_AMB_LO_abc,
    STR_T9_BOPOMOFO,
    STR_T9_TR_STROKE,
    STR_T9_PINYIN,
    STR_T9_SM_STROKE,

    //STR_T9_CLEAR, ==>replaced by Global String
    //STR_T9_BACK,==>replaced by Global String
    //STR_T9_SELECT,==>replaced by Global String
    STR_T9_123,
    STR_INPUT_METHOD_THAI,
    /* MTK Elvis for R2L characters */
    STR_INPUT_METHOD_ARABIC,
//PMT START PERSIAN
    STR_INPUT_METHOD_PERSIAN,
//PMT END PERSIAN
    /* PMT START GR_HE_CZ_FI_DA_HU 20051007 */
    STR_INPUT_METHOD_HEBREW,
    //PMT END GR_HE_CZ_FI_DA_HU 20051007
    //MTK end
    STR_INPUT_METHOD_REACH_MAX_LEN
} STRINGID_LIST_T9_INPUT_METHOD;

/* image ids */
typedef enum
{
    IMG_T9 = INPUT_METHOD_BASE + 1
} IMAGEID_LIST_T9_INPUT_METHOD;

#endif /* __T9DEF_H__ */ 

