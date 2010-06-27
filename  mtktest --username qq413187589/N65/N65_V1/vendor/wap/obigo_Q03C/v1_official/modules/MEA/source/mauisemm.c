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

/* !\file mauisemm.c
 *  \brief The main menu for the SMIL editor.
 */

/* MSF */
#ifdef WAP_SUPPORT
#include "msf_core.h"
#include "msf_cmmn.h"
#endif /* WAP_SUPPORT */
#include "msf_mem.h"
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_lib.h"
#include "msf_mem.h"

/* MMS */
#include "mms_def.h"

/* BRA */
#include "bra_if.h"

/* MEA */
#include "mea_def.h"
#include "matypes.h"
#include "mea_cfg.h"
#include "mea_rc.h"
#include "maintsig.h"
#include "mase.h"
#include "mamr.h"
#include "mame.h"
#include "mauise.h"
#include "mauimenu.h"
#include "mauicmn.h"
#include "mauiform.h"
#include "mauisemm.h"
#ifdef WAP_SUPPORT
#include "maconf.h" //for meaSaveOnSendSet
#include "mase.h"   //for meaGetCurrentSlideObjectDef
#include "mamem.h"
#include "mauisig.h"
#include "mauidia.h"

#include "widget_extension.h"
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void navMenuSignalConverter(MeaNavAction actionType);
#ifdef WAP_SUPPORT
static int createMenuItems(int slideCount, int initiated, int slideIndex);
#else
static int createMenuItems(int slideCount, int initiated, MeaMeStartupMode mode);
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Function implementation
 *****************************************************************************/

static MeaSeAttachmentListView seAttachmentListView;
void meaSeMmUiInit(void)
{
    memset(&seAttachmentListView, 0, sizeof(MeaSeAttachmentListView));
}

static void meaSeEditAttachment(MsfWindowHandle winHandle)
{
    MSF_INT32 index = meaGetSelectedChoiceIndex(winHandle);
    MEA_SIGNAL_SENDTO_UU(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, MEA_MEDIA_GROUP_ATTACHMENT, index);
}

static void meaSeRemoveAttachment(MsfWindowHandle winHandle)
{
    MSF_INT32 index = meaGetSelectedChoiceIndex(winHandle);
    meaSeRemoveAttachmentByIndex(index);
    meaShowSlideForAttachment();
}

static void meaSeRemoveAttachmentListView(MsfWindowHandle winHandle)
{
    (void)meaDeleteWindow(seAttachmentListView.menuHandle);
    memset(&seAttachmentListView, 0, sizeof(MeaSeAttachmentListView));
}

