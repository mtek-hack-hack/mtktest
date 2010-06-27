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
 *
 * Filename:
 * ---------
 *  NAND_FDM.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a NAND FDM header file
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NAND_FDM_H
#define NAND_FDM_H


/*******************************************************************************
 * Include Header Files
 * FLASH_DISKDRV_DEBUG indicates simulation environment
 *******************************************************************************/
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
   #include <stdio.h>
   #include <stdlib.h>
   #include <assert.h>
#else
   #include "kal_release.h"
#endif

#include <string.h>
#include "NAND_MTD.h"

/*******************************************************************************
 * parameter definition
 *******************************************************************************/
#ifndef ONE_BYTE_ALIGN_ADS
    #ifdef __MTK_TARGET__
    #define ONE_BYTE_ALIGN_ADS  __packed
    #else
    #define ONE_BYTE_ALIGN_ADS
    #endif
#endif /* !ONE_BYTE_ALIGN_ADS */

//#define POWERLOSS_TEST             // power recovery test in simulation
//#define ERROR_HANDLING_TEST   // error handling test in simulation
#define DDWORD_INVALID           ((kal_uint64)~0)
#define DWORD_INVALID            0xFFFFFFFF
#define WORD_INVALID             0xFFFF
#define BYTE_INVALID             0xFF
#define FDM_ERROR                1
#define FDM_NO_ERROR             0

// FIXME - Remember to rocover correct value check in.
#define POOL_SIZE                12    // used for non-data blocks in a region (double in first region)
#define GC_THRESHOLD             25
#define TRY_TIMES                3


#define MAX_REGION_NUM           72    // max disk volumn = 2GB
#define MAX_PAGES_PER_BLOCK      64
#define MAX_SECTORS_PER_PAGE     4

#define MAX_PAGE_SIZE            2112
#define MAX_DATA_SIZE            2048
#define MAX_SPARE_SIZE           64
#define SECTOR_SIZE              512
#define MAX_CTRL_LOG_NUM         5   /*Max number of control_log block*/
/* page size */
enum
{
    PAGE_512,
    PAGE_2K
};

/* indicate if write ECC fields while program page */
enum
{
    ECC_SKIP = 0,            // don't program spare area
    ECC_FIRST_HALF,      // only program first and second ECC fields
    ECC_SECOND_HALF,     // only program third and fourth ECC fields
    ECC_WHOLE            // program whole ECC fields
};

/* Public drive size customization constraints */
#define NAND_MINIMUM_PARTITION_SIZE     (400)

/*******************************************************************************
 * block/page/sector state ID
 *******************************************************************************/
#define BLOCK_EMPTY              0xFF
#define BLOCK_CONTROL            0xFC
#define BLOCK_ALLOCATED          0xAF    /*use to avoid double allocate at LocateBlock or LocateEmptyBlock*/
#define BLOCK_ACTIVE             0xAE
#define BLOCK_DATA               0xAC
#define BLOCK_BAD                0x00
#define BLOCK_NG_CONTROL         0xC3
#define BLOCK_CTRL_LOG           0xC0    // Old control block, reserve as a record
#define BLOCK_COPY_DST           0xAA    /*copy destination block*/
#define BLOCK_MERGE_BMR0         0xA9    /*active merge destination when BMR = 0*/
#define BLOCK_MERGE_BMR1         0xA8    /*active merge destination when BMR = 1*/
#define BLOCK_ERASING            0x07    /*Ready to erase*/   

#define PAGE_EMPTY               0xFF
#define PAGE_DATA                0x0F
#define PAGE_DELETED             0x00
#define PAGE_LOG                 0x3F   /*For log section - 2007/05/29 Yehudi*/

#define SECTOR_EMPTY             0xFF
#define SECTOR_DATA              0x0F
#define SECTOR_CONTROL           0xF0    // control block header
#define SECTOR_CTRL_LOG          0xC0    // Old control block, reserve as a record
#define SECTOR_BST               0x33    // block status table
#define SECTOR_LBM               0xCC    // logical block mapping
#define SECTOR_SPOT              0x55   // yoda add for reserving spot
#define SECTOR_DELETED           0x00
#define SECTOR_LOG               0x3F   /*For log section - 2007/05/29 Yehudi*/

