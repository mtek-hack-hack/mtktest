/*******************************************************************************
 * Filename:
 * ---------
 *   vid_avi.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes avi related functions of camera module.
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "FSAL.h"
#include "med_main.h"
#include "med_global.h"
#include "med_struct.h"
#include "med_utility.h"
#include "med_trc.h"
#include "vid_avi.h"
#include "vid_main.h"



/* player */
#define MED_AVI_VID_FSAL_BUF_SIZE       (10*1024)     /* 10k */
#define MED_AVI_AUD_FSAL_BUF_SIZE       (1024)        /* 1k */
#define MED_AVI_IDX_FSAL_BUF_SIZE       (1024)        /* 1k */

#define MED_AVI_IDX_BUF_SIZE            (1024)        /* 1k */

/* recorder */
#define MED_AVI_WRITE_DATA_BUF_SIZE     (100*1024)    /* 100k */
#define MED_AVI_WRITE_IDX_BUF_SIZE      (5*1024)      /* 5k */
#define MED_AVI_RECORD_TIME_LIMIT       (60)          /* 60 min */
#define MED_AVI_MAX_PARSING_TIME        (1000)        /* 1000*4.615ms~=4.6 sec */


typedef struct
{
    /* parser */
    STFSAL vid_fsal_cntx;
    STFSAL aud_fsal_cntx;
    STFSAL vid_idx_fsal_cntx;
    STFSAL aud_idx_fsal_cntx;    

    kal_char *vid_fsal_buf_p;
    kal_char *aud_fsal_buf_p;
    kal_char *vid_idx_fsal_buf_p;
    kal_char *aud_idx_fsal_buf_p;

    kal_uint32 riff_size;
    kal_uint32 file_header_size;
    kal_uint32 video_meta_size;
    kal_uint32 audio_meta_size;
    kal_uint32 junk_size;

    med_avi_file_header_struct file_header;
    med_avi_stream_header_struct video_stream_header;
    med_avi_stream_header_struct audio_stream_header;

    med_avi_video_format_header_struct video_format_header;
    med_avi_audio_format_header_struct audio_format_header;

    med_avi_index_struct *aud_idx_list_buf_p;
    med_avi_index_struct *vid_idx_list_buf_p;

    med_avi_index_map_struct vid_idx_map;
    med_avi_index_map_struct aud_idx_map;    
    med_avi_index_map_struct start_idx_map;
    kal_uint32 vid_idx_list_start_idx;
    kal_uint32 vid_idx_list_count;    
    kal_uint32 aud_idx_list_start_idx;
    kal_uint32 aud_idx_list_count;    
    kal_uint32 data_file_size;
    kal_uint32 idx_file_size;

    /* player */

    /* vid */
    kal_uint32 vid_frame_idx;
    kal_uint32 vid_total_frame;
    kal_uint64 vid_duration;

    /* aud */
    kal_uint32 aud_frame_idx;
    kal_uint32 aud_total_frame;
    kal_uint32 aud_remain_len;  /* remaing data in the segment */
    kal_bool is_valid_aud;

    /* recorder */
    FS_HANDLE data_h;
    FS_HANDLE idx_h;
    kal_uint64 ms_per_frame;
    kal_uint64 time_limit;

    kal_uint8 act_data_buf_id;  /* double buffe, 0 or 1 */
    kal_uint8 act_idx_buf_id;   /* double buffe, 0 or 1 */

    kal_uint32 data_written[2];
    kal_uint32 idx_written[2];

    kal_char *data_buf_p[2];
    kal_char *idx_buf_p[2];

    kal_int32 total_av_data_written;
    kal_int32 aud_len;
    kal_int32 av_data_offset;
    kal_uint32 vid_frame_count;
    
    med_avi_rec_struct rec_data;

    kal_mutexid avi_mutex;
    kal_uint32 movi_start;

} med_avi_cntx_struct;

med_avi_cntx_struct g_med_avi_cntx;
med_avi_cntx_struct *med_avi_p = &g_med_avi_cntx;


#define FETCH_TAG(__buf_p__)                                             \
do{                                                                      \
    ret = FSAL_Read(&med_avi_p->vid_fsal_cntx, (kal_uint8*)__buf_p__, 4);\
    if(ret != FSAL_OK)                                                   \
    {                                                                    \
        error_cause = MED_RES_OPEN_FILE_FAIL;                            \
        goto error;                                                      \
    }                                                                    \
}while(0);

#define FETCH_AND_CHECK_TAG(__buf_p__,__TAG__)                           \
do{                                                                      \
    ret = FSAL_Read(&med_avi_p->vid_fsal_cntx, (kal_uint8*)__buf_p__, 4);\
    if(ret != FSAL_OK)                                                   \
    {                                                                    \
        error_cause = MED_RES_OPEN_FILE_FAIL;                            \
        goto error;                                                      \
    }                                                                    \
    if(strncmp((char*)__buf_p__, (char*)__TAG__, 4) != 0)                \
    {                                                                    \
        error_cause = MED_RES_BAD_FORMAT;                                \
        goto error;                                                      \
    }                                                                    \
}while(0);

#define FETCH_SIZE()                                                       \
do{                                                                        \
    ret = FSAL_Read(&med_avi_p->vid_fsal_cntx, (kal_uint8*)&chunk_size, 4);\
    if(ret != FSAL_OK)                                                     \
    {                                                                      \
        error_cause = MED_RES_OPEN_FILE_FAIL;                              \
        goto error;                                                        \
    }                                                                      \
    ret = FSAL_GetCurPos(&med_avi_p->vid_fsal_cntx, (kal_uint32*)&cur_pos);\
    if(ret != FSAL_OK)                                                     \
    {                                                                      \
        error_cause = MED_RES_OPEN_FILE_FAIL;                              \
        goto error;                                                        \
    }                                                                      \
}while(0);

#define FETCH_DATA(__buf_p__,__size__)                                          \
do{                                                                             \
    ret = FSAL_Read(&med_avi_p->vid_fsal_cntx, (kal_uint8*)__buf_p__, __size__);\
    if(ret != FSAL_OK)                                                          \
    {                                                                           \
        error_cause = MED_RES_OPEN_FILE_FAIL;                                   \
        goto error;                                                             \
    }                                                                           \
}while(0);

#define GOTO_NEXT_CHUNK()                                          \
do{                                                                \
    if(cur_pos+chunk_size >= file_size)                            \
    {                                                              \
       goto parse_finish;                                          \
    }                                                              \
    ret = FSAL_Seek(&med_avi_p->vid_fsal_cntx, cur_pos+chunk_size);\
    if(ret != FSAL_OK)                                             \
    {                                                              \
        error_cause = MED_RES_OPEN_FILE_FAIL;                      \
        goto error;                                                \
    }                                                              \
}while(0);

#define FETCH_AUD_DATA(__buf_p__,__size__)                                      \
do{                                                                             \
    ret = FSAL_Read(&med_avi_p->aud_fsal_cntx, (kal_uint8*)__buf_p__, __size__);\
    if(ret != FSAL_OK)                                                          \
    {                                                                           \
        error_cause = MED_RES_OPEN_FILE_FAIL;                                   \
        goto error;                                                             \
    }                                                                           \
}while(0);

#define MAKE_UPPER(__buf_p__)     \
do{                               \
    kal_char *byte_p;             \
    kal_int32 i;                  \
    byte_p = (kal_char*)__buf_p__;\
    for(i = 0; i < 4; i++)        \
    {                             \
        if (byte_p[i] >= 'a')     \
        {                         \
           byte_p[i] += 'A' - 'a';\
        }                         \
    }                             \
}while(0);

#define IS_TAG_MATCH(__buf_p__,__tag__)\
    (strncmp((char*)__buf_p__, (char*)__tag__, 4) == 0)

#define IS_TAG_NOT_MATCH(__buf_p__,__tag__)\
    (strncmp((char*)__buf_p__, (char*)__tag__, 4) != 0)

static kal_int32 med_avi_close_play_internal(void);
static kal_int32 med_avi_open_play_internal(
                    med_avi_info_struct *avi_info_p,
                    const kal_wchar *filename,
                    kal_char *data_p,
                    kal_int32 data_size);

static kal_int32 med_avi_read_video_frame_internal(kal_char *data_p, kal_uint32 *len_p, kal_bool is_move_next);
static kal_int32 med_avi_load_aud_idx(kal_uint32 frame_idx);
static kal_int32 med_avi_load_vid_idx(kal_uint32 frame_idx);
static kal_int32 med_avi_get_vid_idx(kal_uint32 frame_idx, med_avi_index_struct **idx_p);
static kal_int32 med_avi_get_aud_idx(kal_uint32 frame_idx, med_avi_index_struct **idx_p);

