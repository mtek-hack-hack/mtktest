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

/* !\file mauicomm.c
 */

/* MSF */
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_cfg.h"
#include "msf_def.h"
#include "msf_lib.h"
#include "msf_cmmn.h"

/* MMS */
#include "mms_def.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_rc.h"
#include "maintsig.h"
#include "mauidia.h"
#include "mea_def.h"
#include "mauicmn.h"
#include "matypes.h"
#include "mautils.h"
#include "mamem.h"

#ifdef WAP_SUPPORT
static MSF_BOOL confirmDialogWithStatusIconsFlag = FALSE;
/*!
 * \brief Set ConfirmDialogWithStatusIconsFlag
 *****************************************************************************/
void meaSetConfirmDialogWithStatusIcons(void)
{
    confirmDialogWithStatusIconsFlag = TRUE;
}
#endif /* WAP_SUPPORT */

/*!
 * \brief Creates a transaction request dialog
 *
 * \param fsm The FSM to report the answer to.
 * \param signal The signal to send.
 * \param strId1 The first predefined string to use
 * \param strId2 The second predefined string to use
 * \param size The byte size of the message to download.
 * \return TRUE if the dialog is displayed successfully, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL meaShowTransferDialog(MeaStateMachine fsm, unsigned int signal, 
    MSF_UINT32 strId1, MSF_UINT32 strId2, unsigned int size)
{
    char *str1;
    char *str3;
    char *newStr;
    char buffer[10*sizeof(char) + sizeof('\0')];

    str1 = meaGetStringFromHandle(MEA_GET_STR_ID(strId1));
    str3 = meaGetStringFromHandle(MEA_GET_STR_ID(strId2));
    sprintf(buffer, "%d", (size + (MEA_1_KB - 1)) / MEA_1_KB);
    if (NULL == (newStr = msf_cmmn_str3cat(MSF_MODID_MEA, str1, buffer, str3)))
    {
        return FALSE;
    }
    MEA_FREE(str1);
    MEA_FREE(str3);
    if (!meaShowConfirmDialog(0, newStr, fsm, (int)signal, 0))
    {
        /*lint -e{774} */
        MEA_FREE(newStr);
        return FALSE;
    }
    /*lint -e{774} */
    MEA_FREE(newStr);
    return TRUE;
}


/*!
 * \brief Creates a transaction request dialog
 *
 * \param fsm The FSM to report the answer to.
 * \param signal The signal to send.
 * \param strId1 The first predefined string to use
 * \param strId2 The second predefined string to use
 * \param size The byte size of the message to download.
 * \return TRUE if the dialog is displayed successfully, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL meaShowTransferDialogExt(MeaStateMachine fsm, unsigned int signal, 
    MSF_UINT32 strId1, MSF_UINT32 strId2, unsigned int size, MSF_UINT32 simId)
{
    char *str1;
    char *str3;
    char *newStr;
    char buffer[10*sizeof(char) + sizeof('\0')];

    str1 = meaGetStringFromHandle(MEA_GET_STR_ID(strId1));
    str3 = meaGetStringFromHandle(MEA_GET_STR_ID(strId2));
    sprintf(buffer, "%d", (size + (MEA_1_KB - 1)) / MEA_1_KB);
    if (NULL == (newStr = msf_cmmn_str3cat(MSF_MODID_MEA, str1, buffer, str3)))
    {
        return FALSE;
    }
    MEA_FREE(str1);
    MEA_FREE(str3);
#ifdef __MMS_DUAL_SIM_SUPPORT__
    if(simId == MMS_SIM_CARD_MASTER || simId == MMS_SIM_CARD_SLAVE)
    {
        if(simId == MMS_SIM_CARD_MASTER)
        {
            str1 = meaGetStringFromHandle(MEA_GET_STR_ID(MEA_STR_ID_SIM_1));
        }
        else if(simId == MMS_SIM_CARD_SLAVE)
        {
            str1 = meaGetStringFromHandle(MEA_GET_STR_ID(MEA_STR_ID_SIM_2));
        }
        str3 = msf_cmmn_str3cat(MSF_MODID_MEA, " (", str1, ")");
        newStr = msf_cmmn_strcat(MSF_MODID_MEA,newStr,str3);
        
        MEA_FREE(str1);
        MEA_FREE(str3);
    }
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
    
    if (!meaShowConfirmDialog(0, newStr, fsm, (int)signal, simId))
    {
        /*lint -e{774} */
        MEA_FREE(newStr);
        return FALSE;
    }
    /*lint -e{774} */
    MEA_FREE(newStr);
    return TRUE;
}


