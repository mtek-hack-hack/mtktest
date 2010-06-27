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
 * Filename:
 * ---------
 *  FileMgrCore.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"

#include "CommonScreens.h"
#include "SettingProfile.h"     /* error tone */

#include "fmt_def.h"

#include "FileMgr.h"

#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#endif /* __DRM_SUPPORT__ */ 

#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "FileMgrStruct.h"

extern pBOOL IsBackHistory;

extern S8 nPrintableStr[];

extern fmgr_context_struct *fmgr_p;
extern fmgr_filter_struct fmgr_filter[FMGR_MAX_FILTER_COUNT];

extern S32 gdi_ucs2_stricmp(U16 *s1,U16 *s2);

/*****************************************************************************
 * FUNCTION
 *  fmgr_construct_filter_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 fmgr_construct_filter_pattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fmgr_p->filter_pattern, 0, sizeof(fmgr_p->filter_pattern));

    if (FMGR_FILTER_IS_SET(&fmgr_p->filter_type, FMGR_TYPE_ALL))
    {
        return 0;
    }

    for (i = 0; i < FMGR_MAX_FILTER_COUNT; i++)
    {
        if (FMGR_FILTER_IS_SET(&fmgr_p->filter_type, fmgr_filter[i].type))
        {
            S8 *ptr;
            U16 len;

            mmi_ucs2cpy((S8*) fmgr_p->filter_pattern[count].Pattern, (S8*) L"*.");
            if ((ptr = (S8*) strstr((S8*) fmgr_filter[i].ext, (S8*) " ")) != NULL)
            {
                len = ptr - fmgr_filter[i].ext;
            }
            else
            {
                len = strlen(fmgr_filter[i].ext);
            }
            mmi_asc_n_to_ucs2((S8*) & fmgr_p->filter_pattern[count].Pattern[2], (S8*) fmgr_filter[i].ext, len);
            count++;
        }
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_parent_highlight_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 fmgr_get_parent_highlight_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    S32 load_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    load_index = mmi_fmgr_kernel_get_hash_item_for_parent_idx_cache();

    if (load_index != -1)
    {
        return load_index;
    }
    
#if 0
#if defined(MT6223P)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MT6223P */
#endif /* if 0 */
    
    while (fmgr_p->cache_end_idx <= fmgr_p->file_count)
    {
        for (i = fmgr_p->cache_start_idx; i < fmgr_p->cache_end_idx; i++)
        {
            /*if (mmi_ucs2cmp(
                    (PS8) fmgr_p->parent_name,
                    (PS8) fmgr_p->file_cache[i - fmgr_p->cache_start_idx].file_name) == 0)*/
            if (gdi_ucs2_stricmp(
                    (PU16) fmgr_p->parent_name,
                    (PU16) fmgr_p->file_cache[i - fmgr_p->cache_start_idx].file_name) == 0)
            {
                return i;
            }
        }
        if (i < fmgr_p->file_count - 1)
        {
            mmi_fmgr_kernel_load_cache((U16) (i + 1));
        }
        else
        {
            break;
        }
    }

    return 0;
}

