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

#include "msf_lib.h"
#include "msf_core.h"
#include "msf_int.h"
#include "msf_log.h"
#include "msf_mem.h"


/* MEA */
#include "mea_def.h"
#include "mea_if.h"

#ifdef __UNIFIED_MSG_SUPPORT__
void MEAif_createMessage(MSF_UINT8 sender)
{
    void *sig = NULL;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_4DE50AF32925141CE4F5725516504FB8, "MEAif_createMessage(%d)\n", sender));    
    sig = MSF_SIGNAL_CREATE (MEA_SIG_CREATE_MSG, sender, MSF_MODID_MEA, 0);
    if (sig != NULL) 
    {
        MSF_SIGNAL_SEND (sig);
    }
}

void MEAif_readMessage(MSF_UINT8 sender, MSF_UINT32 folder, MSF_UINT16 msgIndex)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;
    MeaReadMsgSig data;

    data.folder = folder;
    data.msgIndex = msgIndex;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_81D782BCE15F36AEC14998CC6094A4FD, "MEAif_readMessage(%d, %d, %d)\n", sender, folder, msgIndex));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&data.folder) ||
    	!msf_dcvt_uint16(&cvt, (MSF_UINT16 *)&data.msgIndex))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_READ_MSG, sender, MSF_MODID_MEA, length);

    if(sig != NULL)
    {
        sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
        msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
        if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&data.folder) ||
        	!msf_dcvt_uint16(&cvt, (MSF_UINT16 *)&data.msgIndex))
        {
            return;
        }
    
        MSF_SIGNAL_SEND (sig);
    }
}

void MEAif_enterTemplate(MSF_UINT8 sender)
{
    void *sig = NULL;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_542B8531F3C003D682407877DC6D2894, "MEAif_enterTemplate(%d)\n", sender));
    sig = MSF_SIGNAL_CREATE (MEA_SIG_ENTER_TEMPLATE, sender, MSF_MODID_MEA, 0);
    if (sig != NULL) 
    {
        MSF_SIGNAL_SEND (sig);
    }
}

void MEAif_enterSetting(MSF_UINT8 sender)
{
    void *sig = NULL;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_25E6C09B7B054DD1C1F7C80BB1ABBFEA, "MEAif_enterSetting(%d)\n", sender));
    sig = MSF_SIGNAL_CREATE (MEA_SIG_ENTER_SETTING, sender, MSF_MODID_MEA, 0);
    if (sig != NULL) 
    {
        MSF_SIGNAL_SEND (sig);
    }
}

void MEAif_getMessageNumber(MSF_UINT8 sender)
{
    void *sig = NULL;
    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_CEEB1D5553B86DEDB4BB67FC966DC8F5, "MEAif_getMessageNumber(%d)\n", sender));
    sig = MSF_SIGNAL_CREATE (MEA_SIG_GET_MSG_NUM, sender, MSF_MODID_MEA, 0);
    if (sig != NULL) 
    {
        MSF_SIGNAL_SEND (sig);
    }
}

void MEAif_getMessageList(MSF_UINT8 sender, MSF_UINT32 folder, MSF_UINT16 start)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;
    MeaFolderListSig data;

    data.folder = folder;
    data.start = start;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_3F6E45F7932075AD285411297D6BE6BA, "MEAif_getMessageList(%d, %d, %d)\n", sender, folder, start));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&data.folder) ||
    	!msf_dcvt_uint16(&cvt, (MSF_UINT16 *)&data.start))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_GET_MSG_LIST, sender, MSF_MODID_MEA, length);

    if(sig != NULL)
    {
        sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
        msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
        if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&data.folder) ||
        	!msf_dcvt_uint16(&cvt, (MSF_UINT16 *)&data.start))
        {
            return;
        }
    
        MSF_SIGNAL_SEND (sig);
    }
}

