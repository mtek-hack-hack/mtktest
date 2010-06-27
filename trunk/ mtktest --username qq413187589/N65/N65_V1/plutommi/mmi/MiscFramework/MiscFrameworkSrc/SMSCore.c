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
 *  SMSCore.c
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
#include "CallHistoryGProts.h"
#include "CallManagementGprot.h"
#include "IdleAppProt.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "AlarmFrameworkProt.h"
#include "PhoneBookTypes.h"
#include "PhoneBookGprot.h"
#include "SimDetectionGexdcl.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "NetworkSetupDefs.h"
#include "SimDetectionGProt.h"
/*  */

#include "PhoneBookDef.h"

#include "wgui_status_icons.h"

#include "SMSApi.h"
#include "SMSStruct.h"
#include "SMSFunc.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageGProt.h"
#endif 

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_PFAL_MessageSetup.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_CC.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if 1
#ifndef MMI_FRM_SMS_INVALID_NUM
#define MMI_FRM_SMS_INVALID_NUM     0xff
#endif 
#ifndef MMI_FRM_SMS_ACTION_SIZE
#define MMI_FRM_SMS_ACTION_SIZE     15
#endif 
#ifndef MMI_FRM_SMS_INVALID_INDEX
#define MMI_FRM_SMS_INVALID_INDEX   0xffff
#endif 

#define SWAP(T,A,B) { T TMP = A; A = B; B = TMP; }

static mmi_frm_sms_action_struct mmi_frm_sms_action[MMI_FRM_SMS_ACTION_SIZE];
static U8 mmi_frm_sms_action_head = 0;
static U8 mmi_frm_sms_action_tail = 0;
static U8 mmi_frm_sms_action_num = 0;
static U8 mmi_frm_sms_action_curr = MMI_FRM_SMS_INVALID_NUM;

static mmi_frm_sms_msg_check_struct mmi_frm_sms_msg_check[MMI_FRM_SMS_ACTION_SIZE];
static U8 mmi_frm_sms_msg_check_num = 0;

static mmi_frm_sms_data_check_struct mmi_frm_sms_data_check[MMI_FRM_SMS_ACTION_SIZE];
static U8 mmi_frm_sms_data_check_num = 0;

static U8 mmi_frm_sms_search_phb_type = 0;

mmi_frm_sms_context_struct g_frm_sms_cntx;

#ifdef __MMI_MESSAGES_COPY__
mmi_frm_sms_copy_info_struct g_frm_sms_copy_info;
#endif 

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
PsFuncPtrU16 backgroundSendAbortcallback = NULL;
mmi_frm_sms_background_send_info_struct g_frm_sms_background_send_info;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 

MMI_BOOL g_mmi_frm_sms_change_status = MMI_FALSE;

/*******************************************************

   mmi sms app test code start

*******************************************************/
static msg_ems_data_struct bufForDisplay;
static msg_ems_data_struct bufForEdit;

extern void mmi_phb_frm_enter_send_entry(void);


/*****************************************************************************
 * FUNCTION
 *  InitMessagesEMSBuffer
 * DESCRIPTION
 *  Reset EMS edit/view buffer
 * PARAMETERS
 *  pE          [?]             
 *  force       [IN]            
 *  a(?)        [IN/OUT]        Msg_ems_data_struct EME buffer
 *  b(?)        [IN]            Force to clear
 * RETURNS
 *  EMS buffer valid flag
 *****************************************************************************/
U8 InitMessagesEMSBuffer(msg_ems_data_struct *pE, U8 force)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS retVal;
    U8 oldFlag = pE->validFlag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pE->validFlag == 0) || force)
    {
        if (pE->validFlag)
        {
            retVal = ReleaseEMSData(&pE->emsData);
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[EmsMiscell.c] InitMessagesEMSBuffer: ReleaseEMSData()"
                                 " returns %d-------*\n", (int)retVal);
        }
        retVal = InitializeEMSData(&pE->emsData, 0);    /* = SMSAL_DEFAULT_DCS */
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[EmsMiscell.c] InitMessagesEMSBuffer: InitializeEMSData()"
                             " returns %d, dcs set to 0X%.2X-------*\n", (int)retVal, (int)pE->emsData.dcs);
    }

    pE->validFlag = 1;
    return oldFlag;
}


/*****************************************************************************
 * FUNCTION
 *  DeInitMessagesEMSBuffer
 * DESCRIPTION
 *  Releaset EMS buffer
 * PARAMETERS
 *  pE          [?]             
 *  a(?)        [IN/OUT]        Msg_ems_data_struct EMS buffer
 *  b(?)        [IN]            
 * RETURNS
 *  EMS buffer valid flag
 *****************************************************************************/
U8 DeInitMessagesEMSBuffer(msg_ems_data_struct *pE)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 oldFlag = pE->validFlag;
    EMSTATUS retVal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pE->validFlag)
    {
        retVal = ReleaseEMSData(&pE->emsData);
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[EmsMiscell.c] DeInitMessagesEMSBuffer: ReleaseEMSData()"
                             " returns %d-------*\n", (int)retVal);
    }
    pE->validFlag = 0;
    return oldFlag;
}


/*****************************************************************************
 * FUNCTION
 *  GetEMSDataForView
 * DESCRIPTION
 *  Get EMS view buffer
 * PARAMETERS
 *  p           [IN]        EMS data pointer
 *  force       [IN]        Force to clear
 * RETURNS
 *  EMS buffer for display
 *****************************************************************************/
EMSData *GetEMSDataForView(EMSData **p, U8 force)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p)
    {
        *p = &bufForDisplay.emsData;
    }

    InitMessagesEMSBuffer(&bufForDisplay, force);

    return &bufForDisplay.emsData;
}


/*****************************************************************************
 * FUNCTION
 *  GetEMSDataForEdit
 * DESCRIPTION
 *  Get EMS edit buffer
 * PARAMETERS
 *  p           [IN]        EMS data pointer
 *  force       [IN]        Force to clear
 * RETURNS
 *  EMS buffer for edit
 *****************************************************************************/
EMSData *GetEMSDataForEdit(EMSData **p, U8 force)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p)
    {
        *p = &bufForEdit.emsData;
    }

    InitMessagesEMSBuffer(&bufForEdit, force);
    return &bufForEdit.emsData;
}


/*****************************************************************************
 * FUNCTION
 *  CopyEMSViewToEditBuffer
 * DESCRIPTION
 *  Copy EMS view buffer to edit buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 CopyEMSViewToEditBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReleaseEMSEditBuffer();
    InitMessagesEMSBuffer(&bufForEdit, 1);
    if (bufForDisplay.validFlag)
    {
        result = CopyEMSData(&bufForEdit.emsData, &bufForDisplay.emsData);
        bufForEdit.validFlag = 1;
        if (result == EMS_OK)
        {
            EMSResetPortNum(&bufForEdit.emsData);
            GoToEndPosition(&bufForEdit.emsData);
        }
        else
        {
            ReleaseEMSEditBuffer(); /* because validFlag for edit buffer is 1, it is equivalent to force to realease */
        }
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[SMSCore.c] ERROR : CopyEMSViewToEditBuffer: src buffer uninitialized -------*\n");
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  ReleaseEMSViewBuffer
 * DESCRIPTION
 *  Release EMS view buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReleaseEMSViewBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeInitMessagesEMSBuffer(&bufForDisplay);
}


/*****************************************************************************
 * FUNCTION
 *  ReleaseEMSEditBuffer
 * DESCRIPTION
 *  Release EMS edit buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReleaseEMSEditBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeInitMessagesEMSBuffer(&bufForEdit);
}


/*****************************************************************************
 * FUNCTION
 *  GetRefFromNVRAM
 * DESCRIPTION
 *  Get concatenate reference from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  reference
 *****************************************************************************/
U16 GetRefFromNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 ref;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ReadValue(NVRAM_SMS_CONCAT_MSG_REF_VALUE, (void*)&ref, DS_SHORT, &error) < 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "GetRefFromNVRAM:: Read from NVRAM failed (ecode == %d)", (int)error);
    }
    return ref;
}


/*****************************************************************************
 * FUNCTION
 *  WriteRefToNVRAM
 * DESCRIPTION
 *  Write referemce to NVRAM
 * PARAMETERS
 *  val     [IN]        Reference
 * RETURNS
 *  void
 *****************************************************************************/
static void WriteRefToNVRAM(U16 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WriteValue(NVRAM_SMS_CONCAT_MSG_REF_VALUE, (void*)&val, DS_SHORT, &error) < 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "WriteRefToNVRAM:: Write to NVRAM failed (ecode == %d)", (int)error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  RefGeneratorCallback
 * DESCRIPTION
 *  Call back for reference generator
 * PARAMETERS
 *  void
 * RETURNS
 *  reference
 *****************************************************************************/
static U16 RefGeneratorCallback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 static ref = 65534;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ref == 65534)
    {
        ref = GetRefFromNVRAM();
    }
    ++ref;
    WriteRefToNVRAM(ref);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "RefGeneratorCallback:: New ref number %d", (int)ref);
    return ref;
}


/*****************************************************************************
 * FUNCTION
 *  InitEMSDataStruct
 * DESCRIPTION
 *  Init EMS data structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitEMSDataStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMSInitialize();
#ifdef __EMS_REL5__
#ifdef __EMS_NOT_COMPRESS__
    EMSSetCompressMode(FALSE);
#else /* __EMS_NOT_COMPRESS__ */
    EMSSetCompressMode(TRUE);
#endif /* __EMS_NOT_COMPRESS__ */ 
#endif /* __EMS_REL5__ */ 
    EMSConcatMsgRefFunc(RefGeneratorCallback);
    bufForDisplay.validFlag = 0;
    bufForEdit.validFlag = 0;
