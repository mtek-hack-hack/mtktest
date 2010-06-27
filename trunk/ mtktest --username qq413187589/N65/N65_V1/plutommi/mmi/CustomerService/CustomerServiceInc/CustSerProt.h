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
 *   CustSerProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   customer service  header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_CUSTOMER_SERVICE_PROT_H_
#define _MMI_CUSTOMER_SERVICE_PROT_H_

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_CUSTOMER_SERVICE__

#include "MMIDataType.h"
#include "common_nvram_editor_data_item.h"

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    MMI_CUSTSER_MYMONWAP_MONWAP = 0,
    MMI_CUSTSER_MYMONWAP_SMS,
    MMI_CUSTSER_MYMONWAP_MMS,
    MMI_CUSTSER_MYMONWAP_TOTAL
} mmi_custser_mymonternet_hilite_enum;

typedef struct
{
    U16 title_icon_id;
    U16 title_str_id;
    U16 content_str_id;

} mmi_custser_textview_data_struct;

typedef struct
{
    U8 selected_hilight_idx;
    HILITE_STR hilite_item[MMI_CUSTSER_MYMONWAP_TOTAL];

} mmi_custser_mymonternet_struct;

typedef struct
{
    MMI_BOOL isModified;
    U8 option_index;
    U8 name_text_editor_buffer[(1 + MAX_PB_NAME_LENGTH) *ENCODING_LENGTH];
} mmi_custser_name_edit_struct;

typedef struct
{
    mmi_custser_textview_data_struct textview_data;
    mmi_custser_mymonternet_struct mymonternet_data;
    nvram_custser_setting_struct setting_data;
    mmi_custser_name_edit_struct name_edit_data;
    PU8 pCurrHiliteNumber;

} mmi_custser_context_struct;

typedef enum
{
    MMI_CUSTSER_HILITE_HOTLINE = MENU_ID_CUSTSER_HOTLINE - MENU_ID_CUSTSER_GUIDELINE,
    MMI_CUSTSER_HILITE_MANAGER = MENU_ID_CUSTSER_MANAGER - MENU_ID_CUSTSER_GUIDELINE
} mmi_custser_hilite_call_enum;

extern mmi_custser_context_struct g_custser_context;

#endif /* __MMI_CUSTOMER_SERVICE__ */ 

#endif /* _MMI_CUSTOMER_SERVICE_PROT_H_ */ 