/*****************************************************************************
 * FUNCTION
 *  med_avi_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void med_avi_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    med_avi_p->avi_mutex = kal_create_mutex("AVI");
}

/*****************************************************************************
 * FUNCTION
 *  med_avi_open_play_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  avi_info_p      [?]         
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_open_play_file(med_avi_info_struct *avi_info_p, const kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return med_avi_open_play_internal(avi_info_p, filename, NULL, 0);
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_open_play_array
 * DESCRIPTION
 *  
 * PARAMETERS
 *  avi_info_p      [?]         
 *  data_p          [?]         
 *  data_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_open_play_array(med_avi_info_struct *avi_info_p, kal_char *data_p, kal_int32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return med_avi_open_play_internal(avi_info_p, NULL, data_p, data_size);
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_close_play_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_close_play_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return med_avi_close_play_internal();
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_close_play_array
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_close_play_array(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return med_avi_close_play_internal();
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_open_play_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  avi_info_p      [?]         
 *  filename        [IN]        
 *  data_p          [?]         
 *  data_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 med_avi_open_play_internal(
                    med_avi_info_struct *avi_info_p,
                    const kal_wchar *filename,
                    kal_char *data_p,
                    kal_int32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 data_dword;
    FSAL_Status ret;
    kal_bool is_file_opened;
    kal_int32 error_cause;
    med_avi_stream_header_struct stream_header;
    kal_int32 cur_pos;
    kal_int32 chunk_size;
    kal_uint32 file_size;
    kal_uint32 file_pos;
    kal_uint32 idx_count;
    kal_uint32 aud_idx;
    kal_uint32 vid_idx;
    kal_uint32 idx_id;
    kal_uint32 i;
    kal_uint32 start_time;
    kal_uint32 current_time;
    kal_uint32 elapse_time;
    med_avi_index_struct idx_data;
    med_avi_index_struct *idx_p;
    kal_uint32 max_idx_count;
    kal_bool need_cal_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, AVI_TRC_OPEN_PLAY_INTERNAL);      
    kal_get_time(&start_time);

    /* init */
    med_avi_p->vid_frame_idx = 0;
    med_avi_p->vid_total_frame = 0;

    med_avi_p->aud_total_frame = 0;
    med_avi_p->aud_frame_idx = 0;
    med_avi_p->aud_remain_len = 0;
    med_avi_p->is_valid_aud = KAL_FALSE;

    memset((void*)&med_avi_p->file_header, 0, sizeof(med_avi_file_header_struct));
    memset((void*)&med_avi_p->video_stream_header, 0, sizeof(med_avi_stream_header_struct));
    memset((void*)&med_avi_p->audio_stream_header, 0, sizeof(med_avi_stream_header_struct));

    is_file_opened = KAL_FALSE;

    /* allocate buffer - fsal */
    med_avi_p->vid_fsal_buf_p = (kal_char*)med_alloc_ext_mem(MED_AVI_VID_FSAL_BUF_SIZE);
    ASSERT(med_avi_p->vid_fsal_buf_p != 0);

    med_avi_p->vid_idx_fsal_buf_p = (kal_char*)med_alloc_ext_mem(MED_AVI_IDX_FSAL_BUF_SIZE);
    ASSERT(med_avi_p->vid_idx_fsal_buf_p != 0);

    med_avi_p->aud_fsal_buf_p = (kal_char*)med_alloc_ext_mem(MED_AVI_AUD_FSAL_BUF_SIZE);
    ASSERT(med_avi_p->aud_fsal_buf_p != 0);

    med_avi_p->aud_idx_fsal_buf_p = (kal_char*)med_alloc_ext_mem(MED_AVI_IDX_FSAL_BUF_SIZE);
    ASSERT(med_avi_p->aud_idx_fsal_buf_p != 0);

    /* idx cache buffer */
    med_avi_p->vid_idx_list_buf_p = (med_avi_index_struct*)med_alloc_ext_mem(MED_AVI_IDX_BUF_SIZE);
    ASSERT(med_avi_p->vid_idx_list_buf_p != 0);

    med_avi_p->aud_idx_list_buf_p = (med_avi_index_struct*)med_alloc_ext_mem(MED_AVI_IDX_BUF_SIZE);
    ASSERT(med_avi_p->aud_idx_list_buf_p != 0);

    /* TODO: add parse timeout protection */

    /* open resource, create FSAL */
    if (filename != NULL)
    {
        /* open from file - vid */
        ret = FSAL_Open(&med_avi_p->vid_fsal_cntx, (void*)filename, FSAL_READ);
        ret = FSAL_Open(&med_avi_p->vid_idx_fsal_cntx, (void*)filename, FSAL_READ);
        
        /* open from file - aud */
        ret = FSAL_Open(&med_avi_p->aud_fsal_cntx, (void*)filename, FSAL_READ);
        ret = FSAL_Open(&med_avi_p->aud_idx_fsal_cntx, (void*)filename, FSAL_READ);
 
        FSAL_SetBuffer(
            &med_avi_p->vid_fsal_cntx, 
            MED_AVI_VID_FSAL_BUF_SIZE, 
            (kal_uint8*)med_avi_p->vid_fsal_buf_p);

        FSAL_SetBuffer(
            &med_avi_p->vid_idx_fsal_cntx, 
            MED_AVI_IDX_FSAL_BUF_SIZE, 
            (kal_uint8*)med_avi_p->vid_idx_fsal_buf_p);

        FSAL_SetBuffer(
            &med_avi_p->aud_fsal_cntx, 
            MED_AVI_AUD_FSAL_BUF_SIZE, 
            (kal_uint8*)med_avi_p->aud_fsal_buf_p);
        
        FSAL_SetBuffer(
            &med_avi_p->aud_idx_fsal_cntx, 
            MED_AVI_IDX_FSAL_BUF_SIZE, 
            (kal_uint8*)med_avi_p->aud_idx_fsal_buf_p);
        
    }
    else
    {
        /* open from memory */
        FSAL_Direct_SetRamFileSize(&med_avi_p->vid_fsal_cntx, data_size);
        ret = FSAL_Open(&med_avi_p->vid_fsal_cntx, (void*)data_p, FSAL_ROMFILE);

        FSAL_Direct_SetRamFileSize(&med_avi_p->vid_idx_fsal_cntx, data_size);
        ret = FSAL_Open(&med_avi_p->vid_idx_fsal_cntx, (void*)data_p, FSAL_ROMFILE);

        FSAL_Direct_SetRamFileSize(&med_avi_p->aud_fsal_cntx, data_size);
        ret = FSAL_Open(&med_avi_p->aud_fsal_cntx, (void*)data_p, FSAL_ROMFILE);

        FSAL_Direct_SetRamFileSize(&med_avi_p->aud_idx_fsal_cntx, data_size);
        ret = FSAL_Open(&med_avi_p->aud_idx_fsal_cntx, (void*)data_p, FSAL_ROMFILE);

        FSAL_SetBuffer(
            &med_avi_p->vid_fsal_cntx, 
            MED_AVI_VID_FSAL_BUF_SIZE, 
            (kal_uint8*)med_avi_p->vid_fsal_buf_p);
        
        FSAL_SetBuffer(
            &med_avi_p->vid_idx_fsal_cntx, 
            MED_AVI_IDX_FSAL_BUF_SIZE, 
            (kal_uint8*)med_avi_p->vid_idx_fsal_buf_p);

        
        FSAL_SetBuffer(
            &med_avi_p->aud_fsal_cntx, 
            MED_AVI_AUD_FSAL_BUF_SIZE, 
            (kal_uint8*)med_avi_p->aud_fsal_buf_p);
        
        FSAL_SetBuffer(
            &med_avi_p->aud_idx_fsal_cntx, 
            MED_AVI_IDX_FSAL_BUF_SIZE, 
            (kal_uint8*)med_avi_p->aud_idx_fsal_buf_p);
        
    }

    if (ret != FSAL_OK)
    {
        error_cause = MED_RES_OPEN_FILE_FAIL;
        goto error;
    }
    else
    {
        is_file_opened = KAL_TRUE;
    }

    FSAL_GetFileSize(&med_avi_p->vid_fsal_cntx, &file_size);

    if (file_size == 0)
    {
        error_cause = MED_RES_BAD_FORMAT;    
        goto error;
    }

    /*
     * [AVI File Format] for MJPEG
     * 
     * RIFF.4.AVI .
     *     LIST.4.hdlr.avih.4.(file header)
     *     LIST.4.strl.strh.4.(video header)
     *                .strf.4.(video format)
     *     LIST.4.strl.strh.4.(audio header)
     *                .strf.4.(audio format)
     *     JUNK.4.(junk)
     *     LIST.4.movi.xxdb.4.(video data)
     *                 xxdc.4.(video data) 
     *                 xxwb.4.(audio data)  
     *            ind1.4.(list data)
     */

    /* read RIFF header and get size */
    FETCH_AND_CHECK_TAG(&data_dword, MED_AVI_TAG_RIFF);
    FETCH_SIZE();

    med_avi_p->riff_size = chunk_size;

    /* read AVI type */
    FETCH_AND_CHECK_TAG(&data_dword, MED_AVI_TAG_AVI);

    while (1)
    {
        /* avoid decode too long */
        kal_get_time(&current_time);

        kal_trace(TRACE_GROUP_4, VID_TRC_START_TIME, start_time);  
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, current_time);          

        if (current_time >= start_time)
        {
            elapse_time = current_time - start_time;
        }
        else
        {
            /* wrap around case */
            elapse_time = current_time - (0xFFFFFFFF - 1 - start_time);
        }

        if (elapse_time > MED_AVI_MAX_PARSING_TIME)
        {
            error_cause = MED_RES_VIDEO_FILE_TOO_LARGE;
            goto error;
        }

        FSAL_GetCurPos(&med_avi_p->vid_fsal_cntx, &file_pos);

        if (file_pos >= file_size)
        {
            /* teminate condition */
            break;
        }

        /* read LIST or JUNK */
        FETCH_TAG(&data_dword);

        if (IS_TAG_MATCH(&data_dword, MED_AVI_TAG_LIST))
        {
            /* LIST */
            FETCH_SIZE();

            /* read tag */
            FETCH_TAG(&data_dword);

            if (IS_TAG_MATCH(&data_dword, MED_AVI_TAG_HEADER_LIST))
            {
                kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_FILE_HEADER);     

                /* avhi */
                FETCH_AND_CHECK_TAG(&data_dword, MED_AVI_TAG_AVI_HEADER);
                FETCH_SIZE();

                FETCH_DATA(&med_avi_p->file_header, sizeof(med_avi_file_header_struct));
                GOTO_NEXT_CHUNK();
                
                kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_FILE_HEADER_DONE);                     
            }
            else if (IS_TAG_MATCH(&data_dword, MED_AVI_TAG_STREAM_LIST))
            {
                /* strl readed */

                /* read strh */
                FETCH_AND_CHECK_TAG(&data_dword, MED_AVI_TAG_STREAM_HEADER);
                FETCH_SIZE();
                FETCH_DATA(&stream_header, sizeof(med_avi_stream_header_struct));

                if (IS_TAG_MATCH(&stream_header.fcc_type, MED_AVI_TAG_STREAM_TYPE_VID))
                {
                    kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_VID_HEADER);                     
                
                    MAKE_UPPER(&stream_header.fcc_hdlr);

                    if (IS_TAG_NOT_MATCH(&stream_header.fcc_hdlr, MED_AVI_TAG_MJPG))
                    {
                        error_cause = MED_RES_BAD_FORMAT;
                        goto error;
                    }

                    /* video type */
                    memcpy(
                        (char*)&med_avi_p->video_stream_header,
                        &stream_header,
                        sizeof(med_avi_stream_header_struct));

                    GOTO_NEXT_CHUNK();

                    /* read video strh */
                    FETCH_AND_CHECK_TAG(&data_dword, MED_AVI_TAG_STREAM_FORMAT);
                    FETCH_SIZE();
                    FETCH_DATA(&med_avi_p->video_format_header, sizeof(med_avi_video_format_header_struct));

                    GOTO_NEXT_CHUNK();

                    kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_VID_HEADER_DONE);                                         
                }
                else if (IS_TAG_MATCH(&stream_header.fcc_type, MED_AVI_TAG_STREAM_TYPE_AUD))
                {
                    kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_AUD_HEADER);                     
                
                    /* audio type */
                    memcpy(
                        (char*)&med_avi_p->audio_stream_header,
                        &stream_header,
                        sizeof(med_avi_stream_header_struct));

                    GOTO_NEXT_CHUNK();

                    /* read audio strh */
                    FETCH_AND_CHECK_TAG(&data_dword, MED_AVI_TAG_STREAM_FORMAT);
                    FETCH_SIZE();
                    FETCH_DATA(&med_avi_p->audio_format_header, sizeof(med_avi_audio_format_header_struct));

                    if (med_avi_p->audio_format_header.format == MED_AVI_AUD_FORMAT_WAV_PCM)
                    {
                        kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_AUD_ON);                                             
                        med_avi_p->is_valid_aud = KAL_TRUE;
                    }
                    else
                    {
                        kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_AUD_OFF);                                             
                        med_avi_p->is_valid_aud = KAL_FALSE;
                    }

                    GOTO_NEXT_CHUNK();
                    kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_AUD_HEADER_DONE);                                         
                }
                else
                {
                    /* unknow fourCC type */
                }

            }
            else if (IS_TAG_MATCH(&data_dword, MED_AVI_TAG_MOVI))
            {
                kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_MOVI);    
                
                FSAL_GetCurPos(&med_avi_p->vid_fsal_cntx, &med_avi_p->movi_start);
                kal_prompt_trace(MOD_MED, "head_chunk_pos=%d", med_avi_p->movi_start);
                med_avi_p->movi_start -= 4;

                /* movi - skip when parsing */
                GOTO_NEXT_CHUNK();

                /* idx1 */
                FETCH_AND_CHECK_TAG(&data_dword, MED_AVI_TAG_IDX1);
                FETCH_SIZE();

                /* calc a and v buffer can put how many idx struct */
                max_idx_count = MED_AVI_IDX_BUF_SIZE/sizeof(med_avi_index_struct);
                
                idx_count = chunk_size / sizeof(med_avi_index_struct);

                aud_idx = 0;
                vid_idx = 0;

                /* get index start position */
                FSAL_GetCurPos(&med_avi_p->vid_fsal_cntx, &med_avi_p->vid_idx_map.file_offset);
                med_avi_p->vid_idx_map.frame_idx = 0;

                med_avi_p->aud_idx_map.file_offset = med_avi_p->vid_idx_map.file_offset;
                med_avi_p->start_idx_map.file_offset = med_avi_p->vid_idx_map.file_offset;
                
                med_avi_p->aud_idx_map.frame_idx = med_avi_p->vid_idx_map.frame_idx;
                med_avi_p->start_idx_map.frame_idx = med_avi_p->vid_idx_map.frame_idx;

                need_cal_offset = KAL_TRUE;
                for (i = 0; i < idx_count; i++)
                {
                    FETCH_DATA(&idx_data, sizeof(med_avi_index_struct));
                    idx_id = idx_data.chunk_id & 0xFFFF0000;

                    if (idx_id == 0x62770000)   /* 00wb */
                    {
                        /* check first index. to check if offset from file start or MOVI start */
                        if (need_cal_offset)
                        {
                            if (idx_data.chunk_offset > med_avi_p->movi_start)
                            {
                                /* 
                                 * if first valid chunk offset value larger than movi start, 
                                 * means it should calc from the start of the file 
                                 */
                                med_avi_p->movi_start = 0;
                            }
                            need_cal_offset = KAL_FALSE;                            
                        }
                    
                        if (med_avi_p->is_valid_aud)
                        {
                            aud_idx++;
                        }
                    }
                    else if (idx_id == 0x62640000 ||    /* 00db - raw */
                             idx_id == 0x63640000)      /* 00dc - compressed */
                    {
                        /* check first index. to check if offset from file start or MOVI start */
                        if (need_cal_offset)
                        {
                            if (idx_data.chunk_offset > med_avi_p->movi_start)
                            {
                                /* 
                                 * if first valid chunk offset value larger than movi start, 
                                 * means it should calc from the start of the file 
                                 */
                                med_avi_p->movi_start = 0;
                            }
                            need_cal_offset = KAL_FALSE;                              
                        }
                    
                        vid_idx++;
                    }
                }

                med_avi_p->vid_total_frame = vid_idx;
                med_avi_p->aud_total_frame = aud_idx;
                /* load into index catch */

                GOTO_NEXT_CHUNK();

                kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_MOVI_DONE);                                     

            }
            else
            {
                /* skip unknow part */
                GOTO_NEXT_CHUNK();
            }

        }
        else if (IS_TAG_MATCH(&data_dword, MED_AVI_TAG_JUNK))
        {
            /* JUNK - skip */
            FETCH_SIZE();
            GOTO_NEXT_CHUNK();
        }
        else
        {
            /* unused chunk */
            FETCH_SIZE();
            GOTO_NEXT_CHUNK();
        }

    }

  parse_finish:

    kal_trace(TRACE_GROUP_4, AVI_TRC_PARSE_FINISH);                         
    
    if (med_avi_p->is_valid_aud && 
        med_avi_p->audio_format_header.format == MED_AVI_AUD_FORMAT_WAV_PCM &&
        med_avi_p->audio_format_header.sample_per_sec == 8000 &&
        med_avi_p->audio_format_header.channels == 1)
    {
        avi_info_p->aud_format = MED_AVI_AUD_FORMAT_PCM;

        if (med_avi_p->aud_total_frame != 0)
        {
            /* init idx cache */
            med_avi_p->aud_frame_idx = 0;            
            
            if (med_avi_load_aud_idx(med_avi_p->aud_frame_idx) != MED_RES_OK)
            {
                error_cause = MED_RES_FSAL_ERROR;
                goto error;
            }

            if (med_avi_get_aud_idx(med_avi_p->aud_frame_idx, &idx_p) != MED_RES_OK)
            {
                error_cause = MED_RES_FSAL_ERROR;
                goto error;
            }

            med_avi_p->aud_remain_len = idx_p->chunk_lenght;

            /* +8 skip xxwb (4 byte), size (4 byte) */
            ret = FSAL_Seek(&med_avi_p->aud_fsal_cntx, idx_p->chunk_offset + 8);
        }

        avi_info_p->aud_sample_rate = med_avi_p->audio_format_header.sample_per_sec;
        avi_info_p->aud_channel = med_avi_p->audio_format_header.channels;
        avi_info_p->aud_bit_per_sample = med_avi_p->audio_format_header.bit_per_sample;

        kal_trace(TRACE_GROUP_4, AVI_TRC_AUD_SAMPLE_RATE, avi_info_p->aud_sample_rate);                             
        kal_trace(TRACE_GROUP_4, AVI_TRC_AUD_CHANNEL, avi_info_p->aud_channel); 
        kal_trace(TRACE_GROUP_4, AVI_TRC_AUD_BIT_PER_SAMPLE, avi_info_p->aud_bit_per_sample); 
        kal_trace(TRACE_GROUP_4, AVI_TRC_AUD_FRAME, med_avi_p->aud_total_frame);                 
    }
    else
    {
        avi_info_p->aud_format = MED_AVI_AUD_FORMAT_NOT_SUPPORT;
        error_cause = MED_RES_AUDIO_ERROR;        
        goto error;        
    }

    /* avoid divie by 0 - will cause data abort */
    if (med_avi_p->video_stream_header.rate == 0)
    {
        error_cause = MED_RES_BAD_FORMAT;
        goto error;
    }

    if (med_avi_p->video_stream_header.scale == 0)
    {
        error_cause = MED_RES_BAD_FORMAT;
        goto error;
    }

    /* init idx cache */
    if (med_avi_load_vid_idx(0) != MED_RES_OK)
    {
        error_cause = MED_RES_FSAL_ERROR;
        goto error;
    }

    /* duration farme_no/fps = frame_no*1000/(rate/scale) = frame_no*1000*scale/rate */
    med_avi_p->vid_duration
        = ((kal_uint64) med_avi_p->vid_total_frame)
        * ((kal_uint64) med_avi_p->video_stream_header.scale)
        * 1000 / ((kal_uint64) med_avi_p->video_stream_header.rate);

    avi_info_p->vid_fps =
        (kal_int32) ((med_avi_p->video_stream_header.rate * 10) / (med_avi_p->video_stream_header.scale * 10));

    if (avi_info_p->vid_fps == 0)
    {
        error_cause = MED_RES_BAD_FORMAT;
        goto error;
    }
    
    
    avi_info_p->vid_format = MED_AVI_VID_FORMAT_MJPEG;
    avi_info_p->vid_width = med_avi_p->video_format_header.width;
    avi_info_p->vid_height = med_avi_p->video_format_header.height;

    avi_info_p->vid_duration_in_ms = med_avi_p->vid_duration;

    avi_info_p->vid_rate = med_avi_p->video_stream_header.rate;
    avi_info_p->vid_scale = med_avi_p->video_stream_header.scale;

    kal_trace(TRACE_GROUP_4, AVI_TRC_VID_FPS, avi_info_p->vid_fps);
    kal_trace(TRACE_GROUP_4, AVI_TRC_VID_WIDTH, avi_info_p->vid_width);
    kal_trace(TRACE_GROUP_4, AVI_TRC_VID_HEIGHT, avi_info_p->vid_height);
    kal_trace(TRACE_GROUP_4, AVI_TRC_VID_DURATION_IN_MS, avi_info_p->vid_duration_in_ms);
    kal_trace(TRACE_GROUP_4, AVI_TRC_VID_RATE, avi_info_p->vid_rate);
    kal_trace(TRACE_GROUP_4, AVI_TRC_VID_SCALE, avi_info_p->vid_scale);
    kal_trace(TRACE_GROUP_4, AVI_TRC_VID_FRAME, med_avi_p->vid_total_frame);


    med_debug_print_result(MED_RES_OK, __LINE__); 
    return MED_RES_OK;

  error:
    if (is_file_opened)
    {
        FSAL_Close(&med_avi_p->vid_fsal_cntx);
        FSAL_Close(&med_avi_p->vid_idx_fsal_cntx);        
        FSAL_Close(&med_avi_p->aud_fsal_cntx);
        FSAL_Close(&med_avi_p->aud_idx_fsal_cntx);        
    }

    /* open file failed */
    med_free_ext_mem((void**)&med_avi_p->vid_fsal_buf_p);
    med_free_ext_mem((void**)&med_avi_p->vid_idx_fsal_buf_p);    
    med_free_ext_mem((void**)&med_avi_p->aud_fsal_buf_p);
    med_free_ext_mem((void**)&med_avi_p->aud_idx_fsal_buf_p);    
    med_free_ext_mem((void**)&med_avi_p->vid_idx_list_buf_p);
    med_free_ext_mem((void**)&med_avi_p->aud_idx_list_buf_p);

    med_avi_p->vid_fsal_buf_p = NULL;
    med_avi_p->vid_idx_fsal_buf_p = NULL;    
    med_avi_p->aud_fsal_buf_p = NULL;
    med_avi_p->aud_idx_fsal_buf_p = NULL;    
    med_avi_p->aud_idx_list_buf_p = NULL;
    med_avi_p->vid_idx_list_buf_p = NULL;

    med_debug_print_result(error_cause, __LINE__); 
    return error_cause;

}


