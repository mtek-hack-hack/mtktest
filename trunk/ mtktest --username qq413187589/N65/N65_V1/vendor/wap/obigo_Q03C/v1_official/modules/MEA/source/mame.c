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

/* !\file mame.c
 *  \brief Message editor (properties) control logic. 
 */

/* MSF */
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_int.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_file.h" //for MSF_FILE_GETSIZE

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#ifdef WAP_SUPPORT
#include "msig.h"  /* for fldmgr.h */
#include "fldmgr.h"  /* for fldrGetFolderId */
#include "mmsl_if.h"
#include "mms_aApp.h" //for IsReachMEAMaxNumofMsg
#endif /* WAP_SUPPORT */

/* MEA */
#include "maintsig.h"
#include "mea_def.h"
#include "mea_env.h"
#include "mea_cfg.h"
#include "mea_rc.h"
#include "matypes.h"
#include "mamem.h"
#include "mase.h"
#include "mamr.h"
#include "mame.h"
#include "mamcr.h"
#include "mauimenu.h"
#include "mauime.h"
#include "maconf.h"
#include "macore.h"
#include "macomm.h"
#include "mauidia.h"
#include "maslh.h"
#include "mauiform.h"
#include "mauicmn.h"
#include "maaddr.h"
#include "mapbh.h"
#include "macth.h"
#include "masrh.h"
#include "mamme.h"
#include "mamh.h"
#include "madel.h"  /* for meaDeleteMsgSilent */
#ifdef WAP_SUPPORT
#include "mautils.h"
#include "mamoh.h"
#include "mamv.h"
#include "mauise.h" //for meaSeShowSlide
#include "widget.h"  /* func_ptr */
#include "widget_extension.h"
#include "phoneBook/phoneBookInc/phoneBookGprot.h"
#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "mmsadp.h"
extern void wap_send_mmi_mms_start_uc_req(kal_uint8 mode, kal_uint32 msg_id);
#endif
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Macros
 *****************************************************************************/
/* Checks whether the message type is needed */
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
#define MEA_ME_IS_MSG_TYPE_NEEDED(m) ((m == MEA_ME_STARTUP_EDIT) ||\
    (m == MEA_ME_STARTUP_FORWARD)   || (m == MEA_ME_STARTUP_REPLY) ||\
    (m == MEA_ME_STARTUP_REPLY_ALL) || (m == MEA_ME_STARTUP_FROM_TEMPLATE) || \
    (m == MEA_ME_STARTUP_SAVE_AS_TEMPLATE))
#else
#define MEA_ME_IS_MSG_TYPE_NEEDED(m) ((m == MEA_ME_STARTUP_EDIT) ||\
    (m == MEA_ME_STARTUP_FORWARD)   || (m == MEA_ME_STARTUP_REPLY) ||\
    (m == MEA_ME_STARTUP_REPLY_ALL) || (m == MEA_ME_STARTUP_FROM_TEMPLATE))
#endif

/* Checks if a new message is going to be created */
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
#define MEA_ME_CREATE_NEW_MSG(m) ((m == MEA_ME_STARTUP_NEW_MIXED) ||\
    (m == MEA_ME_STARTUP_NEW_SMIL) || (m == MEA_ME_STARTUP_NEW_TEMPLATE))
#else
#define MEA_ME_CREATE_NEW_MSG(m) ((m == MEA_ME_STARTUP_NEW_MIXED) ||\
    (m == MEA_ME_STARTUP_NEW_SMIL) || (m == MEA_ME_STARTUP_NEW_TEMPLATE))
#endif

/* Check whether the message properties needs to be verified before save */
#define MEA_IS_PROP_CHECK_NEEDED(type) ((MEA_SIG_ME_SAVE_PREVIEW != type) &&\
    (MEA_SIG_ME_SAVE_AS_TEMPLATE != type))
/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void meaMeSignalHandler(MeaSignal *sig);
static MSF_BOOL createInstance(MeaMeInstance **inst, MeaMeStartupMode mode);
static void deleteInstance(void);
static MSF_BOOL handleStartupMode(MeaMeInstance *inst, MeaStateMachine fsm, 
    int sig);
static void handleCt(MeaMeInstance *inst);
static MSF_BOOL handleStartup(const MeaMeStartupMode mode, MmsMsgId origId);
static MSF_BOOL showMenuEntry(int entryId);
#ifdef WAP_SUPPORT
static MSF_BOOL meaMeAddSignature(void);
static MSF_BOOL meaDeleteSignatureSlide(MeaSmilInfo *smilInfo);
#endif /* WAP_SUPPORT */
static MSF_BOOL meaCheckPropFields(MeaPropItem prop);

static MSF_BOOL meaMeIsUnrestrictedObjExist(MeaMessage *msg);
#ifndef __UNIFIED_COMPOSER_SUPPORT__
static void meaMeRemoveUnrestrictedObj(MeaSmilInfo *smilInfo);
#endif
#ifdef __UNIFIED_MSG_SUPPORT__
  #ifndef __UNIFIED_COMPOSER_SUPPORT__
static MSF_BOOL meaMeCreateMixedSmil(MeaMessage *theMessage);
  #endif
extern void mmi_um_skip_write_menu( kal_bool operation );
#endif
/******************************************************************************
 * Static variables 
 *****************************************************************************/
MSF_BOOL meaContentValidFlag = TRUE;      /* to check whether the MM is valid */
static MeaMeInstance        *curInst;    /*!< The message data */
static MSF_BOOL             needRRConfirm = FALSE; /* If show RR confirm when come edit prop screen from SMIL viewer*/

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
static MSF_UINT32 curDefTempIndex = 0;
#endif

#ifdef WAP_SUPPORT
struct cbFunc
{
    func_ptr func;
    void *param;
}exitCallback;
#endif /* WAP_SUPPORT */

typedef enum
{
    MEA_ME_NAV_NOT_USED,
    MEA_ME_NAV_SEND,
#ifdef WAP_SUPPORT
    MEA_ME_NAV_SAVE_AND_SEND,
#endif /* WAP_SUPPORT */
    MEA_ME_NAV_SAVE,
    MEA_ME_NAV_SAVE_AS_TEMPLATE,
    MEA_ME_NAV_EDIT_CONTENT,
    MEA_ME_NAV_OPTIONS,
    MEA_ME_NAV_NAV_BACK
}MeaMeNavMenuEntries;

const MeaNavMenuItem meaMeNavMenuItems[] = 
{
#ifdef WAP_SUPPORT
    {MEA_ME_NAV_SEND, MEA_STR_ID_SEND_ONLY, MEA_ME_FSM, MEA_SIG_ME_SEND, showMenuEntry},
    {MEA_ME_NAV_SAVE_AND_SEND, MEA_STR_ID_SAVE_AND_SEND, MEA_ME_FSM, MEA_SIG_ME_SAVE_AND_SEND, showMenuEntry},
    {MEA_ME_NAV_SAVE, MEA_STR_ID_SAVE_TO_DRAFTS, MEA_ME_FSM, MEA_SIG_ME_SAVE, showMenuEntry},
#else
    /*! Send message */
    {MEA_ME_NAV_SEND, MEA_STR_ID_SEND, MEA_ME_FSM, MEA_SIG_ME_SEND, showMenuEntry},

    /*! Save message */
    {MEA_ME_NAV_SAVE, MEA_STR_ID_SAVE, MEA_ME_FSM, MEA_SIG_ME_SAVE, showMenuEntry},
#endif /* WAP_SUPPORT */
    
    /*! Save message as template */
    {MEA_ME_NAV_SAVE_AS_TEMPLATE, MEA_STR_ID_SAVE_AS_TEMPLATE, MEA_ME_FSM, 
    MEA_SIG_ME_SAVE_AS_TEMPLATE, showMenuEntry},
    
#ifndef WAP_SUPPORT    
    /*! Edit content part of the message */
    {MEA_ME_NAV_EDIT_CONTENT, MEA_STR_ID_EDIT_CONTENT, MEA_ME_FSM, 
    MEA_SIG_ME_EDIT_CONTENT, showMenuEntry},
    
    /*! Message options */
    {MEA_ME_NAV_OPTIONS, MEA_STR_ID_OPTIONS, MEA_ME_FSM, 
    MEA_SIG_ME_EDIT_PROPERTIES, showMenuEntry},

    /*! Back, in property editor */
    {MEA_ME_NAV_NAV_BACK, MEA_STR_ID_BACK, MEA_ME_FSM, MEA_SIG_ME_PROP_BACK,
    NULL},
#else
    /*! Message options */
    {MEA_ME_NAV_OPTIONS, MEA_STR_ID_SEND_OPTIONS, MEA_ME_FSM, 
    MEA_SIG_ME_EDIT_PROPERTIES, showMenuEntry},
    //Change to exit
    {MEA_ME_NAV_NAV_BACK, MEA_STR_ID_EXIT, MEA_ME_FSM, MEA_SIG_ME_PROP_BACK,
    showMenuEntry},
#endif /* ~WAP_SUPPORT */

    {MEA_ME_NAV_NOT_USED, 0, MEA_NOTUSED_FSM, 0, NULL}
};

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
#define MEA_DEF_TEMP_TEXT_OBJ_NAME "Text"
#define MEA_DEF_TEMP_TEXT_OBJ_NAME_TYPE ".txt"
#define MEA_DEF_TEMP_IMAGE_OBJ_NAME "Image"
#define MEA_DEF_TEMP_IMAGE_OBJ_NAME_TYPE ".gif"
#define MEA_DEF_TEMP_AUDIO_OBJ_NAME "Audio"
#define MEA_DEF_TEMP_AUDIO_OBJ_NAME_TYPE ".mid"
#define MEA_DEF_TEMP_OBJ_NAME_MAX_LEN   32
extern MmsTemplateInfo mmsTemplates[];
extern audio_resource_struct *resource_mms_sounds;

static void meaAddDefTempContent(void);
static void meaSetMeDefTempIndex(MSF_UINT32 index);
static MSF_UINT32 meaGetMeDefTempIndex(void);
static void meaResetMeDefTempIndex(void);
static MSF_BOOL meaMeAddDefTempContent(void);
static void meaMeAddDefTempContentFail(MeaMhCreateDefTemplateResult error);
static MSF_BOOL meaMeAddSubject(MeaMeInstance *inst, MSF_UINT32 index);
static MSF_BOOL meaMeAddSlide(MeaSmilInfo *smilInfo);
static MSF_BOOL meaMeAddTextObj(MeaSmilInfo *smilInfo, MSF_UINT32 index);
static MSF_BOOL meaMeAddImageObj(MeaSmilInfo *smilInfo, MSF_UINT32 index);
static MSF_BOOL meaMeAddAudioObj(MeaSmilInfo *smilInfo, MSF_UINT32 index);

#endif /* MEA_CFG_USER_TEMPLATE_SUPPORT*/

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Function called by menu system to decide if a menu entry should 
 *        be shown
 * 
 * \param entryId   The entryId of the selected menu entry
 * \return TRUE if save as template menu entry should be displayed
 *****************************************************************************/