void meaSeCreateAttachmentListView(int action)
{
    MsfActionHandle actionHandle;
    MeaActionCallBack callback = NULL;
    MSF_UINT32 title = 0;

    if (action != MEA_SE_EDIT_ATTACHMENT && action != MEA_SE_REMOVE_ATTACHMENT)
    {
        return;
    }

    callback = (action == MEA_SE_EDIT_ATTACHMENT) ? meaSeEditAttachment : meaSeRemoveAttachment;
    title = (action == MEA_SE_EDIT_ATTACHMENT) ? MEA_STR_ID_EDIT_ATTACHMENT : MEA_STR_ID_REMOVE_ATTACHMENT;
    /* Check that this view is not already active */
    if (0 != seAttachmentListView.menuHandle)
    {
        return;
    }
    else if (0 == (actionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_OK), 
        MsfSelect, 0, MSF_ACTION_PROPERTY_ENABLED)))
    {
        return;
    }
    else if (0 == (seAttachmentListView.menuHandle = MSF_WIDGET_MENU_CREATE(MSF_MODID_MEA, 
        MsfImplicitChoice, NULL, actionHandle, NULL, 
        MSF_CHOICE_ELEMENT_IMAGE_1 | MSF_CHOICE_ELEMENT_IMAGE_2 | 
        MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_STRING_2, 
        MSF_WINDOW_PROPERTY_TITLE | MSF_WINDOW_PROPERTY_SCROLLBARVER, 0)))
    {
        (void)MSF_WIDGET_RELEASE(actionHandle);
        return;
    }
    else if (!meaRegisterAction(seAttachmentListView.menuHandle, actionHandle, callback, MEA_NOTUSED_FSM, 0))  /*  LSK: Ok */
    {
        (void)MSF_WIDGET_RELEASE(actionHandle);
        meaSeRemoveAttachmentListView(seAttachmentListView.menuHandle);
        return;
    }
    else if (0 == meaCreateAction(seAttachmentListView.menuHandle, MsfBack, meaSeRemoveAttachmentListView, 
        MEA_NOTUSED_FSM, 0, MEA_STR_ID_BACK))  /*  RSK: Back */
    {
        meaSeRemoveAttachmentListView(seAttachmentListView.menuHandle);  /* actionHandle'd be released in it */
        return;
    }
    else
    {
        attachmentObjectList *list = meaGetAttachmentList();
        attachmentObjectList *ptr = list;
		int i = 0;
        while (ptr != NULL)
        {
            /* Add content to the list*/
            MsfStringHandle strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, (char *)ptr->filename, MsfUtf8, 
                                                                 (int)strlen((char *)ptr->filename) + 1, 0);
    		if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(seAttachmentListView.menuHandle, i, strHandle, 0, 
                meaGetListNumImage(i), 0, TRUE))
            {
                meaSeRemoveAttachmentListView(seAttachmentListView.menuHandle);
                (void)MSF_WIDGET_RELEASE(strHandle);
                return;
            }
            i++;
            ptr = ptr->next;
            (void)MSF_WIDGET_RELEASE(strHandle);
        }

        meaSetTitle(seAttachmentListView.menuHandle, MEA_GET_STR_ID(title), 0);
        meaDisplayWindow(seAttachmentListView.menuHandle, meaGetPosLeftTop());
    }
}

#ifdef WIDGET_ADVANCED_SMIL_EDITOR
static void meaSeInputMethodDeactivate(void)
{
    (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_DEACTIVATE);
    (void)MSF_WIDGET_SET_IN_FOCUS(meaSeGetFormHandle(), TRUE);
}

/*!
 * \brief Creates menu items for the navigation menu for the SE.
 *
 * \param slideCount The total number of slides.
 * \param initiated TRUE if the current slide has any media objects attached,
 *                  otherwise FALSE.
 * \param mode The current startup mode, see #MeaMeStartupMode.
 * \return TRUE on OK else FALSE
 *****************************************************************************/
static int createMenuItems(int slideCount, int initiated, int slideIndex)
{
	MeaMediaGroupType visibleObjs = meaGetCurrentSlideObjectDef();

    /* DONE */
    if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DONE), MEA_SE_BACK))
    {
        return FALSE;
    }	
    
    /* INPUT METHOD */
    if (!meaAddNavMenuItem(MEA_GET_STR_ID(WIDGET_STR_ID_INPUT_METHOD), MEA_SE_INPUT_METHOD))
    {
        return FALSE;
    }

    /* Add Image, Edit Image, Remove Image */
    if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_IMAGE), MEA_SE_ADD_IMAGE))
    {
        return FALSE;
    }

    if (MEA_MEDIA_GROUP_IMAGE & visibleObjs)
    {
        if ((!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_EDIT_IMAGE), MEA_SE_EDIT_IMAGE)) 
        	|| (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REMOVE_IMAGE), MEA_SE_REMOVE_IMAGE)))
            return FALSE;	
    }

    /* Add Audio, Edit Audio, Remove Audio */
    if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_AUDIO), MEA_SE_ADD_AUDIO))
    {
        return FALSE;
    }

    if (MEA_MEDIA_GROUP_AUDIO & visibleObjs)
    {
        if ((!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_EDIT_AUDIO), MEA_SE_EDIT_AUDIO))
        	|| (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REMOVE_AUDIO), MEA_SE_REMOVE_AUDIO)))
            return FALSE;
    }

    /* Add Video, Edit Video, Remove Video */
#if defined(MJPG_SUPPORT) || defined(MP4_CODEC)
    if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_VIDEO), MEA_SE_ADD_VIDEO))
    {
        return FALSE;
    }
    
    if (MEA_MEDIA_GROUP_VIDEO & visibleObjs)
    {
        if ((!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_EDIT_VIDEO), MEA_SE_EDIT_VIDEO)) 
        	|| (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REMOVE_VIDEO), MEA_SE_REMOVE_VIDEO)))
            return FALSE;	
    }
