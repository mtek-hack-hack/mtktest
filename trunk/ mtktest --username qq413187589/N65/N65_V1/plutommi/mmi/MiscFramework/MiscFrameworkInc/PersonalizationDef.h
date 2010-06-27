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
 * PersonalizationDef.h
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : PersonalizationDef.h

   PURPOSE     : defines of Personalization module

   REMARKS     : nil

   AUTHOR      : Deepali

   DATE     : 12/03/03

**************************************************************/

#ifndef _PERSONALIZATION_DEF_H
#define _PERSONALIZATION_DEF_H

#include "MMIDataType.h"

#include "PersonalizationResDef.h"

#ifdef __MMI_SML_MENU__
    #define MAX_GID_LEN	        3
    #define MAX_IMSI_LEN        15
    #define MAX_NP_LEN          6
    #define MAX_NSP_LEN         8
#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
    #define MIN_RETRY_INTERVAL  30
#endif
#endif /* __MMI_SML_MENU__ */

/* SML menu implementation */
#ifdef __MMI_SML_MENU__
typedef struct
{
    U8 operation_type;          /* lock (0) or unlock (1) */
    U8 selected_category;       /* from 0 to 6 */
    U8 category_state[7];
    U8 total_records[7];
    U8 used_records[7];
    U8 key_state[7];
    U8 retry_count[7];
    U8 imsi[MAX_IMSI_LEN+1];
    U8 gid1;
    U8 gid2;
    U8 gid_valid_nibble;        /* lower nibble for gid1 and upper nibble for gid2 */
    U8 autolock_nibble;         /* lower nibble for auto lock enable and upper nibble for auto lock result */
    U8 digits_of_mcc_mnc;
    U8 action_not_from_menu;
    U8 highlight_inline_item;
#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
    S32 retry_countdown;
    FuncPtr next_attempt_hdlr;
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */
    U8 input_imsi[(MAX_IMSI_LEN+1)*ENCODING_LENGTH];
    U8 input_gid1[(MAX_GID_LEN+1)*ENCODING_LENGTH];
    U8 input_gid2[(MAX_GID_LEN+1)*ENCODING_LENGTH];
#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
    U8 auto_unlock_key[7][MAX_SIM_PASSWD_LEN];
#endif
} mmi_sml_menu_struct;
#endif /* __MMI_SML_MENU__ */

#endif /* _PERSONALIZATION_DEF_H */

