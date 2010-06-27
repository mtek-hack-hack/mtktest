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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*! \file masig.c
 *  \brief Signal dispatcher for external (MSF) signals.
 */

/* MSF */
#include "msf_core.h"
#include "msf_log.h"
#include "msf_cfg.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_mem.h"

/* MMS Service */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#ifdef WAP_SUPPORT
#include "msig.h" //for delete msg
#include "fldmgr.h" //for delete msg
#include "mms_aApp.h" //for delChkSumFile
#endif /* WAP_SUPPORT */

/* MMC Service */
#ifdef MMSAT_SUPPORT
#include "kal_release.h"      	/* Basic data type */
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"      	/* Task creation */
#include "custom_config.h"
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"       	/* Event scheduler */
#include "stack_timer.h"      	/* Stack timer */
#include "app_buff_alloc.h"
#include "stack_buff_alloc.h"
#include "l4a.h"
#include "wap_ps_struct.h"
#include "mmc_env.h"

extern void mmcMmsSignalHandler(MSF_UINT16 signal, void *p);
#endif /* MMSAT_SUPPORT */

/* BRA */
#include "bra_if.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* SMA */
#include "sma_if.h"

/* MEA*/
#include "mea_rc.h"
#include "mea_def.h"
#include "mea_cfg.h"
#include "matypes.h"
#include "mamem.h"
#include "maintsig.h"
#include "maincn.h"
#include "maconf.h"
#include "masig.h"
#include "macore.h"
#include "mamh.h"
#include "mamv.h"
#include "mamr.h"
#include "mauisig.h"
#include "maasync.h"
#include "mamcr.h"
#include "macrh.h"
#include "mauidia.h"
#include "macomm.h"
#include "mauipm.h"
#include "madel.h"
#include "mauicmn.h"
#include "maph.h"
#include "macrh.h"
#include "masrh.h"
#include "mautils.h"
#include "mase.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"
#include "mtr.h" /* for mauimob.h */
#include "mamob.h"  /* for mauimob.h */
#include "mauimob.h"  /* for meaUiMobHandleTimer */
#include "mauimh.h"  /* for meaCreateDetailListView */
#include "mame.h"

#ifdef __UNIFIED_MSG_SUPPORT__
#include "wap_um.h"
#include "mea_if.h"
#endif

#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "mammv.h"
#include "mmsadp.h"
#include "mma_if.h"
#endif
extern int MSF_moduleIsRunning(MSF_UINT8 modId);
extern MSF_BOOL mmcRemoveMsgIdFromJSRIndex(MSF_UINT32 msgId);
extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);

static MmsMsgId corruptedMsgId = 0;  //failed to generate checksum
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Prototypes
 *****************************************************************************/

static void msfSignalHandler(MSF_UINT16 signal, void *p);
static void mmsSignalHandler(MSF_UINT16 signal, void *p);
static void smaSignalHandler(MSF_UINT16 signal, void *p);
static void slsSignalHandler(MSF_UINT16 signal, void *p);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Handler/converter for signals received from MSF
 * \param signal The external signal received
 * \param p The serialized signal data
 *****************************************************************************/
