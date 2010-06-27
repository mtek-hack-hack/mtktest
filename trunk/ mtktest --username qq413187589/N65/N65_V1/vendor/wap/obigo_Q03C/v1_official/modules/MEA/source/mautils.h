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

/* !\file mautils.h
 *  \brief Utility functions for MEA.
 */

#ifndef _MAUTILS_H_
#define _MAUTILS_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! The maximum length of a date string */
#define MEA_DATESTRING_LENGTH       29

/*! Swaps the values of to integers */
#define MEA_SWAP(i, j)              (i ^= j, j ^= i, i ^= j)

/*! \struct MeaMediaObjects
 *  
 */
typedef struct
{
    const MeaMediaType      mediaType;      /*!< The media type, see 
                                                 #MeaMediaType */
    const MeaMediaGroupType objectType;     /*!< The type of object see 
                                                 #MeaMediaGroupType */
    const char              *mimeType;      /*!< Mime type */
    const MmsKnownMediaType assignedValue;  /*!< The assigned IANA value */
    const SlsMediaType      slsMediaType;   /*!< The media types as defined by 
                                                 SLS  */
    const MSF_UINT32        msfType;        /*!< MsfImageFormat or MsfSoundFormat */
    const char              *fileExtension; /*!< The file extension of the 
                                                 media type  */
}MeaMediaObjects;


typedef struct 
{
    const char          *mimeType;      /*!< The mime-type */
    const char          *ending;        /*!< The file ending */
}MeaExtAttachmentType;
/******************************************************************************
 * Prototypes 
 *****************************************************************************/

char *meaCreateFileName(const char *extension);
char *meaCreateFileNameFromType(MeaMediaType mediaType);
char *meaCreateFileNameFromMime(const char *mime);
void meaCopyContentType(MmsContentType *toContent, 
                            const MmsContentType *fromContent);
void meaFreePropItem(MeaPropItem *prop, MSF_BOOL dynamicOnly);
MSF_UINT32 meaIsValidCharset(MmsCharset charset);
MSF_BOOL meaConvertToUTF8(int charset, MSF_UINT32 *size, unsigned char **text);
MSF_UINT32 meaConvertMediaTypeToMsf(MeaMediaType mediaType);
MeaMediaType meaConvertMsfTypeToMediaType(MSF_UINT32 msfType);
MeaMediaGroupType meaMediaType2ObjType(MeaMediaType mediaType);
MeaMediaType meaMime2MediaType(const char *mime);
char *meaMediaType2Mime(MeaMediaType mediaType);
SlsMediaType meaConvertMediaTypeToSls(MeaMediaType mediaType);
MSF_BOOL meaMediaTypeMeaToMms(const MeaMediaType mediaType, 
    MmsKnownMediaType *outType, char **outStr);
MeaMediaType meaSlsMediaTypeToMea(SlsMediaType slsMediaType);
void meaRemPathFromFileName(char *fileName);
void meaFreeMmsContentType(MmsContentType *contentType);
void meaFreeMmsContentTypeParams(MmsAllParams *params);
void meaRemoveMmsParam(MmsAllParams **params, MmsParam paramToRemove);
MeaMediaType meaMmsKnownValueToMea(MmsKnownMediaType mmsMediaType);

char *meaKnownValueToMimeType(MmsKnownMediaType knownType);
#ifdef WAP_SUPPORT
MeaFolder mmsFolder2MeaFolder(MmsFolderType folder);
MmsFolderType meaFolder2MmsFolder(MeaFolder folder);

const char *meaFileName2MimeType(const char *filename);
MmsKnownMediaType meaMime2MmsMediaType(const char *mime);
MSF_BOOL meaCheckCharacterIsAllEnglish(const char *str);
void meaExtractFileName(char *fName);
void meaTransformIllegalFileName(char *name);
SlsUnrefItemList *meaCopySlsUnrefList(SlsUnrefItemList *sourceList);
void meaFreeUnrefList(SlsUnrefItemList **list);
#ifdef JPG_ENCODE
MSF_BOOL meaIsResizedFile(char *name);
void meaCleanupResizedFiles(void);
#endif
MSF_BOOL meaRenameExtensionFromType(MSF_UINT8 modId, char **name, MeaMediaType type);
MSF_BOOL meaRenameExtensionFromMime(MSF_UINT8 modId, char **name, const char *mime);
char *meaCreateMsgPropText(MmsMsgId msgId);
char *meaCreateNotifPropText(MmsMsgId msgId);
#endif

SlsGetSlideInfoRsp *meaCopySlsSlideInfo(const SlsGetSlideInfoRsp *info);
void meaFreeSlsSlideInfo(SlsGetSlideInfoRsp *info);

MSF_UINT32 meaCreateVirtualFileResource(MeaMediaType mType, const char *filename, int offset, int size);
#ifdef __DRM_SUPPORT__
MSF_UINT32 meaCreateDrmVirtualFileResource(MeaMediaType mType, const char *filename, int offset, int size, 
    MmsMsgId msgId, MSF_INT32 fileHandle, MeaMediaType *drmType);
MeaMediaType meaDrm2MediaType(char * fileName);
MSF_UINT8 meaDrmGetMethod(const char *filepath);
#endif
MSF_BOOL meaIsSupportedMimeType(const char *mime);
MSF_BOOL meaIsRestrictedType(const char *filename);
MSF_BOOL meaIsRestrictedTypeVF(const char *filename, MeaMediaType type, MSF_UINT32 offset, MSF_UINT32 size);
void meaRemoveAttachment(MeaMoDataItem **list);

#endif

