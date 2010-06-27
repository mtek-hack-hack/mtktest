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
 *  SMSUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *==============================================================================
 *******************************************************************************/

#include "MMI_include.h"
#ifdef __MOD_SMSAL__


/* ... Add More MMI header */
#include "CommonScreens.h"
#include "ProtocolEvents.h"

/* ...Add MSG header */
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "CellBroadcastType.h"
#ifdef __MMI_MESSAGES_CHAT__
#include "ChatAppGprot.h"
#include "ChatAppResDef.h"
#endif /* __MMI_MESSAGES_CHAT__ */ 
/*  */
#include "customer_ps_inc.h"
#include "l4c2smsal_struct.h"
#include "smsal_l4c_enum.h"
#include "ems.h"
/*  */
#include "Gui_ems.h"
#include "wgui_ems.h"
#include "GSM7BitDefaultAlphabet.h"
/*  */
#include "PhoneBookGprot.h"
#include "CallHistoryGProts.h"
#include "IdleAppProt.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "AlarmFrameworkProt.h"
#include "PhoneBookTypes.h"
#include "SimDetectionGexdcl.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
/*  */
#include "wgui_status_icons.h"

#include "DateTimeGprot.h"

#include "SMSApi.h"
#include "SMSStruct.h"
#include "SMSFunc.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageGProt.h"
#endif 
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#include "FileManagerGProt.h"
#endif

#define smstest

#define MMI_FRM_SMS_INVALID_INDEX   0xffff
#ifndef MMI_FRM_SMS_INVALID_NUM
#define MMI_FRM_SMS_INVALID_NUM     0xff
#endif 
#ifndef MMI_FRM_SMS_MSG_LEN
#define MMI_FRM_SMS_MSG_LEN         160
#endif 
#ifndef MMI_FRM_SMS_MSG_CONTENT_NUM
#define MMI_FRM_SMS_MSG_CONTENT_NUM 20
#endif 
#ifndef MMI_FRM_SMS_ACTION_SIZE
#define MMI_FRM_SMS_ACTION_SIZE     15
#endif 
static U16 mmi_frm_sms_msgbox_size = 0;
static U16 mmi_frm_sms_inbox_size = 0;
static U16 mmi_frm_sms_outbox_size = 0;
#ifdef __MMI_UNIFIED_MESSAGE__
static U16 mmi_frm_sms_unsent_size = 0;
#endif

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#define MMI_FRM_SMS_ARCHIVE_GUARD_PATTERN "F2F2"  
static U16 mmi_frm_sms_archive_size = 0; /*how many records in archive box*/  
#endif


#ifdef __MMI_MESSAGES_DRAFT_BOX__
static U16 mmi_frm_sms_drafts_size = 0;
#endif 

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
static U16 mmi_frm_sms_simbox_size = 0;
unsigned short *mmi_frm_sms_sim_list = NULL;
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

static U8 mmi_frm_sms_list_done = FALSE;

static mmi_frm_sms_deliver_msg_struct mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE + 1];
static mmi_frm_sms_deliver_data_struct mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE + 1];
static mmi_frm_sms_content_struct mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM + 1];

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
static mmi_frm_sms_delivery_report_list_struct mmi_frm_sms_delivery_report_awaited[MMI_FRM_SMS_ACTION_SIZE];
#endif 

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
static MMI_BOOL g_mmi_frm_sms_archive_del_folder_result = MMI_TRUE;
#endif

static U8 mmi_frm_sms_awaited_counter[MMI_FRM_SMS_ACTION_SIZE];
static U8 mmi_frm_sms_awaited_counting = FALSE;
static U8 mmi_frm_sms_data_counter[MMI_FRM_SMS_ACTION_SIZE];
static U8 mmi_frm_sms_data_counting = FALSE;
static U16 mmi_frm_sms_data_checked = 0;
extern MMI_BOOL g_mmi_frm_sms_change_status;

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
static U8 mmi_frm_sms_delivery_report_awaited_next_available = 0;
#endif 

#define ONE_DIGIT(value)                  ((value) % 10)

#ifdef __MMI_MESSAGES_MOSES_FEATURE__
const U8 MMI_FRM_SMS_MOSES_PATTERN[6] = {0xa1, 0x1a, 0x5f, 0x20, 0x0a,0x00};
#endif /* __MMI_MESSAGES_MOSES_FEATURE__ */

extern U8 GetSecondSemiOctetTarget(U8 ch);
extern U8 GetFirstSemiOctetTarget(U8 ch);
extern void EMS_ConvertGSM7BitDefaultEncodingToAsciiWithoutEMSlib(EMSData *data);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern EMSData *GetEMSDataForView(EMSData **p, U8 force); 
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
static mmi_frm_sms_send_struct *g_pSendData = NULL;
static PsFuncPtrU16 g_callback;
static module_type g_mod_src;
unsigned short mmi_frm_sms_show_list_index[MMI_SMS_MAX_MSG_NUM]; /* list index to show */
#endif /* __MMI_DUAL_SIM_MASTER__ */

#define MMI_SMS_EURO_SIGN (0x20AC)
#define MMI_SMS_TEST_GSM7BIT_EXTENDED(c)     \
(     (c==MMI_SMS_EURO_SIGN)                     \
   || (c=='^')                      \
   || (c=='{')                      \
   || (c=='}')                      \
   || (c=='\\')                     \
   || (c=='[')                      \
   || (c=='~')                      \
   || (c==']')                      \
   || (c=='|')                      \
)                                   \


/*****************************************************************************
 * FUNCTION
 *  ComparePhoneNum
 * DESCRIPTION
 *  It Compares phone numbers
 * PARAMETERS
 *  src     [IN]        
 *  dst     [IN]        
 *  Source and destination phone number(?)
 * RETURNS
 *  status
 *****************************************************************************/