static void msfSignalHandler(MSF_UINT16 signal, void *p)
{
    msf_module_status_t *moduleStatus;
    msf_module_execute_cmd_t *cl;
    msf_pipe_notify_t *pn;

#ifndef __UNIFIED_MSG_SUPPORT__
    /* Check that the signal is valid */
    if (NULL == p)
    {
        meaPanic(TRUE);
    }
#endif
    /* Check if the package handler consumes this signal */
    if (meaPhHandleSignal(signal, p))
    {
        MSF_SIGNAL_DESTRUCT(MSF_MODID_MEA, signal, p);
        return;
    }
    else
    {    
        switch(signal)
        {
        case MSF_SIG_WIDGET_NOTIFY:
        case MSF_SIG_WIDGET_ACTION:
        case MSF_SIG_WIDGET_USEREVT:
            if (NULL != p)
            {
                meaWidgetSignalHandler(signal, p);
            }
            else
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASIG_755EEBA14A7DAACA813AFD81ECE63DD1, "(%s) (%d) erroneous widget signal\n", __FILE__, __LINE__));
            }
            break;

        case MSF_SIG_MODULE_STATUS:
            if (NULL == (moduleStatus = ((msf_module_status_t*)p)))
            {
                break;
            }

            if (MODULE_STATUS_TERMINATED == moduleStatus->status)
            {
                if (MSF_MODID_MMS == moduleStatus->modId)
                {
                    (void)MEA_SIGNAL_SENDTO_U(MEA_CORE_FSM, 
                        MEA_SIG_CORE_MODULE_TERMINATED, MSF_MODID_MMS);
                }
                else if (MSF_MODID_SMA == moduleStatus->modId)
                {
                    (void)MEA_SIGNAL_SENDTO_U(MEA_CORE_FSM, 
                        MEA_SIG_CORE_MODULE_TERMINATED, MSF_MODID_SMA);
                }
                else if (MSF_MODID_SLS == moduleStatus->modId)
                {
                    (void)MEA_SIGNAL_SENDTO_U(MEA_CORE_FSM, 
                        MEA_SIG_CORE_MODULE_TERMINATED, MSF_MODID_SLS);
                }
            }
            else if (MODULE_STATUS_ACTIVE == moduleStatus->status)
            {
                /* MMS */
                if (MSF_MODID_MMS == moduleStatus->modId)
                {
                    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                        MASIG_5163169AC9A6C66D36BE2F60A151B164, "The MMS Service is started.\n"));
                    meaModuleStarted(MSF_MODID_MMS);
                    /* Get notifications for new messages */
                    MMSif_applicationReg(MSF_MODID_MEA);
                    /* The MMS Service is started, get the configuration data */
                    (void)MEA_SIGNAL_SENDTO(MEA_CONFIG_FSM, 
                        MEA_SIG_CONF_INITIAL_ACTIVATE);

                } /* SMA */
                else if (MSF_MODID_SMA == moduleStatus->modId)
                {
                    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                        MASIG_AEC027A06CEC45770EE2C844630282D8, "The SMA is started.\n"));
                    (void)MEA_SIGNAL_SENDTO_U(MEA_CORE_FSM, 
                        MEA_SIG_CORE_MODULE_ACTIVE, MSF_MODID_SMA);
                }
                else if (MSF_MODID_SLS == moduleStatus->modId)
                {
                    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                        MASIG_AEC027A06CEC45770EE2C844630282D8, "The SMA is started.\n"));
                    (void)MEA_SIGNAL_SENDTO_U(MEA_CORE_FSM, 
                        MEA_SIG_CORE_MODULE_ACTIVE, MSF_MODID_SLS);
                } 
            }
            else
            {
                MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
                    MASIG_A9D15203AFB20F2A14D23074FCF57F3B, "msfSignalHandler erroneous signal module status\n"));
            }
            break;

        case MSF_SIG_MODULE_EXECUTE_COMMAND:
            cl = ((msf_module_execute_cmd_t*)p);
#ifdef __UNIFIED_MSG_SUPPORT__
            if (MEA_STARTUP_MODE_NONE == meaGetStartupMode() || MEA_STARTUP_MODE_DEFAULT == meaGetStartupMode())
#else
            if (MEA_STARTUP_MODE_NONE == meaGetStartupMode())
#endif
            {
                MSF_MODULE_IS_ACTIVE(MSF_MODID_MEA);
                meaSetStartupParameters(cl);
                if (MEA_STARTUP_MODE_PROVISIONING == meaGetStartupMode())
                {
                     /*	Don't need to start MMS. Just lay low and wait. 
                        Todo: Also in settings mode?*/
                }
                else
                {
                    /* Start MMS Service if not active */
                    if (!(MSF_moduleIsRunning(MSF_MODID_MMS)))
                    {
                        /*
                         *	Start MMS Service. MEA startup continues on receival
                         *  of MMS startup confirmation (MSF_SIG_MODULE_STATUS)
                         */
                        meaModuleStart(MSF_MODID_MMS, FALSE, (MeaStateMachine)0, 
                            0);
                    }
                    else  /* if MMS is MSF_STARTUP_STATIC */
                    {
                        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MASIG_5163169AC9A6C66D36BE2F60A151B164, "The MMS Service is started.\n"));
                        /* Get notifications for new messages */
                        MMSif_applicationReg(MSF_MODID_MEA);
                        /* The MMS Service is started, get the configuration data */
                        (void)MEA_SIGNAL_SENDTO(MEA_CONFIG_FSM, MEA_SIG_CONF_INITIAL_ACTIVATE);
                    }
                } /* if */
            }
            else
            {
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
    #endif
            }
            break;

        case MSF_SIG_MODULE_TERMINATE:
#ifdef __UNIFIED_MSG_SUPPORT__
            (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_ABNORMAL_TERMINATE_APP);
#else
            (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);        
#endif
            break;

        case MSF_SIG_TIMER_EXPIRED:
            /* Timer handling */
            if (NULL == p)
            {
                break;
            }
            if (MEA_PM_TIMER_ID == ((msf_timer_expired_t *)p)->timerID)
            {
                meaPmHandleTimer();
            }
            else if(MEA_MOB_TIMER_ID == ((msf_timer_expired_t *)p)->timerID)
            {
                meaUiMobHandleTimer();
            }
