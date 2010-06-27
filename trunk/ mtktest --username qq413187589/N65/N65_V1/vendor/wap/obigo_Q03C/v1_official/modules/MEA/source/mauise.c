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
 * Description:     Functionality for the SMIL editor UI.
 */

/* !\file mauise.c
 *  \brief Functionality for the SMIL editor GUI
 */

/* MSF */
#include "msf_mem.h"
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_lib.h"
#include "msf_log.h"
#include "msf_mem.h"

/* MMS */
#include "mms_def.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MTR */
#include "mtr.h"

/* MEA */
#ifndef WAP_SUPPORT //move matypes.h back to mea_cfg.h
#include "mea_def.h"
#include "matypes.h"
#endif /* WAP_SUPPORT */
#include "mea_cfg.h"
#ifdef WAP_SUPPORT 
#include "matypes.h"
#endif /* WAP_SUPPORT */
#include "mea_rc.h"
#include "maintsig.h"
#include "mamem.h"
#include "mase.h"
#include "maslh.h"
#include "mauise.h"
#include "mauisig.h"
#include "mauicmn.h"
#include "mauiform.h"
#include "maph.h"
#include "mautils.h"
#ifdef WAP_SUPPORT
#include "widget_extension.h"
#endif /* WAP_SUPPORT */
#ifdef __DRM_SUPPORT__
#include "fs_type.h"   //for FS_READ_ONLY
#include "fs_errCode.h" //for FS_NO_ERROR
#include "../../drm/include/drm_def.h" //for DRM_PERMISSION_DISPLAY
#include "../../drm/include/drm_gprot.h"
#include "../../drm/include/drm_main.h"
#endif /* __DRM_SUPPORT__ */
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
#include "mamr.h"  //for mame.h
#include "mame.h"  //for meaMeCalculateMsgSize
extern MeaSeverity meaSeSetTextObject(MeaAfiReadResultData *objData);
#endif /* WIDGET_ADVANCED_SMILE_EDDITOR*/

/******************************************************************************
 * Constants
 *****************************************************************************/

#define EDITOR_PROPERTIES           (MSF_WINDOW_PROPERTY_TITLE)
#define PAR_CHAR_RIGHT              ((unsigned char)'(')
#define PAR_CHAR_LEFT               ((unsigned char)')')
#define SLASH_CHAR                  ((unsigned char)'/')

#define MEA_SE_OBJECT_PADDING       (6)
#define MEA_SE_MAX_IMAGE_WIDTH      (800)
#define MEA_SE_MAX_IMAGE_HEIGHT     (600)

#define MEA_SE_TEXT_MIME_TYPE       "text/plain"

/* Sets the color distance for when the text color (cursor) in a SMIL is to
 * close to the background color and needs to be changed.
 */
#define MEA_MIN_COLOR_DIFF      0x08
#ifdef __DRM_SUPPORT__
#define MEA_DRM_READ_CHUNK_SIZE     (4096)     //for reading drm object
#endif /* __DRM_SUPPORT__ */

/******************************************************************************
 * Definitions of internal data-structures for the GUI.
 *****************************************************************************/

/*! \struct MeaSeEditor
 *  Main view */
typedef struct
{
    MsfWindowHandle formHandle;
    /* Media obj */

#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    MsfImageHandle imageHandle;
#else
    /* Image handling */
    MsfGadgetHandle imageGadgetHandle;

    /* Text handling */
    MsfGadgetHandle textGadgetHandle;
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */
    int textBoxInstance;
    MsfStringHandle textHandle;

    /* Audio handling */
    MsfGadgetHandle audioGadgetHandle;

    /* Input gadgets */
    MsfGadgetHandle textInputHandle;
    MsfGadgetHandle imageInputHandle;
    MsfGadgetHandle audioInputHandle;

    /* The currently active object */
    MeaSeGadgetDef  activeMediaObject;   /* The type of media that is currently 
                                                active */
#ifdef WAP_SUPPORT
    MsfActionHandle backActHandle;
#endif /* WAP_SUPPORT */
}MeaSeEditor;

/******************************************************************************
 * Internal data-structures for the GUI.
 *****************************************************************************/

static MeaSeEditor     *meaSeView;

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void cleanupGadgets(void);
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
static void handleSeOkAction(ctk_screen_handle scrid);
#else
static void handleSeOkAction(MsfWindowHandle winHandle);
static void adjustTextColor(MsfColor *textColor, const MsfColor *bgColor);
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Initiates internal data-structures for the SE.
 *****************************************************************************/
void meaSeUiInit(void)
{
    meaSeView = NULL;
} /* meaSeUiInit */

#ifdef WIDGET_ADVANCED_SMIL_EDITOR
char *meaSeGetTextBuffer(void)
{
    MsfStringHandle strHandle = HDIa_widgetExtSmilEditorGetText(meaSeView->formHandle);
    int strHandleLength = MSF_WIDGET_STRING_GET_LENGTH (strHandle, TRUE, MsfUtf8);
    char *str = MEA_ALLOC(strHandleLength+1);

    MSF_WIDGET_STRING_GET_DATA (strHandle, str, MsfUtf8);
    return str;
}

/*!
 *  \brief Ok signal handler for the editor view.
 *  \param winHandle The current window handle.
 *****************************************************************************/
static void handleSeOkAction(ctk_screen_handle scrid)
{
    MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_ACTIVATE);
    widget_send_update_event_to_wap();
}

//TODO: remove it after widget clear the RSK Back
static void handleSeBackAction(ctk_screen_handle scrid)
{
    (void)handleSeTvOkAction(meaSeGetTextBuffer(), 0, NULL, 0);
    MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_DEACTIVATE);
	widget_send_update_event_to_wap();
}

/*! Gets the form handle of meaSeview.
 *	
 * \return The form handle of meaSeview.
 */
MsfWindowHandle meaSeGetFormHandle(void)
{
    if (NULL != meaSeView)
    {
        return meaSeView->formHandle;
    }
    return 0;
}
#else /* WIDGET_ADVANCED_SMIL_EDITOR */
/*!
 *  \brief Ok signal handler for the editor view.
 *  \param winHandle The current window handle.
 *****************************************************************************/
static void handleSeOkAction(MsfWindowHandle winHandle)
{
    (void)winHandle;
    /* Set which gadget that is currently active */
    meaSeSetActiveObj();

    /* perform actions accordingly */
    switch(meaSeGetActiveGadget())
    {
    case MEA_SE_GADGET_IMAGE:
    case MEA_SE_GADGET_INP_IMAGE:
        (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, 
            MEA_MEDIA_GROUP_IMAGE);
        break;
    case MEA_SE_GADGET_TEXT:
    case MEA_SE_GADGET_INP_TEXT:
        (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, 
            MEA_MEDIA_GROUP_TEXT);
        break;
    case MEA_SE_GADGET_AUDIO:
    case MEA_SE_GADGET_INP_AUDIO:
        (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, 
            MEA_MEDIA_GROUP_AUDIO);
        break;
  #ifndef WAP_SUPPORT
    case MEA_SE_GADGET_NONE:
        (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_ACTIVATE);
        break;
  #endif /* ~WAP_SUPPORT */
    }
} /* handleSeEvOkAction */ 
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */

/*!
 *  \brief Ok signal handler for the text editor.
 *  \param text The edited text
 *  \param notUsed N/A.
 *  \param dataPtr N/A.
 *  \param uintValue N/A.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL handleSeTvOkAction(char *text, unsigned int notUsed, 
    void *dataPtr, unsigned int uintValue)
{
    MeaAfiReadResultData *resultData;
    int size = 0;
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    MSF_BOOL ret;
#endif
    if ((0 != notUsed) && (NULL != dataPtr) && (0 != uintValue))
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MAUISE_8B1D26F751745562FA5363E1110E09CB, "(%s) (%d) Erroneous parameter value!\n", __FILE__, __LINE__));
    }
    MEA_CALLOC(resultData, sizeof(MeaAfiReadResultData));
    resultData->mimeType = MEA_ALLOC(sizeof(MEA_SE_TEXT_MIME_TYPE));
    strcpy(resultData->mimeType, MEA_SE_TEXT_MIME_TYPE);
    if (!*text) 
    {
        MEA_FREE(text);
        text = NULL;
        size = 0;
    }
    else
    {
        size = (int)strlen(text) + 1;
    }
    resultData->data = text;
    resultData->size = (MSF_UINT32)size;
    resultData->fileName = meaCreateFileNameFromType(MEA_MEDIA_TYPE_TEXT_PLAIN); /* should not fail */
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    /* Add text to MO list */
    if (MEA_SEVERITY_ERROR != meaSeSetTextObject(resultData))
    {
        HDIa_widgetExtSmilEditorSetUnmodified(meaSeView->formHandle);
		ret = TRUE;
    }
	else
	{
	    ret = FALSE;
	}
    /* Free data */
    meaSeSetBusy(FALSE);
    meaAfiLoadFreeData(resultData);
	return ret;
