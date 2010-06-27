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
 *  VoiceMemoMsgHandler.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMI_include.h"
#ifdef __MMI_VOICE_MEMO__

#include "wgui.h"
#include "IdleAppProt.h"
#include "ProtocolEvents.h"
#include "DateTimeType.h"
#include "ThrdOsInterface.h"
#include "OSThreadInterfaceGprot.h"
#include "MiscFunctions.h"
/* JL #include "MainTaskGexdcl.h" */
#include "TaskInit.h"
#include "VoiceMemoResDef.h"
#include "VoiceMemoType.h"
#include "VoiceMemoProt.h"
#include "SettingProfile.h"
#include "gpioInc.h"

#ifdef MMI_ON_HARDWARE_P
#include "custom_util.h"
#endif /* MMI_ON_HARDWARE_P */ 

/*----------- global variable --------------*/
BOOL cmdProcessing = FALSE;

extern FuncPtr KbCBackVoiceMemoPause;
extern FuncPtr KbCBackVoiceMemoResume;
extern FuncPtr KbCBackVoiceMemoStop;
extern FuncPtr KbCBackVoiceMemoAbort;

#ifdef VOICE_RECOGNITION_TEST
/* external funcitons */
extern void tst_sys_trace(kal_uint8 *info);
extern void SendVRSampleGetInfoReq(void);
extern void ShowVoiceMemoOptionIdle(void);

