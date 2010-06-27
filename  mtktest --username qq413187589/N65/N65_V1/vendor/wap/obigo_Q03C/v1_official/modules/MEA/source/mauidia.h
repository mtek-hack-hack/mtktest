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

/*!\file mauidia.h
 * \brief Dialog handling.
 */

#ifndef _MAUIDIA_H_
#define _MAUIDIA_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! \enum MeaDialogType
 *  Global dialog types */
typedef enum
{
    MEA_DIALOG_ALERT,   /* !< Alert dialog */
    MEA_DIALOG_WARNING, /* !< Warning dialog */
#ifdef WAP_SUPPORT  //should map to msfDialog in showDialog function
    MEA_DIALOG_CONFIRMATION,
    MEA_DIALOG_PROMPT,
    MEA_DIALOG_PROMPT_EMPTY,
    MEA_DIALOG_PROMPT_DONE,
#endif /* WAP_SUPPORT */
    MEA_DIALOG_INFO,    /* !< Information dialog */
    MEA_DIALOG_ERROR    /* !< Error dialog */
}MeaDialogType;

/*! \enum MeaConfirmDialogResult
 *  Actions related to the confirmation dialog */
typedef enum
{
    MEA_CONFIRM_DIALOG_OK,     /* !< The End User presses ok */
    MEA_CONFIRM_DIALOG_CANCEL  /* !< The End USer presses cancel */
}MeaConfirmDialogResult;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

MSF_BOOL meaDeleteDialog(MsfWindowHandle windowHandle);
MSF_BOOL meaDeletePanicDialog(MsfWindowHandle windowHandle);
MSF_BOOL meaHandleConfirmationDialogSignal(MsfWindowHandle windowHandle, 
    MsfActionHandle actionHandle);
void meaInitDia(void);
MSF_BOOL meaShowConfirmDialog(MSF_UINT32 textStrId, const char *str, 
    MeaStateMachine fsm, int signal, unsigned int id);
MSF_BOOL meaShowDialog(MsfStringHandle strHandle, MeaDialogType dialogType);
MSF_BOOL meaShowDialogWithCallback(MsfStringHandle strHandle, 
    MeaDialogType dialogType, MeaStateMachine fsm, int signal);
MSF_BOOL meaShowPanicDialog(void);
unsigned int meaGetDialogCount(void);
MSF_BOOL meaCheckDialogs(void);
void meaTerminateDia(void);
MSF_BOOL showErrorDlg(const char *str);

#ifdef WAP_SUPPORT
MSF_BOOL meaShowConfirmDialogWithStatusIcons(MSF_UINT32 textStrId, const char *str, 
    MeaStateMachine fsm, int signal, unsigned int id);
void meaShowWindowAfterDialog(MsfWindowHandle windowHandle);
MSF_BOOL meaShowDialogWithConfirm(MsfDialogType dlgType, MSF_UINT32 lskStrId, MSF_UINT32 rskStrId, 
    MSF_UINT32 textStrId, MeaStateMachine fsm, int signal, unsigned int id);
#endif /* WAP_SUPPORT */
#endif