static MSF_BOOL showMenuEntry(int entryId)
{
    MSF_BOOL ret = TRUE;
    switch ((MeaMeNavMenuEntries)entryId)
    {
#ifdef WAP_SUPPORT
    case MEA_ME_NAV_SAVE_AND_SEND:
        {
        MeaPropItem *propItem = curInst->theMessage->msgProperties;
        if ((curInst != NULL ) && 
            (curInst->theMessage->fileType == MMS_SUFFIX_TEMPLATE && curInst->mode != MEA_ME_STARTUP_FROM_TEMPLATE) )
        {
            /* Do not display send for templates and retrieve conf. */
            ret = FALSE;
        }
        if ((curInst != NULL) && (propItem->to == NULL) && (propItem->cc == NULL) && 
            (propItem->bcc == NULL))
        {
            /* Do not display Save and Send if no recipient */
            ret = FALSE;
        }
        curInst->mcrFsm = MEA_ME_FSM;
        curInst->mcrSig = MEA_SIG_ME_MENU_SEND_DONE;
        break;
    }
    case MEA_ME_NAV_NAV_BACK:
        /* Display "Exit", not "Save", during a forward operation */
        curInst->mcrFsm = MEA_ME_FSM;
        curInst->mcrSig = MEA_SIG_ME_MENU_SAVE_DONE;
        break;
#endif  /*WAP_SUPPORT*/
    case MEA_ME_NAV_SEND:
#ifdef WAP_SUPPORT
        if ((curInst != NULL ) && 
            (curInst->theMessage->fileType == MMS_SUFFIX_TEMPLATE && curInst->mode != MEA_ME_STARTUP_FROM_TEMPLATE) )
        {
            /* Do not display send for templates and retrieve conf. */
            ret = FALSE;
        }
        if ((curInst != NULL) && (curInst->theMessage->msgProperties->to == NULL) && 
            (curInst->theMessage->msgProperties->cc == NULL) && 
            (curInst->theMessage->msgProperties->bcc == NULL))
        {
            /* Do not display Send Only if no recipient */
            ret = FALSE;
        }
#else
        if ((curInst != NULL ) && (
            (curInst->theMessage->fileType == MMS_SUFFIX_TEMPLATE) ||
            (curInst->theMessage->fileType == MMS_SUFFIX_MSG)))
        {
            /* Do not display send for templates and retrieve conf. */
            ret = FALSE;
        }
#endif /* WAP_SUPPORT */
        curInst->mcrFsm = MEA_ME_FSM;
        curInst->mcrSig = MEA_SIG_ME_MENU_SEND_DONE;
        break;
    case MEA_ME_NAV_SAVE:
#ifdef WAP_SUPPORT
        if ((curInst != NULL ) && ( curInst->mode == MEA_ME_STARTUP_FORWARD ||
            (curInst->theMessage->fileType == MMS_SUFFIX_TEMPLATE && curInst->mode != MEA_ME_STARTUP_FROM_TEMPLATE) ))
#else
        if ((curInst != NULL ) && ((curInst->mode == MEA_ME_STARTUP_FORWARD) ||
            (curInst->theMessage->fileType == MMS_SUFFIX_TEMPLATE) ||
            (curInst->theMessage->fileType == MMS_SUFFIX_MSG)))
#endif /* WAP_SUPPORT */
        {
            /* Do not display save during a forward operation, or for 
               templates and retrieve conf. */
            ret = FALSE;
        }
        curInst->mcrFsm = MEA_ME_FSM;
        curInst->mcrSig = MEA_SIG_ME_MENU_SAVE_DONE;
        break;
    case MEA_ME_NAV_SAVE_AS_TEMPLATE:
        /*	Insert code here that determines whether this entry should be shown
         *  and returns FALSE instead of breaks if so.
         */

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        if ((curInst != NULL ) && (curInst->mode == MEA_ME_STARTUP_FORWARD))
#endif /* ~WAP_SUPPORT */
        {
            /* Do not display "save as template" during a forward operation */
            ret = FALSE;
        }
        curInst->mcrFsm = MEA_ME_FSM;
        curInst->mcrSig = MEA_SIG_ME_MENU_SAVE_AS_TEMPLATE_DONE;
        break;
    case MEA_ME_NAV_EDIT_CONTENT:
        if ((curInst != NULL ) && (curInst->mode == MEA_ME_STARTUP_FORWARD))
        {
            /* Do not display "Edit content" during a forward operation */
            ret = FALSE;
        }
        break;
    case MEA_ME_NAV_OPTIONS:
#ifdef WAP_SUPPORT
    {
        MeaPropItem *propItem = curInst->theMessage->msgProperties;
        if ((curInst != NULL ) && 
            (curInst->theMessage->fileType == MMS_SUFFIX_TEMPLATE && curInst->mode != MEA_ME_STARTUP_FROM_TEMPLATE) )
        {
            /* Do not display send for edit templates*/
            ret = FALSE;
        }
        if ((curInst != NULL) && (propItem->to == NULL) && (propItem->cc == NULL) && 
            (propItem->bcc == NULL))
        {
            /* Do not display Send Option if no recipient */
            ret = FALSE;
        }
        break;
    }
#else
    case MEA_ME_NAV_NAV_BACK:
#endif /*~WAP_SUPPORT*/
    case MEA_ME_NAV_NOT_USED:
    default:
        break;
    } /* switch */

    return ret; /* Always show all menu entries */
} /* showMenuEntry */

/*! 
 * \brief Closes the GUI for the message editor 
 *****************************************************************************/
void meaMeTerminateGui(void)
{
    meaMeDeleteNavMenu();
    meaMeDeletePropView();
#ifdef WAP_SUPPORT
    meaMeDeleteAddrListView();
    if (meaGetAttachmentList())
        meaSeRemoveAttachmentList();
#endif /* WAP_SUPPORT */

/* for VScrollbar error*/
#ifdef WIDGET_SLIDING_SMIL_VBAR
    mtrDeleteVScrollBar();
#endif
/* for VScrollbar error end*/

}

/*!
 * \brief Initiates the message editor by registering its signal handler
 *****************************************************************************/
void meaMeInit(void)
{
    curInst = NULL;
    needRRConfirm = FALSE;
    meaSignalRegisterDst(MEA_ME_FSM, meaMeSignalHandler);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, MAME_45EB9FE2D26D8693C0D2DE1AE7AD12FA, "ME initialized\n"));
}

/*!
 * \brief Terminates the message editor.
 *****************************************************************************/
void meaMeTerminate(void)
{
    /* GUI clean-up*/
    meaMeTerminateGui();
    /* Clean-up message data */
    deleteInstance();
#ifdef WAP_SUPPORT
    if (exitCallback.func)
    {
        widget_execute_MMI_p(exitCallback.func, exitCallback.param, FALSE);
        memset(&exitCallback, 0x00, sizeof(struct cbFunc));
    }
#endif
    /* Deregister queue */
    meaSignalDeregister(MEA_ME_FSM);
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MAME_2AA9B3F27C8D4FF6967E91FF111BE09F, "(%s) (%d) ME terminated\n", __FILE__, __LINE__));
}

/*!
 * \brief Creates a message editor instance
 *
 * \param inst The new instance
 * \param mode The start-up mode for the ME.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL createInstance(MeaMeInstance **inst, MeaMeStartupMode mode)
{
    MeaMeInstance *newInst;
    
    if (NULL != *inst)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAME_109B30CA61C747DF61037B358C3DE192, "(%s) (%d) cannot initialize!\n", __FILE__, __LINE__));
        return FALSE;
    }    
    
    /* Allocate the new instance */
    MEA_CALLOC(newInst, sizeof(MeaMeInstance));
    /* Set the mode */
    newInst->mode = mode;
    /* Set the new instance */
    *inst = newInst;

    if (!meaIsCreateConfValid())
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ME_INVALID_CONFIG),
            MEA_DIALOG_ERROR);
        return FALSE;
    } 
    return TRUE;
}

/*!
 * \brief Deletes the ME instance.
 *****************************************************************************/
static void deleteInstance(void)
{
    MeaMeInstance **inst = &curInst;

    if (NULL == *inst)
    {
        return;
    }
    
    /* Containing SMIL presentation? */
    if ((*inst)->theMessage && (*inst)->theMessage->smilInfo)
    {
        meaCleanupSmilInstance(&(*inst)->theMessage->smilInfo);
    }
    /* Delete message properties */
    meaFreeMessage(&(*inst)->theMessage);
    /* Check if the "content insert" data has been de-allocated */
    meaCtFreeContentInsert((*inst)->ct);
    /* De-allocate the instance */
    MEA_FREE(*inst);
    *inst = NULL;

    needRRConfirm = FALSE;
}

/*!
 * \brief Handles the structure passed to the ME FSM if Cross Triggering is 
 *        Initiating the start-up.
 *****************************************************************************/
static void handleCt(MeaMeInstance *inst)
{
    /* Check if the instance is valid */
    if (NULL != inst->ct)
    {
        if ((inst->ct->name != NULL) && 
            (NULL != meaInsertSlide(inst->theMessage->smilInfo)))
        {
            /* Set the image as the slide content */
#ifdef __DRM_SUPPORT__ 
            /* get drmType in meaSeShowSlide() */
            if (NULL == meaSetSlideMo(inst->theMessage->smilInfo, inst->ct->mediaType, MEA_MEDIA_TYPE_UNKNOWN, NULL, 
                                      inst->ct->buffer, inst->ct->bufferSize, inst->ct->name, inst->ct->resHandle))
#else
            if (NULL == meaSetSlideMo(inst->theMessage->smilInfo, inst->ct->mediaType, NULL, inst->ct->buffer, 
                                      inst->ct->bufferSize, inst->ct->name, inst->ct->resHandle))
#endif
            {
                meaCtFreeContentInsert(inst->ct);
            }
            inst->ct->buffer     = NULL;
            inst->ct->bufferSize = 0;
            inst->ct->name       = NULL;
        }
        if (NULL != inst->ct->propItem)
        {
            inst->theMessage->msgProperties->to = inst->ct->propItem->to;
            if (inst->theMessage->msgProperties->to)
            {
                meaNameLookup(inst->theMessage->msgProperties->to, (MeaStateMachine)0, (int)0);
            }
            inst->ct->propItem->to = NULL;
            inst->theMessage->msgProperties->cc = inst->ct->propItem->cc;
            inst->ct->propItem->cc = NULL;
            inst->theMessage->msgProperties->bcc = inst->ct->propItem->bcc;
            inst->ct->propItem->bcc = NULL;
            inst->theMessage->msgProperties->subject = 
                inst->ct->propItem->subject;
            inst->ct->propItem->subject = NULL;
        }
    }
    /* The content is copied, removed unused data */
    meaCtFreeContentInsert(inst->ct);
    inst->ct = NULL;
}

/*!
 * \brief Handles the different ways that the ME can be started
 * 
 * \param inst The current ME instance.
 * \param fsm Callback FSM, used when a message needs to be loaded first
 * \param sig Callback signal, used when a message needs to be loaded first
 * \return TRUE if everything went ok, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL handleStartupMode(MeaMeInstance *inst, MeaStateMachine fsm, 
    int sig)
{
    MeaConfig *config;
    MeaPropItem *propItem;
    MeaMrStartupMode mode;
    
    if (!inst) 
    {
        return FALSE;
    } /* if */

    if (MEA_ME_CREATE_NEW_MSG(inst->mode))
    {
        MEA_CALLOC(inst->theMessage, sizeof(MeaMessage));
        MEA_CALLOC(inst->theMessage->msgProperties, sizeof(MeaPropItem));
        /* Always create SMIL instance for new messages */
        if ((MEA_ME_STARTUP_NEW_SMIL == inst->mode) || 
            (MEA_ME_STARTUP_NEW_TEMPLATE == inst->mode))
        {
            inst->theMessage->msgType = MEA_MR_SMIL;
            if (!meaCreateSmilInstance(&inst->theMessage->smilInfo))
            {
                return FALSE;
            }
        }

        /* Insert content, if any */
        handleCt(inst);

        /* Copy configuration data to new message */
        config = meaGetConfig();
        propItem = inst->theMessage->msgProperties;
        propItem->deliveryReport        = config->deliveryReport;
        propItem->readReport            = config->readReport;
        propItem->senderVisibility      = config->senderVisibility;
        propItem->expiryTime            = config->expiryTime;
        propItem->priority              = config->priority;
        propItem->replyCharging         = config->replyCharging;
        propItem->replyChargingDeadline = config->replyChargingDeadline;
        propItem->replyChargingSize     = config->replyChargingSize;

        if(meaCalculateMsgSize(inst->theMessage->smilInfo, inst->theMessage->msgProperties) > 
            MEA_CFG_MESSAGE_SIZE_MAXIMUM)
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED), MEA_DIALOG_ERROR);
            return FALSE;
        }
        
        /* For new messages, show the GUI directly */
        if (!meaMeCreatePropView(inst->theMessage->msgProperties, inst->mode))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAME_C339F59A049C8D3DE7F766C87349F83F, "(%s) (%d) failed to create message property form!\n", 
                __FILE__, __LINE__));
            meaMeDeletePropView();
            return FALSE;
        }
        return TRUE;
    } 
    else
    {
        /* Check which mode to start the MR FSM in */
        switch (inst->mode)
        {
        case MEA_ME_STARTUP_FROM_TEMPLATE:
        case MEA_ME_STARTUP_EDIT:
#ifdef WAP_SUPPORT
        case MEA_ME_STARTUP_APPEND_SIGNATURE:
#endif /* WAP_SUPPORT */
            mode = MEA_MR_STARTUP_NORMAL;
            break;
        case MEA_ME_STARTUP_REPLY:
            mode = MEA_MR_STARTUP_REPLY;
            break;
        case MEA_ME_STARTUP_FORWARD:
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        case MEA_ME_STARTUP_SAVE_AS_TEMPLATE:
#endif
            mode = MEA_MR_STARTUP_FORWARD;
            break;
        case MEA_ME_STARTUP_REPLY_ALL:
            mode = MEA_MR_STARTUP_REPLY_ALL;
            break;
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        case MEA_ME_STARTUP_CREATE_DEF_TEMP:
            /* Create SMIL*/
            MEA_CALLOC(inst->theMessage, sizeof(MeaMessage));
            MEA_CALLOC(inst->theMessage->msgProperties, sizeof(MeaPropItem));
        
            inst->theMessage->msgType = MEA_MR_SMIL;
            if (!meaCreateSmilInstance(&inst->theMessage->smilInfo))
            {
                return FALSE;
            }
            /* Start adding content*/
            meaAddDefTempContent();
            return TRUE;
#endif
        case MEA_ME_STARTUP_NEW_MIXED:
        case MEA_ME_STARTUP_NEW_SMIL:
        case MEA_ME_STARTUP_NEW_TEMPLATE:
        default:
            return FALSE;
        }
        meaStartMr(mode, inst->origMsgId, inst->origFileType, fsm, 
            (unsigned int)sig);
        return TRUE;
    } /* if */
}

/*! \brief Adds recipient addresses.
 *
 * \param propItem The current addresses
 * \param items The address to add.
 *****************************************************************************/
static void setAddr(MeaAddrItem **current, MeaAddrItem *items)
{
    unsigned int addCount;
    unsigned int currentCount;

    addCount = meaAddrItemCount(*current);
    currentCount = meaAddrItemCount(items);
    if ((addCount + currentCount) > MEA_CFG_MAX_RECIPIENT_ADDRESSES)
    {
        /* To many items */
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_TO_MANY_RECIPIENTS), 
            MEA_DIALOG_ERROR);
        meaAddrListFree(&items);
        return;
    }
#ifdef WAP_SUPPORT
    if (meaMeAddressAlreadyExists(*current, items) > -1)
    {
        /* Already Exists */
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ADDRESS_ALREADY_EXISTS), 
            MEA_DIALOG_ERROR);
        meaAddrListFree(&items);
        return;
    }
#endif /* WAP_SUPPORT */
    /* Insert items */
    *current = meaAddrItemAppend(*current, items);
}

