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
 * vObjects.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is intends for common screen and functionality for vObjects.
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
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VOBJECTS_C
#define _MMI_VOBJECTS_C

#if defined(__MMI_BIP_SUPPORT__) ||defined(__MMI_OPP_SUPPORT__) || defined(__MMI_IRDA_SUPPORT__)
#include "AlarmFrameworkProt.h"
#include "SettingProfile.h"
#endif

#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__)|| defined(__MMI_VBOOKMARK__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "FileManagerGProt.h"
#include "vObjects.h"
#include "vCard.h"
#include "vCalendar.h"
#ifdef __MMI_VBOOKMARK__
#include "vBookmark.h"
#endif
#include "IdleAppDef.h" /* Idle Screen Flag */
#include "IdleAppProt.h"
#include "SettingProfile.h"
#include "ProfileGProts.h"
#include "gpioInc.h"
#include "Fmt_struct.h"
#include "CallManagementGprot.h"
#include "MessagesMiscell.h"
#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"      /* IrDA support */
#endif 
#include "ctype.h"      /* For tolower() */
#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"

#include "AlarmFrameworkProt.h"

#define MMIAPI_USING_SMS        /* Reister SMS from mmiapi. */
#include "mmiapi.h"
#include "mmiapi_struct.h"


#ifdef __MMI_OPP_SUPPORT__
#include "OPPMMIGprots.h"
#endif 

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
vobj_context_struct g_vobj_cntx;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
const S8 *g_vobj_encoding[VOBJ_EN_TOTAL] = 
{
    "7BIT",
    "8BIT",
    "QUOTED-PRINTABLE",
    "BASE64",
    "X-"
};

const S8 *g_vobj_paras[VOBJ_PARA_TOTAL] = 
{
    "LANGUAGE",
    "CHARSET",
    "ENCODING"
};

const S8 *g_vobj_charset[VOBJ_CH_TOTAL] = 
{
    "UTF-8",
    "BIG5",
    "UTF-7"
};

/* 
 * Global Function
 */
#ifdef __USB_IN_NORMAL_MODE__    
extern pBOOL mmi_usb_is_in_mass_storage_mode(void);
#endif
/* extern U8 Tolower(U8); */

/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_increase_sms_register
 * DESCRIPTION
 *  Add port number into sms register array
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_increase_sms_register(U16 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_vobj_cntx.sms_port_reg[g_vobj_cntx.sms_port_reg_count] = port;
    g_vobj_cntx.sms_port_reg_count++;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_set_sms_register
 * DESCRIPTION
 *  Set sms port to receive vobject
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_set_sms_register(void)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DUAL_SIM_MASTER__
    if (g_vobj_cntx.sms_port_reg_count / 2 < VOBJ_TYPE_NUM)
    {
        mmi_vobj_register_sms_req(g_vobj_cntx.sms_port_reg[g_vobj_cntx.sms_port_reg_count / 2]);
        SetProtocolEventHandler(mmi_vobj_register_sms_rsp, MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP);    
    }
#else
    if (g_vobj_cntx.sms_port_reg_count < VOBJ_TYPE_NUM)
    {    
        mmi_vobj_register_sms_req(g_vobj_cntx.sms_port_reg[g_vobj_cntx.sms_port_reg_count]);    
        SetProtocolEventHandler(mmi_vobj_register_sms_rsp, MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP);    
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_register_sms_rsp
 * DESCRIPTION
 *  Response message of registering L4 modules for incoming messages.
 * PARAMETERS
 *  info        [IN]        Message response strut variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_register_sms_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_register_port_rsp_struct *local;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = (mmiapi_sms_register_port_rsp_struct*) info;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_REGISTER_VCARD_SMS_RSP, local->result, local->cause);

    g_vobj_cntx.sms_port_reg_count++;
    mmi_vobj_set_sms_register();

//#ifdef __MMI_VCALENDAR__
//    mmi_vobj_register_sms_req(VOBJ_VCLNDR_PORT);
//    SetProtocolEventHandler(mmi_vobj_register_vclndr_sms_rsp, MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP);
//#endif /* __MMI_VCALENDAR__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_init
 * DESCRIPTION
 *  Initialization of vobject application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_INIT);

    memset(&g_vobj_cntx, 0, sizeof(vobj_context_struct));

    /* Clear file buffer */
#ifdef __MMI_VCARD__
    mmi_vobj_increase_sms_register(VOBJ_VCARD_PORT);
    mmi_vcard_init();
#endif /* __MMI_VCARD__ */ 

#ifdef __MMI_VCALENDAR__
    mmi_vobj_increase_sms_register(VOBJ_VCLNDR_PORT);
    mmi_vclndr_init();
#endif /* __MMI_VCALENDAR__ */ 

#ifdef __MMI_VBOOKMARK__
    mmi_vobj_increase_sms_register(VOBJ_VBKM_PORT);
    mmi_vbkm_init();
