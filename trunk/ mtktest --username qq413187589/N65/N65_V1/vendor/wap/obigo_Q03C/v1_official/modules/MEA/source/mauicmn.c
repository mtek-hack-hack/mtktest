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

/*! \file mauicmn.c
 *  \brief Common functions for the GUI.
 */

/* MSF */
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_def.h"
#include "msf_mem.h"
#include "msf_cmmn.h"

/* MMS Service */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"

/* SLS */
#include "sls_def.h"
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_def.h"
#include "mea_cfg.h"
#include "mea_rc.h"
#include "matypes.h"
#include "mamem.h"
#include "maintsig.h"
#include "mamr.h"
#include "mame.h"
#include "mauimenu.h"
#include "mauicmn.h"
#include "mauiincn.h"
#include "mauiconf.h"
#include "mauiincn.h"
#include "mamh.h"
#include "mauimh.h"
#include "mauimv.h"
#include "mauime.h"
#include "mauimmv.h"
#include "mauimme.h"
#include "mauisig.h"
#include "mauise.h"
#include "mauipm.h"
#include "mauidia.h"
#include "mauimenu.h"
#include "mauiform.h"
#include "mautils.h"
#include "mauimmv.h"
#include "mauicols.h"

/******************************************************************************
 * Constants
 *****************************************************************************/
static const MsfPosition      posLeftTop     = {0, 0};

/******************************************************************************
 * Global variables
 *****************************************************************************/

static MsfScreenHandle   meaScreenHandle;

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief Create the initial data-structures needed for MEA to run.
 *
 *****************************************************************************/
void meaInitGui()
{
    meaScreenHandle = MSF_WIDGET_SCREEN_CREATE(MSF_MODID_MEA, 1, 0);
  
    /* Initiate widget signal handler */
    meaInitWidgetSignalHandler();
    /* Init the progress meter */
    meaInitPm();
    /* Init the dialog handling */
    meaInitDia();
    /* Init input form handling */
    meaInitForms();
    /* Init the menu handling */
    meaInitNavMenu();
    /* Message handler */
    meaMhUiInit();
    /* Config */
    meaConfigUiInit();
    /* Message viewer */
    meaMvUiInit();
    /* Message editor */
    meaMeUiInit();
    /* SMIL editor */
    meaSeUiInit();
    /* Incoming notifications */
    meaInUiInit();
    /* The Multipart/Mixed viewer */
    meaMmvUiInit();
    /* The Multipart/Mixed editor */
    meaMmeUiInit();
    /* The color selector */
    meaColorSelectorInit();
}

/*!
 * \brief Free the resources allocated in meaInitGui.
 *
 *****************************************************************************/
void meaTerminateGui()
{
    /* Remove the progress meter */
    meaTerminatePm();
    /* Terminate input form handling */
    meaTerminateForms();
    /* Terminate dialogs */
    meaTerminateDia();
    /* Terminate navigation menu */
    meaTerminateNavMenu();
    /* Color selector */
    meaColorSelectorTerminate();
    /* Terminate the widget signal handler */
    meaTerminateWidgetSignalHandler();
    
    /* Delete the screen */
    if (0 != meaScreenHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaScreenHandle);
        meaScreenHandle = 0;
    }
}

/*!
 * \brief Gets the size of the display.
 *
 * \param ms A pointer to a MsfSize struct.
 *****************************************************************************/
void meaGetDisplaySize(MsfSize *ms)
{
    MsfDeviceProperties dp;
    (void)MSF_WIDGET_DEVICE_GET_PROPERTIES(&dp);
    *ms = dp.displaySize;
}

#ifdef WAP_SUPPORT
MsfImageHandle meaGetListNumImage(int i)
{
   i++;
   switch(i)
   {
   case 1:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB1,0);
   case 2:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB2,0);
   case 3:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB3,0);
   case 4:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB4,0);
   case 5:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB5,0);
   case 6:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB6,0);
   case 7:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB7,0);
   case 8:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB8,0);
   case 9:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB9,0);
   case 10:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB10,0);
   case 11:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB11,0);
   case 12:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB12,0);
   case 13:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB13,0);
   case 14:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB14,0);
   case 15:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB15,0);
   case 16:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB16,0);
   case 17:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB17,0);
   case 18:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB18,0);
   case 19:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB19,0);
   case 20:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB20,0);
   default:
     return 0;
   }
}
#endif /* WAP_SUPPORT */
/*!
 * \brief Gets an empty string.
 *
 * \return A string-handle containing a empty string.
 *****************************************************************************/
