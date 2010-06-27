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
 *  BarcodeReader.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  QR Code Reader Applications v0.1
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef MMI_BARCODEREADER_DATATPYE_H
#define MMI_BARCODEREADER_DTATTYPE_H

#include "mmi_features.h"

#ifdef __MMI_BARCODEREADER__

#include "resource_barcodereader_skins.h"      /* UI custom config */

/****************************************************************************
* MACRO
*****************************************************************************/
#define MMI_BARCODEREADER_MAX_NUM_URL_PATTERN   3
#define MMI_BARCODEREADER_MAX_NUM_VALID_HTTP_PREFIX   6
#define MMI_BARCODEREADER_MAX_LEN_URL_PATTERN   15
#define MMI_BARCODEREADER_MAX_USE_NUMBERS               6
#define MMI_BARCODEREADER_USE_NUM_MIN_LENGTH            2
#define MMI_BARCODEREADER_MAX_URL_LEN    (256)
#define MMI_BARCODEREADER_MAX_DIGITS               40 /* Maximum number of digits in phone number */
#define MMI_BARCODEREADER_MAX_MMS_CONTENT     612
#define MMI_BARCODEREADER_MAX_MMS_SUBJECT     40
#define MMI_BARCODEREADER_MAX_SMS_CONTENT     670
#define MMI_BARCODEREADER_TO_LOWER(ch) ( (((ch)>='A') && ((ch)<='Z'))?('a'+((ch)-'A')) :((ch))  )

typedef enum
{
    PARSER_STATE_UNKNOWN,
    PARSER_STATE_URL1,
    PARSER_STATE_URL2,
    PARSER_STATE_PHONENUMBER,
    PARSER_STATE_COMMON,
    PARSER_STATE_TOTAL_COUNT
} mmi_parser_state_enum;

#define MMI_BARCODEREADER_ENTER_STATE(_STATE_)      do{                                           \
                                                   MMI_BARCODEREADER_TRACE_EXIT_STATE();             \
                                                   g_barcodereader_cntx.app_next_state = _STATE_;\
                                                   mmi_barcodereader_exit_current_state();       \
                                                   MMI_BARCODEREADER_TRACE_ENTER_STATE();            \
                                                   mmi_barcodereader_enter_state(_STATE_);       \
                                                }while(0)

#define  MMI_BARCODEREADER_TRACE_EXIT_STATE()    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[barcodereader.c] exit from state: %d---*\n",g_barcodereader_cntx.app_state)
#define  MMI_BARCODEREADER_TRACE_ENTER_STATE()   PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[barcodereader.c] entry to state: %d---*\n",g_barcodereader_cntx.app_next_state)

typedef enum
{
    MMI_BARCODEREADER_SETTING_FOCUS_MODE_AUTO,

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
    MMI_BARCODEREADER_SETTING_FOCUS_MODE_MACRO,
#endif 

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
    MMI_BARCODEREADER_SETTING_FOCUS_MODE_MANUAL,
#endif 

    MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT
} barcodereader_setting_focus_mode_enum;

/********************************************************************************************************************** 
* EV
**********************************************************************************************************************/
typedef enum
{

#ifdef __MMI_BARCODEREADER_EV_4__
    MMI_BARCODEREADER_SETTING_EV_N4,
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__

    MMI_BARCODEREADER_SETTING_EV_N3,
#endif /* __MMI_BARCODEREADER_EV_3__ */ 

#ifdef __MMI_BARCODEREADER_EV_2__
    MMI_BARCODEREADER_SETTING_EV_N2,
#endif 

    MMI_BARCODEREADER_SETTING_EV_N1,
    MMI_BARCODEREADER_SETTING_EV_0,
    MMI_BARCODEREADER_SETTING_EV_P1,

#ifdef __MMI_BARCODEREADER_EV_2__
    MMI_BARCODEREADER_SETTING_EV_P2,
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    MMI_BARCODEREADER_SETTING_EV_P3,
#endif 

#ifdef __MMI_BARCODEREADER_EV_4__
    MMI_BARCODEREADER_SETTING_EV_P4,
#endif 
    MMI_BARCODEREADER_SETTING_EV_COUNT
} barcodereader_setting_ev_enum;

