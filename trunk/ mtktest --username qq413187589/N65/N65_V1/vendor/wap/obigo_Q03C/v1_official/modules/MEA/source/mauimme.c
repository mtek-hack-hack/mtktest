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

/* !\file mauimme.c
 *  \brief Functionality for the Multipart/mixed editor UI.
 */

/* MSF */
#include "msf_mem.h"
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_lib.h"
#include "msf_mem.h"

/* MMS */
#include "mms_def.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_def.h"
#include "matypes.h"
#include "mea_cfg.h"
#include "mea_rc.h"
#include "maintsig.h"
#include "mauimenu.h"
#include "mamme.h"
#include "mamr.h"
#include "mauisig.h"
#include "mauicmn.h"
#include "mauimme.h"
#include "maph.h"
#include "mautils.h"

/******************************************************************************
 * Definitions of internal data-structures for the GUI.
 *****************************************************************************/
/*! \struct MeaMmeEditor
 *  Main view 
 */
typedef struct
{
    MeaMessage          *msg;
    MeaMoDataItem       *mo;
    MeaMediaGroupType   gType;
    MSF_UINT32          audioHandle;
}MeaMmeEditor;

/*! \struct MeaMmeTextView
 *  Text editing view
 */
typedef struct
{
    MsfWindowHandle formHandle;
}MeaMmeTextView;

/*! \struct MeaMmeMenuItem
 *	
 */
typedef struct  
{
    MSF_UINT32  strId;      /*!< String to display in menu */
    int         signal;     /*!< Signal to send on selection */
    int         mediaGroup; /*!< Show menu entry for these media groups */
    MmsFileType blockedType;/*!< Tells if a menu alternative needs to be blocked
                                 for a specific message-type */
    MmsFileType blockedType2;/*!< Tells if a menu alternative needs to be blocked
                                 for a specific message-type */
}MeaMmeMenuItem;

/******************************************************************************
 * Constants
 *****************************************************************************/
/* Shorthand for "any type of object" */
#define ALL_MEDIA_GROUPS (MEA_MEDIA_GROUP_NONE | MEA_MEDIA_GROUP_IMAGE | \
    MEA_MEDIA_GROUP_TEXT | MEA_MEDIA_GROUP_AUDIO)
/* The maximum number of characters in the text editor */
#define MEA_MME_TEXT_MAX_SIZE            512

/* Menu items for the navigation menu */
static const MeaMmeMenuItem menuItems[] = 
{
    {MEA_STR_ID_ADD_TEXT, MEA_MME_ADD_TEXT, MEA_MEDIA_GROUP_NONE, MMS_SUFFIX_ERROR, MMS_SUFFIX_ERROR},
    {MEA_STR_ID_ADD_MEDIA_OBJECT, MEA_MME_ADD_MEDIA_OBJECT, MEA_MEDIA_GROUP_NONE, MMS_SUFFIX_ERROR, MMS_SUFFIX_ERROR},
    {MEA_STR_ID_REM_MEDIA_OBJ, MEA_MME_DELETE_MEDIA_OBJECT, ALL_MEDIA_GROUPS, MMS_SUFFIX_ERROR, MMS_SUFFIX_ERROR},
    {MEA_STR_ID_EDIT_TEXT, MEA_MME_EDIT_TEXT, MEA_MEDIA_GROUP_TEXT, MMS_SUFFIX_ERROR, MMS_SUFFIX_ERROR},
    {MEA_STR_ID_PLAY_SOUND, MEA_MME_PLAY_SOUND, MEA_MEDIA_GROUP_AUDIO, MMS_SUFFIX_ERROR, MMS_SUFFIX_ERROR},
    {MEA_STR_ID_SAVE, MEA_MME_SAVE, MEA_MEDIA_GROUP_NONE, MMS_SUFFIX_MSG, MMS_SUFFIX_ERROR},  /* Block save for retrieve conf. */
    {MEA_STR_ID_SAVE_AS_TEMPLATE, MEA_MME_SAVE_AS_TEMPLATE, MEA_MEDIA_GROUP_NONE, MMS_SUFFIX_ERROR},
    {MEA_STR_ID_SEND, MEA_MME_SEND, MEA_MEDIA_GROUP_NONE, MMS_SUFFIX_MSG, MMS_SUFFIX_TEMPLATE}, /* Block send for retrieve conf. and templates */
#ifndef WAP_SUPPORT
    {MEA_STR_ID_BACK, MEA_MME_BACK, MEA_MEDIA_GROUP_NONE, MMS_SUFFIX_ERROR, MMS_SUFFIX_ERROR},
#endif /* ~WAP_SUPPORT */
    {0,0,0}        
};

