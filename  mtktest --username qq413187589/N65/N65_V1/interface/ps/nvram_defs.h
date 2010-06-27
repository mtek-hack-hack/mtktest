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
 * nvram_defs.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file contains definitions used by NVRAM task.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_DEFS_H
#define NVRAM_DEFS_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included"
#endif 

#ifndef NVRAM_AUTO_GEN
#include "nvram_lid_statistics.h"
#endif 

#define NVRAM_COMMENT 0

/**
 * If `lock' field of system record is NVRAM_LOCK_PATTERN_LOCKED, 
 * the global software lock status is LOCKED. (Its default value is assigned through
 * coded_version_lock in ltable.c)
 * Otherwise, the global software lock status is UNLOCKED.
 */
#define NVRAM_LOCK_PATTERN_LOCKED         "_NVRAM__YES_"
#define NVRAM_LOCK_PATTERN_UNLOCKED       " _NVRAM__NO_"

    /* File/Path length */
#define FILE_PREFIX_LEN 4
#define FILE_VERNO_LEN  3
#define NVRAM_FILE_LEN (FILE_PREFIX_LEN + 1 + FILE_VERNO_LEN)
#define NVRAM_MAX_DESC_LEN 20

#define NVRAM_MAKE_LID_FILENAME(buf, prefix, M, verno) {\
   ((kal_char*) (buf))[0] = ((kal_char*) (prefix))[0];  \
   ((kal_char*) (buf))[1] = ((kal_char*) (prefix))[1];  \
   ((kal_char*) (buf))[2] = ((kal_char*) (prefix))[2];  \
   ((kal_char*) (buf))[3] = ((kal_char*) (prefix))[3];  \
   ((kal_char*) (buf))[4] = (kal_char) (M);             \
   ((kal_char*) (buf))[5] = ((kal_char*) (verno))[0];   \
   ((kal_char*) (buf))[6] = ((kal_char*) (verno))[1];   \
   ((kal_char*) (buf))[7] = ((kal_char*) (verno))[2];   \
   ((kal_char*) (buf))[8] = '\0';                       \
};

#define NVRAM_MAKE_LID_FILENAME_PREFIX(buf, prefix) { \
   ((kal_char*) (buf))[0] = ((kal_char*) (prefix))[0];\
   ((kal_char*) (buf))[1] = ((kal_char*) (prefix))[1];\
   ((kal_char*) (buf))[2] = ((kal_char*) (prefix))[2];\
   ((kal_char*) (buf))[3] = ((kal_char*) (prefix))[3];\
   ((kal_char*) (buf))[4] = '\0';                     \
};

#define NVRAM_RESERVED_VALUE
#define NVRAM_INVALID_VALUE      ~0
#define NVRAM_EF_ZERO_DEFAULT_VALUE  0x00

#if defined(__MA_L1__) || defined(__WCDMA_RAT__)
/* under construction !*/
#else 
#define MAX_NVRAM_RECORD_SIZE 2048
#endif 

#ifndef NVRAM_AUTO_GEN
#define NVRAM_EXTERN(X) X
#else 
#define NVRAM_EXTERN(X) NVRAM_EF_ZERO_DEFAULT
#define NVRAM_MAX_SHADOW_REC 4
#endif 

#define nvram_get_data_item(ldi,LID)    \
{                                       \
    kal_uint8 lid = LID;                \
    ldi = nvram_ptr->ltable.table[lid]; \
}

#define NVRAM_IS_LID_VALID(x)   (x < NVRAM_TOTAL_LID && nvram_ptr->ltable.table[x])

    typedef kal_char NVRAM_FILE_NAME[9];

    /* Attributes of a Logical Data Item, predefined. */
    typedef kal_uint16 nvram_attr_enum;
#define NVRAM_ATTR_AVERAGE          0x0000
#define NVRAM_ATTR_IMPORTANT        0x0001
#define NVRAM_ATTR_WRITEPROTECT     0x0002
#define NVRAM_ATTR_MULTIPLE         0x0004
#define NVRAM_ATTR_CONFIDENTIAL     0x0008
#define NVRAM_ATTR_MULTIREC_READ    0x0010
#define NVRAM_ATTR_OTP              0x0020
#define NVRAM_ATTR_MSP              0x0040 /*__MTK_SECURE_PLATFORM__*/
#define NVRAM_ATTR_DIFFERENCE       0x0080
#define NVRAM_ATTR_RING             0x0100

