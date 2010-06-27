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

/*******************************************************************************
 * Filename:
 * ---------
 * ShortcutsResDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines resource id used in Shortcuts application.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMI_SHORTCUTS_RESDEF_H
#define _MMI_SHORTCUTS_RESDEF_H

#include "MMI_features.h"
#ifndef __DISABLE_SHORTCUTS_IMPL__

#include "MMIDataType.h" 

/* Screen Ids */
typedef enum
{
    SCR_ID_SHCT_IDLE_SHORTCUT = SHORTCUTS_BASE + 1,
    SCR_ID_SHCT_MAIN_MENU,
    SCR_ID_SHCT_EDIT,
    SCR_ID_SHCT_OPTION,
    SCR_ID_SHCT_ORDER,
    SCR_ID_SHCT_DEDICATED_KEYS,
    SCR_ID_SHCT_EDIT_DEDICATED_KEYS,
    SCR_ID_SHTC_TOTAL
} SCR_ID_SHCT_ENUM;

/* String Ids */
typedef enum
{
    //SHORTCUTS_OPTIONS_EDIT_STRING_ID = SHORTCUTS_BASE + 1,
    SHORTCUTS_TITLE_STRING_ID = SHORTCUTS_BASE + 1,
    SHORTCUTS_HINT_STRING_ID,
    SHORTCUTS_ADD_STRING_ID,
    SHORTCUTS_EDIT_STRING_ID,
    SHORTCUTS_DELETE_ASK_STRING_ID,
    SHORTCUTS_DELETE_ALL_ASK_STRING_ID,
    SHORTCUTS_ENABLE_STRING_ID,
    SHORTCUTS_DISABLE_STRING_ID,
    SHORTCUTS_FULL_MSG_STRING_ID,
    SHORTCUTS_CHANGE_ORDER_STRING_ID,
    SHORTCUTS_NO_SIM_WARNING_ID,
    SHORTCUTS_INVALID_SIM_WARNING_ID,  
    SHORTCUTS_INVALID_NO_IDLE_WARNING_ID,  
#ifdef __MMI_DUAL_SIM_MASTER__    
    SHORTCUTS_NO_SIM1_WARNING_ID,
    SHORTCUTS_INVALID_SIM1_WARNING_ID,    
    SHORTCUTS_NO_SIM2_WARNING_ID,
    SHORTCUTS_INVALID_SIM2_WARNING_ID,
    SHORTCUTS_SIM1_CLOSED_WARNING_ID,
    SHORTCUTS_SIM2_CLOSED_WARNING_ID
#endif    
} STR_ID_SHCT_ENUM;

/* Image Ids */
typedef enum
{
    SHORTCUTS_OPTIONS_EDIT_IMAGE_ID = SHORTCUTS_BASE + 1,
    SHORTCUTS_TITLE_IMAGE_ID
} IMG_ID_SHCT_ENUM;
#endif /* __DISABLE_SHORTCUTS_IMPL__ */
#endif /*_MMI_SHORTCUTS_RESDEF_H*/
