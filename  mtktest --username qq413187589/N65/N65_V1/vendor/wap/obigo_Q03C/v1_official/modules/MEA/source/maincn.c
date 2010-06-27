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

/* \file maincn.c
 * \brief Control logic for the incoming notification.
 */

/* MSF */
#include "msf_log.h"
#include "msf_core.h"

/* MMS */
#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"

/* MEA */
#include "mea_def.h"
#include "mea_rc.h"
#include "maintsig.h"
#include "maincn.h"
#include "mauiincn.h"
#include "mamh.h"

/******************************************************************************
 * Prototypes
 *****************************************************************************/

static void meaInSignalHandler(MeaSignal *sig);

/******************************************************************************
 * Implementation
 *****************************************************************************/

/*!
 * \brief Signal handler for IN.
 *
 * \param sig The incoming signal.
 *****************************************************************************/
static void meaInSignalHandler(MeaSignal *sig)
{
    /*lint -e{788}*/
    switch ((MeaInSignalId) sig->type)
    {
    case(MEA_SIG_IN_ACTIVATE):
#ifndef WAP_SUPPORT
        /* Play a notification sound */
        meaInPlayNotification();
#endif /* ~WAP_SUPPORT */
        /* Send update signal to MH */
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER);
        break;
    case(MEA_SIG_IN_DEACTIVATE):
        /* Nothing to do */
        break;
    default :
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAINCN_D7A3597F16116CD54F62F3FD55B515DD, "MEA IN: Unknown signal received (%d)\n", sig->type));
        break;
    }
    meaSignalDelete(sig);
}

/*!
 * \brief Initiates the IN FSM.
 *
 *****************************************************************************/
void meaInInit(void)
{
    /* set sig-handler */
    meaSignalRegisterDst(MEA_IN_FSM, meaInSignalHandler);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAINCN_BE713B8DA521EB3B4500A329F5EAC6BC, "MEA IN: initialized\n"));
}

/*!
 * \brief Terminates the IN FSM.
 *
 *****************************************************************************/
void meaInTerminate(void)
{
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAINCN_78E5D72B0ABE8949E34120C1792651B7, "MEA IN: terminated\n"));
    meaSignalDeregister(MEA_IN_FSM); 
}


