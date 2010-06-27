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

/*!\file mauiform.c
 * \brief Common input forms.
 */

/* MSF */
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_lib.h"
#include "msf_def.h"
#include "msf_log.h"
#include "msf_cfg.h"

/* MEA */
#include "maintsig.h"
#include "mea_rc.h"
#include "mea_def.h"
#include "mauicmn.h"
#include "mamem.h"
#include "mauiform.h"
#include "mauisig.h"
#ifdef WAP_SUPPORT
#include "widget_extension.h"
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Const
 *****************************************************************************/
const MsfAlignment meaInputPos = {MsfHigh, MsfLeft};

/*! The maximum number of concurrent input form items */
#define MEA_MAX_INPUT_FORMS     4

/*! \enum MeaInputFormAction
 *  Actions related to the input form */
typedef enum
{
    MEA_INPUT_FORM_NO_OP,  /* !< */
    MEA_INPUT_FORM_OK,     /* !< The End User presses ok */
    MEA_INPUT_FORM_CANCEL  /* !< The End USer presses cancel */
}MeaInputFormAction;

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/* !\struct MeaInputForm 
 *  \brief Data-structure for radio button input 
 */
typedef struct
{
    MsfWindowHandle winHandle;      /* !< The window handle */
    MsfGadgetHandle gadgetHandle;   /* !< The gadget handle */
    MeaInputItem    item;           /* !< See #MeaInputItem */
} MeaInputForm;

/******************************************************************************
 * Static data
 *****************************************************************************/
static MeaInputForm *meaInputForm[MEA_MAX_INPUT_FORMS];

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void meaHandleOkFormAction(MsfWindowHandle winHandle);
static void meaHandleBackFormAction(MsfWindowHandle winHandle);
static void deleteInputForm(MsfWindowHandle winHandle,
                            MeaInputFormAction action);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Initiates the input form handling.
 *
 *****************************************************************************/
void meaInitForms(void)
{
    /* Set all instance pointers to zero */
    memset(meaInputForm, 0, sizeof(MeaInputForm*)*MEA_MAX_INPUT_FORMS);
}

/*!
 * \brief Terminates and de-allocates the input form handling.
 *
 *****************************************************************************/
void meaTerminateForms(void)
{
    memset(meaInputForm, 0, sizeof(MeaInputForm*)*MEA_MAX_INPUT_FORMS);
    /* Delete all instances */
    deleteInputForm(0, MEA_INPUT_FORM_NO_OP);
}

/*!
 * \brief Finds the instance matching a widget action.
 * 
 * \param winHandle The window that generated the action.
 * \return A pointer to the instance (with reference to the winHandle) or NULL
 *         if not valid.
 *****************************************************************************/
static MeaInputForm *getInstance(MsfWindowHandle winHandle)
{
    int i;
    /* Go through all slots and find the current corresponding instance */
    for(i = 0; i < MEA_MAX_INPUT_FORMS; i++)
    {
        /* Return the matching instance */
        if ((NULL != meaInputForm[i]) && (meaInputForm[i]->winHandle == 
            winHandle))
        {
            return meaInputForm[i];
        }
    }
    return NULL;
}

/*!
 * \brief Creates a new instance.
 *
 * \param item Data for the new instance.
 * \return The new instance or NULL if no new instance could be created.
 *****************************************************************************/
static MeaInputForm *createInstance(const MeaInputItem *item)
{
    int i;
    /* Find an empty slot */
    for(i = 0; i < MEA_MAX_INPUT_FORMS; i++)
    {
        if (NULL == meaInputForm[i])
        {
            meaInputForm[i] = MEA_ALLOC(sizeof(MeaInputForm));
            memset(meaInputForm[i], 0, sizeof(MeaInputForm));
            memcpy(&(meaInputForm[i]->item), item, sizeof(MeaInputItem));
            return meaInputForm[i];
        }
    }
    return NULL;
}

/*!
 * \brief Creates a input form.
 *
 * \param item The type of input form to create.
 * \param titleStrHandle The title of the form.
 * \return TRUE of successful, otherwise FALSE:
 *****************************************************************************/