#ifdef __MMI_MESSAGES_EMS__
    mmi_ems_create_ems_folder();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  DeInitEMSDataStruct
 * DESCRIPTION
 *  Deinit EMS data structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitEMSDataStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMSDeInitialize();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_reg_interrupt_check
 * DESCRIPTION
 *  Register SMS related interrupt check
 * PARAMETERS
 *  mod             [IN]        Module
 *  msgid           [IN]        Message ID
 *  callback        [IN]        Callback for interrupt
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_reg_interrupt_check(module_type mod, U16 msgid, PsFuncPtrU16 callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_reg_interrupt_handler(mod, msgid, callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_reg_msg_check
 * DESCRIPTION
 *  Register SMS check
 * PARAMETERS
 *  action          [IN]        Check action
 *  callback        [IN]        Callback for interrupt
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_reg_msg_check(PsExtPeerIntFuncPtr action, PsFuncPtrFuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_msg_check[mmi_frm_sms_msg_check_num].action = action;
    mmi_frm_sms_msg_check[mmi_frm_sms_msg_check_num].callback = callback;
    mmi_frm_sms_msg_check_num++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_indicate_sms
 * DESCRIPTION
 *  Indicate new SMS
 * PARAMETERS
 *  index           [IN]        
 *  callback(?)     [IN]        Callback for interrupt
 *  action(?)       [IN]        Check action
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_indicate_sms(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_frm_sms_deliver_msg_struct *data = OslMalloc(sizeof(mmi_frm_sms_deliver_msg_struct));

    /* MMI could only allocate 2K control buffer, so limit the max allocate buffer to 1600 here */
    U16 content_len =
        ((MMI_FRM_SMS_MSG_LEN * g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) <
         (MMI_FRM_SMS_MSG_LEN * 10)) ? (MMI_FRM_SMS_MSG_LEN *
                                        g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) : (MMI_FRM_SMS_MSG_LEN * 10);
    U8 *content = OslMalloc(content_len);
    U8 withobject;
    U8 updatelist = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(content, 0x00, content_len);
    withobject = mmi_frm_sms_get_awaited_sms((U8) index, data, content);
    data->msg_data[0] = (U8) index;

    if (data->display_type == SMSAL_MSG_TYPE_UPDATE_ONLY)
    {
        /* default indication here */
        mmi_frm_sms_msgbox_struct *entry = OslMalloc(sizeof(mmi_frm_sms_msgbox_struct));

        //mmi_frm_sms_concat_struct* concatinfo = (mmi_frm_sms_concat_struct*)&(data->concat_info);
        //U8 segment=((concatinfo->seg%g_frm_sms_cntx.mmi_frm_sms_msg_seg_size)==0)?
        //g_frm_sms_cntx.mmi_frm_sms_msg_seg_size:(concatinfo->seg%g_frm_sms_cntx.mmi_frm_sms_msg_seg_size);
        U8 segment = mmi_frm_sms_index_list[data->index].segment;

        mmi_frm_sms_convert_mt_to_entry(data, entry);

    #ifdef __MMI_UNIFIED_MESSAGE__
        memset(entry->content, 0, sizeof(entry->content));
        if (data->dcs == SMSAL_UCS2_DCS)
        {
            if (mmi_ucs2strlen((S8*) content))
            {
                mmi_frm_sms_add_content_to_entry(entry, content);
            }
        }
        else
        {
            if (strlen((S8*) content))
            {
                U8 *ucs2_content = NULL;
                U16 ucs2_content_len = 0;

                ucs2_content_len = ((mmi_msg_get_max_content_size() + 1) * ENCODING_LENGTH);
                ucs2_content = OslMalloc(ucs2_content_len);
                memset(ucs2_content, 0, ucs2_content_len);
                mmi_asc_n_to_ucs2((S8*) ucs2_content, (S8*) content, (U32) mmi_msg_get_max_content_size());
                mmi_frm_sms_add_content_to_entry(entry, ucs2_content);
                OslMfree(ucs2_content);
            }
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 

        mmi_frm_sms_add_sms_to_msgbox(entry, data->index, segment);
        OslMfree(entry);
    }
    else
    {
        while (i < mmi_frm_sms_msg_check_num)
        {
            if (mmi_frm_sms_msg_check[i].action((void*)data, (int)withobject, (void*)content) == TRUE)
            {
                mmi_frm_sms_convert_time_stamp(data->scts, data->scts);
                if (mmi_frm_sms_msg_check[i].callback((void*)data, (void*)content))
                {
                    updatelist = TRUE;
                }
                break;
            }
            i++;
        }
        if ((i == mmi_frm_sms_msg_check_num) || (updatelist == TRUE))
        {
            /* default indication here */
            mmi_frm_sms_msgbox_struct *entry = OslMalloc(sizeof(mmi_frm_sms_msgbox_struct));

            //mmi_frm_sms_concat_struct* concatinfo = (mmi_frm_sms_concat_struct*)&(data->concat_info);
            //U8 segment=((concatinfo->seg%g_frm_sms_cntx.mmi_frm_sms_msg_seg_size)==0)?
            //g_frm_sms_cntx.mmi_frm_sms_msg_seg_size:(concatinfo->seg%g_frm_sms_cntx.mmi_frm_sms_msg_seg_size);
            U8 segment = mmi_frm_sms_index_list[data->index].segment;
            U16 msgbox_index;

            mmi_frm_sms_convert_mt_to_entry(data, entry);

        #ifdef __MMI_UNIFIED_MESSAGE__
            memset(entry->content, 0, sizeof(entry->content));
            if (data->dcs == SMSAL_UCS2_DCS)
            {
                if (mmi_ucs2strlen((S8*) content))
                {
                    mmi_frm_sms_add_content_to_entry(entry, content);
                }
            }
            else
            {
                if (strlen((S8*) content))
                {
                    U8 *ucs2_content = NULL;
                    U16 ucs2_content_len = 0;

                    ucs2_content_len = ((mmi_msg_get_max_content_size() + 1) * ENCODING_LENGTH);
                    ucs2_content = OslMalloc(ucs2_content_len);
                    memset(ucs2_content, 0, ucs2_content_len);
                    mmi_asc_n_to_ucs2((S8*) ucs2_content, (S8*) content, (U32) mmi_msg_get_max_content_size());
                    mmi_frm_sms_add_content_to_entry(entry, ucs2_content);
                    OslMfree(ucs2_content);
                }
            }
        #endif /* __MMI_UNIFIED_MESSAGE__ */ 

            msgbox_index = mmi_frm_sms_add_sms_to_msgbox(entry, data->index, segment);
            if (i == mmi_frm_sms_msg_check_num)
            {
                mmi_frm_sms_new_msg_ind(msgbox_index);
            }
            OslMfree(entry);
        }
    }
    mmi_frm_sms_free_awaited((U8) index);
    if (data != NULL)
    {
        OslMfree(data);
        data = NULL;
    }
    if (content != NULL)
    {
        OslMfree(content);
        content = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_indicate_data
 * DESCRIPTION
 *  Indicate new SMS with port number
 * PARAMETERS
 *  index       [IN]        Data index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_indicate_data(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_frm_sms_deliver_data_struct *data = OslMalloc(sizeof(mmi_frm_sms_deliver_data_struct));

    /* MMI could only allocate 2K control buffer, so limit the max allocate buffer to 1600 here */
    U16 content_len =
        ((MMI_FRM_SMS_MSG_LEN * g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) <
         (MMI_FRM_SMS_MSG_LEN * 10)) ? (MMI_FRM_SMS_MSG_LEN *
                                        g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) : (MMI_FRM_SMS_MSG_LEN * 10);
    U8 *content = OslMalloc(content_len);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(content, 0, content_len);
    mmi_frm_sms_set_data_check(index, 0);
    mmi_frm_sms_get_data(index, data, content);
    while (i < mmi_frm_sms_data_check_num)
    {
        if ((mmi_frm_sms_data_check[i].module == data->dest_mod_id)
            && (mmi_frm_sms_data_check[i].desport == data->dest_port)
        #ifdef __MMI_DUAL_SIM_MASTER__
            && (mmi_frm_sms_data_check[i].isSlave== data->isSlave)
        #endif
            )
        {
            if (mmi_frm_sms_data_check[i].withdata)
            {
                mmi_frm_sms_free_data(index);
            }
            else
            {
                mmi_frm_sms_data_check[i].serial++;
                if (mmi_frm_sms_data_check[i].serial == MMI_FRM_SMS_INVALID_NUM)
                {
                    mmi_frm_sms_data_check[i].serial = 0;
                }
                if (index == MMI_FRM_SMS_ACTION_SIZE)
                {
                    /* add one entry with index awaited_index in the mmi_frm_sms_data */
                    U8 awaited_index = mmi_frm_sms_add_data_entry();

                    /* find an empty entry in the data list and add successfully */
                    if (awaited_index != MMI_FRM_SMS_INVALID_NUM)
                    {
                        /* Reset the data check bit to zero  */
                        mmi_frm_sms_set_data_check(awaited_index, 0);
                        mmi_frm_sms_free_new_data();
                    }
                }
            }
            mmi_frm_sms_data_check[i].callback(
                                        (void*)data,
                                        (module_type) data->dest_mod_id,
                                        mmi_frm_sms_data_check[i].serial);
            break;
        }
        i++;
    }
    if (i == mmi_frm_sms_data_check_num)
    {
        mmi_frm_sms_free_data(index);
    }
    if (data != NULL)
    {
        OslMfree(data);
        data = NULL;
    }
    if (content != NULL)
    {
        OslMfree(content);
        content = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_new_sms
 * DESCRIPTION
 *  handle new SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_new_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check segment */
    switch (mmi_frm_sms_check_concatenate_sms(&index))
    {
        case MMI_FRM_SMS_AWAITS:
        {
            mmi_frm_sms_indicate_sms(index);
        }
            break;
        case MMI_FRM_SMS_INBOX:
        {
            /* when there is a new segment coming, always set the status as unread, in case the previous segments in inbox is read */
            mmi_frm_sms_set_sms_status(MMI_FRM_SMS_NOBOX, index, MMI_FRM_SMS_UNREAD);
            mmi_frm_sms_new_msg_ind(index);
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_new_data
 * DESCRIPTION
 *  handle new SMS with port number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_new_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check segment */
    switch (mmi_frm_sms_check_concatenate_data(&index))
    {
        case MMI_FRM_SMS_DATA:
        {
            mmi_frm_sms_indicate_data(index);
        }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_entry_abort
 * DESCRIPTION
 *  Entry abort screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_entry_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_PROCESSING, NULL, mmi_frm_sms_entry_abort, NULL);
    ShowCategory8Screen(
        STR_ABORT_SENDING_SMS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        0,
        0,
        0,
        0,
        STR_SENDIING_SMS_BODY,
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
    if (isInCall())
    {
        SetKeyHandler(HangupAllCalls, KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_entry_send
 * DESCRIPTION
 *  Entry send screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_entry_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_SENDING, NULL, mmi_frm_sms_entry_send, NULL);
    /* reset the status because sending SMS in the idle screen background is allowable */
    g_msg_cntx.msg_status = MSG_STATUS_IDLE;
#ifndef __MMI_DUAL_SIM_MASTER__
    ShowCategory8Screen(
        STR_SENDING_SMS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_SMS_COMMON_NOIMAGE,
        STR_SENDIING_SMS_BODY,
        IMG_NEW_SMS_SEND,
        NULL);
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
	case MTPNP_AD_CHANNEL_MASTER:
		ShowCategory8Screen(
	        STRING_MTPNP_MASTER_SENDING_SMS,
	        IMG_SMS_ENTRY_SCRN_CAPTION,
	        0,
	        0,
	        STR_GLOBAL_CANCEL,
	        IMG_SMS_COMMON_NOIMAGE,
	        STR_SENDIING_SMS_BODY,
	        IMG_NEW_SMS_SEND,
	        NULL);
		break;
	case MTPNP_AD_CHANNEL_SLAVE:
		ShowCategory8Screen(
	        STRING_MTPNP_SLAVE_SENDING_SMS,
	        IMG_SMS_ENTRY_SCRN_CAPTION,
	        0,
	        0,
	        STR_GLOBAL_CANCEL,
	        IMG_SMS_COMMON_NOIMAGE,
	        STR_SENDIING_SMS_BODY,
	        IMG_NEW_SMS_SEND,
	        NULL);
		break;
	case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
	case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
	default:
		ShowCategory8Screen(
	        STR_SENDING_SMS,
	        IMG_SMS_ENTRY_SCRN_CAPTION,
	        0,
	        0,
	        STR_GLOBAL_CANCEL,
	        IMG_SMS_COMMON_NOIMAGE,
	        STR_SENDIING_SMS_BODY,
	        IMG_NEW_SMS_SEND,
	        NULL);
		break;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    if (!g_frm_sms_background_send_info.isBackground)   
#endif
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        GetCurrEndKeyDownHandler();
    #endif 

    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);

#ifndef __MMI_DUAL_SIM_MASTER__
#ifdef __MMI_UNIFIED_MESSAGE__
    SetKeyHandler(mmi_frm_sms_abort_sms_by_end_key, KEY_END, KEY_EVENT_DOWN);
#else 
    SetKeyHandler(mmi_frm_sms_abort_sms, KEY_END, KEY_EVENT_DOWN);
#endif 
    SetRightSoftkeyFunction(mmi_frm_sms_abort_sms, KEY_EVENT_UP);
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_SLAVE:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
		#ifdef __MMI_UNIFIED_MESSAGE__
		/*
		       SetKeyHandler(mmi_frm_sms_abort_sms_by_end_key, KEY_END, KEY_EVENT_DOWN);
		*/       
		#else 
			SetKeyHandler(MTPNP_PFAL_Abort_SMS_Req, KEY_END, KEY_EVENT_DOWN);
		#endif 
			SetRightSoftkeyFunction(MTPNP_PFAL_Abort_SMS_Req, KEY_EVENT_UP);
			break;
		case MTPNP_AD_CHANNEL_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		default:
		#ifdef __MMI_UNIFIED_MESSAGE__
		       SetKeyHandler(mmi_frm_sms_abort_sms_by_end_key, KEY_END, KEY_EVENT_DOWN);
		#else 
			SetKeyHandler(mmi_frm_sms_abort_sms, KEY_END, KEY_EVENT_DOWN);
		#endif 
			SetRightSoftkeyFunction(mmi_frm_sms_abort_sms, KEY_EVENT_UP);
			break;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_entry_save
 * DESCRIPTION
 *  Entry save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_entry_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_SAVING, NULL, mmi_frm_sms_entry_save, NULL);
    ShowCategory8Screen(
        STR_SAVING_SMS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        0,
        0,
        0,
        IMG_SMS_COMMON_NOIMAGE,
        STR_SENDIING_SMS_BODY,
        IMG_GLOBAL_SAVE,
        NULL);

    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_phb_number
 * DESCRIPTION
 *  Get phonebook number
 * PARAMETERS
 *  name        [IN]        Name
 *  number      [IN]        Number
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_phb_number(U8 name[], U8 number[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) number) > (MAX_DIGITS_SMS - 1))
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            PHB_NOTIFY_TIMEOUT,
            (U8) ERROR_TONE);
        return;
    }

    memset(g_frm_sms_cntx.mmi_frm_sms_number, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
    if (number)
    {
        mmi_ucs2cpy((S8*) g_frm_sms_cntx.mmi_frm_sms_number, (PS8) number);
    }

    if (mmi_frm_sms_search_phb_type == MMI_FRM_SMS_SC)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
    	if (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL) == MTPNP_AD_CHANNEL_SLAVE
			|| MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL) == MTPNP_AD_CHANNEL_DEFAULT_SLAVE)
		{
			HistoryReplace(SCR_ID_MSG_SC_NUMBER, SCR_ID_MSG_SC_NUMBER, mmi_frm_sms_entry_card2_sc); 
		}
		else
	#endif /* __MMI_DUAL_SIM_MASTER__ */
		{
        	HistoryReplace(SCR_ID_MSG_SC_NUMBER, SCR_ID_MSG_SC_NUMBER, mmi_frm_sms_entry_sc);
		}
        GoBackToHistory(SCR_ID_MSG_SC_NUMBER);
    }
    else
    {
        HistoryReplace(SCR_ID_MSG_NUMBER, SCR_ID_MSG_NUMBER, mmi_frm_sms_entry_number);
        GoBackToHistory(SCR_ID_MSG_NUMBER);
    }
    /* GoBackHistory (); */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_phb_number_ext
 * DESCRIPTION
 *  Get phonebook number
 * PARAMETERS
 *  name        [IN]        Name
 *  number      [IN]        Number
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_phb_number_ext(S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_sms_get_phb_number((U8*)name, (U8*)number);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_search_phb
 * DESCRIPTION
 *  Interface to enter phone book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_search_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_ALL_NUMBER, mmi_frm_sms_get_phb_number_ext);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_number_empty
 * DESCRIPTION
 *  LSK handle when number input is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_number_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_search_phb_type = MMI_FRM_SMS_DA;
    ChangeLeftSoftkey(STR_SMS_COMMON_SEARCH, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_frm_sms_search_phb, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_number_not_empty
 * DESCRIPTION
 *  LSK handle when number input is not empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_number_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_frm_sms_entry_number_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_go_back_from_send
 * DESCRIPTION
 *  RSK handle in input SC/number screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_go_back_from_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.msg_status = MSG_STATUS_IDLE;
    mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_RETURN);
    AlmEnableSPOF();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_end_key_from_send
 * DESCRIPTION
 *  END key handle in input SC/number screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_end_key_from_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() == FALSE)
    {
        g_msg_cntx.msg_status = MSG_STATUS_IDLE;
        mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_END);
        AlmEnableSPOF();
        memset(g_frm_sms_cntx.mmi_frm_sms_number, 0, sizeof(g_frm_sms_cntx.mmi_frm_sms_number));
    }
    ExecCurrEndKeyDownHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_handle_number_deleted
 * DESCRIPTION
 *  delete the action from queue if SMS application is re-entering
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_frm_sms_handle_number_deleted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_delete_action_pending();

	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_entry_number
 * DESCRIPTION
 *  Entry SMS number screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_entry_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_NUMBER, NULL, mmi_frm_sms_entry_number, NULL);
    AlmDisableSPOF();   /* in case schedule power off in sending a message */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_NUMBER);
    /* keep the status in number editing screen and check the status in idle screeen.
       in the normal case, the status should be MSG_STATUS_IDLE in idle screen */
    g_msg_cntx.msg_status = MSG_STATUS_INPUT_NUM;
    GetCurrEndKeyDownHandler();

    RegisterInputBoxEmptyFunction(mmi_frm_sms_number_empty);
    RegisterInputBoxNotEmptyFunction(mmi_frm_sms_number_not_empty);

    ShowCategory5Screen(
        STR_ENTER_PHONE_NUMBER_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        INPUT_TYPE_PHONE_NUMBER /* |INPUT_TYPE_PLUS_CHARACTER_HANDLING */ ,
        (U8*) g_frm_sms_cntx.mmi_frm_sms_number,
        MAX_DIGITS_SMS,
        guiBuffer);

    SetKeyHandler(mmi_frm_sms_entry_number_done, KEY_SEND, KEY_EVENT_UP);
	SetDelScrnIDCallbackHandler(SCR_ID_MSG_NUMBER, (HistoryDelCBPtr)mmi_frm_sms_handle_number_deleted);
    SetCategory5RightSoftkeyFunction(mmi_frm_sms_go_back_from_send, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_sms_end_key_from_send, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_entry_sc_done
 * DESCRIPTION
 *  save entered SC number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_entry_sc_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode = 0;
    S8 nvramActiveProfileIndex = 0;
    msg_profile_edit_struct *profileSC = NULL;
    S8 scAddress[MAX_DIGITS + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(scAddress, 0, MAX_DIGITS + 1);
    mmi_ucs2_n_to_asc((PS8) scAddress, (PS8) g_frm_sms_cntx.mmi_frm_sms_number, (MAX_CC_ADDR_LEN *ENCODING_LENGTH));
    if (MMI_FALSE == mmi_frm_sms_check_dst_number((U8*)scAddress, (U8)strlen(scAddress)))
    {    	
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);

        return;
    }	
	profileSC = OslMalloc(sizeof(msg_profile_edit_struct));
    ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &nvramActiveProfileIndex, DS_BYTE, &errorCode);
    profileSC->profileIndex = nvramActiveProfileIndex;
    mmi_ucs2cpy((S8*) profileSC->scAddress, (S8*) g_frm_sms_cntx.mmi_frm_sms_number);
    mmi_frm_sms_set_sc_addr_req(profileSC);
    ClearInputEventHandler(MMI_DEVICE_ALL);
    OslMfree(profileSC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_sc_empty
 * DESCRIPTION
 *  LSK handle when sc input is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_sc_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_search_phb_type = MMI_FRM_SMS_SC;
    ChangeLeftSoftkey(STR_SMS_COMMON_SEARCH, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_frm_sms_search_phb, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_sc_not_empty
 * DESCRIPTION
 *  LSK handle when sc input is not empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_sc_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_frm_sms_entry_sc_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_entry_sc
 * DESCRIPTION
 *  Entry input SC screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_entry_sc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_SC_NUMBER, NULL, mmi_frm_sms_entry_sc, NULL);
    AlmDisableSPOF();   /* in case schedule power off in sending a message */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SC_NUMBER);
    /* keep the status in number editing screen and check the status in idle screeen.
       in the normal case, the status should be MSG_STATUS_IDLE in idle screen */
    g_msg_cntx.msg_status = MSG_STATUS_INPUT_NUM;
    GetCurrEndKeyDownHandler();

    RegisterInputBoxEmptyFunction(mmi_frm_sms_sc_empty);
    RegisterInputBoxNotEmptyFunction(mmi_frm_sms_sc_not_empty);

    ShowCategory5Screen(
        STR_SC_EMPTY_CAPTION_ID,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        INPUT_TYPE_PHONE_NUMBER /* |INPUT_TYPE_PLUS_CHARACTER_HANDLING */ ,
        (U8*) g_frm_sms_cntx.mmi_frm_sms_number,
        MAX_DIGITS_SMS,
        guiBuffer);
    SetCategory5RightSoftkeyFunction(mmi_frm_sms_go_back_from_send, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_sms_end_key_from_send, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_write_action
 * DESCRIPTION
 *  mmi_frm_sms_write_action
 * PARAMETERS
 *  callback        [IN]        
 *  mod_src         [IN]        
 *  data            [?]         
 *  function        [IN]        
 *  a  action      action(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_sms_write_action(PsFuncPtrU16 callback, module_type mod_src, void *data, PsFuncPtr function)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_action_struct action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    action.mod_src = mod_src;
    action.data = data;
    action.callback = callback;
    action.action = function;

    if (mmi_frm_sms_action_num == MMI_FRM_SMS_ACTION_SIZE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_frm_sms_write_action:: mmi_frm_sms_action_num %d",
                             (int)mmi_frm_sms_action_num);
        return FALSE;
    }

    MMI_ASSERT((mmi_frm_sms_action_tail < MMI_FRM_SMS_ACTION_SIZE));

    memcpy(&mmi_frm_sms_action[mmi_frm_sms_action_tail], (S8*) & action, sizeof(mmi_frm_sms_action_struct));

    if (++mmi_frm_sms_action_tail == MMI_FRM_SMS_ACTION_SIZE)
    {
        mmi_frm_sms_action_tail = 0;
    }

    mmi_frm_sms_action_num++;

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_frm_sms_write_action:: mmi_frm_sms_action_curr %d",
                         (int)mmi_frm_sms_action_curr);

    if (mmi_frm_sms_action_curr == MMI_FRM_SMS_INVALID_NUM)
    {
        mmi_frm_sms_read_action();
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_read_action
 * DESCRIPTION
 *  mmi_frm_sms_read_action
 * PARAMETERS
 *  void
 *  a  action      action(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_sms_read_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PsFuncPtr currFuncPtr = mmi_frm_sms_action[mmi_frm_sms_action_head].action;
    void *currFuncData = mmi_frm_sms_action[mmi_frm_sms_action_head].data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_action_num == 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_frm_sms_read_action:: mmi_frm_sms_action_num %d",
                             (int)mmi_frm_sms_action_num);
        return FALSE;
    }

    MMI_ASSERT((mmi_frm_sms_action_head < MMI_FRM_SMS_ACTION_SIZE));

    mmi_frm_sms_action_curr = mmi_frm_sms_action_head;
    mmi_frm_sms_action_num--;

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_frm_sms_read_action:: mmi_frm_sms_action_curr %d",
                         (int)mmi_frm_sms_action_curr);

    if (currFuncPtr != NULL)
    {
        (*currFuncPtr) (currFuncData);
    }

    if (++mmi_frm_sms_action_head == MMI_FRM_SMS_ACTION_SIZE)
    {
        mmi_frm_sms_action_head = 0;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_callback_action
 * DESCRIPTION
 *  mmi_frm_sms_callback_action
 * PARAMETERS
 *  data        [?]         
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_callback_action(void *data, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PsFuncPtrU16 callback = mmi_frm_sms_action[mmi_frm_sms_action_curr].callback;
    module_type mod_src = mmi_frm_sms_action[mmi_frm_sms_action_curr].mod_src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_frm_sms_callback_action:: mmi_frm_sms_action_curr %d",
                         (int)mmi_frm_sms_action_curr);

    if ((callback != NULL) && (mmi_frm_sms_action_curr != MMI_FRM_SMS_INVALID_NUM))
    {
        MMI_ASSERT((mmi_frm_sms_action_curr < MMI_FRM_SMS_ACTION_SIZE));
        callback(data, (module_type) mod_src, result);
    }
    mmi_frm_sms_action_curr = MMI_FRM_SMS_INVALID_NUM;

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_frm_sms_callback_action:: mmi_frm_sms_action_curr %d",
                         (int)mmi_frm_sms_action_curr);

    mmi_frm_sms_read_action();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_action_pending
 * DESCRIPTION
 *  check if there is a pending action in SMS framework
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_sms_check_action_pending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_frm_sms_check_action_pending:: mmi_frm_sms_action_curr %d",
                         (int)mmi_frm_sms_action_curr);
    MMI_ASSERT((mmi_frm_sms_action_curr == MMI_FRM_SMS_INVALID_NUM) ||
               (mmi_frm_sms_action_curr < MMI_FRM_SMS_ACTION_SIZE));

    if (mmi_frm_sms_action_curr != MMI_FRM_SMS_INVALID_NUM)
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
 *  mmi_frm_sms_delete_action_pending
 * DESCRIPTION
 *  delete the action from queue if SMS application is re-entering
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_delete_action_pending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.msg_status != MSG_STATUS_IDLE)
    {
        if (IsScreenPresent(SCR_ID_MSG_SENDING) || IsScreenPresent(SCR_ID_MSG_PROCESSING))
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*-------[SmsCore.c] mmi_frm_sms_delete_action_pending DO NOTHING -------*\n");
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*-------[SmsCore.c] mmi_frm_sms_delete_action_pending DELETE ACTION QUEUE -------*\n");
            /* reset the status after deleting the action queue */
            g_msg_cntx.msg_status = MSG_STATUS_IDLE;
            mmi_frm_sms_callback_action(NULL, MMI_FRM_SMS_END);
        }
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*-------[SmsCore.c] mmi_frm_sms_delete_action_pending IDLE -------*\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_delete_screen_history
 * DESCRIPTION
 *  delete the screen history that is not set to g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_delete_screen_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
    DeleteScreenIfPresent(SCR_ID_MSG_SENDING);
    DeleteScreenIfPresent(SCR_ID_MSG_NUMBER);
    DeleteScreenIfPresent(SCR_ID_MSG_SC_NUMBER);
    DeleteScreenIfPresent(SCR_ID_MSG_SAVING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_check_complete
 * DESCRIPTION
 *  Check message completeneww
 * PARAMETERS
 *  type        [IN]        Message type
 *  index       [IN]        Message index
 * RETURNS
 *  TRUE: complete; FALSE: not
 *****************************************************************************/
U8 mmi_frm_sms_check_complete(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_sms_check_sms_complete(type, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_status
 * DESCRIPTION
 *  Get message status
 * PARAMETERS
 *  type        [IN]        Message type
 *  index       [IN]        Message index
 * RETURNS
 *  status
 *****************************************************************************/
U16 mmi_frm_sms_get_status(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_sms_get_sms_status(type, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_dcs
 * DESCRIPTION
 *  Get message DCS
 * PARAMETERS
 *  type        [IN]        Message type
 *  index       [IN]        Message index
 * RETURNS
 *  dcs
 *****************************************************************************/
U8 mmi_frm_sms_get_dcs(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_sms_get_sms_dcs(type, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_address
 * DESCRIPTION
 *  Get message address
 * PARAMETERS
 *  type        [IN]        Message type
 *  index       [IN]        Message index
 * RETURNS
 *  address
 *****************************************************************************/
U8 *mmi_frm_sms_get_address(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_sms_get_sms_address(type, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_timestamp
 * DESCRIPTION
 *  Get message timestamp
 * PARAMETERS
 *  type        [IN]        Message type
 *  index       [IN]        Message index
 * RETURNS
 *  timestamp
 *****************************************************************************/
U8 *mmi_frm_sms_get_timestamp(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_sms_get_sms_timestamp(type, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_list_index
 * DESCRIPTION
 *  Get SMS type/index
 * PARAMETERS
 *  type                [OUT]       Message type
 *  index               [OUT]       Message index
 *  msgbox_index        [IN]        Message index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_list_index(U16 *type, U16 *index, U16 msgbox_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_get_sms_list_index(type, index, msgbox_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sms
 * DESCRIPTION
 *  Abort MO SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_abort_sms_req(NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sending_sms
 * DESCRIPTION
 *  Abort sending SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sending_sms(mmi_frm_sms_abort_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_abort_sending_sms_req(type);
}

#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_sms_by_end_key
 * DESCRIPTION
 *  Abort MO SMS by end key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_sms_by_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() == FALSE)
    {
        mmi_frm_sms_abort_sms_req_by_end_key(NULL);
        mmi_frm_sms_callback_abort_sms_by_end_key();
        AlmEnableSPOF();
    }
    ExecCurrEndKeyDownHandler();
}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_send_sms
 * DESCRIPTION
 *  Send SMS
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  sendData        [IN]        Send data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_send_sms(PsFuncPtrU16 callback, module_type mod_src, mmi_frm_sms_send_struct *sendData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *data = OslMalloc(sizeof(mmi_frm_sms_send_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((S8*) data, (S8*) sendData, sizeof(mmi_frm_sms_send_struct));
#ifdef __MMI_DUAL_SIM_MASTER__
	if (!(sendData->sendrequire&MMI_FRM_SMS_DISP_SIM_OPT))
#endif
	{
    	mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_pre_send_sms);
    }
#ifdef __MMI_DUAL_SIM_MASTER__
	else
	{	
		mmi_frm_msg_set_send_data(callback, mod_src, data);
		mmi_frm_msg_entry_Select_option_screen();
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_send_sms_for_other_app
 * DESCRIPTION
 *  Send SMS
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  sendData        [IN]        Send data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_send_sms_for_other_app(PsFuncPtrU16 callback, module_type mod_src, mmi_frm_sms_send_struct *sendData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	/* If queue is not empty,  return */
	if (mmi_frm_sms_action_curr != MMI_FRM_SMS_INVALID_NUM)
	{		        
        if (sendData->string != NULL)
        {
            OslMfree(sendData->string);
            sendData->string = NULL;
        }
        callback(NULL, (module_type) mod_src, MMI_FRM_SMS_NOTREADY);
        return;	
	}
	mmi_frm_sms_send_sms(callback, mod_src, sendData);   	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_read_sms
 * DESCRIPTION
 *  Read SMS
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  type            [IN]        Message type
 *  index           [IN]        Message index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_read_sms(PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index, MMI_BOOL change_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *data = OslMalloc(sizeof(U16) * (g_frm_sms_cntx.mmi_frm_sms_msg_seg_size + 1));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (type == MMI_FRM_SMS_NOBOX || type == MMI_FRM_SMS_INBOX ||
		type == MMI_FRM_SMS_UNREAD
	#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
		|| type == MMI_FRM_SMS_SIM
	#endif
		)
	{
		g_mmi_frm_sms_change_status = change_status;
		if (g_mmi_frm_sms_change_status)
		{
		#ifdef __MMI_DUAL_SIM_MASTER__
			BOOL isMaster = mmi_frm_msg_is_from_master_sim(g_msg_cntx.msg_ind_index);
			U16 ret = MTPNP_AD_SMS_Get_Filter_Rule();
		#endif /* __MMI_DUAL_SIM_MASTER__ */

			if ((mmi_frm_sms_get_status(type, index) & 0x0f) == MMI_FRM_SMS_APP_UNREAD
		#ifdef __MMI_DUAL_SIM_MASTER__
			&& ((ret == MTPNP_AD_FILTER_MASTER && isMaster)	|| (ret == MTPNP_AD_FILTER_SLAVE && !isMaster) || (ret == MTPNP_AD_FILTER_ALL))
		#endif /* __MMI_DUAL_SIM_MASTER__ */
				)
			{
				g_msg_cntx.msg_ind_in_idle = FALSE;
				//mmi_frm_sms_set_sms_status(type, index, MMI_FRM_SMS_INBOX);
			}
                    mmi_frm_sms_set_sms_status(type, index, MMI_FRM_SMS_INBOX); //sc.wu sms message state
		    
		}
	}
	else
	{
		g_mmi_frm_sms_change_status = MMI_FALSE;
	}
    mmi_frm_sms_get_sms_index((mmi_frm_sms_msgbox_enum) type, index, data);
    data[g_frm_sms_cntx.mmi_frm_sms_msg_seg_size] = (U16) mmi_frm_sms_get_sms_size(type, index);
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_read_sms_req);
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_read_one_archive_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 *  type            [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_read_one_archive_msg(PsFuncForArchPtr callback,  U16 type, U16 index) //type is not used here, for future
{
    U8 result =MMI_FALSE;
    mmi_frm_sms_msgbox_enum fromBoxType;
    result = mmi_frm_sms_get_one_archive_msg(index);
/*need to maintain read/unread status*/
    fromBoxType = mmi_frm_sms_get_archive_src_box_type(MMI_FRM_SMS_ARCHIVE, index);    

    if (result != MMI_TRUE)
    {
        callback((U16)fromBoxType, MMI_FRM_SMS_ERROR);
    }
    else
    {
        callback((U16)fromBoxType, MMI_FRM_SMS_OK);
    }	
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sms
 * DESCRIPTION
 *  Get SMS, for AT sync indication
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  index           [IN]        Message index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sms(PsFuncPtrU16 callback, module_type mod_src, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *data = OslMalloc(sizeof(U16));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *data = index;
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_get_sms_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_save_sms
 * DESCRIPTION
 *  Save SMS
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  sendData        [IN]        Save data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_save_sms(PsFuncPtrU16 callback, module_type mod_src, mmi_frm_sms_send_struct *sendData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *data = OslMalloc(sizeof(mmi_frm_sms_send_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((S8*) data, (S8*) sendData, sizeof(mmi_frm_sms_send_struct));    
#ifdef __MMI_DUAL_SIM_MASTER__
	if (!(sendData->sendrequire&MMI_FRM_SMS_DISP_SIM_OPT))
#endif
	{
    	mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_save_sms_req);
    }
#ifdef __MMI_DUAL_SIM_MASTER__
	else
	{	
		mmi_frm_msg_set_send_data(callback, mod_src, data);
		mmi_msg_entry_select_save_option_screen();
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_save_sms_for_other_app
 * DESCRIPTION
 *  Save SMS for other module
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  sendData        [IN]        Save data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_save_sms_for_other_app(PsFuncPtrU16 callback, module_type mod_src, mmi_frm_sms_send_struct *sendData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* If queue is not empty, return */
	if (mmi_frm_sms_action_curr != MMI_FRM_SMS_INVALID_NUM)
	{		        
        if (sendData->string != NULL)
        {
            OslMfree(sendData->string);
            sendData->string = NULL;
        }
        callback(NULL, (module_type) mod_src, MMI_FRM_SMS_NOTREADY);
        return;	
	}	
    mmi_frm_sms_save_sms(callback, mod_src, sendData);
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_move_to_archive
 * DESCRIPTION
 *  Delete SMS
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module, --- MOD_MMI
 *  type            [IN]        Message type --- from which box (MMI_FRM_SMS_APP_INBOX or MMI_FRM_SMS_APP_INBOX)
 *  index           [IN]        Message index --- current index (in first sms layer list)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_move_to_archive(PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index)
{
    /* in the following API will save this msg to archive and then delete msg from inbox/outbox*/
    /* 1- save this msg to archive*/
    FS_HANDLE fsErrCode = FS_NO_ERROR;
    U8 result = mmi_frm_sms_save_one_archive_msg((mmi_frm_sms_msgbox_enum) type, index, &fsErrCode);
    /*if((mmi_frm_sms_save_one_archive_msg((mmi_frm_sms_msgbox_enum) type, index)) != MMI_TRUE)*/
    if (result != MMI_TRUE)
    {
        callback(&fsErrCode, MOD_MMI, MMI_FRM_SMS_ERROR); 
    }
    else
    {
    /*2- delete the msg from srcBox*/
        mmi_frm_sms_delete_sms(callback, mod_src, type, index);
    }
}



//index here is the 1st layer index
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_delete_one_archive_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 *  type            [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_delete_one_archive_msg_req(PsFuncPtrU16 callback, U16 type, U16 index)
{
    U8 result = mmi_frm_sms_remove_one_archive_msg(type, index);
    if (result != TRUE)
    {
        callback(NULL, MOD_MMI, MMI_FRM_SMS_ERROR);		
    }
    else
    {
        callback(NULL, MOD_MMI, MMI_FRM_SMS_OK);    
    }
}


#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_delete_sms
 * DESCRIPTION
 *  Delete SMS
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  type            [IN]        Message type
 *  index           [IN]        Message index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_delete_sms(PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data = OslMalloc(sizeof(U8) * 480);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) data, 0, sizeof(U8) * 480);

#ifndef __MMI_DUAL_SIM_MASTER__
    if (mmi_frm_sms_get_sms_bitmap(type, index, data) == FALSE)
    {
        callback(NULL, MOD_MMI, MMI_FRM_SMS_ERROR);
    }
    else
    {
        mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_delete_sms_req);
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (mmi_frm_sms_record_is_slave_sms(type, index))
    {
        /* delete slave sms */
        if (mmi_frm_sms_get_slave_sms_bitmap(type, index, data) == FALSE)
        {
            callback(NULL, MOD_MMI, MMI_FRM_SMS_ERROR);
        }
        else
        {
            mmi_frm_sms_write_action(callback, mod_src, data, MTPNP_PFAL_Delete_Slave_SMS_Req);
        }
    }
    else
    {
        /* delete master sms */
        if (mmi_frm_sms_get_master_sms_bitmap(type, index, data) == FALSE)
        {
            callback(NULL, MOD_MMI, MMI_FRM_SMS_ERROR);
        }
        else
        {
            mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_delete_sms_req);
        }
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
}

#if defined(__MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_delete_sms
 * DESCRIPTION
 *  Delete SMS
 * PARAMETERS
 *  side            [IN]        witch side to delete, master or slave
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  type            [IN]        Message type
 *  index           [IN]        Message index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_dm_delete_sms(U8 side, PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((side & DM_SLAVE_BOX))
    {
        U8 *data1 = OslMalloc(sizeof(U8) * 480);

        memset((S8*) data1, 0, sizeof(U8) * 480);
        
        /* delete slave sms */
        if (mmi_frm_sms_get_slave_sms_bitmap(type, index, data1) == FALSE)
        {
            callback(NULL, MOD_MMI, MMI_FRM_SMS_ERROR);
        }
        else
        {
            mmi_frm_sms_write_action(callback, mod_src, data1, MTPNP_PFAL_Delete_Slave_SMS_Req);
        }
    }

    if ((side & DM_MASTER_BOX))
    {
        U8 *data2 = OslMalloc(sizeof(U8) * 480);

        memset((S8*) data2, 0, sizeof(U8) * 480);
        
        /* delete master sms */
        if (mmi_frm_sms_get_master_sms_bitmap(type, index, data2) == FALSE)
        {
            callback(NULL, MOD_MMI, MMI_FRM_SMS_ERROR);
        }
        else
        {
            mmi_frm_sms_write_action(callback, mod_src, data2, mmi_frm_sms_delete_sms_req);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_msg_is_from_master_sim_by_l4_index
 * DESCRIPTION
 *  whether current sms is from master sim by l4 index
 * PARAMETERS
 *  l4_index         [IN]
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_frm_msg_is_from_master_sim_by_l4_index(U16 l4_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
	{
		return TRUE;
	}
	return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_is_from_master_sim
 * DESCRIPTION
 *  whether current sms is from master sim
 * PARAMETERS
 *  list_index         [IN]
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_frm_msg_is_from_master_sim(U16 list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 l4_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	l4_index = mmi_frm_sms_msg_box[list_index].startindex;	

	return mmi_frm_msg_is_from_master_sim_by_l4_index(l4_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_msg_is_from_master_sim_by_msgbox_index
 * DESCRIPTION
 *  whether current sms is from master sim by msgbox index
 * PARAMETERS
 *  type        [IN]        Type
 *  index       [IN]        Index
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_frm_msg_is_from_master_sim_by_msgbox_index(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 entryindex;

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

    return mmi_frm_msg_is_from_master_sim(entryindex);
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_delete_sms_by_bitmap
 * DESCRIPTION
 *  Delete SMS
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  bitmap          [IN]        Bitmap
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_delete_sms_by_bitmap(PsFuncPtrU16 callback, module_type mod_src, U8 *bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data = OslMalloc(sizeof(U8) * 480);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) data, 0, sizeof(U8) * 480);
    memcpy((S8*) data, (S8*) bitmap, sizeof(U8) * 480);

    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_delete_sms_req);
}

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_delete_archive_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_delete_archive_folder(void)
{
    MMI_BOOL del_result = MMI_FALSE;
    mmi_frm_sms_clear_archive_del_folder_result();
    del_result = mmi_frm_sms_remove_all_archive_msg(MMI_FRM_SMS_ARCHIVE) ;
    mmi_frm_sms_set_archive_del_folder_result(del_result);
}

#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_reg_port
 * DESCRIPTION
 *  Register SMS port
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  port_num        [IN]        Port number
 *  enable          [IN]        Enable/disable
 *  withdata        [IN]        Indicate with data
 *  regcallback     [IN]        Regiter callback module
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_reg_port_for_internal(
        PsFuncPtrU16 callback,
        module_type mod_src,
        U16 port_num,
        BOOL enable,
        BOOL withdata,
    #ifdef __MMI_DUAL_SIM_MASTER__
		BOOL isSlave,
	#endif
        PsFuncPtrU16 regcallback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_data_check_struct *data = OslMalloc(sizeof(mmi_frm_sms_data_check_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data->module = mod_src;
    data->desport = port_num;
    data->enable = enable;
#ifdef __MMI_DUAL_SIM_MASTER__
	data->isSlave = isSlave;
#endif
    if (enable)
    {
        mmi_frm_sms_data_check[mmi_frm_sms_data_check_num].desport = port_num;
        mmi_frm_sms_data_check[mmi_frm_sms_data_check_num].module = mod_src;
        mmi_frm_sms_data_check[mmi_frm_sms_data_check_num].serial = 0;
        mmi_frm_sms_data_check[mmi_frm_sms_data_check_num].withdata = withdata;
        mmi_frm_sms_data_check[mmi_frm_sms_data_check_num].callback = regcallback;
	#ifdef __MMI_DUAL_SIM_MASTER__
		mmi_frm_sms_data_check[mmi_frm_sms_data_check_num].isSlave = isSlave;
	#endif
        mmi_frm_sms_data_check_num++;
    }
    else
    {
        U8 i = mmi_frm_sms_data_check_num;

        while (i > 0)
        {
            i--;
            if ((mmi_frm_sms_data_check[i].desport == port_num) && (mmi_frm_sms_data_check[i].module == mod_src)
			#ifdef __MMI_DUAL_SIM_MASTER__
				&& (mmi_frm_sms_data_check[i].isSlave == isSlave)
			#endif
				)
            {
                U8 j = i + 1;

                for (j = (i + 1); j < mmi_frm_sms_data_check_num; j++)
                {
                    memcpy(
                        (S8*) & mmi_frm_sms_data_check[j - 1],
                        (S8*) & mmi_frm_sms_data_check[j],
                        sizeof(mmi_frm_sms_data_check_struct));
                }
                mmi_frm_sms_data_check_num--;
                break;
            }
        }
    }
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_reg_port_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_reg_port
 * DESCRIPTION
 *  Register SMS port
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  port_num        [IN]        Port number
 *  enable          [IN]        Enable/disable
 *  withdata        [IN]        Indicate with data
 *  regcallback     [IN]        Regiter callback module
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_reg_port(
        PsFuncPtrU16 callback,
        module_type mod_src,
        U16 port_num,
        BOOL enable,
        BOOL withdata,
        PsFuncPtrU16 regcallback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_sms_reg_port_for_internal(callback, 
	mod_src, 
	port_num, 
	enable, 
	withdata,
#ifdef __MMI_DUAL_SIM_MASTER__
	FALSE,
#endif
	regcallback);
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_reg_port_for_slave
 * DESCRIPTION
 *  Register SMS port
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  port_num        [IN]        Port number
 *  enable          [IN]        Enable/disable
 *  withdata        [IN]        Indicate with data
 *  regcallback     [IN]        Regiter callback module
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_reg_port_for_slave(
        PsFuncPtrU16 callback,
        module_type mod_src,
        U16 port_num,
        BOOL enable,
        BOOL withdata,
        PsFuncPtrU16 regcallback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_sms_reg_port_for_internal(callback, mod_src, port_num, enable, withdata, TRUE, regcallback);
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_profile_active
 * DESCRIPTION
 *  Set active profile
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  index           [IN]        Active profile index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_profile_active(PsFuncPtrU16 callback, module_type mod_src, U8 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, index, DS_BYTE, &errorCode);
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	mmi_frm_sms_get_vp_sc_req(*index);
#endif
    callback(index, mod_src, MMI_FRM_SMS_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_profile_list
 * DESCRIPTION
 *  Get profile list, as well as active profile index
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_profile_list(PsFuncPtrU16 callback, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_profile_num_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_sc_addr
 * DESCRIPTION
 *  Get SC address
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  index           [IN]        Profile index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_sc_addr(PsFuncPtrU16 callback, module_type mod_src, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data = OslMalloc(sizeof(U8));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(data, index, sizeof(U8));
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_get_sc_addr_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_sc_addr
 * DESCRIPTION
 *  handle new SMS
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  index           [IN]        Profile index
 *  scAddr          [IN]        SC address
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_sc_addr(PsFuncPtrU16 callback, module_type mod_src, U8 index, S8 scAddr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msg_profile_edit_struct *data = OslMalloc(sizeof(msg_profile_edit_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(data->scAddress, scAddr, MAX_CC_ADDR_LEN * ENCODING_LENGTH);
    memset(data->scAddress + MAX_CC_ADDR_LEN * ENCODING_LENGTH, 0, ENCODING_LENGTH);
    data->profileIndex = index;
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_set_sc_addr_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_profile_detail
 * DESCRIPTION
 *  Get profile detail info
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  index           [IN]        Profile index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_profile_detail(PsFuncPtrU16 callback, module_type mod_src, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data = OslMalloc(sizeof(U8));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(data, index, sizeof(U8));
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_get_profile_detail_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_profile_detail
 * DESCRIPTION
 *  Set profile detail info
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  profile         [IN]        Profile content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_profile_detail(PsFuncPtrU16 callback, module_type mod_src, void *profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msg_profile_edit_struct *data = OslMalloc(sizeof(msg_profile_edit_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(data, profile, sizeof(msg_profile_edit_struct));
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_set_profile_detail_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_common_settings
 * DESCRIPTION
 *  Get common setting
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_common_settings(PsFuncPtrU16 callback, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_common_settings_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_common_settings
 * DESCRIPTION
 *  Set common setting
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  setting         [IN]        Settings
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_common_settings(PsFuncPtrU16 callback, module_type mod_src, U8 *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data = OslMalloc(sizeof(U8) * 2);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(data, setting, sizeof(U8) * 2);
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_set_common_settings_req);
}

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_memory_status
 * DESCRIPTION
 *  Get memory status
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_memory_status(PsFuncPtrU16 callback, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_memory_status_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_preferred_storage
 * DESCRIPTION
 *  Get preferred storage
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_preferred_storage(PsFuncPtrU16 callback, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_preferred_storage_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_preferred_storage
 * DESCRIPTION
 *  Set preferred storage
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  storage         [IN]        Storage
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_preferred_storage(PsFuncPtrU16 callback, module_type mod_src, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data = OslMalloc(sizeof(U8));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(data, storage, sizeof(U8));
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_set_preferred_storage_req);
}
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */ 

#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_preferred_bearer
 * DESCRIPTION
 *  Get preferred bearer
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_preferred_bearer(PsFuncPtrU16 callback, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_preferred_bearer_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_preferred_bearer
 * DESCRIPTION
 *  Set preferred bearer
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  bearer          [IN]        Bearer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_preferred_bearer(PsFuncPtrU16 callback, module_type mod_src, U8 bearer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data = OslMalloc(sizeof(U8));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(data, bearer, sizeof(U8));
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_set_preferred_bearer_req);
}
#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_mailbox_info
 * DESCRIPTION
 *  Get mailbox info
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_mailbox_info(PsFuncPtrU16 callback, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_mailbox_info_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_mailbox_info
 * DESCRIPTION
 *  Set mailbox info
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  mod_src         [IN]        Callback module
 *  mailbox         [IN]        Mailbox info to be set
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_mailbox_info(PsFuncPtrU16 callback, module_type mod_src, void *mailbox)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msg_mailbox_edit_struct *data = OslMalloc(sizeof(msg_mailbox_edit_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(data, mailbox, sizeof(msg_mailbox_edit_struct));
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_set_mailbox_info_req);
}

#ifdef __MMI_MESSAGES_COPY__


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_storage
 * DESCRIPTION
 *  get SMS storage type
 * PARAMETERS
 *  type        [IN]        mmi_frm_sms_app_msgbox_enum
 *  index       [IN]        message list index
 * RETURNS
 *  smsal_storage_enum (SMSAL_SM or SMSAL_ME)
 *****************************************************************************/
U8 mmi_frm_sms_get_storage(U16 type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_sms_get_sms_storage(type, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_copy_abort
 * DESCRIPTION
 *  abort SMS copy action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_copy_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_copy_sms_abort();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_copy_sms
 * DESCRIPTION
 *  copy SMS
 * PARAMETERS
 *  callback        [IN]        
 *  mod_src         [IN]        
 *  type            [IN]        mmi_frm_sms_app_msgbox_enum, (only UNREAD,INBOX,OUTBOX,DRAFTS are valid)
 *  index           [IN]        message list index, MMI_FRM_SMS_INVALID_INDEX means ALL
 *  action          [IN]        smsal_copy_action_enum, copy or move
 *  dst_storage     [IN]        smsal_storage_enum (SMSAL_SM or SMSAL_ME)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_copy_sms(PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index, U8 action, U8 dst_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index != MMI_FRM_SMS_INVALID_INDEX)
    {
        g_frm_sms_copy_info.total_msg_number = 1;
        g_frm_sms_copy_info.present_msg_index = index;
    }
    else
    {
    #if !defined(__MMI_DUAL_SIM_MASTER__)
        g_frm_sms_copy_info.total_msg_number = mmi_frm_sms_get_sms_list_size(type);
        g_frm_sms_copy_info.present_msg_index = 0;  /* first element of list */
    #else /* __MMI_DUAL_SIM_MASTER__ */
        g_frm_sms_copy_info.total_msg_number = MTPNP_PFAL_SMS_Get_SMS_List_Size(type);
        MTPNP_PFAL_SMS_Init_Copy_Index();
    #endif /* __MMI_DUAL_SIM_MASTER__ */

    }
    g_frm_sms_copy_info.handled_msg_number = 0;
    g_frm_sms_copy_info.copy_msg_number = 0;
    g_frm_sms_copy_info.msg_list_type = type;
    g_frm_sms_copy_info.present_L4_index = MMI_FRM_SMS_INVALID_INDEX;
    g_frm_sms_copy_info.dst_storage = dst_storage;
    g_frm_sms_copy_info.dst_msg_index = MMI_FRM_SMS_INVALID_INDEX;
    g_frm_sms_copy_info.action = action;
    g_frm_sms_copy_info.is_aborted = FALSE;
    g_frm_sms_copy_info.is_memory_full = FALSE;

    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_pre_copy_sms_req);

}
#endif /* __MMI_MESSAGES_COPY__ */ 

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_abort_background_sms_rsp
 * DESCRIPTION
 *  Abort background SMS response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_abort_background_sms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_SMS_SEND_ABORT_FINISH_IND_STRUCT *msgRsp = (MMI_FRM_SMS_SEND_ABORT_FINISH_IND_STRUCT*) inMsg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
    if (msgRsp->result == FALSE)
    {
		g_frm_sms_cntx.is_aborting = MMI_FALSE;
		backgroundSendAbortcallback(NULL, MOD_MMI, MMI_FRM_SMS_ERROR);
	}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_unsent_status
 * DESCRIPTION
 *  Set the status of unsent message
 * PARAMETERS
 *  callback        [IN]        Callback after action
 *  index           [IN]        the list index of message in unsent box
 *  send_status     [IN]        the status of sending about message in unsent box
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_set_unsent_status(PsFuncPtrU16 callback,kal_uint16 index, mmi_frm_send_status_app_enum send_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msgindex = 0;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgindex = mmi_frm_sms_unsent_list[index];
    backgroundSendAbortcallback = callback;
    if (send_status == mmi_frm_sms_msg_box[msgindex].send_status)
    {
        backgroundSendAbortcallback(NULL,MOD_MMI,MMI_FRM_SMS_ERROR);
        return;
    }
    if (mmi_frm_sms_msg_box[msgindex].send_status == MMI_FRM_SMS_APP_SENDING)
    {  
    	if (g_frm_sms_background_send_info.l4_index == MMI_FRM_SMS_INVALID_INDEX)
		{
		    backgroundSendAbortcallback(NULL,MOD_MMI,MMI_FRM_SMS_ERROR);
        	return;
		}
        g_frm_sms_cntx.is_aborting = MMI_TRUE;
        SetProtocolEventHandler(mmi_frm_sms_abort_background_sms_rsp, PRT_MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND);
        mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_ABORT_REQ, NULL, NULL);
    }
    else
    {
    	if (send_status == MMI_FRM_SMS_APP_SENDING)
		{
			send_status = MMI_FRM_SMS_APP_WAITING;
		}
        mmi_frm_sms_msg_box[msgindex].send_status = send_status;
        backgroundSendAbortcallback(NULL,MOD_MMI,MMI_FRM_SMS_OK);
		mmi_frm_sms_background_send_schedule();        		
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_unsent_status
 * DESCRIPTION
 *  Get the status of unsent message
 * PARAMETERS
 *  index      [?]    the list index of message in unsent box 
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_sms_get_unsent_status(kal_uint16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msgindex = 0;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msgindex = mmi_frm_sms_unsent_list[index];
	if (msgindex == MMI_FRM_SMS_INVALID_INDEX)
	{
		return MMI_FRM_SMS_INVALID_NUM;
	}
    
    return mmi_frm_sms_msg_box[msgindex].send_status;   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_background_send_schedule
 * DESCRIPTION
 *  the background send schedule
 * PARAMETERS
 *  void      [?]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_background_send_schedule(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;      

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[SmsCore.c] mmi_frm_sms_background_send_schedule start*\n");

	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
			"*g_frm_sms_background_send_info.background_state %d *\n", g_frm_sms_background_send_info.background_state);
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
			"*g_frm_sms_background_send_info.foreground_state %d *\n", g_frm_sms_background_send_info.foreground_state);
	/* If currrent sending sms, not re-schedule */
    if ((g_frm_sms_background_send_info.background_state == MMI_FRM_SMS_SEND_STATE_SENDING)
        || (g_frm_sms_background_send_info.foreground_state == MMI_FRM_SMS_SEND_STATE_SENDING))
    {
        return;
    }
    
    if (g_frm_sms_background_send_info.foreground_state == MMI_FRM_SMS_SEND_STATE_SUSPEND)
    {
        g_frm_sms_background_send_info.foreground_state = MMI_FRM_SMS_SEND_STATE_SENDING;
        
        SetProtocolEventHandler(mmi_frm_sms_send_sms_rsp, PRT_MSG_ID_MMI_SMS_SEND_MSG_RSP);
        SetProtocolEventHandler(mmi_frm_sms_abort_sms_ind, PRT_MSG_ID_MMI_SMS_SEND_ABORT_START_IND);                
        mmi_frm_sms_send_sms_seg();
        
        return;
    }
    else if (g_frm_sms_background_send_info.background_state !=  MMI_FRM_SMS_SEND_STATE_SUSPEND)
    {
        U16 l4_index[MMI_SMS_MAX_MSG_SEG];

        if (mmi_frm_sms_get_unsent_sms_waitting_index(&index) == FALSE)
    	{
    		g_frm_sms_background_send_info.background_state =  MMI_FRM_SMS_SEND_STATE_IDLE;

			return;
    	}
        mmi_frm_sms_msg_box[mmi_frm_sms_unsent_list[index]].send_status = MMI_FRM_SMS_SENDING;
		mmi_frm_sms_background_send_refresh_ind(index, MMI_FRM_SMS_SENDING);
        mmi_frm_sms_get_sms_index(MMI_FRM_SMS_UNSENT, index, l4_index);
        g_frm_sms_background_send_info.l4_index = l4_index[0];
    }
    g_frm_sms_background_send_info.background_state = MMI_FRM_SMS_SEND_STATE_SENDING;
    mmi_frm_sms_background_send_sms_seg();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_move_sms_to_otherbox
 * DESCRIPTION
 *  move SMS to other box
 * PARAMETERS
 *  callback        [IN]        
 *  mod_src         [IN]        
 *  type            [IN]        mmi_frm_sms_app_msgbox_enum, (only OUTBOX is valid)
 *  index           [IN]        message list index
 *  dst_type        [IN]        mmi_frm_sms_app_msgbox_enum, (only DRAFT is valid)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_move_sms_to_otherbox(PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index, U8 dst_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 l4index[MMI_SMS_MAX_MSG_SEG];      

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_frm_sms_background_send_info.cur_l4_index = MMI_FRM_SMS_INVALID_INDEX;
    if (type == dst_type)
    {
        callback(NULL, MOD_MMI, MMI_FRM_SMS_ERROR);
    }
    mmi_frm_sms_get_sms_index(type, index, l4index);
    g_frm_sms_background_send_info.cur_l4_index = l4index[0];
	g_frm_sms_background_send_info.msgType = type;
    switch (dst_type)
    {
        case MMI_FRM_SMS_UNSENT:
            g_frm_sms_background_send_info.dst_status = SMSAL_STO_UNSENT;
            break;
            
        case MMI_FRM_SMS_DRAFTS:
            g_frm_sms_background_send_info.dst_status = SMSAL_STO_DRAFT;
            break;
            
        case MMI_FRM_SMS_OUTBOX:
            g_frm_sms_background_send_info.dst_status = SMSAL_STO_SENT;
            break;
            
        default:
            g_frm_sms_background_send_info.dst_status = SMSAL_INVALID_STATUS;
            break;
    }
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_background_pre_move_to_otherbox_req);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_set_background_save_to_setting
 * DESCRIPTION
 *  Set whether save message to sentbox
 * PARAMETERS
 *  isSave           [IN]        true if save message to sent box
 * RETURNS
 *  void
 *****************************************************************************/
mmi_frm_sms_result mmi_frm_sms_set_background_save_setting(BOOL isSave)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode = 0;
    U8 tempValue = (U8)(0x02 | isSave);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_SMS_BACKGROUND_SAVE_TO_SENT, &tempValue, DS_BYTE, &errorCode);
    if (errorCode == NVRAM_WRITE_SUCCESS)
    {
        return MMI_FRM_SMS_OK;
    }
    
    return MMI_FRM_SMS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_get_background_save_to_setting
 * DESCRIPTION
 *  get profile whether save message to sentbox
 * PARAMETERS
 *  isSave           [IN]        true if save message to sent box
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_get_background_save_setting(BOOL *isSave)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode = 0; 
    U8 tempValue = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SMS_BACKGROUND_SAVE_TO_SENT, &tempValue, DS_BYTE, &errorCode);
    if ((tempValue & 0x02) && tempValue != 0xff)
    {
        *isSave = (BOOL)0x01 & tempValue;
    }
    else
    {
        mmi_frm_sms_set_background_save_setting(TRUE);
        *isSave = TRUE;
    }
}


#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_api_result_handler
 * DESCRIPTION
 *  Handler for applications to process post SMS request actions, such as
 *  display result popup, delete SMS framework screens, and enable SPOF
 * PARAMETERS
 *  result      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_api_result_handler(mmi_frm_sms_api_result_handler_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[SmsCore.c] mmi_frm_sms_api_result_handler display_popup=%d request_type=%d*\n",
                         result->display_popup, result->request_type);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[SmsCore.c] mmi_frm_sms_api_result_handler result=%d delete_sms_screen=%d*\n",
                         result->result, result->delete_sms_screen);

    if (result->display_popup)
    {
        switch (result->result)
        {
            case MMI_FRM_SMS_OK:
            {
                if (result->request_type == MMI_FRM_SMS_REQ_SEND)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_SMS_SEND_SUCCESS),
                        IMG_SEND_SUCCESS_PIC_MSG,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) SUCCESS_TONE);
                    break;
                }
                else if (result->request_type == MMI_FRM_SMS_REQ_SAVE)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_SAVED),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) SUCCESS_TONE);
                    break;
                }
                else
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_DONE),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) SUCCESS_TONE);
                    break;
                }
            }
            case MMI_FRM_SMS_ERROR:
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SEND_FAILED),
                    IMG_SEND_FAIL_PIC_MSG,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                break;
            }
            case MMI_FRM_SMS_ABORT:
            {
                DisplayPopup(
                    (PU8) GetString(STR_ABORT_SENDING_SMS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
                break;
            }
            case MMI_FRM_SMS_NOTREADY:
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                    IMG_SEND_FAIL_PIC_MSG,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                break;
            }
            case MMI_FRM_SMS_RETURN:
            case MMI_FRM_SMS_END:
            {
                /* Do nothing due to pressing RSK back from entry destination number screen or entry SC number screen */
                break;
            }

            case MMI_FRM_SMS_END_FROM_SENDING:
            {
            #ifdef __MMI_UNIFIED_MESSAGE__
                mmi_msg_set_background_process(KAL_TRUE);
                mmi_msg_save_msg_after_send_req(SMSAL_STO_UNSENT, result->number);
            #endif /* __MMI_UNIFIED_MESSAGE__ */ 
                break;
            }
            case MMI_FRM_SMS_NUMINVALID:
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_PHB_NUM_INVALID),
                    IMG_GLOBAL_ERROR,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                break;
            }
            case MMI_FRM_SMS_DATAEMPTY:
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_FAILURE_DATA_EMPTY),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                break;
            }
            case MMI_FRM_SMS_DATAINVALID:
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_FAILURE_DATA_INVALID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                break;
            }
            case MMI_FRM_SMS_DATAEXCEED:
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_FAILURE_DATA_EXCEED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                break;
            }
            case MMI_FRM_SMS_SC_EMPTY:
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_FAILURE_SC_NUM_EMPTY),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                break;
            }
            case MMI_FRM_SMS_MEMFULL:
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_FAILURE_MEM_FULL),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) WARNING_TONE);
                break;
            }
            case MMI_FRM_SMS_MEMINSUFFICIENT:
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_FAILURE_MEM_CAP_EXCEEDED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                break;
            }
            default:
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SEND_FAILED),
                    IMG_SEND_FAIL_PIC_MSG,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                break;
            }
        }
    }

    if (result->delete_sms_screen)
    {
        mmi_frm_sms_delete_screen_history();
    }

    AlmEnableSPOF();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_api_entry_write_msg
 * DESCRIPTION
 *  Handler for applications to entry write msg screen with content
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_api_entry_write_msg(mmi_frm_sms_api_entry_write_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_entry_write_msg_req(data);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_fill_in_edit_buffer
 * DESCRIPTION
 *  Fill in EMS edit buffer
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_frm_sms_fill_in_edit_buffer(U8* buffer, U16 char_num, U8 dcs, BOOL is_reset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEMS;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_reset)
    {
        ReleaseEMSEditBuffer();
        pEMS = GetEMSDataForEdit(0, 1);
    }
    else
    {
        pEMS = GetEMSDataForEdit(0, 0);
    }

    EMSSetDCS(pEMS, dcs);
    
    if (char_num == 0)
    {
        return MMI_TRUE;
    }
    
    result = AddString(pEMS, buffer, char_num, NULL);

    if (result == EMS_OK)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_is_hide_send_sms_menu_item
 * DESCRIPTION
 *  enter sms option screen
 * PARAMETERS
 *  void        
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_frm_sms_is_hide_send_sms_menu_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_FEATURES__)
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
    {
     	return TRUE;
    }
#endif /* defined(__MMI_WLAN_FEATURES__) */

#ifdef __MMI_DUAL_SIM_MASTER__
	if (GetNumOfChild_Ext(MENU_MTPNP_SMS_SELECT_OPTION) == 0)
	{
		return TRUE;
	}
    else
    {
        return FALSE;
    }	 
#else /* __MMI_DUAL_SIM_MASTER__ */	
	return (!mmi_frm_sms_is_sms_valid());
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_is_sms_valid
 * DESCRIPTION
 *  whether enter sms for other module
 * PARAMETERS
 *  void        
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_frm_sms_is_sms_valid(void)
{
#ifdef __MMI_DUAL_SIM_MASTER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	E_MTPNP_AD_SIMCARD_USABLE_SIDE usableSide = MTPNP_AD_Get_UsableSide();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	switch(usableSide)
	{
		case MTPNP_AD_DUALSIM_USABLE:			
		case MTPNP_AD_SIMCARD1_USABLE:			
		case MTPNP_AD_SIMCARD2_USABLE:
			return TRUE;
	} 
#else /* __MMI_DUAL_SIM_MASTER__ */
	if ( mmi_bootup_is_sim_valid() && !mmi_bootup_get_active_flight_mode())
	{
		return TRUE;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sms_init
 * DESCRIPTION
 *  Init framework SMS: protocol event handler and data init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sms_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_frm_sms_cntx.mmi_frm_sms_ready = FALSE;
    g_frm_sms_cntx.mmi_frm_sms_msg_box_size = mmi_msg_get_msgbox_size();
    g_frm_sms_cntx.mmi_frm_sms_msg_seg_size = mmi_msg_get_seg_num();
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    g_frm_sms_cntx.mmi_frm_sms_delivery_report_setting = FALSE;
#endif 
#ifdef __MMI_MESSAGES_COPY__
    g_frm_sms_copy_info.is_aborted = FALSE;
#endif 
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
memset( (S8*) &g_frm_sms_background_send_info,
        MMI_FRM_SMS_INVALID_NUM,
        sizeof(mmi_frm_sms_background_send_info_struct));
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    /* init msgbox in case of receiving class 0 message before startup_begin_ind */
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_frm_sms_init_msgbox();
#else /* __MMI_DUAL_SIM_MASTER__ */
	if (!MTPNP_AD_Msgbox_Is_Init())
	{
		mmi_frm_sms_init_msgbox();
		MTPNP_AD_Msgbox_HasInit();
	}
	SetHiliteHandler(MENU_MTPNP_SMS_SELECT_SIM1_OPTION, mmi_msg_highlight_send_from_SIM1);
	SetHiliteHandler(MENU_MTPNP_SMS_SELECT_SIM2_OPTION, mmi_msg_highlight_send_from_SIM2);
	SetHiliteHandler(MENU_MTPNP_SMS_SELECT_SAVE_SIM1_OPTION, mmi_msg_highlight_save_from_SIM1);
	SetHiliteHandler(MENU_MTPNP_SMS_SELECT_SAVE_SIM2_OPTION, mmi_msg_highlight_save_from_SIM2);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    mmi_frm_sms_set_protocol_event_handler();
}

#endif /* 1 */ /* __MMI_MESSAGES_VERSION_3__ */

#endif /* __MOD_SMSAL__ */ 