MsfStringHandle meaGetEmptyStringHandle()
{
    return MEA_GET_STR_ID(MEA_STR_ID_EMPTY_STRING);
}

/*!
 * \brief Gets the screen handle of the main screen.
 *
 * \return The screen handle of the main screen, if no screen handle is 
 *         available 0 is returned.
 *****************************************************************************/
MsfScreenHandle meaGetScreenHandle()
{
    return meaScreenHandle;
}

/*!
 * \brief Finds the first selected choice index.
 *
 * \param choiceHandle The handle of a choiceGroup.
 * \return The index of the first selected item, -1 if no item is selected.
 *          
 *****************************************************************************/
int meaGetSelectedChoiceIndex(MSF_UINT32 choiceHandle)
{
    int i, count;
    if (0 == choiceHandle)
        return -1;
    count = MSF_WIDGET_CHOICE_SIZE(choiceHandle);
    for (i=0; i < count; i++)
    {
        if (MSF_CHOICE_ELEMENT_SELECTED & MSF_WIDGET_CHOICE_GET_ELEM_STATE(
            choiceHandle, i))
            return i;
    }
    return -1;
}

/*!
 * \brief Binds a window the the MEA screen handle and sets the window in 
 *        focus.
 *
 * \param WindowHandle The handle of the window to show.
 * \param pos A pointer to the position the window should be displayed.
 * \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
int meaDisplayWindow(MsfWindowHandle windowHandle, const MsfPosition *pos)
{
    if (0 <= MSF_WIDGET_SCREEN_ADD_WINDOW(meaGetScreenHandle(), 
        windowHandle, (MsfPosition *)pos, 0, 0))
    {
        (void)MSF_WIDGET_SET_IN_FOCUS(meaGetScreenHandle(), TRUE);
        (void)MSF_WIDGET_SET_IN_FOCUS(windowHandle, TRUE);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*\brief Returns the position for widget placement left, top.
 *
 *\return A pointer to a MsfPostion = {0,0}.
 *****************************************************************************/
MsfPosition *meaGetPosLeftTop()
{
    return (MsfPosition *)&posLeftTop;
}

/*!
 * \brief Gets text from a widget.
 *
 * \param gadgetHandle The handle of the gadget to retrieve text from.
 * \return A pointer to a new string or NULL. The caller is responsible for 
 *         returning the allocated string.
 *****************************************************************************/
char *meaGetTextFromGadget(MsfGadgetHandle gadgetHandle)
{
    MsfStringHandle strHandle;
    char *tmpStr;
    int length;

    if (0 == (strHandle = MSF_WIDGET_STRING_CREATE_TEXT(MSF_MODID_MEA, 
        gadgetHandle, 0)))
    {
        return NULL;
    }
    if (0 >= (length = MSF_WIDGET_STRING_GET_LENGTH(strHandle, TRUE, 
        MsfUtf8)))
    {
        (void)MSF_WIDGET_RELEASE(strHandle);
        return NULL;
    }
    /* Add space for NULL termination*/
    length += 1;
    tmpStr = (char *)MEA_ALLOC(sizeof(char)*(unsigned)length);
    memset(tmpStr, 0, (unsigned int)length);
    /* Get string data */
    if (0 > MSF_WIDGET_STRING_GET_DATA(strHandle, tmpStr, MsfUtf8))
    {
        (void)MSF_WIDGET_RELEASE(strHandle);
        /*lint -e{774} */
        MEA_FREE(tmpStr);
        tmpStr = NULL;
        return NULL;    
    }
    (void)MSF_WIDGET_RELEASE(strHandle);
    return tmpStr;
}