#endif /*defined(MJPG_SUPPORT) || defined(MP4_CODEC)*/
    /* ADD ATTACHMENT */
    if (meaSeGetAttachmentNo() < MEA_MAX_ATTACHMENT_NO)
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_ATTACHMENT), MEA_SE_ADD_ATTACHMENT))
        {
            return FALSE;
        }
    }

    /* EDIT/REMOVE ATTACHMENT */
    if (meaSeGetAttachmentNo() > 0)
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_EDIT_ATTACHMENT), MEA_SE_EDIT_ATTACHMENT))
        {
            return FALSE;
        }
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REMOVE_ATTACHMENT), MEA_SE_REMOVE_ATTACHMENT))
        {
            return FALSE;
        }
    }

    /* INSERT SLIDE */
    if (initiated)
    {
#if MEA_CFG_INSERT_SLIDE_OPTION == 1
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_SLIDE_BEFORE), MEA_SE_ADD_SLIDE_BEFORE))
        {
            return FALSE;
        }
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_SLIDE_AFTER), MEA_SE_ADD_SLIDE_AFTER))
        {
            return FALSE;
        }
#else
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_INSERT_SLIDE), MEA_SE_INSERT_PAGE))
        {
            return FALSE;
        }
#endif
    }

    /* DELETE SLIDE */
    if (slideCount > 1)
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE_SLIDE), MEA_SE_DELETE_SLIDE))
        {
            return FALSE;
        }
        if (slideIndex)
        {
            if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_PREVIOUS_SLIDE), MEA_SE_PREVIOUS_SLIDE))
                return FALSE;
        }
        if (slideIndex < slideCount - 1)
        {
            if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_NEXT_SLIDE), MEA_SE_NEXT_SLIDE))
                return FALSE;
        }
    }

    /* Add Bookmark Text */
    if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_BOOKMARK_TEXT), MEA_SE_ADD_BOOKMARK_TEXT))
    {
        return FALSE;
    }
    
    if ((slideCount > 0) && (initiated))
    {
        /* PREVIEW */
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_PREVIEW_SMIL), MEA_SE_PREVIEW_SMIL))
        {
            return FALSE;
        }

        /* DURATION */
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DURATION), MEA_SE_DURATION))
        {
            return FALSE;
        }
    }
    return TRUE;
}

/*!
 * \brief Signal converter callback function for the context sensitive menu.
 *
 * \param actionType The type of action that was generated.
 *****************************************************************************/
static void navMenuSignalConverter(MeaNavAction actionType)
{
    MeaInputItem inputItem;
    char buffer[MEA_CFG_DURATION_SIZE + 1];

    memset(&inputItem, 0, sizeof(MeaInputItem));
    if (MEA_NAV_ACTION_BACK == actionType)
    {
        (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_DEACTIVATE);
    }

    if (MEA_NAV_ACTION_OK == actionType)
    {
        switch(meaGetNavMenuItem())
        {
        case MEA_SE_DELETE_SLIDE:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_DELETE_SLIDE);
            break;
#if MEA_CFG_INSERT_SLIDE_OPTION == 1
        case MEA_SE_ADD_SLIDE_BEFORE:
	        MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_INSERT_SLIDE, TRUE);
            break;
        case MEA_SE_ADD_SLIDE_AFTER:
	        MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_INSERT_SLIDE, FALSE);
            break;
#else
        case MEA_SE_INSERT_PAGE:
	        MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_INSERT_SLIDE);
            break;