/*****************************************************************************
 * FUNCTION
 *  med_avi_close_play_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 med_avi_close_play_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_close_play_internal()");

    ASSERT(med_avi_p->vid_fsal_buf_p != NULL);

    FSAL_Close(&med_avi_p->vid_fsal_cntx);
    FSAL_Close(&med_avi_p->vid_idx_fsal_cntx);    
    FSAL_Close(&med_avi_p->aud_fsal_cntx);
    FSAL_Close(&med_avi_p->aud_idx_fsal_cntx);    

    /* open file failed */
    med_free_ext_mem((void**)&med_avi_p->vid_fsal_buf_p);
    med_free_ext_mem((void**)&med_avi_p->vid_idx_fsal_buf_p);    
    med_free_ext_mem((void**)&med_avi_p->aud_fsal_buf_p);
    med_free_ext_mem((void**)&med_avi_p->aud_idx_fsal_buf_p);    
    med_free_ext_mem((void**)&med_avi_p->vid_idx_list_buf_p);
    med_free_ext_mem((void**)&med_avi_p->aud_idx_list_buf_p);

    med_avi_p->vid_fsal_buf_p = NULL;
    med_avi_p->vid_idx_fsal_buf_p = NULL;
    med_avi_p->aud_fsal_buf_p = NULL;
    med_avi_p->aud_idx_fsal_buf_p = NULL;    
    med_avi_p->aud_idx_list_buf_p = NULL;
    med_avi_p->vid_idx_list_buf_p = NULL;

    return MED_RES_OK;
}