MSF_BOOL meaCreateInputForm(const MeaInputItem *item, 
    MSF_UINT32 titleStrHandle)
{
    int i;
    MsfStringHandle strHandle;
    MeaInputForm *inst;
    MsfActionHandle actionHandle;
    const MsfSize maxSize = {MEA_GADGET_DEF_HEIGHT, MEA_GADGET_DEF_WIDTH};
    MsfSize newSize = {0, 0};
    
    actionHandle = 0;
    
    if (NULL == (inst = createInstance(item)))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIFORM_46E7974CE7354600D97E60808E9536EF, "(%s) (%d) Input form instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }
    /* Do not copy the list of elements */
    inst->item.items = NULL;
    /* Create gadget */
    switch(item->type)
    {
    case MEA_SINGLE_LINE_INPUT:
        /* Create string handle */
        if (NULL != item->text)
        {
            if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
                item->text, MsfUtf8, strlen(item->text) + 1, 0)))
            {
                return FALSE;
            }
        }
        else
        {
            if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
                "", MsfUtf8, 1, 0)))
            {
                return FALSE;
            }
        }
        if (0 == (inst->winHandle = MSF_WIDGET_FORM_CREATE(
            MSF_MODID_MEA, NULL, 0, 0)))
        {
            (void)MSF_WIDGET_RELEASE(strHandle);
            return FALSE;
        }
        if (0 == (inst->gadgetHandle = 
            MSF_WIDGET_TEXT_INPUT_CREATE(MSF_MODID_MEA, 
            meaGetEmptyStringHandle(), strHandle, item->textType, 
            (int)item->maxTextSize, TRUE, NULL, MSF_GADGET_PROPERTY_FOCUS, 0)))
        {
            (void)MSF_WIDGET_RELEASE(strHandle);
            (void)MSF_WIDGET_RELEASE(inst->winHandle);
            inst->winHandle = 0;
        }
        /* Calculate optimal size of gadget */
        meaCalculateStringGadgetSize(inst->winHandle, inst->gadgetHandle,
            strHandle, (MsfPosition*)&meaInputPos, (MsfSize*)&maxSize, 
            &newSize, FALSE);
        (void)MSF_WIDGET_SET_SIZE(inst->gadgetHandle, &newSize);

        (void)MSF_WIDGET_RELEASE(strHandle);
        if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(inst->winHandle, 
            inst->gadgetHandle, NULL, (MsfAlignment *)&meaInputPos))
        {
            (void)MSF_WIDGET_RELEASE(inst->winHandle);
            inst->winHandle = 0;
            (void)MSF_WIDGET_RELEASE(inst->gadgetHandle);
            inst->gadgetHandle = 0;
            return FALSE;
        }
        break;
    case MEA_TEXT_INPUT:
        /* Create string handle */
        if (NULL != item->text)
        {
            if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
                item->text, MsfUtf8, strlen(item->text) + 1, 0)))
            {
                return FALSE;
            }
        }
        else
        {
            if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
                "", MsfUtf8, 1, 0)))
            {
                return FALSE;
            }
        }
        /* Create editor */
        if (0 == (inst->winHandle = MSF_WIDGET_EDITOR_CREATE(
            MSF_MODID_MEA, meaGetEmptyStringHandle(), strHandle,
            item->textType, (int)item->maxTextSize, 
            (MEA_TEXT_INPUT == item->type), NULL, 0, 0)))
        {
            (void)MSF_WIDGET_RELEASE(strHandle);
            return FALSE;
        }
        (void)MSF_WIDGET_RELEASE(strHandle);
        break;
    case MEA_RADIO_BUTTON_INPUT:
        /* Create radio button list */
        if (0 == (inst->winHandle = MSF_WIDGET_MENU_CREATE(
            MSF_MODID_MEA, MsfExclusiveChoice, NULL, 0, NULL,
            MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_ICON, 0, 0)))
        {
            return FALSE;
        }
        /* Add items to the list */
        for(i = 0; 0 != item->items[i]; i++)
        {
            if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(inst->winHandle,
                i, item->items[i], 0, 0, 0, TRUE))
            {
                (void)MSF_WIDGET_RELEASE(inst->winHandle);
                return FALSE;
            }
        }
        /* Set selected index */
        if ((inst->item.selectedItem < i) && (i >= 0))
        {
            (void)MSF_WIDGET_CHOICE_SET_ELEM_STATE(inst->winHandle, 
                    inst->item.selectedItem, MSF_CHOICE_ELEMENT_SELECTED);
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAUIFORM_7C3400E063A6C6DC06716EB479BBE41B, "(%s) (%d) erroneous selected index!\n", __FILE__, __LINE__));
        }
        break;
    case MEA_SELECT_INPUT:
        actionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA,
            MEA_GET_STR_ID(MEA_STR_ID_OK), MsfSelect, 0, 
            MSF_ACTION_PROPERTY_ENABLED);
        if (0 == (inst->winHandle = MSF_WIDGET_MENU_CREATE(
            MSF_MODID_MEA, MsfImplicitChoice, NULL, actionHandle, NULL,
            MSF_CHOICE_ELEMENT_STRING_1, 0, 0)))
        {
            return FALSE;
        }
        /* Add items to the list */
        for(i = 0; 0 != item->items[i]; i++)
        {
#ifdef WAP_SUPPORT
            if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(inst->winHandle,
                i, item->items[i], 0, meaGetListNumImage(i), 0, TRUE))
