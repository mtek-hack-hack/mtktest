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
 *  ResMemMgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Resource Memory Sharing Manager
 *
 *  It is for resource memory management in Enhanced NFB (ENFB) platform.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#if !defined(__MTK_TARGET__)
#define UNICODE

#include <stdio.h>
#include "Windows.h"
#endif /* !defined(__MTK_TARGET__) */ 

#if !defined(__MTK_TARGET__)
#define _WINDOWS_       /* to solve redefine prbolem */
#endif 

#include "kal_non_specific_general_types.h"
#include "kal_release.h"
#include "MMI_features.h"

#include "stdC.h"
#include "GlobalDefs.h"
#include "DebugInitDef.h"
#include "ResMemMgrGprot.h"
#include "CustDataRes.h"
#include "gdi_include.h"

#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)
#include "CustENFBStr.h"
#include "nfb_loader.h"
#endif /* defined(__MMI_RESOURCE_ENFB_SUPPORT__) */ 

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define MMI_FRM_RESMEM_CS_ENTER  GDI_LOCK
#define MMI_FRM_RESMEM_CS_LEAVE  GDI_UNLOCK

/* Invalid resoruce ID */
#define MMI_FRM_RESMEM_INVALID_RES_ID          0xFFFF

/*----------------------------------------------------------------*
  Image resource                                                 
 *----------------------------------------------------------------*/

/* Unit test */
// #define MMI_FRM_RESMEM_UNIT_TEST

/* Enable debugging invalid pointer usage by application */
// #define MMI_FRM_RESMEM_DEBUG_DANGLING_POINTER

#if defined(MMI_FRM_RESMEM_DEBUG_DANGLING_POINTER)
#define MMI_FRM_RESMEM_LOAD_ON_DEMAND_SCREEN_NUMBER    5
#define MMI_FRM_RESMEM_SPOT_ICON_RESERVED_SIZE         300
#else /* defined(MMI_FRM_RESMEM_DEBUG_DANGLING_POINTER) */ 
#define MMI_FRM_RESMEM_LOAD_ON_DEMAND_SCREEN_NUMBER    1
#endif /* defined(MMI_FRM_RESMEM_DEBUG_DANGLING_POINTER) */ 

/* size of memory pool
   the size is adjustable */
#define MMI_FRM_RESMEM_POOL_LOD_ON_DEMAND_SIZE  (750 * 1024)    /* 750 K */
#define MMI_FRM_RESMEM_POOL_ALWASY_EXIST_SIZE   (200 * 1024)    /* 200 K */

/* maximum number of records for keeping memory allocation informaiton
   the number is adjustable */
#define MMI_FRM_RESMEM_LOAD_ON_DEMAND_NUMBER    100
#define MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER      20

#if !defined(__MTK_TARGET__)
/* destination file for simulating loading via driver */

#define MMI_FRM_RESMEM_IMAGE_FILE   L"..\\MoDIS\\CustENFBImgData"       /* relative to fssim_root_dir (mcu\MoDIS\WIN32FS\) */

#endif /* !defined(__MTK_TARGET__) */ 

/*----------------------------------------------------------------*
  String resource
 *----------------------------------------------------------------*/

#if !defined(__MTK_TARGET__)
/* destination file for simulating loading via driver */

#define MMI_FRM_RESMEM_STRING_FILE     L"..\\MoDIS\\CustENFBStrData"
 
#endif /* !defined(__MTK_TARGET__) */ 

/* string suite memory buffer size */
#define MMI_FRM_RESMEM_POOL_STR_RAM_SIZE  (MaxENFBStringSize)   /* bytes */

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/*----------------------------------------------------------------*
  Image resource                                                 
 *----------------------------------------------------------------*/

typedef struct
{
    U16 id;
    U8 *mem_ptr;
    U32 size;
} mmi_frm_resmem_alloc_struct;

/*----------------------------------------------------------------*
  String resource
 *----------------------------------------------------------------*/

/*----------------------------------------------------------------*
  Common
 *----------------------------------------------------------------*/
/* internal context struct */
typedef struct
{
    mmi_frm_resmem_alloc_struct
        lod_ary[MMI_FRM_RESMEM_LOAD_ON_DEMAND_SCREEN_NUMBER][MMI_FRM_RESMEM_LOAD_ON_DEMAND_NUMBER];
    mmi_frm_resmem_alloc_struct always_ary[MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER];
    U16 always_keep_ID[MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER];
    KAL_ADM_ID adm_lod_id[MMI_FRM_RESMEM_LOAD_ON_DEMAND_SCREEN_NUMBER];
    KAL_ADM_ID adm_always_id;
    U8 lod_active_screen;

    /* for adjustment */
    U32 lod_mem_using;
    U32 lod_mem_max_used;
    U32 always_mem_using;
    U32 always_mem_max_used;

    /* string part */
    U8 *str_content;
    U8 *str_map;
} mmi_frm_resmem_context_struct;

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)

static mmi_frm_resmem_context_struct g_mmi_frm_resmem_cntx;

/*----------------------------------------------------------------*
  Image resource                                                 
 *----------------------------------------------------------------*/
/* memory pool */
#ifdef __MTK_TARGET__
#pragma arm section zidata = "LARGEPOOL_ZI"
#endif 