#endif /* __MMI_VBOOKMARK__ */ 

    g_vobj_cntx.sms_port_reg_count = 0;
    mmi_vobj_set_sms_register();
    SetProtocolEventHandler(mmi_vobj_sms_receive_ind, MSG_ID_MMIAPI_SMS_IND);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_deinit
 * DESCRIPTION
 *  Deinitialize function for vObjects. Free allocated buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_DEINIT);

#if defined(__MMI_VCALENDAR__)
    mmi_vclndr_deinit();
#endif 

#if defined(__MMI_VCARD__)
    mmi_vcard_deinit();
#endif 

#if defined(__MMI_VBOOKMARK__)
    mmi_vbkm_deinit();
#endif 
}

#ifdef __MMI_IRDA_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_irda_receive_ind
 * DESCRIPTION
 *  Indication handler when receiving a vObject message from IrDA.
 *  If it's in Idle screen, process the object immediatelly,
 *  otherwise, insert into the queue.
 * PARAMETERS
 *  path_src        [IN/OUT]        File path name of the vobject received from irda
 *  type            [IN]            Type of the object (vCard or vCalendar)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_irda_receive_ind(void *path_src, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *path_name;
    S32 result;
    U8 cursor;
    U8 obj_type;
    S32 check_result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_IRDA_RECEIVE_IND);

    if (type == FMGR_TYPE_VCF)
    {
        obj_type = MMI_VOBJ_VCARD;
    }
    else if (type == FMGR_TYPE_VCS)
    {
        obj_type = MMI_VOBJ_VCLNDR;
    }
#if defined(__MMI_VBOOKMARK__)
    else
    {
	    obj_type = MMI_VOBJ_VBKM;
    }
#endif /*__MMI_VBOOKMARK__*/			

    /* Wrtie object to tempoary file, parsing later. */
    if (check_result == FS_NO_ERROR)
    {
        if ((cursor = mmi_vobj_get_file_buffer_slot()) != 255)
        {
#if defined(__MMI_VBOOKMARK__)
			if (type == MMI_VOBJ_VBKM)
			{
				mmi_vbkm_recv_file_save_file_info(path_src, VBKM_RECV_VIA_IRDA);
			}
#endif /*__MMI_VBOOKMARK__*/			
            path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH);

            /* diamond, always enter pending vObj screen from idle screen */
            mmi_vobj_get_full_tmp_path_name(cursor, path_name, obj_type);

            FS_Delete((U16*) path_name);

            result = FS_Rename((U16*) path_src, (U16*) path_name);

            if (result == FS_NO_ERROR)
            {
                FS_SetAttributes((const WCHAR *)path_name, (U8) FS_ATTR_HIDDEN);
                mmi_vobj_increase_file_buffer_counter(obj_type);

                mmi_vobj_receive_ind_prompt(obj_type);
            }

            OslMfree(path_name);
        }
        else
        {
            FS_Delete((U16*) path_src);
            DisplayPopup((PU8) GetString(STR_ID_VOBJ_UNFINISHED), 
                IMG_GLOBAL_ERROR, FALSE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_irda_progress_scr_del_callback
 * DESCRIPTION
 *  Callback function when Irda progressing screen is deleted
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vobj_irda_progress_scr_del_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_irda_is_sending())  /* if Irda is sending, do not deleted this screen */
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
 *  mmi_vobj_entry_irda_processing_screen
 * DESCRIPTION
 *  Display progressing screen when sending vobject via irda.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_entry_irda_processing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_ENTRY_IRDA_PROCESSING_SCREEN);

    /* Call Exit Handler */
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_ID_VOBJ_IRDA_FORWARD_PROCESSING, NULL, mmi_vobj_entry_irda_processing_screen, NULL);

    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    /* Show Sending screen */
    ShowCategory165Screen(
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (UI_string_type) GetString(STR_GLOBAL_SENDING),
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetDelScrnIDCallbackHandler(
        SCR_ID_VOBJ_IRDA_FORWARD_PROCESSING,
        (HistoryDelCBPtr) mmi_vobj_irda_progress_scr_del_callback);

    /* Set Right softkey function to abort sending */
    SetRightSoftkeyFunction(mmi_irda_obex_snd_abort, KEY_EVENT_UP);

    /* Set Exit function for Sending Screen */
    /* SetGenericExitHandler(SCR_ID_VOBJ_IRDA_FORWARD_PROCESSING, NULL, mmi_vobj_entry_irda_processing_screen); */
}
#endif /* __MMI_IRDA_SUPPORT__ */ 

#if defined(__MMI_OPP_SUPPORT__) || defined(__MMI_FTP_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_opp_receive_ind
 * DESCRIPTION
 *  Indication handler when receiving a vObject message from BT.
 *  If it's in Idle screen, process the object immediatelly,
 *  otherwise, insert into the queue.
 * PARAMETERS
 *  path_src        [IN/OUT]        File path name of the vobject received from opp
 *  type            [IN]            Type of the object (vCard or vCalendar)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_opp_receive_ind(void *path_src, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *path_name;
    S32 result;
    U8 cursor;
    U8 obj_type = MMI_VOBJ_UNRECOGNIZED;
    S32 check_result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_IRDA_RECEIVE_IND);

    if (type == FMGR_TYPE_VCF)
    {
        obj_type = MMI_VOBJ_VCARD;
    }
    else if(type == FMGR_TYPE_VCS)
    {
        obj_type = MMI_VOBJ_VCLNDR;
    }
