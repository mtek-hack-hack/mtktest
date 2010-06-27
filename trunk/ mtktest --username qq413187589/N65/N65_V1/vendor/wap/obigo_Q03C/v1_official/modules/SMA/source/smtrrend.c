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

/*! \file smtrrend.c
 *  This file contains the control logic for rendering/viewing a text.
 */

/* MSF */
#ifdef WAP_SUPPORT
#include "msf_cfg.h" // For  MMI features.
#endif
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_cmmn.h"

/* SMTR */
#include "smtr.h"
#include "smtrcmn.h"
#include "smtrrend.h"

#include "sma_cfg.h"

#ifdef WIDGET_SLIDING_SMIL_SUPPORT
#include "widget_extension.h" //need include first

extern MsfWindowHandle getSlideFormHandle(void);
  #if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
extern void smaHandleScrollEvent(MsfNotificationType event);
extern void smaRegisterScrollNotif(void);
  #endif /* WIDGET_SLIDING_SMIL_VBAR && __MMI_TOUCH_SCREEN__ */
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */
/******************************************************************************
 * Constants
 *****************************************************************************/

#define IS_NEWLINE(c) ((c)==0x0A||(c)==0x0D)

#if defined( __MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)//041205 Calvin modified
#define SMTR_BASELINE_SIZE        (2)
#else
#define SMTR_BASELINE_SIZE        (0)
#endif

/******************************************************************************
 * Data-structures
 *****************************************************************************/
#ifdef WIDGET_SLIDING_SMIL_VBAR
static int totalTextHeight;
static int oneLineTextHeight;
static int currentTextOffset;
  #ifdef __MMI_TOUCH_SCREEN__
static int movedTextOffset;
  #endif /* __MMI_TOUCH_SCREEN__ */
#endif /* WIDGET_SLIDING_SMIL_VBAR */

/******************************************************************************
 * Static variables
 *****************************************************************************/
static SmtrInstance *currInst;
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
static MSF_BOOL imageOnTop = TRUE;
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static MSF_BOOL linkExists(int startPos, int endPos);
static int newLineExists(int start, int chars, int *len, int *newIndex);

/******************************************************************************
 * Function implementations
 *****************************************************************************/

#ifdef WIDGET_SLIDING_SMIL_SUPPORT
/*!
 * \brief Set imageOnTop static variable
 *
 * \param image on top was TRUE; at bottom was FALSE.
 *****************************************************************************/
void smaSetImageOnTop(MSF_BOOL onTop)
{
    imageOnTop = onTop;
}
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */

/*!
 * \brief Checks if any links are present within current character range.
 *
 * \param startPos Start index.
 * \param endPos End index.
 * \return TRUE if a link exists within specified range, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL linkExists(int startPos, int endPos)
{
    SmtrParseResult *p;

    p = currInst->parse;
    while (p) 
    {
        if (p->index >= startPos && p->index < endPos)  /* link starts during this line */
        {
            return TRUE;
        }
        if (p->index <= startPos && endPos <= p->index + p->utf8Len) /* this line is part of the link */
        {
            return TRUE;
        }
        if (startPos <= p->index + p->utf8Len && p->index + p->utf8Len <= endPos) /* link ends during this line */
        {
            return TRUE;
        }
        /* Since the list is backwards we can stop here */
        if (p->index < startPos) 
        {
            /* Since the list is backwards we can stop here */
            return FALSE;
        }
        p = p->next;
    }
    return FALSE;
}

/*!
 * \brief Finds the first link in the text.
 *
 * \return The link if it exists, otherwise NULL.
 *****************************************************************************/
static SmtrParseResult *getFirstLink()
{
    SmtrParseResult *p, *head = NULL;
    
    p = currInst->parse;
    while (p)
    {
        head = p;
        p = p->next;
    }
    return head;    
}

/*!
 * \brief Finds the next link in logical order.
 *
 * \return The link if it exists, otherwise NULL.
 *****************************************************************************/
static SmtrParseResult *getNextLink(const SmtrParseResult *link)
{
    if (link) 
    {
        /* prev is returned since we have a stack, not a queue */
        return link->prev;    
    }
    return NULL;
}

/*!
 * \brief Finds the previous link in logical order.
 *
 * \return The link if it exists, otherwise NULL.
 *****************************************************************************/
static SmtrParseResult *getPrevLink(const SmtrParseResult *link)
{
    if (link) 
    {
        /* next is returned since we have a stack, not a queue */
        return link->next;    
    }
    return NULL;
}

/*!
 * \brief Finds next visible link within current character range.
 *
 * \param startPos Start index.
 * \param endPos End index.
 * \return The link if it exists within specified range, otherwise NULL.
 *****************************************************************************/
