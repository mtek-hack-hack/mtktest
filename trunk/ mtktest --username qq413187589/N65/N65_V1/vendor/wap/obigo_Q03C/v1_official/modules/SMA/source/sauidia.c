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

/* MSF */
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_def.h"
#include "msf_log.h"
#include "msf_wid.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

/* SMA */
#include "sma_cfg.h"
#include "sma_rc.h"
#include "saintsig.h"
#include "sauidia.h"
#include "satypes.h"
#include "sma_def.h"
#include "saui.h"

/******************************************************************************
 * Defines
 *****************************************************************************/
#define SMA_MAX_DIALOGS     3 /* <! Maximum number of dialogs queued */
#define IS_DIALOG_DISPLAYED (smaDialog.dialogHandle != 0)

/******************************************************************************
 * Data-types
 *****************************************************************************/

/* Data structure for confirmation dialogs */
typedef struct
{
    MsfWindowHandle dialogHandle;       /* <! The dialog handle */
    /* Action handles */             
    MsfActionHandle cancelActionHandle; /* <! Cancel action handle*/
    MsfActionHandle okActionHandle;     /* <! Ok action handle */
    /* Destination signal */
    int fsm;                    /* <! The response FSM */
    int signal;                 /* <! The response signal */
    unsigned int    id;         /* <! ID,  */
}SmaConfirmDialog;

/* Data-structures for global dialog data */
typedef struct
{
    MsfWindowHandle dialogHandle;   /* <! Dialog handle */
}SmaDialog;

/* Dialog structure, used for queuing dialog  */
typedef struct
{
    MsfStringHandle	strHandle;      /* <! The string to be displayed*/
    SmaDialogType   dialogType; /* <! The type of dialog that is displayed */
}SmaDialogItem;

/******************************************************************************
 * Global variables
 *****************************************************************************/

static SmaDialog            smaDialog;
static SmaDialogItem        smaDialogQueue[SMA_MAX_DIALOGS];
static SmaConfirmDialog     smaConfirmDialog;
static MsfWindowHandle      smaPanicDialog;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

static MSF_BOOL addDialogItem(SmaDialogType dialogType, MsfStringHandle strHandle);
static MSF_BOOL showDialog(void);

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief Add a dialog to the dialog queue.
 *
 * \param item The dialog item to add to the list of items to be displayed.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL addDialogItem(SmaDialogType dialogType, MsfStringHandle strHandle)
{
    int i;
    for(i = 0; i < SMA_MAX_DIALOGS; i++)
    {
        /* Find an empty slot */
        if (0 == smaDialogQueue[i].strHandle)
        {
            smaDialogQueue[i].strHandle  = strHandle;
            smaDialogQueue[i].dialogType = dialogType;
            return TRUE;
        }
    }
    return FALSE;
}

/*!
 * \brief Deletes the dialog with dialogHandle .
 *
 * \param windowHandle The handle of the window that is to be deleted.
 * \return TRUE if the window has been deleted, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaDeleteDialog(MsfWindowHandle dialogHandle)
{
    /* Check all the global dialogs */
    if (smaConfirmDialog.dialogHandle == dialogHandle)
    {
        /* Confirm dialog */
        (void)MSF_WIDGET_REMOVE(smaGetScreenHandle(), 
            smaConfirmDialog.dialogHandle);
        (void)MSF_WIDGET_RELEASE(smaConfirmDialog.dialogHandle);
        (void)MSF_WIDGET_RELEASE(smaConfirmDialog.okActionHandle);
        (void)MSF_WIDGET_RELEASE(smaConfirmDialog.cancelActionHandle);
        memset(&smaConfirmDialog, 0, sizeof(SmaConfirmDialog));
        return TRUE;
    }
    else if (smaDialog.dialogHandle == dialogHandle)
    {
        (void)MSF_WIDGET_RELEASE(smaDialog.dialogHandle);
        memset(&smaDialog, 0, sizeof(SmaDialog));
        /* Show the next dialog in the list */
        (void)showDialog();
        return TRUE;
    }
    return FALSE;
}

/*! \brief Deletes the panic dialog.
 *
 * \param windowHandle The handle of the 
 * \return TRUE if successfull, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaDeletePanicDialog(MsfWindowHandle windowHandle)
{
    if (windowHandle == smaPanicDialog)
    {
        (void)MSF_WIDGET_RELEASE(smaPanicDialog);
        return TRUE;
    } /* if */
    return FALSE;
}