/*!
 * \brief Reports an MFS_BOOL result back to a requesting FSM, or 
 *        deactivates ME in the case of no requesting FSM
 * 
 * \param result The result to report
 * \param fsm    The FSM to report to
 * \parm sig     The signal to carry the report
 *****************************************************************************/
static void reportOrClose(MSF_BOOL result, MeaStateMachine *fsm, int *sig)
{
    if (MEA_NOTUSED_FSM != *fsm)
    {
        (void)MEA_SIGNAL_SENDTO_U(*fsm, *sig, (unsigned long)result);
    }
    else
    {
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
    } /* if */

    /* Used now, don't need'em anymore */
    *fsm = MEA_NOTUSED_FSM;
    *sig = 0;    
} /* reportOrClose */

/*!
 * \brief Handles startup of ME, i.e. decides what to do next
 * 
 * \param mode      The ME startup mode
 * \param origId    The msgid of the originating message, if any
 * \return TRUE on successful startup, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL handleStartup(const MeaMeStartupMode mode, MmsMsgId origId)
{
    /* Check if the file type for the originating message is needed */
    if (MEA_ME_IS_MSG_TYPE_NEEDED(mode))
    {
        /* Get the file type of the originating message */
        meaSrhGetMessageInfo(MEA_ME_FSM, MEA_SIG_ME_GET_MSG_INFO_RSP, origId);
        return TRUE;
    }
    else if (MEA_ME_CREATE_NEW_MSG(mode))
    {
        /* Initiate new message in next state */
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_MR_START);
        return TRUE;
    }

    (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), 
        MEA_DIALOG_ERROR);
    return FALSE;
} /* handleStartup */

/*!
 * \brief Remove Unknown Type Object. 
 * 
 * \param smilInfo  smil info
 * \return <whatever is returned>
 *****************************************************************************/

static void meaMeRemoveUnknownTypeObject(MeaSmilInfo *smilInfo)
{
    MeaSmilSlide *cur_slide;
    MeaMoDataItem *check;
    int i;
    /* SANITY CHECK */
    if(smilInfo == NULL)
    {
        return;
    }

    /* remove invalid object from slide */
    cur_slide = smilInfo->slides;
    while(cur_slide != NULL)
    {
        for(i= 0 ; i<MEA_MAX_SMIL_OBJS ; i++)
        {
            if(cur_slide->objects[i]!= NULL &&
                (cur_slide->objects[i]->object->content.type < 0 || meaFileName2MimeType(cur_slide->objects[i]->object->name) == NULL))
            {
                cur_slide->objects[i] = NULL;
            }
        }
        cur_slide = cur_slide->next;
    }

    check = smilInfo->mediaObjects;

    while(check != NULL)
    {
        /* remove invalid object from object list*/
        if(check->content.type < 0 || meaFileName2MimeType(check->name) == NULL)
        {
            MeaMoDataItem *next = check->next;
            meaContentValidFlag = FALSE;
            meaDeleteMo(&(smilInfo->mediaObjects), smilInfo->slides, check);
            check = next;
        }
        else
        {
            check = check->next;
        }
    }

}
/*!
 * \brief check object type. 
 * 
 * \param smilInfo  smil info
 * \return <whatever is returned>
 *****************************************************************************/

static void meaMeValidateObject(MeaSmilInfo **smilInfo)
{
    MeaMoDataItem *check;

    int temp_size = 0, i, j, index;
    

    if(smilInfo == NULL || *smilInfo == NULL)      /* SANITY CHECK */
    {
        return ;
    }

    /* remove invalid object from slide */
    meaMeRemoveUnknownTypeObject(*smilInfo);

    if(smilInfo == NULL || *smilInfo == NULL)
    {
        return;
    }

    check = (*smilInfo)->mediaObjects;

    while(check != NULL)
    {
        MeaMediaGroupType gType = meaMediaType2ObjType(check->content.type);
        switch(gType)
        {
            /* truncate the text length*/
            case MEA_MEDIA_GROUP_TEXT:
            {
                if(widget_utf8_length(check->data) > MEA_MAX_TEXT_LENGTH)
                {
                    temp_size = 0;
                    index = 0;
                    for(i = 0, j = 0 ; j < MEA_MAX_TEXT_LENGTH+1     ; i += index, j++)
                    {
                        index = msf_cmmn_utf8_charlen((char *)(&check->data[i]));
                        if(index == 0)
                        {
                            index++;
                        }
                        temp_size += index;
                    }
                    check->size = temp_size;
                    check->data[i] = 0;                    

                }
                else
                {
                    int       i, j;
                    MSF_INT32 utf8_string_len = 0;
                    MSF_INT32 utf8_char_len = 0;
                    MSF_INT32 utf8_string_byte_len = 0;

                    /* utf8 string character len*/
                    utf8_string_len = widget_utf8_length(check->data) + 1;
                    
                    /* calc utf8 string byte len*/
                    for(i = 0, j = 0; j < utf8_string_len; i += utf8_char_len, j++)
                    {
                        utf8_char_len = msf_cmmn_utf8_charlen((char *)(&check->data[i]));
                        if (utf8_char_len == 0)
                        {
                            utf8_char_len++;
                        }
                        utf8_string_byte_len += utf8_char_len;
                    }

                    if (utf8_string_byte_len < check->size)
                    {
                        check->size = utf8_string_byte_len;
                    }
                }

                check = check->next;
            }
            break;

            default:
            {
                check = check->next;
            }
            break;
        }
        continue;
    }
    return;
}
/*!
 * \brief Handles returning from MR FSM. 
 * 
 * \param inst          The current instance
 * \param result        The MR result code
 * \param message       The message read by MR
 * \param largeObjects  Number of objects larger than limitations
 * \return <whatever is returned>
 *****************************************************************************/
void handleReturnFromMr(MeaMeInstance *inst, MeaMrResult result, 
    MeaMessage *message, int largeObjects)
{
    MSF_UINT32 msgSize;
    inst->theMessage = message;

    if ((MEA_MR_OK != result) || 
        (NULL == inst->theMessage) || 
        (NULL == inst->theMessage->msgProperties))
    {
        /* Clean-up */
        meaMeTerminateGui();
        if(MEA_ME_STARTUP_FORWARD == inst->mode)
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_FORWARD), MEA_DIALOG_ERROR);
        }
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        else if(MEA_ME_STARTUP_SAVE_AS_TEMPLATE == inst->mode)
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_SAVE_AS_TEMPLATE), MEA_DIALOG_ERROR);
        }
#endif
        else
        {
            if (MEA_MR_UNSUPPORTED_HEADER_FIELDS == result)
            {
                (void)meaShowDialog(
                    MEA_GET_STR_ID(MEA_STR_ID_UNSUPPORTED_HEADER_FIELDS),
                    MEA_DIALOG_ERROR);
            }
            else if (MEA_MR_FORWARD_LOCK == result)
            {
                (void)meaShowDialog(
                    MEA_GET_STR_ID(MEA_STR_ID_FAILED_FORWARD_LOCK), MEA_DIALOG_ERROR);
            }
            else
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), 
                    MEA_DIALOG_ERROR);            
            }
        }
        
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        return;
    }
    
    /* validate object from mr */
    meaMeValidateObject(&(inst->theMessage->smilInfo));
    inst->theMessage->msgProperties->senderVisibility = meaGetConfig()->senderVisibility;

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    if (MEA_ME_STARTUP_SAVE_AS_TEMPLATE == inst->mode)
    {
        meaAddrListFree(&inst->theMessage->msgProperties->to);
        meaAddrListFree(&inst->theMessage->msgProperties->cc);
        meaAddrListFree(&inst->theMessage->msgProperties->bcc);
        meaAddrListFree(&inst->theMessage->msgProperties->from);
    }
    else
    {
#endif
    /* Address filter */
    meaMeAddressFilter(&inst->theMessage->msgProperties->to, MEA_ADDR_TYPE_PLMN | MEA_ADDR_TYPE_EMAIL);
    meaMeAddressFilter(&inst->theMessage->msgProperties->cc, MEA_ADDR_TYPE_PLMN | MEA_ADDR_TYPE_EMAIL);
    meaMeAddressFilter(&inst->theMessage->msgProperties->bcc, MEA_ADDR_TYPE_PLMN | MEA_ADDR_TYPE_EMAIL);
    
    /* Name lookup */
    meaNameLookup(inst->theMessage->msgProperties->to, MEA_ME_FSM, MEA_SIG_ME_LOOKUP_RSP);
    meaNameLookup(inst->theMessage->msgProperties->cc, MEA_ME_FSM, MEA_SIG_ME_LOOKUP_RSP);
    meaNameLookup(inst->theMessage->msgProperties->bcc, MEA_ME_FSM, MEA_SIG_ME_LOOKUP_RSP);

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    }
#endif

    msgSize = meaMeCalculateMsgSize();
    if ( msgSize > MEA_CFG_MESSAGE_SIZE_MAXIMUM)
    {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED), 
                MEA_DIALOG_ERROR);
            return;
    }

    /* No SMIL will have been read and allocated in these startup modes */
    if ((MEA_ME_STARTUP_REPLY     == inst->mode) ||
        (MEA_ME_STARTUP_REPLY_ALL == inst->mode))
    {
        if (!meaCreateSmilInstance(&inst->theMessage->smilInfo))
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), 
                MEA_DIALOG_ERROR);
            return;
        }            
    }
    else if (MEA_ME_STARTUP_APPEND_SIGNATURE == inst->mode)
    {
        //meaInsertSignatureSlide(inst->theMessage->smilInfo);
        MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_SEND);
        return;
    }
    else if(MEA_ME_STARTUP_EDIT == inst->mode || MEA_ME_STARTUP_FROM_TEMPLATE == inst->mode)
    {
#ifdef __UNIFIED_MSG_SUPPORT__
  #ifndef __UNIFIED_COMPOSER_SUPPORT__
        if((MEA_MR_PLAIN_TEXT == inst->theMessage->msgType) || (MEA_MR_MULTIPART_MIXED == inst->theMessage->msgType))
        {
            if(meaMeCreateMixedSmil(inst->theMessage) == FALSE)
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), MEA_DIALOG_ERROR);
                (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
                return;
            }
        }
                
        inst->theMessage->smilInfo->currentSlide = inst->theMessage->smilInfo->slides;
  #endif
#else
        if(inst->theMessage->msgType != MEA_MR_SMIL)
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), MEA_DIALOG_ERROR);
            return;
        }
#endif
        if(inst->theMessage->unrefList)  /* GUI limitation for multiple attachment editing */
        {
            meaRemoveAttachment(&inst->theMessage->unrefList);
            inst->delOrigMsgAttachmentFlg = TRUE;  /* To popup after property editing screen */
        }

        if(meaConfGetCreationMode() != MEA_CREATION_MODE_FREE)
        {
            char *filename = MMSlib_getMessageFullPath(MSF_MODID_MEA, inst->theMessage->msgId, 
                fldrGetFileSuffix(inst->theMessage->msgId));
            
            if(MSF_FILE_GETSIZE(filename) > MEA_RESTRICTED_MESSAGE_SIZE)
            {
                (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_RESTRICTED_MODE_FAIL_TO_EDIT), MEA_DIALOG_ERROR);
                MEA_FREE(filename);
                return;
            }
            else if(meaMeIsUnrestrictedObjExist(inst->theMessage))
            {
                (void)meaShowConfirmDialog(MEA_STR_ID_RESTRICTED_MODE_REMOVE_OBJ_REQ, NULL, MEA_ME_FSM, 
                    MEA_SIG_ME_REMOVE_UNRESTRICTED_OBJECT, 0);
                MEA_FREE(filename);
                return;
            }
            MEA_FREE(filename);
        }
#ifdef __UNIFIED_COMPOSER_SUPPORT__
        if(meaContentValidFlag == FALSE)
        {
            (void)meaShowDialogWithConfirm(MsfWarning, MEA_STR_ID_OK, 0, MEA_STR_ID_REMOVE_INVALID_OBJECT, 
                                        MEA_ME_FSM, MEA_SIG_ME_REMOVE_INVALID_OBJECT, 0);
            return;
        }
#endif /*__UNIFIED_COMPOSER_SUPPORT__*/
#ifdef __UNIFIED_COMPOSER_SUPPORT__
        wap_send_mmi_mms_start_uc_req(MMA_MODE_EDIT, inst->theMessage->msgId);
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        return;
#endif
    }
    else if(MEA_ME_STARTUP_FORWARD == inst->mode)
    {
        char *filename = MMSlib_getMessageFullPath(MSF_MODID_MEA, inst->theMessage->msgId, 
            fldrGetFileSuffix(inst->theMessage->msgId));
        
        if(meaConfGetCreationMode() != MEA_CREATION_MODE_FREE && (MSF_FILE_GETSIZE(filename) > MEA_RESTRICTED_MESSAGE_SIZE ||
            meaMeIsUnrestrictedObjExist(inst->theMessage)))
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_RESTRICTED_MODE_FAIL_TO_FORWARD), MEA_DIALOG_ERROR);
            MEA_FREE(filename);
            return;
        }
        MEA_FREE(filename);

#ifdef __UNIFIED_COMPOSER_SUPPORT__
        wap_send_mmi_mms_start_uc_req(MMA_MODE_FORWARD, inst->theMessage->msgId);
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        return;
#endif
    }

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    else if (MEA_ME_STARTUP_SAVE_AS_TEMPLATE == inst->mode)
    {
        MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_SAVE_AS_TEMPLATE);
        return;
    }
#endif

    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_CREATE_PROP_VIEW);
} /* handleReturnFromMr */

/*!
 * \brief The message editor signal handling logic
 *
 * \param sig The received signal
 *****************************************************************************/