/*!
 * \brief Extracts the string from a string handle.
 *
 * \param strHandle The string handle to extract text from
 * \return The string from the string handle. Note the caller is responsible
 *         for deallocating the returned string.
 *****************************************************************************/
char *meaGetStringFromHandle(MsfStringHandle strHandle)
{
    char *tmpStr = NULL;
    unsigned int length;
    length = (unsigned)MSF_WIDGET_STRING_GET_LENGTH(strHandle, TRUE, MsfUtf8);
    tmpStr = MEA_ALLOC(length);
    if (0 > MSF_WIDGET_STRING_GET_DATA(strHandle, tmpStr, MsfUtf8))
    {
        return NULL;    
    }
    return tmpStr;
}

/*!
 * \brief Sets the text part of a gadget.
 *
 * \param gadgetHandle The handle of the gadget to set.
 * \param maxLen Maximum length of the text.
 * \param newStringValue The text to set.
 * \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaSetTextInputGadgetValue(MsfGadgetHandle gadgetHandle, int maxLen, 
    const char *newStringValue)
{
    MsfStringHandle tmpStrHandle;
    int len;

    if (NULL != newStringValue)
    {
        len = (int)strlen(newStringValue) + 1;
        tmpStrHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, newStringValue, 
            MsfUtf8, len, 0);
        /* Set the new value */
        if (0 == tmpStrHandle)
        {
            return FALSE;
        }
        if (0 > MSF_WIDGET_TEXT_SET_TEXT(gadgetHandle, 0, MsfText, maxLen, 
            tmpStrHandle, TRUE))
        {
            (void)MSF_WIDGET_RELEASE(tmpStrHandle);
            return FALSE;
        }
        (void)MSF_WIDGET_RELEASE(tmpStrHandle);
    }
    else
    {
        if (0 > MSF_WIDGET_TEXT_SET_TEXT(gadgetHandle, 0, MsfText, maxLen, 
            meaGetEmptyStringHandle(), TRUE))
        {
            return FALSE;
        }
    }
    return TRUE;
}

/*! 
 * \brief Sets a window title.
 *
 * \param win The window to set title.
 * \param strHandle The string handle of the title.
 * \param currentProperties The current properties set for the window.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaSetTitle(MsfWindowHandle win, MsfStringHandle strHandle, 
    int currentProperties)
{
    /* Title*/
    if (0 > MSF_WIDGET_SET_TITLE(win, strHandle))
    {
        return FALSE;
    }
    (void)MSF_WIDGET_WINDOW_SET_PROPERTIES(win,
        MSF_WINDOW_PROPERTY_TITLE | currentProperties);
    return TRUE;
}

/*!
 *  \brief Sets the string value for a gadget.
 *  \param gadgetHandle The handle of the gadget to set the text for.
 *  \param strHandle The handle of the static string to display
 *  \param str The string to set.
 *  \return TRUE on success, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaSetStringGadgetValue(MsfGadgetHandle gadgetHandle,
    MsfStringHandle strHandle, const char *str)
{
    unsigned int len;
    char *buffer;
    MsfStringHandle newStrHandle;
    len = ((0 != strHandle) ? (unsigned)MSF_WIDGET_STRING_GET_LENGTH(
        strHandle, TRUE, MsfUtf8):0) + 
        ((NULL != str) ? (unsigned)strlen(str): 0) + 1;

    buffer = MEA_ALLOC(len);
    memset(buffer, 0, len);
    if (0 != strHandle)
    {
        if (0 > MSF_WIDGET_STRING_GET_DATA(strHandle, buffer, MsfUtf8))
        {
            return FALSE;
        }
    }
    if (NULL != str)
    {
        strcat(buffer, str);
    }
    if (0 == (newStrHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, buffer, 
        MsfUtf8, (int)strlen(buffer) + 1, 0)))
    {
        /*lint -e{774} */
        MEA_FREE(buffer);
        return FALSE;
    }
    /*lint -e{774} */
    MEA_FREE(buffer);
    if (0 > MSF_WIDGET_STRING_GADGET_SET(gadgetHandle, newStrHandle, TRUE))
    {
        (void)MSF_WIDGET_RELEASE(newStrHandle);
        return FALSE;
    }
    (void)MSF_WIDGET_RELEASE(newStrHandle);
    return TRUE;
}

