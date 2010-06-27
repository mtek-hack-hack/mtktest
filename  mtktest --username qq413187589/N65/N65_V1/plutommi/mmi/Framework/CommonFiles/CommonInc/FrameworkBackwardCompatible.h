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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  FrameworkBackwardCompatible.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Framework backward compatible items
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef FRAMEWORK_BACKWARD_COMPATIBLE_H
#define FRAMEWORK_BACKWARD_COMPATIBLE_H


/***************************************************************************** 
 * Include header file
 *****************************************************************************/
#include "MMI_features.h"
#include "EventsDef.h"
#include "FrameworkStruct.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#if (!defined(DEMO_PROJECT))
	#define MMI_FRM_BACKWARD_COMPATIBLE
#endif

#if (!defined(DEMO_PROJECT))
	#define MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
#endif

#if (!defined(DEMO_PROJECT)) || defined(__MMI_DICT_TRILOGY__)
	#define MMI_FRM_BACKWARD_COMPATIBLE_STRING
#endif

#define MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
#define MMI_FRM_BACKWARD_COMPATIBLE_STRING

/***************************************************************************** 
* Global Variable
*****************************************************************************/
#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
extern U16 maxInterruptEvent;
extern PsInteventInfo interruptEventHandler[MAX_INTERRUPT_EVENT];
#endif /* MMI_FRM_BACKWARD_COMPATIBLE_EVENTS */
/***************************************************************************** 
* Global Function
*****************************************************************************/
#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
extern void mmi_frm_set_interrupt_event_handler(PsIntFuncPtr func_ptr, PsIntFuncPtr post_func_ptr, U16 event_id);
extern void mmi_frm_set_group_interrupt_event_handler(PsIntFuncPtr func_ptr, PsIntFuncPtr post_func_ptr, PU16 events_id, U8 len);
extern void mmi_frm_clear_interrupt_event_handler_old(U16 event_id);
extern void mmi_frm_clear_all_interrupt_event_handler_old(void);
#define SetInterruptEventHandler    \
        mmi_frm_set_interrupt_event_handler
        
#define SetGroupInterruptEventHandler   \
        mmi_frm_set_group_interrupt_event_handler
        
#define ClearInterruptEventHandler  \
        mmi_frm_clear_interrupt_event_handler_old
        
#define ClearAllInterruptEventHandler   \
        mmi_frm_clear_all_interrupt_event_handler_old
#endif /* MMI_FRM_BACKWARD_COMPATIBLE_EVENTS */