/********************************************************************************************************************** 
* Flash
**********************************************************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_SETTING_FLASH_OFF,
    MMI_BARCODEREADER_SETTING_FLASH_ON,
    MMI_BARCODEREADER_SETTING_FLASH_COUNT
} barcodereader_setting_flash_enum;

/********************************************************************************************************************** 
* Storage
**********************************************************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_SETTING_STORAGE_PHONE,
    MMI_BARCODEREADER_SETTING_STORAGE_MEMORY_CARD,
    MMI_BARCODEREADER_SETTING_STORAGE_COUNT
} barcodereader_setting_storage_enum;

/********************************************************************************************************************** 
* Banding
**********************************************************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_SETTING_BANDING_50HZ = 0,
    MMI_BARCODEREADER_SETTING_BANDING_60HZ,
    MMI_BARCODEREADER_SETTING_BANDING_COUNT
} barcodereader_setting_banding_enum;

typedef enum
{
    MMI_BARCODEREADER_TOUCH_RSK,
    MMI_BARCODEREADER_TOUCH_LSK,
    MMI_BARCODEREADER_TOUCH_FLASH,
    MMI_BARCODEREADER_TOUCH_STORAGE,
    MMI_BARCODEREADER_TOUCH_EV_INC,
    MMI_BARCODEREADER_TOUCH_EV_DEC,
    MMI_BARCODEREADER_TOUCH_CAPTURE,
    MMI_BARCODEREADER_TOUCH_FOCUS_MODE,
    MMI_BARCODEREADER_TOUCH_MF_INC,
    MMI_BARCODEREADER_TOUCH_MF_DEC,

    MMI_BARCODEREADER_TOUCH_NONE
} barcodereader_touch_obj_enum;

/********************************************************************************************************************** 
* Define
**********************************************************************************************************************/
#define MMI_BARCODEREADER_APPLIACTION_LIST_NUM   (20)
#define MMI_BARCODEREADER_STORAGE_FILEPATH_PHONE          FMGR_DEFAULT_FOLDER_BARCODE
#define MMI_BARCODEREADER_STORAGE_FILEPATH_MEMORY_CARD    FMGR_DEFAULT_FOLDER_BARCODE

/********************************************************************************************************************** 
* display rotate
**********************************************************************************************************************/
#define MMI_BARCODEREADER_OSD_ROTATE_0        MDI_CAMERA_PREVIEW_ROTATE_0
#define MMI_BARCODEREADER_OSD_ROTATE_90       MDI_CAMERA_PREVIEW_ROTATE_90
#define MMI_BARCODEREADER_OSD_ROTATE_180         MDI_CAMERA_PREVIEW_ROTATE_180
#define MMI_BARCODEREADER_OSD_ROTATE_270         MDI_CAMERA_PREVIEW_ROTATE_270
#define MMI_BARCODEREADER_OSD_ROTATE_RESET       255

#define MMI_BARCODEREADER_PREVIEW_ROTATE_0                MDI_CAMERA_PREVIEW_ROTATE_0
#define MMI_BARCODEREADER_PREVIEW_ROTATE_90               MDI_CAMERA_PREVIEW_ROTATE_90
#define MMI_BARCODEREADER_PREVIEW_ROTATE_180           MDI_CAMERA_PREVIEW_ROTATE_180
#define MMI_BARCODEREADER_PREVIEW_RORATE_270           MDI_CAMERA_PREVIEW_ROTATE_270
#define MMI_BARCODEREADER_PREVIEW_ROTATE_0_MIRROR      MDI_CAMERA_PREVIEW_ROTATE_0_MIRROR
#define MMI_BARCODEREADER_PREVIEW_ROTATE_90_MIRROR     MDI_CAMERA_PREVIEW_ROTATE_90_MIRROR
#define MMI_BARCODEREADER_PREVIEW_ROTATE_180_MIRROR    MDI_CAMERA_PREVIEW_ROTATE_180_MIRROR
#define MMI_BARCODEREADER_PREVIEW_ROTATE_270_MIRROR    MDI_CAMERA_PREVIEW_ROTATE_270_MIRROR

#define MMI_BARCODEREADER_LCM_ROTATE_0                 MDI_CAMERA_LCM_ROTATE_0
#define MMI_BARCODEREADER_LCM_ROTATE_90                MDI_CAMERA_LCM_ROTATE_90
#define MMI_BARCODEREADER_LCM_ROTATE_180               MDI_CAMERA_LCM_ROTATE_180
#define MMI_BARCODEREADER_LCM_ROTATE_270                  MDI_CAMERA_LCM_ROTATE_270
#define MMI_BARCODEREADER_LCM_ROTATE_0_MIRROR             MDI_CAMERA_LCM_ROTATE_0_MIRROR
#define MMI_BARCODEREADER_LCM_ROTATE_90_MIRROR         MDI_CAMERA_LCM_ROTATE_90_MIRROR
#define MMI_BARCODEREADER_LCM_ROTATE_180_MIRROR        MDI_CAMERA_LCM_ROTATE_180_MIRROR
#define MMI_BARCODEREADER_LCM_ROTATE_270_MIRROR        MDI_CAMERA_LCM_ROTATE_270_MIRROR