#if defined(__MMI_VBOOKMARK__)
    else
    {
	    obj_type = MMI_VOBJ_VBKM;
    }
#endif /*__MMI_VBOOKMARK__*/

    /* Wrtie object to tempoary file, parsing later. */
    if (check_result == FS_NO_ERROR)
    {
        if ((cursor = mmi_vobj_get_file_buffer_slot()) != 255)
        {
#if defined(__MMI_VBOOKMARK__)
			if (type == MMI_VOBJ_VBKM)
			{
				mmi_vbkm_recv_file_save_file_info(path_src, VBKM_RECV_VIA_BT);
			}
#endif /*__MMI_VBOOKMARK__*/

            path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH);

            /* diamond, always enter pending vObj screen from idle screen */
            mmi_vobj_get_full_tmp_path_name(cursor, path_name, obj_type);

            FS_Delete((U16*) path_name);

            result = FS_Rename((U16*) path_src, (U16*) path_name);

            if (result == FS_NO_ERROR)
            {
                mmi_vobj_increase_file_buffer_counter(obj_type);

                FS_SetAttributes((const WCHAR *)path_name, (U8) FS_ATTR_HIDDEN);

                mmi_vobj_receive_ind_prompt(obj_type);
            }

            OslMfree(path_name);
        }
        else
        {
            FS_Delete((U16*) path_src);
            DisplayPopup((PU8) GetString(STR_ID_VOBJ_UNFINISHED), 
                IMG_GLOBAL_ERROR, FALSE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
        }
    }
    else
    {
        DisplayPopup((U8*) GetString(GetFileSystemErrorString(check_result)),
            IMG_GLOBAL_ERROR, FALSE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);    
    }
}

#endif /* defined(__MMI_OPP_SUPPORT__) || defined(__MMI_FTP_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_register_sms_req
 * DESCRIPTION
 *  Register to L4 modules for incoming messages.
 * PARAMETERS
 *  port        [IN]        Port nnumber to be regirstered
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_register_sms_req(U16 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_register_port_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_REGISTER_SMS_REQ, port);

    myMsgPtr = (mmiapi_sms_register_port_req_struct*) OslConstructDataPtr(sizeof(mmiapi_sms_register_port_req_struct));
    myMsgPtr->port_number = port;
    myMsgPtr->enable = KAL_TRUE;
    myMsgPtr->remove_reminder_data = KAL_TRUE;
    myMsgPtr->blocking_data = NULL;
#ifdef __MMI_DUAL_SIM_MASTER__
    myMsgPtr->isSlave = g_vobj_cntx.sms_port_reg_count % 2; // 0:master, 1:slave