#else
    (void)MEA_SIGNAL_SENDTO_UP(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT_RSP, 
            MEA_AFI_READ_RESULT_OK, resultData);
    return TRUE;
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */
} /* handleSeTvOkAction */

/*!
 * \brief Creates the text edit view SMIL edit.
 *
 * \param text The initial text.
 * \param title The title for the form.
 * \return TRUE if the view was created successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaSeCreateTextView(char *text, const char* title)
{
    MeaInputItem item;
    MSF_BOOL ret;
#ifndef WAP_SUPPORT
    MsfStringHandle strHandle;
#endif /* WAP_SUPPORT */
    memset(&item, 0, sizeof(MeaInputItem));
    item.type           = MEA_TEXT_INPUT;
    item.callback       = handleSeTvOkAction;
    item.text           = text;
    item.maxTextSize    = MEA_MAX_TEXT_LENGTH;
#ifdef WAP_SUPPORT
    item.textType       = (MsfTextType)MsfMMIDefaultInputMethod;
    ret = meaCreateInputForm(&item, MEA_GET_STR_ID(MEA_STR_ID_EDIT_TEXT));
#else
    item.textType       = MsfText;

    if (title)
    {
        if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, title, 
            MsfUtf8, (int)strlen(title) + 1, 0)))
        {
            (void)MSF_WIDGET_RELEASE(strHandle);
            return FALSE;
        }
        ret = meaCreateInputForm(&item, strHandle);
        (void)MSF_WIDGET_RELEASE(strHandle);
    }
    else
    {
        ret = meaCreateInputForm(&item, MEA_GET_STR_ID(MEA_STR_ID_EDIT_TEXT));
    }
#endif /* WAP_SUPPORT */
    return ret;
} /* meaSeCreateTextView */

/*!
 * \brief Creates the main view for the SMIL editor.
 * 
 * \return TRUE if the view was created successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaSeCreateEditorView(void)
{
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
	widget_string_pack_struct dumpTitle;
	ctk_screen_handle scrid;
    if (NULL != meaSeView)
    {
        return FALSE;
    }
    MEA_CALLOC(meaSeView, sizeof(MeaSeEditor));
    /*
	if (widget_test_smil_editor_image)
	{
		HDIa_widgetRelease(widget_test_smil_editor_image);
	}
	widget_test_smil_editor_image = HDIa_widgetImageCreateResource(MSF_MODID_MEA, 
				"/public/sh.gif", MsfResourceFile , MsfGif);
	*/
	dumpTitle.type = WIDGET_STRING_PACK_UTF8;
	dumpTitle._u.utf8 = (kal_uint8*) "";
	/* Create the form */
    if (0 == (meaSeView->formHandle = HDIa_widgetExtCreateSmilEditor(MSF_MODID_MEA, 
		dumpTitle, dumpTitle, 0, 0, MEA_MAX_TEXT_LENGTH, 0, WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM)))
    {
        return FALSE;
    }
	// HDIa_widgetCtkSetFlag(wnd, WIDGET_CTK_FLAG_DISABLE_FIXED_STATUS_ICONS);

    meaAddWidgetList(meaSeView->formHandle);
	scrid = HDIa_widgetCtkGetScreenHandle(meaSeView->formHandle);
	ctk_screen_addLSK_UA(scrid, MEA_STR_ID_OPTIONS, 0, NULL, handleSeOkAction, KAL_TRUE);
	ctk_screen_addRSK_UA(scrid, MEA_STR_ID_DONE, 0, NULL, handleSeBackAction, KAL_TRUE);
#else /* WIDGET_ADVANCED_SMIL_EDITOR */
    MsfStyleHandle styleHandle;
    if (NULL != meaSeView)
    {
        return FALSE;
    }
    MEA_CALLOC(meaSeView, sizeof(MeaSeEditor));
    meaSeView->textBoxInstance = -1;
    /* Create a style for this form, since the background is going to be 
       changed */
    styleHandle = MSF_WIDGET_STYLE_CREATE(MSF_MODID_MEA, NULL, NULL, NULL, 
        NULL, NULL, NULL, NULL);

    /* Create the form */
    if (0 == (meaSeView->formHandle = MSF_WIDGET_FORM_CREATE(
        MSF_MODID_MEA, NULL, EDITOR_PROPERTIES, styleHandle)))
    {
        return FALSE;
    }
    /* Actions */
    if (0 == (meaSeView->backActHandle = meaCreateAction(meaSeView->formHandle, MsfBack, 
        NULL, MEA_SE_FSM, MEA_SIG_SE_DEACTIVATE, MEA_STR_ID_BACK)))
    {
        return FALSE;
    }
    if (0 == meaCreateAction(meaSeView->formHandle, MsfSelect, 
        NULL, MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_ACTIVATE, 
        MEA_STR_ID_OPTIONS))
        return FALSE;
    /* Handle the event for the "send" key */
    if (meaRegisterUserEvent(meaSeView->formHandle, MsfKey_Yes, handleSeOkAction, 
        (MeaStateMachine)0, 0) < 0)
    {
        return FALSE;
    }
    /* Handle the event for the "right" key */
    if (meaRegisterUserEvent(meaSeView->formHandle, MsfKey_Right, NULL, MEA_SE_FSM, 
        MEA_SIG_SE_NEXT_SLIDE) < 0)
    {
        return FALSE;
    }
    /* Handle the event for the "left" key */
    if (meaRegisterUserEvent(meaSeView->formHandle, MsfKey_Left, NULL, MEA_SE_FSM, 
        MEA_SIG_SE_PREVIOUS_SLIDE) < 0)
    {
        return FALSE;
    }
#endif /* WIDGET_ADVANCED_SMIL_EDITOR	*/
    /* Display form */
    return meaDisplayWindow(meaSeView->formHandle, meaGetPosLeftTop());
} /* meaSeCreateEditorView */

/*!
 * \brief Sets the title of the SMIL editor
 *
 * \param subject The subject of the message.
 * \param slideIndex The index of the current slide.
 * \param slideCount The total number of slides.
 * \param msgSize The size of the message in bytes.
 *****************************************************************************/
static void seSetTitle(const char *subject, unsigned int slideIndex, 
    unsigned int slideCount, unsigned int msgSize)
{
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
	widget_string_pack_struct title1, title2;
	char *sizeBuffer;
#else
    MsfStringHandle strHandle;
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */
    char *buffer;
    unsigned int len;
    int kb;

    /* Calculate the buffer length for the string to format */
    len = ((NULL != subject) ? strlen(subject) : 0) + 
        ((sizeof(unsigned int) * 3) * 2) / 10 + 
        sizeof(PAR_CHAR_RIGHT) + sizeof(SLASH_CHAR) + sizeof(PAR_CHAR_LEFT) + 
        strlen("KB") + sizeof(char)*3 + sizeof(char)*6 + sizeof(char);
    buffer = MEA_ALLOC((MSF_UINT32)len);

    /* Format string: do not use string resource ID, ex. MEA_STR_ID_KB, for font consistency */
    if (msgSize > MEA_CFG_MESSAGE_SIZE_MAXIMUM)
        msgSize = MEA_CFG_MESSAGE_SIZE_MAXIMUM;

    kb = (int)((msgSize + (MEA_1_KB - 1)) / MEA_1_KB); /* Calculate the size in kilo bytes using ceil */
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    sprintf(buffer, "%c%d%c%d%c", PAR_CHAR_RIGHT, slideIndex + 1, 
        SLASH_CHAR, slideCount, PAR_CHAR_LEFT);
    sizeBuffer = MEA_ALLOC((MSF_UINT32)(strlen("300 KB ") + 1));
    sprintf(sizeBuffer, "%d KB ", kb);	
    title1.type = WIDGET_STRING_PACK_UTF8;
    title1._u.utf8 = (kal_uint8*)buffer;
    title2.type = WIDGET_STRING_PACK_UTF8;
    title2._u.ucs2 = (kal_uint8*)sizeBuffer;
    HDIa_widgetExtSmilEditorUpdateTitle(meaSeView->formHandle, title1, title2, 0);
    MEA_FREE(sizeBuffer);
#else
    sprintf(buffer, "%c%d%c%d%c %d KB ", PAR_CHAR_RIGHT, slideIndex + 1, 
        SLASH_CHAR, slideCount, PAR_CHAR_LEFT, kb);
    strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, buffer, MsfUtf8, 
        (int)strlen(buffer) + 1, 0);
    (void)meaSetTitle(meaSeView->formHandle, strHandle, 
        EDITOR_PROPERTIES);
    (void)MSF_WIDGET_RELEASE(strHandle);
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */
    /*lint -e{774} */
    MEA_FREE(buffer);
}

