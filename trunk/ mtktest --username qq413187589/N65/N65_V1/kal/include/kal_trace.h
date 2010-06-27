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
 *   kal_trace.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides typedefs and definiton for PS index trace.
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _KAL_TRACE_H
#define _KAL_TRACE_H

#include "stdarg.h"

#define MAX_MSG_NBR_IN_MODULE       20
#define ADDITIONAL_BUFFER_FOR_MUX   45
#define DEFAULT_RS232_FRAME_SIZE    5                 /* STX, LenHi, LenLo, Type, Checksum*/
#define SAP_LOCAL_PARA_FILTER       0x02
#define SAP_PEER_BUFF_FILTER        0x04


#define STX_OCTET                   0x55
#define LOGGED_PRIMITIVE_TYPE       0x60
#define PS_TRACE_INDEX_TRACE_TYPE   0x61
#define PS_PROMPT_TRACE_TYPE        0x62
#define CONTROL_COMMAND_TYPE        0x63
#define INJECT_PRIMITIVE_TYPE       0x64
#define SYS_TRACE_TYPE              0x65



#ifdef GEN_FOR_PC
#ifndef GEN_FOR_CPARSER
   #define BEGIN_TRACE_MAP(MOD)     START_MODULE_MSG MOD MAX_MSG_NBR_IN_MODULE
   #define TRC_MSG(MSG,STR)         MSG STR
   #define END_TRACE_MAP(MOD)       END_MODULE_MSG
#else
   #define BEGIN_TRACE_MAP(MOD)     enum MOD##_MSG_ENUM{\
                                       MOD##_empty_string=MOD<<MAX_MSG_NBR_IN_MODULE,
   #define TRC_MSG(MSG,STR)         MSG##__enum,
   #define  END_TRACE_MAP(MOD)      MOD##__end};
#endif
#else /* GEN_FOR_PC */
   #define BEGIN_TRACE_MAP(MOD)     enum MOD##_MSG_ENUM{\
                                       MOD##_empty_string=MOD<<MAX_MSG_NBR_IN_MODULE,
   #define TRC_MSG(MSG,STR)         MSG##__enum,
   #define  END_TRACE_MAP(MOD)      MOD##__end};
#endif /* GEN_FOR_PC */




typedef enum
{
   TRACE_FUNC,
   TRACE_STATE,
   TRACE_INFO,
   TRACE_WARNING,
   TRACE_ERROR,
   TRACE_GROUP_1,
   TRACE_GROUP_2,
   TRACE_GROUP_3,
   TRACE_GROUP_4,
   TRACE_GROUP_5,
   TRACE_GROUP_6,
   TRACE_GROUP_7,
   TRACE_GROUP_8,
   TRACE_GROUP_9,
   TRACE_GROUP_10,
   TRACE_PEER
}trace_class_enum;


#if !defined(GEN_FOR_PC) 
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
   #include "..\..\tst\database_classb\pstrace_db\ps_trace.h"
#endif /* TST Trace Defintion */
#endif


#ifdef __TST_MODULE__

#ifdef DEBUG_KAL

extern void kal_trace( trace_class_enum, kal_uint32, const kal_char* , ...);
extern void kal_trace_for_3rd_party( trace_class_enum, kal_uint32, const kal_char* , va_list);
extern void kal_lib_trace( trace_class_enum, kal_uint32, const kal_char* , ...);
extern void kal_assert_trace( trace_class_enum, kal_uint32, const kal_char* , ...);
extern void kal_wap_trace(module_type mod_id, trace_class_enum trc_class, const char *fmt,...);
extern void kal_buffer_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* fmt, kal_uint32 buf_len, const kal_uint8* pData);
extern void kal_dev_trace(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type,...);

#elif defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR) || defined(MCD_DLL_EXPORT) || defined(L1_SIM)  /* DEBUG_KAL */

/*
 * For non-target platform (PC simulator or MNT),
 * we define trace-related functions as inline function to avoid compile error
 * in VC++.
 */

__inline void kal_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* arg_type, ...)
{
    return ;
}

__inline void kal_trace_for_3rd_party(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* arg_type, va_list argument_info)
{
    return ;
}

__inline void kal_lib_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* arg_type, ...)
{
    return ;
}
__inline void kal_assert_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* arg_type, ...)
{
    return ;
}
__inline void kal_wap_trace(module_type mod_id, trace_class_enum trc_class, const char *fmt,...)
{
    return ;
}

__inline void kal_buffer_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* fmt, kal_uint32 buf_len, const kal_uint8* pData)
{
    return;
}

__inline void kal_dev_trace(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type,...)
{
    return;
}
#else   /* DEBUG_KAL  */

#define kal_trace(...)
#define kal_trace_for_3rd_party(...)
#define kal_lib_trace(...)
#define kal_assert_trace(...)
#define kal_wap_trace(...)
#define kal_buffer_trace(...)
#define kal_dev_trace(...)

#endif   /* DEBUG_KAL */

extern void kal_prompt_trace(module_type, const kal_char *fmt,...);

#else   /* __TST_MODULE__ */

#if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR) || defined(MCD_DLL_EXPORT) || defined(L1_SIM)

__inline void kal_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* arg_type, ...)
{
    return ;
}

__inline void kal_trace_for_3rd_party(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* arg_type, va_list argument_info)
{
    return ;
}

__inline void kal_lib_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* arg_type, ...)
{
    return ;
}
__inline void kal_assert_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* arg_type, ...)
{
    return ;
}
__inline void kal_wap_trace(module_type mod_id, trace_class_enum trc_class, const char *fmt,...)
{
    return ;
}
__inline void kal_prompt_trace(module_type mod_id, const kal_char *fmt,...)
{
    return ;
}

__inline void kal_buffer_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* fmt, kal_uint32 buf_len, const kal_uint8* pData)
{
    return;
}

__inline void kal_dev_trace(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type,...)
{
    return;
}

#else   /* MTK_KAL_MNT ||  KAL_ON_OSCAR */

#define kal_trace(...)
#define kal_trace_for_3rd_party(...)
#define kal_lib_trace(...)
#define kal_assert_trace(...)
#define kal_wap_trace(...)
#define kal_prompt_trace(...)
#define kal_buffer_trace(...)
#define kal_dev_trace(...)

#endif  /* MTK_KAL_MNT ||  KAL_ON_OSCAR */

#endif /* __TST_MODULE__ */


typedef void (*TST_VC_CallBack)(const kal_uint8* pData, kal_uint32 nLen);

/*
* tst_virtual_channel_id:
* regiester new virtual channel here and remake tst
*/
typedef enum
{
	TVCI_GPS_LOGGING,
	TVCI_LAST_ID
}
tst_virtual_channel_id;

#endif /* _KAL_TRACE_H */