/*****************************************************************************
 * FUNCTION
 *  med_avi_load_aud_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 med_avi_load_aud_idx(kal_uint32 frame_idx)
{
    kal_uint32 file_offset;
    kal_uint32 cur_frame_idx;
    kal_uint32 cache_frame_idx;
    kal_int32 fs_ret;
    med_avi_index_struct idx_data;
    kal_uint32 idx_id;
    kal_uint32 max_idx_count;
    kal_uint32 cur_file_offset;

    cache_frame_idx = 0;
    med_avi_p->aud_idx_list_start_idx = frame_idx;
    med_avi_p->aud_idx_list_count = 0;

    /* find start position */    
    if (frame_idx < med_avi_p->aud_idx_map.frame_idx)
    {
        cur_frame_idx = med_avi_p->start_idx_map.frame_idx;
        file_offset = med_avi_p->start_idx_map.file_offset; 
    }
    else
    {
        cur_frame_idx = med_avi_p->aud_idx_map.frame_idx;
        file_offset = med_avi_p->aud_idx_map.file_offset; 
    }

    max_idx_count = MED_AVI_IDX_BUF_SIZE / sizeof(med_avi_index_struct);

    /* search to frame idx position */
    fs_ret = FSAL_GetCurPos(&med_avi_p->aud_idx_fsal_cntx, &cur_file_offset);    
    
    if (fs_ret != FSAL_OK)
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: FSAL_GetCurPos Error");
        return MED_RES_FSAL_ERROR;
    }   
    
    if (cur_file_offset != file_offset)
    {
        /* avoid unessary seek */
        fs_ret = FSAL_Seek(&med_avi_p->aud_idx_fsal_cntx, file_offset);

        if (fs_ret != FSAL_OK)
        {
            kal_prompt_trace(MOD_MED, "[MED AVI] ret: FSAL_Seek Error");
            return MED_RES_FSAL_ERROR;
        }        
    }

    while(1)
    {
        memset((void*)&idx_data, 0, sizeof(med_avi_index_struct));
        fs_ret = FSAL_Read(&med_avi_p->aud_idx_fsal_cntx, (kal_uint8*)&idx_data, sizeof(med_avi_index_struct));

        if (fs_ret == FSAL_READ_OVER_EOF)
        {
            /* read to EOF */
            break;
        }
        else if (fs_ret != FSAL_OK)
        {
            kal_prompt_trace(MOD_MED, "[MED AVI] ret: FSAL_Read Error");
            return MED_RES_FSAL_ERROR;
        }        
        
        idx_id = idx_data.chunk_id & 0xFFFF0000;
            
        if (idx_id == 0x62770000)   /* 00wb */
        {
            if (cur_frame_idx >= frame_idx)
            {
                memcpy(
                    &med_avi_p->aud_idx_list_buf_p[cache_frame_idx], 
                    &idx_data, 
                    sizeof(med_avi_index_struct));
                
                cache_frame_idx++;           
                
                if (cache_frame_idx >= med_avi_p->aud_total_frame)
                {
                    break;
                }

                /* cache is full */
                if (cache_frame_idx >= max_idx_count)
                {
                    med_avi_p->aud_idx_map.frame_idx = cur_frame_idx + 1;
                    FSAL_GetCurPos(&med_avi_p->aud_idx_fsal_cntx, &med_avi_p->aud_idx_map.file_offset);
                    break;
                }                
            }
            
            cur_frame_idx ++;            
        }
        else if (idx_id == 0x62640000 ||    /* 00db */
                 idx_id == 0x63640000)      /* 00dc */
        {
            /* skip vid */        
        }
        else
        {
            /* idx chunk finished */
            break;
        }
    }

    med_avi_p->aud_idx_list_count = cache_frame_idx;

    return MED_RES_OK;
}


static kal_int32 med_avi_load_vid_idx(kal_uint32 frame_idx)
{
    kal_uint32 file_offset;
    kal_uint32 cur_frame_idx;
    kal_uint32 cache_frame_idx;
    kal_int32 fs_ret;
    med_avi_index_struct idx_data;
    kal_uint32 idx_id;
    kal_uint32 max_idx_count;
    kal_uint32 cur_file_offset;
    
    cache_frame_idx = 0;
    med_avi_p->vid_idx_list_start_idx = frame_idx;
    med_avi_p->vid_idx_list_count = 0;

    /* find start position */    
    if (frame_idx < med_avi_p->vid_idx_map.frame_idx)
    {
        cur_frame_idx = med_avi_p->start_idx_map.frame_idx;
        file_offset = med_avi_p->start_idx_map.file_offset; 
    }
    else
    {
        cur_frame_idx = med_avi_p->vid_idx_map.frame_idx;
        file_offset = med_avi_p->vid_idx_map.file_offset; 
    }

    max_idx_count = MED_AVI_IDX_BUF_SIZE / sizeof(med_avi_index_struct);

    /* search to frame idx position */
    fs_ret = FSAL_GetCurPos(&med_avi_p->vid_idx_fsal_cntx, &cur_file_offset);    

    if (fs_ret != FSAL_OK)
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: FSAL_GetCurPos Error");
        return MED_RES_FSAL_ERROR;
    }  
    
    if (cur_file_offset != file_offset)
    {
        /* avoid unessary seek */
        fs_ret = FSAL_Seek(&med_avi_p->vid_idx_fsal_cntx, file_offset);

        if (fs_ret != FSAL_OK)
        {
            kal_prompt_trace(MOD_MED, "[MED AVI] ret: FSAL_Seek Error");
            return MED_RES_FSAL_ERROR;
        }
    }

    while(1)
    {
        memset((void*)&idx_data, 0, sizeof(med_avi_index_struct));
        fs_ret = FSAL_Read(&med_avi_p->vid_idx_fsal_cntx, (kal_uint8*)&idx_data, sizeof(med_avi_index_struct));

        if (fs_ret == FSAL_READ_OVER_EOF)
        {
            /* read to EOF */
            break;
        }
        else if (fs_ret != FSAL_OK)
        {
            kal_prompt_trace(MOD_MED, "[MED AVI] ret: FSAL_Read Error");
            return MED_RES_FSAL_ERROR;
        }
        
        idx_id = idx_data.chunk_id & 0xFFFF0000;
            
        if (idx_id == 0x62770000)   /* 00wb */
        {
            /* skip aud */
        }
        else if (idx_id == 0x62640000 ||    /* 00db */
                 idx_id == 0x63640000)      /* 00dc */
        {
            if (cur_frame_idx >= frame_idx)
            {
                memcpy(
                    &med_avi_p->vid_idx_list_buf_p[cache_frame_idx], 
                    &idx_data, 
                    sizeof(med_avi_index_struct));
                
                cache_frame_idx++;    
                
                if (cache_frame_idx >= med_avi_p->vid_total_frame)
                {
                    break;
                }         

                /* cache is full */
                if (cache_frame_idx >= max_idx_count)
                {
                    med_avi_p->vid_idx_map.frame_idx = cur_frame_idx + 1;
                    FSAL_GetCurPos(&med_avi_p->vid_idx_fsal_cntx, &med_avi_p->vid_idx_map.file_offset);
                    break;
                }                
            }
            
            cur_frame_idx ++;
        }
        else
        {
            /* idx chunk finished */
            break;
        }
    }

    med_avi_p->vid_idx_list_count = cache_frame_idx;

    return MED_RES_OK;
}


static kal_int32 med_avi_get_vid_idx(kal_uint32 frame_idx, med_avi_index_struct **idx_p)
{
    if (frame_idx >= med_avi_p->vid_idx_list_start_idx && 
        frame_idx < med_avi_p->vid_idx_list_start_idx + med_avi_p->vid_idx_list_count)
    {
        /* hit */
        *idx_p = &med_avi_p->vid_idx_list_buf_p[frame_idx - med_avi_p->vid_idx_list_start_idx];
        return MED_RES_OK;             
    }
    else
    {
        /* miss */
        if (med_avi_load_vid_idx(frame_idx) == MED_RES_OK)
        {
            *idx_p = &med_avi_p->vid_idx_list_buf_p[0];
            return MED_RES_OK;   
        }
        else
        {
            return MED_RES_FSAL_ERROR;
        }
    }
}