/*! Gets the currently active MeaSeGadgetDef.
 *	
 * \return The currently active media group type, see #MeaSeGadgetDef.
 */
MeaSeGadgetDef meaSeGetActiveGadget(void)
{
    if (NULL != meaSeView)
    {
        return meaSeView->activeMediaObject;
    }
    return MEA_SE_GADGET_NONE;
}

#ifndef WIDGET_ADVANCED_SMIL_EDITOR
/*! \brief Sets the currently active media object gadget. This function can 
 *         only be called when the SE form has focus
 *
 *****************************************************************************/
void meaSeSetActiveObj(void)
{
    if (NULL == meaSeView)
    {
        return;
    }
    else if ((0 != meaSeView->imageGadgetHandle) &&
        MSF_WIDGET_HAS_FOCUS(meaSeView->imageGadgetHandle))
    {
        meaSeView->activeMediaObject = MEA_SE_GADGET_IMAGE;
    }
    else if ((meaSeView->imageInputHandle) && 
        MSF_WIDGET_HAS_FOCUS(meaSeView->imageInputHandle))
    {
        meaSeView->activeMediaObject = MEA_SE_GADGET_INP_IMAGE;
    }else if ((0 != meaSeView->textGadgetHandle) &&
        MSF_WIDGET_HAS_FOCUS(meaSeView->textGadgetHandle))
    {
        meaSeView->activeMediaObject = MEA_SE_GADGET_TEXT;
    }
    else if ((meaSeView->textInputHandle) && 
        MSF_WIDGET_HAS_FOCUS(meaSeView->textInputHandle))
    {
        meaSeView->activeMediaObject = MEA_SE_GADGET_INP_TEXT;
    } 
    else if ((0 != meaSeView->audioGadgetHandle) && 
        MSF_WIDGET_HAS_FOCUS(meaSeView->audioGadgetHandle))
    {
        meaSeView->activeMediaObject = MEA_SE_GADGET_AUDIO;
    }
    else if ((meaSeView->audioInputHandle) && 
        MSF_WIDGET_HAS_FOCUS(meaSeView->audioInputHandle))
    {
        meaSeView->activeMediaObject = MEA_SE_GADGET_INP_AUDIO;
    }
    else
    {
        meaSeView->activeMediaObject = MEA_SE_GADGET_NONE;
    }
}
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */

/*!
 * \brief Delets the main view for the SMIL editor.
 *****************************************************************************/
void meaSeDeleteEditorView(void)
{
    /* Gadgets */
    if (NULL != meaSeView)
    {
        cleanupGadgets();
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
        if (meaSeView->textHandle) 
        {
            (void)MSF_WIDGET_RELEASE(meaSeView->textHandle);
            meaSeView->textHandle = 0;
        }		
#endif /* WIDGET_ADVANCED_SMIL_EDIOT */
        /* Delete window and handles */    
        (void)meaDeleteWindow(meaSeView->formHandle);
        MEA_FREE(meaSeView);
        meaSeView = NULL;
    }
} /* meaSeDeleteEditorView */

/*!
 * \brief Set/unset busy state for the SMIL editor view.
 * 
 * All actions are blocked during a busy state, i.e., no End User input is
 * received.
 *
 * \param busy TRUE to set the form in a busy state, FALSE to set the form in
 *             a "normal" state again.
 *****************************************************************************/
void meaSeSetBusy(MSF_BOOL busy)
{
    if ((NULL != meaSeView) && (0 != meaSeView->formHandle))
    {
        if (busy)
        {
            /* Display the busy icon and do not allow any actions */
#ifdef WAP_SUPPORT
            (void)MSF_WIDGET_WINDOW_SET_PROPERTIES(meaSeView->formHandle, 
                EDITOR_PROPERTIES | /* MSF_WINDOW_PROPERTY_BUSY | */
                MSF_WINDOW_PROPERTY_DISABLED);
#else
            (void)MSF_WIDGET_WINDOW_SET_PROPERTIES(meaSeView->formHandle, 
                EDITOR_PROPERTIES | MSF_WINDOW_PROPERTY_BUSY | 
                MSF_WINDOW_PROPERTY_DISABLED);
#endif
        }
        else
        {
            /* Remove the busy icon and allow actions */
            (void)MSF_WIDGET_WINDOW_SET_PROPERTIES(meaSeView->formHandle, 
                EDITOR_PROPERTIES);
        }
    }
}

/*!
 * \brief Removes dynamicly created gadgets in the main SE view.
 *****************************************************************************/
static void cleanupGadgets(void)
{
    if (NULL != meaSeView)
    {
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
        HDIa_widgetExtSmilEditorUpdateImage(meaSeView->formHandle, 0);
        HDIa_widgetExtSmilEditorUpdateText(meaSeView->formHandle, 0);        
        if (meaSeView->textHandle) 
        {
            (void)MSF_WIDGET_RELEASE(meaSeView->textHandle);
            meaSeView->textHandle = 0;
        }
        HDIa_widgetExtSmilEditorUnsetFlag(meaSeView->formHandle, WIDGET_SMIL_EDITOR_FLAG_AUDIO);
        HDIa_widgetExtSmilEditorUnsetFlag(meaSeView->formHandle, WIDGET_SMIL_EDITOR_FLAG_ATTACHMENT);
#else
        /* Text input */
        if (0 != meaSeView->textInputHandle)
        {
            (void)MSF_WIDGET_REMOVE(meaSeView->formHandle,
                meaSeView->textInputHandle);
            (void)MSF_WIDGET_RELEASE(meaSeView->textInputHandle);
            meaSeView->textInputHandle = 0;
        }
        /* Image input */
        if (0 != meaSeView->imageInputHandle)
        {
            (void)MSF_WIDGET_REMOVE(meaSeView->formHandle,
                meaSeView->imageInputHandle);
            (void)MSF_WIDGET_RELEASE(meaSeView->imageInputHandle);
            meaSeView->imageInputHandle = 0;
        }
        /* Audio input */
        if (0 != meaSeView->audioInputHandle)
        {
            (void)MSF_WIDGET_REMOVE(meaSeView->formHandle,
                meaSeView->audioInputHandle);
            (void)MSF_WIDGET_RELEASE(meaSeView->audioInputHandle);
            meaSeView->audioInputHandle = 0;
        }
        /* Image */
        if (0 != meaSeView->imageGadgetHandle)
        {
            (void)MSF_WIDGET_REMOVE(meaSeView->formHandle,
                meaSeView->imageGadgetHandle);
            (void)MSF_WIDGET_RELEASE(meaSeView->imageGadgetHandle);
            meaSeView->imageGadgetHandle = 0;
        }
        /* Audio input */
        if (0 != meaSeView->audioGadgetHandle)
        {
            (void)MSF_WIDGET_REMOVE(meaSeView->formHandle,
                meaSeView->audioGadgetHandle);
            (void)MSF_WIDGET_RELEASE(meaSeView->audioGadgetHandle);
            meaSeView->audioGadgetHandle = 0;
        }
        /* Text */
        if (0 != meaSeView->textGadgetHandle)
        {
            (void)MSF_WIDGET_REMOVE(meaSeView->formHandle,
                meaSeView->textGadgetHandle);
            meaSeView->textGadgetHandle = 0;
            (void)mtrDeleteTextBox(meaSeView->textBoxInstance);
            meaSeView->textBoxInstance = -1;
            if (meaSeView->textHandle) 
            {
                (void)MSF_WIDGET_RELEASE(meaSeView->textHandle);
                meaSeView->textHandle = 0;
            }
        }
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */
    }
} /* cleanupGadgets */

