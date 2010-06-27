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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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

/*! \file sSMTR.h
 *  \brief API for text rendering
 *
 *  API usage:
 *  Use SMTRCreateTextBox() to create a new text box. A 
 *  #SMTRCreateTextBoxProperties struct must be filled in with creation 
 *  properties. The returned #SMTRCreateRspData struct contains an instance
 *  number that is needed when using the rest of the API functions.
 *
 *  Use the SMTRFree functions to deallocate structs that have been allocated
 *  by SMTR.
 *
 *  When the text box should be deallocated, the user must first remove the
 *  gadget from the form and then call SMTRDeleteTextBox() with the instance
 *  to release it.
 *  
 *  Since the widget API doesn't support handling user events to gadgets, the
 *  user of SMTR must notify SMTR when a key event has happened by calling
 *  SMTRRedraw(). In the return data from SMTRRedraw() the user will find out
 *  if the event caused the text box to loose focus.
 *
 *  The same goes for OK actions. The user must as SMTR if any link is selected
 *  when the OK button is pressed and the text box has focus. This is done by
 *  calling SMTRHasActiveLink().
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

#ifndef _SSMTR_H
#define _SSMTR_H


/**********************************************************************
 * External Signals
 **********************************************************************/

/*  At this moment there are no exported signals since SMTR is incorporated 
 *  in MEA so only internal signals are used. */

/**********************************************************************
 * Signal parameter definitions:
 **********************************************************************/

/*! \enum SMTRResult
 */
typedef enum
{
    SMTR_RESULT_OK = 0,
    SMTR_RESULT_BUSY,
    SMTR_RESULT_ERROR
}SmtrResult;

/*! \enum SMTRScheme
 */
typedef enum  
{
    SMTR_SCHEME_HTTP     = 0x0001,
    SMTR_SCHEME_HTTPS    = 0x0002,
    SMTR_SCHEME_WWW      = 0x0004,
    SMTR_SCHEME_MAIL     = 0x0008,
    SMTR_SCHEME_PHONE    = 0x0010,
    SMTR_SCHEME_NONE     = 0x8000
}SmtrScheme;

/*! \enum SMTRProperties
 *  Text box properties to use in call to SMTRCreateTextBox
 */
typedef enum  
{
    SMTR_PROP_RENDER_LINKS          = 0x0001,
    SMTR_PROP_USE_SCROLLBARS        = 0x0002,
    SMTR_PROP_VERTICAL_RESIZE       = 0x0004,
    SMTR_PROP_HORIZONTAL_RESIZE     = 0x0008,
    SMTR_PROP_RETURN_LINKS          = 0x0010,
    SMTR_PROP_HIDE_CURSOR           = 0x0020
}SmtrProperties;

/*! \struct SMTRCreateTextBoxProperties
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
                                     See #SMTRSchemes for the schemes. 
                                     Supported schemes should be masked in.
                                     Ex. SMTR_SCHEME_HTTP | SMTR_SCHEME_PHONE */
    /* Behaviour */
    MSF_UINT32 flags;           /*!< Behaviour flags. See #SMTRProperties */
}SmtrCreateTextBoxProperties;

/*! \struct SMTRLinkEntry
 *  A list of links found in a text
 */
typedef struct _SmtrLinkEntry 
{
    SmtrScheme scheme;           /*!< The scheme of the link */
    char *link;                 /*!< A string representation of the link */
    struct _SmtrLinkEntry *next; /*!< Pointer to the next link in the list */
}SmtrLinkEntry;

/*! \struct SMTRCreateRspData
 */
typedef struct  
{
    int instance;               /*!< Instance number. Needed to identify 
                                     instance. */
    MsfGadgetHandle gadgetHandle; /*!< The handle of the created gadget. */
    MsfSize gadgetSize;         /*!< The size of the rendered gadget. */
    SmtrLinkEntry *links;        /*!< A list of found links in text if 
                                     applicable. NULL if returnLinks is FALSE*/
}SmtrCreateRspData;

/*!
 * \brief Create a text box in current window.
 * 
 * \param stringHandle Handle of the text string to display in the text box. 
 * \param prop Properties of the text box. See #SMTRCreateTextBoxProperties.
 * \param rsp An allocated #SMTRCreateRspData struct containing the result of the 
 *            operation. It is up to the caller to deallocate the struct with a 
 *            call to SMTRFreeSMTRLinkEntry().
 * \return SMTR_RESULT_OK on success, otherwise the proper result code.
 *****************************************************************************/
SmtrResult smtrCreateTextBox(MsfStringHandle stringHandle, 
    const SmtrCreateTextBoxProperties *prop, SmtrCreateRspData **rsp);
                                   
/*!
 * \brief Deletes a text box. Note that this function will not remove the
 *        gadget from the form. The removal must be done prior to the call to
 *        SMTRDeleteTextBox().
 * 
 * \param instance The text box instance.
 * \return SMTR_RESULT_OK on success, otherwise the proper result code.
 *****************************************************************************/
SmtrResult smtrDeleteTextBox(int instance);

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
SmtrResult smtrRedraw(int instance, MsfEventType event, MSF_BOOL *lostFocus);

/*!
 * \brief Checks if any link is active (is selected) in current text box.
 *        The function will allocate data for the #SMTRLinkEntry link if
 *        the functions returns TRUE, otherwise no memory will be allocated
 *        and link will be set to NULL.
 * \param instance The text box instance.
 * \param link The returned link if active, otherwise NULL.
 * \return TRUE if a link is active, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smtrHasActiveLink(int instance, SmtrLinkEntry **link);

/*!
 * \brief Deallocates a #SMTRCreateRspData struct.
 * 
 * \param data The data to free.
 *****************************************************************************/
void smtrFreeSmtrCreateRspData(SmtrCreateRspData **data);

/*!
 * \brief Deallocates a #SMTRLinkEntry struct.
 * 
 * \param data The data to free.
 *****************************************************************************/
void smtrFreeSmtrLinkEntry(SmtrLinkEntry **data);

#endif