#define HINT_POPUP_FADE_TIME           (1200)
#define TOGGLE_POPUP_FADE_TIME         (800)
#define DONE_POPUP_FADE_TIME           (1000)

typedef enum
{
    MMI_BARCODEREADER_ERROR_NO_ERROR = 0,
    MMI_BARCODEREADER_ERROR_ENCODING_ERROR,
    MMI_BARCODEREADER_ERROR_COMMON,
    MMI_BARCODEREADER_ERROR_TOO_LONG_NUMBER,
    MMI_BARCODEREADER_ERROR_DECODE_FAILED,
    MMI_BARCODEREADER_ERROR_NO_STORAGE,
    MMI_BARCODEREADER_ERROR_ALL
}mmi_barcodereader_error_result_enum;

#define MMI_BARCODEREADER_ERR_COMMON            (-1)
#define MMI_BARCODEREADER_ERR_PHONE_DISK_FULL (-2)
#define MMI_BARCODEREADER_ERR_CARD_DISK_FULL  (-3)
#define MMI_BARCODEREADER_ERR_WRITE_PROTECT      (-4)
#define MMI_BARCODEREADER_ERR_ROOT_DIR_FULL      (-5)

#define MMI_BARCODEREADER_DEFAULT_SETTING_ZOOM_IDX (10)

#ifdef __MMI_BARCODEREADER_OPERATOR1__
#define MMI_BARCODEREADER_HELP_CONTENT_PHASE_COUNT (STR_ID_BARCODEREADER_HELP_END - STR_ID_BARCODEREADER_HELP_START - 1)
#define MMI_BARCODEREADER_SP_ID                             (0x01)
#define MMI_BARCODEREADER_CONTENT_MAX_COUNT                 (10)
#define MMI_BARCODEREADER_ATTRIBUTE_CONTENT_SEPERATOR       ','   
#define MMI_BARCODEREADER_ATTRRBUTE_NAME_SEPERATOR          ':'
#define MMI_BARCODEREADER_ATTRABUTE_SEPERATOR               ';'
#define MMI_BARCODEREADER_ATTRIBUTE_CONTENT_MAX             (7+4*MMI_BARCODEREADER_CONTENT_MAX_COUNT)
#define MMI_BARCODEREADER_PHB_MULTI_CONTENT_MAX_COUNT       (4)
#define __MMI_BARCODEREADER_GEN_TYPE_FILE__
#undef __MMI_BARCODEREADER_GEN_TYPE_FILE__
#define MMI_BARCODEREADER_DECODE_INTERVAL                   (2000)
#endif

#define MMI_BARCODEREADER_FILE_EXT_NAME                     L".mbc"

typedef struct
{
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    BOOL is_press;
} barcodereader_ui_touch_struct;


typedef enum
{
    MMI_BARCODEREADER_EV_STATUS_INC = 0,
    MMI_BARCODEREADER_EV_STATUS_DEC,
    MMI_BARCODEREADER_EV_STATUS_NULL
}mmi_barcodereader_ev_status_enum;

#ifdef __MMI_BARCODEREADER_MF_SUPPORT__
typedef enum
{
    MMI_BARCODEREADER_MF_STATUS_FORWARD = 0,
    MMI_BARCODEREADER_MF_STATUS_BACKWARD,
    MMI_BARCODEREADER_MF_STATUS_NULL
}mmi_barcodereader_mf_status_enum;
#endif

typedef enum
{
    MMI_BARCODEREADER_AF_ANIMATION_STEP1,
    MMI_BARCODEREADER_AF_ANIMATION_STEP2,
    MMI_BARCODEREADER_AF_ANIMATION_STEP3,
    MMI_BARCODEREADER_AF_ANIMATION_END
} barcodereader_af_animtaion_process;

typedef enum
{
    MMI_BARCODEREADER_AF_IDLE = 0,
    MMI_BARCODEREADER_AF_CALCULATE,
    MMI_BARCODEREADER_AF_SUCCEED,
    MMI_BARCODEREADER_AF_FAIL,
    MMI_BARCODEREADER_AF_ONFOCUS
} barcodereader_af_states;