#define NVRAM_IS_ATTR_AVERAGE(x)        (x & NVRAM_ATTR_AVERAGE)
#define NVRAM_IS_ATTR_IMPORTANT(x)      (x & NVRAM_ATTR_IMPORTANT)
#define NVRAM_IS_ATTR_WRITEPROTECT(x)   (x & NVRAM_ATTR_WRITEPROTECT)
#define NVRAM_IS_ATTR_MULTIPLE(x)       (x & NVRAM_ATTR_MULTIPLE)
#define NVRAM_IS_ATTR_CONFIDENTIAL(x)   (x & NVRAM_ATTR_CONFIDENTIAL)
#define NVRAM_TURNOFF_ATTR_MULTIPLE(x)  (x &= ~(NVRAM_ATTR_MULTIPLE))

/**
 * Category of a Logical Data Item could belong to, predefined. 
 * Must be synchronous with nvram_reset_category_enum.
 */
typedef kal_uint32 nvram_category_enum;
#define NVRAM_CATEGORY_USER             0x0000
#define NVRAM_CATEGORY_SYSTEM           0x0001
#define NVRAM_CATEGORY_BRANCH           0x0002
#define NVRAM_CATEGORY_FACTORY          0x0004
#define NVRAM_CATEGORY_MULTI_DEFAULT    0x0008
#define NVRAM_CATEGORY_SHADOW           0x0010
#define NVRAM_CATEGORY_SHADOW_MS        0x0020
#define NVRAM_CATEGORY_CUSTPACK         0x0040
#define NVRAM_CATEGORY_SECUPACK         0x0080
#define NVRAM_CATEGORY_COMPOSED         0x8000

typedef kal_uint16 nvram_lid_enum;
typedef struct
{
    nvram_lid_enum LID;             /* Logical Data Item ID */
    kal_uint16 size;                /* Size of one record. < sizeof(control buffer) */
    kal_uint16 total_records;       /* Number of records */
    kal_uint8 const *default_value; /* Hardcoded default */
    nvram_attr_enum attr;           /* U16 */
    nvram_category_enum category;   /* U32 */
    kal_char fileprefix[FILE_PREFIX_LEN + 1];
    kal_char fileverno[FILE_VERNO_LEN + 1];
    kal_char *description;
    kal_uint8 record_ID;            /* Reserved */
} ltable_entry_struct;

#if (defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__NVRAM_IN_USB_MS__)) && defined(__MTK_TARGET__)
#if defined(__MULTI_BOOT__) || defined(__L1_STANDALONE__)
#define __SHADOW_NVRAM__
#else 
#error "Shadow NVRAM only supported when __MULTI_BOOT__ exists"
#endif 

#if defined(_LOW_COST_SINGLE_BANK_FLASH_)
#define __SHADOW_SUPPORT_SB__   /* for Single Bank */
#else 
#define __SHADOW_SUPPORT_MS__   /* for Shadow Alarm */
#endif 
/**
 * Shadow lookup table
 */

typedef struct
{
   nvram_lid_enum	LID;             		            /* Logical Data Item ID */
	kal_uint8	*offset;					            /* start address in Shadow buffer*/
	kal_uint32	dirty_records[NVRAM_MAX_SHADOW_REC];    /* dirty bit map of Shadow records*/
}shadow_ltable_struct;

#define GUARD_PATTERN_SIZE 2

#endif /* defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__NVRAM_IN_USB_MS__) */ 

#ifdef __SECURITY_OTP__
typedef struct
{
    kal_uint8	LID;             		/* Logical Data Item ID */
    kal_uint32	offset;					/* start address in Shadow buffer*/
}nvram_otp_table_sturct;

extern kal_uint16 otp_item_total;
extern kal_uint16 otp_item_total;
extern nvram_otp_table_sturct nvram_otp_ltable[];
#endif/* __SECURITY_OTP__ */

extern const kal_uint8 NVRAM_EF_ZERO_DEFAULT[];
extern const kal_uint8 NVRAM_EF_FF_DEFAULT[];
extern const kal_uint8 *NVRAM_EF_CUSTPACK_DEFAULT[];

extern ltable_entry_struct *logical_data_item_table[];

extern ltable_entry_struct logical_data_item_table_core[];
extern ltable_entry_struct logical_data_item_table_comm_app[];
extern ltable_entry_struct logical_data_item_table_cust[];

extern const kal_uint8 NVRAM_TOTAL_LID;
extern kal_uint8 coded_version_lock[];

extern const kal_uint8 NVRAM_LAST_COMMAPP_LID;

#ifdef __cplusplus
}
#endif 

#endif /* NVRAM_DEFS_H */ 