/*******************************************************************************
 * Macro definition used for code simplification
 *******************************************************************************/
#define R_BLOCKS                256   /* Default(Maximun) value of block number of region. REGION_B(b) is the real block number of region(b)*/
#define B_PAGES                 (D->flash_info.pages_per_block)
#define P_SECTORS               ((D->flash_info.page_type==PAGE_2K) ? 4 : 1)
#define DATA_SIZE               ((D->flash_info.page_type==PAGE_2K) ? 2048 : 512)
#define SPARE_SIZE              ((D->flash_info.page_type==PAGE_2K) ?   64 :  16)
#define LOG_BLOCKS              ((D->flash_info.page_type==PAGE_2K) ? 3 : 6)    /*Block number of log section - Yehudi*/
#define PAGE_SIZE               ((DATA_SIZE)+(SPARE_SIZE))
#define P_SHIFTS                ((D->flash_info.page_type==PAGE_2K) ? 2 : 0)

/* region info */
#define CUR_R                   (D->region_info.current_region)
#define BASE_B                  (D->region_info.base_block)
#define REGION_B(b)             (D->region_info.region_block[(b)])              /*2007/05/26 Yehudi*/

/* control info */
#define LBM(b)                  (D->control_table.block_mapping[(b)])
#define BST(b)                  (D->control_table.block_state[(b)])
#define CNT_PB                  (D->control_info.physical_block)

/* active info */
#define ACT_LB                  (D->active_info.logical_block)
#define ACT_PB                  (D->active_info.physical_block)
#define ACT_LPM(p)              (D->active_info.page_mapping[(p)])

#define IS_VALID_DATA_BLOCK(b)  (LBM(b)!=BYTE_INVALID || (LBM(b)==255 && LBM(255)==b))
#define IS_INVALID_DATA_BLOCK(b)(LBM(b)==BYTE_INVALID && LBM(255) != b)
#define SET_FLAG_FOR_PHY255(log_b,phy_b)\
{\
if( ((kal_uint8)(phy_b)) == 255)\
      LBM(255) = (kal_uint8)(log_b);\
}

#define IS_2K_CNTL_TABLE(half,ptr)\
   ( ((half)==0) && (((spare_2k*)(ptr))->spare[0].SS == SECTOR_BST)\
      && (((spare_2k*)(ptr))->spare[1].SS == SECTOR_LBM) )\
   || ( ((half)==1) && (((spare_2k*)(ptr))->spare[2].SS == SECTOR_BST)\
      && (((spare_2k*)(ptr))->spare[3].SS == SECTOR_LBM) )

#define IS_2K_CNTL_SPOT(half,ptr)\
   ( ((half)==0) && (((spare_2k*)(ptr))->spare[0].SS == SECTOR_SPOT))\
   || ( ((half)==1) && (((spare_2k*)(ptr))->spare[2].SS == SECTOR_SPOT))

#define IS_2K_NEXT_CNTL_TABLE(half,ptr)\
   ( ((half)==0) && (((spare_2k*)(ptr))->spare[0].SS == SECTOR_EMPTY)\
      && (((spare_2k*)(ptr))->spare[1].SS == SECTOR_EMPTY) )\
   || ( ((half)==1) && (((spare_2k*)(ptr))->spare[2].SS == SECTOR_EMPTY)\
      && (((spare_2k*)(ptr))->spare[3].SS == SECTOR_EMPTY) )

#define IS_512_CNTL_TABLE(spare0,spare1)\
   spare_512_PS(spare0)==SECTOR_BST && spare_512_PS(spare1)==SECTOR_LBM

#define IS_512_CNTL_SPOT(spare0,spare1)\
   spare_512_PS(spare0)==SECTOR_SPOT 


