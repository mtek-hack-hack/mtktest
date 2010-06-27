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
 *   cp15.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for coprocessor(CP15) control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CP15_H__
#define __CP15_H__


#if defined(__ARM9_MMU__)

extern kal_uint32 cp15_read_cache_type(void);
extern void cp15_enable_icache(void);
extern void cp15_disable_icache(void);
extern void cp15_invalidate_icache(void);
extern void cp15_enable_dcache(void);
extern void cp15_disable_dcache(void);
extern void cp15_invalidate_dcache(void);
extern void cp15_invalidate_dcache_single(kal_uint32 mva);
extern void cp15_clean_dcache_single(kal_uint32 mva);
extern void cp15_drain_write_buffer(void);
extern kal_uint32 cp15_read_tcm_status(void);
extern kal_uint32 cp15_read_itcm_region(void);
extern kal_uint32 cp15_read_dtcm_region(void);
extern void cp15_enable_itcm(kal_uint32 addr);
extern void cp15_enable_dtcm(kal_uint32 addr);
extern kal_uint32 cp15_read_tbbr(void);
extern void cp15_write_tbbr(kal_uint32 addr);
extern void cp15_enable_mmu(void);
extern void cp15_disable_mmu(void);
extern kal_uint32 cp15_read_domain_access(void);
extern void cp15_write_domain_access(kal_uint32 domain, kal_uint32 access);
extern kal_uint32 cp15_read_ifsr(void);
extern kal_uint32 cp15_read_dfsr(void);
extern kal_uint32 cp15_read_far(void);
extern void cp15_enable_rom_protect(void);
extern void cp15_disable_rom_protect(void);
extern void cp15_enable_sys_protect(void);
extern void cp15_disable_sys_protect(void);
extern void cp15_enable_alignment_fault(void);
extern void cp15_disable_alignment_fault(void);
extern void cp15_enter_low_pwr_state(void);

#else   /* __ARM9_MMU__ */

/* define empty macro for backward compatible */

#define cp15_read_ifsr() 0
#define cp15_read_dfsr() 0
#define cp15_read_far() 0

#endif  /* !__ARM9_MMU__ */

#endif  /* __CP15_H__ */