static SmtrParseResult *getNextVisibleLink(int startPos, int endPos)
{
    SmtrParseResult *p;

    if (startPos == endPos)
    {
        return NULL;
    }
    
    p = getFirstLink();
    while (p) 
    {
        if (p->index >= startPos && p->index < endPos) 
        {
            return p;
        }
        if (p->index <= startPos && endPos <= p->index + p->utf8Len) /* this line is part of the link */
        {
            return p;
        }
        if (startPos < p->index + p->utf8Len && p->index + p->utf8Len <= endPos) /* link ends during this line */
        {
            return p;
        }

        /* We are outside visible area now so we can stop */
        if (p->index >= endPos) 
        {
            /* Since the list is backwards we can stop here */
            return NULL;
        }
        p = getNextLink(p);
    }
    return NULL;
}


/*!
 * \brief Finds the row index previous to startPos.
 *  NOTE! This function should be used with caution since it will do a linear
 *  search from the beginning of text.
 *
 * \return The new index on success, otherwise -1.
 *****************************************************************************/
static int stepBack(int startPos)
{
    MsfSize tmpSize;
    int lastIndex, index, visibleChars, tmp;
#ifdef WAP_SUPPORT
    int nextIndex, strChkLinePos=0;
    char *tPos;
#endif

    index = 0;
    tmpSize.height = currInst->boxSize.height;
    tmpSize.width = currInst->boxSize.width;
    do 
    {
        lastIndex = index;
        /* Check how many characters that can be displayed */
        if (MSF_WIDGET_STRING_GET_VISIBLE(currInst->stringHandle, 0, 
            &tmpSize, index, 1, &visibleChars, &tmp, &tmp) < 0)
        {
            return -1;
        }
#ifdef WAP_SUPPORT
        /* Check for new-line characters */
		if (0 <= (nextIndex = newLineExists(strChkLinePos, visibleChars, &tmp, 
                &strChkLinePos))) 
        {
            visibleChars = nextIndex;
            index += visibleChars + tmp;
            strChkLinePos += tmp;
            continue;
        }
        else
        {
            tPos = &currInst->charBuffer[strChkLinePos];
            tPos = msf_cmmn_utf8_str_incr(tPos, visibleChars);
            strChkLinePos = (tPos - &currInst->charBuffer[strChkLinePos]) + strChkLinePos;
        }
        /* Prevent infinite loops */
        if (!visibleChars) 
        {
            break;
        }
#endif /* WAP_SUPPORT */
        index += visibleChars;
        /* Iterate until all characters are visible */
    } while (index < startPos);
    return lastIndex;
}


/*!
 * \brief Checks a string for newlines within the specified range.
 * \param start
 * \param end
 * \param len (out)
 * \param newIndex (out)
 * \return TRUE if new-line characters exist.
 *****************************************************************************/