#endif    

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
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
#ifdef __MMI_VCALENDAR__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VCALENDAR__ */ 
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
#ifdef __MMI_VBOOKMARK__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VBOOKMARK__ */ 
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
#ifdef __MMI_VBOOKMARK__
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
#endif /* __MMI_VBOOKMARK__ */ 
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_sms_receive_ind
 * DESCRIPTION
 *  indication of receive incoming SMS vobject message.
 * PARAMETERS
 *  info        [IN]        Message indication struct variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_sms_receive_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_ind_struct *local;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = (mmiapi_sms_ind_struct*) info;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_SMS_RECEIVE_IND, local->port_number);

    if (local->port_number == VOBJ_VCARD_PORT || local->port_number == VOBJ_VCLNDR_PORT
#ifdef __MMI_VBOOKMARK__
		|| local->port_number == VOBJ_VBKM_PORT
#endif /* __MMI_VBOOKMARK__ */ 
       )
    {
        mmi_vobj_sms_get_incoming_msg_req((U16) local->port_number);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_sms_get_incoming_msg_req
 * DESCRIPTION
 *  request to retrieve incoming vobject sms back.
 * PARAMETERS
 *  port        [IN]        Port number of the message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_sms_get_incoming_msg_req(U16 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_get_incoming_msg_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_SMS_GET_INCOMING_MSG_REQ);

    myMsgPtr =
        (mmiapi_sms_get_incoming_msg_req_struct*)
        OslConstructDataPtr(sizeof(mmiapi_sms_check_incoming_msg_req_struct));
    myMsgPtr->port_number = port;
    myMsgPtr->blocking_data = NULL;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    g_vobj_cntx.curr_sms_port = port;

    SetProtocolEventHandler(mmi_vobj_sms_get_incoming_msg_rsp, MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_sms_get_incoming_msg_rsp
 * DESCRIPTION
 *  response to retrieve incoming vobject sms.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_sms_get_incoming_msg_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_get_incoming_msg_rsp_struct *local;
    FS_HANDLE fh;
    S8 *path_name;
    U8 cursor;
    U8 type = MMI_VOBJ_UNRECOGNIZED;
    U32 write_len;
    int result;
    S32 check_result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_SMS_GET_INCOMING_MSG_RSP);

    local = (mmiapi_sms_get_incoming_msg_rsp_struct*) info;
    path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH);

    if (check_result == FS_NO_ERROR)
    {
        if ((cursor = mmi_vobj_get_file_buffer_slot()) != 255)
        {
            if (g_vobj_cntx.curr_sms_port == VOBJ_VCARD_PORT)
            {
                type = MMI_VOBJ_VCARD;
            }
            else if(g_vobj_cntx.curr_sms_port == VOBJ_VCLNDR_PORT)
            {
                type = MMI_VOBJ_VCLNDR;
            }
#ifdef __MMI_VBOOKMARK__
	        else
	        {
		        type = MMI_VOBJ_VBKM;
	        }
#endif /* __MMI_VBOOKMARK__ */ 

            /* diamond, always enter pending vObj screen from idle screen */
            mmi_vobj_get_full_tmp_path_name(cursor, path_name, type);

            fh = FS_Open((U16*) path_name, FS_CREATE_ALWAYS | FS_READ_WRITE);

            if (fh > 0)
            {
                /* hide this received file*/
                FS_SetAttributes((const WCHAR *)path_name, (U8) FS_ATTR_HIDDEN);
                result = FS_Write(fh, local->message, local->message_len, (U32*) & write_len);
                FS_Close(fh);

                if (result == FS_NO_ERROR)
                {
                    mmi_vobj_increase_file_buffer_counter(type);

                    mmi_vobj_receive_ind_prompt(type);
                }
                else
                {
                    DisplayPopup
                        ((PU8) GetString(GetFileSystemErrorString(result)), 
                        IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                    return;
                }
            }
            else
            {
                DisplayPopup
                    ((PU8) GetString(GetFileSystemErrorString(fh)), 
                    IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                return;
            }
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_ID_VOBJ_UNFINISHED), 
                IMG_GLOBAL_ERROR, FALSE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
        }
    }

    OslMfree(local->message);
    OslMfree(path_name);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_is_pending_object
 * DESCRIPTION
 *  Check if there any pending objects.
 *  Criterion: if buffer size > 0 and rename succesfully.
 *  If there is any pending obejct, rename the temporary file.
 * PARAMETERS
 *  void
 * RETURNS
 *  ture if there is any pending object, otherwiser false.
 *****************************************************************************/
BOOL mmi_vobj_is_pending_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type;
    S8 *src_path;
    S8 *dst_path;
    S32 result;
    FS_HANDLE fd_src, fd_des;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_IS_PENDING_OBJECT);

#ifdef __USB_IN_NORMAL_MODE__    
    if (mmi_usb_is_in_mass_storage_mode())
    {
    	return FALSE;
    }
