/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *  mdi_swflash.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SW Flash interfce header file
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

#ifndef _MDI_SWFLASH_H
#define _MDI_SWFLASH_H

#ifndef _MDI_DATATYPE_H_
#error "Please include mdi_datatype.h before mdi_swflash.h"
#endif 

#include "TouchScreenGprot.h" 
#ifdef SWFLASH_CHAOTEX
#include "med_api.h"
#include "cimlib.h"
#include "cimdepends.h"
#include "l1audio.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define MMI_SWFLASH_MAX_STR_LEN 80

#define MMI_SWFLASH_MAX_FILE_DATA_BUFFER_SIZE (100*1024)
#define MMI_SWFLASH_MEM_BUFFER_SIZE (600*1024)  /* add the memory that cimsendsms need +text layer+store first frame */
#define MMI_SWFLASH_PERFORMANCE 200

typedef enum
{
    MDI_SWFLASH_DL_STATE_IDLE,
    MDI_SWFLASH_DL_STATE_CONNTECTING,
    MDI_SWFLASH_DL_STATE_CONNECTED
} mdi_swflash_dl_state_enum;

typedef enum
{
    MDI_SWFLASH_SOC_NOTIFY_DL_COMPLETE,
    MDI_SWFLASH_SOC_NOTIFY_DL_STATUS,
    MDI_SWFLASH_SOC_NOTIFY_FILE_ERROR,
    MDI_SWFLASH_SOC_NOTIFY_NETWORK_ERROR,
    MDI_SWFLASH_SOC_NOTIFY_DISK_FULL,
    MDI_SWFLASH_SOC_NOTIFY_DISK_WRITE_PROTECT,
    MDI_SWFLASH_SOC_NOTIFY_SOCKET_ERROR,
    MDI_SWFLASH_SOC_NOTIFY_SERVER_ERROR,
    MDI_SWFLASH_SOC_NOTIFY_HTTP_FAILED,
    MDI_SWFLASH_SOC_NOTIFY_UNKNOWN
} mdi_swflash_soc_notify_enum;

typedef enum
{
    MDI_SWFLASH_PL_STATE_NULL,
    MDI_SWFLASH_PL_STATE_READY,
    MDI_SWFLASH_PL_STATE_PLAY,
    MDI_SWFLASH_PL_STATE_PAUSE
} mdi_swflash_pl_state_enum;

typedef void (*mdi_swflash_dl_result_callback) (MDI_RESULT);
typedef void (*mdi_swflash_dl_progress_callback) (S32 dl_size, S32 total_size);

typedef struct
{
    /* adaptation to socket */
    S8 soc_id;                              /*socket id*/
    mdi_swflash_dl_state_enum dl_state;     /*download state*/
    S8 *savename_buf_p;                     /*save name of download file*/
    mdi_swflash_dl_result_callback dl_result_callback;
    mdi_swflash_dl_progress_callback dl_progress_callback;
    HSE session_handle;                     /* session handle*/
    S32 seq_num;                            /*sequence number*/
    HCIMFILE dl_file_handle;                /*download object handle*/
  
    /* swflash AP */
    gdi_handle swflash_layer_handle;         
    S16 layer_width;
    S16 layer_height;
    
    FS_HANDLE fd;                           /*mtk file handle*/
    HCIM cim_handle;                        /*cim handle*/
    HCIMFILE file_handle;                   /*chaotex file handle*/
    U8 *cim_buffer;                         /*the aim buffer of decoded data*/
    U32 playmode;                           /*play mode*/
    U8 state;                               /*play state*/
    U8 bpp;                                 /*byte per pixel*/
    S32 error;                              /*error info from cim engine*/

    /* Interaction */
    S8 is_audio_on;
    S8 is_vibrate_on;
    S8 is_interact_on;

    /* indicate if enter from swflash player */
    U8 fromplayer;
} mdi_swflash_context_struct;

typedef struct
{
    S8 title[MAX_SWFLASH_STR_LEN];
    S8 filename[MAX_SWFLASH_STR_LEN];
    S8 author[MAX_SWFLASH_STR_LEN];
    S8 company[MAX_SWFLASH_STR_LEN];
    S8 date[MAX_SWFLASH_STR_LEN];
    S8 time[MAX_SWFLASH_STR_LEN];
    S8 preinstall[MAX_SWFLASH_STR_LEN];

    S32 curlen;
    S32 size;
    S32 category;

    S16 width;
    S16 height;

    S32 bk_color;
} mdi_swflash_info_struct;                  /*swflash works info*/

HCIM mdi_swflash_get_cimhandle(void);
extern MDI_RESULT mdi_swflash_start_download_file(
                    S8 *descriptor_filename,
                   S8 *save_filename,
                    S32 nwk_accound_id,
                   mdi_swflash_dl_result_callback result_callback,
                   mdi_swflash_dl_progress_callback progress_callback);

#endif

#ifdef SWFLASH_NEOMTEL


#include "sscStringhandle.h"
#include "Fat_fs.h"
#include "filemgr.h"
/***************************************************************************** 
* Define
*****************************************************************************/

