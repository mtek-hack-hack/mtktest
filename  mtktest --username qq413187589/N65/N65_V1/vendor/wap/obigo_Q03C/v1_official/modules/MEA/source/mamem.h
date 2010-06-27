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

/* \file mamem.h
 * Memory (de)allocation macros for MEA.
 */

#ifndef _MAMEM_H_
#define _MAMEM_H_

#ifndef _msf_mem_h
#error msf_mem.h must be included before mamem.h.
#endif

/******************************************************************************
 * Macros
 *****************************************************************************/

/*!\brief Allocation macro for MEA. If memory cannot be allocated then the
 *        application is going to terminate.
 *
 * \param s The number of bytes to allocate.
 * \return The pointer to the allocated memory.
 */
#define MEA_ALLOC(s)            meaAlloc(s)

/*!\brief Allocation macro for MEA. If memory cannot be allocated then the
 *        application is going to terminate. Memory is also cleared. 
 *
 * \param s The number of bytes to allocate.
 * \param p Pointer that will point to newly allocated memory
 */
#define MEA_CALLOC(p, s)            p = meaAlloc(s); memset((p), 0, (s))

/*!\brief Allocation macro for MEA. If memory cannot be allocated then the
 *        application is going to terminate.
 *
 * \param s The number of bytes to allocate.
 * \param type The type to allocate.
 * \return The pointer to the allocated memory.
 */
#define MEA_ALLOC_TYPE(type)    meaAlloc(sizeof(type))

/*!\brief Allocation macro for with termination used in MEA. 
 *
 * \param s The number of bytes to allocate.
 * \return The pointer to the allocated memory, or NULL if no memory could be 
 *         allocated.
 */
#define MEA_ALLOC_NE(s)         meaAllocNoException(s)

/*!\brief Deallocation macro for MEA 
 *
 * \param p The memory location to deallocate..
 * \return The pointer to the allocated memory, or NULL if no memory could be 
 *         allocated.
 */
#define MEA_FREE(p)       if (NULL != (p)) MSF_MEM_FREE(MSF_MODID_MEA, (p))
#ifdef WAP_SUPPORT //for MMS_SLIM_MEM
// #define MEA_CFREE(p)     if (NULL != (p)) MSF_MEM_FREE(MSF_MODID_MEA, (p));p=NULL
#define MEA_CFREE(p)     do { \
		if (NULL != (p)) \
			MSF_MEM_FREE(MSF_MODID_MEA, (p));\
		p = NULL; \
	} while (0)
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Prototypes
 *****************************************************************************/

void *meaAllocNoException(MSF_UINT32 size);
void *meaAlloc(MSF_UINT32 size);
void meaFree(void *p);

#endif