typedef enum
{
    MMI_BARCODEREADER_HELP_NONE = 0,
    MMI_BARCODEREADER_HELP_DECODE_NEXT,
    MMI_BARCODEREADER_HELP_WRONG_SERIES,
    MMI_BARCODEREADER_HELP_DUPLICATED_CODE,
    MMI_BARCODEREADER_HELP_TOTAL_COUNT
} barcodereader_help_screen_enum;

typedef struct
{
    /* camera setting - 8 byte */
    U16 flash;
    U16 ev;
    U16 af_mode;
    U16 storage;
    U16 banding;
    
    /* reserve 20 bytes */
    U16 reserved1;
    U16 reserved2;
    U16 reserved3;
    U16 reserved4;
    U16 reserved5;
    U16 reserved6;
    U16 reserved7;
    U16 reserved8;
    U16 reserved9;
    U16 reserved10;
} barcodereader_setting_struct;

/*used to deal with error*/
typedef enum
{
    MMI_BARCODEREADER_ERROR_TYPE_FROM_FS = 0,   
    MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA,
    MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER,
    MMI_BARCODEREADER_ERROR_TYPE_ALL
}mmi_barcodereader_error_type_enum;

typedef struct  
{
    S32 error_result;
    mmi_barcodereader_error_type_enum  error_type;
}mmi_barcodereader_error_struct;


/*********** Storage ***********/
typedef enum
{
    MMI_BARCODEREADER_STORAGE_PHONE,
    MMI_BARCODEREADER_STORAGE_MEMORY_CARD,
    MMI_BARCODEREADER_STORAGE_TOTAL
} mmi_barcodereader_storage;

typedef enum
{
    MMI_BARCODEREADER_APP_VCARD,
    MMI_BARCODEREADER_APP_EMAIL,
    MMI_BARCODEREADER_APP_SMS,
    MMI_BARCODEREADER_APP_DTXT,
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    MMI_BARCODEREADER_APP_BUSINESS,
    MMI_BARCODEREADER_APP_MMS,
    MMI_BARCODEREADER_APP_PHONENUMBER,
    MMI_BARCODEREADER_APP_URL,
    MMI_BARCODEREADER_APP_EMAILADDRESS,
#else
    MMI_BARCODEREADER_APP_WAPSELL,
    MMI_BARCODEREADER_APP_SMSSELL,
    MMI_BARCODEREADER_APP_IVRSELL,
#endif
    MMI_BARCODEREADER_NONE,
    MMI_BARCODEREADER_APP_TOTAL
} mmi_barcodereader_app_type_enum;

#ifdef __MMI_BARCODEREADER_OPERATOR1__
typedef enum
{
    MMI_BARCODEREADER_MENULIST_PREVIEW = 0,
    MMI_BARCODEREADER_MENULIST_FILELIST,
    MMI_BARCODEREADER_MENULIST_SERVICE_SUMMARY,
    MMI_BARCODEREADER_MENULIST_HELP,
    MMI_BARCODEREADER_MENULIST_SETTING,
    MMI_BARCODEREADER_MENULIST_TOTAL
}MMI_BARCODEREADER_MENULIST_ENUM;
#endif