#endif
        case MEA_SE_REMOVE_IMAGE:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REM_OBJECT, MEA_MEDIA_GROUP_IMAGE);
            HDIa_widgetExtSmilEditorUpdateImage(meaSeGetFormHandle(), 0);
            break;
        case MEA_SE_REMOVE_AUDIO:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REM_OBJECT, MEA_MEDIA_GROUP_AUDIO);
            break;
        case MEA_SE_REMOVE_VIDEO:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REM_OBJECT, MEA_MEDIA_GROUP_VIDEO);
            HDIa_widgetExtSmilEditorUpdateImage(meaSeGetFormHandle(), 0);
            break;

        case MEA_SE_ADD_IMAGE:
        {
	        MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_ADD_OBJECT, MEA_MEDIA_GROUP_IMAGE);
            break;
        }
        case MEA_SE_EDIT_IMAGE:
        {
	        MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, MEA_MEDIA_GROUP_IMAGE);
            break;
        }
        
        case MEA_SE_ADD_AUDIO:
        {
	        MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_ADD_OBJECT, MEA_MEDIA_GROUP_AUDIO);
            break;
        }
        case MEA_SE_EDIT_AUDIO:
        {
	        MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, MEA_MEDIA_GROUP_AUDIO);
            break;
        }
        
        case MEA_SE_ADD_VIDEO:
        {
	        MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_ADD_OBJECT, MEA_MEDIA_GROUP_VIDEO);
            break;
        }
        case MEA_SE_EDIT_VIDEO:
        {
	        MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, MEA_MEDIA_GROUP_VIDEO);
            break;
        }
        case MEA_SE_ADD_ATTACHMENT:
	        MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_ADD_OBJECT, MEA_MEDIA_GROUP_ATTACHMENT);
            break;
        case MEA_SE_EDIT_ATTACHMENT:
            meaSeCreateAttachmentListView(MEA_SE_EDIT_ATTACHMENT);
            break;
        case MEA_SE_REMOVE_ATTACHMENT:
            meaSeCreateAttachmentListView(MEA_SE_REMOVE_ATTACHMENT);
            break;
        case MEA_SE_PREVIOUS_SLIDE:
	        MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_PREVIOUS_SLIDE);
            break;
        case MEA_SE_NEXT_SLIDE:
	        MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NEXT_SLIDE);
            break;
        case MEA_SE_INPUT_METHOD:
            HDIa_widgetExtSmilEditorEnterInputMethod(meaSeGetFormHandle(), meaSeInputMethodDeactivate);
            break;
        case MEA_SE_PREVIEW_SMIL:
	        MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_PREVIEW_SMIL);
            break;
        case MEA_SE_DURATION:
            inputItem.type = MEA_TEXT_INPUT;
            inputItem.textType = MsfNumeric;
            inputItem.maxTextSize = MEA_CFG_DURATION_SIZE;
            sprintf(buffer,"%d", meaSeGetDuration()/1000);
            inputItem.text = buffer;
            inputItem.callback = meaSeHandleDuration;
            (void)meaCreateInputForm(&inputItem, 
                MEA_GET_STR_ID(MEA_STR_ID_DURATION));
            break;
        case MEA_SE_BACK:
	        MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_DEACTIVATE);
            break;
        case MEA_SE_ADD_BOOKMARK_TEXT:
	        BRAif_selectBookmark(MSF_MODID_MEA);
            break;
        }
        if (MEA_SE_PREVIEW_SMIL == meaGetNavMenuItem())
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_DEACTIVATE);
    }
} /* navMenuSignalConverter */

#else /* WIDGET_ADVANCED_SMIL_EDITOR */
  #ifdef WAP_SUPPORT
