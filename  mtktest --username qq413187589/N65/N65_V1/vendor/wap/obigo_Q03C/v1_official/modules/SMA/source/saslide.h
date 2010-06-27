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

#ifndef _SASLIDE_H
#define _SASLIDE_H

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/* Signal destinations.*/
typedef enum
{
    /*! Response from read operation
     *  - Param I : - 
     *  - Param U1: Result of the operation 
     *  - Param U2: Bytes read
     *  - Param P : -
     */        
    SMA_SIG_SLIDE_READ_RSP,

#ifndef __DRM_SUPPORT__
	/*! Response from get DRM header operation
     *  - Param I : - 
     *  - Param U1: Result of the operation 
     *  - Param U2: Bytes read
     *  - Param P : The DRM header.
     */        
    SMA_SIG_SLIDE_DRE_MSG_RSP,

	/*! Response from get DRM object operation
     *  - Param I : - 
     *  - Param U1: Result of the operation 
     *  - Param U2: Buffer size if buffer is used.
     *  - Param P : NULL or the decoded data if buffer is used.
     */        
    SMA_SIG_SLIDE_DRE_OBJ_RSP,
#endif /* __DRM_SUPPORT__ */

    /*! Handling of the boundary part
     *  - Param I : - 
     *  - Param U1: Result of the operation 
     *  - Param U2: Buffer size if buffer is used.
     */
    SMA_SIG_READ_BOUNDARY_RSP,

    /*! Handling of the boundary part
     *  - Param I : - 
     *  - Param U1: - 
     *  - Param U2: -
     */
    SMA_SIG_GADGET_GOT_FOCUS,

    /*! Handling of the boundary part
     *  - Param I : - 
     *  - Param U1: - 
     *  - Param U2: -
     */
    SMA_SIG_GADGET_LOST_FOCUS,

#ifdef WAP_SUPPORT
    SMA_SIG_EVENT_KEY_RIGHT,
    SMA_SIG_EVENT_KEY_LEFT,
#endif /* WAP_SUPPORT */
#ifdef __MMI_TOUCH_SCREEN__
    SMA_SIG_EVENT_SCROLL,
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
    SMA_SIG_GET_TOTAL_TEXT_HEIGHT,
    SMA_SIG_GET_TOTAL_TEXT_HEIGHT_CONTINUE,
    SMA_SIG_GET_TOTAL_TEXT_HEIGHT_FINISHED,
#endif

    /*! Handling of the boundary part
     *  - Param I : - 
     *  - Param U1: - 
     *  - Param U2: -
     */
    SMA_SIG_EVENT_KEY_DOWN,

    /*! Handling of the boundary part
     *  - Param I : - 
     *  - Param U1: - 
     *  - Param U2: -
     */
    SMA_SIG_EVENT_KEY_UP,

    /*! Load the next object
     *  - Param I : result of the last operation
     *  - Param U1: - 
     *  - Param U2: -
     */
    SMA_SIG_LOAD_NEXT_OBJECT
}SmaSlideSignalId;

/*********************************************
 * Exported function
 *********************************************/

void smaSlideInit(void);
void smaSlideTerminate(void);
void generateSlide( MSF_UINT8 number, SmaPlayerInfo *playerInfo, 
    MSF_UINT32 callingFsm, int returnSig);

#endif /* _SASLIDE_H */