/******************************************************************************
 * Internal data-structures for the GUI.
 *****************************************************************************/
static MeaMmeEditor   meaMmeEditorView;
static MeaMmeTextView meaMmeTextView;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Initiates internal data-structures for the MME.
 *****************************************************************************/
void meaMmeUiInit(void)
{
    memset(&meaMmeEditorView, 0, sizeof(MeaMmeEditor));
    meaMmeEditorView.gType = MEA_MEDIA_GROUP_NONE;
} /* meaMmeUiInit */

/*!
 * \brief Initiates message pointer for MME UI
 * \param msg The message being edited
 *****************************************************************************/
void meaMmeUiSetMsg(MeaMessage *msg)
{
    meaMmeEditorView.msg = msg;        
}

/*!
 * \brief Signal converter callback function for the context sensitive menu.
 *
 * \param actionType The type of action that was generated.
 *****************************************************************************/
static void navMenuSignalConverter(MeaNavAction actionType)
{
    if (MEA_NAV_ACTION_BACK == actionType)
    {
        (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_NAV_MENU_DEACTIVATE);
    }

    if (MEA_NAV_ACTION_OK == actionType)
    {
        switch(meaGetNavMenuItem())
        {
        case MEA_MME_ADD_TEXT:
            (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_ADD_TEXT);
            break;
        case MEA_MME_ADD_MEDIA_OBJECT:       /*!< Add MO to the message */
            (void)meaOpenDlgCreateMediaInput(MEA_MME_FSM, 
                MEA_SIG_MME_GET_MEDIA_OBJECT, 
                MEA_CFG_OPEN_IMAGE_TYPES","MEA_CFG_OPEN_TEXT_TYPES"," MEA_CFG_OPEN_AUDIO_TYPES, meaInsertMixedObjCallback);
            break;
        case MEA_MME_DELETE_MEDIA_OBJECT:    /*!< Delete MO from the message */
            (void)MEA_SIGNAL_SENDTO_P(MEA_MME_FSM, MEA_SIG_MME_DELETE_MO, 
                meaMmeEditorView.mo);
            break;
        case MEA_MME_REPLACE_MEDIA_OBJECT:   /*!< Replace MO in the message */
            (void)meaOpenDlgCreateMediaInput(MEA_MME_FSM, 
                MEA_SIG_MME_GET_MEDIA_OBJECT_REPLACEMENT, 
                MEA_CFG_OPEN_IMAGE_TYPES","MEA_CFG_OPEN_TEXT_TYPES","MEA_CFG_OPEN_AUDIO_TYPES, meaInsertMixedObjCallback);
            break;
        case MEA_MME_EDIT_TEXT:              /*!< Edit text */
            (void)MEA_SIGNAL_SENDTO_P(MEA_MME_FSM, MEA_SIG_MME_EDIT_TEXT, 
                meaMmeEditorView.mo);
            break;
        case MEA_MME_PLAY_SOUND:             /*!< Play sound */
            (void)MEA_SIGNAL_SENDTO_P(MEA_MME_FSM, MEA_SIG_MME_PLAY_SOUND, 
                meaMmeEditorView.mo);
                break;
        case MEA_MME_SAVE:                   /*!< Save message */
            (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_SAVE);
            break;
        case MEA_MME_SAVE_AS_TEMPLATE:       /*!< Save message as template */
            (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_SAVE_AS_TEMPLATE);
            break;
        case MEA_MME_SEND:                   /*!< Send message */
            (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_SEND);
            break;
        case MEA_MME_PREVIEW:                /*!< Preview message */
            break;
        case MEA_MME_BACK:                   /*!< Go back */
            (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_DEACTIVATE);
            break;
        default:
            break;
        }
        (void)MEA_SIGNAL_SENDTO(MEA_MME_FSM, MEA_SIG_MME_NAV_MENU_DEACTIVATE);
    }
} /* navMenuSignalConverter */