static int createMenuItems(int slideCount, int initiated, int slideIndex)
#else
static int createMenuItems(int slideCount, int initiated, MeaMeStartupMode mode)
#endif /* WAP_SUPPORT */
{
    MeaSeGadgetDef gadget;
#ifdef WAP_SUPPORT
	MeaMediaGroupType visibleObjs = meaGetCurrentSlideObjectDef();
#endif /* WAP_SUPPORT */

    gadget = meaSeGetActiveGadget();

  #ifdef WAP_SUPPORT
    /* Add text, image, audio */
    if ((MEA_MEDIA_GROUP_TEXT & visibleObjs) == 0)
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_TEXT),  
             MEA_SE_ADD_TEXT))
        {
            return FALSE;
        }
    }

    if ((MEA_MEDIA_GROUP_IMAGE & visibleObjs) == 0)
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_IMAGE),
             MEA_SE_ADD_IMAGE))
        {
            return FALSE;
        }
    }

    if ((MEA_MEDIA_GROUP_AUDIO & visibleObjs) == 0)
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_AUDIO),  
             MEA_SE_ADD_AUDIO))
        {
            return FALSE;
        }
    }

    /* Delete object - Remove Media Object--> Remove Text/Image/Audio*/
	switch (gadget)
	{
	    case MEA_SE_GADGET_IMAGE:
            if ((!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_EDIT_IMAGE), MEA_SE_ADD_IMAGE)) 
            	|| (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REMOVE_IMAGE),//Rem_image
                MEA_SE_DELETE_OBJECT)))
                return FALSE;	
	    	break;
	    case MEA_SE_GADGET_TEXT:
            if ((!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_EDIT_TEXT), MEA_SE_ADD_TEXT))
            	|| (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REMOVE_TEXT),//Rem_text
                MEA_SE_DELETE_OBJECT)))
                return FALSE;
	    	break;
	    case MEA_SE_GADGET_AUDIO:
            if ((!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_EDIT_AUDIO), MEA_SE_EDIT_AUDIO))
            	|| (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REMOVE_AUDIO),//Rem_audio
                MEA_SE_DELETE_OBJECT)))
                return FALSE;	    	
	    	break;
	    default:
	    	break;
	}

    if (!meaGetAttachmentList())
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_ATTACHMENT),  
             MEA_SE_ADD_ATTACHMENT))
        {
            return FALSE;
        }
    }
    else
    {
        char *str = (char*)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_EDIT_ATTACHMENT);
        int size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8 *)str)+1;
        char *strEditAttachment = MEA_ALLOC(size);
        char * strMenu;
        MsfStringHandle strHandle;
        char *strFileName = strrchr((char *)meaGetAttachmentList()->filename, '\\');
        if (strFileName)
            strFileName++;
        else
            strFileName = (char *)meaGetAttachmentList()->filename;
        widget_ucs2_to_utf8_string((kal_uint8*)strEditAttachment, size, (kal_uint8 *)str);
        strMenu = msf_cmmn_str3cat(MSF_MODID_MEA, strEditAttachment, (char *)"-", 
            strFileName);
        MEA_FREE(strEditAttachment);
        if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
            strMenu, MsfUtf8, 
            strlen(strMenu) + 1, 0)))
        {
            MEA_FREE(strMenu);
            return FALSE;
        }
    
        if (!meaAddNavMenuItem(strHandle, //MEA_GET_STR_ID(MEA_STR_ID_EDIT_ATTACHMENT),  
             MEA_SE_EDIT_ATTACHMENT))
        {
            return FALSE;
        }
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REMOVE_ATTACHMENT),  
             MEA_SE_REMOVE_ATTACHMENT))
        {
            return FALSE;
        }
    }
  #else /* WAP_SUPPORT */
    /* Text color */
    if (MEA_SE_GADGET_TEXT == meaSeGetActiveGadget())
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_TEXT_COLOR),
            MEA_SE_TEXT_FG_COLOR))
        {
            return FALSE;
        }
    }


  /* Text color */
    if (MEA_SE_GADGET_TEXT == meaSeGetActiveGadget())
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_TEXT_COLOR_ALL),
            MEA_SE_TEXT_FG_COLOR_ALL))
        {
            return FALSE;
        }
    }


    /* Delete object */
    if ((gadget == MEA_SE_GADGET_IMAGE) || (gadget == MEA_SE_GADGET_TEXT) ||
        (gadget == MEA_SE_GADGET_AUDIO))
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REM_MEDIA_OBJ),
            MEA_SE_DELETE_OBJECT))
        {
            return FALSE;
        }
    }
  #endif /* WAP_SUPPORT */

    /* Insert page */
    if (initiated)
    {
#if MEA_CFG_INSERT_SLIDE_OPTION == 1
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_SLIDE_BEFORE), MEA_SE_ADD_SLIDE_BEFORE))
        {
            return FALSE;
        }
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_SLIDE_AFTER), MEA_SE_ADD_SLIDE_AFTER))
        {
            return FALSE;
        }
#else
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_INSERT_SLIDE),
            MEA_SE_INSERT_PAGE))
        {
            return FALSE;
        }
#endif
    }
    /* Delete slide*/
    if (slideCount > 1)
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE_SLIDE),
            MEA_SE_DELETE_SLIDE))
        {
            return FALSE;
        }
  #ifdef WAP_SUPPORT
        if (slideIndex)
        {
            if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_PREVIOUS_SLIDE),
                MEA_SE_PREVIOUS_SLIDE))
                return FALSE;
        }
        if (slideIndex < slideCount - 1)
        {
            if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_NEXT_SLIDE),
                MEA_SE_NEXT_SLIDE))
                return FALSE;
        }