#else
            if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(inst->winHandle,
                i, item->items[i], 0, 0, 0, TRUE))
#endif /* WAP_SUPPORT */
            {
                (void)MSF_WIDGET_RELEASE(inst->winHandle);
                return FALSE;
            }
        }
        /* Set selected index */
        if ((inst->item.selectedItem < i) && (i >= 0))
        {
            (void)MSF_WIDGET_CHOICE_SET_ELEM_STATE(inst->winHandle, 
                    inst->item.selectedItem, MSF_CHOICE_ELEMENT_SELECTED);
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAUIFORM_7C3400E063A6C6DC06716EB479BBE41B, "(%s) (%d) erroneous selected index!\n", __FILE__, __LINE__));
        }
        break;
    }
    /* Actions */
    if (MEA_SELECT_INPUT == item->type)
    {
        if (!meaRegisterAction(inst->winHandle, actionHandle, 
            meaHandleOkFormAction, 0, 0))
        {
            (void)MSF_WIDGET_RELEASE(actionHandle);
            return FALSE;
        }
        /* Back action */
        if (0 == meaCreateAction(inst->winHandle, MsfBack, meaHandleBackFormAction, 
            0, 0, MEA_STR_ID_BACK))
        {
            return FALSE;
        }
    }
    else
    {
        if (0 == meaCreateAction(inst->winHandle, MsfOk, meaHandleOkFormAction, 
            0, 0, MEA_STR_ID_OK))
        {
            return FALSE;
        }
        /* Cancel action */
        if (0 == meaCreateAction(inst->winHandle, MsfCancel, meaHandleBackFormAction, 
            0, 0, MEA_STR_ID_CANCEL))
        {
            return FALSE;
        }
    }

    /* Set title*/
    if (!meaSetTitle(inst->winHandle, titleStrHandle, 0))
    {
        return FALSE;
    }
#ifdef WAP_SUPPORT
    //MSF_WIDGET_WINDOW_SET_PROPERTIES(inst->winHandle, (int) MSF_WINDOW_PROPERTY_EXT_DISABLE_RIGHT_ARROW | MSF_WINDOW_PROPERTY_TITLE);
#endif /* WAP_SUPPORT */
    /* Display form */
    return meaDisplayWindow(inst->winHandle, meaGetPosLeftTop());
}

/*!
 *  \brief Deletes the current input form.
 *
 *  \param winHandle The window handle of the instance to delete or 0 to delete
 *                  all instances.
 *  \param action Tells the reason why the function was called. See
 *                #MeaInputFormAction for possible values.
 *****************************************************************************/