#endif    

    while (mmi_vobj_get_file_buffer_size())
    {
        /* Pending vObj: do not clear this vObj if MMI is in idle screen */
        if (g_keylock_context.gKeyPadLockFlag)
        {
		return TRUE;
        }

        src_path = OslMalloc(VOBJ_MAX_PATH_LENGTH);
        dst_path = OslMalloc(VOBJ_MAX_PATH_LENGTH);

        type = mmi_vobj_check_curr_file_type();

        mmi_vobj_get_full_tmp_path_name(g_vobj_cntx.buffer_begin, src_path, type);

        mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin, dst_path, type);

        /* vobject may be renamed but not handled, we delete src file after rename to check the status */
        fd_src = FS_Open((U16*)src_path, FS_READ_ONLY);
        fd_des = FS_Open((U16*)dst_path, FS_READ_ONLY);
        if (fd_src >= FS_NO_ERROR)
        {
            FS_Close(fd_src);
            FS_Close(fd_des);
            FS_Delete((U16*) dst_path);
            result = FS_Rename((U16*) src_path, (U16*) dst_path);
        }  
        else if (fd_des >= FS_NO_ERROR)
        {
            FS_Close(fd_des);
            OslMfree(src_path);
            OslMfree(dst_path);
            return TRUE;
        }
        
        if (result == FS_NO_ERROR)
        {
            FS_Delete((U16*) src_path);            
            OslMfree(src_path);
            OslMfree(dst_path);    
            return TRUE;
        }
        else
        {
            mmi_vobj_clear_one_file_buffer();
        }
        
        OslMfree(src_path);
        OslMfree(dst_path);    
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_receive_ind_prompt
 * DESCRIPTION
 *  Display prompt message according to the current screen.
 *  Shall follow the SMS prompt scenario.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_receive_ind_prompt(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pp_flag;
    MMI_ALERT_TYPE alertType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In idle screen */
    if (g_idle_context.IsOnIdleScreen)
    {
        TurnOnBacklight(1);
        mmi_file_arrival_tone();   /* Same action as receive SMS */
        EntryIdleScreen(); /* mmi_vobj_entry_recv_object(); */
    }
    /* In insert sim screen */
    else if (g_idle_context.IsOnSimErrorScreen)
    {
        TurnOnBacklight(1);
        mmi_file_arrival_tone();   /* Same action as receive SMS */
        if (GetActiveScreenId() == SCR_SIM_BLOCK)
        {
            EntryScrnSimBlockRsp();
        }
        else
        {
            EntryScrnSimErrorScreen();
        }
    }
    /* Not in idle screen and not in call or wap over csd*/
    else if (!isInCall() || (isInCall() && GetWapCallPresent()))
    {
        alertType = GetMtCallAlertTypeEnum();
        pp_flag = GetInterruptPopupDisplay();
    
        if ((pp_flag & POPUP_DSPL_ON) == 0)
        {
            if ((pp_flag & POPUP_TONE_ON) == POPUP_TONE_ON)
            {
                if ((alertType == MMI_VIBRATION_ONLY) || (alertType == MMI_VIBRATION_AND_RING)
                    || (alertType == MMI_VIBRATION_THEN_RING))
                {
                    if (!AlmIsTonePlaying())
                    {
                        PlaySmsVibratorOnce();
                    }
                }
                playRequestedTone(FILE_ARRIVAL_TONE);
            }
            return;
        }
        mmi_vboj_entry_recv_popup(type);
    }
    else
    {
        mmi_file_arrival_tone();   /* Same action as receive SMS */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vboj_entry_recv_popup
 * DESCRIPTION
 *  Display popup indication screen whe receiving vobjects.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vboj_entry_recv_popup(U8 type)
{
#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* vobj_object_type_enum type; */
    U16 strId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* type = mmi_vobj_check_curr_file_type(); */

#ifdef __MMI_VCARD__
    if (type == MMI_VOBJ_VCARD)
    {
        strId = STR_ID_VOBJ_RECV_VCARD;
    }
#endif /* __MMI_VCARD__ */ 

#ifdef __MMI_VCALENDAR__
    if (type == MMI_VOBJ_VCLNDR)
    {
        strId = STR_ID_VOBJ_RECV_VCLNDR;
    }
#endif /* __MMI_VCALENDAR__ */ 

#ifdef __MMI_VBOOKMARK__
    if (type == MMI_VOBJ_VBKM)
    {
        strId = STR_ID_VOBJ_RECV_VBKM;
    }
#endif /* __MMI_VBOOKMARK__ */ 

    DisplayPopup((U8*) GetString(strId), IMG_GLOBAL_WARNING, FALSE, UI_POPUP_NOTIFYDURATION_TIME, 0);
    mmi_file_arrival_tone();   /* Same action as receive SMS */

#endif /* defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_exit_recv_object
 * DESCRIPTION
 *  Exit handler of display indication screen whe receiving vobjects.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_exit_recv_object(void)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_entry_recv_object
 * DESCRIPTION
 *  Display indication screen whe receiving vobjects.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_entry_recv_object(void)
{
#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    vobj_object_type_enum type;
    U16 strId = 0;
    FuncPtr fPtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_vobj_check_curr_file_type();

    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_ID_VOBJ_RECV_OBJECT, mmi_vobj_exit_recv_object, NULL, NULL);

    TurnOnBacklight(TRUE);

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_ENTRY_RECV_OBJECT, type);

#ifdef __MMI_VCARD__
    if (type == MMI_VOBJ_VCARD)
    {
        strId = STR_ID_VOBJ_RECV_VCARD;
        fPtr = (FuncPtr) mmi_vcard_recv_from_idle_screen;
    }
#endif /* __MMI_VCARD__ */ 

#ifdef __MMI_VCALENDAR__
    if (type == MMI_VOBJ_VCLNDR)
    {
        strId = STR_ID_VOBJ_RECV_VCLNDR;
        fPtr = (FuncPtr) mmi_vclndr_recv_file_pre_entry_options;
    }
#endif /* __MMI_VCALENDAR__ */ 

#ifdef __MMI_VBOOKMARK__
    if (type == MMI_VOBJ_VBKM)
    {
        strId = STR_ID_VOBJ_RECV_VBKM;
        fPtr = (FuncPtr) mmi_vbkm_recv_file_pre_entry_options;
    }
#endif /* __MMI_VBOOKMARK__ */ 

    MMI_ASSERT(fPtr != NULL);

    /* Pending vObj: add handler for keypad lock */
    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
        ShowCategory154Screen(
            0,
            0,
            STR_GLOBAL_OPTIONS,
            0,
            STR_GLOBAL_CANCEL,
            0,
            (U8*) GetString(strId),
            NULL,
            IMG_GLOBAL_INFO,
            NULL);

        SetLeftSoftkeyFunction(fPtr, KEY_EVENT_UP);

        SetRightSoftkeyFunction(mmi_vobj_entry_recv_object_abort, KEY_EVENT_UP);
        SetKeyHandler(mmi_vobj_abort_object, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        ShowCategory154Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*) GetString(strId),
            NULL,
            IMG_GLOBAL_INFO,
            NULL);
    }

    /* SetGenericExitHandler(SCR_ID_VOBJ_RECV_OBJECT, NULL, mmi_vobj_entry_recv_object); */
