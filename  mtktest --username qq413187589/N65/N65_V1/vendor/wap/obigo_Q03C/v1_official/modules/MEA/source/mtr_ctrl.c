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

/*! \file mtr_ctrl.c
 *  This file contains the control logic for rendering/viewing a text.
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_mem.h"

/* MEA */
#include "mamem.h"

/* MTR */
#include "mtr.h"
#include "mtr_cmn.h"
#include "mtr_par.h"
#include "mtr_rend.h"
#include "mtr_ctrl.h"

/******************************************************************************
 * Constants
 *****************************************************************************/
/*!< Defines the maximum number of concurrent text boxes */
#define MTR_MAX_INSTANCES 5

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/******************************************************************************
 * Static variables
 *****************************************************************************/
/*lint -e{621}*/
static MtrInstance *mtrTextBoxes[MTR_MAX_INSTANCES];
#ifndef WIDGET_ADVANCED_SMIL_EDITOR
static MtrInstance *currInst;
#endif /* ~WIDGET_ADVANCED_SMIL_EDITOR */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static MtrInstance *createInstance(MsfStringHandle stringHandle,
    const MtrCreateTextBoxProperties *prop);
                                   
static void deleteInstance(MtrInstance **inst);

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief Initializes the MTR component
 *****************************************************************************/
void mtrCtrlInit(void)
{
    memset(mtrTextBoxes, 0, sizeof(MtrInstance*) * MTR_MAX_INSTANCES);
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MTR, 
        MTR_CTRL_BA5C1403F6CD4F357617F392BA773496, "MTR CTRL: initialized\n"));
}

/*!
 * \brief Terminates the MTR component
 *****************************************************************************/
void mtrCtrlTerminate(void)
{
    /* Delete all instances */
    deleteInstance(NULL);
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MTR, MTR_CTRL_E7A811331EDB724B8862EEA47A75ADF4, "MTR CTRL: terminated\n"));

}

/*!
 * \brief Creates a new text box instance.
 *
 * \param stringHandle The string handle of the string to show.
 * \param prop The user defined properties of the text box.
 * \return The new instance or NULL if no new instance could be created.
 *****************************************************************************/
static MtrInstance *createInstance(MsfStringHandle stringHandle,
                                   const MtrCreateTextBoxProperties *prop)
{
    int i;
    /* Find an empty slot. */
    for(i = 0; i < MTR_MAX_INSTANCES; i++)
    {
        if (NULL == mtrTextBoxes[i])
        {
            mtrTextBoxes[i] = MSF_MEM_ALLOCTYPE(MSF_MODID_MTR, MtrInstance);
            memset(mtrTextBoxes[i], 0, sizeof(MtrInstance));
            mtrTextBoxes[i]->instance = i;
            memcpy(&mtrTextBoxes[i]->boxSize, &prop->size, sizeof(MsfSize));
            mtrTextBoxes[i]->stringHandle = stringHandle;
            memcpy(&(mtrTextBoxes[i]->prop), prop, 
                sizeof(MtrCreateTextBoxProperties));
            return mtrTextBoxes[i];
        }
    }
    return NULL;
}

/*!
 * \brief Deallocates a #MtrInstance struct.
 * 
 * \param inst The instance to free. If inst is NULL then all instances will
 * be removed.
 *****************************************************************************/
static void deleteInstance(MtrInstance **inst)
{
    int i;
    if (inst) 
    {
        if (*inst)
        {
            if ((*inst)->gadgetHandle > 0) 
            {
                (void)MSF_WIDGET_RELEASE((*inst)->gadgetHandle);
            }
            
            mtrFreeParseResult(&((*inst)->parse));
            if ((*inst)->charBuffer) 
            {
                MTR_FREE((*inst)->charBuffer);
            }
            MTR_FREE(*inst);
            *inst = NULL;
        }
    }
    else
    {
        /* Remove all instances */
        for(i = 0; i < MTR_MAX_INSTANCES; i++)
        {
            deleteInstance(&mtrTextBoxes[i]);
        }        
    }
}

#ifndef WIDGET_ADVANCED_SMIL_EDITOR
/*!
 * \brief Draws a link and the space before it if it exists.
 * \param imgHandle
 * \param strHandle
 * \param link
 * \param pos
 * \param index
 * \param chars
 * \param size
 * \return The new index on success, otherwise -1.
 *****************************************************************************/