void MEAif_getMessageInfo(MSF_UINT8 sender, MSF_UINT32 folder, MSF_UINT16 start, MSF_UINT16 max)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;
    MeaFolderInfoSig data;

   data.folder = folder;
   data.start = start;
   data.max = max;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_6D7EFC8089F42C9C730217B0A1B2AD5D, "MEAif_getMessageInfo(%d, %d, %d, %d)\n", sender, folder, start, max));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&data.folder) ||
    	!msf_dcvt_uint16(&cvt, (MSF_UINT16 *)&data.start) ||
    	!msf_dcvt_uint16(&cvt, (MSF_UINT16 *)&data.max))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_GET_MSG_INFO, sender, MSF_MODID_MEA, length);

    if(sig != NULL)
    {
        sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
        msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
        if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&data.folder) ||
        	!msf_dcvt_uint16(&cvt, (MSF_UINT16 *)&data.start) ||
        	!msf_dcvt_uint16(&cvt, (MSF_UINT16 *)&data.max))
        {
            return;
        }
    
        MSF_SIGNAL_SEND (sig);
    }
}

void MEAif_deleteFolder(MSF_UINT8 sender, MSF_UINT32 folder)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_4892B4B1D2CD5FA38654B20E01F4E9E2, "MEAif_deleteFolder(%d, %d)\n", sender, folder));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&folder))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_DELETE_FOLDER, sender, MSF_MODID_MEA, length);

    if(sig != NULL)
    {
        sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
        msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
        if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&folder))
        {
            return;
        }
    
        MSF_SIGNAL_SEND (sig);
    }
}

/*! \brief send the message
 *  \param msgId To-be-sent msg id
 *****************************************************************************/
void MEAif_sendMessage(MSF_UINT8 sender, MSF_UINT32 msgId)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_626CD38DAC56701B8E74B447096BE3BC, "MEAif_sendMessage(%d, %d)\n", sender, msgId));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_SEND, sender, MSF_MODID_MEA, length);
    sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    MSF_SIGNAL_SEND (sig);
}

/*! \brief reply sender of the message
 *  \param msgId To-be-replied msg id
 *****************************************************************************/
void MEAif_replyMessage(MSF_UINT8 sender, MSF_UINT32 msgId)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_CC0BB4698AC19F8BC4CDBF0B0EF7AB27, "MEAif_replyMessage(%d, %d)\n", sender, msgId));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_REPLY, sender, MSF_MODID_MEA, length);
    sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    MSF_SIGNAL_SEND (sig);
}

/*! \brief reply all recipient and sender of the message
 *  \param msgId To-be-replied msg id
 *****************************************************************************/
void MEAif_replyMessageAll(MSF_UINT8 sender, MSF_UINT32 msgId)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_78E2B15017EC8F53DBC7869441D27FD3, "MEAif_replyMessageAll(%d, %d)\n", sender, msgId));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_REPLY_ALL, sender, MSF_MODID_MEA, length);
    sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    MSF_SIGNAL_SEND (sig);
}

/*! \brief Forward message
 *  \param msgId To-be-forwarded msg id
 *****************************************************************************/
void MEAif_forwardMessage(MSF_UINT8 sender, MSF_UINT32 msgId)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_137D77B19CE3C6150D3E07E0F2448967, "MEAif_forwardMessage(%d, %d)\n", sender, msgId));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_FORWARD, sender, MSF_MODID_MEA, length);
    sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    MSF_SIGNAL_SEND (sig);
}

/*! \brief Edit message
 *  \param msgId To-be-edited msg id
 *****************************************************************************/
void MEAif_editMessage(MSF_UINT8 sender, MSF_UINT32 msgId)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_9D0B35CE1277AD469552439F709B46BE, "MEAif_editMessage(%d, %d)\n", sender, msgId));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_EDIT, sender, MSF_MODID_MEA, length);
    sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    MSF_SIGNAL_SEND (sig);
}

/*! \brief Delete message
 *  \param msgId To-be-deleted msg id
 *****************************************************************************/