/*!
 *  \brief Gets a string handle to a string on the form
 *         prefix minVal infix maxVal
 *  \param prefix The resource ID for the prefix string.
 *  \param minVal The first number.
 *  \param infix The resource ID for the prefix string.
 *  \param maxVal The second number.
 *  \return The new string handle on success, otherwise 0.
 *****************************************************************************/
char *meaGetIntervalString(MSF_UINT32 prefix, int minVal, 
                                     MSF_UINT32 infix, int maxVal)
{
    char *str1;
    char *str2;
    char *newStr, *tmpStr;
    char buffer[10 * sizeof(char) + sizeof(char)/*MSF_EOS*/];
    
    str1 = meaGetStringFromHandle(MEA_GET_STR_ID(prefix));
    str2 = meaGetStringFromHandle(MEA_GET_STR_ID(infix));
    sprintf(buffer, "%d", minVal);
    if (NULL == (tmpStr = msf_cmmn_str3cat(MSF_MODID_MEA, str1, buffer, str2)))
    {
        return NULL;
    }
    MEA_FREE(str1);
    MEA_FREE(str2);

    sprintf(buffer, "%d", maxVal);
    if (NULL == (newStr = msf_cmmn_str3cat(MSF_MODID_MEA, tmpStr, buffer, 
        NULL)))
    {
        return NULL;
    }
    /*lint -e{774} */
    MEA_FREE(tmpStr);
    return newStr;
    
}

/*! \brief Compares configured limitations against current message size and
 *         object size and shows warning/error dialogs accordingly
 * \param newMsgSize    the potential message size after adding object
 * \param objectSize    the size of the controversial object 
 * \param mediaType     the media type of the controversial object
 * \param fsm           the fsm to call when dialog is closed
 * \param signal        the signal to send to the fsm when dialog is closed
 * \return TRUE if adding can proceed, FALSE if serious error level.
 *****************************************************************************/           
MeaSeverity meaShowSizeWarningDialog(MSF_UINT32 newMsgSize, 
    MSF_UINT32 objectSize, MeaMediaType mediaType, MeaStateMachine fsm, 
    int signal)
{
	/* Check if inclusion of this media object would break the 100k barrier */
	if (newMsgSize > MEA_CFG_MESSAGE_SIZE_MAXIMUM)
	{
        if (MEA_NOTUSED_FSM == fsm)
        {
            (void)meaShowDialog(MEA_GET_STR_ID(
                MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED), MEA_DIALOG_ERROR);
        }
        else
        {
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(
                MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED), MEA_DIALOG_ERROR,
                fsm, signal);
        }
        //return MEA_SEVERITY_ASSERT;
        return MEA_SEVERITY_ERROR;
	} /* if */

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
/* under construction !*/
#ifdef WAP_SUPPORT
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif /* WAP_SUPPORT */
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

    return MEA_SEVERITY_OK;
}

/*! \brief Converts an integer containing an RGB value (8-bits per channel) 
 *         into a #MsfColor data-structure.
 *
 * \param rgbColor The color to convert into a #MsfColor structure.
 * \param msfColor A reference to a #MsfColor data-structure.
 *****************************************************************************/
void meaIntToMsfColor(MSF_UINT32 rgbColor, MsfColor *msfColor)
{
    msfColor->r = (rgbColor >> 16) & 0xff;
    msfColor->g = (rgbColor >> 8)  & 0xff;
    msfColor->b = (rgbColor >> 0)  & 0xff;
}

/*! \brief Converts an integer containing an #MsfColor data-structure
 *         into a RGB value (8-bits per channel).
 *
 * \param msfColor A reference to a #MsfColor data-structure.
 * \return The corresponding color as an integer.
 *****************************************************************************/
MSF_UINT32 meaMsfToIntColor(MsfColor *msfColor)
{
    return (msfColor->r << 16) | (msfColor->g << 8) | (msfColor->b);
}