/*!
 * \brief Creates menu items for the navigation menu for the MME.
 * \return TRUE on OK else FALSE
 *****************************************************************************/
static MSF_BOOL createMenuItems(MmsFileType msgType)
{
    int i = 0;

    /* Iterate through menuitems */
    for (i=0; menuItems[i].strId != 0; i++)
    {
        /* add menu entry if suitable for selected media object */
        if (((menuItems[i].mediaGroup == MEA_MEDIA_GROUP_NONE) || 
            (meaMmeEditorView.gType & menuItems[i].mediaGroup)) && 
            (menuItems[i].blockedType != msgType) &&
            (menuItems[i].blockedType2 != msgType) &&
            (! meaAddNavMenuItem(MEA_GET_STR_ID(menuItems[i].strId), 
            menuItems[i].signal)))
        {
            return FALSE;
        } /* if */
    } /* for */

    return TRUE;
} /* createMenuItems */

/*!
 * \brief Creates a navigation menu for the MME.
 * \param index the selected object on previous screen
 * \return TRUE on OK else FALSE
 *****************************************************************************/
MSF_BOOL meaUiMmeCreateNavMenu(int index, MmsFileType msgType)
{
    int i;

    /* Find selected mo, get media group info */
    meaMmeEditorView.mo = NULL;
    meaMmeEditorView.gType = MEA_MEDIA_GROUP_NONE;
    if ((-1 != index) && 
        (meaMmeEditorView.msg) &&
        (meaMmeEditorView.msg->smilInfo) &&
        (meaMmeEditorView.msg->smilInfo->mediaObjects))
    {
        meaMmeEditorView.mo = meaMmeEditorView.msg->smilInfo->mediaObjects;
        for (i=0; i<index; i++)
        {
            meaMmeEditorView.mo = meaMmeEditorView.mo->next;
        } /* for */
        meaMmeEditorView.gType = 
            meaMediaType2ObjType(meaMmeEditorView.mo->content.type);
    } /* if */
    

    /* Create navigation menu */
    if (!meaCreateNavMenu(0, navMenuSignalConverter))
    {
        meaRemoveNavMenu();
        return FALSE;
    }
    else if (!createMenuItems(msgType))
    {
        meaRemoveNavMenu();
        return FALSE;
    }
    else if (!meaShowNavMenu())
    {
        meaRemoveNavMenu();
        return FALSE;
    }
    return TRUE;
} 

/*!
 * \brief Deletes the navigation menu.
 *****************************************************************************/
void meaUiMmeDeleteNavMenu(void)
{
    meaRemoveNavMenu();
} 

/*!
 * \brief Returns selected MO in UI
 * \return selected MO in UI
 *****************************************************************************/
MeaMoDataItem *meaUiMmeGetSelectedMo(void)
{
    return meaMmeEditorView.mo;
} 

