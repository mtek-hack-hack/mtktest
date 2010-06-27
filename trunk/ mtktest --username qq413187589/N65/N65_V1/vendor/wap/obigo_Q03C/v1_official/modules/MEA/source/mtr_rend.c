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

/*! \file mtr_rend.c
 *  This file contains the control logic for rendering/viewing a text.
 *
 *  IMPORTANT: The complexity of this file is quite big since there are
 *  different indices that might be hard to follow. For instance, there is
 *  handling for both UTF8-position and char buffer position in the code
 *  and it might be confusing. There is no way around this, sorry.
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_cmmn.h"

/* MTR */
#include "mtr.h"
#include "mtr_cmn.h"
#include "mtr_rend.h"

#if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
#include "Widget_extension.h"
#endif

#if defined(WIDGET_SLIDING_SMIL_VBAR)
#include "Mea_cfg.h"
#endif

/******************************************************************************
 * Constants
 *****************************************************************************/

#define IS_NEWLINE(c) ((c)==0x0A||(c)==0x0D)

#define MTR_BASELINE_SIZE        (1)

#define QUANTUM_IN_TICKS   (KAL_TICKS_1_SEC /4)

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/******************************************************************************
 * Static variables
 *****************************************************************************/
static MtrInstance *currInst;

#ifdef WIDGET_SLIDING_SMIL_VBAR

/* Scroll bar position info*/
static int totalTextHeight;
static int oneLineTextHeight;
static int currentTextOffset;
#ifdef __MMI_TOUCH_SCREEN__
static int movedTextOffset;
#endif /* __MMI_TOUCH_SCREEN__ */
  
/* Scroll bar handle*/
static MsfGadgetHandle mtrVScrollBar = 0;

static MsfGadgetHandle mtrCreateVScrollBar(int width, int height);
static void mtrSetVScrollBarValues(int value, int maxValue);
extern MsfWindowHandle meaUiMobGetForm(void);
extern void wap_task_sleep(int milliseconds);

#ifdef __MMI_TOUCH_SCREEN__
static MSF_BOOL setNewIndicesByOffset(MsfStringHandle strHandle, int newOffset);
extern void meaHandleScrollEvent(MsfNotificationType event);
#endif /* __MMI_TOUCH_SCREEN__*/

