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
 *   flash_opt.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   NOR flash related options
 *
 * Author:
 * -------
 *   EMI auto generator V4.17
 *
 *   Memory Device database last modified on 2009/11/16
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define NOR_FLASH_TYPE_SPANSION_PL_J
#define __MULTI_BANK_NOR_DEVICE__

#ifdef NOR_FLASH_TYPE_INTEL_SERIES
#define __INTEL_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_INTEL
#define __INTEL_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_RENESAS_SERIES
#define __RENESAS_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_RENESAS
#define __RENESAS_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_INTEL_SIBLEY
#define __INTEL_SERIES_NOR__
#define __INTEL_SIBLEY__
#endif

#ifdef NOR_FLASH_TYPE_RAM_DISK
#define __RAMDISK__
#endif

#ifdef NOR_FLASH_TYPE_SST
#define __AMD_SERIES_NOR__
#define __SST_NOR__
#endif

#ifdef NOR_FLASH_TYPE_ST_AMD_LIKE
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_ST_INTEL_LIKE
#define __INTEL_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_AMD_SERIES
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_PL_J
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_PL_N
#define __AMD_SERIES_NOR__
#define __SPANSION_PL_N__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_WS_N
#define __AMD_SERIES_NOR__
#define __SPANSION_WS_N__
#define __SPANSION_PL_N__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_GL_A
#define __AMD_SERIES_NOR__
#define __SPANSION_GL_A__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_GL_N
#define __AMD_SERIES_NOR__
#define __SPANSION_GL_N__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_NS_N
#define __AMD_SERIES_NOR__
#define __SPANSION_NS_N__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_NS_J
#define __AMD_SERIES_NOR__
#define __SPANSION_NS_J__
#endif

#ifdef NOR_FLASH_TYPE_TOSHIBA
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_TOSHIBA_TV
#define __AMD_SERIES_NOR__
#define __TOSHIBA_TV__
#endif

#ifdef NOR_FLASH_TYPE_TOSHIBA_TY
#define __AMD_SERIES_NOR__
#define __TOSHIBA_TY__
#endif

#ifdef NOR_FLASH_TYPE_SILICON7
#define __RENESAS_SERIES_NOR__
#endif

