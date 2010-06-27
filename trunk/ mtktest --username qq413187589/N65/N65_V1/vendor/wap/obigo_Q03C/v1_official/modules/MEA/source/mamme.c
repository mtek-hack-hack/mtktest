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

/*!\file mamme.c
 * \brief Message editor (Multi-Part/Mixed) control logic. 
 */

/* MSF */
#include "msf_mem.h"
#include "msf_int.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_dlg.h"

#ifdef WAP_SUPPORT
#include "msf_file.h"  //for MSF_FILE_GETSIZE
#endif

/* MMS Service/Lib */
#include "mms_def.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA*/
#include "mea_def.h"
#include "mea_cfg.h"
#include "mea_rc.h"
#include "matypes.h"
#include "maintsig.h"
#include "mamme.h"
#include "mamr.h"
#include "mame.h"
#include "mautils.h"
#include "maslh.h"
#include "mamem.h"
#include "maintsig.h"
#include "mauicmn.h"
#include "mautils.h"
#include "mauidia.h"
#include "maph.h"
#include "mamob.h"
#include "mauimme.h"
#include "mamoh.h"

/******************************************************************************
 * Constants
 *****************************************************************************/
#define MEA_MME_TYPE_SEP ","

/******************************************************************************
 * Static data-types
 *****************************************************************************/
static MeaMessage   *currentMsg;        /*!< The current message */
static MSF_BOOL     replaceFlag;        /*!< Whether add == replace */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void handleMobAction(MeaMobOperation op, int index);
static MeaSeverity setMediaObject(const MeaMessage *msg, MSF_BOOL replace, 
    MeaAfiReadResultData *objData, MeaAfiReadResult readResult);
static void restartMob(void);
static void mmeSignalHandler(MeaSignal *sig);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Handles events from the MOB
 * 
 * \param op    The operation or event 
 * \param index The index of the selected object while the event occurred
 *****************************************************************************/
static void handleMobAction(MeaMobOperation op, int index)
{
    MeaMobSpecialOp param;

    switch(op) 
    {
    case MEA_MOB_SELECT: 
    case MEA_MOB_MENU: 
        /* Menu button pressed on entry */
        (void)MEA_SIGNAL_SENDTO_I(MEA_MME_FSM, MEA_SIG_MME_NAV_MENU_ACTIVATE, 
            index);
        break;

    case MEA_MOB_FOCUS_ACTIVITY:
        /* Changed focus within attachment list */
        meaUiMmeStopAudio();
        break;

    case MEA_MOB_SPECIAL_OP:
        param = (MeaMobSpecialOp)index;
        if (MEA_MOB_SOP_ADD_MO & param) 
        {
            (void)meaOpenDlgCreateMediaInput(MEA_MME_FSM, 
            MEA_SIG_MME_GET_MEDIA_OBJECT, 
            MEA_CFG_OPEN_IMAGE_TYPES    MEA_MME_TYPE_SEP \
            MEA_CFG_OPEN_TEXT_TYPES     MEA_MME_TYPE_SEP \
            MEA_CFG_OPEN_AUDIO_TYPES, meaInsertMixedObjCallback);            
        } /* if */
        break;    
        
    case MEA_MOB_DEACTIVATED:
    default:
        /* no action*/
        break;
    }    
} /* handleMobAction */

/*! \brief Adds a media object to a message
 *
 * \param msg The message to add the MO to
 * \param replace Whether to replace current object 
 * \param objData the media object and information about it
 * \param readResult the result of the load object operation
 * \return MEA_SIZE_INFO_OK, otherwise how a dialog should be shown
 *****************************************************************************/
