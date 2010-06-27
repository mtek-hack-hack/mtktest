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
 *  JMMSUseDetails.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_use_details_ui.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSUSEDETAILSSECMMI_H
#define __MMI_JMMSUSEDETAILSSECMMI_H

#include "MMI_features.h"
#include "MMIDataType.h"
// #include "MessagingDataTypes.h"

/* 
 * Define
 */

/* 
 * Typedef 
 */

typedef enum
{
    E_USE_NUMBER,
    E_USE_EMAIL
} use_details_enum;

typedef struct _mms_addresses_list
{
    S8 *address;
    MMI_BOOL is_email;
    struct _mms_addresses_list *next_p;
} mms_addresses_list;

typedef struct
{
    U8 hilite_address_index;
    use_details_enum number_email_flag;
    mms_addresses_list *addresses_list;
} jmms_use_details_struct;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
#ifndef __MMI_UNIFIED_MESSAGE__
extern void mmi_jmms_entry_use_details_screen(void);
extern void mmi_jmms_highlight_options_use_details_email(void);
extern void mmi_jmms_use_details_email(void);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
extern void mmi_jmms_edit_message(S8 *folder_name_p);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
extern void mmi_jmms_highlight_options_use_details_number(void);
extern void mmi_jmms_highlight_options_use_details_add_to_contact(void);
extern void mmi_jmms_highlight_options_use_details_call(void);

extern void mmi_jmms_pre_use_details_call(void);
extern void mmi_jmms_use_details_call(void);
extern void mmi_jmms_use_details_add_to_contact(void);
extern void mmi_jmms_entry_use_details_addresses_list(void);
extern void mmi_jmms_use_details_list_highlight_hdlr(S32 index);
extern void mmi_jmms_entry_use_details_addresses_options(void);
extern void mmi_jmms_use_details_number(void);

extern void mmi_jmms_pre_entry_use_details_screen(S8 *folder_name_p);

extern void mmi_jmms_create_use_details_addresses_list(
                JC_CHAR *from_p,
                JC_CHAR *to_p,
                JC_CHAR *cc_p,
                JC_CHAR *bcc_p);
extern void mmi_jmms_free_use_details_adrresses_list(void);
extern void mmi_jmms_back_from_use_details_main_screen(void);

#endif /* __MMI_JMMSUSEDETAILSSECMMI_H */ 