#ifndef WIDGET_ADVANCED_SMIL_EDITOR
/*! Handles the gadget placement.
 *
 * \param handle The handle 
 * \param size The size of the gadget is written here.
 * \param pos The position tho place the gadget is written here.
 *****************************************************************************/
static void handleImgPlacement(MsfGadgetHandle handle, MsfSize *size, 
    MsfPosition *pos)
{
    MsfSize dSize;
    (void)MSF_WIDGET_GET_SIZE(handle, size);
    /* Calculate the position */
   (void)MSF_WIDGET_WINDOW_SPECIFIC_SIZE(meaSeView->formHandle, &dSize, 1);
    /* center horizontally */
    pos->x = (MSF_INT16)((MSF_UINT16)(dSize.width - size->width) >> 1);
}

/*! \brief Adjusts the text color so that it wont clash with the background 
 *         color.
 *
 * \param textColor The current text color from the default style.
 * \param bgColor The background color.
 *****************************************************************************/
static void adjustTextColor(MsfColor *textColor, const MsfColor *bgColor)
{
    int diff[3];
    unsigned int i;
    int level;
    diff[0] = textColor->r - bgColor->r;
    diff[1] = textColor->g - bgColor->g;
    diff[2] = textColor->b - bgColor->b;
    /* ABS */
    for (i = 0; i < 3; i++)
    {
        if (diff[i] < 0)
        {
            diff[i] = -diff[i];
        }
    }
    /* Check if the color is ok */
    for (i = 0; i < 3; i++)
    {
        if (MEA_MIN_COLOR_DIFF < diff[i])
        {
            /* This color is ok to display */
            return;
        }
    }
    /* Create a new color that can be displayed */

    /* Get the "brightness" level */
    level = (textColor->r + textColor->g + textColor->b)/3;
    /* Adjust level up or down */
    if ((level + 0x7f) <= 0xff)
    {
        level += 0x7f;
    }
    else
    {
        level -= 0x7f;
    }
    /* Create gray scale color with the caluclated color */
    textColor->r = textColor->g = textColor->b = level;
}

static void meaSeGetDisplaySize(MsfSize *ms)
{
    MsfDeviceProperties dp;
    (void)MSF_WIDGET_DEVICE_GET_PROPERTIES(&dp);
    *ms = dp.displaySize;
    ms->height = (MSF_INT16)(ms->height/2 -MEA_SE_OBJECT_PADDING);
}
#endif /* ~WIDGET_ADVANCED_SMIL_EDITOR */
#ifdef WAP_SUPPORT
//return true is SMIL editor is active. Check if previewing
MSF_BOOL meaSmilEditorIsActive(void)
{
    if (meaSeView)
        return (meaSeView->formHandle);
	return FALSE;
}
#else /* WAP_SUPPORT */
/*! Creates a cursor for the SMIL presentation
 *	
 * \param vertPos The vertical position to display the gadget.
 * \param size The size of the new gadget
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL displayInput(MsfGadgetHandle *gHandle, MsfColor *bgColor, 
    MSF_UINT32 strId, MSF_INT16 vertPos, MsfSize *size)
{
    MsfPosition pos;
    MsfSize dSize;
    MsfStyleHandle style;
    MsfColor textColor;
    MsfStringHandle strHandle;

    /* Check the color of the text */
    strHandle = MEA_GET_STR_ID(strId);
    /* Copy the handle in order to be able to change the style */
    if (0 == (strHandle = MSF_WIDGET_COPY(MSF_MODID_MEA, strHandle)))
    {
        return FALSE;
    }
    (void)MSF_WIDGET_GET_COLOR(strHandle, &textColor, 0);
    /* Make sure that the text color is not the same as the background color */
    adjustTextColor(&textColor, bgColor);
    (void)MSF_WIDGET_SET_COLOR(strHandle, &textColor, 0);

    if (0 == (style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_MEA, NULL, bgColor, 
        NULL, NULL, NULL, NULL, NULL)))
    {
        (void)MSF_WIDGET_RELEASE(strHandle);
        return FALSE;
    }
    if (0 == (*gHandle = MSF_WIDGET_STRING_GADGET_CREATE(MSF_MODID_MEA, 
        strHandle, NULL, TRUE, MSF_GADGET_PROPERTY_FOCUS, style)))
    {
        (void)MSF_WIDGET_RELEASE(strHandle);
        (void)MSF_WIDGET_RELEASE(style);
        return FALSE;
    }
    (void)MSF_WIDGET_RELEASE(strHandle);
    (void)MSF_WIDGET_RELEASE(style);
    
    if ((MSF_WIDGET_GET_SIZE(*gHandle, size) < 0) ||
        (MSF_WIDGET_WINDOW_SPECIFIC_SIZE(meaSeView->formHandle, &dSize, 1) < 0))
    {
        return FALSE;
    }
    pos.y = vertPos;
    pos.x = (MSF_INT16)((MSF_UINT16)(dSize.width - size->width)>>1);
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaSeView->formHandle, 
        *gHandle, &pos, 0))
    {
        return FALSE;
    }
    /* Everything went ok, return */
    return TRUE;
}