static int newLineExists(int start, int chars, int *len, int *newIndex)
{
    char *p, *old;
    int i;
    p = &currInst->charBuffer[start];
    i = 0;
    while (p && *p && (i < chars)) 
    {
        if (p && IS_NEWLINE(*p)) 
        {
            *len = 1;
            p++;
            /*lint -e{774}*/
            if (p && IS_NEWLINE(*p)) 
            {
                *len = 2;
            }
            *newIndex = (p - &currInst->charBuffer[start] - 1) + start;
            return i;
        }
        old = p;
        p = msf_cmmn_utf8_str_incr(p, 1);
        ++i;
        /* Avoid infinite loops */
        p += (old == p ? 1 : 0);        
    }
    *len = 0;
    *newIndex = start;
    return -1;
}

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
static int drawLink(MsfImageHandle imgHandle, MsfStringHandle strHandle, 
    const SmtrParseResult *link, MsfPosition *pos, int index, int chars, 
    MsfSize *size, MSF_BOOL hideCursor)
{
    MsfTextProperty tmpProp, textProp;
    MsfColor tmpColor, tmpBgColor;
    MsfColor color = {0, 0, 255};
    MsfColor bgColor = {255, 255, 255};
    MsfSize tmpSize;

    /* Draw the space before the link, if any */
    if (link->index > index)
    {
        if (MSF_WIDGET_STRING_GET_SUB_SIZE(strHandle, 0, index, 
            link->index - index, 0, &tmpSize) < 0)
        {
            return -1;
        }
        if (MSF_WIDGET_DRAW_STRING(imgHandle, strHandle, pos, size, index, 
            link->index - index, 0, 1) < 0)
        {
            return -1;
        }
        pos->x = (MSF_INT16)(pos->x + tmpSize.width);
        index = link->index;
    }
    
    if (MSF_WIDGET_GET_COLOR(strHandle, &tmpColor, 0) < 0)
    {
        memcpy(&tmpColor, &color, sizeof(MsfColor));
    }
    if (MSF_WIDGET_GET_COLOR(strHandle, &tmpBgColor, 1) < 0)
    {
        memcpy(&tmpBgColor, &bgColor, sizeof(MsfColor));
    }
    if (link->isSelected && !hideCursor) 
    {
#ifdef WAP_SUPPORT
		/* We set link background color directly because we don't use SMIL background color*/
		MsfColor markColor = {150, 150, 150};
		(void)MSF_WIDGET_SET_COLOR(strHandle, &markColor, 1);
#else
        /* Swap foreground and background color */
        (void)MSF_WIDGET_SET_COLOR(strHandle, &tmpColor, 1);
        if (-1 == tmpBgColor.r) 
        {
            tmpBgColor.r = tmpBgColor.g = tmpBgColor.b = 255;
        }
        (void)MSF_WIDGET_SET_COLOR(strHandle, &tmpBgColor, 0);                    
#endif /* WAP_SUPPORT */
    }
#ifndef WAP_SUPPORT
    else
#endif /* ~WAP_SUPPORT */
    {
        /* Check if background is the same color as link color */
        if (!tmpBgColor.r && !tmpBgColor.g && 255 == tmpBgColor.b) 
        {
            (void)MSF_WIDGET_SET_COLOR(strHandle, &bgColor, 0);
        }
        else
        {
            (void)MSF_WIDGET_SET_COLOR(strHandle, &color, 0);
        }
    }
    /* Make link underlined */
    if (MSF_WIDGET_GET_TEXT_PROPERTY(strHandle, &textProp) < 0)
    {
        return -1;
    }
    tmpProp.decoration = textProp.decoration;
    textProp.decoration = MSF_TEXT_DECORATION_UNDERLINE;
    if (MSF_WIDGET_SET_TEXT_PROPERTY(strHandle, &textProp) < 0)
    {
        return -1;
    }
    if (MSF_WIDGET_DRAW_STRING(imgHandle, strHandle, pos, size, index, 
        chars, 0, 0) < 0)
    {
        return -1;
    }
    /* Restore styles */
    (void)MSF_WIDGET_SET_COLOR(strHandle, &tmpColor, 0);
    if (link->isSelected) 
    {
        (void)MSF_WIDGET_SET_COLOR(strHandle, &tmpBgColor, 1);
    }
    textProp.decoration = tmpProp.decoration;
    if (MSF_WIDGET_SET_TEXT_PROPERTY(strHandle, &textProp) < 0)
    {
        return -1;        
    }
    if (MSF_WIDGET_STRING_GET_SUB_SIZE(strHandle, 0, index, 
        chars, 0, &tmpSize) < 0)
    {
        return -1;
    }
    /* Increase index/position counters */
    index += chars;
    pos->x = (MSF_INT16)(pos->x + tmpSize.width);
    return index;
}

#ifdef WIDGET_SLIDING_SMIL_VBAR
static int setTotalGadgetHeight(int index, MsfStringHandle strHandle, int maxHeight, 
    int strPos, char* tPos, MsfSize tmpSize)
{
    int lastIndex, visibleChars, tmp, nextIndex;
	int leftTextHeight =0;
	if (index < currInst->totalLength)
	{
		do 
		{
			lastIndex = index;
			/* oneLineTextHeight = fontHeight + SMTR_BASELINE_SIZE */
			leftTextHeight = (MSF_UINT16)(leftTextHeight + oneLineTextHeight);
			/* Check how many characters that can be displayed */
        
			if (MSF_WIDGET_STRING_GET_VISIBLE(strHandle, 0, &tmpSize, 
				index, 1, &visibleChars, &tmp, &tmp) < 0)
			{
				return FALSE;
			}
			/* Check for new-line characters */
			if (0 <= (nextIndex = newLineExists(strPos, visibleChars, &tmp, 
				&strPos))) 
			{
				visibleChars = nextIndex;
				index += visibleChars + tmp;
				strPos += tmp;
				continue;
			}
			else
			{
				tPos = &currInst->charBuffer[strPos];
				tPos = msf_cmmn_utf8_str_incr(tPos, visibleChars);
				strPos = (tPos - &currInst->charBuffer[strPos]) + strPos;
			}
			/* Prevent infinite loops */
			if (!visibleChars) 
			{
				break;
			}
			/* NOTE! If links are rendered much different than the text we need
			 * to take that extra size into account when calculating the size */

			index += visibleChars;
    		/* Iterate until all characters are visible */
		} while (index < currInst->totalLength);
	}
	return leftTextHeight;
}

  #ifdef __MMI_TOUCH_SCREEN__
void smaGetScrollOffset(void)
{
    HDIa_widgetExtFormGetSlidingSMILTextOffsetByPen(getSlideFormHandle(), &movedTextOffset);
	//HDIa_widgetExtFormSlidingSMILAdjustGadgetFocusByPen();
	if (0 > movedTextOffset)
		movedTextOffset = 0;
	else if (totalTextHeight < movedTextOffset)
	    movedTextOffset = totalTextHeight;	
	if (movedTextOffset > currentTextOffset)
	{
	    smaHandleScrollEvent(MsfKey_Down);
	}
	else if (movedTextOffset < currentTextOffset && (currentTextOffset - movedTextOffset) >= oneLineTextHeight)
	{
	    //for example if currentTextOffset is 60, we only scroll when movedTextOffset is less and equal than 40
	    smaHandleScrollEvent(MsfKey_Up);
	}
}
  #endif /* __MMI_TOUCH_SCREEN__ */