/*!
 * \brief Handles deletion of the confirmation dialog.
 *
 * \param windowHandle The handle of the window that generated a notification.
 * \param actionHandle The action handle of the generated action.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaHandleConfirmationDialogSignal(MsfWindowHandle windowHandle, 
    MsfActionHandle actionHandle)
{
    if (smaConfirmDialog.dialogHandle == windowHandle)
    {
        /* Send signal depending on action type */
        if (actionHandle == smaConfirmDialog.okActionHandle)
        {
            (void)SMA_SIGNAL_SENDTO_UU( (SmaStateMachine)smaConfirmDialog.fsm, 
                smaConfirmDialog.signal, SMA_CONFIRM_DIALOG_OK, 
                smaConfirmDialog.id);
        }
        else if (actionHandle == smaConfirmDialog.cancelActionHandle)
        {
            (void)SMA_SIGNAL_SENDTO_UU( (SmaStateMachine)smaConfirmDialog.fsm, 
                smaConfirmDialog.signal, SMA_CONFIRM_DIALOG_CANCEL, 
                smaConfirmDialog.id);
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
                SAUIDIA_68108B0AB2E07EB677F5E16478AD88F2, "(%s) (%d) erroneous signal type!\n", __FILE__, __LINE__));
        }
        /* Delete the dialog */
        (void)smaDeleteDialog(windowHandle);
        return TRUE;
    }
    return FALSE;
}

/*!
 * \brief Initiates the data-structures for the dialog handling.
 *****************************************************************************/
void smaInitDia(void)
{
    /* Create a panic dialog, if anything went totaly wrong */
    smaPanicDialog = MSF_WIDGET_DIALOG_CREATE(MSF_MODID_SMA,
        SMA_GET_STR_ID(SMA_STR_ID_EMPTY_STRING), MsfError,
		SMA_DIALOG_DEFAULT_TIME_OUT, 0, 0);
    memset(&smaConfirmDialog, 0, sizeof(SmaConfirmDialog));
    memset(smaDialogQueue, 0, sizeof(smaDialogQueue));
    memset(&smaDialog, 0, sizeof(SmaDialog));
} /* smaInitDia */

/*!
 * \brief Creates and displays a global dialog. If textStr is NULL textStrId is
 *        used instead. 
 *
 * \param textStrId The text that is presented.
 * \param dialogType The type of dialog that is presented, see #SmaDialogType.
 * \return TRUE if the dialog was created, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaShowDialog(MSF_UINT32 textStrId, SmaDialogType dialogType)
{
	MsfStringHandle stringHandle;
	stringHandle = MSF_WIDGET_STRING_GET_PREDEFINED(textStrId);
		
    if (!addDialogItem(dialogType, stringHandle))
    {
        return FALSE;
    }
    /* Check if a dialog is currently displayed */
    if (!IS_DIALOG_DISPLAYED)
    {
        /* Show next dialog in the queue */
        return showDialog();
    }
    return TRUE;
} /* smaShowDialog */

/*!
 * \brief Displays a dialog that requires End User actions to disappear.
 *
 * \param textStrId The text to be displayed.
 * \param fsm The FSM to respond the result to.
 * \param signal The response signal.
 * \param id A optional id that is sent back in the response as u_param2.
 * \return  TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaShowConfirmDialog(MSF_UINT32 textStrId, SmaStateMachine fsm, 
    int signal, unsigned int id)
{
    if (0 != smaConfirmDialog.dialogHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
            SAUIDIA_B308D4280296A2DC7B04F7DE3E738342, "(%s) (%d) instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }
    smaConfirmDialog.fsm    = fsm;
    smaConfirmDialog.signal = signal;
    smaConfirmDialog.id     = id;
   
    /* Create dialog */
    smaConfirmDialog.dialogHandle = MSF_WIDGET_DIALOG_CREATE(MSF_MODID_SMA, 
        SMA_GET_STR_ID(textStrId), MsfConfirmation, 0, 
        MSF_WINDOW_PROPERTY_NOTIFY, 0);
    if (0 == smaConfirmDialog.dialogHandle)
    {
        return FALSE;
    }
    /* Create actions */
    smaConfirmDialog.okActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, 
        SMA_GET_STR_ID(MEA_STR_ID_LSK_YES), MsfOk, 0, MSF_ACTION_PROPERTY_ENABLED);/*SMA_STR_EMPTY_STRING*/
    if (-1 == MSF_WIDGET_ADD_ACTION(smaConfirmDialog.dialogHandle, 
        smaConfirmDialog.okActionHandle))
    {
        (void)MSF_WIDGET_RELEASE(smaConfirmDialog.dialogHandle);
        memset(&smaConfirmDialog, 0 , sizeof(SmaConfirmDialog));
        return FALSE;
    }
    smaConfirmDialog.cancelActionHandle = MSF_WIDGET_ACTION_CREATE(
        MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_RSK_NO), MsfCancel, 0, /*SMA_STR_EMPTY_STRING*/
        MSF_ACTION_PROPERTY_ENABLED);
    if (-1 == MSF_WIDGET_ADD_ACTION(smaConfirmDialog.dialogHandle, 
        smaConfirmDialog.cancelActionHandle))
    {
        (void)MSF_WIDGET_RELEASE(smaConfirmDialog.dialogHandle);
        (void)MSF_WIDGET_RELEASE(smaConfirmDialog.okActionHandle);
        memset(&smaConfirmDialog, 0 , sizeof(SmaConfirmDialog));
        return FALSE;
    }
    /* Display the dialog */
    if (-1 != MSF_WIDGET_SCREEN_ADD_WINDOW(smaGetScreenHandle(), 
        smaConfirmDialog.dialogHandle, smaGetPosLeftTop(), 
        smaGetScreenHandle(), 0))
    {
        (void)MSF_WIDGET_SET_IN_FOCUS(smaGetScreenHandle(), TRUE);
        (void)MSF_WIDGET_SET_IN_FOCUS(smaConfirmDialog.dialogHandle, TRUE);
    }
    else
    {
        (void)MSF_WIDGET_RELEASE(smaConfirmDialog.dialogHandle);
        (void)MSF_WIDGET_RELEASE(smaConfirmDialog.okActionHandle);
        (void)MSF_WIDGET_RELEASE(smaConfirmDialog.cancelActionHandle);
        memset(&smaConfirmDialog, 0 , sizeof(SmaConfirmDialog));
        return FALSE;
    }
    return TRUE;
} /* smaShowConfirmDialog */
 
