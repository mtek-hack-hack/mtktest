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

/* MSF */
#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_def.h"
#include "msf_cmmn.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_wid.h"
#include "msf_log.h"
#include "msf_pipe.h"
#include "msf_file.h"

/* MMS */
#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* SMA */
#include "sma_if.h"

/* MTR */
#include "mtr_ctrl.h"

/* MEA */
#include "mea_rc.h"
#include "mea_cfg.h"
#include "mea_def.h"
#include "mea_env.h"
#include "matypes.h"
#include "mamem.h"
#include "maintsig.h"
#include "macore.h"
#include "mamh.h"
#include "maconf.h"
#include "mauicmn.h"
#include "maasync.h"
#include "maincn.h"
#include "mamv.h"
#include "mamme.h"
#include "mammv.h"
#include "mamob.h"
#include "mase.h"
#include "mamr.h"
#include "mame.h"
#include "mamcr.h"
#include "macrh.h"
#include "macomm.h"
#include "mauidia.h"
#include "mauimh.h"
#include "mapbh.h"
#include "macth.h"
#include "maopts.h"
#include "madel.h"
#include "maph.h"
#include "maaddr.h"
#include "masrh.h"
#ifdef WAP_SUPPORT
#include "mauidia.h"   //for meaShowConfirmationDialogWithStatusIcon
#include "mauicomm.h" //for meaSetCofnirmationDialogWithStatusIcon
#include "mauimv.h"  //for meaMvSetPlySmilFailed
#include "mms_aApp.h" //for delChkSumFile
#include "msig.h"     //for fldmgr.h
#include "fldmgr.h"   //for fldrMgrDeleteMessage
#include "mauise.h"		//for meaSmilEditorIsActive
#include "mautils.h"  /* meaCleanupResizedFiles */
#endif /* WAP_SUPPORT */

#ifdef __MMS_DUAL_SIM_SUPPORT__
#include "bra_cmn.h"
#include "wap_ps_struct.h"
#include "gv.h"
#include "tst_def.h"
#include "wap_cmn.h"
#endif /*__MMS_DUAL_SIM_SUPPORT__*/

#if defined(WAP_SUPPORT) || defined(__DRM_SUPPORT__)
#include "widget_extension.h" //for HDIa_widgetExtRegisterSystemMsg
#endif /* defined(WAP_SUPPORT) || defined(__DRM_SUPPORT__) */

/*! \file macore.c
 *  \brief Handling of: start/stop of other modules, cross triggering, start-up
 *         data and handling of asynchronous error events from the MMS Service.
 */

/******************************************************************************
 * Data-types
 *****************************************************************************/
typedef struct 
{
    const char            *asString;
    const MeaStartupMode  asInteger;
}MeaModeType;

/******************************************************************************
 * Constants
 *****************************************************************************/

/* ! Command line parameters */ 
#define MEA_CL_MODE                 "mode"      /*!< The mode identifier */
#define MEA_CL_ACTION               "a"         /*!< The action identifier */
#define MEA_CL_INSERT               "i"         /*!< Insert mode */
#define MEA_CL_MSG_ID               "m"         /*!< Message id */
#define MEA_CL_TEMPLATE_ID          "t"         /*!< The message type */
#define MEA_CL_TO                   "to"        /*!< Message recipients */
#define MEA_CL_CC                   "cc"        /*!< Message recipients */
#define MEA_CL_SUBJECT              "subject"   /*!< The message subject */
#ifdef WAP_SUPPORT
#define MEA_CL_SIZE                   "size"        /*!< Message size */
#define MEA_CL_FROM                   "from"        /*!< Message from address */
#endif /* WAP_SUPPORT */

/* Modes */
#define MEA_MODE_MENU         "menu"            /*!< The menu mode */
#define MEA_MODE_NEW          "new"             /*!< New message */
#define MEA_MODE_NEW_TEMPLATE "new_template"    /*!< New template */
#define MEA_MODE_VIEW         "view"            /*!< View a message */
#define MEA_MODE_DEL          "delete"          /*!< Delete a message */
#define MEA_MODE_FORWARD      "forward"         /*!< Forward a message */
#define MEA_MODE_REPLY        "reply"           /*!< Reply to a message */
#define MEA_MODE_REPLY_ALL    "reply_to_all"    /*!< Reply to a message */
#define MEA_MODE_SETTINGS     "settings"        /*!< Settings */
#define MEA_MODE_EDIT         "edit"            /*!< Edit a message */
#define MEA_MODE_SEND         "send"            /*!< Send a message */
#define MEA_MODE_DOWNLOAD     "download"        /*!< Download a message */
#define MEA_MODE_PROVISIONING "wait_for_settings"/*!<Receive provisioning */

static const MeaModeType modes[] = {
                            {MEA_MODE_MENU,         MEA_STARTUP_MODE_MENU},
                            {MEA_MODE_NEW,          MEA_STARTUP_MODE_NEW},
                            {MEA_MODE_NEW_TEMPLATE, MEA_STARTUP_MODE_NEW_TEMPLATE},
                            {MEA_MODE_EDIT,         MEA_STARTUP_MODE_EDIT},
                            {MEA_MODE_FORWARD,      MEA_STARTUP_MODE_FORWARD},
                            {MEA_MODE_REPLY,        MEA_STARTUP_MODE_REPLY},
                            {MEA_MODE_REPLY_ALL,    MEA_STARTUP_MODE_REPLY_ALL},
                            {MEA_MODE_VIEW,         MEA_STARTUP_MODE_VIEW},
                            {MEA_MODE_DEL,          MEA_STARTUP_MODE_DELETE},
                            {MEA_MODE_SETTINGS,     MEA_STARTUP_MODE_CONFIG},
                            {MEA_MODE_SEND,         MEA_STARTUP_MODE_SEND},
                            {MEA_MODE_DOWNLOAD,     MEA_STARTUP_MODE_DOWNLOAD},
                            {MEA_MODE_PROVISIONING, MEA_STARTUP_MODE_PROVISIONING},
                            {NULL,                  MEA_STARTUP_MODE_DEFAULT}
                            };

/*! \enum ModuleState
 *  \brief Possible states for the SMA module 
 */
typedef enum
{
    MOD_STARTED,                /* !< The module is started */
    MOD_STOPPED,                /* !< The module is stopped */
    MOD_INTERNAL_TERMINATION,   /* !< The module is terminating. The 
                                      termination is initiated through an 
                                      internal call to meaServiceStop. */
    MOD_APP_TERMINATION         /* !< The module is terminated as a part 
                                      of the termination of the application */
}ModuleState;

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/*! \struct ModuleInfo
 *  \brief start-up information about other modules
 */
typedef struct
{
    ModuleState     state;      /* !< The current state of the module, see 
                                     #ModuleState */
    MSF_BOOL        useCallback;/* !< TRUE if a signal is sent when the module 
                                     is terminated, otherwise FALSE */
    MeaStateMachine fsm;        /* !< The callback FSM */
    unsigned int    signal;     /* !< The signal sent to the callback FSM */
}ModuleInfo;

/*! \struct MeaSmaPlayInfo
 *  \brief structure for handling of playing SMIL messages
 */ 