/********************************************************************************************************************** 
* operator attribute enum
**********************************************************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_ATTRIBUTE_N = 0,  
    MMI_BARCODEREADER_ATTRIBUTE_TIL,	 
    MMI_BARCODEREADER_ATTRIBUTE_DIV, 
    MMI_BARCODEREADER_ATTRIBUTE_COR,	 
    MMI_BARCODEREADER_ATTRIBUTE_ADR,	 
    MMI_BARCODEREADER_ATTRIBUTE_ZIP,	 	 
    MMI_BARCODEREADER_ATTRIBUTE_M,	     
    MMI_BARCODEREADER_ATTRIBUTE_FAX,	 
    MMI_BARCODEREADER_ATTRIBUTE_EM,	     
    MMI_BARCODEREADER_ATTRIBUTE_SM,	     
    MMI_BARCODEREADER_ATTRIBUTE_TO,	      	  
    MMI_BARCODEREADER_ATTRIBUTE_SUB,
    MMI_BARCODEREADER_ATTRIBUTE_TXT,	 
    MMI_BARCODEREADER_ATTRIBUTE_INTR,
    MMI_BARCODEREADER_ATTRIBUTE_CT,
    MMI_BARCODEREADER_ATTRIBUTE_TYPE,
    MMI_BARCODEREADER_ATTRIBUTE_URL,
    MMI_BARCODEREADER_ATTRIBUTE_DG,	 
    MMI_BARCODEREADER_ATTRIBUTE_TEL,
    MMI_BARCODEREADER_ATTRIBUTE_LEN,	 
    MMI_BARCODEREADER_ATTRIBUTE_FILE,	 
    MMI_BARCODEREADER_ATTRIBUTE_CR,
    MMI_BARCODEREADER_ATTRIBUTE_SID,
#ifndef __MMI_BARCODEREADER_OPERATOR1__
    MMI_BARCODEREADER_ATTRIBUTE_NICK,
    MMI_BARCODEREADER_ATTRIBUTE_NOTE,    
#endif
    MMI_BARCODEREADER_ATTRIBUTE_ALL
}mmi_barcodereader_attribute_enum;


typedef enum
{
    MMI_BARCODEREADER_HIGHLIGHT_TYPE_TEL,
    MMI_BARCODEREADER_HIGHLIGHT_TYPE_M,
    MMI_BARCODEREADER_HIGHLIGHT_TYPE_EM,
    MMI_BARCODEREADER_HIGHLIGHT_TYPE_URL,
    MMI_BARCODEREADER_HIGHLIGHT_TYPE_OPEN_URL,
    MMI_BARCODEREADER_HIGHLIGHT_TYPE_SAVE_URL,
    MMI_BARCODEREADER_HIGHLIGHT_TYPE_TO_COMMEND,
    MMI_BARCODEREADER_HIGHLIGHT_TYPE_TO_ORDER,
    MMI_BARCODEREADER_HIGHLIGHT_TYPE_TO_LISTEN,
    MMI_BARCODEREADER_HIGHLIGHT_TYPE_ALL
}mmi_barcodereader_highlight_type_enum;

typedef enum
{
    MMI_BARCODEREADER_FILELIST_OPTION_HIGHLIGHT_OPEN = 0,
    MMI_BARCODEREADER_FILELIST_OPTION_HIGHLIGHT_DELETE_FILE,
    //MMI_BARCODEREADER_FILELIST_OPTION_HIGHLIGHT_DELETE_FILE_ALL,
    MMI_BARCODEREADER_FILELIST_OPTION_HIGHLIGHT_TOTAL
}mmi_barcodereader_filelist_option_highlight_enum;


typedef struct
{
    HILITE_STR content;
    U16 highlight_type;
}mmi_barcodereader_highlight_struct;


typedef struct 
{
    HILITE_STR ct_element[MMI_BARCODEREADER_ATTRIBUTE_ALL];
    U32 ct_attribute;
}mmi_barcodereader_app_content_struct;

typedef struct  
{
    U32 index;
    U32 value;
}mmi_barcodereader_phb_multi_count_struct;
/********************************************************************************************************************** 
* BarcodeReader Context
**********************************************************************************************************************/
typedef struct
{
    gdi_handle base_layer_handle;
    gdi_handle osd_layer_handle;
    gdi_handle preview_layer_handle;        // use the base layer buffer
    gdi_handle sublcd_base_layer_handle;

    mmi_barcodereader_error_struct last_error;

    barcodereader_setting_struct setting;
    barcodereader_osd_layeout_struct *active_barcodereader_osd_ptr;

    U8 lcm_rotate;
    U8 previous_osd_rotate;
    U8 osd_rotate;

    U16 zoom_idx;
    U32 osd_UI_device_width;
    U32 osd_UI_device_height;
    U32 base_UI_device_width;
    U32 base_UI_device_height;

    S16 *storage_filepath;
    PU8 osd_layer_buf_ptr;

    U16 preview_width;
    U16 preview_height;
    U16 image_width;
    U16 image_height;

    U16 zoom_limit;
    U16 app_state;
    U16 app_prev_state;
    U16 app_next_state;
    PU8 capture_buf_ptr;
    U32 capture_size;

    /* this four variables is for append structure qr code */
    BOOL is_append_qrcode;
    U8  nsymbol;
    U8  symbolid;
    U8  symbol_count;
    U8  paritydata;
    U8  encoding;
    U16  symbol_masks;

    BOOL is_lsk_pressed;
    BOOL is_rsk_pressed;
    BOOL is_up_arrow_pressed;
    BOOL is_down_arrow_pressed;

    BOOL is_autofocus_pressed;
    BOOL is_manual_autofocus;
    barcodereader_af_states af_state;
    barcodereader_af_animtaion_process af_animation_process;
    U8 af_result;
    BOOL is_af_capture;
    BOOL is_capturing;
    BOOL is_setting_loaded;
    BOOL is_mainlcd_resource;
    BOOL is_cat65_show;
    BOOL is_hide_osd;
    BOOL is_draw_timer_on;
    BOOL is_sublcd_display;
    BOOL is_storage_ready;   
    BOOL is_storage_path_changed;
    BOOL is_multiple_receiver;
    U32  current_receiver;
    U32  total_receiver;

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
    BOOL is_mf_continue;
    U32 mf_level_idx;
    U32 mf_level_cnt;
#endif /* __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__ */ 

    void *app_mem_pool;
    KAL_ADM_ID adm_pool_id;
    
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    S8 *buffer_from_screen_asm; /*help screen*/
    S32 file_list_option_index;
    S16 file_path[FMGR_MAX_PATH_LEN];
    /*commend*/
    MMI_BOOL is_commend;
#endif

    S8 *hint1_buf;
    S8 *hint2_buf;
    U16 fade_time;

    /* decoded text related variable */
    S8 *text_buf;
    S8 *formatted_text_buf;
    S8 *text_slot[16];
    S8 *decode_text;
    S8 *input_string_tmp;
    S8 *input_string;
    S8 *working_buffer;

    barcodereader_help_screen_enum help_str_enum;

    U16 formatted_text_buf_length;
    U16 text_buf_length;
    mmi_barcodereader_app_content_struct app_content;
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    mmi_barcodereader_highlight_struct  highlight[MMI_BARCODEREADER_ATTRIBUTE_CONTENT_MAX];
    U8 highlight_total_count;
#endif
    U8 current_highlight;
    /*email attribute , save to draft box or not*/
    MMI_BOOL is_save_to_draft;

    /*phonebook needed*/
#ifdef __MMI_BARCODEREADER_OPERATOR1__
    U32 phb_multiple_content_to_select;
    mmi_barcodereader_phb_multi_count_struct phb_selected[MMI_BARCODEREADER_PHB_MULTI_CONTENT_MAX_COUNT];

    /*time interval to stop the the decode*/
    MMI_BOOL b_stop_decode;
#endif

    U16 storage_disk;
    //HILITE_STR ct_element[MMI_BARCODEREADER_ATTRIBUTE_ALL];
    mmi_barcodereader_app_type_enum app_type_list[MMI_BARCODEREADER_APPLIACTION_LIST_NUM];
    U8 app_list_idx;
    U8 app_list_idx_count;
    U8 selected_hilight_idx;
    mmi_barcodereader_app_type_enum selected_app_type;

    void (*entry_app_callback)(void);

    U16 touch_object;
    barcodereader_ui_touch_struct touch_lsk;
    barcodereader_ui_touch_struct touch_rsk;

    barcodereader_ui_touch_struct touch_flash;
    barcodereader_ui_touch_struct touch_mf_inc;
    barcodereader_ui_touch_struct touch_mf_dec;
    barcodereader_ui_touch_struct touch_ev_inc;
    barcodereader_ui_touch_struct touch_ev_dec;
    barcodereader_ui_touch_struct touch_capture;
    barcodereader_ui_touch_struct touch_af_mode;
    barcodereader_ui_touch_struct touch_storage;

   /***************************
   * AF
   ***************************/
#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
    U16 af_zone0_x; /* AF Zone 0 X-coordinate, (0,0) means left-top corner */
    U16 af_zone0_y; /* AF Zone 0 Y-coordinate */
    U16 af_zone1_x; /* AF Zone 1 X-coordinate */
    U16 af_zone1_y; /* AF Zone 1 Y-coordinate */
    U16 af_zone2_x; /* AF Zone 2 X-coordinate */
    U16 af_zone2_y; /* AF Zone 2 Y-coordinate */
    U16 af_zone3_x; /* AF Zone 3 X-coordinate */
    U16 af_zone3_y; /* AF Zone 3 Y-coordinate */
    U16 af_zone4_x; /* AF Zone 4 X-coordinate */
    U16 af_zone4_y; /* AF Zone 4 Y-coordinate */
#endif /* __MMI_BARCODEREADER_AF_SUPPORT__ */ 

    U32 drv_inline_list_p;
    MMI_BOOL is_camera_powered_on;
} barcodereader_context_struct;