#ifdef MMI_FRM_BACKWARD_COMPATIBLE_STRING
extern U8(*pfnUnicodeToEncodingScheme) (U16 Unicode, U8 *CharacterLength, U8 *CharBuffer);
extern U8(*pfnEncodingSchemeToUnicode) (PU16 pUnicode, PU8 arrOut);
extern S32(*pfnUnicodeStrlen) (const S8 *arrOut);
extern PS8(*pfnUnicodeStrcpy) (S8 *strDestination, const S8 *strSource);
extern PS8(*pfnUnicodeStrncpy) (S8 *strDestination, const S8 *strSource, U32 size);
extern S32(*pfnUnicodeStrcmp) (const S8 *string1, const S8 *string2);
extern S32(*pfnUnicodeStrncmp) (const S8 *string1, const S8 *string2, U32 size);
extern PS8(*pfnUnicodeStrcat) (S8 *strDestination, const S8 *strSource);
extern PS8(*pfnUnicodeStrncat) (S8 *strDestination, const S8 *strSource, U32 size);
/* For convert error */
#define mmi_asc_to_ucs2_Ex				mmi_asc_to_ucs2_ex
#define mmi_asc_n_to_ucs2_Ex			mmi_asc_n_to_ucs2_ex
extern U16 AnsiiToUnicodeString(S8 *pOutBuffer, S8 *pInBuffer);
extern U16 AnsiiNToUnicodeString(S8 *pOutBuffer, S8 *pInBuffer, U32 len);
extern U16 UnicodeToAnsii(S8 *pOutBuffer, S8 *pInBuffer);
extern U16 UnicodeNToAnsii(S8 *pOutBuffer, S8 *pInBuffer, U32 len);
extern U8 UnicodeToUCS2Encoding(U16 unicode, U8 *charLength, U8 *arrOut);
extern U8 UCS2EncodingToUnicode(PU16 pUnicode, PU8 arr);
extern S32 UCS2Strlen(const S8 *arrOut);
extern S32 UCS2Strcmp(const S8 *string1, const S8 *string2);
extern S8 *UCS2Strcpy(S8 *strDestination, const S8 *strSource);
extern S32 UCS2Strncmp(const S8 *string1, const S8 *string2, U32 size);
extern S8 *UCS2Strncpy(S8 *strDestination, const S8 *strSource, U32 size);
extern S8 *UCS2Strcat(S8 *strDestination, const S8 *strSource);
extern S8 *UCS2Strncat(S8 *strDestination, const S8 *strSource, U32 size);
extern S8 *UCS2Strstr(const S8 *str1, const S8 *str2);
extern S8 *UCS2Strchr(const S8 *strSrc, U16 c);
extern S8 *UCS2Strrchr(const S8 * string, U16 ch);
extern S8 *UCS2Strupr(S8 *string);
extern S8 *UCS2Strlwr(S8 *string);
extern S32 UCS2Stricmp(const S8 *str_src, const S8 *str_dst);
extern S32 UCS2Strnicmp(const S8 *str_src, const S8 *str_dst, U32 count);
extern S8 *UCS2StrTrimLeft(const S8 *strSrc, const S8 *TrimChars);
extern S32 UCS2StrGetStr(const S8 *strSrc, const S8 *break_chars, S32 *read_length, S16 direction);
extern S32 UCS2StrGetNumInt(const S8 *strSrc, S32 *out_num, S32 *read_length);
extern U16 AnsiiToUnicodeString_Ex(S8 *pOutBuffer, S8 *pInBuffer);
extern U16 AnsiiNToUnicodeString_Ex(S8 *pOutBuffer, S8 *pInBuffer, U32 len);
extern U16 AnsiiCharToUnicodeWideChar(U16 *pOutBuffer, S8 *pInBuffer);
extern U16 AnsiiCharToUnicodeWideCharEx(U16 *dest, S8 *src, U32 *src_end_pos);
extern U16 AnsiiCharNToUnicodeWideChar(U16 *pOutBuffer, S8 *pInBuffer, U32 len);
extern U16 AnsiiCharNToUnicodeWideCharEx(U16 *dest, S8 *src, U32 len, U32 *src_end_pos);
extern U16 UnicodeWideCharToAnsiiChar(S8 *pOutBuffer, U16 *pInBuffer);
extern U16 UnicodeWidecharNToAnsii(S8 *pOutBuffer, U16 *pInBuffer, U32 len);
extern S32 UCS2Wcslen(const U16 *string);
extern S32 UCS2Wcscmp(const U16 *str_src, const U16 *str_dst);
extern S32 UCS2Wcsncmp(const U16 *str_src, const U16 *str_dst, U32 count);
extern U16 *UCS2Wcscpy(U16 *str_dst, const U16 *str_src);
extern U16 *UCS2Wcsncpy(U16 *str_dst, const U16 *str_src, U32 count);
extern U16 *UCS2Wcscat(U16 *str_dst, const U16 *str_src);
extern U16 *UCS2Wcsncat(U16 *str_dst, const U16 *str_src, U32 count);
extern U16 *UCS2Wcsstr(U16 *string, const U16 *str_char_set);
extern U16 *UCS2Wcschr(const U16 *string,  U16 ch);
extern U16 *UCS2Wcsrchr(const U16 * string, U16 ch);
extern U16 *UCS2Wcslwr(U16 *string);
extern U16 *UCS2Wcsupr(U16 *string);
extern S32 UCS2Wcsicmp(const U16 *str_src, const U16 *str_dst);
extern S32 UCS2Wcsnicmp(const U16 *str_src, const U16 *str_dst, U32 count);

#endif /* MMI_FRM_BACKWARD_COMPATIBLE_STRING */

#endif /* FRAMEWORK_BACKWARD_COMPATIBLE_H*/ 