#if MEA_CFG_SEND_TIMEOUT
            else if(MEA_COMM_TIMER_ID == ((msf_timer_expired_t *)p)->timerID)
            {
                (void)MEA_SIGNAL_SENDTO_U(MEA_COMM_FSM, MEA_SIG_COMM_SEND_MSG_RESPONSE, MMS_RESULT_OK);
            }
#endif
#if defined(MEA_GET_MIXED_TEXT_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
            else if(MEA_MOB_TEXT_HEIGHT_TIMER_ID == ((msf_timer_expired_t *)p)->timerID)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MASIG_7206E2A049C3E38DEC709F5940C2CA47, "[TEXT HEIGHT] MEA_MOB_TEXT_HEIGHT_TIMER_ID\n"));
            
                (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM,
                    MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_CONTINUE);
            }
#endif
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            else if(MEA_MH_CREATE_DEF_TEMP_TIMER_ID == ((msf_timer_expired_t *)p)->timerID)
            {
                (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM,
                    MEA_SIG_MH_CREATE_DEF_TEMP_FINISHED_CONTINUE);
            }
#endif
            else
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                        MASIG_CB22A2C5C202F31883D847DD539BFA5C, "Unhandled timer event timerId=%d", ((msf_timer_expired_t *)p)->timerID));
            }
            break;

        case MSF_SIG_FILE_NOTIFY:
            if (NULL != p)
            {
                (void)MEA_SIGNAL_SENDTO_IU(MEA_ASYNC_FSM, MEA_SIG_ASYNC_NOTIFY,
                    ((msf_file_notify_t *)p)->eventType, 
                    (unsigned)((msf_file_notify_t *)p)->fileHandle);
            }
            break;

        case MSF_SIG_PIPE_NOTIFY:
            pn = (msf_pipe_notify_t *)p;
            if (NULL != pn)
            {
#ifdef MMS_SLIM_MEM
                (void)MEA_SIGNAL_SENDTO_IU(MEA_ASYNC_FSM, MEA_SIG_ASYNC_PIPE_NOTIFY, 
                    pn->eventType, pn->handle);
#else
                (void)MEA_SIGNAL_SENDTO_IU(MEA_CRH_FSM, MEA_SIG_CRH_NOTIFY, 
                    pn->eventType, (unsigned long)(pn->handle));
#endif /* MMS_SLIM_MEM */
            }
            break;

        case MSF_SIG_REG_RESPONSE:
            (void)MEA_SIGNAL_SENDTO_P(MEA_CONFIG_FSM, MEA_SIG_CONF_GET_REG_RSP, p);
            /* Do not destruct this signal yet */
            return;

        case MSF_SIG_CONTENT_SEND_ACK:
            if (NULL == p)
            {
                break;
            }
            if (MEA_CRH_SEND_ID == ((msf_content_send_ack_t *)p)->id)
            {
                (void)MEA_SIGNAL_SENDTO_U(MEA_CRH_FSM, MEA_SIG_CRH_SEND_RSP, 
                    ((msf_content_send_ack_t *)p)->status);    
            }
            else
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASIG_02ABDF9EF062D6CED7E8A148E4E602BB, "(%s) (%d) unhandled content routing response!\n", __FILE__, 
                    __LINE__));
            }
            break;

        case MSF_SIG_TEL_MAKE_CALL_RESPONSE:
            meaSrhMakeCallRsp((msf_tel_make_call_resp_t *)p);
            break;

#ifdef __UNIFIED_MSG_SUPPORT__
        case MEA_SIG_CREATE_MSG:
        {
            meaSetStartupFsm(MEA_ME_FSM);
            (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL, 0);
            break;
        }

        case MEA_SIG_READ_MSG:
        {
            if(NULL != p)
            {
                MeaReadMsgSig *sig = (MeaReadMsgSig *)p;
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_NAV_ACTIVATE, sig->folder, sig->msgIndex);
#else
                (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_UM_READ_MSG, sig->folder, sig->msgIndex);
#endif
            }
            else
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASIG_755EEBA14A7DAACA813AFD81ECE63DD1, "(%s) (%d) erroneous widget signal\n", __FILE__, __LINE__));
            }
            break;
        }

        case MEA_SIG_ENTER_TEMPLATE:
        {
#ifdef  MEA_CFG_USER_TEMPLATE_SUPPORT
            meaCreateTemplatesFolderListView();
#else
            MSF_UINT16 templates = 0, dummy = 0;
            fldrMgrGetNumberOfMessages(MMS_TEMPLATES, &templates, &dummy);
            if(templates > 0)
            {
                HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
                meaSetStartupFsm(MEA_MH_FSM);
                (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, MEA_FOLDER_TEMPLATE);
            }
            else
            {
                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), MEA_DIALOG_PROMPT_EMPTY);
            }