#ifdef __MMI_BARCODEREADER_OPERATOR1__
typedef struct  
{
    WCHAR *name;
    U32 value;
    U16 string_id;
    U16 content_count;
}mmi_barcodereader_attribute_struct;

typedef struct  
{
    WCHAR *name;
    U32 value;
}mmi_barcodereader_applist_struct;
#endif

/********************************************************************************************************************** 
* file name prefix
**********************************************************************************************************************/
#define MMI_BARCODEREADER_FILE_NAME_VCARD	    "MingPian"	
#define MMI_BARCODEREADER_FILE_NAME_SMS	        "DuanXin"	
#define MMI_BARCODEREADER_FILE_NAME_DTXT	    "WenBen"	
#define MMI_BARCODEREADER_FILE_NAME_EMAIL	    "YouJian"	
#ifndef __MMI_BARCODEREADER_OPERATOR1__
#define MMI_BARCODEREADER_FILE_NAME_BUSINESS    "AD"
#define MMI_BARCODEREADER_FILE_NAME_PHONENUMBER "DianHua"
#define MMI_BARCODEREADER_FILE_NAME_URL         "WangZhi"
#define MMI_BARCODEREADER_FILE_NAME_EMAILADDRESS "YouJianDiZhi"	
#else
#define MMI_BARCODEREADER_FILE_NAME_WAPSELL	    "WAP"	
#define MMI_BARCODEREADER_FILE_NAME_SMSSELL	    "SMS"	
#define MMI_BARCODEREADER_FILE_NAME_IVRSELL	    "IVR"	
#endif