static kal_int32 med_avi_get_aud_idx(kal_uint32 frame_idx, med_avi_index_struct **idx_p)
{
    if (frame_idx >= med_avi_p->aud_idx_list_start_idx && 
        frame_idx < med_avi_p->aud_idx_list_start_idx + med_avi_p->aud_idx_list_count)
    {
        /* hit */
        *idx_p = &med_avi_p->aud_idx_list_buf_p[frame_idx - med_avi_p->aud_idx_list_start_idx];
        return MED_RES_OK;          
    }
    else
    {
        /* miss */
        if (med_avi_load_aud_idx(frame_idx) == MED_RES_OK)
        {
            *idx_p = &med_avi_p->aud_idx_list_buf_p[0];
             return MED_RES_OK;            
        }
        else
        {
             return MED_RES_FSAL_ERROR;          
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  med_avi_read_video_frame_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_p      [?]     
 *  len_p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_read_video_frame_move_next(kal_char *data_p, kal_uint32 *len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return med_avi_read_video_frame_internal(data_p, len_p, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_read_video_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_p      [?]     
 *  len_p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_read_video_frame(kal_char *data_p, kal_uint32 *len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return med_avi_read_video_frame_internal(data_p, len_p, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_read_video_frame_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_p              [?]         
 *  len_p               [?]         
 *  is_move_next        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 med_avi_read_video_frame_internal(kal_char *data_p, kal_uint32 *len_p, kal_bool is_move_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_avi_index_struct *idx_p;
    kal_int32 ret;
    kal_int32 error_cause;
    kal_uint32 vid_chunk_offset;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_read_video_frame_internal()");
    kal_prompt_trace(MOD_MED, "[MED AVI] idx: %d, req: %d)", med_avi_p->vid_frame_idx, *len_p);

    if (med_avi_p->vid_frame_idx >= med_avi_p->vid_total_frame)
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_VIDEO_END");
        return MED_RES_VIDEO_END;
    }

    if (med_avi_get_vid_idx(med_avi_p->vid_frame_idx, &idx_p) != MED_RES_OK)
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_FSAL_ERROR");
        return MED_RES_FSAL_ERROR;
    }

    vid_chunk_offset = idx_p->chunk_offset + med_avi_p->movi_start;
    ret = FSAL_Seek(&med_avi_p->vid_fsal_cntx, vid_chunk_offset + 8);

    FETCH_DATA(data_p, idx_p->chunk_lenght);

    *len_p = idx_p->chunk_lenght;

    if (is_move_next)
    {
        med_avi_p->vid_frame_idx++;
    }

    kal_prompt_trace(MOD_MED, "[MED AVI] read: %d)", *len_p);
    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
    return MED_RES_OK;

  error:
    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_VIDEO_ERROR");
    return MED_RES_VIDEO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_skip_video_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_p              [?]         
 *  len_p               [?]         
 *  is_move_next        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_skip_video_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_avi_index_struct *idx_p;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_skip_video_frame()");

    if (med_avi_p->vid_frame_idx >= med_avi_p->vid_total_frame)
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_VIDEO_END");
        return MED_RES_VIDEO_END;
    }

    if (med_avi_get_vid_idx(med_avi_p->vid_frame_idx, &idx_p) != MED_RES_OK)
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_FSAL_ERROR");
        return MED_RES_FSAL_ERROR;
    }

    /* +8 skip xxdb (4 byte), size (4 byte) + chunk data length */
    ret = FSAL_Seek(&med_avi_p->vid_fsal_cntx, idx_p->chunk_offset + 8 + idx_p->chunk_lenght);

    if (ret != FSAL_OK)
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_FSAL_ERROR");
        return MED_RES_FSAL_ERROR;
    }

    med_avi_p->vid_frame_idx++;

    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
    return MED_RES_OK;

}




/*****************************************************************************
 * FUNCTION
 *  med_avi_read_audio_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_p      [?]     
 *  len_p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_read_audio_data(kal_char *data_p, kal_uint32 *len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_avi_index_struct *idx_p;
    kal_int32 ret;
    kal_int32 error_cause;
    kal_int32 need_len;
    kal_uint32 aud_chunk_offset; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_read_audio_data()");

    kal_prompt_trace(
        MOD_MED,
        "[MED AVI] idx: %d, remain: %d, req: %d",
        med_avi_p->aud_frame_idx,
        med_avi_p->aud_remain_len,
        *len_p);

    /* check if audio valid */
    if (!med_avi_p->is_valid_aud)
    {
        *len_p = 0;

        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_INVALID_FORMAT");
        return MED_RES_AUDIO_ERROR;
    }

    need_len = *len_p;
    *len_p = 0;

    while (need_len)
    {
        if (med_avi_p->aud_remain_len == 0)
        {
            /* if remain all used, need move to next aud frame */

            if (med_avi_p->aud_frame_idx + 1 >= med_avi_p->aud_total_frame)
            {
                /* terminate condition */
                kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_AUDIO_END");
                return MED_RES_AUDIO_END;
            }

            med_avi_p->aud_frame_idx++;
            
            if (med_avi_get_aud_idx(med_avi_p->aud_frame_idx, &idx_p) != MED_RES_OK)
            {
                /* terminate condition */
                kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_FSAL_ERROR");
                return MED_RES_FSAL_ERROR;
            }

            aud_chunk_offset = idx_p->chunk_offset + med_avi_p->movi_start;

            /* +8 skip xxdb (4 byte), size (4 byte) */
            ret = FSAL_Seek(&med_avi_p->aud_fsal_cntx, aud_chunk_offset+ 8);  

            med_avi_p->aud_remain_len = idx_p->chunk_lenght;

            if (ret != FSAL_OK)
            {
                kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_FSAL_ERROR");
                return MED_RES_FSAL_ERROR;
            }

        }

        if (need_len >= med_avi_p->aud_remain_len)
        {
            /* needed data more than this segment */
            FETCH_AUD_DATA(data_p, med_avi_p->aud_remain_len);
            *len_p += med_avi_p->aud_remain_len;
            data_p += med_avi_p->aud_remain_len;    /* shift point */
            need_len -= med_avi_p->aud_remain_len;
            med_avi_p->aud_remain_len = 0;
        }
        else
        {
            /* remain data can fullfil request */
            FETCH_AUD_DATA(data_p, need_len);
            *len_p += need_len;
            med_avi_p->aud_remain_len -= need_len;
            need_len = 0;
        }

    }

    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
    return MED_RES_OK;

  error:
    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_AUDIO_ERROR");
    return MED_RES_AUDIO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_seek_by_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time_in_ms      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_seek_by_time(kal_uint64 time_in_ms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 need_aud_size;
    kal_int32 i;
    kal_int32 data_size;
    kal_int32 prev_data_size;
    kal_int32 data_within;
    med_avi_index_struct *idx_p;
    kal_int32 ret;
    kal_uint32 aud_chunk_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_seek_by_time()");
    kal_prompt_trace(MOD_MED, "[MED AVI] seek_time: %d", time_in_ms);

    /* VIDEO!! */

    /* rate/scale = FPS */
    /* rate/(scale*1000) = frame per ms */
    /* scale*1000/rate = ms per frame */
    /* frame_idx = time_in_ms/((scale*1000)/rate) */

    /* 
     * [example]
     * 
     * rate = 5000
     * scale = 1000
     * fps = 5
     * frame per ms = 5/1000
     * ms per frame = 1000/5 = 200ms
     */

    if (time_in_ms > med_avi_p->vid_duration)
    {
        /* seek time exceed total time */
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_PARAM_ERROR");
        return MED_RES_PARAM_ERROR;
    }

    med_avi_p->vid_frame_idx
        = time_in_ms * med_avi_p->video_stream_header.rate / (med_avi_p->video_stream_header.scale * 1000);

    if (med_avi_p->vid_frame_idx >= med_avi_p->vid_total_frame)
    {
        /* align to last valid index */
        med_avi_p->vid_frame_idx = med_avi_p->vid_total_frame - 1;
    }

    kal_prompt_trace(MOD_MED, "[MED AVI] vid idx: %d", med_avi_p->vid_frame_idx);

    /* AUDIO!! */
    if (med_avi_p->is_valid_aud)
    {
        /* seek from start */
        need_aud_size = time_in_ms * med_avi_p->audio_format_header.avg_byte_per_sec / 1000;

        prev_data_size = 0;
        data_size = 0;

        for (i = 0; i < med_avi_p->aud_total_frame; i++)
        {
            /* load index cache */
            if (med_avi_get_aud_idx(i, &idx_p) != MED_RES_OK)
            {
                kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_FSAL_ERROR");
                return MED_RES_FSAL_ERROR;   
            }
            
            data_size += idx_p->chunk_lenght;

            if (data_size > need_aud_size)
            {
                /* data within this segment */
                data_within = need_aud_size - prev_data_size;

                aud_chunk_offset = idx_p->chunk_offset + med_avi_p->movi_start;

                /* +8 skip xxdb (4 byte), size (4 byte) */
                ret = FSAL_Seek(&med_avi_p->aud_fsal_cntx, aud_chunk_offset + 8 + data_within);

                if (ret != FSAL_OK)
                {
                    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_FSAL_ERROR");
                    return MED_RES_FSAL_ERROR;
                }

                med_avi_p->aud_remain_len = idx_p->chunk_lenght - data_within;
                med_avi_p->aud_frame_idx = i;

                kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
                return MED_RES_OK;
            }

            prev_data_size = data_size;

        }

        /* V > A */
        med_avi_p->aud_frame_idx = med_avi_p->aud_total_frame;
        med_avi_p->aud_remain_len = 0;
        return MED_RES_OK;
    }

    kal_prompt_trace(
        MOD_MED,
        "[MED AVI] aud idx: %d, aud remain: %d",
        med_avi_p->aud_frame_idx,
        med_avi_p->aud_remain_len);

    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
    return MED_RES_OK;

}


/*****************************************************************************
 * FUNCTION
 *  med_avi_open_record_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rec_data_p      [?]         
 *  filename_p      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_open_record_file(med_avi_rec_struct *rec_data_p, const kal_wchar *filename_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *data_filename_p;
    kal_char *idx_filename_p;
    kal_int32 v_idx_count;
    kal_int32 a_idx_count;    
    kal_int64 max_limit;
    kal_int32 max_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_open_record_file()");

    /* check if rec_data is valid */
    ASSERT(rec_data_p->vid_scale != 0);

    med_avi_p->data_h = 0;
    med_avi_p->idx_h = 0;
    med_avi_p->total_av_data_written = 0;
    med_avi_p->av_data_offset = 0;
    med_avi_p->vid_frame_count = 0;
    med_avi_p->aud_len = 0;

    memcpy(&med_avi_p->rec_data, rec_data_p, sizeof(med_avi_rec_struct));

    /* allocate file name buf */
    data_filename_p = (kal_char*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * ENCODE_BYTE);
    ASSERT(data_filename_p != 0);

    idx_filename_p = (kal_char*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * ENCODE_BYTE);
    ASSERT(idx_filename_p != 0);

    /* rate/scale = fps */
    v_idx_count = med_avi_p->rec_data.vid_rate/med_avi_p->rec_data.vid_scale;
    a_idx_count = 3; /* we assume 3 audio frame per sec */

    max_count = (v_idx_count > a_idx_count) ? v_idx_count : a_idx_count;

    /* we need record limit size, this will be restricted by playback's idx buffer size */
    max_limit = 
        ((kal_uint64)MED_AVI_IDX_BUF_SIZE) * ((kal_uint64)1000) / 
        ((kal_uint64)(sizeof(med_avi_index_struct) * (max_count)));

    /* we hard code record time to 60 min */
    med_avi_p->time_limit = MED_AVI_RECORD_TIME_LIMIT*60*1000; /* in ms */

    /* TODO: we need implement catch loading mechanism for index */
//  ASSERT(max_limit > med_avi_p->time_limit);

    med_avi_p->ms_per_frame 
        = ((kal_uint64)med_avi_p->rec_data.vid_scale) * \
          ((kal_uint64)1000) / \
          ((kal_uint64)med_avi_p->rec_data.vid_rate);
    
    /*
     * [AVI File Format] for MJPEG
     * 
     * = Data File ========================
     * RIFF.4.AVI .
     *     LIST.4.hdlr.avih.4.(file header)
     *     LIST.4.strl.strh.4.(video header)
     *                .strf.4.(video format)
     *     LIST.4.strl.strh.4.(audio header)
     *                .strf.4.(audio format)
     *     JUNK.4.(junk)
     *     LIST.4.movi.xxdb.4.(video data)
     *                 xxdc.4.(video data) 
     *                 xxwb.4.(audio data)  
     * = Idx File =========================     
     *            idx1.4.(list data)
     * ====================================
     */

    /* data file - avi header and data chunk file  */
    kal_mem_cpy(data_filename_p, filename_p, MAX_FILE_NAME_LEN * ENCODE_BYTE);
    med_remove_file_name((kal_wchar*) data_filename_p);
    kal_wstrcat((kal_wchar*) data_filename_p, MED_AVI_VISUAL_FILE);

    med_avi_p->data_h = FS_Open((kal_wchar*) data_filename_p, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);

    if (med_avi_p->data_h <= 0)
    {
        med_free_ext_mem((void **)&data_filename_p);
        med_free_ext_mem((void **)&idx_filename_p);


        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OPEN_FILE_FAIL");
        return MED_RES_OPEN_FILE_FAIL;
    }

    /* seek to movi chunk */
    med_avi_p->av_data_offset = 4 + 4 + 4;  /* (RIFF.4.AVI .) */
    med_avi_p->av_data_offset += 4 + 4 + 4 + 4 + 4 + sizeof(med_avi_file_header_struct);        /*    LIST.4.hdlr.avih.4.(file header)    */
    med_avi_p->av_data_offset += 4 + 4 + 4 + 4 + 4 + sizeof(med_avi_stream_header_struct);      /*    LIST.4.strl.strh.4.(video header)   */
    med_avi_p->av_data_offset += 4 + 4 + sizeof(med_avi_video_format_header_struct);    /*               .strf.4.(video format)   */
    med_avi_p->av_data_offset += 4 + 4 + 4 + 4 + 4 + sizeof(med_avi_stream_header_struct);      /*    LIST.4.strl.strh.4.(audio header)   */
    med_avi_p->av_data_offset += 4 + 4 + sizeof(med_avi_audio_format_header_struct);    /*               .strf.4.(audio format)   */
    med_avi_p->av_data_offset += 4 + 4 + 4; /*    LIST.4.movi.                      */

    /* extend file - and seek to movi start */
    FS_Extend(med_avi_p->data_h, med_avi_p->av_data_offset);
    FS_Seek(med_avi_p->data_h, med_avi_p->av_data_offset, FS_FILE_BEGIN);

    /* idx file */
    kal_mem_cpy(idx_filename_p, filename_p, MAX_FILE_NAME_LEN * ENCODE_BYTE);
    med_remove_file_name((kal_wchar*) idx_filename_p);
    kal_wstrcat((kal_wchar*) idx_filename_p, MED_AVI_IDX_FILE);

    /* Todo */
    FS_Delete((kal_wchar*) idx_filename_p);

    med_avi_p->idx_h = FS_Open((kal_wchar*) idx_filename_p, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);

    if (med_avi_p->idx_h <= 0)
    {
        FS_Close(med_avi_p->data_h);
        med_free_ext_mem((void **)&data_filename_p);
        med_free_ext_mem((void **)&idx_filename_p);

        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OPEN_FILE_FAIL");
        return MED_RES_OPEN_FILE_FAIL;
    }

    med_free_ext_mem((void **)&data_filename_p);
    med_free_ext_mem((void **)&idx_filename_p);

    /* extend to idx.4 */
    FS_Extend(med_avi_p->idx_h, 8);
    FS_Seek(med_avi_p->idx_h, 8, FS_FILE_BEGIN);

    /* open file ok, allocate buffer for caching */
    med_avi_p->data_buf_p[0] = (kal_char*) med_alloc_ext_mem(MED_AVI_WRITE_DATA_BUF_SIZE);
    ASSERT(med_avi_p->data_buf_p[0] != 0);

    med_avi_p->data_buf_p[1] = (kal_char*) med_alloc_ext_mem(MED_AVI_WRITE_DATA_BUF_SIZE);
    ASSERT(med_avi_p->data_buf_p[1] != 0);

    med_avi_p->idx_buf_p[0] = (kal_char*) med_alloc_ext_mem(MED_AVI_WRITE_IDX_BUF_SIZE);
    ASSERT(med_avi_p->idx_buf_p[0] != 0);

    med_avi_p->idx_buf_p[1] = (kal_char*) med_alloc_ext_mem(MED_AVI_WRITE_IDX_BUF_SIZE);
    ASSERT(med_avi_p->idx_buf_p[1] != 0);

    med_avi_p->act_data_buf_id = 0;
    med_avi_p->act_idx_buf_id = 0;

    med_avi_p->data_written[0] = 0;
    med_avi_p->data_written[1] = 0;
    med_avi_p->idx_written[0] = 0;
    med_avi_p->idx_written[1] = 0;

    med_avi_p->data_file_size = 0;
    med_avi_p->idx_file_size = 0; 

    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
    return MED_RES_OK;

}


/*****************************************************************************
 * FUNCTION
 *  med_avi_close_record_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_close_record_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_close_record_file()");

    /* dump remain data in buffer to file */
//  med_avi_toggle_data_buffer();
//  med_avi_toggle_idx_buffer();
//  med_avi_dump_data_buffer_to_file();
//  med_avi_dump_idx_buffer_to_file();

    /* make sure resource is not freed yet */
    ASSERT(med_avi_p->data_buf_p[0] != 0);
    ASSERT(med_avi_p->data_buf_p[1] != 0);
    ASSERT(med_avi_p->idx_buf_p[0] != 0);
    ASSERT(med_avi_p->idx_buf_p[1] != 0);

    med_free_ext_mem((void **)&med_avi_p->data_buf_p[0]);
    med_free_ext_mem((void **)&med_avi_p->data_buf_p[1]);
    med_free_ext_mem((void **)&med_avi_p->idx_buf_p[0]);
    med_free_ext_mem((void **)&med_avi_p->idx_buf_p[1]);

    med_avi_p->data_buf_p[0] = NULL;
    med_avi_p->data_buf_p[1] = NULL;
    med_avi_p->idx_buf_p[0] = NULL;
    med_avi_p->idx_buf_p[1] = NULL;

    if (med_avi_p->data_h != 0)
    {
        FS_Close(med_avi_p->data_h);
    }

    if (med_avi_p->idx_h != 0)
    {
        FS_Close(med_avi_p->idx_h);
    }

    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_toggle_data_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 med_avi_toggle_data_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_avi_p->avi_mutex);
    
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_toggle_data_buffer()");

    if (med_avi_p->act_data_buf_id == 0)
    {
        /* make sure next chunk buffer is clear - data has been flushed to fs */
        if (med_avi_p->data_written[1] != 0)
        {
            /* 
             * the other buffer not flushed yet, 
             * has bandwith problem, need stop recording 
             */
            kal_give_mutex(med_avi_p->avi_mutex);             
            return MED_RES_FAIL;
        }

        med_avi_p->act_data_buf_id = 1;
    }
    else
    {
        /* make sure next chunk buffer is clear - data has been flushed to fs */
        if (med_avi_p->data_written[0] != 0)
        {
            /* 
             * the other buffer not flushed yet, 
             * has bandwith problem, need stop recording 
             */
            kal_give_mutex(med_avi_p->avi_mutex);             
            return MED_RES_FAIL;
        }        

        med_avi_p->act_data_buf_id = 0;
    }

    kal_give_mutex(med_avi_p->avi_mutex);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_toggle_idx_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 med_avi_toggle_idx_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_avi_p->avi_mutex);
    
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_toggle_idx_buffer()");

    if (med_avi_p->act_idx_buf_id == 0)
    {
        /* make sure next idx buffer is clear - data has been flushed to fs */
        if (med_avi_p->idx_written[1] != 0)
        {
            /* 
             * the other buffer not flushed yet, 
             * has bandwith problem, need stop recording 
             */
            kal_give_mutex(med_avi_p->avi_mutex);             
            return MED_RES_FAIL;
        }

        med_avi_p->act_idx_buf_id = 1;
    }
    else
    {
        /* make sure next idx buffer is clear - data has been flushed to fs */
        if (med_avi_p->idx_written[0] != 0)
        {
            /* 
             * the other buffer not flushed yet, 
             * has bandwith problem, need stop recording 
             */
            kal_give_mutex(med_avi_p->avi_mutex);             
            return MED_RES_FAIL;
        }

        med_avi_p->act_idx_buf_id = 0;
    }

    kal_give_mutex(med_avi_p->avi_mutex);    
    return MED_RES_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_dump_data_buffer_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_dump_data_buffer_to_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 written = 0;
    kal_int32 fs_ret;
    kal_int32 idx;
    kal_char *buf_ptr;
    kal_uint32 dump_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_avi_p->avi_mutex);    

    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_dump_data_buffer_to_file()");
    ASSERT(med_avi_p->data_h != 0);

    if (med_avi_p->act_data_buf_id == 0)
    {
        idx = 1;
    }
    else
    {
        idx = 0;
    }

    buf_ptr = med_avi_p->data_buf_p[idx];
    dump_size = med_avi_p->data_written[idx];

    kal_give_mutex(med_avi_p->avi_mutex);    

    
    kal_prompt_trace(MOD_MED, "[MED AVI] before FS_Write");
    fs_ret = FS_Write(med_avi_p->data_h, (void*)buf_ptr, dump_size, &written);
    kal_prompt_trace(MOD_MED, "[MED AVI] FS_Write done");

    med_avi_p->data_file_size += written;
    
    if (fs_ret < 0) /* !FS_NO_ERROR */
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_ERROR");
        kal_prompt_trace(MOD_MED, "[MED AVI] fs error: %d", fs_ret);     
        
        kal_take_mutex(med_avi_p->avi_mutex);           
        med_avi_p->data_written[idx] = 0;                
        kal_give_mutex(med_avi_p->avi_mutex);       
        return MED_RES_ERROR;
    }

    if (written != med_avi_p->data_written[idx])
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_NOT_ENOUGH_SPACE");

        kal_take_mutex(med_avi_p->avi_mutex);           
        med_avi_p->data_written[idx] = 0;       
        kal_give_mutex(med_avi_p->avi_mutex);        
        return MED_RES_NOT_ENOUGH_SPACE;
    }

    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");

    kal_take_mutex(med_avi_p->avi_mutex);    
    med_avi_p->data_written[idx] = 0;    
    kal_give_mutex(med_avi_p->avi_mutex);        
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_dump_idx_buffer_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_dump_idx_buffer_to_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 written = 0;
    kal_int32 fs_ret;
    kal_int32 idx;
    kal_char *buf_ptr;
    kal_uint32 dump_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_avi_p->avi_mutex);    
    
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_dump_idx_buffer_to_file()");
    ASSERT(med_avi_p->idx_h != 0);

    if (med_avi_p->act_idx_buf_id == 0)
    {
        idx = 1;
    }
    else
    {
        idx = 0;
    }

    buf_ptr = med_avi_p->idx_buf_p[idx];
    dump_size = med_avi_p->idx_written[idx];

    kal_give_mutex(med_avi_p->avi_mutex);    

    /* fs access may take too long, dont put in mutex protection */    
    kal_prompt_trace(MOD_MED, "[MED AVI] before FS_Write");    
    fs_ret = FS_Write(med_avi_p->idx_h, (void*)buf_ptr, dump_size, &written);
    kal_prompt_trace(MOD_MED, "[MED AVI] FS_Write done");

    med_avi_p->idx_file_size += written;

    if (fs_ret < 0) /* !FS_NO_ERROR */
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_ERROR");
        
        kal_take_mutex(med_avi_p->avi_mutex);            
        med_avi_p->idx_written[idx] = 0;        
        kal_give_mutex(med_avi_p->avi_mutex);        
        return MED_RES_ERROR;
    }

    if (written != med_avi_p->idx_written[idx])
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_NOT_ENOUGH_SPACE");
        
        kal_take_mutex(med_avi_p->avi_mutex);            
        med_avi_p->idx_written[idx] = 0;            
        kal_give_mutex(med_avi_p->avi_mutex);        
        return MED_RES_NOT_ENOUGH_SPACE;
    }

    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");

    kal_take_mutex(med_avi_p->avi_mutex);
    med_avi_p->idx_written[idx] = 0; 
    kal_give_mutex(med_avi_p->avi_mutex);    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_is_active_data_buf_sufficient
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_is_active_data_buf_sufficient(kal_int32 req_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 remain_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_avi_p->avi_mutex);
    
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_is_active_data_buf_sufficient()");

    remain_buf = MED_AVI_WRITE_DATA_BUF_SIZE - med_avi_p->data_written[med_avi_p->act_data_buf_id];

    /* 
     * when write data chunk, we will write 4 byte of 00db or 01wb 
     * and 4 byte of chunk size, so we need add 8 byte to  req buffer size 
     */
    
    if (remain_buf <= (req_size+8))
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_BUFFER_INSUFFICIENT");
        kal_give_mutex(med_avi_p->avi_mutex);        
        return MED_RES_BUFFER_INSUFFICIENT;
    }
    else
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
        kal_give_mutex(med_avi_p->avi_mutex);           
        return MED_RES_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_is_active_idx_buf_sufficient
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_is_active_idx_buf_sufficient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 remain_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_avi_p->avi_mutex);
    
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_is_active_idx_buf_sufficient()");

    remain_buf = MED_AVI_WRITE_IDX_BUF_SIZE - med_avi_p->idx_written[med_avi_p->act_idx_buf_id];

    if (remain_buf <= sizeof(med_avi_index_struct))
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_BUFFER_INSUFFICIENT");
        kal_give_mutex(med_avi_p->avi_mutex);        
        return MED_RES_BUFFER_INSUFFICIENT;
    }
    else
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
        kal_give_mutex(med_avi_p->avi_mutex);        
        return MED_RES_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_write_video_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_p      [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_write_video_frame(kal_char *data_p, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *data_buf_p;
    kal_char *idx_buf_p;
    kal_uint32 size;
    med_avi_index_struct idx_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_avi_p->avi_mutex);
    
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_write_video_frame()");
    kal_prompt_trace(MOD_MED, "[MED AVI] write: %d", len);

    /* video data */
    /* 00db, size, raw data */
    /* 4     4     ... */

    size = len;

    data_buf_p = med_avi_p->data_buf_p[med_avi_p->act_data_buf_id];
    data_buf_p += med_avi_p->data_written[med_avi_p->act_data_buf_id];
    memcpy(data_buf_p, &("00db"), 4);
    data_buf_p += 4;
    memcpy(data_buf_p, &size, 4);
    data_buf_p += 4;
    memcpy(data_buf_p, data_p, len);

    /* write idx */
    memcpy(&idx_data.chunk_id, &("00db"), 4);

    idx_data.flag = 0;
    idx_data.chunk_offset = med_avi_p->total_av_data_written + med_avi_p->av_data_offset;
    idx_data.chunk_lenght = len;

    idx_buf_p = med_avi_p->idx_buf_p[med_avi_p->act_idx_buf_id];
    idx_buf_p += med_avi_p->idx_written[med_avi_p->act_idx_buf_id];

    memcpy(idx_buf_p, &idx_data, sizeof(med_avi_index_struct));

    med_avi_p->idx_written[med_avi_p->act_idx_buf_id] += sizeof(med_avi_index_struct);

    /* calc next start pos */
    med_avi_p->data_written[med_avi_p->act_data_buf_id] += len + 8;     /* data witten in this act buf */
    med_avi_p->total_av_data_written += len + 8;    /* data written from data chunk start, no include movi tag */

    med_avi_p->vid_frame_count++;

    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
    kal_give_mutex(med_avi_p->avi_mutex);    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_write_audio_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_p      [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_write_audio_data(kal_char *data_p, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *data_buf_p;
    kal_char *idx_buf_p;
    kal_uint32 size;
    med_avi_index_struct idx_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_avi_p->avi_mutex);
    
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_write_audio_data()");
    kal_prompt_trace(MOD_MED, "[MED AVI] write: %d)", len);

    /* audio data */
    /* 01wb, size, raw data */
    /* 4     4     ... */

    size = len;

    data_buf_p = med_avi_p->data_buf_p[med_avi_p->act_data_buf_id];
    data_buf_p += med_avi_p->data_written[med_avi_p->act_data_buf_id];
    memcpy(data_buf_p, &("01wb"), 4);
    data_buf_p += 4;
    memcpy(data_buf_p, &size, 4);
    data_buf_p += 4;
    memcpy(data_buf_p, data_p, len);

    /* write idx */
    memcpy(&idx_data.chunk_id, &("01wb"), 4);

    idx_data.flag = 0;
    idx_data.chunk_offset = med_avi_p->total_av_data_written + med_avi_p->av_data_offset;
    idx_data.chunk_lenght = len;

    idx_buf_p = med_avi_p->idx_buf_p[med_avi_p->act_idx_buf_id];
    idx_buf_p += med_avi_p->idx_written[med_avi_p->act_idx_buf_id];

    memcpy(idx_buf_p, &idx_data, sizeof(med_avi_index_struct));

    med_avi_p->idx_written[med_avi_p->act_idx_buf_id] += sizeof(med_avi_index_struct);

    /* calc next start pos */
    med_avi_p->data_written[med_avi_p->act_data_buf_id] += len + 8;     /* data witten in this act buf */
    med_avi_p->total_av_data_written += len + 8;    /* data writen from data chunk start, no include movi tag */

    med_avi_p->aud_len += len;

    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
    kal_give_mutex(med_avi_p->avi_mutex);    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_merge_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename_p      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_merge_result(const kal_wchar *filename_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 attribute;
    kal_uint32 size;
    kal_uint32 written;
    kal_uint32 cluster_size;
    kal_uint32 file_size;
    kal_uint32 riff_size;
    kal_uint32 stuff_size;  /* stuff trash at the end of the cluster for pseudo merge */
    kal_char *data_filename_p;
    kal_char *idx_filename_p;

    med_avi_file_header_struct file_header;
    med_avi_stream_header_struct video_header;
    med_avi_stream_header_struct audio_header;
    med_avi_video_format_header_struct video_format;
    med_avi_audio_format_header_struct audio_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_merge_result()");

    if (med_avi_p->vid_frame_count == 0)
    {
        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_FAIL");
        return MED_RES_FAIL;
    }

    data_filename_p = (kal_char*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * ENCODE_BYTE);
    ASSERT(data_filename_p != 0);

    idx_filename_p = (kal_char*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * ENCODE_BYTE);
    ASSERT(idx_filename_p != 0);

    /* data file name */
    kal_mem_cpy(data_filename_p, filename_p, MAX_FILE_NAME_LEN * ENCODE_BYTE);
    med_remove_file_name((kal_wchar*) data_filename_p);
    kal_wstrcat((kal_wchar*) data_filename_p, MED_AVI_VISUAL_FILE);

    /* idx file name */
    kal_mem_cpy(idx_filename_p, filename_p, MAX_FILE_NAME_LEN * ENCODE_BYTE);
    med_remove_file_name((kal_wchar*) idx_filename_p);
    kal_wstrcat((kal_wchar*) idx_filename_p, MED_AVI_IDX_FILE);

    med_avi_p->data_h = FS_Open((kal_wchar*) data_filename_p, FS_READ_WRITE);

    if (med_avi_p->data_h <= 0)
    {
        med_free_ext_mem((void **)&data_filename_p);
        med_free_ext_mem((void **)&idx_filename_p);

        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OPEN_FILE_FAIL");
        return MED_RES_OPEN_FILE_FAIL;
    }

    med_avi_p->idx_h = FS_Open((kal_wchar*) idx_filename_p, FS_READ_WRITE);

    if (med_avi_p->idx_h <= 0)
    {
        FS_Close(med_avi_p->data_h);
        med_free_ext_mem((void **)&data_filename_p);
        med_free_ext_mem((void **)&idx_filename_p);

        kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OPEN_FILE_FAIL");
        return MED_RES_OPEN_FILE_FAIL;
    }

    /*
     * [AVI File Format] for MJPEG
     * 
     * = Data File ========================
     * RIFF.4.AVI .
     *     LIST.4.hdlr.avih.4.(file header)
     *     LIST.4.strl.strh.4.(video header)
     *                .strf.4.(video format)
     *     LIST.4.strl.strh.4.(audio header)
     *                .strf.4.(audio format)
     *     JUNK.4.(junk)
     *     LIST.4.movi.xxdb.4.(video data)
     *                 xxdc.4.(video data) 
     *                 xxwb.4.(audio data)  
     * = Idx File =========================     
     *            idx1.4.(list data)
     * ====================================
     */

    /* fill to fit cluster size */
    cluster_size = FS_GetClusterSize((kal_uint32) filename_p[0]);
    FS_GetFileSize(med_avi_p->data_h, &file_size);

    stuff_size = cluster_size - file_size % cluster_size;
    if (stuff_size)
    {
        /* seek to end and exten */
        FS_Seek(med_avi_p->data_h, 0, FS_FILE_END);
        FS_Extend(med_avi_p->data_h, stuff_size);
    }

    /* data size + idx size */
    riff_size = file_size + stuff_size;
    FS_GetFileSize(med_avi_p->idx_h, &file_size);
    riff_size += file_size;

    /* seek to begin */
    FS_Seek(med_avi_p->data_h, 0, FS_FILE_BEGIN);

    /* RIFF.4.AVI . */
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_RIFF, 4, &written);
    FS_Write(med_avi_p->data_h, &riff_size, 4, &written);
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_AVI, 4, &written);

    /* LIST.4.hdlr.avih.4.(file header) */
    file_header.micro_sec_per_frame = med_avi_p->rec_data.vid_scale * 1000000 / med_avi_p->rec_data.vid_rate;
    file_header.max_byte_per_sec = 0;
    file_header.padding_factor = 0;
    file_header.flag = 272; /* ? */
    file_header.total_frame = med_avi_p->vid_frame_count;
    file_header.init_frames = 0;
    file_header.num_of_stream = 2;
    file_header.suggest_buf_size = 0;
    file_header.width = med_avi_p->rec_data.vid_width;
    file_header.height = med_avi_p->rec_data.vid_height;
    file_header.reserve[0] = 0;
    file_header.reserve[1] = 0;
    file_header.reserve[2] = 0;
    file_header.reserve[3] = 0;

    /*
     *             hdlr.avih.4.(file header)
     *     LIST.4.strl.strh.4.(video header)
     *                .strf.4.(video format)
     *     LIST.4.strl.strh.4.(audio header)
     *                .strf.4.(audio format)
     */

    /* med_avi_file_header_struct = 56 */
    /* med_avi_stream_header_struct = 52 */
    /* med_avi_video_format_header_struct = 40 */
    /* med_avi_audio_format_header_struct = 20 */
    /* 68+ 56 + 104 + 40 + 20 = 288 */
    size = 4 + 4 + 4 + sizeof(med_avi_file_header_struct) +
        4 + 4 + 4 + 4 + 4 + sizeof(med_avi_stream_header_struct) +
        4 + 4 + sizeof(med_avi_video_format_header_struct) +
        4 + 4 + 4 + 4 + 4 + sizeof(med_avi_stream_header_struct) + 4 + 4 + sizeof(med_avi_audio_format_header_struct);

    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_LIST, 4, &written);
    FS_Write(med_avi_p->data_h, &size, 4, &written);
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_HEADER_LIST, 4, &written);
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_AVI_HEADER, 4, &written);
    size = sizeof(med_avi_file_header_struct);
    FS_Write(med_avi_p->data_h, &size, 4, &written);
    FS_Write(med_avi_p->data_h, &file_header, sizeof(med_avi_file_header_struct), &written);

    /* LIST.4.strl.strh.4.(video header)
       .strf.4.(video format) */
    strncpy((char*)&video_header.fcc_type, (char*)&MED_AVI_TAG_STREAM_TYPE_VID, 4);
    strncpy((char*)&video_header.fcc_hdlr, (char*)&MED_AVI_TAG_MJPG, 4);
    video_header.flag = 0;
    video_header.priority = 0;
    video_header.language = 0;
    video_header.init_frames = 0;
    video_header.scale = med_avi_p->rec_data.vid_scale;
    video_header.rate = med_avi_p->rec_data.vid_rate;
    video_header.start = 0;
    video_header.length = med_avi_p->vid_frame_count;
    video_header.suggest_buf_size = 0;
    video_header.quality = -1;  /* default */
    video_header.sample_size = 0;
    video_header.rect_left = 0;
    video_header.rect_top = 0;
    video_header.rect_right = 0;
    video_header.rect_bottom = 0;

    video_format.size = 40;                 /* this header size */
    video_format.width = med_avi_p->rec_data.vid_width;
    video_format.height = med_avi_p->rec_data.vid_height;
    video_format.planes = 1;
    video_format.bit_count = 24;
    video_format.compression = 1196444237;  /* ? */
    video_format.size_image = med_avi_p->rec_data.vid_width * med_avi_p->rec_data.vid_height * 3;       /* image buffer size */
    video_format.x_pels_per_meter = 0;
    video_format.y_pels_per_meter = 0;
    video_format.color_used = 0;
    video_format.color_important = 0;

    /*
     *     strl.strh.4.(video header)
     *         .strf.4.(video format)
     */
    /* med_avi_stream_header_struct = 52 */
    /* med_avi_video_format_header_struct = 40 */
    /* 20 + 52 + 40 = 112 */

    size = 4 + 4 + 4 + sizeof(med_avi_stream_header_struct) + 4 + 4 + sizeof(med_avi_video_format_header_struct);
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_LIST, 4, &written);
    FS_Write(med_avi_p->data_h, &size, 4, &written);
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_STREAM_LIST, 4, &written);
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_STREAM_HEADER, 4, &written);
    size = sizeof(med_avi_stream_header_struct);
    FS_Write(med_avi_p->data_h, &size, 4, &written);
    FS_Write(med_avi_p->data_h, &video_header, sizeof(med_avi_stream_header_struct), &written);
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_STREAM_FORMAT, 4, &written);
    size = sizeof(med_avi_video_format_header_struct);
    FS_Write(med_avi_p->data_h, &size, 4, &written);
    FS_Write(med_avi_p->data_h, &video_format, sizeof(med_avi_video_format_header_struct), &written);

    /* LIST.4.strl.strh.4.(audio header)
       .strf.4.(audio format) */
    strncpy((char*)&audio_header.fcc_type, (char*)&MED_AVI_TAG_STREAM_TYPE_AUD, 4);
    audio_header.fcc_hdlr = 0;
    audio_header.flag = 0;
    audio_header.priority = 0;
    audio_header.language = 0;
    audio_header.init_frames = 0;
    audio_header.scale = 1;
    audio_header.rate = med_avi_p->rec_data.aud_sample_rate;
    audio_header.start = 0;
    audio_header.length = med_avi_p->aud_len;
    audio_header.suggest_buf_size = 0;
    audio_header.quality = -1;
    audio_header.sample_size = 2;
    audio_header.rect_left = 0;
    audio_header.rect_top = 0;
    audio_header.rect_right = 0;
    audio_header.rect_bottom = 0;

    audio_format.format = MED_AVI_AUD_FORMAT_WAV_PCM;
    audio_format.channels = med_avi_p->rec_data.aud_channel;
    audio_format.sample_per_sec = med_avi_p->rec_data.aud_sample_rate;
    audio_format.avg_byte_per_sec = med_avi_p->rec_data.aud_sample_rate * med_avi_p->rec_data.aud_bit_per_sample / 8;
    audio_format.block_align = 2;
    audio_format.bit_per_sample = med_avi_p->rec_data.aud_bit_per_sample;
    audio_format.size = 21834;  /* ingorne in PCM format ? */

    /*
     *     strl.strh.4.(audio header)
     *         .strf.4.(audio format)
     */
    /* med_avi_stream_header_struct = 52 */
    /* med_avi_audio_format_header_struct = 20 */
    /* 20 + 52 + 20 = 92 */

    size = 4 + 4 + 4 + sizeof(med_avi_stream_header_struct) + 4 + 4 + sizeof(med_avi_audio_format_header_struct);

    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_LIST, 4, &written);
    FS_Write(med_avi_p->data_h, &size, 4, &written);
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_STREAM_LIST, 4, &written); /* strl */
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_STREAM_HEADER, 4, &written);       /* strh */
    size = sizeof(med_avi_stream_header_struct);
    FS_Write(med_avi_p->data_h, &size, 4, &written);    /* size */
    FS_Write(med_avi_p->data_h, &audio_header, sizeof(med_avi_stream_header_struct), &written); /* audio stream header */
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_STREAM_FORMAT, 4, &written);       /* strf */
    size = sizeof(med_avi_audio_format_header_struct);
    FS_Write(med_avi_p->data_h, &size, 4, &written);    /* size */
    FS_Write(med_avi_p->data_h, &audio_format, sizeof(med_avi_audio_format_header_struct), &written);   /* audio format */

    /* LIST.4.movi. */
    size = 4 + med_avi_p->total_av_data_written + stuff_size;
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_LIST, 4, &written);
    FS_Write(med_avi_p->data_h, &size, 4, &written);
    FS_Write(med_avi_p->data_h, &MED_AVI_TAG_MOVI, 4, &written);

    /* add idx1.4 */
    FS_Seek(med_avi_p->idx_h, 0, FS_FILE_BEGIN);
    FS_GetFileSize(med_avi_p->idx_h, &file_size);
    FS_Write(med_avi_p->idx_h, &MED_AVI_TAG_IDX1, 4, &written);
    file_size -= 8;
    FS_Write(med_avi_p->idx_h, &file_size, 4, &written);

    /* close file first to merge */
    FS_Close(med_avi_p->data_h);
    FS_Close(med_avi_p->idx_h);

    /* merge data and idx file into AVI file */
    FS_PseudoMerge((kal_wchar*) data_filename_p, (kal_wchar*) idx_filename_p);
    FS_Rename((kal_wchar*) data_filename_p, (kal_wchar*) filename_p);

    attribute = FS_GetAttributes((kal_wchar*) filename_p);
    attribute &= (~FS_ATTR_HIDDEN);

    FS_SetAttributes((kal_wchar*) filename_p, attribute);

    FS_Close(med_avi_p->data_h);
    FS_Close(med_avi_p->idx_h);

    med_free_ext_mem((void **)&data_filename_p);
    med_free_ext_mem((void **)&idx_filename_p);

    kal_prompt_trace(MOD_MED, "[MED AVI] ret: MED_RES_OK");
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_get_cur_file_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_get_cur_file_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 file_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_get_cur_file_size()");

    file_size = med_avi_p->data_file_size + med_avi_p->idx_file_size;
    
    kal_prompt_trace(MOD_MED, "[MED AVI] file size: %d", file_size);
    
    return file_size;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_get_cur_record_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_avi_get_cur_record_time(kal_uint64 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED, "[MED AVI] med_avi_get_cur_record_time()");

    /* in ms */
    *time = ((kal_uint64)med_avi_p->vid_frame_count)*((kal_uint64)med_avi_p->ms_per_frame);

    kal_prompt_trace(MOD_MED, "[MED AVI] record time: %d", *time);

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_is_reach_record_limit
 * DESCRIPTION
 *  reach record limit or not, this will be restricted 
 *  by the playback's index buffer
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_avi_is_reach_record_limit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (med_avi_p->time_limit <= (med_avi_p->vid_frame_count*med_avi_p->ms_per_frame))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_has_unsaved_file
 * DESCRIPTION
 *  check if has unsaved file or not
 * PARAMETERS
 *  filepath_p      [IN]        file path
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool med_avi_has_unsaved_file(const kal_wchar *filepath_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fs_ret;
    kal_wchar filename[MAX_FILE_NAME_LEN];
    kal_bool has_data_file = KAL_FALSE;
    kal_bool has_idx_file = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrcpy(filename, filepath_p);
    kal_wstrcat(filename, MED_AVI_VISUAL_FILE);

    fs_ret = FS_CheckFile(filename);

    if (fs_ret == FS_NO_ERROR)
    {
       has_data_file = KAL_TRUE;
    }

    kal_wstrcpy(filename, filepath_p);
    kal_wstrcat(filename, MED_AVI_IDX_FILE);

    fs_ret = FS_CheckFile(filename);
    
    if (fs_ret == FS_NO_ERROR)
    {
       has_idx_file = KAL_TRUE;
    }

    if (has_data_file && has_idx_file)
    {
        return KAL_TRUE;
    }
    else
    {
        med_avi_clean_tmp_files(filepath_p);
        return KAL_FALSE;
    }
    
}



