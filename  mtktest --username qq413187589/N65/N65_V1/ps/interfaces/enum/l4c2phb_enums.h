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
 *	l4c2phb_enums.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for NVRAM.
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _L4C2PHB_ENUMS_H
#define _L4C2PHB_ENUMS_H

typedef enum {
   PHB_ERRNO_FAIL,
   PHB_ERRNO_SUCCESS,
   PHB_ERRNO_NOT_SUPPORT,
   PHB_ERRNO_READ_FAIL,
   PHB_ERRNO_READ_SUCCESS,
   PHB_ERRNO_READ_EMPTY,
   PHB_ERRNO_NOT_READY,
   PHB_ERRNO_BUSY,
   PHB_ERRNO_ANR_FULL,
   PHB_ERRNO_EMAIL_FULL,
   PHB_ERRNO_SNE_FULL
} phb_errno_enum;

typedef enum {
   PHB_NONE,
   PHB_ECC,
   PHB_FDN,
   PHB_BDN,
   PHB_MSISDN,
   PHB_SDN,
   PHB_PHONEBOOK,
   PHB_GAS,
   PHB_GRP,
   PHB_ANR,
   PHB_ANRA, /* only use for ext type */
   PHB_ANRB, /* only use for ext type */
   PHB_ANRC, /* only use for ext type */
   PHB_SNE,
   PHB_EMAIL,
   PHB_IAP
} phb_type_enum;

typedef enum {
   PHB_LND,
   PHB_LNM,
   PHB_LNR,
   PHB_LN_NONE
} phb_ln_type_enum;

typedef enum {
   PHB_LN_CALL,
   PHB_LN_VOIP,
   PHB_LN_VIDEO
} phb_ln_addr_type_enum;

typedef enum {
   PHB_BYNAME,
   PHB_BYNAME_EXACT,
   PHB_BYNUMBER
} phb_query_method_enum;

typedef enum {
   PHB_BCD = 0x01,
   PHB_ASCII = 0x00,
   PHB_UCS2 = 0x08
#ifdef __PHB_0x81_SUPPORT__	/*MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2*/
   ,
   PHB_UCS2_81 = 0x09,
   PHB_UCS2_82 = 0x10
#endif
} phb_charset_enum;

typedef enum {
   PHB_STORAGE_NONE,
   PHB_SIM,
   PHB_NVRAM
} phb_storage_enum;


typedef enum {
   PHB_NO_CAUSE,
   PHB_CAUSE_STORAGE_FULL,          /* This value is returned when just added entry causes storage full */
   PHB_CAUSE_CAPACITY_EXCEEDED      /* Since storage is full, attempt of adding an entry returns this value */
} phb_cause_enum;

#endif

