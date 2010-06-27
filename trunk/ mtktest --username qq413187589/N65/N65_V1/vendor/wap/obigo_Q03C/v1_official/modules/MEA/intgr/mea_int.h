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

/*! \file mea_int.h
 *  Adapter functions for the MEA.
 */

#ifndef _MEA_INT_H_
#define _MEA_INT_H_

/******************************************************************************
 * Prototypes
 *****************************************************************************/

/*!
 * \brief Launches the Phone-book application.
 * 
 * This call launches the phone book application. When the phone book later
 * is closed the answer is provided through a call to MEAc_pbLaunchRsp. The 
 * possible result address type from the response is PLMN or EMAIL.
 *
 * \param id An identity that is provided in the response function.
 *****************************************************************************/
void MEAa_pbLaunch(MSF_UINT16 id);

/*! \brief Cancels all ongoing operations with the phone book
 *
 * This adaptor function is called if the phone book needs to be closed, for 
 * example, if the MEA receives a stop signal when the phone book has been
 * launched from the MEA.
 *
 *****************************************************************************/
void MEAa_pbCancel(void);

/*!
 * \brief Lookup of names or addresses in the phone book.
 *
 * This function is used in order to find the name for a specific address.
 * The response is provided through a call to MEAc_pbLookupNameRsp().
 *
 * It should be possible to make multiple calls to this functions before
 * a response has been received.
 *
 * \param instanceId An identity that is provided in the response.
 * \param type The type of address to lookup; email or phone number.
 * \param value The address to lookup.
 *****************************************************************************/
void MEAa_pbLookupName(MSF_UINT16 instanceId, MSF_UINT8 type, void *value);
#ifdef __MMI_MMS_BGSR_SUPPORT__
void MEAa_sendMessageReq(void *p);
void MEAa_cancelSendMessageReq(void *p);
void MEAa_downloadMessageReq(void *p);
void MEAa_cancelDownloadMessageReq(void *p);
void MEAa_getMessageInfo(void *p);
void MEAa_chagneMessageReq(void *p);
void mmi_mms_send_rsp_callback(U32 msg_id, U8 result, U16 *text);
void mmi_mms_cancel_send_rsp_callback(U32 msg_id, U8 result);
void mmi_mms_download_rsp_callback(U32 msg_id, U8 result, U16 *text);
void mmi_mms_cancel_download_rsp_callback(U32 msg_id, U8 result);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

#endif