#endif /* WIDGET_SLIDING_SMIL_VBAR */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static MSF_BOOL linkExists(int startPos, int endPos);
#ifdef WAP_SUPPORT
static int newLineExists(int start, int chars, int *len, int *newIndex);
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief Checks if any links are present within current character range.
 *
 * \param startPos Start index.
 * \param endPos End index.
 * \return TRUE if a link exists within specified range, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL linkExists(int startPos, int endPos)
{
    MtrParseResult *p;

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
static MtrParseResult *getFirstLink()
{
    MtrParseResult *p, *head = NULL;
    
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
static MtrParseResult *getNextLink(const MtrParseResult *link)
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
static MtrParseResult *getPrevLink(const MtrParseResult *link)
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
static MtrParseResult *getNextVisibleLink(int startPos, int endPos)
{
    MtrParseResult *p;
    
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
	int nextIndex, strChkLinePos=0, lastStrChkLinePos = 0;
    char *tPos;
#endif /* WAP_SUPPORT */
    index = 0;
    tmpSize.height = currInst->boxSize.height;
    tmpSize.width = currInst->boxSize.width;

    while((nextIndex = newLineExists(strChkLinePos, startPos, &tmp, &strChkLinePos)) >= 0)  /* Improve : we start search from the last newline */
    {
        lastIndex = index;
        index += nextIndex + tmp;
        strChkLinePos += tmp;
        if(index >= startPos)
        {
            index = lastIndex;
            strChkLinePos = lastStrChkLinePos;
            break;
        }
        lastStrChkLinePos = strChkLinePos;
    }

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
    const MtrParseResult *link, MsfPosition *pos, int index, int chars, 
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
            link->index - index, 0, 0) < 0)
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
        MsfColor markColor = {150, 150, 150};
        (void)MSF_WIDGET_SET_COLOR(strHandle, &markColor, 1);
    }
    
    if (!tmpBgColor.r && !tmpBgColor.g && 255 == tmpBgColor.b) 
    {
        (void)MSF_WIDGET_SET_COLOR(strHandle, &bgColor, 0);
    }
    else
    {
        (void)MSF_WIDGET_SET_COLOR(strHandle, &color, 0);
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
    kal_uint32 last_ticks, ticks;

    kal_get_time(&last_ticks);

    if (index < currInst->totalLength)
	{
		do
		{
            kal_get_time(&ticks);
            if (ticks > last_ticks)
            {
                if (ticks - last_ticks > QUANTUM_IN_TICKS)
                {
                    wap_task_sleep(10);
                    kal_get_time(&last_ticks);
                }
            }
            else
            {
                last_ticks = ticks;
            }

			lastIndex = index;
			/* oneLineTextHeight = fontHeight + SMTR_BASELINE_SIZE */
			leftTextHeight = (leftTextHeight + oneLineTextHeight);
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
#endif /* WIDGET_SLIDING_SMIL_VBAR*/

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
#ifdef WIDGET_SLIDING_SMIL_VBAR
static MsfImageHandle textToImage(MsfStringHandle strHandle, MsfSize *size, 
                                  MSF_INT16 maxWidth, MSF_INT16 maxHeight, MSF_BOOL redraw)
#else /* WIDGET_SLIDING_SMIL_VBAR*/
static MsfImageHandle textToImage(MsfStringHandle strHandle, MsfSize *size, 
                                  MSF_INT16 maxWidth, MSF_INT16 maxHeight)
#endif /* WIDGET_SLIDING_SMIL_VBAR*/
{
    int tmp, strPos = 0, oldStrPos = 0;
    int visibleChars;
    int toRend = 0;
    int index, lastIndex, nextIndex;
    int rowEnd;
    char *tPos;
    MtrParseResult *link = NULL;
    MsfImageHandle imgHandle;
    MsfSize tmpSize = {0, 0};
    MsfSize rowSize = {0, 0};
    MsfPosition pos = {0, 0};
    int fontHeight;
    MsfFont font;
    MSF_BOOL linkSpan = FALSE;
    MSF_BOOL firstLine = TRUE;
    MSF_BOOL vertResize, horizResize, renderLinks, hideCursor;
    MsfStyleHandle style;

    if (0 == maxWidth || 0 == maxHeight)
    {
        return 0;
    }

    size->width = maxWidth;
    size->height = maxHeight;
    
    /* Check flags */
    vertResize = IS_SET(currInst->prop.flags, MTR_PROP_VERTICAL_RESIZE);
    horizResize = IS_SET(currInst->prop.flags, MTR_PROP_HORIZONTAL_RESIZE);
    renderLinks = IS_SET(currInst->prop.flags, MTR_PROP_RENDER_LINKS);
    hideCursor = IS_SET(currInst->prop.flags, MTR_PROP_HIDE_CURSOR);

    (void)MSF_WIDGET_SET_COLOR(strHandle, &currInst->prop.bgColor, 1);
    (void)MSF_WIDGET_SET_COLOR(strHandle, &currInst->prop.textColor, 0);
    
    currInst->totalLength = MSF_WIDGET_STRING_GET_LENGTH(strHandle, 0, MsfUtf8);  /* Get the total number of characters. */

    if (MSF_WIDGET_GET_FONT(strHandle, &font) < 0)  /* Get the font to determine the height */
    {
        return FALSE;
    }

    if (MSF_WIDGET_FONT_GET_VALUES(&font, &tmp, &fontHeight, &tmp) < 0)  /* Get the heigh of the text in order to calculate the height of the gadget later on */
    {
        return FALSE;
    }

    style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_MTR, &currInst->prop.textColor, &currInst->prop.bgColor, NULL, NULL, NULL, NULL, NULL);

    /* Create an empty image */
    if (0 == (imgHandle = MSF_WIDGET_IMAGE_CREATE_EMPTY(MSF_MODID_MTR, size, style)))
    {
        (void)MSF_WIDGET_RELEASE(style);
        return FALSE;
    }
    (void)MSF_WIDGET_RELEASE(style);
    
    /* Check if the text can be displayed on one line */
    index = currInst->currentIndex;
    tPos = &currInst->charBuffer[0];
    tPos = msf_cmmn_utf8_str_incr(tPos, index);
    oldStrPos = strPos = tPos - &currInst->charBuffer[0];

    /*  Find previous index. This can be very expensive since we must search from the beginning, but there is no other solution right now */
    if (MsfKey_Down != currInst->currentEvent)
    {
        currInst->prevIndex = stepBack(index);
    }

    do
    {
        lastIndex = index;
        tmp = 0;

        if (MSF_WIDGET_STRING_GET_VISIBLE(strHandle, 0, size, index, 1, &visibleChars, &tmp, &tmp) < 0)  /* Check how many characters that can be displayed */
        {
            (void)MSF_WIDGET_RELEASE(imgHandle);
            return FALSE;
        }

        if (0 <= (nextIndex = newLineExists(strPos, visibleChars, &tmp, &strPos)))  /* Check for new-line characters */
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

        
        if (!visibleChars)
        {
            index += tmp;  /* Go pass any newline characters */
        }
        else if ((renderLinks && linkExists(index, index + visibleChars)) || linkSpan)  /* Render this line with link */
        {
            rowEnd = index + visibleChars;

            if (MSF_WIDGET_STRING_GET_SUB_SIZE(strHandle, 0, index, visibleChars, 0, &rowSize) < 0)
            {
                (void)MSF_WIDGET_RELEASE(imgHandle);
                return FALSE;
            }

            if (currInst->prop.alignment == MsfRight)
            {
                pos.x = (MSF_UINT16)(size->width - rowSize.width);
            }
            else if (currInst->prop.alignment == MsfCenter)
            {
                if (size->width < rowSize.width)
                {
                    pos.x = 0;
                }
                else
                {
                    pos.x = (MSF_INT16)((MSF_UINT16)(size->width - rowSize.width) >> 1);  /* Center the text */
                }
            }
            else /* It may be modified in drawLink*/
            {
                pos.x = 0;
            }
            
            if (linkSpan && link) 
            {
                if (toRend > visibleChars)  /* Check if link span multiple rows */
                {
                    if ((index = drawLink(imgHandle, strHandle, link, &pos, index, visibleChars, size, hideCursor)) < 0)  /* Draw the link */
                    {
                        (void)MSF_WIDGET_RELEASE(imgHandle);
                        return FALSE;
                    }
                    linkSpan = TRUE;
                    toRend -= visibleChars; 
                }
                else
                {
                    if ((index = drawLink(imgHandle, strHandle, link, &pos, index, toRend, size, hideCursor)) < 0)  /* Draw the link */
                    {
                        (void)MSF_WIDGET_RELEASE(imgHandle);
                        return FALSE;
                    }
                    toRend = link->utf8Len - (index - link->index);
                    linkSpan = FALSE;
                }
            }

            while (!linkSpan && (NULL != (link = getNextVisibleLink(index, rowEnd))))  /* For each link... */
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
                if ((index = drawLink(imgHandle, strHandle, link, &pos, index, curRend, size, hideCursor)) < 0)
                {
                    (void)MSF_WIDGET_RELEASE(imgHandle);
                    return FALSE;
                }
            }
            /* Check if anything left to draw on the row */
            if (!linkSpan && (index < rowEnd)) 
            {
                if (MSF_WIDGET_DRAW_STRING(imgHandle, strHandle, &pos, size, index, rowEnd - index, 0, 0) < 0)
                {
                    (void)MSF_WIDGET_RELEASE(imgHandle);
                    return FALSE;
                }
                index = rowEnd;                
            }
            /* Go pass any new-line characters */
            index += tmp;
        }
        else {
            if (MSF_WIDGET_STRING_GET_SUB_SIZE(strHandle, 0, index, visibleChars, 0, &tmpSize) < 0)
            {
                (void)MSF_WIDGET_RELEASE(imgHandle);
                return FALSE;
            }
            if (currInst->prop.alignment == MsfRight)
                pos.x = (MSF_UINT16)(size->width - rowSize.width);
            else if (currInst->prop.alignment == MsfCenter)  /* Center the text */
            {
                if (size->width < tmpSize.width)
                {
                    pos.x = 0;
                }
                else
                {
                    pos.x = (MSF_INT16)((MSF_UINT16)(size->width - tmpSize.width)>>1);
                }
            }
            else
                pos.x = 0;
            
            /* Draw */
            if (MSF_WIDGET_DRAW_STRING(imgHandle, strHandle, &pos, size, index, visibleChars, 0, 0) < 0)
            {
                (void)MSF_WIDGET_RELEASE(imgHandle);
                return FALSE;
            }
            index += visibleChars;
            /* Go pass any new-line characters */
            index += tmp;
        }
        pos.y = (MSF_INT16)(pos.y + fontHeight + MTR_BASELINE_SIZE);  /* Next line */

        if (firstLine) 
        {
            currInst->nextIndex = index;
            firstLine = FALSE;
        }
        currInst->currentEndIndex = lastIndex;
        currInst->nextEndIndex = index;
    } while (index < currInst->totalLength && (pos.y + fontHeight + MTR_BASELINE_SIZE) <= size->height);  /* Iterate until all characters are visible */

#ifdef WIDGET_SLIDING_SMIL_VBAR
        if (!redraw)
        {
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MTR_REND_91D40419FBA99529ABBD5C4293863A45, "MEA MMV Scroll: in textToImage and not redraw, calc total text height\n"));
            
            oneLineTextHeight = fontHeight + MTR_BASELINE_SIZE;

     #ifdef __MMI_TOUCH_SCREEN__
            movedTextOffset = 0;
    #endif
            currentTextOffset = 0;

#if defined(MEA_GET_MIXED_TEXT_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
#else
            totalTextHeight = pos.y + 
                setTotalGadgetHeight(index, strHandle, size->height, strPos, tPos, *size);
#endif

            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MTR_REND_0F6F43615495BBEA5F148702F3CEF350, "MEA MMV Scroll: totalTextHeight = %d\n", totalTextHeight));
            
        }
