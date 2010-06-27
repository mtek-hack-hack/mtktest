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
 *   cache_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of code and data cache.
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

#ifndef _CACHE_SW_H
#define _CACHE_SW_H

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) )

/* Code Cache and MPU */
typedef enum RegionSize_T
{
   CACHE_SIZE_1KB   = 0,
   CACHE_SIZE_2KB   = 0x02,
   CACHE_SIZE_4KB   = 0x04,
   CACHE_SIZE_8KB   = 0x06,
   CACHE_SIZE_16KB  = 0x08,
   CACHE_SIZE_32KB  = 0x0a,
   CACHE_SIZE_64KB  = 0x0c,
   CACHE_SIZE_128KB = 0x0e,
   CACHE_SIZE_256KB = 0x10,
   CACHE_SIZE_512KB = 0x12,
   CACHE_SIZE_1MB   = 0x14,
   CACHE_SIZE_2MB   = 0x16,
   CACHE_SIZE_4MB   = 0x18
} RegionSize;


typedef enum CacheType_T
{
   NO_CACHE   = 0x0000,  /* 128KB TCM, 0KB Cache  */
   CACHE_1WAY = 0x0100,  /* 120KB TCM, 8KB Cache  */
   CACHE_2WAY = 0x0200,  /* 112KB TCM, 16KB Cache */
   CACHE_4WAY = 0x0300   /* 96KB TCM, 32KB Cache  */
} CacheType;


typedef enum MPU_ATTRIBUTE_T
{
   NON_READABLE_NON_WRITEABLE = 0x00,
   NON_READABLE_BUT_WRITEABLE = 0x40,
   READABLE_BUT_NON_WRITEABLE = 0x80,
   READABLE_WRITEABLE = 0xc0
} MPU_ATTRIBUTE;


typedef struct CacheMenu_T
{   
   kal_uint32  c_addr;
   kal_uint32  c_range;   
   kal_uint16  c_channel;   
   kal_uint16  c_enable;   
} CacheMenuType;


typedef struct MPUMenu_T
{   
   kal_uint32     m_addr;
   kal_uint32     m_range;
   kal_uint16     m_channel;   
   MPU_ATTRIBUTE  m_attribute;   
   kal_uint8      m_enable;
} MPUMenuType;


typedef struct CodeCACHEHitRate_T
{   
   kal_uint64  hitCount1;
   kal_uint64  accessCount1;
   kal_uint64  hitCount2;
   kal_uint64  accessCount2;
} CodeCacheHitCount;

/* Data Cache */
#define  DataCacheDisabled           0x80000013
#define  DataCacheInvalidateAll      0x80000050
#define  DataCacheEnabled            0x80000003
#define  DataCacheLocking2Way        0x00000020
#define  DataCacheGATEDG             0x00000040
#define  DataCacheFBBR               0x00000100

#define  DataCacheCommandBusy        0x01
#define  DataCacheWaitCommandReady() while ( *(L2C_STA) & DataCacheCommandBusy );

#define InvalidCodeCacheByAddr(addr) do { *CACHE_OP = ((addr) & 0xFFFFFFE0 ) | 0x00000005; } while (0)
#define InvalidCodeCacheByAlignedAddr(addr) do { *CACHE_OP = (addr) | 0x00000005; } while (0)

/* Prototypes */
void CodeCacheConfig(CacheType type, kal_bool enable);
void CodeCacheSetting(CacheMenuType *cacheMenu);
void MPUSetting(MPUMenuType *menu);
kal_bool DataCacheConfig(kal_bool enable, kal_bool reservedForMPEG4);
void CacheAccessHitCount(CodeCacheHitCount *ret);
void CacheInit(void);
kal_uint32 EnableFBBR(void);
void DisableFBBR(kal_uint32 val);
kal_uint32 Lock2WaysForMPEG4(void);
void Unlock2WaysForMPEG4(kal_uint32 val);
kal_uint32 GateDG(void);
void UngateDG(kal_uint32 val);

#elif defined(MT6225)   /* MT6228 || MT6229 || MT6230 */

