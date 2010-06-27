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
 *   kal_adm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This header file defines data structure for KAL application dynamic memory
 *   management.
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

#ifndef _KAL_ADM_H
#define _KAL_ADM_H

/*******************************************************************************
 * Constant definitions
 *******************************************************************************/

enum { ADM_INUSE = 0, ADM_FREE = 1, ADM_ID = 0x20040505, ADM_MB_LOG_STAMP = 0x03F3F3F3, \
		ADM_MB_FOOT_STAMP = 0x04F4F4F4, ADM_MAX_PRINT_LEN = 128 };

/*******************************************************************************
 * Data structure definitions
 *******************************************************************************/

/* ADM Control Block */
typedef struct
{
	kal_uint32 adm_id;   /* ID */
	kal_uint16 bl_num;   /* number of block lists */
#ifdef DEBUG_ADM
	kal_uint16 owner;    /* owner of ADM */
#else
	kal_uint16 reserved;
#endif
	kal_uint8 islogging;
	kal_uint8 reserved2[3];
} ADM_CB;

/* ADM Memory Block Mini Header */
typedef struct ADM_MB_MINI_HEAD_STRUCT
{
	struct ADM_MB_HEAD_STRUCT *prev;     /* previous MB */
	struct ADM_MB_HEAD_STRUCT *next;     /* next MB */
} ADM_MB_MINI_HEAD;

/* ADM Memory Block Header (for FREE memory block) */
typedef struct ADM_MB_HEAD_STRUCT
{
	struct ADM_MB_HEAD_STRUCT *prev;     /* previous MB */
	struct ADM_MB_HEAD_STRUCT *next;     /* next MB */
	struct ADM_MB_HEAD_STRUCT *bl_prev;  /* prev pointer in Block List */
	struct ADM_MB_HEAD_STRUCT *bl_next;  /* next pointer in Block List */
} ADM_MB_HEAD;

/* ADM Memory Block Log */
typedef struct ADM_MB_LOG_STRUCT
{
	kal_uint32 stamp;    /* store a fixed pattern to check corruption */
	kal_char *filename;
	kal_uint32 line;
} ADM_MB_LOG;

/* ADM Memory Block Footer */
typedef struct ADM_MB_FOOT_STRUCT
{
	kal_uint32 stamp;   /* store a fixed pattern to check corruption */
} ADM_MB_FOOT;

/* ADM Block List */
typedef struct
{
	kal_uint32 size;
	kal_uint32 reserved;
	struct ADM_MB_HEAD_STRUCT *bl_prev;  /* prev pointer in Block List */
	struct ADM_MB_HEAD_STRUCT *bl_next;  /* next pointer in Block List */
	/*
	 * NoteXXX: bl_prev and bl_next must be the last 2 elements
	 * since ADM_MB_HEAD's bl_prev may point to one ADM_BL.
	 * (i may cast a ADM_BL to ADM_MB_HEAD to reference bl_prev and bl_next.)
	 */
} ADM_BL;

/*******************************************************************************
 * Macros definitions
 *******************************************************************************/

/*
 * NoteXXX: the least-significant-bit of adm_mb_head->prev is used to store the memory
 * block's state. 1 for INUSE; 0 for FREE.
 * Need to use these special macros for accessing adm_mb_head->prev.
 */
#define ADM_MB_PREV(adm_mb_head) \
		(ADM_MB_HEAD *)((kal_uint32)(adm_mb_head)->prev & ~0x01)

#define ADM_MB_SET_PREV(oldval, newval) \
		(ADM_MB_HEAD *)((kal_uint32)(newval) | ((kal_uint32)(oldval) & 0x01))

#define ADM_MB_SET_INUSE(adm_mb_head) \
		(adm_mb_head)->prev = (ADM_MB_HEAD *)((kal_uint32)(adm_mb_head)->prev | 0x01)

#define ADM_MB_SET_FREE(adm_mb_head) \
		(adm_mb_head)->prev = (ADM_MB_HEAD *)((kal_uint32)(adm_mb_head)->prev & ~0x01)

#define ADM_MB_STATE(adm_mb_head) \
		(((kal_uint32)(adm_mb_head)->prev & 0x01)? ADM_INUSE: ADM_FREE)

#define ADM_MB_SIZE(adm_mb_head) \
		(((adm_mb_head)->next == NULL)? 0: (kal_uint32)(adm_mb_head)->next - (kal_uint32)(adm_mb_head))

#define ADM_GET_CB(mem_addr) (ADM_CB *)((mem_addr))

#define ADM_GET_FIRST_BL(mem_addr) (ADM_BL *)((kal_uint8 *)(mem_addr) + sizeof(ADM_CB))

#define ADM_GET_FIRST_MB(mem_addr, bl_num) \
		(ADM_MB_HEAD *)((kal_uint8 *)(mem_addr) + sizeof(ADM_CB) + (bl_num) * sizeof(ADM_BL))

#define ADM_GET_TAIL_MB(mem_addr, totalsize) \
		(ADM_MB_HEAD *)((kal_uint8 *)(mem_addr) + (totalsize) - sizeof(ADM_MB_HEAD))

#define ADM_GET_MB_HEAD(mem_addr) \
		(ADM_MB_HEAD *)((kal_uint8 *)(mem_addr) - sizeof(ADM_MB_MINI_HEAD))

#define ADM_GET_MB_LOG(adm_mb_head) \
		(ADM_MB_LOG *)((kal_uint8 *)(adm_mb_head) + sizeof(ADM_MB_MINI_HEAD))

#define ADM_GET_MB_FOOT(adm_mb_head) \
		(ADM_MB_FOOT *)((kal_uint8 *)(adm_mb_head)->next - sizeof(ADM_MB_FOOT))

#define ADM_ROUND_2_4BYTE(value) (value) = ((((value) + 3) >> 2) << 2)

#endif   /* _KAL_ADM_H */