#endif /* WIDGET_SLIDING_SMIL_VBAR */

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
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
static MsfImageHandle textToImage(MsfStringHandle strHandle,
    MsfSize *size, MSF_BOOL redraw, MSF_INT16 maxHeight, MsfStyleHandle style)
{
    MSF_INT16 maxWidth = size->width;
#else
static MsfImageHandle textToImage(MsfStringHandle strHandle,
    MsfSize *size, MSF_INT16 maxWidth, MSF_INT16 maxHeight, MsfStyleHandle style)
{
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */
    int tmp, strPos = 0, oldStrPos = 0;
    int visibleChars;
    int totalChars, toRend = 0;
    int index, lastIndex, nextIndex;
    int gadgetHeight;
    int rowEnd;
    char *tPos;
    SmtrParseResult *link = NULL;
    MsfImageHandle imgHandle;
    MsfSize tmpSize = {0, 0};
    MsfSize rowSize = {0, 0};
    MsfPosition pos = {0, 0};
    int fontHeight;
    MsfFont font;
    MSF_BOOL linkSpan = FALSE;
    MSF_BOOL firstLine = TRUE;
    MSF_BOOL vertResize, horizResize, renderLinks, hideCursor;
    
    if (0 == maxWidth) 
    {
        return 0;
    }
    /* Check flags */
    vertResize = IS_SET(currInst->prop.flags, SMTR_PROP_VERTICAL_RESIZE);
    horizResize = IS_SET(currInst->prop.flags, SMTR_PROP_HORIZONTAL_RESIZE);
    renderLinks = IS_SET(currInst->prop.flags, SMTR_PROP_RENDER_LINKS);
    hideCursor = IS_SET(currInst->prop.flags, SMTR_PROP_HIDE_CURSOR);
#ifndef WAP_SUPPORT
    (void)MSF_WIDGET_SET_COLOR(strHandle, &currInst->prop.bgColor, 1);
    (void)MSF_WIDGET_SET_COLOR(strHandle, &currInst->prop.textColor, 0);
#endif
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
#ifdef WAP_SUPPORT
    if (visibleChars == totalChars && 
        0 > newLineExists(index, index + visibleChars, &tmp, &tmp))
#else
    if (visibleChars == totalChars && 
        !newLineExists(index, index + visibleChars, &tmp, &tmp))
#endif /* WAP_SUPPORT */
    {
        /* The text can be displayed on one line, shrink the width */
        if (MSF_WIDGET_STRING_GET_SUB_SIZE(strHandle, 0, 0, totalChars, 0, 
            &tmpSize) < 0)
        {
            return FALSE;
        }

        if (vertResize) 
        {
            size->height = (MSF_INT16)(fontHeight + SMTR_BASELINE_SIZE);
        }
        else
        {
            size->height = maxHeight;
        }
#ifdef WAP_SUPPORT
        currInst->nextEndIndex = totalChars;
  #ifdef WIDGET_SLIDING_SMIL_VBAR
		totalTextHeight = size->height;
  #endif /* WIDGET_SLIDING_SMIL_VBAR */
#endif /* WAP_SUPPORT */
    }
    else
    {
        /* The text needs multiple line, iterate until all lines fits */
        size->height = (MSF_INT16)(maxHeight ? maxHeight : 0x7FFF);
        do 
        {
            lastIndex = index;
            /* Add the visible height */
            gadgetHeight = (MSF_UINT16)(gadgetHeight + fontHeight + 
                SMTR_BASELINE_SIZE);
            /* Check how many characters that can be displayed */
            
            if (MSF_WIDGET_STRING_GET_VISIBLE(strHandle, 0, &tmpSize, 
                index, 1, &visibleChars, &tmp, &tmp) < 0)
            {
                return FALSE;
            }
            /* Check for new-line characters */
            if (0 <= (nextIndex = newLineExists(strPos, visibleChars, &tmp, 
                &strPos))) 
            {
                visibleChars = nextIndex;
                index += visibleChars + tmp;
                strPos += tmp;
                if (firstLine) 
                {
                    currInst->nextIndex = index;
                    firstLine = FALSE;
                }
                continue;
            }
            else
            {
                tPos = &currInst->charBuffer[strPos];
                tPos = msf_cmmn_utf8_str_incr(tPos, visibleChars);
                strPos = (tPos - &currInst->charBuffer[strPos]) + strPos;
            }
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
            /* NOTE! If links are rendered much different than the text we need
             * to take that extra size into account when calculating the size */

            index += visibleChars;
        	/* Iterate until all characters are visible */
        } while (index < totalChars && (gadgetHeight + fontHeight + 
            SMTR_BASELINE_SIZE) <= size->height);

        currInst->currentEndIndex = lastIndex;
        currInst->nextEndIndex = index;

        if (vertResize && gadgetHeight < maxHeight && index >= totalChars)
        {
            size->height = (MSF_INT16)gadgetHeight;
        }
        else
        {
            size->height = maxHeight;
        }
#ifdef WIDGET_SLIDING_SMIL_VBAR
        if (!redraw)
        {
            oneLineTextHeight = fontHeight + SMTR_BASELINE_SIZE;
    #ifdef __MMI_TOUCH_SCREEN__
            movedTextOffset = 0;
    #endif
            currentTextOffset = 0;

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
#else
		    totalTextHeight = gadgetHeight + 
				setTotalGadgetHeight(index, strHandle, size->height, strPos, tPos, tmpSize);
#endif
		}
#endif /* WIDGET_SLIDING_SMIL_VBAR */

        size->width  = maxWidth;
    }
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    if (!redraw)
    {
        HDIa_widgetExtFormClearSlidingSMIL(getSlideFormHandle());
        HDIa_widgetExtFormSetSlidingSMIL(getSlideFormHandle(), (kal_bool)imageOnTop, 
            (MSF_INT16)((index && index < totalChars)? (maxHeight) : gadgetHeight));
  #ifdef WIDGET_SLIDING_SMIL_VBAR
	    HDIa_widgetExtFormSetSlidingSMILTextHeight(getSlideFormHandle(), totalTextHeight, oneLineTextHeight);
    #ifdef __MMI_TOUCH_SCREEN__
        smaRegisterScrollNotif();
	#endif /* __MMI_TOUCH_SCREEN__ */
  #endif /* WIDGET_SLIDING_SMIL_VBAR */
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */

    /* Create an empty image */
    if (0 == (imgHandle = MSF_WIDGET_IMAGE_CREATE_EMPTY(MSF_MODID_SMTR, size, 
        style)))
    {
        (void)MSF_WIDGET_RELEASE(style);
        return FALSE;
    }
    
    /* Draw the text on the image */
    index = currInst->currentIndex;
    strPos = oldStrPos;
    /*  Find previous index. This can be very expensive since we must search 
     *  from the beginning, but there is no other solution right now */

    if (MsfKey_Down != currInst->currentEvent)
        currInst->prevIndex = stepBack(index);

    do
    {
        /* Check how many characters that can be displayed */
        if (MSF_WIDGET_STRING_GET_VISIBLE(strHandle, imgHandle, size, index, 1, 
            &visibleChars, &tmp, &tmp) < 0)
        {
            (void)MSF_WIDGET_RELEASE(imgHandle);
            return FALSE;
        }
        lastIndex = index;
        tmp = 0;
        /* Check for new-line characters */
        if (0 <= (nextIndex = newLineExists(strPos, visibleChars, &tmp, 
            &strPos))) 
        {
            visibleChars = nextIndex;
            strPos += tmp;
        }
        else
        {
            tPos = &currInst->charBuffer[strPos];
            tPos = msf_cmmn_utf8_str_incr(tPos, visibleChars);
            strPos = (tPos - &currInst->charBuffer[strPos]) + strPos;
        }
        /* Check if there are any links to render on this line */
		if ((renderLinks && linkExists(index, index + visibleChars))
            || linkSpan) 
        {
            if (MSF_WIDGET_STRING_GET_SUB_SIZE(strHandle, imgHandle, index, 
                visibleChars, 0, &rowSize) < 0)
            {
                (void)MSF_WIDGET_RELEASE(imgHandle);
                return FALSE;
            }
            /* Center the text */
            if (size->width < rowSize.width)
            {
                pos.x = 0;
            }
            else
            {
                pos.x = (MSF_INT16)((MSF_UINT16)(size->width - rowSize.width) >> 1);
            }

            rowEnd = index + visibleChars;
            if (linkSpan && link) 
            {
                /* Check if link span multiple rows */
                if (toRend > visibleChars) 
                {
                    /* Draw the link */
                    if ((index = drawLink(imgHandle, strHandle, link, &pos, index, 
                        visibleChars, size, hideCursor)) < 0)
                    {
                        (void)MSF_WIDGET_RELEASE(imgHandle);
                        return FALSE;
                    }
                    linkSpan = TRUE;
                    toRend -= visibleChars; 
                }
                else
                {
                    /* Draw the link */
                    if ((index = drawLink(imgHandle, strHandle, link, &pos, index, 
                        toRend, size, hideCursor)) < 0)
                    {
                        (void)MSF_WIDGET_RELEASE(imgHandle);
                        return FALSE;
                    }
                    toRend = link->utf8Len - (index - link->index);
                    linkSpan = FALSE;
                }
            }
            /* For each link... */
            while (!linkSpan &&
                (NULL != (link = getNextVisibleLink(index, rowEnd))))
            {
                int curRend = 0;
                /* Check if link span multiple rows */
                if (link->index + link->utf8Len > rowEnd) 
                {
                    linkSpan = TRUE;
                    toRend = link->utf8Len - (rowEnd - link->index);
                    curRend = (index > link->index)? (rowEnd - index) : (rowEnd - link->index);
                }
                else
                {
                    linkSpan = FALSE;
                    toRend = 0;
                    curRend = (index > link->index)? (link->utf8Len + link->index - index) : link->utf8Len;
                }
                /* Draw the link */
                if ((index = drawLink(imgHandle, strHandle, link, &pos, index, 
                    curRend, size, hideCursor)) < 0)
                {
                    (void)MSF_WIDGET_RELEASE(imgHandle);
                    return FALSE;
                }
            }
            /* Check if anything left to draw on the row */
            if (!linkSpan && (index < rowEnd)) 
            {
                if (MSF_WIDGET_DRAW_STRING(imgHandle, strHandle, &pos, size, index, 
                    rowEnd - index, 0, 1) < 0)
                {
                    (void)MSF_WIDGET_RELEASE(imgHandle);
                    return FALSE;
                }
                index = rowEnd;                
            }
            /* Go pass any new-line characters */
            index += tmp;
        }
        else {  /* Draw plain string */
            if(visibleChars)
            {
                if (MSF_WIDGET_STRING_GET_SUB_SIZE(strHandle, imgHandle, index, visibleChars, 0, 
                    &tmpSize) < 0)
                {
                    (void)MSF_WIDGET_RELEASE(imgHandle);
                    return FALSE;
                }
                /* Center the text */
                if (size->width < tmpSize.width)
                {
                    pos.x = 0;
                }
                else
                {
                    pos.x = (MSF_INT16)((MSF_UINT16)(size->width - tmpSize.width)>>1);
                }
                
                /* Draw */
                if (MSF_WIDGET_DRAW_STRING(imgHandle, strHandle, &pos, size, index, 
                    visibleChars, 0, 1) < 0)
                {
                    (void)MSF_WIDGET_RELEASE(imgHandle);
                    return FALSE;
                }
                index += visibleChars;
            }
            /* Go pass any new-line characters */
            index += tmp;
        }
        /* Next line */
        pos.y = (MSF_INT16)(pos.y + fontHeight + SMTR_BASELINE_SIZE);
        /* Iterate until all characters are visible */
    } while (lastIndex != index && index <= currInst->currentEndIndex);
        
    if (index == totalChars)
    {
        if (0 == currInst->currentIndex) 
        {
            currInst->fullScreen = TRUE;
        }
        else
        {
            currInst->fullScreen = FALSE;
        }
    }
        return imgHandle;
}

#if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
/*!
 * \brief Calculates new start indices for current screen.
 *
 * \return TRUE if indices has changed, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL setNewIndicesByOffset(MsfStringHandle strHandle, int newOffset)
{
    MsfSize boxSize;
    int charIndex = 0, lastCharIndex = 0, byteIndex=0, nextByteIndex = 0;
    int visibleCharCount, dummy = 0;
    int offset = 0;
    char *tPos;

    if(newOffset == currentTextOffset)
        return FALSE;

    newOffset = (newOffset < 0) ? 0 : newOffset;
    newOffset = (newOffset > totalTextHeight) ? totalTextHeight : newOffset;
	
    boxSize.height = currInst->boxSize.height;
    boxSize.width = currInst->boxSize.width;

    if(MsfKey_Up != currInst->currentEvent && MsfKey_Left != currInst->currentEvent) /* Down */
	{
        offset = oneLineTextHeight;
	}

    while (offset <= newOffset)    /* Proceed to the specified (page start) offset */
    {
        int visibleChars = 0, newlineBytes = 0;
        lastCharIndex = charIndex;
        if (MSF_WIDGET_STRING_GET_VISIBLE(strHandle, 0, &boxSize, charIndex, 1, &visibleChars, &dummy, &dummy) < 0)
        {
            return FALSE;
        }

        if (visibleChars == 0)         /* Prevent infinite loops */
        {
            break;
        }

        if (0 <= (visibleCharCount = newLineExists(byteIndex, visibleChars, &newlineBytes, &nextByteIndex)))         /* Check for new-line characters */
        {
            charIndex += visibleCharCount + newlineBytes;
            byteIndex = nextByteIndex + newlineBytes;
        }
        else
        {
            charIndex += visibleChars;
            tPos = &currInst->charBuffer[byteIndex];
            tPos = msf_cmmn_utf8_str_incr(tPos, visibleChars);
            byteIndex = (tPos - &currInst->charBuffer[byteIndex]) + byteIndex;
        }
	     offset += oneLineTextHeight;
    }

    if (MsfKey_Up == currInst->currentEvent ||MsfKey_Left == currInst->currentEvent) 
    {
        currInst->currentIndex = lastCharIndex;
    }
    else
    {
        currInst->currentIndex = charIndex;
        currInst->prevIndex = lastCharIndex;
    }
    currentTextOffset = newOffset;
    HDIa_widgetExtFormUpdateSlidingSMILTextOffset(getSlideFormHandle(), currentTextOffset);
    return TRUE;
}
#endif
/*!
 * \brief Calculates new start and end indices for current screen.
 *
 * \return TRUE if indices has changed, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL setNewIndices(void)
{
    int index, endIndex;
    if (MsfKey_Up == currInst->currentEvent || 
        MsfKey_Left == currInst->currentEvent) 
    {
        if (0 == currInst->currentIndex) 
        {
            /* Nothing has changed */
            return FALSE;
        }
        /* Start index */
        index = currInst->prevIndex;
        currInst->nextIndex = currInst->currentIndex;
        currInst->currentIndex = index;
        /* End index*/
        endIndex = currInst->prevEndIndex;
        currInst->nextEndIndex = currInst->currentEndIndex;
        currInst->currentEndIndex = endIndex;
