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

/*!\file maph.h
 * \brief Packet handling.
 */

#ifndef _MAPH_H_
#define _MAPH_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

typedef enum
{
    /* The result from a package operation
     *
     * p_param = The result
     */
    MEA_SIG_PH_READ_RESULT
}MeaPhSignal;

typedef enum
{
    MEA_AFI_READ_RESULT_OK,         /*!< The operation was successful */
    MEA_AFI_READ_RESULT_FAILED,     /*!< The operation failed */
    MEA_AFI_READ_RESULT_FAILED_LARGE_RESOLUTION,
    MEA_AFI_READ_RESULT_FAILED_FS_FULL,
    MEA_AFI_READ_RESULT_FAILED_NO_RESOURCE,
    MEA_AFI_READ_RESULT_FAILED_CORRUPT,
    MEA_AFI_READ_RESULT_TO_LARGE,   /*!< The file was larger than the largest file requested */
    MEA_AFI_READ_RESULT_INT_TERM    /*!< Only used internally */
}MeaAfiReadResult;

typedef MeaInsertResult (*MeaInsertObjCallBack)(const char *);

/******************************************************************************
 * Data-types
 *****************************************************************************/
typedef struct
{
    void        *data;
    MSF_UINT32  size;
    char        *fileName;
    char        *mimeType;
    void        *callbackData;

#ifdef __DRM_SUPPORT__
    char        *drmMimeType;
#endif
#ifdef MMS_SLIM_MEM
    MSF_UINT32 resHandle;    /* the resource has been created in handleReadOp(); we use it in editor */
#endif
}MeaAfiReadResultData;

/******************************************************************************
 * Prototypes 
 *****************************************************************************/

MSF_BOOL meaPhInit(void);
void meaPhTerminate(void);
MSF_BOOL meaPhHandleSignal(MSF_UINT16, void *p);

#ifdef WAP_SUPPORT //use MTK_FMGR
MSF_BOOL meaOpenDlgCreateMediaInput(MeaStateMachine fsm, int signal, 
    const char *mimeTypes, MeaInsertObjCallBack callback);
void meaOpenDlgMediaInputAbort(void);
#else
MSF_BOOL meaOpenDlgCreateMediaInput(MeaStateMachine fsm, int signal, 
    const char *mimeTypes);
void *meaOpenDlgMediaInputAbort(void);
#endif /* WAP_SUPPORT */

#ifdef MMS_SLIM_MEM
MSF_BOOL isForMeaAfiLoadFromFile(MSF_UINT32 handle, MsfNotificationType notificationType);
void meaAfiReleaseHandle(MeaAfiReadResultData *data);
#endif

MSF_BOOL meaAfiLoadFromFile(MeaStateMachine fsm, int signal, 
    char *fileName, void *callbackData, MSF_UINT32 maxSize);
void *meaAfiLoadFromFileAbort(void);
MSF_UINT32 meaAfiGetFileSize(char *fileName);

void meaAfiLoadFreeData(MeaAfiReadResultData *data);

MSF_UINT32 meaCreateSaveAs(MeaStateMachine fsm, int signal, 
    char *mimeTypes, const char *fileName, char *data, long dataLen);


#endif