static void meaMeSignalHandler(MeaSignal *sig)
{
    MeaAddrItem     *tmpAddrItem;
    MeaMeInstance   *inst;
    MmsFolderType   folder;
    MeaAddrItem     *item = NULL;
    MSF_BOOL        deleteMsg;

    inst = curInst;
    if ((sig->type != MEA_SIG_ME_ACTIVATE) && (inst == NULL)) 
    {
        meaSignalDelete(sig);
        return;
    } /* if */

    switch(sig->type)
    {

    /*
     *	ACTIVATION/DEACTIVATION
     */
    case MEA_SIG_ME_ACTIVATE:
#ifndef __UNIFIED_COMPOSER_SUPPORT__
        if (IsReachMEAMaxNumofMsg(MMS_MAX_NO_OF_MSG-1))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MAX_NUMBER_OF_MSG), MEA_DIALOG_ERROR);

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            if ((MeaMeStartupMode)sig->u_param1 == MEA_ME_STARTUP_CREATE_DEF_TEMP)
            {
                (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_CREATE_DEF_TEMP_FINISHED, 
                    MEA_MH_DEF_TEMP_RESULT_MAX_NUM);
            }
#endif
            break;
        }
#endif
        if (!createInstance(&curInst, (MeaMeStartupMode)sig->u_param1))
        {
            meaCtFreeContentInsert(sig->p_param);
            /* Failed to create the instance */
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            if ((MeaMeStartupMode)sig->u_param1 == MEA_ME_STARTUP_CREATE_DEF_TEMP)
            {
                (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_CREATE_DEF_TEMP_FINISHED, 
                    MEA_MH_DEF_TEMP_RESULT_FAILED);
            }
#endif

            break;
        }
        inst = curInst;
        /* Save activation parameters */
        inst->ct          = (MeaCtContentInsert *)sig->p_param;
        inst->origMsgId   = (MmsMsgId)sig->u_param2;

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        if ((MeaMeStartupMode)sig->u_param1 == MEA_ME_STARTUP_CREATE_DEF_TEMP)
        {
            meaSetMeDefTempIndex((MSF_UINT32)sig->u_param2);
        }
#endif

#ifdef WAP_SUPPORT
        if ((MeaMeStartupMode)sig->u_param1 == MEA_ME_STARTUP_APPEND_SIGNATURE)
        {
            inst->origFileType = MMS_SUFFIX_SEND_REQ;
            /* Get message in next state */
	        if (!handleStartupMode(inst, MEA_ME_FSM, MEA_SIG_ME_MR_DONE))
	        {
	            /* Failed to start-up, clean-up and exit */
	            deleteInstance();
	            /* If messages can not be created then something must be terribly
	             * wrong, restart!
	             */
#ifdef __UNIFIED_MSG_SUPPORT__
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
#else
	            meaSignalDelete(sig);
	            MEA_TERMINATE;
#endif
	        }
	        break;
        }
#endif /* WAP_SUPPORT */

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        if ((MeaMeStartupMode)sig->u_param1 == MEA_ME_STARTUP_SAVE_AS_TEMPLATE)
        {
            inst->origFileType = sig->i_param;

            if (!handleStartupMode(inst, MEA_ME_FSM, MEA_SIG_ME_MR_DONE))
	     {
	            /* Failed to start-up, clean-up and exit */
	            deleteInstance();
	            /* If messages can not be created then something must be terribly
	             * wrong, restart!
	             */
#ifdef __UNIFIED_MSG_SUPPORT__
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
#else
	            meaSignalDelete(sig);
	            MEA_TERMINATE;
#endif
	     }
            break;
        }

        if ((MeaMeStartupMode)sig->u_param1 == MEA_ME_STARTUP_CREATE_DEF_TEMP)
        {
            if (!handleStartupMode(inst, MEA_ME_FSM, MEA_SIG_ME_MR_DONE))
	     {
	            /* Failed to start-up, clean-up and exit */
	            deleteInstance();
	            /* If messages can not be created then something must be terribly
	             * wrong, restart!
	             */
/*
#ifdef __UNIFIED_MSG_SUPPORT__
                   (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
#else
	            meaSignalDelete(sig);
	            MEA_TERMINATE;
#endif
*/
                    (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_CREATE_DEF_TEMP_FINISHED, 
                        MEA_MH_DEF_TEMP_RESULT_FAILED);
	     }
            break;
        }
#endif

        /*  Handle startup. Will generate MEA_SIG_ME_GET_MSG_INFO_RSP or 
         *  MEA_SIG_ME_MR_START.
         */
        if (! handleStartup(inst->mode, inst->origMsgId))
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        } /* if */
        break;
        
    case MEA_SIG_ME_DEACTIVATE:
        {
#ifdef __UNIFIED_MSG_SUPPORT__        	
            MmsMsgId mea_to_delete_msg_id = 0;
            if(curInst->origMsgId != 0 && curInst->delOrigMsgFlg == TRUE)
            {
                mea_to_delete_msg_id = curInst->origMsgId;
            }
#endif /*__UNIFIED_MSG_SUPPORT__*/
            /* Bring down the GUI*/
            meaMeTerminateGui();
            /* Clean-up the text editor instance */
            deleteInstance();
            (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
                MEA_FOLDER_NONE);
#ifdef __UNIFIED_MSG_SUPPORT__                            
            if(mea_to_delete_msg_id != 0)
            {
                meaDeleteMsgSilent(mea_to_delete_msg_id);       
            }
#endif /*__UNIFIED_MSG_SUPPORT__*/            
            if ((MEA_STARTUP_MODE_DEFAULT != meaGetStartupMode()) &&
                (MEA_STARTUP_MODE_MENU != meaGetStartupMode()))
            {
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
            }
            break;
        }
    case MEA_SIG_ME_GET_MSG_INFO_RSP:
        /* Got the file type of the originating message */
        if (NULL == sig->p_param)
        {
            /* The file type could not be handled ... exit */
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MAME_4C72BD91F0420DA24124155E6FBD1291, "(%s) (%d) failed to get the file type!\n", __FILE__, 
                __LINE__));
            (void)meaShowDialog(MEA_GET_STR_ID(
                MEA_STR_ID_FAILED_TO_GET_MESSAGE_INFO), MEA_DIALOG_ERROR);
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            break;
        }
        inst->origFileType = 
            ((MmsMessageFolderInfo *)sig->p_param)->suffix;
        MEA_FREE(sig->p_param);
        /* Get message in next state */
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_MR_START);
        break;
        
    /*
     *	MR (Message Reader) INTERACTION
     */
    case MEA_SIG_ME_MR_START:
        /*
         *	Start reading of originating message from disk or content router, 
         *  or setup a fresh new one
         */
        if (!handleStartupMode(inst, MEA_ME_FSM, MEA_SIG_ME_MR_DONE))
        {
            /* Failed to start-up, clean-up and exit */
            deleteInstance();
            /* If messages can not be created then something must be terribly
             * wrong, restart!
             */
#ifdef __UNIFIED_MSG_SUPPORT__
            (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
#else
            meaSignalDelete(sig);
            MEA_TERMINATE;
#endif
        }
#ifdef WAP_SUPPORT
	    if (meaGetStartupMode() == MEA_STARTUP_MODE_NEW)
	        HDIa_widgetExtCloseTransitionAnimation();
#endif
        break;
        
    case MEA_SIG_ME_MR_DONE:
        /* Message has been read from disk */
        meaFreeMessage(&inst->theMessage);
        handleReturnFromMr(inst, (MeaMrResult)sig->u_param1, 
            (MeaMessage *)sig->p_param,(int)sig->u_param2);
        break;

    /*
     *	SAVING and SENDING
     */
    case MEA_SIG_ME_SAVE:
    case MEA_SIG_ME_SAVE_AS_TEMPLATE:
    case MEA_SIG_ME_SEND:
	case MEA_SIG_ME_SAVE_AND_SEND:
    case MEA_SIG_ME_SAVE_PREVIEW:
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    case MEA_SIG_ME_SAVE_AS_DEF_TEMPLATE:
#endif
        /*
         *	Save/send requests are generated by navigation menus,
         *  or requesting FSMs. requesting FSMs want return signals, menus no.
         *  u_param1/2 will be zero when _UU isn't used to send this signal, 
         *  which is ok! (MEA_NOTUSED_FSM)
         */
        if (MEA_NOTUSED_FSM == inst->mcrFsm)
        {
            /* Only set if not already set */
            inst->mcrFsm = (MeaStateMachine)sig->u_param1; 
            inst->mcrSig = (int)sig->u_param2;
        } /* if */
        
        if (IsReachMEAMaxNumofMsg(MMS_MAX_NO_OF_MSG-1))
        {
        #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            if (sig->type == MEA_SIG_ME_SAVE_AS_DEF_TEMPLATE)
            {
                HDIa_widgetExtCloseTransitionAnimation();
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MAX_NUMBER_OF_MSG), MEA_DIALOG_ERROR);
                meaMeAddDefTempContentFail(MEA_MH_DEF_TEMP_RESULT_MAX_NUM);
                (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            }
            else if (sig->type == MEA_SIG_ME_SAVE_AS_TEMPLATE &&
                inst->mode == MEA_ME_STARTUP_SAVE_AS_TEMPLATE)
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MAX_NUMBER_OF_MSG), MEA_DIALOG_ERROR);
                (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            }
            else
        #endif
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MAX_NUMBER_OF_MSG), MEA_DIALOG_ERROR);
            break;
        }

        if ((U64)msm_get_disk_free_space(WAP_STORAGE_MMS) < (U64)meaCalculateMsgSize
            (inst->theMessage->smilInfo, inst->theMessage->msgProperties))
        {
        #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            if (sig->type == MEA_SIG_ME_SAVE_AS_DEF_TEMPLATE)
            {
                meaMeAddDefTempContentFail(MEA_MH_DEF_TEMP_RESULT_MEM_FULL);
            }
            else if (MEA_ME_STARTUP_SAVE_AS_TEMPLATE == inst->mode)
            {
                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_STORAGE_FULL), MEA_DIALOG_ERROR);
                (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            }
            else
        #endif
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_STORAGE_FULL), MEA_DIALOG_ERROR);
            if(sig->type != MEA_SIG_ME_SAVE_PREVIEW)
            {
                (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            }
            break;
        }

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        if (MEA_SIG_ME_SAVE_AS_DEF_TEMPLATE != sig->type &&
            MEA_SIG_ME_SAVE != sig->type)
#else
        if (MEA_SIG_ME_SAVE != sig->type)