#endif /* WAP_SUPPORT */
    }
#ifndef WAP_SUPPORT    
    /* Send message */
    if ((slideCount > 0) && (initiated) && MEA_ME_ALLOW_SEND(mode))
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SEND), MEA_SE_SEND))
        {
            return FALSE;
        }
    }

     /* Save message */
    if ((slideCount > 0) && (initiated))
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SAVE), 
            (MEA_ME_STARTUP_NEW_TEMPLATE == mode) ? MEA_SE_SAVE_AS_TEMPLATE: 
             MEA_SE_SAVE))
        {
            return FALSE;
        }
    }
    /* Save message as template, note that new templates uses "save" */
    if ((slideCount > 0) && (initiated) && MEA_ME_ALLOW_SAVE_TEMPLATE(mode))
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SAVE_AS_TEMPLATE), 
            MEA_SE_SAVE_AS_TEMPLATE))
        {
            return FALSE;
        }
    }
#endif /* ~WAP_SUPPORT */
    /* Preview SMIL */
    if ((slideCount > 0) && (initiated))
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_PREVIEW_SMIL), 
            MEA_SE_PREVIEW_SMIL))
        {
            return FALSE;
        }
#ifndef WAP_SUPPORT
    }
#endif /* ~WAP_SUPPORT */
    /* Duration */    
    if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DURATION), 
        MEA_SE_DURATION))
    {
        return FALSE;
    }
#ifdef WAP_SUPPORT
    }
#else
    /* Background color */
    if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_BG_COLOR), 
        MEA_SE_BG_COLOR))
    {
        return FALSE;
    }
    /* Back*/    
    if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_BACK), 
        MEA_SE_BACK))
    {
        return FALSE;
    }
#endif /* WAP_SUPPORT */
    return TRUE;
} /* createMenuItems */

/*!
 * \brief Signal converter callback function for the context sensitive menu.
 *
 * \param actionType The type of action that was generated.
 *****************************************************************************/
static void navMenuSignalConverter(MeaNavAction actionType)
{
    MeaInputItem inputItem;
    char buffer[MEA_CFG_DURATION_SIZE + 1];

    memset(&inputItem, 0, sizeof(MeaInputItem));
    if (MEA_NAV_ACTION_BACK == actionType)
    {
        (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_DEACTIVATE);
    }

    if (MEA_NAV_ACTION_OK == actionType)
    {
        switch(meaGetNavMenuItem())
        {
        case MEA_SE_DELETE_SLIDE:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_DELETE_SLIDE);
            break;
#if MEA_CFG_INSERT_SLIDE_OPTION == 1
        case MEA_SE_ADD_SLIDE_BEFORE:
            MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_INSERT_SLIDE, TRUE);
            break;
        case MEA_SE_ADD_SLIDE_AFTER:
            MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_INSERT_SLIDE, FALSE);
            break;
#else
        case MEA_SE_INSERT_PAGE:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_INSERT_SLIDE);
            break;
#endif
        case MEA_SE_TEXT_FG_COLOR:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_SET_TEXT_COLOR);
            break;
        case MEA_SE_TEXT_FG_COLOR_ALL:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_SET_TEXT_COLOR_ALL);
            break;
        case MEA_SE_TEXT_BG_COLOR:
            break;
        case MEA_SE_OBJ_TIMING_START:
            break;
        case MEA_SE_OBJ_TIMING_DURATION:
            break;
        case MEA_SE_DELETE_OBJECT:
            if (MEA_MEDIA_GROUP_NONE != meaSeGetActiveObjType())
            {
                (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REM_OBJECT, 
                    meaSeGetActiveObjType());
            }
            break;        
        case MEA_SE_SAVE:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_SAVE, 0);
            break;
        case MEA_SE_SAVE_AS_TEMPLATE:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_SAVE_AS_TEMPLATE);
            break;
        case MEA_SE_SEND:
#ifdef WAP_SUPPORT	//Save&Send Jo 030915
			meaSaveOnSendSet(FALSE);
#endif /* WAP_SUPPORT */
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_SEND);
            break;