/*!
 * \brief Creates the text edit view.
 *
 * \param text The initial text.
 * \param subject The window title
 * \param retFsm The FSM to receive signals on button presses
 * \param retSigOk The signal to receive on OK presses
 * \param retSigBack The signal to receive on Back presses
 * \param retSigMenu The signal to receive on Menu presses
 * \return TRUE if the view was created successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaUiMmeCreateTextView(const char *text, const char *subject, 
    MeaStateMachine retFsm, int retSigOk, int retSigBack, int retSigMenu)
{
    MsfStringHandle textStringHandle;
    MsfStringHandle strHandle;
    const char *tmpStr;
    MSF_UINT32  maxLength;

    if (0 != meaMmeTextView.formHandle)
    {
        return FALSE; /* already running.. */
    }
    memset(&meaMmeTextView, 0, sizeof(MeaMmeTextView));
    
    /* Create text */
    tmpStr = (NULL != text) ? (char *)text: "";
    if (0 == (textStringHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
        tmpStr, MsfUtf8, (int)strlen(tmpStr) + 1, 0)))
    {
        return FALSE;
    }

    /* Checks if the total number of character to input needs to be higher
     * than default. This can be the case if a retrieved message is used as a
     * template.
     */
    if ((maxLength = MSF_WIDGET_STRING_GET_LENGTH(textStringHandle, 0, MsfUtf8)) < 
        MEA_MME_TEXT_MAX_SIZE)
    {
        maxLength = MEA_MME_TEXT_MAX_SIZE;
    }

    /* Create editor */
    if (0 == (meaMmeTextView.formHandle = MSF_WIDGET_EDITOR_CREATE(
        MSF_MODID_MEA, meaGetEmptyStringHandle(), textStringHandle, MsfText, 
        maxLength, FALSE, NULL, MSF_WINDOW_PROPERTY_TITLE, 0)))
    {
        (void)MSF_WIDGET_RELEASE(textStringHandle);
        return FALSE;
    }
    (void)MSF_WIDGET_RELEASE(textStringHandle);

    /* Set the title */
    tmpStr = (NULL != subject) ? subject: "";
    if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
        tmpStr, MsfUtf8, (int)strlen(tmpStr) + 1, 0)))
    {
        (void)MSF_WIDGET_RELEASE(strHandle);
        return FALSE;
    }
    (void)meaSetTitle(meaMmeTextView.formHandle, strHandle, 
        MSF_WINDOW_PROPERTY_TITLE);

    /* Create actions */
    if ((-1 != retSigOk) && 
        !meaCreateAction(meaMmeTextView.formHandle, MsfOk, NULL, retFsm, 
        retSigOk, MEA_STR_ID_OK))
    {
        return FALSE;
    }
    if ((-1 != retSigBack) && 
        !meaCreateAction(meaMmeTextView.formHandle, MsfCancel, NULL, retFsm, 
        retSigBack, MEA_STR_ID_CANCEL))
    {
        return FALSE;
    }
    if ((-1 != retSigMenu) && 
        !meaCreateAction(meaMmeTextView.formHandle, MsfMenu, NULL, retFsm, 
        retSigMenu, MEA_STR_ID_MENU))
    {
        return FALSE;
    }
    /* Show editor */
    return meaDisplayWindow(meaMmeTextView.formHandle, meaGetPosLeftTop());
}

/*!
 * \brief Deletes the text edit view.
 *****************************************************************************/
void meaUiMmeDeleteTextView(void)
{
    /* Delete window and actions */
    (void)meaDeleteWindow(meaMmeTextView.formHandle);
    /* Delete obsolete handles */
    memset(&meaMmeTextView, 0, sizeof(MeaMmeTextView));
}

/*!
 * \brief Retrieves text from text edit view
 *
 * \return The text string. It is the callers responsibility to free the 
 *         string. NULL is returned if no data can be retrieved.
 *****************************************************************************/
char *meaUiMmeGetMessageText(void)
{
    return (0 != meaMmeTextView.formHandle) 
        ? meaGetTextFromGadget(meaMmeTextView.formHandle) 
        : NULL;
}

/*!
 * \brief Stops the currently playing sound from playing
 *****************************************************************************/
void meaUiMmeStopAudio(void)
{
    if (meaMmeEditorView.audioHandle)
    {
        (void)MSF_WIDGET_SOUND_STOP(meaMmeEditorView.audioHandle);
        (void)MSF_WIDGET_RELEASE(meaMmeEditorView.audioHandle);
    }
    meaMmeEditorView.audioHandle = 0;
}

/*!
 * \brief Plays the currently selected sound
 *****************************************************************************/
void meaUiMmePlayAudio(void)
{
    meaUiMmeStopAudio();
    meaMmeEditorView.audioHandle = MSF_WIDGET_SOUND_CREATE(
        MSF_MODID_MEA, (char*)meaMmeEditorView.mo->data, 
        (MsfSoundFormat)meaConvertMediaTypeToMsf(meaMmeEditorView.mo->content.type), 
        (int)meaMmeEditorView.mo->size, 0);
    (void)MSF_WIDGET_SOUND_PLAY(meaMmeEditorView.audioHandle);
}