static void deleteInputForm(MsfWindowHandle winHandle, 
    MeaInputFormAction action)
{
    MeaInputForm *currItem;
    int i;
    void *ptr = NULL;
    unsigned int value = 0;
    MeaInputActionBackCallBack callback;

    /*lint -e{611} */
    callback = (MeaInputActionBackCallBack)NULL;

    if (0 != winHandle)
    {
        if (0 != (currItem = getInstance(winHandle)))
        {
            /*  Save values before we deallocates the instance in case 
             *  we need them later */
            callback = currItem->item.backCallback;
            value = currItem->item.uintValue;
            ptr = currItem->item.dataPtr;

            /* Remove the gadget if it has been created */
            if (0 != currItem->gadgetHandle)
            {
                (void)MSF_WIDGET_RELEASE(currItem->gadgetHandle);
            }
            /* Remove the window and its actions */
            (void)meaDeleteWindow(currItem->winHandle);
            /* Delete the instance */
            /*lint -e{774}*/
            MEA_FREE(currItem);
            for(i = 0; i < MEA_MAX_INPUT_FORMS; i++)
            {
                if (currItem == meaInputForm[i])
                {
                    meaInputForm[i] = NULL;
                    break;
                }
            }
        }
    }
    else
    {
        /* Delete all instances */
        for (i = 0; i < MEA_MAX_INPUT_FORMS; i++)
        {
            if (NULL != meaInputForm[i])
            {
                if (0 != meaInputForm[i]->gadgetHandle)
                {
                    (void)MSF_WIDGET_RELEASE(meaInputForm[i]->gadgetHandle);
                }
                /* Remove the window and its actions */
                (void)meaDeleteWindow(meaInputForm[i]->winHandle);
                MEA_FREE(meaInputForm[i]);
                meaInputForm[i] = NULL;
            }
        }
    }
    /* The window is closed, tell the user about it */
    if ((NULL != callback) && (MEA_INPUT_FORM_CANCEL == action))
    {
        /* Call callback, preserve original data parameters */
        callback(ptr, value);
    }
}

/*!
 *  \brief Handles "Back" actions for the input form.
 *  \param winHandle The window handle of the current form
 *****************************************************************************/
static void meaHandleBackFormAction(MsfWindowHandle winHandle)
{
    deleteInputForm(winHandle, MEA_INPUT_FORM_CANCEL);
}

/*!
 *  \brief Handles "Ok" actions for the input form.
 *  \param winHandle The window handle of the current form
 *****************************************************************************/
static void meaHandleOkFormAction(MsfWindowHandle winHandle)
{
    char *strData;
    int intData;
    MeaInputForm *inst;

    if (NULL != (inst = getInstance(winHandle)))
    {
        strData = NULL;
        intData = 0;
        /* Get data from the form */
        switch(inst->item.type)
        {
        case MEA_SINGLE_LINE_INPUT:
            strData = meaGetTextFromGadget(inst->gadgetHandle);
            break;
        case MEA_TEXT_INPUT:
            strData = meaGetTextFromGadget(inst->winHandle);
            break;
        case MEA_SELECT_INPUT:
        case MEA_RADIO_BUTTON_INPUT:
            if ((intData = meaGetSelectedChoiceIndex(inst->winHandle)) < 0)
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MAUIFORM_0231735396647D61F06689285AC2959C, "(%s) (%d) Erroneous choice index\n", __FILE__, __LINE__));
                return;
            }
            break;
        }
        /* Check if a callback is registered */
        if (NULL != inst->item.callback)
        {
            /* Call callback, check if the form can be closed down*/
            if (inst->item.callback(strData, (unsigned)intData, 
                inst->item.dataPtr, inst->item.uintValue))
            {
                deleteInputForm(winHandle, MEA_INPUT_FORM_OK);
            }
#ifdef WAP_SUPPORT
            else
            {
                if (inst->item.type == MEA_TEXT_INPUT)
                    (void)MSF_WIDGET_SET_IN_FOCUS(winHandle, TRUE);
            }
#endif /* WAP_SUPPORT */
        }
        else
        {
            /* No callback is registered, close the form */
            deleteInputForm(winHandle, MEA_INPUT_FORM_OK);
        }
    }
}