/* external variables */
extern kal_bool g_VRQuasi;
extern kal_bool g_VRQuasiAuto;
#endif /* VOICE_RECOGNITION_TEST */ 


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoGetInfoReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoGetInfoReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        VoiceMemoSendMsg(MSG_ID_VM_GET_INFO_REQ, NULL, NULL);
        cmdProcessing = TRUE;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoRecordReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoRecordReq(U8 dir)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        mmi_vm_record_req_struct *msg_p;

        msg_p = OslConstructDataPtr(sizeof(mmi_vm_record_req_struct));
        msg_p->dir = dir;
        VoiceMemoSendMsg(MSG_ID_VM_RECORD_REQ, msg_p, NULL);
        cmdProcessing = TRUE;

    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoPauseReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoPauseReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        VoiceMemoSendMsg(MSG_ID_VM_PAUSE_REQ, NULL, NULL);
        cmdProcessing = TRUE;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoStopReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoStopReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        VoiceMemoSendMsg(MSG_ID_VM_STOP_REQ, NULL, NULL);
        cmdProcessing = TRUE;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoAbortReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoAbortReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        VoiceMemoSendMsg(MSG_ID_VM_ABORT_REQ, NULL, NULL);
        cmdProcessing = TRUE;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoResumeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoResumeReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        VoiceMemoSendMsg(MSG_ID_VM_RESUME_REQ, NULL, NULL);
        cmdProcessing = TRUE;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoAppendReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoAppendReq(UI_string_type filename)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        mmi_vm_append_req_struct *msg_p;

        msg_p = OslConstructDataPtr(sizeof(mmi_vm_append_req_struct));
        memcpy(msg_p->file_name, filename, MAX_VM_FILE_NAME * ENCODE_BYTE);
        VoiceMemoSendMsg(MSG_ID_VM_APPEND_REQ, msg_p, NULL);
        cmdProcessing = TRUE;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoPlayReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoPlayReq(UI_string_type filename)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        mmi_vm_play_req_struct *msg_p;

        msg_p = OslConstructDataPtr(sizeof(mmi_vm_play_req_struct));
        memcpy(msg_p->file_name, filename, MAX_VM_FILE_NAME * ENCODE_BYTE);
        VoiceMemoSendMsg(MSG_ID_VM_PLAY_REQ, msg_p, NULL);
        cmdProcessing = TRUE;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoDeleteReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoDeleteReq(UI_string_type filename)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        mmi_vm_del_req_struct *msg_p;

        msg_p = OslConstructDataPtr(sizeof(mmi_vm_del_req_struct));
        memcpy(msg_p->file_name, filename, MAX_VM_FILE_NAME * ENCODE_BYTE);
        msg_p->delete_all = FALSE;
        VoiceMemoSendMsg(MSG_ID_VM_DEL_REQ, msg_p, NULL);
        cmdProcessing = TRUE;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoDeleteAllReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoDeleteAllReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        mmi_vm_del_req_struct *msg_p;

        msg_p = OslConstructDataPtr(sizeof(mmi_vm_del_req_struct));
        strcpy((char*)msg_p->file_name, "*.vm");
        msg_p->delete_all = TRUE;
        VoiceMemoSendMsg(MSG_ID_VM_DEL_REQ, msg_p, NULL);
        cmdProcessing = TRUE;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoRenameReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  old     [IN]        
 *  new     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoRenameReq(UI_string_type old, UI_string_type new)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        mmi_vm_rename_req_struct *msg_p;

        msg_p = OslConstructDataPtr(sizeof(mmi_vm_rename_req_struct));
        memcpy(msg_p->old_name, old, MAX_VM_FILE_NAME * ENCODE_BYTE);
        memcpy(msg_p->new_name, new, MAX_VM_FILE_NAME * ENCODE_BYTE);
        VoiceMemoSendMsg(MSG_ID_VM_RENAME_REQ, msg_p, NULL);
        cmdProcessing = TRUE;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoGetInfoRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoGetInfoRes(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_get_info_rsp_struct *msg_p = (mmi_vm_get_info_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    EntryVoiceMemoList(msg_p->no_vm, msg_p->file_list, msg_p->more_entry, msg_p->free_space);
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoRecordRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoRecordRes(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_record_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result)
    {
        EntryVoiceMemoRecord();
    }
    else
    {
        VoiceMemoExceptionHandler(res_p->cause);
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoPlayRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoPlayRes(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_play_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result)
    {
        EntryVoiceMemoPlay();
    }
    else
    {
        VoiceMemoExceptionHandler(res_p->cause);
    }
#endif /* MMI_ON_HARDWARE_P */ 

}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoStopRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoStopRes(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_stop_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result.flag == L4C_OK)
    {
        VoiceMemoSaveFileName(res_p->file_name);
        KbCBackVoiceMemoStop();
    }
    else
    {
        VoiceMemoExceptionHandler(res_p->result.cause);
    }
#endif /* MMI_ON_HARDWARE_P */ 

}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoDeleteRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoDeleteRes(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_del_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result)
    {
        DisplayPopup(
            (PU8) GetString(VM_NOTICE_SUCCESS_TEXT),
            IMG_GLOBAL_ACTIVATED,
            1,
            VM_NOTIFYDURATION,
            (U8) SUCCESS_TONE);
    }
    else
    {
        VoiceMemoExceptionHandler(res_p->cause);
    }

    DeleteVoiceMemoHistoryNodesG();

#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoAbortRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoAbortRes(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_abort_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result)
    {
        KbCBackVoiceMemoAbort();
    }
    else
    {
        VoiceMemoExceptionHandler(res_p->cause);
    }
#endif /* MMI_ON_HARDWARE_P */ 

}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoPauseRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoPauseRes(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_pause_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result.flag == L4C_OK)
    {
        KbCBackVoiceMemoPause();
    }
    else
    {
        VoiceMemoExceptionHandler(res_p->result.cause);
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoResumeRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoResumeRes(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_resume_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result)
    {
        KbCBackVoiceMemoResume();
    }
    else
    {
        VoiceMemoExceptionHandler(res_p->cause);
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoAppendRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoAppendRes(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_append_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result)
    {
        EntryVoiceMemoAppend();
    }
    else
    {
        VoiceMemoExceptionHandler(res_p->cause);
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoRenameRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoRenameRes(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_rename_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result)
    {
        DisplayPopup(
            (PU8) GetString(VM_NOTICE_SUCCESS_TEXT),
            IMG_GLOBAL_ACTIVATED,
            1,
            VM_NOTIFYDURATION,
            (U8) SUCCESS_TONE);
    }
    else
    {
        VoiceMemoExceptionHandler(res_p->cause);
    }

    DeleteVoiceMemoHistoryNodesG();
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoRecordFinishInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoRecordFinishInd(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_record_finish_ind_struct *ind_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    /* if (ind_p->result == L4C_OK) */
    {
        VoiceMemoSaveFileName(ind_p->file_name);
        KbCBackRecordStop();
        VoiceMemoExceptionHandler(VM_RES_DISC_FULL);
        TurnOnBacklight(1);
    }
    //else
    //VoiceMemoExceptionHandler(VM_RES_FAIL);

    /*   mmi_vm_record_finish_ind_struct *ind_p = inMsg;
       if (ind_p->result)
       DisplayPopup ((PU8)GetString (VM_NOTICE_SUCCESS_TEXT), IMG_GLOBAL_ACTIVATED, 1, VM_NOTIFYDURATION, (U8)SUCCESS_TONE);
       else
       VoiceMemoExceptionHandler(res_p->cause); */
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoPlayFinishInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoPlayFinishInd(void *inMsg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_append_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (res_p->result)
    {
        GoBackHistory();
    }
    else
    {
        VoiceMemoExceptionHandler(res_p->cause);
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoSendMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoSendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->dest_mod_id = MOD_L4C;

    ilm_ptr->msg_id = (kal_uint16) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    msg_send_ext_queue(ilm_ptr);

#endif /* MMI_ON_HARDWARE_P */ 
}

#ifdef VOICE_RECOGNITION_TEST

#define FT_FAT_MAX_PEER_SIZE     2048
#define FT_FAT_MAX_FRAME_SIZE    FT_FAT_MAX_PEER_SIZE/64*56
#define MAX_VM_NAME 20
#define   MSG_ID_VRSAMPLE_IND                   0x000B


/*****************************************************************************
 * FUNCTION
 *  VRSampleStopRes
 * DESCRIPTION
 *  This function is based on and to replace the function "VoiceMemoStopRes" in VR Test Quasi mode.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VRSampleStopRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_vm_stop_rsp_struct *res_p = inMsg;
    mmi_vm_play_req_struct *msg_p = NULL;

    kal_uint8 strToTrace[MAX_VM_NAME + 1];
    kal_uint8 i;
    kal_uint8 c;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;

    if (res_p->result.flag == L4C_OK)
    {

        VoiceMemoSaveFileName(res_p->file_name);
        for (i = 0; i < MAX_VM_NAME; i++)
        {
            c = (kal_uint8) res_p->file_name[i] % 256;
            strToTrace[i] = c;
            if (0 == c)
            {
                break;
            }
        }
        strToTrace[MAX_VM_NAME] = 0;
        tst_sys_trace((kal_uint8*) strToTrace);
        /* Process the wave data here: wrap and send it to PC */
        /* Wrap And Send: res_p->file_name */

        msg_p = OslConstructDataPtr(sizeof(mmi_vm_play_req_struct));
        memcpy(msg_p->file_name, res_p->file_name, MAX_VM_FILE_NAME * ENCODE_BYTE);

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->sap_id = 0;    /* JOHN: use for status, 0:normal, 1:premature */
        ilm_ptr->dest_mod_id = MOD_TST_READER;

        ilm_ptr->msg_id = (kal_uint16) MSG_ID_VRSAMPLE_IND;
        ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
        ilm_ptr->peer_buff_ptr = NULL;
        msg_send_ext_queue(ilm_ptr);

        if (!g_VRQuasiAuto)
        {
            ShowVoiceMemoOptionIdle();  /* THIS SCREEN IS GOOD */
        }
    }
    else
    {
        if (!g_VRQuasiAuto)
        {
            VoiceMemoExceptionHandler(res_p->result.cause);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  VRSampleRecordRes
 * DESCRIPTION
 *  This function is based on the and to replace function "VoiceMemoRecordRes" in VR Test Quasi Automatic mode.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VRSampleRecordRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_record_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result)
    {
        tst_sys_trace((kal_uint8*) "PHONE: Rescord Res: OK!");
    }
}


/*****************************************************************************
 * FUNCTION
 *  VRSampleRecordFinishInd
 * DESCRIPTION
 *  This function is based on and to replace the function "VoiceMemoRecordFinishInd" in VR Test Quasi Automatic mode.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VRSampleRecordFinishInd(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_record_finish_ind_struct *ind_p = inMsg;
    mmi_vm_play_req_struct *msg_p = NULL;

    kal_uint8 strToTrace[MAX_VM_NAME + 1];
    kal_uint8 i;
    kal_uint8 c;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tst_sys_trace((kal_uint8*) "[PHONE] VRSampleRecordFinishInd() (Prematured!)");

    cmdProcessing = FALSE;

    {
        VoiceMemoSaveFileName(ind_p->file_name);
        for (i = 0; i < MAX_VM_NAME; i++)
        {
            c = (kal_uint8) ind_p->file_name[i] % 256;
            strToTrace[i] = c;
            if (0 == c)
            {
                break;
            }
        }
        strToTrace[MAX_VM_NAME] = 0;
        tst_sys_trace(strToTrace);
        /* Process the wave data here: wrap and send it to PC */
        /* Wrap And Send: res_p->file_name */

        msg_p = OslConstructDataPtr(sizeof(mmi_vm_play_req_struct));
        memcpy(msg_p->file_name, ind_p->file_name, MAX_VM_FILE_NAME * ENCODE_BYTE);

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->sap_id = 1;                    /* JOHN: 0:normal, 1:premature */
        ilm_ptr->dest_mod_id = MOD_TST_READER;  /* MOD_L4C; */

        ilm_ptr->msg_id = (kal_uint16) MSG_ID_VRSAMPLE_IND;
        ilm_ptr->local_para_ptr = (local_para_struct*) msg_p;
        ilm_ptr->peer_buff_ptr = NULL;
        msg_send_ext_queue(ilm_ptr);

        if (!g_VRQuasiAuto)
        {
            /* KbCBackRecordStop(); NOT THIS SCREEN */
            ShowVoiceMemoOptionIdle();  /* THIS SCREEN IS GOOD */
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  VRSampleDeleteRes
 * DESCRIPTION
 *  This function is based on and to replace the function "VoiceMemoDeleteRes" in VR Test Quasi mode.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VRSampleDeleteRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vm_del_rsp_struct *res_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
    if (res_p->result)
    {
        tst_sys_trace((kal_uint8*) "[PHONE] Successfully delete a file");
    }
    else
    {
        tst_sys_trace((kal_uint8*) "[PHONE] Delete file error");
    }

    SendVRSampleGetInfoReq();
}


/*****************************************************************************
 * FUNCTION
 *  VRSampleGetInfoRes
 * DESCRIPTION
 *  This function is based on and to replace the function "VoiceMemoGetInfoRes" in VR Test Quasi mode.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void VRSampleGetInfoRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmdProcessing = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  VRSampleRecordReq
 * DESCRIPTION
 *  This function is based on and to replace the function "VoiceMemoRecordReq" in VR Test Quasi Automatic mode.
 * PARAMETERS
 *  dir     [IN]        
 *  void*          inMsg(?)
 * RETURNS
 *  kal_bool    KAL_TRUE if no errors
 *****************************************************************************/
kal_bool VRSampleRecordReq(U8 dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmdProcessing)
    {
        tst_sys_trace((kal_uint8*) "[PHONE] VRSampleRecordReq");
        VoiceMemoRecordReq(dir);
        return KAL_TRUE;
    }
    else
    {
        tst_sys_trace((kal_uint8*) "[PHONE]ERROR: NOT VoiceMemoRecordReq -- cmdProcessing");
        return KAL_FALSE;
    }
}
#endif /* VOICE_RECOGNITION_TEST */ 
#endif /* __MMI_VOICE_MEMO__ */ /* VM_SUPPORT */