#define MMI_SWFLASH_MAX_STR_LEN (FMGR_MAX_FILE_LEN + 1) *ENCODING_LENGTH
#define MMI_SWFLASH_MAX_FILE_DATA_BUFFER_SIZE (301*1024)
#define MMI_SWFLASH_MEM_BUFFER_SIZE (600*1024)
#define MMI_SWFLASH_PERFORMANCE 300
#define VIS_PLAYER 0x01
#define VIS_SCREEN 0x20
typedef void (*play_result_callback) (MDI_RESULT);
typedef void (*mdi_swflash_perdraw)(S32 offset_x, S32 offset_y, S32 width, S32 height) ;
typedef void (*mdi_swflash_postdraw)(void);

typedef enum
{
    MDI_SWFLASH_PL_STATE_NULL,
    MDI_SWFLASH_PL_STATE_READY,
    MDI_SWFLASH_PL_STATE_PLAY,
    MDI_SWFLASH_PL_STATE_PAUSE
} mdi_swflash_pl_state_enum;

typedef enum
{
    MDI_SWFLASH_PL_RES_END_OF_FILE,
    MDI_SWFLASH_PL_RES_DRM_END,
    MDI_SWFLASH_PL_RES_LOOP
} mdi_swflash_pl_res_enum;

typedef struct
{
    /* swflash AP */
    gdi_handle swflash_layer_handle;         
    S32 layer_width;
    S32 layer_height;
    S32 layer_offsetx;
    S32 layer_offsety;
    
    FS_HANDLE fd;                           /*mtk file handle*/
    void * instance;                        /*engine instance,it means handle*/
    U8 *decipher_buffer;                    /*point to the decipher data*/
    U8 *decode_buffer;                      /*the aim buffer of decoded data*/
    U8 *back_buffer;                        /*the backup buffer mem*/
    U32 playmode;                           /*play mode*/
    mdi_swflash_pl_state_enum state;                               /*play state*/
    
    kal_uint8 *mem_ptr;
    U32 size;
    S32 error;                              /*error info from engine*/

    MMI_BOOL is_loop;                       /*indicate if need play looply*/
    MMI_BOOL is_fromplayer;                          /* indicate if enter from swflash player */
    MMI_BOOL is_first_frame;                /*indicate if need just play first frame*/
    MMI_BOOL is_ready_update;               /*indicate if decode ready*/
   
    S8 imei[(MAX_IMEI_LEN + 1) * ENCODING_LENGTH];
    play_result_callback play_result;
    mdi_swflash_perdraw  pre_blt;
    mdi_swflash_postdraw post_blt;
} mdi_swflash_context_struct;

typedef struct
{
    S8 title[MMI_SWFLASH_MAX_STR_LEN];
    S8 company[MMI_SWFLASH_MAX_STR_LEN];
    S8 date[MMI_SWFLASH_MAX_STR_LEN];
    S8 time[MMI_SWFLASH_MAX_STR_LEN];

    S32 curlen;
    S32 size;
    U16 type;
    S16 width;
    S16 height;
} mdi_swflash_info_struct;                  /*swflash works info*/
#endif


extern MDI_RESULT mdi_swflash_write_file(UI_character_type *file_name, char *pData, int nSize);
extern MDI_RESULT mdi_swflash_open_file(const S8 *filename, U32 playmode, mdi_swflash_info_struct *info);
extern MDI_RESULT mdi_swflash_close_file(void);
extern MDI_RESULT mdi_swflash_open_id(U16 id, U32 playmode, mdi_swflash_info_struct *info);
extern MDI_RESULT mdi_swflash_close_id(void);

extern MDI_RESULT mdi_swflash_play(gdi_handle layer_handle,
                                   U16 repeat_count, U8 audio_path, void (*play_result_callback) (MDI_RESULT));

extern MDI_RESULT mdi_swflash_stop(void);
extern MDI_RESULT mdi_swflash_pause(void);
extern MDI_RESULT mdi_swflash_resume(void);

extern MDI_RESULT mdi_swflash_enable_audio(void);
extern MDI_RESULT mdi_swflash_disable_audio(void);

extern MDI_RESULT mdi_swflash_enable_vibrate(void);
extern MDI_RESULT mdi_swflash_disable_vibrate(void);

extern MDI_RESULT mdi_swflash_enable_interaction(void);
extern MDI_RESULT mdi_swflash_disable_interaction(void);

/* download from a swflash file */
/* start and stop must be paired */
extern MDI_RESULT mdi_swflash_check_download_file(
                    U16 *descriptor_filename,
                    U32 *total_len,
                    U32 *current_len,
                    U32 *category);


extern MDI_RESULT mdi_swflash_stop_download_file(void);
extern MDI_RESULT mdi_swflash_update_frame(void);
extern MDI_RESULT mdi_swflash_key_down_event(kal_uint16 key);
extern MDI_RESULT mdi_swflash_key_up_event(kal_uint16 key);

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL  mdi_swflash_pen_down_event(mmi_pen_point_struct pos);
extern MMI_BOOL mdi_swflash_pen_up_event(mmi_pen_point_struct pos);
extern MMI_BOOL mdi_swflash_pen_move_event(mmi_pen_point_struct pos);
#endif

void mdi_swflash_init(void);
void mdi_swflash_set_imei(S8 *imei);
void mdi_swflash_on_end(void);
void mdi_swflash_set_is_from_player(MMI_BOOL from_player);
MDI_RESULT mdi_swflash_transform_info(S8 *str);
void mdi_swflash_register_blt_callback(
        void (*per_blt_callback)(S32 offset_x, S32 offset_y, S32 width, S32 height), 
        void (*post_blt_callback)(void));

#endif /* _MDI_SWFLASH_H */ 