#endif
        {
            /* Properties doesn't have to be OK for previewing */
            if (MEA_IS_PROP_CHECK_NEEDED(sig->type) && 
                (!meaCheckPropFields(*inst->theMessage->msgProperties)))
            {
                reportOrClose(FALSE, &inst->mcrFsm, &inst->mcrSig);
                break;
            }
        }

        inst->sendFlg = ((MEA_SIG_ME_SEND == sig->type) || (MEA_SIG_ME_SAVE_AND_SEND == sig->type));
  #ifdef WAP_SUPPORT
        if(inst->mode == MEA_ME_STARTUP_APPEND_SIGNATURE && inst->theMessage->msgType != MEA_MR_SMIL)  /* send mixed mms in Drafts, no need to recreate the MMS, just send out */
        {
            meaSendMessage(MEA_MH_FSM, MEA_SIG_MH_SEND_RESPONSE, inst->origMsgId, TRUE);
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            break;
        }
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        else if(inst->mode != MEA_ME_STARTUP_FORWARD &&
            inst->mode != MEA_ME_STARTUP_CREATE_DEF_TEMP)
    #else
        else if(inst->mode != MEA_ME_STARTUP_FORWARD)  /* smilInfo is empty in Forward mode */
    #endif
        {
            if (meaMeAddSignature() != TRUE)
            {
				inst->mcrFsm = MEA_NOTUSED_FSM;
                if( inst->mode == MEA_ME_STARTUP_APPEND_SIGNATURE)
                    deleteInstance();
                break;
            }
        }
  #endif /* WAP_SUPPORT */

        /* Start message creation FSM */
        switch(sig->type)
        {
        case MEA_SIG_ME_SAVE_AS_TEMPLATE:
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            folder = MMS_USRDEF_TEMPLATES;
#else
            folder = MMS_TEMPLATES;  /* save in template folder */
#endif
            break;

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    case MEA_SIG_ME_SAVE_AS_DEF_TEMPLATE:
        folder = MMS_TEMPLATES;
        break;
#endif

        case MEA_SIG_ME_SEND:
			meaSaveOnSendSet(FALSE);
            folder = MMS_OUTBOX;
			break;
		case MEA_SIG_ME_SAVE_AND_SEND:
			meaSaveOnSendSet(TRUE);
#ifdef __UNIFIED_MSG_SUPPORT__
            folder = MMS_SENT;  /* save in sent folder */
#else
			folder = MMS_OUTBOX;
#endif
			break;
        case MEA_SIG_ME_SAVE:
            folder = MMS_DRAFTS;
            break;
        case MEA_SIG_ME_SAVE_PREVIEW:
            folder = MMS_HIDDEN;
            break;
        default:
            folder = MMS_DRAFTS;
            break;
        }

        { /* Delete the message or not? */
            MmsFolderType origFolder = fldrGetFolderId(inst->origMsgId);

#ifdef __UNIFIED_MSG_SUPPORT__
            if (origFolder == MMS_INBOX || origFolder == MMS_SENT
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                || origFolder == MMS_ARCHIVE
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
                )
            {
                inst->delOrigMsgFlg = FALSE;
            }
            else if ((sig->type == MEA_SIG_ME_SAVE_PREVIEW) || /* preview will be deleted in preview response */
                (sig->type == MEA_SIG_ME_SAVE_AS_TEMPLATE))
            {
                inst->delOrigMsgFlg = FALSE;
            }
            else
            {
                inst->delOrigMsgFlg = (MEA_ME_STARTUP_EDIT == inst->mode) &&
                    (!(MEA_ME_STARTUP_FROM_TEMPLATE == inst->mode));
            }

            deleteMsg = inst->delOrigMsgFlg;
#else
        if (MMS_SUFFIX_MSG == inst->origFileType)
        {
            /* Do not delete retrive.conf PDU's */
            deleteMsg = FALSE;
        }
        else
        {
            /* Do not delete the originating message if it is a template or if
               it is a preview operation */
            if ((sig->type == MEA_SIG_ME_SAVE_PREVIEW) || //preview will be deleted in preview response
                (sig->type == MEA_SIG_ME_SAVE_AS_TEMPLATE) ||
            #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
                (sig->type == MEA_SIG_ME_SAVE_AS_DEF_TEMPLATE) ||
            #endif
                    ((sig->type == MEA_SIG_ME_SAVE && ((origFolder == MMS_DRAFTS) ||
                        origFolder == MMS_OUTBOX) || origFolder == MMS_SENT)) ||
                ((sig->type == MEA_SIG_ME_SEND || sig->type == MEA_SIG_ME_SAVE_AND_SEND) && 
                    (origFolder == MMS_DRAFTS || origFolder == MMS_SENT)))
            {
                deleteMsg = FALSE;
            }
            else
            {
                deleteMsg = (MEA_ME_STARTUP_EDIT == inst->mode) &&
                    (!(MEA_ME_STARTUP_FROM_TEMPLATE == inst->mode));
            }
        }
#endif
        }
        /* Create the message */
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        meaCreateMessage(MEA_ME_FSM, MEA_SIG_ME_SAVE_DONE, inst->theMessage, 
            inst->origMsgId, deleteMsg, folder, inst->origFileType,
            (MEA_ME_STARTUP_FORWARD == inst->mode || 
             MEA_ME_STARTUP_SAVE_AS_TEMPLATE == inst->mode) ? TRUE: FALSE);
    #else
        meaCreateMessage(MEA_ME_FSM, MEA_SIG_ME_SAVE_DONE, inst->theMessage, 
            inst->origMsgId, deleteMsg, folder, inst->origFileType,
            (MEA_ME_STARTUP_FORWARD == inst->mode) ? TRUE: FALSE);
    #endif
        break;
        
    case MEA_SIG_ME_SAVE_DONE:
        if (MEA_MCR_TOO_MANY_MSG == (MeaMcrResult)sig->u_param1)
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MAX_NUMBER_OF_MSG), 
                MEA_DIALOG_ERROR);

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            if (MEA_ME_STARTUP_CREATE_DEF_TEMP == inst->mode)
                meaMeAddDefTempContentFail(MEA_MH_DEF_TEMP_RESULT_MAX_NUM);
            else if (MEA_ME_STARTUP_SAVE_AS_TEMPLATE == inst->mode)
                (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
#endif
            break;
        }
        else if(MEA_MCR_STORAGE_FULL == (MeaMcrResult)sig->u_param1)
        {
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            if (MEA_ME_STARTUP_CREATE_DEF_TEMP == inst->mode)
            {
                meaMeAddDefTempContentFail(MEA_MH_DEF_TEMP_RESULT_MEM_FULL);
                break;
            }
            else if (MEA_ME_STARTUP_SAVE_AS_TEMPLATE == inst->mode)
            {
                (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            }
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_STORAGE_FULL), 
                MEA_DIALOG_ERROR);
#else
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_STORAGE_FULL), 
                MEA_DIALOG_ERROR);
#endif
            break;
        }
        if (MEA_MCR_OK != (MeaMcrResult)sig->u_param1)
        {
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            if (MEA_ME_STARTUP_CREATE_DEF_TEMP == inst->mode)
            {
                meaMeAddDefTempContentFail(MEA_MH_DEF_TEMP_RESULT_FAILED);
                break;
            }
            else if (MEA_ME_STARTUP_SAVE_AS_TEMPLATE == inst->mode)
            {
                (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            }
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_SAVE), 
                MEA_DIALOG_ERROR);
#else
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_SAVE), 
                MEA_DIALOG_ERROR);
#endif
            break;
        }
        else
        {
#ifdef __UNIFIED_MSG_SUPPORT__
            if(inst->mode == MEA_ME_STARTUP_NEW_SMIL)
            {
                mmi_um_skip_write_menu(TRUE);
            }
            
            /* delayed orig msg deletion after save/send done */
            if(!(inst->sendFlg) && inst->delOrigMsgFlg == TRUE)  /* save */
            {
                meaDeleteMsgSilent(inst->origMsgId);
            }
#endif
            if ((NULL != inst) && (NULL != inst->theMessage))
            {
                inst->theMessage->msgId    = (MmsMsgId)sig->u_param2;
                inst->theMessage->fileType = (MmsFileType)sig->i_param;
            }
        }

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        if (MEA_ME_STARTUP_SAVE_AS_TEMPLATE == inst->mode)
        {
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_SAVE_AS_TEMPLATE_FINISHED);
        }
        else if (MEA_ME_STARTUP_CREATE_DEF_TEMP == inst->mode)
        {
            (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_CREATE_DEF_TEMP_FINISHED,
                MEA_MH_DEF_TEMP_RESULT_OK);
        }
#endif

        /* On error and if done, report and break */
        /*lint -e{613} */
        if ( !(inst->sendFlg) || MEA_MCR_OK != (MeaMcrResult)sig->u_param1)
        {
            /*lint -e{613} */
            reportOrClose((MEA_MCR_OK == (MeaMcrResult)sig->u_param1), &inst->mcrFsm, &inst->mcrSig);
            break;
        }

#ifdef WAP_SUPPORT
        if (MEA_ME_STARTUP_APPEND_SIGNATURE == inst->mode)
        {
#ifdef __UNIFIED_MSG_SUPPORT__
            if(inst->delOrigMsgFlg)
            {
                meaSendEditedMessage(MEA_ME_FSM, MEA_SIG_ME_SEND_WITH_SIGN_DONE, inst->theMessage->msgId, inst->origMsgId, FALSE);
            }
            else
#endif
                meaSendMessage(MEA_ME_FSM, MEA_SIG_ME_SEND_WITH_SIGN_DONE, inst->theMessage->msgId, FALSE);
        }
        else
#endif
        {
#ifdef __UNIFIED_MSG_SUPPORT__
            if(inst->delOrigMsgFlg)
            {
                meaSendEditedMessage(MEA_ME_FSM, MEA_SIG_ME_SEND_DONE, inst->theMessage->msgId, inst->origMsgId, FALSE);
            }
            else
#endif
                meaSendMessage(MEA_ME_FSM, MEA_SIG_ME_SEND_DONE, inst->theMessage->msgId, FALSE);
        }
        break;
        
#ifdef WAP_SUPPORT
    case MEA_SIG_ME_SEND_WITH_SIGN_DONE:
        if (sig->p_param)
        {
            meaShowSendDialogWithText((MeaSendResult)sig->u_param1, (char *)sig->p_param);
            MEA_FREE(sig->p_param);
            sig->p_param = NULL;
        }
        else
        {
            meaShowSendDialog((MeaSendResult)sig->u_param1, MEA_NOTUSED_FSM, 0);
        }
//#ifdef __UNIFIED_MSG_SUPPORT__
        if (MEA_SEND_CANCELLED == (MeaSendResult)sig->u_param1)  /* only user cancel return to editor */
//#else
//        if (MEA_SEND_CANCELLED == (MeaSendResult)sig->u_param1 || MEA_SEND_FAILED_COMM == (MeaSendResult)sig->u_param1)
//#endif
        {
            meaDeleteMsgSilent(inst->theMessage->msgId);
        }
#ifdef __UNIFIED_MSG_SUPPORT__
        else if(inst->delOrigMsgFlg == TRUE)
        {
            meaDeleteMsgSilent(inst->origMsgId);
        }
#else
        else
        {
            meaDeleteMsgSilent(inst->origMsgId);
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
        }
#endif

        /* Always update the current folder after a send operations since
           the messge can have moved to outbox */
        (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
            MEA_FOLDER_NONE);
        deleteInstance();
		break;
#endif /* WAP_SUPPORT */

    case MEA_SIG_ME_SEND_DONE:
        if (sig->p_param)
        {
            meaShowSendDialogWithText((MeaSendResult)sig->u_param1, (char *)sig->p_param);
            MEA_FREE(sig->p_param);
            sig->p_param = NULL;
        }
        else
        {
            meaShowSendDialog((MeaSendResult)sig->u_param1, MEA_NOTUSED_FSM, 0);
        }
#ifdef __UNIFIED_MSG_SUPPORT__
        if (MEA_SEND_CANCELLED == (MeaSendResult)sig->u_param1 || MEA_SEND_FAILED_SETTING == (MeaSendResult)sig->u_param1)  /* return to editor */
#else
        if (MEA_SEND_CANCELLED == (MeaSendResult)sig->u_param1 || MEA_SEND_FAILED_SETTING == (MeaSendResult)sig->u_param1
            || MEA_SEND_FAILED_COMM == (MeaSendResult)sig->u_param1)
#endif
        {
            meaDeleteMsgSilent(inst->theMessage->msgId);
        }
#ifdef __UNIFIED_MSG_SUPPORT__
        else if(inst->delOrigMsgFlg == TRUE)
        {
            meaDeleteMsgSilent(inst->origMsgId);
        }
#endif
        
#ifdef WAP_SUPPORT
        if (MEA_SEND_OK != (MeaSendResult)sig->u_param1 && 
	    MEA_SEND_TERMINATE_SILENT != (MeaSendResult)sig->u_param1 && meaConfGetAutoSignature()) //signature is on
        {
            if(inst->mode != MEA_ME_STARTUP_FORWARD && inst->theMessage->msgType == MEA_MR_SMIL)  /* signature not attached in Forward mode */
                meaDeleteSignatureSlide(inst->theMessage->smilInfo);
        }
#endif /* WAP_SUPPORT */

        /* Always update the current folder after a send operations since
           the MMS Service can have moved to messge to outbox or sent */
        (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
            MEA_FOLDER_NONE);

#ifdef __UNIFIED_MSG_SUPPORT__
        reportOrClose((MeaSendResult)MEA_SEND_CANCELLED != sig->u_param1, &inst->mcrFsm, &inst->mcrSig);
/*
        reportOrClose((MeaSendResult)(MEA_SEND_OK != sig->u_param1 && MEA_SEND_TERMINATE_SILENT != sig->u_param1), 
            &inst->mcrFsm, &inst->mcrSig);*/
#else
        reportOrClose((MeaSendResult)MEA_SEND_CANCELLED != sig->u_param1, 
            &inst->mcrFsm, &inst->mcrSig);
#endif
        break;                
        
    /*
     *	NAVIGATION MENU 
     */
    case MEA_SIG_ME_NAV_ACTIVATE:
        if (! meaMeCreateNavMenu((void*)meaMeNavMenuItems))
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        } /* if */
        break;

    case MEA_SIG_ME_NAV_DEACTIVATE:
        meaMeDeleteNavMenu();
        break;

    /*
     *	CONTENT EDITING
     */
    case MEA_SIG_ME_EDIT_CONTENT:
        if (MEA_ME_IS_NEW_SMIL_MSG(inst->mode) ||
            ((NULL != inst->theMessage) && 
            (MEA_MR_SMIL == inst->theMessage->msgType)))
        {
            (void)MEA_SIGNAL_SENDTO_P(MEA_SE_FSM, MEA_SIG_SE_ACTIVATE, inst);
        }
        else if ((MEA_MR_PLAIN_TEXT == inst->theMessage->msgType) 
            || (MEA_MR_MULTIPART_MIXED == inst->theMessage->msgType))
        {
#ifdef __UNIFIED_MSG_SUPPORT__
            (void)MEA_SIGNAL_SENDTO_P(MEA_SE_FSM, MEA_SIG_SE_ACTIVATE, inst);
#else
            /* Activate the right editor - SMIL or Multipart/Mixed */
            (void)MEA_SIGNAL_SENDTO_P(MEA_MME_FSM, MEA_SIG_MME_ACTIVATE,
                inst->theMessage);
#endif
        }     
        else
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);            
        }
        break;
        
    /*
     *	PROPERTY EDITING
     */
    case MEA_SIG_ME_EDIT_PROPERTIES:
        if (NULL != inst->theMessage->msgProperties)
        {
            (void)MEA_SIGNAL_SENDTO_P(MEA_CONFIG_FSM, 
                MEA_SIG_CONF_ACTIVATE_SETTINGS, 
                inst->theMessage->msgProperties);
        }
        else
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        } /* if */
        break;

    case MEA_SIG_ME_SAVE_CONFIRM:
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_SAVE);
        else
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        break;
    case MEA_SIG_ME_MENU_SAVE_DONE:
    case MEA_SIG_ME_MENU_SAVE_AS_TEMPLATE_DONE:
        if (TRUE == sig->u_param1)
        {    
            /*
             *	All done, let's shut down. 
             *  Any error messages will have been shown by others. 
             */
            (void)meaShowDialog(MEA_GET_STR_ID(BRA_STR_ID_SAVED), 
                MEA_DIALOG_PROMPT_DONE);
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        } /* if */                
        break;

    case MEA_SIG_ME_PROP_NEXT:
        if (MEA_ME_STARTUP_FORWARD == inst->mode)
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_NAV_ACTIVATE);
        }
        else
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_EDIT_CONTENT);
        }
        break;

    case MEA_SIG_ME_PROP_BACK:
        if (meaUiMeIsPropertyViewActive())
        {
#ifdef WAP_SUPPORT
            (void)meaShowConfirmDialog(BRA_STR_ID_SAVE_ASK, NULL, 
                MEA_ME_FSM, MEA_SIG_ME_SAVE_CONFIRM, 0);
#endif /* WAP_SUPPORT */
        } /* if */
        break;

    case MEA_SIG_ME_MENU_SEND_DONE:
