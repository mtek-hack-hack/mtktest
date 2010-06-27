/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MT6226_NVRAMStatistic/include/nvram_auto_gen.h,v 1.1 2007/05/17 07:24:47 bw Exp $
*
* $Id: nvram_auto_gen.h,v 1.1 2007/05/17 07:24:47 bw Exp $
*
* $Date: 2007/05/17 07:24:47 $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 1.1 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: nvram_auto_gen.h,v $
* Revision 1.1  2007/05/17 07:24:47  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * nvram_auto_gen.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for generating NVRAM information.
 *
 * Author:
 * -------
 * Cylen Yao (mtk00911)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * ~Log$
 *
 * Dec 17 2006 mtk00911
 * [MAUI_00351729] [NVRAM] Define kal_bool as 8-bit int in pc environment
 * 
 *
 * Jul 31 2006 mtk00911
 * [MAUI_00213455] [EngineerMode] CTI Log baudrate setting support.
 * 
 *
 * May 17 2006 mtk00911
 * [MAUI_00194692] [NVRAM] Fix the side effect of exception header change
 * 
 *
 * Apr 22 2006 mtk00911
 * [MAUI_00188983] [NVRAM] Revise customization process
 * Tool to auto gen NVRAM statistics
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_AUTO_GEN_H
#define NVRAM_AUTO_GEN_H

#define __inline
#define _KAL_RELEASE_H
#include "kal_non_specific_general_types.h"

#define kal_bool kal_uint8

typedef enum {
    INVAID_EXCEPTION        =  0,
    UNDEF_EXCEPTION         =  1,
    SWI_EXCEPTION        =  2,
    PREFETCH_EXCEPTION      =  3,
    DATAABORT_EXCEPTION     =  4,
    ASSERT_FAIL_EXCEPTION   =  5,
    SYS_FATALERR_EXT_TASK_EXCEPTION  =  6,
    SYS_FATALERR_EXT_BUF_EXCEPTION = 7,
    SYS_LOCKUP           =  8,
    NUM_EXCEPTION
} exception_type;

typedef enum {
    FACTORY_BOOT = 0,
    NORMAL_BOOT = 1,
    USBMS_BOOT =  2,
    NUM_OF_BOOT_MODE,
    UNKNOWN_BOOT_MODE = 0xff
} boot_mode_type;

enum { ASSERT_DUMP_PARAM_MAX = 10 };

typedef struct ASSERT_DUMP_PARAM
{
    kal_uint32 addr[ASSERT_DUMP_PARAM_MAX];
    kal_uint32 len[ASSERT_DUMP_PARAM_MAX];  /* in bytes */
} ASSERT_DUMP_PARAM_T;

typedef struct {
	kal_uint8   unused;
} *kal_poolid;

typedef void *kal_hisrid;

#define KAL_MAX_NUM_HISRS 20
#define static
#endif/*NVRAM_AUTO_GEN_H*/