#endif /* WAP_SUPPORT */
#ifdef __DRM_SUPPORT__
MsfImageHandle createDrmImageHandle(MSF_INT32 fileHandle, MeaMediaType type)
{
    MsfImageHandle imageHandle=0;
    char * buffer = MEA_ALLOC(MEA_DRM_READ_CHUNK_SIZE);
    if ( buffer && fileHandle>=0)
    {
	while(1)
	{
		unsigned int readLength;
		memset(buffer, 0x00, MEA_DRM_READ_CHUNK_SIZE);
		if ((DRM_read_file(fileHandle, buffer, MEA_DRM_READ_CHUNK_SIZE, &readLength)) == FS_NO_ERROR) 
		{
			if (readLength < MEA_DRM_READ_CHUNK_SIZE)   /*End of File*/
			{
				if (imageHandle == 0)
				{
					/* no current image handle, create a new one */
					imageHandle = MSF_WIDGET_IMAGE_CREATE(MSF_MODID_MEA, 
					buffer, (int)readLength,
					(MsfImageFormat)meaConvertMediaTypeToMsf(type), 
					FALSE, 0);

					if (imageHandle == 0)
					{
						/* failed to create image handle */
						//DRM_close_file(fileHandle);
						return 0;
					} /* if */
				}
				else
				{
					/* Image handle already exists */
					if (MSF_WIDGET_IMAGE_NEXT_PART(imageHandle, buffer, 
						(int)readLength, FALSE) == -1)
					{
						/* failed to create the image */
						(void)MSF_WIDGET_RELEASE(imageHandle);
						imageHandle = 0;
						MEA_FREE(buffer);
						return 0;
					} /* if */
				} /* if */
				break;
			}
			else if (readLength == MEA_DRM_READ_CHUNK_SIZE) 
			{
				if (imageHandle ==0)
				{
					/* no current image handle, create a new one */
					imageHandle = MSF_WIDGET_IMAGE_CREATE(MSF_MODID_SMA, 
					buffer, (int)readLength,
					(MsfImageFormat)meaConvertMediaTypeToMsf(type), 
					TRUE, 0);

					if (imageHandle == 0)
					{
						/* failed to create image handle */
						MEA_FREE(buffer);
						return 0;
					} /* if */
				}
				else
				{
					/* Image handle already exists */
					if (MSF_WIDGET_IMAGE_NEXT_PART(imageHandle, buffer, 
						(int)readLength, TRUE) == -1)
					{
						/* failed to create the image */
						(void)MSF_WIDGET_RELEASE(imageHandle);
						imageHandle = 0;
						return 0;
					} /* if */
				} /* if */
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
        //DRM_close_file(fileHandle);
    }
    MEA_FREE(buffer);
    return imageHandle;        
}

/*! Displays a DRM image.
 *
 * \param mo The current drm(image type) object. or fileHandle the drm file handle
 * \param pos The position to display the gadget.
 * \param size (out) The size of the new gadget.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL displayDrmImage(const MeaMoDataItem *mo, MSF_UINT16 vertPos, 
    MsfSize *size, MeaMediaType type)
{
    MsfImageHandle imgHandle=0;
#ifndef WIDGET_ADVANCED_SMIL_EDITOR
    MsfSize dSize;
    MSF_UINT16 newHeight;
    MSF_UINT16 newWidth;
    MsfPosition pos;
#endif /* ~WIDGET_ADVANCED_SMIL_EDITOR */

    if (0 == (imgHandle = mo->reshandle))
    {
        /* Create */
        imgHandle = MEA_GET_IMG_ID(MEA_IMG_IMAGE_ERROR);
    }
#ifdef WIDGET_PRECACHE_IMAGE
    HDIa_widgetExtEnablePreCacheImage(imgHandle);
#endif /* WIDGET_PRECACHE_IMAGE */
#ifdef WIDGET_ANIMATION_ON_SMIL_PLAYING
    HDIa_widgetExtDisableImageAnimation(imgHandle);
#endif /* WIDGET_ANIMATION_ON_SMIL_PLAYING */
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    HDIa_widgetExtSmilEditorUpdateImage(meaSeView->formHandle, imgHandle);
	meaSeView->imageHandle = imgHandle;
#else
    /* Handle the image scaling */
    (void)MSF_WIDGET_GET_SIZE(imgHandle, size);
    meaSeGetDisplaySize(&dSize);
    if (size->height > dSize.height)
    {
        newHeight = (MSF_UINT16)(dSize.height);
        size->width = (MSF_INT16)((size->width * newHeight) / (size->height)); //shrink width
        size->height = (MSF_INT16)newHeight;
    }
    /* Check if the image can fit horizontally on the display  */
    if (size->width > dSize.width - 2 * MEA_SE_OBJECT_PADDING)
    {
        /* Scale using the same aspect */
        newWidth = (MSF_UINT16)(dSize.width - 2 * MEA_SE_OBJECT_PADDING);
        size->height = (MSF_INT16)((size->height * newWidth) / size->width);
        size->width = (MSF_INT16)newWidth;
    }
    /* Image position */
    pos.x = (MSF_INT16)((MSF_UINT16)(dSize.width - size->width) >> 1);
    pos.y = (MSF_INT16)vertPos;

    /* Display the image */
    if (0 == (meaSeView->imageGadgetHandle = 
        MSF_WIDGET_IMAGE_GADGET_CREATE(MSF_MODID_MEA, imgHandle, size, 
        MsfImageZoomAutofit, MSF_GADGET_PROPERTY_FOCUS, 0)))
    {
        if (0 != imgHandle)
        {
            (void)MSF_WIDGET_RELEASE(imgHandle);
        }
        return FALSE;
    }
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaSeView->formHandle, 
        meaSeView->imageGadgetHandle, &pos, 0))
    {
        return FALSE;
    }
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */
    return TRUE;
}

static MSF_BOOL displayDrmBrokenImage(MSF_UINT16 vertPos, MsfSize *size)
{
    MsfImageHandle imgHandle=0;
#ifndef WIDGET_ADVANCED_SMIL_EDITOR
    MsfSize dSize;
    MSF_UINT16 newHeight;
    MSF_UINT16 newWidth;
    MsfPosition pos;
#endif /* ~WIDGET_ADVANCED_SMIL_EDITOR */
    /* Create */
    imgHandle = MEA_GET_IMG_ID(MEA_IMG_IMAGE_ERROR);
#ifdef WIDGET_PRECACHE_IMAGE
    HDIa_widgetExtEnablePreCacheImage(imgHandle);
#endif /* WIDGET_PRECACHE_IMAGE */
#ifdef WIDGET_ANIMATION_ON_SMIL_PLAYING
    HDIa_widgetExtDisableImageAnimation(imgHandle);
#endif /* WIDGET_ANIMATION_ON_SMIL_PLAYING */
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    HDIa_widgetExtSmilEditorUpdateImage(meaSeView->formHandle, imgHandle);
#else
    /* Handle the image scaling */
    (void)MSF_WIDGET_GET_SIZE(imgHandle, size);
    meaSeGetDisplaySize(&dSize);
    if (size->height > dSize.height)
    {
        newHeight = (MSF_UINT16)(dSize.height);
        size->width = (MSF_INT16)((size->width * newHeight) / (size->height)); //shrink width
        size->height = (MSF_INT16)newHeight;
    }
    /* Check if the image can fit horizontally on the display  */
    if (size->width > dSize.width - 2 * MEA_SE_OBJECT_PADDING)
    {
        /* Scale using the same aspect */
        newWidth = (MSF_UINT16)(dSize.width - 2 * MEA_SE_OBJECT_PADDING);
        size->height = (MSF_INT16)((size->height * newWidth) / size->width);
        size->width = (MSF_INT16)newWidth;
    }
    /* Image position */
    pos.x = (MSF_INT16)((MSF_UINT16)(dSize.width - size->width) >> 1);
    pos.y = (MSF_INT16)vertPos;

    /* Display the image */
    if (0 == (meaSeView->imageGadgetHandle = 
        MSF_WIDGET_IMAGE_GADGET_CREATE(MSF_MODID_MEA, imgHandle, size, 
        MsfImageZoomAutofit, MSF_GADGET_PROPERTY_FOCUS, 0)))
    {
        if (0 != imgHandle)
        {
            (void)MSF_WIDGET_RELEASE(imgHandle);
        }
        return FALSE;
    }
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaSeView->formHandle, 
        meaSeView->imageGadgetHandle, &pos, 0))
    {
        return FALSE;
    }
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */
    return TRUE;
}
#endif /* __DRM_SUPPORT__ */

/*! Displays an image.
 *
 * \param objInfo The image object.
 * \param pos The position to display the gadget.
 * \param size (out) The size of the new gadget.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL displayImage(const MeaObjInfo *objInfo, MSF_UINT16 vertPos, 
    MsfSize *size)
{
    MsfImageHandle imgHandle = 0;
#ifndef WIDGET_ADVANCED_SMIL_EDITOR
    MsfSize dSize;
    MSF_UINT16 newWidth;
    MsfPosition pos;
#ifdef WAP_SUPPORT
    MSF_UINT16 newHeight;
#endif /* WAP_SUPPORT */
#endif /* ~WIDGET_ADVANCED_SMIL_EDITOR */

    /* Check if there is a valid picture to display */
    if(0 != (imgHandle = objInfo->object->reshandle))
    {
        {
            (void)MSF_WIDGET_GET_SIZE(imgHandle, size);
#ifdef WAP_SUPPORT //check if failed to shrink image
            if ((size->width == 0) || (size->height == 0))
            {
                (void)MSF_WIDGET_RELEASE(imgHandle);
                imgHandle = 0;
                objInfo->object->reshandle = 0;
            }
#else
            /* Check that the image is not too large */
            if ((size->width > MEA_SE_MAX_IMAGE_WIDTH) || 
                (size->height > MEA_SE_MAX_IMAGE_HEIGHT))
            {
                (void)MSF_WIDGET_RELEASE(imgHandle);
                imgHandle = 0;
            }
#endif /* WAP_SUPPORT */
        }
    }
    /* Check if an icon should be displayed instead */
    if (0 == imgHandle)
    {
        /* Create */
        imgHandle = MEA_GET_IMG_ID(MEA_IMG_IMAGE_ERROR);
    }
#ifdef WIDGET_PRECACHE_IMAGE
    HDIa_widgetExtEnablePreCacheImage(imgHandle);
#endif /* WIDGET_PRECACHE_IMAGE */
#ifdef WIDGET_ANIMATION_ON_SMIL_PLAYING
    HDIa_widgetExtDisableImageAnimation(imgHandle);