#define IS_512_NEXT_CNTL_TABLE(spare0,spare1)\
   spare_512_PS(spare0)==SECTOR_EMPTY && spare_512_PS(spare1)==SECTOR_EMPTY

/* MTK FDM signature mark */
#define BAD_BLOCK_MARK_2K   (0x4242)
#define BAD_BLOCK_MARK_512  (0x42)
#define MTK_SIGNATURE_MARK   (0x4B544D)
#define FDM_SIGNATURE_MARK   (0x4D4446)
#define FDM_CHECK_MARK_1  (0xF0)
#define FDM_CHECK_MARK_2  (0x0F)
#define FDM_NG_CONTROL_BLOCK_MARK  (0x8000)      /*This mark means the correct control block does not exist - Yehudi*/

#define FDM_TABLE_MARK_POSITION         (2)      /*Use by Control Table*/

/* MTK NAND FDM control block header layout */
#define FDM_CONTROL_BACKUP_POSITION     (256)
#define FDM_RESERVED_POOL_SIZE_POSITION (64)    /*Reserve 4 byte - Yehudi*/
#define FDM_VERSION_POSITION (68)               /*Reserve 4 byte - Yehudi*/

//#define FDM_REGION_BLOCK_POSITION (72)          /*Reserve 4 byte - Yehudi*/
//#define FDM_TIME_INFO_POSITION (76)             /*Reserve 8 byte - Yehudi*/
//#define FDM_CBLK_PROGRAM_COUNT_POSITION (80)    /*Reserve 4 byte - Yehudi*/
/*******************************************************************************
 * structure definition for spare area of 2k/512 page-size
 *******************************************************************************/
#ifdef __MTK_TARGET__
extern kal_bool INT_QueryExceptionStatus(void);
#else
#define INT_QueryExceptionStatus() (KAL_FALSE)

// pragma is used for specific bytes in a structure
    #pragma pack(1)
#endif

typedef struct control_block_header_tag
{
    kal_uint8   mtk_fdm_mark[64];
    kal_uint8   erase_pool_size;    /*position 64*/
    kal_uint8   reserve1[3];
    kal_uint16  version_info;       /*position 68*/
    kal_uint8   reserve2[2];
    kal_uint16  cur_region_block;   /*position 72*/
    kal_uint16  next_region_block;  /*position 74*/
    kal_uint32  create_time;        /*position 76*/
    kal_uint64  program_count;      /*position 80 (position at 8 byte alignment for PC )*/
}control_block_header; /*The total size should not over FDM_CONTROL_BACKUP_POSITION - Yehudi*/

typedef struct spare_2k_component_tag
{
    kal_uint16     BI;               // block info
    kal_uint8     SS;                // sector state
    kal_uint8     Reserved0;
    kal_uint32    LSN;           // logical sector number
    kal_uint32    ECC;
    kal_uint16     Reserved;     /*In FDM 4.3, spare[2].Reserved & spare[3].Reserved will put fdm_data_time_info_struct*/
    kal_uint16     LSN_Chk;
} spare_2k_component;

typedef struct spare_2k_tag
{
    spare_2k_component spare[4];
} spare_2k;

/* Use spare[3]'s Reserved0 as page state */
#define spare_2k_PS(p)          ( ((spare_2k*)(p))->spare[3].Reserved0 )
#define spare_2k_LCHK(p, s)     ( ((spare_2k*)(p))->spare[s].LSN_Chk )
#define spare_2k_VER(p)         ( ((spare_2k*)(p))->spare[0].LSN_Chk )
#define spare_2k_HCHK(p)        ( ((spare_2k*)(p))->spare[0].Reserved0 )


typedef struct spare_512_tag
{
    kal_uint32    ECC;
    kal_uint8     SS;         // sector state
    kal_uint8     BI;         // block info
    kal_uint8     Reserved[4]; /*In FDM 4.3, it will put fdm_data_time_info_struct*/ 
    kal_uint16    LSN_Chk;
    kal_uint32    LSN;        // logical sector number
} spare_512;

