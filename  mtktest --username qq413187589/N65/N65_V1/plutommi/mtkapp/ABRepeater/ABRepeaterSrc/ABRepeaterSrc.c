/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  ABRepeaterSrc.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   AB Repeater main program
*
* Author:
* -------
*  Tarun Bakshi
*
*============================================================================
*             HISTORY
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
 * created by clearfsimport
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
 * 
* 
* 
* 
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_AB_REPEATER__
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "CallmanagementIdDef.h"

#include "MainMenuDef.h"
#include "FunAndGamesDefs.h"
#include "CustomCfg.h"


#include "ProfileGprots.h"
#include "SettingProfile.h"

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
#include "FileMgr.h"
#include "ProfileMgrGProt.h"
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 


#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "FileManagerGProt.h"
#include "FileManagerDef.h"
#include "FileMgr.h"

#include "ABRepeaterResDef.h"
#include "ABRepeaterDef.h"
#include "ABRepeaterType.h"
#include "ABRepeaterProt.h"
#include "ABRepeaterMainScreen.h"
#include "DataMgr.h"
#ifdef __DRM_SUPPORT__
#ifdef __MTK_TARGET__
#include "Drm_gprot.h"
#endif /* __MTK_TARGET__ */ 
#endif /* __DRM_SUPPORT__ */ 
#include "Conversions.h"

#include "USBDeviceGprot.h"
#include "gpioInc.h"    /* TurnOnBacklight */


abrepeat_struct g_abrepeat;

#define MAX_FWD_REW_DIV_VAL 16
U16 g_mmi_abrepeat_option_highlighted_item;

/* drives and paths */
S16 phoneDrvLetter_ab;
S16 cardDrvLetter_ab;
UI_character_type root_dir_phone_ab[4];
UI_character_type root_dir_card_ab[4];
UI_character_type phone_list_name_ab[FMGR_MAX_FILE_LEN + 4];
UI_character_type card_list_name_ab[FMGR_MAX_FILE_LEN + 4];

/* manish variables */
S32 g_mmi_abrepeat_Back_Stop = FALSE;
S32 g_mmi_abrepeat_Option_lsk_stop = FALSE;
extern U16 g_mmi_abrepeat_Callback;
S32 g_mmi_abrepeat_interrupt_exit = FALSE;


static mmi_data_record_store_type g_abrepeat_ab_record_store;
U8 g_mmi_abrepeat_setting_storage = 0;

ab_data_struct g_mmi_abrepeat_abplay_data[MAX_AB_POINT];
BOOL g_mmi_abrepeat_record_exist[MAX_AB_POINT];
BOOL g_mmi_abrepeat_start_progress = FALSE;
BOOL g_mmi_abrepeat_end_progress = FALSE;
BOOL g_mmi_abrepeat_first_time_entry = TRUE;
BOOL g_mmi_abrepeat_has_suspend_bg_play = FALSE;
extern const abrepeat_skin_struct g_abrepeat_skins[NO_OF_AB_SKIN];
BOOL g_mmi_abrepeat_section_deleted = FALSE;    /* for checking the release of button after deletion */
signed char g_mmi_abrepeat_draw_refer_state[MAX_AB_POINT] = 
{
    AB_SECTION_DISABLED, AB_SECTION_DISABLED,
        AB_SECTION_DISABLED, AB_SECTION_DISABLED,
        AB_SECTION_DISABLED, AB_SECTION_DISABLED,
        AB_SECTION_DISABLED, AB_SECTION_DISABLED,
        AB_SECTION_DISABLED, AB_SECTION_DISABLED
};

#ifdef SIMULATOR_TESTING
BOOL inscreen_first_time = TRUE;
extern U32 offset;
#endif /* SIMULATOR_TESTING */ 

#ifdef __MTK_TARGET__
#define CACHE_HEADER_SIZE sizeof(cache_header_struct)

typedef struct
{
    kal_uint32 self_checksum;
    kal_uint32 audio_checksum;
    kal_uint32 audio_file_size;
    kal_uint32 duration;
} cache_header_struct;

static U32 build_cache_progress;
static FS_HANDLE fd_idx;
static BOOL audio_checksum_done;

static void *g_abrepeat_app_mem_pool = NULL;
static KAL_ADM_ID g_abrepeat_adm_id = NULL;

static U8 *file_buf_p = NULL;
static U8 *proc_buf_p = NULL;

#ifdef __MTK_TARGET__
__align(4)
#endif /* __MTK_TARGET__ */
static U8 cache[ABR_CACHE_SIZE];

extern kal_bool aud_util_build_cache_start( kal_wchar *filename, 
                                           void* cache_p, kal_int32 cache_size, 
                                           void *file_buf, kal_int32 file_buf_size, 
                                           void *proc_buf, kal_int32 proc_buf_size );
extern void aud_util_build_cache_stop( void );
extern kal_bool aud_util_build_cache_process( kal_uint32 *progress_p );
extern kal_uint32 aud_util_build_cache_get_duration( void );
extern kal_uint32 med_crc_calculate(kal_uint8 const *data, kal_uint32 length);
#endif /* __MTK_TARGET__ */


static U8 mmi_abrepeat_util_count_optional_drv(void);


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_is_record_valid
* DESCRIPTION
*  check whether is the data record is valid
* PARAMETERS
*  record      [?]     
* RETURNS
* BOOL
*****************************************************************************/
BOOL mmi_abrepeat_is_record_valid(ab_data_struct *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record->keyindex < MAX_AB_POINT && record->abstart < record->abend)
    {
        return TRUE;
    }
    return FALSE;
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_select_file
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_select_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    UI_character_type storagePath[FMGR_MAX_PATH_LEN + 1];
    UI_character_type absStoragePath[FMGR_MAX_PATH_LEN + 1];
    UI_string_type ptr;
#ifdef __MTK_TARGET__
    U32 read_size;
    U32 cache_checksum;
    void* buf;
    FS_HANDLE fd;
    kal_int32 fs_result;
#endif
    /* manish here */
    S32 len;
    UI_character_type ext[FMGR_MAX_EXT_LEN + 2];
    U8 i;
    UI_character_type tmpTitle[FMGR_MAX_FILE_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!fmgr_exe_app_call_back())
    {
        return;
    }
    
    /* Extract the file name without extension for saving the ab points for this file */
    mmi_ucs2cpy((S8*) storagePath, (S8*) g_abrepeat.filefullname);
    /* manish to ensure abs file created ok for all files even with files 
    having dots inbetween */
    len = mmi_ucs2strlen((S8*) storagePath);
    ptr = &storagePath[len];
    for (;len > 0; ptr--,len--)
    {
        if (*ptr == L'.')
        {
            break;
        }
    }
    
    ASSERT(*ptr == L'.');
    
    mmi_ucs2cpy((S8*)ext, (S8*)ptr);
    
    mmi_ucs2cpy((S8*) ptr, (S8*) L".abs");
    
    g_abrepeat.cur_mode = AB_SETTING_MODE;
    g_abrepeat.is_init_scrolling_text = FALSE;
    g_abrepeat.is_replay_on = FALSE;
    
    /* Open the file for saving and retreiving the ab points */
    
#ifdef __MTK_TARGET__
#ifdef __DRM_V02__
    if(DRM_is_archive(NULL, (PU16)storagePath))
    {
        PS8 sepa = mmi_ucs2rchr((S8*)storagePath, (U16) L'\\');
        *sepa = (S8)'_';
    }
#endif /*__DRM_V02__*/
#endif /*__MTK_TARGET__*/

    mmi_ucs2cpy((S8*)absStoragePath, (S8*)storagePath);
    result = mmi_data_init_record_store(&g_abrepeat_ab_record_store, (S8*) absStoragePath, sizeof(ab_data_struct));
    
    mmi_ucs2cpy((PS8)tmpTitle, (PS8)mmi_fmgr_extract_file_name((PS8)g_abrepeat.filefullname)); 
    if(g_abrepeat.is_short_name)
    {
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) g_abrepeat.title,
            (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH,
            (U8*) tmpTitle,
            g_chset_text_encoding);
    }
    else
    {
        mmi_ucs2cpy((PS8)g_abrepeat.title, (PS8)tmpTitle);
    }
