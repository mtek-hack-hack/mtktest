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

/*!\file mauipm.c
 * \brief Progress meter.
 */

/* MSF */
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_def.h"
#ifdef WAP_SUPPORT
#include "msf_mem.h"
#endif /* WAP_SUPPORT */

/* MMS */
#ifdef WAP_SUPPORT
#include "mms_def.h"
#endif

/* MEA */
#include "mea_rc.h"
#include "masig.h"
#include "maintsig.h"
#include "mauisig.h"
#include "maintsig.h"
#include "mea_def.h"
#include "mauicmn.h"
#include "mauipm.h"
#ifdef WAP_SUPPORT
#include "mamem.h"
#include "matypes.h"

#include "widget_extension.h"

extern void clearProgressPercent(void);
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Constants
 *****************************************************************************/
#define MEA_PM_BORDER_WIDTH             8
#define MEA_PM_HEIGHT                   30
#define MEA_PM_TEXT_HEIGHT              50
/* The time between each tick for the progress meter */
#define MEA_PM_TICK_TIME                20
/* The number of steps for the progress meter gadget*/
#define MEA_PM_TICKS                    25

/******************************************************************************
 * Data-types
 *****************************************************************************/
/*! \struct MeaPmView
 *  Data structure for the progress meter */
typedef struct
{
    /* The form */
    MsfWindowHandle formHandle;
    /* Gadget handles */
    MsfGadgetHandle progressGadget;
    MsfGadgetHandle textGadget;
}MeaPmView;

/******************************************************************************
 * Global variables
 *****************************************************************************/
static MeaPmView         meaPmView;

#ifdef WAP_SUPPORT
static int cancelFsm, cancelSignal;
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief Create the initial data-structures needed for MEA to run.
 *
 *****************************************************************************/
void meaInitPm()
{
    memset(&meaPmView, 0, sizeof(MeaPmView));
}

/*!
 * \brief Free the resources allocated in meaInitGui.
 *
 *****************************************************************************/
void meaTerminatePm()
{
    meaPmViewRemove();
}

#ifdef WAP_SUPPORT
//Remove progressing View
static void meaPmHandleCancel(ctk_screen_handle scrId)
{
	CTK_UNUSED(scrId);
	MEA_SIGNAL_SENDTO((MeaStateMachine)cancelFsm, cancelSignal);
	meaPmViewRemove();
}

//check if progressing view existing
MSF_BOOL meaPmIsActive(void)
{
    return (meaPmView.formHandle);
}

//Set title and precentage of progressing view
void meaPmSetProgressWithText(unsigned int perCent, const char *initialStr, const char *endStr)
{
    kal_uint8 *buffer1=NULL;
    kal_uint8 *buffer2=NULL;
    int size;
    if (initialStr)
    {
        size=(widget_utf8_length((kal_uint8*)initialStr)+1) * UCS2_ENCODING_LENGTH;		
        buffer1 = MEA_ALLOC(size);
        widget_utf8_to_ucs2_string(buffer1, 40, (kal_uint8*)initialStr);
    }
    if (endStr)
    {
        size=(widget_utf8_length((kal_uint8*)endStr)+1) * UCS2_ENCODING_LENGTH;		
        buffer2 = MEA_ALLOC(size);
        widget_utf8_to_ucs2_string(buffer2, 40, (kal_uint8*)endStr);
    }
    if (meaPmView.formHandle)
        HDIa_widgetExtSetProgressPercentage(meaPmView.formHandle, (unsigned short)perCent, 
            buffer1, buffer2);
}
#endif /* WAP_SUPPORT */
/*!
 * \brief Creates a progress meter "dialog".
 *
 * \param messageStrId The message that is displayed in the PM dialog.
 * \param manualTick Tick the progress meter manually.
 * \param allowCancel Tells whether a cancel signal is sent when the user wants
 *                    to cancel the ongoing operation.
 * \param fsm The fsm that receives a signal when the End User wants to cancel
 *            the ongoing operation.
 * \param signal The signal that is sent to the fsm.
 * \return TRUE if successful, otherwise FALSE. If the operation failed, call
 *         meaPmViewRemove for a clean-up.
 *****************************************************************************/