static U8
    g_mmi_frm_resmem_lod_pool[MMI_FRM_RESMEM_LOAD_ON_DEMAND_SCREEN_NUMBER][MMI_FRM_RESMEM_POOL_LOD_ON_DEMAND_SIZE];
static U8 g_mmi_frm_resmem_always_pool[MMI_FRM_RESMEM_POOL_ALWASY_EXIST_SIZE];

#ifdef __MTK_TARGET__
#pragma arm section zidata
#endif 

/* for KAL ADM */
static const kal_uint32 g_mmi_frm_resmem_mem_pool_chunk_size[11] = 
{
    16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 0xffffffff, 0
};

/*----------------------------------------------------------------*
  String resource
 *----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
#pragma arm section zidata = "LARGEPOOL_ZI"
#endif 

/* force (1) start address to 4-alignment and (2) size to 4N */
static U32 g_mmi_frm_resmem_str_pool[(MMI_FRM_RESMEM_POOL_STR_RAM_SIZE+3)/4];

#ifdef __MTK_TARGET__
#pragma arm section zidata
#endif 

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/

/*----------------------------------------------------------------*
  Image resource                                                 
 *----------------------------------------------------------------*/

#if !defined(__MTK_TARGET__)

/*****************************************************************************
 * FUNCTION
 *  NFB_RES_Load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cid             [IN]        
 *  dst_addr        [?]         [?]
 *  offset          [IN]        
 *  length          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool NFB_RES_Load(kal_uint8 cid, void *dst_addr, kal_uint32 offset, kal_uint32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define TCHAR_BUFFER_SIZE 512
    HANDLE hFile;
    int ret = 0;
    int size = length;
    char *buf = (char*)dst_addr;
    U32 bytesRead;
    TCHAR tchBuffer[TCHAR_BUFFER_SIZE];
    extern TCHAR fssim_root_dir[];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetCurrentDirectory(TCHAR_BUFFER_SIZE, tchBuffer);

    if (cid == ENFB_CONTENT_IMAGERES)
    {
        wcscpy(tchBuffer, fssim_root_dir);
        wcscat(tchBuffer, MMI_FRM_RESMEM_IMAGE_FILE);
    }
    else if (cid == ENFB_CONTENT_STRINGRES)
    {
        wcscpy(tchBuffer, fssim_root_dir);
        wcscat(tchBuffer, MMI_FRM_RESMEM_STRING_FILE);
    }
    else
    {
        MMI_ASSERT(0);
    }

    hFile = CreateFile(tchBuffer, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        MMI_ASSERT(0);
        exit(1);
    }
    SetFilePointer(hFile, offset, NULL, FILE_BEGIN);
    ret = ReadFile(hFile, dst_addr, (DWORD) length, &bytesRead, NULL);

    CloseHandle(hFile);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  NFB_RES_Loadv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cid                 [IN]        
 *  scatter             [?]         [?]
 *  scatter_number      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool NFB_RES_Loadv(kal_uint8 cid, enfb_scatter *scatter, kal_uint32 scatter_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < scatter_number; i++)
    {
        NFB_RES_Load(cid, scatter[i].dst_addr, scatter[i].offset, scatter[i].length);
    }

    return TRUE;
}

#endif /* !defined(__MTK_TARGET__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_rec_add
 * DESCRIPTION
 *  add record of resource memory occupation
 * PARAMETERS
 *  mem_type        [IN]        Memory type
 *  id              [IN]        Resource ID
 *  ptr             [IN]        Pointer to resource in RAM
 *  size            [IN]        Size of the resource
 * RETURNS
 *  When succeed MMI_TRUE; otherwise MMI_FALSE
 *****************************************************************************/