#if !defined(__MMI_SHOW_DAF_FILE_EXT__)   
    for (i = 0; i <= FMGR_MAX_EXT_LEN; i++)
    {
        if (ext[i] >= 97 && ext[i] <= 122)
        {
            ext[i] -= 32;
        }
    }
    
    if (mmi_ucs2cmp((PS8)ext, (PS8)L".MP3") == 0) 
    {
        mmi_abrepeat_hide_ext_name((PS8)g_abrepeat.title);
    }    
#endif /*!defined(__MMI_SHOW_DAF_FILE_EXT__) */
    
    /* calculate audio content checksum */
#ifdef __MTK_TARGET__
    audio_checksum_done = FALSE;
    build_cache_progress = 0;
#ifdef __DRM_SUPPORT__
    fs_result = fd = DRM_open_file( (PU16)g_abrepeat.filefullname, FS_READ_ONLY, DRM_PERMISSION_PLAY );
    if(fd >= 0)
    {
        if (!DRM_validate_permission(fd, NULL, DRM_PERMISSION_PLAY))
        {
            DRM_close_file(fd);
            DisplayPopup( (PU8)GetString( STR_GLOBAL_DRM_PROHIBITED ), IMG_GLOBAL_WARNING, 0, 1000, (U8)WARNING_TONE );
            return;
        }
    }

#else
    fs_result = fd = FS_Open( g_abrepeat.filefullname, FS_READ_ONLY );
#endif
    if( fd >= 0 )
    {
        buf = get_ctrl_buffer( 1024 );
        read_size = 0;
#ifdef __DRM_SUPPORT__
        if( (fs_result = DRM_read_file( fd, buf, 1024, &read_size )) == FS_NO_ERROR && read_size != 0 )
#else
            if( (fs_result = FS_Read( fd, buf, 1024, &read_size )) == FS_NO_ERROR && read_size != 0 )
#endif
            {
                g_abrepeat.audio_checksum = med_crc_calculate( (kal_uint8 const *) buf, read_size );
                /*add audio file size for validation process */
#ifdef __DRM_SUPPORT__   
                if ((fs_result = DRM_file_size(fd, &g_abrepeat.audio_file_size)) == FS_NO_ERROR && g_abrepeat.audio_file_size != 0) 
#else 
                    if ((fs_result = FS_GetFileSize(fd, &g_abrepeat.audio_file_size)) == FS_NO_ERROR && g_abrepeat.audio_file_size != 0) 
#endif
                    {
                        audio_checksum_done = TRUE;
                    }
            }
            
#ifdef __DRM_SUPPORT__
            DRM_close_file( fd );
#else
            FS_Close( fd );
#endif
            free_ctrl_buffer( buf );
    }
    
    /* open idx file */
    if( audio_checksum_done )
    {
        mmi_ucs2cpy((S8*) ptr, (S8*) L".idx");
        if( (fd_idx = FS_Open( storagePath, FS_CREATE | FS_ATTR_HIDDEN )) >= 0 )
        {
            if( FS_Read( fd_idx, (void *)cache, ABR_CACHE_SIZE, &read_size ) == FS_NO_ERROR 
                && read_size == ABR_CACHE_SIZE )
            {
                if( g_abrepeat.audio_checksum == ((cache_header_struct*)&cache[0])->audio_checksum 
                    && g_abrepeat.audio_file_size == ((cache_header_struct*)&cache[0])->audio_file_size)
                {
                    cache_checksum = med_crc_calculate( (kal_uint8 const *)
                        &cache[CACHE_HEADER_SIZE], ABR_CACHE_SIZE-CACHE_HEADER_SIZE );
                    if( cache_checksum == ((cache_header_struct*)&cache[0])->self_checksum )
                    {
                        FS_Close( fd_idx );
                        g_abrepeat.total_offset = ((cache_header_struct*)&cache[0])->duration;
                        g_abrepeat.fwd_rew_units = (U32) (g_abrepeat.total_offset / MAX_FWD_REW_DIV_VAL);
                        g_mmi_abrepeat_first_time_entry = TRUE;
                        build_cache_progress = 100;
                        mmi_abrepeat_entry_main();  /* call main setting screen */
                        return;
                    }
                }
            }
        }
        
        /*if need build cache, delete the abs file and reinit data*/
        FS_Delete((WCHAR*)absStoragePath);
        mmi_data_init_record_store(&g_abrepeat_ab_record_store, (S8*) absStoragePath, sizeof(ab_data_struct));
        
        mmi_abrepeat_build_cache_start();
    }
    else