#endif
            break;
        }

        case MEA_SIG_ENTER_SETTING:
        {
            meaSetStartupFsm(MEA_CONFIG_FSM);
            (void)MEA_SIGNAL_SENDTO(MEA_CONFIG_FSM, MEA_SIG_CONF_ACTIVATE);
            break;
        }

        case MEA_SIG_GET_MSG_NUM:
        {
            MSF_UINT16 inbox = 0, inboxUnread = 0, unsent = 0, sent = 0, draft = 0, dummy = 0;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            MSF_UINT16 archive = 0;
#endif
            fldrMgrGetNumberOfMessages(MMS_INBOX | MMS_NOTIFY, &inbox, &inboxUnread);
            fldrMgrGetNumberOfMessages(MMS_OUTBOX, &unsent, &dummy);
            fldrMgrGetNumberOfMessages(MMS_SENT, &sent, &dummy);
            fldrMgrGetNumberOfMessages(MMS_DRAFTS, &draft, &dummy);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            fldrMgrGetNumberOfMessages(MMS_ARCHIVE, &archive, &dummy);
#endif
            wap_send_mmi_mms_get_msg_num_rsp(inboxUnread, inbox - inboxUnread, unsent, sent, draft
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            , archive
#endif
            );
            break;
        }

        case MEA_SIG_GET_MSG_LIST:
        {
            if (NULL != p)
            {
                MeaFolderListSig *sig = (MeaFolderListSig *)p;
                (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_UM_GET_FOLDER_LIST, sig->folder, sig->start);
            }
            else
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASIG_755EEBA14A7DAACA813AFD81ECE63DD1, "(%s) (%d) erroneous widget signal\n", __FILE__, __LINE__));
            }

            break;
        }

        case MEA_SIG_GET_MSG_INFO:
        {
            if (NULL != p)
            {
                MeaFolderInfoSig *sig = (MeaFolderInfoSig *)p;
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_MH_FSM, MEA_SIG_MH_UM_GET_MSG_INFO,  sig->max, sig->folder, sig->start);
            }
            else
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASIG_755EEBA14A7DAACA813AFD81ECE63DD1, "(%s) (%d) erroneous widget signal\n", __FILE__, __LINE__));
            }

            break;
        }

        case MEA_SIG_DELETE_FOLDER:
        {
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_DELETE_ALL_MSG, MEA_CONFIRM_DIALOG_OK, *(MeaFolder *)p);
            break;
        }
#endif
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMS_SIG_MOV_MSG_REPLY:
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_DONE), MEA_DIALOG_PROMPT_DONE);
            break;
        }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        default:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
                MASIG_D9D226E6B78558176BAC310FD0B95FFF, "(%s) (%d) Erroneous signal received!\n", __FILE__,  __LINE__));
            break;
        }
    }
    /* Delete signal */
    MSF_SIGNAL_DESTRUCT(MSF_MODID_MEA, signal, p);
}

/*!
 * \brief Handler/converter for signals received from the MMS Service. 
 * \param signal The external signal received that we should convert into an 
 *           internal representation
 * \param p The serialized signal data.
 *****************************************************************************/
static void mmsSignalHandler(MSF_UINT16 signal, void *p)
{
    MmsRRReplySig *rrSig = NULL;
    MmsProgressStatus *msgStatus;
    MmsListOfProperties *newList;

    switch(signal)
    {
    case MMS_SIG_MOV_MSG_REPLY:
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER);
        break;
    case MMS_SIG_GET_FLDR_REPLY:
        {
#ifdef MMSAT_SUPPORT
            if(!isMmsReplyForMMC(MMS_SIG_GET_FLDR_REPLY,0))
            {
#endif /* MMSAT_SUPPORT */
                MmsListOfProperties *list = (MmsListOfProperties*)p;
                if (NULL != list)
                {
                    newList = MEA_ALLOC(sizeof(MmsListOfProperties));
                    MMSif_copyMmsListOfProperties(newList, list, MSF_MODID_MEA);
                    (void)MEA_SIGNAL_SENDTO_P(MEA_MH_FSM, 
                        MEA_SIG_MH_FOLDER_LIST_RESPONSE, newList);
                }
#ifdef MMSAT_SUPPORT
    	}
	else
    	{
		//for MMS Composer
		mmcMmsSignalHandler(MMS_SIG_GET_FLDR_REPLY,p);		
        }
#endif /* MMSAT_SUPPORT */
        }
        break;

    case MMS_SIG_CREATE_MSG_REPLY:
        {
#ifdef MMSAT_SUPPORT
		if(!isMmsReplyForMMC(MMS_SIG_CREATE_MSG_REPLY,0))
		{
            		MmsMsgReplySig *rep = (MmsMsgReplySig *)p;
	            	(void)MEA_SIGNAL_SENDTO_UU(MEA_MCR_FSM,MEA_SIG_MCR_CREATE_MSG_RESPONSE, rep->result, rep->msgId);
		}
		else
		{			
			mmcMmsSignalHandler(MMS_SIG_CREATE_MSG_REPLY,p);			
		}
#else
            MmsMsgReplySig *rep = (MmsMsgReplySig *)p;
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MCR_FSM, 
                MEA_SIG_MCR_CREATE_MSG_RESPONSE, rep->result, rep->msgId);
#endif
        }
        break;

    case MMS_SIG_SEND_MSG_REPLY:
#ifdef MMSAT_SUPPORT
        if(isMmsReplyForMMC(MMS_SIG_SEND_MSG_REPLY, 0))
        {           
            mmcMmsSignalHandler(MMS_SIG_SEND_MSG_REPLY,p);      
        }       
        else
#endif
        {
            char *response_text = NULL;
#if MEA_CFG_SHOW_RESPONSE_TEXT
            if (((MmsResultSig*)p)->responseText)
            {
                MEA_CALLOC(response_text, strlen(((MmsResultSig*)p)->responseText) + 1);
                strcpy(response_text, ((MmsResultSig*)p)->responseText);
            }
#endif
            (void)MEA_SIGNAL_SENDTO_UP(MEA_COMM_FSM, MEA_SIG_COMM_SEND_MSG_RESPONSE, ((MmsResultSig*)p)->result, response_text);
        }
        break;
        
    case MMS_SIG_MSG_DONE_REPLY:
#ifdef MMSAT_SUPPORT
    	if(!isMmsReplyForMMC(MMS_SIG_MSG_DONE_REPLY,((MmsMsgReplySig*)p)->msgId))
	{
        	(void)MEA_SIGNAL_SENDTO_UU(MEA_MCR_FSM, 
            	MEA_SIG_MCR_CREATE_MSG_DONE_RESPONSE,((MmsMsgReplySig*)p)->result, ((MmsMsgReplySig*)p)->msgId);        	
    	}
    	else
    	{			
		mmcMmsSignalHandler(MMS_SIG_MSG_DONE_REPLY,p);		
    	}       
#else
        (void)MEA_SIGNAL_SENDTO_UU(MEA_MCR_FSM, 
            MEA_SIG_MCR_CREATE_MSG_DONE_RESPONSE, 
            ((MmsMsgReplySig*)p)->result, 
            ((MmsMsgReplySig*)p)->msgId);
#endif /* MMSAT_SUPPORT */
        break;        

    case MMS_SIG_NOTIFICATION:
        if (((MmsMsgReplyNotification *)p)->notifId == corruptedMsgId)
        {
            fldrMgrDeleteMessage(corruptedMsgId);
            corruptedMsgId = 0;
            break;
        }
        (void)MEA_SIGNAL_SENDTO(MEA_IN_FSM, MEA_SIG_IN_ACTIVATE);
        break;

    case MMS_SIG_ERROR:
        meaHandleMmsErrors(((MmsResultSig*)p)->result);
        break;
       
    case MMS_SIG_DELETE_MSG_REPLY:
#ifdef __UNIFIED_MSG_SUPPORT__
        (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_DELETE_MESSAGE_RESPONSE, ((MmsResultSig *)p)->result);
