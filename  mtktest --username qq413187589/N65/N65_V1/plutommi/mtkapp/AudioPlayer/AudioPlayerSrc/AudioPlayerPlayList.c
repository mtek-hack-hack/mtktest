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
*  AudioPlayerPlayList.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player play list
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_include.h"
#ifdef __MMI_AUDIO_PLAYER__


#include "stdlib.h"
#include "time.h"
#include "Ucs2prot.h"
/* dependent headers for AudioPlayerXXX.h" */
#include "gui_data_types.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "Conversions.h"
#include "FileMgr.h"
#include "FileManagerGProt.h"

#include "Drm_gprot.h"

#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerPlayList.h"

const UI_character_type audio_file_restorable_upper_exts[][5] = 
{
#ifdef DAF_DECODE
    L"MP3",
#ifdef MUSICAM_DECODE    
    L"MP2",
#endif    
#endif 
    L"MID",
    L"MIDI",
    L"IMY",
    L"WAV",
#ifdef AU_DECODE
    L"AU ",
    L"SND",
#endif
#ifdef AIFF_DECODE
    L"AIF",
    L"AIFF",
    L"AIFC",
#endif
    L"AMR",
#ifdef AMRWB_DECODE
    L"AWB",
#endif 
#ifdef AAC_DECODE
    L"M4A",
#endif 
#ifdef YAMAHA_MA3
    L"MMF",
#endif 
#ifdef WMA_DECODE
    L"WMA",
#endif 
#ifdef AAC_DECODE
    L"AAC",
#endif 
#if defined(__MMI_PURE_AUDIO__)
    L"3GP",
    L"MP4",
#endif
#ifdef __DRM_V02__
    L"ODF",
#endif

    L"\0"   /* end of list */
};
const UI_character_type audio_file_restorable_lower_exts[][5] = 
{
#ifdef DAF_DECODE
    L"mp3",
#ifdef MUSICAM_DECODE    
    L"mp2",
#endif    
#endif 
    L"mid",
    L"midi",
    L"imy",
    L"wav",
#ifdef AU_DECODE
    L"au ",
    L"snd",
#endif
#ifdef AIFF_DECODE
    L"aif",
    L"aiff",
    L"aifc",
#endif
    L"amr",
#ifdef AMRWB_DECODE
    L"awb",
#endif 
#ifdef AAC_DECODE
    L"m4a",
#endif 
#ifdef YAMAHA_MA3
    L"mmf",
#endif 
#ifdef WMA_DECODE
    L"wma",
#endif 
#ifdef AAC_DECODE
    L"aac",
#endif 
#if defined(__MMI_PURE_AUDIO__)
    L"3gp",
    L"mp4",
#endif
#ifdef __DRM_V02__
    L"odf",
#endif
    L"\0"   /* end of list */
};

#if defined(MT6223) || defined(MT6223P)
const UI_character_type audio_file_not_support_a2dp_upper_exts[][5] = 
{
    L"AMR",
    L"\0"   /* end of list */
};

const UI_character_type audio_file_not_support_a2dp_lower_exts[][5] = 
{
    L"amr",
    L"\0"   /* end of list */
};
#endif

/* drives and paths */

UI_character_type present_dir_root[4];
UI_character_type present_list_name[FMGR_MAX_FILE_LEN + 4];
UI_character_type choosen_dir_root[4];
UI_character_type choosen_list_name[FMGR_MAX_FILE_LEN + 4];

extern const UI_character_type audio_file_lower_exts[NO_AUDIO_FILE_TYPES][5];
extern const UI_character_type audio_file_upper_exts[NO_AUDIO_FILE_TYPES][5];
extern audply_struct g_audply;
extern UI_character_type fullfilename_temp[FMGR_MAX_PATH_LEN + 1];

/* steal using subMenuData as a buffer to move data in play list file */
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];

/* definition for auto update list begin */
#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
static PS8 g_mmi_update_list_buff = (PS8)subMenuData;
static U32 g_mmi_update_list_buff_size = 4698;

static audply_auto_update_cache_struct cache_cntx;
static audply_auto_update_struct update_cntx;

static MMI_BOOL mmi_audply_update_set_cache_buff(PS8 buffer_ptr, U32 size_limit);
static MMI_BOOL mmi_audply_update_fill_cache(FS_HANDLE fd, U32 offset);
static MMI_BOOL mmi_audply_update_backfill_cache(FS_HANDLE fd, U32 offset);
static void mmi_audply_update_rename_folder(MMI_BOOL is_folder);
static void mmi_audply_update_do_rename_folder(void);
static void mmi_audply_update_delete_folder(MMI_BOOL is_folder);
static void mmi_audply_update_do_delete_folder(void);
static void mmi_audply_update_append_file(MMI_BOOL is_short);
static U32 mmi_audply_update_does_record_in_list(const PS8 list_path, const PS8 file_path);
#endif
/* definition for auto update list end */

extern BOOL need_refresh_list;
extern BOOL need_reload_list;
extern BOOL g_mmi_audply_init_done;

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_does_present_list_file_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_does_present_list_file_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type list_path[FMGR_MAX_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((kal_wchar*)list_path, "%c:\\audio_play_list.txt", (S8)g_audply.present_list);

    if (FS_GetAttributes((PU16)list_path) < 0)
    {        
        if (g_audply.n_total_items != 0)
        {
            g_audply.buff_head = 0;
            g_audply.n_buff_items = 0;
            g_audply.n_total_items = 0;
            g_audply.pick_index = -1;
        }
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_restorable
 * DESCRIPTION
 *  check does the audio type support store/restore function (real resume function)
 * PARAMETERS
 *  ext     [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_check_restorable(UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; audio_file_restorable_lower_exts[i][0]; i++)
    {
        BOOL match = TRUE;

        for (j = 0; j < 4; j++) /* it's is not necessary to check j < 4, but for safety */
        {
            UI_character_type file_ext_char = ext[j];

            if (file_ext_char != audio_file_restorable_lower_exts[i][j] &&
                file_ext_char != audio_file_restorable_upper_exts[i][j])
            {
                match = FALSE;
                break;
            }
            else if (file_ext_char == 0)    /* both are end and length less than 4 */
            {
                return TRUE;
            }
        }
        if (match)
        {
            return TRUE;
        }
    }

    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_whether_build_cache
 * DESCRIPTION
 *  check if the file type needs to build cache to seek
 * PARAMETERS
 *  need_to_build_cache [OUT]
 *  seekable [OUT]
 *  ext     [IN]        
 * RETURNS
 * void
 *****************************************************************************/
void mmi_audply_check_whether_build_cache(BOOL *need_to_build_cache, BOOL *seekable,UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

#ifdef __DRM_V02__
    UI_character_type ext_in_odf[FMGR_MAX_EXT_LEN + 1];
    PU8 ext_name_p = NULL; 
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < NEED_TO_BUILD_CACHE_NUM ; i++)
    {
        MMI_BOOL match = MMI_TRUE;

        for (j = 0; j < 4; j++) /* it's is not necessary to check j < 4, but for safety */
        {
            UI_character_type file_ext_char = ext[j];

            if (file_ext_char != audio_file_lower_exts[i][j] &&
                file_ext_char != audio_file_upper_exts[i][j])
            {
                match = MMI_FALSE;
                break;
            }
            else if (file_ext_char == 0)    /* both are end and length less than 4 */
            {
                break;
            }
        }
        if (match)
        {
        #ifdef __DRM_V02__
            if(i==ODF_FORMAT_FOR_CACHE)
            {
                ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)g_audply.filefullname);
                if(ext_name_p != NULL)
                {
                    memset(ext_in_odf,0,sizeof(ext_in_odf));
                    mmi_asc_n_to_ucs2((PS8)ext_in_odf, (PS8)ext_name_p, strlen((const char *)ext_name_p));
                    for (i = 0; i < NEED_TO_BUILD_CACHE_NUM ; i++)
                    {
                        match = MMI_TRUE;
                        for (j = 0; j < 4; j++) /* it's is not necessary to check j < 4, but for safety */
                        {
                            UI_character_type file_ext_char = ext_in_odf[j];
                            if (file_ext_char != audio_file_lower_exts[i][j] &&
                                file_ext_char != audio_file_upper_exts[i][j])
                            {
                                match = MMI_FALSE;
                                break;
                            }
                            else if (file_ext_char == 0)    /* both are end and length less than 4 */
                            {
                                break;
                            }
                        }
                        if(match)
                        {
                            *need_to_build_cache = TRUE;
                            *seekable = TRUE;
                            return;
                        }
                    }
                }
            }
            if(match)
        #endif /*__DRM_V02__*/                
            {
                *need_to_build_cache = TRUE;
                *seekable = TRUE;
                return;
            }
        }
    }

    *need_to_build_cache = FALSE;
    *seekable = TRUE; 
    return;
}