#define spare_512_PS(p)                 ( ((spare_512*)(p))->SS )
#define spare_512_LCHK(p)               ( ((spare_512*)(p))->LSN_Chk )
#define spare_512_VER(p)                ( ((spare_512*)(p))->LSN_Chk )
#define spare_512_HCHK(p)               ( ((spare_512*)(p))->Reserved[0] )

#ifndef __MTK_TARGET__
#pragma pack()
#endif



/*******************************************************************************
 * structure definition for driver data
 *******************************************************************************/
typedef struct flash_info_tag
{
    kal_uint32    id_data[2];
    kal_uint16     block_num;            /*total FAT block number, not include log block - Yehudi*/
    kal_uint8     region_num;
    kal_uint8     pages_per_block;
    kal_uint8     page_type;
    kal_uint8       address_cycle;
    kal_uint8       io_width;
    kal_uint8       log_block;           /*block number of log section - Yehudi*/
    kal_uint16     bad_num;
    kal_uint32    total_FAT_sectors;     // total sectors that FAT can use
    kal_uint32    partition_sectors;     // partiton sectors that FAT can use
    kal_uint32    region_sectors[MAX_REGION_NUM];  // LBB design

} flash_info_struct;


typedef struct region_info_tag
{

    kal_uint16     control_block[MAX_REGION_NUM];
    kal_uint16     region_block[MAX_REGION_NUM+1]; /*block number of the region - Yehudi*/
    kal_uint32     base_block;
    /* Adjust to be 4 byte alignment */

    kal_uint8     control_next_index[MAX_REGION_NUM]; // next programmable page
    kal_uint8     current_region;
    kal_uint8     erase_pool[MAX_REGION_NUM];   // LBB design
    kal_uint32    base_LSN;
    kal_uint32    end_LSN;
} region_info_struct;


typedef struct control_info_tag
{
    kal_uint16     physical_block;
    kal_uint8     next_index; // next programmable page index ?? -- kirk
    kal_uint8     modified_flag;
    kal_uint16     version;
} control_info_struct;


typedef struct control_table_tag
{
    kal_uint8     block_state[R_BLOCKS];        // physical block state
    kal_uint8     erase_count[R_BLOCKS];        // erase count of physical block
    kal_uint8     block_mapping[R_BLOCKS];      // map logical to physical block
} control_table_struct;

typedef struct ctrl_table_extra_info_tag
{
    kal_uint8   reserve1[2];
    kal_uint8   table_mark;             /* controbl table mark, must at position FDM_TABLE_MARK_POSITION*/
    kal_uint8   reserve2[9];
    kal_uint32  create_time;            /*position 12*/
    kal_uint64  program_count;          /*position 16 (position at 8 byte alignment for PC )*/
    kal_uint16  active_logical_block;
    kal_uint16  active_physical_block;
    kal_uint8   active_bmr_flag;
    kal_uint8   active_next_index;                            // next programmable page index
}ctrl_table_extra_info;

typedef enum
{
    CLOSE_REGION_MARK      = 0x20,
    NORMAL_SHUTDOWN_MARK   = 0x31,
    MERGEACTIVE_MARK1      = 0x40,
    MERGEACTIVE_MARK2      = 0x42,
    MERGEACTIVE_MARK3      = 0x44,
    RECONSTRUCTED_MARK     = 0x52,
    COPY_MARK              = 0x60,
    SPOT_MARK              = 0x62,
    NONE_MARK              = 0xFF
} ControblTableMark;

typedef struct active_info_tag
{
    kal_uint16     logical_block;                         // logical number of active block
    kal_uint16     physical_block;                        // physical number of active block
    kal_uint8     next_index;                            // next programmable page index
    kal_uint8     bmr_flag;                              // indicate if active block fits block mappingn rule
    /*kal_uint8     first_page;*/
    kal_uint8     page_mapping[MAX_PAGES_PER_BLOCK];     // map logical to physical page
} active_info_struct;


typedef struct sequential_info_tag
{
    kal_uint16     physical_block; // which physical block this information is for.
    kal_uint8     last_index;     // The page offset on which the last programming operation is performed.
} seq_info_struct;


