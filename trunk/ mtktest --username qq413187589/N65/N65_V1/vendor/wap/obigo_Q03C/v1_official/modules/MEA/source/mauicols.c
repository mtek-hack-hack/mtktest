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

/* !\file mauicols.c
 * \brief A color selector component.
 */

/* MSF */
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_lib.h"
#include "msf_def.h"
#include "msf_cfg.h"

/* MEA */
#include "maintsig.h"
#include "mea_rc.h"
#include "mea_def.h"
#include "mauicmn.h"
#include "mamem.h"
#include "mauisig.h"
#include "mauicols.h"

/******************************************************************************
 * Const
 *****************************************************************************/
#define MEA_COLOR_SEL_SIZE              (30)
#define MEA_COLOR_SEL_PADDING           (5)
#define MEA_COLOR_SEL_WIDTH             (MEA_COLOR_SEL_SIZE + MEA_COLOR_SEL_PADDING)
#define MEA_COLOR_SEL_HEIGHT            (MEA_COLOR_SEL_SIZE + MEA_COLOR_SEL_PADDING)
#define MEA_COLOR_SEL_BORDER_SIZE       (2)

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/*!\struct MeaGadgetColItem
 * \brief Data-structure to keep track of image gadget handles and its 
 *        corresponding color.
 */
typedef struct
{
    MsfGadgetHandle handle;     /*!< The gadget handle */
    MSF_UINT32      color;      /*!< The color that is associated with the 
                                     gadget */
}MeaGadgetColItem;

/* !\struct MeaColsForm 
 *  \brief Data-structure for radio button input 
 */
typedef struct
{
    MsfWindowHandle     winHandle;      /*!< The window handle */
    MeaGadgetColItem    *colors;        /*!< A list of gadgets and its 
                                              corresponding color */
    unsigned int        gadgetsPerRow;  /*!< The total number of colors on one row */
    unsigned int        colorCount;     /*!< The total numer of colors 
                                             displayed to the End User */
    MeaStateMachine     fsm;            /*!< Callback fsm */
    int                 signal;         /*!< Callback signal */
}MeaColsForm;

/******************************************************************************
 * Static data
 *****************************************************************************/
static MeaColsForm *meaColsForm;

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static MSF_BOOL createImages(const MSF_UINT32 *colors, MSF_UINT32 colorCount, 
    const MeaColsForm *form, MSF_UINT32 hideColor, unsigned int *gadgetsPerRow);
static void meaHandleOkFormAction(MsfWindowHandle winHandle);
static void meaHandleBackFormAction(MsfWindowHandle winHandle);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Initiates the color selector handling.
 *
 *****************************************************************************/
void meaColorSelectorInit(void)
{
    /* Set all instance pointers to zero */
    meaColsForm = NULL;
}

/*!
 * \brief Terminates and de-allocates the input form handling.
 *
 *****************************************************************************/
void meaColorSelectorTerminate(void)
{
    if (NULL != meaColsForm)
    {
        meaDeleteColorSelector();
    }
}

/*! \brief Handles key press on the left arrow.
 *	
 *****************************************************************************/
static void handleLeft(MsfWindowHandle notUsed)
{
    unsigned int i;
    (void)notUsed;
    if (NULL != meaColsForm)
    {
        for(i = 0; i < meaColsForm->colorCount; i++)
        {
            if (MSF_WIDGET_HAS_FOCUS(meaColsForm->colors[i].handle))
            {
                if (i > 0)
                {
                    (void)MSF_WIDGET_SET_IN_FOCUS(
                        meaColsForm->colors[i - 1].handle, 1);
                }
                return;
            }
        }
    }
}

/*! \brief Handles key press on the right arrow.
 *	
 *****************************************************************************/