#ifdef WIDGET_SLIDING_SMIL_VBAR
        currentTextOffset = currentTextOffset - oneLineTextHeight;
        if (currentTextOffset < oneLineTextHeight)
        {
   	        currentTextOffset = 0;
        }
		    HDIa_widgetExtFormUpdateSlidingSMILTextOffset(getSlideFormHandle(), currentTextOffset);
#endif /* WIDGET_SLIDING_SMIL_VBAR */
    }
    else 
    {
        if (currInst->nextEndIndex == currInst->totalLength) 
        {
            /* Nothing has changed */
            return FALSE;
        }
        /* Start index */
        index = currInst->nextIndex;
        currInst->prevIndex = currInst->currentIndex;
        currInst->currentIndex = index;
        /* End index*/
        endIndex = currInst->nextEndIndex;
        currInst->prevEndIndex = currInst->currentEndIndex;
        currInst->currentEndIndex = endIndex;
#ifdef WIDGET_SLIDING_SMIL_VBAR
        if (currentTextOffset == 0)
        {
	    currentTextOffset += (currInst->boxSize.height % oneLineTextHeight);			
        }
        currentTextOffset = currentTextOffset + oneLineTextHeight;

	HDIa_widgetExtFormUpdateSlidingSMILTextOffset(getSlideFormHandle(), currentTextOffset);
#endif /* WIDGET_SLIDING_SMIL_VBAR */
    }
    return TRUE;
}

