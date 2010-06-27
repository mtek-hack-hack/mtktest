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
 * PersonalizationResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for defines of Personalization module
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _PERSONALIZATIONRES_DEF_H
#define _PERSONALIZATIONRES_DEF_H

#include "MMI_features.h"
#include "MMIDataType.h"

enum STR_PERSONALIZATION_LIST
{
    STR_ENTER_NP_MSG = SIM_DETECTION_BASE + 200,
    STR_ENTER_NSP_MSG,
    STR_ENTER_CP_MSG,
    STR_ENTER_SP_MSG,
    STR_ENTER_SIMP_MSG,
    STR_WRONG_SP_MSG,
    STR_WRONG_CP_MSG,
    STR_WRONG_NSP_MSG,
    STR_WRONG_NP_MSG,
    STR_WRONG_SIMP_MSG,
/* SML menu implementation */
#ifdef __MMI_SML_MENU__
    STR_ENTER_NSSP_MSG,
    STR_ENTER_SIMC_MSG,
    STR_WRONG_NSSP_MSG,
    STR_WRONG_SIMC_MSG,

    STR_ID_CATEGORY_NP_LOCK,
    STR_ID_CATEGORY_NSP_LOCK,
    STR_ID_CATEGORY_CP_LOCK,
    STR_ID_CATEGORY_SP_LOCK,
    STR_ID_CATEGORY_SIMP_LOCK,
    STR_ID_CATEGORY_NSP_SP_LOCK,
    STR_ID_CATEGORY_SIMP_CP_LOCK,

    STR_ID_SML_LOCK_MENU,
    STR_ID_SML_UNLOCK_MENU,
    STR_ID_SML_ADD_MENU,
    STR_ID_SML_REMOVE_MENU,
    STR_ID_SML_DEACTIVATE_MENU,

    STR_ID_SML_REBOOT_MSG,
    STR_ID_SML_QUREY_MSG,
    STR_ID_SML_BLOCK_MSG,
    STR_ID_SML_NO_EF_GID,
    STR_ID_SML_INVALID_DATA,
    STR_ID_SML_AUTOKEY_CONFIRM,
    STR_ID_LAST_RETRY_MSG,
    STR_ID_GENERAL_RETRY_MSG,
    STR_ID_UNLOCK_FIRST_MSG,
    STR_ID_EMPTY_CATEGORY_MSG,
    STR_ID_NO_RECORD_MSG,
    STR_ID_NO_DATA_MSG,

    STR_ID_SML_CAT_LOCKED,
    STR_ID_SML_CAT_UNLOCKED,
    STR_ID_SML_CAT_AUTOLOCKED,

    STR_ID_SML_AUTOLOCKED,
    STR_ID_SML_FAIL_TO_AUTOLOCK,

    STR_ID_SML_NP_DATA,
    STR_ID_SML_NSP_DATA,
    STR_ID_SML_SP_DATA,
    STR_ID_SML_CP_DATA,
    STR_ID_SML_SIMP_DATA,
#endif /* __MMI_SML_MENU__ */
    STR_PERS_RSK_SOS
};

enum SCR_PERSONALIZATION_LIST
{
    SCR_ENTER_NP = SIM_DETECTION_BASE + 200,
    SCR_ENTER_NSP,
    SCR_ENTER_CP,
    SCR_ENTER_SP,
    SCR_ENTER_SIMP,

/* SML menu implementation */
    SCR_ENTER_NS_SP,
    SCR_ENTER_SIM_C,
    /* screens for menu */
    SCR_ID_SML_LOCK_MENU,
    SCR_ID_SML_UNLOCK_MENU,
    SCR_ID_SML_ADD_MENU,
    SCR_ID_SML_REMOVE_MENU,
    SCR_ID_SML_DEACTIVATE_MENU,
    /* screens for add data */
    SCR_ID_SML_QUERY_POPUP,
    SCR_ID_SML_FILL_DATA,
    SCR_ID_SML_AUTOKEY_CONFIRM,
    /* screens for confirmation */
    SCR_ID_SML_REMOVE_CONFIRM,
    SCR_ID_SML_DEACTIVATE_CONFIRM,
    /* screens for input key */
    SCR_ID_SML_INPUT_KEY,
    SCR_ID_SML_CONFIRM_KEY,
    /* screens for please wait next attempt */
    SCR_ID_SML_WAIT_ATTEMPT,

    SCR_ID_PERSONALIZATION_DUMMY
};

#endif /* _PERSONALIZATIONRES_DEF_H */