typedef struct
{
    MmsMsgId        msgId;  /*!< The msgId of the message to play */
    MmsFileType     fileType; /*!< The file type of the message to start playing */
    MeaStateMachine fsm;    /*!< The callback FSM */
    unsigned int    sig;    /*!< The callback signal */
}MeaSmaPlayInfo;

/******************************************************************************
 * Variables
 *****************************************************************************/

/*! The start start-up mode of the module, see #MeaStartupMode. 
 */
static MeaStartupMode       startupMode;

/*! The FSM that the MEA was started in
 */
static MeaStateMachine      startupFsm;

/*! Data-structures for handling of module start-up/termination. */
static ModuleInfo           mmsModInfo; /* !< MMS module info */
static ModuleInfo           smaModInfo; /* !< SMA module info */
static ModuleInfo           slsModInfo; /* !< SLS module info */

/*! Information about a play SMIL operation */
static MeaSmaPlayInfo smaPlay;

/*! Exception handling */
static MSF_BOOL isInsideRun;    /*!< TRUE if the MEA is executing inside a 
                                     MEAc_run call, otherwise FALSE */
static MSF_BOOL isExceptionAllowed; /*!< TRUE if a memory exception results in 
                                         a long jump, otherwise FALSE */
/* Used for start-up */
static MmsMsgId     msgId;
#ifdef WAP_SUPPORT
static MSF_UINT32 downloadSize;
static int lastMmsError = -1;
#endif /* WAP_SUPPORT */

/*! Global variable for stack rollback to MEAc_run */
jmp_buf meaJmpBuf;
int meaPanicMode;

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void parseCommandLine(const msf_module_execute_cmd_t *command);
static void coreSignalHandler(MeaSignal *sig);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Check whether memory exceptions are allowed or not.
 * 
 * \return TRUE if memory exceptions is allowed, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaIsExceptionAllowed(void)
{
    return isExceptionAllowed;
}

/*!
 * \brief Allows memory exceptions.
 * 
 * \param state TRUE if memory exceptions is allowed, otherwise FALSE.
 *****************************************************************************/
void meaAllowException(MSF_BOOL state)
{
    isExceptionAllowed = state;
}

/*!
 * \brief Check whether the MEA is running through a call to MEAc_run.
 * 
 * \return TRUE if the MEA is executing through a call to MEAc_run, otherwise
 *         FALSE.
 *****************************************************************************/
MSF_BOOL meaIsInsideRun(void)
{
    return isInsideRun;
}

/*!
 * \brief Changes the state that MEA is running in, i.e.,the MEA is running 
 *        through a call to MEAc_run or not.
 * 
 * \param state TRUE if the MEA is running through a call to MEAc_run, 
 *              otherwise FALSE.
 *****************************************************************************/
void meaSetInsideRun(MSF_BOOL state)
{
    isInsideRun = state;
}

/*!
 * \brief This function is called in order to terminate the MEA when a 
 *        unrecoverable error has occured.
 *
 * \param showDialog TRUE if a dialog should be displayed before the shutdown,
 *                   otherwise FALSE.
 *****************************************************************************/
void meaPanic(int showDialog)
{
    if (showDialog)
    {
        if (meaShowPanicDialog())
        {
            /* Shutdown the application when the dialog disappears */
            meaPanicMode = MEA_PANIC_IMPLICIT;
            longjmp(meaJmpBuf, MEA_PANIC);
        }
    }
    /* If no dialog should be display or if the dialog could not be 
       displayed shutdown the application */
    meaPanicMode = MEA_PANIC_EXPLICIT;
    longjmp(meaJmpBuf, MEA_PANIC);
}

/*!
 * \brief Starts a service if not previously started.
 *
 * \param modId The identity of the module to start.
 * \param useCallback TRUE if a signal is sent when the module is started.
 * \param fsm The FSM to send a signal to when the module is started.
 * \param signal The signal to send when the module is started.
 *****************************************************************************/
void meaModuleStart(MSF_UINT32 modId, MSF_BOOL useCallback, 
    MeaStateMachine fsm, unsigned int signal)
{
    switch(modId)
    {
    case MSF_MODID_MMS:
        if (MOD_STOPPED == mmsModInfo.state)
        {
            MMSif_startInterface();
            MSF_MODULE_START(MSF_MODID_MEA, MSF_MODID_MMS, NULL, NULL, NULL);
        }
        break;

    case MSF_MODID_SMA:
        if (MOD_STOPPED == smaModInfo.state)
        {
            MSF_MODULE_START(MSF_MODID_MEA, MSF_MODID_SMA, NULL, NULL, NULL);
            smaModInfo.useCallback  = useCallback;
            smaModInfo.fsm          = fsm;
            smaModInfo.signal       = signal;
        }
        break;

    case MSF_MODID_SLS:
        if (MOD_STOPPED == slsModInfo.state)
        {
            MSF_MODULE_START(MSF_MODID_MEA, MSF_MODID_SLS, NULL, NULL, NULL);
            slsModInfo.useCallback  = useCallback;
            slsModInfo.fsm          = fsm;
            slsModInfo.signal       = signal;
        }
        break;

    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_0F82E5B03E5350B0BC5E632729DD47A5, "(%s) (%d) Unsupported modId %d\n", __FILE__, __LINE__, modId));
        break;
    }
}

/*!
 * \brief Sets the MMS Service status state to started.
 *
 * \param modId The identity of the module that is started.
 *****************************************************************************/
void meaModuleStarted(MSF_UINT32 modId)
{
    switch (modId)
    {
    case MSF_MODID_MMS:
        mmsModInfo.state = MOD_STARTED;
        break;
    case MSF_MODID_SMA:
        smaModInfo.state = MOD_STARTED;
        break;
    case MSF_MODID_SLS:
        slsModInfo.state = MOD_STARTED;
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_0F82E5B03E5350B0BC5E632729DD47A5, "(%s) (%d) Unsupported modId %d\n", __FILE__, __LINE__, modId));
        break;
    }
}

/*!
 * \brief Terminates the a module if it is running.
 *
 * \param modId The identity of the module that shall be stopped.
 * \param terminateApp TRUE if the entire application is terminating.
 *****************************************************************************/
void meaModuleStop(MSF_UINT32 modId, MSF_BOOL terminateApp)
{
    ModuleInfo *modInfo = NULL;

    switch (modId)
    {
    case MSF_MODID_MMS:
        modInfo = &mmsModInfo;
        break;
    case MSF_MODID_SMA:
        modInfo = &smaModInfo;
        break;
    case MSF_MODID_SLS:
        modInfo = &slsModInfo;
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_0F82E5B03E5350B0BC5E632729DD47A5, "(%s) (%d) Unsupported modId %d\n", __FILE__, __LINE__, modId));
        return;
    }
    /* Check if the application is terminating or not */
    if (terminateApp)
    {
        modInfo->state = MOD_APP_TERMINATION;
    }
    else
    {
        modInfo->state = MOD_INTERNAL_TERMINATION;
    }
    /* Send termination signal */
    MSF_MODULE_TERMINATE(MSF_MODID_MEA, (MSF_UINT8)modId);
}

/*!
 * \brief Sets the MMS status state to stopped.
 *
 * \param modId The identity of the module that is stopped.
 *****************************************************************************/