static MMI_BOOL mmi_frm_resmem_rec_add(mmi_frm_resmem_enum mem_type, U16 id, U8 *ptr, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, number = 0;
    mmi_frm_resmem_alloc_struct *rec = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(id != MMI_FRM_RESMEM_INVALID_RES_ID);
    MMI_ASSERT(ptr != NULL);

    if (mem_type == MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND)
    {
        number = MMI_FRM_RESMEM_LOAD_ON_DEMAND_NUMBER;
        rec = g_mmi_frm_resmem_cntx.lod_ary[g_mmi_frm_resmem_cntx.lod_active_screen];
    }
    else if (mem_type == MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST)
    {
        number = MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER;
        rec = g_mmi_frm_resmem_cntx.always_ary;
    }
    else
    {
        MMI_ASSERT(0);
    }

    for (i = 0; i < number; i++, rec++)
    {
        if (rec->mem_ptr == NULL)
        {
            MMI_ASSERT(rec->id == MMI_FRM_RESMEM_INVALID_RES_ID);
            rec->id = id;
            rec->mem_ptr = ptr;
            rec->size = size;
            return MMI_TRUE;
        }
    }

    /* empty item is no found. Call the module's owner to handle this situation */
    MMI_ASSERT(0);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_rec_del
 * DESCRIPTION
 *  init the module
 * PARAMETERS
 *  mem_type        [IN]        Memory type
 *  id              [IN]        Resource ID
 * RETURNS
 *  resource pointer; NULL if no record allocated
 *****************************************************************************/
static U8 *mmi_frm_resmem_rec_del(mmi_frm_resmem_enum mem_type, U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, number = 0;
    mmi_frm_resmem_alloc_struct *rec = NULL;
    U8 *ret_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(id != MMI_FRM_RESMEM_INVALID_RES_ID);

    if (mem_type == MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND)
    {
        number = MMI_FRM_RESMEM_LOAD_ON_DEMAND_NUMBER;
        rec = g_mmi_frm_resmem_cntx.lod_ary[g_mmi_frm_resmem_cntx.lod_active_screen];
    }
    else if (mem_type == MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST)
    {
        number = MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER;
        rec = g_mmi_frm_resmem_cntx.always_ary;
    }
    else
    {
        MMI_ASSERT(0);
    }

    for (i = 0; i < number; i++, rec++)
    {
        if (rec->id == id)
        {
            rec->id = MMI_FRM_RESMEM_INVALID_RES_ID;
            ret_ptr = rec->mem_ptr;
            rec->mem_ptr = NULL;
            return ret_ptr;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_rec_del_one
 * DESCRIPTION
 *  delete one record of resource memory occupation, if available
 * PARAMETERS
 *  mem_type            [IN]        Memory type
 *  which_screen        [IN]        Which screen, indentifying what managment table to do the deleting. only valid for LOD
 *  id                  [OUT]       Which ID. If not interested, pass in NULL
 * RETURNS
 *  resource pointer; NULL if no record allocated
 *****************************************************************************/
static U8 *mmi_frm_resmem_rec_del_one(mmi_frm_resmem_enum mem_type, U16 which_screen, U16 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, number = 0;
    mmi_frm_resmem_alloc_struct *rec = NULL;
    U8 *ret_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mem_type == MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND)
    {
        MMI_ASSERT(which_screen < MMI_FRM_RESMEM_LOAD_ON_DEMAND_SCREEN_NUMBER);
        number = MMI_FRM_RESMEM_LOAD_ON_DEMAND_NUMBER;
        rec = g_mmi_frm_resmem_cntx.lod_ary[which_screen];
    }
    else if (mem_type == MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST)
    {
        number = MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER;
        rec = g_mmi_frm_resmem_cntx.always_ary;
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* TBD. enhance performance */
    for (i = 0; i < number; i++, rec++)
    {
        if (rec->id != MMI_FRM_RESMEM_INVALID_RES_ID)
        {
            MMI_ASSERT(rec->mem_ptr != NULL);

            if (id != NULL)
            {
                *id = rec->id;
            }
            ret_ptr = rec->mem_ptr;
            rec->id = MMI_FRM_RESMEM_INVALID_RES_ID;
            rec->mem_ptr = NULL;
            rec->size = 0;
            return ret_ptr;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_rec_if_exist
 * DESCRIPTION
 *  query whether the resource is existing in memory based on records
 * PARAMETERS
 *  flag        [IN]        Bit-wise flag: combination of MMI_FRM_RESMEM_MEMORY_LOAD_ON_DEMAND, MMI_FRM_RESMEM_MEMORY_ALWAYS_EXIST
 *  id          [IN]        Resource ID
 *  size        [OUT]       Place to receive resource size. It not of interest, pass in NULL
 * RETURNS
 *  if exist, return the memory pointer; otherwise, NULL
 *****************************************************************************/
static U8 *mmi_frm_resmem_rec_if_exist(U32 flag, U16 id, U32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, i, number;
    mmi_frm_resmem_alloc_struct *rec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((flag & (~(MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST | MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND))) == 0);
    MMI_ASSERT(id != MMI_FRM_RESMEM_INVALID_RES_ID);

    for (j = 0;; j++)
    {
        if (j == 0)
        {
            if (flag & MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST)
            {
                number = MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER;
                rec = g_mmi_frm_resmem_cntx.always_ary;
            }
            else
            {
                continue;
            }
        }
        else if (j == 1)
        {
            if (flag & MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND)
            {
                number = MMI_FRM_RESMEM_LOAD_ON_DEMAND_NUMBER;
                rec = g_mmi_frm_resmem_cntx.lod_ary[g_mmi_frm_resmem_cntx.lod_active_screen];
            }
            else
            {
                continue;
            }
        }
        else
        {
            /* not found */
            break;
        }

        for (i = 0; i < number; i++, rec++)
        {
            if (rec->id == id)
            {
                if (size != NULL)
                {
                    *size = rec->size;
                }
                return rec->mem_ptr;
            }
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_if_res_to_always_keep
 * DESCRIPTION
 *  query whether to keep the specified resource
 * PARAMETERS
 *  id      [IN]        Resource ID
 * RETURNS
 *  MMI_TRUE if necessary
 *****************************************************************************/
static MMI_BOOL mmi_frm_resmem_if_res_to_always_keep(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER; i++)
    {
        if (g_mmi_frm_resmem_cntx.always_keep_ID[i] == id)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

#ifdef MMI_FRM_RESMEM_UNIT_TEST


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_unit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_resmem_unit_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_resmem_init();

    /* test case: load single image */
    {
        ptr = mmi_frm_resmem_if_ramed(2);
        mmi_frm_resmem_load_single_image(2, 2000, 22);
        mmi_frm_resmem_load_single_image(4, 4000, 444);
        mmi_frm_resmem_load_single_image(5, 5000, 5555);
        ptr = mmi_frm_resmem_load_single_image(4, 4000, 444);
        ptr = mmi_frm_resmem_if_ramed(2);
    }

    /* test case: reset LOD memory */
    {
        mmi_frm_resmem_reset(MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND);
        ptr = mmi_frm_resmem_if_ramed(2);
    }

    /* test case: load array image */
    {
        static mmi_frm_resmem_res_info_struct info_array[10];

        ptr = mmi_frm_resmem_if_ramed(7);
        info_array[0].id = 1;
        info_array[0].offset = 1000;
        info_array[0].size = 111;
        info_array[1].id = 2;
        info_array[1].offset = 2000;
        info_array[1].size = 222;
        info_array[2].id = 7;
        info_array[2].offset = 7000;
        info_array[2].size = 777;
        info_array[3].id = 8;
        info_array[3].offset = 8000;
        info_array[3].size = 888;
        ptr = mmi_frm_resmem_load_multi_image(7, info_array, 4);
        ptr = mmi_frm_resmem_if_ramed(7);
    }

    /* test case: load single image */
    {
        U16 i;

        ptr = mmi_frm_resmem_if_ramed(15);
        for (i = 1; i < 20; i++)
        {
            mmi_frm_resmem_load_single_image(i, i * 20, i * 20);
        }
        ptr = mmi_frm_resmem_if_ramed(10);
    }

    /* test case: load image to Always Exist area */
    {
        U16 i;

        ptr = mmi_frm_resmem_if_ramed(21);
        for (i = 10; i < 30; i++)
        {
            mmi_frm_resmem_reg_retain(i);
            mmi_frm_resmem_load_single_image(i, i * 20, i * 20);
        }
        ptr = mmi_frm_resmem_if_ramed(21);
    }

    /* test case: remove image from Always Exist area */
    {
        U16 i;

        ptr = mmi_frm_resmem_if_ramed(21);
        for (i = 10; i < 30; i++)
        {
            mmi_frm_resmem_dereg_retain(i);
        }
        ptr = mmi_frm_resmem_if_ramed(21);
    }
    return;
}
#endif /* MMI_FRM_RESMEM_UNIT_TEST */ 

/*****************************************************************************              
 * Extern Global Variable                                                                    
 *****************************************************************************/

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_init
 * DESCRIPTION
 *  init the module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_resmem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mmi_frm_resmem_cntx, 0, sizeof(mmi_frm_resmem_context_struct));

    /* init ID table */
    for (j = 0; j < MMI_FRM_RESMEM_LOAD_ON_DEMAND_SCREEN_NUMBER; j++)
    {
        for (i = 0; i < MMI_FRM_RESMEM_LOAD_ON_DEMAND_NUMBER; i++)
        {
            g_mmi_frm_resmem_cntx.lod_ary[j][i].id = MMI_FRM_RESMEM_INVALID_RES_ID;
        }
    }
    for (i = 0; i < MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER; i++)
    {
        g_mmi_frm_resmem_cntx.always_ary[i].id = MMI_FRM_RESMEM_INVALID_RES_ID;
    }

    /* init retain-ID registration table */
    for (i = 0; i < MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER; i++)
    {
        g_mmi_frm_resmem_cntx.always_keep_ID[i] = MMI_FRM_RESMEM_INVALID_RES_ID;
    }

    /* init malloc record table */
    for (i = 0; i < MMI_FRM_RESMEM_LOAD_ON_DEMAND_SCREEN_NUMBER; i++)
    {
        g_mmi_frm_resmem_cntx.adm_lod_id[i] = kal_adm_create(
                                                g_mmi_frm_resmem_lod_pool[i],
                                                MMI_FRM_RESMEM_POOL_LOD_ON_DEMAND_SIZE,
                                                (kal_uint32*) g_mmi_frm_resmem_mem_pool_chunk_size,
                                                KAL_TRUE);
        MMI_ASSERT(g_mmi_frm_resmem_cntx.adm_lod_id[i] != (KAL_ADM_ID) NULL);
    }

    g_mmi_frm_resmem_cntx.adm_always_id = kal_adm_create(
                                            g_mmi_frm_resmem_always_pool,
                                            MMI_FRM_RESMEM_POOL_ALWASY_EXIST_SIZE,
                                            (kal_uint32*) g_mmi_frm_resmem_mem_pool_chunk_size,
                                            KAL_TRUE);
    MMI_ASSERT(g_mmi_frm_resmem_cntx.adm_always_id != (KAL_ADM_ID) NULL);

    g_mmi_frm_resmem_cntx.lod_active_screen = 0;

#if !defined(__MTK_TARGET__)
    FS_SanityCheck();
#endif /* !defined(__MTK_TARGET__) */ 

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_if_ramed
 * DESCRIPTION
 *  check whether the memory of the specified resource is existing in memory.
 * PARAMETERS
 *  id      [IN]        Resource ID
 * RETURNS
 *  if exist, the pointer of RAM ; otherwise, NULL
 *****************************************************************************/
U8 *mmi_frm_resmem_if_ramed(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_RESMEM_CS_ENTER;
    MMI_ASSERT(id != MMI_FRM_RESMEM_INVALID_RES_ID);

    ret = mmi_frm_resmem_rec_if_exist((MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST | MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND), id, NULL);
    MMI_FRM_RESMEM_CS_LEAVE;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_load_single_image
 * DESCRIPTION
 *  load the specified resource into memory.
 * PARAMETERS
 *  id          [IN]        Resource ID
 *  offset      [IN]        Offset in bin
 *  size        [IN]        Resource size
 * RETURNS
 *  memory pointer; NULL if not successful
 *****************************************************************************/
U8 *mmi_frm_resmem_load_single_image(U16 id, U32 offset, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf_size;
    U8 *ret_ptr = NULL;
    kal_bool kal_rslt;
    KAL_ADM_ID adm_id;
    MMI_BOOL ret_bool;
    mmi_frm_resmem_enum mem_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_RESMEM_CS_ENTER;

    MMI_ASSERT(id != MMI_FRM_RESMEM_INVALID_RES_ID);
    MMI_ASSERT(size != 0);

    /* check whether already exist in RAM */
    ret_ptr = mmi_frm_resmem_if_ramed(id);
    if (ret_ptr != NULL)
    {
        MMI_FRM_RESMEM_CS_LEAVE;
        return ret_ptr;
    }

    /* decide which kind of memory */
    if (mmi_frm_resmem_if_res_to_always_keep(id) == MMI_TRUE)
    {
        mem_type = MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST;
        adm_id = g_mmi_frm_resmem_cntx.adm_always_id;
    }
    else
    {
        mem_type = MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND;
        adm_id = g_mmi_frm_resmem_cntx.adm_lod_id[g_mmi_frm_resmem_cntx.lod_active_screen];
    }

    MMI_ASSERT(adm_id != (KAL_ADM_ID) NULL);

    /* allocate RAM block */
    buf_size = size;
#if defined(MMI_FRM_RESMEM_DEBUG_DANGLING_POINTER)
    buf_size = (buf_size >= MMI_FRM_RESMEM_SPOT_ICON_RESERVED_SIZE ? buf_size : MMI_FRM_RESMEM_SPOT_ICON_RESERVED_SIZE);
#endif 
    ret_ptr = kal_adm_alloc(adm_id, buf_size);
    /* Check memory alloc success or not. 
       If assertion failure here, maybe result from
       - image/animation/video size increased, or
       - more images are added in one screen, or
       - mmi_frm_resmem_reset() is not called when screen change, or
       - macro MMI_FRM_RESMEM_POOL_LOD_ON_DEMAND_SIZE value is too small */
    MMI_ASSERT(ret_ptr != NULL);
    /* 4-byte alignment for GDI API requirement, at least necessary for target */
    MMI_ASSERT(((U32) ret_ptr & 0x00000003) == 0);

    if (mem_type == MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND)
    {
        g_mmi_frm_resmem_cntx.lod_mem_using += buf_size;
        if (g_mmi_frm_resmem_cntx.lod_mem_using > g_mmi_frm_resmem_cntx.lod_mem_max_used)
        {
            g_mmi_frm_resmem_cntx.lod_mem_max_used = g_mmi_frm_resmem_cntx.lod_mem_using;
            MMI_ASSERT(g_mmi_frm_resmem_cntx.lod_mem_max_used < MMI_FRM_RESMEM_POOL_LOD_ON_DEMAND_SIZE);
        }
    }
    else
    {
        g_mmi_frm_resmem_cntx.always_mem_using += buf_size;
        if (g_mmi_frm_resmem_cntx.always_mem_using > g_mmi_frm_resmem_cntx.always_mem_max_used)
        {
            g_mmi_frm_resmem_cntx.always_mem_max_used = g_mmi_frm_resmem_cntx.always_mem_using;
            MMI_ASSERT(g_mmi_frm_resmem_cntx.always_mem_max_used < MMI_FRM_RESMEM_POOL_ALWASY_EXIST_SIZE);
        }
    }

    /* load via driver */
    kal_rslt = NFB_RES_Load(ENFB_CONTENT_IMAGERES, (void*)ret_ptr, offset, size);
    MMI_ASSERT(kal_rslt == KAL_TRUE);
    if (kal_rslt == KAL_FALSE)
    {
        kal_adm_free(adm_id, ret_ptr);
        ret_ptr = NULL;
        MMI_FRM_RESMEM_CS_LEAVE;
        return NULL;
    }

    /* update managment records */
    ret_bool = mmi_frm_resmem_rec_add(mem_type, id, ret_ptr, size);
    MMI_ASSERT(ret_bool == MMI_TRUE);

    MMI_FRM_RESMEM_CS_LEAVE;
    return ret_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_load_multi_image
 * DESCRIPTION
 *  load the specified resource into memory. Since the resource in in a
 *  multi-res pack, it is better to one, rather than multiple, access to ROM.
 * PARAMETERS
 *  id              [IN]        Resource ID
 *  info_array      [IN]        Array the stores the resource-pack info, which allows single access
 *  res_cnt         [IN]        The number of resource in info_array
 * RETURNS
 *  memory pointer; NULL if not successful
 *****************************************************************************/
U8 *mmi_frm_resmem_load_multi_image(U16 id, const mmi_frm_resmem_res_info_struct *info_array, U32 res_cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf_size;
    U8 i;
    U8 *ret_ptr = 0;
    static enfb_scatter scatter[MMI_FRM_RESMEM_SCATTER_MAX_NUMBER];
    kal_bool kal_rslt;
    KAL_ADM_ID adm_id;
    MMI_BOOL ret_bool;
    mmi_frm_resmem_enum mem_type;
    const mmi_frm_resmem_res_info_struct *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_RESMEM_CS_ENTER;

    MMI_ASSERT(id != MMI_FRM_RESMEM_INVALID_RES_ID);
    MMI_ASSERT(info_array != 0);
    MMI_ASSERT(res_cnt != 0);
    MMI_ASSERT(res_cnt < MMI_FRM_RESMEM_SCATTER_MAX_NUMBER);

    /* check whether already exist in in RAM */
    ret_ptr = mmi_frm_resmem_if_ramed(id);
    if (ret_ptr != NULL)
    {
        MMI_FRM_RESMEM_CS_LEAVE;
        return ret_ptr;
    }

    /* decide which kind of memory */
    if (mmi_frm_resmem_if_res_to_always_keep(id) == MMI_TRUE)
    {
        mem_type = MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST;
        adm_id = g_mmi_frm_resmem_cntx.adm_always_id;
    }
    else
    {
        mem_type = MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND;
        adm_id = g_mmi_frm_resmem_cntx.adm_lod_id[g_mmi_frm_resmem_cntx.lod_active_screen];
    }
    MMI_ASSERT(adm_id != (KAL_ADM_ID) NULL);

    /* allocate RAM block */
    for (i = 0, info = info_array; i < res_cnt; i++, info++)
    {
        buf_size = info->size;

    #if defined(MMI_FRM_RESMEM_DEBUG_DANGLING_POINTER)
        buf_size =
            (buf_size >= MMI_FRM_RESMEM_SPOT_ICON_RESERVED_SIZE ? buf_size : MMI_FRM_RESMEM_SPOT_ICON_RESERVED_SIZE);
    #endif /* defined(MMI_FRM_RESMEM_DEBUG_DANGLING_POINTER) */ 
        ret_ptr = kal_adm_alloc(adm_id, buf_size);
        MMI_ASSERT(ret_ptr != NULL);
        /* 4-byte alignment for GDI API requirement, at least necessary for target */
        MMI_ASSERT(((U32) ret_ptr & 0x00000003) == 0);

        scatter[i].dst_addr = ret_ptr;
        scatter[i].offset = info->offset;
        scatter[i].length = info->size;

        if (mem_type == MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND)
        {
            g_mmi_frm_resmem_cntx.lod_mem_using += buf_size;
            if (g_mmi_frm_resmem_cntx.lod_mem_using > g_mmi_frm_resmem_cntx.lod_mem_max_used)
            {
                g_mmi_frm_resmem_cntx.lod_mem_max_used = g_mmi_frm_resmem_cntx.lod_mem_using;
                MMI_ASSERT(g_mmi_frm_resmem_cntx.lod_mem_max_used < MMI_FRM_RESMEM_POOL_LOD_ON_DEMAND_SIZE);
            }
        }
        else
        {
            g_mmi_frm_resmem_cntx.always_mem_using += buf_size;
            if (g_mmi_frm_resmem_cntx.always_mem_using > g_mmi_frm_resmem_cntx.always_mem_max_used)
            {
                g_mmi_frm_resmem_cntx.always_mem_max_used = g_mmi_frm_resmem_cntx.always_mem_using;
            }
            MMI_ASSERT(g_mmi_frm_resmem_cntx.always_mem_max_used < MMI_FRM_RESMEM_POOL_ALWASY_EXIST_SIZE);
        }
    }

    /* load via driver */
    kal_rslt = NFB_RES_Loadv(ENFB_CONTENT_IMAGERES, scatter, res_cnt);
    MMI_ASSERT(kal_rslt == KAL_TRUE);
    if (kal_rslt == KAL_FALSE)
    {
        for (i = 0; i < res_cnt; i++)
        {
            kal_adm_free(adm_id, scatter[i].dst_addr);
        }
        ret_ptr = NULL;
        MMI_FRM_RESMEM_CS_LEAVE;
        return NULL;
    }

    /* update managment records */
    for (i = 0, info = info_array; i < res_cnt; i++, info++)
    {
        ret_bool = mmi_frm_resmem_rec_add(mem_type, info->id, scatter[i].dst_addr, scatter[i].length);
        MMI_ASSERT(ret_bool == MMI_TRUE);

        if (id == info->id)
        {
            ret_ptr = scatter[i].dst_addr;
        }
    }

    MMI_FRM_RESMEM_CS_LEAVE;
    return ret_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_reset
 * DESCRIPTION
 *  reset the occupied memory whose type is specified
 * PARAMETERS
 *  flag        [IN]        Bit-wise flag: combination of MMI_FRM_RESMEM_MEMORY_LOAD_ON_DEMAND, MMI_FRM_RESMEM_MEMORY_ALWAYS_EXIST
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_resmem_reset(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *mem_addr;
    S32 i;
    U16 id;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_RESMEM_CS_ENTER;

    if (flag & MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND)
    {

    #if defined(MMI_FRM_RESMEM_DEBUG_DANGLING_POINTER)
        /* display "X" icon for invlaid pointer usage */
        U16 number;
        mmi_frm_resmem_alloc_struct *rec;
	    U8 *res_src = NULL;

        number = MMI_FRM_RESMEM_LOAD_ON_DEMAND_NUMBER;
        rec = g_mmi_frm_resmem_cntx.lod_ary[g_mmi_frm_resmem_cntx.lod_active_screen];

        for (i = 0; i < number; i++, rec++)
        {
            if (rec->mem_ptr != NULL)
            {
                /* dangling pointer. fill in special icon. this icon is not in 3rd ROM */
                res_src = NULL;
                res_src = (U8*) GetImage(IMG_GLOBAL_DEFAULT);
                MMI_ASSERT(res_src != NULL);
                size = ((S32) (res_src[2]) |
                        (S32) ((S32) res_src[3] << 8) |
                        (S32) ((S32) res_src[4] << 16) | (S32) ((S32) res_src[5] << 24));
                MMI_ASSERT(MMI_FRM_RESMEM_SPOT_ICON_RESERVED_SIZE > size);
                memcpy((char*)rec->mem_ptr, res_src, size);
                rec->size = size;
            }
        }
        /* prepare the memory for next screen usage */
        g_mmi_frm_resmem_cntx.lod_active_screen++;
        g_mmi_frm_resmem_cntx.lod_active_screen %= MMI_FRM_RESMEM_LOAD_ON_DEMAND_SCREEN_NUMBER;

    #else /* defined(MMI_FRM_RESMEM_DEBUG_DANGLING_POINTER) */ 
        MMI_ASSERT(g_mmi_frm_resmem_cntx.lod_active_screen == 0);
    #endif /* defined(MMI_FRM_RESMEM_DEBUG_DANGLING_POINTER) */ 

        /* delete and create again */
        do
        {
            mem_addr = mmi_frm_resmem_rec_del_one(
                        MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND,
                        g_mmi_frm_resmem_cntx.lod_active_screen,
                        NULL);

            if (mem_addr == NULL)
            {
                break;
            }
            kal_adm_free(g_mmi_frm_resmem_cntx.adm_lod_id[g_mmi_frm_resmem_cntx.lod_active_screen], mem_addr);
        } while (1);

        kal_adm_delete(g_mmi_frm_resmem_cntx.adm_lod_id[g_mmi_frm_resmem_cntx.lod_active_screen]);
        g_mmi_frm_resmem_cntx.adm_lod_id[g_mmi_frm_resmem_cntx.lod_active_screen] = 
            kal_adm_create(
                                                                                        g_mmi_frm_resmem_lod_pool[g_mmi_frm_resmem_cntx.lod_active_screen],
                                                                                        MMI_FRM_RESMEM_POOL_LOD_ON_DEMAND_SIZE,
                                                                                        (kal_uint32*) g_mmi_frm_resmem_mem_pool_chunk_size,
                                                                                        KAL_TRUE);
        g_mmi_frm_resmem_cntx.lod_mem_using = 0;
    }

    if (flag & MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST)
    {
        for (i = 0; i < MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER; i++)
        {
            id = g_mmi_frm_resmem_cntx.always_keep_ID[i];
            if (id != MMI_FRM_RESMEM_INVALID_RES_ID)
            {
            g_mmi_frm_resmem_cntx.always_keep_ID[i] = MMI_FRM_RESMEM_INVALID_RES_ID;

            /* clear those res de-reg always attribute */
            mem_addr = mmi_frm_resmem_rec_if_exist(MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST, id, &size);
            if (mem_addr != NULL)
            {
                mmi_frm_resmem_rec_del(MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST, id);
                kal_adm_free(g_mmi_frm_resmem_cntx.adm_always_id, mem_addr);
            }
        }
    }
        
        kal_adm_delete(g_mmi_frm_resmem_cntx.adm_always_id);
        g_mmi_frm_resmem_cntx.adm_always_id = kal_adm_create(
                                                g_mmi_frm_resmem_always_pool,
                                                MMI_FRM_RESMEM_POOL_ALWASY_EXIST_SIZE,
                                                (kal_uint32*) g_mmi_frm_resmem_mem_pool_chunk_size,
                                                KAL_TRUE);
        g_mmi_frm_resmem_cntx.always_mem_using = 0;
    }

    /* should call this to avoid incorrect displaying because of GDI cache */
    gdi_image_cache_reset();

    MMI_FRM_RESMEM_CS_LEAVE;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_reg_retain
 * DESCRIPTION
 *  Register the resource to have MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST attribute
 *  With the attribute, resource will not be cleared from RAM when reset resource 
 *  of MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND type.
 *  Please note that if the resource is already allocated in LOD, it will
 *  be moved to Always-Exist area.
 * PARAMETERS
 *  id      [IN]        Resource ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_resmem_reg_retain(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U8 *mem_addr = NULL, *mem_addr_dst;
    U32 size;
    MMI_BOOL ret_bool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_RESMEM_CS_ENTER;
    /* registration */
    if (mmi_frm_resmem_if_res_to_always_keep(id) == MMI_FALSE)
    {
        for (i = 0; i < MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER; i++)
        {
            if (g_mmi_frm_resmem_cntx.always_keep_ID[i] == MMI_FRM_RESMEM_INVALID_RES_ID)
            {
                g_mmi_frm_resmem_cntx.always_keep_ID[i] = id;
                break;
            }
        }
    }

    /* consider already load in memory */
    /* alreay in Always Exist area? */
    if (NULL != mmi_frm_resmem_rec_if_exist(MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST, id, NULL))
    {
        /* do nothing */
        MMI_FRM_RESMEM_CS_LEAVE;
        return;
    }

    /* already in LOD area? */
    mem_addr = mmi_frm_resmem_rec_if_exist(MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND, id, &size);
    if (mem_addr != NULL)
    {
        /* move to Always Exist area */
        mem_addr_dst = kal_adm_alloc(g_mmi_frm_resmem_cntx.adm_always_id, size);
        memcpy(mem_addr_dst, mem_addr, size);
        g_mmi_frm_resmem_cntx.always_mem_using += size;
        if (g_mmi_frm_resmem_cntx.always_mem_using > g_mmi_frm_resmem_cntx.always_mem_max_used)
        {
            g_mmi_frm_resmem_cntx.always_mem_max_used = g_mmi_frm_resmem_cntx.always_mem_using;
        }
        MMI_ASSERT(g_mmi_frm_resmem_cntx.always_mem_max_used < MMI_FRM_RESMEM_POOL_ALWASY_EXIST_SIZE);
        ret_bool = mmi_frm_resmem_rec_add(MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST, id, mem_addr_dst, size);
        MMI_ASSERT(ret_bool == MMI_TRUE);

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
    }
    MMI_FRM_RESMEM_CS_LEAVE;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_dereg_retain
 * DESCRIPTION
 *  de-register MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST attribute from resource.
 *  Please note that the calling will also clear the memory of specified resource.
 *  So the allocated pointer, if any, will not valid any more.
 * PARAMETERS
 *  id      [IN]        Resource ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_resmem_dereg_retain(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U8 *mem_addr;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_RESMEM_CS_ENTER;
    for (i = 0; i < MMI_FRM_RESMEM_ALWAYS_EXIST_NUMBER; i++)
    {
        if (g_mmi_frm_resmem_cntx.always_keep_ID[i] == id)
        {
            g_mmi_frm_resmem_cntx.always_keep_ID[i] = MMI_FRM_RESMEM_INVALID_RES_ID;
            break;
        }
    }

    /* clear those res de-reg always attribute */
    mem_addr = mmi_frm_resmem_rec_if_exist(MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST, id, &size);
    if (mem_addr != NULL)
    {
        mmi_frm_resmem_rec_del(MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST, id);
        g_mmi_frm_resmem_cntx.always_mem_using -= size;
        kal_adm_free(g_mmi_frm_resmem_cntx.adm_always_id, mem_addr);

        /* should call this to avoid incorrect displaying because of GDI cache */
        gdi_image_cache_reset();
    }

    MMI_FRM_RESMEM_CS_LEAVE;
    return;
}

/*----------------------------------------------------------------*
  String resource
 *----------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resmem_load_str_suite
 * DESCRIPTION
 *  load the specified string resource suite into memory.
 *  Please note that the first item in the array is for string content part, 
 *  and the other item is string map part.
 * PARAMETERS
 *  ptr_ary         [OUT]       Array of memory pointers to string suite
 *  offset_ary      [IN]        Array of offset positions in flash file
 *  size_ary        [IN]        Array of size in flash file
 *  ary_count       [IN]        Number of entries in offset_ary and size_ary
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_resmem_load_str_suite(U8 **ptr_ary, U32 *offset_ary, U32 *size_ary, U32 ary_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(ptr_ary != NULL);
    MMI_ASSERT(offset_ary != NULL);
    MMI_ASSERT(size_ary != NULL);
    MMI_ASSERT(ary_count == 2);

    /* string content part */
    g_mmi_frm_resmem_cntx.str_content = (U8 *)g_mmi_frm_resmem_str_pool;
    NFB_RES_Load(ENFB_CONTENT_STRINGRES, g_mmi_frm_resmem_cntx.str_content, offset_ary[0], size_ary[0]);

    /* string map part */
    g_mmi_frm_resmem_cntx.str_map = (U8 *)((((U32)g_mmi_frm_resmem_str_pool + size_ary[0] + 3)/4)*4);
    
    /* make sure data doesn't exceed pool size */
    MMI_ASSERT( ((U32)g_mmi_frm_resmem_cntx.str_map + size_ary[1]) <= 
                ((U32)g_mmi_frm_resmem_str_pool + sizeof(g_mmi_frm_resmem_str_pool)) );
    
    NFB_RES_Load(ENFB_CONTENT_STRINGRES, g_mmi_frm_resmem_cntx.str_map, offset_ary[1], size_ary[1]);

    ptr_ary[0] = g_mmi_frm_resmem_cntx.str_content;
    ptr_ary[1] = g_mmi_frm_resmem_cntx.str_map;

    return;
}

#endif /* defined(__MMI_RESOURCE_ENFB_SUPPORT__) */ 