static void handleRight(MsfWindowHandle notUsed)
{
    unsigned int i;
    (void)notUsed;
    if (NULL != meaColsForm)
    {
        for(i = 0; i < meaColsForm->colorCount; i++)
        {
            if (MSF_WIDGET_HAS_FOCUS(meaColsForm->colors[i].handle))
            {
                if (i + 1 < meaColsForm->colorCount)
                {
                    (void)MSF_WIDGET_SET_IN_FOCUS(
                        meaColsForm->colors[i + 1].handle, 1);
                }
                return;
            }
        }
    }
}

/*! \brief Handles key press on the up arrow.
 *	
 *****************************************************************************/
static void handleUp(MsfWindowHandle notUsed)
{
    unsigned int i;
    int p;

    (void)notUsed;

    if (NULL != meaColsForm)
    {
        for(i = 0; i < meaColsForm->colorCount; i++)
        {
            if (MSF_WIDGET_HAS_FOCUS(meaColsForm->colors[i].handle))
            {
                p = i - meaColsForm->gadgetsPerRow;
                if (p >= 0)
                {
                    (void)MSF_WIDGET_SET_IN_FOCUS(
                        meaColsForm->colors[i - meaColsForm->gadgetsPerRow].handle,
                        1);
                }
                return;
            }
        }
    }
}

/*! \brief Handles key press on the down arrow.
 *	
 *****************************************************************************/
static void handleDown(MsfWindowHandle notUsed)
{
    unsigned int i;
    (void)notUsed;
    if (NULL != meaColsForm)
    {
        for(i = 0; i < meaColsForm->colorCount; i++)
        {
            if (MSF_WIDGET_HAS_FOCUS(meaColsForm->colors[i].handle))
            {
                if (i + meaColsForm->gadgetsPerRow < meaColsForm->colorCount)
                {
                    (void)MSF_WIDGET_SET_IN_FOCUS(
                        meaColsForm->colors[i + meaColsForm->gadgetsPerRow].handle, 
                        1);
                }
                return;
            }
        }
    }
}

/*! \brief Creates a matrix of possible colors to input
 *
 * \param colors A list of colors to display to the End User.
 * \param colorCount The total number of colors in the list
 * \param form The current instance
 * \param hideColor A color to exclude from the list
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL createImages(const MSF_UINT32 *colors, MSF_UINT32 colorCount, 
    const MeaColsForm *form, MSF_UINT32 hideColor, unsigned int *gadgetsPerRow)
{
    unsigned int    i;
    unsigned int    p;
    MsfSize         size = {MEA_COLOR_SEL_SIZE, MEA_COLOR_SEL_SIZE};
    MsfSize         size2 = {MEA_COLOR_SEL_SIZE - MEA_COLOR_SEL_BORDER_SIZE, 
                             MEA_COLOR_SEL_SIZE - MEA_COLOR_SEL_BORDER_SIZE};
    MsfSize         dSize;
    MsfPosition     pos = {1, 1};
    MsfPosition     currPos = {MEA_COLOR_SEL_PADDING, MEA_COLOR_SEL_PADDING};
    MsfColor        black = {0, 0, 0};
    MsfColor        col;
    MsfBrushHandle  brush;
    MsfImageHandle  handle;
    MsfGadgetHandle gadgetHandle;

    /* Get the current display width */
    (void)MSF_WIDGET_WINDOW_SPECIFIC_SIZE(meaColsForm->winHandle , &dSize, 1);
    *gadgetsPerRow = (unsigned int)(dSize.width / (MEA_COLOR_SEL_PADDING + MEA_COLOR_SEL_WIDTH));
    /* Create images */
    for (p = i = 0; i < colorCount; ++i)
    {
        /* Do not display the color to hide */
        if (hideColor == colors[i])
        {
            continue;
        }
        /* Create the image */
        if (0 == (handle = MSF_WIDGET_IMAGE_CREATE_EMPTY(MSF_MODID_MEA, &size, 0)))
        {
            return FALSE;
        }
        brush = MSF_WIDGET_GET_BRUSH(handle);
        /* Set the current color */
        meaIntToMsfColor(colors[i], &col);
        if (MSF_WIDGET_SET_COLOR(brush, &col, 1) < 0)
        {
            (void)MSF_WIDGET_RELEASE(handle);
            return FALSE;
        }
        if (MSF_WIDGET_SET_COLOR(brush, &black, 0) < 0)
        {
            (void)MSF_WIDGET_RELEASE(handle);
            return FALSE;
        }
        /* Paint the image  rect */
        if (MSF_WIDGET_DRAW_RECT(handle, &pos, &size2, 1) < 0)
        {
            (void)MSF_WIDGET_RELEASE(handle);
            return FALSE;
        }
        if (0 == (gadgetHandle = MSF_WIDGET_IMAGE_GADGET_CREATE(MSF_MODID_MEA, 
            handle, &size, MsfImageZoom100, MSF_GADGET_PROPERTY_FOCUS, 0)))
        {
            (void)MSF_WIDGET_RELEASE(handle);
            return FALSE;
        }
        (void)MSF_WIDGET_RELEASE(handle);
        /* Release the gadgetHandle later, the handle is needed in order to
           find the focus */
        meaColsForm->colors[p].handle = gadgetHandle;
        /* Check so that there are room left on the "line" */
        if (p > 0 && (p % *gadgetsPerRow) == 0)
        {
            currPos.y += (MSF_UINT16)MEA_COLOR_SEL_HEIGHT;
            currPos.x = MEA_COLOR_SEL_PADDING;
        }

        /* Bind the image to the form */
        if (MSF_WIDGET_WINDOW_ADD_GADGET(form->winHandle, gadgetHandle, 
            &currPos, NULL) < 0)
        {
            return FALSE;
        }

        /* Update the color table */
        form->colors[p].color = colors[i];
        ++p;
        /* Next item one step to the right */
        /*lint -e{571,713} */
        currPos.x = (MSF_UINT16)(currPos.x + MEA_COLOR_SEL_WIDTH + 
            MEA_COLOR_SEL_PADDING);
    }
    return TRUE;
}