#else
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_DELETE_MESSAGE_RESPONSE);
#endif
        break;

    case MMS_SIG_READ_REPORT_IND:
    {
        MmsMsgReadReport * report  = (MmsMsgReadReport *)p;
        if (report->msgIdFile == HDIa_widgetExtGetMMSMessageID())
        {
#ifndef __UNIFIED_MSG_SUPPORT__
            /* Send update signal to MH */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER);
#else
            HDIa_widgetExtClearMMS();
#endif
            return;
        }
    }
        /* A read report is ready to be viewed */
        (void)MEA_SIGNAL_SENDTO_P(MEA_MV_FSM, MEA_SIG_MV_RR, p);
        return;

    case MMS_SIG_DELIVERY_REPORT:
    {
        MmsMsgDeliveryReportInd * report  = (MmsMsgDeliveryReportInd *)p;
        if (report->msgIdFile == HDIa_widgetExtGetMMSMessageID())
        {
#ifndef __UNIFIED_MSG_SUPPORT__
            /* Send update signal to MH */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER);
#else
            HDIa_widgetExtClearMMS();
#endif
            return;
        }
    }
        /* A delivery report is ready to be viewed */
        (void)MEA_SIGNAL_SENDTO_P(MEA_MV_FSM, MEA_SIG_MV_DR, p);
        return;

    case MMS_SIG_RETRIEVE_MSG_REPLY:
        (void)MEA_SIGNAL_SENDTO_UU(MEA_COMM_FSM, 
            MEA_SIG_COMM_DOWNLOAD_RESPONSE, ((MmsMsgReplySig*)p)->result,  
            ((MmsMsgReplySig*)p)->msgId);
        break;

    case MMS_SIG_SEND_RR_REPLY:
        rrSig = (MmsRRReplySig*)p;
        if (MMS_RESULT_OK == rrSig->result ||
            MMS_RESULT_CANCELLED_BY_USER == rrSig->result)
        {
            fldrMgrDeleteMessage(rrSig->rrId);
        }
        else
        {
#ifdef MMS_FILE_PROTECT_SUPPORT
            genChkSumFile(rrSig->rrId);
#endif
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_SEND_RR), 
                MEA_DIALOG_ALERT);            
        }
        break;    
    
    case MMS_SIG_PROGRESS_STATUS_REPLY:
        if (NULL != p)
        {
            msgStatus = MEA_ALLOC(sizeof(MmsProgressStatus));
            memcpy(msgStatus, (MmsProgressStatus*)p, 
                sizeof(MmsProgressStatus));

            (void)MEA_SIGNAL_SENDTO_P(MEA_COMM_FSM, 
                MEA_SIG_COMM_PROGRESS_STATUS, msgStatus);
        }
        break;
    case MMS_SIG_GET_MSG_INFO_REPLY:
        meaSrhGetMessageInfoRsp((MmsListOfProperties*)p);
        break;

    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MASIG_4AF66111DF921E6A14D8748760C901C4, "(%s) (%d) invalid signal mmsServiceSignalHandler\n", __FILE__, 
            __LINE__));
        break;
    }
    /* Delete signal */
    MSF_SIGNAL_DESTRUCT(MSF_MODID_MEA, signal, p);
}

/*!
 * \brief Handler/converter for signals received from the SMIL player.
 *
 * \param signal The external signal received that we should convert into an
 *           internal representation.
 * \param p The serialized signal data.
 *****************************************************************************/
static void smaSignalHandler(MSF_UINT16 signal, void *p)
{
#ifdef __UNIFIED_MSG_SUPPORT__
    MSF_UINT32 msgId = 0;

    switch(signal)
   {
    case MEA_SIG_SEND:
    case MEA_SIG_REPLY:
    case MEA_SIG_REPLY_ALL:
    case MEA_SIG_FORWARD:
    case MEA_SIG_EDIT:
    case MEA_SIG_USE_NUMBER:
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    case MEA_SIG_MOVE_TO_ARCHIVE:
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        msgId = *(MSF_UINT32 *)p;
        if(msgId != 0 && msgId == meaGetActiveMm()->msgId)
        {
            if(!isValidMmsMSg(msgId))
            {
                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_CORRUPT), MEA_DIALOG_ERROR);
                MSF_SIGNAL_DESTRUCT(MSF_MODID_MEA, signal, p);
                return;
            }
        }
        else
        {
            MSF_SIGNAL_DESTRUCT(MSF_MODID_MEA, signal, p);
            return;
        }
    }
#endif

    switch(signal)
    {
    case SMA_SIG_PLAY_SMIL_RSP:
        /* Finished playing SMIL. Close the SMA module */
        (void)MEA_SIGNAL_SENDTO_U(MEA_CORE_FSM, MEA_SIG_CORE_SMA_STOP, 
            ((SmaPlaySmilRsp *)p)->result);
        break;

#ifdef __UNIFIED_MSG_SUPPORT__
    case MEA_SIG_SEND:
        (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_SEND_MSG_MR_START, (unsigned long)msgId); 
        break;
    case MEA_SIG_REPLY:
        (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
            meaGetActiveMm()->fileType, MEA_ME_STARTUP_REPLY, (unsigned long)msgId);
        break;
    case MEA_SIG_REPLY_ALL:
        (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
            meaGetActiveMm()->fileType, MEA_ME_STARTUP_REPLY_ALL, (unsigned long)msgId);
        break;
    case MEA_SIG_FORWARD:
        if (!meaGetActiveMm()->forwardLock)
        {
            (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                meaGetActiveMm()->fileType, MEA_ME_STARTUP_FORWARD, (unsigned long)msgId);
        }
        break;
    case MEA_SIG_EDIT:
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        if (meaGetCurrentFolder() == MEA_FOLDER_USER_TEMPLATE)
        {
            (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE,
                    meaGetActiveMm()->fileType, MEA_ME_STARTUP_FROM_TEMPLATE, 
                    msgId);
        }
        else
#endif
        {
        (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                meaGetActiveMm()->fileType, MEA_ME_STARTUP_EDIT, (unsigned int)msgId);
        }
        break;
    case MEA_SIG_DELETE:
    {
        MSF_UINT32 msgId = *(MSF_UINT32 *)p;
        if(msgId != 0 && msgId == meaGetActiveMm()->msgId)
        {
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_DELETE_MSG, MEA_CONFIRM_DIALOG_OK, (unsigned long)msgId); 
        }
        break;
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    case MEA_SIG_MOVE_TO_ARCHIVE:
    {
        MSF_UINT32 msgId = *(MSF_UINT32 *)p;
        if(msgId != 0 && msgId == meaGetActiveMm()->msgId)
        {
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_MOVE_TO_ARCHIVE, MEA_CONFIRM_DIALOG_OK, (unsigned long)msgId); 
        }
        break;
    }