MSF_BOOL meaPmViewShow(MSF_UINT32 messageStrId, MSF_BOOL manualTick, 
    int allowCancel, int fsm, int signal)
{
#ifndef WAP_SUPPORT
    MsfPosition pos;
    MsfSize     size;
    MSF_INT16   oldPos, txtPos;
#endif /* ~WAP_SUPPORT */

    if (0 != meaPmView.formHandle)
    {
        return FALSE;
    }

#ifdef WAP_SUPPORT
    if (0 == (meaPmView.formHandle = HDIa_widgetExtCreateProgressView(MSF_MODID_MEA, 
        (ctk_string_id)messageStrId, (ctk_image_id)(allowCancel?MEA_IMG_TITLE_NORMAL:0), KAL_TRUE)))
    {
        return FALSE;
    }

    HDIa_widgetExtSetProgressPercentage(meaPmView.formHandle, 0,
		  HDIa_widgetExtStringGetPredefinedUCS2buffer(messageStrId),
		   (kal_uint8*)L"0%");
    meaAddWidgetList(meaPmView.formHandle);
#else
    if (0 == (meaPmView.formHandle = MSF_WIDGET_FORM_CREATE(MSF_MODID_MEA, 
        NULL, 0, 0)))
    {
        return FALSE;
    }
    /* Add text */
    meaGetDisplaySize(&size);
    pos.x = MEA_PM_BORDER_WIDTH;
    pos.y = (short)(size.height / 2);
    size.height = MEA_PM_TEXT_HEIGHT;
    size.width = (short)(size.width - 2*MEA_PM_BORDER_WIDTH);
    if (0 == (meaPmView.textGadget = MSF_WIDGET_STRING_GADGET_CREATE(
        MSF_MODID_MEA, MEA_GET_STR_ID(messageStrId), &size,
        FALSE, 0 ,0)))
    {
        return FALSE;
    }
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaPmView.formHandle, 
        meaPmView.textGadget, &pos, 0))
    {
        return FALSE;
    }

    /* Create progress meter gadget */
    txtPos = pos.y;
    pos.y = (short)((pos.y - MEA_PM_BORDER_WIDTH) - MEA_PM_HEIGHT);
    if (pos.y < 0) 
    {
        /* This should normally not happen unless the screen is very small, 
         * then the effect will be that the text has to be moved down */
        txtPos = (MSF_INT16)(txtPos + -pos.y);
        oldPos = pos.y;
        pos.y = txtPos;
        (void)MSF_WIDGET_SET_POSITION(meaPmView.textGadget, &pos, NULL);
        pos.y = 0;
    }
    size.height = MEA_PM_HEIGHT;
    if (0 == (meaPmView.progressGadget = MSF_WIDGET_BAR_CREATE(MSF_MODID_MEA,
        MsfProgressBar, MEA_PM_TICKS, 0, &size, 0, 0)))
    {
        return FALSE;
    }
    
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaPmView.formHandle, 
        meaPmView.progressGadget, &pos, 0))
    {
        return FALSE;
    }
#endif /* WAP_SUPPORT */
    if (!manualTick)
    {
        MSF_TIMER_SET(MSF_MODID_MEA, MEA_PM_TIMER_ID, MEA_PM_TICK_TIME);
    }
    /* Create cancel action if needed */
    if (allowCancel)
    {
#ifdef WAP_SUPPORT
        ctk_screen_handle scrId = HDIa_widgetCtkGetScreenHandle(meaPmView.formHandle);
        cancelFsm = fsm; 
        cancelSignal = signal;
        ctk_screen_addRSK_UA(scrId, MEA_STR_ID_CANCEL, 0, NULL, meaPmHandleCancel, KAL_TRUE);
#else
        if (0 == meaCreateAction(meaPmView.formHandle, MsfCancel, NULL, 
            fsm, signal, MEA_STR_ID_CANCEL))
            return FALSE;
#endif /* WAP_SUPPORT */
    }
    /* Show the progress meter view */
    return meaDisplayWindow(meaPmView.formHandle, meaGetPosLeftTop());
}