/*!
 * \brief Finds the nearest link from current.
 *
 * \param dirDown TRUE if search direction is down.
 * \return TRUE if a new link is selected, otherwise FALSE and current link
 *  is unchanged.
 *****************************************************************************/
static MSF_BOOL findNearestLink(MSF_BOOL dirDown)
{
    SmtrParseResult *tmp;
    if (dirDown) 
    {
        if (NULL != (tmp = getNextLink(currInst->selectedLink)))
        {
            currInst->selectedLink->isSelected = FALSE;
            currInst->selectedLink = tmp;
            currInst->selectedLink->isSelected = TRUE;
            return TRUE;
        }
        return FALSE;        
    }
    else
    {
        if (NULL != (tmp = getPrevLink(currInst->selectedLink)))
        {
            currInst->selectedLink->isSelected = FALSE;
            currInst->selectedLink = tmp;
            currInst->selectedLink->isSelected = TRUE;
            return TRUE;
        }
    }
    return FALSE;
}

/*!
 * \brief 
 *
 * \param item Data for the new instance.
 * \return The new instance or NULL if no new instance could be created.
 *****************************************************************************/
MSF_BOOL smtrRender(SmtrInstance *inst)
{
    MsfSize *size = NULL;
    SmtrParseResult *tmp = NULL;
    MsfImageHandle imgHandle = 0;
    MSF_BOOL linkChanged = FALSE;
    MSF_BOOL indexChanged = FALSE;
    MSF_BOOL hideCursor = FALSE;
    MsfStyleHandle style = 0;
	
    currInst = inst;
    size = &inst->actualSize;
    size->width = inst->boxSize.width;
    size->height = 0;
    hideCursor = IS_SET(inst->prop.flags, SMTR_PROP_HIDE_CURSOR);

    if (0 == (style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_SMTR, &inst->prop.textColor, 
        &inst->prop.bgColor, NULL, NULL, NULL, NULL, NULL)))
    {
        return FALSE;
    }
    
    /* Check if this is a redraw */
    if (currInst->redraw) 
    {
#if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
        if (!hideCursor && movedTextOffset == currentTextOffset) /* change link highlight by keypad */
#else
        if (!hideCursor)
#endif
        {
            /* Take actions according to current event */
            if (MsfKey_Up == inst->currentEvent || 
                MsfKey_Left == inst->currentEvent) 
            {
                /*  Key up...Find prev selected and check if the link will be
                 *  visible. */
                tmp = getPrevLink(currInst->selectedLink);
#ifdef WAP_SUPPORT
	                if (tmp && tmp->index >= currInst->currentIndex) 
#else
                if (tmp && tmp->index >= currInst->prevIndex) 
#endif /* WAP_SUPPORT */
                {
                    linkChanged = findNearestLink(FALSE);
                }
            }
            else
            {
                /* Key down...Find next selected and check if the link will be
                 *  visible. */
                tmp = getNextLink(currInst->selectedLink);
                if (tmp && tmp->index < currInst->nextEndIndex) 
                {                
                    linkChanged = findNearestLink(TRUE);
                }
            }
        }
        /* We only scroll text if we have not already scrolled cursor */
        if (!linkChanged && !inst->fullScreen)
        {
#if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
            if(movedTextOffset != currentTextOffset)  /* scroll by touch panel */
            {
                indexChanged = setNewIndicesByOffset(inst->stringHandle, movedTextOffset);  /* Find next index*/
            }
            else  /* scroll by keypad */
            {
                indexChanged = setNewIndices();  /* Find next index*/
                movedTextOffset = currentTextOffset;
            }
#else
            indexChanged = setNewIndices();  /* Find next index*/
#endif
        }
        /* We only have to redraw if something has changed */
        if (indexChanged || linkChanged) 
        {
            /* create image */
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
            if (0 == (imgHandle = textToImage(inst->stringHandle,
                size, currInst->redraw, inst->boxSize.height, style)))
#else
            if (0 == (imgHandle = textToImage(inst->stringHandle,
                size, size->width, inst->boxSize.height, style)))
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */
            {
                (void)MSF_WIDGET_RELEASE(style);
                return FALSE;
            }
            /* Set size of new image in gadget to avoid stretching */
            if (MSF_WIDGET_SET_SIZE(inst->gadgetHandle, size) < 0)
            {
                (void)MSF_WIDGET_RELEASE(style);
                (void)MSF_WIDGET_RELEASE(imgHandle);                
                return FALSE;
            }
            /* Replace image in gadget */
            if (MSF_WIDGET_IMAGE_GADGET_SET(inst->gadgetHandle, imgHandle, 
                MsfImageZoomAutofit) < 0)
            {
                (void)MSF_WIDGET_RELEASE(style);
                (void)MSF_WIDGET_RELEASE(imgHandle);                
                return FALSE;
            }
            (void)MSF_WIDGET_RELEASE(imgHandle);
        }
        if (!indexChanged && !linkChanged) 
        {
            /* Nothing has happened, we can loose focus */
            currInst->lostFocus = TRUE;
        }
        else
        {
            currInst->lostFocus = FALSE;
        }
    }
    else
    {
        currInst->selectedLink = getFirstLink();
        if (currInst->selectedLink) 
        {
            currInst->selectedLink->isSelected = TRUE;
        }
        inst->currentIndex = inst->prevIndex = inst->nextIndex = 0;
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
        if (0 == (imgHandle = textToImage(inst->stringHandle,
            size, currInst->redraw, inst->boxSize.height, style)))
#else
        if (0 == (imgHandle = textToImage(inst->stringHandle,
            size, size->width, inst->boxSize.height, style)))
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */
        {
            (void)MSF_WIDGET_RELEASE(style);
            return FALSE;
        }

        if (0 == (inst->gadgetHandle = 
            MSF_WIDGET_IMAGE_GADGET_CREATE(MSF_MODID_SMTR, imgHandle, size, 
            MsfImageZoomAutofit, 
            MSF_GADGET_PROPERTY_FOCUS | MSF_GADGET_PROPERTY_NOTIFY, style)))
        {
            (void)MSF_WIDGET_RELEASE(style);            
            (void)MSF_WIDGET_RELEASE(imgHandle);
            return FALSE;
        }
        (void)MSF_WIDGET_RELEASE(imgHandle);
#ifdef WIDGET_SLIDING_SMIL_VBAR
		HDIa_widgetExtFormUpdateSlidingSMILTextOffset(getSlideFormHandle(), 0);
#endif /* WIDGET_SLIDING_SMIL_VBAR */
    }
    (void)MSF_WIDGET_RELEASE(style);    
    return TRUE;
}

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
void SetSMILTotalTextHeightValue(int totalHeight)
{
    if (totalHeight < 0)
    {
        totalTextHeight = oneLineTextHeight;
        return;
    }
    totalTextHeight = totalHeight;
}

#endif