#if defined(MT6223) || defined(MT6223P)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_support_A2DP_or_not
 * DESCRIPTION
 *  check if the file type supports A2DP
 * PARAMETERS
 *  ext     [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_check_support_A2DP_or_not(UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NOT_SUPPORT_A2DP_NUM ; i++)
    {
        BOOL match = FALSE;

        for (j = 0; j < 4; j++) /* it's is not necessary to check j < 4, but for safety */
        {
            UI_character_type file_ext_char = ext[j];

            if (file_ext_char == audio_file_not_support_a2dp_upper_exts[i][j] ||
                file_ext_char == audio_file_not_support_a2dp_lower_exts[i][j])
            {
                match = TRUE;
            }
            else
            {
                match = FALSE;
                break;
            }
        }
        if(match)
        {
            return FALSE;
        }
    }
    
    return TRUE;

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_apply_picked_file
 * DESCRIPTION
 *  apply pick index to get full filename and title
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_apply_picked_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    BOOL isOK;
    UI_character_type filename[FMGR_MAX_FILE_LEN];
    UI_character_type wchar_filename[FMGR_MAX_FILE_LEN];
    UI_character_type ext[FMGR_MAX_EXT_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((result = mmi_audply_playlist_get_fullfilename(g_audply.filefullname, g_audply.pick_index)) == 0)
    {
        isOK = FALSE;
        g_audply.restorable = FALSE;
        g_audply.seekable = FALSE;
        g_audply.need_to_build_cache = FALSE;
    }
    else
    {
        if (result == 2)    /* if it is a short filename */
        {
            mmi_audply_extract_filename(wchar_filename, g_audply.filefullname);
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) filename,
                (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                (U8*) wchar_filename,
                g_chset_text_encoding);
        }
        else
        {
            mmi_audply_extract_filename(filename, g_audply.filefullname);
        }
        mmi_audply_split_filename_ext(filename, g_audply.title, ext);
        g_audply.restorable = mmi_audply_check_restorable(ext);
        mmi_audply_check_whether_build_cache(&g_audply.need_to_build_cache,&g_audply.seekable,ext);
        
    #if defined(MT6223) || defined(MT6223P)
        g_audply.support_A2DP = mmi_audply_check_support_A2DP_or_not(ext);
    #endif
    
        if(mdi_audio_get_duration(g_audply.filefullname, &(g_audply.duration)) != MDI_AUDIO_SUCCESS)
        {
            g_audply.duration = 0 ;
        }
        mmi_audply_determine_progress_speed();
        
        if (mmi_ucs2cmp((const PS8)g_audply.filefullname, (const PS8)g_audply.prev_filefullname))
        {
            g_audply.file_name_identical = FALSE ;
        }
        else
        {
            g_audply.file_name_identical = TRUE ;
        }
    
        isOK = TRUE;
    }

    return isOK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_start_playlist_at
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_start_playlist_at(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_audply.bitset, 0, MAX_PLAY_LIST_BYTES);
    g_audply.pick_index = index;
    g_audply.pick_count = 0;
    /*
     * Seed the random-number generator with current time so that
     * * the numbers will be different every time we run.
     */
    /* srand( (unsigned)time( NULL ) ); this line cause fatal error in target!!! */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pick_playlist_at
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pick_playlist_at(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.pick_index = index;
    if (!IsBitSetOn(index, g_audply.bitset))
    {
        SetBitSet(index, g_audply.bitset);
        g_audply.pick_count++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_extract_ext
 * DESCRIPTION
 *  extract filename extension
 * PARAMETERS
 *  filename        [IN]        
 *  ext             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_extract_ext(UI_string_type filename, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type ptr = filename;
    UI_string_type dot;
    S32 ext_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (dot = NULL; *ptr; ptr++)
    {
        if (*ptr == (L'.'))
        {
            dot = ptr;
        }
    }

    if (dot != NULL)
    {
        mmi_ucs2ncpy((PS8)ext, (const PS8)(dot + 1), FMGR_MAX_EXT_LEN);
        for (ext_size = mmi_ucs2strlen((const PS8)ext); ext_size < 3; ext_size++)
        {
            mmi_ucs2cat((PS8)ext, (const PS8)L" ");
        }
    }
    else
    {
        ext[0] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_split_filename_ext
 * DESCRIPTION
 *  split filename into two parts: name and extension
 * PARAMETERS
 *  filename                    [IN]        
 *  filename_without_ext        [IN]        
 *  ext                         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_split_filename_ext(UI_string_type filename, UI_string_type filename_without_ext, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 dot;
    S32 ext_size;
    S32 name_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dot = mmi_ucs2rchr((const PS8)filename, (U16)L'.');
	name_size = mmi_ucs2strlen((const PS8)filename);
	ext_size = mmi_ucs2strlen((const PS8)dot);
    if (dot != NULL)
    {
        mmi_ucs2ncpy((PS8)filename_without_ext, (const PS8)filename, (U32)(name_size - ext_size));
        mmi_ucs2ncpy((PS8)ext, (const PS8)(dot + 2), FMGR_MAX_EXT_LEN);
        for (ext_size = mmi_ucs2strlen((const PS8)ext); ext_size < 3; ext_size++)
        {
            mmi_ucs2cat((PS8)ext, (const PS8)L" ");
        }
    }
    else
    {
        mmi_ucs2cpy((PS8)filename_without_ext, (const PS8)filename);
        ext[0] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_extract_filename
 * DESCRIPTION
 *  get filename without path
 * PARAMETERS
 *  filename            [IN]        
 *  fullfilename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_extract_filename(UI_string_type filename, UI_string_type fullfilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 ch = mmi_ucs2rchr((const PS8)fullfilename, (U16)(L'\\'));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == NULL)
    {
        filename[0] = 0;
    }
    else
    {
        mmi_ucs2cpy((PS8)filename, (const PS8)(ch + 2));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_load_playlist
 * DESCRIPTION
 *  load play list to buffer
 * PARAMETERS
 *  list_file       [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_load_playlist(UI_string_type list_file, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, size, no_items;
    FS_HANDLE fd;
    UI_character_type filename[FMGR_MAX_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index -= (PLAY_LIST_BUFF_SIZE / 2 - 1);
    if (index < 0)
    {
        index = 0;
    }
    no_items = MAX_PLAY_LIST_NUM - index;
    if (no_items > PLAY_LIST_BUFF_SIZE)
    {
        no_items = PLAY_LIST_BUFF_SIZE;
    }
    g_audply.buff_head = index;
    g_audply.n_buff_items = 0;
    fd = FS_Open(list_file, FS_READ_ONLY);
    if (fd >= 0)
    {
        if (FS_Seek(fd, index * PLAY_LIST_RECORD_SIZE, FS_FILE_BEGIN) >= 0)
        {
            for (; i < no_items && FS_Read(fd, fullfilename_temp, PLAY_LIST_RECORD_SIZE, (U32*) & size) == FS_NO_ERROR;
                 i++)
            {
                if (size < PLAY_LIST_RECORD_SIZE)
                {
                    break;
                }
                /* load filename to play list buffer */
                fullfilename_temp[EOS(size)] = 0;   /* make it must be in boundary */
                if (IS_SNAME(fullfilename_temp))
                {
                    mmi_audply_extract_filename(filename, fullfilename_temp);
                    mmi_chset_mixed_text_to_ucs2_str(
                        (U8*) g_audply.buff_filename[i],
                        (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                        (U8*) filename,
                        g_chset_text_encoding);
                }
                else
                {
                    mmi_audply_extract_filename(g_audply.buff_filename[i], fullfilename_temp);
                }
                g_audply.n_buff_items++;
            }
        }
        FS_Close(fd);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_present_list_root
 * DESCRIPTION
 *  config the present play list root
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type mmi_audply_get_present_list_root()
{

    kal_wsprintf((kal_wchar*)present_dir_root, "%c:\\", (S8)g_audply.present_list);
    return present_dir_root ;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_present_list_file
 * DESCRIPTION
 *  config the present play list fila path
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type mmi_audply_get_present_list_file()
{

    kal_wsprintf((kal_wchar*)present_list_name, "%c:\\audio_play_list.txt", (S8)g_audply.present_list);
    return present_list_name ;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_choosen_present_list_root
 * DESCRIPTION
 *  config the present play list root by parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type mmi_audply_get_choosen_list_root(UI_character_type folder)
{

    kal_wsprintf((kal_wchar*)choosen_dir_root, "%c:\\", folder);
    return choosen_dir_root;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_choosen_present_list_file
 * DESCRIPTION
 *  config the present play list fila path by paramenter
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type mmi_audply_get_choosen_list_file(UI_character_type folder)
{

    kal_wsprintf((kal_wchar*)choosen_list_name, "%c:\\audio_play_list.txt", folder);
    return choosen_list_name ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_audio_path
 * DESCRIPTION
 *  check a path whether is an audio path
 * PARAMETERS
 *  path        [IN]
 * RETURNS
 *  BOOL        
 *****************************************************************************/
BOOL mmi_audply_is_audio_path(const PS8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type ext[FMGR_MAX_EXT_LEN + 1];
    PS8 dot;
    S32 ext_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        PRINT_INFORMATION("Audply | Debug: is_path | path = NULL.\n");
        return FALSE;
    }
/*
    if (!mmi_ucs2str((const PS8)path, (const PS8)ROOT_PATH_UNICODE_PATTERN))
    {
        PRINT_INFORMATION("Audply | Debug: is_path | check ROOT_PATH_UNICODE_PATTERN failed!");
        return FALSE;
    }
*/    
    dot = mmi_ucs2rchr((const PS8)path, (U16)L'.');

    if (dot != NULL)
    {
        mmi_ucs2ncpy((PS8)ext, (const PS8)(dot + 2), FMGR_MAX_EXT_LEN);
        for (ext_size = mmi_ucs2strlen((const PS8)ext); ext_size < 3; ext_size++)
        {
            mmi_ucs2cat((PS8)ext, (const PS8)L" ");
        }
        
        if (-1 == mmi_audply_lookup_audio_file_format(ext))
        {
            PRINT_INFORMATION("Audply | Debug: is_path | it is not a supported audio file format.\n");
            return FALSE;
        }
    }
    else
    {
        PRINT_INFORMATION("Audply | Debug: is_path | path is not included a dot.\n");
        return FALSE;
    }
    PRINT_INFORMATION("Audply | Debug: is_path | ok.\n");
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_init_playlist
 * DESCRIPTION
 *  init play list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_init_playlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, size;
    FS_HANDLE fd;
    UI_character_type filename[FMGR_MAX_FILE_LEN];
    UI_string_type list_name ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_clear_play_seconds();
    g_audply.restorable = FALSE;
    g_audply.seekable = FALSE;
    g_audply.need_to_build_cache = FALSE;
    g_audply.title[0] = 0;
    g_audply.filefullname[0] = 0;

    g_audply.buff_head = 0;
    g_audply.n_buff_items = 0;

    memset(g_audply.bitset, 0, MAX_PLAY_LIST_BYTES);
    g_audply.n_total_items = 0;
    g_audply.pick_index = -1;
    g_audply.pick_count = 0;
    
    /*config present play list path*/
    list_name = mmi_audply_get_present_list_file();
    
    fd = FS_Open(list_name, FS_READ_ONLY | FS_CREATE);
    if (fd >= 0)
    {
    	U8 error_conut = 0;
        for (;
             i < MAX_PLAY_LIST_NUM &&
             FS_Read(fd, fullfilename_temp, PLAY_LIST_RECORD_SIZE, (U32*) & size) == FS_NO_ERROR;)
        {
            if (size < PLAY_LIST_RECORD_SIZE)
            {
                break;
            }
            
            if (!mmi_audply_is_audio_path((const PS8)fullfilename_temp))
            {		
                error_conut++;
                /*if (error_conut > 3)
                {	
                    PRINT_INFORMATION("Audply | Debug: init_list | too many error, failed!\n");
                	break;
                }
                else*/
                {
                    PRINT_INFORMATION("Audply | Debug: init_list | error : %d.\n", error_conut);
                	continue;
                }
            }
            else
            {
                if (i < PLAY_LIST_BUFF_SIZE)
    		{
    		    /* load filename to play list buffer */
    		    fullfilename_temp[EOS(size)] = 0;   /* make it must be in boundary */
    		    if (IS_SNAME(fullfilename_temp))
    		    {
    		        mmi_audply_extract_filename(filename, fullfilename_temp);
    		        mmi_chset_mixed_text_to_ucs2_str(
    		            (U8*) g_audply.buff_filename[i],
    		            (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
    		            (U8*) filename,
    		            g_chset_text_encoding);
    		    }
    		    else
    		    {
    		        mmi_audply_extract_filename(g_audply.buff_filename[i], fullfilename_temp);
    		    }
    		    g_audply.n_buff_items++;
    		}
                i++;
            }
        }
        FS_Close(fd);
    }

    g_audply.n_total_items = i;
    mmi_audply_start_playlist_at(-1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_remove_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fd          [IN]        
 *  index       [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_playlist_remove_index(FS_HANDLE fd, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type file_list_buff = (UI_string_type) subMenuData;       /* use 4698 bytes (it has 5040 bytes) */
    S32 max_buff_size = MAX_SUB_MENUS * MAX_SUB_MENU_SIZE / PLAY_LIST_RECORD_SIZE;
    S32 n_items_in_buff, buff_size, size;
    S32 file_size = g_audply.n_total_items * PLAY_LIST_RECORD_SIZE;
    S32 offset = index * PLAY_LIST_RECORD_SIZE;
    S32 count = index;
    BOOL isOK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    isOK = TRUE;
    n_items_in_buff = g_audply.n_total_items - count - 1;
    while (n_items_in_buff > 0)
    {
        if (n_items_in_buff > max_buff_size)
        {
            n_items_in_buff = max_buff_size;
        }
        buff_size = PLAY_LIST_RECORD_SIZE * n_items_in_buff;
        if (FS_Seek(fd, offset + PLAY_LIST_RECORD_SIZE, FS_FILE_BEGIN) < 0)
        {
            isOK = FALSE;
            break;
        }
        if (FS_Read(fd, file_list_buff, buff_size, (UINT*) & size) != FS_NO_ERROR)
        {
            isOK = FALSE;
            break;
        }
        if (FS_Seek(fd, offset, FS_FILE_BEGIN) < 0)
        {
            isOK = FALSE;
            break;
        }
        if (FS_Write(fd, file_list_buff, buff_size, (UINT*) & size) != FS_NO_ERROR)
        {
            isOK = FALSE;
            break;
        }
        offset += buff_size;
        count += n_items_in_buff;
        n_items_in_buff = g_audply.n_total_items - count - 1;
    }

    if (isOK)
    {
        /* erase the last record */
        if (FS_Seek(fd, file_size - PLAY_LIST_RECORD_SIZE, FS_FILE_BEGIN) >= 0)
        {
            if (FS_Truncate(fd) == FS_NO_ERROR)
            {
                /* eliminate the bit at index and left-shift the rest of bitset after index */
                S32 m = index / 8;
                S32 k = g_audply.n_total_items / 8;
                S32 n;
                U8 CR, LSB;

                /* update pick count before we shift it */
                if (IsBitSetOn(index, g_audply.bitset))
                {
                    g_audply.pick_count--;
                }
                for (CR = 0, LSB = 0; k > m; k--)
                {
                    LSB = ((g_audply.bitset[k] & 0x01) != 0) ? 0x80 : 0;        /* store LSB */
                    g_audply.bitset[k] = (g_audply.bitset[k] >> 1) | CR;
                    CR = LSB;
                }
                for (n = index & 0x07; n < 7; n++)
                {
                    if ((g_audply.bitset[m] & (1 << (n + 1))) != 0)
                    {
                        g_audply.bitset[m] |= (1 << n);     /* set bit */
                    }
                    else
                    {
                        g_audply.bitset[m] &= ~(1 << n);    /* clear bit */
                     }
                }
                if (CR != 0)
                {
                    g_audply.bitset[m] |= 0x80; /* set MSB */
                }
                else
                {
                    g_audply.bitset[m] &= 0x7f; /* clear MSB */
                }

                g_audply.n_total_items--;

                if (g_audply.pick_index == index)
                {
                    if (g_audply.pick_index == g_audply.n_total_items)  /* it's the tail before, but now it's out of list */
                    {
                        mmi_audply_start_playlist_at(-1);   /* repick one */
                        mmi_audply_pick_playlist();
                    }
                    else if (!IsBitSetOn(index, g_audply.bitset))       /* keep pick_index, but need to update bitset & pick_count */
                    {
                        SetBitSet(g_audply.pick_index, g_audply.bitset);
                        g_audply.pick_count++;
                    }
                }
                else if (g_audply.pick_index > index)
                {
                    g_audply.pick_index--;
                }

                g_audply.buff_head = 0;
                g_audply.n_buff_items = 0;
            }
            else
            {
                isOK = FALSE;
            }
        }
        else
        {
            isOK = FALSE;
        }
    }

    return isOK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_append_one
 * DESCRIPTION
 *  append one song at tail
 * PARAMETERS
 *  fullfilename        [?]     
 * RETURNS
 *  U8 (0: success, 1: disk full, 2: other error)
 *****************************************************************************/
U8 mmi_audply_playlist_append_one(S8 *fullfilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    FS_HANDLE fd;
    U8 result = 2;
    int write_result;
    UI_string_type list_name ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*config present play list path*/    
    list_name = mmi_audply_get_present_list_file();
    
    if ((fd = FS_Open(list_name, FS_READ_WRITE | FS_CREATE | FS_ATTR_HIDDEN)) >= 0)
    {
        if (FS_Seek(fd, g_audply.n_total_items * PLAY_LIST_RECORD_SIZE, FS_FILE_BEGIN) >= 0)
        {
            if ((write_result = FS_Write(fd, fullfilename, PLAY_LIST_RECORD_SIZE, (U32*) & size)) == FS_NO_ERROR)
            {
                g_audply.n_total_items++;
                result = 0;
            }
            else if (write_result == FS_DISK_FULL)
            {
                result = 1;
            }
        }
        FS_Close(fd);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_remove_one
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_playlist_remove_one(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    BOOL isOK = FALSE;
    UI_string_type list_name ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*config present play list path*/    
    list_name = mmi_audply_get_present_list_file();
    
    if (g_audply.n_total_items <= 1)
    {
        isOK = mmi_audply_playlist_remove_all();
    }
    else if ((fd = FS_Open(list_name, FS_READ_WRITE)) >= 0)
    {
        isOK = mmi_audply_playlist_remove_index(fd, index);
        FS_Close(fd);
    }

    return isOK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_remove_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_playlist_remove_all()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    BOOL isOK = FALSE;
    UI_string_type list_name ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.n_total_items == 0)
    {
        return TRUE;
    }

    /*config present play list path*/
    list_name = mmi_audply_get_present_list_file();

    if ((fd = FS_Open(list_name, FS_READ_WRITE)) >= 0)
    {
        if (FS_Seek(fd, 0, FS_FILE_BEGIN) >= 0)
        {
            if (FS_Truncate(fd) == FS_NO_ERROR)
            {
                mmi_audply_clear_play_seconds();
                g_audply.restorable = FALSE;
                g_audply.seekable = FALSE;                
                g_audply.need_to_build_cache = FALSE;
                g_audply.title[0] = 0;
                g_audply.filefullname[0] = 0;
                g_audply.buff_head = 0;
                g_audply.n_buff_items = 0;
                g_audply.n_total_items = 0;
                mmi_audply_start_playlist_at(-1);
                isOK = TRUE;
            }
        }
        FS_Close(fd);
    }

    return isOK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_filename
 * DESCRIPTION
 *  retrieve file name from play list buffer or reload buffer
 * PARAMETERS
 *  filename        [IN]        
 *  index           [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_playlist_get_filename(UI_string_type filename, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset;
    UI_string_type list_name ;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0 || index >= g_audply.n_total_items)
    {
        return FALSE;
    }
    offset = index - g_audply.buff_head;
    if (offset >= 0 && offset < g_audply.n_buff_items)
    {
        /* hit: get item from buffer */
        mmi_ucs2cpy((PS8)filename, (const PS8)g_audply.buff_filename[offset]);
        return TRUE;
    }

    /*config present play list path*/
    list_name = mmi_audply_get_present_list_file();

    /* miss: load items to buffer */
    mmi_audply_load_playlist(list_name, index);

    /* double check if load successfully */
    offset = index - g_audply.buff_head;
    if (offset >= 0 && offset < g_audply.n_buff_items)
    {
        mmi_ucs2cpy((PS8)filename, (const PS8)g_audply.buff_filename[offset]);
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_fullfilename
 * DESCRIPTION
 *  retrieve file path and name from play list file
 * PARAMETERS
 *  fullfilename        [IN]        
 *  index               [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_playlist_get_fullfilename(UI_string_type fullfilename, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;
    S32 size;
    FS_HANDLE fd ;
    UI_string_type list_name ;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*config present play list path*/
    list_name = mmi_audply_get_present_list_file();

    fd = FS_Open(list_name,FS_READ_ONLY);
    
    if (fd >= 0)
    {
        if (FS_Seek(fd, index * PLAY_LIST_RECORD_SIZE, FS_FILE_BEGIN) >= 0)
        {
            if (FS_Read(fd, fullfilename, PLAY_LIST_RECORD_SIZE, (U32*) & size) == FS_NO_ERROR)
            {
                if (size > 0)
                {
                    result = IS_SNAME(fullfilename) ? 2 : 1;
                    MARK_DRIVE(fullfilename);
                    fullfilename[EOS(size)] = 0;    /* make it must be in boundary */
                }
            }
        }
        FS_Close(fd);
    }

    if (!result)
    {
        fullfilename[0] = 0;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pick_playlist
 * DESCRIPTION
 *  pick a song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_pick_playlist()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.n_total_items == 0)
    {
        return -1;
    }

    if (g_audply.pick_count == 0 || g_audply.repeat_mode != REPEAT_ONE)
    {
        if (g_audply.random_mode)
        {
            if (g_audply.n_total_items == g_audply.pick_count)
            {
                /* we already played one round */
                mmi_audply_start_playlist_at(-1);
                if (g_audply.repeat_mode == REPEAT_OFF)
                {
                    return -1;
                }
            }
            /* randomly pick next item */
            i = (g_audply.pick_index + (rand() % g_audply.n_total_items) + 1) % g_audply.n_total_items;
            while (IsBitSetOn(i, g_audply.bitset))
            {
                i = (i + 1) % g_audply.n_total_items;
            }
            g_audply.pick_index = i;
            g_audply.pick_count++;
        }
        else
        {
            if (g_audply.pick_index == g_audply.n_total_items - 1)
            {
                /* we reached the last song */
                mmi_audply_start_playlist_at(-1);
                if (g_audply.repeat_mode == REPEAT_OFF)
                {
                    return -1;
                }
            }
            /* sequentially pick next item */
            g_audply.pick_index++;
            if (!IsBitSetOn(g_audply.pick_index, g_audply.bitset))
            {
                g_audply.pick_count++;
            }
        }
        SetBitSet(g_audply.pick_index, g_audply.bitset);
    }

    return g_audply.pick_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pick_playlist_next
 * DESCRIPTION
 *  pick the next song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_pick_playlist_next()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.n_total_items == 0)
    {
        return -1;
    }

    if (g_audply.random_mode)
    {
        if (g_audply.n_total_items == g_audply.pick_count)
        {
            mmi_audply_start_playlist_at(-1);
        }

        /* randomly pick next item */
        i = (g_audply.pick_index + (rand() % g_audply.n_total_items) + 1) % g_audply.n_total_items;
        while (IsBitSetOn(i, g_audply.bitset))
        {
            i = (i + 1) % g_audply.n_total_items;
        }
        g_audply.pick_index = i;
        g_audply.pick_count++;
    }
    else
    {
        if (g_audply.pick_index == g_audply.n_total_items - 1)
        {
            mmi_audply_start_playlist_at(-1);
        }

        /* sequentially pick next item */
        g_audply.pick_index++;
        if (!IsBitSetOn(g_audply.pick_index, g_audply.bitset))
        {
            g_audply.pick_count++;
        }
    }
    SetBitSet(g_audply.pick_index, g_audply.bitset);

    return g_audply.pick_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pick_playlist_prev
 * DESCRIPTION
 *  pick the previous song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_pick_playlist_prev()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.n_total_items == 0)
    {
        return -1;
    }

    if (g_audply.pick_index == 0)
    {
        index = g_audply.n_total_items - 1;
    }
    else
    {
        index = g_audply.pick_index - 1;
    }
    mmi_audply_start_playlist_at(index);
    mmi_audply_pick_playlist_at(index);

    return g_audply.pick_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_dir_ready
 * DESCRIPTION
 *  check whether is the phone fs available
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_is_dir_ready(UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((hd = FS_Open((PU16) path, FS_OPEN_DIR | FS_READ_ONLY)) >= 0)
    {
        FS_Close(hd);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_does_file_exist
 * DESCRIPTION
 *  check whether does a file exist
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_does_file_exist(UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* FS_HANDLE hd; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetAttributes((PU16) path) < 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_preferred_or_available_list
 * DESCRIPTION
 *  get preferred or available list
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_get_preferred_or_available_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*check if the prefered drive is mounted on*/
    if (FS_GetDevStatus(g_audply.preferred_list, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
    {
        return g_audply.preferred_list;
    }
    /*return public drive (phone)*/
    return (U8)MMI_PUBLIC_DRV ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_regen_and_reload_playlist
 * DESCRIPTION
 *  stop playing, regen, and reload playlist
 * PARAMETERS
 *  need_regen_list         [IN]        
 *  need_reload_list        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_regen_and_reload_playlist(BOOL need_regen_list, BOOL need_reload_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[Audply]regen=%d and reload=%d",need_regen_list,need_reload_list);
    
    if (need_regen_list || need_reload_list)
    {
        mmi_audply_stop_playing();
    }
    
    if (need_regen_list)
    {
        mmi_audply_regenerate_play_list();
        need_reload_list = TRUE;
    }

    if (need_reload_list)
    {
		mmi_audply_reload_play_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_any_file_selected
 * DESCRIPTION
 *  check does any song is selected
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_is_any_file_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.n_total_items > 0 && g_audply.pick_index >= 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_list_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_update_list_hdlr(const PS8 old_path, const PS8 new_path, U8 action_type, BOOL is_folder)
{
#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type list_path[FMGR_MAX_PATH_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("<Audply>[Auto update list] enter callback function!, old=%d, new=%d, action=%d, folder=%d",old_path==NULL,new_path==NULL,action_type,is_folder);
    /* check necessarily parameter. */
    if (old_path == NULL)
    {
        PRINT_INFORMATION("<Audply>[Auto update list] invalid parameter!");
        return;
    }

    /* check compile option. */
    if (g_audply.list_auto_gen)
    {
    #ifndef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        return;
    #endif 
    }
    else    /* !list_auto_gen */
    {
    #ifndef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__
        return;
    #endif 
    }

    if (g_mmi_audply_init_done)
    {
        kal_wsprintf((kal_wchar*)list_path, "%c:\\audio_play_list.txt", (S8)g_audply.present_list);
    }
    else
    {
        kal_wsprintf((kal_wchar*)list_path, "%c:\\audio_play_list.txt", (S8)old_path[0]);
    }
    
    /* check the modified file/folder whether about present list. start */
    if (mmi_ucs2nicmp((const PS8)old_path, (const PS8)list_path, 1) && (action_type != AUDPLY_ACTION_COPY && action_type != AUDPLY_ACTION_MOVE))
    {
        PRINT_INFORMATION("<Audply>[Auto update list] current path's driver id is different with present list!"); 
        return;
    }
    else if (FS_GetAttributes((PU16)list_path) < 0)
    {
        PRINT_INFORMATION("<Audply>[Auto update list] no list file exist!"); 
        return;
    }

    /* init update_cntx begin */
    mmi_ucs2ncpy((PS8)update_cntx.old_path, (const PS8)old_path, (U32)mmi_ucs2strlen((const PS8)old_path));
    if (new_path != NULL)
    {
        mmi_ucs2ncpy((PS8)update_cntx.new_path, (const PS8)new_path, (U32)mmi_ucs2strlen((const PS8)new_path));
    }
    update_cntx.temp_file = -1;
    update_cntx.present_list = -1;
    update_cntx.counter = 0;
    update_cntx.deleted = 0;
    update_cntx.offset = 0;
    update_cntx.old_path_len = (U32)mmi_ucs2strlen((const PS8)update_cntx.old_path);
    update_cntx.action_type = action_type;
    update_cntx.is_folder = is_folder;
    memset(&cache_cntx, 0, sizeof(audply_auto_update_cache_struct));
    /* init update_cntx end  */
    
    /* do check if action from FMGR is about audio player list */
    if (is_folder)
    {
        if (action_type == AUDPLY_ACTION_RENAME)
        {
            mmi_audply_update_rename_folder(MMI_TRUE);
        }
        else if (action_type == AUDPLY_ACTION_DELETE)
        {
            mmi_audply_update_delete_folder(MMI_TRUE);
        }
        else if (action_type == AUDPLY_ACTION_DELETE_FAIL)
        {
            /* need modify */
            mmi_audply_update_delete_folder(MMI_TRUE);
        }
    }
    else
    {
        if (0 < mmi_audply_update_does_record_in_list((const PS8)list_path, (const PS8)old_path))
        {
            if (action_type == AUDPLY_ACTION_RENAME)
            {
                mmi_audply_update_rename_folder(MMI_FALSE);
            }
            else if (action_type == AUDPLY_ACTION_DELETE)
            {
                mmi_audply_update_delete_folder(MMI_FALSE);
            }
            else if (action_type == AUDPLY_ACTION_MOVE)
            {
                action_type = AUDPLY_ACTION_DELETE;
                mmi_audply_update_delete_folder(MMI_FALSE);
            }
        }
        else if (action_type == AUDPLY_ACTION_COPY || action_type == AUDPLY_ACTION_MOVE)
        {
            if (g_mmi_audply_init_done)
            {
                kal_wsprintf((kal_wchar*)list_path, "%c:\\", (S8)g_audply.present_list);
            }
            else
            {
                kal_wsprintf((kal_wchar*)list_path, "%c:\\", (S8)old_path[0]);
            }
            mmi_ucs2cat((PS8)list_path, (const PS8)MUSIC_FOLDER);
            if (g_audply.list_auto_gen &&
                !mmi_ucs2nicmp((const PS8)new_path, (const PS8)list_path, (U32)mmi_ucs2strlen((const PS8)list_path)) &&
                mmi_audply_is_audio_path((const PS8)new_path))
            {
                BOOL is_short;
                FMGR_FILE_INFO_STRUCT file_info;
                mmi_fmgr_get_file_info_by_path((S8*)new_path, &file_info);
                is_short = file_info.is_short;
                if (action_type == AUDPLY_ACTION_COPY)
                {
                    mmi_audply_update_append_file(is_short);
                }
                else if (action_type == AUDPLY_ACTION_MOVE)
                {
                    action_type = AUDPLY_ACTION_COPY;
                    mmi_audply_update_append_file(is_short);
                }
            }
        }
    }
#endif /*defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__) */
}


#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_rename_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_update_rename_folder(MMI_BOOL is_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.list_auto_gen && is_folder)
    {
        UI_character_type list_path[FMGR_MAX_PATH_LEN + 1];
        UI_character_type present_folder[FMGR_MAX_PATH_LEN + 1];
        
        kal_wsprintf((kal_wchar*)present_folder, "%c:\\", (S8)g_audply.present_list);
        mmi_ucs2cat((PS8)present_folder, (const PS8)MUSIC_FOLDER);
        kal_wsprintf((kal_wchar*)list_path, "%c:\\audio_play_list.txt", (S8)g_audply.present_list);

        /* rename: from "My Music" to "my music" and something else... */
        if (!mmi_ucs2nicmp((const PS8)update_cntx.old_path, (const PS8)update_cntx.new_path, (U32)mmi_ucs2strlen((const PS8)update_cntx.old_path)))
        {
            PRINT_INFORMATION("<Audply>[Auto update list] no need to modify list!"); 
            return;
        }
        /* rename: from to "my music" to something else... */
        else if (!mmi_ucs2nicmp((const PS8)update_cntx.old_path, (const PS8)present_folder, (U32)mmi_ucs2strlen((const PS8)present_folder)))
        {
            /*since it's renamed, create an empty play list file*/
            FS_HANDLE fd ;
            if((fd = FS_Open((PU16)list_path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN)) >= 0)
            {
                FS_Close(fd);
            }
            if (g_mmi_audply_init_done)
            {
                need_reload_list = TRUE;
            }
            PRINT_INFORMATION("<Audply>[Auto update list] delete list data file and reload list!");
            return;
        }
        /* rename: from other name to "my music" or "My Music" or something else... */
        else if (!mmi_ucs2nicmp((const PS8)update_cntx.new_path, (const PS8)present_folder, (U32)mmi_ucs2strlen((const PS8)present_folder)))
        {
            if (g_mmi_audply_init_done)
            {
                g_audply.seekable = TRUE;
                need_refresh_list = TRUE;
            }
            PRINT_INFORMATION("<Audply>[Auto update list] only need refresh list!");
            return;
        }
        else
        {
            PRINT_INFORMATION("<Audply>[Auto update list] no need to modify list! this is impossible!!!"); 
            return;
        }
    }
    else
    {
#ifdef __DRM_V02__

        PS8 ext = NULL;
    
        ext = mmi_ucs2rchr((const PS8)update_cntx.new_path, (U16)L'.');
        ext += 2;
        if (!mmi_ucs2nicmp((const PS8)ext, (const PS8)L"odf", (U32)mmi_ucs2strlen((const PS8)ext)))
        {
            /* this is an odf file */
            if (DRM_is_archive(0, (PU16)update_cntx.new_path))
            {
                /* it is a multi-part odf file. */
                update_cntx.is_folder = MMI_TRUE;
            }
        }
#endif  /* __DRM_V02__ */
        mmi_audply_update_do_rename_folder();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_set_cache_buff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_update_set_cache_buff(PS8 buffer_ptr, U32 size_limit)
{
    cache_cntx.file_offset = 0;
    cache_cntx.cache_offset = 0;
    cache_cntx.cache_size = 0;
    cache_cntx.cache_limit = 0;

    if (buffer_ptr != NULL)
    {
        cache_cntx.cache_buffer_ptr = buffer_ptr;
        cache_cntx.cache_limit = size_limit;
        return MMI_TRUE;
    }
    else
    {
        cache_cntx.cache_buffer_ptr = NULL;
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_fill_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_update_fill_cache(FS_HANDLE fd, U32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 read_size;
    S32 seek_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fd < 0)
    {
        PRINT_INFORMATION("Audply | Debug : fill cache - invalid parameter!");
        return MMI_FALSE;
    }

    if (cache_cntx.cache_buffer_ptr == NULL)
    {
        PRINT_INFORMATION("Audply | Debug : fill cache - buffer_ptr = NULL!");
        return MMI_FALSE;
    }
    
    if ((seek_ret = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
    {
        if (seek_ret != offset)
        {
            PRINT_INFORMATION("Audply | Debug : seek failed!");
            return MMI_FALSE;
        }

        if (FS_NO_ERROR <= (FS_Read(fd, cache_cntx.cache_buffer_ptr, cache_cntx.cache_limit, &read_size)))
        {
            cache_cntx.file_offset = offset;
            cache_cntx.cache_offset = 0;
            cache_cntx.cache_size = read_size;
            if (read_size == 0)
            {
                return MMI_FALSE;
            }
            else
            {
               return MMI_TRUE;
            }
        }
        else
        {
            PRINT_INFORMATION("Audply | Debug : fill cache - read file failed 1!");
            return MMI_FALSE;
        }
    }
    else
    {
        PRINT_INFORMATION("Audply | Debug : fill cache - seek file failed 2!");
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_backfill_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_update_backfill_cache(FS_HANDLE fd, U32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_size;
    S32 seek_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (fd < 0)
    {
        PRINT_INFORMATION("Audply | Debug : fill cache - invalid parameter!");
        return MMI_FALSE;
    }

    if (cache_cntx.cache_buffer_ptr == NULL)
    {
        PRINT_INFORMATION("Audply | Debug : fill cache - buffer_ptr = NULL!");
        return MMI_FALSE;
    }
    
    if ((seek_ret = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
    {
        if (seek_ret != offset)
        {
            PRINT_INFORMATION("Audply | Debug : seek failed!");
            return MMI_FALSE;
        }

        if (FS_NO_ERROR == (FS_Write(fd, cache_cntx.cache_buffer_ptr, cache_cntx.cache_size, &write_size)))
        {
            if (write_size == cache_cntx.cache_size)
            {
                //cache_cntx.file_offset = 0;
                cache_cntx.cache_offset = 0;
                cache_cntx.cache_size = 0;
                return MMI_TRUE;
            }
            else
            {
                PRINT_INFORMATION("Audply | Debug : backfill cache - write file error!");
                return MMI_FALSE;
            }
        }
        else
        {
            PRINT_INFORMATION("Audply | Debug : backfill cache - write file error1!");
            return MMI_FALSE;
        }
    }
    else
    {
        PRINT_INFORMATION("Audply | Debug : fill cache - seek file failed!");
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_do_rename_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_update_do_rename_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 modified = 0;
    PS8 filename = NULL;
    UI_character_type new_path_buffer[PLAY_LIST_RECORD_SIZE];
    MMI_BOOL need_reload_cache = MMI_TRUE;
    MMI_BOOL need_backfill_cache = MMI_FALSE;
    MMI_BOOL is_short = MMI_FALSE;
    U32 record_in_cache = 0;
    PS8 path = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_cntx.present_list == -1)
    {
        if (g_mmi_audply_init_done)
        {
            kal_wsprintf((kal_wchar*)new_path_buffer, "%c:\\audio_play_list.txt", (S8)g_audply.present_list);
        }
        else
        {
            kal_wsprintf((kal_wchar*)new_path_buffer, "%c:\\audio_play_list.txt", (S8)update_cntx.old_path[0]);
        }
        if (FS_NO_ERROR > (update_cntx.present_list = FS_Open((PU16)new_path_buffer, FS_READ_WRITE)))
        {
            PRINT_INFORMATION("<Audply>[Auto update list] can not open present list file!");
            return;
        }

        FS_Seek(update_cntx.present_list, 0, FS_FILE_BEGIN);
        if (!mmi_audply_update_set_cache_buff((PS8)g_mmi_update_list_buff, g_mmi_update_list_buff_size))
        {
            MMI_ASSERT(0);
        }
        update_cntx.offset = 0;
    }
    
    for (modified = 0; update_cntx.counter < g_audply.n_total_items; )
    {
        if (need_reload_cache)
        {
            if (!mmi_audply_update_fill_cache(update_cntx.present_list, update_cntx.offset))
            {
                PRINT_INFORMATION("<Audply>[Auto update list] load cache failed!"); 
                break;
            }
            else
            {
                need_reload_cache = MMI_FALSE;
                record_in_cache = (cache_cntx.cache_size / PLAY_LIST_RECORD_SIZE);
                update_cntx.offset += cache_cntx.cache_size;
            }
        }
        
        do
        {
            path = cache_cntx.cache_buffer_ptr + cache_cntx.cache_offset;
			is_short = MMI_FALSE;
            if (IS_SNAME2(path))
            {
                is_short = MMI_TRUE;
            }
            
            MARK_DRIVE_PS8(path);
            if (!mmi_ucs2nicmp((const PS8)path, 
                            (const PS8)update_cntx.old_path, 
                            update_cntx.old_path_len))
            {
                if (update_cntx.is_folder)
                {
                    filename = path + (mmi_ucs2strlen((const PS8)update_cntx.old_path) * ENCODING_LENGTH);
                    mmi_ucs2cpy((PS8)new_path_buffer, (const PS8)update_cntx.new_path);
                    mmi_ucs2cat((PS8)new_path_buffer, (const PS8)filename);

                    if (is_short)
                    {
                        MARK_SNAME(new_path_buffer);
                    }
                    else
                    {
                        MARK_LNAME(new_path_buffer);
                    }
                    if (FMGR_MAX_PATH_LEN < mmi_ucs2strlen((const PS8)new_path_buffer))
                    {
                        PRINT_INFORMATION("<Audply>[Auto update list] new path is too long!");
                        break;
                    }
                    mmi_ucs2ncpy((PS8)path, (const PS8)new_path_buffer, PLAY_LIST_RECORD_SIZE);
                }
                else
                {
                    MARK_LNAME(update_cntx.new_path);
                    mmi_ucs2ncpy((PS8)path, 
                        (const PS8)update_cntx.new_path, PLAY_LIST_RECORD_SIZE);

                    /* reset loading file's filename and title in g_audply */
                    if (g_mmi_audply_init_done)
                    {
                        U32 index = update_cntx.counter + (cache_cntx.cache_size / PLAY_LIST_RECORD_SIZE) - record_in_cache;
                        if (index == g_audply.pick_index)
                        {
                            PS8 filename = mmi_ucs2rchr((const PS8)update_cntx.new_path, (U16)L'\\');
                            PS8 dot = mmi_ucs2rchr((const PS8)update_cntx.new_path, (U16)L'.');
                            
                            mmi_ucs2ncpy((PS8)g_audply.filefullname, 
                                (const PS8)update_cntx.new_path, PLAY_LIST_RECORD_SIZE);
                            mmi_ucs2ncpy((PS8)g_audply.title, (const PS8)(filename + 2), (U32)(((dot - 2) - filename) / 2));
			    MARK_DRIVE(g_audply.filefullname);
                        }
                    }
                }
                need_backfill_cache = MMI_TRUE;
            }
			else
			{
				if (is_short)
				{
					MARK_SNAME2(path);
				}
				else
				{
					MARK_LNAME2(path);
				}
			}
			cache_cntx.cache_offset += PLAY_LIST_RECORD_SIZE;

        } while((--record_in_cache) > 0);

        update_cntx.counter += (cache_cntx.cache_size / PLAY_LIST_RECORD_SIZE);

        if (need_backfill_cache)
        {
            need_backfill_cache = MMI_FALSE;
            if (!mmi_audply_update_backfill_cache(update_cntx.present_list, cache_cntx.file_offset))
            {                
                PRINT_INFORMATION("<Audply>[Auto update list] backfill cache failed!"); 
                break;
            }
        }
        need_reload_cache = MMI_TRUE;
    }
    FS_Close(update_cntx.present_list);
    /* clear dynamic list buffer */
    if (g_mmi_audply_init_done)
    {
        g_audply.buff_head = 0;
        g_audply.n_buff_items = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_delete_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_update_delete_folder(MMI_BOOL is_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("<Audply>[Auto update list] mmi_audply_update_delete_folder, auto=%d,folder=%d",g_audply.list_auto_gen, is_folder);
    
    if (g_audply.list_auto_gen && is_folder)
    {
        UI_character_type list_path[FMGR_MAX_PATH_LEN + 1];
        UI_character_type present_folder[FMGR_MAX_PATH_LEN + 1];
        
        kal_wsprintf((kal_wchar*)present_folder, "%c:\\", (S8)g_audply.present_list);
        mmi_ucs2cat((PS8)present_folder, (const PS8)MUSIC_FOLDER);
        kal_wsprintf((kal_wchar*)list_path, "%c:\\audio_play_list.txt", (S8)g_audply.present_list);

        /* delete: delete "My Music" folder. */
              
        if (!mmi_ucs2cmp((const PS8)update_cntx.old_path, (const PS8)present_folder))
        {
            /*since it's renamed, create an empty play list file*/
            FS_HANDLE fd ;
            if((fd = FS_Open((PU16)list_path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN)) >= 0)
            {
                FS_Close(fd);
            }
            if (g_mmi_audply_init_done)
            {
                need_reload_list = TRUE;
            }
            PRINT_INFORMATION("<Audply>[Auto update list] delete list data file and reload list!");
            return;
        }
        else
        {
            PRINT_INFORMATION("<Audply>[Auto update list] no need to modify list! this is impossible!!!"); 
            return;
        }
    }
    else
    {
        mmi_audply_update_do_delete_folder();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_do_rename_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_update_do_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[PLAY_LIST_RECORD_SIZE];
    PS8 path = NULL;
    
    S32 total_records = g_audply.n_total_items;    
    U32 modified = 0;
    U32 record_in_cache = 0;
    U32 buffer_size; 
    
    MMI_BOOL need_reload_cache = MMI_TRUE;
    MMI_BOOL is_short = MMI_FALSE;
    MMI_BOOL fs_error = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_cntx.present_list == -1)
    {
        if (g_mmi_audply_init_done)
        {
            kal_wsprintf((kal_wchar*)buffer, "%c:\\audio_play_list.txt", (S8)g_audply.present_list);
        }
        else
        {
            kal_wsprintf((kal_wchar*)buffer, "%c:\\audio_play_list.txt", (S8)update_cntx.old_path[0]);
        }
        if (FS_NO_ERROR > (update_cntx.present_list = FS_Open((PU16)buffer, FS_READ_WRITE)))
        {
            PRINT_INFORMATION("<Audply>[Auto update list] can not open present list file!");
            return;
        }

        if (update_cntx.temp_file == -1)
        {
            kal_wsprintf((kal_wchar*)buffer, "%c:\\~audio_play_list.txt", (S8)g_audply.present_list);
            update_cntx.temp_file= FS_Open((PU16)buffer, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
            ASSERT(update_cntx.temp_file != 0);
            if (update_cntx.temp_file < 0)
            {
                PRINT_INFORMATION("<Audply>[Auto update list] can not create temp file!!!");
                FS_Close(update_cntx.present_list);
                return;
            }
        }

        FS_Seek(update_cntx.present_list, 0, FS_FILE_BEGIN);
        if (!mmi_audply_update_set_cache_buff((PS8)g_mmi_update_list_buff, g_mmi_update_list_buff_size))
        {
            MMI_ASSERT(0);
        }
        update_cntx.offset = 0;
    }
    
    for (modified = 0; update_cntx.counter < total_records; )
    {
        if (need_reload_cache)
        {
            if (!mmi_audply_update_fill_cache(update_cntx.present_list, cache_cntx.file_offset))
            {
                PRINT_INFORMATION("<Audply>[Auto update list] load cache failed!"); 
                fs_error = MMI_TRUE;
                break;
            }
            else
            {
                need_reload_cache = MMI_FALSE;
                record_in_cache = (cache_cntx.cache_size / PLAY_LIST_RECORD_SIZE);
                cache_cntx.file_offset += cache_cntx.cache_size;
            }
        }
        
        do
        {
            path = cache_cntx.cache_buffer_ptr + cache_cntx.cache_offset;
            is_short = MMI_FALSE;
            if (IS_SNAME2(path))
            {
                is_short = MMI_TRUE;
            }
            
            MARK_DRIVE_PS8(path);
            if (!mmi_ucs2nicmp((const PS8)path, 
                            (const PS8)update_cntx.old_path, 
                            update_cntx.old_path_len))
            {
                U8 i = 0;
                for (i = 0; i < record_in_cache; i++)
                {
                    memcpy((path + i * PLAY_LIST_RECORD_SIZE), (path + (i + 1) * PLAY_LIST_RECORD_SIZE), PLAY_LIST_RECORD_SIZE);
                }
                /* update relative variable in struct "g_audply" */
                if (g_mmi_audply_init_done)
                {
                    U32 index = update_cntx.counter;

                    if ((--total_records) < 0)
                    {
                        total_records = 0;
                    }

                    if (g_audply.pick_index > index)
                    {
                        if ((--g_audply.pick_index) < 0)
                        {
                            g_audply.pick_index = 0;
                        }
                    }
                    else if (g_audply.pick_index == index)
                    {
                        mmi_audply_clear_play_seconds();
                    }
                }
                cache_cntx.cache_size -= PLAY_LIST_RECORD_SIZE;
                update_cntx.deleted++;
            } 
            else
            {
                if (is_short)
                {
                    MARK_SNAME2(path);
                }
                else
                {
                    MARK_LNAME2(path);
                }
                update_cntx.counter++;
                cache_cntx.cache_offset += PLAY_LIST_RECORD_SIZE;
			}
            
        } while((--record_in_cache) > 0);
        buffer_size = cache_cntx.cache_size;

        if (!mmi_audply_update_backfill_cache(update_cntx.temp_file, update_cntx.offset))
        {                
            PRINT_INFORMATION("<Audply>[Auto update list] backfill cache failed!"); 
            fs_error = MMI_TRUE;
            break;
        }
        else
        {
            update_cntx.offset += buffer_size;
        }

        need_reload_cache = MMI_TRUE;
    }

    if (!fs_error)
    {   
        S32 seek_ret;
        seek_ret = FS_Seek(update_cntx.present_list, 
            update_cntx.counter * PLAY_LIST_RECORD_SIZE, FS_FILE_BEGIN);
        
        if ((update_cntx.counter * PLAY_LIST_RECORD_SIZE) != seek_ret)
        {
            fs_error = MMI_TRUE;
        }
        else
        {
            if (FS_NO_ERROR == FS_Truncate(update_cntx.present_list))
            {
                FS_Close(update_cntx.present_list);
                FS_Close(update_cntx.temp_file);

                /* replace old file */
                kal_wsprintf((kal_wchar*)update_cntx.old_path, "%c:\\~audio_play_list.txt", (S8)g_audply.present_list);
                kal_wsprintf((kal_wchar*)update_cntx.new_path, "%c:\\audio_play_list.txt", (S8)g_audply.present_list);
                if (FS_NO_ERROR == FS_Delete((const PU16)update_cntx.new_path))
                {
                    FS_Rename((const PU16)update_cntx.old_path, (const PU16)update_cntx.new_path);
                    g_audply.n_total_items = total_records;
                }
                else
                {
                    FS_Delete((const PU16)update_cntx.old_path);
                }
            }
            else
            {
                fs_error = MMI_TRUE;
            }
        }
    }


    if (fs_error)
    {
        FS_Close(update_cntx.present_list);
        FS_Close(update_cntx.temp_file);
        
        kal_wsprintf((kal_wchar*)update_cntx.old_path, "%c:\\~audio_play_list.txt", (S8)g_audply.present_list);
        FS_Delete((const PU16)update_cntx.old_path);
    }

    /* clear dynamic list buffer */
    if (g_mmi_audply_init_done)
    {
        if (g_audply.pick_index == g_audply.n_total_items)
        {
    	    if (g_audply.n_total_items == 0)
    	    {
    		    mmi_audply_init_playlist();
    	    }
    	    else
    	    {
                g_audply.buff_head = 0;
                g_audply.n_buff_items = 0;
    		    mmi_audply_start_playlist_at(0);
    		    mmi_audply_apply_picked_file();
            }
        }
        else if (g_audply.n_total_items == 0)
        {
            mmi_audply_init_playlist();
        }
        else
        {
            g_audply.buff_head = 0;
            g_audply.n_buff_items = 0;
            mmi_audply_start_playlist_at(g_audply.pick_index);
            mmi_audply_apply_picked_file();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_check_need_modify
 * DESCRIPTION
 *  check a file path whether in list.
 * PARAMETERS
 *  PS8         [IN]
 * RETURNS
 *  BOOL
 *****************************************************************************/
static U32 mmi_audply_update_does_record_in_list(const PS8 list_path, const PS8 file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 match = 0;
    U32 counter;
    U32 read_size;
    FS_HANDLE fd;
    UI_character_type buffer[FMGR_MAX_PATH_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (FS_NO_ERROR > (fd = FS_Open((PU16)list_path, FS_READ_WRITE)))
    {
        PRINT_INFORMATION("Audply | Debug : [auto update list] can not open present list file!");
        return 0;
    }
        
    for (counter = 0; counter < g_audply.n_total_items; counter++)
    {
        if (FS_NO_ERROR== FS_Read(fd, &buffer, PLAY_LIST_RECORD_SIZE, &read_size))
        {
            if (read_size != PLAY_LIST_RECORD_SIZE)
            {  
                /* get end of file. */
                PRINT_INFORMATION("Audply | Debug : [auto update list]break from seek loop!"); 
                break;
            }
            
            MARK_DRIVE(buffer);
            if (!mmi_ucs2nicmp((const PS8)file_path, (const PS8)buffer, (U32)mmi_ucs2strlen((const PS8)file_path)))
            {
                match++;
            }
        }
    }
    FS_Close(fd);

    return match;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_append_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_audply_update_append_file(MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_size;
    UI_character_type buffer[FMGR_MAX_PATH_LEN + 1];
#ifdef __DRM_V02__
    MMI_BOOL multi_part_odf = MMI_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_cntx.present_list == -1)
    {
        if (g_mmi_audply_init_done)
        {
            kal_wsprintf((kal_wchar*)buffer, "%c:\\audio_play_list.txt", (S8)g_audply.present_list);
        }
        else
        {
            kal_wsprintf((kal_wchar*)buffer, "%c:\\audio_play_list.txt", (S8)update_cntx.old_path[0]);
        }
        if (FS_NO_ERROR > (update_cntx.present_list = FS_Open((PU16)buffer, FS_READ_WRITE)))
        {
            PRINT_INFORMATION("<Audply>[Auto update list] can not open present list file!");
            return;
        }
#ifdef __DRM_V02__
        {
            PS8 ext = NULL;
        
            ext = mmi_ucs2rchr((const PS8)update_cntx.new_path, (U16)L'.');
            ext += 2;
            if (!mmi_ucs2nicmp((const PS8)ext, (const PS8)L"odf", (U32)mmi_ucs2strlen((const PS8)ext)))
            {
                /* this is an odf file */
                if (DRM_is_archive(0, (PU16)update_cntx.new_path))
                {
                    multi_part_odf = MMI_TRUE;
                }
            }
        }
#endif  /* __DRM_V02__ */
        FS_Seek(update_cntx.present_list, (g_audply.n_total_items * PLAY_LIST_RECORD_SIZE), FS_FILE_BEGIN);

#ifdef __DRM_V02__
        if (multi_part_odf)
        {
            /* it is a multi-part odf file. */
            FS_HANDLE multi_part_handle;
            drm_file_info_struct drm_file_info;
            UI_character_type content_name[FMGR_MAX_FILE_LEN + 1];
            UI_character_type ext[FMGR_MAX_EXT_LEN + 1];
            UI_character_type buffer[FMGR_MAX_PATH_LEN + 1];
            
            void* find_cntx = NULL;
            
            find_cntx = DRM_get_find_cntx();
            multi_part_handle = DRM_find_firstN(
                                        find_cntx,
                                        update_cntx.new_path, 
                                        0, 
                                        0,
                                        &drm_file_info,
                                        content_name,
                                        (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                                        0);

            if (multi_part_handle >= FS_NO_ERROR)
            {
                do
                {
                    mmi_audply_extract_ext(content_name, ext);
                    if (mmi_audply_lookup_audio_file_format(ext) >= 0)
                    {
                        if (mmi_ucs2strlen((const PS8)update_cntx.new_path) + mmi_ucs2strlen((const PS8)content_name) <= FMGR_MAX_PATH_LEN)
                        {
                            mmi_ucs2cpy((PS8)buffer, (const PS8)update_cntx.new_path);
                            mmi_ucs2cat((PS8)buffer, (const PS8)L"\\");
                            mmi_ucs2cat((PS8)buffer, (PS8)content_name);
                            MARK_LNAME(buffer);

                            if ((FS_Write(update_cntx.present_list, buffer, PLAY_LIST_RECORD_SIZE, (U32*)&write_size)) != FS_NO_ERROR)
                            {
                                PRINT_INFORMATION("<Audply>[Auto update list] write list file failed!");
                                DRM_find_close(find_cntx, multi_part_handle);
                                FS_Close(update_cntx.present_list);
                                return;
                            }
                            else
                            {
                                g_audply.n_total_items++;
                            }
                        }
                    }
                } while (FS_NO_ERROR == DRM_find_nextN(
                                find_cntx,
                                multi_part_handle, 
                                &drm_file_info,
                                content_name,
                                (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                                1));
                DRM_find_close(find_cntx, multi_part_handle);
            }
            FS_Close(update_cntx.present_list);
        }
        else
#endif  /* __DRM_V02__ */
        {
            if(is_short)
            {
                MARK_SNAME(update_cntx.new_path);
            }
            else
            {
                MARK_LNAME(update_cntx.new_path);
            }

            if (FS_NO_ERROR > FS_Write(update_cntx.present_list, update_cntx.new_path, PLAY_LIST_RECORD_SIZE, &write_size))
            {
                PRINT_INFORMATION("<Audply>[Auto update list] write list file failed!");
                FS_Close(update_cntx.present_list);
                return;
            }
            FS_Close(update_cntx.present_list);
            g_audply.n_total_items++;
        }
        
	if (g_audply.n_total_items == 1)
	{
	    mmi_audply_start_playlist_at(0);
            mmi_audply_apply_picked_file();
	}
    }    
}

#endif /* defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__) */

#endif /* __MMI_AUDIO_PLAYER__ */ 

