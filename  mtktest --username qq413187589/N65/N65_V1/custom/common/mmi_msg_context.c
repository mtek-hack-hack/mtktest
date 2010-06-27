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
 * mmi_msg_context.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI message application context.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_MSG_CONTEXT_C
#define _MMI_MSG_CONTEXT_C

#include "customer_ps_inc.h"
#include "mmi_msg_context.h"

#ifdef SMS_FOR_NEPTUNE
msg_msgbox_info_struct msgbox_info;
msg_msgbox_entry_struct msgbox_newmsg;
#else /* SMS_FOR_NEPTUNE */ 
unsigned short mmi_frm_sms_inbox_list[MMI_SMS_MAX_MSG_NUM];
unsigned short mmi_frm_sms_outbox_list[MMI_SMS_MAX_MSG_NUM];
unsigned short mmi_frm_sms_drafts_list[MMI_SMS_MAX_MSG_NUM];
#ifdef __UNIFIED_MSG_SUPPORT__
unsigned short mmi_frm_sms_unsent_list[MMI_SMS_MAX_MSG_NUM];
#endif

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#error "Huyanwei Test Macro"
unsigned short mmi_frm_sms_archive_list[CM_SMS_MAX_ARMSG_NUM]; 
mmi_frm_sms_archiveIndex_struct mmi_frm_sms_archiveIndex_list[CM_SMS_MAX_ARMSG_NUM];  
#endif
mmi_frm_sms_msgbox_struct mmi_frm_sms_msg_box[MMI_SMS_MAX_MSG_NUM];
mmi_frm_sms_index_struct mmi_frm_sms_index_list[MMI_SMS_MAX_MSG_NUM];
#endif /* SMS_FOR_NEPTUNE */ 
PendingSaveSendDataStruct PendingSaveSendData;


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_seg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned char mmi_msg_get_seg_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_SMS_MAX_MSG_SEG;
}

#ifdef SMS_FOR_NEPTUNE


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msgbox_entry_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned char mmi_msg_get_msgbox_entry_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(msg_msgbox_entry_struct);
}
#endif /* SMS_FOR_NEPTUNE */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msgbox_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned short mmi_msg_get_msgbox_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_SMS_MAX_MSG_NUM;
}

#ifdef __UNIFIED_MSG_SUPPORT__
/* Get the number of UCS2 characters of SMS content that would be stored in MMI SMS context. */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_max_content_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned char mmi_msg_get_max_content_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_SMS_MAX_MMI_STORED_CONTENT_SIZE;
}
#endif /* __UNIFIED_MSG_SUPPORT__ */ 

#endif /* _MMI_MSG_CONTEXT_C */ 