#endif /* WIDGET_ANIMATION_ON_SMIL_PLAYING */
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    HDIa_widgetExtSmilEditorUpdateImage(meaSeView->formHandle, imgHandle);
	meaSeView->imageHandle = imgHandle;
#else
    /* Handle the image scaling */
    (void)MSF_WIDGET_GET_SIZE(imgHandle, size);
  #ifdef WAP_SUPPORT
    meaSeGetDisplaySize(&dSize);
    if (size->height > dSize.height)
    {
        newHeight = (MSF_UINT16)(dSize.height);
        size->width = (MSF_INT16)((size->width * newHeight) / (size->height)); //shrink width
        size->height = (MSF_INT16)newHeight;
    }
  #else
    meaGetDisplaySize(&dSize);
  #endif /* WAP_SUPPORT */
    /* Check if the image can fit horizontally on the display  */
    if (size->width > dSize.width - 2 * MEA_SE_OBJECT_PADDING)
    {
        /* Scale using the same aspect */
        newWidth = (MSF_UINT16)(dSize.width - 2 * MEA_SE_OBJECT_PADDING);
        size->height = (MSF_INT16)((size->height * newWidth) / size->width);
        size->width = (MSF_INT16)newWidth;
    }
    /* Image position */
    pos.x = (MSF_INT16)((MSF_UINT16)(dSize.width - size->width) >> 1);
    pos.y = (MSF_INT16)vertPos;

    /* Display the image */
    if (0 == (meaSeView->imageGadgetHandle = 
        MSF_WIDGET_IMAGE_GADGET_CREATE(MSF_MODID_MEA, imgHandle, size, 
        MsfImageZoomAutofit, MSF_GADGET_PROPERTY_FOCUS, 0)))
    {
        if (NULL != objInfo->object->data)
        {
            (void)MSF_WIDGET_RELEASE(imgHandle);
        }
        return FALSE;
    }
    /* Release the image handle */
    if (NULL != objInfo->object->data)
    {
        (void)MSF_WIDGET_RELEASE(imgHandle);
    }
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaSeView->formHandle, 
        meaSeView->imageGadgetHandle, &pos, 0))
    {
        return FALSE;
    }
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */
    return TRUE;
}


#ifdef WIDGET_ADVANCED_SMIL_EDITOR
/*! Displays a video.
 *
 * \param objInfo The video object.
 * \param pos The position to display the gadget.
 * \param size (out) The size of the new gadget.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL displayVideo(const MeaObjInfo *objInfo, MSF_UINT16 vertPos, MsfSize *size)
{
    MsfVideoHandle videoHandle = 0;

    /* Check if there is a valid picture to display */
    if(0 != (videoHandle = objInfo->object->reshandle))
    {
        (void)MSF_WIDGET_GET_SIZE(videoHandle, size);
        if ((size->width == 0) || (size->height == 0))
        {
            (void)MSF_WIDGET_RELEASE(videoHandle);
            videoHandle = 0;
            objInfo->object->reshandle = 0;
        }
    }
    
    /* Check if an icon should be displayed instead */
    if (0 == videoHandle)
    {
        videoHandle = MEA_GET_IMG_ID(MEA_IMG_VIDEO_ERROR);
    }
    else
    {
        MSF_WIDGET_EXT_DISABLE_VIDEO_PLAY(videoHandle);
    }
    
    HDIa_widgetExtSmilEditorUpdateImageEx(meaSeView->formHandle, videoHandle,TRUE);
    meaSeView->imageHandle = videoHandle;
    return TRUE;
}
#endif

/*! Displays a text gadget.
 *
 * \param objInfo The text object.
 * \param pos The position to display the gadget.
 * \param size (out) The size of the new gadget.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL displayText(MeaObjInfo *objInfo, MSF_INT16 vertPos, 
    MsfSize *size, const MsfColor *bgColor)
{
    MsfStringHandle strHandle;
#ifndef WIDGET_ADVANCED_SMIL_EDITOR
    MsfSize dSize;
    MsfPosition pos = {0, 0};
    MtrCreateRspData *rsp;
    MtrCreateTextBoxProperties prop;
    MsfColor fgColor;
	int endIndex;
#endif /* ~WIDGET_ADVANCED_SMIL_EDITOR */
    
    if ((NULL != objInfo->object->data) &&
        (MEA_MEDIA_TYPE_UNKNOWN != objInfo->object->content.type))
    {
        /* Create the string gadget */
        if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
            (char *)objInfo->object->data, MsfUtf8, 
            (int)strlen((char *)objInfo->object->data) + 1, 0)))
        {
            return FALSE;
        }

    }
    else
    {
        /* No text can be displayed, display a default text */
        strHandle = MEA_GET_STR_ID(MEA_STR_ID_TEXT_MISSING);
    }
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    HDIa_widgetExtSmilEditorUpdateText(meaSeView->formHandle, strHandle);
    if (meaSeView->textHandle) 
    {
        (void)MSF_WIDGET_RELEASE(meaSeView->textHandle);
    }
    meaSeView->textHandle = strHandle;
#else
    meaIntToMsfColor(objInfo->textColor, &fgColor);    
    /* Adjust color so that the text is going to be visible */
    adjustTextColor(&fgColor, bgColor);
    /* Make sure that color is written back if it should ha changed in the call
       to adjustTextColor 
     */
    objInfo->textColor = meaMsfToIntColor(&fgColor);
    
    /* Get the display size */
    if (MSF_WIDGET_WINDOW_SPECIFIC_SIZE(meaSeView->formHandle, &dSize, 1) 
        < 0)
    {
        return FALSE;
    }
    /* Set text box properties */
    memset(&prop, 0, sizeof(MtrCreateTextBoxProperties));
    /* Colors */
    memcpy(&prop.bgColor, bgColor, sizeof(MsfColor));
    memcpy(&prop.textColor, &fgColor, sizeof(MsfColor));
    //prop.alignment = MsfLeft;
    prop.alignment = MsfCenter;
    /* Calculate maximum size for text box */
    prop.size.height = (MSF_INT16)((MSF_UINT16)dSize.height >> 1);
    prop.size.width = (MSF_INT16)(dSize.width - 2 * MEA_SE_OBJECT_PADDING);
    prop.flags = 
        MTR_PROP_RENDER_LINKS | 
        MTR_PROP_VERTICAL_RESIZE | 
        MTR_PROP_HORIZONTAL_RESIZE |
        MTR_PROP_HIDE_CURSOR;
  #ifdef WAP_SUPPORT
	prop.size.height = (MSF_INT16)(prop.size.height * 2 / 3);
    endIndex = mtrGetTextBoxEndIndex(strHandle, &prop);
	//endIndex is length, not bytes
	if (endIndex > 0)
	{
	    char * endPos = msf_cmmn_utf8_str_incr((const char*)objInfo->object->data, endIndex);
		int strBytes;
		strBytes = endPos - (char*)objInfo->object->data;
		if (strBytes > 0)
		{
	        char * displayedText = MEA_ALLOC(strBytes + 1);
		    MSF_WIDGET_RELEASE(strHandle);
			endPos = msf_cmmn_utf8_str_incr((const char*)objInfo->object->data, endIndex-strlen("..."));
			strBytes = endPos-(char*)objInfo->object->data;
			strncpy(displayedText, (char*)objInfo->object->data, strBytes);
			strncpy(displayedText + strBytes, "...", strlen("..."));
			memset(displayedText + strBytes + strlen("..."), 0, 1);
	        /* Create the string gadget */
	        if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
	            (char *)displayedText, MsfUtf8, endIndex + 1, 0)))
	        {
	            return FALSE;
	        }
			MEA_FREE(displayedText);
		}
	}
  #endif /*WAP_SUPPORT */

    if (MTR_RESULT_OK != mtrCreateTextBox(strHandle, &prop, &rsp)) 
    {
        (void)MSF_WIDGET_RELEASE(strHandle);
        return FALSE;
    }
    meaSeView->textBoxInstance = rsp->instance;
    meaSeView->textGadgetHandle = rsp->gadgetHandle;
    meaSeView->textHandle = strHandle;
    size->height = rsp->gadgetSize.height;
    size->width = rsp->gadgetSize.width;
    /* Image position */
    pos.x = (MSF_INT16)((MSF_UINT16)(dSize.width - rsp->gadgetSize.width) >> 1);
    pos.y = vertPos;

    (void)meaRegisterNotification(rsp->gadgetHandle, MsfNotifyFocus, 0, 
        MEA_SE_FSM, MEA_SIG_SE_GADGET_GOT_FOCUS);
    (void)meaRegisterNotification(rsp->gadgetHandle, MsfNotifyLostFocus, 0, 
        MEA_SE_FSM, MEA_SIG_SE_GADGET_LOST_FOCUS);
    
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaSeView->formHandle, 
        rsp->gadgetHandle, &pos, 0))
    {
        return FALSE;
    }
    mtrFreeMtrCreateRspData(&rsp);
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */
    return TRUE;
}