#endif  /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    case MEA_SIG_USE_NUMBER:
        /* Start the SLS module, continue when the SLS is started */
        meaModuleStart(MSF_MODID_SLS, TRUE, MEA_MH_FSM, MEA_SIG_MH_SLS_RSP);        
        break;

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    case MEA_SIG_DELETE_FOLDER:
        {
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_DELETE_ALL_MSG, MEA_CONFIRM_DIALOG_OK, *(MeaFolder *)p);
            break;
        }
        break;
#endif /* MEA_CFG_USER_TEMPLATE_SUPPORT*/
#endif /* __UNIFIED_MSG_SUPPORT__*/
	default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MASIG_1EA3A371B9FE1A356316508F9A243D2E, "(%s) (%d) Unhandled signal from the SMA module!\n", __FILE__, 
            __LINE__));
        break;
    }

    MSF_SIGNAL_DESTRUCT(MSF_MODID_MEA, signal, p); 
}

/*!
 * \brief Handler/converter for signals received from the SLS. 
 * \param signal The external signal received that we should convert into an 
 *           internal representation
 * \param p The serialized signal data
 *****************************************************************************/
static void slsSignalHandler(MSF_UINT16 signal, void* p)
{
    SlsOpenSmilRsp      *openSmilRsp;
    SlsCloseSmilRsp     *closeSmilRsp;
    SlsGetSlideInfoRsp  *smilInfo;

    switch(signal)
    {
    case SLS_OPEN_SMIL_RSP:
        if(0 == meaGetUseNumberMsgID())
        {
        MEA_CALLOC(openSmilRsp, sizeof(SlsOpenSmilRsp));
        openSmilRsp->result = ((SlsOpenSmilRsp *)p)->result;
        openSmilRsp->noOfSlides = ((SlsOpenSmilRsp *)p)->noOfSlides;
        openSmilRsp->rootLayout.bgColor = ((SlsOpenSmilRsp *)p)->rootLayout.bgColor;
        openSmilRsp->file = msf_cmmn_strdup(MSF_MODID_MEA, ((SlsOpenSmilRsp *)p)->file);
        if(((SlsOpenSmilRsp *)p)->unrefItems != NULL)
        {
            openSmilRsp->unrefItems = meaCopySlsUnrefList(((SlsOpenSmilRsp *)p)->unrefItems);
        }
        /* Forward the signal to the MRC FSM */
        (void)MEA_SIGNAL_SENDTO_P(MEA_MR_FSM, MEA_SIG_MR_OPEN_SMIL_RSP, openSmilRsp);
        }
        else
        {
            meaCreateDetailListView(meaGetUseNumberMsgID(), ((SlsOpenSmilRsp *)p)->unrefItems);
            meaSetUseNumberMsgID(0);
            /* Close down the SLS module */
            meaModuleStop(MSF_MODID_SLS, FALSE);
        }
        break;

    case SLS_CLOSE_SMIL_RSP:
        closeSmilRsp = (SlsCloseSmilRsp *)p;
        /* Forward the signal to the MRC FSM */
        (void)MEA_SIGNAL_SENDTO_U(MEA_MR_FSM, MEA_SIG_MR_CLOSE_SMIL_RSP, 
            closeSmilRsp->result);
        break;

    case SLS_GET_SLIDE_INFO_RSP:
        smilInfo = meaCopySlsSlideInfo((SlsGetSlideInfoRsp *)p);
        (void)MEA_SIGNAL_SENDTO_P(MEA_MR_FSM, MEA_SIG_MR_GET_SLIDE_INFO_RSP,
            smilInfo);
        break;
        
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MASIG_B50277B3F9B29749E70023C37C879398, "(%s) (%d) Unhandled signal from SLS!\n", __FILE__, __LINE__));
        break;
    }
    /* Delete the external signal */
    MSF_SIGNAL_DESTRUCT(MSF_MODID_MEA, signal, p);
}

