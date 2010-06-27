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

#ifndef _MEA_IF_H
#define _MEA_IF_H

#ifdef __UNIFIED_MSG_SUPPORT__
/*! Convert from memory buffer to signal structs */
void * mea_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer);

/*! Released a signal structure to a signal */
void mea_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);


void MEAif_createMessage(MSF_UINT8 sender);
void MEAif_readMessage(MSF_UINT8 sender, MSF_UINT32 folder, MSF_UINT16 msgIndex);
void MEAif_enterTemplate(MSF_UINT8 sender);
void MEAif_enterSetting(MSF_UINT8 sender);
void MEAif_getMessageNumber(MSF_UINT8 sender);
void MEAif_getMessageList(MSF_UINT8 sender, MSF_UINT32 folder, MSF_UINT16 start);
void MEAif_getMessageInfo(MSF_UINT8 sender, MSF_UINT32 folder, MSF_UINT16 start, MSF_UINT16 max);
void MEAif_deleteFolder(MSF_UINT8 sender, MSF_UINT32 folder);
void MEAif_sendMessage(MSF_UINT8 sender, MSF_UINT32 msgId);
void MEAif_replyMessage(MSF_UINT8 sender, MSF_UINT32 msgId);
void MEAif_replyMessageAll(MSF_UINT8 sender, MSF_UINT32 msgId);
void MEAif_forwardMessage(MSF_UINT8 sender, MSF_UINT32 msgId);
void MEAif_editMessage(MSF_UINT8 sender, MSF_UINT32 msgId);
void MEAif_deleteMessage(MSF_UINT8 sender, MSF_UINT32 msgId);
void MEAif_useNumber(MSF_UINT8 sender, MSF_UINT32 msgId);

typedef struct 
{
   MSF_UINT32 folder; /*!< Folder identification */
   MSF_UINT16 msgIndex;
} MeaReadMsgSig;

typedef struct 
{
   MSF_UINT32 folder; /*!< Folder identification */
   MSF_UINT16 start;
} MeaFolderListSig;

typedef struct 
{
   MSF_UINT32  folder; /*!< Folder identification */
   MSF_UINT16 start;
   MSF_UINT16 max;
} MeaFolderInfoSig;

/*--- Signals sent to MEA ---*/
#define MEA_SIG_CREATE_MSG	((MSF_MODID_MEA << 8) + 0x01) 
#define MEA_SIG_READ_MSG	((MSF_MODID_MEA << 8) + 0x02)
#define MEA_SIG_ENTER_TEMPLATE	((MSF_MODID_MEA << 8) + 0x03)
#define MEA_SIG_ENTER_SETTING	((MSF_MODID_MEA << 8) + 0x04)

#define MEA_SIG_GET_MSG_NUM	((MSF_MODID_MEA << 8) + 0x05) 
#define MEA_SIG_GET_MSG_LIST	((MSF_MODID_MEA << 8) + 0x06)
#define MEA_SIG_GET_MSG_INFO	((MSF_MODID_MEA << 8) + 0x07) 
#define MEA_SIG_DELETE_FOLDER	((MSF_MODID_MEA << 8) + 0x08) 

#define MEA_SIG_SEND    ((MSF_MODID_MEA << 8) + 0x09)
#define MEA_SIG_REPLY    ((MSF_MODID_MEA << 8) + 0x0A)
#define MEA_SIG_REPLY_ALL    ((MSF_MODID_MEA << 8) + 0x0B)
#define MEA_SIG_FORWARD    ((MSF_MODID_MEA << 8) + 0x0C)
#define MEA_SIG_EDIT    ((MSF_MODID_MEA << 8) + 0x0D)
#define MEA_SIG_DELETE    ((MSF_MODID_MEA << 8) + 0x0E)
#define MEA_SIG_USE_NUMBER    ((MSF_MODID_MEA << 8) + 0xF)
#define MEA_SIG_MOVE_TO_ARCHIVE    ((MSF_MODID_MEA << 8) + 0x10)
#endif
#endif
