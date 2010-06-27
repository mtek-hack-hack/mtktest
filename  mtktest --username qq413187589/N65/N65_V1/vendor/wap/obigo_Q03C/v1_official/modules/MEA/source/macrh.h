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

/*!\file macrh.h
 * \brief Content routing handler.
 */

#ifndef _MACRH_H_
#define _MACRH_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! \enum MeaCrhSignalId
 *  Signal destinations.*/
typedef enum
{
    /*!
     * Entry point signal, 
     * P: Information about the body-part to read, see #MeaCrhBodyPart.
     */
    MEA_SIG_CRH_START,

    /*! Pipe notification arrived.
     * U1: handle
     * I:  eventType 
     */
    MEA_SIG_CRH_NOTIFY,

    /*! Read a chunk from the body-part
     *
     */
    MEA_SIG_CRH_READ_BODYPART,

    /*! A delayed file operation is ready to be retried again
     *
     */
    MEA_SIG_CRH_FILE_NOTIFY,

    /*! Cancel the current content routing.
     * 
     */
    MEA_SIG_CRH_CANCEL,
    
    /*! Handles response from the content router
     * u_param1 = TRUE if content data can be handles, otherwise FALSE.
     */
    MEA_SIG_CRH_SEND_RSP
}MeaCrhSignalId;

/* !The identity used when sending a content routing request 
 */
#define MEA_CRH_SEND_ID                     0x01

/*! \enum MeaCrhResult
 *  Error codes */
typedef enum
{
    MEA_CRH_VIEW_ATTACH_ERROR, /* !< Failed use the content routing */
    MEA_CRH_VIEW_ATTACH_NO_HANDLER, /* !< No content handler available */
    MEA_CRH_VIEW_ATTACH_OK     /* !< The body part was successfully sent */
}MeaCrhResult;

/******************************************************************************
 * Data-types
 *****************************************************************************/
/*! \struct MeaCrhBodyPart
 *  Data type used for a content routing request */
typedef struct
{
    char            *contentType; /* !< The content-type of the body-part, do 
                                        not free this data*/
    char            *contentHeaders; /* !< The content headers (HTTP) of the 
                                           body part to send*/
    char            *fileName;    /* !< The file-name, do not free this data*/
    MSF_UINT32      index;        /* !< The index of the body-part */
    MSF_UINT32      totalSize;    /* !< The size of the body-part to read */
    MSF_UINT32      readPos;      /* !< The current position position in the 
                                        body-part*/
    MmsMsgId        mmsMsgId;     /* !< The id of the current message*/
    MmsFileType     fileType;     /* !< Message type */

    int             fsm;          /* !< The FSM to send response to */
    int             signal;       /* !< The response signal */
}MeaCrhBodyPart;

/******************************************************************************
 * Function prototypes
 *****************************************************************************/

void meaCrhInit(void);
void meaCrhTerminate(void);

#endif