//void sendDeleteReq(MSF_UINT32 msgId)
void MEAif_deleteMessage(MSF_UINT8 sender, MSF_UINT32 msgId)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_CC0BAC5A5DD880C7E757F1EB550915F9, "MEAif_deleteMessage(%d, %d)\n", sender, msgId));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_DELETE, sender, MSF_MODID_MEA, length);
    sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    MSF_SIGNAL_SEND (sig);
}

/*! \brief Use number existed in the message
 *  \param msgId msg id
 *****************************************************************************/
void MEAif_useNumber(MSF_UINT8 sender, MSF_UINT32 msgId)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, MEA_IF_72F37C1FFC844D729169B4631082472B, "MEAif_useNumber(%d, %d)\n", sender, msgId));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_USE_NUMBER, sender, MSF_MODID_MEA, length);
    sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    MSF_SIGNAL_SEND (sig);
}

/*
 * Converts a parameters into a signal buffer for MeaReadMsgSig
 *
 * Please note: Doxygen dokumentation, see file description in header file.
 *****************************************************************************/
int mea_cvt_MeaReadMsgSig(msf_dcvt_t *obj, MeaReadMsgSig *data)
{
    MSF_UINT32 folder;
    MSF_UINT16 msgIndex;

    if (NULL == data)
    {
        return FALSE;
    }
    folder = (MSF_UINT32)data->folder;
    msgIndex = (MSF_UINT16)data->msgIndex;
    
    if (!msf_dcvt_uint32(obj, &folder) || !msf_dcvt_uint16(obj, &msgIndex))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MEA_IF_7C6C5CB5C722371433C7222564DCC4B1, "%s(%d): Conversion failed.\n", __FILE__, __LINE__));
        return FALSE;
    }

    data->folder = folder;
    data->msgIndex = msgIndex;
    return TRUE; 
}

/*
 * Converts a parameters into a signal buffer for MeaFolderListSig
 *
 * Please note: Doxygen dokumentation, see file description in header file.
 *****************************************************************************/
int mea_cvt_MeaFolderListSig(msf_dcvt_t *obj, MeaFolderListSig *data)
{
    MSF_UINT32 folder;
    MSF_UINT16 start;

    if (NULL == data)
    {
        return FALSE;
    }
    folder = (MSF_UINT32)data->folder;
    start = (MSF_UINT16)data->start;
    
    if (!msf_dcvt_uint32(obj, &folder) || !msf_dcvt_uint16(obj, &start))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MEA_IF_7C6C5CB5C722371433C7222564DCC4B1, "%s(%d): Conversion failed.\n", __FILE__, __LINE__));
        return FALSE;
    }

    data->folder = folder;
    data->start = start;
    return TRUE; 
}

/*
 * Converts a parameters into a signal buffer for MeaFolderListSig
 *
 * Please note: Doxygen dokumentation, see file description in header file.
 *****************************************************************************/
int mea_cvt_MeaFolderInfoSig(msf_dcvt_t *obj, MeaFolderInfoSig *data)
{
    MSF_UINT32 folder;
    MSF_UINT16 start;
    MSF_UINT16 max;

    if (NULL == data)
    {
        return FALSE;
    }
    folder = (MSF_UINT32)data->folder;
    start = (MSF_UINT16)data->start;
    max = (MSF_UINT16)data->max;
    
    if (!msf_dcvt_uint32(obj, &folder) || !msf_dcvt_uint16(obj, &start) || !msf_dcvt_uint16(obj, &max))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MEA_IF_7C6C5CB5C722371433C7222564DCC4B1, "%s(%d): Conversion failed.\n", __FILE__, __LINE__));
        return FALSE;
    }

    data->folder = folder;
    data->start = start;
    data->max = max;
    return TRUE; 
}

/*
 * Converts a parameters into a signal buffer for message ID
 *
 * Please note: Doxygen dokumentation, see file description in header file.
 *****************************************************************************/