#endif /* defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_entry_recv_object_abort
 * DESCRIPTION
 *  display abort confirmation screen when receiving an vobjects.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_entry_recv_object_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_VOBJ_CANCEL_QUERY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetKeyHandler(mmi_vobj_abort_object, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_vobj_abort_object, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* SetGenericExitHandler(SCR_ID_VOBJ_REVC_OBJECT_ABORT, NULL, NULL); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_abort_object
 * DESCRIPTION
 *  abort function for vobject screen.
 *  1. clear file buffer.
 *  2. go to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_abort_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vobj_clear_one_file_buffer();
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_clear_one_file_buffer
 * DESCRIPTION
 *  remove current indexing file from file buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_clear_one_file_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *path_name;
    U8 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_CLEAR_ONE_FILE_BUFFER);

    path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH);

    /* Delete temp file first. */
    type = mmi_vobj_check_curr_file_type();

    mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin, path_name, type);
    FS_Delete((U16*) path_name);
    mmi_vobj_get_full_tmp_path_name(g_vobj_cntx.buffer_begin, path_name, type);
    FS_Delete((U16*) path_name);

    /* Decrease counter */
    mmi_vobj_decrease_file_buffer_counter();

    OslMfree(path_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_get_file_buffer_size
 * DESCRIPTION
 *  return number of current pending objects
 * PARAMETERS
 *  void
 * RETURNS
 *  number of objects
 *****************************************************************************/
U8 mmi_vobj_get_file_buffer_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_VOBJ_GET_FILE_BUFFER_SIZE, g_vobj_cntx.buffer_begin, g_vobj_cntx.buffer_end);

    if (g_vobj_cntx.buffer_begin <= g_vobj_cntx.buffer_end)
    {
        return g_vobj_cntx.buffer_end - g_vobj_cntx.buffer_begin;
    }
    else
    {
        return VOBJ_MAX_TEMP_FILE - g_vobj_cntx.buffer_begin + g_vobj_cntx.buffer_end + 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_get_file_buffer_slot
 * DESCRIPTION
 *  return current buffer position to insert an object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vobj_get_file_buffer_slot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vobj_get_file_buffer_size() < VOBJ_MAX_TEMP_FILE)
    {
        return g_vobj_cntx.buffer_end;
    }
    else
    {
        return 255;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_increase_file_buffer_counter
 * DESCRIPTION
 *  increase file buffer counter by 1 and insert into event list
 * PARAMETERS
 *  type        [IN]        Type of vobject
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_increase_file_buffer_counter(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VBOOKMARK__
    MMI_ASSERT(g_vobj_cntx.buffer_end <= VOBJ_MAX_TEMP_FILE);

    g_vobj_cntx.obj_list[g_vobj_cntx.buffer_end] = type;
#else
    if (type == MMI_VOBJ_VCARD)
    {
        g_vobj_cntx.obj_list &= (~(0x01 << g_vobj_cntx.buffer_end));
    }
    else
    {
        g_vobj_cntx.obj_list |= (0x01 << g_vobj_cntx.buffer_end);
    }
#endif

    /* shift write cursor */
    if (g_vobj_cntx.buffer_end < VOBJ_MAX_TEMP_FILE)
    {
        g_vobj_cntx.buffer_end++;
    }
    else
    {
        g_vobj_cntx.buffer_end = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_decrease_file_buffer_counter
 * DESCRIPTION
 *  decrease file conter by 1.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vobj_decrease_file_buffer_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vobj_get_file_buffer_size() > 0)
    {
        if (g_vobj_cntx.buffer_begin < VOBJ_MAX_TEMP_FILE)
        {
            g_vobj_cntx.buffer_begin++;
        }
        else
        {
            g_vobj_cntx.buffer_begin = 0;
        }

        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_fs_check_folder
 * DESCRIPTION
 *  check if vObject folder exists, if not, create the folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vobj_fs_check_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    S8 *path;
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* S8 flag = FALSE; */

    path = OslMalloc(VOBJ_MAX_PATH_LENGTH);

    mmi_vobj_get_full_path_name(0, path, MMI_VOBJ_UNRECOGNIZED);

    fh = FS_Open((U16*) path, FS_OPEN_DIR | FS_READ_ONLY);

    if (fh <= 0)    /* Folder Does Not Exist */
    {
        result = FS_CreateDir((U16*) path);
        //if(result == FS_NO_ERROR) /*Create Success*/
        //        flag =  TRUE;
    }
    else
    {
        /* Folder Exists */
        FS_Close(fh);
        /* flag = TRUE; */
    }

    OslMfree(path);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_check_curr_file_type
 * DESCRIPTION
 *  get current type of file
 * PARAMETERS
 *  void
 * RETURNS
 *  enum value of type
 *****************************************************************************/
vobj_object_type_enum mmi_vobj_check_curr_file_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VBOOKMARK__
    MMI_ASSERT(g_vobj_cntx.buffer_begin <= VOBJ_MAX_TEMP_FILE);

    return g_vobj_cntx.obj_list[g_vobj_cntx.buffer_begin];
#else
    if (g_vobj_cntx.obj_list & (0x01 << g_vobj_cntx.buffer_begin))
    {
        return MMI_VOBJ_VCLNDR;
    }
    else
    {
        return MMI_VOBJ_VCARD;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_get_full_tmp_path_name
 * DESCRIPTION
 *  This function is to generate full file path and name to store
 *  vCard and vCalendar objects from the network.
 * PARAMETERS
 *  index       [IN]            Sequence number of the object
 *  result      [IN/OUT]        String buffer to store the result path and name
 *  type        [IN]            Type of the object, vCard/vCalendar
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_get_full_tmp_path_name(U8 index, S8 *result, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_path[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_VOBJ_VCARD)
    {
        sprintf(
            ascii_path,
            "%c:\\%s\\~vcard%s%d.tmp",
            VOBJ_DRV,
            (S8*) VOBJ_FILE_PATH,
            (S8*) VOBJ_TMP_FILE_NAME,
            index);
    }
    else if (type == MMI_VOBJ_VCLNDR)
    {
        sprintf(
            ascii_path,
            "%c:\\%s\\~vcalendar%s%d.tmp",
            VOBJ_DRV,
            (S8*) VOBJ_FILE_PATH,
            (S8*) VOBJ_TMP_FILE_NAME,
            index);
    }
#ifdef __MMI_VBOOKMARK__
    else if (type == MMI_VOBJ_VBKM)
    {
        sprintf(
            ascii_path,
            "%c:\\%s\\~vbookmark%s%d.tmp",
            VOBJ_DRV,
            (S8*) VOBJ_FILE_PATH,
            (S8*) VOBJ_TMP_FILE_NAME,
            index);
    }
#endif /* __MMI_VBOOKMARK__ */ 

    mmi_asc_to_ucs2(result, ascii_path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_get_full_path_name
 * DESCRIPTION
 *  This function is to generate full file path and name to store
 *  vCard and vCalendar objects from the network.
 * PARAMETERS
 *  index       [IN]            Sequence number of the object
 *  result      [IN/OUT]        String buffer to store the result path and name
 *  type        [IN]            Type of the object, vCard/vCalendar
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_get_full_path_name(U8 index, S8 *result, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_path[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_VOBJ_VCARD)
    {
        sprintf(ascii_path, "%c:\\%s\\~vcard%d.tmp", VOBJ_DRV, (S8*) VOBJ_FILE_PATH, index);
    }
    else if (type == MMI_VOBJ_VCLNDR)
    {
        sprintf(ascii_path, "%c:\\%s\\~vcalendar%d.tmp", VOBJ_DRV, (S8*) VOBJ_FILE_PATH, index);
    }
#ifdef __MMI_VBOOKMARK__
    else if (type == MMI_VOBJ_VBKM)
    {
        sprintf(ascii_path, "%c:\\%s\\~vbookmark%d.tmp", VOBJ_DRV, (S8*) VOBJ_FILE_PATH, index);
    }
#endif /* __MMI_VBOOKMARK__ */ 
    else
    {
        sprintf(ascii_path, "%c:\\%s\\", VOBJ_DRV, (S8*) VOBJ_FILE_PATH);
    }

    mmi_asc_to_ucs2(result, ascii_path);
}

#define VOBJ_UTILITY


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_uti_strnicmp
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  src         [IN]        String pointer to be compared
 *  dest        [IN]        String pointer to be compared
 *  maxlen      [IN]        Lengh to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, false
 *****************************************************************************/
S8 mmi_vobj_uti_strnicmp(S8 *src, S8 *dest, S32 maxlen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ch1, ch2;
    S8 *s1, *s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s1 = src;
    s2 = dest;

    while (maxlen-- > 0)
    {
        ch1 = tolower(*s1++);
        ch2 = tolower(*s2++);
        if (ch1 != ch2)
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_uti_get_line
 * DESCRIPTION
 *  Get a line from file system, excluding the escape characters.
 * PARAMETERS
 *  strOutput       [IN/OUT]        Storage location for data
 *  fh              [IN]            File handle
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vobj_uti_get_line(S8 *strOutput, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nBytes = 0;
    S8 strCRLF[4];
    S8 *currCRLF = 0;
    S8 *prevCRLF = 0;
    S8 *firstColon;
    S8 *cursor;
    S8 *secondColon;
    S32 strLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(strCRLF, "%c%c", VOBJ_CR_CHAR, VOBJ_LF_CHAR);

    FS_Read(fh, strOutput, VOBJ_READ_BUFF_LEN - 1, (UINT *)&nBytes);

    strOutput[nBytes] = VOBJ_NULL;

    if (!nBytes)
    {
        return 0;
    }

    cursor = firstColon = strstr(strOutput, VOBJ_VALUE_SEP_STR);
    cursor++;
    secondColon = strstr(cursor, VOBJ_VALUE_SEP_STR);

    currCRLF = strstr(strOutput, strCRLF);

    if (currCRLF == NULL)
    {
        return 0;
    }

    if (secondColon != NULL)    /* only one line */
    {
        while (currCRLF < secondColon)
        {
            cursor = prevCRLF = currCRLF;
            cursor++;
            currCRLF = strstr(cursor, strCRLF);
            if (currCRLF == NULL)
            {
                break;
            }
        }
    }
    else
    {
        while (currCRLF != NULL)
        {
            cursor = prevCRLF = currCRLF;
            cursor++;
            currCRLF = strstr(cursor, strCRLF);
        }
    }

    if (prevCRLF == NULL || firstColon == NULL) /* unsupported format */
    {
        return 0;
    }

    strLen = (S32) (prevCRLF - strOutput);
    strOutput[strLen] = VOBJ_NULL;

    FS_Seek(fh, (S32) (strLen - nBytes + 2), SEEK_CUR);

    nBytes = strLen;

    return nBytes;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_uti_get_value
 * DESCRIPTION
 *  Get the string after ":"
 * PARAMETERS
 *  strString       [IN]        Input string.
 * RETURNS
 *  pointer to the starting point after ":"
 *****************************************************************************/
S8 *mmi_vobj_uti_get_value(S8 *strString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strstr(strString, (S8*) VOBJ_VALUE_SEP_STR) != NULL)
    {
	    return (S8*) (strstr(strString, (S8*) VOBJ_VALUE_SEP_STR) + 1);
    }
    else
    {
		return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_uti_cmp_filed
 * DESCRIPTION
 *  Check if the string constains a filed.
 * PARAMETERS
 *  srcString       [IN]        Source string to be compared.
 *  refString       [IN]        Header of the filed
 * RETURNS
 *  TRUE if string exists, otherwise FALSE.
 *****************************************************************************/
U8 mmi_vobj_uti_cmp_filed(S8 *srcString, const S8 *refString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 refLen, srcLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srcLen = strlen(srcString);
    refLen = strlen(refString);

    if (srcLen < refLen)
    {
        return FALSE;
    }
    if (mmi_vobj_uti_strnicmp(srcString, (S8*) refString, refLen))
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
 *  mmi_vobj_util_eliminate_qp_CRLF
 * DESCRIPTION
 *  To eliminate quoted printable CRLF sequence.
 * PARAMETERS
 *  string      [IN/OUT]        String to be parsed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_util_eliminate_qp_CRLF(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((cursor = strstr(string, (S8*) VOBJ_QP_CRLF_STR)) != NULL)
    {
        cursor[0] = VOBJ_CR_CHAR;
        cursor[1] = VOBJ_LF_CHAR;
        cursor[2] = VOBJ_NULL;

        cursor += strlen((S8*) VOBJ_QP_CRLF_STR);
        strcat(string, cursor);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_util_append_qp_CRLF
 * DESCRIPTION
 *  To append CRLF string for quoted-printable encoding.
 * PARAMETERS
 *  string      [IN/OUT]        String to be parsed
 * RETURNS
 *  TRUE if any CRLF found; otherwise, FALSE.
 *****************************************************************************/
U8 mmi_vobj_util_append_qp_CRLF(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor = string;
    S8 *rem_string;
    S8 *tmpBuff;
    U8 result = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmpBuff = OslMalloc(VOBJ_READ_BUFF_LEN);

    while ((cursor = strstr(cursor, (S8*) VOBJ_CRLF_STR)) != NULL)
    {
        /* the string after \r, \n */
        rem_string = (cursor + strlen(VOBJ_CRLF_STR));
        strcpy(tmpBuff, rem_string);
        strcpy(cursor, (S8*) VOBJ_QP_CRLF_STR);
        cursor += strlen((S8*) VOBJ_QP_CRLF_STR);
        strcat(cursor, tmpBuff);
        result = TRUE;
    }
    if (cursor)
    {
        cursor -= strlen((S8*) VOBJ_QP_CRLF_STR);
        cursor[0] = '\0';
    }
    OslMfree(tmpBuff);
    return result;
}

#endif /* defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) */ /* END #if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) */

#if defined(__MMI_BIP_SUPPORT__) ||defined(__MMI_OPP_SUPPORT__) || defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) ||defined(__MMI_VBOOKMARK__) || defined(__MMI_IRDA_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_file_arrival_tone
 * DESCRIPTION
 *  Play file arrival tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_file_arrival_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ALERT_TYPE alertType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alertType = GetMtCallAlertTypeEnum();

    if (alertType == MMI_VIBRATION_AND_RING || alertType == MMI_VIBRATION_THEN_RING || alertType == MMI_RING)
    {
        if ((!isInCall()) || (isInCall() && (GetWapCallPresent())))
        {
            playRequestedTone(FILE_ARRIVAL_TONE);        
        }
        //else
        //{
        //    playRequestedTone(SMS_IN_CALL_TONE);
        //}
    }
    if ((alertType == MMI_VIBRATION_ONLY) || (alertType == MMI_VIBRATION_AND_RING) ||
        (alertType == MMI_VIBRATION_THEN_RING))
    {
        if ((!g_alm_frm_cntx.IsAlmTonePlaying) && ((!isInCall()) || (isInCall() && (GetWapCallPresent()))))
        {
            PlaySmsVibratorOnce();
        }
    }
}
#endif /* defined(__MMI_BIP_SUPPORT__) ||defined(__MMI_OPP_SUPPORT__) || defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_IRDA_SUPPORT__) */
#endif /* _MMI_VOBJECTS_C */ /* END #define _MMI_VOBJECTS_C */

