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
 *	asn-bool.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _asn_bool_h_
#define _asn_bool_h_

#include "kal_non_specific_general_types.h"
#include "act-ttbuffmgr.h"

/* typedef unsigned char AsnBool; */
typedef kal_uint8 AsnBool;

/* do nothing  while alloc'ing */
#define AsnBool_alloc( v)

#define AsnBool_dealloc( v)

void AsnBool_print (AsnBool *b, PrintBuffMgr *pbm, unsigned short int indent);

#ifdef BER

/* 
 * 1 byte to store the data (TRUE/FALSE),
 * 1 byte to store the length required for data (1 byte)
 * 1 byte for tag ==> 24 bits
 */
#define ber_AsnBool_bits(v)     24

/* captures only the number of bits to store the content */
#define ber_AsnBoolContent_bits(v)  8

AsnLen ber_AsnBool_pack(unsigned char *b, AsnBool *data, AsnLen bits);

AsnLen ber_AsnBool_unpack(AsnBool *result, unsigned char *b, AsnLen bits, AsnLen encodedLen, void *err);

AsnLen ber_AsnBoolContent_pack(BUF_TYPE b, AsnBool *data);

void ber_AsnBoolContent_unpack (BUF_TYPE b, AsnTag tag, AsnLen len, AsnBool *result, AsnLen *bytesDecoded, ENV_TYPE env);

#endif

#ifdef UPER

#define uper_AsnBool_pack(b, data, bits)  uper_BufPutBits(b, bits, 1, *data ? TRUE : FALSE);

/*AsnLen uper_AsnBool_unpack(AsnBool *result, BUF_TYPE b, AsnLen bits, AsnLen encodedLen); */

#define uper_AsnBool_unpack(result, b, bits, enc, d)  \
    ((*result = (unsigned char)uper_BufGetBits(b, bits, 1)), 1);


    /* <manu> 04-12-01 additions for new _BITS functions */
#define uper_AsnBool_BITS(b, data, bits) 1
    /* <manu> 04-12-01 end of additions for new _BITS functions */


#endif


#endif


