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
 *   kal_non_specific_general_types.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides general types definations that are not specific
 *   to any os
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _KAL_NON_SPECIFIC_GENERAL_TYPES_H
#define _KAL_NON_SPECIFIC_GENERAL_TYPES_H

/*******************************************************************************
 * Type Definitions
 *******************************************************************************/
typedef unsigned char           kal_uint8;
typedef signed char             kal_int8;
typedef char                    kal_char;
typedef unsigned short          kal_wchar;

typedef unsigned short int      kal_uint16;
typedef signed short int        kal_int16;

typedef unsigned int            kal_uint32;
typedef signed int              kal_int32;

#if !defined(GEN_FOR_PC) && !defined(__MTK_TARGET__)
   //typedef ULONG64              kal_uint64;
   //typedef LONG64               kal_int64;
   typedef unsigned __int64      kal_uint64;
   typedef __int64               kal_int64;
#else
   typedef unsigned long long   kal_uint64;
   typedef signed long long     kal_int64;
#endif

#if !defined(__MTK_TARGET__)
   typedef int kal_jmpbuf[64];
#elif defined(__RVCT__)   
   typedef long long kal_jmpbuf[48];
#else
   typedef int kal_jmpbuf[32];
#endif

typedef enum 
{
  KAL_FALSE,
  KAL_TRUE
} kal_bool;

typedef void (*kal_func_ptr)(void);

/*******************************************************************************
 * Constant definition
 *******************************************************************************/
#ifndef NULL
#define NULL               0
#endif

#if defined(KAL_ON_NUCLEUS)

#define KAL_AND               NU_AND
#define KAL_CONSUME           NU_OR_CONSUME
#define KAL_AND_CONSUME       NU_AND_CONSUME
#define KAL_NO_SUSPEND        NU_NO_SUSPEND
#define KAL_OR                NU_OR
#define KAL_OR_CONSUME        NU_OR_CONSUME
#define KAL_SUSPEND           NU_SUSPEND

#elif defined (KAL_ON_OSCAR)    /* KAL_ON_NUCLEUS */

#define KAL_AND               OSC_ACTION_FULL_SET
#define KAL_CONSUME           OSC_ACTION_CLS
#define KAL_AND_CONSUME       OSC_ACTION_FULL_SET | OSC_ACTION_CLS
#define KAL_NO_SUSPEND        OSC_TIMEOUT_NONE
#define KAL_OR                OSC_ACTION_PART_SET
#define KAL_OR_CONSUME        OSC_ACTION_PART_SET | OSC_ACTION_CLS
#define KAL_SUSPEND           OSC_TIMEOUT_FOREVER

#elif defined(KAL_ON_THREADX)   /* KAL_ON_NUCLEUS */

#define KAL_AND               TX_AND
#define KAL_CONSUME           TX_OR_CLEAR
#define KAL_AND_CONSUME       TX_AND_CLEAR
#define KAL_NO_SUSPEND        TX_NO_WAIT
#define KAL_OR                TX_OR
#define KAL_OR_CONSUME        TX_OR_CLEAR
#define KAL_SUSPEND           TX_WAIT_FOREVER

#endif  /* KAL_ON_NUCLEUS */

#endif  /* _KAL_NON_SPECIFIC_GENERAL_TYPES_H */