typedef struct dup_block_tag
{
    kal_uint16 l_block;
    kal_uint16 p_block;
} dup_block_struct;


typedef  struct
{
    NAND_MTD_DRIVER         * MTD;

#ifndef __MTK_TARGET__
    const char              * file_name;
    void                    * flash_device;
#endif

    flash_info_struct        flash_info;
    region_info_struct       region_info;
    control_info_struct      control_info;
    control_table_struct     control_table;
    active_info_struct       active_info;
    seq_info_struct          seq_info;


    kal_uint32                       buffer[MAX_PAGE_SIZE/sizeof(kal_uint32)];
    kal_uint32                       spare0[MAX_SPARE_SIZE/sizeof(kal_uint32)];
    kal_uint32                       spare1[MAX_SPARE_SIZE/sizeof(kal_uint32)];
    //kal_uint32                     badspare[MAX_SPARE_SIZE/sizeof(kal_uint32)];//TODO: should check whether this is necessary

} NAND_FLASH_DRV_DATA;

typedef struct fdm_global_time_info_tag
{
    kal_uint32 Second:6;
    kal_uint32 Minute:6;
    kal_uint32 Hour:5;
    kal_uint32 Day:5;
    kal_uint32 Month:4;
    kal_uint32 Year2000:6;
} fdm_global_time_info_struct; 


typedef struct fdm_data_time_info_tag
{
    kal_uint32 Count:9;
    kal_uint32 Second:6;
    kal_uint32 Minute:6;
    kal_uint32 Hour:5;
    kal_uint32 Day:5;
    kal_uint32 Month:1;
} fdm_data_time_info_struct; 

typedef struct fdm_log_section_info_tag
{
    kal_uint8     is_init;
    kal_uint32    log_start_page;
    kal_uint32    total_page_num;
    kal_uint32    cur_page;
    kal_uint64    program_count;  /*position 16 (position at 8 byte alignment for PC simulator) */
    kal_uint32    buffer[MAX_PAGE_SIZE/sizeof(kal_uint32)]; 
    kal_uint32    spare0[MAX_SPARE_SIZE/sizeof(kal_uint32)];
    kal_uint32    spare1[MAX_SPARE_SIZE/sizeof(kal_uint32)];
} fdm_log_section_info_struct;
/*******************************************************************************
 * Definition for power loss test
 *******************************************************************************/
#if defined(FLASH_DISKDRV_DEBUG) && defined(POWERLOSS_TEST)

enum
{
    MERGE_ACTIVE = 1,
    COPY_BLOCK,
    WRITE_SECTORS,
    FLUSH_TABLE,
};

#include <setjmp.h>
extern jmp_buf mark;
extern int Test_CD_Value;
#define TEST_POINT(a)\
   {\
      switch(a)\
      {\
         case MERGE_ACTIVE:\
            Test_CD_Value-=1;\
                break;\
         case COPY_BLOCK:\
            Test_CD_Value-=1;\
                break;\
         case WRITE_SECTORS:\
            Test_CD_Value-=1;\
                break;\
         case FLUSH_TABLE:\
            Test_CD_Value-=1;\
                break;\
         default:\
            Test_CD_Value-=1;\
            break;\
       }\
      if(Test_CD_Value <= 0)\
         longjmp(mark, a);\
   }

#define START_POINT  setjmp(mark)

#else
#define TEST_POINT(a)
#define START_POINT
#endif

#if defined(FLASH_DISKDRV_DEBUG) && defined(ERROR_HANDLING_TEST)

/* for error handling test */

extern void ProgramPageFailure(kal_int32 times);
extern void ProgramSpareFailure(kal_int32 times);
extern void BlockEraseFailure(kal_int32 times);
extern void ReadPageFailure(kal_int32 times);
extern void ReadSpareFailure(kal_int32 times);

typedef enum
{
    PAGE_WRITE,
    SPARE_WRITE,
    PAGE_READ,
    SPARE_READ,
    BLOCK_ERASE,
    TOTAL_OPERATIONS
} Operation_Type;

