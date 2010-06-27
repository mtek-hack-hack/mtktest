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
 * mmi_msg_context.h
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_MSG_CONTEXT_H
#define _MMI_MSG_CONTEXT_H

/* if some header should be include before this one */
#ifndef _CUSTOMER_PS_INC_H
#error "customer_ps_inc.h should be included before mmi_msg_context.h"
#endif 

#ifdef __UNIFIED_MSG_SUPPORT__
 /* Number of UCS2 characters of SMS content that would be stored in MMI SMS context. */
#define MMI_SMS_MAX_MMI_STORED_CONTENT_SIZE 20
#endif /* __UNIFIED_MSG_SUPPORT__ */

#ifdef __GEMINI__
#define MMI_SMS_MAX_MSG_NUM	 (CM_SMS_MAX_MSG_NUM * 2)
#else
#define MMI_SMS_MAX_MSG_NUM	 CM_SMS_MAX_MSG_NUM
#endif

#ifdef SMS_FOR_NEPTUNE
typedef struct
{
    unsigned short ref;
    unsigned char totalseg;
    unsigned char startseg;
} msg_concat_info_struct;

typedef struct
{
    unsigned char status;
    unsigned char type;
    unsigned char timer;
    unsigned char mti;
    unsigned char number[20];
    unsigned char timestamp[6];
    unsigned short index[MMI_SMS_MAX_MSG_SEG];
    msg_concat_info_struct concatinfo;
} msg_msgbox_entry_struct;

typedef struct
{
    unsigned short totalinbox;
    unsigned short totaloutbox;
    unsigned short totaldraftbox;
    unsigned short totalawaited;
    msg_msgbox_entry_struct msgentry[MMI_SMS_MAX_MSG_NUM];
} msg_msgbox_info_struct;
#endif /* SMS_FOR_NEPTUNE */ 

typedef struct
{
    unsigned char totalSegments;
    unsigned char presentSegments;  /* use for send waiting response */
    unsigned char nextSegment;      /* use for save one by one */
    unsigned char dcs[MMI_SMS_MAX_MSG_SEG];
    unsigned char ori_dcs[MMI_SMS_MAX_MSG_SEG];
    unsigned char udhi;
    unsigned char mti;
    unsigned char st;

    /* Params for Sending only */
    char *phNumber;
    unsigned char number[(20 + 2) *2];
    unsigned char status;
    unsigned char timestamp[6];

    /* prepare for new interface, 0416 */
    unsigned short msgboxindex;

    /* Take a contiguous buffer so that we can re-use! */
    unsigned char TPUD[MMI_SMS_MAX_MSG_SEG *160];
    unsigned char *TPUD_p[MMI_SMS_MAX_MSG_SEG];
    unsigned char TPUDLen[MMI_SMS_MAX_MSG_SEG];

    /* MTK Joy added for error SIM handler, 10/07 */
    unsigned char TPUD_udhi[MMI_SMS_MAX_MSG_SEG];
    unsigned short l4index[MMI_SMS_MAX_MSG_SEG];

} PendingSaveSendDataStruct;

#ifdef SMS_FOR_NEPTUNE
extern msg_msgbox_info_struct msgbox_info;
extern msg_msgbox_entry_struct msgbox_newmsg;
#else /* SMS_FOR_NEPTUNE */ 
typedef struct
{
    /* mti and status */
    unsigned short msgtype;
    unsigned char storageType;

    unsigned char startseg;
    unsigned char totalseg;

    unsigned char timestamp[7];
    unsigned char number[21];

    unsigned short ref;
    unsigned short startindex;
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    unsigned char send_status;
#endif

#ifdef __UNIFIED_MSG_SUPPORT__
    unsigned short content[MMI_SMS_MAX_MMI_STORED_CONTENT_SIZE];
#endif 

} mmi_frm_sms_msgbox_struct;

typedef struct
{
    unsigned char segment;
    unsigned short prevtype;

    /* next non-empty segment, 0xffff for last segment */
    unsigned short nextindex;
    unsigned short previndex;
} mmi_frm_sms_index_struct;

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
typedef struct
{
    //unsigned char filename[6]; //001.a,...009.a, 00A.a, 00B.a...00F.a, 010.a, ....  //depends on define //here max: FFF.a, (include"\0")
    unsigned short filesize;
    unsigned char timestamp[7];
    unsigned char number[21];

    unsigned short objectnum; //to record how many objects in this message
    unsigned short textLength; //for addstring ask use u16 or kal_uint16 

#ifdef __UNIFIED_MSG_SUPPORT__
    unsigned short content[MMI_SMS_MAX_MMI_STORED_CONTENT_SIZE];
#endif
//moved from which box (will be MMI_FRM_SMS_OUTBOX, or MMI_FRM_SMS_INBOX or MMI_FRM_SMS_UNREAD)  //should be mmi_frm_sms_msgbox_enum, 
    unsigned short fromboxtype; 
    unsigned char dcs;
    unsigned char isComplete;
    unsigned char reserved[3];	
    unsigned char guardPattern[4]; //patten: F2F2F2F2  
}mmi_frm_sms_archiveIndex_struct; //plz keep this sturcture size to be multiple of 4 

extern unsigned short mmi_frm_sms_archive_list[CM_SMS_MAX_ARMSG_NUM]; 
extern mmi_frm_sms_archiveIndex_struct mmi_frm_sms_archiveIndex_list[CM_SMS_MAX_ARMSG_NUM];  
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

extern unsigned short mmi_frm_sms_inbox_list[MMI_SMS_MAX_MSG_NUM];
extern unsigned short mmi_frm_sms_outbox_list[MMI_SMS_MAX_MSG_NUM];
extern unsigned short mmi_frm_sms_drafts_list[MMI_SMS_MAX_MSG_NUM];
#ifdef __UNIFIED_MSG_SUPPORT__
extern unsigned short mmi_frm_sms_unsent_list[MMI_SMS_MAX_MSG_NUM];
#endif

extern mmi_frm_sms_msgbox_struct mmi_frm_sms_msg_box[MMI_SMS_MAX_MSG_NUM];
extern mmi_frm_sms_index_struct mmi_frm_sms_index_list[MMI_SMS_MAX_MSG_NUM];
#endif /* SMS_FOR_NEPTUNE */ 
extern PendingSaveSendDataStruct PendingSaveSendData;
extern unsigned char mmi_msg_get_seg_num(void);
extern unsigned short mmi_msg_get_msgbox_size(void);

#ifdef SMS_FOR_NEPTUNE
extern unsigned char mmi_msg_get_msgbox_entry_size(void);
#endif 

#ifdef __UNIFIED_MSG_SUPPORT__
extern unsigned char mmi_msg_get_max_content_size(void);
#endif 

#endif /* _MMI_MSG_CONTEXT_H */ 