void meaModuleStopped(MSF_UINT32 modId)
{
    switch (modId)
    {
    case MSF_MODID_MMS:
        mmsModInfo.state = MOD_STOPPED;
        break;
    case MSF_MODID_SMA:
        smaModInfo.state = MOD_STOPPED;
        break;
    case MSF_MODID_SLS:
        slsModInfo.state = MOD_STOPPED;
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_0F82E5B03E5350B0BC5E632729DD47A5, "(%s) (%d) Unsupported modId %d\n", __FILE__, __LINE__, modId));
        break;
    }
}

/*!
 * \Checks whether the MMS Service has been started.
 *
 * \param modId The identity of the module that is started.
 * \return TRUE if the service is started, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaIsModuleStarted(MSF_UINT32 modId)
{
    MSF_BOOL started = FALSE;

    switch (modId)
    {
    case MSF_MODID_MMS:
        started = (MOD_STARTED == mmsModInfo.state);
        break;
    case MSF_MODID_SMA:
        started = (MOD_STARTED == smaModInfo.state);
        break;
    case MSF_MODID_SLS:
        started = (MOD_STARTED == slsModInfo.state);
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_0F82E5B03E5350B0BC5E632729DD47A5, "(%s) (%d) Unsupported modId %d\n", __FILE__, __LINE__, modId));
        break;
    }
    return started;
}

/*!
 *\brief Sets the startup FSM.
 *
 * \param stateM The state machine to start the application in.
 *****************************************************************************/
void meaSetStartupFsm(MeaStateMachine stateM)
{
    startupFsm = stateM;
}

/*!
 * \brief Gets the startup FSM.
 *
 * \return The startup FSM.
 *****************************************************************************/
MeaStateMachine meaGetStartupFsm(void)
{
    return startupFsm;
}

/*!
 * \brief Converts startup command line parameters into a static C 
 *        data-structure.
 *
 * \param cl A pointer to a string containing command line parameters.
 *****************************************************************************/
void meaSetStartupParameters(const msf_module_execute_cmd_t *command)
{
    if (command->contentDataExists)
    {
        /* Check if the content originates from a BRA scheme */
        if (meaCthHandleSchemeCt(command))
        {
            startupMode = MEA_STARTUP_MODE_SCHEME;
        }

#ifndef __UNIFIED_MSG_SUPPORT__  /* UM: startupMode = MEA_STARTUP_MODE_DEFAULT */
        /* If no start-up mode has been set, then check the command line */
        if (MEA_STARTUP_MODE_NONE == meaGetStartupMode())
#endif
        {
            parseCommandLine(command);
        }
    }
    else
    {
        parseCommandLine(command);
    }
    if ((MEA_STARTUP_MODE_DELETE != meaGetStartupMode()) && 
        (MEA_STARTUP_MODE_PROVISIONING != meaGetStartupMode()))
    {
        /*
         *	Only in DELETE and PROVISIONING startup mode do MEA not use a GUI. 
         *  In all other*  startup modes snatch focus at once. TR #14521.
         */
        (void)MSF_WIDGET_SET_IN_FOCUS(meaGetScreenHandle(), TRUE);
    } /* if */
}

#ifdef WAP_SUPPORT
/*! \brief Parses the download size.
 *
 * \param optsList The command line.
 * \param t The token to search for
 * \return The size, or 0 if the operation fails.
 *****************************************************************************/
static MSF_UINT32 getDownloadSize(const mea_opts_list *optsList, const char *t)
{
    mea_opts_token *token;
    MSF_UINT32 size = 0;
    if (NULL != (token = mea_opts_find_option(optsList, 
        t)))
    {
        if (((NULL != (token = mea_opts_get_next_arg(token))) &&
            mea_opts_get_uint32(token, &size)))
        {
            return size;
        }
    }
    else
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_70C8686B55263AC95530B8ED71D6D59F, "(%s) (%d) No valid size for the operation\n", 
            __FILE__, __LINE__));
    }
    return 0;
}
#endif /* WAP_SUPPORT */

/*! \brief Parses the msgId.
 *
 * \param optsList The command line.
 * \param t The token to search for
 * \return The message Id, or 0 if the operation fails.
 *****************************************************************************/
static MmsMsgId getMsgId(const mea_opts_list *optsList, const char *t)
{
    mea_opts_token *token;
    MmsMsgId newMsgId = 0;
    char *data;
    if (NULL != (token = mea_opts_find_option(optsList, 
        t)))
    {
        if (((NULL != (token = mea_opts_get_next_arg(token))) &&
            mea_opts_get_str(MSF_MODID_MEA, token, &data)))
        {
            newMsgId = (unsigned)msf_cmmn_hex2long(data);
            MEA_FREE(data);
        }
    }
    else
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_A67412BAAB52AEF65E4EA4B283CB3796, "(%s) (%d) No valid msgId for the operation\n", 
            __FILE__, __LINE__));
    }
    return newMsgId;
}

/*! \brief Handles the message properties provided through the command line, 
 *         i.e., To, Cc and Subject.
 *
 * \param optsList The current list of options.
 * \return A message property item, see #MeaPropItem.
 *****************************************************************************/
static MeaPropItem *getMsgProp(const mea_opts_list *optsList)
{
    MeaPropItem *item = NULL;
    mea_opts_token *token;
    char *data = NULL;
    MeaAddrItem *to = NULL;
    MeaAddrItem *cc = NULL;
    char *subject = NULL;

    /* To */
    if (NULL != (token = mea_opts_find_option(optsList, MEA_CL_TO)))
    {
        if (NULL != (token = mea_opts_get_next_arg(token)))
        {
            if (mea_opts_get_str(MSF_MODID_MEA, token, &data))
            {
                MSF_LOG_MSG_OFF((MSF_MODID_MEA, MSF_LOG_DETAIL_HIGH,
                    MACORE_E8D92B44ED208BAEE229450652BC3599, "(%s) (%d) To option found! To = %s!\n", __FILE__, 
                    __LINE__, data));
                to = meaAddrStrToList(data);
#ifdef WAP_SUPPORT
                MSF_MEM_FREE(MSF_MODID_MEA, data);
	            data = NULL;
                if(to == NULL)
                {
                    MSF_LOG_MSG_ARGS((MSF_MODID_MEA, MSF_LOG_DETAIL_MEDIUM,
                      MACORE_84027A7DB279B13B25040D5E08F5ED0A, "(%s) (%d) To option parameter found NULL!\n", __FILE__, __LINE__));
                }
                else if (NULL != (token = mea_opts_get_next_arg(token)))
		        {
		            if (mea_opts_get_str(MSF_MODID_MEA, token, &data))
		            {
		                MSF_LOG_MSG_ARGS((MSF_MODID_MEA, MSF_LOG_DETAIL_MEDIUM,
		                    MACORE_6678A1BB59D6065F2EFEFF03FE36F411, "(%s) (%d) To option found! Name = %s!\n", __FILE__, 
		                    __LINE__, data));
						to->name = data;
		            }        
		        }
#endif /* WAP_SUPPORT */
            }        
        }
    }

    /* Cc */
    if (NULL != (token = mea_opts_find_option(optsList, MEA_CL_CC)))
    {
        if (NULL != (token = mea_opts_get_next_arg(token)))
        {
            if (mea_opts_get_str(MSF_MODID_MEA, token, &data))
            {
                MSF_LOG_MSG_OFF((MSF_MODID_MEA, MSF_LOG_DETAIL_HIGH,
                    MACORE_6C04105D884427D2ADA140B32179E06F, "(%s) (%d) Cc option found! Cc = %s!\n", __FILE__, 
                    __LINE__, data));
                cc = meaAddrStrToList(data);
#ifdef WAP_SUPPORT
                MSF_MEM_FREE(MSF_MODID_MEA, data);
	            data = NULL;
#endif /* WAP_SUPPORT */
            }
        }
    }

    /* Subject */
    if (NULL != (token = mea_opts_find_option(optsList, MEA_CL_SUBJECT)))
    {
        if (NULL != (token = mea_opts_get_next_arg(token)))
        {
//            if (mea_opts_get_data(MSF_MODID_MEA, token, &data))
            if (mea_opts_get_str(MSF_MODID_MEA, token, &data))
            {
                MSF_LOG_MSG_OFF((MSF_MODID_MEA, MSF_LOG_DETAIL_HIGH,
                    MACORE_987BDDF61FB456CAC9D5AB2F8308B6F4, "(%s) (%d) Subject option found! subject = %s!\n", __FILE__, __LINE__, data));
                subject = data;
            }
        }
    }

    /* Allocate structure */
    if ((NULL != to) || (NULL != cc) || (NULL != subject))
    {
        item = MEA_ALLOC(sizeof(MeaPropItem));
        memset(item, 0, sizeof(MeaPropItem));
        item->to = to;
        item->cc = cc;
        item->subject = subject;
    }
    return item;
}