/* Code Cache and MPU */
typedef enum RegionSize_T
{
   CACHE_SIZE_1KB   = 0,
   CACHE_SIZE_2KB   = 0x02,
   CACHE_SIZE_4KB   = 0x04,
   CACHE_SIZE_8KB   = 0x06,
   CACHE_SIZE_16KB  = 0x08,
   CACHE_SIZE_32KB  = 0x0a,
   CACHE_SIZE_64KB  = 0x0c,
   CACHE_SIZE_128KB = 0x0e,
   CACHE_SIZE_256KB = 0x10,
   CACHE_SIZE_512KB = 0x12,
   CACHE_SIZE_1MB   = 0x14,
   CACHE_SIZE_2MB   = 0x16,
   CACHE_SIZE_4MB   = 0x18,
   CACHE_SIZE_8MB   = 0x1a,
   CACHE_SIZE_16MB  = 0x1c
} RegionSize;


typedef enum CacheType_T
{
   NO_CACHE   = 0x0000,  /* 0KB Cache  */
   CACHE_1WAY = 0x0100,  /* 8KB Cache  */
   CACHE_2WAY = 0x0200   /* 16KB Cache */
} CacheType;


typedef enum MPU_ATTRIBUTE_T
{
   NON_READABLE_NON_WRITEABLE = 0x00,
   NON_READABLE_BUT_WRITEABLE = 0x40,
   READABLE_BUT_NON_WRITEABLE = 0x80,
   READABLE_WRITEABLE = 0xc0
} MPU_ATTRIBUTE;


typedef struct CacheMenu_T
{   
   kal_uint32  c_addr;
   kal_uint32  c_range;   
   kal_uint16  c_channel;   
   kal_uint16  c_enable;   
} CacheMenuType;


typedef struct MPUMenu_T
{   
   kal_uint32     m_addr;
   kal_uint32     m_range;
   kal_uint16     m_channel;   
   MPU_ATTRIBUTE  m_attribute;   
   kal_uint8      m_enable;
} MPUMenuType;


typedef struct CodeCACHEHitRate_T
{   
   kal_uint64  hitCount1;
   kal_uint64  accessCount1;
   kal_uint64  hitCount2;
   kal_uint64  accessCount2;
} CodeCacheHitCount;

#define InvalidCodeCacheByAddr(addr) do { *CACHE_OP = ((addr) & 0xFFFFFFE0 ) | 0x00000005; } while (0)
#define InvalidCodeCacheByAlignedAddr(addr) do { *CACHE_OP = (addr) | 0x00000005; } while (0)

/* Prototypes */
void CodeCacheConfig(CacheType type, kal_bool enable);
void CodeCacheSetting(CacheMenuType *cacheMenu);
void MPUSetting(MPUMenuType *menu);
void CacheAccessHitCount(CodeCacheHitCount *ret);
void CacheInit(void);

#elif defined(MT6238)   /* MT6228 || MT6229 || MT6230 */

/* Data Cache */
#define  DataCacheDisabled              0x80000013
#define  DataCacheInvalidateAll         0x80000050
#define  DataCacheEnabled               0x80000003
#define  DataCacheLocking2Way           0x00000020
#define  DataCacheGATEDG                0x00000040
#define  DataCacheDIRTYAALL             0x00000080
#define  DataCacheFBBR                  0x00000100
#define  DataCacheEX                    0x00000200
#define  DataCacheC2WBUF                0x00000400
#define  DataCacheBURSTDIS              0x00000800
#define  DataCacheCNTEN                 0x00001000
#define  DataCacheCommandBusy           0x01
#define  DataCacheWaitCommandReady()    while ( *(L2C_STA) & DataCacheCommandBusy );

/* Prototypes */
kal_bool DataCacheConfig(kal_bool enable, kal_bool reservedForMPEG4);
extern kal_uint32 EnableFBBR(void);
extern void DisableFBBR(kal_uint32 val);
extern kal_uint32 Lock2WaysForMPEG4(void);
extern void Unlock2WaysForMPEG4(kal_uint32 val);
extern kal_uint32 GateDG(void);
extern void UngateDG(kal_uint32 val);
extern kal_int32 invalidate_arm9_dcache(kal_uint32 addr, kal_uint32 len);
extern kal_int32 clean_arm9_dcache(kal_uint32 addr, kal_uint32 len);

#endif  /* MT6228 || MT6229 || MT6230 */

#endif