#endif /* WIDGET_SLIDING_SMIL_VBAR */

    if (index == currInst->totalLength)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef WAP_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* WAPS_SUPPORT */
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
/* under construction !*/
#ifdef WAP_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* WAPS_SUPPORT */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
        /* Set scroll bar position */
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MTR_REND_1C4E87DD01B38B8843C0469A0ECF3634, "MEA MMV Scroll: in setNewIndices, will set scroll bar pos\n"));

        currentTextOffset = currentTextOffset - oneLineTextHeight;
        if (currentTextOffset < oneLineTextHeight)
        {
   	        currentTextOffset = 0;
        }
        mtrSetVScrollBarValues(currentTextOffset, totalTextHeight);
        
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
        /* Set scroll bar position*/
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MTR_REND_1C4E87DD01B38B8843C0469A0ECF3634, "MEA MMV Scroll: in setNewIndices, will set scroll bar pos\n"));

        if (currentTextOffset == 0)
        {
            currentTextOffset += (currInst->boxSize.height % oneLineTextHeight);			
        }
        currentTextOffset = currentTextOffset + oneLineTextHeight;
        mtrSetVScrollBarValues(currentTextOffset, totalTextHeight);
        
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
    MtrParseResult *tmp;
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

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MTR_REND_ED86FD9D329A0EBD7828AC0EE8CF14C9, "MEA MMV Scroll: setNewIndicesByOffset\n"));
    
    if(newOffset == currentTextOffset)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MTR_REND_D2D3CCC0E3621727353281983231FD2E, "MEA MMV Scroll: newOffset == currentTextOffset\n"));
        return FALSE;
    }
    
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
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MTR_REND_578A739CA9BDD44A3C3468F5705E149F, "MEA MMV Scroll: MSF_WIDGET_STRING_GET_VISIBLE failed\n"));
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
#endif
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MTR_REND_7017A26CDF88AF9E9C3D019FDFBB255F, "MEA MMV Scroll: charIndex = %d\n", charIndex));
    
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
    mtrSetVScrollBarValues(currentTextOffset, totalTextHeight);
    
    return TRUE;
}
#endif

