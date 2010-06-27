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
 * Filename:
 * ---------
 * NVRAMProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for NVRAM function prototype.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _NVRM_PROT_H
#define _NVRM_PROT_H

#include "MMIDataType.h"

/***************************************************************************** 
* Define
*****************************************************************************/

#define __NEW_NVRAMINTERFACE__

#if defined(__NEW_NVRAMINTERFACE__)
#define WriteRecord(nFileId,nRecordId,pBuffer,nBufferSize,pError)\
   AccessRecordInt(nFileId,nRecordId,pBuffer,nBufferSize, 1, pError,  MMI_TRUE, MMI_FALSE, __FILE__,__LINE__)

#define ReadRecord(nFileId,nRecordId,pBuffer,nBufferSize,pError)\
   AccessRecordInt(nFileId,nRecordId,pBuffer,nBufferSize, 1, pError, MMI_FALSE, MMI_FALSE, __FILE__,__LINE__)

#define ReadMultiRecord(nFileId,nRecordId,pBuffer,nBufferSize, nRecordAmount, pError)\
   AccessRecordInt(nFileId,nRecordId,pBuffer,nBufferSize, nRecordAmount, pError, MMI_FALSE, MMI_FALSE, __FILE__,__LINE__)

#else /* defined(__NEW_NVRAMINTERFACE__)  */ 
#define WriteRecord(nFileId,nRecordId,pBuffer,nBufferSize,pError)\
   WriteRecordInt(nFileId,nRecordId,pBuffer,nBufferSize,pError, __FILE__,__LINE__)

#define ReadRecord(nFileId,nRecordId,pBuffer,nBufferSize,pError)\
   ReadRecordInt(nFileId,nRecordId,pBuffer,nBufferSize,pError,__FILE__,__LINE__)
#endif /* defined(__NEW_NVRAMINTERFACE__)  */ 

#define ReadValue(nId,pBuffer,nDataType,pError)\
      ReadValueInt(nId,pBuffer,nDataType,pError,__FILE__,__LINE__)

#define WriteValue(nId,pBuffer,nDataType,pError)\
      WriteValueInt(nId,pBuffer,nDataType,pError,__FILE__,__LINE__)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

#if defined(__NEW_NVRAMINTERFACE__)
extern S32 AccessRecordInt(
            U16 nFileId,
            U16 nRecordId,
            void *pBuffer,
            U16 nBufferSize,
            U16 nRecordAmount,
            S16 *pError,
            pBOOL isWrite,
            pBOOL isValue,
            S8 *fileName,
            S32 lineNumber);
#if 0
/* under construction !*/
#endif /* 0 */ 

#else /* defined(__NEW_NVRAMINTERFACE__) */ 
extern S32 WriteRecordInt(
            U16 nFileId,
            U16 nRecordId,
            void *pBuffer,
            U16 nBufferSize,
            S16 *pError,
            S8 *fileName,
            S32 lineNumber);

extern S32 ReadRecordInt(
            U16 nFileId,
            U16 nRecordId,
            void *pBuffer,
            U16 nBufferSize,
            S16 *pError,
            S8 *filename,
            S32 lineNumber);
#endif /* defined(__NEW_NVRAMINTERFACE__) */ 

extern S32 ReadValueInt(U8 nId, void *pBuffer, U8 nDataType, S16 *pError, S8 *fileName, S32 lineNumber);

extern S32 WriteValueInt(U8 nId, void *pBuffer, U8 nDataType, S16 *pError, S8 *fileName, S32 lineNumber);

extern U8 SetFlashNVRAMCatchData(U8 nDataType, U8 l_DataWriteFlashFlag);
extern U8 SetFlashAllNVRAMCatchData(U8 l_DataWriteFlashFlag);
extern S32 WriteFlashNVRAMCatchData(U8 nDataType);
extern S32 WriteFlashAllNVRAMCatchData(void);

extern U8 IsInNVRAMProcedure(void);

#endif /* _NVRM_PROT_H */ 