static MeaSeverity setMediaObject(const MeaMessage *msg, MSF_BOOL replace, 
    MeaAfiReadResultData *objData, MeaAfiReadResult readResult)
{
	MSF_UINT32      newMsgSize;
    unsigned int    oldMoSize = 0;
    unsigned int    newMoSize = 0;
    MeaMediaType    mType = MEA_MEDIA_TYPE_UNKNOWN;
    MeaMoDataItem   *item;
    MeaSeverity     result;

    if (NULL == objData)
    {
        return MEA_SEVERITY_ERROR;
    }

    result = MEA_SEVERITY_OK;

    if (NULL != objData->mimeType)
    {
        mType = meaMime2MediaType(objData->mimeType);
        /* oldMoSize = size before inclusion */
        if (NULL != 
            (item = meaGetMo(msg->smilInfo, meaMediaType2ObjType(mType))))
        {
            oldMoSize = item->size;
        }
        /* newMoSize = size of new object */
        newMoSize = objData->size;
    } /* if */

    if ((MEA_AFI_READ_RESULT_TO_LARGE != readResult) && /* handled below */
        (MEA_MEDIA_TYPE_UNKNOWN == mType))
    {
        (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_READ_MO), 
            MEA_DIALOG_ERROR, MEA_MME_FSM, MEA_SIG_MME_RESTART_MOB_IND);
        return MEA_SEVERITY_ERROR;
    } /* if */

    /* The size the message will get after inclusion of this media object */
	newMsgSize = meaCalculateMsgSize(msg->smilInfo, msg->msgProperties) 
        - (replace ? oldMoSize : 0) + newMoSize;
       
    /* compare message and object sizes */
    result = meaShowSizeWarningDialog(MEA_AFI_READ_RESULT_TO_LARGE == readResult
        ? 0xffffffff : newMsgSize, newMoSize, mType, MEA_MME_FSM, 
        MEA_SIG_MME_RESTART_MOB_IND);
    if (result == MEA_SEVERITY_ERROR)
    {
        return MEA_SEVERITY_ERROR;
    }
    
    if (replace) 
    {
        meaDeleteMo(&msg->smilInfo->mediaObjects, NULL, 
            meaUiMmeGetSelectedMo());        
    } /* if */    

    if (NULL == objData->fileName)
    {
        objData->fileName = meaCreateFileNameFromType(mType);
        if (NULL == objData->fileName)
        {
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(
                MEA_STR_ID_FAILED_TO_READ_MO), MEA_DIALOG_ERROR, MEA_MME_FSM,
                MEA_SIG_MME_RESTART_MOB_IND);
            return MEA_SEVERITY_ERROR;
        } /* if */
    }
//    meaRemPathFromFileName(objData->fileName);

#ifdef __DRM_SUPPORT__
    item = meaAddMo(&msg->smilInfo->mediaObjects, objData->data, objData->size, mType, MEA_MEDIA_TYPE_UNKNOWN, NULL, 
                    objData->fileName,0, 0);
#else
    item = meaAddMo(&msg->smilInfo->mediaObjects, objData->data, objData->size, mType, NULL, objData->fileName,0, 0);
#endif
    if (NULL == item)
    {
        (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_READ_MO),
                MEA_DIALOG_ERROR, MEA_MME_FSM, MEA_SIG_MME_RESTART_MOB_IND);
        return MEA_SEVERITY_ERROR;
    }
    objData->data = NULL;
    objData->fileName = NULL;
    return result;
} /* setMediaObject */


/*! \brief Restart mob
 *****************************************************************************/
static void restartMob(void)
{
    (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);            
    meaMobActivate(currentMsg->smilInfo->mediaObjects, MEA_MOB_SOP_ADD_MO, 
        MEA_STR_ID_EDIT_CONTENT, MEA_MME_FSM, 
        MEA_SIG_MME_MOB_OP);             
}

#ifdef WAP_SUPPORT
MeaInsertResult meaInsertMixedObjCallback(const char * pathname)	/* called in MMI task */
{
    int spaceLeft = 0;
    int filesize = MSF_FILE_GETSIZE(pathname);

    spaceLeft = MIN(MEA_CFG_MESSAGE_SIZE_MAXIMUM - meaCalculateMsgSize(currentMsg->smilInfo, currentMsg->msgProperties), 
                MEA_CFG_INSERT_MEDIA_OBJECT_MAX_SIZE);

    if(filesize > spaceLeft)
    	return FALSE;
    else
    	return TRUE;
}
#endif

/*!
 * \brief The Multipart/mixed editor signal handling logic
 *
 * \param sig The received signal
 *****************************************************************************/
