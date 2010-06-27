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

#ifndef _SMA_IF_H
#define _SMA_IF_H

#include "sma_def.h"

/**********************************************************************
 * External Signals
 **********************************************************************/

/*! Return Signal sent from the SMA Module */
#define SMA_SIG_PLAY_SMIL_RSP   ((MSF_MODID_SMA << 8) + 0x02)

#ifdef __UNIFIED_COMPOSER_SUPPORT__
/* SMA starts to control the screen */
#define SMA_SIG_PLAY_SMIL_IND   ((MSF_MODID_SMA << 8) + 0x03)
#endif

/**********************************************************************
 * Signal parameter definitions:
 **********************************************************************/


/*! \struct SmaPlaySmilReq Used for the signal SMA_SIG_PLAY_SMIL_REQ */
typedef struct
{
    MSF_UINT32 msgId;
    MSF_UINT32 fileType;
} SmaPlaySmilReq;

/*! \struct SmaPlaySmilRsp Used for the signal SMA_SIG_PLAY_SMIL_RSP */
typedef struct
{
    SmaResult result;
} SmaPlaySmilRsp;



/*! Starts SMA if not previously started. */
void SMAif_startInterface (void);

/**********************************************************************
 * Signal-sending API
 * These functions should be used by any other module that wants to
 * send a signal to the SMA module.
 **********************************************************************/

/*!
 * \brief Signal sent from client to SMA-Module, plays a SMIL in a MMS message
 * 
 * \param sender Sender module
 * \param msgId ID of a MMS message containing a SMIL
 * \param fileType The type of the message to handle: 
 *                 MMS_SUFFIX_SEND_REQ or MMS_SUFFIX_MSG.
 * \return Result of the operation.
 *****************************************************************************/
SmaResult SMAif_playSmil(MSF_UINT8 sender, MSF_UINT32 msgId,
    MSF_UINT32 fileType);
/**********************************************************************
 * Conversion routines for all signal owned by this module.
 * None of these functions should be called directly by another module.
 **********************************************************************/

/*! Convert from memory buffer to signal structs */
void *sma_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer);

/*! Released a signal structure to a signal */
void sma_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);

/*!
 * \brief  Converts a parameters into a signal buffer for SmaPlaySmilReq 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 *****************************************************************************/
int sma_cvt_SmaPlaySmilReq( msf_dcvt_t *obj, SmaPlaySmilReq *data);

/*!
 * \brief  Converts a parameters into a signal buffer for SmaPlaySmilReq 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 *****************************************************************************/
int sma_cvt_SmaPlaySmilRsp( msf_dcvt_t *obj, SmaPlaySmilRsp *data);

/*
 * Exported function call to check if certain attachment exists by specifying its filename
 *
 * \param filename filename of attachment
 *****************************************************************************/
char *SMAlib_getAttachment(char *filename);
#endif