#endif /* __MTK_TARGET__ */
    {
        result = mdi_audio_get_duration( g_abrepeat.filefullname, &g_abrepeat.total_offset ); 
        g_abrepeat.fwd_rew_units = (U32) (g_abrepeat.total_offset/MAX_FWD_REW_DIV_VAL);
        if( result == 0 )
        {
            g_mmi_abrepeat_first_time_entry = TRUE;
            mmi_abrepeat_entry_main(); // call main setting screen 
        }
#ifdef __MTK_TARGET__
#ifdef __DRM_SUPPORT__
        else if( fs_result == DRM_RESULT_NO_PERMISSION )
            DisplayPopup( (PU8)GetString( STR_GLOBAL_DRM_PROHIBITED ), IMG_GLOBAL_WARNING, 0, 1000, (U8)WARNING_TONE );
#endif /*__DRM_SUPPORT__*/
#endif /* __MTK_TARGET__ */
        else
            DisplayPopup( (PU8)GetString( mmi_abrepeat_err_str( (S32)result ) ), IMG_GLOBAL_WARNING, 0, 1000, (U8)WARNING_TONE );
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_enter_highlight_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_enter_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(mmi_abrepeat_select_file, KEY_EVENT_UP);
    
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
    /* 5 Register function for right  key */
    SetKeyHandler(mmi_abrepeat_select_file, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
    g_mmi_abrepeat_Back_Stop = FALSE;
    
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_build_cache_ptr
* DESCRIPTION
*  get the cache pointer
* PARAMETERS
*  void
* RETURNS
*  void*
*****************************************************************************/
void* mmi_abrepeat_build_cache_ptr(void)
{
    void *cache_p = NULL;
    
#ifdef __MTK_TARGET__
    if( build_cache_progress == 100 )
        cache_p = (void *)&cache[CACHE_HEADER_SIZE];
#endif /* __MTK_TARGET__ */
    
    return cache_p;
}

#ifdef __MTK_TARGET__

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_free_asm_resource
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_free_asm_resource(void)
{
    kal_status ret;
    
    if(g_abrepeat_adm_id != NULL)
    {
        kal_adm_free(g_abrepeat_adm_id, file_buf_p);
        file_buf_p = NULL;
        kal_adm_free(g_abrepeat_adm_id, proc_buf_p);
        proc_buf_p = NULL;
        
        ret = kal_adm_delete(g_abrepeat_adm_id);
        ASSERT(ret == KAL_SUCCESS);
        g_abrepeat_adm_id = NULL;
    }
    
    if(g_abrepeat_app_mem_pool)
    {
        applib_mem_ap_free(g_abrepeat_app_mem_pool);
        g_abrepeat_app_mem_pool = NULL;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_app_asm_stop_cb
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_app_asm_stop_cb(void)
{
    mmi_abrepeat_free_asm_resource();
    
    ASSERT(g_abrepeat_adm_id == NULL);
    ASSERT(g_abrepeat_app_mem_pool == NULL);
    
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_AB_REPEATER, KAL_TRUE);
    
    DeleteUptoScrID(SCR_ID_AB_BUILD_CACHE);
    DeleteScreenIfPresent(SCR_ID_AB_BUILD_CACHE);
    
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_app_mem_success_callback
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_app_mem_success_callback(void)
{
    g_abrepeat_app_mem_pool = 
        applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AB_REPEATER, ABREPEAT_APP_ASM_BUF_SIZE);
    ASSERT(g_abrepeat_app_mem_pool != NULL);
    
    mmi_abrepeat_build_cache_start();
}  

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_build_cache_start
* DESCRIPTION
*  start the process of build cache
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_build_cache_start(void)
{
    if(g_abrepeat_app_mem_pool == NULL)
    {
        g_abrepeat_app_mem_pool = 
            applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AB_REPEATER, ABREPEAT_APP_ASM_BUF_SIZE);
        
        if (g_abrepeat_app_mem_pool == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_AB_REPEATER,
                0,
                ABREPEAT_APP_ASM_BUF_SIZE,
                mmi_abrepeat_app_mem_success_callback);
            return;
        }
    }
    
    ASSERT(g_abrepeat_app_mem_pool != NULL);
    g_abrepeat_adm_id = kal_adm_create((void*)g_abrepeat_app_mem_pool, 
        ABREPEAT_APP_ASM_BUF_SIZE, NULL, KAL_FALSE);
    ASSERT(g_abrepeat_adm_id != NULL);
    proc_buf_p = (U8*)kal_adm_alloc(g_abrepeat_adm_id, ABR_PROC_BUF_SIZE);
    ASSERT(proc_buf_p != NULL);
    file_buf_p = (U8*)kal_adm_alloc(g_abrepeat_adm_id, ABR_FILE_BUF_SIZE);
    ASSERT(file_buf_p != NULL);

    
    aud_util_build_cache_start( g_abrepeat.filefullname, 
        (void *)&cache[CACHE_HEADER_SIZE], ABR_CACHE_SIZE-CACHE_HEADER_SIZE, 
        (void *)file_buf_p, ABR_FILE_BUF_SIZE, 
        (void *)proc_buf_p, ABR_PROC_BUF_SIZE );
    
    mmi_abrepeat_entry_build_cache();

}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_build_cache_process
* DESCRIPTION
*  build cache process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_build_cache_process(void)
{
    U32 write_size;
    U32 prev_progress = build_cache_progress;
    S32 fs_result = FS_NO_ERROR;
    
    if((build_cache_progress == 100) || aud_util_build_cache_process( &build_cache_progress ))
    {
        if( prev_progress != build_cache_progress )
            UpdateCategory402Value( build_cache_progress, NULL);
        
        if( build_cache_progress == 100 )
        {
            g_abrepeat.total_offset = aud_util_build_cache_get_duration();
            ((cache_header_struct*)&cache[0])->duration = g_abrepeat.total_offset;
            ((cache_header_struct*)&cache[0])->self_checksum = 
                med_crc_calculate( (kal_uint8 const *)&cache[CACHE_HEADER_SIZE], 
                ABR_CACHE_SIZE-CACHE_HEADER_SIZE );
            if( audio_checksum_done )
            {
                ((cache_header_struct*)&cache[0])->audio_checksum = g_abrepeat.audio_checksum;
                ((cache_header_struct*)&cache[0])->audio_file_size = g_abrepeat.audio_file_size;
            }
            aud_util_build_cache_stop();
            g_abrepeat.fwd_rew_units = (U32) (g_abrepeat.total_offset / MAX_FWD_REW_DIV_VAL);
            g_mmi_abrepeat_first_time_entry = TRUE;
            if( fd_idx >= 0 )
            {
                FS_Seek( fd_idx, 0, FS_FILE_BEGIN );
                fs_result = FS_Write( fd_idx, (void *)&cache[0], ABR_CACHE_SIZE, &write_size );
                FS_Close( fd_idx );
                
                fd_idx = -1;
            }
            mmi_abrepeat_entry_main();  /* call main setting screen */
            DeleteScreenIfPresent( SCR_ID_AB_BUILD_CACHE );
            /*when fs error popup*/
            if(fs_result != FS_NO_ERROR)
            {
                DisplayPopup(
                    (U8*) GetString(GetFileSystemErrorString(fs_result)),
                    IMG_GLOBAL_WARNING,
                    0,
                    1000,
                    (U8) WARNING_TONE);
            }
        }
        else 
        {
            gui_start_timer(20, mmi_abrepeat_build_cache_process);
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(mmi_abrepeat_err_str((S32) MDI_AUDIO_ERROR)),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
        DeleteScreenIfPresent( SCR_ID_AB_BUILD_CACHE );
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_entry_build_cache
* DESCRIPTION
*  enter the screen of build cache
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_entry_build_cache(void)
{
    EntryNewScreen(SCR_ID_AB_BUILD_CACHE, 
        mmi_abrepeat_exit_build_cache, 
        mmi_abrepeat_entry_build_cache, 
        NULL);
    
    TurnOnBacklight(0);     /* prevent backlight being turned off */
    mdi_audio_suspend_background_play();
    
    ShowCategory402Screen( 
        (U8*)GetString(STR_ID_ABREPEAT_BUILDING_CACHE), /* title string */
        GetRootTitleIcon(MENU_ID_AB_REPEATER_MAIN), /* title icon */
        (build_cache_progress == 100) ? STR_GLOBAL_DONE: 0, 0, /* LSK */
        (build_cache_progress == 100) ? STR_GLOBAL_BACK: STR_GLOBAL_CANCEL, 0, /* RSK */
        (U8*) g_abrepeat.title,
        build_cache_progress,
        NULL);
    
    /* register LSK & RSK UP handlers */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_ID_AB_BUILD_CACHE, 
        (HistoryDelCBPtr) mmi_abrepeat_exit_build_cache_root);
    
    gui_start_timer(20, mmi_abrepeat_build_cache_process);
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_exit_build_cache
* DESCRIPTION
*  exit the screen of build cache
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_exit_build_cache(void)
{
    gui_cancel_timer(mmi_abrepeat_build_cache_process);

    TurnOffBacklight();
    mdi_audio_resume_background_play();
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_exit_build_cache_root
* DESCRIPTION
*  exit the root of build_cache screen
* PARAMETERS
*  param_p     [IN]
* RETURNS
*  U8
*****************************************************************************/
U8 mmi_abrepeat_exit_build_cache_root(void *param_p)
{    
    aud_util_build_cache_stop();
    if( fd_idx >= 0 )
    {
        FS_Close( fd_idx );
    }

    mmi_abrepeat_free_asm_resource();
    
    return FALSE;
}
#endif /* __MTK_TARGET__ */

/*****************************************************************************
* FUNCTION
*  InitABRepeaterApp
* DESCRIPTION
*  Initialization function of AB Repeater Application
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void InitABRepeaterApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_AB_REPEATER_MAIN, HighlightABRepeater);
    SetHiliteHandler(MENU_ID_AB_REPEAT_ENTER, mmi_abrepeat_enter_highlight_hdlr);
    SetHiliteHandler(MENU_ID_AB_REPEAT_STORAGE, mmi_abrepeat_storage_highlight_hdlr);
    mmi_abrepeat_read_settings();

#ifdef __MTK_TARGET__
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_AB_REPEATER,
        STR_ID_ABREPEAT_TITLE, 
        0, 
        mmi_abrepeat_app_asm_stop_cb);
#endif 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_storage_highlight_hdlr
* DESCRIPTION
*  Highlight Handler for storage menu item
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_storage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(mmi_abrepeat_enter_storage_media, KEY_EVENT_UP);
    
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
    /* 5 Register function for right  key */
    SetKeyHandler(mmi_abrepeat_enter_storage_media, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
    /* manish adding this line */
    g_mmi_abrepeat_interrupt_exit = FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeatget_drive_callback
* DESCRIPTION
*  get drive callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_abrepeat_get_drive_callback(S8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    history currHistory;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!drv_letter)
        return;
    
    DeleteNScrId(SCR_FMGR_EXPLORER);
    
    currHistory.scrnID = SCR_ID_AB_LIST;//SCR_FMGR_EXPLORER;
    currHistory.entryFuncPtr = mmi_abrepeat_entry_list;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
    AddHistory(currHistory);

    g_mmi_abrepeat_setting_storage = (U8)drv_letter;
    
    WriteValue(NVRAM_ABREPEAT_STORAGE, &g_mmi_abrepeat_setting_storage, DS_BYTE, &error);
    //DisplayPopupCallBack((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 2000, (U8) SUCCESS_TONE, mmi_abrepeat_entry_list);
    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        0,
        1000,
        (U8)SUCCESS_TONE);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_enter_storage_media
* DESCRIPTION
*  Category 57 inline edit screen for selecting the storage type either card or phone
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_enter_storage_media(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_ABREPEAT_STORAGE_SETTINGS, NULL, NULL, NULL);
    mmi_fmgr_sel_drv_and_enter(APP_ABREPEATER, mmi_abrepeat_get_drive_callback, g_mmi_abrepeat_setting_storage);
    
}


/*****************************************************************************
* FUNCTION
*  HighlightABRepeater
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightABRepeater(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    
    SetLeftSoftkeyFunction(mmi_abrepeat_entry_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_abrepeat_entry_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_entry_list
* DESCRIPTION
*  ENtry function to intialize the file manager filter and call back handlers
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id;
    FMGR_FILTER filter;
    S16 error;
    kal_wchar root_dir[25];
    U16 count = 0;
	U8 optional_drv_number = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    /* check is in mass storage mode */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    
    /* EntryNewScreen( SCR_ID_AB_LIST, 0, NULL, NULL ); */
    
    mmi_abrepeat_get_fs_info(); /* get the storage path according to drive */
    
    title_id = STR_ID_ABREPEAT_TITLE;
    
    if (!mmi_fmgr_is_drive_letter_valid(g_mmi_abrepeat_setting_storage))
    {
        g_mmi_abrepeat_setting_storage = (U8)MMI_PUBLIC_DRV;
        WriteValue(NVRAM_ABREPEAT_STORAGE, &g_mmi_abrepeat_setting_storage, DS_BYTE, &error);
    }
    
    kal_wsprintf(root_dir, "%c:\\", (S8) g_mmi_abrepeat_setting_storage);
    mmi_ucs2cat((S8*)root_dir, (const S8*)(L"Audio\\"));
    FMGR_FILTER_INIT(&filter);  /* set the filters */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AMR);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_DAF);
#ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /*__DRM_V02__*/

    optional_drv_number = mmi_abrepeat_util_count_optional_drv();
    if (optional_drv_number == 0)
	{
		DisplayPopup(
			(PU8)GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
		return;
	}
	else if (optional_drv_number < 2)
	{
		/* only one optional driver, no choice. */
        mmi_fmgr_kernel_init((PS8)root_dir, filter, &count);
        
		if (!count)
		{
			DisplayPopup(
				(PU8)GetString(STR_GLOBAL_EMPTY),
				IMG_GLOBAL_WARNING,
				1,
				UI_POPUP_NOTIFYDURATION_TIME,
				WARNING_TONE);
			return;
		}
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_AB_REPEAT_STORAGE);
        }
	}
	
    mmi_fmgr_select_path_and_enter(
        APP_ABREPEATER,
        FMGR_SELECT_BROWSE,
        filter,
        (PS8)root_dir,
        mmi_abrepeat_filename_callback);
    
    
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_filename_callback
* DESCRIPTION
*  Callback function from file manaegr
* PARAMETERS
*  fullname        [?]         (Full path name of the file )
*  is_short        [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_filename_callback(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_abrepeat.is_short_name = FALSE;
    if (fullname == NULL)
    {
        GoBackHistory();
    }
    else
    {
        mmi_ucs2cpy((S8*) g_abrepeat.filefullname, (S8*) fullname);
        if(is_short)
        {
            g_abrepeat.is_short_name = TRUE;
        }   
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_entry_main
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AB_MAIN, mmi_abrepeat_exit_main, NULL, MMI_FULL_SCREEN);
    entry_full_screen();

    if(!g_mmi_abrepeat_has_suspend_bg_play)
    {
        mdi_audio_suspend_background_play();
        g_mmi_abrepeat_has_suspend_bg_play = TRUE;
    }
    
    g_abrepeat.is_main_sel_btn_down = FALSE;
    g_abrepeat.is_absection_sel_btn_down = FALSE;
    
    /* manish here */
    if (g_mmi_abrepeat_Callback == PLAY_STOPPED)
    {
        g_mmi_abrepeat_first_time_entry = TRUE;
        g_abrepeat.state = AB_STATE_IDLE;
    }
    
    mmi_abrepeat_redraw_setting_play_screen();
    SetDelScrnIDCallbackHandler(SCR_ID_AB_MAIN, (HistoryDelCBPtr) mmi_abrepeat_delete_history_hdlr);
    if (g_mmi_abrepeat_Callback == PLAY_COMPLETED)
    {
        g_mmi_abrepeat_Callback = NOTHING;
        mmi_abrepeat_play_completed();  /* return back to func on interrupt ending */
    }
    else if (g_mmi_abrepeat_Callback == PLAY_STOPPED)
    {
        g_mmi_abrepeat_Callback = NOTHING;
    }
    
    
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(mmi_abrepeat_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_abrepeat_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_abrepeat_pen_move_hdlr);
    mmi_pen_register_long_tap_handler(mmi_abrepeat_pen_long_tap_hdlr);
    mmi_pen_register_abort_handler(mmi_abrepeat_pen_up_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_delete_history_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  in_param        [?]     
* RETURNS
*  U8
*****************************************************************************/
U8 mmi_abrepeat_delete_history_hdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_abrepeat_do_stop_action();                  /* stop audio */
    StopTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER);    /* stop the progrss bar redraw timer too */
    
    mdi_audio_resume_background_play();
    g_mmi_abrepeat_has_suspend_bg_play = FALSE;
    
    return FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_setting_play_screen
* DESCRIPTION
*  Redraws Play and Setting Screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_setting_play_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    ab_data_struct abrepeat_ab_data;
    U8 i;
    U16 key_index;
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_abrepeat_first_time_entry)
    {
        g_mmi_abrepeat_start_progress = FALSE;
        g_mmi_abrepeat_end_progress = FALSE;
        
        g_abrepeat.curr_play_section = -1;
        g_abrepeat.prgbar_cur_offset = 0;
        if (g_abrepeat.cur_mode == AB_SETTING_MODE)
        {
            g_abrepeat.replay_btn_state = AB_REPLAY_DISABLE;
        }
        else /*play mode*/
        {
            if (g_abrepeat.is_replay_on)
            {
                g_abrepeat.replay_btn_state = AB_REPLAY_ALWAYS;
            }
            else
            {
                g_abrepeat.replay_btn_state = AB_REPLAY_ONCE;
            }      
        }
        
#ifdef SIMULATOR_TESTING
        inscreen_first_time = TRUE;
        offset = 0;
#endif /* SIMULATOR_TESTING */ 
        memset(g_mmi_abrepeat_draw_refer_state, AB_SECTION_DISABLED, MAX_AB_POINT);
    }
    
    switch (g_abrepeat.state)
    {
    case AB_STATE_IDLE:
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_STOP;
        break;
    case AB_STATE_PLAY:
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PLAY;
        break;
    case AB_STATE_PAUSED:
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PAUSE;
        break;
    }
    
    if (g_mmi_abrepeat_first_time_entry)
    {
        memset(g_mmi_abrepeat_record_exist, FALSE, MAX_AB_POINT);
        /* CHECK IF ENTRY ALREADY EXISTS IN DATA MANAGER */
        for (i = 0; i < MAX_AB_POINT; i++)
        {
            result = mmi_data_get_record(&g_abrepeat_ab_record_store, i, &abrepeat_ab_data);
            if (result == 0 && mmi_abrepeat_is_record_valid(&abrepeat_ab_data))
            {
                key_index = abrepeat_ab_data.keyindex;
                if (g_mmi_abrepeat_record_exist[key_index])
                {
                    mmi_data_delete_record(&g_abrepeat_ab_record_store, i);     /* clean duplicated records */
                }
                else
                {
                    if (AB_SETTING_MODE == g_abrepeat.cur_mode)
                    {
                        g_mmi_abrepeat_draw_refer_state[key_index] = AB_SECTION_COMPLETE_SET;
                    }
                    else
                    {
                        g_mmi_abrepeat_draw_refer_state[key_index] = AB_SECTION_NON_PLAYING;
                    }
                    g_mmi_abrepeat_abplay_data[key_index].abstart = abrepeat_ab_data.abstart;
                    g_mmi_abrepeat_abplay_data[key_index].abend = abrepeat_ab_data.abend;
                    g_mmi_abrepeat_record_exist[key_index] = TRUE;
                }
            }
        }
    }
    mmi_abrepeat_show_mainscreen(STR_ID_ABREPEAT_TITLE, STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, g_abrepeat.skin);
    
    if (g_mmi_abrepeat_first_time_entry)
    {
        g_abrepeat.abkey_state = AB_SET_IDLE;
        g_abrepeat.curr_set_section  = -1;
    }
    
    g_mmi_abrepeat_first_time_entry = FALSE;
    
    if (AB_SETTING_MODE == g_abrepeat.cur_mode)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        mmi_abrepeat_setting_set_key_handlers();
    }
    else
    {
        /* Draw the once/always button grey */
        ClearInputEventHandler(MMI_DEVICE_KEY);
        mmi_abrepeat_play_set_key_handlers();
    }
    mmi_abrepeat_set_mainplay_section_key_handler();
    SetKeyHandler(mmi_abrepeat_entry_option, KEY_LSK, KEY_EVENT_UP);
    
    /* manish adding here because clearallkeyhandler() has been done */
    SetKeyHandler(mmi_abrepeat_mainscr_LSK_down_hldr, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_abrepeat_mainscr_RSK_down_hldr, KEY_RSK, KEY_EVENT_DOWN);
    
    // manish chaning here to convert SetRightSoftkeyFunction into SetKeyHandler*/
    /* MTK has also done so manish not merging */
    SetKeyHandler(mmi_abrepeat_rsk_action, KEY_RSK, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_rsk_action
* DESCRIPTION
*  RSK Action of the AB Repeater main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_rsk_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_abrepeat_Back_Stop = TRUE;
    
    mmi_abrepeat_do_stop_action();  /* stop audio */
    if(IsScreenPresent(SCR_FMGR_EXPLORER))
    {
        GoBackToHistory(SCR_FMGR_EXPLORER);
    }
    else
    {
        GoBackHistory();
    } 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_entry_option
* DESCRIPTION
*  LSK Option Action of the AB Repeater main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 option_items;
    U16 option_icons[4];
    U8 *tempBuffer;
    U16 option_buffer[4];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* manish adding this for stopin audio when entering into option screen */
    g_mmi_abrepeat_Option_lsk_stop = TRUE;
    mmi_abrepeat_do_stop_action();
    
    //manish adding following lines so that after interrupt control back on option screen
    EntryNewScreen(SCR_ID_ABREPEAT_OPTION, 0, mmi_abrepeat_entry_option, NULL);
    
    /* gui buffer */
    tempBuffer = GetCurrGuiBuffer(SCR_ID_ABREPEAT_OPTION);
    
    option_buffer[0] = STR_ID_ABREPEAT_SWITCH;
    option_icons[0] = IMG_GLOBAL_L1;    /* ask for new icon */
    
    option_items = 1;
    
    /* register highligh handler */
    RegisterHighlightHandler(mmi_abrepeat_option_highlight_hdlr);
    /* show category screen */
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_AB_REPEATER_MAIN),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        option_items,
        option_buffer,
        option_icons,
        LIST_MENU,
        0,
        tempBuffer);
    
    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_abrepeat_option_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_abrepeat_option_back, KEY_EVENT_UP);
    
    // register left, right key handlers
    SetKeyHandler(mmi_abrepeat_option_back, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_option_highlight_hdlr
* DESCRIPTION
*  Sets the highlight index for the option menu items in Options of AB Repeater
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_abrepeat_option_highlighted_item = (U16) index;
    
    /* manish adding this for not draw in case of going to switching screen */
    g_mmi_abrepeat_Option_lsk_stop = FALSE;
}