typedef enum
{
    WRITEDATA_ACTIVE = 0,
    WRITEDATA_BLOCK,
    COPY_BLOCK,
    FLUSH_TABLE,
    MODIFY_TABLE,
    MERGE_ACTIVE,
    DELETE_PAGE,
    MARK_BAD_BLOCK,
    DISCARD_SECTOR,
    INITIALIZE_REGION_DATA,
    READSECTOR_512,
    READ_SECTOR_2K,
    READ_TABLE,
    READDATA_ACTIVE,
    READDATA_BLOCK,
    FIND_CONTROL_BAD_BLOCK,
    ERASE_BLOCK,
    FIND_TABLE,
    BLOCK_BMR,
    DELETEDATA_ACTIVE,
    DELETEDATA_BLOCK,
    POWER_RECOVERY,
    RECONSTRUCT_TABLE,
    RESTORE_DD,
    TOTAL_FUNCTIONS
} ErrorHandling_TestCase;

typedef struct
{
    kal_uint32                triggered;  // test enabled or not
    kal_uint32                step_id;    // determine which step is allowed to go
    ErrorHandling_TestCase    case_type;
    Operation_Type            op_type;
} test_command;

extern test_command test_item[];

#define TEST_ERROR_ENABLE(function, operation, step)\
{\
   test_item[function].triggered = 1;\
   test_item[function].op_type = operation;\
   test_item[function].case_type = function;\
   test_item[function].step_id = step;\
}

#define TEST_ERROR_DISABLE(function, operation, step)\
{\
   if( (function == test_item[function].case_type) &&\
       (step == test_item[function].step_id) )\
   {\
      test_item[function].triggered = 0;\
      test_item[function].op_type = TOTAL_OPERATIONS;\
      test_item[function].case_type = TOTAL_FUNCTIONS;\
      test_item[function].step_id = 0;\
   }\
}

/*   assert( function == test_item[function].case_type);\*/
#define TEST_ERROR_EVENT(function, step)\
{\
   if( test_item[function].triggered )\
   {\
      if( step == test_item[function].step_id )\
      {\
         if( PAGE_WRITE == test_item[function].op_type )\
         {\
            kal_print("Page program error is triggered!\n");\
            ProgramPageFailure(1);\
            test_item[function].triggered = 0;\
         }else if( SPARE_WRITE == test_item[function].op_type )\
         {\
            kal_print("Spare program error is triggered!\n");\
            ProgramSpareFailure(1);\
            test_item[function].triggered = 0;\
         } else if( PAGE_READ == test_item[function].op_type )\
         {\
            kal_print("Page read error is triggered!\n");\
            ReadPageFailure(1);\
            test_item[function].triggered = 0;\
         } else if( SPARE_READ == test_item[function].op_type )\
         {\
            kal_print("Spare read error is triggered!\n");\
            ReadSpareFailure(1);\
            test_item[function].triggered = 0;\
         } else if (BLOCK_ERASE == test_item[function].op_type)\
         {\
            kal_print("Block erase error is triggered!\n");\
            BlockEraseFailure(1);\
            test_item[function].triggered = 0;\
         }\
      }\
   }\
}

#else
#define TEST_ERROR_EVENT(function, step)
#endif


/*******************************************************************************
 *  FDM function declaration
 *******************************************************************************/
kal_int32 MountDevice       (void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);
kal_int32 ShutDown          (void * DriveData);
kal_int32 ReadSectors       (void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Data);
kal_int32 WriteSectors      (void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Data);
kal_int32 MediaChanged      (void * DriveData);
kal_int32 DiscardSectors    (void * DriveData, kal_uint32 Sector, kal_uint32 Sectors);
kal_int32 GetDiskGeometry   (void * DriveData, FS_PartitionRecord * DiskGeometry, kal_uint8 * MediaDescriptor);
kal_int32 LowLevelFormat    (void * DriveData, const kal_char * DeviceName, FS_FormatCallback Progress, kal_uint32 Flags);
kal_int32 PowerOnAssert_DriveFormat(void * DriveData);
int CopySectors(void *DriveData, kal_uint32 SrcSector , kal_uint32 DstSector, kal_uint32 Sectors);