/*!
 * \brief Converts startup command line parameters into a static C 
 *        data-structure.
 *
 * \param cl A pointer to a string containing command line parameters.
 *****************************************************************************/
static void parseCommandLine(const msf_module_execute_cmd_t *command)
{
    mea_opts_list *optsList;
    mea_opts_token *token;
    char *data;
    unsigned int i;
    char *cl;
    msf_content_data_t *cData = NULL;
    /* Set default values */

    cl = command->commandOptions;
    startupMode = MEA_STARTUP_MODE_DEFAULT;
    if (NULL == cl)  /* Unified Message: would be NULL if user enter from menu */
    {
        return;
    }

    if (NULL == (optsList = mea_opts_get_list(MSF_MODID_MEA, cl)))
    {
        return;
    }
    /* Find the mode */
    if (NULL == (token = mea_opts_find_option(optsList, MEA_CL_MODE)))
    {
        if (NULL == (token = mea_opts_find_option(optsList, MEA_CL_ACTION)))
        {
            return;
        }
    }
    /* Find the current mode */
    if (NULL != (token = mea_opts_get_next_arg(token)))
    {
        if (mea_opts_get_str(MSF_MODID_MEA, token, &data))
        {
            for (i = 0; NULL != modes[i].asString; i++)
            {
                if (0 == msf_cmmn_strcmp_nc(data, modes[i].asString))
                {
                    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                        MACORE_957483CB7E11E01FECF264F677D634A2, "(%s) (%d) startup mode [%s] found\n", __FILE__, 
                        __LINE__, data));
                    startupMode = modes[i].asInteger;
                    break;
                }
            }
            MEA_FREE(data);
            /* Now the command line parameters are dependant on the mode  */
            switch(startupMode)
            {
            case MEA_STARTUP_MODE_DEFAULT:
            case MEA_STARTUP_MODE_MENU:
            case MEA_STARTUP_MODE_SCHEME:
            case MEA_STARTUP_MODE_PROVISIONING:
                /* No more information is needed */
                break;
            case MEA_STARTUP_MODE_NEW:
                msgId = 0;
                cData = NULL;
                if (NULL != (token = mea_opts_find_option(optsList, 
                    MEA_CL_TEMPLATE_ID)))
                {
                    /* A new message needs to be created using a template. 
                       First to the id of the template needs to be found. */
                    msgId = getMsgId(optsList, MEA_CL_TEMPLATE_ID);
                }
                /* check for the -i option */
                else if (NULL != (token = mea_opts_find_option(optsList, 
                    MEA_CL_INSERT)))
                {
                    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                        MACORE_5E63ECA2EBCCA0F4AE809EF516CEC862, "(%s) (%d) insert mode detected\n", __FILE__, 
                        __LINE__));
                    cData = (command->contentDataExists) ?
                        command->contentData: NULL;
                }
                /* Set the insert data direct */
                if (!meaCthHandleInsertContentCt(cData, getMsgProp(optsList)))
                {
                    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                        MACORE_F7493511E545CB732295FCD648A04F11, "(%s) (%d) Failed to insert content.\n", __FILE__, 
                        __LINE__));
                }
                break;

            case MEA_STARTUP_MODE_CONFIG:
                /* No parameters are needed for settings */
                break;

            case MEA_STARTUP_MODE_NEW_TEMPLATE:
                break;

            case MEA_STARTUP_MODE_DELETE:
            case MEA_STARTUP_MODE_FORWARD:
            case MEA_STARTUP_MODE_REPLY:
            case MEA_STARTUP_MODE_REPLY_ALL:
            case MEA_STARTUP_MODE_VIEW:
            case MEA_STARTUP_MODE_SEND:
            case MEA_STARTUP_MODE_DOWNLOAD:
            case MEA_STARTUP_MODE_EDIT:
                msgId = getMsgId(optsList, MEA_CL_MSG_ID);
                break;

            case MEA_STARTUP_MODE_NONE:
            default:
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MACORE_05D14DCE283D9DCD9E5F1F88EBB9D1FA, "(%s) (%d) Erroneous start-up parameters\n", __FILE__, 
                    __LINE__));
                break;
            }
#ifdef WAP_SUPPORT
            if (startupMode == MEA_STARTUP_MODE_DOWNLOAD)
            {
                downloadSize = getDownloadSize(optsList, MEA_CL_SIZE);
            }
            else if (startupMode == MEA_STARTUP_MODE_VIEW)
            {
                //fromAddress = getFromAddress(optsList, MEA_CL_FROM);
            }
            if (startupMode != MEA_STARTUP_MODE_NEW)
                meaActivateStartupFsm(); //if starting MEA without startup param, move it to the next line
#endif /* WAP_SUPPORT */
        }
    }
    mea_opts_free_list(MSF_MODID_MEA, optsList);
}

/*!
 * \brief Terminates MEA.
 *
 * \param internalOnly The module is only terminated internally, i.e., the 
 *                     MEA module is not terminated.
 *****************************************************************************/
