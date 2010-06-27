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

/*! \file mtr.h
 *  \brief API for text rendering
 *
 *  API usage:
 *  Use mtrCreateTextBox() to create a new text box. A 
 *  #MtrCreateTextBoxProperties struct must be filled in with creation 
 *  properties. The returned #MtrCreateRspData struct contains an instance
 *  number that is needed when using the rest of the API functions.
 *
 *  Use the mtrFree functions to deallocate structs that have been allocated
 *  by MTR.
 *
 *  When the text box should be deallocated, the user must first remove the
 *  gadget from the form and then call mtrDeleteTextBox() with the instance
 *  to release it.
 *  
 *  Since the widget API doesn't support handling user events to gadgets, the
 *  user of MTR must notify MTR when a key event has happened by calling
 *  mtrRedraw(). In the return data from mtrRedraw() the user will find out
 *  if the event caused the text box to loose focus.
 *
 *  The same goes for OK actions. The user must as MTR if any link is selected
 *  when the OK button is pressed and the text box has focus. This is done by
 *  calling mtrHasActiveLink().
 *
 *  Text box features:
 *  The text box supports rendering of links (HTTP, HTTPS, phone numbers, 
 *  email). Text alignment; only center alignment is supported today.
 *  Scrolling of text; if the text is larger than maximum size of text box the
 *  text will be scrolled. Scrolling can only be made up and down and only one
 *  text line at a time. Text color and background color is supported. 
 *  The colors for links are not adjustable today; default is blue. 
 *  A marked link will display with inverted colors. Displaying scrollbars are 
 *  not implemented today.
 */

#ifndef _MTR_H
#define _MTR_H


/**********************************************************************
 * External Signals
 **********************************************************************/

/*  At this moment there are no exported signals since MTR is incorporated 
 *  in MEA so only internal signals are used. */

/**********************************************************************
 * Signal parameter definitions:
 **********************************************************************/

/*! \enum MtrResult
 */
typedef enum
{
    MTR_RESULT_OK = 0,
    MTR_RESULT_BUSY,
    MTR_RESULT_ERROR
}MtrResult;

/*! \enum MtrScheme
 */
typedef enum  
{
    MTR_SCHEME_HTTP     = 0x0001,
    MTR_SCHEME_HTTPS    = 0x0002,
    MTR_SCHEME_WWW      = 0x0004,
    MTR_SCHEME_MAIL     = 0x0008,
    MTR_SCHEME_PHONE    = 0x0010,
    MTR_SCHEME_NONE     = 0x8000
}MtrScheme;

/*! \enum MtrProperties
 *  Text box properties to use in call to mtrCreateTextBox
 */
typedef enum  
{
    MTR_PROP_RENDER_LINKS          = 0x0001,
    MTR_PROP_USE_SCROLLBARS        = 0x0002,
    MTR_PROP_VERTICAL_RESIZE       = 0x0004,
    MTR_PROP_HORIZONTAL_RESIZE     = 0x0008,
    MTR_PROP_RETURN_LINKS          = 0x0010,
    MTR_PROP_HIDE_CURSOR           = 0x0020
}MtrProperties;

/*! \struct MtrCreateTextBoxProperties
 */
typedef struct 
{
    /* Looks */
    MsfSize size;               /*!< Size of the resulting text box */
    MsfHorizontalPos alignment; /*!< Alignment of text. Default is MsfCenter */
    MsfColor bgColor;           /*!< Background color of the text box */
    MsfColor textColor;         /*!< Color of the text */
    /* Data */
    MSF_UINT32 schemes;         /*!< The schemes to match in the text.
                                     See #MtrSchemes for the schemes. 
                                     Supported schemes should be masked in.
                                     Ex. MTR_SCHEME_HTTP | MTR_SCHEME_PHONE */
    /* Behaviour */
    MSF_UINT32 flags;           /*!< Behaviour flags. See #MtrProperties */
}MtrCreateTextBoxProperties;

/*! \struct MtrLinkEntry
 *  A list of links found in a text
 */
typedef struct _MtrLinkEntry 
{
    MtrScheme scheme;           /*!< The scheme of the link */
    char *link;                 /*!< A string representation of the link */
    struct _MtrLinkEntry *next; /*!< Pointer to the next link in the list */
}MtrLinkEntry;

/*! \struct MtrCreateRspData
 */
typedef struct  
{
    int instance;               /*!< Instance number. Needed to identify 
                                     instance. */
    MsfGadgetHandle gadgetHandle; /*!< The handle of the created gadget. */
    MsfSize gadgetSize;         /*!< The size of the rendered gadget. */
    MtrLinkEntry *links;        /*!< A list of found links in text if 
                                     applicable. NULL if returnLinks is FALSE*/
}MtrCreateRspData;

#ifndef WIDGET_ADVANCED_SMIL_EDITOR
int mtrGetTextBoxEndIndex(MsfStringHandle stringHandle, 
    const MtrCreateTextBoxProperties *prop);
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */

/*!
 * \brief Create a text box in current window.
 * 
 * \param stringHandle Handle of the text string to display in the text box. 
 * \param prop Properties of the text box. See #MtrCreateTextBoxProperties.
 * \param rsp An allocated #MtrCreateRspData struct containing the result of the 
 *            operation. It is up to the caller to deallocate the struct with a 
 *            call to mtrFreeMtrLinkEntry().
 * \return MTR_RESULT_OK on success, otherwise the proper result code.
 *****************************************************************************/
MtrResult mtrCreateTextBox(MsfStringHandle stringHandle, 
    const MtrCreateTextBoxProperties *prop, MtrCreateRspData **rsp);
                                   
/*!
 * \brief Deletes a text box. Note that this function will not remove the
 *        gadget from the form. The removal must be done prior to the call to
 *        mtrDeleteTextBox().
 * 
 * \param instance The text box instance.
 * \return MTR_RESULT_OK on success, otherwise the proper result code.
 *****************************************************************************/
MtrResult mtrDeleteTextBox(int instance);

/*!
 * \brief Redraws the text box according to current event. The supported events
 *        are MsfKey_Down, MsfKey_Up, MsfKey_Left, MsfKey_Right. Down and right
 *        events are interpreted as down. Up and left events are interpreted as
 *        up.
 * \param instance The text box instance.
 * \param event The event that causes the text box to redraw.
 * \param lostFocus (out) This parameter will be set to TRUE if the text box
 *                  will loose focus due to the event.
 *****************************************************************************/
MtrResult mtrRedraw(int instance, MsfEventType event, MSF_BOOL *lostFocus);

/*!
 * \brief Checks if any link is active (is selected) in current text box.
 *        The function will allocate data for the #MtrLinkEntry link if
 *        the functions returns TRUE, otherwise no memory will be allocated
 *        and link will be set to NULL.
 * \param instance The text box instance.
 * \param link The returned link if active, otherwise NULL.
 * \return TRUE if a link is active, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL mtrHasActiveLink(int instance, MtrLinkEntry **link);

/*!
 * \brief Deallocates a #MtrCreateRspData struct.
 * 
 * \param data The data to free.
 *****************************************************************************/
void mtrFreeMtrCreateRspData(MtrCreateRspData **data);

/*!
 * \brief Deallocates a #MtrLinkEntry struct.
 * 
 * \param data The data to free.
 *****************************************************************************/
void mtrFreeMtrLinkEntry(MtrLinkEntry **data);

#endif