/*******************************************************************************
 *  Sub-function declaration
 *******************************************************************************/
kal_int32 FindControlBadBlock(NAND_FLASH_DRV_DATA * D, kal_uint8 * control_num);
kal_uint8 IsGoodBlock(NAND_FLASH_DRV_DATA * D, void * Spare);
kal_uint8 ReadSector_512(NAND_FLASH_DRV_DATA * D, kal_uint32 Sector, kal_uint8 * Data);
kal_uint8 ReadSector_2k(NAND_FLASH_DRV_DATA * D, kal_uint32 Sector, kal_uint32 read_sectors, kal_uint8 * Data);
kal_uint8 WriteSector_512(NAND_FLASH_DRV_DATA * D, kal_uint32 Sector, kal_uint8 * Data);
kal_uint8 WriteSector_2k(NAND_FLASH_DRV_DATA * D, kal_uint32 Sector, kal_uint32 write_sectors, kal_uint8 * Data);
kal_uint32 MapSector(NAND_FLASH_DRV_DATA * D, kal_uint32 Sector);
void  LocateRegion(NAND_FLASH_DRV_DATA * D, kal_uint32 Sector);
kal_uint8 InitializeRegionData_byReadTableInfo(NAND_FLASH_DRV_DATA * D);  
void  InitializeRegionData(NAND_FLASH_DRV_DATA * D);
void  SelfFormat(NAND_FLASH_DRV_DATA * D, kal_int32 DeviceType);
kal_uint8  DeletePage(NAND_FLASH_DRV_DATA * D, kal_uint32 PageIndex);
kal_uint8  EraseBlock(NAND_FLASH_DRV_DATA *D, kal_uint32 BlockIndex);
kal_uint8  MarkBadBlock(NAND_FLASH_DRV_DATA * D, kal_uint32 BlockIndex);
kal_uint8  LocateBlock(NAND_FLASH_DRV_DATA *D);
kal_uint8  LocateEmptyBlock(NAND_FLASH_DRV_DATA *D);
kal_uint8  CopyBlock(NAND_FLASH_DRV_DATA *D, kal_uint8 sourceB, kal_uint8 sourceP, kal_uint8 *destinationB, kal_uint8 destinationP, kal_uint8 num);
kal_int32  FlushTable(NAND_FLASH_DRV_DATA *D, ControblTableMark mark_flag);
kal_uint8  ModifyTable(NAND_FLASH_DRV_DATA *D);
kal_bool  FindTable(NAND_FLASH_DRV_DATA *D);
kal_uint8  ReadTable(NAND_FLASH_DRV_DATA *D);
kal_uint8  Read_FoundTable(NAND_FLASH_DRV_DATA *D);
void  LocatePage(NAND_FLASH_DRV_DATA * D, kal_uint32 Sector, kal_bool readback);
kal_bool  BlockBMR(NAND_FLASH_DRV_DATA *D, kal_uint16 Block , kal_uint8 Offset);
kal_uint32 Writedata_Active(NAND_FLASH_DRV_DATA * D, kal_uint8 Offset, kal_uint8 * Data, kal_uint8 * Spare);
kal_uint32 Writedata_Block(NAND_FLASH_DRV_DATA * D, kal_uint16 Block, kal_uint8 Offset, kal_uint8 * Data, kal_uint8 * Spare);
void  Deletedata_Active(NAND_FLASH_DRV_DATA *D, kal_uint8 Offset);
void  Deletedata_Block(NAND_FLASH_DRV_DATA *D, kal_uint16 Block, kal_uint8 Offset);
void  Readdata_Active(NAND_FLASH_DRV_DATA *D, kal_uint8 Offset);
void  Readdata_Block(NAND_FLASH_DRV_DATA *D, kal_uint16 Block, kal_uint8 Offset);
void  MergeActive(NAND_FLASH_DRV_DATA *D);
void  PowerRecovery(NAND_FLASH_DRV_DATA * D);
void  ReconstructTable(NAND_FLASH_DRV_DATA * D, dup_block_struct dupB[2][2]);
void  DeleteAllControlBlock(NAND_FLASH_DRV_DATA * D);
void  ReconstructAllTable(NAND_FLASH_DRV_DATA * D);
void  RestoreAD(NAND_FLASH_DRV_DATA * D, dup_block_struct *dupB, kal_uint8 PageState0);
void  RestoreDD(NAND_FLASH_DRV_DATA * D, dup_block_struct *dupB);
kal_uint8 CreateControlBlock (NAND_FLASH_DRV_DATA* D);
kal_uint8 LimitControlLogBlockNumber (NAND_FLASH_DRV_DATA* D);
kal_bool MarkControlLogBlock(NAND_FLASH_DRV_DATA* D, kal_uint32 BlockOffset);
kal_bool Find_TableNewestProgramCounter (NAND_FLASH_DRV_DATA * D, kal_uint8 region);
kal_uint8 LogSectionInit (NAND_FLASH_DRV_DATA * D);
kal_uint8 WriteLog (NAND_FLASH_DRV_DATA * D, kal_char* message);
void  SC(NAND_FLASH_DRV_DATA * D);
void  SC_UT(NAND_FLASH_DRV_DATA * D);
/******************************************************************************
 * SuperAND flash device definition                                           *
 ******************************************************************************/
