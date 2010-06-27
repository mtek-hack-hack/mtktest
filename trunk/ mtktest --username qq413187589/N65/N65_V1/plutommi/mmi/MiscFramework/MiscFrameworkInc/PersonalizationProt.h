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
 * PersonalizationProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Global functions declarations for personalization module
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

   FILENAME : PersonalizationProt.h

   PURPOSE     : Global functions declarations for Sim 
               Detction module.

   REMARKS     : nil

   AUTHOR      : Deepali

   DATE     : 12/03/03

**************************************************************/

#ifndef _PERSONALIZATION_PROT_H
#define _PERSONALIZATION_PROT_H

#include "MMIDataType.h"

extern void EntryScrEnterNP(void);
extern void EntryScrEnterNSP(void);
extern void EntryScrEnterSIMP(void);
extern void EntryScrEnterCP(void);
extern void EntryScrEnterSP(void);

/* void PopulatePersonalizationRes(void); */

extern void EntryScrIncorrectSIMP(void);
extern void EntryScrIncorrectNP(void);
extern void EntryScrIncorrectSP(void);
extern void EntryScrIncorrectCP(void);
extern void EntryScrIncorrectNSP(void);

/* void PopulatePersonalizationRes(void); */

extern void ValidateNP(void);
extern void ValidateNSP(void);
extern void ValidateSIMP(void);
extern void ValidateCP(void);
extern void ValidateSP(void);

/* SML menu implementation */
#ifdef __MMI_SML_MENU__
extern void EntryScrEnterNSSP(void);
extern void EntryScrEnterSIMC(void);
extern void EntryScrIncorrectNSSP(void);
extern void EntryScrIncorrectSIMC(void);

extern void mmi_sml_init(void);
extern void mmi_sml_power_on_query_req(void);

extern void mmi_sml_entry_lock_category_selection(void);
extern void mmi_sml_entry_unlock_category_selection(void);
extern void mmi_sml_entry_add_category_data(void);
extern void mmi_sml_entry_remove_category_data(void);
extern void mmi_sml_entry_permanent_unlock_selection(void);

extern void mmi_sml_send_lock_req_by_ssc(void);
extern void mmi_sml_send_unlock_req_by_ssc(void);
extern void mmi_sml_send_query_req_by_ssc(void);

extern void mmi_sml_display_auto_locked_notification (void);
extern void mmi_sml_popup_error_msg(U8 retry_count);

#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
extern S32 mmi_sml_count_retry_interval(U8 retry_count, U8 max_count);
extern void mmi_sml_entry_please_wait_next_attempt(void);
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */

#ifdef __MMI_SML_UNLOCK_AFTER_VERIFIED__
extern void mmi_sml_unlock_after_verified_paswd(void);
#ifdef __MMI_SML_NP_ONLY__
extern void mmi_bootup_sim_entry_pending_np_screen(void);
extern void mmi_bootup_sim_entry_check_np_screen(void);
extern void mmi_bootup_sim_verify_success(void);
#endif /* __MMI_SML_NP_ONLY__ */
#endif /* __MMI_SML_UNLOCK_AFTER_VERIFIED__ */

#endif /* __MMI_SML_MENU__ */

#endif /* _PERSONALIZATION_GPROT_H */