void meaTerminate(MSF_BOOL internalOnly)
{
    /* Terminate all FSMs */
    meaSignalTerminate();  /* Clear internal signal queue */
    meaCoreTerminate(internalOnly);
    meaAsyncTerminate();
    meaConfTerminate();    
    meaMhTerminate();
    meaInTerminate();
    meaMvTerminate();
    meaMeTerminate();
    meaSeTerminate();
    meaMmeTerminate();
    meaMmvTerminate();
    meaMobTerminate();
    meaMcrTerminate();
    meaCrhTerminate();
    meaCommTerminate();
    meaMrTerminate();
    meaPbhTerminate();
    meaCthTerminate();
    /* Terminate user interface */
    meaTerminateGui();
    meaPhTerminate();
    meaSrhTerminate();
    mtrCtrlTerminate(); 
    HDIa_widgetExtDeleteWidgetScreenIfPresent();

    if (!internalOnly)
    {
#ifdef WAP_SUPPORT //for MMS is MSF_STARTUP_STATIC
    MMSif_applicationReg(0);
#endif /* WAP_SUPPORT */

        /* Deregister signal handler */
        MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_MEA);
        /* Free all resources just to be sure */
        MSF_PIPE_CLOSE_ALL(MSF_MODID_MEA);
        MSF_FILE_CLOSE_ALL(MSF_MODID_MEA);
        (void)MSF_WIDGET_RELEASE_ALL(MSF_MODID_MEA);
        MSF_MEM_FREE_ALL(MSF_MODID_MEA);
        /* Set module as terminated */
        MSF_MODULE_IS_TERMINATED(MSF_MODID_MEA);
        MSF_KILL_TASK(MSF_MODID_MEA);

        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MACORE_461B0EDE10081FCE58D3839AD5E88E05, "(%s) (%d) MEA is terminated\n", __FILE__, __LINE__));
    }
    else
    {
        /* Free resources */
        (void)MSF_WIDGET_RELEASE_ALL(MSF_MODID_MEA);
        MSF_PIPE_CLOSE_ALL(MSF_MODID_MEA);
        MSF_FILE_CLOSE_ALL(MSF_MODID_MEA);
        /* Do not free all memory since then the content routing info is lost*/
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_CB1F823AE3C09E4038C3C25182DDF2AA, "(%s) (%d) MEA is terminated internaly!\n", __FILE__, __LINE__));
    }

#ifdef __DRM_SUPPORT__
    msm_remove_files_under_dir(MMS_DRM_FOLDER);
#endif

#ifdef JPG_ENCODE
    meaCleanupResizedFiles();
#endif
    mmsUpdateIndicator();
}

/*!
 * \brief Returns a flag describing how MEA was started
 *
 * \return The start-up mode.
 *****************************************************************************/
MeaStartupMode meaGetStartupMode()
{
    return startupMode;
}

/*!
 * \brief Handles error signals from the MMS Service.
 *
 * \param result The result code for the error encountered, see #MmsResult. 
 *****************************************************************************/
void meaHandleMmsErrors(int result)
{
    switch(result)
    {
    /*! Communication error: Service unavailable or not supported. */    
    case MMS_RESULT_COMM_UNAVAILABLE:
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_COMM_UNAVAILABLE), 
            MEA_DIALOG_ERROR);
       break;
    /*! An #MMSc_sendMessage or #MMSc_retrieveMessage operation is cancelled
     *  by an #MMSc_cancel. */
    case MMS_RESULT_CANCELLED_BY_USER:
    /*! Communication error: The address could not be resolved. */
    case MMS_RESULT_COMM_ADDRESS_UNRESOLVED:
    /*! Communication error: Bad gateway. */
    case MMS_RESULT_COMM_BAD_GATEWAY:
    /*! Communication error: Entity too large. */
    case MMS_RESULT_COMM_ENTITY_TOO_LARGE:
    /*! Communication error: Unknown communication error. */
    case MMS_RESULT_COMM_FAILED:
    /*! Communication error: File or message not found. */        
    case MMS_RESULT_COMM_FILE_NOT_FOUND:
    /*! Communication error: Communication not allowed, service or method 
     *  denied. */
    case MMS_RESULT_COMM_FORBIDDEN:
    /*! Communication error: PDU did not contain expected tag. */
    case MMS_RESULT_COMM_HEADER_TAG:
    /*! Communication error: An illegal or badly formatted PDU was received. */
    case MMS_RESULT_COMM_ILLEGAL_PDU:
    /*! Communication error: The operation (e.g. Reply Charging) had 
     *  limitations that were violated in the request. */
    case MMS_RESULT_COMM_LIMITATIONS_NOT_MET:
#ifdef WAP_SUPPORT
        //(void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
            //MEA_DIALOG_ERROR);
		break;
#endif /* WAP_SUPPORT */
    /*! Communication error: The message size is specified in the notification.
     *  When the message is retrieved, it is larger than specified.
     */
    case MMS_RESULT_COMM_PROXY_ERROR:
    /*! Communication error: The MMS Proxy-Relay did not recognize one PDU
     *  that the MMS Service sent. This is probably due to a mis-configuration
     *  of the MMS Proxy-Relay version. */
    case MMS_RESULT_COMM_MMSC_VERSION:
    /*! Communication error: Error in TLS/WTLS setup. */
    case MMS_RESULT_COMM_SECURITY_ERROR:
    /*! Communication error: Unknown MMS Proxy-Relay error. */
    case MMS_RESULT_COMM_SERVER_ERROR:
    /*! Communication error: Wrong communication status. */
    case MMS_RESULT_COMM_STATUS:
    /*! Communication error: Operation timed out, e.g. no contact with the MMS 
     *  Proxy-Relay. */
    case MMS_RESULT_COMM_TIMEOUT:
#ifdef WAP_SUPPORT
        //(void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
            //MEA_DIALOG_ERROR);
		break;
#endif /* WAP_SUPPORT */
    /*! Communication error: Unexpected transaction ID. */
    case MMS_RESULT_COMM_TRANSACTION_ID:
    /*! Communication error: Unauthorized. */
    case MMS_RESULT_COMM_UNAUTHORIZED:
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_UNAUTHORIZED_ACCESS), 
            MEA_DIALOG_ERROR);
        break;

    /*! Communication error: Unexpected message received. */
    case MMS_RESULT_COMM_UNEXPECTED_MESSAGE:
    /*! Communication error: Unsupported media type or content. */
    case MMS_RESULT_COMM_UNSUPPORTED_MEDIA_TYPE:
        (void)meaShowDialog(MEA_GET_STR_ID(MSF_STR_ID_DLG_MIME_ACTION_NONE), 
            MEA_DIALOG_ERROR);
        break;

    /*! Communication error: Unsupported version. */
    case MMS_RESULT_COMM_UNSUPPORTED_VERSION:
    /*! Communication error: URI is too large. */
    case MMS_RESULT_COMM_URI_TOO_LARGE:
        (void)meaShowDialog(MEA_GET_STR_ID(BRA_STR_ID_INVALID_URL), 
            MEA_DIALOG_ERROR);
        break;
    /*! A message for a not supported MMS version is received */
    case MMS_RESULT_COMM_WRONG_MMS_VERSION:
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_MMS_VERSION), 
            MEA_DIALOG_ERROR);
        break;
    /*! The MMS Client has encountered an unrecoverable application error.
     *  The MMS Client must be stopped and restarted by the MMS Application.
     */
    case MMS_RESULT_RESTART_NEEDED:
        /* Close down application. Cannot make longjmp since we will have a memory leak */

#ifdef __UNIFIED_MSG_SUPPORT__
        (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_ABNORMAL_TERMINATE_APP);
#else
        (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);        