/********************************************************************************************************************** 
* app ID
**********************************************************************************************************************/
#define MMI_BARCODEREADER_APP_VCARD_ID          L"card"
#define MMI_BARCODEREADER_APP_EMAIL_ID           L"mail"
#define MMI_BARCODEREADER_APP_SMS_ID            L"sms"
#define MMI_BARCODEREADER_APP_DTXT_ID           L"dtxt"
#ifndef __MMI_BARCODEREADER_OPERATOR1__
#define MMI_BARCODEREADER_APP_BUSINESS_ID        L"ad"
#else
#define MMI_BARCODEREADER_APP_SMSSELL_ID        L"smssell"
#define MMI_BARCODEREADER_APP_WAPSELL_ID        L"wapsell"
#define MMI_BARCODEREADER_APP_IVRSELL_ID        L"ivrsell"
#endif

#ifdef __MMI_BARCODEREADER_OPERATOR1__
/********************************************************************************************************************** 
* operator attribute name
**********************************************************************************************************************/
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_N	      L"n"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_TIL	  L"til"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_DIV	  L"div"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_COR	  L"cor"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_ADR	  L"adr"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_ZIP	  L"zip"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_TEL	  L"tel"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_M	      L"m"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_FAX	  L"fax"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_EM	      L"em"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_URL	  L"url"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_SM	      L"sm"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_TO	      L"to"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_CT	      L"ct"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_TXT	  L"txt"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_INTR	  L"intr"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_TYPE	  L"type"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_LEN	  L"len"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_FILE	  L"file"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_CR	      L"cr"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_SUB	  L"sub"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_DG	      L"dg"
#define MMI_BARCODEREADER_ATTRIBUTE_NAME_SID	  L"sid"
//#define MMI_BARCODEREADER_ATTRIBUTE_NAME_NULL     ""

/********************************************************************************************************************** 
* operator attribute value
**********************************************************************************************************************/
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_N	            0X00000001	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_TIL	        0X00000002	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_DIV	        0X00000004	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_COR	        0X00000008	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_ADR	        0X00000010	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_ZIP	        0X00000020	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL	        0X00000040	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_M	            0X00000080	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_FAX	        0X00000100	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_EM	        0X00000200	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_URL	        0X00000400	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_SM	        0X00000800	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_TO	        0X00001000	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_CT	        0X00002000	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_TXT	        0X00004000	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_INTR	        0X00008000	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_TYPE	        0X00010000	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_LEN	        0X00020000	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_FILE	        0X00040000	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_CR	        0X00080000	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB	        0X00100000	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_DG	        0X00200000	
#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_SID	        0X00400000	
//#define MMI_BARCODEREADER_ATTRIBUTE_VALUE_NULL          0X00800000

/********************************************************************************************************************** 
* multi content attribute 
**********************************************************************************************************************/
#define MMI_BARCODEREADER_MULTI_CONTENT_ATTRIBUTE      (MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL |\
                                                        MMI_BARCODEREADER_ATTRIBUTE_VALUE_M |\
                                                        MMI_BARCODEREADER_ATTRIBUTE_VALUE_FAX |\
                                                        MMI_BARCODEREADER_ATTRIBUTE_VALUE_EM |\
                                                        MMI_BARCODEREADER_ATTRIBUTE_VALUE_SM |\
                                                        MMI_BARCODEREADER_ATTRIBUTE_VALUE_CT )

