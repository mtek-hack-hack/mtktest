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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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

#ifndef _SASBP_H_
#define _SASBP_H_

#ifndef _SAASYNC_H
#error saasync.h must be included berfore sasbp.h!
#endif


/******************************************************************************
 * Constants
 *****************************************************************************/

/* Signal destinations.*/
typedef enum
{
    /*! Received when the async read operation is complete
     *  - Param I : -  
     *  - Param U1: -
     *  - Param U2: -
     *  - Param P : File name
     */
    SMA_SIG_SBP_READ_RSP,

    /*! Response from the "DRM get header" operation
     *  - Param I : -  
     *  - Param U1: The result of the operation
     *  - Param U2: Total number of bytes read.
     *  - Param P : The DRM header, see #SmaDreResultItem,
     */
    SMA_SIG_SBP_DRM_HEAD_RSP,

    /*! Response from the "DRM get object" is handled here
     *  - Param I : -  
     *  - Param U1: -
     *  - Param U2: -
     *  - Param P : File name
     */
    SMA_SIG_SBP_DRM_BODY_RSP,
    
    /*! Received when the "save body part"-operation is complete
     *  - Param I : 
     *  - Param U1: Result of the operation, see smaResult
     *  - Param U2: Data length in bytes
     *  - Param P : The extracted data
     */
    SMA_SIG_SBP_COMPLETE

}SmaSbpSignalId;

/* Error codes */
typedef enum
{
    SMA_SBP_RESULT_OK,
    SMA_SBP_RESULT_TERMINATE
}SmaSbpResult;

/******************************************************************************
 * Data-types
 *****************************************************************************/


/******************************************************************************
 * Function prototypes
 *****************************************************************************/

void smaSbpInit(void);
void smaSbpTerminate(void);
void saveBodyPart(const char *fileName, const char *mimeType, 
    const char *sourceFilePath, MSF_UINT32 startPos, 
    MSF_UINT32 dataSize, MSF_UINT32 callingFsm, int returnSig, 
    const char *boundary);
SmaResult convertAsio2SmaRes( SmaAsioResult asioRes);

#endif /* _SASBP_H_ */


