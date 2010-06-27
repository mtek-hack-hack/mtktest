/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cache_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of L1 and L2 cache.
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

#ifndef _CACHE_HW_H
#define _CACHE_HW_H

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230))

/* L1 Cache and MPU */
#define L1CACHE_BASE    (0x80700000)
#define CACHE_CON       ((volatile kal_uint16 *)(L1CACHE_BASE+0x0000))
#define CACHE_OP        ((volatile kal_uint32 *)(L1CACHE_BASE+0x0004))
#define CACHE_HCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0008))
#define CACHE_HCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x000C))
#define CACHE_CCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0010))
#define CACHE_CCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0014))
#define CACHE_HCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0018))
#define CACHE_HCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x001C))
#define CACHE_CCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0020))
#define CACHE_CCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0024))

#define MPU_BASE        (0x80701000)
#define MPU_PORT0       ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_PORT1       ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_PORT2       ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_PORT3       ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_PORT4       ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_PORT5       ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_PORT6       ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_PORT7       ((volatile kal_uint32 *)(MPU_BASE+0x001C))

#define MPU_CACHE0      ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_CACHE1      ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_CACHE2      ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_CACHE3      ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_CACHE4      ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_CACHE5      ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_CACHE6      ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_CACHE7      ((volatile kal_uint32 *)(MPU_BASE+0x005C))

/* L2 Cache */
#define L2CACHE_BASE    (0x80050000)
#define L2C_CON         ((volatile kal_uint32 *)(L2CACHE_BASE+0x0000))
#define L2_TARGET       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0004))
#define L2C_STA         ((volatile kal_uint32 *)(L2CACHE_BASE+0x0008))
#define L2C_TAG         ((volatile kal_uint32 *)(L2CACHE_BASE+0x000C))
#define L2C_DATA        ((volatile kal_uint32 *)(L2CACHE_BASE+0x0010))

#elif defined(MT6225)

#define L1CACHE_BASE    (0x80700000)
#define CACHE_CON       ((volatile kal_uint16 *)(L1CACHE_BASE+0x0000))
#define CACHE_OP        ((volatile kal_uint32 *)(L1CACHE_BASE+0x0004))
#define CACHE_HCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0008))
#define CACHE_HCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x000C))
#define CACHE_CCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0010))
#define CACHE_CCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0014))
#define CACHE_HCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0018))
#define CACHE_HCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x001C))
#define CACHE_CCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0020))
#define CACHE_CCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0024))

#define MPU_BASE        (0x80701000)
#define MPU_PORT0       ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_PORT1       ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_PORT2       ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_PORT3       ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_PORT4       ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_PORT5       ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_PORT6       ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_PORT7       ((volatile kal_uint32 *)(MPU_BASE+0x001C))

#define MPU_CACHE0      ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_CACHE1      ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_CACHE2      ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_CACHE3      ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_CACHE4      ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_CACHE5      ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_CACHE6      ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_CACHE7      ((volatile kal_uint32 *)(MPU_BASE+0x005C))

#elif defined(MT6238)   /* MT6228 || MT6229 || MT6230 */

/* L2 Cache */
#define L2CACHE_BASE    (0x810b0000)
#define L2C_CON         ((volatile kal_uint32 *)(L2CACHE_BASE+0x0000))
#define L2_TARGET       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0004))
#define L2C_STA         ((volatile kal_uint32 *)(L2CACHE_BASE+0x0008))
#define L2C_TAG         ((volatile kal_uint32 *)(L2CACHE_BASE+0x000C))
#define L2C_DATA        ((volatile kal_uint32 *)(L2CACHE_BASE+0x0010))
#define L2C_MODE        ((volatile kal_uint32 *)(L2CACHE_BASE+0x0014))
#define L2C_DMYTAG      ((volatile kal_uint32 *)(L2CACHE_BASE+0x0018))
#define L2C_HCNTL       ((volatile kal_uint32 *)(L2CACHE_BASE+0x001C))
#define L2C_HCNTU       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0020))
#define L2C_ACNTL       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0024))
#define L2C_ACNTU       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0028))

#endif   /* MT6228 || MT6229 || MT6230 */

#endif
