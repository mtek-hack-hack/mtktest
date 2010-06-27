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
 *   mmu.h
 *
 * Project:
 * --------
 *   Device Test
 *
 * Description:
 * ------------
 *   Header file for MMU.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMU_H__
#define __MMU_H__

/*
 * Define constants.
 */

/* page table descriptor attribute */
enum 
{
    FIRST_LEVEL_FAULT = 0,
    FIRST_LEVEL_COARSE_PAGE = 1,
    FIRST_LEVEL_SECTION = 2,
    FIRST_LEVEL_FINE_PAGE = 3,
    SECOND_LEVEL_FAULT = 0,
    SECOND_LEVEL_LARGE_PAGE = 1,
    SECOND_LEVEL_SMALL_PAGE = 2,
    SECOND_LEVEL_TINY_PAGE = 3
};

/* cacheable and bufferable */
enum
{
    PAGE_NO_CACHE = 0,
    PAGE_BUFFERABLE = 1,
    PAGE_CACHEABLE = 1
};

/* access permission */
enum
{
    PRIV_READ_ONLY = 0,
    PRIV_READ_WRITE = 1,
    USER_READ_ONLY = 2,
    USER_READ_WRITE = 3
};

/* domain access control */
enum
{
    DOMAIN_READ_ONLY = 0,
    DOMAIN_CLIENT = 1,
    DOMAIN_RESERVED = 2,
    DOMAIN_MANAGER = 3
};

/* domains */
enum
{
    DOMAIN00 = 0,
    DOMAIN01 = 1,
    DOMAIN02 = 2,
    DOMAIN03 = 3,
    DOMAIN04 = 4,
    DOMAIN05 = 5,
    DOMAIN06 = 6,
    DOMAIN07 = 7,
    DOMAIN08 = 8,
    DOMAIN09 = 9,
    DOMAIN10 = 10,
    DOMAIN11 = 11,
    DOMAIN12 = 12,
    DOMAIN13 = 13,
    DOMAIN14 = 14,
    DOMAIN15 = 15
};

/* page size */
enum 
{
    PAGE_SIZE_1KB = 1 * 1024,
    PAGE_SIZE_1KB_SHIFT = 10,
    PAGE_SIZE_1KB_MASK = 0x000003FF,
    PAGE_SIZE_4KB = 4 * 1024,
    PAGE_SIZE_4KB_SHIFT = 12,
    PAGE_SIZE_4KB_MASK = 0x00000FFF,
    PAGE_SIZE_64KB = 64 * 1024,
    PAGE_SIZE_64KB_SHIFT = 16,
    PAGE_SIZE_64KB_MASK = 0x0000FFFF,
    PAGE_SIZE_1MB = 1 * 1024 * 1024,
    PAGE_SIZE_1MB_SHIFT = 20,
    PAGE_SIZE_1MB_MASK = 0x000FFFFF,
    PAGE_SIZE_NUM = 4
};

/* page table size */
enum 
{
    CPT_SIZE = 256 * 4,    /* coarse page table size */
    FPT_SIZE = 1024 * 4    /* fine page table size */
};

/* page table base address mask */
#define CPT_BASE_MASK 0xFFFFFC00
#define FPT_BASE_MASK 0xFFFFF000


/*
 * Define macros.
 */

/* make section descriptor */
#define mk_sd(addr, ap, domain, c, b) (((addr) & 0xfff00000) | ((ap) << 10) | ((domain) << 5) | (1 << 4) | ((c) << 3) | ((b) << 2) | FIRST_LEVEL_SECTION)

/* make coarse page table descriptor */
#define mk_cptd(addr, domain) (((addr) & 0xfffffc00) | ((domain) << 5) | (1 << 4) | FIRST_LEVEL_COARSE_PAGE)

/* make fine page table descriptor */
#define mk_fptd(addr, domain) (((addr) & 0xfffff000) | ((domain) << 5) | (1 << 4) | FIRST_LEVEL_FINE_PAGE)

/* make large page descripter */
#define mk_lpd(addr, ap, c, b) (((addr) & 0xffff0000) | ((ap) << 10) | ((ap) << 8) | ((ap) << 6) | ((ap) << 4) | ((c) << 3) | ((b) << 2) | SECOND_LEVEL_LARGE_PAGE)

/* make small page descripter */
#define mk_spd(addr, ap, c, b) (((addr) & 0xfffff000) | ((ap) << 10) | ((ap) << 8) | ((ap) << 6) | ((ap) << 4) | ((c) << 3) | ((b) << 2) | SECOND_LEVEL_SMALL_PAGE)

/* make tiny page descripter */
#define mk_tpd(addr, ap, c, b) (((addr) & 0xfffffc00) | ((ap) << 4) | ((c) << 3) | ((b) << 2) | SECOND_LEVEL_TINY_PAGE)

/* determin if section descripter */
#define is_sd(d) (((d) & 0x00000003) == FIRST_LEVEL_SECTION)

/* determin if coarse page table descripter */
#define is_cptd(d) (((d) & 0x00000003) == FIRST_LEVEL_COARSE_PAGE)

/* determin if fine page table descripter */
#define is_fptd(d) (((d) & 0x00000003) == FIRST_LEVEL_FINE_PAGE)

/* make default page table */
#define mk_def_pt(tbl) \
        do {    \
            kal_int32 i;   \
            kal_uint32 *tbl_ptr = (kal_uint32 *)(tbl);  \
            for (i = 4096; i >= 0; i--) {   \
                tbl_ptr[i] = FIRST_LEVEL_FAULT; \
            }   \
        } while (0)

/* make coarse page table */
#define mk_cpt(tbl, base) \
        do {    \
            kal_uint32 i, a;   \
            kal_uint32 *tbl_ptr = (kal_uint32 *)(tbl);    \
            for (i = 0, a = (kal_uint32)(base); i < 256; i ++, a += PAGE_SIZE_4KB) {   \
               tbl_ptr[i] = SECOND_LEVEL_FAULT; \
            }   \
        } while (0)

/* make fine page table */
#define mk_fpt(tbl, base)   \
        do {    \
            kal_uint32 i, a; \
            kal_uint32 *tbl_ptr = (kal_uint32 *)(tbl);    \
            for (i = 0, a = (kal_uint32)(base); i < 1024; i++, a += PAGE_SIZE_1KB) {  \
               tbl_ptr[i] = SECOND_LEVEL_FAULT; \
            }   \
        } while (0)

#endif  /* __MMU_H__ */