static void mmeSignalHandler(MeaSignal *sig)
{
    int             spaceLeft;
    char            *text;
    MeaMoDataItem   *mo;

    if ((MEA_SIG_MME_ACTIVATE != sig->type) && (NULL == currentMsg)) 
    {
        return; 
    }

    switch (sig->type)
    {
    /*
     *	Activation/deactivation
     */
    case MEA_SIG_MME_ACTIVATE: 
        /*
         *	Activation. 
         */
        currentMsg = (MeaMessage*)sig->p_param;
        if (!currentMsg) 
        {
            break;
        } /* if */
        meaMmeUiSetMsg(currentMsg);

        /* activate MOB */
        meaMobActivate(currentMsg->smilInfo->mediaObjects, 
            MEA_MOB_SOP_ADD_MO, MEA_STR_ID_EDIT_CONTENT,  
            MEA_MME_FSM, MEA_SIG_MME_MOB_OP);             
        break; 

    case MEA_SIG_MME_DEACTIVATE: 
        meaUiMmeStopAudio();
        meaMmeUiSetMsg(NULL);
        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
        /* terminate ME */
        meaMmeTerminateGui();
        currentMsg = NULL; 
        break;
        
    /*
     *	Interaction with the MOB
     */
    case MEA_SIG_MME_MOB_OP:
        /* End User did something in MOB view */
        meaUiMmeStopAudio();
        handleMobAction((MeaMobOperation)sig->u_param1, sig->i_param);        
        break;

    case MEA_SIG_MME_GET_MEDIA_OBJECT_REPLACEMENT:
    case MEA_SIG_MME_GET_MEDIA_OBJECT:
        replaceFlag = (MEA_SIG_MME_GET_MEDIA_OBJECT_REPLACEMENT == sig->type);

        if (MSF_DLG_RETURN_OK == sig->u_param1)
        {
            /*
             *	No use loading media objects larger than the lesser of 
             *  a) the 100k barrier, and b) the maximum media object size
             */
            spaceLeft = MIN(
                MEA_CFG_MESSAGE_SIZE_MAXIMUM - meaCalculateMsgSize(
                currentMsg->smilInfo, currentMsg->msgProperties), 
                MEA_CFG_INSERT_MEDIA_OBJECT_MAX_SIZE);

            if (!meaAfiLoadFromFile(MEA_MME_FSM, MEA_SIG_MME_GET_MEDIA_OBJECT_RSP, 
                sig->p_param, NULL, (unsigned int)spaceLeft))
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_READ_MO), 
                    MEA_DIALOG_ERROR);
            }
        }
        break;

    case MEA_SIG_MME_GET_MEDIA_OBJECT_RSP:
        /*
         *	Data has been fetched for inclusion into MM.
         */

        if (MEA_SEVERITY_OK == setMediaObject(currentMsg, replaceFlag,
            (MeaAfiReadResultData *)sig->p_param, 
            (MeaAfiReadResult)sig->u_param1))
        {
            /* no dialogs visible, can restart MOB directly */
            (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_RESTART_MOB_IND);
        } /* if */
        meaAfiLoadFreeData((MeaAfiReadResultData *)sig->p_param);

        break;

    case MEA_SIG_MME_RESTART_MOB_IND:
        /* object was added and MOB must be restarted */
        restartMob();
        break;

    case MEA_SIG_MME_PLAY_SOUND:
        meaUiMmePlayAudio();
        break;
        
    /*
     *	Text editing
     */
    case MEA_SIG_MME_DELETE_MO: 
        meaDeleteMo(&currentMsg->smilInfo->mediaObjects, NULL, 
            (MeaMoDataItem *)sig->p_param);        
        sig->p_param = NULL;
        /* Restart MOB because it cannot be modified */
        restartMob();
        break;

    case MEA_SIG_MME_ADD_TEXT:
        if (!meaUiMmeCreateTextView(NULL, 
            meaGetStringFromHandle(MEA_GET_STR_ID(MEA_STR_ID_ADD_TEXT)),
            MEA_MME_FSM, MEA_SIG_MME_ADD_TEXT_OK, MEA_SIG_MME_TEXT_BACK, -1))
        {
            /* Text creation failed terminate FSM */
            (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_DEACTIVATE);
        }
        break;

    case MEA_SIG_MME_EDIT_TEXT:
        mo = (MeaMoDataItem *)sig->p_param;
        if (!meaUiMmeCreateTextView(mo ? (char *)mo->data : NULL, 
            mo ? mo->name : NULL, MEA_MME_FSM, MEA_SIG_MME_TEXT_OK, 
            MEA_SIG_MME_TEXT_BACK, -1))
        {
            /* Text creation failed terminate FSM */
            (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_DEACTIVATE);
        }
        break;

    case MEA_SIG_MME_ADD_TEXT_OK:
        if ((NULL != (text = meaUiMmeGetMessageText())) &&
            (strlen(text) > 0))
        {
#ifdef __DRM_SUPPORT__
            if (NULL == meaAddMo(&currentMsg->smilInfo->mediaObjects, (unsigned char*)text, strlen(text)+1, 
                                 MEA_MEDIA_TYPE_TEXT_PLAIN, MEA_MEDIA_TYPE_UNKNOWN, NULL, 
                                 meaCreateFileNameFromType(MEA_MEDIA_TYPE_TEXT_PLAIN),0, 0))
#else
            if (NULL == meaAddMo(&currentMsg->smilInfo->mediaObjects, (unsigned char*)text, strlen(text)+1, 
                                 MEA_MEDIA_TYPE_TEXT_PLAIN, NULL, meaCreateFileNameFromType(MEA_MEDIA_TYPE_TEXT_PLAIN),0
                                 , 0))
#endif
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR),
                    MEA_DIALOG_ERROR);
                meaUiMmeDeleteTextView();    
                break;
            }
        } /* if */
        meaUiMmeDeleteTextView();
        /* Restart MOB because it cannot be modified */
        restartMob();
        break;

    case MEA_SIG_MME_TEXT_OK:
        if ((NULL != (mo = meaUiMmeGetSelectedMo()))  &&
            (NULL != (text = meaUiMmeGetMessageText())))
        {
            if (strlen(text) > 0)
            {
                MEA_FREE(mo->data);
                mo->data = (unsigned char *)text;
                mo->size = strlen(text)+1;            
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO_P(MEA_MME_FSM, MEA_SIG_MME_DELETE_MO,
                    mo);
                meaUiMmeDeleteTextView();
                break;
            }
        } /* if */
        meaUiMmeDeleteTextView();
        /* Restart MOB because it cannot be modified */
        restartMob();
        break;

    case MEA_SIG_MME_TEXT_BACK:
        meaUiMmeDeleteTextView();
        break;

    /*
     *	Saving/sending - done via ME.
     */
    case MEA_SIG_MME_SEND: 
        (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_SEND, 
            MEA_MME_FSM, MEA_SIG_MME_SEND_DONE);
        break;
        
    case MEA_SIG_MME_SAVE: 
        (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_SAVE, 
            MEA_MME_FSM, MEA_SIG_MME_SAVE_DONE);
        break;
        
    case MEA_SIG_MME_SAVE_AS_TEMPLATE: 
        (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_SAVE_AS_TEMPLATE,
            MEA_MME_FSM, MEA_SIG_MME_SAVE_AS_TEMPLATE_DONE);
        break;

    case MEA_SIG_MME_SEND_DONE:
    case MEA_SIG_MME_SAVE_DONE:
    case MEA_SIG_MME_SAVE_AS_TEMPLATE_DONE:
        if (TRUE == sig->u_param1)
        {    
            /*
             *	All done, let's shut down. 
             *  Any error messages will have been shown by ME.
             */
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM,  MEA_SIG_ME_DEACTIVATE);
            (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_DEACTIVATE);
        } /* if */        
        break;
        
    /*
     *	Navigation menu, context sensitive
     */
    case MEA_SIG_MME_NAV_MENU_DEACTIVATE: 
        meaUiMmeDeleteNavMenu();        
        break;       
        
    case MEA_SIG_MME_NAV_MENU_ACTIVATE: 
        if (!meaUiMmeCreateNavMenu(sig->i_param, currentMsg->fileType))
        {
            (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_DEACTIVATE);
        }
        break;       

    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMME_6261D9A93DB1F4473DF1A2469318A06A, "%s(%d): mmeSignalHandler erroneous signal received(%d)\n", 
            __FILE__, __LINE__, sig->type));
        break;
    }
    meaSignalDelete(sig);
} /* mmeSignalHandler */