/*! Displays a "sound" gadget.
 *
 * \param pos The position to display the gadget.
 * \param size (out) The size of the new gadget.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL displayAudioIcon(MSF_INT16 vertPos, MsfSize *size)
{
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    HDIa_widgetExtSmilEditorSetFlag(meaSeView->formHandle, WIDGET_SMIL_EDITOR_FLAG_AUDIO);
#else
    MsfPosition pos;
    MsfImageHandle imgHandle;

    /* Get the image */
    imgHandle = MEA_GET_IMG_ID(MEA_IMG_AUDIO);
    /* Handle the layout */
    handleImgPlacement(imgHandle, size, &pos);
    pos.y = vertPos;
    /* Create the gadget */
    if (0 == (meaSeView->audioGadgetHandle = 
        MSF_WIDGET_IMAGE_GADGET_CREATE(MSF_MODID_MEA, imgHandle, NULL, 
        MsfImageZoom100, MSF_GADGET_PROPERTY_FOCUS | 
        MSF_GADGET_PROPERTY_ALWAYSONTOP, 0)))
    {
        return FALSE;
    }
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaSeView->formHandle, 
        meaSeView->audioGadgetHandle, &pos, NULL))
    {
        return FALSE;
    }
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */
    return TRUE;
}

/*!
 * \brief Displayes a slide.
 *
 * \param smilInfo The information about the SMIL presentation.
 * \param propItem The current message properties.
 * \return TRUE if the slide was displayed successfully, otherwise FALSE.
 *****************************************************************************/
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
MSF_BOOL meaSeShowSlide(const MeaSmilInfo *smilInfo, const MeaPropItem *propItem)
{
    MsfColor     bgColor;
    MsfSize      size = {0, 0};
    MsfPosition  pos = {0, 5};
    MeaMediaGroupType objectInserted = MEA_MEDIA_GROUP_NONE, topObject = MEA_MEDIA_GROUP_NONE;
    unsigned int i;
    MeaSmilSlide *sSlide = NULL;

    (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_DEACTIVATE);
    if (NULL == meaSeView || NULL == smilInfo || (sSlide = meaGetCurrentSlide(smilInfo)) == NULL)
    {
        return FALSE;
    }

    /* Remove old gadgets and window bindings */
    cleanupGadgets();
    seSetTitle(propItem->subject, 
        meaGetSlideIndex(smilInfo, sSlide), meaGetSlideCount(smilInfo), 
        meaCalculateMsgSize(smilInfo, propItem));
    topObject = meaGetLayoutOrder(smilInfo);

    /* Set the background color */
    if (SLS_COLOR_NOT_USED != smilInfo->bgColor)
    {
        meaIntToMsfColor(smilInfo->bgColor, &bgColor);
    }
    else
    {
        meaIntToMsfColor(MEA_CFG_DEFAULT_SMIL_BG_COLOR, &bgColor);
    }
    (void)MSF_WIDGET_SET_COLOR(meaSeView->formHandle, &bgColor, 1);

    /* Create new gadgets */
    for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)
    {
        if (NULL != sSlide->objects[i])
        {
            switch(meaMediaType2ObjType(sSlide->objects[i]->object->content.type))
            {
            case MEA_MEDIA_GROUP_IMAGE:
                if (!displayImage(sSlide->objects[i], (MSF_UINT16)pos.y, &size))
                {
                    cleanupGadgets();
                    return FALSE;
                }
                objectInserted |= MEA_MEDIA_GROUP_IMAGE;
                break;

            case MEA_MEDIA_GROUP_VIDEO:
                if (!displayVideo(sSlide->objects[i], (MSF_UINT16)pos.y, &size))
                {
                    cleanupGadgets();
                    return FALSE;
                }
                objectInserted |= MEA_MEDIA_GROUP_VIDEO;
                break;
                
            case MEA_MEDIA_GROUP_TEXT:
                if (!displayText(sSlide->objects[i], pos.y, &size, &bgColor))
                {
                    cleanupGadgets();
                    return FALSE;
                }
                objectInserted |= MEA_MEDIA_GROUP_TEXT;
                break;
                
            case MEA_MEDIA_GROUP_AUDIO:
                if (!displayAudioIcon(pos.y, &size))
                {
                    cleanupGadgets();
                    return FALSE;
                }
                break;
                
#ifdef __DRM_SUPPORT__
            case MEA_MEDIA_GROUP_DRM:
            {
                MeaMoDataItem *item = sSlide->objects[i]->object;
                unsigned char *externalFileName = NULL;
                MSF_INT32 fileHandle = 0;

                if(item->content.drmType == MEA_MEDIA_TYPE_UNKNOWN)
                {
                    externalFileName = HDI_FileNameTranslate(item->name);
                    fileHandle = DRM_open_file((kal_wchar*)externalFileName, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
                    HDI_FileNameFree(externalFileName);
                    if (fileHandle > 0)
                    {
                        item->content.drmType = meaMime2MediaType((char*)DRM_get_content_type(fileHandle, NULL));
                        DRM_close_file(fileHandle);
                    }
                    else
                    {
                        /* Display the broken image */
                        displayDrmBrokenImage((MSF_UINT16)pos.y, &size);
                        break;
                    }
                }

                switch (meaMediaType2ObjType(item->content.drmType))
                {
                case MEA_MEDIA_GROUP_IMAGE:
                    if (!displayDrmImage(item, (MSF_UINT16)pos.y, &size, item->content.drmType))
                    {
                        cleanupGadgets();
                        return FALSE;
                    }
                    objectInserted |= MEA_MEDIA_GROUP_IMAGE;
                    break;

                case MEA_MEDIA_GROUP_VIDEO:
                    if (!displayVideo(sSlide->objects[i], (MSF_UINT16)pos.y, &size))
                    {
                        cleanupGadgets();
                        return FALSE;
                    }
                    objectInserted |= MEA_MEDIA_GROUP_VIDEO;
                    break;

                case MEA_MEDIA_GROUP_TEXT:
                    WAP_DBG_ASSERT(0);
                    break;

                case MEA_MEDIA_GROUP_AUDIO:
                    if (!displayAudioIcon(pos.y, &size))
                    {
                        cleanupGadgets();
                        return FALSE;
                    }
                    break;
                }
                break;
            }
#endif /* __DRM_SUPPORT__ */
            case MEA_MEDIA_GROUP_NONE:
            default:
                break;
            }
            pos.y = (MSF_INT16)(pos.y + size.height + MEA_SE_OBJECT_PADDING);
        }
    }
    /* Create "insert" alternatives */

    if(objectInserted & MEA_MEDIA_GROUP_IMAGE || objectInserted & MEA_MEDIA_GROUP_VIDEO)
    {
        if(topObject != MEA_MEDIA_GROUP_TEXT)
		    HDIa_widgetExtSmilEditorUnsetFlag(meaSeView->formHandle, 
			    WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM);
        else
		    HDIa_widgetExtSmilEditorSetFlag(meaSeView->formHandle, 
			    WIDGET_SMIL_EDITOR_FLAG_IMAGE_ON_BOTTOM);
    }
    
    if (meaSeGetAttachmentNo() > 0)
    {
        HDIa_widgetExtSmilEditorSetFlag(meaSeView->formHandle, WIDGET_SMIL_EDITOR_FLAG_ATTACHMENT);
    }
    return TRUE;
} /* meaSeShowSlide */
#else