/*!
 * \brief Creates a download request dialog
 *
 * \param fsm The FSM to report the answer to.
 * \param signal The signal to send.
 * \param size The size of the message to download.
 * \return TRUE if the dialog is displayed successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowHomeRetrievalDialogExt(MeaStateMachine fsm, unsigned int signal, 
    unsigned int size, MSF_UINT32 simId)
{
    return meaShowTransferDialogExt(fsm, signal, MEA_STR_ID_DOWNLOAD_REQ1,
        MEA_STR_ID_DOWNLOAD_REQ2, size, simId);
}


/*!
 * \brief Creates a download request dialog for use when roaming
 *
 * \param fsm The FSM to report the answer to.
 * \param signal The signal to send.
 * \param size The size of the message to download.
 * \return TRUE if the dialog is displayed successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowRoamingRetrievalDialogExt(MeaStateMachine fsm, 
    unsigned int signal, unsigned int size, MSF_UINT32 simId)
{
    return meaShowTransferDialogExt(fsm, signal, MEA_STR_ID_ROAM_DOWNLOAD_REQ1,
        MEA_STR_ID_ROAM_DOWNLOAD_REQ2, size, simId);
}

/*!
 * \brief Creates a download request dialog
 *
 * \param fsm The FSM to report the answer to.
 * \param signal The signal to send.
 * \param size The size of the message to download.
 * \return TRUE if the dialog is displayed successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowHomeRetrievalDialog(MeaStateMachine fsm, unsigned int signal, 
    unsigned int size)
{
    return meaShowTransferDialog(fsm, signal, MEA_STR_ID_DOWNLOAD_REQ1,
        MEA_STR_ID_DOWNLOAD_REQ2, size);
}


/*!
 * \brief Creates a download request dialog for use when roaming
 *
 * \param fsm The FSM to report the answer to.
 * \param signal The signal to send.
 * \param size The size of the message to download.
 * \return TRUE if the dialog is displayed successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowRoamingRetrievalDialog(MeaStateMachine fsm, 
    unsigned int signal, unsigned int size)
{
    return meaShowTransferDialog(fsm, signal, MEA_STR_ID_ROAM_DOWNLOAD_REQ1,
        MEA_STR_ID_ROAM_DOWNLOAD_REQ2, size);
}

/*!
 * \brief Creates a send request dialog for use when roaming
 *
 * \param fsm The FSM to report the answer to.
 * \param signal The signal to send.
 * \param size The size of the message to download.
 * \return TRUE if the dialog is displayed successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowRoamingSendDialog(MeaStateMachine fsm, unsigned int signal,
                                  unsigned int size)
{
    return meaShowTransferDialog(fsm, signal, MEA_STR_ID_ROAM_SEND_REQ1,
        MEA_STR_ID_ROAM_SEND_REQ2, size);

}

/*!
 * \brief Creates a send request dialog for use when roaming
 *
 * \param fsm The FSM to report the answer to.
 * \param signal The signal to send.
 * \param size The size of the message to download.
 * \return TRUE if the dialog is displayed successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowRoamingSendDialogExt(MeaStateMachine fsm, unsigned int signal,
                                  unsigned int size, MSF_UINT32 simId)
{
    return meaShowTransferDialogExt(fsm, signal, MEA_STR_ID_ROAM_SEND_REQ1,
        MEA_STR_ID_ROAM_SEND_REQ2, size, simId);

}


/*!
 * \brief Creates a network settings error dialog
 *
 * \param fsm The FSM to report the answer to.
 * \param signal The signal to send.
 * \return TRUE if the dialog is displayed successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowSettingsErrorDialog(MeaStateMachine fsm, int signal)
{
    return meaShowDialogWithCallback(MEA_GET_STR_ID(
        MEA_STR_ID_INVALID_NETWORK_SETTINGS), MEA_DIALOG_ERROR, fsm, signal);
}