#ifdef WAP_SUPPORT
        case MEA_SE_ADD_TEXT:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_ADD_OBJECT, MEA_MEDIA_GROUP_TEXT);	
            break;
        case MEA_SE_EDIT_TEXT:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, MEA_MEDIA_GROUP_TEXT);	
            break;

        case MEA_SE_ADD_IMAGE:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_ADD_OBJECT, MEA_MEDIA_GROUP_IMAGE);
            break;
        case MEA_SE_EDIT_IMAGE:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, MEA_MEDIA_GROUP_IMAGE);
            break;
        case MEA_SE_ADD_AUDIO:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_ADD_OBJECT, MEA_MEDIA_GROUP_AUDIO);
            break;
        case MEA_SE_EDIT_AUDIO:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, MEA_MEDIA_GROUP_AUDIO);
            break;
        case MEA_SE_ADD_ATTACHMENT:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_ADD_OBJECT, MEA_MEDIA_GROUP_ATTACHMENT);
            break;
        case MEA_SE_EDIT_ATTACHMENT:
            (void)MEA_SIGNAL_SENDTO_U(MEA_SE_FSM, MEA_SIG_SE_REPLACE_OBJECT, MEA_MEDIA_GROUP_ATTACHMENT);
            break;
        case MEA_SE_REMOVE_ATTACHMENT:
        {
            meaSeRemoveAttachmentList();
            meaShowSlideForAttachment();
            break;
        }
        case MEA_SE_PREVIOUS_SLIDE:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_PREVIOUS_SLIDE);
            break;
        case MEA_SE_NEXT_SLIDE:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NEXT_SLIDE);
            break;
#endif /* WAP_SUPPORT */
        case MEA_SE_PREVIEW_SMIL:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_PREVIEW_SMIL);
            break;
        case MEA_SE_DURATION:
#ifdef WAP_SUPPORT
            inputItem.type = MEA_TEXT_INPUT;
#else
            inputItem.type = MEA_SINGLE_LINE_INPUT;
#endif /* WAP_SUPPORT */
            inputItem.textType = MsfNumeric;
            inputItem.maxTextSize = MEA_CFG_DURATION_SIZE;
            sprintf(buffer,"%d", meaSeGetDuration()/1000);
            inputItem.text = buffer;
            inputItem.callback = meaSeHandleDuration;
            (void)meaCreateInputForm(&inputItem, 
                MEA_GET_STR_ID(MEA_STR_ID_DURATION));
            break;
        case MEA_SE_BACK:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_DEACTIVATE);
            break;
        case MEA_SE_BG_COLOR:
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_SET_BG_COLOR);
            break;
        }
#ifdef WAP_SUPPORT
        if (MEA_SE_PREVIEW_SMIL == meaGetNavMenuItem())
#endif /* WAP_SUPPORT */
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_DEACTIVATE);
    }
} /* navMenuSignalConverter */
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */

/*!
 * \brief Creates a navigation menu for the SE.
 *
 * \param slideNo The index of the current slide.
 * \param slideCount The total number of slides.
 * \param initiated TRUE if the menu was created successfully, otherwise 
 *                  FALSE.
 * \param mode The current startup mode, see #MeaMeStartupMode.
 * \return TRUE on OK else FALSE
 *****************************************************************************/
MSF_BOOL meaSeCreateNavMenu(int slideCount, int initiated,
    int slideIndex)
{
    /* The menu is dependant on which object that is currently active */
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    (void)handleSeTvOkAction(meaSeGetTextBuffer(), 0, NULL, 0); /* Add text to MO list */
#else
    meaSeSetActiveObj();
#endif
    
    /* Create navigation menu */
    if (!meaCreateNavMenu(0, navMenuSignalConverter))
    {
        meaRemoveNavMenu();
        return FALSE;
    }
    else if (!createMenuItems(slideCount, initiated, slideIndex))
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
} /* meaSeCreateNavMenu */

/*!
 * \brief Deletes the navigation menu.
 *****************************************************************************/
void meaSeDeleteNavMenu(void)
{
    meaRemoveNavMenu();
    meaSeRemoveAttachmentListView(seAttachmentListView.menuHandle);
} /* meaSeDeleteNavMenu */