#endif
        break;
    case MMS_RESULT_OK:
        break;
    /*! One of the fields To, Cc, Bcc is invalid */
    case MMS_RESULT_INVALID_ADDRESS:
    /*! Invalid or not existing application header field. */
    case MMS_RESULT_INVALID_APPLICATION_HEADER:
    /*! Invalid or not existing Content-Id. */
    case MMS_RESULT_INVALID_CONTENT_ID:
    /*! Invalid or not existing Content-Location. */
    case MMS_RESULT_INVALID_CONTENT_LOCATION:

    /*! Content type is invalid. */
    case MMS_RESULT_INVALID_CONTENT_TYPE:
    
    /*! Expiry time is invalid. */
    case MMS_RESULT_INVALID_EXPIRY_TIME:

    /*! The total size of the MMS header is invalid. */
    case MMS_RESULT_INVALID_HEADER_SIZE:

    /*! Message class is invalid. */
    case MMS_RESULT_INVALID_MSG_CLASS:

    /*! Reply Charging Deadline is invalid.  */
    case MMS_RESULT_INVALID_REPLY_CHARGING_DEADLINE:

    /*! The storage type is invalid. */
    case MMS_RESULT_INVALID_STORAGE_TYPE:

    /*! Subject is invalid. */
    case MMS_RESULT_INVALID_SUBJECT:

    /*! The MMS version number is invalid for the requested operation. */
    case MMS_RESULT_INVALID_VERSION:
#ifdef WAP_SUPPORT
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_MMS_VERSION), 
            MEA_DIALOG_ERROR);
		break;
#endif /* WAP_SUPPORT */
   
    /*! The message is corrupt. */
    case MMS_RESULT_MESSAGE_CORRUPT:
#ifdef WAP_SUPPORT
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_MESSAGE), 
            MEA_DIALOG_ERROR);
		break;
#endif /* WAP_SUPPORT */

    /*! The message was empty. */
    case MMS_RESULT_MESSAGE_EMPTY:
    
    /*! The message with the specified message ID could not be found. */
    case MMS_RESULT_MESSAGE_ID_NOT_FOUND:

    /*! No report should be sent to this message. */
    case MMS_RESULT_NO_REPORT:

    /*! The queue holding immediate retrieval notifications is full. */
    case MMS_RESULT_NOTIFICATION_QUEUE_FULL:

    /*! The recipient address is not set in the message. */
    case MMS_RESULT_RECIPIENT_ADDRESS_NOT_SET:
    
    /*! The MMS Client has been stopped due to an internal error. */
    case MMS_RESULT_STOPPED:

    /*! The URI is not valid. */
    case MMS_RESULT_URI_NOT_VALID:
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_MESSAGE), 
            MEA_DIALOG_INFO);
        break;
    /*! Not enough persistent storage for the requested operation. */
    case MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
#ifdef  __USB_IN_NORMAL_MODE__
    if (!(mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc()))
		{
#endif /*__USB_IN_NORMAL_MODE__*/
#ifdef WAP_SUPPORT
			if (lastMmsError != MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE)  /* prevent continuous same popup */
			{
				(void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_NO_PERSISTENT_STORAGE), 
					MEA_DIALOG_ALERT);
			}
			HDIa_widgetExtRegisterSystemMsg(MSF_MODID_MEA, MEA_STR_ID_MMS, 
				MEA_STR_ID_NO_PERSISTENT_STORAGE);
#else
			(void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_NO_PERSISTENT_STORAGE), 
				MEA_DIALOG_ALERT);
#endif /* WAP_SUPPORT */
#ifdef  __USB_IN_NORMAL_MODE__
		}
#endif /*__USB_IN_NORMAL_MODE__*/
        break;

    /*! Max number of message reached. */
    case MMS_RESULT_TOO_MANY_MSG:
#ifdef WAP_SUPPORT
        HDIa_widgetExtRegisterSystemMsg(MSF_MODID_MEA, MEA_STR_ID_MMS, 
            MEA_STR_ID_MAX_NUMBER_OF_MSG);
#endif
        break;    
    /*! Warning threshold of number of MMS messages reached. */
    case MMS_RESULT_MANY_MSG_WARNING:
#ifdef WAP_SUPPORT
        HDIa_widgetExtRegisterSystemMsg(MSF_MODID_MEA, MEA_STR_ID_MMS, 
            MEA_STR_ID_NUMBER_OF_MSG_WARNING);
#else
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_NUMBER_OF_MSG_WARNING), MEA_DIALOG_ALERT);
#endif /* WAP_SUPPORT */
        break;

    /*! Not enough memory for the requested operation. */
    case MMS_RESULT_INSUFFICIENT_MEMORY:
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_NOT_ENOUGH_MEM), 
            MEA_DIALOG_ERROR);
        break;
    /*! The supplied buffer is full */
    case MMS_RESULT_BUFFER_FULL:
   /*! Too many consecutive calls to a connector function have been made without 
    *  waiting for the outcome of the previous calls.
    */        
    case MMS_RESULT_BUSY:
    /*! A requested body part was not found */
    case MMS_RESULT_BODY_PART_NOT_FOUND:
    /*! Configuration is not correct. */
    case MMS_RESULT_CONFIG_ERROR:
    /*! Index file is corrupt or does not exist. */
    case MMS_RESULT_INDEX_FILE_ERROR:
    /*! The current file operation cannot be performed at the moment. */
    case MMS_RESULT_DELAYED:
    /*! An unknown error has occurred. No further information can be given. */
    case MMS_RESULT_ERROR:
    /*! The End Of File has been reached. */
#ifdef WAP_SUPPORT
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACORE_6D08CD94BB9D9B8D7BBAE6B5FE7B04FC, "MEA MMS Sig error (%d)\n", result));
       break;
#endif /* WAP_SUPPORT */
    case MMS_RESULT_EOF:
    /*! Error when creating forward header. */
    case MMS_RESULT_ERROR_CREATING_FORWARD:
    /*! Error when creating a Read Report. */
    case MMS_RESULT_ERROR_CREATING_READ_REPORT:
    /*! Error when creating send header. */
    case MMS_RESULT_ERROR_CREATING_SEND_HEADER:
    /*! Error creating backup file. */
    case MMS_RESULT_FILE_BACKUP_ERROR:
    /*! A file is not found.*/
    case MMS_RESULT_FILE_NOT_FOUND:
    /*! Error reading file. */
    case MMS_RESULT_FILE_READ_ERROR:
    /*! Error when trying write to file */
    case MMS_RESULT_FILE_WRITE_ERROR:
    /*! The folder is not found. */
    case MMS_RESULT_FOLDER_NOT_FOUND:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACORE_6D08CD94BB9D9B8D7BBAE6B5FE7B04FC, "MEA MMS Sig error (%d)\n", result));
#ifdef WAP_SUPPORT
        //(void)meaShowDialog(MEA_GET_STR_ID(SMA_STR_ID_ERR_WRITING_FILE), 
        //    MEA_DIALOG_ERROR);
#else
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
            MEA_DIALOG_ERROR);
#endif /* WAP_SUPPORT */
        break;
    case MMS_RESULT_MAX_RETRIEVAL_SIZE_EXCEEDED:
#ifdef WAP_SUPPORT
        HDIa_widgetExtRegisterSystemMsg(MSF_MODID_MEA, MEA_STR_ID_MMS, 
            MEA_STR_ID_RETR_SIZE_EXCEEDED);
#else
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_RETR_SIZE_EXCEEDED), 
            MEA_DIALOG_INFO);
#endif /* WAP_SUPPORT */
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_46004D12B4BC0FD8886C7B22F543EEAE, "(%s) (%d) Unhandled MMS Service result\n", __FILE__, __LINE__));
        break;
    }

    lastMmsError = result;
}