static int textToImageEndIndex(MsfStringHandle strHandle,
    MsfSize *size, MSF_INT16 maxWidth, MSF_INT16 maxHeight)
{
    int tmp, strPos = 0, oldStrPos = 0;
    int visibleChars;
    int totalChars;
    int index, lastIndex;
    int gadgetHeight;
    char *tPos;
    MsfSize tmpSize = {0, 0};
    MsfSize rowSize = {0, 0};
    MsfPosition pos = {0, 0};
    int fontHeight;
    MsfFont font;
    MSF_BOOL firstLine = TRUE;
    MSF_BOOL vertResize, horizResize;
    
    if (0 == maxWidth) 
    {
        return 0;
    }
    /* Check flags */
    vertResize = IS_SET(currInst->prop.flags, MTR_PROP_VERTICAL_RESIZE);
    horizResize = IS_SET(currInst->prop.flags, MTR_PROP_HORIZONTAL_RESIZE);

    /* Get the total number of characters. */
    totalChars = MSF_WIDGET_STRING_GET_LENGTH(strHandle, 0, MsfUtf8);
    currInst->totalLength = totalChars; 
    /* Get the font to determine the height */
    if (MSF_WIDGET_GET_FONT(strHandle, &font) < 0)
    {
        return FALSE;
    }
    /* Get the heigh of the text in order to calculate the height of the 
    gadget later on */
    if (MSF_WIDGET_FONT_GET_VALUES(&font, &tmp, &fontHeight, &tmp) < 0)
    {
        return FALSE;
    }
    
    /* Check if the text can be displayed on one line */
    index = currInst->currentIndex;
    /* Ugly work but somebody is got to do it */
    tPos = &currInst->charBuffer[0];
    tPos = msf_cmmn_utf8_str_incr(tPos, index);
    oldStrPos = strPos = tPos - &currInst->charBuffer[0];
    
    if (MSF_WIDGET_STRING_GET_VISIBLE(strHandle, 0, size, index, 1, 
        &visibleChars, &tmp, &tmp) < 0)
    {
        return FALSE;
    }
    /* At least one line must be visible */
    if (vertResize) 
    {
        tmpSize.height = 0; 
    }
    else 
    {
        tmpSize.height = (MSF_INT16)maxHeight; 
    }
    tmpSize.width = (MSF_INT16)maxWidth;
    gadgetHeight = 0;
    if (visibleChars == totalChars)
    {
        /* The text can be displayed on one line*/
		return 0;
    }
    else
    {
        /* The text needs multiple line, iterate until all lines fits */
        size->height = (MSF_INT16)(maxHeight ? maxHeight : 0x7FFF);
        do 
        {
            lastIndex = index;
            /* Add the visible height */
            gadgetHeight = (MSF_UINT16)(gadgetHeight + fontHeight + 1);
            /* Check how many characters that can be displayed */
            
            if (MSF_WIDGET_STRING_GET_VISIBLE(strHandle, 0, &tmpSize, 
                index, 1, &visibleChars, &tmp, &tmp) < 0)
            {
                return FALSE;
            }
            tPos = &currInst->charBuffer[strPos];
            tPos = msf_cmmn_utf8_str_incr(tPos, visibleChars);
            strPos = (tPos - &currInst->charBuffer[strPos]) + strPos;
            /* Prevent infinite loops */
            if (!visibleChars) 
            {
                break;
            }
            if (firstLine) 
            {
                currInst->nextIndex = index + visibleChars;
                firstLine = FALSE;
            }

            index += visibleChars;
        	/* Iterate until all characters are visible */
        } while (index < totalChars && (gadgetHeight + fontHeight + 
            1) <= size->height);

        currInst->currentEndIndex = lastIndex;
        currInst->nextEndIndex = index;

        if (vertResize && gadgetHeight < maxHeight)
        {
            size->height = (MSF_INT16)gadgetHeight;
        }
        else
        {
            size->height = maxHeight;
        }

        size->width  = maxWidth;
    }

    /* Draw the text on the image */
    index = currInst->currentIndex;
    strPos = oldStrPos;
    do
    {
        /* Check how many characters that can be displayed */
        if (MSF_WIDGET_STRING_GET_VISIBLE(strHandle, 0, size, index, 1, 
            &visibleChars, &tmp, &tmp) < 0)
        {
            return FALSE;
        }
        lastIndex = index;
        tmp = 0;
        tPos = &currInst->charBuffer[strPos];
        tPos = msf_cmmn_utf8_str_incr(tPos, visibleChars);
        strPos = (tPos - &currInst->charBuffer[strPos]) + strPos;
        if (!visibleChars)
        {
            /* Go pass any newline characters */
            index += tmp;
        }
        else 
		{
            if (MSF_WIDGET_STRING_GET_SUB_SIZE(strHandle, 0, index, visibleChars, 0, 
                &tmpSize) < 0)
            {
                return FALSE;
            }
            if (currInst->prop.alignment == MsfRight)
                pos.x = (MSF_UINT16)(size->width - rowSize.width);
            else if (currInst->prop.alignment == MsfCenter)
                /* Center the text */
                pos.x = (MSF_INT16)((MSF_UINT16)(size->width - tmpSize.width)>>1);
            index += visibleChars;
            /* Go pass any new-line characters */
            index += tmp;
        }
        /* Next line */
        pos.y = (MSF_INT16)(pos.y + fontHeight + 1);
        /* Iterate until all characters are visible */
    } while (lastIndex != index && index <= currInst->currentEndIndex);
        
    if (index == totalChars)
    {
        return 0;
    }
    return index;
}