#if defined(WIN32) && defined(TRACE_ON)
#define FDM_TRACE   printf
#else
#define FDM_TRACE
#endif

#define SUPERAND_SECTOR_SIZE    2048
#define SUPERAND_FAT_API_ENTRANCE \
    Sector += D->first_fat_sector_offset;

typedef struct
{
    SuperAND_MTD_DRIVER     * MTD;

#ifndef __MTK_TARGET__
    const char              * file_name;
    void                    * flash_device;
#endif
    kal_uint8                    io_width;
    kal_uint32                   pages_of_first_device;
    kal_uint32                   pages_of_block;
    kal_uint32                  block_mask;
    kal_uint32                   total_pages;

    kal_uint32                   first_fat_sector_offset;
    kal_uint32                   total_fat_sectors;
    kal_uint32                   partition_sectors;

    kal_uint32                   buffer[SUPERAND_SECTOR_SIZE/sizeof(kal_uint32)];
} SuperAND_FLASH_DRV_DATA;

#define SUPERAND_MOUNTED    0x1000

void SuperAND_FDM_Init(void);
void SuperAND_SelfFormat(SuperAND_FLASH_DRV_DATA *D, kal_int32 DeviceType);

kal_int32 SuperAND_FDM_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);
kal_int32 SuperAND_FDM_ShutDown(void * DriveData);
kal_int32 SuperAND_FDM_ReadSectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);
kal_int32 SuperAND_FDM_WriteSectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);
kal_int32 SuperAND_FDM_MediaChanged(void * DriveData);
kal_int32 SuperAND_FDM_DiscardSectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors);
kal_int32 SuperAND_FDM_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, kal_uint8 * MediaDescriptor);
kal_int32 SuperAND_FDM_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, kal_uint8 * MediaDescriptor);
kal_int32 SuperAND_FDM_LowLevelFormat(void * DriveData, const char * DeviceName, FS_FormatCallback Progress, kal_uint32 Flags);
kal_int32 SuperAND_FDM_NonBlockWriteSectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);
kal_int32 SuperAND_FDM_RecoverableWriteSectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);
kal_int32 SuperAND_FDM_ResumeSectorStates(void  * DriveData);
kal_int32 SuperAND_FDM_HighLevelFormat(void);
kal_int32 SuperAND_FDM_FlushData(void * DriveData);
kal_int32 SuperAND_FDM_CopySectors(void * DriveData, kal_uint32 SrcSector, kal_uint32 DstSector, kal_uint32 Sectors);

#endif /* NAND_FDM_H */