/*!
 * \brief Initiates the CRR FSM.
 *
 * \param internalOnly TRUE if the modules is re-initiated, FALSE if the init
 *                     is called during a module start-up.
 *****************************************************************************/
void meaCoreInit(MSF_BOOL internalOnly)
{
    startupMode         = MEA_STARTUP_MODE_NONE;
    startupFsm          = MEA_MH_FSM;
    
    if (!internalOnly)
    {
        mmsModInfo.state = MOD_STOPPED;
        smaModInfo.state = MOD_STOPPED;
        slsModInfo.state = MOD_STOPPED;
    }
    isInsideRun         = FALSE;
    isExceptionAllowed  = TRUE;
    msgId               = (MmsMsgId)0;
    memset(&smaPlay, 0, sizeof(MeaSmaPlayInfo));
    smaPlay.fsm = MEA_NOTUSED_FSM;
#ifdef WAP_SUPPORT
    lastMmsError = -1;
#endif
    meaSignalRegisterDst(MEA_CORE_FSM, coreSignalHandler);
}

/*!
 * \brief Terminates the CRR FSM.
 *
 * \param internalOnly TRUE if the modules is terminating internally, FALSE if 
 *                     the terminate is called during a module termination.
 *****************************************************************************/
void meaCoreTerminate(MSF_BOOL internalOnly)
{
    meaSignalDeregister(MEA_CORE_FSM);
    if (!internalOnly)
    {
        mmsModInfo.state = MOD_STOPPED;
        smaModInfo.state = MOD_STOPPED;
        slsModInfo.state = MOD_STOPPED;
    }
    startupMode         = MEA_STARTUP_MODE_NONE;
    isInsideRun         = FALSE;
    isExceptionAllowed  = FALSE;
    msgId               = (MmsMsgId)0;
    smaPlay.fsm = MEA_NOTUSED_FSM;
}

/*!
 * \brief The signal handler for the CRR FSM.
 *
 * \param sig The current signal.
 *****************************************************************************/
static void coreSignalHandler(MeaSignal *sig)
{
    ModuleInfo *modInfo;

    /* Check which signal that was received */
    switch(sig->type)
    {
    case MEA_SIG_CORE_TERMINATE_APP:  /* In UM: we don't have normal termination, MEA should always be active */
        meaSignalDelete(sig);
#ifdef __UNIFIED_MSG_SUPPORT__  /* MEA internal reset */
        if (meaIsModuleStarted(MSF_MODID_SMA))
        {
            meaModuleStop(MSF_MODID_SMA, TRUE);
        }
        else if (meaIsModuleStarted(MSF_MODID_SLS))
        {
            meaModuleStop(MSF_MODID_SLS, TRUE);
        }
        else
        {
            meaTerminate(TRUE);  /* need to meaSignalDelete(sig) before this */
            meaInit(TRUE);
            {
                msf_module_execute_cmd_t cmd;
                cmd.srcModId = MSF_MODID_MEA;
                cmd.commandOptions = NULL;
                cmd.contentDataExists = FALSE;
                cmd.contentData = NULL;
                meaSetStartupParameters(&cmd);
            }
            (void)MEA_SIGNAL_SENDTO(MEA_CONFIG_FSM, MEA_SIG_CONF_INITIAL_ACTIVATE);
        }
        return;
#else
//        HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
        MEA_TERMINATE;
#endif
        break;

#ifdef __UNIFIED_MSG_SUPPORT__
    case MEA_SIG_CORE_ABNORMAL_TERMINATE_APP:
        meaSignalDelete(sig);
        MEA_TERMINATE;
#endif
        
    case MEA_SIG_CORE_MODULE_ACTIVE:
        modInfo = NULL;
        if (MSF_MODID_SMA == sig->u_param1)
        {
            modInfo = &smaModInfo;
            /* Start the SMA interface */
            SMAif_startInterface();

        }else if (MSF_MODID_SLS == sig->u_param1)
        {
            modInfo = &slsModInfo;
            /* Start the SLS interface */
            (void)SLSif_startInterface();
        }
        if (NULL != modInfo)
        {
            /* Set the state to started */
            modInfo->state = MOD_STARTED;
            /* Tell the starting FSM that the SMA is started */
            if (modInfo->useCallback)
            {
                (void)MEA_SIGNAL_SENDTO(modInfo->fsm, (int)modInfo->signal);
            }
        }
        break;

    case MEA_SIG_CORE_MODULE_TERMINATED:
        if (MSF_MODID_MMS == sig->u_param1)
        {
            meaSignalDelete(sig);
            mmsModInfo.state = MOD_STOPPED;
            /* Long jump */
            MEA_TERMINATE;
            break;
        }
        else if (MSF_MODID_SMA == sig->u_param1)
        {
            if (MOD_APP_TERMINATION == smaModInfo.state)
            {
#ifdef WAP_SUPPORT
                if(MEA_NOTUSED_FSM != smaPlay.fsm && meaSmilEditorIsActive())
                {
                    fldrMgrDeleteMessage(smaPlay.msgId);
#ifdef MMS_FILE_PROTECT_SUPPORT
                    delChkSumFile(smaPlay.msgId);
#endif
                }
#endif

                smaModInfo.state = MOD_STOPPED;
#ifdef __UNIFIED_MSG_SUPPORT__
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);  /* continue termination */
#else
                meaSignalDelete(sig);
                /* Long jump */
                MEA_TERMINATE;
#endif
                break;
            }
            else
            {
                /* Send the response to the calling FSM if the SMA have 
                   terminated whithout response */
                if (MEA_NOTUSED_FSM != smaPlay.fsm)
                {
                    (void)MEA_SIGNAL_SENDTO(smaPlay.fsm, (int)smaPlay.sig);
                }
                /* Make sure only one response is valid */
                smaPlay.fsm = MEA_NOTUSED_FSM;
                smaModInfo.state = MOD_STOPPED;
            }
        }
        else if (MSF_MODID_SLS == sig->u_param1)
        {
            if (MOD_APP_TERMINATION == slsModInfo.state)
            {
                slsModInfo.state = MOD_STOPPED;
#ifdef __UNIFIED_MSG_SUPPORT__
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);  /* continue termination */
#else
                meaSignalDelete(sig);
                /* Long jump */
                MEA_TERMINATE;
#endif
                break;
            }
            else
            {
                slsModInfo.state = MOD_STOPPED;
            }
        }
        break;

    case MEA_SIG_CORE_SMA_STARTED_PLY:
        /* Start playing the SMIL presentation if the SMA module is started */
        (void)SMAif_playSmil(MSF_MODID_MEA, smaPlay.msgId, smaPlay.fileType);
        break;

    case MEA_SIG_CORE_SMA_STOP:
        /* Stop the SMA module when finished plying the SMIL presentation */
        if (SMA_RESULT_OK != (SmaResult)sig->u_param1)
        {
            if (SMA_RESULT_BUSY == (SmaResult)sig->u_param1)
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_PLY_SMIL_BUSY), 
                    MEA_DIALOG_ERROR);
            else
                meaMvSetPlySmilFailed(TRUE);
        }
        /* the callback is handled in module stop */
        meaModuleStop(MSF_MODID_SMA, FALSE);
        break;

    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_9252FB418A508E1E72F85A010F76C04B, "(%s) (%d) Unhandled signal in coreSignalHandler!\n", __FILE__, 
            __LINE__));
        break;
    }
    meaSignalDelete(sig);
}