int mea_cvt_MeaMsgId(msf_dcvt_t *obj, MSF_UINT32 *data)
{
    MSF_UINT32 msgId;
    
    if (NULL == data)
    {
        return FALSE;
    }
    msgId = *data; 
    
    if (!msf_dcvt_uint32(obj, &msgId))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, MEA_IF_7C6C5CB5C722371433C7222564DCC4B1, "%s(%d): Conversion failed.\n", __FILE__, __LINE__));
        return FALSE;
    }
    
    *data = msgId;
    return TRUE; 
}

/*!
 * \brief Convert signals owned by the MEA module.
 *        Conversion is from signal buffer to signal structs.
 * 
 * \param module Module id of the module using the convert function
 * \param signal Signal to convert
 * \param buffer Buffer to convert
 * \return <whatever is returned>
 *****************************************************************************/
void *mea_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer)
{
    msf_dcvt_t  cvt_obj;
    void       *user_data;
    MSF_UINT16  length;
    
    if ( buffer == NULL)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
        MEA_IF_202A1B7D992A7D20315840535A569029, "%s(%d) mea_convert: Invalid parameter\n", __FILE__, __LINE__));
        return NULL;
    }
    
    user_data = MSF_SIGNAL_GET_USER_DATA (buffer, &length);
    if ((user_data == NULL) || (length == 0))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
        MEA_IF_5265205D73ADF577846EC0B2E0118A36, "%s(%d) mea_convert: No data received.", __FILE__, __LINE__));
        return NULL;
    }
        
    msf_dcvt_init (&cvt_obj, MSF_DCVT_DECODE, user_data, length, module);
    
    switch (signal)
    {
    case MEA_SIG_READ_MSG:
    {
        MeaReadMsgSig *data = MSF_MEM_ALLOCTYPE (module, MeaReadMsgSig);
        if (data == NULL)
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MEA_IF_C292A255B7CA0A77F0C1E70FBA5A6CE7, "%s(%d) mea_convert: Unable to allocate memory.", __FILE__, __LINE__));
        }
        else 
        {
            memset(data, 0x00, sizeof(MeaReadMsgSig));
 
            if (!mea_cvt_MeaReadMsgSig(&cvt_obj, data))
            {
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
                MEA_IF_ECC889CCA76B946845D5C925193E80BD, "%s(%d) mea_convert: Unable convert data.", __FILE__, __LINE__));
                MSF_MEM_FREE(module, data);
                data = NULL;
            }
        }
        return data;
    }

    case MEA_SIG_GET_MSG_LIST:
    {
        MeaFolderListSig *data = MSF_MEM_ALLOCTYPE (module, MeaFolderListSig);
        if (data == NULL)
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MEA_IF_C292A255B7CA0A77F0C1E70FBA5A6CE7, "%s(%d) mea_convert: Unable to allocate memory.", __FILE__, __LINE__));
        }
        else 
        {
            memset(data, 0x00, sizeof(MeaFolderListSig));
 
            if (!mea_cvt_MeaFolderListSig(&cvt_obj, data))
            {
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
                MEA_IF_ECC889CCA76B946845D5C925193E80BD, "%s(%d) mea_convert: Unable convert data.", __FILE__, __LINE__));
                MSF_MEM_FREE(module, data);
                data = NULL;
            }
        }
        return data;
    }

    case MEA_SIG_GET_MSG_INFO:
    {
        MeaFolderInfoSig *data = MSF_MEM_ALLOCTYPE (module, MeaFolderInfoSig);
        if (data == NULL)
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MEA_IF_C292A255B7CA0A77F0C1E70FBA5A6CE7, "%s(%d) mea_convert: Unable to allocate memory.", __FILE__, __LINE__));
        }
        else 
        {
            memset(data, 0x00, sizeof(MeaFolderInfoSig));
 
            if (!mea_cvt_MeaFolderInfoSig(&cvt_obj, data))
            {
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
                MEA_IF_ECC889CCA76B946845D5C925193E80BD, "%s(%d) mea_convert: Unable convert data.", __FILE__, __LINE__));
                MSF_MEM_FREE(module, data);
                data = NULL;
            }
        }
        return data;
    }
    	
    case MEA_SIG_DELETE_FOLDER:
    case MEA_SIG_SEND:
    case MEA_SIG_REPLY:
    case MEA_SIG_REPLY_ALL:
    case MEA_SIG_FORWARD:
    case MEA_SIG_EDIT:
    case MEA_SIG_DELETE:
    case MEA_SIG_USE_NUMBER:
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    case MEA_SIG_MOVE_TO_ARCHIVE:
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    {
        MSF_UINT32 *data = MSF_MEM_ALLOCTYPE (module, MSF_UINT32);
        if (data == NULL)
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MEA_IF_C292A255B7CA0A77F0C1E70FBA5A6CE7, "%s(%d) mea_convert: Unable to allocate memory.", __FILE__, __LINE__));
        }
        else 
        {	
            *data = 0;

            if(!mea_cvt_MeaMsgId(&cvt_obj, data))
            {
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
                MEA_IF_ECC889CCA76B946845D5C925193E80BD, "%s(%d) mea_convert: Unable convert data.", __FILE__, __LINE__));
                MSF_MEM_FREE(module, data);
                data = NULL;
            }
        }
        return data;
    }
    	
    default:
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
                MEA_IF_F84BE80305524C0A5C19387563D6996F, "%s(%d) mea_convert: Received unknown signal.", __FILE__, __LINE__));
            return NULL;
        }
    }
}