/*!
 * \brief 
 *
 * \param item Data for the new instance.
 * \return The new instance or NULL if no new instance could be created.
 *****************************************************************************/
static int mtrRenderEndIndex(MtrInstance *inst)
{
    MsfSize *size;
    currInst = inst;
    size = &inst->actualSize;
    size->width = inst->boxSize.width;
    size->height = 0;
    
    inst->currentIndex = inst->prevIndex = inst->nextIndex = 0;
    return textToImageEndIndex(inst->stringHandle,
        size, size->width, inst->boxSize.height);
}

/*!
 * \brief Get the end index of TextBox
 * 
 * \param stringHandle Handle of the text string to display in the text box. 
 * \return end index on success, otherwise -1.
 *****************************************************************************/
int mtrGetTextBoxEndIndex(MsfStringHandle stringHandle, 
    const MtrCreateTextBoxProperties *prop)
{
    MtrInstance *inst;
	int endIndex;

    /* We don't accept empty strings */
    if (MSF_WIDGET_STRING_GET_LENGTH(stringHandle, 0, MsfUtf8) <= 0) 
    {
        return -1;
    }
    /* Create a new text box instance */
    if (NULL == (inst = createInstance(stringHandle, prop)))
    {
        return -1;
    }
    /* Save flags */
    //flags = prop->flags;
	
    inst->charBuffer = mtrGetStringBufferFromHandle(inst->stringHandle);

	/* Render screen to get the end index, get -1 if error*/
	endIndex = mtrRenderEndIndex(inst);
    //deleteInstance(&inst);
    deleteInstance(&mtrTextBoxes[inst->instance]);
	return endIndex;
}
#endif /* ~WIDGET_ADVANCED_SMIL_EDITOR */

/*!
 * \brief Create a text box
 * 
 * \param stringHandle Handle of the text string to display in the text box. 
 * \param prop Properties of the text box. See #MtrCreateTextBoxProperties.
 * \return MTR_RESULT_OK on success, otherwise the proper error code.
 *****************************************************************************/