/*!
 * \brief 
 *
 * \param item Data for the new instance.
 * \return The new instance or NULL if no new instance could be created.
 *****************************************************************************/
MSF_BOOL mtrRender(MtrInstance *inst)
{
    MsfSize *size;
    MtrParseResult *tmp;
    MsfImageHandle imgHandle;
    MSF_BOOL linkChanged = FALSE;
    MSF_BOOL indexChanged = FALSE;
    MSF_BOOL hideCursor;
    currInst = inst;
    size = &inst->actualSize;
    size->width = inst->boxSize.width;
    size->height = 0;
    hideCursor = IS_SET(inst->prop.flags, MTR_PROP_HIDE_CURSOR);
    
    /* Check if this is a redraw */
    if (currInst->redraw) 
    {
#if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
        if ((currInst->boxSize.height < totalTextHeight) && 
            ((movedTextOffset + currInst->boxSize.height) >= totalTextHeight))
        {
            int over = 0;
            movedTextOffset = totalTextHeight - currInst->boxSize.height;
            if ((over = movedTextOffset % oneLineTextHeight) > 0)
            {
                movedTextOffset = (movedTextOffset - over)  + oneLineTextHeight;
            }
        }

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

                /* if (tmp && tmp->index >= currInst->prevIndex) */
                /*Old code need  press two times to keyup to prev link in prev page*/
                if (tmp && tmp->index >= currInst->currentIndex) 
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
            /* Find next index */
            indexChanged = setNewIndices();            
#endif
        }
        /* We only have to redraw if something has changed */
        if (indexChanged || linkChanged) 
        {
            /* create image */
#ifdef WIDGET_SLIDING_SMIL_VBAR
            if (0 == (imgHandle = textToImage(inst->stringHandle,
                size, size->width, inst->boxSize.height, TRUE)))
#else
            if (0 == (imgHandle = textToImage(inst->stringHandle,
                size, size->width, inst->boxSize.height)))
#endif /* WIDGET_SLIDING_SMIL_VBAR*/
            {
                return FALSE;
            }
            /* Set size of new image in gadget to avoid stretching */
            if (MSF_WIDGET_SET_SIZE(inst->gadgetHandle, size) < 0)
            {
                (void)MSF_WIDGET_RELEASE(imgHandle);                
                return FALSE;
            }
            /* Replace image in gadget */
            if (MSF_WIDGET_IMAGE_GADGET_SET(inst->gadgetHandle, imgHandle, 
                MsfImageZoomAutofit) < 0)
            {
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

#ifdef WIDGET_SLIDING_SMIL_VBAR
        if (0 == (imgHandle = textToImage(inst->stringHandle,
            size, size->width, inst->boxSize.height, FALSE)))
#else
        if (0 == (imgHandle = textToImage(inst->stringHandle,
            size, size->width, inst->boxSize.height)))
#endif /* WIDGET_SLIDING_SMIL_VBAR*/
        {
            return FALSE;
        }

        if (0 == (inst->gadgetHandle = 
            MSF_WIDGET_IMAGE_GADGET_CREATE(MSF_MODID_MTR, imgHandle, size, 
            MsfImageZoomAutofit, 
            MSF_GADGET_PROPERTY_FOCUS | MSF_GADGET_PROPERTY_NOTIFY, 0)))
        {
            (void)MSF_WIDGET_RELEASE(imgHandle);
            return FALSE;
        }
        (void)MSF_WIDGET_RELEASE(imgHandle);

#ifdef WIDGET_SLIDING_SMIL_VBAR
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MTR_REND_ACBDC85958374473FBF26AE3593357D9, "MEA MMV Scroll: in mtrRender, will create scroll bar\n"));

        mtrDeleteVScrollBar();
        mtrCreateVScrollBar(MSF_CFG_SCROLLBAR_WIDTH, currInst->prop.size.height);
        mtrSetVScrollBarValues(currentTextOffset, totalTextHeight);
  #ifdef __MMI_TOUCH_SCREEN__
        HDIa_widgetExtBarSetMinPenOffsetValue(mtrGetVScrollBar(), oneLineTextHeight);
  #endif
        
#endif /* WIDGET_SLIDING_SMIL_VBAR */
    }
    return TRUE;
}