/*! \brief Display the panic dialog.
 *
 * \return TRUE if successfull, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaShowPanicDialog(void)
{
    if (0 != smaPanicDialog)
    {
        return smaBindAndShowWindow(smaPanicDialog, smaGetPosLeftTop());
    }
    return FALSE;      
} /* smaShowPanicDialog */

/*!
 * \brief De-allocates resources allocated for the dialog handling.
 *****************************************************************************/
void smaTerminateDia(void)
{
    /* Delete panic dialog */
    if (0 != smaPanicDialog)
    {
       (void)MSF_WIDGET_RELEASE(smaPanicDialog);
        smaPanicDialog = 0;
    }
    memset(smaDialogQueue, 0, sizeof(smaDialogQueue));
    (void)smaDeleteDialog(smaDialog.dialogHandle);
    (void)smaDeleteDialog(smaConfirmDialog.dialogHandle);
} /* smaTerminateDia */

/*!
 * \brief Creates and displays a dialog.
 * 
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL showDialog()
{
    int i;
    MsfDialogType msfDialogType;
    
    if (0 != smaDialog.dialogHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
            SAUIDIA_5AA3B4FB841AC6A9C5FC4188FD141007, "(%s) (%d) instance busy!\n", __FILE__, __LINE__));
        return FALSE;
    }
    if (0 == smaDialogQueue[0].strHandle)
    {
        return FALSE;
    }
    msfDialogType = MsfWarning;
    switch (smaDialogQueue[0].dialogType)
    {
    case(SMA_DIALOG_ALERT):
        msfDialogType = MsfAlert;
        break;
    case(SMA_DIALOG_WARNING):
        msfDialogType = MsfWarning;
        break;
    case(SMA_DIALOG_INFO):
        msfDialogType = MsfInfo;
        break;
    case(SMA_DIALOG_ERROR):
        msfDialogType = MsfError;
        break;
    }
    
    /* Create dialog */
    smaDialog.dialogHandle = MSF_WIDGET_DIALOG_CREATE(MSF_MODID_SMA, 
        smaDialogQueue[0].strHandle, msfDialogType, 
        SMA_DIALOG_DEFAULT_TIME_OUT, MSF_WINDOW_PROPERTY_NOTIFY, 0);
    if (0 == smaDialog.dialogHandle)
    {
        return FALSE;
    }

    /* Display the dialog */
    if (-1 != MSF_WIDGET_SCREEN_ADD_WINDOW(smaGetScreenHandle(), 
        smaDialog.dialogHandle, smaGetPosLeftTop(), smaGetScreenHandle(), 0))
    {
        (void)MSF_WIDGET_SET_IN_FOCUS(smaGetScreenHandle(), TRUE);
        (void)MSF_WIDGET_SET_IN_FOCUS(smaDialog.dialogHandle, TRUE);
    }
    else
    {
        (void)MSF_WIDGET_RELEASE(smaDialog.dialogHandle);
        smaDialog.dialogHandle = 0;
        return FALSE;
    }
    /* Remove the item from the queue */
    for(i = 0; i < SMA_MAX_DIALOGS - 1; i++)
    {
        memcpy(&smaDialogQueue[i], &smaDialogQueue[i + 1], 
            sizeof(SmaDialogItem));
    }
    /* Set last item to zero */
    smaDialogQueue[SMA_MAX_DIALOGS - 1].dialogType = (SmaDialogType)0;
    smaDialogQueue[SMA_MAX_DIALOGS - 1].strHandle  = 0;
    return TRUE;
} /* showDialog */

void smaShowPopup(MSF_UINT32 textStrId, MsfDialogType dialogType)
{
    MsfStringHandle string;

    string = MSF_WIDGET_STRING_GET_PREDEFINED(textStrId);
    HDIa_widgetExtForcePopup(string, dialogType, 0);
}