#ifdef __UNIFIED_COMPOSER_SUPPORT__
/*!
 * \brief Handler/converter for signals received from MMA. 
 * \param signal The external signal received that we should convert into an 
 *           internal representation
 * \param p The serialized signal data
 *****************************************************************************/
static void mmaSignalHandler(MSF_UINT16 signal, void* p)
{
    switch(signal)
    {
    case MMA_SIG_START_UC_RSP:
        {
            mma_uc_start_rsp_struct *rsp = (mma_uc_start_rsp_struct *)p;
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, MASIG_12B0060F29AC65F25743C4F3F7C2025A, "MEA: received signal MMA_SIG_START_UC_RSP (%d, %d)\n", 
                rsp->result, rsp->mode));

            switch(rsp->result)
            {
            case MMA_RESULT_OK:
                (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);  /* Delete menu */
                (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_DEACTIVATE);  /* Stop MMV */
                (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);  /* Stop MOB */
                HDIa_widgetExtDeleteWidgetScreenIfPresent();
                (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_DEACTIVATE);   /* For template */

                break;
            case MMA_RESULT_FAIL_IN_CALL:
                break;
            default:
                switch(rsp->mode)
                {
                case MMA_MODE_EDIT:
                    HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), MsfError, 0);
                    break;
                case MMA_MODE_SEND:
                    HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_SEND), MsfError, 0);
                    break;
                case MMA_MODE_REPLY:
                case MMA_MODE_REPLY_ALL:
                    HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_REPLY), MsfError, 0);
                    break;
                case MMA_MODE_FORWARD:
                    HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_FORWARD), MsfError, 0);
                    break;
                default:
                    break;
                }
                break;
            }
            break;
        }

        break;

    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
            MASIG_3D60A79D5C87A81F9AF21AC02F8AF144, "(%s) (%d) Unhandled signal from MMA\n", __FILE__, __LINE__));
        break;
    }
    /* Delete the external signal */
    MSF_SIGNAL_DESTRUCT(MSF_MODID_MEA, signal, p);
}
#endif

/*!
 * \brief Handler/converter for signals received from BRA. 
 * \param signal The external signal received that we should convert into an 
 *           internal representation
 * \param p The serialized signal data
 *****************************************************************************/
static void braSignalHandler(MSF_UINT16 signal, void* p)
{
    switch(signal)
    {
    case BRA_SIG_SELECT_BOOKMARK_REPLY:
    {
        char *url = NULL;
        bra_select_bookmark_reply_t *rsp = (bra_select_bookmark_reply_t *)p;
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MASIG_88DB002A0476BA3DBBB310C04428B086, "MEA: received signal BRA_SIG_SELECT_BOOKMARK_REPLY (%d)\n", rsp->result));
        if (rsp->result)
        {
            url = msf_cmmn_strdup(MSF_MODID_MEA, rsp->url);
        }
        (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_ADD_TEXT, (unsigned)url);
    }
    break;

    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
            MASIG_EA271912A9E731F613E5587DAB104447, "(%s) (%d) Unhandled signal from BRA\n", __FILE__, __LINE__));
        break;
    }
    /* Delete the external signal */
    MSF_SIGNAL_DESTRUCT(MSF_MODID_MEA, signal, p);
}

/*!
 * \brief Set the message id for corrupted message need to be deleted. 
 * \param the corrupted message id
 *****************************************************************************/
void meaSetCorruptedMsgId(MmsMsgId msgId)
{
    corruptedMsgId = msgId;	
}


/*!
 * \brief Router for external signals received. Routes them to the appropriate 
 *          signal handler/converter. 
 * \param src_module The internal destination the signal is intended for
 * \param signal The external signal received that we should route to its 
 *                  destination "within" MEA
 * \param p The serialized signal data
 *****************************************************************************/
void meaSignalReceive(MSF_UINT8 src_module, MSF_UINT16 signal, void* p)
{
    /* Dispatch signals to the correct module */
    switch(src_module)
    {
    case MSF_MODID_SMA:
        smaSignalHandler(signal, p);
        break;

    case MSF_MODID_MSM:
        msfSignalHandler(signal, p);
        break;
   
    case MSF_MODID_MMS:
        mmsSignalHandler(signal, p);
        break;

    case MSF_MODID_SLS:
        slsSignalHandler(signal, p);
        break;
        
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    case MSF_MODID_MMA:
        mmaSignalHandler(signal, p);
        break;
#endif

    case MSF_MODID_BRA:
        braSignalHandler(signal, p);
        break;

    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MASIG_A3EF898C55EC6C886A0189C119A0BD44, "(%s) (%d) Erroneous signal recieved in meaSignalReceive\n", 
            __FILE__, __LINE__));
        MSF_SIGNAL_DESTRUCT(MSF_MODID_MEA, signal, p);
        break;
    }
}