#ifdef WIDGET_SLIDING_SMIL_VBAR
MsfGadgetHandle mtrGetVScrollBar(void)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MTR_REND_42372817DA26A166CF06BF2674FB29EB, "MEA MMV Scroll: mtrGetVScrollBar, mtrVScrollBar = %x\n", mtrVScrollBar));
    return mtrVScrollBar;
}

void mtrDeleteVScrollBar(void)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MTR_REND_1D5973A8C4F62631EAC50FF55A81673E, "MEA MMV Scroll: mtrDeleteVScrollBar, mtrVScrollBar = %x\n", mtrVScrollBar));
    if (mtrVScrollBar > 0)
    {
        MSF_WIDGET_RELEASE(mtrVScrollBar);
        mtrVScrollBar = 0;
    }
    /*HDIa_widgetExtBarSetMinPenOffsetValue(mtrVScrollBar, -1);*/
}

#ifdef __MMI_TOUCH_SCREEN__
void meaGetScrollOffset(void)
{
    int over;

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MTR_REND_B9EFA35A4C74C0970DF28DE53BB0F4B8, "MEA MMV Scroll: meaGetScrollOffset\n"));
    
    HDIa_widgetExtFormGetMOBTextOffsetByPen(meaUiMobGetForm(), &movedTextOffset);

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MTR_REND_EC9199EE42E3609C3DB728867268D88A, "MEA MMV Scroll: movedTextOffset = %d, totalTextHeight = %d, currentTextOffset = %d, oneLineTextHeight = %d\n",
            movedTextOffset, totalTextHeight, currentTextOffset, oneLineTextHeight));

    ASSERT(oneLineTextHeight);

