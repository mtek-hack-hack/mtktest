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
/*******************************************************************************
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   MapStructure2MMI.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  .......
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
#include "MMI_include.h"

#ifdef __MMI_UCM__


#ifdef MMI_ON_HARDWARE_P

#include "custom_util.h"
#endif /* MMI_ON_HARDWARE_P */ 

/*****************************************************************************
 * FUNCTION
 *  CheckAndPrintMsgId
 * DESCRIPTION
 *  Checks and Prints Msg Ids Recieved from L4
 * PARAMETERS
 *  Id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CheckAndPrintMsgId(U16 Id)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (Id)
    {
        case MSG_ID_MMI_CC_SPEECH_IND:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_SPEECH_IND ***\n");
            break;
        case MSG_ID_MMI_CC_CALL_RELEASE_IND:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_CALL_RELEASE_IND ***\n");
            break;
        case MSG_ID_MMI_CC_START_DTMF_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_START_DTMF_RSP ***\n");
            break;
        case MSG_ID_MMI_CC_STOP_DTMF_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_STOP_DTMF_RSP ***\n");
            break;
        case MSG_ID_MMI_CC_DIAL_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_DIAL_RSP ***\n");
            break;
        case MSG_ID_MMI_CC_GET_CALL_LIST_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_GET_CALL_LIST_RSP ***\n");
            break;
        case MSG_ID_MMI_CC_GET_CALL_LIST_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_GET_CALL_LIST_REQ ***\n");
            break;
        case MSG_ID_MMI_CC_CHLD_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_CHLD_RSP ***\n");
            break;
        case MSG_ID_MMI_CC_ATH_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_ATH_RSP ***\n");
            break;
        case MSG_ID_MMI_CC_CALL_RING_IND:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_CALL_RING_IND ***\n");
            break;
        case MSG_ID_MMI_CC_ATA_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_ATA_RSP ***\n");
            break;
        case MSG_ID_MMI_EQ_SET_SPEECH_MODE_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_EQ_SET_SPEECH_MODE_RSP ***\n");
            break;
        case MSG_ID_MMI_CC_DIAL_IND:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_DIAL_IND ***\n");
            break;
        case MSG_ID_MMI_CC_CALL_CONNECT_IND:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_CALL_CONNECT_IND ***\n");
            break;
        case MSG_ID_MMI_CC_CALL_WAIT_IND:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_CALL_WAIT_IND ***\n");
            break;
        case MSG_ID_MMI_CC_ATA_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_ATA_REQ ***\n");
            break;
        case MSG_ID_MMI_CC_ATH_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_ATH_REQ ***\n");
            break;
        case MSG_ID_MMI_CC_CHLD_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_CHLD_REQ ***\n");
            break;
        case MSG_ID_MMI_CC_DIAL_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_DIAL_REQ ***\n");
            break;
        case MSG_ID_MMI_CC_START_DTMF_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_START_DTMF_REQ ***\n");
            break;
        case MSG_ID_MMI_CC_STOP_DTMF_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_STOP_DTMF_REQ ***\n");
            break;
        case MSG_ID_MMI_SS_USSD_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_SS_USSD_REQ ***\n");
            break;
        case MSG_ID_MMI_SS_CALL_FORWARD_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_SS_CALL_FORWARD_REQ ***\n");
            break;
        case MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ ***\n");
            break;
        case MSG_ID_MMI_EQ_PLAY_AUDIO_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_EQ_PLAY_AUDIO_REQ***\n");
            break;
        case MSG_ID_MMI_EQ_PLAY_AUDIO_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_EQ_PLAY_AUDIO_RSP***\n");
            break;
        case MSG_ID_MMI_EQ_STOP_AUDIO_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_EQ_STOP_AUDIO_REQ***\n");
            break;
        case MSG_ID_MMI_EQ_STOP_AUDIO_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_EQ_STOP_AUDIO_RSP***\n");
            break;
        case MSG_ID_MMI_SS_PARSING_STRING_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_SS_PARSING_STRING_REQ***\n");
            break;
        case MSG_ID_MMI_SS_PARSING_STRING_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_SS_PARSING_STRING_RSP***\n");
            break;
        case MSG_ID_MMI_CC_INTERNAL_ALERT_IND:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_INTERNAL_ALERT_IND***\n");
            break;
        case MSG_ID_MMI_CC_NOTIFY_SS_IND:
            PRINT_INFORMATION("*** MSG_ID_MMI_CC_NOTIFY_SS_IND***\n");
            break;
        case MSG_ID_MMI_CC_CALL_DEFLECT_REQ:
            PRINT_INFORMATION("*** MSG_ID_MMI_SS_CALL_DEFLECT_REQ***\n");
            break;
        case MSG_ID_MMI_CC_CALL_DEFLECT_RSP:
            PRINT_INFORMATION("*** MSG_ID_MMI_SS_CALL_DEFLECT_RSP***\n");
            break;
        default:
            /* custom_print ("*** Non CC Message ***\n"); */
            break;
    }
#endif /* MMI_ON_HARDWARE_P */ 
}
#endif /* __MMI_UCM__ */