#ifndef WAP_SUPPORT
    case MEA_SIG_ME_MENU_SAVE_DONE:
    case MEA_SIG_ME_MENU_SAVE_AS_TEMPLATE_DONE:
#endif /* ~WAP_SUPPORT */
    case MEA_SIG_ME_PROP_SEND_DONE:     
    case MEA_SIG_ME_PROP_SAVE_DONE:
    case MEA_SIG_ME_PROP_SAVE_AS_TEMPLATE_DONE:        
        if (TRUE == sig->u_param1)
        {    
            /*
             *	All done, let's shut down. 
             *  Any error messages will have been shown by others. 
             */
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        } /* if */                
        break;

    case MEA_SIG_ME_ADDR_INPUT_DEACTIVATE:
        meaMeDeleteAddrInputView();
        break;

    case MEA_SIG_ME_ADD_RECEPIENTS:
        switch(sig->u_param1)
        {
        case MEA_ME_TO:
            setAddr(&(inst->theMessage->msgProperties->to),
                (MeaAddrItem *)sig->p_param);
#ifdef WAP_SUPPORT
            item = inst->theMessage->msgProperties->to;            
#endif /* WAP_SUPPORT */
            break;
        case MEA_ME_CC:
            setAddr(&(inst->theMessage->msgProperties->cc),
                (MeaAddrItem *)sig->p_param);
#ifdef WAP_SUPPORT
            item = inst->theMessage->msgProperties->cc;
#endif /* WAP_SUPPORT */
            break;
        case MEA_ME_BCC:
            setAddr(&(inst->theMessage->msgProperties->bcc),
                (MeaAddrItem *)sig->p_param);
#ifdef WAP_SUPPORT
            item = inst->theMessage->msgProperties->bcc;
#endif /* WAP_SUPPORT */
            break;
        }
#ifdef WAP_SUPPORT
        //if more than 2 entries
        if (!meaMeUpdateAddrListViewForAdd(item))
            meaMeDeleteAddrListView();
#endif /* WAP_SUPPORT */
        /* Update the property view */
        if (!meaMeSetPropertyValues(inst->theMessage->msgProperties))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(
                MEA_STR_ID_FAILED_TO_OPEN_WINDOW), MEA_DIALOG_ERROR);
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MAME_FA6A498543205CF8BC63FF697417C426, "(%s) (%d) failed to display message properties\n", 
                __FILE__, __LINE__));
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        }
        
        meaMeUpdateEditContent(inst->theMessage->smilInfo, inst->theMessage->msgProperties, inst->mode);
        break;

    case MEA_SIG_ME_CHANGE_RECEPIENT:
        switch(sig->u_param1)
        {
        case MEA_ME_TO:
            meaChangeAddr(inst->theMessage->msgProperties->to, 
                (MeaAddrItem *)sig->p_param, sig->u_param2);
#ifdef WAP_SUPPORT
            item = inst->theMessage->msgProperties->to;            
#endif /* WAP_SUPPORT */
            break;
        case MEA_ME_CC:
            meaChangeAddr(inst->theMessage->msgProperties->cc,
                (MeaAddrItem *)sig->p_param, sig->u_param2);
#ifdef WAP_SUPPORT
            item = inst->theMessage->msgProperties->cc;
#endif /* WAP_SUPPORT */
            break;
        case MEA_ME_BCC:
            meaChangeAddr(inst->theMessage->msgProperties->bcc,
                (MeaAddrItem *)sig->p_param, sig->u_param2);
#ifdef WAP_SUPPORT
            item = inst->theMessage->msgProperties->bcc;
#endif /* WAP_SUPPORT */
            break;
        }
#ifdef WAP_SUPPORT
        if (!meaMeUpdateAddrListViewForEdit(item,(unsigned int)sig->u_param2))
            meaMeDeleteAddrListView();
#endif /* WAP_SUPPORT */
        /* Update the */
        if (!meaMeSetPropertyValues(inst->theMessage->msgProperties))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(
                MEA_STR_ID_FAILED_TO_OPEN_WINDOW), MEA_DIALOG_ERROR);
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MAME_FA6A498543205CF8BC63FF697417C426, "(%s) (%d) failed to display message properties\n", 
                __FILE__, __LINE__));
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        }

        meaMeUpdateEditContent(inst->theMessage->smilInfo, inst->theMessage->msgProperties, inst->mode);
        break;
        
    case MEA_SIG_ME_LOOKUP_RSP:
        if ((NULL != inst) && 
            (NULL != inst->theMessage) && 
            (NULL != inst->theMessage->msgProperties) && 
            ((NULL != inst->theMessage->msgProperties->to) || 
             (NULL != inst->theMessage->msgProperties->cc) ||
             (NULL != inst->theMessage->msgProperties->bcc)))            
        {
            meaAddrItemMerge(inst->theMessage->msgProperties->to, 
                sig->p_param);
            meaAddrItemMerge(inst->theMessage->msgProperties->cc, 
                sig->p_param);
            meaAddrItemMerge(inst->theMessage->msgProperties->bcc,
                sig->p_param);
            /* Update the message properties */
            if (!meaMeSetPropertyValues(inst->theMessage->msgProperties))
            {
                (void)meaShowDialog(MEA_GET_STR_ID(
                    MEA_STR_ID_FAILED_TO_OPEN_WINDOW), MEA_DIALOG_ERROR);
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                    MAME_FA6A498543205CF8BC63FF697417C426, "(%s) (%d) failed to display message properties\n", 
                    __FILE__, __LINE__));
                (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            }
        }
        if (NULL != sig->p_param)
        {
            tmpAddrItem = (MeaAddrItem *)sig->p_param;
            meaAddrListFree(&tmpAddrItem);
        }
        break;

    case MEA_SIG_ME_ADDR_LIST_DEACTIVATE:
        meaMeDeleteAddrListView();
        break;

    case MEA_SIG_ME_ADDR_LIST_MENU_ACTIVATE:
        if (!meaMeCreateAddrListMenu())
        {
            meaMeDeleteAddrListMenu();
        }
        break;

    case MEA_SIG_ME_ADDR_LIST_MENU_DEACTIVATE:
        meaMeDeleteAddrListMenu();
        break;

    case MEA_SIG_ME_DELETE_ADDR_ITEM:
        switch(sig->u_param1)
        {
        case MEA_ME_TO:
            meaAddrItemDelete(&inst->theMessage->msgProperties->to, sig->u_param2);
            item = inst->theMessage->msgProperties->to;
            break;
        case MEA_ME_CC:
            meaAddrItemDelete(&inst->theMessage->msgProperties->cc, sig->u_param2);
            item = inst->theMessage->msgProperties->cc;
            break;
        case MEA_ME_BCC:
            meaAddrItemDelete(&inst->theMessage->msgProperties->bcc, sig->u_param2);
            item = inst->theMessage->msgProperties->bcc;
            break;
        }
        if (!meaMeUpdateAddrListView(item))
        {
            meaMeDeleteAddrListView();
        }
        if (!meaMeSetPropertyValues(inst->theMessage->msgProperties))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(
                MEA_STR_ID_FAILED_TO_OPEN_WINDOW), MEA_DIALOG_ERROR);
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
        }

        meaMeUpdateEditContent(inst->theMessage->smilInfo, inst->theMessage->msgProperties, inst->mode);
        break;

    case MEA_SIG_ME_REMOVE_UNRESTRICTED_OBJECT:
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
        {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            wap_send_mmi_mms_start_uc_req(MMA_MODE_EDIT, inst->theMessage->msgId);
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
#else
            meaMeRemoveUnrestrictedObj(inst->theMessage->smilInfo);
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_CREATE_PROP_VIEW);
#endif
        }
        else
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
/*            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_RESTRICTED_MODE_FAIL_TO_EDIT), MEA_DIALOG_ERROR);*/
        }
        break;

#ifdef __UNIFIED_COMPOSER_SUPPORT__        
    case MEA_SIG_ME_REMOVE_INVALID_OBJECT:
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
        {
            wap_send_mmi_mms_start_uc_req(MMA_MODE_EDIT, inst->theMessage->msgId);
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            meaContentValidFlag = TRUE;
        }
        break;
#endif    
    case MEA_SIG_ME_CREATE_PROP_VIEW:
        if (!meaMeCreatePropView(inst->theMessage->msgProperties, inst->mode))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAME_C339F59A049C8D3DE7F766C87349F83F, "(%s) (%d) failed to create message property form!\n", 
                __FILE__, __LINE__));
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
            return;
        }
        (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_PROP_VIEW_SHOW_POPUP,0,0);
        break;

    case MEA_SIG_ME_PROP_VIEW_SHOW_POPUP:
    {
        MSF_INT8 state = sig->u_param2;

        switch(state)
        {
            /* if invalid object remove, popup*/
            case 0:
            {
                if(meaContentValidFlag == FALSE)
                {
                    if(inst->mode != MEA_ME_STARTUP_FORWARD)
                    {
                        (void)meaShowDialogWithConfirm(MsfWarning, MEA_STR_ID_OK, 0, MEA_STR_ID_REMOVE_INVALID_OBJECT, 
                                        MEA_ME_FSM, MEA_SIG_ME_PROP_VIEW_SHOW_POPUP, 1);     
                    }
                    meaContentValidFlag = TRUE;
                    break;
                }
                else
                    state = 1;

            }

            /* if there is attachment removed, popup*/
            case 1:
            {
                if(inst->delOrigMsgAttachmentFlg == TRUE)
                {
                    (void)meaShowDialogWithConfirm(MsfWarning, MEA_STR_ID_OK, 0, MEA_STR_ID_ATTACHMENT_REMOVED, 
                                    MEA_ME_FSM, MEA_SIG_ME_PROP_VIEW_SHOW_POPUP, 2);     
                    break;
                }
                else
                    state = 2;
            }

            /* removed invalid number */
            case 2:
            {
                if( meaMeGetNumberValidFlag() == TRUE) /*there is a invalid number removed*/
                {
                    (void)meaShowDialogWithConfirm(MsfWarning, MEA_STR_ID_OK, 0, MEA_STR_ID_REMOVE_INVALID_NUMBER, 
                                    MEA_ME_FSM, MEA_SIG_ME_PROP_VIEW_SHOW_POPUP, 3);     
                    break;
                }
                else
                    state = 3;

            }

            case 3:
            {
                if (needRRConfirm == TRUE)
                {
                    needRRConfirm = FALSE;
                    (void)meaShowConfirmDialog(MEA_STR_ID_READ_REPORT_SEND,
                                NULL, MEA_MV_FSM, MEA_SIG_MV_SEND_READ_REPORT, 0);
                    break;
                }
                
            }
            default:
                break;
        }
    }
    break;

    case MEA_SIG_ME_CREATE_PROP_RR_CONFIRM:
#if MEA_CFG_REQ_RR_AFTER_READ_FINISH == 1
        needRRConfirm = TRUE;        
#endif /* MEA_CFG_REQ_RR_AFTER_READ_FINISH == 1*/

        break;

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    case MEA_SIG_ME_ADD_DEFAULT_TEMP_CONT:
        if (meaMeAddDefTempContent() == FALSE)
        {
            meaMeAddDefTempContentFail(MEA_MH_DEF_TEMP_RESULT_FAILED);
        }
        else
        {
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_SAVE_AS_DEF_TEMPLATE);
        }
        break;
#endif

    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAME_3536C450CE01DCCD464B16024B9342F8, "ME: Erroneous signal received (%d).\n", sig->type));
        break;
    }
    /* Remove signal data */
    meaSignalDelete(sig);
}

#ifdef WAP_SUPPORT
void meaMeRegisterExitCallback(func_ptr funcPtr, void *param)
{
    if (exitCallback.func)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAME_CEFEEDB235E199AEF52731C86D8AACB8, "ME: exitCallback not NULL (0x%x).\n", (unsigned)exitCallback.func));
    }
    memset(&exitCallback, 0x00, sizeof(struct cbFunc));
    exitCallback.func = funcPtr;
    exitCallback.param = param;
}

/*!
 * \brief Check if the signature (the last) slide exist
 *
 * \param smilInfo All slides.
 * \return TRUE or FALSE
 *****************************************************************************/