/*!
 * \brief Initiates all FSM's of the MEA.
 * \param internalOnly TRUE if the module is restarting, else FALSE.
 *****************************************************************************/
void meaInit(MSF_BOOL internalOnly)
{
    /* Init internal signal queue*/
    meaSignalInit();
    /* Init the UI */
    meaInitGui();

    /* Init all FSMs */
    if (!meaAsyncInit())
    {
        meaPanic(TRUE);
    }
    meaCoreInit(internalOnly);
    meaConfInit();
    meaMhInit();
    meaMvInit();
    meaInInit();
    meaMeInit();
    meaSeInit();
    meaMmeInit();
    meaMmvInit();
    meaMobInit();
    meaCrhInit();
    meaCommInit();
    meaMcrInit();
    meaMrInit();
    meaPbhInit();
    meaCthInit();
    meaSrhInit();
    mtrCtrlInit(); 

    /* Packages */
    if (!meaPhInit())
    {
        meaPanic(TRUE);
    }
}

/*!
 * \brief Starts the GUI for the application.
 *
 *****************************************************************************/
void meaActivateStartupFsm(void)
{
    /* Where to start is dependent on which mode the application is started */
    switch(meaGetStartupMode())
    {
    case MEA_STARTUP_MODE_MENU:
        /* Show the start-up menu */
        if (!meaCreateMhStartupMenu())
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MACORE_E36AA136B701BE9DC7A2274B7D23E5A1, "(%s) (%d) failed to create the start-up menu!\n", __FILE__, 
                __LINE__));
            MEA_TERMINATE;
        }
#ifdef WAP_SUPPORT
        HDIa_widgetExtPaintDirectly();
        HDIa_widgetExtCloseTransitionAnimation();
#endif /* WAP_SUPPORT */
        break;
    case MEA_STARTUP_MODE_DEFAULT:
        /* Default mode */
        (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, 
            MEA_FOLDER_INBOX);
        break;
    case MEA_STARTUP_MODE_NEW:
        if (0 == msgId)
        {
            /* This is a new message */
            (void)MEA_SIGNAL_SENDTO_U(MEA_CTH_FSM, MEA_SIG_CTH_START, 
                startupMode);
        }
        else
        {
            /* This is a new message using a template */
            (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 0,
                MEA_ME_STARTUP_FROM_TEMPLATE, msgId);
        }
        break;
    case MEA_STARTUP_MODE_NEW_TEMPLATE:
        (void)MEA_SIGNAL_SENDTO_IU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 0,
            MEA_ME_STARTUP_NEW_TEMPLATE);
        break;
    case MEA_STARTUP_MODE_EDIT:
        (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 0,
            MEA_ME_STARTUP_EDIT, msgId);
        break;
    case MEA_STARTUP_MODE_FORWARD:
        (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 0,
            MEA_ME_STARTUP_FORWARD, msgId);
        break;
    case MEA_STARTUP_MODE_REPLY:
        (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 0, 
            MEA_ME_STARTUP_REPLY, msgId);
        break;
    case MEA_STARTUP_MODE_REPLY_ALL:
        (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 0, 
            MEA_ME_STARTUP_REPLY_ALL, msgId);
        break;
    case MEA_STARTUP_MODE_DELETE:
        meaDeleteMsg(msgId);
        break;
    case MEA_STARTUP_MODE_SCHEME:
        (void)MEA_SIGNAL_SENDTO_U(MEA_CTH_FSM, MEA_SIG_CTH_START, 
            startupMode);
        break;
    case MEA_STARTUP_MODE_VIEW:
        {
#ifdef WAP_SUPPORT
            MSF_UINT32 str_id;
            str_id = MEA_STR_ID_NEW_MMS_MSG;
#ifdef __MMS_DUAL_SIM_SUPPORT__
            if(fldrGetMessageSimId(msgId) == MMS_SIM_CARD_MASTER && 
                (wap_get_sim_setting_mode() == WAP_SIM_ID_SIM1 || wap_get_sim_setting_mode() == WAP_SIM_ID_DUAL_SIM))
            {
                str_id = WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_1;
            }
            else if(fldrGetMessageSimId(msgId) == MMS_SIM_CARD_SLAVE && 
                    (wap_get_sim_setting_mode() == WAP_SIM_ID_SIM2 || wap_get_sim_setting_mode() == WAP_SIM_ID_DUAL_SIM))
            {
                str_id = WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_2;
            }
#endif /*__MMS_DUAL_SIM_SUPPORT__*/            
            if (!meaShowConfirmDialogWithStatusIcons(str_id, NULL, 
                MEA_MV_FSM, MEA_SIG_MV_ACTIVATE_CONFIRM, msgId))
            {
#ifdef __UNIFIED_MSG_SUPPORT__
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_ABNORMAL_TERMINATE_APP);
#else
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
#endif
            }
#else
            (void)MEA_SIGNAL_SENDTO_U(MEA_MV_FSM, MEA_SIG_MV_ACTIVATE, msgId);
#endif /* WAP_SUPPORT */
        }
        break;
    case MEA_STARTUP_MODE_CONFIG:
        /* Activate the configuration FSM */
        (void)MEA_SIGNAL_SENDTO(MEA_CONFIG_FSM, MEA_SIG_CONF_ACTIVATE);
        break;
    case MEA_STARTUP_MODE_SEND:
        /* Activate the sending FSM */
        meaSendMessage(MEA_NOTUSED_FSM, 0, msgId, TRUE);
        break;
    case MEA_STARTUP_MODE_DOWNLOAD:
        /* Activate the sending FSM */
#ifdef WAP_SUPPORT
        meaSetConfirmDialogWithStatusIcons();
        verifyDownload(MEA_SIG_COMM_DOWNLOAD_MODE_RSP, downloadSize, msgId);
        //meaDownloadMessage(MEA_MV_FSM, MEA_SIG_MV_DOWNLOAD_RSP, msgId);
#else
        meaDownloadMessage(MEA_NOTUSED_FSM, 0, msgId);
#endif /* WAP_SUPPORT */
        break;
    case MEA_STARTUP_MODE_PROVISIONING:
        /* Wait for provisioning data */
        break;
    case MEA_STARTUP_MODE_NONE:
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACORE_87661F15E46313EB7752BB6D872C1744, "(%s) (%d) Erroneous start-up mode!", __FILE__, __LINE__));
        MEA_TERMINATE;
        break;
    }
}

/*!
 * \brief Starts the SMIL player and plays the message.
 *
 * \param msgId The message identity of the message to start playing.
 * \param fileType The file type of the message. See #MmsFileType.
 * \param fsm The callback fsm (called when the player is stopped)
 * \param sig The callback signal.
 *****************************************************************************/
void meaPlaySmil(MmsMsgId pMsgId, MmsFileType fileType, MeaStateMachine fsm, 
    unsigned int sig)
{
    smaPlay.msgId       = pMsgId;
    smaPlay.fsm         = fsm;
    smaPlay.sig         = sig;
    smaPlay.fileType    = fileType;
    meaModuleStart(MSF_MODID_SMA, TRUE, MEA_CORE_FSM, 
        MEA_SIG_CORE_SMA_STARTED_PLY);
}