/*****************************************************************************
 * FUNCTION
 *  med_avi_clean_tmp_files
 * DESCRIPTION
 *  clean temp files
 * PARAMETERS
 *  filepath_p      [IN]        file path
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool med_avi_clean_tmp_files(const kal_wchar *filepath_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[MAX_FILE_NAME_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrcpy(filename, filepath_p);
    kal_wstrcat(filename, MED_AVI_VISUAL_FILE);
    FS_Delete(filename);

    kal_wstrcpy(filename, filepath_p);
    kal_wstrcat(filename, MED_AVI_IDX_FILE);
    FS_Delete(filename);
    
    return KAL_TRUE;
}




/*****************************************************************************
 * FUNCTION
 *  med_avi_get_data_buf_size
 * DESCRIPTION
 *  get data buffer size
 * PARAMETERS
 *  void
 * RETURNS
 *  data buffer size
 *****************************************************************************/
kal_int32 med_avi_get_data_buf_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MED_AVI_WRITE_DATA_BUF_SIZE * 2);    
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_get_idx_buf_size
 * DESCRIPTION
 *  get idx buffer size
 * PARAMETERS
 *  void
 * RETURNS
 *  data buffer size
 *****************************************************************************/
kal_int32 med_avi_get_idx_buf_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MED_AVI_WRITE_IDX_BUF_SIZE * 2);
}


/*****************************************************************************
 * FUNCTION
 *  med_avi_update_fps
 * DESCRIPTION
 *  update fps (rate/scale = fps)
 * PARAMETERS
 *  rate        [IN]        rate
 *  scale       [IN]        scale
 * RETURNS
 *  data buffer size
 *****************************************************************************/
kal_int32 med_avi_update_fps(kal_uint32 rate, kal_uint32 scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_avi_p->rec_data.vid_rate = rate;
    med_avi_p->rec_data.vid_scale = scale;

    med_avi_p->ms_per_frame 
        = ((kal_uint64)med_avi_p->rec_data.vid_scale) * \
          ((kal_uint64)1000) / \
          ((kal_uint64)med_avi_p->rec_data.vid_rate);
    
    
    return MED_RES_OK;
}