MSF_BOOL meaSeShowSlide(const MeaSmilInfo *smilInfo, 
    const MeaPropItem *propItem)
{
    MsfColor     bgColor;
    MsfSize      size = {0, 0};
#ifdef WAP_SUPPORT
    MsfPosition  pos = {0, 5};
#else
    MsfPosition  pos = {0, 0};
#endif /*WAP_SUPPORT*/
    unsigned int i;
    MeaSmilSlide *sSlide = meaGetCurrentSlide(smilInfo);
#ifdef WAP_SUPPORT
    (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_DEACTIVATE);
#else
    MeaMediaGroupType visibleObjs;
#endif /* WAP_SUPPORT */
    if (NULL == meaSeView)
    {
#if defined(WAP_SUPPORT) && !defined(WIDGET_ADVANCED_SMIL_EDITOR)
        if (!meaSeCreateEditorView())
#endif /* defined(WAP_SUPPORT) && !defined(WIDGET_ADVANCED_SMIL_EDITOR) */
        return FALSE;
    }
    /* Remove old gadgets and window bindings */
    cleanupGadgets();
    seSetTitle(propItem->subject, 
        meaGetSlideIndex(smilInfo, sSlide), meaGetSlideCount(smilInfo), 
        meaCalculateMsgSize(smilInfo, propItem));
    /* Set the background color */
    if (SLS_COLOR_NOT_USED != smilInfo->bgColor)
    {
        meaIntToMsfColor(smilInfo->bgColor, &bgColor);
    }
    else
    {
        meaIntToMsfColor(MEA_CFG_DEFAULT_SMIL_BG_COLOR, &bgColor);
    }
    
    (void)MSF_WIDGET_SET_COLOR(meaSeView->formHandle, &bgColor, 1);
    /* Create new gadgets */
    for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)
    {
        if (NULL != sSlide->objects[i])
        {
            switch(meaMediaType2ObjType(sSlide->objects[i]->object->content.type))
            {
            case MEA_MEDIA_GROUP_IMAGE:
                if (!displayImage(sSlide->objects[i], (MSF_UINT16)pos.y, &size))
                {
                    cleanupGadgets();
                    return FALSE;
                }
                break;
            case MEA_MEDIA_GROUP_TEXT:
                if (!displayText(sSlide->objects[i], pos.y, &size, &bgColor))
                {
                    cleanupGadgets();
                    return FALSE;
                }
                break;
            case MEA_MEDIA_GROUP_AUDIO:
                if (!displayAudioIcon(pos.y, &size))
                {
                    cleanupGadgets();
                    return FALSE;
                }
                break;
#ifdef __DRM_SUPPORT__
            case MEA_MEDIA_GROUP_DRM:
            {
                MeaMoDataItem * item = sSlide->objects[i]->object;
                unsigned char *externalFileName = NULL;
                MSF_INT32 fileHandle;
                externalFileName = HDI_FileNameTranslate(item->name);
                fileHandle = DRM_open_file((kal_wchar*)externalFileName, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
                HDI_FileNameFree(externalFileName);
                if (fileHandle > 0)
                {
                    //MeaMediaType objType = meaDrm2MediaType(item->name);
		            MeaMediaType objType = meaMime2MediaType((char*)DRM_get_content_type(fileHandle, NULL));
                    switch (meaMediaType2ObjType(objType))
                    {
                    case MEA_MEDIA_GROUP_IMAGE:
                        if (!displayDrmImage(item, (MSF_UINT16)pos.y, &size, objType))
                        {
                            cleanupGadgets();
                            DRM_close_file(fileHandle);
                            return FALSE;
                        }
                        break;
                    case MEA_MEDIA_GROUP_TEXT:
						WAP_DBG_ASSERT(0);
                        break;
                    case MEA_MEDIA_GROUP_AUDIO:
                        if (!displayAudioIcon(pos.y, &size))
                        {
                            cleanupGadgets();
                            DRM_close_file(fileHandle);
                            return FALSE;
                        }
                        break;
                    } //end switch
                    DRM_close_file(fileHandle);
                }
				else
				{
					/* Display the broken image */
					displayDrmBrokenImage((MSF_UINT16)pos.y, &size);
                }
                break;
            }
#endif /* __DRM_SUPPORT__ */
            case MEA_MEDIA_GROUP_NONE:
            default:
                break;
            }
            pos.y = (MSF_INT16)(pos.y + size.height + MEA_SE_OBJECT_PADDING);
        }
    }
    /* Create "insert" alternatives */
#ifdef WAP_SUPPORT
    MSF_WIDGET_SET_TITLE(meaSeView->backActHandle, MEA_GET_STR_ID(MEA_STR_ID_DONE));  
#endif /* WAP_SUPPORT */
    return TRUE;
} /* meaSeShowSlide */

void meaSeFocusObject(MeaMediaGroupType type)
{
    MsfGadgetHandle focus = 0;
    switch (type)
    {
    case MEA_MEDIA_GROUP_TEXT:
        focus = meaSeView->textGadgetHandle;
        break;
    case MEA_MEDIA_GROUP_IMAGE:
        focus = meaSeView->imageGadgetHandle;
        break;
    case MEA_MEDIA_GROUP_AUDIO:
        focus = meaSeView->audioGadgetHandle;
        break;
    }
    
    if (focus) 
    {
        (void)MSF_WIDGET_SET_IN_FOCUS(focus, 1);
    }
}
#endif  /* WIDGET_ADVANCED_SMIL_EDITOR */

/*! \brief 
 *
 * \return The type of media that is currently "selected", or 
 *         MEA_MEDIA_GROUP_NONE if no object is selected.
 *****************************************************************************/
MeaMediaGroupType meaSeGetActiveObjType(void)
{
    switch(meaSeGetActiveGadget())
    {
    case MEA_SE_GADGET_IMAGE:
    case MEA_SE_GADGET_INP_IMAGE:
        return MEA_MEDIA_GROUP_IMAGE;
    case MEA_SE_GADGET_TEXT:
    case MEA_SE_GADGET_INP_TEXT:
        return MEA_MEDIA_GROUP_TEXT;
    case MEA_SE_GADGET_AUDIO:
    case MEA_SE_GADGET_INP_AUDIO:
        return MEA_MEDIA_GROUP_AUDIO;
    case MEA_SE_GADGET_NONE:
    default:
        return MEA_MEDIA_GROUP_NONE;
    }
}

/*! \brief 
 *
 * \return The type of media that is currently "selected", or 
 *         MEA_MEDIA_GROUP_NONE if no object is selected.
 *****************************************************************************/
void meaSeHandleEvent(MsfEventType event)
{
    MSF_BOOL lostFocus;
    
    if (NULL == meaSeView)
    {
        return;
    }

    if (MsfKey_Down == event || MsfKey_Up == event)
    {
        (void)mtrRedraw(meaSeView->textBoxInstance, event, &lostFocus);
        if (lostFocus) 
        {
            (void)meaDeleteUserEvent(meaSeView->formHandle, MsfKey_Down);
            (void)meaDeleteUserEvent(meaSeView->formHandle, MsfKey_Up);        
        }        
    }
}

/*! \brief 
 *
 * \return The type of media that is currently "selected", or 
 *         MEA_MEDIA_GROUP_NONE if no object is selected.
 *****************************************************************************/
void meaSeHandleNotif(MsfNotificationType notif)
{
    if (NULL == meaSeView)
    {
        return;
    }
#ifndef WAP_SUPPORT

    if (MsfNotifyFocus == notif) 
    {
        /* Register user events */
        (void)meaRegisterUserEvent(meaSeView->formHandle, MsfKey_Down, NULL, 
            MEA_SE_FSM, MEA_SIG_SE_EVENT_KEY_DOWN);
        (void)meaRegisterUserEvent(meaSeView->formHandle, MsfKey_Up, NULL, 
            MEA_SE_FSM, MEA_SIG_SE_EVENT_KEY_UP);
    }
    else if (MsfNotifyLostFocus == notif)
    {
        (void)meaDeleteUserEvent(meaSeView->formHandle, MsfKey_Down);
        (void)meaDeleteUserEvent(meaSeView->formHandle, MsfKey_Up);        
    }
#endif /*~WAP_SUPPORT*/
}