/*!\brief Removes the progress meter dialog.
 *
 *****************************************************************************/
void meaPmViewRemove()
{
    /* Delete the form and its associated actions */
    if (0 == meaPmView.formHandle)
    {
        return;
    }
#ifdef WAP_SUPPORT
    clearProgressPercent();
#endif /* WAP_SUPPORT */
    
    /* Remove gadgets */
    if (0 != meaPmView.progressGadget)
    {
        (void)MSF_WIDGET_RELEASE(meaPmView.progressGadget);
    }

    if (0 != meaPmView.textGadget)
    {
        (void)MSF_WIDGET_RELEASE(meaPmView.textGadget);
    }
    if (!meaDeleteWindow(meaPmView.formHandle))
    {
        /* Delete the window if is is not registered */
        if (!MSF_WIDGET_REMOVE(meaGetScreenHandle(), meaPmView.formHandle))
        {
            (void)MSF_WIDGET_RELEASE(meaPmView.formHandle);
        }
    }
    /* Reset timer */
    MSF_TIMER_RESET(MSF_MODID_MEA, MEA_PM_TIMER_ID);
    /* Delete obsolete handles */
    memset(&meaPmView, 0, sizeof(MeaPmView));
    /* Reset variables*/
    cancelFsm = 0;
    cancelSignal = 0;
}

void meaPmViewRemoveFromMV(void)
{
    /* Have a sending or receiving process, remain this PM view*/
    if (cancelFsm == MEA_COMM_FSM)
    {
        return;
    }
    meaPmViewRemove();
}

/*!\brief Handles timer events for the progress meter dialog.
 *
 *****************************************************************************/
void meaPmHandleTimer()
{
    int value;
    int maxValue;
    if (0 != meaPmView.progressGadget)
    {
        (void)MSF_WIDGET_BAR_GET_VALUES(meaPmView.progressGadget, 
            &value, &maxValue);
        value++;
        (void)MSF_WIDGET_BAR_SET_VALUES(meaPmView.progressGadget, 
            value%MEA_PM_TICKS, maxValue);
        MSF_TIMER_SET(MSF_MODID_MEA, MEA_PM_TIMER_ID, MEA_PM_TICK_TIME);
    }
}

/*!\brief Handles timer events for the progress meter dialog.
 *
 * \param perCent The progress in "per cent".
 * \param str The string to display or NULL if the string should be unchanged.
 *****************************************************************************/
void meaPmSetProgress(unsigned int perCent, const char *str)
{
#ifdef WAP_SUPPORT
	if (meaPmView.formHandle)
    {
        HDIa_widgetExtSetProgressPercentage(meaPmView.formHandle, (unsigned short)perCent, 
            NULL, NULL);//(kal_uint8*)buffer);
    }
#else
    int value;
    int maxValue;
    MsfStringHandle strHandle;
    if (0 != meaPmView.progressGadget)
    {
        (void)MSF_WIDGET_BAR_GET_VALUES(meaPmView.progressGadget, 
            &value, &maxValue);
        value = (maxValue*(int)perCent)/100;
        (void)MSF_WIDGET_BAR_SET_VALUES(meaPmView.progressGadget, 
            value, maxValue);
        if ((NULL != str) && (0 != meaPmView.textGadget))
        {
            if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
                str, MsfUtf8, (int)strlen(str) + 1, 0)))
            {
                (void)MSF_WIDGET_RELEASE(strHandle);
                return;
            }
            (void)MSF_WIDGET_STRING_GADGET_SET(meaPmView.textGadget, strHandle, 
                FALSE);
            (void)MSF_WIDGET_RELEASE(strHandle);
        }
    }
#endif /* WAP_SUPPORT */
}