/*!
 * \brief Deallocate signal buffer
 * 
 * \param module The calling module identity
 * \param signal Signal identity
 * \param p The signal buffer
 *****************************************************************************/
void mea_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p)
{
    msf_dcvt_t cvt_obj;

    if (p == NULL)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
        MEA_IF_7E9E1A78F8AF32DEAA6205A8217B116F, "%s(%d) mea_destruct: no signal data \n", __FILE__, __LINE__));
        return;
    }
    
    msf_dcvt_init (&cvt_obj, MSF_DCVT_FREE, NULL, 0, module);
    switch (signal)
    {
    case MEA_SIG_READ_MSG:
    {
        if ( !mea_cvt_MeaReadMsgSig( &cvt_obj, p))
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MEA_IF_63FCA33608887EDFDDA17314EE8BB3CE, "%s(%d) mea_destruct: Unable convert.", __FILE__, __LINE__));
        }
        break;
    }
    case MEA_SIG_GET_MSG_LIST:
    {
        if (!mea_cvt_MeaFolderListSig( &cvt_obj, p))
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MEA_IF_63FCA33608887EDFDDA17314EE8BB3CE, "%s(%d) mea_destruct: Unable convert.", __FILE__, __LINE__));
        }
        break;
    }
    case MEA_SIG_GET_MSG_INFO:
    {
        if (!mea_cvt_MeaFolderInfoSig( &cvt_obj, p))
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MEA_IF_63FCA33608887EDFDDA17314EE8BB3CE, "%s(%d) mea_destruct: Unable convert.", __FILE__, __LINE__));
        }
        break;
    }
    case MEA_SIG_DELETE_FOLDER:
    case MEA_SIG_SEND:
    case MEA_SIG_REPLY:
    case MEA_SIG_REPLY_ALL:
    case MEA_SIG_FORWARD:
    case MEA_SIG_EDIT:
    case MEA_SIG_DELETE:
    case MEA_SIG_USE_NUMBER:
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    case MEA_SIG_MOVE_TO_ARCHIVE:
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    {
        if (!mea_cvt_MeaMsgId( &cvt_obj, p))
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MEA_IF_63FCA33608887EDFDDA17314EE8BB3CE, "%s(%d) mea_destruct: Unable convert.", __FILE__, __LINE__));
        }
        break;
    }
    default:
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
                MEA_IF_54E42C56DD40A3E383CD6E5816ACF2A5, "%s(%d) mea_destruct: Received unknown signal.", __FILE__, __LINE__));
            return;
        }
    } /* switch */
  MSF_MEM_FREE (module, p);
} /* sma_destruct */
#endif