pBOOL ComparePhoneNum(PU8 src, PU8 dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (pBOOL)mmi_phb_compare_numbers((S8*)src, (S8*)dst);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_time_stamp
 * DESCRIPTION
 *  convert time stamp
 * PARAMETERS
 *  scts            [?]     Scts
 *  timestamp       [?]     Timestamp
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_convert_time_stamp(U8 *scts, U8 *timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* No Timestamp */
    if (scts[0] == MMI_FRM_SMS_INVALID_NUM)
    {
        memset((S8*) timestamp, 0, 7);
        return;
    }

    /* year */
    timestamp[0] = ONE_DIGIT(GetSecondSemiOctetTarget(scts[0])) * 10 + ONE_DIGIT(GetFirstSemiOctetTarget(scts[0]));
    /* month */
    timestamp[1] = ONE_DIGIT(GetSecondSemiOctetTarget(scts[1])) * 10 + ONE_DIGIT(GetFirstSemiOctetTarget(scts[1]));
    /* day */
    timestamp[2] = ONE_DIGIT(GetSecondSemiOctetTarget(scts[2])) * 10 + ONE_DIGIT(GetFirstSemiOctetTarget(scts[2]));
    /* hour */
    timestamp[3] = ONE_DIGIT(GetSecondSemiOctetTarget(scts[3])) * 10 + ONE_DIGIT(GetFirstSemiOctetTarget(scts[3]));
    /* minute */
    timestamp[4] = ONE_DIGIT(GetSecondSemiOctetTarget(scts[4])) * 10 + ONE_DIGIT(GetFirstSemiOctetTarget(scts[4]));
    /* second */
    timestamp[5] = ONE_DIGIT(GetSecondSemiOctetTarget(scts[5])) * 10 + ONE_DIGIT(GetFirstSemiOctetTarget(scts[5]));
      /**timezone, convert date/time to one variable */
    timestamp[6] = ONE_DIGIT(GetSecondSemiOctetTarget(scts[6])) * 10 + ONE_DIGIT(GetFirstSemiOctetTarget(scts[6]));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_mytime
 * DESCRIPTION
 *  convert MYTIME to scts
 * PARAMETERS
 *  scts        [?]     Scts
 *  time        [?]     
 *  b  timestamp      timestamp(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_convert_mytime(U8 *scts, MYTIME *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 year = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (time->nYear > 2000)
    {
        year = (U8)(time->nYear - 2000);
    }
    else
    {
        year = (U8)(time->nYear - 1900);
    }

    scts[0] = ((year % 10) << 4) | (year / 10);
    scts[1] = ((time->nMonth % 10) << 4) | (time->nMonth / 10);
    scts[2] = ((time->nDay % 10) << 4) | (time->nDay / 10);
    scts[3] = ((time->nHour % 10) << 4) | (time->nHour / 10);
    scts[4] = ((time->nMin % 10) << 4) | (time->nMin / 10);
    scts[5] = ((time->nSec % 10) << 4) | (time->nSec / 10);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_new_sms
 * DESCRIPTION
 *  free new sms buff
 * PARAMETERS
 *  entry       [IN]        Entry
 *  length      [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_add_new_sms(mmi_frm_sms_deliver_msg_struct *entry, U16 length, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_concat_struct *concatinfo = (mmi_frm_sms_concat_struct*) & (entry->concat_info);
    U16 index = entry->index;
    U8 segment = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((concatinfo->seg > concatinfo->total_seg) || (concatinfo->seg == 0) || (concatinfo->total_seg == 0))
    {
        concatinfo->seg = 1;
        concatinfo->total_seg = 1;
    }

    if (((concatinfo->seg) % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) == 0)
    {
        segment = (U8) g_frm_sms_cntx.mmi_frm_sms_msg_seg_size;
    }
    else
    {
        segment = (concatinfo->seg) % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size;
    }

    /* change seg info to start seg */
    concatinfo->seg =
        ((concatinfo->seg - 1) / g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) * g_frm_sms_cntx.mmi_frm_sms_msg_seg_size + 1;

    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].dcs = entry->dcs;
    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].display_type = entry->display_type;
#ifdef __MMI_MESSAGES_COPY__
    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].storageType = entry->storageType;
#endif 
    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].fo = entry->fo;
    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].index = entry->index;
    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].mti = entry->mti;
    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].pid = entry->pid;
	mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].src_port = entry->src_port;
    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].dest_port = entry->dest_port;
    memcpy(&(mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].concat_info), concatinfo, sizeof(smsal_concat_struct));

    memcpy(
        (S8*) & (mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].addr_number),
        (S8*) & (entry->addr_number),
        sizeof(l4c_number_struct));
    memcpy(
        (S8*) & (mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].sca_number),
        (S8*) & (entry->sca_number),
        sizeof(l4c_number_struct));
    memcpy((S8*) (mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].scts), (S8*) (entry->scts), 7);

    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].msg_data[0] = MMI_FRM_SMS_MSG_CONTENT_NUM;
    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].no_msg_data = entry->no_msg_data;

    /* handle message content part */
    mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].segment = segment;
    mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].msglen = length;
    if (mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data != NULL)
    {
        OslMfree(mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data);
    }
    if (length)
    {
        mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data = OslMalloc(length);
        memcpy(mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data, (S8*) data, length);
    }

    /* class 0 message */
    if (index == MMI_FRM_SMS_INVALID_INDEX)
    {
        return;
    }

    /* used index list entry, replace the old entry with the new one */
    if (mmi_frm_sms_index_list[index].segment != MMI_FRM_SMS_INVALID_NUM)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[SmsUtil.c] mmi_frm_sms_add_new_sms remove used L4 list entry %d-------*\n",
                             index);        

        /* Free awaited list entry and content list entry if the replaced msg is in awaited list */
        /* The replaced segment is the first segment of awaited msg */
        if (mmi_frm_sms_index_list[index].prevtype == MMI_FRM_SMS_AWAITS)
        {
            U16 awaited_index = (U16) mmi_frm_sms_index_list[index].previndex;

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*-------[SmsUtil.c] first segment in awaited list ------*\n");
                
            /* Only one segment in the awaited msg. Just delete the awaited msg. */
            if (mmi_frm_sms_index_list[index].nextindex == MMI_FRM_SMS_INVALID_INDEX)
            {            
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*-------[SmsUtil.c] free awaited list %d-------*\n",
                                     awaited_index);

                /* Stop the timer counter of the awaited list entry to be deleted */
                mmi_frm_sms_awaited_counter[awaited_index] = MMI_FRM_SMS_INVALID_NUM;
                mmi_frm_sms_free_awaited((U8)awaited_index);
            }

            /* More than one segment in the awaited msg. Modify awaited msg and free content list entry. */
            else
            {
                U8 content_index = mmi_frm_sms_awaited[awaited_index].msg_data[0];

                MMI_ASSERT(mmi_frm_sms_awaited[awaited_index].no_msg_data >= mmi_frm_sms_content[content_index].msglen);
            
                mmi_frm_sms_awaited[awaited_index].no_msg_data -= mmi_frm_sms_content[content_index].msglen;
                mmi_frm_sms_awaited[awaited_index].msg_data[0] = mmi_frm_sms_content[content_index].nextindex;
                
                if (mmi_frm_sms_content[content_index].data != NULL)
                {
                    OslMfree(mmi_frm_sms_content[content_index].data);
                    mmi_frm_sms_content[content_index].data = NULL;
                }
                mmi_frm_sms_content[content_index].msglen = 0;
                mmi_frm_sms_content[content_index].nextindex = MMI_FRM_SMS_INVALID_NUM;
                mmi_frm_sms_content[content_index].segment = MMI_FRM_SMS_INVALID_NUM;            

                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                     "*-------[SmsUtil.c] modify awaited list %d-------*\n",
                     awaited_index);

                mmi_frm_sms_remove_sms_entry(index);                
            }
        }
        else if (mmi_frm_sms_index_list[index].prevtype == MMI_FRM_SMS_NOBOX)
        {
            U16 L4index = mmi_frm_sms_index_list[index].previndex;

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*-------[SmsUtil.c] type of segment is NOBOX ------*\n");
            
            while (mmi_frm_sms_index_list[L4index].prevtype == MMI_FRM_SMS_NOBOX)
            {
                L4index = mmi_frm_sms_index_list[L4index].previndex;
            }

            /* The replaced segment is in the awaited list */
            if (mmi_frm_sms_index_list[L4index].prevtype == MMI_FRM_SMS_AWAITS)
            {
                U16 awaited_index = (U16) mmi_frm_sms_index_list[L4index].previndex;            
                U8 content_index = mmi_frm_sms_awaited[awaited_index].msg_data[0];
                U8 pre_content_index = MMI_FRM_SMS_INVALID_NUM;
                U8 segment = mmi_frm_sms_index_list[index].segment;
                
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*-------[SmsUtil.c] non-first segment in awaited list -------*\n");       

                while(content_index != MMI_FRM_SMS_INVALID_NUM)
                {
                    if (mmi_frm_sms_content[content_index].segment == segment)
                    {
                        break;
                    }
                    pre_content_index = content_index;
                    content_index = mmi_frm_sms_content[content_index].nextindex;
                }
                
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "[SmsUtil.c] After search for content entry, segment=%d content_index=%d pre_content_index=%d \n",
                                     segment, content_index, pre_content_index);

                if (content_index != MMI_FRM_SMS_INVALID_NUM && pre_content_index != MMI_FRM_SMS_INVALID_NUM)
                {
                    MMI_ASSERT(mmi_frm_sms_awaited[awaited_index].no_msg_data >= mmi_frm_sms_content[content_index].msglen);
                
                    mmi_frm_sms_awaited[awaited_index].no_msg_data -= mmi_frm_sms_content[content_index].msglen;
                    mmi_frm_sms_content[pre_content_index].nextindex = mmi_frm_sms_content[content_index].nextindex;
                    
                    if (mmi_frm_sms_content[content_index].data != NULL)
                    {
                        OslMfree(mmi_frm_sms_content[content_index].data);
                        mmi_frm_sms_content[content_index].data = NULL;
                    }
                    mmi_frm_sms_content[content_index].msglen = 0;
                    mmi_frm_sms_content[content_index].nextindex = MMI_FRM_SMS_INVALID_NUM;
                    mmi_frm_sms_content[content_index].segment = MMI_FRM_SMS_INVALID_NUM;            

                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*-------[SmsUtil.c] modify awaited list -------*\n");                    

                    mmi_frm_sms_remove_sms_entry(index);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                
            }
            
            /* The replaced segment is in the message box  */
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*-------[SmsUtil.c] The replaced segment is in the message box -------*\n");                    
                mmi_frm_sms_remove_sms_entry(index);
            }
        }
        
        /* The replaced segment is in the message box  */
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*-------[SmsUtil.c] The replaced segment is in the message box-------*\n");       
            mmi_frm_sms_remove_sms_entry(index);
        }
    }

    mmi_frm_sms_index_list[index].segment = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].segment;
    mmi_frm_sms_index_list[index].nextindex = MMI_FRM_SMS_INVALID_INDEX;
    mmi_frm_sms_index_list[index].previndex = MMI_FRM_SMS_ACTION_SIZE;;
    mmi_frm_sms_index_list[index].prevtype = MMI_FRM_SMS_AWAITS;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_free_new_sms
 * DESCRIPTION
 *  free new sms buff
 * PARAMETERS
 *  void
 *  entry(?)        [IN]        Entry
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_free_new_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data != NULL)
    {
        OslMfree(mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data);
        mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data = NULL;
    }
    mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].msglen = 0;
    mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].nextindex = MMI_FRM_SMS_INVALID_NUM;
    mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].segment = MMI_FRM_SMS_INVALID_NUM;
    memset(
        (S8*) & mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE],
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(mmi_frm_sms_deliver_msg_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_free_awaited
 * DESCRIPTION
 *  Free awaited message by index
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_free_awaited(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = mmi_frm_sms_awaited[index].msg_data[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i != MMI_FRM_SMS_INVALID_NUM)
    {
        U8 nextindex = mmi_frm_sms_content[i].nextindex;

        if (mmi_frm_sms_content[i].data != NULL)
        {
            OslMfree(mmi_frm_sms_content[i].data);
            mmi_frm_sms_content[i].data = NULL;
        }
        mmi_frm_sms_content[i].msglen = 0;
        mmi_frm_sms_content[i].nextindex = MMI_FRM_SMS_INVALID_NUM;
        mmi_frm_sms_content[i].segment = MMI_FRM_SMS_INVALID_NUM;
        i = nextindex;
    }
    memset((S8*) & mmi_frm_sms_awaited[index], MMI_FRM_SMS_INVALID_NUM, sizeof(mmi_frm_sms_deliver_msg_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_new_data
 * DESCRIPTION
 *  free new sms buff
 * PARAMETERS
 *  entry       [IN]        Entry
 *  length      [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_add_new_data(mmi_frm_sms_deliver_data_struct *entry, U16 length, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_concat_struct *concatinfo = (mmi_frm_sms_concat_struct*) & (entry->concat_info);
    U8 segment = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((concatinfo->seg > concatinfo->total_seg) || (concatinfo->seg == 0) || (concatinfo->total_seg == 0))
    {
        concatinfo->seg = 1;
        concatinfo->total_seg = 1;
    }

    if (((concatinfo->seg) % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) == 0)
    {
        segment = (U8) g_frm_sms_cntx.mmi_frm_sms_msg_seg_size;
    }
    else
    {
        segment = (concatinfo->seg) % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size;
    }

    /* change seg info to start seg */
    concatinfo->seg =
        ((concatinfo->seg - 1) / g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) * g_frm_sms_cntx.mmi_frm_sms_msg_seg_size + 1;
#ifdef __MMI_DUAL_SIM_MASTER__
	mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].isSlave = entry->isSlave;
#endif

    mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].dest_mod_id = entry->dest_mod_id;
    mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].dest_port = entry->dest_port;
    mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].dcs = entry->dcs;
    mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].mti = entry->mti;
    memcpy(&(mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].concat_info), concatinfo, sizeof(smsal_concat_struct));

    memcpy((S8*) & (mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].oa), (S8*) & (entry->oa), sizeof(l4c_number_struct));
    memcpy((S8*) (mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].scts), (S8*) (entry->scts), 7);

    mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].data[0] = MMI_FRM_SMS_MSG_CONTENT_NUM;
    mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].message_len = entry->message_len;

    /* handle message content part */
    mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].segment = segment;
    mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].msglen = length;
    if (mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data != NULL)
    {
        OslMfree(mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data);
    }
    if (length)
    {
        mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data = OslMalloc(length);
        memcpy(mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data, (S8*) data, length);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_free_new_data
 * DESCRIPTION
 *  free new sms buff
 * PARAMETERS
 *  void
 *  entry(?)        [IN]        Entry
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_free_new_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data != NULL)
    {
        OslMfree(mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data);
        mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data = NULL;
    }
    mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].msglen = 0;
    mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].nextindex = MMI_FRM_SMS_INVALID_NUM;
    mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].segment = MMI_FRM_SMS_INVALID_NUM;
    memset(
        (S8*) & mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE],
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(mmi_frm_sms_deliver_data_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_free_data
 * DESCRIPTION
 *  Free SMS with port number by index
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_free_data(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = mmi_frm_sms_data[index].data[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i != MMI_FRM_SMS_INVALID_NUM)
    {
        U8 nextindex = mmi_frm_sms_content[i].nextindex;

        if (mmi_frm_sms_content[i].data != NULL)
        {
            OslMfree(mmi_frm_sms_content[i].data);
            mmi_frm_sms_content[i].data = NULL;
        }
        mmi_frm_sms_content[i].msglen = 0;
        mmi_frm_sms_content[i].nextindex = MMI_FRM_SMS_INVALID_NUM;
        mmi_frm_sms_content[i].segment = MMI_FRM_SMS_INVALID_NUM;
        i = nextindex;
    }
    memset((S8*) & mmi_frm_sms_data[index], MMI_FRM_SMS_INVALID_NUM, sizeof(mmi_frm_sms_deliver_data_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_new_data
 * DESCRIPTION
 *  convert mt structure to entry structure
 * PARAMETERS
 *  data        [?]     New data
 *  entry       [?]     Message entry
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_convert_new_data(MMI_FRM_SMS_APP_DATA_IND_STRUCT *data, mmi_frm_sms_deliver_data_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry->dest_mod_id = data->dest_mod_id;
    entry->dest_port = data->dest_port;
    entry->src_port = data->src_port;
    entry->dcs = data->dcs;
    entry->mti = data->mti;
    entry->message_len = data->message_len;
    entry->concat_info = data->concat_info[0];
    memcpy(&entry->oa, &data->oa, sizeof(l4_addr_bcd_struct));
    memcpy(entry->scts, data->scts, 7);
#ifdef __MMI_DUAL_SIM_MASTER__
	entry->isSlave = FALSE;
#endif
    entry->data[0] = MMI_FRM_SMS_MSG_CONTENT_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_new_sms
 * DESCRIPTION
 *  convert mt structure to entry structure
 * PARAMETERS
 *  data        [?]     Data
 *  entry       [?]     
 *  a  index    index(?)
 *  b  type     type(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_convert_new_sms(MMI_FRM_SMS_DELIVER_MSG_IND_STRUCT *data, mmi_frm_sms_deliver_msg_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry->fo = data->fo;
    memcpy(entry->scts, data->scts, 7);
    memcpy(&entry->sca_number, &data->sca_number, sizeof(l4c_number_struct));
    memcpy(&entry->addr_number, &data->oa_number, sizeof(l4c_number_struct));
    entry->pid = data->pid;
    entry->dcs = data->dcs;
    entry->ori_dcs = data->ori_dcs;
    entry->index = data->index; /* for awaited message, this is the start index */
    entry->mti = data->mti;
    entry->display_type = data->display_type;
#ifdef __MMI_MESSAGES_COPY__
    entry->storageType = data->storage_type;
#endif 
    entry->concat_info = data->concat_info;
    entry->no_msg_data = data->no_msg_data;
    entry->msg_data[0] = MMI_FRM_SMS_MSG_CONTENT_NUM;
	entry->src_port = data->src_port;
	entry->dest_port = data->dest_port;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_mt_to_entry
 * DESCRIPTION
 *  convert mt structure to entry structure
 * PARAMETERS
 *  data        [?]     Data
 *  entry       [?]     
 *  a  index    index(?)
 *  b  type     type(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_convert_mt_to_entry(mmi_frm_sms_deliver_msg_struct *data, mmi_frm_sms_msgbox_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type;
    U8 numbertype = (data->addr_number.type == CSMCC_INTERNATIONAL_ADDR ||
                     (data->addr_number.type & 0xf0) == 0x90) ? 1 : 0;
    mmi_frm_sms_concat_struct *concat = (mmi_frm_sms_concat_struct*) & (data->concat_info);
    MMI_BOOL is_compress = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) entry->number, 0, MAX_DIGITS_SMS);
    if (numbertype)
    {
        entry->number[0] = '+';
    }
    memcpy(entry->number + numbertype, data->addr_number.number, data->addr_number.length);

#ifdef __MMI_MESSAGES_MOSES_FEATURE__    
    if ((data->addr_number.type & 0xd0) == 0xd0)
    {
        /* Support ORANGE MOSES requirement */
        if (data->addr_number.length == 5 &&
            strcmp((S8*)data->addr_number.number,(S8*)MMI_FRM_SMS_MOSES_PATTERN) == 0)
        {

            if (gOpNameValid && (mmi_ucs2strlen(gOperatorName) != 0))
            {
                memset((S8*) entry->number, 0, sizeof(entry->number));
                mmi_ucs2_n_to_asc((S8*) entry->number, (S8*) gOperatorName, sizeof(entry->number));
            }            
        }

    }
#endif /* __MMI_MESSAGES_MOSES_FEATURE__ */    
    
    type = MMI_FRM_SMS_UNREAD;

#ifdef __MMI_UNIFIED_MESSAGE__
#ifdef __MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__

    if (data->dcs == SMSAL_8BIT_DCS)
    {
        entry->msgtype = (SMSAL_MTI_UNSPECIFIED << 12) | type;
    }
    else
#endif /* __MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__ */ 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    {
        entry->msgtype = (data->mti << 12) | type;
    }
    
    /* Compress dcs SMS is not supported. */
    ems_decode_dcs(data->ori_dcs, &is_compress);
    if (is_compress)
    {
        entry->msgtype = (SMSAL_MTI_UNSPECIFIED << 12) | type;	
    }
	else
	{
		/* The NSM SMS is not supported  */
		if ((data->dest_port == 0x1581) || (data->dest_port == 0x158A) || 
			(data->dest_port == 0x1582) || (data->dest_port == 0x1583))
		{
	        entry->msgtype = (SMSAL_MTI_UNSPECIFIED << 12) | type;
	    }
	}

    entry->startseg =
        ((concat->seg - 1) / g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) * g_frm_sms_cntx.mmi_frm_sms_msg_seg_size + 1;
    entry->totalseg = concat->total_seg;
    entry->startindex = data->index;
#ifdef __MMI_MESSAGES_COPY__
    entry->storageType = data->storageType;
#endif 

    entry->ref = concat->ref;
    mmi_frm_sms_convert_time_stamp(data->scts, entry->timestamp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_mo_to_entry
 * DESCRIPTION
 *  convert mo structure to entry structure
 * PARAMETERS
 *  data                [?]         Data
 *  entry               [?]         
 *  index               [IN]        Index
 *  status              [IN]        
 *  totalsegment        [IN]        
 *  reference           [IN]        
 *  storagetype         [IN]        
 *  time                [?]         
 *  b  type     type(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_convert_mo_to_entry(
        mmi_frm_sms_send_struct *data,
        mmi_frm_sms_msgbox_struct *entry,
        U16 index,
        U8 status,
        U8 totalsegment,
        U16 reference,
        U8 storagetype,
        MYTIME *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status)
    {
        case SMSAL_REC_UNREAD:
            type = MMI_FRM_SMS_UNREAD;
            break;
        case SMSAL_REC_READ:
            type = MMI_FRM_SMS_INBOX;
            break;
        case SMSAL_STO_SENT:
            type = MMI_FRM_SMS_OUTBOX;
            break;
        case SMSAL_STO_UNSENT:
        #ifdef __MMI_UNIFIED_MESSAGE__
            type = MMI_FRM_SMS_UNSENT;
		#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
			if (strlen((S8*) data->number) == 0)
			{
				type = MMI_FRM_SMS_DRAFTS;
			}
		#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        #else /* __MMI_UNIFIED_MESSAGE__ */
            type = MMI_FRM_SMS_DRAFTS;
        #endif
            break;
        case SMSAL_STO_DRAFT:
            type = MMI_FRM_SMS_DRAFTS;
            break;
    }
    entry->msgtype = (SMSAL_MTI_SUBMIT << 12) | type;
    entry->startindex = index;

    entry->startseg = 1;
    entry->totalseg = totalsegment;

    memset((S8*) entry->timestamp, 0, 7);
    memset((S8*) entry->number, 0, 21);
    memcpy((S8*) entry->number, (S8*) data->number, strlen((S8*) data->number));

    entry->ref = reference;
#ifdef __MMI_MESSAGES_COPY__
    entry->storageType = storagetype;
#endif 

    if (storagetype == SMSAL_SM)
    {
        memset((S8*) entry->timestamp, 0, 7);
    }
    else
    {
        /* Add timestamp information  */
        if (time->nYear > 2000)
        {
            entry->timestamp[0] = (U8) (time->nYear - 2000);
        }
        else
        {
            entry->timestamp[0] = (U8) (time->nYear - 1900);
        }
        entry->timestamp[1] = time->nMonth;
        entry->timestamp[2] = time->nDay;
        entry->timestamp[3] = time->nHour;
        entry->timestamp[4] = time->nMin;
        entry->timestamp[5] = time->nSec;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_read_to_entry
 * DESCRIPTION
 *  convert read structure to entry structure
 * PARAMETERS
 *  data        [?]         Data
 *  entry       [?]         
 *  index       [IN]        Index
 *  b  type     type(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_convert_read_to_entry(
        MMI_FRM_SMS_GET_MSG_RSP_STRUCT *data,
        mmi_frm_sms_msgbox_struct *entry,
        U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type;
    mmi_frm_sms_concat_struct *concat = (mmi_frm_sms_concat_struct*) & (data->concat_info);
    MMI_BOOL is_compress = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->status)
    {
        case SMSAL_REC_UNREAD:
            type = MMI_FRM_SMS_UNREAD;
            break;
        case SMSAL_REC_READ:
            type = MMI_FRM_SMS_INBOX;
            break;
        case SMSAL_STO_SENT:
            type = MMI_FRM_SMS_OUTBOX;
            break;
        case SMSAL_STO_UNSENT:
        #ifdef __MMI_UNIFIED_MESSAGE__
            type = MMI_FRM_SMS_UNSENT;
        #else
            type = MMI_FRM_SMS_DRAFTS;
        #endif
            break;
        case SMSAL_STO_DRAFT:
            type = MMI_FRM_SMS_DRAFTS;
            break;
        default:
            type = MMI_FRM_SMS_NOBOX;
            break;
    }
    
#ifdef __MMI_UNIFIED_MESSAGE__
#ifdef __MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__

    if (data->dcs == SMSAL_8BIT_DCS)
    {
        entry->msgtype = (SMSAL_MTI_UNSPECIFIED << 12) | type;
    }
    else
#endif /* __MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__ */ 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    {
        entry->msgtype = (data->mti << 12) | type;
    }

    /* Compress dcs SMS is not supported. */
    ems_decode_dcs(data->ori_dcs, &is_compress);
    if (is_compress)
    {
        entry->msgtype = (SMSAL_MTI_UNSPECIFIED << 12) | type;
    }
	else
	{
		/* The NSM SMS is not supported  */
		if ((data->dest_port == 0x1581) || (data->dest_port == 0x158A) || 
			(data->dest_port == 0x1582) || (data->dest_port == 0x1583))
		{
	        entry->msgtype = (SMSAL_MTI_UNSPECIFIED << 12) | type;
	    }
	}

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    entry->send_status = MMI_FRM_SMS_FAILTOSEND;
#endif

    entry->startseg =
        ((concat->seg - 1) / g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) * g_frm_sms_cntx.mmi_frm_sms_msg_seg_size + 1;
    entry->totalseg = concat->total_seg;

    memset((S8*) entry->number, 0, MAX_DIGITS_SMS);
    type = (data->addr_number.type == CSMCC_INTERNATIONAL_ADDR ||
            (data->addr_number.type & 0xf0) == 0x90) ? 1 : 0;
    if (type)
    {
        entry->number[0] = '+';
    }
    memcpy((S8*) & (entry->number[type]), (S8*) data->addr_number.number, data->addr_number.length);
    
#ifdef __MMI_MESSAGES_MOSES_FEATURE__    
    if ((data->addr_number.type & 0xd0) == 0xd0)
    {
        /* Support ORANGE MOSES requirement */
        if (data->addr_number.length == 5 &&
            strcmp((S8*)data->addr_number.number,(S8*)MMI_FRM_SMS_MOSES_PATTERN) == 0)
        {

            if (gOpNameValid && (mmi_ucs2strlen(gOperatorName) != 0))
            {
                memset((S8*) entry->number, 0, sizeof(entry->number));
                mmi_ucs2_n_to_asc((S8*) entry->number, (S8*) gOperatorName, sizeof(entry->number));
            }            
        }

    }
#endif /* __MMI_MESSAGES_MOSES_FEATURE__ */    

    entry->ref = concat->ref;
    entry->startindex = index;
#ifdef __MMI_MESSAGES_COPY__
    entry->storageType = data->storage_type;
#endif 

#ifdef __MMI_UNIFIED_MESSAGE__
    {
        U8 *content = NULL;

        content = OslMalloc(MMI_FRM_SMS_MSG_LEN);
        memset(content, 0, MMI_FRM_SMS_MSG_LEN);
        memset(entry->content, 0, sizeof(entry->content));
        mmi_frm_sms_get_read_sms_content(data, content);
        if (mmi_ucs2strlen((S8*) content))
        {
            mmi_frm_sms_add_content_to_entry(entry, content);
        }

        OslMfree(content);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    mmi_frm_sms_convert_time_stamp(data->scts, entry->timestamp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_startup_read_to_entry
 * DESCRIPTION
 *  convert startup read structure to entry structure
 * PARAMETERS
 *  data        [?]     Data
 *  entry       [?]     
 *  a  index    index(?)
 *  b  type     type(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_convert_startup_read_to_entry(
        MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT *data,
        mmi_frm_sms_msgbox_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type;
    mmi_frm_sms_concat_struct concat;
    MMI_BOOL is_compress = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    concat.seg = (data->concat_info & 0xff000000) >> 24;
    concat.total_seg = (data->concat_info & 0x00ff0000) >> 16;
    concat.ref = (data->concat_info & 0x0000ffff);
	if ((concat.seg > concat.total_seg) || (concat.seg == 0) || (concat.total_seg == 0))
    {
        concat.seg = 1;
        concat.total_seg = 1;
    }

    switch (data->status)
    {
        case SMSAL_REC_UNREAD:
            type = MMI_FRM_SMS_UNREAD;
            break;
        case SMSAL_REC_READ:
            type = MMI_FRM_SMS_INBOX;
            break;
        case SMSAL_STO_SENT:
            type = MMI_FRM_SMS_OUTBOX;
            break;
        case SMSAL_STO_UNSENT:
        #ifdef __MMI_UNIFIED_MESSAGE__
            type = MMI_FRM_SMS_UNSENT;
		#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
			if (data->addr_number.length == 0 || strlen((S8*)(data->addr_number.number)) == 0)
			{
				type = MMI_FRM_SMS_DRAFTS;
			}
		#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        #else
            type = MMI_FRM_SMS_DRAFTS;
        #endif
            break;
        case SMSAL_STO_DRAFT:
            type = MMI_FRM_SMS_DRAFTS;
            break;
        default:
            type = MMI_FRM_SMS_NOBOX;
            break;
    }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    entry->send_status = MMI_FRM_SMS_FAILTOSEND;
#endif

#ifdef __MMI_UNIFIED_MESSAGE__
#ifdef __MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__

    if (data->dcs == SMSAL_8BIT_DCS)
    {
        entry->msgtype = (SMSAL_MTI_UNSPECIFIED << 12) | type;
    }
    else
#endif /* __MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__ */ 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    {
        entry->msgtype = (data->mti << 12) | type;
    }
    
    /* Compress dcs SMS is not supported. */
    ems_decode_dcs(data->ori_dcs, &is_compress);
    if (is_compress)
    {
        entry->msgtype = (SMSAL_MTI_UNSPECIFIED << 12) | type;	
    }
	else
	{
		/* The NSM SMS is not supported  */
		if ((data->dest_port == 0x1581) || (data->dest_port == 0x158A) || 
			(data->dest_port == 0x1582) || (data->dest_port == 0x1583))
		{
	        entry->msgtype = (SMSAL_MTI_UNSPECIFIED << 12) | type;
	    }
	}

    entry->startseg =
        ((concat.seg - 1) / g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) * g_frm_sms_cntx.mmi_frm_sms_msg_seg_size + 1;
    entry->totalseg = concat.total_seg;

    memset((S8*) entry->number, 0, MAX_DIGITS_SMS);
    type = (data->addr_number.type == CSMCC_INTERNATIONAL_ADDR ||
            (data->addr_number.type & 0xf0) == 0x90) ? 1 : 0;
    if (type)
    {
        entry->number[0] = '+';
    }
    memcpy((S8*) & (entry->number[type]), (S8*) data->addr_number.number, data->addr_number.length);

#ifdef __MMI_MESSAGES_MOSES_FEATURE__    
    if ((data->addr_number.type & 0xd0) == 0xd0)
    {
        /* Support ORANGE MOSES requirement */
        if (data->addr_number.length == 5 &&
            strcmp((S8*)data->addr_number.number,(S8*)MMI_FRM_SMS_MOSES_PATTERN) == 0)
        {

            if (gOpNameValid && (mmi_ucs2strlen(gOperatorName) != 0))
            {
                memset((S8*) entry->number, 0, sizeof(entry->number));
                mmi_ucs2_n_to_asc((S8*) entry->number, (S8*) gOperatorName, sizeof(entry->number));
            }            
        }

    }
#endif /* __MMI_MESSAGES_MOSES_FEATURE__ */

    entry->ref = concat.ref;
    entry->startindex = data->index;
    mmi_frm_sms_convert_time_stamp(data->scts, entry->timestamp);
#ifdef __MMI_MESSAGES_COPY__
    entry->storageType = data->storage_type;
#endif 

#ifdef __MMI_UNIFIED_MESSAGE__
    {
        U8 *content = NULL;

        memset(entry->content, 0, sizeof(entry->content));
        content = OslMalloc(MMI_FRM_SMS_MSG_LEN);
        memset(content, 0, MMI_FRM_SMS_MSG_LEN);
        mmi_frm_sms_get_startup_sms_content(data, content);
        if (mmi_ucs2strlen((S8*) content))
        {
            mmi_frm_sms_add_content_to_entry(entry, content);
        }

        OslMfree(content);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_compare_entry
 * DESCRIPTION
 *  convert mo structure to entry structure
 * PARAMETERS
 *  index           [IN]        Index
 *  data            [?]         Data
 *  thissegment     [IN]        
 *  b  type     type(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_sms_compare_entry(U16 index, mmi_frm_sms_msgbox_struct *data, U8 thissegment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* concatenate class0 message will have a MMI_FRM_SMS_INVALID_INDEX startindex */
    if ((data->startindex != MMI_FRM_SMS_INVALID_INDEX) && (mmi_frm_sms_msg_box[index].startindex == data->startindex))
    {
        return TRUE;
    }
    if ((mmi_frm_sms_msg_box[index].msgtype & 0xf000) == (data->msgtype & 0xf000))
        if (mmi_frm_sms_msg_box[index].ref == data->ref)
            if (mmi_frm_sms_msg_box[index].totalseg == data->totalseg)
                if (mmi_frm_sms_msg_box[index].startseg == data->startseg)
                    if (ComparePhoneNum((U8*) data->number, (U8*) mmi_frm_sms_msg_box[index].number) == TRUE)
                    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                        if (mmi_frm_sms_msg_box[index].storageType == data->storageType)
                    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
					#ifdef __MMI_DUAL_SIM_MASTER__
						 if (MTPNP_AD_Index_IsSame_Part((U16)mmi_frm_sms_msg_box[index].startindex, data->startindex))
					#endif
                        {
                            U16 i = mmi_frm_sms_msg_box[index].startindex;
                            U16 previndex = MMI_FRM_SMS_INVALID_INDEX;

                        while (i != MMI_FRM_SMS_INVALID_INDEX)
                        {
                            if (mmi_frm_sms_index_list[i].segment == thissegment)
                            {
                                return FALSE;
                            }
                            else if (mmi_frm_sms_index_list[i].segment > thissegment)
                            {
                                return TRUE;
                            }
                            previndex = i;
                            i = mmi_frm_sms_index_list[i].nextindex;
                        }
                        if ((previndex != MMI_FRM_SMS_INVALID_INDEX) &&
                            (mmi_frm_sms_index_list[previndex].segment < thissegment))
                        {
                            return TRUE;
                        }
                    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_sms_to_list
 * DESCRIPTION
 *  mmi_frm_sms_add_sms_to_list
 * PARAMETERS
 *  data        [?]         Data
 *  index       [IN]        Index
 *  b  type     type(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_add_sms_to_list(mmi_frm_sms_msgbox_struct *data, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 type = MMI_FRM_SMS_NOBOX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data->msgtype & MMI_FRM_SMS_UNREAD) == MMI_FRM_SMS_UNREAD)
    {
        type = MMI_FRM_SMS_UNREAD;
    }
    else if ((data->msgtype & MMI_FRM_SMS_INBOX) == MMI_FRM_SMS_INBOX)
    {
        type = MMI_FRM_SMS_INBOX;
    }
    else if ((data->msgtype & MMI_FRM_SMS_OUTBOX) == MMI_FRM_SMS_OUTBOX)
    {
        type = MMI_FRM_SMS_OUTBOX;
    }
    else if ((data->msgtype & MMI_FRM_SMS_DRAFTS) == MMI_FRM_SMS_DRAFTS)
#ifdef __MMI_MESSAGES_DRAFT_BOX__
        type = MMI_FRM_SMS_DRAFTS;
#else 
        type = MMI_FRM_SMS_OUTBOX;
#endif 

#ifdef __MMI_UNIFIED_MESSAGE__
    else if ((data->msgtype & MMI_FRM_SMS_UNSENT) == MMI_FRM_SMS_UNSENT)
    {
        type = MMI_FRM_SMS_UNSENT;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (data->storageType == SMSAL_SM)
    {
        type = MMI_FRM_SMS_SIM;
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    switch (type)
    {
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
        {
            U16 i = 0;
            U16 j;

            while (i < mmi_frm_sms_inbox_size)
            {
                if (mmi_frm_sms_inbox_list[i] == index)
                {
                    return;
                }
                if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[0] < data->timestamp[0])
                {
                    break;
                }
                else if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[0] > data->timestamp[0])
                {
                    i++;
                    continue;
                }
                if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[1] < data->timestamp[1])
                {
                    break;
                }
                else if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[1] > data->timestamp[1])
                {
                    i++;
                    continue;
                }
                if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[2] < data->timestamp[2])
                {
                    break;
                }
                else if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[2] > data->timestamp[2])
                {
                    i++;
                    continue;
                }
                if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[3] < data->timestamp[3])
                {
                    break;
                }
                else if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[3] > data->timestamp[3])
                {
                    i++;
                    continue;
                }
                if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[4] < data->timestamp[4])
                {
                    break;
                }
                else if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[4] > data->timestamp[4])
                {
                    i++;
                    continue;
                }
                if (mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[i]].timestamp[5] <= data->timestamp[5])
                {
                    break;
                }
                i++;
                continue;
            }
            if (mmi_frm_sms_inbox_size > 0)
            {
                for (j = mmi_frm_sms_inbox_size; j > i; j--)
                {
                    mmi_frm_sms_inbox_list[j] = mmi_frm_sms_inbox_list[j - 1];
                }
            }
            mmi_frm_sms_inbox_list[i] = index;
            mmi_frm_sms_inbox_size++;
        }
            break;

        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
        {
            U16 i = 0;
            U16 j = 0;
            U16 k = 0;

            for (k = 0; k < mmi_frm_sms_outbox_size; k++)
            {
                if (mmi_frm_sms_outbox_list[k] == index)
                {
                    return;
                }
            }

            /* No timestamp */
            if (data->timestamp[1] == 0)
            {
                mmi_frm_sms_outbox_list[mmi_frm_sms_outbox_size] = index;
                mmi_frm_sms_outbox_size++;
            }
            else
            {
                while (i < mmi_frm_sms_outbox_size)
                {
                    if (mmi_frm_sms_outbox_list[i] == index)
                    {
                        return;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[0] < data->timestamp[0])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[0] > data->timestamp[0])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[1] < data->timestamp[1])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[1] > data->timestamp[1])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[2] < data->timestamp[2])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[2] > data->timestamp[2])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[3] < data->timestamp[3])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[3] > data->timestamp[3])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[4] < data->timestamp[4])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[4] > data->timestamp[4])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[i]].timestamp[5] <= data->timestamp[5])
                    {
                        break;
                    }
                    i++;
                    continue;
                }
                if (mmi_frm_sms_outbox_size > 0)
                {
                    for (j = mmi_frm_sms_outbox_size; j > i; j--)
                    {
                        mmi_frm_sms_outbox_list[j] = mmi_frm_sms_outbox_list[j - 1];
                    }
                }
                mmi_frm_sms_outbox_list[i] = index;
                mmi_frm_sms_outbox_size++;
            }
        }
            break;

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
        {
            U16 i = 0;
            U16 j = 0;
            U16 k = 0;

            for (k = 0; k < mmi_frm_sms_drafts_size; k++)
            {
                if (mmi_frm_sms_drafts_list[k] == index)
                {
                    return;
                }
            }

            /* No timestamp */
            if (data->timestamp[1] == 0)
            {
                mmi_frm_sms_drafts_list[mmi_frm_sms_drafts_size] = index;
                mmi_frm_sms_drafts_size++;
            }
            else
            {
                while (i < mmi_frm_sms_drafts_size)
                {
                    if (mmi_frm_sms_drafts_list[i] == index)
                    {
                        return;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[0] < data->timestamp[0])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[0] > data->timestamp[0])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[1] < data->timestamp[1])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[1] > data->timestamp[1])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[2] < data->timestamp[2])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[2] > data->timestamp[2])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[3] < data->timestamp[3])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[3] > data->timestamp[3])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[4] < data->timestamp[4])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[4] > data->timestamp[4])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[i]].timestamp[5] <= data->timestamp[5])
                    {
                        break;
                    }
                    i++;
                    continue;
                }
                if (mmi_frm_sms_drafts_size > 0)
                {
                    for (j = mmi_frm_sms_drafts_size; j > i; j--)
                    {
                        mmi_frm_sms_drafts_list[j] = mmi_frm_sms_drafts_list[j - 1];
                    }
                }
                mmi_frm_sms_drafts_list[i] = index;
                mmi_frm_sms_drafts_size++;
            }
        }
        break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */
    
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
        {
            U16 i = 0;
            U16 j = 0;
            U16 k = 0;

            for (k = 0; k < mmi_frm_sms_unsent_size; k++)
            {
                if (mmi_frm_sms_unsent_list[k] == index)
                {
                    return;
                }
            }

            /* No timestamp */
            if (data->timestamp[1] == 0)
            {
                mmi_frm_sms_unsent_list[mmi_frm_sms_unsent_size] = index;
                mmi_frm_sms_unsent_size++;
            }
            else
            {
                while (i < mmi_frm_sms_unsent_size)
                {
                    if (mmi_frm_sms_unsent_list[i] == index)
                    {
                        return;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[0] < data->timestamp[0])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[0] > data->timestamp[0])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[1] < data->timestamp[1])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[1] > data->timestamp[1])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[2] < data->timestamp[2])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[2] > data->timestamp[2])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[3] < data->timestamp[3])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[3] > data->timestamp[3])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[4] < data->timestamp[4])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[4] > data->timestamp[4])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].timestamp[5] <= data->timestamp[5])
                    {
                        break;
                    }
                    i++;
                    continue;
                }
                if (mmi_frm_sms_unsent_size > 0)
                {
                    for (j = mmi_frm_sms_unsent_size; j > i; j--)
                    {
                        mmi_frm_sms_unsent_list[j] = mmi_frm_sms_unsent_list[j - 1];
                    }
                }
                mmi_frm_sms_unsent_list[i] = index;
                mmi_frm_sms_unsent_size++;
            }
        }
        break;
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
        {
            U16 i = 0;
            U16 j = 0;
            U16 k = 0;

            if (mmi_frm_sms_sim_list == NULL)
            {
                return;
            }
            
            for (k = 0; k < mmi_frm_sms_simbox_size; k++)
            {
                if (mmi_frm_sms_sim_list[k] == index)
                {
                    return;
                }
            }

            /* No timestamp */
            if (data->timestamp[1] == 0)
            {
                mmi_frm_sms_sim_list[mmi_frm_sms_simbox_size] = index;
                mmi_frm_sms_simbox_size++;
            }
            else
            {
                while (i < mmi_frm_sms_simbox_size)
                {
                    if (mmi_frm_sms_sim_list[i] == index)
                    {
                        return;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[0] < data->timestamp[0])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[0] > data->timestamp[0])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[1] < data->timestamp[1])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[1] > data->timestamp[1])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[2] < data->timestamp[2])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[2] > data->timestamp[2])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[3] < data->timestamp[3])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[3] > data->timestamp[3])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[4] < data->timestamp[4])
                    {
                        break;
                    }
                    else if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[4] > data->timestamp[4])
                    {
                        i++;
                        continue;
                    }
                    if (mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[i]].timestamp[5] <= data->timestamp[5])
                    {
                        break;
                    }
                    i++;
                    continue;
                }
                if (mmi_frm_sms_simbox_size > 0)
                {
                    for (j = mmi_frm_sms_simbox_size; j > i; j--)
                    {
                        mmi_frm_sms_sim_list[j] = mmi_frm_sms_sim_list[j - 1];
                    }
                }
                mmi_frm_sms_sim_list[i] = index;                
                mmi_frm_sms_simbox_size++;
            }
        }
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_remove_sms_from_list
 * DESCRIPTION
 *  mmi_frm_sms_remove_sms_from_list
 * PARAMETERS
 *  index       [IN]        Index
 *  type        [IN]        Type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_remove_sms_from_list(U16 index, U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[SmsUtil.c] mmi_frm_sms_remove_sms_from_list DO NOTHING -------*\n");
        return;
    }

    switch (type)
    {
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            while (i < mmi_frm_sms_inbox_size)
            {
                if (mmi_frm_sms_inbox_list[i] == index)
                {
                    break;
                }
                i++;
            }
            for (j = i; j < (mmi_frm_sms_inbox_size - 1); j++)
            {
                mmi_frm_sms_inbox_list[j] = mmi_frm_sms_inbox_list[j + 1];
            }
            mmi_frm_sms_inbox_list[j] = MMI_FRM_SMS_INVALID_INDEX;
            mmi_frm_sms_inbox_size--;
            break;

        case MMI_FRM_SMS_OUTBOX:
        #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
        #endif 
            while (i < mmi_frm_sms_outbox_size)
            {
                if (mmi_frm_sms_outbox_list[i] == index)
                {
                    break;
                }
                i++;
            }
            for (j = i; j < (mmi_frm_sms_outbox_size - 1); j++)
            {
                mmi_frm_sms_outbox_list[j] = mmi_frm_sms_outbox_list[j + 1];
            }
            mmi_frm_sms_outbox_list[j] = MMI_FRM_SMS_INVALID_INDEX;
            mmi_frm_sms_outbox_size--;
            break;

        #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
            while (i < mmi_frm_sms_drafts_size)
            {
                if (mmi_frm_sms_drafts_list[i] == index)
                {
                    break;
                }
                i++;
            }
            for (j = i; j < (mmi_frm_sms_drafts_size - 1); j++)
            {
                mmi_frm_sms_drafts_list[j] = mmi_frm_sms_drafts_list[j + 1];
            }
            mmi_frm_sms_drafts_list[j] = MMI_FRM_SMS_INVALID_INDEX;
            mmi_frm_sms_drafts_size--;
            break;
        #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
        #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            while (i < mmi_frm_sms_unsent_size)
            {
                if (mmi_frm_sms_unsent_list[i] == index)
                {
                    break;
                }
                i++;
            }
            for (j = i; j < (mmi_frm_sms_unsent_size - 1); j++)
            {
                mmi_frm_sms_unsent_list[j] = mmi_frm_sms_unsent_list[j + 1];
            }
            mmi_frm_sms_unsent_list[j] = MMI_FRM_SMS_INVALID_INDEX;
            mmi_frm_sms_unsent_size--;
            break;
        #endif /* __MMI_UNIFIED_MESSAGE__ */         
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            if (mmi_frm_sms_sim_list != NULL)
            {
                while (i < mmi_frm_sms_simbox_size)
                {
                    if (mmi_frm_sms_sim_list[i] == index)
                    {
                        break;
                    }
                    i++;
                }
                for (j = i; j < (mmi_frm_sms_simbox_size - 1); j++)
                {
                    mmi_frm_sms_sim_list[j] = mmi_frm_sms_sim_list[j + 1];
                }
                mmi_frm_sms_sim_list[j] = MMI_FRM_SMS_INVALID_INDEX;
                mmi_frm_sms_simbox_size--;
                }
            break;
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_sms_segment
 * DESCRIPTION
 *  add one segment to sms entry
 * PARAMETERS
 *  index           [IN]        Index
 *  addindex        [IN]        Addindex
 *  segment         [IN]        Segment
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_add_sms_segment(U16 index, U16 addindex, U8 segment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 thisindex = mmi_frm_sms_msg_box[index].startindex;
    U8 islast = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_index_list[addindex].segment = segment;
    /* thisindex is the current smallest segment index of this message */
    if (mmi_frm_sms_index_list[thisindex].segment > segment)
    {
        islast = FALSE;
        /* addindex is inserted in the head, now addindex is the current smallest segment index of this message */
        mmi_frm_sms_msg_box[index].startindex = addindex;
    }
    else
    {
        while (mmi_frm_sms_index_list[thisindex].nextindex != MMI_FRM_SMS_INVALID_INDEX)
        {
            thisindex = mmi_frm_sms_index_list[thisindex].nextindex;
            if (mmi_frm_sms_index_list[thisindex].segment > segment)
            {
                islast = FALSE;
                break;
            }
        }
    }

    if (islast == TRUE)
    {
        /* addindex is inserted in the tail, now addindex is the current largest segment index of this message */
        mmi_frm_sms_index_list[thisindex].nextindex = addindex;
        mmi_frm_sms_index_list[addindex].nextindex = MMI_FRM_SMS_INVALID_INDEX;
        mmi_frm_sms_index_list[addindex].previndex = thisindex;
        mmi_frm_sms_index_list[addindex].prevtype = MMI_FRM_SMS_NOBOX;
    }
    else
    {
        /* addindex is inserted in the middle */
        mmi_frm_sms_index_list[addindex].nextindex = thisindex;
        mmi_frm_sms_index_list[addindex].previndex = mmi_frm_sms_index_list[thisindex].previndex;
        mmi_frm_sms_index_list[addindex].prevtype = mmi_frm_sms_index_list[thisindex].prevtype;
        if (mmi_frm_sms_index_list[thisindex].prevtype == MMI_FRM_SMS_NOBOX)
        {
            mmi_frm_sms_index_list[mmi_frm_sms_index_list[thisindex].previndex].nextindex = addindex;
        }
        mmi_frm_sms_index_list[thisindex].previndex = addindex;
        mmi_frm_sms_index_list[thisindex].prevtype = MMI_FRM_SMS_NOBOX;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_sms_entry
 * DESCRIPTION
 *  add sms entry:
 * PARAMETERS
 *  data            [?]         
 *  L4index         [IN]        
 *  thissegment     [IN]        
 *  a  index       index(?)
 *  b  addindex    addindex(?)
 *  c  segment     segment(?)
 * RETURNS
 *  index
 *****************************************************************************/
U16 mmi_frm_sms_add_sms_entry(mmi_frm_sms_msgbox_struct *data, U16 L4index, U8 thissegment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 addindex = g_frm_sms_cntx.mmi_frm_sms_msg_box_size;
    U16 emptyindex = g_frm_sms_cntx.mmi_frm_sms_msg_box_size;
    U8 found = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((found == FALSE) && (addindex > 0))
    {
        addindex--;
        if (mmi_frm_sms_msg_box[addindex].startindex == MMI_FRM_SMS_INVALID_INDEX)
        {
            emptyindex = addindex;
            continue;
        }
        if (mmi_frm_sms_compare_entry(addindex, data, thissegment) == TRUE)
        {
            found = TRUE;
            break;
        }
    }
    if (found == FALSE)
    {
        U16 type;

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        if (data->storageType == SMSAL_SM)
        {
            type = MMI_FRM_SMS_SIM;
        }
        else
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        if ((data->msgtype & MMI_FRM_SMS_INBOX) == MMI_FRM_SMS_INBOX)
        {
            type = MMI_FRM_SMS_INBOX;
        }
        else if ((data->msgtype & MMI_FRM_SMS_UNREAD) == MMI_FRM_SMS_UNREAD)
        {
            type = MMI_FRM_SMS_UNREAD;
        }
        else if ((data->msgtype & MMI_FRM_SMS_OUTBOX) == MMI_FRM_SMS_OUTBOX)
        {
            type = MMI_FRM_SMS_OUTBOX;
        }
    #ifdef __MMI_UNIFIED_MESSAGE__
        else if ((data->msgtype & MMI_FRM_SMS_UNSENT) == MMI_FRM_SMS_UNSENT)
        {
            type = MMI_FRM_SMS_UNSENT;
        }
    #endif   
        else
        {
            type = MMI_FRM_SMS_DRAFTS;
        }
        memcpy((S8*) & mmi_frm_sms_msg_box[emptyindex], (S8*) data, sizeof(mmi_frm_sms_msgbox_struct));
        mmi_frm_sms_index_list[L4index].segment = thissegment;
        /* mmi_frm_sms_index_list[L4index].nextindex=MMI_FRM_SMS_INVALID_INDEX; */
        mmi_frm_sms_index_list[L4index].previndex = emptyindex;
        mmi_frm_sms_index_list[L4index].prevtype = type;
        mmi_frm_sms_msgbox_size++;
        addindex = emptyindex;
    }
    else
    {
    #ifdef __MMI_MESSAGES_COPY__
        if (mmi_frm_sms_msg_box[addindex].storageType != MMI_FRM_SMS_PREFER_STORAGE)
        {
            mmi_frm_sms_msg_box[addindex].storageType = data->storageType;
        }
    #endif /* __MMI_MESSAGES_COPY__ */ 

    #ifdef __MMI_UNIFIED_MESSAGE__
        if (mmi_frm_sms_index_list[mmi_frm_sms_msg_box[addindex].startindex].segment == thissegment - 1)
        {
            if (mmi_ucs2strlen((S8*) data->content))
            {
                if (mmi_ucs2strlen((S8*) mmi_frm_sms_msg_box[addindex].content) <
                    (mmi_msg_get_max_content_size() - 1))
                {
                    /* append data->content to mmi_frm_sms_msg_box[addindex].content */
                    U16 *temp_content;
                    U16 temp_content_size = (U16) (mmi_msg_get_max_content_size() + 1) * ENCODING_LENGTH;

                    temp_content = OslMalloc(temp_content_size);
                    memset((S8*) temp_content, 0, temp_content_size);
                    mmi_ucs2ncpy(
                        (S8*) temp_content,
                        (S8*) mmi_frm_sms_msg_box[addindex].content,
                        mmi_msg_get_max_content_size());
                    mmi_ucs2ncat(
                        (S8*) temp_content,
                        (S8*) data->content,
                        (mmi_msg_get_max_content_size() - mmi_ucs2strlen((S8*) temp_content)));

                    mmi_frm_sms_add_content_to_entry(
                        (mmi_frm_sms_msgbox_struct*) & mmi_frm_sms_msg_box[addindex],
                        (U8*) temp_content);

                    OslMfree(temp_content);

                }

            }
        }
        else if (mmi_frm_sms_index_list[mmi_frm_sms_msg_box[addindex].startindex].segment == thissegment + 1)
        {
            if (mmi_ucs2strlen((S8*) data->content))
            {
                /* copy data->content to the beginning of  mmi_frm_sms_msg_box[addindex].content */
                U16 *temp_content;
                U16 temp_content_size = (U16) (mmi_msg_get_max_content_size() + 1) * ENCODING_LENGTH;

                temp_content = OslMalloc(temp_content_size);
                memset((S8*) temp_content, 0, temp_content_size);
                mmi_ucs2ncpy((S8*) temp_content, (S8*) data->content, mmi_msg_get_max_content_size());

                if (mmi_msg_get_max_content_size() > mmi_ucs2strlen((S8*) temp_content))
                {
                    mmi_ucs2ncat(
                        (S8*) temp_content,
                        (S8*) mmi_frm_sms_msg_box[addindex].content,
                        (mmi_msg_get_max_content_size() - mmi_ucs2strlen((S8*) temp_content)));
                }

                mmi_frm_sms_add_content_to_entry(
                    (mmi_frm_sms_msgbox_struct*) & mmi_frm_sms_msg_box[addindex],
                    (U8*) temp_content);

                OslMfree(temp_content);

            }
        }
        else if (mmi_frm_sms_index_list[mmi_frm_sms_msg_box[addindex].startindex].segment > thissegment)
        {
            if (mmi_ucs2strlen((S8*) data->content))
            {
                mmi_frm_sms_add_content_to_entry(
                    (mmi_frm_sms_msgbox_struct*) & mmi_frm_sms_msg_box[addindex],
                    (U8*) data->content);
            }
        }
        else
        {
            /* thissegment > start_segment + 1 */
            /* If thissegment is the last segment of received segments, append the content */
            if (mmi_ucs2strlen((S8*) mmi_frm_sms_msg_box[addindex].content) <
                (mmi_msg_get_max_content_size() - 1))
            {
                U16 l4_index = mmi_frm_sms_index_list[mmi_frm_sms_msg_box[addindex].startindex].nextindex;

                if (l4_index == MMI_FRM_SMS_INVALID_INDEX)
                {
                    /* Do nothing */
                    ;
                }
                else
                {
                    for (;;)
                    {
                        /* Received segments are continuous */
                        if (mmi_frm_sms_index_list[l4_index].nextindex == MMI_FRM_SMS_INVALID_INDEX)
                        {

                            if ((mmi_frm_sms_index_list[l4_index].segment - 1 ) != 
                                mmi_frm_sms_index_list[mmi_frm_sms_index_list[l4_index].previndex].segment)
                            {
                                /* Do nothing if received segments are not continuous */
                                break;
                            }                

                            /* thissegment is the last segment of received segments */
                            if (thissegment == (mmi_frm_sms_index_list[l4_index].segment + 1 ))
                            {
                                /* Append the content */
                                if (mmi_ucs2strlen((S8*) data->content))
                                {
                                    /* append data->content to mmi_frm_sms_msg_box[addindex].content */
                                    U16 *temp_content;
                                    U16 temp_content_size = (U16) (mmi_msg_get_max_content_size() + 1) * ENCODING_LENGTH;

                                    temp_content = OslMalloc(temp_content_size);
                                    memset((S8*) temp_content, 0, temp_content_size);
                                    mmi_ucs2ncpy(
                                        (S8*) temp_content,
                                        (S8*) mmi_frm_sms_msg_box[addindex].content,
                                        mmi_msg_get_max_content_size());
                                    mmi_ucs2ncat(
                                        (S8*) temp_content,
                                        (S8*) data->content,
                                        (mmi_msg_get_max_content_size() - mmi_ucs2strlen((S8*) temp_content)));

                                    mmi_frm_sms_add_content_to_entry(
                                        (mmi_frm_sms_msgbox_struct*) & mmi_frm_sms_msg_box[addindex],
                                        (U8*) temp_content);

                                    OslMfree(temp_content);
                                    
                                }

                            }
                            break;
                        }   

                        if ((mmi_frm_sms_index_list[l4_index].segment - 1 ) != 
                            mmi_frm_sms_index_list[mmi_frm_sms_index_list[l4_index].previndex].segment)
                        {
                            /* Do nothing if received segments are not continuous */
                            break;
                        } 

                        l4_index = mmi_frm_sms_index_list[l4_index].nextindex;
                    }                
                }
            }
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 

        mmi_frm_sms_add_sms_segment(addindex, L4index, thissegment);

        /* If one segment of the message is unread, the message shall be unread. */
        if ((data->msgtype & MMI_FRM_SMS_UNREAD) == MMI_FRM_SMS_UNREAD)
        {
            mmi_frm_sms_msg_box[addindex].msgtype = ((mmi_frm_sms_msg_box[addindex].msgtype & 0xf000) | 
                                                     (MMI_FRM_SMS_UNREAD));
        }
    }
    return addindex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_remove_sms_entry
 * DESCRIPTION
 *  remove sms entry:
 * PARAMETERS
 *  index       [IN]        Index
 *  b  addindex    addindex(?)
 *  c  segment     segment(?)
 * RETURNS
 *  index(?)
 *****************************************************************************/
void mmi_frm_sms_remove_sms_entry(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 previndex, nextindex;
    U16 type = mmi_frm_sms_index_list[index].prevtype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    previndex = mmi_frm_sms_index_list[index].previndex;
    nextindex = mmi_frm_sms_index_list[index].nextindex;

	if (previndex == MMI_FRM_SMS_INVALID_INDEX)
	{
		return;
	}

    /* chat message is not in message box, so message box should remain unchanged and only delete index list entry */
    /* For message with only one segment, also update msg box and inbox/outbox/draft list */
    if ((type != MMI_FRM_SMS_NOBOX && type != MMI_FRM_SMS_AWAITS && type != MMI_FRM_SMS_DATA) &&
        (nextindex == MMI_FRM_SMS_INVALID_INDEX))
    {
        mmi_frm_sms_remove_sms_from_list(previndex, type);
        memset((S8*) & mmi_frm_sms_msg_box[previndex], 0xff, sizeof(mmi_frm_sms_msgbox_struct));
    }
    else
    {
        /* the first segment of message */
        if (type != MMI_FRM_SMS_NOBOX)
        {
            /* for message in awaited list, ex. chat msg,  modify start index of awaitd list entry to next index */
            if (type == MMI_FRM_SMS_AWAITS || type == MMI_FRM_SMS_DATA)
            {
                mmi_frm_sms_awaited[previndex].index = nextindex;
            }

            /* for message in msg box, ex. inbox/outbox/draft  message, modify start index of msg box entry to next index  */
            else
            {
                mmi_frm_sms_msg_box[previndex].startindex = nextindex;
            }
        }

        /* the 2nd or after segment of message */
        else
        {
            mmi_frm_sms_index_list[previndex].nextindex = nextindex;
        }

        if (nextindex != MMI_FRM_SMS_INVALID_INDEX)
        {
            mmi_frm_sms_index_list[nextindex].prevtype = type;
            mmi_frm_sms_index_list[nextindex].previndex = previndex;
        }
    }
    memset((S8*) & mmi_frm_sms_index_list[index], 0xff, sizeof(mmi_frm_sms_index_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_sms_to_msgbox
 * DESCRIPTION
 *  add sms to msgbox
 * PARAMETERS
 *  entry       [?]         
 *  index       [IN]        
 *  thisseg     [IN]        
 *  a  data     data(?)
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_frm_sms_add_sms_to_msgbox(mmi_frm_sms_msgbox_struct *entry, U16 index, U8 thisseg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 entryindex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add to msg entry */
    entryindex = mmi_frm_sms_add_sms_entry(entry, index, thisseg);

    /* update msg list */
    if (mmi_frm_sms_list_done)
    {
        mmi_frm_sms_add_sms_to_list(entry, entryindex);
    }
    return entryindex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_index
 * DESCRIPTION
 *  get sms index from bitmap
 * PARAMETERS
 *  index               [IN]        Index
 *  index_bitmap        [?]         Index_bitmap
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_frm_sms_get_index(U16 index, U8 *index_bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 start_byte_idx, i;
    U8 start_bit_idx, j, mapping_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_byte_idx = (index >> 3);  /* divide 8 */
    start_bit_idx = (index & 0x7);  /* reminder */
    for (i = start_byte_idx; i < ((g_frm_sms_cntx.mmi_frm_sms_msg_box_size >> 3) + 1); i++)
    {
        mapping_byte = index_bitmap[i];
        for (j = start_bit_idx; j < 8; j++)
        {
            if (((mapping_byte >> j) & 0x01) == 0x01)
            {
                return (i * 8 + j);
            }
        }
        start_bit_idx = 0;
    }
    return MMI_FRM_SMS_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_bitmap
 * DESCRIPTION
 *  set bitmap from index
 * PARAMETERS
 *  index               [IN]        Index
 *  index_bitmap        [?]         Index_bitmap
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_bitmap(U16 index, U8 *index_bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 byte_index;
    U8 bit_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_index = (index >> 3);  /* divide 8 */
    bit_index = (index & 0x7);  /* reminder */
    index_bitmap[byte_index] |= (0x01 << bit_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_remove_sms_from_msgbox
 * DESCRIPTION
 *  mmi_frm_sms_remove_sms_from_msgbox
 * PARAMETERS
 *  data        [?]     Data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_remove_sms_from_msgbox(U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *index_bitmap = (U8*) data;
    U16 index = mmi_frm_sms_get_index(0, index_bitmap);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (index != MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_frm_sms_remove_sms_entry(index);
        index++;
        index = mmi_frm_sms_get_index(index, index_bitmap);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_create_sms_list
 * DESCRIPTION
 *  mmi_frm_sms_create_sms_list
 * PARAMETERS
 *  void
 *  a  data     data(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_create_sms_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_list_done != TRUE
	#ifdef __MMI_DUAL_SIM_MASTER__
		&& MTPNP_AD_Card2_SMS_Is_Load_Finished()
	#endif
		)
    {
        for (i = 0; i < g_frm_sms_cntx.mmi_frm_sms_msg_box_size; i++)
        {
            if (mmi_frm_sms_msg_box[i].startindex == MMI_FRM_SMS_INVALID_INDEX)
            {
                continue;
            }
            mmi_frm_sms_add_sms_to_list(&mmi_frm_sms_msg_box[i], i);
        }
        mmi_frm_sms_list_done = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_list_index
 * DESCRIPTION
 *  map message box index to message list index
 * PARAMETERS
 *  type                [?]         Type
 *  index               [?]         Index
 *  msgbox_index        [IN]        Msgbox_index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sms_list_index(U16 *type, U16 *index, U16 msgbox_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < mmi_frm_sms_inbox_size)
    {
        if (mmi_frm_sms_inbox_list[i] == msgbox_index)
        {
            *type = MMI_FRM_SMS_INBOX;
            *index = i;
            return;
        }
        i++;
    }
    i = 0;
    while (i < mmi_frm_sms_outbox_size)
    {
        if (mmi_frm_sms_outbox_list[i] == msgbox_index)
        {
            *type = MMI_FRM_SMS_OUTBOX;
            *index = i;
            return;
        }
        i++;
    }
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    i = 0;
    while (i < mmi_frm_sms_drafts_size)
    {
        if (mmi_frm_sms_drafts_list[i] == msgbox_index)
        {
            *type = MMI_FRM_SMS_DRAFTS;
            *index = i;
            return;
        }
        i++;
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__
    i = 0;
    while (i < mmi_frm_sms_unsent_size)
    {
        if (mmi_frm_sms_unsent_list[i] == msgbox_index)
        {
            *type = MMI_FRM_SMS_UNSENT;
            *index = i;
            return;
        }
        i++;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    i = 0;
    if (mmi_frm_sms_sim_list != NULL)
    {
        while (i < mmi_frm_sms_simbox_size)
        {
            if (mmi_frm_sms_sim_list[i] == msgbox_index)
            {
                *type = MMI_FRM_SMS_SIM;
                *index = i;
                return;
            }
            i++;
        }
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_index
 * DESCRIPTION
 *  get sms index array, in sequence
 * PARAMETERS
 *  type            [IN]        Type
 *  index           [IN]        Index
 *  l4_index        [?]         L4_index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sms_index(mmi_frm_sms_msgbox_enum type, U16 index, U16 *l4_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 L4index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_frm_sms_cntx.mmi_frm_sms_msg_seg_size; i++)
    {
        l4_index[i] = MMI_FRM_SMS_INVALID_INDEX;
    }
    switch (type)
    {
        case MMI_FRM_SMS_NOBOX:
        {
            L4index = mmi_frm_sms_msg_box[index].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                l4_index[mmi_frm_sms_index_list[L4index].segment - 1] = L4index;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
            break;
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
        {
			if (index >= mmi_frm_sms_inbox_size)
			{
				return;
			}
            L4index = mmi_frm_sms_msg_box[mmi_frm_sms_inbox_list[index]].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                l4_index[mmi_frm_sms_index_list[L4index].segment - 1] = L4index;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
            break;
        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
        {
			if (index >= mmi_frm_sms_outbox_size)
			{
				return;
			}
            L4index = mmi_frm_sms_msg_box[mmi_frm_sms_outbox_list[index]].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                l4_index[mmi_frm_sms_index_list[L4index].segment - 1] = L4index;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
            break;
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
        {
			if (index >= mmi_frm_sms_drafts_size)
			{
				return;
			}
            L4index = mmi_frm_sms_msg_box[mmi_frm_sms_drafts_list[index]].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                l4_index[mmi_frm_sms_index_list[L4index].segment - 1] = L4index;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
        {
			if (index >= mmi_frm_sms_unsent_size)
			{
				return;
			}
            L4index = mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[index]].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                l4_index[mmi_frm_sms_index_list[L4index].segment - 1] = L4index;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
            break;
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
        {
            if (mmi_frm_sms_sim_list != NULL)
            {
				if (index >= mmi_frm_sms_simbox_size)
				{
					return;
				}
                L4index = mmi_frm_sms_msg_box[mmi_frm_sms_sim_list[index]].startindex;
                while (L4index != MMI_FRM_SMS_INVALID_INDEX)
                {
                    l4_index[mmi_frm_sms_index_list[L4index].segment - 1] = L4index;
                    L4index = mmi_frm_sms_index_list[L4index].nextindex;
                }
            }
        }
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_msgbox_index
 * DESCRIPTION
 *  map L4 index to message box index
 * PARAMETERS
 *  l4_index            [IN]        L4 index
 *  msgbox_index        [?]         Msgbox_index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sms_msgbox_index(U16 l4_index, U16 *msgbox_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 L4index = l4_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *msgbox_index = MMI_FRM_SMS_INVALID_INDEX;

    while (mmi_frm_sms_index_list[L4index].prevtype == MMI_FRM_SMS_NOBOX)
    {
        L4index = mmi_frm_sms_index_list[L4index].previndex;
    }

    if (mmi_frm_sms_index_list[L4index].prevtype != MMI_FRM_SMS_AWAITS &&
        mmi_frm_sms_index_list[L4index].prevtype != MMI_FRM_SMS_DATA)
    {
        *msgbox_index = mmi_frm_sms_index_list[L4index].previndex;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_bitmap
 * DESCRIPTION
 *  get sms index in bitmap
 * PARAMETERS
 *  type            [IN]        Type
 *  index           [IN]        Index
 *  l4_index        [?]         L4_index
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_sms_get_sms_bitmap(U16 type, U16 index, U8 *l4_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 startindex = index;
    U16 endindex = index + 1;
    U16 entryindex = 0;
    U16 L4index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_list_done == FALSE
	#ifdef __MMI_DUAL_SIM_MASTER__
		|| (!MTPNP_AD_Card2_SMS_Is_Load_Finished())
	#endif
		)
    {
        return FALSE;
    }

    if (type & MMI_FRM_SMS_NOBOX)
    {
        mmi_frm_sms_set_bitmap(index, l4_index);
    }

    if (type & MMI_FRM_SMS_AWAITS)
    {
        for (i = startindex; i < endindex; i++)
        {
            entryindex = index;
            L4index = entryindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }

    if ((type & MMI_FRM_SMS_INBOX) || (type & MMI_FRM_SMS_UNREAD))
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_inbox_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_inbox_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
    if ((type & MMI_FRM_SMS_OUTBOX)
#ifndef __MMI_MESSAGES_DRAFT_BOX__
        || (type & MMI_FRM_SMS_DRAFTS)
#endif 
        )
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_outbox_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_outbox_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    if (type & MMI_FRM_SMS_DRAFTS)
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_drafts_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_drafts_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */

#ifdef __MMI_UNIFIED_MESSAGE__
    if (type & MMI_FRM_SMS_UNSENT)
    {
    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        BOOL isOnlySending = TRUE;
	#endif
        
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_unsent_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_unsent_list[i];
		#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            if (mmi_frm_sms_msg_box[entryindex].send_status != MMI_FRM_SMS_SENDING)
            {
                isOnlySending = FALSE;
				mmi_frm_sms_msg_box[entryindex].send_status = MMI_FRM_SMS_FAILTOSEND;
		#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
                L4index = mmi_frm_sms_msg_box[entryindex].startindex;
                while (L4index != MMI_FRM_SMS_INVALID_INDEX)
                {
                    mmi_frm_sms_set_bitmap(L4index, l4_index);
                    L4index = mmi_frm_sms_index_list[L4index].nextindex;
                }
		#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            }
		#endif
        }
	#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        if (isOnlySending && mmi_frm_sms_unsent_size > 0)
        {
            return (U8)MMI_FRM_SMS_NOT_DELETE_SENDING;
        }
	#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if ((type & MMI_FRM_SMS_SIM))
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_simbox_size;
        }
        if (mmi_frm_sms_sim_list != NULL)
        {
            for (i = startindex; i < endindex; i++)
            {
                entryindex = mmi_frm_sms_sim_list[i];
                L4index = mmi_frm_sms_msg_box[entryindex].startindex;
                while (L4index != MMI_FRM_SMS_INVALID_INDEX)
                {
                    mmi_frm_sms_set_bitmap(L4index, l4_index);
                    L4index = mmi_frm_sms_index_list[L4index].nextindex;
                }
            }
        }
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_awaited_segment
 * DESCRIPTION
 *  add one segment to awaited entry
 * PARAMETERS
 *  index           [IN]        The index found in mmi_frm_sms_awaited that matches the last entry
 *  addindex        [IN]        Addindex
 *  segment         [IN]        The current segment of the last entry in mmi_frm_sms_awaited
 *  entry           [?]         
 * RETURNS
 *  add success or fail
 *****************************************************************************/
U8 mmi_frm_sms_add_awaited_segment(U8 index, U16 addindex, U8 segment, mmi_frm_sms_deliver_msg_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 thisindex = mmi_frm_sms_awaited[index].index;
    U8 islast = TRUE;
    U8 dataindex = 0;
    U8 thisdataindex = mmi_frm_sms_awaited[index].msg_data[0];
    U8 prevdataindex = MMI_FRM_SMS_INVALID_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find an empty entry in the mmi_frm_sms_content in order to move the last entry to that entry */
    while (dataindex < MMI_FRM_SMS_MSG_CONTENT_NUM)
    {
        if (mmi_frm_sms_content[dataindex].msglen == 0)
        {
            break;  /* found empty entry */
        }
        dataindex++;
    }
    /* if mmi_frm_sms_content is full and cannot find any empty entry, don't have to move */
    if (dataindex != MMI_FRM_SMS_MSG_CONTENT_NUM)
    {
        /* move the actual data of the last entry to the entry with the index dataindex in mmi_frm_sms_content */
        if (entry->no_msg_data)
        {
            mmi_frm_sms_content[dataindex].data = OslMalloc(entry->no_msg_data);
            memcpy(
                (S8*) mmi_frm_sms_content[dataindex].data,
                (S8*) mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data,
                entry->no_msg_data);
        }
        mmi_frm_sms_content[dataindex].msglen = entry->no_msg_data;
        mmi_frm_sms_content[dataindex].segment = segment;
    }
    mmi_frm_sms_awaited[index].no_msg_data += entry->no_msg_data;
    MMI_ASSERT(mmi_frm_sms_awaited[index].no_msg_data <= MMI_SMS_MAX_MSG_SEG * MMI_FRM_SMS_MSG_LEN);
    if (addindex != MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_frm_sms_index_list[addindex].segment = segment;
    }
    /* thisdataindex is the current smallest segment index of this message */
    if (mmi_frm_sms_content[thisdataindex].segment > segment)
    {
        islast = FALSE;
        /* dataindex is inserted in the head, now dataindex is the current smallest segment index of this message */
        mmi_frm_sms_content[dataindex].nextindex = thisdataindex;
        mmi_frm_sms_awaited[index].msg_data[0] = dataindex;
        if (addindex != MMI_FRM_SMS_INVALID_INDEX)
        {
            mmi_frm_sms_awaited[index].index = addindex;
        }
    }
    else
    {
        while (mmi_frm_sms_content[thisdataindex].nextindex != MMI_FRM_SMS_INVALID_NUM)
        {
            if (addindex != MMI_FRM_SMS_INVALID_INDEX)
            {
                thisindex = mmi_frm_sms_index_list[thisindex].nextindex;
            }
            prevdataindex = thisdataindex;
            thisdataindex = mmi_frm_sms_content[thisdataindex].nextindex;
            if (mmi_frm_sms_content[thisdataindex].segment > segment)
            {
                islast = FALSE;
                break;
            }
        }
    }

    if (islast == TRUE)
    {
        /* dataindex is inserted in the tail, now dataindex is the current largest segment index of this message */
        mmi_frm_sms_content[thisdataindex].nextindex = dataindex;
        mmi_frm_sms_content[dataindex].nextindex = MMI_FRM_SMS_INVALID_NUM;
        if (addindex != MMI_FRM_SMS_INVALID_INDEX)
        {
            mmi_frm_sms_index_list[thisindex].nextindex = addindex;
            mmi_frm_sms_index_list[addindex].nextindex = MMI_FRM_SMS_INVALID_INDEX;
            mmi_frm_sms_index_list[addindex].previndex = thisindex;
            mmi_frm_sms_index_list[addindex].prevtype = MMI_FRM_SMS_NOBOX;
        }
    }
    else
    {
        /* dataindex is inserted in the middle */
        if (prevdataindex != MMI_FRM_SMS_INVALID_NUM)
        {
            mmi_frm_sms_content[prevdataindex].nextindex = dataindex;
        }
        mmi_frm_sms_content[dataindex].nextindex = thisdataindex;
        if (addindex != MMI_FRM_SMS_INVALID_INDEX)
        {
            mmi_frm_sms_index_list[addindex].nextindex = thisindex;
            mmi_frm_sms_index_list[addindex].previndex = mmi_frm_sms_index_list[thisindex].previndex;
            mmi_frm_sms_index_list[addindex].prevtype = mmi_frm_sms_index_list[thisindex].prevtype;
            if (mmi_frm_sms_index_list[thisindex].prevtype == MMI_FRM_SMS_NOBOX)
            {
                mmi_frm_sms_index_list[mmi_frm_sms_index_list[thisindex].previndex].nextindex = addindex;
            }
            mmi_frm_sms_index_list[thisindex].previndex = addindex;
            mmi_frm_sms_index_list[thisindex].prevtype = MMI_FRM_SMS_NOBOX;
        }
    }
    /* mmi_frm_sms_content is full and cannot handle other new segment coming anymore */
    if (dataindex == MMI_FRM_SMS_MSG_CONTENT_NUM)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_awaited_entry
 * DESCRIPTION
 *  add sms to awaited list
 * PARAMETERS
 *  void
 *  a  type        type(?)
 *  b  index       index(?)
 *  c  l4_index    l4_index(?)
 * RETURNS
 *  TRUE: inserted, FALSE: not inserted
 *****************************************************************************/
U8 mmi_frm_sms_add_awaited_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 dataindex = 0;
    U16 index = mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].index;
    U16 length = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].msglen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (dataindex < MMI_FRM_SMS_MSG_CONTENT_NUM)
    {
        if (mmi_frm_sms_content[dataindex].segment == MMI_FRM_SMS_INVALID_NUM)
        {
            break;  /* found empty entry */
        }
        dataindex++;
    }
    /* cannot find any empty entry in mmi_frm_sms_content */
    if (dataindex == MMI_FRM_SMS_MSG_CONTENT_NUM)
    {
        return MMI_FRM_SMS_INVALID_NUM;
    }

    mmi_frm_sms_content[dataindex].msglen = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].msglen;
    mmi_frm_sms_content[dataindex].nextindex = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].nextindex;
    mmi_frm_sms_content[dataindex].segment = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].segment;
    /* mmi_frm_sms_content[dataindex].data=mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data;*/
    /* mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data=NULL;*/
    if (length)
    {
        mmi_frm_sms_content[dataindex].data = OslMalloc(length);
        memcpy(mmi_frm_sms_content[dataindex].data, mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data, length);
    }

    while (i < MMI_FRM_SMS_ACTION_SIZE)
    {
        if (mmi_frm_sms_awaited[i].msg_data[0] == MMI_FRM_SMS_INVALID_NUM)
        {
            memcpy(
                &(mmi_frm_sms_awaited[i]),
                &(mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE]),
                sizeof(mmi_frm_sms_deliver_msg_struct));
            mmi_frm_sms_awaited[i].msg_data[0] = dataindex;

            /* non-class 0 message!!!!!!! */
            if (index != MMI_FRM_SMS_INVALID_INDEX)
                mmi_frm_sms_index_list[index].previndex = i;;
            return i;
        }
        i++;
    }
    /* cannot find any empty entry in mmi_frm_sms_awaited */
    return MMI_FRM_SMS_INVALID_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_awaited_sms
 * DESCRIPTION
 *  Get awaited SMS by index
 * PARAMETERS
 *  index       [IN]        Index
 *  entry       [?]         Message entry info
 *  content     [?]         Message content
 * RETURNS
 *  object present
 *****************************************************************************/
U8 mmi_frm_sms_get_awaited_sms(U8 index, mmi_frm_sms_deliver_msg_struct *entry, U8 *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i = 0;
    U8 nextindex = mmi_frm_sms_awaited[index].msg_data[0];
    EMSData *pEMSdata = NULL;
    U8 *textBuff;
    U8 *TPUD[10];
    U8 TPUDLEN[10];
    U8 is_obj_present = 0;
    U16 buffLen = mmi_frm_sms_awaited[index].no_msg_data;
    U16 textLen = 0;
    U8 totalseg = 0;
    EMSTATUS result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((S8*) entry, (S8*) & mmi_frm_sms_awaited[index], sizeof(mmi_frm_sms_deliver_msg_struct));

    for (i = 0; i < 10; i++)
    {
        TPUDLEN[i] = 0;
        TPUD[i] = NULL;
    }
    i = 0;
    while (nextindex != MMI_FRM_SMS_INVALID_NUM && i < 10)
    {
        totalseg = i + 1;   /* total segment that the TPUD is not NULL */
        TPUDLEN[i] = (U8) mmi_frm_sms_content[nextindex].msglen;
        TPUD[i] = (U8*) mmi_frm_sms_content[nextindex].data;
        nextindex = mmi_frm_sms_content[nextindex].nextindex;
        i++;
    }
    if (mmi_frm_sms_awaited[index].dcs == SMSAL_DEFAULT_DCS || mmi_frm_sms_awaited[index].dcs == SMSAL_8BIT_DCS)
    {
        buffLen *= 2;
    }
    if (buffLen)
    {
        pEMSdata = OslMalloc(sizeof(EMSData));
        /* MMI could only allocate 2K control buffer, so limit the max allocate buffer to 1600 here */
        buffLen = (buffLen < (MMI_FRM_SMS_MSG_LEN * 10)) ? buffLen : (MMI_FRM_SMS_MSG_LEN * 10);
        textBuff = OslMalloc(buffLen);
        result = EMSMsgPreview(
                    totalseg,
                    mmi_frm_sms_awaited[index].dcs,
                    (U8) GetUDHIBit(mmi_frm_sms_awaited[index].fo),
                    TPUD,
                    TPUDLEN,
                    buffLen,
                    textBuff,
                    &is_obj_present,
                    &textLen);

        if (result == EMS_OK)
        {
            pEMSdata->textBuffer = textBuff;
            pEMSdata->textBufferSize = mmi_frm_sms_awaited[index].no_msg_data;
            pEMSdata->textLength = textLen;
            pEMSdata->dcs = mmi_frm_sms_awaited[index].dcs;

            EMS_ConvertGSM7BitDefaultEncodingToAsciiWithoutEMSlib(pEMSdata);
            entry->no_msg_data = pEMSdata->textLength;

            if (mmi_frm_sms_awaited[index].dcs == SMSAL_UCS2_DCS)
            {
                memcpy((S8*) content, (S8*) pEMSdata->textBuffer, pEMSdata->textLength);
            }
            else
            {
                S8 *pOutBuffer = (S8*) content;
                S8 *pInBuffer = (S8*) pEMSdata->textBuffer;
                U32 len = pEMSdata->textLength;

                /* 34.2.5.1 test case contains a null terminator in the message content but actually it is not the end of the message */
                /* mmi_ucs2_n_to_asc((S8*)content, (S8*)pEMSdata->textBuffer, pEMSdata->textLength); */
                while (len)
                {
                    *pOutBuffer = *(pInBuffer);
                    pInBuffer += 2;
                    pOutBuffer++;
                    len -= 2;
                }
            }
        }
        else
        {
            entry->no_msg_data = 0;
            memset((S8*) content, 0, ENCODING_LENGTH);
        }

        OslMfree(textBuff);
        OslMfree(pEMSdata);
    }
    else
    {
        memset((S8*) content, 0, ENCODING_LENGTH);
    }

    return is_obj_present;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_awaited_complete
 * DESCRIPTION
 *  Check awaited message completeness
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_sms_check_awaited_complete(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_frm_sms_concat_struct *concat_info = (mmi_frm_sms_concat_struct*) & (mmi_frm_sms_awaited[index].concat_info);
    U8 total_seg = ((concat_info->total_seg - concat_info->seg + 1) > g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) ?
        g_frm_sms_cntx.mmi_frm_sms_msg_seg_size : (concat_info->total_seg - concat_info->seg + 1);
    U8 dataindex = mmi_frm_sms_awaited[index].msg_data[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the message has only one segment */
    if (index == MMI_FRM_SMS_ACTION_SIZE)
    {
        return TRUE;
    }
    while (dataindex != MMI_FRM_SMS_INVALID_NUM)
    {
        /* if mmi_frm_sms_content is full */
        if (dataindex == MMI_FRM_SMS_MSG_CONTENT_NUM)
        {
            return TRUE;
        }
        if (mmi_frm_sms_content[dataindex].segment != (i + 1))
        {
            return FALSE;
        }
        dataindex = mmi_frm_sms_content[dataindex].nextindex;
        i++;
    }
    if (i == total_seg)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_awaited_complete_msg
 * DESCRIPTION
 *  Check awaited message completeness , excluding mmi_frm_sms_content full
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_sms_check_awaited_complete_msg(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_frm_sms_concat_struct *concat_info = (mmi_frm_sms_concat_struct*) & (mmi_frm_sms_awaited[index].concat_info);
    U8 total_seg = ((concat_info->total_seg - concat_info->seg + 1) > g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) ?
        g_frm_sms_cntx.mmi_frm_sms_msg_seg_size : (concat_info->total_seg - concat_info->seg + 1);
    U8 dataindex = mmi_frm_sms_awaited[index].msg_data[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (dataindex != MMI_FRM_SMS_INVALID_NUM)
    {
        if (mmi_frm_sms_content[dataindex].segment != (i + 1))
        {
            return FALSE;
        }
        dataindex = mmi_frm_sms_content[dataindex].nextindex;
        i++;
    }
    if (i == total_seg)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_awaited
 * DESCRIPTION
 *  Check awaited entry, see if any match
 * PARAMETERS
 *  void
 * RETURNS
 *  index
 *****************************************************************************/
U8 mmi_frm_sms_check_awaited(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* find the entry in the awaited list that matches the last entry in the mmi_frm_sms_awaited  */
    U8 i = 0;
    mmi_frm_sms_deliver_msg_struct *datainfo = &mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE];
    mmi_frm_sms_concat_struct *concatinfo =
        ((mmi_frm_sms_concat_struct*) & (mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].concat_info));
    U8 thisseg = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].segment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((concatinfo->total_seg % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) == 1) &&
        (concatinfo->total_seg == concatinfo->seg))
    {
        return MMI_FRM_SMS_ACTION_SIZE;
    }

    while (i < MMI_FRM_SMS_ACTION_SIZE)
    {
        mmi_frm_sms_deliver_msg_struct *data = &mmi_frm_sms_awaited[i];
        mmi_frm_sms_concat_struct *concat = ((mmi_frm_sms_concat_struct*) & (mmi_frm_sms_awaited[i].concat_info));

#ifndef __MMI_DUAL_SIM_MASTER__
        if ((data->display_type == datainfo->display_type) && (concat->total_seg == concatinfo->total_seg) &&
            (concat->seg == concatinfo->seg) && (concat->ref == concatinfo->ref) &&
            ((ComparePhoneNum((PU8) data->addr_number.number, (PU8) datainfo->addr_number.number)) == TRUE))
#else /* __MMI_DUAL_SIM_MASTER__ */
        if ((data->display_type == datainfo->display_type) && (concat->total_seg == concatinfo->total_seg) &&
            (concat->seg == concatinfo->seg) && (concat->ref == concatinfo->ref) &&
            ((ComparePhoneNum((PU8) data->addr_number.number, (PU8) datainfo->addr_number.number)) == TRUE) &&
            MTPNP_AD_Index_IsSame_Part(data->index, datainfo->index))
#endif /* __MMI_DUAL_SIM_MASTER__ */
        {
            U8 j = mmi_frm_sms_awaited[i].msg_data[0];

            while (j != MMI_FRM_SMS_INVALID_NUM)
            {
                /* find exactly the same entry in the awaited list as the last entry */
                if (mmi_frm_sms_content[j].segment == thisseg)
                {
                    break;
                }
                /* thisseg is smaller than the current smallest segment number of this message */
                else if (mmi_frm_sms_content[j].segment > thisseg)
                {
                #ifdef __MMI_MESSAGES_COPY__
                    if (mmi_frm_sms_awaited[i].storageType != MMI_FRM_SMS_PREFER_STORAGE)
                    {
                        mmi_frm_sms_awaited[i].storageType = datainfo->storageType;
                    }
                #endif /* __MMI_MESSAGES_COPY__ */ 
                    /* if add awaited segment fail, it will popup arbitrarily, so leave the mmi_frm_sms_indicate_sms to free memory */
                    if (mmi_frm_sms_add_awaited_segment(i, datainfo->index, thisseg, datainfo) == TRUE)
                    {
                        mmi_frm_sms_free_new_sms();
                    }
                    return i;
                }
                /* thisseg is greater than the current largest segment number of this message */
                else if (mmi_frm_sms_content[j].segment < thisseg &&
                         mmi_frm_sms_content[j].nextindex == MMI_FRM_SMS_INVALID_NUM)
                {
                #ifdef __MMI_MESSAGES_COPY__
                    if (mmi_frm_sms_awaited[i].storageType != MMI_FRM_SMS_PREFER_STORAGE)
                    {
                        mmi_frm_sms_awaited[i].storageType = datainfo->storageType;
                    }
                #endif /* __MMI_MESSAGES_COPY__ */ 
                    /* if add awaited segment fail, it will popup arbitrarily, so leave the mmi_frm_sms_indicate_sms to free memory */
                    if (mmi_frm_sms_add_awaited_segment(i, datainfo->index, thisseg, datainfo) == TRUE)
                    {
                        mmi_frm_sms_free_new_sms();
                    }
                    return i;
                }
                j = mmi_frm_sms_content[j].nextindex;
            }
        }
        i++;
    }
    return MMI_FRM_SMS_INVALID_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_inbox
 * DESCRIPTION
 *  Check inbox, see if any match
 * PARAMETERS
 *  entry           [?]         Message entry info
 *  thissegment     [IN]        Segment
 * RETURNS
 *  index
 *****************************************************************************/
U16 mmi_frm_sms_check_inbox(mmi_frm_sms_msgbox_struct *entry, U8 thissegment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < g_frm_sms_cntx.mmi_frm_sms_msg_box_size)
    {
        if (mmi_frm_sms_compare_entry(i, entry, thissegment) == TRUE)
        {
            return i;
        }
        i++;
    }
    return MMI_FRM_SMS_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_timeout_concatenate_sms
 * DESCRIPTION
 *  timeout check concatenate SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_timeout_concatenate_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 awaited_remain = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < MMI_FRM_SMS_ACTION_SIZE)
    {
        if (mmi_frm_sms_awaited_counter[i] != MMI_FRM_SMS_INVALID_NUM)
        {
            mmi_frm_sms_awaited_counter[i]++;
            if (mmi_frm_sms_awaited_counter[i] == MMI_FRM_SMS_ACTION_SIZE)
            {
                mmi_frm_sms_awaited_counter[i] = MMI_FRM_SMS_INVALID_NUM;
                mmi_frm_sms_indicate_sms(i);
            }
            else
            {
                awaited_remain = TRUE;
            }
        }
        i++;
    }
    /* timer expires but still some segments are missing in the mmi_frm_sms_awaited */
    if (awaited_remain == TRUE)
    {
        StartTimer(MESSAGES_LMS_RECV_TIMER_ID, MMI_FRM_SMS_LMS_TIME_OUT, mmi_frm_sms_timeout_concatenate_sms);
    }
    else
    {
        mmi_frm_sms_awaited_counting = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_concatenate_sms
 * DESCRIPTION
 *  Check concatenate SMS in awaited and inbox list
 * PARAMETERS
 *  index       [?]     Index
 * RETURNS
 *  type
 *****************************************************************************/
U8 mmi_frm_sms_check_concatenate_sms(U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_concat_struct *concatinfo =
        (mmi_frm_sms_concat_struct*) & (mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].concat_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((concatinfo->total_seg % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) == 1) &&
        (concatinfo->total_seg == concatinfo->seg))
    {
        *index = MMI_FRM_SMS_ACTION_SIZE;
        return MMI_FRM_SMS_AWAITS;
    }
    else
    {
        U8 awaited_index = mmi_frm_sms_check_awaited();

        /* the last entry in the mmi_frm_sms_awaited belongs to one of the segments of the entry with index awaited_index in the awaited list */
        if (awaited_index != MMI_FRM_SMS_INVALID_NUM)
        {
            if (mmi_frm_sms_check_awaited_complete(awaited_index) == TRUE)
            {
                mmi_frm_sms_awaited_counter[awaited_index] = MMI_FRM_SMS_INVALID_NUM;
                *index = awaited_index;
                return MMI_FRM_SMS_AWAITS;
            }
            /* not all segments of this message are arrived, restart the counter to keep waiting for other segment's arriving */
            else
            {
                mmi_frm_sms_awaited_counter[awaited_index] = 0;
                *index = awaited_index;
                return MMI_FRM_SMS_NOBOX;
            }
        }
        /* the last entry in the mmi_frm_sms_awaited matches nothing with other entries in the awaited list */
        else if ((mmi_frm_sms_list_done
			#ifdef __MMI_DUAL_SIM_MASTER__
				&& mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
				|| ( MTPNP_AD_Card2_SMS_Is_Load_Finished() 
				&& mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].index >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox()
			#endif
			))
        {
            U16 inbox_index;
            mmi_frm_sms_msgbox_struct *entry = OslMalloc(sizeof(mmi_frm_sms_msgbox_struct));
            U8 thissegment = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].segment;

            mmi_frm_sms_convert_mt_to_entry(&(mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE]), entry);
            inbox_index = mmi_frm_sms_check_inbox(entry, thissegment);
            OslMfree(entry);

            /* the last entry in the mmi_frm_sms_awaited belongs to one of the segments of the entry with index inbox_index in the inbox list */
            if (inbox_index != MMI_FRM_SMS_INVALID_INDEX)
            {
            #ifdef __MMI_UNIFIED_MESSAGE__
                {
                    mmi_frm_sms_deliver_msg_struct *data = OslMalloc(sizeof(mmi_frm_sms_deliver_msg_struct));

                    /* MMI could only allocate 2K control buffer, so limit the max allocate buffer to 1600 here */
                    U16 content_len =
                        ((MMI_FRM_SMS_MSG_LEN * g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) < (MMI_FRM_SMS_MSG_LEN * 10)) ? 
                        (MMI_FRM_SMS_MSG_LEN * g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) : (MMI_FRM_SMS_MSG_LEN * 10);
                    
                    U8 *content = OslMalloc(content_len);
                    U8 withobject;
                    U8 new_segment_index = MMI_FRM_SMS_ACTION_SIZE;
                    U8 *ucs2_content = NULL;
                    U16 ucs2_content_len = 0;

                    memset(content, 0x00, content_len);
                    withobject = mmi_frm_sms_get_awaited_sms((U8) new_segment_index, data, content);

                    ucs2_content_len = ((mmi_msg_get_max_content_size() + 1) * ENCODING_LENGTH);
                    ucs2_content = OslMalloc(ucs2_content_len);
                    memset(ucs2_content, 0, ucs2_content_len);
                    
                    if (data->dcs == SMSAL_UCS2_DCS)
                    {
                        if (mmi_ucs2strlen((S8*) content))
                        {
                            mmi_ucs2ncpy(
                                (S8*) ucs2_content,
                                (S8*) content,
                                mmi_msg_get_max_content_size());
                        }                        
                    }
                    else
                    {
                        if (strlen((S8*) content))
                        {
                            mmi_asc_n_to_ucs2((S8*) ucs2_content, (S8*) content, (U32) mmi_msg_get_max_content_size());
                        }
                    }

                    if (mmi_ucs2strlen((S8*) ucs2_content) > 0)
                    {
                        if (mmi_frm_sms_index_list[mmi_frm_sms_msg_box[inbox_index].startindex].segment == thissegment - 1)
                        {
                            if (mmi_ucs2strlen((S8*) mmi_frm_sms_msg_box[inbox_index].content) <
                                (mmi_msg_get_max_content_size() - 1))
                            {
                                /* append content to mmi_frm_sms_msg_box[addindex].content */
                                U16 *temp_content;
                                U16 temp_content_size = (U16) (mmi_msg_get_max_content_size() + 1) * ENCODING_LENGTH;
                    
                                temp_content = OslMalloc(temp_content_size);
                                memset((S8*) temp_content, 0, temp_content_size);
                                mmi_ucs2ncpy(
                                    (S8*) temp_content,
                                    (S8*) mmi_frm_sms_msg_box[inbox_index].content,
                                    mmi_msg_get_max_content_size());
                                
                                mmi_ucs2ncat(
                                    (S8*) temp_content,
                                    (S8*) ucs2_content,
                                    (mmi_msg_get_max_content_size() - mmi_ucs2strlen((S8*) temp_content)));
                    
                                mmi_frm_sms_add_content_to_entry(
                                    (mmi_frm_sms_msgbox_struct*) & mmi_frm_sms_msg_box[inbox_index],
                                    (U8*) temp_content);
                    
                                OslMfree(temp_content);                        
                            }
                        }
                        else if (mmi_frm_sms_index_list[mmi_frm_sms_msg_box[inbox_index].startindex].segment == thissegment + 1)
                        {
                            /* copy data->content to the beginning of  mmi_frm_sms_msg_box[addindex].content */
                            U16 *temp_content;
                            U16 temp_content_size = (U16) (mmi_msg_get_max_content_size() + 1) * ENCODING_LENGTH;
                    
                            temp_content = OslMalloc(temp_content_size);
                            memset((S8*) temp_content, 0, temp_content_size);
                            mmi_ucs2ncpy((S8*) temp_content, (S8*) ucs2_content, mmi_msg_get_max_content_size());
                    
                            if (mmi_msg_get_max_content_size() > mmi_ucs2strlen((S8*) temp_content))
                            {
                                mmi_ucs2ncat(
                                    (S8*) temp_content,
                                    (S8*) mmi_frm_sms_msg_box[inbox_index].content,
                                    (mmi_msg_get_max_content_size() - mmi_ucs2strlen((S8*) temp_content)));
                            }
                    
                            mmi_frm_sms_add_content_to_entry(
                                (mmi_frm_sms_msgbox_struct*) & mmi_frm_sms_msg_box[inbox_index],
                                (U8*) temp_content);
                    
                            OslMfree(temp_content);
                        }
                        else if (mmi_frm_sms_index_list[mmi_frm_sms_msg_box[inbox_index].startindex].segment > thissegment)
                        {
                            mmi_frm_sms_add_content_to_entry(
                                (mmi_frm_sms_msgbox_struct*) & mmi_frm_sms_msg_box[inbox_index],
                                (U8*) ucs2_content);
                        }
                        else
                        {
                            /* thissegment > start_segment + 1 */
                            /* If thissegment is the last segment of received segments, append the content */
                            if (mmi_ucs2strlen((S8*) mmi_frm_sms_msg_box[inbox_index].content) <
                                (mmi_msg_get_max_content_size() - 1))
                            {
                                U16 l4_index = mmi_frm_sms_index_list[mmi_frm_sms_msg_box[inbox_index].startindex].nextindex;

                                if (l4_index == MMI_FRM_SMS_INVALID_INDEX)
                                {
                                    /* Do nothing */
                                    ;
                                }
                                else
                                {
                                    for (;;)
                                    {
                                        /* Received segments are continuous */
                                        if (mmi_frm_sms_index_list[l4_index].nextindex == MMI_FRM_SMS_INVALID_INDEX)
                                        {

                                            if ((mmi_frm_sms_index_list[l4_index].segment - 1 ) != 
                                                mmi_frm_sms_index_list[mmi_frm_sms_index_list[l4_index].previndex].segment)
                                            {
                                                /* Do nothing if received segments are not continuous */
                                                break;
                                            }                

                                            /* thissegment is the last segment of received segments */
                                            if (thissegment == (mmi_frm_sms_index_list[l4_index].segment + 1 ))
                                            {
                                                /* append content to mmi_frm_sms_msg_box[addindex].content */
                                                U16 *temp_content;
                                                U16 temp_content_size = (U16) (mmi_msg_get_max_content_size() + 1) * ENCODING_LENGTH;
                                    
                                                temp_content = OslMalloc(temp_content_size);
                                                memset((S8*) temp_content, 0, temp_content_size);
                                                mmi_ucs2ncpy(
                                                    (S8*) temp_content,
                                                    (S8*) mmi_frm_sms_msg_box[inbox_index].content,
                                                    mmi_msg_get_max_content_size());
                                                
                                                mmi_ucs2ncat(
                                                    (S8*) temp_content,
                                                    (S8*) ucs2_content,
                                                    (mmi_msg_get_max_content_size() - mmi_ucs2strlen((S8*) temp_content)));
                                    
                                                mmi_frm_sms_add_content_to_entry(
                                                    (mmi_frm_sms_msgbox_struct*) & mmi_frm_sms_msg_box[inbox_index],
                                                    (U8*) temp_content);
                                    
                                                OslMfree(temp_content);      
                                            }
                                            break;
                                        }   

                                        if ((mmi_frm_sms_index_list[l4_index].segment - 1 ) != 
                                            mmi_frm_sms_index_list[mmi_frm_sms_index_list[l4_index].previndex].segment)
                                        {
                                            /* Do nothing if received segments are not continuous */
                                            break;
                                        } 

                                        l4_index = mmi_frm_sms_index_list[l4_index].nextindex;
                                    }                
                                }
                            }
                        }
                    }
                    
                    OslMfree(data);
                    OslMfree(content);
                    OslMfree(ucs2_content);
                }
            #endif /* __MMI_UNIFIED_MESSAGE__ */ 

                mmi_frm_sms_add_sms_segment(
                    inbox_index,
                    mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].index,
                    thissegment);
            #ifdef __MMI_MESSAGES_COPY__
                if (mmi_frm_sms_msg_box[inbox_index].storageType != MMI_FRM_SMS_PREFER_STORAGE)
                {
                    mmi_frm_sms_msg_box[inbox_index].storageType =
                        mmi_frm_sms_awaited[MMI_FRM_SMS_ACTION_SIZE].storageType;
                }
            #endif /* __MMI_MESSAGES_COPY__ */ 
                mmi_frm_sms_free_new_sms();
                *index = inbox_index;
                return MMI_FRM_SMS_INBOX;
            }
        }
        /* cannot find any match in awaited list and inbox list, add one entry with index awaited_index in the mmi_frm_sms_awaited */
        awaited_index = mmi_frm_sms_add_awaited_entry();
        /* find an empty entry in the awaited list and add successfully */
        if (awaited_index != MMI_FRM_SMS_INVALID_NUM)
        {
            mmi_frm_sms_free_new_sms();
            /* the timer is not started yet */
            if (mmi_frm_sms_awaited_counting == FALSE)
            {
                StartTimer(MESSAGES_LMS_RECV_TIMER_ID, MMI_FRM_SMS_LMS_TIME_OUT, mmi_frm_sms_timeout_concatenate_sms);
                mmi_frm_sms_awaited_counting = TRUE;
            }
            mmi_frm_sms_awaited_counter[awaited_index] = 0;
            *index = MMI_FRM_SMS_INVALID_INDEX;
            return MMI_FRM_SMS_NOBOX;
        }
        /* awaited list is full and the segment should be popup arbitrarily */
        else
        {
            *index = MMI_FRM_SMS_ACTION_SIZE;
            return MMI_FRM_SMS_AWAITS;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_sms_complete
 * DESCRIPTION
 *  Check SMS completeness
 * PARAMETERS
 *  type        [IN]        Type
 *  index       [IN]        Index
 * RETURNS
 *  TRUE: complete, FALSE: not
 *****************************************************************************/
U8 mmi_frm_sms_check_sms_complete(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 total_seg;
    U16 dataindex;
    U16 msgindex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMI_FRM_SMS_ARCHIVE:
			msgindex = mmi_frm_sms_archive_list[index];
			return mmi_frm_sms_archiveIndex_list[msgindex].isComplete;
            break;
#endif
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            msgindex = mmi_frm_sms_inbox_list[index];
            break;
        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
            msgindex = mmi_frm_sms_outbox_list[index];
            break;
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
            msgindex = mmi_frm_sms_drafts_list[index];
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */
    
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            msgindex = mmi_frm_sms_unsent_list[index];
            break;
    #endif /* __MMI_UNIFIED_MESSAGE__ */
    
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            if (mmi_frm_sms_sim_list != NULL)
            {
                msgindex = mmi_frm_sms_sim_list[index];
            }
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        default:
            msgindex = 0;
            break;
    }
    total_seg =
        ((mmi_frm_sms_msg_box[msgindex].totalseg - mmi_frm_sms_msg_box[msgindex].startseg + 1) >
         g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) ? g_frm_sms_cntx.
        mmi_frm_sms_msg_seg_size : (mmi_frm_sms_msg_box[msgindex].totalseg - mmi_frm_sms_msg_box[msgindex].startseg +
                                    1);
    dataindex = mmi_frm_sms_msg_box[msgindex].startindex;
    while (dataindex != MMI_FRM_SMS_INVALID_INDEX)
    {
        if (mmi_frm_sms_index_list[dataindex].segment != (i + 1))
        {
            return FALSE;
        }
        dataindex = mmi_frm_sms_index_list[dataindex].nextindex;
        i++;
    }
    if (i == total_seg)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_data_index
 * DESCRIPTION
 *  get data index of specific source port and module
 * PARAMETERS
 *  mod             [IN]        Port
 *  port            [IN]        
 *  startindex      [IN]        
 * RETURNS
 *  index
 *****************************************************************************/
U8 mmi_frm_sms_get_data_index(module_type mod, U16 port, U8 startindex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = startindex; i < MMI_FRM_SMS_ACTION_SIZE; i++)
    {
        if ((mmi_frm_sms_data[i].dest_mod_id == mod) && (mmi_frm_sms_data[i].dest_port == port))
        {
            return i;
        }
    }
    return MMI_FRM_SMS_INVALID_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_remove_data
 * DESCRIPTION
 *  Remove SMS with port, by module and port
 * PARAMETERS
 *  mod         [IN]        Module
 *  port        [IN]        Port number
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_remove_data(module_type mod, U16 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_FRM_SMS_ACTION_SIZE; i++)
    {
        if ((mmi_frm_sms_data[i].dest_mod_id == mod) && (mmi_frm_sms_data[i].dest_port == port))
        {
            mmi_frm_sms_free_data(i);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_data_segment
 * DESCRIPTION
 *  add one segment to awaited entry
 * PARAMETERS
 *  index       [IN]        Index
 *  segment     [IN]        Segment
 *  entry       [?]         
 *  b  addindex    addindex(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_sms_add_data_segment(U8 index, U8 segment, mmi_frm_sms_deliver_data_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 islast = TRUE;
    U8 dataindex = 0;
    U8 thisdataindex = mmi_frm_sms_data[index].data[0];
    U8 prevdataindex = MMI_FRM_SMS_INVALID_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find an empty entry in mmi_frm_sms_content in order to move the last entry to that entry */
    while (dataindex < MMI_FRM_SMS_MSG_CONTENT_NUM)
    {
        if (mmi_frm_sms_content[dataindex].msglen == 0)
        {
            break;  /* found empty entry */
        }
        dataindex++;
    }
    /* if mmi_frm_sms_content is full and cannot find any empty entry, don't have to move */
    if (dataindex != MMI_FRM_SMS_MSG_CONTENT_NUM)
    {
        /* move the actual data of the last entry to the entry with the index dataindex in mmi_frm_sms_content */
        if (entry->message_len)
        {
            mmi_frm_sms_content[dataindex].data = OslMalloc(entry->message_len);
            memcpy(
                (S8*) mmi_frm_sms_content[dataindex].data,
                (S8*) mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data,
                entry->message_len);
        }
        mmi_frm_sms_content[dataindex].msglen = entry->message_len;
        mmi_frm_sms_content[dataindex].segment = segment;
    }
    mmi_frm_sms_data[index].message_len += entry->message_len;
    MMI_ASSERT(mmi_frm_sms_data[index].message_len <= MMI_SMS_MAX_MSG_SEG * MMI_FRM_SMS_MSG_LEN);

    /* thisdataindex is the current smallest segment index of this message */
    if (mmi_frm_sms_content[thisdataindex].segment > segment)
    {
        islast = FALSE;
        /* dataindex is inserted in the head, now dataindex is the current smallest segment index of this message */
        mmi_frm_sms_content[dataindex].nextindex = thisdataindex;
        mmi_frm_sms_data[index].data[0] = dataindex;
    }
    else
    {
        while (mmi_frm_sms_content[thisdataindex].nextindex != MMI_FRM_SMS_INVALID_NUM)
        {
            prevdataindex = thisdataindex;
            thisdataindex = mmi_frm_sms_content[thisdataindex].nextindex;
            if (mmi_frm_sms_content[thisdataindex].segment > segment)
            {
                islast = FALSE;
                break;
            }
        }
    }

    if (islast == TRUE)
    {
        /* dataindex is inserted in the tail, now dataindex is the current largest segment index of this message */
        mmi_frm_sms_content[thisdataindex].nextindex = dataindex;
        mmi_frm_sms_content[dataindex].nextindex = MMI_FRM_SMS_INVALID_NUM;
    }
    else
    {
        /* dataindex is inserted in the middle */
        if (prevdataindex != MMI_FRM_SMS_INVALID_NUM)
        {
            mmi_frm_sms_content[prevdataindex].nextindex = dataindex;
        }
        mmi_frm_sms_content[dataindex].nextindex = thisdataindex;
    }
    /* mmi_frm_sms_content is full and cannot handle other new segment coming anymore */
    if (dataindex == MMI_FRM_SMS_MSG_CONTENT_NUM)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_data_entry
 * DESCRIPTION
 *  add sms to awaited list
 * PARAMETERS
 *  void
 *  a  type        type(?)
 *  b  index       index(?)
 *  c  l4_index    l4_index(?)
 * RETURNS
 *  TRUE: inserted, FALSE: not inserted
 *****************************************************************************/
U8 mmi_frm_sms_add_data_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 dataindex = 0;
    U16 length = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].msglen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (dataindex < MMI_FRM_SMS_MSG_CONTENT_NUM)
    {
        if (mmi_frm_sms_content[dataindex].segment == MMI_FRM_SMS_INVALID_NUM)
        {
            break;  /* found empty entry */
        }
        dataindex++;
    }
    /* cannot find any empty entry in mmi_frm_sms_content */
    if (dataindex == MMI_FRM_SMS_MSG_CONTENT_NUM)
    {
        return MMI_FRM_SMS_INVALID_NUM;
    }

    mmi_frm_sms_content[dataindex].msglen = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].msglen;
    mmi_frm_sms_content[dataindex].nextindex = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].nextindex;
    mmi_frm_sms_content[dataindex].segment = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].segment;
    /* mmi_frm_sms_content[dataindex].data=mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data;*/
    /* mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data=NULL;*/
    if (length)
    {
        mmi_frm_sms_content[dataindex].data = OslMalloc(length);
        memcpy(mmi_frm_sms_content[dataindex].data, mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].data, length);
    }

    while (i < MMI_FRM_SMS_ACTION_SIZE)
    {
        if (mmi_frm_sms_data[i].data[0] == MMI_FRM_SMS_INVALID_NUM)
        {
            memcpy(
                &(mmi_frm_sms_data[i]),
                &(mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE]),
                sizeof(mmi_frm_sms_deliver_data_struct));
            mmi_frm_sms_data[i].data[0] = dataindex;
            return i;
        }
        i++;
    }
    /* cannot find any empty entry in mmi_frm_sms_data */
    return MMI_FRM_SMS_INVALID_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_data
 * DESCRIPTION
 *  Get SMS with port: get content
 * PARAMETERS
 *  index       [IN]        Index
 *  data        [?]         Entry info
 *  content     [?]         Content
 * RETURNS
 *  TRUE: OK, FALSE: content empty
 *****************************************************************************/
U8 mmi_frm_sms_get_data(U8 index, mmi_frm_sms_deliver_data_struct *data, U8 *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((S8*) data, (S8*) & mmi_frm_sms_data[index], sizeof(mmi_frm_sms_deliver_data_struct));

    if (mmi_frm_sms_data[index].message_len == 0)
    {
        return FALSE;
    }
    
    memset((S8*) content, 0, mmi_frm_sms_data[index].message_len);

    if (mmi_frm_sms_data[index].dcs == SMSAL_UCS2_DCS || mmi_frm_sms_data[index].dcs == SMSAL_DEFAULT_DCS)
    {
        U8 i = mmi_frm_sms_data[index].data[0];
        EMSData *pEMSdata = NULL;
        U8 *textBuff = NULL;
        U8 *textBuffShifted = NULL;
        U8 *TPUD[1];
        U8 TPUDLEN[1];
        U8 is_obj_present = 0;
        U16 buffLen = mmi_frm_sms_data[index].message_len;
        U16 textLen = 0;
        U8 udhi = KAL_FALSE;

        if (mmi_frm_sms_data[index].dcs == SMSAL_DEFAULT_DCS)
        {
            buffLen *= 2;
        }

        if (buffLen)
        {
            pEMSdata = OslMalloc(sizeof(EMSData));
            /* MMI could only allocate 2K control buffer, so limit the max allocate buffer to 1600 here */
            buffLen = (buffLen < (MMI_FRM_SMS_MSG_LEN * 10)) ? buffLen : (MMI_FRM_SMS_MSG_LEN * 10);
            textBuff = OslMalloc(buffLen);
            textBuffShifted = textBuff;

            pEMSdata->textBuffer = textBuff;
            pEMSdata->textBufferSize = buffLen;
            pEMSdata->textLength = 0;
            pEMSdata->dcs = mmi_frm_sms_data[index].dcs;

            while (i != MMI_FRM_SMS_INVALID_NUM)
            {
                TPUDLEN[0] = (U8) mmi_frm_sms_content[i].msglen;
                TPUD[0] = (U8*) mmi_frm_sms_content[i].data;
                EMSMsgPreview(
                    1,
                    mmi_frm_sms_data[index].dcs,
                    udhi,
                    TPUD,
                    TPUDLEN,
                    buffLen,
                    textBuffShifted,
                    &is_obj_present,
                    &textLen);

                pEMSdata->textLength += textLen;
                textBuffShifted += textLen;
                buffLen -= textLen;
                textLen = 0;

                i = mmi_frm_sms_content[i].nextindex;
            }

            EMS_ConvertGSM7BitDefaultEncodingToAsciiWithoutEMSlib(pEMSdata);
            /* mmi_ucs2_n_to_asc((S8*)content, (S8*)pEMSdata->textBuffer, pEMSdata->textBufferSize); */
            memcpy((S8*) content, (S8*) pEMSdata->textBuffer, pEMSdata->textLength);
            data->message_len = pEMSdata->textLength;
            OslMfree(textBuff);
            OslMfree(pEMSdata);
        }
        else
        {
            memset((S8*) content, 0, ENCODING_LENGTH);
        }
        return TRUE;
    }
    else
    {
        U8 i = mmi_frm_sms_data[index].data[0];
        U16 len = 0;

        while (i != MMI_FRM_SMS_INVALID_NUM)
        {
            memcpy(((S8*) content) + len, (S8*) mmi_frm_sms_content[i].data, mmi_frm_sms_content[i].msglen);
            len += mmi_frm_sms_content[i].msglen;
            i = mmi_frm_sms_content[i].nextindex;
        }
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_data
 * DESCRIPTION
 *  Check SMS with port in data list
 * PARAMETERS
 *  void
 * RETURNS
 *  index
 *****************************************************************************/
U8 mmi_frm_sms_check_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* find the entry in the data list that matches the last entry in the mmi_frm_sms_data */
    U8 i = 0;
    mmi_frm_sms_deliver_data_struct *datainfo = &mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE];
    mmi_frm_sms_concat_struct *concatinfo =
        ((mmi_frm_sms_concat_struct*) & (mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].concat_info));
    U8 thisseg = mmi_frm_sms_content[MMI_FRM_SMS_MSG_CONTENT_NUM].segment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((concatinfo->total_seg % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) == 1) &&
        (concatinfo->total_seg == concatinfo->seg))
    {
        return MMI_FRM_SMS_ACTION_SIZE;
    }

    while (i < MMI_FRM_SMS_ACTION_SIZE)
    {
        mmi_frm_sms_deliver_data_struct *data = &mmi_frm_sms_data[i];
        mmi_frm_sms_concat_struct *concat = ((mmi_frm_sms_concat_struct*) & (mmi_frm_sms_data[i].concat_info));

        if ((concat->total_seg == concatinfo->total_seg) && (concat->seg == concatinfo->seg) &&
            (concat->ref == concatinfo->ref) &&
            ((ComparePhoneNum((PU8) data->oa.number, (PU8) datainfo->oa.number)) == TRUE)
        #ifdef __MMI_DUAL_SIM_MASTER__
			 && (data->isSlave == datainfo->isSlave)
		#endif
            )
        {
            U8 j = mmi_frm_sms_data[i].data[0];

            while (j != MMI_FRM_SMS_INVALID_NUM)
            {
                /* find exactly the same entry in the data list as the last entry */
                if (mmi_frm_sms_content[j].segment == thisseg)
                {
                    break;
                }
                /* thisseg is smaller than the current smallest segment number of this message */
                else if (mmi_frm_sms_content[j].segment > thisseg)
                {
                    /* if add data segment fail, the last entry is not duplicated, so it cannot free here */
                    if (mmi_frm_sms_add_data_segment(i, thisseg, datainfo) == TRUE)
                    {
                        mmi_frm_sms_free_new_data();
                    }
                    return i;
                }
                /* thisseg is greater than the current largest segment number of this message */
                else if (mmi_frm_sms_content[j].segment < thisseg &&
                         mmi_frm_sms_content[j].nextindex == MMI_FRM_SMS_INVALID_NUM)
                {
                    /* if add data segment fail, the last entry is not duplicated, so it cannot free here */
                    if (mmi_frm_sms_add_data_segment(i, thisseg, datainfo) == TRUE)
                    {
                        mmi_frm_sms_free_new_data();
                    }
                    return i;
                }
                j = mmi_frm_sms_content[j].nextindex;
            }
        }
        i++;
    }
    return MMI_FRM_SMS_INVALID_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_timeout_concatenate_data
 * DESCRIPTION
 *  timeout check concatenate SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_timeout_concatenate_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 awaited_remain = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < MMI_FRM_SMS_ACTION_SIZE)
    {
        if (mmi_frm_sms_data_counter[i] != MMI_FRM_SMS_INVALID_NUM)
        {
            mmi_frm_sms_data_counter[i]++;

            /* Give twice time for data to be re-assembled. */
            if (mmi_frm_sms_data_counter[i] == MMI_FRM_SMS_ACTION_SIZE * 2)
            {
                mmi_frm_sms_data_counter[i] = MMI_FRM_SMS_INVALID_NUM;
                mmi_frm_sms_free_data(i);
            }
            else
            {
                awaited_remain = TRUE;
            }
        }
        i++;
    }
    /* timer expires but still some segments are missing in the mmi_frm_sms_awaited */
    if (awaited_remain == TRUE)
    {
        StartTimer(MESSAGES_LMS_RECV_TIMER_ID, MMI_FRM_SMS_LMS_TIME_OUT, mmi_frm_sms_timeout_concatenate_data);
    }
    else
    {
        mmi_frm_sms_data_counting = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_concatenate_data
 * DESCRIPTION
 *  Check concatenate data
 * PARAMETERS
 *  index       [?]     Index
 * RETURNS
 *  index
 *****************************************************************************/
U8 mmi_frm_sms_check_concatenate_data(U8 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_concat_struct *concatinfo =
        (mmi_frm_sms_concat_struct*) & (mmi_frm_sms_data[MMI_FRM_SMS_ACTION_SIZE].concat_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((concatinfo->total_seg % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) == 1) &&
        (concatinfo->total_seg == concatinfo->seg))
    {
        *index = MMI_FRM_SMS_ACTION_SIZE;
        return MMI_FRM_SMS_DATA;
    }
    else
    {
        U8 awaited_index = mmi_frm_sms_check_data();

        /* the last entry in the mmi_frm_sms_data belongs to one of the segments of the entry with index awaited_index in the data list */
        if (awaited_index != MMI_FRM_SMS_INVALID_NUM)
        {
            if (mmi_frm_sms_check_data_complete(awaited_index) == TRUE)
            {
                mmi_frm_sms_data_counter[awaited_index] = MMI_FRM_SMS_INVALID_NUM;
                *index = awaited_index;
                return MMI_FRM_SMS_DATA;
            }
            /* not all segments of this message are arrived */
            else
            {
                U8 dataindex = 0;

                /* check if mmi_frm_sms_content is full */
                while (dataindex < MMI_FRM_SMS_MSG_CONTENT_NUM)
                {
                    if (mmi_frm_sms_content[dataindex].segment == MMI_FRM_SMS_INVALID_NUM)
                    {
                        /* mmi_frm_sms_content is not full, restart the counter to keep waiting for other segment's arriving */
                        mmi_frm_sms_data_counter[awaited_index] = 0;
                        *index = awaited_index;
                        return MMI_FRM_SMS_NOBOX;
                    }
                    dataindex++;
                }
                /* mmi_frm_sms_content is full, reset the counter and free this message */
                mmi_frm_sms_data_counter[awaited_index] = MMI_FRM_SMS_INVALID_NUM;
                mmi_frm_sms_free_data(awaited_index);
                *index = awaited_index;
                return MMI_FRM_SMS_NOBOX;
            }
        }
        else
        {
            /* cannot find any match in data list, add one entry with index awaited_index in the mmi_frm_sms_data */
            awaited_index = mmi_frm_sms_add_data_entry();
            /* find an empty entry in the data list and add successfully */
            if (awaited_index != MMI_FRM_SMS_INVALID_NUM)
            {
                mmi_frm_sms_free_new_data();
                /* the timer is not started yet */
                if (mmi_frm_sms_data_counting == FALSE)
                {
                    StartTimer(
                        MESSAGES_LMS_RECV_TIMER_ID,
                        MMI_FRM_SMS_LMS_TIME_OUT,
                        mmi_frm_sms_timeout_concatenate_data);
                    mmi_frm_sms_data_counting = TRUE;
                }
                mmi_frm_sms_data_counter[awaited_index] = 0;
                *index = MMI_FRM_SMS_INVALID_NUM;
                return MMI_FRM_SMS_NOBOX;
            }
            /* data list or content list is full and the segment should be discarded */
            else
            {
                mmi_frm_sms_free_new_data();
                *index = MMI_FRM_SMS_ACTION_SIZE;
                return MMI_FRM_SMS_NOBOX;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_data_complete
 * DESCRIPTION
 *  Check SMS with port completeness
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  TRUE: complete, FALSE: not
 *****************************************************************************/
U8 mmi_frm_sms_check_data_complete(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_frm_sms_concat_struct *concat_info = (mmi_frm_sms_concat_struct*) & (mmi_frm_sms_data[index].concat_info);
    U8 total_seg = ((concat_info->total_seg - concat_info->seg + 1) > g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) ?
        g_frm_sms_cntx.mmi_frm_sms_msg_seg_size : (concat_info->total_seg - concat_info->seg + 1);
    U8 dataindex = mmi_frm_sms_data[index].data[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the message has only one segment */
    if (index == MMI_FRM_SMS_ACTION_SIZE)
    {
        return TRUE;
    }
    while (dataindex != MMI_FRM_SMS_INVALID_NUM)
    {
        if (mmi_frm_sms_content[dataindex].segment != (i + 1))
        {
            return FALSE;
        }
        dataindex = mmi_frm_sms_content[dataindex].nextindex;
        i++;
    }
    if (i == total_seg)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* given msg box index, change to type */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_sms_status
 * DESCRIPTION
 *  Set SMS status
 * PARAMETERS
 *  type        [IN]        Origin type
 *  index       [IN]        Index
 *  newtype     [IN]        Type to be set
 * RETURNS
 * TRUE
 *****************************************************************************/
U8 mmi_frm_sms_set_sms_status(U16 type, U16 index, U8 newtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 mti;
    U16 msgindex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_FRM_SMS_NOBOX:
            msgindex = index;
            mti = (mmi_frm_sms_msg_box[msgindex].msgtype & 0xf000);
            mmi_frm_sms_msg_box[msgindex].msgtype = mti | newtype;
            break;
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            msgindex = mmi_frm_sms_inbox_list[index];
            mti = (mmi_frm_sms_msg_box[msgindex].msgtype & 0xf000);
            mmi_frm_sms_msg_box[msgindex].msgtype = mti | newtype;
            break;
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            if (mmi_frm_sms_sim_list != NULL)
            {
                msgindex = mmi_frm_sms_sim_list[index];
                mti = (mmi_frm_sms_msg_box[msgindex].msgtype & 0xf000);
                if (mmi_frm_sms_msg_box[msgindex].msgtype & MMI_FRM_SMS_UNREAD
                    || mmi_frm_sms_msg_box[msgindex].msgtype & MMI_FRM_SMS_INBOX)
                {
                    mmi_frm_sms_msg_box[msgindex].msgtype = mti | newtype;
                }
                else
                {
                    g_mmi_frm_sms_change_status = FALSE;
                }
            }
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        default:
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*-------[SmsUtil.c] mmi_frm_sms_set_sms_status DO NOTHING -------*\n");
            break;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_status
 * DESCRIPTION
 *  Get SMS status
 * PARAMETERS
 *  type        [IN]        Type
 *  index       [IN]        Index
 * RETURNS
 *  status
 *****************************************************************************/
U16 mmi_frm_sms_get_sms_status(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 entryindex = index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            entryindex = mmi_frm_sms_inbox_list[index];
            break;
        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
            entryindex = mmi_frm_sms_outbox_list[index];
            break;
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
            entryindex = mmi_frm_sms_drafts_list[index];
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            entryindex = mmi_frm_sms_unsent_list[index];
            break;
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMI_FRM_SMS_ARCHIVE:
			return MMI_FRM_SMS_INVALID_NUM;  /*ti's a workaround way. to avoid use L4 layer data. */
			break;
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            if (mmi_frm_sms_sim_list != NULL)
            {
                entryindex = mmi_frm_sms_sim_list[index];
            }
            break;
    #endif/* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
    }
    return mmi_frm_sms_msg_box[entryindex].msgtype;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_dcs
 * DESCRIPTION
 *  Get SMS DCS
 * PARAMETERS
 *  type        [IN]        Type
 *  index       [IN]        Index
 * RETURNS
 *  dcs
 *****************************************************************************/
U8 mmi_frm_sms_get_sms_dcs(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_FRM_SMS_DATA)
    {
        return mmi_frm_sms_data[index].dcs;
    }
    else
    {
        return SMSAL_8BIT_DCS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_address
 * DESCRIPTION
 *  Get SMS address
 * PARAMETERS
 *  type        [IN]        Type
 *  index       [IN]        Index
 * RETURNS
 *  address
 *****************************************************************************/
U8 *mmi_frm_sms_get_sms_address(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 entryindex = index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            entryindex = mmi_frm_sms_inbox_list[index];
            break;
        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
            entryindex = mmi_frm_sms_outbox_list[index];
            break;
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
            entryindex = mmi_frm_sms_drafts_list[index];
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            entryindex = mmi_frm_sms_unsent_list[index];
            break;
    #endif /* __MMI_UNIFIED_MESSAGE__ */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
         case MMI_FRM_SMS_ARCHIVE:
            entryindex = mmi_frm_sms_archive_list[index];
		break;	
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            if (mmi_frm_sms_sim_list != NULL)
            {
                entryindex = mmi_frm_sms_sim_list[index];
            }
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__*/
        default:
            entryindex = index;
            break;
    }
    if (type == MMI_FRM_SMS_DATA)
    {
        return (U8*) & mmi_frm_sms_data[entryindex].oa;
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (type ==  MMI_FRM_SMS_ARCHIVE)
    {
        return  mmi_frm_sms_archiveIndex_list[entryindex].number; 
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    else
    {
        return mmi_frm_sms_msg_box[entryindex].number;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_timestamp
 * DESCRIPTION
 *  Get SMS timestamp
 * PARAMETERS
 *  type        [IN]        Type
 *  index       [IN]        Index
 * RETURNS
 *  timestamp
 *****************************************************************************/
U8 *mmi_frm_sms_get_sms_timestamp(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 entryindex = index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            entryindex = mmi_frm_sms_inbox_list[index];
            break;
        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
            entryindex = mmi_frm_sms_outbox_list[index];
            break;
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
            entryindex = mmi_frm_sms_drafts_list[index];
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            entryindex = mmi_frm_sms_unsent_list[index];
            break;
    #endif /* __MMI_UNIFIED_MESSAGE__ */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMI_FRM_SMS_ARCHIVE:
            entryindex = mmi_frm_sms_archive_list[index];
            break; 
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            if (mmi_frm_sms_sim_list != NULL)
            {
                entryindex = mmi_frm_sms_sim_list[index];
            }
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
    }
    if (type == MMI_FRM_SMS_DATA)
    {
        return mmi_frm_sms_data[entryindex].scts;
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (type ==  MMI_FRM_SMS_ARCHIVE)
    {
        return mmi_frm_sms_archiveIndex_list[entryindex].timestamp;
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    else
    {
        return mmi_frm_sms_msg_box[entryindex].timestamp;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_size
 * DESCRIPTION
 *  Get SMS size
 * PARAMETERS
 *  type        [IN]        Type
 *  index       [IN]        Index
 * RETURNS
 *  size
 *****************************************************************************/
U8 mmi_frm_sms_get_sms_size(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msgindex = 0;
    U8 totalseg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_FRM_SMS_NOBOX:
            msgindex = index;
            break;

        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            msgindex = mmi_frm_sms_inbox_list[index];
            break;

        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
            msgindex = mmi_frm_sms_outbox_list[index];
            break;

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
            msgindex = mmi_frm_sms_drafts_list[index];
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            msgindex = mmi_frm_sms_unsent_list[index];
            break;
    #endif /* __MMI_UNIFIED_MESSAGE__ */     
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            if (mmi_frm_sms_sim_list != NULL)
            {
                msgindex = mmi_frm_sms_sim_list[index];
            }
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */     
    }
    totalseg = mmi_frm_sms_msg_box[msgindex].totalseg - mmi_frm_sms_msg_box[msgindex].startseg + 1;
    return ((totalseg > g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) ? g_frm_sms_cntx.mmi_frm_sms_msg_seg_size : totalseg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_received_size
 * DESCRIPTION
 *  Get SMS received segment number
 * PARAMETERS
 *  type        [IN]        Type
 *  index       [IN]        Index
 * RETURNS
 *  size
 *****************************************************************************/
U8 mmi_frm_sms_get_sms_received_size(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msgindex = 0;
    U8 receivedseg = 0;
    unsigned short l4index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_FRM_SMS_NOBOX:
            msgindex = index;
            break;

        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            msgindex = mmi_frm_sms_inbox_list[index];
            break;

        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
            msgindex = mmi_frm_sms_outbox_list[index];
            break;

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
            msgindex = mmi_frm_sms_drafts_list[index];
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            msgindex = mmi_frm_sms_unsent_list[index];
            break;
    #endif /* __MMI_UNIFIED_MESSAGE__ */
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            if (mmi_frm_sms_sim_list != NULL)
            {
                msgindex = mmi_frm_sms_sim_list[index];
            }
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
    }

    l4index = mmi_frm_sms_msg_box[msgindex].startindex;
    while (l4index != MMI_FRM_SMS_INVALID_INDEX)
    {
        receivedseg++;
        l4index = mmi_frm_sms_index_list[l4index].nextindex;
    }
    return receivedseg;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_list_size
 * DESCRIPTION
 *  Get SMS list size
 * PARAMETERS
 *  type        [IN]        Type
 * RETURNS
 *  size
 *****************************************************************************/
U16 mmi_frm_sms_get_sms_list_size(U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_list_done == FALSE || g_frm_sms_cntx.mmi_frm_sms_ready == FALSE
	#ifdef __MMI_DUAL_SIM_MASTER__
		|| (!MTPNP_AD_Card2_SMS_Is_Load_Finished())
	#endif
		)
    {
        return MMI_FRM_SMS_INVALID_INDEX;
    }
    switch (type)
    {
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            return mmi_frm_sms_inbox_size;
        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
            return mmi_frm_sms_outbox_size;
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
            return mmi_frm_sms_drafts_size;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            return mmi_frm_sms_unsent_size;
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMI_FRM_SMS_ARCHIVE:
        {
            return mmi_frm_sms_archive_size;
        }
#endif

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            return mmi_frm_sms_simbox_size;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
    
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_data_check
 * DESCRIPTION
 *  See if data is checked
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  Check or not
 *****************************************************************************/
U8 mmi_frm_sms_get_data_check(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_frm_sms_data_checked >> index) & 0x01;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_data_check
 * DESCRIPTION
 *  Set SMS check
 * PARAMETERS
 *  index       [IN]        Index
 *  set         [IN]        1/0
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_data_check(U8 index, U8 set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 resetVector = (U16) (0xffff - (1 << index));
    U16 setVector = (U16) set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setVector = setVector << index;

    /* Reset the check bit to zero  */
    mmi_frm_sms_data_checked &= resetVector;

    mmi_frm_sms_data_checked |= setVector;
}

#ifdef __MMI_MESSAGES_COPY__


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms_storage
 * DESCRIPTION
 *  get SMS storage type
 * PARAMETERS
 *  type        [IN]        mmi_frm_sms_app_msgbox_enum
 *  index       [IN]        message list index
 * RETURNS
 *  smsal_storage_enum (SMSAL_SM or SMSAL_ME)
 *****************************************************************************/
U8 mmi_frm_sms_get_sms_storage(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msgindex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_FRM_SMS_NOBOX:
            msgindex = index;
            break;

        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            msgindex = mmi_frm_sms_inbox_list[index];
            break;

        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
            msgindex = mmi_frm_sms_outbox_list[index];
            break;

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
            msgindex = mmi_frm_sms_drafts_list[index];
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            msgindex = mmi_frm_sms_unsent_list[index];
            break;
    #endif /* __MMI_UNIFIED_MESSAGE__ */
    
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            return SMSAL_SM;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    }

    return mmi_frm_sms_msg_box[msgindex].storageType;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_copy_sms_abort
 * DESCRIPTION
 *  abort SMS copy action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_copy_sms_abort()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_frm_sms_copy_info.is_aborted = TRUE;
    return;
}
#endif /* __MMI_MESSAGES_COPY__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_swap_list_index
 * DESCRIPTION
 *  swap list index
 * PARAMETERS
 *  type        [IN]        mmi_frm_sms_app_msgbox_enum, only inbox, outbox or draft
 *  index1      [IN]        
 *  index2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_swap_list_index(U16 type, U16 index1, U16 index2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msgindex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            msgindex = mmi_frm_sms_inbox_list[index1];
            mmi_frm_sms_inbox_list[index1] = mmi_frm_sms_inbox_list[index2];
            mmi_frm_sms_inbox_list[index2] = msgindex;
            break;

        case MMI_FRM_SMS_OUTBOX:
    #ifndef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
    #endif 
            msgindex = mmi_frm_sms_outbox_list[index1];
            mmi_frm_sms_outbox_list[index1] = mmi_frm_sms_outbox_list[index2];
            mmi_frm_sms_outbox_list[index2] = msgindex;
            break;

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case MMI_FRM_SMS_DRAFTS:
            msgindex = mmi_frm_sms_drafts_list[index1];
            mmi_frm_sms_drafts_list[index1] = mmi_frm_sms_drafts_list[index2];
            mmi_frm_sms_drafts_list[index2] = msgindex;
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            msgindex = mmi_frm_sms_unsent_list[index1];
            mmi_frm_sms_unsent_list[index1] = mmi_frm_sms_unsent_list[index2];
            mmi_frm_sms_unsent_list[index2] = msgindex;
            break;
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        default:
            return;
    }

    return;
}

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_delivery_report_awaited_check
 * DESCRIPTION
 *  set check bit of msg box in delivery report list
 * PARAMETERS
 *  delivery_report_awaited_index       [IN]        
 *  msg_ref                             [IN]        
 *  status_type                         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_delivery_report_awaited_check(U16 delivery_report_awaited_index, U8 msg_ref, U8 status_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_index = delivery_report_awaited_index;
    U8 mr = msg_ref;
    U8 st = status_type;
    int i = 0;
    mmi_frm_sms_delivery_report_box_struct *box = mmi_frm_sms_delivery_report_awaited[list_index].ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (st != ST_COMP_MSG_RECV_BY_SME)
    {
        mmi_frm_sms_delivery_report_awaited[list_index].result = st;
    }

    for (i = 0; i < mmi_frm_sms_delivery_report_awaited[list_index].box_number; i++)
    {
        if (box[i].mr == mr)
        {
            box[i].check_bit = 1;
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_delivery_report_awaited_mr
 * DESCRIPTION
 *  set message reference of msg box in delivery report list
 * PARAMETERS
 *  delivery_report_awaited_index       [IN]        
 *  msg_ref                             [IN]        
 *  seq_number                          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_delivery_report_awaited_mr(U16 delivery_report_awaited_index, U8 msg_ref, U8 seq_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mr = msg_ref;
    U8 seq_no = seq_number;
    U16 list_index = delivery_report_awaited_index;
    mmi_frm_sms_delivery_report_box_struct *box;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (seq_no < mmi_frm_sms_delivery_report_awaited[list_index].box_number)
    {
        box = mmi_frm_sms_delivery_report_awaited[list_index].ptr;
        box[seq_no].mr = mr;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_delivery_report_awaited_complete
 * DESCRIPTION
 *  check if entry of delivery report awaited list is complete
 * PARAMETERS
 *  delivery_report_awaited_index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_frm_sms_check_delivery_report_awaited_complete(U16 delivery_report_awaited_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_index = delivery_report_awaited_index;
    int i = 0;
    mmi_frm_sms_delivery_report_box_struct *box = mmi_frm_sms_delivery_report_awaited[list_index].ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_frm_sms_delivery_report_awaited[list_index].box_number; i++)
    {
        if (box[i].check_bit == 0)
        {
            return FALSE;
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_remove_delivery_report_awaited
 * DESCRIPTION
 *  remove delivery report list entry with the specified list index
 * PARAMETERS
 *  delivery_report_awaited_list_index      [IN]        
 * RETURNS
 *  index of delivery_report_awaited list(?)
 *  MMI_FRM_SMS_ACTION_SIZE means not found(?)
 *****************************************************************************/
void mmi_frm_sms_remove_delivery_report_awaited(U16 delivery_report_awaited_list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_index = delivery_report_awaited_list_index;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_delivery_report_awaited[list_index].result = 0;
    mmi_frm_sms_delivery_report_awaited[list_index].ref = 0;
    mmi_frm_sms_delivery_report_awaited[list_index].box_number = 0;
    if (mmi_frm_sms_delivery_report_awaited[list_index].ptr != NULL)
    {
        OslMfree(mmi_frm_sms_delivery_report_awaited[list_index].ptr);
        mmi_frm_sms_delivery_report_awaited[list_index].ptr = NULL;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_delivery_report_index_by_mr
 * DESCRIPTION
 *  check if delivery report box with the specified message reference already in list
 * PARAMETERS
 *  mr      [IN]        
 * RETURNS
 *  index of delivery_report_awaited list
 *  MMI_FRM_SMS_ACTION_SIZE means not found
 *****************************************************************************/
U16 mmi_frm_sms_get_delivery_report_index_by_mr(U8 mr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg_reference = mr;
    int list_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (list_index = 0; list_index < MMI_FRM_SMS_ACTION_SIZE; list_index++)
    {
        if (mmi_frm_sms_delivery_report_awaited[list_index].box_number != 0)
        {
            int box_no = mmi_frm_sms_delivery_report_awaited[list_index].box_number;
            int box_index = 0;
            mmi_frm_sms_delivery_report_box_struct *box = mmi_frm_sms_delivery_report_awaited[list_index].ptr;

            for (box_index = 0; box_index < box_no; box_index++)
            {
                if (box[box_index].mr == msg_reference)
                {
                    return list_index;
                }
            }
        }
    }

    return list_index;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_delivery_report_index_by_ref
 * DESCRIPTION
 *  check if delivery report entry with the specified reference number already in list
 * PARAMETERS
 *  ref     [IN]        
 * RETURNS
 *  index of delivery_report_awaited list
 *  MMI_FRM_SMS_ACTION_SIZE means not found
 *****************************************************************************/
U16 mmi_frm_sms_get_delivery_report_index_by_ref(U16 ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 reference_no = ref;
    int list_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (list_index = 0; list_index < MMI_FRM_SMS_ACTION_SIZE; list_index++)
    {
        if (mmi_frm_sms_delivery_report_awaited[list_index].box_number != 0)
        {
            if (mmi_frm_sms_delivery_report_awaited[list_index].ref == reference_no)
            {
                return list_index;
            }
        }
    }

    return list_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_delivery_report_awaited
 * DESCRIPTION
 *  add entry to delivery report awaited list
 * PARAMETERS
 *  reference_number        [IN]        
 *  total_segment           [IN]        
 *  index                   [IN]        
 *  mr                      [IN]        
 * RETURNS
 *  ref         : reference number(?)
 *  total_segment  : number of total segments(?)
 *  index : segment number -1(?)
 *  mr    : message reference(?)
 *****************************************************************************/
void mmi_frm_sms_add_delivery_report_awaited(U16 reference_number, U8 total_segment, U8 index, U8 mr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ref_no = reference_number;
    U8 total_seg = total_segment;
    U8 box_index = index;
    U8 msg_reference = mr;
    mmi_frm_sms_delivery_report_box_struct *box;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_delivery_report_awaited[mmi_frm_sms_delivery_report_awaited_next_available].box_number != 0)
    {
        mmi_frm_sms_remove_delivery_report_awaited(mmi_frm_sms_delivery_report_awaited_next_available);
    }

    mmi_frm_sms_delivery_report_awaited[mmi_frm_sms_delivery_report_awaited_next_available].ref = ref_no;
    mmi_frm_sms_delivery_report_awaited[mmi_frm_sms_delivery_report_awaited_next_available].box_number = total_seg;
    mmi_frm_sms_delivery_report_awaited[mmi_frm_sms_delivery_report_awaited_next_available].result =
        ST_COMP_MSG_RECV_BY_SME;
    mmi_frm_sms_delivery_report_awaited[mmi_frm_sms_delivery_report_awaited_next_available].ptr = OslMalloc(total_seg * sizeof(mmi_frm_sms_delivery_report_box_struct));
    memset(
        (S8*) mmi_frm_sms_delivery_report_awaited[mmi_frm_sms_delivery_report_awaited_next_available].ptr,
        0,
        total_seg * sizeof(mmi_frm_sms_delivery_report_box_struct));
    box = mmi_frm_sms_delivery_report_awaited[mmi_frm_sms_delivery_report_awaited_next_available].ptr;
    box[box_index].mr = msg_reference;

    mmi_frm_sms_delivery_report_awaited_next_available++;

    if (mmi_frm_sms_delivery_report_awaited_next_available == MMI_FRM_SMS_ACTION_SIZE)
    {
        mmi_frm_sms_delivery_report_awaited_next_available = 0;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_delivery_report_awaited_result
 * DESCRIPTION
 *  get result of delivery report awaited list entry
 * PARAMETERS
 *  delivery_report_awaited_index       [IN]        
 * RETURNS
 *  delivery_report_awaited_index : index of delivery report list
 *****************************************************************************/
U8 mmi_frm_sms_get_delivery_report_awaited_result(U16 delivery_report_awaited_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_sms_delivery_report_awaited[delivery_report_awaited_index].result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_delivery_report_awaited
 * DESCRIPTION
 *  entry of check delivery report awaited list
 * PARAMETERS
 *  result            [?]
 *  concat_info       [?]     
 *  msg_mr            [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_check_delivery_report_awaited(BOOL result, smsal_concat_struct	concat_info, U8 msg_mr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 delivery_report_awaited_index;
    U16 ref = concat_info.ref;
    U8 msg_reference = msg_mr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == TRUE) /* success */
    {

        /* check if mr is in delivery report awaited list */
        delivery_report_awaited_index = mmi_frm_sms_get_delivery_report_index_by_mr(msg_reference);

        /* mr is in delivery report  awaited list */
        while (delivery_report_awaited_index != MMI_FRM_SMS_ACTION_SIZE)
        {
            mmi_frm_sms_remove_delivery_report_awaited(delivery_report_awaited_index);

            /* check if mr is in delivery report awaited list */
            delivery_report_awaited_index = mmi_frm_sms_get_delivery_report_index_by_mr(msg_reference);
        }

        /* Single-segment msg is always added into awaited list.  Ref of single-segment msg is always zero. */
        if (concat_info.total_seg == 1)
        {
            delivery_report_awaited_index = MMI_FRM_SMS_ACTION_SIZE;
        }
        else
        {
            delivery_report_awaited_index = mmi_frm_sms_get_delivery_report_index_by_ref(ref);
        }

        /* reference number not in awaited list, add an entry to delivery report awaited list */
        if (delivery_report_awaited_index == MMI_FRM_SMS_ACTION_SIZE)
        {
            U8 total_seg = concat_info.total_seg;
            U8 box_index = concat_info.seg - 1; /* start from 0 */

            /* add entry to delivery report awaited list */
            mmi_frm_sms_add_delivery_report_awaited(ref, total_seg, box_index, msg_reference);
        }
        /* reference number is in awaited list */
        else
        {
            U8 box_index = concat_info.seg - 1; /* start from 0 */

            /* add mr to delivery report awaited list */
            mmi_frm_sms_set_delivery_report_awaited_mr(delivery_report_awaited_index, msg_reference, box_index);
        }
    }
    /* Send_RSP fail */
    else
    {
        /* Single-segment msg should not be taken care. */
        if (concat_info.total_seg == 1)
        {
            delivery_report_awaited_index = MMI_FRM_SMS_ACTION_SIZE;
        }
        else
        {
            delivery_report_awaited_index = mmi_frm_sms_get_delivery_report_index_by_ref(ref);
        }

        /* reference number in awaited list */
        while (delivery_report_awaited_index != MMI_FRM_SMS_ACTION_SIZE)
        {
            mmi_frm_sms_remove_delivery_report_awaited(delivery_report_awaited_index);
            delivery_report_awaited_index = mmi_frm_sms_get_delivery_report_index_by_ref(ref);
        }
    }

}
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_handle_extension_char
 * DESCRIPTION
 *  added '1b' before extionsion char
 *  caller must make sure the dstBuf size is at least twice more than srcBuf size
 * PARAMETERS
 *  dstBuf      [?]         
 *  srcBuf      [?]         
 *  charNum     [IN]        number of char in srcBuffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_handle_extension_char(U16 *dstBuf, U16 *srcBuf, U16 charNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *dstBuffer = dstBuf;
    U16 *srcBuffer = srcBuf;
    U16 charNumber = charNum;
    U16 c;
    U16 srcCount = 0;
    U16 dstCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (srcCount < charNumber)
    {
        c = srcBuffer[srcCount];

		if (c != EMS_ESCAPE_CHARACTER)
		{
            if (UI_TEST_GSM_EXTENDED(c))
            {
                dstBuffer[dstCount] = EMS_ESCAPE_CHARACTER;
                dstCount++;
            }
            dstBuffer[dstCount] = c;
            dstCount++;
        }
        
        srcCount++;
    }

    dstBuffer[dstCount] = '\0';

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_count_extension_char
 * DESCRIPTION
 *  count the number of extension characters in buff
 * PARAMETERS
 *  buff            [?]         
 *  char_num        [IN]        
 * RETURNS
 *  number of extension characters in buff
 *****************************************************************************/
U32 mmi_frm_sms_count_extension_char(U16 *buff, U32 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 extension_char_num = 0;
    U32 count = 0;
    U16 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < char_num)
    {
        c = buff[count];
        if (UI_TEST_GSM_EXTENDED(c))
        {
            extension_char_num++;
        }
        count++;
    }

    return extension_char_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_UCS2
 * DESCRIPTION
 *  check if UCS2 char exists
 * PARAMETERS
 *  buf         [?]         
 *  charNum     [IN]        number of char in buffer
 * RETURNS
 *  return true if UCS2 char exists, else return false
 *****************************************************************************/
BOOL mmi_frm_sms_check_UCS2(U16 *buf, U16 charNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *buffer = buf;
    U16 charNumber = charNum;
    U16 c;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < charNumber)
    {
        c = buffer[count];
        if (UI_TEST_UCS2_CHARACTER(c))
        {
            return KAL_TRUE;
        }
        count++;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_dst_number
 * DESCRIPTION
 *  check if the number is valid
 * PARAMETERS
 *  num         [?]         dst number
 *  numLen      [IN]        number length
 * RETURNS
 *  return true if number is valid, else return false
 *****************************************************************************/
BOOL mmi_frm_sms_check_dst_number(U8 *num, U8 numLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *number = num;
    U8 numberlen = numLen;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < numberlen; i++)
    {
        U8 digit = number[i];

		if( (i == 0 ) && (digit == '+'))
		{
			continue;
		}

        if ((digit < '0' || digit > '9') && digit != '*' && digit != '#' )
		{
			return KAL_FALSE;
		}
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_is_in_sim_refresh
 * DESCRIPTION
 *  return if in sim refresh
 * PARAMETERS
 *  void
 * RETURNS
 *  return true if in sim refresh, else return false
 *****************************************************************************/
BOOL mmi_frm_sms_is_in_sim_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_frm_sms_list_done) && (!g_frm_sms_cntx.mmi_frm_sms_ready))
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}

#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_read_sms_content
 * DESCRIPTION
 *  Get start up sms content
 * PARAMETERS
 *  entry       [?]     Message entry info
 *  content     [?]     Message content
 * RETURNS
 *  object present
 *****************************************************************************/
U8 mmi_frm_sms_get_read_sms_content(MMI_FRM_SMS_GET_MSG_RSP_STRUCT *entry, U8 *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *date_p = entry->msg_data;
    EMSData *pEMSdata = NULL;
    U8 *textBuff;
    U8 *TPUD[1];
    U8 TPUDLEN[1];
    U8 is_obj_present = 0;
    U16 buffLen = entry->no_msg_data;
    U16 textLen = 0;
    U8 totalseg = 1;    /* always extract one segment at one time */

    EMSTATUS result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TPUDLEN[0] = (U8) buffLen;
    TPUD[0] = (U8*) date_p;

    if (entry->dcs != SMSAL_UCS2_DCS)
    {
        buffLen *= 2;
    }

    if (buffLen)
    {
        pEMSdata = OslMalloc(sizeof(EMSData));
        textBuff = OslMalloc(buffLen);
        result = EMSMsgPreview(
                    totalseg,
                    entry->dcs,
                    (U8) GetUDHIBit(entry->fo),
                    TPUD,
                    TPUDLEN,
                    buffLen,
                    textBuff,
                    &is_obj_present,
                    &textLen);

        if (result == EMS_OK)
        {
            kal_uint16 content_len = 0;

            pEMSdata->textBuffer = textBuff;
            pEMSdata->textBufferSize = entry->no_msg_data;
            pEMSdata->textLength = textLen;
            pEMSdata->dcs = entry->dcs;

            EMS_ConvertGSM7BitDefaultEncodingToAsciiWithoutEMSlib(pEMSdata);

            content_len = (pEMSdata->textLength < MMI_FRM_SMS_MSG_LEN) ? pEMSdata->textLength : MMI_FRM_SMS_MSG_LEN;

            memcpy((S8*) content, (S8*) pEMSdata->textBuffer, content_len);
        }
        else
        {
            memset((S8*) content, 0, ENCODING_LENGTH);
        }

        OslMfree(textBuff);
        OslMfree(pEMSdata);
    }
    else
    {
        memset((S8*) content, 0, ENCODING_LENGTH);
    }

    return is_obj_present;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_startup_sms_content
 * DESCRIPTION
 *  Get start up sms content
 * PARAMETERS
 *  entry       [?]     Message entry info
 *  content     [?]     Message content
 * RETURNS
 *  object present
 *****************************************************************************/
U8 mmi_frm_sms_get_startup_sms_content(MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT *entry, U8 *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *date_p = entry->msg_data;
    EMSData *pEMSdata = NULL;
    U8 *textBuff;
    U8 *TPUD[1];
    U8 TPUDLEN[1];
    U8 is_obj_present = 0;
    U16 buffLen = entry->no_msg_data;
    U16 textLen = 0;
    U8 totalseg = 1;    /* always extract one segment at one time */
    EMSTATUS result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TPUDLEN[0] = (U8) buffLen;
    TPUD[0] = (U8*) date_p;

    if (entry->dcs != SMSAL_UCS2_DCS)
    {
        buffLen *= 2;
    }

    if (buffLen)
    {
        pEMSdata = OslMalloc(sizeof(EMSData));
        textBuff = OslMalloc(buffLen);
        result = EMSMsgPreview(
                    totalseg,
                    entry->dcs,
                    (U8) GetUDHIBit(entry->fo),
                    TPUD,
                    TPUDLEN,
                    buffLen,
                    textBuff,
                    &is_obj_present,
                    &textLen);

        if (result == EMS_OK)
        {
            kal_uint16 content_len = 0;

            pEMSdata->textBuffer = textBuff;
            pEMSdata->textBufferSize = entry->no_msg_data;
            pEMSdata->textLength = textLen;
            pEMSdata->dcs = entry->dcs;

            EMS_ConvertGSM7BitDefaultEncodingToAsciiWithoutEMSlib(pEMSdata);

            content_len = (pEMSdata->textLength < MMI_FRM_SMS_MSG_LEN) ? pEMSdata->textLength : MMI_FRM_SMS_MSG_LEN;

            memcpy((S8*) content, (S8*) pEMSdata->textBuffer, content_len);
        }
        else
        {
            memset((S8*) content, 0, ENCODING_LENGTH);
        }

        OslMfree(textBuff);
        OslMfree(pEMSdata);
    }
    else
    {
        memset((S8*) content, 0, ENCODING_LENGTH);
    }

    return is_obj_present;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_content_to_entry
 * DESCRIPTION
 *  Add message content to message box structure
 * PARAMETERS
 *  entry       [?]     
 *  content     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_add_content_to_entry(mmi_frm_sms_msgbox_struct *entry, U8 *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) entry->content, 0, mmi_msg_get_max_content_size() * ENCODING_LENGTH);
    /* Decrease one due to the null terminator */
    mmi_ucs2ncpy((S8*) entry->content, (S8*) content, mmi_msg_get_max_content_size() - 1);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_content
 * DESCRIPTION
 *  get msg content
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_list_index      [IN]        
 *  content             [?]         
 *  max_subject_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mmi_frm_sms_get_content(
            kal_uint16 msg_box_type,
            kal_uint16 msg_list_index,
            kal_wchar *content,
            kal_uint8 max_subject_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 entryindex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case MMI_FRM_SMS_INBOX:
        case MMI_FRM_SMS_UNREAD:
            entryindex = mmi_frm_sms_inbox_list[msg_list_index];
            break;
        case MMI_FRM_SMS_OUTBOX:
            entryindex = mmi_frm_sms_outbox_list[msg_list_index];
            break;
        case MMI_FRM_SMS_DRAFTS:
            entryindex = mmi_frm_sms_drafts_list[msg_list_index];
            break;
    #ifdef __MMI_UNIFIED_MESSAGE__
        case MMI_FRM_SMS_UNSENT:
            entryindex = mmi_frm_sms_unsent_list[msg_list_index];
            break;
    #endif
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMI_FRM_SMS_ARCHIVE:
            entryindex = mmi_frm_sms_archive_list[msg_list_index];
            mmi_ucs2ncpy((S8*) content, (S8*) mmi_frm_sms_archiveIndex_list[entryindex].content, max_subject_len);
            return KAL_TRUE;
            break;
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case MMI_FRM_SMS_SIM:
            if (mmi_frm_sms_sim_list != NULL)
            {
                entryindex = mmi_frm_sms_sim_list[msg_list_index];
            }
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        default:
            entryindex = msg_list_index;
    }

    mmi_ucs2ncpy((S8*) content, (S8*) mmi_frm_sms_msg_box[entryindex].content, max_subject_len);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_highlight_ind
 * DESCRIPTION
 *  indicate UM to change highlighted msg
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  index               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_highlight_ind(U8 msg_box_type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 type;
    U16 msg_list_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box_type == MMI_FRM_SMS_NOBOX)
    {
        mmi_frm_sms_get_list_index(&type, &msg_list_index, index);

        if (type == MMI_FRM_SMS_INBOX)
        {
            type = UM_MSG_BOX_TYPE_INBOX;
        }
        else if (type == MMI_FRM_SMS_OUTBOX)
        {
            type = UM_MSG_BOX_TYPE_SENT;
        }
        else
        {
            U8 *address = NULL;

            address = mmi_frm_sms_get_sms_address(MMI_FRM_SMS_APP_DRAFTS, msg_list_index);

            if (strlen((char*)address))
            {
                type = UM_MSG_BOX_TYPE_UNSENT;
            }
            else
            {
                type = UM_MSG_BOX_TYPE_DRAFT;
            }
        }
    }
    else
    {
        switch (msg_box_type)
        {
            case MMI_FRM_SMS_INBOX:
            {
                type = UM_MSG_BOX_TYPE_INBOX;
                msg_list_index = index;
            }
                break;
            case MMI_FRM_SMS_OUTBOX:
            {
                type = UM_MSG_BOX_TYPE_SENT;
                msg_list_index = index;
            }
                break;
        #ifdef __MMI_UNIFIED_MESSAGE__
            case MMI_FRM_SMS_UNSENT:
            {
                type = UM_MSG_BOX_TYPE_UNSENT;
                msg_list_index = index;
            }
                break;
        #endif /* __MMI_UNIFIED_MESSAGE__ */
            case MMI_FRM_SMS_DRAFTS:
            {
                type = UM_MSG_BOX_TYPE_DRAFT;
                msg_list_index = index;
            }
                break;
            default:
            {
                MMI_ASSERT(0);
            }
                break;
        }
    }

    mmi_um_highlight_msg_ind(UM_MSG_TYPE_SMS, type, msg_list_index);

}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_escape_symbol_for_extension_char
 * DESCRIPTION
 *  added '1b' before extionsion char
 *  caller must make sure the dstBuf size is large enough
 *  The Euro sign is handled in this API.
 * PARAMETERS
 *  dstBuf      [?]         
 *  srcBuf      [?]         
 *  charNum     [IN]        number of char in srcBuffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_add_escape_symbol_for_extension_char(U16 *dstBuf, U16 *srcBuf, U16 charNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *dstBuffer = dstBuf;
    U16 *srcBuffer = srcBuf;
    U16 charNumber = charNum;
    U16 c;
    U16 srcCount = 0;
    U16 dstCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (srcCount < charNumber)
    {
        c = srcBuffer[srcCount];
        if (MMI_SMS_TEST_GSM7BIT_EXTENDED(c))
        {
            dstBuffer[dstCount] = EMS_ESCAPE_CHARACTER;
            dstCount++;
        }

        if (c == MMI_SMS_EURO_SIGN)
        {
            dstBuffer[dstCount] = EMS_EURO_CHARACTER;
        }
        else
        {
            dstBuffer[dstCount] = c;
        }
        
        srcCount++;
        dstCount++;
    }

    dstBuffer[dstCount] = '\0';

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_remove_escape_symbol_for_extension_char
 * DESCRIPTION
 *  remove '1b' before extionsion char
 *  caller must make sure the dstBuf size is large enough
 *  The Euro sign is handled in this API.
 * PARAMETERS
 *  dstBuf      [?]         
 *  srcBuf      [?]         
 *  charNum     [IN]        number of char in srcBuffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_remove_escape_symbol_for_extension_char(U16 *dstBuf, U16 *srcBuf, U16 charNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *dstBuffer = dstBuf;
    U16 *srcBuffer = srcBuf;
    U16 charNumber = charNum;
    U16 c;
    U16 srcCount = 0;
    U16 dstCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (srcCount < charNumber)
    {
        c = srcBuffer[srcCount];
        if (c == EMS_ESCAPE_CHARACTER)
        {
            srcCount++;

            c = srcBuffer[srcCount];

            if (c == EMS_EURO_CHARACTER)
            {
                dstBuffer[dstCount] = MMI_SMS_EURO_SIGN;        
                
                srcCount++;
                dstCount++;
            }
            continue;
        }

        dstBuffer[dstCount] = c;
        
        srcCount++;
        dstCount++;
    }

    dstBuffer[dstCount] = '\0';

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_init_msgbox
 * DESCRIPTION
 *  Init message box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_init_msgbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(
        (S8*) mmi_frm_sms_inbox_list,
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(U16) * g_frm_sms_cntx.mmi_frm_sms_msg_box_size);
    memset(
        (S8*) mmi_frm_sms_outbox_list,
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(U16) * g_frm_sms_cntx.mmi_frm_sms_msg_box_size);
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    memset(
        (S8*) mmi_frm_sms_drafts_list,
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(U16) * g_frm_sms_cntx.mmi_frm_sms_msg_box_size);
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */
#ifdef __MMI_UNIFIED_MESSAGE__
    memset(
        (S8*) mmi_frm_sms_unsent_list,
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(U16) * g_frm_sms_cntx.mmi_frm_sms_msg_box_size);
#endif /* __MMI_UNIFIED_MESSAGE__ */
    memset(
        (S8*) mmi_frm_sms_msg_box,
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(mmi_frm_sms_msgbox_struct) * g_frm_sms_cntx.mmi_frm_sms_msg_box_size);
    memset(
        (S8*) mmi_frm_sms_index_list,
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(mmi_frm_sms_index_struct) * g_frm_sms_cntx.mmi_frm_sms_msg_box_size);
    memset(
        (S8*) mmi_frm_sms_awaited,
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(mmi_frm_sms_deliver_msg_struct) * (MMI_FRM_SMS_ACTION_SIZE + 1));
    memset((S8*) mmi_frm_sms_awaited_counter, MMI_FRM_SMS_INVALID_NUM, sizeof(U8) * (MMI_FRM_SMS_ACTION_SIZE));
    memset(
        (S8*) mmi_frm_sms_data,
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(mmi_frm_sms_deliver_data_struct) * (MMI_FRM_SMS_ACTION_SIZE + 1));
    memset((S8*) mmi_frm_sms_data_counter, MMI_FRM_SMS_INVALID_NUM, sizeof(U8) * (MMI_FRM_SMS_ACTION_SIZE));
    memset((S8*) mmi_frm_sms_content, 0, sizeof(mmi_frm_sms_content_struct) * (MMI_FRM_SMS_MSG_CONTENT_NUM + 1));

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    memset(
        (S8*) mmi_frm_sms_delivery_report_awaited,
        0,
        sizeof(mmi_frm_sms_delivery_report_list_struct) * (MMI_FRM_SMS_ACTION_SIZE));
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */ 
    for (i = 0; i < (MMI_FRM_SMS_MSG_CONTENT_NUM + 1); i++)
    {
        mmi_frm_sms_content[i].segment = MMI_FRM_SMS_INVALID_NUM;
        mmi_frm_sms_content[i].nextindex = MMI_FRM_SMS_INVALID_NUM;
    }
    mmi_frm_sms_inbox_size = 0;
    mmi_frm_sms_outbox_size = 0;
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    mmi_frm_sms_drafts_size = 0;
#endif 
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_frm_sms_unsent_size = 0;
#endif
    /* reset message icon in the status bar in case of sim refresh */
    g_msg_cntx.msg_full_ind = FALSE;
    g_msg_cntx.msg_ind_in_idle = FALSE;
#ifndef __MMI_DUAL_SIM_MASTER__
        mmi_msg_set_msg_icon(FALSE, FALSE);
#else /* __MMI_DUAL_SIM_MASTER__ */
	MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
	MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_status_report
 * DESCRIPTION
 *  convert status report structure to entry structure
 * PARAMETERS
 *  data        [?]     Data
 *  entry       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_convert_status_report(MMI_FRM_SMS_STATUS_REPORT_IND_STRUCT *data, mmi_frm_sms_status_report_ind_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry->fo= data->fo;
    memcpy(entry->scts, data->scts, 7);
	memcpy(entry->dt, data->dt, 7);
    memcpy(&entry->ra_number, &data->ra_number, sizeof(l4c_number_struct));    
    entry->st = data->st;
    entry->pid = data->pid;
    entry->dcs = data->dcs;
    entry->mr = data->mr;    
    entry->no_msg_data = data->no_msg_data;    
	memcpy(entry->msg_data, data->msg_data, 1);
#ifdef __MMI_DUAL_SIM_MASTER__
	entry->isFromMaster = TRUE;
#endif
	
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_copy_object_data
 * DESCRIPTION
 *  copy obj related data to dstBuff
 * PARAMETERS
 *  OUT: dstBuff --- dst buffer
 *  OUT: copyedBytes --- how many bytes are cpoied for this object, the copied data includes 2 bytes for copied number (U16) 
 *  IN:  objType --- object type 
 *  IN:  objData --- object data
 * RETURNS
 *  return FALSE meana unsupport type, don't copy anything
 *  the copied data includes 2 bytes for copied number (U16) 
 *****************************************************************************/
#ifndef OFFSET_OF
#define OFFSET_OF(_type, _field)      ((U32)&(((_type *)0)->_field))
#endif

U8 mmi_frm_sms_copy_object_data(U8*dstBuff, U16*copyedBytes, U8 objType, EMSObjData *objData)
{
    U16 objDataLen = 0; /*include pdulen and needed info len*/
    U16 lenFieldSize = sizeof(objDataLen);
    int b_pos = 0;
	
    switch (objType)
    {
        case EMS_TYPE_TEXT_FORMAT:
        {
            EMSTextFormat *text_ptr = &(objData->text_format);
            objDataLen = sizeof(EMSTextFormat);  
            memcpy(dstBuff, &objDataLen, lenFieldSize);
            memcpy(dstBuff + lenFieldSize, text_ptr, objDataLen);
        }
        break;
        
        case EMS_TYPE_PREDEF_SND:
        case EMS_TYPE_PREDEF_ANM:    
        {
            objDataLen = 0;
            memcpy(dstBuff, &objDataLen, lenFieldSize);					
        }
        break;        
        
        case EMS_TYPE_USERDEF_SND:
        {
            EMSSound *snd_ptr = &(objData->sound);	
            b_pos = OFFSET_OF(EMSSound, pdu_length); 
            objDataLen =  sizeof(EMSSound) - b_pos + snd_ptr->pdu_length; /*-pos: does not need copy kal_uint8  *pdu;*/
            memcpy(dstBuff, &objDataLen, lenFieldSize);
            memcpy(dstBuff + lenFieldSize, &(snd_ptr->pdu_length),  sizeof(EMSSound) - b_pos); /*+4: does not need copy kal_uint8  *pdu;, only copy others*/
            memcpy(dstBuff + lenFieldSize + sizeof(EMSSound) - b_pos, snd_ptr->pdu, snd_ptr->pdu_length);        
        }
        break;
        
        case EMS_TYPE_USERDEF_ANM:
        {
            EMSAnim *anm_ptr = &(objData->animation);
            b_pos = OFFSET_OF(EMSAnim,pdu_length); 
            objDataLen =  sizeof(EMSAnim) -b_pos + anm_ptr->pdu_length; /*-4: does not need copy kal_uint8  *pdu;*/
            memcpy(dstBuff, &objDataLen, lenFieldSize);
            memcpy(dstBuff + lenFieldSize, &(anm_ptr->pdu_length), sizeof(EMSAnim) - b_pos); /*+4: does not need copy kal_uint8  *pdu;, only copy others*/
            memcpy(dstBuff + lenFieldSize + sizeof(EMSAnim) - b_pos, anm_ptr->pdu, anm_ptr->pdu_length);          
        }
        break;
        
        case EMS_TYPE_PIC:
        {
  
            EMSPicture *pic_ptr = (EMSPicture *)&(objData->picture);

            b_pos = OFFSET_OF(EMSPicture,pdu_length);  /*pay attendsion, here, sizeof struc value will BE 4*n*/
            objDataLen =  sizeof(EMSPicture) - b_pos + pic_ptr->pdu_length; /*-4: does not need copy kal_uint8  *pdu;*/
            memcpy(dstBuff, &objDataLen, lenFieldSize);
            memcpy(dstBuff + lenFieldSize, &(pic_ptr->pdu_length), sizeof(EMSPicture) - b_pos); /*+4: does not need copy kal_uint8  *pdu;, only copy others*/
            memcpy(dstBuff + lenFieldSize + sizeof(EMSPicture) - b_pos, pic_ptr->pdu, pic_ptr->pdu_length);

        }
        break;                       
        
        
        default: 
        {
            return FALSE; 
        }
        break;
        
    }
    *copyedBytes = objDataLen + lenFieldSize; /*how many bytes are copyed, +2 : the field to store "objDatalen" info*/
    return TRUE; 
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_archive_content_file_size
 * DESCRIPTION
 *  Get ems object file sze
 * PARAMETERS  
 *    
 * RETURNS
 *  return file size. 
 *****************************************************************************/
U16 mmi_frm_sms_get_archive_content_file_size()
{
    EMSData *pEMSdata;
    EMSObject *currObj = NULL;
    U16  filesize=0; /*filesize unit= byte*/
    int e_pos =0;
	U16 objDataLen = 0; /*include pdulen and needed info len*/
    U16 lenFieldSize = sizeof(objDataLen);
    int b_pos = 0;
    
    GetEMSDataForView(&pEMSdata, 0);
    
    filesize = filesize+ sizeof(pEMSdata->textLength);    
    filesize = filesize + pEMSdata->textLength; 
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                               "*-------[Smsutil.c] mmi_frm_sms_get_archive_content_file_size  -------*\n");       
    currObj = pEMSdata->listHead;
    e_pos = OFFSET_OF(EMSObject, data); 
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[Smsutil.c]pEMSdata->textLength: %d\n", pEMSdata->textLength);
    while (currObj != NULL)
    {                    	
		switch (currObj->Type)
		{
	        case EMS_TYPE_TEXT_FORMAT:
	        {	            
	            objDataLen = sizeof(EMSTextFormat); 	            
	        }
	        break;
	        
	        case EMS_TYPE_PREDEF_SND:
	        case EMS_TYPE_PREDEF_ANM:    
	        {
	            objDataLen = 0;	            			
	        }
	        break;        
	        
	        case EMS_TYPE_USERDEF_SND:
	        {	            	
	            b_pos = OFFSET_OF(EMSSound, pdu_length); 
	            objDataLen =  sizeof(EMSSound) - b_pos + currObj->data->sound.pdu_length; /*-pos: does not need copy kal_uint8  *pdu;*/	                    
	        }
	        break;
	        
	        case EMS_TYPE_USERDEF_ANM:
	        {	            
	            b_pos = OFFSET_OF(EMSAnim,pdu_length); 
	            objDataLen =  sizeof(EMSAnim) - b_pos + currObj->data->animation.pdu_length; /*-4: does not need copy kal_uint8  *pdu;*/	                     
	        }
	        break;
	        
	        case EMS_TYPE_PIC:
	        {				
	            b_pos = OFFSET_OF(EMSPicture,pdu_length);  /*pay attendsion, here, sizeof struc value will BE 4*n*/
	            objDataLen =  sizeof(EMSPicture) - b_pos + currObj->data->picture.pdu_length; /*-4: does not need copy kal_uint8  *pdu;*/	           

	        }
	        break; 
	        
	        default: 
	        {
	            objDataLen = MMI_FRM_SMS_INVALID_INDEX; 
	        }
	        break;
        
    	}
		
		if (objDataLen != MMI_FRM_SMS_INVALID_INDEX)        
        {    
            filesize = filesize + objDataLen + lenFieldSize + e_pos;            
        }
		
        currObj = currObj->next;
    }    
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[Smsutil.c]filesize: %d\n", filesize);
    return filesize;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_to_archive_content_file
 * DESCRIPTION
 *  convert EMS info to archive content file
 * PARAMETERS
 *  OUT: convertedBuff --- buff for converted result, 
 *  OUT: objNum --- object number  
 * RETURNS
 *  return converted file size. 0 means convert fail, it must more than 0 bytes
 *****************************************************************************/
U16 mmi_frm_sms_convert_to_archive_content_file(U8* convertedBuff, U16 *objNum)
{
    EMSData *pEMSdata;
    EMSObject *currObj = NULL;
    U16 object_num=0, filesize=0, copyednum=0; /*filesize unit= byte*/
    int e_pos =0;
    
    GetEMSDataForView(&pEMSdata, 0);
    
    /*1. text part */   
    memcpy(convertedBuff,&(pEMSdata->textLength), sizeof(pEMSdata->textLength));  /*if empty, at least 2 bytes field to store 0 value*/
    filesize = filesize+ sizeof(pEMSdata->textLength);
    memcpy(convertedBuff+filesize, pEMSdata->textBuffer, pEMSdata->textLength);
    filesize = filesize + pEMSdata->textLength; 
    
    
    /*2. object part */   
    currObj = pEMSdata->listHead;
    e_pos = OFFSET_OF(EMSObject, data); /*copy kal_uint8 Type, kal_uint8 PredefNo, kal_uint16 offsetToText*/
    
    while (currObj != NULL)
    {
        memcpy(convertedBuff+filesize, currObj, e_pos);
        filesize = filesize + e_pos;
        copyednum = 0;
        if (mmi_frm_sms_copy_object_data(convertedBuff+filesize, &copyednum, currObj->Type, currObj->data) != TRUE) 
        {
            filesize = filesize -e_pos;    
        }    
        else
        {    
            filesize = filesize + copyednum; 
            object_num ++;
        }
        currObj = currObj->next;
    }
    
    *objNum = object_num;
    return filesize;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_to_archive_index_entry
 * DESCRIPTION
 *  convert info to archive index entry
 * PARAMETERS
 *  OUT: archIndexfile_entry --- structure for converted result,  <-- before calling this API. plz memset the structure
 *  IN:  filesize --- file size of converted indexfile "idx.a"
 *  IN:  objNum ---object number, 
 *  IN:  fromboxtype --- from which box type (inbox/outbox) 
 *  IN:  srcIndex --- the index in srcBox
 * RETURNS
 *  return TRUE or FALSE -- convert successfully or not
 *****************************************************************************/
U8 mmi_frm_sms_convert_to_archive_index_entry(
    mmi_frm_sms_archiveIndex_struct *archIndexfile_entry,
    U16 filesize,
    U16 objNum,
    mmi_frm_sms_msgbox_enum fromboxtype,
    U16 srcIndex)
{
    EMSData *pEMSdata;
    U8 *timestamp = NULL;

   /*1. check the msg complete or not -- for display incomplete icon, here, the fromboxtype will not be archive :> */
    if (!mmi_frm_sms_check_sms_complete((U16)fromboxtype, srcIndex))
    {
        archIndexfile_entry->isComplete = FALSE;        
    }
    else
    {
        archIndexfile_entry->isComplete = TRUE;        
    }
/*    //no need to store filename to save flash memory
    //1. decide filename
    int freeid = getFreeArchFileId();
    if(freeid > 0)
        sprintf(archIndexfile_entry->fileName,"%3lx.a", freeid);
    else
        return FALSE; //need any handle??
*/        
    /*2. convert info from mmi_frm_sms_xxx_list[] (xxx mean fromboxtype--MMI_FRM_SMS_INBOX/MMI_FRM_SMS_OUTBOX)*/
    memcpy((S8*)archIndexfile_entry->number,
    	(S8*)mmi_frm_sms_get_address((U16)fromboxtype, srcIndex),
    	MAX_DIGITS_SMS);
    timestamp = mmi_frm_sms_get_timestamp((U16)fromboxtype, srcIndex);
    memcpy( archIndexfile_entry->timestamp, timestamp, sizeof(archIndexfile_entry->timestamp));
    
    mmi_frm_sms_get_content(
    (kal_uint16) fromboxtype,
    srcIndex,
    archIndexfile_entry->content,
    (kal_uint8) mmi_msg_get_max_content_size());
    
    /*3. convert info from EMSDATA and input parameter*/
    GetEMSDataForView(&pEMSdata, 0);
    archIndexfile_entry->dcs = pEMSdata->dcs;
    archIndexfile_entry->fromboxtype = fromboxtype;
    archIndexfile_entry->textLength = pEMSdata->textLength;
    archIndexfile_entry->objectnum = objNum;    
    archIndexfile_entry->filesize = filesize; 
    memcpy(archIndexfile_entry->guardPattern, MMI_FRM_SMS_ARCHIVE_GUARD_PATTERN, 4);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_archive_pub_folder_created
 * DESCRIPTION
 *  to make sure the archive folder for archive is created, if not, create it
 * PARAMETERS
 *  FS_HANDLE
 * RETURNS
 *  void
 *****************************************************************************/
FS_HANDLE mmi_frm_sms_check_archive_pub_folder_created(void)
{
    S8 tmp_str[MMI_SMS_MAX_ARCH_PATH_LEN+ 1 +4];
    S8 archive_folder_path[(MMI_SMS_MAX_ARCH_PATH_LEN + 1 +4) * ENCODING_LENGTH];
    FS_HANDLE file_handle = FS_NO_ERROR; 
    sprintf(tmp_str, "%c:%s", MMI_PUBLIC_DRV, MMI_SMS_ARCH_PATH);
    mmi_asc_to_ucs2((S8*) archive_folder_path, (S8*) tmp_str);
    
    file_handle = FS_Open((PU16)archive_folder_path, FS_OPEN_DIR|FS_READ_ONLY);
    if (file_handle < 0)
    {
        file_handle = FS_CreateDir ((PU16)archive_folder_path);
    }
    else
    {
        FS_Close(file_handle);
    }
    

    if (file_handle < 0) //create folder fail
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "[smsUtil.c] #1 Create arch folder in pub drv FAIL! errCode=%d\n",file_handle);   
    }
    else
    {
        FS_SetAttributes((PU16) archive_folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }
    return file_handle;
}   

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_new_archive_content_file
 * DESCRIPTION
 *  store one archive content file
 * PARAMETERS
 *  IN: U8* ArchBuf
 *  IN: U16 fileId 
 *  IN: U16 fileSize 
 *  OUT: FS_HANDLE *fsErrCode  --file system related error code 
 * RETURNS
 *  return TRUE or FALSE -- convert successfully or not
 *****************************************************************************/
U8 mmi_frm_sms_new_archive_content_file(U8* ArchBuf ,U16 fileId , U16 fileSize, FS_HANDLE *pFsErrCode)
{
    FS_HANDLE file_handle;
    U32 write_len = 0;
    S8 filename_buff_ucs2[(MMI_SMS_MAX_ARCH_PATH_LEN + 1 + 4) * ENCODING_LENGTH];
    S8 filename_buff_ascii[MMI_SMS_MAX_ARCH_PATH_LEN + 4];  /*+4 for D:*/
    *pFsErrCode = FS_NO_ERROR;

    if(fileId >= CM_SMS_MAX_ARMSG_NUM)
    {
    	return FALSE;	
    }
    
    memset(filename_buff_ucs2,0, sizeof(filename_buff_ucs2));
    memset(filename_buff_ascii,0, sizeof(filename_buff_ascii));
    sprintf(filename_buff_ascii, "%c:%s%x.a", (S8)MMI_PUBLIC_DRV, MMI_SMS_ARCH_PATH, fileId);
    mmi_asc_to_ucs2(filename_buff_ucs2, filename_buff_ascii);
    
    file_handle = FS_Open((const WCHAR*)filename_buff_ucs2, FS_CREATE_ALWAYS | FS_READ_WRITE | FS_ATTR_HIDDEN);
    
    if (file_handle < 0)
    {
        *pFsErrCode = file_handle;
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "[SMS-ARCH](new content file), error=%d\n", file_handle);
        return FALSE;  
    }     
    
    if ((*pFsErrCode = FS_Write(file_handle, ArchBuf, fileSize, &write_len)) != FS_NO_ERROR)
    {
        FS_Close(file_handle);
        return FALSE;
    }        
    FS_Close(file_handle);    
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_update_archive_index_entry
 * DESCRIPTION
 *  update one entry in archive index file
 * PARAMETERS
 *  IN: archIndexfile_entry -- one entry strcture for data u want to update 
 *  IN: dstIdx --- the index of mmi_frm_sms_archiveIndex_list[] (value = 0~CM_SMS_MAX_ARMSG_NUM-1)
 *  OUT: pFsErrCode --- file sys related error code
 * RETURNS
 *  return TRUE or FALSE -- update successfully or not
 *****************************************************************************/


U8 mmi_frm_sms_update_archive_index_entry(mmi_frm_sms_archiveIndex_struct *archIndexfile_entry, U16 dstIdx, FS_HANDLE *pFsErrCode)
{
    FS_HANDLE file_handle;
    U32 write_len = 0;
    S8 filename_buff_ucs2[(MMI_SMS_MAX_ARCH_PATH_LEN + 1 +4) * ENCODING_LENGTH];
    S8 filename_buff_ascii[MMI_SMS_MAX_ARCH_PATH_LEN +4];

    memset(filename_buff_ucs2, 0, sizeof(filename_buff_ucs2));
    memset(filename_buff_ascii, 0, sizeof(filename_buff_ascii));
    sprintf(filename_buff_ascii, "%c:%s%s", (S8)MMI_SYSTEM_DRV, MMI_SMS_ARCH_SYS_PATH, "idx.a");
    mmi_asc_to_ucs2(filename_buff_ucs2, filename_buff_ascii);
    *pFsErrCode = FS_NO_ERROR;     
    file_handle = FS_Open((const WCHAR*)filename_buff_ucs2, FS_READ_WRITE);
    
    if (file_handle < 0)
    {
        *pFsErrCode = file_handle;
        return FALSE;  
    }        
    
    FS_Seek(file_handle, dstIdx * sizeof(mmi_frm_sms_archiveIndex_struct), FS_FILE_BEGIN);
    
    if ((*pFsErrCode = FS_Write(file_handle, archIndexfile_entry, sizeof(mmi_frm_sms_archiveIndex_struct), &write_len)) != FS_NO_ERROR)
    {
    	FS_Close(file_handle);
        return FALSE;
    }   
    
    FS_Close(file_handle);
    return MMI_TRUE;;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_free_archive_file_id
 * DESCRIPTION
 *  To get free id in archive file (value =0~CM_SMS_MAX_ARMSG_NUM-1)
 * PARAMETERS
 *  IN: fromboxtype --- saved from which box (inbox or outbox) 
 *  IN: index --- the index in srcBox
 * RETURNS
 *  TRUE--- save successfully. FALSE--- save fail 
 *****************************************************************************/
U8 mmi_frm_sms_get_free_archive_file_id(U16* freeId)
{
   U16 addindex = CM_SMS_MAX_ARMSG_NUM;
   U16 emptyindex = CM_SMS_MAX_ARMSG_NUM;
   U8 found = FALSE;
   
    while ((found == FALSE) && (addindex > 0))
    {
        addindex--;
        if (mmi_frm_sms_archiveIndex_list[addindex].filesize == 0) /*it means the entry is not used to record archive msg*/
        {
            emptyindex = addindex;
            continue;
        }
    }
    
    if (emptyindex == CM_SMS_MAX_ARMSG_NUM) /*no free id can be used*/
    {
    	return FALSE;
    }
    *freeId =  emptyindex;  
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_add_archive_to_list
 * DESCRIPTION
 *  add archive msg to arch ist (mmi_frm_sms_archive_list[])
 * PARAMETERS
 *  IN: data --- 
 *  IN: index --- the index in mmi_frm_sms_archiveIndex_list
 * RETURNS
 *  TRUE/FASLE : init ok or fail
 ** need sort by time
 *****************************************************************************/
void mmi_frm_sms_add_archive_to_list(mmi_frm_sms_archiveIndex_struct *data, U16 index)
{
    U16 i = 0;
    U16 j = 0;
    U16 k = 0;

    for (k = 0; k < mmi_frm_sms_archive_size; k++)
    {
        if (mmi_frm_sms_archive_list[k] == index)
        {
            return;
        }
    }

    /* No timestamp */
    if (data->timestamp[1] == 0)
    {
        mmi_frm_sms_archive_list[mmi_frm_sms_archive_size] = index;
        mmi_frm_sms_archive_size++;
    }
    else
    {
        while (i < mmi_frm_sms_archive_size)
        {
            if (mmi_frm_sms_archive_list[i] == index)
            {
                return;
            }
            if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[0] < data->timestamp[0])
            {
                break;
            }
            else if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[0] > data->timestamp[0])
            {
                i++;
                continue;
            }
            if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[1] < data->timestamp[1])
            {
                break;
            }
            else if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[1] > data->timestamp[1])
            {
                i++;
                continue;
            }
            if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[2] < data->timestamp[2])
            {
                break;
            }
            else if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[2] > data->timestamp[2])
            {
                i++;
                continue;
            }
            if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[3] < data->timestamp[3])
            {
                break;
            }
            else if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[3] > data->timestamp[3])
            {
                i++;
                continue;
            }
            if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[4] < data->timestamp[4])
            {
                break;
            }
            else if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[4] > data->timestamp[4])
            {
                i++;
                continue;
            }
            if (mmi_frm_sms_archiveIndex_list[mmi_frm_sms_archive_list[i]].timestamp[5] <= data->timestamp[5])
            {
                break;
            }
            i++;
            continue;
        }
        if (mmi_frm_sms_archive_size > 0)
        {
            for (j = mmi_frm_sms_archive_size; j > i; j--)
            {
                mmi_frm_sms_archive_list[j] = mmi_frm_sms_archive_list[j - 1];
            }
        }
        mmi_frm_sms_archive_list[i] = index;
        mmi_frm_sms_archive_size++;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_memset_archive_index_entry
 * DESCRIPTION
 *  memset archive index entry (mmi_frm_sms_archiveIndex_list[])
 *  guardPattern field will be reset to F2F2F2F2 and other fileds will be 0 
 * PARAMETERS
 *  U16 index in mmi_frm_sms_archiveIndex_list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_memset_archive_index_entry(mmi_frm_sms_archiveIndex_struct *entry_ptr)  
{
    memset(entry_ptr, 0, sizeof(mmi_frm_sms_archiveIndex_struct));
    memcpy(entry_ptr->guardPattern, MMI_FRM_SMS_ARCHIVE_GUARD_PATTERN, 4);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_save_one_archive_msg
 * DESCRIPTION
 *  To save one archive message
 * PARAMETERS
 *  IN: fromboxtype --- saved from which box (inbox or outbox) 
 *  IN: index --- the index in srcBox
 *  OUT: FS_error_code --- file system  related error code
 * RETURNS
 *  TRUE--- save successfully. FALSE--- save fail 
 *****************************************************************************/
U8 mmi_frm_sms_save_one_archive_msg(mmi_frm_sms_msgbox_enum fromboxtype, U16 srcIndex, FS_HANDLE *pFsErrCode) 
{
    U16 objectnum = 0, filesize = 0;
    U16 fileId = 0; /*valid file id is from 0~ CM_SMS_MAX_ARMSG_NUM-1*/
    U8 result = FALSE;
    mmi_frm_sms_archiveIndex_struct *archIndexfile_entry_ptr = NULL;
    U8* smsArchBuf = NULL;
    *pFsErrCode = FS_NO_ERROR;
    /*get free file id*/
    if (FALSE == mmi_frm_sms_get_free_archive_file_id(&fileId))
    {
      return FALSE;	
    }  


    *pFsErrCode = mmi_frm_sms_check_archive_pub_folder_created();
        
    if (*pFsErrCode < 0)
    {
     	return FALSE;	   
    }

	filesize = mmi_frm_sms_get_archive_content_file_size();
	if (filesize < MMI_SMS_MAX_ARCH_BUF_SIZE)
	{
		filesize = MMI_SMS_MAX_ARCH_BUF_SIZE;
	}
	if (applib_mem_screen_get_max_alloc_size() < (U32)filesize)
	{
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[Smsutil.c]mmi_frm_sms_memset_archive_index_entry no space\n" );
		return FALSE;
	}
    smsArchBuf = (U8*)applib_mem_screen_alloc(filesize);
    memset((S8*) smsArchBuf, 0, MMI_SMS_MAX_ARCH_BUF_SIZE);	

	if ((filesize = mmi_frm_sms_convert_to_archive_content_file(smsArchBuf, &objectnum)) == 0)
    { 
        applib_mem_screen_free(smsArchBuf);
        return FALSE;  
    }

    archIndexfile_entry_ptr = (mmi_frm_sms_archiveIndex_struct*) OslMalloc(sizeof(mmi_frm_sms_archiveIndex_struct));
    mmi_frm_sms_memset_archive_index_entry(archIndexfile_entry_ptr);

    if (FALSE == mmi_frm_sms_convert_to_archive_index_entry(archIndexfile_entry_ptr, filesize, objectnum, fromboxtype, srcIndex) )
    {
        applib_mem_screen_free(smsArchBuf);
        OslMfree(archIndexfile_entry_ptr);
        return FALSE;  
    } 
    
    /*write content part to FS , if write ok, update index file and index list*/
    if ((result = mmi_frm_sms_new_archive_content_file(smsArchBuf, fileId, filesize, pFsErrCode)) != FALSE)  
    {
        memcpy((S8*) &mmi_frm_sms_archiveIndex_list[fileId], (S8*)archIndexfile_entry_ptr, sizeof(mmi_frm_sms_archiveIndex_struct));
        mmi_frm_sms_add_archive_to_list(&mmi_frm_sms_archiveIndex_list[fileId], fileId);
        result = mmi_frm_sms_update_archive_index_entry(archIndexfile_entry_ptr, fileId, pFsErrCode);    /*fileId=2 save to "002.a" in [2] */
    }

    /*free memory*/
    applib_mem_screen_free(smsArchBuf);
    OslMfree(archIndexfile_entry_ptr);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_update_whole_archive_index_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_frm_sms_update_whole_archive_index_file(void)
{
    FS_HANDLE file_handle;
    S8 filename_buff_ucs2[(MMI_SMS_MAX_ARCH_PATH_LEN + 1 + 4) * ENCODING_LENGTH];
    S8 filename_buff_ascii[MMI_SMS_MAX_ARCH_PATH_LEN + 4];
    U32 write_size = 0;

    memset(filename_buff_ucs2, 0, sizeof(filename_buff_ucs2));
    memset(filename_buff_ascii, 0, sizeof(filename_buff_ascii));
    sprintf(filename_buff_ascii, "%c:%s%s", (S8)MMI_SYSTEM_DRV, MMI_SMS_ARCH_SYS_PATH, "idx.a");
    mmi_asc_to_ucs2(filename_buff_ucs2, filename_buff_ascii);

    if ((file_handle = FS_Open((U16*)filename_buff_ucs2, FS_READ_WRITE) ) < 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "[SMS-ARCH](update whole)open idx.a fail, error=%d\n", file_handle);
        return FALSE;
    }
    FS_Write(file_handle, mmi_frm_sms_archiveIndex_list, sizeof(mmi_frm_sms_archiveIndex_struct) * CM_SMS_MAX_ARMSG_NUM, &write_size);    
    FS_Close(file_handle);
    return TRUE;	

}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_archive_folder_created
 * DESCRIPTION
 *  to make sure the archive folder for archive is created, if not, create it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_check_archive_folder_created(void)
{

    S8 tmp_str[MMI_SMS_MAX_ARCH_PATH_LEN+ 1 +4];
    S8 archive_folder_path[(MMI_SMS_MAX_ARCH_PATH_LEN + 1 +4) * ENCODING_LENGTH];
    FS_HANDLE file_handle; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

//1--- create arch folder in sys drive for storing idx file
    sprintf(tmp_str, "%c:%s", MMI_SYSTEM_DRV, MMI_SMS_ARCH_SYS_PATH);
    mmi_asc_to_ucs2((S8*) archive_folder_path, (S8*) tmp_str);
    file_handle = FS_CreateDir((PU16) archive_folder_path);
    if ((file_handle < 0) && (file_handle != FS_FILE_EXISTS))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "[smsUtil.c] Create arch folder in sys drv FAIL!errcode=%d\n",file_handle);
    }    
    FS_SetAttributes((PU16) archive_folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);

//2--- create arch folder in user drive for storing content file
    mmi_frm_sms_check_archive_pub_folder_created();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_recreate_archive_folder_in_public_drv
 * DESCRIPTION
 *  to remove all files in this folder  (archive folder in public drv)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_frm_sms_recreate_archive_folder_in_public_drv(void)
{
    S8 tmp_str[MMI_SMS_MAX_ARCH_PATH_LEN+ 1 +4];
    S8 archive_folder_path[(MMI_SMS_MAX_ARCH_PATH_LEN + 1 +4) * ENCODING_LENGTH];

    sprintf(tmp_str, "%c:%s", MMI_PUBLIC_DRV, MMI_SMS_ARCH_PATH);
    mmi_asc_to_ucs2((S8*) archive_folder_path, (S8*) tmp_str);

    FS_XDelete((WCHAR*)archive_folder_path, 
       FS_FILE_TYPE, 
       NULL, 
       0);

    FS_CreateDir((PU16) archive_folder_path);
    FS_SetAttributes((PU16) archive_folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);  
}


/*delete one arch content file ex. 2.a*/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_remove_archive_content_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileId      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_frm_sms_remove_archive_content_file(U16 fileId)
{
    S8 filename_buff_ucs2[(MMI_SMS_MAX_ARCH_PATH_LEN + 1 +4) * ENCODING_LENGTH];
    S8 filename_buff_ascii[MMI_SMS_MAX_ARCH_PATH_LEN +4];  /*+4 for D:*/
    FS_HANDLE file_handle;          
    memset(filename_buff_ucs2,0, sizeof(filename_buff_ucs2));
    memset(filename_buff_ascii,0, sizeof(filename_buff_ascii));
    sprintf(filename_buff_ascii, "%c:%s%x.a", (S8)MMI_PUBLIC_DRV, MMI_SMS_ARCH_PATH, fileId);
    mmi_asc_to_ucs2(filename_buff_ucs2, filename_buff_ascii);	

    file_handle = FS_Delete((const WCHAR*)filename_buff_ucs2);

    if (FS_READ_ONLY_ERROR == file_handle) /*mean user may change attribute to read only via usb*/
    {
        FS_SetAttributes((PU16) filename_buff_ucs2, FS_READ_WRITE);  
        file_handle = FS_Delete((const WCHAR*)filename_buff_ucs2);
    }
    else if ( (FS_PATH_NOT_FOUND == file_handle) || (FS_FILE_NOT_FOUND == file_handle) ) /*mean user remove files via usb, need sync to idx.a file*/
    {
        return TRUE; /* use return ture to sync idx file and content file*/
    }
    
    if (file_handle < 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "[SMS-ARCH]remove content file fail, error = %d\n",file_handle);
        return FALSE;
    }
    else 
    {
        return TRUE;
    }        
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_memset_archive_index_list
 * DESCRIPTION
 *  memset archive index list (mmi_frm_sms_archiveIndex_list[])
 *  guardPattern field will be reset to F2F2F2F2 and other fileds will be 0 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_memset_archive_index_list(void) 
{
    int i=0;
    for (i=0; i<CM_SMS_MAX_ARMSG_NUM; i++)
    {
        mmi_frm_sms_memset_archive_index_entry(&mmi_frm_sms_archiveIndex_list[i]);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_archive_index_list_guard_pattern
 * DESCRIPTION
 *  check archive index list's guard_pattern, if there is one entry's guard pattern is wrong, delete all archive msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_check_archive_index_list_guard_pattern(void)  
{
    int i=0;
    U8 check_result = TRUE;
    for (i=0; i<CM_SMS_MAX_ARMSG_NUM; i++)
    {
        if (memcmp(mmi_frm_sms_archiveIndex_list[i].guardPattern, MMI_FRM_SMS_ARCHIVE_GUARD_PATTERN, 4))   /*if not match*/     
        {
            check_result = FALSE;
            break;
        }
    }    

    if(check_result != TRUE)  /*the file is corrupted, remove all archive files*/
    {
        mmi_frm_sms_memset_archive_index_list(); /*memset mmi_frm_sms_archiveIndex_list*/
        /*remove all archive files*/
        for (i=0; i<CM_SMS_MAX_ARMSG_NUM; i++)
        {
            mmi_frm_sms_remove_archive_content_file((U16)i);
        }
        mmi_frm_sms_update_whole_archive_index_file();
    }

         
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_init_archive_index_List
 * DESCRIPTION
 *  Init archive index list (mmi_frm_sms_archiveIndex_list[])
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE/FASLE : init ok or fail
 *****************************************************************************/
U8 mmi_frm_sms_init_archive_index_List(void)
{

    FS_HANDLE file_handle;
    S8 filename_buff_ucs2[(MMI_SMS_MAX_ARCH_PATH_LEN + 1 +4) * ENCODING_LENGTH];
    S8 filename_buff_ascii[MMI_SMS_MAX_ARCH_PATH_LEN +4];
    U32 read_size =0, write_size = 0;

    mmi_frm_sms_memset_archive_index_list();  

    memset(filename_buff_ucs2, 0, sizeof(filename_buff_ucs2));
    memset(filename_buff_ascii, 0, sizeof(filename_buff_ascii));
    sprintf(filename_buff_ascii, "%c:%s%s", (S8)MMI_SYSTEM_DRV, MMI_SMS_ARCH_SYS_PATH, "idx.a");
    mmi_asc_to_ucs2(filename_buff_ucs2, filename_buff_ascii);

	
    if ((file_handle = FS_Open((U16*)filename_buff_ucs2, FS_READ_WRITE)) == FS_FILE_NOT_FOUND)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "[SMS-ARCH]no idx.a file, create one\n");
        file_handle = FS_Open((U16*)filename_buff_ucs2, FS_CREATE_ALWAYS | FS_READ_WRITE | FS_ATTR_HIDDEN);
        FS_Write(file_handle, mmi_frm_sms_archiveIndex_list, sizeof(mmi_frm_sms_archiveIndex_struct) * CM_SMS_MAX_ARMSG_NUM, &write_size);
        FS_Close(file_handle);
        //remove all files in smsArch folder in public drive
        mmi_frm_sms_recreate_archive_folder_in_public_drv();
		return TRUE;
    }
	
    if (file_handle < 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "[SMS-ARCH]open idx.a fail, error=%d\n",file_handle);
        return FALSE;  
    }        

    if (FS_Read(file_handle, mmi_frm_sms_archiveIndex_list,  sizeof(mmi_frm_sms_archiveIndex_struct) * CM_SMS_MAX_ARMSG_NUM, &read_size) !=  FS_NO_ERROR 
		|| (read_size != sizeof(mmi_frm_sms_archiveIndex_struct) * CM_SMS_MAX_ARMSG_NUM) )
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "[SMS-ARCH]read idx.a fail\n");
        FS_Close(file_handle);			
        return FALSE;
    }
    
    FS_Close(file_handle);
    mmi_frm_sms_check_archive_index_list_guard_pattern();
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_create_archive_list
 * DESCRIPTION
 *  create archive list (construct mmi_frm_sms_archive_list[]) 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *  ** need sorted by time
 *****************************************************************************/
void mmi_frm_sms_create_archive_list(void)
{
    U16 i;

   memset(mmi_frm_sms_archive_list, 0, sizeof(U16) * CM_SMS_MAX_ARMSG_NUM);	
    mmi_frm_sms_archive_size = 0;
    
    for (i = 0; i < CM_SMS_MAX_ARMSG_NUM; i++)
    {
        if (mmi_frm_sms_archiveIndex_list[i].filesize == 0) /*means free*/ 
        {
            continue;
        }
        mmi_frm_sms_add_archive_to_list(&mmi_frm_sms_archiveIndex_list[i], i);
    }
    return;	
}	


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_init_msgbox
 * DESCRIPTION
 *  Init archive box
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE/FASLE : init ok or fail
 *****************************************************************************/
U8 mmi_frm_sms_init_archive(void)
{
    mmi_frm_sms_check_archive_folder_created();
    if (mmi_frm_sms_init_archive_index_List() != FALSE)
    {
        mmi_frm_sms_create_archive_list();
        return TRUE;	
    }
    return FALSE;	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_archive_src_box_type
 * DESCRIPTION
 *  get frombox type in archive
 * PARAMETERS
 *  IN: type  ---MMI_FRM_SMS_INBOX ..etc
 *  IN: index --- the index in archive list (mmi_frm_sms_archive_list) 
 * RETURNS
 *  return which box that the archive msg saved from (mmi_frm_sms_msgbox_enum)
 *****************************************************************************/
mmi_frm_sms_msgbox_enum mmi_frm_sms_get_archive_src_box_type(U16 type, U16 index)
{
    U16 entryindex = index;
    
    switch (type)
    {
        case MMI_FRM_SMS_ARCHIVE:
            entryindex = mmi_frm_sms_archive_list[index];
            break;
        default:
	     MMI_ASSERT(0);
            break;	
    }			
    return (mmi_frm_sms_msgbox_enum) mmi_frm_sms_archiveIndex_list[entryindex].fromboxtype;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_archive_change_status_to_read
 * DESCRIPTION
 *  change archive msg status from unread to read
 * PARAMETERS
 *  IN: type  ---box type
 *  IN: index --- the index in archive list (mmi_frm_sms_archive_list) 
 * RETURNS
 *  return which box that the archive msg saved from (mmi_frm_sms_msgbox_enum)
 *****************************************************************************/
void mmi_frm_sms_archive_change_status_to_read(U16 type, U16 index)
{
    U16 entryindex = index;
    FS_HANDLE fsErrCode; //here, this parameter will not be used
    switch (type)
    {
        case MMI_FRM_SMS_ARCHIVE:
            entryindex = mmi_frm_sms_archive_list[index];
            break;
        default:
	     MMI_ASSERT(0);	
            break;	            
    }            
    mmi_frm_sms_archiveIndex_list[entryindex].fromboxtype = MMI_FRM_SMS_INBOX;
    mmi_frm_sms_update_archive_index_entry( (mmi_frm_sms_archiveIndex_struct *) &mmi_frm_sms_archiveIndex_list[entryindex], entryindex, &fsErrCode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_read_archive_content_file
 * DESCRIPTION
 *  read one archive content file 
 * PARAMETERS
 *  OUT: ArchBuf, store the content 
 *  IN: fileId --- fileid (ex. will save to "00C.a" if fildId=12)
 *  IN fileSize --- how many size we want to read in this file
 * RETURNS
 *  return TRUE or FALSE -- read successfully or not
 *****************************************************************************/
U8 mmi_frm_sms_read_archive_content_file(U8* ArchBuf ,U16 fileId , U16 fileSize)
{

    FS_HANDLE file_handle;
    S8 filename_buff_ucs2[(MMI_SMS_MAX_ARCH_PATH_LEN + 1 +4) * ENCODING_LENGTH];
    S8 filename_buff_ascii[MMI_SMS_MAX_ARCH_PATH_LEN +4]; // for "MMI_PUBLIC_DRV:"
    U32 read_size =0;

    memset(filename_buff_ucs2, 0, sizeof(filename_buff_ucs2));
    memset(filename_buff_ascii, 0, sizeof(filename_buff_ascii));
    sprintf(filename_buff_ascii, "%c:%s%x.a", (S8)MMI_PUBLIC_DRV, MMI_SMS_ARCH_PATH, fileId);
    mmi_asc_to_ucs2(filename_buff_ucs2, filename_buff_ascii);
    
    file_handle = FS_Open((const WCHAR*)filename_buff_ucs2, FS_READ_ONLY);
    if (file_handle > 0)
    {
        if (FS_Read(file_handle, ArchBuf, fileSize, &read_size) == FS_NO_ERROR)
        {
            FS_Close(file_handle);
            return TRUE;
        }		
    }
    FS_Close(file_handle);
    return FALSE;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_fill_object_data
 * DESCRIPTION
 *  fill obj data
 * PARAMETERS
 *  OUT: filled_objData, filled object data 
 *  IN: objType --- object type
 *  IN: rawData --- the data for convert
 *  IN: objDataLen --- how many bytes for this data (start from the in para--rawData) (pdulen and needed info len)
 * RETURNS
 *  return TRUE or FALSE -- convert successfully or not
 *****************************************************************************/
void mmi_frm_sms_fill_object_data(EMSObjData* filled_objData, U8 objType, U8* rawData,  U16 objDataLen)
{
    U16 pos = 0;


    /*1. objDataLen field --> the value includes pdulen and needinfo len  */
    switch (objType)
    {
        case EMS_TYPE_TEXT_FORMAT:
        {
            EMSTextFormat *text_ptr = &(filled_objData->text_format);
            memcpy(text_ptr, rawData, objDataLen); /*avoid alignment and optimize issue*/
        }
        break;


        case EMS_TYPE_PREDEF_SND:  /*the case should not happen, if happen, it still can work*/
        case EMS_TYPE_PREDEF_ANM:
        { 	
			/*don nothing*/
        }
        break;

        case EMS_TYPE_USERDEF_SND:
        {
            EMSSound *snd_ptr = &(filled_objData->sound);	
            U16 pdu_length = 0;
            U8   attribute = 0;	         
            memcpy(&pdu_length, rawData, sizeof(U16));
            pos= pos + sizeof(U16);	
            snd_ptr->pdu_length = pdu_length;	
			
            memcpy(&attribute, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            snd_ptr->attribute= attribute;		
	     /* in order to avoid sizeof alignment issue, so not use pos, use as following*/	
	     /* objDataLen - pic_ptr->pdu_length) is field for need info*/
	     snd_ptr->pdu = rawData  + (objDataLen - snd_ptr->pdu_length);	  
        }
        break;

        case EMS_TYPE_USERDEF_ANM:
        {
            EMSAnim *anm_ptr = &(filled_objData->animation);
            U16 tmp_value_16 = 0;
            U8   tmp_value_8 = 0;	
            memcpy(&tmp_value_16, rawData, sizeof(U16));
            pos= pos + sizeof(U16);	
            anm_ptr->pdu_length = tmp_value_16;	
			
            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            anm_ptr->attribute = tmp_value_8;	

            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            anm_ptr->bitsPerPixel = tmp_value_8;	

            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            anm_ptr->vDim = tmp_value_8;	

            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            anm_ptr->hDim = tmp_value_8;	

            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            anm_ptr->cFrame = tmp_value_8;	

            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            anm_ptr->cRepeat = tmp_value_8;	

            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            anm_ptr->Duration = tmp_value_8;				
			
            /* in order to avoid sizeof alignment issue, so not use pos, use as following	*/
	     /* (objDataLen - pic_ptr->pdu_length) is field for need info*/
	     anm_ptr->pdu = rawData +  (objDataLen - anm_ptr->pdu_length);		
        }
        break;

        case EMS_TYPE_PIC:
        {
            EMSPicture *pic_ptr = &(filled_objData->picture);
            U16 tmp_value_16 = 0;
            U8   tmp_value_8 = 0;			
            memcpy(&tmp_value_16, rawData, sizeof(U16));
            pos= pos + sizeof(U16);	
            pic_ptr->pdu_length = tmp_value_16;	
			
            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            pic_ptr->attribute = tmp_value_8;	
			
            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            pic_ptr->bitsPerPixel = tmp_value_8;	

            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            pic_ptr->vDim = tmp_value_8;		
			
            memcpy(&tmp_value_8, rawData + pos, sizeof(U8));	
            pos = pos + sizeof(U8);
            pic_ptr->hDim = tmp_value_8;	
	     /* in order to avoid sizeof alignment issue, so not use pos, use as following	*/
	     /* (objDataLen - pic_ptr->pdu_length) is field for need info*/
	     pic_ptr->pdu = rawData +  (objDataLen - pic_ptr->pdu_length);	    	 
        }
        break;		
		
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_object_basic_info
 * DESCRIPTION
 *  read one archive content file 
 * PARAMETERS
 *  IN: raw_data, the content we want to convert 
 *  OUT: Type,
 *  OUT: PredefNo, 
 *  OUT: OffsetToText
 *  OUT: how many byte following for this object (needed info and pdu_data)
 * RETURNS
 *  return moved bye numbers
 *****************************************************************************/
U16 mmi_frm_sms_get_object_basic_info(U8 *raw_data, U8* Type, U8* PredefNo, U16* OffsetToText, U16* objDataLen)
{
        U16 pos = 0;
        U8 out_type = 0, out_predefNo = 0;
        U16 out_offsetToText = 0; 		
        U16 out_objDataLen = 0;		
        memcpy(&out_type,  raw_data, sizeof(U8)); 
        pos++;		
        memcpy(&out_predefNo, raw_data+pos, sizeof(U8));
        pos++;
        memcpy(&out_offsetToText, raw_data+pos, sizeof(U16));	
        pos = pos + sizeof(U16);
        memcpy(&out_objDataLen, raw_data+pos, sizeof(U16));	
        pos = pos + sizeof(U16);	
		
        *Type = out_type;
        *PredefNo = out_predefNo;	
        *OffsetToText = out_offsetToText;
        *objDataLen = out_objDataLen;
	 return pos;	
}



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_convert_to_EMS
 * DESCRIPTION
 *  convert to EMS 
 * PARAMETERS
 *  IN: ArchBuf, the content we want to convert 
 *  IN: objNum --- object number
 *  IN fileSize --- how many size we want to read in this file  //no use here, but can use this to check error in the future
 * RETURNS
 *  return TRUE or FALSE -- convert successfully or not
 *****************************************************************************/
U8 mmi_frm_sms_convert_to_EMS(U8* ArchBuf, U8 dcs, U16 objNum, U16 fileSize)
{

    U16 raw_currOffset = 0; 
    EMSData *pEMSdata;
    int i =0;
    U16 textLen = 0;
    U8   obj_Type = 0, obj_PredefNo = 0; 	        	
    U16 obj_OffsetToText = 0, obj_objDataLen = 0, handled_bytes = 0;  	
    U16 movedBytes = 0; /*include needinfo, + pdulen (not include the field for storing the value)*/
    EMSObjData objData;
    EMSTextFormat *tf_ptr;
    U8 *text_string_head; /*pointer to the start position of text string*/	
    U16 nonTextObj_num = 0;	
	
    /*1. handle text part*/
    memcpy(&textLen, ArchBuf, sizeof(U16)); 
    raw_currOffset = raw_currOffset + sizeof(U16);	
    text_string_head = ArchBuf + raw_currOffset;
	
    GetEMSDataForView(&pEMSdata, 1);    /* force to clear old content and initialize */	
    ResetCurrentPosition(pEMSdata);

    /*hendle dcs for text*/
    pEMSdata->dcs = dcs;
    pEMSdata->ps_dcs = dcs;
    if((textLen > 0) && (objNum == 0)) /*mean there is only text data*/
    {
         AddString(
                pEMSdata,
                (U8*)(ArchBuf+raw_currOffset),
                (U16)(textLen/2),  /*number of chacters ( ex."A", textLen =2, but addString paramter should 1)*/
                NULL);

         return TRUE;
    }

    /* there are objects*/
    raw_currOffset = raw_currOffset + textLen; /*now, offset for start pos of  obj related data in raw data */

    /*2. handle object*/	
    /*2-1: first round, scan all and only handle textformat obj*/
   	
    for( i = objNum; i > 0; i--)
    {
        movedBytes = mmi_frm_sms_get_object_basic_info(ArchBuf+raw_currOffset, &obj_Type, &obj_PredefNo, 
                                                                                     &obj_OffsetToText, &obj_objDataLen);
        raw_currOffset = raw_currOffset + movedBytes; /* --> need_info pdu_data  */
	 	
        

        if (obj_Type == EMS_TYPE_TEXT_FORMAT)
        {
            memset(&objData, 0, sizeof(EMSObjData));  
            mmi_frm_sms_fill_object_data(&objData, EMS_TYPE_TEXT_FORMAT, ArchBuf + raw_currOffset, obj_objDataLen);
           
            tf_ptr = &(objData.text_format);
            			
            /*add the text with no textformat 	(previous)*/
            AddString(pEMSdata, (U8*)(text_string_head + handled_bytes), (U16)((obj_OffsetToText -handled_bytes) / 2), NULL);		
            handled_bytes = obj_OffsetToText;		
            /*add string affected by textformat*/		  			
            AddString(pEMSdata, (U8*)(text_string_head + handled_bytes), (U16)((tf_ptr->textLength) / 2), tf_ptr);	
            handled_bytes = handled_bytes + tf_ptr->textLength;	     		           
        }
        raw_currOffset = raw_currOffset + obj_objDataLen; /*offset for point to next obj in raw data	-->(objDataLen needed_info pdu_data)*/
    }
    /*2-2 handle the string which is not covered by text object*/
    if(handled_bytes != textLen)
    {
        AddString(pEMSdata, (U8*)(text_string_head + handled_bytes), (U16)((textLen -handled_bytes) / 2), NULL);	     
    }
	
    /*2-3: second round, scan all and handle non-textformat obj*/
    raw_currOffset = sizeof(U16) + textLen;  /*now, offset for start pos of  obj related data in raw data */
    
    for( i = objNum; i > 0; i--)
    {
        movedBytes = mmi_frm_sms_get_object_basic_info(ArchBuf+raw_currOffset, &obj_Type, &obj_PredefNo, 
                                                                                     &obj_OffsetToText, &obj_objDataLen);
        raw_currOffset = raw_currOffset + movedBytes; /* --> need_info pdu_data */ 
        if(obj_Type == EMS_TYPE_TEXT_FORMAT)
        {
            raw_currOffset = raw_currOffset + obj_objDataLen; /*now, offset for start pos of  obj related data in raw data */
            continue;
        }
		
        memset(&objData, 0, sizeof(EMSObjData)); 
        ResetCurrentPosition(pEMSdata);
        if( (obj_Type == EMS_TYPE_PREDEF_SND) || (obj_Type == EMS_TYPE_PREDEF_ANM) )
        {      
            ForwardCurrentPosition(pEMSdata, (U16)((obj_OffsetToText / 2) + nonTextObj_num));	    
            AddObject(pEMSdata, obj_Type, NULL,obj_PredefNo);       
 			
        }
        else
        {        
            mmi_frm_sms_fill_object_data(&objData, obj_Type, ArchBuf+raw_currOffset, obj_objDataLen);
            ForwardCurrentPosition(pEMSdata, (U16)((obj_OffsetToText / 2) + nonTextObj_num) );	 
            AddObject(pEMSdata, obj_Type, &objData, obj_PredefNo);     			            			
        }
        nonTextObj_num ++;		
        raw_currOffset = raw_currOffset + obj_objDataLen; /*now, offset for start pos of  obj related data in raw data */
    }
	   
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_one_archive_msg
 * DESCRIPTION
 *  get one archive msg (read from file and convert to EMS structure. )
 * PARAMETERS
 *  IN: index --- the index in archive list (mmi_frm_sms_archive_list) 
 * RETURNS
 *  return MMI_TRUE or MMI_FALSE to mean get successfully or not
 *****************************************************************************/
U8 mmi_frm_sms_get_one_archive_msg(U16 index)
{
    U8* smsArchBuf = NULL;
    U16 entryindex = mmi_frm_sms_archive_list[index];
    U8 readResult = FALSE;	
	U16 filesize = MMI_SMS_MAX_ARCH_BUF_SIZE;
	
	if (filesize < mmi_frm_sms_archiveIndex_list[entryindex].filesize)
	{
		filesize = mmi_frm_sms_archiveIndex_list[entryindex].filesize;
	}
    smsArchBuf = (U8*)applib_mem_screen_alloc(filesize);
    memset((S8*) smsArchBuf, 0, filesize);	       
    /*1. read corresponding file from flash    */
    readResult = mmi_frm_sms_read_archive_content_file(smsArchBuf,  entryindex, 
                                    mmi_frm_sms_archiveIndex_list[entryindex].filesize);
	
    /*2. convert to EMS structure if read from file successfully  */
    if(readResult)
    {
        mmi_frm_sms_convert_to_EMS(smsArchBuf, 
                                    mmi_frm_sms_archiveIndex_list[entryindex].dcs,
                                    mmi_frm_sms_archiveIndex_list[entryindex].objectnum, 
                                    mmi_frm_sms_archiveIndex_list[entryindex].filesize); 		
    }	
    /*3. free memory*/		
    applib_mem_screen_free(smsArchBuf);
    return readResult;
}



/*remove the idx from list (mmi_frm_sms_archive_list)*/
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_remove_archive_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_remove_archive_from_list(U16 index)
{
    U16 j = 0;

    for (j = index; j < (mmi_frm_sms_archive_size - 1); j++)
    {
        mmi_frm_sms_archive_list[j] = mmi_frm_sms_archive_list[j + 1];
    }
    mmi_frm_sms_archive_list[j] = 0;
    mmi_frm_sms_archive_size--;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_remove_one_archive_msg
 * DESCRIPTION
 *  remove one archive msg
 * PARAMETERS
 *  IN:  index   --- the index in archivelist (mmi_frm_sms_archive_list)
 *  IN:  type --- for future enhance (diff archive boxes)
 * RETURNS
 *  return TRUE or FALSE to mean remove one entry ok or not
 *****************************************************************************/
U8 mmi_frm_sms_remove_one_archive_msg(U16 type, U16 index)
{
    U16 entryIndex;
    U8 result = FALSE;
    FS_HANDLE fsErrCode; //here, this parameter will not be used
    mmi_frm_sms_archiveIndex_struct archIndex_entry;
    if(type != MMI_FRM_SMS_ARCHIVE)
    {
        return FALSE;
    }
    else
    {
         entryIndex =  mmi_frm_sms_archive_list[index];
    }

    /* 1. remove corresponding content file*/
    result = mmi_frm_sms_remove_archive_content_file(entryIndex);
    if (result != TRUE) /*archive content file removed fail*/
    {
        return FALSE;
    }	    
    /* 2. update corresponding entry in  index file */
    mmi_frm_sms_memset_archive_index_entry(&archIndex_entry);
    result = mmi_frm_sms_update_archive_index_entry(&archIndex_entry, entryIndex, &fsErrCode);    /*fileId=2 save to "002.a" in [2] */
    if (result != TRUE) /*archive index file does not modified*/
    {
        return FALSE;
    }	
    /* 3. update corresponding entry in memory	*/
    memcpy((S8*) &mmi_frm_sms_archiveIndex_list[entryIndex], (S8*)&archIndex_entry, sizeof(mmi_frm_sms_archiveIndex_struct));

    /* 4. remove it from arch list*/
    mmi_frm_sms_remove_archive_from_list(index);     
    
    return TRUE;
}

/* to save time, so not loop call mmi_frm_sms_remove_one_archive_entry API to do this
   type is for future enhance (diff archive boxes)
   till need consider if to seprate remove content to another loop */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_remove_all_archive_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_frm_sms_remove_all_archive_msg(U16 type)  
{    

    int i;
    U16 entryNum = mmi_frm_sms_archive_size; 	
    U16 entryIndex;
    U8 delAll_result = TRUE;
    
    if (type != MMI_FRM_SMS_ARCHIVE)
    {
        MMI_ASSERT(0);
        return FALSE;
    }

    /*1. remove content files, update index list in memory */
    for (i = 0; i < entryNum; i++)
    {
        entryIndex =  mmi_frm_sms_archive_list[i];
        if (mmi_frm_sms_remove_archive_content_file(entryIndex) != TRUE)
        {
            delAll_result = FALSE;
        }
        else /*remove ok*/
        {
            /* update corresponding entry in memory	*/
            mmi_frm_sms_memset_archive_index_entry(&mmi_frm_sms_archiveIndex_list[entryIndex]);
            /* !!! Can't use mmi_frm_sms_remove_archive_from_list here, because entryIndex is got from mmi_frm_sms_archive_list*/
        }
    }

    /*2. re-arrange mmi_frm_sms_archive_list and re-count mmi_frm_sms_archive_size */
    if(delAll_result) /* mean all content files are removed successfully*/
    {
        memset(mmi_frm_sms_archive_list, 0, sizeof(U16) * CM_SMS_MAX_ARMSG_NUM);
        mmi_frm_sms_archive_size = 0;
    }
    else
    {
        mmi_frm_sms_create_archive_list();          
    }
    
    /*3. update to index file   */
    if (mmi_frm_sms_update_whole_archive_index_file() != TRUE)
    {
        delAll_result = FALSE;
    }	

    return delAll_result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_archive_del_folder_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_frm_sms_get_archive_del_folder_result(void)
{
    return g_mmi_frm_sms_archive_del_folder_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_clear_archive_del_folder_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_clear_archive_del_folder_result(void)
{
    g_mmi_frm_sms_archive_del_folder_result = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_archive_del_folder_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_archive_del_folder_result(MMI_BOOL result)
{
    g_mmi_frm_sms_archive_del_folder_result = result;
}

#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_unsent_sms_waitting_index
 * DESCRIPTION
 *  get sms index array, in sequence
 * PARAMETERS
 *  index        [?]         index
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_frm_sms_get_unsent_sms_waitting_index(U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S16 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[SmsUitl.c] mmi_frm_sms_get_unsent_sms_waitting_index start*\n");
    if (index == NULL)
    {
        return FALSE;
    }
    
    for (i = mmi_frm_sms_unsent_size - 1; i >= 0; i--)
    {
        if (mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[i]].send_status == MMI_FRM_SMS_WAITING)
        {
            *index = i;
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"* index: %d, msgindex: %d *\n", *index, mmi_frm_sms_unsent_list[i]);
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_move_sms_from_msgbox
 * DESCRIPTION
 *  add sms to msgbox
 * PARAMETERS
 *  type        [?]         
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_move_sms_from_msgbox(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_frm_sms_list_done)
    {
        mmi_frm_sms_add_sms_to_list(&mmi_frm_sms_msg_box[index], index);
        mmi_frm_sms_remove_sms_from_list(index, type);
    }
}


#endif

#ifdef __MMI_DUAL_SIM_MASTER__
MMI_BOOL mmi_frm_sms_record_is_slave_sms(U16 box, U16 index)
{
    MMI_BOOL result = FALSE;
    U16 startindex = index;
    U16 endindex = index + 1;
    U16 entryindex = 0;
    U16 L4index = 0;
    U16 currIndex = 0;

    if (box & MMI_FRM_SMS_AWAITS)
    {
        entryindex = index;
        L4index = entryindex;
        if (L4index >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
        {
            result = TRUE;
        }
    }

    if ((box & MMI_FRM_SMS_INBOX) || (box & MMI_FRM_SMS_UNREAD))
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_inbox_size;
            currIndex = g_msg_cntx.currBoxIndex;
            entryindex = mmi_frm_sms_inbox_list[currIndex];
            if (mmi_frm_sms_msg_box[entryindex].startindex >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                result = TRUE;
            }
        }
        else
        {
            entryindex = mmi_frm_sms_inbox_list[startindex];
            if (mmi_frm_sms_msg_box[entryindex].startindex >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                result = TRUE;
            }
        }
    }
    if ((box & MMI_FRM_SMS_OUTBOX)
#ifndef __MMI_MESSAGES_DRAFT_BOX__
        || (box & MMI_FRM_SMS_DRAFTS)
#endif
        )
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_outbox_size;
            currIndex = g_msg_cntx.currBoxIndex;
            entryindex = mmi_frm_sms_outbox_list[currIndex];
            if (mmi_frm_sms_msg_box[entryindex].startindex >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                result = TRUE;
            }
        }
        else
        {
            entryindex = mmi_frm_sms_outbox_list[startindex];
            if (mmi_frm_sms_msg_box[entryindex].startindex >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                result = TRUE;
            }
        }
    }
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    if ((box & MMI_FRM_SMS_DRAFTS))
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_drafts_size;
            currIndex = g_msg_cntx.currBoxIndex;
            entryindex = mmi_frm_sms_drafts_list[currIndex];
            if (mmi_frm_sms_msg_box[entryindex].startindex >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                result = TRUE;
            }
        }
        else
        {
            entryindex = mmi_frm_sms_drafts_list[startindex];
            if (mmi_frm_sms_msg_box[entryindex].startindex >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                result = TRUE;
            }
        }
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */

#ifdef __MMI_UNIFIED_MESSAGE__
    if ((box & MMI_FRM_SMS_UNSENT))
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_unsent_size;
            currIndex = g_msg_cntx.currBoxIndex;
            entryindex = mmi_frm_sms_unsent_list[currIndex];
            if (mmi_frm_sms_msg_box[entryindex].startindex >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                result = TRUE;
            }
        }
        else
        {
            entryindex = mmi_frm_sms_unsent_list[startindex];
            if (mmi_frm_sms_msg_box[entryindex].startindex >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                result = TRUE;
            }
        }
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if ((box & MMI_FRM_SMS_SIM))
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_simbox_size;
            currIndex = g_msg_cntx.currBoxIndex;
            entryindex = mmi_frm_sms_sim_list[currIndex];
            if (mmi_frm_sms_msg_box[entryindex].startindex >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                result = TRUE;
            }
        }
        else
        {
            entryindex = mmi_frm_sms_sim_list[startindex];
            if (mmi_frm_sms_msg_box[entryindex].startindex >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                result = TRUE;
            }
        }
    }

#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    return result;
}

U8 mmi_frm_sms_get_slave_sms_bitmap(U16 type, U16 index, U8 * l4_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 startindex = index;
    U16 endindex = index + 1;
    U16 entryindex = 0;
    U16 L4index = 0;
    U16 currIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_list_done == FALSE || (!MTPNP_AD_Card2_SMS_Is_Load_Finished()))
    {
        return FALSE;
    }

    if (type & MMI_FRM_SMS_NOBOX)
    {
        if (index >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
        {
            index = MTPNP_AD_Get_SIM2_Index(index);
        }
        mmi_frm_sms_set_bitmap(index, l4_index);
    }

    if (type & MMI_FRM_SMS_AWAITS)
    {
        for (i = startindex; i < endindex; i++)
        {
            entryindex = index;
            L4index = entryindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                currIndex = L4index;
                if (L4index >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
                {
                    L4index = MTPNP_AD_Get_SIM2_Index(L4index);
                }
                else
                {
                    L4index = MMI_FRM_SMS_INVALID_INDEX;
                    continue;
                }
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = currIndex;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }

    if ((type & MMI_FRM_SMS_INBOX) || (type & MMI_FRM_SMS_UNREAD))
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_inbox_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_inbox_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                currIndex = L4index;
                if (L4index >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
                {
                    L4index = MTPNP_AD_Get_SIM2_Index(L4index);
                }
                else
                {
                    L4index = MMI_FRM_SMS_INVALID_INDEX;
                    continue;
                }
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = currIndex;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
    if ((type & MMI_FRM_SMS_OUTBOX)
#ifndef __MMI_MESSAGES_DRAFT_BOX__
        || (type & MMI_FRM_SMS_DRAFTS)
#endif
        )
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_outbox_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_outbox_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                currIndex = L4index;
                if (L4index >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
                {
                    L4index = MTPNP_AD_Get_SIM2_Index(L4index);
                }
                else
                {
                    L4index = MMI_FRM_SMS_INVALID_INDEX;
                    continue;
                }
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = currIndex;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    if (type & MMI_FRM_SMS_DRAFTS)
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_drafts_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_drafts_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                currIndex = L4index;
                if (L4index >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
                {
                    L4index = MTPNP_AD_Get_SIM2_Index(L4index);
                }
                else
                {
                    L4index = MMI_FRM_SMS_INVALID_INDEX;
                    continue;
                }
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = currIndex;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */

#ifdef __MMI_UNIFIED_MESSAGE__
    if (type & MMI_FRM_SMS_UNSENT)
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_unsent_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_unsent_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                currIndex = L4index;
                if (L4index >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
                {
                    L4index = MTPNP_AD_Get_SIM2_Index(L4index);
                }
                else
                {
                    L4index = MMI_FRM_SMS_INVALID_INDEX;
                    continue;
                }
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = currIndex;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (type & MMI_FRM_SMS_SIM)
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_simbox_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_sim_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX)
            {
                currIndex = L4index;
                if (L4index >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
                {
                    L4index = MTPNP_AD_Get_SIM2_Index(L4index);
                }
                else
                {
                    L4index = MMI_FRM_SMS_INVALID_INDEX;
                    continue;
                }
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = currIndex;
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    return TRUE;
}

U8 mmi_frm_sms_get_master_sms_bitmap(U16 type, U16 index, U8 *l4_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 startindex = index;
    U16 endindex = index + 1;
    U16 entryindex = 0;
    U16 L4index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_list_done == FALSE  || (!MTPNP_AD_Card2_SMS_Is_Load_Finished()))
    {
        return FALSE;
    }

    if (type & MMI_FRM_SMS_NOBOX)
    {
        mmi_frm_sms_set_bitmap(index, l4_index);
    }

    if (type & MMI_FRM_SMS_AWAITS)
    {
        for (i = startindex; i < endindex; i++)
        {
            entryindex = index;
            L4index = entryindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX &&
                    L4index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }

    if ((type & MMI_FRM_SMS_INBOX) || (type & MMI_FRM_SMS_UNREAD))
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_inbox_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_inbox_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX &&
                    L4index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
    if ((type & MMI_FRM_SMS_OUTBOX)
#ifndef __MMI_MESSAGES_DRAFT_BOX__
        || (type & MMI_FRM_SMS_DRAFTS)
#endif 
        )
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_outbox_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_outbox_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX &&
                    L4index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    if (type & MMI_FRM_SMS_DRAFTS)
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_drafts_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_drafts_list[i];
            L4index = mmi_frm_sms_msg_box[entryindex].startindex;
            while (L4index != MMI_FRM_SMS_INVALID_INDEX &&
                    L4index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                mmi_frm_sms_set_bitmap(L4index, l4_index);
                L4index = mmi_frm_sms_index_list[L4index].nextindex;
            }
        }
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */

#ifdef __MMI_UNIFIED_MESSAGE__
    if (type & MMI_FRM_SMS_UNSENT)
    {
    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        BOOL isOnlySending = TRUE;
	#endif
        
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_unsent_size;
        }
        for (i = startindex; i < endindex; i++)
        {
            entryindex = mmi_frm_sms_unsent_list[i];
		#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            if (mmi_frm_sms_msg_box[entryindex].send_status != MMI_FRM_SMS_SENDING)
            {
                isOnlySending = FALSE;
				mmi_frm_sms_msg_box[entryindex].send_status = MMI_FRM_SMS_FAILTOSEND;
		#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
                L4index = mmi_frm_sms_msg_box[entryindex].startindex;
                while (L4index != MMI_FRM_SMS_INVALID_INDEX &&
                    L4index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
                {
                    mmi_frm_sms_set_bitmap(L4index, l4_index);
                    L4index = mmi_frm_sms_index_list[L4index].nextindex;
                }
		#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            }
		#endif
        }
	#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        if (isOnlySending && mmi_frm_sms_unsent_size > 0)
        {
            return (U8)MMI_FRM_SMS_NOT_DELETE_SENDING;
        }
	#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if ((type & MMI_FRM_SMS_SIM))
    {
        if (index == MMI_FRM_SMS_INVALID_INDEX)
        {
            startindex = 0;
            endindex = mmi_frm_sms_simbox_size;
        }
        if (mmi_frm_sms_sim_list != NULL)
        {
            for (i = startindex; i < endindex; i++)
            {
                entryindex = mmi_frm_sms_sim_list[i];
                L4index = mmi_frm_sms_msg_box[entryindex].startindex;
                while (L4index != MMI_FRM_SMS_INVALID_INDEX &&
                    L4index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
                {
                    mmi_frm_sms_set_bitmap(L4index, l4_index);
                    L4index = mmi_frm_sms_index_list[L4index].nextindex;
                }
            }
        }
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 

    return TRUE;
}

void mmi_frm_sms_remove_slave_sms_from_msgbox(U8 * data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *index_bitmap = (U8 *) data;
    U16 index = mmi_frm_sms_get_index(0, index_bitmap);
    U16 remove_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (index != MMI_FRM_SMS_INVALID_INDEX)
    {
        remove_index = MTPNP_AD_Set_SIM2_Index(index);
        mmi_frm_sms_remove_sms_entry(remove_index);
        index++;
        index = mmi_frm_sms_get_index(index, index_bitmap);
    }
    return;
}

U16 mmi_frm_get_sms_action_size(void)
{
    return MMI_FRM_SMS_ACTION_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_msg_set_send_data
 * DESCRIPTION
 *  Entry send only screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_msg_set_send_data(PsFuncPtrU16 callback, module_type mod_src, mmi_frm_sms_send_struct *sendData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_pSendData = sendData;
	g_callback = callback;
	g_mod_src = mod_src;
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_send_only
 * DESCRIPTION
 *  Entry send only screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_msg_entry_send_from_SIM1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_frm_sms_check_action_pending() == TRUE)
	{
		
        if (g_pSendData->string != NULL)
        {
            OslMfree(g_pSendData->string);
            g_pSendData->string = NULL;
        }				
        g_callback(NULL, (module_type) g_mod_src, MMI_FRM_SMS_NOTREADY);       
	}
	else
	{
	    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
	    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
		g_pSendData->sendrequire &= ~MMI_FRM_SMS_DISP_SIM_OPT;
		mmi_frm_sms_send_sms(g_callback, g_mod_src, g_pSendData);
	}
	if (g_pSendData != NULL)
	{	
		OslMfree(g_pSendData);
		g_pSendData = NULL;
	}		
}



/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_send_only
 * DESCRIPTION
 *  Entry send only screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_msg_entry_send_from_SIM2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_frm_sms_check_action_pending() == TRUE)
	{
		
        if (g_pSendData->string != NULL)
        {
            OslMfree(g_pSendData->string);
            g_pSendData->string = NULL;
        }				
        g_callback(NULL, (module_type) g_mod_src, MMI_FRM_SMS_NOTREADY);        
	}
	else
	{
	    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
	    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
		g_pSendData->sendrequire &= ~MMI_FRM_SMS_DISP_SIM_OPT;
		mmi_frm_sms_send_sms(g_callback, g_mod_src, g_pSendData);
	}
	if (g_pSendData != NULL)
	{	
		OslMfree(g_pSendData);
		g_pSendData = NULL;
	}		
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_from_SIM1
 * DESCRIPTION
 *  Highlight send from SIM1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_from_SIM1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_frm_msg_entry_send_from_SIM1,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_from_SIM2
 * DESCRIPTION
 *  Highlight send from SIM1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_from_SIM2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_frm_msg_entry_send_from_SIM2,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_Select_option_screen
 * DESCRIPTION
 *  enter sms option screen
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_msg_entry_Select_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[2];        /* Stores the strings id of submenus returned */
    U16 nNumofItem;             /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_msg_entry_Select_option_screen: %d", MTPNP_AD_Get_UsableSide());
	
    EntryNewScreen(SCR_MTPNP_SMS_SELECT_OPTION, NULL, NULL, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_SMS_SELECT_OPTION);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_SMS_SELECT_OPTION);

    /* 4. Get attribute of menu to be displayed */
//      nDispAttribute = GetDispAttributeOfItem(MENU8234_FDL_VIEW_OPTIONS_MAIN  );
    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_MTPNP_SMS_SELECT_OPTION, nStrItemList);
    //GetSequenceImageIds(SLAVE_MENU_CC_MO_SELETECT_NET     , nImageItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_MTPNP_SMS_SELECT_OPTION);
    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* 8 Display Category15 Screen */
    ShowCategory15Screen(STR_GLOBAL_OPTIONS, 0,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (PU16) gIndexIconsImageList, LIST_MENU, 0, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_msg_entry_save_from_SIM1
 * DESCRIPTION
 *  Entry save only screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_msg_entry_save_from_SIM1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_frm_sms_check_action_pending() == TRUE)
	{
		
        if (g_pSendData->string != NULL)
        {
            OslMfree(g_pSendData->string);
            g_pSendData->string = NULL;
        }				
        g_callback(NULL, (module_type) g_mod_src, MMI_FRM_SMS_NOTREADY);       
	}
	else
	{
	    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
	    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
		g_pSendData->sendrequire &= ~MMI_FRM_SMS_DISP_SIM_OPT;
		mmi_frm_sms_save_sms(g_callback, g_mod_src, g_pSendData);
	}
	if (g_pSendData != NULL)
	{	
		OslMfree(g_pSendData);
		g_pSendData = NULL;
	}		
}



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_msg_entry_save_from_SIM2
 * DESCRIPTION
 *  Entry save only screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_msg_entry_save_from_SIM2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_frm_sms_check_action_pending() == TRUE)
	{
		
        if (g_pSendData->string != NULL)
        {
            OslMfree(g_pSendData->string);
            g_pSendData->string = NULL;
        }				
        g_callback(NULL, (module_type) g_mod_src, MMI_FRM_SMS_NOTREADY);        
	}
	else
	{
	    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
	    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
		g_pSendData->sendrequire &= ~MMI_FRM_SMS_DISP_SIM_OPT;
		mmi_frm_sms_save_sms(g_callback, g_mod_src, g_pSendData);
	}
	if (g_pSendData != NULL)
	{	
		OslMfree(g_pSendData);
		g_pSendData = NULL;
	}		
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_save_from_SIM1
 * DESCRIPTION
 *  Highlight save from SIM1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_save_from_SIM1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_frm_msg_entry_save_from_SIM1,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_save_from_SIM2
 * DESCRIPTION
 *  Highlight save from SIM2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_save_from_SIM2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_frm_msg_entry_save_from_SIM2,
        GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_select_save_option_screen
 * DESCRIPTION
 *  enter save sms option screen
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_select_save_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[2];        /* Stores the strings id of submenus returned */
    U16 nNumofItem;             /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_msg_entry_select_save_option_screen: %d", MTPNP_AD_Get_UsableSide());
	
    EntryNewScreen(SCR_MTPNP_SMS_SAVE_SELECT_OPTION, NULL, NULL, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_SMS_SAVE_SELECT_OPTION);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_SMS_SELECT_SAVE_OPTION);

    /* 4. Get attribute of menu to be displayed */
//      nDispAttribute = GetDispAttributeOfItem(MENU8234_FDL_VIEW_OPTIONS_MAIN  );
    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_MTPNP_SMS_SELECT_SAVE_OPTION, nStrItemList);
    //GetSequenceImageIds(SLAVE_MENU_CC_MO_SELETECT_NET     , nImageItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_MTPNP_SMS_SELECT_SAVE_OPTION);
    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* 8 Display Category15 Screen */
    ShowCategory15Screen(STR_GLOBAL_OPTIONS, 0,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (PU16) gIndexIconsImageList, LIST_MENU, 0, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_handle_sms_refresh
 * DESCRIPTION
 *  handle sms refresh and remove sms entry:
 * PARAMETERS
 *  index       [IN]        Index
 *  b  addindex    addindex(?)
 *  c  segment     segment(?)
 * RETURNS
 *  index(?)
 *****************************************************************************/
void mmi_frm_sms_handle_sms_refresh(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 previndex, nextindex;
    U16 type = mmi_frm_sms_index_list[index].prevtype;
	U16 i = 0;
    U16 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    previndex = mmi_frm_sms_index_list[index].previndex;
    nextindex = mmi_frm_sms_index_list[index].nextindex;

	if (previndex == MMI_FRM_SMS_INVALID_INDEX)
	{
		return;
	}

    /* chat message is not in message box, so message box should remain unchanged and only delete index list entry */
    /* For message with only one segment, also update msg box and inbox/outbox/draft list */
    if ((type != MMI_FRM_SMS_NOBOX && type != MMI_FRM_SMS_AWAITS && type != MMI_FRM_SMS_DATA) &&
        (nextindex == MMI_FRM_SMS_INVALID_INDEX))
    {        
		switch (type)
	    {
	        case MMI_FRM_SMS_INBOX:
	        case MMI_FRM_SMS_UNREAD:
	            while (i < mmi_frm_sms_inbox_size)
	            {
	                if (mmi_frm_sms_inbox_list[i] == previndex)
	                {
	                    break;
	                }
	                i++;
	            }
	            for (j = i; j < (mmi_frm_sms_inbox_size - 1); j++)
	            {
	                mmi_frm_sms_inbox_list[j] = mmi_frm_sms_inbox_list[j + 1];
	            }
	            mmi_frm_sms_inbox_list[j] = MMI_FRM_SMS_INVALID_INDEX;
	            mmi_frm_sms_inbox_size--;
	            break;

	        case MMI_FRM_SMS_OUTBOX:
	        #ifndef __MMI_MESSAGES_DRAFT_BOX__
	        case MMI_FRM_SMS_DRAFTS:
	        #endif 
	            while (i < mmi_frm_sms_outbox_size)
	            {
	                if (mmi_frm_sms_outbox_list[i] == previndex)
	                {
	                    break;
	                }
	                i++;
	            }
	            for (j = i; j < (mmi_frm_sms_outbox_size - 1); j++)
	            {
	                mmi_frm_sms_outbox_list[j] = mmi_frm_sms_outbox_list[j + 1];
	            }
	            mmi_frm_sms_outbox_list[j] = MMI_FRM_SMS_INVALID_INDEX;
	            mmi_frm_sms_outbox_size--;
	            break;

	        #ifdef __MMI_MESSAGES_DRAFT_BOX__
	        case MMI_FRM_SMS_DRAFTS:
	            while (i < mmi_frm_sms_drafts_size)
	            {
	                if (mmi_frm_sms_drafts_list[i] == previndex)
	                {
	                    break;
	                }
	                i++;
	            }
	            for (j = i; j < (mmi_frm_sms_drafts_size - 1); j++)
	            {
	                mmi_frm_sms_drafts_list[j] = mmi_frm_sms_drafts_list[j + 1];
	            }
	            mmi_frm_sms_drafts_list[j] = MMI_FRM_SMS_INVALID_INDEX;
	            mmi_frm_sms_drafts_size--;
	            break;
	        #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
	        #ifdef __MMI_UNIFIED_MESSAGE__
	        case MMI_FRM_SMS_UNSENT:
	            while (i < mmi_frm_sms_unsent_size)
	            {
	                if (mmi_frm_sms_unsent_list[i] == previndex)
	                {
	                    break;
	                }
	                i++;
	            }
	            for (j = i; j < (mmi_frm_sms_unsent_size - 1); j++)
	            {
	                mmi_frm_sms_unsent_list[j] = mmi_frm_sms_unsent_list[j + 1];
	            }
	            mmi_frm_sms_unsent_list[j] = MMI_FRM_SMS_INVALID_INDEX;
	            mmi_frm_sms_unsent_size--;
	            break;
	        #endif /* __MMI_UNIFIED_MESSAGE__ */         
	        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
	        case MMI_FRM_SMS_SIM:
	            if (mmi_frm_sms_sim_list != NULL)
	            {
	                while (i < mmi_frm_sms_simbox_size)
	                {
	                    if (mmi_frm_sms_sim_list[i] == previndex)
	                    {
	                        break;
	                    }
	                    i++;
	                }
	                for (j = i; j < (mmi_frm_sms_simbox_size - 1); j++)
	                {
	                    mmi_frm_sms_sim_list[j] = mmi_frm_sms_sim_list[j + 1];
	                }
	                mmi_frm_sms_sim_list[j] = MMI_FRM_SMS_INVALID_INDEX;
	                mmi_frm_sms_simbox_size--;
	                }
	            break;
	        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 

	    }
        memset((S8*) & mmi_frm_sms_msg_box[previndex], 0xff, sizeof(mmi_frm_sms_msgbox_struct));
    }
    else
    {
        /* the first segment of message */
        if (type != MMI_FRM_SMS_NOBOX)
        {
            /* for message in awaited list, ex. chat msg,  modify start index of awaitd list entry to next index */
            if (type == MMI_FRM_SMS_AWAITS || type == MMI_FRM_SMS_DATA)
            {
                mmi_frm_sms_awaited[previndex].index = nextindex;
            }

            /* for message in msg box, ex. inbox/outbox/draft  message, modify start index of msg box entry to next index  */
            else
            {
                mmi_frm_sms_msg_box[previndex].startindex = nextindex;
            }
        }

        /* the 2nd or after segment of message */
        else
        {
            mmi_frm_sms_index_list[previndex].nextindex = nextindex;
        }

        if (nextindex != MMI_FRM_SMS_INVALID_INDEX)
        {
            mmi_frm_sms_index_list[nextindex].prevtype = type;
            mmi_frm_sms_index_list[nextindex].previndex = previndex;
        }
    }
    memset((S8*) & mmi_frm_sms_index_list[index], 0xff, sizeof(mmi_frm_sms_index_struct));
}

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MOD_SMSAL__ */