/***************************************************************************** 
 * Exported functions 
 *****************************************************************************/

/*!
 * \brief Initiates the Multipart/mixed editor by registering its signal 
 *        handler and initiating the data structures etc
 *****************************************************************************/
void meaMmeInit(void)
{
    meaSignalRegisterDst(MEA_MME_FSM, mmeSignalHandler);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAMME_C714A93C3DBB0CBA7F40EBA7E29BB3F9, "%s(%d): MME FSM initialised!\n", __FILE__, __LINE__));
    currentMsg = NULL; 
} /* meaMmeInit */

/*!
 * \brief Terminates by de-registering the signal handler and 
 *          freeing all data structures used
 *****************************************************************************/
void meaMmeTerminate(void)
{
    meaSignalDeregister(MEA_MME_FSM);
    meaMmeTerminateGui();
    currentMsg = NULL; 
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAMME_0910CF6FC6104D0189ECA92D59150D8A, "%s(%d): MME FSM terminated!\n", __FILE__, __LINE__));
} /* meaMmeTerminate */

/*!
 * \brief Terminates the GUI for the Multipart/mixed editor.
 *****************************************************************************/
void meaMmeTerminateGui(void)
{
    /* One-state shutdown */
    meaUiMmeStopAudio();
    meaUiMmeDeleteTextView();
    meaUiMmeDeleteNavMenu();
} /* meaMmeTerminateGui */