MtrResult mtrCreateTextBox(MsfStringHandle stringHandle, 
    const MtrCreateTextBoxProperties *prop, MtrCreateRspData **rsp)
{
    MtrInstance *inst;
    MSF_UINT32 flags;
    *rsp = NULL;

    /* We don't accept empty strings */
    if (MSF_WIDGET_STRING_GET_LENGTH(stringHandle, 0, MsfUtf8) <= 0) 
    {
        *rsp = NULL;
        return MTR_RESULT_ERROR;
    }
    /* Create a new text box instance */
    if (NULL == (inst = createInstance(stringHandle, prop)))
    {
        return MTR_RESULT_BUSY;
    }
    /* Save flags */
    flags = prop->flags;
    /* Only parse if user wants to */
    if (IS_SET(flags, MTR_PROP_RENDER_LINKS) ||
        IS_SET(flags, MTR_PROP_RETURN_LINKS)) 
    {
        if (mtrParse(inst) < 0) 
        {
            deleteInstance(&inst);
            return MTR_RESULT_ERROR;
        }
    }
    /* Render screen */
    if (mtrRender(inst) < 0) 
    {
        deleteInstance(&inst);
        return MTR_RESULT_ERROR;        
    }
    /* Create response data */
    *rsp = MSF_MEM_ALLOCTYPE(MSF_MODID_MTR, MtrCreateRspData);
    memset(*rsp, 0, sizeof(MtrCreateRspData));
    (*rsp)->instance = inst->instance;
    (*rsp)->gadgetHandle = inst->gadgetHandle;
    memcpy(&(*rsp)->gadgetSize, &inst->actualSize, sizeof(MsfSize));
    if (IS_SET(flags, MTR_PROP_RETURN_LINKS))
    {
        if (!mtrCopyLinkList(inst->parse, &(*rsp)->links))
        {
            return MTR_RESULT_ERROR;
        }
    }
    return MTR_RESULT_OK;
}

/*!
 * \brief Deletes a text box.
 * 
 * \param callerFsm Caller FSM
 * \param returnSignal The signal to return when done.
 * \param instance The text box instance.
 *****************************************************************************/
MtrResult mtrDeleteTextBox(int instance)
{
    if (instance < 0 || instance >= MTR_MAX_INSTANCES) 
    {
        return MTR_RESULT_ERROR;
    }
    deleteInstance(&mtrTextBoxes[instance]);
    return MTR_RESULT_OK;
}

/*!
 * \brief Checks if any link is active (is selected) in current text box.
 *        The function will allocate data for the MtrLinkEntry link if
 *        the functions returns TRUE, otherwise no memory will be allocated
 *        and link will be set to NULL.
 * \param instance The text box instance.
 * \param link The returned link if active, otherwise NULL.
 * \return TRUE if a link is active, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL mtrHasActiveLink(int instance, MtrLinkEntry **link)
{
    MtrInstance *inst = NULL;

    if (NULL == link) 
    {
        return FALSE;
    }
    *link = NULL;
    if (instance < 0 || instance >= MTR_MAX_INSTANCES) 
    {
        return FALSE;
    }
    inst = mtrTextBoxes[instance];
    if (NULL != inst->selectedLink) 
    {
        *link = (MtrLinkEntry*)MTR_ALLOC(sizeof(MtrLinkEntry));
        (*link)->link = mtrStrDup(inst->selectedLink->link);
        (*link)->scheme = inst->selectedLink->scheme;
        (*link)->next = NULL;
        return TRUE;
    }
    return FALSE;
}

/*!
 * \brief Deallocates a MtrCreateRspData struct.
 * 
 * \param data The data to free.
 *****************************************************************************/
void mtrFreeMtrCreateRspData(MtrCreateRspData **data)
{
    mtrFreeLinks(&((*data)->links));
    MSF_MEM_FREE(MSF_MODID_MTR, *data);
    *data = NULL;
}

/*!
 * \brief Deallocates a #MtrLinkEntry struct.
 * 
 * \param data The data to free.
 *****************************************************************************/
void mtrFreeMtrLinkEntry(MtrLinkEntry **data)
{
    mtrFreeLinks(data);
}


/*!
 * \brief Redraws the text box according to current event.
 * 
 * \param instance The text box instance.
 * \param event The event that causes the text box to redraw.
 * \param lostFocus (out) This parameter will be set to TRUE if the text box
 *                  will loose focus due to the event.
*****************************************************************************/
MtrResult mtrRedraw(int instance, MsfEventType event, MSF_BOOL *lostFocus)
{
    MtrInstance *inst;
    if (instance < 0 || instance >= MTR_MAX_INSTANCES) 
    {
        return MTR_RESULT_ERROR;
    }
    if (NULL == (inst = mtrTextBoxes[instance]))
    {
        return MTR_RESULT_ERROR;
    }
    inst->currentEvent = event;
    inst->redraw = TRUE;
    if (FALSE == mtrRender(inst))
    {
        return MTR_RESULT_ERROR;
    }
    *lostFocus = inst->lostFocus;
    return MTR_RESULT_OK;
}