/* manish adding this function */


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_option_back
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_option_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_abrepeat_first_time_entry = TRUE;
    g_abrepeat.state = AB_STATE_IDLE;
    GoBackToHistory(SCR_ID_AB_MAIN);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_option_lsk
* DESCRIPTION
*  Handler of lsk press of Option screen of AB repeater
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_option_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_abrepeat_option_highlighted_item)
    {
    case 0:
        {
            if (AB_SETTING_MODE == g_abrepeat.cur_mode)
            {
                g_abrepeat.cur_mode = AB_PLAY_MODE;
            }
            else
            {
                g_abrepeat.cur_mode = AB_SETTING_MODE;
            }
            /* enter to main screen again for switching in between play and setting screen */
            g_mmi_abrepeat_first_time_entry = TRUE;
            g_abrepeat.state = AB_STATE_IDLE;
            mdi_audio_stop_file();  /* stop the playing audio */
            GoBackToHistory(SCR_ID_AB_MAIN);
            
            break;
        }
    default:
        break;
        
    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_exit_main
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_exit_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_abrepeat_exit_mainscreen();
    currHistory.scrnID = SCR_ID_AB_MAIN;
    currHistory.entryFuncPtr = mmi_abrepeat_entry_main;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
    AddHistory(currHistory);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_set_key_handlers
* DESCRIPTION
*  Sets the key handlers of the setting screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_set_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ABSettingScreenDigits[MAX_AB_SETTING_SCREEN_DIGITS] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6,
        KEY_7, KEY_8, KEY_9, KEY_POUND
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetGroupKeyHandler(
        mmi_abrepeat_setting_press_digit_up,
        ABSettingScreenDigits,
        MAX_AB_SETTING_SCREEN_DIGITS - 2,
        KEY_EVENT_UP);
    SetGroupKeyHandler(
        mmi_abrepeat_setting_press_digit_down,
        ABSettingScreenDigits,
        MAX_AB_SETTING_SCREEN_DIGITS - 2,
        KEY_EVENT_DOWN);
    SetGroupKeyHandler(
        mmi_abrepeat_setting_long_press_digit,
        ABSettingScreenDigits,
        MAX_AB_SETTING_SCREEN_DIGITS - 2,
        KEY_EVENT_LONG_PRESS);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_press_digit_down
* DESCRIPTION
*  Entry Function when Setting Screen Keys are Pressed down
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_press_digit_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mmi_abrepeat_setting_press_digit_down_hdlr(Keycode);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_press_digit_up
* DESCRIPTION
*  Entry Function when Setting Screen Keys are Released
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_press_digit_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mmi_abrepeat_setting_press_digit_up_hdlr(Keycode);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_press_digit_down_hdlr
* DESCRIPTION
*  Handles when Setting Screen Keys are Pressed
* PARAMETERS
*  keycode     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_press_digit_down_hdlr(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keycode != KEY_POUND)   /* screen switching */
    {
        g_abrepeat.is_absection_sel_btn_down = TRUE;
        mmi_abrepeat_redraw_absection_buttons(keycode);
    }
    else
    {
        mmi_abrepeat_redraw_mode_switch_button(TRUE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_press_digit_up_hdlr
* DESCRIPTION
*  Handles when Setting Screen Keys are Released
* PARAMETERS
*  keycode     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_press_digit_up_hdlr(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ab_data_struct abrepeat_ab_data;
    
    U8 i;
    S32 result;
    S32 aud_result = 0;
    BOOL entryexists = FALSE;
    static U16 lastkeycode;
    U32 abs_end_offset;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* after deletion don't enter the normal setting operation ..Return from here.. */
    if (g_mmi_abrepeat_section_deleted == TRUE)
    {
        g_abrepeat.is_absection_sel_btn_down = FALSE;
        mmi_abrepeat_redraw_absection_buttons(keycode);
        
        g_mmi_abrepeat_section_deleted = FALSE;
        return;
    }
    g_abrepeat.is_absection_sel_btn_down = FALSE;
    
    if (keycode == KEY_POUND)
    {
        g_abrepeat.cur_mode = AB_PLAY_MODE;
        mmi_abrepeat_do_stop_action();  /* stop the playing audio */
        /* enter to main screen again for switching in between play and setting screen */
        g_mmi_abrepeat_first_time_entry = TRUE;
        /* mmi_abrepeat_entry_main(); */
        mmi_abrepeat_exit_mainscreen();
        mmi_abrepeat_redraw_setting_play_screen();
        return;
    }
    /* If audio file is not playing don't try to set the AB section start or end.. */
    if (g_abrepeat.state != AB_STATE_PLAY)
    {
        mmi_abrepeat_redraw_absection_buttons(keycode);
        return;
    }
    /* CHECK IF ENTRY ALREADY EXISTS IN DATA MANAGER */
    for (i = 0; i < MAX_AB_POINT; i++)
    {
        result = mmi_data_get_record(&g_abrepeat_ab_record_store, i, &abrepeat_ab_data);
        if (result == 0 && mmi_abrepeat_is_record_valid(&abrepeat_ab_data))
        {
            if (abrepeat_ab_data.keyindex == keycode)
            {
                entryexists = TRUE;
                break;
            }
        }
    }
    result = 0;
    /* If key is pressed first time and other key is not pressed single time earlier */
    if ((g_abrepeat.abkey_state == AB_SET_IDLE) && (g_abrepeat.curr_set_section  == -1))
    {
        if (!entryexists)
        {
            /* SAVE FIRST AB POINT IN TEMP variable */
#ifdef SIMULATOR_TESTING
            /* g_abrepeat.cur_setab_start_offset  = mmi_abrepeat_dummy_get_curr_offset(); */
#endif 
            aud_result = mdi_audio_get_progress_time(&g_abrepeat.cur_setab_start_offset );
            if (aud_result == 0)
            {
                g_abrepeat.abkey_state = AB_SET_PARTIAL;
                g_abrepeat.curr_set_section  = keycode;
                g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_FIRST_SET;
                g_mmi_abrepeat_start_progress = TRUE;
            }
        }
        else
        {
            g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_COMPLETE_SET;
        }
    }
    /* If same key is pressed second time */
    else if ((g_abrepeat.abkey_state == AB_SET_PARTIAL) && (g_abrepeat.curr_set_section  == keycode))
    {
        
#ifdef SIMULATOR_TESTING
        /* abs_end_offset = mmi_abrepeat_dummy_get_curr_offset(); */
#endif 
        
        /* Call the lower layer api to get the offset (start ab point) */
        aud_result = mdi_audio_get_progress_time(&abs_end_offset);
        if ((aud_result == 0) && (abs_end_offset > g_abrepeat.cur_setab_start_offset ))
        {
            for (i = 0; i < MAX_AB_POINT; i++)
            {
                result = mmi_data_get_record(&g_abrepeat_ab_record_store, i, &abrepeat_ab_data);
                if (result != 0 || !mmi_abrepeat_is_record_valid(&abrepeat_ab_data))
                {
                    break;
                }
            }
            /* SAVE SET OF AB POINT IN DATA MANAGER */
            abrepeat_ab_data.abstart = g_abrepeat.cur_setab_start_offset ;
            abrepeat_ab_data.abend = abs_end_offset;
            abrepeat_ab_data.keyindex = keycode;
            
            result = mmi_data_set_record(&g_abrepeat_ab_record_store, i, &abrepeat_ab_data, TRUE);
            
            if (result == 0)    /* Success */
            {
                g_abrepeat.abkey_state = AB_SET_IDLE;
                g_abrepeat.curr_set_section  = -1;
                g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_COMPLETE_SET;
                g_mmi_abrepeat_end_progress = TRUE;
                g_mmi_abrepeat_start_progress = FALSE;
            }
        }
    }
    /* If a key is pressed one time earlier but now other key is pressed first time */
    else    /* if ((g_abrepeat.curr_set_section  != keycode) && (abrepeat.abkey_state == AB_SET_PARTIAL) ) */
    {
        if (!entryexists)   /* only if pressed key doesn't have entry otherwise no treatment */
        {
            /* Call the lower layer api to get the offset (start ab point) */
            aud_result = mdi_audio_get_progress_time(&g_abrepeat.cur_setab_start_offset );
            if (aud_result == 0)
            {
                g_abrepeat.abkey_state = AB_SET_PARTIAL;
                g_abrepeat.curr_set_section = keycode;
                g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_FIRST_SET;
                /* Change the state of the key as last recording AB Section */
                g_mmi_abrepeat_draw_refer_state[lastkeycode] = AB_SECTION_DISABLED;
                mmi_abrepeat_redraw_absection_buttons(lastkeycode);
            }
        }
        else
        {
            g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_COMPLETE_SET;
            mmi_abrepeat_redraw_absection_buttons(keycode);
            return; /* return from here as no need to store the lastkeycode this time */
        }
    }
    lastkeycode = keycode;  /* for disabling the last absection in case its not completely set */
    mmi_abrepeat_redraw_absection_buttons(keycode);
    if (aud_result != 0 && aud_result != MDI_AUDIO_FAIL)
    {
        DisplayPopup((PU8) GetString(mmi_abrepeat_err_str(aud_result)), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
    }
    else if(result < 0) /*file system error code*/
    {
        DisplayPopup(
            (U8*) GetString(GetFileSystemErrorString(result)),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);

        if (g_abrepeat.state != AB_STATE_IDLE)
        {
            mmi_abrepeat_do_stop_action();  /* stop audio */
        }
    }
    else if (result > 0)/*data manager return error code*/
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_long_press_digit
* DESCRIPTION
*  Entry Function when AB section key is long prssed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_long_press_digit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mmi_abrepeat_setting_long_press_digit_hdlr(Keycode);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_long_press_digit_hdlr
* DESCRIPTION
*  Handler and operation function  when AB section key is long prssed
* PARAMETERS
*  keycode     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_long_press_digit_hdlr(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, delresult;
    ab_data_struct abrepeat_ab_data;
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_abrepeat.is_absection_sel_btn_down = FALSE;
    if (keycode != KEY_POUND)
    {
        for (i = 0; i < MAX_AB_POINT; i++)
        {
            result = mmi_data_get_record(&g_abrepeat_ab_record_store, i, &abrepeat_ab_data);
            if (result == 0 && mmi_abrepeat_is_record_valid(&abrepeat_ab_data))
            {
                if (abrepeat_ab_data.keyindex == keycode)
                {
                    /* Delete that keycode record from the data manager */
                    delresult = mmi_data_delete_record(&g_abrepeat_ab_record_store, i);
                    if (delresult == 0)
                    {
                        g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_DISABLED;
                        g_mmi_abrepeat_record_exist[keycode] = FALSE;
                        mmi_abrepeat_redraw_absection_buttons(keycode);
                        break;
                        /* Draw Disabled the AB button */
                    }
                }
            }
        }
        
        g_mmi_abrepeat_section_deleted = TRUE;
        
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_play_set_key_handlers
* DESCRIPTION
*  Key handler setting function for Play Screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_play_set_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ABPlayScreenDigits[MAX_AB_SETTING_SCREEN_DIGITS] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6,
        KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetGroupKeyHandler(
        mmi_abrepeat_play_press_digit_up,
        ABPlayScreenDigits,
        MAX_AB_SETTING_SCREEN_DIGITS - 1,
        KEY_EVENT_UP);
    SetGroupKeyHandler(
        mmi_abrepeat_play_press_digit_down,
        ABPlayScreenDigits,
        MAX_AB_SETTING_SCREEN_DIGITS - 1,
        KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_play_press_digit_up
* DESCRIPTION
*  Entry Function for Key up event
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_play_press_digit_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mmi_abrepeat_play_press_digit_up_hdlr(Keycode);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_play_press_digit_down
* DESCRIPTION
*  Entry Function for Key down event
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_play_press_digit_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mmi_abrepeat_play_press_digit_down_hdlr(Keycode);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_play_press_digit_down_hdlr
* DESCRIPTION
*  Handler of key Pressed  on Play Screen
* PARAMETERS
*  keycode     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_play_press_digit_down_hdlr(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keycode != KEY_POUND)
    {
        if (keycode != KEY_STAR)
        {
            g_abrepeat.is_absection_sel_btn_down = TRUE;
            mmi_abrepeat_redraw_absection_buttons(keycode);
            if (g_mmi_abrepeat_record_exist[keycode] == TRUE)
            {
                mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PLAY, TRUE);
            }            
        }
        else
        {
            mmi_abrepeat_redraw_once_always_button(TRUE);
        }
    }
    else
    {
        mmi_abrepeat_redraw_mode_switch_button(TRUE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_play_press_digit_up_hdlr
* DESCRIPTION
*  Handler of key Release  on Play Screen
* PARAMETERS
*  keycode     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_play_press_digit_up_hdlr(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_abrepeat.is_absection_sel_btn_down = FALSE;
    g_abrepeat.is_main_sel_btn_down = FALSE;
    
    ASSERT(g_abrepeat.replay_btn_state != AB_REPLAY_DISABLE);
    if (keycode == KEY_STAR)
    {
        if (g_abrepeat.replay_btn_state == AB_REPLAY_ONCE)
        {
            g_abrepeat.replay_btn_state = AB_REPLAY_ALWAYS;
            g_abrepeat.is_replay_on = TRUE;
        }
        else
        {
            g_abrepeat.replay_btn_state = AB_REPLAY_ONCE;
            g_abrepeat.is_replay_on = FALSE;
        }
        
        mmi_abrepeat_redraw_once_always_button(FALSE);
        /* May be to put the code here to repeat on/off the playing audio */
        return;
    }
    if (keycode == KEY_POUND)
    {
        g_abrepeat.cur_mode = AB_SETTING_MODE;
        g_mmi_abrepeat_first_time_entry = TRUE;
        mmi_abrepeat_do_stop_action();  /* stop the playing audio */
        /* enter to main screen again for switching in between play and setting screen */
        /* mmi_abrepeat_entry_main(); */
        mmi_abrepeat_exit_mainscreen();
        mmi_abrepeat_redraw_setting_play_screen();
        return;
    }
    if (g_mmi_abrepeat_record_exist[keycode] == TRUE)
    {
    /* Pass the g_mmi_abrepeat_abplay_data start and end to lower layer api 
        and set the play command */
        if (g_abrepeat.curr_play_section >= 0)
        {
            g_mmi_abrepeat_draw_refer_state[g_abrepeat.curr_play_section] = AB_SECTION_NON_PLAYING;
            mmi_abrepeat_redraw_absection_buttons(g_abrepeat.curr_play_section);
        }
        
        //Check for the AB_STATE_IDLE , if it is idle then give the play command
        //after giving the play command check for the result if result == TRUE then update the
        //buttons 
        if (g_abrepeat.state != AB_STATE_IDLE)
        {
            mmi_abrepeat_do_stop_action();  /* stop audio */
        }
        if (g_abrepeat.state == AB_STATE_IDLE)
        {
            g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PLAY;
            mmi_abrepeat_redraw_main_buttons();
            g_abrepeat.curr_play_section = keycode;
            g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_PLAYING;
            mmi_abrepeat_redraw_absection_buttons(keycode);
            mmi_abrepeat_do_play_action();
        }
    }
    else    /* record does not exist */
    {
        g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_DISABLED;
        mmi_abrepeat_redraw_absection_buttons(keycode);
    }
    /* Put the code for playing AB Points as well as display part */
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_set_mainplay_section_key_handler
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_set_mainplay_section_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const abrepeat_skin_struct *skinab_p;
    
    FuncPtr ab_button_press_hdlr[] = 
    {
        mmi_abrepeat_press_play_button_down,    /* ABREPEAT_MAIN_PLAY */
            mmi_abrepeat_press_rewind_button_down,  /* ABREPEAT_MAIN_PREV */
            mmi_abrepeat_press_forward_button_down, /* ABREPEAT_MAIN_NEXT */
            mmi_abrepeat_press_stop_button_down     /* ABREPEAT_MAIN_STOP */
    };
    FuncPtr ab_button_release_hdlr[] = 
    {
        mmi_abrepeat_press_play_button_up,      /* ABREPEAT_MAIN_PLAY */
            mmi_abrepeat_press_rewind_button_up,    /* ABREPEAT_MAIN_PREV */
            mmi_abrepeat_press_forward_button_up,   /* ABREPEAT_MAIN_NEXT */
            mmi_abrepeat_press_stop_button_up       /* ABREPEAT_MAIN_STOP */
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register play / pause, stop, prev, next button handlers */
    skinab_p = &g_abrepeat_skins[g_abrepeat.skin];
    
    SetKeyHandler(ab_button_release_hdlr[skinab_p->left_ab_key_mapping], KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(ab_button_release_hdlr[skinab_p->right_ab_key_mapping], KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(ab_button_release_hdlr[skinab_p->up_ab_key_mapping], KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(ab_button_release_hdlr[skinab_p->down_ab_key_mapping], KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(ab_button_press_hdlr[skinab_p->left_ab_key_mapping], KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ab_button_press_hdlr[skinab_p->right_ab_key_mapping], KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ab_button_press_hdlr[skinab_p->up_ab_key_mapping], KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ab_button_press_hdlr[skinab_p->down_ab_key_mapping], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    
    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_abrepeat_press_inc_volume, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_abrepeat_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(mmi_abrepeat_press_inc_volume_down, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_abrepeat_press_dec_volume_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);

}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_stop_button_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_stop_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.main_selected_button == ABREPEAT_MAIN_DISABLED)
    {
        return;
    }
    
    /* change selected button & update state */
    g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_STOP;
    g_abrepeat.is_main_sel_btn_down = TRUE;
    
    mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_stop_button_up
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_stop_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.is_main_sel_btn_down && (g_abrepeat.main_selected_button == ABREPEAT_MAIN_STOP))
    {
        /* update selected button state */
        g_abrepeat.is_main_sel_btn_down = FALSE;
        
        if (g_abrepeat.state != AB_STATE_IDLE)
        {
            mmi_abrepeat_do_stop_action();  /* stop audio */
        }
        
        mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_play_button_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_play_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.main_selected_button == ABREPEAT_MAIN_DISABLED)
    {
        return;
    }
    
    /* update selected button state */
    g_abrepeat.is_main_sel_btn_down = TRUE;
    
    if (g_abrepeat.state == AB_STATE_PLAY)
    {
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PAUSE;     /* change selected button */
    }
    else if (g_abrepeat.state == AB_STATE_PAUSED)
    {
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PLAY;      /* change selected button */
    }
    else    /* g_abrepeat.state == AB_STATE_IDLE */
    {
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PLAY;      /* change selected button */
    }
    
    // update button display
    mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_play_button_up
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_play_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.is_main_sel_btn_down && ((g_abrepeat.main_selected_button == ABREPEAT_MAIN_PLAY) ||
        (g_abrepeat.main_selected_button == ABREPEAT_MAIN_PAUSE)))
    {
        /* update selected button state */
        g_abrepeat.is_main_sel_btn_down = FALSE;
        
        if (g_abrepeat.state == AB_STATE_PLAY)
        {
            mmi_abrepeat_do_pause_action(); /* do pause action */
        }
        else if (g_abrepeat.state == AB_STATE_PAUSED)
        {
            mmi_abrepeat_do_resume_action();    /* do resume action */
        }
        else    /* g_abrepeat.state == AB_STATE_IDLE */
        {
            mmi_abrepeat_do_play_action();  /* do play action */
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_rewind_button_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_rewind_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.main_selected_button == ABREPEAT_MAIN_DISABLED)
    {
        return;
    }
    
    /* change selected button & update state */
    g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_REWIND;
    g_abrepeat.is_main_sel_btn_down = TRUE;
    
    // update button display
    mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_rewind_button_up
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_rewind_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 aud_result = MDI_AUDIO_SUCCESS;
    S32 current_playing_offset; /* call the expected api to get the current offset */
    MMI_BOOL is_redraw_prgbar = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.is_main_sel_btn_down && (g_abrepeat.main_selected_button == ABREPEAT_MAIN_REWIND))
    {
        /* update selected button state */
        g_abrepeat.is_main_sel_btn_down = FALSE;
        if ((g_abrepeat.state == AB_STATE_PLAY) && (g_abrepeat.state != AB_STATE_PAUSED))
        {
            //when do rewind check the start of file  and in case of AB section play
            //check the start  of the AB section 
            aud_result = mdi_audio_get_progress_time((U32*) & current_playing_offset);
            if (aud_result == MDI_AUDIO_SUCCESS)
            {
                if(current_playing_offset > (S32)g_abrepeat.total_offset)
                {
                    current_playing_offset = g_abrepeat.total_offset ;
                }
                
                current_playing_offset -= g_abrepeat.fwd_rew_units;   /* imcrease the rewind units */
                if (current_playing_offset < 0)
                {
                    current_playing_offset = 1;
                }
                if (current_playing_offset >= 0)
                {   
                    if (g_abrepeat.curr_play_section >= 0)
                    {
                        if (current_playing_offset >=
                            (S32) g_mmi_abrepeat_abplay_data[g_abrepeat.curr_play_section].abstart)
                        {
                            aud_result = mdi_audio_set_progress_time((U32) current_playing_offset);
                            is_redraw_prgbar = MMI_TRUE;
                        }
                    }
                    else
                    {
                        if (g_mmi_abrepeat_start_progress)
                        {
                            if (current_playing_offset >= (S32) g_abrepeat.cur_setab_start_offset )
                            {
                                aud_result = mdi_audio_set_progress_time((U32) current_playing_offset);
                                is_redraw_prgbar = MMI_TRUE;
                            }
                        }
                        else
                        {
                            aud_result = mdi_audio_set_progress_time((U32) current_playing_offset);
                            is_redraw_prgbar = MMI_TRUE;
                        }
                    }
                    if ((aud_result == MDI_AUDIO_SUCCESS) && is_redraw_prgbar)
                    {
                        g_abrepeat.prgbar_cur_offset = current_playing_offset;
                        mmi_abrepeat_redraw_progress_bar();
                    }
                }
            }
            
        }
        
        // update main buttons
        mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
        if(aud_result != MDI_AUDIO_SUCCESS)
        {
        	//mmi_abrepeat_do_stop_action();
        	//DisplayPopup((PU8) GetString(mmi_abrepeat_err_str(aud_result)), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_forward_button_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_forward_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.main_selected_button == ABREPEAT_MAIN_DISABLED)
    {
        return;
    }
    
    /* change selected button & update state */
    g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_FORWARD;
    g_abrepeat.is_main_sel_btn_down = TRUE;
    
    // update button display
    mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_forward_button_up
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_forward_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 aud_result = MDI_AUDIO_SUCCESS;
    U32 current_playing_offset; /* call the expected api to get the current offset */
    MMI_BOOL is_redraw_prgbar = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.is_main_sel_btn_down && (g_abrepeat.main_selected_button == ABREPEAT_MAIN_FORWARD))
    {
        /* update selected button state */
        g_abrepeat.is_main_sel_btn_down = FALSE;
        if ((g_abrepeat.state == AB_STATE_PLAY) && (g_abrepeat.state != AB_STATE_PAUSED))
        {
            //when do forwarding check the end of file (total offset ) and in case of AB section play
            //check the end of the AB section
            aud_result = mdi_audio_get_progress_time(&current_playing_offset);
            if (aud_result == MDI_AUDIO_SUCCESS)
            {
                current_playing_offset += g_abrepeat.fwd_rew_units;
                if (current_playing_offset < g_abrepeat.total_offset)
                {                    
                    if (g_abrepeat.curr_play_section >= 0)
                    {
                        if (current_playing_offset <
                            g_mmi_abrepeat_abplay_data[g_abrepeat.curr_play_section].abend)
                        {
                            aud_result = mdi_audio_set_progress_time(current_playing_offset);
                            is_redraw_prgbar = MMI_TRUE;
                        }
                    }
                    else
                    {
                        aud_result = mdi_audio_set_progress_time(current_playing_offset);
                        is_redraw_prgbar = MMI_TRUE;
                    }
                    if ((aud_result == MDI_AUDIO_SUCCESS) && is_redraw_prgbar)
                    {
                        g_abrepeat.prgbar_cur_offset = current_playing_offset;
                        mmi_abrepeat_redraw_progress_bar();
                    }
                }
            }
            
        }
        // update main buttons
        mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
        if(aud_result != MDI_AUDIO_SUCCESS)
        {
        	//mmi_abrepeat_do_stop_action();
        	//DisplayPopup((PU8) GetString(mmi_abrepeat_err_str(aud_result)), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_inc_volume_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_inc_volume_down(void)
{
    mmi_abrepeat_redraw_volumectrl(TRUE, TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_dec_volume_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_dec_volume_down(void)
{
    mmi_abrepeat_redraw_volumectrl(FALSE, TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_inc_volume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.volume < MAX_VOL_LEVEL - 1)
    {
        S16 error;
        
        mdi_audio_set_volume(VOL_TYPE_MEDIA, ++g_abrepeat.volume);
        mmi_abrepeat_redraw_main_volumebar();
        WriteValue(NVRAM_ABREPEAT_VOLUME, &g_abrepeat.volume, DS_BYTE, &error);
    }
    
    mmi_abrepeat_redraw_volumectrl(TRUE, FALSE);
    
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_dec_volume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.volume > 0)
    {
        S16 error;
        
        mdi_audio_set_volume(VOL_TYPE_MEDIA, --g_abrepeat.volume);
        mmi_abrepeat_redraw_main_volumebar();
        WriteValue(NVRAM_ABREPEAT_VOLUME, &g_abrepeat.volume, DS_BYTE, &error);
    }
    
    mmi_abrepeat_redraw_volumectrl(FALSE, FALSE); 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_get_fs_info
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_get_fs_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[4];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get phone drive */
    if ((phoneDrvLetter_ab = MMI_PUBLIC_DRV) > 0)
    {
        sprintf(temp, "%c:\\", (S8) phoneDrvLetter_ab);
        mmi_asc_to_ucs2((S8*) root_dir_phone_ab, temp);
        mmi_ucs2cpy((S8*) phone_list_name_ab, (const S8*)root_dir_phone_ab);
        mmi_ucs2cat((S8*) phone_list_name_ab, (const S8*)(L"Audio"));
    }
    
    /* get card drive */
    if ((cardDrvLetter_ab = MMI_CARD_DRV) > 0)
    {
        sprintf(temp, "%c:\\", (S8) cardDrvLetter_ab);
        mmi_asc_to_ucs2((S8*) root_dir_card_ab, temp);
        mmi_ucs2cpy((S8*) card_list_name_ab, (const S8*)root_dir_card_ab);
        mmi_ucs2cat((S8*) card_list_name_ab, (const S8*)(L"Audio"));
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_timer
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_timer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.state == AB_STATE_PLAY)
    {
        /* call the progrss bar draw */
        if (GetActiveScreenId() == SCR_ID_AB_MAIN)
        {
            mdi_audio_get_progress_time(&g_abrepeat.prgbar_cur_offset);
            if (g_abrepeat.prgbar_cur_offset != 0)
            {
                mmi_abrepeat_redraw_progress_bar();
            }    
        }
        StartTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER, ABREPEAT_PROGRESS_BAR_DRAW_TIMER_DELAY, mmi_abrepeat_timer);
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_read_settings
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_read_settings(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_ABREPEAT_VOLUME, &g_abrepeat.volume, DS_BYTE, &error);
    ReadValue(NVRAM_ABREPEAT_STORAGE, &g_mmi_abrepeat_setting_storage, DS_BYTE, &error);
    if (g_abrepeat.volume == 0xFF || g_mmi_abrepeat_setting_storage == 0xFF)
    {
        g_abrepeat.volume = 4;                              /* default value first time if NVRAM is formatted */
        g_mmi_abrepeat_setting_storage = (U8)MMI_PUBLIC_DRV;  /* default storage */
        WriteValue(NVRAM_ABREPEAT_VOLUME, &g_abrepeat.volume, DS_BYTE, &error);
        WriteValue(NVRAM_ABREPEAT_STORAGE, &g_mmi_abrepeat_setting_storage, DS_BYTE, &error);
    }
#else /* __MTK_TARGET__ */ 
    g_abrepeat.volume = 4;
    g_abrepeat.skin = 0;
    g_mmi_abrepeat_setting_storage = (U8)MMI_PUBLIC_DRV;  /* default storage */
#endif /* __MTK_TARGET__ */ 
}

#if !defined(__MMI_SHOW_DAF_FILE_EXT__)  
/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_hide_ext_name
* DESCRIPTION
*  hide extension file name
* PARAMETERS
*  file_name       [?]     
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_hide_ext_name(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* find ext name - by finding "." */
    S32 str_len;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = mmi_ucs2strlen(file_name);
    index = (str_len - 1) * ENCODING_LENGTH;
    
    while (index > 0)
    {
        if (mmi_ucs2ncmp((PS8) & file_name[index], (PS8) L".", 1) == 0)
        {
            file_name[index] = '\0';
            file_name[index + 1] = '\0';
            break;
        }
        
        file_name[index] = '\0';
        file_name[index + 1] = '\0';
        index -= 2;
    }
}
#endif /*!defined(__MMI_SHOW_DAF_FILE_EXT__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_abrepeat_util_count_optional_drv
 * DESCRIPTION
 *  return optional driver number.
 *  check phone memory, memory card, SIM+ and OTG.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_abrepeat_util_count_optional_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drive; 
    U8 count = 0;
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        count++;
    }
    
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        count++;
    }

#ifdef __OTG_ENABLE__
    for (i = 0; i < 4; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_EXTERNAL, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            count++;
        }
    }
    
#endif /* __OTG_ENABLE__ */ 

#ifdef __SIM_PLUS__
    for (i = 0; i < 4; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_SIMPLUS, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            count++;
        }
    }
#endif

#ifdef __MSDC2_SD_MMC__
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        count++;
    }    
#endif

    return count;
}

#endif /* __MMI_AB_REPEATER__ */ 