/*
    movedTextOffset = ((movedTextOffset + (oneLineTextHeight - 1)) / oneLineTextHeight) * 
        oneLineTextHeight;
*/
/*    if ((over = movedTextOffset % oneLineTextHeight) > 0)
    {
        movedTextOffset = (movedTextOffset - over)  + oneLineTextHeight;
    }
    */
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MTR_REND_B096EB23E8E3B9E63ECABD0A561CA956, "MEA MMV Scroll: After adjust, movedTextOffset = %d,\n", movedTextOffset));
    
	if (0 > movedTextOffset)
		movedTextOffset = 0;
	else if (totalTextHeight < movedTextOffset)
	    movedTextOffset = totalTextHeight;	

	if (movedTextOffset > currentTextOffset)
	{
        if ((movedTextOffset + currInst->boxSize.height) >= totalTextHeight)
        {
            movedTextOffset = totalTextHeight - currInst->boxSize.height;
            if ((over = movedTextOffset % oneLineTextHeight) > 0)
            {
                movedTextOffset = (movedTextOffset - over)  + oneLineTextHeight;
            }
        }
	    meaHandleScrollEvent(MsfKey_Down);
	}
	else if (movedTextOffset < currentTextOffset && (currentTextOffset - movedTextOffset) >= oneLineTextHeight)
	{
        if ((currentTextOffset + currInst->boxSize.height) >= totalTextHeight)
        {
            if ((over = movedTextOffset % oneLineTextHeight) > 0)
            {
                movedTextOffset = (movedTextOffset - over)  + oneLineTextHeight;
            }
        }
	    //for example if currentTextOffset is 60, we only scroll when movedTextOffset is less and equal than 40
	    meaHandleScrollEvent(MsfKey_Up);
	}
}
#endif /* __MMI_TOUCH_SCREEN__*/

static MsfGadgetHandle mtrCreateVScrollBar(int width, int height)
{
    MsfSize size;

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MTR_REND_4FBD36699FCCE7A6B48FC73C5D0D4FD9, "MEA MMV Scroll: mtrCreateVScrollBar\n"));
    
    size.width = width;
    size.height = height;
    
    mtrVScrollBar = HDIa_widgetBarCreate(MSF_MODID_MEA, MsfVerticalScrollBar, 1, 1, &size, 0, 0);

    return mtrVScrollBar;
}

static void mtrSetVScrollBarValues(int value, int maxValue)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MTR_REND_4B912A05382EAF48A787973115B6E61C, "MEA MMV Scroll: mtrSetVScrollBarValues, mtrVScrollBar = %x,value = %d, maxValue = %d\n", 
        mtrVScrollBar, value, maxValue));
    
    if (mtrVScrollBar == 0)
        return;

    if (value > maxValue)
        value = maxValue;
    
    HDIa_widgetBarSetValues(mtrVScrollBar, value, maxValue);
}

void SetTotalTextHeightValue(int totalHeight)
{
    if (totalHeight < 0)
    {
        totalTextHeight = oneLineTextHeight;
        return;
    }
    totalTextHeight = totalHeight;
}

MtrParseResult *mtrGetSelectedLink()
{
    if (currInst != NULL)
    {
        return currInst->selectedLink;
    }
    return NULL;
}

void mtrClearCurrInst()
{
    currInst = NULL;
}

#endif /* WIDGET_SLIDING_SMIL_VBAR*/
