/*
 * Copyright (C) Obigo AB, 2002-2005.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */





#ifndef _MMSREC_H
#define _MMSREC_H




















#ifdef MTK_TMP_PATCH /*TR 19175*/
void recContentRouting(const msf_content_data_t* pContentData);
#else
void recContentRouting(msf_content_data_t* pContentData);
#endif

















void recCreateMessage(MmsFileType fileType);













void recCreateMessageDone(MmsMsgId msgId, MmsFolderType folder);











void recDeleteMessage(MmsMsgId msgId);















#ifdef MTK_TMP_PATCH /*TR 19175*/
void recForwardReq(const unsigned char *pdu, MSF_UINT32 length);
#else
void recForwardReq(unsigned char *pdu, MSF_UINT32 length);
#endif













void recGetBodyPart( MmsMsgId msgId, MSF_UINT32 number);











void recGetNumberOfMessages(MmsFolderType folder);












void recGetMessageIdList(MmsFolderType folder, MSF_UINT32 startPos, 
    MSF_UINT32 maxIds);










void recGetMessageInfo(MSF_UINT8 source, MSF_UINT32 msgId);














void recMoveMessage(MmsMsgId msgId, MmsFolderType toFolder);











#ifdef __MMS_DUAL_SIM_SUPPORT__
void recPush( MmsSimCardEnum simId, MSF_BOOL isSmsBearer, unsigned long size, void *pdu);
#else
void recPush( MSF_BOOL isSmsBearer, unsigned long size, void *pdu);
#endif







void recRegResponse(msf_registry_response_t* p);












void recRetrieveCancel(MmsMsgId notifId);











void recRetrieveMessage(MmsMsgId notifId);














void recSendCancel(MmsMsgId msgId);











void recSendMessage(MmsMsgId msgId);














void recSendReadReport(MmsMsgId msgId, MmsReadStatus readStatus);











void recTerminate(void);










void recSetReadMark(MmsMsgId msgId, MSF_UINT8 value); 









void recGetReport(MmsMsgId msgId);









void getFolderStatus(MSF_UINT8 source, MSF_UINT32 folderMask);

#endif  