/*! \brief Handles the [OK] action for the color selector form.
 *
 * \param notUsed The handle of the form that generated the action.
 *****************************************************************************/
static void meaHandleOkFormAction(MsfWindowHandle notUsed)
{
    MSF_UINT32 color = 0;
    unsigned int i;

    (void)notUsed;

    /* Find the selected item */
    for (i = 0; i < meaColsForm->colorCount; ++i)
    {
        if (MSF_WIDGET_HAS_FOCUS(meaColsForm->colors[i].handle))
        {
            color = meaColsForm->colors[i].color;
            break;
        }
    }
    /* Send the response */
    (void)MEA_SIGNAL_SENDTO_U(meaColsForm->fsm, meaColsForm->signal, color);
    /* Delete the form */
    meaDeleteColorSelector();
}

/*! \brief Handles [Back] action for the color selection form
 *
 * \param notUsed The handle of the form that generated the action.
 *****************************************************************************/
static void meaHandleBackFormAction(MsfWindowHandle notUsed)
{
    (void)notUsed;
    /* Delete the instance */
    meaDeleteColorSelector();
}

/*! \brief Creates a color selector form, i.e., a form that the End User can
 *         select a color from a couple of predefined ones.
 *         The form is automaticaly removed if the creation failed or if [ok]
 *         or [back] action was received.
 *
 * \param colors A list of colors to display
 * \param colorCount The total number of items in the list
 * \param hideColor A color to exclude from the list 
 * \param selectedColor The color to be selected
 * \param fsm The callback FSM
 * \param signal The callback signal.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaCreateColorSelector(const MSF_UINT32 *colors, unsigned int colorCount, 
    MSF_UINT32 hideColor, MSF_UINT32 selectedColor, MeaStateMachine fsm, 
    int signal)
{
    unsigned int i;
    if (NULL != meaColsForm)
    {
        return FALSE;
    }
    /* Setup instance data */
    meaColsForm = MEA_ALLOC(sizeof(MeaColsForm));
    memset(meaColsForm, 0, sizeof(MeaColsForm));
    meaColsForm->colorCount = colorCount;
    meaColsForm->fsm        = fsm;
    meaColsForm->signal     = signal;
    /* Create the form */
    if (0 == (meaColsForm->winHandle = MSF_WIDGET_FORM_CREATE(
        MSF_MODID_MEA, NULL, 0, 0)))
    {
        (void)MSF_WIDGET_RELEASE(meaColsForm->winHandle);
        MEA_FREE(meaColsForm);
        meaColsForm = NULL;
        return FALSE;
    }

    /* Ok action */
    if (0 == meaCreateAction(meaColsForm->winHandle, MsfOk, 
        meaHandleOkFormAction, 0, 0, MEA_STR_ID_OK))
    {
        meaDeleteColorSelector();
        return FALSE;
    }
    /* Back action */
    if (0 == meaCreateAction(meaColsForm->winHandle, MsfCancel, 
        meaHandleBackFormAction, 0, 0, MEA_STR_ID_CANCEL))
    {
        meaDeleteColorSelector();
        return FALSE;
    }
    /* Create images */
    meaColsForm->colors = MEA_ALLOC(sizeof(MeaGadgetColItem)*colorCount);
    memset(meaColsForm->colors, 0, sizeof(MeaGadgetColItem)*colorCount);

    if (!createImages(colors, colorCount, meaColsForm, hideColor, 
        &meaColsForm->gadgetsPerRow))
    {
        meaDeleteColorSelector();
        return FALSE;
    }

    /* Set title*/
    if (!meaSetTitle(meaColsForm->winHandle, 
        MEA_GET_STR_ID(MEA_STR_ID_SELECT_COLOR), 0))
    {
        meaDeleteColorSelector();
        return FALSE;
    }
    /* Get navigation key notifications */
    if (!meaRegisterUserEvent(meaColsForm->winHandle, MsfKey_Left, handleLeft, 
        MEA_NOTUSED_FSM, 0) || 
        !meaRegisterUserEvent(meaColsForm->winHandle, MsfKey_Right, handleRight, 
        MEA_NOTUSED_FSM, 0) ||
        !meaRegisterUserEvent(meaColsForm->winHandle, MsfKey_Up, handleUp, 
        MEA_NOTUSED_FSM, 0) ||
        !meaRegisterUserEvent(meaColsForm->winHandle, MsfKey_Down, handleDown, 
        MEA_NOTUSED_FSM, 0))
    {
        meaDeleteColorSelector();
        return FALSE;
    }
    /* Display form */
    if (!meaDisplayWindow(meaColsForm->winHandle, meaGetPosLeftTop()))
    {
        meaDeleteColorSelector();
        return FALSE;
    }

    /* Set the correct item in focus */
    for (i = 0; i < colorCount; ++i)
    {
        if (selectedColor == meaColsForm->colors[i].color)
        {
            (void)MSF_WIDGET_SET_IN_FOCUS(meaColsForm->colors[i].handle, 1);
            break;
        }
    }
    return TRUE;
}

/*! brief Deletes the current color selector instance
 *
 *****************************************************************************/
void meaDeleteColorSelector(void)
{
    unsigned int i;
    if (NULL != meaColsForm)
    {
        /* Remove the GUI */
        if (0 != meaColsForm->winHandle)
        {
            (void)meaDeleteWindow(meaColsForm->winHandle);
        }
        /* Free all open handles */
        for (i = 0; i < meaColsForm->colorCount; ++i)
        {
            if (0 != meaColsForm->colors[i].handle)
            {
                (void)MSF_WIDGET_RELEASE(meaColsForm->colors[i].handle);
            }
        }
        /* Free the instance data */
        MEA_FREE(meaColsForm->colors);
        MEA_FREE(meaColsForm);
        meaColsForm = NULL;
    }
}