/*!
 * \brief Calculates the size of a gadget from a set of criterias.
 *        See inline comment for information on how the values are calculated.
 * \param data A pointer to a #MeaCmnStringGadgetData struct.
 *****************************************************************************/
void meaCalculateStringGadgetSize(MsfWindowHandle window, 
    MsfGadgetHandle gadget, MsfStringHandle strHandle, const MsfPosition *pos, 
    const MsfSize *maxSize, MsfSize *newSize, MSF_BOOL multipleLines)
{
    MsfSize winSize;
    MsfFont font;
    int chars = 0, fontHeight = 0, tmp;
    int len = 0, index, gadgetHeight;

    /* First get the size of the window */
    if (MSF_WIDGET_WINDOW_SPECIFIC_SIZE(window, &winSize, 1) < 0)
    {
        return;
    }
    /* Get the font to determine the height */
    if (strHandle && MSF_WIDGET_GET_FONT(strHandle, &font) < 0)
    {
        return;
    }
    /* Get the heigh of the text in order to calculate the height of the 
     * gadget later on */
    if (strHandle && MSF_WIDGET_FONT_GET_VALUES(&font, &tmp, &fontHeight, 
        &tmp) < 0)
    {
        return;
    }
    if (MSF_WIDGET_GET_SIZE(gadget, newSize) < 0) 
    {
        return;
    }
    if (!strHandle) 
    {
        if (0 == newSize->width || (pos->x + newSize->width) > (winSize.width - pos->x))
        {
            /* Default width is too large. Decrease width to fit screen */
            newSize->width = (MSF_INT16)((int)winSize.width - (int)pos->x);
        }
        if (0 == newSize->height) 
        {
            /* Get the font to determine the height */
            if (MSF_WIDGET_GET_FONT(meaGetEmptyStringHandle(), &font) < 0)
            {
                return;
            }
            /* Get the heigh of the text in order to calculate the height of the 
             * gadget later on */
            if (MSF_WIDGET_FONT_GET_VALUES(&font, &tmp, &fontHeight, 
                &tmp) < 0)
            {
                return;
            }
            newSize->height = (MSF_INT16)(fontHeight + MEA_CMN_BASELINE_SIZE);
        }
        return;
    }
    /* Calculate width */
    if (0 == newSize->width || (pos->x + newSize->width) > (winSize.width - pos->x))
    {
        /* Default width is too large. Decrease width to fit screen */
        newSize->width = (MSF_INT16)((int)winSize.width - (int)pos->x);
    }
    /* The text needs multiple line, iterate until all lines fits */
    gadgetHeight = 0;
    len = MSF_WIDGET_STRING_GET_LENGTH(strHandle, 0, MsfUtf8);
    index = 0;
    if (len)
    {
        if (multipleLines) 
        {
            do 
            {
                /* Add the visible height */
                gadgetHeight = (MSF_INT16)(gadgetHeight + fontHeight + 
                    MEA_CMN_BASELINE_SIZE);
                /* Check how many characters that can be displayed */
                if (MSF_WIDGET_STRING_GET_VISIBLE(strHandle, 0, newSize, index, 1, 
                    &chars, &tmp, &tmp) < 0)
                {
                    return;
                }
                /* Prevent infinite loop */
                if (!chars) 
                {
                    break;
                }
                index += chars;
                /* Iterate until all characters are visible */
            } while (index < len);
        }
        else
        {
            gadgetHeight = (MSF_INT16)(fontHeight + MEA_CMN_BASELINE_SIZE);
            /* Check how many characters that can be displayed */
            if (MSF_WIDGET_STRING_GET_VISIBLE(strHandle, 0, newSize, index, 1, 
                &chars, &tmp, &tmp) < 0)
            {
                return;
            }
            if (chars < len) 
            {
                newSize->width = (MSF_INT16)((int)winSize.width - (int)pos->x);
            }
        }
        newSize->height = (MSF_INT16)gadgetHeight;
        if (newSize->height > maxSize->height) 
        {
            newSize->height = maxSize->height;
        }
    }
    else
    {
        newSize->height = (MSF_INT16)(fontHeight + MEA_CMN_BASELINE_SIZE);
    }
}