/*****************************************************************************
******************************************************************************
* From this line is File Manager [Caching Kernal]
*****************************************************************************
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_move_selection_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_kernel_move_selection_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 load_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_p->cur_index > 0)
    {
        fmgr_p->cur_index--;
    }
    else
    {
        fmgr_p->cur_index = fmgr_p->file_count - 1;
    }

    /* out of cache, reload cache */
    if ((fmgr_p->cur_index < fmgr_p->cache_start_idx) || (fmgr_p->cur_index >= fmgr_p->cache_end_idx))
    {
        /* not in the cache, reload the cache, and put the desired entry in the middle of cache */
        load_index = fmgr_p->cur_index - (FMGR_CACHE_ENTRY_COUNT / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        /* load the info into cache */
        mmi_fmgr_kernel_load_cache((U16) load_index);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_move_selection_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_kernel_move_selection_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 load_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_p->cur_index < fmgr_p->file_count - 1)
    {
        fmgr_p->cur_index++;
    }
    else
    {
        fmgr_p->cur_index = 0;
    }

    /* out of cache, reload cache */
    if ((fmgr_p->cur_index < fmgr_p->cache_start_idx) || (fmgr_p->cur_index >= fmgr_p->cache_end_idx))
    {
        /* not in the cache, reload the cache, and put the desired entry in the middle of cache */
        load_index = fmgr_p->cur_index - (FMGR_CACHE_ENTRY_COUNT / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        /* load the info into cache */
        mmi_fmgr_kernel_load_cache((U16) load_index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_get_file_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_fmgr_kernel_get_file_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return fmgr_p->file_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_get_cur_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_fmgr_kernel_get_cur_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return fmgr_p->cur_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_set_cur_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_kernel_set_cur_idx(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->cur_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_hide_ext_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_buf_ptr     [?]     
 *  info_ptr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_kernel_hide_ext_name(S8 *str_buf_ptr, FMGR_FILE_INFO_STRUCT *info_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ext = mmi_fmgr_extract_ext_file_name((PS8)str_buf_ptr);

#ifndef __MMI_SHOW_FILE_EXT__
    /* hide all ext */
    if (!(info_ptr->attribute & FS_ATTR_DIR))   /* not folder */
    {
        if(ext)
        {
            ext-=2;
            ext[0] = ext[1] = 0;
        }
    }
#else /* __MMI_SHOW_FILE_EXT__ */ 
    /* show others except and test daf */
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    /* hide daf */

    if (FMGR_FILTER_IS_SET(&info_ptr->file_type, FMGR_TYPE_DAF) ||
        FMGR_FILTER_IS_SET(&info_ptr->file_type, FMGR_TYPE_MP2))
    {
        if(ext)
        {
            ext-=2;
            ext[0] = ext[1] = 0;
        }
    }
#endif /* __MMI_SHOW_DAF_FILE_EXT__ */ 
#ifndef __MMI_SHOW_CMP_FILE_EXT__
    /* hide cmp */

    if (FMGR_FILTER_IS_SET(&info_ptr->file_type, FMGR_TYPE_CMP))
    {
        if(ext)
        {
            ext-=2;
            ext[0] = ext[1] = 0;
        }
    }
#endif /* __MMI_SHOW_CMP_FILE_EXT__ */ 
#endif /* __MMI_SHOW_FILE_EXT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_get_path_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_path_name      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_kernel_get_path_name(S8 *full_path_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) full_path_name, (PS8) fmgr_p->file_path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_pass_filter_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_info_p         [?]     
 *  file_type_p         [?]     
 *  buf_file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_fmgr_kernel_pass_filter_check(FS_DOSDirEntry *file_info_p, FMGR_FILTER *file_type_p, S8 *buf_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_pass_filter;
    S32 i;
    S32 filter_count;
    FMGR_FILTER file_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init */
    is_pass_filter = FALSE;
    FMGR_FILTER_INIT(&file_type);
    FMGR_FILTER_SET(&file_type, FMGR_TYPE_UNKNOW);

    /* is folder */
    if (file_info_p->Attributes & FS_ATTR_DIR)
    {
        if (mmi_ucs2cmp(buf_file_name, (S8*) L"..") == 0)
        {
            FMGR_FILTER_SET(&file_type, FMGR_TYPE_FOLDER_DOT);
            FMGR_FILTER_CLEAR(&file_type, FMGR_TYPE_UNKNOW);
        }
        else
        {
            FMGR_FILTER_SET(&file_type, FMGR_TYPE_FOLDER);
            FMGR_FILTER_CLEAR(&file_type, FMGR_TYPE_UNKNOW);
        }

        if (FMGR_FILTER_IS_SET(&fmgr_p->filter_type, FMGR_TYPE_ALL))
        {
            /* don't show . and .. folder */
            if (mmi_ucs2cmp(buf_file_name, (S8*) L".") != 0 && mmi_ucs2cmp(buf_file_name, (S8*) L"..") != 0)
            {
                is_pass_filter = TRUE;
            }
        }
        else
        {
            if (FMGR_FILTER_IS_SET(&fmgr_p->filter_type, FMGR_TYPE_FOLDER))
            {
                if ((mmi_ucs2cmp(buf_file_name, (S8*) L".") != 0) &&
                    (mmi_ucs2cmp(buf_file_name, (S8*) L"..") != 0))
                {
                    is_pass_filter = TRUE;
                }
            }
            else if (FMGR_FILTER_IS_SET(&fmgr_p->filter_type, FMGR_TYPE_FOLDER_DOT))
            {
                if (mmi_ucs2cmp(buf_file_name, (S8*) L".") != 0)
                {
                    FMGR_FILTER_CLEAR(&file_type, FMGR_TYPE_UNKNOW);
                    is_pass_filter = TRUE;
                }
            }
        }
    }
    else
    {
        S8 buf_file_ext[FMGR_MAX_EXT_LEN + 1];
        S8 *ext_ptr;

        /* get file extension - and make it upper case */
        memset(buf_file_ext, 0, sizeof(buf_file_ext));
        ext_ptr = mmi_fmgr_extract_ext_file_name((PS8) buf_file_name);
        if (ext_ptr != NULL)
            /* mmi_ucs2_to_asc((PS8)buf_file_ext, ext_ptr); */
        {
            mmi_ucs2_n_to_asc((PS8) buf_file_ext, ext_ptr, FMGR_MAX_EXT_LEN << 1);
        }
        /* strncpy((PS8)buf_file_ext, (PS8)file_info_p->Extension,3); */

        for (i = 0; i < (S32) strlen((char*)buf_file_ext); i++)
        {
            if (buf_file_ext[i] >= 'a')
            {
                buf_file_ext[i] += 'A' - 'a';
            }
        }

        /* use extension to check filter */
        filter_count = sizeof(fmgr_filter) / sizeof(fmgr_filter_struct);

        for (i = 0; i < filter_count; i++)
        {
            if (FMGR_FILTER_IS_SET(&fmgr_p->filter_type, fmgr_filter[i].type))
            {
                if (strcmp((char*)buf_file_ext, (char*)fmgr_filter[i].ext) == 0)
                    /* if((buf_file_ext[0] == fmgr_filter[i].ext[0]) &&
                       (buf_file_ext[1] == fmgr_filter[i].ext[1]) &&
                       (buf_file_ext[2] == fmgr_filter[i].ext[2])) */
                {
                    FMGR_FILTER_SET(&file_type, fmgr_filter[i].type);
                    FMGR_FILTER_CLEAR(&file_type, FMGR_TYPE_UNKNOW);
                    is_pass_filter = TRUE;
                    break;
                }
            }
        }

        if (FMGR_FILTER_IS_SET(&fmgr_p->filter_type, FMGR_TYPE_ALL))
        {
            is_pass_filter = TRUE;
        }
    }

    /* assign return value */
    *file_type_p = file_type;

    return is_pass_filter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_fmgr_kernel_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete files including drm file + rights */
    fs_ret = FS_XDelete((PU16) fmgr_p->file_path, FS_FILE_TYPE, NULL, 0);

    if (!(fs_ret >= FS_NO_ERROR))
    {
        /* fail */
        mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) fmgr_p->file_path);
        PRINT_INFORMATION("delete all fail: %s", nPrintableStr);

        DisplayPopup((PU8) GetString(GetFileSystemErrorString(fs_ret)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);

        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_load_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_kernel_load_cache(U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_file_path[(FMGR_MAX_PATH_LEN + 5) * ENCODING_LENGTH];
    S8 buf_file_ext[(FMGR_MAX_EXT_LEN + 1) * ENCODING_LENGTH];
    U16 cache_index = 0;
    S32 fs_ret;

#ifdef __FS_SORT_SUPPORT__
    U32 seq;
#endif 
    U8 filter_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(start_index < fmgr_p->file_count);

    /* init some value */
    fmgr_p->cache_start_idx = start_index;
    /* fmgr_p->cache_end_idx                = 0; */

    memset((PU8) fmgr_p->file_cache, 0, sizeof(FMGR_FILE_INFO_STRUCT) * FMGR_CACHE_ENTRY_COUNT);

    /* define search file */
    /* create "filepath\*.*" */
    mmi_asc_to_ucs2((PS8) buf_file_ext, "*.*");

    mmi_ucs2cpy((PS8) buf_file_path, (PS8) fmgr_p->file_path);
    if (buf_file_path[(mmi_ucs2strlen(buf_file_path) - 1) << 1] != '\\')
    {
        mmi_ucs2cat((PS8) buf_file_path, (PS8) L"\\");
    }
    mmi_ucs2cat((PS8) buf_file_path, (PS8) buf_file_ext);

    filter_count = fmgr_construct_filter_pattern();
#ifdef __FS_SORT_SUPPORT__
    if( !fmgr_p->kernel_init_include_dir )
    {
        fs_ret = FS_XFindReset(
                    (PU16) buf_file_path,
                    fmgr_p->filter_pattern,
                    filter_count,
                    0,
                    FS_ATTR_HIDDEN | FS_ATTR_SYSTEM | FS_ATTR_VOLUME,
                    FS_FILE_TYPE | fmgr_p->sort_option,
                    TRUE,
                    &seq);
    }
    else
    {
        fs_ret = FS_XFindReset(
                    (PU16) buf_file_path,
                    fmgr_p->filter_pattern,
                    filter_count,
                    FS_ATTR_DIR,
                    FS_ATTR_HIDDEN | FS_ATTR_SYSTEM | FS_ATTR_VOLUME,
                    FS_DIR_TYPE | FS_FILE_TYPE | fmgr_p->sort_option,
                    TRUE,
                    &seq);
    }

#else /* __FS_SORT_SUPPORT__ */ 
    fs_ret = FS_TOO_MANY_FILES;
#endif /* __FS_SORT_SUPPORT__ */ 

    if (fs_ret < FS_NO_ERROR)
    {
        if (fs_ret == FS_TOO_MANY_FILES)
        {
            /* too many files, can't sort */
            mmi_fmgr_kernel_list((PS8) buf_file_path, &cache_index, fmgr_p->cache_start_idx, FALSE);
        }
        else
        {
            fmgr_p->cache_end_idx = start_index;
            return;
        }
    }
#ifdef __FS_SORT_SUPPORT__
    if (fs_ret > 0)
    {
        mmi_fmgr_kernel_init_continue(buf_file_path, &seq, fs_ret, &cache_index, fmgr_p->cache_start_idx, FALSE);
    }

    FS_XFindClose(&seq);
#endif /* __FS_SORT_SUPPORT__ */ 
    fmgr_p->cache_start_idx = start_index;
    fmgr_p->cache_end_idx = start_index + cache_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_get_file_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index               [IN]        
 *  file_info_ptr       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_kernel_get_file_info(S32 index, FMGR_FILE_INFO_STRUCT *file_info_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 load_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < fmgr_p->file_count);

    if ((index < fmgr_p->cache_start_idx) || (index >= fmgr_p->cache_end_idx))
    {
        /* desired entry in the middle of cache */
        load_index = index - (FMGR_CACHE_ENTRY_COUNT / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        mmi_fmgr_kernel_load_cache(load_index);
    }

    memcpy(file_info_ptr, &fmgr_p->file_cache[index - fmgr_p->cache_start_idx], sizeof(FMGR_FILE_INFO_STRUCT));
}


static void mmi_fmgr_kernel_init_intenal(S8 *file_path, FMGR_FILTER filter, U16 *file_count_ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_init_by_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path           [?]         
 *  filter              [IN]        
 *  file_count_ptr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_kernel_init_by_app(S8 *file_path, FMGR_FILTER filter, U16 *file_count_ptr)
{
    // this is from App, no need directory
    fmgr_p->kernel_init_include_dir = FALSE;
    mmi_fmgr_kernel_init_intenal(file_path, filter, file_count_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path           [?]         
 *  filter              [IN]        
 *  file_count_ptr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_kernel_init(S8 *file_path, FMGR_FILTER filter, U16 *file_count_ptr)
{
    // This is from FileMgr
    /* don't display folder when browse from app */
    if (fmgr_p->src_application != APP_FILEMANAGER && (fmgr_p->sel_type & FMGR_SELECT_BROWSE))
        fmgr_p->kernel_init_include_dir = FALSE;
    else
        fmgr_p->kernel_init_include_dir = TRUE;
    mmi_fmgr_kernel_init_intenal(file_path, filter, file_count_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_init_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path           [?]         
 *  filter              [IN]        
 *  file_count_ptr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fmgr_kernel_init_intenal(S8 *file_path, FMGR_FILTER filter, U16 *file_count_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_file_path[(FMGR_MAX_PATH_LEN + 5) * ENCODING_LENGTH];
    S8 buf_file_ext[(FMGR_MAX_EXT_LEN + 1) * ENCODING_LENGTH];
    S32 fs_ret;

#ifdef __FS_SORT_SUPPORT__
    U32 seq;
#endif 
    U8 filter_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) file_path);

    /* init some global value */
    fmgr_p->file_count = 0;
    fmgr_p->cache_start_idx = 0;
    fmgr_p->cache_end_idx = 0;
    fmgr_p->filter_type = filter;
    (*file_count_ptr) = 0;

    memset((PU8) fmgr_p->file_cache, 0, sizeof(FMGR_FILE_INFO_STRUCT) * FMGR_CACHE_ENTRY_COUNT);

    mmi_ucs2cpy((PS8) buf_file_path, (PS8) file_path);
    if (buf_file_path[(mmi_ucs2strlen(buf_file_path) - 1) << 1] != '\\')
    {
        mmi_ucs2cat((PS8) buf_file_path, (PS8) L"\\");
    }

    /* define search file */
    /* create "filepath\*.*" */
    mmi_asc_to_ucs2((PS8) buf_file_ext, "*.*");
    mmi_ucs2cat((PS8) buf_file_path, (PS8) buf_file_ext);

    filter_count = fmgr_construct_filter_pattern();
#ifdef __FS_SORT_SUPPORT__
    if( !fmgr_p->kernel_init_include_dir )
    {
        fs_ret = FS_XFindReset(
                    (PU16) buf_file_path,
                    fmgr_p->filter_pattern,
                    filter_count,
                    0,
                    FS_ATTR_HIDDEN | FS_ATTR_SYSTEM | FS_ATTR_VOLUME,
                    FS_FILE_TYPE | fmgr_p->sort_option,
                    TRUE,
                    &seq);
    }
    else
    {
        fs_ret = FS_XFindReset(
                    (PU16) buf_file_path,
                    fmgr_p->filter_pattern,
                    filter_count,
                    FS_ATTR_DIR,
                    FS_ATTR_HIDDEN | FS_ATTR_SYSTEM | FS_ATTR_VOLUME,
                    FS_DIR_TYPE | FS_FILE_TYPE | fmgr_p->sort_option,
                    TRUE,
                    &seq);
    }
#else /* __FS_SORT_SUPPORT__ */ 
    fs_ret = FS_TOO_MANY_FILES;
#endif /* __FS_SORT_SUPPORT__ */ 

    if (fs_ret < FS_NO_ERROR)
    {
        if (fs_ret == FS_TOO_MANY_FILES)
        {
            //if (fmgr_p->tree_action != FMGR_ACTION_NONE)
            {
            	 fmgr_p->file_count = mmi_fmgr_kernel_list(
                                (PS8) buf_file_path,
                                &fmgr_p->cache_end_idx,
                                fmgr_p->cache_start_idx,
                                TRUE);
            	 (*file_count_ptr) = fmgr_p->file_count;
            }
#if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
        }

        goto end_fmgr_init;
        return;
    }

#ifdef __FS_SORT_SUPPORT__
    if (seq > 0)
    {
        fmgr_p->file_count = mmi_fmgr_kernel_init_continue(
                                buf_file_path,
                                &seq,
                                fs_ret,
                                &fmgr_p->cache_end_idx,
                                fmgr_p->cache_start_idx,
                                TRUE);
    }
    FS_XFindClose(&seq);
#endif /* __FS_SORT_SUPPORT__ */ 
    (*file_count_ptr) = fmgr_p->file_count;

end_fmgr_init:
    if ( (fmgr_p->parent_name[0] == 0 && fmgr_p->parent_name[1] == 0) && 
         fmgr_p->cur_index != 0 &&
         fmgr_p->file_count != 0 && 
         !IsBackHistory )
    {
        mmi_fmgr_kernel_add_hash_item_for_parent_idx_cache();
    }
}

#ifdef __FS_SORT_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_init_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        
 *  seq             [?]         
 *  total           [IN]        
 *  cached_num      [IN]        
 *  start_index     [IN]        
 *  read_all        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_fmgr_kernel_init_continue(PS8 path, U32 *seq, S32 total, PU16 cached_num, U16 start_index, BOOL read_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_file_name[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
    FS_DOSDirEntry file_info;
    FS_HANDLE file_handle = 0;
    FMGR_FILTER file_type;
    U16 file_count = 0, cached_index, i;
    S16 j;
    BOOL is_pass_filter, is_short = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cached_index = *cached_num;

    for (i = start_index; i < total; i++)
    {
        file_handle = FS_XFindStart(
                        (PU16) path,
                        &file_info,
                        (PU16) buf_file_name,
                        FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                        i,
                        seq,
                        FS_FIND_DEFAULT);
        if (file_handle >= 0)
        {
            /* check if pass filter and get file type */
            is_pass_filter = mmi_fmgr_kernel_pass_filter_check(&file_info, &file_type, buf_file_name);

            /* test if pass the filter */
            if (is_pass_filter == TRUE && ((file_info.Attributes & FS_ATTR_HIDDEN) == 0))
            {
                /* still have entry to fill in the cache */
                if (cached_index < FMGR_CACHE_ENTRY_COUNT)
                {
                #ifndef __MMI_SHOW_FILE_EXT__
                    if (!(file_info.Attributes & FS_ATTR_DIR))
                    {
                        U16 len;

                        len = mmi_ucs2strlen((PS8) buf_file_name);
                        if (file_info.Extension[0] != ' ')
                        {
                            memset(&buf_file_name[(len - 4) << 1], 0, 8);
                        }
                    }
                #endif /* __MMI_SHOW_FILE_EXT__ */ 

                    /* copy file name */
                    is_short = FALSE;
                    if (file_info.NTReserved == FS_SFN_MATCH)
                    {
                        is_short = TRUE;
                    }
                    mmi_ucs2cpy((PS8) fmgr_p->file_cache[cached_index].file_name, (PS8) buf_file_name);
                    /* get file extension */
                    memset(
                        (PS8) fmgr_p->file_cache[cached_index].file_ext,
                        0,
                        sizeof(fmgr_p->file_cache[cached_index].file_ext));
                #ifndef __MMI_SHOW_FILE_EXT__
                    fmgr_p->file_cache[cached_index].file_ext[0] = '.';
                    mmi_asc_n_to_ucs2(
                        (PS8) & (fmgr_p->file_cache[cached_index].file_ext[2]),
                        (PS8) file_info.Extension,
                        3);
                #else /* __MMI_SHOW_FILE_EXT__ */ 
                    mmi_asc_n_to_ucs2(
                        (PS8) fmgr_p->file_cache[cached_index].file_ext,
                        (PS8) file_info.Extension,
                        3);
                #endif /* __MMI_SHOW_FILE_EXT__ */ 
                    for (j = (sizeof(file_info.Extension) - 1) * 2; j >= 0; j -= 2)
                    {
                        if (fmgr_p->file_cache[cached_index].file_ext[j] == ' ')
                        {
                            fmgr_p->file_cache[cached_index].file_ext[j] = '\0';
                        }
                    }

                    fmgr_p->file_cache[cached_index].is_short = is_short;
                    fmgr_p->file_cache[cached_index].index = fmgr_p->file_count;
                    fmgr_p->file_cache[cached_index].file_type = file_type;
                    fmgr_p->file_cache[cached_index].attribute = file_info.Attributes;
                    fmgr_p->file_cache[cached_index].time.nYear = file_info.DateTime.Year1980 + 1980;
                    fmgr_p->file_cache[cached_index].time.nMonth = file_info.DateTime.Month;
                    fmgr_p->file_cache[cached_index].time.nDay = file_info.DateTime.Day;
                    fmgr_p->file_cache[cached_index].time.nHour = file_info.DateTime.Hour;
                    fmgr_p->file_cache[cached_index].time.nMin = file_info.DateTime.Minute;
                    fmgr_p->file_cache[cached_index].time.nSec = file_info.DateTime.Second2;
                    fmgr_p->file_cache[cached_index].file_size = file_info.FileSize;
                    fmgr_p->file_cache[cached_index].is_used = TRUE;
                    fmgr_p->file_cache[cached_index].is_able_display = TRUE;

                    cached_index++;
                }

                /* increase counter */
                file_count++;
            }

            if (cached_index == FMGR_CACHE_ENTRY_COUNT && read_all == FALSE)
            {
                break;
            }

        }
    }
    *cached_num = cached_index;
    return file_count;
}
#endif /* __FS_SORT_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [?]         
 *  cached_num      [?]         
 *  start_index     [IN]        
 *  read_all        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_fmgr_kernel_list(S8 *file_path, U16 *cached_num, U16 start_index, BOOL read_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_file_name[FMGR_MAX_FILE_LEN * ENCODING_LENGTH];
    FS_DOSDirEntry file_info;
    FS_HANDLE file_handle;
    FMGR_FILTER file_type;
    S16 return_value, j;
    U16 file_count = 0, cache_index;
    BOOL is_pass_filter, is_short = FALSE;
    U8 filter_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cache_index = *cached_num;

    filter_count = fmgr_construct_filter_pattern();
    if (fmgr_p->src_application != APP_FILEMANAGER && (fmgr_p->sel_type & FMGR_SELECT_BROWSE))
    {
        file_handle = FS_FindFirstN(
                        (PU16) file_path,
                        fmgr_p->filter_pattern,
                        filter_count,
                        0,
                        0,
                        FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                        &file_info,
                        (PU16) buf_file_name,
                        FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                        start_index,
                        FS_FIND_DEFAULT);
    }

    else
    {
        file_handle = FS_FindFirstN(
                        (PU16) file_path,
                        fmgr_p->filter_pattern,
                        filter_count,
                        FS_ATTR_DIR,
                        0,
                        FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                        &file_info,
                        (PU16) buf_file_name,
                        FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                        start_index,
                        FS_FIND_DEFAULT);
    }

    if (file_handle >= 0)
    {
        do
        {
            /* check if pass filter and get file type */
            is_pass_filter = mmi_fmgr_kernel_pass_filter_check(&file_info, &file_type, buf_file_name);

            /* test if pass the filter */
            if (is_pass_filter == TRUE && ((file_info.Attributes & FS_ATTR_HIDDEN) == 0))
            {
                /* still have entry to fill in the catch */
                if (cache_index < FMGR_CACHE_ENTRY_COUNT)
                {
                #ifndef __MMI_SHOW_FILE_EXT__
                    if (!(file_info.Attributes & FS_ATTR_DIR))
                    {
                        U16 len;

                        len = mmi_ucs2strlen((PS8) buf_file_name);
                        if (file_info.Extension[0] != ' ')
                        {
                            memset(&buf_file_name[(len - sizeof(file_info.Extension) - 1) << 1], 0, 8);
                        }
                    }
                #endif /* __MMI_SHOW_FILE_EXT__ */ 

                    /* get file name */
                    is_short = FALSE;
                    if (file_info.NTReserved == FS_SFN_MATCH)
                    {
                        is_short = TRUE;
                    }
                    mmi_ucs2cpy((PS8) fmgr_p->file_cache[cache_index].file_name, (PS8) buf_file_name);

                    /* get file extension */
                    memset(
                        (PS8) fmgr_p->file_cache[cache_index].file_ext,
                        0,
                        sizeof(fmgr_p->file_cache[cache_index].file_ext));
                #ifndef __MMI_SHOW_FILE_EXT__
                    fmgr_p->file_cache[cache_index].file_ext[0] = '.';
                    mmi_asc_n_to_ucs2(
                        (PS8) & (fmgr_p->file_cache[cache_index].file_ext[2]),
                        (PS8) file_info.Extension,
                        3);
                #else /* __MMI_SHOW_FILE_EXT__ */ 
                    mmi_asc_n_to_ucs2((PS8) fmgr_p->file_cache[cache_index].file_ext, (PS8) file_info.Extension, 3);
                #endif /* __MMI_SHOW_FILE_EXT__ */ 
                    for (j = (sizeof(file_info.Extension) - 1) * 2; j >= 0; j -= 2)
                    {
                        if (fmgr_p->file_cache[cache_index].file_ext[j] == ' ')
                        {
                            fmgr_p->file_cache[cache_index].file_ext[j] = '\0';
                        }
                    }

                    fmgr_p->file_cache[cache_index].is_short = is_short;
                    fmgr_p->file_cache[cache_index].index = file_count;
                    fmgr_p->file_cache[cache_index].file_type = file_type;
                    fmgr_p->file_cache[cache_index].attribute = file_info.Attributes;
                    fmgr_p->file_cache[cache_index].time.nYear = file_info.DateTime.Year1980 + 1980;
                    fmgr_p->file_cache[cache_index].time.nMonth = file_info.DateTime.Month;
                    fmgr_p->file_cache[cache_index].time.nDay = file_info.DateTime.Day;
                    fmgr_p->file_cache[cache_index].time.nHour = file_info.DateTime.Hour;
                    fmgr_p->file_cache[cache_index].time.nMin = file_info.DateTime.Minute;
                    fmgr_p->file_cache[cache_index].time.nSec = file_info.DateTime.Second2;
                    fmgr_p->file_cache[cache_index].file_size = file_info.FileSize;
                    fmgr_p->file_cache[cache_index].is_used = TRUE;
                    fmgr_p->file_cache[cache_index].is_able_display = TRUE;

                    cache_index++;
                }

                /* increase counter */
                file_count++;
            }

            if (cache_index == FMGR_CACHE_ENTRY_COUNT && read_all == FALSE)
            {
                break;
            }

            if (fmgr_p->src_application != APP_FILEMANAGER && (fmgr_p->sel_type & FMGR_SELECT_BROWSE))
            {
                return_value = FS_FindNextN(
                                file_handle,
                                fmgr_p->filter_pattern,
                                filter_count,
                                0,
                                &file_info,
                                (PU16) buf_file_name,
                                FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
            }
            else
            {
                return_value = FS_FindNextN(
                                file_handle,
                                fmgr_p->filter_pattern,
                                filter_count,
                                FS_ATTR_DIR,
                                &file_info,
                                (PU16) buf_file_name,
                                FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
            }

        } while (return_value == FS_NO_ERROR);

        FS_FindClose(file_handle);
    }
    *cached_num = cache_index;
    return file_count;
}


#if defined(__DRM_V02__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_mul_odf_kernel_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path           [?]         
 *  filter              [IN]        
 *  file_count_ptr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_mul_odf_kernel_init(S8 *file_path, FMGR_FILTER filter, U16 *file_count_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_file_path[(FMGR_MAX_PATH_LEN + 5) * ENCODING_LENGTH];
    S32 fs_ret;
    U8 filter_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) file_path);

    /* init some global value */
    fmgr_p->file_count = 0;
    fmgr_p->cache_start_idx = 0;
    fmgr_p->cache_end_idx = 0;
    fmgr_p->filter_type = filter;
    (*file_count_ptr) = 0;

    memset((PU8) fmgr_p->file_cache, 0, sizeof(FMGR_FILE_INFO_STRUCT) * FMGR_CACHE_ENTRY_COUNT);

    mmi_ucs2cpy((PS8) buf_file_path, (PS8) file_path);

    /* define search file */
    /* create "filepath\*.*" */

    filter_count = fmgr_construct_filter_pattern();
    fs_ret = FS_TOO_MANY_FILES;

    if (fs_ret < FS_NO_ERROR)
    {
        if (fs_ret == FS_TOO_MANY_FILES)
        {
            fmgr_p->file_count = mmi_fmgr_mul_odf_kernel_list(
                                (PS8) buf_file_path,
                                &fmgr_p->cache_end_idx,
                                fmgr_p->cache_start_idx,
                                TRUE);
            (*file_count_ptr) = fmgr_p->file_count;
        }
        return;
    }

    (*file_count_ptr) = fmgr_p->file_count;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_mul_odf_kernel_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [?]         
 *  cached_num      [?]         
 *  start_index     [IN]        
 *  read_all        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_fmgr_mul_odf_kernel_list(S8 *file_path, U16 *cached_num, U16 start_index, BOOL read_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_file_name[FMGR_MAX_FILE_LEN * ENCODING_LENGTH];
    drm_file_info_struct drm_file_info;
    FS_DOSDirEntry file_info;
    FS_HANDLE file_handle;
    FMGR_FILTER file_type;
    S16 j;
    S32 return_value;
    U16 file_count = 0, cache_index;
    BOOL is_pass_filter, is_short = FALSE;
    U8 filter_count = 0;
    PU8 drm_archive_cnt;
    S8 *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cache_index = *cached_num;

    drm_archive_cnt = DRM_get_find_cntx();
    
    filter_count = fmgr_construct_filter_pattern();
    if (fmgr_p->src_application != APP_FILEMANAGER && (fmgr_p->sel_type & FMGR_SELECT_BROWSE))
    {
        file_handle = DRM_find_firstN((void*)drm_archive_cnt,
                         (PU16) file_path, 
                         fmgr_p->filter_pattern, 
                         filter_count,
                         &drm_file_info,
                         (PU16) buf_file_name,
                         FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                         start_index);
    }

    else
    {
        file_handle = DRM_find_firstN((void*)drm_archive_cnt,
                        (PU16) file_path,
                        fmgr_p->filter_pattern,
                        filter_count,
                        &drm_file_info,
                        (PU16) buf_file_name,
                        FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                        start_index);
    }

    file_info.Attributes = 0;
        
    if (file_handle >= 0)
    {
        do
        {
            /* check if pass filter and get file type */
            is_pass_filter = mmi_fmgr_kernel_pass_filter_check(&file_info, &file_type, buf_file_name);

            /* test if pass the filter */
            if (is_pass_filter == TRUE)
            {
                /* still have entry to fill in the catch */
                if (cache_index < FMGR_CACHE_ENTRY_COUNT)
                {
                #ifndef __MMI_SHOW_FILE_EXT__
                    {
                        U16 len;

                        len = mmi_ucs2strlen((PS8) buf_file_name);
                        if (file_info.Extension[0] != ' ')
                        {
                            memset(&buf_file_name[(len - sizeof(file_info.Extension) - 1) << 1], 0, 8);
                        }
                    }
                #endif /* __MMI_SHOW_FILE_EXT__ */ 

                    /* get file name */
                    is_short = FALSE;
                    mmi_ucs2cpy((PS8) fmgr_p->file_cache[cache_index].file_name, (PS8) buf_file_name);

                    /* get file extension */
                    memset(
                        (PS8) fmgr_p->file_cache[cache_index].file_ext,
                        0,
                        sizeof(fmgr_p->file_cache[cache_index].file_ext));


                    ptr = (S8*)mmi_fmgr_extract_ext_file_name((PS8) buf_file_name);

                    if (ptr != NULL)
                    {
                        U8 ext_len;

                        ext_len = mmi_ucs2strlen((PS8)ptr);

                        if (ext_len >=3)
                        {
                            mmi_ucs2_n_to_asc((PS8)file_info.Extension, (PS8)ptr, 3);
                        }
                        else
                        {
                            mmi_ucs2_n_to_asc((PS8)file_info.Extension, (PS8)ptr, (mmi_ucs2strlen((PS8)ptr))*ENCODING_LENGTH);
                        }
                    #ifndef __MMI_SHOW_FILE_EXT__
                        fmgr_p->file_cache[cache_index].file_ext[0] = '.';
                        mmi_asc_n_to_ucs2((PS8)&(fmgr_p->file_cache[cache_index].file_ext[2]), (PS8) file_info.Extension, 3);
                    #else /* __MMI_SHOW_FILE_EXT__ */ 
                        mmi_asc_n_to_ucs2((PS8) fmgr_p->file_cache[cache_index].file_ext, (PS8) file_info.Extension, 3);
                    #endif /* __MMI_SHOW_FILE_EXT__ */ 
                        for (j = (sizeof(file_info.Extension) - 1) * 2; j >= 0; j -= 2)
                        {
                            if (fmgr_p->file_cache[cache_index].file_ext[j] == ' ')
                            {
                                fmgr_p->file_cache[cache_index].file_ext[j] = '\0';
                            }
                        }
                    }
                    
                    fmgr_p->file_cache[cache_index].is_short = is_short;
                    fmgr_p->file_cache[cache_index].index = file_count;
                    fmgr_p->file_cache[cache_index].file_type = file_type;
                    fmgr_p->file_cache[cache_index].attribute = file_info.Attributes;
                    fmgr_p->file_cache[cache_index].time.nYear = drm_file_info.creation_date.Year1980 + 1980;
                    fmgr_p->file_cache[cache_index].time.nMonth = drm_file_info.creation_date.Month;
                    fmgr_p->file_cache[cache_index].time.nDay = drm_file_info.creation_date.Day;
                    fmgr_p->file_cache[cache_index].time.nHour = drm_file_info.creation_date.Hour;
                    fmgr_p->file_cache[cache_index].time.nMin = drm_file_info.creation_date.Minute;
                    fmgr_p->file_cache[cache_index].time.nSec = drm_file_info.creation_date.Second2;
                    fmgr_p->file_cache[cache_index].file_size = drm_file_info.file_size;
                    fmgr_p->file_cache[cache_index].is_used = TRUE;
                    fmgr_p->file_cache[cache_index].is_able_display = TRUE;

                    cache_index++;
                }

                /* increase counter */
                file_count++;
            }

            if (cache_index == FMGR_CACHE_ENTRY_COUNT && read_all == FALSE)
            {
                break;
            }

            if (fmgr_p->src_application != APP_FILEMANAGER && (fmgr_p->sel_type & FMGR_SELECT_BROWSE))
            {
                return_value = DRM_find_nextN((void*)drm_archive_cnt,
                                file_handle,
                                &drm_file_info,
                                (PU16) buf_file_name,
                                FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                                1);
            }
            else
            {
                return_value = DRM_find_nextN((void*)drm_archive_cnt,
                                file_handle,
                                &drm_file_info,
                                (PU16) buf_file_name,
                                FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                                1);
            }

        } while (return_value == FS_NO_ERROR);

        DRM_find_close((void*)drm_archive_cnt, file_handle);
    }
    *cached_num = cache_index;
    return file_count;
}

#endif /* #if defined(__DRM_V02__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_add_hash_item_for_parent_idx_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_kernel_add_hash_item_for_parent_idx_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH]; 
    S32 key;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FMGR] add hash item");

    if (mmi_ucs2strlen((PS8) fmgr_p->file_path) <= 3)
    {
        /* begin to browse root dir needn't to cache */
        return;
    }
    
    mmi_ucs2cpy(path,fmgr_p->file_path);     
    mmi_fmgr_remove_last_dir((PS8)path);    
    key = mmi_fmgr_kernel_hash_func_for_parent_idx_cache(path, mmi_ucs2strlen((PS8)path));

    for(i=0; i<FMGR_PARENT_INDEX_NUM; i++)
    {
        if (fmgr_p->parent_idx_hash_table[i].key == key)
        {
//            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FMGR] already in hash & overwrite");
            
//            fmgr_p->parent_idx_hash_table[i].key = key;        
//            fmgr_p->parent_idx_hash_table[i].index = fmgr_p->cur_index; 
            return;
        }
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FMGR] add hash -- new one");    
    
    fmgr_p->parent_idx_hash_table[fmgr_p->cur_hash_index].key = key;        
    fmgr_p->parent_idx_hash_table[fmgr_p->cur_hash_index].index = fmgr_p->cur_index; 
    fmgr_p->cur_hash_index++;

    if (fmgr_p->cur_hash_index >= FMGR_PARENT_INDEX_NUM)
    {
        fmgr_p->cur_hash_index=0;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_get_hash_item_for_parent_idx_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_fmgr_kernel_get_hash_item_for_parent_idx_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 key;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FMGR] get hash item");
    
    key = mmi_fmgr_kernel_hash_func_for_parent_idx_cache(fmgr_p->file_path, mmi_ucs2strlen((PS8)fmgr_p->file_path));

    for(i=0; i<FMGR_PARENT_INDEX_NUM; i++)
    {
        if (fmgr_p->parent_idx_hash_table[i].key == key)
        {
            S32 index;

            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FMGR] get hash item - hit");
    
            index = fmgr_p->parent_idx_hash_table[i].index; 
            fmgr_p->parent_idx_hash_table[i].index = 0;
            fmgr_p->parent_idx_hash_table[i].key = 0;
            return index;
        }
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[FMGR] get hash item - miss");
            
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_kernel_hash_func_for_parent_idx_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_fmgr_kernel_hash_func_for_parent_idx_cache(PS8 data_info, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 key = 5381;
    S32 value;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((*data_info) && len)
    {
        value = (*data_info);
        key = ((key << 5) + key) ^ value; 
        len--;
        data_info+=2;
    }

    return (S32)key;


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* if 0 */
}