static MSF_BOOL meaIsSignatureSlideExist(MeaSmilInfo *smilInfo)
{
    if (smilInfo->slides != NULL)
    {
		int i;
        MeaSmilSlide *delSlide = smilInfo->slides;

        while (NULL != delSlide->next)
        {
            delSlide = delSlide->next;
        }

        /* Check if the last slide is signature */
        for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)
        {
            if ((NULL != delSlide->objects[i]) && (NULL != delSlide->objects[i]->object))
            {
                if (delSlide->objects[i]->object->content.type == MEA_MEDIA_TYPE_TEXT_PLAIN && msf_cmmn_strcmp_nc(delSlide->objects[i]->object->name, MEA_SIG_FILE_NAME) == 0)
                {
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

/*!
 * \brief Adds a new slide to the list of slides after the last one,
 *          and updates the current-pointer and slide count.
 * \param smilInfo The current SMIL presentation.
 * \return The new slide, or NULL.
 *****************************************************************************/
static MSF_BOOL meaInsertSignatureSlide(MeaSmilInfo *smilInfo)//, unsigned char* buffer)
{
    MeaSmilSlide *newSlide;
    MeaSmilSlide *origCurrentSlide = smilInfo->currentSlide;

	char * fileName;
	int openMode = MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING;
    int fileHandle;
	long result;
	unsigned char *data = NULL;
	
    if(meaIsSignatureSlideExist(smilInfo) == TRUE)
    {
        return TRUE;
    }
	
	if ((fileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, MEA_SIG_TEXT_FILE, openMode, 0)) > 0)
	{
		data = MEA_ALLOC(128*3+1);
		if (!data)
		{
		    MSF_FILE_CLOSE(fileHandle);
			return FALSE;
		}
	    result = MSF_FILE_READ(fileHandle, data, 128*3+1);
		MSF_FILE_CLOSE(fileHandle);
		if (result < 0)
		    return FALSE;
	}
    newSlide = (MeaSmilSlide*)MEA_ALLOC(sizeof(MeaSmilSlide));
    memset(newSlide, 0, sizeof(MeaSmilSlide));
#ifndef WAP_SUPPORT		/* MTK support empty slide */
    if (NULL != smilInfo->currentSlide && !smilInfo->currentSlide->objects[0])
	{
		//delete the empty slide
		meaDeleteAllEmptySlides(smilInfo);
		origCurrentSlide = NULL;
	}
#endif	/* WAP_SUPPORT */
    if (NULL != smilInfo->currentSlide)
    {
        while (NULL!=smilInfo->currentSlide->next)
        {
        	smilInfo->currentSlide = smilInfo->currentSlide->next;
        }
        smilInfo->currentSlide->next = newSlide;
    }
    else
    {
        smilInfo->slides = newSlide;
        newSlide->next = NULL;
    }
    smilInfo->noOfSlides++;
    smilInfo->currentSlide = newSlide;
    /* Set the default duration */
    meaSetDuration(smilInfo, (unsigned)meaGetConfig()->slideDuration * 1000);
    if (NULL == (fileName = msf_cmmn_strdup(MSF_MODID_MEA, MEA_SIG_FILE_NAME)))
    {
        return FALSE;
    }
#ifdef __DRM_SUPPORT__ 
	meaSetSlideMo(smilInfo, MEA_MEDIA_TYPE_TEXT_PLAIN, MEA_MEDIA_TYPE_UNKNOWN, NULL, data, strlen((char *)data)+1, 
	              fileName, 0);
#else
	meaSetSlideMo(smilInfo, MEA_MEDIA_TYPE_TEXT_PLAIN, NULL, data, strlen((char *)data)+1, fileName, 0);
#endif
	smilInfo->currentSlide = origCurrentSlide;
    return TRUE;
} /* meaInsertSignatureSlide */

/*!
 * \brief Deletes the signature (the last) slide
 *
 * \param smilInfo All slides.
 * \return TRUE on ok or FALSE on error
 *****************************************************************************/
static MSF_BOOL meaDeleteSignatureSlide(MeaSmilInfo *smilInfo)
{
    MSF_BOOL isSigExisted = FALSE;
    MeaSmilSlide *delSlide = smilInfo->slides;
    MeaSmilSlide *prev = NULL;
    unsigned int i;

    /* Check that any slide exists */
    if (smilInfo->slides != NULL)
    {
        prev = smilInfo->slides;
        while (NULL != prev->next && NULL != prev->next->next)  /* find the last 2nd slide */
        {
            prev = prev->next;
        }

        if (prev && prev->next)  /* signature can only be the last slide */
        {
            delSlide = prev->next;
        }

        /* Check if the last slide is signature */
        for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)
        {
            if ((NULL != delSlide->objects[i]) && (NULL != delSlide->objects[i]->object))
            {
                if (delSlide->objects[i]->object->content.type == MEA_MEDIA_TYPE_TEXT_PLAIN && msf_cmmn_strcmp_nc(delSlide->objects[i]->object->name, MEA_SIG_FILE_NAME) == 0)
                {
                    isSigExisted = TRUE;
                }
            }
        }

        /* Delete signature slide */
        if(isSigExisted)
        {
            for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)    /* Free all data in the slide */
            {
                if ((NULL != delSlide->objects[i]) && (NULL != delSlide->objects[i]->object))
                {
                    meaDeleteMo(&(smilInfo->mediaObjects), smilInfo->slides, delSlide->objects[i]->object);
                    MEA_FREE(delSlide->objects[i]);
                    delSlide->objects[i] = NULL;
                }
            }
            smilInfo->noOfSlides--;
            MEA_FREE(delSlide);

            if (prev && prev != delSlide) /* signature slide is not the only slide: adjust slide link list */
            {
                prev->next = NULL;
            }
            else
            {
                smilInfo->slides = NULL;
            }
        }
        return TRUE;
    }
    return FALSE;
} /* meaDeleteSignatureSlide */

static MSF_BOOL meaMeAddSignature(void)
{
    MeaMeInstance   *inst = curInst;
	MSF_INT32 sigFileSize;
    if (inst->sendFlg && meaConfGetAutoSignature() && //not send to others
		!(inst->mode == MEA_ME_STARTUP_FORWARD && meaGetCurrentFolder() != MEA_FOLDER_INBOX))
    {
        MeaSmilInfo *smilInfo = inst->theMessage->smilInfo;
		if ((sigFileSize = MSF_FILE_GETSIZE(MEA_SIG_TEXT_FILE)) < 0)
		{
            meaShowDialog(MEA_GET_STR_ID
				(MEA_STR_ID_AUTO_SIGNATURE_ERROR_SIZE_TOO_LARGE), MEA_DIALOG_ERROR);
            return FALSE;
		}
        
		if (meaGetSlideCount(smilInfo) > MEA_CFG_SLIDE_LIMIT - 1)
		{
            meaShowDialog(MEA_GET_STR_ID
				(MEA_STR_ID_AUTO_SIGNATURE_ERROR_TOO_MANY_SLIDES), MEA_DIALOG_ERROR);
            return FALSE;
		}
		else if (meaCalculateMsgSize(smilInfo, inst->theMessage->msgProperties) + sigFileSize
			 > MEA_CFG_MESSAGE_SIZE_MAXIMUM)
		{
            meaShowDialog(MEA_GET_STR_ID
				(MEA_STR_ID_AUTO_SIGNATURE_ERROR_SIZE_TOO_LARGE), MEA_DIALOG_ERROR);
            return FALSE;
		}
        else if (!meaInsertSignatureSlide(smilInfo))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAME_AB2EBC33CA0EA810A7F812C6DFF2C86E, "Insert Slide for signature failed\n"));
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), MEA_DIALOG_ERROR);
            return FALSE;
        }
        /* TO DO : NOT REMOVE ATTACHMENT WHILE EDIT A MESSAGE */
        if( inst->theMessage->unrefList != NULL)
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ATTACHMENT_REMOVED), MEA_DIALOG_WARNING);            
        }

    }
    return TRUE;
}
#endif /* WAP_SUPPORT */

/*!
 * \Clear FSM and Signal if user press "Back" in Done Option menu of MMS Message editor
 *****************************************************************************/
void meaMeClearNavMenuSignal(void)
{
    curInst->mcrFsm = MEA_NOTUSED_FSM;
    curInst->mcrSig = 0;
}

void meaMeAddressFilter(MeaAddrItem **list, MeaAddrType filter)
{
    MeaAddrItem *item = *list;
    MeaAddrItem *prev = NULL, *next = NULL;
    while(item)
    {
        next = item->next;
        if (item->addrType & filter)
        {
            prev = item;
        }
        else
        {
            if (prev != NULL)
            {
                prev->next = item->next;
            }
            else
            {
                *list = next;
            }
            item->next = NULL;
            meaAddrListFree(&item);
        }
        item = next;
    }
}

int meaMeAddressAlreadyExists(MeaAddrItem *current, MeaAddrItem *items)
{
    int index = 0;
    MSF_BOOL found = FALSE;
    while (current && !found)
    {
        if ((items->addrType == MEA_ADDR_TYPE_PLMN && current->addrType == MEA_ADDR_TYPE_PLMN))
        {
            if (mmi_phb_util_convert_number_to_int((unsigned char*)items->address) == 
             mmi_phb_util_convert_number_to_int((unsigned char*)current->address))
            {
                found = TRUE;
                break;
            }
        }
        else if (0 == msf_cmmn_strcmp_nc(items->address,current->address))
        {
                found = TRUE;
                break;
        }
        current = current->next;
        index ++;
    }
    return (found?index:-1);
}

MSF_BOOL meaMeIsHavingEmptySlide(void)
{
    MeaSmilSlide *theSlide = NULL;
    if (!curInst)
        return TRUE;

    theSlide = curInst->theMessage->smilInfo->slides;
    if (!theSlide)
        return TRUE;
    
    while (theSlide->next)
    {
        theSlide = theSlide->next;
        if (!theSlide->objects[0])
            return TRUE;
    }
    if (theSlide->objects[0])
        return FALSE;
    return TRUE;
}
/*!
 * \brief When write message done
 * \param strValue The string value
 *****************************************************************************/
MSF_BOOL meaMeSubjectUpdate(char *strValue)
{
    char **property = NULL;

    if ((NULL != curInst) &&
            (NULL != curInst->theMessage) &&
            (NULL != curInst->theMessage->msgProperties))
    {
        property = &(curInst->theMessage->msgProperties->subject);        
    } /* if */
    /* Free old property*/
    if (NULL != property)
    {
        MEA_FREE(*property);
        *property = NULL;
        *property = strValue;
    }

    return meaMeUpdateEditContent(curInst->theMessage->smilInfo, curInst->theMessage->msgProperties, curInst->mode);
}

unsigned int meaMeGetSlideCount(void)
{
//    if (curInst && curInst->theMessage->smilInfo->mediaObjects)
	if (curInst)		/* allow empty slide*/
        return meaGetSlideCount(curInst->theMessage->smilInfo);
    return 0;
}

unsigned int meaMeCalculateMsgSize(void)
{
    if (curInst && curInst->theMessage->smilInfo && curInst->theMessage->msgProperties)
        return meaCalculateMsgSize(curInst->theMessage->smilInfo, curInst->theMessage->msgProperties);
    return 0;
}

void meaDisplayInlineProperty(MeaMeProperty theProperty)
{
    int i;
    MeaInputItem item;
    MeaMeInstance *meInstance = curInst;
    MeaAddrItem *addr = NULL, *nowAddr = NULL;

    memset(&item, 0, sizeof(MeaInputItem));

    if ((NULL == meInstance) ||
        (NULL == meInstance->theMessage) ||
        (NULL == meInstance->theMessage->msgProperties))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAME_F1D239D8B0F78D7A41330A6051A774CC, "(%s) (%d) instance or data missing!\n", __FILE__, __LINE__));
        return /*FALSE*/;
    }
    /* Check which property that is active */
    switch(theProperty)
    {
    case MEA_ME_TO:
        addr = meInstance->theMessage->msgProperties->to;
        break;
    case MEA_ME_CC:
        addr = meInstance->theMessage->msgProperties->cc;
        break;
    case MEA_ME_BCC:
        addr = meInstance->theMessage->msgProperties->bcc;
        break;
    //case MEA_ME_SUBJECT: //handle by meaMeSubjectUpdate
    case MEA_ME_NONE:
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAME_1A86EEB0AE98E93DCC701760819E16F7, "(%s) (%d) erroneous property value!\n", __FILE__, __LINE__));
        return /*FALSE*/;
    }

    /* delete more than MEA_CFG_MAX_RECIPIENT_ADDRESSES addrs */
    nowAddr = addr;
    for(i = 1; i < MEA_CFG_MAX_RECIPIENT_ADDRESSES && nowAddr != NULL; i++)
    {
        nowAddr = nowAddr->next;
    }
    if (i == MEA_CFG_MAX_RECIPIENT_ADDRESSES && nowAddr != NULL)
    {
        meaAddrListFree(&nowAddr->next);
    }

    /* TO/CC/BCC */
    if (NULL == addr)
    {
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, 
            MEA_SIG_ME_ADDR_LIST_MENU_ACTIVATE);
        widget_send_update_event_to_wap();
        //meaMeCreateAddrListEmptyView(theProperty);
    }
    else if (!meaMeCreateAddrListView(theProperty, addr))
	{
	    meaMeDeleteAddrListView();
	}
    return;
}

#ifdef __UNIFIED_MSG_SUPPORT__
  #ifndef __UNIFIED_COMPOSER_SUPPORT__
/*!
 * \brief To edit mixed MMS by using SMIL editor, we must create slide info for it
 *
 * \param smilInfo: add slides, currentSlide, noOfSlides info for smilInfo structure
 * \return void
 *****************************************************************************/