/********************************************************************************************************************** 
* content can highlight attribute 
**********************************************************************************************************************/
#define MMI_BARCODEREADER_HIGHLIGHT_CONTENT_ATTRIBUTE  (MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL |\
                                                        MMI_BARCODEREADER_ATTRIBUTE_VALUE_M |\
                                                        MMI_BARCODEREADER_ATTRIBUTE_VALUE_EM |\
                                                        MMI_BARCODEREADER_ATTRIBUTE_VALUE_URL |\
                                                        MMI_BARCODEREADER_ATTRIBUTE_VALUE_CT)

/********************************************************************************************************************** 
* all available attribute app need
**********************************************************************************************************************/
#define MMI_BARCODEREADER_APP_VCARD_ATTR_ALL   (MMI_BARCODEREADER_ATTRIBUTE_VALUE_N | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_TIL | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_DIV | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_COR | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_ADR | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_ZIP | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_M | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_FAX | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_EM | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_URL) 

#define MMI_BARCODEREADER_APP_SMS_ATTR_ALL     (MMI_BARCODEREADER_ATTRIBUTE_VALUE_SM | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_TXT)
                                                     
#define MMI_BARCODEREADER_APP_EMAIL_ATTR_ALL   (MMI_BARCODEREADER_ATTRIBUTE_VALUE_TO | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_TXT)

#define MMI_BARCODEREADER_APP_DTXT_ATTR_ALL    (MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB | \
                                                MMI_BARCODEREADER_ATTRIBUTE_VALUE_TXT)
                                

#define MMI_BARCODEREADER_APP_WAPSELL_ATTR_ALL	(MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB |\
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_INTR |\
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_URL |\
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL)

#define MMI_BARCODEREADER_APP_SMSSELL_ATTR_ALL	(MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB |\
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_INTR |\
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_DG |\
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_SID|\
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL)  
                                                     
#define MMI_BARCODEREADER_APP_IVRSELL_ATTR_ALL	(MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB |\
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_INTR |\
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_CT |\
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL)

/********************************************************************************************************************** 
* all must attribute app need
**********************************************************************************************************************/
#define MMI_BARCODEREADER_APP_VCARD_ATTR_MUST    (MMI_BARCODEREADER_ATTRIBUTE_VALUE_N)

#define MMI_BARCODEREADER_APP_SMS_ATTR_MUST      (MMI_BARCODEREADER_ATTRIBUTE_VALUE_SM | \
                                                 MMI_BARCODEREADER_ATTRIBUTE_VALUE_TXT)

#define MMI_BARCODEREADER_APP_EMAIL_ATTR_MUST    (MMI_BARCODEREADER_ATTRIBUTE_VALUE_TO )

#define MMI_BARCODEREADER_APP_DTXT_ATTR_MUST     (MMI_BARCODEREADER_ATTRIBUTE_VALUE_TXT)

#define MMI_BARCODEREADER_APP_WAPSELL_ATTR_MUST	 (MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB |\
                                                  MMI_BARCODEREADER_ATTRIBUTE_VALUE_INTR |\
                                                  MMI_BARCODEREADER_ATTRIBUTE_VALUE_URL |\
                                                  MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL)
                                                  
#define MMI_BARCODEREADER_APP_SMSSELL_ATTR_MUST	 (MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB |\
                                                  MMI_BARCODEREADER_ATTRIBUTE_VALUE_INTR |\
                                                  MMI_BARCODEREADER_ATTRIBUTE_VALUE_DG |\
                                                  MMI_BARCODEREADER_ATTRIBUTE_VALUE_SID|\
                                                  MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL)  
                                                  
#define MMI_BARCODEREADER_APP_IVRSELL_ATTR_MUST	 (MMI_BARCODEREADER_ATTRIBUTE_VALUE_SUB |\
                                                  MMI_BARCODEREADER_ATTRIBUTE_VALUE_INTR |\
                                                  MMI_BARCODEREADER_ATTRIBUTE_VALUE_CT |\
                                                  MMI_BARCODEREADER_ATTRIBUTE_VALUE_TEL)

#endif


#define MMI_BARCODEREADER_ENCODING_TYPE_GB2312  0x001
#define MMI_BARCODEREADER_ENCODING_TYPE_UTF8    0x110

#endif /* __MMI_BARCODEREADER__ */ 
#endif /* _BARCODEREADER_DATATPYE_H_ */ /* _BARCODEREADER_DATATYPE_H_ */

