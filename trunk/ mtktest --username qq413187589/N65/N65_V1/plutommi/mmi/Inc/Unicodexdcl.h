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
 *  Unicodexdcl.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/************************************************************** 
 FILENAME   : Unicodexdcl.h 
 PURPOSE : Gives the current build settings. 
 REMARKS : Manish 
 AUTHOR     : Pixtel Engineers 
 DATE    : . 
 **************************************************************/

#ifndef _UNICODEXDCL_H_
#define _UNICODEXDCL_H_

#include "MMIDataType.h"
#include "FrameworkBackwardCompatible.h"

/* the application include this header to get related API */

extern U8 mmi_wc_to_ucs2(U16 unicode, U8 *charLength, U8 *arrOut);
extern U8 mmi_ucs2_to_wc(PU16 pUnicode, PU8 arrOut);
extern S32 mmi_ucs2strlen(const S8 *arrOut);
extern S32 mmi_ucs2cmp(const S8 *string1, const S8 *string2);
extern S8 *mmi_ucs2cpy(S8 *strDestination, const S8 *strSource);

extern S32 mmi_ucs2ncmp(const S8 *string1, const S8 *string2, U32 count);
extern S8 *mmi_ucs2ncpy(S8 *strDestination, const S8 *strSource, U32 size);
extern S8 *mmi_ucs2cat(S8 *strDestination, const S8 *strSource);
extern S8 *mmi_ucs2ncat(S8 *strDestination, const S8 *strSource, U32 size);

extern S8 *mmi_ucs2trim_left(const S8 *strSrc, const S8 *TrimChars);
extern S32 mmi_ucs2find(const S8 *strSrc, const S8 *break_chars, S32 *read_length, S16 direction);
extern S32 mmi_ucs2toi(const S8 *strSrc, S32 *out_num, S32 *read_length);

extern U16 mmi_asc_to_ucs2(S8 *pOutBuffer, S8 *pInBuffer);
extern U16 mmi_asc_n_to_ucs2(S8 *pOutBuffer, S8 *pInBuffer, U32 len);
extern U16 mmi_asc_to_ucs2_ex(S8 *pOutBuffer, S8 *pInBuffer);
extern U16 mmi_asc_n_to_ucs2_ex(S8 *pOutBuffer, S8 *pInBuffer, U32 len);
extern U16 mmi_ucs2_to_asc(S8 *pOutBuffer, S8 *pInBuffer);
extern U16 mmi_ucs2_n_to_asc(S8 *pOutBuffer, S8 *pInBuffer, U32 len);

extern S8 *mmi_ucs2str(const S8 *str1, const S8 *str2);
extern S8 *mmi_ucs2chr(const S8 *string,  U16 ch);
extern S8 *mmi_ucs2rchr(const S8 * string, U16 ch);
extern S8 *mmi_ucs2upr(S8 *string);
extern S8 *mmi_ucs2lwr(S8 *string);
extern S32 mmi_ucs2icmp(const S8 *str_src, const S8 *str_dst);
extern S32 mmi_ucs2nicmp(const S8 *str_src, const S8 *str_dst, U32 count);

extern U16 mmi_asc_to_wcs(U16 *pOutBuffer, S8 *pInBuffer);
extern U16 mmi_asc_n_to_wcs(U16 *pOutBuffer, S8 *pInBuffer, U32 len);
extern U16 mmi_wcs_to_asc(S8 *pOutBuffer, U16 *pInBuffer);
extern U16 mmi_wcs_n_to_asc(S8 *pOutBuffer, U16 *pInBuffer, U32 len);
extern U16 mmi_asc_to_wcs_ex(U16 *dest, S8 *src, U32 *src_end_pos);
extern U16 mmi_asc_n_to_wcs_ex(U16 *dest, S8 *src, U32 len, U32 *src_end_pos);

extern S32 mmi_wcslen(const U16 *string);
extern S32 mmi_wcscmp(const U16 *str_src, const U16 *str_dst);
extern S32 mmi_wcsncmp(const U16 *str_src, const U16 *str_dst, U32 count);
extern U16 *mmi_wcscpy(U16 *str_dst, const U16 *str_src);
extern U16 *mmi_wcsncpy(U16 *str_dst, const U16 *str_src, U32 count);
extern U16 *mmi_wcscat(U16 *str_dst, const U16 *str_src);
extern U16 *mmi_wcsncat(U16 *str_dst, const U16 *str_src, U32 count);
extern U16 *mmi_wcsstr(U16 *string, const U16 *str_char_set);
extern U16 *mmi_wcschr(const U16 *string,  U16 ch);
extern U16 *mmi_wcsrchr(const U16 * string, U16 ch);
extern U16 *mmi_wcslwr(U16 *string);
extern U16 *mmi_wcsupr(U16 *string);
extern S32 mmi_wcsicmp(const U16 *str_src, const U16 *str_dst);
extern S32 mmi_wcsnicmp(const U16 *str_src, const U16 *str_dst, U32 count);


#endif /* _UNICODEXDCL_H_ */