static MSF_BOOL meaMeCreateMixedSmil(MeaMessage *theMessage)
{
    MeaMoDataItem *mo = NULL, *prev = NULL, *attach_obj = NULL;
    if(theMessage == NULL || theMessage->smilInfo == NULL)
    {
        return FALSE;
    }

    if(theMessage->smilInfo->mediaObjects == NULL)
    {
        (void)meaInsertSlide(theMessage->smilInfo);
	    return TRUE;
    }
 
    mo = theMessage->smilInfo->mediaObjects;

    while(mo && theMessage->smilInfo->noOfSlides < MEA_CFG_SLIDE_LIMIT)
    {
        MeaSmilSlide *slide = NULL;
        MeaMediaGroupType gType = meaMediaType2ObjType(mo->content.type);

        /* treat unsupported and unknown type object as attachment */
        if(!(gType & (MEA_MEDIA_GROUP_AUDIO | MEA_MEDIA_GROUP_IMAGE | MEA_MEDIA_GROUP_VIDEO | MEA_MEDIA_GROUP_TEXT)))
        {
            attach_obj = mo;
            if(prev == NULL)
            {
                mo = mo->next;
                theMessage->smilInfo->mediaObjects = mo;
            }
            else
            {
                prev->next = mo->next;
                mo=mo->next;
            }
            attach_obj->next = theMessage->unrefList;
            theMessage->unrefList = attach_obj;
        }
        else
        {
            slide = meaInsertSlide(theMessage->smilInfo);
            MEA_CALLOC(slide->objects[0], sizeof(MeaObjInfo));
            ASSERT(slide->objects[0] != NULL);

            slide->objects[0]->object = mo;
            if(gType | MEA_MEDIA_GROUP_TEXT)
            {
                slide->objects[0]->textColor = theMessage->smilInfo->fgColorDefault;
            }
            prev = mo;
            mo = mo->next;
        }
    }

    return TRUE;
}
  #endif
#endif

static MSF_BOOL meaMeIsUnrestrictedObjExist(MeaMessage *msg)
{
    MeaMoDataItem *mo;
    
    if (meaContentValidFlag == FALSE)
    {
        return TRUE;
    }

    if(msg == NULL || msg->smilInfo == NULL)
    {
        return FALSE;
    }
    mo = msg->smilInfo->mediaObjects;

    while(mo)
    {
        if(mo->isRestricted == FALSE)
        {
            return TRUE;
        }
        mo = mo->next;
    }
    mo = msg->unrefList;

    while(mo)
    {
        if(mo->isRestricted == FALSE)
        {
            return TRUE;
        }
        mo = mo->next;
    }
	return FALSE;
}

#ifndef __UNIFIED_COMPOSER_SUPPORT__
static void meaMeRemoveUnrestrictedObj(MeaSmilInfo *smilInfo)
{
    MeaSmilSlide *slide = NULL;
    MeaMoDataItem *mo = NULL;
    
    if(smilInfo == NULL || smilInfo->slides == NULL || smilInfo->mediaObjects == NULL)
    {
        return;
    }

    slide = smilInfo->slides;
    mo = smilInfo->mediaObjects;

    while(slide)  /* slide items */
    {
        int i = 0;
        for(i = 0; i < MEA_MAX_SMIL_OBJS; i++)
        {
            MeaMoDataItem *mo = NULL;
            if(slide->objects[i] != NULL && (mo = slide->objects[i]->object) != NULL)
            {
                if(mo->isRestricted == FALSE)
                {
                    meaDeleteMo(&smilInfo->mediaObjects, smilInfo->slides, mo);
                    MEA_CFREE(slide->objects[i]);
                }
            }
        }
        slide = slide->next;
    }
    
    while(mo)  /* check again so that we won't miss unref items */
    {
        MeaMoDataItem *next = mo->next;
        if(mo->isRestricted == FALSE)
        {
            meaDeleteMo(&smilInfo->mediaObjects, smilInfo->slides, mo);
        }
        mo = next;
    }

}
#endif

/*!
 * \brief Verifies if at least one of the properties are set.
 *
 * \param prop Which property to display.
 * \return TRUE if at least one property field is present and the mode is
 *         not TEMPLATE-mode.
 *****************************************************************************/
static MSF_BOOL meaCheckPropFields(MeaPropItem prop)
{
    MeaMeInstance *meInstance = curInst;

    if (!(meInstance->mode == MEA_ME_STARTUP_NEW_TEMPLATE))
    {
        /*
         *	We must test all combinations of empty address fields.
         *  Both NULL-fields and ""-fields.
         */
        if ((NULL == prop.cc) && (NULL == prop.to) && ((NULL == prop.bcc)))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ADDRESS_FIELD_MISSING), 
                MEA_DIALOG_ERROR);
            return FALSE;
        }
    }
    return TRUE;
}

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT

static void meaAddDefTempContent(void)
{
    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_ADD_DEFAULT_TEMP_CONT);
}

static void meaSetMeDefTempIndex(MSF_UINT32 index)
{
    curDefTempIndex = index;
}

static MSF_UINT32 meaGetMeDefTempIndex(void)
{
    return curDefTempIndex;
}

static void meaResetMeDefTempIndex(void)
{
    curDefTempIndex = 0;
}

static MSF_BOOL meaMeAddDefTempContent(void)
{
    MSF_UINT32 index;
    MeaSmilInfo *smilInfo = NULL;

    if (!curInst)
        return FALSE;

    /* Get smil info*/
    smilInfo = curInst->theMessage->smilInfo;
    if (!smilInfo)
        return FALSE;
    
    index = meaGetMeDefTempIndex();

    if (meaMeAddSubject(curInst, index) == FALSE)
    {
        return FALSE;
    }
    
    if (meaMeAddSlide(smilInfo) == FALSE)
    {
        return FALSE;
    }
    
    if (meaMeAddTextObj(smilInfo, index) == FALSE)
    {
        return FALSE;
    }
    
    if (meaMeAddImageObj(smilInfo, index) == FALSE)
    {
        return FALSE;
    }
    
    if (meaMeAddAudioObj(smilInfo, index) == FALSE)
    {
        return FALSE;
    }

    return TRUE;
}

static void meaMeAddDefTempContentFail(MeaMhCreateDefTemplateResult error)
{
    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
    (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, 
        MEA_SIG_MH_CREATE_DEF_TEMP_FINISHED, error);
}

static MSF_BOOL meaMeAddSubject(MeaMeInstance *inst, MSF_UINT32 index)
{
    MSF_UINT8 *utf8Ptr = NULL;
    MSF_UINT8 *ucs2Ptr = NULL;
    MSF_UINT32 utf8Len;
    MSF_UINT32 ucs2Len;
    unsigned short id;

    id = mmsTemplates[index].strId;
    ucs2Ptr = (MSF_UINT8*)GetString(id);
    if (!ucs2Ptr)
        return FALSE;

     /* ucs2 to utf8*/
    utf8Len = (widget_ucs2_length(ucs2Ptr) + 1) * 3;
    utf8Ptr = (MSF_UINT8*)MEA_ALLOC(utf8Len);
    utf8Len = widget_ucs2_to_utf8_string(utf8Ptr, utf8Len, ucs2Ptr);
    utf8Ptr[utf8Len] = 0;

    inst->theMessage->msgProperties->subject = (char*)utf8Ptr;

    return TRUE;
}

static MSF_BOOL meaMeAddSlide(MeaSmilInfo *smilInfo)
{
    MeaSmilSlide *newSlide;

    /* alloc a slide struct*/
    newSlide = (MeaSmilSlide*)MEA_ALLOC(sizeof(MeaSmilSlide));
    memset(newSlide, 0, sizeof(MeaSmilSlide));

    /* add slide into smilInfo*/
    if (NULL != smilInfo->currentSlide)
    {
        while (NULL!=smilInfo->currentSlide->next)
        {
        	smilInfo->currentSlide = smilInfo->currentSlide->next;
        }
        smilInfo->currentSlide->next = newSlide;
    }
    else
    {
        smilInfo->slides = newSlide;
        newSlide->next = NULL;
    }
    
    smilInfo->noOfSlides++;
    smilInfo->currentSlide = newSlide;

    /* Set the default duration */
    /* meaSetDuration(smilInfo, (unsigned)meaGetConfig()->slideDuration * 1000);*/
    meaSetDuration(smilInfo, (unsigned)MEA_CFG_DEFAULT_DURATION);
    
    return TRUE;
}

static MSF_BOOL meaMeAddTextObj(MeaSmilInfo *smilInfo, MSF_UINT32 index)
{
    MSF_UINT8 *utf8Ptr = NULL;
    MSF_UINT8 *ucs2Ptr = NULL;
    MSF_UINT32 utf8Len;
    MSF_UINT32 ucs2Len;
    unsigned short id;
    char name[MEA_DEF_TEMP_OBJ_NAME_MAX_LEN];
    char* objName = NULL;
    
    /* get string data from mmsTemplates[index]*/
    id = mmsTemplates[index].strId;
    ucs2Ptr = (MSF_UINT8*)GetString(id);
    if (!ucs2Ptr)
        return FALSE;
    
    /* ucs2 to utf8*/
    utf8Len = (widget_ucs2_length(ucs2Ptr) + 1) * 3;
    utf8Ptr = (MSF_UINT8*)MEA_ALLOC(utf8Len);
    utf8Len = widget_ucs2_to_utf8_string(utf8Ptr, utf8Len, ucs2Ptr);
    utf8Ptr[utf8Len] = 0;

    sprintf(name, "%s%02d%s", MEA_DEF_TEMP_TEXT_OBJ_NAME, (int)(index+1), MEA_DEF_TEMP_TEXT_OBJ_NAME_TYPE);
    objName = msf_cmmn_strdup(MSF_MODID_MEA, (char*)name);
    
    if (!objName)
    {
        MEA_FREE(utf8Ptr);
        return FALSE;
    }
    
    /* Set text data to message*/
#ifdef __DRM_SUPPORT__ 
    if (!meaSetSlideMo(smilInfo, MEA_MEDIA_TYPE_TEXT_PLAIN, MEA_MEDIA_TYPE_UNKNOWN, 
                 NULL, utf8Ptr, utf8Len + 1, 
	             objName, 0))
#else
    if (!meaSetSlideMo(smilInfo, MEA_MEDIA_TYPE_TEXT_PLAIN, NULL, 
                    utf8Ptr, utf8Len + 1, objName, 0))
#endif
    {
        MEA_FREE(utf8Ptr);
        MEA_FREE(objName);
        return FALSE;
    }
        
    return TRUE;
}

static MSF_BOOL meaMeAddImageObj(MeaSmilInfo *smilInfo, MSF_UINT32 index)
{
    MSF_UINT8 *ptr = NULL;
    MSF_UINT8 *objData = NULL;
    int len;
    MsfImageFormat type;
    unsigned short id;
    char name[MEA_DEF_TEMP_OBJ_NAME_MAX_LEN];
    char* objName = NULL;

    id = mmsTemplates[index].imageId;
    
    /* Get image data, type and length*/
    ptr = (MSF_UINT8*)HDIa_widgetExtImageGetPredefinedBuffer(id, &len, &type);
    if (!ptr || (len == 0))
        return FALSE;

    MEA_CALLOC(objData, len);
    memcpy(objData, ptr, len);

    sprintf(name, "%s%02d%s", MEA_DEF_TEMP_IMAGE_OBJ_NAME, (int)(index+1), MEA_DEF_TEMP_IMAGE_OBJ_NAME_TYPE);
    objName = msf_cmmn_strdup(MSF_MODID_MEA, (char*)name);
    if (!objName)
    {
        MEA_FREE(objData);
        return FALSE;
    }
    
    /* Set image data to message*/
#ifdef __DRM_SUPPORT__ 
    if (!meaSetSlideMo(smilInfo, meaConvertMsfTypeToMediaType(type), 
                MEA_MEDIA_TYPE_UNKNOWN, NULL, objData, len, 
	         objName, 0))
#else
    if (!meaSetSlideMo(smilInfo, meaConvertMsfTypeToMediaType(type), NULL, 
                    objData, len,  objName, 0))
#endif
    {
        MEA_FREE(objData);
        MEA_FREE(objName);
        return FALSE;
    }
        
    return TRUE;
}

static MSF_BOOL meaMeAddAudioObj(MeaSmilInfo *smilInfo, MSF_UINT32 index)
{
    MSF_UINT8 *ptr = NULL;
    MSF_UINT8 *objData = NULL;
    MSF_UINT32 len;
    MsfImageFormat type;
    unsigned short id;
    char name[MEA_DEF_TEMP_OBJ_NAME_MAX_LEN];
    char* objName = NULL;
    id = mmsTemplates[index].audioId;
    
    /*get audio data, type and length*/
    ptr = (MSF_UINT8*)resource_mms_sounds[id].data;
    len = resource_mms_sounds[id].len;
    type = resource_mms_sounds[id].format;
    
    if (!ptr || (len == 0))
        return FALSE;

    MEA_CALLOC(objData, len);
    memcpy(objData, ptr, len);

    sprintf(name, "%s%02d%s", MEA_DEF_TEMP_AUDIO_OBJ_NAME, (int)(index+1), MEA_DEF_TEMP_AUDIO_OBJ_NAME_TYPE);
    objName = msf_cmmn_strdup(MSF_MODID_MEA, (char*)name);
    if (!objName)
    {
        MEA_FREE(objData);
        return FALSE;
    }
    
#ifdef __DRM_SUPPORT__ 
    if (!meaSetSlideMo(smilInfo, meaConvertMsfTypeToMediaType(MsfMidi), 
             MEA_MEDIA_TYPE_UNKNOWN, NULL, objData, len, 
	         objName, 0))
#else
    if (!meaSetSlideMo(smilInfo, meaConvertMsfTypeToMediaType(MsfMidi), NULL, 
                    objData, len,  objName, 0))
#endif
    {
        MEA_FREE(objData);
        MEA_FREE(objName);
        return FALSE;
    }

    return TRUE;
}

MSF_BOOL meaMeIsSaveAsTemplateMode(void)
{
    if (!curInst)
        return FALSE;
    return curInst->mode == MEA_ME_STARTUP_SAVE_AS_TEMPLATE;
}
#endif

